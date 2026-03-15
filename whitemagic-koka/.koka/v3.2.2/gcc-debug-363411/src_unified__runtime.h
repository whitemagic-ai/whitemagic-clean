#pragma once
#ifndef kk_src_unified__runtime_H
#define kk_src_unified__runtime_H
// Koka generated module: src/unified_runtime, koka version: 3.2.2, platform: 64-bit
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
#include "std_num_float64.h"

// type declarations

// value type src/unified_runtime/complexity
enum kk_src_unified__runtime__complexity_e {
  kk_src_unified__runtime_Low,
  kk_src_unified__runtime_Medium,
  kk_src_unified__runtime_High
};
typedef uint8_t kk_src_unified__runtime__complexity;

static inline kk_src_unified__runtime__complexity kk_src_unified__runtime__new_Low(kk_context_t* _ctx) {
  return kk_src_unified__runtime_Low;
}
static inline kk_src_unified__runtime__complexity kk_src_unified__runtime__new_Medium(kk_context_t* _ctx) {
  return kk_src_unified__runtime_Medium;
}
static inline kk_src_unified__runtime__complexity kk_src_unified__runtime__new_High(kk_context_t* _ctx) {
  return kk_src_unified__runtime_High;
}
static inline bool kk_src_unified__runtime__is_Low(kk_src_unified__runtime__complexity x, kk_context_t* _ctx) {
  return (x == kk_src_unified__runtime_Low);
}
static inline bool kk_src_unified__runtime__is_Medium(kk_src_unified__runtime__complexity x, kk_context_t* _ctx) {
  return (x == kk_src_unified__runtime_Medium);
}
static inline bool kk_src_unified__runtime__is_High(kk_src_unified__runtime__complexity x, kk_context_t* _ctx) {
  return (x == kk_src_unified__runtime_High);
}
static inline kk_src_unified__runtime__complexity kk_src_unified__runtime__complexity_dup(kk_src_unified__runtime__complexity _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_src_unified__runtime__complexity_drop(kk_src_unified__runtime__complexity _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_src_unified__runtime__complexity_box(kk_src_unified__runtime__complexity _x, kk_context_t* _ctx) {
  return kk_enum_box(_x);
}
static inline kk_src_unified__runtime__complexity kk_src_unified__runtime__complexity_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return (kk_src_unified__runtime__complexity)kk_enum_unbox(_x);
}

// value type src/unified_runtime/event-type
enum kk_src_unified__runtime__event_type_e {
  kk_src_unified__runtime_SystemStarted,
  kk_src_unified__runtime_SystemStopped,
  kk_src_unified__runtime_MemoryCreated,
  kk_src_unified__runtime_MemoryUpdated,
  kk_src_unified__runtime_ThreatDetected,
  kk_src_unified__runtime_FlowStateEntered,
  kk_src_unified__runtime_FlowStateExited
};
typedef uint8_t kk_src_unified__runtime__event_type;

static inline kk_src_unified__runtime__event_type kk_src_unified__runtime__new_SystemStarted(kk_context_t* _ctx) {
  return kk_src_unified__runtime_SystemStarted;
}
static inline kk_src_unified__runtime__event_type kk_src_unified__runtime__new_SystemStopped(kk_context_t* _ctx) {
  return kk_src_unified__runtime_SystemStopped;
}
static inline kk_src_unified__runtime__event_type kk_src_unified__runtime__new_MemoryCreated(kk_context_t* _ctx) {
  return kk_src_unified__runtime_MemoryCreated;
}
static inline kk_src_unified__runtime__event_type kk_src_unified__runtime__new_MemoryUpdated(kk_context_t* _ctx) {
  return kk_src_unified__runtime_MemoryUpdated;
}
static inline kk_src_unified__runtime__event_type kk_src_unified__runtime__new_ThreatDetected(kk_context_t* _ctx) {
  return kk_src_unified__runtime_ThreatDetected;
}
static inline kk_src_unified__runtime__event_type kk_src_unified__runtime__new_FlowStateEntered(kk_context_t* _ctx) {
  return kk_src_unified__runtime_FlowStateEntered;
}
static inline kk_src_unified__runtime__event_type kk_src_unified__runtime__new_FlowStateExited(kk_context_t* _ctx) {
  return kk_src_unified__runtime_FlowStateExited;
}
static inline bool kk_src_unified__runtime__is_SystemStarted(kk_src_unified__runtime__event_type x, kk_context_t* _ctx) {
  return (x == kk_src_unified__runtime_SystemStarted);
}
static inline bool kk_src_unified__runtime__is_SystemStopped(kk_src_unified__runtime__event_type x, kk_context_t* _ctx) {
  return (x == kk_src_unified__runtime_SystemStopped);
}
static inline bool kk_src_unified__runtime__is_MemoryCreated(kk_src_unified__runtime__event_type x, kk_context_t* _ctx) {
  return (x == kk_src_unified__runtime_MemoryCreated);
}
static inline bool kk_src_unified__runtime__is_MemoryUpdated(kk_src_unified__runtime__event_type x, kk_context_t* _ctx) {
  return (x == kk_src_unified__runtime_MemoryUpdated);
}
static inline bool kk_src_unified__runtime__is_ThreatDetected(kk_src_unified__runtime__event_type x, kk_context_t* _ctx) {
  return (x == kk_src_unified__runtime_ThreatDetected);
}
static inline bool kk_src_unified__runtime__is_FlowStateEntered(kk_src_unified__runtime__event_type x, kk_context_t* _ctx) {
  return (x == kk_src_unified__runtime_FlowStateEntered);
}
static inline bool kk_src_unified__runtime__is_FlowStateExited(kk_src_unified__runtime__event_type x, kk_context_t* _ctx) {
  return (x == kk_src_unified__runtime_FlowStateExited);
}
static inline kk_src_unified__runtime__event_type kk_src_unified__runtime__event_type_dup(kk_src_unified__runtime__event_type _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_src_unified__runtime__event_type_drop(kk_src_unified__runtime__event_type _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_src_unified__runtime__event_type_box(kk_src_unified__runtime__event_type _x, kk_context_t* _ctx) {
  return kk_enum_box(_x);
}
static inline kk_src_unified__runtime__event_type kk_src_unified__runtime__event_type_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return (kk_src_unified__runtime__event_type)kk_enum_unbox(_x);
}

// type src/unified_runtime/runtime-state
struct kk_src_unified__runtime__runtime_state_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_unified__runtime__runtime_state;
struct kk_src_unified__runtime_Runtime_state {
  struct kk_src_unified__runtime__runtime_state_s _base;
  kk_integer_t event_count;
  kk_integer_t total_calls;
  kk_string_t last_event;
  kk_integer_t hot_paths_count;
  double total_time_ms;
};
static inline kk_src_unified__runtime__runtime_state kk_src_unified__runtime__base_Runtime_state(struct kk_src_unified__runtime_Runtime_state* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_unified__runtime__runtime_state kk_src_unified__runtime__new_Runtime_state(kk_reuse_t _at, int32_t _cpath, kk_integer_t event_count, kk_integer_t total_calls, double total_time_ms, kk_string_t last_event, kk_integer_t hot_paths_count, kk_context_t* _ctx) {
  struct kk_src_unified__runtime_Runtime_state* _con = kk_block_alloc_at_as(struct kk_src_unified__runtime_Runtime_state, _at, 4 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->event_count = event_count;
  _con->total_calls = total_calls;
  _con->last_event = last_event;
  _con->hot_paths_count = hot_paths_count;
  _con->total_time_ms = total_time_ms;
  return kk_src_unified__runtime__base_Runtime_state(_con, _ctx);
}
static inline struct kk_src_unified__runtime_Runtime_state* kk_src_unified__runtime__as_Runtime_state(kk_src_unified__runtime__runtime_state x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_unified__runtime_Runtime_state*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_unified__runtime__is_Runtime_state(kk_src_unified__runtime__runtime_state x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_unified__runtime__runtime_state kk_src_unified__runtime__runtime_state_dup(kk_src_unified__runtime__runtime_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_unified__runtime__runtime_state_drop(kk_src_unified__runtime__runtime_state _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_unified__runtime__runtime_state_box(kk_src_unified__runtime__runtime_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_unified__runtime__runtime_state kk_src_unified__runtime__runtime_state_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Tests for the `SystemStarted` constructor of the `:event-type` type.

static inline bool kk_src_unified__runtime_is_systemStarted(kk_src_unified__runtime__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_src_unified__runtime__is_SystemStarted(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `SystemStopped` constructor of the `:event-type` type.

static inline bool kk_src_unified__runtime_is_systemStopped(kk_src_unified__runtime__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_src_unified__runtime__is_SystemStopped(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `MemoryCreated` constructor of the `:event-type` type.

static inline bool kk_src_unified__runtime_is_memoryCreated(kk_src_unified__runtime__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_src_unified__runtime__is_MemoryCreated(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `MemoryUpdated` constructor of the `:event-type` type.

static inline bool kk_src_unified__runtime_is_memoryUpdated(kk_src_unified__runtime__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_src_unified__runtime__is_MemoryUpdated(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `ThreatDetected` constructor of the `:event-type` type.

static inline bool kk_src_unified__runtime_is_threatDetected(kk_src_unified__runtime__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_src_unified__runtime__is_ThreatDetected(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `FlowStateEntered` constructor of the `:event-type` type.

static inline bool kk_src_unified__runtime_is_flowStateEntered(kk_src_unified__runtime__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_src_unified__runtime__is_FlowStateEntered(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `FlowStateExited` constructor of the `:event-type` type.

static inline bool kk_src_unified__runtime_is_flowStateExited(kk_src_unified__runtime__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_src_unified__runtime__is_FlowStateExited(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Low` constructor of the `:complexity` type.

static inline bool kk_src_unified__runtime_is_low(kk_src_unified__runtime__complexity complexity, kk_context_t* _ctx) { /* (complexity : complexity) -> bool */ 
  if (kk_src_unified__runtime__is_Low(complexity, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Medium` constructor of the `:complexity` type.

static inline bool kk_src_unified__runtime_is_medium(kk_src_unified__runtime__complexity complexity, kk_context_t* _ctx) { /* (complexity : complexity) -> bool */ 
  if (kk_src_unified__runtime__is_Medium(complexity, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `High` constructor of the `:complexity` type.

static inline bool kk_src_unified__runtime_is_high(kk_src_unified__runtime__complexity complexity, kk_context_t* _ctx) { /* (complexity : complexity) -> bool */ 
  if (kk_src_unified__runtime__is_High(complexity, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Retrieves the `event-count` constructor field of the `:runtime-state` type.

static inline kk_integer_t kk_src_unified__runtime_runtime_state_fs_event_count(kk_src_unified__runtime__runtime_state _this, kk_context_t* _ctx) { /* (runtime-state) -> int */ 
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x295 = kk_src_unified__runtime__as_Runtime_state(_this, _ctx);
    kk_integer_t _x = _con_x295->event_count;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `total-calls` constructor field of the `:runtime-state` type.

static inline kk_integer_t kk_src_unified__runtime_runtime_state_fs_total_calls(kk_src_unified__runtime__runtime_state _this, kk_context_t* _ctx) { /* (runtime-state) -> int */ 
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x296 = kk_src_unified__runtime__as_Runtime_state(_this, _ctx);
    kk_integer_t _x = _con_x296->total_calls;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `total-time-ms` constructor field of the `:runtime-state` type.

static inline double kk_src_unified__runtime_runtime_state_fs_total_time_ms(kk_src_unified__runtime__runtime_state _this, kk_context_t* _ctx) { /* (runtime-state) -> float64 */ 
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x297 = kk_src_unified__runtime__as_Runtime_state(_this, _ctx);
    double _x = _con_x297->total_time_ms;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `last-event` constructor field of the `:runtime-state` type.

static inline kk_string_t kk_src_unified__runtime_runtime_state_fs_last_event(kk_src_unified__runtime__runtime_state _this, kk_context_t* _ctx) { /* (runtime-state) -> string */ 
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x298 = kk_src_unified__runtime__as_Runtime_state(_this, _ctx);
    kk_string_t _x = _con_x298->last_event;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `hot-paths-count` constructor field of the `:runtime-state` type.

static inline kk_integer_t kk_src_unified__runtime_runtime_state_fs_hot_paths_count(kk_src_unified__runtime__runtime_state _this, kk_context_t* _ctx) { /* (runtime-state) -> int */ 
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x299 = kk_src_unified__runtime__as_Runtime_state(_this, _ctx);
    kk_integer_t _x = _con_x299->hot_paths_count;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_unified__runtime__runtime_state kk_src_unified__runtime_runtime_state_fs__copy(kk_src_unified__runtime__runtime_state _this, kk_std_core_types__optional event_count, kk_std_core_types__optional total_calls, kk_std_core_types__optional total_time_ms, kk_std_core_types__optional last_event, kk_std_core_types__optional hot_paths_count, kk_context_t* _ctx); /* (runtime-state, event-count : ? int, total-calls : ? int, total-time-ms : ? float64, last-event : ? string, hot-paths-count : ? int) -> runtime-state */ 

kk_string_t kk_src_unified__runtime_event_type_to_string(kk_src_unified__runtime__event_type et, kk_context_t* _ctx); /* (et : event-type) -> string */ 

kk_src_unified__runtime__event_type kk_src_unified__runtime_string_to_event_type(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> event-type */ 

kk_src_unified__runtime__complexity kk_src_unified__runtime_estimate_complexity(double avg_time_ms, kk_integer_t call_count, kk_context_t* _ctx); /* (avg-time-ms : float64, call-count : int) -> complexity */ 

static inline kk_string_t kk_src_unified__runtime_complexity_to_string(kk_src_unified__runtime__complexity c, kk_context_t* _ctx) { /* (c : complexity) -> string */ 
  if (kk_src_unified__runtime__is_Low(c, _ctx)) {
    kk_define_string_literal(, _s_x317, 3, "low", _ctx)
    return kk_string_dup(_s_x317, _ctx);
  }
  if (kk_src_unified__runtime__is_Medium(c, _ctx)) {
    kk_define_string_literal(, _s_x318, 6, "medium", _ctx)
    return kk_string_dup(_s_x318, _ctx);
  }
  {
    kk_define_string_literal(, _s_x319, 4, "high", _ctx)
    return kk_string_dup(_s_x319, _ctx);
  }
}

kk_src_unified__runtime__runtime_state kk_src_unified__runtime_emit_and_profile(kk_src_unified__runtime__event_type et, double time_ms, kk_src_unified__runtime__runtime_state state, kk_context_t* _ctx); /* (et : event-type, time-ms : float64, state : runtime-state) -> runtime-state */ 

kk_std_core_types__tuple2 kk_src_unified__runtime_check_cascade_profiled(kk_src_unified__runtime__event_type et, kk_src_unified__runtime__runtime_state state, kk_context_t* _ctx); /* (et : event-type, state : runtime-state) -> (int, runtime-state) */ 

kk_string_t kk_src_unified__runtime_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_src_unified__runtime__event_type kk_src_unified__runtime_extract_event_type(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> event-type */ 

kk_string_t kk_src_unified__runtime_json_state(kk_src_unified__runtime__runtime_state s, kk_context_t* _ctx); /* (s : runtime-state) -> string */ 

kk_unit_t kk_src_unified__runtime__mlift_server_loop_10072(kk_string_t line, kk_string_t op, kk_src_unified__runtime__runtime_state state, kk_string_t _c_x10030, kk_context_t* _ctx); /* (line : string, op : string, state : runtime-state, string) -> () */ 

kk_unit_t kk_src_unified__runtime__mlift_server_loop_10073(kk_src_unified__runtime__runtime_state state_0, kk_string_t line_0, kk_context_t* _ctx); /* (state : runtime-state, line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_unified__runtime_server_loop(kk_src_unified__runtime__runtime_state state_2, kk_context_t* _ctx); /* (state : runtime-state) -> io () */ 

static inline kk_unit_t kk_src_unified__runtime_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_src_unified__runtime__runtime_state _x_x734;
  kk_string_t _x_x735;
  kk_define_string_literal(, _s_x736, 4, "none", _ctx)
  _x_x735 = kk_string_dup(_s_x736, _ctx); /*string*/
  _x_x734 = kk_src_unified__runtime__new_Runtime_state(kk_reuse_null, 0, kk_integer_from_small(0), kk_integer_from_small(0), 0x0p+0, _x_x735, kk_integer_from_small(0), _ctx); /*src/unified_runtime/runtime-state*/
  kk_src_unified__runtime_server_loop(_x_x734, _ctx); return kk_Unit;
}

void kk_src_unified__runtime__init(kk_context_t* _ctx);


void kk_src_unified__runtime__done(kk_context_t* _ctx);

#endif // header
