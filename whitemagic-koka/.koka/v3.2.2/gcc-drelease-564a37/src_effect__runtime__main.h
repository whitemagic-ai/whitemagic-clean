#pragma once
#ifndef kk_src_effect__runtime__main_H
#define kk_src_effect__runtime__main_H
// Koka generated module: src/effect_runtime/@main, koka version: 3.2.2, platform: 64-bit
#include <kklib.h>
#include "std_core_undiv.h"
#include "std_text_parse.h"
#include "std_num_int32.h"
#include "std_num_int64.h"
#include "std_os_readline.h"
#include "std_num_float64.h"
#include "gan__ying.h"
#include "hot__paths.h"
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
#include "src_effect__runtime.h"
#include "std_core.h"

// type declarations

// value declarations

static inline kk_unit_t kk_src_effect__runtime__main__expr(kk_context_t* _ctx) { /* () -> io () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x21;
  kk_define_string_literal(, _s_x22, 112, "{\"status\":\"started\",\"effect_runtime\":true,\"version\":\"4.0\",\"features\":[\"state_effects\",\"emit\",\"profile\",\"trace\"]}", _ctx)
  _x_x21 = kk_string_dup(_s_x22, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x21, _ctx);
  kk_src_effect__runtime__runtime_state _x_x23 = kk_src_effect__runtime__new_Runtime_state(kk_reuse_null, 0, kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), kk_integer_from_small(0), _ctx); /*src/effect_runtime/runtime-state*/
  kk_src_effect__runtime_server_loop(_x_x23, _ctx); return kk_Unit;
}

kk_unit_t kk_src_effect__runtime__main__main(kk_context_t* _ctx); /* () -> <st<global>,console/console,div,fsys,ndet,net,ui> () */ 

void kk_src_effect__runtime__main__init(kk_context_t* _ctx);


void kk_src_effect__runtime__main__done(kk_context_t* _ctx);

#endif // header
