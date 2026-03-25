// Koka generated module: std/core/hnd, koka version: 3.2.2, platform: 64-bit
#include "std_core_hnd.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/
/*
typedef datatype_t kk_std_core_hnd__ev;
struct kk_std_core_hnd_Ev {
  kk_std_core_hnd__htag htag;
  kk_box_t hnd;
  // kk_cfc_t cfc;  // control flow context
  kk_std_core_hnd__evv hevv;
  kk_std_core_hnd__marker marker;
};
*/


// Note. We no longer support cfc for `evv_is_affine` in the C backend since we always use context paths now.
//
// typedef int32_t kk_cfc_t;

// static kk_cfc_t kk_handler_cfc_borrow( kk_box_t h, kk_context_t* ctx ) {
//   kk_box_t b = kk_block_field(kk_ptr_unbox(h,ctx),0);  // first field of the handler is the cfc
//   return kk_integer_clamp32_borrow(kk_integer_unbox(b,ctx),ctx);
// }


static kk_evv_vector_t kk_evv_vector_alloc(kk_ssize_t length, kk_context_t* ctx) {
  kk_assert_internal(length>=0);
  kk_evv_vector_t v = (kk_evv_vector_t)kk_block_alloc(kk_ssizeof(struct kk_evv_vector_s) + (length-1)*kk_ssizeof(kk_std_core_hnd__ev_t), length, KK_TAG_EVV_VECTOR, ctx);
  // v->cfc = kk_integer_from_int32(cfc,ctx);
  return v;
}

static kk_std_core_hnd__ev* kk_evv_vector_buf(kk_evv_vector_t vec, kk_ssize_t* len) {
  if (len != NULL) { *len = kk_block_scan_fsize(&vec->_block); }
  return &vec->vec[0];
}

static kk_std_core_hnd__ev* kk_evv_as_vec(kk_evv_t evv, kk_ssize_t* len, kk_std_core_hnd__ev* single, kk_context_t* ctx) {
  if (kk_evv_is_vector(evv,ctx)) {
    kk_evv_vector_t vec = kk_evv_as_vector(evv,ctx);
    *len = kk_block_scan_fsize(&vec->_block);
    return &vec->vec[0];
  }
  else {
    // single evidence
    *single = kk_evv_as_ev(evv,ctx);
    *len = 1;
    return single;
  }
}

// kk_std_core_hnd__ev kk_ev_none(kk_context_t* ctx) {
//   static kk_std_core_hnd__ev ev_none_singleton = { kk_datatype_null_init };
//   if (kk_datatype_is_null(ev_none_singleton)) {
//     ev_none_singleton = kk_std_core_hnd__new_Ev(
//       kk_reuse_null,
//       0, // cpath
//       kk_std_core_hnd__new_Htag(kk_string_empty(),ctx), // tag ""
//       0,                                                // marker 0
//       kk_box_null(),                                    // no handler
//       // -1,                                               // bot
//       kk_evv_empty(ctx),
//       ctx
//     );
//   }
//   return kk_std_core_hnd__ev_dup(ev_none_singleton,ctx);
// }


kk_ssize_t kk_evv_index( struct kk_std_core_hnd_Htag htag, kk_context_t* ctx ) {
  // todo: drop htag?
  kk_ssize_t len;
  kk_std_core_hnd__ev single;
  kk_std_core_hnd__ev* vec = kk_evv_as_vec(ctx->evv,&len,&single,ctx);
  for(kk_ssize_t i = 0; i < len; i++) {
    struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(vec[i],ctx);
    if (kk_string_cmp_borrow(htag.tagname,ev->htag.tagname,ctx) <= 0) return i; // break on insertion point
  }
  //string_t evvs = kk_evv_show(dup_datatype_as(kk_evv_t,ctx->evv),ctx);
  //fatal_error(EFAULT,"cannot find tag '%s' in: %s", string_cbuf_borrow(htag.htag), string_cbuf_borrow(evvs));
  //drop_string_t(evvs,ctx);
  return len;
}


// static inline kk_cfc_t kk_cfc_lub(kk_cfc_t cfc1, kk_cfc_t cfc2) {
//   if (cfc1 < 0) return cfc2;
//   else if (cfc1+cfc2 == 1) return 2;
//   else if (cfc1>cfc2) return cfc1;
//   else return cfc2;
// }

// static inline struct kk_std_core_hnd_Ev* kk_evv_as_Ev( kk_evv_t evv, kk_context_t* ctx ) {
//   return kk_std_core_hnd__as_Ev(kk_evv_as_ev(evv,ctx),ctx);
// }


// static kk_cfc_t kk_evv_cfc_of_borrow(kk_evv_t evv, kk_context_t* ctx) {
//   if (kk_evv_is_vector(evv,ctx)) {
//     kk_cfc_t cfc = -1;
//     kk_ssize_t len;
//     kk_std_core_hnd__ev single;
//     kk_std_core_hnd__ev* vec = kk_evv_as_vec(ctx->evv,&len,&single,ctx);
//     for(kk_ssize_t i = 0; i < len; i++) {
//       struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(vec[i],ctx);
//       cfc = kk_cfc_lub(cfc, kk_handler_cfc_borrow(ev->hnd,ctx));
//     }
//     return cfc;
//   }
//   else {
//     struct kk_std_core_hnd_Ev* ev = kk_evv_as_Ev(evv,ctx);
//     return kk_handler_cfc_borrow(ev->hnd,ctx);
//   }
// }

bool kk_evv_is_affine(kk_context_t* ctx) {
  return false;
  // return (kk_evv_cfc_of_borrow(ctx->evv,ctx) <= 2);
}


// static void kk_evv_update_cfc_borrow(kk_evv_t evv, kk_cfc_t cfc, kk_context_t* ctx) {
//   kk_assert_internal(!kk_evv_is_empty(evv,ctx)); // should never happen (as named handlers are always in some context)
//   if (kk_evv_is_vector(evv,ctx)) {
//     kk_evv_vector_t vec = kk_evv_as_vector(evv,ctx);
//     vec->cfc = kk_integer_from_int32(kk_cfc_lub(kk_integer_clamp32_borrow(vec->cfc,ctx),cfc), ctx);
//   }
//   else {
//     struct kk_std_core_hnd_Ev* ev = kk_evv_as_Ev(evv,ctx);
//     ev->cfc = kk_cfc_lub(ev->cfc,cfc);
//   }
// }

kk_evv_t kk_evv_insert(kk_evv_t evvd, kk_std_core_hnd__ev evd, kk_context_t* ctx) {
  struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(evd,ctx);
  // update ev with parent evidence vector (either at init, or due to non-scoped resumptions)
  kk_marker_t marker = ev->marker;
  if (marker==0) { kk_std_core_hnd__ev_drop(evd,ctx); return evvd; } // ev-none
  kk_evv_drop(ev->hevv,ctx);
  ev->hevv = kk_evv_dup(evvd,ctx); // fixme: update in-place
  if (marker<0) { // negative marker is used for named evidence; this means this evidence should not be inserted into the evidence vector
    // kk_evv_update_cfc_borrow(evvd,ev->cfc,ctx); // update cfc in-place for named evidence
    kk_std_core_hnd__ev_drop(evd,ctx);
    return evvd;
  }
  // for regular handler evidence, insert ev
  kk_ssize_t n;
  kk_std_core_hnd__ev single;
  kk_std_core_hnd__ev* const evv1 = kk_evv_as_vec(evvd, &n, &single, ctx);
  if (n == 0) {
    // use ev directly as the evidence vector
    kk_evv_drop(evvd, ctx);
    return kk_ev_as_evv(evd,ctx);
  }
  else {
    // create evidence vector
    // const kk_cfc_t cfc = kk_cfc_lub(kk_evv_cfc_of_borrow(evvd, ctx), ev->cfc);
    // ev->cfc = cfc; // update in place
    kk_evv_vector_t vec2 = kk_evv_vector_alloc(n+1, /* cfc,*/ ctx);
    kk_std_core_hnd__ev* const evv2 = kk_evv_vector_buf(vec2, NULL);
    kk_ssize_t i;
    for (i = 0; i < n; i++) {
      struct kk_std_core_hnd_Ev* ev1 = kk_std_core_hnd__as_Ev(evv1[i],ctx);
      if (kk_string_cmp_borrow(ev->htag.tagname, ev1->htag.tagname,ctx) <= 0) break;
      evv2[i] = kk_std_core_hnd__ev_dup(evv1[i],ctx);
    }
    evv2[i] = evd;
    for (; i < n; i++) {
      evv2[i+1] = kk_std_core_hnd__ev_dup(evv1[i],ctx);
    }
    kk_evv_drop(evvd, ctx);  // assigned to evidence already
    return kk_datatype_from_base(vec2,ctx);
  }
}

kk_evv_t kk_evv_delete(kk_evv_t evvd, kk_ssize_t index, bool behind, kk_context_t* ctx) {
  kk_ssize_t n;
  kk_std_core_hnd__ev single;
  const kk_std_core_hnd__ev* evv1 = kk_evv_as_vec(evvd, &n, &single, ctx);
  if (n <= 1) {
    kk_evv_drop(evvd,ctx);
    return kk_evv_empty(ctx);
  }
  if (behind) index++;
  kk_assert_internal(index < n);
  // todo: copy without dupping (and later dropping) when possible
  // const kk_cfc_t cfc1 = kk_evv_cfc_of_borrow(evvd,ctx);
  kk_evv_vector_t const vec2 = kk_evv_vector_alloc(n-1,/*cfc1,*/ ctx);
  kk_std_core_hnd__ev* const evv2 = kk_evv_vector_buf(vec2,NULL);
  kk_ssize_t i;
  for(i = 0; i < index; i++) {
    evv2[i] = kk_std_core_hnd__ev_dup(evv1[i],ctx);
  }
  for(; i < n-1; i++) {
    evv2[i] = kk_std_core_hnd__ev_dup(evv1[i+1],ctx);
  }
  struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(evv1[index],ctx);
  // if (ev->cfc >= cfc1) {
  //   kk_cfc_t cfc = kk_std_core_hnd__as_Ev(evv2[0],ctx)->cfc;
  //   for(i = 1; i < n-1; i++) {
  //     cfc = kk_cfc_lub(cfc,kk_std_core_hnd__as_Ev(evv2[i],ctx)->cfc);
  //   }
  //   vec2->cfc = kk_integer_from_int32(cfc,ctx);
  // }
  kk_evv_drop(evvd,ctx);
  return kk_datatype_from_base(vec2,ctx);
}

kk_evv_t kk_evv_create(kk_evv_t evv1, kk_vector_t indices, kk_context_t* ctx) {
  kk_ssize_t len;
  kk_box_t* elems = kk_vector_buf_borrow(indices,&len,ctx); // borrows
  kk_evv_vector_t evv2 = kk_evv_vector_alloc(len,/* kk_evv_cfc_of_borrow(evv1,ctx),*/ ctx);
  kk_std_core_hnd__ev* buf2 = kk_evv_vector_buf(evv2,NULL);
  kk_assert_internal(kk_evv_is_vector(evv1,ctx));
  kk_ssize_t len1;
  kk_std_core_hnd__ev single;
  kk_std_core_hnd__ev* buf1 = kk_evv_as_vec(evv1,&len1,&single,ctx);
  for(kk_ssize_t i = 0; i < len; i++) {
    kk_ssize_t idx = kk_ssize_unbox(elems[i],KK_BORROWED,ctx);
    kk_assert_internal(idx < len1);
    buf2[i] = kk_std_core_hnd__ev_dup( buf1[idx], ctx );
  }
  kk_vector_drop(indices,ctx);
  kk_evv_drop(evv1,ctx);
  return kk_datatype_from_base(evv2,ctx);
}

kk_evv_t kk_evv_swap_create( kk_vector_t indices, kk_context_t* ctx ) {
  kk_ssize_t len;
  kk_box_t* vec = kk_vector_buf_borrow(indices,&len,ctx);
  if (len==0) {
    kk_vector_drop(indices,ctx);
    return kk_evv_swap_create0(ctx);
  }
  if (len==1) {
    kk_ssize_t i = kk_ssize_unbox(vec[0],KK_BORROWED,ctx);
    kk_vector_drop(indices,ctx);
    return kk_evv_swap_create1(i,ctx);
  }
  return kk_evv_swap( kk_evv_create(kk_evv_dup(ctx->evv,ctx),indices,ctx), ctx );
}


kk_string_t kk_evv_show(kk_evv_t evv, kk_context_t* ctx) {
  return kk_string_alloc_dup_valid_utf8("(not yet implemented: kk_evv_show)",ctx);
}


/*-----------------------------------------------------------------------
  Compose continuations
-----------------------------------------------------------------------*/

struct kcompose_fun_s {
  struct kk_function_s _base;
  kk_box_t      count;
  kk_function_t conts[1];
};

// kleisli composition of continuations
static kk_box_t kcompose( kk_function_t fself, kk_box_t x, kk_context_t* ctx) {
  struct kcompose_fun_s* self = kk_function_as(struct kcompose_fun_s*,fself,ctx);
  kk_intx_t count = kk_intf_unbox(self->count);
  kk_function_t* conts = &self->conts[0];
  // call each continuation in order
  for(kk_intx_t i = 0; i < count; i++) {
    // todo: take uniqueness of fself into account to avoid dup_function
    kk_function_t f = kk_function_dup(conts[i],ctx);
    x = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, ctx), ctx);
    if (kk_yielding(ctx)) {
      // if yielding, `yield_next` all continuations that still need to be done
      while(++i < count) {
        // todo: if fself is unique, we could copy without dup?
        kk_yield_extend(kk_function_dup(conts[i],ctx),ctx);
      }
      kk_function_drop(fself,ctx);
      kk_box_drop(x,ctx);     // still drop even though we yield as it may release a boxed value type?
      return kk_box_any(ctx); // return yielding
    }
  }
  kk_function_drop(fself,ctx);
  return x;
}

static kk_function_t new_kcompose( kk_function_t* conts, kk_intf_t count, kk_context_t* ctx ) {
  if (count==0) return kk_function_id(ctx);
  if (count==1) return conts[0];
  struct kcompose_fun_s* f = kk_block_as(struct kcompose_fun_s*,
                               kk_block_alloc(kk_ssizeof(struct kcompose_fun_s) - kk_ssizeof(kk_function_t) + (count*kk_ssizeof(kk_function_t)),
                                 2 + count /* scan size */, KK_TAG_FUNCTION, ctx));
  f->_base.fun = kk_kkfun_ptr_box(&kcompose,ctx);
  f->count = kk_intf_box(count);
  kk_memcpy(f->conts, conts, count * kk_ssizeof(kk_function_t));
  return kk_datatype_from_base(&f->_base,ctx);
}

/*-----------------------------------------------------------------------
  Yield extension
-----------------------------------------------------------------------*/

