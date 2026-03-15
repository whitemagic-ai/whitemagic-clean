// Koka generated module: src/resonance, koka version: 3.2.2, platform: 64-bit
#include "src_resonance.h"

kk_std_core_types__list kk_src_resonance_gana_order;
 
// Find index of gana in order


// lift anonymous function
struct kk_src_resonance_gana_index_fun383__t {
  struct kk_function_s _base;
  kk_string_t name;
};
static kk_box_t kk_src_resonance_gana_index_fun383(kk_function_t _fself, kk_box_t _b_x123, kk_box_t _b_x124, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_gana_index_fun383(kk_string_t name, kk_context_t* _ctx) {
  struct kk_src_resonance_gana_index_fun383__t* _self = kk_function_alloc_as(struct kk_src_resonance_gana_index_fun383__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_resonance_gana_index_fun383, kk_context());
  _self->name = name;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_resonance_gana_index_fun383(kk_function_t _fself, kk_box_t _b_x123, kk_box_t _b_x124, kk_context_t* _ctx) {
  struct kk_src_resonance_gana_index_fun383__t* _self = kk_function_as(struct kk_src_resonance_gana_index_fun383__t*, _fself, _ctx);
  kk_string_t name = _self->name; /* string */
  kk_drop_match(_self, {kk_string_dup(name, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x384;
  kk_std_core_types__tuple2 _match_x264;
  kk_box_t _x_x385 = kk_box_dup(_b_x123, _ctx); /*10002*/
  _match_x264 = kk_std_core_types__tuple2_unbox(_x_x385, KK_OWNED, _ctx); /*(int, bool)*/
  {
    kk_box_t _box_x114 = _match_x264.fst;
    kk_box_t _box_x115 = _match_x264.snd;
    kk_integer_t idx = kk_integer_unbox(_box_x114, _ctx);
    bool found = kk_bool_unbox(_box_x115);
    kk_integer_dup(idx, _ctx);
    kk_std_core_types__tuple2_drop(_match_x264, _ctx);
    if (found) {
      kk_string_drop(name, _ctx);
      kk_integer_drop(idx, _ctx);
      kk_box_drop(_b_x124, _ctx);
      _x_x384 = kk_std_core_types__tuple2_unbox(_b_x123, KK_OWNED, _ctx); /*(int, bool)*/
    }
    else {
      kk_box_drop(_b_x123, _ctx);
      bool _match_x265;
      kk_string_t _x_x386 = kk_string_unbox(_b_x124); /*string*/
      _match_x265 = kk_string_is_eq(_x_x386,name,kk_context()); /*bool*/
      if (_match_x265) {
        _x_x384 = kk_std_core_types__new_Tuple2(kk_integer_box(idx, _ctx), kk_bool_box(true), _ctx); /*(int, bool)*/
      }
      else {
        kk_integer_t _b_x118_132 = kk_integer_add_small_const(idx, 1, _ctx); /*int*/;
        _x_x384 = kk_std_core_types__new_Tuple2(kk_integer_box(_b_x118_132, _ctx), kk_bool_box(false), _ctx); /*(int, bool)*/
      }
    }
  }
  return kk_std_core_types__tuple2_box(_x_x384, _ctx);
}

kk_integer_t kk_src_resonance_gana_index(kk_string_t name, kk_context_t* _ctx) { /* (name : string) -> int */ 
  kk_std_core_types__tuple2 result;
  kk_box_t _x_x379;
  kk_std_core_types__list _x_x380 = kk_std_core_types__list_dup(kk_src_resonance_gana_order, _ctx); /*list<string>*/
  kk_box_t _x_x381;
  kk_std_core_types__tuple2 _x_x382 = kk_std_core_types__new_Tuple2(kk_integer_box(kk_integer_from_small(0), _ctx), kk_bool_box(false), _ctx); /*(10037, 10038)*/
  _x_x381 = kk_std_core_types__tuple2_box(_x_x382, _ctx); /*10002*/
  _x_x379 = kk_std_core_list_foldl(_x_x380, _x_x381, kk_src_resonance_new_gana_index_fun383(name, _ctx), _ctx); /*10002*/
  result = kk_std_core_types__tuple2_unbox(_x_x379, KK_OWNED, _ctx); /*(int, bool)*/
  {
    kk_box_t _box_x136 = result.fst;
    kk_box_t _box_x137 = result.snd;
    bool _x = kk_bool_unbox(_box_x137);
    if (_x) {
      kk_box_t _box_x138 = result.fst;
      kk_box_t _box_x139 = result.snd;
      kk_integer_t _x_0 = kk_integer_unbox(_box_x138, _ctx);
      kk_integer_dup(_x_0, _ctx);
      kk_std_core_types__tuple2_drop(result, _ctx);
      return _x_0;
    }
    {
      kk_std_core_types__tuple2_drop(result, _ctx);
      return kk_integer_from_small(-1);
    }
  }
}
 
// Get element at index from list

kk_string_t kk_src_resonance_list_at(kk_std_core_types__list lst, kk_integer_t idx, kk_context_t* _ctx) { /* (lst : list<string>, idx : int) -> string */ 
  kk__tailcall: ;
  bool _match_x263 = kk_integer_lte_borrow(idx,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x263) {
    kk_integer_drop(idx, _ctx);
    if (kk_std_core_types__is_Nil(lst, _ctx)) {
      kk_define_string_literal(, _s_x387, 9, "gana_horn", _ctx)
      return kk_string_dup(_s_x387, _ctx);
    }
    {
      struct kk_std_core_types_Cons* _con_x388 = kk_std_core_types__as_Cons(lst, _ctx);
      kk_box_t _box_x140 = _con_x388->head;
      kk_std_core_types__list _pat_2 = _con_x388->tail;
      kk_string_t hd = kk_string_unbox(_box_x140);
      if kk_likely(kk_datatype_ptr_is_unique(lst, _ctx)) {
        kk_std_core_types__list_drop(_pat_2, _ctx);
        kk_datatype_ptr_free(lst, _ctx);
      }
      else {
        kk_string_dup(hd, _ctx);
        kk_datatype_ptr_decref(lst, _ctx);
      }
      return hd;
    }
  }
  if (kk_std_core_types__is_Nil(lst, _ctx)) {
    kk_integer_drop(idx, _ctx);
    kk_define_string_literal(, _s_x389, 9, "gana_horn", _ctx)
    return kk_string_dup(_s_x389, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x390 = kk_std_core_types__as_Cons(lst, _ctx);
    kk_box_t _box_x141 = _con_x390->head;
    kk_std_core_types__list tl = _con_x390->tail;
    kk_string_t _pat_6 = kk_string_unbox(_box_x141);
    if kk_likely(kk_datatype_ptr_is_unique(lst, _ctx)) {
      kk_string_drop(_pat_6, _ctx);
      kk_datatype_ptr_free(lst, _ctx);
    }
    else {
      kk_std_core_types__list_dup(tl, _ctx);
      kk_datatype_ptr_decref(lst, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x391 = kk_integer_add_small_const(idx, -1, _ctx); /*int*/
      lst = tl;
      idx = _x_x391;
      goto kk__tailcall;
    }
  }
}
 
// Get predecessor gana (circular)

kk_string_t kk_src_resonance_get_predecessor(kk_string_t gana_name, kk_context_t* _ctx) { /* (gana-name : string) -> string */ 
  kk_integer_t idx = kk_src_resonance_gana_index(gana_name, _ctx); /*int*/;
  bool _match_x262 = kk_integer_lt_borrow(idx,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x262) {
    kk_integer_drop(idx, _ctx);
    kk_define_string_literal(, _s_x392, 9, "gana_horn", _ctx)
    return kk_string_dup(_s_x392, _ctx);
  }
  {
    kk_std_core_types__list _x_x393 = kk_std_core_types__list_dup(kk_src_resonance_gana_order, _ctx); /*list<string>*/
    kk_integer_t _x_x394;
    kk_integer_t _x_x395 = kk_integer_add_small_const(idx, 27, _ctx); /*int*/
    _x_x394 = kk_integer_mod(_x_x395,(kk_integer_from_small(28)),kk_context()); /*int*/
    return kk_src_resonance_list_at(_x_x393, _x_x394, _ctx);
  }
}
 
// Get successor gana (circular)

kk_string_t kk_src_resonance_get_successor(kk_string_t gana_name, kk_context_t* _ctx) { /* (gana-name : string) -> string */ 
  kk_integer_t idx = kk_src_resonance_gana_index(gana_name, _ctx); /*int*/;
  bool _match_x261 = kk_integer_lt_borrow(idx,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x261) {
    kk_integer_drop(idx, _ctx);
    kk_define_string_literal(, _s_x396, 9, "gana_horn", _ctx)
    return kk_string_dup(_s_x396, _ctx);
  }
  {
    kk_std_core_types__list _x_x397 = kk_std_core_types__list_dup(kk_src_resonance_gana_order, _ctx); /*list<string>*/
    kk_integer_t _x_x398;
    kk_integer_t _x_x399 = kk_integer_add_small_const(idx, 1, _ctx); /*int*/
    _x_x398 = kk_integer_mod(_x_x399,(kk_integer_from_small(28)),kk_context()); /*int*/
    return kk_src_resonance_list_at(_x_x397, _x_x398, _ctx);
  }
}

kk_string_t kk_src_resonance_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x255;
  kk_string_t _x_x400 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x401 = kk_string_empty(); /*string*/
  _match_x255 = kk_string_is_eq(_x_x400,_x_x401,kk_context()); /*bool*/
  if (_match_x255) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x403, 7, "unknown", _ctx)
    return kk_string_dup(_s_x403, _ctx);
  }
  {
    bool _match_x256;
    kk_string_t _x_x404 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x405;
    kk_define_string_literal(, _s_x406, 13, "\"predecessor\"", _ctx)
    _x_x405 = kk_string_dup(_s_x406, _ctx); /*string*/
    _match_x256 = kk_string_contains(_x_x404,_x_x405,kk_context()); /*bool*/
    if (_match_x256) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x407, 11, "predecessor", _ctx)
      return kk_string_dup(_s_x407, _ctx);
    }
    {
      bool _match_x257;
      kk_string_t _x_x408 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x409;
      kk_define_string_literal(, _s_x410, 11, "\"successor\"", _ctx)
      _x_x409 = kk_string_dup(_s_x410, _ctx); /*string*/
      _match_x257 = kk_string_contains(_x_x408,_x_x409,kk_context()); /*bool*/
      if (_match_x257) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x411, 9, "successor", _ctx)
        return kk_string_dup(_s_x411, _ctx);
      }
      {
        bool _match_x258;
        kk_string_t _x_x412 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x413;
        kk_define_string_literal(, _s_x414, 8, "\"record\"", _ctx)
        _x_x413 = kk_string_dup(_s_x414, _ctx); /*string*/
        _match_x258 = kk_string_contains(_x_x412,_x_x413,kk_context()); /*bool*/
        if (_match_x258) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x415, 6, "record", _ctx)
          return kk_string_dup(_s_x415, _ctx);
        }
        {
          bool _match_x259;
          kk_string_t _x_x416 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x417;
          kk_define_string_literal(, _s_x418, 8, "\"status\"", _ctx)
          _x_x417 = kk_string_dup(_s_x418, _ctx); /*string*/
          _match_x259 = kk_string_contains(_x_x416,_x_x417,kk_context()); /*bool*/
          if (_match_x259) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x419, 6, "status", _ctx)
            return kk_string_dup(_s_x419, _ctx);
          }
          {
            bool _match_x260;
            kk_string_t _x_x420;
            kk_define_string_literal(, _s_x421, 7, "\"reset\"", _ctx)
            _x_x420 = kk_string_dup(_s_x421, _ctx); /*string*/
            _match_x260 = kk_string_contains(line,_x_x420,kk_context()); /*bool*/
            if (_match_x260) {
              kk_define_string_literal(, _s_x422, 5, "reset", _ctx)
              return kk_string_dup(_s_x422, _ctx);
            }
            {
              kk_define_string_literal(, _s_x423, 7, "unknown", _ctx)
              return kk_string_dup(_s_x423, _ctx);
            }
          }
        }
      }
    }
  }
}
 
