#pragma once
#ifndef kk_src_prat__main_H
#define kk_src_prat__main_H
// Koka generated module: src/prat_main, koka version: 3.2.2, platform: 64-bit
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
#include "std_os_readline.h"

// type declarations

// value declarations

kk_unit_t kk_src_prat__main_flush_stdout(kk_context_t* _ctx); /* () -> console/console () */ 

kk_string_t kk_src_prat__main_route_to_gana(kk_string_t tool, kk_context_t* _ctx); /* (tool : string) -> string */ 
 
// Extract tool name from JSON (simplified - just returns fixed tool for benchmarking)

static inline kk_string_t kk_src_prat__main_extract_tool(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x38;
  kk_string_t _x_x66 = kk_string_empty(); /*string*/
  _match_x38 = kk_string_is_eq(line,_x_x66,kk_context()); /*bool*/
  if (_match_x38) {
    kk_define_string_literal(, _s_x68, 7, "unknown", _ctx)
    return kk_string_dup(_s_x68, _ctx);
  }
  {
    kk_define_string_literal(, _s_x69, 15, "search_memories", _ctx)
    return kk_string_dup(_s_x69, _ctx);
  }
}

kk_unit_t kk_src_prat__main__mlift_server_loop_10009(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_prat__main_server_loop(kk_context_t* _ctx); /* () -> io () */ 
 
// monadic lift

static inline kk_unit_t kk_src_prat__main__mlift_main_10010(kk_unit_t wild__, kk_context_t* _ctx) { /* (wild_ : ()) -> io () */ 
  kk_Unit; return kk_Unit;
}

kk_unit_t kk_src_prat__main_main(kk_context_t* _ctx); /* () -> io () */ 

void kk_src_prat__main__init(kk_context_t* _ctx);


void kk_src_prat__main__done(kk_context_t* _ctx);

#endif // header
