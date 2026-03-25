#pragma once
#ifndef kk_std_time_chrono_H
#define kk_std_time_chrono_H
// Koka generated module: std/time/chrono, koka version: 3.2.2, platform: 64-bit
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
#include "std_time_timestamp.h"
#include "std_time_duration.h"
#include "std_time_instant.h"
#include "std_time_utc.h"
#include "std_num_ddouble.h"
#include "std_num_float64.h"

// type declarations

// value declarations

kk_std_core_types__tuple2 kk_std_time_chrono_unix_now(kk_context_t* _ctx); /* () -> ndet (float64, float64) */ 

kk_std_time_instant__instant kk_std_time_chrono_now_in(kk_std_core_types__optional ts, kk_context_t* _ctx); /* (ts : ? std/time/instant/timescale) -> ndet std/time/instant/instant */ 

kk_std_time_instant__instant kk_std_time_chrono__mlift_now_10006(kk_std_time_instant__timescale _y_x10003, kk_context_t* _ctx); /* (std/time/instant/timescale) -> std/time/utc/utc std/time/instant/instant */ 

kk_std_time_instant__instant kk_std_time_chrono_now(kk_context_t* _ctx); /* () -> <ndet,std/time/utc/utc> std/time/instant/instant */ 

double kk_std_time_chrono_xnow_resolution(kk_context_t* _ctx); /* () -> ndet float64 */ 
 
// Return the smallest time difference that the system clock can measure.

static inline kk_std_time_duration__duration kk_std_time_chrono_now_resolution(kk_context_t* _ctx) { /* () -> ndet std/time/duration/duration */ 
  double secs_10002 = kk_std_time_chrono_xnow_resolution(_ctx); /*float64*/;
  kk_std_num_ddouble__ddouble _x_x58 = kk_std_num_ddouble__new_Ddouble(secs_10002, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x58, _ctx);
}

void kk_std_time_chrono__init(kk_context_t* _ctx);


void kk_std_time_chrono__done(kk_context_t* _ctx);

#endif // header
