// Koka generated module: src/circuit, koka version: 3.2.2, platform: 64-bit
#include "src_circuit.h"

kk_string_t kk_src_circuit_check_state(kk_src_circuit__circuit_state st, kk_integer_t failures, kk_integer_t successes, kk_integer_t tick, kk_integer_t last_fail, kk_context_t* _ctx) { /* (st : circuit-state, failures : int, successes : int, tick : int, last-fail : int) -> string */ 
  if (kk_src_circuit__is_Closed(st, _ctx)) {
    kk_integer_drop(tick, _ctx);
    kk_integer_drop(successes, _ctx);
    kk_integer_drop(last_fail, _ctx);
    bool _match_x98;
    bool _brw_x99 = kk_integer_gte_borrow(failures,(kk_integer_from_small(5)),kk_context()); /*bool*/;
    kk_integer_drop(failures, _ctx);
    _match_x98 = _brw_x99; /*bool*/
    if (_match_x98) {
      kk_define_string_literal(, _s_x103, 4, "open", _ctx)
      return kk_string_dup(_s_x103, _ctx);
    }
    {
      kk_define_string_literal(, _s_x104, 6, "closed", _ctx)
      return kk_string_dup(_s_x104, _ctx);
    }
  }
  if (kk_src_circuit__is_Open(st, _ctx)) {
    kk_integer_drop(successes, _ctx);
    kk_integer_drop(failures, _ctx);
    kk_integer_t elapsed = kk_integer_sub(tick,last_fail,kk_context()); /*int*/;
    bool _match_x95;
    kk_integer_t _brw_x96 = kk_integer_from_int(30000, _ctx); /*int*/;
    bool _brw_x97 = kk_integer_gt_borrow(elapsed,_brw_x96,kk_context()); /*bool*/;
    kk_integer_drop(elapsed, _ctx);
    kk_integer_drop(_brw_x96, _ctx);
    _match_x95 = _brw_x97; /*bool*/
    if (_match_x95) {
      kk_define_string_literal(, _s_x105, 9, "half-open", _ctx)
      return kk_string_dup(_s_x105, _ctx);
    }
    {
      kk_define_string_literal(, _s_x106, 4, "open", _ctx)
      return kk_string_dup(_s_x106, _ctx);
    }
  }
  {
    kk_integer_drop(tick, _ctx);
    kk_integer_drop(last_fail, _ctx);
    kk_integer_drop(failures, _ctx);
    bool _match_x93;
    bool _brw_x94 = kk_integer_gte_borrow(successes,(kk_integer_from_small(3)),kk_context()); /*bool*/;
    kk_integer_drop(successes, _ctx);
    _match_x93 = _brw_x94; /*bool*/
    if (_match_x93) {
      kk_define_string_literal(, _s_x107, 6, "closed", _ctx)
      return kk_string_dup(_s_x107, _ctx);
    }
    {
      kk_define_string_literal(, _s_x108, 9, "half-open", _ctx)
      return kk_string_dup(_s_x108, _ctx);
    }
  }
}

kk_string_t kk_src_circuit_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x87;
  kk_string_t _x_x109 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x110 = kk_string_empty(); /*string*/
  _match_x87 = kk_string_is_eq(_x_x109,_x_x110,kk_context()); /*bool*/
  if (_match_x87) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x112, 7, "unknown", _ctx)
    return kk_string_dup(_s_x112, _ctx);
  }
  {
    bool _match_x88;
    kk_string_t _x_x113 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x114;
    kk_define_string_literal(, _s_x115, 7, "\"check\"", _ctx)
    _x_x114 = kk_string_dup(_s_x115, _ctx); /*string*/
    _match_x88 = kk_string_contains(_x_x113,_x_x114,kk_context()); /*bool*/
    if (_match_x88) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x116, 5, "check", _ctx)
      return kk_string_dup(_s_x116, _ctx);
    }
    {
      bool _match_x89;
      kk_string_t _x_x117 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x118;
      kk_define_string_literal(, _s_x119, 9, "\"success\"", _ctx)
      _x_x118 = kk_string_dup(_s_x119, _ctx); /*string*/
      _match_x89 = kk_string_contains(_x_x117,_x_x118,kk_context()); /*bool*/
      if (_match_x89) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x120, 7, "success", _ctx)
        return kk_string_dup(_s_x120, _ctx);
      }
      {
        bool _match_x90;
        kk_string_t _x_x121 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x122;
        kk_define_string_literal(, _s_x123, 9, "\"failure\"", _ctx)
        _x_x122 = kk_string_dup(_s_x123, _ctx); /*string*/
        _match_x90 = kk_string_contains(_x_x121,_x_x122,kk_context()); /*bool*/
        if (_match_x90) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x124, 7, "failure", _ctx)
          return kk_string_dup(_s_x124, _ctx);
        }
        {
          bool _match_x91;
          kk_string_t _x_x125 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x126;
          kk_define_string_literal(, _s_x127, 7, "\"reset\"", _ctx)
          _x_x126 = kk_string_dup(_s_x127, _ctx); /*string*/
          _match_x91 = kk_string_contains(_x_x125,_x_x126,kk_context()); /*bool*/
          if (_match_x91) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x128, 5, "reset", _ctx)
            return kk_string_dup(_s_x128, _ctx);
          }
          {
            bool _match_x92;
            kk_string_t _x_x129;
            kk_define_string_literal(, _s_x130, 8, "\"status\"", _ctx)
            _x_x129 = kk_string_dup(_s_x130, _ctx); /*string*/
            _match_x92 = kk_string_contains(line,_x_x129,kk_context()); /*bool*/
            if (_match_x92) {
              kk_define_string_literal(, _s_x131, 6, "status", _ctx)
              return kk_string_dup(_s_x131, _ctx);
            }
            {
              kk_define_string_literal(, _s_x132, 7, "unknown", _ctx)
              return kk_string_dup(_s_x132, _ctx);
            }
          }
        }
      }
    }
  }
}

