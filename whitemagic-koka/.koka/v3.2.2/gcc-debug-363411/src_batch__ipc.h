#pragma once
#ifndef kk_src_batch__ipc_H
#define kk_src_batch__ipc_H
// Koka generated module: src/batch_ipc, koka version: 3.2.2, platform: 64-bit
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

kk_string_t kk_src_batch__ipc_execute_cmd(kk_string_t op, kk_context_t* _ctx); /* (op : string) -> string */ 

kk_string_t kk_src_batch__ipc_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 
 
// Count commands in JSON

static inline kk_integer_t kk_src_batch__ipc_count_cmds(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> int */ 
  kk_string_t _x_x99;
  kk_define_string_literal(, _s_x100, 6, "{\"id\":", _ctx)
  _x_x99 = kk_string_dup(_s_x100, _ctx); /*string*/
  return kk_string_count_pattern(line,_x_x99,kk_context());
}
 
// Is batch request?

static inline bool kk_src_batch__ipc_is_batch(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> bool */ 
  kk_string_t _x_x101;
  kk_define_string_literal(, _s_x102, 11, "\"commands\":", _ctx)
  _x_x101 = kk_string_dup(_s_x102, _ctx); /*string*/
  return kk_string_contains(line,_x_x101,kk_context());
}

kk_string_t kk_src_batch__ipc_batch_response(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> string */ 

kk_unit_t kk_src_batch__ipc__mlift_main_loop_10014(kk_string_t _c_x10001, kk_context_t* _ctx); /* (string) -> () */ 

kk_unit_t kk_src_batch__ipc__mlift_main_loop_10015(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_batch__ipc_main_loop(kk_context_t* _ctx); /* () -> io () */ 

static inline kk_unit_t kk_src_batch__ipc_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x188;
  kk_define_string_literal(, _s_x189, 53, "{\"status\":\"started\",\"batch_ipc\":true,\"version\":\"1.0\"}", _ctx)
  _x_x188 = kk_string_dup(_s_x189, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x188, _ctx);
  kk_src_batch__ipc_main_loop(_ctx); return kk_Unit;
}

void kk_src_batch__ipc__init(kk_context_t* _ctx);


void kk_src_batch__ipc__done(kk_context_t* _ctx);

#endif // header
