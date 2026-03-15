// Koka generated module: src/rust_bridge, koka version: 3.2.2, platform: 64-bit
#include "src_rust__bridge.h"

kk_src_rust__bridge__rust_call kk_src_rust__bridge_rust_call_fs__copy(kk_src_rust__bridge__rust_call _this, kk_std_core_types__optional func_name, kk_std_core_types__optional args, kk_std_core_types__optional result, kk_std_core_types__optional elapsed_ms, kk_context_t* _ctx) { /* (rust-call, func-name : ? string, args : ? (list<string>), result : ? string, elapsed-ms : ? float64) -> rust-call */ 
  kk_string_t _x_x178;
  if (kk_std_core_types__is_Optional(func_name, _ctx)) {
    kk_box_t _box_x0 = func_name._cons._Optional.value;
    kk_string_t _uniq_func_name_76 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_func_name_76, _ctx);
    kk_std_core_types__optional_drop(func_name, _ctx);
    _x_x178 = _uniq_func_name_76; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(func_name, _ctx);
    {
      struct kk_src_rust__bridge_Rust_call* _con_x179 = kk_src_rust__bridge__as_Rust_call(_this, _ctx);
      kk_string_t _x = _con_x179->func_name;
      kk_string_dup(_x, _ctx);
      _x_x178 = _x; /*string*/
    }
  }
  kk_std_core_types__list _x_x180;
  if (kk_std_core_types__is_Optional(args, _ctx)) {
    kk_box_t _box_x1 = args._cons._Optional.value;
    kk_std_core_types__list _uniq_args_84 = kk_std_core_types__list_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_args_84, _ctx);
    kk_std_core_types__optional_drop(args, _ctx);
    _x_x180 = _uniq_args_84; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(args, _ctx);
    {
      struct kk_src_rust__bridge_Rust_call* _con_x181 = kk_src_rust__bridge__as_Rust_call(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x181->args;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x180 = _x_0; /*list<string>*/
    }
  }
  kk_string_t _x_x182;
  if (kk_std_core_types__is_Optional(result, _ctx)) {
    kk_box_t _box_x2 = result._cons._Optional.value;
    kk_string_t _uniq_result_92 = kk_string_unbox(_box_x2);
    kk_string_dup(_uniq_result_92, _ctx);
    kk_std_core_types__optional_drop(result, _ctx);
    _x_x182 = _uniq_result_92; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(result, _ctx);
    {
      struct kk_src_rust__bridge_Rust_call* _con_x183 = kk_src_rust__bridge__as_Rust_call(_this, _ctx);
      kk_string_t _x_1 = _con_x183->result;
      kk_string_dup(_x_1, _ctx);
      _x_x182 = _x_1; /*string*/
    }
  }
  double _x_x184;
  if (kk_std_core_types__is_Optional(elapsed_ms, _ctx)) {
    kk_box_t _box_x3 = elapsed_ms._cons._Optional.value;
    double _uniq_elapsed_ms_100 = kk_double_unbox(_box_x3, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(elapsed_ms, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x184 = _uniq_elapsed_ms_100; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(elapsed_ms, _ctx);
    {
      struct kk_src_rust__bridge_Rust_call* _con_x185 = kk_src_rust__bridge__as_Rust_call(_this, _ctx);
      kk_string_t _pat_0_3 = _con_x185->func_name;
      kk_std_core_types__list _pat_1_4 = _con_x185->args;
      kk_string_t _pat_2_3 = _con_x185->result;
      double _x_2 = _con_x185->elapsed_ms;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_2_3, _ctx);
        kk_std_core_types__list_drop(_pat_1_4, _ctx);
        kk_string_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x184 = _x_2; /*float64*/
    }
  }
  return kk_src_rust__bridge__new_Rust_call(kk_reuse_null, 0, _x_x178, _x_x180, _x_x182, _x_x184, _ctx);
}

kk_src_rust__bridge__bridge_stats kk_src_rust__bridge_bridge_stats_fs__copy(kk_src_rust__bridge__bridge_stats _this, kk_std_core_types__optional calls_made, kk_std_core_types__optional total_time_ms, kk_std_core_types__optional cache_hits, kk_std_core_types__optional cache_misses, kk_context_t* _ctx) { /* (bridge-stats, calls-made : ? int64, total-time-ms : ? float64, cache-hits : ? int64, cache-misses : ? int64) -> bridge-stats */ 
  int64_t _x_x190;
  if (kk_std_core_types__is_Optional(calls_made, _ctx)) {
    kk_box_t _box_x4 = calls_made._cons._Optional.value;
    int64_t _uniq_calls_made_151 = kk_int64_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(calls_made, _ctx);
    _x_x190 = _uniq_calls_made_151; /*int64*/
  }
  else {
    kk_std_core_types__optional_drop(calls_made, _ctx);
    {
      struct kk_src_rust__bridge_Bridge_stats* _con_x191 = kk_src_rust__bridge__as_Bridge_stats(_this, _ctx);
      int64_t _x = _con_x191->calls_made;
      _x_x190 = _x; /*int64*/
    }
  }
  double _x_x192;
  if (kk_std_core_types__is_Optional(total_time_ms, _ctx)) {
    kk_box_t _box_x5 = total_time_ms._cons._Optional.value;
    double _uniq_total_time_ms_159 = kk_double_unbox(_box_x5, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    _x_x192 = _uniq_total_time_ms_159; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    {
      struct kk_src_rust__bridge_Bridge_stats* _con_x193 = kk_src_rust__bridge__as_Bridge_stats(_this, _ctx);
      double _x_0 = _con_x193->total_time_ms;
      _x_x192 = _x_0; /*float64*/
    }
  }
  int64_t _x_x194;
  if (kk_std_core_types__is_Optional(cache_hits, _ctx)) {
    kk_box_t _box_x6 = cache_hits._cons._Optional.value;
    int64_t _uniq_cache_hits_167 = kk_int64_unbox(_box_x6, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(cache_hits, _ctx);
    _x_x194 = _uniq_cache_hits_167; /*int64*/
  }
  else {
    kk_std_core_types__optional_drop(cache_hits, _ctx);
    {
      struct kk_src_rust__bridge_Bridge_stats* _con_x195 = kk_src_rust__bridge__as_Bridge_stats(_this, _ctx);
      int64_t _x_1 = _con_x195->cache_hits;
      _x_x194 = _x_1; /*int64*/
    }
  }
  int64_t _x_x196;
  if (kk_std_core_types__is_Optional(cache_misses, _ctx)) {
    kk_box_t _box_x7 = cache_misses._cons._Optional.value;
    int64_t _uniq_cache_misses_175 = kk_int64_unbox(_box_x7, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(cache_misses, _ctx);
    kk_src_rust__bridge__bridge_stats_drop(_this, _ctx);
    _x_x196 = _uniq_cache_misses_175; /*int64*/
  }
  else {
    kk_std_core_types__optional_drop(cache_misses, _ctx);
    {
      struct kk_src_rust__bridge_Bridge_stats* _con_x197 = kk_src_rust__bridge__as_Bridge_stats(_this, _ctx);
      int64_t _x_2 = _con_x197->cache_misses;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x196 = _x_2; /*int64*/
    }
  }
  return kk_src_rust__bridge__new_Bridge_stats(kk_reuse_null, 0, _x_x190, _x_x192, _x_x194, _x_x196, _ctx);
}

kk_src_rust__bridge__bridge_stats kk_src_rust__bridge_update_stats(kk_src_rust__bridge__bridge_stats stats, double elapsed, bool cache_hit, kk_context_t* _ctx) { /* (stats : bridge-stats, elapsed : float64, cache-hit : bool) -> bridge-stats */ 
  int64_t _x_x203;
  int64_t _x_x204;
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x205 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
    int64_t _x = _con_x205->calls_made;
    _x_x204 = _x; /*int64*/
  }
  int64_t _x_x206 = (KK_I64(1)); /*int64*/
  _x_x203 = (int64_t)((uint64_t)_x_x204 + (uint64_t)_x_x206); /*int64*/
  double _x_x207;
  double _x_x208;
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x209 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
    double _x_0 = _con_x209->total_time_ms;
    _x_x208 = _x_0; /*float64*/
  }
  _x_x207 = (_x_x208 + elapsed); /*float64*/
  int64_t _x_x210;
  if (cache_hit) {
    int64_t _x_x211;
    {
      struct kk_src_rust__bridge_Bridge_stats* _con_x212 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
      int64_t _x_1 = _con_x212->cache_hits;
      _x_x211 = _x_1; /*int64*/
    }
    int64_t _x_x213 = (KK_I64(1)); /*int64*/
    _x_x210 = (int64_t)((uint64_t)_x_x211 + (uint64_t)_x_x213); /*int64*/
  }
  else {
    struct kk_src_rust__bridge_Bridge_stats* _con_x214 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
    int64_t _x_2 = _con_x214->cache_hits;
    _x_x210 = _x_2; /*int64*/
  }
  int64_t _x_x215;
  if (cache_hit) {
    struct kk_src_rust__bridge_Bridge_stats* _con_x216 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
    int64_t _x_3 = _con_x216->cache_misses;
    if kk_likely(kk_datatype_ptr_is_unique(stats, _ctx)) {
      kk_datatype_ptr_free(stats, _ctx);
    }
    else {
      kk_datatype_ptr_decref(stats, _ctx);
    }
    _x_x215 = _x_3; /*int64*/
  }
  else {
    int64_t _x_x217;
    {
      struct kk_src_rust__bridge_Bridge_stats* _con_x218 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
      int64_t _x_4 = _con_x218->cache_misses;
      if kk_likely(kk_datatype_ptr_is_unique(stats, _ctx)) {
        kk_datatype_ptr_free(stats, _ctx);
      }
      else {
        kk_datatype_ptr_decref(stats, _ctx);
      }
      _x_x217 = _x_4; /*int64*/
    }
    int64_t _x_x219 = (KK_I64(1)); /*int64*/
    _x_x215 = (int64_t)((uint64_t)_x_x217 + (uint64_t)_x_x219); /*int64*/
  }
  return kk_src_rust__bridge__new_Bridge_stats(kk_reuse_null, 0, _x_x203, _x_x207, _x_x210, _x_x215, _ctx);
}

kk_string_t kk_src_rust__bridge_json_stats(kk_src_rust__bridge__bridge_stats s, kk_context_t* _ctx) { /* (s : bridge-stats) -> string */ 
  kk_string_t _x_x220;
  kk_define_string_literal(, _s_x221, 9, "{\"calls\":", _ctx)
  _x_x220 = kk_string_dup(_s_x221, _ctx); /*string*/
  kk_string_t _x_x222;
  kk_string_t _x_x223;
  kk_integer_t _x_x224;
  int64_t _x_x225;
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x226 = kk_src_rust__bridge__as_Bridge_stats(s, _ctx);
    int64_t _x = _con_x226->calls_made;
    _x_x225 = _x; /*int64*/
  }
  _x_x224 = kk_integer_from_int64(_x_x225,kk_context()); /*int*/
  _x_x223 = kk_std_core_int_show(_x_x224, _ctx); /*string*/
  kk_string_t _x_x227;
  kk_string_t _x_x228;
  kk_define_string_literal(, _s_x229, 12, ",\"total_ms\":", _ctx)
  _x_x228 = kk_string_dup(_s_x229, _ctx); /*string*/
  kk_string_t _x_x230;
  kk_string_t _x_x231;
  double _x_x232;
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x233 = kk_src_rust__bridge__as_Bridge_stats(s, _ctx);
    double _x_0 = _con_x233->total_time_ms;
    _x_x232 = _x_0; /*float64*/
  }
  _x_x231 = kk_std_num_float64_show(_x_x232, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x234;
  kk_string_t _x_x235;
  kk_define_string_literal(, _s_x236, 14, ",\"cache_hits\":", _ctx)
  _x_x235 = kk_string_dup(_s_x236, _ctx); /*string*/
  kk_string_t _x_x237;
  kk_string_t _x_x238;
  kk_integer_t _x_x239;
  int64_t _x_x240;
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x241 = kk_src_rust__bridge__as_Bridge_stats(s, _ctx);
    int64_t _x_1 = _con_x241->cache_hits;
    _x_x240 = _x_1; /*int64*/
  }
  _x_x239 = kk_integer_from_int64(_x_x240,kk_context()); /*int*/
  _x_x238 = kk_std_core_int_show(_x_x239, _ctx); /*string*/
  kk_string_t _x_x242;
  kk_string_t _x_x243;
  kk_define_string_literal(, _s_x244, 16, ",\"cache_misses\":", _ctx)
  _x_x243 = kk_string_dup(_s_x244, _ctx); /*string*/
  kk_string_t _x_x245;
  kk_string_t _x_x246;
  kk_integer_t _x_x247;
  int64_t _x_x248;
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x249 = kk_src_rust__bridge__as_Bridge_stats(s, _ctx);
    int64_t _x_2 = _con_x249->cache_misses;
    if kk_likely(kk_datatype_ptr_is_unique(s, _ctx)) {
      kk_datatype_ptr_free(s, _ctx);
    }
    else {
      kk_datatype_ptr_decref(s, _ctx);
    }
    _x_x248 = _x_2; /*int64*/
  }
  _x_x247 = kk_integer_from_int64(_x_x248,kk_context()); /*int*/
  _x_x246 = kk_std_core_int_show(_x_x247, _ctx); /*string*/
  kk_string_t _x_x250;
  kk_define_string_literal(, _s_x251, 1, "}", _ctx)
  _x_x250 = kk_string_dup(_s_x251, _ctx); /*string*/
  _x_x245 = kk_std_core_types__lp__plus__plus__rp_(_x_x246, _x_x250, _ctx); /*string*/
  _x_x242 = kk_std_core_types__lp__plus__plus__rp_(_x_x243, _x_x245, _ctx); /*string*/
  _x_x237 = kk_std_core_types__lp__plus__plus__rp_(_x_x238, _x_x242, _ctx); /*string*/
  _x_x234 = kk_std_core_types__lp__plus__plus__rp_(_x_x235, _x_x237, _ctx); /*string*/
  _x_x230 = kk_std_core_types__lp__plus__plus__rp_(_x_x231, _x_x234, _ctx); /*string*/
  _x_x227 = kk_std_core_types__lp__plus__plus__rp_(_x_x228, _x_x230, _ctx); /*string*/
  _x_x222 = kk_std_core_types__lp__plus__plus__rp_(_x_x223, _x_x227, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x220, _x_x222, _ctx);
}

