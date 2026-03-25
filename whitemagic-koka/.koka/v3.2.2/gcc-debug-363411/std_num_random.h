#pragma once
#ifndef kk_std_num_random_H
#define kk_std_num_random_H
// Koka generated module: std/num/random, koka version: 3.2.2, platform: 64-bit
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
#include "std_num_int32.h"
#include "std_num_int64.h"
#include "std_num_float64.h"

// type declarations

// type std/num/random/random
struct kk_std_num_random__random_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_num_random__random;
struct kk_std_num_random__Hnd_random {
  struct kk_std_num_random__random_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause0 _fun_random_int32;
};
static inline kk_std_num_random__random kk_std_num_random__base_Hnd_random(struct kk_std_num_random__Hnd_random* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_num_random__random kk_std_num_random__new_Hnd_random(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause0 _fun_random_int32, kk_context_t* _ctx) {
  struct kk_std_num_random__Hnd_random* _con = kk_block_alloc_at_as(struct kk_std_num_random__Hnd_random, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_random_int32 = _fun_random_int32;
  return kk_std_num_random__base_Hnd_random(_con, _ctx);
}
static inline struct kk_std_num_random__Hnd_random* kk_std_num_random__as_Hnd_random(kk_std_num_random__random x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_num_random__Hnd_random*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_num_random__is_Hnd_random(kk_std_num_random__random x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_num_random__random kk_std_num_random__random_dup(kk_std_num_random__random _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_num_random__random_drop(kk_std_num_random__random _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_num_random__random_box(kk_std_num_random__random _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_num_random__random kk_std_num_random__random_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value type std/num/random/sfc
struct kk_std_num_random_Sfc {
  int32_t x;
  int32_t y;
  int32_t z;
  int32_t cnt;
};
typedef struct kk_std_num_random_Sfc kk_std_num_random__sfc;
static inline kk_std_num_random__sfc kk_std_num_random__new_Sfc(int32_t x, int32_t y, int32_t z, int32_t cnt, kk_context_t* _ctx) {
  kk_std_num_random__sfc _con;
  _con.x = x;
  _con.y = y;
  _con.z = z;
  _con.cnt = cnt;
  return _con;
}
static inline bool kk_std_num_random__is_Sfc(kk_std_num_random__sfc x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_num_random__sfc kk_std_num_random__sfc_dup(kk_std_num_random__sfc _x, kk_context_t* _ctx) {
  kk_skip_dup(_x.x, _ctx);
  kk_skip_dup(_x.y, _ctx);
  kk_skip_dup(_x.z, _ctx);
  kk_skip_dup(_x.cnt, _ctx);
  return _x;
}
static inline void kk_std_num_random__sfc_drop(kk_std_num_random__sfc _x, kk_context_t* _ctx) {
  kk_skip_drop(_x.x, _ctx);
  kk_skip_drop(_x.y, _ctx);
  kk_skip_drop(_x.z, _ctx);
  kk_skip_drop(_x.cnt, _ctx);
}
static inline kk_box_t kk_std_num_random__sfc_box(kk_std_num_random__sfc _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_num_random__sfc, _box, _x, 0 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_num_random__sfc kk_std_num_random__sfc_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_std_num_random__sfc _unbox;
  kk_valuetype_unbox(kk_std_num_random__sfc, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// value type std/num/random/sfc-result
struct kk_std_num_random_Sfc_result {
  int32_t rnd;
  kk_std_num_random__sfc rstate;
};
typedef struct kk_std_num_random_Sfc_result kk_std_num_random__sfc_result;
static inline kk_std_num_random__sfc_result kk_std_num_random__new_Sfc_result(int32_t rnd, kk_std_num_random__sfc rstate, kk_context_t* _ctx) {
  kk_std_num_random__sfc_result _con;
  _con.rnd = rnd;
  _con.rstate = rstate;
  return _con;
}
static inline bool kk_std_num_random__is_Sfc_result(kk_std_num_random__sfc_result x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_num_random__sfc_result kk_std_num_random__sfc_result_dup(kk_std_num_random__sfc_result _x, kk_context_t* _ctx) {
  kk_skip_dup(_x.rnd, _ctx);
  kk_std_num_random__sfc_dup(_x.rstate, _ctx);
  return _x;
}
static inline void kk_std_num_random__sfc_result_drop(kk_std_num_random__sfc_result _x, kk_context_t* _ctx) {
  kk_skip_drop(_x.rnd, _ctx);
  kk_std_num_random__sfc_drop(_x.rstate, _ctx);
}
static inline kk_box_t kk_std_num_random__sfc_result_box(kk_std_num_random__sfc_result _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_num_random__sfc_result, _box, _x, 0 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_num_random__sfc_result kk_std_num_random__sfc_result_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_std_num_random__sfc_result _unbox;
  kk_valuetype_unbox(kk_std_num_random__sfc_result, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// value declarations
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:random` type.

static inline kk_integer_t kk_std_num_random_random_fs__cfc(kk_std_num_random__random random, kk_context_t* _ctx) { /* forall<e,a> (random : random<e,a>) -> int */ 
  {
    struct kk_std_num_random__Hnd_random* _con_x177 = kk_std_num_random__as_Hnd_random(random, _ctx);
    kk_integer_t _x = _con_x177->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_std_num_random_random_fs__tag;

kk_box_t kk_std_num_random_random_fs__handle(kk_std_num_random__random hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : random<e,b>, ret : (res : a) -> e b, action : () -> <random|e> a) -> e b */ 
 
// select `random-int32` operation out of effect `:random`

static inline kk_std_core_hnd__clause0 kk_std_num_random_random_int32_fs__select(kk_std_num_random__random hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : random<e,a>) -> hnd/clause0<int32,random,e,a> */ 
  {
    struct kk_std_num_random__Hnd_random* _con_x181 = kk_std_num_random__as_Hnd_random(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_random_int32 = _con_x181->_fun_random_int32;
    return kk_std_core_hnd__clause0_dup(_fun_random_int32, _ctx);
  }
}
 
// Call the `fun random-int32` operation of the effect `:random`

static inline int32_t kk_std_num_random_random_int32(kk_context_t* _ctx) { /* () -> random int32 */ 
  kk_std_core_hnd__ev ev_10051 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/num/random/random>*/;
  kk_box_t _x_x182;
  {
    struct kk_std_core_hnd_Ev* _con_x183 = kk_std_core_hnd__as_Ev(ev_10051, _ctx);
    kk_box_t _box_x8 = _con_x183->hnd;
    int32_t m = _con_x183->marker;
    kk_std_num_random__random h = kk_std_num_random__random_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_std_num_random__random_dup(h, _ctx);
    {
      struct kk_std_num_random__Hnd_random* _con_x184 = kk_std_num_random__as_Hnd_random(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x184->_cfc;
      kk_std_core_hnd__clause0 _fun_random_int32 = _con_x184->_fun_random_int32;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_random_int32, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x11 = _fun_random_int32.clause;
        _x_x182 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x11, (_fun_unbox_x11, m, ev_10051, _ctx), _ctx); /*35*/
      }
    }
  }
  return kk_int32_unbox(_x_x182, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-random-int32` constructor field of the `:random` type.

static inline kk_std_core_hnd__clause0 kk_std_num_random_random_fs__fun_random_int32(kk_std_num_random__random random, kk_context_t* _ctx) { /* forall<e,a> (random : random<e,a>) -> hnd/clause0<int32,random,e,a> */ 
  {
    struct kk_std_num_random__Hnd_random* _con_x185 = kk_std_num_random__as_Hnd_random(random, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x185->_fun_random_int32;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `cnt` constructor field of the `:sfc` type.

static inline int32_t kk_std_num_random_sfc_fs_cnt(kk_std_num_random__sfc sfc, kk_context_t* _ctx) { /* (sfc : sfc) -> int32 */ 
  {
    int32_t _x = sfc.cnt;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `x` constructor field of the `:sfc` type.

static inline int32_t kk_std_num_random_sfc_fs_x(kk_std_num_random__sfc sfc, kk_context_t* _ctx) { /* (sfc : sfc) -> int32 */ 
  {
    int32_t _x = sfc.x;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `y` constructor field of the `:sfc` type.

static inline int32_t kk_std_num_random_sfc_fs_y(kk_std_num_random__sfc sfc, kk_context_t* _ctx) { /* (sfc : sfc) -> int32 */ 
  {
    int32_t _x = sfc.y;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `z` constructor field of the `:sfc` type.

static inline int32_t kk_std_num_random_sfc_fs_z(kk_std_num_random__sfc sfc, kk_context_t* _ctx) { /* (sfc : sfc) -> int32 */ 
  {
    int32_t _x = sfc.z;
    return _x;
  }
}

kk_std_num_random__sfc kk_std_num_random_sfc_fs__copy(kk_std_num_random__sfc _this, kk_std_core_types__optional x, kk_std_core_types__optional y, kk_std_core_types__optional z, kk_std_core_types__optional cnt, kk_context_t* _ctx); /* (sfc, x : ? int32, y : ? int32, z : ? int32, cnt : ? int32) -> sfc */ 
 
// Automatically generated. Retrieves the `rnd` constructor field of the `:sfc-result` type.

static inline int32_t kk_std_num_random_sfc_result_fs_rnd(kk_std_num_random__sfc_result _this, kk_context_t* _ctx) { /* (sfc-result) -> int32 */ 
  {
    kk_std_num_random__sfc _pat_0 = _this.rstate;
    int32_t _x = _this.rnd;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `rstate` constructor field of the `:sfc-result` type.

static inline kk_std_num_random__sfc kk_std_num_random_sfc_result_fs_rstate(kk_std_num_random__sfc_result _this, kk_context_t* _ctx) { /* (sfc-result) -> sfc */ 
  {
    kk_std_num_random__sfc _x = _this.rstate;
    return _x;
  }
}

kk_std_num_random__sfc_result kk_std_num_random_sfc_result_fs__copy(kk_std_num_random__sfc_result _this, kk_std_core_types__optional rnd, kk_std_core_types__optional rstate, kk_context_t* _ctx); /* (sfc-result, rnd : ? int32, rstate : ? sfc) -> sfc-result */ 

int32_t kk_std_num_random_srandom_int32(kk_context_t* _ctx); /* () -> ndet int32 */ 
 
// Pick random numbers from a the best strong random source in the OS.
// (e.g. like `/dev/urandom`, `arc4random` etc.). Use `srandom-is-strong` to test if the
// numbers are indeed based on a strong random source.


// lift anonymous function
struct kk_std_num_random_strong_random_fun192__t {
  struct kk_function_s _base;
};
extern int32_t kk_std_num_random_strong_random_fun192(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_num_random_new_strong_random_fun192(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_strong_random_fun192, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_random_strong_random_fun195__t {
  struct kk_function_s _base;
  kk_function_t _b_x20_21;
};
extern kk_box_t kk_std_num_random_strong_random_fun195(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_num_random_new_strong_random_fun195(kk_function_t _b_x20_21, kk_context_t* _ctx) {
  struct kk_std_num_random_strong_random_fun195__t* _self = kk_function_alloc_as(struct kk_std_num_random_strong_random_fun195__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_random_strong_random_fun195, kk_context());
  _self->_b_x20_21 = _b_x20_21;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_num_random_strong_random_fun197__t {
  struct kk_function_s _base;
};
extern kk_box_t kk_std_num_random_strong_random_fun197(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static inline kk_function_t kk_std_num_random_new_strong_random_fun197(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_strong_random_fun197, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}


static inline kk_box_t kk_std_num_random_strong_random(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <random,ndet|e> a) -> <ndet|e> a */ 
  kk_function_t _b_x20_21 = kk_std_num_random_new_strong_random_fun192(_ctx); /*() -> ndet int32*/;
  kk_std_num_random__random _x_x193;
  kk_std_core_hnd__clause0 _x_x194 = kk_std_core_hnd_clause_tail0(kk_std_num_random_new_strong_random_fun195(_b_x20_21, _ctx), _ctx); /*hnd/clause0<6948,6947,6945,6946>*/
  _x_x193 = kk_std_num_random__new_Hnd_random(kk_reuse_null, 0, kk_integer_from_small(1), _x_x194, _ctx); /*std/num/random/random<5,6>*/
  return kk_std_num_random_random_fs__handle(_x_x193, kk_std_num_random_new_strong_random_fun197(_ctx), action, _ctx);
}


// lift anonymous function
struct kk_std_num_random__default_random_fun198__t {
  struct kk_function_s _base;
};
extern int32_t kk_std_num_random__default_random_fun198(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_num_random__new_default_random_fun198(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random__default_random_fun198, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_random__default_random_fun201__t {
  struct kk_function_s _base;
  kk_function_t _b_x22_23;
};
extern kk_box_t kk_std_num_random__default_random_fun201(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_num_random__new_default_random_fun201(kk_function_t _b_x22_23, kk_context_t* _ctx) {
  struct kk_std_num_random__default_random_fun201__t* _self = kk_function_alloc_as(struct kk_std_num_random__default_random_fun201__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_random__default_random_fun201, kk_context());
  _self->_b_x22_23 = _b_x22_23;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_num_random__default_random_fun203__t {
  struct kk_function_s _base;
};
extern kk_box_t kk_std_num_random__default_random_fun203(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static inline kk_function_t kk_std_num_random__new_default_random_fun203(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random__default_random_fun203, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}


static inline kk_box_t kk_std_num_random__default_random(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <random,ndet|e> a) -> <ndet|e> a */ 
  kk_function_t _b_x22_23 = kk_std_num_random__new_default_random_fun198(_ctx); /*() -> ndet int32*/;
  kk_std_num_random__random _x_x199;
  kk_std_core_hnd__clause0 _x_x200 = kk_std_core_hnd_clause_tail0(kk_std_num_random__new_default_random_fun201(_b_x22_23, _ctx), _ctx); /*hnd/clause0<6948,6947,6945,6946>*/
  _x_x199 = kk_std_num_random__new_Hnd_random(kk_reuse_null, 0, kk_integer_from_small(1), _x_x200, _ctx); /*std/num/random/random<5,6>*/
  return kk_std_num_random_random_fs__handle(_x_x199, kk_std_num_random__new_default_random_fun203(_ctx), action, _ctx);
}

kk_std_num_random__sfc_result kk_std_num_random_sfc_step(kk_std_num_random__sfc sfc, kk_context_t* _ctx); /* (sfc : sfc) -> sfc-result */ 

kk_std_num_random__sfc kk_std_num_random_sfc_init32(int32_t seed1, int32_t seed2, kk_context_t* _ctx); /* (seed1 : int32, seed2 : int32) -> sfc */ 

kk_std_num_random__sfc kk_std_num_random_sfc_init(kk_integer_t seed, kk_context_t* _ctx); /* (seed : int) -> sfc */ 
 
// monadic lift

static inline int32_t kk_std_num_random__mlift_pseudo_random_10043(kk_std_num_random__sfc_result sfc, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,e> (sfc : sfc-result, wild_ : ()) -> <local<h>|e> int32 */ 
  {
    kk_std_num_random__sfc _pat_0_0 = sfc.rstate;
    int32_t _x_0 = sfc.rnd;
    return _x_0;
  }
}

int32_t kk_std_num_random__mlift_pseudo_random_10044(kk_ref_t s, kk_std_num_random__sfc _y_x10023, kk_context_t* _ctx); /* forall<h,e> (s : local-var<h,sfc>, sfc) -> <local<h>|e> int32 */ 

kk_box_t kk_std_num_random_pseudo_random(kk_integer_t seed, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (seed : int, action : () -> <random|e> a) -> e a */ 
 
// monadic lift

static inline bool kk_std_num_random__mlift_random_bool_10045(int32_t _y_x10029, kk_context_t* _ctx) { /* (int32) -> random bool */ 
  return (_y_x10029 >= ((KK_I32(0))));
}

bool kk_std_num_random_random_bool(kk_context_t* _ctx); /* () -> random bool */ 
 
// monadic lift

static inline kk_integer_t kk_std_num_random__mlift_random_int_10046(int32_t _y_x10030, kk_context_t* _ctx) { /* (int32) -> random int */ 
  return kk_integer_from_int(_y_x10030,kk_context());
}

kk_integer_t kk_std_num_random_random_int(kk_context_t* _ctx); /* () -> random int */ 
 
// monadic lift

static inline int64_t kk_std_num_random__mlift_random_int64_10047(int32_t _y_x10031, int32_t _y_x10032, kk_context_t* _ctx) { /* (int32, int32) -> random int64 */ 
  return kk_int64_hi_lo(_y_x10031,_y_x10032);
}

int64_t kk_std_num_random__mlift_random_int64_10048(int32_t _y_x10031, kk_context_t* _ctx); /* (int32) -> random int64 */ 

int64_t kk_std_num_random_random_int64(kk_context_t* _ctx); /* () -> random int64 */ 

double kk_std_num_random__mlift_random_float64_10049(int64_t _y_x10033, kk_context_t* _ctx); /* (int64) -> random float64 */ 

double kk_std_num_random_random_float64(kk_context_t* _ctx); /* () -> random float64 */ 
 
// Return a strong random boolean

static inline bool kk_std_num_random_srandom_bool(kk_context_t* _ctx) { /* () -> ndet bool */ 
  int32_t _x_x308 = kk_std_num_random_srandom_int32(_ctx); /*int32*/
  return (_x_x308 >= ((KK_I32(0))));
}

kk_box_t kk_std_num_random_choose(kk_box_t x, kk_box_t y, kk_context_t* _ctx); /* forall<a> (x : a, y : a) -> ndet a */ 
 
// Return a strong random integer in the range [-2^31^, 2^31^).

static inline kk_integer_t kk_std_num_random_srandom_int(kk_context_t* _ctx) { /* () -> ndet int */ 
  int32_t _x_x310 = kk_std_num_random_srandom_int32(_ctx); /*int32*/
  return kk_integer_from_int(_x_x310,kk_context());
}

double kk_std_num_random_srandom_float64(kk_context_t* _ctx); /* () -> ndet float64 */ 

bool kk_std_num_random_srandom_is_strong(kk_context_t* _ctx); /* () -> ndet bool */ 

int32_t kk_std_num_random_srandom_int32_range(int32_t lo, int32_t hi, kk_context_t* _ctx); /* (lo : int32, hi : int32) -> ndet int32 */ 

double kk_std_num_random_srandom_float64_range(double lo, double hi, kk_context_t* _ctx); /* (lo : float64, hi : float64) -> ndet float64 */ 

void kk_std_num_random__init(kk_context_t* _ctx);


void kk_std_num_random__done(kk_context_t* _ctx);

#endif // header