// Extract gana name from JSON (simplified - just looks for gana_ pattern)

kk_string_t kk_src_resonance_extract_gana(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x249;
  kk_string_t _x_x424 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x425;
  kk_define_string_literal(, _s_x426, 9, "gana_horn", _ctx)
  _x_x425 = kk_string_dup(_s_x426, _ctx); /*string*/
  _match_x249 = kk_string_contains(_x_x424,_x_x425,kk_context()); /*bool*/
  if (_match_x249) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x427, 9, "gana_horn", _ctx)
    return kk_string_dup(_s_x427, _ctx);
  }
  {
    bool _match_x250;
    kk_string_t _x_x428 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x429;
    kk_define_string_literal(, _s_x430, 9, "gana_neck", _ctx)
    _x_x429 = kk_string_dup(_s_x430, _ctx); /*string*/
    _match_x250 = kk_string_contains(_x_x428,_x_x429,kk_context()); /*bool*/
    if (_match_x250) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x431, 9, "gana_neck", _ctx)
      return kk_string_dup(_s_x431, _ctx);
    }
    {
      bool _match_x251;
      kk_string_t _x_x432 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x433;
      kk_define_string_literal(, _s_x434, 10, "gana_ghost", _ctx)
      _x_x433 = kk_string_dup(_s_x434, _ctx); /*string*/
      _match_x251 = kk_string_contains(_x_x432,_x_x433,kk_context()); /*bool*/
      if (_match_x251) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x435, 10, "gana_ghost", _ctx)
        return kk_string_dup(_s_x435, _ctx);
      }
      {
        bool _match_x252;
        kk_string_t _x_x436 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x437;
        kk_define_string_literal(, _s_x438, 21, "gana_winnowing_basket", _ctx)
        _x_x437 = kk_string_dup(_s_x438, _ctx); /*string*/
        _match_x252 = kk_string_contains(_x_x436,_x_x437,kk_context()); /*bool*/
        if (_match_x252) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x439, 21, "gana_winnowing_basket", _ctx)
          return kk_string_dup(_s_x439, _ctx);
        }
        {
          bool _match_x253;
          kk_string_t _x_x440 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x441;
          kk_define_string_literal(, _s_x442, 9, "gana_void", _ctx)
          _x_x441 = kk_string_dup(_s_x442, _ctx); /*string*/
          _match_x253 = kk_string_contains(_x_x440,_x_x441,kk_context()); /*bool*/
          if (_match_x253) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x443, 9, "gana_void", _ctx)
            return kk_string_dup(_s_x443, _ctx);
          }
          {
            bool _match_x254;
            kk_string_t _x_x444;
            kk_define_string_literal(, _s_x445, 14, "gana_abundance", _ctx)
            _x_x444 = kk_string_dup(_s_x445, _ctx); /*string*/
            _match_x254 = kk_string_contains(line,_x_x444,kk_context()); /*bool*/
            if (_match_x254) {
              kk_define_string_literal(, _s_x446, 14, "gana_abundance", _ctx)
              return kk_string_dup(_s_x446, _ctx);
            }
            {
              kk_define_string_literal(, _s_x447, 9, "gana_horn", _ctx)
              return kk_string_dup(_s_x447, _ctx);
            }
          }
        }
      }
    }
  }
}