kk_string_t kk_src_rust__bridge_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x149;
  kk_string_t _x_x252 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x253;
  kk_define_string_literal(, _s_x254, 8, "\"cosine\"", _ctx)
  _x_x253 = kk_string_dup(_s_x254, _ctx); /*string*/
  _match_x149 = kk_string_contains(_x_x252,_x_x253,kk_context()); /*bool*/
  if (_match_x149) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x255, 6, "cosine", _ctx)
    return kk_string_dup(_s_x255, _ctx);
  }
  {
    bool _match_x150;
    kk_string_t _x_x256 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x257;
    kk_define_string_literal(, _s_x258, 11, "\"serialize\"", _ctx)
    _x_x257 = kk_string_dup(_s_x258, _ctx); /*string*/
    _match_x150 = kk_string_contains(_x_x256,_x_x257,kk_context()); /*bool*/
    if (_match_x150) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x259, 9, "serialize", _ctx)
      return kk_string_dup(_s_x259, _ctx);
    }
    {
      bool _match_x151;
      kk_string_t _x_x260 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x261;
      kk_define_string_literal(, _s_x262, 7, "\"embed\"", _ctx)
      _x_x261 = kk_string_dup(_s_x262, _ctx); /*string*/
      _match_x151 = kk_string_contains(_x_x260,_x_x261,kk_context()); /*bool*/
      if (_match_x151) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x263, 5, "embed", _ctx)
        return kk_string_dup(_s_x263, _ctx);
      }
      {
        bool _match_x152;
        kk_string_t _x_x264 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x265;
        kk_define_string_literal(, _s_x266, 7, "\"stats\"", _ctx)
        _x_x265 = kk_string_dup(_s_x266, _ctx); /*string*/
        _match_x152 = kk_string_contains(_x_x264,_x_x265,kk_context()); /*bool*/
        if (_match_x152) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x267, 5, "stats", _ctx)
          return kk_string_dup(_s_x267, _ctx);
        }
        {
          bool _match_x153;
          kk_string_t _x_x268 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x269;
          kk_define_string_literal(, _s_x270, 7, "\"batch\"", _ctx)
          _x_x269 = kk_string_dup(_s_x270, _ctx); /*string*/
          _match_x153 = kk_string_contains(_x_x268,_x_x269,kk_context()); /*bool*/
          if (_match_x153) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x271, 5, "batch", _ctx)
            return kk_string_dup(_s_x271, _ctx);
          }
          {
            bool _match_x154;
            kk_string_t _x_x272;
            kk_define_string_literal(, _s_x273, 6, "\"quit\"", _ctx)
            _x_x272 = kk_string_dup(_s_x273, _ctx); /*string*/
            _match_x154 = kk_string_contains(line,_x_x272,kk_context()); /*bool*/
            if (_match_x154) {
              kk_define_string_literal(, _s_x274, 4, "quit", _ctx)
              return kk_string_dup(_s_x274, _ctx);
            }
            {
              kk_define_string_literal(, _s_x275, 7, "unknown", _ctx)
              return kk_string_dup(_s_x275, _ctx);
            }
          }
        }
      }
    }
  }
}

kk_std_core_types__tuple2 kk_src_rust__bridge_extract_vectors(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> (list<float64>, list<float64>) */ 
  kk_string_drop(line, _ctx);
  kk_box_t _x_x276;
  kk_std_core_types__list _x_x277;
  kk_std_core_types__list _x_x278;
  kk_std_core_types__list _x_x279 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_double_box(0x1.8p1, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x278 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_double_box(0x1p1, _ctx), _x_x279, _ctx); /*list<10021>*/
  _x_x277 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_double_box(0x1p0, _ctx), _x_x278, _ctx); /*list<10021>*/
  _x_x276 = kk_std_core_types__list_box(_x_x277, _ctx); /*10037*/
  kk_box_t _x_x280;
  kk_std_core_types__list _x_x281;
  kk_std_core_types__list _x_x282;
  kk_std_core_types__list _x_x283 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_double_box(0x1p2, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x282 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_double_box(0x1.8p1, _ctx), _x_x283, _ctx); /*list<10021>*/
  _x_x281 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_double_box(0x1p1, _ctx), _x_x282, _ctx); /*list<10021>*/
  _x_x280 = kk_std_core_types__list_box(_x_x281, _ctx); /*10038*/
  return kk_std_core_types__new_Tuple2(_x_x276, _x_x280, _ctx);
}
 
