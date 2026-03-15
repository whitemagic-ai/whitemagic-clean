#pragma once
#ifndef kk_src_circuit_H
#define kk_src_circuit_H
// Koka generated module: src/circuit, koka version: 3.2.2, platform: 64-bit
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

// value type src/circuit/circuit-state
enum kk_src_circuit__circuit_state_e {
  kk_src_circuit_Closed,
  kk_src_circuit_Open,
  kk_src_circuit_HalfOpen
};
typedef uint8_t kk_src_circuit__circuit_state;

static inline kk_src_circuit__circuit_state kk_src_circuit__new_Closed(kk_context_t* _ctx) {
  return kk_src_circuit_Closed;
}
static inline kk_src_circuit__circuit_state kk_src_circuit__new_Open(kk_context_t* _ctx) {
  return kk_src_circuit_Open;
}
static inline kk_src_circuit__circuit_state kk_src_circuit__new_HalfOpen(kk_context_t* _ctx) {
  return kk_src_circuit_HalfOpen;
}
static inline bool kk_src_circuit__is_Closed(kk_src_circuit__circuit_state x, kk_context_t* _ctx) {
  return (x == kk_src_circuit_Closed);
}
static inline bool kk_src_circuit__is_Open(kk_src_circuit__circuit_state x, kk_context_t* _ctx) {
  return (x == kk_src_circuit_Open);
}
static inline bool kk_src_circuit__is_HalfOpen(kk_src_circuit__circuit_state x, kk_context_t* _ctx) {
  return (x == kk_src_circuit_HalfOpen);
}
static inline kk_src_circuit__circuit_state kk_src_circuit__circuit_state_dup(kk_src_circuit__circuit_state _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_src_circuit__circuit_state_drop(kk_src_circuit__circuit_state _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_src_circuit__circuit_state_box(kk_src_circuit__circuit_state _x, kk_context_t* _ctx) {
  return kk_enum_box(_x);
}
static inline kk_src_circuit__circuit_state kk_src_circuit__circuit_state_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return (kk_src_circuit__circuit_state)kk_enum_unbox(_x);
}

// value declarations
 
// Automatically generated. Tests for the `Closed` constructor of the `:circuit-state` type.

static inline bool kk_src_circuit_is_closed(kk_src_circuit__circuit_state circuit_state, kk_context_t* _ctx) { /* (circuit-state : circuit-state) -> bool */ 
  if (kk_src_circuit__is_Closed(circuit_state, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Open` constructor of the `:circuit-state` type.

static inline bool kk_src_circuit_is_open(kk_src_circuit__circuit_state circuit_state, kk_context_t* _ctx) { /* (circuit-state : circuit-state) -> bool */ 
  if (kk_src_circuit__is_Open(circuit_state, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `HalfOpen` constructor of the `:circuit-state` type.

static inline bool kk_src_circuit_is_halfOpen(kk_src_circuit__circuit_state circuit_state, kk_context_t* _ctx) { /* (circuit-state : circuit-state) -> bool */ 
  if (kk_src_circuit__is_HalfOpen(circuit_state, _ctx)) {
    return true;
  }
  {
    return false;
  }
}

static inline kk_string_t kk_src_circuit_state_to_string(kk_src_circuit__circuit_state s, kk_context_t* _ctx) { /* (s : circuit-state) -> string */ 
  if (kk_src_circuit__is_Closed(s, _ctx)) {
    kk_define_string_literal(, _s_x100, 6, "closed", _ctx)
    return kk_string_dup(_s_x100, _ctx);
  }
  if (kk_src_circuit__is_Open(s, _ctx)) {
    kk_define_string_literal(, _s_x101, 4, "open", _ctx)
    return kk_string_dup(_s_x101, _ctx);
  }
  {
    kk_define_string_literal(, _s_x102, 9, "half-open", _ctx)
    return kk_string_dup(_s_x102, _ctx);
  }
}

kk_string_t kk_src_circuit_check_state(kk_src_circuit__circuit_state st, kk_integer_t failures, kk_integer_t successes, kk_integer_t tick, kk_integer_t last_fail, kk_context_t* _ctx); /* (st : circuit-state, failures : int, successes : int, tick : int, last-fail : int) -> string */ 

kk_string_t kk_src_circuit_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_unit_t kk_src_circuit_flush_stdout(kk_context_t* _ctx); /* () -> console/console () */ 

kk_unit_t kk_src_circuit__mlift_server_loop_10035(kk_string_t _c_x10003, kk_src_circuit__circuit_state _c_x10006, kk_integer_t _c_x10007, kk_integer_t last_fail, kk_integer_t new_tick, kk_string_t op, kk_integer_t total, kk_integer_t _c_x10008, kk_context_t* _ctx); /* (string, circuit-state, int, last-fail : int, new-tick : int, op : string, total : int, int) -> () */ 

kk_unit_t kk_src_circuit__mlift_server_loop_10036(kk_string_t _c_x10003_0, kk_src_circuit__circuit_state _c_x10006_0, kk_integer_t last_fail_0, kk_integer_t new_tick_0, kk_string_t op_0, kk_integer_t successes, kk_integer_t total_0, kk_integer_t _c_x10007_0, kk_context_t* _ctx); /* (string, circuit-state, last-fail : int, new-tick : int, op : string, successes : int, total : int, int) -> () */ 

kk_unit_t kk_src_circuit__mlift_server_loop_10037(kk_string_t _c_x10003_1, kk_integer_t failures, kk_integer_t last_fail_1, kk_integer_t new_tick_1, kk_string_t op_1, kk_integer_t successes_0, kk_integer_t total_1, kk_src_circuit__circuit_state _c_x10006_1, kk_context_t* _ctx); /* (string, failures : int, last-fail : int, new-tick : int, op : string, successes : int, total : int, circuit-state) -> () */ 

kk_unit_t kk_src_circuit__mlift_server_loop_10038(kk_integer_t failures_0, kk_integer_t last_fail_2, kk_integer_t new_tick_2, kk_string_t op_2, kk_src_circuit__circuit_state st, kk_integer_t successes_1, kk_integer_t total_2, kk_string_t _c_x10003_2, kk_context_t* _ctx); /* (failures : int, last-fail : int, new-tick : int, op : string, st : circuit-state, successes : int, total : int, string) -> () */ 

kk_unit_t kk_src_circuit__mlift_server_loop_10039(kk_integer_t failures_1, kk_integer_t last_fail_3, kk_src_circuit__circuit_state st_0, kk_integer_t successes_2, kk_integer_t tick, kk_integer_t total_3, kk_string_t line, kk_context_t* _ctx); /* (failures : int, last-fail : int, st : circuit-state, successes : int, tick : int, total : int, line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_circuit_server_loop(kk_integer_t tick_0, kk_src_circuit__circuit_state st_1, kk_integer_t failures_2, kk_integer_t successes_3, kk_integer_t last_fail_4, kk_integer_t total_4, kk_context_t* _ctx); /* (tick : int, st : circuit-state, failures : int, successes : int, last-fail : int, total : int) -> io () */ 

static inline kk_unit_t kk_src_circuit_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_src_circuit_server_loop(kk_integer_from_small(0), kk_src_circuit__new_Closed(_ctx), kk_integer_from_small(0), kk_integer_from_small(0), kk_integer_from_small(0), kk_integer_from_small(0), _ctx); return kk_Unit;
}

void kk_src_circuit__init(kk_context_t* _ctx);


void kk_src_circuit__done(kk_context_t* _ctx);

#endif // header
