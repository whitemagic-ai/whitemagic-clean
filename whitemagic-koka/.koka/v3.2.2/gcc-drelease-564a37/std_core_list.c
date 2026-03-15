// Koka generated module: std/core/list, koka version: 3.2.2, platform: 64-bit
#include "std_core_list.h"
 
// Return the head of list if the list is not empty.

kk_std_core_types__maybe kk_std_core_list_maybe_fs_head(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1392 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1392->head;
    kk_std_core_types__list _pat_0 = _con_x1392->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__list_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    return kk_std_core_types__new_Just(x, _ctx);
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Return the head of list with a default value in case the list is empty.

kk_box_t kk_std_core_list_head(kk_std_core_types__list xs, kk_box_t kkloc_default, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, default : a) -> a */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1393 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1393->head;
    kk_std_core_types__list _pat_0 = _con_x1393->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__list_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_drop(kkloc_default, _ctx);
    return x;
  }
  {
    return kkloc_default;
  }
}
 
// Return the tail of list. Returns the empty list if `xs` is empty.

kk_std_core_types__list kk_std_core_list_tail(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1394 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _pat_0 = _con_x1394->head;
    kk_std_core_types__list xx = _con_x1394->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    return xx;
  }
  {
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// lifted local: length, len

kk_integer_t kk_std_core_list__unroll_lift_length_5730_10000(kk_std_core_types__list ys, kk_integer_t acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, acc : int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1395 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _pat_0 = _con_x1395->head;
    kk_std_core_types__list yy = _con_x1395->tail;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(ys, _ctx);
    }
    else {
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x1396 = kk_integer_add_small_const(acc, 1, _ctx); /*int*/
      ys = yy;
      acc = _x_x1396;
      goto kk__tailcall;
    }
  }
  {
    return acc;
  }
}
 
// monadic lift

bool kk_std_core_list__lp__at_mlift_unroll_x_10001_10675_eq__eq__rp_(kk_function_t _implicit_fs__lp__eq__eq__rp_, kk_std_core_types__list xx, kk_std_core_types__list yy, bool _y_x10421, kk_context_t* _ctx) { /* forall<a,e> (?(==) : (a, a) -> e bool, xx : list<a>, yy : list<a>, bool) -> e bool */ 
  if (_y_x10421) {
    return kk_std_core_list__lp__at_unroll_x_10001_eq__eq__rp_(xx, yy, _implicit_fs__lp__eq__eq__rp_, _ctx);
  }
  {
    kk_std_core_types__list_drop(yy, _ctx);
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
    return false;
  }
}
 
// Element-wise list equality


// lift anonymous function
struct kk_std_core_list__lp__at_unroll_x_10001_fun1401__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs__lp__at_x_0_eq__eq__rp_;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__lp__at_unroll_x_10001_fun1401_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__lp__at_new_unroll_x_10001_fun1401_eq__eq__rp_(kk_function_t _implicit_fs__lp__at_x_0_eq__eq__rp_, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lp__at_unroll_x_10001_fun1401__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_list__lp__at_unroll_x_10001_fun1401__t_eq__eq__rp_, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lp__at_unroll_x_10001_fun1401_eq__eq__rp_, kk_context());
  _self->_implicit_fs__lp__at_x_0_eq__eq__rp_ = _implicit_fs__lp__at_x_0_eq__eq__rp_;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lp__at_unroll_x_10001_fun1401_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx) {
  struct kk_std_core_list__lp__at_unroll_x_10001_fun1401__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_list__lp__at_unroll_x_10001_fun1401__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs__lp__at_x_0_eq__eq__rp_ = _self->_implicit_fs__lp__at_x_0_eq__eq__rp_; /* (802, 802) -> 803 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<802> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<802> */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs__lp__at_x_0_eq__eq__rp_, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  bool _y_x10421_0_3 = kk_bool_unbox(_b_x1); /*bool*/;
  bool _x_x1402 = kk_std_core_list__lp__at_mlift_unroll_x_10001_10675_eq__eq__rp_(_implicit_fs__lp__at_x_0_eq__eq__rp_, xx_0, yy_0, _y_x10421_0_3, _ctx); /*bool*/
  return kk_bool_box(_x_x1402);
}

bool kk_std_core_list__lp__at_unroll_x_10001_eq__eq__rp_(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs__lp__at_x_0_eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, ys : list<a>, ?(==) : (a, a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1397 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1397->head;
    kk_std_core_types__list xx_0 = _con_x1397->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_function_drop(_implicit_fs__lp__at_x_0_eq__eq__rp_, _ctx);
      return false;
    }
    {
      struct kk_std_core_types_Cons* _con_x1398 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1398->head;
      kk_std_core_types__list yy_0 = _con_x1398->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      bool x_0_10709;
      kk_function_t _x_x1399 = kk_function_dup(_implicit_fs__lp__at_x_0_eq__eq__rp_, _ctx); /*(802, 802) -> 803 bool*/
      x_0_10709 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1399, (_x_x1399, x, y, _ctx), _ctx); /*bool*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1400 = kk_std_core_hnd_yield_extend(kk_std_core_list__lp__at_new_unroll_x_10001_fun1401_eq__eq__rp_(_implicit_fs__lp__at_x_0_eq__eq__rp_, xx_0, yy_0, _ctx), _ctx); /*2419*/
        return kk_bool_unbox(_x_x1400);
      }
      if (x_0_10709) { // tailcall
                       xs = xx_0;
                       ys = yy_0;
                       goto kk__tailcall;
      }
      {
        kk_std_core_types__list_drop(yy_0, _ctx);
        kk_std_core_types__list_drop(xx_0, _ctx);
        kk_function_drop(_implicit_fs__lp__at_x_0_eq__eq__rp_, _ctx);
        return false;
      }
    }
  }
  {
    kk_function_drop(_implicit_fs__lp__at_x_0_eq__eq__rp_, _ctx);
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      return true;
    }
    {
      struct kk_std_core_types_Cons* _con_x1403 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t _pat_7 = _con_x1403->head;
      kk_std_core_types__list _pat_8 = _con_x1403->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_std_core_types__list_drop(_pat_8, _ctx);
        kk_box_drop(_pat_7, _ctx);
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ys, _ctx);
      }
      return false;
    }
  }
}
 
// monadic lift

kk_std_core_types__order kk_std_core_list__mlift_unroll_cmp_10002_10676(kk_function_t _implicit_fs_cmp, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_std_core_types__order _y_x10428, kk_context_t* _ctx) { /* forall<a,e> (?cmp : (a, a) -> e order, xx : list<a>, yy : list<a>, order) -> e order */ 
  if (kk_std_core_types__is_Eq(_y_x10428, _ctx)) {
    return kk_std_core_list__unroll_cmp_10002(xx, yy, _implicit_fs_cmp, _ctx);
  }
  {
    kk_std_core_types__list_drop(yy, _ctx);
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(_implicit_fs_cmp, _ctx);
    return _y_x10428;
  }
}
 
// Order on lists


// lift anonymous function
struct kk_std_core_list__unroll_cmp_10002_fun1409__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_cmp_0;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__unroll_cmp_10002_fun1409(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_cmp_10002_fun1409(kk_function_t _implicit_fs_cmp_0, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_cmp_10002_fun1409__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_cmp_10002_fun1409__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_cmp_10002_fun1409, kk_context());
  _self->_implicit_fs_cmp_0 = _implicit_fs_cmp_0;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_cmp_10002_fun1409(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_cmp_10002_fun1409__t* _self = kk_function_as(struct kk_std_core_list__unroll_cmp_10002_fun1409__t*, _fself, _ctx);
  kk_function_t _implicit_fs_cmp_0 = _self->_implicit_fs_cmp_0; /* (898, 898) -> 899 order */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<898> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<898> */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_cmp_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10428_0_7 = kk_std_core_types__order_unbox(_b_x5, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x1410 = kk_std_core_list__mlift_unroll_cmp_10002_10676(_implicit_fs_cmp_0, xx_0, yy_0, _y_x10428_0_7, _ctx); /*order*/
  return kk_std_core_types__order_box(_x_x1410, _ctx);
}

kk_std_core_types__order kk_std_core_list__unroll_cmp_10002(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs_cmp_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, ys : list<a>, ?cmp : (a, a) -> e order) -> e order */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1405 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1405->head;
    kk_std_core_types__list xx_0 = _con_x1405->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_function_drop(_implicit_fs_cmp_0, _ctx);
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      struct kk_std_core_types_Cons* _con_x1406 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1406->head;
      kk_std_core_types__list yy_0 = _con_x1406->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_std_core_types__order x_0_10712;
      kk_function_t _x_x1407 = kk_function_dup(_implicit_fs_cmp_0, _ctx); /*(898, 898) -> 899 order*/
      x_0_10712 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1407, (_x_x1407, x, y, _ctx), _ctx); /*order*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1408 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_cmp_10002_fun1409(_implicit_fs_cmp_0, xx_0, yy_0, _ctx), _ctx); /*2419*/
        return kk_std_core_types__order_unbox(_x_x1408, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq(x_0_10712, _ctx)) { // tailcall
                                                       xs = xx_0;
                                                       ys = yy_0;
                                                       goto kk__tailcall;
      }
      {
        kk_std_core_types__list_drop(yy_0, _ctx);
        kk_std_core_types__list_drop(xx_0, _ctx);
        kk_function_drop(_implicit_fs_cmp_0, _ctx);
        return x_0_10712;
      }
    }
  }
  {
    kk_function_drop(_implicit_fs_cmp_0, _ctx);
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      return kk_std_core_types__new_Eq(_ctx);
    }
    {
      struct kk_std_core_types_Cons* _con_x1411 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t _pat_6 = _con_x1411->head;
      kk_std_core_types__list _pat_7 = _con_x1411->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_std_core_types__list_drop(_pat_7, _ctx);
        kk_box_drop(_pat_6, _ctx);
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ys, _ctx);
      }
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list__trmc_take(kk_std_core_types__list xs, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1413 = kk_std_core_types__as_Cons(xs, _ctx);
    if (kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context())) {
      kk_box_t x = _con_x1413->head;
      kk_std_core_types__list xx = _con_x1413->tail;
      kk_reuse_t _ru_x1316 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        _ru_x1316 = (kk_datatype_ptr_reuse(xs, _ctx));
      }
      else {
        kk_box_dup(x, _ctx);
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_std_core_types__list _trmc_x10360 = kk_datatype_null(); /*list<960>*/;
      kk_std_core_types__list _trmc_x10361 = kk_std_core_types__new_Cons(_ru_x1316, 0, x, _trmc_x10360, _ctx); /*list<960>*/;
      kk_field_addr_t _b_x13_18 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10361, _ctx)->tail, _ctx); /*@field-addr<list<960>>*/;
      { // tailcall
        kk_integer_t _x_x1414 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        kk_std_core_types__cctx _x_x1415 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10361, _ctx)),_b_x13_18,kk_context()); /*ctx<0>*/
        xs = xx;
        n = _x_x1414;
        _acc = _x_x1415;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_std_core_types__list_drop(xs, _ctx);
    kk_integer_drop(n, _ctx);
    kk_box_t _x_x1416 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1416, KK_OWNED, _ctx);
  }
}
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list_take(kk_std_core_types__list xs_0, kk_integer_t n_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk_std_core_types__cctx _x_x1417 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_take(xs_0, n_0, _x_x1417, _ctx);
}
 
// Drop the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list_drop(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1418 = kk_std_core_types__as_Cons(xs, _ctx);
    if (kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context())) {
      kk_box_t _pat_0 = _con_x1418->head;
      kk_std_core_types__list xx = _con_x1418->tail;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_box_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      { // tailcall
        kk_integer_t _x_x1419 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        xs = xx;
        n = _x_x1419;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(n, _ctx);
    return xs;
  }
}

kk_std_core_types__list kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__list acc, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1420 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t x = _con_x1420->head;
    kk_std_core_types__list xx = _con_x1420->tail;
    kk_reuse_t _ru_x1318 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1318 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x1421 = kk_std_core_types__new_Cons(_ru_x1318, 0, x, acc, _ctx); /*list<79>*/
      acc = _x_x1421;
      ys = xx;
      goto kk__tailcall;
    }
  }
  {
    return acc;
  }
}
 
// Append two lists.

kk_std_core_types__list kk_std_core_list__trmc_unroll_append_10004(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1422 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1422->head;
    kk_std_core_types__list xx = _con_x1422->tail;
    kk_reuse_t _ru_x1319 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1319 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__list _trmc_x10362 = kk_datatype_null(); /*list<1121>*/;
    kk_std_core_types__list _trmc_x10363 = kk_std_core_types__new_Cons(_ru_x1319, 0, x, _trmc_x10362, _ctx); /*list<1121>*/;
    kk_field_addr_t _b_x29_34 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10363, _ctx)->tail, _ctx); /*@field-addr<list<1121>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1423 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10363, _ctx)),_b_x29_34,kk_context()); /*ctx<0>*/
      xs = xx;
      _acc = _x_x1423;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1424 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(ys, _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1424, KK_OWNED, _ctx);
  }
}
 
// Append two lists.

kk_std_core_types__list kk_std_core_list__unroll_append_10004(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1425 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_append_10004(xs_0, ys_0, _x_x1425, _ctx);
}
 
// monadic lift

kk_box_t kk_std_core_list__mlift_unroll_foldl_10005_10677(kk_function_t f, kk_std_core_types__list xx, kk_box_t _y_x10435, kk_context_t* _ctx) { /* forall<a,b,e> (f : (b, a) -> e b, xx : list<a>, b) -> e b */ 
  return kk_std_core_list__unroll_foldl_10005(xx, _y_x10435, f, _ctx);
}
 
// Fold a list from the left, i.e. `foldl([1,2],0,(+)) == (0+1)+2`
// Since `foldl` is tail recursive, it is preferred over `foldr` when using an associative function `f`


// lift anonymous function
struct kk_std_core_list__unroll_foldl_10005_fun1430__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_foldl_10005_fun1430(kk_function_t _fself, kk_box_t _y_x10435_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_foldl_10005_fun1430(kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foldl_10005_fun1430__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_foldl_10005_fun1430__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_foldl_10005_fun1430, kk_context());
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_foldl_10005_fun1430(kk_function_t _fself, kk_box_t _y_x10435_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foldl_10005_fun1430__t* _self = kk_function_as(struct kk_std_core_list__unroll_foldl_10005_fun1430__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (1192, 1191) -> 1193 1192 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1191> */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  return kk_std_core_list__mlift_unroll_foldl_10005_10677(f_0, xx_0, _y_x10435_0, _ctx);
}

kk_box_t kk_std_core_list__unroll_foldl_10005(kk_std_core_types__list xs, kk_box_t z, kk_function_t f_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, z : b, f : (b, a) -> e b) -> e b */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1428 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1428->head;
    kk_std_core_types__list xx_0 = _con_x1428->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_t x_0_10719;
    kk_function_t _x_x1429 = kk_function_dup(f_0, _ctx); /*(1192, 1191) -> 1193 1192*/
    x_0_10719 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1429, (_x_x1429, z, x, _ctx), _ctx); /*1192*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10719, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_foldl_10005_fun1430(f_0, xx_0, _ctx), _ctx);
    }
    { // tailcall
      xs = xx_0;
      z = x_0_10719;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    return z;
  }
}
 
// monadic lift

kk_box_t kk_std_core_list__mlift_lift_foldr_10344_10678(kk_std_core_types__list _uniq_xx_10269, kk_function_t f, kk_box_t _uniq_z_10265_0_10354, kk_context_t* _ctx) { /* forall<a,b,e> (list<a>, f : (a, b) -> e b, b) -> e b */ 
  return kk_std_core_list__lift_foldr_10344(f, _uniq_xx_10269, _uniq_z_10265_0_10354, _ctx);
}
 
// lifted local: foldr, @spec-x10271
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10266, using:
// @uniq-f@10266 = fn<(e :: E)>(x: 1245, y: 1244){
//   f(y, x);
// }


// lift anonymous function
struct kk_std_core_list__lift_foldr_10344_fun1433__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10269_0;
  kk_function_t f_0;
};
static kk_box_t kk_std_core_list__lift_foldr_10344_fun1433(kk_function_t _fself, kk_box_t _uniq_z_10265_0_10354_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foldr_10344_fun1433(kk_std_core_types__list _uniq_xx_10269_0, kk_function_t f_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foldr_10344_fun1433__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foldr_10344_fun1433__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foldr_10344_fun1433, kk_context());
  _self->_uniq_xx_10269_0 = _uniq_xx_10269_0;
  _self->f_0 = f_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foldr_10344_fun1433(kk_function_t _fself, kk_box_t _uniq_z_10265_0_10354_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foldr_10344_fun1433__t* _self = kk_function_as(struct kk_std_core_list__lift_foldr_10344_fun1433__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10269_0 = _self->_uniq_xx_10269_0; /* list<1244> */
  kk_function_t f_0 = _self->f_0; /* (1244, 1245) -> 1246 1245 */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10269_0, _ctx);kk_function_dup(f_0, _ctx);}, {}, _ctx)
  return kk_std_core_list__mlift_lift_foldr_10344_10678(_uniq_xx_10269_0, f_0, _uniq_z_10265_0_10354_0, _ctx);
}

kk_box_t kk_std_core_list__lift_foldr_10344(kk_function_t f_0, kk_std_core_types__list _uniq_xs_10264, kk_box_t _uniq_z_10265, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a, b) -> e b, list<a>, b) -> e b */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10264, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1431 = kk_std_core_types__as_Cons(_uniq_xs_10264, _ctx);
    kk_box_t _uniq_x_10268 = _con_x1431->head;
    kk_std_core_types__list _uniq_xx_10269_0 = _con_x1431->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10264, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10264, _ctx);
    }
    else {
      kk_box_dup(_uniq_x_10268, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10269_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10264, _ctx);
    }
    kk_box_t x_10722;
    kk_function_t _x_x1432 = kk_function_dup(f_0, _ctx); /*(1244, 1245) -> 1246 1245*/
    x_10722 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1432, (_x_x1432, _uniq_x_10268, _uniq_z_10265, _ctx), _ctx); /*1245*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10722, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foldr_10344_fun1433(_uniq_xx_10269_0, f_0, _ctx), _ctx);
    }
    { // tailcall
      _uniq_xs_10264 = _uniq_xx_10269_0;
      _uniq_z_10265 = x_10722;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    return _uniq_z_10265;
  }
}


// lift anonymous function
struct kk_std_core_list_foldl1_fun1442__t {
  struct kk_function_s _base;
  kk_ssize_t i_10725;
};
static kk_box_t kk_std_core_list_foldl1_fun1442(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foldl1_fun1442(kk_ssize_t i_10725, kk_context_t* _ctx) {
  struct kk_std_core_list_foldl1_fun1442__t* _self = kk_function_alloc_as(struct kk_std_core_list_foldl1_fun1442__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_foldl1_fun1442, kk_context());
  _self->i_10725 = i_10725;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_foldl1_fun1442(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_list_foldl1_fun1442__t* _self = kk_function_as(struct kk_std_core_list_foldl1_fun1442__t*, _fself, _ctx);
  kk_ssize_t i_10725 = _self->i_10725; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10725, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10725, cont, res, _ctx);
}

kk_box_t kk_std_core_list_foldl1(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1434 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1434->head;
    kk_std_core_types__list xx = _con_x1434->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      kk_function_drop(f, _ctx);
      return x;
    }
    {
      return kk_std_core_list__unroll_foldl_10005(xx, x, f, _ctx);
    }
  }
  {
    kk_function_drop(f, _ctx);
    kk_ssize_t i_10725;
    kk_std_core_hnd__htag _x_x1435 = kk_std_core_hnd__htag_dup(kk_std_core_exn_exn_fs__tag, _ctx); /*hnd/htag<exn>*/
    i_10725 = kk_std_core_hnd__evv_index(_x_x1435, _ctx); /*hnd/ev-index*/
    kk_evv_t w = kk_evv_swap_create1(i_10725,kk_context()); /*hnd/evv<<exn|1303>>*/;
    kk_std_core_hnd__ev ev_10729 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t y;
    {
      struct kk_std_core_hnd_Ev* _con_x1436 = kk_std_core_hnd__as_Ev(ev_10729, _ctx);
      kk_box_t _box_x40 = _con_x1436->hnd;
      int32_t m = _con_x1436->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x40, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x1297;
      kk_std_core_hnd__clause1 _brw_x1299 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,276,exn,277,278>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x1297 = _brw_x1299; /*hnd/clause1<exception,276,exn,277,278>*/
      {
        kk_function_t _fun_unbox_x44 = _match_x1297.clause;
        kk_box_t _x_x1437;
        kk_std_core_exn__exception _x_x1438;
        kk_string_t _x_x1439;
        kk_define_string_literal(, _s_x1440, 33, "unexpected Nil in std/core/foldl1", _ctx)
        _x_x1439 = kk_string_dup(_s_x1440, _ctx); /*string*/
        kk_std_core_exn__exception_info _x_x1441;
        kk_std_core_types__optional _match_x1298 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x1298, _ctx)) {
          kk_box_t _box_x48 = _match_x1298._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_399 = kk_std_core_exn__exception_info_unbox(_box_x48, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_399, _ctx);
          kk_std_core_types__optional_drop(_match_x1298, _ctx);
          _x_x1441 = _uniq_info_399; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x1298, _ctx);
          _x_x1441 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x1438 = kk_std_core_exn__new_Exception(_x_x1439, _x_x1441, _ctx); /*exception*/
        _x_x1437 = kk_std_core_exn__exception_box(_x_x1438, _ctx); /*45*/
        y = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x44, (_fun_unbox_x44, m, ev_10729, _x_x1437, _ctx), _ctx); /*1302*/
      }
    }
    kk_unit_t __ = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_drop(y, _ctx);
      return kk_std_core_hnd_yield_cont(kk_std_core_list_new_foldl1_fun1442(i_10725, _ctx), _ctx);
    }
    {
      return y;
    }
  }
}


// lift anonymous function
struct kk_std_core_list_foldr1_fun1451__t {
  struct kk_function_s _base;
  kk_ssize_t i_10734;
};
static kk_box_t kk_std_core_list_foldr1_fun1451(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foldr1_fun1451(kk_ssize_t i_10734, kk_context_t* _ctx) {
  struct kk_std_core_list_foldr1_fun1451__t* _self = kk_function_alloc_as(struct kk_std_core_list_foldr1_fun1451__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_foldr1_fun1451, kk_context());
  _self->i_10734 = i_10734;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_foldr1_fun1451(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_list_foldr1_fun1451__t* _self = kk_function_as(struct kk_std_core_list_foldr1_fun1451__t*, _fself, _ctx);
  kk_ssize_t i_10734 = _self->i_10734; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10734, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10734, cont, res, _ctx);
}

kk_box_t kk_std_core_list_foldr1(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn|1339>>*/;
  kk_std_core_types__list x;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    x = kk_std_core_types__new_Nil(_ctx); /*list<1338>*/
  }
  else {
    x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), xs, _ctx); /*list<1338>*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_std_core_types__is_Cons(x, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1443 = kk_std_core_types__as_Cons(x, _ctx);
    kk_box_t x_0 = _con_x1443->head;
    kk_std_core_types__list xx = _con_x1443->tail;
    if kk_likely(kk_datatype_ptr_is_unique(x, _ctx)) {
      kk_datatype_ptr_free(x, _ctx);
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(x, _ctx);
    }
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      kk_function_drop(f, _ctx);
      return x_0;
    }
    {
      return kk_std_core_list__unroll_foldl_10005(xx, x_0, f, _ctx);
    }
  }
  {
    kk_function_drop(f, _ctx);
    kk_ssize_t i_10734;
    kk_std_core_hnd__htag _x_x1444 = kk_std_core_hnd__htag_dup(kk_std_core_exn_exn_fs__tag, _ctx); /*hnd/htag<exn>*/
    i_10734 = kk_std_core_hnd__evv_index(_x_x1444, _ctx); /*hnd/ev-index*/
    kk_evv_t w_0 = kk_evv_swap_create1(i_10734,kk_context()); /*hnd/evv<<exn|1339>>*/;
    kk_std_core_hnd__ev ev_10738 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t y;
    {
      struct kk_std_core_hnd_Ev* _con_x1445 = kk_std_core_hnd__as_Ev(ev_10738, _ctx);
      kk_box_t _box_x49 = _con_x1445->hnd;
      int32_t m = _con_x1445->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x49, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x1293;
      kk_std_core_hnd__clause1 _brw_x1295 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,276,exn,277,278>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x1293 = _brw_x1295; /*hnd/clause1<exception,276,exn,277,278>*/
      {
        kk_function_t _fun_unbox_x53 = _match_x1293.clause;
        kk_box_t _x_x1446;
        kk_std_core_exn__exception _x_x1447;
        kk_string_t _x_x1448;
        kk_define_string_literal(, _s_x1449, 33, "unexpected Nil in std/core/foldl1", _ctx)
        _x_x1448 = kk_string_dup(_s_x1449, _ctx); /*string*/
        kk_std_core_exn__exception_info _x_x1450;
        kk_std_core_types__optional _match_x1294 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x1294, _ctx)) {
          kk_box_t _box_x57 = _match_x1294._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_399 = kk_std_core_exn__exception_info_unbox(_box_x57, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_399, _ctx);
          kk_std_core_types__optional_drop(_match_x1294, _ctx);
          _x_x1450 = _uniq_info_399; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x1294, _ctx);
          _x_x1450 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x1447 = kk_std_core_exn__new_Exception(_x_x1448, _x_x1450, _ctx); /*exception*/
        _x_x1446 = kk_std_core_exn__exception_box(_x_x1447, _ctx); /*45*/
        y = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x53, (_fun_unbox_x53, m, ev_10738, _x_x1446, _ctx), _ctx); /*1338*/
      }
    }
    kk_unit_t __ = kk_Unit;
    kk_evv_set(w_0,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_drop(y, _ctx);
      return kk_std_core_hnd_yield_cont(kk_std_core_list_new_foldr1_fun1451(i_10734, _ctx), _ctx);
    }
    {
      return y;
    }
  }
}
 
