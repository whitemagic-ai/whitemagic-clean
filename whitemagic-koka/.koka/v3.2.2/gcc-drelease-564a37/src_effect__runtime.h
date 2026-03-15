#pragma once
#ifndef kk_src_effect__runtime_H
#define kk_src_effect__runtime_H
// Koka generated module: src/effect_runtime, koka version: 3.2.2, platform: 64-bit
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

// type src/effect_runtime/runtime-state
struct kk_src_effect__runtime__runtime_state_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_effect__runtime__runtime_state;
struct kk_src_effect__runtime_Runtime_state {
  struct kk_src_effect__runtime__runtime_state_s _base;
  kk_std_core_types__list events;
  kk_std_core_types__list profiles;
  kk_integer_t total_ops;
};
static inline kk_src_effect__runtime__runtime_state kk_src_effect__runtime__base_Runtime_state(struct kk_src_effect__runtime_Runtime_state* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_effect__runtime__runtime_state kk_src_effect__runtime__new_Runtime_state(kk_reuse_t _at, int32_t _cpath, kk_std_core_types__list events, kk_std_core_types__list profiles, kk_integer_t total_ops, kk_context_t* _ctx) {
  struct kk_src_effect__runtime_Runtime_state* _con = kk_block_alloc_at_as(struct kk_src_effect__runtime_Runtime_state, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->events = events;
  _con->profiles = profiles;
  _con->total_ops = total_ops;
  return kk_src_effect__runtime__base_Runtime_state(_con, _ctx);
}
static inline struct kk_src_effect__runtime_Runtime_state* kk_src_effect__runtime__as_Runtime_state(kk_src_effect__runtime__runtime_state x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_effect__runtime_Runtime_state*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_effect__runtime__is_Runtime_state(kk_src_effect__runtime__runtime_state x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_effect__runtime__runtime_state kk_src_effect__runtime__runtime_state_dup(kk_src_effect__runtime__runtime_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_effect__runtime__runtime_state_drop(kk_src_effect__runtime__runtime_state _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_effect__runtime__runtime_state_box(kk_src_effect__runtime__runtime_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_effect__runtime__runtime_state kk_src_effect__runtime__runtime_state_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Emit an event, returning new state

static inline kk_std_core_types__list kk_src_effect__runtime_emit_effect(kk_string_t source, kk_gan__ying__event_type et, kk_std_core_types__list state, kk_context_t* _ctx) { /* (source : string, et : gan_ying/event-type, state : list<gan_ying/resonance-event>) -> list<gan_ying/resonance-event> */ 
  kk_box_t _x_x250;
  kk_gan__ying__resonance_event _x_x251;
  kk_string_t _x_x252 = kk_string_empty(); /*string*/
  _x_x251 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, source, et, _x_x252, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x250 = kk_gan__ying__resonance_event_box(_x_x251, _ctx); /*10021*/
  return kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x250, state, _ctx);
}
 
// Profile an operation, returning new state

static inline kk_std_core_types__list kk_src_effect__runtime_profile_effect(kk_string_t name, double duration, kk_std_core_types__list state, kk_context_t* _ctx) { /* (name : string, duration : float64, state : list<hot_paths/path-profile>) -> list<hot_paths/path-profile> */ 
  kk_box_t _x_x254;
  kk_hot__paths__path_profile _x_x255 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, name, kk_integer_from_small(1), duration, duration, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_Compute(_ctx), _ctx); /*hot_paths/path-profile*/
  _x_x254 = kk_hot__paths__path_profile_box(_x_x255, _ctx); /*10021*/
  return kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x254, state, _ctx);
}
 
// Trace an operation (side-effect only, returns unit)

static inline kk_unit_t kk_src_effect__runtime_trace_effect(kk_string_t op, kk_string_t details, kk_context_t* _ctx) { /* (op : string, details : string) -> io () */ 
  kk_string_t _x_x256;
  kk_string_t _x_x257;
  kk_define_string_literal(, _s_x258, 8, "[TRACE] ", _ctx)
  _x_x257 = kk_string_dup(_s_x258, _ctx); /*string*/
  kk_string_t _x_x259;
  kk_string_t _x_x260;
  kk_string_t _x_x261;
  kk_define_string_literal(, _s_x262, 2, ": ", _ctx)
  _x_x261 = kk_string_dup(_s_x262, _ctx); /*string*/
  _x_x260 = kk_std_core_types__lp__plus__plus__rp_(_x_x261, details, _ctx); /*string*/
  _x_x259 = kk_std_core_types__lp__plus__plus__rp_(op, _x_x260, _ctx); /*string*/
  _x_x256 = kk_std_core_types__lp__plus__plus__rp_(_x_x257, _x_x259, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x256, _ctx); return kk_Unit;
}
 
// Automatically generated. Retrieves the `events` constructor field of the `:runtime-state` type.

static inline kk_std_core_types__list kk_src_effect__runtime_runtime_state_fs_events(kk_src_effect__runtime__runtime_state _this, kk_context_t* _ctx) { /* (runtime-state) -> list<gan_ying/resonance-event> */ 
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x263 = kk_src_effect__runtime__as_Runtime_state(_this, _ctx);
    kk_std_core_types__list _x = _con_x263->events;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `profiles` constructor field of the `:runtime-state` type.

static inline kk_std_core_types__list kk_src_effect__runtime_runtime_state_fs_profiles(kk_src_effect__runtime__runtime_state _this, kk_context_t* _ctx) { /* (runtime-state) -> list<hot_paths/path-profile> */ 
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x264 = kk_src_effect__runtime__as_Runtime_state(_this, _ctx);
    kk_std_core_types__list _x = _con_x264->profiles;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `total-ops` constructor field of the `:runtime-state` type.

static inline kk_integer_t kk_src_effect__runtime_runtime_state_fs_total_ops(kk_src_effect__runtime__runtime_state _this, kk_context_t* _ctx) { /* (runtime-state) -> int */ 
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x265 = kk_src_effect__runtime__as_Runtime_state(_this, _ctx);
    kk_integer_t _x = _con_x265->total_ops;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_effect__runtime__runtime_state kk_src_effect__runtime_runtime_state_fs__copy(kk_src_effect__runtime__runtime_state _this, kk_std_core_types__optional events, kk_std_core_types__optional profiles, kk_std_core_types__optional total_ops, kk_context_t* _ctx); /* (runtime-state, events : ? (list<gan_ying/resonance-event>), profiles : ? (list<hot_paths/path-profile>), total-ops : ? int) -> runtime-state */ 

kk_src_effect__runtime__runtime_state kk_src_effect__runtime_emit_profiled(kk_string_t source, kk_gan__ying__event_type et, kk_src_effect__runtime__runtime_state state, kk_context_t* _ctx); /* (source : string, et : gan_ying/event-type, state : runtime-state) -> runtime-state */ 

kk_std_core_types__tuple2 kk_src_effect__runtime_cascade_profiled(kk_gan__ying__event_type et, kk_src_effect__runtime__runtime_state state, kk_context_t* _ctx); /* (et : gan_ying/event-type, state : runtime-state) -> (int, runtime-state) */ 

kk_string_t kk_src_effect__runtime_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_gan__ying__event_type kk_src_effect__runtime_extract_event_type(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> gan_ying/event-type */ 

kk_string_t kk_src_effect__runtime_json_state(kk_src_effect__runtime__runtime_state s, kk_context_t* _ctx); /* (s : runtime-state) -> string */ 

kk_unit_t kk_src_effect__runtime__mlift_server_loop_10201(kk_string_t line, kk_string_t op, kk_src_effect__runtime__runtime_state state, kk_string_t _c_x10155, kk_context_t* _ctx); /* (line : string, op : string, state : runtime-state, string) -> () */ 

kk_unit_t kk_src_effect__runtime__mlift_server_loop_10202(kk_src_effect__runtime__runtime_state state_0, kk_string_t line_0, kk_context_t* _ctx); /* (state : runtime-state, line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_effect__runtime_server_loop(kk_src_effect__runtime__runtime_state state_1, kk_context_t* _ctx); /* (state : runtime-state) -> io () */ 

static inline kk_unit_t kk_src_effect__runtime_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x719;
  kk_define_string_literal(, _s_x720, 112, "{\"status\":\"started\",\"effect_runtime\":true,\"version\":\"4.0\",\"features\":[\"state_effects\",\"emit\",\"profile\",\"trace\"]}", _ctx)
  _x_x719 = kk_string_dup(_s_x720, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x719, _ctx);
  kk_src_effect__runtime__runtime_state _x_x721 = kk_src_effect__runtime__new_Runtime_state(kk_reuse_null, 0, kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), kk_integer_from_small(0), _ctx); /*src/effect_runtime/runtime-state*/
  kk_src_effect__runtime_server_loop(_x_x721, _ctx); return kk_Unit;
}

void kk_src_effect__runtime__init(kk_context_t* _ctx);


void kk_src_effect__runtime__done(kk_context_t* _ctx);

#endif // header
