#pragma once
#ifndef kk_std_time_timer_H
#define kk_std_time_timer_H
// Koka generated module: std/time/timer, koka version: 3.2.2, platform: 64-bit
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
#include "std_num_float64.h"
#include "std_num_ddouble.h"
#include "std_time_duration.h"
#include "std_time_instant.h"

// type declarations

// value declarations

kk_std_core_types__tuple2 kk_std_time_timer_xticks(kk_context_t* _ctx); /* () -> ndet (float64, float64) */ 
 
// Return a high-resolution time stamp in fractional SI seconds.
// The duration is guaranteed to be monotonically increasing
// and have at least millisecond resolution.

static inline kk_std_time_duration__duration kk_std_time_timer_ticks(kk_context_t* _ctx) { /* () -> ndet std/time/duration/duration */ 
  kk_std_core_types__tuple2 _match_x44 = kk_std_time_timer_xticks(_ctx); /*(float64, float64)*/;
  {
    kk_box_t _box_x0 = _match_x44.fst;
    kk_box_t _box_x1 = _match_x44.snd;
    double secs = kk_double_unbox(_box_x0, KK_BORROWED, _ctx);
    double frac = kk_double_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__tuple2_drop(_match_x44, _ctx);
    return kk_std_time_duration_float64frac_fs_duration(secs, frac, _ctx);
  }
}

double kk_std_time_timer_xticks_resolution(kk_context_t* _ctx); /* () -> ndet float64 */ 
 
// Return the smallest time difference in seconds that `ticks` can measure.

static inline kk_std_time_duration__duration kk_std_time_timer_ticks_resolution(kk_context_t* _ctx) { /* () -> ndet std/time/duration/duration */ 
  double secs_10000 = kk_std_time_timer_xticks_resolution(_ctx); /*float64*/;
  kk_std_num_ddouble__ddouble _x_x45 = kk_std_num_ddouble__new_Ddouble(secs_10000, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x45, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_timer__mlift_elapsed_10004(kk_std_time_duration__duration t0, kk_box_t x, kk_context_t* _ctx); /* forall<a,e> (t0 : std/time/duration/duration, x : a) -> <ndet|e> (std/time/duration/duration, a) */ 

kk_std_core_types__tuple2 kk_std_time_timer_elapsed(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <ndet|e> a) -> <ndet|e> (std/time/duration/duration, a) */ 

kk_box_t kk_std_time_timer__mlift_print_elapsed_10005(kk_std_core_types__optional msg, kk_std_core_types__tuple2 _y_x10002, kk_context_t* _ctx); /* forall<a,e> (msg : ? string, (std/time/duration/duration, a)) -> <ndet,console/console|e> a */ 

kk_box_t kk_std_time_timer_print_elapsed(kk_function_t action, kk_std_core_types__optional msg, kk_context_t* _ctx); /* forall<a,e> (action : () -> <ndet,console/console|e> a, msg : ? string) -> <ndet,console/console|e> a */ 

void kk_std_time_timer__init(kk_context_t* _ctx);


void kk_std_time_timer__done(kk_context_t* _ctx);

#endif // header