kk_unit_t kk_src_circuit_flush_stdout(kk_context_t* _ctx) { /* () -> console/console () */ 
  fflush(stdout); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_src_circuit__mlift_server_loop_10035_fun134__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_circuit__mlift_server_loop_10035_fun134(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_circuit__new_mlift_server_loop_10035_fun134(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_circuit__mlift_server_loop_10035_fun134, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_circuit__mlift_server_loop_10035_fun134(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x135 = kk_Unit;
  kk_src_circuit_flush_stdout(_ctx);
  return kk_unit_box(_x_x135);
}

kk_unit_t kk_src_circuit__mlift_server_loop_10035(kk_string_t _c_x10003, kk_src_circuit__circuit_state _c_x10006, kk_integer_t _c_x10007, kk_integer_t last_fail, kk_integer_t new_tick, kk_string_t op, kk_integer_t total, kk_integer_t _c_x10008, kk_context_t* _ctx) { /* (string, circuit-state, int, last-fail : int, new-tick : int, op : string, total : int, int) -> () */ 
  kk_integer_t next_total = kk_integer_add_small_const(total, 1, _ctx); /*int*/;
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10003, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x133 = kk_std_core_hnd__open_none0(kk_src_circuit__new_mlift_server_loop_10035_fun134(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x133);
  kk_integer_t _x_x136 = kk_integer_dup(new_tick, _ctx); /*int*/
  kk_integer_t _x_x137;
  if (kk_string_cmp_cstr_borrow(op, "failure", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_integer_drop(last_fail, _ctx);
    _x_x137 = new_tick; /*int*/
    goto _match_x138;
  }
  if (kk_string_cmp_cstr_borrow(op, "reset", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_integer_drop(new_tick, _ctx);
    kk_integer_drop(last_fail, _ctx);
    _x_x137 = kk_integer_from_small(0); /*int*/
    goto _match_x138;
  }
  {
    kk_string_drop(op, _ctx);
    kk_integer_drop(new_tick, _ctx);
    _x_x137 = last_fail; /*int*/
  }
  _match_x138: ;
  kk_src_circuit_server_loop(_x_x136, _c_x10006, _c_x10007, _c_x10008, _x_x137, next_total, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_src_circuit__mlift_server_loop_10036_fun141__t {
  struct kk_function_s _base;
  kk_string_t _c_x10003_0;
  kk_integer_t _c_x10007_0;
  kk_integer_t last_fail_0;
  kk_integer_t new_tick_0;
  kk_string_t op_0;
  kk_integer_t total_0;
  kk_src_circuit__circuit_state _c_x10006_0;
};
static kk_box_t kk_src_circuit__mlift_server_loop_10036_fun141(kk_function_t _fself, kk_box_t _b_x3, kk_context_t* _ctx);
static kk_function_t kk_src_circuit__new_mlift_server_loop_10036_fun141(kk_string_t _c_x10003_0, kk_integer_t _c_x10007_0, kk_integer_t last_fail_0, kk_integer_t new_tick_0, kk_string_t op_0, kk_integer_t total_0, kk_src_circuit__circuit_state _c_x10006_0, kk_context_t* _ctx) {
  struct kk_src_circuit__mlift_server_loop_10036_fun141__t* _self = kk_function_alloc_as(struct kk_src_circuit__mlift_server_loop_10036_fun141__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_circuit__mlift_server_loop_10036_fun141, kk_context());
  _self->_c_x10003_0 = _c_x10003_0;
  _self->_c_x10007_0 = _c_x10007_0;
  _self->last_fail_0 = last_fail_0;
  _self->new_tick_0 = new_tick_0;
  _self->op_0 = op_0;
  _self->total_0 = total_0;
  _self->_c_x10006_0 = _c_x10006_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_circuit__mlift_server_loop_10036_fun141(kk_function_t _fself, kk_box_t _b_x3, kk_context_t* _ctx) {
  struct kk_src_circuit__mlift_server_loop_10036_fun141__t* _self = kk_function_as(struct kk_src_circuit__mlift_server_loop_10036_fun141__t*, _fself, _ctx);
  kk_string_t _c_x10003_0 = _self->_c_x10003_0; /* string */
  kk_integer_t _c_x10007_0 = _self->_c_x10007_0; /* int */
  kk_integer_t last_fail_0 = _self->last_fail_0; /* int */
  kk_integer_t new_tick_0 = _self->new_tick_0; /* int */
  kk_string_t op_0 = _self->op_0; /* string */
  kk_integer_t total_0 = _self->total_0; /* int */
  kk_src_circuit__circuit_state _c_x10006_0 = _self->_c_x10006_0; /* src/circuit/circuit-state */
  kk_drop_match(_self, {kk_string_dup(_c_x10003_0, _ctx);kk_integer_dup(_c_x10007_0, _ctx);kk_integer_dup(last_fail_0, _ctx);kk_integer_dup(new_tick_0, _ctx);kk_string_dup(op_0, _ctx);kk_integer_dup(total_0, _ctx);kk_src_circuit__circuit_state_dup(_c_x10006_0, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10008_0_5 = kk_integer_unbox(_b_x3, _ctx); /*int*/;
  kk_unit_t _x_x142 = kk_Unit;
  kk_src_circuit__mlift_server_loop_10035(_c_x10003_0, _c_x10006_0, _c_x10007_0, last_fail_0, new_tick_0, op_0, total_0, _c_x10008_0_5, _ctx);
  return kk_unit_box(_x_x142);
}

kk_unit_t kk_src_circuit__mlift_server_loop_10036(kk_string_t _c_x10003_0, kk_src_circuit__circuit_state _c_x10006_0, kk_integer_t last_fail_0, kk_integer_t new_tick_0, kk_string_t op_0, kk_integer_t successes, kk_integer_t total_0, kk_integer_t _c_x10007_0, kk_context_t* _ctx) { /* (string, circuit-state, last-fail : int, new-tick : int, op : string, successes : int, total : int, int) -> () */ 
  kk_integer_t x_10040;
  if (kk_string_cmp_cstr_borrow(op_0, "success", _ctx) == 0) {
    x_10040 = kk_integer_add_small_const(successes, 1, _ctx); /*int*/
    goto _match_x139;
  }
  if (kk_string_cmp_cstr_borrow(op_0, "failure", _ctx) == 0) {
    kk_integer_drop(successes, _ctx);
    x_10040 = kk_integer_from_small(0); /*int*/
    goto _match_x139;
  }
  if (kk_string_cmp_cstr_borrow(op_0, "reset", _ctx) == 0) {
    kk_integer_drop(successes, _ctx);
    x_10040 = kk_integer_from_small(0); /*int*/
    goto _match_x139;
  }
  {
    x_10040 = successes; /*int*/
  }
  _match_x139: ;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10040, _ctx);
    kk_box_t _x_x140 = kk_std_core_hnd_yield_extend(kk_src_circuit__new_mlift_server_loop_10036_fun141(_c_x10003_0, _c_x10007_0, last_fail_0, new_tick_0, op_0, total_0, _c_x10006_0, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x140); return kk_Unit;
  }
  {
    kk_src_circuit__mlift_server_loop_10035(_c_x10003_0, _c_x10006_0, _c_x10007_0, last_fail_0, new_tick_0, op_0, total_0, x_10040, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_circuit__mlift_server_loop_10037_fun145__t {
  struct kk_function_s _base;
  kk_string_t _c_x10003_1;
  kk_integer_t last_fail_1;
  kk_integer_t new_tick_1;
  kk_string_t op_1;
  kk_integer_t successes_0;
  kk_integer_t total_1;
  kk_src_circuit__circuit_state _c_x10006_1;
};
static kk_box_t kk_src_circuit__mlift_server_loop_10037_fun145(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_src_circuit__new_mlift_server_loop_10037_fun145(kk_string_t _c_x10003_1, kk_integer_t last_fail_1, kk_integer_t new_tick_1, kk_string_t op_1, kk_integer_t successes_0, kk_integer_t total_1, kk_src_circuit__circuit_state _c_x10006_1, kk_context_t* _ctx) {
  struct kk_src_circuit__mlift_server_loop_10037_fun145__t* _self = kk_function_alloc_as(struct kk_src_circuit__mlift_server_loop_10037_fun145__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_circuit__mlift_server_loop_10037_fun145, kk_context());
  _self->_c_x10003_1 = _c_x10003_1;
  _self->last_fail_1 = last_fail_1;
  _self->new_tick_1 = new_tick_1;
  _self->op_1 = op_1;
  _self->successes_0 = successes_0;
  _self->total_1 = total_1;
  _self->_c_x10006_1 = _c_x10006_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_circuit__mlift_server_loop_10037_fun145(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  struct kk_src_circuit__mlift_server_loop_10037_fun145__t* _self = kk_function_as(struct kk_src_circuit__mlift_server_loop_10037_fun145__t*, _fself, _ctx);
  kk_string_t _c_x10003_1 = _self->_c_x10003_1; /* string */
  kk_integer_t last_fail_1 = _self->last_fail_1; /* int */
  kk_integer_t new_tick_1 = _self->new_tick_1; /* int */
  kk_string_t op_1 = _self->op_1; /* string */
  kk_integer_t successes_0 = _self->successes_0; /* int */
  kk_integer_t total_1 = _self->total_1; /* int */
  kk_src_circuit__circuit_state _c_x10006_1 = _self->_c_x10006_1; /* src/circuit/circuit-state */
  kk_drop_match(_self, {kk_string_dup(_c_x10003_1, _ctx);kk_integer_dup(last_fail_1, _ctx);kk_integer_dup(new_tick_1, _ctx);kk_string_dup(op_1, _ctx);kk_integer_dup(successes_0, _ctx);kk_integer_dup(total_1, _ctx);kk_src_circuit__circuit_state_dup(_c_x10006_1, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10007_1_9 = kk_integer_unbox(_b_x7, _ctx); /*int*/;
  kk_unit_t _x_x146 = kk_Unit;
  kk_src_circuit__mlift_server_loop_10036(_c_x10003_1, _c_x10006_1, last_fail_1, new_tick_1, op_1, successes_0, total_1, _c_x10007_1_9, _ctx);
  return kk_unit_box(_x_x146);
}

kk_unit_t kk_src_circuit__mlift_server_loop_10037(kk_string_t _c_x10003_1, kk_integer_t failures, kk_integer_t last_fail_1, kk_integer_t new_tick_1, kk_string_t op_1, kk_integer_t successes_0, kk_integer_t total_1, kk_src_circuit__circuit_state _c_x10006_1, kk_context_t* _ctx) { /* (string, failures : int, last-fail : int, new-tick : int, op : string, successes : int, total : int, circuit-state) -> () */ 
  kk_integer_t x_0_10042;
  if (kk_string_cmp_cstr_borrow(op_1, "success", _ctx) == 0) {
    kk_integer_drop(failures, _ctx);
    x_0_10042 = kk_integer_from_small(0); /*int*/
    goto _match_x143;
  }
  if (kk_string_cmp_cstr_borrow(op_1, "failure", _ctx) == 0) {
    x_0_10042 = kk_integer_add_small_const(failures, 1, _ctx); /*int*/
    goto _match_x143;
  }
  if (kk_string_cmp_cstr_borrow(op_1, "reset", _ctx) == 0) {
    kk_integer_drop(failures, _ctx);
    x_0_10042 = kk_integer_from_small(0); /*int*/
    goto _match_x143;
  }
  {
    x_0_10042 = failures; /*int*/
  }
  _match_x143: ;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_0_10042, _ctx);
    kk_box_t _x_x144 = kk_std_core_hnd_yield_extend(kk_src_circuit__new_mlift_server_loop_10037_fun145(_c_x10003_1, last_fail_1, new_tick_1, op_1, successes_0, total_1, _c_x10006_1, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x144); return kk_Unit;
  }
  {
    kk_src_circuit__mlift_server_loop_10036(_c_x10003_1, _c_x10006_1, last_fail_1, new_tick_1, op_1, successes_0, total_1, x_0_10042, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_circuit__mlift_server_loop_10038_fun151__t {
  struct kk_function_s _base;
  kk_string_t _c_x10003_2;
  kk_integer_t failures_0;
  kk_integer_t last_fail_2;
  kk_integer_t new_tick_2;
  kk_string_t op_2;
  kk_integer_t successes_1;
  kk_integer_t total_2;
};
static kk_box_t kk_src_circuit__mlift_server_loop_10038_fun151(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx);
static kk_function_t kk_src_circuit__new_mlift_server_loop_10038_fun151(kk_string_t _c_x10003_2, kk_integer_t failures_0, kk_integer_t last_fail_2, kk_integer_t new_tick_2, kk_string_t op_2, kk_integer_t successes_1, kk_integer_t total_2, kk_context_t* _ctx) {
  struct kk_src_circuit__mlift_server_loop_10038_fun151__t* _self = kk_function_alloc_as(struct kk_src_circuit__mlift_server_loop_10038_fun151__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_circuit__mlift_server_loop_10038_fun151, kk_context());
  _self->_c_x10003_2 = _c_x10003_2;
  _self->failures_0 = failures_0;
  _self->last_fail_2 = last_fail_2;
  _self->new_tick_2 = new_tick_2;
  _self->op_2 = op_2;
  _self->successes_1 = successes_1;
  _self->total_2 = total_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_circuit__mlift_server_loop_10038_fun151(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx) {
  struct kk_src_circuit__mlift_server_loop_10038_fun151__t* _self = kk_function_as(struct kk_src_circuit__mlift_server_loop_10038_fun151__t*, _fself, _ctx);
  kk_string_t _c_x10003_2 = _self->_c_x10003_2; /* string */
  kk_integer_t failures_0 = _self->failures_0; /* int */
  kk_integer_t last_fail_2 = _self->last_fail_2; /* int */
  kk_integer_t new_tick_2 = _self->new_tick_2; /* int */
  kk_string_t op_2 = _self->op_2; /* string */
  kk_integer_t successes_1 = _self->successes_1; /* int */
  kk_integer_t total_2 = _self->total_2; /* int */
  kk_drop_match(_self, {kk_string_dup(_c_x10003_2, _ctx);kk_integer_dup(failures_0, _ctx);kk_integer_dup(last_fail_2, _ctx);kk_integer_dup(new_tick_2, _ctx);kk_string_dup(op_2, _ctx);kk_integer_dup(successes_1, _ctx);kk_integer_dup(total_2, _ctx);}, {}, _ctx)
  kk_src_circuit__circuit_state _c_x10006_2_13 = kk_src_circuit__circuit_state_unbox(_b_x11, KK_OWNED, _ctx); /*src/circuit/circuit-state*/;
  kk_unit_t _x_x152 = kk_Unit;
  kk_src_circuit__mlift_server_loop_10037(_c_x10003_2, failures_0, last_fail_2, new_tick_2, op_2, successes_1, total_2, _c_x10006_2_13, _ctx);
  return kk_unit_box(_x_x152);
}

kk_unit_t kk_src_circuit__mlift_server_loop_10038(kk_integer_t failures_0, kk_integer_t last_fail_2, kk_integer_t new_tick_2, kk_string_t op_2, kk_src_circuit__circuit_state st, kk_integer_t successes_1, kk_integer_t total_2, kk_string_t _c_x10003_2, kk_context_t* _ctx) { /* (failures : int, last-fail : int, new-tick : int, op : string, st : circuit-state, successes : int, total : int, string) -> () */ 
  kk_src_circuit__circuit_state x_1_10044;
  if (kk_string_cmp_cstr_borrow(op_2, "success", _ctx) == 0) {
    if (kk_src_circuit__is_HalfOpen(st, _ctx)) {
      kk_integer_t new_s;
      kk_integer_t _x_x148 = kk_integer_dup(successes_1, _ctx); /*int*/
      new_s = kk_integer_add_small_const(_x_x148, 1, _ctx); /*int*/
      bool _match_x83;
      bool _brw_x84 = kk_integer_gte_borrow(new_s,(kk_integer_from_small(3)),kk_context()); /*bool*/;
      kk_integer_drop(new_s, _ctx);
      _match_x83 = _brw_x84; /*bool*/
      if (_match_x83) {
        x_1_10044 = kk_src_circuit__new_Closed(_ctx); /*src/circuit/circuit-state*/
        goto _match_x147;
      }
      {
        x_1_10044 = kk_src_circuit__new_HalfOpen(_ctx); /*src/circuit/circuit-state*/
        goto _match_x147;
      }
    }
    {
      x_1_10044 = st; /*src/circuit/circuit-state*/
      goto _match_x147;
    }
  }
  if (kk_string_cmp_cstr_borrow(op_2, "failure", _ctx) == 0) {
    if (kk_src_circuit__is_Closed(st, _ctx)) {
      kk_integer_t new_f;
      kk_integer_t _x_x149 = kk_integer_dup(failures_0, _ctx); /*int*/
      new_f = kk_integer_add_small_const(_x_x149, 1, _ctx); /*int*/
      bool _match_x81;
      bool _brw_x82 = kk_integer_gte_borrow(new_f,(kk_integer_from_small(5)),kk_context()); /*bool*/;
      kk_integer_drop(new_f, _ctx);
      _match_x81 = _brw_x82; /*bool*/
      if (_match_x81) {
        x_1_10044 = kk_src_circuit__new_Open(_ctx); /*src/circuit/circuit-state*/
        goto _match_x147;
      }
      {
        x_1_10044 = kk_src_circuit__new_Closed(_ctx); /*src/circuit/circuit-state*/
        goto _match_x147;
      }
    }
    if (kk_src_circuit__is_HalfOpen(st, _ctx)) {
      x_1_10044 = kk_src_circuit__new_Open(_ctx); /*src/circuit/circuit-state*/
      goto _match_x147;
    }
    {
      x_1_10044 = st; /*src/circuit/circuit-state*/
      goto _match_x147;
    }
  }
  if (kk_string_cmp_cstr_borrow(op_2, "reset", _ctx) == 0) {
    x_1_10044 = kk_src_circuit__new_Closed(_ctx); /*src/circuit/circuit-state*/
    goto _match_x147;
  }
  {
    x_1_10044 = st; /*src/circuit/circuit-state*/
  }
  _match_x147: ;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x150 = kk_std_core_hnd_yield_extend(kk_src_circuit__new_mlift_server_loop_10038_fun151(_c_x10003_2, failures_0, last_fail_2, new_tick_2, op_2, successes_1, total_2, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x150); return kk_Unit;
  }
  {
    kk_src_circuit__mlift_server_loop_10037(_c_x10003_2, failures_0, last_fail_2, new_tick_2, op_2, successes_1, total_2, x_1_10044, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_circuit__mlift_server_loop_10039_fun157__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_circuit__mlift_server_loop_10039_fun157(kk_function_t _fself, kk_box_t _b_x16, kk_context_t* _ctx);
static kk_function_t kk_src_circuit__new_mlift_server_loop_10039_fun157(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_circuit__mlift_server_loop_10039_fun157, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_circuit__mlift_server_loop_10039_fun157(kk_function_t _fself, kk_box_t _b_x16, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x158;
  kk_string_t _x_x159 = kk_string_unbox(_b_x16); /*string*/
  _x_x158 = kk_src_circuit_extract_op(_x_x159, _ctx); /*string*/
  return kk_string_box(_x_x158);
}


// lift anonymous function
struct kk_src_circuit__mlift_server_loop_10039_fun167__t {
  struct kk_function_s _base;
  kk_integer_t failures_1;
  kk_integer_t last_fail_3;
  kk_integer_t new_tick_3;
  kk_integer_t successes_2;
  kk_src_circuit__circuit_state st_0;
};
static kk_box_t kk_src_circuit__mlift_server_loop_10039_fun167(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_circuit__new_mlift_server_loop_10039_fun167(kk_integer_t failures_1, kk_integer_t last_fail_3, kk_integer_t new_tick_3, kk_integer_t successes_2, kk_src_circuit__circuit_state st_0, kk_context_t* _ctx) {
  struct kk_src_circuit__mlift_server_loop_10039_fun167__t* _self = kk_function_alloc_as(struct kk_src_circuit__mlift_server_loop_10039_fun167__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_circuit__mlift_server_loop_10039_fun167, kk_context());
  _self->failures_1 = failures_1;
  _self->last_fail_3 = last_fail_3;
  _self->new_tick_3 = new_tick_3;
  _self->successes_2 = successes_2;
  _self->st_0 = st_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_circuit__mlift_server_loop_10039_fun167(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_src_circuit__mlift_server_loop_10039_fun167__t* _self = kk_function_as(struct kk_src_circuit__mlift_server_loop_10039_fun167__t*, _fself, _ctx);
  kk_integer_t failures_1 = _self->failures_1; /* int */
  kk_integer_t last_fail_3 = _self->last_fail_3; /* int */
  kk_integer_t new_tick_3 = _self->new_tick_3; /* int */
  kk_integer_t successes_2 = _self->successes_2; /* int */
  kk_src_circuit__circuit_state st_0 = _self->st_0; /* src/circuit/circuit-state */
  kk_drop_match(_self, {kk_integer_dup(failures_1, _ctx);kk_integer_dup(last_fail_3, _ctx);kk_integer_dup(new_tick_3, _ctx);kk_integer_dup(successes_2, _ctx);kk_src_circuit__circuit_state_dup(st_0, _ctx);}, {}, _ctx)
  kk_string_t _x_x168 = kk_src_circuit_check_state(st_0, failures_1, successes_2, new_tick_3, last_fail_3, _ctx); /*string*/
  return kk_string_box(_x_x168);
}


// lift anonymous function
struct kk_src_circuit__mlift_server_loop_10039_fun183__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_circuit__mlift_server_loop_10039_fun183(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static kk_function_t kk_src_circuit__new_mlift_server_loop_10039_fun183(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_circuit__mlift_server_loop_10039_fun183, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_circuit__mlift_server_loop_10039_fun183(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x184;
  kk_src_circuit__circuit_state _match_x79 = kk_src_circuit__circuit_state_unbox(_b_x22, KK_OWNED, _ctx); /*src/circuit/circuit-state*/;
  if (kk_src_circuit__is_Closed(_match_x79, _ctx)) {
    kk_define_string_literal(, _s_x186, 6, "closed", _ctx)
    _x_x184 = kk_string_dup(_s_x186, _ctx); /*string*/
    goto _match_x185;
  }
  if (kk_src_circuit__is_Open(_match_x79, _ctx)) {
    kk_define_string_literal(, _s_x187, 4, "open", _ctx)
    _x_x184 = kk_string_dup(_s_x187, _ctx); /*string*/
    goto _match_x185;
  }
  {
    kk_define_string_literal(, _s_x188, 9, "half-open", _ctx)
    _x_x184 = kk_string_dup(_s_x188, _ctx); /*string*/
  }
  _match_x185: ;
  return kk_string_box(_x_x184);
}


// lift anonymous function
struct kk_src_circuit__mlift_server_loop_10039_fun217__t {
  struct kk_function_s _base;
  kk_integer_t failures_1;
  kk_integer_t last_fail_3;
  kk_integer_t new_tick_3;
  kk_string_t op_3;
  kk_integer_t successes_2;
  kk_integer_t total_3;
  kk_src_circuit__circuit_state st_0;
};
static kk_box_t kk_src_circuit__mlift_server_loop_10039_fun217(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_src_circuit__new_mlift_server_loop_10039_fun217(kk_integer_t failures_1, kk_integer_t last_fail_3, kk_integer_t new_tick_3, kk_string_t op_3, kk_integer_t successes_2, kk_integer_t total_3, kk_src_circuit__circuit_state st_0, kk_context_t* _ctx) {
  struct kk_src_circuit__mlift_server_loop_10039_fun217__t* _self = kk_function_alloc_as(struct kk_src_circuit__mlift_server_loop_10039_fun217__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_circuit__mlift_server_loop_10039_fun217, kk_context());
  _self->failures_1 = failures_1;
  _self->last_fail_3 = last_fail_3;
  _self->new_tick_3 = new_tick_3;
  _self->op_3 = op_3;
  _self->successes_2 = successes_2;
  _self->total_3 = total_3;
  _self->st_0 = st_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_circuit__mlift_server_loop_10039_fun217(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx) {
  struct kk_src_circuit__mlift_server_loop_10039_fun217__t* _self = kk_function_as(struct kk_src_circuit__mlift_server_loop_10039_fun217__t*, _fself, _ctx);
  kk_integer_t failures_1 = _self->failures_1; /* int */
  kk_integer_t last_fail_3 = _self->last_fail_3; /* int */
  kk_integer_t new_tick_3 = _self->new_tick_3; /* int */
  kk_string_t op_3 = _self->op_3; /* string */
  kk_integer_t successes_2 = _self->successes_2; /* int */
  kk_integer_t total_3 = _self->total_3; /* int */
  kk_src_circuit__circuit_state st_0 = _self->st_0; /* src/circuit/circuit-state */
  kk_drop_match(_self, {kk_integer_dup(failures_1, _ctx);kk_integer_dup(last_fail_3, _ctx);kk_integer_dup(new_tick_3, _ctx);kk_string_dup(op_3, _ctx);kk_integer_dup(successes_2, _ctx);kk_integer_dup(total_3, _ctx);kk_src_circuit__circuit_state_dup(st_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10003_3_30 = kk_string_unbox(_b_x27); /*string*/;
  kk_unit_t _x_x218 = kk_Unit;
  kk_src_circuit__mlift_server_loop_10038(failures_1, last_fail_3, new_tick_3, op_3, st_0, successes_2, total_3, _c_x10003_3_30, _ctx);
  return kk_unit_box(_x_x218);
}

kk_unit_t kk_src_circuit__mlift_server_loop_10039(kk_integer_t failures_1, kk_integer_t last_fail_3, kk_src_circuit__circuit_state st_0, kk_integer_t successes_2, kk_integer_t tick, kk_integer_t total_3, kk_string_t line, kk_context_t* _ctx) { /* (failures : int, last-fail : int, st : circuit-state, successes : int, tick : int, total : int, line : string) -> <console/console,exn> () */ 
  bool _match_x77;
  kk_string_t _x_x153 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x154 = kk_string_empty(); /*string*/
  _match_x77 = kk_string_is_neq(_x_x153,_x_x154,kk_context()); /*bool*/
  if (_match_x77) {
    kk_integer_t new_tick_3 = kk_integer_add_small_const(tick, 1, _ctx); /*int*/;
    kk_string_t op_3;
    kk_box_t _x_x156 = kk_std_core_hnd__open_none1(kk_src_circuit__new_mlift_server_loop_10039_fun157(_ctx), kk_string_box(line), _ctx); /*10001*/
    op_3 = kk_string_unbox(_x_x156); /*string*/
    kk_string_t x_2_10046;
    if (kk_string_cmp_cstr_borrow(op_3, "check", _ctx) == 0) {
      kk_string_t _x_x161;
      kk_define_string_literal(, _s_x162, 33, "{\"operation\": \"check\", \"state\": \"", _ctx)
      _x_x161 = kk_string_dup(_s_x162, _ctx); /*string*/
      kk_string_t _x_x163;
      kk_string_t _x_x164;
      kk_box_t _x_x165;
      kk_function_t _x_x166;
      kk_integer_dup(failures_1, _ctx);
      kk_integer_dup(last_fail_3, _ctx);
      kk_integer_dup(new_tick_3, _ctx);
      kk_integer_dup(successes_2, _ctx);
      _x_x166 = kk_src_circuit__new_mlift_server_loop_10039_fun167(failures_1, last_fail_3, new_tick_3, successes_2, st_0, _ctx); /*() -> 10001 10000*/
      _x_x165 = kk_std_core_hnd__open_none0(_x_x166, _ctx); /*10000*/
      _x_x164 = kk_string_unbox(_x_x165); /*string*/
      kk_string_t _x_x169;
      kk_define_string_literal(, _s_x170, 2, "\"}", _ctx)
      _x_x169 = kk_string_dup(_s_x170, _ctx); /*string*/
      _x_x163 = kk_std_core_types__lp__plus__plus__rp_(_x_x164, _x_x169, _ctx); /*string*/
      x_2_10046 = kk_std_core_types__lp__plus__plus__rp_(_x_x161, _x_x163, _ctx); /*string*/
      goto _match_x160;
    }
    if (kk_string_cmp_cstr_borrow(op_3, "success", _ctx) == 0) {
      if (kk_src_circuit__is_Closed(st_0, _ctx)) {
        kk_define_string_literal(, _s_x171, 40, "{\"operation\": \"success\", \"result\": \"ok\"}", _ctx)
        x_2_10046 = kk_string_dup(_s_x171, _ctx); /*string*/
        goto _match_x160;
      }
      if (kk_src_circuit__is_HalfOpen(st_0, _ctx)) {
        kk_define_string_literal(, _s_x172, 40, "{\"operation\": \"success\", \"result\": \"ok\"}", _ctx)
        x_2_10046 = kk_string_dup(_s_x172, _ctx); /*string*/
        goto _match_x160;
      }
      {
        kk_define_string_literal(, _s_x173, 40, "{\"operation\": \"success\", \"result\": \"ok\"}", _ctx)
        x_2_10046 = kk_string_dup(_s_x173, _ctx); /*string*/
        goto _match_x160;
      }
    }
    if (kk_string_cmp_cstr_borrow(op_3, "failure", _ctx) == 0) {
      if (kk_src_circuit__is_Closed(st_0, _ctx)) {
        kk_define_string_literal(, _s_x174, 40, "{\"operation\": \"failure\", \"result\": \"ok\"}", _ctx)
        x_2_10046 = kk_string_dup(_s_x174, _ctx); /*string*/
        goto _match_x160;
      }
      if (kk_src_circuit__is_HalfOpen(st_0, _ctx)) {
        kk_define_string_literal(, _s_x175, 40, "{\"operation\": \"failure\", \"result\": \"ok\"}", _ctx)
        x_2_10046 = kk_string_dup(_s_x175, _ctx); /*string*/
        goto _match_x160;
      }
      {
        kk_define_string_literal(, _s_x176, 40, "{\"operation\": \"failure\", \"result\": \"ok\"}", _ctx)
        x_2_10046 = kk_string_dup(_s_x176, _ctx); /*string*/
        goto _match_x160;
      }
    }
    if (kk_string_cmp_cstr_borrow(op_3, "reset", _ctx) == 0) {
      kk_define_string_literal(, _s_x177, 38, "{\"operation\": \"reset\", \"result\": \"ok\"}", _ctx)
      x_2_10046 = kk_string_dup(_s_x177, _ctx); /*string*/
      goto _match_x160;
    }
    if (kk_string_cmp_cstr_borrow(op_3, "status", _ctx) == 0) {
      kk_string_t _x_x178;
      kk_define_string_literal(, _s_x179, 11, "{\"state\": \"", _ctx)
      _x_x178 = kk_string_dup(_s_x179, _ctx); /*string*/
      kk_string_t _x_x180;
      kk_string_t _x_x181;
      kk_box_t _x_x182 = kk_std_core_hnd__open_none1(kk_src_circuit__new_mlift_server_loop_10039_fun183(_ctx), kk_src_circuit__circuit_state_box(st_0, _ctx), _ctx); /*10001*/
      _x_x181 = kk_string_unbox(_x_x182); /*string*/
      kk_string_t _x_x189;
      kk_string_t _x_x190;
      kk_define_string_literal(, _s_x191, 15, "\", \"failures\": ", _ctx)
      _x_x190 = kk_string_dup(_s_x191, _ctx); /*string*/
      kk_string_t _x_x192;
      kk_string_t _x_x193;
      kk_integer_t _x_x194 = kk_integer_dup(failures_1, _ctx); /*int*/
      _x_x193 = kk_std_core_int_show(_x_x194, _ctx); /*string*/
      kk_string_t _x_x195;
      kk_string_t _x_x196;
      kk_define_string_literal(, _s_x197, 15, ", \"successes\": ", _ctx)
      _x_x196 = kk_string_dup(_s_x197, _ctx); /*string*/
      kk_string_t _x_x198;
      kk_string_t _x_x199;
      kk_integer_t _x_x200 = kk_integer_dup(successes_2, _ctx); /*int*/
      _x_x199 = kk_std_core_int_show(_x_x200, _ctx); /*string*/
      kk_string_t _x_x201;
      kk_string_t _x_x202;
      kk_define_string_literal(, _s_x203, 17, ", \"total_calls\": ", _ctx)
      _x_x202 = kk_string_dup(_s_x203, _ctx); /*string*/
      kk_string_t _x_x204;
      kk_string_t _x_x205;
      kk_integer_t _x_x206 = kk_integer_dup(total_3, _ctx); /*int*/
      _x_x205 = kk_std_core_int_show(_x_x206, _ctx); /*string*/
      kk_string_t _x_x207;
      kk_string_t _x_x208;
      kk_define_string_literal(, _s_x209, 10, ", \"tick\": ", _ctx)
      _x_x208 = kk_string_dup(_s_x209, _ctx); /*string*/
      kk_string_t _x_x210;
      kk_string_t _x_x211;
      kk_integer_t _x_x212 = kk_integer_dup(new_tick_3, _ctx); /*int*/
      _x_x211 = kk_std_core_int_show(_x_x212, _ctx); /*string*/
      kk_string_t _x_x213;
      kk_define_string_literal(, _s_x214, 1, "}", _ctx)
      _x_x213 = kk_string_dup(_s_x214, _ctx); /*string*/
      _x_x210 = kk_std_core_types__lp__plus__plus__rp_(_x_x211, _x_x213, _ctx); /*string*/
      _x_x207 = kk_std_core_types__lp__plus__plus__rp_(_x_x208, _x_x210, _ctx); /*string*/
      _x_x204 = kk_std_core_types__lp__plus__plus__rp_(_x_x205, _x_x207, _ctx); /*string*/
      _x_x201 = kk_std_core_types__lp__plus__plus__rp_(_x_x202, _x_x204, _ctx); /*string*/
      _x_x198 = kk_std_core_types__lp__plus__plus__rp_(_x_x199, _x_x201, _ctx); /*string*/
      _x_x195 = kk_std_core_types__lp__plus__plus__rp_(_x_x196, _x_x198, _ctx); /*string*/
      _x_x192 = kk_std_core_types__lp__plus__plus__rp_(_x_x193, _x_x195, _ctx); /*string*/
      _x_x189 = kk_std_core_types__lp__plus__plus__rp_(_x_x190, _x_x192, _ctx); /*string*/
      _x_x180 = kk_std_core_types__lp__plus__plus__rp_(_x_x181, _x_x189, _ctx); /*string*/
      x_2_10046 = kk_std_core_types__lp__plus__plus__rp_(_x_x178, _x_x180, _ctx); /*string*/
      goto _match_x160;
    }
    {
      kk_define_string_literal(, _s_x215, 30, "{\"error\": \"unknown_operation\"}", _ctx)
      x_2_10046 = kk_string_dup(_s_x215, _ctx); /*string*/
    }
    _match_x160: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_2_10046, _ctx);
      kk_box_t _x_x216 = kk_std_core_hnd_yield_extend(kk_src_circuit__new_mlift_server_loop_10039_fun217(failures_1, last_fail_3, new_tick_3, op_3, successes_2, total_3, st_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x216); return kk_Unit;
    }
    {
      kk_src_circuit__mlift_server_loop_10038(failures_1, last_fail_3, new_tick_3, op_3, st_0, successes_2, total_3, x_2_10046, _ctx); return kk_Unit;
    }
  }
  {
    kk_integer_drop(total_3, _ctx);
    kk_integer_drop(tick, _ctx);
    kk_integer_drop(successes_2, _ctx);
    kk_string_drop(line, _ctx);
    kk_integer_drop(last_fail_3, _ctx);
    kk_integer_drop(failures_1, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_src_circuit_server_loop_fun220__t {
  struct kk_function_s _base;
  kk_integer_t failures_2;
  kk_integer_t last_fail_4;
  kk_integer_t successes_3;
  kk_integer_t tick_0;
  kk_integer_t total_4;
  kk_src_circuit__circuit_state st_1;
};
static kk_box_t kk_src_circuit_server_loop_fun220(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx);
static kk_function_t kk_src_circuit_new_server_loop_fun220(kk_integer_t failures_2, kk_integer_t last_fail_4, kk_integer_t successes_3, kk_integer_t tick_0, kk_integer_t total_4, kk_src_circuit__circuit_state st_1, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun220__t* _self = kk_function_alloc_as(struct kk_src_circuit_server_loop_fun220__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_circuit_server_loop_fun220, kk_context());
  _self->failures_2 = failures_2;
  _self->last_fail_4 = last_fail_4;
  _self->successes_3 = successes_3;
  _self->tick_0 = tick_0;
  _self->total_4 = total_4;
  _self->st_1 = st_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_circuit_server_loop_fun220(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun220__t* _self = kk_function_as(struct kk_src_circuit_server_loop_fun220__t*, _fself, _ctx);
  kk_integer_t failures_2 = _self->failures_2; /* int */
  kk_integer_t last_fail_4 = _self->last_fail_4; /* int */
  kk_integer_t successes_3 = _self->successes_3; /* int */
  kk_integer_t tick_0 = _self->tick_0; /* int */
  kk_integer_t total_4 = _self->total_4; /* int */
  kk_src_circuit__circuit_state st_1 = _self->st_1; /* src/circuit/circuit-state */
  kk_drop_match(_self, {kk_integer_dup(failures_2, _ctx);kk_integer_dup(last_fail_4, _ctx);kk_integer_dup(successes_3, _ctx);kk_integer_dup(tick_0, _ctx);kk_integer_dup(total_4, _ctx);kk_src_circuit__circuit_state_dup(st_1, _ctx);}, {}, _ctx)
  kk_string_t line_0_61 = kk_string_unbox(_b_x32); /*string*/;
  kk_unit_t _x_x221 = kk_Unit;
  kk_src_circuit__mlift_server_loop_10039(failures_2, last_fail_4, st_1, successes_3, tick_0, total_4, line_0_61, _ctx);
  return kk_unit_box(_x_x221);
}


// lift anonymous function
struct kk_src_circuit_server_loop_fun226__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_circuit_server_loop_fun226(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx);
static kk_function_t kk_src_circuit_new_server_loop_fun226(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_circuit_server_loop_fun226, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_circuit_server_loop_fun226(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x227;
  kk_string_t _x_x228 = kk_string_unbox(_b_x35); /*string*/
  _x_x227 = kk_src_circuit_extract_op(_x_x228, _ctx); /*string*/
  return kk_string_box(_x_x227);
}


// lift anonymous function
struct kk_src_circuit_server_loop_fun236__t {
  struct kk_function_s _base;
  kk_integer_t failures_2;
  kk_integer_t last_fail_4;
  kk_integer_t new_tick_4;
  kk_integer_t successes_3;
  kk_src_circuit__circuit_state st_1;
};
static kk_box_t kk_src_circuit_server_loop_fun236(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_circuit_new_server_loop_fun236(kk_integer_t failures_2, kk_integer_t last_fail_4, kk_integer_t new_tick_4, kk_integer_t successes_3, kk_src_circuit__circuit_state st_1, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun236__t* _self = kk_function_alloc_as(struct kk_src_circuit_server_loop_fun236__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_circuit_server_loop_fun236, kk_context());
  _self->failures_2 = failures_2;
  _self->last_fail_4 = last_fail_4;
  _self->new_tick_4 = new_tick_4;
  _self->successes_3 = successes_3;
  _self->st_1 = st_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_circuit_server_loop_fun236(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun236__t* _self = kk_function_as(struct kk_src_circuit_server_loop_fun236__t*, _fself, _ctx);
  kk_integer_t failures_2 = _self->failures_2; /* int */
  kk_integer_t last_fail_4 = _self->last_fail_4; /* int */
  kk_integer_t new_tick_4 = _self->new_tick_4; /* int */
  kk_integer_t successes_3 = _self->successes_3; /* int */
  kk_src_circuit__circuit_state st_1 = _self->st_1; /* src/circuit/circuit-state */
  kk_drop_match(_self, {kk_integer_dup(failures_2, _ctx);kk_integer_dup(last_fail_4, _ctx);kk_integer_dup(new_tick_4, _ctx);kk_integer_dup(successes_3, _ctx);kk_src_circuit__circuit_state_dup(st_1, _ctx);}, {}, _ctx)
  kk_string_t _x_x237 = kk_src_circuit_check_state(st_1, failures_2, successes_3, new_tick_4, last_fail_4, _ctx); /*string*/
  return kk_string_box(_x_x237);
}


// lift anonymous function
struct kk_src_circuit_server_loop_fun252__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_circuit_server_loop_fun252(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx);
static kk_function_t kk_src_circuit_new_server_loop_fun252(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_circuit_server_loop_fun252, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_circuit_server_loop_fun252(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x253;
  kk_src_circuit__circuit_state _match_x76 = kk_src_circuit__circuit_state_unbox(_b_x41, KK_OWNED, _ctx); /*src/circuit/circuit-state*/;
  if (kk_src_circuit__is_Closed(_match_x76, _ctx)) {
    kk_define_string_literal(, _s_x255, 6, "closed", _ctx)
    _x_x253 = kk_string_dup(_s_x255, _ctx); /*string*/
    goto _match_x254;
  }
  if (kk_src_circuit__is_Open(_match_x76, _ctx)) {
    kk_define_string_literal(, _s_x256, 4, "open", _ctx)
    _x_x253 = kk_string_dup(_s_x256, _ctx); /*string*/
    goto _match_x254;
  }
  {
    kk_define_string_literal(, _s_x257, 9, "half-open", _ctx)
    _x_x253 = kk_string_dup(_s_x257, _ctx); /*string*/
  }
  _match_x254: ;
  return kk_string_box(_x_x253);
}


// lift anonymous function
struct kk_src_circuit_server_loop_fun286__t {
  struct kk_function_s _base;
  kk_integer_t failures_2;
  kk_integer_t last_fail_4;
  kk_integer_t new_tick_4;
  kk_string_t op_4;
  kk_integer_t successes_3;
  kk_integer_t total_4;
  kk_src_circuit__circuit_state st_1;
};
static kk_box_t kk_src_circuit_server_loop_fun286(kk_function_t _fself, kk_box_t _b_x46, kk_context_t* _ctx);
static kk_function_t kk_src_circuit_new_server_loop_fun286(kk_integer_t failures_2, kk_integer_t last_fail_4, kk_integer_t new_tick_4, kk_string_t op_4, kk_integer_t successes_3, kk_integer_t total_4, kk_src_circuit__circuit_state st_1, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun286__t* _self = kk_function_alloc_as(struct kk_src_circuit_server_loop_fun286__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_circuit_server_loop_fun286, kk_context());
  _self->failures_2 = failures_2;
  _self->last_fail_4 = last_fail_4;
  _self->new_tick_4 = new_tick_4;
  _self->op_4 = op_4;
  _self->successes_3 = successes_3;
  _self->total_4 = total_4;
  _self->st_1 = st_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_circuit_server_loop_fun286(kk_function_t _fself, kk_box_t _b_x46, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun286__t* _self = kk_function_as(struct kk_src_circuit_server_loop_fun286__t*, _fself, _ctx);
  kk_integer_t failures_2 = _self->failures_2; /* int */
  kk_integer_t last_fail_4 = _self->last_fail_4; /* int */
  kk_integer_t new_tick_4 = _self->new_tick_4; /* int */
  kk_string_t op_4 = _self->op_4; /* string */
  kk_integer_t successes_3 = _self->successes_3; /* int */
  kk_integer_t total_4 = _self->total_4; /* int */
  kk_src_circuit__circuit_state st_1 = _self->st_1; /* src/circuit/circuit-state */
  kk_drop_match(_self, {kk_integer_dup(failures_2, _ctx);kk_integer_dup(last_fail_4, _ctx);kk_integer_dup(new_tick_4, _ctx);kk_string_dup(op_4, _ctx);kk_integer_dup(successes_3, _ctx);kk_integer_dup(total_4, _ctx);kk_src_circuit__circuit_state_dup(st_1, _ctx);}, {}, _ctx)
  kk_string_t _c_x10003_4_62 = kk_string_unbox(_b_x46); /*string*/;
  kk_unit_t _x_x287 = kk_Unit;
  kk_src_circuit__mlift_server_loop_10038(failures_2, last_fail_4, new_tick_4, op_4, st_1, successes_3, total_4, _c_x10003_4_62, _ctx);
  return kk_unit_box(_x_x287);
}


// lift anonymous function
struct kk_src_circuit_server_loop_fun292__t {
  struct kk_function_s _base;
  kk_integer_t failures_2;
  kk_integer_t last_fail_4;
  kk_integer_t new_tick_4;
  kk_string_t op_4;
  kk_integer_t successes_3;
  kk_integer_t total_4;
  kk_string_t x_4_10051;
};
static kk_box_t kk_src_circuit_server_loop_fun292(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx);
static kk_function_t kk_src_circuit_new_server_loop_fun292(kk_integer_t failures_2, kk_integer_t last_fail_4, kk_integer_t new_tick_4, kk_string_t op_4, kk_integer_t successes_3, kk_integer_t total_4, kk_string_t x_4_10051, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun292__t* _self = kk_function_alloc_as(struct kk_src_circuit_server_loop_fun292__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_circuit_server_loop_fun292, kk_context());
  _self->failures_2 = failures_2;
  _self->last_fail_4 = last_fail_4;
  _self->new_tick_4 = new_tick_4;
  _self->op_4 = op_4;
  _self->successes_3 = successes_3;
  _self->total_4 = total_4;
  _self->x_4_10051 = x_4_10051;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_circuit_server_loop_fun292(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun292__t* _self = kk_function_as(struct kk_src_circuit_server_loop_fun292__t*, _fself, _ctx);
  kk_integer_t failures_2 = _self->failures_2; /* int */
  kk_integer_t last_fail_4 = _self->last_fail_4; /* int */
  kk_integer_t new_tick_4 = _self->new_tick_4; /* int */
  kk_string_t op_4 = _self->op_4; /* string */
  kk_integer_t successes_3 = _self->successes_3; /* int */
  kk_integer_t total_4 = _self->total_4; /* int */
  kk_string_t x_4_10051 = _self->x_4_10051; /* string */
  kk_drop_match(_self, {kk_integer_dup(failures_2, _ctx);kk_integer_dup(last_fail_4, _ctx);kk_integer_dup(new_tick_4, _ctx);kk_string_dup(op_4, _ctx);kk_integer_dup(successes_3, _ctx);kk_integer_dup(total_4, _ctx);kk_string_dup(x_4_10051, _ctx);}, {}, _ctx)
  kk_src_circuit__circuit_state _c_x10006_3_63 = kk_src_circuit__circuit_state_unbox(_b_x48, KK_OWNED, _ctx); /*src/circuit/circuit-state*/;
  kk_unit_t _x_x293 = kk_Unit;
  kk_src_circuit__mlift_server_loop_10037(x_4_10051, failures_2, last_fail_4, new_tick_4, op_4, successes_3, total_4, _c_x10006_3_63, _ctx);
  return kk_unit_box(_x_x293);
}


// lift anonymous function
struct kk_src_circuit_server_loop_fun296__t {
  struct kk_function_s _base;
  kk_integer_t last_fail_4;
  kk_integer_t new_tick_4;
  kk_string_t op_4;
  kk_integer_t successes_3;
  kk_integer_t total_4;
  kk_string_t x_4_10051;
  kk_src_circuit__circuit_state x_5_10054;
};
static kk_box_t kk_src_circuit_server_loop_fun296(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx);
static kk_function_t kk_src_circuit_new_server_loop_fun296(kk_integer_t last_fail_4, kk_integer_t new_tick_4, kk_string_t op_4, kk_integer_t successes_3, kk_integer_t total_4, kk_string_t x_4_10051, kk_src_circuit__circuit_state x_5_10054, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun296__t* _self = kk_function_alloc_as(struct kk_src_circuit_server_loop_fun296__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_circuit_server_loop_fun296, kk_context());
  _self->last_fail_4 = last_fail_4;
  _self->new_tick_4 = new_tick_4;
  _self->op_4 = op_4;
  _self->successes_3 = successes_3;
  _self->total_4 = total_4;
  _self->x_4_10051 = x_4_10051;
  _self->x_5_10054 = x_5_10054;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_circuit_server_loop_fun296(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun296__t* _self = kk_function_as(struct kk_src_circuit_server_loop_fun296__t*, _fself, _ctx);
  kk_integer_t last_fail_4 = _self->last_fail_4; /* int */
  kk_integer_t new_tick_4 = _self->new_tick_4; /* int */
  kk_string_t op_4 = _self->op_4; /* string */
  kk_integer_t successes_3 = _self->successes_3; /* int */
  kk_integer_t total_4 = _self->total_4; /* int */
  kk_string_t x_4_10051 = _self->x_4_10051; /* string */
  kk_src_circuit__circuit_state x_5_10054 = _self->x_5_10054; /* src/circuit/circuit-state */
  kk_drop_match(_self, {kk_integer_dup(last_fail_4, _ctx);kk_integer_dup(new_tick_4, _ctx);kk_string_dup(op_4, _ctx);kk_integer_dup(successes_3, _ctx);kk_integer_dup(total_4, _ctx);kk_string_dup(x_4_10051, _ctx);kk_src_circuit__circuit_state_dup(x_5_10054, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10007_2_64 = kk_integer_unbox(_b_x50, _ctx); /*int*/;
  kk_unit_t _x_x297 = kk_Unit;
  kk_src_circuit__mlift_server_loop_10036(x_4_10051, x_5_10054, last_fail_4, new_tick_4, op_4, successes_3, total_4, _c_x10007_2_64, _ctx);
  return kk_unit_box(_x_x297);
}


// lift anonymous function
struct kk_src_circuit_server_loop_fun300__t {
  struct kk_function_s _base;
  kk_integer_t last_fail_4;
  kk_integer_t new_tick_4;
  kk_string_t op_4;
  kk_integer_t total_4;
  kk_string_t x_4_10051;
  kk_integer_t x_6_10057;
  kk_src_circuit__circuit_state x_5_10054;
};
static kk_box_t kk_src_circuit_server_loop_fun300(kk_function_t _fself, kk_box_t _b_x52, kk_context_t* _ctx);
static kk_function_t kk_src_circuit_new_server_loop_fun300(kk_integer_t last_fail_4, kk_integer_t new_tick_4, kk_string_t op_4, kk_integer_t total_4, kk_string_t x_4_10051, kk_integer_t x_6_10057, kk_src_circuit__circuit_state x_5_10054, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun300__t* _self = kk_function_alloc_as(struct kk_src_circuit_server_loop_fun300__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_circuit_server_loop_fun300, kk_context());
  _self->last_fail_4 = last_fail_4;
  _self->new_tick_4 = new_tick_4;
  _self->op_4 = op_4;
  _self->total_4 = total_4;
  _self->x_4_10051 = x_4_10051;
  _self->x_6_10057 = x_6_10057;
  _self->x_5_10054 = x_5_10054;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_circuit_server_loop_fun300(kk_function_t _fself, kk_box_t _b_x52, kk_context_t* _ctx) {
  struct kk_src_circuit_server_loop_fun300__t* _self = kk_function_as(struct kk_src_circuit_server_loop_fun300__t*, _fself, _ctx);
  kk_integer_t last_fail_4 = _self->last_fail_4; /* int */
  kk_integer_t new_tick_4 = _self->new_tick_4; /* int */
  kk_string_t op_4 = _self->op_4; /* string */
  kk_integer_t total_4 = _self->total_4; /* int */
  kk_string_t x_4_10051 = _self->x_4_10051; /* string */
  kk_integer_t x_6_10057 = _self->x_6_10057; /* int */
  kk_src_circuit__circuit_state x_5_10054 = _self->x_5_10054; /* src/circuit/circuit-state */
  kk_drop_match(_self, {kk_integer_dup(last_fail_4, _ctx);kk_integer_dup(new_tick_4, _ctx);kk_string_dup(op_4, _ctx);kk_integer_dup(total_4, _ctx);kk_string_dup(x_4_10051, _ctx);kk_integer_dup(x_6_10057, _ctx);kk_src_circuit__circuit_state_dup(x_5_10054, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10008_1_65 = kk_integer_unbox(_b_x52, _ctx); /*int*/;
  kk_unit_t _x_x301 = kk_Unit;
  kk_src_circuit__mlift_server_loop_10035(x_4_10051, x_5_10054, x_6_10057, last_fail_4, new_tick_4, op_4, total_4, _c_x10008_1_65, _ctx);
  return kk_unit_box(_x_x301);
}


// lift anonymous function
struct kk_src_circuit_server_loop_fun303__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_circuit_server_loop_fun303(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_circuit_new_server_loop_fun303(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_circuit_server_loop_fun303, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_circuit_server_loop_fun303(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x304 = kk_Unit;
  kk_src_circuit_flush_stdout(_ctx);
  return kk_unit_box(_x_x304);
}

kk_unit_t kk_src_circuit_server_loop(kk_integer_t tick_0, kk_src_circuit__circuit_state st_1, kk_integer_t failures_2, kk_integer_t successes_3, kk_integer_t last_fail_4, kk_integer_t total_4, kk_context_t* _ctx) { /* (tick : int, st : circuit-state, failures : int, successes : int, last-fail : int, total : int) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_3_10048 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_3_10048, _ctx);
    kk_box_t _x_x219 = kk_std_core_hnd_yield_extend(kk_src_circuit_new_server_loop_fun220(failures_2, last_fail_4, successes_3, tick_0, total_4, st_1, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x219); return kk_Unit;
  }
  {
    bool _match_x67;
    kk_string_t _x_x222 = kk_string_dup(x_3_10048, _ctx); /*string*/
    kk_string_t _x_x223 = kk_string_empty(); /*string*/
    _match_x67 = kk_string_is_neq(_x_x222,_x_x223,kk_context()); /*bool*/
    if (_match_x67) {
      kk_integer_t new_tick_4 = kk_integer_add_small_const(tick_0, 1, _ctx); /*int*/;
      kk_string_t op_4;
      kk_box_t _x_x225 = kk_std_core_hnd__open_none1(kk_src_circuit_new_server_loop_fun226(_ctx), kk_string_box(x_3_10048), _ctx); /*10001*/
      op_4 = kk_string_unbox(_x_x225); /*string*/
      kk_string_t x_4_10051;
      if (kk_string_cmp_cstr_borrow(op_4, "check", _ctx) == 0) {
        kk_string_t _x_x230;
        kk_define_string_literal(, _s_x231, 33, "{\"operation\": \"check\", \"state\": \"", _ctx)
        _x_x230 = kk_string_dup(_s_x231, _ctx); /*string*/
        kk_string_t _x_x232;
        kk_string_t _x_x233;
        kk_box_t _x_x234;
        kk_function_t _x_x235;
        kk_integer_dup(failures_2, _ctx);
        kk_integer_dup(last_fail_4, _ctx);
        kk_integer_dup(new_tick_4, _ctx);
        kk_integer_dup(successes_3, _ctx);
        _x_x235 = kk_src_circuit_new_server_loop_fun236(failures_2, last_fail_4, new_tick_4, successes_3, st_1, _ctx); /*() -> 10001 10000*/
        _x_x234 = kk_std_core_hnd__open_none0(_x_x235, _ctx); /*10000*/
        _x_x233 = kk_string_unbox(_x_x234); /*string*/
        kk_string_t _x_x238;
        kk_define_string_literal(, _s_x239, 2, "\"}", _ctx)
        _x_x238 = kk_string_dup(_s_x239, _ctx); /*string*/
        _x_x232 = kk_std_core_types__lp__plus__plus__rp_(_x_x233, _x_x238, _ctx); /*string*/
        x_4_10051 = kk_std_core_types__lp__plus__plus__rp_(_x_x230, _x_x232, _ctx); /*string*/
        goto _match_x229;
      }
      if (kk_string_cmp_cstr_borrow(op_4, "success", _ctx) == 0) {
        if (kk_src_circuit__is_Closed(st_1, _ctx)) {
          kk_define_string_literal(, _s_x240, 40, "{\"operation\": \"success\", \"result\": \"ok\"}", _ctx)
          x_4_10051 = kk_string_dup(_s_x240, _ctx); /*string*/
          goto _match_x229;
        }
        if (kk_src_circuit__is_HalfOpen(st_1, _ctx)) {
          kk_define_string_literal(, _s_x241, 40, "{\"operation\": \"success\", \"result\": \"ok\"}", _ctx)
          x_4_10051 = kk_string_dup(_s_x241, _ctx); /*string*/
          goto _match_x229;
        }
        {
          kk_define_string_literal(, _s_x242, 40, "{\"operation\": \"success\", \"result\": \"ok\"}", _ctx)
          x_4_10051 = kk_string_dup(_s_x242, _ctx); /*string*/
          goto _match_x229;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_4, "failure", _ctx) == 0) {
        if (kk_src_circuit__is_Closed(st_1, _ctx)) {
          kk_define_string_literal(, _s_x243, 40, "{\"operation\": \"failure\", \"result\": \"ok\"}", _ctx)
          x_4_10051 = kk_string_dup(_s_x243, _ctx); /*string*/
          goto _match_x229;
        }
        if (kk_src_circuit__is_HalfOpen(st_1, _ctx)) {
          kk_define_string_literal(, _s_x244, 40, "{\"operation\": \"failure\", \"result\": \"ok\"}", _ctx)
          x_4_10051 = kk_string_dup(_s_x244, _ctx); /*string*/
          goto _match_x229;
        }
        {
          kk_define_string_literal(, _s_x245, 40, "{\"operation\": \"failure\", \"result\": \"ok\"}", _ctx)
          x_4_10051 = kk_string_dup(_s_x245, _ctx); /*string*/
          goto _match_x229;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_4, "reset", _ctx) == 0) {
        kk_define_string_literal(, _s_x246, 38, "{\"operation\": \"reset\", \"result\": \"ok\"}", _ctx)
        x_4_10051 = kk_string_dup(_s_x246, _ctx); /*string*/
        goto _match_x229;
      }
      if (kk_string_cmp_cstr_borrow(op_4, "status", _ctx) == 0) {
        kk_string_t _x_x247;
        kk_define_string_literal(, _s_x248, 11, "{\"state\": \"", _ctx)
        _x_x247 = kk_string_dup(_s_x248, _ctx); /*string*/
        kk_string_t _x_x249;
        kk_string_t _x_x250;
        kk_box_t _x_x251 = kk_std_core_hnd__open_none1(kk_src_circuit_new_server_loop_fun252(_ctx), kk_src_circuit__circuit_state_box(st_1, _ctx), _ctx); /*10001*/
        _x_x250 = kk_string_unbox(_x_x251); /*string*/
        kk_string_t _x_x258;
        kk_string_t _x_x259;
        kk_define_string_literal(, _s_x260, 15, "\", \"failures\": ", _ctx)
        _x_x259 = kk_string_dup(_s_x260, _ctx); /*string*/
        kk_string_t _x_x261;
        kk_string_t _x_x262;
        kk_integer_t _x_x263 = kk_integer_dup(failures_2, _ctx); /*int*/
        _x_x262 = kk_std_core_int_show(_x_x263, _ctx); /*string*/
        kk_string_t _x_x264;
        kk_string_t _x_x265;
        kk_define_string_literal(, _s_x266, 15, ", \"successes\": ", _ctx)
        _x_x265 = kk_string_dup(_s_x266, _ctx); /*string*/
        kk_string_t _x_x267;
        kk_string_t _x_x268;
        kk_integer_t _x_x269 = kk_integer_dup(successes_3, _ctx); /*int*/
        _x_x268 = kk_std_core_int_show(_x_x269, _ctx); /*string*/
        kk_string_t _x_x270;
        kk_string_t _x_x271;
        kk_define_string_literal(, _s_x272, 17, ", \"total_calls\": ", _ctx)
        _x_x271 = kk_string_dup(_s_x272, _ctx); /*string*/
        kk_string_t _x_x273;
        kk_string_t _x_x274;
        kk_integer_t _x_x275 = kk_integer_dup(total_4, _ctx); /*int*/
        _x_x274 = kk_std_core_int_show(_x_x275, _ctx); /*string*/
        kk_string_t _x_x276;
        kk_string_t _x_x277;
        kk_define_string_literal(, _s_x278, 10, ", \"tick\": ", _ctx)
        _x_x277 = kk_string_dup(_s_x278, _ctx); /*string*/
        kk_string_t _x_x279;
        kk_string_t _x_x280;
        kk_integer_t _x_x281 = kk_integer_dup(new_tick_4, _ctx); /*int*/
        _x_x280 = kk_std_core_int_show(_x_x281, _ctx); /*string*/
        kk_string_t _x_x282;
        kk_define_string_literal(, _s_x283, 1, "}", _ctx)
        _x_x282 = kk_string_dup(_s_x283, _ctx); /*string*/
        _x_x279 = kk_std_core_types__lp__plus__plus__rp_(_x_x280, _x_x282, _ctx); /*string*/
        _x_x276 = kk_std_core_types__lp__plus__plus__rp_(_x_x277, _x_x279, _ctx); /*string*/
        _x_x273 = kk_std_core_types__lp__plus__plus__rp_(_x_x274, _x_x276, _ctx); /*string*/
        _x_x270 = kk_std_core_types__lp__plus__plus__rp_(_x_x271, _x_x273, _ctx); /*string*/
        _x_x267 = kk_std_core_types__lp__plus__plus__rp_(_x_x268, _x_x270, _ctx); /*string*/
        _x_x264 = kk_std_core_types__lp__plus__plus__rp_(_x_x265, _x_x267, _ctx); /*string*/
        _x_x261 = kk_std_core_types__lp__plus__plus__rp_(_x_x262, _x_x264, _ctx); /*string*/
        _x_x258 = kk_std_core_types__lp__plus__plus__rp_(_x_x259, _x_x261, _ctx); /*string*/
        _x_x249 = kk_std_core_types__lp__plus__plus__rp_(_x_x250, _x_x258, _ctx); /*string*/
        x_4_10051 = kk_std_core_types__lp__plus__plus__rp_(_x_x247, _x_x249, _ctx); /*string*/
        goto _match_x229;
      }
      {
        kk_define_string_literal(, _s_x284, 30, "{\"error\": \"unknown_operation\"}", _ctx)
        x_4_10051 = kk_string_dup(_s_x284, _ctx); /*string*/
      }
      _match_x229: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_4_10051, _ctx);
        kk_box_t _x_x285 = kk_std_core_hnd_yield_extend(kk_src_circuit_new_server_loop_fun286(failures_2, last_fail_4, new_tick_4, op_4, successes_3, total_4, st_1, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x285); return kk_Unit;
      }
      {
        kk_src_circuit__circuit_state x_5_10054;
        if (kk_string_cmp_cstr_borrow(op_4, "success", _ctx) == 0) {
          if (kk_src_circuit__is_HalfOpen(st_1, _ctx)) {
            kk_integer_t new_s_0;
            kk_integer_t _x_x289 = kk_integer_dup(successes_3, _ctx); /*int*/
            new_s_0 = kk_integer_add_small_const(_x_x289, 1, _ctx); /*int*/
            bool _match_x74;
            bool _brw_x75 = kk_integer_gte_borrow(new_s_0,(kk_integer_from_small(3)),kk_context()); /*bool*/;
            kk_integer_drop(new_s_0, _ctx);
            _match_x74 = _brw_x75; /*bool*/
            if (_match_x74) {
              x_5_10054 = kk_src_circuit__new_Closed(_ctx); /*src/circuit/circuit-state*/
              goto _match_x288;
            }
            {
              x_5_10054 = kk_src_circuit__new_HalfOpen(_ctx); /*src/circuit/circuit-state*/
              goto _match_x288;
            }
          }
          {
            x_5_10054 = st_1; /*src/circuit/circuit-state*/
            goto _match_x288;
          }
        }
        if (kk_string_cmp_cstr_borrow(op_4, "failure", _ctx) == 0) {
          if (kk_src_circuit__is_Closed(st_1, _ctx)) {
            kk_integer_t new_f_0;
            kk_integer_t _x_x290 = kk_integer_dup(failures_2, _ctx); /*int*/
            new_f_0 = kk_integer_add_small_const(_x_x290, 1, _ctx); /*int*/
            bool _match_x72;
            bool _brw_x73 = kk_integer_gte_borrow(new_f_0,(kk_integer_from_small(5)),kk_context()); /*bool*/;
            kk_integer_drop(new_f_0, _ctx);
            _match_x72 = _brw_x73; /*bool*/
            if (_match_x72) {
              x_5_10054 = kk_src_circuit__new_Open(_ctx); /*src/circuit/circuit-state*/
              goto _match_x288;
            }
            {
              x_5_10054 = kk_src_circuit__new_Closed(_ctx); /*src/circuit/circuit-state*/
              goto _match_x288;
            }
          }
          if (kk_src_circuit__is_HalfOpen(st_1, _ctx)) {
            x_5_10054 = kk_src_circuit__new_Open(_ctx); /*src/circuit/circuit-state*/
            goto _match_x288;
          }
          {
            x_5_10054 = st_1; /*src/circuit/circuit-state*/
            goto _match_x288;
          }
        }
        if (kk_string_cmp_cstr_borrow(op_4, "reset", _ctx) == 0) {
          x_5_10054 = kk_src_circuit__new_Closed(_ctx); /*src/circuit/circuit-state*/
          goto _match_x288;
        }
        {
          x_5_10054 = st_1; /*src/circuit/circuit-state*/
        }
        _match_x288: ;
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x291 = kk_std_core_hnd_yield_extend(kk_src_circuit_new_server_loop_fun292(failures_2, last_fail_4, new_tick_4, op_4, successes_3, total_4, x_4_10051, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x291); return kk_Unit;
        }
        {
          kk_integer_t x_6_10057;
          if (kk_string_cmp_cstr_borrow(op_4, "success", _ctx) == 0) {
            kk_integer_drop(failures_2, _ctx);
            x_6_10057 = kk_integer_from_small(0); /*int*/
            goto _match_x294;
          }
          if (kk_string_cmp_cstr_borrow(op_4, "failure", _ctx) == 0) {
            x_6_10057 = kk_integer_add_small_const(failures_2, 1, _ctx); /*int*/
            goto _match_x294;
          }
          if (kk_string_cmp_cstr_borrow(op_4, "reset", _ctx) == 0) {
            kk_integer_drop(failures_2, _ctx);
            x_6_10057 = kk_integer_from_small(0); /*int*/
            goto _match_x294;
          }
          {
            x_6_10057 = failures_2; /*int*/
          }
          _match_x294: ;
          if (kk_yielding(kk_context())) {
            kk_integer_drop(x_6_10057, _ctx);
            kk_box_t _x_x295 = kk_std_core_hnd_yield_extend(kk_src_circuit_new_server_loop_fun296(last_fail_4, new_tick_4, op_4, successes_3, total_4, x_4_10051, x_5_10054, _ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x295); return kk_Unit;
          }
          {
            kk_integer_t x_7_10060;
            if (kk_string_cmp_cstr_borrow(op_4, "success", _ctx) == 0) {
              x_7_10060 = kk_integer_add_small_const(successes_3, 1, _ctx); /*int*/
              goto _match_x298;
            }
            if (kk_string_cmp_cstr_borrow(op_4, "failure", _ctx) == 0) {
              kk_integer_drop(successes_3, _ctx);
              x_7_10060 = kk_integer_from_small(0); /*int*/
              goto _match_x298;
            }
            if (kk_string_cmp_cstr_borrow(op_4, "reset", _ctx) == 0) {
              kk_integer_drop(successes_3, _ctx);
              x_7_10060 = kk_integer_from_small(0); /*int*/
              goto _match_x298;
            }
            {
              x_7_10060 = successes_3; /*int*/
            }
            _match_x298: ;
            if (kk_yielding(kk_context())) {
              kk_integer_drop(x_7_10060, _ctx);
              kk_box_t _x_x299 = kk_std_core_hnd_yield_extend(kk_src_circuit_new_server_loop_fun300(last_fail_4, new_tick_4, op_4, total_4, x_4_10051, x_6_10057, x_5_10054, _ctx), _ctx); /*10001*/
              kk_unit_unbox(_x_x299); return kk_Unit;
            }
            {
              kk_integer_t next_total_0 = kk_integer_add_small_const(total_4, 1, _ctx); /*int*/;
              kk_unit_t ___1 = kk_Unit;
              kk_std_core_console_printsln(x_4_10051, _ctx);
              kk_unit_t ___0_0 = kk_Unit;
              kk_box_t _x_x302 = kk_std_core_hnd__open_none0(kk_src_circuit_new_server_loop_fun303(_ctx), _ctx); /*10000*/
              kk_unit_unbox(_x_x302);
              { // tailcall
                kk_integer_t _x_x305 = kk_integer_dup(new_tick_4, _ctx); /*int*/
                kk_integer_t _x_x306;
                if (kk_string_cmp_cstr_borrow(op_4, "failure", _ctx) == 0) {
                  kk_string_drop(op_4, _ctx);
                  kk_integer_drop(last_fail_4, _ctx);
                  _x_x306 = new_tick_4; /*int*/
                  goto _match_x307;
                }
                if (kk_string_cmp_cstr_borrow(op_4, "reset", _ctx) == 0) {
                  kk_string_drop(op_4, _ctx);
                  kk_integer_drop(new_tick_4, _ctx);
                  kk_integer_drop(last_fail_4, _ctx);
                  _x_x306 = kk_integer_from_small(0); /*int*/
                  goto _match_x307;
                }
                {
                  kk_string_drop(op_4, _ctx);
                  kk_integer_drop(new_tick_4, _ctx);
                  _x_x306 = last_fail_4; /*int*/
                }
                _match_x307: ;
                tick_0 = _x_x305;
                st_1 = x_5_10054;
                failures_2 = x_6_10057;
                successes_3 = x_7_10060;
                last_fail_4 = _x_x306;
                total_4 = next_total_0;
                goto kk__tailcall;
              }
            }
          }
        }
      }
    }
    {
      kk_string_drop(x_3_10048, _ctx);
      kk_integer_drop(total_4, _ctx);
      kk_integer_drop(tick_0, _ctx);
      kk_integer_drop(successes_3, _ctx);
      kk_integer_drop(last_fail_4, _ctx);
      kk_integer_drop(failures_2, _ctx);
      kk_Unit; return kk_Unit;
    }
  }
}

// initialization
void kk_src_circuit__init(kk_context_t* _ctx){
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
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_src_circuit__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
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
