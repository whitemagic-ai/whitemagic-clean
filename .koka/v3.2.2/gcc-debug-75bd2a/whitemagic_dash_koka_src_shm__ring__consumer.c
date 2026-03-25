// Koka generated module: whitemagic-koka/src/shm_ring_consumer, koka version: 3.2.2, platform: 64-bit
#include "whitemagic_dash_koka_src_shm__ring__consumer.h"
#ifndef SHM_RING_CONSUMER_H
#define SHM_RING_CONSUMER_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <kklib.h>

#define RING_MAGIC 0x52494E47
#define RING_HEADER_SIZE 64
#define RING_SLOT_SIZE 256

static inline int64_t kk_shm_ring_open(kk_string_t name, kk_integer_t size, kk_context_t* ctx) {
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

// Reads the next event from the ring buffer if available, updates tail.
// Returns a JSON string or empty string if no event.
static inline kk_string_t kk_shm_ring_poll(int64_t addr, kk_context_t* ctx) {
    int32_t magic = *(int32_t*)addr;
    if (magic != RING_MAGIC) return kk_string_empty(ctx);
    
    int32_t head = *(int32_t*)(addr + 4);
    int32_t tail = *(int32_t*)(addr + 8);
    int32_t capacity = *(int32_t*)(addr + 12);
    
    if (head == tail) {
        return kk_string_empty(ctx); // empty
    }
    
    intptr_t offset = RING_HEADER_SIZE + (tail * RING_SLOT_SIZE);
    
    int32_t event_type = *(int32_t*)(addr + offset);
    int32_t sender_hash = *(int32_t*)(addr + offset + 4);
    double timestamp = *(double*)(addr + offset + 8);
    
    const char* payload = (const char*)(addr + offset + 16);
    
    char buf[512];
    snprintf(buf, sizeof(buf), "{\"event_type\":%d,\"sender_hash\":%d,\"timestamp\":%f,\"payload\":\"%s\"}", 
             event_type, sender_hash, timestamp, payload);
             
    // Update tail
    int32_t next_tail = (tail + 1) % capacity;
    *(int32_t*)(addr + 8) = next_tail;
    
    return kk_string_alloc_from_utf8(buf, ctx);
}

#endif


int64_t kk_whitemagic_dash_koka_src_shm__ring__consumer_shm_ring_open(kk_string_t name, kk_integer_t size, kk_context_t* _ctx) { /* (name : string, size : int) -> int64 */ 
  return kk_shm_ring_open(name,size,kk_context());
}

kk_string_t kk_whitemagic_dash_koka_src_shm__ring__consumer_shm_ring_poll(int64_t addr, kk_context_t* _ctx) { /* (addr : int64) -> string */ 
  return kk_shm_ring_poll(addr,kk_context());
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_flush_stdout(kk_context_t* _ctx) { /* () -> console/console () */ 
  fflush(stdout); return kk_Unit;
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_sleep_us(kk_integer_t us, kk_context_t* _ctx) { /* (us : int) -> () */ 
  usleep(kk_integer_clamp32(us, kk_context())); return kk_Unit;
}
kk_declare_string_literal(static, kk_whitemagic_dash_koka_src_shm__ring__consumer_shm_name, 22, "/whitemagic_event_ring")

kk_integer_t kk_whitemagic_dash_koka_src_shm__ring__consumer_capacity;

kk_integer_t kk_whitemagic_dash_koka_src_shm__ring__consumer_header_size;

kk_integer_t kk_whitemagic_dash_koka_src_shm__ring__consumer_slot_size;

kk_integer_t kk_whitemagic_dash_koka_src_shm__ring__consumer_segment_size;


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun97__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun97(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun97(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun97, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun98__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun98(kk_function_t _fself, kk_function_t _b_x2, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun98(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun98, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun99__t {
  struct kk_function_s _base;
  kk_function_t _b_x2;
};
static kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun99(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x3, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun99(kk_function_t _b_x2, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun99__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun99__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun99, kk_context());
  _self->_b_x2 = _b_x2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun99(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x3, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun99__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun99__t*, _fself, _ctx);
  kk_function_t _b_x2 = _self->_b_x2; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x2, _ctx);}, {}, _ctx)
  kk_box_t _x_x100 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x2, (_b_x2, _b_x3, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x100); return kk_Unit;
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun98(kk_function_t _fself, kk_function_t _b_x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t ___wildcard_x653__45_44 = kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun99(_b_x2, _ctx); /*(hnd/resume-result<132,()>) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> ()*/;
  kk_function_drop(___wildcard_x653__45_44, _ctx);
  return kk_unit_box(kk_Unit);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun97(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  kk_std_core_exn__exception_drop(x, _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun98(_ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun103__t {
  struct kk_function_s _base;
  kk_function_t _b_x4_35;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun103(kk_function_t _fself, int32_t _b_x5, kk_std_core_hnd__ev _b_x6, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun103(kk_function_t _b_x4_35, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun103__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun103__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun103, kk_context());
  _self->_b_x4_35 = _b_x4_35;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun103(kk_function_t _fself, int32_t _b_x5, kk_std_core_hnd__ev _b_x6, kk_box_t _b_x7, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun103__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun103__t*, _fself, _ctx);
  kk_function_t _b_x4_35 = _self->_b_x4_35; /* (m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 132 */
  kk_drop_match(_self, {kk_function_dup(_b_x4_35, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x104 = kk_std_core_exn__exception_unbox(_b_x7, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x4_35, (_b_x4_35, _b_x5, _b_x6, _x_x104, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun105__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun105(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun105(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun105, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun105(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_45 = kk_Unit;
  kk_unit_unbox(_b_x31);
  return kk_unit_box(_res_45);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun106__t {
  struct kk_function_s _base;
  int64_t addr;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun106(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun106(int64_t addr, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun106__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun106__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun106, kk_context());
  _self->addr = addr;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun108__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun108(kk_function_t _fself, kk_box_t _b_x10, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun108(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun108, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun108(kk_function_t _fself, kk_box_t _b_x10, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x109;
  int64_t _x_x110 = kk_int64_unbox(_b_x10, KK_OWNED, _ctx); /*int64*/
  _x_x109 = kk_whitemagic_dash_koka_src_shm__ring__consumer_shm_ring_poll(_x_x110, _ctx); /*string*/
  return kk_string_box(_x_x109);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun122__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun122(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun122(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun122, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun122(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x123 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__ring__consumer_flush_stdout(_ctx);
  return kk_unit_box(_x_x123);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun125__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun125(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun125(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun125, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun125(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x126 = kk_Unit;
  int64_t _x_x127 = kk_int64_unbox(_b_x18, KK_OWNED, _ctx); /*int64*/
  kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop(_x_x127, _ctx);
  return kk_unit_box(_x_x126);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun129__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun129(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun129(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun129, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun129(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x130 = kk_Unit;
  kk_integer_t _x_x131 = kk_integer_unbox(_b_x21, _ctx); /*int*/
  kk_whitemagic_dash_koka_src_shm__ring__consumer_sleep_us(_x_x131, _ctx);
  return kk_unit_box(_x_x130);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun133__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun133(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun133(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun133, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun133(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x134 = kk_Unit;
  int64_t _x_x135 = kk_int64_unbox(_b_x27, KK_OWNED, _ctx); /*int64*/
  kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop(_x_x135, _ctx);
  return kk_unit_box(_x_x134);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun106(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun106__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop_fun106__t*, _fself, _ctx);
  int64_t addr = _self->addr; /* int64 */
  kk_drop_match(_self, {kk_skip_dup(addr, _ctx);}, {}, _ctx)
  kk_string_t event;
  kk_box_t _x_x107 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun108(_ctx), kk_int64_box(addr, _ctx), _ctx); /*10001*/
  event = kk_string_unbox(_x_x107); /*string*/
  kk_unit_t _x_x111 = kk_Unit;
  bool _match_x93;
  kk_string_t _x_x112 = kk_string_dup(event, _ctx); /*string*/
  kk_string_t _x_x113 = kk_string_empty(); /*string*/
  _match_x93 = kk_string_is_neq(_x_x112,_x_x113,kk_context()); /*bool*/
  if (_match_x93) {
    kk_unit_t __ = kk_Unit;
    kk_string_t _x_x115;
    kk_string_t _x_x116;
    kk_define_string_literal(, _s_x117, 35, "{\"status\":\"event_received\",\"event\":", _ctx)
    _x_x116 = kk_string_dup(_s_x117, _ctx); /*string*/
    kk_string_t _x_x118;
    kk_string_t _x_x119;
    kk_define_string_literal(, _s_x120, 1, "}", _ctx)
    _x_x119 = kk_string_dup(_s_x120, _ctx); /*string*/
    _x_x118 = kk_std_core_types__lp__plus__plus__rp_(event, _x_x119, _ctx); /*string*/
    _x_x115 = kk_std_core_types__lp__plus__plus__rp_(_x_x116, _x_x118, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x115, _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_box_t _x_x121 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun122(_ctx), _ctx); /*10000*/
    kk_unit_unbox(_x_x121);
    kk_ssize_t _b_x15_38 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_box_t _x_x124 = kk_std_core_hnd__open_at1(_b_x15_38, kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun125(_ctx), kk_int64_box(addr, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x124);
  }
  else {
    kk_string_drop(event, _ctx);
    kk_unit_t ___1 = kk_Unit;
    kk_box_t _x_x128 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun129(_ctx), kk_integer_box(kk_integer_from_small(1000), _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x128);
    kk_ssize_t _b_x24_41 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_box_t _x_x132 = kk_std_core_hnd__open_at1(_b_x24_41, kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun133(_ctx), kk_int64_box(addr, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x132);
  }
  return kk_unit_box(_x_x111);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop(int64_t addr, kk_context_t* _ctx) { /* (addr : int64) -> io () */ 
  kk_box_t _x_x96;
  kk_function_t _b_x4_35 = kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun97(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 132*/;
  kk_std_core_exn__exn _x_x101;
  kk_std_core_hnd__clause1 _x_x102 = kk_std_core_hnd__new_Clause1(kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun103(_b_x4_35, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x101 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x102, _ctx); /*exn<10005,10006>*/
  _x_x96 = kk_std_core_exn_exn_fs__handle(_x_x101, kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun105(_ctx), kk_whitemagic_dash_koka_src_shm__ring__consumer_new_server_loop_fun106(addr, _ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x96); return kk_Unit;
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun137__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun137(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun137(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun137, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun138__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun138(kk_function_t _fself, kk_function_t _b_x48, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun138(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun138, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun139__t {
  struct kk_function_s _base;
  kk_function_t _b_x48;
};
static kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun139(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x49, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun139(kk_function_t _b_x48, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun139__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun139__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun139, kk_context());
  _self->_b_x48 = _b_x48;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun139(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x49, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun139__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun139__t*, _fself, _ctx);
  kk_function_t _b_x48 = _self->_b_x48; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x48, _ctx);}, {}, _ctx)
  kk_box_t _x_x140 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x48, (_b_x48, _b_x49, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x140); return kk_Unit;
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun138(kk_function_t _fself, kk_function_t _b_x48, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t ___wildcard_x653__45_90 = kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun139(_b_x48, _ctx); /*(hnd/resume-result<341,()>) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> ()*/;
  kk_function_drop(___wildcard_x653__45_90, _ctx);
  return kk_unit_box(kk_Unit);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun137(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  kk_std_core_exn__exception_drop(x, _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun138(_ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun143__t {
  struct kk_function_s _base;
  kk_function_t _b_x50_81;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun143(kk_function_t _fself, int32_t _b_x51, kk_std_core_hnd__ev _b_x52, kk_box_t _b_x53, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun143(kk_function_t _b_x50_81, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun143__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun143__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun143, kk_context());
  _self->_b_x50_81 = _b_x50_81;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun143(kk_function_t _fself, int32_t _b_x51, kk_std_core_hnd__ev _b_x52, kk_box_t _b_x53, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun143__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun143__t*, _fself, _ctx);
  kk_function_t _b_x50_81 = _self->_b_x50_81; /* (m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 341 */
  kk_drop_match(_self, {kk_function_dup(_b_x50_81, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x144 = kk_std_core_exn__exception_unbox(_b_x53, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x50_81, (_b_x50_81, _b_x51, _b_x52, _x_x144, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun145__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun145(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun145(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun145, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun145(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_91 = kk_Unit;
  kk_unit_unbox(_b_x77);
  return kk_unit_box(_res_91);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun146__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun146(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun146(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun146, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun150__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun150(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun150(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun150, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun150(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x151 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__ring__consumer_flush_stdout(_ctx);
  return kk_unit_box(_x_x151);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun153__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun153(kk_function_t _fself, kk_box_t _b_x59, kk_box_t _b_x60, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun153(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun153, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun153(kk_function_t _fself, kk_box_t _b_x59, kk_box_t _b_x60, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x154;
  kk_string_t _x_x155 = kk_string_unbox(_b_x59); /*string*/
  kk_integer_t _x_x156 = kk_integer_unbox(_b_x60, _ctx); /*int*/
  _x_x154 = kk_whitemagic_dash_koka_src_shm__ring__consumer_shm_ring_open(_x_x155, _x_x156, _ctx); /*int64*/
  return kk_int64_box(_x_x154, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun164__t {
  struct kk_function_s _base;
};
static int64_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun164(kk_function_t _fself, kk_integer_t _x1_x163, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun164(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun164, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static int64_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun164(kk_function_t _fself, kk_integer_t _x1_x163, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_int64_int64(_x1_x163, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun167__t {
  struct kk_function_s _base;
  kk_function_t _b_x64_84;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun167(kk_function_t _fself, kk_box_t _b_x66, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun167(kk_function_t _b_x64_84, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun167__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun167__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun167, kk_context());
  _self->_b_x64_84 = _b_x64_84;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun167(kk_function_t _fself, kk_box_t _b_x66, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun167__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun167__t*, _fself, _ctx);
  kk_function_t _b_x64_84 = _self->_b_x64_84; /* (i : int) -> int64 */
  kk_drop_match(_self, {kk_function_dup(_b_x64_84, _ctx);}, {}, _ctx)
  int64_t _x_x168;
  kk_integer_t _x_x169 = kk_integer_unbox(_b_x66, _ctx); /*int*/
  _x_x168 = kk_function_call(int64_t, (kk_function_t, kk_integer_t, kk_context_t*), _b_x64_84, (_b_x64_84, _x_x169, _ctx), _ctx); /*int64*/
  return kk_int64_box(_x_x168, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun173__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun173(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun173(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun173, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun173(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x174 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__ring__consumer_flush_stdout(_ctx);
  return kk_unit_box(_x_x174);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun178__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun178(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun178(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun178, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun178(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x179 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__ring__consumer_flush_stdout(_ctx);
  return kk_unit_box(_x_x179);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun181__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun181(kk_function_t _fself, kk_box_t _b_x73, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun181(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun181, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun181(kk_function_t _fself, kk_box_t _b_x73, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x182 = kk_Unit;
  int64_t _x_x183 = kk_int64_unbox(_b_x73, KK_OWNED, _ctx); /*int64*/
  kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop(_x_x183, _ctx);
  return kk_unit_box(_x_x182);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main_fun146(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x147;
  kk_define_string_literal(, _s_x148, 46, "{\"status\":\"starting\",\"shm_ring_consumer\":true}", _ctx)
  _x_x147 = kk_string_dup(_s_x148, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x147, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x149 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun150(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x149);
  int64_t addr;
  kk_box_t _x_x152;
  kk_box_t _x_x157;
  kk_string_t _x_x158;
  kk_define_string_literal(, _s_x159, 22, "/whitemagic_event_ring", _ctx)
  _x_x158 = kk_string_dup(_s_x159, _ctx); /*string*/
  _x_x157 = kk_string_box(_x_x158); /*10000*/
  kk_box_t _x_x160;
  kk_integer_t _x_x161 = kk_integer_dup(kk_whitemagic_dash_koka_src_shm__ring__consumer_segment_size, _ctx); /*int*/
  _x_x160 = kk_integer_box(_x_x161, _ctx); /*10001*/
  _x_x152 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun153(_ctx), _x_x157, _x_x160, _ctx); /*10002*/
  addr = kk_int64_unbox(_x_x152, KK_OWNED, _ctx); /*int64*/
  kk_unit_t _x_x162 = kk_Unit;
  kk_function_t _b_x64_84 = kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun164(_ctx); /*(i : int) -> int64*/;
  kk_integer_t _b_x65_85 = kk_integer_from_small(0); /*int*/;
  bool _match_x92;
  int64_t _x_x165;
  kk_box_t _x_x166 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun167(_b_x64_84, _ctx), kk_integer_box(_b_x65_85, _ctx), _ctx); /*10001*/
  _x_x165 = kk_int64_unbox(_x_x166, KK_OWNED, _ctx); /*int64*/
  _match_x92 = (addr == _x_x165); /*bool*/
  if (_match_x92) {
    kk_unit_t ___1 = kk_Unit;
    kk_string_t _x_x170;
    kk_define_string_literal(, _s_x171, 52, "{\"error\":\"failed to open shared memory ring buffer\"}", _ctx)
    _x_x170 = kk_string_dup(_s_x171, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x170, _ctx);
    kk_box_t _x_x172 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun173(_ctx), _ctx); /*10000*/
    kk_unit_unbox(_x_x172);
  }
  else {
    kk_unit_t ___2 = kk_Unit;
    kk_string_t _x_x175;
    kk_define_string_literal(, _s_x176, 37, "{\"status\":\"started\",\"connected\":true}", _ctx)
    _x_x175 = kk_string_dup(_s_x176, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x175, _ctx);
    kk_unit_t ___3 = kk_Unit;
    kk_box_t _x_x177 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun178(_ctx), _ctx); /*10000*/
    kk_unit_unbox(_x_x177);
    kk_ssize_t _b_x70_87 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_box_t _x_x180 = kk_std_core_hnd__open_at1(_b_x70_87, kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun181(_ctx), kk_int64_box(addr, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x180);
  }
  return kk_unit_box(_x_x162);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_box_t _x_x136;
  kk_function_t _b_x50_81 = kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun137(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 341*/;
  kk_std_core_exn__exn _x_x141;
  kk_std_core_hnd__clause1 _x_x142 = kk_std_core_hnd__new_Clause1(kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun143(_b_x50_81, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x141 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x142, _ctx); /*exn<10005,10006>*/
  _x_x136 = kk_std_core_exn_exn_fs__handle(_x_x141, kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun145(_ctx), kk_whitemagic_dash_koka_src_shm__ring__consumer_new_main_fun146(_ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x136); return kk_Unit;
}

// initialization
void kk_whitemagic_dash_koka_src_shm__ring__consumer__init(kk_context_t* _ctx){
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
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  kk_init_string_literal(kk_whitemagic_dash_koka_src_shm__ring__consumer_shm_name, _ctx)
  {
    kk_whitemagic_dash_koka_src_shm__ring__consumer_capacity = kk_integer_from_int(65536, _ctx); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__ring__consumer_header_size = kk_integer_from_small(64); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__ring__consumer_slot_size = kk_integer_from_small(256); /*int*/
  }
  {
    kk_integer_t y_10001 = kk_integer_mul((kk_integer_from_int(65536, _ctx)),(kk_integer_from_small(256)),kk_context()); /*int*/;
    kk_whitemagic_dash_koka_src_shm__ring__consumer_segment_size = kk_integer_add_small_const(y_10001, 64, _ctx); /*int*/
  }
}

// termination
void kk_whitemagic_dash_koka_src_shm__ring__consumer__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__ring__consumer_segment_size, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__ring__consumer_slot_size, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__ring__consumer_header_size, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__ring__consumer_capacity, _ctx);
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
