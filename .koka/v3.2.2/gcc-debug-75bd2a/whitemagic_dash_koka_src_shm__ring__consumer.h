#pragma once
#ifndef kk_whitemagic_dash_koka_src_shm__ring__consumer_H
#define kk_whitemagic_dash_koka_src_shm__ring__consumer_H
// Koka generated module: whitemagic-koka/src/shm_ring_consumer, koka version: 3.2.2, platform: 64-bit
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

// type declarations

// value declarations

int64_t kk_whitemagic_dash_koka_src_shm__ring__consumer_shm_ring_open(kk_string_t name, kk_integer_t size, kk_context_t* _ctx); /* (name : string, size : int) -> int64 */ 

kk_string_t kk_whitemagic_dash_koka_src_shm__ring__consumer_shm_ring_poll(int64_t addr, kk_context_t* _ctx); /* (addr : int64) -> string */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_flush_stdout(kk_context_t* _ctx); /* () -> console/console () */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_sleep_us(kk_integer_t us, kk_context_t* _ctx); /* (us : int) -> () */ 

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__ring__consumer_capacity;

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__ring__consumer_header_size;

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__ring__consumer_slot_size;

extern kk_integer_t kk_whitemagic_dash_koka_src_shm__ring__consumer_segment_size;

kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_server_loop(int64_t addr, kk_context_t* _ctx); /* (addr : int64) -> io () */ 

kk_unit_t kk_whitemagic_dash_koka_src_shm__ring__consumer_main(kk_context_t* _ctx); /* () -> io () */ 

void kk_whitemagic_dash_koka_src_shm__ring__consumer__init(kk_context_t* _ctx);


void kk_whitemagic_dash_koka_src_shm__ring__consumer__done(kk_context_t* _ctx);

#endif // header