// split a list at position `n`

kk_std_core_types__tuple2 kk_std_core_list_split(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> (list<a>, list<a>) */ 
  kk_std_core_types__list _b_x58_60;
  kk_std_core_types__list _x_x1452 = kk_std_core_types__list_dup(xs, _ctx); /*list<1381>*/
  kk_integer_t _x_x1453 = kk_integer_dup(n, _ctx); /*int*/
  kk_std_core_types__cctx _x_x1454 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  _b_x58_60 = kk_std_core_list__trmc_take(_x_x1452, _x_x1453, _x_x1454, _ctx); /*list<1381>*/
  kk_std_core_types__list _b_x59_61 = kk_std_core_list_drop(xs, n, _ctx); /*list<1381>*/;
  return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x58_60, _ctx), kk_std_core_types__list_box(_b_x59_61, _ctx), _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_unroll_drop_while_10006_10679(kk_function_t predicate, kk_std_core_types__list xs, kk_std_core_types__list xx, bool _y_x10455, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xs : list<a>, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10455) {
    kk_std_core_types__list_drop(xs, _ctx);
    return kk_std_core_list__unroll_drop_while_10006(xx, predicate, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return xs;
  }
}
 
// Drop all initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core_list__unroll_drop_while_10006_fun1458__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xs_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_drop_while_10006_fun1458(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_drop_while_10006_fun1458(kk_function_t predicate_0, kk_std_core_types__list xs_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_drop_while_10006_fun1458__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_drop_while_10006_fun1458__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_drop_while_10006_fun1458, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xs_0 = xs_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_drop_while_10006_fun1458(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_drop_while_10006_fun1458__t* _self = kk_function_as(struct kk_std_core_list__unroll_drop_while_10006_fun1458__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (1427) -> 1428 bool */
  kk_std_core_types__list xs_0 = _self->xs_0; /* list<1427> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1427> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xs_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10455_0_65 = kk_bool_unbox(_b_x63); /*bool*/;
  kk_std_core_types__list _x_x1459 = kk_std_core_list__mlift_unroll_drop_while_10006_10679(predicate_0, xs_0, xx_0, _y_x10455_0_65, _ctx); /*list<1427>*/
  return kk_std_core_types__list_box(_x_x1459, _ctx);
}

kk_std_core_types__list kk_std_core_list__unroll_drop_while_10006(kk_std_core_types__list xs_0, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs_0, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1455 = kk_std_core_types__as_Cons(xs_0, _ctx);
    kk_box_t x = _con_x1455->head;
    kk_std_core_types__list xx_0 = _con_x1455->tail;
    kk_box_dup(x, _ctx);
    kk_std_core_types__list_dup(xx_0, _ctx);
    bool x_0_10743;
    kk_function_t _x_x1456 = kk_function_dup(predicate_0, _ctx); /*(1427) -> 1428 bool*/
    x_0_10743 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1456, (_x_x1456, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1457 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_drop_while_10006_fun1458(predicate_0, xs_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1457, KK_OWNED, _ctx);
    }
    if (x_0_10743) {
      if kk_likely(kk_datatype_ptr_is_unique(xs_0, _ctx)) {
        kk_std_core_types__list_drop(xx_0, _ctx);
        kk_box_drop(x, _ctx);
        kk_datatype_ptr_free(xs_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(xs_0, _ctx);
      }
      { // tailcall
        xs_0 = xx_0;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return xs_0;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_filter_10007_10680(kk_std_core_types__cctx _acc, kk_function_t pred, kk_box_t x, kk_std_core_types__list xx, bool _y_x10461, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10461) {
    kk_std_core_types__list _trmc_x10364 = kk_datatype_null(); /*list<1493>*/;
    kk_std_core_types__list _trmc_x10365 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _trmc_x10364, _ctx); /*list<1493>*/;
    kk_field_addr_t _b_x71_74 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10365, _ctx)->tail, _ctx); /*@field-addr<list<1493>>*/;
    kk_std_core_types__cctx _x_x1460 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10365, _ctx)),_b_x71_74,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_filter_10007(xx, pred, _x_x1460, _ctx);
  }
  {
    kk_box_drop(x, _ctx);
    return kk_std_core_list__trmc_unroll_filter_10007(xx, pred, _acc, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_filter_10007_fun1465__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t pred_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_filter_10007_fun1465(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_filter_10007_fun1465(kk_std_core_types__cctx _acc_0, kk_function_t pred_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_10007_fun1465__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_filter_10007_fun1465__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_filter_10007_fun1465, kk_context());
  _self->_acc_0 = _acc_0;
  _self->pred_0 = pred_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_filter_10007_fun1465(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_10007_fun1465__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_filter_10007_fun1465__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1493>> */
  kk_function_t pred_0 = _self->pred_0; /* (1493) -> 1494 bool */
  kk_box_t x_0 = _self->x_0; /* 1493 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1493> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(pred_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10461_0_97 = kk_bool_unbox(_b_x79); /*bool*/;
  kk_std_core_types__list _x_x1466 = kk_std_core_list__mlift_trmc_unroll_filter_10007_10680(_acc_0, pred_0, x_0, xx_0, _y_x10461_0_97, _ctx); /*list<1493>*/
  return kk_std_core_types__list_box(_x_x1466, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_filter_10007(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1461 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1461->head;
    kk_std_core_types__list xx_0 = _con_x1461->tail;
    kk_reuse_t _ru_x1327 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1327 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10746;
    kk_function_t _x_x1463 = kk_function_dup(pred_0, _ctx); /*(1493) -> 1494 bool*/
    kk_box_t _x_x1462 = kk_box_dup(x_0, _ctx); /*1493*/
    x_1_10746 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1463, (_x_x1463, _x_x1462, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1327,kk_context());
      kk_box_t _x_x1464 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_filter_10007_fun1465(_acc_0, pred_0, x_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1464, KK_OWNED, _ctx);
    }
    if (x_1_10746) {
      kk_std_core_types__list _trmc_x10364_0 = kk_datatype_null(); /*list<1493>*/;
      kk_std_core_types__list _trmc_x10365_0 = kk_std_core_types__new_Cons(_ru_x1327, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _trmc_x10364_0, _ctx); /*list<1493>*/;
      kk_field_addr_t _b_x85_91 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10365_0, _ctx)->tail, _ctx); /*@field-addr<list<1493>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1467 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10365_0, _ctx)),_b_x85_91,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1467;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1327,kk_context());
      kk_box_drop(x_0, _ctx);
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x1468 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1468, KK_OWNED, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`

kk_std_core_types__list kk_std_core_list__unroll_filter_10007(kk_std_core_types__list xs_0, kk_function_t pred_1, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1469 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_filter_10007(xs_0, pred_1, _x_x1469, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_filter_map_10008_10681(kk_std_core_types__cctx _acc, kk_function_t pred, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10469, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Nothing(_y_x10469, _ctx)) {
    return kk_std_core_list__trmc_unroll_filter_map_10008(xx, pred, _acc, _ctx);
  }
  {
    kk_box_t y = _y_x10469._cons.Just.value;
    kk_std_core_types__list _trmc_x10366 = kk_datatype_null(); /*list<1577>*/;
    kk_std_core_types__list _trmc_x10367 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10366, _ctx); /*list<1577>*/;
    kk_field_addr_t _b_x103_106 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10367, _ctx)->tail, _ctx); /*@field-addr<list<1577>>*/;
    kk_std_core_types__cctx _x_x1471 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10367, _ctx)),_b_x103_106,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_filter_map_10008(xx, pred, _x_x1471, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1476__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t pred_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_filter_map_10008_fun1476(kk_function_t _fself, kk_box_t _b_x113, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_filter_map_10008_fun1476(kk_std_core_types__cctx _acc_0, kk_function_t pred_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1476__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1476__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_filter_map_10008_fun1476, kk_context());
  _self->_acc_0 = _acc_0;
  _self->pred_0 = pred_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_filter_map_10008_fun1476(kk_function_t _fself, kk_box_t _b_x113, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1476__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1476__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1577>> */
  kk_function_t pred_0 = _self->pred_0; /* (1576) -> 1578 maybe<1577> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1576> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(pred_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10469_0_129 = kk_std_core_types__maybe_unbox(_b_x113, KK_OWNED, _ctx); /*maybe<1577>*/;
  kk_std_core_types__list _x_x1477 = kk_std_core_list__mlift_trmc_unroll_filter_map_10008_10681(_acc_0, pred_0, xx_0, _y_x10469_0_129, _ctx); /*list<1577>*/
  return kk_std_core_types__list_box(_x_x1477, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_filter_map_10008(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x1472 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1472, KK_OWNED, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1473 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1473->head;
    kk_std_core_types__list xx_0 = _con_x1473->tail;
    kk_reuse_t _ru_x1328 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1328 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10751;
    kk_function_t _x_x1474 = kk_function_dup(pred_0, _ctx); /*(1576) -> 1578 maybe<1577>*/
    x_0_10751 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1474, (_x_x1474, x, _ctx), _ctx); /*maybe<1577>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1328,kk_context());
      kk_std_core_types__maybe_drop(x_0_10751, _ctx);
      kk_box_t _x_x1475 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_filter_map_10008_fun1476(_acc_0, pred_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1475, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10751, _ctx)) {
      kk_reuse_drop(_ru_x1328,kk_context());
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
    {
      kk_box_t y_0 = x_0_10751._cons.Just.value;
      kk_std_core_types__list _trmc_x10366_0 = kk_datatype_null(); /*list<1577>*/;
      kk_std_core_types__list _trmc_x10367_0 = kk_std_core_types__new_Cons(_ru_x1328, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10366_0, _ctx); /*list<1577>*/;
      kk_field_addr_t _b_x119_125 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10367_0, _ctx)->tail, _ctx); /*@field-addr<list<1577>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1478 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10367_0, _ctx)),_b_x119_125,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1478;
        goto kk__tailcall;
      }
    }
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`

kk_std_core_types__list kk_std_core_list__unroll_filter_map_10008(kk_std_core_types__list xs_0, kk_function_t pred_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1479 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_filter_map_10008(xs_0, pred_1, _x_x1479, _ctx);
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_list__mlift_unroll_foreach_while_10009_10682(kk_function_t action, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10477, kk_context_t* _ctx) { /* forall<a,b,e> (action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nothing(_y_x10477, _ctx)) {
    return kk_std_core_list__unroll_foreach_while_10009(xx, action, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(action, _ctx);
    return _y_x10477;
  }
}
 
// Invoke `action` for each element of a list while `action` return `Nothing`


// lift anonymous function
struct kk_std_core_list__unroll_foreach_while_10009_fun1484__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_foreach_while_10009_fun1484(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_foreach_while_10009_fun1484(kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_while_10009_fun1484__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_foreach_while_10009_fun1484__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_foreach_while_10009_fun1484, kk_context());
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_foreach_while_10009_fun1484(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_while_10009_fun1484__t* _self = kk_function_as(struct kk_std_core_list__unroll_foreach_while_10009_fun1484__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (1650) -> 1652 maybe<1651> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1650> */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10477_0_133 = kk_std_core_types__maybe_unbox(_b_x131, KK_OWNED, _ctx); /*maybe<1651>*/;
  kk_std_core_types__maybe _x_x1485 = kk_std_core_list__mlift_unroll_foreach_while_10009_10682(action_0, xx_0, _y_x10477_0_133, _ctx); /*maybe<1651>*/
  return kk_std_core_types__maybe_box(_x_x1485, _ctx);
}

kk_std_core_types__maybe kk_std_core_list__unroll_foreach_while_10009(kk_std_core_types__list xs, kk_function_t action_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1481 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1481->head;
    kk_std_core_types__list xx_0 = _con_x1481->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10756;
    kk_function_t _x_x1482 = kk_function_dup(action_0, _ctx); /*(1650) -> 1652 maybe<1651>*/
    x_0_10756 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1482, (_x_x1482, x, _ctx), _ctx); /*maybe<1651>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10756, _ctx);
      kk_box_t _x_x1483 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_foreach_while_10009_fun1484(action_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x1483, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10756, _ctx)) { // tailcall
                                                          xs = xx_0;
                                                          goto kk__tailcall;
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(action_0, _ctx);
      return x_0_10756;
    }
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_list__mlift_lift_find_10345_10683(kk_box_t _uniq_x_10278, kk_std_core_types__list _uniq_xx_10279, kk_function_t pred, bool _y_x10483, kk_context_t* _ctx) { /* forall<a,e> (a, list<a>, pred : (a) -> e bool, bool) -> e maybe<a> */ 
  if (_y_x10483) {
    kk_function_drop(pred, _ctx);
    kk_std_core_types__list_drop(_uniq_xx_10279, _ctx);
    return kk_std_core_types__new_Just(_uniq_x_10278, _ctx);
  }
  {
    kk_box_drop(_uniq_x_10278, _ctx);
    return kk_std_core_list__lift_find_10345(pred, _uniq_xx_10279, _ctx);
  }
}
 
// lifted local: find, @spec-x10282
// specialized: std/core/list/@unroll-foreach-while@10009, on parameters @uniq-action@10275, using:
// @uniq-action@10275 = fn<(e :: E)>(x: 1719){
//   match ((pred(x))) {
//     ((std/core/types/True() : bool ) as @pat@1: bool)
//        -> std/core/types/Just<a>(x);
//     ((@skip std/core/types/False() : bool ) as @pat@0@0: bool)
//        -> std/core/types/Nothing<a>;
//   };
// }


// lift anonymous function
struct kk_std_core_list__lift_find_10345_fun1490__t {
  struct kk_function_s _base;
  kk_box_t _uniq_x_10278_0;
  kk_std_core_types__list _uniq_xx_10279_0;
  kk_function_t pred_0;
};
static kk_box_t kk_std_core_list__lift_find_10345_fun1490(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_find_10345_fun1490(kk_box_t _uniq_x_10278_0, kk_std_core_types__list _uniq_xx_10279_0, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_find_10345_fun1490__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_find_10345_fun1490__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_find_10345_fun1490, kk_context());
  _self->_uniq_x_10278_0 = _uniq_x_10278_0;
  _self->_uniq_xx_10279_0 = _uniq_xx_10279_0;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_find_10345_fun1490(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_find_10345_fun1490__t* _self = kk_function_as(struct kk_std_core_list__lift_find_10345_fun1490__t*, _fself, _ctx);
  kk_box_t _uniq_x_10278_0 = _self->_uniq_x_10278_0; /* 1719 */
  kk_std_core_types__list _uniq_xx_10279_0 = _self->_uniq_xx_10279_0; /* list<1719> */
  kk_function_t pred_0 = _self->pred_0; /* (1719) -> 1720 bool */
  kk_drop_match(_self, {kk_box_dup(_uniq_x_10278_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10279_0, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  bool _y_x10483_0_137 = kk_bool_unbox(_b_x135); /*bool*/;
  kk_std_core_types__maybe _x_x1491 = kk_std_core_list__mlift_lift_find_10345_10683(_uniq_x_10278_0, _uniq_xx_10279_0, pred_0, _y_x10483_0_137, _ctx); /*maybe<1719>*/
  return kk_std_core_types__maybe_box(_x_x1491, _ctx);
}

kk_std_core_types__maybe kk_std_core_list__lift_find_10345(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10274, kk_context_t* _ctx) { /* forall<a,e> (pred : (a) -> e bool, list<a>) -> e maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_xs_10274, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1486 = kk_std_core_types__as_Cons(_uniq_xs_10274, _ctx);
    kk_box_t _uniq_x_10278_0 = _con_x1486->head;
    kk_std_core_types__list _uniq_xx_10279_0 = _con_x1486->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10274, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10274, _ctx);
    }
    else {
      kk_box_dup(_uniq_x_10278_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10279_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10274, _ctx);
    }
    bool x_10759;
    kk_function_t _x_x1488 = kk_function_dup(pred_0, _ctx); /*(1719) -> 1720 bool*/
    kk_box_t _x_x1487 = kk_box_dup(_uniq_x_10278_0, _ctx); /*1719*/
    x_10759 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1488, (_x_x1488, _x_x1487, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1489 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_find_10345_fun1490(_uniq_x_10278_0, _uniq_xx_10279_0, pred_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x1489, KK_OWNED, _ctx);
    }
    if (x_10759) {
      kk_function_drop(pred_0, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10279_0, _ctx);
      return kk_std_core_types__new_Just(_uniq_x_10278_0, _ctx);
    }
    {
      kk_box_drop(_uniq_x_10278_0, _ctx);
      { // tailcall
        _uniq_xs_10274 = _uniq_xx_10279_0;
        goto kk__tailcall;
      }
    }
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_range_fs__trmc_list(kk_integer_t lo, kk_integer_t hi, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (lo : int, hi : int, ctx<list<int>>) -> list<int> */ 
  kk__tailcall: ;
  bool _match_x1286 = kk_integer_lte_borrow(lo,hi,kk_context()); /*bool*/;
  if (_match_x1286) {
    kk_std_core_types__list _trmc_x10368 = kk_datatype_null(); /*list<int>*/;
    kk_std_core_types__list _trmc_x10369;
    kk_box_t _x_x1492;
    kk_integer_t _x_x1493 = kk_integer_dup(lo, _ctx); /*int*/
    _x_x1492 = kk_integer_box(_x_x1493, _ctx); /*79*/
    _trmc_x10369 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1492, _trmc_x10368, _ctx); /*list<int>*/
    kk_field_addr_t _b_x147_152 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10369, _ctx)->tail, _ctx); /*@field-addr<list<int>>*/;
    { // tailcall
      kk_integer_t _x_x1494 = kk_integer_add_small_const(lo, 1, _ctx); /*int*/
      kk_std_core_types__cctx _x_x1495 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10369, _ctx)),_b_x147_152,kk_context()); /*ctx<0>*/
      lo = _x_x1494;
      _acc = _x_x1495;
      goto kk__tailcall;
    }
  }
  {
    kk_integer_drop(lo, _ctx);
    kk_integer_drop(hi, _ctx);
    kk_box_t _x_x1496 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1496, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_range_fs_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_context_t* _ctx) { /* (lo : int, hi : int) -> list<int> */ 
  kk_std_core_types__cctx _x_x1497 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_range_fs__trmc_list(lo_0, hi_0, _x_x1497, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_map_10010_10684(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_box_t _trmc_x10370, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10371 = kk_datatype_null(); /*list<2218>*/;
  kk_std_core_types__list _trmc_x10372 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10370, _trmc_x10371, _ctx); /*list<2218>*/;
  kk_field_addr_t _b_x163_166 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10372, _ctx)->tail, _ctx); /*@field-addr<list<2218>>*/;
  kk_std_core_types__cctx _own_x1284 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10372, _ctx)),_b_x163_166,kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1285 = kk_std_core_list__trmc_unroll_map_10010(xx, f, _own_x1284, _ctx); /*list<2218>*/;
  kk_function_drop(f, _ctx);
  return _brw_x1285;
}
 
// Apply a function `f` to each element of the input list in sequence.


// lift anonymous function
struct kk_std_core_list__trmc_unroll_map_10010_fun1502__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_map_10010_fun1502(kk_function_t _fself, kk_box_t _b_x171, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_map_10010_fun1502(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_10010_fun1502__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_map_10010_fun1502__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_map_10010_fun1502, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_map_10010_fun1502(kk_function_t _fself, kk_box_t _b_x171, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_10010_fun1502__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_map_10010_fun1502__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2218>> */
  kk_function_t f_0 = _self->f_0; /* (2217) -> 2219 2218 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2217> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10370_0_189 = _b_x171; /*2218*/;
  kk_std_core_types__list _x_x1503 = kk_std_core_list__mlift_trmc_unroll_map_10010_10684(_acc_0, f_0, xx_0, _trmc_x10370_0_189, _ctx); /*list<2218>*/
  return kk_std_core_types__list_box(_x_x1503, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_map_10010(kk_std_core_types__list xs, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1498 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1498->head;
    kk_std_core_types__list xx_0 = _con_x1498->tail;
    kk_reuse_t _ru_x1331 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1331 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_t x_0_10762;
    kk_function_t _x_x1499 = kk_function_dup(f_0, _ctx); /*(2217) -> 2219 2218*/
    x_0_10762 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1499, (_x_x1499, x, _ctx), _ctx); /*2218*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1331,kk_context());
      kk_box_drop(x_0_10762, _ctx);
      kk_box_t _x_x1500;
      kk_function_t _x_x1501;
      kk_function_dup(f_0, _ctx);
      _x_x1501 = kk_std_core_list__new_trmc_unroll_map_10010_fun1502(_acc_0, f_0, xx_0, _ctx); /*(2418) -> 2420 2419*/
      _x_x1500 = kk_std_core_hnd_yield_extend(_x_x1501, _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1500, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10371_0 = kk_datatype_null(); /*list<2218>*/;
      kk_std_core_types__list _trmc_x10372_0 = kk_std_core_types__new_Cons(_ru_x1331, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10762, _trmc_x10371_0, _ctx); /*list<2218>*/;
      kk_field_addr_t _b_x177_183 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10372_0, _ctx)->tail, _ctx); /*@field-addr<list<2218>>*/;
      kk_std_core_types__cctx _own_x1283 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10372_0, _ctx)),_b_x177_183,kk_context()); /*ctx<0>*/;
      { // tailcall
        xs = xx_0;
        _acc_0 = _own_x1283;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x1504 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1504, KK_OWNED, _ctx);
  }
}
 
// Apply a function `f` to each element of the input list in sequence.

kk_std_core_types__list kk_std_core_list__unroll_map_10010(kk_std_core_types__list xs_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */ 
  kk_std_core_types__cctx _own_x1281 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  return kk_std_core_list__trmc_unroll_map_10010(xs_0, f_1, _own_x1281, _ctx);
}
 
// lifted local: char/list, @spec-x10290
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10285, using:
// @uniq-f@10285 = std/core/char/int/char

kk_std_core_types__list kk_std_core_list_char_fs__trmc_lift_list_10346(kk_std_core_types__list _uniq_xs_10284, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<int>, ctx<list<char>>) -> list<char> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10284, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1505 = kk_std_core_types__as_Cons(_uniq_xs_10284, _ctx);
    kk_box_t _box_x190 = _con_x1505->head;
    kk_std_core_types__list _uniq_xx_10288 = _con_x1505->tail;
    kk_integer_t _uniq_x_10287 = kk_integer_unbox(_box_x190, _ctx);
    kk_reuse_t _ru_x1332 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10284, _ctx)) {
      _ru_x1332 = (kk_datatype_ptr_reuse(_uniq_xs_10284, _ctx));
    }
    else {
      kk_integer_dup(_uniq_x_10287, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10288, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10284, _ctx);
    }
    kk_char_t _trmc_x10373 = kk_integer_clamp32(_uniq_x_10287,kk_context()); /*char*/;
    kk_std_core_types__list _trmc_x10374 = kk_datatype_null(); /*list<char>*/;
    kk_std_core_types__list _trmc_x10375 = kk_std_core_types__new_Cons(_ru_x1332, 0, kk_char_box(_trmc_x10373, _ctx), _trmc_x10374, _ctx); /*list<char>*/;
    kk_field_addr_t _b_x200_205 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10375, _ctx)->tail, _ctx); /*@field-addr<list<char>>*/;
    kk_std_core_types__cctx _brw_x1278;
    kk_std_core_types__cctx _x_x1506 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<char>>*/
    _brw_x1278 = kk_cctx_extend_linear(_x_x1506,(kk_std_core_types__list_box(_trmc_x10375, _ctx)),_b_x200_205,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1279 = kk_std_core_list_char_fs__trmc_lift_list_10346(_uniq_xx_10288, _brw_x1278, _ctx); /*list<char>*/;
    kk_std_core_types__cctx_drop(_brw_x1278, _ctx);
    return _brw_x1279;
  }
  {
    kk_box_t _x_x1507;
    kk_std_core_types__cctx _x_x1508 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<char>>*/
    _x_x1507 = kk_cctx_apply_linear(_x_x1508,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1507, KK_OWNED, _ctx);
  }
}
 
// lifted local: char/list, @spec-x10290
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10285, using:
// @uniq-f@10285 = std/core/char/int/char

kk_std_core_types__list kk_std_core_list_char_fs__lift_list_10346(kk_std_core_types__list _uniq_xs_10284_0, kk_context_t* _ctx) { /* (list<int>) -> list<char> */ 
  kk_std_core_types__cctx _brw_x1276 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1277 = kk_std_core_list_char_fs__trmc_lift_list_10346(_uniq_xs_10284_0, _brw_x1276, _ctx); /*list<char>*/;
  kk_std_core_types__cctx_drop(_brw_x1276, _ctx);
  return _brw_x1277;
}
 
// Create a list of characters from `lo`  to `hi`  (including `hi`).

