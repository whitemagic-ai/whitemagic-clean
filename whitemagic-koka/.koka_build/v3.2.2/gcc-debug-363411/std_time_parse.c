// Koka generated module: std/time/parse, koka version: 3.2.2, platform: 64-bit
#include "std_time_parse.h"
extern kk_box_t kk_std_time_parse_optchar_fun1394(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_optchar_fun1394__t* _self = kk_function_as(struct kk_std_time_parse_optchar_fun1394__t*, _fself, _ctx);
  kk_char_t c = _self->c; /* char */
  kk_drop_match(_self, {kk_skip_dup(c, _ctx);}, {}, _ctx)
  kk_char_t _x_x1395 = kk_std_text_parse_char(c, _ctx); /*char*/
  return kk_char_box(_x_x1395, _ctx);
}
extern kk_box_t kk_std_time_parse_optchar_fun1396(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_optchar_fun1396__t* _self = kk_function_as(struct kk_std_time_parse_optchar_fun1396__t*, _fself, _ctx);
  kk_char_t c = _self->c; /* char */
  kk_drop_match(_self, {kk_skip_dup(c, _ctx);}, {}, _ctx)
  return kk_char_box(c, _ctx);
}
extern kk_box_t kk_std_time_parse_dash_fun1398(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1399 = kk_std_text_parse_char('-', _ctx); /*char*/
  return kk_char_box(_x_x1399, _ctx);
}
extern kk_box_t kk_std_time_parse_dash_fun1400(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box('-', _ctx);
}
extern kk_box_t kk_std_time_parse_colon_fun1402(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1403 = kk_std_text_parse_char(':', _ctx); /*char*/
  return kk_char_box(_x_x1403, _ctx);
}
extern kk_box_t kk_std_time_parse_colon_fun1404(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box(':', _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_num_10253_fun1406__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_num_10253_fun1406(kk_function_t _fself, kk_box_t _b_x15, kk_box_t _b_x16, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_num_10253_fun1406(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_num_10253_fun1406, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_num_10253_fun1406(kk_function_t _fself, kk_box_t _b_x15, kk_box_t _b_x16, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_20 = kk_integer_unbox(_b_x15, _ctx); /*int*/;
  kk_integer_t d_21 = kk_integer_unbox(_b_x16, _ctx); /*int*/;
  kk_integer_t x_0_10139 = kk_integer_mul(x_20,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1407 = kk_integer_add(x_0_10139,d_21,kk_context()); /*int*/
  return kk_integer_box(_x_x1407, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_num_10253(kk_std_core_types__list _y_x10049, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1405 = kk_std_core_list_foldl(_y_x10049, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_num_10253_fun1406(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1405, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_num_fun1408__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_num_fun1408(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_num_fun1408(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_num_fun1408, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_num_fun1408(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1409 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1409, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_num_fun1411__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_num_fun1411(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_num_fun1411(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_num_fun1411, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_num_fun1411(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1412;
  kk_std_core_types__list _x_x1413 = kk_std_core_types__list_unbox(_b_x27, KK_OWNED, _ctx); /*list<int>*/
  _x_x1412 = kk_std_time_parse__mlift_num_10253(_x_x1413, _ctx); /*int*/
  return kk_integer_box(_x_x1412, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_num_fun1414__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_num_fun1414(kk_function_t _fself, kk_box_t _b_x31, kk_box_t _b_x32, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_num_fun1414(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_num_fun1414, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_num_fun1414(kk_function_t _fself, kk_box_t _b_x31, kk_box_t _b_x32, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_0_37 = kk_integer_unbox(_b_x31, _ctx); /*int*/;
  kk_integer_t d_38 = kk_integer_unbox(_b_x32, _ctx); /*int*/;
  kk_integer_t x_0_10139 = kk_integer_mul(x_0_37,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1415 = kk_integer_add(x_0_10139,d_38,kk_context()); /*int*/
  return kk_integer_box(_x_x1415, _ctx);
}

kk_integer_t kk_std_time_parse_num(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> std/text/parse/parse int */ 
  kk_std_core_types__list x_10306 = kk_std_text_parse_count(n, kk_std_time_parse_new_num_fun1408(_ctx), _ctx); /*list<int>*/;
  kk_box_t _x_x1410;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10306, _ctx);
    _x_x1410 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_num_fun1411(_ctx), _ctx); /*2419*/
  }
  else {
    _x_x1410 = kk_std_core_list_foldl(x_10306, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse_new_num_fun1414(_ctx), _ctx); /*2419*/
  }
  return kk_integer_unbox(_x_x1410, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10254_fun1417__t {
  struct kk_function_s _base;
  kk_integer_t _c_x10083;
  kk_integer_t tzmin;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10254_fun1417(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10254_fun1417(kk_integer_t _c_x10083, kk_integer_t tzmin, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10254_fun1417__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10254_fun1417__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10254_fun1417, kk_context());
  _self->_c_x10083 = _c_x10083;
  _self->tzmin = tzmin;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10254_fun1417(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10254_fun1417__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10254_fun1417__t*, _fself, _ctx);
  kk_integer_t _c_x10083 = _self->_c_x10083; /* int */
  kk_integer_t tzmin = _self->tzmin; /* int */
  kk_drop_match(_self, {kk_integer_dup(_c_x10083, _ctx);kk_integer_dup(tzmin, _ctx);}, {}, _ctx)
  kk_std_time_calendar__timezone _x_x1418;
  kk_std_core_types__optional _x_x1419 = kk_std_core_types__new_Optional(kk_integer_box(tzmin, _ctx), _ctx); /*? 7*/
  _x_x1418 = kk_std_time_calendar_tz_fixed(_c_x10083, _x_x1419, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x1418, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10254(kk_integer_t tzmin, kk_integer_t _c_x10083, kk_context_t* _ctx) { /* (tzmin : int, int) -> std/time/calendar/timezone */ 
  kk_box_t _x_x1416 = kk_std_core_hnd__open_none0(kk_std_time_parse__new_mlift_ptime_10254_fun1417(_c_x10083, tzmin, _ctx), _ctx); /*9836*/
  return kk_std_time_calendar__timezone_unbox(_x_x1416, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10255_fun1421__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10255_fun1421(kk_function_t _fself, kk_box_t _b_x46, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10255_fun1421(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10255_fun1421, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10255_fun1421(kk_function_t _fself, kk_box_t _b_x46, kk_box_t _b_x47, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_8_51 = kk_integer_unbox(_b_x46, _ctx); /*int*/;
  kk_integer_t d_3_52 = kk_integer_unbox(_b_x47, _ctx); /*int*/;
  kk_integer_t x_9_10166 = kk_integer_mul(x_8_51,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1422 = kk_integer_add(x_9_10166,d_3_52,kk_context()); /*int*/
  return kk_integer_box(_x_x1422, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_ptime_10255(kk_std_core_types__list _y_x10080, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1420 = kk_std_core_list_foldl(_y_x10080, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_ptime_10255_fun1421(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1420, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10256_fun1423__t {
  struct kk_function_s _base;
  kk_integer_t tzmin;
};
static kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10256_fun1423(kk_function_t _fself, kk_integer_t _c_x10083, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10256_fun1423(kk_integer_t tzmin, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10256_fun1423__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10256_fun1423__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10256_fun1423, kk_context());
  _self->tzmin = tzmin;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10256_fun1425__t {
  struct kk_function_s _base;
  kk_integer_t _c_x10083;
  kk_integer_t tzmin;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10256_fun1425(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10256_fun1425(kk_integer_t _c_x10083, kk_integer_t tzmin, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10256_fun1425__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10256_fun1425__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10256_fun1425, kk_context());
  _self->_c_x10083 = _c_x10083;
  _self->tzmin = tzmin;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10256_fun1425(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10256_fun1425__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10256_fun1425__t*, _fself, _ctx);
  kk_integer_t _c_x10083 = _self->_c_x10083; /* int */
  kk_integer_t tzmin = _self->tzmin; /* int */
  kk_drop_match(_self, {kk_integer_dup(_c_x10083, _ctx);kk_integer_dup(tzmin, _ctx);}, {}, _ctx)
  kk_std_time_calendar__timezone _x_x1426;
  kk_std_core_types__optional _x_x1427 = kk_std_core_types__new_Optional(kk_integer_box(tzmin, _ctx), _ctx); /*? 7*/
  _x_x1426 = kk_std_time_calendar_tz_fixed(_c_x10083, _x_x1427, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x1426, _ctx);
}
static kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10256_fun1423(kk_function_t _fself, kk_integer_t _c_x10083, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10256_fun1423__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10256_fun1423__t*, _fself, _ctx);
  kk_integer_t tzmin = _self->tzmin; /* int */
  kk_drop_match(_self, {kk_integer_dup(tzmin, _ctx);}, {}, _ctx)
  kk_box_t _x_x1424 = kk_std_core_hnd__open_none0(kk_std_time_parse__new_mlift_ptime_10256_fun1425(_c_x10083, tzmin, _ctx), _ctx); /*9836*/
  return kk_std_time_calendar__timezone_unbox(_x_x1424, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10256_fun1429__t {
  struct kk_function_s _base;
  kk_function_t next_10310;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10256_fun1429(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10256_fun1429(kk_function_t next_10310, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10256_fun1429__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10256_fun1429__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10256_fun1429, kk_context());
  _self->next_10310 = next_10310;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10256_fun1429(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10256_fun1429__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10256_fun1429__t*, _fself, _ctx);
  kk_function_t next_10310 = _self->next_10310; /* (int) -> std/time/calendar/timezone */
  kk_drop_match(_self, {kk_function_dup(next_10310, _ctx);}, {}, _ctx)
  kk_std_time_calendar__timezone _x_x1430;
  kk_integer_t _x_x1431 = kk_integer_unbox(_b_x58, _ctx); /*int*/
  _x_x1430 = kk_function_call(kk_std_time_calendar__timezone, (kk_function_t, kk_integer_t, kk_context_t*), next_10310, (next_10310, _x_x1431, _ctx), _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x1430, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10256(kk_char_t sign, kk_integer_t tzhour, kk_integer_t tzmin, kk_context_t* _ctx) { /* (sign : char, tzhour : int, tzmin : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
  kk_integer_t x_10309;
  bool _match_x1387 = (sign == ('-')); /*bool*/;
  if (_match_x1387) {
    x_10309 = kk_integer_neg(tzhour,kk_context()); /*int*/
  }
  else {
    x_10309 = tzhour; /*int*/
  }
  kk_function_t next_10310 = kk_std_time_parse__new_mlift_ptime_10256_fun1423(tzmin, _ctx); /*(int) -> std/time/calendar/timezone*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10309, _ctx);
    kk_box_t _x_x1428 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10256_fun1429(next_10310, _ctx), _ctx); /*2419*/
    return kk_std_time_calendar__timezone_unbox(_x_x1428, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_time_calendar__timezone, (kk_function_t, kk_integer_t, kk_context_t*), next_10310, (next_10310, x_10309, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10257_fun1433__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10257_fun1433(kk_function_t _fself, kk_box_t _b_x74, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10257_fun1433(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10257_fun1433, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10257_fun1435__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10257_fun1435(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10257_fun1435(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10257_fun1435, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10257_fun1435(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1436 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1436, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10257_fun1437__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10257_fun1437(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10257_fun1437(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10257_fun1437, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10257_fun1437(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1438;
  kk_std_core_types__list _x_x1439 = kk_std_core_types__list_unbox(_b_x65, KK_OWNED, _ctx); /*list<int>*/
  _x_x1438 = kk_std_time_parse__mlift_ptime_10255(_x_x1439, _ctx); /*int*/
  return kk_integer_box(_x_x1438, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10257_fun1440__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10257_fun1440(kk_function_t _fself, kk_box_t _b_x69, kk_box_t _b_x70, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10257_fun1440(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10257_fun1440, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10257_fun1440(kk_function_t _fself, kk_box_t _b_x69, kk_box_t _b_x70, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_9_10166;
  kk_integer_t _x_x1441 = kk_integer_unbox(_b_x69, _ctx); /*int*/
  x_9_10166 = kk_integer_mul(_x_x1441,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1442;
  kk_integer_t _x_x1443 = kk_integer_unbox(_b_x70, _ctx); /*int*/
  _x_x1442 = kk_integer_add(x_9_10166,_x_x1443,kk_context()); /*int*/
  return kk_integer_box(_x_x1442, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10257_fun1433(kk_function_t _fself, kk_box_t _b_x74, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_0_10315;
  kk_integer_t _x_x1434 = kk_integer_unbox(_b_x74, _ctx); /*int*/
  x_0_10315 = kk_std_text_parse_count(_x_x1434, kk_std_time_parse__new_mlift_ptime_10257_fun1435(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10315, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10257_fun1437(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_0_10315, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_ptime_10257_fun1440(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10257_fun1445__t {
  struct kk_function_s _base;
  kk_integer_t tzhour;
  kk_char_t sign;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10257_fun1445(kk_function_t _fself, kk_box_t _b_x86, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10257_fun1445(kk_integer_t tzhour, kk_char_t sign, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10257_fun1445__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10257_fun1445__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10257_fun1445, kk_context());
  _self->tzhour = tzhour;
  _self->sign = sign;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10257_fun1445(kk_function_t _fself, kk_box_t _b_x86, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10257_fun1445__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10257_fun1445__t*, _fself, _ctx);
  kk_integer_t tzhour = _self->tzhour; /* int */
  kk_char_t sign = _self->sign; /* char */
  kk_drop_match(_self, {kk_integer_dup(tzhour, _ctx);kk_skip_dup(sign, _ctx);}, {}, _ctx)
  kk_integer_t tzmin_88 = kk_integer_unbox(_b_x86, _ctx); /*int*/;
  kk_std_time_calendar__timezone _x_x1446 = kk_std_time_parse__mlift_ptime_10256(sign, tzhour, tzmin_88, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x1446, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10257(kk_char_t sign, kk_integer_t tzhour, kk_char_t wild___3, kk_context_t* _ctx) { /* (sign : char, tzhour : int, wild_@3 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
  kk_ssize_t _b_x71_75 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_10313;
  kk_box_t _x_x1432 = kk_std_core_hnd__open_at1(_b_x71_75, kk_std_time_parse__new_mlift_ptime_10257_fun1433(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
  x_10313 = kk_integer_unbox(_x_x1432, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10313, _ctx);
    kk_box_t _x_x1444 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10257_fun1445(tzhour, sign, _ctx), _ctx); /*2419*/
    return kk_std_time_calendar__timezone_unbox(_x_x1444, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_10256(sign, tzhour, x_10313, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10258_fun1448__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10258_fun1448(kk_function_t _fself, kk_box_t _b_x92, kk_box_t _b_x93, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10258_fun1448(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10258_fun1448, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10258_fun1448(kk_function_t _fself, kk_box_t _b_x92, kk_box_t _b_x93, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_6_97 = kk_integer_unbox(_b_x92, _ctx); /*int*/;
  kk_integer_t d_2_98 = kk_integer_unbox(_b_x93, _ctx); /*int*/;
  kk_integer_t x_7_10162 = kk_integer_mul(x_6_97,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1449 = kk_integer_add(x_7_10162,d_2_98,kk_context()); /*int*/
  return kk_integer_box(_x_x1449, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_ptime_10258(kk_std_core_types__list _y_x10074, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1447 = kk_std_core_list_foldl(_y_x10074, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_ptime_10258_fun1448(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1447, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10259_fun1451__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10259_fun1451(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10259_fun1451(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10259_fun1451, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10259_fun1452__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10259_fun1452(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10259_fun1452(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10259_fun1452, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10259_fun1452(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1453 = kk_std_text_parse_char(':', _ctx); /*char*/
  return kk_char_box(_x_x1453, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10259_fun1454__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10259_fun1454(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10259_fun1454(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10259_fun1454, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10259_fun1454(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box(':', _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10259_fun1451(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_ptime_10259_fun1452(_ctx), kk_std_time_parse__new_mlift_ptime_10259_fun1454(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10259_fun1456__t {
  struct kk_function_s _base;
  kk_integer_t tzhour;
  kk_char_t sign;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10259_fun1456(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10259_fun1456(kk_integer_t tzhour, kk_char_t sign, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10259_fun1456__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10259_fun1456__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10259_fun1456, kk_context());
  _self->tzhour = tzhour;
  _self->sign = sign;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10259_fun1456(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10259_fun1456__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10259_fun1456__t*, _fself, _ctx);
  kk_integer_t tzhour = _self->tzhour; /* int */
  kk_char_t sign = _self->sign; /* char */
  kk_drop_match(_self, {kk_integer_dup(tzhour, _ctx);kk_skip_dup(sign, _ctx);}, {}, _ctx)
  kk_char_t wild___3_110 = kk_char_unbox(_b_x108, KK_OWNED, _ctx); /*char*/;
  kk_std_time_calendar__timezone _x_x1457 = kk_std_time_parse__mlift_ptime_10257(sign, tzhour, wild___3_110, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x1457, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10259(kk_char_t sign, kk_integer_t tzhour, kk_context_t* _ctx) { /* (sign : char, tzhour : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
  kk_ssize_t _b_x101_103 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_10317;
  kk_box_t _x_x1450 = kk_std_core_hnd__open_at0(_b_x101_103, kk_std_time_parse__new_mlift_ptime_10259_fun1451(_ctx), _ctx); /*10426*/
  x_10317 = kk_char_unbox(_x_x1450, KK_OWNED, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1455 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10259_fun1456(tzhour, sign, _ctx), _ctx); /*2419*/
    return kk_std_time_calendar__timezone_unbox(_x_x1455, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_10257(sign, tzhour, x_10317, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10260_fun1459__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10260_fun1459(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10260_fun1459(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10260_fun1459, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10260_fun1461__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10260_fun1461(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10260_fun1461(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10260_fun1461, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10260_fun1461(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1462 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1462, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10260_fun1463__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10260_fun1463(kk_function_t _fself, kk_box_t _b_x116, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10260_fun1463(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10260_fun1463, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10260_fun1463(kk_function_t _fself, kk_box_t _b_x116, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1464;
  kk_std_core_types__list _x_x1465 = kk_std_core_types__list_unbox(_b_x116, KK_OWNED, _ctx); /*list<int>*/
  _x_x1464 = kk_std_time_parse__mlift_ptime_10258(_x_x1465, _ctx); /*int*/
  return kk_integer_box(_x_x1464, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10260_fun1466__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10260_fun1466(kk_function_t _fself, kk_box_t _b_x120, kk_box_t _b_x121, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10260_fun1466(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10260_fun1466, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10260_fun1466(kk_function_t _fself, kk_box_t _b_x120, kk_box_t _b_x121, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_7_10162;
  kk_integer_t _x_x1467 = kk_integer_unbox(_b_x120, _ctx); /*int*/
  x_7_10162 = kk_integer_mul(_x_x1467,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1468;
  kk_integer_t _x_x1469 = kk_integer_unbox(_b_x121, _ctx); /*int*/
  _x_x1468 = kk_integer_add(x_7_10162,_x_x1469,kk_context()); /*int*/
  return kk_integer_box(_x_x1468, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10260_fun1459(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_0_10321;
  kk_integer_t _x_x1460 = kk_integer_unbox(_b_x125, _ctx); /*int*/
  x_0_10321 = kk_std_text_parse_count(_x_x1460, kk_std_time_parse__new_mlift_ptime_10260_fun1461(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10321, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10260_fun1463(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_0_10321, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_ptime_10260_fun1466(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10260_fun1471__t {
  struct kk_function_s _base;
  kk_char_t sign;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10260_fun1471(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10260_fun1471(kk_char_t sign, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10260_fun1471__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10260_fun1471__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10260_fun1471, kk_context());
  _self->sign = sign;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10260_fun1471(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10260_fun1471__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10260_fun1471__t*, _fself, _ctx);
  kk_char_t sign = _self->sign; /* char */
  kk_drop_match(_self, {kk_skip_dup(sign, _ctx);}, {}, _ctx)
  kk_integer_t tzhour_139 = kk_integer_unbox(_b_x137, _ctx); /*int*/;
  kk_std_time_calendar__timezone _x_x1472 = kk_std_time_parse__mlift_ptime_10259(sign, tzhour_139, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x1472, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10260(kk_char_t sign, kk_context_t* _ctx) { /* (sign : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
  kk_ssize_t _b_x122_126 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_10319;
  kk_box_t _x_x1458 = kk_std_core_hnd__open_at1(_b_x122_126, kk_std_time_parse__new_mlift_ptime_10260_fun1459(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
  x_10319 = kk_integer_unbox(_x_x1458, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10319, _ctx);
    kk_box_t _x_x1470 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10260_fun1471(sign, _ctx), _ctx); /*2419*/
    return kk_std_time_calendar__timezone_unbox(_x_x1470, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_10259(sign, x_10319, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10262_fun1474__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
  kk_integer_t min;
  kk_std_time_calendar__timezone tzone;
  kk_std_num_ddouble__ddouble secs;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10262_fun1474(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10262_fun1474(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_std_time_calendar__timezone tzone, kk_std_num_ddouble__ddouble secs, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10262_fun1474__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10262_fun1474__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10262_fun1474, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  _self->min = min;
  _self->tzone = tzone;
  _self->secs = secs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10262_fun1474(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10262_fun1474__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10262_fun1474__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_integer_t min = _self->min; /* int */
  kk_std_time_calendar__timezone tzone = _self->tzone; /* std/time/calendar/timezone */
  kk_std_num_ddouble__ddouble secs = _self->secs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);kk_integer_dup(min, _ctx);kk_std_time_calendar__timezone_dup(tzone, _ctx);kk_std_num_ddouble__ddouble_dup(secs, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x1475;
  kk_std_core_types__optional _x_x1476;
  kk_box_t _x_x1477;
  kk_std_time_date__clock _x_x1478 = kk_std_time_date__new_Clock(kk_reuse_null, 0, hour, min, secs, _ctx); /*std/time/date/clock*/
  _x_x1477 = kk_std_time_date__clock_box(_x_x1478, _ctx); /*7*/
  _x_x1476 = kk_std_core_types__new_Optional(_x_x1477, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1479 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(tzone, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1480 = kk_std_core_types__new_Optional(kk_std_time_calendar__calendar_box(cal, _ctx), _ctx); /*? 7*/
  _x_x1475 = kk_std_time_time_date_fs_time(date, _x_x1476, _x_x1479, _x_x1480, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1475, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10262(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_std_num_ddouble__ddouble secs, kk_std_time_calendar__timezone tzone, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, min : int, secs : std/num/ddouble/ddouble, tzone : std/time/calendar/timezone) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t _b_x143_145 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_box_t _x_x1473 = kk_std_core_hnd__open_at0(_b_x143_145, kk_std_time_parse__new_mlift_ptime_10262_fun1474(cal, date, hour, min, tzone, secs, _ctx), _ctx); /*10426*/
  return kk_std_time_time__time_unbox(_x_x1473, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10263_fun1482__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10263_fun1482(kk_function_t _fself, kk_box_t _b_x152, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10263_fun1482(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10263_fun1482, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10263_fun1482(kk_function_t _fself, kk_box_t _b_x152, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1483;
  kk_integer_t _x_x1484 = kk_integer_unbox(_b_x152, _ctx); /*int*/
  _x_x1483 = kk_std_num_ddouble_ddouble_int_exp(_x_x1484, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1483, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10263_fun1486__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10263_fun1486(kk_function_t _fself, kk_box_t _b_x159, kk_box_t _b_x160, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10263_fun1486(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10263_fun1486, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10263_fun1486(kk_function_t _fself, kk_box_t _b_x159, kk_box_t _b_x160, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1487;
  kk_std_num_ddouble__ddouble _x_x1488 = kk_std_num_ddouble__ddouble_unbox(_b_x159, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1489 = kk_std_num_ddouble__ddouble_unbox(_b_x160, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1487 = kk_std_num_ddouble__lp__plus__rp_(_x_x1488, _x_x1489, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1487, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_10263(kk_integer_t s, kk_std_num_ddouble__ddouble _c_x10071, kk_context_t* _ctx) { /* (s : int, std/num/ddouble/ddouble) -> std/num/ddouble/ddouble */ 
  kk_std_num_ddouble__ddouble _x_x1_6_10218;
  kk_box_t _x_x1481 = kk_std_core_hnd__open_none1(kk_std_time_parse__new_mlift_ptime_10263_fun1482(_ctx), kk_integer_box(s, _ctx), _ctx); /*9904*/
  _x_x1_6_10218 = kk_std_num_ddouble__ddouble_unbox(_x_x1481, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_box_t _x_x1485 = kk_std_core_hnd__open_none2(kk_std_time_parse__new_mlift_ptime_10263_fun1486(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_6_10218, _ctx), kk_std_num_ddouble__ddouble_box(_c_x10071, _ctx), _ctx); /*9985*/
  return kk_std_num_ddouble__ddouble_unbox(_x_x1485, KK_OWNED, _ctx);
}
extern kk_box_t kk_std_time_parse__mlift_ptime_10264_fun1491(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1492 = kk_std_text_parse_digits(_ctx); /*string*/
  return kk_string_box(_x_x1492);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10265_fun1499__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10265_fun1499(kk_function_t _fself, kk_box_t _b_x170, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10265_fun1499(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10265_fun1499, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10265_fun1499(kk_function_t _fself, kk_box_t _b_x170, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x1500;
  kk_string_t _x_x1501 = kk_string_unbox(_b_x170); /*string*/
  _x_x1500 = kk_std_num_ddouble_parse_ddouble(_x_x1501, _ctx); /*maybe<std/num/ddouble/ddouble>*/
  return kk_std_core_types__maybe_box(_x_x1500, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10265_fun1503__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10265_fun1503(kk_function_t _fself, kk_box_t _b_x177, kk_box_t _b_x178, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10265_fun1503(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10265_fun1503, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10265_fun1503(kk_function_t _fself, kk_box_t _b_x177, kk_box_t _b_x178, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1504;
  kk_std_core_types__maybe _match_x1380 = kk_std_core_types__maybe_unbox(_b_x177, KK_OWNED, _ctx); /*maybe<std/num/ddouble/ddouble>*/;
  if (kk_std_core_types__is_Nothing(_match_x1380, _ctx)) {
    _x_x1504 = kk_std_num_ddouble__ddouble_unbox(_b_x178, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_box_t _box_x173 = _match_x1380._cons.Just.value;
    kk_std_num_ddouble__ddouble x_5 = kk_std_num_ddouble__ddouble_unbox(_box_x173, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_match_x1380, _ctx);
    kk_box_drop(_b_x178, _ctx);
    _x_x1504 = x_5; /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__ddouble_box(_x_x1504, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10265_fun1505__t {
  struct kk_function_s _base;
  kk_integer_t s;
};
static kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_10265_fun1505(kk_function_t _fself, kk_std_num_ddouble__ddouble _c_x10071, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10265_fun1505(kk_integer_t s, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10265_fun1505__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10265_fun1505__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10265_fun1505, kk_context());
  _self->s = s;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10265_fun1507__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10265_fun1507(kk_function_t _fself, kk_box_t _b_x186, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10265_fun1507(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10265_fun1507, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10265_fun1507(kk_function_t _fself, kk_box_t _b_x186, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1508;
  kk_integer_t _x_x1509 = kk_integer_unbox(_b_x186, _ctx); /*int*/
  _x_x1508 = kk_std_num_ddouble_ddouble_int_exp(_x_x1509, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1508, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10265_fun1511__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10265_fun1511(kk_function_t _fself, kk_box_t _b_x193, kk_box_t _b_x194, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10265_fun1511(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10265_fun1511, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10265_fun1511(kk_function_t _fself, kk_box_t _b_x193, kk_box_t _b_x194, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1512;
  kk_std_num_ddouble__ddouble _x_x1513 = kk_std_num_ddouble__ddouble_unbox(_b_x193, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1514 = kk_std_num_ddouble__ddouble_unbox(_b_x194, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1512 = kk_std_num_ddouble__lp__plus__rp_(_x_x1513, _x_x1514, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1512, _ctx);
}
static kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_10265_fun1505(kk_function_t _fself, kk_std_num_ddouble__ddouble _c_x10071, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10265_fun1505__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10265_fun1505__t*, _fself, _ctx);
  kk_integer_t s = _self->s; /* int */
  kk_drop_match(_self, {kk_integer_dup(s, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x_x1_6_10218;
  kk_box_t _x_x1506 = kk_std_core_hnd__open_none1(kk_std_time_parse__new_mlift_ptime_10265_fun1507(_ctx), kk_integer_box(s, _ctx), _ctx); /*9904*/
  _x_x1_6_10218 = kk_std_num_ddouble__ddouble_unbox(_x_x1506, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_box_t _x_x1510 = kk_std_core_hnd__open_none2(kk_std_time_parse__new_mlift_ptime_10265_fun1511(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_6_10218, _ctx), kk_std_num_ddouble__ddouble_box(_c_x10071, _ctx), _ctx); /*9985*/
  return kk_std_num_ddouble__ddouble_unbox(_x_x1510, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10265_fun1516__t {
  struct kk_function_s _base;
  kk_function_t next_10324;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10265_fun1516(kk_function_t _fself, kk_box_t _b_x199, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10265_fun1516(kk_function_t next_10324, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10265_fun1516__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10265_fun1516__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10265_fun1516, kk_context());
  _self->next_10324 = next_10324;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10265_fun1516(kk_function_t _fself, kk_box_t _b_x199, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10265_fun1516__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10265_fun1516__t*, _fself, _ctx);
  kk_function_t next_10324 = _self->next_10324; /* (std/num/ddouble/ddouble) -> std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_function_dup(next_10324, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x_x1517;
  kk_std_num_ddouble__ddouble _x_x1518 = kk_std_num_ddouble__ddouble_unbox(_b_x199, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1517 = kk_function_call(kk_std_num_ddouble__ddouble, (kk_function_t, kk_std_num_ddouble__ddouble, kk_context_t*), next_10324, (next_10324, _x_x1518, _ctx), _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1517, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_10265(kk_integer_t s, kk_string_t f, kk_context_t* _ctx) { /* (s : int, f : string) -> <std/text/parse/parse,std/time/utc/utc> std/num/ddouble/ddouble */ 
  kk_std_num_ddouble__ddouble x_10323;
  bool _match_x1379;
  kk_string_t _x_x1493 = kk_string_dup(f, _ctx); /*string*/
  kk_string_t _x_x1494 = kk_string_empty(); /*string*/
  _match_x1379 = kk_string_is_eq(_x_x1493,_x_x1494,kk_context()); /*bool*/
  if (_match_x1379) {
    kk_string_drop(f, _ctx);
    x_10323 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_string_t _x_x1_5_10217;
    kk_string_t _x_x1496;
    kk_define_string_literal(, _s_x1497, 2, "0.", _ctx)
    _x_x1496 = kk_string_dup(_s_x1497, _ctx); /*string*/
    _x_x1_5_10217 = kk_std_core_types__lp__plus__plus__rp_(_x_x1496, f, _ctx); /*string*/
    kk_std_core_types__maybe _x_x1_4_10215;
    kk_box_t _x_x1498 = kk_std_core_hnd__open_none1(kk_std_time_parse__new_mlift_ptime_10265_fun1499(_ctx), kk_string_box(_x_x1_5_10217), _ctx); /*9904*/
    _x_x1_4_10215 = kk_std_core_types__maybe_unbox(_x_x1498, KK_OWNED, _ctx); /*maybe<std/num/ddouble/ddouble>*/
    kk_box_t _x_x1502 = kk_std_core_hnd__open_none2(kk_std_time_parse__new_mlift_ptime_10265_fun1503(_ctx), kk_std_core_types__maybe_box(_x_x1_4_10215, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx), _ctx); /*9985*/
    x_10323 = kk_std_num_ddouble__ddouble_unbox(_x_x1502, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_function_t next_10324 = kk_std_time_parse__new_mlift_ptime_10265_fun1505(s, _ctx); /*(std/num/ddouble/ddouble) -> std/num/ddouble/ddouble*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1515 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10265_fun1516(next_10324, _ctx), _ctx); /*2419*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1515, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_num_ddouble__ddouble, (kk_function_t, kk_std_num_ddouble__ddouble, kk_context_t*), next_10324, (next_10324, x_10323, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10266_fun1520__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10266_fun1520(kk_function_t _fself, kk_box_t _b_x204, kk_box_t _b_x205, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10266_fun1520(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10266_fun1520, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10266_fun1520(kk_function_t _fself, kk_box_t _b_x204, kk_box_t _b_x205, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_3_209 = kk_integer_unbox(_b_x204, _ctx); /*int*/;
  kk_integer_t d_1_210 = kk_integer_unbox(_b_x205, _ctx); /*int*/;
  kk_integer_t x_4_10151 = kk_integer_mul(x_3_209,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1521 = kk_integer_add(x_4_10151,d_1_210,kk_context()); /*int*/
  return kk_integer_box(_x_x1521, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_ptime_10266(kk_std_core_types__list _y_x10065, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1519 = kk_std_core_list_foldl(_y_x10065, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_ptime_10266_fun1520(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1519, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10267_fun1523__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1523(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10267_fun1523(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10267_fun1523, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10267_fun1525__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1525(kk_function_t _fself, kk_box_t _b_x214, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10267_fun1525(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10267_fun1525, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1525(kk_function_t _fself, kk_box_t _b_x214, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1526;
  kk_string_t _x_x1527 = kk_string_unbox(_b_x214); /*string*/
  _x_x1526 = kk_std_text_parse_one_of(_x_x1527, _ctx); /*char*/
  return kk_char_box(_x_x1526, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10267_fun1533__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1533(kk_function_t _fself, kk_box_t _b_x219, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10267_fun1533(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10267_fun1533, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1533(kk_function_t _fself, kk_box_t _b_x219, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1534;
  kk_char_t _x_x1535 = kk_char_unbox(_b_x219, KK_OWNED, _ctx); /*char*/
  _x_x1534 = kk_std_time_parse__mlift_ptime_10264(_x_x1535, _ctx); /*string*/
  return kk_string_box(_x_x1534);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10267_fun1537__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1537(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10267_fun1537(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10267_fun1537, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1537(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1538 = kk_std_text_parse_digits(_ctx); /*string*/
  return kk_string_box(_x_x1538);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1523(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x211_215 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_0_10329;
  kk_box_t _x_x1524;
  kk_box_t _x_x1528;
  kk_string_t _x_x1529;
  kk_define_string_literal(, _s_x1530, 2, ".,", _ctx)
  _x_x1529 = kk_string_dup(_s_x1530, _ctx); /*string*/
  _x_x1528 = kk_string_box(_x_x1529); /*10539*/
  _x_x1524 = kk_std_core_hnd__open_at1(_b_x211_215, kk_std_time_parse__new_mlift_ptime_10267_fun1525(_ctx), _x_x1528, _ctx); /*10540*/
  x_0_10329 = kk_char_unbox(_x_x1524, KK_OWNED, _ctx); /*char*/
  kk_string_t _x_x1531;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1532 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10267_fun1533(_ctx), _ctx); /*2419*/
    _x_x1531 = kk_string_unbox(_x_x1532); /*string*/
  }
  else {
    kk_ssize_t _b_x220_227 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_box_t _x_x1536 = kk_std_core_hnd__open_at0(_b_x220_227, kk_std_time_parse__new_mlift_ptime_10267_fun1537(_ctx), _ctx); /*10426*/
    _x_x1531 = kk_string_unbox(_x_x1536); /*string*/
  }
  return kk_string_box(_x_x1531);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10267_fun1539__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1539(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10267_fun1539(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10267_fun1539, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1539(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1540 = kk_string_empty(); /*string*/
  return kk_string_box(_x_x1540);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10267_fun1543__t {
  struct kk_function_s _base;
  kk_integer_t s;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1543(kk_function_t _fself, kk_box_t _b_x230, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10267_fun1543(kk_integer_t s, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10267_fun1543__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10267_fun1543__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10267_fun1543, kk_context());
  _self->s = s;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10267_fun1543(kk_function_t _fself, kk_box_t _b_x230, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10267_fun1543__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10267_fun1543__t*, _fself, _ctx);
  kk_integer_t s = _self->s; /* int */
  kk_drop_match(_self, {kk_integer_dup(s, _ctx);}, {}, _ctx)
  kk_string_t f_232 = kk_string_unbox(_b_x230); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1544 = kk_std_time_parse__mlift_ptime_10265(s, f_232, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1544, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_10267(kk_integer_t s, kk_context_t* _ctx) { /* (s : int) -> <std/text/parse/parse,std/time/utc/utc> std/num/ddouble/ddouble */ 
  kk_string_t x_10327;
  kk_box_t _x_x1522 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_ptime_10267_fun1523(_ctx), kk_std_time_parse__new_mlift_ptime_10267_fun1539(_ctx), _ctx); /*1542*/
  x_10327 = kk_string_unbox(_x_x1522); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10327, _ctx);
    kk_box_t _x_x1542 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10267_fun1543(s, _ctx), _ctx); /*2419*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1542, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_10265(s, x_10327, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10268_fun1547__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1547(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10268_fun1547(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10268_fun1547, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10268_fun1549__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1549(kk_function_t _fself, kk_box_t _b_x236, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10268_fun1549(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10268_fun1549, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1549(kk_function_t _fself, kk_box_t _b_x236, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1550;
  kk_string_t _x_x1551 = kk_string_unbox(_b_x236); /*string*/
  _x_x1550 = kk_std_text_parse_one_of(_x_x1551, _ctx); /*char*/
  return kk_char_box(_x_x1550, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10268_fun1557__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1557(kk_function_t _fself, kk_box_t _b_x241, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10268_fun1557(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10268_fun1557, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1557(kk_function_t _fself, kk_box_t _b_x241, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x1558;
  kk_char_t _x_x1559 = kk_char_unbox(_b_x241, KK_OWNED, _ctx); /*char*/
  _x_x1558 = kk_std_time_parse__mlift_ptime_10260(_x_x1559, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x1558, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1547(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x233_237 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_0_10333;
  kk_box_t _x_x1548;
  kk_box_t _x_x1552;
  kk_string_t _x_x1553;
  kk_define_string_literal(, _s_x1554, 2, "+-", _ctx)
  _x_x1553 = kk_string_dup(_s_x1554, _ctx); /*string*/
  _x_x1552 = kk_string_box(_x_x1553); /*10539*/
  _x_x1548 = kk_std_core_hnd__open_at1(_b_x233_237, kk_std_time_parse__new_mlift_ptime_10268_fun1549(_ctx), _x_x1552, _ctx); /*10540*/
  x_0_10333 = kk_char_unbox(_x_x1548, KK_OWNED, _ctx); /*char*/
  kk_std_time_calendar__timezone _x_x1555;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1556 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10268_fun1557(_ctx), _ctx); /*2419*/
    _x_x1555 = kk_std_time_calendar__timezone_unbox(_x_x1556, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  }
  else {
    _x_x1555 = kk_std_time_parse__mlift_ptime_10260(x_0_10333, _ctx); /*std/time/calendar/timezone*/
  }
  return kk_std_time_calendar__timezone_box(_x_x1555, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10268_fun1561__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1561(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10268_fun1561(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10268_fun1561, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10268_fun1563__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1563(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10268_fun1563(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10268_fun1563, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10268_fun1564__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1564(kk_function_t _fself, kk_box_t _b_x245, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10268_fun1564(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10268_fun1564, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1564(kk_function_t _fself, kk_box_t _b_x245, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1565;
  kk_char_t _x_x1566 = kk_char_unbox(_b_x245, KK_OWNED, _ctx); /*char*/
  _x_x1565 = kk_std_text_parse_char(_x_x1566, _ctx); /*char*/
  return kk_char_box(_x_x1565, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1563(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x242_250 = (KK_IZ(0)); /*hnd/ev-index*/;
  return kk_std_core_hnd__open_at1(_b_x242_250, kk_std_time_parse__new_mlift_ptime_10268_fun1564(_ctx), kk_char_box('Z', _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10268_fun1567__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1567(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10268_fun1567(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10268_fun1567, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1567(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box('Z', _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10268_fun1570__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1570(kk_function_t _fself, kk_box_t _b_x254, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10268_fun1570(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10268_fun1570, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1570(kk_function_t _fself, kk_box_t _b_x254, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x1571;
  kk_char_t _x_x1572 = kk_char_unbox(_b_x254, KK_OWNED, _ctx); /*char*/
  _x_x1571 = kk_std_time_parse__mlift_ptime_10261(_x_x1572, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x1571, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1561(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_1_10335;
  kk_box_t _x_x1562 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_ptime_10268_fun1563(_ctx), kk_std_time_parse__new_mlift_ptime_10268_fun1567(_ctx), _ctx); /*1542*/
  x_1_10335 = kk_char_unbox(_x_x1562, KK_OWNED, _ctx); /*char*/
  kk_std_time_calendar__timezone _x_x1568;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1569 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10268_fun1570(_ctx), _ctx); /*2419*/
    _x_x1568 = kk_std_time_calendar__timezone_unbox(_x_x1569, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  }
  else {
    _x_x1568 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  return kk_std_time_calendar__timezone_box(_x_x1568, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10268_fun1574__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
  kk_integer_t min;
  kk_std_num_ddouble__ddouble secs;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1574(kk_function_t _fself, kk_box_t _b_x270, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10268_fun1574(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_std_num_ddouble__ddouble secs, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10268_fun1574__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10268_fun1574__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10268_fun1574, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  _self->min = min;
  _self->secs = secs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10268_fun1574(kk_function_t _fself, kk_box_t _b_x270, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10268_fun1574__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10268_fun1574__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_integer_t min = _self->min; /* int */
  kk_std_num_ddouble__ddouble secs = _self->secs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);kk_integer_dup(min, _ctx);kk_std_num_ddouble__ddouble_dup(secs, _ctx);}, {}, _ctx)
  kk_std_time_calendar__timezone tzone_272 = kk_std_time_calendar__timezone_unbox(_b_x270, KK_OWNED, _ctx); /*std/time/calendar/timezone*/;
  kk_std_time_time__time _x_x1575 = kk_std_time_parse__mlift_ptime_10262(cal, date, hour, min, secs, tzone_272, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1575, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10268(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_std_num_ddouble__ddouble secs, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, min : int, secs : std/num/ddouble/ddouble) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_std_time_calendar__timezone x_10331;
  kk_box_t _x_x1545;
  kk_std_core_types__list _x_x1546;
  kk_std_core_types__list _x_x1560 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse__new_mlift_ptime_10268_fun1561(_ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
  _x_x1546 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse__new_mlift_ptime_10268_fun1547(_ctx), _ctx), _x_x1560, _ctx); /*list<79>*/
  _x_x1545 = kk_std_text_parse_choose(_x_x1546, _ctx); /*1639*/
  x_10331 = kk_std_time_calendar__timezone_unbox(_x_x1545, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10331, (KK_I32(3)), _ctx);
    kk_box_t _x_x1573 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10268_fun1574(cal, date, hour, min, secs, _ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x1573, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_10262(cal, date, hour, min, secs, x_10331, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10269_fun1577__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1577(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10269_fun1577(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10269_fun1577, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10269_fun1579__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1579(kk_function_t _fself, kk_box_t _b_x287, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10269_fun1579(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10269_fun1579, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10269_fun1581__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1581(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10269_fun1581(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10269_fun1581, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1581(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1582 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1582, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10269_fun1583__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1583(kk_function_t _fself, kk_box_t _b_x278, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10269_fun1583(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10269_fun1583, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1583(kk_function_t _fself, kk_box_t _b_x278, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1584;
  kk_std_core_types__list _x_x1585 = kk_std_core_types__list_unbox(_b_x278, KK_OWNED, _ctx); /*list<int>*/
  _x_x1584 = kk_std_time_parse__mlift_ptime_10266(_x_x1585, _ctx); /*int*/
  return kk_integer_box(_x_x1584, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10269_fun1586__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1586(kk_function_t _fself, kk_box_t _b_x282, kk_box_t _b_x283, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10269_fun1586(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10269_fun1586, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1586(kk_function_t _fself, kk_box_t _b_x282, kk_box_t _b_x283, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_4_10151;
  kk_integer_t _x_x1587 = kk_integer_unbox(_b_x282, _ctx); /*int*/
  x_4_10151 = kk_integer_mul(_x_x1587,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1588;
  kk_integer_t _x_x1589 = kk_integer_unbox(_b_x283, _ctx); /*int*/
  _x_x1588 = kk_integer_add(x_4_10151,_x_x1589,kk_context()); /*int*/
  return kk_integer_box(_x_x1588, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1579(kk_function_t _fself, kk_box_t _b_x287, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_1_10341;
  kk_integer_t _x_x1580 = kk_integer_unbox(_b_x287, _ctx); /*int*/
  x_1_10341 = kk_std_text_parse_count(_x_x1580, kk_std_time_parse__new_mlift_ptime_10269_fun1581(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_10341, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10269_fun1583(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_1_10341, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_ptime_10269_fun1586(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10269_fun1592__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1592(kk_function_t _fself, kk_box_t _b_x299, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10269_fun1592(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10269_fun1592, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1592(kk_function_t _fself, kk_box_t _b_x299, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1593;
  kk_integer_t _x_x1594 = kk_integer_unbox(_b_x299, _ctx); /*int*/
  _x_x1593 = kk_std_time_parse__mlift_ptime_10267(_x_x1594, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1593, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1577(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x284_288 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_0_10339;
  kk_box_t _x_x1578 = kk_std_core_hnd__open_at1(_b_x284_288, kk_std_time_parse__new_mlift_ptime_10269_fun1579(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
  x_0_10339 = kk_integer_unbox(_x_x1578, _ctx); /*int*/
  kk_std_num_ddouble__ddouble _x_x1590;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_0_10339, _ctx);
    kk_box_t _x_x1591 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10269_fun1592(_ctx), _ctx); /*2419*/
    _x_x1590 = kk_std_num_ddouble__ddouble_unbox(_x_x1591, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    _x_x1590 = kk_std_time_parse__mlift_ptime_10267(x_0_10339, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__ddouble_box(_x_x1590, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10269_fun1595__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1595(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10269_fun1595(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10269_fun1595, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1595(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10269_fun1597__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
  kk_integer_t min;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1597(kk_function_t _fself, kk_box_t _b_x306, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10269_fun1597(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10269_fun1597__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10269_fun1597__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10269_fun1597, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  _self->min = min;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10269_fun1597(kk_function_t _fself, kk_box_t _b_x306, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10269_fun1597__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10269_fun1597__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_integer_t min = _self->min; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);kk_integer_dup(min, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble secs_308 = kk_std_num_ddouble__ddouble_unbox(_b_x306, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_time__time _x_x1598 = kk_std_time_parse__mlift_ptime_10268(cal, date, hour, min, secs_308, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1598, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10269(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_char_t wild___1, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, min : int, wild_@1 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_std_num_ddouble__ddouble x_10337;
  kk_box_t _x_x1576 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_ptime_10269_fun1577(_ctx), kk_std_time_parse__new_mlift_ptime_10269_fun1595(_ctx), _ctx); /*1542*/
  x_10337 = kk_std_num_ddouble__ddouble_unbox(_x_x1576, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1596 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10269_fun1597(cal, date, hour, min, _ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x1596, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_10268(cal, date, hour, min, x_10337, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10270_fun1600__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10270_fun1600(kk_function_t _fself, kk_box_t _b_x312, kk_box_t _b_x313, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10270_fun1600(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10270_fun1600, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10270_fun1600(kk_function_t _fself, kk_box_t _b_x312, kk_box_t _b_x313, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_1_317 = kk_integer_unbox(_b_x312, _ctx); /*int*/;
  kk_integer_t d_0_318 = kk_integer_unbox(_b_x313, _ctx); /*int*/;
  kk_integer_t x_2_10147 = kk_integer_mul(x_1_317,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1601 = kk_integer_add(x_2_10147,d_0_318,kk_context()); /*int*/
  return kk_integer_box(_x_x1601, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_ptime_10270(kk_std_core_types__list _y_x10058, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1599 = kk_std_core_list_foldl(_y_x10058, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_ptime_10270_fun1600(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1599, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10271_fun1603__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10271_fun1603(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10271_fun1603(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10271_fun1603, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10271_fun1604__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10271_fun1604(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10271_fun1604(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10271_fun1604, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10271_fun1604(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1605 = kk_std_text_parse_char(':', _ctx); /*char*/
  return kk_char_box(_x_x1605, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10271_fun1606__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10271_fun1606(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10271_fun1606(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10271_fun1606, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10271_fun1606(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box(':', _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10271_fun1603(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_ptime_10271_fun1604(_ctx), kk_std_time_parse__new_mlift_ptime_10271_fun1606(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10271_fun1608__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
  kk_integer_t min;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10271_fun1608(kk_function_t _fself, kk_box_t _b_x328, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10271_fun1608(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10271_fun1608__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10271_fun1608__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10271_fun1608, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  _self->min = min;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10271_fun1608(kk_function_t _fself, kk_box_t _b_x328, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10271_fun1608__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10271_fun1608__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_integer_t min = _self->min; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);kk_integer_dup(min, _ctx);}, {}, _ctx)
  kk_char_t wild___1_330 = kk_char_unbox(_b_x328, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x1609 = kk_std_time_parse__mlift_ptime_10269(cal, date, hour, min, wild___1_330, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1609, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10271(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, min : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t _b_x321_323 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_10343;
  kk_box_t _x_x1602 = kk_std_core_hnd__open_at0(_b_x321_323, kk_std_time_parse__new_mlift_ptime_10271_fun1603(_ctx), _ctx); /*10426*/
  x_10343 = kk_char_unbox(_x_x1602, KK_OWNED, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1607 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10271_fun1608(cal, date, hour, min, _ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x1607, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_10269(cal, date, hour, min, x_10343, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10272_fun1611__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1611(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10272_fun1611(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10272_fun1611, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10272_fun1612__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1612(kk_function_t _fself, kk_box_t _b_x345, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10272_fun1612(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10272_fun1612, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10272_fun1614__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1614(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10272_fun1614(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10272_fun1614, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1614(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1615 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1615, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10272_fun1616__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1616(kk_function_t _fself, kk_box_t _b_x336, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10272_fun1616(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10272_fun1616, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1616(kk_function_t _fself, kk_box_t _b_x336, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1617;
  kk_std_core_types__list _x_x1618 = kk_std_core_types__list_unbox(_b_x336, KK_OWNED, _ctx); /*list<int>*/
  _x_x1617 = kk_std_time_parse__mlift_ptime_10270(_x_x1618, _ctx); /*int*/
  return kk_integer_box(_x_x1617, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10272_fun1619__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1619(kk_function_t _fself, kk_box_t _b_x340, kk_box_t _b_x341, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10272_fun1619(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10272_fun1619, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1619(kk_function_t _fself, kk_box_t _b_x340, kk_box_t _b_x341, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_2_10147;
  kk_integer_t _x_x1620 = kk_integer_unbox(_b_x340, _ctx); /*int*/
  x_2_10147 = kk_integer_mul(_x_x1620,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1621;
  kk_integer_t _x_x1622 = kk_integer_unbox(_b_x341, _ctx); /*int*/
  _x_x1621 = kk_integer_add(x_2_10147,_x_x1622,kk_context()); /*int*/
  return kk_integer_box(_x_x1621, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1612(kk_function_t _fself, kk_box_t _b_x345, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_0_10347;
  kk_integer_t _x_x1613 = kk_integer_unbox(_b_x345, _ctx); /*int*/
  x_0_10347 = kk_std_text_parse_count(_x_x1613, kk_std_time_parse__new_mlift_ptime_10272_fun1614(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10347, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10272_fun1616(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_0_10347, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_ptime_10272_fun1619(_ctx), _ctx);
  }
}
static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1611(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x342_350 = (KK_IZ(0)); /*hnd/ev-index*/;
  return kk_std_core_hnd__open_at1(_b_x342_350, kk_std_time_parse__new_mlift_ptime_10272_fun1612(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10272_fun1623__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1623(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10272_fun1623(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10272_fun1623, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1623(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_integer_box(kk_integer_from_small(0), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10272_fun1625__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1625(kk_function_t _fself, kk_box_t _b_x360, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10272_fun1625(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10272_fun1625__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10272_fun1625__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10272_fun1625, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10272_fun1625(kk_function_t _fself, kk_box_t _b_x360, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10272_fun1625__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10272_fun1625__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);}, {}, _ctx)
  kk_integer_t min_363 = kk_integer_unbox(_b_x360, _ctx); /*int*/;
  kk_std_time_time__time _x_x1626 = kk_std_time_parse__mlift_ptime_10271(cal, date, hour, min_363, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1626, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10272(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_char_t wild___0, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, wild_@0 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_integer_t x_10345;
  kk_box_t _x_x1610 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_ptime_10272_fun1611(_ctx), kk_std_time_parse__new_mlift_ptime_10272_fun1623(_ctx), _ctx); /*1542*/
  x_10345 = kk_integer_unbox(_x_x1610, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10345, _ctx);
    kk_box_t _x_x1624 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10272_fun1625(cal, date, hour, _ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x1624, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_10271(cal, date, hour, x_10345, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10273_fun1628__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10273_fun1628(kk_function_t _fself, kk_box_t _b_x367, kk_box_t _b_x368, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10273_fun1628(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10273_fun1628, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10273_fun1628(kk_function_t _fself, kk_box_t _b_x367, kk_box_t _b_x368, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_372 = kk_integer_unbox(_b_x367, _ctx); /*int*/;
  kk_integer_t d_373 = kk_integer_unbox(_b_x368, _ctx); /*int*/;
  kk_integer_t x_0_10143 = kk_integer_mul(x_372,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1629 = kk_integer_add(x_0_10143,d_373,kk_context()); /*int*/
  return kk_integer_box(_x_x1629, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_ptime_10273(kk_std_core_types__list _y_x10052, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1627 = kk_std_core_list_foldl(_y_x10052, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_ptime_10273_fun1628(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1627, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10274_fun1631__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10274_fun1631(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10274_fun1631(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10274_fun1631, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10274_fun1632__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10274_fun1632(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10274_fun1632(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10274_fun1632, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10274_fun1632(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1633 = kk_std_text_parse_char(':', _ctx); /*char*/
  return kk_char_box(_x_x1633, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10274_fun1634__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10274_fun1634(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10274_fun1634(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10274_fun1634, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10274_fun1634(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box(':', _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10274_fun1631(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_ptime_10274_fun1632(_ctx), kk_std_time_parse__new_mlift_ptime_10274_fun1634(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10274_fun1636__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10274_fun1636(kk_function_t _fself, kk_box_t _b_x383, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10274_fun1636(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10274_fun1636__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10274_fun1636__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10274_fun1636, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10274_fun1636(kk_function_t _fself, kk_box_t _b_x383, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10274_fun1636__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10274_fun1636__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);}, {}, _ctx)
  kk_char_t wild___0_385 = kk_char_unbox(_b_x383, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x1637 = kk_std_time_parse__mlift_ptime_10272(cal, date, hour, wild___0_385, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1637, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10274(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t _b_x376_378 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_10349;
  kk_box_t _x_x1630 = kk_std_core_hnd__open_at0(_b_x376_378, kk_std_time_parse__new_mlift_ptime_10274_fun1631(_ctx), _ctx); /*10426*/
  x_10349 = kk_char_unbox(_x_x1630, KK_OWNED, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1635 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10274_fun1636(cal, date, hour, _ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x1635, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_10272(cal, date, hour, x_10349, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10275_fun1639__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10275_fun1639(kk_function_t _fself, kk_box_t _b_x400, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10275_fun1639(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10275_fun1639, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10275_fun1641__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10275_fun1641(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10275_fun1641(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10275_fun1641, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10275_fun1641(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1642 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1642, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10275_fun1643__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10275_fun1643(kk_function_t _fself, kk_box_t _b_x391, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10275_fun1643(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10275_fun1643, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10275_fun1643(kk_function_t _fself, kk_box_t _b_x391, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1644;
  kk_std_core_types__list _x_x1645 = kk_std_core_types__list_unbox(_b_x391, KK_OWNED, _ctx); /*list<int>*/
  _x_x1644 = kk_std_time_parse__mlift_ptime_10273(_x_x1645, _ctx); /*int*/
  return kk_integer_box(_x_x1644, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10275_fun1646__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10275_fun1646(kk_function_t _fself, kk_box_t _b_x395, kk_box_t _b_x396, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10275_fun1646(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10275_fun1646, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10275_fun1646(kk_function_t _fself, kk_box_t _b_x395, kk_box_t _b_x396, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_0_10143;
  kk_integer_t _x_x1647 = kk_integer_unbox(_b_x395, _ctx); /*int*/
  x_0_10143 = kk_integer_mul(_x_x1647,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1648;
  kk_integer_t _x_x1649 = kk_integer_unbox(_b_x396, _ctx); /*int*/
  _x_x1648 = kk_integer_add(x_0_10143,_x_x1649,kk_context()); /*int*/
  return kk_integer_box(_x_x1648, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_10275_fun1639(kk_function_t _fself, kk_box_t _b_x400, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_0_10353;
  kk_integer_t _x_x1640 = kk_integer_unbox(_b_x400, _ctx); /*int*/
  x_0_10353 = kk_std_text_parse_count(_x_x1640, kk_std_time_parse__new_mlift_ptime_10275_fun1641(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10353, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10275_fun1643(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_0_10353, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_ptime_10275_fun1646(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10275_fun1651__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse__mlift_ptime_10275_fun1651(kk_function_t _fself, kk_box_t _b_x412, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_10275_fun1651(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10275_fun1651__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_10275_fun1651__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_10275_fun1651, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_10275_fun1651(kk_function_t _fself, kk_box_t _b_x412, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_10275_fun1651__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_10275_fun1651__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_integer_t hour_414 = kk_integer_unbox(_b_x412, _ctx); /*int*/;
  kk_std_time_time__time _x_x1652 = kk_std_time_parse__mlift_ptime_10274(cal, date, hour_414, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1652, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10275(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_char_t wild__, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, wild_ : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t _b_x397_401 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_10351;
  kk_box_t _x_x1638 = kk_std_core_hnd__open_at1(_b_x397_401, kk_std_time_parse__new_mlift_ptime_10275_fun1639(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
  x_10351 = kk_integer_unbox(_x_x1638, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10351, _ctx);
    kk_box_t _x_x1650 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_10275_fun1651(cal, date, _ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x1650, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_10274(cal, date, x_10351, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1654__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1654(kk_function_t _fself, kk_box_t _b_x418, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1654(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1654, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1654(kk_function_t _fself, kk_box_t _b_x418, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1655;
  kk_string_t _x_x1656 = kk_string_unbox(_b_x418); /*string*/
  _x_x1655 = kk_std_text_parse_one_of(_x_x1656, _ctx); /*char*/
  return kk_char_box(_x_x1655, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1661__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse_ptime_fun1661(kk_function_t _fself, kk_box_t _b_x423, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1661(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1661__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun1661__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun1661, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1661(kk_function_t _fself, kk_box_t _b_x423, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1661__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun1661__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_char_t wild___591 = kk_char_unbox(_b_x423, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x1662 = kk_std_time_parse__mlift_ptime_10275(cal, date, wild___591, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1662, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1664__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1664(kk_function_t _fself, kk_box_t _b_x438, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1664(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1664, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun1666__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1666(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1666(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1666, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1666(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1667 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1667, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1668__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1668(kk_function_t _fself, kk_box_t _b_x429, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1668(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1668, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1668(kk_function_t _fself, kk_box_t _b_x429, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1669;
  kk_std_core_types__list _x_x1670 = kk_std_core_types__list_unbox(_b_x429, KK_OWNED, _ctx); /*list<int>*/
  _x_x1669 = kk_std_time_parse__mlift_ptime_10273(_x_x1670, _ctx); /*int*/
  return kk_integer_box(_x_x1669, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1671__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1671(kk_function_t _fself, kk_box_t _b_x433, kk_box_t _b_x434, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1671(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1671, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1671(kk_function_t _fself, kk_box_t _b_x433, kk_box_t _b_x434, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_0_10143;
  kk_integer_t _x_x1672 = kk_integer_unbox(_b_x433, _ctx); /*int*/
  x_0_10143 = kk_integer_mul(_x_x1672,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1673;
  kk_integer_t _x_x1674 = kk_integer_unbox(_b_x434, _ctx); /*int*/
  _x_x1673 = kk_integer_add(x_0_10143,_x_x1674,kk_context()); /*int*/
  return kk_integer_box(_x_x1673, _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun1664(kk_function_t _fself, kk_box_t _b_x438, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_1_10361;
  kk_integer_t _x_x1665 = kk_integer_unbox(_b_x438, _ctx); /*int*/
  x_1_10361 = kk_std_text_parse_count(_x_x1665, kk_std_time_parse_new_ptime_fun1666(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_10361, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1668(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_1_10361, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse_new_ptime_fun1671(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1676__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse_ptime_fun1676(kk_function_t _fself, kk_box_t _b_x450, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1676(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1676__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun1676__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun1676, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1676(kk_function_t _fself, kk_box_t _b_x450, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1676__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun1676__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_integer_t hour_592 = kk_integer_unbox(_b_x450, _ctx); /*int*/;
  kk_std_time_time__time _x_x1677 = kk_std_time_parse__mlift_ptime_10274(cal, date, hour_592, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1677, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1679__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1679(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1679(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1679, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun1680__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1680(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1680(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1680, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1680(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1681 = kk_std_text_parse_char(':', _ctx); /*char*/
  return kk_char_box(_x_x1681, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1682__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1682(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1682(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1682, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1682(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box(':', _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun1679(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse_new_ptime_fun1680(_ctx), kk_std_time_parse_new_ptime_fun1682(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1684__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_0_10358;
};
static kk_box_t kk_std_time_parse_ptime_fun1684(kk_function_t _fself, kk_box_t _b_x460, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1684(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_0_10358, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1684__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun1684__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun1684, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_0_10358 = x_0_10358;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1684(kk_function_t _fself, kk_box_t _b_x460, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1684__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun1684__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_0_10358 = _self->x_0_10358; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_0_10358, _ctx);}, {}, _ctx)
  kk_char_t wild___0_593 = kk_char_unbox(_b_x460, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x1685 = kk_std_time_parse__mlift_ptime_10272(cal, date, x_0_10358, wild___0_593, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1685, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1687__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1687(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1687(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1687, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun1688__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1688(kk_function_t _fself, kk_box_t _b_x475, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1688(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1688, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun1690__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1690(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1690(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1690, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1690(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1691 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1691, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1692__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1692(kk_function_t _fself, kk_box_t _b_x466, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1692(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1692, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1692(kk_function_t _fself, kk_box_t _b_x466, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1693;
  kk_std_core_types__list _x_x1694 = kk_std_core_types__list_unbox(_b_x466, KK_OWNED, _ctx); /*list<int>*/
  _x_x1693 = kk_std_time_parse__mlift_ptime_10270(_x_x1694, _ctx); /*int*/
  return kk_integer_box(_x_x1693, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1695__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1695(kk_function_t _fself, kk_box_t _b_x470, kk_box_t _b_x471, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1695(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1695, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1695(kk_function_t _fself, kk_box_t _b_x470, kk_box_t _b_x471, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_2_10147;
  kk_integer_t _x_x1696 = kk_integer_unbox(_b_x470, _ctx); /*int*/
  x_2_10147 = kk_integer_mul(_x_x1696,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1697;
  kk_integer_t _x_x1698 = kk_integer_unbox(_b_x471, _ctx); /*int*/
  _x_x1697 = kk_integer_add(x_2_10147,_x_x1698,kk_context()); /*int*/
  return kk_integer_box(_x_x1697, _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun1688(kk_function_t _fself, kk_box_t _b_x475, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_4_10369;
  kk_integer_t _x_x1689 = kk_integer_unbox(_b_x475, _ctx); /*int*/
  x_4_10369 = kk_std_text_parse_count(_x_x1689, kk_std_time_parse_new_ptime_fun1690(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_4_10369, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1692(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_4_10369, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse_new_ptime_fun1695(_ctx), _ctx);
  }
}
static kk_box_t kk_std_time_parse_ptime_fun1687(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x472_480 = (KK_IZ(0)); /*hnd/ev-index*/;
  return kk_std_core_hnd__open_at1(_b_x472_480, kk_std_time_parse_new_ptime_fun1688(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1699__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1699(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1699(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1699, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1699(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_integer_box(kk_integer_from_small(0), _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1701__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_0_10358;
};
static kk_box_t kk_std_time_parse_ptime_fun1701(kk_function_t _fself, kk_box_t _b_x490, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1701(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_0_10358, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1701__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun1701__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun1701, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_0_10358 = x_0_10358;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1701(kk_function_t _fself, kk_box_t _b_x490, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1701__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun1701__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_0_10358 = _self->x_0_10358; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_0_10358, _ctx);}, {}, _ctx)
  kk_integer_t min_594 = kk_integer_unbox(_b_x490, _ctx); /*int*/;
  kk_std_time_time__time _x_x1702 = kk_std_time_parse__mlift_ptime_10271(cal, date, x_0_10358, min_594, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1702, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1704__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1704(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1704(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1704, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun1705__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1705(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1705(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1705, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1705(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1706 = kk_std_text_parse_char(':', _ctx); /*char*/
  return kk_char_box(_x_x1706, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1707__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1707(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1707(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1707, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1707(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box(':', _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun1704(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse_new_ptime_fun1705(_ctx), kk_std_time_parse_new_ptime_fun1707(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1709__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_0_10358;
  kk_integer_t x_3_10366;
};
static kk_box_t kk_std_time_parse_ptime_fun1709(kk_function_t _fself, kk_box_t _b_x500, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1709(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_0_10358, kk_integer_t x_3_10366, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1709__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun1709__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun1709, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_0_10358 = x_0_10358;
  _self->x_3_10366 = x_3_10366;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1709(kk_function_t _fself, kk_box_t _b_x500, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1709__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun1709__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_0_10358 = _self->x_0_10358; /* int */
  kk_integer_t x_3_10366 = _self->x_3_10366; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_0_10358, _ctx);kk_integer_dup(x_3_10366, _ctx);}, {}, _ctx)
  kk_char_t wild___1_595 = kk_char_unbox(_b_x500, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x1710 = kk_std_time_parse__mlift_ptime_10269(cal, date, x_0_10358, x_3_10366, wild___1_595, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1710, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1712__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1712(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1712(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1712, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun1714__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1714(kk_function_t _fself, kk_box_t _b_x515, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1714(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1714, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun1716__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1716(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1716(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1716, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1716(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1717 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1717, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1718__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1718(kk_function_t _fself, kk_box_t _b_x506, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1718(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1718, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1718(kk_function_t _fself, kk_box_t _b_x506, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1719;
  kk_std_core_types__list _x_x1720 = kk_std_core_types__list_unbox(_b_x506, KK_OWNED, _ctx); /*list<int>*/
  _x_x1719 = kk_std_time_parse__mlift_ptime_10266(_x_x1720, _ctx); /*int*/
  return kk_integer_box(_x_x1719, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1721__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1721(kk_function_t _fself, kk_box_t _b_x510, kk_box_t _b_x511, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1721(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1721, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1721(kk_function_t _fself, kk_box_t _b_x510, kk_box_t _b_x511, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_4_10151;
  kk_integer_t _x_x1722 = kk_integer_unbox(_b_x510, _ctx); /*int*/
  x_4_10151 = kk_integer_mul(_x_x1722,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1723;
  kk_integer_t _x_x1724 = kk_integer_unbox(_b_x511, _ctx); /*int*/
  _x_x1723 = kk_integer_add(x_4_10151,_x_x1724,kk_context()); /*int*/
  return kk_integer_box(_x_x1723, _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun1714(kk_function_t _fself, kk_box_t _b_x515, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_8_10379;
  kk_integer_t _x_x1715 = kk_integer_unbox(_b_x515, _ctx); /*int*/
  x_8_10379 = kk_std_text_parse_count(_x_x1715, kk_std_time_parse_new_ptime_fun1716(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_8_10379, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1718(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_8_10379, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse_new_ptime_fun1721(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1727__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1727(kk_function_t _fself, kk_box_t _b_x527, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1727(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1727, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1727(kk_function_t _fself, kk_box_t _b_x527, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1728;
  kk_integer_t _x_x1729 = kk_integer_unbox(_b_x527, _ctx); /*int*/
  _x_x1728 = kk_std_time_parse__mlift_ptime_10267(_x_x1729, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1728, _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun1712(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x512_516 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_7_10377;
  kk_box_t _x_x1713 = kk_std_core_hnd__open_at1(_b_x512_516, kk_std_time_parse_new_ptime_fun1714(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
  x_7_10377 = kk_integer_unbox(_x_x1713, _ctx); /*int*/
  kk_std_num_ddouble__ddouble _x_x1725;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_7_10377, _ctx);
    kk_box_t _x_x1726 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1727(_ctx), _ctx); /*2419*/
    _x_x1725 = kk_std_num_ddouble__ddouble_unbox(_x_x1726, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    _x_x1725 = kk_std_time_parse__mlift_ptime_10267(x_7_10377, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__ddouble_box(_x_x1725, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1730__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1730(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1730(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1730, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1730(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1732__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_0_10358;
  kk_integer_t x_3_10366;
};
static kk_box_t kk_std_time_parse_ptime_fun1732(kk_function_t _fself, kk_box_t _b_x534, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1732(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_0_10358, kk_integer_t x_3_10366, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1732__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun1732__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun1732, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_0_10358 = x_0_10358;
  _self->x_3_10366 = x_3_10366;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1732(kk_function_t _fself, kk_box_t _b_x534, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1732__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun1732__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_0_10358 = _self->x_0_10358; /* int */
  kk_integer_t x_3_10366 = _self->x_3_10366; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_0_10358, _ctx);kk_integer_dup(x_3_10366, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble secs_596 = kk_std_num_ddouble__ddouble_unbox(_b_x534, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_time__time _x_x1733 = kk_std_time_parse__mlift_ptime_10268(cal, date, x_0_10358, x_3_10366, secs_596, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1733, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1736__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1736(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1736(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1736, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun1738__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1738(kk_function_t _fself, kk_box_t _b_x538, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1738(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1738, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1738(kk_function_t _fself, kk_box_t _b_x538, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1739;
  kk_string_t _x_x1740 = kk_string_unbox(_b_x538); /*string*/
  _x_x1739 = kk_std_text_parse_one_of(_x_x1740, _ctx); /*char*/
  return kk_char_box(_x_x1739, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1746__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1746(kk_function_t _fself, kk_box_t _b_x543, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1746(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1746, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1746(kk_function_t _fself, kk_box_t _b_x543, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x1747;
  kk_char_t _x_x1748 = kk_char_unbox(_b_x543, KK_OWNED, _ctx); /*char*/
  _x_x1747 = kk_std_time_parse__mlift_ptime_10260(_x_x1748, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x1747, _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun1736(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x535_539 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_10_10384;
  kk_box_t _x_x1737;
  kk_box_t _x_x1741;
  kk_string_t _x_x1742;
  kk_define_string_literal(, _s_x1743, 2, "+-", _ctx)
  _x_x1742 = kk_string_dup(_s_x1743, _ctx); /*string*/
  _x_x1741 = kk_string_box(_x_x1742); /*10539*/
  _x_x1737 = kk_std_core_hnd__open_at1(_b_x535_539, kk_std_time_parse_new_ptime_fun1738(_ctx), _x_x1741, _ctx); /*10540*/
  x_10_10384 = kk_char_unbox(_x_x1737, KK_OWNED, _ctx); /*char*/
  kk_std_time_calendar__timezone _x_x1744;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1745 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1746(_ctx), _ctx); /*2419*/
    _x_x1744 = kk_std_time_calendar__timezone_unbox(_x_x1745, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  }
  else {
    _x_x1744 = kk_std_time_parse__mlift_ptime_10260(x_10_10384, _ctx); /*std/time/calendar/timezone*/
  }
  return kk_std_time_calendar__timezone_box(_x_x1744, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1750__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1750(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1750(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1750, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun1752__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1752(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1752(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1752, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun1753__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1753(kk_function_t _fself, kk_box_t _b_x547, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1753(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1753, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1753(kk_function_t _fself, kk_box_t _b_x547, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1754;
  kk_char_t _x_x1755 = kk_char_unbox(_b_x547, KK_OWNED, _ctx); /*char*/
  _x_x1754 = kk_std_text_parse_char(_x_x1755, _ctx); /*char*/
  return kk_char_box(_x_x1754, _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun1752(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x544_552 = (KK_IZ(0)); /*hnd/ev-index*/;
  return kk_std_core_hnd__open_at1(_b_x544_552, kk_std_time_parse_new_ptime_fun1753(_ctx), kk_char_box('Z', _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1756__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1756(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1756(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1756, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1756(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box('Z', _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1759__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun1759(kk_function_t _fself, kk_box_t _b_x556, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1759(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun1759, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1759(kk_function_t _fself, kk_box_t _b_x556, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x1760;
  kk_char_t _x_x1761 = kk_char_unbox(_b_x556, KK_OWNED, _ctx); /*char*/
  _x_x1760 = kk_std_time_parse__mlift_ptime_10261(_x_x1761, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x1760, _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun1750(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_11_10386;
  kk_box_t _x_x1751 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse_new_ptime_fun1752(_ctx), kk_std_time_parse_new_ptime_fun1756(_ctx), _ctx); /*1542*/
  x_11_10386 = kk_char_unbox(_x_x1751, KK_OWNED, _ctx); /*char*/
  kk_std_time_calendar__timezone _x_x1757;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1758 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1759(_ctx), _ctx); /*2419*/
    _x_x1757 = kk_std_time_calendar__timezone_unbox(_x_x1758, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  }
  else {
    _x_x1757 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  return kk_std_time_calendar__timezone_box(_x_x1757, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1763__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_0_10358;
  kk_integer_t x_3_10366;
  kk_std_num_ddouble__ddouble x_6_10374;
};
static kk_box_t kk_std_time_parse_ptime_fun1763(kk_function_t _fself, kk_box_t _b_x572, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1763(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_0_10358, kk_integer_t x_3_10366, kk_std_num_ddouble__ddouble x_6_10374, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1763__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun1763__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun1763, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_0_10358 = x_0_10358;
  _self->x_3_10366 = x_3_10366;
  _self->x_6_10374 = x_6_10374;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1763(kk_function_t _fself, kk_box_t _b_x572, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1763__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun1763__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_0_10358 = _self->x_0_10358; /* int */
  kk_integer_t x_3_10366 = _self->x_3_10366; /* int */
  kk_std_num_ddouble__ddouble x_6_10374 = _self->x_6_10374; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_0_10358, _ctx);kk_integer_dup(x_3_10366, _ctx);kk_std_num_ddouble__ddouble_dup(x_6_10374, _ctx);}, {}, _ctx)
  kk_std_time_calendar__timezone tzone_597 = kk_std_time_calendar__timezone_unbox(_b_x572, KK_OWNED, _ctx); /*std/time/calendar/timezone*/;
  kk_std_time_time__time _x_x1764 = kk_std_time_parse__mlift_ptime_10262(cal, date, x_0_10358, x_3_10366, x_6_10374, tzone_597, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1764, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun1766__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_0_10358;
  kk_integer_t x_3_10366;
  kk_std_time_calendar__timezone x_9_10381;
  kk_std_num_ddouble__ddouble x_6_10374;
};
static kk_box_t kk_std_time_parse_ptime_fun1766(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun1766(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_0_10358, kk_integer_t x_3_10366, kk_std_time_calendar__timezone x_9_10381, kk_std_num_ddouble__ddouble x_6_10374, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1766__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun1766__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun1766, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_0_10358 = x_0_10358;
  _self->x_3_10366 = x_3_10366;
  _self->x_9_10381 = x_9_10381;
  _self->x_6_10374 = x_6_10374;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun1766(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun1766__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun1766__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_0_10358 = _self->x_0_10358; /* int */
  kk_integer_t x_3_10366 = _self->x_3_10366; /* int */
  kk_std_time_calendar__timezone x_9_10381 = _self->x_9_10381; /* std/time/calendar/timezone */
  kk_std_num_ddouble__ddouble x_6_10374 = _self->x_6_10374; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_0_10358, _ctx);kk_integer_dup(x_3_10366, _ctx);kk_std_time_calendar__timezone_dup(x_9_10381, _ctx);kk_std_num_ddouble__ddouble_dup(x_6_10374, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x1767;
  kk_std_core_types__optional _x_x1768;
  kk_box_t _x_x1769;
  kk_std_time_date__clock _x_x1770 = kk_std_time_date__new_Clock(kk_reuse_null, 0, x_0_10358, x_3_10366, x_6_10374, _ctx); /*std/time/date/clock*/
  _x_x1769 = kk_std_time_date__clock_box(_x_x1770, _ctx); /*7*/
  _x_x1768 = kk_std_core_types__new_Optional(_x_x1769, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1771 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(x_9_10381, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1772 = kk_std_core_types__new_Optional(kk_std_time_calendar__calendar_box(cal, _ctx), _ctx); /*? 7*/
  _x_x1767 = kk_std_time_time_date_fs_time(date, _x_x1768, _x_x1771, _x_x1772, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1767, _ctx);
}

kk_std_time_time__time kk_std_time_parse_ptime(kk_std_time_date__date date, kk_std_time_calendar__calendar cal, kk_context_t* _ctx) { /* (date : std/time/date/date, cal : std/time/calendar/calendar) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t _b_x415_419 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_10355;
  kk_box_t _x_x1653;
  kk_box_t _x_x1657;
  kk_string_t _x_x1658;
  kk_define_string_literal(, _s_x1659, 2, "T ", _ctx)
  _x_x1658 = kk_string_dup(_s_x1659, _ctx); /*string*/
  _x_x1657 = kk_string_box(_x_x1658); /*10539*/
  _x_x1653 = kk_std_core_hnd__open_at1(_b_x415_419, kk_std_time_parse_new_ptime_fun1654(_ctx), _x_x1657, _ctx); /*10540*/
  x_10355 = kk_char_unbox(_x_x1653, KK_OWNED, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1660 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1661(cal, date, _ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x1660, KK_OWNED, _ctx);
  }
  {
    kk_ssize_t _b_x435_439 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_integer_t x_0_10358;
    kk_box_t _x_x1663 = kk_std_core_hnd__open_at1(_b_x435_439, kk_std_time_parse_new_ptime_fun1664(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
    x_0_10358 = kk_integer_unbox(_x_x1663, _ctx); /*int*/
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_10358, _ctx);
      kk_box_t _x_x1675 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1676(cal, date, _ctx), _ctx); /*2419*/
      return kk_std_time_time__time_unbox(_x_x1675, KK_OWNED, _ctx);
    }
    {
      kk_ssize_t _b_x453_455 = (KK_IZ(0)); /*hnd/ev-index*/;
      kk_char_t x_2_10363;
      kk_box_t _x_x1678 = kk_std_core_hnd__open_at0(_b_x453_455, kk_std_time_parse_new_ptime_fun1679(_ctx), _ctx); /*10426*/
      x_2_10363 = kk_char_unbox(_x_x1678, KK_OWNED, _ctx); /*char*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1683 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1684(cal, date, x_0_10358, _ctx), _ctx); /*2419*/
        return kk_std_time_time__time_unbox(_x_x1683, KK_OWNED, _ctx);
      }
      {
        kk_integer_t x_3_10366;
        kk_box_t _x_x1686 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse_new_ptime_fun1687(_ctx), kk_std_time_parse_new_ptime_fun1699(_ctx), _ctx); /*1542*/
        x_3_10366 = kk_integer_unbox(_x_x1686, _ctx); /*int*/
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_3_10366, _ctx);
          kk_box_t _x_x1700 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1701(cal, date, x_0_10358, _ctx), _ctx); /*2419*/
          return kk_std_time_time__time_unbox(_x_x1700, KK_OWNED, _ctx);
        }
        {
          kk_ssize_t _b_x493_495 = (KK_IZ(0)); /*hnd/ev-index*/;
          kk_char_t x_5_10371;
          kk_box_t _x_x1703 = kk_std_core_hnd__open_at0(_b_x493_495, kk_std_time_parse_new_ptime_fun1704(_ctx), _ctx); /*10426*/
          x_5_10371 = kk_char_unbox(_x_x1703, KK_OWNED, _ctx); /*char*/
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1708 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1709(cal, date, x_0_10358, x_3_10366, _ctx), _ctx); /*2419*/
            return kk_std_time_time__time_unbox(_x_x1708, KK_OWNED, _ctx);
          }
          {
            kk_std_num_ddouble__ddouble x_6_10374;
            kk_box_t _x_x1711 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse_new_ptime_fun1712(_ctx), kk_std_time_parse_new_ptime_fun1730(_ctx), _ctx); /*1542*/
            x_6_10374 = kk_std_num_ddouble__ddouble_unbox(_x_x1711, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
            if (kk_yielding(kk_context())) {
              kk_box_t _x_x1731 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1732(cal, date, x_0_10358, x_3_10366, _ctx), _ctx); /*2419*/
              return kk_std_time_time__time_unbox(_x_x1731, KK_OWNED, _ctx);
            }
            {
              kk_std_time_calendar__timezone x_9_10381;
              kk_box_t _x_x1734;
              kk_std_core_types__list _x_x1735;
              kk_std_core_types__list _x_x1749 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse_new_ptime_fun1750(_ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
              _x_x1735 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse_new_ptime_fun1736(_ctx), _ctx), _x_x1749, _ctx); /*list<79>*/
              _x_x1734 = kk_std_text_parse_choose(_x_x1735, _ctx); /*1639*/
              x_9_10381 = kk_std_time_calendar__timezone_unbox(_x_x1734, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
              if (kk_yielding(kk_context())) {
                kk_datatype_ptr_dropn(x_9_10381, (KK_I32(3)), _ctx);
                kk_box_t _x_x1762 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun1763(cal, date, x_0_10358, x_3_10366, x_6_10374, _ctx), _ctx); /*2419*/
                return kk_std_time_time__time_unbox(_x_x1762, KK_OWNED, _ctx);
              }
              {
                kk_ssize_t _b_x576_586 = (KK_IZ(1)); /*hnd/ev-index*/;
                kk_box_t _x_x1765 = kk_std_core_hnd__open_at0(_b_x576_586, kk_std_time_parse_new_ptime_fun1766(cal, date, x_0_10358, x_3_10366, x_9_10381, x_6_10374, _ctx), _ctx); /*10426*/
                return kk_std_time_time__time_unbox(_x_x1765, KK_OWNED, _ctx);
              }
            }
          }
        }
      }
    }
  }
}
extern kk_box_t kk_std_time_parse__mlift_piso_10276_fun1774(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10276_fun1774__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10276_fun1774__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x1775 = kk_std_time_parse_ptime(date, cal, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1775, _ctx);
}
extern kk_box_t kk_std_time_parse__mlift_piso_10276_fun1776(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10276_fun1776__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10276_fun1776__t*, _fself, _ctx);
  kk_std_time_time__time default_4_10039 = _self->default_4_10039; /* std/time/time/time */
  kk_drop_match(_self, {kk_std_time_time__time_dup(default_4_10039, _ctx);}, {}, _ctx)
  return kk_std_time_time__time_box(default_4_10039, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10277_fun1778__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10277_fun1778(kk_function_t _fself, kk_box_t _b_x605, kk_box_t _b_x606, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10277_fun1778(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10277_fun1778, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10277_fun1778(kk_function_t _fself, kk_box_t _b_x605, kk_box_t _b_x606, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_3_610 = kk_integer_unbox(_b_x605, _ctx); /*int*/;
  kk_integer_t d_1_611 = kk_integer_unbox(_b_x606, _ctx); /*int*/;
  kk_integer_t x_4_10181 = kk_integer_mul(x_3_610,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1779 = kk_integer_add(x_4_10181,d_1_611,kk_context()); /*int*/
  return kk_integer_box(_x_x1779, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_piso_10277(kk_std_core_types__list _y_x10100, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1777 = kk_std_core_list_foldl(_y_x10100, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10277_fun1778(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1777, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10279_fun1783__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10279_fun1783(kk_function_t _fself, kk_box_t _b_x630, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10279_fun1783(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10279_fun1783, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10279_fun1785__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10279_fun1785(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10279_fun1785(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10279_fun1785, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10279_fun1785(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1786 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1786, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10279_fun1787__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10279_fun1787(kk_function_t _fself, kk_box_t _b_x621, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10279_fun1787(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10279_fun1787, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10279_fun1787(kk_function_t _fself, kk_box_t _b_x621, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1788;
  kk_std_core_types__list _x_x1789 = kk_std_core_types__list_unbox(_b_x621, KK_OWNED, _ctx); /*list<int>*/
  _x_x1788 = kk_std_time_parse__mlift_piso_10277(_x_x1789, _ctx); /*int*/
  return kk_integer_box(_x_x1788, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10279_fun1790__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10279_fun1790(kk_function_t _fself, kk_box_t _b_x625, kk_box_t _b_x626, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10279_fun1790(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10279_fun1790, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10279_fun1790(kk_function_t _fself, kk_box_t _b_x625, kk_box_t _b_x626, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_4_10181;
  kk_integer_t _x_x1791 = kk_integer_unbox(_b_x625, _ctx); /*int*/
  x_4_10181 = kk_integer_mul(_x_x1791,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1792;
  kk_integer_t _x_x1793 = kk_integer_unbox(_b_x626, _ctx); /*int*/
  _x_x1792 = kk_integer_add(x_4_10181,_x_x1793,kk_context()); /*int*/
  return kk_integer_box(_x_x1792, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10279_fun1783(kk_function_t _fself, kk_box_t _b_x630, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_0_10390;
  kk_integer_t _x_x1784 = kk_integer_unbox(_b_x630, _ctx); /*int*/
  x_0_10390 = kk_std_text_parse_count(_x_x1784, kk_std_time_parse__new_mlift_piso_10279_fun1785(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10390, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10279_fun1787(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_0_10390, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10279_fun1790(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10279_fun1794__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t m;
  kk_integer_t year;
};
static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10279_fun1794(kk_function_t _fself, kk_integer_t d_2, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10279_fun1794(kk_std_time_calendar__calendar calendar, kk_integer_t m, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10279_fun1794__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10279_fun1794__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10279_fun1794, kk_context());
  _self->calendar = calendar;
  _self->m = m;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10279_fun1794(kk_function_t _fself, kk_integer_t d_2, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10279_fun1794__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10279_fun1794__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t m = _self->m; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(m, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_box_t _x_x1795;
  kk_std_time_date__date _x_x1796 = kk_std_time_date__new_Date(year, m, d_2, _ctx); /*std/time/date/date*/
  _x_x1795 = kk_std_time_date__date_box(_x_x1796, _ctx); /*134*/
  return kk_std_core_types__new_Tuple2(_x_x1795, kk_std_time_calendar__calendar_box(calendar, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10279_fun1798__t {
  struct kk_function_s _base;
  kk_function_t next_10389;
};
static kk_box_t kk_std_time_parse__mlift_piso_10279_fun1798(kk_function_t _fself, kk_box_t _b_x646, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10279_fun1798(kk_function_t next_10389, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10279_fun1798__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10279_fun1798__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10279_fun1798, kk_context());
  _self->next_10389 = next_10389;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10279_fun1798(kk_function_t _fself, kk_box_t _b_x646, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10279_fun1798__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10279_fun1798__t*, _fself, _ctx);
  kk_function_t next_10389 = _self->next_10389; /* (int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_10389, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x1799;
  kk_integer_t _x_x1800 = kk_integer_unbox(_b_x646, _ctx); /*int*/
  _x_x1799 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_10389, (next_10389, _x_x1800, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x1799, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10279(kk_std_time_calendar__calendar calendar, kk_integer_t m, kk_integer_t year, kk_char_t wild___0, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, m : int, year : int, wild_@0 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t _b_x627_631 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_10388;
  kk_box_t _x_x1782 = kk_std_core_hnd__open_at1(_b_x627_631, kk_std_time_parse__new_mlift_piso_10279_fun1783(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
  x_10388 = kk_integer_unbox(_x_x1782, _ctx); /*int*/
  kk_function_t next_10389 = kk_std_time_parse__new_mlift_piso_10279_fun1794(calendar, m, year, _ctx); /*(int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar)*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10388, _ctx);
    kk_box_t _x_x1797 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10279_fun1798(next_10389, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x1797, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_10389, (next_10389, x_10388, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10280_fun1802__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10280_fun1802(kk_function_t _fself, kk_box_t _b_x651, kk_box_t _b_x652, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10280_fun1802(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10280_fun1802, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10280_fun1802(kk_function_t _fself, kk_box_t _b_x651, kk_box_t _b_x652, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_1_656 = kk_integer_unbox(_b_x651, _ctx); /*int*/;
  kk_integer_t d_0_657 = kk_integer_unbox(_b_x652, _ctx); /*int*/;
  kk_integer_t x_2_10177 = kk_integer_mul(x_1_656,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1803 = kk_integer_add(x_2_10177,d_0_657,kk_context()); /*int*/
  return kk_integer_box(_x_x1803, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_piso_10280(kk_std_core_types__list _y_x10094, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1801 = kk_std_core_list_foldl(_y_x10094, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10280_fun1802(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1801, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10281_fun1805__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10281_fun1805(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10281_fun1805(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10281_fun1805, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10281_fun1806__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10281_fun1806(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10281_fun1806(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10281_fun1806, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10281_fun1806(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1807 = kk_std_text_parse_char('-', _ctx); /*char*/
  return kk_char_box(_x_x1807, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10281_fun1808__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10281_fun1808(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10281_fun1808(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10281_fun1808, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10281_fun1808(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box('-', _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10281_fun1805(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_piso_10281_fun1806(_ctx), kk_std_time_parse__new_mlift_piso_10281_fun1808(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10281_fun1810__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t m;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10281_fun1810(kk_function_t _fself, kk_box_t _b_x667, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10281_fun1810(kk_std_time_calendar__calendar calendar, kk_integer_t m, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10281_fun1810__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10281_fun1810__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10281_fun1810, kk_context());
  _self->calendar = calendar;
  _self->m = m;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10281_fun1810(kk_function_t _fself, kk_box_t _b_x667, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10281_fun1810__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10281_fun1810__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t m = _self->m; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(m, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_char_t wild___0_669 = kk_char_unbox(_b_x667, KK_OWNED, _ctx); /*char*/;
  kk_std_core_types__tuple2 _x_x1811 = kk_std_time_parse__mlift_piso_10279(calendar, m, year, wild___0_669, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x1811, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10281(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_integer_t m, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, year : int, m : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t _b_x660_662 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_10396;
  kk_box_t _x_x1804 = kk_std_core_hnd__open_at0(_b_x660_662, kk_std_time_parse__new_mlift_piso_10281_fun1805(_ctx), _ctx); /*10426*/
  x_10396 = kk_char_unbox(_x_x1804, KK_OWNED, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1809 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10281_fun1810(calendar, m, year, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x1809, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_10279(calendar, m, year, x_10396, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10282_fun1813__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10282_fun1813(kk_function_t _fself, kk_box_t _b_x673, kk_box_t _b_x674, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10282_fun1813(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10282_fun1813, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10282_fun1813(kk_function_t _fself, kk_box_t _b_x673, kk_box_t _b_x674, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_7_678 = kk_integer_unbox(_b_x673, _ctx); /*int*/;
  kk_integer_t d_4_679 = kk_integer_unbox(_b_x674, _ctx); /*int*/;
  kk_integer_t x_8_10189 = kk_integer_mul(x_7_678,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1814 = kk_integer_add(x_8_10189,d_4_679,kk_context()); /*int*/
  return kk_integer_box(_x_x1814, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_piso_10282(kk_std_core_types__list _y_x10110, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1812 = kk_std_core_list_foldl(_y_x10110, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10282_fun1813(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1812, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10284_fun1820__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1820(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10284_fun1820(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10284_fun1820, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10284_fun1821__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1821(kk_function_t _fself, kk_box_t _b_x698, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10284_fun1821(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10284_fun1821, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10284_fun1823__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1823(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10284_fun1823(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10284_fun1823, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1823(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1824 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1824, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10284_fun1825__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1825(kk_function_t _fself, kk_box_t _b_x689, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10284_fun1825(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10284_fun1825, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1825(kk_function_t _fself, kk_box_t _b_x689, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1826;
  kk_std_core_types__list _x_x1827 = kk_std_core_types__list_unbox(_b_x689, KK_OWNED, _ctx); /*list<int>*/
  _x_x1826 = kk_std_time_parse__mlift_piso_10282(_x_x1827, _ctx); /*int*/
  return kk_integer_box(_x_x1826, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10284_fun1828__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1828(kk_function_t _fself, kk_box_t _b_x693, kk_box_t _b_x694, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10284_fun1828(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10284_fun1828, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1828(kk_function_t _fself, kk_box_t _b_x693, kk_box_t _b_x694, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_8_10189;
  kk_integer_t _x_x1829 = kk_integer_unbox(_b_x693, _ctx); /*int*/
  x_8_10189 = kk_integer_mul(_x_x1829,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1830;
  kk_integer_t _x_x1831 = kk_integer_unbox(_b_x694, _ctx); /*int*/
  _x_x1830 = kk_integer_add(x_8_10189,_x_x1831,kk_context()); /*int*/
  return kk_integer_box(_x_x1830, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1821(kk_function_t _fself, kk_box_t _b_x698, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_0_10400;
  kk_integer_t _x_x1822 = kk_integer_unbox(_b_x698, _ctx); /*int*/
  x_0_10400 = kk_std_text_parse_count(_x_x1822, kk_std_time_parse__new_mlift_piso_10284_fun1823(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10400, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10284_fun1825(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_0_10400, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10284_fun1828(_ctx), _ctx);
  }
}
static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1820(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x695_703 = (KK_IZ(0)); /*hnd/ev-index*/;
  return kk_std_core_hnd__open_at1(_b_x695_703, kk_std_time_parse__new_mlift_piso_10284_fun1821(_ctx), kk_integer_box(kk_integer_from_small(1), _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10284_fun1832__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1832(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10284_fun1832(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10284_fun1832, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1832(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_integer_box(kk_integer_from_small(1), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10284_fun1833__t {
  struct kk_function_s _base;
  kk_integer_t w;
  kk_integer_t year;
};
static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10284_fun1833(kk_function_t _fself, kk_integer_t d_0_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10284_fun1833(kk_integer_t w, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10284_fun1833__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10284_fun1833__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10284_fun1833, kk_context());
  _self->w = w;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10284_fun1833(kk_function_t _fself, kk_integer_t d_0_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10284_fun1833__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10284_fun1833__t*, _fself, _ctx);
  kk_integer_t w = _self->w; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(w, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_box_t _x_x1834;
  kk_std_time_date__date _x_x1835 = kk_std_time_date__new_Date(year, w, d_0_0, _ctx); /*std/time/date/date*/
  _x_x1834 = kk_std_time_date__date_box(_x_x1835, _ctx); /*134*/
  kk_box_t _x_x1836;
  kk_std_time_calendar__calendar _x_x1837 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_week, _ctx); /*std/time/calendar/calendar*/
  _x_x1836 = kk_std_time_calendar__calendar_box(_x_x1837, _ctx); /*135*/
  return kk_std_core_types__new_Tuple2(_x_x1834, _x_x1836, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10284_fun1839__t {
  struct kk_function_s _base;
  kk_function_t next_10399;
};
static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1839(kk_function_t _fself, kk_box_t _b_x717, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10284_fun1839(kk_function_t next_10399, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10284_fun1839__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10284_fun1839__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10284_fun1839, kk_context());
  _self->next_10399 = next_10399;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10284_fun1839(kk_function_t _fself, kk_box_t _b_x717, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10284_fun1839__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10284_fun1839__t*, _fself, _ctx);
  kk_function_t next_10399 = _self->next_10399; /* (int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_10399, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x1840;
  kk_integer_t _x_x1841 = kk_integer_unbox(_b_x717, _ctx); /*int*/
  _x_x1840 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_10399, (next_10399, _x_x1841, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x1840, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10284(kk_integer_t w, kk_integer_t year, kk_char_t wild___2, kk_context_t* _ctx) { /* (w : int, year : int, wild_@2 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_integer_t x_10398;
  kk_box_t _x_x1819 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_piso_10284_fun1820(_ctx), kk_std_time_parse__new_mlift_piso_10284_fun1832(_ctx), _ctx); /*1542*/
  x_10398 = kk_integer_unbox(_x_x1819, _ctx); /*int*/
  kk_function_t next_10399 = kk_std_time_parse__new_mlift_piso_10284_fun1833(w, year, _ctx); /*(int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar)*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10398, _ctx);
    kk_box_t _x_x1838 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10284_fun1839(next_10399, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x1838, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_10399, (next_10399, x_10398, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10285_fun1843__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10285_fun1843(kk_function_t _fself, kk_box_t _b_x723, kk_box_t _b_x724, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10285_fun1843(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10285_fun1843, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10285_fun1843(kk_function_t _fself, kk_box_t _b_x723, kk_box_t _b_x724, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_5_728 = kk_integer_unbox(_b_x723, _ctx); /*int*/;
  kk_integer_t d_3_729 = kk_integer_unbox(_b_x724, _ctx); /*int*/;
  kk_integer_t x_6_10185 = kk_integer_mul(x_5_728,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1844 = kk_integer_add(x_6_10185,d_3_729,kk_context()); /*int*/
  return kk_integer_box(_x_x1844, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_piso_10285(kk_std_core_types__list _y_x10104, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1842 = kk_std_core_list_foldl(_y_x10104, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10285_fun1843(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1842, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10286_fun1846__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10286_fun1846(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10286_fun1846(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10286_fun1846, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10286_fun1847__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10286_fun1847(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10286_fun1847(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10286_fun1847, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10286_fun1847(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1848 = kk_std_text_parse_char('-', _ctx); /*char*/
  return kk_char_box(_x_x1848, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10286_fun1849__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10286_fun1849(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10286_fun1849(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10286_fun1849, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10286_fun1849(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box('-', _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10286_fun1846(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_piso_10286_fun1847(_ctx), kk_std_time_parse__new_mlift_piso_10286_fun1849(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10286_fun1851__t {
  struct kk_function_s _base;
  kk_integer_t w;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10286_fun1851(kk_function_t _fself, kk_box_t _b_x739, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10286_fun1851(kk_integer_t w, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10286_fun1851__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10286_fun1851__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10286_fun1851, kk_context());
  _self->w = w;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10286_fun1851(kk_function_t _fself, kk_box_t _b_x739, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10286_fun1851__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10286_fun1851__t*, _fself, _ctx);
  kk_integer_t w = _self->w; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(w, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_char_t wild___2_741 = kk_char_unbox(_b_x739, KK_OWNED, _ctx); /*char*/;
  kk_std_core_types__tuple2 _x_x1852 = kk_std_time_parse__mlift_piso_10284(w, year, wild___2_741, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x1852, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10286(kk_integer_t year, kk_integer_t w, kk_context_t* _ctx) { /* (year : int, w : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t _b_x732_734 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_10405;
  kk_box_t _x_x1845 = kk_std_core_hnd__open_at0(_b_x732_734, kk_std_time_parse__new_mlift_piso_10286_fun1846(_ctx), _ctx); /*10426*/
  x_10405 = kk_char_unbox(_x_x1845, KK_OWNED, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1850 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10286_fun1851(w, year, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x1850, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_10284(w, year, x_10405, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10287_fun1854__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10287_fun1854(kk_function_t _fself, kk_box_t _b_x756, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10287_fun1854(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10287_fun1854, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10287_fun1856__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10287_fun1856(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10287_fun1856(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10287_fun1856, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10287_fun1856(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1857 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1857, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10287_fun1858__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10287_fun1858(kk_function_t _fself, kk_box_t _b_x747, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10287_fun1858(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10287_fun1858, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10287_fun1858(kk_function_t _fself, kk_box_t _b_x747, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1859;
  kk_std_core_types__list _x_x1860 = kk_std_core_types__list_unbox(_b_x747, KK_OWNED, _ctx); /*list<int>*/
  _x_x1859 = kk_std_time_parse__mlift_piso_10285(_x_x1860, _ctx); /*int*/
  return kk_integer_box(_x_x1859, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10287_fun1861__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10287_fun1861(kk_function_t _fself, kk_box_t _b_x751, kk_box_t _b_x752, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10287_fun1861(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10287_fun1861, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10287_fun1861(kk_function_t _fself, kk_box_t _b_x751, kk_box_t _b_x752, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_6_10185;
  kk_integer_t _x_x1862 = kk_integer_unbox(_b_x751, _ctx); /*int*/
  x_6_10185 = kk_integer_mul(_x_x1862,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1863;
  kk_integer_t _x_x1864 = kk_integer_unbox(_b_x752, _ctx); /*int*/
  _x_x1863 = kk_integer_add(x_6_10185,_x_x1864,kk_context()); /*int*/
  return kk_integer_box(_x_x1863, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10287_fun1854(kk_function_t _fself, kk_box_t _b_x756, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_0_10409;
  kk_integer_t _x_x1855 = kk_integer_unbox(_b_x756, _ctx); /*int*/
  x_0_10409 = kk_std_text_parse_count(_x_x1855, kk_std_time_parse__new_mlift_piso_10287_fun1856(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10409, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10287_fun1858(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_0_10409, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10287_fun1861(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10287_fun1866__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10287_fun1866(kk_function_t _fself, kk_box_t _b_x768, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10287_fun1866(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10287_fun1866__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10287_fun1866__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10287_fun1866, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10287_fun1866(kk_function_t _fself, kk_box_t _b_x768, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10287_fun1866__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10287_fun1866__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_integer_t w_770 = kk_integer_unbox(_b_x768, _ctx); /*int*/;
  kk_std_core_types__tuple2 _x_x1867 = kk_std_time_parse__mlift_piso_10286(year, w_770, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x1867, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10287(kk_integer_t year, kk_char_t wild___1, kk_context_t* _ctx) { /* (year : int, wild_@1 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t _b_x753_757 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_10407;
  kk_box_t _x_x1853 = kk_std_core_hnd__open_at1(_b_x753_757, kk_std_time_parse__new_mlift_piso_10287_fun1854(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
  x_10407 = kk_integer_unbox(_x_x1853, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10407, _ctx);
    kk_box_t _x_x1865 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10287_fun1866(year, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x1865, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_10286(year, x_10407, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10288_fun1869__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10288_fun1869(kk_function_t _fself, kk_box_t _b_x774, kk_box_t _b_x775, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10288_fun1869(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10288_fun1869, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10288_fun1869(kk_function_t _fself, kk_box_t _b_x774, kk_box_t _b_x775, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_9_779 = kk_integer_unbox(_b_x774, _ctx); /*int*/;
  kk_integer_t d_5_780 = kk_integer_unbox(_b_x775, _ctx); /*int*/;
  kk_integer_t x_10_10192 = kk_integer_mul(x_9_779,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1870 = kk_integer_add(x_10_10192,d_5_780,kk_context()); /*int*/
  return kk_integer_box(_x_x1870, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_piso_10288(kk_std_core_types__list _y_x10114, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1868 = kk_std_core_list_foldl(_y_x10114, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10288_fun1869(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1868, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10290_fun1874__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10290_fun1874(kk_function_t _fself, kk_box_t _b_x788, kk_box_t _b_x789, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10290_fun1874(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10290_fun1874, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10290_fun1874(kk_function_t _fself, kk_box_t _b_x788, kk_box_t _b_x789, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_13_793 = kk_integer_unbox(_b_x788, _ctx); /*int*/;
  kk_integer_t d_7_794 = kk_integer_unbox(_b_x789, _ctx); /*int*/;
  kk_integer_t x_14_10200 = kk_integer_mul(x_13_793,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1875 = kk_integer_add(x_14_10200,d_7_794,kk_context()); /*int*/
  return kk_integer_box(_x_x1875, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_piso_10290(kk_std_core_types__list _y_x10124, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1873 = kk_std_core_list_foldl(_y_x10124, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10290_fun1874(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1873, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10292_fun1881__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10292_fun1881(kk_function_t _fself, kk_box_t _b_x813, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10292_fun1881(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10292_fun1881, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10292_fun1883__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10292_fun1883(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10292_fun1883(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10292_fun1883, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10292_fun1883(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1884 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1884, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10292_fun1885__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10292_fun1885(kk_function_t _fself, kk_box_t _b_x804, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10292_fun1885(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10292_fun1885, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10292_fun1885(kk_function_t _fself, kk_box_t _b_x804, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1886;
  kk_std_core_types__list _x_x1887 = kk_std_core_types__list_unbox(_b_x804, KK_OWNED, _ctx); /*list<int>*/
  _x_x1886 = kk_std_time_parse__mlift_piso_10290(_x_x1887, _ctx); /*int*/
  return kk_integer_box(_x_x1886, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10292_fun1888__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10292_fun1888(kk_function_t _fself, kk_box_t _b_x808, kk_box_t _b_x809, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10292_fun1888(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10292_fun1888, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10292_fun1888(kk_function_t _fself, kk_box_t _b_x808, kk_box_t _b_x809, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_14_10200;
  kk_integer_t _x_x1889 = kk_integer_unbox(_b_x808, _ctx); /*int*/
  x_14_10200 = kk_integer_mul(_x_x1889,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1890;
  kk_integer_t _x_x1891 = kk_integer_unbox(_b_x809, _ctx); /*int*/
  _x_x1890 = kk_integer_add(x_14_10200,_x_x1891,kk_context()); /*int*/
  return kk_integer_box(_x_x1890, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10292_fun1881(kk_function_t _fself, kk_box_t _b_x813, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_0_10413;
  kk_integer_t _x_x1882 = kk_integer_unbox(_b_x813, _ctx); /*int*/
  x_0_10413 = kk_std_text_parse_count(_x_x1882, kk_std_time_parse__new_mlift_piso_10292_fun1883(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10413, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10292_fun1885(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_0_10413, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10292_fun1888(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10292_fun1892__t {
  struct kk_function_s _base;
  kk_integer_t m_0;
  kk_integer_t year;
};
static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10292_fun1892(kk_function_t _fself, kk_integer_t d_2_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10292_fun1892(kk_integer_t m_0, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10292_fun1892__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10292_fun1892__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10292_fun1892, kk_context());
  _self->m_0 = m_0;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10292_fun1892(kk_function_t _fself, kk_integer_t d_2_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10292_fun1892__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10292_fun1892__t*, _fself, _ctx);
  kk_integer_t m_0 = _self->m_0; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(m_0, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_box_t _x_x1893;
  kk_std_time_date__date _x_x1894 = kk_std_time_date__new_Date(year, m_0, d_2_0, _ctx); /*std/time/date/date*/
  _x_x1893 = kk_std_time_date__date_box(_x_x1894, _ctx); /*134*/
  kk_box_t _x_x1895;
  kk_std_time_calendar__calendar _x_x1896 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_month, _ctx); /*std/time/calendar/calendar*/
  _x_x1895 = kk_std_time_calendar__calendar_box(_x_x1896, _ctx); /*135*/
  return kk_std_core_types__new_Tuple2(_x_x1893, _x_x1895, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10292_fun1898__t {
  struct kk_function_s _base;
  kk_function_t next_10412;
};
static kk_box_t kk_std_time_parse__mlift_piso_10292_fun1898(kk_function_t _fself, kk_box_t _b_x829, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10292_fun1898(kk_function_t next_10412, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10292_fun1898__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10292_fun1898__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10292_fun1898, kk_context());
  _self->next_10412 = next_10412;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10292_fun1898(kk_function_t _fself, kk_box_t _b_x829, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10292_fun1898__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10292_fun1898__t*, _fself, _ctx);
  kk_function_t next_10412 = _self->next_10412; /* (int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_10412, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x1899;
  kk_integer_t _x_x1900 = kk_integer_unbox(_b_x829, _ctx); /*int*/
  _x_x1899 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_10412, (next_10412, _x_x1900, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x1899, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10292(kk_integer_t m_0, kk_integer_t year, kk_char_t wild___4, kk_context_t* _ctx) { /* (m@0 : int, year : int, wild_@4 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t _b_x810_814 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_10411;
  kk_box_t _x_x1880 = kk_std_core_hnd__open_at1(_b_x810_814, kk_std_time_parse__new_mlift_piso_10292_fun1881(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
  x_10411 = kk_integer_unbox(_x_x1880, _ctx); /*int*/
  kk_function_t next_10412 = kk_std_time_parse__new_mlift_piso_10292_fun1892(m_0, year, _ctx); /*(int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar)*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10411, _ctx);
    kk_box_t _x_x1897 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10292_fun1898(next_10412, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x1897, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_10412, (next_10412, x_10411, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10293_fun1902__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10293_fun1902(kk_function_t _fself, kk_box_t _b_x834, kk_box_t _b_x835, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10293_fun1902(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10293_fun1902, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10293_fun1902(kk_function_t _fself, kk_box_t _b_x834, kk_box_t _b_x835, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_11_839 = kk_integer_unbox(_b_x834, _ctx); /*int*/;
  kk_integer_t d_6_840 = kk_integer_unbox(_b_x835, _ctx); /*int*/;
  kk_integer_t x_12_10196 = kk_integer_mul(x_11_839,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1903 = kk_integer_add(x_12_10196,d_6_840,kk_context()); /*int*/
  return kk_integer_box(_x_x1903, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_piso_10293(kk_std_core_types__list _y_x10118, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1901 = kk_std_core_list_foldl(_y_x10118, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10293_fun1902(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1901, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10294_fun1905__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10294_fun1905(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10294_fun1905(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10294_fun1905, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10294_fun1906__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10294_fun1906(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10294_fun1906(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10294_fun1906, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10294_fun1906(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1907 = kk_std_text_parse_char('-', _ctx); /*char*/
  return kk_char_box(_x_x1907, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10294_fun1908__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10294_fun1908(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10294_fun1908(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10294_fun1908, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10294_fun1908(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box('-', _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10294_fun1905(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_piso_10294_fun1906(_ctx), kk_std_time_parse__new_mlift_piso_10294_fun1908(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10294_fun1910__t {
  struct kk_function_s _base;
  kk_integer_t m_0;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10294_fun1910(kk_function_t _fself, kk_box_t _b_x850, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10294_fun1910(kk_integer_t m_0, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10294_fun1910__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10294_fun1910__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10294_fun1910, kk_context());
  _self->m_0 = m_0;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10294_fun1910(kk_function_t _fself, kk_box_t _b_x850, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10294_fun1910__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10294_fun1910__t*, _fself, _ctx);
  kk_integer_t m_0 = _self->m_0; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(m_0, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_char_t wild___4_852 = kk_char_unbox(_b_x850, KK_OWNED, _ctx); /*char*/;
  kk_std_core_types__tuple2 _x_x1911 = kk_std_time_parse__mlift_piso_10292(m_0, year, wild___4_852, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x1911, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10294(kk_integer_t year, kk_integer_t m_0, kk_context_t* _ctx) { /* (year : int, m@0 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t _b_x843_845 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_10418;
  kk_box_t _x_x1904 = kk_std_core_hnd__open_at0(_b_x843_845, kk_std_time_parse__new_mlift_piso_10294_fun1905(_ctx), _ctx); /*10426*/
  x_10418 = kk_char_unbox(_x_x1904, KK_OWNED, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1909 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10294_fun1910(m_0, year, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x1909, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_10292(m_0, year, x_10418, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10295_fun1913__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10295_fun1913(kk_function_t _fself, kk_box_t _b_x867, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10295_fun1913(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10295_fun1913, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10295_fun1915__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10295_fun1915(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10295_fun1915(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10295_fun1915, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10295_fun1915(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1916 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1916, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10295_fun1917__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10295_fun1917(kk_function_t _fself, kk_box_t _b_x858, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10295_fun1917(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10295_fun1917, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10295_fun1917(kk_function_t _fself, kk_box_t _b_x858, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1918;
  kk_std_core_types__list _x_x1919 = kk_std_core_types__list_unbox(_b_x858, KK_OWNED, _ctx); /*list<int>*/
  _x_x1918 = kk_std_time_parse__mlift_piso_10293(_x_x1919, _ctx); /*int*/
  return kk_integer_box(_x_x1918, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10295_fun1920__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10295_fun1920(kk_function_t _fself, kk_box_t _b_x862, kk_box_t _b_x863, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10295_fun1920(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10295_fun1920, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10295_fun1920(kk_function_t _fself, kk_box_t _b_x862, kk_box_t _b_x863, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_12_10196;
  kk_integer_t _x_x1921 = kk_integer_unbox(_b_x862, _ctx); /*int*/
  x_12_10196 = kk_integer_mul(_x_x1921,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1922;
  kk_integer_t _x_x1923 = kk_integer_unbox(_b_x863, _ctx); /*int*/
  _x_x1922 = kk_integer_add(x_12_10196,_x_x1923,kk_context()); /*int*/
  return kk_integer_box(_x_x1922, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10295_fun1913(kk_function_t _fself, kk_box_t _b_x867, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_0_10422;
  kk_integer_t _x_x1914 = kk_integer_unbox(_b_x867, _ctx); /*int*/
  x_0_10422 = kk_std_text_parse_count(_x_x1914, kk_std_time_parse__new_mlift_piso_10295_fun1915(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10422, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10295_fun1917(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_0_10422, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10295_fun1920(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10295_fun1925__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10295_fun1925(kk_function_t _fself, kk_box_t _b_x879, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10295_fun1925(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10295_fun1925__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10295_fun1925__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10295_fun1925, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10295_fun1925(kk_function_t _fself, kk_box_t _b_x879, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10295_fun1925__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10295_fun1925__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_integer_t m_0_881 = kk_integer_unbox(_b_x879, _ctx); /*int*/;
  kk_std_core_types__tuple2 _x_x1926 = kk_std_time_parse__mlift_piso_10294(year, m_0_881, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x1926, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10295(kk_integer_t year, kk_char_t wild___3, kk_context_t* _ctx) { /* (year : int, wild_@3 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t _b_x864_868 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_10420;
  kk_box_t _x_x1912 = kk_std_core_hnd__open_at1(_b_x864_868, kk_std_time_parse__new_mlift_piso_10295_fun1913(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
  x_10420 = kk_integer_unbox(_x_x1912, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10420, _ctx);
    kk_box_t _x_x1924 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10295_fun1925(year, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x1924, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_10294(year, x_10420, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10296_fun1928__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10296_fun1928(kk_function_t _fself, kk_box_t _b_x885, kk_box_t _b_x886, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10296_fun1928(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10296_fun1928, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10296_fun1928(kk_function_t _fself, kk_box_t _b_x885, kk_box_t _b_x886, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_15_890 = kk_integer_unbox(_b_x885, _ctx); /*int*/;
  kk_integer_t d_8_891 = kk_integer_unbox(_b_x886, _ctx); /*int*/;
  kk_integer_t x_16_10204 = kk_integer_mul(x_15_890,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x1929 = kk_integer_add(x_16_10204,d_8_891,kk_context()); /*int*/
  return kk_integer_box(_x_x1929, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_piso_10296(kk_std_core_types__list _y_x10128, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x1927 = kk_std_core_list_foldl(_y_x10128, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10296_fun1928(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x1927, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10298_fun1935__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10298_fun1935(kk_function_t _fself, kk_box_t _b_x910, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10298_fun1935(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10298_fun1935, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10298_fun1937__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10298_fun1937(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10298_fun1937(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10298_fun1937, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10298_fun1937(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1938 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1938, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10298_fun1939__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10298_fun1939(kk_function_t _fself, kk_box_t _b_x901, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10298_fun1939(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10298_fun1939, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10298_fun1939(kk_function_t _fself, kk_box_t _b_x901, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1940;
  kk_std_core_types__list _x_x1941 = kk_std_core_types__list_unbox(_b_x901, KK_OWNED, _ctx); /*list<int>*/
  _x_x1940 = kk_std_time_parse__mlift_piso_10296(_x_x1941, _ctx); /*int*/
  return kk_integer_box(_x_x1940, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10298_fun1942__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10298_fun1942(kk_function_t _fself, kk_box_t _b_x905, kk_box_t _b_x906, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10298_fun1942(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10298_fun1942, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10298_fun1942(kk_function_t _fself, kk_box_t _b_x905, kk_box_t _b_x906, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_16_10204;
  kk_integer_t _x_x1943 = kk_integer_unbox(_b_x905, _ctx); /*int*/
  x_16_10204 = kk_integer_mul(_x_x1943,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1944;
  kk_integer_t _x_x1945 = kk_integer_unbox(_b_x906, _ctx); /*int*/
  _x_x1944 = kk_integer_add(x_16_10204,_x_x1945,kk_context()); /*int*/
  return kk_integer_box(_x_x1944, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10298_fun1935(kk_function_t _fself, kk_box_t _b_x910, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_0_10426;
  kk_integer_t _x_x1936 = kk_integer_unbox(_b_x910, _ctx); /*int*/
  x_0_10426 = kk_std_text_parse_count(_x_x1936, kk_std_time_parse__new_mlift_piso_10298_fun1937(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10426, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10298_fun1939(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_0_10426, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10298_fun1942(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10298_fun1946__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10298_fun1946(kk_function_t _fself, kk_integer_t d_3_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10298_fun1946(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10298_fun1946__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10298_fun1946__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10298_fun1946, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10298_fun1946(kk_function_t _fself, kk_integer_t d_3_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10298_fun1946__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10298_fun1946__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_box_t _x_x1947;
  kk_std_time_date__date _x_x1948 = kk_std_time_date__new_Date(year, kk_integer_from_small(1), d_3_0, _ctx); /*std/time/date/date*/
  _x_x1947 = kk_std_time_date__date_box(_x_x1948, _ctx); /*134*/
  kk_box_t _x_x1949;
  kk_std_time_calendar__calendar _x_x1950 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_month, _ctx); /*std/time/calendar/calendar*/
  _x_x1949 = kk_std_time_calendar__calendar_box(_x_x1950, _ctx); /*135*/
  return kk_std_core_types__new_Tuple2(_x_x1947, _x_x1949, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10298_fun1952__t {
  struct kk_function_s _base;
  kk_function_t next_10425;
};
static kk_box_t kk_std_time_parse__mlift_piso_10298_fun1952(kk_function_t _fself, kk_box_t _b_x926, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10298_fun1952(kk_function_t next_10425, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10298_fun1952__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10298_fun1952__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10298_fun1952, kk_context());
  _self->next_10425 = next_10425;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10298_fun1952(kk_function_t _fself, kk_box_t _b_x926, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10298_fun1952__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10298_fun1952__t*, _fself, _ctx);
  kk_function_t next_10425 = _self->next_10425; /* (int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_10425, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x1953;
  kk_integer_t _x_x1954 = kk_integer_unbox(_b_x926, _ctx); /*int*/
  _x_x1953 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_10425, (next_10425, _x_x1954, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x1953, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10298(kk_integer_t year, kk_char_t wild___5, kk_context_t* _ctx) { /* (year : int, wild_@5 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t _b_x907_911 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_10424;
  kk_box_t _x_x1934 = kk_std_core_hnd__open_at1(_b_x907_911, kk_std_time_parse__new_mlift_piso_10298_fun1935(_ctx), kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*10540*/
  x_10424 = kk_integer_unbox(_x_x1934, _ctx); /*int*/
  kk_function_t next_10425 = kk_std_time_parse__new_mlift_piso_10298_fun1946(year, _ctx); /*(int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar)*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10424, _ctx);
    kk_box_t _x_x1951 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10298_fun1952(next_10425, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x1951, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_10425, (next_10425, x_10424, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10299_fun1958__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse__mlift_piso_10299_fun1958(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10299_fun1958(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10299_fun1958__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10299_fun1958__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10299_fun1958, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10299_fun1958(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10299_fun1958__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10299_fun1958__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x1959;
  kk_std_core_types__optional _x_x1960 = kk_std_core_types__new_Optional(kk_std_time_calendar__calendar_box(cal, _ctx), _ctx); /*? 7*/
  _x_x1959 = kk_std_time_time_date_fs_time(date, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _x_x1960, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1959, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10299_fun1961__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_std_time_time__time kk_std_time_parse__mlift_piso_10299_fun1961(kk_function_t _fself, kk_std_time_time__time default_4_10039, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10299_fun1961(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10299_fun1961__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10299_fun1961__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10299_fun1961, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10299_fun1963__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse__mlift_piso_10299_fun1963(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10299_fun1963(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10299_fun1963__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10299_fun1963__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10299_fun1963, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10299_fun1963(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10299_fun1963__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10299_fun1963__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x1964 = kk_std_time_parse_ptime(date, cal, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1964, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10299_fun1965__t {
  struct kk_function_s _base;
  kk_std_time_time__time default_4_10039;
};
static kk_box_t kk_std_time_parse__mlift_piso_10299_fun1965(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10299_fun1965(kk_std_time_time__time default_4_10039, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10299_fun1965__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10299_fun1965__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10299_fun1965, kk_context());
  _self->default_4_10039 = default_4_10039;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10299_fun1965(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10299_fun1965__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10299_fun1965__t*, _fself, _ctx);
  kk_std_time_time__time default_4_10039 = _self->default_4_10039; /* std/time/time/time */
  kk_drop_match(_self, {kk_std_time_time__time_dup(default_4_10039, _ctx);}, {}, _ctx)
  return kk_std_time_time__time_box(default_4_10039, _ctx);
}
static kk_std_time_time__time kk_std_time_parse__mlift_piso_10299_fun1961(kk_function_t _fself, kk_std_time_time__time default_4_10039, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10299_fun1961__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10299_fun1961__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_box_t _x_x1962 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_piso_10299_fun1963(cal, date, _ctx), kk_std_time_parse__new_mlift_piso_10299_fun1965(default_4_10039, _ctx), _ctx); /*1542*/
  return kk_std_time_time__time_unbox(_x_x1962, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10299_fun1967__t {
  struct kk_function_s _base;
  kk_function_t next_10431;
};
static kk_box_t kk_std_time_parse__mlift_piso_10299_fun1967(kk_function_t _fself, kk_box_t _b_x941, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10299_fun1967(kk_function_t next_10431, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10299_fun1967__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10299_fun1967__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10299_fun1967, kk_context());
  _self->next_10431 = next_10431;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10299_fun1967(kk_function_t _fself, kk_box_t _b_x941, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10299_fun1967__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10299_fun1967__t*, _fself, _ctx);
  kk_function_t next_10431 = _self->next_10431; /* (std/time/time/time) -> <std/time/utc/utc,std/text/parse/parse> std/time/time/time */
  kk_drop_match(_self, {kk_function_dup(next_10431, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x1968;
  kk_std_time_time__time _x_x1969 = kk_std_time_time__time_unbox(_b_x941, KK_OWNED, _ctx); /*std/time/time/time*/
  _x_x1968 = kk_function_call(kk_std_time_time__time, (kk_function_t, kk_std_time_time__time, kk_context_t*), next_10431, (next_10431, _x_x1969, _ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1968, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_piso_10299(kk_std_core_types__tuple2 _y_x10131, kk_context_t* _ctx) { /* ((std/time/date/date, std/time/calendar/calendar)) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  {
    kk_box_t _box_x928 = _y_x10131.fst;
    kk_box_t _box_x929 = _y_x10131.snd;
    kk_std_time_date__date date = kk_std_time_date__date_unbox(_box_x928, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar cal = kk_std_time_calendar__calendar_unbox(_box_x929, KK_BORROWED, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1955 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_std_time_calendar__calendar_dup(cal, _ctx);
    kk_std_time_date__date_dup(date, _ctx);
    kk_std_core_types__tuple2_drop(_y_x10131, _ctx);
    kk_ssize_t _b_x931_933 = (KK_IZ(1)); /*hnd/ev-index*/;
    kk_std_time_time__time x_10430;
    kk_box_t _x_x1956;
    kk_function_t _x_x1957;
    kk_std_time_calendar__calendar_dup(cal, _ctx);
    kk_std_time_date__date_dup(date, _ctx);
    _x_x1957 = kk_std_time_parse__new_mlift_piso_10299_fun1958(cal, date, _ctx); /*() -> 10427 10426*/
    _x_x1956 = kk_std_core_hnd__open_at0(_b_x931_933, _x_x1957, _ctx); /*10426*/
    x_10430 = kk_std_time_time__time_unbox(_x_x1956, KK_OWNED, _ctx); /*std/time/time/time*/
    kk_function_t next_10431 = kk_std_time_parse__new_mlift_piso_10299_fun1961(cal, date, _ctx); /*(std/time/time/time) -> <std/time/utc/utc,std/text/parse/parse> std/time/time/time*/;
    if (kk_yielding(kk_context())) {
      kk_datatype_ptr_dropn(x_10430, (KK_I32(9)), _ctx);
      kk_box_t _x_x1966 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10299_fun1967(next_10431, _ctx), _ctx); /*2419*/
      return kk_std_time_time__time_unbox(_x_x1966, KK_OWNED, _ctx);
    }
    {
      return kk_function_call(kk_std_time_time__time, (kk_function_t, kk_std_time_time__time, kk_context_t*), next_10431, (next_10431, x_10430, _ctx), _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun1974__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1974(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun1974(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun1974__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10300_fun1974__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10300_fun1974, kk_context());
  _self->calendar = calendar;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun1976__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1976(kk_function_t _fself, kk_box_t _b_x957, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun1976(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun1976, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun1978__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1978(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun1978(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun1978, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1978(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1979 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x1979, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun1980__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1980(kk_function_t _fself, kk_box_t _b_x948, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun1980(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun1980, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1980(kk_function_t _fself, kk_box_t _b_x948, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1981;
  kk_std_core_types__list _x_x1982 = kk_std_core_types__list_unbox(_b_x948, KK_OWNED, _ctx); /*list<int>*/
  _x_x1981 = kk_std_time_parse__mlift_piso_10280(_x_x1982, _ctx); /*int*/
  return kk_integer_box(_x_x1981, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun1983__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1983(kk_function_t _fself, kk_box_t _b_x952, kk_box_t _b_x953, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun1983(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun1983, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1983(kk_function_t _fself, kk_box_t _b_x952, kk_box_t _b_x953, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_2_10177;
  kk_integer_t _x_x1984 = kk_integer_unbox(_b_x952, _ctx); /*int*/
  x_2_10177 = kk_integer_mul(_x_x1984,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x1985;
  kk_integer_t _x_x1986 = kk_integer_unbox(_b_x953, _ctx); /*int*/
  _x_x1985 = kk_integer_add(x_2_10177,_x_x1986,kk_context()); /*int*/
  return kk_integer_box(_x_x1985, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1976(kk_function_t _fself, kk_box_t _b_x957, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_1_10439;
  kk_integer_t _x_x1977 = kk_integer_unbox(_b_x957, _ctx); /*int*/
  x_1_10439 = kk_std_text_parse_count(_x_x1977, kk_std_time_parse__new_mlift_piso_10300_fun1978(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_10439, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10300_fun1980(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_1_10439, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10300_fun1983(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun1989__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1989(kk_function_t _fself, kk_box_t _b_x969, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun1989(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun1989__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10300_fun1989__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10300_fun1989, kk_context());
  _self->calendar = calendar;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1989(kk_function_t _fself, kk_box_t _b_x969, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun1989__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10300_fun1989__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x1990;
  kk_integer_t _x_x1991 = kk_integer_unbox(_b_x969, _ctx); /*int*/
  _x_x1990 = kk_std_time_parse__mlift_piso_10281(calendar, year, _x_x1991, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x1990, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1974(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun1974__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10300_fun1974__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x954_958 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_0_10437;
  kk_box_t _x_x1975 = kk_std_core_hnd__open_at1(_b_x954_958, kk_std_time_parse__new_mlift_piso_10300_fun1976(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
  x_0_10437 = kk_integer_unbox(_x_x1975, _ctx); /*int*/
  kk_std_core_types__tuple2 _x_x1987;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_0_10437, _ctx);
    kk_box_t _x_x1988 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10300_fun1989(calendar, year, _ctx), _ctx); /*2419*/
    _x_x1987 = kk_std_core_types__tuple2_unbox(_x_x1988, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x1987 = kk_std_time_parse__mlift_piso_10281(calendar, year, x_0_10437, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x1987, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun1995__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1995(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun1995(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun1995__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10300_fun1995__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10300_fun1995, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun1997__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1997(kk_function_t _fself, kk_box_t _b_x973, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun1997(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun1997, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1997(kk_function_t _fself, kk_box_t _b_x973, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1998;
  kk_char_t _x_x1999 = kk_char_unbox(_b_x973, KK_OWNED, _ctx); /*char*/
  _x_x1998 = kk_std_text_parse_char(_x_x1999, _ctx); /*char*/
  return kk_char_box(_x_x1998, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2002__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2002(kk_function_t _fself, kk_box_t _b_x978, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2002(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2002__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10300_fun2002__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10300_fun2002, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2002(kk_function_t _fself, kk_box_t _b_x978, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2002__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10300_fun2002__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2003;
  kk_char_t _x_x2004 = kk_char_unbox(_b_x978, KK_OWNED, _ctx); /*char*/
  _x_x2003 = kk_std_time_parse__mlift_piso_10287(year, _x_x2004, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2003, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun1995(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun1995__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10300_fun1995__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x970_974 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_2_10441;
  kk_box_t _x_x1996 = kk_std_core_hnd__open_at1(_b_x970_974, kk_std_time_parse__new_mlift_piso_10300_fun1997(_ctx), kk_char_box('W', _ctx), _ctx); /*10540*/
  x_2_10441 = kk_char_unbox(_x_x1996, KK_OWNED, _ctx); /*char*/
  kk_std_core_types__tuple2 _x_x2000;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2001 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10300_fun2002(year, _ctx), _ctx); /*2419*/
    _x_x2000 = kk_std_core_types__tuple2_unbox(_x_x2001, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2000 = kk_std_time_parse__mlift_piso_10287(year, x_2_10441, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2000, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2008__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2008(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2008(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2008__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10300_fun2008__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10300_fun2008, kk_context());
  _self->calendar = calendar;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2010__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2010(kk_function_t _fself, kk_box_t _b_x993, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2010(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun2010, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2012__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2012(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2012(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun2012, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2012(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2013 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x2013, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2014__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2014(kk_function_t _fself, kk_box_t _b_x984, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2014(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun2014, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2014(kk_function_t _fself, kk_box_t _b_x984, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2015;
  kk_std_core_types__list _x_x2016 = kk_std_core_types__list_unbox(_b_x984, KK_OWNED, _ctx); /*list<int>*/
  _x_x2015 = kk_std_time_parse__mlift_piso_10288(_x_x2016, _ctx); /*int*/
  return kk_integer_box(_x_x2015, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2017__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2017(kk_function_t _fself, kk_box_t _b_x988, kk_box_t _b_x989, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2017(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun2017, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2017(kk_function_t _fself, kk_box_t _b_x988, kk_box_t _b_x989, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_10_10192;
  kk_integer_t _x_x2018 = kk_integer_unbox(_b_x988, _ctx); /*int*/
  x_10_10192 = kk_integer_mul(_x_x2018,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x2019;
  kk_integer_t _x_x2020 = kk_integer_unbox(_b_x989, _ctx); /*int*/
  _x_x2019 = kk_integer_add(x_10_10192,_x_x2020,kk_context()); /*int*/
  return kk_integer_box(_x_x2019, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2010(kk_function_t _fself, kk_box_t _b_x993, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_4_10445;
  kk_integer_t _x_x2011 = kk_integer_unbox(_b_x993, _ctx); /*int*/
  x_4_10445 = kk_std_text_parse_count(_x_x2011, kk_std_time_parse__new_mlift_piso_10300_fun2012(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_4_10445, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10300_fun2014(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_4_10445, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10300_fun2017(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2021__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t year;
};
static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10300_fun2021(kk_function_t _fself, kk_integer_t d_1_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2021(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2021__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10300_fun2021__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10300_fun2021, kk_context());
  _self->calendar = calendar;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10300_fun2021(kk_function_t _fself, kk_integer_t d_1_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2021__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10300_fun2021__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_box_t _x_x2022;
  kk_std_time_date__date _x_x2023 = kk_std_time_date__new_Date(year, kk_integer_from_small(1), d_1_0, _ctx); /*std/time/date/date*/
  _x_x2022 = kk_std_time_date__date_box(_x_x2023, _ctx); /*134*/
  return kk_std_core_types__new_Tuple2(_x_x2022, kk_std_time_calendar__calendar_box(calendar, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2026__t {
  struct kk_function_s _base;
  kk_function_t next_3_10444;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2026(kk_function_t _fself, kk_box_t _b_x1009, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2026(kk_function_t next_3_10444, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2026__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10300_fun2026__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10300_fun2026, kk_context());
  _self->next_3_10444 = next_3_10444;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2026(kk_function_t _fself, kk_box_t _b_x1009, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2026__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10300_fun2026__t*, _fself, _ctx);
  kk_function_t next_3_10444 = _self->next_3_10444; /* (int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_3_10444, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2027;
  kk_integer_t _x_x2028 = kk_integer_unbox(_b_x1009, _ctx); /*int*/
  _x_x2027 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_3_10444, (next_3_10444, _x_x2028, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2027, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2008(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2008__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10300_fun2008__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x990_994 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_3_10443;
  kk_box_t _x_x2009 = kk_std_core_hnd__open_at1(_b_x990_994, kk_std_time_parse__new_mlift_piso_10300_fun2010(_ctx), kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*10540*/
  x_3_10443 = kk_integer_unbox(_x_x2009, _ctx); /*int*/
  kk_function_t next_3_10444 = kk_std_time_parse__new_mlift_piso_10300_fun2021(calendar, year, _ctx); /*(int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar)*/;
  kk_std_core_types__tuple2 _x_x2024;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_3_10443, _ctx);
    kk_box_t _x_x2025 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10300_fun2026(next_3_10444, _ctx), _ctx); /*2419*/
    _x_x2024 = kk_std_core_types__tuple2_unbox(_x_x2025, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2024 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_3_10444, (next_3_10444, x_3_10443, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2024, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2032__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2032(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2032(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2032__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10300_fun2032__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10300_fun2032, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2034__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2034(kk_function_t _fself, kk_box_t _b_x1013, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2034(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun2034, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2034(kk_function_t _fself, kk_box_t _b_x1013, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2035;
  kk_char_t _x_x2036 = kk_char_unbox(_b_x1013, KK_OWNED, _ctx); /*char*/
  _x_x2035 = kk_std_text_parse_char(_x_x2036, _ctx); /*char*/
  return kk_char_box(_x_x2035, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2039__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2039(kk_function_t _fself, kk_box_t _b_x1018, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2039(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2039__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10300_fun2039__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10300_fun2039, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2039(kk_function_t _fself, kk_box_t _b_x1018, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2039__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10300_fun2039__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2040;
  kk_char_t _x_x2041 = kk_char_unbox(_b_x1018, KK_OWNED, _ctx); /*char*/
  _x_x2040 = kk_std_time_parse__mlift_piso_10295(year, _x_x2041, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2040, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2032(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2032__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10300_fun2032__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x1010_1014 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_5_10450;
  kk_box_t _x_x2033 = kk_std_core_hnd__open_at1(_b_x1010_1014, kk_std_time_parse__new_mlift_piso_10300_fun2034(_ctx), kk_char_box('M', _ctx), _ctx); /*10540*/
  x_5_10450 = kk_char_unbox(_x_x2033, KK_OWNED, _ctx); /*char*/
  kk_std_core_types__tuple2 _x_x2037;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2038 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10300_fun2039(year, _ctx), _ctx); /*2419*/
    _x_x2037 = kk_std_core_types__tuple2_unbox(_x_x2038, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2037 = kk_std_time_parse__mlift_piso_10295(year, x_5_10450, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2037, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2043__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2043(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2043(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2043__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10300_fun2043__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10300_fun2043, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2045__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2045(kk_function_t _fself, kk_box_t _b_x1022, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2045(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun2045, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2045(kk_function_t _fself, kk_box_t _b_x1022, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2046;
  kk_char_t _x_x2047 = kk_char_unbox(_b_x1022, KK_OWNED, _ctx); /*char*/
  _x_x2046 = kk_std_text_parse_char(_x_x2047, _ctx); /*char*/
  return kk_char_box(_x_x2046, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2050__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2050(kk_function_t _fself, kk_box_t _b_x1027, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2050(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2050__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10300_fun2050__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10300_fun2050, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2050(kk_function_t _fself, kk_box_t _b_x1027, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2050__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10300_fun2050__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2051;
  kk_char_t _x_x2052 = kk_char_unbox(_b_x1027, KK_OWNED, _ctx); /*char*/
  _x_x2051 = kk_std_time_parse__mlift_piso_10298(year, _x_x2052, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2051, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2043(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10300_fun2043__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10300_fun2043__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x1019_1023 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_6_10452;
  kk_box_t _x_x2044 = kk_std_core_hnd__open_at1(_b_x1019_1023, kk_std_time_parse__new_mlift_piso_10300_fun2045(_ctx), kk_char_box('M', _ctx), _ctx); /*10540*/
  x_6_10452 = kk_char_unbox(_x_x2044, KK_OWNED, _ctx); /*char*/
  kk_std_core_types__tuple2 _x_x2048;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2049 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10300_fun2050(year, _ctx), _ctx); /*2419*/
    _x_x2048 = kk_std_core_types__tuple2_unbox(_x_x2049, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2048 = kk_std_time_parse__mlift_piso_10298(year, x_6_10452, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2048, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10300_fun2054__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2054(kk_function_t _fself, kk_box_t _b_x1065, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10300_fun2054(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10300_fun2054, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10300_fun2054(kk_function_t _fself, kk_box_t _b_x1065, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_time__time _x_x2055;
  kk_std_core_types__tuple2 _x_x2056 = kk_std_core_types__tuple2_unbox(_b_x1065, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  _x_x2055 = kk_std_time_parse__mlift_piso_10299(_x_x2056, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2055, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_piso_10300(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_char_t wild__, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, year : int, wild_ : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_std_core_types__tuple2 x_10435;
  kk_box_t _x_x1970;
  kk_std_core_types__list _x_x1971;
  kk_box_t _x_x1972;
  kk_function_t _x_x1973;
  kk_std_time_calendar__calendar_dup(calendar, _ctx);
  kk_integer_dup(year, _ctx);
  _x_x1973 = kk_std_time_parse__new_mlift_piso_10300_fun1974(calendar, year, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1042*/
  _x_x1972 = kk_function_box(_x_x1973, _ctx); /*79*/
  kk_std_core_types__list _x_x1992;
  kk_box_t _x_x1993;
  kk_function_t _x_x1994;
  kk_integer_dup(year, _ctx);
  _x_x1994 = kk_std_time_parse__new_mlift_piso_10300_fun1995(year, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1039*/
  _x_x1993 = kk_function_box(_x_x1994, _ctx); /*79*/
  kk_std_core_types__list _x_x2005;
  kk_box_t _x_x2006;
  kk_function_t _x_x2007;
  kk_integer_dup(year, _ctx);
  _x_x2007 = kk_std_time_parse__new_mlift_piso_10300_fun2008(calendar, year, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1036*/
  _x_x2006 = kk_function_box(_x_x2007, _ctx); /*79*/
  kk_std_core_types__list _x_x2029;
  kk_box_t _x_x2030;
  kk_function_t _x_x2031;
  kk_integer_dup(year, _ctx);
  _x_x2031 = kk_std_time_parse__new_mlift_piso_10300_fun2032(year, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1033*/
  _x_x2030 = kk_function_box(_x_x2031, _ctx); /*79*/
  kk_std_core_types__list _x_x2042 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse__new_mlift_piso_10300_fun2043(year, _ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
  _x_x2029 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2030, _x_x2042, _ctx); /*list<79>*/
  _x_x2005 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2006, _x_x2029, _ctx); /*list<79>*/
  _x_x1992 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1993, _x_x2005, _ctx); /*list<79>*/
  _x_x1971 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1972, _x_x1992, _ctx); /*list<79>*/
  _x_x1970 = kk_std_text_parse_choose(_x_x1971, _ctx); /*1639*/
  x_10435 = kk_std_core_types__tuple2_unbox(_x_x1970, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2_drop(x_10435, _ctx);
    kk_box_t _x_x2053 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10300_fun2054(_ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x2053, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_10299(x_10435, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10301_fun2058__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10301_fun2058(kk_function_t _fself, kk_box_t _b_x1070, kk_box_t _b_x1071, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10301_fun2058(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10301_fun2058, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10301_fun2058(kk_function_t _fself, kk_box_t _b_x1070, kk_box_t _b_x1071, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_1075 = kk_integer_unbox(_b_x1070, _ctx); /*int*/;
  kk_integer_t d_1076 = kk_integer_unbox(_b_x1071, _ctx); /*int*/;
  kk_integer_t x_0_10173 = kk_integer_mul(x_1075,(kk_integer_from_small(10)),kk_context()); /*int*/;
  kk_integer_t _x_x2059 = kk_integer_add(x_0_10173,d_1076,kk_context()); /*int*/
  return kk_integer_box(_x_x2059, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_piso_10301(kk_std_core_types__list _y_x10088, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  kk_box_t _x_x2057 = kk_std_core_list_foldl(_y_x10088, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse__new_mlift_piso_10301_fun2058(_ctx), _ctx); /*1192*/
  return kk_integer_unbox(_x_x2057, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10302_fun2061__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10302_fun2061(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10302_fun2061(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10302_fun2061, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10302_fun2062__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10302_fun2062(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10302_fun2062(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10302_fun2062, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10302_fun2062(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2063 = kk_std_text_parse_char('-', _ctx); /*char*/
  return kk_char_box(_x_x2063, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10302_fun2064__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_10302_fun2064(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10302_fun2064(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_10302_fun2064, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10302_fun2064(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box('-', _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_10302_fun2061(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_piso_10302_fun2062(_ctx), kk_std_time_parse__new_mlift_piso_10302_fun2064(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10302_fun2066__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_10302_fun2066(kk_function_t _fself, kk_box_t _b_x1086, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_10302_fun2066(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10302_fun2066__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10302_fun2066__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10302_fun2066, kk_context());
  _self->calendar = calendar;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_10302_fun2066(kk_function_t _fself, kk_box_t _b_x1086, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10302_fun2066__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_10302_fun2066__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_char_t wild___1088 = kk_char_unbox(_b_x1086, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x2067 = kk_std_time_parse__mlift_piso_10300(calendar, year, wild___1088, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2067, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_piso_10302(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, year : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t _b_x1079_1081 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_10454;
  kk_box_t _x_x2060 = kk_std_core_hnd__open_at0(_b_x1079_1081, kk_std_time_parse__new_mlift_piso_10302_fun2061(_ctx), _ctx); /*10426*/
  x_10454 = kk_char_unbox(_x_x2060, KK_OWNED, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2065 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_10302_fun2066(calendar, year, _ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x2065, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_10300(calendar, year, x_10454, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2069__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2069(kk_function_t _fself, kk_box_t _b_x1103, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2069(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2069, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2071__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2071(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2071(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2071, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2071(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2072 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x2072, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2073__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2073(kk_function_t _fself, kk_box_t _b_x1094, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2073(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2073, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2073(kk_function_t _fself, kk_box_t _b_x1094, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2074;
  kk_std_core_types__list _x_x2075 = kk_std_core_types__list_unbox(_b_x1094, KK_OWNED, _ctx); /*list<int>*/
  _x_x2074 = kk_std_time_parse__mlift_piso_10301(_x_x2075, _ctx); /*int*/
  return kk_integer_box(_x_x2074, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2076__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2076(kk_function_t _fself, kk_box_t _b_x1098, kk_box_t _b_x1099, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2076(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2076, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2076(kk_function_t _fself, kk_box_t _b_x1098, kk_box_t _b_x1099, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_0_10173;
  kk_integer_t _x_x2077 = kk_integer_unbox(_b_x1098, _ctx); /*int*/
  x_0_10173 = kk_integer_mul(_x_x2077,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x2078;
  kk_integer_t _x_x2079 = kk_integer_unbox(_b_x1099, _ctx); /*int*/
  _x_x2078 = kk_integer_add(x_0_10173,_x_x2079,kk_context()); /*int*/
  return kk_integer_box(_x_x2078, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2069(kk_function_t _fself, kk_box_t _b_x1103, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_0_10459;
  kk_integer_t _x_x2070 = kk_integer_unbox(_b_x1103, _ctx); /*int*/
  x_0_10459 = kk_std_text_parse_count(_x_x2070, kk_std_time_parse_new_piso_fun2071(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10459, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2073(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_0_10459, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse_new_piso_fun2076(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2081__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
};
static kk_box_t kk_std_time_parse_piso_fun2081(kk_function_t _fself, kk_box_t _b_x1115, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2081(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2081__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2081__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2081, kk_context());
  _self->calendar = calendar;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2081(kk_function_t _fself, kk_box_t _b_x1115, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2081__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2081__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);}, {}, _ctx)
  kk_integer_t year_1271 = kk_integer_unbox(_b_x1115, _ctx); /*int*/;
  kk_std_time_time__time _x_x2082 = kk_std_time_parse__mlift_piso_10302(calendar, year_1271, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2082, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2084__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2084(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2084(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2084, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2085__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2085(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2085(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2085, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2085(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2086 = kk_std_text_parse_char('-', _ctx); /*char*/
  return kk_char_box(_x_x2086, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2087__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2087(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2087(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2087, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2087(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_char_box('-', _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2084(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse_new_piso_fun2085(_ctx), kk_std_time_parse_new_piso_fun2087(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2089__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t x_10456;
};
static kk_box_t kk_std_time_parse_piso_fun2089(kk_function_t _fself, kk_box_t _b_x1125, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2089(kk_std_time_calendar__calendar calendar, kk_integer_t x_10456, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2089__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2089__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2089, kk_context());
  _self->calendar = calendar;
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2089(kk_function_t _fself, kk_box_t _b_x1125, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2089__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2089__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t x_10456 = _self->x_10456; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(x_10456, _ctx);}, {}, _ctx)
  kk_char_t wild___1272 = kk_char_unbox(_b_x1125, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x2090 = kk_std_time_parse__mlift_piso_10300(calendar, x_10456, wild___1272, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2090, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2095__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t x_10456;
};
static kk_box_t kk_std_time_parse_piso_fun2095(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2095(kk_std_time_calendar__calendar calendar, kk_integer_t x_10456, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2095__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2095__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2095, kk_context());
  _self->calendar = calendar;
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2097__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2097(kk_function_t _fself, kk_box_t _b_x1140, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2097(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2097, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2099__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2099(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2099(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2099, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2099(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2100 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x2100, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2101__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2101(kk_function_t _fself, kk_box_t _b_x1131, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2101(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2101, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2101(kk_function_t _fself, kk_box_t _b_x1131, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2102;
  kk_std_core_types__list _x_x2103 = kk_std_core_types__list_unbox(_b_x1131, KK_OWNED, _ctx); /*list<int>*/
  _x_x2102 = kk_std_time_parse__mlift_piso_10280(_x_x2103, _ctx); /*int*/
  return kk_integer_box(_x_x2102, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2104__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2104(kk_function_t _fself, kk_box_t _b_x1135, kk_box_t _b_x1136, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2104(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2104, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2104(kk_function_t _fself, kk_box_t _b_x1135, kk_box_t _b_x1136, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_2_10177;
  kk_integer_t _x_x2105 = kk_integer_unbox(_b_x1135, _ctx); /*int*/
  x_2_10177 = kk_integer_mul(_x_x2105,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x2106;
  kk_integer_t _x_x2107 = kk_integer_unbox(_b_x1136, _ctx); /*int*/
  _x_x2106 = kk_integer_add(x_2_10177,_x_x2107,kk_context()); /*int*/
  return kk_integer_box(_x_x2106, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2097(kk_function_t _fself, kk_box_t _b_x1140, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_4_10469;
  kk_integer_t _x_x2098 = kk_integer_unbox(_b_x1140, _ctx); /*int*/
  x_4_10469 = kk_std_text_parse_count(_x_x2098, kk_std_time_parse_new_piso_fun2099(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_4_10469, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2101(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_4_10469, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse_new_piso_fun2104(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2110__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t x_10456;
};
static kk_box_t kk_std_time_parse_piso_fun2110(kk_function_t _fself, kk_box_t _b_x1152, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2110(kk_std_time_calendar__calendar calendar, kk_integer_t x_10456, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2110__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2110__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2110, kk_context());
  _self->calendar = calendar;
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2110(kk_function_t _fself, kk_box_t _b_x1152, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2110__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2110__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t x_10456 = _self->x_10456; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(x_10456, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2111;
  kk_integer_t _x_x2112 = kk_integer_unbox(_b_x1152, _ctx); /*int*/
  _x_x2111 = kk_std_time_parse__mlift_piso_10281(calendar, x_10456, _x_x2112, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2111, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2095(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2095__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2095__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t x_10456 = _self->x_10456; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(x_10456, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x1137_1141 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_3_10467;
  kk_box_t _x_x2096 = kk_std_core_hnd__open_at1(_b_x1137_1141, kk_std_time_parse_new_piso_fun2097(_ctx), kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*10540*/
  x_3_10467 = kk_integer_unbox(_x_x2096, _ctx); /*int*/
  kk_std_core_types__tuple2 _x_x2108;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_3_10467, _ctx);
    kk_box_t _x_x2109 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2110(calendar, x_10456, _ctx), _ctx); /*2419*/
    _x_x2108 = kk_std_core_types__tuple2_unbox(_x_x2109, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2108 = kk_std_time_parse__mlift_piso_10281(calendar, x_10456, x_3_10467, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2108, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2116__t {
  struct kk_function_s _base;
  kk_integer_t x_10456;
};
static kk_box_t kk_std_time_parse_piso_fun2116(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2116(kk_integer_t x_10456, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2116__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2116__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2116, kk_context());
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2118__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2118(kk_function_t _fself, kk_box_t _b_x1156, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2118(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2118, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2118(kk_function_t _fself, kk_box_t _b_x1156, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2119;
  kk_char_t _x_x2120 = kk_char_unbox(_b_x1156, KK_OWNED, _ctx); /*char*/
  _x_x2119 = kk_std_text_parse_char(_x_x2120, _ctx); /*char*/
  return kk_char_box(_x_x2119, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2123__t {
  struct kk_function_s _base;
  kk_integer_t x_10456;
};
static kk_box_t kk_std_time_parse_piso_fun2123(kk_function_t _fself, kk_box_t _b_x1161, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2123(kk_integer_t x_10456, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2123__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2123__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2123, kk_context());
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2123(kk_function_t _fself, kk_box_t _b_x1161, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2123__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2123__t*, _fself, _ctx);
  kk_integer_t x_10456 = _self->x_10456; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_10456, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2124;
  kk_char_t _x_x2125 = kk_char_unbox(_b_x1161, KK_OWNED, _ctx); /*char*/
  _x_x2124 = kk_std_time_parse__mlift_piso_10287(x_10456, _x_x2125, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2124, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2116(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2116__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2116__t*, _fself, _ctx);
  kk_integer_t x_10456 = _self->x_10456; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_10456, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x1153_1157 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_5_10471;
  kk_box_t _x_x2117 = kk_std_core_hnd__open_at1(_b_x1153_1157, kk_std_time_parse_new_piso_fun2118(_ctx), kk_char_box('W', _ctx), _ctx); /*10540*/
  x_5_10471 = kk_char_unbox(_x_x2117, KK_OWNED, _ctx); /*char*/
  kk_std_core_types__tuple2 _x_x2121;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2122 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2123(x_10456, _ctx), _ctx); /*2419*/
    _x_x2121 = kk_std_core_types__tuple2_unbox(_x_x2122, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2121 = kk_std_time_parse__mlift_piso_10287(x_10456, x_5_10471, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2121, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2129__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t x_10456;
};
static kk_box_t kk_std_time_parse_piso_fun2129(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2129(kk_std_time_calendar__calendar calendar, kk_integer_t x_10456, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2129__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2129__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2129, kk_context());
  _self->calendar = calendar;
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2131__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2131(kk_function_t _fself, kk_box_t _b_x1176, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2131(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2131, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2133__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2133(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2133(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2133, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2133(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2134 = kk_std_text_parse_digit(_ctx); /*int*/
  return kk_integer_box(_x_x2134, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2135__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2135(kk_function_t _fself, kk_box_t _b_x1167, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2135(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2135, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2135(kk_function_t _fself, kk_box_t _b_x1167, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2136;
  kk_std_core_types__list _x_x2137 = kk_std_core_types__list_unbox(_b_x1167, KK_OWNED, _ctx); /*list<int>*/
  _x_x2136 = kk_std_time_parse__mlift_piso_10288(_x_x2137, _ctx); /*int*/
  return kk_integer_box(_x_x2136, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2138__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2138(kk_function_t _fself, kk_box_t _b_x1171, kk_box_t _b_x1172, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2138(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2138, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2138(kk_function_t _fself, kk_box_t _b_x1171, kk_box_t _b_x1172, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t x_10_10192;
  kk_integer_t _x_x2139 = kk_integer_unbox(_b_x1171, _ctx); /*int*/
  x_10_10192 = kk_integer_mul(_x_x2139,(kk_integer_from_small(10)),kk_context()); /*int*/
  kk_integer_t _x_x2140;
  kk_integer_t _x_x2141 = kk_integer_unbox(_b_x1172, _ctx); /*int*/
  _x_x2140 = kk_integer_add(x_10_10192,_x_x2141,kk_context()); /*int*/
  return kk_integer_box(_x_x2140, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2131(kk_function_t _fself, kk_box_t _b_x1176, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_7_10475;
  kk_integer_t _x_x2132 = kk_integer_unbox(_b_x1176, _ctx); /*int*/
  x_7_10475 = kk_std_text_parse_count(_x_x2132, kk_std_time_parse_new_piso_fun2133(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_7_10475, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2135(_ctx), _ctx);
  }
  {
    return kk_std_core_list_foldl(x_7_10475, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_time_parse_new_piso_fun2138(_ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2142__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t x_10456;
};
static kk_std_core_types__tuple2 kk_std_time_parse_piso_fun2142(kk_function_t _fself, kk_integer_t d_1_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2142(kk_std_time_calendar__calendar calendar, kk_integer_t x_10456, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2142__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2142__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2142, kk_context());
  _self->calendar = calendar;
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse_piso_fun2142(kk_function_t _fself, kk_integer_t d_1_0, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2142__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2142__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t x_10456 = _self->x_10456; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(x_10456, _ctx);}, {}, _ctx)
  kk_box_t _x_x2143;
  kk_std_time_date__date _x_x2144 = kk_std_time_date__new_Date(x_10456, kk_integer_from_small(1), d_1_0, _ctx); /*std/time/date/date*/
  _x_x2143 = kk_std_time_date__date_box(_x_x2144, _ctx); /*134*/
  return kk_std_core_types__new_Tuple2(_x_x2143, kk_std_time_calendar__calendar_box(calendar, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2147__t {
  struct kk_function_s _base;
  kk_function_t next_6_10474;
};
static kk_box_t kk_std_time_parse_piso_fun2147(kk_function_t _fself, kk_box_t _b_x1192, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2147(kk_function_t next_6_10474, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2147__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2147__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2147, kk_context());
  _self->next_6_10474 = next_6_10474;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2147(kk_function_t _fself, kk_box_t _b_x1192, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2147__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2147__t*, _fself, _ctx);
  kk_function_t next_6_10474 = _self->next_6_10474; /* (int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_6_10474, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2148;
  kk_integer_t _x_x2149 = kk_integer_unbox(_b_x1192, _ctx); /*int*/
  _x_x2148 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_6_10474, (next_6_10474, _x_x2149, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2148, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2129(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2129__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2129__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t x_10456 = _self->x_10456; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(x_10456, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x1173_1177 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_6_10473;
  kk_box_t _x_x2130 = kk_std_core_hnd__open_at1(_b_x1173_1177, kk_std_time_parse_new_piso_fun2131(_ctx), kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*10540*/
  x_6_10473 = kk_integer_unbox(_x_x2130, _ctx); /*int*/
  kk_function_t next_6_10474 = kk_std_time_parse_new_piso_fun2142(calendar, x_10456, _ctx); /*(int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar)*/;
  kk_std_core_types__tuple2 _x_x2145;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_6_10473, _ctx);
    kk_box_t _x_x2146 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2147(next_6_10474, _ctx), _ctx); /*2419*/
    _x_x2145 = kk_std_core_types__tuple2_unbox(_x_x2146, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2145 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_6_10474, (next_6_10474, x_6_10473, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2145, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2153__t {
  struct kk_function_s _base;
  kk_integer_t x_10456;
};
static kk_box_t kk_std_time_parse_piso_fun2153(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2153(kk_integer_t x_10456, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2153__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2153__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2153, kk_context());
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2155__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2155(kk_function_t _fself, kk_box_t _b_x1196, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2155(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2155, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2155(kk_function_t _fself, kk_box_t _b_x1196, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2156;
  kk_char_t _x_x2157 = kk_char_unbox(_b_x1196, KK_OWNED, _ctx); /*char*/
  _x_x2156 = kk_std_text_parse_char(_x_x2157, _ctx); /*char*/
  return kk_char_box(_x_x2156, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2160__t {
  struct kk_function_s _base;
  kk_integer_t x_10456;
};
static kk_box_t kk_std_time_parse_piso_fun2160(kk_function_t _fself, kk_box_t _b_x1201, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2160(kk_integer_t x_10456, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2160__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2160__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2160, kk_context());
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2160(kk_function_t _fself, kk_box_t _b_x1201, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2160__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2160__t*, _fself, _ctx);
  kk_integer_t x_10456 = _self->x_10456; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_10456, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2161;
  kk_char_t _x_x2162 = kk_char_unbox(_b_x1201, KK_OWNED, _ctx); /*char*/
  _x_x2161 = kk_std_time_parse__mlift_piso_10295(x_10456, _x_x2162, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2161, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2153(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2153__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2153__t*, _fself, _ctx);
  kk_integer_t x_10456 = _self->x_10456; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_10456, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x1193_1197 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_8_10480;
  kk_box_t _x_x2154 = kk_std_core_hnd__open_at1(_b_x1193_1197, kk_std_time_parse_new_piso_fun2155(_ctx), kk_char_box('M', _ctx), _ctx); /*10540*/
  x_8_10480 = kk_char_unbox(_x_x2154, KK_OWNED, _ctx); /*char*/
  kk_std_core_types__tuple2 _x_x2158;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2159 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2160(x_10456, _ctx), _ctx); /*2419*/
    _x_x2158 = kk_std_core_types__tuple2_unbox(_x_x2159, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2158 = kk_std_time_parse__mlift_piso_10295(x_10456, x_8_10480, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2158, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2164__t {
  struct kk_function_s _base;
  kk_integer_t x_10456;
};
static kk_box_t kk_std_time_parse_piso_fun2164(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2164(kk_integer_t x_10456, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2164__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2164__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2164, kk_context());
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2166__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2166(kk_function_t _fself, kk_box_t _b_x1205, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2166(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2166, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2166(kk_function_t _fself, kk_box_t _b_x1205, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2167;
  kk_char_t _x_x2168 = kk_char_unbox(_b_x1205, KK_OWNED, _ctx); /*char*/
  _x_x2167 = kk_std_text_parse_char(_x_x2168, _ctx); /*char*/
  return kk_char_box(_x_x2167, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2171__t {
  struct kk_function_s _base;
  kk_integer_t x_10456;
};
static kk_box_t kk_std_time_parse_piso_fun2171(kk_function_t _fself, kk_box_t _b_x1210, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2171(kk_integer_t x_10456, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2171__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2171__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2171, kk_context());
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2171(kk_function_t _fself, kk_box_t _b_x1210, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2171__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2171__t*, _fself, _ctx);
  kk_integer_t x_10456 = _self->x_10456; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_10456, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2172;
  kk_char_t _x_x2173 = kk_char_unbox(_b_x1210, KK_OWNED, _ctx); /*char*/
  _x_x2172 = kk_std_time_parse__mlift_piso_10298(x_10456, _x_x2173, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2172, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2164(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2164__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2164__t*, _fself, _ctx);
  kk_integer_t x_10456 = _self->x_10456; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_10456, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x1202_1206 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_char_t x_9_10482;
  kk_box_t _x_x2165 = kk_std_core_hnd__open_at1(_b_x1202_1206, kk_std_time_parse_new_piso_fun2166(_ctx), kk_char_box('M', _ctx), _ctx); /*10540*/
  x_9_10482 = kk_char_unbox(_x_x2165, KK_OWNED, _ctx); /*char*/
  kk_std_core_types__tuple2 _x_x2169;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2170 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2171(x_10456, _ctx), _ctx); /*2419*/
    _x_x2169 = kk_std_core_types__tuple2_unbox(_x_x2170, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2169 = kk_std_time_parse__mlift_piso_10298(x_10456, x_9_10482, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2169, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2175__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2175(kk_function_t _fself, kk_box_t _b_x1248, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2175(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2175, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2175(kk_function_t _fself, kk_box_t _b_x1248, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_time__time _x_x2176;
  kk_std_core_types__tuple2 _x_x2177 = kk_std_core_types__tuple2_unbox(_b_x1248, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  _x_x2176 = kk_std_time_parse__mlift_piso_10299(_x_x2177, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2176, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2181__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse_piso_fun2181(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2181(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2181__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2181__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2181, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2181(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2181__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2181__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2182;
  kk_std_core_types__optional _x_x2183 = kk_std_core_types__new_Optional(kk_std_time_calendar__calendar_box(cal, _ctx), _ctx); /*? 7*/
  _x_x2182 = kk_std_time_time_date_fs_time(date, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _x_x2183, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2182, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2185__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse_piso_fun2185(kk_function_t _fself, kk_box_t _b_x1260, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2185(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2185__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2185__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2185, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2186__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_std_time_time__time kk_std_time_parse_piso_fun2186(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2186(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2186__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2186__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2186, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_time__time kk_std_time_parse_piso_fun2186(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2186__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2186__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  return kk_std_time_parse_ptime(date, cal, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2187__t {
  struct kk_function_s _base;
  kk_std_time_time__time default_4_10039_1273;
};
static kk_std_time_time__time kk_std_time_parse_piso_fun2187(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2187(kk_std_time_time__time default_4_10039_1273, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2187__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2187__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2187, kk_context());
  _self->default_4_10039_1273 = default_4_10039_1273;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_time__time kk_std_time_parse_piso_fun2187(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2187__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2187__t*, _fself, _ctx);
  kk_std_time_time__time default_4_10039_1273 = _self->default_4_10039_1273; /* std/time/time/time */
  kk_drop_match(_self, {kk_std_time_time__time_dup(default_4_10039_1273, _ctx);}, {}, _ctx)
  return default_4_10039_1273;
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2188__t {
  struct kk_function_s _base;
  kk_function_t _b_x1257_1267;
};
static kk_box_t kk_std_time_parse_piso_fun2188(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2188(kk_function_t _b_x1257_1267, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2188__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2188__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2188, kk_context());
  _self->_b_x1257_1267 = _b_x1257_1267;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2188(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2188__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2188__t*, _fself, _ctx);
  kk_function_t _b_x1257_1267 = _self->_b_x1257_1267; /* () -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */
  kk_drop_match(_self, {kk_function_dup(_b_x1257_1267, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2189 = kk_function_call(kk_std_time_time__time, (kk_function_t, kk_context_t*), _b_x1257_1267, (_b_x1257_1267, _ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2189, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2190__t {
  struct kk_function_s _base;
  kk_function_t _b_x1258_1268;
};
static kk_box_t kk_std_time_parse_piso_fun2190(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2190(kk_function_t _b_x1258_1268, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2190__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2190__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2190, kk_context());
  _self->_b_x1258_1268 = _b_x1258_1268;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2190(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2190__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2190__t*, _fself, _ctx);
  kk_function_t _b_x1258_1268 = _self->_b_x1258_1268; /* () -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */
  kk_drop_match(_self, {kk_function_dup(_b_x1258_1268, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2191 = kk_function_call(kk_std_time_time__time, (kk_function_t, kk_context_t*), _b_x1258_1268, (_b_x1258_1268, _ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2191, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2185(kk_function_t _fself, kk_box_t _b_x1260, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2185__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2185__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_std_time_time__time default_4_10039_1273 = kk_std_time_time__time_unbox(_b_x1260, KK_OWNED, _ctx); /*std/time/time/time*/;
  kk_function_t _b_x1257_1267 = kk_std_time_parse_new_piso_fun2186(cal, date, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time*/;
  kk_function_t _b_x1258_1268 = kk_std_time_parse_new_piso_fun2187(default_4_10039_1273, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time*/;
  return kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse_new_piso_fun2188(_b_x1257_1267, _ctx), kk_std_time_parse_new_piso_fun2190(_b_x1258_1268, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2192__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse_piso_fun2192(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2192(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2192__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2192__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2192, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2192(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2192__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2192__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2193 = kk_std_time_parse_ptime(date, cal, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2193, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2194__t {
  struct kk_function_s _base;
  kk_std_time_time__time x_10_10484;
};
static kk_box_t kk_std_time_parse_piso_fun2194(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2194(kk_std_time_time__time x_10_10484, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2194__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2194__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2194, kk_context());
  _self->x_10_10484 = x_10_10484;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2194(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2194__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2194__t*, _fself, _ctx);
  kk_std_time_time__time x_10_10484 = _self->x_10_10484; /* std/time/time/time */
  kk_drop_match(_self, {kk_std_time_time__time_dup(x_10_10484, _ctx);}, {}, _ctx)
  return kk_std_time_time__time_box(x_10_10484, _ctx);
}

kk_std_time_time__time kk_std_time_parse_piso(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t _b_x1100_1104 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_10456;
  kk_box_t _x_x2068 = kk_std_core_hnd__open_at1(_b_x1100_1104, kk_std_time_parse_new_piso_fun2069(_ctx), kk_integer_box(kk_integer_from_small(4), _ctx), _ctx); /*10540*/
  x_10456 = kk_integer_unbox(_x_x2068, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10456, _ctx);
    kk_box_t _x_x2080 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2081(calendar, _ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x2080, KK_OWNED, _ctx);
  }
  {
    kk_ssize_t _b_x1118_1120 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_char_t x_1_10461;
    kk_box_t _x_x2083 = kk_std_core_hnd__open_at0(_b_x1118_1120, kk_std_time_parse_new_piso_fun2084(_ctx), _ctx); /*10426*/
    x_1_10461 = kk_char_unbox(_x_x2083, KK_OWNED, _ctx); /*char*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2088 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2089(calendar, x_10456, _ctx), _ctx); /*2419*/
      return kk_std_time_time__time_unbox(_x_x2088, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__tuple2 x_2_10464;
      kk_box_t _x_x2091;
      kk_std_core_types__list _x_x2092;
      kk_box_t _x_x2093;
      kk_function_t _x_x2094;
      kk_std_time_calendar__calendar_dup(calendar, _ctx);
      kk_integer_dup(x_10456, _ctx);
      _x_x2094 = kk_std_time_parse_new_piso_fun2095(calendar, x_10456, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1225*/
      _x_x2093 = kk_function_box(_x_x2094, _ctx); /*79*/
      kk_std_core_types__list _x_x2113;
      kk_box_t _x_x2114;
      kk_function_t _x_x2115;
      kk_integer_dup(x_10456, _ctx);
      _x_x2115 = kk_std_time_parse_new_piso_fun2116(x_10456, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1222*/
      _x_x2114 = kk_function_box(_x_x2115, _ctx); /*79*/
      kk_std_core_types__list _x_x2126;
      kk_box_t _x_x2127;
      kk_function_t _x_x2128;
      kk_integer_dup(x_10456, _ctx);
      _x_x2128 = kk_std_time_parse_new_piso_fun2129(calendar, x_10456, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1219*/
      _x_x2127 = kk_function_box(_x_x2128, _ctx); /*79*/
      kk_std_core_types__list _x_x2150;
      kk_box_t _x_x2151;
      kk_function_t _x_x2152;
      kk_integer_dup(x_10456, _ctx);
      _x_x2152 = kk_std_time_parse_new_piso_fun2153(x_10456, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1216*/
      _x_x2151 = kk_function_box(_x_x2152, _ctx); /*79*/
      kk_std_core_types__list _x_x2163 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse_new_piso_fun2164(x_10456, _ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
      _x_x2150 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2151, _x_x2163, _ctx); /*list<79>*/
      _x_x2126 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2127, _x_x2150, _ctx); /*list<79>*/
      _x_x2113 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2114, _x_x2126, _ctx); /*list<79>*/
      _x_x2092 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2093, _x_x2113, _ctx); /*list<79>*/
      _x_x2091 = kk_std_text_parse_choose(_x_x2092, _ctx); /*1639*/
      x_2_10464 = kk_std_core_types__tuple2_unbox(_x_x2091, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__tuple2_drop(x_2_10464, _ctx);
        kk_box_t _x_x2174 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2175(_ctx), _ctx); /*2419*/
        return kk_std_time_time__time_unbox(_x_x2174, KK_OWNED, _ctx);
      }
      {
        kk_box_t _box_x1249 = x_2_10464.fst;
        kk_box_t _box_x1250 = x_2_10464.snd;
        kk_std_time_date__date date = kk_std_time_date__date_unbox(_box_x1249, KK_BORROWED, _ctx);
        kk_std_time_calendar__calendar cal = kk_std_time_calendar__calendar_unbox(_box_x1250, KK_BORROWED, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2178 = kk_std_time_calendar__as_Calendar(cal, _ctx);
        kk_std_time_calendar__calendar_dup(cal, _ctx);
        kk_std_time_date__date_dup(date, _ctx);
        kk_std_core_types__tuple2_drop(x_2_10464, _ctx);
        kk_ssize_t _b_x1252_1254 = (KK_IZ(1)); /*hnd/ev-index*/;
        kk_std_time_time__time x_10_10484;
        kk_box_t _x_x2179;
        kk_function_t _x_x2180;
        kk_std_time_calendar__calendar_dup(cal, _ctx);
        kk_std_time_date__date_dup(date, _ctx);
        _x_x2180 = kk_std_time_parse_new_piso_fun2181(cal, date, _ctx); /*() -> 10427 10426*/
        _x_x2179 = kk_std_core_hnd__open_at0(_b_x1252_1254, _x_x2180, _ctx); /*10426*/
        x_10_10484 = kk_std_time_time__time_unbox(_x_x2179, KK_OWNED, _ctx); /*std/time/time/time*/
        kk_box_t _x_x2184;
        if (kk_yielding(kk_context())) {
          kk_datatype_ptr_dropn(x_10_10484, (KK_I32(9)), _ctx);
          _x_x2184 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2185(cal, date, _ctx), _ctx); /*2419*/
        }
        else {
          _x_x2184 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse_new_piso_fun2192(cal, date, _ctx), kk_std_time_parse_new_piso_fun2194(x_10_10484, _ctx), _ctx); /*2419*/
        }
        return kk_std_time_time__time_unbox(_x_x2184, KK_OWNED, _ctx);
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_parse_iso_10304_fun2196__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_parse_iso_10304_fun2196(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_parse_iso_10304_fun2196(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_parse_iso_10304_fun2196, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_parse_iso_10304_fun2196(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x2197 = kk_Unit;
  kk_std_text_parse_eof(_ctx);
  return kk_unit_box(_x_x2197);
}


// lift anonymous function
struct kk_std_time_parse__mlift_parse_iso_10304_fun2199__t {
  struct kk_function_s _base;
  kk_std_time_time__time x;
};
static kk_box_t kk_std_time_parse__mlift_parse_iso_10304_fun2199(kk_function_t _fself, kk_box_t _b_x1279, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_parse_iso_10304_fun2199(kk_std_time_time__time x, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_parse_iso_10304_fun2199__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_parse_iso_10304_fun2199__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_parse_iso_10304_fun2199, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_parse_iso_10304_fun2199(kk_function_t _fself, kk_box_t _b_x1279, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_parse_iso_10304_fun2199__t* _self = kk_function_as(struct kk_std_time_parse__mlift_parse_iso_10304_fun2199__t*, _fself, _ctx);
  kk_std_time_time__time x = _self->x; /* std/time/time/time */
  kk_drop_match(_self, {kk_std_time_time__time_dup(x, _ctx);}, {}, _ctx)
  kk_unit_t wild___1281 = kk_Unit;
  kk_unit_unbox(_b_x1279);
  return kk_std_time_time__time_box(x, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_parse_iso_10304(kk_std_time_time__time x, kk_context_t* _ctx) { /* (x : std/time/time/time) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t _b_x1274_1276 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_unit_t x_0_10490 = kk_Unit;
  kk_box_t _x_x2195 = kk_std_core_hnd__open_at0(_b_x1274_1276, kk_std_time_parse__new_mlift_parse_iso_10304_fun2196(_ctx), _ctx); /*10426*/
  kk_unit_unbox(_x_x2195);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2198 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_parse_iso_10304_fun2199(x, _ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x2198, KK_OWNED, _ctx);
  }
  {
    return x;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_parse_iso_10305_fun2201__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_parse_iso_10305_fun2201(kk_function_t _fself, kk_box_t _b_x1286, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_parse_iso_10305_fun2201(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_parse_iso_10305_fun2201, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_parse_iso_10305_fun2201(kk_function_t _fself, kk_box_t _b_x1286, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_text_parse__parse_error perr_1290 = kk_std_text_parse__parse_error_unbox(_b_x1286, KK_OWNED, _ctx); /*std/text/parse/parse-error<std/time/time/time>*/;
  kk_std_core_types__maybe _x_x2202;
  if (kk_std_text_parse__is_ParseOk(perr_1290, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2203 = kk_std_text_parse__as_ParseOk(perr_1290, _ctx);
    kk_box_t _box_x1282 = _con_x2203->result;
    kk_std_core_sslice__sslice _pat_0_0 = _con_x2203->rest;
    kk_std_time_time__time x_0 = kk_std_time_time__time_unbox(_box_x1282, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(perr_1290, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(perr_1290, _ctx);
    }
    else {
      kk_std_time_time__time_dup(x_0, _ctx);
      kk_datatype_ptr_decref(perr_1290, _ctx);
    }
    _x_x2202 = kk_std_core_types__new_Just(kk_std_time_time__time_box(x_0, _ctx), _ctx); /*maybe<88>*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2204 = kk_std_text_parse__as_ParseError(perr_1290, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x2204->rest;
    kk_string_t msg = _con_x2204->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_1290, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr_1290, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_1290, _ctx);
    }
    _x_x2202 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  return kk_std_core_types__maybe_box(_x_x2202, _ctx);
}

kk_std_core_types__maybe kk_std_time_parse__mlift_parse_iso_10305(kk_std_text_parse__parse_error _y_x10138, kk_context_t* _ctx) { /* (std/text/parse/parse-error<std/time/time/time>) -> std/time/utc/utc maybe<std/time/time/time> */ 
  kk_box_t _x_x2200 = kk_std_core_hnd__open_none1(kk_std_time_parse__new_mlift_parse_iso_10305_fun2201(_ctx), kk_std_text_parse__parse_error_box(_y_x10138, _ctx), _ctx); /*9904*/
  return kk_std_core_types__maybe_unbox(_x_x2200, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_parse_iso_fun2207__t {
  struct kk_function_s _base;
  kk_std_core_types__optional calendar;
};
static kk_box_t kk_std_time_parse_parse_iso_fun2207(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_parse_iso_fun2207(kk_std_core_types__optional calendar, kk_context_t* _ctx) {
  struct kk_std_time_parse_parse_iso_fun2207__t* _self = kk_function_alloc_as(struct kk_std_time_parse_parse_iso_fun2207__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_parse_iso_fun2207, kk_context());
  _self->calendar = calendar;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_parse_iso_fun2211__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_parse_iso_fun2211(kk_function_t _fself, kk_box_t _b_x1293, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_parse_iso_fun2211(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_parse_iso_fun2211, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_parse_iso_fun2211(kk_function_t _fself, kk_box_t _b_x1293, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_time__time _x_x2212;
  kk_std_time_time__time _x_x2213 = kk_std_time_time__time_unbox(_b_x1293, KK_OWNED, _ctx); /*std/time/time/time*/
  _x_x2212 = kk_std_time_parse__mlift_parse_iso_10304(_x_x2213, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2212, _ctx);
}
static kk_box_t kk_std_time_parse_parse_iso_fun2207(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_parse_iso_fun2207__t* _self = kk_function_as(struct kk_std_time_parse_parse_iso_fun2207__t*, _fself, _ctx);
  kk_std_core_types__optional calendar = _self->calendar; /* ? std/time/calendar/calendar */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(calendar, _ctx);}, {}, _ctx)
  kk_std_time_time__time x_0_10497;
  kk_std_time_calendar__calendar _x_x2208;
  if (kk_std_core_types__is_Optional(calendar, _ctx)) {
    kk_box_t _box_x1291 = calendar._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_calendar_766 = kk_std_time_calendar__calendar_unbox(_box_x1291, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_calendar_766, _ctx);
    kk_std_core_types__optional_drop(calendar, _ctx);
    _x_x2208 = _uniq_calendar_766; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(calendar, _ctx);
    _x_x2208 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  x_0_10497 = kk_std_time_parse_piso(_x_x2208, _ctx); /*std/time/time/time*/
  kk_std_time_time__time _x_x2209;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_0_10497, (KK_I32(9)), _ctx);
    kk_box_t _x_x2210 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_parse_iso_fun2211(_ctx), _ctx); /*2419*/
    _x_x2209 = kk_std_time_time__time_unbox(_x_x2210, KK_OWNED, _ctx); /*std/time/time/time*/
  }
  else {
    _x_x2209 = kk_std_time_parse__mlift_parse_iso_10304(x_0_10497, _ctx); /*std/time/time/time*/
  }
  return kk_std_time_time__time_box(_x_x2209, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_parse_iso_fun2215__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_parse_iso_fun2215(kk_function_t _fself, kk_box_t _b_x1300, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_parse_iso_fun2215(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_parse_iso_fun2215, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_parse_iso_fun2215(kk_function_t _fself, kk_box_t _b_x1300, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2216;
  kk_std_text_parse__parse_error _x_x2217 = kk_std_text_parse__parse_error_unbox(_b_x1300, KK_OWNED, _ctx); /*std/text/parse/parse-error<std/time/time/time>*/
  _x_x2216 = kk_std_time_parse__mlift_parse_iso_10305(_x_x2217, _ctx); /*maybe<std/time/time/time>*/
  return kk_std_core_types__maybe_box(_x_x2216, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_parse_iso_fun2218__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_parse_iso_fun2218(kk_function_t _fself, kk_box_t _b_x1305, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_parse_iso_fun2218(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_parse_iso_fun2218, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_parse_iso_fun2218(kk_function_t _fself, kk_box_t _b_x1305, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_text_parse__parse_error perr_1310 = kk_std_text_parse__parse_error_unbox(_b_x1305, KK_OWNED, _ctx); /*std/text/parse/parse-error<std/time/time/time>*/;
  kk_std_core_types__maybe _x_x2219;
  if (kk_std_text_parse__is_ParseOk(perr_1310, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2220 = kk_std_text_parse__as_ParseOk(perr_1310, _ctx);
    kk_box_t _box_x1301 = _con_x2220->result;
    kk_std_core_sslice__sslice _pat_0_0_0 = _con_x2220->rest;
    kk_std_time_time__time x_0_0 = kk_std_time_time__time_unbox(_box_x1301, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(perr_1310, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(perr_1310, _ctx);
    }
    else {
      kk_std_time_time__time_dup(x_0_0, _ctx);
      kk_datatype_ptr_decref(perr_1310, _ctx);
    }
    _x_x2219 = kk_std_core_types__new_Just(kk_std_time_time__time_box(x_0_0, _ctx), _ctx); /*maybe<88>*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2221 = kk_std_text_parse__as_ParseError(perr_1310, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x2221->rest;
    kk_string_t msg = _con_x2221->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_1310, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr_1310, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_1310, _ctx);
    }
    _x_x2219 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  return kk_std_core_types__maybe_box(_x_x2219, _ctx);
}

kk_std_core_types__maybe kk_std_time_parse_parse_iso(kk_string_t s, kk_std_core_types__optional calendar, kk_context_t* _ctx) { /* (s : string, calendar : ? std/time/calendar/calendar) -> std/time/utc/utc maybe<std/time/time/time> */ 
  kk_std_core_sslice__sslice input_10041;
  kk_string_t _x_x2205 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x2206 = kk_string_len_int(s,kk_context()); /*int*/
  input_10041 = kk_std_core_sslice__new_Sslice(_x_x2205, kk_integer_from_small(0), _x_x2206, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error x_10494 = kk_std_text_parse_parse(input_10041, kk_std_time_parse_new_parse_iso_fun2207(calendar, _ctx), _ctx); /*std/text/parse/parse-error<std/time/time/time>*/;
  kk_box_t _x_x2214;
  if (kk_yielding(kk_context())) {
    kk_std_text_parse__parse_error_drop(x_10494, _ctx);
    _x_x2214 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_parse_iso_fun2215(_ctx), _ctx); /*2419*/
  }
  else {
    _x_x2214 = kk_std_core_hnd__open_none1(kk_std_time_parse_new_parse_iso_fun2218(_ctx), kk_std_text_parse__parse_error_box(x_10494, _ctx), _ctx); /*2419*/
  }
  return kk_std_core_types__maybe_unbox(_x_x2214, KK_OWNED, _ctx);
}

// initialization
void kk_std_time_parse__init(kk_context_t* _ctx){
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
  kk_std_text_parse__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_time_duration__init(_ctx);
  kk_std_time_instant__init(_ctx);
  kk_std_time_date__init(_ctx);
  kk_std_time_calendar__init(_ctx);
  kk_std_time_calendars__init(_ctx);
  kk_std_time_time__init(_ctx);
  kk_std_time_locale__init(_ctx);
  kk_std_time_utc__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_time_parse__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_time_utc__done(_ctx);
  kk_std_time_locale__done(_ctx);
  kk_std_time_time__done(_ctx);
  kk_std_time_calendars__done(_ctx);
  kk_std_time_calendar__done(_ctx);
  kk_std_time_date__done(_ctx);
  kk_std_time_instant__done(_ctx);
  kk_std_time_duration__done(_ctx);
  kk_std_num_ddouble__done(_ctx);
  kk_std_text_parse__done(_ctx);
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
