#pragma once
#ifndef kk_whitemagic_dash_koka_src_unified__fast__brain_H
#define kk_whitemagic_dash_koka_src_unified__fast__brain_H
// Koka generated module: whitemagic-koka/src/unified_fast_brain, koka version: 3.2.2, platform: 64-bit
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
#include "std_core_console.h"
#include "std_core.h"
#include "std_os_readline.h"
#include "std_num_int64.h"
#include "std_core_int.h"
#include "std_core_string.h"
#include "std_core_list.h"
#include "std_core_delayed.h"
#include "std_num_float64.h"

// type declarations

// type whitemagic-koka/src/unified_fast_brain/prat-route
struct kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route;
struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause2 _fun_dispatch_tool;
};
static inline kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route kk_whitemagic_dash_koka_src_unified__fast__brain__base_Hnd_prat_route(struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route kk_whitemagic_dash_koka_src_unified__fast__brain__new_Hnd_prat_route(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause2 _fun_dispatch_tool, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _con = kk_block_alloc_at_as(struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_dispatch_tool = _fun_dispatch_tool;
  return kk_whitemagic_dash_koka_src_unified__fast__brain__base_Hnd_prat_route(_con, _ctx);
}
static inline struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* kk_whitemagic_dash_koka_src_unified__fast__brain__as_Hnd_prat_route(kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_whitemagic_dash_koka_src_unified__fast__brain__is_Hnd_prat_route(kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_dup(kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_drop(kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_box(kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations

double kk_whitemagic_dash_koka_src_unified__fast__brain_get_time_ms(kk_context_t* _ctx); /* () -> float64 */ 

int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_ring_open(kk_string_t name, kk_integer_t size, kk_context_t* _ctx); /* (name : string, size : int) -> int64 */ 

kk_string_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_ring_poll(int64_t addr, kk_context_t* _ctx); /* (addr : int64) -> string */ 

int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_embed_open(kk_string_t name, kk_context_t* _ctx); /* (name : string) -> int64 */ 

kk_integer_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_embed_search(int64_t addr, kk_context_t* _ctx); /* (addr : int64) -> int */ 

int64_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_graph_open(kk_string_t name, kk_integer_t size, kk_context_t* _ctx); /* (name : string, size : int) -> int64 */ 

kk_string_t kk_whitemagic_dash_koka_src_unified__fast__brain_shm_graph_walk(int64_t addr, kk_integer_t start_id, kk_integer_t hops, kk_context_t* _ctx); /* (addr : int64, start-id : int, hops : int) -> string */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_flush_stdout(kk_context_t* _ctx); /* () -> console/console () */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_sleep_us(kk_integer_t us, kk_context_t* _ctx); /* (us : int) -> () */ 

extern kk_integer_t kk_whitemagic_dash_koka_src_unified__fast__brain_ring_size;

extern kk_integer_t kk_whitemagic_dash_koka_src_unified__fast__brain_graph_size;
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:prat-route` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_unified__fast__brain_prat_route_fs__cfc(kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route _this, kk_context_t* _ctx) { /* forall<e,a> (prat-route<e,a>) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _con_x551 = kk_whitemagic_dash_koka_src_unified__fast__brain__as_Hnd_prat_route(_this, _ctx);
    kk_integer_t _x = _con_x551->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_whitemagic_dash_koka_src_unified__fast__brain_prat_route_fs__tag;

kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_prat_route_fs__handle(kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : prat-route<e,b>, ret : (res : a) -> e b, action : () -> <prat-route|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-dispatch-tool` constructor field of the `:prat-route` type.

static inline kk_std_core_hnd__clause2 kk_whitemagic_dash_koka_src_unified__fast__brain_prat_route_fs__fun_dispatch_tool(kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route _this, kk_context_t* _ctx) { /* forall<e,a> (prat-route<e,a>) -> hnd/clause2<string,string,string,prat-route,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _con_x555 = kk_whitemagic_dash_koka_src_unified__fast__brain__as_Hnd_prat_route(_this, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x555->_fun_dispatch_tool;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `dispatch-tool` operation out of effect `:prat-route`

static inline kk_std_core_hnd__clause2 kk_whitemagic_dash_koka_src_unified__fast__brain_dispatch_tool_fs__select(kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : prat-route<e,a>) -> hnd/clause2<string,string,string,prat-route,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _con_x556 = kk_whitemagic_dash_koka_src_unified__fast__brain__as_Hnd_prat_route(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_dispatch_tool = _con_x556->_fun_dispatch_tool;
    return kk_std_core_hnd__clause2_dup(_fun_dispatch_tool, _ctx);
  }
}
 
// Call the `fun dispatch-tool` operation of the effect `:prat-route`

static inline kk_string_t kk_whitemagic_dash_koka_src_unified__fast__brain_dispatch_tool(kk_string_t tool_name, kk_string_t args, kk_context_t* _ctx) { /* (tool-name : string, args : string) -> prat-route string */ 
  kk_std_core_hnd__ev evx_10133 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/unified_fast_brain/prat-route>*/;
  kk_box_t _x_x557;
  {
    struct kk_std_core_hnd_Ev* _con_x558 = kk_std_core_hnd__as_Ev(evx_10133, _ctx);
    kk_box_t _box_x8 = _con_x558->hnd;
    int32_t m = _con_x558->marker;
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route h = kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_unified__fast__brain__prat_route_dup(h, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__fast__brain__Hnd_prat_route* _con_x559 = kk_whitemagic_dash_koka_src_unified__fast__brain__as_Hnd_prat_route(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x559->_cfc;
      kk_std_core_hnd__clause2 _fun_dispatch_tool = _con_x559->_fun_dispatch_tool;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_dispatch_tool, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x13 = _fun_dispatch_tool.clause;
        _x_x557 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x13, (_fun_unbox_x13, m, evx_10133, kk_string_box(tool_name), kk_string_box(args), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_string_unbox(_x_x557);
}

kk_string_t kk_whitemagic_dash_koka_src_unified__fast__brain_route_to_gana(kk_string_t tool, kk_context_t* _ctx); /* (tool : string) -> string */ 

kk_box_t kk_whitemagic_dash_koka_src_unified__fast__brain_with_prat_router(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <prat-route|e> a) -> e a */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10124(double start_time, kk_string_t res, kk_context_t* _ctx); /* (start-time : float64, res : string) -> <prat-route,console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10125(double start_time, kk_string_t _c_x10007, kk_context_t* _ctx); /* (start-time : float64, string) -> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10126(double start_time, kk_string_t res_0, kk_context_t* _ctx); /* (start-time : float64, res@0 : string) -> <prat-route,console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10127(double start_time, kk_string_t _c_x10012, kk_context_t* _ctx); /* (start-time : float64, string) -> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10128(double start_time, kk_string_t res_1, kk_context_t* _ctx); /* (start-time : float64, res@1 : string) -> <prat-route,console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_handle_event_10129(double start_time, kk_string_t _c_x10017, kk_context_t* _ctx); /* (start-time : float64, string) -> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_handle_event(int64_t ring_addr, int64_t embed_addr, int64_t graph_addr, kk_string_t event, kk_context_t* _ctx); /* (ring-addr : int64, embed-addr : int64, graph-addr : int64, event : string) -> <pure,alloc<global>,console/console,fsys,ndet,net,prat-route,read<global>,ui,write<global>> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_server_loop_10130(int64_t embed_addr, int64_t graph_addr, int64_t ring_addr, kk_unit_t wild__, kk_context_t* _ctx); /* (embed-addr : int64, graph-addr : int64, ring-addr : int64, wild_ : ()) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,exn> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_server_loop(int64_t ring_addr_0, int64_t embed_addr_0, int64_t graph_addr_0, kk_context_t* _ctx); /* (ring-addr : int64, embed-addr : int64, graph-addr : int64) -> io () */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain__mlift_main_10131(int64_t embed, int64_t graph, int64_t ring, kk_unit_t _c_x10028, kk_context_t* _ctx); /* (embed : int64, graph : int64, ring : int64, ()) -> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_unified__fast__brain_main(kk_context_t* _ctx); /* () -> io () */ 

void kk_whitemagic_dash_koka_src_unified__fast__brain__init(kk_context_t* _ctx);


void kk_whitemagic_dash_koka_src_unified__fast__brain__done(kk_context_t* _ctx);

#endif // header