kk_std_core_types__list kk_std_core_list_char_fs_list(kk_char_t lo, kk_char_t hi, kk_context_t* _ctx) { /* (lo : char, hi : char) -> list<char> */ 
  kk_integer_t lo_0_10767 = kk_integer_from_int(lo,kk_context()); /*int*/;
  kk_integer_t hi_0_10768 = kk_integer_from_int(hi,kk_context()); /*int*/;
  kk_std_core_types__list xs_10070;
  kk_std_core_types__cctx _x_x1509 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  xs_10070 = kk_std_core_list_range_fs__trmc_list(lo_0_10767, hi_0_10768, _x_x1509, _ctx); /*list<int>*/
  if (kk_std_core_types__is_Nil(xs_10070, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1274 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1275 = kk_std_core_list_char_fs__trmc_lift_list_10346(xs_10070, _brw_x1274, _ctx); /*list<char>*/;
    kk_std_core_types__cctx_drop(_brw_x1274, _ctx);
    return _brw_x1275;
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list_function_fs__mlift_trmc_list_10685(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t hi, kk_integer_t lo, kk_box_t _trmc_x10376, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, a) -> e list<a> */ 
  kk_std_core_types__list _trmc_x10377 = kk_datatype_null(); /*list<1927>*/;
  kk_std_core_types__list _trmc_x10378 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10376, _trmc_x10377, _ctx); /*list<1927>*/;
  kk_field_addr_t _b_x216_219 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10378, _ctx)->tail, _ctx); /*@field-addr<list<1927>>*/;
  kk_integer_t _x_x1510 = kk_integer_add_small_const(lo, 1, _ctx); /*int*/
  kk_std_core_types__cctx _x_x1511 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10378, _ctx)),_b_x216_219,kk_context()); /*ctx<0>*/
  return kk_std_core_list_function_fs__trmc_list(_x_x1510, hi, f, _x_x1511, _ctx);
}
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.


// lift anonymous function
struct kk_std_core_list_function_fs__trmc_list_fun1515__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t hi_0;
  kk_integer_t lo_0;
};
static kk_box_t kk_std_core_list_function_fs__trmc_list_fun1515(kk_function_t _fself, kk_box_t _b_x224, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_function_fs__new_trmc_list_fun1515(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t hi_0, kk_integer_t lo_0, kk_context_t* _ctx) {
  struct kk_std_core_list_function_fs__trmc_list_fun1515__t* _self = kk_function_alloc_as(struct kk_std_core_list_function_fs__trmc_list_fun1515__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_function_fs__trmc_list_fun1515, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->hi_0 = hi_0;
  _self->lo_0 = lo_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_function_fs__trmc_list_fun1515(kk_function_t _fself, kk_box_t _b_x224, kk_context_t* _ctx) {
  struct kk_std_core_list_function_fs__trmc_list_fun1515__t* _self = kk_function_as(struct kk_std_core_list_function_fs__trmc_list_fun1515__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1927>> */
  kk_function_t f_0 = _self->f_0; /* (int) -> 1928 1927 */
  kk_integer_t hi_0 = _self->hi_0; /* int */
  kk_integer_t lo_0 = _self->lo_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(hi_0, _ctx);kk_integer_dup(lo_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10376_0_242 = _b_x224; /*1927*/;
  kk_std_core_types__list _x_x1516 = kk_std_core_list_function_fs__mlift_trmc_list_10685(_acc_0, f_0, hi_0, lo_0, _trmc_x10376_0_242, _ctx); /*list<1927>*/
  return kk_std_core_types__list_box(_x_x1516, _ctx);
}

kk_std_core_types__list kk_std_core_list_function_fs__trmc_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  bool _match_x1272 = kk_integer_lte_borrow(lo_0,hi_0,kk_context()); /*bool*/;
  if (_match_x1272) {
    kk_box_t x_10770;
    kk_function_t _x_x1513 = kk_function_dup(f_0, _ctx); /*(int) -> 1928 1927*/
    kk_integer_t _x_x1512 = kk_integer_dup(lo_0, _ctx); /*int*/
    x_10770 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x1513, (_x_x1513, _x_x1512, _ctx), _ctx); /*1927*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10770, _ctx);
      kk_box_t _x_x1514 = kk_std_core_hnd_yield_extend(kk_std_core_list_function_fs__new_trmc_list_fun1515(_acc_0, f_0, hi_0, lo_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1514, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10377_0 = kk_datatype_null(); /*list<1927>*/;
      kk_std_core_types__list _trmc_x10378_0 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10770, _trmc_x10377_0, _ctx); /*list<1927>*/;
      kk_field_addr_t _b_x230_236 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10378_0, _ctx)->tail, _ctx); /*@field-addr<list<1927>>*/;
      { // tailcall
        kk_integer_t _x_x1517 = kk_integer_add_small_const(lo_0, 1, _ctx); /*int*/
        kk_std_core_types__cctx _x_x1518 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10378_0, _ctx)),_b_x230_236,kk_context()); /*ctx<0>*/
        lo_0 = _x_x1517;
        _acc_0 = _x_x1518;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(lo_0, _ctx);
    kk_integer_drop(hi_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1519 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1519, KK_OWNED, _ctx);
  }
}
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_function_fs_list(kk_integer_t lo_1, kk_integer_t hi_1, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, f : (int) -> e a) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1520 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_function_fs__trmc_list(lo_1, hi_1, f_1, _x_x1520, _ctx);
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stride_fs__trmc_list(kk_integer_t lo, kk_integer_t hi, kk_integer_t stride, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (lo : int, hi : int, stride : int, ctx<list<int>>) -> list<int> */ 
  kk__tailcall: ;
  bool _match_x1271 = kk_integer_lte_borrow(lo,hi,kk_context()); /*bool*/;
  if (_match_x1271) {
    kk_std_core_types__list _trmc_x10379 = kk_datatype_null(); /*list<int>*/;
    kk_std_core_types__list _trmc_x10380;
    kk_box_t _x_x1521;
    kk_integer_t _x_x1522 = kk_integer_dup(lo, _ctx); /*int*/
    _x_x1521 = kk_integer_box(_x_x1522, _ctx); /*79*/
    _trmc_x10380 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1521, _trmc_x10379, _ctx); /*list<int>*/
    kk_field_addr_t _b_x252_257 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10380, _ctx)->tail, _ctx); /*@field-addr<list<int>>*/;
    { // tailcall
      kk_integer_t _x_x1523;
      kk_integer_t _x_x1524 = kk_integer_dup(stride, _ctx); /*int*/
      _x_x1523 = kk_integer_add(lo,_x_x1524,kk_context()); /*int*/
      kk_std_core_types__cctx _x_x1525 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10380, _ctx)),_b_x252_257,kk_context()); /*ctx<0>*/
      lo = _x_x1523;
      _acc = _x_x1525;
      goto kk__tailcall;
    }
  }
  {
    kk_integer_drop(stride, _ctx);
    kk_integer_drop(lo, _ctx);
    kk_integer_drop(hi, _ctx);
    kk_box_t _x_x1526 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1526, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stride_fs_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_integer_t stride_0, kk_context_t* _ctx) { /* (lo : int, hi : int, stride : int) -> list<int> */ 
  kk_std_core_types__cctx _x_x1527 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_stride_fs__trmc_list(lo_0, hi_0, stride_0, _x_x1527, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list_stridefunction_fs__mlift_trmc_list_10686(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t hi, kk_integer_t lo, kk_integer_t stride, kk_box_t _trmc_x10381, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, stride : int, a) -> e list<a> */ 
  kk_std_core_types__list _trmc_x10382 = kk_datatype_null(); /*list<2107>*/;
  kk_std_core_types__list _trmc_x10383 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10381, _trmc_x10382, _ctx); /*list<2107>*/;
  kk_field_addr_t _b_x268_271 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10383, _ctx)->tail, _ctx); /*@field-addr<list<2107>>*/;
  kk_integer_t _x_x1528;
  kk_integer_t _x_x1529 = kk_integer_dup(stride, _ctx); /*int*/
  _x_x1528 = kk_integer_add(lo,_x_x1529,kk_context()); /*int*/
  kk_std_core_types__cctx _x_x1530 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10383, _ctx)),_b_x268_271,kk_context()); /*ctx<0>*/
  return kk_std_core_list_stridefunction_fs__trmc_list(_x_x1528, hi, stride, f, _x_x1530, _ctx);
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.


// lift anonymous function
struct kk_std_core_list_stridefunction_fs__trmc_list_fun1534__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t hi_0;
  kk_integer_t lo_0;
  kk_integer_t stride_0;
};
static kk_box_t kk_std_core_list_stridefunction_fs__trmc_list_fun1534(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_stridefunction_fs__new_trmc_list_fun1534(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t hi_0, kk_integer_t lo_0, kk_integer_t stride_0, kk_context_t* _ctx) {
  struct kk_std_core_list_stridefunction_fs__trmc_list_fun1534__t* _self = kk_function_alloc_as(struct kk_std_core_list_stridefunction_fs__trmc_list_fun1534__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_stridefunction_fs__trmc_list_fun1534, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->hi_0 = hi_0;
  _self->lo_0 = lo_0;
  _self->stride_0 = stride_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_stridefunction_fs__trmc_list_fun1534(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx) {
  struct kk_std_core_list_stridefunction_fs__trmc_list_fun1534__t* _self = kk_function_as(struct kk_std_core_list_stridefunction_fs__trmc_list_fun1534__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2107>> */
  kk_function_t f_0 = _self->f_0; /* (int) -> 2108 2107 */
  kk_integer_t hi_0 = _self->hi_0; /* int */
  kk_integer_t lo_0 = _self->lo_0; /* int */
  kk_integer_t stride_0 = _self->stride_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(hi_0, _ctx);kk_integer_dup(lo_0, _ctx);kk_integer_dup(stride_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10381_0_294 = _b_x276; /*2107*/;
  kk_std_core_types__list _x_x1535 = kk_std_core_list_stridefunction_fs__mlift_trmc_list_10686(_acc_0, f_0, hi_0, lo_0, stride_0, _trmc_x10381_0_294, _ctx); /*list<2107>*/
  return kk_std_core_types__list_box(_x_x1535, _ctx);
}

kk_std_core_types__list kk_std_core_list_stridefunction_fs__trmc_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_integer_t stride_0, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  bool _match_x1269 = kk_integer_lte_borrow(lo_0,hi_0,kk_context()); /*bool*/;
  if (_match_x1269) {
    kk_box_t x_10773;
    kk_function_t _x_x1532 = kk_function_dup(f_0, _ctx); /*(int) -> 2108 2107*/
    kk_integer_t _x_x1531 = kk_integer_dup(lo_0, _ctx); /*int*/
    x_10773 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x1532, (_x_x1532, _x_x1531, _ctx), _ctx); /*2107*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10773, _ctx);
      kk_box_t _x_x1533 = kk_std_core_hnd_yield_extend(kk_std_core_list_stridefunction_fs__new_trmc_list_fun1534(_acc_0, f_0, hi_0, lo_0, stride_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1533, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10382_0 = kk_datatype_null(); /*list<2107>*/;
      kk_std_core_types__list _trmc_x10383_0 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10773, _trmc_x10382_0, _ctx); /*list<2107>*/;
      kk_field_addr_t _b_x282_288 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10383_0, _ctx)->tail, _ctx); /*@field-addr<list<2107>>*/;
      { // tailcall
        kk_integer_t _x_x1536;
        kk_integer_t _x_x1537 = kk_integer_dup(stride_0, _ctx); /*int*/
        _x_x1536 = kk_integer_add(lo_0,_x_x1537,kk_context()); /*int*/
        kk_std_core_types__cctx _x_x1538 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10383_0, _ctx)),_b_x282_288,kk_context()); /*ctx<0>*/
        lo_0 = _x_x1536;
        _acc_0 = _x_x1538;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(stride_0, _ctx);
    kk_integer_drop(lo_0, _ctx);
    kk_integer_drop(hi_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1539 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1539, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stridefunction_fs_list(kk_integer_t lo_1, kk_integer_t hi_1, kk_integer_t stride_1, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1540 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_stridefunction_fs__trmc_list(lo_1, hi_1, stride_1, f_1, _x_x1540, _ctx);
}
 
// Apply a function `f` to each character in a string


// lift anonymous function
struct kk_std_core_list_string_fs_map_fun1541__t {
  struct kk_function_s _base;
  kk_function_t f;
};
static kk_box_t kk_std_core_list_string_fs_map_fun1541(kk_function_t _fself, kk_box_t _b_x298, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_string_fs_new_map_fun1541(kk_function_t f, kk_context_t* _ctx) {
  struct kk_std_core_list_string_fs_map_fun1541__t* _self = kk_function_alloc_as(struct kk_std_core_list_string_fs_map_fun1541__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_string_fs_map_fun1541, kk_context());
  _self->f = f;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_string_fs_map_fun1541(kk_function_t _fself, kk_box_t _b_x298, kk_context_t* _ctx) {
  struct kk_std_core_list_string_fs_map_fun1541__t* _self = kk_function_as(struct kk_std_core_list_string_fs_map_fun1541__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (char) -> 2160 char */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);}, {}, _ctx)
  kk_char_t _x_x1542;
  kk_char_t _x_x1543 = kk_char_unbox(_b_x298, KK_OWNED, _ctx); /*char*/
  _x_x1542 = kk_function_call(kk_char_t, (kk_function_t, kk_char_t, kk_context_t*), f, (f, _x_x1543, _ctx), _ctx); /*char*/
  return kk_char_box(_x_x1542, _ctx);
}


// lift anonymous function
struct kk_std_core_list_string_fs_map_fun1545__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_string_fs_map_fun1545(kk_function_t _fself, kk_box_t _b_x303, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_string_fs_new_map_fun1545(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_string_fs_map_fun1545, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_string_fs_map_fun1545(kk_function_t _fself, kk_box_t _b_x303, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1546;
  kk_std_core_types__list _x_x1547 = kk_std_core_types__list_unbox(_b_x303, KK_OWNED, _ctx); /*list<char>*/
  _x_x1546 = kk_std_core_string_listchar_fs_string(_x_x1547, _ctx); /*string*/
  return kk_string_box(_x_x1546);
}

kk_string_t kk_std_core_list_string_fs_map(kk_string_t s, kk_function_t f, kk_context_t* _ctx) { /* forall<e> (s : string, f : (char) -> e char) -> e string */ 
  kk_std_core_types__list xs_10074 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
  kk_std_core_types__list x_10776;
  if (kk_std_core_types__is_Nil(xs_10074, _ctx)) {
    kk_function_drop(f, _ctx);
    x_10776 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
  }
  else {
    kk_std_core_types__cctx _b_x297_301 = kk_cctx_empty(kk_context()); /*ctx<list<char>>*/;
    kk_function_t _brw_x1267 = kk_std_core_list_string_fs_new_map_fun1541(f, _ctx); /*(2217) -> 2219 2218*/;
    kk_std_core_types__list _brw_x1268 = kk_std_core_list__trmc_unroll_map_10010(xs_10074, _brw_x1267, _b_x297_301, _ctx); /*list<2218>*/;
    kk_function_drop(_brw_x1267, _ctx);
    x_10776 = _brw_x1268; /*list<char>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10776, _ctx);
    kk_box_t _x_x1544 = kk_std_core_hnd_yield_extend(kk_std_core_list_string_fs_new_map_fun1545(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1544);
  }
  {
    return kk_std_core_string_listchar_fs_string(x_10776, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_5731_10011_10687(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10077, kk_std_core_types__list yy, kk_box_t _trmc_x10384, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a) -> e b, i@0@10077 : int, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10385 = kk_datatype_null(); /*list<2316>*/;
  kk_std_core_types__list _trmc_x10386 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10384, _trmc_x10385, _ctx); /*list<2316>*/;
  kk_field_addr_t _b_x310_313 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10386, _ctx)->tail, _ctx); /*@field-addr<list<2316>>*/;
  kk_std_core_types__cctx _x_x1548 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10386, _ctx)),_b_x310_313,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_5731_10011(f, yy, i_0_10077, _x_x1548, _ctx);
}
 
// lifted local: map-indexed, map-idx


// lift anonymous function
struct kk_std_core_list__trmc_unroll_lift_map_indexed_5731_10011_fun1553__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0_10077_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_5731_10011_fun1553(kk_function_t _fself, kk_box_t _b_x318, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_lift_map_indexed_5731_10011_fun1553(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0_10077_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_5731_10011_fun1553__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_5731_10011_fun1553__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_lift_map_indexed_5731_10011_fun1553, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0_10077_0 = i_0_10077_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_5731_10011_fun1553(kk_function_t _fself, kk_box_t _b_x318, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_5731_10011_fun1553__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_5731_10011_fun1553__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2316>> */
  kk_function_t f_0 = _self->f_0; /* (idx : int, value : 2315) -> 2317 2316 */
  kk_integer_t i_0_10077_0 = _self->i_0_10077_0; /* int */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2315> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0_10077_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10384_0_336 = _b_x318; /*2316*/;
  kk_std_core_types__list _x_x1554 = kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_5731_10011_10687(_acc_0, f_0, i_0_10077_0, yy_0, _trmc_x10384_0_336, _ctx); /*list<2316>*/
  return kk_std_core_types__list_box(_x_x1554, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_indexed_5731_10011(kk_function_t f_0, kk_std_core_types__list ys, kk_integer_t i, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1549 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1549->head;
    kk_std_core_types__list yy_0 = _con_x1549->tail;
    kk_reuse_t _ru_x1333 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1333 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_integer_t i_0_10077_0;
    kk_integer_t _x_x1550 = kk_integer_dup(i, _ctx); /*int*/
    i_0_10077_0 = kk_integer_add_small_const(_x_x1550, 1, _ctx); /*int*/
    kk_box_t x_10780;
    kk_function_t _x_x1551 = kk_function_dup(f_0, _ctx); /*(idx : int, value : 2315) -> 2317 2316*/
    x_10780 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x1551, (_x_x1551, i, y, _ctx), _ctx); /*2316*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1333,kk_context());
      kk_box_drop(x_10780, _ctx);
      kk_box_t _x_x1552 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_lift_map_indexed_5731_10011_fun1553(_acc_0, f_0, i_0_10077_0, yy_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1552, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10385_0 = kk_datatype_null(); /*list<2316>*/;
      kk_std_core_types__list _trmc_x10386_0 = kk_std_core_types__new_Cons(_ru_x1333, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10780, _trmc_x10385_0, _ctx); /*list<2316>*/;
      kk_field_addr_t _b_x324_330 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10386_0, _ctx)->tail, _ctx); /*@field-addr<list<2316>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1555 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10386_0, _ctx)),_b_x324_330,kk_context()); /*ctx<0>*/
        ys = yy_0;
        i = i_0_10077_0;
        _acc_0 = _x_x1555;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(i, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1556 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1556, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-indexed, map-idx

kk_std_core_types__list kk_std_core_list__unroll_lift_map_indexed_5731_10011(kk_function_t f_1, kk_std_core_types__list ys_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1557 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_5731_10011(f_1, ys_0, i_0, _x_x1557, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_peek_5732_10012_10688(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list yy, kk_box_t _trmc_x10387, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10388 = kk_datatype_null(); /*list<2378>*/;
  kk_std_core_types__list _trmc_x10389 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10387, _trmc_x10388, _ctx); /*list<2378>*/;
  kk_field_addr_t _b_x342_345 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10389, _ctx)->tail, _ctx); /*@field-addr<list<2378>>*/;
  kk_std_core_types__cctx _x_x1560 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10389, _ctx)),_b_x342_345,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_peek_5732_10012(f, yy, _x_x1560, _ctx);
}
 
// lifted local: map-peek, mappeek


// lift anonymous function
struct kk_std_core_list__trmc_unroll_lift_map_peek_5732_10012_fun1565__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_lift_map_peek_5732_10012_fun1565(kk_function_t _fself, kk_box_t _b_x350, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_lift_map_peek_5732_10012_fun1565(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_peek_5732_10012_fun1565__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_lift_map_peek_5732_10012_fun1565__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_lift_map_peek_5732_10012_fun1565, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_lift_map_peek_5732_10012_fun1565(kk_function_t _fself, kk_box_t _b_x350, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_peek_5732_10012_fun1565__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_lift_map_peek_5732_10012_fun1565__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2378>> */
  kk_function_t f_0 = _self->f_0; /* (value : 2377, rest : list<2377>) -> 2379 2378 */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2377> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10387_0_368 = _b_x350; /*2378*/;
  kk_std_core_types__list _x_x1566 = kk_std_core_list__mlift_trmc_unroll_lift_map_peek_5732_10012_10688(_acc_0, f_0, yy_0, _trmc_x10387_0_368, _ctx); /*list<2378>*/
  return kk_std_core_types__list_box(_x_x1566, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_peek_5732_10012(kk_function_t f_0, kk_std_core_types__list ys, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1561 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1561->head;
    kk_std_core_types__list yy_0 = _con_x1561->tail;
    kk_reuse_t _ru_x1334 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1334 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_box_t x_10789;
    kk_function_t _x_x1563 = kk_function_dup(f_0, _ctx); /*(value : 2377, rest : list<2377>) -> 2379 2378*/
    kk_std_core_types__list _x_x1562 = kk_std_core_types__list_dup(yy_0, _ctx); /*list<2377>*/
    x_10789 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_std_core_types__list, kk_context_t*), _x_x1563, (_x_x1563, y, _x_x1562, _ctx), _ctx); /*2378*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1334,kk_context());
      kk_box_drop(x_10789, _ctx);
      kk_box_t _x_x1564 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_lift_map_peek_5732_10012_fun1565(_acc_0, f_0, yy_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1564, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10388_0 = kk_datatype_null(); /*list<2378>*/;
      kk_std_core_types__list _trmc_x10389_0 = kk_std_core_types__new_Cons(_ru_x1334, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10789, _trmc_x10388_0, _ctx); /*list<2378>*/;
      kk_field_addr_t _b_x356_362 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10389_0, _ctx)->tail, _ctx); /*@field-addr<list<2378>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1567 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10389_0, _ctx)),_b_x356_362,kk_context()); /*ctx<0>*/
        ys = yy_0;
        _acc_0 = _x_x1567;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1568 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1568, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-peek, mappeek

kk_std_core_types__list kk_std_core_list__unroll_lift_map_peek_5732_10012(kk_function_t f_1, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1569 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_peek_5732_10012(f_1, ys_0, _x_x1569, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_peek_5733_10013_10689(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10085, kk_std_core_types__list yy, kk_box_t _trmc_x10390, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a, rest : list<a>) -> e b, i@0@10085 : int, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10391 = kk_datatype_null(); /*list<2449>*/;
  kk_std_core_types__list _trmc_x10392 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10390, _trmc_x10391, _ctx); /*list<2449>*/;
  kk_field_addr_t _b_x374_377 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10392, _ctx)->tail, _ctx); /*@field-addr<list<2449>>*/;
  kk_std_core_types__cctx _x_x1572 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10392, _ctx)),_b_x374_377,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_peek_5733_10013(f, yy, i_0_10085, _x_x1572, _ctx);
}
 
// lifted local: map-indexed-peek, mapidx


// lift anonymous function
struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_5733_10013_fun1578__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0_10085_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_peek_5733_10013_fun1578(kk_function_t _fself, kk_box_t _b_x382, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_lift_map_indexed_peek_5733_10013_fun1578(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0_10085_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_5733_10013_fun1578__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_5733_10013_fun1578__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_lift_map_indexed_peek_5733_10013_fun1578, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0_10085_0 = i_0_10085_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_peek_5733_10013_fun1578(kk_function_t _fself, kk_box_t _b_x382, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_5733_10013_fun1578__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_5733_10013_fun1578__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2449>> */
  kk_function_t f_0 = _self->f_0; /* (idx : int, value : 2448, rest : list<2448>) -> 2450 2449 */
  kk_integer_t i_0_10085_0 = _self->i_0_10085_0; /* int */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2448> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0_10085_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10390_0_400 = _b_x382; /*2449*/;
  kk_std_core_types__list _x_x1579 = kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_peek_5733_10013_10689(_acc_0, f_0, i_0_10085_0, yy_0, _trmc_x10390_0_400, _ctx); /*list<2449>*/
  return kk_std_core_types__list_box(_x_x1579, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_indexed_peek_5733_10013(kk_function_t f_0, kk_std_core_types__list ys, kk_integer_t i, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1573 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1573->head;
    kk_std_core_types__list yy_0 = _con_x1573->tail;
    kk_reuse_t _ru_x1335 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1335 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_integer_t i_0_10085_0;
    kk_integer_t _x_x1574 = kk_integer_dup(i, _ctx); /*int*/
    i_0_10085_0 = kk_integer_add_small_const(_x_x1574, 1, _ctx); /*int*/
    kk_box_t x_10796;
    kk_function_t _x_x1576 = kk_function_dup(f_0, _ctx); /*(idx : int, value : 2448, rest : list<2448>) -> 2450 2449*/
    kk_std_core_types__list _x_x1575 = kk_std_core_types__list_dup(yy_0, _ctx); /*list<2448>*/
    x_10796 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_std_core_types__list, kk_context_t*), _x_x1576, (_x_x1576, i, y, _x_x1575, _ctx), _ctx); /*2449*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1335,kk_context());
      kk_box_drop(x_10796, _ctx);
      kk_box_t _x_x1577 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_lift_map_indexed_peek_5733_10013_fun1578(_acc_0, f_0, i_0_10085_0, yy_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1577, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10391_0 = kk_datatype_null(); /*list<2449>*/;
      kk_std_core_types__list _trmc_x10392_0 = kk_std_core_types__new_Cons(_ru_x1335, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10796, _trmc_x10391_0, _ctx); /*list<2449>*/;
      kk_field_addr_t _b_x388_394 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10392_0, _ctx)->tail, _ctx); /*@field-addr<list<2449>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1580 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10392_0, _ctx)),_b_x388_394,kk_context()); /*ctx<0>*/
        ys = yy_0;
        i = i_0_10085_0;
        _acc_0 = _x_x1580;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(i, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1581 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1581, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-indexed-peek, mapidx

kk_std_core_types__list kk_std_core_list__unroll_lift_map_indexed_peek_5733_10013(kk_function_t f_1, kk_std_core_types__list ys_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1582 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_peek_5733_10013(f_1, ys_0, i_0, _x_x1582, _ctx);
}
 
// Create a list of `n` repeated elements `x`

kk_std_core_types__list kk_std_core_list__trmc_replicate(kk_box_t x, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (x : a, n : int, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  bool _match_x1262 = kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1262) {
    kk_std_core_types__list _trmc_x10393 = kk_datatype_null(); /*list<2508>*/;
    kk_std_core_types__list _trmc_x10394;
    kk_box_t _x_x1585 = kk_box_dup(x, _ctx); /*2508*/
    _trmc_x10394 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1585, _trmc_x10393, _ctx); /*list<2508>*/
    kk_field_addr_t _b_x406_411 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10394, _ctx)->tail, _ctx); /*@field-addr<list<2508>>*/;
    { // tailcall
      kk_integer_t _x_x1586 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
      kk_std_core_types__cctx _x_x1587 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10394, _ctx)),_b_x406_411,kk_context()); /*ctx<0>*/
      n = _x_x1586;
      _acc = _x_x1587;
      goto kk__tailcall;
    }
  }
  {
    kk_box_drop(x, _ctx);
    kk_integer_drop(n, _ctx);
    kk_box_t _x_x1588 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1588, KK_OWNED, _ctx);
  }
}
 