// monadic lift

kk_unit_t kk_src_rust__bridge__mlift_server_loop_10171(kk_string_t op, kk_src_rust__bridge__bridge_stats stats, kk_string_t _c_x10142, kk_context_t* _ctx) { /* (op : string, stats : bridge-stats, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10142, _ctx);
  bool _x_x3_10167;
  kk_string_t _x_x284;
  kk_define_string_literal(, _s_x285, 6, "cosine", _ctx)
  _x_x284 = kk_string_dup(_s_x285, _ctx); /*string*/
  _x_x3_10167 = kk_string_is_eq(op,_x_x284,kk_context()); /*bool*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_src_rust__bridge__bridge_stats x;
  int64_t _x_x286;
  int64_t _x_x287;
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x288 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
    int64_t _x = _con_x288->calls_made;
    _x_x287 = _x; /*int64*/
  }
  int64_t _x_x289 = (KK_I64(1)); /*int64*/
  _x_x286 = (int64_t)((uint64_t)_x_x287 + (uint64_t)_x_x289); /*int64*/
  double _x_x290;
  double _x_x291;
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x292 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
    double _x_0 = _con_x292->total_time_ms;
    _x_x291 = _x_0; /*float64*/
  }
  _x_x290 = (_x_x291 + (0x1.999999999999ap-4)); /*float64*/
  int64_t _x_x293;
  if (_x_x3_10167) {
    int64_t _x_x294;
    {
      struct kk_src_rust__bridge_Bridge_stats* _con_x295 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
      int64_t _x_1 = _con_x295->cache_hits;
      _x_x294 = _x_1; /*int64*/
    }
    int64_t _x_x296 = (KK_I64(1)); /*int64*/
    _x_x293 = (int64_t)((uint64_t)_x_x294 + (uint64_t)_x_x296); /*int64*/
  }
  else {
    struct kk_src_rust__bridge_Bridge_stats* _con_x297 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
    int64_t _x_2 = _con_x297->cache_hits;
    _x_x293 = _x_2; /*int64*/
  }
  int64_t _x_x298;
  if (_x_x3_10167) {
    struct kk_src_rust__bridge_Bridge_stats* _con_x299 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
    int64_t _x_3 = _con_x299->cache_misses;
    if kk_likely(kk_datatype_ptr_is_unique(stats, _ctx)) {
      kk_datatype_ptr_free(stats, _ctx);
    }
    else {
      kk_datatype_ptr_decref(stats, _ctx);
    }
    _x_x298 = _x_3; /*int64*/
  }
  else {
    int64_t _x_x300;
    {
      struct kk_src_rust__bridge_Bridge_stats* _con_x301 = kk_src_rust__bridge__as_Bridge_stats(stats, _ctx);
      int64_t _x_4 = _con_x301->cache_misses;
      if kk_likely(kk_datatype_ptr_is_unique(stats, _ctx)) {
        kk_datatype_ptr_free(stats, _ctx);
      }
      else {
        kk_datatype_ptr_decref(stats, _ctx);
      }
      _x_x300 = _x_4; /*int64*/
    }
    int64_t _x_x302 = (KK_I64(1)); /*int64*/
    _x_x298 = (int64_t)((uint64_t)_x_x300 + (uint64_t)_x_x302); /*int64*/
  }
  x = kk_src_rust__bridge__new_Bridge_stats(kk_reuse_null, 0, _x_x286, _x_x290, _x_x293, _x_x298, _ctx); /*src/rust_bridge/bridge-stats*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_src_rust__bridge_server_loop(x, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_src_rust__bridge__mlift_server_loop_10172_fun312__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_rust__bridge__mlift_server_loop_10172_fun312(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx);
static kk_function_t kk_src_rust__bridge__new_mlift_server_loop_10172_fun312(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_rust__bridge__mlift_server_loop_10172_fun312, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_rust__bridge__mlift_server_loop_10172_fun312(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x313;
  kk_string_t _x_x314 = kk_string_unbox(_b_x38); /*string*/
  _x_x313 = kk_src_rust__bridge_extract_op(_x_x314, _ctx); /*string*/
  return kk_string_box(_x_x313);
}


