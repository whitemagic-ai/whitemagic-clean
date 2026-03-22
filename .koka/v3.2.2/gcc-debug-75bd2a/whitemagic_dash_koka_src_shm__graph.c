// Koka generated module: whitemagic-koka/src/shm_graph, koka version: 3.2.2, platform: 64-bit
#include "whitemagic_dash_koka_src_shm__graph.h"
#ifndef SHM_GRAPH_H
#define SHM_GRAPH_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <kklib.h>

#define GRAPH_MAGIC 0x47525048
#define GRAPH_HEADER_SIZE 64
#define GRAPH_SLOT_SIZE 16

static inline int64_t kk_shm_graph_open(kk_string_t name, kk_integer_t size, kk_context_t* ctx) {
    const char* n = kk_string_cbuf_borrow(name, NULL, ctx);
    intptr_t sz = kk_integer_clamp_ssize_t(size, ctx);
    
    int fd = shm_open(n, O_RDWR, 0666);
    kk_string_drop(name, ctx);
    if (fd < 0) return 0;
    
    void* addr = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    if (addr == MAP_FAILED) return 0;
    return (int64_t)addr;
}


static inline kk_integer_t kk_shm_unmap(int64_t addr, kk_integer_t size, kk_context_t* ctx) {
    intptr_t sz = kk_integer_clamp_ssize_t(size, ctx);
    int res = munmap((void*)addr, sz);
    return kk_integer_from_int(res, ctx);
}

static inline kk_integer_t kk_shm_read_int(int64_t addr, kk_integer_t offset, kk_context_t* ctx) {
    intptr_t off = kk_integer_clamp_ssize_t(offset, ctx);
    int32_t val = *(int32_t*)(addr + off);
    return kk_integer_from_int(val, ctx);
}

#pragma GCC push_options

#pragma GCC optimize("O3,unroll-loops")
// A super simple graph walker in C over the SHM segment
// Returns JSON string with node traversal counts
static inline kk_string_t kk_shm_graph_walk(int64_t addr, kk_integer_t kk_count, kk_integer_t kk_start_id, kk_integer_t kk_hops, kk_context_t* ctx) {
    intptr_t count = kk_integer_clamp_ssize_t(kk_count, ctx);
    int32_t start_id = (int32_t)kk_integer_clamp_ssize_t(kk_start_id, ctx);
    int hops = (int)kk_integer_clamp_ssize_t(kk_hops, ctx);
    
    // In a real implementation we'd need an index (source -> offset)
    // Since edges are unsorted, walking is O(N) per hop unless we index it.
    // For this benchmark/prototype, let's just do a linear scan to find edges out of the current set of active nodes.
    
    int32_t* active_nodes = malloc(1000 * sizeof(int32_t));
    int32_t* next_nodes = malloc(1000 * sizeof(int32_t));
    int active_count = 1;
    active_nodes[0] = start_id;
    
    int traversed_edges = 0;
    
    for (int h = 0; h < hops; h++) {
        int next_count = 0;
        
        for (intptr_t i = 0; i < count; i++) {
            intptr_t offset = GRAPH_HEADER_SIZE + (i * GRAPH_SLOT_SIZE);
            int32_t src = *(int32_t*)(addr + offset);
            int32_t tgt = *(int32_t*)(addr + offset + 4);
            
            // Check if src is in active_nodes
            for (int a = 0; a < active_count; a++) {
                if (src == active_nodes[a]) {
                    if (next_count < 1000) {
                        next_nodes[next_count++] = tgt;
                    }
                    traversed_edges++;
                    break;
                }
            }
        }
        
        // Swap arrays
        memcpy(active_nodes, next_nodes, next_count * sizeof(int32_t));
        active_count = next_count;
    }
    
    free(active_nodes);
    free(next_nodes);
    
    char buf[256];
    snprintf(buf, sizeof(buf), "{\"nodes_visited\":%d,\"edges_traversed\":%d}", active_count, traversed_edges);
    return kk_string_alloc_from_utf8(buf, ctx);
}
#pragma GCC pop_options

#endif


int64_t kk_whitemagic_dash_koka_src_shm__graph_shm_graph_open(kk_string_t name, kk_integer_t size, kk_context_t* _ctx) { /* (name : string, size : int) -> int64 */ 
  return kk_shm_graph_open(name,size,kk_context());
}

kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_shm_unmap(int64_t addr, kk_integer_t size, kk_context_t* _ctx) { /* (addr : int64, size : int) -> int */ 
  return kk_shm_unmap(addr,size,kk_context());
}

kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_shm_read_int(int64_t addr, kk_integer_t offset, kk_context_t* _ctx) { /* (addr : int64, offset : int) -> int */ 
  return kk_shm_read_int(addr,offset,kk_context());
}

