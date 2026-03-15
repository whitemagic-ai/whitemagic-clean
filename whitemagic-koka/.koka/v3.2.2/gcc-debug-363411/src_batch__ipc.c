// Koka generated module: src/batch_ipc, koka version: 3.2.2, platform: 64-bit
#include "src_batch__ipc.h"
 
// Execute single command and return JSON result

kk_string_t kk_src_batch__ipc_execute_cmd(kk_string_t op, kk_context_t* _ctx) { /* (op : string) -> string */ 
  if (kk_string_cmp_cstr_borrow(op, "ping", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_define_string_literal(, _s_x74, 13, "{\"pong\":true}", _ctx)
    return kk_string_dup(_s_x74, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(op, "status", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_define_string_literal(, _s_x75, 32, "{\"status\":\"ok\",\"batch_ipc\":true}", _ctx)
    return kk_string_dup(_s_x75, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(op, "emit", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_define_string_literal(, _s_x76, 16, "{\"emitted\":true}", _ctx)
    return kk_string_dup(_s_x76, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(op, "count", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_define_string_literal(, _s_x77, 11, "{\"count\":0}", _ctx)
    return kk_string_dup(_s_x77, _ctx);
  }
  {
    kk_string_drop(op, _ctx);
    kk_define_string_literal(, _s_x78, 19, "{\"error\":\"unknown\"}", _ctx)
    return kk_string_dup(_s_x78, _ctx);
  }
}
 
// Extract op from line using contains pattern

kk_string_t kk_src_batch__ipc_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x69;
  kk_string_t _x_x79 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x80;
  kk_define_string_literal(, _s_x81, 6, "\"ping\"", _ctx)
  _x_x80 = kk_string_dup(_s_x81, _ctx); /*string*/
  _match_x69 = kk_string_contains(_x_x79,_x_x80,kk_context()); /*bool*/
  if (_match_x69) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x82, 4, "ping", _ctx)
    return kk_string_dup(_s_x82, _ctx);
  }
  {
    bool _match_x70;
    kk_string_t _x_x83 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x84;
    kk_define_string_literal(, _s_x85, 8, "\"status\"", _ctx)
    _x_x84 = kk_string_dup(_s_x85, _ctx); /*string*/
    _match_x70 = kk_string_contains(_x_x83,_x_x84,kk_context()); /*bool*/
    if (_match_x70) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x86, 6, "status", _ctx)
      return kk_string_dup(_s_x86, _ctx);
    }
    {
      bool _match_x71;
      kk_string_t _x_x87 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x88;
      kk_define_string_literal(, _s_x89, 6, "\"emit\"", _ctx)
      _x_x88 = kk_string_dup(_s_x89, _ctx); /*string*/
      _match_x71 = kk_string_contains(_x_x87,_x_x88,kk_context()); /*bool*/
      if (_match_x71) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x90, 4, "emit", _ctx)
        return kk_string_dup(_s_x90, _ctx);
      }
      {
        bool _match_x72;
        kk_string_t _x_x91 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x92;
        kk_define_string_literal(, _s_x93, 7, "\"count\"", _ctx)
        _x_x92 = kk_string_dup(_s_x93, _ctx); /*string*/
        _match_x72 = kk_string_contains(_x_x91,_x_x92,kk_context()); /*bool*/
        if (_match_x72) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x94, 5, "count", _ctx)
          return kk_string_dup(_s_x94, _ctx);
        }
        {
          bool _match_x73;
          kk_string_t _x_x95;
          kk_define_string_literal(, _s_x96, 6, "\"quit\"", _ctx)
          _x_x95 = kk_string_dup(_s_x96, _ctx); /*string*/
          _match_x73 = kk_string_contains(line,_x_x95,kk_context()); /*bool*/
          if (_match_x73) {
            kk_define_string_literal(, _s_x97, 4, "quit", _ctx)
            return kk_string_dup(_s_x97, _ctx);
          }
          {
            kk_define_string_literal(, _s_x98, 7, "unknown", _ctx)
            return kk_string_dup(_s_x98, _ctx);
          }
        }
      }
    }
  }
}
 
// Build batch response for n commands