// lift anonymous function
struct kk_src_rust__bridge__mlift_server_loop_10172_fun319__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_rust__bridge__mlift_server_loop_10172_fun319(kk_function_t _fself, kk_box_t _b_x43, kk_context_t* _ctx);
static kk_function_t kk_src_rust__bridge__new_mlift_server_loop_10172_fun319(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_rust__bridge__mlift_server_loop_10172_fun319, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_rust__bridge__mlift_server_loop_10172_fun319(kk_function_t _fself, kk_box_t _b_x43, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x320;
  kk_string_t _x_x321 = kk_string_unbox(_b_x43); /*string*/
  _x_x320 = kk_src_rust__bridge_extract_vectors(_x_x321, _ctx); /*(list<float64>, list<float64>)*/
  return kk_std_core_types__tuple2_box(_x_x320, _ctx);
}


// lift anonymous function
struct kk_src_rust__bridge__mlift_server_loop_10172_fun342__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_rust__bridge__mlift_server_loop_10172_fun342(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx);
static kk_function_t kk_src_rust__bridge__new_mlift_server_loop_10172_fun342(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_rust__bridge__mlift_server_loop_10172_fun342, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_rust__bridge__mlift_server_loop_10172_fun342(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x343;
  kk_src_rust__bridge__bridge_stats _x_x344 = kk_src_rust__bridge__bridge_stats_unbox(_b_x48, KK_OWNED, _ctx); /*src/rust_bridge/bridge-stats*/
  _x_x343 = kk_src_rust__bridge_json_stats(_x_x344, _ctx); /*string*/
  return kk_string_box(_x_x343);
}


// lift anonymous function
struct kk_src_rust__bridge__mlift_server_loop_10172_fun349__t {
  struct kk_function_s _base;
  kk_string_t op_0;
  kk_src_rust__bridge__bridge_stats stats_1;
};
static kk_box_t kk_src_rust__bridge__mlift_server_loop_10172_fun349(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx);
static kk_function_t kk_src_rust__bridge__new_mlift_server_loop_10172_fun349(kk_string_t op_0, kk_src_rust__bridge__bridge_stats stats_1, kk_context_t* _ctx) {
  struct kk_src_rust__bridge__mlift_server_loop_10172_fun349__t* _self = kk_function_alloc_as(struct kk_src_rust__bridge__mlift_server_loop_10172_fun349__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_rust__bridge__mlift_server_loop_10172_fun349, kk_context());
  _self->op_0 = op_0;
  _self->stats_1 = stats_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_rust__bridge__mlift_server_loop_10172_fun349(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx) {
  struct kk_src_rust__bridge__mlift_server_loop_10172_fun349__t* _self = kk_function_as(struct kk_src_rust__bridge__mlift_server_loop_10172_fun349__t*, _fself, _ctx);
  kk_string_t op_0 = _self->op_0; /* string */
  kk_src_rust__bridge__bridge_stats stats_1 = _self->stats_1; /* src/rust_bridge/bridge-stats */
  kk_drop_match(_self, {kk_string_dup(op_0, _ctx);kk_src_rust__bridge__bridge_stats_dup(stats_1, _ctx);}, {}, _ctx)
  kk_string_t _c_x10142_0_56 = kk_string_unbox(_b_x54); /*string*/;
  kk_unit_t _x_x350 = kk_Unit;
  kk_src_rust__bridge__mlift_server_loop_10171(op_0, stats_1, _c_x10142_0_56, _ctx);
  return kk_unit_box(_x_x350);
}

kk_unit_t kk_src_rust__bridge__mlift_server_loop_10172(kk_src_rust__bridge__bridge_stats stats_1, kk_string_t line, kk_context_t* _ctx) { /* (stats : bridge-stats, line : string) -> <console/console,exn> () */ 
  bool _match_x145;
  kk_string_t _x_x303 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x304 = kk_string_empty(); /*string*/
  _match_x145 = kk_string_is_eq(_x_x303,_x_x304,kk_context()); /*bool*/
  if (_match_x145) {
    kk_src_rust__bridge__bridge_stats_drop(stats_1, _ctx);
    kk_string_drop(line, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    bool _match_x146;
    kk_string_t _x_x306 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x307;
    kk_define_string_literal(, _s_x308, 6, "\"quit\"", _ctx)
    _x_x307 = kk_string_dup(_s_x308, _ctx); /*string*/
    _match_x146 = kk_string_contains(_x_x306,_x_x307,kk_context()); /*bool*/
    if (_match_x146) {
      kk_src_rust__bridge__bridge_stats_drop(stats_1, _ctx);
      kk_string_drop(line, _ctx);
      kk_string_t _x_x309;
      kk_define_string_literal(, _s_x310, 20, "{\"status\":\"stopped\"}", _ctx)
      _x_x309 = kk_string_dup(_s_x310, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x309, _ctx); return kk_Unit;
    }
    {
      kk_string_t op_0;
      kk_box_t _x_x311;
      kk_box_t _x_x315;
      kk_string_t _x_x316 = kk_string_dup(line, _ctx); /*string*/
      _x_x315 = kk_string_box(_x_x316); /*10000*/
      _x_x311 = kk_std_core_hnd__open_none1(kk_src_rust__bridge__new_mlift_server_loop_10172_fun312(_ctx), _x_x315, _ctx); /*10001*/
      op_0 = kk_string_unbox(_x_x311); /*string*/
      kk_string_t x_0_10177;
      if (kk_string_cmp_cstr_borrow(op_0, "cosine", _ctx) == 0) {
        kk_std_core_types__tuple2 _match_x148;
        kk_box_t _x_x318 = kk_std_core_hnd__open_none1(kk_src_rust__bridge__new_mlift_server_loop_10172_fun319(_ctx), kk_string_box(line), _ctx); /*10001*/
        _match_x148 = kk_std_core_types__tuple2_unbox(_x_x318, KK_OWNED, _ctx); /*(list<float64>, list<float64>)*/
        {
          kk_box_t _box_x44 = _match_x148.fst;
          kk_box_t _box_x45 = _match_x148.snd;
          kk_std_core_types__tuple2_drop(_match_x148, _ctx);
          kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_string_t x_1 = kk_std_num_float64_show(0x1.b333333333333p-1, kk_std_core_types__new_None(_ctx), _ctx); /*string*/;
          kk_unit_t keep_0 = kk_Unit;
          kk_evv_set(w_0,kk_context());
          kk_string_t _x_x322;
          kk_define_string_literal(, _s_x323, 14, "{\"cosine_sim\":", _ctx)
          _x_x322 = kk_string_dup(_s_x323, _ctx); /*string*/
          kk_string_t _x_x324;
          kk_string_t _x_x325;
          kk_define_string_literal(, _s_x326, 25, ",\"rust_accelerated\":true}", _ctx)
          _x_x325 = kk_string_dup(_s_x326, _ctx); /*string*/
          _x_x324 = kk_std_core_types__lp__plus__plus__rp_(x_1, _x_x325, _ctx); /*string*/
          x_0_10177 = kk_std_core_types__lp__plus__plus__rp_(_x_x322, _x_x324, _ctx); /*string*/
          goto _match_x317;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_0, "serialize", _ctx) == 0) {
        kk_string_drop(line, _ctx);
        kk_string_t _x_x327;
        kk_define_string_literal(, _s_x328, 27, "{\"serialized\":true,\"data\":\"", _ctx)
        _x_x327 = kk_string_dup(_s_x328, _ctx); /*string*/
        kk_string_t _x_x329;
        kk_string_t _x_x330;
        kk_define_string_literal(, _s_x331, 11, "test_object", _ctx)
        _x_x330 = kk_string_dup(_s_x331, _ctx); /*string*/
        kk_string_t _x_x332;
        kk_define_string_literal(, _s_x333, 2, "\"}", _ctx)
        _x_x332 = kk_string_dup(_s_x333, _ctx); /*string*/
        _x_x329 = kk_std_core_types__lp__plus__plus__rp_(_x_x330, _x_x332, _ctx); /*string*/
        x_0_10177 = kk_std_core_types__lp__plus__plus__rp_(_x_x327, _x_x329, _ctx); /*string*/
        goto _match_x317;
      }
      if (kk_string_cmp_cstr_borrow(op_0, "embed", _ctx) == 0) {
        kk_string_drop(line, _ctx);
        kk_string_t _x_x334;
        kk_define_string_literal(, _s_x335, 20, "{\"embedding_scores\":", _ctx)
        _x_x334 = kk_string_dup(_s_x335, _ctx); /*string*/
        kk_string_t _x_x336;
        kk_string_t _x_x337 = kk_std_core_int_show(kk_integer_from_small(3), _ctx); /*string*/
        kk_string_t _x_x338;
        kk_define_string_literal(, _s_x339, 25, ",\"rust_accelerated\":true}", _ctx)
        _x_x338 = kk_string_dup(_s_x339, _ctx); /*string*/
        _x_x336 = kk_std_core_types__lp__plus__plus__rp_(_x_x337, _x_x338, _ctx); /*string*/
        x_0_10177 = kk_std_core_types__lp__plus__plus__rp_(_x_x334, _x_x336, _ctx); /*string*/
        goto _match_x317;
      }
      if (kk_string_cmp_cstr_borrow(op_0, "batch", _ctx) == 0) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x340, 43, "{\"batch_results\":2,\"rust_accelerated\":true}", _ctx)
        x_0_10177 = kk_string_dup(_s_x340, _ctx); /*string*/
        goto _match_x317;
      }
      if (kk_string_cmp_cstr_borrow(op_0, "stats", _ctx) == 0) {
        kk_string_drop(line, _ctx);
        kk_box_t _x_x341;
        kk_box_t _x_x345;
        kk_src_rust__bridge__bridge_stats _x_x346 = kk_src_rust__bridge__bridge_stats_dup(stats_1, _ctx); /*src/rust_bridge/bridge-stats*/
        _x_x345 = kk_src_rust__bridge__bridge_stats_box(_x_x346, _ctx); /*10000*/
        _x_x341 = kk_std_core_hnd__open_none1(kk_src_rust__bridge__new_mlift_server_loop_10172_fun342(_ctx), _x_x345, _ctx); /*10001*/
        x_0_10177 = kk_string_unbox(_x_x341); /*string*/
        goto _match_x317;
      }
      {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x347, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_0_10177 = kk_string_dup(_s_x347, _ctx); /*string*/
      }
      _match_x317: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_0_10177, _ctx);
        kk_box_t _x_x348 = kk_std_core_hnd_yield_extend(kk_src_rust__bridge__new_mlift_server_loop_10172_fun349(op_0, stats_1, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x348); return kk_Unit;
      }
      {
        kk_src_rust__bridge__mlift_server_loop_10171(op_0, stats_1, x_0_10177, _ctx); return kk_Unit;
      }
    }
  }
}


// lift anonymous function
struct kk_src_rust__bridge_server_loop_fun352__t {
  struct kk_function_s _base;
  kk_src_rust__bridge__bridge_stats stats_2;
};
static kk_box_t kk_src_rust__bridge_server_loop_fun352(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx);
static kk_function_t kk_src_rust__bridge_new_server_loop_fun352(kk_src_rust__bridge__bridge_stats stats_2, kk_context_t* _ctx) {
  struct kk_src_rust__bridge_server_loop_fun352__t* _self = kk_function_alloc_as(struct kk_src_rust__bridge_server_loop_fun352__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_rust__bridge_server_loop_fun352, kk_context());
  _self->stats_2 = stats_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_rust__bridge_server_loop_fun352(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx) {
  struct kk_src_rust__bridge_server_loop_fun352__t* _self = kk_function_as(struct kk_src_rust__bridge_server_loop_fun352__t*, _fself, _ctx);
  kk_src_rust__bridge__bridge_stats stats_2 = _self->stats_2; /* src/rust_bridge/bridge-stats */
  kk_drop_match(_self, {kk_src_rust__bridge__bridge_stats_dup(stats_2, _ctx);}, {}, _ctx)
  kk_string_t line_0_80 = kk_string_unbox(_b_x58); /*string*/;
  kk_unit_t _x_x353 = kk_Unit;
  kk_src_rust__bridge__mlift_server_loop_10172(stats_2, line_0_80, _ctx);
  return kk_unit_box(_x_x353);
}


// lift anonymous function
struct kk_src_rust__bridge_server_loop_fun363__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_rust__bridge_server_loop_fun363(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx);
static kk_function_t kk_src_rust__bridge_new_server_loop_fun363(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_rust__bridge_server_loop_fun363, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_rust__bridge_server_loop_fun363(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x364;
  kk_string_t _x_x365 = kk_string_unbox(_b_x61); /*string*/
  _x_x364 = kk_src_rust__bridge_extract_op(_x_x365, _ctx); /*string*/
  return kk_string_box(_x_x364);
}


// lift anonymous function
struct kk_src_rust__bridge_server_loop_fun370__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_rust__bridge_server_loop_fun370(kk_function_t _fself, kk_box_t _b_x66, kk_context_t* _ctx);
static kk_function_t kk_src_rust__bridge_new_server_loop_fun370(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_rust__bridge_server_loop_fun370, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_rust__bridge_server_loop_fun370(kk_function_t _fself, kk_box_t _b_x66, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x371;
  kk_string_t _x_x372 = kk_string_unbox(_b_x66); /*string*/
  _x_x371 = kk_src_rust__bridge_extract_vectors(_x_x372, _ctx); /*(list<float64>, list<float64>)*/
  return kk_std_core_types__tuple2_box(_x_x371, _ctx);
}


// lift anonymous function
struct kk_src_rust__bridge_server_loop_fun393__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_rust__bridge_server_loop_fun393(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx);
static kk_function_t kk_src_rust__bridge_new_server_loop_fun393(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_rust__bridge_server_loop_fun393, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_rust__bridge_server_loop_fun393(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x394;
  kk_src_rust__bridge__bridge_stats _x_x395 = kk_src_rust__bridge__bridge_stats_unbox(_b_x71, KK_OWNED, _ctx); /*src/rust_bridge/bridge-stats*/
  _x_x394 = kk_src_rust__bridge_json_stats(_x_x395, _ctx); /*string*/
  return kk_string_box(_x_x394);
}


// lift anonymous function
struct kk_src_rust__bridge_server_loop_fun400__t {
  struct kk_function_s _base;
  kk_string_t op_1;
  kk_src_rust__bridge__bridge_stats stats_2;
};
static kk_box_t kk_src_rust__bridge_server_loop_fun400(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx);
static kk_function_t kk_src_rust__bridge_new_server_loop_fun400(kk_string_t op_1, kk_src_rust__bridge__bridge_stats stats_2, kk_context_t* _ctx) {
  struct kk_src_rust__bridge_server_loop_fun400__t* _self = kk_function_alloc_as(struct kk_src_rust__bridge_server_loop_fun400__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_rust__bridge_server_loop_fun400, kk_context());
  _self->op_1 = op_1;
  _self->stats_2 = stats_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_rust__bridge_server_loop_fun400(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx) {
  struct kk_src_rust__bridge_server_loop_fun400__t* _self = kk_function_as(struct kk_src_rust__bridge_server_loop_fun400__t*, _fself, _ctx);
  kk_string_t op_1 = _self->op_1; /* string */
  kk_src_rust__bridge__bridge_stats stats_2 = _self->stats_2; /* src/rust_bridge/bridge-stats */
  kk_drop_match(_self, {kk_string_dup(op_1, _ctx);kk_src_rust__bridge__bridge_stats_dup(stats_2, _ctx);}, {}, _ctx)
  kk_string_t _c_x10142_1_81 = kk_string_unbox(_b_x77); /*string*/;
  kk_unit_t _x_x401 = kk_Unit;
  kk_src_rust__bridge__mlift_server_loop_10171(op_1, stats_2, _c_x10142_1_81, _ctx);
  return kk_unit_box(_x_x401);
}

kk_unit_t kk_src_rust__bridge_server_loop(kk_src_rust__bridge__bridge_stats stats_2, kk_context_t* _ctx) { /* (stats : bridge-stats) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_2_10182 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2_10182, _ctx);
    kk_box_t _x_x351 = kk_std_core_hnd_yield_extend(kk_src_rust__bridge_new_server_loop_fun352(stats_2, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x351); return kk_Unit;
  }
  {
    bool _match_x141;
    kk_string_t _x_x354 = kk_string_dup(x_2_10182, _ctx); /*string*/
    kk_string_t _x_x355 = kk_string_empty(); /*string*/
    _match_x141 = kk_string_is_eq(_x_x354,_x_x355,kk_context()); /*bool*/
    if (_match_x141) {
      kk_string_drop(x_2_10182, _ctx);
      kk_src_rust__bridge__bridge_stats_drop(stats_2, _ctx);
      kk_Unit; return kk_Unit;
    }
    {
      bool _match_x142;
      kk_string_t _x_x357 = kk_string_dup(x_2_10182, _ctx); /*string*/
      kk_string_t _x_x358;
      kk_define_string_literal(, _s_x359, 6, "\"quit\"", _ctx)
      _x_x358 = kk_string_dup(_s_x359, _ctx); /*string*/
      _match_x142 = kk_string_contains(_x_x357,_x_x358,kk_context()); /*bool*/
      if (_match_x142) {
        kk_string_drop(x_2_10182, _ctx);
        kk_src_rust__bridge__bridge_stats_drop(stats_2, _ctx);
        kk_string_t _x_x360;
        kk_define_string_literal(, _s_x361, 20, "{\"status\":\"stopped\"}", _ctx)
        _x_x360 = kk_string_dup(_s_x361, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x360, _ctx); return kk_Unit;
      }
      {
        kk_string_t op_1;
        kk_box_t _x_x362;
        kk_box_t _x_x366;
        kk_string_t _x_x367 = kk_string_dup(x_2_10182, _ctx); /*string*/
        _x_x366 = kk_string_box(_x_x367); /*10000*/
        _x_x362 = kk_std_core_hnd__open_none1(kk_src_rust__bridge_new_server_loop_fun363(_ctx), _x_x366, _ctx); /*10001*/
        op_1 = kk_string_unbox(_x_x362); /*string*/
        kk_string_t x_3_10185;
        if (kk_string_cmp_cstr_borrow(op_1, "cosine", _ctx) == 0) {
          kk_std_core_types__tuple2 _match_x144;
          kk_box_t _x_x369 = kk_std_core_hnd__open_none1(kk_src_rust__bridge_new_server_loop_fun370(_ctx), kk_string_box(x_2_10182), _ctx); /*10001*/
          _match_x144 = kk_std_core_types__tuple2_unbox(_x_x369, KK_OWNED, _ctx); /*(list<float64>, list<float64>)*/
          {
            kk_box_t _box_x67 = _match_x144.fst;
            kk_box_t _box_x68 = _match_x144.snd;
            kk_std_core_types__tuple2_drop(_match_x144, _ctx);
            kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_string_t x_4 = kk_std_num_float64_show(0x1.b333333333333p-1, kk_std_core_types__new_None(_ctx), _ctx); /*string*/;
            kk_unit_t keep_1 = kk_Unit;
            kk_evv_set(w_1,kk_context());
            kk_string_t _x_x373;
            kk_define_string_literal(, _s_x374, 14, "{\"cosine_sim\":", _ctx)
            _x_x373 = kk_string_dup(_s_x374, _ctx); /*string*/
            kk_string_t _x_x375;
            kk_string_t _x_x376;
            kk_define_string_literal(, _s_x377, 25, ",\"rust_accelerated\":true}", _ctx)
            _x_x376 = kk_string_dup(_s_x377, _ctx); /*string*/
            _x_x375 = kk_std_core_types__lp__plus__plus__rp_(x_4, _x_x376, _ctx); /*string*/
            x_3_10185 = kk_std_core_types__lp__plus__plus__rp_(_x_x373, _x_x375, _ctx); /*string*/
            goto _match_x368;
          }
        }
        if (kk_string_cmp_cstr_borrow(op_1, "serialize", _ctx) == 0) {
          kk_string_drop(x_2_10182, _ctx);
          kk_string_t _x_x378;
          kk_define_string_literal(, _s_x379, 27, "{\"serialized\":true,\"data\":\"", _ctx)
          _x_x378 = kk_string_dup(_s_x379, _ctx); /*string*/
          kk_string_t _x_x380;
          kk_string_t _x_x381;
          kk_define_string_literal(, _s_x382, 11, "test_object", _ctx)
          _x_x381 = kk_string_dup(_s_x382, _ctx); /*string*/
          kk_string_t _x_x383;
          kk_define_string_literal(, _s_x384, 2, "\"}", _ctx)
          _x_x383 = kk_string_dup(_s_x384, _ctx); /*string*/
          _x_x380 = kk_std_core_types__lp__plus__plus__rp_(_x_x381, _x_x383, _ctx); /*string*/
          x_3_10185 = kk_std_core_types__lp__plus__plus__rp_(_x_x378, _x_x380, _ctx); /*string*/
          goto _match_x368;
        }
        if (kk_string_cmp_cstr_borrow(op_1, "embed", _ctx) == 0) {
          kk_string_drop(x_2_10182, _ctx);
          kk_string_t _x_x385;
          kk_define_string_literal(, _s_x386, 20, "{\"embedding_scores\":", _ctx)
          _x_x385 = kk_string_dup(_s_x386, _ctx); /*string*/
          kk_string_t _x_x387;
          kk_string_t _x_x388 = kk_std_core_int_show(kk_integer_from_small(3), _ctx); /*string*/
          kk_string_t _x_x389;
          kk_define_string_literal(, _s_x390, 25, ",\"rust_accelerated\":true}", _ctx)
          _x_x389 = kk_string_dup(_s_x390, _ctx); /*string*/
          _x_x387 = kk_std_core_types__lp__plus__plus__rp_(_x_x388, _x_x389, _ctx); /*string*/
          x_3_10185 = kk_std_core_types__lp__plus__plus__rp_(_x_x385, _x_x387, _ctx); /*string*/
          goto _match_x368;
        }
        if (kk_string_cmp_cstr_borrow(op_1, "batch", _ctx) == 0) {
          kk_string_drop(x_2_10182, _ctx);
          kk_define_string_literal(, _s_x391, 43, "{\"batch_results\":2,\"rust_accelerated\":true}", _ctx)
          x_3_10185 = kk_string_dup(_s_x391, _ctx); /*string*/
          goto _match_x368;
        }
        if (kk_string_cmp_cstr_borrow(op_1, "stats", _ctx) == 0) {
          kk_string_drop(x_2_10182, _ctx);
          kk_box_t _x_x392;
          kk_box_t _x_x396;
          kk_src_rust__bridge__bridge_stats _x_x397 = kk_src_rust__bridge__bridge_stats_dup(stats_2, _ctx); /*src/rust_bridge/bridge-stats*/
          _x_x396 = kk_src_rust__bridge__bridge_stats_box(_x_x397, _ctx); /*10000*/
          _x_x392 = kk_std_core_hnd__open_none1(kk_src_rust__bridge_new_server_loop_fun393(_ctx), _x_x396, _ctx); /*10001*/
          x_3_10185 = kk_string_unbox(_x_x392); /*string*/
          goto _match_x368;
        }
        {
          kk_string_drop(x_2_10182, _ctx);
          kk_define_string_literal(, _s_x398, 22, "{\"error\":\"unknown op\"}", _ctx)
          x_3_10185 = kk_string_dup(_s_x398, _ctx); /*string*/
        }
        _match_x368: ;
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_3_10185, _ctx);
          kk_box_t _x_x399 = kk_std_core_hnd_yield_extend(kk_src_rust__bridge_new_server_loop_fun400(op_1, stats_2, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x399); return kk_Unit;
        }
        {
          kk_unit_t ___0 = kk_Unit;
          kk_std_core_console_printsln(x_3_10185, _ctx);
          bool _x_x3_10167_0;
          kk_string_t _x_x402;
          kk_define_string_literal(, _s_x403, 6, "cosine", _ctx)
          _x_x402 = kk_string_dup(_s_x403, _ctx); /*string*/
          _x_x3_10167_0 = kk_string_is_eq(op_1,_x_x402,kk_context()); /*bool*/
          kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_src_rust__bridge__bridge_stats x_5;
          int64_t _x_x404;
          int64_t _x_x405;
          {
            struct kk_src_rust__bridge_Bridge_stats* _con_x406 = kk_src_rust__bridge__as_Bridge_stats(stats_2, _ctx);
            int64_t _x_5 = _con_x406->calls_made;
            _x_x405 = _x_5; /*int64*/
          }
          int64_t _x_x407 = (KK_I64(1)); /*int64*/
          _x_x404 = (int64_t)((uint64_t)_x_x405 + (uint64_t)_x_x407); /*int64*/
          double _x_x408;
          double _x_x409;
          {
            struct kk_src_rust__bridge_Bridge_stats* _con_x410 = kk_src_rust__bridge__as_Bridge_stats(stats_2, _ctx);
            double _x_0_0 = _con_x410->total_time_ms;
            _x_x409 = _x_0_0; /*float64*/
          }
          _x_x408 = (_x_x409 + (0x1.999999999999ap-4)); /*float64*/
          int64_t _x_x411;
          if (_x_x3_10167_0) {
            int64_t _x_x412;
            {
              struct kk_src_rust__bridge_Bridge_stats* _con_x413 = kk_src_rust__bridge__as_Bridge_stats(stats_2, _ctx);
              int64_t _x_1_0 = _con_x413->cache_hits;
              _x_x412 = _x_1_0; /*int64*/
            }
            int64_t _x_x414 = (KK_I64(1)); /*int64*/
            _x_x411 = (int64_t)((uint64_t)_x_x412 + (uint64_t)_x_x414); /*int64*/
          }
          else {
            struct kk_src_rust__bridge_Bridge_stats* _con_x415 = kk_src_rust__bridge__as_Bridge_stats(stats_2, _ctx);
            int64_t _x_2_0 = _con_x415->cache_hits;
            _x_x411 = _x_2_0; /*int64*/
          }
          int64_t _x_x416;
          if (_x_x3_10167_0) {
            struct kk_src_rust__bridge_Bridge_stats* _con_x417 = kk_src_rust__bridge__as_Bridge_stats(stats_2, _ctx);
            int64_t _x_3_0 = _con_x417->cache_misses;
            if kk_likely(kk_datatype_ptr_is_unique(stats_2, _ctx)) {
              kk_datatype_ptr_free(stats_2, _ctx);
            }
            else {
              kk_datatype_ptr_decref(stats_2, _ctx);
            }
            _x_x416 = _x_3_0; /*int64*/
          }
          else {
            int64_t _x_x418;
            {
              struct kk_src_rust__bridge_Bridge_stats* _con_x419 = kk_src_rust__bridge__as_Bridge_stats(stats_2, _ctx);
              int64_t _x_4_0 = _con_x419->cache_misses;
              if kk_likely(kk_datatype_ptr_is_unique(stats_2, _ctx)) {
                kk_datatype_ptr_free(stats_2, _ctx);
              }
              else {
                kk_datatype_ptr_decref(stats_2, _ctx);
              }
              _x_x418 = _x_4_0; /*int64*/
            }
            int64_t _x_x420 = (KK_I64(1)); /*int64*/
            _x_x416 = (int64_t)((uint64_t)_x_x418 + (uint64_t)_x_x420); /*int64*/
          }
          x_5 = kk_src_rust__bridge__new_Bridge_stats(kk_reuse_null, 0, _x_x404, _x_x408, _x_x411, _x_x416, _ctx); /*src/rust_bridge/bridge-stats*/
          kk_unit_t keep_2 = kk_Unit;
          kk_evv_set(w_2,kk_context());
          { // tailcall
            stats_2 = x_5;
            goto kk__tailcall;
          }
        }
      }
    }
  }
}

kk_src_rust__bridge__rust_function kk_src_rust__bridge_rust_function_fs__copy(kk_src_rust__bridge__rust_function _this, kk_std_core_types__optional name, kk_std_core_types__optional arg_types, kk_std_core_types__optional return_type, kk_std_core_types__optional hot_path, kk_context_t* _ctx) { /* (rust-function, name : ? string, arg-types : ? (list<string>), return-type : ? string, hot-path : ? bool) -> rust-function */ 
  kk_string_t _x_x425;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x82 = name._cons._Optional.value;
    kk_string_t _uniq_name_1295 = kk_string_unbox(_box_x82);
    kk_string_dup(_uniq_name_1295, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x425 = _uniq_name_1295; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_src_rust__bridge_Rust_function* _con_x426 = kk_src_rust__bridge__as_Rust_function(_this, _ctx);
      kk_string_t _x = _con_x426->name;
      kk_string_dup(_x, _ctx);
      _x_x425 = _x; /*string*/
    }
  }
  kk_std_core_types__list _x_x427;
  if (kk_std_core_types__is_Optional(arg_types, _ctx)) {
    kk_box_t _box_x83 = arg_types._cons._Optional.value;
    kk_std_core_types__list _uniq_arg_types_1303 = kk_std_core_types__list_unbox(_box_x83, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_arg_types_1303, _ctx);
    kk_std_core_types__optional_drop(arg_types, _ctx);
    _x_x427 = _uniq_arg_types_1303; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(arg_types, _ctx);
    {
      struct kk_src_rust__bridge_Rust_function* _con_x428 = kk_src_rust__bridge__as_Rust_function(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x428->arg_types;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x427 = _x_0; /*list<string>*/
    }
  }
  kk_string_t _x_x429;
  if (kk_std_core_types__is_Optional(return_type, _ctx)) {
    kk_box_t _box_x84 = return_type._cons._Optional.value;
    kk_string_t _uniq_return_type_1311 = kk_string_unbox(_box_x84);
    kk_string_dup(_uniq_return_type_1311, _ctx);
    kk_std_core_types__optional_drop(return_type, _ctx);
    _x_x429 = _uniq_return_type_1311; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(return_type, _ctx);
    {
      struct kk_src_rust__bridge_Rust_function* _con_x430 = kk_src_rust__bridge__as_Rust_function(_this, _ctx);
      kk_string_t _x_1 = _con_x430->return_type;
      kk_string_dup(_x_1, _ctx);
      _x_x429 = _x_1; /*string*/
    }
  }
  bool _x_x431;
  if (kk_std_core_types__is_Optional(hot_path, _ctx)) {
    kk_box_t _box_x85 = hot_path._cons._Optional.value;
    bool _uniq_hot_path_1319 = kk_bool_unbox(_box_x85);
    kk_std_core_types__optional_drop(hot_path, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x431 = _uniq_hot_path_1319; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(hot_path, _ctx);
    {
      struct kk_src_rust__bridge_Rust_function* _con_x432 = kk_src_rust__bridge__as_Rust_function(_this, _ctx);
      kk_string_t _pat_0_3 = _con_x432->name;
      kk_std_core_types__list _pat_1_4 = _con_x432->arg_types;
      kk_string_t _pat_2_3 = _con_x432->return_type;
      bool _x_2 = _con_x432->hot_path;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_2_3, _ctx);
        kk_std_core_types__list_drop(_pat_1_4, _ctx);
        kk_string_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x431 = _x_2; /*bool*/
    }
  }
  return kk_src_rust__bridge__new_Rust_function(kk_reuse_null, 0, _x_x425, _x_x427, _x_x429, _x_x431, _ctx);
}

kk_std_core_types__list kk_src_rust__bridge_rust_registry;
 
// lifted local: json-registry, list-functions

kk_string_t kk_src_rust__bridge__unroll_lift_json_registry_1913_10000(kk_std_core_types__list fns, kk_string_t acc, kk_context_t* _ctx) { /* (fns : list<rust-function>, acc : string) -> string */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(fns, _ctx)) {
    return acc;
  }
  {
    struct kk_std_core_types_Cons* _con_x486 = kk_std_core_types__as_Cons(fns, _ctx);
    kk_box_t _box_x138 = _con_x486->head;
    kk_src_rust__bridge__rust_function f = kk_src_rust__bridge__rust_function_unbox(_box_x138, KK_BORROWED, _ctx);
    struct kk_src_rust__bridge_Rust_function* _con_x487 = kk_src_rust__bridge__as_Rust_function(f, _ctx);
    kk_std_core_types__list rest = _con_x486->tail;
    if kk_likely(kk_datatype_ptr_is_unique(fns, _ctx)) {
      kk_datatype_ptr_free(fns, _ctx);
    }
    else {
      kk_src_rust__bridge__rust_function_dup(f, _ctx);
      kk_std_core_types__list_dup(rest, _ctx);
      kk_datatype_ptr_decref(fns, _ctx);
    }
    kk_string_t entry;
    kk_string_t _x_x488;
    kk_define_string_literal(, _s_x489, 9, "{\"name\":\"", _ctx)
    _x_x488 = kk_string_dup(_s_x489, _ctx); /*string*/
    kk_string_t _x_x490;
    kk_string_t _x_x491;
    {
      struct kk_src_rust__bridge_Rust_function* _con_x492 = kk_src_rust__bridge__as_Rust_function(f, _ctx);
      kk_string_t _x = _con_x492->name;
      kk_string_dup(_x, _ctx);
      _x_x491 = _x; /*string*/
    }
    kk_string_t _x_x493;
    kk_string_t _x_x494;
    kk_define_string_literal(, _s_x495, 8, "\",\"hot\":", _ctx)
    _x_x494 = kk_string_dup(_s_x495, _ctx); /*string*/
    kk_string_t _x_x496;
    kk_string_t _x_x497;
    {
      struct kk_src_rust__bridge_Rust_function* _con_x498 = kk_src_rust__bridge__as_Rust_function(f, _ctx);
      kk_string_t _pat_0_1 = _con_x498->name;
      kk_std_core_types__list _pat_1_1 = _con_x498->arg_types;
      kk_string_t _pat_2_1 = _con_x498->return_type;
      bool _x_0 = _con_x498->hot_path;
      if kk_likely(kk_datatype_ptr_is_unique(f, _ctx)) {
        kk_string_drop(_pat_2_1, _ctx);
        kk_std_core_types__list_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(f, _ctx);
      }
      else {
        kk_datatype_ptr_decref(f, _ctx);
      }
      if (_x_0) {
        kk_define_string_literal(, _s_x499, 4, "true", _ctx)
        _x_x497 = kk_string_dup(_s_x499, _ctx); /*string*/
      }
      else {
        kk_define_string_literal(, _s_x500, 5, "false", _ctx)
        _x_x497 = kk_string_dup(_s_x500, _ctx); /*string*/
      }
    }
    kk_string_t _x_x501;
    kk_define_string_literal(, _s_x502, 1, "}", _ctx)
    _x_x501 = kk_string_dup(_s_x502, _ctx); /*string*/
    _x_x496 = kk_std_core_types__lp__plus__plus__rp_(_x_x497, _x_x501, _ctx); /*string*/
    _x_x493 = kk_std_core_types__lp__plus__plus__rp_(_x_x494, _x_x496, _ctx); /*string*/
    _x_x490 = kk_std_core_types__lp__plus__plus__rp_(_x_x491, _x_x493, _ctx); /*string*/
    entry = kk_std_core_types__lp__plus__plus__rp_(_x_x488, _x_x490, _ctx); /*string*/
    kk_string_t sep;
    bool _match_x139;
    kk_string_t _x_x503 = kk_string_dup(acc, _ctx); /*string*/
    kk_string_t _x_x504 = kk_string_empty(); /*string*/
    _match_x139 = kk_string_is_eq(_x_x503,_x_x504,kk_context()); /*bool*/
    if (_match_x139) {
      sep = kk_string_empty(); /*string*/
    }
    else {
      kk_define_string_literal(, _s_x507, 1, ",", _ctx)
      sep = kk_string_dup(_s_x507, _ctx); /*string*/
    }
    { // tailcall
      kk_string_t _x_x508;
      kk_string_t _x_x509 = kk_std_core_types__lp__plus__plus__rp_(sep, entry, _ctx); /*string*/
      _x_x508 = kk_std_core_types__lp__plus__plus__rp_(acc, _x_x509, _ctx); /*string*/
      fns = rest;
      acc = _x_x508;
      goto kk__tailcall;
    }
  }
}

kk_string_t kk_src_rust__bridge_json_registry(kk_context_t* _ctx) { /* () -> string */ 
  kk_string_t _x_x510;
  kk_define_string_literal(, _s_x511, 19, "{\"rust_functions\":[", _ctx)
  _x_x510 = kk_string_dup(_s_x511, _ctx); /*string*/
  kk_string_t _x_x512;
  kk_string_t _x_x513;
  kk_std_core_types__list _x_x514 = kk_src_rust__bridge_rust_registry; /*list<src/rust_bridge/rust-function>*/
  if (kk_std_core_types__is_Nil(_x_x514, _ctx)) {
    _x_x513 = kk_string_empty(); /*string*/
  }
  else {
    kk_std_core_types__list _x_x516 = kk_std_core_types__list_dup(kk_src_rust__bridge_rust_registry, _ctx); /*list<src/rust_bridge/rust-function>*/
    kk_string_t _x_x517 = kk_string_empty(); /*string*/
    _x_x513 = kk_src_rust__bridge__unroll_lift_json_registry_1913_10000(_x_x516, _x_x517, _ctx); /*string*/
  }
  kk_string_t _x_x519;
  kk_string_t _x_x520;
  kk_define_string_literal(, _s_x521, 10, "],\"count\":", _ctx)
  _x_x520 = kk_string_dup(_s_x521, _ctx); /*string*/
  kk_string_t _x_x522;
  kk_string_t _x_x523;
  kk_integer_t _x_x524;
  kk_std_core_types__list _x_x525 = kk_src_rust__bridge_rust_registry; /*list<src/rust_bridge/rust-function>*/
  if (kk_std_core_types__is_Nil(_x_x525, _ctx)) {
    _x_x524 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_std_core_types__list _x_x526 = kk_std_core_types__list_dup(kk_src_rust__bridge_rust_registry, _ctx); /*list<src/rust_bridge/rust-function>*/
    _x_x524 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x526, kk_integer_from_small(0), _ctx); /*int*/
  }
  _x_x523 = kk_std_core_int_show(_x_x524, _ctx); /*string*/
  kk_string_t _x_x527;
  kk_define_string_literal(, _s_x528, 1, "}", _ctx)
  _x_x527 = kk_string_dup(_s_x528, _ctx); /*string*/
  _x_x522 = kk_std_core_types__lp__plus__plus__rp_(_x_x523, _x_x527, _ctx); /*string*/
  _x_x519 = kk_std_core_types__lp__plus__plus__rp_(_x_x520, _x_x522, _ctx); /*string*/
  _x_x512 = kk_std_core_types__lp__plus__plus__rp_(_x_x513, _x_x519, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x510, _x_x512, _ctx);
}

kk_unit_t kk_src_rust__bridge_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_string_t x;
  kk_string_t _x_x529;
  kk_define_string_literal(, _s_x530, 19, "{\"rust_functions\":[", _ctx)
  _x_x529 = kk_string_dup(_s_x530, _ctx); /*string*/
  kk_string_t _x_x531;
  kk_string_t _x_x532;
  kk_std_core_types__list _x_x533 = kk_src_rust__bridge_rust_registry; /*list<src/rust_bridge/rust-function>*/
  if (kk_std_core_types__is_Nil(_x_x533, _ctx)) {
    _x_x532 = kk_string_empty(); /*string*/
  }
  else {
    kk_std_core_types__list _x_x535 = kk_std_core_types__list_dup(kk_src_rust__bridge_rust_registry, _ctx); /*list<src/rust_bridge/rust-function>*/
    kk_string_t _x_x536 = kk_string_empty(); /*string*/
    _x_x532 = kk_src_rust__bridge__unroll_lift_json_registry_1913_10000(_x_x535, _x_x536, _ctx); /*string*/
  }
  kk_string_t _x_x538;
  kk_string_t _x_x539;
  kk_define_string_literal(, _s_x540, 10, "],\"count\":", _ctx)
  _x_x539 = kk_string_dup(_s_x540, _ctx); /*string*/
  kk_string_t _x_x541;
  kk_string_t _x_x542;
  kk_integer_t _x_x543;
  kk_std_core_types__list _x_x544 = kk_src_rust__bridge_rust_registry; /*list<src/rust_bridge/rust-function>*/
  if (kk_std_core_types__is_Nil(_x_x544, _ctx)) {
    _x_x543 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_std_core_types__list _x_x545 = kk_std_core_types__list_dup(kk_src_rust__bridge_rust_registry, _ctx); /*list<src/rust_bridge/rust-function>*/
    _x_x543 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x545, kk_integer_from_small(0), _ctx); /*int*/
  }
  _x_x542 = kk_std_core_int_show(_x_x543, _ctx); /*string*/
  kk_string_t _x_x546;
  kk_define_string_literal(, _s_x547, 1, "}", _ctx)
  _x_x546 = kk_string_dup(_s_x547, _ctx); /*string*/
  _x_x541 = kk_std_core_types__lp__plus__plus__rp_(_x_x542, _x_x546, _ctx); /*string*/
  _x_x538 = kk_std_core_types__lp__plus__plus__rp_(_x_x539, _x_x541, _ctx); /*string*/
  _x_x531 = kk_std_core_types__lp__plus__plus__rp_(_x_x532, _x_x538, _ctx); /*string*/
  x = kk_std_core_types__lp__plus__plus__rp_(_x_x529, _x_x531, _ctx); /*string*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x548;
  kk_string_t _x_x549;
  kk_define_string_literal(, _s_x550, 139, "{\"status\":\"started\",\"rust_bridge\":true,\"version\":\"6.0\",\"features\":[\"cosine_sim\",\"json_serialize\",\"batch_embed\",\"vector_search\"],\"registry\":", _ctx)
  _x_x549 = kk_string_dup(_s_x550, _ctx); /*string*/
  kk_string_t _x_x551;
  kk_string_t _x_x552;
  kk_define_string_literal(, _s_x553, 1, "}", _ctx)
  _x_x552 = kk_string_dup(_s_x553, _ctx); /*string*/
  _x_x551 = kk_std_core_types__lp__plus__plus__rp_(x, _x_x552, _ctx); /*string*/
  _x_x548 = kk_std_core_types__lp__plus__plus__rp_(_x_x549, _x_x551, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x548, _ctx);
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  int64_t x_0 = (KK_I64(0)); /*int64*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_evv_t w_0_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  int64_t x_0_0 = (KK_I64(0)); /*int64*/;
  kk_unit_t keep_0_0 = kk_Unit;
  kk_evv_set(w_0_0,kk_context());
  kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  int64_t x_1 = (KK_I64(0)); /*int64*/;
  kk_unit_t keep_1 = kk_Unit;
  kk_evv_set(w_1,kk_context());
  kk_src_rust__bridge__bridge_stats _x_x554 = kk_src_rust__bridge__new_Bridge_stats(kk_reuse_null, 0, x_0, 0x0p+0, x_0_0, x_1, _ctx); /*src/rust_bridge/bridge-stats*/
  kk_src_rust__bridge_server_loop(_x_x554, _ctx); return kk_Unit;
}

