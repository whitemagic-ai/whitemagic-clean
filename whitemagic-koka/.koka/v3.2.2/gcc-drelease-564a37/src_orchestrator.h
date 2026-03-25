#pragma once
#ifndef kk_src_orchestrator_H
#define kk_src_orchestrator_H
// Koka generated module: src/orchestrator, koka version: 3.2.2, platform: 64-bit
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
#include "std_core.h"
#include "std_os_readline.h"
#include "std_os_process.h"
#include "std_num_float64.h"
#include "std_num_int64.h"
#include "std_time.h"

// type declarations

// type src/orchestrator/managed-process
struct kk_src_orchestrator__managed_process_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_orchestrator__managed_process;
struct kk_src_orchestrator_Managed_process {
  struct kk_src_orchestrator__managed_process_s _base;
  kk_string_t name;
  kk_integer_t pid;
  kk_string_t binary_path;
  kk_string_t status;
  kk_integer_t restart_count;
  double start_time;
};
static inline kk_src_orchestrator__managed_process kk_src_orchestrator__base_Managed_process(struct kk_src_orchestrator_Managed_process* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_orchestrator__managed_process kk_src_orchestrator__new_Managed_process(kk_reuse_t _at, int32_t _cpath, kk_string_t name, kk_integer_t pid, kk_string_t binary_path, kk_string_t status, double start_time, kk_integer_t restart_count, kk_context_t* _ctx) {
  struct kk_src_orchestrator_Managed_process* _con = kk_block_alloc_at_as(struct kk_src_orchestrator_Managed_process, _at, 5 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->name = name;
  _con->pid = pid;
  _con->binary_path = binary_path;
  _con->status = status;
  _con->restart_count = restart_count;
  _con->start_time = start_time;
  return kk_src_orchestrator__base_Managed_process(_con, _ctx);
}
static inline struct kk_src_orchestrator_Managed_process* kk_src_orchestrator__as_Managed_process(kk_src_orchestrator__managed_process x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_orchestrator_Managed_process*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_orchestrator__is_Managed_process(kk_src_orchestrator__managed_process x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_orchestrator__managed_process kk_src_orchestrator__managed_process_dup(kk_src_orchestrator__managed_process _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_orchestrator__managed_process_drop(kk_src_orchestrator__managed_process _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_orchestrator__managed_process_box(kk_src_orchestrator__managed_process _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_orchestrator__managed_process kk_src_orchestrator__managed_process_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/orchestrator/orchestrator-state
struct kk_src_orchestrator__orchestrator_state_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_orchestrator__orchestrator_state;
struct kk_src_orchestrator_Orchestrator_state {
  struct kk_src_orchestrator__orchestrator_state_s _base;
  kk_std_core_types__list processes;
  kk_integer_t total_restarts;
  double last_health_check;
};
static inline kk_src_orchestrator__orchestrator_state kk_src_orchestrator__base_Orchestrator_state(struct kk_src_orchestrator_Orchestrator_state* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_orchestrator__orchestrator_state kk_src_orchestrator__new_Orchestrator_state(kk_reuse_t _at, int32_t _cpath, kk_std_core_types__list processes, kk_integer_t total_restarts, double last_health_check, kk_context_t* _ctx) {
  struct kk_src_orchestrator_Orchestrator_state* _con = kk_block_alloc_at_as(struct kk_src_orchestrator_Orchestrator_state, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->processes = processes;
  _con->total_restarts = total_restarts;
  _con->last_health_check = last_health_check;
  return kk_src_orchestrator__base_Orchestrator_state(_con, _ctx);
}
static inline struct kk_src_orchestrator_Orchestrator_state* kk_src_orchestrator__as_Orchestrator_state(kk_src_orchestrator__orchestrator_state x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_orchestrator_Orchestrator_state*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_orchestrator__is_Orchestrator_state(kk_src_orchestrator__orchestrator_state x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_orchestrator__orchestrator_state kk_src_orchestrator__orchestrator_state_dup(kk_src_orchestrator__orchestrator_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_orchestrator__orchestrator_state_drop(kk_src_orchestrator__orchestrator_state _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_orchestrator__orchestrator_state_box(kk_src_orchestrator__orchestrator_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_orchestrator__orchestrator_state kk_src_orchestrator__orchestrator_state_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `name` constructor field of the `:managed-process` type.

static inline kk_string_t kk_src_orchestrator_managed_process_fs_name(kk_src_orchestrator__managed_process _this, kk_context_t* _ctx) { /* (managed-process) -> string */ 
  {
    struct kk_src_orchestrator_Managed_process* _con_x392 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
    kk_string_t _x = _con_x392->name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `pid` constructor field of the `:managed-process` type.

static inline kk_integer_t kk_src_orchestrator_managed_process_fs_pid(kk_src_orchestrator__managed_process _this, kk_context_t* _ctx) { /* (managed-process) -> int */ 
  {
    struct kk_src_orchestrator_Managed_process* _con_x393 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
    kk_integer_t _x = _con_x393->pid;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `binary-path` constructor field of the `:managed-process` type.

static inline kk_string_t kk_src_orchestrator_managed_process_fs_binary_path(kk_src_orchestrator__managed_process _this, kk_context_t* _ctx) { /* (managed-process) -> string */ 
  {
    struct kk_src_orchestrator_Managed_process* _con_x394 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
    kk_string_t _x = _con_x394->binary_path;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `status` constructor field of the `:managed-process` type.

static inline kk_string_t kk_src_orchestrator_managed_process_fs_status(kk_src_orchestrator__managed_process _this, kk_context_t* _ctx) { /* (managed-process) -> string */ 
  {
    struct kk_src_orchestrator_Managed_process* _con_x395 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
    kk_string_t _x = _con_x395->status;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `start-time` constructor field of the `:managed-process` type.

static inline double kk_src_orchestrator_managed_process_fs_start_time(kk_src_orchestrator__managed_process _this, kk_context_t* _ctx) { /* (managed-process) -> float64 */ 
  {
    struct kk_src_orchestrator_Managed_process* _con_x396 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
    double _x = _con_x396->start_time;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `restart-count` constructor field of the `:managed-process` type.

static inline kk_integer_t kk_src_orchestrator_managed_process_fs_restart_count(kk_src_orchestrator__managed_process _this, kk_context_t* _ctx) { /* (managed-process) -> int */ 
  {
    struct kk_src_orchestrator_Managed_process* _con_x397 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
    kk_integer_t _x = _con_x397->restart_count;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_orchestrator__managed_process kk_src_orchestrator_managed_process_fs__copy(kk_src_orchestrator__managed_process _this, kk_std_core_types__optional name, kk_std_core_types__optional pid, kk_std_core_types__optional binary_path, kk_std_core_types__optional status, kk_std_core_types__optional start_time, kk_std_core_types__optional restart_count, kk_context_t* _ctx); /* (managed-process, name : ? string, pid : ? int, binary-path : ? string, status : ? string, start-time : ? float64, restart-count : ? int) -> managed-process */ 
 
// Automatically generated. Retrieves the `processes` constructor field of the `:orchestrator-state` type.

static inline kk_std_core_types__list kk_src_orchestrator_orchestrator_state_fs_processes(kk_src_orchestrator__orchestrator_state _this, kk_context_t* _ctx) { /* (orchestrator-state) -> list<managed-process> */ 
  {
    struct kk_src_orchestrator_Orchestrator_state* _con_x410 = kk_src_orchestrator__as_Orchestrator_state(_this, _ctx);
    kk_std_core_types__list _x = _con_x410->processes;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `total-restarts` constructor field of the `:orchestrator-state` type.

static inline kk_integer_t kk_src_orchestrator_orchestrator_state_fs_total_restarts(kk_src_orchestrator__orchestrator_state _this, kk_context_t* _ctx) { /* (orchestrator-state) -> int */ 
  {
    struct kk_src_orchestrator_Orchestrator_state* _con_x411 = kk_src_orchestrator__as_Orchestrator_state(_this, _ctx);
    kk_integer_t _x = _con_x411->total_restarts;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `last-health-check` constructor field of the `:orchestrator-state` type.

static inline double kk_src_orchestrator_orchestrator_state_fs_last_health_check(kk_src_orchestrator__orchestrator_state _this, kk_context_t* _ctx) { /* (orchestrator-state) -> float64 */ 
  {
    struct kk_src_orchestrator_Orchestrator_state* _con_x412 = kk_src_orchestrator__as_Orchestrator_state(_this, _ctx);
    double _x = _con_x412->last_health_check;
    return _x;
  }
}

kk_src_orchestrator__orchestrator_state kk_src_orchestrator_orchestrator_state_fs__copy(kk_src_orchestrator__orchestrator_state _this, kk_std_core_types__optional processes, kk_std_core_types__optional total_restarts, kk_std_core_types__optional last_health_check, kk_context_t* _ctx); /* (orchestrator-state, processes : ? (list<managed-process>), total-restarts : ? int, last-health-check : ? float64) -> orchestrator-state */ 

extern kk_std_core_types__list kk_src_orchestrator_binary_registry;

kk_std_core_types__maybe kk_src_orchestrator__lift_find_process_10242(kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10139, kk_context_t* _ctx); /* (proc-name : string, list<managed-process>) -> maybe<managed-process> */ 

kk_std_core_types__maybe kk_src_orchestrator__lift_find_process_10241(kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10130, kk_context_t* _ctx); /* (proc-name : string, list<managed-process>) -> maybe<managed-process> */ 

static inline kk_std_core_types__maybe kk_src_orchestrator_find_process(kk_string_t proc_name, kk_std_core_types__list processes, kk_context_t* _ctx) { /* (proc-name : string, processes : list<managed-process>) -> maybe<managed-process> */ 
  return kk_src_orchestrator__lift_find_process_10241(proc_name, processes, _ctx);
}

kk_std_core_types__list kk_src_orchestrator__trmc_lift_update_process_10244(kk_string_t new_status, kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10154, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (new-status : string, proc-name : string, list<managed-process>, ctx<list<managed-process>>) -> list<managed-process> */ 

kk_std_core_types__list kk_src_orchestrator__lift_update_process_10244(kk_string_t new_status_0, kk_string_t proc_name_0, kk_std_core_types__list _uniq_xs_10154_0, kk_context_t* _ctx); /* (new-status : string, proc-name : string, list<managed-process>) -> list<managed-process> */ 

kk_std_core_types__list kk_src_orchestrator__lift_update_process_10243(kk_string_t new_status, kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10149, kk_context_t* _ctx); /* (new-status : string, proc-name : string, list<managed-process>) -> list<managed-process> */ 

kk_src_orchestrator__orchestrator_state kk_src_orchestrator_update_process(kk_src_orchestrator__orchestrator_state state, kk_string_t proc_name, kk_string_t new_status, kk_context_t* _ctx); /* (state : orchestrator-state, proc-name : string, new-status : string) -> orchestrator-state */ 

kk_string_t kk_src_orchestrator_check_health(kk_src_orchestrator__managed_process process, kk_context_t* _ctx); /* (process : managed-process) -> string */ 

kk_std_core_types__list kk_src_orchestrator__trmc_lift_health_summary_10246(kk_std_core_types__list _uniq_xs_10167, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<managed-process>, ctx<list<managed-process>>) -> list<managed-process> */ 

kk_std_core_types__list kk_src_orchestrator__lift_health_summary_10246(kk_std_core_types__list _uniq_xs_10167_0, kk_context_t* _ctx); /* (list<managed-process>) -> list<managed-process> */ 

kk_std_core_types__list kk_src_orchestrator__lift_health_summary_10245(kk_std_core_types__list _uniq_xs_10162, kk_context_t* _ctx); /* (list<managed-process>) -> list<managed-process> */ 

kk_std_core_types__list kk_src_orchestrator__trmc_lift_health_summary_10248(kk_std_core_types__list _uniq_xs_10182, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<managed-process>, ctx<list<managed-process>>) -> list<managed-process> */ 

kk_std_core_types__list kk_src_orchestrator__lift_health_summary_10248(kk_std_core_types__list _uniq_xs_10182_0, kk_context_t* _ctx); /* (list<managed-process>) -> list<managed-process> */ 

kk_std_core_types__list kk_src_orchestrator__lift_health_summary_10247(kk_std_core_types__list _uniq_xs_10177, kk_context_t* _ctx); /* (list<managed-process>) -> list<managed-process> */ 

kk_string_t kk_src_orchestrator_health_summary(kk_src_orchestrator__orchestrator_state state, kk_context_t* _ctx); /* (state : orchestrator-state) -> string */ 

kk_string_t kk_src_orchestrator_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_string_t kk_src_orchestrator_extract_binary(kk_string_t cmd_line, kk_context_t* _ctx); /* (cmd-line : string) -> string */ 

kk_std_core_types__maybe kk_src_orchestrator__lift_server_loop_10250(kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10201, kk_context_t* _ctx); /* (proc-name : string, list<managed-process>) -> maybe<managed-process> */ 

kk_std_core_types__maybe kk_src_orchestrator__lift_server_loop_10249(kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10192, kk_context_t* _ctx); /* (proc-name : string, list<managed-process>) -> maybe<managed-process> */ 

kk_std_core_types__list kk_src_orchestrator__trmc_lift_server_loop_10252(kk_std_core_types__list _uniq_xs_10216, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<managed-process>, ctx<list<string>>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<string> */ 

kk_std_core_types__list kk_src_orchestrator__lift_server_loop_10252(kk_std_core_types__list _uniq_xs_10216_0, kk_context_t* _ctx); /* (list<managed-process>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<string> */ 

kk_std_core_types__list kk_src_orchestrator__lift_server_loop_10251(kk_std_core_types__list _uniq_xs_10211, kk_context_t* _ctx); /* (list<managed-process>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<string> */ 

kk_string_t kk_src_orchestrator__mlift_lift_server_loop_10253_10350(kk_std_core_types__list _c_x10274, kk_context_t* _ctx); /* (list<string>) -> string */ 

kk_string_t kk_src_orchestrator__lift_server_loop_10253(kk_std_core_types__list _uniq_xs_10224, kk_context_t* _ctx); /* (list<string>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */ 

kk_string_t kk_src_orchestrator__mlift_server_loop_10351(kk_src_orchestrator__orchestrator_state state, kk_string_t _y_x10282, kk_context_t* _ctx); /* (state : orchestrator-state, string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */ 

kk_string_t kk_src_orchestrator__mlift_server_loop_10352(kk_src_orchestrator__orchestrator_state state_0, kk_std_core_types__list names, kk_context_t* _ctx); /* (state : orchestrator-state, names : list<string>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */ 

kk_unit_t kk_src_orchestrator__mlift_server_loop_10353(kk_string_t binary, kk_string_t op, kk_src_orchestrator__orchestrator_state state_1, kk_string_t _c_x10283, kk_context_t* _ctx); /* (binary : string, op : string, state : orchestrator-state, string) -> () */ 

kk_unit_t kk_src_orchestrator__mlift_server_loop_10354(kk_src_orchestrator__orchestrator_state state_2, kk_string_t line, kk_context_t* _ctx); /* (state : orchestrator-state, line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_orchestrator_server_loop(kk_src_orchestrator__orchestrator_state state_3, kk_context_t* _ctx); /* (state : orchestrator-state) -> io () */ 

kk_unit_t kk_src_orchestrator_main(kk_context_t* _ctx); /* () -> io () */ 

void kk_src_orchestrator__init(kk_context_t* _ctx);


void kk_src_orchestrator__done(kk_context_t* _ctx);

#endif // header