kk_string_t kk_src_batch__ipc_batch_response(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> string */ 
  bool _match_x64 = kk_integer_eq_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x64) {
    kk_integer_drop(n, _ctx);
    kk_define_string_literal(, _s_x103, 58, "{\"request_id\":\"batch\",\"results\":[],\"commands_processed\":0}", _ctx)
    return kk_string_dup(_s_x103, _ctx);
  }
  {
    bool _match_x65 = kk_integer_eq_borrow(n,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x65) {
      kk_integer_drop(n, _ctx);
      kk_define_string_literal(, _s_x104, 103, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":1}", _ctx)
      return kk_string_dup(_s_x104, _ctx);
    }
    {
      bool _match_x66 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
      if (_match_x66) {
        kk_integer_drop(n, _ctx);
        kk_define_string_literal(, _s_x105, 149, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":2}", _ctx)
        return kk_string_dup(_s_x105, _ctx);
      }
      {
        bool _match_x67;
        bool _brw_x68 = kk_integer_eq_borrow(n,(kk_integer_from_small(3)),kk_context()); /*bool*/;
        kk_integer_drop(n, _ctx);
        _match_x67 = _brw_x68; /*bool*/
        if (_match_x67) {
          kk_define_string_literal(, _s_x106, 195, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":3,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":3}", _ctx)
          return kk_string_dup(_s_x106, _ctx);
        }
        {
          kk_define_string_literal(, _s_x107, 287, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":3,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":4,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":5,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":5}", _ctx)
          return kk_string_dup(_s_x107, _ctx);
        }
      }
    }
  }
}
 
// monadic lift

kk_unit_t kk_src_batch__ipc__mlift_main_loop_10014(kk_string_t _c_x10001, kk_context_t* _ctx) { /* (string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10001, _ctx);
  kk_src_batch__ipc_main_loop(_ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_src_batch__ipc__mlift_main_loop_10015_fun122__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_batch__ipc__mlift_main_loop_10015_fun122(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx);
static kk_function_t kk_src_batch__ipc__new_mlift_main_loop_10015_fun122(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_batch__ipc__mlift_main_loop_10015_fun122, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_batch__ipc__mlift_main_loop_10015_fun122(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t n_15 = kk_integer_unbox(_b_x2, _ctx); /*int*/;
  kk_string_t _x_x123;
  bool _match_x59 = kk_integer_eq_borrow(n_15,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x59) {
    kk_integer_drop(n_15, _ctx);
    kk_define_string_literal(, _s_x124, 58, "{\"request_id\":\"batch\",\"results\":[],\"commands_processed\":0}", _ctx)
    _x_x123 = kk_string_dup(_s_x124, _ctx); /*string*/
  }
  else {
    bool _match_x60 = kk_integer_eq_borrow(n_15,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x60) {
      kk_integer_drop(n_15, _ctx);
      kk_define_string_literal(, _s_x125, 103, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":1}", _ctx)
      _x_x123 = kk_string_dup(_s_x125, _ctx); /*string*/
    }
    else {
      bool _match_x61 = kk_integer_eq_borrow(n_15,(kk_integer_from_small(2)),kk_context()); /*bool*/;
      if (_match_x61) {
        kk_integer_drop(n_15, _ctx);
        kk_define_string_literal(, _s_x126, 149, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":2}", _ctx)
        _x_x123 = kk_string_dup(_s_x126, _ctx); /*string*/
      }
      else {
        bool _match_x62;
        bool _brw_x63 = kk_integer_eq_borrow(n_15,(kk_integer_from_small(3)),kk_context()); /*bool*/;
        kk_integer_drop(n_15, _ctx);
        _match_x62 = _brw_x63; /*bool*/
        if (_match_x62) {
          kk_define_string_literal(, _s_x127, 195, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":3,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":3}", _ctx)
          _x_x123 = kk_string_dup(_s_x127, _ctx); /*string*/
        }
        else {
          kk_define_string_literal(, _s_x128, 287, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":3,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":4,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":5,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":5}", _ctx)
          _x_x123 = kk_string_dup(_s_x128, _ctx); /*string*/
        }
      }
    }
  }
  return kk_string_box(_x_x123);
}