kk_string_t kk_whitemagic_dash_koka_src_shm__graph_shm_graph_walk(int64_t addr, kk_integer_t count, kk_integer_t start_id, kk_integer_t hops, kk_context_t* _ctx) { /* (addr : int64, count : int, start-id : int, hops : int) -> string */ 
  return kk_shm_graph_walk(addr,count,start_id,hops,kk_context());
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__graph_flush_stdout(kk_context_t* _ctx) { /* () -> console/console () */ 
  fflush(stdout); return kk_Unit;
}
kk_declare_string_literal(static, kk_whitemagic_dash_koka_src_shm__graph_shm_name, 24, "/whitemagic_graph_bridge")

kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_magic_number;

kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_header_size;

kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_slot_size;

kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_capacity;

kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_segment_size;

kk_whitemagic_dash_koka_src_shm__graph__header kk_whitemagic_dash_koka_src_shm__graph_header_fs__copy(kk_whitemagic_dash_koka_src_shm__graph__header _this, kk_std_core_types__optional magic, kk_std_core_types__optional version, kk_std_core_types__optional capacity_0, kk_std_core_types__optional count, kk_context_t* _ctx) { /* (header, magic : ? int, version : ? int, capacity : ? int, count : ? int) -> header */ 
  kk_integer_t _x_x211;
  if (kk_std_core_types__is_Optional(magic, _ctx)) {
    kk_box_t _box_x0 = magic._cons._Optional.value;
    kk_integer_t _uniq_magic_129 = kk_integer_unbox(_box_x0, _ctx);
    kk_integer_dup(_uniq_magic_129, _ctx);
    kk_std_core_types__optional_drop(magic, _ctx);
    _x_x211 = _uniq_magic_129; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(magic, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x212 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(_this, _ctx);
      kk_integer_t _x = _con_x212->magic;
      kk_integer_dup(_x, _ctx);
      _x_x211 = _x; /*int*/
    }
  }
  kk_integer_t _x_x213;
  if (kk_std_core_types__is_Optional(version, _ctx)) {
    kk_box_t _box_x1 = version._cons._Optional.value;
    kk_integer_t _uniq_version_137 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_version_137, _ctx);
    kk_std_core_types__optional_drop(version, _ctx);
    _x_x213 = _uniq_version_137; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(version, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x214 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(_this, _ctx);
      kk_integer_t _x_0 = _con_x214->version;
      kk_integer_dup(_x_0, _ctx);
      _x_x213 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x215;
  if (kk_std_core_types__is_Optional(capacity_0, _ctx)) {
    kk_box_t _box_x2 = capacity_0._cons._Optional.value;
    kk_integer_t _uniq_capacity_145 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_capacity_145, _ctx);
    kk_std_core_types__optional_drop(capacity_0, _ctx);
    _x_x215 = _uniq_capacity_145; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(capacity_0, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x216 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(_this, _ctx);
      kk_integer_t _x_1 = _con_x216->capacity;
      kk_integer_dup(_x_1, _ctx);
      _x_x215 = _x_1; /*int*/
    }
  }
  kk_integer_t _x_x217;
  if (kk_std_core_types__is_Optional(count, _ctx)) {
    kk_box_t _box_x3 = count._cons._Optional.value;
    kk_integer_t _uniq_count_153 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_count_153, _ctx);
    kk_std_core_types__optional_drop(count, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(4)), _ctx);
    _x_x217 = _uniq_count_153; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(count, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x218 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(_this, _ctx);
      kk_integer_t _pat_0_3 = _con_x218->magic;
      kk_integer_t _pat_1_4 = _con_x218->version;
      kk_integer_t _pat_2_3 = _con_x218->capacity;
      kk_integer_t _x_2 = _con_x218->count;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_2_3, _ctx);
        kk_integer_drop(_pat_1_4, _ctx);
        kk_integer_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x217 = _x_2; /*int*/
    }
  }
  return kk_whitemagic_dash_koka_src_shm__graph__new_Header(kk_reuse_null, 0, _x_x211, _x_x213, _x_x215, _x_x217, _ctx);
}

kk_string_t kk_whitemagic_dash_koka_src_shm__graph_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x193;
  kk_string_t _x_x219 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x220;
  kk_define_string_literal(, _s_x221, 6, "\"walk\"", _ctx)
  _x_x220 = kk_string_dup(_s_x221, _ctx); /*string*/
  _match_x193 = kk_string_contains(_x_x219,_x_x220,kk_context()); /*bool*/
  if (_match_x193) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x222, 4, "walk", _ctx)
    return kk_string_dup(_s_x222, _ctx);
  }
  {
    bool _match_x194;
    kk_string_t _x_x223 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x224;
    kk_define_string_literal(, _s_x225, 8, "\"status\"", _ctx)
    _x_x224 = kk_string_dup(_s_x225, _ctx); /*string*/
    _match_x194 = kk_string_contains(_x_x223,_x_x224,kk_context()); /*bool*/
    if (_match_x194) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x226, 6, "status", _ctx)
      return kk_string_dup(_s_x226, _ctx);
    }
    {
      bool _match_x195;
      kk_string_t _x_x227;
      kk_define_string_literal(, _s_x228, 6, "\"quit\"", _ctx)
      _x_x227 = kk_string_dup(_s_x228, _ctx); /*string*/
      _match_x195 = kk_string_contains(line,_x_x227,kk_context()); /*bool*/
      if (_match_x195) {
        kk_define_string_literal(, _s_x229, 4, "quit", _ctx)
        return kk_string_dup(_s_x229, _ctx);
      }
      {
        kk_define_string_literal(, _s_x230, 7, "unknown", _ctx)
        return kk_string_dup(_s_x230, _ctx);
      }
    }
  }
}

kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_extract_start_id(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> int */ 
  kk_vector_t v_10011;
  kk_string_t _x_x231;
  kk_define_string_literal(, _s_x232, 11, "\"start_id\":", _ctx)
  _x_x231 = kk_string_dup(_s_x232, _ctx); /*string*/
  v_10011 = kk_string_splitv(line,_x_x231,kk_context()); /*vector<string>*/
  kk_std_core_types__list parts = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  if (kk_std_core_types__is_Cons(parts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x233 = kk_std_core_types__as_Cons(parts, _ctx);
    kk_box_t _box_x4 = _con_x233->head;
    kk_std_core_types__list _pat_1 = _con_x233->tail;
    if (kk_std_core_types__is_Cons(_pat_1, _ctx)) {
      struct kk_std_core_types_Cons* _con_x234 = kk_std_core_types__as_Cons(_pat_1, _ctx);
      kk_box_t _box_x5 = _con_x234->head;
      kk_string_t _pat_0 = kk_string_unbox(_box_x4);
      kk_std_core_types__list _pat_2 = _con_x234->tail;
      kk_string_t rest = kk_string_unbox(_box_x5);
      if kk_likely(kk_datatype_ptr_is_unique(parts, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_1, _ctx)) {
          kk_std_core_types__list_drop(_pat_2, _ctx);
          kk_datatype_ptr_free(_pat_1, _ctx);
        }
        else {
          kk_string_dup(rest, _ctx);
          kk_datatype_ptr_decref(_pat_1, _ctx);
        }
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(parts, _ctx);
      }
      else {
        kk_string_dup(rest, _ctx);
        kk_datatype_ptr_decref(parts, _ctx);
      }
      kk_vector_t v_10011_0;
      kk_string_t _x_x235;
      kk_define_string_literal(, _s_x236, 1, "}", _ctx)
      _x_x235 = kk_string_dup(_s_x236, _ctx); /*string*/
      v_10011_0 = kk_string_splitv(rest,_x_x235,kk_context()); /*vector<string>*/
      kk_std_core_types__list _match_x190 = kk_std_core_vector_vlist(v_10011_0, kk_std_core_types__new_None(_ctx), _ctx); /*list<10000>*/;
      if (kk_std_core_types__is_Cons(_match_x190, _ctx)) {
        struct kk_std_core_types_Cons* _con_x237 = kk_std_core_types__as_Cons(_match_x190, _ctx);
        kk_box_t _box_x6 = _con_x237->head;
        kk_std_core_types__list _pat_4 = _con_x237->tail;
        kk_string_t id = kk_string_unbox(_box_x6);
        if kk_likely(kk_datatype_ptr_is_unique(_match_x190, _ctx)) {
          kk_std_core_types__list_drop(_pat_4, _ctx);
          kk_datatype_ptr_free(_match_x190, _ctx);
        }
        else {
          kk_string_dup(id, _ctx);
          kk_datatype_ptr_decref(_match_x190, _ctx);
        }
        kk_string_t s_1_10010;
        kk_string_t _x_x238 = kk_string_trim_left(id,kk_context()); /*string*/
        s_1_10010 = kk_string_trim_right(_x_x238,kk_context()); /*string*/
        kk_std_core_types__maybe _match_x191;
        bool _x_x239;
        kk_std_core_types__optional _match_x192 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x192, _ctx)) {
          kk_box_t _box_x7 = _match_x192._cons._Optional.value;
          bool _uniq_hex_581 = kk_bool_unbox(_box_x7);
          kk_std_core_types__optional_drop(_match_x192, _ctx);
          _x_x239 = _uniq_hex_581; /*bool*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x192, _ctx);
          _x_x239 = false; /*bool*/
        }
        _match_x191 = kk_std_core_int_xparse(s_1_10010, _x_x239, _ctx); /*maybe<int>*/
        if (kk_std_core_types__is_Just(_match_x191, _ctx)) {
          kk_box_t _box_x8 = _match_x191._cons.Just.value;
          kk_integer_t i = kk_integer_unbox(_box_x8, _ctx);
          kk_integer_dup(i, _ctx);
          kk_std_core_types__maybe_drop(_match_x191, _ctx);
          return i;
        }
        {
          return kk_integer_from_small(0);
        }
      }
      {
        return kk_integer_from_small(0);
      }
    }
  }
  {
    kk_std_core_types__list_drop(parts, _ctx);
    return kk_integer_from_small(0);
  }
  {
    kk_std_core_types__list_drop(parts, _ctx);
    return kk_integer_from_small(0);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun241__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun241(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10068_fun241(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun241, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun241(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x242 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__graph_flush_stdout(_ctx);
  return kk_unit_box(_x_x242);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun246__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun246(kk_function_t _fself, kk_box_t _b_x14, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10068_fun246(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun246, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun246(kk_function_t _fself, kk_box_t _b_x14, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x247 = kk_Unit;
  int64_t _x_x248 = kk_int64_unbox(_b_x14, KK_OWNED, _ctx); /*int64*/
  kk_whitemagic_dash_koka_src_shm__graph_server_loop(_x_x248, _ctx);
  return kk_unit_box(_x_x247);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun250__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun250(kk_function_t _fself, kk_box_t _b_x18, kk_box_t _b_x19, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10068_fun250(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun250, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068_fun250(kk_function_t _fself, kk_box_t _b_x18, kk_box_t _b_x19, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x251;
  int64_t _x_x252 = kk_int64_unbox(_b_x18, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x253 = kk_integer_unbox(_b_x19, _ctx); /*int*/
  _x_x251 = kk_whitemagic_dash_koka_src_shm__graph_shm_unmap(_x_x252, _x_x253, _ctx); /*int*/
  return kk_integer_box(_x_x251, _ctx);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068(int64_t addr, kk_string_t op, kk_string_t _c_x10015, kk_context_t* _ctx) { /* (addr : int64, op : string, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10015, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x240 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10068_fun241(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x240);
  bool _match_x189;
  kk_string_t _x_x243;
  kk_define_string_literal(, _s_x244, 4, "quit", _ctx)
  _x_x243 = kk_string_dup(_s_x244, _ctx); /*string*/
  _match_x189 = kk_string_is_neq(op,_x_x243,kk_context()); /*bool*/
  if (_match_x189) {
    kk_ssize_t _b_x11_23 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_box_t _x_x245 = kk_std_core_hnd__open_at1(_b_x11_23, kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10068_fun246(_ctx), kk_int64_box(addr, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x245); return kk_Unit;
  }
  {
    kk_integer_t _pat_9;
    kk_box_t _x_x249;
    kk_box_t _x_x254;
    kk_integer_t _x_x255 = kk_integer_dup(kk_whitemagic_dash_koka_src_shm__graph_segment_size, _ctx); /*int*/
    _x_x254 = kk_integer_box(_x_x255, _ctx); /*10001*/
    _x_x249 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10068_fun250(_ctx), kk_int64_box(addr, _ctx), _x_x254, _ctx); /*10002*/
    _pat_9 = kk_integer_unbox(_x_x249, _ctx); /*int*/
    kk_integer_drop(_pat_9, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun260__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun260(kk_function_t _fself, kk_box_t _b_x28, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun260(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun260, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun260(kk_function_t _fself, kk_box_t _b_x28, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x261;
  kk_string_t _x_x262 = kk_string_unbox(_b_x28); /*string*/
  _x_x261 = kk_whitemagic_dash_koka_src_shm__graph_extract_op(_x_x262, _ctx); /*string*/
  return kk_string_box(_x_x261);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun267__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun267(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun267(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun267, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun267(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x268;
  kk_string_t _x_x269 = kk_string_unbox(_b_x33); /*string*/
  _x_x268 = kk_whitemagic_dash_koka_src_shm__graph_extract_start_id(_x_x269, _ctx); /*int*/
  return kk_integer_box(_x_x268, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun271__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun271(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun271(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun271, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun271(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__graph__header _x_x272;
  int64_t _x_x273 = kk_int64_unbox(_b_x38, KK_OWNED, _ctx); /*int64*/
  _x_x272 = kk_whitemagic_dash_koka_src_shm__graph_read_header(_x_x273, _ctx); /*whitemagic-koka/src/shm_graph/header*/
  return kk_whitemagic_dash_koka_src_shm__graph__header_box(_x_x272, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun275__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun275(kk_function_t _fself, kk_box_t _b_x43, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun275(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun275, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun275(kk_function_t _fself, kk_box_t _b_x43, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x276;
  kk_whitemagic_dash_koka_src_shm__graph__header _match_x186 = kk_whitemagic_dash_koka_src_shm__graph__header_unbox(_b_x43, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_graph/header*/;
  {
    struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x277 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(_match_x186, _ctx);
    kk_integer_t _pat_0_0_0 = _con_x277->magic;
    kk_integer_t _pat_1_0_0 = _con_x277->version;
    kk_integer_t _pat_2_0 = _con_x277->capacity;
    kk_integer_t _x = _con_x277->count;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x186, _ctx)) {
      kk_integer_drop(_pat_2_0, _ctx);
      kk_integer_drop(_pat_1_0_0, _ctx);
      kk_integer_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(_match_x186, _ctx);
    }
    else {
      kk_integer_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x186, _ctx);
    }
    _x_x276 = _x; /*int*/
  }
  return kk_integer_box(_x_x276, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun282__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun282(kk_function_t _fself, kk_box_t _b_x46, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun282(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun282, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun282(kk_function_t _fself, kk_box_t _b_x46, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x283;
  kk_whitemagic_dash_koka_src_shm__graph__header _match_x185 = kk_whitemagic_dash_koka_src_shm__graph__header_unbox(_b_x46, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_graph/header*/;
  {
    struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x284 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(_match_x185, _ctx);
    kk_integer_t _pat_0_1 = _con_x284->magic;
    kk_integer_t _pat_1_1 = _con_x284->version;
    kk_integer_t _pat_2_2 = _con_x284->capacity;
    kk_integer_t _x_0 = _con_x284->count;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x185, _ctx)) {
      kk_integer_drop(_pat_2_2, _ctx);
      kk_integer_drop(_pat_1_1, _ctx);
      kk_integer_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(_match_x185, _ctx);
    }
    else {
      kk_integer_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x185, _ctx);
    }
    _x_x283 = _x_0; /*int*/
  }
  return kk_integer_box(_x_x283, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun286__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun286(kk_function_t _fself, kk_box_t _b_x55, kk_box_t _b_x56, kk_box_t _b_x57, kk_box_t _b_x58, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun286(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun286, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun286(kk_function_t _fself, kk_box_t _b_x55, kk_box_t _b_x56, kk_box_t _b_x57, kk_box_t _b_x58, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x287;
  int64_t _x_x288 = kk_int64_unbox(_b_x55, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x289 = kk_integer_unbox(_b_x56, _ctx); /*int*/
  kk_integer_t _x_x290 = kk_integer_unbox(_b_x57, _ctx); /*int*/
  kk_integer_t _x_x291 = kk_integer_unbox(_b_x58, _ctx); /*int*/
  _x_x287 = kk_whitemagic_dash_koka_src_shm__graph_shm_graph_walk(_x_x288, _x_x289, _x_x290, _x_x291, _ctx); /*string*/
  return kk_string_box(_x_x287);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun298__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun298(kk_function_t _fself, kk_box_t _b_x66, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun298(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun298, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun298(kk_function_t _fself, kk_box_t _b_x66, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__graph__header _x_x299;
  int64_t _x_x300 = kk_int64_unbox(_b_x66, KK_OWNED, _ctx); /*int64*/
  _x_x299 = kk_whitemagic_dash_koka_src_shm__graph_read_header(_x_x300, _ctx); /*whitemagic-koka/src/shm_graph/header*/
  return kk_whitemagic_dash_koka_src_shm__graph__header_box(_x_x299, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun307__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun307(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun307(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun307, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun307(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__graph__header header_1_80 = kk_whitemagic_dash_koka_src_shm__graph__header_unbox(_b_x71, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_graph/header*/;
  kk_integer_t _x_x308;
  {
    struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x309 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(header_1_80, _ctx);
    kk_integer_t _pat_0_2 = _con_x309->magic;
    kk_integer_t _pat_1_2 = _con_x309->version;
    kk_integer_t _pat_2_3 = _con_x309->capacity;
    kk_integer_t _x_1 = _con_x309->count;
    if kk_likely(kk_datatype_ptr_is_unique(header_1_80, _ctx)) {
      kk_integer_drop(_pat_2_3, _ctx);
      kk_integer_drop(_pat_1_2, _ctx);
      kk_integer_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(header_1_80, _ctx);
    }
    else {
      kk_integer_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(header_1_80, _ctx);
    }
    _x_x308 = _x_1; /*int*/
  }
  return kk_integer_box(_x_x308, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun315__t {
  struct kk_function_s _base;
  kk_string_t op_0;
  int64_t addr_0;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun315(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun315(kk_string_t op_0, int64_t addr_0, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun315__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun315__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun315, kk_context());
  _self->op_0 = op_0;
  _self->addr_0 = addr_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun315(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun315__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069_fun315__t*, _fself, _ctx);
  kk_string_t op_0 = _self->op_0; /* string */
  int64_t addr_0 = _self->addr_0; /* int64 */
  kk_drop_match(_self, {kk_string_dup(op_0, _ctx);kk_skip_dup(addr_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10015_0_81 = kk_string_unbox(_b_x77); /*string*/;
  kk_unit_t _x_x316 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068(addr_0, op_0, _c_x10015_0_81, _ctx);
  return kk_unit_box(_x_x316);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069(int64_t addr_0, kk_string_t line, kk_context_t* _ctx) { /* (addr : int64, line : string) -> <console/console,exn,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>,exn> () */ 
  bool _match_x182;
  kk_string_t _x_x256 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x257 = kk_string_empty(); /*string*/
  _match_x182 = kk_string_is_eq(_x_x256,_x_x257,kk_context()); /*bool*/
  if (_match_x182) {
    kk_string_drop(line, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_string_t op_0;
    kk_box_t _x_x259;
    kk_box_t _x_x263;
    kk_string_t _x_x264 = kk_string_dup(line, _ctx); /*string*/
    _x_x263 = kk_string_box(_x_x264); /*10000*/
    _x_x259 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun260(_ctx), _x_x263, _ctx); /*10001*/
    op_0 = kk_string_unbox(_x_x259); /*string*/
    kk_string_t x_10070;
    if (kk_string_cmp_cstr_borrow(op_0, "walk", _ctx) == 0) {
      kk_integer_t start_id;
      kk_box_t _x_x266 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun267(_ctx), kk_string_box(line), _ctx); /*10001*/
      start_id = kk_integer_unbox(_x_x266, _ctx); /*int*/
      kk_whitemagic_dash_koka_src_shm__graph__header h;
      kk_box_t _x_x270 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun271(_ctx), kk_int64_box(addr_0, _ctx), _ctx); /*10001*/
      h = kk_whitemagic_dash_koka_src_shm__graph__header_unbox(_x_x270, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_graph/header*/
      bool _match_x184;
      kk_integer_t _brw_x187;
      kk_box_t _x_x274;
      kk_box_t _x_x278;
      kk_whitemagic_dash_koka_src_shm__graph__header _x_x279 = kk_whitemagic_dash_koka_src_shm__graph__header_dup(h, _ctx); /*whitemagic-koka/src/shm_graph/header*/
      _x_x278 = kk_whitemagic_dash_koka_src_shm__graph__header_box(_x_x279, _ctx); /*10000*/
      _x_x274 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun275(_ctx), _x_x278, _ctx); /*10001*/
      _brw_x187 = kk_integer_unbox(_x_x274, _ctx); /*int*/
      bool _brw_x188 = kk_integer_eq_borrow(_brw_x187,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x187, _ctx);
      _match_x184 = _brw_x188; /*bool*/
      if (_match_x184) {
        kk_integer_drop(start_id, _ctx);
        kk_datatype_ptr_dropn(h, (KK_I32(4)), _ctx);
        kk_define_string_literal(, _s_x280, 17, "{\"error\":\"empty\"}", _ctx)
        x_10070 = kk_string_dup(_s_x280, _ctx); /*string*/
        goto _match_x265;
      }
      {
        kk_integer_t _x_x2_10051;
        kk_box_t _x_x281 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun282(_ctx), kk_whitemagic_dash_koka_src_shm__graph__header_box(h, _ctx), _ctx); /*10001*/
        _x_x2_10051 = kk_integer_unbox(_x_x281, _ctx); /*int*/
        kk_string_t res;
        kk_box_t _x_x285 = kk_std_core_hnd__open_none4(kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun286(_ctx), kk_int64_box(addr_0, _ctx), kk_integer_box(_x_x2_10051, _ctx), kk_integer_box(start_id, _ctx), kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*10004*/
        res = kk_string_unbox(_x_x285); /*string*/
        kk_string_t _x_x292;
        kk_define_string_literal(, _s_x293, 25, "{\"status\":\"ok\",\"results\":", _ctx)
        _x_x292 = kk_string_dup(_s_x293, _ctx); /*string*/
        kk_string_t _x_x294;
        kk_string_t _x_x295;
        kk_define_string_literal(, _s_x296, 1, "}", _ctx)
        _x_x295 = kk_string_dup(_s_x296, _ctx); /*string*/
        _x_x294 = kk_std_core_types__lp__plus__plus__rp_(res, _x_x295, _ctx); /*string*/
        x_10070 = kk_std_core_types__lp__plus__plus__rp_(_x_x292, _x_x294, _ctx); /*string*/
        goto _match_x265;
      }
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_whitemagic_dash_koka_src_shm__graph__header h_0;
      kk_box_t _x_x297 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun298(_ctx), kk_int64_box(addr_0, _ctx), _ctx); /*10001*/
      h_0 = kk_whitemagic_dash_koka_src_shm__graph__header_unbox(_x_x297, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_graph/header*/
      kk_string_t _x_x301;
      kk_define_string_literal(, _s_x302, 26, "{\"shm_graph\":true,\"count\":", _ctx)
      _x_x301 = kk_string_dup(_s_x302, _ctx); /*string*/
      kk_string_t _x_x303;
      kk_string_t _x_x304;
      kk_integer_t _x_x305;
      kk_box_t _x_x306 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun307(_ctx), kk_whitemagic_dash_koka_src_shm__graph__header_box(h_0, _ctx), _ctx); /*10001*/
      _x_x305 = kk_integer_unbox(_x_x306, _ctx); /*int*/
      _x_x304 = kk_std_core_int_show(_x_x305, _ctx); /*string*/
      kk_string_t _x_x310;
      kk_define_string_literal(, _s_x311, 1, "}", _ctx)
      _x_x310 = kk_string_dup(_s_x311, _ctx); /*string*/
      _x_x303 = kk_std_core_types__lp__plus__plus__rp_(_x_x304, _x_x310, _ctx); /*string*/
      x_10070 = kk_std_core_types__lp__plus__plus__rp_(_x_x301, _x_x303, _ctx); /*string*/
      goto _match_x265;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "quit", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x312, 20, "{\"status\":\"stopped\"}", _ctx)
      x_10070 = kk_string_dup(_s_x312, _ctx); /*string*/
      goto _match_x265;
    }
    {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x313, 22, "{\"error\":\"unknown op\"}", _ctx)
      x_10070 = kk_string_dup(_s_x313, _ctx); /*string*/
    }
    _match_x265: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_10070, _ctx);
      kk_box_t _x_x314 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_shm__graph__new_mlift_server_loop_10069_fun315(op_0, addr_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x314); return kk_Unit;
    }
    {
      kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10068(addr_0, op_0, x_10070, _ctx); return kk_Unit;
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun318__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun318(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x_0, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun318(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun318, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun319__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun319(kk_function_t _fself, kk_function_t _b_x84, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun319(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun319, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun320__t {
  struct kk_function_s _base;
  kk_function_t _b_x84;
};
static kk_unit_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun320(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x85, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun320(kk_function_t _b_x84, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun320__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun320__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun320, kk_context());
  _self->_b_x84 = _b_x84;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun320(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x85, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun320__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun320__t*, _fself, _ctx);
  kk_function_t _b_x84 = _self->_b_x84; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x84, _ctx);}, {}, _ctx)
  kk_box_t _x_x321 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x84, (_b_x84, _b_x85, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x321); return kk_Unit;
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun319(kk_function_t _fself, kk_function_t _b_x84, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t ___wildcard_x653__45_107 = kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun320(_b_x84, _ctx); /*(hnd/resume-result<364,()>) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> ()*/;
  kk_function_drop(___wildcard_x653__45_107, _ctx);
  return kk_unit_box(kk_Unit);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun318(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  kk_std_core_exn__exception_drop(x_0, _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun319(_ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun324__t {
  struct kk_function_s _base;
  kk_function_t _b_x86_103;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun324(kk_function_t _fself, int32_t _b_x87, kk_std_core_hnd__ev _b_x88, kk_box_t _b_x89, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun324(kk_function_t _b_x86_103, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun324__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun324__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun324, kk_context());
  _self->_b_x86_103 = _b_x86_103;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun324(kk_function_t _fself, int32_t _b_x87, kk_std_core_hnd__ev _b_x88, kk_box_t _b_x89, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun324__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun324__t*, _fself, _ctx);
  kk_function_t _b_x86_103 = _self->_b_x86_103; /* (m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x@0 : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 364 */
  kk_drop_match(_self, {kk_function_dup(_b_x86_103, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x325 = kk_std_core_exn__exception_unbox(_b_x89, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x86_103, (_b_x86_103, _b_x87, _b_x88, _x_x325, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun326__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun326(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun326(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun326, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun326(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_108 = kk_Unit;
  kk_unit_unbox(_b_x99);
  return kk_unit_box(_res_108);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun327__t {
  struct kk_function_s _base;
  int64_t addr_1;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun327(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun327(int64_t addr_1, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun327__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun327__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun327, kk_context());
  _self->addr_1 = addr_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun329__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun329(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun329(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun329, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun329(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x330 = kk_std_os_readline_readline(_ctx); /*string*/
  return kk_string_box(_x_x330);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun333__t {
  struct kk_function_s _base;
  int64_t addr_1;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun333(kk_function_t _fself, kk_box_t _b_x95, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun333(int64_t addr_1, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun333__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun333__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun333, kk_context());
  _self->addr_1 = addr_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun333(kk_function_t _fself, kk_box_t _b_x95, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun333__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun333__t*, _fself, _ctx);
  int64_t addr_1 = _self->addr_1; /* int64 */
  kk_drop_match(_self, {kk_skip_dup(addr_1, _ctx);}, {}, _ctx)
  kk_string_t line_0_109 = kk_string_unbox(_b_x95); /*string*/;
  kk_unit_t _x_x334 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069(addr_1, line_0_109, _ctx);
  return kk_unit_box(_x_x334);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun327(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun327__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__graph_server_loop_fun327__t*, _fself, _ctx);
  int64_t addr_1 = _self->addr_1; /* int64 */
  kk_drop_match(_self, {kk_skip_dup(addr_1, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x90_92 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_string_t x_1_10073;
  kk_box_t _x_x328 = kk_std_core_hnd__open_at0(_b_x90_92, kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun329(_ctx), _ctx); /*10000*/
  x_1_10073 = kk_string_unbox(_x_x328); /*string*/
  kk_unit_t _x_x331 = kk_Unit;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_1_10073, _ctx);
    kk_box_t _x_x332 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun333(addr_1, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x332);
  }
  else {
    kk_whitemagic_dash_koka_src_shm__graph__mlift_server_loop_10069(addr_1, x_1_10073, _ctx);
  }
  return kk_unit_box(_x_x331);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__graph_server_loop(int64_t addr_1, kk_context_t* _ctx) { /* (addr : int64) -> io () */ 
  kk_box_t _x_x317;
  kk_function_t _b_x86_103 = kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun318(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x@0 : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 364*/;
  kk_std_core_exn__exn _x_x322;
  kk_std_core_hnd__clause1 _x_x323 = kk_std_core_hnd__new_Clause1(kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun324(_b_x86_103, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x322 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x323, _ctx); /*exn<10005,10006>*/
  _x_x317 = kk_std_core_exn_exn_fs__handle(_x_x322, kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun326(_ctx), kk_whitemagic_dash_koka_src_shm__graph_new_server_loop_fun327(addr_1, _ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x317); return kk_Unit;
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun336__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun336(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun336(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun336, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun337__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun337(kk_function_t _fself, kk_function_t _b_x112, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun337(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun337, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun338__t {
  struct kk_function_s _base;
  kk_function_t _b_x112;
};
static kk_unit_t kk_whitemagic_dash_koka_src_shm__graph_main_fun338(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x113, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun338(kk_function_t _b_x112, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_main_fun338__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__graph_main_fun338__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__graph_main_fun338, kk_context());
  _self->_b_x112 = _b_x112;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_whitemagic_dash_koka_src_shm__graph_main_fun338(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x113, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_main_fun338__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__graph_main_fun338__t*, _fself, _ctx);
  kk_function_t _b_x112 = _self->_b_x112; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x112, _ctx);}, {}, _ctx)
  kk_box_t _x_x339 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x112, (_b_x112, _b_x113, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x339); return kk_Unit;
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun337(kk_function_t _fself, kk_function_t _b_x112, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t ___wildcard_x653__45_174 = kk_whitemagic_dash_koka_src_shm__graph_new_main_fun338(_b_x112, _ctx); /*(hnd/resume-result<967,()>) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> ()*/;
  kk_function_drop(___wildcard_x653__45_174, _ctx);
  return kk_unit_box(kk_Unit);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun336(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  kk_std_core_exn__exception_drop(x, _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_whitemagic_dash_koka_src_shm__graph_new_main_fun337(_ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun342__t {
  struct kk_function_s _base;
  kk_function_t _b_x114_162;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun342(kk_function_t _fself, int32_t _b_x115, kk_std_core_hnd__ev _b_x116, kk_box_t _b_x117, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun342(kk_function_t _b_x114_162, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_main_fun342__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__graph_main_fun342__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__graph_main_fun342, kk_context());
  _self->_b_x114_162 = _b_x114_162;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun342(kk_function_t _fself, int32_t _b_x115, kk_std_core_hnd__ev _b_x116, kk_box_t _b_x117, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_main_fun342__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__graph_main_fun342__t*, _fself, _ctx);
  kk_function_t _b_x114_162 = _self->_b_x114_162; /* (m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 967 */
  kk_drop_match(_self, {kk_function_dup(_b_x114_162, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x343 = kk_std_core_exn__exception_unbox(_b_x117, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x114_162, (_b_x114_162, _b_x115, _b_x116, _x_x343, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun344__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun344(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun344(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun344, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun344(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_175 = kk_Unit;
  kk_unit_unbox(_b_x158);
  return kk_unit_box(_res_175);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun345__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun345(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun345(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun345, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun349__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun349(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun349(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun349, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun349(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x350 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__graph_flush_stdout(_ctx);
  return kk_unit_box(_x_x350);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun352__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun352(kk_function_t _fself, kk_box_t _b_x123, kk_box_t _b_x124, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun352(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun352, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun352(kk_function_t _fself, kk_box_t _b_x123, kk_box_t _b_x124, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x353;
  kk_string_t _x_x354 = kk_string_unbox(_b_x123); /*string*/
  kk_integer_t _x_x355 = kk_integer_unbox(_b_x124, _ctx); /*int*/
  _x_x353 = kk_whitemagic_dash_koka_src_shm__graph_shm_graph_open(_x_x354, _x_x355, _ctx); /*int64*/
  return kk_int64_box(_x_x353, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun363__t {
  struct kk_function_s _base;
};
static int64_t kk_whitemagic_dash_koka_src_shm__graph_main_fun363(kk_function_t _fself, kk_integer_t _x1_x362, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun363(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun363, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static int64_t kk_whitemagic_dash_koka_src_shm__graph_main_fun363(kk_function_t _fself, kk_integer_t _x1_x362, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_int64_int64(_x1_x362, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun366__t {
  struct kk_function_s _base;
  kk_function_t _b_x128_165;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun366(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun366(kk_function_t _b_x128_165, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_main_fun366__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__graph_main_fun366__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__graph_main_fun366, kk_context());
  _self->_b_x128_165 = _b_x128_165;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun366(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_main_fun366__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__graph_main_fun366__t*, _fself, _ctx);
  kk_function_t _b_x128_165 = _self->_b_x128_165; /* (i : int) -> int64 */
  kk_drop_match(_self, {kk_function_dup(_b_x128_165, _ctx);}, {}, _ctx)
  int64_t _x_x367;
  kk_integer_t _x_x368 = kk_integer_unbox(_b_x130, _ctx); /*int*/
  _x_x367 = kk_function_call(int64_t, (kk_function_t, kk_integer_t, kk_context_t*), _b_x128_165, (_b_x128_165, _x_x368, _ctx), _ctx); /*int64*/
  return kk_int64_box(_x_x367, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun372__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun372(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun372(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun372, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun372(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x373 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__graph_flush_stdout(_ctx);
  return kk_unit_box(_x_x373);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun375__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun375(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun375(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun375, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun375(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__graph__header _x_x376;
  int64_t _x_x377 = kk_int64_unbox(_b_x134, KK_OWNED, _ctx); /*int64*/
  _x_x376 = kk_whitemagic_dash_koka_src_shm__graph_read_header(_x_x377, _ctx); /*whitemagic-koka/src/shm_graph/header*/
  return kk_whitemagic_dash_koka_src_shm__graph__header_box(_x_x376, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun378__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_main_fun378(kk_function_t _fself, kk_whitemagic_dash_koka_src_shm__graph__header header, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun378(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun378, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_whitemagic_dash_koka_src_shm__graph_main_fun378(kk_function_t _fself, kk_whitemagic_dash_koka_src_shm__graph__header header, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_whitemagic_dash_koka_src_shm__graph_Header* _con_x379 = kk_whitemagic_dash_koka_src_shm__graph__as_Header(header, _ctx);
    kk_integer_t _x = _con_x379->magic;
    kk_integer_t _pat_0_0 = _con_x379->version;
    kk_integer_t _pat_1_0 = _con_x379->capacity;
    kk_integer_t _pat_2 = _con_x379->count;
    if kk_likely(kk_datatype_ptr_is_unique(header, _ctx)) {
      kk_integer_drop(_pat_2, _ctx);
      kk_integer_drop(_pat_1_0, _ctx);
      kk_integer_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(header, _ctx);
    }
    else {
      kk_integer_dup(_x, _ctx);
      kk_datatype_ptr_decref(header, _ctx);
    }
    return _x;
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun381__t {
  struct kk_function_s _base;
  kk_function_t _b_x137_168;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun381(kk_function_t _fself, kk_box_t _b_x139, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun381(kk_function_t _b_x137_168, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_main_fun381__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__graph_main_fun381__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__graph_main_fun381, kk_context());
  _self->_b_x137_168 = _b_x137_168;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun381(kk_function_t _fself, kk_box_t _b_x139, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__graph_main_fun381__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__graph_main_fun381__t*, _fself, _ctx);
  kk_function_t _b_x137_168 = _self->_b_x137_168; /* (header : whitemagic-koka/src/shm_graph/header) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x137_168, _ctx);}, {}, _ctx)
  kk_integer_t _x_x382;
  kk_whitemagic_dash_koka_src_shm__graph__header _x_x383 = kk_whitemagic_dash_koka_src_shm__graph__header_unbox(_b_x139, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_graph/header*/
  _x_x382 = kk_function_call(kk_integer_t, (kk_function_t, kk_whitemagic_dash_koka_src_shm__graph__header, kk_context_t*), _b_x137_168, (_b_x137_168, _x_x383, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x382, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun387__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun387(kk_function_t _fself, kk_box_t _b_x143, kk_box_t _b_x144, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun387(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun387, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun387(kk_function_t _fself, kk_box_t _b_x143, kk_box_t _b_x144, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x388;
  int64_t _x_x389 = kk_int64_unbox(_b_x143, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x390 = kk_integer_unbox(_b_x144, _ctx); /*int*/
  _x_x388 = kk_whitemagic_dash_koka_src_shm__graph_shm_unmap(_x_x389, _x_x390, _ctx); /*int*/
  return kk_integer_box(_x_x388, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun394__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun394(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun394(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun394, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun394(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x395 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__graph_flush_stdout(_ctx);
  return kk_unit_box(_x_x395);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun399__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun399(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun399(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun399, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun399(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x400 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__graph_flush_stdout(_ctx);
  return kk_unit_box(_x_x400);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__graph_main_fun402__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun402(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__graph_new_main_fun402(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__graph_main_fun402, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun402(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x403 = kk_Unit;
  int64_t _x_x404 = kk_int64_unbox(_b_x154, KK_OWNED, _ctx); /*int64*/
  kk_whitemagic_dash_koka_src_shm__graph_server_loop(_x_x404, _ctx);
  return kk_unit_box(_x_x403);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__graph_main_fun345(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x346;
  kk_define_string_literal(, _s_x347, 38, "{\"status\":\"starting\",\"shm_graph\":true}", _ctx)
  _x_x346 = kk_string_dup(_s_x347, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x346, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x348 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__graph_new_main_fun349(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x348);
  int64_t addr;
  kk_box_t _x_x351;
  kk_box_t _x_x356;
  kk_string_t _x_x357;
  kk_define_string_literal(, _s_x358, 24, "/whitemagic_graph_bridge", _ctx)
  _x_x357 = kk_string_dup(_s_x358, _ctx); /*string*/
  _x_x356 = kk_string_box(_x_x357); /*10000*/
  kk_box_t _x_x359;
  kk_integer_t _x_x360 = kk_integer_dup(kk_whitemagic_dash_koka_src_shm__graph_segment_size, _ctx); /*int*/
  _x_x359 = kk_integer_box(_x_x360, _ctx); /*10001*/
  _x_x351 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__graph_new_main_fun352(_ctx), _x_x356, _x_x359, _ctx); /*10002*/
  addr = kk_int64_unbox(_x_x351, KK_OWNED, _ctx); /*int64*/
  kk_unit_t _x_x361 = kk_Unit;
  kk_function_t _b_x128_165 = kk_whitemagic_dash_koka_src_shm__graph_new_main_fun363(_ctx); /*(i : int) -> int64*/;
  kk_integer_t _b_x129_166 = kk_integer_from_small(0); /*int*/;
  bool _match_x176;
  int64_t _x_x364;
  kk_box_t _x_x365 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__graph_new_main_fun366(_b_x128_165, _ctx), kk_integer_box(_b_x129_166, _ctx), _ctx); /*10001*/
  _x_x364 = kk_int64_unbox(_x_x365, KK_OWNED, _ctx); /*int64*/
  _match_x176 = (addr == _x_x364); /*bool*/
  if (_match_x176) {
    kk_unit_t ___1 = kk_Unit;
    kk_string_t _x_x369;
    kk_define_string_literal(, _s_x370, 40, "{\"error\":\"failed to open shared memory\"}", _ctx)
    _x_x369 = kk_string_dup(_s_x370, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x369, _ctx);
    kk_box_t _x_x371 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__graph_new_main_fun372(_ctx), _ctx); /*10000*/
    kk_unit_unbox(_x_x371);
  }
  else {
    kk_whitemagic_dash_koka_src_shm__graph__header h;
    kk_box_t _x_x374 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__graph_new_main_fun375(_ctx), kk_int64_box(addr, _ctx), _ctx); /*10001*/
    h = kk_whitemagic_dash_koka_src_shm__graph__header_unbox(_x_x374, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_graph/header*/
    kk_function_t _b_x137_168 = kk_whitemagic_dash_koka_src_shm__graph_new_main_fun378(_ctx); /*(header : whitemagic-koka/src/shm_graph/header) -> int*/;
    kk_whitemagic_dash_koka_src_shm__graph__header _b_x138_169 = h; /*whitemagic-koka/src/shm_graph/header*/;
    bool _match_x177;
    kk_integer_t _brw_x179;
    kk_box_t _x_x380 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__graph_new_main_fun381(_b_x137_168, _ctx), kk_whitemagic_dash_koka_src_shm__graph__header_box(_b_x138_169, _ctx), _ctx); /*10001*/
    _brw_x179 = kk_integer_unbox(_x_x380, _ctx); /*int*/
    kk_integer_t _brw_x178 = kk_integer_from_int(1196576840, _ctx); /*int*/;
    bool _brw_x180 = kk_integer_neq_borrow(_brw_x179,_brw_x178,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x179, _ctx);
    kk_integer_drop(_brw_x178, _ctx);
    _match_x177 = _brw_x180; /*bool*/
    if (_match_x177) {
      kk_unit_t ___2 = kk_Unit;
      kk_string_t _x_x384;
      kk_define_string_literal(, _s_x385, 25, "{\"error\":\"invalid magic\"}", _ctx)
      _x_x384 = kk_string_dup(_s_x385, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x384, _ctx);
      kk_integer_t _pat_2_0;
      kk_box_t _x_x386;
      kk_box_t _x_x391;
      kk_integer_t _x_x392 = kk_integer_dup(kk_whitemagic_dash_koka_src_shm__graph_segment_size, _ctx); /*int*/
      _x_x391 = kk_integer_box(_x_x392, _ctx); /*10001*/
      _x_x386 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__graph_new_main_fun387(_ctx), kk_int64_box(addr, _ctx), _x_x391, _ctx); /*10002*/
      _pat_2_0 = kk_integer_unbox(_x_x386, _ctx); /*int*/
      kk_integer_drop(_pat_2_0, _ctx);
      kk_box_t _x_x393 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__graph_new_main_fun394(_ctx), _ctx); /*10000*/
      kk_unit_unbox(_x_x393);
    }
    else {
      kk_unit_t ___3 = kk_Unit;
      kk_string_t _x_x396;
      kk_define_string_literal(, _s_x397, 37, "{\"status\":\"started\",\"connected\":true}", _ctx)
      _x_x396 = kk_string_dup(_s_x397, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x396, _ctx);
      kk_unit_t ___4 = kk_Unit;
      kk_box_t _x_x398 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__graph_new_main_fun399(_ctx), _ctx); /*10000*/
      kk_unit_unbox(_x_x398);
      kk_ssize_t _b_x151_171 = (KK_IZ(0)); /*hnd/ev-index*/;
      kk_box_t _x_x401 = kk_std_core_hnd__open_at1(_b_x151_171, kk_whitemagic_dash_koka_src_shm__graph_new_main_fun402(_ctx), kk_int64_box(addr, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x401);
    }
  }
  return kk_unit_box(_x_x361);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__graph_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_box_t _x_x335;
  kk_function_t _b_x114_162 = kk_whitemagic_dash_koka_src_shm__graph_new_main_fun336(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 967*/;
  kk_std_core_exn__exn _x_x340;
  kk_std_core_hnd__clause1 _x_x341 = kk_std_core_hnd__new_Clause1(kk_whitemagic_dash_koka_src_shm__graph_new_main_fun342(_b_x114_162, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x340 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x341, _ctx); /*exn<10005,10006>*/
  _x_x335 = kk_std_core_exn_exn_fs__handle(_x_x340, kk_whitemagic_dash_koka_src_shm__graph_new_main_fun344(_ctx), kk_whitemagic_dash_koka_src_shm__graph_new_main_fun345(_ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x335); return kk_Unit;
}

// initialization
void kk_whitemagic_dash_koka_src_shm__graph__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_bool__init(_ctx);
  kk_std_core_order__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_vector__init(_ctx);
  kk_std_core_sslice__init(_ctx);
  kk_std_core_maybe__init(_ctx);
  kk_std_core_maybe2__init(_ctx);
  kk_std_core_either__init(_ctx);
  kk_std_core_tuple__init(_ctx);
  kk_std_core_lazy__init(_ctx);
  kk_std_core_show__init(_ctx);
  kk_std_core_debug__init(_ctx);
  kk_std_core_delayed__init(_ctx);
  kk_std_core_console__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_os_readline__init(_ctx);
  kk_std_num_int64__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_list__init(_ctx);
  kk_std_text_parse__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  kk_init_string_literal(kk_whitemagic_dash_koka_src_shm__graph_shm_name, _ctx)
  {
    kk_whitemagic_dash_koka_src_shm__graph_magic_number = kk_integer_from_int(1196576840, _ctx); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__graph_header_size = kk_integer_from_small(64); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__graph_slot_size = kk_integer_from_small(16); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__graph_capacity = kk_integer_from_int(3000000, _ctx); /*int*/
  }
  {
    kk_integer_t y_10001 = kk_integer_mul((kk_integer_from_int(3000000, _ctx)),(kk_integer_from_small(16)),kk_context()); /*int*/;
    kk_whitemagic_dash_koka_src_shm__graph_segment_size = kk_integer_add_small_const(y_10001, 64, _ctx); /*int*/
  }
}

// termination
void kk_whitemagic_dash_koka_src_shm__graph__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__graph_segment_size, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__graph_capacity, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__graph_slot_size, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__graph_header_size, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__graph_magic_number, _ctx);
  kk_std_text_parse__done(_ctx);
  kk_std_core_list__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_num_int64__done(_ctx);
  kk_std_os_readline__done(_ctx);
  kk_std_core__done(_ctx);
  kk_std_core_console__done(_ctx);
  kk_std_core_delayed__done(_ctx);
  kk_std_core_debug__done(_ctx);
  kk_std_core_show__done(_ctx);
  kk_std_core_lazy__done(_ctx);
  kk_std_core_tuple__done(_ctx);
  kk_std_core_either__done(_ctx);
  kk_std_core_maybe2__done(_ctx);
  kk_std_core_maybe__done(_ctx);
  kk_std_core_sslice__done(_ctx);
  kk_std_core_vector__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_order__done(_ctx);
  kk_std_core_bool__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