// Create a list of `n` repeated elements `x`

kk_std_core_types__list kk_std_core_list_replicate(kk_box_t x_0, kk_integer_t n_0, kk_context_t* _ctx) { /* forall<a> (x : a, n : int) -> list<a> */ 
  kk_std_core_types__cctx _x_x1589 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_replicate(x_0, n_0, _x_x1589, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_remove_10347_10690(kk_std_core_types__cctx _acc, kk_box_t _uniq_x_10294, kk_std_core_types__list _uniq_xx_10295, kk_function_t pred, bool _y_x10532, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, a, list<a>, pred : (a) -> e bool, bool) -> e list<a> */ 
  if (_y_x10532) {
    kk_box_drop(_uniq_x_10294, _ctx);
    return kk_std_core_list__trmc_lift_remove_10347(pred, _uniq_xx_10295, _acc, _ctx);
  }
  {
    kk_std_core_types__list _trmc_x10395 = kk_datatype_null(); /*list<2548>*/;
    kk_std_core_types__list _trmc_x10396 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _uniq_x_10294, _trmc_x10395, _ctx); /*list<2548>*/;
    kk_field_addr_t _b_x422_425 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10396, _ctx)->tail, _ctx); /*@field-addr<list<2548>>*/;
    kk_std_core_types__cctx _x_x1590 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10396, _ctx)),_b_x422_425,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_lift_remove_10347(pred, _uniq_xx_10295, _x_x1590, _ctx);
  }
}
 
// lifted local: remove, @spec-x10299
// specialized: std/core/list/@unroll-filter@10007, on parameters @uniq-pred@10292, using:
// @uniq-pred@10292 = fn<(e :: E)>(x: 2548){
//   std/core/types/@open<(total :: E),(e :: E),(b : bool) -> bool,(b : bool) -> (e :: E) bool>((fn(b: bool){
//     (match (b) {
//       ((std/core/types/True() : bool ) as @pat@0: bool)
//          -> std/core/types/False;
//       ((@skip std/core/types/False() : bool ) as @pat@0@0: bool)
//          -> std/core/types/True;
//     });
//   }))((pred(x)));
// }


// lift anonymous function
struct kk_std_core_list__trmc_lift_remove_10347_fun1595__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_box_t _uniq_x_10294_0;
  kk_std_core_types__list _uniq_xx_10295_0;
  kk_function_t pred_0;
};
static kk_box_t kk_std_core_list__trmc_lift_remove_10347_fun1595(kk_function_t _fself, kk_box_t _b_x430, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_lift_remove_10347_fun1595(kk_std_core_types__cctx _acc_0, kk_box_t _uniq_x_10294_0, kk_std_core_types__list _uniq_xx_10295_0, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_remove_10347_fun1595__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_lift_remove_10347_fun1595__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_lift_remove_10347_fun1595, kk_context());
  _self->_acc_0 = _acc_0;
  _self->_uniq_x_10294_0 = _uniq_x_10294_0;
  _self->_uniq_xx_10295_0 = _uniq_xx_10295_0;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_lift_remove_10347_fun1595(kk_function_t _fself, kk_box_t _b_x430, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_remove_10347_fun1595__t* _self = kk_function_as(struct kk_std_core_list__trmc_lift_remove_10347_fun1595__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2548>> */
  kk_box_t _uniq_x_10294_0 = _self->_uniq_x_10294_0; /* 2548 */
  kk_std_core_types__list _uniq_xx_10295_0 = _self->_uniq_xx_10295_0; /* list<2548> */
  kk_function_t pred_0 = _self->pred_0; /* (2548) -> 2549 bool */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_box_dup(_uniq_x_10294_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10295_0, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  bool _y_x10532_0_448 = kk_bool_unbox(_b_x430); /*bool*/;
  kk_std_core_types__list _x_x1596 = kk_std_core_list__mlift_trmc_lift_remove_10347_10690(_acc_0, _uniq_x_10294_0, _uniq_xx_10295_0, pred_0, _y_x10532_0_448, _ctx); /*list<2548>*/
  return kk_std_core_types__list_box(_x_x1596, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_lift_remove_10347(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10291, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (pred : (a) -> e bool, list<a>, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10291, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1591 = kk_std_core_types__as_Cons(_uniq_xs_10291, _ctx);
    kk_box_t _uniq_x_10294_0 = _con_x1591->head;
    kk_std_core_types__list _uniq_xx_10295_0 = _con_x1591->tail;
    kk_reuse_t _ru_x1336 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10291, _ctx)) {
      _ru_x1336 = (kk_datatype_ptr_reuse(_uniq_xs_10291, _ctx));
    }
    else {
      kk_box_dup(_uniq_x_10294_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10295_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10291, _ctx);
    }
    bool x_10805;
    kk_function_t _x_x1593 = kk_function_dup(pred_0, _ctx); /*(2548) -> 2549 bool*/
    kk_box_t _x_x1592 = kk_box_dup(_uniq_x_10294_0, _ctx); /*2548*/
    x_10805 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1593, (_x_x1593, _x_x1592, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1336,kk_context());
      kk_box_t _x_x1594 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_lift_remove_10347_fun1595(_acc_0, _uniq_x_10294_0, _uniq_xx_10295_0, pred_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1594, KK_OWNED, _ctx);
    }
    if (x_10805) {
      kk_reuse_drop(_ru_x1336,kk_context());
      kk_box_drop(_uniq_x_10294_0, _ctx);
      { // tailcall
        _uniq_xs_10291 = _uniq_xx_10295_0;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list _trmc_x10395_0 = kk_datatype_null(); /*list<2548>*/;
      kk_std_core_types__list _trmc_x10396_0 = kk_std_core_types__new_Cons(_ru_x1336, kk_field_index_of(struct kk_std_core_types_Cons, tail), _uniq_x_10294_0, _trmc_x10395_0, _ctx); /*list<2548>*/;
      kk_field_addr_t _b_x436_442 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10396_0, _ctx)->tail, _ctx); /*@field-addr<list<2548>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1597 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10396_0, _ctx)),_b_x436_442,kk_context()); /*ctx<0>*/
        _uniq_xs_10291 = _uniq_xx_10295_0;
        _acc_0 = _x_x1597;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x1598 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1598, KK_OWNED, _ctx);
  }
}
 
// lifted local: remove, @spec-x10299
// specialized: std/core/list/@unroll-filter@10007, on parameters @uniq-pred@10292, using:
// @uniq-pred@10292 = fn<(e :: E)>(x: 2548){
//   std/core/types/@open<(total :: E),(e :: E),(b : bool) -> bool,(b : bool) -> (e :: E) bool>((fn(b: bool){
//     (match (b) {
//       ((std/core/types/True() : bool ) as @pat@0: bool)
//          -> std/core/types/False;
//       ((@skip std/core/types/False() : bool ) as @pat@0@0: bool)
//          -> std/core/types/True;
//     });
//   }))((pred(x)));
// }

kk_std_core_types__list kk_std_core_list__lift_remove_10347(kk_function_t pred_1, kk_std_core_types__list _uniq_xs_10291_0, kk_context_t* _ctx) { /* forall<a,e> (pred : (a) -> e bool, list<a>) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1599 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_remove_10347(pred_1, _uniq_xs_10291_0, _x_x1599, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2 kk_std_core_list__mlift_unroll_partition_acc_10014_10691(kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_function_t pred, kk_box_t x, kk_std_core_types__list xx, bool _y_x10540, kk_context_t* _ctx) { /* forall<a,e> (acc1 : ctx<list<a>>, acc2 : ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e (list<a>, list<a>) */ 
  if (_y_x10540) {
    kk_std_core_types__list _cctx_x2651;
    kk_std_core_types__list _x_x1601 = kk_datatype_null(); /*list<2711>*/
    _cctx_x2651 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1601, _ctx); /*list<2711>*/
    kk_field_addr_t _cctx_x2652 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2651, _ctx)->tail, _ctx); /*@field-addr<list<2711>>*/;
    kk_std_core_types__list _b_x455_465 = _cctx_x2651; /*list<2711>*/;
    kk_field_addr_t _b_x456_466 = _cctx_x2652; /*@field-addr<list<2711>>*/;
    kk_std_core_types__cctx _own_x1259;
    kk_std_core_types__cctx _x_x1602 = kk_cctx_create((kk_std_core_types__list_box(_b_x455_465, _ctx)),_b_x456_466,kk_context()); /*cctx<0,1>*/
    _own_x1259 = kk_cctx_compose(acc1,_x_x1602,kk_context()); /*cctx<394,396>*/
    kk_std_core_types__tuple2 _brw_x1260 = kk_std_core_list__unroll_partition_acc_10014(xx, pred, _own_x1259, acc2, _ctx); /*(list<2711>, list<2711>)*/;
    kk_function_drop(pred, _ctx);
    return _brw_x1260;
  }
  {
    kk_std_core_types__list _cctx_x2698;
    kk_std_core_types__list _x_x1603 = kk_datatype_null(); /*list<2711>*/
    _cctx_x2698 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1603, _ctx); /*list<2711>*/
    kk_field_addr_t _cctx_x2699 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2698, _ctx)->tail, _ctx); /*@field-addr<list<2711>>*/;
    kk_std_core_types__list _b_x463_467 = _cctx_x2698; /*list<2711>*/;
    kk_field_addr_t _b_x464_468 = _cctx_x2699; /*@field-addr<list<2711>>*/;
    kk_std_core_types__cctx _own_x1257;
    kk_std_core_types__cctx _x_x1604 = kk_cctx_create((kk_std_core_types__list_box(_b_x463_467, _ctx)),_b_x464_468,kk_context()); /*cctx<0,1>*/
    _own_x1257 = kk_cctx_compose(acc2,_x_x1604,kk_context()); /*cctx<394,396>*/
    kk_std_core_types__tuple2 _brw_x1258 = kk_std_core_list__unroll_partition_acc_10014(xx, pred, acc1, _own_x1257, _ctx); /*(list<2711>, list<2711>)*/;
    kk_function_drop(pred, _ctx);
    return _brw_x1258;
  }
}


// lift anonymous function
struct kk_std_core_list__unroll_partition_acc_10014_fun1612__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx acc1_0;
  kk_std_core_types__cctx acc2_0;
  kk_function_t pred_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_partition_acc_10014_fun1612(kk_function_t _fself, kk_box_t _b_x476, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_partition_acc_10014_fun1612(kk_std_core_types__cctx acc1_0, kk_std_core_types__cctx acc2_0, kk_function_t pred_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_partition_acc_10014_fun1612__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_partition_acc_10014_fun1612__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_partition_acc_10014_fun1612, kk_context());
  _self->acc1_0 = acc1_0;
  _self->acc2_0 = acc2_0;
  _self->pred_0 = pred_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_partition_acc_10014_fun1612(kk_function_t _fself, kk_box_t _b_x476, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_partition_acc_10014_fun1612__t* _self = kk_function_as(struct kk_std_core_list__unroll_partition_acc_10014_fun1612__t*, _fself, _ctx);
  kk_std_core_types__cctx acc1_0 = _self->acc1_0; /* ctx<list<2711>> */
  kk_std_core_types__cctx acc2_0 = _self->acc2_0; /* ctx<list<2711>> */
  kk_function_t pred_0 = _self->pred_0; /* (2711) -> 2712 bool */
  kk_box_t x_0 = _self->x_0; /* 2711 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2711> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(acc1_0, _ctx);kk_std_core_types__cctx_dup(acc2_0, _ctx);kk_function_dup(pred_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10540_0_504 = kk_bool_unbox(_b_x476); /*bool*/;
  kk_std_core_types__tuple2 _x_x1613 = kk_std_core_list__mlift_unroll_partition_acc_10014_10691(acc1_0, acc2_0, pred_0, x_0, xx_0, _y_x10540_0_504, _ctx); /*(list<2711>, list<2711>)*/
  return kk_std_core_types__tuple2_box(_x_x1613, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_list__unroll_partition_acc_10014(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx acc1_0, kk_std_core_types__cctx acc2_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : ctx<list<a>>, acc2 : ctx<list<a>>) -> e (list<a>, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x473_493;
    kk_box_t _x_x1605 = kk_cctx_apply(acc1_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x473_493 = kk_std_core_types__list_unbox(_x_x1605, KK_OWNED, _ctx); /*list<2711>*/
    kk_std_core_types__list _b_x474_494;
    kk_box_t _x_x1606 = kk_cctx_apply(acc2_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x474_494 = kk_std_core_types__list_unbox(_x_x1606, KK_OWNED, _ctx); /*list<2711>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x473_493, _ctx), kk_std_core_types__list_box(_b_x474_494, _ctx), _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1607 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1607->head;
    kk_std_core_types__list xx_0 = _con_x1607->tail;
    kk_reuse_t _ru_x1337 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1337 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10810;
    kk_function_t _x_x1609 = kk_function_dup(pred_0, _ctx); /*(2711) -> 2712 bool*/
    kk_box_t _x_x1608 = kk_box_dup(x_0, _ctx); /*2711*/
    x_1_10810 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1609, (_x_x1609, _x_x1608, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1337,kk_context());
      kk_box_t _x_x1610;
      kk_function_t _x_x1611;
      kk_function_dup(pred_0, _ctx);
      _x_x1611 = kk_std_core_list__new_unroll_partition_acc_10014_fun1612(acc1_0, acc2_0, pred_0, x_0, xx_0, _ctx); /*(2418) -> 2420 2419*/
      _x_x1610 = kk_std_core_hnd_yield_extend(_x_x1611, _ctx); /*2419*/
      return kk_std_core_types__tuple2_unbox(_x_x1610, KK_OWNED, _ctx);
    }
    if (x_1_10810) {
      kk_std_core_types__list _cctx_x2651_0;
      kk_std_core_types__list _x_x1614 = kk_datatype_null(); /*list<2711>*/
      _cctx_x2651_0 = kk_std_core_types__new_Cons(_ru_x1337, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _x_x1614, _ctx); /*list<2711>*/
      kk_field_addr_t _cctx_x2652_0 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2651_0, _ctx)->tail, _ctx); /*@field-addr<list<2711>>*/;
      kk_std_core_types__list _b_x483_500 = _cctx_x2651_0; /*list<2711>*/;
      kk_field_addr_t _b_x484_501 = _cctx_x2652_0; /*@field-addr<list<2711>>*/;
      kk_std_core_types__cctx _own_x1256;
      kk_std_core_types__cctx _x_x1615 = kk_cctx_create((kk_std_core_types__list_box(_b_x483_500, _ctx)),_b_x484_501,kk_context()); /*cctx<0,1>*/
      _own_x1256 = kk_cctx_compose(acc1_0,_x_x1615,kk_context()); /*cctx<394,396>*/
      { // tailcall
        xs = xx_0;
        acc1_0 = _own_x1256;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list _cctx_x2698_0;
      kk_std_core_types__list _x_x1616 = kk_datatype_null(); /*list<2711>*/
      _cctx_x2698_0 = kk_std_core_types__new_Cons(_ru_x1337, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _x_x1616, _ctx); /*list<2711>*/
      kk_field_addr_t _cctx_x2699_0 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2698_0, _ctx)->tail, _ctx); /*@field-addr<list<2711>>*/;
      kk_std_core_types__list _b_x491_502 = _cctx_x2698_0; /*list<2711>*/;
      kk_field_addr_t _b_x492_503 = _cctx_x2699_0; /*@field-addr<list<2711>>*/;
      kk_std_core_types__cctx _own_x1255;
      kk_std_core_types__cctx _x_x1617 = kk_cctx_create((kk_std_core_types__list_box(_b_x491_502, _ctx)),_b_x492_503,kk_context()); /*cctx<0,1>*/
      _own_x1255 = kk_cctx_compose(acc2_0,_x_x1617,kk_context()); /*cctx<394,396>*/
      { // tailcall
        xs = xx_0;
        acc2_0 = _own_x1255;
        goto kk__tailcall;
      }
    }
  }
}
 
// Partition a list in two lists where the first list contains
// those elements that satisfy the given predicate `pred`.
// For example: `partition([1,2,3],odd?) == ([1,3],[2])`

