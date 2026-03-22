// Koka generated module: whitemagic-koka/src/unified_fast_brain, koka version: 3.2.2, platform: 64-bit
#include "whitemagic_dash_koka_src_unified__fast__brain.h"
#ifndef UNIFIED_FAST_BRAIN_H
#define UNIFIED_FAST_BRAIN_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <kklib.h>

#include <sys/time.h>
static inline double kk_unified_time_ms(kk_context_t* ctx) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}


// --- Ring Buffer Definitions ---
#define RING_MAGIC 0x52494E47
#define RING_HEADER_SIZE 64
#define RING_SLOT_SIZE 256

static inline int64_t kk_unified_ring_open(kk_string_t name, kk_integer_t size, kk_context_t* ctx) {
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

static inline kk_string_t kk_unified_ring_poll(int64_t addr, kk_context_t* ctx) {
    int32_t magic = *(int32_t*)addr;
    if (magic != RING_MAGIC) return kk_string_empty(ctx);
    
    int32_t head = *(int32_t*)(addr + 4);
    int32_t tail = *(int32_t*)(addr + 8);
    int32_t capacity = *(int32_t*)(addr + 12);
    
    if (head == tail) return kk_string_empty(ctx);
    
    intptr_t offset = RING_HEADER_SIZE + (tail * RING_SLOT_SIZE);
    
    int32_t event_type = *(int32_t*)(addr + offset);
    int32_t sender_hash = *(int32_t*)(addr + offset + 4);
    double timestamp = *(double*)(addr + offset + 8);
    const char* payload = (const char*)(addr + offset + 16);
    
    char buf[512];
    snprintf(buf, sizeof(buf), "{\"event_type\":%d,\"sender_hash\":%d,\"timestamp\":%f,\"payload\":%s}", 
             event_type, sender_hash, timestamp, payload);
             
    *(int32_t*)(addr + 8) = (tail + 1) % capacity;
    
    return kk_string_alloc_from_utf8(buf, ctx);
}

// --- Vector Embeddings Definitions ---
#define EMBED_MAGIC 0x454D4244
#define VEC_DIM 384
#define MAX_VECS 100000
#define EMBED_HEADER_SIZE 32
#define EMBED_SLOT_SIZE (36 + (VEC_DIM * 4)) // 36 bytes string + 1536 bytes vec = 1572 bytes

static inline int64_t kk_unified_embed_open(kk_string_t name, kk_context_t* ctx) {
    const char* n = kk_string_cbuf_borrow(name, NULL, ctx);
    int fd = shm_open(n, O_RDWR, 0666);
    kk_string_drop(name, ctx);
    if (fd < 0) return 0;
    
    intptr_t sz = EMBED_HEADER_SIZE + (MAX_VECS * EMBED_SLOT_SIZE);
    void* addr = mmap(NULL, sz, PROT_READ, MAP_SHARED, fd, 0);
    close(fd);
    if (addr == MAP_FAILED) return 0;
    return (int64_t)addr;
}

// Mocking the search for now, to return a random internal node ID we can walk from
static inline kk_integer_t kk_unified_embed_search(int64_t addr, kk_context_t* ctx) {
    if (addr == 0) return kk_integer_from_int(0, ctx);
    int32_t count = *(int32_t*)(addr + 8);
    if (count == 0) return kk_integer_from_int(0, ctx);
    // Just return node 1 for the benchmark/prototype 
    // In reality this calls the AVX2 dot product search over `count` vectors
    return kk_integer_from_int(1, ctx); 
}

// --- Graph Topology Definitions ---
#define GRAPH_MAGIC 0x47525048
#define GRAPH_HEADER_SIZE 64
#define GRAPH_SLOT_SIZE 16

static inline int64_t kk_unified_graph_open(kk_string_t name, kk_integer_t size, kk_context_t* ctx) {
    const char* n = kk_string_cbuf_borrow(name, NULL, ctx);
    intptr_t sz = kk_integer_clamp_ssize_t(size, ctx);
    
    int fd = shm_open(n, O_RDWR, 0666);
    kk_string_drop(name, ctx);
    if (fd < 0) return 0;
    
    void* addr = mmap(NULL, sz, PROT_READ, MAP_SHARED, fd, 0);
    close(fd);
    if (addr == MAP_FAILED) return 0;
    return (int64_t)addr;
}

#pragma GCC push_options
#pragma GCC optimize("O3,unroll-loops")
static inline kk_string_t kk_unified_graph_walk(int64_t addr, kk_integer_t kk_start_id, kk_integer_t kk_hops, kk_context_t* ctx) {
    int32_t start_id = (int32_t)kk_integer_clamp_ssize_t(kk_start_id, ctx);
    int hops = (int)kk_integer_clamp_ssize_t(kk_hops, ctx);
    
    if (addr == 0 || start_id == 0) return kk_string_alloc_from_utf8("{\"nodes_visited\":0,\"edges_traversed\":0}", ctx);
    
    int32_t count = *(int32_t*)(addr + 12);
    if (count == 0) return kk_string_alloc_from_utf8("{\"nodes_visited\":0,\"edges_traversed\":0}", ctx);
    
    int32_t* active_nodes = malloc(1000 * sizeof(int32_t));
    int32_t* next_nodes = malloc(1000 * sizeof(int32_t));
    int active_count = 1;
    active_nodes[0] = start_id;
    
    int traversed_edges = 0;
    int total_nodes_visited = 1;
    
    for (int h = 0; h < hops; h++) {
        int next_count = 0;
        
        for (intptr_t i = 0; i < count; i++) {
            intptr_t offset = GRAPH_HEADER_SIZE + (i * GRAPH_SLOT_SIZE);
            int32_t src = *(int32_t*)(addr + offset);
            int32_t tgt = *(int32_t*)(addr + offset + 4);
            
            for (int a = 0; a < active_count; a++) {
                if (src == active_nodes[a]) {
                    int already_in = 0;
                    for (int n = 0; n < next_count; n++) {
                        if (next_nodes[n] == tgt) { already_in = 1; break; }
                    }
                    if (!already_in && next_count < 1000) {
                        next_nodes[next_count++] = tgt;
                    }
                    traversed_edges++;
                    break;
                }
            }
        }
        
        memcpy(active_nodes, next_nodes, next_count * sizeof(int32_t));
        active_count = next_count;
        total_nodes_visited += active_count;
        
        if (active_count == 0) break;
    }
    
    free(active_nodes);
    free(next_nodes);
    
    char buf[256];
    snprintf(buf, sizeof(buf), "{\"nodes_visited\":%d,\"edges_traversed\":%d}", total_nodes_visited, traversed_edges);
    return kk_string_alloc_from_utf8(buf, ctx);
}
#pragma GCC pop_options

#endif


double kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(kk_context_t* _ctx) { /* () -> float64 */ 
  return kk_unified_time_ms(kk_context());
}

int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_ring_open(kk_string_t name, kk_integer_t size, kk_context_t* _ctx) { /* (name : string, size : int) -> int64 */ 
  return kk_unified_ring_open(name,size,kk_context());
}

kk_string_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_ring_poll(int64_t addr, kk_context_t* _ctx) { /* (addr : int64) -> string */ 
  return kk_unified_ring_poll(addr,kk_context());
}

int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_embed_open(kk_string_t name, kk_context_t* _ctx) { /* (name : string) -> int64 */ 
  return kk_unified_embed_open(name,kk_context());
}

kk_integer_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_embed_search(int64_t addr, kk_context_t* _ctx) { /* (addr : int64) -> int */ 
  return kk_unified_embed_search(addr,kk_context());
}

int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_graph_open(kk_string_t name, kk_integer_t size, kk_context_t* _ctx) { /* (name : string, size : int) -> int64 */ 
  return kk_unified_graph_open(name,size,kk_context());
}

kk_string_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_graph_walk(int64_t addr, kk_integer_t start_id, kk_integer_t hops, kk_context_t* _ctx) { /* (addr : int64, start-id : int, hops : int) -> string */ 
  return kk_unified_graph_walk(addr,start_id,hops,kk_context());
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(kk_context_t* _ctx) { /* () -> console/console () */ 
  fflush(stdout); return kk_Unit;
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_sleep_us(kk_integer_t us, kk_context_t* _ctx) { /* (us : int) -> () */ 
  usleep(kk_integer_clamp32(us, kk_context())); return kk_Unit;
}
kk_declare_string_literal(static, kk_whitemagic_dash_koka_src_unified__fast__brain_ring_name, 22, "/whitemagic_event_ring")

kk_integer_t kk_whitemagic_dash_koka_src_unified__fast__brain_ring_size;
kk_declare_string_literal(static, kk_whitemagic_dash_koka_src_unified__fast__brain_embed_name, 29, "/whitemagic_embed_bridge_real")
kk_declare_string_literal(static, kk_whitemagic_dash_koka_src_unified__fast__brain_graph_name, 24, "/whitemagic_graph_bridge")

kk_integer_t kk_whitemagic_dash_koka_src_unified__fast__brain_graph_size;
 
// runtime tag for the effect `:prat-route`

kk_std_core_hnd__htag kk_whitemagic_dash_koka_src_unified__fast__brain_prat_route_fs__tag;
 
// handler for the effect `:prat-route`

kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_prat_route_fs__handle(kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : prat-route<e,b>, ret : (res : a) -> e b, action : () -> <prat-route|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x554 = kk_std_core_hnd__htag_dup(kk_whitemagic_dash_koka_src_unified__fast__brain_prat_route_fs__tag, _ctx); /*hnd/htag<whitemagic-koka/src/unified_fast_brain/prat-route>*/
  return kk_std_core_hnd__hhandle(_x_x554, kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_box(hnd, _ctx), ret, action, _ctx);
}
 
// PRAT Tool Router via Koka Effect matching

kk_string_t kk_whitemagic_dash_koka_src_unified__fast__brain_route_to_gana(kk_string_t tool, kk_context_t* _ctx) { /* (tool : string) -> string */ 
  if (kk_string_cmp_cstr_borrow(tool, "session_bootstrap", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x560, 9, "gana_horn", _ctx)
    return kk_string_dup(_s_x560, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "create_memory", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x561, 9, "gana_neck", _ctx)
    return kk_string_dup(_s_x561, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "update_memory", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x562, 9, "gana_neck", _ctx)
    return kk_string_dup(_s_x562, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "search_memories", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x563, 21, "gana_winnowing_basket", _ctx)
    return kk_string_dup(_s_x563, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "vector_search", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x564, 21, "gana_winnowing_basket", _ctx)
    return kk_string_dup(_s_x564, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "hybrid_recall", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x565, 21, "gana_winnowing_basket", _ctx)
    return kk_string_dup(_s_x565, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "graph_walk", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x566, 21, "gana_winnowing_basket", _ctx)
    return kk_string_dup(_s_x566, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "health_report", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x567, 9, "gana_root", _ctx)
    return kk_string_dup(_s_x567, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "gnosis", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x568, 10, "gana_ghost", _ctx)
    return kk_string_dup(_s_x568, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "dream", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x569, 14, "gana_abundance", _ctx)
    return kk_string_dup(_s_x569, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "ensemble", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x570, 16, "gana_three_stars", _ctx)
    return kk_string_dup(_s_x570, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "galactic_dashboard", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x571, 9, "gana_void", _ctx)
    return kk_string_dup(_s_x571, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "check", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x572, 9, "gana_root", _ctx)
    return kk_string_dup(_s_x572, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "manifest", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x573, 10, "gana_ghost", _ctx)
    return kk_string_dup(_s_x573, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "capabilities", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x574, 10, "gana_ghost", _ctx)
    return kk_string_dup(_s_x574, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(tool, "recall", _ctx) == 0) {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x575, 21, "gana_winnowing_basket", _ctx)
    return kk_string_dup(_s_x575, _ctx);
  }
  {
    kk_string_drop(tool, _ctx);
    kk_define_string_literal(, _s_x576, 12, "gana_unknown", _ctx)
    return kk_string_dup(_s_x576, _ctx);
  }
}
 
// A basic handler for the PRAT route effect that routes to the correct Gana


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun577__t {
  struct kk_function_s _base;
};
static kk_string_t kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun577(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_string_t x1, kk_string_t x2, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_with_prat_router_fun577(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun577, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun579__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun579(kk_function_t _fself, kk_box_t _b_x22, kk_box_t _b_x23, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_with_prat_router_fun579(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun579, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun579(kk_function_t _fself, kk_box_t _b_x22, kk_box_t _b_x23, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t tool_34 = kk_string_unbox(_b_x22); /*string*/;
  kk_string_t args_35 = kk_string_unbox(_b_x23); /*string*/;
  kk_string_drop(args_35, _ctx);
  kk_string_t gana;
  kk_string_t _x_x580 = kk_string_dup(tool_34, _ctx); /*string*/
  gana = kk_whitemagic_dash_koka_src_unified__fast__brain_route_to_gana(_x_x580, _ctx); /*string*/
  kk_string_t _x_x581;
  kk_string_t _x_x582;
  kk_define_string_literal(, _s_x583, 28, "{\"status\":\"routed\", \"gana\":\"", _ctx)
  _x_x582 = kk_string_dup(_s_x583, _ctx); /*string*/
  kk_string_t _x_x584;
  kk_string_t _x_x585;
  kk_string_t _x_x586;
  kk_define_string_literal(, _s_x587, 11, "\", \"tool\":\"", _ctx)
  _x_x586 = kk_string_dup(_s_x587, _ctx); /*string*/
  kk_string_t _x_x588;
  kk_string_t _x_x589;
  kk_define_string_literal(, _s_x590, 2, "\"}", _ctx)
  _x_x589 = kk_string_dup(_s_x590, _ctx); /*string*/
  _x_x588 = kk_std_core_types__lp__plus__plus__rp_(tool_34, _x_x589, _ctx); /*string*/
  _x_x585 = kk_std_core_types__lp__plus__plus__rp_(_x_x586, _x_x588, _ctx); /*string*/
  _x_x584 = kk_std_core_types__lp__plus__plus__rp_(gana, _x_x585, _ctx); /*string*/
  _x_x581 = kk_std_core_types__lp__plus__plus__rp_(_x_x582, _x_x584, _ctx); /*string*/
  return kk_string_box(_x_x581);
}
static kk_string_t kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun577(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_string_t x1, kk_string_t x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x578 = kk_std_core_hnd_under2(ev, kk_whitemagic_dash_koka_src_unified__fast__brain_new_with_prat_router_fun579(_ctx), kk_string_box(x1), kk_string_box(x2), _ctx); /*10002*/
  return kk_string_unbox(_x_x578);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun593__t {
  struct kk_function_s _base;
  kk_function_t _b_x24_29;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun593(kk_function_t _fself, int32_t _b_x25, kk_std_core_hnd__ev _b_x26, kk_box_t _b_x27, kk_box_t _b_x28, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_with_prat_router_fun593(kk_function_t _b_x24_29, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun593__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun593__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun593, kk_context());
  _self->_b_x24_29 = _b_x24_29;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun593(kk_function_t _fself, int32_t _b_x25, kk_std_core_hnd__ev _b_x26, kk_box_t _b_x27, kk_box_t _b_x28, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun593__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun593__t*, _fself, _ctx);
  kk_function_t _b_x24_29 = _self->_b_x24_29; /* (m : hnd/marker<530,529>, ev : hnd/ev<whitemagic-koka/src/unified_fast_brain/prat-route>, x1 : string, x2 : string) -> 530 string */
  kk_drop_match(_self, {kk_function_dup(_b_x24_29, _ctx);}, {}, _ctx)
  kk_string_t _x_x594;
  kk_string_t _x_x595 = kk_string_unbox(_b_x27); /*string*/
  kk_string_t _x_x596 = kk_string_unbox(_b_x28); /*string*/
  _x_x594 = kk_function_call(kk_string_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_string_t, kk_string_t, kk_context_t*), _b_x24_29, (_b_x24_29, _b_x25, _b_x26, _x_x595, _x_x596, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x594);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun597__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun597(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_with_prat_router_fun597(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun597, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router_fun597(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}

kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <prat-route|e> a) -> e a */ 
  kk_function_t _b_x24_29 = kk_whitemagic_dash_koka_src_unified__fast__brain_new_with_prat_router_fun577(_ctx); /*(m : hnd/marker<530,529>, ev : hnd/ev<whitemagic-koka/src/unified_fast_brain/prat-route>, x1 : string, x2 : string) -> 530 string*/;
  kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route _x_x591;
  kk_std_core_hnd__clause2 _x_x592 = kk_std_core_hnd__new_Clause2(kk_whitemagic_dash_koka_src_unified__fast__brain_new_with_prat_router_fun593(_b_x24_29, _ctx), _ctx); /*hnd/clause2<10021,10022,10023,10024,10025,10026>*/
  _x_x591 = kk_whitemagic_dash_koka_src_unified__fast__brain__new_Hnd_prat_route(kk_reuse_null, 0, kk_integer_from_small(1), _x_x592, _ctx); /*whitemagic-koka/src/unified_fast_brain/prat-route<7,8>*/
  return kk_whitemagic_dash_koka_src_unified__fast__brain_prat_route_fs__handle(_x_x591, kk_whitemagic_dash_koka_src_unified__fast__brain_new_with_prat_router_fun597(_ctx), action, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun599__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun599(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10124_fun599(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun599, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun599(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x600 = kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(_ctx); /*float64*/
  return kk_double_box(_x_x600, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun603__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun603(kk_function_t _fself, kk_box_t _b_x41, kk_box_t _b_x42, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10124_fun603(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun603, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun603(kk_function_t _fself, kk_box_t _b_x41, kk_box_t _b_x42, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x604;
  double _x_x605 = kk_double_unbox(_b_x41, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x606 = kk_std_core_types__optional_unbox(_b_x42, KK_OWNED, _ctx); /*? int*/
  _x_x604 = kk_std_num_float64_show(_x_x605, _x_x606, _ctx); /*string*/
  return kk_string_box(_x_x604);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun620__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun620(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10124_fun620(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun620, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124_fun620(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x621 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x621);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124(double start_time, kk_string_t res, kk_context_t* _ctx) { /* (start-time : float64, res : string) -> <prat-route,console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  double end_time_0;
  kk_box_t _x_x598 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10124_fun599(_ctx), _ctx); /*10000*/
  end_time_0 = kk_double_unbox(_x_x598, KK_OWNED, _ctx); /*float64*/
  double _x_x1_5_10086 = (end_time_0 - start_time); /*float64*/;
  kk_string_t dur_0;
  kk_string_t _x_x601;
  kk_box_t _x_x602 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10124_fun603(_ctx), kk_double_box(_x_x1_5_10086, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
  _x_x601 = kk_string_unbox(_x_x602); /*string*/
  kk_string_t _x_x607;
  kk_define_string_literal(, _s_x608, 2, "ms", _ctx)
  _x_x607 = kk_string_dup(_s_x608, _ctx); /*string*/
  dur_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x601, _x_x607, _ctx); /*string*/
  kk_unit_t ___0 = kk_Unit;
  kk_string_t _x_x609;
  kk_string_t _x_x610;
  kk_define_string_literal(, _s_x611, 36, "{\"status\":\"prat_routed\", \"latency\":\"", _ctx)
  _x_x610 = kk_string_dup(_s_x611, _ctx); /*string*/
  kk_string_t _x_x612;
  kk_string_t _x_x613;
  kk_string_t _x_x614;
  kk_define_string_literal(, _s_x615, 12, "\", \"result\":", _ctx)
  _x_x614 = kk_string_dup(_s_x615, _ctx); /*string*/
  kk_string_t _x_x616;
  kk_string_t _x_x617;
  kk_define_string_literal(, _s_x618, 1, "}", _ctx)
  _x_x617 = kk_string_dup(_s_x618, _ctx); /*string*/
  _x_x616 = kk_std_core_types__lp__plus__plus__rp_(res, _x_x617, _ctx); /*string*/
  _x_x613 = kk_std_core_types__lp__plus__plus__rp_(_x_x614, _x_x616, _ctx); /*string*/
  _x_x612 = kk_std_core_types__lp__plus__plus__rp_(dur_0, _x_x613, _ctx); /*string*/
  _x_x609 = kk_std_core_types__lp__plus__plus__rp_(_x_x610, _x_x612, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x609, _ctx);
  kk_box_t _x_x619 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10124_fun620(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x619); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun623__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun623(kk_function_t _fself, kk_box_t _b_x62, kk_box_t _b_x63, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10125_fun623(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun623, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun623(kk_function_t _fself, kk_box_t _b_x62, kk_box_t _b_x63, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10140 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/unified_fast_brain/prat-route>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x624 = kk_std_core_hnd__as_Ev(evx_10140, _ctx);
    kk_box_t _box_x48 = _con_x624->hnd;
    int32_t m = _con_x624->marker;
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route h = kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_unbox(_box_x48, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_dup(h, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _con_x625 = kk_whitemagic_dash_koka_src_unified__fast__brain__as_Hnd_prat_route(h, _ctx);
      kk_integer_t _pat_0 = _con_x625->_cfc;
      kk_std_core_hnd__clause2 _fun_dispatch_tool = _con_x625->_fun_dispatch_tool;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_dispatch_tool, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x53 = _fun_dispatch_tool.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x53, (_fun_unbox_x53, m, evx_10140, _b_x62, _b_x63, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun630__t {
  struct kk_function_s _base;
  double start_time;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun630(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10125_fun630(double start_time, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun630__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun630__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun630, kk_context());
  _self->start_time = start_time;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun630(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun630__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125_fun630__t*, _fself, _ctx);
  double start_time = _self->start_time; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(start_time, _ctx);}, {}, _ctx)
  kk_string_t res_73 = kk_string_unbox(_b_x71); /*string*/;
  kk_unit_t _x_x631 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124(start_time, res_73, _ctx);
  return kk_unit_box(_x_x631);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125(double start_time, kk_string_t _c_x10007, kk_context_t* _ctx) { /* (start-time : float64, string) -> () */ 
  kk_ssize_t _b_x58_64 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_string_t x_10138;
  kk_box_t _x_x622;
  kk_box_t _x_x626;
  kk_string_t _x_x627;
  kk_define_string_literal(, _s_x628, 2, "{}", _ctx)
  _x_x627 = kk_string_dup(_s_x628, _ctx); /*string*/
  _x_x626 = kk_string_box(_x_x627); /*10001*/
  _x_x622 = kk_std_core_hnd__open_at2(_b_x58_64, kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10125_fun623(_ctx), kk_string_box(_c_x10007), _x_x626, _ctx); /*10002*/
  x_10138 = kk_string_unbox(_x_x622); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10138, _ctx);
    kk_box_t _x_x629 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10125_fun630(start_time, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x629); return kk_Unit;
  }
  {
    kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124(start_time, x_10138, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun633__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun633(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10126_fun633(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun633, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun633(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x634 = kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(_ctx); /*float64*/
  return kk_double_box(_x_x634, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun637__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun637(kk_function_t _fself, kk_box_t _b_x79, kk_box_t _b_x80, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10126_fun637(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun637, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun637(kk_function_t _fself, kk_box_t _b_x79, kk_box_t _b_x80, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x638;
  double _x_x639 = kk_double_unbox(_b_x79, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x640 = kk_std_core_types__optional_unbox(_b_x80, KK_OWNED, _ctx); /*? int*/
  _x_x638 = kk_std_num_float64_show(_x_x639, _x_x640, _ctx); /*string*/
  return kk_string_box(_x_x638);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun654__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun654(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10126_fun654(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun654, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126_fun654(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x655 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x655);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126(double start_time, kk_string_t res_0, kk_context_t* _ctx) { /* (start-time : float64, res@0 : string) -> <prat-route,console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  double end_time_0_0;
  kk_box_t _x_x632 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10126_fun633(_ctx), _ctx); /*10000*/
  end_time_0_0 = kk_double_unbox(_x_x632, KK_OWNED, _ctx); /*float64*/
  double _x_x1_8_10092 = (end_time_0_0 - start_time); /*float64*/;
  kk_string_t dur_0_0;
  kk_string_t _x_x635;
  kk_box_t _x_x636 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10126_fun637(_ctx), kk_double_box(_x_x1_8_10092, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
  _x_x635 = kk_string_unbox(_x_x636); /*string*/
  kk_string_t _x_x641;
  kk_define_string_literal(, _s_x642, 2, "ms", _ctx)
  _x_x641 = kk_string_dup(_s_x642, _ctx); /*string*/
  dur_0_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x635, _x_x641, _ctx); /*string*/
  kk_unit_t ___0_0 = kk_Unit;
  kk_string_t _x_x643;
  kk_string_t _x_x644;
  kk_define_string_literal(, _s_x645, 36, "{\"status\":\"prat_routed\", \"latency\":\"", _ctx)
  _x_x644 = kk_string_dup(_s_x645, _ctx); /*string*/
  kk_string_t _x_x646;
  kk_string_t _x_x647;
  kk_string_t _x_x648;
  kk_define_string_literal(, _s_x649, 12, "\", \"result\":", _ctx)
  _x_x648 = kk_string_dup(_s_x649, _ctx); /*string*/
  kk_string_t _x_x650;
  kk_string_t _x_x651;
  kk_define_string_literal(, _s_x652, 1, "}", _ctx)
  _x_x651 = kk_string_dup(_s_x652, _ctx); /*string*/
  _x_x650 = kk_std_core_types__lp__plus__plus__rp_(res_0, _x_x651, _ctx); /*string*/
  _x_x647 = kk_std_core_types__lp__plus__plus__rp_(_x_x648, _x_x650, _ctx); /*string*/
  _x_x646 = kk_std_core_types__lp__plus__plus__rp_(dur_0_0, _x_x647, _ctx); /*string*/
  _x_x643 = kk_std_core_types__lp__plus__plus__rp_(_x_x644, _x_x646, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x643, _ctx);
  kk_box_t _x_x653 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10126_fun654(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x653); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun657__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun657(kk_function_t _fself, kk_box_t _b_x100, kk_box_t _b_x101, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10127_fun657(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun657, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun657(kk_function_t _fself, kk_box_t _b_x100, kk_box_t _b_x101, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10146 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/unified_fast_brain/prat-route>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x658 = kk_std_core_hnd__as_Ev(evx_10146, _ctx);
    kk_box_t _box_x86 = _con_x658->hnd;
    int32_t m = _con_x658->marker;
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route h = kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_unbox(_box_x86, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_dup(h, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _con_x659 = kk_whitemagic_dash_koka_src_unified__fast__brain__as_Hnd_prat_route(h, _ctx);
      kk_integer_t _pat_0 = _con_x659->_cfc;
      kk_std_core_hnd__clause2 _fun_dispatch_tool = _con_x659->_fun_dispatch_tool;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_dispatch_tool, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x91 = _fun_dispatch_tool.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x91, (_fun_unbox_x91, m, evx_10146, _b_x100, _b_x101, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun664__t {
  struct kk_function_s _base;
  double start_time;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun664(kk_function_t _fself, kk_box_t _b_x109, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10127_fun664(double start_time, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun664__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun664__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun664, kk_context());
  _self->start_time = start_time;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun664(kk_function_t _fself, kk_box_t _b_x109, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun664__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127_fun664__t*, _fself, _ctx);
  double start_time = _self->start_time; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(start_time, _ctx);}, {}, _ctx)
  kk_string_t res_0_111 = kk_string_unbox(_b_x109); /*string*/;
  kk_unit_t _x_x665 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126(start_time, res_0_111, _ctx);
  return kk_unit_box(_x_x665);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127(double start_time, kk_string_t _c_x10012, kk_context_t* _ctx) { /* (start-time : float64, string) -> () */ 
  kk_ssize_t _b_x96_102 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_string_t x_10144;
  kk_box_t _x_x656;
  kk_box_t _x_x660;
  kk_string_t _x_x661;
  kk_define_string_literal(, _s_x662, 2, "{}", _ctx)
  _x_x661 = kk_string_dup(_s_x662, _ctx); /*string*/
  _x_x660 = kk_string_box(_x_x661); /*10001*/
  _x_x656 = kk_std_core_hnd__open_at2(_b_x96_102, kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10127_fun657(_ctx), kk_string_box(_c_x10012), _x_x660, _ctx); /*10002*/
  x_10144 = kk_string_unbox(_x_x656); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10144, _ctx);
    kk_box_t _x_x663 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10127_fun664(start_time, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x663); return kk_Unit;
  }
  {
    kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126(start_time, x_10144, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun667__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun667(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10128_fun667(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun667, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun667(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x668 = kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(_ctx); /*float64*/
  return kk_double_box(_x_x668, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun671__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun671(kk_function_t _fself, kk_box_t _b_x117, kk_box_t _b_x118, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10128_fun671(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun671, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun671(kk_function_t _fself, kk_box_t _b_x117, kk_box_t _b_x118, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x672;
  double _x_x673 = kk_double_unbox(_b_x117, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x674 = kk_std_core_types__optional_unbox(_b_x118, KK_OWNED, _ctx); /*? int*/
  _x_x672 = kk_std_num_float64_show(_x_x673, _x_x674, _ctx); /*string*/
  return kk_string_box(_x_x672);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun688__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun688(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10128_fun688(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun688, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128_fun688(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x689 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x689);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128(double start_time, kk_string_t res_1, kk_context_t* _ctx) { /* (start-time : float64, res@1 : string) -> <prat-route,console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  double end_time_0_1;
  kk_box_t _x_x666 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10128_fun667(_ctx), _ctx); /*10000*/
  end_time_0_1 = kk_double_unbox(_x_x666, KK_OWNED, _ctx); /*float64*/
  double _x_x1_11_10098 = (end_time_0_1 - start_time); /*float64*/;
  kk_string_t dur_0_1;
  kk_string_t _x_x669;
  kk_box_t _x_x670 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10128_fun671(_ctx), kk_double_box(_x_x1_11_10098, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
  _x_x669 = kk_string_unbox(_x_x670); /*string*/
  kk_string_t _x_x675;
  kk_define_string_literal(, _s_x676, 2, "ms", _ctx)
  _x_x675 = kk_string_dup(_s_x676, _ctx); /*string*/
  dur_0_1 = kk_std_core_types__lp__plus__plus__rp_(_x_x669, _x_x675, _ctx); /*string*/
  kk_unit_t ___0_1 = kk_Unit;
  kk_string_t _x_x677;
  kk_string_t _x_x678;
  kk_define_string_literal(, _s_x679, 36, "{\"status\":\"prat_routed\", \"latency\":\"", _ctx)
  _x_x678 = kk_string_dup(_s_x679, _ctx); /*string*/
  kk_string_t _x_x680;
  kk_string_t _x_x681;
  kk_string_t _x_x682;
  kk_define_string_literal(, _s_x683, 12, "\", \"result\":", _ctx)
  _x_x682 = kk_string_dup(_s_x683, _ctx); /*string*/
  kk_string_t _x_x684;
  kk_string_t _x_x685;
  kk_define_string_literal(, _s_x686, 1, "}", _ctx)
  _x_x685 = kk_string_dup(_s_x686, _ctx); /*string*/
  _x_x684 = kk_std_core_types__lp__plus__plus__rp_(res_1, _x_x685, _ctx); /*string*/
  _x_x681 = kk_std_core_types__lp__plus__plus__rp_(_x_x682, _x_x684, _ctx); /*string*/
  _x_x680 = kk_std_core_types__lp__plus__plus__rp_(dur_0_1, _x_x681, _ctx); /*string*/
  _x_x677 = kk_std_core_types__lp__plus__plus__rp_(_x_x678, _x_x680, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x677, _ctx);
  kk_box_t _x_x687 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10128_fun688(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x687); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun691__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun691(kk_function_t _fself, kk_box_t _b_x138, kk_box_t _b_x139, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10129_fun691(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun691, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun691(kk_function_t _fself, kk_box_t _b_x138, kk_box_t _b_x139, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10152 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/unified_fast_brain/prat-route>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x692 = kk_std_core_hnd__as_Ev(evx_10152, _ctx);
    kk_box_t _box_x124 = _con_x692->hnd;
    int32_t m = _con_x692->marker;
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route h = kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_unbox(_box_x124, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_dup(h, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _con_x693 = kk_whitemagic_dash_koka_src_unified__fast__brain__as_Hnd_prat_route(h, _ctx);
      kk_integer_t _pat_0 = _con_x693->_cfc;
      kk_std_core_hnd__clause2 _fun_dispatch_tool = _con_x693->_fun_dispatch_tool;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_dispatch_tool, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x129 = _fun_dispatch_tool.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x129, (_fun_unbox_x129, m, evx_10152, _b_x138, _b_x139, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun698__t {
  struct kk_function_s _base;
  double start_time;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun698(kk_function_t _fself, kk_box_t _b_x147, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10129_fun698(double start_time, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun698__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun698__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun698, kk_context());
  _self->start_time = start_time;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun698(kk_function_t _fself, kk_box_t _b_x147, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun698__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129_fun698__t*, _fself, _ctx);
  double start_time = _self->start_time; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(start_time, _ctx);}, {}, _ctx)
  kk_string_t res_1_149 = kk_string_unbox(_b_x147); /*string*/;
  kk_unit_t _x_x699 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128(start_time, res_1_149, _ctx);
  return kk_unit_box(_x_x699);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129(double start_time, kk_string_t _c_x10017, kk_context_t* _ctx) { /* (start-time : float64, string) -> () */ 
  kk_ssize_t _b_x134_140 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_string_t x_10150;
  kk_box_t _x_x690;
  kk_box_t _x_x694;
  kk_string_t _x_x695;
  kk_define_string_literal(, _s_x696, 2, "{}", _ctx)
  _x_x695 = kk_string_dup(_s_x696, _ctx); /*string*/
  _x_x694 = kk_string_box(_x_x695); /*10001*/
  _x_x690 = kk_std_core_hnd__open_at2(_b_x134_140, kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10129_fun691(_ctx), kk_string_box(_c_x10017), _x_x694, _ctx); /*10002*/
  x_10150 = kk_string_unbox(_x_x690); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10150, _ctx);
    kk_box_t _x_x697 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_handle_event_10129_fun698(start_time, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x697); return kk_Unit;
  }
  {
    kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128(start_time, x_10150, _ctx); return kk_Unit;
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun701__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun701(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun701(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun701, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun701(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x702 = kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(_ctx); /*float64*/
  return kk_double_box(_x_x702, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun707__t {
  struct kk_function_s _base;
};
static int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun707(kk_function_t _fself, kk_integer_t _x1_x706, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun707(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun707, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun707(kk_function_t _fself, kk_integer_t _x1_x706, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_int64_int64(_x1_x706, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun710__t {
  struct kk_function_s _base;
  kk_function_t _b_x152_329;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun710(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun710(kk_function_t _b_x152_329, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun710__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun710__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun710, kk_context());
  _self->_b_x152_329 = _b_x152_329;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun710(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun710__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun710__t*, _fself, _ctx);
  kk_function_t _b_x152_329 = _self->_b_x152_329; /* (i : int) -> int64 */
  kk_drop_match(_self, {kk_function_dup(_b_x152_329, _ctx);}, {}, _ctx)
  int64_t _x_x711;
  kk_integer_t _x_x712 = kk_integer_unbox(_b_x154, _ctx); /*int*/
  _x_x711 = kk_function_call(int64_t, (kk_function_t, kk_integer_t, kk_context_t*), _b_x152_329, (_b_x152_329, _x_x712, _ctx), _ctx); /*int64*/
  return kk_int64_box(_x_x711, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun714__t {
  struct kk_function_s _base;
};
static int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun714(kk_function_t _fself, kk_integer_t _x1_x713, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun714(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun714, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun714(kk_function_t _fself, kk_integer_t _x1_x713, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_int64_int64(_x1_x713, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun717__t {
  struct kk_function_s _base;
  kk_function_t _b_x155_331;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun717(kk_function_t _fself, kk_box_t _b_x157, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun717(kk_function_t _b_x155_331, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun717__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun717__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun717, kk_context());
  _self->_b_x155_331 = _b_x155_331;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun717(kk_function_t _fself, kk_box_t _b_x157, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun717__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun717__t*, _fself, _ctx);
  kk_function_t _b_x155_331 = _self->_b_x155_331; /* (i : int) -> int64 */
  kk_drop_match(_self, {kk_function_dup(_b_x155_331, _ctx);}, {}, _ctx)
  int64_t _x_x718;
  kk_integer_t _x_x719 = kk_integer_unbox(_b_x157, _ctx); /*int*/
  _x_x718 = kk_function_call(int64_t, (kk_function_t, kk_integer_t, kk_context_t*), _b_x155_331, (_b_x155_331, _x_x719, _ctx), _ctx); /*int64*/
  return kk_int64_box(_x_x718, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun721__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun721(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun721(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun721, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun721(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x722;
  int64_t _x_x723 = kk_int64_unbox(_b_x160, KK_OWNED, _ctx); /*int64*/
  _x_x722 = kk_whitemagic_dash_koka_src_unified__fast__brain_shm_embed_search(_x_x723, _ctx); /*int*/
  return kk_integer_box(_x_x722, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun725__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun725(kk_function_t _fself, kk_box_t _b_x167, kk_box_t _b_x168, kk_box_t _b_x169, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun725(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun725, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun725(kk_function_t _fself, kk_box_t _b_x167, kk_box_t _b_x168, kk_box_t _b_x169, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x726;
  int64_t _x_x727 = kk_int64_unbox(_b_x167, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x728 = kk_integer_unbox(_b_x168, _ctx); /*int*/
  kk_integer_t _x_x729 = kk_integer_unbox(_b_x169, _ctx); /*int*/
  _x_x726 = kk_whitemagic_dash_koka_src_unified__fast__brain_shm_graph_walk(_x_x727, _x_x728, _x_x729, _ctx); /*string*/
  return kk_string_box(_x_x726);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun731__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun731(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun731(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun731, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun731(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x732 = kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(_ctx); /*float64*/
  return kk_double_box(_x_x732, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun735__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun735(kk_function_t _fself, kk_box_t _b_x179, kk_box_t _b_x180, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun735(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun735, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun735(kk_function_t _fself, kk_box_t _b_x179, kk_box_t _b_x180, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x736;
  double _x_x737 = kk_double_unbox(_b_x179, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x738 = kk_std_core_types__optional_unbox(_b_x180, KK_OWNED, _ctx); /*? int*/
  _x_x736 = kk_std_num_float64_show(_x_x737, _x_x738, _ctx); /*string*/
  return kk_string_box(_x_x736);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun756__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun756(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun756(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun756, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun756(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x757 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x757);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun770__t {
  struct kk_function_s _base;
  double start_time;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun770(kk_function_t _fself, kk_box_t _b_x186, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun770(double start_time, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun770__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun770__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun770, kk_context());
  _self->start_time = start_time;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun770(kk_function_t _fself, kk_box_t _b_x186, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun770__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun770__t*, _fself, _ctx);
  double start_time = _self->start_time; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(start_time, _ctx);}, {}, _ctx)
  kk_string_t _c_x10007_346 = kk_string_unbox(_b_x186); /*string*/;
  kk_unit_t _x_x771 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125(start_time, _c_x10007_346, _ctx);
  return kk_unit_box(_x_x771);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun773__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun773(kk_function_t _fself, kk_box_t _b_x201, kk_box_t _b_x202, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun773(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun773, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun773(kk_function_t _fself, kk_box_t _b_x201, kk_box_t _b_x202, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10162 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/unified_fast_brain/prat-route>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x774 = kk_std_core_hnd__as_Ev(evx_10162, _ctx);
    kk_box_t _box_x187 = _con_x774->hnd;
    int32_t m = _con_x774->marker;
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route h = kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_unbox(_box_x187, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_dup(h, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _con_x775 = kk_whitemagic_dash_koka_src_unified__fast__brain__as_Hnd_prat_route(h, _ctx);
      kk_integer_t _pat_0_1 = _con_x775->_cfc;
      kk_std_core_hnd__clause2 _fun_dispatch_tool = _con_x775->_fun_dispatch_tool;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_dispatch_tool, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x192 = _fun_dispatch_tool.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x192, (_fun_unbox_x192, m, evx_10162, _b_x201, _b_x202, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun780__t {
  struct kk_function_s _base;
  double start_time;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun780(kk_function_t _fself, kk_box_t _b_x210, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun780(double start_time, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun780__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun780__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun780, kk_context());
  _self->start_time = start_time;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun780(kk_function_t _fself, kk_box_t _b_x210, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun780__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun780__t*, _fself, _ctx);
  double start_time = _self->start_time; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(start_time, _ctx);}, {}, _ctx)
  kk_string_t res_347 = kk_string_unbox(_b_x210); /*string*/;
  kk_unit_t _x_x781 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124(start_time, res_347, _ctx);
  return kk_unit_box(_x_x781);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun783__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun783(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun783(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun783, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun783(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x784 = kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(_ctx); /*float64*/
  return kk_double_box(_x_x784, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun787__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun787(kk_function_t _fself, kk_box_t _b_x216, kk_box_t _b_x217, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun787(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun787, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun787(kk_function_t _fself, kk_box_t _b_x216, kk_box_t _b_x217, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x788;
  double _x_x789 = kk_double_unbox(_b_x216, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x790 = kk_std_core_types__optional_unbox(_b_x217, KK_OWNED, _ctx); /*? int*/
  _x_x788 = kk_std_num_float64_show(_x_x789, _x_x790, _ctx); /*string*/
  return kk_string_box(_x_x788);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun804__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun804(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun804(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun804, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun804(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x805 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x805);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun807__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun807(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun807(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun807, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun807(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x808 = kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(_ctx); /*float64*/
  return kk_double_box(_x_x808, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun811__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun811(kk_function_t _fself, kk_box_t _b_x227, kk_box_t _b_x228, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun811(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun811, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun811(kk_function_t _fself, kk_box_t _b_x227, kk_box_t _b_x228, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x812;
  double _x_x813 = kk_double_unbox(_b_x227, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x814 = kk_std_core_types__optional_unbox(_b_x228, KK_OWNED, _ctx); /*? int*/
  _x_x812 = kk_std_num_float64_show(_x_x813, _x_x814, _ctx); /*string*/
  return kk_string_box(_x_x812);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun828__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun828(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun828(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun828, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun828(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x829 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x829);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun842__t {
  struct kk_function_s _base;
  double start_time;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun842(kk_function_t _fself, kk_box_t _b_x234, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun842(double start_time, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun842__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun842__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun842, kk_context());
  _self->start_time = start_time;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun842(kk_function_t _fself, kk_box_t _b_x234, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun842__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun842__t*, _fself, _ctx);
  double start_time = _self->start_time; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(start_time, _ctx);}, {}, _ctx)
  kk_string_t _c_x10012_348 = kk_string_unbox(_b_x234); /*string*/;
  kk_unit_t _x_x843 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127(start_time, _c_x10012_348, _ctx);
  return kk_unit_box(_x_x843);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun845__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun845(kk_function_t _fself, kk_box_t _b_x249, kk_box_t _b_x250, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun845(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun845, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun845(kk_function_t _fself, kk_box_t _b_x249, kk_box_t _b_x250, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_0_10172 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/unified_fast_brain/prat-route>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x846 = kk_std_core_hnd__as_Ev(evx_0_10172, _ctx);
    kk_box_t _box_x235 = _con_x846->hnd;
    int32_t m_0 = _con_x846->marker;
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route h_0 = kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_unbox(_box_x235, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_dup(h_0, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _con_x847 = kk_whitemagic_dash_koka_src_unified__fast__brain__as_Hnd_prat_route(h_0, _ctx);
      kk_integer_t _pat_0_4 = _con_x847->_cfc;
      kk_std_core_hnd__clause2 _fun_dispatch_tool_0 = _con_x847->_fun_dispatch_tool;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_integer_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_dispatch_tool_0, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x240 = _fun_dispatch_tool_0.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x240, (_fun_unbox_x240, m_0, evx_0_10172, _b_x249, _b_x250, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun852__t {
  struct kk_function_s _base;
  double start_time;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun852(kk_function_t _fself, kk_box_t _b_x258, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun852(double start_time, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun852__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun852__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun852, kk_context());
  _self->start_time = start_time;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun852(kk_function_t _fself, kk_box_t _b_x258, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun852__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun852__t*, _fself, _ctx);
  double start_time = _self->start_time; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(start_time, _ctx);}, {}, _ctx)
  kk_string_t res_0_0_349 = kk_string_unbox(_b_x258); /*string*/;
  kk_unit_t _x_x853 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126(start_time, res_0_0_349, _ctx);
  return kk_unit_box(_x_x853);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun855__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun855(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun855(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun855, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun855(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x856 = kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(_ctx); /*float64*/
  return kk_double_box(_x_x856, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun859__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun859(kk_function_t _fself, kk_box_t _b_x264, kk_box_t _b_x265, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun859(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun859, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun859(kk_function_t _fself, kk_box_t _b_x264, kk_box_t _b_x265, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x860;
  double _x_x861 = kk_double_unbox(_b_x264, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x862 = kk_std_core_types__optional_unbox(_b_x265, KK_OWNED, _ctx); /*? int*/
  _x_x860 = kk_std_num_float64_show(_x_x861, _x_x862, _ctx); /*string*/
  return kk_string_box(_x_x860);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun876__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun876(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun876(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun876, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun876(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x877 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x877);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun879__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun879(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun879(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun879, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun879(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x880 = kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(_ctx); /*float64*/
  return kk_double_box(_x_x880, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun883__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun883(kk_function_t _fself, kk_box_t _b_x275, kk_box_t _b_x276, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun883(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun883, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun883(kk_function_t _fself, kk_box_t _b_x275, kk_box_t _b_x276, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x884;
  double _x_x885 = kk_double_unbox(_b_x275, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x886 = kk_std_core_types__optional_unbox(_b_x276, KK_OWNED, _ctx); /*? int*/
  _x_x884 = kk_std_num_float64_show(_x_x885, _x_x886, _ctx); /*string*/
  return kk_string_box(_x_x884);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun900__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun900(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun900(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun900, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun900(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x901 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x901);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun914__t {
  struct kk_function_s _base;
  double start_time;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun914(kk_function_t _fself, kk_box_t _b_x282, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun914(double start_time, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun914__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun914__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun914, kk_context());
  _self->start_time = start_time;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun914(kk_function_t _fself, kk_box_t _b_x282, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun914__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun914__t*, _fself, _ctx);
  double start_time = _self->start_time; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(start_time, _ctx);}, {}, _ctx)
  kk_string_t _c_x10017_350 = kk_string_unbox(_b_x282); /*string*/;
  kk_unit_t _x_x915 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129(start_time, _c_x10017_350, _ctx);
  return kk_unit_box(_x_x915);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun917__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun917(kk_function_t _fself, kk_box_t _b_x297, kk_box_t _b_x298, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun917(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun917, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun917(kk_function_t _fself, kk_box_t _b_x297, kk_box_t _b_x298, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_1_10182 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/unified_fast_brain/prat-route>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x918 = kk_std_core_hnd__as_Ev(evx_1_10182, _ctx);
    kk_box_t _box_x283 = _con_x918->hnd;
    int32_t m_1 = _con_x918->marker;
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route h_1 = kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_unbox(_box_x283, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_dup(h_1, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _con_x919 = kk_whitemagic_dash_koka_src_unified__fast__brain__as_Hnd_prat_route(h_1, _ctx);
      kk_integer_t _pat_0_7 = _con_x919->_cfc;
      kk_std_core_hnd__clause2 _fun_dispatch_tool_1 = _con_x919->_fun_dispatch_tool;
      if kk_likely(kk_datatype_ptr_is_unique(h_1, _ctx)) {
        kk_integer_drop(_pat_0_7, _ctx);
        kk_datatype_ptr_free(h_1, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_dispatch_tool_1, _ctx);
        kk_datatype_ptr_decref(h_1, _ctx);
      }
      {
        kk_function_t _fun_unbox_x288 = _fun_dispatch_tool_1.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x288, (_fun_unbox_x288, m_1, evx_1_10182, _b_x297, _b_x298, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun924__t {
  struct kk_function_s _base;
  double start_time;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun924(kk_function_t _fself, kk_box_t _b_x306, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun924(double start_time, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun924__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun924__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun924, kk_context());
  _self->start_time = start_time;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun924(kk_function_t _fself, kk_box_t _b_x306, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun924__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun924__t*, _fself, _ctx);
  double start_time = _self->start_time; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(start_time, _ctx);}, {}, _ctx)
  kk_string_t res_1_351 = kk_string_unbox(_b_x306); /*string*/;
  kk_unit_t _x_x925 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128(start_time, res_1_351, _ctx);
  return kk_unit_box(_x_x925);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun927__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun927(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun927(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun927, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun927(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x928 = kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(_ctx); /*float64*/
  return kk_double_box(_x_x928, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun931__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun931(kk_function_t _fself, kk_box_t _b_x312, kk_box_t _b_x313, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun931(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun931, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun931(kk_function_t _fself, kk_box_t _b_x312, kk_box_t _b_x313, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x932;
  double _x_x933 = kk_double_unbox(_b_x312, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x934 = kk_std_core_types__optional_unbox(_b_x313, KK_OWNED, _ctx); /*? int*/
  _x_x932 = kk_std_num_float64_show(_x_x933, _x_x934, _ctx); /*string*/
  return kk_string_box(_x_x932);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun948__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun948(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun948(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun948, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun948(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x949 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x949);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun951__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun951(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun951(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun951, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun951(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x952 = kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(_ctx); /*float64*/
  return kk_double_box(_x_x952, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun955__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun955(kk_function_t _fself, kk_box_t _b_x323, kk_box_t _b_x324, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun955(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun955, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun955(kk_function_t _fself, kk_box_t _b_x323, kk_box_t _b_x324, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x956;
  double _x_x957 = kk_double_unbox(_b_x323, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x958 = kk_std_core_types__optional_unbox(_b_x324, KK_OWNED, _ctx); /*? int*/
  _x_x956 = kk_std_num_float64_show(_x_x957, _x_x958, _ctx); /*string*/
  return kk_string_box(_x_x956);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun972__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun972(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun972(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun972, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event_fun972(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x973 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x973);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event(int64_t ring_addr, int64_t embed_addr, int64_t graph_addr, kk_string_t event, kk_context_t* _ctx) { /* (ring-addr : int64, embed-addr : int64, graph-addr : int64, event : string) -> <pure,alloc<global>,console/console,fsys,ndet,net,prat-route,read<global>,ui,write<global>> () */ 
  double start_time;
  kk_box_t _x_x700 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun701(_ctx), _ctx); /*10000*/
  start_time = kk_double_unbox(_x_x700, KK_OWNED, _ctx); /*float64*/
  bool _match_x521;
  kk_string_t _x_x703 = kk_string_dup(event, _ctx); /*string*/
  kk_string_t _x_x704;
  kk_define_string_literal(, _s_x705, 8, "\"query\":", _ctx)
  _x_x704 = kk_string_dup(_s_x705, _ctx); /*string*/
  _match_x521 = kk_string_contains(_x_x703,_x_x704,kk_context()); /*bool*/
  if (_match_x521) {
    kk_function_t _b_x152_329 = kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun707(_ctx); /*(i : int) -> int64*/;
    kk_integer_t _b_x153_330 = kk_integer_from_small(0); /*int*/;
    bool _match_x527;
    int64_t _x_x708;
    kk_box_t _x_x709 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun710(_b_x152_329, _ctx), kk_integer_box(_b_x153_330, _ctx), _ctx); /*10001*/
    _x_x708 = kk_int64_unbox(_x_x709, KK_OWNED, _ctx); /*int64*/
    _match_x527 = (embed_addr != _x_x708); /*bool*/
    if (_match_x527) {
      kk_function_t _b_x155_331 = kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun714(_ctx); /*(i : int) -> int64*/;
      kk_integer_t _b_x156_332 = kk_integer_from_small(0); /*int*/;
      bool _match_x533;
      int64_t _x_x715;
      kk_box_t _x_x716 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun717(_b_x155_331, _ctx), kk_integer_box(_b_x156_332, _ctx), _ctx); /*10001*/
      _x_x715 = kk_int64_unbox(_x_x716, KK_OWNED, _ctx); /*int64*/
      _match_x533 = (graph_addr != _x_x715); /*bool*/
      if (_match_x533) {
        kk_integer_t start_id;
        kk_box_t _x_x720 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun721(_ctx), kk_int64_box(embed_addr, _ctx), _ctx); /*10001*/
        start_id = kk_integer_unbox(_x_x720, _ctx); /*int*/
        kk_string_t graph_res;
        kk_box_t _x_x724 = kk_std_core_hnd__open_none3(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun725(_ctx), kk_int64_box(graph_addr, _ctx), kk_integer_box(start_id, _ctx), kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*10003*/
        graph_res = kk_string_unbox(_x_x724); /*string*/
        double end_time;
        kk_box_t _x_x730 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun731(_ctx), _ctx); /*10000*/
        end_time = kk_double_unbox(_x_x730, KK_OWNED, _ctx); /*float64*/
        double _x_x1_3_10082 = (end_time - start_time); /*float64*/;
        kk_string_t dur;
        kk_string_t _x_x733;
        kk_box_t _x_x734 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun735(_ctx), kk_double_box(_x_x1_3_10082, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
        _x_x733 = kk_string_unbox(_x_x734); /*string*/
        kk_string_t _x_x739;
        kk_define_string_literal(, _s_x740, 2, "ms", _ctx)
        _x_x739 = kk_string_dup(_s_x740, _ctx); /*string*/
        dur = kk_std_core_types__lp__plus__plus__rp_(_x_x733, _x_x739, _ctx); /*string*/
        kk_unit_t __ = kk_Unit;
        kk_string_t _x_x741;
        kk_string_t _x_x742;
        kk_define_string_literal(, _s_x743, 50, "{\"status\":\"system_resonance_achieved\", \"latency\":\"", _ctx)
        _x_x742 = kk_string_dup(_s_x743, _ctx); /*string*/
        kk_string_t _x_x744;
        kk_string_t _x_x745;
        kk_string_t _x_x746;
        kk_define_string_literal(, _s_x747, 17, "\", \"input_event\":", _ctx)
        _x_x746 = kk_string_dup(_s_x747, _ctx); /*string*/
        kk_string_t _x_x748;
        kk_string_t _x_x749;
        kk_string_t _x_x750;
        kk_define_string_literal(, _s_x751, 12, ", \"context\":", _ctx)
        _x_x750 = kk_string_dup(_s_x751, _ctx); /*string*/
        kk_string_t _x_x752;
        kk_string_t _x_x753;
        kk_define_string_literal(, _s_x754, 1, "}", _ctx)
        _x_x753 = kk_string_dup(_s_x754, _ctx); /*string*/
        _x_x752 = kk_std_core_types__lp__plus__plus__rp_(graph_res, _x_x753, _ctx); /*string*/
        _x_x749 = kk_std_core_types__lp__plus__plus__rp_(_x_x750, _x_x752, _ctx); /*string*/
        _x_x748 = kk_std_core_types__lp__plus__plus__rp_(event, _x_x749, _ctx); /*string*/
        _x_x745 = kk_std_core_types__lp__plus__plus__rp_(_x_x746, _x_x748, _ctx); /*string*/
        _x_x744 = kk_std_core_types__lp__plus__plus__rp_(dur, _x_x745, _ctx); /*string*/
        _x_x741 = kk_std_core_types__lp__plus__plus__rp_(_x_x742, _x_x744, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x741, _ctx);
        kk_box_t _x_x755 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun756(_ctx), _ctx); /*10000*/
        kk_unit_unbox(_x_x755); return kk_Unit;
      }
      {
        bool _match_x534;
        kk_string_t _x_x758 = kk_string_dup(event, _ctx); /*string*/
        kk_string_t _x_x759;
        kk_define_string_literal(, _s_x760, 13, "\"prat_route\":", _ctx)
        _x_x759 = kk_string_dup(_s_x760, _ctx); /*string*/
        _match_x534 = kk_string_contains(_x_x758,_x_x759,kk_context()); /*bool*/
        if (_match_x534) {
          kk_string_t x_10156;
          bool _match_x537;
          kk_string_t _x_x761 = kk_string_dup(event, _ctx); /*string*/
          kk_string_t _x_x762;
          kk_define_string_literal(, _s_x763, 15, "search_memories", _ctx)
          _x_x762 = kk_string_dup(_s_x763, _ctx); /*string*/
          _match_x537 = kk_string_contains(_x_x761,_x_x762,kk_context()); /*bool*/
          if (_match_x537) {
            kk_string_drop(event, _ctx);
            kk_define_string_literal(, _s_x764, 15, "search_memories", _ctx)
            x_10156 = kk_string_dup(_s_x764, _ctx); /*string*/
          }
          else {
            bool _match_x538;
            kk_string_t _x_x765;
            kk_define_string_literal(, _s_x766, 13, "create_memory", _ctx)
            _x_x765 = kk_string_dup(_s_x766, _ctx); /*string*/
            _match_x538 = kk_string_contains(event,_x_x765,kk_context()); /*bool*/
            if (_match_x538) {
              kk_define_string_literal(, _s_x767, 13, "create_memory", _ctx)
              x_10156 = kk_string_dup(_s_x767, _ctx); /*string*/
            }
            else {
              kk_define_string_literal(, _s_x768, 7, "unknown", _ctx)
              x_10156 = kk_string_dup(_s_x768, _ctx); /*string*/
            }
          }
          if (kk_yielding(kk_context())) {
            kk_string_drop(x_10156, _ctx);
            kk_box_t _x_x769 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun770(start_time, _ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x769); return kk_Unit;
          }
          {
            kk_ssize_t _b_x197_203 = (KK_IZ(1)); /*hnd/ev-index*/;
            kk_string_t x_0_10159;
            kk_box_t _x_x772;
            kk_box_t _x_x776;
            kk_string_t _x_x777;
            kk_define_string_literal(, _s_x778, 2, "{}", _ctx)
            _x_x777 = kk_string_dup(_s_x778, _ctx); /*string*/
            _x_x776 = kk_string_box(_x_x777); /*10001*/
            _x_x772 = kk_std_core_hnd__open_at2(_b_x197_203, kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun773(_ctx), kk_string_box(x_10156), _x_x776, _ctx); /*10002*/
            x_0_10159 = kk_string_unbox(_x_x772); /*string*/
            if (kk_yielding(kk_context())) {
              kk_string_drop(x_0_10159, _ctx);
              kk_box_t _x_x779 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun780(start_time, _ctx), _ctx); /*10001*/
              kk_unit_unbox(_x_x779); return kk_Unit;
            }
            {
              double end_time_0;
              kk_box_t _x_x782 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun783(_ctx), _ctx); /*10000*/
              end_time_0 = kk_double_unbox(_x_x782, KK_OWNED, _ctx); /*float64*/
              double _x_x1_5_10086 = (end_time_0 - start_time); /*float64*/;
              kk_string_t dur_0;
              kk_string_t _x_x785;
              kk_box_t _x_x786 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun787(_ctx), kk_double_box(_x_x1_5_10086, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
              _x_x785 = kk_string_unbox(_x_x786); /*string*/
              kk_string_t _x_x791;
              kk_define_string_literal(, _s_x792, 2, "ms", _ctx)
              _x_x791 = kk_string_dup(_s_x792, _ctx); /*string*/
              dur_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x785, _x_x791, _ctx); /*string*/
              kk_unit_t ___0 = kk_Unit;
              kk_string_t _x_x793;
              kk_string_t _x_x794;
              kk_define_string_literal(, _s_x795, 36, "{\"status\":\"prat_routed\", \"latency\":\"", _ctx)
              _x_x794 = kk_string_dup(_s_x795, _ctx); /*string*/
              kk_string_t _x_x796;
              kk_string_t _x_x797;
              kk_string_t _x_x798;
              kk_define_string_literal(, _s_x799, 12, "\", \"result\":", _ctx)
              _x_x798 = kk_string_dup(_s_x799, _ctx); /*string*/
              kk_string_t _x_x800;
              kk_string_t _x_x801;
              kk_define_string_literal(, _s_x802, 1, "}", _ctx)
              _x_x801 = kk_string_dup(_s_x802, _ctx); /*string*/
              _x_x800 = kk_std_core_types__lp__plus__plus__rp_(x_0_10159, _x_x801, _ctx); /*string*/
              _x_x797 = kk_std_core_types__lp__plus__plus__rp_(_x_x798, _x_x800, _ctx); /*string*/
              _x_x796 = kk_std_core_types__lp__plus__plus__rp_(dur_0, _x_x797, _ctx); /*string*/
              _x_x793 = kk_std_core_types__lp__plus__plus__rp_(_x_x794, _x_x796, _ctx); /*string*/
              kk_std_core_console_printsln(_x_x793, _ctx);
              kk_box_t _x_x803 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun804(_ctx), _ctx); /*10000*/
              kk_unit_unbox(_x_x803); return kk_Unit;
            }
          }
        }
        {
          double end_time_1;
          kk_box_t _x_x806 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun807(_ctx), _ctx); /*10000*/
          end_time_1 = kk_double_unbox(_x_x806, KK_OWNED, _ctx); /*float64*/
          double _x_x1_6_10088 = (end_time_1 - start_time); /*float64*/;
          kk_string_t dur_1;
          kk_string_t _x_x809;
          kk_box_t _x_x810 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun811(_ctx), kk_double_box(_x_x1_6_10088, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
          _x_x809 = kk_string_unbox(_x_x810); /*string*/
          kk_string_t _x_x815;
          kk_define_string_literal(, _s_x816, 2, "ms", _ctx)
          _x_x815 = kk_string_dup(_s_x816, _ctx); /*string*/
          dur_1 = kk_std_core_types__lp__plus__plus__rp_(_x_x809, _x_x815, _ctx); /*string*/
          kk_unit_t ___1 = kk_Unit;
          kk_string_t _x_x817;
          kk_string_t _x_x818;
          kk_define_string_literal(, _s_x819, 44, "{\"status\":\"telemetry_processed\", \"latency\":\"", _ctx)
          _x_x818 = kk_string_dup(_s_x819, _ctx); /*string*/
          kk_string_t _x_x820;
          kk_string_t _x_x821;
          kk_string_t _x_x822;
          kk_define_string_literal(, _s_x823, 17, "\", \"input_event\":", _ctx)
          _x_x822 = kk_string_dup(_s_x823, _ctx); /*string*/
          kk_string_t _x_x824;
          kk_string_t _x_x825;
          kk_define_string_literal(, _s_x826, 1, "}", _ctx)
          _x_x825 = kk_string_dup(_s_x826, _ctx); /*string*/
          _x_x824 = kk_std_core_types__lp__plus__plus__rp_(event, _x_x825, _ctx); /*string*/
          _x_x821 = kk_std_core_types__lp__plus__plus__rp_(_x_x822, _x_x824, _ctx); /*string*/
          _x_x820 = kk_std_core_types__lp__plus__plus__rp_(dur_1, _x_x821, _ctx); /*string*/
          _x_x817 = kk_std_core_types__lp__plus__plus__rp_(_x_x818, _x_x820, _ctx); /*string*/
          kk_std_core_console_printsln(_x_x817, _ctx);
          kk_box_t _x_x827 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun828(_ctx), _ctx); /*10000*/
          kk_unit_unbox(_x_x827); return kk_Unit;
        }
      }
    }
    {
      bool _match_x528;
      kk_string_t _x_x830 = kk_string_dup(event, _ctx); /*string*/
      kk_string_t _x_x831;
      kk_define_string_literal(, _s_x832, 13, "\"prat_route\":", _ctx)
      _x_x831 = kk_string_dup(_s_x832, _ctx); /*string*/
      _match_x528 = kk_string_contains(_x_x830,_x_x831,kk_context()); /*bool*/
      if (_match_x528) {
        kk_string_t x_2_10166;
        bool _match_x531;
        kk_string_t _x_x833 = kk_string_dup(event, _ctx); /*string*/
        kk_string_t _x_x834;
        kk_define_string_literal(, _s_x835, 15, "search_memories", _ctx)
        _x_x834 = kk_string_dup(_s_x835, _ctx); /*string*/
        _match_x531 = kk_string_contains(_x_x833,_x_x834,kk_context()); /*bool*/
        if (_match_x531) {
          kk_string_drop(event, _ctx);
          kk_define_string_literal(, _s_x836, 15, "search_memories", _ctx)
          x_2_10166 = kk_string_dup(_s_x836, _ctx); /*string*/
        }
        else {
          bool _match_x532;
          kk_string_t _x_x837;
          kk_define_string_literal(, _s_x838, 13, "create_memory", _ctx)
          _x_x837 = kk_string_dup(_s_x838, _ctx); /*string*/
          _match_x532 = kk_string_contains(event,_x_x837,kk_context()); /*bool*/
          if (_match_x532) {
            kk_define_string_literal(, _s_x839, 13, "create_memory", _ctx)
            x_2_10166 = kk_string_dup(_s_x839, _ctx); /*string*/
          }
          else {
            kk_define_string_literal(, _s_x840, 7, "unknown", _ctx)
            x_2_10166 = kk_string_dup(_s_x840, _ctx); /*string*/
          }
        }
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_2_10166, _ctx);
          kk_box_t _x_x841 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun842(start_time, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x841); return kk_Unit;
        }
        {
          kk_ssize_t _b_x245_251 = (KK_IZ(1)); /*hnd/ev-index*/;
          kk_string_t x_3_10169;
          kk_box_t _x_x844;
          kk_box_t _x_x848;
          kk_string_t _x_x849;
          kk_define_string_literal(, _s_x850, 2, "{}", _ctx)
          _x_x849 = kk_string_dup(_s_x850, _ctx); /*string*/
          _x_x848 = kk_string_box(_x_x849); /*10001*/
          _x_x844 = kk_std_core_hnd__open_at2(_b_x245_251, kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun845(_ctx), kk_string_box(x_2_10166), _x_x848, _ctx); /*10002*/
          x_3_10169 = kk_string_unbox(_x_x844); /*string*/
          if (kk_yielding(kk_context())) {
            kk_string_drop(x_3_10169, _ctx);
            kk_box_t _x_x851 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun852(start_time, _ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x851); return kk_Unit;
          }
          {
            double end_time_0_0;
            kk_box_t _x_x854 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun855(_ctx), _ctx); /*10000*/
            end_time_0_0 = kk_double_unbox(_x_x854, KK_OWNED, _ctx); /*float64*/
            double _x_x1_8_10092 = (end_time_0_0 - start_time); /*float64*/;
            kk_string_t dur_0_0;
            kk_string_t _x_x857;
            kk_box_t _x_x858 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun859(_ctx), kk_double_box(_x_x1_8_10092, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
            _x_x857 = kk_string_unbox(_x_x858); /*string*/
            kk_string_t _x_x863;
            kk_define_string_literal(, _s_x864, 2, "ms", _ctx)
            _x_x863 = kk_string_dup(_s_x864, _ctx); /*string*/
            dur_0_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x857, _x_x863, _ctx); /*string*/
            kk_unit_t ___0_0 = kk_Unit;
            kk_string_t _x_x865;
            kk_string_t _x_x866;
            kk_define_string_literal(, _s_x867, 36, "{\"status\":\"prat_routed\", \"latency\":\"", _ctx)
            _x_x866 = kk_string_dup(_s_x867, _ctx); /*string*/
            kk_string_t _x_x868;
            kk_string_t _x_x869;
            kk_string_t _x_x870;
            kk_define_string_literal(, _s_x871, 12, "\", \"result\":", _ctx)
            _x_x870 = kk_string_dup(_s_x871, _ctx); /*string*/
            kk_string_t _x_x872;
            kk_string_t _x_x873;
            kk_define_string_literal(, _s_x874, 1, "}", _ctx)
            _x_x873 = kk_string_dup(_s_x874, _ctx); /*string*/
            _x_x872 = kk_std_core_types__lp__plus__plus__rp_(x_3_10169, _x_x873, _ctx); /*string*/
            _x_x869 = kk_std_core_types__lp__plus__plus__rp_(_x_x870, _x_x872, _ctx); /*string*/
            _x_x868 = kk_std_core_types__lp__plus__plus__rp_(dur_0_0, _x_x869, _ctx); /*string*/
            _x_x865 = kk_std_core_types__lp__plus__plus__rp_(_x_x866, _x_x868, _ctx); /*string*/
            kk_std_core_console_printsln(_x_x865, _ctx);
            kk_box_t _x_x875 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun876(_ctx), _ctx); /*10000*/
            kk_unit_unbox(_x_x875); return kk_Unit;
          }
        }
      }
      {
        double end_time_1_0;
        kk_box_t _x_x878 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun879(_ctx), _ctx); /*10000*/
        end_time_1_0 = kk_double_unbox(_x_x878, KK_OWNED, _ctx); /*float64*/
        double _x_x1_9_10094 = (end_time_1_0 - start_time); /*float64*/;
        kk_string_t dur_1_0;
        kk_string_t _x_x881;
        kk_box_t _x_x882 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun883(_ctx), kk_double_box(_x_x1_9_10094, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
        _x_x881 = kk_string_unbox(_x_x882); /*string*/
        kk_string_t _x_x887;
        kk_define_string_literal(, _s_x888, 2, "ms", _ctx)
        _x_x887 = kk_string_dup(_s_x888, _ctx); /*string*/
        dur_1_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x881, _x_x887, _ctx); /*string*/
        kk_unit_t ___1_0 = kk_Unit;
        kk_string_t _x_x889;
        kk_string_t _x_x890;
        kk_define_string_literal(, _s_x891, 44, "{\"status\":\"telemetry_processed\", \"latency\":\"", _ctx)
        _x_x890 = kk_string_dup(_s_x891, _ctx); /*string*/
        kk_string_t _x_x892;
        kk_string_t _x_x893;
        kk_string_t _x_x894;
        kk_define_string_literal(, _s_x895, 17, "\", \"input_event\":", _ctx)
        _x_x894 = kk_string_dup(_s_x895, _ctx); /*string*/
        kk_string_t _x_x896;
        kk_string_t _x_x897;
        kk_define_string_literal(, _s_x898, 1, "}", _ctx)
        _x_x897 = kk_string_dup(_s_x898, _ctx); /*string*/
        _x_x896 = kk_std_core_types__lp__plus__plus__rp_(event, _x_x897, _ctx); /*string*/
        _x_x893 = kk_std_core_types__lp__plus__plus__rp_(_x_x894, _x_x896, _ctx); /*string*/
        _x_x892 = kk_std_core_types__lp__plus__plus__rp_(dur_1_0, _x_x893, _ctx); /*string*/
        _x_x889 = kk_std_core_types__lp__plus__plus__rp_(_x_x890, _x_x892, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x889, _ctx);
        kk_box_t _x_x899 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun900(_ctx), _ctx); /*10000*/
        kk_unit_unbox(_x_x899); return kk_Unit;
      }
    }
  }
  {
    bool _match_x522;
    kk_string_t _x_x902 = kk_string_dup(event, _ctx); /*string*/
    kk_string_t _x_x903;
    kk_define_string_literal(, _s_x904, 13, "\"prat_route\":", _ctx)
    _x_x903 = kk_string_dup(_s_x904, _ctx); /*string*/
    _match_x522 = kk_string_contains(_x_x902,_x_x903,kk_context()); /*bool*/
    if (_match_x522) {
      kk_string_t x_5_10176;
      bool _match_x525;
      kk_string_t _x_x905 = kk_string_dup(event, _ctx); /*string*/
      kk_string_t _x_x906;
      kk_define_string_literal(, _s_x907, 15, "search_memories", _ctx)
      _x_x906 = kk_string_dup(_s_x907, _ctx); /*string*/
      _match_x525 = kk_string_contains(_x_x905,_x_x906,kk_context()); /*bool*/
      if (_match_x525) {
        kk_string_drop(event, _ctx);
        kk_define_string_literal(, _s_x908, 15, "search_memories", _ctx)
        x_5_10176 = kk_string_dup(_s_x908, _ctx); /*string*/
      }
      else {
        bool _match_x526;
        kk_string_t _x_x909;
        kk_define_string_literal(, _s_x910, 13, "create_memory", _ctx)
        _x_x909 = kk_string_dup(_s_x910, _ctx); /*string*/
        _match_x526 = kk_string_contains(event,_x_x909,kk_context()); /*bool*/
        if (_match_x526) {
          kk_define_string_literal(, _s_x911, 13, "create_memory", _ctx)
          x_5_10176 = kk_string_dup(_s_x911, _ctx); /*string*/
        }
        else {
          kk_define_string_literal(, _s_x912, 7, "unknown", _ctx)
          x_5_10176 = kk_string_dup(_s_x912, _ctx); /*string*/
        }
      }
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_5_10176, _ctx);
        kk_box_t _x_x913 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun914(start_time, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x913); return kk_Unit;
      }
      {
        kk_ssize_t _b_x293_299 = (KK_IZ(1)); /*hnd/ev-index*/;
        kk_string_t x_6_10179;
        kk_box_t _x_x916;
        kk_box_t _x_x920;
        kk_string_t _x_x921;
        kk_define_string_literal(, _s_x922, 2, "{}", _ctx)
        _x_x921 = kk_string_dup(_s_x922, _ctx); /*string*/
        _x_x920 = kk_string_box(_x_x921); /*10001*/
        _x_x916 = kk_std_core_hnd__open_at2(_b_x293_299, kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun917(_ctx), kk_string_box(x_5_10176), _x_x920, _ctx); /*10002*/
        x_6_10179 = kk_string_unbox(_x_x916); /*string*/
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_6_10179, _ctx);
          kk_box_t _x_x923 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun924(start_time, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x923); return kk_Unit;
        }
        {
          double end_time_0_1;
          kk_box_t _x_x926 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun927(_ctx), _ctx); /*10000*/
          end_time_0_1 = kk_double_unbox(_x_x926, KK_OWNED, _ctx); /*float64*/
          double _x_x1_11_10098 = (end_time_0_1 - start_time); /*float64*/;
          kk_string_t dur_0_1;
          kk_string_t _x_x929;
          kk_box_t _x_x930 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun931(_ctx), kk_double_box(_x_x1_11_10098, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
          _x_x929 = kk_string_unbox(_x_x930); /*string*/
          kk_string_t _x_x935;
          kk_define_string_literal(, _s_x936, 2, "ms", _ctx)
          _x_x935 = kk_string_dup(_s_x936, _ctx); /*string*/
          dur_0_1 = kk_std_core_types__lp__plus__plus__rp_(_x_x929, _x_x935, _ctx); /*string*/
          kk_unit_t ___0_1 = kk_Unit;
          kk_string_t _x_x937;
          kk_string_t _x_x938;
          kk_define_string_literal(, _s_x939, 36, "{\"status\":\"prat_routed\", \"latency\":\"", _ctx)
          _x_x938 = kk_string_dup(_s_x939, _ctx); /*string*/
          kk_string_t _x_x940;
          kk_string_t _x_x941;
          kk_string_t _x_x942;
          kk_define_string_literal(, _s_x943, 12, "\", \"result\":", _ctx)
          _x_x942 = kk_string_dup(_s_x943, _ctx); /*string*/
          kk_string_t _x_x944;
          kk_string_t _x_x945;
          kk_define_string_literal(, _s_x946, 1, "}", _ctx)
          _x_x945 = kk_string_dup(_s_x946, _ctx); /*string*/
          _x_x944 = kk_std_core_types__lp__plus__plus__rp_(x_6_10179, _x_x945, _ctx); /*string*/
          _x_x941 = kk_std_core_types__lp__plus__plus__rp_(_x_x942, _x_x944, _ctx); /*string*/
          _x_x940 = kk_std_core_types__lp__plus__plus__rp_(dur_0_1, _x_x941, _ctx); /*string*/
          _x_x937 = kk_std_core_types__lp__plus__plus__rp_(_x_x938, _x_x940, _ctx); /*string*/
          kk_std_core_console_printsln(_x_x937, _ctx);
          kk_box_t _x_x947 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun948(_ctx), _ctx); /*10000*/
          kk_unit_unbox(_x_x947); return kk_Unit;
        }
      }
    }
    {
      double end_time_1_1;
      kk_box_t _x_x950 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun951(_ctx), _ctx); /*10000*/
      end_time_1_1 = kk_double_unbox(_x_x950, KK_OWNED, _ctx); /*float64*/
      double _x_x1_12_10100 = (end_time_1_1 - start_time); /*float64*/;
      kk_string_t dur_1_1;
      kk_string_t _x_x953;
      kk_box_t _x_x954 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun955(_ctx), kk_double_box(_x_x1_12_10100, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
      _x_x953 = kk_string_unbox(_x_x954); /*string*/
      kk_string_t _x_x959;
      kk_define_string_literal(, _s_x960, 2, "ms", _ctx)
      _x_x959 = kk_string_dup(_s_x960, _ctx); /*string*/
      dur_1_1 = kk_std_core_types__lp__plus__plus__rp_(_x_x953, _x_x959, _ctx); /*string*/
      kk_unit_t ___1_1 = kk_Unit;
      kk_string_t _x_x961;
      kk_string_t _x_x962;
      kk_define_string_literal(, _s_x963, 44, "{\"status\":\"telemetry_processed\", \"latency\":\"", _ctx)
      _x_x962 = kk_string_dup(_s_x963, _ctx); /*string*/
      kk_string_t _x_x964;
      kk_string_t _x_x965;
      kk_string_t _x_x966;
      kk_define_string_literal(, _s_x967, 17, "\", \"input_event\":", _ctx)
      _x_x966 = kk_string_dup(_s_x967, _ctx); /*string*/
      kk_string_t _x_x968;
      kk_string_t _x_x969;
      kk_define_string_literal(, _s_x970, 1, "}", _ctx)
      _x_x969 = kk_string_dup(_s_x970, _ctx); /*string*/
      _x_x968 = kk_std_core_types__lp__plus__plus__rp_(event, _x_x969, _ctx); /*string*/
      _x_x965 = kk_std_core_types__lp__plus__plus__rp_(_x_x966, _x_x968, _ctx); /*string*/
      _x_x964 = kk_std_core_types__lp__plus__plus__rp_(dur_1_1, _x_x965, _ctx); /*string*/
      _x_x961 = kk_std_core_types__lp__plus__plus__rp_(_x_x962, _x_x964, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x961, _ctx);
      kk_box_t _x_x971 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_handle_event_fun972(_ctx), _ctx); /*10000*/
      kk_unit_unbox(_x_x971); return kk_Unit;
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_server_loop_10130_fun975__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_server_loop_10130_fun975(kk_function_t _fself, kk_box_t _b_x357, kk_box_t _b_x358, kk_box_t _b_x359, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_server_loop_10130_fun975(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_server_loop_10130_fun975, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_server_loop_10130_fun975(kk_function_t _fself, kk_box_t _b_x357, kk_box_t _b_x358, kk_box_t _b_x359, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x976 = kk_Unit;
  int64_t _x_x977 = kk_int64_unbox(_b_x357, KK_OWNED, _ctx); /*int64*/
  int64_t _x_x978 = kk_int64_unbox(_b_x358, KK_OWNED, _ctx); /*int64*/
  int64_t _x_x979 = kk_int64_unbox(_b_x359, KK_OWNED, _ctx); /*int64*/
  kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop(_x_x977, _x_x978, _x_x979, _ctx);
  return kk_unit_box(_x_x976);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_server_loop_10130(int64_t embed_addr, int64_t graph_addr, int64_t ring_addr, kk_unit_t wild__, kk_context_t* _ctx) { /* (embed-addr : int64, graph-addr : int64, ring-addr : int64, wild_ : ()) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,exn> () */ 
  kk_ssize_t _b_x352_360 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_box_t _x_x974 = kk_std_core_hnd__open_at3(_b_x352_360, kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_server_loop_10130_fun975(_ctx), kk_int64_box(ring_addr, _ctx), kk_int64_box(embed_addr, _ctx), kk_int64_box(graph_addr, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x974); return kk_Unit;
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun981__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun981(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun981(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun981, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun982__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun982(kk_function_t _fself, kk_function_t _b_x367, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun982(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun982, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun983__t {
  struct kk_function_s _base;
  kk_function_t _b_x367;
};
static kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun983(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x368, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun983(kk_function_t _b_x367, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun983__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun983__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun983, kk_context());
  _self->_b_x367 = _b_x367;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun983(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x368, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun983__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun983__t*, _fself, _ctx);
  kk_function_t _b_x367 = _self->_b_x367; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x367, _ctx);}, {}, _ctx)
  kk_box_t _x_x984 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x367, (_b_x367, _b_x368, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x984); return kk_Unit;
}
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun982(kk_function_t _fself, kk_function_t _b_x367, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t ___wildcard_x653__45_423 = kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun983(_b_x367, _ctx); /*(hnd/resume-result<1303,()>) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> ()*/;
  kk_function_drop(___wildcard_x653__45_423, _ctx);
  return kk_unit_box(kk_Unit);
}
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun981(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  kk_std_core_exn__exception_drop(x, _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun982(_ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun987__t {
  struct kk_function_s _base;
  kk_function_t _b_x369_414;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun987(kk_function_t _fself, int32_t _b_x370, kk_std_core_hnd__ev _b_x371, kk_box_t _b_x372, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun987(kk_function_t _b_x369_414, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun987__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun987__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun987, kk_context());
  _self->_b_x369_414 = _b_x369_414;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun987(kk_function_t _fself, int32_t _b_x370, kk_std_core_hnd__ev _b_x371, kk_box_t _b_x372, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun987__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun987__t*, _fself, _ctx);
  kk_function_t _b_x369_414 = _self->_b_x369_414; /* (m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 1303 */
  kk_drop_match(_self, {kk_function_dup(_b_x369_414, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x988 = kk_std_core_exn__exception_unbox(_b_x372, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x369_414, (_b_x369_414, _b_x370, _b_x371, _x_x988, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun989__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun989(kk_function_t _fself, kk_box_t _b_x410, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun989(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun989, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun989(kk_function_t _fself, kk_box_t _b_x410, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_424 = kk_Unit;
  kk_unit_unbox(_b_x410);
  return kk_unit_box(_res_424);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun990__t {
  struct kk_function_s _base;
  int64_t embed_addr_0;
  int64_t graph_addr_0;
  int64_t ring_addr_0;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun990(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun990(int64_t embed_addr_0, int64_t graph_addr_0, int64_t ring_addr_0, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun990__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun990__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun990, kk_context());
  _self->embed_addr_0 = embed_addr_0;
  _self->graph_addr_0 = graph_addr_0;
  _self->ring_addr_0 = ring_addr_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun992__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun992(kk_function_t _fself, kk_box_t _b_x375, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun992(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun992, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun992(kk_function_t _fself, kk_box_t _b_x375, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x993;
  int64_t _x_x994 = kk_int64_unbox(_b_x375, KK_OWNED, _ctx); /*int64*/
  _x_x993 = kk_whitemagic_dash_koka_src_unified__fast__brain_shm_ring_poll(_x_x994, _ctx); /*string*/
  return kk_string_box(_x_x993);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1000__t {
  struct kk_function_s _base;
  kk_string_t event;
  int64_t embed_addr_0;
  int64_t graph_addr_0;
  int64_t ring_addr_0;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1000(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun1000(kk_string_t event, int64_t embed_addr_0, int64_t graph_addr_0, int64_t ring_addr_0, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1000__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1000__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1000, kk_context());
  _self->event = event;
  _self->embed_addr_0 = embed_addr_0;
  _self->graph_addr_0 = graph_addr_0;
  _self->ring_addr_0 = ring_addr_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1003__t {
  struct kk_function_s _base;
  kk_string_t event;
  int64_t embed_addr_0;
  int64_t graph_addr_0;
  int64_t ring_addr_0;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1003(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun1003(kk_string_t event, int64_t embed_addr_0, int64_t graph_addr_0, int64_t ring_addr_0, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1003__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1003__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1003, kk_context());
  _self->event = event;
  _self->embed_addr_0 = embed_addr_0;
  _self->graph_addr_0 = graph_addr_0;
  _self->ring_addr_0 = ring_addr_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1003(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1003__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1003__t*, _fself, _ctx);
  kk_string_t event = _self->event; /* string */
  int64_t embed_addr_0 = _self->embed_addr_0; /* int64 */
  int64_t graph_addr_0 = _self->graph_addr_0; /* int64 */
  int64_t ring_addr_0 = _self->ring_addr_0; /* int64 */
  kk_drop_match(_self, {kk_string_dup(event, _ctx);kk_skip_dup(embed_addr_0, _ctx);kk_skip_dup(graph_addr_0, _ctx);kk_skip_dup(ring_addr_0, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1004 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event(ring_addr_0, embed_addr_0, graph_addr_0, event, _ctx);
  return kk_unit_box(_x_x1004);
}
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1000(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1000__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1000__t*, _fself, _ctx);
  kk_string_t event = _self->event; /* string */
  int64_t embed_addr_0 = _self->embed_addr_0; /* int64 */
  int64_t graph_addr_0 = _self->graph_addr_0; /* int64 */
  int64_t ring_addr_0 = _self->ring_addr_0; /* int64 */
  kk_drop_match(_self, {kk_string_dup(event, _ctx);kk_skip_dup(embed_addr_0, _ctx);kk_skip_dup(graph_addr_0, _ctx);kk_skip_dup(ring_addr_0, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x380_388 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_ssize_t _b_x378_390 = (KK_IZ(2)); /*hnd/ev-index*/;
  kk_vector_t _b_x382_386;
  kk_vector_t _vec_x1001 = kk_std_core_vector__unsafe_vector((KK_IZ(2)), _ctx);
  kk_box_t* _buf_x1002 = kk_vector_buf_borrow(_vec_x1001, NULL, _ctx);
  _buf_x1002[0] = kk_ssize_box(_b_x380_388, _ctx);
  _buf_x1002[1] = kk_ssize_box(_b_x378_390, _ctx);
  _b_x382_386 = _vec_x1001; /*vector<hnd/ev-index>*/
  return kk_std_core_hnd__open0(_b_x382_386, kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun1003(event, embed_addr_0, graph_addr_0, ring_addr_0, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1006__t {
  struct kk_function_s _base;
  int64_t embed_addr_0;
  int64_t graph_addr_0;
  int64_t ring_addr_0;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1006(kk_function_t _fself, kk_box_t _b_x393, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun1006(int64_t embed_addr_0, int64_t graph_addr_0, int64_t ring_addr_0, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1006__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1006__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1006, kk_context());
  _self->embed_addr_0 = embed_addr_0;
  _self->graph_addr_0 = graph_addr_0;
  _self->ring_addr_0 = ring_addr_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1006(kk_function_t _fself, kk_box_t _b_x393, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1006__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1006__t*, _fself, _ctx);
  int64_t embed_addr_0 = _self->embed_addr_0; /* int64 */
  int64_t graph_addr_0 = _self->graph_addr_0; /* int64 */
  int64_t ring_addr_0 = _self->ring_addr_0; /* int64 */
  kk_drop_match(_self, {kk_skip_dup(embed_addr_0, _ctx);kk_skip_dup(graph_addr_0, _ctx);kk_skip_dup(ring_addr_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_425 = kk_Unit;
  kk_unit_unbox(_b_x393);
  kk_unit_t _x_x1007 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_server_loop_10130(embed_addr_0, graph_addr_0, ring_addr_0, wild___0_425, _ctx);
  return kk_unit_box(_x_x1007);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1009__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1009(kk_function_t _fself, kk_box_t _b_x396, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun1009(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1009, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1009(kk_function_t _fself, kk_box_t _b_x396, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1010 = kk_Unit;
  kk_integer_t _x_x1011 = kk_integer_unbox(_b_x396, _ctx); /*int*/
  kk_whitemagic_dash_koka_src_unified__fast__brain_sleep_us(_x_x1011, _ctx);
  return kk_unit_box(_x_x1010);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1013__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1013(kk_function_t _fself, kk_box_t _b_x404, kk_box_t _b_x405, kk_box_t _b_x406, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun1013(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1013, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun1013(kk_function_t _fself, kk_box_t _b_x404, kk_box_t _b_x405, kk_box_t _b_x406, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1014 = kk_Unit;
  int64_t _x_x1015 = kk_int64_unbox(_b_x404, KK_OWNED, _ctx); /*int64*/
  int64_t _x_x1016 = kk_int64_unbox(_b_x405, KK_OWNED, _ctx); /*int64*/
  int64_t _x_x1017 = kk_int64_unbox(_b_x406, KK_OWNED, _ctx); /*int64*/
  kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop(_x_x1015, _x_x1016, _x_x1017, _ctx);
  return kk_unit_box(_x_x1014);
}
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun990(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun990__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop_fun990__t*, _fself, _ctx);
  int64_t embed_addr_0 = _self->embed_addr_0; /* int64 */
  int64_t graph_addr_0 = _self->graph_addr_0; /* int64 */
  int64_t ring_addr_0 = _self->ring_addr_0; /* int64 */
  kk_drop_match(_self, {kk_skip_dup(embed_addr_0, _ctx);kk_skip_dup(graph_addr_0, _ctx);kk_skip_dup(ring_addr_0, _ctx);}, {}, _ctx)
  kk_string_t event;
  kk_box_t _x_x991 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun992(_ctx), kk_int64_box(ring_addr_0, _ctx), _ctx); /*10001*/
  event = kk_string_unbox(_x_x991); /*string*/
  kk_unit_t _x_x995 = kk_Unit;
  bool _match_x519;
  kk_string_t _x_x996 = kk_string_dup(event, _ctx); /*string*/
  kk_string_t _x_x997 = kk_string_empty(); /*string*/
  _match_x519 = kk_string_is_neq(_x_x996,_x_x997,kk_context()); /*bool*/
  if (_match_x519) {
    kk_unit_t x_0_10187 = kk_Unit;
    kk_box_t _x_x999 = kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router(kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun1000(event, embed_addr_0, graph_addr_0, ring_addr_0, _ctx), _ctx); /*529*/
    kk_unit_unbox(_x_x999);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1005 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun1006(embed_addr_0, graph_addr_0, ring_addr_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x1005);
    }
    else {
      kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_server_loop_10130(embed_addr_0, graph_addr_0, ring_addr_0, x_0_10187, _ctx);
    }
  }
  else {
    kk_string_drop(event, _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_box_t _x_x1008 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun1009(_ctx), kk_integer_box(kk_integer_from_small(1000), _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x1008);
    kk_ssize_t _b_x399_418 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_box_t _x_x1012 = kk_std_core_hnd__open_at3(_b_x399_418, kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun1013(_ctx), kk_int64_box(ring_addr_0, _ctx), kk_int64_box(embed_addr_0, _ctx), kk_int64_box(graph_addr_0, _ctx), _ctx); /*10003*/
    kk_unit_unbox(_x_x1012);
  }
  return kk_unit_box(_x_x995);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop(int64_t ring_addr_0, int64_t embed_addr_0, int64_t graph_addr_0, kk_context_t* _ctx) { /* (ring-addr : int64, embed-addr : int64, graph-addr : int64) -> io () */ 
  kk_box_t _x_x980;
  kk_function_t _b_x369_414 = kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun981(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 1303*/;
  kk_std_core_exn__exn _x_x985;
  kk_std_core_hnd__clause1 _x_x986 = kk_std_core_hnd__new_Clause1(kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun987(_b_x369_414, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x985 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x986, _ctx); /*exn<10005,10006>*/
  _x_x980 = kk_std_core_exn_exn_fs__handle(_x_x985, kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun989(_ctx), kk_whitemagic_dash_koka_src_unified__fast__brain_new_server_loop_fun990(embed_addr_0, graph_addr_0, ring_addr_0, _ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x980); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_main_10131_fun1021__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_main_10131_fun1021(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_main_10131_fun1021(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_main_10131_fun1021, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_main_10131_fun1021(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1022 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x1022);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_main_10131_fun1024__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_main_10131_fun1024(kk_function_t _fself, kk_box_t _b_x433, kk_box_t _b_x434, kk_box_t _b_x435, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_main_10131_fun1024(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_main_10131_fun1024, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_main_10131_fun1024(kk_function_t _fself, kk_box_t _b_x433, kk_box_t _b_x434, kk_box_t _b_x435, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1025 = kk_Unit;
  int64_t _x_x1026 = kk_int64_unbox(_b_x433, KK_OWNED, _ctx); /*int64*/
  int64_t _x_x1027 = kk_int64_unbox(_b_x434, KK_OWNED, _ctx); /*int64*/
  int64_t _x_x1028 = kk_int64_unbox(_b_x435, KK_OWNED, _ctx); /*int64*/
  kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop(_x_x1026, _x_x1027, _x_x1028, _ctx);
  return kk_unit_box(_x_x1025);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_main_10131(int64_t embed, int64_t graph, int64_t ring, kk_unit_t _c_x10028, kk_context_t* _ctx) { /* (embed : int64, graph : int64, ring : int64, ()) -> () */ 
  kk_unit_t ___4 = kk_Unit;
  kk_string_t _x_x1018;
  kk_define_string_literal(, _s_x1019, 37, "{\"status\":\"started\",\"connected\":true}", _ctx)
  _x_x1018 = kk_string_dup(_s_x1019, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x1018, _ctx);
  kk_unit_t ___5 = kk_Unit;
  kk_box_t _x_x1020 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_main_10131_fun1021(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x1020);
  kk_ssize_t _b_x428_436 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_box_t _x_x1023 = kk_std_core_hnd__open_at3(_b_x428_436, kk_whitemagic_dash_koka_src_unified__fast__brain__new_mlift_main_10131_fun1024(_ctx), kk_int64_box(ring, _ctx), kk_int64_box(embed, _ctx), kk_int64_box(graph, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x1023); return kk_Unit;
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1030__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1030(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1030(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1030, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1031__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1031(kk_function_t _fself, kk_function_t _b_x443, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1031(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1031, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1032__t {
  struct kk_function_s _base;
  kk_function_t _b_x443;
};
static kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1032(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x444, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1032(kk_function_t _b_x443, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1032__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1032__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1032, kk_context());
  _self->_b_x443 = _b_x443;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1032(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x444, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1032__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1032__t*, _fself, _ctx);
  kk_function_t _b_x443 = _self->_b_x443; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x443, _ctx);}, {}, _ctx)
  kk_box_t _x_x1033 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x443, (_b_x443, _b_x444, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x1033); return kk_Unit;
}
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1031(kk_function_t _fself, kk_function_t _b_x443, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t ___wildcard_x653__45_514 = kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1032(_b_x443, _ctx); /*(hnd/resume-result<1467,()>) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> ()*/;
  kk_function_drop(___wildcard_x653__45_514, _ctx);
  return kk_unit_box(kk_Unit);
}
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1030(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  kk_std_core_exn__exception_drop(x, _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1031(_ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1036__t {
  struct kk_function_s _base;
  kk_function_t _b_x445_507;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1036(kk_function_t _fself, int32_t _b_x446, kk_std_core_hnd__ev _b_x447, kk_box_t _b_x448, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1036(kk_function_t _b_x445_507, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1036__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1036__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1036, kk_context());
  _self->_b_x445_507 = _b_x445_507;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1036(kk_function_t _fself, int32_t _b_x446, kk_std_core_hnd__ev _b_x447, kk_box_t _b_x448, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1036__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1036__t*, _fself, _ctx);
  kk_function_t _b_x445_507 = _self->_b_x445_507; /* (m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 1467 */
  kk_drop_match(_self, {kk_function_dup(_b_x445_507, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x1037 = kk_std_core_exn__exception_unbox(_b_x448, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x445_507, (_b_x445_507, _b_x446, _b_x447, _x_x1037, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1038__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1038(kk_function_t _fself, kk_box_t _b_x503, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1038(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1038, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1038(kk_function_t _fself, kk_box_t _b_x503, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_515 = kk_Unit;
  kk_unit_unbox(_b_x503);
  return kk_unit_box(_res_515);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1039__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1039(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1039(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1039, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1043__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1043(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1043(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1043, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1043(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1044 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x1044);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1046__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1046(kk_function_t _fself, kk_box_t _b_x454, kk_box_t _b_x455, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1046(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1046, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1046(kk_function_t _fself, kk_box_t _b_x454, kk_box_t _b_x455, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x1047;
  kk_string_t _x_x1048 = kk_string_unbox(_b_x454); /*string*/
  kk_integer_t _x_x1049 = kk_integer_unbox(_b_x455, _ctx); /*int*/
  _x_x1047 = kk_whitemagic_dash_koka_src_unified__fast__brain_shm_ring_open(_x_x1048, _x_x1049, _ctx); /*int64*/
  return kk_int64_box(_x_x1047, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1056__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1056(kk_function_t _fself, kk_box_t _b_x461, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1056(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1056, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1056(kk_function_t _fself, kk_box_t _b_x461, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x1057;
  kk_string_t _x_x1058 = kk_string_unbox(_b_x461); /*string*/
  _x_x1057 = kk_whitemagic_dash_koka_src_unified__fast__brain_shm_embed_open(_x_x1058, _ctx); /*int64*/
  return kk_int64_box(_x_x1057, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1063__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1063(kk_function_t _fself, kk_box_t _b_x467, kk_box_t _b_x468, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1063(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1063, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1063(kk_function_t _fself, kk_box_t _b_x467, kk_box_t _b_x468, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x1064;
  kk_string_t _x_x1065 = kk_string_unbox(_b_x467); /*string*/
  kk_integer_t _x_x1066 = kk_integer_unbox(_b_x468, _ctx); /*int*/
  _x_x1064 = kk_whitemagic_dash_koka_src_unified__fast__brain_shm_graph_open(_x_x1065, _x_x1066, _ctx); /*int64*/
  return kk_int64_box(_x_x1064, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1074__t {
  struct kk_function_s _base;
};
static int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1074(kk_function_t _fself, kk_integer_t _x1_x1073, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1074(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1074, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1074(kk_function_t _fself, kk_integer_t _x1_x1073, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_int64_int64(_x1_x1073, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1077__t {
  struct kk_function_s _base;
  kk_function_t _b_x472_510;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1077(kk_function_t _fself, kk_box_t _b_x474, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1077(kk_function_t _b_x472_510, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1077__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1077__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1077, kk_context());
  _self->_b_x472_510 = _b_x472_510;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1077(kk_function_t _fself, kk_box_t _b_x474, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1077__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1077__t*, _fself, _ctx);
  kk_function_t _b_x472_510 = _self->_b_x472_510; /* (i : int) -> int64 */
  kk_drop_match(_self, {kk_function_dup(_b_x472_510, _ctx);}, {}, _ctx)
  int64_t _x_x1078;
  kk_integer_t _x_x1079 = kk_integer_unbox(_b_x474, _ctx); /*int*/
  _x_x1078 = kk_function_call(int64_t, (kk_function_t, kk_integer_t, kk_context_t*), _b_x472_510, (_b_x472_510, _x_x1079, _ctx), _ctx); /*int64*/
  return kk_int64_box(_x_x1078, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1083__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1083(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1083(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1083, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1083(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1084 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x1084);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1087__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1087(kk_function_t _fself, kk_box_t _b_x478, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1087(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1087, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1087(kk_function_t _fself, kk_box_t _b_x478, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x1088;
  kk_integer_t _x_x1089 = kk_integer_unbox(_b_x478, _ctx); /*int*/
  _x_x1088 = kk_std_num_int64_int64(_x_x1089, _ctx); /*int64*/
  return kk_int64_box(_x_x1088, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1093__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1093(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1093(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1093, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1093(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1094 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x1094);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1095__t {
  struct kk_function_s _base;
  int64_t embed;
  int64_t graph;
  int64_t ring;
};
static kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1095(kk_function_t _fself, kk_unit_t _c_x10028, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1095(int64_t embed, int64_t graph, int64_t ring, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1095__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1095__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1095, kk_context());
  _self->embed = embed;
  _self->graph = graph;
  _self->ring = ring;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1099__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1099(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1099(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1099, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1099(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1100 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(_ctx);
  return kk_unit_box(_x_x1100);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1102__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1102(kk_function_t _fself, kk_box_t _b_x490, kk_box_t _b_x491, kk_box_t _b_x492, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1102(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1102, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1102(kk_function_t _fself, kk_box_t _b_x490, kk_box_t _b_x491, kk_box_t _b_x492, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1103 = kk_Unit;
  int64_t _x_x1104 = kk_int64_unbox(_b_x490, KK_OWNED, _ctx); /*int64*/
  int64_t _x_x1105 = kk_int64_unbox(_b_x491, KK_OWNED, _ctx); /*int64*/
  int64_t _x_x1106 = kk_int64_unbox(_b_x492, KK_OWNED, _ctx); /*int64*/
  kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop(_x_x1104, _x_x1105, _x_x1106, _ctx);
  return kk_unit_box(_x_x1103);
}
static kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1095(kk_function_t _fself, kk_unit_t _c_x10028, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1095__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1095__t*, _fself, _ctx);
  int64_t embed = _self->embed; /* int64 */
  int64_t graph = _self->graph; /* int64 */
  int64_t ring = _self->ring; /* int64 */
  kk_drop_match(_self, {kk_skip_dup(embed, _ctx);kk_skip_dup(graph, _ctx);kk_skip_dup(ring, _ctx);}, {}, _ctx)
  kk_unit_t ___4 = kk_Unit;
  kk_string_t _x_x1096;
  kk_define_string_literal(, _s_x1097, 37, "{\"status\":\"started\",\"connected\":true}", _ctx)
  _x_x1096 = kk_string_dup(_s_x1097, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x1096, _ctx);
  kk_unit_t ___5 = kk_Unit;
  kk_box_t _x_x1098 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1099(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x1098);
  kk_ssize_t _b_x485_493 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_box_t _x_x1101 = kk_std_core_hnd__open_at3(_b_x485_493, kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1102(_ctx), kk_int64_box(ring, _ctx), kk_int64_box(embed, _ctx), kk_int64_box(graph, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x1101); return kk_Unit;
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1108__t {
  struct kk_function_s _base;
  kk_function_t next;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1108(kk_function_t _fself, kk_box_t _b_x499, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1108(kk_function_t next, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1108__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1108__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1108, kk_context());
  _self->next = next;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1108(kk_function_t _fself, kk_box_t _b_x499, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1108__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1108__t*, _fself, _ctx);
  kk_function_t next = _self->next; /* (()) -> () */
  kk_drop_match(_self, {kk_function_dup(next, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1109 = kk_Unit;
  kk_unit_t _x_x1110 = kk_Unit;
  kk_unit_unbox(_b_x499);
  kk_function_call(kk_unit_t, (kk_function_t, kk_unit_t, kk_context_t*), next, (next, _x_x1110, _ctx), _ctx);
  return kk_unit_box(_x_x1109);
}
static kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_main_fun1039(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x1040;
  kk_define_string_literal(, _s_x1041, 47, "{\"status\":\"starting\",\"unified_fast_brain\":true}", _ctx)
  _x_x1040 = kk_string_dup(_s_x1041, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x1040, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x1042 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1043(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x1042);
  int64_t ring;
  kk_box_t _x_x1045;
  kk_box_t _x_x1050;
  kk_string_t _x_x1051;
  kk_define_string_literal(, _s_x1052, 22, "/whitemagic_event_ring", _ctx)
  _x_x1051 = kk_string_dup(_s_x1052, _ctx); /*string*/
  _x_x1050 = kk_string_box(_x_x1051); /*10000*/
  kk_box_t _x_x1053;
  kk_integer_t _x_x1054 = kk_integer_dup(kk_whitemagic_dash_koka_src_unified__fast__brain_ring_size, _ctx); /*int*/
  _x_x1053 = kk_integer_box(_x_x1054, _ctx); /*10001*/
  _x_x1045 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1046(_ctx), _x_x1050, _x_x1053, _ctx); /*10002*/
  ring = kk_int64_unbox(_x_x1045, KK_OWNED, _ctx); /*int64*/
  int64_t embed;
  kk_box_t _x_x1055;
  kk_box_t _x_x1059;
  kk_string_t _x_x1060;
  kk_define_string_literal(, _s_x1061, 29, "/whitemagic_embed_bridge_real", _ctx)
  _x_x1060 = kk_string_dup(_s_x1061, _ctx); /*string*/
  _x_x1059 = kk_string_box(_x_x1060); /*10000*/
  _x_x1055 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1056(_ctx), _x_x1059, _ctx); /*10001*/
  embed = kk_int64_unbox(_x_x1055, KK_OWNED, _ctx); /*int64*/
  int64_t graph;
  kk_box_t _x_x1062;
  kk_box_t _x_x1067;
  kk_string_t _x_x1068;
  kk_define_string_literal(, _s_x1069, 24, "/whitemagic_graph_bridge", _ctx)
  _x_x1068 = kk_string_dup(_s_x1069, _ctx); /*string*/
  _x_x1067 = kk_string_box(_x_x1068); /*10000*/
  kk_box_t _x_x1070;
  kk_integer_t _x_x1071 = kk_integer_dup(kk_whitemagic_dash_koka_src_unified__fast__brain_graph_size, _ctx); /*int*/
  _x_x1070 = kk_integer_box(_x_x1071, _ctx); /*10001*/
  _x_x1062 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1063(_ctx), _x_x1067, _x_x1070, _ctx); /*10002*/
  graph = kk_int64_unbox(_x_x1062, KK_OWNED, _ctx); /*int64*/
  kk_unit_t _x_x1072 = kk_Unit;
  kk_function_t _b_x472_510 = kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1074(_ctx); /*(i : int) -> int64*/;
  kk_integer_t _b_x473_511 = kk_integer_from_small(0); /*int*/;
  bool _match_x516;
  int64_t _x_x1075;
  kk_box_t _x_x1076 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1077(_b_x472_510, _ctx), kk_integer_box(_b_x473_511, _ctx), _ctx); /*10001*/
  _x_x1075 = kk_int64_unbox(_x_x1076, KK_OWNED, _ctx); /*int64*/
  _match_x516 = (ring == _x_x1075); /*bool*/
  if (_match_x516) {
    kk_unit_t ___1 = kk_Unit;
    kk_string_t _x_x1080;
    kk_define_string_literal(, _s_x1081, 37, "{\"error\":\"failed to open event ring\"}", _ctx)
    _x_x1080 = kk_string_dup(_s_x1081, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x1080, _ctx);
    kk_box_t _x_x1082 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1083(_ctx), _ctx); /*10000*/
    kk_unit_unbox(_x_x1082);
  }
  else {
    kk_unit_t x_0 = kk_Unit;
    bool _match_x518;
    int64_t _x_x1085;
    kk_box_t _x_x1086 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1087(_ctx), kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*10001*/
    _x_x1085 = kk_int64_unbox(_x_x1086, KK_OWNED, _ctx); /*int64*/
    _match_x518 = (graph == _x_x1085); /*bool*/
    if (_match_x518) {
      kk_unit_t ___2 = kk_Unit;
      kk_string_t _x_x1090;
      kk_define_string_literal(, _s_x1091, 41, "{\"error\":\"failed to open graph topology\"}", _ctx)
      _x_x1090 = kk_string_dup(_s_x1091, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x1090, _ctx);
      kk_box_t _x_x1092 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1093(_ctx), _ctx); /*10000*/
      kk_unit_unbox(_x_x1092);
    }
    else {
      
    }
    kk_function_t next = kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1095(embed, graph, ring, _ctx); /*(()) -> ()*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1107 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1108(next, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x1107);
    }
    else {
      kk_function_call(kk_unit_t, (kk_function_t, kk_unit_t, kk_context_t*), next, (next, x_0, _ctx), _ctx);
    }
  }
  return kk_unit_box(_x_x1072);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_box_t _x_x1029;
  kk_function_t _b_x445_507 = kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1030(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 1467*/;
  kk_std_core_exn__exn _x_x1034;
  kk_std_core_hnd__clause1 _x_x1035 = kk_std_core_hnd__new_Clause1(kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1036(_b_x445_507, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x1034 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x1035, _ctx); /*exn<10005,10006>*/
  _x_x1029 = kk_std_core_exn_exn_fs__handle(_x_x1034, kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1038(_ctx), kk_whitemagic_dash_koka_src_unified__fast__brain_new_main_fun1039(_ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x1029); return kk_Unit;
}

// initialization
void kk_whitemagic_dash_koka_src_unified__fast__brain__init(kk_context_t* _ctx){
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
  kk_std_core_console__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_os_readline__init(_ctx);
  kk_std_num_int64__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_list__init(_ctx);
  kk_std_core_delayed__init(_ctx);
  kk_std_num_float64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  kk_init_string_literal(kk_whitemagic_dash_koka_src_unified__fast__brain_ring_name, _ctx)
  {
    kk_integer_t y_10001 = kk_integer_mul((kk_integer_from_int(65536, _ctx)),(kk_integer_from_small(256)),kk_context()); /*int*/;
    kk_whitemagic_dash_koka_src_unified__fast__brain_ring_size = kk_integer_add_small_const(y_10001, 64, _ctx); /*int*/
  }
  kk_init_string_literal(kk_whitemagic_dash_koka_src_unified__fast__brain_embed_name, _ctx)
  kk_init_string_literal(kk_whitemagic_dash_koka_src_unified__fast__brain_graph_name, _ctx)
  {
    kk_integer_t y_10003 = kk_integer_mul((kk_integer_from_int(3000000, _ctx)),(kk_integer_from_small(16)),kk_context()); /*int*/;
    kk_whitemagic_dash_koka_src_unified__fast__brain_graph_size = kk_integer_add_small_const(y_10003, 64, _ctx); /*int*/
  }
  {
    kk_string_t _x_x552;
    kk_define_string_literal(, _s_x553, 29, "prat-route@unified_fast_brain", _ctx)
    _x_x552 = kk_string_dup(_s_x553, _ctx); /*string*/
    kk_whitemagic_dash_koka_src_unified__fast__brain_prat_route_fs__tag = kk_std_core_hnd__new_Htag(_x_x552, _ctx); /*hnd/htag<whitemagic-koka/src/unified_fast_brain/prat-route>*/
  }
}

// termination
void kk_whitemagic_dash_koka_src_unified__fast__brain__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__htag_drop(kk_whitemagic_dash_koka_src_unified__fast__brain_prat_route_fs__tag, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_unified__fast__brain_graph_size, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_unified__fast__brain_ring_size, _ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_core_delayed__done(_ctx);
  kk_std_core_list__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_num_int64__done(_ctx);
  kk_std_os_readline__done(_ctx);
  kk_std_core__done(_ctx);
  kk_std_core_console__done(_ctx);
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