// lift anonymous function
struct kk_src_batch__ipc__mlift_main_loop_10015_fun130__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_batch__ipc__mlift_main_loop_10015_fun130(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx);
static kk_function_t kk_src_batch__ipc__new_mlift_main_loop_10015_fun130(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_batch__ipc__mlift_main_loop_10015_fun130, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_batch__ipc__mlift_main_loop_10015_fun130(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x131;
  kk_string_t _x_x132 = kk_string_unbox(_b_x5); /*string*/
  _x_x131 = kk_src_batch__ipc_extract_op(_x_x132, _ctx); /*string*/
  return kk_string_box(_x_x131);
}


// lift anonymous function
struct kk_src_batch__ipc__mlift_main_loop_10015_fun134__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_batch__ipc__mlift_main_loop_10015_fun134(kk_function_t _fself, kk_box_t _b_x10, kk_context_t* _ctx);
static kk_function_t kk_src_batch__ipc__new_mlift_main_loop_10015_fun134(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_batch__ipc__mlift_main_loop_10015_fun134, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_batch__ipc__mlift_main_loop_10015_fun134(kk_function_t _fself, kk_box_t _b_x10, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x135;
  kk_string_t _match_x58 = kk_string_unbox(_b_x10); /*string*/;
  if (kk_string_cmp_cstr_borrow(_match_x58, "ping", _ctx) == 0) {
    kk_string_drop(_match_x58, _ctx);
    kk_define_string_literal(, _s_x137, 13, "{\"pong\":true}", _ctx)
    _x_x135 = kk_string_dup(_s_x137, _ctx); /*string*/
    goto _match_x136;
  }
  if (kk_string_cmp_cstr_borrow(_match_x58, "status", _ctx) == 0) {
    kk_string_drop(_match_x58, _ctx);
    kk_define_string_literal(, _s_x138, 32, "{\"status\":\"ok\",\"batch_ipc\":true}", _ctx)
    _x_x135 = kk_string_dup(_s_x138, _ctx); /*string*/
    goto _match_x136;
  }
  if (kk_string_cmp_cstr_borrow(_match_x58, "emit", _ctx) == 0) {
    kk_string_drop(_match_x58, _ctx);
    kk_define_string_literal(, _s_x139, 16, "{\"emitted\":true}", _ctx)
    _x_x135 = kk_string_dup(_s_x139, _ctx); /*string*/
    goto _match_x136;
  }
  if (kk_string_cmp_cstr_borrow(_match_x58, "count", _ctx) == 0) {
    kk_string_drop(_match_x58, _ctx);
    kk_define_string_literal(, _s_x140, 11, "{\"count\":0}", _ctx)
    _x_x135 = kk_string_dup(_s_x140, _ctx); /*string*/
    goto _match_x136;
  }
  {
    kk_string_drop(_match_x58, _ctx);
    kk_define_string_literal(, _s_x141, 19, "{\"error\":\"unknown\"}", _ctx)
    _x_x135 = kk_string_dup(_s_x141, _ctx); /*string*/
  }
  _match_x136: ;
  return kk_string_box(_x_x135);
}


// lift anonymous function
struct kk_src_batch__ipc__mlift_main_loop_10015_fun143__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_batch__ipc__mlift_main_loop_10015_fun143(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx);
static kk_function_t kk_src_batch__ipc__new_mlift_main_loop_10015_fun143(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_batch__ipc__mlift_main_loop_10015_fun143, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_batch__ipc__mlift_main_loop_10015_fun143(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x144 = kk_Unit;
  kk_string_t _x_x145 = kk_string_unbox(_b_x18); /*string*/
  kk_src_batch__ipc__mlift_main_loop_10014(_x_x145, _ctx);
  return kk_unit_box(_x_x144);
}

kk_unit_t kk_src_batch__ipc__mlift_main_loop_10015(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> <console/console,exn> () */ 
  bool _match_x54;
  kk_string_t _x_x108 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x109 = kk_string_empty(); /*string*/
  _match_x54 = kk_string_is_eq(_x_x108,_x_x109,kk_context()); /*bool*/
  if (_match_x54) {
    kk_string_drop(line, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    bool _match_x55;
    kk_string_t _x_x111 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x112;
    kk_define_string_literal(, _s_x113, 6, "\"quit\"", _ctx)
    _x_x112 = kk_string_dup(_s_x113, _ctx); /*string*/
    _match_x55 = kk_string_contains(_x_x111,_x_x112,kk_context()); /*bool*/
    if (_match_x55) {
      kk_string_drop(line, _ctx);
      kk_string_t _x_x114;
      kk_define_string_literal(, _s_x115, 20, "{\"status\":\"stopped\"}", _ctx)
      _x_x114 = kk_string_dup(_s_x115, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x114, _ctx); return kk_Unit;
    }
    {
      kk_string_t x_10016;
      bool _match_x57;
      kk_string_t _x_x116 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x117;
      kk_define_string_literal(, _s_x118, 11, "\"commands\":", _ctx)
      _x_x117 = kk_string_dup(_s_x118, _ctx); /*string*/
      _match_x57 = kk_string_contains(_x_x116,_x_x117,kk_context()); /*bool*/
      if (_match_x57) {
        kk_integer_t _x_x1_10011;
        kk_string_t _x_x119;
        kk_define_string_literal(, _s_x120, 6, "{\"id\":", _ctx)
        _x_x119 = kk_string_dup(_s_x120, _ctx); /*string*/
        _x_x1_10011 = kk_string_count_pattern(line,_x_x119,kk_context()); /*int*/
        kk_box_t _x_x121 = kk_std_core_hnd__open_none1(kk_src_batch__ipc__new_mlift_main_loop_10015_fun122(_ctx), kk_integer_box(_x_x1_10011, _ctx), _ctx); /*10001*/
        x_10016 = kk_string_unbox(_x_x121); /*string*/
      }
      else {
        kk_string_t _x_x1_0_10012;
        kk_box_t _x_x129 = kk_std_core_hnd__open_none1(kk_src_batch__ipc__new_mlift_main_loop_10015_fun130(_ctx), kk_string_box(line), _ctx); /*10001*/
        _x_x1_0_10012 = kk_string_unbox(_x_x129); /*string*/
        kk_box_t _x_x133 = kk_std_core_hnd__open_none1(kk_src_batch__ipc__new_mlift_main_loop_10015_fun134(_ctx), kk_string_box(_x_x1_0_10012), _ctx); /*10001*/
        x_10016 = kk_string_unbox(_x_x133); /*string*/
      }
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_10016, _ctx);
        kk_box_t _x_x142 = kk_std_core_hnd_yield_extend(kk_src_batch__ipc__new_mlift_main_loop_10015_fun143(_ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x142); return kk_Unit;
      }
      {
        kk_src_batch__ipc__mlift_main_loop_10014(x_10016, _ctx); return kk_Unit;
      }
    }
  }
}
 
// Main loop - handles both single commands and batches


// lift anonymous function
struct kk_src_batch__ipc_main_loop_fun147__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_batch__ipc_main_loop_fun147(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_src_batch__ipc_new_main_loop_fun147(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_batch__ipc_main_loop_fun147, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_batch__ipc_main_loop_fun147(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x148 = kk_Unit;
  kk_string_t _x_x149 = kk_string_unbox(_b_x21); /*string*/
  kk_src_batch__ipc__mlift_main_loop_10015(_x_x149, _ctx);
  return kk_unit_box(_x_x148);
}


// lift anonymous function
struct kk_src_batch__ipc_main_loop_fun164__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_batch__ipc_main_loop_fun164(kk_function_t _fself, kk_box_t _b_x24, kk_context_t* _ctx);
static kk_function_t kk_src_batch__ipc_new_main_loop_fun164(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_batch__ipc_main_loop_fun164, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_batch__ipc_main_loop_fun164(kk_function_t _fself, kk_box_t _b_x24, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t n_0_37 = kk_integer_unbox(_b_x24, _ctx); /*int*/;
  kk_string_t _x_x165;
  bool _match_x49 = kk_integer_eq_borrow(n_0_37,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x49) {
    kk_integer_drop(n_0_37, _ctx);
    kk_define_string_literal(, _s_x166, 58, "{\"request_id\":\"batch\",\"results\":[],\"commands_processed\":0}", _ctx)
    _x_x165 = kk_string_dup(_s_x166, _ctx); /*string*/
  }
  else {
    bool _match_x50 = kk_integer_eq_borrow(n_0_37,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x50) {
      kk_integer_drop(n_0_37, _ctx);
      kk_define_string_literal(, _s_x167, 103, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":1}", _ctx)
      _x_x165 = kk_string_dup(_s_x167, _ctx); /*string*/
    }
    else {
      bool _match_x51 = kk_integer_eq_borrow(n_0_37,(kk_integer_from_small(2)),kk_context()); /*bool*/;
      if (_match_x51) {
        kk_integer_drop(n_0_37, _ctx);
        kk_define_string_literal(, _s_x168, 149, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":2}", _ctx)
        _x_x165 = kk_string_dup(_s_x168, _ctx); /*string*/
      }
      else {
        bool _match_x52;
        bool _brw_x53 = kk_integer_eq_borrow(n_0_37,(kk_integer_from_small(3)),kk_context()); /*bool*/;
        kk_integer_drop(n_0_37, _ctx);
        _match_x52 = _brw_x53; /*bool*/
        if (_match_x52) {
          kk_define_string_literal(, _s_x169, 195, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":3,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":3}", _ctx)
          _x_x165 = kk_string_dup(_s_x169, _ctx); /*string*/
        }
        else {
          kk_define_string_literal(, _s_x170, 287, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":3,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":4,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":5,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":5}", _ctx)
          _x_x165 = kk_string_dup(_s_x170, _ctx); /*string*/
        }
      }
    }
  }
  return kk_string_box(_x_x165);
}


// lift anonymous function
struct kk_src_batch__ipc_main_loop_fun172__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_batch__ipc_main_loop_fun172(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_src_batch__ipc_new_main_loop_fun172(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_batch__ipc_main_loop_fun172, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_batch__ipc_main_loop_fun172(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x173;
  kk_string_t _x_x174 = kk_string_unbox(_b_x27); /*string*/
  _x_x173 = kk_src_batch__ipc_extract_op(_x_x174, _ctx); /*string*/
  return kk_string_box(_x_x173);
}


// lift anonymous function
struct kk_src_batch__ipc_main_loop_fun176__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_batch__ipc_main_loop_fun176(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx);
static kk_function_t kk_src_batch__ipc_new_main_loop_fun176(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_batch__ipc_main_loop_fun176, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_batch__ipc_main_loop_fun176(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x177;
  kk_string_t _match_x48 = kk_string_unbox(_b_x32); /*string*/;
  if (kk_string_cmp_cstr_borrow(_match_x48, "ping", _ctx) == 0) {
    kk_string_drop(_match_x48, _ctx);
    kk_define_string_literal(, _s_x179, 13, "{\"pong\":true}", _ctx)
    _x_x177 = kk_string_dup(_s_x179, _ctx); /*string*/
    goto _match_x178;
  }
  if (kk_string_cmp_cstr_borrow(_match_x48, "status", _ctx) == 0) {
    kk_string_drop(_match_x48, _ctx);
    kk_define_string_literal(, _s_x180, 32, "{\"status\":\"ok\",\"batch_ipc\":true}", _ctx)
    _x_x177 = kk_string_dup(_s_x180, _ctx); /*string*/
    goto _match_x178;
  }
  if (kk_string_cmp_cstr_borrow(_match_x48, "emit", _ctx) == 0) {
    kk_string_drop(_match_x48, _ctx);
    kk_define_string_literal(, _s_x181, 16, "{\"emitted\":true}", _ctx)
    _x_x177 = kk_string_dup(_s_x181, _ctx); /*string*/
    goto _match_x178;
  }
  if (kk_string_cmp_cstr_borrow(_match_x48, "count", _ctx) == 0) {
    kk_string_drop(_match_x48, _ctx);
    kk_define_string_literal(, _s_x182, 11, "{\"count\":0}", _ctx)
    _x_x177 = kk_string_dup(_s_x182, _ctx); /*string*/
    goto _match_x178;
  }
  {
    kk_string_drop(_match_x48, _ctx);
    kk_define_string_literal(, _s_x183, 19, "{\"error\":\"unknown\"}", _ctx)
    _x_x177 = kk_string_dup(_s_x183, _ctx); /*string*/
  }
  _match_x178: ;
  return kk_string_box(_x_x177);
}


// lift anonymous function
struct kk_src_batch__ipc_main_loop_fun185__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_batch__ipc_main_loop_fun185(kk_function_t _fself, kk_box_t _b_x40, kk_context_t* _ctx);
static kk_function_t kk_src_batch__ipc_new_main_loop_fun185(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_batch__ipc_main_loop_fun185, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_batch__ipc_main_loop_fun185(kk_function_t _fself, kk_box_t _b_x40, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x186 = kk_Unit;
  kk_string_t _x_x187 = kk_string_unbox(_b_x40); /*string*/
  kk_src_batch__ipc__mlift_main_loop_10014(_x_x187, _ctx);
  return kk_unit_box(_x_x186);
}

kk_unit_t kk_src_batch__ipc_main_loop(kk_context_t* _ctx) { /* () -> io () */ 
  kk__tailcall: ;
  kk_string_t x_0_10018 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10018, _ctx);
    kk_box_t _x_x146 = kk_std_core_hnd_yield_extend(kk_src_batch__ipc_new_main_loop_fun147(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x146); return kk_Unit;
  }
  {
    bool _match_x44;
    kk_string_t _x_x150 = kk_string_dup(x_0_10018, _ctx); /*string*/
    kk_string_t _x_x151 = kk_string_empty(); /*string*/
    _match_x44 = kk_string_is_eq(_x_x150,_x_x151,kk_context()); /*bool*/
    if (_match_x44) {
      kk_string_drop(x_0_10018, _ctx);
      kk_Unit; return kk_Unit;
    }
    {
      bool _match_x45;
      kk_string_t _x_x153 = kk_string_dup(x_0_10018, _ctx); /*string*/
      kk_string_t _x_x154;
      kk_define_string_literal(, _s_x155, 6, "\"quit\"", _ctx)
      _x_x154 = kk_string_dup(_s_x155, _ctx); /*string*/
      _match_x45 = kk_string_contains(_x_x153,_x_x154,kk_context()); /*bool*/
      if (_match_x45) {
        kk_string_drop(x_0_10018, _ctx);
        kk_string_t _x_x156;
        kk_define_string_literal(, _s_x157, 20, "{\"status\":\"stopped\"}", _ctx)
        _x_x156 = kk_string_dup(_s_x157, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x156, _ctx); return kk_Unit;
      }
      {
        kk_string_t x_1_10021;
        bool _match_x47;
        kk_string_t _x_x158 = kk_string_dup(x_0_10018, _ctx); /*string*/
        kk_string_t _x_x159;
        kk_define_string_literal(, _s_x160, 11, "\"commands\":", _ctx)
        _x_x159 = kk_string_dup(_s_x160, _ctx); /*string*/
        _match_x47 = kk_string_contains(_x_x158,_x_x159,kk_context()); /*bool*/
        if (_match_x47) {
          kk_integer_t _x_x1_10011_0;
          kk_string_t _x_x161;
          kk_define_string_literal(, _s_x162, 6, "{\"id\":", _ctx)
          _x_x161 = kk_string_dup(_s_x162, _ctx); /*string*/
          _x_x1_10011_0 = kk_string_count_pattern(x_0_10018,_x_x161,kk_context()); /*int*/
          kk_box_t _x_x163 = kk_std_core_hnd__open_none1(kk_src_batch__ipc_new_main_loop_fun164(_ctx), kk_integer_box(_x_x1_10011_0, _ctx), _ctx); /*10001*/
          x_1_10021 = kk_string_unbox(_x_x163); /*string*/
        }
        else {
          kk_string_t _x_x1_0_10012_0;
          kk_box_t _x_x171 = kk_std_core_hnd__open_none1(kk_src_batch__ipc_new_main_loop_fun172(_ctx), kk_string_box(x_0_10018), _ctx); /*10001*/
          _x_x1_0_10012_0 = kk_string_unbox(_x_x171); /*string*/
          kk_box_t _x_x175 = kk_std_core_hnd__open_none1(kk_src_batch__ipc_new_main_loop_fun176(_ctx), kk_string_box(_x_x1_0_10012_0), _ctx); /*10001*/
          x_1_10021 = kk_string_unbox(_x_x175); /*string*/
        }
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_1_10021, _ctx);
          kk_box_t _x_x184 = kk_std_core_hnd_yield_extend(kk_src_batch__ipc_new_main_loop_fun185(_ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x184); return kk_Unit;
        }
        {
          kk_unit_t ___0 = kk_Unit;
          kk_std_core_console_printsln(x_1_10021, _ctx);
          { // tailcall
            goto kk__tailcall;
          }
        }
      }
    }
  }
}

// initialization
void kk_src_batch__ipc__init(kk_context_t* _ctx){
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
void kk_src_batch__ipc__done(kk_context_t* _ctx){
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