kk_std_core_types__tuple2 kk_std_core_list_partition(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e (list<a>, list<a>) */ 
  kk_std_core_types__cctx acc1_10094 = kk_cctx_empty(kk_context()); /*ctx<list<2758>>*/;
  kk_std_core_types__cctx acc2_10095 = kk_cctx_empty(kk_context()); /*ctx<list<2758>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x521_523;
    kk_box_t _x_x1620 = kk_cctx_apply(acc1_10094,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x521_523 = kk_std_core_types__list_unbox(_x_x1620, KK_OWNED, _ctx); /*list<2758>*/
    kk_std_core_types__list _b_x522_524;
    kk_box_t _x_x1621 = kk_cctx_apply(acc2_10095,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x522_524 = kk_std_core_types__list_unbox(_x_x1621, KK_OWNED, _ctx); /*list<2758>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x521_523, _ctx), kk_std_core_types__list_box(_b_x522_524, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_partition_acc_10014(xs, pred, acc1_10094, acc2_10095, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_list__mlift_lift_lookup_10348_10692(kk_std_core_types__tuple2 _uniq_x_10305, kk_std_core_types__list _uniq_xx_10306, kk_function_t pred, bool _y_x10549, kk_context_t* _ctx) { /* forall<a,b,e> ((a, b), list<(a, b)>, pred : (a) -> e bool, bool) -> e maybe<b> */ 
  if (_y_x10549) {
    kk_function_drop(pred, _ctx);
    kk_std_core_types__list_drop(_uniq_xx_10306, _ctx);
    kk_box_t _x_x1622;
    {
      kk_box_t _x_0 = _uniq_x_10305.snd;
      kk_box_dup(_x_0, _ctx);
      kk_std_core_types__tuple2_drop(_uniq_x_10305, _ctx);
      _x_x1622 = _x_0; /*2895*/
    }
    return kk_std_core_types__new_Just(_x_x1622, _ctx);
  }
  {
    kk_std_core_types__tuple2_drop(_uniq_x_10305, _ctx);
    return kk_std_core_list__lift_lookup_10348(pred, _uniq_xx_10306, _ctx);
  }
}
 
// lifted local: lookup, @spec-x10309
// specialized: std/core/list/@unroll-foreach-while@10009, on parameters @uniq-action@10302, using:
// @uniq-action@10302 = fn<(e :: E)>(kv: (2894, 2895)){
//   match ((pred((std/core/types/@open<(total :: E),(e :: E),(tuple2 : (a, b)) -> a,(tuple2 : (a, b)) -> (e :: E) a>((fn(tuple2: (2894, 2895)){
//     (match (tuple2) {
//       ((@skip std/core/types/Tuple2((@x: 2894) : a, (@pat@0@0: 2895) : a) : (a, b) ) as @pat@1: (2894, 2895))
//          -> @x;
//     });
//   }))(kv))))) {
//     ((std/core/types/True() : bool ) as @pat@2: bool)
//        -> std/core/types/Just<a>((std/core/types/@open<(total :: E),(e :: E),(tuple2 : (a, b)) -> b,(tuple2 : (a, b)) -> (e :: E) b>((fn(tuple2@0: (2894, 2895)){
//         (match (tuple2@0) {
//           ((@skip std/core/types/Tuple2((@pat@0@1: 2894) : a, (@x@0: 2895) : a) : (a, b) ) as @pat@3: (2894, 2895))
//              -> @x@0;
//         });
//       }))(kv)));
//     ((@skip std/core/types/False() : bool ) as @pat@0@2: bool)
//        -> std/core/types/Nothing<a>;
//   };
// }


// lift anonymous function
struct kk_std_core_list__lift_lookup_10348_fun1627__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2 _uniq_x_10305_0;
  kk_std_core_types__list _uniq_xx_10306_0;
  kk_function_t pred_0;
};
static kk_box_t kk_std_core_list__lift_lookup_10348_fun1627(kk_function_t _fself, kk_box_t _b_x531, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_lookup_10348_fun1627(kk_std_core_types__tuple2 _uniq_x_10305_0, kk_std_core_types__list _uniq_xx_10306_0, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_lookup_10348_fun1627__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_lookup_10348_fun1627__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_lookup_10348_fun1627, kk_context());
  _self->_uniq_x_10305_0 = _uniq_x_10305_0;
  _self->_uniq_xx_10306_0 = _uniq_xx_10306_0;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_lookup_10348_fun1627(kk_function_t _fself, kk_box_t _b_x531, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_lookup_10348_fun1627__t* _self = kk_function_as(struct kk_std_core_list__lift_lookup_10348_fun1627__t*, _fself, _ctx);
  kk_std_core_types__tuple2 _uniq_x_10305_0 = _self->_uniq_x_10305_0; /* (2894, 2895) */
  kk_std_core_types__list _uniq_xx_10306_0 = _self->_uniq_xx_10306_0; /* list<(2894, 2895)> */
  kk_function_t pred_0 = _self->pred_0; /* (2894) -> 2896 bool */
  kk_drop_match(_self, {kk_std_core_types__tuple2_dup(_uniq_x_10305_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10306_0, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  bool _y_x10549_0_533 = kk_bool_unbox(_b_x531); /*bool*/;
  kk_std_core_types__maybe _x_x1628 = kk_std_core_list__mlift_lift_lookup_10348_10692(_uniq_x_10305_0, _uniq_xx_10306_0, pred_0, _y_x10549_0_533, _ctx); /*maybe<2895>*/
  return kk_std_core_types__maybe_box(_x_x1628, _ctx);
}

kk_std_core_types__maybe kk_std_core_list__lift_lookup_10348(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10301, kk_context_t* _ctx) { /* forall<a,b,e> (pred : (a) -> e bool, list<(a, b)>) -> e maybe<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_xs_10301, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1623 = kk_std_core_types__as_Cons(_uniq_xs_10301, _ctx);
    kk_box_t _box_x529 = _con_x1623->head;
    kk_std_core_types__list _uniq_xx_10306_0 = _con_x1623->tail;
    kk_std_core_types__tuple2 _uniq_x_10305_0 = kk_std_core_types__tuple2_unbox(_box_x529, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10301, _ctx)) {
      kk_std_core_types__tuple2_dup(_uniq_x_10305_0, _ctx);
      kk_box_drop(_box_x529, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10301, _ctx);
    }
    else {
      kk_std_core_types__tuple2_dup(_uniq_x_10305_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10306_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10301, _ctx);
    }
    bool x_10813;
    kk_function_t _x_x1625 = kk_function_dup(pred_0, _ctx); /*(2894) -> 2896 bool*/
    kk_box_t _x_x1624;
    {
      kk_box_t _x = _uniq_x_10305_0.fst;
      kk_box_dup(_x, _ctx);
      _x_x1624 = _x; /*2894*/
    }
    x_10813 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1625, (_x_x1625, _x_x1624, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1626 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_lookup_10348_fun1627(_uniq_x_10305_0, _uniq_xx_10306_0, pred_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x1626, KK_OWNED, _ctx);
    }
    if (x_10813) {
      kk_function_drop(pred_0, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10306_0, _ctx);
      kk_box_t _x_x1629;
      {
        kk_box_t _x_0_0 = _uniq_x_10305_0.snd;
        kk_box_dup(_x_0_0, _ctx);
        kk_std_core_types__tuple2_drop(_uniq_x_10305_0, _ctx);
        _x_x1629 = _x_0_0; /*2895*/
      }
      return kk_std_core_types__new_Just(_x_x1629, _ctx);
    }
    {
      kk_std_core_types__tuple2_drop(_uniq_x_10305_0, _ctx);
      { // tailcall
        _uniq_xs_10301 = _uniq_xx_10306_0;
        goto kk__tailcall;
      }
    }
  }
}
 
// monadic lift

kk_integer_t kk_std_core_list__mlift_unroll_index_of_acc_10015_10693(kk_integer_t idx, kk_function_t pred, kk_std_core_types__list xx, bool _y_x10556, kk_context_t* _ctx) { /* forall<a,e> (idx : int, pred : (a) -> e bool, xx : list<a>, bool) -> e int */ 
  if (_y_x10556) {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(pred, _ctx);
    return idx;
  }
  {
    kk_integer_t _x_x1630 = kk_integer_add_small_const(idx, 1, _ctx); /*int*/
    return kk_std_core_list__unroll_index_of_acc_10015(xx, pred, _x_x1630, _ctx);
  }
}


// lift anonymous function
struct kk_std_core_list__unroll_index_of_acc_10015_fun1634__t {
  struct kk_function_s _base;
  kk_integer_t idx_0;
  kk_function_t pred_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_index_of_acc_10015_fun1634(kk_function_t _fself, kk_box_t _b_x535, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_index_of_acc_10015_fun1634(kk_integer_t idx_0, kk_function_t pred_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_index_of_acc_10015_fun1634__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_index_of_acc_10015_fun1634__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_index_of_acc_10015_fun1634, kk_context());
  _self->idx_0 = idx_0;
  _self->pred_0 = pred_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_index_of_acc_10015_fun1634(kk_function_t _fself, kk_box_t _b_x535, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_index_of_acc_10015_fun1634__t* _self = kk_function_as(struct kk_std_core_list__unroll_index_of_acc_10015_fun1634__t*, _fself, _ctx);
  kk_integer_t idx_0 = _self->idx_0; /* int */
  kk_function_t pred_0 = _self->pred_0; /* (2951) -> 2952 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2951> */
  kk_drop_match(_self, {kk_integer_dup(idx_0, _ctx);kk_function_dup(pred_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10556_0_537 = kk_bool_unbox(_b_x535); /*bool*/;
  kk_integer_t _x_x1635 = kk_std_core_list__mlift_unroll_index_of_acc_10015_10693(idx_0, pred_0, xx_0, _y_x10556_0_537, _ctx); /*int*/
  return kk_integer_box(_x_x1635, _ctx);
}

kk_integer_t kk_std_core_list__unroll_index_of_acc_10015(kk_std_core_types__list xs, kk_function_t pred_0, kk_integer_t idx_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, idx : int) -> e int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1631 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1631->head;
    kk_std_core_types__list xx_0 = _con_x1631->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10816;
    kk_function_t _x_x1632 = kk_function_dup(pred_0, _ctx); /*(2951) -> 2952 bool*/
    x_0_10816 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1632, (_x_x1632, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1633 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_index_of_acc_10015_fun1634(idx_0, pred_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_integer_unbox(_x_x1633, _ctx);
    }
    if (x_0_10816) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(pred_0, _ctx);
      return idx_0;
    }
    { // tailcall
      kk_integer_t _x_x1636 = kk_integer_add_small_const(idx_0, 1, _ctx); /*int*/
      xs = xx_0;
      idx_0 = _x_x1636;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(pred_0, _ctx);
    kk_integer_drop(idx_0, _ctx);
    return kk_integer_from_small(-1);
  }
}
 
// monadic lift

kk_unit_t kk_std_core_list__mlift_unroll_foreach_10016_10694(kk_function_t action, kk_std_core_types__list xx, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (action : (a) -> e (), xx : list<a>, wild_ : ()) -> e () */ 
  kk_std_core_list__unroll_foreach_10016(xx, action, _ctx); return kk_Unit;
}
 
// Invoke `action` for each element of a list


// lift anonymous function
struct kk_std_core_list__unroll_foreach_10016_fun1640__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_foreach_10016_fun1640(kk_function_t _fself, kk_box_t _b_x539, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_foreach_10016_fun1640(kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_10016_fun1640__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_foreach_10016_fun1640__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_foreach_10016_fun1640, kk_context());
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_foreach_10016_fun1640(kk_function_t _fself, kk_box_t _b_x539, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_10016_fun1640__t* _self = kk_function_as(struct kk_std_core_list__unroll_foreach_10016_fun1640__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (3031) -> 3032 () */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3031> */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_541 = kk_Unit;
  kk_unit_unbox(_b_x539);
  kk_unit_t _x_x1641 = kk_Unit;
  kk_std_core_list__mlift_unroll_foreach_10016_10694(action_0, xx_0, wild___0_541, _ctx);
  return kk_unit_box(_x_x1641);
}

kk_unit_t kk_std_core_list__unroll_foreach_10016(kk_std_core_types__list xs, kk_function_t action_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1637 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1637->head;
    kk_std_core_types__list xx_0 = _con_x1637->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_unit_t x_0_10819 = kk_Unit;
    kk_function_t _x_x1638 = kk_function_dup(action_0, _ctx); /*(3031) -> 3032 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1638, (_x_x1638, x, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1639 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_foreach_10016_fun1640(action_0, xx_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x1639); return kk_Unit;
    }
    { // tailcall
      xs = xx_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(action_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_map_while_10017_10695(kk_std_core_types__cctx _acc, kk_function_t action, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10569, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_x10569, _ctx)) {
    kk_box_t y = _y_x10569._cons.Just.value;
    kk_std_core_types__list _trmc_x10397 = kk_datatype_null(); /*list<3109>*/;
    kk_std_core_types__list _trmc_x10398 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10397, _ctx); /*list<3109>*/;
    kk_field_addr_t _b_x547_552 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10398, _ctx)->tail, _ctx); /*@field-addr<list<3109>>*/;
    kk_std_core_types__cctx _x_x1642 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10398, _ctx)),_b_x547_552,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_map_while_10017(xx, action, _x_x1642, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(action, _ctx);
    kk_box_t _x_x1643 = kk_cctx_apply(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1643, KK_OWNED, _ctx);
  }
}
 
// Invoke `action` on each element of a list while `action` returns `Just`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_map_while_10017_fun1648__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_map_while_10017_fun1648(kk_function_t _fself, kk_box_t _b_x561, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_map_while_10017_fun1648(kk_std_core_types__cctx _acc_0, kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_while_10017_fun1648__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_map_while_10017_fun1648__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_map_while_10017_fun1648, kk_context());
  _self->_acc_0 = _acc_0;
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_map_while_10017_fun1648(kk_function_t _fself, kk_box_t _b_x561, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_while_10017_fun1648__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_map_while_10017_fun1648__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<3109>> */
  kk_function_t action_0 = _self->action_0; /* (3108) -> 3110 maybe<3109> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3108> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10569_0_581 = kk_std_core_types__maybe_unbox(_b_x561, KK_OWNED, _ctx); /*maybe<3109>*/;
  kk_std_core_types__list _x_x1649 = kk_std_core_list__mlift_trmc_unroll_map_while_10017_10695(_acc_0, action_0, xx_0, _y_x10569_0_581, _ctx); /*list<3109>*/
  return kk_std_core_types__list_box(_x_x1649, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_map_while_10017(kk_std_core_types__list xs, kk_function_t action_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action_0, _ctx);
    kk_box_t _x_x1644 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1644, KK_OWNED, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1645 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1645->head;
    kk_std_core_types__list xx_0 = _con_x1645->tail;
    kk_reuse_t _ru_x1341 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1341 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10822;
    kk_function_t _x_x1646 = kk_function_dup(action_0, _ctx); /*(3108) -> 3110 maybe<3109>*/
    x_0_10822 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1646, (_x_x1646, x, _ctx), _ctx); /*maybe<3109>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1341,kk_context());
      kk_std_core_types__maybe_drop(x_0_10822, _ctx);
      kk_box_t _x_x1647 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_map_while_10017_fun1648(_acc_0, action_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1647, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Just(x_0_10822, _ctx)) {
      kk_box_t y_0 = x_0_10822._cons.Just.value;
      kk_std_core_types__list _trmc_x10397_0 = kk_datatype_null(); /*list<3109>*/;
      kk_std_core_types__list _trmc_x10398_0 = kk_std_core_types__new_Cons(_ru_x1341, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10397_0, _ctx); /*list<3109>*/;
      kk_field_addr_t _b_x567_575 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10398_0, _ctx)->tail, _ctx); /*@field-addr<list<3109>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1650 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10398_0, _ctx)),_b_x567_575,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1650;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1341,kk_context());
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(action_0, _ctx);
      kk_box_t _x_x1651 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1651, KK_OWNED, _ctx);
    }
  }
}
 
// Invoke `action` on each element of a list while `action` returns `Just`

kk_std_core_types__list kk_std_core_list__unroll_map_while_10017(kk_std_core_types__list xs_0, kk_function_t action_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1652 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_map_while_10017(xs_0, action_1, _x_x1652, _ctx);
}
 
// monadic lift

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10349_10696(kk_std_core_types__list _uniq_xx_10315, kk_function_t action, kk_ref_t i, kk_unit_t _uniq_x___10316, kk_context_t* _ctx) { /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, ()) -> <local<h>|e> () */ 
  kk_std_core_list__lift_foreach_indexed_10349(action, i, _uniq_xx_10315, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10697_fun1655__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10315_0;
  kk_function_t action_0;
  kk_ref_t i_0;
};
static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10349_10697_fun1655(kk_function_t _fself, kk_box_t _b_x587, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_lift_foreach_indexed_10349_10697_fun1655(kk_std_core_types__list _uniq_xx_10315_0, kk_function_t action_0, kk_ref_t i_0, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10697_fun1655__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10697_fun1655__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_lift_foreach_indexed_10349_10697_fun1655, kk_context());
  _self->_uniq_xx_10315_0 = _uniq_xx_10315_0;
  _self->action_0 = action_0;
  _self->i_0 = i_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10349_10697_fun1655(kk_function_t _fself, kk_box_t _b_x587, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10697_fun1655__t* _self = kk_function_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10697_fun1655__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10315_0 = _self->_uniq_xx_10315_0; /* list<3247> */
  kk_function_t action_0 = _self->action_0; /* (int, 3247) -> 3248 () */
  kk_ref_t i_0 = _self->i_0; /* local-var<3237,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10315_0, _ctx);kk_function_dup(action_0, _ctx);kk_ref_dup(i_0, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10316_0_589 = kk_Unit;
  kk_unit_unbox(_b_x587);
  kk_unit_t _x_x1656 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10349_10696(_uniq_xx_10315_0, action_0, i_0, _uniq_x___10316_0_589, _ctx);
  return kk_unit_box(_x_x1656);
}

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10349_10697(kk_std_core_types__list _uniq_xx_10315_0, kk_function_t action_0, kk_ref_t i_0, kk_integer_t _y_x10579, kk_context_t* _ctx) { /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, int) -> <local<h>|e> () */ 
  kk_integer_t _b_x583_585 = kk_integer_add_small_const(_y_x10579, 1, _ctx); /*int*/;
  kk_unit_t x_10827 = kk_Unit;
  kk_ref_set_borrow(i_0,(kk_integer_box(_b_x583_585, _ctx)),kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1654 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_lift_foreach_indexed_10349_10697_fun1655(_uniq_xx_10315_0, action_0, i_0, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x1654); return kk_Unit;
  }
  {
    kk_std_core_list__mlift_lift_foreach_indexed_10349_10696(_uniq_xx_10315_0, action_0, i_0, x_10827, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10698_fun1660__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10315_1;
  kk_function_t action_1;
  kk_ref_t i_1;
};
static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10349_10698_fun1660(kk_function_t _fself, kk_box_t _b_x595, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_lift_foreach_indexed_10349_10698_fun1660(kk_std_core_types__list _uniq_xx_10315_1, kk_function_t action_1, kk_ref_t i_1, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10698_fun1660__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10698_fun1660__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_lift_foreach_indexed_10349_10698_fun1660, kk_context());
  _self->_uniq_xx_10315_1 = _uniq_xx_10315_1;
  _self->action_1 = action_1;
  _self->i_1 = i_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10349_10698_fun1660(kk_function_t _fself, kk_box_t _b_x595, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10698_fun1660__t* _self = kk_function_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10698_fun1660__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10315_1 = _self->_uniq_xx_10315_1; /* list<3247> */
  kk_function_t action_1 = _self->action_1; /* (int, 3247) -> 3248 () */
  kk_ref_t i_1 = _self->i_1; /* local-var<3237,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10315_1, _ctx);kk_function_dup(action_1, _ctx);kk_ref_dup(i_1, _ctx);}, {}, _ctx)
  kk_integer_t _y_x10579_0_597 = kk_integer_unbox(_b_x595, _ctx); /*int*/;
  kk_unit_t _x_x1661 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10349_10697(_uniq_xx_10315_1, action_1, i_1, _y_x10579_0_597, _ctx);
  return kk_unit_box(_x_x1661);
}

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10349_10698(kk_std_core_types__list _uniq_xx_10315_1, kk_function_t action_1, kk_ref_t i_1, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, wild_ : ()) -> <local<h>|e> () */ 
  kk_integer_t x_0_10829;
  kk_box_t _x_x1657;
  kk_ref_t _x_x1658 = kk_ref_dup(i_1, _ctx); /*local-var<3237,int>*/
  _x_x1657 = kk_ref_get(_x_x1658,kk_context()); /*298*/
  x_0_10829 = kk_integer_unbox(_x_x1657, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_0_10829, _ctx);
    kk_box_t _x_x1659 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_lift_foreach_indexed_10349_10698_fun1660(_uniq_xx_10315_1, action_1, i_1, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x1659); return kk_Unit;
  }
  {
    kk_std_core_list__mlift_lift_foreach_indexed_10349_10697(_uniq_xx_10315_1, action_1, i_1, x_0_10829, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10699_fun1664__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10315_2;
  kk_function_t action_2;
  kk_ref_t i_2;
};
static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10349_10699_fun1664(kk_function_t _fself, kk_box_t _b_x599, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_lift_foreach_indexed_10349_10699_fun1664(kk_std_core_types__list _uniq_xx_10315_2, kk_function_t action_2, kk_ref_t i_2, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10699_fun1664__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10699_fun1664__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_lift_foreach_indexed_10349_10699_fun1664, kk_context());
  _self->_uniq_xx_10315_2 = _uniq_xx_10315_2;
  _self->action_2 = action_2;
  _self->i_2 = i_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10349_10699_fun1664(kk_function_t _fself, kk_box_t _b_x599, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10699_fun1664__t* _self = kk_function_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10349_10699_fun1664__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10315_2 = _self->_uniq_xx_10315_2; /* list<3247> */
  kk_function_t action_2 = _self->action_2; /* (int, 3247) -> 3248 () */
  kk_ref_t i_2 = _self->i_2; /* local-var<3237,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10315_2, _ctx);kk_function_dup(action_2, _ctx);kk_ref_dup(i_2, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_601 = kk_Unit;
  kk_unit_unbox(_b_x599);
  kk_unit_t _x_x1665 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10349_10698(_uniq_xx_10315_2, action_2, i_2, wild___0_601, _ctx);
  return kk_unit_box(_x_x1665);
}

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10349_10699(kk_box_t _uniq_x_10314, kk_std_core_types__list _uniq_xx_10315_2, kk_function_t action_2, kk_ref_t i_2, kk_integer_t j, kk_context_t* _ctx) { /* forall<h,a,e> (a, list<a>, action : (int, a) -> e (), i : local-var<h,int>, j : int) -> <local<h>|e> () */ 
  kk_unit_t x_1_10831 = kk_Unit;
  kk_function_t _x_x1662 = kk_function_dup(action_2, _ctx); /*(int, 3247) -> 3248 ()*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x1662, (_x_x1662, j, _uniq_x_10314, _ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1663 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_lift_foreach_indexed_10349_10699_fun1664(_uniq_xx_10315_2, action_2, i_2, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x1663); return kk_Unit;
  }
  {
    kk_std_core_list__mlift_lift_foreach_indexed_10349_10698(_uniq_xx_10315_2, action_2, i_2, x_1_10831, _ctx); return kk_Unit;
  }
}
 
// lifted local: foreach-indexed, @spec-x10318
// specialized: std/core/list/@unroll-foreach@10016, on parameters @uniq-action@10312, using:
// @uniq-action@10312 = fn<<(local :: H -> X)<(h :: H)>|(e :: E)>>(x: 3247){
//   val j : int;
//   val _ : ();
//   std/core/types/local-set<int,(e :: E),(h :: H)>(i, (std/core/types/@open<(total :: E),<(local :: H -> X)<(h :: H)>|(e :: E)>,(x : int, y : int) -> int,(x : int, y : int) -> <(local :: H -> X)<(h :: H)>|(e :: E)> int>((fn(x@0: int, y: int){
//       (std/core/int/int-add(x@0, y));
//     }))((std/core/types/local-get<int,(h :: H),(e :: E)>(i, (std/core/types/@Hnodiv<(h :: H),int,(e :: E)>))), 1)));
// }


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10349_fun1670__t {
  struct kk_function_s _base;
  kk_box_t _uniq_x_10314_0;
  kk_std_core_types__list _uniq_xx_10315_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10349_fun1670(kk_function_t _fself, kk_box_t _b_x607, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10349_fun1670(kk_box_t _uniq_x_10314_0, kk_std_core_types__list _uniq_xx_10315_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10349_fun1670__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10349_fun1670__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10349_fun1670, kk_context());
  _self->_uniq_x_10314_0 = _uniq_x_10314_0;
  _self->_uniq_xx_10315_3 = _uniq_xx_10315_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10349_fun1670(kk_function_t _fself, kk_box_t _b_x607, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10349_fun1670__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10349_fun1670__t*, _fself, _ctx);
  kk_box_t _uniq_x_10314_0 = _self->_uniq_x_10314_0; /* 3247 */
  kk_std_core_types__list _uniq_xx_10315_3 = _self->_uniq_xx_10315_3; /* list<3247> */
  kk_function_t action_4 = _self->action_4; /* (int, 3247) -> 3248 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<3237,int> */
  kk_drop_match(_self, {kk_box_dup(_uniq_x_10314_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10315_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_integer_t j_0_626 = kk_integer_unbox(_b_x607, _ctx); /*int*/;
  kk_unit_t _x_x1671 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10349_10699(_uniq_x_10314_0, _uniq_xx_10315_3, action_4, i_3, j_0_626, _ctx);
  return kk_unit_box(_x_x1671);
}


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10349_fun1674__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10315_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10349_fun1674(kk_function_t _fself, kk_box_t _b_x609, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10349_fun1674(kk_std_core_types__list _uniq_xx_10315_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10349_fun1674__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10349_fun1674__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10349_fun1674, kk_context());
  _self->_uniq_xx_10315_3 = _uniq_xx_10315_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10349_fun1674(kk_function_t _fself, kk_box_t _b_x609, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10349_fun1674__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10349_fun1674__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10315_3 = _self->_uniq_xx_10315_3; /* list<3247> */
  kk_function_t action_4 = _self->action_4; /* (int, 3247) -> 3248 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<3237,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10315_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_unit_t wild___1_627 = kk_Unit;
  kk_unit_unbox(_b_x609);
  kk_unit_t _x_x1675 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10349_10698(_uniq_xx_10315_3, action_4, i_3, wild___1_627, _ctx);
  return kk_unit_box(_x_x1675);
}


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10349_fun1679__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10315_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10349_fun1679(kk_function_t _fself, kk_box_t _b_x615, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10349_fun1679(kk_std_core_types__list _uniq_xx_10315_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10349_fun1679__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10349_fun1679__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10349_fun1679, kk_context());
  _self->_uniq_xx_10315_3 = _uniq_xx_10315_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10349_fun1679(kk_function_t _fself, kk_box_t _b_x615, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10349_fun1679__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10349_fun1679__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10315_3 = _self->_uniq_xx_10315_3; /* list<3247> */
  kk_function_t action_4 = _self->action_4; /* (int, 3247) -> 3248 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<3237,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10315_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_integer_t _y_x10579_1_628 = kk_integer_unbox(_b_x615, _ctx); /*int*/;
  kk_unit_t _x_x1680 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10349_10697(_uniq_xx_10315_3, action_4, i_3, _y_x10579_1_628, _ctx);
  return kk_unit_box(_x_x1680);
}


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10349_fun1682__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10315_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10349_fun1682(kk_function_t _fself, kk_box_t _b_x621, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10349_fun1682(kk_std_core_types__list _uniq_xx_10315_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10349_fun1682__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10349_fun1682__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10349_fun1682, kk_context());
  _self->_uniq_xx_10315_3 = _uniq_xx_10315_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10349_fun1682(kk_function_t _fself, kk_box_t _b_x621, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10349_fun1682__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10349_fun1682__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10315_3 = _self->_uniq_xx_10315_3; /* list<3247> */
  kk_function_t action_4 = _self->action_4; /* (int, 3247) -> 3248 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<3237,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10315_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10316_1_629 = kk_Unit;
  kk_unit_unbox(_b_x621);
  kk_unit_t _x_x1683 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10349_10696(_uniq_xx_10315_3, action_4, i_3, _uniq_x___10316_1_629, _ctx);
  return kk_unit_box(_x_x1683);
}

kk_unit_t kk_std_core_list__lift_foreach_indexed_10349(kk_function_t action_4, kk_ref_t i_3, kk_std_core_types__list _uniq_xs_10311, kk_context_t* _ctx) { /* forall<h,a,e> (action : (int, a) -> e (), i : local-var<h,int>, list<a>) -> <local<h>|e> () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10311, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1666 = kk_std_core_types__as_Cons(_uniq_xs_10311, _ctx);
    kk_box_t _uniq_x_10314_0 = _con_x1666->head;
    kk_std_core_types__list _uniq_xx_10315_3 = _con_x1666->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10311, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10311, _ctx);
    }
    else {
      kk_box_dup(_uniq_x_10314_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10315_3, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10311, _ctx);
    }
    kk_integer_t x_2_10834;
    kk_box_t _x_x1667;
    kk_ref_t _x_x1668 = kk_ref_dup(i_3, _ctx); /*local-var<3237,int>*/
    _x_x1667 = kk_ref_get(_x_x1668,kk_context()); /*298*/
    x_2_10834 = kk_integer_unbox(_x_x1667, _ctx); /*int*/
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_2_10834, _ctx);
      kk_box_t _x_x1669 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10349_fun1670(_uniq_x_10314_0, _uniq_xx_10315_3, action_4, i_3, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x1669); return kk_Unit;
    }
    {
      kk_unit_t x_3_10837 = kk_Unit;
      kk_function_t _x_x1672 = kk_function_dup(action_4, _ctx); /*(int, 3247) -> 3248 ()*/
      kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x1672, (_x_x1672, x_2_10834, _uniq_x_10314_0, _ctx), _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1673 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10349_fun1674(_uniq_xx_10315_3, action_4, i_3, _ctx), _ctx); /*2419*/
        kk_unit_unbox(_x_x1673); return kk_Unit;
      }
      {
        kk_integer_t x_4_10841;
        kk_box_t _x_x1676;
        kk_ref_t _x_x1677 = kk_ref_dup(i_3, _ctx); /*local-var<3237,int>*/
        _x_x1676 = kk_ref_get(_x_x1677,kk_context()); /*298*/
        x_4_10841 = kk_integer_unbox(_x_x1676, _ctx); /*int*/
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_4_10841, _ctx);
          kk_box_t _x_x1678 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10349_fun1679(_uniq_xx_10315_3, action_4, i_3, _ctx), _ctx); /*2419*/
          kk_unit_unbox(_x_x1678); return kk_Unit;
        }
        {
          kk_integer_t _b_x617_619 = kk_integer_add_small_const(x_4_10841, 1, _ctx); /*int*/;
          kk_unit_t x_5_10844 = kk_Unit;
          kk_ref_set_borrow(i_3,(kk_integer_box(_b_x617_619, _ctx)),kk_context());
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1681 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10349_fun1682(_uniq_xx_10315_3, action_4, i_3, _ctx), _ctx); /*2419*/
            kk_unit_unbox(_x_x1681); return kk_Unit;
          }
          { // tailcall
            _uniq_xs_10311 = _uniq_xx_10315_3;
            goto kk__tailcall;
          }
        }
      }
    }
  }
  {
    kk_ref_drop(i_3, _ctx);
    kk_function_drop(action_4, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// Invoke `action` for each element of a list, passing also the position of the element.

kk_unit_t kk_std_core_list_foreach_indexed(kk_std_core_types__list xs, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (int, a) -> e ()) -> e () */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*local-var<3237,int>*/;
  kk_unit_t res = kk_Unit;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action, _ctx);
  }
  else {
    kk_ref_t _x_x1684 = kk_ref_dup(loc, _ctx); /*local-var<3237,int>*/
    kk_std_core_list__lift_foreach_indexed_10349(action, _x_x1684, xs, _ctx);
  }
  kk_box_t _x_x1685 = kk_std_core_hnd_prompt_local_var(loc, kk_unit_box(res), _ctx); /*4162*/
  kk_unit_unbox(_x_x1685); return kk_Unit;
}
 
// lifted local: intersperse, before

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_intersperse_5734_10018(kk_box_t sep, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (sep : a, ys : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1686 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1686->head;
    kk_std_core_types__list yy = _con_x1686->tail;
    kk_reuse_t _ru_x1343 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1343 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10399;
    kk_std_core_types__list _x_x1687 = kk_datatype_null(); /*list<3324>*/
    _trmc_x10399 = kk_std_core_types__new_Cons(_ru_x1343, 0, y, _x_x1687, _ctx); /*list<3324>*/
    kk_field_addr_t _b_x641_646 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10399, _ctx)->tail, _ctx); /*@field-addr<list<3324>>*/;
    { // tailcall
      kk_box_t _x_x1688 = kk_box_dup(sep, _ctx); /*3324*/
      kk_std_core_types__cctx _x_x1689;
      kk_box_t _x_x1690;
      kk_std_core_types__list _x_x1691 = kk_std_core_types__new_Cons(kk_reuse_null, 0, sep, _trmc_x10399, _ctx); /*list<79>*/
      _x_x1690 = kk_std_core_types__list_box(_x_x1691, _ctx); /*0*/
      _x_x1689 = kk_cctx_extend_linear(_acc,_x_x1690,_b_x641_646,kk_context()); /*ctx<0>*/
      sep = _x_x1688;
      ys = yy;
      _acc = _x_x1689;
      goto kk__tailcall;
    }
  }
  {
    kk_box_drop(sep, _ctx);
    kk_box_t _x_x1692 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1692, KK_OWNED, _ctx);
  }
}
 
