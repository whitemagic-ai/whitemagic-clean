#pragma once
#ifndef kk_whitemagic_dash_koka_src_shm__search_H
#define kk_whitemagic_dash_koka_src_shm__search_H
// Koka generated module: whitemagic-koka/src/shm_search, koka version: 3.2.2, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"
#include "std_core_bool.h"
#include "std_core_order.h"
#include "std_core_char.h"
#include "std_core_vector.h"
#include "std_core_sslice.h"
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
#include "std_core_list.h"
#include "std_core_string.h"
#include "std_core_int.h"

// type declarations

// type whitemagic-koka/src/shm_search/shm-header
struct kk_whitemagic_dash_koka_src_shm__search__shm_header_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_whitemagic_dash_koka_src_shm__search__shm_header;
struct kk_whitemagic_dash_koka_src_shm__search_Shm_header {
  struct kk_whitemagic_dash_koka_src_shm__search__shm_header_s _base;
  kk_integer_t magic;
  kk_integer_t version;
  kk_integer_t capacity;
  kk_integer_t count;
  kk_integer_t write_pos;
  kk_integer_t read_pos;
};
static inline kk_whitemagic_dash_koka_src_shm__search__shm_header kk_whitemagic_dash_koka_src_shm__search__base_Shm_header(struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_whitemagic_dash_koka_src_shm__search__shm_header kk_whitemagic_dash_koka_src_shm__search__new_Shm_header(kk_reuse_t _at, int32_t _cpath, kk_integer_t magic, kk_integer_t version, kk_integer_t capacity, kk_integer_t count, kk_integer_t write_pos, kk_integer_t read_pos, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con = kk_block_alloc_at_as(struct kk_whitemagic_dash_koka_src_shm__search_Shm_header, _at, 6 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->magic = magic;
  _con->version = version;
  _con->capacity = capacity;
  _con->count = count;
  _con->write_pos = write_pos;
  _con->read_pos = read_pos;
  return kk_whitemagic_dash_koka_src_shm__search__base_Shm_header(_con, _ctx);
}
static inline struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(kk_whitemagic_dash_koka_src_shm__search__shm_header x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_whitemagic_dash_koka_src_shm__search_Shm_header*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_whitemagic_dash_koka_src_shm__search__is_Shm_header(kk_whitemagic_dash_koka_src_shm__search__shm_header x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_whitemagic_dash_koka_src_shm__search__shm_header kk_whitemagic_dash_koka_src_shm__search__shm_header_dup(kk_whitemagic_dash_koka_src_shm__search__shm_header _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_whitemagic_dash_koka_src_shm__search__shm_header_drop(kk_whitemagic_dash_koka_src_shm__search__shm_header _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_whitemagic_dash_koka_src_shm__search__shm_header_box(kk_whitemagic_dash_koka_src_shm__search__shm_header _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_whitemagic_dash_koka_src_shm__search__shm_header kk_whitemagic_dash_koka_src_shm__search__shm_header_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations

int64_t kk_whitemagic_dash_koka_src_shm__search_shm_open_map(kk_string_t name, kk_integer_t size, kk_context_t* _ctx); /* (name : string, size : int) -> int64 */ 

kk_integer_t kk_whitemagic_dash_koka_src_shm__search_shm_unmap(int64_t addr, kk_integer_t size, kk_context_t* _ctx); /* (addr : int64, size : int) -> int */ 

kk_integer_t kk_whitemagic_dash_koka_src_shm__search_shm_read_int(int64_t addr, kk_integer_t offset, kk_context_t* _ctx); /* (addr : int64, offset : int) -> int */ 

kk_string_t kk_whitemagic_dash_koka_src_shm__search_shm_search_top5(int64_t addr, kk_integer_t count, kk_integer_t query_item_id, kk_context_t* _ctx); /* (addr : int64, count : int, query-item-id : int) -> string */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__search_flush_stdout(kk_context_t* _ctx); /* () -> console/console () */ 

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__search_segment_size;

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__search_header_size;

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__search_slot_size;
 
// id (4 bytes) + 384 float32 (1536 bytes)

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__search_embedding_dim;

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__search_magic_number;
 
// Automatically generated. Retrieves the `magic` constructor field of the `:shm-header` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_shm__search_shm_header_fs_magic(kk_whitemagic_dash_koka_src_shm__search__shm_header _this, kk_context_t* _ctx) { /* (shm-header) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x206 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
    kk_integer_t _x = _con_x206->magic;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `version` constructor field of the `:shm-header` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_shm__search_shm_header_fs_version(kk_whitemagic_dash_koka_src_shm__search__shm_header _this, kk_context_t* _ctx) { /* (shm-header) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x207 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
    kk_integer_t _x = _con_x207->version;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `capacity` constructor field of the `:shm-header` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_shm__search_shm_header_fs_capacity(kk_whitemagic_dash_koka_src_shm__search__shm_header _this, kk_context_t* _ctx) { /* (shm-header) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x208 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
    kk_integer_t _x = _con_x208->capacity;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `count` constructor field of the `:shm-header` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_shm__search_shm_header_fs_count(kk_whitemagic_dash_koka_src_shm__search__shm_header _this, kk_context_t* _ctx) { /* (shm-header) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x209 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
    kk_integer_t _x = _con_x209->count;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `write-pos` constructor field of the `:shm-header` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_shm__search_shm_header_fs_write_pos(kk_whitemagic_dash_koka_src_shm__search__shm_header _this, kk_context_t* _ctx) { /* (shm-header) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x210 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
    kk_integer_t _x = _con_x210->write_pos;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `read-pos` constructor field of the `:shm-header` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_shm__search_shm_header_fs_read_pos(kk_whitemagic_dash_koka_src_shm__search__shm_header _this, kk_context_t* _ctx) { /* (shm-header) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x211 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
    kk_integer_t _x = _con_x211->read_pos;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_whitemagic_dash_koka_src_shm__search__shm_header kk_whitemagic_dash_koka_src_shm__search_shm_header_fs__copy(kk_whitemagic_dash_koka_src_shm__search__shm_header _this, kk_std_core_types__optional magic, kk_std_core_types__optional version, kk_std_core_types__optional capacity, kk_std_core_types__optional count, kk_std_core_types__optional write_pos, kk_std_core_types__optional read_pos, kk_context_t* _ctx); /* (shm-header, magic : ? int, version : ? int, capacity : ? int, count : ? int, write-pos : ? int, read-pos : ? int) -> shm-header */ 

kk_whitemagic_dash_koka_src_shm__search__shm_header kk_whitemagic_dash_koka_src_shm__search_read_header(int64_t addr, kk_context_t* _ctx); /* (addr : int64) -> shm-header */ 

kk_string_t kk_whitemagic_dash_koka_src_shm__search_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_integer_t kk_whitemagic_dash_koka_src_shm__search_extract_query_id(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> int */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067(int64_t addr, kk_string_t op, kk_string_t _c_x10015, kk_context_t* _ctx); /* (addr : int64, op : string, string) -> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068(int64_t addr_0, kk_string_t line, kk_context_t* _ctx); /* (addr : int64, line : string) -> <console/console,exn,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>,exn> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__search_server_loop(int64_t addr_1, kk_context_t* _ctx); /* (addr : int64) -> io () */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__search_main(kk_context_t* _ctx); /* () -> io () */ 

void kk_whitemagic_dash_koka_src_shm__search__init(kk_context_t* _ctx);


void kk_whitemagic_dash_koka_src_shm__search__done(kk_context_t* _ctx);

#endif // header
