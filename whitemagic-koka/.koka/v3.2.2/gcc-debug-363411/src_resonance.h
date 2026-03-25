#pragma once
#ifndef kk_src_resonance_H
#define kk_src_resonance_H
// Koka generated module: src/resonance, koka version: 3.2.2, platform: 64-bit
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

// value declarations

extern kk_std_core_types__list kk_src_resonance_gana_order;

kk_integer_t kk_src_resonance_gana_index(kk_string_t name, kk_context_t* _ctx); /* (name : string) -> int */ 

kk_string_t kk_src_resonance_list_at(kk_std_core_types__list lst, kk_integer_t idx, kk_context_t* _ctx); /* (lst : list<string>, idx : int) -> string */ 

kk_string_t kk_src_resonance_get_predecessor(kk_string_t gana_name, kk_context_t* _ctx); /* (gana-name : string) -> string */ 

kk_string_t kk_src_resonance_get_successor(kk_string_t gana_name, kk_context_t* _ctx); /* (gana-name : string) -> string */ 

kk_string_t kk_src_resonance_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_string_t kk_src_resonance_extract_gana(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_unit_t kk_src_resonance_flush_stdout(kk_context_t* _ctx); /* () -> console/console () */ 

kk_unit_t kk_src_resonance__mlift_server_loop_10033(kk_string_t _c_x10011, double harmony, double lunar_phase, kk_string_t new_last_gana, kk_integer_t _c_x10012, kk_context_t* _ctx); /* (string, harmony : float64, lunar-phase : float64, new-last-gana : string, int) -> () */ 

kk_unit_t kk_src_resonance__mlift_server_loop_10034(kk_integer_t call_count, kk_string_t gana, double harmony_0, kk_string_t last_gana, double lunar_phase_0, kk_string_t op, kk_string_t _c_x10011_0, kk_context_t* _ctx); /* (call-count : int, gana : string, harmony : float64, last-gana : string, lunar-phase : float64, op : string, string) -> () */ 

kk_unit_t kk_src_resonance__mlift_server_loop_10035(kk_integer_t call_count_0, double harmony_1, kk_string_t last_gana_0, double lunar_phase_1, kk_string_t line, kk_context_t* _ctx); /* (call-count : int, harmony : float64, last-gana : string, lunar-phase : float64, line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_resonance_server_loop(kk_string_t last_gana_1, kk_integer_t call_count_1, double lunar_phase_2, double harmony_2, kk_context_t* _ctx); /* (last-gana : string, call-count : int, lunar-phase : float64, harmony : float64) -> io () */ 

static inline kk_unit_t kk_src_resonance_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_string_t _x_x669 = kk_string_empty(); /*string*/
  kk_src_resonance_server_loop(_x_x669, kk_integer_from_small(0), 0x1p-1, 0x1.e666666666666p-1, _ctx); return kk_Unit;
}

void kk_src_resonance__init(kk_context_t* _ctx);


void kk_src_resonance__done(kk_context_t* _ctx);

#endif // header
