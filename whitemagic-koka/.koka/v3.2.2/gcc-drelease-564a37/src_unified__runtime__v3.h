#pragma once
#ifndef kk_src_unified__runtime__v3_H
#define kk_src_unified__runtime__v3_H
// Koka generated module: src/unified_runtime_v3, koka version: 3.2.2, platform: 64-bit
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
#include "gan__ying.h"
#include "hot__paths.h"

// type declarations

// type src/unified_runtime_v3/unified-state
struct kk_src_unified__runtime__v3__unified_state_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_unified__runtime__v3__unified_state;
struct kk_src_unified__runtime__v3_Unified_state {
  struct kk_src_unified__runtime__v3__unified_state_s _base;
  kk_std_core_types__list events;
  kk_std_core_types__list profiles;
  kk_integer_t total_ops;
  kk_integer_t batch_count;
  double session_start;
};
static inline kk_src_unified__runtime__v3__unified_state kk_src_unified__runtime__v3__base_Unified_state(struct kk_src_unified__runtime__v3_Unified_state* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_unified__runtime__v3__unified_state kk_src_unified__runtime__v3__new_Unified_state(kk_reuse_t _at, int32_t _cpath, kk_std_core_types__list events, kk_std_core_types__list profiles, kk_integer_t total_ops, kk_integer_t batch_count, double session_start, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v3_Unified_state* _con = kk_block_alloc_at_as(struct kk_src_unified__runtime__v3_Unified_state, _at, 4 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->events = events;
  _con->profiles = profiles;
  _con->total_ops = total_ops;
  _con->batch_count = batch_count;
  _con->session_start = session_start;
  return kk_src_unified__runtime__v3__base_Unified_state(_con, _ctx);
}
static inline struct kk_src_unified__runtime__v3_Unified_state* kk_src_unified__runtime__v3__as_Unified_state(kk_src_unified__runtime__v3__unified_state x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_unified__runtime__v3_Unified_state*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_unified__runtime__v3__is_Unified_state(kk_src_unified__runtime__v3__unified_state x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_unified__runtime__v3__unified_state kk_src_unified__runtime__v3__unified_state_dup(kk_src_unified__runtime__v3__unified_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_unified__runtime__v3__unified_state_drop(kk_src_unified__runtime__v3__unified_state _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_unified__runtime__v3__unified_state_box(kk_src_unified__runtime__v3__unified_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_unified__runtime__v3__unified_state kk_src_unified__runtime__v3__unified_state_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `events` constructor field of the `:unified-state` type.

static inline kk_std_core_types__list kk_src_unified__runtime__v3_unified_state_fs_events(kk_src_unified__runtime__v3__unified_state _this, kk_context_t* _ctx) { /* (unified-state) -> list<gan_ying/resonance-event> */ 
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x305 = kk_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
    kk_std_core_types__list _x = _con_x305->events;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `profiles` constructor field of the `:unified-state` type.

static inline kk_std_core_types__list kk_src_unified__runtime__v3_unified_state_fs_profiles(kk_src_unified__runtime__v3__unified_state _this, kk_context_t* _ctx) { /* (unified-state) -> list<hot_paths/path-profile> */ 
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x306 = kk_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
    kk_std_core_types__list _x = _con_x306->profiles;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `total-ops` constructor field of the `:unified-state` type.

static inline kk_integer_t kk_src_unified__runtime__v3_unified_state_fs_total_ops(kk_src_unified__runtime__v3__unified_state _this, kk_context_t* _ctx) { /* (unified-state) -> int */ 
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x307 = kk_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
    kk_integer_t _x = _con_x307->total_ops;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `batch-count` constructor field of the `:unified-state` type.

static inline kk_integer_t kk_src_unified__runtime__v3_unified_state_fs_batch_count(kk_src_unified__runtime__v3__unified_state _this, kk_context_t* _ctx) { /* (unified-state) -> int */ 
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x308 = kk_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
    kk_integer_t _x = _con_x308->batch_count;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `session-start` constructor field of the `:unified-state` type.

static inline double kk_src_unified__runtime__v3_unified_state_fs_session_start(kk_src_unified__runtime__v3__unified_state _this, kk_context_t* _ctx) { /* (unified-state) -> float64 */ 
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x309 = kk_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
    double _x = _con_x309->session_start;
    return _x;
  }
}

kk_src_unified__runtime__v3__unified_state kk_src_unified__runtime__v3_unified_state_fs__copy(kk_src_unified__runtime__v3__unified_state _this, kk_std_core_types__optional events, kk_std_core_types__optional profiles, kk_std_core_types__optional total_ops, kk_std_core_types__optional batch_count, kk_std_core_types__optional session_start, kk_context_t* _ctx); /* (unified-state, events : ? (list<gan_ying/resonance-event>), profiles : ? (list<hot_paths/path-profile>), total-ops : ? int, batch-count : ? int, session-start : ? float64) -> unified-state */ 

kk_src_unified__runtime__v3__unified_state kk_src_unified__runtime__v3_emit_profiled(kk_gan__ying__event_type et, kk_string_t source, kk_src_unified__runtime__v3__unified_state state, kk_context_t* _ctx); /* (et : gan_ying/event-type, source : string, state : unified-state) -> unified-state */ 

kk_std_core_types__tuple2 kk_src_unified__runtime__v3_cascade_profiled(kk_gan__ying__event_type et, kk_src_unified__runtime__v3__unified_state state, kk_context_t* _ctx); /* (et : gan_ying/event-type, state : unified-state) -> (int, unified-state) */ 

static inline kk_integer_t kk_src_unified__runtime__v3_count_cmds(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> int */ 
  kk_string_t _x_x357;
  kk_define_string_literal(, _s_x358, 6, "{\"id\":", _ctx)
  _x_x357 = kk_string_dup(_s_x358, _ctx); /*string*/
  return kk_string_count_pattern(line,_x_x357,kk_context());
}

static inline bool kk_src_unified__runtime__v3_is_batch(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> bool */ 
  kk_string_t _x_x359;
  kk_define_string_literal(, _s_x360, 11, "\"commands\":", _ctx)
  _x_x359 = kk_string_dup(_s_x360, _ctx); /*string*/
  return kk_string_contains(line,_x_x359,kk_context());
}

kk_string_t kk_src_unified__runtime__v3_batch_response(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> string */ 

kk_string_t kk_src_unified__runtime__v3_json_state(kk_src_unified__runtime__v3__unified_state s, kk_context_t* _ctx); /* (s : unified-state) -> string */ 

kk_string_t kk_src_unified__runtime__v3_execute_cmd(kk_string_t op, kk_src_unified__runtime__v3__unified_state state, kk_context_t* _ctx); /* (op : string, state : unified-state) -> string */ 

kk_string_t kk_src_unified__runtime__v3_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_gan__ying__event_type kk_src_unified__runtime__v3_extract_event_type(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> gan_ying/event-type */ 

kk_std_core_types__list kk_src_unified__runtime__v3__lift_server_loop_10148(kk_std_core_types__list _uniq_xs_10143, kk_context_t* _ctx); /* (list<hot_paths/path-profile>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<hot_paths/path-profile> */ 

kk_string_t kk_src_unified__runtime__v3__mlift_server_loop_10227(kk_std_core_types__list _y_x10153, kk_context_t* _ctx); /* (list<hot_paths/path-profile>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */ 

kk_unit_t kk_src_unified__runtime__v3__mlift_server_loop_10228(kk_string_t line, kk_src_unified__runtime__v3__unified_state state, kk_string_t _c_x10155, kk_context_t* _ctx); /* (line : string, state : unified-state, string) -> () */ 

kk_unit_t kk_src_unified__runtime__v3__mlift_server_loop_10229(kk_src_unified__runtime__v3__unified_state state_0, kk_string_t line_0, kk_context_t* _ctx); /* (state : unified-state, line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_unified__runtime__v3_server_loop(kk_src_unified__runtime__v3__unified_state state_2, kk_context_t* _ctx); /* (state : unified-state) -> io () */ 

static inline kk_unit_t kk_src_unified__runtime__v3_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x865;
  kk_define_string_literal(, _s_x866, 117, "{\"status\":\"started\",\"unified_runtime\":true,\"version\":\"3.0\",\"features\":[\"batch_ipc\",\"events\",\"profiling\",\"hot_paths\"]}", _ctx)
  _x_x865 = kk_string_dup(_s_x866, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x865, _ctx);
  kk_src_unified__runtime__v3__unified_state _x_x867 = kk_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), kk_integer_from_small(0), kk_integer_from_small(0), 0x0p+0, _ctx); /*src/unified_runtime_v3/unified-state*/
  kk_src_unified__runtime__v3_server_loop(_x_x867, _ctx); return kk_Unit;
}

void kk_src_unified__runtime__v3__init(kk_context_t* _ctx);


void kk_src_unified__runtime__v3__done(kk_context_t* _ctx);

#endif // header
