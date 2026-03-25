// Koka generated module: std/time/parse, koka version: 3.2.2, platform: 64-bit
#include "std_time_parse.h"


// lift anonymous function
struct kk_std_time_parse_optchar_fun2042__t {
  struct kk_function_s _base;
  kk_char_t c;
};
static kk_box_t kk_std_time_parse_optchar_fun2042(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_optchar_fun2042(kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_time_parse_optchar_fun2042__t* _self = kk_function_alloc_as(struct kk_std_time_parse_optchar_fun2042__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_optchar_fun2042, kk_context());
  _self->c = c;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_optchar_fun2042(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  struct kk_std_time_parse_optchar_fun2042__t* _self = kk_function_as(struct kk_std_time_parse_optchar_fun2042__t*, _fself, _ctx);
  kk_char_t c = _self->c; /* char */
  kk_drop_match(_self, {kk_skip_dup(c, _ctx);}, {}, _ctx)
  bool _y_x10668_9 = kk_bool_unbox(_b_x7); /*bool*/;
  kk_char_t _x_x2043;
  if (_y_x10668_9) {
    _x_x2043 = kk_std_text_parse_char(c, _ctx); /*char*/
  }
  else {
    _x_x2043 = c; /*char*/
  }
  return kk_char_box(_x_x2043, _ctx);
}

kk_char_t kk_std_time_parse_optchar(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> std/text/parse/parse char */ 
  kk_std_core_hnd__ev ev_11179 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_11176;
  kk_box_t _x_x2039;
  {
    struct kk_std_core_hnd_Ev* _con_x2040 = kk_std_core_hnd__as_Ev(ev_11179, _ctx);
    kk_box_t _box_x0 = _con_x2040->hnd;
    int32_t m = _con_x2040->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1986;
    kk_std_core_hnd__clause0 _brw_x1987 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1986 = _brw_x1987; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x3 = _match_x1986.clause;
      _x_x2039 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3, (_fun_unbox_x3, m, ev_11179, _ctx), _ctx); /*10005*/
    }
  }
  x_11176 = kk_bool_unbox(_x_x2039); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2041 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_optchar_fun2042(c, _ctx), _ctx); /*10001*/
    return kk_char_unbox(_x_x2041, KK_OWNED, _ctx);
  }
  if (x_11176) {
    return kk_std_text_parse_char(c, _ctx);
  }
  {
    return c;
  }
}


// lift anonymous function
struct kk_std_time_parse_dash_fun2047__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_dash_fun2047(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_dash_fun2047(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_dash_fun2047, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_dash_fun2047(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2048;
  bool _x_x2049 = kk_bool_unbox(_b_x17); /*bool*/
  _x_x2048 = kk_std_time_parse__mlift_dash_11095(_x_x2049, _ctx); /*char*/
  return kk_char_box(_x_x2048, _ctx);
}

kk_char_t kk_std_time_parse_dash(kk_context_t* _ctx) { /* () -> std/text/parse/parse char */ 
  kk_std_core_hnd__ev ev_11186 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_11183;
  kk_box_t _x_x2044;
  {
    struct kk_std_core_hnd_Ev* _con_x2045 = kk_std_core_hnd__as_Ev(ev_11186, _ctx);
    kk_box_t _box_x10 = _con_x2045->hnd;
    int32_t m = _con_x2045->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x10, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1983;
    kk_std_core_hnd__clause0 _brw_x1984 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1983 = _brw_x1984; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x13 = _match_x1983.clause;
      _x_x2044 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x13, (_fun_unbox_x13, m, ev_11186, _ctx), _ctx); /*10005*/
    }
  }
  x_11183 = kk_bool_unbox(_x_x2044); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2046 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_dash_fun2047(_ctx), _ctx); /*10001*/
    return kk_char_unbox(_x_x2046, KK_OWNED, _ctx);
  }
  if (x_11183) {
    return kk_std_text_parse_char('-', _ctx);
  }
  {
    return '-';
  }
}


// lift anonymous function
struct kk_std_time_parse_colon_fun2053__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_colon_fun2053(kk_function_t _fself, kk_box_t _b_x26, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_colon_fun2053(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_colon_fun2053, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_colon_fun2053(kk_function_t _fself, kk_box_t _b_x26, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2054;
  bool _x_x2055 = kk_bool_unbox(_b_x26); /*bool*/
  _x_x2054 = kk_std_time_parse__mlift_colon_11096(_x_x2055, _ctx); /*char*/
  return kk_char_box(_x_x2054, _ctx);
}

kk_char_t kk_std_time_parse_colon(kk_context_t* _ctx) { /* () -> std/text/parse/parse char */ 
  kk_std_core_hnd__ev ev_11191 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_11188;
  kk_box_t _x_x2050;
  {
    struct kk_std_core_hnd_Ev* _con_x2051 = kk_std_core_hnd__as_Ev(ev_11191, _ctx);
    kk_box_t _box_x19 = _con_x2051->hnd;
    int32_t m = _con_x2051->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x19, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1980;
    kk_std_core_hnd__clause0 _brw_x1981 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1980 = _brw_x1981; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x22 = _match_x1980.clause;
      _x_x2050 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x22, (_fun_unbox_x22, m, ev_11191, _ctx), _ctx); /*10005*/
    }
  }
  x_11188 = kk_bool_unbox(_x_x2050); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2052 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_colon_fun2053(_ctx), _ctx); /*10001*/
    return kk_char_unbox(_x_x2052, KK_OWNED, _ctx);
  }
  if (x_11188) {
    return kk_std_text_parse_char(':', _ctx);
  }
  {
    return ':';
  }
}
 
// lifted local: @lift-num@10608, num, @spec-x10156
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10151, using:
// @uniq-f@10151 = fn<(std/text/parse/parse :: (E, V) -> V)>(x: int, d: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@0: int, y: int){
//     (std/core/int/int-add(x@0, y));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x, 10)), d);
// }

kk_integer_t kk_std_time_parse__lift_num_10609(kk_std_core_types__list _uniq_xs_10149, kk_integer_t _uniq_z_10150, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10149, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2056 = kk_std_core_types__as_Cons(_uniq_xs_10149, _ctx);
    kk_box_t _box_x28 = _con_x2056->head;
    kk_std_core_types__list _uniq_xx_10154 = _con_x2056->tail;
    kk_integer_t _uniq_x_10153 = kk_integer_unbox(_box_x28, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10149, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10149, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10153, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10154, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10149, _ctx);
    }
    kk_integer_t x_0_10911 = kk_integer_mul(_uniq_z_10150,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2057 = kk_integer_add(x_0_10911,_uniq_x_10153,kk_context()); /*int*/
      _uniq_xs_10149 = _uniq_xx_10154;
      _uniq_z_10150 = _x_x2057;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10150;
  }
}
 
// lifted local: num, @spec-x10148
// specialized: std/core/list/foldl, on parameters @uniq-f@10145, using:
// @uniq-f@10145 = fn<(std/text/parse/parse :: (E, V) -> V)>(x: int, d: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@0: int, y: int){
//     (std/core/int/int-add(x@0, y));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x, 10)), d);
// }

