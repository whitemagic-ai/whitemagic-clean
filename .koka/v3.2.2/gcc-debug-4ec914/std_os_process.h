#pragma once
#ifndef kk_std_os_process_H
#define kk_std_os_process_H
// Koka generated module: std/os/process, koka version: 3.2.2, platform: 64-bit
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
#include "std_os_path.h"

// type declarations

// value declarations

kk_std_core_exn__error kk_std_os_process_run_system_read(kk_string_t cmd, kk_context_t* _ctx); /* (cmd : string) -> io error<string> */ 

kk_integer_t kk_std_os_process_run_system(kk_string_t cmd, kk_context_t* _ctx); /* (cmd : string) -> io int */ 

void kk_std_os_process__init(kk_context_t* _ctx);


void kk_std_os_process__done(kk_context_t* _ctx);

#endif // header