kk_box_t kk_yield_extend( kk_function_t next, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  kk_assert_internal(kk_yielding(ctx));  // cannot extend if not yielding
  if (kk_unlikely(kk_yielding_final(ctx))) {
    // todo: can we optimize this so `next` is never allocated in the first place?
    kk_function_drop(next,ctx); // ignore extension if never resuming
  }
  else {
    if (kk_unlikely(yield->conts_count >= KK_YIELD_CONT_MAX)) {
      // alloc a function to compose all continuations in the array
      kk_function_t comp = new_kcompose( yield->conts, yield->conts_count, ctx );
      yield->conts[0] = comp;
      yield->conts_count = 1;
    }
    yield->conts[yield->conts_count++] = next;
  }
  return kk_box_any(ctx);
}

// cont_apply: \x -> f(cont,x)
struct cont_apply_fun_s {
  struct kk_function_s _base;
  kk_function_t f;
  kk_function_t cont;
};

static kk_box_t cont_apply( kk_function_t fself, kk_box_t x, kk_context_t* ctx ) {
  struct cont_apply_fun_s* self = kk_function_as(struct cont_apply_fun_s*, fself, ctx);
  kk_function_t f = self->f;
  kk_function_t cont = self->cont;
  kk_drop_match(self,{kk_function_dup(f,ctx);kk_function_dup(cont,ctx);},{},ctx);
  return kk_function_call( kk_box_t, (kk_function_t, kk_function_t, kk_box_t, kk_context_t* ctx), f, (f, cont, x, ctx), ctx);
}

static kk_function_t kk_new_cont_apply( kk_function_t f, kk_function_t cont, kk_context_t* ctx ) {
  struct cont_apply_fun_s* self = kk_function_alloc_as(struct cont_apply_fun_s, 3, ctx);
  self->_base.fun = kk_kkfun_ptr_box(&cont_apply,ctx);
  self->f = f;
  self->cont = cont;
  return kk_datatype_from_base(&self->_base,ctx);
}

// Unlike `yield_extend`, `yield_cont` gets access to the current continuation. This is used in `yield_prompt`.
kk_box_t kk_yield_cont( kk_function_t f, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  kk_assert_internal(kk_yielding(ctx)); // cannot extend if not yielding
  if (kk_unlikely(kk_yielding_final(ctx))) {
    kk_function_drop(f,ctx); // ignore extension if never resuming
  }
  else {
    kk_function_t cont = new_kcompose(yield->conts, yield->conts_count, ctx);
    yield->conts_count = 1;
    yield->conts[0] = kk_new_cont_apply(f, cont, ctx);
  }
  return kk_box_any(ctx);
}

kk_function_t kk_yield_to( kk_marker_t m, kk_function_t clause, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  kk_assert_internal(!kk_yielding(ctx)); // already yielding
  ctx->yielding = KK_YIELD_NORMAL;
  yield->marker = m;
  yield->clause = clause;
  yield->conts_count = 0;
  return kk_datatype_unbox(kk_box_any(ctx));
}

kk_box_t kk_yield_final( kk_marker_t m, kk_function_t clause, kk_context_t* ctx ) {
  kk_yield_to(m,clause,ctx);
  ctx->yielding = KK_YIELD_FINAL;
  return kk_box_any(ctx);
}

kk_box_t kk_fatal_resume_final(kk_context_t* ctx) {
  kk_fatal_error(EFAULT,"trying to resume a finalized resumption");
  return kk_box_any(ctx);
}

static kk_box_t _fatal_resume_final(kk_function_t self, kk_context_t* ctx) {
  kk_function_drop(self,ctx);
  return kk_fatal_resume_final(ctx);
}
static kk_function_t fun_fatal_resume_final(kk_context_t* ctx) {
  kk_define_static_function(f,_fatal_resume_final,ctx);
  return kk_function_dup(f,ctx);
}


struct kk_std_core_hnd_yld_s kk_yield_prompt( kk_marker_t m, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  if (ctx->yielding == KK_YIELD_NONE) {
    return kk_std_core_hnd__new_Pure(ctx);
  }
  else if (yield->marker != m) {
    return (ctx->yielding == KK_YIELD_FINAL ? kk_std_core_hnd__new_YieldingFinal(ctx) : kk_std_core_hnd__new_Yielding(ctx));
  }
  else {
    kk_function_t cont = (ctx->yielding == KK_YIELD_FINAL ? fun_fatal_resume_final(ctx) : new_kcompose(yield->conts, yield->conts_count, ctx));
    kk_function_t clause = yield->clause;
    ctx->yielding = KK_YIELD_NONE;
    #ifndef NDEBUG
    kk_memset(yield,0,kk_ssizeof(kk_yield_t));
    #endif
    return kk_std_core_hnd__new_Yield(clause, cont, ctx);
  }
}

kk_unit_t  kk_evv_guard(kk_evv_t evv, kk_context_t* ctx) {
  bool eq = kk_datatype_eq(ctx->evv,evv);
  kk_evv_drop(evv,ctx);
  if (!eq) {
    // todo: improve error message with diagnostics
    kk_fatal_error(EFAULT,"trying to resume outside the (handler) scope of the original handler");
  }
  return kk_Unit;
}

typedef struct yield_info_s {
  struct kk_std_core_hnd__yield_info_s _base;
  kk_function_t clause;
  kk_function_t conts[KK_YIELD_CONT_MAX];
  kk_intf_t     conts_count;
  kk_marker_t   marker;
  int8_t        yielding;
}* yield_info_t;

kk_std_core_hnd__yield_info kk_yield_capture(kk_context_t* ctx) {
  kk_assert_internal(kk_yielding(ctx));
  yield_info_t yld = kk_block_alloc_as(struct yield_info_s, 1 + KK_YIELD_CONT_MAX, (kk_tag_t)1, ctx);
  yld->clause = ctx->yield.clause;
  kk_ssize_t i = 0;
  for( ; i < ctx->yield.conts_count; i++) {
    yld->conts[i] = ctx->yield.conts[i];
  }
  for( ; i < KK_YIELD_CONT_MAX; i++) {
    yld->conts[i] = kk_function_null(ctx);
  }
  yld->conts_count = ctx->yield.conts_count;
  yld->marker = ctx->yield.marker;
  yld->yielding = ctx->yielding;
  ctx->yielding = 0;
  ctx->yield.conts_count = 0;
  return kk_datatype_from_base(&yld->_base,ctx);
}

kk_box_t kk_yield_reyield( kk_std_core_hnd__yield_info yldinfo, kk_context_t* ctx) {
  kk_assert_internal(!kk_yielding(ctx));
  yield_info_t yld = kk_datatype_as_assert(yield_info_t, yldinfo, (kk_tag_t)1, ctx);
  ctx->yield.clause = kk_function_dup(yld->clause,ctx);
  ctx->yield.marker = yld->marker;
  ctx->yield.conts_count = yld->conts_count;
  ctx->yielding = yld->yielding;
  for(kk_ssize_t i = 0; i < yld->conts_count; i++) {
    ctx->yield.conts[i] = kk_function_dup(yld->conts[i],ctx);
  }
  kk_constructor_drop(yld,ctx);
  return kk_box_any(ctx);
}


kk_std_core_hnd__htag kk_std_core_hnd_htag_fs__copy(kk_std_core_hnd__htag _this, kk_std_core_types__optional tagname, kk_context_t* _ctx) { /* forall<a> (htag<a>, tagname : ? string) -> htag<a> */ 
  kk_string_t _x_x308;
  if (kk_std_core_types__is_Optional(tagname, _ctx)) {
    kk_box_t _box_x0 = tagname._cons._Optional.value;
    kk_string_t _uniq_tagname_1886 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_tagname_1886, _ctx);
    kk_std_core_types__optional_drop(tagname, _ctx);
    kk_std_core_hnd__htag_drop(_this, _ctx);
    _x_x308 = _uniq_tagname_1886; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(tagname, _ctx);
    {
      kk_string_t _x = _this.tagname;
      _x_x308 = _x; /*string*/
    }
  }
  return kk_std_core_hnd__new_Htag(_x_x308, _ctx);
}

