#pragma once
#ifndef kk_src_effects_prat__resonance__main_H
#define kk_src_effects_prat__resonance__main_H
// Koka generated module: src/effects/prat_resonance/@main, koka version: 3.2.2, platform: 64-bit
#include <kklib.h>
#include "std_time_timestamp.h"
#include "std_num_decimal.h"
#include "std_time_duration.h"
#include "std_time_instant.h"
#include "std_time_utc.h"
#include "std_time_chrono.h"
#include "std_time_timer.h"
#include "std_time_date.h"
#include "std_time_calendar.h"
#include "std_time_calendars.h"
#include "std_time_time.h"
#include "std_time_locale.h"
#include "std_time_format.h"
#include "std_time_parse.h"
#include "std_num_ddouble.h"
#include "std_num_int32.h"
#include "std_num_int64.h"
#include "std_core_undiv.h"
#include "std_text_parse.h"
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
#include "std_time.h"
#include "std_num_random.h"
#include "std_core_vector.h"
#include "std_num_float64.h"
#include "std_core.h"
#include "src_effects_prat__resonance.h"

// type declarations

// value declarations

static inline kk_unit_t kk_src_effects_prat__resonance__main__expr(kk_context_t* _ctx) { /* () -> console/console () */ 
  kk_string_t _x_x0 = kk_std_core_int_show(kk_integer_from_small(0), _ctx); /*string*/
  kk_std_core_console_printsln(_x_x0, _ctx); return kk_Unit;
}

static inline kk_unit_t kk_src_effects_prat__resonance__main__main(kk_context_t* _ctx) { /* () -> <st<global>,console/console,div,fsys,ndet,net,ui> () */ 
  kk_string_t _x_x1 = kk_std_core_int_show(kk_integer_from_small(0), _ctx); /*string*/
  kk_std_core_console_printsln(_x_x1, _ctx); return kk_Unit;
}

void kk_src_effects_prat__resonance__main__init(kk_context_t* _ctx);


void kk_src_effects_prat__resonance__main__done(kk_context_t* _ctx);

#endif // header
