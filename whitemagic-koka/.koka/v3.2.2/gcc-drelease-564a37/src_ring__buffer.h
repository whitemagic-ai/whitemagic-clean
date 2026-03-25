#pragma once
#ifndef kk_src_ring__buffer_H
#define kk_src_ring__buffer_H
// Koka generated module: src/ring_buffer, koka version: 3.2.2, platform: 64-bit
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

// type src/ring_buffer/buffer-config
struct kk_src_ring__buffer__buffer_config_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_ring__buffer__buffer_config;
struct kk_src_ring__buffer_Buffer_config {
  struct kk_src_ring__buffer__buffer_config_s _base;
  kk_integer_t capacity;
  kk_integer_t slot_size;
  kk_integer_t header_size;
};
static inline kk_src_ring__buffer__buffer_config kk_src_ring__buffer__base_Buffer_config(struct kk_src_ring__buffer_Buffer_config* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_ring__buffer__buffer_config kk_src_ring__buffer__new_Buffer_config(kk_reuse_t _at, int32_t _cpath, kk_integer_t capacity, kk_integer_t slot_size, kk_integer_t header_size, kk_context_t* _ctx) {
  struct kk_src_ring__buffer_Buffer_config* _con = kk_block_alloc_at_as(struct kk_src_ring__buffer_Buffer_config, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->capacity = capacity;
  _con->slot_size = slot_size;
  _con->header_size = header_size;
  return kk_src_ring__buffer__base_Buffer_config(_con, _ctx);
}
static inline struct kk_src_ring__buffer_Buffer_config* kk_src_ring__buffer__as_Buffer_config(kk_src_ring__buffer__buffer_config x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_ring__buffer_Buffer_config*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_ring__buffer__is_Buffer_config(kk_src_ring__buffer__buffer_config x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_ring__buffer__buffer_config kk_src_ring__buffer__buffer_config_dup(kk_src_ring__buffer__buffer_config _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_ring__buffer__buffer_config_drop(kk_src_ring__buffer__buffer_config _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_ring__buffer__buffer_config_box(kk_src_ring__buffer__buffer_config _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_ring__buffer__buffer_config kk_src_ring__buffer__buffer_config_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/ring_buffer/buffer-state
struct kk_src_ring__buffer__buffer_state_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_ring__buffer__buffer_state;
struct kk_src_ring__buffer_Buffer_state {
  struct kk_src_ring__buffer__buffer_state_s _base;
  kk_integer_t write_pos;
  kk_integer_t read_pos;
  kk_integer_t count;
  int64_t total_written;
  int64_t total_read;
};
static inline kk_src_ring__buffer__buffer_state kk_src_ring__buffer__base_Buffer_state(struct kk_src_ring__buffer_Buffer_state* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_ring__buffer__buffer_state kk_src_ring__buffer__new_Buffer_state(kk_reuse_t _at, int32_t _cpath, kk_integer_t write_pos, kk_integer_t read_pos, kk_integer_t count, int64_t total_written, int64_t total_read, kk_context_t* _ctx) {
  struct kk_src_ring__buffer_Buffer_state* _con = kk_block_alloc_at_as(struct kk_src_ring__buffer_Buffer_state, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->write_pos = write_pos;
  _con->read_pos = read_pos;
  _con->count = count;
  _con->total_written = total_written;
  _con->total_read = total_read;
  return kk_src_ring__buffer__base_Buffer_state(_con, _ctx);
}
static inline struct kk_src_ring__buffer_Buffer_state* kk_src_ring__buffer__as_Buffer_state(kk_src_ring__buffer__buffer_state x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_ring__buffer_Buffer_state*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_ring__buffer__is_Buffer_state(kk_src_ring__buffer__buffer_state x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_ring__buffer__buffer_state kk_src_ring__buffer__buffer_state_dup(kk_src_ring__buffer__buffer_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_ring__buffer__buffer_state_drop(kk_src_ring__buffer__buffer_state _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_ring__buffer__buffer_state_box(kk_src_ring__buffer__buffer_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_ring__buffer__buffer_state kk_src_ring__buffer__buffer_state_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `capacity` constructor field of the `:buffer-config` type.

static inline kk_integer_t kk_src_ring__buffer_buffer_config_fs_capacity(kk_src_ring__buffer__buffer_config _this, kk_context_t* _ctx) { /* (buffer-config) -> int */ 
  {
    struct kk_src_ring__buffer_Buffer_config* _con_x380 = kk_src_ring__buffer__as_Buffer_config(_this, _ctx);
    kk_integer_t _x = _con_x380->capacity;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `slot-size` constructor field of the `:buffer-config` type.

static inline kk_integer_t kk_src_ring__buffer_buffer_config_fs_slot_size(kk_src_ring__buffer__buffer_config _this, kk_context_t* _ctx) { /* (buffer-config) -> int */ 
  {
    struct kk_src_ring__buffer_Buffer_config* _con_x381 = kk_src_ring__buffer__as_Buffer_config(_this, _ctx);
    kk_integer_t _x = _con_x381->slot_size;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `header-size` constructor field of the `:buffer-config` type.

static inline kk_integer_t kk_src_ring__buffer_buffer_config_fs_header_size(kk_src_ring__buffer__buffer_config _this, kk_context_t* _ctx) { /* (buffer-config) -> int */ 
  {
    struct kk_src_ring__buffer_Buffer_config* _con_x382 = kk_src_ring__buffer__as_Buffer_config(_this, _ctx);
    kk_integer_t _x = _con_x382->header_size;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_ring__buffer__buffer_config kk_src_ring__buffer_buffer_config_fs__copy(kk_src_ring__buffer__buffer_config _this, kk_std_core_types__optional capacity, kk_std_core_types__optional slot_size, kk_std_core_types__optional header_size, kk_context_t* _ctx); /* (buffer-config, capacity : ? int, slot-size : ? int, header-size : ? int) -> buffer-config */ 
 
// Automatically generated. Retrieves the `write-pos` constructor field of the `:buffer-state` type.

static inline kk_integer_t kk_src_ring__buffer_buffer_state_fs_write_pos(kk_src_ring__buffer__buffer_state _this, kk_context_t* _ctx) { /* (buffer-state) -> int */ 
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x389 = kk_src_ring__buffer__as_Buffer_state(_this, _ctx);
    kk_integer_t _x = _con_x389->write_pos;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `read-pos` constructor field of the `:buffer-state` type.

static inline kk_integer_t kk_src_ring__buffer_buffer_state_fs_read_pos(kk_src_ring__buffer__buffer_state _this, kk_context_t* _ctx) { /* (buffer-state) -> int */ 
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x390 = kk_src_ring__buffer__as_Buffer_state(_this, _ctx);
    kk_integer_t _x = _con_x390->read_pos;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `count` constructor field of the `:buffer-state` type.

static inline kk_integer_t kk_src_ring__buffer_buffer_state_fs_count(kk_src_ring__buffer__buffer_state _this, kk_context_t* _ctx) { /* (buffer-state) -> int */ 
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x391 = kk_src_ring__buffer__as_Buffer_state(_this, _ctx);
    kk_integer_t _x = _con_x391->count;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `total-written` constructor field of the `:buffer-state` type.

static inline int64_t kk_src_ring__buffer_buffer_state_fs_total_written(kk_src_ring__buffer__buffer_state _this, kk_context_t* _ctx) { /* (buffer-state) -> int64 */ 
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x392 = kk_src_ring__buffer__as_Buffer_state(_this, _ctx);
    int64_t _x = _con_x392->total_written;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `total-read` constructor field of the `:buffer-state` type.

static inline int64_t kk_src_ring__buffer_buffer_state_fs_total_read(kk_src_ring__buffer__buffer_state _this, kk_context_t* _ctx) { /* (buffer-state) -> int64 */ 
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x393 = kk_src_ring__buffer__as_Buffer_state(_this, _ctx);
    int64_t _x = _con_x393->total_read;
    return _x;
  }
}

kk_src_ring__buffer__buffer_state kk_src_ring__buffer_buffer_state_fs__copy(kk_src_ring__buffer__buffer_state _this, kk_std_core_types__optional write_pos, kk_std_core_types__optional read_pos, kk_std_core_types__optional count, kk_std_core_types__optional total_written, kk_std_core_types__optional total_read, kk_context_t* _ctx); /* (buffer-state, write-pos : ? int, read-pos : ? int, count : ? int, total-written : ? int64, total-read : ? int64) -> buffer-state */ 
 
// Calculate next position in ring

static inline kk_integer_t kk_src_ring__buffer_next_pos(kk_integer_t pos, kk_integer_t capacity, kk_context_t* _ctx) { /* (pos : int, capacity : int) -> int */ 
  kk_integer_t _x_x404 = kk_integer_add_small_const(pos, 1, _ctx); /*int*/
  return kk_integer_mod(_x_x404,capacity,kk_context());
}

bool kk_src_ring__buffer_is_full(kk_src_ring__buffer__buffer_state state, kk_integer_t capacity, kk_context_t* _ctx); /* (state : buffer-state, capacity : int) -> bool */ 

bool kk_src_ring__buffer_is_empty(kk_src_ring__buffer__buffer_state state, kk_context_t* _ctx); /* (state : buffer-state) -> bool */ 

kk_std_core_types__maybe kk_src_ring__buffer_try_write(kk_src_ring__buffer__buffer_state state, kk_src_ring__buffer__buffer_config config, kk_context_t* _ctx); /* (state : buffer-state, config : buffer-config) -> maybe<buffer-state> */ 

kk_std_core_types__maybe kk_src_ring__buffer_try_read(kk_src_ring__buffer__buffer_state state, kk_src_ring__buffer__buffer_config config, kk_context_t* _ctx); /* (state : buffer-state, config : buffer-config) -> maybe<buffer-state> */ 

kk_integer_t kk_src_ring__buffer_write_available(kk_src_ring__buffer__buffer_state state, kk_integer_t capacity, kk_context_t* _ctx); /* (state : buffer-state, capacity : int) -> int */ 

kk_integer_t kk_src_ring__buffer_read_available(kk_src_ring__buffer__buffer_state state, kk_context_t* _ctx); /* (state : buffer-state) -> int */ 

kk_std_core_types__tuple2 kk_src_ring__buffer_write_batch(kk_src_ring__buffer__buffer_state state, kk_src_ring__buffer__buffer_config config, kk_integer_t n, kk_context_t* _ctx); /* (state : buffer-state, config : buffer-config, n : int) -> (int, buffer-state) */ 

kk_std_core_types__tuple2 kk_src_ring__buffer_read_batch(kk_src_ring__buffer__buffer_state state, kk_src_ring__buffer__buffer_config config, kk_integer_t n, kk_context_t* _ctx); /* (state : buffer-state, config : buffer-config, n : int) -> (int, buffer-state) */ 

kk_string_t kk_src_ring__buffer_buffer_stats(kk_src_ring__buffer__buffer_state state, kk_src_ring__buffer__buffer_config config, kk_context_t* _ctx); /* (state : buffer-state, config : buffer-config) -> string */ 

kk_string_t kk_src_ring__buffer_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_integer_t kk_src_ring__buffer_extract_count(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> int */ 

kk_unit_t kk_src_ring__buffer__mlift_server_loop_10264(kk_src_ring__buffer__buffer_config config, kk_src_ring__buffer__buffer_state _c_x10204, kk_context_t* _ctx); /* (config : buffer-config, buffer-state) -> () */ 

kk_unit_t kk_src_ring__buffer__mlift_server_loop_10265(kk_src_ring__buffer__buffer_config config_0, kk_string_t line, kk_string_t op, kk_src_ring__buffer__buffer_state state, kk_string_t _c_x10203, kk_context_t* _ctx); /* (config : buffer-config, line : string, op : string, state : buffer-state, string) -> () */ 

kk_unit_t kk_src_ring__buffer__mlift_server_loop_10266(kk_src_ring__buffer__buffer_config config_1, kk_src_ring__buffer__buffer_state state_0, kk_string_t line_0, kk_context_t* _ctx); /* (config : buffer-config, state : buffer-state, line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_ring__buffer_server_loop(kk_src_ring__buffer__buffer_state state_1, kk_src_ring__buffer__buffer_config config_2, kk_context_t* _ctx); /* (state : buffer-state, config : buffer-config) -> io () */ 

kk_unit_t kk_src_ring__buffer_main(kk_context_t* _ctx); /* () -> io () */ 

void kk_src_ring__buffer__init(kk_context_t* _ctx);


void kk_src_ring__buffer__done(kk_context_t* _ctx);

#endif // header
