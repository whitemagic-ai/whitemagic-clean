// Koka generated module: src/prat_main, koka version: 3.2.2, platform: 64-bit
#include "src_prat__main.h"
 
// Flush stdout via inline C

kk_unit_t kk_src_prat__main_flush_stdout(kk_context_t* _ctx) { /* () -> console/console () */ 
  fflush(stdout); return kk_Unit;
}
 
// Route tool name to Gana name (inline pattern matching)

kk_string_t kk_src_prat__main_route_to_gana(kk_string_t tool, kk_context_t* _ctx) { /* (tool : string) -> string */ 
  if (kk_string_cmp_cstr_borrow(tool, "session_bootstrap", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x39, 9, "gana_horn", _ctx)
    return kk_string_dup(_s_x39, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "create_session", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x40, 9, "gana_horn", _ctx)
    return kk_string_dup(_s_x40, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "resume_session", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x41, 9, "gana_horn", _ctx)
    return kk_string_dup(_s_x41, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "create_memory", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x42, 9, "gana_neck", _ctx)
    return kk_string_dup(_s_x42, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "update_memory", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x43, 9, "gana_neck", _ctx)
    return kk_string_dup(_s_x43, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "delete_memory", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x44, 9, "gana_neck", _ctx)
    return kk_string_dup(_s_x44, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "remember", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x45, 9, "gana_neck", _ctx)
    return kk_string_dup(_s_x45, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "health_report", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x46, 9, "gana_root", _ctx)
    return kk_string_dup(_s_x46, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "rust_status", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x47, 9, "gana_root", _ctx)
    return kk_string_dup(_s_x47, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "check", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x48, 9, "gana_root", _ctx)
    return kk_string_dup(_s_x48, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "search_memories", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x49, 21, "gana_winnowing_basket", _ctx)
    return kk_string_dup(_s_x49, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "vector_search", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x50, 21, "gana_winnowing_basket", _ctx)
    return kk_string_dup(_s_x50, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "read_memory", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x51, 21, "gana_winnowing_basket", _ctx)
    return kk_string_dup(_s_x51, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "recall", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x52, 21, "gana_winnowing_basket", _ctx)
    return kk_string_dup(_s_x52, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "hybrid_recall", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x53, 21, "gana_winnowing_basket", _ctx)
    return kk_string_dup(_s_x53, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "graph_walk", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x54, 21, "gana_winnowing_basket", _ctx)
    return kk_string_dup(_s_x54, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "gnosis", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x55, 10, "gana_ghost", _ctx)
    return kk_string_dup(_s_x55, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "capabilities", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x56, 10, "gana_ghost", _ctx)
    return kk_string_dup(_s_x56, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "manifest", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x57, 10, "gana_ghost", _ctx)
    return kk_string_dup(_s_x57, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "dream", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x58, 14, "gana_abundance", _ctx)
    return kk_string_dup(_s_x58, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "serendipity_surface", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x59, 14, "gana_abundance", _ctx)
    return kk_string_dup(_s_x59, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "ensemble", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x60, 16, "gana_three_stars", _ctx)
    return kk_string_dup(_s_x60, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "think", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x61, 16, "gana_three_stars", _ctx)
    return kk_string_dup(_s_x61, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "galactic_dashboard", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x62, 9, "gana_void", _ctx)
    return kk_string_dup(_s_x62, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "galaxy_create", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x63, 9, "gana_void", _ctx)
    return kk_string_dup(_s_x63, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "galaxy_list", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x64, 9, "gana_void", _ctx)
    return kk_string_dup(_s_x64, _ctx);
  }
  {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x65, 10, "gana_ghost", _ctx)
    return kk_string_dup(_s_x65, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_prat__main__mlift_server_loop_10009_fun74__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_prat__main__mlift_server_loop_10009_fun74(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx);
static kk_function_t kk_src_prat__main__new_mlift_server_loop_10009_fun74(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_prat__main__mlift_server_loop_10009_fun74, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_prat__main__mlift_server_loop_10009_fun74(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x75;
  bool _match_x37;
  kk_string_t _x_x76 = kk_string_unbox(_b_x2); /*string*/
  kk_string_t _x_x77 = kk_string_empty(); /*string*/
  _match_x37 = kk_string_is_eq(_x_x76,_x_x77,kk_context()); /*bool*/
  if (_match_x37) {
    kk_define_string_literal(, _s_x79, 7, "unknown", _ctx)
    _x_x75 = kk_string_dup(_s_x79, _ctx); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x80, 15, "search_memories", _ctx)
    _x_x75 = kk_string_dup(_s_x80, _ctx); /*string*/
  }
  return kk_string_box(_x_x75);
}


// lift anonymous function
struct kk_src_prat__main__mlift_server_loop_10009_fun82__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_prat__main__mlift_server_loop_10009_fun82(kk_function_t _fself, kk_box_t _b_x8, kk_context_t* _ctx);
static kk_function_t kk_src_prat__main__new_mlift_server_loop_10009_fun82(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_prat__main__mlift_server_loop_10009_fun82, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_prat__main__mlift_server_loop_10009_fun82(kk_function_t _fself, kk_box_t _b_x8, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x83;
  kk_string_t _x_x84 = kk_string_unbox(_b_x8); /*string*/
  _x_x83 = kk_src_prat__main_route_to_gana(_x_x84, _ctx); /*string*/
  return kk_string_box(_x_x83);
}


// lift anonymous function
struct kk_src_prat__main__mlift_server_loop_10009_fun98__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_prat__main__mlift_server_loop_10009_fun98(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_prat__main__new_mlift_server_loop_10009_fun98(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_prat__main__mlift_server_loop_10009_fun98, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_prat__main__mlift_server_loop_10009_fun98(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x99 = kk_Unit;
  kk_src_prat__main_flush_stdout(_ctx);
  return kk_unit_box(_x_x99);
}

kk_unit_t kk_src_prat__main__mlift_server_loop_10009(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> <console/console,exn> () */ 
  bool _match_x36;
  kk_string_t _x_x70 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x71 = kk_string_empty(); /*string*/
  _match_x36 = kk_string_is_neq(_x_x70,_x_x71,kk_context()); /*bool*/
  if (_match_x36) {
    kk_string_t tool;
    kk_box_t _x_x73 = kk_std_core_hnd__open_none1(kk_src_prat__main__new_mlift_server_loop_10009_fun74(_ctx), kk_string_box(line), _ctx); /*10001*/
    tool = kk_string_unbox(_x_x73); /*string*/
    kk_string_t gana;
    kk_box_t _x_x81;
    kk_box_t _x_x85;
    kk_string_t _x_x86 = kk_string_dup(tool, _ctx); /*string*/
    _x_x85 = kk_string_box(_x_x86); /*10000*/
    _x_x81 = kk_std_core_hnd__open_none1(kk_src_prat__main__new_mlift_server_loop_10009_fun82(_ctx), _x_x85, _ctx); /*10001*/
    gana = kk_string_unbox(_x_x81); /*string*/
    kk_unit_t __ = kk_Unit;
    kk_string_t _x_x87;
    kk_string_t _x_x88;
    kk_define_string_literal(, _s_x89, 26, "{\"status\": \"ok\", \"gana\": \"", _ctx)
    _x_x88 = kk_string_dup(_s_x89, _ctx); /*string*/
    kk_string_t _x_x90;
    kk_string_t _x_x91;
    kk_string_t _x_x92;
    kk_define_string_literal(, _s_x93, 12, "\", \"tool\": \"", _ctx)
    _x_x92 = kk_string_dup(_s_x93, _ctx); /*string*/
    kk_string_t _x_x94;
    kk_string_t _x_x95;
    kk_define_string_literal(, _s_x96, 18, "\", \"routed\": true}", _ctx)
    _x_x95 = kk_string_dup(_s_x96, _ctx); /*string*/
    _x_x94 = kk_std_core_types__lp__plus__plus__rp_(tool, _x_x95, _ctx); /*string*/
    _x_x91 = kk_std_core_types__lp__plus__plus__rp_(_x_x92, _x_x94, _ctx); /*string*/
    _x_x90 = kk_std_core_types__lp__plus__plus__rp_(gana, _x_x91, _ctx); /*string*/
    _x_x87 = kk_std_core_types__lp__plus__plus__rp_(_x_x88, _x_x90, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x87, _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_box_t _x_x97 = kk_std_core_hnd__open_none0(kk_src_prat__main__new_mlift_server_loop_10009_fun98(_ctx), _ctx); /*10000*/
    kk_unit_unbox(_x_x97);
    kk_src_prat__main_server_loop(_ctx); return kk_Unit;
  }
  {
    kk_string_drop(line, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// Persistent server loop - handles multiple requests with routing


// lift anonymous function
struct kk_src_prat__main_server_loop_fun101__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_prat__main_server_loop_fun101(kk_function_t _fself, kk_box_t _b_x14, kk_context_t* _ctx);
static kk_function_t kk_src_prat__main_new_server_loop_fun101(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_prat__main_server_loop_fun101, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_prat__main_server_loop_fun101(kk_function_t _fself, kk_box_t _b_x14, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x102 = kk_Unit;
  kk_string_t _x_x103 = kk_string_unbox(_b_x14); /*string*/
  kk_src_prat__main__mlift_server_loop_10009(_x_x103, _ctx);
  return kk_unit_box(_x_x102);
}


// lift anonymous function
struct kk_src_prat__main_server_loop_fun108__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_prat__main_server_loop_fun108(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_src_prat__main_new_server_loop_fun108(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_prat__main_server_loop_fun108, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_prat__main_server_loop_fun108(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x109;
  bool _match_x35;
  kk_string_t _x_x110 = kk_string_unbox(_b_x17); /*string*/
  kk_string_t _x_x111 = kk_string_empty(); /*string*/
  _match_x35 = kk_string_is_eq(_x_x110,_x_x111,kk_context()); /*bool*/
  if (_match_x35) {
    kk_define_string_literal(, _s_x113, 7, "unknown", _ctx)
    _x_x109 = kk_string_dup(_s_x113, _ctx); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x114, 15, "search_memories", _ctx)
    _x_x109 = kk_string_dup(_s_x114, _ctx); /*string*/
  }
  return kk_string_box(_x_x109);
}


// lift anonymous function
struct kk_src_prat__main_server_loop_fun116__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_prat__main_server_loop_fun116(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx);
static kk_function_t kk_src_prat__main_new_server_loop_fun116(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_prat__main_server_loop_fun116, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_prat__main_server_loop_fun116(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x117;
  kk_string_t _x_x118 = kk_string_unbox(_b_x23); /*string*/
  _x_x117 = kk_src_prat__main_route_to_gana(_x_x118, _ctx); /*string*/
  return kk_string_box(_x_x117);
}


// lift anonymous function
struct kk_src_prat__main_server_loop_fun132__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_prat__main_server_loop_fun132(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_prat__main_new_server_loop_fun132(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_prat__main_server_loop_fun132, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_prat__main_server_loop_fun132(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x133 = kk_Unit;
  kk_src_prat__main_flush_stdout(_ctx);
  return kk_unit_box(_x_x133);
}

kk_unit_t kk_src_prat__main_server_loop(kk_context_t* _ctx) { /* () -> io () */ 
  kk__tailcall: ;
  kk_string_t x_10011 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10011, _ctx);
    kk_box_t _x_x100 = kk_std_core_hnd_yield_extend(kk_src_prat__main_new_server_loop_fun101(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x100); return kk_Unit;
  }
  {
    bool _match_x34;
    kk_string_t _x_x104 = kk_string_dup(x_10011, _ctx); /*string*/
    kk_string_t _x_x105 = kk_string_empty(); /*string*/
    _match_x34 = kk_string_is_neq(_x_x104,_x_x105,kk_context()); /*bool*/
    if (_match_x34) {
      kk_string_t tool_0;
      kk_box_t _x_x107 = kk_std_core_hnd__open_none1(kk_src_prat__main_new_server_loop_fun108(_ctx), kk_string_box(x_10011), _ctx); /*10001*/
      tool_0 = kk_string_unbox(_x_x107); /*string*/
      kk_string_t gana_0;
      kk_box_t _x_x115;
      kk_box_t _x_x119;
      kk_string_t _x_x120 = kk_string_dup(tool_0, _ctx); /*string*/
      _x_x119 = kk_string_box(_x_x120); /*10000*/
      _x_x115 = kk_std_core_hnd__open_none1(kk_src_prat__main_new_server_loop_fun116(_ctx), _x_x119, _ctx); /*10001*/
      gana_0 = kk_string_unbox(_x_x115); /*string*/
      kk_unit_t ___1 = kk_Unit;
      kk_string_t _x_x121;
      kk_string_t _x_x122;
      kk_define_string_literal(, _s_x123, 26, "{\"status\": \"ok\", \"gana\": \"", _ctx)
      _x_x122 = kk_string_dup(_s_x123, _ctx); /*string*/
      kk_string_t _x_x124;
      kk_string_t _x_x125;
      kk_string_t _x_x126;
      kk_define_string_literal(, _s_x127, 12, "\", \"tool\": \"", _ctx)
      _x_x126 = kk_string_dup(_s_x127, _ctx); /*string*/
      kk_string_t _x_x128;
      kk_string_t _x_x129;
      kk_define_string_literal(, _s_x130, 18, "\", \"routed\": true}", _ctx)
      _x_x129 = kk_string_dup(_s_x130, _ctx); /*string*/
      _x_x128 = kk_std_core_types__lp__plus__plus__rp_(tool_0, _x_x129, _ctx); /*string*/
      _x_x125 = kk_std_core_types__lp__plus__plus__rp_(_x_x126, _x_x128, _ctx); /*string*/
      _x_x124 = kk_std_core_types__lp__plus__plus__rp_(gana_0, _x_x125, _ctx); /*string*/
      _x_x121 = kk_std_core_types__lp__plus__plus__rp_(_x_x122, _x_x124, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x121, _ctx);
      kk_unit_t ___0_0 = kk_Unit;
      kk_box_t _x_x131 = kk_std_core_hnd__open_none0(kk_src_prat__main_new_server_loop_fun132(_ctx), _ctx); /*10000*/
      kk_unit_unbox(_x_x131);
      { // tailcall
        goto kk__tailcall;
      }
    }
    {
      kk_string_drop(x_10011, _ctx);
      kk_Unit; return kk_Unit;
    }
  }
}
 
// Main entry point - persistent JSON dispatch loop


// lift anonymous function
struct kk_src_prat__main_main_fun135__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_prat__main_main_fun135(kk_function_t _fself, kk_box_t _b_x30, kk_context_t* _ctx);
static kk_function_t kk_src_prat__main_new_main_fun135(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_prat__main_main_fun135, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_prat__main_main_fun135(kk_function_t _fself, kk_box_t _b_x30, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x136 = kk_Unit;
  kk_unit_t _x_x137 = kk_Unit;
  kk_unit_unbox(_b_x30);
  kk_src_prat__main__mlift_main_10010(_x_x137, _ctx);
  return kk_unit_box(_x_x136);
}

kk_unit_t kk_src_prat__main_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_unit_t x_10014 = kk_Unit;
  kk_src_prat__main_server_loop(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x134 = kk_std_core_hnd_yield_extend(kk_src_prat__main_new_main_fun135(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x134); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}

// initialization
void kk_src_prat__main__init(kk_context_t* _ctx){
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
void kk_src_prat__main__done(kk_context_t* _ctx){
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
