// Koka generated module: std/time/locale, koka version: 3.2.2, platform: 64-bit
#include "std_time_locale.h"
 
// lifted local: @lift-create-Time-locale@10403, @uniq-month-names-short@92, @create-Time-locale, @spec-x10239
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10234, using:
// @uniq-f@10234 = fn(m: string){
//   val n@10001 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10001) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@1: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@0: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@0: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10001) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_create_Time_locale_10404(kk_std_core_types__list _uniq_xs_10233, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10233, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1247 = kk_std_core_types__as_Cons(_uniq_xs_10233, _ctx);
    kk_box_t _box_x0 = _con_x1247->head;
    kk_std_core_types__list _uniq_xx_10237 = _con_x1247->tail;
    kk_string_t _uniq_x_10236 = kk_string_unbox(_box_x0);
    kk_reuse_t _ru_x1231 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10233, _ctx)) {
      _ru_x1231 = (kk_datatype_ptr_reuse(_uniq_xs_10233, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10236, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10237, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10233, _ctx);
    }
    kk_std_core_types__optional n_10001 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(_uniq_x_10236, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10431;
    kk_std_core_sslice__sslice _x_x1248;
    bool _match_x1226;
    kk_integer_t _brw_x1229;
    if (kk_std_core_types__is_Optional(n_10001, _ctx)) {
      kk_box_t _box_x3 = n_10001._cons._Optional.value;
      kk_integer_t _uniq_n_414 = kk_integer_unbox(_box_x3, _ctx);
      kk_integer_dup(_uniq_n_414, _ctx);
      _brw_x1229 = _uniq_n_414; /*int*/
    }
    else {
      _brw_x1229 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1230 = kk_integer_eq_borrow(_brw_x1229,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1229, _ctx);
    _match_x1226 = _brw_x1230; /*bool*/
    if (_match_x1226) {
      kk_std_core_types__optional_drop(n_10001, _ctx);
      _x_x1248 = slice_0; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1227;
      kk_integer_t _x_x1249;
      if (kk_std_core_types__is_Optional(n_10001, _ctx)) {
        kk_box_t _box_x4 = n_10001._cons._Optional.value;
        kk_integer_t _uniq_n_414_0 = kk_integer_unbox(_box_x4, _ctx);
        kk_integer_dup(_uniq_n_414_0, _ctx);
        kk_std_core_types__optional_drop(n_10001, _ctx);
        _x_x1249 = _uniq_n_414_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_10001, _ctx);
        _x_x1249 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1227 = kk_integer_add_small_const(_x_x1249, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1228 = kk_std_core_sslice_extend(slice_0, _brw_x1227, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1227, _ctx);
      _x_x1248 = _brw_x1228; /*sslice/sslice*/
    }
    _trmc_x10431 = kk_std_core_sslice_string(_x_x1248, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10432 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10433 = kk_std_core_types__new_Cons(_ru_x1231, 0, kk_string_box(_trmc_x10431), _trmc_x10432, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x14_19 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10433, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1224;
    kk_std_core_types__cctx _x_x1250 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1224 = kk_cctx_extend_linear(_x_x1250,(kk_std_core_types__list_box(_trmc_x10433, _ctx)),_b_x14_19,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1225 = kk_std_time_locale__trmc_lift_create_Time_locale_10404(_uniq_xx_10237, _brw_x1224, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1224, _ctx);
    return _brw_x1225;
  }
  {
    kk_box_t _x_x1251;
    kk_std_core_types__cctx _x_x1252 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1251 = kk_cctx_apply_linear(_x_x1252,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1251, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-create-Time-locale@10403, @uniq-month-names-short@92, @create-Time-locale, @spec-x10239
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10234, using:
// @uniq-f@10234 = fn(m: string){
//   val n@10001 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10001) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@1: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@0: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@0: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10001) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10404(kk_std_core_types__list _uniq_xs_10233_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1222 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1223 = kk_std_time_locale__trmc_lift_create_Time_locale_10404(_uniq_xs_10233_0, _brw_x1222, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1222, _ctx);
  return _brw_x1223;
}
 
// lifted local: @uniq-month-names-short@92, @create-Time-locale, @spec-x10232
// specialized: std/core/list/map, on parameters @uniq-f@10229, using:
// @uniq-f@10229 = fn(m: string){
//   val n@10001 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10001) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@1: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@0: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@0: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10001) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10403(kk_std_core_types__list _uniq_xs_10228, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10228, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1220 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1221 = kk_std_time_locale__trmc_lift_create_Time_locale_10404(_uniq_xs_10228, _brw_x1220, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1220, _ctx);
    return _brw_x1221;
  }
}
 
// lifted local: @lift-create-Time-locale@10405, @uniq-day-names-short@153, @create-Time-locale, @spec-x10252
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10247, using:
// @uniq-f@10247 = fn(m@0: string){
//   val n@0@10003 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10003) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@4: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@1: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@2: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10003) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@0: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_create_Time_locale_10406(kk_std_core_types__list _uniq_xs_10246, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10246, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1253 = kk_std_core_types__as_Cons(_uniq_xs_10246, _ctx);
    kk_box_t _box_x25 = _con_x1253->head;
    kk_std_core_types__list _uniq_xx_10250 = _con_x1253->tail;
    kk_string_t _uniq_x_10249 = kk_string_unbox(_box_x25);
    kk_reuse_t _ru_x1232 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10246, _ctx)) {
      _ru_x1232 = (kk_datatype_ptr_reuse(_uniq_xs_10246, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10249, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10250, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10246, _ctx);
    }
    kk_std_core_types__optional n_0_10003 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0_0 = kk_std_core_sslice_first1(_uniq_x_10249, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10434;
    kk_std_core_sslice__sslice _x_x1254;
    bool _match_x1215;
    kk_integer_t _brw_x1218;
    if (kk_std_core_types__is_Optional(n_0_10003, _ctx)) {
      kk_box_t _box_x28 = n_0_10003._cons._Optional.value;
      kk_integer_t _uniq_n_414_1 = kk_integer_unbox(_box_x28, _ctx);
      kk_integer_dup(_uniq_n_414_1, _ctx);
      _brw_x1218 = _uniq_n_414_1; /*int*/
    }
    else {
      _brw_x1218 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1219 = kk_integer_eq_borrow(_brw_x1218,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1218, _ctx);
    _match_x1215 = _brw_x1219; /*bool*/
    if (_match_x1215) {
      kk_std_core_types__optional_drop(n_0_10003, _ctx);
      _x_x1254 = slice_0_0; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1216;
      kk_integer_t _x_x1255;
      if (kk_std_core_types__is_Optional(n_0_10003, _ctx)) {
        kk_box_t _box_x29 = n_0_10003._cons._Optional.value;
        kk_integer_t _uniq_n_414_0_0 = kk_integer_unbox(_box_x29, _ctx);
        kk_integer_dup(_uniq_n_414_0_0, _ctx);
        kk_std_core_types__optional_drop(n_0_10003, _ctx);
        _x_x1255 = _uniq_n_414_0_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_0_10003, _ctx);
        _x_x1255 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1216 = kk_integer_add_small_const(_x_x1255, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1217 = kk_std_core_sslice_extend(slice_0_0, _brw_x1216, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1216, _ctx);
      _x_x1254 = _brw_x1217; /*sslice/sslice*/
    }
    _trmc_x10434 = kk_std_core_sslice_string(_x_x1254, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10435 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10436 = kk_std_core_types__new_Cons(_ru_x1232, 0, kk_string_box(_trmc_x10434), _trmc_x10435, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x39_44 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10436, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1213;
    kk_std_core_types__cctx _x_x1256 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1213 = kk_cctx_extend_linear(_x_x1256,(kk_std_core_types__list_box(_trmc_x10436, _ctx)),_b_x39_44,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1214 = kk_std_time_locale__trmc_lift_create_Time_locale_10406(_uniq_xx_10250, _brw_x1213, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1213, _ctx);
    return _brw_x1214;
  }
  {
    kk_box_t _x_x1257;
    kk_std_core_types__cctx _x_x1258 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1257 = kk_cctx_apply_linear(_x_x1258,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1257, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-create-Time-locale@10405, @uniq-day-names-short@153, @create-Time-locale, @spec-x10252
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10247, using:
// @uniq-f@10247 = fn(m@0: string){
//   val n@0@10003 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10003) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@4: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@1: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@2: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10003) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@0: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10406(kk_std_core_types__list _uniq_xs_10246_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1211 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1212 = kk_std_time_locale__trmc_lift_create_Time_locale_10406(_uniq_xs_10246_0, _brw_x1211, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1211, _ctx);
  return _brw_x1212;
}
 
// lifted local: @uniq-day-names-short@153, @create-Time-locale, @spec-x10245
// specialized: std/core/list/map, on parameters @uniq-f@10242, using:
// @uniq-f@10242 = fn(m@0: string){
//   val n@0@10003 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10003) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@4: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@1: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@2: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10003) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@0: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10405(kk_std_core_types__list _uniq_xs_10241, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10241, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1209 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1210 = kk_std_time_locale__trmc_lift_create_Time_locale_10406(_uniq_xs_10241, _brw_x1209, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1209, _ctx);
    return _brw_x1210;
  }
}
 
// lifted local: @lift-create-Time-locale@10407, @uniq-day-names-min@214, @create-Time-locale, @spec-x10265
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10260, using:
// @uniq-f@10260 = fn(m@1: string){
//   val n@1@10005 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10005) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@5: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@2: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10005) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_create_Time_locale_10408(kk_std_core_types__list _uniq_xs_10259, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10259, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1259 = kk_std_core_types__as_Cons(_uniq_xs_10259, _ctx);
    kk_box_t _box_x50 = _con_x1259->head;
    kk_std_core_types__list _uniq_xx_10263 = _con_x1259->tail;
    kk_string_t _uniq_x_10262 = kk_string_unbox(_box_x50);
    kk_reuse_t _ru_x1233 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10259, _ctx)) {
      _ru_x1233 = (kk_datatype_ptr_reuse(_uniq_xs_10259, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10262, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10263, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10259, _ctx);
    }
    kk_std_core_types__optional n_1_10005 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0_1 = kk_std_core_sslice_first1(_uniq_x_10262, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10437;
    kk_std_core_sslice__sslice _x_x1260;
    bool _match_x1204;
    kk_integer_t _brw_x1207;
    if (kk_std_core_types__is_Optional(n_1_10005, _ctx)) {
      kk_box_t _box_x53 = n_1_10005._cons._Optional.value;
      kk_integer_t _uniq_n_414_2 = kk_integer_unbox(_box_x53, _ctx);
      kk_integer_dup(_uniq_n_414_2, _ctx);
      _brw_x1207 = _uniq_n_414_2; /*int*/
    }
    else {
      _brw_x1207 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1208 = kk_integer_eq_borrow(_brw_x1207,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1207, _ctx);
    _match_x1204 = _brw_x1208; /*bool*/
    if (_match_x1204) {
      kk_std_core_types__optional_drop(n_1_10005, _ctx);
      _x_x1260 = slice_0_1; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1205;
      kk_integer_t _x_x1261;
      if (kk_std_core_types__is_Optional(n_1_10005, _ctx)) {
        kk_box_t _box_x54 = n_1_10005._cons._Optional.value;
        kk_integer_t _uniq_n_414_0_1 = kk_integer_unbox(_box_x54, _ctx);
        kk_integer_dup(_uniq_n_414_0_1, _ctx);
        kk_std_core_types__optional_drop(n_1_10005, _ctx);
        _x_x1261 = _uniq_n_414_0_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_1_10005, _ctx);
        _x_x1261 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1205 = kk_integer_add_small_const(_x_x1261, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1206 = kk_std_core_sslice_extend(slice_0_1, _brw_x1205, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1205, _ctx);
      _x_x1260 = _brw_x1206; /*sslice/sslice*/
    }
    _trmc_x10437 = kk_std_core_sslice_string(_x_x1260, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10438 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10439 = kk_std_core_types__new_Cons(_ru_x1233, 0, kk_string_box(_trmc_x10437), _trmc_x10438, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x64_69 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10439, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1202;
    kk_std_core_types__cctx _x_x1262 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1202 = kk_cctx_extend_linear(_x_x1262,(kk_std_core_types__list_box(_trmc_x10439, _ctx)),_b_x64_69,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1203 = kk_std_time_locale__trmc_lift_create_Time_locale_10408(_uniq_xx_10263, _brw_x1202, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1202, _ctx);
    return _brw_x1203;
  }
  {
    kk_box_t _x_x1263;
    kk_std_core_types__cctx _x_x1264 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1263 = kk_cctx_apply_linear(_x_x1264,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1263, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-create-Time-locale@10407, @uniq-day-names-min@214, @create-Time-locale, @spec-x10265
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10260, using:
// @uniq-f@10260 = fn(m@1: string){
//   val n@1@10005 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10005) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@5: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@2: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10005) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10408(kk_std_core_types__list _uniq_xs_10259_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1200 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1201 = kk_std_time_locale__trmc_lift_create_Time_locale_10408(_uniq_xs_10259_0, _brw_x1200, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1200, _ctx);
  return _brw_x1201;
}
 
// lifted local: @uniq-day-names-min@214, @create-Time-locale, @spec-x10258
// specialized: std/core/list/map, on parameters @uniq-f@10255, using:
// @uniq-f@10255 = fn(m@1: string){
//   val n@1@10005 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10005) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@5: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@2: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10005) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10407(kk_std_core_types__list _uniq_xs_10254, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10254, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1198 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1199 = kk_std_time_locale__trmc_lift_create_Time_locale_10408(_uniq_xs_10254, _brw_x1198, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1198, _ctx);
    return _brw_x1199;
  }
}

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_fs__copy(kk_std_time_locale__time_locale _this, kk_std_core_types__optional lang_name, kk_std_core_types__optional day_names, kk_std_core_types__optional month_names, kk_std_core_types__optional month_names_short, kk_std_core_types__optional day_names_short, kk_std_core_types__optional day_names_min, kk_std_core_types__optional format_t, kk_std_core_types__optional format_tt, kk_std_core_types__optional format_l, kk_std_core_types__optional format_ll, kk_std_core_types__optional format_lll, kk_std_core_types__optional format_llll, kk_context_t* _ctx) { /* (time-locale, lang-name : ? string, day-names : ? (list<string>), month-names : ? (list<string>), month-names-short : ? (list<string>), day-names-short : ? (list<string>), day-names-min : ? (list<string>), format-t : ? string, format-tt : ? string, format-l : ? string, format-ll : ? string, format-lll : ? string, format-llll : ? string) -> time-locale */ 
  kk_string_t _x_x1292;
  if (kk_std_core_types__is_Optional(lang_name, _ctx)) {
    kk_box_t _box_x84 = lang_name._cons._Optional.value;
    kk_string_t _uniq_lang_name_362 = kk_string_unbox(_box_x84);
    kk_string_dup(_uniq_lang_name_362, _ctx);
    kk_std_core_types__optional_drop(lang_name, _ctx);
    _x_x1292 = _uniq_lang_name_362; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(lang_name, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1293 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x = _con_x1293->lang_name;
      kk_string_dup(_x, _ctx);
      _x_x1292 = _x; /*string*/
    }
  }
  kk_std_core_types__list _x_x1294;
  if (kk_std_core_types__is_Optional(day_names, _ctx)) {
    kk_box_t _box_x85 = day_names._cons._Optional.value;
    kk_std_core_types__list _uniq_day_names_370 = kk_std_core_types__list_unbox(_box_x85, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_day_names_370, _ctx);
    kk_std_core_types__optional_drop(day_names, _ctx);
    _x_x1294 = _uniq_day_names_370; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(day_names, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1295 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x1295->day_names;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x1294 = _x_0; /*list<string>*/
    }
  }
  kk_std_core_types__list _x_x1296;
  if (kk_std_core_types__is_Optional(month_names, _ctx)) {
    kk_box_t _box_x86 = month_names._cons._Optional.value;
    kk_std_core_types__list _uniq_month_names_378 = kk_std_core_types__list_unbox(_box_x86, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_month_names_378, _ctx);
    kk_std_core_types__optional_drop(month_names, _ctx);
    _x_x1296 = _uniq_month_names_378; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(month_names, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1297 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_std_core_types__list _x_1 = _con_x1297->month_names;
      kk_std_core_types__list_dup(_x_1, _ctx);
      _x_x1296 = _x_1; /*list<string>*/
    }
  }
  kk_std_core_types__list _x_x1298;
  if (kk_std_core_types__is_Optional(month_names_short, _ctx)) {
    kk_box_t _box_x87 = month_names_short._cons._Optional.value;
    kk_std_core_types__list _uniq_month_names_short_386 = kk_std_core_types__list_unbox(_box_x87, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_month_names_short_386, _ctx);
    kk_std_core_types__optional_drop(month_names_short, _ctx);
    _x_x1298 = _uniq_month_names_short_386; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(month_names_short, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1299 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_std_core_types__list _x_2 = _con_x1299->month_names_short;
      kk_std_core_types__list_dup(_x_2, _ctx);
      _x_x1298 = _x_2; /*list<string>*/
    }
  }
  kk_std_core_types__list _x_x1300;
  if (kk_std_core_types__is_Optional(day_names_short, _ctx)) {
    kk_box_t _box_x88 = day_names_short._cons._Optional.value;
    kk_std_core_types__list _uniq_day_names_short_394 = kk_std_core_types__list_unbox(_box_x88, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_day_names_short_394, _ctx);
    kk_std_core_types__optional_drop(day_names_short, _ctx);
    _x_x1300 = _uniq_day_names_short_394; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(day_names_short, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1301 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_std_core_types__list _x_3 = _con_x1301->day_names_short;
      kk_std_core_types__list_dup(_x_3, _ctx);
      _x_x1300 = _x_3; /*list<string>*/
    }
  }
  kk_std_core_types__list _x_x1302;
  if (kk_std_core_types__is_Optional(day_names_min, _ctx)) {
    kk_box_t _box_x89 = day_names_min._cons._Optional.value;
    kk_std_core_types__list _uniq_day_names_min_402 = kk_std_core_types__list_unbox(_box_x89, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_day_names_min_402, _ctx);
    kk_std_core_types__optional_drop(day_names_min, _ctx);
    _x_x1302 = _uniq_day_names_min_402; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(day_names_min, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1303 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_std_core_types__list _x_4 = _con_x1303->day_names_min;
      kk_std_core_types__list_dup(_x_4, _ctx);
      _x_x1302 = _x_4; /*list<string>*/
    }
  }
  kk_string_t _x_x1304;
  if (kk_std_core_types__is_Optional(format_t, _ctx)) {
    kk_box_t _box_x90 = format_t._cons._Optional.value;
    kk_string_t _uniq_format_t_410 = kk_string_unbox(_box_x90);
    kk_string_dup(_uniq_format_t_410, _ctx);
    kk_std_core_types__optional_drop(format_t, _ctx);
    _x_x1304 = _uniq_format_t_410; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_t, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1305 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x_5 = _con_x1305->format_t;
      kk_string_dup(_x_5, _ctx);
      _x_x1304 = _x_5; /*string*/
    }
  }
  kk_string_t _x_x1306;
  if (kk_std_core_types__is_Optional(format_tt, _ctx)) {
    kk_box_t _box_x91 = format_tt._cons._Optional.value;
    kk_string_t _uniq_format_tt_418 = kk_string_unbox(_box_x91);
    kk_string_dup(_uniq_format_tt_418, _ctx);
    kk_std_core_types__optional_drop(format_tt, _ctx);
    _x_x1306 = _uniq_format_tt_418; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_tt, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1307 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x_6 = _con_x1307->format_tt;
      kk_string_dup(_x_6, _ctx);
      _x_x1306 = _x_6; /*string*/
    }
  }
  kk_string_t _x_x1308;
  if (kk_std_core_types__is_Optional(format_l, _ctx)) {
    kk_box_t _box_x92 = format_l._cons._Optional.value;
    kk_string_t _uniq_format_l_426 = kk_string_unbox(_box_x92);
    kk_string_dup(_uniq_format_l_426, _ctx);
    kk_std_core_types__optional_drop(format_l, _ctx);
    _x_x1308 = _uniq_format_l_426; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_l, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1309 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x_7 = _con_x1309->format_l;
      kk_string_dup(_x_7, _ctx);
      _x_x1308 = _x_7; /*string*/
    }
  }
  kk_string_t _x_x1310;
  if (kk_std_core_types__is_Optional(format_ll, _ctx)) {
    kk_box_t _box_x93 = format_ll._cons._Optional.value;
    kk_string_t _uniq_format_ll_434 = kk_string_unbox(_box_x93);
    kk_string_dup(_uniq_format_ll_434, _ctx);
    kk_std_core_types__optional_drop(format_ll, _ctx);
    _x_x1310 = _uniq_format_ll_434; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_ll, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1311 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x_8 = _con_x1311->format_ll;
      kk_string_dup(_x_8, _ctx);
      _x_x1310 = _x_8; /*string*/
    }
  }
  kk_string_t _x_x1312;
  if (kk_std_core_types__is_Optional(format_lll, _ctx)) {
    kk_box_t _box_x94 = format_lll._cons._Optional.value;
    kk_string_t _uniq_format_lll_442 = kk_string_unbox(_box_x94);
    kk_string_dup(_uniq_format_lll_442, _ctx);
    kk_std_core_types__optional_drop(format_lll, _ctx);
    _x_x1312 = _uniq_format_lll_442; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_lll, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1313 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x_9 = _con_x1313->format_lll;
      kk_string_dup(_x_9, _ctx);
      _x_x1312 = _x_9; /*string*/
    }
  }
  kk_string_t _x_x1314;
  if (kk_std_core_types__is_Optional(format_llll, _ctx)) {
    kk_box_t _box_x95 = format_llll._cons._Optional.value;
    kk_string_t _uniq_format_llll_450 = kk_string_unbox(_box_x95);
    kk_string_dup(_uniq_format_llll_450, _ctx);
    kk_std_core_types__optional_drop(format_llll, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(12)), _ctx);
    _x_x1314 = _uniq_format_llll_450; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_llll, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x1315 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _pat_0_11 = _con_x1315->lang_name;
      kk_std_core_types__list _pat_1_12 = _con_x1315->day_names;
      kk_std_core_types__list _pat_2_11 = _con_x1315->month_names;
      kk_std_core_types__list _pat_3_11 = _con_x1315->month_names_short;
      kk_std_core_types__list _pat_4_11 = _con_x1315->day_names_short;
      kk_std_core_types__list _pat_5_11 = _con_x1315->day_names_min;
      kk_string_t _pat_6_11 = _con_x1315->format_t;
      kk_string_t _pat_7_11 = _con_x1315->format_tt;
      kk_string_t _pat_8_11 = _con_x1315->format_l;
      kk_string_t _pat_9_11 = _con_x1315->format_ll;
      kk_string_t _pat_10_11 = _con_x1315->format_lll;
      kk_string_t _x_10 = _con_x1315->format_llll;
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
      _x_x1314 = _x_10; /*string*/
    }
  }
  return kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1292, _x_x1294, _x_x1296, _x_x1298, _x_x1300, _x_x1302, _x_x1304, _x_x1306, _x_x1308, _x_x1310, _x_x1312, _x_x1314, _ctx);
}
 
// lifted local: @lift-time-locale-en@10409, @uniq-month-names-short@92, time-locale-en, @spec-x10278
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10273, using:
// @uniq-f@10273 = fn(m: string){
//   val n@10037 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10037) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@1: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@0: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@0: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10037) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_10410(kk_std_core_types__list _uniq_xs_10272, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10272, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1316 = kk_std_core_types__as_Cons(_uniq_xs_10272, _ctx);
    kk_box_t _box_x96 = _con_x1316->head;
    kk_std_core_types__list _uniq_xx_10276 = _con_x1316->tail;
    kk_string_t _uniq_x_10275 = kk_string_unbox(_box_x96);
    kk_reuse_t _ru_x1236 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10272, _ctx)) {
      _ru_x1236 = (kk_datatype_ptr_reuse(_uniq_xs_10272, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10275, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10276, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10272, _ctx);
    }
    kk_std_core_types__optional n_10037 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(_uniq_x_10275, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10440;
    kk_std_core_sslice__sslice _x_x1317;
    bool _match_x1193;
    kk_integer_t _brw_x1196;
    if (kk_std_core_types__is_Optional(n_10037, _ctx)) {
      kk_box_t _box_x99 = n_10037._cons._Optional.value;
      kk_integer_t _uniq_n_414 = kk_integer_unbox(_box_x99, _ctx);
      kk_integer_dup(_uniq_n_414, _ctx);
      _brw_x1196 = _uniq_n_414; /*int*/
    }
    else {
      _brw_x1196 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1197 = kk_integer_eq_borrow(_brw_x1196,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1196, _ctx);
    _match_x1193 = _brw_x1197; /*bool*/
    if (_match_x1193) {
      kk_std_core_types__optional_drop(n_10037, _ctx);
      _x_x1317 = slice_0; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1194;
      kk_integer_t _x_x1318;
      if (kk_std_core_types__is_Optional(n_10037, _ctx)) {
        kk_box_t _box_x100 = n_10037._cons._Optional.value;
        kk_integer_t _uniq_n_414_0 = kk_integer_unbox(_box_x100, _ctx);
        kk_integer_dup(_uniq_n_414_0, _ctx);
        kk_std_core_types__optional_drop(n_10037, _ctx);
        _x_x1318 = _uniq_n_414_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_10037, _ctx);
        _x_x1318 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1194 = kk_integer_add_small_const(_x_x1318, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1195 = kk_std_core_sslice_extend(slice_0, _brw_x1194, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1194, _ctx);
      _x_x1317 = _brw_x1195; /*sslice/sslice*/
    }
    _trmc_x10440 = kk_std_core_sslice_string(_x_x1317, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10441 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10442 = kk_std_core_types__new_Cons(_ru_x1236, 0, kk_string_box(_trmc_x10440), _trmc_x10441, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x110_115 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10442, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1191;
    kk_std_core_types__cctx _x_x1319 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1191 = kk_cctx_extend_linear(_x_x1319,(kk_std_core_types__list_box(_trmc_x10442, _ctx)),_b_x110_115,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1192 = kk_std_time_locale__trmc_lift_time_locale_en_10410(_uniq_xx_10276, _brw_x1191, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1191, _ctx);
    return _brw_x1192;
  }
  {
    kk_box_t _x_x1320;
    kk_std_core_types__cctx _x_x1321 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1320 = kk_cctx_apply_linear(_x_x1321,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1320, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-time-locale-en@10409, @uniq-month-names-short@92, time-locale-en, @spec-x10278
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10273, using:
// @uniq-f@10273 = fn(m: string){
//   val n@10037 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10037) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@1: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@0: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@0: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10037) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10410(kk_std_core_types__list _uniq_xs_10272_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1189 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1190 = kk_std_time_locale__trmc_lift_time_locale_en_10410(_uniq_xs_10272_0, _brw_x1189, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1189, _ctx);
  return _brw_x1190;
}
 
// lifted local: @uniq-month-names-short@92, time-locale-en, @spec-x10271
// specialized: std/core/list/map, on parameters @uniq-f@10268, using:
// @uniq-f@10268 = fn(m: string){
//   val n@10037 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10037) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@1: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@0: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@0: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10037) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10409(kk_std_core_types__list _uniq_xs_10267, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10267, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1187 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1188 = kk_std_time_locale__trmc_lift_time_locale_en_10410(_uniq_xs_10267, _brw_x1187, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1187, _ctx);
    return _brw_x1188;
  }
}
 
// lifted local: @lift-time-locale-en@10411, @uniq-day-names-short@153, time-locale-en, @spec-x10291
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10286, using:
// @uniq-f@10286 = fn(m@0: string){
//   val n@0@10039 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10039) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@4: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@1: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@2: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10039) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@0: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_10412(kk_std_core_types__list _uniq_xs_10285, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10285, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1322 = kk_std_core_types__as_Cons(_uniq_xs_10285, _ctx);
    kk_box_t _box_x121 = _con_x1322->head;
    kk_std_core_types__list _uniq_xx_10289 = _con_x1322->tail;
    kk_string_t _uniq_x_10288 = kk_string_unbox(_box_x121);
    kk_reuse_t _ru_x1237 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10285, _ctx)) {
      _ru_x1237 = (kk_datatype_ptr_reuse(_uniq_xs_10285, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10288, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10289, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10285, _ctx);
    }
    kk_std_core_types__optional n_0_10039 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0_0 = kk_std_core_sslice_first1(_uniq_x_10288, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10443;
    kk_std_core_sslice__sslice _x_x1323;
    bool _match_x1182;
    kk_integer_t _brw_x1185;
    if (kk_std_core_types__is_Optional(n_0_10039, _ctx)) {
      kk_box_t _box_x124 = n_0_10039._cons._Optional.value;
      kk_integer_t _uniq_n_414_1 = kk_integer_unbox(_box_x124, _ctx);
      kk_integer_dup(_uniq_n_414_1, _ctx);
      _brw_x1185 = _uniq_n_414_1; /*int*/
    }
    else {
      _brw_x1185 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1186 = kk_integer_eq_borrow(_brw_x1185,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1185, _ctx);
    _match_x1182 = _brw_x1186; /*bool*/
    if (_match_x1182) {
      kk_std_core_types__optional_drop(n_0_10039, _ctx);
      _x_x1323 = slice_0_0; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1183;
      kk_integer_t _x_x1324;
      if (kk_std_core_types__is_Optional(n_0_10039, _ctx)) {
        kk_box_t _box_x125 = n_0_10039._cons._Optional.value;
        kk_integer_t _uniq_n_414_0_0 = kk_integer_unbox(_box_x125, _ctx);
        kk_integer_dup(_uniq_n_414_0_0, _ctx);
        kk_std_core_types__optional_drop(n_0_10039, _ctx);
        _x_x1324 = _uniq_n_414_0_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_0_10039, _ctx);
        _x_x1324 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1183 = kk_integer_add_small_const(_x_x1324, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1184 = kk_std_core_sslice_extend(slice_0_0, _brw_x1183, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1183, _ctx);
      _x_x1323 = _brw_x1184; /*sslice/sslice*/
    }
    _trmc_x10443 = kk_std_core_sslice_string(_x_x1323, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10444 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10445 = kk_std_core_types__new_Cons(_ru_x1237, 0, kk_string_box(_trmc_x10443), _trmc_x10444, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x135_140 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10445, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1180;
    kk_std_core_types__cctx _x_x1325 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1180 = kk_cctx_extend_linear(_x_x1325,(kk_std_core_types__list_box(_trmc_x10445, _ctx)),_b_x135_140,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1181 = kk_std_time_locale__trmc_lift_time_locale_en_10412(_uniq_xx_10289, _brw_x1180, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1180, _ctx);
    return _brw_x1181;
  }
  {
    kk_box_t _x_x1326;
    kk_std_core_types__cctx _x_x1327 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1326 = kk_cctx_apply_linear(_x_x1327,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1326, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-time-locale-en@10411, @uniq-day-names-short@153, time-locale-en, @spec-x10291
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10286, using:
// @uniq-f@10286 = fn(m@0: string){
//   val n@0@10039 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10039) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@4: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@1: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@2: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10039) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@0: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10412(kk_std_core_types__list _uniq_xs_10285_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1178 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1179 = kk_std_time_locale__trmc_lift_time_locale_en_10412(_uniq_xs_10285_0, _brw_x1178, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1178, _ctx);
  return _brw_x1179;
}
 
// lifted local: @uniq-day-names-short@153, time-locale-en, @spec-x10284
// specialized: std/core/list/map, on parameters @uniq-f@10281, using:
// @uniq-f@10281 = fn(m@0: string){
//   val n@0@10039 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10039) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@4: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@1: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@2: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10039) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@0: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10411(kk_std_core_types__list _uniq_xs_10280, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10280, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1176 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1177 = kk_std_time_locale__trmc_lift_time_locale_en_10412(_uniq_xs_10280, _brw_x1176, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1176, _ctx);
    return _brw_x1177;
  }
}
 
// lifted local: @lift-time-locale-en@10413, @uniq-day-names-min@214, time-locale-en, @spec-x10304
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10299, using:
// @uniq-f@10299 = fn(m@1: string){
//   val n@1@10041 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10041) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@5: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@2: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10041) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_10414(kk_std_core_types__list _uniq_xs_10298, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10298, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1328 = kk_std_core_types__as_Cons(_uniq_xs_10298, _ctx);
    kk_box_t _box_x146 = _con_x1328->head;
    kk_std_core_types__list _uniq_xx_10302 = _con_x1328->tail;
    kk_string_t _uniq_x_10301 = kk_string_unbox(_box_x146);
    kk_reuse_t _ru_x1238 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10298, _ctx)) {
      _ru_x1238 = (kk_datatype_ptr_reuse(_uniq_xs_10298, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10301, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10302, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10298, _ctx);
    }
    kk_std_core_types__optional n_1_10041 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0_1 = kk_std_core_sslice_first1(_uniq_x_10301, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10446;
    kk_std_core_sslice__sslice _x_x1329;
    bool _match_x1171;
    kk_integer_t _brw_x1174;
    if (kk_std_core_types__is_Optional(n_1_10041, _ctx)) {
      kk_box_t _box_x149 = n_1_10041._cons._Optional.value;
      kk_integer_t _uniq_n_414_2 = kk_integer_unbox(_box_x149, _ctx);
      kk_integer_dup(_uniq_n_414_2, _ctx);
      _brw_x1174 = _uniq_n_414_2; /*int*/
    }
    else {
      _brw_x1174 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1175 = kk_integer_eq_borrow(_brw_x1174,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1174, _ctx);
    _match_x1171 = _brw_x1175; /*bool*/
    if (_match_x1171) {
      kk_std_core_types__optional_drop(n_1_10041, _ctx);
      _x_x1329 = slice_0_1; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1172;
      kk_integer_t _x_x1330;
      if (kk_std_core_types__is_Optional(n_1_10041, _ctx)) {
        kk_box_t _box_x150 = n_1_10041._cons._Optional.value;
        kk_integer_t _uniq_n_414_0_1 = kk_integer_unbox(_box_x150, _ctx);
        kk_integer_dup(_uniq_n_414_0_1, _ctx);
        kk_std_core_types__optional_drop(n_1_10041, _ctx);
        _x_x1330 = _uniq_n_414_0_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_1_10041, _ctx);
        _x_x1330 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1172 = kk_integer_add_small_const(_x_x1330, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1173 = kk_std_core_sslice_extend(slice_0_1, _brw_x1172, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1172, _ctx);
      _x_x1329 = _brw_x1173; /*sslice/sslice*/
    }
    _trmc_x10446 = kk_std_core_sslice_string(_x_x1329, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10447 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10448 = kk_std_core_types__new_Cons(_ru_x1238, 0, kk_string_box(_trmc_x10446), _trmc_x10447, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x160_165 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10448, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1169;
    kk_std_core_types__cctx _x_x1331 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1169 = kk_cctx_extend_linear(_x_x1331,(kk_std_core_types__list_box(_trmc_x10448, _ctx)),_b_x160_165,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1170 = kk_std_time_locale__trmc_lift_time_locale_en_10414(_uniq_xx_10302, _brw_x1169, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1169, _ctx);
    return _brw_x1170;
  }
  {
    kk_box_t _x_x1332;
    kk_std_core_types__cctx _x_x1333 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1332 = kk_cctx_apply_linear(_x_x1333,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1332, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-time-locale-en@10413, @uniq-day-names-min@214, time-locale-en, @spec-x10304
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10299, using:
// @uniq-f@10299 = fn(m@1: string){
//   val n@1@10041 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10041) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@5: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@2: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10041) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10414(kk_std_core_types__list _uniq_xs_10298_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1167 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1168 = kk_std_time_locale__trmc_lift_time_locale_en_10414(_uniq_xs_10298_0, _brw_x1167, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1167, _ctx);
  return _brw_x1168;
}
 
// lifted local: @uniq-day-names-min@214, time-locale-en, @spec-x10297
// specialized: std/core/list/map, on parameters @uniq-f@10294, using:
// @uniq-f@10294 = fn(m@1: string){
//   val n@1@10041 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10041) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@5: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@2: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10041) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10413(kk_std_core_types__list _uniq_xs_10293, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10293, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1165 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1166 = kk_std_time_locale__trmc_lift_time_locale_en_10414(_uniq_xs_10293, _brw_x1165, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1165, _ctx);
    return _brw_x1166;
  }
}
 
// English time locale (`en`)

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_en;
 
// lifted local: @lift-time-locale-en-iso@10415, @uniq-month-names-short@92, time-locale-en-iso, @spec-x10317
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10312, using:
// @uniq-f@10312 = fn(m: string){
//   val n@10043 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10043) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@13: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@1: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10043) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3@1: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_iso_10416(kk_std_core_types__list _uniq_xs_10311, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10311, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1425 = kk_std_core_types__as_Cons(_uniq_xs_10311, _ctx);
    kk_box_t _box_x252 = _con_x1425->head;
    kk_std_core_types__list _uniq_xx_10315 = _con_x1425->tail;
    kk_string_t _uniq_x_10314 = kk_string_unbox(_box_x252);
    kk_reuse_t _ru_x1239 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10311, _ctx)) {
      _ru_x1239 = (kk_datatype_ptr_reuse(_uniq_xs_10311, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10314, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10315, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10311, _ctx);
    }
    kk_std_core_types__optional n_10043 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(_uniq_x_10314, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10449;
    kk_std_core_sslice__sslice _x_x1426;
    bool _match_x1155;
    kk_integer_t _brw_x1158;
    if (kk_std_core_types__is_Optional(n_10043, _ctx)) {
      kk_box_t _box_x255 = n_10043._cons._Optional.value;
      kk_integer_t _uniq_n_414 = kk_integer_unbox(_box_x255, _ctx);
      kk_integer_dup(_uniq_n_414, _ctx);
      _brw_x1158 = _uniq_n_414; /*int*/
    }
    else {
      _brw_x1158 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1159 = kk_integer_eq_borrow(_brw_x1158,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1158, _ctx);
    _match_x1155 = _brw_x1159; /*bool*/
    if (_match_x1155) {
      kk_std_core_types__optional_drop(n_10043, _ctx);
      _x_x1426 = slice_0; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1156;
      kk_integer_t _x_x1427;
      if (kk_std_core_types__is_Optional(n_10043, _ctx)) {
        kk_box_t _box_x256 = n_10043._cons._Optional.value;
        kk_integer_t _uniq_n_414_0 = kk_integer_unbox(_box_x256, _ctx);
        kk_integer_dup(_uniq_n_414_0, _ctx);
        kk_std_core_types__optional_drop(n_10043, _ctx);
        _x_x1427 = _uniq_n_414_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_10043, _ctx);
        _x_x1427 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1156 = kk_integer_add_small_const(_x_x1427, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1157 = kk_std_core_sslice_extend(slice_0, _brw_x1156, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1156, _ctx);
      _x_x1426 = _brw_x1157; /*sslice/sslice*/
    }
    _trmc_x10449 = kk_std_core_sslice_string(_x_x1426, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10450 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10451 = kk_std_core_types__new_Cons(_ru_x1239, 0, kk_string_box(_trmc_x10449), _trmc_x10450, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x266_271 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10451, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1153;
    kk_std_core_types__cctx _x_x1428 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1153 = kk_cctx_extend_linear(_x_x1428,(kk_std_core_types__list_box(_trmc_x10451, _ctx)),_b_x266_271,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1154 = kk_std_time_locale__trmc_lift_time_locale_en_iso_10416(_uniq_xx_10315, _brw_x1153, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1153, _ctx);
    return _brw_x1154;
  }
  {
    kk_box_t _x_x1429;
    kk_std_core_types__cctx _x_x1430 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1429 = kk_cctx_apply_linear(_x_x1430,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1429, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-time-locale-en-iso@10415, @uniq-month-names-short@92, time-locale-en-iso, @spec-x10317
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10312, using:
// @uniq-f@10312 = fn(m: string){
//   val n@10043 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10043) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@13: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@1: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10043) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3@1: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10416(kk_std_core_types__list _uniq_xs_10311_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1151 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1152 = kk_std_time_locale__trmc_lift_time_locale_en_iso_10416(_uniq_xs_10311_0, _brw_x1151, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1151, _ctx);
  return _brw_x1152;
}
 
// lifted local: @uniq-month-names-short@92, time-locale-en-iso, @spec-x10310
// specialized: std/core/list/map, on parameters @uniq-f@10307, using:
// @uniq-f@10307 = fn(m: string){
//   val n@10043 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10043) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@13: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@1: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10043) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3@1: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10415(kk_std_core_types__list _uniq_xs_10306, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10306, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1149 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1150 = kk_std_time_locale__trmc_lift_time_locale_en_iso_10416(_uniq_xs_10306, _brw_x1149, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1149, _ctx);
    return _brw_x1150;
  }
}
 
// lifted local: @lift-time-locale-en-iso@10417, @uniq-day-names-short@153, time-locale-en-iso, @spec-x10330
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10325, using:
// @uniq-f@10325 = fn(m@0: string){
//   val n@0@10045 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10045) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@14: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@3: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@3: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10045) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_iso_10418(kk_std_core_types__list _uniq_xs_10324, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10324, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1431 = kk_std_core_types__as_Cons(_uniq_xs_10324, _ctx);
    kk_box_t _box_x277 = _con_x1431->head;
    kk_std_core_types__list _uniq_xx_10328 = _con_x1431->tail;
    kk_string_t _uniq_x_10327 = kk_string_unbox(_box_x277);
    kk_reuse_t _ru_x1240 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10324, _ctx)) {
      _ru_x1240 = (kk_datatype_ptr_reuse(_uniq_xs_10324, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10327, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10328, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10324, _ctx);
    }
    kk_std_core_types__optional n_0_10045 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0_0 = kk_std_core_sslice_first1(_uniq_x_10327, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10452;
    kk_std_core_sslice__sslice _x_x1432;
    bool _match_x1144;
    kk_integer_t _brw_x1147;
    if (kk_std_core_types__is_Optional(n_0_10045, _ctx)) {
      kk_box_t _box_x280 = n_0_10045._cons._Optional.value;
      kk_integer_t _uniq_n_414_1 = kk_integer_unbox(_box_x280, _ctx);
      kk_integer_dup(_uniq_n_414_1, _ctx);
      _brw_x1147 = _uniq_n_414_1; /*int*/
    }
    else {
      _brw_x1147 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1148 = kk_integer_eq_borrow(_brw_x1147,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1147, _ctx);
    _match_x1144 = _brw_x1148; /*bool*/
    if (_match_x1144) {
      kk_std_core_types__optional_drop(n_0_10045, _ctx);
      _x_x1432 = slice_0_0; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1145;
      kk_integer_t _x_x1433;
      if (kk_std_core_types__is_Optional(n_0_10045, _ctx)) {
        kk_box_t _box_x281 = n_0_10045._cons._Optional.value;
        kk_integer_t _uniq_n_414_0_0 = kk_integer_unbox(_box_x281, _ctx);
        kk_integer_dup(_uniq_n_414_0_0, _ctx);
        kk_std_core_types__optional_drop(n_0_10045, _ctx);
        _x_x1433 = _uniq_n_414_0_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_0_10045, _ctx);
        _x_x1433 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1145 = kk_integer_add_small_const(_x_x1433, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1146 = kk_std_core_sslice_extend(slice_0_0, _brw_x1145, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1145, _ctx);
      _x_x1432 = _brw_x1146; /*sslice/sslice*/
    }
    _trmc_x10452 = kk_std_core_sslice_string(_x_x1432, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10453 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10454 = kk_std_core_types__new_Cons(_ru_x1240, 0, kk_string_box(_trmc_x10452), _trmc_x10453, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x291_296 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10454, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1142;
    kk_std_core_types__cctx _x_x1434 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1142 = kk_cctx_extend_linear(_x_x1434,(kk_std_core_types__list_box(_trmc_x10454, _ctx)),_b_x291_296,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1143 = kk_std_time_locale__trmc_lift_time_locale_en_iso_10418(_uniq_xx_10328, _brw_x1142, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1142, _ctx);
    return _brw_x1143;
  }
  {
    kk_box_t _x_x1435;
    kk_std_core_types__cctx _x_x1436 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1435 = kk_cctx_apply_linear(_x_x1436,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1435, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-time-locale-en-iso@10417, @uniq-day-names-short@153, time-locale-en-iso, @spec-x10330
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10325, using:
// @uniq-f@10325 = fn(m@0: string){
//   val n@0@10045 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10045) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@14: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@3: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@3: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10045) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10418(kk_std_core_types__list _uniq_xs_10324_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1140 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1141 = kk_std_time_locale__trmc_lift_time_locale_en_iso_10418(_uniq_xs_10324_0, _brw_x1140, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1140, _ctx);
  return _brw_x1141;
}
 
// lifted local: @uniq-day-names-short@153, time-locale-en-iso, @spec-x10323
// specialized: std/core/list/map, on parameters @uniq-f@10320, using:
// @uniq-f@10320 = fn(m@0: string){
//   val n@0@10045 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10045) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@14: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@3: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@3: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10045) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10417(kk_std_core_types__list _uniq_xs_10319, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10319, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1138 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1139 = kk_std_time_locale__trmc_lift_time_locale_en_iso_10418(_uniq_xs_10319, _brw_x1138, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1138, _ctx);
    return _brw_x1139;
  }
}
 
// lifted local: @lift-time-locale-en-iso@10419, @uniq-day-names-min@214, time-locale-en-iso, @spec-x10343
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10338, using:
// @uniq-f@10338 = fn(m@1: string){
//   val n@1@10047 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10047) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@15: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@4: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@4: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@4: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10047) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@4: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_iso_10420(kk_std_core_types__list _uniq_xs_10337, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10337, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1437 = kk_std_core_types__as_Cons(_uniq_xs_10337, _ctx);
    kk_box_t _box_x302 = _con_x1437->head;
    kk_std_core_types__list _uniq_xx_10341 = _con_x1437->tail;
    kk_string_t _uniq_x_10340 = kk_string_unbox(_box_x302);
    kk_reuse_t _ru_x1241 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10337, _ctx)) {
      _ru_x1241 = (kk_datatype_ptr_reuse(_uniq_xs_10337, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10340, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10341, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10337, _ctx);
    }
    kk_std_core_types__optional n_1_10047 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0_1 = kk_std_core_sslice_first1(_uniq_x_10340, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10455;
    kk_std_core_sslice__sslice _x_x1438;
    bool _match_x1133;
    kk_integer_t _brw_x1136;
    if (kk_std_core_types__is_Optional(n_1_10047, _ctx)) {
      kk_box_t _box_x305 = n_1_10047._cons._Optional.value;
      kk_integer_t _uniq_n_414_2 = kk_integer_unbox(_box_x305, _ctx);
      kk_integer_dup(_uniq_n_414_2, _ctx);
      _brw_x1136 = _uniq_n_414_2; /*int*/
    }
    else {
      _brw_x1136 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1137 = kk_integer_eq_borrow(_brw_x1136,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1136, _ctx);
    _match_x1133 = _brw_x1137; /*bool*/
    if (_match_x1133) {
      kk_std_core_types__optional_drop(n_1_10047, _ctx);
      _x_x1438 = slice_0_1; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1134;
      kk_integer_t _x_x1439;
      if (kk_std_core_types__is_Optional(n_1_10047, _ctx)) {
        kk_box_t _box_x306 = n_1_10047._cons._Optional.value;
        kk_integer_t _uniq_n_414_0_1 = kk_integer_unbox(_box_x306, _ctx);
        kk_integer_dup(_uniq_n_414_0_1, _ctx);
        kk_std_core_types__optional_drop(n_1_10047, _ctx);
        _x_x1439 = _uniq_n_414_0_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_1_10047, _ctx);
        _x_x1439 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1134 = kk_integer_add_small_const(_x_x1439, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1135 = kk_std_core_sslice_extend(slice_0_1, _brw_x1134, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1134, _ctx);
      _x_x1438 = _brw_x1135; /*sslice/sslice*/
    }
    _trmc_x10455 = kk_std_core_sslice_string(_x_x1438, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10456 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10457 = kk_std_core_types__new_Cons(_ru_x1241, 0, kk_string_box(_trmc_x10455), _trmc_x10456, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x316_321 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10457, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1131;
    kk_std_core_types__cctx _x_x1440 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1131 = kk_cctx_extend_linear(_x_x1440,(kk_std_core_types__list_box(_trmc_x10457, _ctx)),_b_x316_321,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1132 = kk_std_time_locale__trmc_lift_time_locale_en_iso_10420(_uniq_xx_10341, _brw_x1131, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1131, _ctx);
    return _brw_x1132;
  }
  {
    kk_box_t _x_x1441;
    kk_std_core_types__cctx _x_x1442 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1441 = kk_cctx_apply_linear(_x_x1442,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1441, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-time-locale-en-iso@10419, @uniq-day-names-min@214, time-locale-en-iso, @spec-x10343
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10338, using:
// @uniq-f@10338 = fn(m@1: string){
//   val n@1@10047 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10047) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@15: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@4: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@4: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@4: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10047) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@4: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10420(kk_std_core_types__list _uniq_xs_10337_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1129 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1130 = kk_std_time_locale__trmc_lift_time_locale_en_iso_10420(_uniq_xs_10337_0, _brw_x1129, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1129, _ctx);
  return _brw_x1130;
}
 
// lifted local: @uniq-day-names-min@214, time-locale-en-iso, @spec-x10336
// specialized: std/core/list/map, on parameters @uniq-f@10333, using:
// @uniq-f@10333 = fn(m@1: string){
//   val n@1@10047 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10047) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@15: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@4: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@4: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@4: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10047) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@4: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10419(kk_std_core_types__list _uniq_xs_10332, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10332, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1127 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1128 = kk_std_time_locale__trmc_lift_time_locale_en_iso_10420(_uniq_xs_10332, _brw_x1127, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1127, _ctx);
    return _brw_x1128;
  }
}
 
// ISO English time locale (`en-iso`). Uses English names for
// months and days but displays numeric dates and times using unambigious ISO format.

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_en_iso;
 
// French time locale (`fr`)

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_fr;
 
// German time locale (`de`)

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_de;
 
// lifted local: @lift-time-locale-es@10421, @uniq-month-names-short@92, time-locale-es, @spec-x10356
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10351, using:
// @uniq-f@10351 = fn(m: string){
//   val n@10099 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10099) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@1: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@0: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@0: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10099) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_es_10422(kk_std_core_types__list _uniq_xs_10350, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10350, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1860 = kk_std_core_types__as_Cons(_uniq_xs_10350, _ctx);
    kk_box_t _box_x701 = _con_x1860->head;
    kk_std_core_types__list _uniq_xx_10354 = _con_x1860->tail;
    kk_string_t _uniq_x_10353 = kk_string_unbox(_box_x701);
    kk_reuse_t _ru_x1242 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10350, _ctx)) {
      _ru_x1242 = (kk_datatype_ptr_reuse(_uniq_xs_10350, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10353, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10354, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10350, _ctx);
    }
    kk_std_core_types__optional n_10099 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(_uniq_x_10353, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10458;
    kk_std_core_sslice__sslice _x_x1861;
    bool _match_x1108;
    kk_integer_t _brw_x1111;
    if (kk_std_core_types__is_Optional(n_10099, _ctx)) {
      kk_box_t _box_x704 = n_10099._cons._Optional.value;
      kk_integer_t _uniq_n_414 = kk_integer_unbox(_box_x704, _ctx);
      kk_integer_dup(_uniq_n_414, _ctx);
      _brw_x1111 = _uniq_n_414; /*int*/
    }
    else {
      _brw_x1111 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1112 = kk_integer_eq_borrow(_brw_x1111,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1111, _ctx);
    _match_x1108 = _brw_x1112; /*bool*/
    if (_match_x1108) {
      kk_std_core_types__optional_drop(n_10099, _ctx);
      _x_x1861 = slice_0; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1109;
      kk_integer_t _x_x1862;
      if (kk_std_core_types__is_Optional(n_10099, _ctx)) {
        kk_box_t _box_x705 = n_10099._cons._Optional.value;
        kk_integer_t _uniq_n_414_0 = kk_integer_unbox(_box_x705, _ctx);
        kk_integer_dup(_uniq_n_414_0, _ctx);
        kk_std_core_types__optional_drop(n_10099, _ctx);
        _x_x1862 = _uniq_n_414_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_10099, _ctx);
        _x_x1862 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1109 = kk_integer_add_small_const(_x_x1862, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1110 = kk_std_core_sslice_extend(slice_0, _brw_x1109, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1109, _ctx);
      _x_x1861 = _brw_x1110; /*sslice/sslice*/
    }
    _trmc_x10458 = kk_std_core_sslice_string(_x_x1861, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10459 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10460 = kk_std_core_types__new_Cons(_ru_x1242, 0, kk_string_box(_trmc_x10458), _trmc_x10459, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x715_720 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10460, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1106;
    kk_std_core_types__cctx _x_x1863 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1106 = kk_cctx_extend_linear(_x_x1863,(kk_std_core_types__list_box(_trmc_x10460, _ctx)),_b_x715_720,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1107 = kk_std_time_locale__trmc_lift_time_locale_es_10422(_uniq_xx_10354, _brw_x1106, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1106, _ctx);
    return _brw_x1107;
  }
  {
    kk_box_t _x_x1864;
    kk_std_core_types__cctx _x_x1865 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1864 = kk_cctx_apply_linear(_x_x1865,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1864, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-time-locale-es@10421, @uniq-month-names-short@92, time-locale-es, @spec-x10356
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10351, using:
// @uniq-f@10351 = fn(m: string){
//   val n@10099 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10099) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@1: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@0: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@0: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10099) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10422(kk_std_core_types__list _uniq_xs_10350_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1104 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1105 = kk_std_time_locale__trmc_lift_time_locale_es_10422(_uniq_xs_10350_0, _brw_x1104, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1104, _ctx);
  return _brw_x1105;
}
 
// lifted local: @uniq-month-names-short@92, time-locale-es, @spec-x10349
// specialized: std/core/list/map, on parameters @uniq-f@10346, using:
// @uniq-f@10346 = fn(m: string){
//   val n@10099 : ? int;
//   val slice@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@10099) {
//       ((std/core/types/@Optional((@uniq-n@414: int) : int) : ? int ) as @pat@1: ? int)
//          -> @uniq-n@414;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@0: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@0: bool)
//        -> slice@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2: bool)
//        -> std/core/sslice/extend(slice@0, (std/core/int/int-sub((match (n@10099) {
//             ((std/core/types/@Optional((@uniq-n@414@0: int) : int) : ? int ) as @pat@3: ? int)
//                -> @uniq-n@414@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@0: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10421(kk_std_core_types__list _uniq_xs_10345, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10345, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1102 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1103 = kk_std_time_locale__trmc_lift_time_locale_es_10422(_uniq_xs_10345, _brw_x1102, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1102, _ctx);
    return _brw_x1103;
  }
}
 
// lifted local: @lift-time-locale-es@10423, @uniq-day-names-short@153, time-locale-es, @spec-x10369
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10364, using:
// @uniq-f@10364 = fn(m@0: string){
//   val n@0@10101 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10101) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@4: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@1: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@2: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10101) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@0: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_es_10424(kk_std_core_types__list _uniq_xs_10363, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10363, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1866 = kk_std_core_types__as_Cons(_uniq_xs_10363, _ctx);
    kk_box_t _box_x726 = _con_x1866->head;
    kk_std_core_types__list _uniq_xx_10367 = _con_x1866->tail;
    kk_string_t _uniq_x_10366 = kk_string_unbox(_box_x726);
    kk_reuse_t _ru_x1243 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10363, _ctx)) {
      _ru_x1243 = (kk_datatype_ptr_reuse(_uniq_xs_10363, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10366, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10367, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10363, _ctx);
    }
    kk_std_core_types__optional n_0_10101 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0_0 = kk_std_core_sslice_first1(_uniq_x_10366, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10461;
    kk_std_core_sslice__sslice _x_x1867;
    bool _match_x1097;
    kk_integer_t _brw_x1100;
    if (kk_std_core_types__is_Optional(n_0_10101, _ctx)) {
      kk_box_t _box_x729 = n_0_10101._cons._Optional.value;
      kk_integer_t _uniq_n_414_1 = kk_integer_unbox(_box_x729, _ctx);
      kk_integer_dup(_uniq_n_414_1, _ctx);
      _brw_x1100 = _uniq_n_414_1; /*int*/
    }
    else {
      _brw_x1100 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1101 = kk_integer_eq_borrow(_brw_x1100,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1100, _ctx);
    _match_x1097 = _brw_x1101; /*bool*/
    if (_match_x1097) {
      kk_std_core_types__optional_drop(n_0_10101, _ctx);
      _x_x1867 = slice_0_0; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1098;
      kk_integer_t _x_x1868;
      if (kk_std_core_types__is_Optional(n_0_10101, _ctx)) {
        kk_box_t _box_x730 = n_0_10101._cons._Optional.value;
        kk_integer_t _uniq_n_414_0_0 = kk_integer_unbox(_box_x730, _ctx);
        kk_integer_dup(_uniq_n_414_0_0, _ctx);
        kk_std_core_types__optional_drop(n_0_10101, _ctx);
        _x_x1868 = _uniq_n_414_0_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_0_10101, _ctx);
        _x_x1868 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1098 = kk_integer_add_small_const(_x_x1868, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1099 = kk_std_core_sslice_extend(slice_0_0, _brw_x1098, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1098, _ctx);
      _x_x1867 = _brw_x1099; /*sslice/sslice*/
    }
    _trmc_x10461 = kk_std_core_sslice_string(_x_x1867, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10462 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10463 = kk_std_core_types__new_Cons(_ru_x1243, 0, kk_string_box(_trmc_x10461), _trmc_x10462, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x740_745 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10463, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1095;
    kk_std_core_types__cctx _x_x1869 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1095 = kk_cctx_extend_linear(_x_x1869,(kk_std_core_types__list_box(_trmc_x10463, _ctx)),_b_x740_745,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1096 = kk_std_time_locale__trmc_lift_time_locale_es_10424(_uniq_xx_10367, _brw_x1095, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1095, _ctx);
    return _brw_x1096;
  }
  {
    kk_box_t _x_x1870;
    kk_std_core_types__cctx _x_x1871 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1870 = kk_cctx_apply_linear(_x_x1871,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1870, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-time-locale-es@10423, @uniq-day-names-short@153, time-locale-es, @spec-x10369
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10364, using:
// @uniq-f@10364 = fn(m@0: string){
//   val n@0@10101 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10101) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@4: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@1: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@2: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10101) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@0: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10424(kk_std_core_types__list _uniq_xs_10363_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1093 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1094 = kk_std_time_locale__trmc_lift_time_locale_es_10424(_uniq_xs_10363_0, _brw_x1093, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1093, _ctx);
  return _brw_x1094;
}
 
// lifted local: @uniq-day-names-short@153, time-locale-es, @spec-x10362
// specialized: std/core/list/map, on parameters @uniq-f@10359, using:
// @uniq-f@10359 = fn(m@0: string){
//   val n@0@10101 : ? int;
//   val slice@0@0 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@0@10101) {
//       ((std/core/types/@Optional((@uniq-n@414@1: int) : int) : ? int ) as @pat@4: ? int)
//          -> @uniq-n@414@1;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@1: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@2: bool)
//        -> slice@0@0;
//     ((@skip std/core/types/False() : bool ) as @pat@2@1: bool)
//        -> std/core/sslice/extend(slice@0@0, (std/core/int/int-sub((match (n@0@10101) {
//             ((std/core/types/@Optional((@uniq-n@414@0@0: int) : int) : ? int ) as @pat@3@0: ? int)
//                -> @uniq-n@414@0@0;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@1: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10423(kk_std_core_types__list _uniq_xs_10358, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10358, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1091 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1092 = kk_std_time_locale__trmc_lift_time_locale_es_10424(_uniq_xs_10358, _brw_x1091, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1091, _ctx);
    return _brw_x1092;
  }
}
 
// lifted local: @lift-time-locale-es@10425, @uniq-day-names-min@214, time-locale-es, @spec-x10382
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10377, using:
// @uniq-f@10377 = fn(m@1: string){
//   val n@1@10103 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10103) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@5: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@2: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10103) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_es_10426(kk_std_core_types__list _uniq_xs_10376, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10376, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1872 = kk_std_core_types__as_Cons(_uniq_xs_10376, _ctx);
    kk_box_t _box_x751 = _con_x1872->head;
    kk_std_core_types__list _uniq_xx_10380 = _con_x1872->tail;
    kk_string_t _uniq_x_10379 = kk_string_unbox(_box_x751);
    kk_reuse_t _ru_x1244 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10376, _ctx)) {
      _ru_x1244 = (kk_datatype_ptr_reuse(_uniq_xs_10376, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10379, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10380, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10376, _ctx);
    }
    kk_std_core_types__optional n_1_10103 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*? int*/;
    kk_std_core_sslice__sslice slice_0_1 = kk_std_core_sslice_first1(_uniq_x_10379, _ctx); /*sslice/sslice*/;
    kk_string_t _trmc_x10464;
    kk_std_core_sslice__sslice _x_x1873;
    bool _match_x1086;
    kk_integer_t _brw_x1089;
    if (kk_std_core_types__is_Optional(n_1_10103, _ctx)) {
      kk_box_t _box_x754 = n_1_10103._cons._Optional.value;
      kk_integer_t _uniq_n_414_2 = kk_integer_unbox(_box_x754, _ctx);
      kk_integer_dup(_uniq_n_414_2, _ctx);
      _brw_x1089 = _uniq_n_414_2; /*int*/
    }
    else {
      _brw_x1089 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x1090 = kk_integer_eq_borrow(_brw_x1089,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1089, _ctx);
    _match_x1086 = _brw_x1090; /*bool*/
    if (_match_x1086) {
      kk_std_core_types__optional_drop(n_1_10103, _ctx);
      _x_x1873 = slice_0_1; /*sslice/sslice*/
    }
    else {
      kk_integer_t _brw_x1087;
      kk_integer_t _x_x1874;
      if (kk_std_core_types__is_Optional(n_1_10103, _ctx)) {
        kk_box_t _box_x755 = n_1_10103._cons._Optional.value;
        kk_integer_t _uniq_n_414_0_1 = kk_integer_unbox(_box_x755, _ctx);
        kk_integer_dup(_uniq_n_414_0_1, _ctx);
        kk_std_core_types__optional_drop(n_1_10103, _ctx);
        _x_x1874 = _uniq_n_414_0_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(n_1_10103, _ctx);
        _x_x1874 = kk_integer_from_small(1); /*int*/
      }
      _brw_x1087 = kk_integer_add_small_const(_x_x1874, -1, _ctx); /*int*/
      kk_std_core_sslice__sslice _brw_x1088 = kk_std_core_sslice_extend(slice_0_1, _brw_x1087, _ctx); /*sslice/sslice*/;
      kk_integer_drop(_brw_x1087, _ctx);
      _x_x1873 = _brw_x1088; /*sslice/sslice*/
    }
    _trmc_x10464 = kk_std_core_sslice_string(_x_x1873, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10465 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10466 = kk_std_core_types__new_Cons(_ru_x1244, 0, kk_string_box(_trmc_x10464), _trmc_x10465, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x765_770 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10466, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1084;
    kk_std_core_types__cctx _x_x1875 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1084 = kk_cctx_extend_linear(_x_x1875,(kk_std_core_types__list_box(_trmc_x10466, _ctx)),_b_x765_770,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1085 = kk_std_time_locale__trmc_lift_time_locale_es_10426(_uniq_xx_10380, _brw_x1084, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1084, _ctx);
    return _brw_x1085;
  }
  {
    kk_box_t _x_x1876;
    kk_std_core_types__cctx _x_x1877 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1876 = kk_cctx_apply_linear(_x_x1877,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1876, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-time-locale-es@10425, @uniq-day-names-min@214, time-locale-es, @spec-x10382
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10377, using:
// @uniq-f@10377 = fn(m@1: string){
//   val n@1@10103 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10103) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@5: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@2: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10103) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10426(kk_std_core_types__list _uniq_xs_10376_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1082 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1083 = kk_std_time_locale__trmc_lift_time_locale_es_10426(_uniq_xs_10376_0, _brw_x1082, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1082, _ctx);
  return _brw_x1083;
}
 
// lifted local: @uniq-day-names-min@214, time-locale-es, @spec-x10375
// specialized: std/core/list/map, on parameters @uniq-f@10372, using:
// @uniq-f@10372 = fn(m@1: string){
//   val n@1@10103 : ? int;
//   val slice@0@1 : sslice/sslice;
//   std/core/sslice/string((match ((std/core/int/(==)((match (n@1@10103) {
//       ((std/core/types/@Optional((@uniq-n@414@2: int) : int) : ? int ) as @pat@5: ? int)
//          -> @uniq-n@414@2;
//       ((@skip std/core/types/@None() : ? int ) as @pat@0@2: ? int)
//          -> 1;
//     }), 1))) {
//     ((std/core/types/True() : bool ) as @pat@1@3: bool)
//        -> slice@0@1;
//     ((@skip std/core/types/False() : bool ) as @pat@2@2: bool)
//        -> std/core/sslice/extend(slice@0@1, (std/core/int/int-sub((match (n@1@10103) {
//             ((std/core/types/@Optional((@uniq-n@414@0@1: int) : int) : ? int ) as @pat@3@2: ? int)
//                -> @uniq-n@414@0@1;
//             ((@skip std/core/types/@None() : ? int ) as @pat@0@0@2: ? int)
//                -> 1;
//           }), 1)));
//   }));
// }

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10425(kk_std_core_types__list _uniq_xs_10371, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10371, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1080 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1081 = kk_std_time_locale__trmc_lift_time_locale_es_10426(_uniq_xs_10371, _brw_x1080, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1080, _ctx);
    return _brw_x1081;
  }
}
 
// Spanish time locale (`es`)

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_es;
 
// Dutch time locale (`nl`)

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_nl;

kk_std_core_types__list kk_std_time_locale_locales;
 
// lifted local: @lift-get-time-locale@10427, get-time-locale, @spec-x10401
// specialized: std/core/list/@unroll-foreach-while@10009, on parameters @uniq-action@10394, using:
// @uniq-action@10394 = fn(@uniq-x@10388: std/time/locale/time-locale){
//   match (val l@10392 : std/time/locale/time-locale;
//          val maybe@10122 : ((maybe :: V -> V)<sslice/sslice>);
//   (match (maybe@10122) {
//     ((std/core/types/Just((@pat@0: sslice/sslice) : sslice/sslice) : (maybe :: V -> V)<sslice/sslice> ) as @pat: ((maybe :: V -> V)<sslice/sslice>))
//        -> std/core/types/True;
//     ((@skip std/core/types/Nothing() : (maybe :: V -> V)<sslice/sslice> ) as @pat@1: ((maybe :: V -> V)<sslice/sslice>))
//        -> std/core/types/False;
//   })) {
//     ((std/core/types/True() : bool ) as @uniq-pat@1@10389: bool)
//        -> std/core/types/Just<std/time/locale/time-locale>(@uniq-x@10388);
//     ((@skip std/core/types/False() : bool ) as @uniq-pat@0@0@10390: bool)
//        -> std/core/types/Nothing<std/time/locale/time-locale>;
//   };
// }

kk_std_core_types__maybe kk_std_time_locale__lift_get_time_locale_10428(kk_string_t locale, kk_std_core_types__list _uniq_xs_10393, kk_context_t* _ctx) { /* (locale : string, list<time-locale>) -> maybe<time-locale> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_xs_10393, _ctx)) {
    kk_string_drop(locale, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x2180 = kk_std_core_types__as_Cons(_uniq_xs_10393, _ctx);
    kk_box_t _box_x1064 = _con_x2180->head;
    kk_std_core_types__list _uniq_xx_10398 = _con_x2180->tail;
    kk_std_time_locale__time_locale _uniq_x_10397 = kk_std_time_locale__time_locale_unbox(_box_x1064, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10393, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10393, _ctx);
    }
    else {
      kk_std_time_locale__time_locale_dup(_uniq_x_10397, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10398, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10393, _ctx);
    }
    kk_std_core_types__maybe maybe_10122;
    bool _match_x1071;
    kk_string_t _x_x2181 = kk_string_dup(locale, _ctx); /*string*/
    kk_string_t _x_x2182;
    {
      struct kk_std_time_locale_Time_locale* _con_x2183 = kk_std_time_locale__as_Time_locale(_uniq_x_10397, _ctx);
      kk_string_t _x = _con_x2183->lang_name;
      kk_string_dup(_x, _ctx);
      _x_x2182 = _x; /*string*/
    }
    _match_x1071 = kk_string_starts_with(_x_x2181,_x_x2182,kk_context()); /*bool*/
    if (_match_x1071) {
      kk_integer_t x_10081;
      kk_string_t _x_x2184 = kk_string_dup(locale, _ctx); /*string*/
      x_10081 = kk_string_len_int(_x_x2184,kk_context()); /*int*/
      kk_integer_t y_10082;
      kk_string_t _x_x2185;
      {
        struct kk_std_time_locale_Time_locale* _con_x2186 = kk_std_time_locale__as_Time_locale(_uniq_x_10397, _ctx);
        kk_string_t _x_0 = _con_x2186->lang_name;
        kk_string_dup(_x_0, _ctx);
        _x_x2185 = _x_0; /*string*/
      }
      y_10082 = kk_string_len_int(_x_x2185,kk_context()); /*int*/
      kk_std_core_sslice__sslice _b_x1065_1066;
      kk_string_t _x_x2187 = kk_string_dup(locale, _ctx); /*string*/
      kk_integer_t _x_x2188;
      kk_string_t _x_x2189;
      {
        struct kk_std_time_locale_Time_locale* _con_x2190 = kk_std_time_locale__as_Time_locale(_uniq_x_10397, _ctx);
        kk_string_t _x_1 = _con_x2190->lang_name;
        kk_string_dup(_x_1, _ctx);
        _x_x2189 = _x_1; /*string*/
      }
      _x_x2188 = kk_string_len_int(_x_x2189,kk_context()); /*int*/
      kk_integer_t _x_x2191 = kk_integer_sub(x_10081,y_10082,kk_context()); /*int*/
      _b_x1065_1066 = kk_std_core_sslice__new_Sslice(_x_x2187, _x_x2188, _x_x2191, _ctx); /*sslice/sslice*/
      maybe_10122 = kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x1065_1066, _ctx), _ctx); /*maybe<sslice/sslice>*/
    }
    else {
      maybe_10122 = kk_std_core_types__new_Nothing(_ctx); /*maybe<sslice/sslice>*/
    }
    if (kk_std_core_types__is_Just(maybe_10122, _ctx)) {
      kk_box_t _box_x1067 = maybe_10122._cons.Just.value;
      kk_std_core_types__maybe_drop(maybe_10122, _ctx);
      kk_string_drop(locale, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10398, _ctx);
      return kk_std_core_types__new_Just(kk_std_time_locale__time_locale_box(_uniq_x_10397, _ctx), _ctx);
    }
    {
      kk_datatype_ptr_dropn(_uniq_x_10397, (KK_I32(12)), _ctx);
      { // tailcall
        _uniq_xs_10393 = _uniq_xx_10398;
        goto kk__tailcall;
      }
    }
  }
}
 
// lifted local: get-time-locale, @spec-x10391
// specialized: std/core/list/find, on parameters @uniq-pred@10385, using:
// @uniq-pred@10385 = fn(l: std/time/locale/time-locale){
//   val maybe@10122 : (maybe :: V -> V)<sslice/sslice>
//         = match ((std/core/sslice/xstarts-with(locale, (match (l) {
//             ((@skip std/time/locale/Time-locale((@x: string) : string, (@pat@0@1: (list :: V -> V)<string>) : (list :: V -> V)<string>, (@pat@1@0: (list :: V -> V)<string>) : (list :: V -> V)<string>, (@pat@2@0: (list :: V -> V)<string>) : (list :: V -> V)<string>, (@pat@3@0: (list :: V -> V)<string>) : (list :: V -> V)<string>, (@pat@4: (list :: V -> V)<string>) : (list :: V -> V)<string>, (@pat@5: string) : string, (@pat@6: string) : string, (@pat@7: string) : string, (@pat@8: string) : string, (@pat@9: string) : string, (@pat@10: string) : string) : std/time/locale/time-locale ) as @pat@3: std/time/locale/time-locale)
//                -> @x;
//           })))) {
//           ((std/core/types/True() : bool ) as @pat@2: bool)
//              -> val x@10081 : int;
//                 val y@10082 : int;
//             std/core/types/Just<sslice/sslice>((std/core/sslice/Sslice(locale, (std/core/sslice/length((match (l) {
//                 ((@skip std/time/locale/Time-locale((@x: string) : string, (@pat@0@1: (list :: V -> V)<string>) : (list :: V -> V)<string>, (@pat@1@0: (list :: V -> V)<string>) : (list :: V -> V)<string>, (@pat@2@0: (list :: V -> V)<string>) : (list :: V -> V)<string>, (@pat@3@0: (list :: V -> V)<string>) : (list :: V -> V)<string>, (@pat@4: (list :: V -> V)<string>) : (list :: V -> V)<string>, (@pat@5: string) : string, (@pat@6: string) : string, (@pat@7: string) : string, (@pat@8: string) : string, (@pat@9: string) : string, (@pat@10: string) : string) : std/time/locale/time-locale ) as @pat@3: std/time/locale/time-locale)
//                    -> @x;
//               }))), (std/core/int/int-sub(x@10081, y@10082)))));
//           ((@skip std/core/types/False() : bool ) as @pat@0@0: bool)
//              -> std/core/types/Nothing<sslice/sslice>;
//         };
//   match (maybe@10122) {
//     ((std/core/types/Just((@pat@0: sslice/sslice) : sslice/sslice) : (maybe :: V -> V)<sslice/sslice> ) as @pat: ((maybe :: V -> V)<sslice/sslice>))
//        -> std/core/types/True;
//     ((@skip std/core/types/Nothing() : (maybe :: V -> V)<sslice/sslice> ) as @pat@1: ((maybe :: V -> V)<sslice/sslice>))
//        -> std/core/types/False;
//   };
// }

kk_std_core_types__maybe kk_std_time_locale__lift_get_time_locale_10427(kk_string_t locale, kk_std_core_types__list _uniq_xs_10384, kk_context_t* _ctx) { /* (locale : string, list<time-locale>) -> maybe<time-locale> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10384, _ctx)) {
    kk_string_drop(locale, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    return kk_std_time_locale__lift_get_time_locale_10428(locale, _uniq_xs_10384, _ctx);
  }
}
 
// Return a builtin locale given a locale string (e.g. ``en-GB``, ``es``);
// Use `time-locale-iso` if no particular match is found.
// Supports ``de``,``en``,``es``,``fr``,``nl`` and ``en-iso``.

kk_std_time_locale__time_locale kk_std_time_locale_get_time_locale(kk_string_t locale, kk_context_t* _ctx) { /* (locale : string) -> time-locale */ 
  kk_std_core_types__maybe res;
  kk_std_core_types__list _x_x2192 = kk_std_core_types__list_dup(kk_std_time_locale_locales, _ctx); /*list<std/time/locale/time-locale>*/
  res = kk_std_time_locale__lift_get_time_locale_10427(locale, _x_x2192, _ctx); /*maybe<std/time/locale/time-locale>*/
  if (kk_std_core_types__is_Nothing(res, _ctx)) {
    return kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx);
  }
  {
    kk_box_t _box_x1070 = res._cons.Just.value;
    kk_std_time_locale__time_locale x = kk_std_time_locale__time_locale_unbox(_box_x1070, KK_BORROWED, _ctx);
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
    kk_std_core_types__list day_names_10025;
    kk_box_t _x_x1334;
    kk_string_t _x_x1335;
    kk_define_string_literal(, _s_x1336, 6, "Monday", _ctx)
    _x_x1335 = kk_string_dup(_s_x1336, _ctx); /*string*/
    _x_x1334 = kk_string_box(_x_x1335); /*10021*/
    kk_std_core_types__list _x_x1337;
    kk_box_t _x_x1338;
    kk_string_t _x_x1339;
    kk_define_string_literal(, _s_x1340, 7, "Tuesday", _ctx)
    _x_x1339 = kk_string_dup(_s_x1340, _ctx); /*string*/
    _x_x1338 = kk_string_box(_x_x1339); /*10021*/
    kk_std_core_types__list _x_x1341;
    kk_box_t _x_x1342;
    kk_string_t _x_x1343;
    kk_define_string_literal(, _s_x1344, 9, "Wednesday", _ctx)
    _x_x1343 = kk_string_dup(_s_x1344, _ctx); /*string*/
    _x_x1342 = kk_string_box(_x_x1343); /*10021*/
    kk_std_core_types__list _x_x1345;
    kk_box_t _x_x1346;
    kk_string_t _x_x1347;
    kk_define_string_literal(, _s_x1348, 8, "Thursday", _ctx)
    _x_x1347 = kk_string_dup(_s_x1348, _ctx); /*string*/
    _x_x1346 = kk_string_box(_x_x1347); /*10021*/
    kk_std_core_types__list _x_x1349;
    kk_box_t _x_x1350;
    kk_string_t _x_x1351;
    kk_define_string_literal(, _s_x1352, 6, "Friday", _ctx)
    _x_x1351 = kk_string_dup(_s_x1352, _ctx); /*string*/
    _x_x1350 = kk_string_box(_x_x1351); /*10021*/
    kk_std_core_types__list _x_x1353;
    kk_box_t _x_x1354;
    kk_string_t _x_x1355;
    kk_define_string_literal(, _s_x1356, 8, "Saturday", _ctx)
    _x_x1355 = kk_string_dup(_s_x1356, _ctx); /*string*/
    _x_x1354 = kk_string_box(_x_x1355); /*10021*/
    kk_std_core_types__list _x_x1357;
    kk_box_t _x_x1358;
    kk_string_t _x_x1359;
    kk_define_string_literal(, _s_x1360, 6, "Sunday", _ctx)
    _x_x1359 = kk_string_dup(_s_x1360, _ctx); /*string*/
    _x_x1358 = kk_string_box(_x_x1359); /*10021*/
    _x_x1357 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1358, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1353 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1354, _x_x1357, _ctx); /*list<10021>*/
    _x_x1349 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1350, _x_x1353, _ctx); /*list<10021>*/
    _x_x1345 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1346, _x_x1349, _ctx); /*list<10021>*/
    _x_x1341 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1342, _x_x1345, _ctx); /*list<10021>*/
    _x_x1337 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1338, _x_x1341, _ctx); /*list<10021>*/
    day_names_10025 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1334, _x_x1337, _ctx); /*list<string>*/
    kk_std_core_types__list month_names_10026;
    kk_box_t _x_x1361;
    kk_string_t _x_x1362;
    kk_define_string_literal(, _s_x1363, 7, "January", _ctx)
    _x_x1362 = kk_string_dup(_s_x1363, _ctx); /*string*/
    _x_x1361 = kk_string_box(_x_x1362); /*10021*/
    kk_std_core_types__list _x_x1364;
    kk_box_t _x_x1365;
    kk_string_t _x_x1366;
    kk_define_string_literal(, _s_x1367, 8, "February", _ctx)
    _x_x1366 = kk_string_dup(_s_x1367, _ctx); /*string*/
    _x_x1365 = kk_string_box(_x_x1366); /*10021*/
    kk_std_core_types__list _x_x1368;
    kk_box_t _x_x1369;
    kk_string_t _x_x1370;
    kk_define_string_literal(, _s_x1371, 5, "March", _ctx)
    _x_x1370 = kk_string_dup(_s_x1371, _ctx); /*string*/
    _x_x1369 = kk_string_box(_x_x1370); /*10021*/
    kk_std_core_types__list _x_x1372;
    kk_box_t _x_x1373;
    kk_string_t _x_x1374;
    kk_define_string_literal(, _s_x1375, 5, "April", _ctx)
    _x_x1374 = kk_string_dup(_s_x1375, _ctx); /*string*/
    _x_x1373 = kk_string_box(_x_x1374); /*10021*/
    kk_std_core_types__list _x_x1376;
    kk_box_t _x_x1377;
    kk_string_t _x_x1378;
    kk_define_string_literal(, _s_x1379, 3, "May", _ctx)
    _x_x1378 = kk_string_dup(_s_x1379, _ctx); /*string*/
    _x_x1377 = kk_string_box(_x_x1378); /*10021*/
    kk_std_core_types__list _x_x1380;
    kk_box_t _x_x1381;
    kk_string_t _x_x1382;
    kk_define_string_literal(, _s_x1383, 4, "June", _ctx)
    _x_x1382 = kk_string_dup(_s_x1383, _ctx); /*string*/
    _x_x1381 = kk_string_box(_x_x1382); /*10021*/
    kk_std_core_types__list _x_x1384;
    kk_box_t _x_x1385;
    kk_string_t _x_x1386;
    kk_define_string_literal(, _s_x1387, 4, "July", _ctx)
    _x_x1386 = kk_string_dup(_s_x1387, _ctx); /*string*/
    _x_x1385 = kk_string_box(_x_x1386); /*10021*/
    kk_std_core_types__list _x_x1388;
    kk_box_t _x_x1389;
    kk_string_t _x_x1390;
    kk_define_string_literal(, _s_x1391, 6, "August", _ctx)
    _x_x1390 = kk_string_dup(_s_x1391, _ctx); /*string*/
    _x_x1389 = kk_string_box(_x_x1390); /*10021*/
    kk_std_core_types__list _x_x1392;
    kk_box_t _x_x1393;
    kk_string_t _x_x1394;
    kk_define_string_literal(, _s_x1395, 9, "September", _ctx)
    _x_x1394 = kk_string_dup(_s_x1395, _ctx); /*string*/
    _x_x1393 = kk_string_box(_x_x1394); /*10021*/
    kk_std_core_types__list _x_x1396;
    kk_box_t _x_x1397;
    kk_string_t _x_x1398;
    kk_define_string_literal(, _s_x1399, 7, "October", _ctx)
    _x_x1398 = kk_string_dup(_s_x1399, _ctx); /*string*/
    _x_x1397 = kk_string_box(_x_x1398); /*10021*/
    kk_std_core_types__list _x_x1400;
    kk_box_t _x_x1401;
    kk_string_t _x_x1402;
    kk_define_string_literal(, _s_x1403, 8, "November", _ctx)
    _x_x1402 = kk_string_dup(_s_x1403, _ctx); /*string*/
    _x_x1401 = kk_string_box(_x_x1402); /*10021*/
    kk_std_core_types__list _x_x1404;
    kk_box_t _x_x1405;
    kk_string_t _x_x1406;
    kk_define_string_literal(, _s_x1407, 8, "December", _ctx)
    _x_x1406 = kk_string_dup(_s_x1407, _ctx); /*string*/
    _x_x1405 = kk_string_box(_x_x1406); /*10021*/
    _x_x1404 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1405, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1400 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1401, _x_x1404, _ctx); /*list<10021>*/
    _x_x1396 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1397, _x_x1400, _ctx); /*list<10021>*/
    _x_x1392 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1393, _x_x1396, _ctx); /*list<10021>*/
    _x_x1388 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1389, _x_x1392, _ctx); /*list<10021>*/
    _x_x1384 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1385, _x_x1388, _ctx); /*list<10021>*/
    _x_x1380 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1381, _x_x1384, _ctx); /*list<10021>*/
    _x_x1376 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1377, _x_x1380, _ctx); /*list<10021>*/
    _x_x1372 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1373, _x_x1376, _ctx); /*list<10021>*/
    _x_x1368 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1369, _x_x1372, _ctx); /*list<10021>*/
    _x_x1364 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1365, _x_x1368, _ctx); /*list<10021>*/
    month_names_10026 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1361, _x_x1364, _ctx); /*list<string>*/
    kk_std_core_types__list _uniq_month_names_short_92;
    kk_std_core_types__optional _match_x1164 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1164, _ctx)) {
      kk_box_t _box_x247 = _match_x1164._cons._Optional.value;
      kk_std_core_types__list _uniq_month_names_short_93 = kk_std_core_types__list_unbox(_box_x247, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_month_names_short_93, _ctx);
      kk_std_core_types__optional_drop(_match_x1164, _ctx);
      _uniq_month_names_short_92 = _uniq_month_names_short_93; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1164, _ctx);
      kk_std_core_types__list _x_x1408 = kk_std_core_types__list_dup(month_names_10026, _ctx); /*list<string>*/
      _uniq_month_names_short_92 = kk_std_time_locale__lift_time_locale_en_10409(_x_x1408, _ctx); /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_short_153;
    kk_std_core_types__optional _match_x1163 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1163, _ctx)) {
      kk_box_t _box_x248 = _match_x1163._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_short_154 = kk_std_core_types__list_unbox(_box_x248, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_short_154, _ctx);
      kk_std_core_types__optional_drop(_match_x1163, _ctx);
      _uniq_day_names_short_153 = _uniq_day_names_short_154; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1163, _ctx);
      kk_std_core_types__list _x_x1409 = kk_std_core_types__list_dup(day_names_10025, _ctx); /*list<string>*/
      _uniq_day_names_short_153 = kk_std_time_locale__lift_time_locale_en_10411(_x_x1409, _ctx); /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_min_214;
    kk_std_core_types__optional _match_x1162 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1162, _ctx)) {
      kk_box_t _box_x249 = _match_x1162._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_min_215 = kk_std_core_types__list_unbox(_box_x249, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_min_215, _ctx);
      kk_std_core_types__optional_drop(_match_x1162, _ctx);
      _uniq_day_names_min_214 = _uniq_day_names_min_215; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1162, _ctx);
      kk_std_core_types__list _x_x1410 = kk_std_core_types__list_dup(day_names_10025, _ctx); /*list<string>*/
      _uniq_day_names_min_214 = kk_std_time_locale__lift_time_locale_en_10413(_x_x1410, _ctx); /*list<string>*/
    }
    kk_string_t _x_x1411;
    kk_define_string_literal(, _s_x1412, 2, "en", _ctx)
    _x_x1411 = kk_string_dup(_s_x1412, _ctx); /*string*/
    kk_string_t _x_x1413;
    kk_define_string_literal(, _s_x1414, 6, "h:mmaa", _ctx)
    _x_x1413 = kk_string_dup(_s_x1414, _ctx); /*string*/
    kk_string_t _x_x1415;
    kk_define_string_literal(, _s_x1416, 9, "h:mm:ssaa", _ctx)
    _x_x1415 = kk_string_dup(_s_x1416, _ctx); /*string*/
    kk_string_t _x_x1417;
    kk_define_string_literal(, _s_x1418, 10, "MM/DD/YYYY", _ctx)
    _x_x1417 = kk_string_dup(_s_x1418, _ctx); /*string*/
    kk_string_t _x_x1419;
    kk_std_core_types__optional _match_x1161 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1161, _ctx)) {
      kk_box_t _box_x250 = _match_x1161._cons._Optional.value;
      kk_string_t _uniq_format_ll_231 = kk_string_unbox(_box_x250);
      kk_string_dup(_uniq_format_ll_231, _ctx);
      kk_std_core_types__optional_drop(_match_x1161, _ctx);
      _x_x1419 = _uniq_format_ll_231; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1161, _ctx);
      kk_define_string_literal(, _s_x1420, 11, "D MMMM YYYY", _ctx)
      _x_x1419 = kk_string_dup(_s_x1420, _ctx); /*string*/
    }
    kk_string_t _x_x1421;
    kk_std_core_types__optional _match_x1160 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1160, _ctx)) {
      kk_box_t _box_x251 = _match_x1160._cons._Optional.value;
      kk_string_t _uniq_format_lll_235 = kk_string_unbox(_box_x251);
      kk_string_dup(_uniq_format_lll_235, _ctx);
      kk_std_core_types__optional_drop(_match_x1160, _ctx);
      _x_x1421 = _uniq_format_lll_235; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1160, _ctx);
      kk_define_string_literal(, _s_x1422, 13, "D MMMM YYYY t", _ctx)
      _x_x1421 = kk_string_dup(_s_x1422, _ctx); /*string*/
    }
    kk_string_t _x_x1423;
    kk_define_string_literal(, _s_x1424, 19, "dddd, D MMMM YYYY t", _ctx)
    _x_x1423 = kk_string_dup(_s_x1424, _ctx); /*string*/
    kk_std_time_locale_time_locale_en = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1411, day_names_10025, month_names_10026, _uniq_month_names_short_92, _uniq_day_names_short_153, _uniq_day_names_min_214, _x_x1413, _x_x1415, _x_x1417, _x_x1419, _x_x1421, _x_x1423, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_std_core_types__list _uniq_month_names_short_92;
    kk_std_core_types__optional _match_x1126 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1126, _ctx)) {
      kk_box_t _box_x327 = _match_x1126._cons._Optional.value;
      kk_std_core_types__list _uniq_month_names_short_93 = kk_std_core_types__list_unbox(_box_x327, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_month_names_short_93, _ctx);
      kk_std_core_types__optional_drop(_match_x1126, _ctx);
      _uniq_month_names_short_92 = _uniq_month_names_short_93; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1126, _ctx);
      kk_std_core_types__list _x_x1443;
      kk_std_time_locale__time_locale _x_x1444 = kk_std_time_locale_time_locale_en; /*std/time/locale/time-locale*/
      {
        struct kk_std_time_locale_Time_locale* _con_x1445 = kk_std_time_locale__as_Time_locale(_x_x1444, _ctx);
        kk_std_core_types__list _x_0 = _con_x1445->month_names;
        _x_x1443 = kk_std_core_types__list_dup(_x_0, _ctx); /*list<string>*/
      }
      _uniq_month_names_short_92 = kk_std_time_locale__lift_time_locale_en_iso_10415(_x_x1443, _ctx); /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_short_153;
    kk_std_core_types__optional _match_x1125 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1125, _ctx)) {
      kk_box_t _box_x328 = _match_x1125._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_short_154 = kk_std_core_types__list_unbox(_box_x328, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_short_154, _ctx);
      kk_std_core_types__optional_drop(_match_x1125, _ctx);
      _uniq_day_names_short_153 = _uniq_day_names_short_154; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1125, _ctx);
      kk_std_core_types__list _x_x1446;
      kk_std_time_locale__time_locale _x_x1447 = kk_std_time_locale_time_locale_en; /*std/time/locale/time-locale*/
      {
        struct kk_std_time_locale_Time_locale* _con_x1448 = kk_std_time_locale__as_Time_locale(_x_x1447, _ctx);
        kk_std_core_types__list _x = _con_x1448->day_names;
        _x_x1446 = kk_std_core_types__list_dup(_x, _ctx); /*list<string>*/
      }
      _uniq_day_names_short_153 = kk_std_time_locale__lift_time_locale_en_iso_10417(_x_x1446, _ctx); /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_min_214;
    kk_std_core_types__optional _match_x1124 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1124, _ctx)) {
      kk_box_t _box_x329 = _match_x1124._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_min_215 = kk_std_core_types__list_unbox(_box_x329, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_min_215, _ctx);
      kk_std_core_types__optional_drop(_match_x1124, _ctx);
      _uniq_day_names_min_214 = _uniq_day_names_min_215; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1124, _ctx);
      kk_std_core_types__list _x_x1449;
      kk_std_time_locale__time_locale _x_x1450 = kk_std_time_locale_time_locale_en; /*std/time/locale/time-locale*/
      {
        struct kk_std_time_locale_Time_locale* _con_x1451 = kk_std_time_locale__as_Time_locale(_x_x1450, _ctx);
        kk_std_core_types__list _x_1 = _con_x1451->day_names;
        _x_x1449 = kk_std_core_types__list_dup(_x_1, _ctx); /*list<string>*/
      }
      _uniq_day_names_min_214 = kk_std_time_locale__lift_time_locale_en_iso_10419(_x_x1449, _ctx); /*list<string>*/
    }
    kk_string_t _x_x1452;
    kk_define_string_literal(, _s_x1453, 6, "en-iso", _ctx)
    _x_x1452 = kk_string_dup(_s_x1453, _ctx); /*string*/
    kk_std_core_types__list _x_x1454;
    kk_std_time_locale__time_locale _x_x1455 = kk_std_time_locale_time_locale_en; /*std/time/locale/time-locale*/
    {
      struct kk_std_time_locale_Time_locale* _con_x1456 = kk_std_time_locale__as_Time_locale(_x_x1455, _ctx);
      kk_std_core_types__list _x_2 = _con_x1456->day_names;
      _x_x1454 = kk_std_core_types__list_dup(_x_2, _ctx); /*list<string>*/
    }
    kk_std_core_types__list _x_x1457;
    kk_std_time_locale__time_locale _x_x1458 = kk_std_time_locale_time_locale_en; /*std/time/locale/time-locale*/
    {
      struct kk_std_time_locale_Time_locale* _con_x1459 = kk_std_time_locale__as_Time_locale(_x_x1458, _ctx);
      kk_std_core_types__list _x_0_0 = _con_x1459->month_names;
      _x_x1457 = kk_std_core_types__list_dup(_x_0_0, _ctx); /*list<string>*/
    }
    kk_string_t _x_x1460;
    kk_std_core_types__optional _match_x1123 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1123, _ctx)) {
      kk_box_t _box_x330 = _match_x1123._cons._Optional.value;
      kk_string_t _uniq_format_t_219 = kk_string_unbox(_box_x330);
      kk_string_dup(_uniq_format_t_219, _ctx);
      kk_std_core_types__optional_drop(_match_x1123, _ctx);
      _x_x1460 = _uniq_format_t_219; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1123, _ctx);
      kk_define_string_literal(, _s_x1461, 5, "HH:mm", _ctx)
      _x_x1460 = kk_string_dup(_s_x1461, _ctx); /*string*/
    }
    kk_string_t _x_x1462;
    kk_std_core_types__optional _match_x1122 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1122, _ctx)) {
      kk_box_t _box_x331 = _match_x1122._cons._Optional.value;
      kk_string_t _uniq_format_tt_223 = kk_string_unbox(_box_x331);
      kk_string_dup(_uniq_format_tt_223, _ctx);
      kk_std_core_types__optional_drop(_match_x1122, _ctx);
      _x_x1462 = _uniq_format_tt_223; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1122, _ctx);
      kk_define_string_literal(, _s_x1463, 8, "HH:mm:ss", _ctx)
      _x_x1462 = kk_string_dup(_s_x1463, _ctx); /*string*/
    }
    kk_string_t _x_x1464;
    kk_std_core_types__optional _match_x1121 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1121, _ctx)) {
      kk_box_t _box_x332 = _match_x1121._cons._Optional.value;
      kk_string_t _uniq_format_l_227 = kk_string_unbox(_box_x332);
      kk_string_dup(_uniq_format_l_227, _ctx);
      kk_std_core_types__optional_drop(_match_x1121, _ctx);
      _x_x1464 = _uniq_format_l_227; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1121, _ctx);
      kk_define_string_literal(, _s_x1465, 10, "YYYY-MM-DD", _ctx)
      _x_x1464 = kk_string_dup(_s_x1465, _ctx); /*string*/
    }
    kk_string_t _x_x1466;
    kk_std_core_types__optional _match_x1120 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1120, _ctx)) {
      kk_box_t _box_x333 = _match_x1120._cons._Optional.value;
      kk_string_t _uniq_format_ll_231 = kk_string_unbox(_box_x333);
      kk_string_dup(_uniq_format_ll_231, _ctx);
      kk_std_core_types__optional_drop(_match_x1120, _ctx);
      _x_x1466 = _uniq_format_ll_231; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1120, _ctx);
      kk_define_string_literal(, _s_x1467, 11, "D MMMM YYYY", _ctx)
      _x_x1466 = kk_string_dup(_s_x1467, _ctx); /*string*/
    }
    kk_string_t _x_x1468;
    kk_define_string_literal(, _s_x1469, 15, "D MMMM YYYY, tt", _ctx)
    _x_x1468 = kk_string_dup(_s_x1469, _ctx); /*string*/
    kk_string_t _x_x1470;
    kk_define_string_literal(, _s_x1471, 21, "dddd, D MMMM YYYY, tt", _ctx)
    _x_x1470 = kk_string_dup(_s_x1471, _ctx); /*string*/
    kk_std_time_locale_time_locale_en_iso = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1452, _x_x1454, _x_x1457, _uniq_month_names_short_92, _uniq_day_names_short_153, _uniq_day_names_min_214, _x_x1460, _x_x1462, _x_x1464, _x_x1466, _x_x1468, _x_x1470, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_string_t _x_x1472;
    kk_define_string_literal(, _s_x1473, 2, "fr", _ctx)
    _x_x1472 = kk_string_dup(_s_x1473, _ctx); /*string*/
    kk_std_core_types__list _x_x1474;
    kk_box_t _x_x1475;
    kk_string_t _x_x1476;
    kk_define_string_literal(, _s_x1477, 5, "lundi", _ctx)
    _x_x1476 = kk_string_dup(_s_x1477, _ctx); /*string*/
    _x_x1475 = kk_string_box(_x_x1476); /*10021*/
    kk_std_core_types__list _x_x1478;
    kk_box_t _x_x1479;
    kk_string_t _x_x1480;
    kk_define_string_literal(, _s_x1481, 5, "mardi", _ctx)
    _x_x1480 = kk_string_dup(_s_x1481, _ctx); /*string*/
    _x_x1479 = kk_string_box(_x_x1480); /*10021*/
    kk_std_core_types__list _x_x1482;
    kk_box_t _x_x1483;
    kk_string_t _x_x1484;
    kk_define_string_literal(, _s_x1485, 8, "mercredi", _ctx)
    _x_x1484 = kk_string_dup(_s_x1485, _ctx); /*string*/
    _x_x1483 = kk_string_box(_x_x1484); /*10021*/
    kk_std_core_types__list _x_x1486;
    kk_box_t _x_x1487;
    kk_string_t _x_x1488;
    kk_define_string_literal(, _s_x1489, 5, "jeudi", _ctx)
    _x_x1488 = kk_string_dup(_s_x1489, _ctx); /*string*/
    _x_x1487 = kk_string_box(_x_x1488); /*10021*/
    kk_std_core_types__list _x_x1490;
    kk_box_t _x_x1491;
    kk_string_t _x_x1492;
    kk_define_string_literal(, _s_x1493, 8, "vendredi", _ctx)
    _x_x1492 = kk_string_dup(_s_x1493, _ctx); /*string*/
    _x_x1491 = kk_string_box(_x_x1492); /*10021*/
    kk_std_core_types__list _x_x1494;
    kk_box_t _x_x1495;
    kk_string_t _x_x1496;
    kk_define_string_literal(, _s_x1497, 6, "samedi", _ctx)
    _x_x1496 = kk_string_dup(_s_x1497, _ctx); /*string*/
    _x_x1495 = kk_string_box(_x_x1496); /*10021*/
    kk_std_core_types__list _x_x1498;
    kk_box_t _x_x1499;
    kk_string_t _x_x1500;
    kk_define_string_literal(, _s_x1501, 8, "dimanche", _ctx)
    _x_x1500 = kk_string_dup(_s_x1501, _ctx); /*string*/
    _x_x1499 = kk_string_box(_x_x1500); /*10021*/
    _x_x1498 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1499, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1494 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1495, _x_x1498, _ctx); /*list<10021>*/
    _x_x1490 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1491, _x_x1494, _ctx); /*list<10021>*/
    _x_x1486 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1487, _x_x1490, _ctx); /*list<10021>*/
    _x_x1482 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1483, _x_x1486, _ctx); /*list<10021>*/
    _x_x1478 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1479, _x_x1482, _ctx); /*list<10021>*/
    _x_x1474 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1475, _x_x1478, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x1502;
    kk_box_t _x_x1503;
    kk_string_t _x_x1504;
    kk_define_string_literal(, _s_x1505, 7, "janvier", _ctx)
    _x_x1504 = kk_string_dup(_s_x1505, _ctx); /*string*/
    _x_x1503 = kk_string_box(_x_x1504); /*10021*/
    kk_std_core_types__list _x_x1506;
    kk_box_t _x_x1507;
    kk_string_t _x_x1508;
    kk_define_string_literal(, _s_x1509, 8, "f" "\xC3\xA9" "vrier", _ctx)
    _x_x1508 = kk_string_dup(_s_x1509, _ctx); /*string*/
    _x_x1507 = kk_string_box(_x_x1508); /*10021*/
    kk_std_core_types__list _x_x1510;
    kk_box_t _x_x1511;
    kk_string_t _x_x1512;
    kk_define_string_literal(, _s_x1513, 4, "mars", _ctx)
    _x_x1512 = kk_string_dup(_s_x1513, _ctx); /*string*/
    _x_x1511 = kk_string_box(_x_x1512); /*10021*/
    kk_std_core_types__list _x_x1514;
    kk_box_t _x_x1515;
    kk_string_t _x_x1516;
    kk_define_string_literal(, _s_x1517, 5, "avril", _ctx)
    _x_x1516 = kk_string_dup(_s_x1517, _ctx); /*string*/
    _x_x1515 = kk_string_box(_x_x1516); /*10021*/
    kk_std_core_types__list _x_x1518;
    kk_box_t _x_x1519;
    kk_string_t _x_x1520;
    kk_define_string_literal(, _s_x1521, 3, "mai", _ctx)
    _x_x1520 = kk_string_dup(_s_x1521, _ctx); /*string*/
    _x_x1519 = kk_string_box(_x_x1520); /*10021*/
    kk_std_core_types__list _x_x1522;
    kk_box_t _x_x1523;
    kk_string_t _x_x1524;
    kk_define_string_literal(, _s_x1525, 4, "juin", _ctx)
    _x_x1524 = kk_string_dup(_s_x1525, _ctx); /*string*/
    _x_x1523 = kk_string_box(_x_x1524); /*10021*/
    kk_std_core_types__list _x_x1526;
    kk_box_t _x_x1527;
    kk_string_t _x_x1528;
    kk_define_string_literal(, _s_x1529, 7, "juillet", _ctx)
    _x_x1528 = kk_string_dup(_s_x1529, _ctx); /*string*/
    _x_x1527 = kk_string_box(_x_x1528); /*10021*/
    kk_std_core_types__list _x_x1530;
    kk_box_t _x_x1531;
    kk_string_t _x_x1532;
    kk_define_string_literal(, _s_x1533, 5, "ao" "\xC3\xBB" "t", _ctx)
    _x_x1532 = kk_string_dup(_s_x1533, _ctx); /*string*/
    _x_x1531 = kk_string_box(_x_x1532); /*10021*/
    kk_std_core_types__list _x_x1534;
    kk_box_t _x_x1535;
    kk_string_t _x_x1536;
    kk_define_string_literal(, _s_x1537, 9, "septembre", _ctx)
    _x_x1536 = kk_string_dup(_s_x1537, _ctx); /*string*/
    _x_x1535 = kk_string_box(_x_x1536); /*10021*/
    kk_std_core_types__list _x_x1538;
    kk_box_t _x_x1539;
    kk_string_t _x_x1540;
    kk_define_string_literal(, _s_x1541, 7, "octobre", _ctx)
    _x_x1540 = kk_string_dup(_s_x1541, _ctx); /*string*/
    _x_x1539 = kk_string_box(_x_x1540); /*10021*/
    kk_std_core_types__list _x_x1542;
    kk_box_t _x_x1543;
    kk_string_t _x_x1544;
    kk_define_string_literal(, _s_x1545, 8, "novembre", _ctx)
    _x_x1544 = kk_string_dup(_s_x1545, _ctx); /*string*/
    _x_x1543 = kk_string_box(_x_x1544); /*10021*/
    kk_std_core_types__list _x_x1546;
    kk_box_t _x_x1547;
    kk_string_t _x_x1548;
    kk_define_string_literal(, _s_x1549, 9, "d" "\xC3\xA9" "cembre", _ctx)
    _x_x1548 = kk_string_dup(_s_x1549, _ctx); /*string*/
    _x_x1547 = kk_string_box(_x_x1548); /*10021*/
    _x_x1546 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1547, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1542 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1543, _x_x1546, _ctx); /*list<10021>*/
    _x_x1538 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1539, _x_x1542, _ctx); /*list<10021>*/
    _x_x1534 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1535, _x_x1538, _ctx); /*list<10021>*/
    _x_x1530 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1531, _x_x1534, _ctx); /*list<10021>*/
    _x_x1526 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1527, _x_x1530, _ctx); /*list<10021>*/
    _x_x1522 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1523, _x_x1526, _ctx); /*list<10021>*/
    _x_x1518 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1519, _x_x1522, _ctx); /*list<10021>*/
    _x_x1514 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1515, _x_x1518, _ctx); /*list<10021>*/
    _x_x1510 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1511, _x_x1514, _ctx); /*list<10021>*/
    _x_x1506 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1507, _x_x1510, _ctx); /*list<10021>*/
    _x_x1502 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1503, _x_x1506, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x1550;
    kk_box_t _x_x1551;
    kk_string_t _x_x1552;
    kk_define_string_literal(, _s_x1553, 5, "janv.", _ctx)
    _x_x1552 = kk_string_dup(_s_x1553, _ctx); /*string*/
    _x_x1551 = kk_string_box(_x_x1552); /*10021*/
    kk_std_core_types__list _x_x1554;
    kk_box_t _x_x1555;
    kk_string_t _x_x1556;
    kk_define_string_literal(, _s_x1557, 6, "f" "\xC3\xA9" "vr.", _ctx)
    _x_x1556 = kk_string_dup(_s_x1557, _ctx); /*string*/
    _x_x1555 = kk_string_box(_x_x1556); /*10021*/
    kk_std_core_types__list _x_x1558;
    kk_box_t _x_x1559;
    kk_string_t _x_x1560;
    kk_define_string_literal(, _s_x1561, 4, "mars", _ctx)
    _x_x1560 = kk_string_dup(_s_x1561, _ctx); /*string*/
    _x_x1559 = kk_string_box(_x_x1560); /*10021*/
    kk_std_core_types__list _x_x1562;
    kk_box_t _x_x1563;
    kk_string_t _x_x1564;
    kk_define_string_literal(, _s_x1565, 4, "avr.", _ctx)
    _x_x1564 = kk_string_dup(_s_x1565, _ctx); /*string*/
    _x_x1563 = kk_string_box(_x_x1564); /*10021*/
    kk_std_core_types__list _x_x1566;
    kk_box_t _x_x1567;
    kk_string_t _x_x1568;
    kk_define_string_literal(, _s_x1569, 3, "mai", _ctx)
    _x_x1568 = kk_string_dup(_s_x1569, _ctx); /*string*/
    _x_x1567 = kk_string_box(_x_x1568); /*10021*/
    kk_std_core_types__list _x_x1570;
    kk_box_t _x_x1571;
    kk_string_t _x_x1572;
    kk_define_string_literal(, _s_x1573, 4, "juin", _ctx)
    _x_x1572 = kk_string_dup(_s_x1573, _ctx); /*string*/
    _x_x1571 = kk_string_box(_x_x1572); /*10021*/
    kk_std_core_types__list _x_x1574;
    kk_box_t _x_x1575;
    kk_string_t _x_x1576;
    kk_define_string_literal(, _s_x1577, 5, "juil.", _ctx)
    _x_x1576 = kk_string_dup(_s_x1577, _ctx); /*string*/
    _x_x1575 = kk_string_box(_x_x1576); /*10021*/
    kk_std_core_types__list _x_x1578;
    kk_box_t _x_x1579;
    kk_string_t _x_x1580;
    kk_define_string_literal(, _s_x1581, 5, "ao" "\xC3\xBB" "t", _ctx)
    _x_x1580 = kk_string_dup(_s_x1581, _ctx); /*string*/
    _x_x1579 = kk_string_box(_x_x1580); /*10021*/
    kk_std_core_types__list _x_x1582;
    kk_box_t _x_x1583;
    kk_string_t _x_x1584;
    kk_define_string_literal(, _s_x1585, 5, "sept.", _ctx)
    _x_x1584 = kk_string_dup(_s_x1585, _ctx); /*string*/
    _x_x1583 = kk_string_box(_x_x1584); /*10021*/
    kk_std_core_types__list _x_x1586;
    kk_box_t _x_x1587;
    kk_string_t _x_x1588;
    kk_define_string_literal(, _s_x1589, 4, "oct.", _ctx)
    _x_x1588 = kk_string_dup(_s_x1589, _ctx); /*string*/
    _x_x1587 = kk_string_box(_x_x1588); /*10021*/
    kk_std_core_types__list _x_x1590;
    kk_box_t _x_x1591;
    kk_string_t _x_x1592;
    kk_define_string_literal(, _s_x1593, 4, "nov.", _ctx)
    _x_x1592 = kk_string_dup(_s_x1593, _ctx); /*string*/
    _x_x1591 = kk_string_box(_x_x1592); /*10021*/
    kk_std_core_types__list _x_x1594;
    kk_box_t _x_x1595;
    kk_string_t _x_x1596;
    kk_define_string_literal(, _s_x1597, 5, "d" "\xC3\xA9" "c.", _ctx)
    _x_x1596 = kk_string_dup(_s_x1597, _ctx); /*string*/
    _x_x1595 = kk_string_box(_x_x1596); /*10021*/
    _x_x1594 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1595, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1590 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1591, _x_x1594, _ctx); /*list<10021>*/
    _x_x1586 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1587, _x_x1590, _ctx); /*list<10021>*/
    _x_x1582 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1583, _x_x1586, _ctx); /*list<10021>*/
    _x_x1578 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1579, _x_x1582, _ctx); /*list<10021>*/
    _x_x1574 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1575, _x_x1578, _ctx); /*list<10021>*/
    _x_x1570 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1571, _x_x1574, _ctx); /*list<10021>*/
    _x_x1566 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1567, _x_x1570, _ctx); /*list<10021>*/
    _x_x1562 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1563, _x_x1566, _ctx); /*list<10021>*/
    _x_x1558 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1559, _x_x1562, _ctx); /*list<10021>*/
    _x_x1554 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1555, _x_x1558, _ctx); /*list<10021>*/
    _x_x1550 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1551, _x_x1554, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x1598;
    kk_box_t _x_x1599;
    kk_string_t _x_x1600;
    kk_define_string_literal(, _s_x1601, 4, "lun.", _ctx)
    _x_x1600 = kk_string_dup(_s_x1601, _ctx); /*string*/
    _x_x1599 = kk_string_box(_x_x1600); /*10021*/
    kk_std_core_types__list _x_x1602;
    kk_box_t _x_x1603;
    kk_string_t _x_x1604;
    kk_define_string_literal(, _s_x1605, 4, "mar.", _ctx)
    _x_x1604 = kk_string_dup(_s_x1605, _ctx); /*string*/
    _x_x1603 = kk_string_box(_x_x1604); /*10021*/
    kk_std_core_types__list _x_x1606;
    kk_box_t _x_x1607;
    kk_string_t _x_x1608;
    kk_define_string_literal(, _s_x1609, 4, "mer.", _ctx)
    _x_x1608 = kk_string_dup(_s_x1609, _ctx); /*string*/
    _x_x1607 = kk_string_box(_x_x1608); /*10021*/
    kk_std_core_types__list _x_x1610;
    kk_box_t _x_x1611;
    kk_string_t _x_x1612;
    kk_define_string_literal(, _s_x1613, 4, "jeu.", _ctx)
    _x_x1612 = kk_string_dup(_s_x1613, _ctx); /*string*/
    _x_x1611 = kk_string_box(_x_x1612); /*10021*/
    kk_std_core_types__list _x_x1614;
    kk_box_t _x_x1615;
    kk_string_t _x_x1616;
    kk_define_string_literal(, _s_x1617, 4, "ven.", _ctx)
    _x_x1616 = kk_string_dup(_s_x1617, _ctx); /*string*/
    _x_x1615 = kk_string_box(_x_x1616); /*10021*/
    kk_std_core_types__list _x_x1618;
    kk_box_t _x_x1619;
    kk_string_t _x_x1620;
    kk_define_string_literal(, _s_x1621, 4, "sam.", _ctx)
    _x_x1620 = kk_string_dup(_s_x1621, _ctx); /*string*/
    _x_x1619 = kk_string_box(_x_x1620); /*10021*/
    kk_std_core_types__list _x_x1622;
    kk_box_t _x_x1623;
    kk_string_t _x_x1624;
    kk_define_string_literal(, _s_x1625, 4, "dim.", _ctx)
    _x_x1624 = kk_string_dup(_s_x1625, _ctx); /*string*/
    _x_x1623 = kk_string_box(_x_x1624); /*10021*/
    _x_x1622 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1623, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1618 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1619, _x_x1622, _ctx); /*list<10021>*/
    _x_x1614 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1615, _x_x1618, _ctx); /*list<10021>*/
    _x_x1610 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1611, _x_x1614, _ctx); /*list<10021>*/
    _x_x1606 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1607, _x_x1610, _ctx); /*list<10021>*/
    _x_x1602 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1603, _x_x1606, _ctx); /*list<10021>*/
    _x_x1598 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1599, _x_x1602, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x1626;
    kk_box_t _x_x1627;
    kk_string_t _x_x1628;
    kk_define_string_literal(, _s_x1629, 2, "Lu", _ctx)
    _x_x1628 = kk_string_dup(_s_x1629, _ctx); /*string*/
    _x_x1627 = kk_string_box(_x_x1628); /*10021*/
    kk_std_core_types__list _x_x1630;
    kk_box_t _x_x1631;
    kk_string_t _x_x1632;
    kk_define_string_literal(, _s_x1633, 2, "Ma", _ctx)
    _x_x1632 = kk_string_dup(_s_x1633, _ctx); /*string*/
    _x_x1631 = kk_string_box(_x_x1632); /*10021*/
    kk_std_core_types__list _x_x1634;
    kk_box_t _x_x1635;
    kk_string_t _x_x1636;
    kk_define_string_literal(, _s_x1637, 2, "Me", _ctx)
    _x_x1636 = kk_string_dup(_s_x1637, _ctx); /*string*/
    _x_x1635 = kk_string_box(_x_x1636); /*10021*/
    kk_std_core_types__list _x_x1638;
    kk_box_t _x_x1639;
    kk_string_t _x_x1640;
    kk_define_string_literal(, _s_x1641, 2, "Je", _ctx)
    _x_x1640 = kk_string_dup(_s_x1641, _ctx); /*string*/
    _x_x1639 = kk_string_box(_x_x1640); /*10021*/
    kk_std_core_types__list _x_x1642;
    kk_box_t _x_x1643;
    kk_string_t _x_x1644;
    kk_define_string_literal(, _s_x1645, 2, "Ve", _ctx)
    _x_x1644 = kk_string_dup(_s_x1645, _ctx); /*string*/
    _x_x1643 = kk_string_box(_x_x1644); /*10021*/
    kk_std_core_types__list _x_x1646;
    kk_box_t _x_x1647;
    kk_string_t _x_x1648;
    kk_define_string_literal(, _s_x1649, 2, "Sa", _ctx)
    _x_x1648 = kk_string_dup(_s_x1649, _ctx); /*string*/
    _x_x1647 = kk_string_box(_x_x1648); /*10021*/
    kk_std_core_types__list _x_x1650;
    kk_box_t _x_x1651;
    kk_string_t _x_x1652;
    kk_define_string_literal(, _s_x1653, 2, "Di", _ctx)
    _x_x1652 = kk_string_dup(_s_x1653, _ctx); /*string*/
    _x_x1651 = kk_string_box(_x_x1652); /*10021*/
    _x_x1650 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1651, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1646 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1647, _x_x1650, _ctx); /*list<10021>*/
    _x_x1642 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1643, _x_x1646, _ctx); /*list<10021>*/
    _x_x1638 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1639, _x_x1642, _ctx); /*list<10021>*/
    _x_x1634 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1635, _x_x1638, _ctx); /*list<10021>*/
    _x_x1630 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1631, _x_x1634, _ctx); /*list<10021>*/
    _x_x1626 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1627, _x_x1630, _ctx); /*list<10021>*/
    kk_string_t _x_x1654;
    kk_std_core_types__optional _match_x1119 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1119, _ctx)) {
      kk_box_t _box_x424 = _match_x1119._cons._Optional.value;
      kk_string_t _uniq_format_t_219 = kk_string_unbox(_box_x424);
      kk_string_dup(_uniq_format_t_219, _ctx);
      kk_std_core_types__optional_drop(_match_x1119, _ctx);
      _x_x1654 = _uniq_format_t_219; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1119, _ctx);
      kk_define_string_literal(, _s_x1655, 5, "HH:mm", _ctx)
      _x_x1654 = kk_string_dup(_s_x1655, _ctx); /*string*/
    }
    kk_string_t _x_x1656;
    kk_std_core_types__optional _match_x1118 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1118, _ctx)) {
      kk_box_t _box_x425 = _match_x1118._cons._Optional.value;
      kk_string_t _uniq_format_tt_223 = kk_string_unbox(_box_x425);
      kk_string_dup(_uniq_format_tt_223, _ctx);
      kk_std_core_types__optional_drop(_match_x1118, _ctx);
      _x_x1656 = _uniq_format_tt_223; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1118, _ctx);
      kk_define_string_literal(, _s_x1657, 8, "HH:mm:ss", _ctx)
      _x_x1656 = kk_string_dup(_s_x1657, _ctx); /*string*/
    }
    kk_string_t _x_x1658;
    kk_define_string_literal(, _s_x1659, 10, "DD/MM/YYYY", _ctx)
    _x_x1658 = kk_string_dup(_s_x1659, _ctx); /*string*/
    kk_string_t _x_x1660;
    kk_std_core_types__optional _match_x1117 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1117, _ctx)) {
      kk_box_t _box_x426 = _match_x1117._cons._Optional.value;
      kk_string_t _uniq_format_ll_231 = kk_string_unbox(_box_x426);
      kk_string_dup(_uniq_format_ll_231, _ctx);
      kk_std_core_types__optional_drop(_match_x1117, _ctx);
      _x_x1660 = _uniq_format_ll_231; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1117, _ctx);
      kk_define_string_literal(, _s_x1661, 11, "D MMMM YYYY", _ctx)
      _x_x1660 = kk_string_dup(_s_x1661, _ctx); /*string*/
    }
    kk_string_t _x_x1662;
    kk_std_core_types__optional _match_x1116 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1116, _ctx)) {
      kk_box_t _box_x427 = _match_x1116._cons._Optional.value;
      kk_string_t _uniq_format_lll_235 = kk_string_unbox(_box_x427);
      kk_string_dup(_uniq_format_lll_235, _ctx);
      kk_std_core_types__optional_drop(_match_x1116, _ctx);
      _x_x1662 = _uniq_format_lll_235; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1116, _ctx);
      kk_define_string_literal(, _s_x1663, 13, "D MMMM YYYY t", _ctx)
      _x_x1662 = kk_string_dup(_s_x1663, _ctx); /*string*/
    }
    kk_string_t _x_x1664;
    kk_std_core_types__optional _match_x1115 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1115, _ctx)) {
      kk_box_t _box_x428 = _match_x1115._cons._Optional.value;
      kk_string_t _uniq_format_llll_239 = kk_string_unbox(_box_x428);
      kk_string_dup(_uniq_format_llll_239, _ctx);
      kk_std_core_types__optional_drop(_match_x1115, _ctx);
      _x_x1664 = _uniq_format_llll_239; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1115, _ctx);
      kk_define_string_literal(, _s_x1665, 18, "dddd D MMMM YYYY t", _ctx)
      _x_x1664 = kk_string_dup(_s_x1665, _ctx); /*string*/
    }
    kk_std_time_locale_time_locale_fr = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1472, _x_x1474, _x_x1502, _x_x1550, _x_x1598, _x_x1626, _x_x1654, _x_x1656, _x_x1658, _x_x1660, _x_x1662, _x_x1664, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_string_t _x_x1666;
    kk_define_string_literal(, _s_x1667, 2, "de", _ctx)
    _x_x1666 = kk_string_dup(_s_x1667, _ctx); /*string*/
    kk_std_core_types__list _x_x1668;
    kk_box_t _x_x1669;
    kk_string_t _x_x1670;
    kk_define_string_literal(, _s_x1671, 6, "Montag", _ctx)
    _x_x1670 = kk_string_dup(_s_x1671, _ctx); /*string*/
    _x_x1669 = kk_string_box(_x_x1670); /*10021*/
    kk_std_core_types__list _x_x1672;
    kk_box_t _x_x1673;
    kk_string_t _x_x1674;
    kk_define_string_literal(, _s_x1675, 8, "Dienstag", _ctx)
    _x_x1674 = kk_string_dup(_s_x1675, _ctx); /*string*/
    _x_x1673 = kk_string_box(_x_x1674); /*10021*/
    kk_std_core_types__list _x_x1676;
    kk_box_t _x_x1677;
    kk_string_t _x_x1678;
    kk_define_string_literal(, _s_x1679, 8, "Mittwoch", _ctx)
    _x_x1678 = kk_string_dup(_s_x1679, _ctx); /*string*/
    _x_x1677 = kk_string_box(_x_x1678); /*10021*/
    kk_std_core_types__list _x_x1680;
    kk_box_t _x_x1681;
    kk_string_t _x_x1682;
    kk_define_string_literal(, _s_x1683, 10, "Donnerstag", _ctx)
    _x_x1682 = kk_string_dup(_s_x1683, _ctx); /*string*/
    _x_x1681 = kk_string_box(_x_x1682); /*10021*/
    kk_std_core_types__list _x_x1684;
    kk_box_t _x_x1685;
    kk_string_t _x_x1686;
    kk_define_string_literal(, _s_x1687, 7, "Freitag", _ctx)
    _x_x1686 = kk_string_dup(_s_x1687, _ctx); /*string*/
    _x_x1685 = kk_string_box(_x_x1686); /*10021*/
    kk_std_core_types__list _x_x1688;
    kk_box_t _x_x1689;
    kk_string_t _x_x1690;
    kk_define_string_literal(, _s_x1691, 7, "Samstag", _ctx)
    _x_x1690 = kk_string_dup(_s_x1691, _ctx); /*string*/
    _x_x1689 = kk_string_box(_x_x1690); /*10021*/
    kk_std_core_types__list _x_x1692;
    kk_box_t _x_x1693;
    kk_string_t _x_x1694;
    kk_define_string_literal(, _s_x1695, 7, "Sonntag", _ctx)
    _x_x1694 = kk_string_dup(_s_x1695, _ctx); /*string*/
    _x_x1693 = kk_string_box(_x_x1694); /*10021*/
    _x_x1692 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1693, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1688 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1689, _x_x1692, _ctx); /*list<10021>*/
    _x_x1684 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1685, _x_x1688, _ctx); /*list<10021>*/
    _x_x1680 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1681, _x_x1684, _ctx); /*list<10021>*/
    _x_x1676 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1677, _x_x1680, _ctx); /*list<10021>*/
    _x_x1672 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1673, _x_x1676, _ctx); /*list<10021>*/
    _x_x1668 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1669, _x_x1672, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x1696;
    kk_box_t _x_x1697;
    kk_string_t _x_x1698;
    kk_define_string_literal(, _s_x1699, 6, "Januar", _ctx)
    _x_x1698 = kk_string_dup(_s_x1699, _ctx); /*string*/
    _x_x1697 = kk_string_box(_x_x1698); /*10021*/
    kk_std_core_types__list _x_x1700;
    kk_box_t _x_x1701;
    kk_string_t _x_x1702;
    kk_define_string_literal(, _s_x1703, 7, "Februar", _ctx)
    _x_x1702 = kk_string_dup(_s_x1703, _ctx); /*string*/
    _x_x1701 = kk_string_box(_x_x1702); /*10021*/
    kk_std_core_types__list _x_x1704;
    kk_box_t _x_x1705;
    kk_string_t _x_x1706;
    kk_define_string_literal(, _s_x1707, 5, "M" "\xC3\xA4" "rz", _ctx)
    _x_x1706 = kk_string_dup(_s_x1707, _ctx); /*string*/
    _x_x1705 = kk_string_box(_x_x1706); /*10021*/
    kk_std_core_types__list _x_x1708;
    kk_box_t _x_x1709;
    kk_string_t _x_x1710;
    kk_define_string_literal(, _s_x1711, 5, "April", _ctx)
    _x_x1710 = kk_string_dup(_s_x1711, _ctx); /*string*/
    _x_x1709 = kk_string_box(_x_x1710); /*10021*/
    kk_std_core_types__list _x_x1712;
    kk_box_t _x_x1713;
    kk_string_t _x_x1714;
    kk_define_string_literal(, _s_x1715, 3, "Mai", _ctx)
    _x_x1714 = kk_string_dup(_s_x1715, _ctx); /*string*/
    _x_x1713 = kk_string_box(_x_x1714); /*10021*/
    kk_std_core_types__list _x_x1716;
    kk_box_t _x_x1717;
    kk_string_t _x_x1718;
    kk_define_string_literal(, _s_x1719, 4, "Juni", _ctx)
    _x_x1718 = kk_string_dup(_s_x1719, _ctx); /*string*/
    _x_x1717 = kk_string_box(_x_x1718); /*10021*/
    kk_std_core_types__list _x_x1720;
    kk_box_t _x_x1721;
    kk_string_t _x_x1722;
    kk_define_string_literal(, _s_x1723, 4, "Juli", _ctx)
    _x_x1722 = kk_string_dup(_s_x1723, _ctx); /*string*/
    _x_x1721 = kk_string_box(_x_x1722); /*10021*/
    kk_std_core_types__list _x_x1724;
    kk_box_t _x_x1725;
    kk_string_t _x_x1726;
    kk_define_string_literal(, _s_x1727, 6, "August", _ctx)
    _x_x1726 = kk_string_dup(_s_x1727, _ctx); /*string*/
    _x_x1725 = kk_string_box(_x_x1726); /*10021*/
    kk_std_core_types__list _x_x1728;
    kk_box_t _x_x1729;
    kk_string_t _x_x1730;
    kk_define_string_literal(, _s_x1731, 9, "September", _ctx)
    _x_x1730 = kk_string_dup(_s_x1731, _ctx); /*string*/
    _x_x1729 = kk_string_box(_x_x1730); /*10021*/
    kk_std_core_types__list _x_x1732;
    kk_box_t _x_x1733;
    kk_string_t _x_x1734;
    kk_define_string_literal(, _s_x1735, 7, "Oktober", _ctx)
    _x_x1734 = kk_string_dup(_s_x1735, _ctx); /*string*/
    _x_x1733 = kk_string_box(_x_x1734); /*10021*/
    kk_std_core_types__list _x_x1736;
    kk_box_t _x_x1737;
    kk_string_t _x_x1738;
    kk_define_string_literal(, _s_x1739, 8, "November", _ctx)
    _x_x1738 = kk_string_dup(_s_x1739, _ctx); /*string*/
    _x_x1737 = kk_string_box(_x_x1738); /*10021*/
    kk_std_core_types__list _x_x1740;
    kk_box_t _x_x1741;
    kk_string_t _x_x1742;
    kk_define_string_literal(, _s_x1743, 8, "Dezember", _ctx)
    _x_x1742 = kk_string_dup(_s_x1743, _ctx); /*string*/
    _x_x1741 = kk_string_box(_x_x1742); /*10021*/
    _x_x1740 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1741, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1736 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1737, _x_x1740, _ctx); /*list<10021>*/
    _x_x1732 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1733, _x_x1736, _ctx); /*list<10021>*/
    _x_x1728 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1729, _x_x1732, _ctx); /*list<10021>*/
    _x_x1724 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1725, _x_x1728, _ctx); /*list<10021>*/
    _x_x1720 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1721, _x_x1724, _ctx); /*list<10021>*/
    _x_x1716 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1717, _x_x1720, _ctx); /*list<10021>*/
    _x_x1712 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1713, _x_x1716, _ctx); /*list<10021>*/
    _x_x1708 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1709, _x_x1712, _ctx); /*list<10021>*/
    _x_x1704 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1705, _x_x1708, _ctx); /*list<10021>*/
    _x_x1700 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1701, _x_x1704, _ctx); /*list<10021>*/
    _x_x1696 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1697, _x_x1700, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x1744;
    kk_box_t _x_x1745;
    kk_string_t _x_x1746;
    kk_define_string_literal(, _s_x1747, 4, "Jan.", _ctx)
    _x_x1746 = kk_string_dup(_s_x1747, _ctx); /*string*/
    _x_x1745 = kk_string_box(_x_x1746); /*10021*/
    kk_std_core_types__list _x_x1748;
    kk_box_t _x_x1749;
    kk_string_t _x_x1750;
    kk_define_string_literal(, _s_x1751, 5, "Febr.", _ctx)
    _x_x1750 = kk_string_dup(_s_x1751, _ctx); /*string*/
    _x_x1749 = kk_string_box(_x_x1750); /*10021*/
    kk_std_core_types__list _x_x1752;
    kk_box_t _x_x1753;
    kk_string_t _x_x1754;
    kk_define_string_literal(, _s_x1755, 4, "Mrz.", _ctx)
    _x_x1754 = kk_string_dup(_s_x1755, _ctx); /*string*/
    _x_x1753 = kk_string_box(_x_x1754); /*10021*/
    kk_std_core_types__list _x_x1756;
    kk_box_t _x_x1757;
    kk_string_t _x_x1758;
    kk_define_string_literal(, _s_x1759, 4, "Apr.", _ctx)
    _x_x1758 = kk_string_dup(_s_x1759, _ctx); /*string*/
    _x_x1757 = kk_string_box(_x_x1758); /*10021*/
    kk_std_core_types__list _x_x1760;
    kk_box_t _x_x1761;
    kk_string_t _x_x1762;
    kk_define_string_literal(, _s_x1763, 3, "Mai", _ctx)
    _x_x1762 = kk_string_dup(_s_x1763, _ctx); /*string*/
    _x_x1761 = kk_string_box(_x_x1762); /*10021*/
    kk_std_core_types__list _x_x1764;
    kk_box_t _x_x1765;
    kk_string_t _x_x1766;
    kk_define_string_literal(, _s_x1767, 4, "Jun.", _ctx)
    _x_x1766 = kk_string_dup(_s_x1767, _ctx); /*string*/
    _x_x1765 = kk_string_box(_x_x1766); /*10021*/
    kk_std_core_types__list _x_x1768;
    kk_box_t _x_x1769;
    kk_string_t _x_x1770;
    kk_define_string_literal(, _s_x1771, 4, "Jul.", _ctx)
    _x_x1770 = kk_string_dup(_s_x1771, _ctx); /*string*/
    _x_x1769 = kk_string_box(_x_x1770); /*10021*/
    kk_std_core_types__list _x_x1772;
    kk_box_t _x_x1773;
    kk_string_t _x_x1774;
    kk_define_string_literal(, _s_x1775, 4, "Aug.", _ctx)
    _x_x1774 = kk_string_dup(_s_x1775, _ctx); /*string*/
    _x_x1773 = kk_string_box(_x_x1774); /*10021*/
    kk_std_core_types__list _x_x1776;
    kk_box_t _x_x1777;
    kk_string_t _x_x1778;
    kk_define_string_literal(, _s_x1779, 5, "Sept.", _ctx)
    _x_x1778 = kk_string_dup(_s_x1779, _ctx); /*string*/
    _x_x1777 = kk_string_box(_x_x1778); /*10021*/
    kk_std_core_types__list _x_x1780;
    kk_box_t _x_x1781;
    kk_string_t _x_x1782;
    kk_define_string_literal(, _s_x1783, 4, "Okt.", _ctx)
    _x_x1782 = kk_string_dup(_s_x1783, _ctx); /*string*/
    _x_x1781 = kk_string_box(_x_x1782); /*10021*/
    kk_std_core_types__list _x_x1784;
    kk_box_t _x_x1785;
    kk_string_t _x_x1786;
    kk_define_string_literal(, _s_x1787, 4, "Nov.", _ctx)
    _x_x1786 = kk_string_dup(_s_x1787, _ctx); /*string*/
    _x_x1785 = kk_string_box(_x_x1786); /*10021*/
    kk_std_core_types__list _x_x1788;
    kk_box_t _x_x1789;
    kk_string_t _x_x1790;
    kk_define_string_literal(, _s_x1791, 4, "Dez.", _ctx)
    _x_x1790 = kk_string_dup(_s_x1791, _ctx); /*string*/
    _x_x1789 = kk_string_box(_x_x1790); /*10021*/
    _x_x1788 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1789, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1784 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1785, _x_x1788, _ctx); /*list<10021>*/
    _x_x1780 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1781, _x_x1784, _ctx); /*list<10021>*/
    _x_x1776 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1777, _x_x1780, _ctx); /*list<10021>*/
    _x_x1772 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1773, _x_x1776, _ctx); /*list<10021>*/
    _x_x1768 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1769, _x_x1772, _ctx); /*list<10021>*/
    _x_x1764 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1765, _x_x1768, _ctx); /*list<10021>*/
    _x_x1760 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1761, _x_x1764, _ctx); /*list<10021>*/
    _x_x1756 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1757, _x_x1760, _ctx); /*list<10021>*/
    _x_x1752 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1753, _x_x1756, _ctx); /*list<10021>*/
    _x_x1748 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1749, _x_x1752, _ctx); /*list<10021>*/
    _x_x1744 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1745, _x_x1748, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x1792;
    kk_box_t _x_x1793;
    kk_string_t _x_x1794;
    kk_define_string_literal(, _s_x1795, 3, "Mo.", _ctx)
    _x_x1794 = kk_string_dup(_s_x1795, _ctx); /*string*/
    _x_x1793 = kk_string_box(_x_x1794); /*10021*/
    kk_std_core_types__list _x_x1796;
    kk_box_t _x_x1797;
    kk_string_t _x_x1798;
    kk_define_string_literal(, _s_x1799, 3, "Di.", _ctx)
    _x_x1798 = kk_string_dup(_s_x1799, _ctx); /*string*/
    _x_x1797 = kk_string_box(_x_x1798); /*10021*/
    kk_std_core_types__list _x_x1800;
    kk_box_t _x_x1801;
    kk_string_t _x_x1802;
    kk_define_string_literal(, _s_x1803, 3, "Mi.", _ctx)
    _x_x1802 = kk_string_dup(_s_x1803, _ctx); /*string*/
    _x_x1801 = kk_string_box(_x_x1802); /*10021*/
    kk_std_core_types__list _x_x1804;
    kk_box_t _x_x1805;
    kk_string_t _x_x1806;
    kk_define_string_literal(, _s_x1807, 3, "Do.", _ctx)
    _x_x1806 = kk_string_dup(_s_x1807, _ctx); /*string*/
    _x_x1805 = kk_string_box(_x_x1806); /*10021*/
    kk_std_core_types__list _x_x1808;
    kk_box_t _x_x1809;
    kk_string_t _x_x1810;
    kk_define_string_literal(, _s_x1811, 3, "Fr.", _ctx)
    _x_x1810 = kk_string_dup(_s_x1811, _ctx); /*string*/
    _x_x1809 = kk_string_box(_x_x1810); /*10021*/
    kk_std_core_types__list _x_x1812;
    kk_box_t _x_x1813;
    kk_string_t _x_x1814;
    kk_define_string_literal(, _s_x1815, 3, "Sa.", _ctx)
    _x_x1814 = kk_string_dup(_s_x1815, _ctx); /*string*/
    _x_x1813 = kk_string_box(_x_x1814); /*10021*/
    kk_std_core_types__list _x_x1816;
    kk_box_t _x_x1817;
    kk_string_t _x_x1818;
    kk_define_string_literal(, _s_x1819, 3, "So.", _ctx)
    _x_x1818 = kk_string_dup(_s_x1819, _ctx); /*string*/
    _x_x1817 = kk_string_box(_x_x1818); /*10021*/
    _x_x1816 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1817, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1812 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1813, _x_x1816, _ctx); /*list<10021>*/
    _x_x1808 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1809, _x_x1812, _ctx); /*list<10021>*/
    _x_x1804 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1805, _x_x1808, _ctx); /*list<10021>*/
    _x_x1800 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1801, _x_x1804, _ctx); /*list<10021>*/
    _x_x1796 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1797, _x_x1800, _ctx); /*list<10021>*/
    _x_x1792 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1793, _x_x1796, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x1820;
    kk_box_t _x_x1821;
    kk_string_t _x_x1822;
    kk_define_string_literal(, _s_x1823, 2, "Mo", _ctx)
    _x_x1822 = kk_string_dup(_s_x1823, _ctx); /*string*/
    _x_x1821 = kk_string_box(_x_x1822); /*10021*/
    kk_std_core_types__list _x_x1824;
    kk_box_t _x_x1825;
    kk_string_t _x_x1826;
    kk_define_string_literal(, _s_x1827, 2, "Di", _ctx)
    _x_x1826 = kk_string_dup(_s_x1827, _ctx); /*string*/
    _x_x1825 = kk_string_box(_x_x1826); /*10021*/
    kk_std_core_types__list _x_x1828;
    kk_box_t _x_x1829;
    kk_string_t _x_x1830;
    kk_define_string_literal(, _s_x1831, 2, "Mi", _ctx)
    _x_x1830 = kk_string_dup(_s_x1831, _ctx); /*string*/
    _x_x1829 = kk_string_box(_x_x1830); /*10021*/
    kk_std_core_types__list _x_x1832;
    kk_box_t _x_x1833;
    kk_string_t _x_x1834;
    kk_define_string_literal(, _s_x1835, 2, "Do", _ctx)
    _x_x1834 = kk_string_dup(_s_x1835, _ctx); /*string*/
    _x_x1833 = kk_string_box(_x_x1834); /*10021*/
    kk_std_core_types__list _x_x1836;
    kk_box_t _x_x1837;
    kk_string_t _x_x1838;
    kk_define_string_literal(, _s_x1839, 2, "Fr", _ctx)
    _x_x1838 = kk_string_dup(_s_x1839, _ctx); /*string*/
    _x_x1837 = kk_string_box(_x_x1838); /*10021*/
    kk_std_core_types__list _x_x1840;
    kk_box_t _x_x1841;
    kk_string_t _x_x1842;
    kk_define_string_literal(, _s_x1843, 2, "Sa", _ctx)
    _x_x1842 = kk_string_dup(_s_x1843, _ctx); /*string*/
    _x_x1841 = kk_string_box(_x_x1842); /*10021*/
    kk_std_core_types__list _x_x1844;
    kk_box_t _x_x1845;
    kk_string_t _x_x1846;
    kk_define_string_literal(, _s_x1847, 2, "So", _ctx)
    _x_x1846 = kk_string_dup(_s_x1847, _ctx); /*string*/
    _x_x1845 = kk_string_box(_x_x1846); /*10021*/
    _x_x1844 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1845, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1840 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1841, _x_x1844, _ctx); /*list<10021>*/
    _x_x1836 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1837, _x_x1840, _ctx); /*list<10021>*/
    _x_x1832 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1833, _x_x1836, _ctx); /*list<10021>*/
    _x_x1828 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1829, _x_x1832, _ctx); /*list<10021>*/
    _x_x1824 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1825, _x_x1828, _ctx); /*list<10021>*/
    _x_x1820 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1821, _x_x1824, _ctx); /*list<10021>*/
    kk_string_t _x_x1848;
    kk_std_core_types__optional _match_x1114 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1114, _ctx)) {
      kk_box_t _box_x609 = _match_x1114._cons._Optional.value;
      kk_string_t _uniq_format_t_219 = kk_string_unbox(_box_x609);
      kk_string_dup(_uniq_format_t_219, _ctx);
      kk_std_core_types__optional_drop(_match_x1114, _ctx);
      _x_x1848 = _uniq_format_t_219; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1114, _ctx);
      kk_define_string_literal(, _s_x1849, 5, "HH:mm", _ctx)
      _x_x1848 = kk_string_dup(_s_x1849, _ctx); /*string*/
    }
    kk_string_t _x_x1850;
    kk_std_core_types__optional _match_x1113 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1113, _ctx)) {
      kk_box_t _box_x610 = _match_x1113._cons._Optional.value;
      kk_string_t _uniq_format_tt_223 = kk_string_unbox(_box_x610);
      kk_string_dup(_uniq_format_tt_223, _ctx);
      kk_std_core_types__optional_drop(_match_x1113, _ctx);
      _x_x1850 = _uniq_format_tt_223; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1113, _ctx);
      kk_define_string_literal(, _s_x1851, 8, "HH:mm:ss", _ctx)
      _x_x1850 = kk_string_dup(_s_x1851, _ctx); /*string*/
    }
    kk_string_t _x_x1852;
    kk_define_string_literal(, _s_x1853, 10, "DD.MM.YYYY", _ctx)
    _x_x1852 = kk_string_dup(_s_x1853, _ctx); /*string*/
    kk_string_t _x_x1854;
    kk_define_string_literal(, _s_x1855, 12, "D. MMMM YYYY", _ctx)
    _x_x1854 = kk_string_dup(_s_x1855, _ctx); /*string*/
    kk_string_t _x_x1856;
    kk_define_string_literal(, _s_x1857, 14, "D. MMMM YYYY t", _ctx)
    _x_x1856 = kk_string_dup(_s_x1857, _ctx); /*string*/
    kk_string_t _x_x1858;
    kk_define_string_literal(, _s_x1859, 20, "dddd, D. MMMM YYYY t", _ctx)
    _x_x1858 = kk_string_dup(_s_x1859, _ctx); /*string*/
    kk_std_time_locale_time_locale_de = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1666, _x_x1668, _x_x1696, _x_x1744, _x_x1792, _x_x1820, _x_x1848, _x_x1850, _x_x1852, _x_x1854, _x_x1856, _x_x1858, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_std_core_types__list day_names_10087;
    kk_box_t _x_x1878;
    kk_string_t _x_x1879;
    kk_define_string_literal(, _s_x1880, 5, "lunes", _ctx)
    _x_x1879 = kk_string_dup(_s_x1880, _ctx); /*string*/
    _x_x1878 = kk_string_box(_x_x1879); /*10021*/
    kk_std_core_types__list _x_x1881;
    kk_box_t _x_x1882;
    kk_string_t _x_x1883;
    kk_define_string_literal(, _s_x1884, 6, "martes", _ctx)
    _x_x1883 = kk_string_dup(_s_x1884, _ctx); /*string*/
    _x_x1882 = kk_string_box(_x_x1883); /*10021*/
    kk_std_core_types__list _x_x1885;
    kk_box_t _x_x1886;
    kk_string_t _x_x1887;
    kk_define_string_literal(, _s_x1888, 10, "mi" "\xC3\xA9" "rcoles", _ctx)
    _x_x1887 = kk_string_dup(_s_x1888, _ctx); /*string*/
    _x_x1886 = kk_string_box(_x_x1887); /*10021*/
    kk_std_core_types__list _x_x1889;
    kk_box_t _x_x1890;
    kk_string_t _x_x1891;
    kk_define_string_literal(, _s_x1892, 6, "jueves", _ctx)
    _x_x1891 = kk_string_dup(_s_x1892, _ctx); /*string*/
    _x_x1890 = kk_string_box(_x_x1891); /*10021*/
    kk_std_core_types__list _x_x1893;
    kk_box_t _x_x1894;
    kk_string_t _x_x1895;
    kk_define_string_literal(, _s_x1896, 7, "viernes", _ctx)
    _x_x1895 = kk_string_dup(_s_x1896, _ctx); /*string*/
    _x_x1894 = kk_string_box(_x_x1895); /*10021*/
    kk_std_core_types__list _x_x1897;
    kk_box_t _x_x1898;
    kk_string_t _x_x1899;
    kk_define_string_literal(, _s_x1900, 7, "s" "\xC3\xA1" "bado", _ctx)
    _x_x1899 = kk_string_dup(_s_x1900, _ctx); /*string*/
    _x_x1898 = kk_string_box(_x_x1899); /*10021*/
    kk_std_core_types__list _x_x1901;
    kk_box_t _x_x1902;
    kk_string_t _x_x1903;
    kk_define_string_literal(, _s_x1904, 7, "domingo", _ctx)
    _x_x1903 = kk_string_dup(_s_x1904, _ctx); /*string*/
    _x_x1902 = kk_string_box(_x_x1903); /*10021*/
    _x_x1901 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1902, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1897 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1898, _x_x1901, _ctx); /*list<10021>*/
    _x_x1893 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1894, _x_x1897, _ctx); /*list<10021>*/
    _x_x1889 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1890, _x_x1893, _ctx); /*list<10021>*/
    _x_x1885 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1886, _x_x1889, _ctx); /*list<10021>*/
    _x_x1881 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1882, _x_x1885, _ctx); /*list<10021>*/
    day_names_10087 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1878, _x_x1881, _ctx); /*list<string>*/
    kk_std_core_types__list month_names_10088;
    kk_box_t _x_x1905;
    kk_string_t _x_x1906;
    kk_define_string_literal(, _s_x1907, 5, "enero", _ctx)
    _x_x1906 = kk_string_dup(_s_x1907, _ctx); /*string*/
    _x_x1905 = kk_string_box(_x_x1906); /*10021*/
    kk_std_core_types__list _x_x1908;
    kk_box_t _x_x1909;
    kk_string_t _x_x1910;
    kk_define_string_literal(, _s_x1911, 7, "febrero", _ctx)
    _x_x1910 = kk_string_dup(_s_x1911, _ctx); /*string*/
    _x_x1909 = kk_string_box(_x_x1910); /*10021*/
    kk_std_core_types__list _x_x1912;
    kk_box_t _x_x1913;
    kk_string_t _x_x1914;
    kk_define_string_literal(, _s_x1915, 5, "marzo", _ctx)
    _x_x1914 = kk_string_dup(_s_x1915, _ctx); /*string*/
    _x_x1913 = kk_string_box(_x_x1914); /*10021*/
    kk_std_core_types__list _x_x1916;
    kk_box_t _x_x1917;
    kk_string_t _x_x1918;
    kk_define_string_literal(, _s_x1919, 5, "abril", _ctx)
    _x_x1918 = kk_string_dup(_s_x1919, _ctx); /*string*/
    _x_x1917 = kk_string_box(_x_x1918); /*10021*/
    kk_std_core_types__list _x_x1920;
    kk_box_t _x_x1921;
    kk_string_t _x_x1922;
    kk_define_string_literal(, _s_x1923, 4, "mayo", _ctx)
    _x_x1922 = kk_string_dup(_s_x1923, _ctx); /*string*/
    _x_x1921 = kk_string_box(_x_x1922); /*10021*/
    kk_std_core_types__list _x_x1924;
    kk_box_t _x_x1925;
    kk_string_t _x_x1926;
    kk_define_string_literal(, _s_x1927, 5, "junio", _ctx)
    _x_x1926 = kk_string_dup(_s_x1927, _ctx); /*string*/
    _x_x1925 = kk_string_box(_x_x1926); /*10021*/
    kk_std_core_types__list _x_x1928;
    kk_box_t _x_x1929;
    kk_string_t _x_x1930;
    kk_define_string_literal(, _s_x1931, 5, "julio", _ctx)
    _x_x1930 = kk_string_dup(_s_x1931, _ctx); /*string*/
    _x_x1929 = kk_string_box(_x_x1930); /*10021*/
    kk_std_core_types__list _x_x1932;
    kk_box_t _x_x1933;
    kk_string_t _x_x1934;
    kk_define_string_literal(, _s_x1935, 6, "agosto", _ctx)
    _x_x1934 = kk_string_dup(_s_x1935, _ctx); /*string*/
    _x_x1933 = kk_string_box(_x_x1934); /*10021*/
    kk_std_core_types__list _x_x1936;
    kk_box_t _x_x1937;
    kk_string_t _x_x1938;
    kk_define_string_literal(, _s_x1939, 10, "septiembre", _ctx)
    _x_x1938 = kk_string_dup(_s_x1939, _ctx); /*string*/
    _x_x1937 = kk_string_box(_x_x1938); /*10021*/
    kk_std_core_types__list _x_x1940;
    kk_box_t _x_x1941;
    kk_string_t _x_x1942;
    kk_define_string_literal(, _s_x1943, 7, "octubre", _ctx)
    _x_x1942 = kk_string_dup(_s_x1943, _ctx); /*string*/
    _x_x1941 = kk_string_box(_x_x1942); /*10021*/
    kk_std_core_types__list _x_x1944;
    kk_box_t _x_x1945;
    kk_string_t _x_x1946;
    kk_define_string_literal(, _s_x1947, 9, "noviembre", _ctx)
    _x_x1946 = kk_string_dup(_s_x1947, _ctx); /*string*/
    _x_x1945 = kk_string_box(_x_x1946); /*10021*/
    kk_std_core_types__list _x_x1948;
    kk_box_t _x_x1949;
    kk_string_t _x_x1950;
    kk_define_string_literal(, _s_x1951, 9, "diciembre", _ctx)
    _x_x1950 = kk_string_dup(_s_x1951, _ctx); /*string*/
    _x_x1949 = kk_string_box(_x_x1950); /*10021*/
    _x_x1948 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1949, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1944 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1945, _x_x1948, _ctx); /*list<10021>*/
    _x_x1940 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1941, _x_x1944, _ctx); /*list<10021>*/
    _x_x1936 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1937, _x_x1940, _ctx); /*list<10021>*/
    _x_x1932 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1933, _x_x1936, _ctx); /*list<10021>*/
    _x_x1928 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1929, _x_x1932, _ctx); /*list<10021>*/
    _x_x1924 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1925, _x_x1928, _ctx); /*list<10021>*/
    _x_x1920 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1921, _x_x1924, _ctx); /*list<10021>*/
    _x_x1916 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1917, _x_x1920, _ctx); /*list<10021>*/
    _x_x1912 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1913, _x_x1916, _ctx); /*list<10021>*/
    _x_x1908 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1909, _x_x1912, _ctx); /*list<10021>*/
    month_names_10088 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1905, _x_x1908, _ctx); /*list<string>*/
    kk_std_core_types__list _uniq_month_names_short_92;
    kk_std_core_types__optional _match_x1079 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1079, _ctx)) {
      kk_box_t _box_x852 = _match_x1079._cons._Optional.value;
      kk_std_core_types__list _uniq_month_names_short_93 = kk_std_core_types__list_unbox(_box_x852, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_month_names_short_93, _ctx);
      kk_std_core_types__optional_drop(_match_x1079, _ctx);
      _uniq_month_names_short_92 = _uniq_month_names_short_93; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1079, _ctx);
      kk_std_core_types__list _x_x1952 = kk_std_core_types__list_dup(month_names_10088, _ctx); /*list<string>*/
      _uniq_month_names_short_92 = kk_std_time_locale__lift_time_locale_es_10421(_x_x1952, _ctx); /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_short_153;
    kk_std_core_types__optional _match_x1078 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1078, _ctx)) {
      kk_box_t _box_x853 = _match_x1078._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_short_154 = kk_std_core_types__list_unbox(_box_x853, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_short_154, _ctx);
      kk_std_core_types__optional_drop(_match_x1078, _ctx);
      _uniq_day_names_short_153 = _uniq_day_names_short_154; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1078, _ctx);
      kk_std_core_types__list _x_x1953 = kk_std_core_types__list_dup(day_names_10087, _ctx); /*list<string>*/
      _uniq_day_names_short_153 = kk_std_time_locale__lift_time_locale_es_10423(_x_x1953, _ctx); /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_min_214;
    kk_std_core_types__optional _match_x1077 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1077, _ctx)) {
      kk_box_t _box_x854 = _match_x1077._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_min_215 = kk_std_core_types__list_unbox(_box_x854, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_min_215, _ctx);
      kk_std_core_types__optional_drop(_match_x1077, _ctx);
      _uniq_day_names_min_214 = _uniq_day_names_min_215; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1077, _ctx);
      kk_std_core_types__list _x_x1954 = kk_std_core_types__list_dup(day_names_10087, _ctx); /*list<string>*/
      _uniq_day_names_min_214 = kk_std_time_locale__lift_time_locale_es_10425(_x_x1954, _ctx); /*list<string>*/
    }
    kk_string_t _x_x1955;
    kk_define_string_literal(, _s_x1956, 2, "es", _ctx)
    _x_x1955 = kk_string_dup(_s_x1956, _ctx); /*string*/
    kk_string_t _x_x1957;
    kk_define_string_literal(, _s_x1958, 4, "H:mm", _ctx)
    _x_x1957 = kk_string_dup(_s_x1958, _ctx); /*string*/
    kk_string_t _x_x1959;
    kk_define_string_literal(, _s_x1960, 7, "H:mm:ss", _ctx)
    _x_x1959 = kk_string_dup(_s_x1960, _ctx); /*string*/
    kk_string_t _x_x1961;
    kk_define_string_literal(, _s_x1962, 10, "DD/MM/YYYY", _ctx)
    _x_x1961 = kk_string_dup(_s_x1962, _ctx); /*string*/
    kk_string_t _x_x1963;
    kk_define_string_literal(, _s_x1964, 21, "D \'de\' MMMM \'de\' YYYY", _ctx)
    _x_x1963 = kk_string_dup(_s_x1964, _ctx); /*string*/
    kk_string_t _x_x1965;
    kk_define_string_literal(, _s_x1966, 26, "D \'de\' MMMM \'de\' YYYY H:mm", _ctx)
    _x_x1965 = kk_string_dup(_s_x1966, _ctx); /*string*/
    kk_string_t _x_x1967;
    kk_define_string_literal(, _s_x1968, 32, "dddd, D \'de\' MMMM \'de\' YYYY H:mm", _ctx)
    _x_x1967 = kk_string_dup(_s_x1968, _ctx); /*string*/
    kk_std_time_locale_time_locale_es = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1955, day_names_10087, month_names_10088, _uniq_month_names_short_92, _uniq_day_names_short_153, _uniq_day_names_min_214, _x_x1957, _x_x1959, _x_x1961, _x_x1963, _x_x1965, _x_x1967, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_string_t _x_x1969;
    kk_define_string_literal(, _s_x1970, 2, "nl", _ctx)
    _x_x1969 = kk_string_dup(_s_x1970, _ctx); /*string*/
    kk_std_core_types__list _x_x1971;
    kk_box_t _x_x1972;
    kk_string_t _x_x1973;
    kk_define_string_literal(, _s_x1974, 7, "maandag", _ctx)
    _x_x1973 = kk_string_dup(_s_x1974, _ctx); /*string*/
    _x_x1972 = kk_string_box(_x_x1973); /*10021*/
    kk_std_core_types__list _x_x1975;
    kk_box_t _x_x1976;
    kk_string_t _x_x1977;
    kk_define_string_literal(, _s_x1978, 7, "dinsdag", _ctx)
    _x_x1977 = kk_string_dup(_s_x1978, _ctx); /*string*/
    _x_x1976 = kk_string_box(_x_x1977); /*10021*/
    kk_std_core_types__list _x_x1979;
    kk_box_t _x_x1980;
    kk_string_t _x_x1981;
    kk_define_string_literal(, _s_x1982, 8, "woensdag", _ctx)
    _x_x1981 = kk_string_dup(_s_x1982, _ctx); /*string*/
    _x_x1980 = kk_string_box(_x_x1981); /*10021*/
    kk_std_core_types__list _x_x1983;
    kk_box_t _x_x1984;
    kk_string_t _x_x1985;
    kk_define_string_literal(, _s_x1986, 9, "donderdag", _ctx)
    _x_x1985 = kk_string_dup(_s_x1986, _ctx); /*string*/
    _x_x1984 = kk_string_box(_x_x1985); /*10021*/
    kk_std_core_types__list _x_x1987;
    kk_box_t _x_x1988;
    kk_string_t _x_x1989;
    kk_define_string_literal(, _s_x1990, 7, "vrijdag", _ctx)
    _x_x1989 = kk_string_dup(_s_x1990, _ctx); /*string*/
    _x_x1988 = kk_string_box(_x_x1989); /*10021*/
    kk_std_core_types__list _x_x1991;
    kk_box_t _x_x1992;
    kk_string_t _x_x1993;
    kk_define_string_literal(, _s_x1994, 8, "zaterdag", _ctx)
    _x_x1993 = kk_string_dup(_s_x1994, _ctx); /*string*/
    _x_x1992 = kk_string_box(_x_x1993); /*10021*/
    kk_std_core_types__list _x_x1995;
    kk_box_t _x_x1996;
    kk_string_t _x_x1997;
    kk_define_string_literal(, _s_x1998, 6, "zondag", _ctx)
    _x_x1997 = kk_string_dup(_s_x1998, _ctx); /*string*/
    _x_x1996 = kk_string_box(_x_x1997); /*10021*/
    _x_x1995 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1996, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1991 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1992, _x_x1995, _ctx); /*list<10021>*/
    _x_x1987 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1988, _x_x1991, _ctx); /*list<10021>*/
    _x_x1983 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1984, _x_x1987, _ctx); /*list<10021>*/
    _x_x1979 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1980, _x_x1983, _ctx); /*list<10021>*/
    _x_x1975 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1976, _x_x1979, _ctx); /*list<10021>*/
    _x_x1971 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1972, _x_x1975, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x1999;
    kk_box_t _x_x2000;
    kk_string_t _x_x2001;
    kk_define_string_literal(, _s_x2002, 7, "januari", _ctx)
    _x_x2001 = kk_string_dup(_s_x2002, _ctx); /*string*/
    _x_x2000 = kk_string_box(_x_x2001); /*10021*/
    kk_std_core_types__list _x_x2003;
    kk_box_t _x_x2004;
    kk_string_t _x_x2005;
    kk_define_string_literal(, _s_x2006, 8, "februari", _ctx)
    _x_x2005 = kk_string_dup(_s_x2006, _ctx); /*string*/
    _x_x2004 = kk_string_box(_x_x2005); /*10021*/
    kk_std_core_types__list _x_x2007;
    kk_box_t _x_x2008;
    kk_string_t _x_x2009;
    kk_define_string_literal(, _s_x2010, 5, "maart", _ctx)
    _x_x2009 = kk_string_dup(_s_x2010, _ctx); /*string*/
    _x_x2008 = kk_string_box(_x_x2009); /*10021*/
    kk_std_core_types__list _x_x2011;
    kk_box_t _x_x2012;
    kk_string_t _x_x2013;
    kk_define_string_literal(, _s_x2014, 5, "april", _ctx)
    _x_x2013 = kk_string_dup(_s_x2014, _ctx); /*string*/
    _x_x2012 = kk_string_box(_x_x2013); /*10021*/
    kk_std_core_types__list _x_x2015;
    kk_box_t _x_x2016;
    kk_string_t _x_x2017;
    kk_define_string_literal(, _s_x2018, 3, "mei", _ctx)
    _x_x2017 = kk_string_dup(_s_x2018, _ctx); /*string*/
    _x_x2016 = kk_string_box(_x_x2017); /*10021*/
    kk_std_core_types__list _x_x2019;
    kk_box_t _x_x2020;
    kk_string_t _x_x2021;
    kk_define_string_literal(, _s_x2022, 4, "juni", _ctx)
    _x_x2021 = kk_string_dup(_s_x2022, _ctx); /*string*/
    _x_x2020 = kk_string_box(_x_x2021); /*10021*/
    kk_std_core_types__list _x_x2023;
    kk_box_t _x_x2024;
    kk_string_t _x_x2025;
    kk_define_string_literal(, _s_x2026, 4, "juli", _ctx)
    _x_x2025 = kk_string_dup(_s_x2026, _ctx); /*string*/
    _x_x2024 = kk_string_box(_x_x2025); /*10021*/
    kk_std_core_types__list _x_x2027;
    kk_box_t _x_x2028;
    kk_string_t _x_x2029;
    kk_define_string_literal(, _s_x2030, 8, "augustus", _ctx)
    _x_x2029 = kk_string_dup(_s_x2030, _ctx); /*string*/
    _x_x2028 = kk_string_box(_x_x2029); /*10021*/
    kk_std_core_types__list _x_x2031;
    kk_box_t _x_x2032;
    kk_string_t _x_x2033;
    kk_define_string_literal(, _s_x2034, 9, "september", _ctx)
    _x_x2033 = kk_string_dup(_s_x2034, _ctx); /*string*/
    _x_x2032 = kk_string_box(_x_x2033); /*10021*/
    kk_std_core_types__list _x_x2035;
    kk_box_t _x_x2036;
    kk_string_t _x_x2037;
    kk_define_string_literal(, _s_x2038, 7, "oktober", _ctx)
    _x_x2037 = kk_string_dup(_s_x2038, _ctx); /*string*/
    _x_x2036 = kk_string_box(_x_x2037); /*10021*/
    kk_std_core_types__list _x_x2039;
    kk_box_t _x_x2040;
    kk_string_t _x_x2041;
    kk_define_string_literal(, _s_x2042, 8, "november", _ctx)
    _x_x2041 = kk_string_dup(_s_x2042, _ctx); /*string*/
    _x_x2040 = kk_string_box(_x_x2041); /*10021*/
    kk_std_core_types__list _x_x2043;
    kk_box_t _x_x2044;
    kk_string_t _x_x2045;
    kk_define_string_literal(, _s_x2046, 8, "december", _ctx)
    _x_x2045 = kk_string_dup(_s_x2046, _ctx); /*string*/
    _x_x2044 = kk_string_box(_x_x2045); /*10021*/
    _x_x2043 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2044, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x2039 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2040, _x_x2043, _ctx); /*list<10021>*/
    _x_x2035 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2036, _x_x2039, _ctx); /*list<10021>*/
    _x_x2031 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2032, _x_x2035, _ctx); /*list<10021>*/
    _x_x2027 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2028, _x_x2031, _ctx); /*list<10021>*/
    _x_x2023 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2024, _x_x2027, _ctx); /*list<10021>*/
    _x_x2019 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2020, _x_x2023, _ctx); /*list<10021>*/
    _x_x2015 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2016, _x_x2019, _ctx); /*list<10021>*/
    _x_x2011 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2012, _x_x2015, _ctx); /*list<10021>*/
    _x_x2007 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2008, _x_x2011, _ctx); /*list<10021>*/
    _x_x2003 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2004, _x_x2007, _ctx); /*list<10021>*/
    _x_x1999 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2000, _x_x2003, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x2047;
    kk_box_t _x_x2048;
    kk_string_t _x_x2049;
    kk_define_string_literal(, _s_x2050, 3, "jan", _ctx)
    _x_x2049 = kk_string_dup(_s_x2050, _ctx); /*string*/
    _x_x2048 = kk_string_box(_x_x2049); /*10021*/
    kk_std_core_types__list _x_x2051;
    kk_box_t _x_x2052;
    kk_string_t _x_x2053;
    kk_define_string_literal(, _s_x2054, 3, "feb", _ctx)
    _x_x2053 = kk_string_dup(_s_x2054, _ctx); /*string*/
    _x_x2052 = kk_string_box(_x_x2053); /*10021*/
    kk_std_core_types__list _x_x2055;
    kk_box_t _x_x2056;
    kk_string_t _x_x2057;
    kk_define_string_literal(, _s_x2058, 3, "mrt", _ctx)
    _x_x2057 = kk_string_dup(_s_x2058, _ctx); /*string*/
    _x_x2056 = kk_string_box(_x_x2057); /*10021*/
    kk_std_core_types__list _x_x2059;
    kk_box_t _x_x2060;
    kk_string_t _x_x2061;
    kk_define_string_literal(, _s_x2062, 3, "apr", _ctx)
    _x_x2061 = kk_string_dup(_s_x2062, _ctx); /*string*/
    _x_x2060 = kk_string_box(_x_x2061); /*10021*/
    kk_std_core_types__list _x_x2063;
    kk_box_t _x_x2064;
    kk_string_t _x_x2065;
    kk_define_string_literal(, _s_x2066, 3, "mei", _ctx)
    _x_x2065 = kk_string_dup(_s_x2066, _ctx); /*string*/
    _x_x2064 = kk_string_box(_x_x2065); /*10021*/
    kk_std_core_types__list _x_x2067;
    kk_box_t _x_x2068;
    kk_string_t _x_x2069;
    kk_define_string_literal(, _s_x2070, 3, "jun", _ctx)
    _x_x2069 = kk_string_dup(_s_x2070, _ctx); /*string*/
    _x_x2068 = kk_string_box(_x_x2069); /*10021*/
    kk_std_core_types__list _x_x2071;
    kk_box_t _x_x2072;
    kk_string_t _x_x2073;
    kk_define_string_literal(, _s_x2074, 3, "jul", _ctx)
    _x_x2073 = kk_string_dup(_s_x2074, _ctx); /*string*/
    _x_x2072 = kk_string_box(_x_x2073); /*10021*/
    kk_std_core_types__list _x_x2075;
    kk_box_t _x_x2076;
    kk_string_t _x_x2077;
    kk_define_string_literal(, _s_x2078, 3, "aug", _ctx)
    _x_x2077 = kk_string_dup(_s_x2078, _ctx); /*string*/
    _x_x2076 = kk_string_box(_x_x2077); /*10021*/
    kk_std_core_types__list _x_x2079;
    kk_box_t _x_x2080;
    kk_string_t _x_x2081;
    kk_define_string_literal(, _s_x2082, 3, "sep", _ctx)
    _x_x2081 = kk_string_dup(_s_x2082, _ctx); /*string*/
    _x_x2080 = kk_string_box(_x_x2081); /*10021*/
    kk_std_core_types__list _x_x2083;
    kk_box_t _x_x2084;
    kk_string_t _x_x2085;
    kk_define_string_literal(, _s_x2086, 3, "okt", _ctx)
    _x_x2085 = kk_string_dup(_s_x2086, _ctx); /*string*/
    _x_x2084 = kk_string_box(_x_x2085); /*10021*/
    kk_std_core_types__list _x_x2087;
    kk_box_t _x_x2088;
    kk_string_t _x_x2089;
    kk_define_string_literal(, _s_x2090, 3, "nov", _ctx)
    _x_x2089 = kk_string_dup(_s_x2090, _ctx); /*string*/
    _x_x2088 = kk_string_box(_x_x2089); /*10021*/
    kk_std_core_types__list _x_x2091;
    kk_box_t _x_x2092;
    kk_string_t _x_x2093;
    kk_define_string_literal(, _s_x2094, 3, "dec", _ctx)
    _x_x2093 = kk_string_dup(_s_x2094, _ctx); /*string*/
    _x_x2092 = kk_string_box(_x_x2093); /*10021*/
    _x_x2091 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2092, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x2087 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2088, _x_x2091, _ctx); /*list<10021>*/
    _x_x2083 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2084, _x_x2087, _ctx); /*list<10021>*/
    _x_x2079 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2080, _x_x2083, _ctx); /*list<10021>*/
    _x_x2075 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2076, _x_x2079, _ctx); /*list<10021>*/
    _x_x2071 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2072, _x_x2075, _ctx); /*list<10021>*/
    _x_x2067 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2068, _x_x2071, _ctx); /*list<10021>*/
    _x_x2063 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2064, _x_x2067, _ctx); /*list<10021>*/
    _x_x2059 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2060, _x_x2063, _ctx); /*list<10021>*/
    _x_x2055 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2056, _x_x2059, _ctx); /*list<10021>*/
    _x_x2051 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2052, _x_x2055, _ctx); /*list<10021>*/
    _x_x2047 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2048, _x_x2051, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x2095;
    kk_box_t _x_x2096;
    kk_string_t _x_x2097;
    kk_define_string_literal(, _s_x2098, 3, "ma.", _ctx)
    _x_x2097 = kk_string_dup(_s_x2098, _ctx); /*string*/
    _x_x2096 = kk_string_box(_x_x2097); /*10021*/
    kk_std_core_types__list _x_x2099;
    kk_box_t _x_x2100;
    kk_string_t _x_x2101;
    kk_define_string_literal(, _s_x2102, 3, "di.", _ctx)
    _x_x2101 = kk_string_dup(_s_x2102, _ctx); /*string*/
    _x_x2100 = kk_string_box(_x_x2101); /*10021*/
    kk_std_core_types__list _x_x2103;
    kk_box_t _x_x2104;
    kk_string_t _x_x2105;
    kk_define_string_literal(, _s_x2106, 3, "wo.", _ctx)
    _x_x2105 = kk_string_dup(_s_x2106, _ctx); /*string*/
    _x_x2104 = kk_string_box(_x_x2105); /*10021*/
    kk_std_core_types__list _x_x2107;
    kk_box_t _x_x2108;
    kk_string_t _x_x2109;
    kk_define_string_literal(, _s_x2110, 3, "do.", _ctx)
    _x_x2109 = kk_string_dup(_s_x2110, _ctx); /*string*/
    _x_x2108 = kk_string_box(_x_x2109); /*10021*/
    kk_std_core_types__list _x_x2111;
    kk_box_t _x_x2112;
    kk_string_t _x_x2113;
    kk_define_string_literal(, _s_x2114, 3, "vr.", _ctx)
    _x_x2113 = kk_string_dup(_s_x2114, _ctx); /*string*/
    _x_x2112 = kk_string_box(_x_x2113); /*10021*/
    kk_std_core_types__list _x_x2115;
    kk_box_t _x_x2116;
    kk_string_t _x_x2117;
    kk_define_string_literal(, _s_x2118, 3, "za.", _ctx)
    _x_x2117 = kk_string_dup(_s_x2118, _ctx); /*string*/
    _x_x2116 = kk_string_box(_x_x2117); /*10021*/
    kk_std_core_types__list _x_x2119;
    kk_box_t _x_x2120;
    kk_string_t _x_x2121;
    kk_define_string_literal(, _s_x2122, 3, "zo.", _ctx)
    _x_x2121 = kk_string_dup(_s_x2122, _ctx); /*string*/
    _x_x2120 = kk_string_box(_x_x2121); /*10021*/
    _x_x2119 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2120, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x2115 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2116, _x_x2119, _ctx); /*list<10021>*/
    _x_x2111 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2112, _x_x2115, _ctx); /*list<10021>*/
    _x_x2107 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2108, _x_x2111, _ctx); /*list<10021>*/
    _x_x2103 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2104, _x_x2107, _ctx); /*list<10021>*/
    _x_x2099 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2100, _x_x2103, _ctx); /*list<10021>*/
    _x_x2095 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2096, _x_x2099, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x2123;
    kk_box_t _x_x2124;
    kk_string_t _x_x2125;
    kk_define_string_literal(, _s_x2126, 2, "Ma", _ctx)
    _x_x2125 = kk_string_dup(_s_x2126, _ctx); /*string*/
    _x_x2124 = kk_string_box(_x_x2125); /*10021*/
    kk_std_core_types__list _x_x2127;
    kk_box_t _x_x2128;
    kk_string_t _x_x2129;
    kk_define_string_literal(, _s_x2130, 2, "Di", _ctx)
    _x_x2129 = kk_string_dup(_s_x2130, _ctx); /*string*/
    _x_x2128 = kk_string_box(_x_x2129); /*10021*/
    kk_std_core_types__list _x_x2131;
    kk_box_t _x_x2132;
    kk_string_t _x_x2133;
    kk_define_string_literal(, _s_x2134, 2, "Wo", _ctx)
    _x_x2133 = kk_string_dup(_s_x2134, _ctx); /*string*/
    _x_x2132 = kk_string_box(_x_x2133); /*10021*/
    kk_std_core_types__list _x_x2135;
    kk_box_t _x_x2136;
    kk_string_t _x_x2137;
    kk_define_string_literal(, _s_x2138, 2, "Do", _ctx)
    _x_x2137 = kk_string_dup(_s_x2138, _ctx); /*string*/
    _x_x2136 = kk_string_box(_x_x2137); /*10021*/
    kk_std_core_types__list _x_x2139;
    kk_box_t _x_x2140;
    kk_string_t _x_x2141;
    kk_define_string_literal(, _s_x2142, 2, "Vr", _ctx)
    _x_x2141 = kk_string_dup(_s_x2142, _ctx); /*string*/
    _x_x2140 = kk_string_box(_x_x2141); /*10021*/
    kk_std_core_types__list _x_x2143;
    kk_box_t _x_x2144;
    kk_string_t _x_x2145;
    kk_define_string_literal(, _s_x2146, 2, "Za", _ctx)
    _x_x2145 = kk_string_dup(_s_x2146, _ctx); /*string*/
    _x_x2144 = kk_string_box(_x_x2145); /*10021*/
    kk_std_core_types__list _x_x2147;
    kk_box_t _x_x2148;
    kk_string_t _x_x2149;
    kk_define_string_literal(, _s_x2150, 2, "Zo", _ctx)
    _x_x2149 = kk_string_dup(_s_x2150, _ctx); /*string*/
    _x_x2148 = kk_string_box(_x_x2149); /*10021*/
    _x_x2147 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2148, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x2143 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2144, _x_x2147, _ctx); /*list<10021>*/
    _x_x2139 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2140, _x_x2143, _ctx); /*list<10021>*/
    _x_x2135 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2136, _x_x2139, _ctx); /*list<10021>*/
    _x_x2131 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2132, _x_x2135, _ctx); /*list<10021>*/
    _x_x2127 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2128, _x_x2131, _ctx); /*list<10021>*/
    _x_x2123 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2124, _x_x2127, _ctx); /*list<10021>*/
    kk_string_t _x_x2151;
    kk_std_core_types__optional _match_x1076 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1076, _ctx)) {
      kk_box_t _box_x945 = _match_x1076._cons._Optional.value;
      kk_string_t _uniq_format_t_219 = kk_string_unbox(_box_x945);
      kk_string_dup(_uniq_format_t_219, _ctx);
      kk_std_core_types__optional_drop(_match_x1076, _ctx);
      _x_x2151 = _uniq_format_t_219; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1076, _ctx);
      kk_define_string_literal(, _s_x2152, 5, "HH:mm", _ctx)
      _x_x2151 = kk_string_dup(_s_x2152, _ctx); /*string*/
    }
    kk_string_t _x_x2153;
    kk_std_core_types__optional _match_x1075 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1075, _ctx)) {
      kk_box_t _box_x946 = _match_x1075._cons._Optional.value;
      kk_string_t _uniq_format_tt_223 = kk_string_unbox(_box_x946);
      kk_string_dup(_uniq_format_tt_223, _ctx);
      kk_std_core_types__optional_drop(_match_x1075, _ctx);
      _x_x2153 = _uniq_format_tt_223; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1075, _ctx);
      kk_define_string_literal(, _s_x2154, 8, "HH:mm:ss", _ctx)
      _x_x2153 = kk_string_dup(_s_x2154, _ctx); /*string*/
    }
    kk_string_t _x_x2155;
    kk_define_string_literal(, _s_x2156, 10, "DD-MM-YYYY", _ctx)
    _x_x2155 = kk_string_dup(_s_x2156, _ctx); /*string*/
    kk_string_t _x_x2157;
    kk_std_core_types__optional _match_x1074 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1074, _ctx)) {
      kk_box_t _box_x947 = _match_x1074._cons._Optional.value;
      kk_string_t _uniq_format_ll_231 = kk_string_unbox(_box_x947);
      kk_string_dup(_uniq_format_ll_231, _ctx);
      kk_std_core_types__optional_drop(_match_x1074, _ctx);
      _x_x2157 = _uniq_format_ll_231; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1074, _ctx);
      kk_define_string_literal(, _s_x2158, 11, "D MMMM YYYY", _ctx)
      _x_x2157 = kk_string_dup(_s_x2158, _ctx); /*string*/
    }
    kk_string_t _x_x2159;
    kk_std_core_types__optional _match_x1073 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1073, _ctx)) {
      kk_box_t _box_x948 = _match_x1073._cons._Optional.value;
      kk_string_t _uniq_format_lll_235 = kk_string_unbox(_box_x948);
      kk_string_dup(_uniq_format_lll_235, _ctx);
      kk_std_core_types__optional_drop(_match_x1073, _ctx);
      _x_x2159 = _uniq_format_lll_235; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1073, _ctx);
      kk_define_string_literal(, _s_x2160, 13, "D MMMM YYYY t", _ctx)
      _x_x2159 = kk_string_dup(_s_x2160, _ctx); /*string*/
    }
    kk_string_t _x_x2161;
    kk_std_core_types__optional _match_x1072 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1072, _ctx)) {
      kk_box_t _box_x949 = _match_x1072._cons._Optional.value;
      kk_string_t _uniq_format_llll_239 = kk_string_unbox(_box_x949);
      kk_string_dup(_uniq_format_llll_239, _ctx);
      kk_std_core_types__optional_drop(_match_x1072, _ctx);
      _x_x2161 = _uniq_format_llll_239; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1072, _ctx);
      kk_define_string_literal(, _s_x2162, 18, "dddd D MMMM YYYY t", _ctx)
      _x_x2161 = kk_string_dup(_s_x2162, _ctx); /*string*/
    }
    kk_std_time_locale_time_locale_nl = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1969, _x_x1971, _x_x1999, _x_x2047, _x_x2095, _x_x2123, _x_x2151, _x_x2153, _x_x2155, _x_x2157, _x_x2159, _x_x2161, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_box_t _x_x2163;
    kk_std_time_locale__time_locale _x_x2164 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
    _x_x2163 = kk_std_time_locale__time_locale_box(_x_x2164, _ctx); /*10021*/
    kk_std_core_types__list _x_x2165;
    kk_box_t _x_x2166;
    kk_std_time_locale__time_locale _x_x2167 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_de, _ctx); /*std/time/locale/time-locale*/
    _x_x2166 = kk_std_time_locale__time_locale_box(_x_x2167, _ctx); /*10021*/
    kk_std_core_types__list _x_x2168;
    kk_box_t _x_x2169;
    kk_std_time_locale__time_locale _x_x2170 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
    _x_x2169 = kk_std_time_locale__time_locale_box(_x_x2170, _ctx); /*10021*/
    kk_std_core_types__list _x_x2171;
    kk_box_t _x_x2172;
    kk_std_time_locale__time_locale _x_x2173 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_es, _ctx); /*std/time/locale/time-locale*/
    _x_x2172 = kk_std_time_locale__time_locale_box(_x_x2173, _ctx); /*10021*/
    kk_std_core_types__list _x_x2174;
    kk_box_t _x_x2175;
    kk_std_time_locale__time_locale _x_x2176 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_fr, _ctx); /*std/time/locale/time-locale*/
    _x_x2175 = kk_std_time_locale__time_locale_box(_x_x2176, _ctx); /*10021*/
    kk_std_core_types__list _x_x2177;
    kk_box_t _x_x2178;
    kk_std_time_locale__time_locale _x_x2179 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_nl, _ctx); /*std/time/locale/time-locale*/
    _x_x2178 = kk_std_time_locale__time_locale_box(_x_x2179, _ctx); /*10021*/
    _x_x2177 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2178, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x2174 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2175, _x_x2177, _ctx); /*list<10021>*/
    _x_x2171 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2172, _x_x2174, _ctx); /*list<10021>*/
    _x_x2168 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2169, _x_x2171, _ctx); /*list<10021>*/
    _x_x2165 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2166, _x_x2168, _ctx); /*list<10021>*/
    kk_std_time_locale_locales = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2163, _x_x2165, _ctx); /*list<std/time/locale/time-locale>*/
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
