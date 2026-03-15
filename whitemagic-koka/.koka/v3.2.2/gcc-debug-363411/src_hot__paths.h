#pragma once
#ifndef kk_src_hot__paths_H
#define kk_src_hot__paths_H
// Koka generated module: src/hot_paths, koka version: 3.2.2, platform: 64-bit
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

// value type src/hot_paths/complexity
enum kk_src_hot__paths__complexity_e {
  kk_src_hot__paths_Low,
  kk_src_hot__paths_Medium,
  kk_src_hot__paths_High
};
typedef uint8_t kk_src_hot__paths__complexity;

static inline kk_src_hot__paths__complexity kk_src_hot__paths__new_Low(kk_context_t* _ctx) {
  return kk_src_hot__paths_Low;
}
static inline kk_src_hot__paths__complexity kk_src_hot__paths__new_Medium(kk_context_t* _ctx) {
  return kk_src_hot__paths_Medium;
}
static inline kk_src_hot__paths__complexity kk_src_hot__paths__new_High(kk_context_t* _ctx) {
  return kk_src_hot__paths_High;
}
static inline bool kk_src_hot__paths__is_Low(kk_src_hot__paths__complexity x, kk_context_t* _ctx) {
  return (x == kk_src_hot__paths_Low);
}
static inline bool kk_src_hot__paths__is_Medium(kk_src_hot__paths__complexity x, kk_context_t* _ctx) {
  return (x == kk_src_hot__paths_Medium);
}
static inline bool kk_src_hot__paths__is_High(kk_src_hot__paths__complexity x, kk_context_t* _ctx) {
  return (x == kk_src_hot__paths_High);
}
static inline kk_src_hot__paths__complexity kk_src_hot__paths__complexity_dup(kk_src_hot__paths__complexity _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_src_hot__paths__complexity_drop(kk_src_hot__paths__complexity _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_src_hot__paths__complexity_box(kk_src_hot__paths__complexity _x, kk_context_t* _ctx) {
  return kk_enum_box(_x);
}
static inline kk_src_hot__paths__complexity kk_src_hot__paths__complexity_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return (kk_src_hot__paths__complexity)kk_enum_unbox(_x);
}

// value type src/hot_paths/path-category
enum kk_src_hot__paths__path_category_e {
  kk_src_hot__paths_Compute,
  kk_src_hot__paths_Memory,
  kk_src_hot__paths_IO,
  kk_src_hot__paths_Mixed
};
typedef uint8_t kk_src_hot__paths__path_category;

static inline kk_src_hot__paths__path_category kk_src_hot__paths__new_Compute(kk_context_t* _ctx) {
  return kk_src_hot__paths_Compute;
}
static inline kk_src_hot__paths__path_category kk_src_hot__paths__new_Memory(kk_context_t* _ctx) {
  return kk_src_hot__paths_Memory;
}
static inline kk_src_hot__paths__path_category kk_src_hot__paths__new_IO(kk_context_t* _ctx) {
  return kk_src_hot__paths_IO;
}
static inline kk_src_hot__paths__path_category kk_src_hot__paths__new_Mixed(kk_context_t* _ctx) {
  return kk_src_hot__paths_Mixed;
}
static inline bool kk_src_hot__paths__is_Compute(kk_src_hot__paths__path_category x, kk_context_t* _ctx) {
  return (x == kk_src_hot__paths_Compute);
}
static inline bool kk_src_hot__paths__is_Memory(kk_src_hot__paths__path_category x, kk_context_t* _ctx) {
  return (x == kk_src_hot__paths_Memory);
}
static inline bool kk_src_hot__paths__is_IO(kk_src_hot__paths__path_category x, kk_context_t* _ctx) {
  return (x == kk_src_hot__paths_IO);
}
static inline bool kk_src_hot__paths__is_Mixed(kk_src_hot__paths__path_category x, kk_context_t* _ctx) {
  return (x == kk_src_hot__paths_Mixed);
}
static inline kk_src_hot__paths__path_category kk_src_hot__paths__path_category_dup(kk_src_hot__paths__path_category _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_src_hot__paths__path_category_drop(kk_src_hot__paths__path_category _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_src_hot__paths__path_category_box(kk_src_hot__paths__path_category _x, kk_context_t* _ctx) {
  return kk_enum_box(_x);
}
static inline kk_src_hot__paths__path_category kk_src_hot__paths__path_category_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return (kk_src_hot__paths__path_category)kk_enum_unbox(_x);
}

// type src/hot_paths/path-profile
struct kk_src_hot__paths__path_profile_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_hot__paths__path_profile;
struct kk_src_hot__paths_Path_profile {
  struct kk_src_hot__paths__path_profile_s _base;
  kk_string_t name;
  kk_integer_t call_count;
  double total_time_ms;
  double avg_time_ms;
  kk_src_hot__paths__complexity complexity;
  kk_src_hot__paths__path_category category;
};
static inline kk_src_hot__paths__path_profile kk_src_hot__paths__base_Path_profile(struct kk_src_hot__paths_Path_profile* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_hot__paths__path_profile kk_src_hot__paths__new_Path_profile(kk_reuse_t _at, int32_t _cpath, kk_string_t name, kk_integer_t call_count, double total_time_ms, double avg_time_ms, kk_src_hot__paths__complexity complexity, kk_src_hot__paths__path_category category, kk_context_t* _ctx) {
  struct kk_src_hot__paths_Path_profile* _con = kk_block_alloc_at_as(struct kk_src_hot__paths_Path_profile, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->name = name;
  _con->call_count = call_count;
  _con->total_time_ms = total_time_ms;
  _con->avg_time_ms = avg_time_ms;
  _con->complexity = complexity;
  _con->category = category;
  return kk_src_hot__paths__base_Path_profile(_con, _ctx);
}
static inline struct kk_src_hot__paths_Path_profile* kk_src_hot__paths__as_Path_profile(kk_src_hot__paths__path_profile x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_hot__paths_Path_profile*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_hot__paths__is_Path_profile(kk_src_hot__paths__path_profile x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_hot__paths__path_profile kk_src_hot__paths__path_profile_dup(kk_src_hot__paths__path_profile _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_hot__paths__path_profile_drop(kk_src_hot__paths__path_profile _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_hot__paths__path_profile_box(kk_src_hot__paths__path_profile _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_hot__paths__path_profile kk_src_hot__paths__path_profile_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/hot_paths/profiling-session
struct kk_src_hot__paths__profiling_session_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_hot__paths__profiling_session;
struct kk_src_hot__paths_Profiling_session {
  struct kk_src_hot__paths__profiling_session_s _base;
  kk_std_core_types__list paths;
  kk_integer_t total_calls;
  double total_time_ms;
  double hot_threshold_ms;
};
static inline kk_src_hot__paths__profiling_session kk_src_hot__paths__base_Profiling_session(struct kk_src_hot__paths_Profiling_session* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_hot__paths__profiling_session kk_src_hot__paths__new_Profiling_session(kk_reuse_t _at, int32_t _cpath, kk_std_core_types__list paths, kk_integer_t total_calls, double total_time_ms, double hot_threshold_ms, kk_context_t* _ctx) {
  struct kk_src_hot__paths_Profiling_session* _con = kk_block_alloc_at_as(struct kk_src_hot__paths_Profiling_session, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->paths = paths;
  _con->total_calls = total_calls;
  _con->total_time_ms = total_time_ms;
  _con->hot_threshold_ms = hot_threshold_ms;
  return kk_src_hot__paths__base_Profiling_session(_con, _ctx);
}
static inline struct kk_src_hot__paths_Profiling_session* kk_src_hot__paths__as_Profiling_session(kk_src_hot__paths__profiling_session x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_hot__paths_Profiling_session*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_hot__paths__is_Profiling_session(kk_src_hot__paths__profiling_session x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_hot__paths__profiling_session kk_src_hot__paths__profiling_session_dup(kk_src_hot__paths__profiling_session _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_hot__paths__profiling_session_drop(kk_src_hot__paths__profiling_session _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_hot__paths__profiling_session_box(kk_src_hot__paths__profiling_session _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_hot__paths__profiling_session kk_src_hot__paths__profiling_session_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Tests for the `Low` constructor of the `:complexity` type.

static inline bool kk_src_hot__paths_is_low(kk_src_hot__paths__complexity complexity, kk_context_t* _ctx) { /* (complexity : complexity) -> bool */ 
  if (kk_src_hot__paths__is_Low(complexity, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Medium` constructor of the `:complexity` type.

static inline bool kk_src_hot__paths_is_medium(kk_src_hot__paths__complexity complexity, kk_context_t* _ctx) { /* (complexity : complexity) -> bool */ 
  if (kk_src_hot__paths__is_Medium(complexity, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `High` constructor of the `:complexity` type.

static inline bool kk_src_hot__paths_is_high(kk_src_hot__paths__complexity complexity, kk_context_t* _ctx) { /* (complexity : complexity) -> bool */ 
  if (kk_src_hot__paths__is_High(complexity, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Compute` constructor of the `:path-category` type.

static inline bool kk_src_hot__paths_is_compute(kk_src_hot__paths__path_category path_category, kk_context_t* _ctx) { /* (path-category : path-category) -> bool */ 
  if (kk_src_hot__paths__is_Compute(path_category, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Memory` constructor of the `:path-category` type.

static inline bool kk_src_hot__paths_is_memory(kk_src_hot__paths__path_category path_category, kk_context_t* _ctx) { /* (path-category : path-category) -> bool */ 
  if (kk_src_hot__paths__is_Memory(path_category, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `IO` constructor of the `:path-category` type.

static inline bool kk_src_hot__paths_is_io(kk_src_hot__paths__path_category path_category, kk_context_t* _ctx) { /* (path-category : path-category) -> bool */ 
  if (kk_src_hot__paths__is_IO(path_category, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Mixed` constructor of the `:path-category` type.

static inline bool kk_src_hot__paths_is_mixed(kk_src_hot__paths__path_category path_category, kk_context_t* _ctx) { /* (path-category : path-category) -> bool */ 
  if (kk_src_hot__paths__is_Mixed(path_category, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Retrieves the `name` constructor field of the `:path-profile` type.

static inline kk_string_t kk_src_hot__paths_path_profile_fs_name(kk_src_hot__paths__path_profile _this, kk_context_t* _ctx) { /* (path-profile) -> string */ 
  {
    struct kk_src_hot__paths_Path_profile* _con_x106 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
    kk_string_t _x = _con_x106->name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `call-count` constructor field of the `:path-profile` type.

static inline kk_integer_t kk_src_hot__paths_path_profile_fs_call_count(kk_src_hot__paths__path_profile _this, kk_context_t* _ctx) { /* (path-profile) -> int */ 
  {
    struct kk_src_hot__paths_Path_profile* _con_x107 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
    kk_integer_t _x = _con_x107->call_count;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `total-time-ms` constructor field of the `:path-profile` type.

static inline double kk_src_hot__paths_path_profile_fs_total_time_ms(kk_src_hot__paths__path_profile _this, kk_context_t* _ctx) { /* (path-profile) -> float64 */ 
  {
    struct kk_src_hot__paths_Path_profile* _con_x108 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
    double _x = _con_x108->total_time_ms;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `avg-time-ms` constructor field of the `:path-profile` type.

static inline double kk_src_hot__paths_path_profile_fs_avg_time_ms(kk_src_hot__paths__path_profile _this, kk_context_t* _ctx) { /* (path-profile) -> float64 */ 
  {
    struct kk_src_hot__paths_Path_profile* _con_x109 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
    double _x = _con_x109->avg_time_ms;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `complexity` constructor field of the `:path-profile` type.

static inline kk_src_hot__paths__complexity kk_src_hot__paths_path_profile_fs_complexity(kk_src_hot__paths__path_profile _this, kk_context_t* _ctx) { /* (path-profile) -> complexity */ 
  {
    struct kk_src_hot__paths_Path_profile* _con_x110 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
    kk_src_hot__paths__complexity _x = _con_x110->complexity;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `category` constructor field of the `:path-profile` type.

static inline kk_src_hot__paths__path_category kk_src_hot__paths_path_profile_fs_category(kk_src_hot__paths__path_profile _this, kk_context_t* _ctx) { /* (path-profile) -> path-category */ 
  {
    struct kk_src_hot__paths_Path_profile* _con_x111 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
    kk_src_hot__paths__path_category _x = _con_x111->category;
    return _x;
  }
}

kk_src_hot__paths__path_profile kk_src_hot__paths_path_profile_fs__copy(kk_src_hot__paths__path_profile _this, kk_std_core_types__optional name, kk_std_core_types__optional call_count, kk_std_core_types__optional total_time_ms, kk_std_core_types__optional avg_time_ms, kk_std_core_types__optional complexity, kk_std_core_types__optional category, kk_context_t* _ctx); /* (path-profile, name : ? string, call-count : ? int, total-time-ms : ? float64, avg-time-ms : ? float64, complexity : ? complexity, category : ? path-category) -> path-profile */ 
 
// Automatically generated. Retrieves the `paths` constructor field of the `:profiling-session` type.

static inline kk_std_core_types__list kk_src_hot__paths_profiling_session_fs_paths(kk_src_hot__paths__profiling_session _this, kk_context_t* _ctx) { /* (profiling-session) -> list<path-profile> */ 
  {
    struct kk_src_hot__paths_Profiling_session* _con_x124 = kk_src_hot__paths__as_Profiling_session(_this, _ctx);
    kk_std_core_types__list _x = _con_x124->paths;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `total-calls` constructor field of the `:profiling-session` type.

static inline kk_integer_t kk_src_hot__paths_profiling_session_fs_total_calls(kk_src_hot__paths__profiling_session _this, kk_context_t* _ctx) { /* (profiling-session) -> int */ 
  {
    struct kk_src_hot__paths_Profiling_session* _con_x125 = kk_src_hot__paths__as_Profiling_session(_this, _ctx);
    kk_integer_t _x = _con_x125->total_calls;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `total-time-ms` constructor field of the `:profiling-session` type.

static inline double kk_src_hot__paths_profiling_session_fs_total_time_ms(kk_src_hot__paths__profiling_session _this, kk_context_t* _ctx) { /* (profiling-session) -> float64 */ 
  {
    struct kk_src_hot__paths_Profiling_session* _con_x126 = kk_src_hot__paths__as_Profiling_session(_this, _ctx);
    double _x = _con_x126->total_time_ms;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `hot-threshold-ms` constructor field of the `:profiling-session` type.

static inline double kk_src_hot__paths_profiling_session_fs_hot_threshold_ms(kk_src_hot__paths__profiling_session _this, kk_context_t* _ctx) { /* (profiling-session) -> float64 */ 
  {
    struct kk_src_hot__paths_Profiling_session* _con_x127 = kk_src_hot__paths__as_Profiling_session(_this, _ctx);
    double _x = _con_x127->hot_threshold_ms;
    return _x;
  }
}

kk_src_hot__paths__profiling_session kk_src_hot__paths_profiling_session_fs__copy(kk_src_hot__paths__profiling_session _this, kk_std_core_types__optional paths, kk_std_core_types__optional total_calls, kk_std_core_types__optional total_time_ms, kk_std_core_types__optional hot_threshold_ms, kk_context_t* _ctx); /* (profiling-session, paths : ? (list<path-profile>), total-calls : ? int, total-time-ms : ? float64, hot-threshold-ms : ? float64) -> profiling-session */ 

static inline kk_string_t kk_src_hot__paths_complexity_to_string(kk_src_hot__paths__complexity c, kk_context_t* _ctx) { /* (c : complexity) -> string */ 
  if (kk_src_hot__paths__is_Low(c, _ctx)) {
    kk_define_string_literal(, _s_x136, 3, "low", _ctx)
    return kk_string_dup(_s_x136, _ctx);
  }
  if (kk_src_hot__paths__is_Medium(c, _ctx)) {
    kk_define_string_literal(, _s_x137, 6, "medium", _ctx)
    return kk_string_dup(_s_x137, _ctx);
  }
  {
    kk_define_string_literal(, _s_x138, 4, "high", _ctx)
    return kk_string_dup(_s_x138, _ctx);
  }
}

static inline kk_string_t kk_src_hot__paths_category_to_string(kk_src_hot__paths__path_category cat, kk_context_t* _ctx) { /* (cat : path-category) -> string */ 
  if (kk_src_hot__paths__is_Compute(cat, _ctx)) {
    kk_define_string_literal(, _s_x139, 7, "compute", _ctx)
    return kk_string_dup(_s_x139, _ctx);
  }
  if (kk_src_hot__paths__is_Memory(cat, _ctx)) {
    kk_define_string_literal(, _s_x140, 6, "memory", _ctx)
    return kk_string_dup(_s_x140, _ctx);
  }
  if (kk_src_hot__paths__is_IO(cat, _ctx)) {
    kk_define_string_literal(, _s_x141, 2, "io", _ctx)
    return kk_string_dup(_s_x141, _ctx);
  }
  {
    kk_define_string_literal(, _s_x142, 5, "mixed", _ctx)
    return kk_string_dup(_s_x142, _ctx);
  }
}

kk_src_hot__paths__complexity kk_src_hot__paths_estimate_complexity(double avg_time_ms, kk_integer_t call_count, kk_context_t* _ctx); /* (avg-time-ms : float64, call-count : int) -> complexity */ 

kk_src_hot__paths__path_category kk_src_hot__paths_estimate_category(kk_string_t name, kk_context_t* _ctx); /* (name : string) -> path-category */ 

static inline kk_src_hot__paths__path_profile kk_src_hot__paths_create_profile(kk_string_t name, double time_ms, kk_context_t* _ctx) { /* (name : string, time-ms : float64) -> path-profile */ 
  kk_string_t _x_x169 = kk_string_dup(name, _ctx); /*string*/
  kk_src_hot__paths__complexity _x_x170 = kk_src_hot__paths_estimate_complexity(time_ms, kk_integer_from_small(1), _ctx); /*src/hot_paths/complexity*/
  kk_src_hot__paths__path_category _x_x171 = kk_src_hot__paths_estimate_category(name, _ctx); /*src/hot_paths/path-category*/
  return kk_src_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x169, kk_integer_from_small(1), time_ms, time_ms, _x_x170, _x_x171, _ctx);
}

kk_string_t kk_src_hot__paths_json_profile(kk_src_hot__paths__path_profile p, kk_context_t* _ctx); /* (p : path-profile) -> string */ 

kk_string_t kk_src_hot__paths_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_string_t kk_src_hot__paths_extract_name(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_unit_t kk_src_hot__paths__mlift_server_loop_10034(kk_string_t op, kk_std_core_types__list profiles, kk_integer_t total_calls, double total_time, kk_string_t _c_x10018, kk_context_t* _ctx); /* (op : string, profiles : list<path-profile>, total-calls : int, total-time : float64, string) -> () */ 

kk_unit_t kk_src_hot__paths__mlift_server_loop_10035(kk_std_core_types__list profiles_0, kk_integer_t total_calls_0, double total_time_0, kk_string_t line, kk_context_t* _ctx); /* (profiles : list<path-profile>, total-calls : int, total-time : float64, line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_hot__paths_server_loop(kk_integer_t total_calls_1, double total_time_1, kk_std_core_types__list profiles_1, kk_context_t* _ctx); /* (total-calls : int, total-time : float64, profiles : list<path-profile>) -> io () */ 

static inline kk_unit_t kk_src_hot__paths_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_src_hot__paths_server_loop(kk_integer_from_small(0), 0x0p+0, kk_std_core_types__new_Nil(_ctx), _ctx); return kk_Unit;
}

void kk_src_hot__paths__init(kk_context_t* _ctx);


void kk_src_hot__paths__done(kk_context_t* _ctx);

#endif // header
