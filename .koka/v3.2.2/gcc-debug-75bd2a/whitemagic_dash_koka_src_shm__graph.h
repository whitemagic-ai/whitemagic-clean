#pragma once
#ifndef kk_whitemagic_dash_koka_src_shm__graph_H
#define kk_whitemagic_dash_koka_src_shm__graph_H
// Koka generated module: whitemagic-koka/src/shm_graph, koka version: 3.2.2, platform: 64-bit
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
#include "std_num_int64.h"
#include "std_core_int.h"
#include "std_core_string.h"
#include "std_core_list.h"
#include "std_text_parse.h"

// type declarations

// type whitemagic-koka/src/shm_graph/header
struct kk_whitemagic_dash_koka_src_shm__graph__header_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_whitemagic_dash_koka_src_shm__graph__header;
struct kk_whitemagic_dash_koka_src_shm__graph_Header {
  struct kk_whitemagic_dash_koka_src_shm__graph__header_s _base;
  kk_integer_t magic;
  kk_integer_t version;
  kk_integer_t capacity;
  kk_integer_t count;
};
static inline kk_whitemagic_dash_koka_src_shm__graph__header kk_whitemagic_dash_koka_src_shm__graph__base_Header(struct kk_whitemagic_dash_koka_src_shm__graph_Header* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_whitemagic_dash_koka_src_shm__graph__header kk_whitemagic_dash_koka_src_shm__graph__new_Header(kk_reuse_t _at, int32_t _cpath, kk_integer_t magic, kk_integer_t version, kk_integer_t capacity, kk_integer_t count, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con = kk_block_alloc_at_as(struct kk_whitemagic_dash_koka_src_shm__graph_Header, _at, 4 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->magic = magic;
  _con->version = version;
  _con->capacity = capacity;
  _con->count = count;
  return kk_whitemagic_dash_koka_src_shm__graph__base_Header(_con, _ctx);
}
static inline struct kk_whitemagic_dash_koka_src_shm__graph_Header* kk_whitemagic_dash_koka_src_shm__graph__as_Header(kk_whitemagic_dash_koka_src_shm__graph__header x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_whitemagic_dash_koka_src_shm__graph_Header*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_whitemagic_dash_koka_src_shm__graph__is_Header(kk_whitemagic_dash_koka_src_shm__graph__header x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_whitemagic_dash_koka_src_shm__graph__header kk_whitemagic_dash_koka_src_shm__graph__header_dup(kk_whitemagic_dash_koka_src_shm__graph__header _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_whitemagic_dash_koka_src_shm__graph__header_drop(kk_whitemagic_dash_koka_src_shm__graph__header _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_whitemagic_dash_koka_src_shm__graph__header_box(kk_whitemagic_dash_koka_src_shm__graph__header _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_whitemagic_dash_koka_src_shm__graph__header kk_whitemagic_dash_koka_src_shm__graph__header_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations

int64_t kk_whitemagic_dash_koka_src_shm__graph_shm_graph_open(kk_string_t name, kk_integer_t size, kk_context_t* _ctx); /* (name : string, size : int) -> int64 */ 

kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_shm_unmap(int64_t addr, kk_integer_t size, kk_context_t* _ctx); /* (addr : int64, size : int) -> int */ 

kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_shm_read_int(int64_t addr, kk_integer_t offset, kk_context_t* _ctx); /* (addr : int64, offset : int) -> int */ 

kk_string_t kk_whitemagic_dash_koka_src_shm__graph_shm_graph_walk(int64_t addr, kk_integer_t count, kk_integer_t start_id, kk_integer_t hops, kk_context_t* _ctx); /* (addr : int64, count : int, start-id : int, hops : int) -> string */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__graph_flush_stdout(kk_context_t* _ctx); /* () -> console/console () */ 

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_magic_number;
 
// "GRPH"

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_header_size;

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_slot_size;

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_capacity;
 
// Automatically generated. Retrieves the `magic` constructor field of the `:header` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_header_fs_magic(kk_whitemagic_dash_koka_src_shm__graph__header header, kk_context_t* _ctx) { /* (header : header) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x207 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(header, _ctx);
    kk_integer_t _x = _con_x207->magic;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `version` constructor field of the `:header` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_header_fs_version(kk_whitemagic_dash_koka_src_shm__graph__header header, kk_context_t* _ctx) { /* (header : header) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x208 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(header, _ctx);
    kk_integer_t _x = _con_x208->version;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `capacity` constructor field of the `:header` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_header_fs_capacity(kk_whitemagic_dash_koka_src_shm__graph__header header, kk_context_t* _ctx) { /* (header : header) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x209 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(header, _ctx);
    kk_integer_t _x = _con_x209->capacity;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_segment_size;
 
// Automatically generated. Retrieves the `count` constructor field of the `:header` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_header_fs_count(kk_whitemagic_dash_koka_src_shm__graph__header header, kk_context_t* _ctx) { /* (header : header) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x210 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(header, _ctx);
    kk_integer_t _x = _con_x210->count;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_whitemagic_dash_koka_src_shm__graph__header kk_whitemagic_dash_koka_src_shm__graph_header_fs__copy(kk_whitemagic_dash_koka_src_shm__graph__header _this, kk_std_core_types__optional magic, kk_std_core_types__optional version, kk_std_core_types__optional capacity_0, kk_std_core_types__optional count, kk_context_t* _ctx); /* (header, magic : ? int, version : ? int, capacity : ? int, count : ? int) -> header */ 

static inline kk_whitemagic_dash_koka_src_shm__graph__header kk_whitemagic_dash_koka_src_shm__graph_read_header(int64_t addr, kk_context_t* _ctx) { /* (addr : int64) -> header */ 
  kk_integer_t m = kk_whitemagic_dash_koka_src_shm__graph_shm_read_int(addr, kk_integer_from_small(0), _ctx); /*int*/;
  kk_integer_t v = kk_whitemagic_dash_koka_src_shm__graph_shm_read_int(addr, kk_integer_from_small(4), _ctx); /*int*/;
  kk_integer_t cap = kk_whitemagic_dash_koka_src_shm__graph_shm_read_int(addr, kk_integer_from_small(8), _ctx); /*int*/;
  kk_integer_t c = kk_whitemagic_dash_koka_src_shm__graph_shm_read_int(addr, kk_integer_from_small(12), _ctx); /*int*/;
  return kk_whitemagic_dash_koka_src_shm__graph__new_Header(kk_reuse_null, 0, m, v, cap, c, _ctx);
}

kk_string_t kk_whitemagic_dash_koka_src_shm__graph_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_extract_start_id(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> int */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068(int64_t addr, kk_string_t op, kk_string_t _c_x10015, kk_context_t* _ctx); /* (addr : int64, op : string, string) -> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069(int64_t addr_0, kk_string_t line, kk_context_t* _ctx); /* (addr : int64, line : string) -> <console/console,exn,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>,exn> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__graph_server_loop(int64_t addr_1, kk_context_t* _ctx); /* (addr : int64) -> io () */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__graph_main(kk_context_t* _ctx); /* () -> io () */ 

void kk_whitemagic_dash_koka_src_shm__graph__init(kk_context_t* _ctx);


void kk_whitemagic_dash_koka_src_shm__graph__done(kk_context_t* _ctx);

#endif // header
