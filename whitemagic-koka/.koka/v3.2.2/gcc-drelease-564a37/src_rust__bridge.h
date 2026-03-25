#pragma once
#ifndef kk_src_rust__bridge_H
#define kk_src_rust__bridge_H
// Koka generated module: src/rust_bridge, koka version: 3.2.2, platform: 64-bit
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
#include "std_num_int64.h"

// type declarations

// type src/rust_bridge/bridge-stats
struct kk_src_rust__bridge__bridge_stats_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_rust__bridge__bridge_stats;
struct kk_src_rust__bridge_Bridge_stats {
  struct kk_src_rust__bridge__bridge_stats_s _base;
  int64_t calls_made;
  double total_time_ms;
  int64_t cache_hits;
  int64_t cache_misses;
};
static inline kk_src_rust__bridge__bridge_stats kk_src_rust__bridge__base_Bridge_stats(struct kk_src_rust__bridge_Bridge_stats* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_rust__bridge__bridge_stats kk_src_rust__bridge__new_Bridge_stats(kk_reuse_t _at, int32_t _cpath, int64_t calls_made, double total_time_ms, int64_t cache_hits, int64_t cache_misses, kk_context_t* _ctx) {
  struct kk_src_rust__bridge_Bridge_stats* _con = kk_block_alloc_at_as(struct kk_src_rust__bridge_Bridge_stats, _at, 0 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->calls_made = calls_made;
  _con->total_time_ms = total_time_ms;
  _con->cache_hits = cache_hits;
  _con->cache_misses = cache_misses;
  return kk_src_rust__bridge__base_Bridge_stats(_con, _ctx);
}
static inline struct kk_src_rust__bridge_Bridge_stats* kk_src_rust__bridge__as_Bridge_stats(kk_src_rust__bridge__bridge_stats x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_rust__bridge_Bridge_stats*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_rust__bridge__is_Bridge_stats(kk_src_rust__bridge__bridge_stats x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_rust__bridge__bridge_stats kk_src_rust__bridge__bridge_stats_dup(kk_src_rust__bridge__bridge_stats _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_rust__bridge__bridge_stats_drop(kk_src_rust__bridge__bridge_stats _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_rust__bridge__bridge_stats_box(kk_src_rust__bridge__bridge_stats _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_rust__bridge__bridge_stats kk_src_rust__bridge__bridge_stats_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/rust_bridge/rust-call
struct kk_src_rust__bridge__rust_call_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_rust__bridge__rust_call;
struct kk_src_rust__bridge_Rust_call {
  struct kk_src_rust__bridge__rust_call_s _base;
  kk_string_t func_name;
  kk_std_core_types__list args;
  kk_string_t result;
  double elapsed_ms;
};
static inline kk_src_rust__bridge__rust_call kk_src_rust__bridge__base_Rust_call(struct kk_src_rust__bridge_Rust_call* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_rust__bridge__rust_call kk_src_rust__bridge__new_Rust_call(kk_reuse_t _at, int32_t _cpath, kk_string_t func_name, kk_std_core_types__list args, kk_string_t result, double elapsed_ms, kk_context_t* _ctx) {
  struct kk_src_rust__bridge_Rust_call* _con = kk_block_alloc_at_as(struct kk_src_rust__bridge_Rust_call, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->func_name = func_name;
  _con->args = args;
  _con->result = result;
  _con->elapsed_ms = elapsed_ms;
  return kk_src_rust__bridge__base_Rust_call(_con, _ctx);
}
static inline struct kk_src_rust__bridge_Rust_call* kk_src_rust__bridge__as_Rust_call(kk_src_rust__bridge__rust_call x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_rust__bridge_Rust_call*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_rust__bridge__is_Rust_call(kk_src_rust__bridge__rust_call x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_rust__bridge__rust_call kk_src_rust__bridge__rust_call_dup(kk_src_rust__bridge__rust_call _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_rust__bridge__rust_call_drop(kk_src_rust__bridge__rust_call _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_rust__bridge__rust_call_box(kk_src_rust__bridge__rust_call _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_rust__bridge__rust_call kk_src_rust__bridge__rust_call_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/rust_bridge/rust-function
struct kk_src_rust__bridge__rust_function_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_rust__bridge__rust_function;
struct kk_src_rust__bridge_Rust_function {
  struct kk_src_rust__bridge__rust_function_s _base;
  kk_string_t name;
  kk_std_core_types__list arg_types;
  kk_string_t return_type;
  bool hot_path;
};
static inline kk_src_rust__bridge__rust_function kk_src_rust__bridge__base_Rust_function(struct kk_src_rust__bridge_Rust_function* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_rust__bridge__rust_function kk_src_rust__bridge__new_Rust_function(kk_reuse_t _at, int32_t _cpath, kk_string_t name, kk_std_core_types__list arg_types, kk_string_t return_type, bool hot_path, kk_context_t* _ctx) {
  struct kk_src_rust__bridge_Rust_function* _con = kk_block_alloc_at_as(struct kk_src_rust__bridge_Rust_function, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->name = name;
  _con->arg_types = arg_types;
  _con->return_type = return_type;
  _con->hot_path = hot_path;
  return kk_src_rust__bridge__base_Rust_function(_con, _ctx);
}
static inline struct kk_src_rust__bridge_Rust_function* kk_src_rust__bridge__as_Rust_function(kk_src_rust__bridge__rust_function x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_rust__bridge_Rust_function*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_rust__bridge__is_Rust_function(kk_src_rust__bridge__rust_function x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_rust__bridge__rust_function kk_src_rust__bridge__rust_function_dup(kk_src_rust__bridge__rust_function _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_rust__bridge__rust_function_drop(kk_src_rust__bridge__rust_function _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_rust__bridge__rust_function_box(kk_src_rust__bridge__rust_function _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_rust__bridge__rust_function kk_src_rust__bridge__rust_function_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `func-name` constructor field of the `:rust-call` type.

static inline kk_string_t kk_src_rust__bridge_rust_call_fs_func_name(kk_src_rust__bridge__rust_call _this, kk_context_t* _ctx) { /* (rust-call) -> string */ 
  {
    struct kk_src_rust__bridge_Rust_call* _con_x174 = kk_src_rust__bridge__as_Rust_call(_this, _ctx);
    kk_string_t _x = _con_x174->func_name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `args` constructor field of the `:rust-call` type.

static inline kk_std_core_types__list kk_src_rust__bridge_rust_call_fs_args(kk_src_rust__bridge__rust_call _this, kk_context_t* _ctx) { /* (rust-call) -> list<string> */ 
  {
    struct kk_src_rust__bridge_Rust_call* _con_x175 = kk_src_rust__bridge__as_Rust_call(_this, _ctx);
    kk_std_core_types__list _x = _con_x175->args;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `result` constructor field of the `:rust-call` type.

static inline kk_string_t kk_src_rust__bridge_rust_call_fs_result(kk_src_rust__bridge__rust_call _this, kk_context_t* _ctx) { /* (rust-call) -> string */ 
  {
    struct kk_src_rust__bridge_Rust_call* _con_x176 = kk_src_rust__bridge__as_Rust_call(_this, _ctx);
    kk_string_t _x = _con_x176->result;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `elapsed-ms` constructor field of the `:rust-call` type.

static inline double kk_src_rust__bridge_rust_call_fs_elapsed_ms(kk_src_rust__bridge__rust_call _this, kk_context_t* _ctx) { /* (rust-call) -> float64 */ 
  {
    struct kk_src_rust__bridge_Rust_call* _con_x177 = kk_src_rust__bridge__as_Rust_call(_this, _ctx);
    double _x = _con_x177->elapsed_ms;
    return _x;
  }
}

kk_src_rust__bridge__rust_call kk_src_rust__bridge_rust_call_fs__copy(kk_src_rust__bridge__rust_call _this, kk_std_core_types__optional func_name, kk_std_core_types__optional args, kk_std_core_types__optional result, kk_std_core_types__optional elapsed_ms, kk_context_t* _ctx); /* (rust-call, func-name : ? string, args : ? (list<string>), result : ? string, elapsed-ms : ? float64) -> rust-call */ 
 
// Automatically generated. Retrieves the `calls-made` constructor field of the `:bridge-stats` type.

static inline int64_t kk_src_rust__bridge_bridge_stats_fs_calls_made(kk_src_rust__bridge__bridge_stats _this, kk_context_t* _ctx) { /* (bridge-stats) -> int64 */ 
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x186 = kk_src_rust__bridge__as_Bridge_stats(_this, _ctx);
    int64_t _x = _con_x186->calls_made;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `total-time-ms` constructor field of the `:bridge-stats` type.

static inline double kk_src_rust__bridge_bridge_stats_fs_total_time_ms(kk_src_rust__bridge__bridge_stats _this, kk_context_t* _ctx) { /* (bridge-stats) -> float64 */ 
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x187 = kk_src_rust__bridge__as_Bridge_stats(_this, _ctx);
    double _x = _con_x187->total_time_ms;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `cache-hits` constructor field of the `:bridge-stats` type.

static inline int64_t kk_src_rust__bridge_bridge_stats_fs_cache_hits(kk_src_rust__bridge__bridge_stats _this, kk_context_t* _ctx) { /* (bridge-stats) -> int64 */ 
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x188 = kk_src_rust__bridge__as_Bridge_stats(_this, _ctx);
    int64_t _x = _con_x188->cache_hits;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `cache-misses` constructor field of the `:bridge-stats` type.

static inline int64_t kk_src_rust__bridge_bridge_stats_fs_cache_misses(kk_src_rust__bridge__bridge_stats _this, kk_context_t* _ctx) { /* (bridge-stats) -> int64 */ 
  {
    struct kk_src_rust__bridge_Bridge_stats* _con_x189 = kk_src_rust__bridge__as_Bridge_stats(_this, _ctx);
    int64_t _x = _con_x189->cache_misses;
    return _x;
  }
}

kk_src_rust__bridge__bridge_stats kk_src_rust__bridge_bridge_stats_fs__copy(kk_src_rust__bridge__bridge_stats _this, kk_std_core_types__optional calls_made, kk_std_core_types__optional total_time_ms, kk_std_core_types__optional cache_hits, kk_std_core_types__optional cache_misses, kk_context_t* _ctx); /* (bridge-stats, calls-made : ? int64, total-time-ms : ? float64, cache-hits : ? int64, cache-misses : ? int64) -> bridge-stats */ 
 
// Simulate cosine similarity (hot path in Python, accelerated in Rust)

static inline double kk_src_rust__bridge_rust_cosine_sim(kk_std_core_types__list a, kk_std_core_types__list b, kk_context_t* _ctx) { /* (a : list<float64>, b : list<float64>) -> float64 */ 
  kk_std_core_types__list_drop(a, _ctx);
  kk_std_core_types__list_drop(b, _ctx);
  return 0x1.b333333333333p-1;
}
 
// Simulate JSON serialization (hot path, accelerated in Rust via orjson)

static inline kk_string_t kk_src_rust__bridge_rust_json_serialize(kk_string_t obj, kk_context_t* _ctx) { /* (obj : string) -> string */ 
  kk_string_t _x_x198;
  kk_define_string_literal(, _s_x199, 27, "{\"serialized\":true,\"data\":\"", _ctx)
  _x_x198 = kk_string_dup(_s_x199, _ctx); /*string*/
  kk_string_t _x_x200;
  kk_string_t _x_x201;
  kk_define_string_literal(, _s_x202, 2, "\"}", _ctx)
  _x_x201 = kk_string_dup(_s_x202, _ctx); /*string*/
  _x_x200 = kk_std_core_types__lp__plus__plus__rp_(obj, _x_x201, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x198, _x_x200, _ctx);
}
 
// Simulate batch embedding lookup

static inline kk_integer_t kk_src_rust__bridge_rust_batch_embed(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> int */ 
  return n;
}

kk_src_rust__bridge__bridge_stats kk_src_rust__bridge_update_stats(kk_src_rust__bridge__bridge_stats stats, double elapsed, bool cache_hit, kk_context_t* _ctx); /* (stats : bridge-stats, elapsed : float64, cache-hit : bool) -> bridge-stats */ 

kk_string_t kk_src_rust__bridge_json_stats(kk_src_rust__bridge__bridge_stats s, kk_context_t* _ctx); /* (s : bridge-stats) -> string */ 

kk_string_t kk_src_rust__bridge_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_std_core_types__tuple2 kk_src_rust__bridge_extract_vectors(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> (list<float64>, list<float64>) */ 

kk_unit_t kk_src_rust__bridge__mlift_server_loop_10171(kk_string_t op, kk_src_rust__bridge__bridge_stats stats, kk_string_t _c_x10142, kk_context_t* _ctx); /* (op : string, stats : bridge-stats, string) -> () */ 

kk_unit_t kk_src_rust__bridge__mlift_server_loop_10172(kk_src_rust__bridge__bridge_stats stats_1, kk_string_t line, kk_context_t* _ctx); /* (stats : bridge-stats, line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_rust__bridge_server_loop(kk_src_rust__bridge__bridge_stats stats_2, kk_context_t* _ctx); /* (stats : bridge-stats) -> io () */ 
 
// Automatically generated. Retrieves the `name` constructor field of the `:rust-function` type.

static inline kk_string_t kk_src_rust__bridge_rust_function_fs_name(kk_src_rust__bridge__rust_function _this, kk_context_t* _ctx) { /* (rust-function) -> string */ 
  {
    struct kk_src_rust__bridge_Rust_function* _con_x421 = kk_src_rust__bridge__as_Rust_function(_this, _ctx);
    kk_string_t _x = _con_x421->name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `arg-types` constructor field of the `:rust-function` type.

static inline kk_std_core_types__list kk_src_rust__bridge_rust_function_fs_arg_types(kk_src_rust__bridge__rust_function _this, kk_context_t* _ctx) { /* (rust-function) -> list<string> */ 
  {
    struct kk_src_rust__bridge_Rust_function* _con_x422 = kk_src_rust__bridge__as_Rust_function(_this, _ctx);
    kk_std_core_types__list _x = _con_x422->arg_types;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `return-type` constructor field of the `:rust-function` type.

static inline kk_string_t kk_src_rust__bridge_rust_function_fs_return_type(kk_src_rust__bridge__rust_function _this, kk_context_t* _ctx) { /* (rust-function) -> string */ 
  {
    struct kk_src_rust__bridge_Rust_function* _con_x423 = kk_src_rust__bridge__as_Rust_function(_this, _ctx);
    kk_string_t _x = _con_x423->return_type;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `hot-path` constructor field of the `:rust-function` type.

static inline bool kk_src_rust__bridge_rust_function_fs_hot_path(kk_src_rust__bridge__rust_function _this, kk_context_t* _ctx) { /* (rust-function) -> bool */ 
  {
    struct kk_src_rust__bridge_Rust_function* _con_x424 = kk_src_rust__bridge__as_Rust_function(_this, _ctx);
    bool _x = _con_x424->hot_path;
    return _x;
  }
}

kk_src_rust__bridge__rust_function kk_src_rust__bridge_rust_function_fs__copy(kk_src_rust__bridge__rust_function _this, kk_std_core_types__optional name, kk_std_core_types__optional arg_types, kk_std_core_types__optional return_type, kk_std_core_types__optional hot_path, kk_context_t* _ctx); /* (rust-function, name : ? string, arg-types : ? (list<string>), return-type : ? string, hot-path : ? bool) -> rust-function */ 

extern kk_std_core_types__list kk_src_rust__bridge_rust_registry;

kk_string_t kk_src_rust__bridge__unroll_lift_json_registry_1913_10000(kk_std_core_types__list fns, kk_string_t acc, kk_context_t* _ctx); /* (fns : list<rust-function>, acc : string) -> string */ 
 
// unrolling of singleton matches of src/rust_bridge/@unroll-lift-json-registry@1913@10000

static inline kk_string_t kk_src_rust__bridge__lift_json_registry_1913(kk_std_core_types__list fns, kk_string_t acc, kk_context_t* _ctx) { /* (fns : list<rust-function>, acc : string) -> string */ 
  if (kk_std_core_types__is_Nil(fns, _ctx)) {
    return acc;
  }
  {
    return kk_src_rust__bridge__unroll_lift_json_registry_1913_10000(fns, acc, _ctx);
  }
}

kk_string_t kk_src_rust__bridge_json_registry(kk_context_t* _ctx); /* () -> string */ 

kk_unit_t kk_src_rust__bridge_main(kk_context_t* _ctx); /* () -> io () */ 

void kk_src_rust__bridge__init(kk_context_t* _ctx);


void kk_src_rust__bridge__done(kk_context_t* _ctx);

#endif // header
