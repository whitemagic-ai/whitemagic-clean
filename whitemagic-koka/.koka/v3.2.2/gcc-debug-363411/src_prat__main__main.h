#pragma once
#ifndef kk_src_prat__main__main_H
#define kk_src_prat__main__main_H
// Koka generated module: src/prat_main/@main, koka version: 3.2.2, platform: 64-bit
#include <kklib.h>
#include "std_os_readline.h"
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
#include "src_prat__main.h"
#include "std_core.h"

// type declarations

// value declarations
 
// monadic lift

static inline kk_unit_t kk_src_prat__main__main__mlift_expr_10002(kk_unit_t wild__, kk_context_t* _ctx) { /* (wild_ : ()) -> io () */ 
  kk_Unit; return kk_Unit;
}

kk_unit_t kk_src_prat__main__main__expr(kk_context_t* _ctx); /* () -> io () */ 
 
// monadic lift

static inline kk_unit_t kk_src_prat__main__main__mlift_main_10003(kk_unit_t wild__, kk_context_t* _ctx) { /* (wild_ : ()) -> io () */ 
  kk_Unit; return kk_Unit;
}

kk_unit_t kk_src_prat__main__main__main(kk_context_t* _ctx); /* () -> <st<global>,console/console,div,fsys,ndet,net,ui> () */ 

void kk_src_prat__main__main__init(kk_context_t* _ctx);


void kk_src_prat__main__main__done(kk_context_t* _ctx);

#endif // header