kk_std_core_hnd__ev kk_std_core_hnd_ev_fs__copy(kk_std_core_hnd__ev _this, kk_std_core_types__optional htag, int32_t marker, kk_box_t hnd, kk_evv_t hevv, kk_context_t* _ctx) { /* forall<a,e,b> (ev<a>, htag : ? (htag<a>), marker : marker<e,b>, hnd : a<e,b>, hevv : evv<e>) -> ev<a> */ 
  kk_std_core_hnd__htag _x_x310;
  if (kk_std_core_types__is_Optional(htag, _ctx)) {
    kk_box_t _box_x1 = htag._cons._Optional.value;
    kk_std_core_hnd__htag _uniq_htag_1987 = kk_std_core_hnd__htag_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_hnd__htag_dup(_uniq_htag_1987, _ctx);
    kk_std_core_types__optional_drop(htag, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x310 = _uniq_htag_1987; /*hnd/htag<2019>*/
  }
  else {
    kk_std_core_types__optional_drop(htag, _ctx);
    {
      struct kk_std_core_hnd_Ev* _con_x311 = kk_std_core_hnd__as_Ev(_this, _ctx);
      kk_std_core_hnd__htag _x = _con_x311->htag;
      kk_box_t _pat_1_0 = _con_x311->hnd;
      kk_evv_t _pat_2 = _con_x311->hevv;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_evv_drop(_pat_2, _ctx);
        kk_box_drop(_pat_1_0, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_std_core_hnd__htag_dup(_x, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x310 = _x; /*hnd/htag<2019>*/
    }
  }
  return kk_std_core_hnd__new_Ev(kk_reuse_null, 0, _x_x310, marker, hnd, hevv, _ctx);
}
 
// Are two markers equal?

bool kk_std_core_hnd_eq_marker(int32_t x, int32_t y, kk_context_t* _ctx) { /* forall<a,b,e,e1> (x : marker<e,a>, y : marker<e1,b>) -> bool */ 
  return x==y;
}
 
// Evidence equality compares the markers.

bool kk_std_core_hnd_ev_fs__lp__eq__eq__rp_(kk_std_core_hnd__ev _pat_x141__18, kk_std_core_hnd__ev _pat_x141__37, kk_context_t* _ctx) { /* forall<a> (ev<a>, ev<a>) -> bool */ 
  {
    struct kk_std_core_hnd_Ev* _con_x312 = kk_std_core_hnd__as_Ev(_pat_x141__18, _ctx);
    kk_std_core_hnd__htag _pat_0 = _con_x312->htag;
    int32_t m1 = _con_x312->marker;
    kk_box_t _pat_1 = _con_x312->hnd;
    kk_evv_t _pat_2 = _con_x312->hevv;
    if kk_likely(kk_datatype_ptr_is_unique(_pat_x141__18, _ctx)) {
      kk_evv_drop(_pat_2, _ctx);
      kk_box_drop(_pat_1, _ctx);
      kk_std_core_hnd__htag_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_pat_x141__18, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_pat_x141__18, _ctx);
    }
    {
      struct kk_std_core_hnd_Ev* _con_x313 = kk_std_core_hnd__as_Ev(_pat_x141__37, _ctx);
      kk_std_core_hnd__htag _pat_4 = _con_x313->htag;
      int32_t m2 = _con_x313->marker;
      kk_box_t _pat_5 = _con_x313->hnd;
      kk_evv_t _pat_6 = _con_x313->hevv;
      if kk_likely(kk_datatype_ptr_is_unique(_pat_x141__37, _ctx)) {
        kk_evv_drop(_pat_6, _ctx);
        kk_box_drop(_pat_5, _ctx);
        kk_std_core_hnd__htag_drop(_pat_4, _ctx);
        kk_datatype_ptr_free(_pat_x141__37, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_x141__37, _ctx);
      }
      return kk_std_core_hnd_eq_marker(m1, m2, _ctx);
    }
  }
}

int32_t kk_std_core_hnd_fresh_marker(kk_context_t* _ctx) { /* forall<a,e> () -> marker<e,a> */ 
  return kk_marker_unique(kk_context());
}

int32_t kk_std_core_hnd_fresh_marker_named(kk_context_t* _ctx) { /* forall<a,e> () -> marker<e,a> */ 
  return -kk_marker_unique(kk_context());
}
 
// Insert new evidence into the given evidence vector.

kk_evv_t kk_std_core_hnd_evv_insert(kk_evv_t evv, kk_std_core_hnd__ev ev, kk_context_t* _ctx) { /* forall<e,e1,a> (evv : evv<e>, ev : ev<a>) -> e evv<e1> */ 
  return kk_evv_insert(evv,ev,kk_context());
}
 
// show evidence for debug purposes

kk_string_t kk_std_core_hnd_evv_show(kk_evv_t evv, kk_context_t* _ctx) { /* forall<e> (evv : evv<e>) -> string */ 
  return kk_evv_show(evv,kk_context());
}
 
// Is an evidence vector unchanged? (i.e. as pointer equality).
// This is used to avoid copying in common cases.

bool kk_std_core_hnd_evv_eq(kk_evv_t evv0, kk_evv_t evv1, kk_context_t* _ctx) { /* forall<e> (evv0 : evv<e>, evv1 : evv<e>) -> bool */ 
  return kk_evv_eq(evv0,evv1,kk_context());
}
 
// (dynamically) find evidence insertion/deletion index in the evidence vector
// The compiler optimizes `@evv-index` to a static index when apparent from the effect type.

kk_ssize_t kk_std_core_hnd__evv_index(kk_std_core_hnd__htag htag, kk_context_t* _ctx) { /* forall<e,a> (htag : htag<a>) -> e ev-index */ 
  return kk_evv_index(htag,kk_context());
}
 
// Get the current evidence vector.

kk_evv_t kk_std_core_hnd_evv_get(kk_context_t* _ctx) { /* forall<e> () -> e evv<e> */ 
  return kk_evv_get(kk_context());
}
 
// Does the current evidence vector consist solely of affine handlers?
// This is called in backends that do not have context paths (like javascript)
// to optimize TRMC (where we can use faster update-in-place TRMC if we know the
// operations are all affine). As such, it is always safe to return `false`.
//
// control flow context:
//                 -1: none: bottom
//                   /
// 0: except: never resumes   1: linear: resumes exactly once
//                   \          /
//           2: affine: resumes never or once
//                        |
//     3: multi: resumes never, once, or multiple times
//

bool kk_std_core_hnd__evv_is_affine(kk_context_t* _ctx) { /* () -> bool */ 
  return kk_evv_is_affine(kk_context());
}
 
// Remove evidence at index `i` of the current evidence vector, and return the old one.
// (used by `mask`)

kk_evv_t kk_std_core_hnd_evv_swap_delete(kk_ssize_t i, bool behind, kk_context_t* _ctx) { /* forall<e,e1> (i : ev-index, behind : bool) -> e1 evv<e> */ 
  return kk_evv_swap_delete(i,behind,kk_context());
}
 
// Swap the current evidence vector with a new vector consisting of evidence
// at indices `indices` in the current vector.

kk_evv_t kk_std_core_hnd_evv_swap_create(kk_vector_t indices, kk_context_t* _ctx) { /* forall<e> (indices : vector<ev-index>) -> e evv<e> */ 
  return kk_evv_swap_create(indices,kk_context());
}

kk_box_t kk_std_core_hnd_yield_extend(kk_function_t next, kk_context_t* _ctx) { /* forall<a,b,e> (next : (a) -> e b) -> e b */ 
  return kk_yield_extend(next,kk_context());
}

kk_box_t kk_std_core_hnd_yield_cont(kk_function_t f, kk_context_t* _ctx) { /* forall<a,e,b> (f : forall<c> ((c) -> e a, c) -> e b) -> e b */ 
  return kk_yield_cont(f,kk_context());
}

kk_std_core_hnd__yld kk_std_core_hnd_yield_prompt(int32_t m, kk_context_t* _ctx) { /* forall<a,e,b> (m : marker<e,b>) -> yld<e,a,b> */ 
  return kk_yield_prompt(m,kk_context());
}

kk_function_t kk_std_core_hnd_yield_to_prim(int32_t m, kk_function_t clause, kk_context_t* _ctx) { /* forall<a,e,e1,b> (m : marker<e1,b>, clause : ((resume-result<a,b>) -> e1 b) -> e1 b) -> e (() -> a) */ 
  return kk_yield_to(m,clause,kk_context());
}

kk_box_t kk_std_core_hnd_yield_to_final(int32_t m, kk_function_t clause, kk_context_t* _ctx) { /* forall<a,e,e1,b> (m : marker<e1,b>, clause : ((resume-result<a,b>) -> e1 b) -> e1 b) -> e a */ 
  return kk_yield_final(m,clause,kk_context());
}


// lift anonymous function
struct kk_std_core_hnd_yield_to_fun314__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_hnd_yield_to_fun314(kk_function_t _fself, kk_box_t _b_x3, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_yield_to_fun314(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_hnd_yield_to_fun314, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_hnd_yield_to_fun314(kk_function_t _fself, kk_box_t _b_x3, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t _x_x315 = kk_function_unbox(_b_x3, _ctx); /*() -> 2786 4*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x315, (_x_x315, _ctx), _ctx);
}

kk_box_t kk_std_core_hnd_yield_to(int32_t m, kk_function_t clause, kk_context_t* _ctx) { /* forall<a,e,b> (m : marker<e,b>, clause : ((resume-result<a,b>) -> e b) -> e b) -> e a */ 
  kk_function_t g = kk_std_core_hnd_yield_to_prim(m, clause, _ctx); /*() -> 2785*/;
  kk_function_drop(g, _ctx);
  return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_yield_to_fun314(_ctx), _ctx);
}

kk_std_core_hnd__yield_info kk_std_core_hnd_yield_capture(kk_context_t* _ctx) { /* forall<e> () -> e yield-info */ 
  return kk_yield_capture(kk_context());
}

kk_box_t kk_std_core_hnd_unsafe_reyield(kk_std_core_hnd__yield_info yld, kk_context_t* _ctx) { /* forall<a,e> (yld : yield-info) -> e a */ 
  return kk_yield_reyield(yld,kk_context());
}

kk_unit_t kk_std_core_hnd_guard(kk_evv_t w, kk_context_t* _ctx) { /* forall<e> (w : evv<e>) -> e () */ 
  kk_evv_guard(w,kk_context()); return kk_Unit;
}

kk_box_t kk_std_core_hnd_resume_final(kk_context_t* _ctx) { /* forall<a> () -> a */ 
  return kk_fatal_resume_final(kk_context());
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun318__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
  kk_function_t ret;
  kk_evv_t w0;
  kk_evv_t w1;
  int32_t m;
};
static kk_box_t kk_std_core_hnd_prompt_fun318(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun318(kk_std_core_hnd__ev ev, kk_function_t ret, kk_evv_t w0, kk_evv_t w1, int32_t m, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun318__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun318__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun318, kk_context());
  _self->ev = ev;
  _self->ret = ret;
  _self->w0 = w0;
  _self->w1 = w1;
  _self->m = m;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun318(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun318__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun318__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<3484> */
  kk_function_t ret = _self->ret; /* (3482) -> 3483 3485 */
  kk_evv_t w0 = _self->w0; /* hnd/evv<3483> */
  kk_evv_t w1 = _self->w1; /* hnd/evv<3483> */
  int32_t m = _self->m; /* hnd/marker<3483,3485> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);kk_function_dup(ret, _ctx);kk_evv_dup(w0, _ctx);kk_evv_dup(w1, _ctx);kk_skip_dup(m, _ctx);}, {}, _ctx)
  kk_evv_t w0_sq_ = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3483>*/;
  kk_evv_t w1_sq_;
  bool _match_x264;
  kk_evv_t _x_x319 = kk_evv_dup(w0_sq_, _ctx); /*hnd/evv<3483>*/
  _match_x264 = kk_std_core_hnd_evv_eq(w0, _x_x319, _ctx); /*bool*/
  if (_match_x264) {
    w1_sq_ = w1; /*hnd/evv<3483>*/
  }
  else {
    kk_evv_drop(w1, _ctx);
    kk_evv_t _x_x320 = kk_evv_dup(w0_sq_, _ctx); /*hnd/evv<3483>*/
    kk_std_core_hnd__ev _x_x321 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3484>*/
    w1_sq_ = kk_std_core_hnd_evv_insert(_x_x320, _x_x321, _ctx); /*hnd/evv<3483>*/
  }
  kk_unit_t ___1 = kk_Unit;
  kk_evv_t _x_x322 = kk_evv_dup(w1_sq_, _ctx); /*hnd/evv<3483>*/
  kk_evv_set(_x_x322,kk_context());
  kk_box_t _x_x323 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*3482*/
  return kk_std_core_hnd_prompt(w0_sq_, w1_sq_, ev, m, ret, _x_x323, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun324__t {
  struct kk_function_s _base;
  kk_function_t cont_0;
  kk_std_core_hnd__ev ev;
  kk_function_t ret;
  kk_evv_t w0;
  kk_evv_t w1;
  int32_t m;
};
static kk_box_t kk_std_core_hnd_prompt_fun324(kk_function_t _fself, kk_std_core_hnd__resume_result r, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun324(kk_function_t cont_0, kk_std_core_hnd__ev ev, kk_function_t ret, kk_evv_t w0, kk_evv_t w1, int32_t m, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun324__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun324__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun324, kk_context());
  _self->cont_0 = cont_0;
  _self->ev = ev;
  _self->ret = ret;
  _self->w0 = w0;
  _self->w1 = w1;
  _self->m = m;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_prompt_fun330__t {
  struct kk_function_s _base;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_prompt_fun330(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun330(kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun330__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun330__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun330, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun330(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun330__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun330__t*, _fself, _ctx);
  kk_box_t x = _self->x; /* 3463 */
  kk_drop_match(_self, {kk_box_dup(x, _ctx);}, {}, _ctx)
  return x;
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun331__t {
  struct kk_function_s _base;
  kk_box_t x_0;
};
static kk_box_t kk_std_core_hnd_prompt_fun331(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun331(kk_box_t x_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun331__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun331__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun331, kk_context());
  _self->x_0 = x_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun331(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun331__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun331__t*, _fself, _ctx);
  kk_box_t x_0 = _self->x_0; /* 3463 */
  kk_drop_match(_self, {kk_box_dup(x_0, _ctx);}, {}, _ctx)
  return x_0;
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun337__t {
  struct kk_function_s _base;
  kk_box_t x_1_0;
  int32_t m;
};
static kk_box_t kk_std_core_hnd_prompt_fun337(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun337(kk_box_t x_1_0, int32_t m, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun337__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun337__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun337, kk_context());
  _self->x_1_0 = x_1_0;
  _self->m = m;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_prompt_fun338__t {
  struct kk_function_s _base;
  kk_box_t x_1_0;
};
static kk_box_t kk_std_core_hnd_prompt_fun338(kk_function_t _fself, kk_function_t ___wildcard_x409__85, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun338(kk_box_t x_1_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun338__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun338__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun338, kk_context());
  _self->x_1_0 = x_1_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun338(kk_function_t _fself, kk_function_t ___wildcard_x409__85, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun338__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun338__t*, _fself, _ctx);
  kk_box_t x_1_0 = _self->x_1_0; /* 3485 */
  kk_drop_match(_self, {kk_box_dup(x_1_0, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x409__85, _ctx);
  return x_1_0;
}
static kk_box_t kk_std_core_hnd_prompt_fun337(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun337__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun337__t*, _fself, _ctx);
  kk_box_t x_1_0 = _self->x_1_0; /* 3485 */
  int32_t m = _self->m; /* hnd/marker<3483,3485> */
  kk_drop_match(_self, {kk_box_dup(x_1_0, _ctx);kk_skip_dup(m, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_prompt_fun338(x_1_0, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_prompt_fun324(kk_function_t _fself, kk_std_core_hnd__resume_result r, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun324__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun324__t*, _fself, _ctx);
  kk_function_t cont_0 = _self->cont_0; /* (() -> 3463) -> 3483 3482 */
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<3484> */
  kk_function_t ret = _self->ret; /* (3482) -> 3483 3485 */
  kk_evv_t w0 = _self->w0; /* hnd/evv<3483> */
  kk_evv_t w1 = _self->w1; /* hnd/evv<3483> */
  int32_t m = _self->m; /* hnd/marker<3483,3485> */
  kk_drop_match(_self, {kk_function_dup(cont_0, _ctx);kk_std_core_hnd__ev_dup(ev, _ctx);kk_function_dup(ret, _ctx);kk_evv_dup(w0, _ctx);kk_evv_dup(w1, _ctx);kk_skip_dup(m, _ctx);}, {}, _ctx)
  if (kk_std_core_hnd__is_Deep(r, _ctx)) {
    kk_box_t x = r._cons.Deep.result;
    kk_evv_t w0_0_sq_ = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3483>*/;
    kk_evv_t w1_0_sq_;
    bool _match_x263;
    kk_evv_t _x_x325 = kk_evv_dup(w0_0_sq_, _ctx); /*hnd/evv<3483>*/
    _match_x263 = kk_std_core_hnd_evv_eq(w0, _x_x325, _ctx); /*bool*/
    if (_match_x263) {
      w1_0_sq_ = w1; /*hnd/evv<3483>*/
    }
    else {
      kk_evv_drop(w1, _ctx);
      kk_evv_t _x_x326 = kk_evv_dup(w0_0_sq_, _ctx); /*hnd/evv<3483>*/
      kk_std_core_hnd__ev _x_x327 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3484>*/
      w1_0_sq_ = kk_std_core_hnd_evv_insert(_x_x326, _x_x327, _ctx); /*hnd/evv<3483>*/
    }
    kk_unit_t ___2 = kk_Unit;
    kk_evv_t _x_x328 = kk_evv_dup(w1_0_sq_, _ctx); /*hnd/evv<3483>*/
    kk_evv_set(_x_x328,kk_context());
    kk_box_t _x_x329 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), cont_0, (cont_0, kk_std_core_hnd_new_prompt_fun330(x, _ctx), _ctx), _ctx); /*3482*/
    return kk_std_core_hnd_prompt(w0_0_sq_, w1_0_sq_, ev, m, ret, _x_x329, _ctx);
  }
  if (kk_std_core_hnd__is_Shallow(r, _ctx)) {
    kk_box_t x_0 = r._cons.Shallow.result;
    kk_evv_drop(w1, _ctx);
    kk_evv_drop(w0, _ctx);
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_box_t x_1_10002 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), cont_0, (cont_0, kk_std_core_hnd_new_prompt_fun331(x_0, _ctx), _ctx), _ctx); /*3482*/;
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_1_10002, _ctx);
      return kk_std_core_hnd_yield_extend(ret, _ctx);
    }
    {
      return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), ret, (ret, x_1_10002, _ctx), _ctx);
    }
  }
  {
    kk_box_t x_1_0 = r._cons.Finalize.result;
    kk_evv_t w0_1_sq_ = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3483>*/;
    kk_evv_t w1_1_sq_;
    bool _match_x261;
    kk_evv_t _x_x332 = kk_evv_dup(w0_1_sq_, _ctx); /*hnd/evv<3483>*/
    _match_x261 = kk_std_core_hnd_evv_eq(w0, _x_x332, _ctx); /*bool*/
    if (_match_x261) {
      w1_1_sq_ = w1; /*hnd/evv<3483>*/
    }
    else {
      kk_evv_drop(w1, _ctx);
      kk_evv_t _x_x333 = kk_evv_dup(w0_1_sq_, _ctx); /*hnd/evv<3483>*/
      kk_std_core_hnd__ev _x_x334 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3484>*/
      w1_1_sq_ = kk_std_core_hnd_evv_insert(_x_x333, _x_x334, _ctx); /*hnd/evv<3483>*/
    }
    kk_unit_t ___3 = kk_Unit;
    kk_evv_t _x_x335 = kk_evv_dup(w1_1_sq_, _ctx); /*hnd/evv<3483>*/
    kk_evv_set(_x_x335,kk_context());
    kk_box_t _x_x336 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), cont_0, (cont_0, kk_std_core_hnd_new_prompt_fun337(x_1_0, m, _ctx), _ctx), _ctx); /*3482*/
    return kk_std_core_hnd_prompt(w0_1_sq_, w1_1_sq_, ev, m, ret, _x_x336, _ctx);
  }
}

kk_box_t kk_std_core_hnd_prompt(kk_evv_t w0, kk_evv_t w1, kk_std_core_hnd__ev ev, int32_t m, kk_function_t ret, kk_box_t result, kk_context_t* _ctx) { /* forall<a,e,b,c> (w0 : evv<e>, w1 : evv<e>, ev : ev<b>, m : marker<e,c>, ret : (a) -> e c, result : a) -> e c */ 
  kk_unit_t __ = kk_Unit;
  kk_evv_t _x_x316 = kk_evv_dup(w1, _ctx); /*hnd/evv<3483>*/
  kk_std_core_hnd_guard(_x_x316, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_evv_t _x_x317 = kk_evv_dup(w0, _ctx); /*hnd/evv<3483>*/
  kk_evv_set(_x_x317,kk_context());
  kk_std_core_hnd__yld _match_x260 = kk_std_core_hnd_yield_prompt(m, _ctx); /*hnd/yld<2611,2610,2612>*/;
  if (kk_std_core_hnd__is_Pure(_match_x260, _ctx)) {
    kk_evv_drop(w1, _ctx);
    kk_evv_drop(w0, _ctx);
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), ret, (ret, result, _ctx), _ctx);
  }
  if (kk_std_core_hnd__is_YieldingFinal(_match_x260, _ctx)) {
    kk_evv_drop(w1, _ctx);
    kk_evv_drop(w0, _ctx);
    kk_function_drop(ret, _ctx);
    kk_box_drop(result, _ctx);
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return kk_box_any(kk_context());
  }
  if (kk_std_core_hnd__is_Yielding(_match_x260, _ctx)) {
    kk_box_drop(result, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_prompt_fun318(ev, ret, w0, w1, m, _ctx), _ctx);
  }
  {
    kk_function_t clause = _match_x260._cons.Yield.clause;
    kk_function_t cont_0 = _match_x260._cons.Yield.cont;
    kk_box_drop(result, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), clause, (clause, kk_std_core_hnd_new_prompt_fun324(cont_0, ev, ret, w0, w1, m, _ctx), _ctx), _ctx);
  }
}

kk_box_t kk_std_core_hnd__hhandle(kk_std_core_hnd__htag tag, kk_box_t h, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,e1,b,c> (tag : htag<b>, h : b<e,c>, ret : (a) -> e c, action : () -> e1 a) -> e c */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3613>*/;
  int32_t m = kk_std_core_hnd_fresh_marker(_ctx); /*hnd/marker<3613,3616>*/;
  kk_std_core_hnd__ev ev;
  kk_evv_t _x_x339 = kk_evv_dup(w0, _ctx); /*hnd/evv<3613>*/
  ev = kk_std_core_hnd__new_Ev(kk_reuse_null, 0, tag, m, h, _x_x339, _ctx); /*hnd/ev<3615>*/
  kk_evv_t w1;
  kk_evv_t _x_x340 = kk_evv_dup(w0, _ctx); /*hnd/evv<3613>*/
  kk_std_core_hnd__ev _x_x341 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3615>*/
  w1 = kk_std_core_hnd_evv_insert(_x_x340, _x_x341, _ctx); /*hnd/evv<3613>*/
  kk_unit_t __ = kk_Unit;
  kk_evv_t _x_x342 = kk_evv_dup(w1, _ctx); /*hnd/evv<3613>*/
  kk_evv_set(_x_x342,kk_context());
  kk_box_t _x_x343 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*3612*/
  return kk_std_core_hnd_prompt(w0, w1, ev, m, ret, _x_x343, _ctx);
}

kk_box_t kk_std_core_hnd__named_handle(kk_std_core_hnd__htag tag, kk_box_t h, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,e1,b,c> (tag : htag<b>, h : b<e,c>, ret : (a) -> e c, action : (ev<b>) -> e1 a) -> e c */ 
  int32_t m = kk_std_core_hnd_fresh_marker_named(_ctx); /*hnd/marker<3729,3732>*/;
  kk_evv_t w0 = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3729>*/;
  kk_std_core_hnd__ev ev;
  kk_evv_t _x_x344 = kk_evv_dup(w0, _ctx); /*hnd/evv<3729>*/
  ev = kk_std_core_hnd__new_Ev(kk_reuse_null, 0, tag, m, h, _x_x344, _ctx); /*hnd/ev<3731>*/
  kk_evv_t _x_x345 = kk_evv_dup(w0, _ctx); /*hnd/evv<3729>*/
  kk_std_core_hnd__ev _x_x346 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3731>*/
  kk_box_t _x_x347 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__ev, kk_context_t*), action, (action, ev, _ctx), _ctx); /*3728*/
  return kk_std_core_hnd_prompt(_x_x345, w0, _x_x346, m, ret, _x_x347, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_mask_at1_fun348__t {
  struct kk_function_s _base;
  kk_ssize_t i;
  bool behind;
};
static kk_box_t kk_std_core_hnd_mask_at1_fun348(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_mask_at1_fun348(kk_ssize_t i, bool behind, kk_context_t* _ctx) {
  struct kk_std_core_hnd_mask_at1_fun348__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_mask_at1_fun348__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_mask_at1_fun348, kk_context());
  _self->i = i;
  _self->behind = behind;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_mask_at1_fun348(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_mask_at1_fun348__t* _self = kk_function_as(struct kk_std_core_hnd_mask_at1_fun348__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  bool behind = _self->behind; /* bool */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);kk_skip_dup(behind, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(i, behind, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_mask_at1(kk_ssize_t i, bool behind, kk_function_t action, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (i : ev-index, behind : bool, action : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(i, behind, _ctx); /*hnd/evv<_3757>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), action, (action, x, _ctx), _ctx); /*3862*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_mask_at1_fun348(i, behind, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__mask_at_fun349__t {
  struct kk_function_s _base;
  kk_ssize_t i;
  bool behind;
};
static kk_box_t kk_std_core_hnd__mask_at_fun349(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_mask_at_fun349(kk_ssize_t i, bool behind, kk_context_t* _ctx) {
  struct kk_std_core_hnd__mask_at_fun349__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__mask_at_fun349__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__mask_at_fun349, kk_context());
  _self->i = i;
  _self->behind = behind;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__mask_at_fun349(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__mask_at_fun349__t* _self = kk_function_as(struct kk_std_core_hnd__mask_at_fun349__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  bool behind = _self->behind; /* bool */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);kk_skip_dup(behind, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(i, behind, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__mask_at(kk_ssize_t i, bool behind, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,e1> (i : ev-index, behind : bool, action : () -> e a) -> e1 a */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(i, behind, _ctx); /*hnd/evv<_3885>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*3974*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_mask_at_fun349(i, behind, _ctx), _ctx);
  }
  {
    return x;
  }
}


// lift anonymous function
struct kk_std_core_hnd_prompt_local_var_fun351__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_box_t v;
};
static kk_box_t kk_std_core_hnd_prompt_local_var_fun351(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_local_var_fun351(kk_ref_t loc, kk_box_t v, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_local_var_fun351__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_local_var_fun351__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_local_var_fun351, kk_context());
  _self->loc = loc;
  _self->v = v;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_local_var_fun351(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_local_var_fun351__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_local_var_fun351__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<4163,4161> */
  kk_box_t v = _self->v; /* 4161 */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);kk_box_dup(v, _ctx);}, {}, _ctx)
  kk_unit_t ___0 = kk_Unit;
  kk_ref_set_borrow(loc,v,kk_context());
  kk_box_t _x_x352 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4162*/
  return kk_std_core_hnd_prompt_local_var(loc, _x_x352, _ctx);
}

kk_box_t kk_std_core_hnd_prompt_local_var(kk_ref_t loc, kk_box_t res, kk_context_t* _ctx) { /* forall<a,b,h> (loc : local-var<h,a>, res : b) -> <div,local<h>> b */ 
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    kk_box_t v;
    kk_ref_t _x_x350 = kk_ref_dup(loc, _ctx); /*local-var<4163,4161>*/
    v = kk_ref_get(_x_x350,kk_context()); /*4161*/
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_prompt_local_var_fun351(loc, v, _ctx), _ctx);
  }
  {
    kk_ref_drop(loc, _ctx);
    return res;
  }
}


// lift anonymous function
struct kk_std_core_hnd_finally_prompt_fun354__t {
  struct kk_function_s _base;
  kk_function_t fin;
};
static kk_box_t kk_std_core_hnd_finally_prompt_fun354(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_finally_prompt_fun354(kk_function_t fin, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun354__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_finally_prompt_fun354__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_finally_prompt_fun354, kk_context());
  _self->fin = fin;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_finally_prompt_fun354(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun354__t* _self = kk_function_as(struct kk_std_core_hnd_finally_prompt_fun354__t*, _fself, _ctx);
  kk_function_t fin = _self->fin; /* () -> 4395 () */
  kk_drop_match(_self, {kk_function_dup(fin, _ctx);}, {}, _ctx)
  kk_box_t _x_x355 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4394*/
  return kk_std_core_hnd_finally_prompt(fin, _x_x355, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_finally_prompt_fun356__t {
  struct kk_function_s _base;
  kk_std_core_hnd__yield_info yld;
};
static kk_box_t kk_std_core_hnd_finally_prompt_fun356(kk_function_t _fself, kk_box_t ___wildcard_x489__43, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_finally_prompt_fun356(kk_std_core_hnd__yield_info yld, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun356__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_finally_prompt_fun356__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_finally_prompt_fun356, kk_context());
  _self->yld = yld;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_finally_prompt_fun356(kk_function_t _fself, kk_box_t ___wildcard_x489__43, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun356__t* _self = kk_function_as(struct kk_std_core_hnd_finally_prompt_fun356__t*, _fself, _ctx);
  kk_std_core_hnd__yield_info yld = _self->yld; /* hnd/yield-info */
  kk_drop_match(_self, {kk_std_core_hnd__yield_info_dup(yld, _ctx);}, {}, _ctx)
  kk_box_drop(___wildcard_x489__43, _ctx);
  return kk_std_core_hnd_unsafe_reyield(yld, _ctx);
}

kk_box_t kk_std_core_hnd_finally_prompt(kk_function_t fin, kk_box_t res, kk_context_t* _ctx) { /* forall<a,e> (fin : () -> e (), res : a) -> e a */ 
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    bool _match_x256 = kk_yielding_non_final(kk_context()); /*bool*/;
    if (_match_x256) {
      return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_finally_prompt_fun354(fin, _ctx), _ctx);
    }
    {
      kk_std_core_hnd__yield_info yld = kk_std_core_hnd_yield_capture(_ctx); /*hnd/yield-info*/;
      kk_unit_t ___0 = kk_Unit;
      kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), fin, (fin, _ctx), _ctx);
      if (kk_yielding(kk_context())) {
        return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_finally_prompt_fun356(yld, _ctx), _ctx);
      }
      {
        return kk_std_core_hnd_unsafe_reyield(yld, _ctx);
      }
    }
  }
  {
    kk_unit_t __ = kk_Unit;
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), fin, (fin, _ctx), _ctx);
    return res;
  }
}


// lift anonymous function
struct kk_std_core_hnd_initially_prompt_fun358__t {
  struct kk_function_s _base;
  kk_ref_t count;
  kk_function_t init;
};
static kk_box_t kk_std_core_hnd_initially_prompt_fun358(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_initially_prompt_fun358(kk_ref_t count, kk_function_t init, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun358__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_initially_prompt_fun358__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_initially_prompt_fun358, kk_context());
  _self->count = count;
  _self->init = init;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_initially_prompt_fun364__t {
  struct kk_function_s _base;
  kk_function_t cont;
  kk_function_t init;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_initially_prompt_fun364(kk_function_t _fself, kk_box_t ___wildcard_x530__35, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_initially_prompt_fun364(kk_function_t cont, kk_function_t init, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun364__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_initially_prompt_fun364__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_initially_prompt_fun364, kk_context());
  _self->cont = cont;
  _self->init = init;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_initially_prompt_fun364(kk_function_t _fself, kk_box_t ___wildcard_x530__35, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun364__t* _self = kk_function_as(struct kk_std_core_hnd_initially_prompt_fun364__t*, _fself, _ctx);
  kk_function_t cont = _self->cont; /* (4616) -> 4630 4629 */
  kk_function_t init = _self->init; /* (int) -> 4630 () */
  kk_box_t x = _self->x; /* 4616 */
  kk_drop_match(_self, {kk_function_dup(cont, _ctx);kk_function_dup(init, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_box_drop(___wildcard_x530__35, _ctx);
  kk_box_t _x_x365 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4629*/
  return kk_std_core_hnd_initially_prompt(init, _x_x365, _ctx);
}
static kk_box_t kk_std_core_hnd_initially_prompt_fun358(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun358__t* _self = kk_function_as(struct kk_std_core_hnd_initially_prompt_fun358__t*, _fself, _ctx);
  kk_ref_t count = _self->count; /* ref<global,int> */
  kk_function_t init = _self->init; /* (int) -> 4630 () */
  kk_drop_match(_self, {kk_ref_dup(count, _ctx);kk_function_dup(init, _ctx);}, {}, _ctx)
  kk_integer_t cnt;
  kk_box_t _x_x359;
  kk_ref_t _x_x360 = kk_ref_dup(count, _ctx); /*ref<global,int>*/
  _x_x359 = kk_ref_get(_x_x360,kk_context()); /*212*/
  cnt = kk_integer_unbox(_x_x359, _ctx); /*int*/
  kk_integer_t _b_x14_16;
  kk_integer_t _x_x361 = kk_integer_dup(cnt, _ctx); /*int*/
  _b_x14_16 = kk_integer_add(_x_x361,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x255 = kk_Unit;
  kk_ref_set_borrow(count,(kk_integer_box(_b_x14_16, _ctx)),kk_context());
  kk_ref_drop(count, _ctx);
  _brw_x255;
  kk_unit_t ___1 = kk_Unit;
  bool _match_x253 = kk_integer_eq_borrow(cnt,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x253) {
    kk_integer_drop(cnt, _ctx);
  }
  else {
    kk_unit_t r = kk_Unit;
    kk_function_t _x_x362 = kk_function_dup(init, _ctx); /*(int) -> 4630 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x362, (_x_x362, cnt, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t ___0;
      kk_function_t _x_x363;
      kk_function_dup(cont, _ctx);
      kk_function_dup(init, _ctx);
      kk_box_dup(x, _ctx);
      _x_x363 = kk_std_core_hnd_new_initially_prompt_fun364(cont, init, x, _ctx); /*(_4563) -> 4630 4629*/
      ___0 = kk_std_core_hnd_yield_extend(_x_x363, _ctx); /*4629*/
      kk_box_drop(___0, _ctx);
    }
    else {
      
    }
  }
  kk_box_t _x_x366 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4629*/
  return kk_std_core_hnd_initially_prompt(init, _x_x366, _ctx);
}

kk_box_t kk_std_core_hnd_initially_prompt(kk_function_t init, kk_box_t res, kk_context_t* _ctx) { /* forall<a,e> (init : (int) -> e (), res : a) -> e a */ 
  bool _match_x252 = kk_yielding_non_final(kk_context()); /*bool*/;
  if (_match_x252) {
    kk_box_drop(res, _ctx);
    kk_ref_t count = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*ref<global,int>*/;
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_initially_prompt_fun358(count, init, _ctx), _ctx);
  }
  {
    kk_function_drop(init, _ctx);
    return res;
  }
}


// lift anonymous function
struct kk_std_core_hnd_initially_fun368__t {
  struct kk_function_s _base;
  kk_function_t action;
  kk_function_t init;
};
static kk_box_t kk_std_core_hnd_initially_fun368(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_initially_fun368(kk_function_t action, kk_function_t init, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_fun368__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_initially_fun368__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_initially_fun368, kk_context());
  _self->action = action;
  _self->init = init;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_initially_fun368(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_fun368__t* _self = kk_function_as(struct kk_std_core_hnd_initially_fun368__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* () -> 4695 4694 */
  kk_function_t init = _self->init; /* (int) -> 4695 () */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);kk_function_dup(init, _ctx);}, {}, _ctx)
  kk_box_drop(_b_x18, _ctx);
  kk_box_t _x_x369 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*4694*/
  return kk_std_core_hnd_initially_prompt(init, _x_x369, _ctx);
}

kk_box_t kk_std_core_hnd_initially(kk_function_t init, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (init : (int) -> e (), action : () -> e a) -> e a */ 
  kk_unit_t __ = kk_Unit;
  kk_function_t _x_x367 = kk_function_dup(init, _ctx); /*(int) -> 4695 ()*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x367, (_x_x367, kk_integer_from_small(0), _ctx), _ctx);
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_initially_fun368(action, init, _ctx), _ctx);
  }
  {
    kk_box_t _x_x370 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*4694*/
    return kk_std_core_hnd_initially_prompt(init, _x_x370, _ctx);
  }
}


// lift anonymous function
struct kk_std_core_hnd_resume_context_fs__copy_fun372__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x24;
};
static kk_box_t kk_std_core_hnd_resume_context_fs__copy_fun372(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x27, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_resume_context_fs__new_copy_fun372(kk_box_t _fun_unbox_x24, kk_context_t* _ctx) {
  struct kk_std_core_hnd_resume_context_fs__copy_fun372__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_resume_context_fs__copy_fun372__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_resume_context_fs__copy_fun372, kk_context());
  _self->_fun_unbox_x24 = _fun_unbox_x24;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_resume_context_fs__copy_fun372(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x27, kk_context_t* _ctx) {
  struct kk_std_core_hnd_resume_context_fs__copy_fun372__t* _self = kk_function_as(struct kk_std_core_hnd_resume_context_fs__copy_fun372__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x24 = _self->_fun_unbox_x24; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x24, _ctx);}, {}, _ctx)
  kk_function_t _x_x373 = kk_function_unbox(_fun_unbox_x24, _ctx); /*(25) -> 4814 26*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x373, (_x_x373, kk_std_core_hnd__resume_result_box(_b_x27, _ctx), _ctx), _ctx);
}

kk_std_core_hnd__resume_context kk_std_core_hnd_resume_context_fs__copy(kk_std_core_hnd__resume_context _this, kk_std_core_types__optional k, kk_context_t* _ctx) { /* forall<a,e,e1,b> (resume-context<a,e,e1,b>, k : ? ((resume-result<a,b>) -> e b)) -> resume-context<a,e,e1,b> */ 
  kk_function_t _x_x371;
  if (kk_std_core_types__is_Optional(k, _ctx)) {
    kk_box_t _fun_unbox_x24 = k._cons._Optional.value;
    kk_box_dup(_fun_unbox_x24, _ctx);
    kk_std_core_types__optional_drop(k, _ctx);
    kk_std_core_hnd__resume_context_drop(_this, _ctx);
    _x_x371 = kk_std_core_hnd_resume_context_fs__new_copy_fun372(_fun_unbox_x24, _ctx); /*(hnd/resume-result<4813,4816>) -> 4814 26*/
  }
  else {
    kk_std_core_types__optional_drop(k, _ctx);
    {
      kk_function_t _x = _this.k;
      _x_x371 = _x; /*(hnd/resume-result<4813,4816>) -> 4814 26*/
    }
  }
  return kk_std_core_hnd__new_Resume_context(_x_x371, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause1_fs__copy_fun378__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x35;
};
static kk_box_t kk_std_core_hnd_clause1_fs__copy_fun378(kk_function_t _fself, int32_t _b_x40, kk_std_core_hnd__ev _b_x41, kk_box_t _b_x42, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_clause1_fs__new_copy_fun378(kk_box_t _fun_unbox_x35, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause1_fs__copy_fun378__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause1_fs__copy_fun378__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause1_fs__copy_fun378, kk_context());
  _self->_fun_unbox_x35 = _fun_unbox_x35;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause1_fs__copy_fun378(kk_function_t _fself, int32_t _b_x40, kk_std_core_hnd__ev _b_x41, kk_box_t _b_x42, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause1_fs__copy_fun378__t* _self = kk_function_as(struct kk_std_core_hnd_clause1_fs__copy_fun378__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x35 = _self->_fun_unbox_x35; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x35, _ctx);}, {}, _ctx)
  kk_function_t _x_x379 = kk_function_unbox(_fun_unbox_x35, _ctx); /*(36, 37, 38) -> 5180 39*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), _x_x379, (_x_x379, kk_int32_box(_b_x40, _ctx), kk_std_core_hnd__ev_box(_b_x41, _ctx), _b_x42, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause1_fs__copy(kk_std_core_hnd__clause1 _this, kk_std_core_types__optional clause, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (clause1<a,b,c,e,d>, clause : ? ((marker<e,d>, ev<c>, a) -> e b)) -> clause1<a,b,c,e,d> */ 
  kk_function_t _x_x377;
  if (kk_std_core_types__is_Optional(clause, _ctx)) {
    kk_box_t _fun_unbox_x35 = clause._cons._Optional.value;
    kk_box_dup(_fun_unbox_x35, _ctx);
    kk_std_core_types__optional_drop(clause, _ctx);
    kk_std_core_hnd__clause1_drop(_this, _ctx);
    _x_x377 = kk_std_core_hnd_clause1_fs__new_copy_fun378(_fun_unbox_x35, _ctx); /*(hnd/marker<5180,5181>, hnd/ev<5179>, 5177) -> 5180 39*/
  }
  else {
    kk_std_core_types__optional_drop(clause, _ctx);
    {
      kk_function_t _x = _this.clause;
      _x_x377 = _x; /*(hnd/marker<5180,5181>, hnd/ev<5179>, 5177) -> 5180 39*/
    }
  }
  return kk_std_core_hnd__new_Clause1(_x_x377, _ctx);
}

kk_evv_t kk_std_core_hnd_evv_swap_with(kk_std_core_hnd__ev ev, kk_context_t* _ctx) { /* forall<a,e> (ev : ev<a>) -> evv<e> */ 
  kk_evv_t _x_x381;
  {
    struct kk_std_core_hnd_Ev* _con_x382 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_std_core_hnd__htag _pat_0 = _con_x382->htag;
    kk_box_t _pat_2 = _con_x382->hnd;
    kk_evv_t w = _con_x382->hevv;
    if kk_likely(kk_datatype_ptr_is_unique(ev, _ctx)) {
      kk_box_drop(_pat_2, _ctx);
      kk_std_core_hnd__htag_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(ev, _ctx);
    }
    else {
      kk_evv_dup(w, _ctx);
      kk_datatype_ptr_decref(ev, _ctx);
    }
    _x_x381 = w; /*hnd/evv<5330>*/
  }
  return kk_evv_swap(_x_x381,kk_context());
}
 
// extra under1x to make under1 inlineable


// lift anonymous function
struct kk_std_core_hnd_under1x_fun385__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under1x_fun385(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under1x_fun385(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under1x_fun385__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under1x_fun385__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under1x_fun385, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under1x_fun385(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under1x_fun385__t* _self = kk_function_as(struct kk_std_core_hnd_under1x_fun385__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<5453> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_under1x(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,c> (ev : ev<c>, op : (a) -> e b, x : a) -> e b */ 
  kk_evv_t w0;
  kk_evv_t _x_x383;
  {
    struct kk_std_core_hnd_Ev* _con_x384 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x384->hevv;
    kk_evv_dup(w, _ctx);
    _x_x383 = w; /*hnd/evv<5330>*/
  }
  w0 = kk_evv_swap(_x_x383,kk_context()); /*hnd/evv<_5364>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx); /*5451*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under1x_fun385(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}
extern kk_box_t kk_std_core_hnd_under1_fun388(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under1_fun388__t* _self = kk_function_as(struct kk_std_core_hnd_under1_fun388__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<5566> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont, res, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw1_fun389__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw1_fun389(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x597__16, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw1_fun389(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun389__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw1_fun389__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw1_fun389, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw1_fun390__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_clause_control_raw1_fun390(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw1_fun390(kk_function_t op, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun390__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw1_fun390__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw1_fun390, kk_context());
  _self->op = op;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw1_fun390(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun390__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw1_fun390__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x : 5664, r : hnd/resume-context<5665,5666,5667,5669>) -> 5666 5669 */
  kk_box_t x = _self->x; /* 5664 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_std_core_hnd__resume_context _x_x391 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, x, _x_x391, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control_raw1_fun389(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x597__16, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun389__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw1_fun389__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x : 5664, r : hnd/resume-context<5665,5666,5667,5669>) -> 5666 5669 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x597__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control_raw1_fun390(op, x, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control_raw1(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,e,e1,c,d> (op : (x : a, r : resume-context<b,e,e1,d>) -> e d) -> clause1<a,b,c,e,d> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control_raw1_fun389(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_protect_prompt_fun394__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_protect_prompt_fun394(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect_prompt_fun394(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_prompt_fun394__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect_prompt_fun394__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect_prompt_fun394, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect_prompt_fun394(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_prompt_fun394__t* _self = kk_function_as(struct kk_std_core_hnd_protect_prompt_fun394__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<5916,5918>) -> 5917 5918 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_box_t _x_x395 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*5918*/
  return kk_std_core_hnd_protect_prompt(resumed, k, _x_x395, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_protect_prompt_fun397__t {
  struct kk_function_s _base;
  kk_std_core_hnd__yield_info yld;
};
static kk_box_t kk_std_core_hnd_protect_prompt_fun397(kk_function_t _fself, kk_box_t ___wildcard_x620__43, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect_prompt_fun397(kk_std_core_hnd__yield_info yld, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_prompt_fun397__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect_prompt_fun397__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect_prompt_fun397, kk_context());
  _self->yld = yld;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect_prompt_fun397(kk_function_t _fself, kk_box_t ___wildcard_x620__43, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_prompt_fun397__t* _self = kk_function_as(struct kk_std_core_hnd_protect_prompt_fun397__t*, _fself, _ctx);
  kk_std_core_hnd__yield_info yld = _self->yld; /* hnd/yield-info */
  kk_drop_match(_self, {kk_std_core_hnd__yield_info_dup(yld, _ctx);}, {}, _ctx)
  kk_box_drop(___wildcard_x620__43, _ctx);
  return kk_std_core_hnd_unsafe_reyield(yld, _ctx);
}

kk_box_t kk_std_core_hnd_protect_prompt(kk_ref_t resumed, kk_function_t k, kk_box_t res, kk_context_t* _ctx) { /* forall<a,e,b> (resumed : ref<global,bool>, k : (resume-result<a,b>) -> e b, res : b) -> e b */ 
  bool did_resume;
  kk_box_t _x_x392;
  kk_ref_t _x_x393 = kk_ref_dup(resumed, _ctx); /*ref<global,bool>*/
  _x_x392 = kk_ref_get(_x_x393,kk_context()); /*212*/
  did_resume = kk_bool_unbox(_x_x392); /*bool*/
  if (did_resume) {
    kk_ref_drop(resumed, _ctx);
    kk_function_drop(k, _ctx);
    return res;
  }
  if (kk_yielding(kk_context())) {
    bool _match_x246 = kk_yielding_non_final(kk_context()); /*bool*/;
    if (_match_x246) {
      kk_box_drop(res, _ctx);
      return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_protect_prompt_fun394(k, resumed, _ctx), _ctx);
    }
    {
      kk_ref_drop(resumed, _ctx);
      kk_std_core_hnd__yield_info yld = kk_std_core_hnd_yield_capture(_ctx); /*hnd/yield-info*/;
      kk_box_t __;
      kk_std_core_hnd__resume_result _x_x396 = kk_std_core_hnd__new_Finalize(res, _ctx); /*hnd/resume-result<74,75>*/
      __ = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x396, _ctx), _ctx); /*5918*/
      kk_box_drop(__, _ctx);
      if (kk_yielding(kk_context())) {
        return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_protect_prompt_fun397(yld, _ctx), _ctx);
      }
      {
        return kk_std_core_hnd_unsafe_reyield(yld, _ctx);
      }
    }
  }
  {
    kk_ref_drop(resumed, _ctx);
    kk_std_core_hnd__resume_result _x_x398 = kk_std_core_hnd__new_Finalize(res, _ctx); /*hnd/resume-result<74,75>*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x398, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_core_hnd_protect_fun400__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_protect_fun400(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect_fun400(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_fun400__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect_fun400__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect_fun400, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect_fun400(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_fun400__t* _self = kk_function_as(struct kk_std_core_hnd_protect_fun400__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<6036,6038>) -> 6037 6038 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x245 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x245;
  kk_std_core_hnd__resume_result _x_x401 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x401, _ctx), _ctx);
}

kk_box_t kk_std_core_hnd_protect(kk_box_t x, kk_function_t clause, kk_function_t k, kk_context_t* _ctx) { /* forall<a,b,e,c> (x : a, clause : (x : a, k : (b) -> e c) -> e c, k : (resume-result<b,c>) -> e c) -> e c */ 
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_function_t _x_x399;
  kk_function_dup(k, _ctx);
  kk_ref_dup(resumed, _ctx);
  _x_x399 = kk_std_core_hnd_new_protect_fun400(k, resumed, _ctx); /*(ret : 6036) -> 6037 6038*/
  res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_function_t, kk_context_t*), clause, (clause, x, _x_x399, _ctx), _ctx); /*6038*/
  return kk_std_core_hnd_protect_prompt(resumed, k, res, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_control1_fun403(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control1_fun403__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control1_fun403__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x : 6128, k : (6129) -> 6130 6132) -> 6130 6132 */
  kk_box_t x = _self->x; /* 6128 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_protect(x, clause, k, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_control1_fun402(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x638__16, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control1_fun402__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control1_fun402__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x : 6128, k : (6129) -> 6130 6132) -> 6130 6132 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x638__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control1_fun403(clause, x, _ctx), _ctx);
}
 
// tail-resumptive clause: resumes exactly once at the end
// (these can be executed 'in-place' without capturing a resumption)


// lift anonymous function
struct kk_std_core_hnd_clause_tail1_fun404__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail1_fun404(kk_function_t _fself, int32_t ___wildcard_x643__14, kk_std_core_hnd__ev ev, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail1_fun404(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun404__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail1_fun404__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail1_fun404, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail1_fun407__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_clause_tail1_fun407(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail1_fun407(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun407__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail1_fun407__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail1_fun407, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail1_fun407(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun407__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail1_fun407__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6215> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail1_fun404(kk_function_t _fself, int32_t ___wildcard_x643__14, kk_std_core_hnd__ev ev, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun404__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail1_fun404__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (6216) -> 6213 6217 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x405;
  {
    struct kk_std_core_hnd_Ev* _con_x406 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x406->hevv;
    kk_evv_dup(w, _ctx);
    _x_x405 = w; /*hnd/evv<5330>*/
  }
  w0 = kk_evv_swap(_x_x405,kk_context()); /*hnd/evv<_5477>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx); /*6217*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail1_fun407(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail1(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d> (op : (c) -> e d) -> clause1<c,d,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail1_fun404(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop1_fun408(kk_function_t _fself, int32_t ___wildcard_x648__14, kk_std_core_hnd__ev ___wildcard_x648__17, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop1_fun408__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop1_fun408__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (6287) -> 6284 6288 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x648__17, (KK_I32(3)), _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx);
}
 
// clause that never resumes (e.g. an exception handler)
// (these do not need to capture a resumption and execute finally clauses upfront)


// lift anonymous function
struct kk_std_core_hnd_clause_never1_fun409__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never1_fun409(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never1_fun409(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun409__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never1_fun409__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never1_fun409, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never1_fun410__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_clause_never1_fun410(kk_function_t _fself, kk_function_t ___wildcard_x653__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never1_fun410(kk_function_t op, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun410__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never1_fun410__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never1_fun410, kk_context());
  _self->op = op;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never1_fun410(kk_function_t _fself, kk_function_t ___wildcard_x653__45, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun410__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never1_fun410__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (6371) -> 6373 6375 */
  kk_box_t x = _self->x; /* 6371 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x653__45, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_never1_fun409(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun409__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never1_fun409__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (6371) -> 6373 6375 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_clause_never1_fun410(op, x, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never1(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,e,c,d> (op : (a) -> e d) -> clause1<a,b,c,e,d> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_never1_fun409(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause0_fs__copy_fun412__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x58;
};
static kk_box_t kk_std_core_hnd_clause0_fs__copy_fun412(kk_function_t _fself, int32_t _b_x62, kk_std_core_hnd__ev _b_x63, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_clause0_fs__new_copy_fun412(kk_box_t _fun_unbox_x58, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause0_fs__copy_fun412__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause0_fs__copy_fun412__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause0_fs__copy_fun412, kk_context());
  _self->_fun_unbox_x58 = _fun_unbox_x58;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause0_fs__copy_fun412(kk_function_t _fself, int32_t _b_x62, kk_std_core_hnd__ev _b_x63, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause0_fs__copy_fun412__t* _self = kk_function_as(struct kk_std_core_hnd_clause0_fs__copy_fun412__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x58 = _self->_fun_unbox_x58; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x58, _ctx);}, {}, _ctx)
  kk_function_t _x_x413 = kk_function_unbox(_fun_unbox_x58, _ctx); /*(59, 60) -> 6505 61*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x413, (_x_x413, kk_int32_box(_b_x62, _ctx), kk_std_core_hnd__ev_box(_b_x63, _ctx), _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause0_fs__copy(kk_std_core_hnd__clause0 _this, kk_std_core_types__optional clause, kk_context_t* _ctx) { /* forall<a,b,e,c> (clause0<a,b,e,c>, clause : ? ((marker<e,c>, ev<b>) -> e a)) -> clause0<a,b,e,c> */ 
  kk_function_t _x_x411;
  if (kk_std_core_types__is_Optional(clause, _ctx)) {
    kk_box_t _fun_unbox_x58 = clause._cons._Optional.value;
    kk_box_dup(_fun_unbox_x58, _ctx);
    kk_std_core_types__optional_drop(clause, _ctx);
    kk_std_core_hnd__clause0_drop(_this, _ctx);
    _x_x411 = kk_std_core_hnd_clause0_fs__new_copy_fun412(_fun_unbox_x58, _ctx); /*(hnd/marker<6505,6506>, hnd/ev<6504>) -> 6505 61*/
  }
  else {
    kk_std_core_types__optional_drop(clause, _ctx);
    {
      kk_function_t _x = _this.clause;
      _x_x411 = _x; /*(hnd/marker<6505,6506>, hnd/ev<6504>) -> 6505 61*/
    }
  }
  return kk_std_core_hnd__new_Clause0(_x_x411, _ctx);
}
extern kk_box_t kk_std_core_hnd_under0_fun420(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under0_fun420__t* _self = kk_function_as(struct kk_std_core_hnd_under0_fun420__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6697> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
extern kk_box_t kk_std_core_hnd_under0_fun417(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under0_fun417__t* _self = kk_function_as(struct kk_std_core_hnd_under0_fun417__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6697> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x418;
  {
    struct kk_std_core_hnd_Ev* _con_x419 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x419->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x418 = w_0; /*hnd/evv<5330>*/
  }
  w0_0 = kk_evv_swap(_x_x418,kk_context()); /*hnd/evv<_5477>*/
  kk_box_t y_0 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*6695*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y_0, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under0_fun420(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y_0;
  }
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw0_fun421__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw0_fun421(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x679__16, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw0_fun421(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun421__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw0_fun421__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw0_fun421, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw0_fun422__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw0_fun422(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw0_fun422(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun422__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw0_fun422__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw0_fun422, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw0_fun422(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun422__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw0_fun422__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (hnd/resume-context<6783,6784,6785,6787>) -> 6784 6787 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_std_core_hnd__resume_context _x_x423 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, _x_x423, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control_raw0_fun421(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x679__16, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun421__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw0_fun421__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (hnd/resume-context<6783,6784,6785,6787>) -> 6784 6787 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x679__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control_raw0_fun422(op, _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_control_raw0(kk_function_t op, kk_context_t* _ctx) { /* forall<a,e,e1,b,c> (op : (resume-context<a,e,e1,c>) -> e c) -> clause0<a,b,e,c> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_control_raw0_fun421(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control0_fun424__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control0_fun424(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x687__16, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control0_fun424(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun424__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control0_fun424__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control0_fun424, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control0_fun425__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control0_fun425(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control0_fun425(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun425__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control0_fun425__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control0_fun425, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control0_fun427__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control0_fun427(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control0_fun427(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun427__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control0_fun427__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control0_fun427, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control0_fun427(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun427__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control0_fun427__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<6876,6879>) -> 6877 6879 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x240 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x240;
  kk_std_core_hnd__resume_result _x_x428 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x428, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control0_fun425(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun425__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control0_fun425__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* ((6876) -> 6877 6879) -> 6877 6879 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_function_t _x_x426;
  kk_function_dup(k, _ctx);
  kk_ref_dup(resumed, _ctx);
  _x_x426 = kk_std_core_hnd_new_clause_control0_fun427(k, resumed, _ctx); /*(ret : 6876) -> 6877 6879*/
  res = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), op, (op, _x_x426, _ctx), _ctx); /*6879*/
  return kk_std_core_hnd_protect_prompt(resumed, k, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control0_fun424(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x687__16, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun424__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control0_fun424__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* ((6876) -> 6877 6879) -> 6877 6879 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x687__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control0_fun425(op, _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_control0(kk_function_t op, kk_context_t* _ctx) { /* forall<a,e,b,c> (op : ((a) -> e c) -> e c) -> clause0<a,b,e,c> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_control0_fun424(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail0_fun429__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail0_fun429(kk_function_t _fself, int32_t ___wildcard_x691__14, kk_std_core_hnd__ev ev, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail0_fun429(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun429__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail0_fun429__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail0_fun429, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail0_fun432__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_clause_tail0_fun432(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail0_fun432(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun432__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail0_fun432__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail0_fun432, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail0_fun435__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_clause_tail0_fun435(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail0_fun435(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun435__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail0_fun435__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail0_fun435, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail0_fun435(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun435__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail0_fun435__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6947> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail0_fun432(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun432__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail0_fun432__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6947> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x433;
  {
    struct kk_std_core_hnd_Ev* _con_x434 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x434->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x433 = w_0; /*hnd/evv<5330>*/
  }
  w0_0 = kk_evv_swap(_x_x433,kk_context()); /*hnd/evv<_5477>*/
  kk_box_t y_0 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*6948*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y_0, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail0_fun435(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y_0;
  }
}
static kk_box_t kk_std_core_hnd_clause_tail0_fun429(kk_function_t _fself, int32_t ___wildcard_x691__14, kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun429__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail0_fun429__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 6945 6948 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x430;
  {
    struct kk_std_core_hnd_Ev* _con_x431 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x431->hevv;
    kk_evv_dup(w, _ctx);
    _x_x430 = w; /*hnd/evv<5330>*/
  }
  w0 = kk_evv_swap(_x_x430,kk_context()); /*hnd/evv<_6621>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), op, (op, _ctx), _ctx); /*6948*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail0_fun432(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return y;
  }
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_tail0(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c> (op : () -> e c) -> clause0<c,b,e,a> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_tail0_fun429(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop0_fun436(kk_function_t _fself, int32_t ___wildcard_x694__14, kk_std_core_hnd__ev ___wildcard_x694__17, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop0_fun436__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop0_fun436__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 7003 7006 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x694__17, (KK_I32(3)), _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), op, (op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_value_fun437(kk_function_t _fself, int32_t ___wildcard_x697__14, kk_std_core_hnd__ev ___wildcard_x697__17, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_value_fun437__t* _self = kk_function_as(struct kk_std_core_hnd_clause_value_fun437__t*, _fself, _ctx);
  kk_box_t v = _self->v; /* 7060 */
  kk_drop_match(_self, {kk_box_dup(v, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x697__17, (KK_I32(3)), _ctx);
  return v;
}


// lift anonymous function
struct kk_std_core_hnd_clause_never0_fun438__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never0_fun438(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x700__16, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never0_fun438(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun438__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never0_fun438__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never0_fun438, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never0_fun439__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never0_fun439(kk_function_t _fself, kk_function_t ___wildcard_x700__43, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never0_fun439(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun439__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never0_fun439__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never0_fun439, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never0_fun439(kk_function_t _fself, kk_function_t ___wildcard_x700__43, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun439__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never0_fun439__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 7135 7137 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x700__43, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), op, (op, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_never0_fun438(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x700__16, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun438__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never0_fun438__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 7135 7137 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x700__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_clause_never0_fun439(op, _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_never0(kk_function_t op, kk_context_t* _ctx) { /* forall<a,e,b,c> (op : () -> e c) -> clause0<a,b,e,c> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_never0_fun438(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause2_fs__copy_fun441__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x79;
};
static kk_box_t kk_std_core_hnd_clause2_fs__copy_fun441(kk_function_t _fself, int32_t _b_x85, kk_std_core_hnd__ev _b_x86, kk_box_t _b_x87, kk_box_t _b_x88, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_clause2_fs__new_copy_fun441(kk_box_t _fun_unbox_x79, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause2_fs__copy_fun441__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause2_fs__copy_fun441__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause2_fs__copy_fun441, kk_context());
  _self->_fun_unbox_x79 = _fun_unbox_x79;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause2_fs__copy_fun441(kk_function_t _fself, int32_t _b_x85, kk_std_core_hnd__ev _b_x86, kk_box_t _b_x87, kk_box_t _b_x88, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause2_fs__copy_fun441__t* _self = kk_function_as(struct kk_std_core_hnd_clause2_fs__copy_fun441__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x79 = _self->_fun_unbox_x79; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x79, _ctx);}, {}, _ctx)
  kk_function_t _x_x442 = kk_function_unbox(_fun_unbox_x79, _ctx); /*(80, 81, 82, 83) -> 7310 84*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), _x_x442, (_x_x442, kk_int32_box(_b_x85, _ctx), kk_std_core_hnd__ev_box(_b_x86, _ctx), _b_x87, _b_x88, _ctx), _ctx);
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause2_fs__copy(kk_std_core_hnd__clause2 _this, kk_std_core_types__optional clause, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (clause2<a,b,c,d,e,a1>, clause : ? ((marker<e,a1>, ev<d>, a, b) -> e c)) -> clause2<a,b,c,d,e,a1> */ 
  kk_function_t _x_x440;
  if (kk_std_core_types__is_Optional(clause, _ctx)) {
    kk_box_t _fun_unbox_x79 = clause._cons._Optional.value;
    kk_box_dup(_fun_unbox_x79, _ctx);
    kk_std_core_types__optional_drop(clause, _ctx);
    kk_std_core_hnd__clause2_drop(_this, _ctx);
    _x_x440 = kk_std_core_hnd_clause2_fs__new_copy_fun441(_fun_unbox_x79, _ctx); /*(hnd/marker<7310,7311>, hnd/ev<7309>, 7306, 7307) -> 7310 84*/
  }
  else {
    kk_std_core_types__optional_drop(clause, _ctx);
    {
      kk_function_t _x = _this.clause;
      _x_x440 = _x; /*(hnd/marker<7310,7311>, hnd/ev<7309>, 7306, 7307) -> 7310 84*/
    }
  }
  return kk_std_core_hnd__new_Clause2(_x_x440, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_under2_fun445__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under2_fun445(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under2_fun445(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun445__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under2_fun445__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under2_fun445, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_under2_fun448__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under2_fun448(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under2_fun448(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun448__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under2_fun448__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under2_fun448, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under2_fun448(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun448__t* _self = kk_function_as(struct kk_std_core_hnd_under2_fun448__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<7431> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_under2_fun445(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun445__t* _self = kk_function_as(struct kk_std_core_hnd_under2_fun445__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<7431> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x446;
  {
    struct kk_std_core_hnd_Ev* _con_x447 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x447->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x446 = w_0; /*hnd/evv<5330>*/
  }
  w0_0 = kk_evv_swap(_x_x446,kk_context()); /*hnd/evv<_5477>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*7429*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under2_fun448(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y;
  }
}

kk_box_t kk_std_core_hnd_under2(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (ev : ev<d>, op : (a, b) -> e c, x1 : a, x2 : b) -> e c */ 
  kk_evv_t w0;
  kk_evv_t _x_x443;
  {
    struct kk_std_core_hnd_Ev* _con_x444 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x444->hevv;
    kk_evv_dup(w, _ctx);
    _x_x443 = w; /*hnd/evv<5330>*/
  }
  w0 = kk_evv_swap(_x_x443,kk_context()); /*hnd/evv<_7343>*/
  kk_box_t z = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, _ctx), _ctx); /*7429*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(z, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under2_fun445(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return z;
  }
}


// lift anonymous function
struct kk_std_core_hnd_protect2_fun450__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_protect2_fun450(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect2_fun450(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect2_fun450__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect2_fun450__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect2_fun450, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect2_fun450(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect2_fun450__t* _self = kk_function_as(struct kk_std_core_hnd_protect2_fun450__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<7562,7564>) -> 7563 7564 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x235 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x235;
  kk_std_core_hnd__resume_result _x_x451 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x451, _ctx), _ctx);
}

kk_box_t kk_std_core_hnd_protect2(kk_box_t x1, kk_box_t x2, kk_function_t clause, kk_function_t k, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (x1 : a, x2 : b, clause : (x : a, x : b, k : (c) -> e d) -> e d, k : (resume-result<c,d>) -> e d) -> e d */ 
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_function_t _x_x449;
  kk_function_dup(k, _ctx);
  kk_ref_dup(resumed, _ctx);
  _x_x449 = kk_std_core_hnd_new_protect2_fun450(k, resumed, _ctx); /*(ret : 7562) -> 7563 7564*/
  res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_function_t, kk_context_t*), clause, (clause, x1, x2, _x_x449, _ctx), _ctx); /*7564*/
  return kk_std_core_hnd_protect_prompt(resumed, k, res, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_control2_fun453(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control2_fun453__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control2_fun453__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x1 : 7669, x2 : 7670, k : (7671) -> 7672 7674) -> 7672 7674 */
  kk_box_t x1 = _self->x1; /* 7669 */
  kk_box_t x2 = _self->x2; /* 7670 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);kk_box_dup(x1, _ctx);kk_box_dup(x2, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_protect2(x1, x2, clause, k, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_control2_fun452(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x725__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control2_fun452__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control2_fun452__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x1 : 7669, x2 : 7670, k : (7671) -> 7672 7674) -> 7672 7674 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x725__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control2_fun453(clause, x1, x2, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw2_fun454__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw2_fun454(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x729__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw2_fun454(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun454__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw2_fun454__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw2_fun454, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw2_fun455__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x1;
  kk_box_t x2;
};
static kk_box_t kk_std_core_hnd_clause_control_raw2_fun455(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw2_fun455(kk_function_t op, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun455__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw2_fun455__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw2_fun455, kk_context());
  _self->op = op;
  _self->x1 = x1;
  _self->x2 = x2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw2_fun455(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun455__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw2_fun455__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 7788, x2 : 7789, r : hnd/resume-context<7790,7791,7792,7794>) -> 7791 7794 */
  kk_box_t x1 = _self->x1; /* 7788 */
  kk_box_t x2 = _self->x2; /* 7789 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x1, _ctx);kk_box_dup(x2, _ctx);}, {}, _ctx)
  kk_std_core_hnd__resume_context _x_x456 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, x1, x2, _x_x456, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control_raw2_fun454(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x729__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun454__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw2_fun454__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 7788, x2 : 7789, r : hnd/resume-context<7790,7791,7792,7794>) -> 7791 7794 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x729__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control_raw2_fun455(op, x1, x2, _ctx), _ctx);
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause_control_raw2(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,e,e1,d,a1> (op : (x1 : a, x2 : b, r : resume-context<c,e,e1,a1>) -> e a1) -> clause2<a,b,c,d,e,a1> */ 
  return kk_std_core_hnd__new_Clause2(kk_std_core_hnd_new_clause_control_raw2_fun454(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail2_fun457(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail2_fun457__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail2_fun457__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (7896, 7897) -> 7893 7898 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under2(ev, op, x1, x2, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop2_fun458(kk_function_t _fself, int32_t ___wildcard_x735__14, kk_std_core_hnd__ev ___wildcard_x735__17, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop2_fun458__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop2_fun458__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (7980, 7981) -> 7977 7982 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x735__17, (KK_I32(3)), _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_never2_fun460__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never2_fun460(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x743__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never2_fun460(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun460__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never2_fun460__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never2_fun460, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never2_fun461__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x1;
  kk_box_t x2;
};
static kk_box_t kk_std_core_hnd_clause_never2_fun461(kk_function_t _fself, kk_function_t ___wildcard_x743__49, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never2_fun461(kk_function_t op, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun461__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never2_fun461__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never2_fun461, kk_context());
  _self->op = op;
  _self->x1 = x1;
  _self->x2 = x2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never2_fun461(kk_function_t _fself, kk_function_t ___wildcard_x743__49, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun461__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never2_fun461__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8198, 8199) -> 8201 8203 */
  kk_box_t x1 = _self->x1; /* 8198 */
  kk_box_t x2 = _self->x2; /* 8199 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x1, _ctx);kk_box_dup(x2, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x743__49, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_never2_fun460(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x743__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun460__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never2_fun460__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8198, 8199) -> 8201 8203 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x743__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_clause_never2_fun461(op, x1, x2, _ctx), _ctx);
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause_never2(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,e,d,a1> (op : (a, b) -> e a1) -> clause2<a,b,c,d,e,a1> */ 
  return kk_std_core_hnd__new_Clause2(kk_std_core_hnd_new_clause_never2_fun460(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw3_fun463__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw3_fun463(kk_function_t _fself, int32_t _b_x96, kk_std_core_hnd__ev _b_x97, kk_box_t _b_x98, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw3_fun463(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun463__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw3_fun463__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw3_fun463, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw3_fun464__t {
  struct kk_function_s _base;
  kk_box_t _b_x98;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw3_fun464(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw3_fun464(kk_box_t _b_x98, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun464__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw3_fun464__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw3_fun464, kk_context());
  _self->_b_x98 = _b_x98;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw3_fun464(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun464__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw3_fun464__t*, _fself, _ctx);
  kk_box_t _b_x98 = _self->_b_x98; /* 45 */
  kk_function_t op = _self->op; /* (x1 : 8410, x2 : 8411, x3 : 8412, r : hnd/resume-context<8413,8414,8415,8417>) -> 8414 8417 */
  kk_drop_match(_self, {kk_box_dup(_b_x98, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple3 _match_x232 = kk_std_core_types__tuple3_unbox(_b_x98, KK_OWNED, _ctx); /*(8410, 8411, 8412)*/;
  {
    kk_box_t x1 = _match_x232.fst;
    kk_box_t x2 = _match_x232.snd;
    kk_box_t x3 = _match_x232.thd;
    kk_std_core_hnd__resume_context _x_x465 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, x1, x2, x3, _x_x465, _ctx), _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_control_raw3_fun463(kk_function_t _fself, int32_t _b_x96, kk_std_core_hnd__ev _b_x97, kk_box_t _b_x98, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun463__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw3_fun463__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 8410, x2 : 8411, x3 : 8412, r : hnd/resume-context<8413,8414,8415,8417>) -> 8414 8417 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x97, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(_b_x96, kk_std_core_hnd_new_clause_control_raw3_fun464(_b_x98, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control_raw3(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,e,e1,a1,b1> (op : (x1 : a, x2 : b, x3 : c, r : resume-context<d,e,e1,b1>) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control_raw3_fun463(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control3_fun466__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control3_fun466(kk_function_t _fself, int32_t _b_x110, kk_std_core_hnd__ev _b_x111, kk_box_t _b_x112, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control3_fun466(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun466__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control3_fun466__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control3_fun466, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control3_fun467__t {
  struct kk_function_s _base;
  kk_box_t _b_x112;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control3_fun467(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control3_fun467(kk_box_t _b_x112, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun467__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control3_fun467__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control3_fun467, kk_context());
  _self->_b_x112 = _b_x112;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control3_fun469__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control3_fun469(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control3_fun469(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun469__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control3_fun469__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control3_fun469, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control3_fun469(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun469__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control3_fun469__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<8519,8522>) -> 8520 8522 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x231 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x231;
  kk_std_core_hnd__resume_result _x_x470 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x470, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control3_fun467(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun467__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control3_fun467__t*, _fself, _ctx);
  kk_box_t _b_x112 = _self->_b_x112; /* 45 */
  kk_function_t op = _self->op; /* (x1 : 8516, x2 : 8517, x3 : 8518, k : (8519) -> 8520 8522) -> 8520 8522 */
  kk_drop_match(_self, {kk_box_dup(_b_x112, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_std_core_types__tuple3 _match_x230 = kk_std_core_types__tuple3_unbox(_b_x112, KK_OWNED, _ctx); /*(8516, 8517, 8518)*/;
  {
    kk_box_t x1 = _match_x230.fst;
    kk_box_t x2 = _match_x230.snd;
    kk_box_t x3 = _match_x230.thd;
    kk_function_t _x_x468;
    kk_function_dup(k, _ctx);
    kk_ref_dup(resumed, _ctx);
    _x_x468 = kk_std_core_hnd_new_clause_control3_fun469(k, resumed, _ctx); /*(ret : 8519) -> 8520 8522*/
    res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_function_t, kk_context_t*), op, (op, x1, x2, x3, _x_x468, _ctx), _ctx); /*8522*/
  }
  return kk_std_core_hnd_protect_prompt(resumed, k, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control3_fun466(kk_function_t _fself, int32_t _b_x110, kk_std_core_hnd__ev _b_x111, kk_box_t _b_x112, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun466__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control3_fun466__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 8516, x2 : 8517, x3 : 8518, k : (8519) -> 8520 8522) -> 8520 8522 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x111, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(_b_x110, kk_std_core_hnd_new_clause_control3_fun467(_b_x112, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control3(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1,b1> (op : (x1 : a, x2 : b, x3 : c, k : (d) -> e b1) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control3_fun466(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail3_fun471__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail3_fun471(kk_function_t _fself, int32_t _b_x118, kk_std_core_hnd__ev _b_x119, kk_box_t _b_x120, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail3_fun471(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun471__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail3_fun471__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail3_fun471, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail3_fun474__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_x119;
};
static kk_box_t kk_std_core_hnd_clause_tail3_fun474(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail3_fun474(kk_std_core_hnd__ev _b_x119, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun474__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail3_fun474__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail3_fun474, kk_context());
  _self->_b_x119 = _b_x119;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail3_fun474(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun474__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail3_fun474__t*, _fself, _ctx);
  kk_std_core_hnd__ev _b_x119 = _self->_b_x119; /* hnd/ev<47> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_x119, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(_b_x119, cont, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail3_fun471(kk_function_t _fself, int32_t _b_x118, kk_std_core_hnd__ev _b_x119, kk_box_t _b_x120, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun471__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail3_fun471__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8620, 8621, 8622) -> 8617 8623 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x472;
  {
    struct kk_std_core_hnd_Ev* _con_x473 = kk_std_core_hnd__as_Ev(_b_x119, _ctx);
    kk_evv_t w = _con_x473->hevv;
    kk_evv_dup(w, _ctx);
    _x_x472 = w; /*hnd/evv<5330>*/
  }
  w0 = kk_evv_swap(_x_x472,kk_context()); /*hnd/evv<_5477>*/
  kk_box_t y;
  kk_std_core_types__tuple3 _match_x229 = kk_std_core_types__tuple3_unbox(_b_x120, KK_OWNED, _ctx); /*(8620, 8621, 8622)*/;
  {
    kk_box_t x1 = _match_x229.fst;
    kk_box_t x2 = _match_x229.snd;
    kk_box_t x3 = _match_x229.thd;
    y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx); /*8623*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail3_fun474(_b_x119, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(_b_x119, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail3(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1,b1> (op : (c, d, a1) -> e b1) -> clause1<(c, d, a1),b1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail3_fun471(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop3_fun475(kk_function_t _fself, int32_t _b_x126, kk_std_core_hnd__ev _b_x127, kk_box_t _b_x128, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop3_fun475__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop3_fun475__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8721, 8722, 8723) -> 8718 8724 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x127, (KK_I32(3)), _ctx);
  kk_std_core_types__tuple3 _match_x227 = kk_std_core_types__tuple3_unbox(_b_x128, KK_OWNED, _ctx); /*(8721, 8722, 8723)*/;
  {
    kk_box_t x1 = _match_x227.fst;
    kk_box_t x2 = _match_x227.snd;
    kk_box_t x3 = _match_x227.thd;
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_core_hnd_clause_never3_fun476__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never3_fun476(kk_function_t _fself, int32_t _b_x134, kk_std_core_hnd__ev _b_x135, kk_box_t _b_x136, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never3_fun476(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun476__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never3_fun476__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never3_fun476, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never3_fun477__t {
  struct kk_function_s _base;
  kk_box_t _b_x136;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never3_fun477(kk_function_t _fself, kk_function_t ___wildcard_x653__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never3_fun477(kk_box_t _b_x136, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun477__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never3_fun477__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never3_fun477, kk_context());
  _self->_b_x136 = _b_x136;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never3_fun477(kk_function_t _fself, kk_function_t ___wildcard_x653__45, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun477__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never3_fun477__t*, _fself, _ctx);
  kk_box_t _b_x136 = _self->_b_x136; /* 45 */
  kk_function_t op = _self->op; /* (8819, 8820, 8821) -> 8823 8825 */
  kk_drop_match(_self, {kk_box_dup(_b_x136, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x653__45, _ctx);
  kk_std_core_types__tuple3 _match_x226 = kk_std_core_types__tuple3_unbox(_b_x136, KK_OWNED, _ctx); /*(8819, 8820, 8821)*/;
  {
    kk_box_t x1 = _match_x226.fst;
    kk_box_t x2 = _match_x226.snd;
    kk_box_t x3 = _match_x226.thd;
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_never3_fun476(kk_function_t _fself, int32_t _b_x134, kk_std_core_hnd__ev _b_x135, kk_box_t _b_x136, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun476__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never3_fun476__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8819, 8820, 8821) -> 8823 8825 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x135, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_x134, kk_std_core_hnd_new_clause_never3_fun477(_b_x136, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never3(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1,b1> (op : (a, b, c) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_never3_fun476(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_under3_fun483__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under3_fun483(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under3_fun483(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun483__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under3_fun483__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under3_fun483, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_under3_fun486__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under3_fun486(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under3_fun486(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun486__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under3_fun486__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under3_fun486, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under3_fun486(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun486__t* _self = kk_function_as(struct kk_std_core_hnd_under3_fun486__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<9062> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_under3_fun483(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun483__t* _self = kk_function_as(struct kk_std_core_hnd_under3_fun483__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<9062> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x484;
  {
    struct kk_std_core_hnd_Ev* _con_x485 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x485->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x484 = w_0; /*hnd/evv<5330>*/
  }
  w0_0 = kk_evv_swap(_x_x484,kk_context()); /*hnd/evv<_5477>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*9060*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under3_fun486(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y;
  }
}

kk_box_t kk_std_core_hnd_under3(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (ev : ev<a1>, op : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e d */ 
  kk_evv_t w0;
  kk_evv_t _x_x481;
  {
    struct kk_std_core_hnd_Ev* _con_x482 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x482->hevv;
    kk_evv_dup(w, _ctx);
    _x_x481 = w; /*hnd/evv<5330>*/
  }
  w0 = kk_evv_swap(_x_x481,kk_context()); /*hnd/evv<_8968>*/
  kk_box_t z = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx); /*9060*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(z, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under3_fun483(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return z;
  }
}


// lift anonymous function
struct kk_std_core_hnd_clause_control4_fun487__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control4_fun487(kk_function_t _fself, int32_t _b_x155, kk_std_core_hnd__ev _b_x156, kk_box_t _b_x157, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control4_fun487(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun487__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control4_fun487__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control4_fun487, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control4_fun488__t {
  struct kk_function_s _base;
  kk_box_t _b_x157;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control4_fun488(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control4_fun488(kk_box_t _b_x157, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun488__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control4_fun488__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control4_fun488, kk_context());
  _self->_b_x157 = _b_x157;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control4_fun491__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control4_fun491(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control4_fun491(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun491__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control4_fun491__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control4_fun491, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control4_fun491(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun491__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control4_fun491__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<9166,9169>) -> 9167 9169 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x222 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x222;
  kk_std_core_hnd__resume_result _x_x492 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x492, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control4_fun488(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun488__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control4_fun488__t*, _fself, _ctx);
  kk_box_t _b_x157 = _self->_b_x157; /* 45 */
  kk_function_t op = _self->op; /* (x1 : 9162, x2 : 9163, x3 : 9164, x4 : 9165, k : (9166) -> 9167 9169) -> 9167 9169 */
  kk_drop_match(_self, {kk_box_dup(_b_x157, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_std_core_types__tuple4 _match_x221 = kk_std_core_types__tuple4_unbox(_b_x157, KK_OWNED, _ctx); /*(9162, 9163, 9164, 9165)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x489 = kk_std_core_types__as_Tuple4(_match_x221, _ctx);
    kk_box_t x1 = _con_x489->fst;
    kk_box_t x2 = _con_x489->snd;
    kk_box_t x3 = _con_x489->thd;
    kk_box_t x4 = _con_x489->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x221, _ctx)) {
      kk_datatype_ptr_free(_match_x221, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x221, _ctx);
    }
    kk_function_t _x_x490;
    kk_function_dup(k, _ctx);
    kk_ref_dup(resumed, _ctx);
    _x_x490 = kk_std_core_hnd_new_clause_control4_fun491(k, resumed, _ctx); /*(ret : 9166) -> 9167 9169*/
    res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_function_t, kk_context_t*), op, (op, x1, x2, x3, x4, _x_x490, _ctx), _ctx); /*9169*/
  }
  return kk_std_core_hnd_protect_prompt(resumed, k, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control4_fun487(kk_function_t _fself, int32_t _b_x155, kk_std_core_hnd__ev _b_x156, kk_box_t _b_x157, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun487__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control4_fun487__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 9162, x2 : 9163, x3 : 9164, x4 : 9165, k : (9166) -> 9167 9169) -> 9167 9169 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x156, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(_b_x155, kk_std_core_hnd_new_clause_control4_fun488(_b_x157, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control4(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,b1,c1> (op : (x1 : a, x2 : b, x3 : c, x4 : d, k : (a1) -> e c1) -> e c1) -> clause1<(a, b, c, d),a1,b1,e,c1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control4_fun487(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail4_fun493__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail4_fun493(kk_function_t _fself, int32_t _b_x163, kk_std_core_hnd__ev _b_x164, kk_box_t _b_x165, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail4_fun493(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun493__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail4_fun493__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail4_fun493, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail4_fun497__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_x164;
};
static kk_box_t kk_std_core_hnd_clause_tail4_fun497(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail4_fun497(kk_std_core_hnd__ev _b_x164, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun497__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail4_fun497__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail4_fun497, kk_context());
  _self->_b_x164 = _b_x164;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail4_fun497(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun497__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail4_fun497__t*, _fself, _ctx);
  kk_std_core_hnd__ev _b_x164 = _self->_b_x164; /* hnd/ev<47> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_x164, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(_b_x164, cont, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail4_fun493(kk_function_t _fself, int32_t _b_x163, kk_std_core_hnd__ev _b_x164, kk_box_t _b_x165, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun493__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail4_fun493__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (9278, 9279, 9280, 9281) -> 9275 9282 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x494;
  {
    struct kk_std_core_hnd_Ev* _con_x495 = kk_std_core_hnd__as_Ev(_b_x164, _ctx);
    kk_evv_t w = _con_x495->hevv;
    kk_evv_dup(w, _ctx);
    _x_x494 = w; /*hnd/evv<5330>*/
  }
  w0 = kk_evv_swap(_x_x494,kk_context()); /*hnd/evv<_5477>*/
  kk_box_t y;
  kk_std_core_types__tuple4 _match_x220 = kk_std_core_types__tuple4_unbox(_b_x165, KK_OWNED, _ctx); /*(9278, 9279, 9280, 9281)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x496 = kk_std_core_types__as_Tuple4(_match_x220, _ctx);
    kk_box_t x1 = _con_x496->fst;
    kk_box_t x2 = _con_x496->snd;
    kk_box_t x3 = _con_x496->thd;
    kk_box_t x4 = _con_x496->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x220, _ctx)) {
      kk_datatype_ptr_free(_match_x220, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x220, _ctx);
    }
    y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx); /*9282*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail4_fun497(_b_x164, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(_b_x164, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail4(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1,b1,c1> (op : (c, d, a1, b1) -> e c1) -> clause1<(c, d, a1, b1),c1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail4_fun493(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail_noop4_fun498__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail_noop4_fun498(kk_function_t _fself, int32_t _b_x171, kk_std_core_hnd__ev _b_x172, kk_box_t _b_x173, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail_noop4_fun498(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop4_fun498__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail_noop4_fun498__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail_noop4_fun498, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail_noop4_fun498(kk_function_t _fself, int32_t _b_x171, kk_std_core_hnd__ev _b_x172, kk_box_t _b_x173, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop4_fun498__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop4_fun498__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (9391, 9392, 9393, 9394) -> 9388 9395 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x172, (KK_I32(3)), _ctx);
  kk_std_core_types__tuple4 _match_x218 = kk_std_core_types__tuple4_unbox(_b_x173, KK_OWNED, _ctx); /*(9391, 9392, 9393, 9394)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x499 = kk_std_core_types__as_Tuple4(_match_x218, _ctx);
    kk_box_t x1 = _con_x499->fst;
    kk_box_t x2 = _con_x499->snd;
    kk_box_t x3 = _con_x499->thd;
    kk_box_t x4 = _con_x499->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x218, _ctx)) {
      kk_datatype_ptr_free(_match_x218, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x218, _ctx);
    }
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx);
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail_noop4(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1,b1,c1> (op : (c, d, a1, b1) -> e c1) -> clause1<(c, d, a1, b1),c1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail_noop4_fun498(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_never4_fun500__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never4_fun500(kk_function_t _fself, int32_t _b_x179, kk_std_core_hnd__ev _b_x180, kk_box_t _b_x181, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never4_fun500(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun500__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never4_fun500__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never4_fun500, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never4_fun501__t {
  struct kk_function_s _base;
  kk_box_t _b_x181;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never4_fun501(kk_function_t _fself, kk_function_t ___wildcard_x653__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never4_fun501(kk_box_t _b_x181, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun501__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never4_fun501__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never4_fun501, kk_context());
  _self->_b_x181 = _b_x181;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never4_fun501(kk_function_t _fself, kk_function_t ___wildcard_x653__45, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun501__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never4_fun501__t*, _fself, _ctx);
  kk_box_t _b_x181 = _self->_b_x181; /* 45 */
  kk_function_t op = _self->op; /* (9501, 9502, 9503, 9504) -> 9506 9508 */
  kk_drop_match(_self, {kk_box_dup(_b_x181, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x653__45, _ctx);
  kk_std_core_types__tuple4 _match_x217 = kk_std_core_types__tuple4_unbox(_b_x181, KK_OWNED, _ctx); /*(9501, 9502, 9503, 9504)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x502 = kk_std_core_types__as_Tuple4(_match_x217, _ctx);
    kk_box_t x1 = _con_x502->fst;
    kk_box_t x2 = _con_x502->snd;
    kk_box_t x3 = _con_x502->thd;
    kk_box_t x4 = _con_x502->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x217, _ctx)) {
      kk_datatype_ptr_free(_match_x217, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x217, _ctx);
    }
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_never4_fun500(kk_function_t _fself, int32_t _b_x179, kk_std_core_hnd__ev _b_x180, kk_box_t _b_x181, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun500__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never4_fun500__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (9501, 9502, 9503, 9504) -> 9506 9508 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x180, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_x179, kk_std_core_hnd_new_clause_never4_fun501(_b_x181, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never4(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,b1,c1> (op : (a, b, c, d) -> e c1) -> clause1<(a, b, c, d),a1,b1,e,c1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_never4_fun500(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_under4_fun508__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under4_fun508(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under4_fun508(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun508__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under4_fun508__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under4_fun508, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_under4_fun511__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under4_fun511(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under4_fun511(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun511__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under4_fun511__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under4_fun511, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under4_fun511(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun511__t* _self = kk_function_as(struct kk_std_core_hnd_under4_fun511__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<9768> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_under4_fun508(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun508__t* _self = kk_function_as(struct kk_std_core_hnd_under4_fun508__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<9768> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x509;
  {
    struct kk_std_core_hnd_Ev* _con_x510 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x510->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x509 = w_0; /*hnd/evv<5330>*/
  }
  w0_0 = kk_evv_swap(_x_x509,kk_context()); /*hnd/evv<_5477>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*9766*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under4_fun511(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y;
  }
}

kk_box_t kk_std_core_hnd_under4(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,b1> (ev : ev<b1>, op : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e a1 */ 
  kk_evv_t w0;
  kk_evv_t _x_x506;
  {
    struct kk_std_core_hnd_Ev* _con_x507 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x507->hevv;
    kk_evv_dup(w, _ctx);
    _x_x506 = w; /*hnd/evv<5330>*/
  }
  w0 = kk_evv_swap(_x_x506,kk_context()); /*hnd/evv<_9668>*/
  kk_box_t z = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx); /*9766*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(z, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under4_fun508(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return z;
  }
}


// lift anonymous function
struct kk_std_core_hnd_open_at1_fun512__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd_open_at1_fun512(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_open_at1_fun512(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open_at1_fun512__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_open_at1_fun512__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_open_at1_fun512, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_open_at1_fun512(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open_at1_fun512__t* _self = kk_function_as(struct kk_std_core_hnd_open_at1_fun512__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_open_at1(kk_ssize_t i, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (i : ev-index, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10321>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*10319*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_open_at1_fun512(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at0_fun513__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at0_fun513(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at0_fun513(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at0_fun513__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at0_fun513__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at0_fun513, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at0_fun513(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at0_fun513__t* _self = kk_function_as(struct kk_std_core_hnd__open_at0_fun513__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at0(kk_ssize_t i, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e,e1> (i : ev-index, f : () -> e a) -> e1 a */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10428>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), f, (f, _ctx), _ctx); /*10426*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at0_fun513(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at1_fun514__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at1_fun514(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at1_fun514(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at1_fun514__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at1_fun514__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at1_fun514, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at1_fun514(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at1_fun514__t* _self = kk_function_as(struct kk_std_core_hnd__open_at1_fun514__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at1(kk_ssize_t i, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (i : ev-index, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10542>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*10540*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at1_fun514(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at2_fun515__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at2_fun515(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at2_fun515(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at2_fun515__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at2_fun515__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at2_fun515, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at2_fun515(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at2_fun515__t* _self = kk_function_as(struct kk_std_core_hnd__open_at2_fun515__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at2(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) { /* forall<a,b,c,e,e1> (i : ev-index, f : (a, b) -> e c, x1 : a, x2 : b) -> e1 c */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10669>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, _ctx), _ctx); /*10667*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at2_fun515(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at3_fun516__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at3_fun516(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at3_fun516(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at3_fun516__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at3_fun516__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at3_fun516, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at3_fun516(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at3_fun516__t* _self = kk_function_as(struct kk_std_core_hnd__open_at3_fun516__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at3(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx) { /* forall<a,b,c,d,e,e1> (i : ev-index, f : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e1 d */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10809>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, _ctx), _ctx); /*10807*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at3_fun516(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at4_fun517__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at4_fun517(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at4_fun517(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at4_fun517__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at4_fun517__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at4_fun517, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at4_fun517(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at4_fun517__t* _self = kk_function_as(struct kk_std_core_hnd__open_at4_fun517__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at4(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,e1> (i : ev-index, f : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e1 a1 */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10962>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, x4, _ctx), _ctx); /*10960*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at4_fun517(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd_open1_fun519__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd_open1_fun519(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_open1_fun519(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open1_fun519__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_open1_fun519__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_open1_fun519, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_open1_fun519(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open1_fun519__t* _self = kk_function_as(struct kk_std_core_hnd_open1_fun519__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_open1(kk_vector_t indices, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (indices : vector<ev-index>, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w;
  kk_vector_t _x_x518 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x518, _ctx); /*hnd/evv<11095>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*11093*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_open1_fun519(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open0_fun521__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open0_fun521(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open0_fun521(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open0_fun521__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open0_fun521__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open0_fun521, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open0_fun521(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open0_fun521__t* _self = kk_function_as(struct kk_std_core_hnd__open0_fun521__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open0(kk_vector_t indices, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e,e1> (indices : vector<ev-index>, f : () -> e a) -> e1 a */ 
  kk_evv_t w;
  kk_vector_t _x_x520 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x520, _ctx); /*hnd/evv<11202>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), f, (f, _ctx), _ctx); /*11200*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open0_fun521(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open1_fun523__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open1_fun523(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open1_fun523(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open1_fun523__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open1_fun523__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open1_fun523, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open1_fun523(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open1_fun523__t* _self = kk_function_as(struct kk_std_core_hnd__open1_fun523__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open1(kk_vector_t indices, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (indices : vector<ev-index>, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w;
  kk_vector_t _x_x522 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x522, _ctx); /*hnd/evv<11316>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*11314*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open1_fun523(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open2_fun525__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open2_fun525(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open2_fun525(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open2_fun525__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open2_fun525__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open2_fun525, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open2_fun525(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open2_fun525__t* _self = kk_function_as(struct kk_std_core_hnd__open2_fun525__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open2(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) { /* forall<a,b,c,e,e1> (indices : vector<ev-index>, f : (a, b) -> e c, x1 : a, x2 : b) -> e1 c */ 
  kk_evv_t w;
  kk_vector_t _x_x524 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x524, _ctx); /*hnd/evv<11443>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, _ctx), _ctx); /*11441*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open2_fun525(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open3_fun527__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open3_fun527(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open3_fun527(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open3_fun527__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open3_fun527__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open3_fun527, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open3_fun527(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open3_fun527__t* _self = kk_function_as(struct kk_std_core_hnd__open3_fun527__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open3(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx) { /* forall<a,b,c,d,e,e1> (indices : vector<ev-index>, f : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e1 d */ 
  kk_evv_t w;
  kk_vector_t _x_x526 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x526, _ctx); /*hnd/evv<11583>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, _ctx), _ctx); /*11581*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open3_fun527(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open4_fun529__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open4_fun529(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open4_fun529(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open4_fun529__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open4_fun529__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open4_fun529, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open4_fun529(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open4_fun529__t* _self = kk_function_as(struct kk_std_core_hnd__open4_fun529__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open4(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,e1> (indices : vector<ev-index>, f : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e1 a1 */ 
  kk_evv_t w;
  kk_vector_t _x_x528 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x528, _ctx); /*hnd/evv<11736>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, x4, _ctx), _ctx); /*11734*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open4_fun529(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd_try_finalize_prompt_fun531__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_hnd_try_finalize_prompt_fun531(kk_function_t _fself, kk_function_t _b_x194, kk_box_t _b_x195, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_try_finalize_prompt_fun531(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_hnd_try_finalize_prompt_fun531, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_hnd_try_finalize_prompt_fun531(kk_function_t _fself, kk_function_t _b_x194, kk_box_t _b_x195, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t cont_199 = _b_x194; /*(11801) -> 11861 11860*/;
  kk_box_t x_200 = _b_x195; /*11801*/;
  kk_std_core_types__either _x_x532;
  kk_box_t _x_x533 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont_199, (cont_199, x_200, _ctx), _ctx); /*11860*/
  _x_x532 = kk_std_core_hnd_try_finalize_prompt(_x_x533, _ctx); /*either<hnd/yield-info,11860>*/
  return kk_std_core_types__either_box(_x_x532, _ctx);
}

kk_std_core_types__either kk_std_core_hnd_try_finalize_prompt(kk_box_t res, kk_context_t* _ctx) { /* forall<a,e> (res : a) -> e either<yield-info,a> */ 
  bool _match_x201 = kk_yielding_non_final(kk_context()); /*bool*/;
  if (_match_x201) {
    kk_box_drop(res, _ctx);
    kk_box_t _x_x530 = kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_try_finalize_prompt_fun531(_ctx), _ctx); /*2568*/
    return kk_std_core_types__either_unbox(_x_x530, KK_OWNED, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    kk_std_core_hnd__yield_info _b_x196_198 = kk_std_core_hnd_yield_capture(_ctx); /*hnd/yield-info*/;
    return kk_std_core_types__new_Left(kk_std_core_hnd__yield_info_box(_b_x196_198, _ctx), _ctx);
  }
  {
    return kk_std_core_types__new_Right(res, _ctx);
  }
}

// initialization
void kk_std_core_hnd__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_hnd__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