kk_unit_t kk_src_resonance_flush_stdout(kk_context_t* _ctx) { /* () -> console/console () */ 
  fflush(stdout); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_src_resonance__mlift_server_loop_10033_fun449__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_resonance__mlift_server_loop_10033_fun449(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_resonance__new_mlift_server_loop_10033_fun449(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance__mlift_server_loop_10033_fun449, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_resonance__mlift_server_loop_10033_fun449(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x450 = kk_Unit;
  kk_src_resonance_flush_stdout(_ctx);
  return kk_unit_box(_x_x450);
}

kk_unit_t kk_src_resonance__mlift_server_loop_10033(kk_string_t _c_x10011, double harmony, double lunar_phase, kk_string_t new_last_gana, kk_integer_t _c_x10012, kk_context_t* _ctx) { /* (string, harmony : float64, lunar-phase : float64, new-last-gana : string, int) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10011, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x448 = kk_std_core_hnd__open_none0(kk_src_resonance__new_mlift_server_loop_10033_fun449(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x448);
  kk_src_resonance_server_loop(new_last_gana, _c_x10012, lunar_phase, harmony, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_src_resonance__mlift_server_loop_10034_fun457__t {
  struct kk_function_s _base;
  kk_string_t _c_x10011_0;
  kk_string_t new_last_gana_0;
  double harmony_0;
  double lunar_phase_0;
};
static kk_box_t kk_src_resonance__mlift_server_loop_10034_fun457(kk_function_t _fself, kk_box_t _b_x145, kk_context_t* _ctx);
static kk_function_t kk_src_resonance__new_mlift_server_loop_10034_fun457(kk_string_t _c_x10011_0, kk_string_t new_last_gana_0, double harmony_0, double lunar_phase_0, kk_context_t* _ctx) {
  struct kk_src_resonance__mlift_server_loop_10034_fun457__t* _self = kk_function_alloc_as(struct kk_src_resonance__mlift_server_loop_10034_fun457__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_resonance__mlift_server_loop_10034_fun457, kk_context());
  _self->_c_x10011_0 = _c_x10011_0;
  _self->new_last_gana_0 = new_last_gana_0;
  _self->harmony_0 = harmony_0;
  _self->lunar_phase_0 = lunar_phase_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_resonance__mlift_server_loop_10034_fun457(kk_function_t _fself, kk_box_t _b_x145, kk_context_t* _ctx) {
  struct kk_src_resonance__mlift_server_loop_10034_fun457__t* _self = kk_function_as(struct kk_src_resonance__mlift_server_loop_10034_fun457__t*, _fself, _ctx);
  kk_string_t _c_x10011_0 = _self->_c_x10011_0; /* string */
  kk_string_t new_last_gana_0 = _self->new_last_gana_0; /* string */
  double harmony_0 = _self->harmony_0; /* float64 */
  double lunar_phase_0 = _self->lunar_phase_0; /* float64 */
  kk_drop_match(_self, {kk_string_dup(_c_x10011_0, _ctx);kk_string_dup(new_last_gana_0, _ctx);kk_skip_dup(harmony_0, _ctx);kk_skip_dup(lunar_phase_0, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10012_0_147 = kk_integer_unbox(_b_x145, _ctx); /*int*/;
  kk_unit_t _x_x458 = kk_Unit;
  kk_src_resonance__mlift_server_loop_10033(_c_x10011_0, harmony_0, lunar_phase_0, new_last_gana_0, _c_x10012_0_147, _ctx);
  return kk_unit_box(_x_x458);
}

kk_unit_t kk_src_resonance__mlift_server_loop_10034(kk_integer_t call_count, kk_string_t gana, double harmony_0, kk_string_t last_gana, double lunar_phase_0, kk_string_t op, kk_string_t _c_x10011_0, kk_context_t* _ctx) { /* (call-count : int, gana : string, harmony : float64, last-gana : string, lunar-phase : float64, op : string, string) -> () */ 
  kk_string_t new_last_gana_0;
  bool _match_x248;
  kk_string_t _x_x451 = kk_string_dup(op, _ctx); /*string*/
  kk_string_t _x_x452;
  kk_define_string_literal(, _s_x453, 6, "record", _ctx)
  _x_x452 = kk_string_dup(_s_x453, _ctx); /*string*/
  _match_x248 = kk_string_is_eq(_x_x451,_x_x452,kk_context()); /*bool*/
  if (_match_x248) {
    kk_string_drop(last_gana, _ctx);
    new_last_gana_0 = gana; /*string*/
  }
  else {
    kk_string_drop(gana, _ctx);
    new_last_gana_0 = last_gana; /*string*/
  }
  kk_integer_t x_10036;
  bool _match_x247;
  kk_string_t _x_x454;
  kk_define_string_literal(, _s_x455, 6, "record", _ctx)
  _x_x454 = kk_string_dup(_s_x455, _ctx); /*string*/
  _match_x247 = kk_string_is_eq(op,_x_x454,kk_context()); /*bool*/
  if (_match_x247) {
    x_10036 = kk_integer_add_small_const(call_count, 1, _ctx); /*int*/
  }
  else {
    x_10036 = call_count; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10036, _ctx);
    kk_box_t _x_x456 = kk_std_core_hnd_yield_extend(kk_src_resonance__new_mlift_server_loop_10034_fun457(_c_x10011_0, new_last_gana_0, harmony_0, lunar_phase_0, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x456); return kk_Unit;
  }
  {
    kk_src_resonance__mlift_server_loop_10033(_c_x10011_0, harmony_0, lunar_phase_0, new_last_gana_0, x_10036, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_resonance__mlift_server_loop_10035_fun463__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun463(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx);
static kk_function_t kk_src_resonance__new_mlift_server_loop_10035_fun463(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance__mlift_server_loop_10035_fun463, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun463(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x464;
  kk_string_t _x_x465 = kk_string_unbox(_b_x150); /*string*/
  _x_x464 = kk_src_resonance_extract_op(_x_x465, _ctx); /*string*/
  return kk_string_box(_x_x464);
}


// lift anonymous function
struct kk_src_resonance__mlift_server_loop_10035_fun469__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun469(kk_function_t _fself, kk_box_t _b_x155, kk_context_t* _ctx);
static kk_function_t kk_src_resonance__new_mlift_server_loop_10035_fun469(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance__mlift_server_loop_10035_fun469, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun469(kk_function_t _fself, kk_box_t _b_x155, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x470;
  kk_string_t _x_x471 = kk_string_unbox(_b_x155); /*string*/
  _x_x470 = kk_src_resonance_extract_gana(_x_x471, _ctx); /*string*/
  return kk_string_box(_x_x470);
}


// lift anonymous function
struct kk_src_resonance__mlift_server_loop_10035_fun474__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun474(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx);
static kk_function_t kk_src_resonance__new_mlift_server_loop_10035_fun474(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance__mlift_server_loop_10035_fun474, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun474(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x475;
  kk_string_t _x_x476 = kk_string_unbox(_b_x160); /*string*/
  _x_x475 = kk_src_resonance_get_predecessor(_x_x476, _ctx); /*string*/
  return kk_string_box(_x_x475);
}


// lift anonymous function
struct kk_src_resonance__mlift_server_loop_10035_fun490__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun490(kk_function_t _fself, kk_box_t _b_x165, kk_context_t* _ctx);
static kk_function_t kk_src_resonance__new_mlift_server_loop_10035_fun490(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance__mlift_server_loop_10035_fun490, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun490(kk_function_t _fself, kk_box_t _b_x165, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x491;
  kk_string_t _x_x492 = kk_string_unbox(_b_x165); /*string*/
  _x_x491 = kk_src_resonance_get_successor(_x_x492, _ctx); /*string*/
  return kk_string_box(_x_x491);
}


// lift anonymous function
struct kk_src_resonance__mlift_server_loop_10035_fun519__t {
  struct kk_function_s _base;
};
static kk_string_t kk_src_resonance__mlift_server_loop_10035_fun519(kk_function_t _fself, double _x1_x517, kk_std_core_types__optional _x2_x518, kk_context_t* _ctx);
static kk_function_t kk_src_resonance__new_mlift_server_loop_10035_fun519(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance__mlift_server_loop_10035_fun519, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_string_t kk_src_resonance__mlift_server_loop_10035_fun519(kk_function_t _fself, double _x1_x517, kk_std_core_types__optional _x2_x518, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_float64_show(_x1_x517, _x2_x518, _ctx);
}


// lift anonymous function
struct kk_src_resonance__mlift_server_loop_10035_fun527__t {
  struct kk_function_s _base;
};
static kk_string_t kk_src_resonance__mlift_server_loop_10035_fun527(kk_function_t _fself, double _x1_x525, kk_std_core_types__optional _x2_x526, kk_context_t* _ctx);
static kk_function_t kk_src_resonance__new_mlift_server_loop_10035_fun527(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance__mlift_server_loop_10035_fun527, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_string_t kk_src_resonance__mlift_server_loop_10035_fun527(kk_function_t _fself, double _x1_x525, kk_std_core_types__optional _x2_x526, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_float64_show(_x1_x525, _x2_x526, _ctx);
}


// lift anonymous function
struct kk_src_resonance__mlift_server_loop_10035_fun536__t {
  struct kk_function_s _base;
  kk_function_t _b_x168_178;
};
static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun536(kk_function_t _fself, kk_box_t _b_x171, kk_box_t _b_x172, kk_context_t* _ctx);
static kk_function_t kk_src_resonance__new_mlift_server_loop_10035_fun536(kk_function_t _b_x168_178, kk_context_t* _ctx) {
  struct kk_src_resonance__mlift_server_loop_10035_fun536__t* _self = kk_function_alloc_as(struct kk_src_resonance__mlift_server_loop_10035_fun536__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_resonance__mlift_server_loop_10035_fun536, kk_context());
  _self->_b_x168_178 = _b_x168_178;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun536(kk_function_t _fself, kk_box_t _b_x171, kk_box_t _b_x172, kk_context_t* _ctx) {
  struct kk_src_resonance__mlift_server_loop_10035_fun536__t* _self = kk_function_as(struct kk_src_resonance__mlift_server_loop_10035_fun536__t*, _fself, _ctx);
  kk_function_t _b_x168_178 = _self->_b_x168_178; /* (d : float64, precision : ? int) -> string */
  kk_drop_match(_self, {kk_function_dup(_b_x168_178, _ctx);}, {}, _ctx)
  kk_string_t _x_x537;
  double _x_x538 = kk_double_unbox(_b_x171, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x539 = kk_std_core_types__optional_unbox(_b_x172, KK_OWNED, _ctx); /*? int*/
  _x_x537 = kk_function_call(kk_string_t, (kk_function_t, double, kk_std_core_types__optional, kk_context_t*), _b_x168_178, (_b_x168_178, _x_x538, _x_x539, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x537);
}


// lift anonymous function
struct kk_src_resonance__mlift_server_loop_10035_fun546__t {
  struct kk_function_s _base;
  kk_function_t _b_x173_181;
};
static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun546(kk_function_t _fself, kk_box_t _b_x176, kk_box_t _b_x177, kk_context_t* _ctx);
static kk_function_t kk_src_resonance__new_mlift_server_loop_10035_fun546(kk_function_t _b_x173_181, kk_context_t* _ctx) {
  struct kk_src_resonance__mlift_server_loop_10035_fun546__t* _self = kk_function_alloc_as(struct kk_src_resonance__mlift_server_loop_10035_fun546__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_resonance__mlift_server_loop_10035_fun546, kk_context());
  _self->_b_x173_181 = _b_x173_181;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun546(kk_function_t _fself, kk_box_t _b_x176, kk_box_t _b_x177, kk_context_t* _ctx) {
  struct kk_src_resonance__mlift_server_loop_10035_fun546__t* _self = kk_function_as(struct kk_src_resonance__mlift_server_loop_10035_fun546__t*, _fself, _ctx);
  kk_function_t _b_x173_181 = _self->_b_x173_181; /* (d : float64, precision : ? int) -> string */
  kk_drop_match(_self, {kk_function_dup(_b_x173_181, _ctx);}, {}, _ctx)
  kk_string_t _x_x547;
  double _x_x548 = kk_double_unbox(_b_x176, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x549 = kk_std_core_types__optional_unbox(_b_x177, KK_OWNED, _ctx); /*? int*/
  _x_x547 = kk_function_call(kk_string_t, (kk_function_t, double, kk_std_core_types__optional, kk_context_t*), _b_x173_181, (_b_x173_181, _x_x548, _x_x549, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x547);
}


// lift anonymous function
struct kk_src_resonance__mlift_server_loop_10035_fun555__t {
  struct kk_function_s _base;
  kk_integer_t call_count_0;
  kk_string_t gana_0;
  kk_string_t last_gana_0;
  kk_string_t op_0;
  double harmony_1;
  double lunar_phase_1;
};
static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun555(kk_function_t _fself, kk_box_t _b_x185, kk_context_t* _ctx);
static kk_function_t kk_src_resonance__new_mlift_server_loop_10035_fun555(kk_integer_t call_count_0, kk_string_t gana_0, kk_string_t last_gana_0, kk_string_t op_0, double harmony_1, double lunar_phase_1, kk_context_t* _ctx) {
  struct kk_src_resonance__mlift_server_loop_10035_fun555__t* _self = kk_function_alloc_as(struct kk_src_resonance__mlift_server_loop_10035_fun555__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_resonance__mlift_server_loop_10035_fun555, kk_context());
  _self->call_count_0 = call_count_0;
  _self->gana_0 = gana_0;
  _self->last_gana_0 = last_gana_0;
  _self->op_0 = op_0;
  _self->harmony_1 = harmony_1;
  _self->lunar_phase_1 = lunar_phase_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_resonance__mlift_server_loop_10035_fun555(kk_function_t _fself, kk_box_t _b_x185, kk_context_t* _ctx) {
  struct kk_src_resonance__mlift_server_loop_10035_fun555__t* _self = kk_function_as(struct kk_src_resonance__mlift_server_loop_10035_fun555__t*, _fself, _ctx);
  kk_integer_t call_count_0 = _self->call_count_0; /* int */
  kk_string_t gana_0 = _self->gana_0; /* string */
  kk_string_t last_gana_0 = _self->last_gana_0; /* string */
  kk_string_t op_0 = _self->op_0; /* string */
  double harmony_1 = _self->harmony_1; /* float64 */
  double lunar_phase_1 = _self->lunar_phase_1; /* float64 */
  kk_drop_match(_self, {kk_integer_dup(call_count_0, _ctx);kk_string_dup(gana_0, _ctx);kk_string_dup(last_gana_0, _ctx);kk_string_dup(op_0, _ctx);kk_skip_dup(harmony_1, _ctx);kk_skip_dup(lunar_phase_1, _ctx);}, {}, _ctx)
  kk_string_t _c_x10011_1_187 = kk_string_unbox(_b_x185); /*string*/;
  kk_unit_t _x_x556 = kk_Unit;
  kk_src_resonance__mlift_server_loop_10034(call_count_0, gana_0, harmony_1, last_gana_0, lunar_phase_1, op_0, _c_x10011_1_187, _ctx);
  return kk_unit_box(_x_x556);
}

kk_unit_t kk_src_resonance__mlift_server_loop_10035(kk_integer_t call_count_0, double harmony_1, kk_string_t last_gana_0, double lunar_phase_1, kk_string_t line, kk_context_t* _ctx) { /* (call-count : int, harmony : float64, last-gana : string, lunar-phase : float64, line : string) -> <console/console,exn> () */ 
  bool _match_x244;
  kk_string_t _x_x459 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x460 = kk_string_empty(); /*string*/
  _match_x244 = kk_string_is_neq(_x_x459,_x_x460,kk_context()); /*bool*/
  if (_match_x244) {
    kk_string_t op_0;
    kk_box_t _x_x462;
    kk_box_t _x_x466;
    kk_string_t _x_x467 = kk_string_dup(line, _ctx); /*string*/
    _x_x466 = kk_string_box(_x_x467); /*10000*/
    _x_x462 = kk_std_core_hnd__open_none1(kk_src_resonance__new_mlift_server_loop_10035_fun463(_ctx), _x_x466, _ctx); /*10001*/
    op_0 = kk_string_unbox(_x_x462); /*string*/
    kk_string_t gana_0;
    kk_box_t _x_x468 = kk_std_core_hnd__open_none1(kk_src_resonance__new_mlift_server_loop_10035_fun469(_ctx), kk_string_box(line), _ctx); /*10001*/
    gana_0 = kk_string_unbox(_x_x468); /*string*/
    kk_string_t x_0_10038;
    if (kk_string_cmp_cstr_borrow(op_0, "predecessor", _ctx) == 0) {
      kk_string_t pred;
      kk_box_t _x_x473;
      kk_box_t _x_x477;
      kk_string_t _x_x478 = kk_string_dup(gana_0, _ctx); /*string*/
      _x_x477 = kk_string_box(_x_x478); /*10000*/
      _x_x473 = kk_std_core_hnd__open_none1(kk_src_resonance__new_mlift_server_loop_10035_fun474(_ctx), _x_x477, _ctx); /*10001*/
      pred = kk_string_unbox(_x_x473); /*string*/
      kk_string_t _x_x479;
      kk_define_string_literal(, _s_x480, 38, "{\"operation\": \"predecessor\", \"gana\": \"", _ctx)
      _x_x479 = kk_string_dup(_s_x480, _ctx); /*string*/
      kk_string_t _x_x481;
      kk_string_t _x_x482 = kk_string_dup(gana_0, _ctx); /*string*/
      kk_string_t _x_x483;
      kk_string_t _x_x484;
      kk_define_string_literal(, _s_x485, 19, "\", \"predecessor\": \"", _ctx)
      _x_x484 = kk_string_dup(_s_x485, _ctx); /*string*/
      kk_string_t _x_x486;
      kk_string_t _x_x487;
      kk_define_string_literal(, _s_x488, 2, "\"}", _ctx)
      _x_x487 = kk_string_dup(_s_x488, _ctx); /*string*/
      _x_x486 = kk_std_core_types__lp__plus__plus__rp_(pred, _x_x487, _ctx); /*string*/
      _x_x483 = kk_std_core_types__lp__plus__plus__rp_(_x_x484, _x_x486, _ctx); /*string*/
      _x_x481 = kk_std_core_types__lp__plus__plus__rp_(_x_x482, _x_x483, _ctx); /*string*/
      x_0_10038 = kk_std_core_types__lp__plus__plus__rp_(_x_x479, _x_x481, _ctx); /*string*/
      goto _match_x472;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "successor", _ctx) == 0) {
      kk_string_t succ;
      kk_box_t _x_x489;
      kk_box_t _x_x493;
      kk_string_t _x_x494 = kk_string_dup(gana_0, _ctx); /*string*/
      _x_x493 = kk_string_box(_x_x494); /*10000*/
      _x_x489 = kk_std_core_hnd__open_none1(kk_src_resonance__new_mlift_server_loop_10035_fun490(_ctx), _x_x493, _ctx); /*10001*/
      succ = kk_string_unbox(_x_x489); /*string*/
      kk_string_t _x_x495;
      kk_define_string_literal(, _s_x496, 36, "{\"operation\": \"successor\", \"gana\": \"", _ctx)
      _x_x495 = kk_string_dup(_s_x496, _ctx); /*string*/
      kk_string_t _x_x497;
      kk_string_t _x_x498 = kk_string_dup(gana_0, _ctx); /*string*/
      kk_string_t _x_x499;
      kk_string_t _x_x500;
      kk_define_string_literal(, _s_x501, 17, "\", \"successor\": \"", _ctx)
      _x_x500 = kk_string_dup(_s_x501, _ctx); /*string*/
      kk_string_t _x_x502;
      kk_string_t _x_x503;
      kk_define_string_literal(, _s_x504, 2, "\"}", _ctx)
      _x_x503 = kk_string_dup(_s_x504, _ctx); /*string*/
      _x_x502 = kk_std_core_types__lp__plus__plus__rp_(succ, _x_x503, _ctx); /*string*/
      _x_x499 = kk_std_core_types__lp__plus__plus__rp_(_x_x500, _x_x502, _ctx); /*string*/
      _x_x497 = kk_std_core_types__lp__plus__plus__rp_(_x_x498, _x_x499, _ctx); /*string*/
      x_0_10038 = kk_std_core_types__lp__plus__plus__rp_(_x_x495, _x_x497, _ctx); /*string*/
      goto _match_x472;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "record", _ctx) == 0) {
      kk_string_t _x_x505;
      kk_define_string_literal(, _s_x506, 33, "{\"operation\": \"record\", \"gana\": \"", _ctx)
      _x_x505 = kk_string_dup(_s_x506, _ctx); /*string*/
      kk_string_t _x_x507;
      kk_string_t _x_x508 = kk_string_dup(gana_0, _ctx); /*string*/
      kk_string_t _x_x509;
      kk_define_string_literal(, _s_x510, 20, "\", \"recorded\": true}", _ctx)
      _x_x509 = kk_string_dup(_s_x510, _ctx); /*string*/
      _x_x507 = kk_std_core_types__lp__plus__plus__rp_(_x_x508, _x_x509, _ctx); /*string*/
      x_0_10038 = kk_std_core_types__lp__plus__plus__rp_(_x_x505, _x_x507, _ctx); /*string*/
      goto _match_x472;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_string_t _x_x511;
      kk_define_string_literal(, _s_x512, 15, "{\"call_count\": ", _ctx)
      _x_x511 = kk_string_dup(_s_x512, _ctx); /*string*/
      kk_string_t _x_x513;
      kk_string_t _x_x514;
      kk_integer_t _x_x515 = kk_integer_dup(call_count_0, _ctx); /*int*/
      _x_x514 = kk_std_core_int_show(_x_x515, _ctx); /*string*/
      kk_string_t _x_x516;
      kk_function_t _b_x168_178 = kk_src_resonance__new_mlift_server_loop_10035_fun519(_ctx); /*(d : float64, precision : ? int) -> string*/;
      double _b_x169_179 = lunar_phase_1; /*float64*/;
      kk_std_core_types__optional _b_x170_180 = kk_std_core_types__new_None(_ctx); /*? int*/;
      kk_string_t _x_x520;
      kk_define_string_literal(, _s_x521, 16, ", \"last_gana\": \"", _ctx)
      _x_x520 = kk_string_dup(_s_x521, _ctx); /*string*/
      kk_string_t _x_x522;
      kk_string_t _x_x523 = kk_string_dup(last_gana_0, _ctx); /*string*/
      kk_string_t _x_x524;
      kk_function_t _b_x173_181 = kk_src_resonance__new_mlift_server_loop_10035_fun527(_ctx); /*(d : float64, precision : ? int) -> string*/;
      double _b_x174_182 = harmony_1; /*float64*/;
      kk_std_core_types__optional _b_x175_183 = kk_std_core_types__new_None(_ctx); /*? int*/;
      kk_string_t _x_x528;
      kk_define_string_literal(, _s_x529, 1, "\"", _ctx)
      _x_x528 = kk_string_dup(_s_x529, _ctx); /*string*/
      kk_string_t _x_x530;
      kk_string_t _x_x531;
      kk_define_string_literal(, _s_x532, 17, ", \"lunar_phase\": ", _ctx)
      _x_x531 = kk_string_dup(_s_x532, _ctx); /*string*/
      kk_string_t _x_x533;
      kk_string_t _x_x534;
      kk_box_t _x_x535 = kk_std_core_hnd__open_none2(kk_src_resonance__new_mlift_server_loop_10035_fun536(_b_x168_178, _ctx), kk_double_box(_b_x169_179, _ctx), kk_std_core_types__optional_box(_b_x170_180, _ctx), _ctx); /*10002*/
      _x_x534 = kk_string_unbox(_x_x535); /*string*/
      kk_string_t _x_x540;
      kk_string_t _x_x541;
      kk_define_string_literal(, _s_x542, 13, ", \"harmony\": ", _ctx)
      _x_x541 = kk_string_dup(_s_x542, _ctx); /*string*/
      kk_string_t _x_x543;
      kk_string_t _x_x544;
      kk_box_t _x_x545 = kk_std_core_hnd__open_none2(kk_src_resonance__new_mlift_server_loop_10035_fun546(_b_x173_181, _ctx), kk_double_box(_b_x174_182, _ctx), kk_std_core_types__optional_box(_b_x175_183, _ctx), _ctx); /*10002*/
      _x_x544 = kk_string_unbox(_x_x545); /*string*/
      kk_string_t _x_x550;
      kk_define_string_literal(, _s_x551, 1, "}", _ctx)
      _x_x550 = kk_string_dup(_s_x551, _ctx); /*string*/
      _x_x543 = kk_std_core_types__lp__plus__plus__rp_(_x_x544, _x_x550, _ctx); /*string*/
      _x_x540 = kk_std_core_types__lp__plus__plus__rp_(_x_x541, _x_x543, _ctx); /*string*/
      _x_x533 = kk_std_core_types__lp__plus__plus__rp_(_x_x534, _x_x540, _ctx); /*string*/
      _x_x530 = kk_std_core_types__lp__plus__plus__rp_(_x_x531, _x_x533, _ctx); /*string*/
      _x_x524 = kk_std_core_types__lp__plus__plus__rp_(_x_x528, _x_x530, _ctx); /*string*/
      _x_x522 = kk_std_core_types__lp__plus__plus__rp_(_x_x523, _x_x524, _ctx); /*string*/
      _x_x516 = kk_std_core_types__lp__plus__plus__rp_(_x_x520, _x_x522, _ctx); /*string*/
      _x_x513 = kk_std_core_types__lp__plus__plus__rp_(_x_x514, _x_x516, _ctx); /*string*/
      x_0_10038 = kk_std_core_types__lp__plus__plus__rp_(_x_x511, _x_x513, _ctx); /*string*/
      goto _match_x472;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "reset", _ctx) == 0) {
      kk_define_string_literal(, _s_x552, 38, "{\"operation\": \"reset\", \"result\": \"ok\"}", _ctx)
      x_0_10038 = kk_string_dup(_s_x552, _ctx); /*string*/
      goto _match_x472;
    }
    {
      kk_define_string_literal(, _s_x553, 30, "{\"error\": \"unknown_operation\"}", _ctx)
      x_0_10038 = kk_string_dup(_s_x553, _ctx); /*string*/
    }
    _match_x472: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10038, _ctx);
      kk_box_t _x_x554 = kk_std_core_hnd_yield_extend(kk_src_resonance__new_mlift_server_loop_10035_fun555(call_count_0, gana_0, last_gana_0, op_0, harmony_1, lunar_phase_1, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x554); return kk_Unit;
    }
    {
      kk_src_resonance__mlift_server_loop_10034(call_count_0, gana_0, harmony_1, last_gana_0, lunar_phase_1, op_0, x_0_10038, _ctx); return kk_Unit;
    }
  }
  {
    kk_string_drop(line, _ctx);
    kk_string_drop(last_gana_0, _ctx);
    kk_integer_drop(call_count_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun558__t {
  struct kk_function_s _base;
  kk_integer_t call_count_1;
  kk_string_t last_gana_1;
  double harmony_2;
  double lunar_phase_2;
};
static kk_box_t kk_src_resonance_server_loop_fun558(kk_function_t _fself, kk_box_t _b_x189, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun558(kk_integer_t call_count_1, kk_string_t last_gana_1, double harmony_2, double lunar_phase_2, kk_context_t* _ctx) {
  struct kk_src_resonance_server_loop_fun558__t* _self = kk_function_alloc_as(struct kk_src_resonance_server_loop_fun558__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_resonance_server_loop_fun558, kk_context());
  _self->call_count_1 = call_count_1;
  _self->last_gana_1 = last_gana_1;
  _self->harmony_2 = harmony_2;
  _self->lunar_phase_2 = lunar_phase_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_resonance_server_loop_fun558(kk_function_t _fself, kk_box_t _b_x189, kk_context_t* _ctx) {
  struct kk_src_resonance_server_loop_fun558__t* _self = kk_function_as(struct kk_src_resonance_server_loop_fun558__t*, _fself, _ctx);
  kk_integer_t call_count_1 = _self->call_count_1; /* int */
  kk_string_t last_gana_1 = _self->last_gana_1; /* string */
  double harmony_2 = _self->harmony_2; /* float64 */
  double lunar_phase_2 = _self->lunar_phase_2; /* float64 */
  kk_drop_match(_self, {kk_integer_dup(call_count_1, _ctx);kk_string_dup(last_gana_1, _ctx);kk_skip_dup(harmony_2, _ctx);kk_skip_dup(lunar_phase_2, _ctx);}, {}, _ctx)
  kk_string_t line_0_235 = kk_string_unbox(_b_x189); /*string*/;
  kk_unit_t _x_x559 = kk_Unit;
  kk_src_resonance__mlift_server_loop_10035(call_count_1, harmony_2, last_gana_1, lunar_phase_2, line_0_235, _ctx);
  return kk_unit_box(_x_x559);
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun564__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_resonance_server_loop_fun564(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun564(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance_server_loop_fun564, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_resonance_server_loop_fun564(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x565;
  kk_string_t _x_x566 = kk_string_unbox(_b_x192); /*string*/
  _x_x565 = kk_src_resonance_extract_op(_x_x566, _ctx); /*string*/
  return kk_string_box(_x_x565);
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun570__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_resonance_server_loop_fun570(kk_function_t _fself, kk_box_t _b_x197, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun570(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance_server_loop_fun570, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_resonance_server_loop_fun570(kk_function_t _fself, kk_box_t _b_x197, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x571;
  kk_string_t _x_x572 = kk_string_unbox(_b_x197); /*string*/
  _x_x571 = kk_src_resonance_extract_gana(_x_x572, _ctx); /*string*/
  return kk_string_box(_x_x571);
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun575__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_resonance_server_loop_fun575(kk_function_t _fself, kk_box_t _b_x202, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun575(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance_server_loop_fun575, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_resonance_server_loop_fun575(kk_function_t _fself, kk_box_t _b_x202, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x576;
  kk_string_t _x_x577 = kk_string_unbox(_b_x202); /*string*/
  _x_x576 = kk_src_resonance_get_predecessor(_x_x577, _ctx); /*string*/
  return kk_string_box(_x_x576);
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun591__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_resonance_server_loop_fun591(kk_function_t _fself, kk_box_t _b_x207, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun591(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance_server_loop_fun591, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_resonance_server_loop_fun591(kk_function_t _fself, kk_box_t _b_x207, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x592;
  kk_string_t _x_x593 = kk_string_unbox(_b_x207); /*string*/
  _x_x592 = kk_src_resonance_get_successor(_x_x593, _ctx); /*string*/
  return kk_string_box(_x_x592);
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun620__t {
  struct kk_function_s _base;
};
static kk_string_t kk_src_resonance_server_loop_fun620(kk_function_t _fself, double _x1_x618, kk_std_core_types__optional _x2_x619, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun620(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance_server_loop_fun620, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_string_t kk_src_resonance_server_loop_fun620(kk_function_t _fself, double _x1_x618, kk_std_core_types__optional _x2_x619, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_float64_show(_x1_x618, _x2_x619, _ctx);
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun628__t {
  struct kk_function_s _base;
};
static kk_string_t kk_src_resonance_server_loop_fun628(kk_function_t _fself, double _x1_x626, kk_std_core_types__optional _x2_x627, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun628(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance_server_loop_fun628, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_string_t kk_src_resonance_server_loop_fun628(kk_function_t _fself, double _x1_x626, kk_std_core_types__optional _x2_x627, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_float64_show(_x1_x626, _x2_x627, _ctx);
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun637__t {
  struct kk_function_s _base;
  kk_function_t _b_x210_220;
};
static kk_box_t kk_src_resonance_server_loop_fun637(kk_function_t _fself, kk_box_t _b_x213, kk_box_t _b_x214, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun637(kk_function_t _b_x210_220, kk_context_t* _ctx) {
  struct kk_src_resonance_server_loop_fun637__t* _self = kk_function_alloc_as(struct kk_src_resonance_server_loop_fun637__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_resonance_server_loop_fun637, kk_context());
  _self->_b_x210_220 = _b_x210_220;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_resonance_server_loop_fun637(kk_function_t _fself, kk_box_t _b_x213, kk_box_t _b_x214, kk_context_t* _ctx) {
  struct kk_src_resonance_server_loop_fun637__t* _self = kk_function_as(struct kk_src_resonance_server_loop_fun637__t*, _fself, _ctx);
  kk_function_t _b_x210_220 = _self->_b_x210_220; /* (d : float64, precision : ? int) -> string */
  kk_drop_match(_self, {kk_function_dup(_b_x210_220, _ctx);}, {}, _ctx)
  kk_string_t _x_x638;
  double _x_x639 = kk_double_unbox(_b_x213, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x640 = kk_std_core_types__optional_unbox(_b_x214, KK_OWNED, _ctx); /*? int*/
  _x_x638 = kk_function_call(kk_string_t, (kk_function_t, double, kk_std_core_types__optional, kk_context_t*), _b_x210_220, (_b_x210_220, _x_x639, _x_x640, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x638);
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun647__t {
  struct kk_function_s _base;
  kk_function_t _b_x215_223;
};
static kk_box_t kk_src_resonance_server_loop_fun647(kk_function_t _fself, kk_box_t _b_x218, kk_box_t _b_x219, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun647(kk_function_t _b_x215_223, kk_context_t* _ctx) {
  struct kk_src_resonance_server_loop_fun647__t* _self = kk_function_alloc_as(struct kk_src_resonance_server_loop_fun647__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_resonance_server_loop_fun647, kk_context());
  _self->_b_x215_223 = _b_x215_223;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_resonance_server_loop_fun647(kk_function_t _fself, kk_box_t _b_x218, kk_box_t _b_x219, kk_context_t* _ctx) {
  struct kk_src_resonance_server_loop_fun647__t* _self = kk_function_as(struct kk_src_resonance_server_loop_fun647__t*, _fself, _ctx);
  kk_function_t _b_x215_223 = _self->_b_x215_223; /* (d : float64, precision : ? int) -> string */
  kk_drop_match(_self, {kk_function_dup(_b_x215_223, _ctx);}, {}, _ctx)
  kk_string_t _x_x648;
  double _x_x649 = kk_double_unbox(_b_x218, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x650 = kk_std_core_types__optional_unbox(_b_x219, KK_OWNED, _ctx); /*? int*/
  _x_x648 = kk_function_call(kk_string_t, (kk_function_t, double, kk_std_core_types__optional, kk_context_t*), _b_x215_223, (_b_x215_223, _x_x649, _x_x650, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x648);
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun656__t {
  struct kk_function_s _base;
  kk_integer_t call_count_1;
  kk_string_t gana_1;
  kk_string_t last_gana_1;
  kk_string_t op_1;
  double harmony_2;
  double lunar_phase_2;
};
static kk_box_t kk_src_resonance_server_loop_fun656(kk_function_t _fself, kk_box_t _b_x227, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun656(kk_integer_t call_count_1, kk_string_t gana_1, kk_string_t last_gana_1, kk_string_t op_1, double harmony_2, double lunar_phase_2, kk_context_t* _ctx) {
  struct kk_src_resonance_server_loop_fun656__t* _self = kk_function_alloc_as(struct kk_src_resonance_server_loop_fun656__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_resonance_server_loop_fun656, kk_context());
  _self->call_count_1 = call_count_1;
  _self->gana_1 = gana_1;
  _self->last_gana_1 = last_gana_1;
  _self->op_1 = op_1;
  _self->harmony_2 = harmony_2;
  _self->lunar_phase_2 = lunar_phase_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_resonance_server_loop_fun656(kk_function_t _fself, kk_box_t _b_x227, kk_context_t* _ctx) {
  struct kk_src_resonance_server_loop_fun656__t* _self = kk_function_as(struct kk_src_resonance_server_loop_fun656__t*, _fself, _ctx);
  kk_integer_t call_count_1 = _self->call_count_1; /* int */
  kk_string_t gana_1 = _self->gana_1; /* string */
  kk_string_t last_gana_1 = _self->last_gana_1; /* string */
  kk_string_t op_1 = _self->op_1; /* string */
  double harmony_2 = _self->harmony_2; /* float64 */
  double lunar_phase_2 = _self->lunar_phase_2; /* float64 */
  kk_drop_match(_self, {kk_integer_dup(call_count_1, _ctx);kk_string_dup(gana_1, _ctx);kk_string_dup(last_gana_1, _ctx);kk_string_dup(op_1, _ctx);kk_skip_dup(harmony_2, _ctx);kk_skip_dup(lunar_phase_2, _ctx);}, {}, _ctx)
  kk_string_t _c_x10011_2_236 = kk_string_unbox(_b_x227); /*string*/;
  kk_unit_t _x_x657 = kk_Unit;
  kk_src_resonance__mlift_server_loop_10034(call_count_1, gana_1, harmony_2, last_gana_1, lunar_phase_2, op_1, _c_x10011_2_236, _ctx);
  return kk_unit_box(_x_x657);
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun664__t {
  struct kk_function_s _base;
  kk_string_t new_last_gana_1;
  kk_string_t x_2_10043;
  double harmony_2;
  double lunar_phase_2;
};
static kk_box_t kk_src_resonance_server_loop_fun664(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun664(kk_string_t new_last_gana_1, kk_string_t x_2_10043, double harmony_2, double lunar_phase_2, kk_context_t* _ctx) {
  struct kk_src_resonance_server_loop_fun664__t* _self = kk_function_alloc_as(struct kk_src_resonance_server_loop_fun664__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_resonance_server_loop_fun664, kk_context());
  _self->new_last_gana_1 = new_last_gana_1;
  _self->x_2_10043 = x_2_10043;
  _self->harmony_2 = harmony_2;
  _self->lunar_phase_2 = lunar_phase_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_resonance_server_loop_fun664(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx) {
  struct kk_src_resonance_server_loop_fun664__t* _self = kk_function_as(struct kk_src_resonance_server_loop_fun664__t*, _fself, _ctx);
  kk_string_t new_last_gana_1 = _self->new_last_gana_1; /* string */
  kk_string_t x_2_10043 = _self->x_2_10043; /* string */
  double harmony_2 = _self->harmony_2; /* float64 */
  double lunar_phase_2 = _self->lunar_phase_2; /* float64 */
  kk_drop_match(_self, {kk_string_dup(new_last_gana_1, _ctx);kk_string_dup(x_2_10043, _ctx);kk_skip_dup(harmony_2, _ctx);kk_skip_dup(lunar_phase_2, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10012_1_237 = kk_integer_unbox(_b_x229, _ctx); /*int*/;
  kk_unit_t _x_x665 = kk_Unit;
  kk_src_resonance__mlift_server_loop_10033(x_2_10043, harmony_2, lunar_phase_2, new_last_gana_1, _c_x10012_1_237, _ctx);
  return kk_unit_box(_x_x665);
}


// lift anonymous function
struct kk_src_resonance_server_loop_fun667__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_resonance_server_loop_fun667(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_resonance_new_server_loop_fun667(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_resonance_server_loop_fun667, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_resonance_server_loop_fun667(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x668 = kk_Unit;
  kk_src_resonance_flush_stdout(_ctx);
  return kk_unit_box(_x_x668);
}

kk_unit_t kk_src_resonance_server_loop(kk_string_t last_gana_1, kk_integer_t call_count_1, double lunar_phase_2, double harmony_2, kk_context_t* _ctx) { /* (last-gana : string, call-count : int, lunar-phase : float64, harmony : float64) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_1_10040 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_1_10040, _ctx);
    kk_box_t _x_x557 = kk_std_core_hnd_yield_extend(kk_src_resonance_new_server_loop_fun558(call_count_1, last_gana_1, harmony_2, lunar_phase_2, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x557); return kk_Unit;
  }
  {
    bool _match_x239;
    kk_string_t _x_x560 = kk_string_dup(x_1_10040, _ctx); /*string*/
    kk_string_t _x_x561 = kk_string_empty(); /*string*/
    _match_x239 = kk_string_is_neq(_x_x560,_x_x561,kk_context()); /*bool*/
    if (_match_x239) {
      kk_string_t op_1;
      kk_box_t _x_x563;
      kk_box_t _x_x567;
      kk_string_t _x_x568 = kk_string_dup(x_1_10040, _ctx); /*string*/
      _x_x567 = kk_string_box(_x_x568); /*10000*/
      _x_x563 = kk_std_core_hnd__open_none1(kk_src_resonance_new_server_loop_fun564(_ctx), _x_x567, _ctx); /*10001*/
      op_1 = kk_string_unbox(_x_x563); /*string*/
      kk_string_t gana_1;
      kk_box_t _x_x569 = kk_std_core_hnd__open_none1(kk_src_resonance_new_server_loop_fun570(_ctx), kk_string_box(x_1_10040), _ctx); /*10001*/
      gana_1 = kk_string_unbox(_x_x569); /*string*/
      kk_string_t x_2_10043;
      if (kk_string_cmp_cstr_borrow(op_1, "predecessor", _ctx) == 0) {
        kk_string_t pred_0;
        kk_box_t _x_x574;
        kk_box_t _x_x578;
        kk_string_t _x_x579 = kk_string_dup(gana_1, _ctx); /*string*/
        _x_x578 = kk_string_box(_x_x579); /*10000*/
        _x_x574 = kk_std_core_hnd__open_none1(kk_src_resonance_new_server_loop_fun575(_ctx), _x_x578, _ctx); /*10001*/
        pred_0 = kk_string_unbox(_x_x574); /*string*/
        kk_string_t _x_x580;
        kk_define_string_literal(, _s_x581, 38, "{\"operation\": \"predecessor\", \"gana\": \"", _ctx)
        _x_x580 = kk_string_dup(_s_x581, _ctx); /*string*/
        kk_string_t _x_x582;
        kk_string_t _x_x583 = kk_string_dup(gana_1, _ctx); /*string*/
        kk_string_t _x_x584;
        kk_string_t _x_x585;
        kk_define_string_literal(, _s_x586, 19, "\", \"predecessor\": \"", _ctx)
        _x_x585 = kk_string_dup(_s_x586, _ctx); /*string*/
        kk_string_t _x_x587;
        kk_string_t _x_x588;
        kk_define_string_literal(, _s_x589, 2, "\"}", _ctx)
        _x_x588 = kk_string_dup(_s_x589, _ctx); /*string*/
        _x_x587 = kk_std_core_types__lp__plus__plus__rp_(pred_0, _x_x588, _ctx); /*string*/
        _x_x584 = kk_std_core_types__lp__plus__plus__rp_(_x_x585, _x_x587, _ctx); /*string*/
        _x_x582 = kk_std_core_types__lp__plus__plus__rp_(_x_x583, _x_x584, _ctx); /*string*/
        x_2_10043 = kk_std_core_types__lp__plus__plus__rp_(_x_x580, _x_x582, _ctx); /*string*/
        goto _match_x573;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "successor", _ctx) == 0) {
        kk_string_t succ_0;
        kk_box_t _x_x590;
        kk_box_t _x_x594;
        kk_string_t _x_x595 = kk_string_dup(gana_1, _ctx); /*string*/
        _x_x594 = kk_string_box(_x_x595); /*10000*/
        _x_x590 = kk_std_core_hnd__open_none1(kk_src_resonance_new_server_loop_fun591(_ctx), _x_x594, _ctx); /*10001*/
        succ_0 = kk_string_unbox(_x_x590); /*string*/
        kk_string_t _x_x596;
        kk_define_string_literal(, _s_x597, 36, "{\"operation\": \"successor\", \"gana\": \"", _ctx)
        _x_x596 = kk_string_dup(_s_x597, _ctx); /*string*/
        kk_string_t _x_x598;
        kk_string_t _x_x599 = kk_string_dup(gana_1, _ctx); /*string*/
        kk_string_t _x_x600;
        kk_string_t _x_x601;
        kk_define_string_literal(, _s_x602, 17, "\", \"successor\": \"", _ctx)
        _x_x601 = kk_string_dup(_s_x602, _ctx); /*string*/
        kk_string_t _x_x603;
        kk_string_t _x_x604;
        kk_define_string_literal(, _s_x605, 2, "\"}", _ctx)
        _x_x604 = kk_string_dup(_s_x605, _ctx); /*string*/
        _x_x603 = kk_std_core_types__lp__plus__plus__rp_(succ_0, _x_x604, _ctx); /*string*/
        _x_x600 = kk_std_core_types__lp__plus__plus__rp_(_x_x601, _x_x603, _ctx); /*string*/
        _x_x598 = kk_std_core_types__lp__plus__plus__rp_(_x_x599, _x_x600, _ctx); /*string*/
        x_2_10043 = kk_std_core_types__lp__plus__plus__rp_(_x_x596, _x_x598, _ctx); /*string*/
        goto _match_x573;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "record", _ctx) == 0) {
        kk_string_t _x_x606;
        kk_define_string_literal(, _s_x607, 33, "{\"operation\": \"record\", \"gana\": \"", _ctx)
        _x_x606 = kk_string_dup(_s_x607, _ctx); /*string*/
        kk_string_t _x_x608;
        kk_string_t _x_x609 = kk_string_dup(gana_1, _ctx); /*string*/
        kk_string_t _x_x610;
        kk_define_string_literal(, _s_x611, 20, "\", \"recorded\": true}", _ctx)
        _x_x610 = kk_string_dup(_s_x611, _ctx); /*string*/
        _x_x608 = kk_std_core_types__lp__plus__plus__rp_(_x_x609, _x_x610, _ctx); /*string*/
        x_2_10043 = kk_std_core_types__lp__plus__plus__rp_(_x_x606, _x_x608, _ctx); /*string*/
        goto _match_x573;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
        kk_string_t _x_x612;
        kk_define_string_literal(, _s_x613, 15, "{\"call_count\": ", _ctx)
        _x_x612 = kk_string_dup(_s_x613, _ctx); /*string*/
        kk_string_t _x_x614;
        kk_string_t _x_x615;
        kk_integer_t _x_x616 = kk_integer_dup(call_count_1, _ctx); /*int*/
        _x_x615 = kk_std_core_int_show(_x_x616, _ctx); /*string*/
        kk_string_t _x_x617;
        kk_function_t _b_x210_220 = kk_src_resonance_new_server_loop_fun620(_ctx); /*(d : float64, precision : ? int) -> string*/;
        double _b_x211_221 = lunar_phase_2; /*float64*/;
        kk_std_core_types__optional _b_x212_222 = kk_std_core_types__new_None(_ctx); /*? int*/;
        kk_string_t _x_x621;
        kk_define_string_literal(, _s_x622, 16, ", \"last_gana\": \"", _ctx)
        _x_x621 = kk_string_dup(_s_x622, _ctx); /*string*/
        kk_string_t _x_x623;
        kk_string_t _x_x624 = kk_string_dup(last_gana_1, _ctx); /*string*/
        kk_string_t _x_x625;
        kk_function_t _b_x215_223 = kk_src_resonance_new_server_loop_fun628(_ctx); /*(d : float64, precision : ? int) -> string*/;
        double _b_x216_224 = harmony_2; /*float64*/;
        kk_std_core_types__optional _b_x217_225 = kk_std_core_types__new_None(_ctx); /*? int*/;
        kk_string_t _x_x629;
        kk_define_string_literal(, _s_x630, 1, "\"", _ctx)
        _x_x629 = kk_string_dup(_s_x630, _ctx); /*string*/
        kk_string_t _x_x631;
        kk_string_t _x_x632;
        kk_define_string_literal(, _s_x633, 17, ", \"lunar_phase\": ", _ctx)
        _x_x632 = kk_string_dup(_s_x633, _ctx); /*string*/
        kk_string_t _x_x634;
        kk_string_t _x_x635;
        kk_box_t _x_x636 = kk_std_core_hnd__open_none2(kk_src_resonance_new_server_loop_fun637(_b_x210_220, _ctx), kk_double_box(_b_x211_221, _ctx), kk_std_core_types__optional_box(_b_x212_222, _ctx), _ctx); /*10002*/
        _x_x635 = kk_string_unbox(_x_x636); /*string*/
        kk_string_t _x_x641;
        kk_string_t _x_x642;
        kk_define_string_literal(, _s_x643, 13, ", \"harmony\": ", _ctx)
        _x_x642 = kk_string_dup(_s_x643, _ctx); /*string*/
        kk_string_t _x_x644;
        kk_string_t _x_x645;
        kk_box_t _x_x646 = kk_std_core_hnd__open_none2(kk_src_resonance_new_server_loop_fun647(_b_x215_223, _ctx), kk_double_box(_b_x216_224, _ctx), kk_std_core_types__optional_box(_b_x217_225, _ctx), _ctx); /*10002*/
        _x_x645 = kk_string_unbox(_x_x646); /*string*/
        kk_string_t _x_x651;
        kk_define_string_literal(, _s_x652, 1, "}", _ctx)
        _x_x651 = kk_string_dup(_s_x652, _ctx); /*string*/
        _x_x644 = kk_std_core_types__lp__plus__plus__rp_(_x_x645, _x_x651, _ctx); /*string*/
        _x_x641 = kk_std_core_types__lp__plus__plus__rp_(_x_x642, _x_x644, _ctx); /*string*/
        _x_x634 = kk_std_core_types__lp__plus__plus__rp_(_x_x635, _x_x641, _ctx); /*string*/
        _x_x631 = kk_std_core_types__lp__plus__plus__rp_(_x_x632, _x_x634, _ctx); /*string*/
        _x_x625 = kk_std_core_types__lp__plus__plus__rp_(_x_x629, _x_x631, _ctx); /*string*/
        _x_x623 = kk_std_core_types__lp__plus__plus__rp_(_x_x624, _x_x625, _ctx); /*string*/
        _x_x617 = kk_std_core_types__lp__plus__plus__rp_(_x_x621, _x_x623, _ctx); /*string*/
        _x_x614 = kk_std_core_types__lp__plus__plus__rp_(_x_x615, _x_x617, _ctx); /*string*/
        x_2_10043 = kk_std_core_types__lp__plus__plus__rp_(_x_x612, _x_x614, _ctx); /*string*/
        goto _match_x573;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "reset", _ctx) == 0) {
        kk_define_string_literal(, _s_x653, 38, "{\"operation\": \"reset\", \"result\": \"ok\"}", _ctx)
        x_2_10043 = kk_string_dup(_s_x653, _ctx); /*string*/
        goto _match_x573;
      }
      {
        kk_define_string_literal(, _s_x654, 30, "{\"error\": \"unknown_operation\"}", _ctx)
        x_2_10043 = kk_string_dup(_s_x654, _ctx); /*string*/
      }
      _match_x573: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_2_10043, _ctx);
        kk_box_t _x_x655 = kk_std_core_hnd_yield_extend(kk_src_resonance_new_server_loop_fun656(call_count_1, gana_1, last_gana_1, op_1, harmony_2, lunar_phase_2, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x655); return kk_Unit;
      }
      {
        kk_string_t new_last_gana_1;
        bool _match_x243;
        kk_string_t _x_x658 = kk_string_dup(op_1, _ctx); /*string*/
        kk_string_t _x_x659;
        kk_define_string_literal(, _s_x660, 6, "record", _ctx)
        _x_x659 = kk_string_dup(_s_x660, _ctx); /*string*/
        _match_x243 = kk_string_is_eq(_x_x658,_x_x659,kk_context()); /*bool*/
        if (_match_x243) {
          kk_string_drop(last_gana_1, _ctx);
          new_last_gana_1 = gana_1; /*string*/
        }
        else {
          kk_string_drop(gana_1, _ctx);
          new_last_gana_1 = last_gana_1; /*string*/
        }
        kk_integer_t x_3_10046;
        bool _match_x242;
        kk_string_t _x_x661;
        kk_define_string_literal(, _s_x662, 6, "record", _ctx)
        _x_x661 = kk_string_dup(_s_x662, _ctx); /*string*/
        _match_x242 = kk_string_is_eq(op_1,_x_x661,kk_context()); /*bool*/
        if (_match_x242) {
          x_3_10046 = kk_integer_add_small_const(call_count_1, 1, _ctx); /*int*/
        }
        else {
          x_3_10046 = call_count_1; /*int*/
        }
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_3_10046, _ctx);
          kk_box_t _x_x663 = kk_std_core_hnd_yield_extend(kk_src_resonance_new_server_loop_fun664(new_last_gana_1, x_2_10043, harmony_2, lunar_phase_2, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x663); return kk_Unit;
        }
        {
          kk_unit_t ___1 = kk_Unit;
          kk_std_core_console_printsln(x_2_10043, _ctx);
          kk_unit_t ___0_0 = kk_Unit;
          kk_box_t _x_x666 = kk_std_core_hnd__open_none0(kk_src_resonance_new_server_loop_fun667(_ctx), _ctx); /*10000*/
          kk_unit_unbox(_x_x666);
          { // tailcall
            last_gana_1 = new_last_gana_1;
            call_count_1 = x_3_10046;
            goto kk__tailcall;
          }
        }
      }
    }
    {
      kk_string_drop(x_1_10040, _ctx);
      kk_string_drop(last_gana_1, _ctx);
      kk_integer_drop(call_count_1, _ctx);
      kk_Unit; return kk_Unit;
    }
  }
}

// initialization
void kk_src_resonance__init(kk_context_t* _ctx){
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
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_box_t _x_x268;
    kk_string_t _x_x269;
    kk_define_string_literal(, _s_x270, 9, "gana_horn", _ctx)
    _x_x269 = kk_string_dup(_s_x270, _ctx); /*string*/
    _x_x268 = kk_string_box(_x_x269); /*10021*/
    kk_std_core_types__list _x_x271;
    kk_box_t _x_x272;
    kk_string_t _x_x273;
    kk_define_string_literal(, _s_x274, 9, "gana_neck", _ctx)
    _x_x273 = kk_string_dup(_s_x274, _ctx); /*string*/
    _x_x272 = kk_string_box(_x_x273); /*10021*/
    kk_std_core_types__list _x_x275;
    kk_box_t _x_x276;
    kk_string_t _x_x277;
    kk_define_string_literal(, _s_x278, 9, "gana_root", _ctx)
    _x_x277 = kk_string_dup(_s_x278, _ctx); /*string*/
    _x_x276 = kk_string_box(_x_x277); /*10021*/
    kk_std_core_types__list _x_x279;
    kk_box_t _x_x280;
    kk_string_t _x_x281;
    kk_define_string_literal(, _s_x282, 9, "gana_room", _ctx)
    _x_x281 = kk_string_dup(_s_x282, _ctx); /*string*/
    _x_x280 = kk_string_box(_x_x281); /*10021*/
    kk_std_core_types__list _x_x283;
    kk_box_t _x_x284;
    kk_string_t _x_x285;
    kk_define_string_literal(, _s_x286, 10, "gana_heart", _ctx)
    _x_x285 = kk_string_dup(_s_x286, _ctx); /*string*/
    _x_x284 = kk_string_box(_x_x285); /*10021*/
    kk_std_core_types__list _x_x287;
    kk_box_t _x_x288;
    kk_string_t _x_x289;
    kk_define_string_literal(, _s_x290, 9, "gana_tail", _ctx)
    _x_x289 = kk_string_dup(_s_x290, _ctx); /*string*/
    _x_x288 = kk_string_box(_x_x289); /*10021*/
    kk_std_core_types__list _x_x291;
    kk_box_t _x_x292;
    kk_string_t _x_x293;
    kk_define_string_literal(, _s_x294, 21, "gana_winnowing_basket", _ctx)
    _x_x293 = kk_string_dup(_s_x294, _ctx); /*string*/
    _x_x292 = kk_string_box(_x_x293); /*10021*/
    kk_std_core_types__list _x_x295;
    kk_box_t _x_x296;
    kk_string_t _x_x297;
    kk_define_string_literal(, _s_x298, 10, "gana_ghost", _ctx)
    _x_x297 = kk_string_dup(_s_x298, _ctx); /*string*/
    _x_x296 = kk_string_box(_x_x297); /*10021*/
    kk_std_core_types__list _x_x299;
    kk_box_t _x_x300;
    kk_string_t _x_x301;
    kk_define_string_literal(, _s_x302, 11, "gana_willow", _ctx)
    _x_x301 = kk_string_dup(_s_x302, _ctx); /*string*/
    _x_x300 = kk_string_box(_x_x301); /*10021*/
    kk_std_core_types__list _x_x303;
    kk_box_t _x_x304;
    kk_string_t _x_x305;
    kk_define_string_literal(, _s_x306, 9, "gana_star", _ctx)
    _x_x305 = kk_string_dup(_s_x306, _ctx); /*string*/
    _x_x304 = kk_string_box(_x_x305); /*10021*/
    kk_std_core_types__list _x_x307;
    kk_box_t _x_x308;
    kk_string_t _x_x309;
    kk_define_string_literal(, _s_x310, 17, "gana_extended_net", _ctx)
    _x_x309 = kk_string_dup(_s_x310, _ctx); /*string*/
    _x_x308 = kk_string_box(_x_x309); /*10021*/
    kk_std_core_types__list _x_x311;
    kk_box_t _x_x312;
    kk_string_t _x_x313;
    kk_define_string_literal(, _s_x314, 10, "gana_wings", _ctx)
    _x_x313 = kk_string_dup(_s_x314, _ctx); /*string*/
    _x_x312 = kk_string_box(_x_x313); /*10021*/
    kk_std_core_types__list _x_x315;
    kk_box_t _x_x316;
    kk_string_t _x_x317;
    kk_define_string_literal(, _s_x318, 12, "gana_chariot", _ctx)
    _x_x317 = kk_string_dup(_s_x318, _ctx); /*string*/
    _x_x316 = kk_string_box(_x_x317); /*10021*/
    kk_std_core_types__list _x_x319;
    kk_box_t _x_x320;
    kk_string_t _x_x321;
    kk_define_string_literal(, _s_x322, 14, "gana_abundance", _ctx)
    _x_x321 = kk_string_dup(_s_x322, _ctx); /*string*/
    _x_x320 = kk_string_box(_x_x321); /*10021*/
    kk_std_core_types__list _x_x323;
    kk_box_t _x_x324;
    kk_string_t _x_x325;
    kk_define_string_literal(, _s_x326, 20, "gana_straddling_legs", _ctx)
    _x_x325 = kk_string_dup(_s_x326, _ctx); /*string*/
    _x_x324 = kk_string_box(_x_x325); /*10021*/
    kk_std_core_types__list _x_x327;
    kk_box_t _x_x328;
    kk_string_t _x_x329;
    kk_define_string_literal(, _s_x330, 10, "gana_mound", _ctx)
    _x_x329 = kk_string_dup(_s_x330, _ctx); /*string*/
    _x_x328 = kk_string_box(_x_x329); /*10021*/
    kk_std_core_types__list _x_x331;
    kk_box_t _x_x332;
    kk_string_t _x_x333;
    kk_define_string_literal(, _s_x334, 12, "gana_stomach", _ctx)
    _x_x333 = kk_string_dup(_s_x334, _ctx); /*string*/
    _x_x332 = kk_string_box(_x_x333); /*10021*/
    kk_std_core_types__list _x_x335;
    kk_box_t _x_x336;
    kk_string_t _x_x337;
    kk_define_string_literal(, _s_x338, 15, "gana_hairy_head", _ctx)
    _x_x337 = kk_string_dup(_s_x338, _ctx); /*string*/
    _x_x336 = kk_string_box(_x_x337); /*10021*/
    kk_std_core_types__list _x_x339;
    kk_box_t _x_x340;
    kk_string_t _x_x341;
    kk_define_string_literal(, _s_x342, 8, "gana_net", _ctx)
    _x_x341 = kk_string_dup(_s_x342, _ctx); /*string*/
    _x_x340 = kk_string_box(_x_x341); /*10021*/
    kk_std_core_types__list _x_x343;
    kk_box_t _x_x344;
    kk_string_t _x_x345;
    kk_define_string_literal(, _s_x346, 16, "gana_turtle_beak", _ctx)
    _x_x345 = kk_string_dup(_s_x346, _ctx); /*string*/
    _x_x344 = kk_string_box(_x_x345); /*10021*/
    kk_std_core_types__list _x_x347;
    kk_box_t _x_x348;
    kk_string_t _x_x349;
    kk_define_string_literal(, _s_x350, 16, "gana_three_stars", _ctx)
    _x_x349 = kk_string_dup(_s_x350, _ctx); /*string*/
    _x_x348 = kk_string_box(_x_x349); /*10021*/
    kk_std_core_types__list _x_x351;
    kk_box_t _x_x352;
    kk_string_t _x_x353;
    kk_define_string_literal(, _s_x354, 11, "gana_dipper", _ctx)
    _x_x353 = kk_string_dup(_s_x354, _ctx); /*string*/
    _x_x352 = kk_string_box(_x_x353); /*10021*/
    kk_std_core_types__list _x_x355;
    kk_box_t _x_x356;
    kk_string_t _x_x357;
    kk_define_string_literal(, _s_x358, 7, "gana_ox", _ctx)
    _x_x357 = kk_string_dup(_s_x358, _ctx); /*string*/
    _x_x356 = kk_string_box(_x_x357); /*10021*/
    kk_std_core_types__list _x_x359;
    kk_box_t _x_x360;
    kk_string_t _x_x361;
    kk_define_string_literal(, _s_x362, 9, "gana_girl", _ctx)
    _x_x361 = kk_string_dup(_s_x362, _ctx); /*string*/
    _x_x360 = kk_string_box(_x_x361); /*10021*/
    kk_std_core_types__list _x_x363;
    kk_box_t _x_x364;
    kk_string_t _x_x365;
    kk_define_string_literal(, _s_x366, 9, "gana_void", _ctx)
    _x_x365 = kk_string_dup(_s_x366, _ctx); /*string*/
    _x_x364 = kk_string_box(_x_x365); /*10021*/
    kk_std_core_types__list _x_x367;
    kk_box_t _x_x368;
    kk_string_t _x_x369;
    kk_define_string_literal(, _s_x370, 9, "gana_roof", _ctx)
    _x_x369 = kk_string_dup(_s_x370, _ctx); /*string*/
    _x_x368 = kk_string_box(_x_x369); /*10021*/
    kk_std_core_types__list _x_x371;
    kk_box_t _x_x372;
    kk_string_t _x_x373;
    kk_define_string_literal(, _s_x374, 15, "gana_encampment", _ctx)
    _x_x373 = kk_string_dup(_s_x374, _ctx); /*string*/
    _x_x372 = kk_string_box(_x_x373); /*10021*/
    kk_std_core_types__list _x_x375;
    kk_box_t _x_x376;
    kk_string_t _x_x377;
    kk_define_string_literal(, _s_x378, 9, "gana_wall", _ctx)
    _x_x377 = kk_string_dup(_s_x378, _ctx); /*string*/
    _x_x376 = kk_string_box(_x_x377); /*10021*/
    _x_x375 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x376, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x371 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x372, _x_x375, _ctx); /*list<10021>*/
    _x_x367 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x368, _x_x371, _ctx); /*list<10021>*/
    _x_x363 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x364, _x_x367, _ctx); /*list<10021>*/
    _x_x359 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x360, _x_x363, _ctx); /*list<10021>*/
    _x_x355 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x356, _x_x359, _ctx); /*list<10021>*/
    _x_x351 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x352, _x_x355, _ctx); /*list<10021>*/
    _x_x347 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x348, _x_x351, _ctx); /*list<10021>*/
    _x_x343 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x344, _x_x347, _ctx); /*list<10021>*/
    _x_x339 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x340, _x_x343, _ctx); /*list<10021>*/
    _x_x335 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x336, _x_x339, _ctx); /*list<10021>*/
    _x_x331 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x332, _x_x335, _ctx); /*list<10021>*/
    _x_x327 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x328, _x_x331, _ctx); /*list<10021>*/
    _x_x323 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x324, _x_x327, _ctx); /*list<10021>*/
    _x_x319 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x320, _x_x323, _ctx); /*list<10021>*/
    _x_x315 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x316, _x_x319, _ctx); /*list<10021>*/
    _x_x311 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x312, _x_x315, _ctx); /*list<10021>*/
    _x_x307 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x308, _x_x311, _ctx); /*list<10021>*/
    _x_x303 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x304, _x_x307, _ctx); /*list<10021>*/
    _x_x299 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x300, _x_x303, _ctx); /*list<10021>*/
    _x_x295 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x296, _x_x299, _ctx); /*list<10021>*/
    _x_x291 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x292, _x_x295, _ctx); /*list<10021>*/
    _x_x287 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x288, _x_x291, _ctx); /*list<10021>*/
    _x_x283 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x284, _x_x287, _ctx); /*list<10021>*/
    _x_x279 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x280, _x_x283, _ctx); /*list<10021>*/
    _x_x275 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x276, _x_x279, _ctx); /*list<10021>*/
    _x_x271 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x272, _x_x275, _ctx); /*list<10021>*/
    kk_src_resonance_gana_order = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x268, _x_x271, _ctx); /*list<string>*/
  }
}

// termination
void kk_src_resonance__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_types__list_drop(kk_src_resonance_gana_order, _ctx);
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