// lifted local: intersperse, before

kk_std_core_types__list kk_std_core_list__unroll_lift_intersperse_5734_10018(kk_box_t sep_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a> (sep : a, ys : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1693 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_intersperse_5734_10018(sep_0, ys_0, _x_x1693, _ctx);
}
 
// Insert a separator `sep`  between all elements of a list `xs` .

kk_std_core_types__list kk_std_core_list_intersperse(kk_std_core_types__list xs, kk_box_t sep, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, sep : a) -> list<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1695 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1695->head;
    kk_std_core_types__list xx = _con_x1695->tail;
    kk_reuse_t _ru_x1344 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1344 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__list _x_x1696;
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      kk_box_drop(sep, _ctx);
      _x_x1696 = kk_std_core_types__new_Nil(_ctx); /*forall<a> list<a>*/
    }
    else {
      kk_std_core_types__cctx _x_x1697 = kk_cctx_empty(kk_context()); /*ctx<0>*/
      _x_x1696 = kk_std_core_list__trmc_unroll_lift_intersperse_5734_10018(sep, xx, _x_x1697, _ctx); /*forall<a> list<a>*/
    }
    return kk_std_core_types__new_Cons(_ru_x1344, 0, x, _x_x1696, _ctx);
  }
  {
    kk_box_drop(sep, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// Concatenate all strings in a list

kk_string_t kk_std_core_list_joinsep(kk_std_core_types__list xs, kk_string_t sep, kk_context_t* _ctx) { /* (xs : list<string>, sep : string) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_string_drop(sep, _ctx);
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1699 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x652 = _con_x1699->head;
    kk_std_core_types__list _pat_1 = _con_x1699->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x652);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_string_drop(sep, _ctx);
      return x;
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1700 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x653 = _con_x1700->head;
    kk_std_core_types__list _pat_3 = _con_x1700->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1701 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x654 = _con_x1701->head;
      kk_std_core_types__list _pat_4 = _con_x1701->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x1702 = kk_string_dup(sep, _ctx); /*string*/
        kk_string_t _x_x1703 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x1702,_x_x1703,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x653);
          kk_string_t y = kk_string_unbox(_box_x654);
          if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(xs, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(xs, _ctx);
          }
          kk_string_drop(sep, _ctx);
          return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
        }
      }
    }
  }
  {
    kk_vector_t _x_x1705 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<978>*/
    return kk_string_join_with(_x_x1705,sep,kk_context());
  }
}
 
// Concatenate all strings in a list

kk_string_t kk_std_core_list_concat_fs_join(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1707 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x655 = _con_x1707->head;
    kk_std_core_types__list _pat_1 = _con_x1707->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x655);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return x;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1708 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x656 = _con_x1708->head;
    kk_std_core_types__list _pat_3 = _con_x1708->tail;
    struct kk_std_core_types_Cons* _con_x1709 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x657 = _con_x1709->head;
    kk_std_core_types__list _pat_4 = _con_x1709->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x656);
      kk_string_t y = kk_string_unbox(_box_x657);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
    }
  }
  {
    kk_vector_t _x_x1710 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<978>*/
    return kk_string_join(_x_x1710,kk_context());
  }
}
 
// monadic lift

kk_string_t kk_std_core_list__mlift_show_10700(kk_std_core_types__list _c_x10588, kk_context_t* _ctx) { /* (list<string>) -> string */ 
  kk_string_t _x_x1711;
  kk_define_string_literal(, _s_x1712, 1, "[", _ctx)
  _x_x1711 = kk_string_dup(_s_x1712, _ctx); /*string*/
  kk_string_t _x_x1713;
  kk_string_t _x_x1714;
  if (kk_std_core_types__is_Nil(_c_x10588, _ctx)) {
    _x_x1714 = kk_string_empty(); /*string*/
    goto _match_x1715;
  }
  {
    struct kk_std_core_types_Cons* _con_x1717 = kk_std_core_types__as_Cons(_c_x10588, _ctx);
    kk_box_t _box_x658 = _con_x1717->head;
    kk_std_core_types__list _pat_1 = _con_x1717->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x658);
      if kk_likely(kk_datatype_ptr_is_unique(_c_x10588, _ctx)) {
        kk_datatype_ptr_free(_c_x10588, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(_c_x10588, _ctx);
      }
      _x_x1714 = x; /*string*/
      goto _match_x1715;
    }
  }
  if (kk_std_core_types__is_Cons(_c_x10588, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1718 = kk_std_core_types__as_Cons(_c_x10588, _ctx);
    kk_box_t _box_x659 = _con_x1718->head;
    kk_std_core_types__list _pat_3 = _con_x1718->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1719 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x660 = _con_x1719->head;
      kk_std_core_types__list _pat_4 = _con_x1719->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x1720;
        kk_define_string_literal(, _s_x1721, 1, ",", _ctx)
        _x_x1720 = kk_string_dup(_s_x1721, _ctx); /*string*/
        kk_string_t _x_x1722 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x1720,_x_x1722,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x659);
          kk_string_t y = kk_string_unbox(_box_x660);
          if kk_likely(kk_datatype_ptr_is_unique(_c_x10588, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(_c_x10588, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(_c_x10588, _ctx);
          }
          _x_x1714 = kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx); /*string*/
          goto _match_x1715;
        }
      }
    }
  }
  {
    kk_vector_t _x_x1724 = kk_std_core_vector_unvlist(_c_x10588, _ctx); /*vector<978>*/
    kk_string_t _x_x1725;
    kk_define_string_literal(, _s_x1726, 1, ",", _ctx)
    _x_x1725 = kk_string_dup(_s_x1726, _ctx); /*string*/
    _x_x1714 = kk_string_join_with(_x_x1724,_x_x1725,kk_context()); /*string*/
  }
  _match_x1715: ;
  kk_string_t _x_x1727;
  kk_define_string_literal(, _s_x1728, 1, "]", _ctx)
  _x_x1727 = kk_string_dup(_s_x1728, _ctx); /*string*/
  _x_x1713 = kk_std_core_types__lp__plus__plus__rp_(_x_x1714, _x_x1727, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1711, _x_x1713, _ctx);
}
 
// Show a list


// lift anonymous function
struct kk_std_core_list_show_fun1729__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_show;
};
static kk_box_t kk_std_core_list_show_fun1729(kk_function_t _fself, kk_box_t _b_x664, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_show_fun1729(kk_function_t _implicit_fs_show, kk_context_t* _ctx) {
  struct kk_std_core_list_show_fun1729__t* _self = kk_function_alloc_as(struct kk_std_core_list_show_fun1729__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_show_fun1729, kk_context());
  _self->_implicit_fs_show = _implicit_fs_show;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_show_fun1729(kk_function_t _fself, kk_box_t _b_x664, kk_context_t* _ctx) {
  struct kk_std_core_list_show_fun1729__t* _self = kk_function_as(struct kk_std_core_list_show_fun1729__t*, _fself, _ctx);
  kk_function_t _implicit_fs_show = _self->_implicit_fs_show; /* (3527) -> 3528 string */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_show, _ctx);}, {}, _ctx)
  kk_string_t _x_x1730 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_show, (_implicit_fs_show, _b_x664, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x1730);
}


// lift anonymous function
struct kk_std_core_list_show_fun1732__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_show_fun1732(kk_function_t _fself, kk_box_t _b_x669, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_show_fun1732(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_show_fun1732, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_show_fun1732(kk_function_t _fself, kk_box_t _b_x669, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1733;
  kk_std_core_types__list _x_x1734 = kk_std_core_types__list_unbox(_b_x669, KK_OWNED, _ctx); /*list<string>*/
  _x_x1733 = kk_std_core_list__mlift_show_10700(_x_x1734, _ctx); /*string*/
  return kk_string_box(_x_x1733);
}

kk_string_t kk_std_core_list_show(kk_std_core_types__list xs, kk_function_t _implicit_fs_show, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, ?show : (a) -> e string) -> e string */ 
  kk_std_core_types__list x_10853;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(_implicit_fs_show, _ctx);
    x_10853 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  else {
    kk_std_core_types__cctx _b_x663_667 = kk_cctx_empty(kk_context()); /*ctx<list<string>>*/;
    kk_function_t _brw_x1241 = kk_std_core_list_new_show_fun1729(_implicit_fs_show, _ctx); /*(2217) -> 2219 2218*/;
    kk_std_core_types__list _brw_x1242 = kk_std_core_list__trmc_unroll_map_10010(xs, _brw_x1241, _b_x663_667, _ctx); /*list<2218>*/;
    kk_function_drop(_brw_x1241, _ctx);
    x_10853 = _brw_x1242; /*list<string>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10853, _ctx);
    kk_box_t _x_x1731 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_show_fun1732(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1731);
  }
  {
    kk_string_t _x_x1735;
    kk_define_string_literal(, _s_x1736, 1, "[", _ctx)
    _x_x1735 = kk_string_dup(_s_x1736, _ctx); /*string*/
    kk_string_t _x_x1737;
    kk_string_t _x_x1738;
    if (kk_std_core_types__is_Nil(x_10853, _ctx)) {
      _x_x1738 = kk_string_empty(); /*string*/
      goto _match_x1739;
    }
    {
      struct kk_std_core_types_Cons* _con_x1741 = kk_std_core_types__as_Cons(x_10853, _ctx);
      kk_box_t _box_x670 = _con_x1741->head;
      kk_std_core_types__list _pat_1_0 = _con_x1741->tail;
      if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
        kk_string_t x_0 = kk_string_unbox(_box_x670);
        if kk_likely(kk_datatype_ptr_is_unique(x_10853, _ctx)) {
          kk_datatype_ptr_free(x_10853, _ctx);
        }
        else {
          kk_string_dup(x_0, _ctx);
          kk_datatype_ptr_decref(x_10853, _ctx);
        }
        _x_x1738 = x_0; /*string*/
        goto _match_x1739;
      }
    }
    if (kk_std_core_types__is_Cons(x_10853, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1742 = kk_std_core_types__as_Cons(x_10853, _ctx);
      kk_box_t _box_x671 = _con_x1742->head;
      kk_std_core_types__list _pat_3 = _con_x1742->tail;
      if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
        struct kk_std_core_types_Cons* _con_x1743 = kk_std_core_types__as_Cons(_pat_3, _ctx);
        kk_box_t _box_x672 = _con_x1743->head;
        kk_std_core_types__list _pat_4 = _con_x1743->tail;
        if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
          kk_string_t _x_x1744;
          kk_define_string_literal(, _s_x1745, 1, ",", _ctx)
          _x_x1744 = kk_string_dup(_s_x1745, _ctx); /*string*/
          kk_string_t _x_x1746 = kk_string_empty(); /*string*/
          if (kk_string_is_eq(_x_x1744,_x_x1746,kk_context())) {
            kk_string_t x_0_0 = kk_string_unbox(_box_x671);
            kk_string_t y = kk_string_unbox(_box_x672);
            if kk_likely(kk_datatype_ptr_is_unique(x_10853, _ctx)) {
              if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
                kk_datatype_ptr_free(_pat_3, _ctx);
              }
              else {
                kk_string_dup(y, _ctx);
                kk_datatype_ptr_decref(_pat_3, _ctx);
              }
              kk_datatype_ptr_free(x_10853, _ctx);
            }
            else {
              kk_string_dup(x_0_0, _ctx);
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(x_10853, _ctx);
            }
            _x_x1738 = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
            goto _match_x1739;
          }
        }
      }
    }
    {
      kk_vector_t _x_x1748 = kk_std_core_vector_unvlist(x_10853, _ctx); /*vector<978>*/
      kk_string_t _x_x1749;
      kk_define_string_literal(, _s_x1750, 1, ",", _ctx)
      _x_x1749 = kk_string_dup(_s_x1750, _ctx); /*string*/
      _x_x1738 = kk_string_join_with(_x_x1748,_x_x1749,kk_context()); /*string*/
    }
    _match_x1739: ;
    kk_string_t _x_x1751;
    kk_define_string_literal(, _s_x1752, 1, "]", _ctx)
    _x_x1751 = kk_string_dup(_s_x1752, _ctx); /*string*/
    _x_x1737 = kk_std_core_types__lp__plus__plus__rp_(_x_x1738, _x_x1751, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x1735, _x_x1737, _ctx);
  }
}
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list__trmc_unroll_zip_10019(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, ys : list<b>, ctx<list<(a, b)>>) -> list<(a, b)> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1753 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1753->head;
    kk_std_core_types__list xx = _con_x1753->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1754 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1754->head;
      kk_std_core_types__list yy = _con_x1754->tail;
      kk_reuse_t _ru_x1358 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1358 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_std_core_types__list _trmc_x10401 = kk_datatype_null(); /*list<(3644, 3645)>*/;
      kk_std_core_types__list _trmc_x10402;
      kk_box_t _x_x1755;
      kk_std_core_types__tuple2 _x_x1756 = kk_std_core_types__new_Tuple2(x, y, _ctx); /*(134, 135)*/
      _x_x1755 = kk_std_core_types__tuple2_box(_x_x1756, _ctx); /*79*/
      _trmc_x10402 = kk_std_core_types__new_Cons(_ru_x1358, 0, _x_x1755, _trmc_x10401, _ctx); /*list<(3644, 3645)>*/
      kk_field_addr_t _b_x683_690 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10402, _ctx)->tail, _ctx); /*@field-addr<list<(3644, 3645)>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1757 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10402, _ctx)),_b_x683_690,kk_context()); /*ctx<0>*/
        xs = xx;
        ys = yy;
        _acc = _x_x1757;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx, _ctx);
      kk_box_drop(x, _ctx);
      kk_box_t _x_x1758 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1758, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_box_t _x_x1759 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1759, KK_OWNED, _ctx);
  }
}
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list__unroll_zip_10019(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, ys : list<b>) -> list<(a, b)> */ 
  kk_std_core_types__cctx _x_x1760 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_zip_10019(xs_0, ys_0, _x_x1760, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_zipwith_10020_10701(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_box_t _trmc_x10403, kk_context_t* _ctx) { /* forall<a,b,c,e> (ctx<list<c>>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */ 
  kk_std_core_types__list _trmc_x10404 = kk_datatype_null(); /*list<3727>*/;
  kk_std_core_types__list _trmc_x10405 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10403, _trmc_x10404, _ctx); /*list<3727>*/;
  kk_field_addr_t _b_x703_706 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10405, _ctx)->tail, _ctx); /*@field-addr<list<3727>>*/;
  kk_std_core_types__cctx _own_x1238 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10405, _ctx)),_b_x703_706,kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1239 = kk_std_core_list__trmc_unroll_zipwith_10020(xx, yy, f, _own_x1238, _ctx); /*list<3727>*/;
  kk_function_drop(f, _ctx);
  return _brw_x1239;
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.


// lift anonymous function
struct kk_std_core_list__trmc_unroll_zipwith_10020_fun1767__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_zipwith_10020_fun1767(kk_function_t _fself, kk_box_t _b_x711, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_zipwith_10020_fun1767(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_zipwith_10020_fun1767__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_zipwith_10020_fun1767__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_zipwith_10020_fun1767, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_zipwith_10020_fun1767(kk_function_t _fself, kk_box_t _b_x711, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_zipwith_10020_fun1767__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_zipwith_10020_fun1767__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<3727>> */
  kk_function_t f_0 = _self->f_0; /* (3725, 3726) -> 3728 3727 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3725> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<3726> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10403_0_733 = _b_x711; /*3727*/;
  kk_std_core_types__list _x_x1768 = kk_std_core_list__mlift_trmc_unroll_zipwith_10020_10701(_acc_0, f_0, xx_0, yy_0, _trmc_x10403_0_733, _ctx); /*list<3727>*/
  return kk_std_core_types__list_box(_x_x1768, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_zipwith_10020(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, ctx<list<c>>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1762 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1762->head;
    kk_std_core_types__list xx_0 = _con_x1762->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1763 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1763->head;
      kk_std_core_types__list yy_0 = _con_x1763->tail;
      kk_reuse_t _ru_x1360 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1360 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_box_t x_0_10860;
      kk_function_t _x_x1764 = kk_function_dup(f_0, _ctx); /*(3725, 3726) -> 3728 3727*/
      x_0_10860 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1764, (_x_x1764, x, y, _ctx), _ctx); /*3727*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x1360,kk_context());
        kk_box_drop(x_0_10860, _ctx);
        kk_box_t _x_x1765;
        kk_function_t _x_x1766;
        kk_function_dup(f_0, _ctx);
        _x_x1766 = kk_std_core_list__new_trmc_unroll_zipwith_10020_fun1767(_acc_0, f_0, xx_0, yy_0, _ctx); /*(2418) -> 2420 2419*/
        _x_x1765 = kk_std_core_hnd_yield_extend(_x_x1766, _ctx); /*2419*/
        return kk_std_core_types__list_unbox(_x_x1765, KK_OWNED, _ctx);
      }
      {
        kk_std_core_types__list _trmc_x10404_0 = kk_datatype_null(); /*list<3727>*/;
        kk_std_core_types__list _trmc_x10405_0 = kk_std_core_types__new_Cons(_ru_x1360, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10860, _trmc_x10404_0, _ctx); /*list<3727>*/;
        kk_field_addr_t _b_x717_725 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10405_0, _ctx)->tail, _ctx); /*@field-addr<list<3727>>*/;
        kk_std_core_types__cctx _own_x1237 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10405_0, _ctx)),_b_x717_725,kk_context()); /*ctx<0>*/;
        { // tailcall
          xs = xx_0;
          ys = yy_0;
          _acc_0 = _own_x1237;
          goto kk__tailcall;
        }
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_box_t _x_x1769 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1769, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_box_t _x_x1770 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1770, KK_OWNED, _ctx);
  }
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list__unroll_zipwith_10020(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */ 
  kk_std_core_types__cctx _own_x1235 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  return kk_std_core_list__trmc_unroll_zipwith_10020(xs_0, ys_0, f_1, _own_x1235, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_zipwith_iter_10021_10702(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_box_t _trmc_x10406, kk_context_t* _ctx) { /* forall<a,b,c,d,e> (ctx<list<a>>, f : (int, b, c) -> e d, i : int, xx : list<b>, yy : list<c>, d) -> e list<d> */ 
  kk_std_core_types__list _trmc_x10407 = kk_datatype_null(); /*list<3813>*/;
  kk_std_core_types__list _trmc_x10408 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10406, _trmc_x10407, _ctx); /*list<3813>*/;
  kk_field_addr_t _b_x739_742 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10408, _ctx)->tail, _ctx); /*@field-addr<list<3813>>*/;
  kk_integer_t _own_x1232 = kk_integer_add_small_const(i, 1, _ctx); /*int*/;
  kk_std_core_types__cctx _own_x1231 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10408, _ctx)),_b_x739_742,kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1233 = kk_std_core_list__trmc_unroll_zipwith_iter_10021(_own_x1232, xx, yy, f, _own_x1231, _ctx); /*list<3809>*/;
  kk_function_drop(f, _ctx);
  return _brw_x1233;
}


// lift anonymous function
struct kk_std_core_list__trmc_unroll_zipwith_iter_10021_fun1777__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_zipwith_iter_10021_fun1777(kk_function_t _fself, kk_box_t _b_x747, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_zipwith_iter_10021_fun1777(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_zipwith_iter_10021_fun1777__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_zipwith_iter_10021_fun1777__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_zipwith_iter_10021_fun1777, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0 = i_0;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_zipwith_iter_10021_fun1777(kk_function_t _fself, kk_box_t _b_x747, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_zipwith_iter_10021_fun1777__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_zipwith_iter_10021_fun1777__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<3809>> */
  kk_function_t f_0 = _self->f_0; /* (int, 3811, 3812) -> 3814 3813 */
  kk_integer_t i_0 = _self->i_0; /* int */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3811> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<3812> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10406_0_769 = _b_x747; /*3813*/;
  kk_std_core_types__list _x_x1778 = kk_std_core_list__mlift_trmc_unroll_zipwith_iter_10021_10702(_acc_0, f_0, i_0, xx_0, yy_0, _trmc_x10406_0_769, _ctx); /*list<3813>*/
  return kk_std_core_types__list_box(_x_x1778, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_zipwith_iter_10021(kk_integer_t i_0, kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,c,e> (i : int, xs : list<a>, ys : list<b>, f : (int, a, b) -> e c, ctx<list<c>>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1771 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1771->head;
    kk_std_core_types__list xx_0 = _con_x1771->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1772 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1772->head;
      kk_std_core_types__list yy_0 = _con_x1772->tail;
      kk_reuse_t _ru_x1362 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1362 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_box_t x_0_10866;
      kk_function_t _x_x1774 = kk_function_dup(f_0, _ctx); /*(int, 3811, 3812) -> 3814 3813*/
      kk_integer_t _x_x1773 = kk_integer_dup(i_0, _ctx); /*int*/
      x_0_10866 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1774, (_x_x1774, _x_x1773, x, y, _ctx), _ctx); /*3813*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x1362,kk_context());
        kk_box_drop(x_0_10866, _ctx);
        kk_box_t _x_x1775;
        kk_function_t _x_x1776;
        kk_function_dup(f_0, _ctx);
        _x_x1776 = kk_std_core_list__new_trmc_unroll_zipwith_iter_10021_fun1777(_acc_0, f_0, i_0, xx_0, yy_0, _ctx); /*(2418) -> 2420 2419*/
        _x_x1775 = kk_std_core_hnd_yield_extend(_x_x1776, _ctx); /*2419*/
        return kk_std_core_types__list_unbox(_x_x1775, KK_OWNED, _ctx);
      }
      {
        kk_std_core_types__list _trmc_x10407_0 = kk_datatype_null(); /*list<3813>*/;
        kk_std_core_types__list _trmc_x10408_0 = kk_std_core_types__new_Cons(_ru_x1362, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10866, _trmc_x10407_0, _ctx); /*list<3813>*/;
        kk_field_addr_t _b_x753_761 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10408_0, _ctx)->tail, _ctx); /*@field-addr<list<3813>>*/;
        kk_integer_t _own_x1230 = kk_integer_add_small_const(i_0, 1, _ctx); /*int*/;
        kk_std_core_types__cctx _own_x1229 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10408_0, _ctx)),_b_x753_761,kk_context()); /*ctx<0>*/;
        { // tailcall
          i_0 = _own_x1230;
          xs = xx_0;
          ys = yy_0;
          _acc_0 = _own_x1229;
          goto kk__tailcall;
        }
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_integer_drop(i_0, _ctx);
      kk_box_t _x_x1779 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1779, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_integer_drop(i_0, _ctx);
    kk_box_t _x_x1780 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1780, KK_OWNED, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__unroll_zipwith_iter_10021(kk_integer_t i_1, kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,c,e> (i : int, xs : list<a>, ys : list<b>, f : (int, a, b) -> e c) -> e list<c> */ 
  kk_std_core_types__cctx _own_x1227 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  return kk_std_core_list__trmc_unroll_zipwith_iter_10021(i_1, xs_0, ys_0, f_1, _own_x1227, _ctx);
}
 
// lifted local: unzip, iter

kk_std_core_types__tuple2 kk_std_core_list__unroll_lift_unzip_5735_10022(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_context_t* _ctx) { /* forall<a,b,c,d> (ys : list<(a, b)>, acc1 : cctx<c,list<a>>, acc2 : cctx<d,list<b>>) -> (c, d) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1781 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x770 = _con_x1781->head;
    kk_std_core_types__tuple2 _pat_0 = kk_std_core_types__tuple2_unbox(_box_x770, KK_BORROWED, _ctx);
    kk_std_core_types__list xx = _con_x1781->tail;
    kk_box_t x = _pat_0.fst;
    kk_box_t y = _pat_0.snd;
    kk_reuse_t _ru_x1363 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_dup(x, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_drop(_box_x770, _ctx);
      _ru_x1363 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x3917;
    kk_std_core_types__list _x_x1782 = kk_datatype_null(); /*list<4024>*/
    _cctx_x3917 = kk_std_core_types__new_Cons(_ru_x1363, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1782, _ctx); /*list<4024>*/
    kk_field_addr_t _cctx_x3918 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3917, _ctx)->tail, _ctx); /*@field-addr<list<4024>>*/;
    kk_std_core_types__list _cctx_x3960;
    kk_std_core_types__list _x_x1783 = kk_datatype_null(); /*list<4025>*/
    _cctx_x3960 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1783, _ctx); /*list<4025>*/
    kk_field_addr_t _cctx_x3961 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3960, _ctx)->tail, _ctx); /*@field-addr<list<4025>>*/;
    kk_std_core_types__list _b_x783_791 = _cctx_x3917; /*list<4024>*/;
    kk_field_addr_t _b_x784_792 = _cctx_x3918; /*@field-addr<list<4024>>*/;
    kk_std_core_types__list _b_x785_793 = _cctx_x3960; /*list<4025>*/;
    kk_field_addr_t _b_x786_794 = _cctx_x3961; /*@field-addr<list<4025>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1784;
      kk_std_core_types__cctx _x_x1785 = kk_cctx_create((kk_std_core_types__list_box(_b_x783_791, _ctx)),_b_x784_792,kk_context()); /*cctx<0,1>*/
      _x_x1784 = kk_cctx_compose(acc1,_x_x1785,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1786;
      kk_std_core_types__cctx _x_x1787 = kk_cctx_create((kk_std_core_types__list_box(_b_x785_793, _ctx)),_b_x786_794,kk_context()); /*cctx<0,1>*/
      _x_x1786 = kk_cctx_compose(acc2,_x_x1787,kk_context()); /*cctx<394,396>*/
      ys = xx;
      acc1 = _x_x1784;
      acc2 = _x_x1786;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1788 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1789 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    return kk_std_core_types__new_Tuple2(_x_x1788, _x_x1789, _ctx);
  }
}
 