// initialization
void kk_src_rust__bridge__init(kk_context_t* _ctx){
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
  kk_std_os_readline__init(_ctx);
  kk_std_num_float64__init(_ctx);
  kk_std_num_int64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_box_t _x_x433;
    kk_string_t _b_x88_114;
    kk_define_string_literal(, _s_x434, 6, "vector", _ctx)
    _b_x88_114 = kk_string_dup(_s_x434, _ctx); /*string*/
    kk_std_core_types__list _b_x89_115;
    kk_box_t _x_x435;
    kk_string_t _x_x436;
    kk_define_string_literal(, _s_x437, 6, "vector", _ctx)
    _x_x436 = kk_string_dup(_s_x437, _ctx); /*string*/
    _x_x435 = kk_string_box(_x_x436); /*10021*/
    _b_x89_115 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x435, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/
    kk_src_rust__bridge__rust_function _x_x438;
    kk_string_t _x_x439;
    kk_define_string_literal(, _s_x440, 17, "cosine_similarity", _ctx)
    _x_x439 = kk_string_dup(_s_x440, _ctx); /*string*/
    kk_std_core_types__list _x_x441 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x88_114), _b_x89_115, _ctx); /*list<10021>*/
    kk_string_t _x_x442;
    kk_define_string_literal(, _s_x443, 7, "float64", _ctx)
    _x_x442 = kk_string_dup(_s_x443, _ctx); /*string*/
    _x_x438 = kk_src_rust__bridge__new_Rust_function(kk_reuse_null, 0, _x_x439, _x_x441, _x_x442, true, _ctx); /*src/rust_bridge/rust-function*/
    _x_x433 = kk_src_rust__bridge__rust_function_box(_x_x438, _ctx); /*10021*/
    kk_std_core_types__list _x_x444;
    kk_box_t _x_x445;
    kk_string_t _b_x90_120;
    kk_define_string_literal(, _s_x446, 6, "object", _ctx)
    _b_x90_120 = kk_string_dup(_s_x446, _ctx); /*string*/
    kk_std_core_types__list _b_x91_121 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/;
    kk_src_rust__bridge__rust_function _x_x447;
    kk_string_t _x_x448;
    kk_define_string_literal(, _s_x449, 14, "json_serialize", _ctx)
    _x_x448 = kk_string_dup(_s_x449, _ctx); /*string*/
    kk_std_core_types__list _x_x450 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x90_120), _b_x91_121, _ctx); /*list<10021>*/
    kk_string_t _x_x451;
    kk_define_string_literal(, _s_x452, 6, "string", _ctx)
    _x_x451 = kk_string_dup(_s_x452, _ctx); /*string*/
    _x_x447 = kk_src_rust__bridge__new_Rust_function(kk_reuse_null, 0, _x_x448, _x_x450, _x_x451, true, _ctx); /*src/rust_bridge/rust-function*/
    _x_x445 = kk_src_rust__bridge__rust_function_box(_x_x447, _ctx); /*10021*/
    kk_std_core_types__list _x_x453;
    kk_box_t _x_x454;
    kk_string_t _b_x92_124;
    kk_define_string_literal(, _s_x455, 9, "list<int>", _ctx)
    _b_x92_124 = kk_string_dup(_s_x455, _ctx); /*string*/
    kk_std_core_types__list _b_x93_125 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/;
    kk_src_rust__bridge__rust_function _x_x456;
    kk_string_t _x_x457;
    kk_define_string_literal(, _s_x458, 11, "batch_embed", _ctx)
    _x_x457 = kk_string_dup(_s_x458, _ctx); /*string*/
    kk_std_core_types__list _x_x459 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x92_124), _b_x93_125, _ctx); /*list<10021>*/
    kk_string_t _x_x460;
    kk_define_string_literal(, _s_x461, 13, "list<float64>", _ctx)
    _x_x460 = kk_string_dup(_s_x461, _ctx); /*string*/
    _x_x456 = kk_src_rust__bridge__new_Rust_function(kk_reuse_null, 0, _x_x457, _x_x459, _x_x460, true, _ctx); /*src/rust_bridge/rust-function*/
    _x_x454 = kk_src_rust__bridge__rust_function_box(_x_x456, _ctx); /*10021*/
    kk_std_core_types__list _x_x462;
    kk_box_t _x_x463;
    kk_string_t _b_x96_128;
    kk_define_string_literal(, _s_x464, 6, "vector", _ctx)
    _b_x96_128 = kk_string_dup(_s_x464, _ctx); /*string*/
    kk_std_core_types__list _b_x97_129;
    kk_box_t _x_x465;
    kk_string_t _x_x466;
    kk_define_string_literal(, _s_x467, 3, "int", _ctx)
    _x_x466 = kk_string_dup(_s_x467, _ctx); /*string*/
    _x_x465 = kk_string_box(_x_x466); /*10021*/
    _b_x97_129 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x465, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/
    kk_src_rust__bridge__rust_function _x_x468;
    kk_string_t _x_x469;
    kk_define_string_literal(, _s_x470, 13, "vector_search", _ctx)
    _x_x469 = kk_string_dup(_s_x470, _ctx); /*string*/
    kk_std_core_types__list _x_x471 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x96_128), _b_x97_129, _ctx); /*list<10021>*/
    kk_string_t _x_x472;
    kk_define_string_literal(, _s_x473, 9, "list<int>", _ctx)
    _x_x472 = kk_string_dup(_s_x473, _ctx); /*string*/
    _x_x468 = kk_src_rust__bridge__new_Rust_function(kk_reuse_null, 0, _x_x469, _x_x471, _x_x472, true, _ctx); /*src/rust_bridge/rust-function*/
    _x_x463 = kk_src_rust__bridge__rust_function_box(_x_x468, _ctx); /*10021*/
    kk_std_core_types__list _x_x474;
    kk_box_t _x_x475;
    kk_string_t _b_x100_134;
    kk_define_string_literal(, _s_x476, 6, "vector", _ctx)
    _b_x100_134 = kk_string_dup(_s_x476, _ctx); /*string*/
    kk_std_core_types__list _b_x101_135;
    kk_box_t _x_x477;
    kk_string_t _x_x478;
    kk_define_string_literal(, _s_x479, 6, "vector", _ctx)
    _x_x478 = kk_string_dup(_s_x479, _ctx); /*string*/
    _x_x477 = kk_string_box(_x_x478); /*10021*/
    _b_x101_135 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x477, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/
    kk_src_rust__bridge__rust_function _x_x480;
    kk_string_t _x_x481;
    kk_define_string_literal(, _s_x482, 13, "distance_calc", _ctx)
    _x_x481 = kk_string_dup(_s_x482, _ctx); /*string*/
    kk_std_core_types__list _x_x483 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x100_134), _b_x101_135, _ctx); /*list<10021>*/
    kk_string_t _x_x484;
    kk_define_string_literal(, _s_x485, 7, "float64", _ctx)
    _x_x484 = kk_string_dup(_s_x485, _ctx); /*string*/
    _x_x480 = kk_src_rust__bridge__new_Rust_function(kk_reuse_null, 0, _x_x481, _x_x483, _x_x484, true, _ctx); /*src/rust_bridge/rust-function*/
    _x_x475 = kk_src_rust__bridge__rust_function_box(_x_x480, _ctx); /*10021*/
    _x_x474 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x475, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x462 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x463, _x_x474, _ctx); /*list<10021>*/
    _x_x453 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x454, _x_x462, _ctx); /*list<10021>*/
    _x_x444 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x445, _x_x453, _ctx); /*list<10021>*/
    kk_src_rust__bridge_rust_registry = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x433, _x_x444, _ctx); /*list<src/rust_bridge/rust-function>*/
  }
}

// termination
void kk_src_rust__bridge__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_types__list_drop(kk_src_rust__bridge_rust_registry, _ctx);
  kk_std_num_int64__done(_ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_os_readline__done(_ctx);
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