kk_integer_t kk_std_time_parse__lift_num_10608(kk_std_core_types__list _uniq_xs_10143, kk_integer_t _uniq_z_10144, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10143, _ctx)) {
    return _uniq_z_10144;
  }
  {
    return kk_std_time_parse__lift_num_10609(_uniq_xs_10143, _uniq_z_10144, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_num_10611_11097(kk_std_core_types__list _uniq_acc_10163, kk_integer_t _uniq_n_10162, kk_integer_t _uniq_x_10170, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2058 = kk_integer_add_small_const(_uniq_n_10162, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2059 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10170, _ctx), _uniq_acc_10163, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_num_10611(_x_x2058, _x_x2059, _ctx);
}
 
// lifted local: @lift-num@10610, num, @spec-x10173
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10164, using:
// @uniq-p@10164 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_num_10611_fun2061__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10163_0;
  kk_integer_t _uniq_n_10162_0;
};
static kk_box_t kk_std_time_parse__lift_num_10611_fun2061(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_num_10611_fun2061(kk_std_core_types__list _uniq_acc_10163_0, kk_integer_t _uniq_n_10162_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_num_10611_fun2061__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_num_10611_fun2061__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_num_10611_fun2061, kk_context());
  _self->_uniq_acc_10163_0 = _uniq_acc_10163_0;
  _self->_uniq_n_10162_0 = _uniq_n_10162_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_num_10611_fun2061(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_num_10611_fun2061__t* _self = kk_function_as(struct kk_std_time_parse__lift_num_10611_fun2061__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10163_0 = _self->_uniq_acc_10163_0; /* list<int> */
  kk_integer_t _uniq_n_10162_0 = _self->_uniq_n_10162_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10163_0, _ctx);kk_integer_dup(_uniq_n_10162_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10170_0_40 = kk_integer_unbox(_b_x34, _ctx); /*int*/;
  kk_std_core_types__list _x_x2062 = kk_std_time_parse__mlift_lift_num_10611_11097(_uniq_acc_10163_0, _uniq_n_10162_0, _uniq_x_10170_0_40, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2062, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_num_10611(kk_integer_t _uniq_n_10162_0, kk_std_core_types__list _uniq_acc_10163_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1977 = kk_integer_lte_borrow(_uniq_n_10162_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1977) {
    kk_integer_drop(_uniq_n_10162_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10163_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10163_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11195 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11195, _ctx);
      kk_box_t _x_x2060 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_num_10611_fun2061(_uniq_acc_10163_0, _uniq_n_10162_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2060, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2063 = kk_integer_add_small_const(_uniq_n_10162_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2064 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11195, _ctx), _uniq_acc_10163_0, _ctx); /*list<10021>*/
      _uniq_n_10162_0 = _x_x2063;
      _uniq_acc_10163_0 = _x_x2064;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: num, @spec-x10161
// specialized: std/text/parse/count, on parameters @uniq-p@10160, using:
// @uniq-p@10160 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_num_10610(kk_integer_t _uniq_n_10159, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_num_10611(_uniq_n_10159, kk_std_core_types__new_Nil(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse_num_fun2066__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_num_fun2066(kk_function_t _fself, kk_box_t _b_x42, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_num_fun2066(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_num_fun2066, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_num_fun2066(kk_function_t _fself, kk_box_t _b_x42, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2067;
  kk_std_core_types__list _x_x2068 = kk_std_core_types__list_unbox(_b_x42, KK_OWNED, _ctx); /*list<int>*/
  _x_x2067 = kk_std_time_parse__mlift_num_11098(_x_x2068, _ctx); /*int*/
  return kk_integer_box(_x_x2067, _ctx);
}

kk_integer_t kk_std_time_parse_num(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> std/text/parse/parse int */ 
  kk_std_core_types__list x_11198 = kk_std_time_parse__lift_num_10610(n, _ctx); /*list<int>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_11198, _ctx);
    kk_box_t _x_x2065 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_num_fun2066(_ctx), _ctx); /*10001*/
    return kk_integer_unbox(_x_x2065, _ctx);
  }
  {
    return kk_std_time_parse__lift_num_10608(x_11198, kk_integer_from_small(0), _ctx);
  }
}
 
// lifted local: @lift-ptime@10612, hour, ptime, @spec-x10187
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10182, using:
// @uniq-f@10182 = fn<(std/text/parse/parse :: (E, V) -> V)>(x: int, d: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@0: int, y: int){
//     (std/core/int/int-add(x@0, y));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x, 10)), d);
// }

kk_integer_t kk_std_time_parse__lift_ptime_10613(kk_std_core_types__list _uniq_xs_10180, kk_integer_t _uniq_z_10181, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10180, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2069 = kk_std_core_types__as_Cons(_uniq_xs_10180, _ctx);
    kk_box_t _box_x44 = _con_x2069->head;
    kk_std_core_types__list _uniq_xx_10185 = _con_x2069->tail;
    kk_integer_t _uniq_x_10184 = kk_integer_unbox(_box_x44, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10180, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10180, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10184, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10185, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10180, _ctx);
    }
    kk_integer_t x_0_10916 = kk_integer_mul(_uniq_z_10181,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2070 = kk_integer_add(x_0_10916,_uniq_x_10184,kk_context()); /*int*/
      _uniq_xs_10180 = _uniq_xx_10185;
      _uniq_z_10181 = _x_x2070;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10181;
  }
}
 
// lifted local: hour, ptime, @spec-x10179
// specialized: std/core/list/foldl, on parameters @uniq-f@10176, using:
// @uniq-f@10176 = fn<(std/text/parse/parse :: (E, V) -> V)>(x: int, d: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@0: int, y: int){
//     (std/core/int/int-add(x@0, y));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x, 10)), d);
// }

kk_integer_t kk_std_time_parse__lift_ptime_10612(kk_std_core_types__list _uniq_xs_10174, kk_integer_t _uniq_z_10175, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10174, _ctx)) {
    return _uniq_z_10175;
  }
  {
    return kk_std_time_parse__lift_ptime_10613(_uniq_xs_10174, _uniq_z_10175, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_ptime_10615_11099(kk_std_core_types__list _uniq_acc_10194, kk_integer_t _uniq_n_10193, kk_integer_t _uniq_x_10201, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2071 = kk_integer_add_small_const(_uniq_n_10193, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2072 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10201, _ctx), _uniq_acc_10194, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_ptime_10615(_x_x2071, _x_x2072, _ctx);
}
 
// lifted local: @lift-ptime@10614, hour, ptime, @spec-x10204
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10195, using:
// @uniq-p@10195 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_ptime_10615_fun2074__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10194_0;
  kk_integer_t _uniq_n_10193_0;
};
static kk_box_t kk_std_time_parse__lift_ptime_10615_fun2074(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_ptime_10615_fun2074(kk_std_core_types__list _uniq_acc_10194_0, kk_integer_t _uniq_n_10193_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_ptime_10615_fun2074__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_ptime_10615_fun2074__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_ptime_10615_fun2074, kk_context());
  _self->_uniq_acc_10194_0 = _uniq_acc_10194_0;
  _self->_uniq_n_10193_0 = _uniq_n_10193_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_ptime_10615_fun2074(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_ptime_10615_fun2074__t* _self = kk_function_as(struct kk_std_time_parse__lift_ptime_10615_fun2074__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10194_0 = _self->_uniq_acc_10194_0; /* list<int> */
  kk_integer_t _uniq_n_10193_0 = _self->_uniq_n_10193_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10194_0, _ctx);kk_integer_dup(_uniq_n_10193_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10201_0_56 = kk_integer_unbox(_b_x50, _ctx); /*int*/;
  kk_std_core_types__list _x_x2075 = kk_std_time_parse__mlift_lift_ptime_10615_11099(_uniq_acc_10194_0, _uniq_n_10193_0, _uniq_x_10201_0_56, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2075, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_ptime_10615(kk_integer_t _uniq_n_10193_0, kk_std_core_types__list _uniq_acc_10194_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1974 = kk_integer_lte_borrow(_uniq_n_10193_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1974) {
    kk_integer_drop(_uniq_n_10193_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10194_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10194_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11203 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11203, _ctx);
      kk_box_t _x_x2073 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_ptime_10615_fun2074(_uniq_acc_10194_0, _uniq_n_10193_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2073, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2076 = kk_integer_add_small_const(_uniq_n_10193_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2077 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11203, _ctx), _uniq_acc_10194_0, _ctx); /*list<10021>*/
      _uniq_n_10193_0 = _x_x2076;
      _uniq_acc_10194_0 = _x_x2077;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: hour, ptime, @spec-x10192
// specialized: std/text/parse/count, on parameters @uniq-p@10191, using:
// @uniq-p@10191 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_ptime_10614(kk_integer_t _uniq_n_10190, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_ptime_10615(_uniq_n_10190, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-ptime@10616, min, ptime, @spec-x10218
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10213, using:
// @uniq-f@10213 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@1: int, d@0: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@2: int, y@0: int){
//     (std/core/int/int-add(x@2, y@0));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@1, 10)), d@0);
// }

kk_integer_t kk_std_time_parse__lift_ptime_10617(kk_std_core_types__list _uniq_xs_10211, kk_integer_t _uniq_z_10212, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10211, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2078 = kk_std_core_types__as_Cons(_uniq_xs_10211, _ctx);
    kk_box_t _box_x57 = _con_x2078->head;
    kk_std_core_types__list _uniq_xx_10216 = _con_x2078->tail;
    kk_integer_t _uniq_x_10215 = kk_integer_unbox(_box_x57, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10211, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10211, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10215, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10216, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10211, _ctx);
    }
    kk_integer_t x_2_10921 = kk_integer_mul(_uniq_z_10212,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2079 = kk_integer_add(x_2_10921,_uniq_x_10215,kk_context()); /*int*/
      _uniq_xs_10211 = _uniq_xx_10216;
      _uniq_z_10212 = _x_x2079;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10212;
  }
}
 
// lifted local: min, ptime, @spec-x10210
// specialized: std/core/list/foldl, on parameters @uniq-f@10207, using:
// @uniq-f@10207 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@1: int, d@0: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@2: int, y@0: int){
//     (std/core/int/int-add(x@2, y@0));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@1, 10)), d@0);
// }

kk_integer_t kk_std_time_parse__lift_ptime_10616(kk_std_core_types__list _uniq_xs_10205, kk_integer_t _uniq_z_10206, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10205, _ctx)) {
    return _uniq_z_10206;
  }
  {
    return kk_std_time_parse__lift_ptime_10617(_uniq_xs_10205, _uniq_z_10206, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_ptime_10619_11100(kk_std_core_types__list _uniq_acc_10225, kk_integer_t _uniq_n_10224, kk_integer_t _uniq_x_10232, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2080 = kk_integer_add_small_const(_uniq_n_10224, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2081 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10232, _ctx), _uniq_acc_10225, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_ptime_10619(_x_x2080, _x_x2081, _ctx);
}
 
// lifted local: @lift-ptime@10618, min, ptime, @spec-x10235
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10226, using:
// @uniq-p@10226 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_ptime_10619_fun2083__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10225_0;
  kk_integer_t _uniq_n_10224_0;
};
static kk_box_t kk_std_time_parse__lift_ptime_10619_fun2083(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_ptime_10619_fun2083(kk_std_core_types__list _uniq_acc_10225_0, kk_integer_t _uniq_n_10224_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_ptime_10619_fun2083__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_ptime_10619_fun2083__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_ptime_10619_fun2083, kk_context());
  _self->_uniq_acc_10225_0 = _uniq_acc_10225_0;
  _self->_uniq_n_10224_0 = _uniq_n_10224_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_ptime_10619_fun2083(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_ptime_10619_fun2083__t* _self = kk_function_as(struct kk_std_time_parse__lift_ptime_10619_fun2083__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10225_0 = _self->_uniq_acc_10225_0; /* list<int> */
  kk_integer_t _uniq_n_10224_0 = _self->_uniq_n_10224_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10225_0, _ctx);kk_integer_dup(_uniq_n_10224_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10232_0_69 = kk_integer_unbox(_b_x63, _ctx); /*int*/;
  kk_std_core_types__list _x_x2084 = kk_std_time_parse__mlift_lift_ptime_10619_11100(_uniq_acc_10225_0, _uniq_n_10224_0, _uniq_x_10232_0_69, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2084, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_ptime_10619(kk_integer_t _uniq_n_10224_0, kk_std_core_types__list _uniq_acc_10225_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1972 = kk_integer_lte_borrow(_uniq_n_10224_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1972) {
    kk_integer_drop(_uniq_n_10224_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10225_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10225_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11208 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11208, _ctx);
      kk_box_t _x_x2082 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_ptime_10619_fun2083(_uniq_acc_10225_0, _uniq_n_10224_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2082, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2085 = kk_integer_add_small_const(_uniq_n_10224_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2086 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11208, _ctx), _uniq_acc_10225_0, _ctx); /*list<10021>*/
      _uniq_n_10224_0 = _x_x2085;
      _uniq_acc_10225_0 = _x_x2086;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: min, ptime, @spec-x10223
// specialized: std/text/parse/count, on parameters @uniq-p@10222, using:
// @uniq-p@10222 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_ptime_10618(kk_integer_t _uniq_n_10221, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_ptime_10619(_uniq_n_10221, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-ptime@10620, s, secs, ptime, @spec-x10249
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10244, using:
// @uniq-f@10244 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@3: int, d@1: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@4: int, y@1: int){
//     (std/core/int/int-add(x@4, y@1));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@3, 10)), d@1);
// }

kk_integer_t kk_std_time_parse__lift_ptime_10621(kk_std_core_types__list _uniq_xs_10242, kk_integer_t _uniq_z_10243, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10242, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2087 = kk_std_core_types__as_Cons(_uniq_xs_10242, _ctx);
    kk_box_t _box_x70 = _con_x2087->head;
    kk_std_core_types__list _uniq_xx_10247 = _con_x2087->tail;
    kk_integer_t _uniq_x_10246 = kk_integer_unbox(_box_x70, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10242, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10242, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10246, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10247, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10242, _ctx);
    }
    kk_integer_t x_4_10926 = kk_integer_mul(_uniq_z_10243,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2088 = kk_integer_add(x_4_10926,_uniq_x_10246,kk_context()); /*int*/
      _uniq_xs_10242 = _uniq_xx_10247;
      _uniq_z_10243 = _x_x2088;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10243;
  }
}
 
// lifted local: s, secs, ptime, @spec-x10241
// specialized: std/core/list/foldl, on parameters @uniq-f@10238, using:
// @uniq-f@10238 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@3: int, d@1: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@4: int, y@1: int){
//     (std/core/int/int-add(x@4, y@1));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@3, 10)), d@1);
// }

kk_integer_t kk_std_time_parse__lift_ptime_10620(kk_std_core_types__list _uniq_xs_10236, kk_integer_t _uniq_z_10237, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10236, _ctx)) {
    return _uniq_z_10237;
  }
  {
    return kk_std_time_parse__lift_ptime_10621(_uniq_xs_10236, _uniq_z_10237, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_ptime_10623_11101(kk_std_core_types__list _uniq_acc_10256, kk_integer_t _uniq_n_10255, kk_integer_t _uniq_x_10263, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2089 = kk_integer_add_small_const(_uniq_n_10255, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2090 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10263, _ctx), _uniq_acc_10256, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_ptime_10623(_x_x2089, _x_x2090, _ctx);
}
 
// lifted local: @lift-ptime@10622, s, secs, ptime, @spec-x10266
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10257, using:
// @uniq-p@10257 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_ptime_10623_fun2092__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10256_0;
  kk_integer_t _uniq_n_10255_0;
};
static kk_box_t kk_std_time_parse__lift_ptime_10623_fun2092(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_ptime_10623_fun2092(kk_std_core_types__list _uniq_acc_10256_0, kk_integer_t _uniq_n_10255_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_ptime_10623_fun2092__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_ptime_10623_fun2092__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_ptime_10623_fun2092, kk_context());
  _self->_uniq_acc_10256_0 = _uniq_acc_10256_0;
  _self->_uniq_n_10255_0 = _uniq_n_10255_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_ptime_10623_fun2092(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_ptime_10623_fun2092__t* _self = kk_function_as(struct kk_std_time_parse__lift_ptime_10623_fun2092__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10256_0 = _self->_uniq_acc_10256_0; /* list<int> */
  kk_integer_t _uniq_n_10255_0 = _self->_uniq_n_10255_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10256_0, _ctx);kk_integer_dup(_uniq_n_10255_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10263_0_82 = kk_integer_unbox(_b_x76, _ctx); /*int*/;
  kk_std_core_types__list _x_x2093 = kk_std_time_parse__mlift_lift_ptime_10623_11101(_uniq_acc_10256_0, _uniq_n_10255_0, _uniq_x_10263_0_82, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2093, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_ptime_10623(kk_integer_t _uniq_n_10255_0, kk_std_core_types__list _uniq_acc_10256_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1970 = kk_integer_lte_borrow(_uniq_n_10255_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1970) {
    kk_integer_drop(_uniq_n_10255_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10256_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10256_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11213 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11213, _ctx);
      kk_box_t _x_x2091 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_ptime_10623_fun2092(_uniq_acc_10256_0, _uniq_n_10255_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2091, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2094 = kk_integer_add_small_const(_uniq_n_10255_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2095 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11213, _ctx), _uniq_acc_10256_0, _ctx); /*list<10021>*/
      _uniq_n_10255_0 = _x_x2094;
      _uniq_acc_10256_0 = _x_x2095;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: s, secs, ptime, @spec-x10254
// specialized: std/text/parse/count, on parameters @uniq-p@10253, using:
// @uniq-p@10253 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_ptime_10622(kk_integer_t _uniq_n_10252, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_ptime_10623(_uniq_n_10252, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-ptime@10624, tzhour, ps@10020, ptime, @spec-x10280
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10275, using:
// @uniq-f@10275 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@6: int, d@2: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@7: int, y@2: int){
//     (std/core/int/int-add(x@7, y@2));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@6, 10)), d@2);
// }

kk_integer_t kk_std_time_parse__lift_ptime_10625(kk_std_core_types__list _uniq_xs_10273, kk_integer_t _uniq_z_10274, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10273, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2096 = kk_std_core_types__as_Cons(_uniq_xs_10273, _ctx);
    kk_box_t _box_x83 = _con_x2096->head;
    kk_std_core_types__list _uniq_xx_10278 = _con_x2096->tail;
    kk_integer_t _uniq_x_10277 = kk_integer_unbox(_box_x83, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10273, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10273, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10277, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10278, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10273, _ctx);
    }
    kk_integer_t x_7_10931 = kk_integer_mul(_uniq_z_10274,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2097 = kk_integer_add(x_7_10931,_uniq_x_10277,kk_context()); /*int*/
      _uniq_xs_10273 = _uniq_xx_10278;
      _uniq_z_10274 = _x_x2097;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10274;
  }
}
 
// lifted local: tzhour, ps@10020, ptime, @spec-x10272
// specialized: std/core/list/foldl, on parameters @uniq-f@10269, using:
// @uniq-f@10269 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@6: int, d@2: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@7: int, y@2: int){
//     (std/core/int/int-add(x@7, y@2));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@6, 10)), d@2);
// }

kk_integer_t kk_std_time_parse__lift_ptime_10624(kk_std_core_types__list _uniq_xs_10267, kk_integer_t _uniq_z_10268, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10267, _ctx)) {
    return _uniq_z_10268;
  }
  {
    return kk_std_time_parse__lift_ptime_10625(_uniq_xs_10267, _uniq_z_10268, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_ptime_10627_11102(kk_std_core_types__list _uniq_acc_10287, kk_integer_t _uniq_n_10286, kk_integer_t _uniq_x_10294, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2098 = kk_integer_add_small_const(_uniq_n_10286, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2099 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10294, _ctx), _uniq_acc_10287, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_ptime_10627(_x_x2098, _x_x2099, _ctx);
}
 
// lifted local: @lift-ptime@10626, tzhour, ps@10020, ptime, @spec-x10297
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10288, using:
// @uniq-p@10288 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_ptime_10627_fun2101__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10287_0;
  kk_integer_t _uniq_n_10286_0;
};
static kk_box_t kk_std_time_parse__lift_ptime_10627_fun2101(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_ptime_10627_fun2101(kk_std_core_types__list _uniq_acc_10287_0, kk_integer_t _uniq_n_10286_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_ptime_10627_fun2101__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_ptime_10627_fun2101__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_ptime_10627_fun2101, kk_context());
  _self->_uniq_acc_10287_0 = _uniq_acc_10287_0;
  _self->_uniq_n_10286_0 = _uniq_n_10286_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_ptime_10627_fun2101(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_ptime_10627_fun2101__t* _self = kk_function_as(struct kk_std_time_parse__lift_ptime_10627_fun2101__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10287_0 = _self->_uniq_acc_10287_0; /* list<int> */
  kk_integer_t _uniq_n_10286_0 = _self->_uniq_n_10286_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10287_0, _ctx);kk_integer_dup(_uniq_n_10286_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10294_0_95 = kk_integer_unbox(_b_x89, _ctx); /*int*/;
  kk_std_core_types__list _x_x2102 = kk_std_time_parse__mlift_lift_ptime_10627_11102(_uniq_acc_10287_0, _uniq_n_10286_0, _uniq_x_10294_0_95, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2102, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_ptime_10627(kk_integer_t _uniq_n_10286_0, kk_std_core_types__list _uniq_acc_10287_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1968 = kk_integer_lte_borrow(_uniq_n_10286_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1968) {
    kk_integer_drop(_uniq_n_10286_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10287_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10287_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11218 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11218, _ctx);
      kk_box_t _x_x2100 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_ptime_10627_fun2101(_uniq_acc_10287_0, _uniq_n_10286_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2100, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2103 = kk_integer_add_small_const(_uniq_n_10286_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2104 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11218, _ctx), _uniq_acc_10287_0, _ctx); /*list<10021>*/
      _uniq_n_10286_0 = _x_x2103;
      _uniq_acc_10287_0 = _x_x2104;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: tzhour, ps@10020, ptime, @spec-x10285
// specialized: std/text/parse/count, on parameters @uniq-p@10284, using:
// @uniq-p@10284 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_ptime_10626(kk_integer_t _uniq_n_10283, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_ptime_10627(_uniq_n_10283, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-ptime@10628, tzmin, ps@10020, ptime, @spec-x10311
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10306, using:
// @uniq-f@10306 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@8: int, d@3: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@9: int, y@3: int){
//     (std/core/int/int-add(x@9, y@3));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@8, 10)), d@3);
// }

kk_integer_t kk_std_time_parse__lift_ptime_10629(kk_std_core_types__list _uniq_xs_10304, kk_integer_t _uniq_z_10305, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10304, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2105 = kk_std_core_types__as_Cons(_uniq_xs_10304, _ctx);
    kk_box_t _box_x96 = _con_x2105->head;
    kk_std_core_types__list _uniq_xx_10309 = _con_x2105->tail;
    kk_integer_t _uniq_x_10308 = kk_integer_unbox(_box_x96, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10304, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10304, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10308, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10309, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10304, _ctx);
    }
    kk_integer_t x_9_10936 = kk_integer_mul(_uniq_z_10305,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2106 = kk_integer_add(x_9_10936,_uniq_x_10308,kk_context()); /*int*/
      _uniq_xs_10304 = _uniq_xx_10309;
      _uniq_z_10305 = _x_x2106;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10305;
  }
}
 
// lifted local: tzmin, ps@10020, ptime, @spec-x10303
// specialized: std/core/list/foldl, on parameters @uniq-f@10300, using:
// @uniq-f@10300 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@8: int, d@3: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@9: int, y@3: int){
//     (std/core/int/int-add(x@9, y@3));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@8, 10)), d@3);
// }

kk_integer_t kk_std_time_parse__lift_ptime_10628(kk_std_core_types__list _uniq_xs_10298, kk_integer_t _uniq_z_10299, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10298, _ctx)) {
    return _uniq_z_10299;
  }
  {
    return kk_std_time_parse__lift_ptime_10629(_uniq_xs_10298, _uniq_z_10299, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_ptime_10631_11103(kk_std_core_types__list _uniq_acc_10318, kk_integer_t _uniq_n_10317, kk_integer_t _uniq_x_10325, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2107 = kk_integer_add_small_const(_uniq_n_10317, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2108 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10325, _ctx), _uniq_acc_10318, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_ptime_10631(_x_x2107, _x_x2108, _ctx);
}
 
// lifted local: @lift-ptime@10630, tzmin, ps@10020, ptime, @spec-x10328
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10319, using:
// @uniq-p@10319 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_ptime_10631_fun2110__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10318_0;
  kk_integer_t _uniq_n_10317_0;
};
static kk_box_t kk_std_time_parse__lift_ptime_10631_fun2110(kk_function_t _fself, kk_box_t _b_x102, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_ptime_10631_fun2110(kk_std_core_types__list _uniq_acc_10318_0, kk_integer_t _uniq_n_10317_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_ptime_10631_fun2110__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_ptime_10631_fun2110__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_ptime_10631_fun2110, kk_context());
  _self->_uniq_acc_10318_0 = _uniq_acc_10318_0;
  _self->_uniq_n_10317_0 = _uniq_n_10317_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_ptime_10631_fun2110(kk_function_t _fself, kk_box_t _b_x102, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_ptime_10631_fun2110__t* _self = kk_function_as(struct kk_std_time_parse__lift_ptime_10631_fun2110__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10318_0 = _self->_uniq_acc_10318_0; /* list<int> */
  kk_integer_t _uniq_n_10317_0 = _self->_uniq_n_10317_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10318_0, _ctx);kk_integer_dup(_uniq_n_10317_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10325_0_108 = kk_integer_unbox(_b_x102, _ctx); /*int*/;
  kk_std_core_types__list _x_x2111 = kk_std_time_parse__mlift_lift_ptime_10631_11103(_uniq_acc_10318_0, _uniq_n_10317_0, _uniq_x_10325_0_108, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2111, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_ptime_10631(kk_integer_t _uniq_n_10317_0, kk_std_core_types__list _uniq_acc_10318_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1966 = kk_integer_lte_borrow(_uniq_n_10317_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1966) {
    kk_integer_drop(_uniq_n_10317_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10318_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10318_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11223 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11223, _ctx);
      kk_box_t _x_x2109 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_ptime_10631_fun2110(_uniq_acc_10318_0, _uniq_n_10317_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2109, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2112 = kk_integer_add_small_const(_uniq_n_10317_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2113 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11223, _ctx), _uniq_acc_10318_0, _ctx); /*list<10021>*/
      _uniq_n_10317_0 = _x_x2112;
      _uniq_acc_10318_0 = _x_x2113;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: tzmin, ps@10020, ptime, @spec-x10316
// specialized: std/text/parse/count, on parameters @uniq-p@10315, using:
// @uniq-p@10315 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_ptime_10630(kk_integer_t _uniq_n_10314, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_ptime_10631(_uniq_n_10314, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11106_fun2116__t {
  struct kk_function_s _base;
  kk_integer_t tzmin;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11106_fun2116(kk_function_t _fself, kk_box_t _b_x112, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11106_fun2116(kk_integer_t tzmin, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11106_fun2116__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11106_fun2116__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11106_fun2116, kk_context());
  _self->tzmin = tzmin;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11106_fun2116(kk_function_t _fself, kk_box_t _b_x112, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11106_fun2116__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11106_fun2116__t*, _fself, _ctx);
  kk_integer_t tzmin = _self->tzmin; /* int */
  kk_drop_match(_self, {kk_integer_dup(tzmin, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10768_114 = kk_integer_unbox(_b_x112, _ctx); /*int*/;
  kk_std_time_calendar__timezone _x_x2117 = kk_std_time_parse__mlift_ptime_11104(tzmin, _c_x10768_114, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2117, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11106(kk_char_t sign, kk_integer_t tzhour, kk_integer_t tzmin, kk_context_t* _ctx) { /* (sign : char, tzhour : int, tzmin : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
  kk_integer_t x_11227;
  bool _match_x1965 = (sign == ('-')); /*bool*/;
  if (_match_x1965) {
    x_11227 = kk_integer_neg(tzhour,kk_context()); /*int*/
  }
  else {
    x_11227 = tzhour; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11227, _ctx);
    kk_box_t _x_x2115 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11106_fun2116(tzmin, _ctx), _ctx); /*10001*/
    return kk_std_time_calendar__timezone_unbox(_x_x2115, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11104(tzmin, x_11227, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11108_fun2119__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11108_fun2119(kk_function_t _fself, kk_box_t _b_x116, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11108_fun2119(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11108_fun2119, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11108_fun2119(kk_function_t _fself, kk_box_t _b_x116, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2120;
  kk_std_core_types__list _x_x2121 = kk_std_core_types__list_unbox(_b_x116, KK_OWNED, _ctx); /*list<int>*/
  _x_x2120 = kk_std_time_parse__mlift_ptime_11105(_x_x2121, _ctx); /*int*/
  return kk_integer_box(_x_x2120, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11108_fun2123__t {
  struct kk_function_s _base;
  kk_ssize_t i_11231;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11108_fun2123(kk_function_t _fself, kk_function_t _b_x123, kk_box_t _b_x124, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11108_fun2123(kk_ssize_t i_11231, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11108_fun2123__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11108_fun2123__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11108_fun2123, kk_context());
  _self->i_11231 = i_11231;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11108_fun2123(kk_function_t _fself, kk_function_t _b_x123, kk_box_t _b_x124, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11108_fun2123__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11108_fun2123__t*, _fself, _ctx);
  kk_ssize_t i_11231 = _self->i_11231; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11231, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11231, _b_x123, _b_x124, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11108_fun2125__t {
  struct kk_function_s _base;
  kk_integer_t tzhour;
  kk_char_t sign;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11108_fun2125(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11108_fun2125(kk_integer_t tzhour, kk_char_t sign, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11108_fun2125__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11108_fun2125__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11108_fun2125, kk_context());
  _self->tzhour = tzhour;
  _self->sign = sign;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11108_fun2125(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11108_fun2125__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11108_fun2125__t*, _fself, _ctx);
  kk_integer_t tzhour = _self->tzhour; /* int */
  kk_char_t sign = _self->sign; /* char */
  kk_drop_match(_self, {kk_integer_dup(tzhour, _ctx);kk_skip_dup(sign, _ctx);}, {}, _ctx)
  kk_integer_t tzmin_136 = kk_integer_unbox(_b_x133, _ctx); /*int*/;
  kk_std_time_calendar__timezone _x_x2126 = kk_std_time_parse__mlift_ptime_11106(sign, tzhour, tzmin_136, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2126, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11108(kk_char_t sign, kk_integer_t tzhour, kk_char_t wild___3, kk_context_t* _ctx) { /* (sign : char, tzhour : int, wild_@3 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
  kk_ssize_t i_11231 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11231,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_1_11234 = kk_std_time_parse__lift_ptime_10630(kk_integer_from_small(2), _ctx); /*list<int>*/;
  kk_integer_t y;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_11234, _ctx);
    kk_box_t _x_x2118 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11108_fun2119(_ctx), _ctx); /*10001*/
    y = kk_integer_unbox(_x_x2118, _ctx); /*int*/
  }
  else {
    y = kk_std_time_parse__lift_ptime_10628(x_1_11234, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w,kk_context());
  kk_integer_t x_11229;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y, _ctx);
    kk_box_t _x_x2122 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11108_fun2123(i_11231, _ctx), _ctx); /*10002*/
    x_11229 = kk_integer_unbox(_x_x2122, _ctx); /*int*/
  }
  else {
    x_11229 = y; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11229, _ctx);
    kk_box_t _x_x2124 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11108_fun2125(tzhour, sign, _ctx), _ctx); /*10001*/
    return kk_std_time_calendar__timezone_unbox(_x_x2124, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11106(sign, tzhour, x_11229, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11110_fun2130__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11110_fun2130(kk_function_t _fself, kk_box_t _b_x144, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11110_fun2130(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11110_fun2130, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11110_fun2130(kk_function_t _fself, kk_box_t _b_x144, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2131;
  bool _x_x2132 = kk_bool_unbox(_b_x144); /*bool*/
  _x_x2131 = kk_std_time_parse__mlift_ptime_11107(_x_x2132, _ctx); /*char*/
  return kk_char_box(_x_x2131, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11110_fun2134__t {
  struct kk_function_s _base;
  kk_ssize_t i_11238;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11110_fun2134(kk_function_t _fself, kk_function_t _b_x151, kk_box_t _b_x152, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11110_fun2134(kk_ssize_t i_11238, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11110_fun2134__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11110_fun2134__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11110_fun2134, kk_context());
  _self->i_11238 = i_11238;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11110_fun2134(kk_function_t _fself, kk_function_t _b_x151, kk_box_t _b_x152, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11110_fun2134__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11110_fun2134__t*, _fself, _ctx);
  kk_ssize_t i_11238 = _self->i_11238; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11238, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11238, _b_x151, _b_x152, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11110_fun2136__t {
  struct kk_function_s _base;
  kk_integer_t tzhour;
  kk_char_t sign;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11110_fun2136(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11110_fun2136(kk_integer_t tzhour, kk_char_t sign, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11110_fun2136__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11110_fun2136__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11110_fun2136, kk_context());
  _self->tzhour = tzhour;
  _self->sign = sign;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11110_fun2136(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11110_fun2136__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11110_fun2136__t*, _fself, _ctx);
  kk_integer_t tzhour = _self->tzhour; /* int */
  kk_char_t sign = _self->sign; /* char */
  kk_drop_match(_self, {kk_integer_dup(tzhour, _ctx);kk_skip_dup(sign, _ctx);}, {}, _ctx)
  kk_char_t wild___3_164 = kk_char_unbox(_b_x161, KK_OWNED, _ctx); /*char*/;
  kk_std_time_calendar__timezone _x_x2137 = kk_std_time_parse__mlift_ptime_11108(sign, tzhour, wild___3_164, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2137, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11110(kk_char_t sign, kk_integer_t tzhour, kk_context_t* _ctx) { /* (sign : char, tzhour : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
  kk_ssize_t i_11238 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11238,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11242 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_0_11240;
  kk_box_t _x_x2127;
  {
    struct kk_std_core_hnd_Ev* _con_x2128 = kk_std_core_hnd__as_Ev(ev_11242, _ctx);
    kk_box_t _box_x137 = _con_x2128->hnd;
    int32_t m = _con_x2128->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x137, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1959;
    kk_std_core_hnd__clause0 _brw_x1960 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1959 = _brw_x1960; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x140 = _match_x1959.clause;
      _x_x2127 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x140, (_fun_unbox_x140, m, ev_11242, _ctx), _ctx); /*10005*/
    }
  }
  x_0_11240 = kk_bool_unbox(_x_x2127); /*bool*/
  kk_char_t y;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2129 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11110_fun2130(_ctx), _ctx); /*10001*/
    y = kk_char_unbox(_x_x2129, KK_OWNED, _ctx); /*char*/
  }
  else {
    if (x_0_11240) {
      y = kk_std_text_parse_char(':', _ctx); /*char*/
    }
    else {
      y = ':'; /*char*/
    }
  }
  kk_evv_set(w,kk_context());
  kk_char_t x_11236;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2133 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11110_fun2134(i_11238, _ctx), _ctx); /*10002*/
    x_11236 = kk_char_unbox(_x_x2133, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_11236 = y; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2135 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11110_fun2136(tzhour, sign, _ctx), _ctx); /*10001*/
    return kk_std_time_calendar__timezone_unbox(_x_x2135, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11108(sign, tzhour, x_11236, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11111_fun2139__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11111_fun2139(kk_function_t _fself, kk_box_t _b_x166, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11111_fun2139(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11111_fun2139, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11111_fun2139(kk_function_t _fself, kk_box_t _b_x166, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2140;
  kk_std_core_types__list _x_x2141 = kk_std_core_types__list_unbox(_b_x166, KK_OWNED, _ctx); /*list<int>*/
  _x_x2140 = kk_std_time_parse__mlift_ptime_11109(_x_x2141, _ctx); /*int*/
  return kk_integer_box(_x_x2140, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11111_fun2143__t {
  struct kk_function_s _base;
  kk_ssize_t i_11246;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11111_fun2143(kk_function_t _fself, kk_function_t _b_x173, kk_box_t _b_x174, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11111_fun2143(kk_ssize_t i_11246, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11111_fun2143__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11111_fun2143__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11111_fun2143, kk_context());
  _self->i_11246 = i_11246;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11111_fun2143(kk_function_t _fself, kk_function_t _b_x173, kk_box_t _b_x174, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11111_fun2143__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11111_fun2143__t*, _fself, _ctx);
  kk_ssize_t i_11246 = _self->i_11246; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11246, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11246, _b_x173, _b_x174, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11111_fun2145__t {
  struct kk_function_s _base;
  kk_char_t sign;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11111_fun2145(kk_function_t _fself, kk_box_t _b_x183, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11111_fun2145(kk_char_t sign, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11111_fun2145__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11111_fun2145__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11111_fun2145, kk_context());
  _self->sign = sign;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11111_fun2145(kk_function_t _fself, kk_box_t _b_x183, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11111_fun2145__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11111_fun2145__t*, _fself, _ctx);
  kk_char_t sign = _self->sign; /* char */
  kk_drop_match(_self, {kk_skip_dup(sign, _ctx);}, {}, _ctx)
  kk_integer_t tzhour_186 = kk_integer_unbox(_b_x183, _ctx); /*int*/;
  kk_std_time_calendar__timezone _x_x2146 = kk_std_time_parse__mlift_ptime_11110(sign, tzhour_186, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2146, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11111(kk_char_t sign, kk_context_t* _ctx) { /* (sign : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
  kk_ssize_t i_11246 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11246,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_1_11249 = kk_std_time_parse__lift_ptime_10626(kk_integer_from_small(2), _ctx); /*list<int>*/;
  kk_integer_t y;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_11249, _ctx);
    kk_box_t _x_x2138 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11111_fun2139(_ctx), _ctx); /*10001*/
    y = kk_integer_unbox(_x_x2138, _ctx); /*int*/
  }
  else {
    y = kk_std_time_parse__lift_ptime_10624(x_1_11249, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w,kk_context());
  kk_integer_t x_11244;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y, _ctx);
    kk_box_t _x_x2142 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11111_fun2143(i_11246, _ctx), _ctx); /*10002*/
    x_11244 = kk_integer_unbox(_x_x2142, _ctx); /*int*/
  }
  else {
    x_11244 = y; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11244, _ctx);
    kk_box_t _x_x2144 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11111_fun2145(sign, _ctx), _ctx); /*10001*/
    return kk_std_time_calendar__timezone_unbox(_x_x2144, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11110(sign, x_11244, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11113_fun2148__t {
  struct kk_function_s _base;
  kk_ssize_t i_11253;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11113_fun2148(kk_function_t _fself, kk_function_t _b_x192, kk_box_t _b_x193, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11113_fun2148(kk_ssize_t i_11253, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11113_fun2148__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11113_fun2148__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11113_fun2148, kk_context());
  _self->i_11253 = i_11253;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11113_fun2148(kk_function_t _fself, kk_function_t _b_x192, kk_box_t _b_x193, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11113_fun2148__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11113_fun2148__t*, _fself, _ctx);
  kk_ssize_t i_11253 = _self->i_11253; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11253, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11253, _b_x192, _b_x193, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11113_fun2150__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11113_fun2150(kk_function_t _fself, kk_box_t _b_x202, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11113_fun2150(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11113_fun2150, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11113_fun2150(kk_function_t _fself, kk_box_t _b_x202, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x2151;
  kk_char_t _x_x2152 = kk_char_unbox(_b_x202, KK_OWNED, _ctx); /*char*/
  _x_x2151 = kk_std_time_parse__mlift_ptime_11112(_x_x2152, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2151, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11113(bool _y_x10770, kk_context_t* _ctx) { /* (bool) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
  kk_char_t x_11251;
  if (_y_x10770) {
    kk_ssize_t i_11253 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i_11253,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
    kk_char_t y = kk_std_text_parse_char('Z', _ctx); /*char*/;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2147 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11113_fun2148(i_11253, _ctx), _ctx); /*10002*/
      x_11251 = kk_char_unbox(_x_x2147, KK_OWNED, _ctx); /*char*/
    }
    else {
      x_11251 = y; /*char*/
    }
  }
  else {
    x_11251 = 'Z'; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2149 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11113_fun2150(_ctx), _ctx); /*10001*/
    return kk_std_time_calendar__timezone_unbox(_x_x2149, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11114_fun2159__t {
  struct kk_function_s _base;
  kk_ssize_t i_11256;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11114_fun2159(kk_function_t _fself, kk_function_t _b_x216, kk_box_t _b_x217, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11114_fun2159(kk_ssize_t i_11256, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11114_fun2159__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11114_fun2159__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11114_fun2159, kk_context());
  _self->i_11256 = i_11256;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11114_fun2160__t {
  struct kk_function_s _base;
  kk_function_t _b_x216;
};
static kk_std_time_time__time kk_std_time_parse__mlift_ptime_11114_fun2160(kk_function_t _fself, kk_box_t _b_x218, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11114_fun2160(kk_function_t _b_x216, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11114_fun2160__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11114_fun2160__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11114_fun2160, kk_context());
  _self->_b_x216 = _b_x216;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_time__time kk_std_time_parse__mlift_ptime_11114_fun2160(kk_function_t _fself, kk_box_t _b_x218, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11114_fun2160__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11114_fun2160__t*, _fself, _ctx);
  kk_function_t _b_x216 = _self->_b_x216; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x216, _ctx);}, {}, _ctx)
  kk_box_t _x_x2161 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x216, (_b_x216, _b_x218, _ctx), _ctx); /*10000*/
  return kk_std_time_time__time_unbox(_x_x2161, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11114_fun2162__t {
  struct kk_function_s _base;
  kk_function_t _b_x212_221;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11114_fun2162(kk_function_t _fself, kk_box_t _b_x214, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11114_fun2162(kk_function_t _b_x212_221, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11114_fun2162__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11114_fun2162__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11114_fun2162, kk_context());
  _self->_b_x212_221 = _b_x212_221;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11114_fun2162(kk_function_t _fself, kk_box_t _b_x214, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11114_fun2162__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11114_fun2162__t*, _fself, _ctx);
  kk_function_t _b_x212_221 = _self->_b_x212_221; /* (10009) -> <std/time/utc/utc,std/text/parse/parse> std/time/time/time */
  kk_drop_match(_self, {kk_function_dup(_b_x212_221, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2163 = kk_function_call(kk_std_time_time__time, (kk_function_t, kk_box_t, kk_context_t*), _b_x212_221, (_b_x212_221, _b_x214, _ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2163, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_11114_fun2159(kk_function_t _fself, kk_function_t _b_x216, kk_box_t _b_x217, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11114_fun2159__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11114_fun2159__t*, _fself, _ctx);
  kk_ssize_t i_11256 = _self->i_11256; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11256, _ctx);}, {}, _ctx)
  kk_function_t cont_223 = kk_std_time_parse__new_mlift_ptime_11114_fun2160(_b_x216, _ctx); /*(10009) -> <std/time/utc/utc,std/text/parse/parse> std/time/time/time*/;
  kk_box_t res_224 = _b_x217; /*10009*/;
  kk_ssize_t _b_x211_220 = i_11256; /*hnd/ev-index*/;
  kk_function_t _b_x212_221 = cont_223; /*(10009) -> <std/time/utc/utc,std/text/parse/parse> std/time/time/time*/;
  kk_box_t _b_x213_222 = res_224; /*10009*/;
  return kk_std_core_hnd_open_at1(_b_x211_220, kk_std_time_parse__new_mlift_ptime_11114_fun2162(_b_x212_221, _ctx), _b_x213_222, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11114(kk_integer_t _c_x10740, kk_std_num_ddouble__ddouble _c_x10756, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_std_time_calendar__timezone _c_x10776, kk_context_t* _ctx) { /* (int, std/num/ddouble/ddouble, cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, std/time/calendar/timezone) -> std/time/time/time */ 
  kk_ssize_t i_11256 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11256,kk_context()); /*hnd/evv<<std/time/utc/utc,std/text/parse/parse>>*/;
  kk_std_time_time__time y;
  kk_std_core_types__optional _x_x2153;
  kk_box_t _x_x2154;
  kk_std_time_date__clock _x_x2155 = kk_std_time_date__new_Clock(kk_reuse_null, 0, hour, _c_x10740, _c_x10756, _ctx); /*std/time/date/clock*/
  _x_x2154 = kk_std_time_date__clock_box(_x_x2155, _ctx); /*10003*/
  _x_x2153 = kk_std_core_types__new_Optional(_x_x2154, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x2156 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_c_x10776, _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x2157 = kk_std_core_types__new_Optional(kk_std_time_calendar__calendar_box(cal, _ctx), _ctx); /*? 10003*/
  y = kk_std_time_time_date_fs_time(date, _x_x2153, _x_x2156, _x_x2157, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(y, (KK_I32(9)), _ctx);
    kk_box_t _x_x2158 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11114_fun2159(i_11256, _ctx), _ctx); /*10002*/
    return kk_std_time_time__time_unbox(_x_x2158, KK_OWNED, _ctx);
  }
  {
    return y;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11115_fun2165__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11115_fun2165(kk_function_t _fself, kk_box_t _b_x228, kk_box_t _b_x229, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11115_fun2165(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11115_fun2165, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11115_fun2165(kk_function_t _fself, kk_box_t _b_x228, kk_box_t _b_x229, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2166;
  kk_std_num_ddouble__ddouble _x_x2167 = kk_std_num_ddouble__ddouble_unbox(_b_x228, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x2168 = kk_std_num_ddouble__ddouble_unbox(_b_x229, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x2166 = kk_std_num_ddouble__lp__plus__rp_(_x_x2167, _x_x2168, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2166, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_11115(kk_integer_t s, kk_std_num_ddouble__ddouble _c_x10755, kk_context_t* _ctx) { /* (s : int, std/num/ddouble/ddouble) -> std/num/ddouble/ddouble */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_num_ddouble__ddouble x = kk_std_num_ddouble_ddouble_int_exp(s, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_box_t _x_x2164 = kk_std_core_hnd__open_none2(kk_std_time_parse__new_mlift_ptime_11115_fun2165(_ctx), kk_std_num_ddouble__ddouble_box(x, _ctx), kk_std_num_ddouble__ddouble_box(_c_x10755, _ctx), _ctx); /*10002*/
  return kk_std_num_ddouble__ddouble_unbox(_x_x2164, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11116_fun2170__t {
  struct kk_function_s _base;
  kk_ssize_t i_11260;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11116_fun2170(kk_function_t _fself, kk_function_t _b_x238, kk_box_t _b_x239, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11116_fun2170(kk_ssize_t i_11260, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11116_fun2170__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11116_fun2170__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11116_fun2170, kk_context());
  _self->i_11260 = i_11260;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11116_fun2171__t {
  struct kk_function_s _base;
  kk_function_t _b_x238;
};
static kk_string_t kk_std_time_parse__mlift_ptime_11116_fun2171(kk_function_t _fself, kk_box_t _b_x240, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11116_fun2171(kk_function_t _b_x238, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11116_fun2171__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11116_fun2171__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11116_fun2171, kk_context());
  _self->_b_x238 = _b_x238;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_parse__mlift_ptime_11116_fun2171(kk_function_t _fself, kk_box_t _b_x240, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11116_fun2171__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11116_fun2171__t*, _fself, _ctx);
  kk_function_t _b_x238 = _self->_b_x238; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x238, _ctx);}, {}, _ctx)
  kk_box_t _x_x2172 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x238, (_b_x238, _b_x240, _ctx), _ctx); /*10000*/
  return kk_string_unbox(_x_x2172);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11116_fun2173__t {
  struct kk_function_s _base;
  kk_function_t _b_x234_243;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11116_fun2173(kk_function_t _fself, kk_box_t _b_x236, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11116_fun2173(kk_function_t _b_x234_243, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11116_fun2173__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11116_fun2173__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11116_fun2173, kk_context());
  _self->_b_x234_243 = _b_x234_243;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11116_fun2173(kk_function_t _fself, kk_box_t _b_x236, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11116_fun2173__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11116_fun2173__t*, _fself, _ctx);
  kk_function_t _b_x234_243 = _self->_b_x234_243; /* (10009) -> <std/text/parse/parse,std/time/utc/utc> string */
  kk_drop_match(_self, {kk_function_dup(_b_x234_243, _ctx);}, {}, _ctx)
  kk_string_t _x_x2174 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x234_243, (_b_x234_243, _b_x236, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x2174);
}
static kk_box_t kk_std_time_parse__mlift_ptime_11116_fun2170(kk_function_t _fself, kk_function_t _b_x238, kk_box_t _b_x239, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11116_fun2170__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11116_fun2170__t*, _fself, _ctx);
  kk_ssize_t i_11260 = _self->i_11260; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11260, _ctx);}, {}, _ctx)
  kk_function_t cont_245 = kk_std_time_parse__new_mlift_ptime_11116_fun2171(_b_x238, _ctx); /*(10009) -> <std/text/parse/parse,std/time/utc/utc> string*/;
  kk_box_t res_246 = _b_x239; /*10009*/;
  kk_ssize_t _b_x233_242 = i_11260; /*hnd/ev-index*/;
  kk_function_t _b_x234_243 = cont_245; /*(10009) -> <std/text/parse/parse,std/time/utc/utc> string*/;
  kk_box_t _b_x235_244 = res_246; /*10009*/;
  return kk_std_core_hnd_open_at1(_b_x233_242, kk_std_time_parse__new_mlift_ptime_11116_fun2173(_b_x234_243, _ctx), _b_x235_244, _ctx);
}

kk_string_t kk_std_time_parse__mlift_ptime_11116(kk_char_t wild___2, kk_context_t* _ctx) { /* (wild_@2 : char) -> <std/text/parse/parse,std/time/utc/utc> string */ 
  kk_ssize_t i_11260 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11260,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_string_t y = kk_std_text_parse_digits(_ctx); /*string*/;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_string_drop(y, _ctx);
    kk_box_t _x_x2169 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11116_fun2170(i_11260, _ctx), _ctx); /*10002*/
    return kk_string_unbox(_x_x2169);
  }
  {
    return y;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11117_fun2181__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11117_fun2181(kk_function_t _fself, kk_box_t _b_x249, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11117_fun2181(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11117_fun2181, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11117_fun2181(kk_function_t _fself, kk_box_t _b_x249, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2182;
  kk_string_t _x_x2183 = kk_string_unbox(_b_x249); /*string*/
  _x_x2182 = kk_std_num_ddouble_parse_ddouble(_x_x2183, _ctx); /*maybe<std/num/ddouble/ddouble>*/
  return kk_std_core_types__maybe_box(_x_x2182, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11117_fun2185__t {
  struct kk_function_s _base;
  kk_integer_t s;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11117_fun2185(kk_function_t _fself, kk_box_t _b_x254, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11117_fun2185(kk_integer_t s, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11117_fun2185__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11117_fun2185__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11117_fun2185, kk_context());
  _self->s = s;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11117_fun2185(kk_function_t _fself, kk_box_t _b_x254, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11117_fun2185__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11117_fun2185__t*, _fself, _ctx);
  kk_integer_t s = _self->s; /* int */
  kk_drop_match(_self, {kk_integer_dup(s, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _c_x10755_256 = kk_std_num_ddouble__ddouble_unbox(_b_x254, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x_x2186 = kk_std_time_parse__mlift_ptime_11115(s, _c_x10755_256, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2186, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_11117(kk_integer_t s, kk_string_t _c_x10754, kk_context_t* _ctx) { /* (s : int, string) -> std/num/ddouble/ddouble */ 
  kk_std_num_ddouble__ddouble x_11262;
  bool _match_x1948;
  kk_string_t _x_x2175 = kk_string_dup(_c_x10754, _ctx); /*string*/
  kk_string_t _x_x2176 = kk_string_empty(); /*string*/
  _match_x1948 = kk_string_is_eq(_x_x2175,_x_x2176,kk_context()); /*bool*/
  if (_match_x1948) {
    kk_string_drop(_c_x10754, _ctx);
    x_11262 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_string_t _x_x1_5_11047;
    kk_string_t _x_x2178;
    kk_define_string_literal(, _s_x2179, 2, "0.", _ctx)
    _x_x2178 = kk_string_dup(_s_x2179, _ctx); /*string*/
    _x_x1_5_11047 = kk_std_core_types__lp__plus__plus__rp_(_x_x2178, _c_x10754, _ctx); /*string*/
    kk_std_core_types__maybe _x_x1_4_11045;
    kk_box_t _x_x2180 = kk_std_core_hnd__open_none1(kk_std_time_parse__new_mlift_ptime_11117_fun2181(_ctx), kk_string_box(_x_x1_5_11047), _ctx); /*10001*/
    _x_x1_4_11045 = kk_std_core_types__maybe_unbox(_x_x2180, KK_OWNED, _ctx); /*maybe<std/num/ddouble/ddouble>*/
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_std_core_types__is_Nothing(_x_x1_4_11045, _ctx)) {
      x_11262 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_box_t _box_x252 = _x_x1_4_11045._cons.Just.value;
      kk_std_num_ddouble__ddouble x_5 = kk_std_num_ddouble__ddouble_unbox(_box_x252, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_drop(_x_x1_4_11045, _ctx);
      x_11262 = x_5; /*std/num/ddouble/ddouble*/
    }
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2184 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11117_fun2185(s, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x2184, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11115(s, x_11262, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11118_fun2190__t {
  struct kk_function_s _base;
  kk_ssize_t i_11271;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11118_fun2190(kk_function_t _fself, kk_function_t _b_x262, kk_box_t _b_x263, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11118_fun2190(kk_ssize_t i_11271, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11118_fun2190__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11118_fun2190__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11118_fun2190, kk_context());
  _self->i_11271 = i_11271;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11118_fun2190(kk_function_t _fself, kk_function_t _b_x262, kk_box_t _b_x263, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11118_fun2190__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11118_fun2190__t*, _fself, _ctx);
  kk_ssize_t i_11271 = _self->i_11271; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11271, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11271, _b_x262, _b_x263, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11118_fun2192__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11118_fun2192(kk_function_t _fself, kk_box_t _b_x272, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11118_fun2192(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11118_fun2192, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11118_fun2192(kk_function_t _fself, kk_box_t _b_x272, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2193;
  kk_char_t _x_x2194 = kk_char_unbox(_b_x272, KK_OWNED, _ctx); /*char*/
  _x_x2193 = kk_std_time_parse__mlift_ptime_11116(_x_x2194, _ctx); /*string*/
  return kk_string_box(_x_x2193);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11118_fun2197__t {
  struct kk_function_s _base;
  kk_integer_t s;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11118_fun2197(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11118_fun2197(kk_integer_t s, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11118_fun2197__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11118_fun2197__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11118_fun2197, kk_context());
  _self->s = s;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11118_fun2197(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11118_fun2197__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11118_fun2197__t*, _fself, _ctx);
  kk_integer_t s = _self->s; /* int */
  kk_drop_match(_self, {kk_integer_dup(s, _ctx);}, {}, _ctx)
  kk_string_t _c_x10754_278 = kk_string_unbox(_b_x276); /*string*/;
  kk_std_num_ddouble__ddouble _x_x2198 = kk_std_time_parse__mlift_ptime_11117(s, _c_x10754_278, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2198, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_11118(kk_integer_t s, bool _y_x10751, kk_context_t* _ctx) { /* (s : int, bool) -> <std/text/parse/parse,std/time/utc/utc> std/num/ddouble/ddouble */ 
  kk_string_t x_11267;
  if (_y_x10751) {
    kk_ssize_t i_11271 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i_11271,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
    kk_char_t y;
    kk_string_t _x_x2187;
    kk_define_string_literal(, _s_x2188, 2, ".,", _ctx)
    _x_x2187 = kk_string_dup(_s_x2188, _ctx); /*string*/
    y = kk_std_text_parse_one_of(_x_x2187, _ctx); /*char*/
    kk_evv_set(w,kk_context());
    kk_char_t x_0_11269;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2189 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11118_fun2190(i_11271, _ctx), _ctx); /*10002*/
      x_0_11269 = kk_char_unbox(_x_x2189, KK_OWNED, _ctx); /*char*/
    }
    else {
      x_0_11269 = y; /*char*/
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2191 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11118_fun2192(_ctx), _ctx); /*10001*/
      x_11267 = kk_string_unbox(_x_x2191); /*string*/
    }
    else {
      x_11267 = kk_std_time_parse__mlift_ptime_11116(x_0_11269, _ctx); /*string*/
    }
  }
  else {
    x_11267 = kk_string_empty(); /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_11267, _ctx);
    kk_box_t _x_x2196 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11118_fun2197(s, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x2196, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11117(s, x_11267, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11120_fun2202__t {
  struct kk_function_s _base;
  kk_ssize_t i_11276;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11120_fun2202(kk_function_t _fself, kk_function_t _b_x290, kk_box_t _b_x291, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11120_fun2202(kk_ssize_t i_11276, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11120_fun2202__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11120_fun2202__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11120_fun2202, kk_context());
  _self->i_11276 = i_11276;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11120_fun2202(kk_function_t _fself, kk_function_t _b_x290, kk_box_t _b_x291, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11120_fun2202__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11120_fun2202__t*, _fself, _ctx);
  kk_ssize_t i_11276 = _self->i_11276; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11276, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11276, _b_x290, _b_x291, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11120_fun2204__t {
  struct kk_function_s _base;
  kk_integer_t s;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11120_fun2204(kk_function_t _fself, kk_box_t _b_x300, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11120_fun2204(kk_integer_t s, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11120_fun2204__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11120_fun2204__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11120_fun2204, kk_context());
  _self->s = s;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11120_fun2204(kk_function_t _fself, kk_box_t _b_x300, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11120_fun2204__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11120_fun2204__t*, _fself, _ctx);
  kk_integer_t s = _self->s; /* int */
  kk_drop_match(_self, {kk_integer_dup(s, _ctx);}, {}, _ctx)
  bool _y_x10751_303 = kk_bool_unbox(_b_x300); /*bool*/;
  kk_std_num_ddouble__ddouble _x_x2205 = kk_std_time_parse__mlift_ptime_11118(s, _y_x10751_303, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2205, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_11120(kk_integer_t s, kk_context_t* _ctx) { /* (s : int) -> <std/text/parse/parse,std/time/utc/utc> std/num/ddouble/ddouble */ 
  kk_ssize_t i_11276 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11276,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11278 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool y;
  kk_box_t _x_x2199;
  {
    struct kk_std_core_hnd_Ev* _con_x2200 = kk_std_core_hnd__as_Ev(ev_11278, _ctx);
    kk_box_t _box_x279 = _con_x2200->hnd;
    int32_t m = _con_x2200->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x279, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1942;
    kk_std_core_hnd__clause0 _brw_x1943 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1942 = _brw_x1943; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x282 = _match_x1942.clause;
      _x_x2199 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x282, (_fun_unbox_x282, m, ev_11278, _ctx), _ctx); /*10005*/
    }
  }
  y = kk_bool_unbox(_x_x2199); /*bool*/
  kk_evv_set(w,kk_context());
  bool x_11274;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2201 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11120_fun2202(i_11276, _ctx), _ctx); /*10002*/
    x_11274 = kk_bool_unbox(_x_x2201); /*bool*/
  }
  else {
    x_11274 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2203 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11120_fun2204(s, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x2203, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11118(s, x_11274, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11121_fun2206__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2206(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11121_fun2206(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11121_fun2206, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11121_fun2210__t {
  struct kk_function_s _base;
  kk_ssize_t i_11282;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2210(kk_function_t _fself, kk_function_t _b_x309, kk_box_t _b_x310, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11121_fun2210(kk_ssize_t i_11282, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11121_fun2210__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11121_fun2210__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11121_fun2210, kk_context());
  _self->i_11282 = i_11282;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2210(kk_function_t _fself, kk_function_t _b_x309, kk_box_t _b_x310, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11121_fun2210__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11121_fun2210__t*, _fself, _ctx);
  kk_ssize_t i_11282 = _self->i_11282; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11282, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11282, _b_x309, _b_x310, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11121_fun2213__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2213(kk_function_t _fself, kk_box_t _b_x319, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11121_fun2213(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11121_fun2213, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2213(kk_function_t _fself, kk_box_t _b_x319, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x2214;
  kk_char_t _x_x2215 = kk_char_unbox(_b_x319, KK_OWNED, _ctx); /*char*/
  _x_x2214 = kk_std_time_parse__mlift_ptime_11111(_x_x2215, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2214, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2206(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t i_11282 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11282,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_char_t y;
  kk_string_t _x_x2207;
  kk_define_string_literal(, _s_x2208, 2, "+-", _ctx)
  _x_x2207 = kk_string_dup(_s_x2208, _ctx); /*string*/
  y = kk_std_text_parse_one_of(_x_x2207, _ctx); /*char*/
  kk_evv_set(w,kk_context());
  kk_char_t x_11280;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2209 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11121_fun2210(i_11282, _ctx), _ctx); /*10002*/
    x_11280 = kk_char_unbox(_x_x2209, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_11280 = y; /*char*/
  }
  kk_std_time_calendar__timezone _x_x2211;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2212 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11121_fun2213(_ctx), _ctx); /*10001*/
    _x_x2211 = kk_std_time_calendar__timezone_unbox(_x_x2212, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  }
  else {
    _x_x2211 = kk_std_time_parse__mlift_ptime_11111(x_11280, _ctx); /*std/time/calendar/timezone*/
  }
  return kk_std_time_calendar__timezone_box(_x_x2211, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11121_fun2217__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2217(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11121_fun2217(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11121_fun2217, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11121_fun2221__t {
  struct kk_function_s _base;
  kk_ssize_t i_0_11287;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2221(kk_function_t _fself, kk_function_t _b_x331, kk_box_t _b_x332, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11121_fun2221(kk_ssize_t i_0_11287, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11121_fun2221__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11121_fun2221__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11121_fun2221, kk_context());
  _self->i_0_11287 = i_0_11287;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2221(kk_function_t _fself, kk_function_t _b_x331, kk_box_t _b_x332, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11121_fun2221__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11121_fun2221__t*, _fself, _ctx);
  kk_ssize_t i_0_11287 = _self->i_0_11287; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_0_11287, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_0_11287, _b_x331, _b_x332, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11121_fun2224__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2224(kk_function_t _fself, kk_box_t _b_x341, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11121_fun2224(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11121_fun2224, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2224(kk_function_t _fself, kk_box_t _b_x341, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x2225;
  bool _x_x2226 = kk_bool_unbox(_b_x341); /*bool*/
  _x_x2225 = kk_std_time_parse__mlift_ptime_11113(_x_x2226, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2225, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2217(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t i_0_11287 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_0 = kk_evv_swap_create1(i_0_11287,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11289 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool y_0;
  kk_box_t _x_x2218;
  {
    struct kk_std_core_hnd_Ev* _con_x2219 = kk_std_core_hnd__as_Ev(ev_11289, _ctx);
    kk_box_t _box_x320 = _con_x2219->hnd;
    int32_t m = _con_x2219->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x320, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1936;
    kk_std_core_hnd__clause0 _brw_x1937 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1936 = _brw_x1937; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x323 = _match_x1936.clause;
      _x_x2218 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x323, (_fun_unbox_x323, m, ev_11289, _ctx), _ctx); /*10005*/
    }
  }
  y_0 = kk_bool_unbox(_x_x2218); /*bool*/
  kk_evv_set(w_0,kk_context());
  bool x_1_11285;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2220 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11121_fun2221(i_0_11287, _ctx), _ctx); /*10002*/
    x_1_11285 = kk_bool_unbox(_x_x2220); /*bool*/
  }
  else {
    x_1_11285 = y_0; /*bool*/
  }
  kk_std_time_calendar__timezone _x_x2222;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2223 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11121_fun2224(_ctx), _ctx); /*10001*/
    _x_x2222 = kk_std_time_calendar__timezone_unbox(_x_x2223, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  }
  else {
    _x_x2222 = kk_std_time_parse__mlift_ptime_11113(x_1_11285, _ctx); /*std/time/calendar/timezone*/
  }
  return kk_std_time_calendar__timezone_box(_x_x2222, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11121_fun2233__t {
  struct kk_function_s _base;
  kk_ssize_t i_1_11293;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2233(kk_function_t _fself, kk_function_t _b_x369, kk_box_t _b_x370, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11121_fun2233(kk_ssize_t i_1_11293, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11121_fun2233__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11121_fun2233__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11121_fun2233, kk_context());
  _self->i_1_11293 = i_1_11293;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2233(kk_function_t _fself, kk_function_t _b_x369, kk_box_t _b_x370, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11121_fun2233__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11121_fun2233__t*, _fself, _ctx);
  kk_ssize_t i_1_11293 = _self->i_1_11293; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_1_11293, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1_11293, _b_x369, _b_x370, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11121_fun2236__t {
  struct kk_function_s _base;
  kk_integer_t _c_x10740;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
  kk_std_num_ddouble__ddouble _c_x10756;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2236(kk_function_t _fself, kk_box_t _b_x381, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11121_fun2236(kk_integer_t _c_x10740, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_std_num_ddouble__ddouble _c_x10756, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11121_fun2236__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11121_fun2236__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11121_fun2236, kk_context());
  _self->_c_x10740 = _c_x10740;
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  _self->_c_x10756 = _c_x10756;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11121_fun2236(kk_function_t _fself, kk_box_t _b_x381, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11121_fun2236__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11121_fun2236__t*, _fself, _ctx);
  kk_integer_t _c_x10740 = _self->_c_x10740; /* int */
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_std_num_ddouble__ddouble _c_x10756 = _self->_c_x10756; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_integer_dup(_c_x10740, _ctx);kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);kk_std_num_ddouble__ddouble_dup(_c_x10756, _ctx);}, {}, _ctx)
  kk_std_time_calendar__timezone _c_x10776_384 = kk_std_time_calendar__timezone_unbox(_b_x381, KK_OWNED, _ctx); /*std/time/calendar/timezone*/;
  kk_std_time_time__time _x_x2237 = kk_std_time_parse__mlift_ptime_11114(_c_x10740, _c_x10756, cal, date, hour, _c_x10776_384, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2237, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11121(kk_integer_t _c_x10740, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_std_num_ddouble__ddouble _c_x10756, kk_context_t* _ctx) { /* (int, cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, std/num/ddouble/ddouble) -> std/time/time/time */ 
  kk_std_core_types__list ps_10020;
  kk_std_core_types__list _x_x2216 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse__new_mlift_ptime_11121_fun2217(_ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  ps_10020 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse__new_mlift_ptime_11121_fun2206(_ctx), _ctx), _x_x2216, _ctx); /*list<std/text/parse/parser<std/time/utc/utc,std/time/calendar/timezone>>*/
  kk_std_time_calendar__timezone x_2_11291;
  if (kk_std_core_types__is_Nil(ps_10020, _ctx)) {
    kk_ssize_t i_1_11293 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_evv_t w_1 = kk_evv_swap_create1(i_1_11293,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
    kk_std_core_hnd__ev ev_0_11296 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_std_time_calendar__timezone y_1;
    kk_box_t _x_x2227;
    {
      struct kk_std_core_hnd_Ev* _con_x2228 = kk_std_core_hnd__as_Ev(ev_0_11296, _ctx);
      kk_box_t _box_x356 = _con_x2228->hnd;
      int32_t m_0 = _con_x2228->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x356, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      kk_std_core_hnd__clause1 _match_x1932;
      kk_std_core_hnd__clause1 _brw_x1933 = kk_std_text_parse_fail_fs__select(h_0, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
      _match_x1932 = _brw_x1933; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x360 = _match_x1932.clause;
        kk_box_t _x_x2229;
        kk_string_t _x_x2230;
        kk_define_string_literal(, _s_x2231, 23, "no further alternatives", _ctx)
        _x_x2230 = kk_string_dup(_s_x2231, _ctx); /*string*/
        _x_x2229 = kk_string_box(_x_x2230); /*10009*/
        _x_x2227 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x360, (_fun_unbox_x360, m_0, ev_0_11296, _x_x2229, _ctx), _ctx); /*10010*/
      }
    }
    y_1 = kk_std_time_calendar__timezone_unbox(_x_x2227, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
    kk_evv_set(w_1,kk_context());
    if (kk_yielding(kk_context())) {
      kk_datatype_ptr_dropn(y_1, (KK_I32(3)), _ctx);
      kk_box_t _x_x2232 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11121_fun2233(i_1_11293, _ctx), _ctx); /*10002*/
      x_2_11291 = kk_std_time_calendar__timezone_unbox(_x_x2232, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
    }
    else {
      x_2_11291 = y_1; /*std/time/calendar/timezone*/
    }
  }
  else {
    kk_box_t _x_x2234 = kk_std_text_parse__unroll_choose_10000(ps_10020, _ctx); /*10000*/
    x_2_11291 = kk_std_time_calendar__timezone_unbox(_x_x2234, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  }
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_2_11291, (KK_I32(3)), _ctx);
    kk_box_t _x_x2235 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11121_fun2236(_c_x10740, cal, date, hour, _c_x10756, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2235, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11114(_c_x10740, _c_x10756, cal, date, hour, x_2_11291, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11122_fun2239__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11122_fun2239(kk_function_t _fself, kk_box_t _b_x386, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11122_fun2239(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11122_fun2239, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11122_fun2239(kk_function_t _fself, kk_box_t _b_x386, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2240;
  kk_std_core_types__list _x_x2241 = kk_std_core_types__list_unbox(_b_x386, KK_OWNED, _ctx); /*list<int>*/
  _x_x2240 = kk_std_time_parse__mlift_ptime_11119(_x_x2241, _ctx); /*int*/
  return kk_integer_box(_x_x2240, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11122_fun2243__t {
  struct kk_function_s _base;
  kk_ssize_t i_11303;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11122_fun2243(kk_function_t _fself, kk_function_t _b_x393, kk_box_t _b_x394, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11122_fun2243(kk_ssize_t i_11303, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11122_fun2243__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11122_fun2243__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11122_fun2243, kk_context());
  _self->i_11303 = i_11303;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11122_fun2243(kk_function_t _fself, kk_function_t _b_x393, kk_box_t _b_x394, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11122_fun2243__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11122_fun2243__t*, _fself, _ctx);
  kk_ssize_t i_11303 = _self->i_11303; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11303, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11303, _b_x393, _b_x394, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11122_fun2245__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11122_fun2245(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11122_fun2245(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11122_fun2245, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11122_fun2245(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2246;
  kk_integer_t _x_x2247 = kk_integer_unbox(_b_x403, _ctx); /*int*/
  _x_x2246 = kk_std_time_parse__mlift_ptime_11120(_x_x2247, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2246, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11122_fun2249__t {
  struct kk_function_s _base;
  kk_integer_t _c_x10740;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11122_fun2249(kk_function_t _fself, kk_box_t _b_x407, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11122_fun2249(kk_integer_t _c_x10740, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11122_fun2249__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11122_fun2249__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11122_fun2249, kk_context());
  _self->_c_x10740 = _c_x10740;
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11122_fun2249(kk_function_t _fself, kk_box_t _b_x407, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11122_fun2249__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11122_fun2249__t*, _fself, _ctx);
  kk_integer_t _c_x10740 = _self->_c_x10740; /* int */
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_drop_match(_self, {kk_integer_dup(_c_x10740, _ctx);kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _c_x10756_409 = kk_std_num_ddouble__ddouble_unbox(_b_x407, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_time__time _x_x2250 = kk_std_time_parse__mlift_ptime_11121(_c_x10740, cal, date, hour, _c_x10756_409, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2250, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11122(kk_integer_t _c_x10740, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, bool _y_x10746, kk_context_t* _ctx) { /* (int, cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, bool) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_std_num_ddouble__ddouble x_11299;
  if (_y_x10746) {
    kk_ssize_t i_11303 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i_11303,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
    kk_std_core_types__list x_2_11306 = kk_std_time_parse__lift_ptime_10622(kk_integer_from_small(2), _ctx); /*list<int>*/;
    kk_integer_t y;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_2_11306, _ctx);
      kk_box_t _x_x2238 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11122_fun2239(_ctx), _ctx); /*10001*/
      y = kk_integer_unbox(_x_x2238, _ctx); /*int*/
    }
    else {
      y = kk_std_time_parse__lift_ptime_10620(x_2_11306, kk_integer_from_small(0), _ctx); /*int*/
    }
    kk_evv_set(w,kk_context());
    kk_integer_t x_0_11301;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(y, _ctx);
      kk_box_t _x_x2242 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11122_fun2243(i_11303, _ctx), _ctx); /*10002*/
      x_0_11301 = kk_integer_unbox(_x_x2242, _ctx); /*int*/
    }
    else {
      x_0_11301 = y; /*int*/
    }
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11301, _ctx);
      kk_box_t _x_x2244 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11122_fun2245(_ctx), _ctx); /*10001*/
      x_11299 = kk_std_num_ddouble__ddouble_unbox(_x_x2244, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      x_11299 = kk_std_time_parse__mlift_ptime_11120(x_0_11301, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  else {
    x_11299 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2248 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11122_fun2249(_c_x10740, cal, date, hour, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2248, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11121(_c_x10740, cal, date, hour, x_11299, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11124_fun2254__t {
  struct kk_function_s _base;
  kk_ssize_t i_11310;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11124_fun2254(kk_function_t _fself, kk_function_t _b_x421, kk_box_t _b_x422, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11124_fun2254(kk_ssize_t i_11310, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11124_fun2254__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11124_fun2254__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11124_fun2254, kk_context());
  _self->i_11310 = i_11310;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11124_fun2254(kk_function_t _fself, kk_function_t _b_x421, kk_box_t _b_x422, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11124_fun2254__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11124_fun2254__t*, _fself, _ctx);
  kk_ssize_t i_11310 = _self->i_11310; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11310, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11310, _b_x421, _b_x422, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11124_fun2256__t {
  struct kk_function_s _base;
  kk_integer_t _c_x10740;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11124_fun2256(kk_function_t _fself, kk_box_t _b_x431, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11124_fun2256(kk_integer_t _c_x10740, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11124_fun2256__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11124_fun2256__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11124_fun2256, kk_context());
  _self->_c_x10740 = _c_x10740;
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11124_fun2256(kk_function_t _fself, kk_box_t _b_x431, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11124_fun2256__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11124_fun2256__t*, _fself, _ctx);
  kk_integer_t _c_x10740 = _self->_c_x10740; /* int */
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_drop_match(_self, {kk_integer_dup(_c_x10740, _ctx);kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);}, {}, _ctx)
  bool _y_x10746_434 = kk_bool_unbox(_b_x431); /*bool*/;
  kk_std_time_time__time _x_x2257 = kk_std_time_parse__mlift_ptime_11122(_c_x10740, cal, date, hour, _y_x10746_434, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2257, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11124(kk_integer_t _c_x10740, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_char_t wild___1, kk_context_t* _ctx) { /* (int, cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, wild_@1 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t i_11310 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11310,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11312 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool y;
  kk_box_t _x_x2251;
  {
    struct kk_std_core_hnd_Ev* _con_x2252 = kk_std_core_hnd__as_Ev(ev_11312, _ctx);
    kk_box_t _box_x410 = _con_x2252->hnd;
    int32_t m = _con_x2252->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x410, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1924;
    kk_std_core_hnd__clause0 _brw_x1925 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1924 = _brw_x1925; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x413 = _match_x1924.clause;
      _x_x2251 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x413, (_fun_unbox_x413, m, ev_11312, _ctx), _ctx); /*10005*/
    }
  }
  y = kk_bool_unbox(_x_x2251); /*bool*/
  kk_evv_set(w,kk_context());
  bool x_11308;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2253 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11124_fun2254(i_11310, _ctx), _ctx); /*10002*/
    x_11308 = kk_bool_unbox(_x_x2253); /*bool*/
  }
  else {
    x_11308 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2255 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11124_fun2256(_c_x10740, cal, date, hour, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2255, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11122(_c_x10740, cal, date, hour, x_11308, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11126_fun2261__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11126_fun2261(kk_function_t _fself, kk_box_t _b_x442, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11126_fun2261(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11126_fun2261, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11126_fun2261(kk_function_t _fself, kk_box_t _b_x442, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2262;
  bool _x_x2263 = kk_bool_unbox(_b_x442); /*bool*/
  _x_x2262 = kk_std_time_parse__mlift_ptime_11123(_x_x2263, _ctx); /*char*/
  return kk_char_box(_x_x2262, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11126_fun2265__t {
  struct kk_function_s _base;
  kk_ssize_t i_11316;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11126_fun2265(kk_function_t _fself, kk_function_t _b_x449, kk_box_t _b_x450, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11126_fun2265(kk_ssize_t i_11316, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11126_fun2265__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11126_fun2265__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11126_fun2265, kk_context());
  _self->i_11316 = i_11316;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11126_fun2265(kk_function_t _fself, kk_function_t _b_x449, kk_box_t _b_x450, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11126_fun2265__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11126_fun2265__t*, _fself, _ctx);
  kk_ssize_t i_11316 = _self->i_11316; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11316, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11316, _b_x449, _b_x450, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11126_fun2267__t {
  struct kk_function_s _base;
  kk_integer_t _c_x10740;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11126_fun2267(kk_function_t _fself, kk_box_t _b_x459, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11126_fun2267(kk_integer_t _c_x10740, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11126_fun2267__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11126_fun2267__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11126_fun2267, kk_context());
  _self->_c_x10740 = _c_x10740;
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11126_fun2267(kk_function_t _fself, kk_box_t _b_x459, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11126_fun2267__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11126_fun2267__t*, _fself, _ctx);
  kk_integer_t _c_x10740 = _self->_c_x10740; /* int */
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_drop_match(_self, {kk_integer_dup(_c_x10740, _ctx);kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);}, {}, _ctx)
  kk_char_t wild___1_462 = kk_char_unbox(_b_x459, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x2268 = kk_std_time_parse__mlift_ptime_11124(_c_x10740, cal, date, hour, wild___1_462, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2268, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11126(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t _c_x10740, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, int) -> std/time/time/time */ 
  kk_ssize_t i_11316 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11316,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11320 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_0_11318;
  kk_box_t _x_x2258;
  {
    struct kk_std_core_hnd_Ev* _con_x2259 = kk_std_core_hnd__as_Ev(ev_11320, _ctx);
    kk_box_t _box_x435 = _con_x2259->hnd;
    int32_t m = _con_x2259->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x435, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1920;
    kk_std_core_hnd__clause0 _brw_x1921 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1920 = _brw_x1921; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x438 = _match_x1920.clause;
      _x_x2258 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x438, (_fun_unbox_x438, m, ev_11320, _ctx), _ctx); /*10005*/
    }
  }
  x_0_11318 = kk_bool_unbox(_x_x2258); /*bool*/
  kk_char_t y;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2260 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11126_fun2261(_ctx), _ctx); /*10001*/
    y = kk_char_unbox(_x_x2260, KK_OWNED, _ctx); /*char*/
  }
  else {
    if (x_0_11318) {
      y = kk_std_text_parse_char(':', _ctx); /*char*/
    }
    else {
      y = ':'; /*char*/
    }
  }
  kk_evv_set(w,kk_context());
  kk_char_t x_11314;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2264 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11126_fun2265(i_11316, _ctx), _ctx); /*10002*/
    x_11314 = kk_char_unbox(_x_x2264, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_11314 = y; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2266 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11126_fun2267(_c_x10740, cal, date, hour, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2266, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11124(_c_x10740, cal, date, hour, x_11314, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11127_fun2270__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11127_fun2270(kk_function_t _fself, kk_box_t _b_x464, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11127_fun2270(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11127_fun2270, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11127_fun2270(kk_function_t _fself, kk_box_t _b_x464, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2271;
  kk_std_core_types__list _x_x2272 = kk_std_core_types__list_unbox(_b_x464, KK_OWNED, _ctx); /*list<int>*/
  _x_x2271 = kk_std_time_parse__mlift_ptime_11125(_x_x2272, _ctx); /*int*/
  return kk_integer_box(_x_x2271, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11127_fun2274__t {
  struct kk_function_s _base;
  kk_ssize_t i_11324;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11127_fun2274(kk_function_t _fself, kk_function_t _b_x471, kk_box_t _b_x472, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11127_fun2274(kk_ssize_t i_11324, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11127_fun2274__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11127_fun2274__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11127_fun2274, kk_context());
  _self->i_11324 = i_11324;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11127_fun2274(kk_function_t _fself, kk_function_t _b_x471, kk_box_t _b_x472, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11127_fun2274__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11127_fun2274__t*, _fself, _ctx);
  kk_ssize_t i_11324 = _self->i_11324; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11324, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11324, _b_x471, _b_x472, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11127_fun2276__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11127_fun2276(kk_function_t _fself, kk_box_t _b_x481, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11127_fun2276(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11127_fun2276__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11127_fun2276__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11127_fun2276, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11127_fun2276(kk_function_t _fself, kk_box_t _b_x481, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11127_fun2276__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11127_fun2276__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10740_484 = kk_integer_unbox(_b_x481, _ctx); /*int*/;
  kk_std_time_time__time _x_x2277 = kk_std_time_parse__mlift_ptime_11126(cal, date, hour, _c_x10740_484, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2277, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11127(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, bool _y_x10736, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, bool) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_integer_t x_11322;
  if (_y_x10736) {
    kk_ssize_t i_11324 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i_11324,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
    kk_std_core_types__list x_1_11327 = kk_std_time_parse__lift_ptime_10618(kk_integer_from_small(2), _ctx); /*list<int>*/;
    kk_integer_t y;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_1_11327, _ctx);
      kk_box_t _x_x2269 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11127_fun2270(_ctx), _ctx); /*10001*/
      y = kk_integer_unbox(_x_x2269, _ctx); /*int*/
    }
    else {
      y = kk_std_time_parse__lift_ptime_10616(x_1_11327, kk_integer_from_small(0), _ctx); /*int*/
    }
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_integer_drop(y, _ctx);
      kk_box_t _x_x2273 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11127_fun2274(i_11324, _ctx), _ctx); /*10002*/
      x_11322 = kk_integer_unbox(_x_x2273, _ctx); /*int*/
    }
    else {
      x_11322 = y; /*int*/
    }
  }
  else {
    x_11322 = kk_integer_from_small(0); /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11322, _ctx);
    kk_box_t _x_x2275 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11127_fun2276(cal, date, hour, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2275, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11126(cal, date, hour, x_11322, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11129_fun2281__t {
  struct kk_function_s _base;
  kk_ssize_t i_11331;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11129_fun2281(kk_function_t _fself, kk_function_t _b_x496, kk_box_t _b_x497, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11129_fun2281(kk_ssize_t i_11331, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11129_fun2281__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11129_fun2281__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11129_fun2281, kk_context());
  _self->i_11331 = i_11331;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11129_fun2281(kk_function_t _fself, kk_function_t _b_x496, kk_box_t _b_x497, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11129_fun2281__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11129_fun2281__t*, _fself, _ctx);
  kk_ssize_t i_11331 = _self->i_11331; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11331, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11331, _b_x496, _b_x497, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11129_fun2283__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11129_fun2283(kk_function_t _fself, kk_box_t _b_x506, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11129_fun2283(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11129_fun2283__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11129_fun2283__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11129_fun2283, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11129_fun2283(kk_function_t _fself, kk_box_t _b_x506, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11129_fun2283__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11129_fun2283__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);}, {}, _ctx)
  bool _y_x10736_509 = kk_bool_unbox(_b_x506); /*bool*/;
  kk_std_time_time__time _x_x2284 = kk_std_time_parse__mlift_ptime_11127(cal, date, hour, _y_x10736_509, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2284, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11129(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_char_t wild___0, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, wild_@0 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t i_11331 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11331,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11333 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool y;
  kk_box_t _x_x2278;
  {
    struct kk_std_core_hnd_Ev* _con_x2279 = kk_std_core_hnd__as_Ev(ev_11333, _ctx);
    kk_box_t _box_x485 = _con_x2279->hnd;
    int32_t m = _con_x2279->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x485, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1912;
    kk_std_core_hnd__clause0 _brw_x1913 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1912 = _brw_x1913; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x488 = _match_x1912.clause;
      _x_x2278 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x488, (_fun_unbox_x488, m, ev_11333, _ctx), _ctx); /*10005*/
    }
  }
  y = kk_bool_unbox(_x_x2278); /*bool*/
  kk_evv_set(w,kk_context());
  bool x_11329;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2280 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11129_fun2281(i_11331, _ctx), _ctx); /*10002*/
    x_11329 = kk_bool_unbox(_x_x2280); /*bool*/
  }
  else {
    x_11329 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2282 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11129_fun2283(cal, date, hour, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2282, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11127(cal, date, hour, x_11329, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11131_fun2288__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11131_fun2288(kk_function_t _fself, kk_box_t _b_x517, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11131_fun2288(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11131_fun2288, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11131_fun2288(kk_function_t _fself, kk_box_t _b_x517, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2289;
  bool _x_x2290 = kk_bool_unbox(_b_x517); /*bool*/
  _x_x2289 = kk_std_time_parse__mlift_ptime_11128(_x_x2290, _ctx); /*char*/
  return kk_char_box(_x_x2289, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11131_fun2292__t {
  struct kk_function_s _base;
  kk_ssize_t i_11337;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11131_fun2292(kk_function_t _fself, kk_function_t _b_x524, kk_box_t _b_x525, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11131_fun2292(kk_ssize_t i_11337, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11131_fun2292__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11131_fun2292__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11131_fun2292, kk_context());
  _self->i_11337 = i_11337;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11131_fun2292(kk_function_t _fself, kk_function_t _b_x524, kk_box_t _b_x525, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11131_fun2292__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11131_fun2292__t*, _fself, _ctx);
  kk_ssize_t i_11337 = _self->i_11337; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11337, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11337, _b_x524, _b_x525, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11131_fun2294__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t hour;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11131_fun2294(kk_function_t _fself, kk_box_t _b_x534, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11131_fun2294(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11131_fun2294__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11131_fun2294__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11131_fun2294, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->hour = hour;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11131_fun2294(kk_function_t _fself, kk_box_t _b_x534, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11131_fun2294__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11131_fun2294__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t hour = _self->hour; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(hour, _ctx);}, {}, _ctx)
  kk_char_t wild___0_537 = kk_char_unbox(_b_x534, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x2295 = kk_std_time_parse__mlift_ptime_11129(cal, date, hour, wild___0_537, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2295, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11131(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t i_11337 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11337,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11341 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_0_11339;
  kk_box_t _x_x2285;
  {
    struct kk_std_core_hnd_Ev* _con_x2286 = kk_std_core_hnd__as_Ev(ev_11341, _ctx);
    kk_box_t _box_x510 = _con_x2286->hnd;
    int32_t m = _con_x2286->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x510, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1908;
    kk_std_core_hnd__clause0 _brw_x1909 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1908 = _brw_x1909; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x513 = _match_x1908.clause;
      _x_x2285 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x513, (_fun_unbox_x513, m, ev_11341, _ctx), _ctx); /*10005*/
    }
  }
  x_0_11339 = kk_bool_unbox(_x_x2285); /*bool*/
  kk_char_t y;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2287 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11131_fun2288(_ctx), _ctx); /*10001*/
    y = kk_char_unbox(_x_x2287, KK_OWNED, _ctx); /*char*/
  }
  else {
    if (x_0_11339) {
      y = kk_std_text_parse_char(':', _ctx); /*char*/
    }
    else {
      y = ':'; /*char*/
    }
  }
  kk_evv_set(w,kk_context());
  kk_char_t x_11335;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2291 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11131_fun2292(i_11337, _ctx), _ctx); /*10002*/
    x_11335 = kk_char_unbox(_x_x2291, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_11335 = y; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2293 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11131_fun2294(cal, date, hour, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2293, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11129(cal, date, hour, x_11335, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11132_fun2297__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11132_fun2297(kk_function_t _fself, kk_box_t _b_x539, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11132_fun2297(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_11132_fun2297, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11132_fun2297(kk_function_t _fself, kk_box_t _b_x539, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2298;
  kk_std_core_types__list _x_x2299 = kk_std_core_types__list_unbox(_b_x539, KK_OWNED, _ctx); /*list<int>*/
  _x_x2298 = kk_std_time_parse__mlift_ptime_11130(_x_x2299, _ctx); /*int*/
  return kk_integer_box(_x_x2298, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11132_fun2301__t {
  struct kk_function_s _base;
  kk_ssize_t i_11345;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11132_fun2301(kk_function_t _fself, kk_function_t _b_x546, kk_box_t _b_x547, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11132_fun2301(kk_ssize_t i_11345, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11132_fun2301__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11132_fun2301__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11132_fun2301, kk_context());
  _self->i_11345 = i_11345;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11132_fun2301(kk_function_t _fself, kk_function_t _b_x546, kk_box_t _b_x547, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11132_fun2301__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11132_fun2301__t*, _fself, _ctx);
  kk_ssize_t i_11345 = _self->i_11345; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11345, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11345, _b_x546, _b_x547, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_11132_fun2303__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse__mlift_ptime_11132_fun2303(kk_function_t _fself, kk_box_t _b_x556, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_ptime_11132_fun2303(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11132_fun2303__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_ptime_11132_fun2303__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_ptime_11132_fun2303, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_ptime_11132_fun2303(kk_function_t _fself, kk_box_t _b_x556, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_ptime_11132_fun2303__t* _self = kk_function_as(struct kk_std_time_parse__mlift_ptime_11132_fun2303__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_integer_t hour_559 = kk_integer_unbox(_b_x556, _ctx); /*int*/;
  kk_std_time_time__time _x_x2304 = kk_std_time_parse__mlift_ptime_11131(cal, date, hour_559, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2304, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11132(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_char_t wild__, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, wild_ : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t i_11345 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11345,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_1_11348 = kk_std_time_parse__lift_ptime_10614(kk_integer_from_small(2), _ctx); /*list<int>*/;
  kk_integer_t y;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_11348, _ctx);
    kk_box_t _x_x2296 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11132_fun2297(_ctx), _ctx); /*10001*/
    y = kk_integer_unbox(_x_x2296, _ctx); /*int*/
  }
  else {
    y = kk_std_time_parse__lift_ptime_10612(x_1_11348, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w,kk_context());
  kk_integer_t x_11343;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y, _ctx);
    kk_box_t _x_x2300 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_ptime_11132_fun2301(i_11345, _ctx), _ctx); /*10002*/
    x_11343 = kk_integer_unbox(_x_x2300, _ctx); /*int*/
  }
  else {
    x_11343 = y; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11343, _ctx);
    kk_box_t _x_x2302 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_ptime_11132_fun2303(cal, date, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2302, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_ptime_11131(cal, date, x_11343, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2308__t {
  struct kk_function_s _base;
  kk_ssize_t i_11353;
};
static kk_box_t kk_std_time_parse_ptime_fun2308(kk_function_t _fself, kk_function_t _b_x565, kk_box_t _b_x566, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2308(kk_ssize_t i_11353, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2308__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2308__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2308, kk_context());
  _self->i_11353 = i_11353;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2308(kk_function_t _fself, kk_function_t _b_x565, kk_box_t _b_x566, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2308__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2308__t*, _fself, _ctx);
  kk_ssize_t i_11353 = _self->i_11353; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11353, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11353, _b_x565, _b_x566, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2310__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse_ptime_fun2310(kk_function_t _fself, kk_box_t _b_x575, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2310(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2310__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2310__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2310, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2310(kk_function_t _fself, kk_box_t _b_x575, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2310__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2310__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_char_t wild___844 = kk_char_unbox(_b_x575, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x2311 = kk_std_time_parse__mlift_ptime_11132(cal, date, wild___844, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2311, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2313__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun2313(kk_function_t _fself, kk_box_t _b_x577, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2313(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun2313, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2313(kk_function_t _fself, kk_box_t _b_x577, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2314;
  kk_std_core_types__list _x_x2315 = kk_std_core_types__list_unbox(_b_x577, KK_OWNED, _ctx); /*list<int>*/
  _x_x2314 = kk_std_time_parse__mlift_ptime_11130(_x_x2315, _ctx); /*int*/
  return kk_integer_box(_x_x2314, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2317__t {
  struct kk_function_s _base;
  kk_ssize_t i_0_11359;
};
static kk_box_t kk_std_time_parse_ptime_fun2317(kk_function_t _fself, kk_function_t _b_x584, kk_box_t _b_x585, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2317(kk_ssize_t i_0_11359, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2317__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2317__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2317, kk_context());
  _self->i_0_11359 = i_0_11359;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2317(kk_function_t _fself, kk_function_t _b_x584, kk_box_t _b_x585, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2317__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2317__t*, _fself, _ctx);
  kk_ssize_t i_0_11359 = _self->i_0_11359; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_0_11359, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_0_11359, _b_x584, _b_x585, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2319__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse_ptime_fun2319(kk_function_t _fself, kk_box_t _b_x594, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2319(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2319__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2319__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2319, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2319(kk_function_t _fself, kk_box_t _b_x594, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2319__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2319__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_integer_t hour_845 = kk_integer_unbox(_b_x594, _ctx); /*int*/;
  kk_std_time_time__time _x_x2320 = kk_std_time_parse__mlift_ptime_11131(cal, date, hour_845, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2320, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2324__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun2324(kk_function_t _fself, kk_box_t _b_x602, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2324(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun2324, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2324(kk_function_t _fself, kk_box_t _b_x602, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2325;
  bool _x_x2326 = kk_bool_unbox(_b_x602); /*bool*/
  _x_x2325 = kk_std_time_parse__mlift_ptime_11128(_x_x2326, _ctx); /*char*/
  return kk_char_box(_x_x2325, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2328__t {
  struct kk_function_s _base;
  kk_ssize_t i_1_11367;
};
static kk_box_t kk_std_time_parse_ptime_fun2328(kk_function_t _fself, kk_function_t _b_x609, kk_box_t _b_x610, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2328(kk_ssize_t i_1_11367, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2328__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2328__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2328, kk_context());
  _self->i_1_11367 = i_1_11367;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2328(kk_function_t _fself, kk_function_t _b_x609, kk_box_t _b_x610, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2328__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2328__t*, _fself, _ctx);
  kk_ssize_t i_1_11367 = _self->i_1_11367; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_1_11367, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1_11367, _b_x609, _b_x610, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2330__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_1_11356;
};
static kk_box_t kk_std_time_parse_ptime_fun2330(kk_function_t _fself, kk_box_t _b_x619, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2330(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_1_11356, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2330__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2330__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2330, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_1_11356 = x_1_11356;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2330(kk_function_t _fself, kk_box_t _b_x619, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2330__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2330__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_1_11356 = _self->x_1_11356; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_1_11356, _ctx);}, {}, _ctx)
  kk_char_t wild___0_846 = kk_char_unbox(_b_x619, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x2331 = kk_std_time_parse__mlift_ptime_11129(cal, date, x_1_11356, wild___0_846, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2331, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2335__t {
  struct kk_function_s _base;
  kk_ssize_t i_2_11376;
};
static kk_box_t kk_std_time_parse_ptime_fun2335(kk_function_t _fself, kk_function_t _b_x631, kk_box_t _b_x632, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2335(kk_ssize_t i_2_11376, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2335__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2335__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2335, kk_context());
  _self->i_2_11376 = i_2_11376;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2335(kk_function_t _fself, kk_function_t _b_x631, kk_box_t _b_x632, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2335__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2335__t*, _fself, _ctx);
  kk_ssize_t i_2_11376 = _self->i_2_11376; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_2_11376, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2_11376, _b_x631, _b_x632, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2337__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_1_11356;
};
static kk_box_t kk_std_time_parse_ptime_fun2337(kk_function_t _fself, kk_box_t _b_x641, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2337(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_1_11356, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2337__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2337__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2337, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_1_11356 = x_1_11356;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2337(kk_function_t _fself, kk_box_t _b_x641, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2337__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2337__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_1_11356 = _self->x_1_11356; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_1_11356, _ctx);}, {}, _ctx)
  bool _y_x10736_847 = kk_bool_unbox(_b_x641); /*bool*/;
  kk_std_time_time__time _x_x2338 = kk_std_time_parse__mlift_ptime_11127(cal, date, x_1_11356, _y_x10736_847, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2338, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2340__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun2340(kk_function_t _fself, kk_box_t _b_x643, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2340(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun2340, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2340(kk_function_t _fself, kk_box_t _b_x643, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2341;
  kk_std_core_types__list _x_x2342 = kk_std_core_types__list_unbox(_b_x643, KK_OWNED, _ctx); /*list<int>*/
  _x_x2341 = kk_std_time_parse__mlift_ptime_11125(_x_x2342, _ctx); /*int*/
  return kk_integer_box(_x_x2341, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2344__t {
  struct kk_function_s _base;
  kk_ssize_t i_3_11383;
};
static kk_box_t kk_std_time_parse_ptime_fun2344(kk_function_t _fself, kk_function_t _b_x650, kk_box_t _b_x651, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2344(kk_ssize_t i_3_11383, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2344__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2344__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2344, kk_context());
  _self->i_3_11383 = i_3_11383;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2344(kk_function_t _fself, kk_function_t _b_x650, kk_box_t _b_x651, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2344__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2344__t*, _fself, _ctx);
  kk_ssize_t i_3_11383 = _self->i_3_11383; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_3_11383, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3_11383, _b_x650, _b_x651, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2346__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_1_11356;
};
static kk_box_t kk_std_time_parse_ptime_fun2346(kk_function_t _fself, kk_box_t _b_x660, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2346(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_1_11356, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2346__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2346__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2346, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_1_11356 = x_1_11356;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2346(kk_function_t _fself, kk_box_t _b_x660, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2346__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2346__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_1_11356 = _self->x_1_11356; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_1_11356, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10740_848 = kk_integer_unbox(_b_x660, _ctx); /*int*/;
  kk_std_time_time__time _x_x2347 = kk_std_time_parse__mlift_ptime_11126(cal, date, x_1_11356, _c_x10740_848, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2347, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2351__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun2351(kk_function_t _fself, kk_box_t _b_x668, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2351(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun2351, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2351(kk_function_t _fself, kk_box_t _b_x668, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2352;
  bool _x_x2353 = kk_bool_unbox(_b_x668); /*bool*/
  _x_x2352 = kk_std_time_parse__mlift_ptime_11123(_x_x2353, _ctx); /*char*/
  return kk_char_box(_x_x2352, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2355__t {
  struct kk_function_s _base;
  kk_ssize_t i_4_11391;
};
static kk_box_t kk_std_time_parse_ptime_fun2355(kk_function_t _fself, kk_function_t _b_x675, kk_box_t _b_x676, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2355(kk_ssize_t i_4_11391, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2355__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2355__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2355, kk_context());
  _self->i_4_11391 = i_4_11391;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2355(kk_function_t _fself, kk_function_t _b_x675, kk_box_t _b_x676, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2355__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2355__t*, _fself, _ctx);
  kk_ssize_t i_4_11391 = _self->i_4_11391; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_4_11391, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4_11391, _b_x675, _b_x676, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2357__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_1_11356;
  kk_integer_t x_7_11380;
};
static kk_box_t kk_std_time_parse_ptime_fun2357(kk_function_t _fself, kk_box_t _b_x685, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2357(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_1_11356, kk_integer_t x_7_11380, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2357__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2357__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2357, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_1_11356 = x_1_11356;
  _self->x_7_11380 = x_7_11380;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2357(kk_function_t _fself, kk_box_t _b_x685, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2357__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2357__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_1_11356 = _self->x_1_11356; /* int */
  kk_integer_t x_7_11380 = _self->x_7_11380; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_1_11356, _ctx);kk_integer_dup(x_7_11380, _ctx);}, {}, _ctx)
  kk_char_t wild___1_849 = kk_char_unbox(_b_x685, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x2358 = kk_std_time_parse__mlift_ptime_11124(x_7_11380, cal, date, x_1_11356, wild___1_849, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2358, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2362__t {
  struct kk_function_s _base;
  kk_ssize_t i_5_11400;
};
static kk_box_t kk_std_time_parse_ptime_fun2362(kk_function_t _fself, kk_function_t _b_x697, kk_box_t _b_x698, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2362(kk_ssize_t i_5_11400, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2362__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2362__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2362, kk_context());
  _self->i_5_11400 = i_5_11400;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2362(kk_function_t _fself, kk_function_t _b_x697, kk_box_t _b_x698, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2362__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2362__t*, _fself, _ctx);
  kk_ssize_t i_5_11400 = _self->i_5_11400; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_5_11400, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5_11400, _b_x697, _b_x698, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2364__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_1_11356;
  kk_integer_t x_7_11380;
};
static kk_box_t kk_std_time_parse_ptime_fun2364(kk_function_t _fself, kk_box_t _b_x707, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2364(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_1_11356, kk_integer_t x_7_11380, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2364__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2364__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2364, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_1_11356 = x_1_11356;
  _self->x_7_11380 = x_7_11380;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2364(kk_function_t _fself, kk_box_t _b_x707, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2364__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2364__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_1_11356 = _self->x_1_11356; /* int */
  kk_integer_t x_7_11380 = _self->x_7_11380; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_1_11356, _ctx);kk_integer_dup(x_7_11380, _ctx);}, {}, _ctx)
  bool _y_x10746_850 = kk_bool_unbox(_b_x707); /*bool*/;
  kk_std_time_time__time _x_x2365 = kk_std_time_parse__mlift_ptime_11122(x_7_11380, cal, date, x_1_11356, _y_x10746_850, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2365, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2367__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun2367(kk_function_t _fself, kk_box_t _b_x709, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2367(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun2367, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2367(kk_function_t _fself, kk_box_t _b_x709, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2368;
  kk_std_core_types__list _x_x2369 = kk_std_core_types__list_unbox(_b_x709, KK_OWNED, _ctx); /*list<int>*/
  _x_x2368 = kk_std_time_parse__mlift_ptime_11119(_x_x2369, _ctx); /*int*/
  return kk_integer_box(_x_x2368, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2371__t {
  struct kk_function_s _base;
  kk_ssize_t i_6_11409;
};
static kk_box_t kk_std_time_parse_ptime_fun2371(kk_function_t _fself, kk_function_t _b_x716, kk_box_t _b_x717, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2371(kk_ssize_t i_6_11409, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2371__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2371__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2371, kk_context());
  _self->i_6_11409 = i_6_11409;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2371(kk_function_t _fself, kk_function_t _b_x716, kk_box_t _b_x717, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2371__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2371__t*, _fself, _ctx);
  kk_ssize_t i_6_11409 = _self->i_6_11409; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_6_11409, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_6_11409, _b_x716, _b_x717, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2373__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun2373(kk_function_t _fself, kk_box_t _b_x726, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2373(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun2373, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2373(kk_function_t _fself, kk_box_t _b_x726, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2374;
  kk_integer_t _x_x2375 = kk_integer_unbox(_b_x726, _ctx); /*int*/
  _x_x2374 = kk_std_time_parse__mlift_ptime_11120(_x_x2375, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2374, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2377__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_1_11356;
  kk_integer_t x_7_11380;
};
static kk_box_t kk_std_time_parse_ptime_fun2377(kk_function_t _fself, kk_box_t _b_x730, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2377(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_1_11356, kk_integer_t x_7_11380, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2377__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2377__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2377, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_1_11356 = x_1_11356;
  _self->x_7_11380 = x_7_11380;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2377(kk_function_t _fself, kk_box_t _b_x730, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2377__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2377__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_1_11356 = _self->x_1_11356; /* int */
  kk_integer_t x_7_11380 = _self->x_7_11380; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_1_11356, _ctx);kk_integer_dup(x_7_11380, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _c_x10756_851 = kk_std_num_ddouble__ddouble_unbox(_b_x730, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_time__time _x_x2378 = kk_std_time_parse__mlift_ptime_11121(x_7_11380, cal, date, x_1_11356, _c_x10756_851, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2378, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2379__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun2379(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2379(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun2379, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun2383__t {
  struct kk_function_s _base;
  kk_ssize_t i_7_11416;
};
static kk_box_t kk_std_time_parse_ptime_fun2383(kk_function_t _fself, kk_function_t _b_x736, kk_box_t _b_x737, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2383(kk_ssize_t i_7_11416, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2383__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2383__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2383, kk_context());
  _self->i_7_11416 = i_7_11416;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2383(kk_function_t _fself, kk_function_t _b_x736, kk_box_t _b_x737, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2383__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2383__t*, _fself, _ctx);
  kk_ssize_t i_7_11416 = _self->i_7_11416; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_7_11416, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_7_11416, _b_x736, _b_x737, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2386__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun2386(kk_function_t _fself, kk_box_t _b_x746, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2386(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun2386, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2386(kk_function_t _fself, kk_box_t _b_x746, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x2387;
  kk_char_t _x_x2388 = kk_char_unbox(_b_x746, KK_OWNED, _ctx); /*char*/
  _x_x2387 = kk_std_time_parse__mlift_ptime_11111(_x_x2388, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2387, _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun2379(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t i_7_11416 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_7 = kk_evv_swap_create1(i_7_11416,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_char_t y_7;
  kk_string_t _x_x2380;
  kk_define_string_literal(, _s_x2381, 2, "+-", _ctx)
  _x_x2380 = kk_string_dup(_s_x2381, _ctx); /*string*/
  y_7 = kk_std_text_parse_one_of(_x_x2380, _ctx); /*char*/
  kk_evv_set(w_7,kk_context());
  kk_char_t x_17_11414;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2382 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2383(i_7_11416, _ctx), _ctx); /*10002*/
    x_17_11414 = kk_char_unbox(_x_x2382, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_17_11414 = y_7; /*char*/
  }
  kk_std_time_calendar__timezone _x_x2384;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2385 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2386(_ctx), _ctx); /*10001*/
    _x_x2384 = kk_std_time_calendar__timezone_unbox(_x_x2385, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  }
  else {
    _x_x2384 = kk_std_time_parse__mlift_ptime_11111(x_17_11414, _ctx); /*std/time/calendar/timezone*/
  }
  return kk_std_time_calendar__timezone_box(_x_x2384, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2390__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun2390(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2390(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun2390, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun2394__t {
  struct kk_function_s _base;
  kk_ssize_t i_8_11421;
};
static kk_box_t kk_std_time_parse_ptime_fun2394(kk_function_t _fself, kk_function_t _b_x758, kk_box_t _b_x759, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2394(kk_ssize_t i_8_11421, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2394__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2394__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2394, kk_context());
  _self->i_8_11421 = i_8_11421;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2394(kk_function_t _fself, kk_function_t _b_x758, kk_box_t _b_x759, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2394__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2394__t*, _fself, _ctx);
  kk_ssize_t i_8_11421 = _self->i_8_11421; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_8_11421, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_8_11421, _b_x758, _b_x759, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2397__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_ptime_fun2397(kk_function_t _fself, kk_box_t _b_x768, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2397(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_ptime_fun2397, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2397(kk_function_t _fself, kk_box_t _b_x768, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x2398;
  bool _x_x2399 = kk_bool_unbox(_b_x768); /*bool*/
  _x_x2398 = kk_std_time_parse__mlift_ptime_11113(_x_x2399, _ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2398, _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun2390(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t i_8_11421 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_8 = kk_evv_swap_create1(i_8_11421,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_3_11423 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool y_8;
  kk_box_t _x_x2391;
  {
    struct kk_std_core_hnd_Ev* _con_x2392 = kk_std_core_hnd__as_Ev(ev_3_11423, _ctx);
    kk_box_t _box_x747 = _con_x2392->hnd;
    int32_t m_3 = _con_x2392->marker;
    kk_std_text_parse__parse h_3 = kk_std_text_parse__parse_unbox(_box_x747, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h_3, _ctx);
    kk_std_core_hnd__clause0 _match_x1876;
    kk_std_core_hnd__clause0 _brw_x1877 = kk_std_text_parse_pick_fs__select(h_3, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h_3, (KK_I32(5)), _ctx);
    _match_x1876 = _brw_x1877; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x750 = _match_x1876.clause;
      _x_x2391 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x750, (_fun_unbox_x750, m_3, ev_3_11423, _ctx), _ctx); /*10005*/
    }
  }
  y_8 = kk_bool_unbox(_x_x2391); /*bool*/
  kk_evv_set(w_8,kk_context());
  bool x_19_11419;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2393 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2394(i_8_11421, _ctx), _ctx); /*10002*/
    x_19_11419 = kk_bool_unbox(_x_x2393); /*bool*/
  }
  else {
    x_19_11419 = y_8; /*bool*/
  }
  kk_std_time_calendar__timezone _x_x2395;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2396 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2397(_ctx), _ctx); /*10001*/
    _x_x2395 = kk_std_time_calendar__timezone_unbox(_x_x2396, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  }
  else {
    _x_x2395 = kk_std_time_parse__mlift_ptime_11113(x_19_11419, _ctx); /*std/time/calendar/timezone*/
  }
  return kk_std_time_calendar__timezone_box(_x_x2395, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2406__t {
  struct kk_function_s _base;
  kk_ssize_t i_9_11428;
};
static kk_box_t kk_std_time_parse_ptime_fun2406(kk_function_t _fself, kk_function_t _b_x796, kk_box_t _b_x797, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2406(kk_ssize_t i_9_11428, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2406__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2406__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2406, kk_context());
  _self->i_9_11428 = i_9_11428;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2406(kk_function_t _fself, kk_function_t _b_x796, kk_box_t _b_x797, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2406__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2406__t*, _fself, _ctx);
  kk_ssize_t i_9_11428 = _self->i_9_11428; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_9_11428, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_9_11428, _b_x796, _b_x797, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2409__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_integer_t x_1_11356;
  kk_integer_t x_7_11380;
  kk_std_num_ddouble__ddouble x_13_11404;
};
static kk_box_t kk_std_time_parse_ptime_fun2409(kk_function_t _fself, kk_box_t _b_x808, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2409(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t x_1_11356, kk_integer_t x_7_11380, kk_std_num_ddouble__ddouble x_13_11404, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2409__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2409__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2409, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_1_11356 = x_1_11356;
  _self->x_7_11380 = x_7_11380;
  _self->x_13_11404 = x_13_11404;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2409(kk_function_t _fself, kk_box_t _b_x808, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2409__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2409__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_integer_t x_1_11356 = _self->x_1_11356; /* int */
  kk_integer_t x_7_11380 = _self->x_7_11380; /* int */
  kk_std_num_ddouble__ddouble x_13_11404 = _self->x_13_11404; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_integer_dup(x_1_11356, _ctx);kk_integer_dup(x_7_11380, _ctx);kk_std_num_ddouble__ddouble_dup(x_13_11404, _ctx);}, {}, _ctx)
  kk_std_time_calendar__timezone _c_x10776_852 = kk_std_time_calendar__timezone_unbox(_b_x808, KK_OWNED, _ctx); /*std/time/calendar/timezone*/;
  kk_std_time_time__time _x_x2410 = kk_std_time_parse__mlift_ptime_11114(x_7_11380, x_13_11404, cal, date, x_1_11356, _c_x10776_852, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2410, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2417__t {
  struct kk_function_s _base;
  kk_ssize_t i_10_11434;
};
static kk_box_t kk_std_time_parse_ptime_fun2417(kk_function_t _fself, kk_function_t _b_x820, kk_box_t _b_x821, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2417(kk_ssize_t i_10_11434, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2417__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2417__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2417, kk_context());
  _self->i_10_11434 = i_10_11434;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_ptime_fun2418__t {
  struct kk_function_s _base;
  kk_function_t _b_x820;
};
static kk_std_time_time__time kk_std_time_parse_ptime_fun2418(kk_function_t _fself, kk_box_t _b_x822, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2418(kk_function_t _b_x820, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2418__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2418__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2418, kk_context());
  _self->_b_x820 = _b_x820;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_time__time kk_std_time_parse_ptime_fun2418(kk_function_t _fself, kk_box_t _b_x822, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2418__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2418__t*, _fself, _ctx);
  kk_function_t _b_x820 = _self->_b_x820; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x820, _ctx);}, {}, _ctx)
  kk_box_t _x_x2419 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x820, (_b_x820, _b_x822, _ctx), _ctx); /*10000*/
  return kk_std_time_time__time_unbox(_x_x2419, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_ptime_fun2420__t {
  struct kk_function_s _base;
  kk_function_t _b_x816_842;
};
static kk_box_t kk_std_time_parse_ptime_fun2420(kk_function_t _fself, kk_box_t _b_x818, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_ptime_fun2420(kk_function_t _b_x816_842, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2420__t* _self = kk_function_alloc_as(struct kk_std_time_parse_ptime_fun2420__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_ptime_fun2420, kk_context());
  _self->_b_x816_842 = _b_x816_842;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_ptime_fun2420(kk_function_t _fself, kk_box_t _b_x818, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2420__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2420__t*, _fself, _ctx);
  kk_function_t _b_x816_842 = _self->_b_x816_842; /* (10009) -> <std/time/utc/utc,std/text/parse/parse> std/time/time/time */
  kk_drop_match(_self, {kk_function_dup(_b_x816_842, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2421 = kk_function_call(kk_std_time_time__time, (kk_function_t, kk_box_t, kk_context_t*), _b_x816_842, (_b_x816_842, _b_x818, _ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2421, _ctx);
}
static kk_box_t kk_std_time_parse_ptime_fun2417(kk_function_t _fself, kk_function_t _b_x820, kk_box_t _b_x821, kk_context_t* _ctx) {
  struct kk_std_time_parse_ptime_fun2417__t* _self = kk_function_as(struct kk_std_time_parse_ptime_fun2417__t*, _fself, _ctx);
  kk_ssize_t i_10_11434 = _self->i_10_11434; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10_11434, _ctx);}, {}, _ctx)
  kk_function_t cont_10_853 = kk_std_time_parse_new_ptime_fun2418(_b_x820, _ctx); /*(10009) -> <std/time/utc/utc,std/text/parse/parse> std/time/time/time*/;
  kk_box_t res_10_854 = _b_x821; /*10009*/;
  kk_ssize_t _b_x815_841 = i_10_11434; /*hnd/ev-index*/;
  kk_function_t _b_x816_842 = cont_10_853; /*(10009) -> <std/time/utc/utc,std/text/parse/parse> std/time/time/time*/;
  kk_box_t _b_x817_843 = res_10_854; /*10009*/;
  return kk_std_core_hnd_open_at1(_b_x815_841, kk_std_time_parse_new_ptime_fun2420(_b_x816_842, _ctx), _b_x817_843, _ctx);
}

kk_std_time_time__time kk_std_time_parse_ptime(kk_std_time_date__date date, kk_std_time_calendar__calendar cal, kk_context_t* _ctx) { /* (date : std/time/date/date, cal : std/time/calendar/calendar) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t i_11353 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11353,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_char_t y;
  kk_string_t _x_x2305;
  kk_define_string_literal(, _s_x2306, 2, "T ", _ctx)
  _x_x2305 = kk_string_dup(_s_x2306, _ctx); /*string*/
  y = kk_std_text_parse_one_of(_x_x2305, _ctx); /*char*/
  kk_evv_set(w,kk_context());
  kk_char_t x_11350;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2307 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2308(i_11353, _ctx), _ctx); /*10002*/
    x_11350 = kk_char_unbox(_x_x2307, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_11350 = y; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2309 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2310(cal, date, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2309, KK_OWNED, _ctx);
  }
  {
    kk_ssize_t i_0_11359 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_evv_t w_0 = kk_evv_swap_create1(i_0_11359,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
    kk_std_core_types__list x_3_11362 = kk_std_time_parse__lift_ptime_10614(kk_integer_from_small(2), _ctx); /*list<int>*/;
    kk_integer_t y_0;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_3_11362, _ctx);
      kk_box_t _x_x2312 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2313(_ctx), _ctx); /*10001*/
      y_0 = kk_integer_unbox(_x_x2312, _ctx); /*int*/
    }
    else {
      y_0 = kk_std_time_parse__lift_ptime_10612(x_3_11362, kk_integer_from_small(0), _ctx); /*int*/
    }
    kk_evv_set(w_0,kk_context());
    kk_integer_t x_1_11356;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(y_0, _ctx);
      kk_box_t _x_x2316 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2317(i_0_11359, _ctx), _ctx); /*10002*/
      x_1_11356 = kk_integer_unbox(_x_x2316, _ctx); /*int*/
    }
    else {
      x_1_11356 = y_0; /*int*/
    }
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_1_11356, _ctx);
      kk_box_t _x_x2318 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2319(cal, date, _ctx), _ctx); /*10001*/
      return kk_std_time_time__time_unbox(_x_x2318, KK_OWNED, _ctx);
    }
    {
      kk_ssize_t i_1_11367 = (KK_IZ(0)); /*hnd/ev-index*/;
      kk_evv_t w_1 = kk_evv_swap_create1(i_1_11367,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
      kk_std_core_hnd__ev ev_11371 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      bool x_5_11369;
      kk_box_t _x_x2321;
      {
        struct kk_std_core_hnd_Ev* _con_x2322 = kk_std_core_hnd__as_Ev(ev_11371, _ctx);
        kk_box_t _box_x595 = _con_x2322->hnd;
        int32_t m = _con_x2322->marker;
        kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x595, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h, _ctx);
        kk_std_core_hnd__clause0 _match_x1897;
        kk_std_core_hnd__clause0 _brw_x1898 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
        kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
        _match_x1897 = _brw_x1898; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
        {
          kk_function_t _fun_unbox_x598 = _match_x1897.clause;
          _x_x2321 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x598, (_fun_unbox_x598, m, ev_11371, _ctx), _ctx); /*10005*/
        }
      }
      x_5_11369 = kk_bool_unbox(_x_x2321); /*bool*/
      kk_char_t y_1;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x2323 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2324(_ctx), _ctx); /*10001*/
        y_1 = kk_char_unbox(_x_x2323, KK_OWNED, _ctx); /*char*/
      }
      else {
        if (x_5_11369) {
          y_1 = kk_std_text_parse_char(':', _ctx); /*char*/
        }
        else {
          y_1 = ':'; /*char*/
        }
      }
      kk_evv_set(w_1,kk_context());
      kk_char_t x_4_11364;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x2327 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2328(i_1_11367, _ctx), _ctx); /*10002*/
        x_4_11364 = kk_char_unbox(_x_x2327, KK_OWNED, _ctx); /*char*/
      }
      else {
        x_4_11364 = y_1; /*char*/
      }
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x2329 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2330(cal, date, x_1_11356, _ctx), _ctx); /*10001*/
        return kk_std_time_time__time_unbox(_x_x2329, KK_OWNED, _ctx);
      }
      {
        kk_ssize_t i_2_11376 = (KK_IZ(0)); /*hnd/ev-index*/;
        kk_evv_t w_2 = kk_evv_swap_create1(i_2_11376,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
        kk_std_core_hnd__ev ev_0_11378 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
        bool y_2;
        kk_box_t _x_x2332;
        {
          struct kk_std_core_hnd_Ev* _con_x2333 = kk_std_core_hnd__as_Ev(ev_0_11378, _ctx);
          kk_box_t _box_x620 = _con_x2333->hnd;
          int32_t m_0 = _con_x2333->marker;
          kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x620, KK_BORROWED, _ctx);
          kk_std_text_parse__parse_dup(h_0, _ctx);
          kk_std_core_hnd__clause0 _match_x1893;
          kk_std_core_hnd__clause0 _brw_x1894 = kk_std_text_parse_pick_fs__select(h_0, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
          kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
          _match_x1893 = _brw_x1894; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
          {
            kk_function_t _fun_unbox_x623 = _match_x1893.clause;
            _x_x2332 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x623, (_fun_unbox_x623, m_0, ev_0_11378, _ctx), _ctx); /*10005*/
          }
        }
        y_2 = kk_bool_unbox(_x_x2332); /*bool*/
        kk_evv_set(w_2,kk_context());
        bool x_6_11373;
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x2334 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2335(i_2_11376, _ctx), _ctx); /*10002*/
          x_6_11373 = kk_bool_unbox(_x_x2334); /*bool*/
        }
        else {
          x_6_11373 = y_2; /*bool*/
        }
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x2336 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2337(cal, date, x_1_11356, _ctx), _ctx); /*10001*/
          return kk_std_time_time__time_unbox(_x_x2336, KK_OWNED, _ctx);
        }
        {
          kk_integer_t x_7_11380;
          if (x_6_11373) {
            kk_ssize_t i_3_11383 = (KK_IZ(0)); /*hnd/ev-index*/;
            kk_evv_t w_3 = kk_evv_swap_create1(i_3_11383,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
            kk_std_core_types__list x_9_11386 = kk_std_time_parse__lift_ptime_10618(kk_integer_from_small(2), _ctx); /*list<int>*/;
            kk_integer_t y_3;
            if (kk_yielding(kk_context())) {
              kk_std_core_types__list_drop(x_9_11386, _ctx);
              kk_box_t _x_x2339 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2340(_ctx), _ctx); /*10001*/
              y_3 = kk_integer_unbox(_x_x2339, _ctx); /*int*/
            }
            else {
              y_3 = kk_std_time_parse__lift_ptime_10616(x_9_11386, kk_integer_from_small(0), _ctx); /*int*/
            }
            kk_evv_set(w_3,kk_context());
            if (kk_yielding(kk_context())) {
              kk_integer_drop(y_3, _ctx);
              kk_box_t _x_x2343 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2344(i_3_11383, _ctx), _ctx); /*10002*/
              x_7_11380 = kk_integer_unbox(_x_x2343, _ctx); /*int*/
            }
            else {
              x_7_11380 = y_3; /*int*/
            }
          }
          else {
            x_7_11380 = kk_integer_from_small(0); /*int*/
          }
          if (kk_yielding(kk_context())) {
            kk_integer_drop(x_7_11380, _ctx);
            kk_box_t _x_x2345 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2346(cal, date, x_1_11356, _ctx), _ctx); /*10001*/
            return kk_std_time_time__time_unbox(_x_x2345, KK_OWNED, _ctx);
          }
          {
            kk_ssize_t i_4_11391 = (KK_IZ(0)); /*hnd/ev-index*/;
            kk_evv_t w_4 = kk_evv_swap_create1(i_4_11391,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
            kk_std_core_hnd__ev ev_1_11395 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
            bool x_11_11393;
            kk_box_t _x_x2348;
            {
              struct kk_std_core_hnd_Ev* _con_x2349 = kk_std_core_hnd__as_Ev(ev_1_11395, _ctx);
              kk_box_t _box_x661 = _con_x2349->hnd;
              int32_t m_1 = _con_x2349->marker;
              kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x661, KK_BORROWED, _ctx);
              kk_std_text_parse__parse_dup(h_1, _ctx);
              kk_std_core_hnd__clause0 _match_x1888;
              kk_std_core_hnd__clause0 _brw_x1889 = kk_std_text_parse_pick_fs__select(h_1, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
              kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
              _match_x1888 = _brw_x1889; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
              {
                kk_function_t _fun_unbox_x664 = _match_x1888.clause;
                _x_x2348 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x664, (_fun_unbox_x664, m_1, ev_1_11395, _ctx), _ctx); /*10005*/
              }
            }
            x_11_11393 = kk_bool_unbox(_x_x2348); /*bool*/
            kk_char_t y_4;
            if (kk_yielding(kk_context())) {
              kk_box_t _x_x2350 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2351(_ctx), _ctx); /*10001*/
              y_4 = kk_char_unbox(_x_x2350, KK_OWNED, _ctx); /*char*/
            }
            else {
              if (x_11_11393) {
                y_4 = kk_std_text_parse_char(':', _ctx); /*char*/
              }
              else {
                y_4 = ':'; /*char*/
              }
            }
            kk_evv_set(w_4,kk_context());
            kk_char_t x_10_11388;
            if (kk_yielding(kk_context())) {
              kk_box_t _x_x2354 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2355(i_4_11391, _ctx), _ctx); /*10002*/
              x_10_11388 = kk_char_unbox(_x_x2354, KK_OWNED, _ctx); /*char*/
            }
            else {
              x_10_11388 = y_4; /*char*/
            }
            if (kk_yielding(kk_context())) {
              kk_box_t _x_x2356 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2357(cal, date, x_1_11356, x_7_11380, _ctx), _ctx); /*10001*/
              return kk_std_time_time__time_unbox(_x_x2356, KK_OWNED, _ctx);
            }
            {
              kk_ssize_t i_5_11400 = (KK_IZ(0)); /*hnd/ev-index*/;
              kk_evv_t w_5 = kk_evv_swap_create1(i_5_11400,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
              kk_std_core_hnd__ev ev_2_11402 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
              bool y_5;
              kk_box_t _x_x2359;
              {
                struct kk_std_core_hnd_Ev* _con_x2360 = kk_std_core_hnd__as_Ev(ev_2_11402, _ctx);
                kk_box_t _box_x686 = _con_x2360->hnd;
                int32_t m_2 = _con_x2360->marker;
                kk_std_text_parse__parse h_2 = kk_std_text_parse__parse_unbox(_box_x686, KK_BORROWED, _ctx);
                kk_std_text_parse__parse_dup(h_2, _ctx);
                kk_std_core_hnd__clause0 _match_x1884;
                kk_std_core_hnd__clause0 _brw_x1885 = kk_std_text_parse_pick_fs__select(h_2, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
                kk_datatype_ptr_dropn(h_2, (KK_I32(5)), _ctx);
                _match_x1884 = _brw_x1885; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
                {
                  kk_function_t _fun_unbox_x689 = _match_x1884.clause;
                  _x_x2359 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x689, (_fun_unbox_x689, m_2, ev_2_11402, _ctx), _ctx); /*10005*/
                }
              }
              y_5 = kk_bool_unbox(_x_x2359); /*bool*/
              kk_evv_set(w_5,kk_context());
              bool x_12_11397;
              if (kk_yielding(kk_context())) {
                kk_box_t _x_x2361 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2362(i_5_11400, _ctx), _ctx); /*10002*/
                x_12_11397 = kk_bool_unbox(_x_x2361); /*bool*/
              }
              else {
                x_12_11397 = y_5; /*bool*/
              }
              if (kk_yielding(kk_context())) {
                kk_box_t _x_x2363 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2364(cal, date, x_1_11356, x_7_11380, _ctx), _ctx); /*10001*/
                return kk_std_time_time__time_unbox(_x_x2363, KK_OWNED, _ctx);
              }
              {
                kk_std_num_ddouble__ddouble x_13_11404;
                if (x_12_11397) {
                  kk_ssize_t i_6_11409 = (KK_IZ(0)); /*hnd/ev-index*/;
                  kk_evv_t w_6 = kk_evv_swap_create1(i_6_11409,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
                  kk_std_core_types__list x_16_11412 = kk_std_time_parse__lift_ptime_10622(kk_integer_from_small(2), _ctx); /*list<int>*/;
                  kk_integer_t y_6;
                  if (kk_yielding(kk_context())) {
                    kk_std_core_types__list_drop(x_16_11412, _ctx);
                    kk_box_t _x_x2366 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2367(_ctx), _ctx); /*10001*/
                    y_6 = kk_integer_unbox(_x_x2366, _ctx); /*int*/
                  }
                  else {
                    y_6 = kk_std_time_parse__lift_ptime_10620(x_16_11412, kk_integer_from_small(0), _ctx); /*int*/
                  }
                  kk_evv_set(w_6,kk_context());
                  kk_integer_t x_14_11407;
                  if (kk_yielding(kk_context())) {
                    kk_integer_drop(y_6, _ctx);
                    kk_box_t _x_x2370 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2371(i_6_11409, _ctx), _ctx); /*10002*/
                    x_14_11407 = kk_integer_unbox(_x_x2370, _ctx); /*int*/
                  }
                  else {
                    x_14_11407 = y_6; /*int*/
                  }
                  if (kk_yielding(kk_context())) {
                    kk_integer_drop(x_14_11407, _ctx);
                    kk_box_t _x_x2372 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2373(_ctx), _ctx); /*10001*/
                    x_13_11404 = kk_std_num_ddouble__ddouble_unbox(_x_x2372, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
                  }
                  else {
                    x_13_11404 = kk_std_time_parse__mlift_ptime_11120(x_14_11407, _ctx); /*std/num/ddouble/ddouble*/
                  }
                }
                else {
                  x_13_11404 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
                }
                if (kk_yielding(kk_context())) {
                  kk_box_t _x_x2376 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2377(cal, date, x_1_11356, x_7_11380, _ctx), _ctx); /*10001*/
                  return kk_std_time_time__time_unbox(_x_x2376, KK_OWNED, _ctx);
                }
                {
                  kk_std_core_types__list ps_10020;
                  kk_std_core_types__list _x_x2389 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse_new_ptime_fun2390(_ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
                  ps_10020 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse_new_ptime_fun2379(_ctx), _ctx), _x_x2389, _ctx); /*list<std/text/parse/parser<std/time/utc/utc,std/time/calendar/timezone>>*/
                  kk_std_time_calendar__timezone x_20_11425;
                  if (kk_std_core_types__is_Nil(ps_10020, _ctx)) {
                    kk_ssize_t i_9_11428 = (KK_IZ(0)); /*hnd/ev-index*/;
                    kk_evv_t w_9 = kk_evv_swap_create1(i_9_11428,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
                    kk_std_core_hnd__ev ev_4_11431 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
                    kk_std_time_calendar__timezone y_9;
                    kk_box_t _x_x2400;
                    {
                      struct kk_std_core_hnd_Ev* _con_x2401 = kk_std_core_hnd__as_Ev(ev_4_11431, _ctx);
                      kk_box_t _box_x783 = _con_x2401->hnd;
                      int32_t m_4 = _con_x2401->marker;
                      kk_std_text_parse__parse h_4 = kk_std_text_parse__parse_unbox(_box_x783, KK_BORROWED, _ctx);
                      kk_std_text_parse__parse_dup(h_4, _ctx);
                      kk_std_core_hnd__clause1 _match_x1872;
                      kk_std_core_hnd__clause1 _brw_x1873 = kk_std_text_parse_fail_fs__select(h_4, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
                      kk_datatype_ptr_dropn(h_4, (KK_I32(5)), _ctx);
                      _match_x1872 = _brw_x1873; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
                      {
                        kk_function_t _fun_unbox_x787 = _match_x1872.clause;
                        kk_box_t _x_x2402;
                        kk_string_t _x_x2403;
                        kk_define_string_literal(, _s_x2404, 23, "no further alternatives", _ctx)
                        _x_x2403 = kk_string_dup(_s_x2404, _ctx); /*string*/
                        _x_x2402 = kk_string_box(_x_x2403); /*10009*/
                        _x_x2400 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x787, (_fun_unbox_x787, m_4, ev_4_11431, _x_x2402, _ctx), _ctx); /*10010*/
                      }
                    }
                    y_9 = kk_std_time_calendar__timezone_unbox(_x_x2400, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
                    kk_evv_set(w_9,kk_context());
                    if (kk_yielding(kk_context())) {
                      kk_datatype_ptr_dropn(y_9, (KK_I32(3)), _ctx);
                      kk_box_t _x_x2405 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2406(i_9_11428, _ctx), _ctx); /*10002*/
                      x_20_11425 = kk_std_time_calendar__timezone_unbox(_x_x2405, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
                    }
                    else {
                      x_20_11425 = y_9; /*std/time/calendar/timezone*/
                    }
                  }
                  else {
                    kk_box_t _x_x2407 = kk_std_text_parse__unroll_choose_10000(ps_10020, _ctx); /*10000*/
                    x_20_11425 = kk_std_time_calendar__timezone_unbox(_x_x2407, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
                  }
                  if (kk_yielding(kk_context())) {
                    kk_datatype_ptr_dropn(x_20_11425, (KK_I32(3)), _ctx);
                    kk_box_t _x_x2408 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_ptime_fun2409(cal, date, x_1_11356, x_7_11380, x_13_11404, _ctx), _ctx); /*10001*/
                    return kk_std_time_time__time_unbox(_x_x2408, KK_OWNED, _ctx);
                  }
                  {
                    kk_ssize_t i_10_11434 = (KK_IZ(1)); /*hnd/ev-index*/;
                    kk_evv_t w_10 = kk_evv_swap_create1(i_10_11434,kk_context()); /*hnd/evv<<std/time/utc/utc,std/text/parse/parse>>*/;
                    kk_std_time_time__time y_10;
                    kk_std_core_types__optional _x_x2411;
                    kk_box_t _x_x2412;
                    kk_std_time_date__clock _x_x2413 = kk_std_time_date__new_Clock(kk_reuse_null, 0, x_1_11356, x_7_11380, x_13_11404, _ctx); /*std/time/date/clock*/
                    _x_x2412 = kk_std_time_date__clock_box(_x_x2413, _ctx); /*10003*/
                    _x_x2411 = kk_std_core_types__new_Optional(_x_x2412, _ctx); /*? 10003*/
                    kk_std_core_types__optional _x_x2414 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(x_20_11425, _ctx), _ctx); /*? 10003*/
                    kk_std_core_types__optional _x_x2415 = kk_std_core_types__new_Optional(kk_std_time_calendar__calendar_box(cal, _ctx), _ctx); /*? 10003*/
                    y_10 = kk_std_time_time_date_fs_time(date, _x_x2411, _x_x2414, _x_x2415, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
                    kk_evv_set(w_10,kk_context());
                    if (kk_yielding(kk_context())) {
                      kk_datatype_ptr_dropn(y_10, (KK_I32(9)), _ctx);
                      kk_box_t _x_x2416 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_ptime_fun2417(i_10_11434, _ctx), _ctx); /*10002*/
                      return kk_std_time_time__time_unbox(_x_x2416, KK_OWNED, _ctx);
                    }
                    {
                      return y_10;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
 
// lifted local: @lift-piso@10632, year, piso, @spec-x10342
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10337, using:
// @uniq-f@10337 = fn<(std/text/parse/parse :: (E, V) -> V)>(x: int, d: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@0: int, y: int){
//     (std/core/int/int-add(x@0, y));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x, 10)), d);
// }

kk_integer_t kk_std_time_parse__lift_piso_10633(kk_std_core_types__list _uniq_xs_10335, kk_integer_t _uniq_z_10336, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10335, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2422 = kk_std_core_types__as_Cons(_uniq_xs_10335, _ctx);
    kk_box_t _box_x855 = _con_x2422->head;
    kk_std_core_types__list _uniq_xx_10340 = _con_x2422->tail;
    kk_integer_t _uniq_x_10339 = kk_integer_unbox(_box_x855, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10335, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10335, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10339, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10340, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10335, _ctx);
    }
    kk_integer_t x_0_10967 = kk_integer_mul(_uniq_z_10336,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2423 = kk_integer_add(x_0_10967,_uniq_x_10339,kk_context()); /*int*/
      _uniq_xs_10335 = _uniq_xx_10340;
      _uniq_z_10336 = _x_x2423;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10336;
  }
}
 
// lifted local: year, piso, @spec-x10334
// specialized: std/core/list/foldl, on parameters @uniq-f@10331, using:
// @uniq-f@10331 = fn<(std/text/parse/parse :: (E, V) -> V)>(x: int, d: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@0: int, y: int){
//     (std/core/int/int-add(x@0, y));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x, 10)), d);
// }

kk_integer_t kk_std_time_parse__lift_piso_10632(kk_std_core_types__list _uniq_xs_10329, kk_integer_t _uniq_z_10330, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10329, _ctx)) {
    return _uniq_z_10330;
  }
  {
    return kk_std_time_parse__lift_piso_10633(_uniq_xs_10329, _uniq_z_10330, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10635_11133(kk_std_core_types__list _uniq_acc_10349, kk_integer_t _uniq_n_10348, kk_integer_t _uniq_x_10356, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2424 = kk_integer_add_small_const(_uniq_n_10348, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2425 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10356, _ctx), _uniq_acc_10349, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_piso_10635(_x_x2424, _x_x2425, _ctx);
}
 
// lifted local: @lift-piso@10634, year, piso, @spec-x10359
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10350, using:
// @uniq-p@10350 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_piso_10635_fun2427__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10349_0;
  kk_integer_t _uniq_n_10348_0;
};
static kk_box_t kk_std_time_parse__lift_piso_10635_fun2427(kk_function_t _fself, kk_box_t _b_x861, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_piso_10635_fun2427(kk_std_core_types__list _uniq_acc_10349_0, kk_integer_t _uniq_n_10348_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10635_fun2427__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_piso_10635_fun2427__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_piso_10635_fun2427, kk_context());
  _self->_uniq_acc_10349_0 = _uniq_acc_10349_0;
  _self->_uniq_n_10348_0 = _uniq_n_10348_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_piso_10635_fun2427(kk_function_t _fself, kk_box_t _b_x861, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10635_fun2427__t* _self = kk_function_as(struct kk_std_time_parse__lift_piso_10635_fun2427__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10349_0 = _self->_uniq_acc_10349_0; /* list<int> */
  kk_integer_t _uniq_n_10348_0 = _self->_uniq_n_10348_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10349_0, _ctx);kk_integer_dup(_uniq_n_10348_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10356_0_867 = kk_integer_unbox(_b_x861, _ctx); /*int*/;
  kk_std_core_types__list _x_x2428 = kk_std_time_parse__mlift_lift_piso_10635_11133(_uniq_acc_10349_0, _uniq_n_10348_0, _uniq_x_10356_0_867, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2428, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_piso_10635(kk_integer_t _uniq_n_10348_0, kk_std_core_types__list _uniq_acc_10349_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1859 = kk_integer_lte_borrow(_uniq_n_10348_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1859) {
    kk_integer_drop(_uniq_n_10348_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10349_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10349_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11438 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11438, _ctx);
      kk_box_t _x_x2426 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_piso_10635_fun2427(_uniq_acc_10349_0, _uniq_n_10348_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2426, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2429 = kk_integer_add_small_const(_uniq_n_10348_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2430 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11438, _ctx), _uniq_acc_10349_0, _ctx); /*list<10021>*/
      _uniq_n_10348_0 = _x_x2429;
      _uniq_acc_10349_0 = _x_x2430;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: year, piso, @spec-x10347
// specialized: std/text/parse/count, on parameters @uniq-p@10346, using:
// @uniq-p@10346 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_piso_10634(kk_integer_t _uniq_n_10345, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_piso_10635(_uniq_n_10345, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-piso@10636, m, ps@10029, piso, @spec-x10373
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10368, using:
// @uniq-f@10368 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@1: int, d@0: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@2: int, y@0: int){
//     (std/core/int/int-add(x@2, y@0));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@1, 10)), d@0);
// }

kk_integer_t kk_std_time_parse__lift_piso_10637(kk_std_core_types__list _uniq_xs_10366, kk_integer_t _uniq_z_10367, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10366, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2431 = kk_std_core_types__as_Cons(_uniq_xs_10366, _ctx);
    kk_box_t _box_x868 = _con_x2431->head;
    kk_std_core_types__list _uniq_xx_10371 = _con_x2431->tail;
    kk_integer_t _uniq_x_10370 = kk_integer_unbox(_box_x868, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10366, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10366, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10370, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10371, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10366, _ctx);
    }
    kk_integer_t x_2_10972 = kk_integer_mul(_uniq_z_10367,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2432 = kk_integer_add(x_2_10972,_uniq_x_10370,kk_context()); /*int*/
      _uniq_xs_10366 = _uniq_xx_10371;
      _uniq_z_10367 = _x_x2432;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10367;
  }
}
 
// lifted local: m, ps@10029, piso, @spec-x10365
// specialized: std/core/list/foldl, on parameters @uniq-f@10362, using:
// @uniq-f@10362 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@1: int, d@0: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@2: int, y@0: int){
//     (std/core/int/int-add(x@2, y@0));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@1, 10)), d@0);
// }

kk_integer_t kk_std_time_parse__lift_piso_10636(kk_std_core_types__list _uniq_xs_10360, kk_integer_t _uniq_z_10361, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10360, _ctx)) {
    return _uniq_z_10361;
  }
  {
    return kk_std_time_parse__lift_piso_10637(_uniq_xs_10360, _uniq_z_10361, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10639_11134(kk_std_core_types__list _uniq_acc_10380, kk_integer_t _uniq_n_10379, kk_integer_t _uniq_x_10387, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2433 = kk_integer_add_small_const(_uniq_n_10379, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2434 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10387, _ctx), _uniq_acc_10380, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_piso_10639(_x_x2433, _x_x2434, _ctx);
}
 
// lifted local: @lift-piso@10638, m, ps@10029, piso, @spec-x10390
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10381, using:
// @uniq-p@10381 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_piso_10639_fun2436__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10380_0;
  kk_integer_t _uniq_n_10379_0;
};
static kk_box_t kk_std_time_parse__lift_piso_10639_fun2436(kk_function_t _fself, kk_box_t _b_x874, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_piso_10639_fun2436(kk_std_core_types__list _uniq_acc_10380_0, kk_integer_t _uniq_n_10379_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10639_fun2436__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_piso_10639_fun2436__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_piso_10639_fun2436, kk_context());
  _self->_uniq_acc_10380_0 = _uniq_acc_10380_0;
  _self->_uniq_n_10379_0 = _uniq_n_10379_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_piso_10639_fun2436(kk_function_t _fself, kk_box_t _b_x874, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10639_fun2436__t* _self = kk_function_as(struct kk_std_time_parse__lift_piso_10639_fun2436__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10380_0 = _self->_uniq_acc_10380_0; /* list<int> */
  kk_integer_t _uniq_n_10379_0 = _self->_uniq_n_10379_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10380_0, _ctx);kk_integer_dup(_uniq_n_10379_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10387_0_880 = kk_integer_unbox(_b_x874, _ctx); /*int*/;
  kk_std_core_types__list _x_x2437 = kk_std_time_parse__mlift_lift_piso_10639_11134(_uniq_acc_10380_0, _uniq_n_10379_0, _uniq_x_10387_0_880, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2437, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_piso_10639(kk_integer_t _uniq_n_10379_0, kk_std_core_types__list _uniq_acc_10380_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1857 = kk_integer_lte_borrow(_uniq_n_10379_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1857) {
    kk_integer_drop(_uniq_n_10379_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10380_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10380_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11443 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11443, _ctx);
      kk_box_t _x_x2435 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_piso_10639_fun2436(_uniq_acc_10380_0, _uniq_n_10379_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2435, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2438 = kk_integer_add_small_const(_uniq_n_10379_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2439 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11443, _ctx), _uniq_acc_10380_0, _ctx); /*list<10021>*/
      _uniq_n_10379_0 = _x_x2438;
      _uniq_acc_10380_0 = _x_x2439;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: m, ps@10029, piso, @spec-x10378
// specialized: std/text/parse/count, on parameters @uniq-p@10377, using:
// @uniq-p@10377 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_piso_10638(kk_integer_t _uniq_n_10376, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_piso_10639(_uniq_n_10376, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-piso@10640, d@2, ps@10029, piso, @spec-x10404
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10399, using:
// @uniq-f@10399 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@3: int, d@1: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@4: int, y@1: int){
//     (std/core/int/int-add(x@4, y@1));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@3, 10)), d@1);
// }

kk_integer_t kk_std_time_parse__lift_piso_10641(kk_std_core_types__list _uniq_xs_10397, kk_integer_t _uniq_z_10398, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10397, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2440 = kk_std_core_types__as_Cons(_uniq_xs_10397, _ctx);
    kk_box_t _box_x881 = _con_x2440->head;
    kk_std_core_types__list _uniq_xx_10402 = _con_x2440->tail;
    kk_integer_t _uniq_x_10401 = kk_integer_unbox(_box_x881, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10397, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10397, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10401, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10402, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10397, _ctx);
    }
    kk_integer_t x_4_10977 = kk_integer_mul(_uniq_z_10398,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2441 = kk_integer_add(x_4_10977,_uniq_x_10401,kk_context()); /*int*/
      _uniq_xs_10397 = _uniq_xx_10402;
      _uniq_z_10398 = _x_x2441;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10398;
  }
}
 
// lifted local: d@2, ps@10029, piso, @spec-x10396
// specialized: std/core/list/foldl, on parameters @uniq-f@10393, using:
// @uniq-f@10393 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@3: int, d@1: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@4: int, y@1: int){
//     (std/core/int/int-add(x@4, y@1));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@3, 10)), d@1);
// }

kk_integer_t kk_std_time_parse__lift_piso_10640(kk_std_core_types__list _uniq_xs_10391, kk_integer_t _uniq_z_10392, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10391, _ctx)) {
    return _uniq_z_10392;
  }
  {
    return kk_std_time_parse__lift_piso_10641(_uniq_xs_10391, _uniq_z_10392, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10643_11135(kk_std_core_types__list _uniq_acc_10411, kk_integer_t _uniq_n_10410, kk_integer_t _uniq_x_10418, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2442 = kk_integer_add_small_const(_uniq_n_10410, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2443 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10418, _ctx), _uniq_acc_10411, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_piso_10643(_x_x2442, _x_x2443, _ctx);
}
 
// lifted local: @lift-piso@10642, d@2, ps@10029, piso, @spec-x10421
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10412, using:
// @uniq-p@10412 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_piso_10643_fun2445__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10411_0;
  kk_integer_t _uniq_n_10410_0;
};
static kk_box_t kk_std_time_parse__lift_piso_10643_fun2445(kk_function_t _fself, kk_box_t _b_x887, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_piso_10643_fun2445(kk_std_core_types__list _uniq_acc_10411_0, kk_integer_t _uniq_n_10410_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10643_fun2445__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_piso_10643_fun2445__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_piso_10643_fun2445, kk_context());
  _self->_uniq_acc_10411_0 = _uniq_acc_10411_0;
  _self->_uniq_n_10410_0 = _uniq_n_10410_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_piso_10643_fun2445(kk_function_t _fself, kk_box_t _b_x887, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10643_fun2445__t* _self = kk_function_as(struct kk_std_time_parse__lift_piso_10643_fun2445__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10411_0 = _self->_uniq_acc_10411_0; /* list<int> */
  kk_integer_t _uniq_n_10410_0 = _self->_uniq_n_10410_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10411_0, _ctx);kk_integer_dup(_uniq_n_10410_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10418_0_893 = kk_integer_unbox(_b_x887, _ctx); /*int*/;
  kk_std_core_types__list _x_x2446 = kk_std_time_parse__mlift_lift_piso_10643_11135(_uniq_acc_10411_0, _uniq_n_10410_0, _uniq_x_10418_0_893, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2446, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_piso_10643(kk_integer_t _uniq_n_10410_0, kk_std_core_types__list _uniq_acc_10411_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1855 = kk_integer_lte_borrow(_uniq_n_10410_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1855) {
    kk_integer_drop(_uniq_n_10410_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10411_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10411_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11448 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11448, _ctx);
      kk_box_t _x_x2444 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_piso_10643_fun2445(_uniq_acc_10411_0, _uniq_n_10410_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2444, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2447 = kk_integer_add_small_const(_uniq_n_10410_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2448 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11448, _ctx), _uniq_acc_10411_0, _ctx); /*list<10021>*/
      _uniq_n_10410_0 = _x_x2447;
      _uniq_acc_10411_0 = _x_x2448;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: d@2, ps@10029, piso, @spec-x10409
// specialized: std/text/parse/count, on parameters @uniq-p@10408, using:
// @uniq-p@10408 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_piso_10642(kk_integer_t _uniq_n_10407, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_piso_10643(_uniq_n_10407, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-piso@10644, w, ps@10029, piso, @spec-x10435
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10430, using:
// @uniq-f@10430 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@5: int, d@3: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@6: int, y@2: int){
//     (std/core/int/int-add(x@6, y@2));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@5, 10)), d@3);
// }

kk_integer_t kk_std_time_parse__lift_piso_10645(kk_std_core_types__list _uniq_xs_10428, kk_integer_t _uniq_z_10429, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10428, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2449 = kk_std_core_types__as_Cons(_uniq_xs_10428, _ctx);
    kk_box_t _box_x894 = _con_x2449->head;
    kk_std_core_types__list _uniq_xx_10433 = _con_x2449->tail;
    kk_integer_t _uniq_x_10432 = kk_integer_unbox(_box_x894, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10428, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10428, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10432, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10433, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10428, _ctx);
    }
    kk_integer_t x_6_10982 = kk_integer_mul(_uniq_z_10429,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2450 = kk_integer_add(x_6_10982,_uniq_x_10432,kk_context()); /*int*/
      _uniq_xs_10428 = _uniq_xx_10433;
      _uniq_z_10429 = _x_x2450;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10429;
  }
}
 
// lifted local: w, ps@10029, piso, @spec-x10427
// specialized: std/core/list/foldl, on parameters @uniq-f@10424, using:
// @uniq-f@10424 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@5: int, d@3: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@6: int, y@2: int){
//     (std/core/int/int-add(x@6, y@2));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@5, 10)), d@3);
// }

kk_integer_t kk_std_time_parse__lift_piso_10644(kk_std_core_types__list _uniq_xs_10422, kk_integer_t _uniq_z_10423, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10422, _ctx)) {
    return _uniq_z_10423;
  }
  {
    return kk_std_time_parse__lift_piso_10645(_uniq_xs_10422, _uniq_z_10423, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10647_11136(kk_std_core_types__list _uniq_acc_10442, kk_integer_t _uniq_n_10441, kk_integer_t _uniq_x_10449, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2451 = kk_integer_add_small_const(_uniq_n_10441, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2452 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10449, _ctx), _uniq_acc_10442, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_piso_10647(_x_x2451, _x_x2452, _ctx);
}
 
// lifted local: @lift-piso@10646, w, ps@10029, piso, @spec-x10452
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10443, using:
// @uniq-p@10443 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_piso_10647_fun2454__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10442_0;
  kk_integer_t _uniq_n_10441_0;
};
static kk_box_t kk_std_time_parse__lift_piso_10647_fun2454(kk_function_t _fself, kk_box_t _b_x900, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_piso_10647_fun2454(kk_std_core_types__list _uniq_acc_10442_0, kk_integer_t _uniq_n_10441_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10647_fun2454__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_piso_10647_fun2454__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_piso_10647_fun2454, kk_context());
  _self->_uniq_acc_10442_0 = _uniq_acc_10442_0;
  _self->_uniq_n_10441_0 = _uniq_n_10441_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_piso_10647_fun2454(kk_function_t _fself, kk_box_t _b_x900, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10647_fun2454__t* _self = kk_function_as(struct kk_std_time_parse__lift_piso_10647_fun2454__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10442_0 = _self->_uniq_acc_10442_0; /* list<int> */
  kk_integer_t _uniq_n_10441_0 = _self->_uniq_n_10441_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10442_0, _ctx);kk_integer_dup(_uniq_n_10441_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10449_0_906 = kk_integer_unbox(_b_x900, _ctx); /*int*/;
  kk_std_core_types__list _x_x2455 = kk_std_time_parse__mlift_lift_piso_10647_11136(_uniq_acc_10442_0, _uniq_n_10441_0, _uniq_x_10449_0_906, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2455, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_piso_10647(kk_integer_t _uniq_n_10441_0, kk_std_core_types__list _uniq_acc_10442_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1853 = kk_integer_lte_borrow(_uniq_n_10441_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1853) {
    kk_integer_drop(_uniq_n_10441_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10442_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10442_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11453 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11453, _ctx);
      kk_box_t _x_x2453 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_piso_10647_fun2454(_uniq_acc_10442_0, _uniq_n_10441_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2453, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2456 = kk_integer_add_small_const(_uniq_n_10441_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2457 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11453, _ctx), _uniq_acc_10442_0, _ctx); /*list<10021>*/
      _uniq_n_10441_0 = _x_x2456;
      _uniq_acc_10442_0 = _x_x2457;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: w, ps@10029, piso, @spec-x10440
// specialized: std/text/parse/count, on parameters @uniq-p@10439, using:
// @uniq-p@10439 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_piso_10646(kk_integer_t _uniq_n_10438, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_piso_10647(_uniq_n_10438, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-piso@10648, d@0@0, ps@10029, piso, @spec-x10466
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10461, using:
// @uniq-f@10461 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@7: int, d@4: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@8: int, y@3: int){
//     (std/core/int/int-add(x@8, y@3));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@7, 10)), d@4);
// }

kk_integer_t kk_std_time_parse__lift_piso_10649(kk_std_core_types__list _uniq_xs_10459, kk_integer_t _uniq_z_10460, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10459, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2458 = kk_std_core_types__as_Cons(_uniq_xs_10459, _ctx);
    kk_box_t _box_x907 = _con_x2458->head;
    kk_std_core_types__list _uniq_xx_10464 = _con_x2458->tail;
    kk_integer_t _uniq_x_10463 = kk_integer_unbox(_box_x907, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10459, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10459, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10463, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10464, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10459, _ctx);
    }
    kk_integer_t x_8_10987 = kk_integer_mul(_uniq_z_10460,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2459 = kk_integer_add(x_8_10987,_uniq_x_10463,kk_context()); /*int*/
      _uniq_xs_10459 = _uniq_xx_10464;
      _uniq_z_10460 = _x_x2459;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10460;
  }
}
 
// lifted local: d@0@0, ps@10029, piso, @spec-x10458
// specialized: std/core/list/foldl, on parameters @uniq-f@10455, using:
// @uniq-f@10455 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@7: int, d@4: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@8: int, y@3: int){
//     (std/core/int/int-add(x@8, y@3));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@7, 10)), d@4);
// }

kk_integer_t kk_std_time_parse__lift_piso_10648(kk_std_core_types__list _uniq_xs_10453, kk_integer_t _uniq_z_10454, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10453, _ctx)) {
    return _uniq_z_10454;
  }
  {
    return kk_std_time_parse__lift_piso_10649(_uniq_xs_10453, _uniq_z_10454, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10651_11137(kk_std_core_types__list _uniq_acc_10473, kk_integer_t _uniq_n_10472, kk_integer_t _uniq_x_10480, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2460 = kk_integer_add_small_const(_uniq_n_10472, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2461 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10480, _ctx), _uniq_acc_10473, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_piso_10651(_x_x2460, _x_x2461, _ctx);
}
 
// lifted local: @lift-piso@10650, d@0@0, ps@10029, piso, @spec-x10483
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10474, using:
// @uniq-p@10474 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_piso_10651_fun2463__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10473_0;
  kk_integer_t _uniq_n_10472_0;
};
static kk_box_t kk_std_time_parse__lift_piso_10651_fun2463(kk_function_t _fself, kk_box_t _b_x913, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_piso_10651_fun2463(kk_std_core_types__list _uniq_acc_10473_0, kk_integer_t _uniq_n_10472_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10651_fun2463__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_piso_10651_fun2463__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_piso_10651_fun2463, kk_context());
  _self->_uniq_acc_10473_0 = _uniq_acc_10473_0;
  _self->_uniq_n_10472_0 = _uniq_n_10472_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_piso_10651_fun2463(kk_function_t _fself, kk_box_t _b_x913, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10651_fun2463__t* _self = kk_function_as(struct kk_std_time_parse__lift_piso_10651_fun2463__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10473_0 = _self->_uniq_acc_10473_0; /* list<int> */
  kk_integer_t _uniq_n_10472_0 = _self->_uniq_n_10472_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10473_0, _ctx);kk_integer_dup(_uniq_n_10472_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10480_0_919 = kk_integer_unbox(_b_x913, _ctx); /*int*/;
  kk_std_core_types__list _x_x2464 = kk_std_time_parse__mlift_lift_piso_10651_11137(_uniq_acc_10473_0, _uniq_n_10472_0, _uniq_x_10480_0_919, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2464, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_piso_10651(kk_integer_t _uniq_n_10472_0, kk_std_core_types__list _uniq_acc_10473_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1851 = kk_integer_lte_borrow(_uniq_n_10472_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1851) {
    kk_integer_drop(_uniq_n_10472_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10473_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10473_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11458 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11458, _ctx);
      kk_box_t _x_x2462 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_piso_10651_fun2463(_uniq_acc_10473_0, _uniq_n_10472_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2462, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2465 = kk_integer_add_small_const(_uniq_n_10472_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2466 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11458, _ctx), _uniq_acc_10473_0, _ctx); /*list<10021>*/
      _uniq_n_10472_0 = _x_x2465;
      _uniq_acc_10473_0 = _x_x2466;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: d@0@0, ps@10029, piso, @spec-x10471
// specialized: std/text/parse/count, on parameters @uniq-p@10470, using:
// @uniq-p@10470 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_piso_10650(kk_integer_t _uniq_n_10469, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_piso_10651(_uniq_n_10469, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-piso@10652, d@1@0, ps@10029, piso, @spec-x10497
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10492, using:
// @uniq-f@10492 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@9: int, d@5: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@10: int, y@4: int){
//     (std/core/int/int-add(x@10, y@4));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@9, 10)), d@5);
// }

kk_integer_t kk_std_time_parse__lift_piso_10653(kk_std_core_types__list _uniq_xs_10490, kk_integer_t _uniq_z_10491, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10490, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2467 = kk_std_core_types__as_Cons(_uniq_xs_10490, _ctx);
    kk_box_t _box_x920 = _con_x2467->head;
    kk_std_core_types__list _uniq_xx_10495 = _con_x2467->tail;
    kk_integer_t _uniq_x_10494 = kk_integer_unbox(_box_x920, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10490, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10490, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10494, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10495, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10490, _ctx);
    }
    kk_integer_t x_10_10992 = kk_integer_mul(_uniq_z_10491,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2468 = kk_integer_add(x_10_10992,_uniq_x_10494,kk_context()); /*int*/
      _uniq_xs_10490 = _uniq_xx_10495;
      _uniq_z_10491 = _x_x2468;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10491;
  }
}
 
// lifted local: d@1@0, ps@10029, piso, @spec-x10489
// specialized: std/core/list/foldl, on parameters @uniq-f@10486, using:
// @uniq-f@10486 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@9: int, d@5: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@10: int, y@4: int){
//     (std/core/int/int-add(x@10, y@4));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@9, 10)), d@5);
// }

kk_integer_t kk_std_time_parse__lift_piso_10652(kk_std_core_types__list _uniq_xs_10484, kk_integer_t _uniq_z_10485, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10484, _ctx)) {
    return _uniq_z_10485;
  }
  {
    return kk_std_time_parse__lift_piso_10653(_uniq_xs_10484, _uniq_z_10485, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10655_11138(kk_std_core_types__list _uniq_acc_10504, kk_integer_t _uniq_n_10503, kk_integer_t _uniq_x_10511, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2469 = kk_integer_add_small_const(_uniq_n_10503, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2470 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10511, _ctx), _uniq_acc_10504, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_piso_10655(_x_x2469, _x_x2470, _ctx);
}
 
// lifted local: @lift-piso@10654, d@1@0, ps@10029, piso, @spec-x10514
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10505, using:
// @uniq-p@10505 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_piso_10655_fun2472__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10504_0;
  kk_integer_t _uniq_n_10503_0;
};
static kk_box_t kk_std_time_parse__lift_piso_10655_fun2472(kk_function_t _fself, kk_box_t _b_x926, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_piso_10655_fun2472(kk_std_core_types__list _uniq_acc_10504_0, kk_integer_t _uniq_n_10503_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10655_fun2472__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_piso_10655_fun2472__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_piso_10655_fun2472, kk_context());
  _self->_uniq_acc_10504_0 = _uniq_acc_10504_0;
  _self->_uniq_n_10503_0 = _uniq_n_10503_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_piso_10655_fun2472(kk_function_t _fself, kk_box_t _b_x926, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10655_fun2472__t* _self = kk_function_as(struct kk_std_time_parse__lift_piso_10655_fun2472__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10504_0 = _self->_uniq_acc_10504_0; /* list<int> */
  kk_integer_t _uniq_n_10503_0 = _self->_uniq_n_10503_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10504_0, _ctx);kk_integer_dup(_uniq_n_10503_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10511_0_932 = kk_integer_unbox(_b_x926, _ctx); /*int*/;
  kk_std_core_types__list _x_x2473 = kk_std_time_parse__mlift_lift_piso_10655_11138(_uniq_acc_10504_0, _uniq_n_10503_0, _uniq_x_10511_0_932, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2473, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_piso_10655(kk_integer_t _uniq_n_10503_0, kk_std_core_types__list _uniq_acc_10504_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1849 = kk_integer_lte_borrow(_uniq_n_10503_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1849) {
    kk_integer_drop(_uniq_n_10503_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10504_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10504_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11463 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11463, _ctx);
      kk_box_t _x_x2471 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_piso_10655_fun2472(_uniq_acc_10504_0, _uniq_n_10503_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2471, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2474 = kk_integer_add_small_const(_uniq_n_10503_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2475 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11463, _ctx), _uniq_acc_10504_0, _ctx); /*list<10021>*/
      _uniq_n_10503_0 = _x_x2474;
      _uniq_acc_10504_0 = _x_x2475;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: d@1@0, ps@10029, piso, @spec-x10502
// specialized: std/text/parse/count, on parameters @uniq-p@10501, using:
// @uniq-p@10501 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_piso_10654(kk_integer_t _uniq_n_10500, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_piso_10655(_uniq_n_10500, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-piso@10656, m@0, ps@10029, piso, @spec-x10528
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10523, using:
// @uniq-f@10523 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@11: int, d@6: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@12: int, y@5: int){
//     (std/core/int/int-add(x@12, y@5));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@11, 10)), d@6);
// }

kk_integer_t kk_std_time_parse__lift_piso_10657(kk_std_core_types__list _uniq_xs_10521, kk_integer_t _uniq_z_10522, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10521, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2476 = kk_std_core_types__as_Cons(_uniq_xs_10521, _ctx);
    kk_box_t _box_x933 = _con_x2476->head;
    kk_std_core_types__list _uniq_xx_10526 = _con_x2476->tail;
    kk_integer_t _uniq_x_10525 = kk_integer_unbox(_box_x933, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10521, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10521, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10525, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10526, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10521, _ctx);
    }
    kk_integer_t x_12_10997 = kk_integer_mul(_uniq_z_10522,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2477 = kk_integer_add(x_12_10997,_uniq_x_10525,kk_context()); /*int*/
      _uniq_xs_10521 = _uniq_xx_10526;
      _uniq_z_10522 = _x_x2477;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10522;
  }
}
 
// lifted local: m@0, ps@10029, piso, @spec-x10520
// specialized: std/core/list/foldl, on parameters @uniq-f@10517, using:
// @uniq-f@10517 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@11: int, d@6: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@12: int, y@5: int){
//     (std/core/int/int-add(x@12, y@5));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@11, 10)), d@6);
// }

kk_integer_t kk_std_time_parse__lift_piso_10656(kk_std_core_types__list _uniq_xs_10515, kk_integer_t _uniq_z_10516, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10515, _ctx)) {
    return _uniq_z_10516;
  }
  {
    return kk_std_time_parse__lift_piso_10657(_uniq_xs_10515, _uniq_z_10516, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10659_11139(kk_std_core_types__list _uniq_acc_10535, kk_integer_t _uniq_n_10534, kk_integer_t _uniq_x_10542, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2478 = kk_integer_add_small_const(_uniq_n_10534, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2479 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10542, _ctx), _uniq_acc_10535, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_piso_10659(_x_x2478, _x_x2479, _ctx);
}
 
// lifted local: @lift-piso@10658, m@0, ps@10029, piso, @spec-x10545
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10536, using:
// @uniq-p@10536 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_piso_10659_fun2481__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10535_0;
  kk_integer_t _uniq_n_10534_0;
};
static kk_box_t kk_std_time_parse__lift_piso_10659_fun2481(kk_function_t _fself, kk_box_t _b_x939, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_piso_10659_fun2481(kk_std_core_types__list _uniq_acc_10535_0, kk_integer_t _uniq_n_10534_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10659_fun2481__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_piso_10659_fun2481__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_piso_10659_fun2481, kk_context());
  _self->_uniq_acc_10535_0 = _uniq_acc_10535_0;
  _self->_uniq_n_10534_0 = _uniq_n_10534_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_piso_10659_fun2481(kk_function_t _fself, kk_box_t _b_x939, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10659_fun2481__t* _self = kk_function_as(struct kk_std_time_parse__lift_piso_10659_fun2481__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10535_0 = _self->_uniq_acc_10535_0; /* list<int> */
  kk_integer_t _uniq_n_10534_0 = _self->_uniq_n_10534_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10535_0, _ctx);kk_integer_dup(_uniq_n_10534_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10542_0_945 = kk_integer_unbox(_b_x939, _ctx); /*int*/;
  kk_std_core_types__list _x_x2482 = kk_std_time_parse__mlift_lift_piso_10659_11139(_uniq_acc_10535_0, _uniq_n_10534_0, _uniq_x_10542_0_945, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2482, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_piso_10659(kk_integer_t _uniq_n_10534_0, kk_std_core_types__list _uniq_acc_10535_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1847 = kk_integer_lte_borrow(_uniq_n_10534_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1847) {
    kk_integer_drop(_uniq_n_10534_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10535_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10535_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11468 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11468, _ctx);
      kk_box_t _x_x2480 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_piso_10659_fun2481(_uniq_acc_10535_0, _uniq_n_10534_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2480, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2483 = kk_integer_add_small_const(_uniq_n_10534_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2484 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11468, _ctx), _uniq_acc_10535_0, _ctx); /*list<10021>*/
      _uniq_n_10534_0 = _x_x2483;
      _uniq_acc_10535_0 = _x_x2484;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: m@0, ps@10029, piso, @spec-x10533
// specialized: std/text/parse/count, on parameters @uniq-p@10532, using:
// @uniq-p@10532 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_piso_10658(kk_integer_t _uniq_n_10531, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_piso_10659(_uniq_n_10531, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-piso@10660, d@2@0, ps@10029, piso, @spec-x10559
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10554, using:
// @uniq-f@10554 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@13: int, d@7: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@14: int, y@6: int){
//     (std/core/int/int-add(x@14, y@6));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@13, 10)), d@7);
// }

kk_integer_t kk_std_time_parse__lift_piso_10661(kk_std_core_types__list _uniq_xs_10552, kk_integer_t _uniq_z_10553, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10552, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2485 = kk_std_core_types__as_Cons(_uniq_xs_10552, _ctx);
    kk_box_t _box_x946 = _con_x2485->head;
    kk_std_core_types__list _uniq_xx_10557 = _con_x2485->tail;
    kk_integer_t _uniq_x_10556 = kk_integer_unbox(_box_x946, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10552, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10552, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10556, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10557, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10552, _ctx);
    }
    kk_integer_t x_14_11002 = kk_integer_mul(_uniq_z_10553,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2486 = kk_integer_add(x_14_11002,_uniq_x_10556,kk_context()); /*int*/
      _uniq_xs_10552 = _uniq_xx_10557;
      _uniq_z_10553 = _x_x2486;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10553;
  }
}
 
// lifted local: d@2@0, ps@10029, piso, @spec-x10551
// specialized: std/core/list/foldl, on parameters @uniq-f@10548, using:
// @uniq-f@10548 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@13: int, d@7: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@14: int, y@6: int){
//     (std/core/int/int-add(x@14, y@6));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@13, 10)), d@7);
// }

kk_integer_t kk_std_time_parse__lift_piso_10660(kk_std_core_types__list _uniq_xs_10546, kk_integer_t _uniq_z_10547, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10546, _ctx)) {
    return _uniq_z_10547;
  }
  {
    return kk_std_time_parse__lift_piso_10661(_uniq_xs_10546, _uniq_z_10547, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10663_11140(kk_std_core_types__list _uniq_acc_10566, kk_integer_t _uniq_n_10565, kk_integer_t _uniq_x_10573, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2487 = kk_integer_add_small_const(_uniq_n_10565, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2488 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10573, _ctx), _uniq_acc_10566, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_piso_10663(_x_x2487, _x_x2488, _ctx);
}
 
// lifted local: @lift-piso@10662, d@2@0, ps@10029, piso, @spec-x10576
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10567, using:
// @uniq-p@10567 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_piso_10663_fun2490__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10566_0;
  kk_integer_t _uniq_n_10565_0;
};
static kk_box_t kk_std_time_parse__lift_piso_10663_fun2490(kk_function_t _fself, kk_box_t _b_x952, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_piso_10663_fun2490(kk_std_core_types__list _uniq_acc_10566_0, kk_integer_t _uniq_n_10565_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10663_fun2490__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_piso_10663_fun2490__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_piso_10663_fun2490, kk_context());
  _self->_uniq_acc_10566_0 = _uniq_acc_10566_0;
  _self->_uniq_n_10565_0 = _uniq_n_10565_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_piso_10663_fun2490(kk_function_t _fself, kk_box_t _b_x952, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10663_fun2490__t* _self = kk_function_as(struct kk_std_time_parse__lift_piso_10663_fun2490__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10566_0 = _self->_uniq_acc_10566_0; /* list<int> */
  kk_integer_t _uniq_n_10565_0 = _self->_uniq_n_10565_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10566_0, _ctx);kk_integer_dup(_uniq_n_10565_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10573_0_958 = kk_integer_unbox(_b_x952, _ctx); /*int*/;
  kk_std_core_types__list _x_x2491 = kk_std_time_parse__mlift_lift_piso_10663_11140(_uniq_acc_10566_0, _uniq_n_10565_0, _uniq_x_10573_0_958, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2491, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_piso_10663(kk_integer_t _uniq_n_10565_0, kk_std_core_types__list _uniq_acc_10566_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1845 = kk_integer_lte_borrow(_uniq_n_10565_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1845) {
    kk_integer_drop(_uniq_n_10565_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10566_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10566_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11473 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11473, _ctx);
      kk_box_t _x_x2489 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_piso_10663_fun2490(_uniq_acc_10566_0, _uniq_n_10565_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2489, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2492 = kk_integer_add_small_const(_uniq_n_10565_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2493 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11473, _ctx), _uniq_acc_10566_0, _ctx); /*list<10021>*/
      _uniq_n_10565_0 = _x_x2492;
      _uniq_acc_10566_0 = _x_x2493;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: d@2@0, ps@10029, piso, @spec-x10564
// specialized: std/text/parse/count, on parameters @uniq-p@10563, using:
// @uniq-p@10563 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_piso_10662(kk_integer_t _uniq_n_10562, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_piso_10663(_uniq_n_10562, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// lifted local: @lift-piso@10664, d@3@0, ps@10029, piso, @spec-x10590
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10585, using:
// @uniq-f@10585 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@15: int, d@8: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@16: int, y@7: int){
//     (std/core/int/int-add(x@16, y@7));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@15, 10)), d@8);
// }

kk_integer_t kk_std_time_parse__lift_piso_10665(kk_std_core_types__list _uniq_xs_10583, kk_integer_t _uniq_z_10584, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10583, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2494 = kk_std_core_types__as_Cons(_uniq_xs_10583, _ctx);
    kk_box_t _box_x959 = _con_x2494->head;
    kk_std_core_types__list _uniq_xx_10588 = _con_x2494->tail;
    kk_integer_t _uniq_x_10587 = kk_integer_unbox(_box_x959, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10583, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10583, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10587, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10588, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10583, _ctx);
    }
    kk_integer_t x_16_11007 = kk_integer_mul(_uniq_z_10584,(kk_integer_from_small(10)),kk_context()); /*int*/;
    { // tailcall
      kk_integer_t _x_x2495 = kk_integer_add(x_16_11007,_uniq_x_10587,kk_context()); /*int*/
      _uniq_xs_10583 = _uniq_xx_10588;
      _uniq_z_10584 = _x_x2495;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10584;
  }
}
 
// lifted local: d@3@0, ps@10029, piso, @spec-x10582
// specialized: std/core/list/foldl, on parameters @uniq-f@10579, using:
// @uniq-f@10579 = fn<(std/text/parse/parse :: (E, V) -> V)>(x@15: int, d@8: int){
//   std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(x : int, y : int) -> int,(x : int, y : int) -> (std/text/parse/parse :: (E, V) -> V) int>((fn(x@16: int, y@7: int){
//     (std/core/int/int-add(x@16, y@7));
//   }))((std/core/types/@open<(total :: E),(std/text/parse/parse :: (E, V) -> V),(int, int) -> int,(int, int) -> (std/text/parse/parse :: (E, V) -> V) int>(std/core/int/(*))(x@15, 10)), d@8);
// }

kk_integer_t kk_std_time_parse__lift_piso_10664(kk_std_core_types__list _uniq_xs_10577, kk_integer_t _uniq_z_10578, kk_context_t* _ctx) { /* (list<int>, int) -> std/text/parse/parse int */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10577, _ctx)) {
    return _uniq_z_10578;
  }
  {
    return kk_std_time_parse__lift_piso_10665(_uniq_xs_10577, _uniq_z_10578, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10667_11141(kk_std_core_types__list _uniq_acc_10597, kk_integer_t _uniq_n_10596, kk_integer_t _uniq_x_10604, kk_context_t* _ctx) { /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 
  kk_integer_t _x_x2496 = kk_integer_add_small_const(_uniq_n_10596, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2497 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(_uniq_x_10604, _ctx), _uniq_acc_10597, _ctx); /*list<10021>*/
  return kk_std_time_parse__lift_piso_10667(_x_x2496, _x_x2497, _ctx);
}
 
// lifted local: @lift-piso@10666, d@3@0, ps@10029, piso, @spec-x10607
// specialized: std/text/parse/count-acc, on parameters @uniq-p@10598, using:
// @uniq-p@10598 = std/text/parse/digit


// lift anonymous function
struct kk_std_time_parse__lift_piso_10667_fun2499__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_acc_10597_0;
  kk_integer_t _uniq_n_10596_0;
};
static kk_box_t kk_std_time_parse__lift_piso_10667_fun2499(kk_function_t _fself, kk_box_t _b_x965, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_lift_piso_10667_fun2499(kk_std_core_types__list _uniq_acc_10597_0, kk_integer_t _uniq_n_10596_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10667_fun2499__t* _self = kk_function_alloc_as(struct kk_std_time_parse__lift_piso_10667_fun2499__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__lift_piso_10667_fun2499, kk_context());
  _self->_uniq_acc_10597_0 = _uniq_acc_10597_0;
  _self->_uniq_n_10596_0 = _uniq_n_10596_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__lift_piso_10667_fun2499(kk_function_t _fself, kk_box_t _b_x965, kk_context_t* _ctx) {
  struct kk_std_time_parse__lift_piso_10667_fun2499__t* _self = kk_function_as(struct kk_std_time_parse__lift_piso_10667_fun2499__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_acc_10597_0 = _self->_uniq_acc_10597_0; /* list<int> */
  kk_integer_t _uniq_n_10596_0 = _self->_uniq_n_10596_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_acc_10597_0, _ctx);kk_integer_dup(_uniq_n_10596_0, _ctx);}, {}, _ctx)
  kk_integer_t _uniq_x_10604_0_971 = kk_integer_unbox(_b_x965, _ctx); /*int*/;
  kk_std_core_types__list _x_x2500 = kk_std_time_parse__mlift_lift_piso_10667_11141(_uniq_acc_10597_0, _uniq_n_10596_0, _uniq_x_10604_0_971, _ctx); /*list<int>*/
  return kk_std_core_types__list_box(_x_x2500, _ctx);
}

kk_std_core_types__list kk_std_time_parse__lift_piso_10667(kk_integer_t _uniq_n_10596_0, kk_std_core_types__list _uniq_acc_10597_0, kk_context_t* _ctx) { /* (int, list<int>) -> std/text/parse/parse list<int> */ 
  kk__tailcall: ;
  bool _match_x1843 = kk_integer_lte_borrow(_uniq_n_10596_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1843) {
    kk_integer_drop(_uniq_n_10596_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(_uniq_acc_10597_0, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<int>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10597_0, _ctx); /*list<int>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_integer_t x_0_11478 = kk_std_text_parse_digit(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11478, _ctx);
      kk_box_t _x_x2498 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_lift_piso_10667_fun2499(_uniq_acc_10597_0, _uniq_n_10596_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x2498, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2501 = kk_integer_add_small_const(_uniq_n_10596_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2502 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_integer_box(x_0_11478, _ctx), _uniq_acc_10597_0, _ctx); /*list<10021>*/
      _uniq_n_10596_0 = _x_x2501;
      _uniq_acc_10597_0 = _x_x2502;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: d@3@0, ps@10029, piso, @spec-x10595
// specialized: std/text/parse/count, on parameters @uniq-p@10594, using:
// @uniq-p@10594 = std/text/parse/digit

kk_std_core_types__list kk_std_time_parse__lift_piso_10666(kk_integer_t _uniq_n_10593, kk_context_t* _ctx) { /* (int) -> std/text/parse/parse list<int> */ 
  return kk_std_time_parse__lift_piso_10667(_uniq_n_10593, kk_std_core_types__new_Nil(_ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11145_fun2506__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11145_fun2506(kk_function_t _fself, kk_box_t _b_x977, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11145_fun2506(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11145_fun2506, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11145_fun2506(kk_function_t _fself, kk_box_t _b_x977, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2507;
  kk_std_core_types__list _x_x2508 = kk_std_core_types__list_unbox(_b_x977, KK_OWNED, _ctx); /*list<int>*/
  _x_x2507 = kk_std_time_parse__mlift_piso_11142(_x_x2508, _ctx); /*int*/
  return kk_integer_box(_x_x2507, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11145_fun2510__t {
  struct kk_function_s _base;
  kk_ssize_t i_11483;
};
static kk_box_t kk_std_time_parse__mlift_piso_11145_fun2510(kk_function_t _fself, kk_function_t _b_x984, kk_box_t _b_x985, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11145_fun2510(kk_ssize_t i_11483, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11145_fun2510__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11145_fun2510__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11145_fun2510, kk_context());
  _self->i_11483 = i_11483;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11145_fun2510(kk_function_t _fself, kk_function_t _b_x984, kk_box_t _b_x985, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11145_fun2510__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11145_fun2510__t*, _fself, _ctx);
  kk_ssize_t i_11483 = _self->i_11483; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11483, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11483, _b_x984, _b_x985, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11145_fun2511__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t m;
  kk_integer_t year;
};
static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11145_fun2511(kk_function_t _fself, kk_integer_t d_2, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11145_fun2511(kk_std_time_calendar__calendar calendar, kk_integer_t m, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11145_fun2511__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11145_fun2511__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11145_fun2511, kk_context());
  _self->calendar = calendar;
  _self->m = m;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11145_fun2511(kk_function_t _fself, kk_integer_t d_2, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11145_fun2511__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11145_fun2511__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t m = _self->m; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(m, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_box_t _x_x2512;
  kk_std_time_date__date _x_x2513 = kk_std_time_date__new_Date(year, m, d_2, _ctx); /*std/time/date/date*/
  _x_x2512 = kk_std_time_date__date_box(_x_x2513, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x2512, kk_std_time_calendar__calendar_box(calendar, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11145_fun2515__t {
  struct kk_function_s _base;
  kk_function_t next_11482;
};
static kk_box_t kk_std_time_parse__mlift_piso_11145_fun2515(kk_function_t _fself, kk_box_t _b_x998, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11145_fun2515(kk_function_t next_11482, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11145_fun2515__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11145_fun2515__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11145_fun2515, kk_context());
  _self->next_11482 = next_11482;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11145_fun2515(kk_function_t _fself, kk_box_t _b_x998, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11145_fun2515__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11145_fun2515__t*, _fself, _ctx);
  kk_function_t next_11482 = _self->next_11482; /* (int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_11482, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2516;
  kk_integer_t _x_x2517 = kk_integer_unbox(_b_x998, _ctx); /*int*/
  _x_x2516 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_11482, (next_11482, _x_x2517, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2516, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11145(kk_std_time_calendar__calendar calendar, kk_integer_t m, kk_integer_t year, kk_char_t wild___0, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, m : int, year : int, wild_@0 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t i_11483 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11483,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_1_11486 = kk_std_time_parse__lift_piso_10642(kk_integer_from_small(2), _ctx); /*list<int>*/;
  kk_integer_t y;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_11486, _ctx);
    kk_box_t _x_x2505 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11145_fun2506(_ctx), _ctx); /*10001*/
    y = kk_integer_unbox(_x_x2505, _ctx); /*int*/
  }
  else {
    y = kk_std_time_parse__lift_piso_10640(x_1_11486, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w,kk_context());
  kk_integer_t x_11481;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y, _ctx);
    kk_box_t _x_x2509 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11145_fun2510(i_11483, _ctx), _ctx); /*10002*/
    x_11481 = kk_integer_unbox(_x_x2509, _ctx); /*int*/
  }
  else {
    x_11481 = y; /*int*/
  }
  kk_function_t next_11482 = kk_std_time_parse__new_mlift_piso_11145_fun2511(calendar, m, year, _ctx); /*(int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar)*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11481, _ctx);
    kk_box_t _x_x2514 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11145_fun2515(next_11482, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x2514, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_11482, (next_11482, x_11481, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11147_fun2521__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11147_fun2521(kk_function_t _fself, kk_box_t _b_x1008, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11147_fun2521(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11147_fun2521, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11147_fun2521(kk_function_t _fself, kk_box_t _b_x1008, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2522;
  bool _x_x2523 = kk_bool_unbox(_b_x1008); /*bool*/
  _x_x2522 = kk_std_time_parse__mlift_piso_11144(_x_x2523, _ctx); /*char*/
  return kk_char_box(_x_x2522, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11147_fun2525__t {
  struct kk_function_s _base;
  kk_ssize_t i_11494;
};
static kk_box_t kk_std_time_parse__mlift_piso_11147_fun2525(kk_function_t _fself, kk_function_t _b_x1015, kk_box_t _b_x1016, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11147_fun2525(kk_ssize_t i_11494, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11147_fun2525__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11147_fun2525__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11147_fun2525, kk_context());
  _self->i_11494 = i_11494;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11147_fun2525(kk_function_t _fself, kk_function_t _b_x1015, kk_box_t _b_x1016, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11147_fun2525__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11147_fun2525__t*, _fself, _ctx);
  kk_ssize_t i_11494 = _self->i_11494; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11494, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11494, _b_x1015, _b_x1016, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11147_fun2527__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t m;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11147_fun2527(kk_function_t _fself, kk_box_t _b_x1025, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11147_fun2527(kk_std_time_calendar__calendar calendar, kk_integer_t m, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11147_fun2527__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11147_fun2527__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11147_fun2527, kk_context());
  _self->calendar = calendar;
  _self->m = m;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11147_fun2527(kk_function_t _fself, kk_box_t _b_x1025, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11147_fun2527__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11147_fun2527__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t m = _self->m; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(m, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_char_t wild___0_1028 = kk_char_unbox(_b_x1025, KK_OWNED, _ctx); /*char*/;
  kk_std_core_types__tuple2 _x_x2528 = kk_std_time_parse__mlift_piso_11145(calendar, m, year, wild___0_1028, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2528, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11147(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_integer_t m, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, year : int, m : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t i_11494 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11494,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11498 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_0_11496;
  kk_box_t _x_x2518;
  {
    struct kk_std_core_hnd_Ev* _con_x2519 = kk_std_core_hnd__as_Ev(ev_11498, _ctx);
    kk_box_t _box_x1001 = _con_x2519->hnd;
    int32_t m_0 = _con_x2519->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1001, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1838;
    kk_std_core_hnd__clause0 _brw_x1839 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1838 = _brw_x1839; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x1004 = _match_x1838.clause;
      _x_x2518 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1004, (_fun_unbox_x1004, m_0, ev_11498, _ctx), _ctx); /*10005*/
    }
  }
  x_0_11496 = kk_bool_unbox(_x_x2518); /*bool*/
  kk_char_t y;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2520 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11147_fun2521(_ctx), _ctx); /*10001*/
    y = kk_char_unbox(_x_x2520, KK_OWNED, _ctx); /*char*/
  }
  else {
    if (x_0_11496) {
      y = kk_std_text_parse_char('-', _ctx); /*char*/
    }
    else {
      y = '-'; /*char*/
    }
  }
  kk_evv_set(w,kk_context());
  kk_char_t x_11492;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2524 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11147_fun2525(i_11494, _ctx), _ctx); /*10002*/
    x_11492 = kk_char_unbox(_x_x2524, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_11492 = y; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2526 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11147_fun2527(calendar, m, year, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x2526, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_11145(calendar, m, year, x_11492, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11150_fun2534__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11150_fun2534(kk_function_t _fself, kk_box_t _b_x1034, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11150_fun2534(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11150_fun2534, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11150_fun2534(kk_function_t _fself, kk_box_t _b_x1034, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2535;
  kk_std_core_types__list _x_x2536 = kk_std_core_types__list_unbox(_b_x1034, KK_OWNED, _ctx); /*list<int>*/
  _x_x2535 = kk_std_time_parse__mlift_piso_11148(_x_x2536, _ctx); /*int*/
  return kk_integer_box(_x_x2535, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11150_fun2538__t {
  struct kk_function_s _base;
  kk_ssize_t i_11502;
};
static kk_box_t kk_std_time_parse__mlift_piso_11150_fun2538(kk_function_t _fself, kk_function_t _b_x1041, kk_box_t _b_x1042, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11150_fun2538(kk_ssize_t i_11502, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11150_fun2538__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11150_fun2538__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11150_fun2538, kk_context());
  _self->i_11502 = i_11502;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11150_fun2538(kk_function_t _fself, kk_function_t _b_x1041, kk_box_t _b_x1042, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11150_fun2538__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11150_fun2538__t*, _fself, _ctx);
  kk_ssize_t i_11502 = _self->i_11502; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11502, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11502, _b_x1041, _b_x1042, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11150_fun2539__t {
  struct kk_function_s _base;
  kk_integer_t w;
  kk_integer_t year;
};
static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11150_fun2539(kk_function_t _fself, kk_integer_t _c_x10880, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11150_fun2539(kk_integer_t w, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11150_fun2539__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11150_fun2539__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11150_fun2539, kk_context());
  _self->w = w;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11150_fun2539(kk_function_t _fself, kk_integer_t _c_x10880, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11150_fun2539__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11150_fun2539__t*, _fself, _ctx);
  kk_integer_t w = _self->w; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(w, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_box_t _x_x2540;
  kk_std_time_date__date _x_x2541 = kk_std_time_date__new_Date(year, w, _c_x10880, _ctx); /*std/time/date/date*/
  _x_x2540 = kk_std_time_date__date_box(_x_x2541, _ctx); /*10037*/
  kk_box_t _x_x2542;
  kk_std_time_calendar__calendar _x_x2543 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_week, _ctx); /*std/time/calendar/calendar*/
  _x_x2542 = kk_std_time_calendar__calendar_box(_x_x2543, _ctx); /*10038*/
  return kk_std_core_types__new_Tuple2(_x_x2540, _x_x2542, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11150_fun2545__t {
  struct kk_function_s _base;
  kk_function_t next_11501;
};
static kk_box_t kk_std_time_parse__mlift_piso_11150_fun2545(kk_function_t _fself, kk_box_t _b_x1055, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11150_fun2545(kk_function_t next_11501, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11150_fun2545__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11150_fun2545__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11150_fun2545, kk_context());
  _self->next_11501 = next_11501;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11150_fun2545(kk_function_t _fself, kk_box_t _b_x1055, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11150_fun2545__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11150_fun2545__t*, _fself, _ctx);
  kk_function_t next_11501 = _self->next_11501; /* (int) -> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_11501, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2546;
  kk_integer_t _x_x2547 = kk_integer_unbox(_b_x1055, _ctx); /*int*/
  _x_x2546 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_11501, (next_11501, _x_x2547, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2546, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11150(kk_integer_t w, kk_integer_t year, bool _y_x10876, kk_context_t* _ctx) { /* (w : int, year : int, bool) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_integer_t x_11500;
  if (_y_x10876) {
    kk_ssize_t i_11502 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_evv_t w_0 = kk_evv_swap_create1(i_11502,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
    kk_std_core_types__list x_1_11505 = kk_std_time_parse__lift_piso_10650(kk_integer_from_small(1), _ctx); /*list<int>*/;
    kk_integer_t y;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_1_11505, _ctx);
      kk_box_t _x_x2533 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11150_fun2534(_ctx), _ctx); /*10001*/
      y = kk_integer_unbox(_x_x2533, _ctx); /*int*/
    }
    else {
      y = kk_std_time_parse__lift_piso_10648(x_1_11505, kk_integer_from_small(0), _ctx); /*int*/
    }
    kk_evv_set(w_0,kk_context());
    if (kk_yielding(kk_context())) {
      kk_integer_drop(y, _ctx);
      kk_box_t _x_x2537 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11150_fun2538(i_11502, _ctx), _ctx); /*10002*/
      x_11500 = kk_integer_unbox(_x_x2537, _ctx); /*int*/
    }
    else {
      x_11500 = y; /*int*/
    }
  }
  else {
    x_11500 = kk_integer_from_small(1); /*int*/
  }
  kk_function_t next_11501 = kk_std_time_parse__new_mlift_piso_11150_fun2539(w, year, _ctx); /*(int) -> (std/time/date/date, std/time/calendar/calendar)*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11500, _ctx);
    kk_box_t _x_x2544 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11150_fun2545(next_11501, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x2544, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_11501, (next_11501, x_11500, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11152_fun2551__t {
  struct kk_function_s _base;
  kk_ssize_t i_11512;
};
static kk_box_t kk_std_time_parse__mlift_piso_11152_fun2551(kk_function_t _fself, kk_function_t _b_x1069, kk_box_t _b_x1070, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11152_fun2551(kk_ssize_t i_11512, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11152_fun2551__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11152_fun2551__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11152_fun2551, kk_context());
  _self->i_11512 = i_11512;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11152_fun2551(kk_function_t _fself, kk_function_t _b_x1069, kk_box_t _b_x1070, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11152_fun2551__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11152_fun2551__t*, _fself, _ctx);
  kk_ssize_t i_11512 = _self->i_11512; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11512, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11512, _b_x1069, _b_x1070, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11152_fun2553__t {
  struct kk_function_s _base;
  kk_integer_t w;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11152_fun2553(kk_function_t _fself, kk_box_t _b_x1079, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11152_fun2553(kk_integer_t w, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11152_fun2553__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11152_fun2553__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11152_fun2553, kk_context());
  _self->w = w;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11152_fun2553(kk_function_t _fself, kk_box_t _b_x1079, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11152_fun2553__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11152_fun2553__t*, _fself, _ctx);
  kk_integer_t w = _self->w; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(w, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  bool _y_x10876_1082 = kk_bool_unbox(_b_x1079); /*bool*/;
  kk_std_core_types__tuple2 _x_x2554 = kk_std_time_parse__mlift_piso_11150(w, year, _y_x10876_1082, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2554, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11152(kk_integer_t w, kk_integer_t year, kk_char_t wild___2, kk_context_t* _ctx) { /* (w : int, year : int, wild_@2 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t i_11512 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_0 = kk_evv_swap_create1(i_11512,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11514 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool y;
  kk_box_t _x_x2548;
  {
    struct kk_std_core_hnd_Ev* _con_x2549 = kk_std_core_hnd__as_Ev(ev_11514, _ctx);
    kk_box_t _box_x1058 = _con_x2549->hnd;
    int32_t m = _con_x2549->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1058, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1830;
    kk_std_core_hnd__clause0 _brw_x1831 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1830 = _brw_x1831; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x1061 = _match_x1830.clause;
      _x_x2548 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1061, (_fun_unbox_x1061, m, ev_11514, _ctx), _ctx); /*10005*/
    }
  }
  y = kk_bool_unbox(_x_x2548); /*bool*/
  kk_evv_set(w_0,kk_context());
  bool x_11510;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2550 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11152_fun2551(i_11512, _ctx), _ctx); /*10002*/
    x_11510 = kk_bool_unbox(_x_x2550); /*bool*/
  }
  else {
    x_11510 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2552 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11152_fun2553(w, year, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x2552, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_11150(w, year, x_11510, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11154_fun2558__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11154_fun2558(kk_function_t _fself, kk_box_t _b_x1090, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11154_fun2558(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11154_fun2558, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11154_fun2558(kk_function_t _fself, kk_box_t _b_x1090, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2559;
  bool _x_x2560 = kk_bool_unbox(_b_x1090); /*bool*/
  _x_x2559 = kk_std_time_parse__mlift_piso_11151(_x_x2560, _ctx); /*char*/
  return kk_char_box(_x_x2559, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11154_fun2562__t {
  struct kk_function_s _base;
  kk_ssize_t i_11518;
};
static kk_box_t kk_std_time_parse__mlift_piso_11154_fun2562(kk_function_t _fself, kk_function_t _b_x1097, kk_box_t _b_x1098, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11154_fun2562(kk_ssize_t i_11518, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11154_fun2562__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11154_fun2562__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11154_fun2562, kk_context());
  _self->i_11518 = i_11518;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11154_fun2562(kk_function_t _fself, kk_function_t _b_x1097, kk_box_t _b_x1098, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11154_fun2562__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11154_fun2562__t*, _fself, _ctx);
  kk_ssize_t i_11518 = _self->i_11518; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11518, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11518, _b_x1097, _b_x1098, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11154_fun2564__t {
  struct kk_function_s _base;
  kk_integer_t w;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11154_fun2564(kk_function_t _fself, kk_box_t _b_x1107, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11154_fun2564(kk_integer_t w, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11154_fun2564__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11154_fun2564__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11154_fun2564, kk_context());
  _self->w = w;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11154_fun2564(kk_function_t _fself, kk_box_t _b_x1107, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11154_fun2564__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11154_fun2564__t*, _fself, _ctx);
  kk_integer_t w = _self->w; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(w, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_char_t wild___2_1110 = kk_char_unbox(_b_x1107, KK_OWNED, _ctx); /*char*/;
  kk_std_core_types__tuple2 _x_x2565 = kk_std_time_parse__mlift_piso_11152(w, year, wild___2_1110, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2565, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11154(kk_integer_t year, kk_integer_t w, kk_context_t* _ctx) { /* (year : int, w : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t i_11518 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_0 = kk_evv_swap_create1(i_11518,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11522 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_0_11520;
  kk_box_t _x_x2555;
  {
    struct kk_std_core_hnd_Ev* _con_x2556 = kk_std_core_hnd__as_Ev(ev_11522, _ctx);
    kk_box_t _box_x1083 = _con_x2556->hnd;
    int32_t m = _con_x2556->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1083, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1826;
    kk_std_core_hnd__clause0 _brw_x1827 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1826 = _brw_x1827; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x1086 = _match_x1826.clause;
      _x_x2555 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1086, (_fun_unbox_x1086, m, ev_11522, _ctx), _ctx); /*10005*/
    }
  }
  x_0_11520 = kk_bool_unbox(_x_x2555); /*bool*/
  kk_char_t y;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2557 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11154_fun2558(_ctx), _ctx); /*10001*/
    y = kk_char_unbox(_x_x2557, KK_OWNED, _ctx); /*char*/
  }
  else {
    if (x_0_11520) {
      y = kk_std_text_parse_char('-', _ctx); /*char*/
    }
    else {
      y = '-'; /*char*/
    }
  }
  kk_evv_set(w_0,kk_context());
  kk_char_t x_11516;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2561 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11154_fun2562(i_11518, _ctx), _ctx); /*10002*/
    x_11516 = kk_char_unbox(_x_x2561, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_11516 = y; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2563 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11154_fun2564(w, year, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x2563, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_11152(w, year, x_11516, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11155_fun2567__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11155_fun2567(kk_function_t _fself, kk_box_t _b_x1112, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11155_fun2567(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11155_fun2567, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11155_fun2567(kk_function_t _fself, kk_box_t _b_x1112, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2568;
  kk_std_core_types__list _x_x2569 = kk_std_core_types__list_unbox(_b_x1112, KK_OWNED, _ctx); /*list<int>*/
  _x_x2568 = kk_std_time_parse__mlift_piso_11153(_x_x2569, _ctx); /*int*/
  return kk_integer_box(_x_x2568, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11155_fun2571__t {
  struct kk_function_s _base;
  kk_ssize_t i_11526;
};
static kk_box_t kk_std_time_parse__mlift_piso_11155_fun2571(kk_function_t _fself, kk_function_t _b_x1119, kk_box_t _b_x1120, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11155_fun2571(kk_ssize_t i_11526, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11155_fun2571__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11155_fun2571__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11155_fun2571, kk_context());
  _self->i_11526 = i_11526;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11155_fun2571(kk_function_t _fself, kk_function_t _b_x1119, kk_box_t _b_x1120, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11155_fun2571__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11155_fun2571__t*, _fself, _ctx);
  kk_ssize_t i_11526 = _self->i_11526; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11526, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11526, _b_x1119, _b_x1120, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11155_fun2573__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11155_fun2573(kk_function_t _fself, kk_box_t _b_x1129, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11155_fun2573(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11155_fun2573__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11155_fun2573__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11155_fun2573, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11155_fun2573(kk_function_t _fself, kk_box_t _b_x1129, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11155_fun2573__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11155_fun2573__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_integer_t w_0_1132 = kk_integer_unbox(_b_x1129, _ctx); /*int*/;
  kk_std_core_types__tuple2 _x_x2574 = kk_std_time_parse__mlift_piso_11154(year, w_0_1132, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2574, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11155(kk_integer_t year, kk_char_t wild___1, kk_context_t* _ctx) { /* (year : int, wild_@1 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t i_11526 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11526,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_1_11529 = kk_std_time_parse__lift_piso_10646(kk_integer_from_small(2), _ctx); /*list<int>*/;
  kk_integer_t y;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_11529, _ctx);
    kk_box_t _x_x2566 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11155_fun2567(_ctx), _ctx); /*10001*/
    y = kk_integer_unbox(_x_x2566, _ctx); /*int*/
  }
  else {
    y = kk_std_time_parse__lift_piso_10644(x_1_11529, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w,kk_context());
  kk_integer_t x_11524;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y, _ctx);
    kk_box_t _x_x2570 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11155_fun2571(i_11526, _ctx), _ctx); /*10002*/
    x_11524 = kk_integer_unbox(_x_x2570, _ctx); /*int*/
  }
  else {
    x_11524 = y; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11524, _ctx);
    kk_box_t _x_x2572 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11155_fun2573(year, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x2572, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_11154(year, x_11524, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11161_fun2582__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11161_fun2582(kk_function_t _fself, kk_box_t _b_x1142, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11161_fun2582(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11161_fun2582, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11161_fun2582(kk_function_t _fself, kk_box_t _b_x1142, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2583;
  kk_std_core_types__list _x_x2584 = kk_std_core_types__list_unbox(_b_x1142, KK_OWNED, _ctx); /*list<int>*/
  _x_x2583 = kk_std_time_parse__mlift_piso_11158(_x_x2584, _ctx); /*int*/
  return kk_integer_box(_x_x2583, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11161_fun2586__t {
  struct kk_function_s _base;
  kk_ssize_t i_11533;
};
static kk_box_t kk_std_time_parse__mlift_piso_11161_fun2586(kk_function_t _fself, kk_function_t _b_x1149, kk_box_t _b_x1150, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11161_fun2586(kk_ssize_t i_11533, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11161_fun2586__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11161_fun2586__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11161_fun2586, kk_context());
  _self->i_11533 = i_11533;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11161_fun2586(kk_function_t _fself, kk_function_t _b_x1149, kk_box_t _b_x1150, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11161_fun2586__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11161_fun2586__t*, _fself, _ctx);
  kk_ssize_t i_11533 = _self->i_11533; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11533, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11533, _b_x1149, _b_x1150, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11161_fun2587__t {
  struct kk_function_s _base;
  kk_integer_t m_0;
  kk_integer_t year;
};
static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11161_fun2587(kk_function_t _fself, kk_integer_t d_2_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11161_fun2587(kk_integer_t m_0, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11161_fun2587__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11161_fun2587__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11161_fun2587, kk_context());
  _self->m_0 = m_0;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11161_fun2587(kk_function_t _fself, kk_integer_t d_2_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11161_fun2587__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11161_fun2587__t*, _fself, _ctx);
  kk_integer_t m_0 = _self->m_0; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(m_0, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_box_t _x_x2588;
  kk_std_time_date__date _x_x2589 = kk_std_time_date__new_Date(year, m_0, d_2_0, _ctx); /*std/time/date/date*/
  _x_x2588 = kk_std_time_date__date_box(_x_x2589, _ctx); /*10037*/
  kk_box_t _x_x2590;
  kk_std_time_calendar__calendar _x_x2591 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_month, _ctx); /*std/time/calendar/calendar*/
  _x_x2590 = kk_std_time_calendar__calendar_box(_x_x2591, _ctx); /*10038*/
  return kk_std_core_types__new_Tuple2(_x_x2588, _x_x2590, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11161_fun2593__t {
  struct kk_function_s _base;
  kk_function_t next_11532;
};
static kk_box_t kk_std_time_parse__mlift_piso_11161_fun2593(kk_function_t _fself, kk_box_t _b_x1163, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11161_fun2593(kk_function_t next_11532, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11161_fun2593__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11161_fun2593__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11161_fun2593, kk_context());
  _self->next_11532 = next_11532;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11161_fun2593(kk_function_t _fself, kk_box_t _b_x1163, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11161_fun2593__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11161_fun2593__t*, _fself, _ctx);
  kk_function_t next_11532 = _self->next_11532; /* (int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_11532, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2594;
  kk_integer_t _x_x2595 = kk_integer_unbox(_b_x1163, _ctx); /*int*/
  _x_x2594 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_11532, (next_11532, _x_x2595, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2594, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11161(kk_integer_t m_0, kk_integer_t year, kk_char_t wild___4, kk_context_t* _ctx) { /* (m@0 : int, year : int, wild_@4 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t i_11533 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11533,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_1_11536 = kk_std_time_parse__lift_piso_10662(kk_integer_from_small(2), _ctx); /*list<int>*/;
  kk_integer_t y;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_11536, _ctx);
    kk_box_t _x_x2581 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11161_fun2582(_ctx), _ctx); /*10001*/
    y = kk_integer_unbox(_x_x2581, _ctx); /*int*/
  }
  else {
    y = kk_std_time_parse__lift_piso_10660(x_1_11536, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w,kk_context());
  kk_integer_t x_11531;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y, _ctx);
    kk_box_t _x_x2585 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11161_fun2586(i_11533, _ctx), _ctx); /*10002*/
    x_11531 = kk_integer_unbox(_x_x2585, _ctx); /*int*/
  }
  else {
    x_11531 = y; /*int*/
  }
  kk_function_t next_11532 = kk_std_time_parse__new_mlift_piso_11161_fun2587(m_0, year, _ctx); /*(int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar)*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11531, _ctx);
    kk_box_t _x_x2592 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11161_fun2593(next_11532, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x2592, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_11532, (next_11532, x_11531, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11163_fun2599__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11163_fun2599(kk_function_t _fself, kk_box_t _b_x1173, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11163_fun2599(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11163_fun2599, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11163_fun2599(kk_function_t _fself, kk_box_t _b_x1173, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2600;
  bool _x_x2601 = kk_bool_unbox(_b_x1173); /*bool*/
  _x_x2600 = kk_std_time_parse__mlift_piso_11160(_x_x2601, _ctx); /*char*/
  return kk_char_box(_x_x2600, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11163_fun2603__t {
  struct kk_function_s _base;
  kk_ssize_t i_11543;
};
static kk_box_t kk_std_time_parse__mlift_piso_11163_fun2603(kk_function_t _fself, kk_function_t _b_x1180, kk_box_t _b_x1181, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11163_fun2603(kk_ssize_t i_11543, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11163_fun2603__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11163_fun2603__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11163_fun2603, kk_context());
  _self->i_11543 = i_11543;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11163_fun2603(kk_function_t _fself, kk_function_t _b_x1180, kk_box_t _b_x1181, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11163_fun2603__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11163_fun2603__t*, _fself, _ctx);
  kk_ssize_t i_11543 = _self->i_11543; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11543, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11543, _b_x1180, _b_x1181, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11163_fun2605__t {
  struct kk_function_s _base;
  kk_integer_t m_0;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11163_fun2605(kk_function_t _fself, kk_box_t _b_x1190, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11163_fun2605(kk_integer_t m_0, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11163_fun2605__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11163_fun2605__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11163_fun2605, kk_context());
  _self->m_0 = m_0;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11163_fun2605(kk_function_t _fself, kk_box_t _b_x1190, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11163_fun2605__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11163_fun2605__t*, _fself, _ctx);
  kk_integer_t m_0 = _self->m_0; /* int */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(m_0, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_char_t wild___4_1193 = kk_char_unbox(_b_x1190, KK_OWNED, _ctx); /*char*/;
  kk_std_core_types__tuple2 _x_x2606 = kk_std_time_parse__mlift_piso_11161(m_0, year, wild___4_1193, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2606, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11163(kk_integer_t year, kk_integer_t m_0, kk_context_t* _ctx) { /* (year : int, m@0 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t i_11543 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11543,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11547 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_0_11545;
  kk_box_t _x_x2596;
  {
    struct kk_std_core_hnd_Ev* _con_x2597 = kk_std_core_hnd__as_Ev(ev_11547, _ctx);
    kk_box_t _box_x1166 = _con_x2597->hnd;
    int32_t m = _con_x2597->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1166, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1815;
    kk_std_core_hnd__clause0 _brw_x1816 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1815 = _brw_x1816; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x1169 = _match_x1815.clause;
      _x_x2596 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1169, (_fun_unbox_x1169, m, ev_11547, _ctx), _ctx); /*10005*/
    }
  }
  x_0_11545 = kk_bool_unbox(_x_x2596); /*bool*/
  kk_char_t y;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2598 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11163_fun2599(_ctx), _ctx); /*10001*/
    y = kk_char_unbox(_x_x2598, KK_OWNED, _ctx); /*char*/
  }
  else {
    if (x_0_11545) {
      y = kk_std_text_parse_char('-', _ctx); /*char*/
    }
    else {
      y = '-'; /*char*/
    }
  }
  kk_evv_set(w,kk_context());
  kk_char_t x_11541;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2602 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11163_fun2603(i_11543, _ctx), _ctx); /*10002*/
    x_11541 = kk_char_unbox(_x_x2602, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_11541 = y; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2604 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11163_fun2605(m_0, year, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x2604, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_11161(m_0, year, x_11541, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11164_fun2608__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11164_fun2608(kk_function_t _fself, kk_box_t _b_x1195, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11164_fun2608(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11164_fun2608, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11164_fun2608(kk_function_t _fself, kk_box_t _b_x1195, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2609;
  kk_std_core_types__list _x_x2610 = kk_std_core_types__list_unbox(_b_x1195, KK_OWNED, _ctx); /*list<int>*/
  _x_x2609 = kk_std_time_parse__mlift_piso_11162(_x_x2610, _ctx); /*int*/
  return kk_integer_box(_x_x2609, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11164_fun2612__t {
  struct kk_function_s _base;
  kk_ssize_t i_11551;
};
static kk_box_t kk_std_time_parse__mlift_piso_11164_fun2612(kk_function_t _fself, kk_function_t _b_x1202, kk_box_t _b_x1203, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11164_fun2612(kk_ssize_t i_11551, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11164_fun2612__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11164_fun2612__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11164_fun2612, kk_context());
  _self->i_11551 = i_11551;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11164_fun2612(kk_function_t _fself, kk_function_t _b_x1202, kk_box_t _b_x1203, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11164_fun2612__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11164_fun2612__t*, _fself, _ctx);
  kk_ssize_t i_11551 = _self->i_11551; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11551, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11551, _b_x1202, _b_x1203, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11164_fun2614__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11164_fun2614(kk_function_t _fself, kk_box_t _b_x1212, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11164_fun2614(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11164_fun2614__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11164_fun2614__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11164_fun2614, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11164_fun2614(kk_function_t _fself, kk_box_t _b_x1212, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11164_fun2614__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11164_fun2614__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_integer_t m_0_1215 = kk_integer_unbox(_b_x1212, _ctx); /*int*/;
  kk_std_core_types__tuple2 _x_x2615 = kk_std_time_parse__mlift_piso_11163(year, m_0_1215, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2615, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11164(kk_integer_t year, kk_char_t wild___3, kk_context_t* _ctx) { /* (year : int, wild_@3 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t i_11551 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11551,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_1_11554 = kk_std_time_parse__lift_piso_10658(kk_integer_from_small(2), _ctx); /*list<int>*/;
  kk_integer_t y;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_11554, _ctx);
    kk_box_t _x_x2607 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11164_fun2608(_ctx), _ctx); /*10001*/
    y = kk_integer_unbox(_x_x2607, _ctx); /*int*/
  }
  else {
    y = kk_std_time_parse__lift_piso_10656(x_1_11554, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w,kk_context());
  kk_integer_t x_11549;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y, _ctx);
    kk_box_t _x_x2611 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11164_fun2612(i_11551, _ctx), _ctx); /*10002*/
    x_11549 = kk_integer_unbox(_x_x2611, _ctx); /*int*/
  }
  else {
    x_11549 = y; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11549, _ctx);
    kk_box_t _x_x2613 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11164_fun2614(year, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x2613, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_11163(year, x_11549, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11167_fun2621__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11167_fun2621(kk_function_t _fself, kk_box_t _b_x1221, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11167_fun2621(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11167_fun2621, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11167_fun2621(kk_function_t _fself, kk_box_t _b_x1221, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2622;
  kk_std_core_types__list _x_x2623 = kk_std_core_types__list_unbox(_b_x1221, KK_OWNED, _ctx); /*list<int>*/
  _x_x2622 = kk_std_time_parse__mlift_piso_11165(_x_x2623, _ctx); /*int*/
  return kk_integer_box(_x_x2622, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11167_fun2625__t {
  struct kk_function_s _base;
  kk_ssize_t i_11558;
};
static kk_box_t kk_std_time_parse__mlift_piso_11167_fun2625(kk_function_t _fself, kk_function_t _b_x1228, kk_box_t _b_x1229, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11167_fun2625(kk_ssize_t i_11558, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11167_fun2625__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11167_fun2625__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11167_fun2625, kk_context());
  _self->i_11558 = i_11558;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11167_fun2625(kk_function_t _fself, kk_function_t _b_x1228, kk_box_t _b_x1229, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11167_fun2625__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11167_fun2625__t*, _fself, _ctx);
  kk_ssize_t i_11558 = _self->i_11558; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11558, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11558, _b_x1228, _b_x1229, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11167_fun2626__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11167_fun2626(kk_function_t _fself, kk_integer_t d_3_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11167_fun2626(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11167_fun2626__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11167_fun2626__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11167_fun2626, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11167_fun2626(kk_function_t _fself, kk_integer_t d_3_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11167_fun2626__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11167_fun2626__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_box_t _x_x2627;
  kk_std_time_date__date _x_x2628 = kk_std_time_date__new_Date(year, kk_integer_from_small(1), d_3_0, _ctx); /*std/time/date/date*/
  _x_x2627 = kk_std_time_date__date_box(_x_x2628, _ctx); /*10037*/
  kk_box_t _x_x2629;
  kk_std_time_calendar__calendar _x_x2630 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_month, _ctx); /*std/time/calendar/calendar*/
  _x_x2629 = kk_std_time_calendar__calendar_box(_x_x2630, _ctx); /*10038*/
  return kk_std_core_types__new_Tuple2(_x_x2627, _x_x2629, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11167_fun2632__t {
  struct kk_function_s _base;
  kk_function_t next_11557;
};
static kk_box_t kk_std_time_parse__mlift_piso_11167_fun2632(kk_function_t _fself, kk_box_t _b_x1242, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11167_fun2632(kk_function_t next_11557, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11167_fun2632__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11167_fun2632__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11167_fun2632, kk_context());
  _self->next_11557 = next_11557;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11167_fun2632(kk_function_t _fself, kk_box_t _b_x1242, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11167_fun2632__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11167_fun2632__t*, _fself, _ctx);
  kk_function_t next_11557 = _self->next_11557; /* (int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_11557, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2633;
  kk_integer_t _x_x2634 = kk_integer_unbox(_b_x1242, _ctx); /*int*/
  _x_x2633 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_11557, (next_11557, _x_x2634, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2633, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11167(kk_integer_t year, kk_char_t wild___5, kk_context_t* _ctx) { /* (year : int, wild_@5 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_ssize_t i_11558 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11558,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_1_11561 = kk_std_time_parse__lift_piso_10666(kk_integer_from_small(3), _ctx); /*list<int>*/;
  kk_integer_t y;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_11561, _ctx);
    kk_box_t _x_x2620 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11167_fun2621(_ctx), _ctx); /*10001*/
    y = kk_integer_unbox(_x_x2620, _ctx); /*int*/
  }
  else {
    y = kk_std_time_parse__lift_piso_10664(x_1_11561, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w,kk_context());
  kk_integer_t x_11556;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y, _ctx);
    kk_box_t _x_x2624 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11167_fun2625(i_11558, _ctx), _ctx); /*10002*/
    x_11556 = kk_integer_unbox(_x_x2624, _ctx); /*int*/
  }
  else {
    x_11556 = y; /*int*/
  }
  kk_function_t next_11557 = kk_std_time_parse__new_mlift_piso_11167_fun2626(year, _ctx); /*(int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar)*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11556, _ctx);
    kk_box_t _x_x2631 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11167_fun2632(next_11557, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x2631, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_11557, (next_11557, x_11556, _ctx), _ctx);
  }
}
 
// monadic lift

kk_std_time_time__time kk_std_time_parse__mlift_piso_11168(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_std_time_time__time default_4_10041, bool _y_x10905, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, default@4@10041 : std/time/time/time, bool) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  if (_y_x10905) {
    kk_datatype_ptr_dropn(default_4_10041, (KK_I32(9)), _ctx);
    return kk_std_time_parse_ptime(date, cal, _ctx);
  }
  {
    kk_std_time_date__date_drop(date, _ctx);
    kk_datatype_ptr_dropn(cal, (KK_I32(8)), _ctx);
    return default_4_10041;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11169_fun2638__t {
  struct kk_function_s _base;
  kk_ssize_t i_11567;
};
static kk_box_t kk_std_time_parse__mlift_piso_11169_fun2638(kk_function_t _fself, kk_function_t _b_x1256, kk_box_t _b_x1257, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11169_fun2638(kk_ssize_t i_11567, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11169_fun2638__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11169_fun2638__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11169_fun2638, kk_context());
  _self->i_11567 = i_11567;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11169_fun2638(kk_function_t _fself, kk_function_t _b_x1256, kk_box_t _b_x1257, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11169_fun2638__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11169_fun2638__t*, _fself, _ctx);
  kk_ssize_t i_11567 = _self->i_11567; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11567, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11567, _b_x1256, _b_x1257, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11169_fun2640__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_std_time_time__time default_4_10041;
};
static kk_box_t kk_std_time_parse__mlift_piso_11169_fun2640(kk_function_t _fself, kk_box_t _b_x1266, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11169_fun2640(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_std_time_time__time default_4_10041, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11169_fun2640__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11169_fun2640__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11169_fun2640, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->default_4_10041 = default_4_10041;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11169_fun2640(kk_function_t _fself, kk_box_t _b_x1266, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11169_fun2640__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11169_fun2640__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_std_time_time__time default_4_10041 = _self->default_4_10041; /* std/time/time/time */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_std_time_time__time_dup(default_4_10041, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2641;
  bool _y_x10905_1269 = kk_bool_unbox(_b_x1266); /*bool*/;
  if (_y_x10905_1269) {
    kk_datatype_ptr_dropn(default_4_10041, (KK_I32(9)), _ctx);
    _x_x2641 = kk_std_time_parse_ptime(date, cal, _ctx); /*std/time/time/time*/
  }
  else {
    kk_std_time_date__date_drop(date, _ctx);
    kk_datatype_ptr_dropn(cal, (KK_I32(8)), _ctx);
    _x_x2641 = default_4_10041; /*std/time/time/time*/
  }
  return kk_std_time_time__time_box(_x_x2641, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_piso_11169(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_std_time_time__time default_4_10041, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, default@4@10041 : std/time/time/time) -> <std/time/utc/utc,std/text/parse/parse> std/time/time/time */ 
  kk_ssize_t i_11567 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11567,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11569 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool y;
  kk_box_t _x_x2635;
  {
    struct kk_std_core_hnd_Ev* _con_x2636 = kk_std_core_hnd__as_Ev(ev_11569, _ctx);
    kk_box_t _box_x1245 = _con_x2636->hnd;
    int32_t m = _con_x2636->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1245, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1804;
    kk_std_core_hnd__clause0 _brw_x1805 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1804 = _brw_x1805; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x1248 = _match_x1804.clause;
      _x_x2635 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1248, (_fun_unbox_x1248, m, ev_11569, _ctx), _ctx); /*10005*/
    }
  }
  y = kk_bool_unbox(_x_x2635); /*bool*/
  kk_evv_set(w,kk_context());
  bool x_11565;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2637 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11169_fun2638(i_11567, _ctx), _ctx); /*10002*/
    x_11565 = kk_bool_unbox(_x_x2637); /*bool*/
  }
  else {
    x_11565 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2639 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11169_fun2640(cal, date, default_4_10041, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2639, KK_OWNED, _ctx);
  }
  if (x_11565) {
    kk_datatype_ptr_dropn(default_4_10041, (KK_I32(9)), _ctx);
    return kk_std_time_parse_ptime(date, cal, _ctx);
  }
  {
    kk_std_time_date__date_drop(date, _ctx);
    kk_datatype_ptr_dropn(cal, (KK_I32(8)), _ctx);
    return default_4_10041;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11170_fun2648__t {
  struct kk_function_s _base;
  kk_ssize_t i_11577;
};
static kk_box_t kk_std_time_parse__mlift_piso_11170_fun2648(kk_function_t _fself, kk_function_t _b_x1280, kk_box_t _b_x1281, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11170_fun2648(kk_ssize_t i_11577, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11170_fun2648__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11170_fun2648__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11170_fun2648, kk_context());
  _self->i_11577 = i_11577;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11170_fun2648(kk_function_t _fself, kk_function_t _b_x1280, kk_box_t _b_x1281, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11170_fun2648__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11170_fun2648__t*, _fself, _ctx);
  kk_ssize_t i_11577 = _self->i_11577; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11577, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11577, _b_x1280, _b_x1281, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11170_fun2650__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse__mlift_piso_11170_fun2650(kk_function_t _fself, kk_box_t _b_x1290, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11170_fun2650(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11170_fun2650__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11170_fun2650__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11170_fun2650, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11170_fun2650(kk_function_t _fself, kk_box_t _b_x1290, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11170_fun2650__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11170_fun2650__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_std_time_time__time default_4_10041_1293 = kk_std_time_time__time_unbox(_b_x1290, KK_OWNED, _ctx); /*std/time/time/time*/;
  kk_std_time_time__time _x_x2651 = kk_std_time_parse__mlift_piso_11169(cal, date, default_4_10041_1293, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2651, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_piso_11170(kk_std_core_types__tuple2 _c_x10902, kk_context_t* _ctx) { /* ((std/time/date/date, std/time/calendar/calendar)) -> std/time/time/time */ 
  {
    kk_box_t _box_x1271 = _c_x10902.fst;
    kk_box_t _box_x1272 = _c_x10902.snd;
    kk_std_time_date__date date = kk_std_time_date__date_unbox(_box_x1271, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar cal = kk_std_time_calendar__calendar_unbox(_box_x1272, KK_BORROWED, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2642 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_std_time_calendar__calendar_dup(cal, _ctx);
    kk_std_time_date__date_dup(date, _ctx);
    kk_std_core_types__tuple2_drop(_c_x10902, _ctx);
    kk_ssize_t i_11577 = (KK_IZ(1)); /*hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i_11577,kk_context()); /*hnd/evv<<std/time/utc/utc,std/text/parse/parse>>*/;
    kk_std_time_time__time y;
    kk_std_time_date__date _x_x2643 = kk_std_time_date__date_dup(date, _ctx); /*std/time/date/date*/
    kk_std_core_types__optional _x_x2644;
    kk_box_t _x_x2645;
    kk_std_time_calendar__calendar _x_x2646 = kk_std_time_calendar__calendar_dup(cal, _ctx); /*std/time/calendar/calendar*/
    _x_x2645 = kk_std_time_calendar__calendar_box(_x_x2646, _ctx); /*10003*/
    _x_x2644 = kk_std_core_types__new_Optional(_x_x2645, _ctx); /*? 10003*/
    y = kk_std_time_time_date_fs_time(_x_x2643, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _x_x2644, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
    kk_evv_set(w,kk_context());
    kk_std_time_time__time x_11575;
    if (kk_yielding(kk_context())) {
      kk_datatype_ptr_dropn(y, (KK_I32(9)), _ctx);
      kk_box_t _x_x2647 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11170_fun2648(i_11577, _ctx), _ctx); /*10002*/
      x_11575 = kk_std_time_time__time_unbox(_x_x2647, KK_OWNED, _ctx); /*std/time/time/time*/
    }
    else {
      x_11575 = y; /*std/time/time/time*/
    }
    if (kk_yielding(kk_context())) {
      kk_datatype_ptr_dropn(x_11575, (KK_I32(9)), _ctx);
      kk_box_t _x_x2649 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11170_fun2650(cal, date, _ctx), _ctx); /*10001*/
      return kk_std_time_time__time_unbox(_x_x2649, KK_OWNED, _ctx);
    }
    {
      return kk_std_time_parse__mlift_piso_11169(cal, date, x_11575, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2654__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2654(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2654(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2654__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2654__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2654, kk_context());
  _self->calendar = calendar;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2656__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2656(kk_function_t _fself, kk_box_t _b_x1295, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2656(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11172_fun2656, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2656(kk_function_t _fself, kk_box_t _b_x1295, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2657;
  kk_std_core_types__list _x_x2658 = kk_std_core_types__list_unbox(_b_x1295, KK_OWNED, _ctx); /*list<int>*/
  _x_x2657 = kk_std_time_parse__mlift_piso_11146(_x_x2658, _ctx); /*int*/
  return kk_integer_box(_x_x2657, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2660__t {
  struct kk_function_s _base;
  kk_ssize_t i_11581;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2660(kk_function_t _fself, kk_function_t _b_x1302, kk_box_t _b_x1303, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2660(kk_ssize_t i_11581, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2660__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2660__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2660, kk_context());
  _self->i_11581 = i_11581;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2660(kk_function_t _fself, kk_function_t _b_x1302, kk_box_t _b_x1303, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2660__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2660__t*, _fself, _ctx);
  kk_ssize_t i_11581 = _self->i_11581; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11581, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11581, _b_x1302, _b_x1303, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2663__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2663(kk_function_t _fself, kk_box_t _b_x1312, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2663(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2663__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2663__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2663, kk_context());
  _self->calendar = calendar;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2663(kk_function_t _fself, kk_box_t _b_x1312, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2663__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2663__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2664;
  kk_integer_t _x_x2665 = kk_integer_unbox(_b_x1312, _ctx); /*int*/
  _x_x2664 = kk_std_time_parse__mlift_piso_11147(calendar, year, _x_x2665, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2664, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2654(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2654__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2654__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_ssize_t i_11581 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11581,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_1_11584 = kk_std_time_parse__lift_piso_10638(kk_integer_from_small(2), _ctx); /*list<int>*/;
  kk_integer_t y;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_11584, _ctx);
    kk_box_t _x_x2655 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11172_fun2656(_ctx), _ctx); /*10001*/
    y = kk_integer_unbox(_x_x2655, _ctx); /*int*/
  }
  else {
    y = kk_std_time_parse__lift_piso_10636(x_1_11584, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w,kk_context());
  kk_integer_t x_11579;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y, _ctx);
    kk_box_t _x_x2659 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11172_fun2660(i_11581, _ctx), _ctx); /*10002*/
    x_11579 = kk_integer_unbox(_x_x2659, _ctx); /*int*/
  }
  else {
    x_11579 = y; /*int*/
  }
  kk_std_core_types__tuple2 _x_x2661;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11579, _ctx);
    kk_box_t _x_x2662 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11172_fun2663(calendar, year, _ctx), _ctx); /*10001*/
    _x_x2661 = kk_std_core_types__tuple2_unbox(_x_x2662, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2661 = kk_std_time_parse__mlift_piso_11147(calendar, year, x_11579, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2661, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2669__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2669(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2669(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2669__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2669__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2669, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2671__t {
  struct kk_function_s _base;
  kk_ssize_t i_0_11588;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2671(kk_function_t _fself, kk_function_t _b_x1318, kk_box_t _b_x1319, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2671(kk_ssize_t i_0_11588, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2671__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2671__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2671, kk_context());
  _self->i_0_11588 = i_0_11588;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2671(kk_function_t _fself, kk_function_t _b_x1318, kk_box_t _b_x1319, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2671__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2671__t*, _fself, _ctx);
  kk_ssize_t i_0_11588 = _self->i_0_11588; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_0_11588, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_0_11588, _b_x1318, _b_x1319, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2674__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2674(kk_function_t _fself, kk_box_t _b_x1328, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2674(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2674__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2674__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2674, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2674(kk_function_t _fself, kk_box_t _b_x1328, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2674__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2674__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2675;
  kk_char_t _x_x2676 = kk_char_unbox(_b_x1328, KK_OWNED, _ctx); /*char*/
  _x_x2675 = kk_std_time_parse__mlift_piso_11155(year, _x_x2676, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2675, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2669(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2669__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2669__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_ssize_t i_0_11588 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_0 = kk_evv_swap_create1(i_0_11588,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_char_t y_0 = kk_std_text_parse_char('W', _ctx); /*char*/;
  kk_evv_set(w_0,kk_context());
  kk_char_t x_2_11586;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2670 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11172_fun2671(i_0_11588, _ctx), _ctx); /*10002*/
    x_2_11586 = kk_char_unbox(_x_x2670, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_2_11586 = y_0; /*char*/
  }
  kk_std_core_types__tuple2 _x_x2672;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2673 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11172_fun2674(year, _ctx), _ctx); /*10001*/
    _x_x2672 = kk_std_core_types__tuple2_unbox(_x_x2673, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2672 = kk_std_time_parse__mlift_piso_11155(year, x_2_11586, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2672, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2680__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2680(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2680(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2680__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2680__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2680, kk_context());
  _self->calendar = calendar;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2682__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2682(kk_function_t _fself, kk_box_t _b_x1330, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2682(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11172_fun2682, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2682(kk_function_t _fself, kk_box_t _b_x1330, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2683;
  kk_std_core_types__list _x_x2684 = kk_std_core_types__list_unbox(_b_x1330, KK_OWNED, _ctx); /*list<int>*/
  _x_x2683 = kk_std_time_parse__mlift_piso_11156(_x_x2684, _ctx); /*int*/
  return kk_integer_box(_x_x2683, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2686__t {
  struct kk_function_s _base;
  kk_ssize_t i_1_11593;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2686(kk_function_t _fself, kk_function_t _b_x1337, kk_box_t _b_x1338, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2686(kk_ssize_t i_1_11593, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2686__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2686__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2686, kk_context());
  _self->i_1_11593 = i_1_11593;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2686(kk_function_t _fself, kk_function_t _b_x1337, kk_box_t _b_x1338, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2686__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2686__t*, _fself, _ctx);
  kk_ssize_t i_1_11593 = _self->i_1_11593; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_1_11593, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1_11593, _b_x1337, _b_x1338, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2687__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t year;
};
static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11172_fun2687(kk_function_t _fself, kk_integer_t d_1_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2687(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2687__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2687__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2687, kk_context());
  _self->calendar = calendar;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11172_fun2687(kk_function_t _fself, kk_integer_t d_1_0, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2687__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2687__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_box_t _x_x2688;
  kk_std_time_date__date _x_x2689 = kk_std_time_date__new_Date(year, kk_integer_from_small(1), d_1_0, _ctx); /*std/time/date/date*/
  _x_x2688 = kk_std_time_date__date_box(_x_x2689, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x2688, kk_std_time_calendar__calendar_box(calendar, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2692__t {
  struct kk_function_s _base;
  kk_function_t next_2_11592;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2692(kk_function_t _fself, kk_box_t _b_x1351, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2692(kk_function_t next_2_11592, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2692__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2692__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2692, kk_context());
  _self->next_2_11592 = next_2_11592;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2692(kk_function_t _fself, kk_box_t _b_x1351, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2692__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2692__t*, _fself, _ctx);
  kk_function_t next_2_11592 = _self->next_2_11592; /* (int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_2_11592, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2693;
  kk_integer_t _x_x2694 = kk_integer_unbox(_b_x1351, _ctx); /*int*/
  _x_x2693 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_2_11592, (next_2_11592, _x_x2694, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2693, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2680(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2680__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2680__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_ssize_t i_1_11593 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_1 = kk_evv_swap_create1(i_1_11593,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_6_11596 = kk_std_time_parse__lift_piso_10654(kk_integer_from_small(3), _ctx); /*list<int>*/;
  kk_integer_t y_1;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_6_11596, _ctx);
    kk_box_t _x_x2681 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11172_fun2682(_ctx), _ctx); /*10001*/
    y_1 = kk_integer_unbox(_x_x2681, _ctx); /*int*/
  }
  else {
    y_1 = kk_std_time_parse__lift_piso_10652(x_6_11596, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w_1,kk_context());
  kk_integer_t x_4_11591;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y_1, _ctx);
    kk_box_t _x_x2685 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11172_fun2686(i_1_11593, _ctx), _ctx); /*10002*/
    x_4_11591 = kk_integer_unbox(_x_x2685, _ctx); /*int*/
  }
  else {
    x_4_11591 = y_1; /*int*/
  }
  kk_function_t next_2_11592 = kk_std_time_parse__new_mlift_piso_11172_fun2687(calendar, year, _ctx); /*(int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar)*/;
  kk_std_core_types__tuple2 _x_x2690;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_4_11591, _ctx);
    kk_box_t _x_x2691 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11172_fun2692(next_2_11592, _ctx), _ctx); /*10001*/
    _x_x2690 = kk_std_core_types__tuple2_unbox(_x_x2691, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2690 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_2_11592, (next_2_11592, x_4_11591, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2690, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2698__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2698(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2698(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2698__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2698__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2698, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2700__t {
  struct kk_function_s _base;
  kk_ssize_t i_2_11603;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2700(kk_function_t _fself, kk_function_t _b_x1357, kk_box_t _b_x1358, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2700(kk_ssize_t i_2_11603, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2700__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2700__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2700, kk_context());
  _self->i_2_11603 = i_2_11603;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2700(kk_function_t _fself, kk_function_t _b_x1357, kk_box_t _b_x1358, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2700__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2700__t*, _fself, _ctx);
  kk_ssize_t i_2_11603 = _self->i_2_11603; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_2_11603, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2_11603, _b_x1357, _b_x1358, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2703__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2703(kk_function_t _fself, kk_box_t _b_x1367, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2703(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2703__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2703__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2703, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2703(kk_function_t _fself, kk_box_t _b_x1367, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2703__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2703__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2704;
  kk_char_t _x_x2705 = kk_char_unbox(_b_x1367, KK_OWNED, _ctx); /*char*/
  _x_x2704 = kk_std_time_parse__mlift_piso_11164(year, _x_x2705, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2704, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2698(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2698__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2698__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_ssize_t i_2_11603 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_2 = kk_evv_swap_create1(i_2_11603,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_char_t y_2 = kk_std_text_parse_char('M', _ctx); /*char*/;
  kk_evv_set(w_2,kk_context());
  kk_char_t x_7_11601;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2699 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11172_fun2700(i_2_11603, _ctx), _ctx); /*10002*/
    x_7_11601 = kk_char_unbox(_x_x2699, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_7_11601 = y_2; /*char*/
  }
  kk_std_core_types__tuple2 _x_x2701;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2702 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11172_fun2703(year, _ctx), _ctx); /*10001*/
    _x_x2701 = kk_std_core_types__tuple2_unbox(_x_x2702, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2701 = kk_std_time_parse__mlift_piso_11164(year, x_7_11601, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2701, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2707__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2707(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2707(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2707__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2707__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2707, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2709__t {
  struct kk_function_s _base;
  kk_ssize_t i_3_11608;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2709(kk_function_t _fself, kk_function_t _b_x1373, kk_box_t _b_x1374, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2709(kk_ssize_t i_3_11608, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2709__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2709__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2709, kk_context());
  _self->i_3_11608 = i_3_11608;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2709(kk_function_t _fself, kk_function_t _b_x1373, kk_box_t _b_x1374, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2709__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2709__t*, _fself, _ctx);
  kk_ssize_t i_3_11608 = _self->i_3_11608; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_3_11608, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3_11608, _b_x1373, _b_x1374, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2712__t {
  struct kk_function_s _base;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2712(kk_function_t _fself, kk_box_t _b_x1383, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2712(kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2712__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2712__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2712, kk_context());
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2712(kk_function_t _fself, kk_box_t _b_x1383, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2712__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2712__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2713;
  kk_char_t _x_x2714 = kk_char_unbox(_b_x1383, KK_OWNED, _ctx); /*char*/
  _x_x2713 = kk_std_time_parse__mlift_piso_11167(year, _x_x2714, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2713, _ctx);
}
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2707(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2707__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2707__t*, _fself, _ctx);
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_ssize_t i_3_11608 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_3 = kk_evv_swap_create1(i_3_11608,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_char_t y_3 = kk_std_text_parse_char('M', _ctx); /*char*/;
  kk_evv_set(w_3,kk_context());
  kk_char_t x_9_11606;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2708 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11172_fun2709(i_3_11608, _ctx), _ctx); /*10002*/
    x_9_11606 = kk_char_unbox(_x_x2708, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_9_11606 = y_3; /*char*/
  }
  kk_std_core_types__tuple2 _x_x2710;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2711 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11172_fun2712(year, _ctx), _ctx); /*10001*/
    _x_x2710 = kk_std_core_types__tuple2_unbox(_x_x2711, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2710 = kk_std_time_parse__mlift_piso_11167(year, x_9_11606, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2710, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2721__t {
  struct kk_function_s _base;
  kk_ssize_t i_4_11613;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2721(kk_function_t _fself, kk_function_t _b_x1436, kk_box_t _b_x1437, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2721(kk_ssize_t i_4_11613, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2721__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11172_fun2721__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11172_fun2721, kk_context());
  _self->i_4_11613 = i_4_11613;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2721(kk_function_t _fself, kk_function_t _b_x1436, kk_box_t _b_x1437, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11172_fun2721__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11172_fun2721__t*, _fself, _ctx);
  kk_ssize_t i_4_11613 = _self->i_4_11613; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_4_11613, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4_11613, _b_x1436, _b_x1437, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11172_fun2724__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2724(kk_function_t _fself, kk_box_t _b_x1448, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11172_fun2724(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11172_fun2724, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11172_fun2724(kk_function_t _fself, kk_box_t _b_x1448, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_time__time _x_x2725;
  kk_std_core_types__tuple2 _x_x2726 = kk_std_core_types__tuple2_unbox(_b_x1448, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  _x_x2725 = kk_std_time_parse__mlift_piso_11170(_x_x2726, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2725, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_piso_11172(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_char_t wild__, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, year : int, wild_ : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_std_core_types__list ps_10029;
  kk_box_t _x_x2652;
  kk_function_t _x_x2653;
  kk_std_time_calendar__calendar_dup(calendar, _ctx);
  kk_integer_dup(year, _ctx);
  _x_x2653 = kk_std_time_parse__new_mlift_piso_11172_fun2654(calendar, year, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1398*/
  _x_x2652 = kk_function_box(_x_x2653, _ctx); /*10021*/
  kk_std_core_types__list _x_x2666;
  kk_box_t _x_x2667;
  kk_function_t _x_x2668;
  kk_integer_dup(year, _ctx);
  _x_x2668 = kk_std_time_parse__new_mlift_piso_11172_fun2669(year, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1395*/
  _x_x2667 = kk_function_box(_x_x2668, _ctx); /*10021*/
  kk_std_core_types__list _x_x2677;
  kk_box_t _x_x2678;
  kk_function_t _x_x2679;
  kk_integer_dup(year, _ctx);
  _x_x2679 = kk_std_time_parse__new_mlift_piso_11172_fun2680(calendar, year, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1392*/
  _x_x2678 = kk_function_box(_x_x2679, _ctx); /*10021*/
  kk_std_core_types__list _x_x2695;
  kk_box_t _x_x2696;
  kk_function_t _x_x2697;
  kk_integer_dup(year, _ctx);
  _x_x2697 = kk_std_time_parse__new_mlift_piso_11172_fun2698(year, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1389*/
  _x_x2696 = kk_function_box(_x_x2697, _ctx); /*10021*/
  kk_std_core_types__list _x_x2706 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse__new_mlift_piso_11172_fun2707(year, _ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x2695 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2696, _x_x2706, _ctx); /*list<10021>*/
  _x_x2677 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2678, _x_x2695, _ctx); /*list<10021>*/
  _x_x2666 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2667, _x_x2677, _ctx); /*list<10021>*/
  ps_10029 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2652, _x_x2666, _ctx); /*list<std/text/parse/parser<std/time/utc/utc,(std/time/date/date, std/time/calendar/calendar)>>*/
  kk_std_core_types__tuple2 x_11_11611;
  if (kk_std_core_types__is_Nil(ps_10029, _ctx)) {
    kk_ssize_t i_4_11613 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_evv_t w_4 = kk_evv_swap_create1(i_4_11613,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
    kk_std_core_hnd__ev ev_11616 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_std_core_types__tuple2 y_4;
    kk_box_t _x_x2715;
    {
      struct kk_std_core_hnd_Ev* _con_x2716 = kk_std_core_hnd__as_Ev(ev_11616, _ctx);
      kk_box_t _box_x1423 = _con_x2716->hnd;
      int32_t m_0 = _con_x2716->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1423, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x1786;
      kk_std_core_hnd__clause1 _brw_x1787 = kk_std_text_parse_fail_fs__select(h, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
      _match_x1786 = _brw_x1787; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x1427 = _match_x1786.clause;
        kk_box_t _x_x2717;
        kk_string_t _x_x2718;
        kk_define_string_literal(, _s_x2719, 23, "no further alternatives", _ctx)
        _x_x2718 = kk_string_dup(_s_x2719, _ctx); /*string*/
        _x_x2717 = kk_string_box(_x_x2718); /*10009*/
        _x_x2715 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1427, (_fun_unbox_x1427, m_0, ev_11616, _x_x2717, _ctx), _ctx); /*10010*/
      }
    }
    y_4 = kk_std_core_types__tuple2_unbox(_x_x2715, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
    kk_evv_set(w_4,kk_context());
    if (kk_yielding(kk_context())) {
      kk_std_core_types__tuple2_drop(y_4, _ctx);
      kk_box_t _x_x2720 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11172_fun2721(i_4_11613, _ctx), _ctx); /*10002*/
      x_11_11611 = kk_std_core_types__tuple2_unbox(_x_x2720, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
    }
    else {
      x_11_11611 = y_4; /*(std/time/date/date, std/time/calendar/calendar)*/
    }
  }
  else {
    kk_box_t _x_x2722 = kk_std_text_parse__unroll_choose_10000(ps_10029, _ctx); /*10000*/
    x_11_11611 = kk_std_core_types__tuple2_unbox(_x_x2722, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2_drop(x_11_11611, _ctx);
    kk_box_t _x_x2723 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11172_fun2724(_ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2723, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_11170(x_11_11611, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11174_fun2730__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse__mlift_piso_11174_fun2730(kk_function_t _fself, kk_box_t _b_x1458, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11174_fun2730(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_piso_11174_fun2730, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11174_fun2730(kk_function_t _fself, kk_box_t _b_x1458, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2731;
  bool _x_x2732 = kk_bool_unbox(_b_x1458); /*bool*/
  _x_x2731 = kk_std_time_parse__mlift_piso_11171(_x_x2732, _ctx); /*char*/
  return kk_char_box(_x_x2731, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11174_fun2734__t {
  struct kk_function_s _base;
  kk_ssize_t i_11621;
};
static kk_box_t kk_std_time_parse__mlift_piso_11174_fun2734(kk_function_t _fself, kk_function_t _b_x1465, kk_box_t _b_x1466, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11174_fun2734(kk_ssize_t i_11621, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11174_fun2734__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11174_fun2734__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11174_fun2734, kk_context());
  _self->i_11621 = i_11621;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11174_fun2734(kk_function_t _fself, kk_function_t _b_x1465, kk_box_t _b_x1466, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11174_fun2734__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11174_fun2734__t*, _fself, _ctx);
  kk_ssize_t i_11621 = _self->i_11621; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11621, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11621, _b_x1465, _b_x1466, _ctx);
}


// lift anonymous function
struct kk_std_time_parse__mlift_piso_11174_fun2736__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t year;
};
static kk_box_t kk_std_time_parse__mlift_piso_11174_fun2736(kk_function_t _fself, kk_box_t _b_x1475, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse__new_mlift_piso_11174_fun2736(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11174_fun2736__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_11174_fun2736__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_11174_fun2736, kk_context());
  _self->calendar = calendar;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse__mlift_piso_11174_fun2736(kk_function_t _fself, kk_box_t _b_x1475, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_11174_fun2736__t* _self = kk_function_as(struct kk_std_time_parse__mlift_piso_11174_fun2736__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_char_t wild___1478 = kk_char_unbox(_b_x1475, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x2737 = kk_std_time_parse__mlift_piso_11172(calendar, year, wild___1478, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2737, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_piso_11174(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, year : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t i_11621 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11621,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_hnd__ev ev_11625 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_0_11623;
  kk_box_t _x_x2727;
  {
    struct kk_std_core_hnd_Ev* _con_x2728 = kk_std_core_hnd__as_Ev(ev_11625, _ctx);
    kk_box_t _box_x1451 = _con_x2728->hnd;
    int32_t m = _con_x2728->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1451, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1782;
    kk_std_core_hnd__clause0 _brw_x1783 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1782 = _brw_x1783; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x1454 = _match_x1782.clause;
      _x_x2727 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1454, (_fun_unbox_x1454, m, ev_11625, _ctx), _ctx); /*10005*/
    }
  }
  x_0_11623 = kk_bool_unbox(_x_x2727); /*bool*/
  kk_char_t y;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2729 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11174_fun2730(_ctx), _ctx); /*10001*/
    y = kk_char_unbox(_x_x2729, KK_OWNED, _ctx); /*char*/
  }
  else {
    if (x_0_11623) {
      y = kk_std_text_parse_char('-', _ctx); /*char*/
    }
    else {
      y = '-'; /*char*/
    }
  }
  kk_evv_set(w,kk_context());
  kk_char_t x_11619;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2733 = kk_std_core_hnd_yield_cont(kk_std_time_parse__new_mlift_piso_11174_fun2734(i_11621, _ctx), _ctx); /*10002*/
    x_11619 = kk_char_unbox(_x_x2733, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_11619 = y; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2735 = kk_std_core_hnd_yield_extend(kk_std_time_parse__new_mlift_piso_11174_fun2736(calendar, year, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2735, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_parse__mlift_piso_11172(calendar, year, x_11619, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2739__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2739(kk_function_t _fself, kk_box_t _b_x1480, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2739(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2739, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2739(kk_function_t _fself, kk_box_t _b_x1480, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2740;
  kk_std_core_types__list _x_x2741 = kk_std_core_types__list_unbox(_b_x1480, KK_OWNED, _ctx); /*list<int>*/
  _x_x2740 = kk_std_time_parse__mlift_piso_11173(_x_x2741, _ctx); /*int*/
  return kk_integer_box(_x_x2740, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2743__t {
  struct kk_function_s _base;
  kk_ssize_t i_11630;
};
static kk_box_t kk_std_time_parse_piso_fun2743(kk_function_t _fself, kk_function_t _b_x1487, kk_box_t _b_x1488, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2743(kk_ssize_t i_11630, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2743__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2743__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2743, kk_context());
  _self->i_11630 = i_11630;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2743(kk_function_t _fself, kk_function_t _b_x1487, kk_box_t _b_x1488, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2743__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2743__t*, _fself, _ctx);
  kk_ssize_t i_11630 = _self->i_11630; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11630, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11630, _b_x1487, _b_x1488, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2745__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
};
static kk_box_t kk_std_time_parse_piso_fun2745(kk_function_t _fself, kk_box_t _b_x1497, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2745(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2745__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2745__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2745, kk_context());
  _self->calendar = calendar;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2745(kk_function_t _fself, kk_box_t _b_x1497, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2745__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2745__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);}, {}, _ctx)
  kk_integer_t year_1730 = kk_integer_unbox(_b_x1497, _ctx); /*int*/;
  kk_std_time_time__time _x_x2746 = kk_std_time_parse__mlift_piso_11174(calendar, year_1730, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2746, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2750__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2750(kk_function_t _fself, kk_box_t _b_x1505, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2750(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2750, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2750(kk_function_t _fself, kk_box_t _b_x1505, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2751;
  bool _x_x2752 = kk_bool_unbox(_b_x1505); /*bool*/
  _x_x2751 = kk_std_time_parse__mlift_piso_11171(_x_x2752, _ctx); /*char*/
  return kk_char_box(_x_x2751, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2754__t {
  struct kk_function_s _base;
  kk_ssize_t i_0_11638;
};
static kk_box_t kk_std_time_parse_piso_fun2754(kk_function_t _fself, kk_function_t _b_x1512, kk_box_t _b_x1513, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2754(kk_ssize_t i_0_11638, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2754__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2754__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2754, kk_context());
  _self->i_0_11638 = i_0_11638;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2754(kk_function_t _fself, kk_function_t _b_x1512, kk_box_t _b_x1513, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2754__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2754__t*, _fself, _ctx);
  kk_ssize_t i_0_11638 = _self->i_0_11638; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_0_11638, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_0_11638, _b_x1512, _b_x1513, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2756__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t x_11627;
};
static kk_box_t kk_std_time_parse_piso_fun2756(kk_function_t _fself, kk_box_t _b_x1522, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2756(kk_std_time_calendar__calendar calendar, kk_integer_t x_11627, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2756__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2756__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2756, kk_context());
  _self->calendar = calendar;
  _self->x_11627 = x_11627;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2756(kk_function_t _fself, kk_box_t _b_x1522, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2756__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2756__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t x_11627 = _self->x_11627; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(x_11627, _ctx);}, {}, _ctx)
  kk_char_t wild___1731 = kk_char_unbox(_b_x1522, KK_OWNED, _ctx); /*char*/;
  kk_std_time_time__time _x_x2757 = kk_std_time_parse__mlift_piso_11172(calendar, x_11627, wild___1731, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2757, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2760__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t x_11627;
};
static kk_box_t kk_std_time_parse_piso_fun2760(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2760(kk_std_time_calendar__calendar calendar, kk_integer_t x_11627, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2760__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2760__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2760, kk_context());
  _self->calendar = calendar;
  _self->x_11627 = x_11627;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2762__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2762(kk_function_t _fself, kk_box_t _b_x1524, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2762(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2762, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2762(kk_function_t _fself, kk_box_t _b_x1524, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2763;
  kk_std_core_types__list _x_x2764 = kk_std_core_types__list_unbox(_b_x1524, KK_OWNED, _ctx); /*list<int>*/
  _x_x2763 = kk_std_time_parse__mlift_piso_11146(_x_x2764, _ctx); /*int*/
  return kk_integer_box(_x_x2763, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2766__t {
  struct kk_function_s _base;
  kk_ssize_t i_1_11646;
};
static kk_box_t kk_std_time_parse_piso_fun2766(kk_function_t _fself, kk_function_t _b_x1531, kk_box_t _b_x1532, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2766(kk_ssize_t i_1_11646, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2766__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2766__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2766, kk_context());
  _self->i_1_11646 = i_1_11646;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2766(kk_function_t _fself, kk_function_t _b_x1531, kk_box_t _b_x1532, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2766__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2766__t*, _fself, _ctx);
  kk_ssize_t i_1_11646 = _self->i_1_11646; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_1_11646, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1_11646, _b_x1531, _b_x1532, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2769__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t x_11627;
};
static kk_box_t kk_std_time_parse_piso_fun2769(kk_function_t _fself, kk_box_t _b_x1541, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2769(kk_std_time_calendar__calendar calendar, kk_integer_t x_11627, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2769__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2769__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2769, kk_context());
  _self->calendar = calendar;
  _self->x_11627 = x_11627;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2769(kk_function_t _fself, kk_box_t _b_x1541, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2769__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2769__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t x_11627 = _self->x_11627; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(x_11627, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2770;
  kk_integer_t _x_x2771 = kk_integer_unbox(_b_x1541, _ctx); /*int*/
  _x_x2770 = kk_std_time_parse__mlift_piso_11147(calendar, x_11627, _x_x2771, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2770, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2760(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2760__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2760__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t x_11627 = _self->x_11627; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(x_11627, _ctx);}, {}, _ctx)
  kk_ssize_t i_1_11646 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_1 = kk_evv_swap_create1(i_1_11646,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_6_11649 = kk_std_time_parse__lift_piso_10638(kk_integer_from_small(2), _ctx); /*list<int>*/;
  kk_integer_t y_1;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_6_11649, _ctx);
    kk_box_t _x_x2761 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2762(_ctx), _ctx); /*10001*/
    y_1 = kk_integer_unbox(_x_x2761, _ctx); /*int*/
  }
  else {
    y_1 = kk_std_time_parse__lift_piso_10636(x_6_11649, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w_1,kk_context());
  kk_integer_t x_4_11644;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y_1, _ctx);
    kk_box_t _x_x2765 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_piso_fun2766(i_1_11646, _ctx), _ctx); /*10002*/
    x_4_11644 = kk_integer_unbox(_x_x2765, _ctx); /*int*/
  }
  else {
    x_4_11644 = y_1; /*int*/
  }
  kk_std_core_types__tuple2 _x_x2767;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_4_11644, _ctx);
    kk_box_t _x_x2768 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2769(calendar, x_11627, _ctx), _ctx); /*10001*/
    _x_x2767 = kk_std_core_types__tuple2_unbox(_x_x2768, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2767 = kk_std_time_parse__mlift_piso_11147(calendar, x_11627, x_4_11644, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2767, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2775__t {
  struct kk_function_s _base;
  kk_integer_t x_11627;
};
static kk_box_t kk_std_time_parse_piso_fun2775(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2775(kk_integer_t x_11627, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2775__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2775__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2775, kk_context());
  _self->x_11627 = x_11627;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2777__t {
  struct kk_function_s _base;
  kk_ssize_t i_2_11653;
};
static kk_box_t kk_std_time_parse_piso_fun2777(kk_function_t _fself, kk_function_t _b_x1547, kk_box_t _b_x1548, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2777(kk_ssize_t i_2_11653, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2777__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2777__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2777, kk_context());
  _self->i_2_11653 = i_2_11653;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2777(kk_function_t _fself, kk_function_t _b_x1547, kk_box_t _b_x1548, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2777__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2777__t*, _fself, _ctx);
  kk_ssize_t i_2_11653 = _self->i_2_11653; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_2_11653, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2_11653, _b_x1547, _b_x1548, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2780__t {
  struct kk_function_s _base;
  kk_integer_t x_11627;
};
static kk_box_t kk_std_time_parse_piso_fun2780(kk_function_t _fself, kk_box_t _b_x1557, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2780(kk_integer_t x_11627, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2780__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2780__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2780, kk_context());
  _self->x_11627 = x_11627;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2780(kk_function_t _fself, kk_box_t _b_x1557, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2780__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2780__t*, _fself, _ctx);
  kk_integer_t x_11627 = _self->x_11627; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_11627, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2781;
  kk_char_t _x_x2782 = kk_char_unbox(_b_x1557, KK_OWNED, _ctx); /*char*/
  _x_x2781 = kk_std_time_parse__mlift_piso_11155(x_11627, _x_x2782, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2781, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2775(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2775__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2775__t*, _fself, _ctx);
  kk_integer_t x_11627 = _self->x_11627; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_11627, _ctx);}, {}, _ctx)
  kk_ssize_t i_2_11653 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_2 = kk_evv_swap_create1(i_2_11653,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_char_t y_2 = kk_std_text_parse_char('W', _ctx); /*char*/;
  kk_evv_set(w_2,kk_context());
  kk_char_t x_7_11651;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2776 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_piso_fun2777(i_2_11653, _ctx), _ctx); /*10002*/
    x_7_11651 = kk_char_unbox(_x_x2776, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_7_11651 = y_2; /*char*/
  }
  kk_std_core_types__tuple2 _x_x2778;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2779 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2780(x_11627, _ctx), _ctx); /*10001*/
    _x_x2778 = kk_std_core_types__tuple2_unbox(_x_x2779, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2778 = kk_std_time_parse__mlift_piso_11155(x_11627, x_7_11651, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2778, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2786__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t x_11627;
};
static kk_box_t kk_std_time_parse_piso_fun2786(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2786(kk_std_time_calendar__calendar calendar, kk_integer_t x_11627, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2786__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2786__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2786, kk_context());
  _self->calendar = calendar;
  _self->x_11627 = x_11627;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2788__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2788(kk_function_t _fself, kk_box_t _b_x1559, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2788(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2788, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2788(kk_function_t _fself, kk_box_t _b_x1559, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2789;
  kk_std_core_types__list _x_x2790 = kk_std_core_types__list_unbox(_b_x1559, KK_OWNED, _ctx); /*list<int>*/
  _x_x2789 = kk_std_time_parse__mlift_piso_11156(_x_x2790, _ctx); /*int*/
  return kk_integer_box(_x_x2789, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2792__t {
  struct kk_function_s _base;
  kk_ssize_t i_3_11658;
};
static kk_box_t kk_std_time_parse_piso_fun2792(kk_function_t _fself, kk_function_t _b_x1566, kk_box_t _b_x1567, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2792(kk_ssize_t i_3_11658, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2792__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2792__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2792, kk_context());
  _self->i_3_11658 = i_3_11658;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2792(kk_function_t _fself, kk_function_t _b_x1566, kk_box_t _b_x1567, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2792__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2792__t*, _fself, _ctx);
  kk_ssize_t i_3_11658 = _self->i_3_11658; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_3_11658, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3_11658, _b_x1566, _b_x1567, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2793__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar calendar;
  kk_integer_t x_11627;
};
static kk_std_core_types__tuple2 kk_std_time_parse_piso_fun2793(kk_function_t _fself, kk_integer_t d_1_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2793(kk_std_time_calendar__calendar calendar, kk_integer_t x_11627, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2793__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2793__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2793, kk_context());
  _self->calendar = calendar;
  _self->x_11627 = x_11627;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_parse_piso_fun2793(kk_function_t _fself, kk_integer_t d_1_0, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2793__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2793__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t x_11627 = _self->x_11627; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(x_11627, _ctx);}, {}, _ctx)
  kk_box_t _x_x2794;
  kk_std_time_date__date _x_x2795 = kk_std_time_date__new_Date(x_11627, kk_integer_from_small(1), d_1_0, _ctx); /*std/time/date/date*/
  _x_x2794 = kk_std_time_date__date_box(_x_x2795, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x2794, kk_std_time_calendar__calendar_box(calendar, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2798__t {
  struct kk_function_s _base;
  kk_function_t next_6_11657;
};
static kk_box_t kk_std_time_parse_piso_fun2798(kk_function_t _fself, kk_box_t _b_x1580, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2798(kk_function_t next_6_11657, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2798__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2798__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2798, kk_context());
  _self->next_6_11657 = next_6_11657;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2798(kk_function_t _fself, kk_box_t _b_x1580, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2798__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2798__t*, _fself, _ctx);
  kk_function_t next_6_11657 = _self->next_6_11657; /* (int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */
  kk_drop_match(_self, {kk_function_dup(next_6_11657, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2799;
  kk_integer_t _x_x2800 = kk_integer_unbox(_b_x1580, _ctx); /*int*/
  _x_x2799 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_6_11657, (next_6_11657, _x_x2800, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2799, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2786(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2786__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2786__t*, _fself, _ctx);
  kk_std_time_calendar__calendar calendar = _self->calendar; /* std/time/calendar/calendar */
  kk_integer_t x_11627 = _self->x_11627; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(calendar, _ctx);kk_integer_dup(x_11627, _ctx);}, {}, _ctx)
  kk_ssize_t i_3_11658 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_3 = kk_evv_swap_create1(i_3_11658,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_11_11661 = kk_std_time_parse__lift_piso_10654(kk_integer_from_small(3), _ctx); /*list<int>*/;
  kk_integer_t y_3;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_11_11661, _ctx);
    kk_box_t _x_x2787 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2788(_ctx), _ctx); /*10001*/
    y_3 = kk_integer_unbox(_x_x2787, _ctx); /*int*/
  }
  else {
    y_3 = kk_std_time_parse__lift_piso_10652(x_11_11661, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w_3,kk_context());
  kk_integer_t x_9_11656;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y_3, _ctx);
    kk_box_t _x_x2791 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_piso_fun2792(i_3_11658, _ctx), _ctx); /*10002*/
    x_9_11656 = kk_integer_unbox(_x_x2791, _ctx); /*int*/
  }
  else {
    x_9_11656 = y_3; /*int*/
  }
  kk_function_t next_6_11657 = kk_std_time_parse_new_piso_fun2793(calendar, x_11627, _ctx); /*(int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar)*/;
  kk_std_core_types__tuple2 _x_x2796;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_9_11656, _ctx);
    kk_box_t _x_x2797 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2798(next_6_11657, _ctx), _ctx); /*10001*/
    _x_x2796 = kk_std_core_types__tuple2_unbox(_x_x2797, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2796 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), next_6_11657, (next_6_11657, x_9_11656, _ctx), _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2796, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2804__t {
  struct kk_function_s _base;
  kk_integer_t x_11627;
};
static kk_box_t kk_std_time_parse_piso_fun2804(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2804(kk_integer_t x_11627, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2804__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2804__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2804, kk_context());
  _self->x_11627 = x_11627;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2806__t {
  struct kk_function_s _base;
  kk_ssize_t i_4_11668;
};
static kk_box_t kk_std_time_parse_piso_fun2806(kk_function_t _fself, kk_function_t _b_x1586, kk_box_t _b_x1587, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2806(kk_ssize_t i_4_11668, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2806__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2806__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2806, kk_context());
  _self->i_4_11668 = i_4_11668;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2806(kk_function_t _fself, kk_function_t _b_x1586, kk_box_t _b_x1587, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2806__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2806__t*, _fself, _ctx);
  kk_ssize_t i_4_11668 = _self->i_4_11668; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_4_11668, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4_11668, _b_x1586, _b_x1587, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2809__t {
  struct kk_function_s _base;
  kk_integer_t x_11627;
};
static kk_box_t kk_std_time_parse_piso_fun2809(kk_function_t _fself, kk_box_t _b_x1596, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2809(kk_integer_t x_11627, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2809__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2809__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2809, kk_context());
  _self->x_11627 = x_11627;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2809(kk_function_t _fself, kk_box_t _b_x1596, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2809__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2809__t*, _fself, _ctx);
  kk_integer_t x_11627 = _self->x_11627; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_11627, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2810;
  kk_char_t _x_x2811 = kk_char_unbox(_b_x1596, KK_OWNED, _ctx); /*char*/
  _x_x2810 = kk_std_time_parse__mlift_piso_11164(x_11627, _x_x2811, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2810, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2804(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2804__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2804__t*, _fself, _ctx);
  kk_integer_t x_11627 = _self->x_11627; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_11627, _ctx);}, {}, _ctx)
  kk_ssize_t i_4_11668 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_4 = kk_evv_swap_create1(i_4_11668,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_char_t y_4 = kk_std_text_parse_char('M', _ctx); /*char*/;
  kk_evv_set(w_4,kk_context());
  kk_char_t x_12_11666;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2805 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_piso_fun2806(i_4_11668, _ctx), _ctx); /*10002*/
    x_12_11666 = kk_char_unbox(_x_x2805, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_12_11666 = y_4; /*char*/
  }
  kk_std_core_types__tuple2 _x_x2807;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2808 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2809(x_11627, _ctx), _ctx); /*10001*/
    _x_x2807 = kk_std_core_types__tuple2_unbox(_x_x2808, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2807 = kk_std_time_parse__mlift_piso_11164(x_11627, x_12_11666, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2807, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2813__t {
  struct kk_function_s _base;
  kk_integer_t x_11627;
};
static kk_box_t kk_std_time_parse_piso_fun2813(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2813(kk_integer_t x_11627, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2813__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2813__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2813, kk_context());
  _self->x_11627 = x_11627;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_piso_fun2815__t {
  struct kk_function_s _base;
  kk_ssize_t i_5_11673;
};
static kk_box_t kk_std_time_parse_piso_fun2815(kk_function_t _fself, kk_function_t _b_x1602, kk_box_t _b_x1603, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2815(kk_ssize_t i_5_11673, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2815__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2815__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2815, kk_context());
  _self->i_5_11673 = i_5_11673;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2815(kk_function_t _fself, kk_function_t _b_x1602, kk_box_t _b_x1603, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2815__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2815__t*, _fself, _ctx);
  kk_ssize_t i_5_11673 = _self->i_5_11673; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_5_11673, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5_11673, _b_x1602, _b_x1603, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2818__t {
  struct kk_function_s _base;
  kk_integer_t x_11627;
};
static kk_box_t kk_std_time_parse_piso_fun2818(kk_function_t _fself, kk_box_t _b_x1612, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2818(kk_integer_t x_11627, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2818__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2818__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2818, kk_context());
  _self->x_11627 = x_11627;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2818(kk_function_t _fself, kk_box_t _b_x1612, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2818__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2818__t*, _fself, _ctx);
  kk_integer_t x_11627 = _self->x_11627; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_11627, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x2819;
  kk_char_t _x_x2820 = kk_char_unbox(_b_x1612, KK_OWNED, _ctx); /*char*/
  _x_x2819 = kk_std_time_parse__mlift_piso_11167(x_11627, _x_x2820, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  return kk_std_core_types__tuple2_box(_x_x2819, _ctx);
}
static kk_box_t kk_std_time_parse_piso_fun2813(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2813__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2813__t*, _fself, _ctx);
  kk_integer_t x_11627 = _self->x_11627; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_11627, _ctx);}, {}, _ctx)
  kk_ssize_t i_5_11673 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_5 = kk_evv_swap_create1(i_5_11673,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_char_t y_5 = kk_std_text_parse_char('M', _ctx); /*char*/;
  kk_evv_set(w_5,kk_context());
  kk_char_t x_14_11671;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2814 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_piso_fun2815(i_5_11673, _ctx), _ctx); /*10002*/
    x_14_11671 = kk_char_unbox(_x_x2814, KK_OWNED, _ctx); /*char*/
  }
  else {
    x_14_11671 = y_5; /*char*/
  }
  kk_std_core_types__tuple2 _x_x2816;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2817 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2818(x_11627, _ctx), _ctx); /*10001*/
    _x_x2816 = kk_std_core_types__tuple2_unbox(_x_x2817, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  else {
    _x_x2816 = kk_std_time_parse__mlift_piso_11167(x_11627, x_14_11671, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  }
  return kk_std_core_types__tuple2_box(_x_x2816, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2827__t {
  struct kk_function_s _base;
  kk_ssize_t i_6_11679;
};
static kk_box_t kk_std_time_parse_piso_fun2827(kk_function_t _fself, kk_function_t _b_x1665, kk_box_t _b_x1666, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2827(kk_ssize_t i_6_11679, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2827__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2827__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2827, kk_context());
  _self->i_6_11679 = i_6_11679;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2827(kk_function_t _fself, kk_function_t _b_x1665, kk_box_t _b_x1666, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2827__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2827__t*, _fself, _ctx);
  kk_ssize_t i_6_11679 = _self->i_6_11679; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_6_11679, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_6_11679, _b_x1665, _b_x1666, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2830__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_piso_fun2830(kk_function_t _fself, kk_box_t _b_x1677, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2830(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_piso_fun2830, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2830(kk_function_t _fself, kk_box_t _b_x1677, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_time__time _x_x2831;
  kk_std_core_types__tuple2 _x_x2832 = kk_std_core_types__tuple2_unbox(_b_x1677, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
  _x_x2831 = kk_std_time_parse__mlift_piso_11170(_x_x2832, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2831, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2839__t {
  struct kk_function_s _base;
  kk_ssize_t i_7_11688;
};
static kk_box_t kk_std_time_parse_piso_fun2839(kk_function_t _fself, kk_function_t _b_x1687, kk_box_t _b_x1688, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2839(kk_ssize_t i_7_11688, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2839__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2839__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2839, kk_context());
  _self->i_7_11688 = i_7_11688;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2839(kk_function_t _fself, kk_function_t _b_x1687, kk_box_t _b_x1688, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2839__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2839__t*, _fself, _ctx);
  kk_ssize_t i_7_11688 = _self->i_7_11688; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_7_11688, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_7_11688, _b_x1687, _b_x1688, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2841__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
static kk_box_t kk_std_time_parse_piso_fun2841(kk_function_t _fself, kk_box_t _b_x1697, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2841(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2841__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2841__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2841, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2841(kk_function_t _fself, kk_box_t _b_x1697, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2841__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2841__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);}, {}, _ctx)
  kk_std_time_time__time default_4_10041_1732 = kk_std_time_time__time_unbox(_b_x1697, KK_OWNED, _ctx); /*std/time/time/time*/;
  kk_std_time_time__time _x_x2842 = kk_std_time_parse__mlift_piso_11169(cal, date, default_4_10041_1732, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2842, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2846__t {
  struct kk_function_s _base;
  kk_ssize_t i_8_11693;
};
static kk_box_t kk_std_time_parse_piso_fun2846(kk_function_t _fself, kk_function_t _b_x1709, kk_box_t _b_x1710, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2846(kk_ssize_t i_8_11693, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2846__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2846__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2846, kk_context());
  _self->i_8_11693 = i_8_11693;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2846(kk_function_t _fself, kk_function_t _b_x1709, kk_box_t _b_x1710, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2846__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2846__t*, _fself, _ctx);
  kk_ssize_t i_8_11693 = _self->i_8_11693; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_8_11693, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_8_11693, _b_x1709, _b_x1710, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_piso_fun2848__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
  kk_std_time_time__time x_19_11685;
};
static kk_box_t kk_std_time_parse_piso_fun2848(kk_function_t _fself, kk_box_t _b_x1719, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_piso_fun2848(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_std_time_time__time x_19_11685, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2848__t* _self = kk_function_alloc_as(struct kk_std_time_parse_piso_fun2848__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_piso_fun2848, kk_context());
  _self->cal = cal;
  _self->date = date;
  _self->x_19_11685 = x_19_11685;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_piso_fun2848(kk_function_t _fself, kk_box_t _b_x1719, kk_context_t* _ctx) {
  struct kk_std_time_parse_piso_fun2848__t* _self = kk_function_as(struct kk_std_time_parse_piso_fun2848__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_std_time_date__date date = _self->date; /* std/time/date/date */
  kk_std_time_time__time x_19_11685 = _self->x_19_11685; /* std/time/time/time */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_std_time_date__date_dup(date, _ctx);kk_std_time_time__time_dup(x_19_11685, _ctx);}, {}, _ctx)
  bool _y_x10905_1733 = kk_bool_unbox(_b_x1719); /*bool*/;
  kk_std_time_time__time _x_x2849;
  if (_y_x10905_1733) {
    kk_datatype_ptr_dropn(x_19_11685, (KK_I32(9)), _ctx);
    _x_x2849 = kk_std_time_parse_ptime(date, cal, _ctx); /*std/time/time/time*/
  }
  else {
    kk_std_time_date__date_drop(date, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(cal, _ctx)) {
      kk_datatype_ptr_free(cal, _ctx);
    }
    else {
      kk_datatype_ptr_decref(cal, _ctx);
    }
    _x_x2849 = x_19_11685; /*std/time/time/time*/
  }
  return kk_std_time_time__time_box(_x_x2849, _ctx);
}

kk_std_time_time__time kk_std_time_parse_piso(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  kk_ssize_t i_11630 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_11630,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_core_types__list x_1_11633 = kk_std_time_parse__lift_piso_10634(kk_integer_from_small(4), _ctx); /*list<int>*/;
  kk_integer_t y;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_11633, _ctx);
    kk_box_t _x_x2738 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2739(_ctx), _ctx); /*10001*/
    y = kk_integer_unbox(_x_x2738, _ctx); /*int*/
  }
  else {
    y = kk_std_time_parse__lift_piso_10632(x_1_11633, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_evv_set(w,kk_context());
  kk_integer_t x_11627;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y, _ctx);
    kk_box_t _x_x2742 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_piso_fun2743(i_11630, _ctx), _ctx); /*10002*/
    x_11627 = kk_integer_unbox(_x_x2742, _ctx); /*int*/
  }
  else {
    x_11627 = y; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11627, _ctx);
    kk_box_t _x_x2744 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2745(calendar, _ctx), _ctx); /*10001*/
    return kk_std_time_time__time_unbox(_x_x2744, KK_OWNED, _ctx);
  }
  {
    kk_ssize_t i_0_11638 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_evv_t w_0 = kk_evv_swap_create1(i_0_11638,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
    kk_std_core_hnd__ev ev_11642 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    bool x_3_11640;
    kk_box_t _x_x2747;
    {
      struct kk_std_core_hnd_Ev* _con_x2748 = kk_std_core_hnd__as_Ev(ev_11642, _ctx);
      kk_box_t _box_x1498 = _con_x2748->hnd;
      int32_t m = _con_x2748->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1498, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x1775;
      kk_std_core_hnd__clause0 _brw_x1776 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
      _match_x1775 = _brw_x1776; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
      {
        kk_function_t _fun_unbox_x1501 = _match_x1775.clause;
        _x_x2747 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1501, (_fun_unbox_x1501, m, ev_11642, _ctx), _ctx); /*10005*/
      }
    }
    x_3_11640 = kk_bool_unbox(_x_x2747); /*bool*/
    kk_char_t y_0;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2749 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2750(_ctx), _ctx); /*10001*/
      y_0 = kk_char_unbox(_x_x2749, KK_OWNED, _ctx); /*char*/
    }
    else {
      if (x_3_11640) {
        y_0 = kk_std_text_parse_char('-', _ctx); /*char*/
      }
      else {
        y_0 = '-'; /*char*/
      }
    }
    kk_evv_set(w_0,kk_context());
    kk_char_t x_2_11635;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2753 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_piso_fun2754(i_0_11638, _ctx), _ctx); /*10002*/
      x_2_11635 = kk_char_unbox(_x_x2753, KK_OWNED, _ctx); /*char*/
    }
    else {
      x_2_11635 = y_0; /*char*/
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2755 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2756(calendar, x_11627, _ctx), _ctx); /*10001*/
      return kk_std_time_time__time_unbox(_x_x2755, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list ps_10029;
      kk_box_t _x_x2758;
      kk_function_t _x_x2759;
      kk_std_time_calendar__calendar_dup(calendar, _ctx);
      kk_integer_dup(x_11627, _ctx);
      _x_x2759 = kk_std_time_parse_new_piso_fun2760(calendar, x_11627, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1627*/
      _x_x2758 = kk_function_box(_x_x2759, _ctx); /*10021*/
      kk_std_core_types__list _x_x2772;
      kk_box_t _x_x2773;
      kk_function_t _x_x2774;
      kk_integer_dup(x_11627, _ctx);
      _x_x2774 = kk_std_time_parse_new_piso_fun2775(x_11627, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1624*/
      _x_x2773 = kk_function_box(_x_x2774, _ctx); /*10021*/
      kk_std_core_types__list _x_x2783;
      kk_box_t _x_x2784;
      kk_function_t _x_x2785;
      kk_integer_dup(x_11627, _ctx);
      _x_x2785 = kk_std_time_parse_new_piso_fun2786(calendar, x_11627, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1621*/
      _x_x2784 = kk_function_box(_x_x2785, _ctx); /*10021*/
      kk_std_core_types__list _x_x2801;
      kk_box_t _x_x2802;
      kk_function_t _x_x2803;
      kk_integer_dup(x_11627, _ctx);
      _x_x2803 = kk_std_time_parse_new_piso_fun2804(x_11627, _ctx); /*() -> <std/text/parse/parse,std/time/utc/utc> 1618*/
      _x_x2802 = kk_function_box(_x_x2803, _ctx); /*10021*/
      kk_std_core_types__list _x_x2812 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_parse_new_piso_fun2813(x_11627, _ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
      _x_x2801 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2802, _x_x2812, _ctx); /*list<10021>*/
      _x_x2783 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2784, _x_x2801, _ctx); /*list<10021>*/
      _x_x2772 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2773, _x_x2783, _ctx); /*list<10021>*/
      ps_10029 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2758, _x_x2772, _ctx); /*list<std/text/parse/parser<std/time/utc/utc,(std/time/date/date, std/time/calendar/calendar)>>*/
      kk_std_core_types__tuple2 x_16_11676;
      if (kk_std_core_types__is_Nil(ps_10029, _ctx)) {
        kk_ssize_t i_6_11679 = (KK_IZ(0)); /*hnd/ev-index*/;
        kk_evv_t w_6 = kk_evv_swap_create1(i_6_11679,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
        kk_std_core_hnd__ev ev_0_11682 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
        kk_std_core_types__tuple2 y_6;
        kk_box_t _x_x2821;
        {
          struct kk_std_core_hnd_Ev* _con_x2822 = kk_std_core_hnd__as_Ev(ev_0_11682, _ctx);
          kk_box_t _box_x1652 = _con_x2822->hnd;
          int32_t m_1 = _con_x2822->marker;
          kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x1652, KK_BORROWED, _ctx);
          kk_std_text_parse__parse_dup(h_0, _ctx);
          kk_std_core_hnd__clause1 _match_x1759;
          kk_std_core_hnd__clause1 _brw_x1760 = kk_std_text_parse_fail_fs__select(h_0, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
          kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
          _match_x1759 = _brw_x1760; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
          {
            kk_function_t _fun_unbox_x1656 = _match_x1759.clause;
            kk_box_t _x_x2823;
            kk_string_t _x_x2824;
            kk_define_string_literal(, _s_x2825, 23, "no further alternatives", _ctx)
            _x_x2824 = kk_string_dup(_s_x2825, _ctx); /*string*/
            _x_x2823 = kk_string_box(_x_x2824); /*10009*/
            _x_x2821 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1656, (_fun_unbox_x1656, m_1, ev_0_11682, _x_x2823, _ctx), _ctx); /*10010*/
          }
        }
        y_6 = kk_std_core_types__tuple2_unbox(_x_x2821, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
        kk_evv_set(w_6,kk_context());
        if (kk_yielding(kk_context())) {
          kk_std_core_types__tuple2_drop(y_6, _ctx);
          kk_box_t _x_x2826 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_piso_fun2827(i_6_11679, _ctx), _ctx); /*10002*/
          x_16_11676 = kk_std_core_types__tuple2_unbox(_x_x2826, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
        }
        else {
          x_16_11676 = y_6; /*(std/time/date/date, std/time/calendar/calendar)*/
        }
      }
      else {
        kk_box_t _x_x2828 = kk_std_text_parse__unroll_choose_10000(ps_10029, _ctx); /*10000*/
        x_16_11676 = kk_std_core_types__tuple2_unbox(_x_x2828, KK_OWNED, _ctx); /*(std/time/date/date, std/time/calendar/calendar)*/
      }
      if (kk_yielding(kk_context())) {
        kk_std_core_types__tuple2_drop(x_16_11676, _ctx);
        kk_box_t _x_x2829 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2830(_ctx), _ctx); /*10001*/
        return kk_std_time_time__time_unbox(_x_x2829, KK_OWNED, _ctx);
      }
      {
        kk_box_t _box_x1678 = x_16_11676.fst;
        kk_box_t _box_x1679 = x_16_11676.snd;
        kk_std_time_date__date date = kk_std_time_date__date_unbox(_box_x1678, KK_BORROWED, _ctx);
        kk_std_time_calendar__calendar cal = kk_std_time_calendar__calendar_unbox(_box_x1679, KK_BORROWED, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2833 = kk_std_time_calendar__as_Calendar(cal, _ctx);
        kk_string_t _pat_3_0_0 = _con_x2833->name;
        kk_string_t _pat_4_0 = _con_x2833->long_name;
        kk_string_t _pat_5_0 = _con_x2833->month_prefix;
        kk_function_t _pat_6_0_0 = _con_x2833->show_era;
        kk_function_t _pat_7_0 = _con_x2833->instant_to_dc;
        kk_function_t _pat_8_0 = _con_x2833->dc_to_instant;
        kk_function_t _pat_9_0 = _con_x2833->days_to_date;
        kk_function_t _pat_10_0 = _con_x2833->date_to_days;
        kk_std_time_calendar__calendar_dup(cal, _ctx);
        kk_std_time_date__date_dup(date, _ctx);
        kk_std_core_types__tuple2_drop(x_16_11676, _ctx);
        kk_ssize_t i_7_11688 = (KK_IZ(1)); /*hnd/ev-index*/;
        kk_evv_t w_7 = kk_evv_swap_create1(i_7_11688,kk_context()); /*hnd/evv<<std/time/utc/utc,std/text/parse/parse>>*/;
        kk_std_time_time__time y_7;
        kk_std_time_date__date _x_x2834 = kk_std_time_date__date_dup(date, _ctx); /*std/time/date/date*/
        kk_std_core_types__optional _x_x2835;
        kk_box_t _x_x2836;
        kk_std_time_calendar__calendar _x_x2837 = kk_std_time_calendar__calendar_dup(cal, _ctx); /*std/time/calendar/calendar*/
        _x_x2836 = kk_std_time_calendar__calendar_box(_x_x2837, _ctx); /*10003*/
        _x_x2835 = kk_std_core_types__new_Optional(_x_x2836, _ctx); /*? 10003*/
        y_7 = kk_std_time_time_date_fs_time(_x_x2834, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _x_x2835, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
        kk_evv_set(w_7,kk_context());
        kk_std_time_time__time x_19_11685;
        if (kk_yielding(kk_context())) {
          kk_datatype_ptr_dropn(y_7, (KK_I32(9)), _ctx);
          kk_box_t _x_x2838 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_piso_fun2839(i_7_11688, _ctx), _ctx); /*10002*/
          x_19_11685 = kk_std_time_time__time_unbox(_x_x2838, KK_OWNED, _ctx); /*std/time/time/time*/
        }
        else {
          x_19_11685 = y_7; /*std/time/time/time*/
        }
        if (kk_yielding(kk_context())) {
          kk_datatype_ptr_dropn(x_19_11685, (KK_I32(9)), _ctx);
          kk_box_t _x_x2840 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2841(cal, date, _ctx), _ctx); /*10001*/
          return kk_std_time_time__time_unbox(_x_x2840, KK_OWNED, _ctx);
        }
        {
          kk_ssize_t i_8_11693 = (KK_IZ(0)); /*hnd/ev-index*/;
          kk_evv_t w_8 = kk_evv_swap_create1(i_8_11693,kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
          kk_std_core_hnd__ev ev_1_11695 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
          bool y_8;
          kk_box_t _x_x2843;
          {
            struct kk_std_core_hnd_Ev* _con_x2844 = kk_std_core_hnd__as_Ev(ev_1_11695, _ctx);
            kk_box_t _box_x1698 = _con_x2844->hnd;
            int32_t m_2 = _con_x2844->marker;
            kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x1698, KK_BORROWED, _ctx);
            kk_std_text_parse__parse_dup(h_1, _ctx);
            kk_std_core_hnd__clause0 _match_x1755;
            kk_std_core_hnd__clause0 _brw_x1756 = kk_std_text_parse_pick_fs__select(h_1, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
            kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
            _match_x1755 = _brw_x1756; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
            {
              kk_function_t _fun_unbox_x1701 = _match_x1755.clause;
              _x_x2843 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1701, (_fun_unbox_x1701, m_2, ev_1_11695, _ctx), _ctx); /*10005*/
            }
          }
          y_8 = kk_bool_unbox(_x_x2843); /*bool*/
          kk_evv_set(w_8,kk_context());
          bool x_20_11690;
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x2845 = kk_std_core_hnd_yield_cont(kk_std_time_parse_new_piso_fun2846(i_8_11693, _ctx), _ctx); /*10002*/
            x_20_11690 = kk_bool_unbox(_x_x2845); /*bool*/
          }
          else {
            x_20_11690 = y_8; /*bool*/
          }
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x2847 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_piso_fun2848(cal, date, x_19_11685, _ctx), _ctx); /*10001*/
            return kk_std_time_time__time_unbox(_x_x2847, KK_OWNED, _ctx);
          }
          if (x_20_11690) {
            kk_datatype_ptr_dropn(x_19_11685, (KK_I32(9)), _ctx);
            return kk_std_time_parse_ptime(date, cal, _ctx);
          }
          {
            kk_std_time_date__date_drop(date, _ctx);
            if kk_likely(kk_datatype_ptr_is_unique(cal, _ctx)) {
              kk_function_drop(_pat_9_0, _ctx);
              kk_function_drop(_pat_8_0, _ctx);
              kk_function_drop(_pat_7_0, _ctx);
              kk_function_drop(_pat_6_0_0, _ctx);
              kk_string_drop(_pat_5_0, _ctx);
              kk_string_drop(_pat_4_0, _ctx);
              kk_string_drop(_pat_3_0_0, _ctx);
              kk_function_drop(_pat_10_0, _ctx);
              kk_datatype_ptr_free(cal, _ctx);
            }
            else {
              kk_datatype_ptr_decref(cal, _ctx);
            }
            return x_19_11685;
          }
        }
      }
    }
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_time_parse__mlift_parse_iso_11175(kk_std_text_parse__parse_error _y_x10910, kk_context_t* _ctx) { /* (std/text/parse/parse-error<std/time/time/time>) -> std/time/utc/utc maybe<std/time/time/time> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/time/utc/utc>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_std_text_parse__is_ParseOk(_y_x10910, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2850 = kk_std_text_parse__as_ParseOk(_y_x10910, _ctx);
    kk_box_t _box_x1734 = _con_x2850->result;
    kk_std_core_sslice__sslice _pat_0_0 = _con_x2850->rest;
    kk_std_time_time__time x_0 = kk_std_time_time__time_unbox(_box_x1734, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_y_x10910, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(_y_x10910, _ctx);
    }
    else {
      kk_std_time_time__time_dup(x_0, _ctx);
      kk_datatype_ptr_decref(_y_x10910, _ctx);
    }
    return kk_std_core_types__new_Just(kk_std_time_time__time_box(x_0, _ctx), _ctx);
  }
  {
    struct kk_std_text_parse_ParseError* _con_x2851 = kk_std_text_parse__as_ParseError(_y_x10910, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x2851->rest;
    kk_string_t msg = _con_x2851->msg;
    if kk_likely(kk_datatype_ptr_is_unique(_y_x10910, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(_y_x10910, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_y_x10910, _ctx);
    }
    return kk_std_core_types__new_Nothing(_ctx);
  }
}


// lift anonymous function
struct kk_std_time_parse_parse_iso_fun2854__t {
  struct kk_function_s _base;
  kk_std_core_types__optional calendar;
};
static kk_box_t kk_std_time_parse_parse_iso_fun2854(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_parse_iso_fun2854(kk_std_core_types__optional calendar, kk_context_t* _ctx) {
  struct kk_std_time_parse_parse_iso_fun2854__t* _self = kk_function_alloc_as(struct kk_std_time_parse_parse_iso_fun2854__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_parse_iso_fun2854, kk_context());
  _self->calendar = calendar;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_parse_parse_iso_fun2854(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_parse_parse_iso_fun2854__t* _self = kk_function_as(struct kk_std_time_parse_parse_iso_fun2854__t*, _fself, _ctx);
  kk_std_core_types__optional calendar = _self->calendar; /* ? std/time/calendar/calendar */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(calendar, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2855;
  kk_std_time_calendar__calendar _x_x2856;
  if (kk_std_core_types__is_Optional(calendar, _ctx)) {
    kk_box_t _box_x1737 = calendar._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_calendar_766 = kk_std_time_calendar__calendar_unbox(_box_x1737, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_calendar_766, _ctx);
    kk_std_core_types__optional_drop(calendar, _ctx);
    _x_x2856 = _uniq_calendar_766; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(calendar, _ctx);
    _x_x2856 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2855 = kk_std_time_parse_piso(_x_x2856, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2855, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_parse_iso_fun2858__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_parse_parse_iso_fun2858(kk_function_t _fself, kk_box_t _b_x1743, kk_context_t* _ctx);
static kk_function_t kk_std_time_parse_new_parse_iso_fun2858(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_parse_iso_fun2858, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_parse_parse_iso_fun2858(kk_function_t _fself, kk_box_t _b_x1743, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2859;
  kk_std_text_parse__parse_error _x_x2860 = kk_std_text_parse__parse_error_unbox(_b_x1743, KK_OWNED, _ctx); /*std/text/parse/parse-error<std/time/time/time>*/
  _x_x2859 = kk_std_time_parse__mlift_parse_iso_11175(_x_x2860, _ctx); /*maybe<std/time/time/time>*/
  return kk_std_core_types__maybe_box(_x_x2859, _ctx);
}

kk_std_core_types__maybe kk_std_time_parse_parse_iso(kk_string_t s, kk_std_core_types__optional calendar, kk_context_t* _ctx) { /* (s : string, calendar : ? std/time/calendar/calendar) -> std/time/utc/utc maybe<std/time/time/time> */ 
  kk_std_core_sslice__sslice _b_x1738_1740;
  kk_string_t _x_x2852 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x2853 = kk_string_len_int(s,kk_context()); /*int*/
  _b_x1738_1740 = kk_std_core_sslice__new_Sslice(_x_x2852, kk_integer_from_small(0), _x_x2853, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error x_11703 = kk_std_text_parse_parse_eof(_b_x1738_1740, kk_std_time_parse_new_parse_iso_fun2854(calendar, _ctx), _ctx); /*std/text/parse/parse-error<std/time/time/time>*/;
  if (kk_yielding(kk_context())) {
    kk_std_text_parse__parse_error_drop(x_11703, _ctx);
    kk_box_t _x_x2857 = kk_std_core_hnd_yield_extend(kk_std_time_parse_new_parse_iso_fun2858(_ctx), _ctx); /*10001*/
    return kk_std_core_types__maybe_unbox(_x_x2857, KK_OWNED, _ctx);
  }
  {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/time/utc/utc>*/;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_std_text_parse__is_ParseOk(x_11703, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x2861 = kk_std_text_parse__as_ParseOk(x_11703, _ctx);
      kk_box_t _box_x1744 = _con_x2861->result;
      kk_std_core_sslice__sslice _pat_0_0_0 = _con_x2861->rest;
      kk_std_time_time__time x_0_0 = kk_std_time_time__time_unbox(_box_x1744, KK_BORROWED, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(x_11703, _ctx)) {
        kk_std_core_sslice__sslice_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(x_11703, _ctx);
      }
      else {
        kk_std_time_time__time_dup(x_0_0, _ctx);
        kk_datatype_ptr_decref(x_11703, _ctx);
      }
      return kk_std_core_types__new_Just(kk_std_time_time__time_box(x_0_0, _ctx), _ctx);
    }
    {
      struct kk_std_text_parse_ParseError* _con_x2862 = kk_std_text_parse__as_ParseError(x_11703, _ctx);
      kk_std_core_sslice__sslice _pat_5 = _con_x2862->rest;
      kk_string_t msg = _con_x2862->msg;
      if kk_likely(kk_datatype_ptr_is_unique(x_11703, _ctx)) {
        kk_string_drop(msg, _ctx);
        kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
        kk_datatype_ptr_free(x_11703, _ctx);
      }
      else {
        kk_datatype_ptr_decref(x_11703, _ctx);
      }
      return kk_std_core_types__new_Nothing(_ctx);
    }
  }
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