// Unzip a list of pairs into two lists

kk_std_core_types__tuple2 kk_std_core_list_unzip(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a,b> (xs : list<(a, b)>) -> (list<a>, list<b>) */ 
  kk_std_core_types__cctx acc1_10151 = kk_cctx_empty(kk_context()); /*ctx<list<4073>>*/;
  kk_std_core_types__cctx acc2_10152 = kk_cctx_empty(kk_context()); /*ctx<list<4074>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x811_813;
    kk_box_t _x_x1792 = kk_cctx_apply(acc1_10151,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x811_813 = kk_std_core_types__list_unbox(_x_x1792, KK_OWNED, _ctx); /*list<4073>*/
    kk_std_core_types__list _b_x812_814;
    kk_box_t _x_x1793 = kk_cctx_apply(acc2_10152,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x812_814 = kk_std_core_types__list_unbox(_x_x1793, KK_OWNED, _ctx); /*list<4074>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x811_813, _ctx), kk_std_core_types__list_box(_b_x812_814, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip_5735_10022(xs, acc1_10151, acc2_10152, _ctx);
  }
}
 
// lifted local: unzip3, iter

kk_std_core_types__tuple3 kk_std_core_list__unroll_lift_unzip3_5736_10023(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,b1> (ys : list<(a, b, c)>, acc1 : cctx<d,list<a>>, acc2 : cctx<a1,list<b>>, acc3 : cctx<b1,list<c>>) -> (d, a1, b1) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1794 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x819 = _con_x1794->head;
    kk_std_core_types__tuple3 _pat_0 = kk_std_core_types__tuple3_unbox(_box_x819, KK_BORROWED, _ctx);
    kk_std_core_types__list xx = _con_x1794->tail;
    kk_box_t x = _pat_0.fst;
    kk_box_t y = _pat_0.snd;
    kk_box_t z = _pat_0.thd;
    kk_reuse_t _ru_x1364 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_dup(x, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_box_drop(_box_x819, _ctx);
      _ru_x1364 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x4133;
    kk_std_core_types__list _x_x1795 = kk_datatype_null(); /*list<4302>*/
    _cctx_x4133 = kk_std_core_types__new_Cons(_ru_x1364, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1795, _ctx); /*list<4302>*/
    kk_field_addr_t _cctx_x4134 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4133, _ctx)->tail, _ctx); /*@field-addr<list<4302>>*/;
    kk_std_core_types__list _cctx_x4176;
    kk_std_core_types__list _x_x1796 = kk_datatype_null(); /*list<4303>*/
    _cctx_x4176 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1796, _ctx); /*list<4303>*/
    kk_field_addr_t _cctx_x4177 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4176, _ctx)->tail, _ctx); /*@field-addr<list<4303>>*/;
    kk_std_core_types__list _cctx_x4219;
    kk_std_core_types__list _x_x1797 = kk_datatype_null(); /*list<4304>*/
    _cctx_x4219 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), z, _x_x1797, _ctx); /*list<4304>*/
    kk_field_addr_t _cctx_x4220 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4219, _ctx)->tail, _ctx); /*@field-addr<list<4304>>*/;
    kk_std_core_types__list _b_x838_850 = _cctx_x4133; /*list<4302>*/;
    kk_field_addr_t _b_x839_851 = _cctx_x4134; /*@field-addr<list<4302>>*/;
    kk_std_core_types__list _b_x840_852 = _cctx_x4176; /*list<4303>*/;
    kk_field_addr_t _b_x841_853 = _cctx_x4177; /*@field-addr<list<4303>>*/;
    kk_std_core_types__list _b_x842_854 = _cctx_x4219; /*list<4304>*/;
    kk_field_addr_t _b_x843_855 = _cctx_x4220; /*@field-addr<list<4304>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1798;
      kk_std_core_types__cctx _x_x1799 = kk_cctx_create((kk_std_core_types__list_box(_b_x838_850, _ctx)),_b_x839_851,kk_context()); /*cctx<0,1>*/
      _x_x1798 = kk_cctx_compose(acc1,_x_x1799,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1800;
      kk_std_core_types__cctx _x_x1801 = kk_cctx_create((kk_std_core_types__list_box(_b_x840_852, _ctx)),_b_x841_853,kk_context()); /*cctx<0,1>*/
      _x_x1800 = kk_cctx_compose(acc2,_x_x1801,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1802;
      kk_std_core_types__cctx _x_x1803 = kk_cctx_create((kk_std_core_types__list_box(_b_x842_854, _ctx)),_b_x843_855,kk_context()); /*cctx<0,1>*/
      _x_x1802 = kk_cctx_compose(acc3,_x_x1803,kk_context()); /*cctx<394,396>*/
      ys = xx;
      acc1 = _x_x1798;
      acc2 = _x_x1800;
      acc3 = _x_x1802;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1804 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1805 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1806 = kk_cctx_apply(acc3,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    return kk_std_core_types__new_Tuple3(_x_x1804, _x_x1805, _x_x1806, _ctx);
  }
}
 
// Unzip a list of triples into three lists

kk_std_core_types__tuple3 kk_std_core_list_unzip3(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a,b,c> (xs : list<(a, b, c)>) -> (list<a>, list<b>, list<c>) */ 
  kk_std_core_types__cctx acc1_10154 = kk_cctx_empty(kk_context()); /*ctx<list<4372>>*/;
  kk_std_core_types__cctx acc2_10155 = kk_cctx_empty(kk_context()); /*ctx<list<4373>>*/;
  kk_std_core_types__cctx acc3_10156 = kk_cctx_empty(kk_context()); /*ctx<list<4374>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x880_883;
    kk_box_t _x_x1810 = kk_cctx_apply(acc1_10154,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x880_883 = kk_std_core_types__list_unbox(_x_x1810, KK_OWNED, _ctx); /*list<4372>*/
    kk_std_core_types__list _b_x881_884;
    kk_box_t _x_x1811 = kk_cctx_apply(acc2_10155,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x881_884 = kk_std_core_types__list_unbox(_x_x1811, KK_OWNED, _ctx); /*list<4373>*/
    kk_std_core_types__list _b_x882_885;
    kk_box_t _x_x1812 = kk_cctx_apply(acc3_10156,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x882_885 = kk_std_core_types__list_unbox(_x_x1812, KK_OWNED, _ctx); /*list<4374>*/
    return kk_std_core_types__new_Tuple3(kk_std_core_types__list_box(_b_x880_883, _ctx), kk_std_core_types__list_box(_b_x881_884, _ctx), kk_std_core_types__list_box(_b_x882_885, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip3_5736_10023(xs, acc1_10154, acc2_10155, acc3_10156, _ctx);
  }
}
 
// lifted local: unzip4, iter

kk_std_core_types__tuple4 kk_std_core_list__unroll_lift_unzip4_5737_10024(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_std_core_types__cctx acc4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,b1,c1,d1> (ys : list<(a, b, c, d)>, acc1 : cctx<a1,list<a>>, acc2 : cctx<b1,list<b>>, acc3 : cctx<c1,list<c>>, acc4 : cctx<d1,list<d>>) -> (a1, b1, c1, d1) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1813 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x892 = _con_x1813->head;
    kk_std_core_types__tuple4 _pat_0 = kk_std_core_types__tuple4_unbox(_box_x892, KK_BORROWED, _ctx);
    struct kk_std_core_types_Tuple4* _con_x1814 = kk_std_core_types__as_Tuple4(_pat_0, _ctx);
    kk_std_core_types__list xx = _con_x1813->tail;
    kk_box_t x = _con_x1814->fst;
    kk_box_t y = _con_x1814->snd;
    kk_box_t z = _con_x1814->thd;
    kk_box_t w = _con_x1814->field4;
    kk_reuse_t _ru_x1366 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_0, _ctx)) {
        kk_datatype_ptr_free(_pat_0, _ctx);
      }
      else {
        kk_box_dup(w, _ctx);
        kk_box_dup(x, _ctx);
        kk_box_dup(y, _ctx);
        kk_box_dup(z, _ctx);
        kk_datatype_ptr_decref(_pat_0, _ctx);
      }
      _ru_x1366 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(w, _ctx);
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x4440;
    kk_std_core_types__list _x_x1815 = kk_datatype_null(); /*list<4671>*/
    _cctx_x4440 = kk_std_core_types__new_Cons(_ru_x1366, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1815, _ctx); /*list<4671>*/
    kk_field_addr_t _cctx_x4441 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4440, _ctx)->tail, _ctx); /*@field-addr<list<4671>>*/;
    kk_std_core_types__list _cctx_x4483;
    kk_std_core_types__list _x_x1816 = kk_datatype_null(); /*list<4672>*/
    _cctx_x4483 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1816, _ctx); /*list<4672>*/
    kk_field_addr_t _cctx_x4484 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4483, _ctx)->tail, _ctx); /*@field-addr<list<4672>>*/;
    kk_std_core_types__list _cctx_x4526;
    kk_std_core_types__list _x_x1817 = kk_datatype_null(); /*list<4673>*/
    _cctx_x4526 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), z, _x_x1817, _ctx); /*list<4673>*/
    kk_field_addr_t _cctx_x4527 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4526, _ctx)->tail, _ctx); /*@field-addr<list<4673>>*/;
    kk_std_core_types__list _cctx_x4569;
    kk_std_core_types__list _x_x1818 = kk_datatype_null(); /*list<4674>*/
    _cctx_x4569 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), w, _x_x1818, _ctx); /*list<4674>*/
    kk_field_addr_t _cctx_x4570 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4569, _ctx)->tail, _ctx); /*@field-addr<list<4674>>*/;
    kk_std_core_types__list _b_x917_933 = _cctx_x4440; /*list<4671>*/;
    kk_field_addr_t _b_x918_934 = _cctx_x4441; /*@field-addr<list<4671>>*/;
    kk_std_core_types__list _b_x919_935 = _cctx_x4483; /*list<4672>*/;
    kk_field_addr_t _b_x920_936 = _cctx_x4484; /*@field-addr<list<4672>>*/;
    kk_std_core_types__list _b_x921_937 = _cctx_x4526; /*list<4673>*/;
    kk_field_addr_t _b_x922_938 = _cctx_x4527; /*@field-addr<list<4673>>*/;
    kk_std_core_types__list _b_x923_939 = _cctx_x4569; /*list<4674>*/;
    kk_field_addr_t _b_x924_940 = _cctx_x4570; /*@field-addr<list<4674>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1819;
      kk_std_core_types__cctx _x_x1820 = kk_cctx_create((kk_std_core_types__list_box(_b_x917_933, _ctx)),_b_x918_934,kk_context()); /*cctx<0,1>*/
      _x_x1819 = kk_cctx_compose(acc1,_x_x1820,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1821;
      kk_std_core_types__cctx _x_x1822 = kk_cctx_create((kk_std_core_types__list_box(_b_x919_935, _ctx)),_b_x920_936,kk_context()); /*cctx<0,1>*/
      _x_x1821 = kk_cctx_compose(acc2,_x_x1822,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1823;
      kk_std_core_types__cctx _x_x1824 = kk_cctx_create((kk_std_core_types__list_box(_b_x921_937, _ctx)),_b_x922_938,kk_context()); /*cctx<0,1>*/
      _x_x1823 = kk_cctx_compose(acc3,_x_x1824,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1825;
      kk_std_core_types__cctx _x_x1826 = kk_cctx_create((kk_std_core_types__list_box(_b_x923_939, _ctx)),_b_x924_940,kk_context()); /*cctx<0,1>*/
      _x_x1825 = kk_cctx_compose(acc4,_x_x1826,kk_context()); /*cctx<394,396>*/
      ys = xx;
      acc1 = _x_x1819;
      acc2 = _x_x1821;
      acc3 = _x_x1823;
      acc4 = _x_x1825;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1827 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1828 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1829 = kk_cctx_apply(acc3,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1830 = kk_cctx_apply(acc4,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x1827, _x_x1828, _x_x1829, _x_x1830, _ctx);
  }
}
 
// Unzip a list of quadruples into four lists

kk_std_core_types__tuple4 kk_std_core_list_unzip4(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a,b,c,d> (xs : list<(a, b, c, d)>) -> (list<a>, list<b>, list<c>, list<d>) */ 
  kk_std_core_types__cctx acc1_10158 = kk_cctx_empty(kk_context()); /*ctx<list<4762>>*/;
  kk_std_core_types__cctx acc2_10159 = kk_cctx_empty(kk_context()); /*ctx<list<4763>>*/;
  kk_std_core_types__cctx acc3_10160 = kk_cctx_empty(kk_context()); /*ctx<list<4764>>*/;
  kk_std_core_types__cctx acc4_10161 = kk_cctx_empty(kk_context()); /*ctx<list<4765>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x973_977;
    kk_box_t _x_x1835 = kk_cctx_apply(acc1_10158,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x973_977 = kk_std_core_types__list_unbox(_x_x1835, KK_OWNED, _ctx); /*list<4762>*/
    kk_std_core_types__list _b_x974_978;
    kk_box_t _x_x1836 = kk_cctx_apply(acc2_10159,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x974_978 = kk_std_core_types__list_unbox(_x_x1836, KK_OWNED, _ctx); /*list<4763>*/
    kk_std_core_types__list _b_x975_979;
    kk_box_t _x_x1837 = kk_cctx_apply(acc3_10160,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x975_979 = kk_std_core_types__list_unbox(_x_x1837, KK_OWNED, _ctx); /*list<4764>*/
    kk_std_core_types__list _b_x976_980;
    kk_box_t _x_x1838 = kk_cctx_apply(acc4_10161,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x976_980 = kk_std_core_types__list_unbox(_x_x1838, KK_OWNED, _ctx); /*list<4765>*/
    return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, kk_std_core_types__list_box(_b_x973_977, _ctx), kk_std_core_types__list_box(_b_x974_978, _ctx), kk_std_core_types__list_box(_b_x975_979, _ctx), kk_std_core_types__list_box(_b_x976_980, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip4_5737_10024(xs, acc1_10158, acc2_10159, acc3_10160, acc4_10161, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__tuple2 kk_std_core_list__mlift_unroll_lift_span_5738_10025_10703(kk_std_core_types__cctx acc, kk_function_t predicate, kk_box_t y, kk_std_core_types__list ys, kk_std_core_types__list yy, bool _y_x10606, kk_context_t* _ctx) { /* forall<a,b,e> (acc : cctx<a,list<b>>, predicate : (b) -> e bool, y : b, ys : list<b>, yy : list<b>, bool) -> e (a, list<b>) */ 
  if (_y_x10606) {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_std_core_types__list _cctx_x4824;
    kk_std_core_types__list _x_x1839 = kk_datatype_null(); /*list<4921>*/
    _cctx_x4824 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1839, _ctx); /*list<4921>*/
    kk_field_addr_t _cctx_x4825 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4824, _ctx)->tail, _ctx); /*@field-addr<list<4921>>*/;
    kk_std_core_types__cctx acc_0_10118;
    kk_std_core_types__cctx _x_x1840 = kk_cctx_create((kk_std_core_types__list_box(_cctx_x4824, _ctx)),_cctx_x4825,kk_context()); /*cctx<0,1>*/
    acc_0_10118 = kk_cctx_compose(acc,_x_x1840,kk_context()); /*cctx<4896,list<4921>>*/
    return kk_std_core_list__unroll_lift_span_5738_10025(predicate, yy, acc_0_10118, _ctx);
  }
  {
    kk_std_core_types__list_drop(yy, _ctx);
    kk_box_drop(y, _ctx);
    kk_function_drop(predicate, _ctx);
    kk_box_t _b_x1001_1003 = kk_cctx_apply(acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*4896*/;
    return kk_std_core_types__new_Tuple2(_b_x1001_1003, kk_std_core_types__list_box(ys, _ctx), _ctx);
  }
}
 
// lifted local: span, span-acc


// lift anonymous function
struct kk_std_core_list__unroll_lift_span_5738_10025_fun1845__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx acc_0;
  kk_function_t predicate_0;
  kk_box_t y_0;
  kk_std_core_types__list ys_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__unroll_lift_span_5738_10025_fun1845(kk_function_t _fself, kk_box_t _b_x1008, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_lift_span_5738_10025_fun1845(kk_std_core_types__cctx acc_0, kk_function_t predicate_0, kk_box_t y_0, kk_std_core_types__list ys_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_lift_span_5738_10025_fun1845__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_lift_span_5738_10025_fun1845__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_lift_span_5738_10025_fun1845, kk_context());
  _self->acc_0 = acc_0;
  _self->predicate_0 = predicate_0;
  _self->y_0 = y_0;
  _self->ys_0 = ys_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_lift_span_5738_10025_fun1845(kk_function_t _fself, kk_box_t _b_x1008, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_lift_span_5738_10025_fun1845__t* _self = kk_function_as(struct kk_std_core_list__unroll_lift_span_5738_10025_fun1845__t*, _fself, _ctx);
  kk_std_core_types__cctx acc_0 = _self->acc_0; /* cctx<4896,list<4921>> */
  kk_function_t predicate_0 = _self->predicate_0; /* (4921) -> 4922 bool */
  kk_box_t y_0 = _self->y_0; /* 4921 */
  kk_std_core_types__list ys_0 = _self->ys_0; /* list<4921> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<4921> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(acc_0, _ctx);kk_function_dup(predicate_0, _ctx);kk_box_dup(y_0, _ctx);kk_std_core_types__list_dup(ys_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  bool _y_x10606_0_1036 = kk_bool_unbox(_b_x1008); /*bool*/;
  kk_std_core_types__tuple2 _x_x1846 = kk_std_core_list__mlift_unroll_lift_span_5738_10025_10703(acc_0, predicate_0, y_0, ys_0, yy_0, _y_x10606_0_1036, _ctx); /*(4896, list<4921>)*/
  return kk_std_core_types__tuple2_box(_x_x1846, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_list__unroll_lift_span_5738_10025(kk_function_t predicate_0, kk_std_core_types__list ys_0, kk_std_core_types__cctx acc_0, kk_context_t* _ctx) { /* forall<a,e,b> (predicate : (a) -> e bool, ys : list<a>, acc : cctx<b,list<a>>) -> e (b, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys_0, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1841 = kk_std_core_types__as_Cons(ys_0, _ctx);
    kk_box_t y_0 = _con_x1841->head;
    kk_std_core_types__list yy_0 = _con_x1841->tail;
    kk_box_dup(y_0, _ctx);
    kk_std_core_types__list_dup(yy_0, _ctx);
    bool x_10877;
    kk_function_t _x_x1843 = kk_function_dup(predicate_0, _ctx); /*(4921) -> 4922 bool*/
    kk_box_t _x_x1842 = kk_box_dup(y_0, _ctx); /*4921*/
    x_10877 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1843, (_x_x1843, _x_x1842, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1844 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_lift_span_5738_10025_fun1845(acc_0, predicate_0, y_0, ys_0, yy_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__tuple2_unbox(_x_x1844, KK_OWNED, _ctx);
    }
    if (x_10877) {
      kk_reuse_t _ru_x1367 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys_0, _ctx)) {
        kk_std_core_types__list_drop(yy_0, _ctx);
        kk_box_drop(y_0, _ctx);
        _ru_x1367 = (kk_datatype_ptr_reuse(ys_0, _ctx));
      }
      else {
        kk_datatype_ptr_decref(ys_0, _ctx);
      }
      kk_std_core_types__list _cctx_x4824_0;
      kk_std_core_types__list _x_x1847 = kk_datatype_null(); /*list<4921>*/
      _cctx_x4824_0 = kk_std_core_types__new_Cons(_ru_x1367, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _x_x1847, _ctx); /*list<4921>*/
      kk_field_addr_t _cctx_x4825_0 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4824_0, _ctx)->tail, _ctx); /*@field-addr<list<4921>>*/;
      kk_std_core_types__cctx acc_0_10118_0;
      kk_std_core_types__cctx _x_x1848 = kk_cctx_create((kk_std_core_types__list_box(_cctx_x4824_0, _ctx)),_cctx_x4825_0,kk_context()); /*cctx<0,1>*/
      acc_0_10118_0 = kk_cctx_compose(acc_0,_x_x1848,kk_context()); /*cctx<4896,list<4921>>*/
      { // tailcall
        ys_0 = yy_0;
        acc_0 = acc_0_10118_0;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(yy_0, _ctx);
      kk_box_drop(y_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      kk_box_t _b_x1021_1028 = kk_cctx_apply(acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*4896*/;
      return kk_std_core_types__new_Tuple2(_b_x1021_1028, kk_std_core_types__list_box(ys_0, _ctx), _ctx);
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    kk_box_t _b_x1025_1032 = kk_cctx_apply(acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*4896*/;
    return kk_std_core_types__new_Tuple2(_b_x1025_1032, kk_std_core_types__list_box(ys_0, _ctx), _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_core_list_span(kk_std_core_types__list xs, kk_function_t predicate, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e (list<a>, list<a>) */ 
  kk_std_core_types__cctx acc = kk_cctx_empty(kk_context()); /*ctx<list<4921>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(predicate, _ctx);
    kk_std_core_types__list _b_x1047_1049;
    kk_box_t _x_x1849 = kk_cctx_apply(acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x1047_1049 = kk_std_core_types__list_unbox(_x_x1849, KK_OWNED, _ctx); /*list<4921>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x1047_1049, _ctx), kk_std_core_types__list_box(xs, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_span_5738_10025(predicate, xs, acc, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_take_while_10026_10704(kk_std_core_types__cctx _acc, kk_function_t predicate, kk_box_t x, kk_std_core_types__list xx, bool _y_x10614, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10614) {
    kk_std_core_types__list _trmc_x10409 = kk_datatype_null(); /*list<4980>*/;
    kk_std_core_types__list _trmc_x10410 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _trmc_x10409, _ctx); /*list<4980>*/;
    kk_field_addr_t _b_x1058_1063 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10410, _ctx)->tail, _ctx); /*@field-addr<list<4980>>*/;
    kk_std_core_types__cctx _x_x1850 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10410, _ctx)),_b_x1058_1063,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_take_while_10026(xx, predicate, _x_x1850, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_box_drop(x, _ctx);
    kk_function_drop(predicate, _ctx);
    kk_box_t _x_x1851 = kk_cctx_apply(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1851, KK_OWNED, _ctx);
  }
}
 
// Keep only those initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_take_while_10026_fun1856__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t predicate_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_take_while_10026_fun1856(kk_function_t _fself, kk_box_t _b_x1070, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_take_while_10026_fun1856(kk_std_core_types__cctx _acc_0, kk_function_t predicate_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_take_while_10026_fun1856__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_take_while_10026_fun1856__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_take_while_10026_fun1856, kk_context());
  _self->_acc_0 = _acc_0;
  _self->predicate_0 = predicate_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_take_while_10026_fun1856(kk_function_t _fself, kk_box_t _b_x1070, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_take_while_10026_fun1856__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_take_while_10026_fun1856__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<4980>> */
  kk_function_t predicate_0 = _self->predicate_0; /* (4980) -> 4981 bool */
  kk_box_t x_0 = _self->x_0; /* 4980 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<4980> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(predicate_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10614_0_1092 = kk_bool_unbox(_b_x1070); /*bool*/;
  kk_std_core_types__list _x_x1857 = kk_std_core_list__mlift_trmc_unroll_take_while_10026_10704(_acc_0, predicate_0, x_0, xx_0, _y_x10614_0_1092, _ctx); /*list<4980>*/
  return kk_std_core_types__list_box(_x_x1857, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_take_while_10026(kk_std_core_types__list xs, kk_function_t predicate_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1852 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1852->head;
    kk_std_core_types__list xx_0 = _con_x1852->tail;
    kk_reuse_t _ru_x1368 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1368 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10880;
    kk_function_t _x_x1854 = kk_function_dup(predicate_0, _ctx); /*(4980) -> 4981 bool*/
    kk_box_t _x_x1853 = kk_box_dup(x_0, _ctx); /*4980*/
    x_1_10880 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1854, (_x_x1854, _x_x1853, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1368,kk_context());
      kk_box_t _x_x1855 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_take_while_10026_fun1856(_acc_0, predicate_0, x_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1855, KK_OWNED, _ctx);
    }
    if (x_1_10880) {
      kk_std_core_types__list _trmc_x10409_0 = kk_datatype_null(); /*list<4980>*/;
      kk_std_core_types__list _trmc_x10410_0 = kk_std_core_types__new_Cons(_ru_x1368, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _trmc_x10409_0, _ctx); /*list<4980>*/;
      kk_field_addr_t _b_x1076_1084 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10410_0, _ctx)->tail, _ctx); /*@field-addr<list<4980>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1858 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10410_0, _ctx)),_b_x1076_1084,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1858;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1368,kk_context());
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      kk_box_t _x_x1859 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1859, KK_OWNED, _ctx);
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    kk_box_t _x_x1860 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1860, KK_OWNED, _ctx);
  }
}
 
// Keep only those initial elements that satisfy `predicate`

kk_std_core_types__list kk_std_core_list__unroll_take_while_10026(kk_std_core_types__list xs_0, kk_function_t predicate_1, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1861 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_take_while_10026(xs_0, predicate_1, _x_x1861, _ctx);
}
 
// Concatenate all strings in a list in reverse order

kk_string_t kk_std_core_list_reverse_join(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  kk_std_core_types__list xs_0_10122;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    xs_0_10122 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  else {
    xs_0_10122 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), xs, _ctx); /*list<string>*/
  }
  if (kk_std_core_types__is_Nil(xs_0_10122, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1864 = kk_std_core_types__as_Cons(xs_0_10122, _ctx);
    kk_box_t _box_x1093 = _con_x1864->head;
    kk_std_core_types__list _pat_1 = _con_x1864->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x1093);
      if kk_likely(kk_datatype_ptr_is_unique(xs_0_10122, _ctx)) {
        kk_datatype_ptr_free(xs_0_10122, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_0_10122, _ctx);
      }
      return x;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1865 = kk_std_core_types__as_Cons(xs_0_10122, _ctx);
    kk_box_t _box_x1094 = _con_x1865->head;
    kk_std_core_types__list _pat_3 = _con_x1865->tail;
    struct kk_std_core_types_Cons* _con_x1866 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x1095 = _con_x1866->head;
    kk_std_core_types__list _pat_4 = _con_x1866->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x1094);
      kk_string_t y = kk_string_unbox(_box_x1095);
      if kk_likely(kk_datatype_ptr_is_unique(xs_0_10122, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(xs_0_10122, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(xs_0_10122, _ctx);
      }
      return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
    }
  }
  {
    kk_vector_t _x_x1867 = kk_std_core_vector_unvlist(xs_0_10122, _ctx); /*vector<978>*/
    return kk_string_join(_x_x1867,kk_context());
  }
}
 
// lifted local: concat, concat-pre

kk_std_core_types__list kk_std_core_list__trmc_lift_concat_5739(kk_std_core_types__list ys, kk_std_core_types__list zss, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, zss : list<list<a>>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1871 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1871->head;
    kk_std_core_types__list yy = _con_x1871->tail;
    kk_reuse_t _ru_x1372 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1372 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10411 = kk_datatype_null(); /*list<5090>*/;
    kk_std_core_types__list _trmc_x10412 = kk_std_core_types__new_Cons(_ru_x1372, 0, y, _trmc_x10411, _ctx); /*list<5090>*/;
    kk_field_addr_t _b_x1101_1107 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10412, _ctx)->tail, _ctx); /*@field-addr<list<5090>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1872 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10412, _ctx)),_b_x1101_1107,kk_context()); /*ctx<0>*/
      ys = yy;
      _acc = _x_x1872;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_Cons(zss, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1873 = kk_std_core_types__as_Cons(zss, _ctx);
    kk_box_t _box_x1102 = _con_x1873->head;
    kk_std_core_types__list zzs = _con_x1873->tail;
    kk_std_core_types__list zs = kk_std_core_types__list_unbox(_box_x1102, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(zss, _ctx)) {
      kk_datatype_ptr_free(zss, _ctx);
    }
    else {
      kk_std_core_types__list_dup(zs, _ctx);
      kk_std_core_types__list_dup(zzs, _ctx);
      kk_datatype_ptr_decref(zss, _ctx);
    }
    { // tailcall
      ys = zs;
      zss = zzs;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1874 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1874, KK_OWNED, _ctx);
  }
}
 
// lifted local: concat, concat-pre

kk_std_core_types__list kk_std_core_list__lift_concat_5739(kk_std_core_types__list ys_0, kk_std_core_types__list zss_0, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, zss : list<list<a>>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1875 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_concat_5739(ys_0, zss_0, _x_x1875, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_flatmap_5740_10705(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list zz, kk_std_core_types__list ys_1_10131, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e list<b>, zz : list<a>, ys@1@10131 : list<b>) -> e list<b> */ 
  return kk_std_core_list__trmc_lift_flatmap_5740(f, ys_1_10131, zz, _acc, _ctx);
}
 
// lifted local: flatmap, flatmap-pre


// lift anonymous function
struct kk_std_core_list__trmc_lift_flatmap_5740_fun1882__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list zz_0;
};
static kk_box_t kk_std_core_list__trmc_lift_flatmap_5740_fun1882(kk_function_t _fself, kk_box_t _b_x1120, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_lift_flatmap_5740_fun1882(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list zz_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_flatmap_5740_fun1882__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_lift_flatmap_5740_fun1882__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_lift_flatmap_5740_fun1882, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->zz_0 = zz_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_lift_flatmap_5740_fun1882(kk_function_t _fself, kk_box_t _b_x1120, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_flatmap_5740_fun1882__t* _self = kk_function_as(struct kk_std_core_list__trmc_lift_flatmap_5740_fun1882__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<5182>> */
  kk_function_t f_0 = _self->f_0; /* (5181) -> 5183 list<5182> */
  kk_std_core_types__list zz_0 = _self->zz_0; /* list<5181> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(zz_0, _ctx);}, {}, _ctx)
  kk_std_core_types__list ys_1_10131_0_1132 = kk_std_core_types__list_unbox(_b_x1120, KK_OWNED, _ctx); /*list<5182>*/;
  kk_std_core_types__list _x_x1883 = kk_std_core_list__mlift_trmc_lift_flatmap_5740_10705(_acc_0, f_0, zz_0, ys_1_10131_0_1132, _ctx); /*list<5182>*/
  return kk_std_core_types__list_box(_x_x1883, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_lift_flatmap_5740(kk_function_t f_0, kk_std_core_types__list ys, kk_std_core_types__list zs, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1877 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1877->head;
    kk_std_core_types__list yy = _con_x1877->tail;
    kk_reuse_t _ru_x1374 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1374 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10413 = kk_datatype_null(); /*list<5182>*/;
    kk_std_core_types__list _trmc_x10414 = kk_std_core_types__new_Cons(_ru_x1374, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10413, _ctx); /*list<5182>*/;
    kk_field_addr_t _b_x1118_1125 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10414, _ctx)->tail, _ctx); /*@field-addr<list<5182>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1878 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10414, _ctx)),_b_x1118_1125,kk_context()); /*ctx<0>*/
      ys = yy;
      _acc_0 = _x_x1878;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_Cons(zs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1879 = kk_std_core_types__as_Cons(zs, _ctx);
    kk_box_t z = _con_x1879->head;
    kk_std_core_types__list zz_0 = _con_x1879->tail;
    if kk_likely(kk_datatype_ptr_is_unique(zs, _ctx)) {
      kk_datatype_ptr_free(zs, _ctx);
    }
    else {
      kk_box_dup(z, _ctx);
      kk_std_core_types__list_dup(zz_0, _ctx);
      kk_datatype_ptr_decref(zs, _ctx);
    }
    kk_std_core_types__list x_10887;
    kk_function_t _x_x1880 = kk_function_dup(f_0, _ctx); /*(5181) -> 5183 list<5182>*/
    x_10887 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_box_t, kk_context_t*), _x_x1880, (_x_x1880, z, _ctx), _ctx); /*list<5182>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_10887, _ctx);
      kk_box_t _x_x1881 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_lift_flatmap_5740_fun1882(_acc_0, f_0, zz_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1881, KK_OWNED, _ctx);
    }
    { // tailcall
      ys = x_10887;
      zs = zz_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1884 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1884, KK_OWNED, _ctx);
  }
}
 
// lifted local: flatmap, flatmap-pre

kk_std_core_types__list kk_std_core_list__lift_flatmap_5740(kk_function_t f_1, kk_std_core_types__list ys_0, kk_std_core_types__list zs_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1885 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_flatmap_5740(f_1, ys_0, zs_0, _x_x1885, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_flatmap_maybe_10027_10706(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10628, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_x10628, _ctx)) {
    kk_box_t y = _y_x10628._cons.Just.value;
    kk_std_core_types__list _trmc_x10415 = kk_datatype_null(); /*list<5269>*/;
    kk_std_core_types__list _trmc_x10416 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10415, _ctx); /*list<5269>*/;
    kk_field_addr_t _b_x1138_1141 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10416, _ctx)->tail, _ctx); /*@field-addr<list<5269>>*/;
    kk_std_core_types__cctx _x_x1887 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10416, _ctx)),_b_x1138_1141,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_flatmap_maybe_10027(xx, f, _x_x1887, _ctx);
  }
  {
    return kk_std_core_list__trmc_unroll_flatmap_maybe_10027(xx, f, _acc, _ctx);
  }
}
 
// Concatenate the `Just` result elements from applying a function to all elements.


// lift anonymous function
struct kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1891__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1891(kk_function_t _fself, kk_box_t _b_x1146, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_flatmap_maybe_10027_fun1891(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1891__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1891__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1891, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1891(kk_function_t _fself, kk_box_t _b_x1146, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1891__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1891__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<5269>> */
  kk_function_t f_0 = _self->f_0; /* (5268) -> 5270 maybe<5269> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<5268> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10628_0_1164 = kk_std_core_types__maybe_unbox(_b_x1146, KK_OWNED, _ctx); /*maybe<5269>*/;
  kk_std_core_types__list _x_x1892 = kk_std_core_list__mlift_trmc_unroll_flatmap_maybe_10027_10706(_acc_0, f_0, xx_0, _y_x10628_0_1164, _ctx); /*list<5269>*/
  return kk_std_core_types__list_box(_x_x1892, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_flatmap_maybe_10027(kk_std_core_types__list xs, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1888 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1888->head;
    kk_std_core_types__list xx_0 = _con_x1888->tail;
    kk_reuse_t _ru_x1376 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1376 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10893;
    kk_function_t _x_x1889 = kk_function_dup(f_0, _ctx); /*(5268) -> 5270 maybe<5269>*/
    x_0_10893 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1889, (_x_x1889, x, _ctx), _ctx); /*maybe<5269>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1376,kk_context());
      kk_std_core_types__maybe_drop(x_0_10893, _ctx);
      kk_box_t _x_x1890 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_flatmap_maybe_10027_fun1891(_acc_0, f_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1890, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Just(x_0_10893, _ctx)) {
      kk_box_t y_0 = x_0_10893._cons.Just.value;
      kk_std_core_types__list _trmc_x10415_0 = kk_datatype_null(); /*list<5269>*/;
      kk_std_core_types__list _trmc_x10416_0 = kk_std_core_types__new_Cons(_ru_x1376, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10415_0, _ctx); /*list<5269>*/;
      kk_field_addr_t _b_x1152_1158 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10416_0, _ctx)->tail, _ctx); /*@field-addr<list<5269>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1893 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10416_0, _ctx)),_b_x1152_1158,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1893;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1376,kk_context());
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1894 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1894, KK_OWNED, _ctx);
  }
}
 
// Concatenate the `Just` result elements from applying a function to all elements.

kk_std_core_types__list kk_std_core_list__unroll_flatmap_maybe_10027(kk_std_core_types__list xs_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1895 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_flatmap_maybe_10027(xs_0, f_1, _x_x1895, _ctx);
}
 
// Concatenate a list of `:maybe` values

kk_std_core_types__list kk_std_core_list__trmc_unroll_concat_maybe_10028(kk_std_core_types__list xs, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1897 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1165 = _con_x1897->head;
    kk_std_core_types__list xx = _con_x1897->tail;
    kk_std_core_types__maybe x = kk_std_core_types__maybe_unbox(_box_x1165, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x1377 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__maybe_dup(x, _ctx);
      kk_box_drop(_box_x1165, _ctx);
      _ru_x1377 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_std_core_types__maybe_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Just(x, _ctx)) {
      kk_box_t y = x._cons.Just.value;
      kk_std_core_types__list _trmc_x10417 = kk_datatype_null(); /*list<5334>*/;
      kk_std_core_types__list _trmc_x10418 = kk_std_core_types__new_Cons(_ru_x1377, 0, y, _trmc_x10417, _ctx); /*list<5334>*/;
      kk_field_addr_t _b_x1171_1176 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10418, _ctx)->tail, _ctx); /*@field-addr<list<5334>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1898 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10418, _ctx)),_b_x1171_1176,kk_context()); /*ctx<0>*/
        xs = xx;
        _acc = _x_x1898;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1377,kk_context());
      { // tailcall
        xs = xx;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x1899 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1899, KK_OWNED, _ctx);
  }
}
 
