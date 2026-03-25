// Koka generated module: std/num/random, koka version: 3.2.2, platform: 64-bit
#include "std_num_random.h"
 
// runtime tag for the effect `:random`

kk_std_core_hnd__htag kk_std_num_random_random_fs__tag;
 
// handler for the effect `:random`

kk_box_t kk_std_num_random_random_fs__handle(kk_std_num_random__random hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : random<e,b>, ret : (res : a) -> e b, action : () -> <random|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x180 = kk_std_core_hnd__htag_dup(kk_std_num_random_random_fs__tag, _ctx); /*hnd/htag<std/num/random/random>*/
  return kk_std_core_hnd__hhandle(_x_x180, kk_std_num_random__random_box(hnd, _ctx), ret, action, _ctx);
}

kk_std_num_random__sfc kk_std_num_random_sfc_fs__copy(kk_std_num_random__sfc _this, kk_std_core_types__optional x, kk_std_core_types__optional y, kk_std_core_types__optional z, kk_std_core_types__optional cnt, kk_context_t* _ctx) { /* (sfc, x : ? int32, y : ? int32, z : ? int32, cnt : ? int32) -> sfc */ 
  int32_t _x_x186;
  if (kk_std_core_types__is_Optional(x, _ctx)) {
    kk_box_t _box_x14 = x._cons._Optional.value;
    int32_t _uniq_x_319 = kk_int32_unbox(_box_x14, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(x, _ctx);
    _x_x186 = _uniq_x_319; /*int32*/
  }
  else {
    kk_std_core_types__optional_drop(x, _ctx);
    {
      int32_t _x = _this.x;
      _x_x186 = _x; /*int32*/
    }
  }
  int32_t _x_x187;
  if (kk_std_core_types__is_Optional(y, _ctx)) {
    kk_box_t _box_x15 = y._cons._Optional.value;
    int32_t _uniq_y_327 = kk_int32_unbox(_box_x15, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(y, _ctx);
    _x_x187 = _uniq_y_327; /*int32*/
  }
  else {
    kk_std_core_types__optional_drop(y, _ctx);
    {
      int32_t _x_0 = _this.y;
      _x_x187 = _x_0; /*int32*/
    }
  }
  int32_t _x_x188;
  if (kk_std_core_types__is_Optional(z, _ctx)) {
    kk_box_t _box_x16 = z._cons._Optional.value;
    int32_t _uniq_z_335 = kk_int32_unbox(_box_x16, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(z, _ctx);
    _x_x188 = _uniq_z_335; /*int32*/
  }
  else {
    kk_std_core_types__optional_drop(z, _ctx);
    {
      int32_t _x_1 = _this.z;
      _x_x188 = _x_1; /*int32*/
    }
  }
  int32_t _x_x189;
  if (kk_std_core_types__is_Optional(cnt, _ctx)) {
    kk_box_t _box_x17 = cnt._cons._Optional.value;
    int32_t _uniq_cnt_343 = kk_int32_unbox(_box_x17, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(cnt, _ctx);
    _x_x189 = _uniq_cnt_343; /*int32*/
  }
  else {
    kk_std_core_types__optional_drop(cnt, _ctx);
    {
      int32_t _x_2 = _this.cnt;
      _x_x189 = _x_2; /*int32*/
    }
  }
  return kk_std_num_random__new_Sfc(_x_x186, _x_x187, _x_x188, _x_x189, _ctx);
}

kk_std_num_random__sfc_result kk_std_num_random_sfc_result_fs__copy(kk_std_num_random__sfc_result _this, kk_std_core_types__optional rnd, kk_std_core_types__optional rstate, kk_context_t* _ctx) { /* (sfc-result, rnd : ? int32, rstate : ? sfc) -> sfc-result */ 
  int32_t _x_x190;
  if (kk_std_core_types__is_Optional(rnd, _ctx)) {
    kk_box_t _box_x18 = rnd._cons._Optional.value;
    int32_t _uniq_rnd_378 = kk_int32_unbox(_box_x18, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(rnd, _ctx);
    _x_x190 = _uniq_rnd_378; /*int32*/
  }
  else {
    kk_std_core_types__optional_drop(rnd, _ctx);
    {
      kk_std_num_random__sfc _pat_0_0 = _this.rstate;
      int32_t _x = _this.rnd;
      _x_x190 = _x; /*int32*/
    }
  }
  kk_std_num_random__sfc _x_x191;
  if (kk_std_core_types__is_Optional(rstate, _ctx)) {
    kk_box_t _box_x19 = rstate._cons._Optional.value;
    kk_std_num_random__sfc _uniq_rstate_386 = kk_std_num_random__sfc_unbox(_box_x19, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(rstate, _ctx);
    _x_x191 = _uniq_rstate_386; /*std/num/random/sfc*/
  }
  else {
    kk_std_core_types__optional_drop(rstate, _ctx);
    {
      kk_std_num_random__sfc _x_0 = _this.rstate;
      _x_x191 = _x_0; /*std/num/random/sfc*/
    }
  }
  return kk_std_num_random__new_Sfc_result(_x_x190, _x_x191, _ctx);
}
 
// Return a strong random `:int32`

int32_t kk_std_num_random_srandom_int32(kk_context_t* _ctx) { /* () -> ndet int32 */ 
  return (int32_t)kk_srandom_uint32(kk_context());
}
extern int32_t kk_std_num_random_strong_random_fun192(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_random_srandom_int32(_ctx);
}
extern kk_box_t kk_std_num_random_strong_random_fun195(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_num_random_strong_random_fun195__t* _self = kk_function_as(struct kk_std_num_random_strong_random_fun195__t*, _fself, _ctx);
  kk_function_t _b_x20_21 = _self->_b_x20_21; /* () -> ndet int32 */
  kk_drop_match(_self, {kk_function_dup(_b_x20_21, _ctx);}, {}, _ctx)
  int32_t _x_x196 = kk_function_call(int32_t, (kk_function_t, kk_context_t*), _b_x20_21, (_b_x20_21, _ctx), _ctx); /*int32*/
  return kk_int32_box(_x_x196, _ctx);
}
extern kk_box_t kk_std_num_random_strong_random_fun197(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}
extern int32_t kk_std_num_random__default_random_fun198(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_random_srandom_int32(_ctx);
}
extern kk_box_t kk_std_num_random__default_random_fun201(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_num_random__default_random_fun201__t* _self = kk_function_as(struct kk_std_num_random__default_random_fun201__t*, _fself, _ctx);
  kk_function_t _b_x22_23 = _self->_b_x22_23; /* () -> ndet int32 */
  kk_drop_match(_self, {kk_function_dup(_b_x22_23, _ctx);}, {}, _ctx)
  int32_t _x_x202 = kk_function_call(int32_t, (kk_function_t, kk_context_t*), _b_x22_23, (_b_x22_23, _ctx), _ctx); /*int32*/
  return kk_int32_box(_x_x202, _ctx);
}
extern kk_box_t kk_std_num_random__default_random_fun203(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}

kk_std_num_random__sfc_result kk_std_num_random_sfc_step(kk_std_num_random__sfc sfc, kk_context_t* _ctx) { /* (sfc : sfc) -> sfc-result */ 
  {
    int32_t x = sfc.x;
    int32_t y = sfc.y;
    int32_t z = sfc.z;
    int32_t cnt = sfc.cnt;
    int32_t res;
    int32_t _x_x204 = (int32_t)((uint32_t)x + (uint32_t)y); /*int32*/
    res = (int32_t)((uint32_t)_x_x204 + (uint32_t)cnt); /*int32*/
    int32_t y_0_10007 = (int32_t)kk_shr32(y,((KK_I32(9)))); /*int32*/;
    kk_std_num_random__sfc _x_x205;
    int32_t _x_x206 = (y ^ y_0_10007); /*int32*/
    int32_t _x_x207;
    int32_t _x_x208 = kk_shl32(z,((KK_I32(3)))); /*int32*/
    _x_x207 = (int32_t)((uint32_t)z + (uint32_t)_x_x208); /*int32*/
    int32_t _x_x209;
    int32_t _x_x210 = (int32_t)kk_bits_rotl32(z,((KK_I32(21)))); /*int32*/
    _x_x209 = (int32_t)((uint32_t)_x_x210 + (uint32_t)res); /*int32*/
    int32_t _x_x211 = (int32_t)((uint32_t)cnt + (uint32_t)((KK_I32(1)))); /*int32*/
    _x_x205 = kk_std_num_random__new_Sfc(_x_x206, _x_x207, _x_x209, _x_x211, _ctx); /*std/num/random/sfc*/
    return kk_std_num_random__new_Sfc_result(res, _x_x205, _ctx);
  }
}


// lift anonymous function
struct kk_std_num_random_sfc_init32_fun213__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_sfc_init32_fun213(kk_function_t _fself, int32_t _b_x27, kk_box_t _b_x28, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_sfc_init32_fun213(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_sfc_init32_fun213, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random_sfc_init32_fun213(kk_function_t _fself, int32_t _b_x27, kk_box_t _b_x28, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int32_t ___wildcard_x57__34_32 = _b_x27; /*int32*/;
  kk_std_num_random__sfc s_33 = kk_std_num_random__sfc_unbox(_b_x28, KK_OWNED, _ctx); /*std/num/random/sfc*/;
  kk_std_num_random__sfc_result _this_10014 = kk_std_num_random_sfc_step(s_33, _ctx); /*std/num/random/sfc-result*/;
  kk_std_num_random__sfc _x_x214;
  {
    kk_std_num_random__sfc _x = _this_10014.rstate;
    _x_x214 = _x; /*std/num/random/sfc*/
  }
  return kk_std_num_random__sfc_box(_x_x214, _ctx);
}

kk_std_num_random__sfc kk_std_num_random_sfc_init32(int32_t seed1, int32_t seed2, kk_context_t* _ctx) { /* (seed1 : int32, seed2 : int32) -> sfc */ 
  kk_std_num_random__sfc sfc0 = kk_std_num_random__new_Sfc((KK_I32(0)), seed1, seed2, (KK_I32(1)), _ctx); /*std/num/random/sfc*/;
  int32_t _b_x24_29 = (KK_I32(12)); /*int32*/;
  kk_box_t _x_x212;
  kk_function_t _brw_x169 = kk_std_num_random_new_sfc_init32_fun213(_ctx); /*(int32, 3415) -> 3416 3415*/;
  kk_box_t _brw_x170 = kk_std_num_int32_fold_int32(_b_x24_29, kk_std_num_random__sfc_box(sfc0, _ctx), _brw_x169, _ctx); /*3415*/;
  kk_function_drop(_brw_x169, _ctx);
  _x_x212 = _brw_x170; /*3415*/
  return kk_std_num_random__sfc_unbox(_x_x212, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_num_random_sfc_init_fun218__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_sfc_init_fun218(kk_function_t _fself, int32_t _b_x37, kk_box_t _b_x38, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_sfc_init_fun218(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_sfc_init_fun218, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random_sfc_init_fun218(kk_function_t _fself, int32_t _b_x37, kk_box_t _b_x38, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int32_t ___wildcard_x57__34_42 = _b_x37; /*int32*/;
  kk_std_num_random__sfc s_43 = kk_std_num_random__sfc_unbox(_b_x38, KK_OWNED, _ctx); /*std/num/random/sfc*/;
  kk_std_num_random__sfc_result _this_10017 = kk_std_num_random_sfc_step(s_43, _ctx); /*std/num/random/sfc-result*/;
  kk_std_num_random__sfc _x_x219;
  {
    kk_std_num_random__sfc _x = _this_10017.rstate;
    _x_x219 = _x; /*std/num/random/sfc*/
  }
  return kk_std_num_random__sfc_box(_x_x219, _ctx);
}

kk_std_num_random__sfc kk_std_num_random_sfc_init(kk_integer_t seed, kk_context_t* _ctx) { /* (seed : int) -> sfc */ 
  int32_t seed1_10015;
  kk_integer_t _x_x215 = kk_integer_dup(seed, _ctx); /*int*/
  seed1_10015 = kk_integer_clamp32(_x_x215,kk_context()); /*int32*/
  int32_t seed2_10016;
  kk_integer_t _x_x216 = kk_integer_div(seed,(kk_integer_from_str("4294967296", _ctx)),kk_context()); /*int*/
  seed2_10016 = kk_integer_clamp32(_x_x216,kk_context()); /*int32*/
  kk_std_num_random__sfc sfc0 = kk_std_num_random__new_Sfc((KK_I32(0)), seed1_10015, seed2_10016, (KK_I32(1)), _ctx); /*std/num/random/sfc*/;
  int32_t _b_x34_39 = (KK_I32(12)); /*int32*/;
  kk_box_t _x_x217;
  kk_function_t _brw_x167 = kk_std_num_random_new_sfc_init_fun218(_ctx); /*(int32, 3415) -> 3416 3415*/;
  kk_box_t _brw_x168 = kk_std_num_int32_fold_int32(_b_x34_39, kk_std_num_random__sfc_box(sfc0, _ctx), _brw_x167, _ctx); /*3415*/;
  kk_function_drop(_brw_x167, _ctx);
  _x_x217 = _brw_x168; /*3415*/
  return kk_std_num_random__sfc_unbox(_x_x217, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_random__mlift_pseudo_random_10044_fun223__t {
  struct kk_function_s _base;
  kk_std_num_random__sfc_result sfc;
};
static kk_box_t kk_std_num_random__mlift_pseudo_random_10044_fun223(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx);
static kk_function_t kk_std_num_random__new_mlift_pseudo_random_10044_fun223(kk_std_num_random__sfc_result sfc, kk_context_t* _ctx) {
  struct kk_std_num_random__mlift_pseudo_random_10044_fun223__t* _self = kk_function_alloc_as(struct kk_std_num_random__mlift_pseudo_random_10044_fun223__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_random__mlift_pseudo_random_10044_fun223, kk_context());
  _self->sfc = sfc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_random__mlift_pseudo_random_10044_fun223(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx) {
  struct kk_std_num_random__mlift_pseudo_random_10044_fun223__t* _self = kk_function_as(struct kk_std_num_random__mlift_pseudo_random_10044_fun223__t*, _fself, _ctx);
  kk_std_num_random__sfc_result sfc = _self->sfc; /* std/num/random/sfc-result */
  kk_drop_match(_self, {kk_std_num_random__sfc_result_dup(sfc, _ctx);}, {}, _ctx)
  kk_unit_t wild___51 = kk_Unit;
  kk_unit_unbox(_b_x49);
  int32_t _x_x224;
  {
    kk_std_num_random__sfc _pat_0_0_0 = sfc.rstate;
    int32_t _x_0 = sfc.rnd;
    _x_x224 = _x_0; /*int32*/
  }
  return kk_int32_box(_x_x224, _ctx);
}

int32_t kk_std_num_random__mlift_pseudo_random_10044(kk_ref_t s, kk_std_num_random__sfc _y_x10023, kk_context_t* _ctx) { /* forall<h,e> (s : local-var<h,sfc>, sfc) -> <local<h>|e> int32 */ 
  kk_std_num_random__sfc_result sfc = kk_std_num_random_sfc_step(_y_x10023, _ctx); /*std/num/random/sfc-result*/;
  kk_unit_t x_10054 = kk_Unit;
  kk_unit_t _brw_x166 = kk_Unit;
  kk_box_t _x_x220;
  kk_std_num_random__sfc _x_x221;
  {
    kk_std_num_random__sfc _x = sfc.rstate;
    _x_x221 = _x; /*std/num/random/sfc*/
  }
  _x_x220 = kk_std_num_random__sfc_box(_x_x221, _ctx); /*284*/
  kk_ref_set_borrow(s,_x_x220,kk_context());
  kk_ref_drop(s, _ctx);
  _brw_x166;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x222 = kk_std_core_hnd_yield_extend(kk_std_num_random__new_mlift_pseudo_random_10044_fun223(sfc, _ctx), _ctx); /*2419*/
    return kk_int32_unbox(_x_x222, KK_OWNED, _ctx);
  }
  {
    kk_std_num_random__sfc _pat_0_0_0_0 = sfc.rstate;
    int32_t _x_0_0 = sfc.rnd;
    return _x_0_0;
  }
}
 
// Use pseudo random numbers given some initial `seed`. At most
// 64-bits of the initial seed are used. Do not use this for
// cryptographic applications (use `strong-random` instead).
// Uses _sfc32_ by Chris Doty-Humphrey which is a fast random
// number generator with a 128-bit internal state which
// passes PractRand and BigCrush. The worst case minimum cycle
// is 2^32^, where a potential cycle of 2^48^ has a chance
// of 2^-80^.


// lift anonymous function
struct kk_std_num_random_pseudo_random_fun228__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_num_random_pseudo_random_fun228(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_pseudo_random_fun228(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_num_random_pseudo_random_fun228__t* _self = kk_function_alloc_as(struct kk_std_num_random_pseudo_random_fun228__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_random_pseudo_random_fun228, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_num_random_pseudo_random_fun233__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_num_random_pseudo_random_fun233(kk_function_t _fself, kk_box_t _b_x59, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_pseudo_random_fun233(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_num_random_pseudo_random_fun233__t* _self = kk_function_alloc_as(struct kk_std_num_random_pseudo_random_fun233__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_random_pseudo_random_fun233, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_random_pseudo_random_fun233(kk_function_t _fself, kk_box_t _b_x59, kk_context_t* _ctx) {
  struct kk_std_num_random_pseudo_random_fun233__t* _self = kk_function_as(struct kk_std_num_random_pseudo_random_fun233__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<803,std/num/random/sfc> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  int32_t _x_x234;
  kk_std_num_random__sfc _x_x235 = kk_std_num_random__sfc_unbox(_b_x59, KK_OWNED, _ctx); /*std/num/random/sfc*/
  _x_x234 = kk_std_num_random__mlift_pseudo_random_10044(loc, _x_x235, _ctx); /*int32*/
  return kk_int32_box(_x_x234, _ctx);
}
static kk_box_t kk_std_num_random_pseudo_random_fun228(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_num_random_pseudo_random_fun228__t* _self = kk_function_as(struct kk_std_num_random_pseudo_random_fun228__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<803,std/num/random/sfc> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_std_num_random__sfc x_10060;
  kk_box_t _x_x229;
  kk_ref_t _x_x230 = kk_ref_dup(loc, _ctx); /*local-var<803,std/num/random/sfc>*/
  _x_x229 = kk_ref_get(_x_x230,kk_context()); /*298*/
  x_10060 = kk_std_num_random__sfc_unbox(_x_x229, KK_OWNED, _ctx); /*std/num/random/sfc*/
  int32_t _x_x231;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x232 = kk_std_core_hnd_yield_extend(kk_std_num_random_new_pseudo_random_fun233(loc, _ctx), _ctx); /*2419*/
    _x_x231 = kk_int32_unbox(_x_x232, KK_OWNED, _ctx); /*int32*/
  }
  else {
    _x_x231 = kk_std_num_random__mlift_pseudo_random_10044(loc, x_10060, _ctx); /*int32*/
  }
  return kk_int32_box(_x_x231, _ctx);
}


// lift anonymous function
struct kk_std_num_random_pseudo_random_fun236__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_pseudo_random_fun236(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_pseudo_random_fun236(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_pseudo_random_fun236, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random_pseudo_random_fun236(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}

kk_box_t kk_std_num_random_pseudo_random(kk_integer_t seed, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (seed : int, action : () -> <random|e> a) -> e a */ 
  kk_std_num_random__sfc init_10058 = kk_std_num_random_sfc_init(seed, _ctx); /*std/num/random/sfc*/;
  kk_ref_t loc = kk_ref_alloc((kk_std_num_random__sfc_box(init_10058, _ctx)),kk_context()); /*local-var<803,std/num/random/sfc>*/;
  kk_box_t res;
  kk_std_num_random__random _x_x225;
  kk_std_core_hnd__clause0 _x_x226;
  kk_function_t _x_x227;
  kk_ref_dup(loc, _ctx);
  _x_x227 = kk_std_num_random_new_pseudo_random_fun228(loc, _ctx); /*() -> 6945 6948*/
  _x_x226 = kk_std_core_hnd_clause_tail0(_x_x227, _ctx); /*hnd/clause0<6948,6947,6945,6946>*/
  _x_x225 = kk_std_num_random__new_Hnd_random(kk_reuse_null, 0, kk_integer_from_small(1), _x_x226, _ctx); /*std/num/random/random<5,6>*/
  res = kk_std_num_random_random_fs__handle(_x_x225, kk_std_num_random_new_pseudo_random_fun236(_ctx), action, _ctx); /*813*/
  return kk_std_core_hnd_prompt_local_var(loc, res, _ctx);
}
 
// Return a random boolean


// lift anonymous function
struct kk_std_num_random_random_bool_fun241__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_random_bool_fun241(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_bool_fun241(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_random_bool_fun241, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random_random_bool_fun241(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x242;
  int32_t _x_x243 = kk_int32_unbox(_b_x71, KK_OWNED, _ctx); /*int32*/
  _x_x242 = kk_std_num_random__mlift_random_bool_10045(_x_x243, _ctx); /*bool*/
  return kk_bool_box(_x_x242);
}

bool kk_std_num_random_random_bool(kk_context_t* _ctx) { /* () -> random bool */ 
  kk_std_core_hnd__ev ev_10066 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/num/random/random>*/;
  int32_t x_10063;
  kk_box_t _x_x237;
  {
    struct kk_std_core_hnd_Ev* _con_x238 = kk_std_core_hnd__as_Ev(ev_10066, _ctx);
    kk_box_t _box_x64 = _con_x238->hnd;
    int32_t m = _con_x238->marker;
    kk_std_num_random__random h = kk_std_num_random__random_unbox(_box_x64, KK_BORROWED, _ctx);
    kk_std_num_random__random_dup(h, _ctx);
    {
      struct kk_std_num_random__Hnd_random* _con_x239 = kk_std_num_random__as_Hnd_random(h, _ctx);
      kk_integer_t _pat_0 = _con_x239->_cfc;
      kk_std_core_hnd__clause0 _fun_random_int32 = _con_x239->_fun_random_int32;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_random_int32, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x67 = _fun_random_int32.clause;
        _x_x237 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x67, (_fun_unbox_x67, m, ev_10066, _ctx), _ctx); /*35*/
      }
    }
  }
  x_10063 = kk_int32_unbox(_x_x237, KK_OWNED, _ctx); /*int32*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x240 = kk_std_core_hnd_yield_extend(kk_std_num_random_new_random_bool_fun241(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x240);
  }
  {
    return (x_10063 >= ((KK_I32(0))));
  }
}
 
// Return a random integer in the range [-2^31^, 2^31^).


// lift anonymous function
struct kk_std_num_random_random_int_fun248__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_random_int_fun248(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_int_fun248(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_random_int_fun248, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random_random_int_fun248(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x249;
  int32_t _x_x250 = kk_int32_unbox(_b_x80, KK_OWNED, _ctx); /*int32*/
  _x_x249 = kk_std_num_random__mlift_random_int_10046(_x_x250, _ctx); /*int*/
  return kk_integer_box(_x_x249, _ctx);
}

kk_integer_t kk_std_num_random_random_int(kk_context_t* _ctx) { /* () -> random int */ 
  kk_std_core_hnd__ev ev_10071 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/num/random/random>*/;
  int32_t x_10068;
  kk_box_t _x_x244;
  {
    struct kk_std_core_hnd_Ev* _con_x245 = kk_std_core_hnd__as_Ev(ev_10071, _ctx);
    kk_box_t _box_x73 = _con_x245->hnd;
    int32_t m = _con_x245->marker;
    kk_std_num_random__random h = kk_std_num_random__random_unbox(_box_x73, KK_BORROWED, _ctx);
    kk_std_num_random__random_dup(h, _ctx);
    {
      struct kk_std_num_random__Hnd_random* _con_x246 = kk_std_num_random__as_Hnd_random(h, _ctx);
      kk_integer_t _pat_0 = _con_x246->_cfc;
      kk_std_core_hnd__clause0 _fun_random_int32 = _con_x246->_fun_random_int32;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_random_int32, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x76 = _fun_random_int32.clause;
        _x_x244 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x76, (_fun_unbox_x76, m, ev_10071, _ctx), _ctx); /*35*/
      }
    }
  }
  x_10068 = kk_int32_unbox(_x_x244, KK_OWNED, _ctx); /*int32*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x247 = kk_std_core_hnd_yield_extend(kk_std_num_random_new_random_int_fun248(_ctx), _ctx); /*2419*/
    return kk_integer_unbox(_x_x247, _ctx);
  }
  {
    return kk_integer_from_int(x_10068,kk_context());
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_random__mlift_random_int64_10048_fun255__t {
  struct kk_function_s _base;
  int32_t _y_x10031;
};
static kk_box_t kk_std_num_random__mlift_random_int64_10048_fun255(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx);
static kk_function_t kk_std_num_random__new_mlift_random_int64_10048_fun255(int32_t _y_x10031, kk_context_t* _ctx) {
  struct kk_std_num_random__mlift_random_int64_10048_fun255__t* _self = kk_function_alloc_as(struct kk_std_num_random__mlift_random_int64_10048_fun255__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_random__mlift_random_int64_10048_fun255, kk_context());
  _self->_y_x10031 = _y_x10031;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_random__mlift_random_int64_10048_fun255(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx) {
  struct kk_std_num_random__mlift_random_int64_10048_fun255__t* _self = kk_function_as(struct kk_std_num_random__mlift_random_int64_10048_fun255__t*, _fself, _ctx);
  int32_t _y_x10031 = _self->_y_x10031; /* int32 */
  kk_drop_match(_self, {kk_skip_dup(_y_x10031, _ctx);}, {}, _ctx)
  int32_t _y_x10032_91 = kk_int32_unbox(_b_x89, KK_OWNED, _ctx); /*int32*/;
  int64_t _x_x256 = kk_int64_hi_lo(_y_x10031,_y_x10032_91); /*int64*/
  return kk_int64_box(_x_x256, _ctx);
}

int64_t kk_std_num_random__mlift_random_int64_10048(int32_t _y_x10031, kk_context_t* _ctx) { /* (int32) -> random int64 */ 
  kk_std_core_hnd__ev ev_10075 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/num/random/random>*/;
  int32_t x_10073;
  kk_box_t _x_x251;
  {
    struct kk_std_core_hnd_Ev* _con_x252 = kk_std_core_hnd__as_Ev(ev_10075, _ctx);
    kk_box_t _box_x82 = _con_x252->hnd;
    int32_t m = _con_x252->marker;
    kk_std_num_random__random h = kk_std_num_random__random_unbox(_box_x82, KK_BORROWED, _ctx);
    kk_std_num_random__random_dup(h, _ctx);
    {
      struct kk_std_num_random__Hnd_random* _con_x253 = kk_std_num_random__as_Hnd_random(h, _ctx);
      kk_integer_t _pat_0 = _con_x253->_cfc;
      kk_std_core_hnd__clause0 _fun_random_int32 = _con_x253->_fun_random_int32;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_random_int32, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x85 = _fun_random_int32.clause;
        _x_x251 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x85, (_fun_unbox_x85, m, ev_10075, _ctx), _ctx); /*35*/
      }
    }
  }
  x_10073 = kk_int32_unbox(_x_x251, KK_OWNED, _ctx); /*int32*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x254 = kk_std_core_hnd_yield_extend(kk_std_num_random__new_mlift_random_int64_10048_fun255(_y_x10031, _ctx), _ctx); /*2419*/
    return kk_int64_unbox(_x_x254, KK_OWNED, _ctx);
  }
  {
    return kk_int64_hi_lo(_y_x10031,x_10073);
  }
}


// lift anonymous function
struct kk_std_num_random_random_int64_fun261__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_random_int64_fun261(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_int64_fun261(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_random_int64_fun261, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random_random_int64_fun261(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x262;
  int32_t _x_x263 = kk_int32_unbox(_b_x99, KK_OWNED, _ctx); /*int32*/
  _x_x262 = kk_std_num_random__mlift_random_int64_10048(_x_x263, _ctx); /*int64*/
  return kk_int64_box(_x_x262, _ctx);
}


// lift anonymous function
struct kk_std_num_random_random_int64_fun268__t {
  struct kk_function_s _base;
  int32_t x_10079;
};
static kk_box_t kk_std_num_random_random_int64_fun268(kk_function_t _fself, kk_box_t _b_x107, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_int64_fun268(int32_t x_10079, kk_context_t* _ctx) {
  struct kk_std_num_random_random_int64_fun268__t* _self = kk_function_alloc_as(struct kk_std_num_random_random_int64_fun268__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_random_random_int64_fun268, kk_context());
  _self->x_10079 = x_10079;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_random_random_int64_fun268(kk_function_t _fself, kk_box_t _b_x107, kk_context_t* _ctx) {
  struct kk_std_num_random_random_int64_fun268__t* _self = kk_function_as(struct kk_std_num_random_random_int64_fun268__t*, _fself, _ctx);
  int32_t x_10079 = _self->x_10079; /* int32 */
  kk_drop_match(_self, {kk_skip_dup(x_10079, _ctx);}, {}, _ctx)
  int32_t _y_x10032_110 = kk_int32_unbox(_b_x107, KK_OWNED, _ctx); /*int32*/;
  int64_t _x_x269 = kk_int64_hi_lo(x_10079,_y_x10032_110); /*int64*/
  return kk_int64_box(_x_x269, _ctx);
}

int64_t kk_std_num_random_random_int64(kk_context_t* _ctx) { /* () -> random int64 */ 
  kk_std_core_hnd__ev ev_10082 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/num/random/random>*/;
  int32_t x_10079;
  kk_box_t _x_x257;
  {
    struct kk_std_core_hnd_Ev* _con_x258 = kk_std_core_hnd__as_Ev(ev_10082, _ctx);
    kk_box_t _box_x92 = _con_x258->hnd;
    int32_t m = _con_x258->marker;
    kk_std_num_random__random h = kk_std_num_random__random_unbox(_box_x92, KK_BORROWED, _ctx);
    kk_std_num_random__random_dup(h, _ctx);
    {
      struct kk_std_num_random__Hnd_random* _con_x259 = kk_std_num_random__as_Hnd_random(h, _ctx);
      kk_integer_t _pat_0 = _con_x259->_cfc;
      kk_std_core_hnd__clause0 _fun_random_int32 = _con_x259->_fun_random_int32;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_random_int32, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x95 = _fun_random_int32.clause;
        _x_x257 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x95, (_fun_unbox_x95, m, ev_10082, _ctx), _ctx); /*35*/
      }
    }
  }
  x_10079 = kk_int32_unbox(_x_x257, KK_OWNED, _ctx); /*int32*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x260 = kk_std_core_hnd_yield_extend(kk_std_num_random_new_random_int64_fun261(_ctx), _ctx); /*2419*/
    return kk_int64_unbox(_x_x260, KK_OWNED, _ctx);
  }
  {
    kk_std_core_hnd__ev ev_0_10087 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/num/random/random>*/;
    int32_t x_0_10084;
    kk_box_t _x_x264;
    {
      struct kk_std_core_hnd_Ev* _con_x265 = kk_std_core_hnd__as_Ev(ev_0_10087, _ctx);
      kk_box_t _box_x100 = _con_x265->hnd;
      int32_t m_0 = _con_x265->marker;
      kk_std_num_random__random h_0 = kk_std_num_random__random_unbox(_box_x100, KK_BORROWED, _ctx);
      kk_std_num_random__random_dup(h_0, _ctx);
      {
        struct kk_std_num_random__Hnd_random* _con_x266 = kk_std_num_random__as_Hnd_random(h_0, _ctx);
        kk_integer_t _pat_0_3 = _con_x266->_cfc;
        kk_std_core_hnd__clause0 _fun_random_int32_0 = _con_x266->_fun_random_int32;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_integer_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause0_dup(_fun_random_int32_0, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x103 = _fun_random_int32_0.clause;
          _x_x264 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x103, (_fun_unbox_x103, m_0, ev_0_10087, _ctx), _ctx); /*35*/
        }
      }
    }
    x_0_10084 = kk_int32_unbox(_x_x264, KK_OWNED, _ctx); /*int32*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x267 = kk_std_core_hnd_yield_extend(kk_std_num_random_new_random_int64_fun268(x_10079, _ctx), _ctx); /*2419*/
      return kk_int64_unbox(_x_x267, KK_OWNED, _ctx);
    }
    {
      return kk_int64_hi_lo(x_10079,x_0_10084);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_random__mlift_random_float64_10049_fun272__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random__mlift_random_float64_10049_fun272(kk_function_t _fself, kk_box_t _b_x114, kk_box_t _b_x115, kk_context_t* _ctx);
static kk_function_t kk_std_num_random__new_mlift_random_float64_10049_fun272(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random__mlift_random_float64_10049_fun272, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random__mlift_random_float64_10049_fun272(kk_function_t _fself, kk_box_t _b_x114, kk_box_t _b_x115, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x273;
  int64_t _x_x274 = kk_int64_unbox(_b_x114, KK_OWNED, _ctx); /*int64*/
  int64_t _x_x275;
  kk_integer_t _x_x276 = kk_integer_unbox(_b_x115, _ctx); /*int*/
  _x_x275 = kk_std_num_int64_int64(_x_x276, _ctx); /*int64*/
  _x_x273 = (int64_t)kk_shr64(_x_x274,_x_x275); /*int64*/
  return kk_int64_box(_x_x273, _ctx);
}


// lift anonymous function
struct kk_std_num_random__mlift_random_float64_10049_fun279__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random__mlift_random_float64_10049_fun279(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx);
static kk_function_t kk_std_num_random__new_mlift_random_float64_10049_fun279(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random__mlift_random_float64_10049_fun279, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random__mlift_random_float64_10049_fun279(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x280;
  kk_integer_t _x_x281 = kk_integer_unbox(_b_x118, _ctx); /*int*/
  _x_x280 = kk_std_num_int64_int64(_x_x281, _ctx); /*int64*/
  return kk_int64_box(_x_x280, _ctx);
}


// lift anonymous function
struct kk_std_num_random__mlift_random_float64_10049_fun284__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random__mlift_random_float64_10049_fun284(kk_function_t _fself, kk_box_t _b_x128, kk_context_t* _ctx);
static kk_function_t kk_std_num_random__new_mlift_random_float64_10049_fun284(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random__mlift_random_float64_10049_fun284, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random__mlift_random_float64_10049_fun284(kk_function_t _fself, kk_box_t _b_x128, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x285;
  int64_t _x_x286 = kk_int64_unbox(_b_x128, KK_OWNED, _ctx); /*int64*/
  _x_x285 = kk_std_num_float64_float64_from_bits(_x_x286, _ctx); /*float64*/
  return kk_double_box(_x_x285, _ctx);
}

double kk_std_num_random__mlift_random_float64_10049(int64_t _y_x10033, kk_context_t* _ctx) { /* (int64) -> random float64 */ 
  int64_t mag;
  int64_t _x_x270;
  kk_box_t _x_x271 = kk_std_core_hnd__open_none2(kk_std_num_random__new_mlift_random_float64_10049_fun272(_ctx), kk_int64_box(_y_x10033, _ctx), kk_integer_box(kk_integer_from_small(12), _ctx), _ctx); /*9985*/
  _x_x270 = kk_int64_unbox(_x_x271, KK_OWNED, _ctx); /*int64*/
  int64_t _x_x277;
  kk_box_t _x_x278 = kk_std_core_hnd__open_none1(kk_std_num_random__new_mlift_random_float64_10049_fun279(_ctx), kk_integer_box(kk_integer_from_str("4607182418800017408", _ctx), _ctx), _ctx); /*9904*/
  _x_x277 = kk_int64_unbox(_x_x278, KK_OWNED, _ctx); /*int64*/
  mag = _x_x270 | _x_x277; /*int64*/
  double _x_x282;
  kk_box_t _x_x283 = kk_std_core_hnd__open_none1(kk_std_num_random__new_mlift_random_float64_10049_fun284(_ctx), kk_int64_box(mag, _ctx), _ctx); /*9904*/
  _x_x282 = kk_double_unbox(_x_x283, KK_OWNED, _ctx); /*float64*/
  return (_x_x282 - 0x1p0);
}
 
// Return a random float64 in the range [0,1) using 52-bits of randomness


// lift anonymous function
struct kk_std_num_random_random_float64_fun288__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_random_float64_fun288(kk_function_t _fself, kk_box_t _b_x132, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_float64_fun288(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_random_float64_fun288, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random_random_float64_fun288(kk_function_t _fself, kk_box_t _b_x132, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x289;
  int64_t _x_x290 = kk_int64_unbox(_b_x132, KK_OWNED, _ctx); /*int64*/
  _x_x289 = kk_std_num_random__mlift_random_float64_10049(_x_x290, _ctx); /*float64*/
  return kk_double_box(_x_x289, _ctx);
}


// lift anonymous function
struct kk_std_num_random_random_float64_fun293__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_random_float64_fun293(kk_function_t _fself, kk_box_t _b_x136, kk_box_t _b_x137, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_float64_fun293(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_random_float64_fun293, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random_random_float64_fun293(kk_function_t _fself, kk_box_t _b_x136, kk_box_t _b_x137, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x294;
  int64_t _x_x295 = kk_int64_unbox(_b_x136, KK_OWNED, _ctx); /*int64*/
  int64_t _x_x296;
  kk_integer_t _x_x297 = kk_integer_unbox(_b_x137, _ctx); /*int*/
  _x_x296 = kk_std_num_int64_int64(_x_x297, _ctx); /*int64*/
  _x_x294 = (int64_t)kk_shr64(_x_x295,_x_x296); /*int64*/
  return kk_int64_box(_x_x294, _ctx);
}


// lift anonymous function
struct kk_std_num_random_random_float64_fun300__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_random_float64_fun300(kk_function_t _fself, kk_box_t _b_x140, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_float64_fun300(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_random_float64_fun300, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random_random_float64_fun300(kk_function_t _fself, kk_box_t _b_x140, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x301;
  kk_integer_t _x_x302 = kk_integer_unbox(_b_x140, _ctx); /*int*/
  _x_x301 = kk_std_num_int64_int64(_x_x302, _ctx); /*int64*/
  return kk_int64_box(_x_x301, _ctx);
}


// lift anonymous function
struct kk_std_num_random_random_float64_fun305__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_random_float64_fun305(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_float64_fun305(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_random_float64_fun305, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_random_random_float64_fun305(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x306;
  int64_t _x_x307 = kk_int64_unbox(_b_x150, KK_OWNED, _ctx); /*int64*/
  _x_x306 = kk_std_num_float64_float64_from_bits(_x_x307, _ctx); /*float64*/
  return kk_double_box(_x_x306, _ctx);
}

double kk_std_num_random_random_float64(kk_context_t* _ctx) { /* () -> random float64 */ 
  int64_t x_10091 = kk_std_num_random_random_int64(_ctx); /*int64*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x287 = kk_std_core_hnd_yield_extend(kk_std_num_random_new_random_float64_fun288(_ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x287, KK_OWNED, _ctx);
  }
  {
    int64_t mag;
    int64_t _x_x291;
    kk_box_t _x_x292 = kk_std_core_hnd__open_none2(kk_std_num_random_new_random_float64_fun293(_ctx), kk_int64_box(x_10091, _ctx), kk_integer_box(kk_integer_from_small(12), _ctx), _ctx); /*9985*/
    _x_x291 = kk_int64_unbox(_x_x292, KK_OWNED, _ctx); /*int64*/
    int64_t _x_x298;
    kk_box_t _x_x299 = kk_std_core_hnd__open_none1(kk_std_num_random_new_random_float64_fun300(_ctx), kk_integer_box(kk_integer_from_str("4607182418800017408", _ctx), _ctx), _ctx); /*9904*/
    _x_x298 = kk_int64_unbox(_x_x299, KK_OWNED, _ctx); /*int64*/
    mag = _x_x291 | _x_x298; /*int64*/
    double _x_x303;
    kk_box_t _x_x304 = kk_std_core_hnd__open_none1(kk_std_num_random_new_random_float64_fun305(_ctx), kk_int64_box(mag, _ctx), _ctx); /*9904*/
    _x_x303 = kk_double_unbox(_x_x304, KK_OWNED, _ctx); /*float64*/
    return (_x_x303 - 0x1p0);
  }
}
 
// Returns one of its arguments `x`  or `y`  based on a non-deterministic choice.

kk_box_t kk_std_num_random_choose(kk_box_t x, kk_box_t y, kk_context_t* _ctx) { /* forall<a> (x : a, y : a) -> ndet a */ 
  bool _match_x157;
  int32_t _x_x309 = kk_std_num_random_srandom_int32(_ctx); /*int32*/
  _match_x157 = (_x_x309 >= ((KK_I32(0)))); /*bool*/
  if (_match_x157) {
    kk_box_drop(y, _ctx);
    return x;
  }
  {
    kk_box_drop(x, _ctx);
    return y;
  }
}
 
// Return a strong random `:float64` in the range [0,1) using 52-bits of randomness

double kk_std_num_random_srandom_float64(kk_context_t* _ctx) { /* () -> ndet float64 */ 
  return kk_srandom_double(kk_context());
}
 
// Are the strong random numbers generated from a strong random source? (like /dev/urandom)

bool kk_std_num_random_srandom_is_strong(kk_context_t* _ctx) { /* () -> ndet bool */ 
  return kk_srandom_is_strong(kk_context());
}
 
// Return a strong random `:int32` uniformly distributed in the range [lo,hi)

int32_t kk_std_num_random_srandom_int32_range(int32_t lo, int32_t hi, kk_context_t* _ctx) { /* (lo : int32, hi : int32) -> ndet int32 */ 
  return kk_srandom_range_int32(lo,hi,kk_context());
}
 
// Generate a strong random float64 uniformly distributed in the range [lo, hi)

double kk_std_num_random_srandom_float64_range(double lo, double hi, kk_context_t* _ctx) { /* (lo : float64, hi : float64) -> ndet float64 */ 
  double low;
  bool _match_x156 = (lo <= hi); /*bool*/;
  if (_match_x156) {
    low = lo; /*float64*/
  }
  else {
    low = hi; /*float64*/
  }
  double high;
  bool _match_x155 = (lo <= hi); /*bool*/;
  if (_match_x155) {
    high = hi; /*float64*/
  }
  else {
    high = lo; /*float64*/
  }
  double x;
  double _x_x311;
  double _x_x312 = (high - low); /*float64*/
  double _x_x313 = kk_std_num_random_srandom_float64(_ctx); /*float64*/
  _x_x311 = (_x_x312 * _x_x313); /*float64*/
  x = (_x_x311 + low); /*float64*/
  bool _match_x154 = (x >= high); /*bool*/;
  if (_match_x154) {
    return low;
  }
  {
    return x;
  }
}

// initialization
void kk_std_num_random__init(kk_context_t* _ctx){
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
  kk_std_num_int32__init(_ctx);
  kk_std_num_int64__init(_ctx);
  kk_std_num_float64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x178;
    kk_define_string_literal(, _s_x179, 13, "random@random", _ctx)
    _x_x178 = kk_string_dup(_s_x179, _ctx); /*string*/
    kk_std_num_random_random_fs__tag = kk_std_core_hnd__new_Htag(_x_x178, _ctx); /*hnd/htag<std/num/random/random>*/
  }
}

// termination
void kk_std_num_random__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__htag_drop(kk_std_num_random_random_fs__tag, _ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_num_int64__done(_ctx);
  kk_std_num_int32__done(_ctx);
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