// Concatenate a list of `:maybe` values

kk_std_core_types__list kk_std_core_list__unroll_concat_maybe_10028(kk_std_core_types__list xs_0, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1900 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_concat_maybe_10028(xs_0, _x_x1900, _ctx);
}
 
// Return the last element of a list (or `Nothing` for the empty list)

kk_std_core_types__maybe kk_std_core_list_last(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1902 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_std_core_types__list _pat_0 = _con_x1902->tail;
    if (kk_std_core_types__is_Nil(_pat_0, _ctx)) {
      kk_box_t x = _con_x1902->head;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_box_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return kk_std_core_types__new_Just(x, _ctx);
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1903 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _pat_2 = _con_x1903->head;
    kk_std_core_types__list xx = _con_x1903->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_pat_2, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    { // tailcall
      xs = xx;
      goto kk__tailcall;
    }
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Return the list without its last element.
// Return an empty list for an empty list.

kk_std_core_types__list kk_std_core_list__trmc_init(kk_std_core_types__list xs, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1904 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_std_core_types__list xx = _con_x1904->tail;
    if (kk_std_core_types__is_Cons(xx, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1905 = kk_std_core_types__as_Cons(xx, _ctx);
      kk_box_t x = _con_x1904->head;
      kk_reuse_t _ru_x1380 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        _ru_x1380 = (kk_datatype_ptr_reuse(xs, _ctx));
      }
      else {
        kk_box_dup(x, _ctx);
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_std_core_types__list _trmc_x10419 = kk_datatype_null(); /*list<5425>*/;
      kk_std_core_types__list _trmc_x10420 = kk_std_core_types__new_Cons(_ru_x1380, 0, x, _trmc_x10419, _ctx); /*list<5425>*/;
      kk_field_addr_t _b_x1187_1192 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10420, _ctx)->tail, _ctx); /*@field-addr<list<5425>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1906 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10420, _ctx)),_b_x1187_1192,kk_context()); /*ctx<0>*/
        xs = xx;
        _acc = _x_x1906;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_std_core_types__list_drop(xs, _ctx);
    kk_box_t _x_x1907 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1907, KK_OWNED, _ctx);
  }
}
 
// Return the list without its last element.
// Return an empty list for an empty list.

kk_std_core_types__list kk_std_core_list_init(kk_std_core_types__list xs_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1908 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_init(xs_0, _x_x1908, _ctx);
}
 
// Get (zero-based) element `n`  of a list. Return a `:maybe` type.

kk_std_core_types__maybe kk_std_core_list__unroll_index_10029(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1909 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1909->head;
    kk_std_core_types__list xx = _con_x1909->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool _match_x1218 = kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x1218) {
      kk_box_drop(x, _ctx);
      { // tailcall
        kk_integer_t _x_x1910 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        xs = xx;
        n = _x_x1910;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx, _ctx);
      bool _match_x1219;
      bool _brw_x1220 = kk_integer_eq_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(n, _ctx);
      _match_x1219 = _brw_x1220; /*bool*/
      if (_match_x1219) {
        return kk_std_core_types__new_Just(x, _ctx);
      }
      {
        kk_box_drop(x, _ctx);
        return kk_std_core_types__new_Nothing(_ctx);
      }
    }
  }
  {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// monadic lift

bool kk_std_core_list__mlift_unroll_all_10030_10707(kk_function_t predicate, kk_std_core_types__list xx, bool _y_x10636, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 
  if (_y_x10636) {
    return kk_std_core_list__unroll_all_10030(xx, predicate, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return false;
  }
}
 
// Do all elements satisfy a predicate ?


// lift anonymous function
struct kk_std_core_list__unroll_all_10030_fun1914__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_all_10030_fun1914(kk_function_t _fself, kk_box_t _b_x1199, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_all_10030_fun1914(kk_function_t predicate_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_all_10030_fun1914__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_all_10030_fun1914__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_all_10030_fun1914, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_all_10030_fun1914(kk_function_t _fself, kk_box_t _b_x1199, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_all_10030_fun1914__t* _self = kk_function_as(struct kk_std_core_list__unroll_all_10030_fun1914__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (5562) -> 5563 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<5562> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10636_0_1201 = kk_bool_unbox(_b_x1199); /*bool*/;
  bool _x_x1915 = kk_std_core_list__mlift_unroll_all_10030_10707(predicate_0, xx_0, _y_x10636_0_1201, _ctx); /*bool*/
  return kk_bool_box(_x_x1915);
}

bool kk_std_core_list__unroll_all_10030(kk_std_core_types__list xs, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1911 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1911->head;
    kk_std_core_types__list xx_0 = _con_x1911->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10899;
    kk_function_t _x_x1912 = kk_function_dup(predicate_0, _ctx); /*(5562) -> 5563 bool*/
    x_0_10899 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1912, (_x_x1912, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1913 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_all_10030_fun1914(predicate_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x1913);
    }
    if (x_0_10899) { // tailcall
                     xs = xx_0;
                     goto kk__tailcall;
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return false;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return true;
  }
}
 
// monadic lift

bool kk_std_core_list__mlift_unroll_any_10031_10708(kk_function_t predicate, kk_std_core_types__list xx, bool _y_x10642, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 
  if (_y_x10642) {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return true;
  }
  {
    return kk_std_core_list__unroll_any_10031(xx, predicate, _ctx);
  }
}
 
// Are there any elements in a list that satisfy a predicate ?


// lift anonymous function
struct kk_std_core_list__unroll_any_10031_fun1919__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_any_10031_fun1919(kk_function_t _fself, kk_box_t _b_x1203, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_any_10031_fun1919(kk_function_t predicate_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_any_10031_fun1919__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_any_10031_fun1919__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_any_10031_fun1919, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_any_10031_fun1919(kk_function_t _fself, kk_box_t _b_x1203, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_any_10031_fun1919__t* _self = kk_function_as(struct kk_std_core_list__unroll_any_10031_fun1919__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (5609) -> 5610 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<5609> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10642_0_1205 = kk_bool_unbox(_b_x1203); /*bool*/;
  bool _x_x1920 = kk_std_core_list__mlift_unroll_any_10031_10708(predicate_0, xx_0, _y_x10642_0_1205, _ctx); /*bool*/
  return kk_bool_box(_x_x1920);
}

bool kk_std_core_list__unroll_any_10031(kk_std_core_types__list xs, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1916 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1916->head;
    kk_std_core_types__list xx_0 = _con_x1916->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10902;
    kk_function_t _x_x1917 = kk_function_dup(predicate_0, _ctx); /*(5609) -> 5610 bool*/
    x_0_10902 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1917, (_x_x1917, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1918 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_any_10031_fun1919(predicate_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x1918);
    }
    if (x_0_10902) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return true;
    }
    { // tailcall
      xs = xx_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return false;
  }
}
 
// lifted local: sum, @spec-x10327
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10322, using:
// @uniq-f@10322 = std/core/int/(+)

kk_integer_t kk_std_core_list__lift_sum_10350(kk_std_core_types__list _uniq_xs_10320, kk_integer_t _uniq_z_10321, kk_context_t* _ctx) { /* (list<int>, int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10320, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1921 = kk_std_core_types__as_Cons(_uniq_xs_10320, _ctx);
    kk_box_t _box_x1206 = _con_x1921->head;
    kk_std_core_types__list _uniq_xx_10325 = _con_x1921->tail;
    kk_integer_t _uniq_x_10324 = kk_integer_unbox(_box_x1206, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10320, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10320, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10324, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10325, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10320, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x1922 = kk_std_core_int__lp__plus__rp_(_uniq_z_10321, _uniq_x_10324, _ctx); /*int*/
      _uniq_xs_10320 = _uniq_xx_10325;
      _uniq_z_10321 = _x_x1922;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10321;
  }
}
 
// lifted local: minimum, @spec-x10335
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10330, using:
// @uniq-f@10330 = std/core/int/min

kk_integer_t kk_std_core_list__lift_minimum_10351(kk_std_core_types__list _uniq_xs_10328, kk_integer_t _uniq_z_10329, kk_context_t* _ctx) { /* (list<int>, int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10328, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1923 = kk_std_core_types__as_Cons(_uniq_xs_10328, _ctx);
    kk_box_t _box_x1207 = _con_x1923->head;
    kk_std_core_types__list _uniq_xx_10333 = _con_x1923->tail;
    kk_integer_t _uniq_x_10332 = kk_integer_unbox(_box_x1207, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10328, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10328, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10332, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10333, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10328, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x1924 = kk_std_core_int_min(_uniq_z_10329, _uniq_x_10332, _ctx); /*int*/
      _uniq_xs_10328 = _uniq_xx_10333;
      _uniq_z_10329 = _x_x1924;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10329;
  }
}
 
// Returns the smallest element of a list of integers (or `default` (=`0`) for the empty list)

kk_integer_t kk_std_core_list_minimum(kk_std_core_types__list xs, kk_std_core_types__optional kkloc_default, kk_context_t* _ctx) { /* (xs : list<int>, default : ? int) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    if (kk_std_core_types__is_Optional(kkloc_default, _ctx)) {
      kk_box_t _box_x1208 = kkloc_default._cons._Optional.value;
      kk_integer_t _uniq_default_5643 = kk_integer_unbox(_box_x1208, _ctx);
      kk_integer_dup(_uniq_default_5643, _ctx);
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return _uniq_default_5643;
    }
    {
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return kk_integer_from_small(0);
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1925 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1209 = _con_x1925->head;
    kk_std_core_types__list xx = _con_x1925->tail;
    kk_integer_t x = kk_integer_unbox(_box_x1209, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_integer_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__optional_drop(kkloc_default, _ctx);
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      return x;
    }
    {
      return kk_std_core_list__lift_minimum_10351(xx, x, _ctx);
    }
  }
}
 
// lifted local: maximum, @spec-x10343
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10338, using:
// @uniq-f@10338 = std/core/int/max

kk_integer_t kk_std_core_list__lift_maximum_10352(kk_std_core_types__list _uniq_xs_10336, kk_integer_t _uniq_z_10337, kk_context_t* _ctx) { /* (list<int>, int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10336, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1926 = kk_std_core_types__as_Cons(_uniq_xs_10336, _ctx);
    kk_box_t _box_x1210 = _con_x1926->head;
    kk_std_core_types__list _uniq_xx_10341 = _con_x1926->tail;
    kk_integer_t _uniq_x_10340 = kk_integer_unbox(_box_x1210, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10336, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10336, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10340, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10341, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10336, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x1927 = kk_std_core_int_max(_uniq_z_10337, _uniq_x_10340, _ctx); /*int*/
      _uniq_xs_10336 = _uniq_xx_10341;
      _uniq_z_10337 = _x_x1927;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10337;
  }
}
 
// Returns the largest element of a list of integers (or `default` (=`0`) for the empty list)

kk_integer_t kk_std_core_list_maximum(kk_std_core_types__list xs, kk_std_core_types__optional kkloc_default, kk_context_t* _ctx) { /* (xs : list<int>, default : ? int) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    if (kk_std_core_types__is_Optional(kkloc_default, _ctx)) {
      kk_box_t _box_x1211 = kkloc_default._cons._Optional.value;
      kk_integer_t _uniq_default_5677 = kk_integer_unbox(_box_x1211, _ctx);
      kk_integer_dup(_uniq_default_5677, _ctx);
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return _uniq_default_5677;
    }
    {
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return kk_integer_from_small(0);
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1928 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1212 = _con_x1928->head;
    kk_std_core_types__list xx = _con_x1928->tail;
    kk_integer_t x = kk_integer_unbox(_box_x1212, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_integer_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__optional_drop(kkloc_default, _ctx);
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      return x;
    }
    {
      return kk_std_core_list__lift_maximum_10352(xx, x, _ctx);
    }
  }
}
 
// Join a list of strings with newlines

kk_string_t kk_std_core_list_unlines(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1932 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1213 = _con_x1932->head;
    kk_std_core_types__list _pat_1 = _con_x1932->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x1213);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return x;
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1933 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1214 = _con_x1933->head;
    kk_std_core_types__list _pat_3 = _con_x1933->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1934 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x1215 = _con_x1934->head;
      kk_std_core_types__list _pat_4 = _con_x1934->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x1935;
        kk_define_string_literal(, _s_x1936, 1, "\n", _ctx)
        _x_x1935 = kk_string_dup(_s_x1936, _ctx); /*string*/
        kk_string_t _x_x1937 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x1935,_x_x1937,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x1214);
          kk_string_t y = kk_string_unbox(_box_x1215);
          if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(xs, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(xs, _ctx);
          }
          return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
        }
      }
    }
  }
  {
    kk_vector_t _x_x1939 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<978>*/
    kk_string_t _x_x1940;
    kk_define_string_literal(, _s_x1941, 1, "\n", _ctx)
    _x_x1940 = kk_string_dup(_s_x1941, _ctx); /*string*/
    return kk_string_join_with(_x_x1939,_x_x1940,kk_context());
  }
}

// initialization
void kk_std_core_list__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_vector__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_list__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_vector__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
