// Koka generated module: src/orchestrator, koka version: 3.2.2, platform: 64-bit
#include "src_orchestrator.h"

kk_src_orchestrator__managed_process kk_src_orchestrator_managed_process_fs__copy(kk_src_orchestrator__managed_process _this, kk_std_core_types__optional name, kk_std_core_types__optional pid, kk_std_core_types__optional binary_path, kk_std_core_types__optional status, kk_std_core_types__optional start_time, kk_std_core_types__optional restart_count, kk_context_t* _ctx) { /* (managed-process, name : ? string, pid : ? int, binary-path : ? string, status : ? string, start-time : ? float64, restart-count : ? int) -> managed-process */ 
  kk_string_t _x_x398;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x0 = name._cons._Optional.value;
    kk_string_t _uniq_name_83 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_name_83, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x398 = _uniq_name_83; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_src_orchestrator_Managed_process* _con_x399 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
      kk_string_t _x = _con_x399->name;
      kk_string_dup(_x, _ctx);
      _x_x398 = _x; /*string*/
    }
  }
  kk_integer_t _x_x400;
  if (kk_std_core_types__is_Optional(pid, _ctx)) {
    kk_box_t _box_x1 = pid._cons._Optional.value;
    kk_integer_t _uniq_pid_91 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_pid_91, _ctx);
    kk_std_core_types__optional_drop(pid, _ctx);
    _x_x400 = _uniq_pid_91; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(pid, _ctx);
    {
      struct kk_src_orchestrator_Managed_process* _con_x401 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
      kk_integer_t _x_0 = _con_x401->pid;
      kk_integer_dup(_x_0, _ctx);
      _x_x400 = _x_0; /*int*/
    }
  }
  kk_string_t _x_x402;
  if (kk_std_core_types__is_Optional(binary_path, _ctx)) {
    kk_box_t _box_x2 = binary_path._cons._Optional.value;
    kk_string_t _uniq_binary_path_99 = kk_string_unbox(_box_x2);
    kk_string_dup(_uniq_binary_path_99, _ctx);
    kk_std_core_types__optional_drop(binary_path, _ctx);
    _x_x402 = _uniq_binary_path_99; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(binary_path, _ctx);
    {
      struct kk_src_orchestrator_Managed_process* _con_x403 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
      kk_string_t _x_1 = _con_x403->binary_path;
      kk_string_dup(_x_1, _ctx);
      _x_x402 = _x_1; /*string*/
    }
  }
  kk_string_t _x_x404;
  if (kk_std_core_types__is_Optional(status, _ctx)) {
    kk_box_t _box_x3 = status._cons._Optional.value;
    kk_string_t _uniq_status_107 = kk_string_unbox(_box_x3);
    kk_string_dup(_uniq_status_107, _ctx);
    kk_std_core_types__optional_drop(status, _ctx);
    _x_x404 = _uniq_status_107; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(status, _ctx);
    {
      struct kk_src_orchestrator_Managed_process* _con_x405 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
      kk_string_t _x_2 = _con_x405->status;
      kk_string_dup(_x_2, _ctx);
      _x_x404 = _x_2; /*string*/
    }
  }
  double _x_x406;
  if (kk_std_core_types__is_Optional(start_time, _ctx)) {
    kk_box_t _box_x4 = start_time._cons._Optional.value;
    double _uniq_start_time_115 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(start_time, _ctx);
    _x_x406 = _uniq_start_time_115; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(start_time, _ctx);
    {
      struct kk_src_orchestrator_Managed_process* _con_x407 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
      double _x_3 = _con_x407->start_time;
      _x_x406 = _x_3; /*float64*/
    }
  }
  kk_integer_t _x_x408;
  if (kk_std_core_types__is_Optional(restart_count, _ctx)) {
    kk_box_t _box_x5 = restart_count._cons._Optional.value;
    kk_integer_t _uniq_restart_count_123 = kk_integer_unbox(_box_x5, _ctx);
    kk_integer_dup(_uniq_restart_count_123, _ctx);
    kk_std_core_types__optional_drop(restart_count, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(5)), _ctx);
    _x_x408 = _uniq_restart_count_123; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(restart_count, _ctx);
    {
      struct kk_src_orchestrator_Managed_process* _con_x409 = kk_src_orchestrator__as_Managed_process(_this, _ctx);
      kk_string_t _pat_0_5 = _con_x409->name;
      kk_integer_t _pat_1_6 = _con_x409->pid;
      kk_string_t _pat_2_5 = _con_x409->binary_path;
      kk_string_t _pat_3_5 = _con_x409->status;
      kk_integer_t _x_4 = _con_x409->restart_count;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_3_5, _ctx);
        kk_string_drop(_pat_2_5, _ctx);
        kk_integer_drop(_pat_1_6, _ctx);
        kk_string_drop(_pat_0_5, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_4, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x408 = _x_4; /*int*/
    }
  }
  return kk_src_orchestrator__new_Managed_process(kk_reuse_null, 0, _x_x398, _x_x400, _x_x402, _x_x404, _x_x406, _x_x408, _ctx);
}

kk_src_orchestrator__orchestrator_state kk_src_orchestrator_orchestrator_state_fs__copy(kk_src_orchestrator__orchestrator_state _this, kk_std_core_types__optional processes, kk_std_core_types__optional total_restarts, kk_std_core_types__optional last_health_check, kk_context_t* _ctx) { /* (orchestrator-state, processes : ? (list<managed-process>), total-restarts : ? int, last-health-check : ? float64) -> orchestrator-state */ 
  kk_std_core_types__list _x_x413;
  if (kk_std_core_types__is_Optional(processes, _ctx)) {
    kk_box_t _box_x6 = processes._cons._Optional.value;
    kk_std_core_types__list _uniq_processes_168 = kk_std_core_types__list_unbox(_box_x6, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_processes_168, _ctx);
    kk_std_core_types__optional_drop(processes, _ctx);
    _x_x413 = _uniq_processes_168; /*list<src/orchestrator/managed-process>*/
  }
  else {
    kk_std_core_types__optional_drop(processes, _ctx);
    {
      struct kk_src_orchestrator_Orchestrator_state* _con_x414 = kk_src_orchestrator__as_Orchestrator_state(_this, _ctx);
      kk_std_core_types__list _x = _con_x414->processes;
      kk_std_core_types__list_dup(_x, _ctx);
      _x_x413 = _x; /*list<src/orchestrator/managed-process>*/
    }
  }
  kk_integer_t _x_x415;
  if (kk_std_core_types__is_Optional(total_restarts, _ctx)) {
    kk_box_t _box_x7 = total_restarts._cons._Optional.value;
    kk_integer_t _uniq_total_restarts_176 = kk_integer_unbox(_box_x7, _ctx);
    kk_integer_dup(_uniq_total_restarts_176, _ctx);
    kk_std_core_types__optional_drop(total_restarts, _ctx);
    _x_x415 = _uniq_total_restarts_176; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(total_restarts, _ctx);
    {
      struct kk_src_orchestrator_Orchestrator_state* _con_x416 = kk_src_orchestrator__as_Orchestrator_state(_this, _ctx);
      kk_integer_t _x_0 = _con_x416->total_restarts;
      kk_integer_dup(_x_0, _ctx);
      _x_x415 = _x_0; /*int*/
    }
  }
  double _x_x417;
  if (kk_std_core_types__is_Optional(last_health_check, _ctx)) {
    kk_box_t _box_x8 = last_health_check._cons._Optional.value;
    double _uniq_last_health_check_184 = kk_double_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(last_health_check, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x417 = _uniq_last_health_check_184; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(last_health_check, _ctx);
    {
      struct kk_src_orchestrator_Orchestrator_state* _con_x418 = kk_src_orchestrator__as_Orchestrator_state(_this, _ctx);
      kk_std_core_types__list _pat_0_2 = _con_x418->processes;
      kk_integer_t _pat_1_3 = _con_x418->total_restarts;
      double _x_1 = _con_x418->last_health_check;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_3, _ctx);
        kk_std_core_types__list_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x417 = _x_1; /*float64*/
    }
  }
  return kk_src_orchestrator__new_Orchestrator_state(kk_reuse_null, 0, _x_x413, _x_x415, _x_x417, _ctx);
}

kk_std_core_types__list kk_src_orchestrator_binary_registry;
 
// lifted local: @lift-find-process@10241, find-process, @spec-x10147
// specialized: std/core/list/@unroll-foreach-while@10009, on parameters @uniq-action@10140, using:
// @uniq-action@10140 = fn(@uniq-x@10134: src/orchestrator/managed-process){
//   match (val p@10138 : src/orchestrator/managed-process
//                = @uniq-x@10134;
//   (std/core/string/(==)((match (p@10138) {
//       ((@skip src/orchestrator/Managed-process((@x: string) : string, (@pat@0: int) : int, (@pat@1: string) : string, (@pat@2: string) : string, (@pat@3: float64) : float64, (@pat@4: int) : int) : src/orchestrator/managed-process ) as @pat: src/orchestrator/managed-process)
//          -> @x;
//     }), proc-name))) {
//     ((std/core/types/True() : bool ) as @uniq-pat@1@10135: bool)
//        -> std/core/types/Just<src/orchestrator/managed-process>(@uniq-x@10134);
//     ((@skip std/core/types/False() : bool ) as @uniq-pat@0@0@10136: bool)
//        -> std/core/types/Nothing<src/orchestrator/managed-process>;
//   };
// }

kk_std_core_types__maybe kk_src_orchestrator__lift_find_process_10242(kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10139, kk_context_t* _ctx) { /* (proc-name : string, list<managed-process>) -> maybe<managed-process> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_xs_10139, _ctx)) {
    kk_string_drop(proc_name, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x490 = kk_std_core_types__as_Cons(_uniq_xs_10139, _ctx);
    kk_box_t _box_x73 = _con_x490->head;
    kk_std_core_types__list _uniq_xx_10144 = _con_x490->tail;
    kk_src_orchestrator__managed_process _uniq_x_10143 = kk_src_orchestrator__managed_process_unbox(_box_x73, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10139, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10139, _ctx);
    }
    else {
      kk_src_orchestrator__managed_process_dup(_uniq_x_10143, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10144, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10139, _ctx);
    }
    bool _match_x349;
    kk_string_t _x_x491;
    {
      struct kk_src_orchestrator_Managed_process* _con_x492 = kk_src_orchestrator__as_Managed_process(_uniq_x_10143, _ctx);
      kk_string_t _x = _con_x492->name;
      kk_string_dup(_x, _ctx);
      _x_x491 = _x; /*string*/
    }
    kk_string_t _x_x493 = kk_string_dup(proc_name, _ctx); /*string*/
    _match_x349 = kk_string_is_eq(_x_x491,_x_x493,kk_context()); /*bool*/
    if (_match_x349) {
      kk_string_drop(proc_name, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10144, _ctx);
      return kk_std_core_types__new_Just(kk_src_orchestrator__managed_process_box(_uniq_x_10143, _ctx), _ctx);
    }
    {
      kk_datatype_ptr_dropn(_uniq_x_10143, (KK_I32(5)), _ctx);
      { // tailcall
        _uniq_xs_10139 = _uniq_xx_10144;
        goto kk__tailcall;
      }
    }
  }
}
 
// lifted local: find-process, @spec-x10137
// specialized: std/core/list/find, on parameters @uniq-pred@10131, using:
// @uniq-pred@10131 = fn(p: src/orchestrator/managed-process){
//   std/core/string/(==)((match (p) {
//       ((@skip src/orchestrator/Managed-process((@x: string) : string, (@pat@0: int) : int, (@pat@1: string) : string, (@pat@2: string) : string, (@pat@3: float64) : float64, (@pat@4: int) : int) : src/orchestrator/managed-process ) as @pat: src/orchestrator/managed-process)
//          -> @x;
//     }), proc-name);
// }

kk_std_core_types__maybe kk_src_orchestrator__lift_find_process_10241(kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10130, kk_context_t* _ctx) { /* (proc-name : string, list<managed-process>) -> maybe<managed-process> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10130, _ctx)) {
    kk_string_drop(proc_name, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    return kk_src_orchestrator__lift_find_process_10242(proc_name, _uniq_xs_10130, _ctx);
  }
}
 
// lifted local: @lift-update-process@10243, update-process, @spec-x10160
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10155, using:
// @uniq-f@10155 = fn(p: src/orchestrator/managed-process){
//   match ((std/core/string/(==)((match (p) {
//       ((@skip src/orchestrator/Managed-process((@x@0: string) : string, (@pat@0@0: int) : int, (@pat@1@0: string) : string, (@pat@2@0: string) : string, (@pat@3: float64) : float64, (@pat@4: int) : int) : src/orchestrator/managed-process ) as @pat@2: src/orchestrator/managed-process)
//          -> @x@0;
//     }), proc-name))) {
//     ((std/core/types/True() : bool ) as @pat@5: bool)
//        -> src/orchestrator/Managed-process((match (p) {
//           ((@skip src/orchestrator/Managed-process((@x@1: string) : string, (@pat@0@1: int) : int, (@pat@1@1: string) : string, (@pat@2@1: string) : string, (@pat@3@0: float64) : float64, (@pat@4@0: int) : int) : src/orchestrator/managed-process ) as @pat@6: src/orchestrator/managed-process)
//              -> @x@1;
//         }), (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@2: string) : string, (@x@2: int) : int, (@pat@1@2: string) : string, (@pat@2@2: string) : string, (@pat@3@1: float64) : float64, (@pat@4@1: int) : int) : src/orchestrator/managed-process ) as @pat@7: src/orchestrator/managed-process)
//              -> @x@2;
//         }), (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@3: string) : string, (@pat@1@3: int) : int, (@x@3: string) : string, (@pat@2@3: string) : string, (@pat@3@2: float64) : float64, (@pat@4@2: int) : int) : src/orchestrator/managed-process ) as @pat@8: src/orchestrator/managed-process)
//              -> @x@3;
//         }), new-status, (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@4: string) : string, (@pat@1@4: int) : int, (@pat@2@4: string) : string, (@pat@3@3: string) : string, (@x@4: float64) : float64, (@pat@4@3: int) : int) : src/orchestrator/managed-process ) as @pat@9: src/orchestrator/managed-process)
//              -> @x@4;
//         }), (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@5: string) : string, (@pat@1@5: int) : int, (@pat@2@5: string) : string, (@pat@3@4: string) : string, (@pat@4@4: float64) : float64, (@x@5: int) : int) : src/orchestrator/managed-process ) as @pat@10: src/orchestrator/managed-process)
//              -> @x@5;
//         }));
//     ((@skip std/core/types/False() : bool ) as @pat@0@6: bool)
//        -> p;
//   };
// }

kk_std_core_types__list kk_src_orchestrator__trmc_lift_update_process_10244(kk_string_t new_status, kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10154, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (new-status : string, proc-name : string, list<managed-process>, ctx<list<managed-process>>) -> list<managed-process> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10154, _ctx)) {
    struct kk_std_core_types_Cons* _con_x494 = kk_std_core_types__as_Cons(_uniq_xs_10154, _ctx);
    kk_box_t _box_x76 = _con_x494->head;
    kk_std_core_types__list _uniq_xx_10158 = _con_x494->tail;
    kk_src_orchestrator__managed_process _uniq_x_10157 = kk_src_orchestrator__managed_process_unbox(_box_x76, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x356 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10154, _ctx)) {
      _ru_x356 = (kk_datatype_ptr_reuse(_uniq_xs_10154, _ctx));
    }
    else {
      kk_src_orchestrator__managed_process_dup(_uniq_x_10157, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10158, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10154, _ctx);
    }
    kk_src_orchestrator__managed_process _trmc_x10258;
    bool _match_x348;
    kk_string_t _x_x495;
    {
      struct kk_src_orchestrator_Managed_process* _con_x496 = kk_src_orchestrator__as_Managed_process(_uniq_x_10157, _ctx);
      kk_string_t _x_0 = _con_x496->name;
      kk_string_dup(_x_0, _ctx);
      _x_x495 = _x_0; /*string*/
    }
    kk_string_t _x_x497 = kk_string_dup(proc_name, _ctx); /*string*/
    _match_x348 = kk_string_is_eq(_x_x495,_x_x497,kk_context()); /*bool*/
    if (_match_x348) {
      kk_string_t _x_x498;
      {
        struct kk_src_orchestrator_Managed_process* _con_x499 = kk_src_orchestrator__as_Managed_process(_uniq_x_10157, _ctx);
        kk_string_t _x_1 = _con_x499->name;
        kk_string_dup(_x_1, _ctx);
        _x_x498 = _x_1; /*string*/
      }
      kk_integer_t _x_x500;
      {
        struct kk_src_orchestrator_Managed_process* _con_x501 = kk_src_orchestrator__as_Managed_process(_uniq_x_10157, _ctx);
        kk_integer_t _x_2 = _con_x501->pid;
        kk_integer_dup(_x_2, _ctx);
        _x_x500 = _x_2; /*int*/
      }
      kk_string_t _x_x502;
      {
        struct kk_src_orchestrator_Managed_process* _con_x503 = kk_src_orchestrator__as_Managed_process(_uniq_x_10157, _ctx);
        kk_string_t _x_3 = _con_x503->binary_path;
        kk_string_dup(_x_3, _ctx);
        _x_x502 = _x_3; /*string*/
      }
      kk_string_t _x_x504 = kk_string_dup(new_status, _ctx); /*string*/
      double _x_x505;
      {
        struct kk_src_orchestrator_Managed_process* _con_x506 = kk_src_orchestrator__as_Managed_process(_uniq_x_10157, _ctx);
        double _x_4 = _con_x506->start_time;
        _x_x505 = _x_4; /*float64*/
      }
      kk_integer_t _x_x507;
      {
        struct kk_src_orchestrator_Managed_process* _con_x508 = kk_src_orchestrator__as_Managed_process(_uniq_x_10157, _ctx);
        kk_string_t _pat_0_5 = _con_x508->name;
        kk_integer_t _pat_1_5 = _con_x508->pid;
        kk_string_t _pat_2_5 = _con_x508->binary_path;
        kk_string_t _pat_3_4 = _con_x508->status;
        kk_integer_t _x_5 = _con_x508->restart_count;
        if kk_likely(kk_datatype_ptr_is_unique(_uniq_x_10157, _ctx)) {
          kk_string_drop(_pat_3_4, _ctx);
          kk_string_drop(_pat_2_5, _ctx);
          kk_integer_drop(_pat_1_5, _ctx);
          kk_string_drop(_pat_0_5, _ctx);
          kk_datatype_ptr_free(_uniq_x_10157, _ctx);
        }
        else {
          kk_integer_dup(_x_5, _ctx);
          kk_datatype_ptr_decref(_uniq_x_10157, _ctx);
        }
        _x_x507 = _x_5; /*int*/
      }
      _trmc_x10258 = kk_src_orchestrator__new_Managed_process(kk_reuse_null, 0, _x_x498, _x_x500, _x_x502, _x_x504, _x_x505, _x_x507, _ctx); /*src/orchestrator/managed-process*/
    }
    else {
      _trmc_x10258 = _uniq_x_10157; /*src/orchestrator/managed-process*/
    }
    kk_std_core_types__list _trmc_x10259 = kk_datatype_null(); /*list<src/orchestrator/managed-process>*/;
    kk_std_core_types__list _trmc_x10260 = kk_std_core_types__new_Cons(_ru_x356, 0, kk_src_orchestrator__managed_process_box(_trmc_x10258, _ctx), _trmc_x10259, _ctx); /*list<src/orchestrator/managed-process>*/;
    kk_field_addr_t _b_x86_91 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10260, _ctx)->tail, _ctx); /*@field-addr<list<src/orchestrator/managed-process>>*/;
    kk_std_core_types__cctx _brw_x346;
    kk_std_core_types__cctx _x_x509 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<src/orchestrator/managed-process>>*/
    _brw_x346 = kk_cctx_extend_linear(_x_x509,(kk_std_core_types__list_box(_trmc_x10260, _ctx)),_b_x86_91,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x347 = kk_src_orchestrator__trmc_lift_update_process_10244(new_status, proc_name, _uniq_xx_10158, _brw_x346, _ctx); /*list<src/orchestrator/managed-process>*/;
    kk_std_core_types__cctx_drop(_brw_x346, _ctx);
    return _brw_x347;
  }
  {
    kk_string_drop(proc_name, _ctx);
    kk_string_drop(new_status, _ctx);
    kk_box_t _x_x510;
    kk_std_core_types__cctx _x_x511 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<src/orchestrator/managed-process>>*/
    _x_x510 = kk_cctx_apply_linear(_x_x511,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x510, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-update-process@10243, update-process, @spec-x10160
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10155, using:
// @uniq-f@10155 = fn(p: src/orchestrator/managed-process){
//   match ((std/core/string/(==)((match (p) {
//       ((@skip src/orchestrator/Managed-process((@x@0: string) : string, (@pat@0@0: int) : int, (@pat@1@0: string) : string, (@pat@2@0: string) : string, (@pat@3: float64) : float64, (@pat@4: int) : int) : src/orchestrator/managed-process ) as @pat@2: src/orchestrator/managed-process)
//          -> @x@0;
//     }), proc-name))) {
//     ((std/core/types/True() : bool ) as @pat@5: bool)
//        -> src/orchestrator/Managed-process((match (p) {
//           ((@skip src/orchestrator/Managed-process((@x@1: string) : string, (@pat@0@1: int) : int, (@pat@1@1: string) : string, (@pat@2@1: string) : string, (@pat@3@0: float64) : float64, (@pat@4@0: int) : int) : src/orchestrator/managed-process ) as @pat@6: src/orchestrator/managed-process)
//              -> @x@1;
//         }), (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@2: string) : string, (@x@2: int) : int, (@pat@1@2: string) : string, (@pat@2@2: string) : string, (@pat@3@1: float64) : float64, (@pat@4@1: int) : int) : src/orchestrator/managed-process ) as @pat@7: src/orchestrator/managed-process)
//              -> @x@2;
//         }), (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@3: string) : string, (@pat@1@3: int) : int, (@x@3: string) : string, (@pat@2@3: string) : string, (@pat@3@2: float64) : float64, (@pat@4@2: int) : int) : src/orchestrator/managed-process ) as @pat@8: src/orchestrator/managed-process)
//              -> @x@3;
//         }), new-status, (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@4: string) : string, (@pat@1@4: int) : int, (@pat@2@4: string) : string, (@pat@3@3: string) : string, (@x@4: float64) : float64, (@pat@4@3: int) : int) : src/orchestrator/managed-process ) as @pat@9: src/orchestrator/managed-process)
//              -> @x@4;
//         }), (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@5: string) : string, (@pat@1@5: int) : int, (@pat@2@5: string) : string, (@pat@3@4: string) : string, (@pat@4@4: float64) : float64, (@x@5: int) : int) : src/orchestrator/managed-process ) as @pat@10: src/orchestrator/managed-process)
//              -> @x@5;
//         }));
//     ((@skip std/core/types/False() : bool ) as @pat@0@6: bool)
//        -> p;
//   };
// }

kk_std_core_types__list kk_src_orchestrator__lift_update_process_10244(kk_string_t new_status_0, kk_string_t proc_name_0, kk_std_core_types__list _uniq_xs_10154_0, kk_context_t* _ctx) { /* (new-status : string, proc-name : string, list<managed-process>) -> list<managed-process> */ 
  kk_std_core_types__cctx _brw_x344 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x345 = kk_src_orchestrator__trmc_lift_update_process_10244(new_status_0, proc_name_0, _uniq_xs_10154_0, _brw_x344, _ctx); /*list<src/orchestrator/managed-process>*/;
  kk_std_core_types__cctx_drop(_brw_x344, _ctx);
  return _brw_x345;
}
 
// lifted local: update-process, @spec-x10153
// specialized: std/core/list/map, on parameters @uniq-f@10150, using:
// @uniq-f@10150 = fn(p: src/orchestrator/managed-process){
//   match ((std/core/string/(==)((match (p) {
//       ((@skip src/orchestrator/Managed-process((@x@0: string) : string, (@pat@0@0: int) : int, (@pat@1@0: string) : string, (@pat@2@0: string) : string, (@pat@3: float64) : float64, (@pat@4: int) : int) : src/orchestrator/managed-process ) as @pat@2: src/orchestrator/managed-process)
//          -> @x@0;
//     }), proc-name))) {
//     ((std/core/types/True() : bool ) as @pat@5: bool)
//        -> src/orchestrator/Managed-process((match (p) {
//           ((@skip src/orchestrator/Managed-process((@x@1: string) : string, (@pat@0@1: int) : int, (@pat@1@1: string) : string, (@pat@2@1: string) : string, (@pat@3@0: float64) : float64, (@pat@4@0: int) : int) : src/orchestrator/managed-process ) as @pat@6: src/orchestrator/managed-process)
//              -> @x@1;
//         }), (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@2: string) : string, (@x@2: int) : int, (@pat@1@2: string) : string, (@pat@2@2: string) : string, (@pat@3@1: float64) : float64, (@pat@4@1: int) : int) : src/orchestrator/managed-process ) as @pat@7: src/orchestrator/managed-process)
//              -> @x@2;
//         }), (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@3: string) : string, (@pat@1@3: int) : int, (@x@3: string) : string, (@pat@2@3: string) : string, (@pat@3@2: float64) : float64, (@pat@4@2: int) : int) : src/orchestrator/managed-process ) as @pat@8: src/orchestrator/managed-process)
//              -> @x@3;
//         }), new-status, (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@4: string) : string, (@pat@1@4: int) : int, (@pat@2@4: string) : string, (@pat@3@3: string) : string, (@x@4: float64) : float64, (@pat@4@3: int) : int) : src/orchestrator/managed-process ) as @pat@9: src/orchestrator/managed-process)
//              -> @x@4;
//         }), (match (p) {
//           ((@skip src/orchestrator/Managed-process((@pat@0@5: string) : string, (@pat@1@5: int) : int, (@pat@2@5: string) : string, (@pat@3@4: string) : string, (@pat@4@4: float64) : float64, (@x@5: int) : int) : src/orchestrator/managed-process ) as @pat@10: src/orchestrator/managed-process)
//              -> @x@5;
//         }));
//     ((@skip std/core/types/False() : bool ) as @pat@0@6: bool)
//        -> p;
//   };
// }

kk_std_core_types__list kk_src_orchestrator__lift_update_process_10243(kk_string_t new_status, kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10149, kk_context_t* _ctx) { /* (new-status : string, proc-name : string, list<managed-process>) -> list<managed-process> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10149, _ctx)) {
    kk_string_drop(proc_name, _ctx);
    kk_string_drop(new_status, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x342 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x343 = kk_src_orchestrator__trmc_lift_update_process_10244(new_status, proc_name, _uniq_xs_10149, _brw_x342, _ctx); /*list<src/orchestrator/managed-process>*/;
    kk_std_core_types__cctx_drop(_brw_x342, _ctx);
    return _brw_x343;
  }
}

kk_src_orchestrator__orchestrator_state kk_src_orchestrator_update_process(kk_src_orchestrator__orchestrator_state state, kk_string_t proc_name, kk_string_t new_status, kk_context_t* _ctx) { /* (state : orchestrator-state, proc-name : string, new-status : string) -> orchestrator-state */ 
  kk_std_core_types__list new_processes;
  kk_std_core_types__list _x_x512;
  {
    struct kk_src_orchestrator_Orchestrator_state* _con_x513 = kk_src_orchestrator__as_Orchestrator_state(state, _ctx);
    kk_std_core_types__list _x = _con_x513->processes;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x512 = _x; /*list<src/orchestrator/managed-process>*/
  }
  new_processes = kk_src_orchestrator__lift_update_process_10243(new_status, proc_name, _x_x512, _ctx); /*list<src/orchestrator/managed-process>*/
  kk_integer_t _x_x514;
  {
    struct kk_src_orchestrator_Orchestrator_state* _con_x515 = kk_src_orchestrator__as_Orchestrator_state(state, _ctx);
    kk_integer_t _x_6 = _con_x515->total_restarts;
    kk_integer_dup(_x_6, _ctx);
    _x_x514 = _x_6; /*int*/
  }
  double _x_x516;
  {
    struct kk_src_orchestrator_Orchestrator_state* _con_x517 = kk_src_orchestrator__as_Orchestrator_state(state, _ctx);
    kk_std_core_types__list _pat_0_8 = _con_x517->processes;
    kk_integer_t _pat_1_7 = _con_x517->total_restarts;
    double _x_7 = _con_x517->last_health_check;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_1_7, _ctx);
      kk_std_core_types__list_drop(_pat_0_8, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x516 = _x_7; /*float64*/
  }
  return kk_src_orchestrator__new_Orchestrator_state(kk_reuse_null, 0, new_processes, _x_x514, _x_x516, _ctx);
}

kk_string_t kk_src_orchestrator_check_health(kk_src_orchestrator__managed_process process, kk_context_t* _ctx) { /* (process : managed-process) -> string */ 
  bool _match_x340;
  kk_string_t _x_x518;
  {
    struct kk_src_orchestrator_Managed_process* _con_x519 = kk_src_orchestrator__as_Managed_process(process, _ctx);
    kk_string_t _x = _con_x519->status;
    kk_string_dup(_x, _ctx);
    _x_x518 = _x; /*string*/
  }
  kk_string_t _x_x520;
  kk_define_string_literal(, _s_x521, 7, "running", _ctx)
  _x_x520 = kk_string_dup(_s_x521, _ctx); /*string*/
  _match_x340 = kk_string_is_eq(_x_x518,_x_x520,kk_context()); /*bool*/
  if (_match_x340) {
    kk_datatype_ptr_dropn(process, (KK_I32(5)), _ctx);
    kk_define_string_literal(, _s_x522, 7, "healthy", _ctx)
    return kk_string_dup(_s_x522, _ctx);
  }
  {
    bool _match_x341;
    kk_string_t _x_x523;
    {
      struct kk_src_orchestrator_Managed_process* _con_x524 = kk_src_orchestrator__as_Managed_process(process, _ctx);
      kk_string_t _pat_0_1 = _con_x524->name;
      kk_integer_t _pat_1_0 = _con_x524->pid;
      kk_string_t _pat_2_0 = _con_x524->binary_path;
      kk_string_t _x_0 = _con_x524->status;
      kk_integer_t _pat_4_0 = _con_x524->restart_count;
      if kk_likely(kk_datatype_ptr_is_unique(process, _ctx)) {
        kk_integer_drop(_pat_4_0, _ctx);
        kk_string_drop(_pat_2_0, _ctx);
        kk_integer_drop(_pat_1_0, _ctx);
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(process, _ctx);
      }
      else {
        kk_string_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(process, _ctx);
      }
      _x_x523 = _x_0; /*string*/
    }
    kk_string_t _x_x525;
    kk_define_string_literal(, _s_x526, 7, "crashed", _ctx)
    _x_x525 = kk_string_dup(_s_x526, _ctx); /*string*/
    _match_x341 = kk_string_is_eq(_x_x523,_x_x525,kk_context()); /*bool*/
    if (_match_x341) {
      kk_define_string_literal(, _s_x527, 9, "unhealthy", _ctx)
      return kk_string_dup(_s_x527, _ctx);
    }
    {
      kk_define_string_literal(, _s_x528, 7, "unknown", _ctx)
      return kk_string_dup(_s_x528, _ctx);
    }
  }
}
 
// lifted local: @lift-health-summary@10245, health-summary, @spec-x10175
// specialized: std/core/list/@unroll-filter@10007, on parameters @uniq-pred@10168, using:
// @uniq-pred@10168 = fn(p: src/orchestrator/managed-process){
//   std/core/string/(==)((match (p) {
//       ((@skip src/orchestrator/Managed-process((@pat@0@2: string) : string, (@pat@1@3: int) : int, (@pat@2@0: string) : string, (@x@1: string) : string, (@pat@3@0: float64) : float64, (@pat@4@0: int) : int) : src/orchestrator/managed-process ) as @pat@4: src/orchestrator/managed-process)
//          -> @x@1;
//     }), "running");
// }

kk_std_core_types__list kk_src_orchestrator__trmc_lift_health_summary_10246(kk_std_core_types__list _uniq_xs_10167, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<managed-process>, ctx<list<managed-process>>) -> list<managed-process> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10167, _ctx)) {
    struct kk_std_core_types_Cons* _con_x529 = kk_std_core_types__as_Cons(_uniq_xs_10167, _ctx);
    kk_box_t _box_x97 = _con_x529->head;
    kk_std_core_types__list _uniq_xx_10171 = _con_x529->tail;
    kk_src_orchestrator__managed_process _uniq_x_10170 = kk_src_orchestrator__managed_process_unbox(_box_x97, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x361 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10167, _ctx)) {
      _ru_x361 = (kk_datatype_ptr_reuse(_uniq_xs_10167, _ctx));
    }
    else {
      kk_src_orchestrator__managed_process_dup(_uniq_x_10170, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10171, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10167, _ctx);
    }
    bool _match_x339;
    kk_string_t _x_x530;
    {
      struct kk_src_orchestrator_Managed_process* _con_x531 = kk_src_orchestrator__as_Managed_process(_uniq_x_10170, _ctx);
      kk_string_t _x_1 = _con_x531->status;
      kk_string_dup(_x_1, _ctx);
      _x_x530 = _x_1; /*string*/
    }
    kk_string_t _x_x532;
    kk_define_string_literal(, _s_x533, 7, "running", _ctx)
    _x_x532 = kk_string_dup(_s_x533, _ctx); /*string*/
    _match_x339 = kk_string_is_eq(_x_x530,_x_x532,kk_context()); /*bool*/
    if (_match_x339) {
      kk_std_core_types__list _trmc_x10261 = kk_datatype_null(); /*list<src/orchestrator/managed-process>*/;
      kk_std_core_types__list _trmc_x10262 = kk_std_core_types__new_Cons(_ru_x361, 0, kk_src_orchestrator__managed_process_box(_uniq_x_10170, _ctx), _trmc_x10261, _ctx); /*list<src/orchestrator/managed-process>*/;
      kk_field_addr_t _b_x107_112 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10262, _ctx)->tail, _ctx); /*@field-addr<list<src/orchestrator/managed-process>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x534 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10262, _ctx)),_b_x107_112,kk_context()); /*ctx<0>*/
        _uniq_xs_10167 = _uniq_xx_10171;
        _acc = _x_x534;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x361,kk_context());
      kk_datatype_ptr_dropn(_uniq_x_10170, (KK_I32(5)), _ctx);
      { // tailcall
        _uniq_xs_10167 = _uniq_xx_10171;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x535 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x535, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-health-summary@10245, health-summary, @spec-x10175
// specialized: std/core/list/@unroll-filter@10007, on parameters @uniq-pred@10168, using:
// @uniq-pred@10168 = fn(p: src/orchestrator/managed-process){
//   std/core/string/(==)((match (p) {
//       ((@skip src/orchestrator/Managed-process((@pat@0@2: string) : string, (@pat@1@3: int) : int, (@pat@2@0: string) : string, (@x@1: string) : string, (@pat@3@0: float64) : float64, (@pat@4@0: int) : int) : src/orchestrator/managed-process ) as @pat@4: src/orchestrator/managed-process)
//          -> @x@1;
//     }), "running");
// }

kk_std_core_types__list kk_src_orchestrator__lift_health_summary_10246(kk_std_core_types__list _uniq_xs_10167_0, kk_context_t* _ctx) { /* (list<managed-process>) -> list<managed-process> */ 
  kk_std_core_types__cctx _x_x536 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_src_orchestrator__trmc_lift_health_summary_10246(_uniq_xs_10167_0, _x_x536, _ctx);
}
 
// lifted local: health-summary, @spec-x10166
// specialized: std/core/list/filter, on parameters @uniq-pred@10163, using:
// @uniq-pred@10163 = fn(p: src/orchestrator/managed-process){
//   std/core/string/(==)((match (p) {
//       ((@skip src/orchestrator/Managed-process((@pat@0@2: string) : string, (@pat@1@3: int) : int, (@pat@2@0: string) : string, (@x@1: string) : string, (@pat@3@0: float64) : float64, (@pat@4@0: int) : int) : src/orchestrator/managed-process ) as @pat@4: src/orchestrator/managed-process)
//          -> @x@1;
//     }), "running");
// }

kk_std_core_types__list kk_src_orchestrator__lift_health_summary_10245(kk_std_core_types__list _uniq_xs_10162, kk_context_t* _ctx) { /* (list<managed-process>) -> list<managed-process> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10162, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x537 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_src_orchestrator__trmc_lift_health_summary_10246(_uniq_xs_10162, _x_x537, _ctx);
  }
}
 
// lifted local: @lift-health-summary@10247, health-summary, @spec-x10190
// specialized: std/core/list/@unroll-filter@10007, on parameters @uniq-pred@10183, using:
// @uniq-pred@10183 = fn(p@0: src/orchestrator/managed-process){
//   std/core/string/(==)((match (p@0) {
//       ((@skip src/orchestrator/Managed-process((@pat@0@4: string) : string, (@pat@1@6: int) : int, (@pat@2@1: string) : string, (@x@3: string) : string, (@pat@3@1: float64) : float64, (@pat@4@1: int) : int) : src/orchestrator/managed-process ) as @pat@7: src/orchestrator/managed-process)
//          -> @x@3;
//     }), "crashed");
// }

kk_std_core_types__list kk_src_orchestrator__trmc_lift_health_summary_10248(kk_std_core_types__list _uniq_xs_10182, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<managed-process>, ctx<list<managed-process>>) -> list<managed-process> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10182, _ctx)) {
    struct kk_std_core_types_Cons* _con_x538 = kk_std_core_types__as_Cons(_uniq_xs_10182, _ctx);
    kk_box_t _box_x118 = _con_x538->head;
    kk_std_core_types__list _uniq_xx_10186 = _con_x538->tail;
    kk_src_orchestrator__managed_process _uniq_x_10185 = kk_src_orchestrator__managed_process_unbox(_box_x118, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x363 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10182, _ctx)) {
      _ru_x363 = (kk_datatype_ptr_reuse(_uniq_xs_10182, _ctx));
    }
    else {
      kk_src_orchestrator__managed_process_dup(_uniq_x_10185, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10186, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10182, _ctx);
    }
    bool _match_x338;
    kk_string_t _x_x539;
    {
      struct kk_src_orchestrator_Managed_process* _con_x540 = kk_src_orchestrator__as_Managed_process(_uniq_x_10185, _ctx);
      kk_string_t _x_3 = _con_x540->status;
      kk_string_dup(_x_3, _ctx);
      _x_x539 = _x_3; /*string*/
    }
    kk_string_t _x_x541;
    kk_define_string_literal(, _s_x542, 7, "crashed", _ctx)
    _x_x541 = kk_string_dup(_s_x542, _ctx); /*string*/
    _match_x338 = kk_string_is_eq(_x_x539,_x_x541,kk_context()); /*bool*/
    if (_match_x338) {
      kk_std_core_types__list _trmc_x10263 = kk_datatype_null(); /*list<src/orchestrator/managed-process>*/;
      kk_std_core_types__list _trmc_x10264 = kk_std_core_types__new_Cons(_ru_x363, 0, kk_src_orchestrator__managed_process_box(_uniq_x_10185, _ctx), _trmc_x10263, _ctx); /*list<src/orchestrator/managed-process>*/;
      kk_field_addr_t _b_x128_133 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10264, _ctx)->tail, _ctx); /*@field-addr<list<src/orchestrator/managed-process>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x543 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10264, _ctx)),_b_x128_133,kk_context()); /*ctx<0>*/
        _uniq_xs_10182 = _uniq_xx_10186;
        _acc = _x_x543;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x363,kk_context());
      kk_datatype_ptr_dropn(_uniq_x_10185, (KK_I32(5)), _ctx);
      { // tailcall
        _uniq_xs_10182 = _uniq_xx_10186;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x544 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x544, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-health-summary@10247, health-summary, @spec-x10190
// specialized: std/core/list/@unroll-filter@10007, on parameters @uniq-pred@10183, using:
// @uniq-pred@10183 = fn(p@0: src/orchestrator/managed-process){
//   std/core/string/(==)((match (p@0) {
//       ((@skip src/orchestrator/Managed-process((@pat@0@4: string) : string, (@pat@1@6: int) : int, (@pat@2@1: string) : string, (@x@3: string) : string, (@pat@3@1: float64) : float64, (@pat@4@1: int) : int) : src/orchestrator/managed-process ) as @pat@7: src/orchestrator/managed-process)
//          -> @x@3;
//     }), "crashed");
// }

kk_std_core_types__list kk_src_orchestrator__lift_health_summary_10248(kk_std_core_types__list _uniq_xs_10182_0, kk_context_t* _ctx) { /* (list<managed-process>) -> list<managed-process> */ 
  kk_std_core_types__cctx _x_x545 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_src_orchestrator__trmc_lift_health_summary_10248(_uniq_xs_10182_0, _x_x545, _ctx);
}
 
// lifted local: health-summary, @spec-x10181
// specialized: std/core/list/filter, on parameters @uniq-pred@10178, using:
// @uniq-pred@10178 = fn(p@0: src/orchestrator/managed-process){
//   std/core/string/(==)((match (p@0) {
//       ((@skip src/orchestrator/Managed-process((@pat@0@4: string) : string, (@pat@1@6: int) : int, (@pat@2@1: string) : string, (@x@3: string) : string, (@pat@3@1: float64) : float64, (@pat@4@1: int) : int) : src/orchestrator/managed-process ) as @pat@7: src/orchestrator/managed-process)
//          -> @x@3;
//     }), "crashed");
// }

kk_std_core_types__list kk_src_orchestrator__lift_health_summary_10247(kk_std_core_types__list _uniq_xs_10177, kk_context_t* _ctx) { /* (list<managed-process>) -> list<managed-process> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10177, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x546 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_src_orchestrator__trmc_lift_health_summary_10248(_uniq_xs_10177, _x_x546, _ctx);
  }
}

kk_string_t kk_src_orchestrator_health_summary(kk_src_orchestrator__orchestrator_state state, kk_context_t* _ctx) { /* (state : orchestrator-state) -> string */ 
  kk_integer_t total;
  {
    struct kk_src_orchestrator_Orchestrator_state* _con_x547 = kk_src_orchestrator__as_Orchestrator_state(state, _ctx);
    kk_std_core_types__list _x = _con_x547->processes;
    kk_std_core_types__list_dup(_x, _ctx);
    if (kk_std_core_types__is_Nil(_x, _ctx)) {
      total = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_std_core_types__list_drop(_x, _ctx);
      kk_std_core_types__list _x_x548;
      {
        struct kk_src_orchestrator_Orchestrator_state* _con_x549 = kk_src_orchestrator__as_Orchestrator_state(state, _ctx);
        kk_std_core_types__list _x_0 = _con_x549->processes;
        kk_std_core_types__list_dup(_x_0, _ctx);
        _x_x548 = _x_0; /*list<src/orchestrator/managed-process>*/
      }
      total = kk_std_core_list__unroll_lift_length_5730_10000(_x_x548, kk_integer_from_small(0), _ctx); /*int*/
    }
  }
  kk_std_core_types__list xs_0_10023;
  kk_std_core_types__list _x_x550;
  {
    struct kk_src_orchestrator_Orchestrator_state* _con_x551 = kk_src_orchestrator__as_Orchestrator_state(state, _ctx);
    kk_std_core_types__list _x_0_0 = _con_x551->processes;
    kk_std_core_types__list_dup(_x_0_0, _ctx);
    _x_x550 = _x_0_0; /*list<src/orchestrator/managed-process>*/
  }
  xs_0_10023 = kk_src_orchestrator__lift_health_summary_10245(_x_x550, _ctx); /*list<src/orchestrator/managed-process>*/
  kk_integer_t running;
  if (kk_std_core_types__is_Nil(xs_0_10023, _ctx)) {
    running = kk_integer_from_small(0); /*int*/
  }
  else {
    running = kk_std_core_list__unroll_lift_length_5730_10000(xs_0_10023, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_std_core_types__list xs_1_10026;
  kk_std_core_types__list _x_x552;
  {
    struct kk_src_orchestrator_Orchestrator_state* _con_x553 = kk_src_orchestrator__as_Orchestrator_state(state, _ctx);
    kk_std_core_types__list _x_2 = _con_x553->processes;
    kk_integer_t _pat_0_3 = _con_x553->total_restarts;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_2, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x552 = _x_2; /*list<src/orchestrator/managed-process>*/
  }
  xs_1_10026 = kk_src_orchestrator__lift_health_summary_10247(_x_x552, _ctx); /*list<src/orchestrator/managed-process>*/
  kk_integer_t crashed;
  if (kk_std_core_types__is_Nil(xs_1_10026, _ctx)) {
    crashed = kk_integer_from_small(0); /*int*/
  }
  else {
    crashed = kk_std_core_list__unroll_lift_length_5730_10000(xs_1_10026, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_string_t _x_x554;
  kk_define_string_literal(, _s_x555, 9, "{\"total\":", _ctx)
  _x_x554 = kk_string_dup(_s_x555, _ctx); /*string*/
  kk_string_t _x_x556;
  kk_string_t _x_x557 = kk_std_core_int_show(total, _ctx); /*string*/
  kk_string_t _x_x558;
  kk_string_t _x_x559;
  kk_define_string_literal(, _s_x560, 11, ",\"running\":", _ctx)
  _x_x559 = kk_string_dup(_s_x560, _ctx); /*string*/
  kk_string_t _x_x561;
  kk_string_t _x_x562 = kk_std_core_int_show(running, _ctx); /*string*/
  kk_string_t _x_x563;
  kk_string_t _x_x564;
  kk_define_string_literal(, _s_x565, 11, ",\"crashed\":", _ctx)
  _x_x564 = kk_string_dup(_s_x565, _ctx); /*string*/
  kk_string_t _x_x566;
  kk_string_t _x_x567 = kk_std_core_int_show(crashed, _ctx); /*string*/
  kk_string_t _x_x568;
  kk_define_string_literal(, _s_x569, 1, "}", _ctx)
  _x_x568 = kk_string_dup(_s_x569, _ctx); /*string*/
  _x_x566 = kk_std_core_types__lp__plus__plus__rp_(_x_x567, _x_x568, _ctx); /*string*/
  _x_x563 = kk_std_core_types__lp__plus__plus__rp_(_x_x564, _x_x566, _ctx); /*string*/
  _x_x561 = kk_std_core_types__lp__plus__plus__rp_(_x_x562, _x_x563, _ctx); /*string*/
  _x_x558 = kk_std_core_types__lp__plus__plus__rp_(_x_x559, _x_x561, _ctx); /*string*/
  _x_x556 = kk_std_core_types__lp__plus__plus__rp_(_x_x557, _x_x558, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x554, _x_x556, _ctx);
}

kk_string_t kk_src_orchestrator_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x331;
  kk_string_t _x_x570 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x571;
  kk_define_string_literal(, _s_x572, 7, "\"spawn\"", _ctx)
  _x_x571 = kk_string_dup(_s_x572, _ctx); /*string*/
  _match_x331 = kk_string_contains(_x_x570,_x_x571,kk_context()); /*bool*/
  if (_match_x331) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x573, 5, "spawn", _ctx)
    return kk_string_dup(_s_x573, _ctx);
  }
  {
    bool _match_x332;
    kk_string_t _x_x574 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x575;
    kk_define_string_literal(, _s_x576, 6, "\"stop\"", _ctx)
    _x_x575 = kk_string_dup(_s_x576, _ctx); /*string*/
    _match_x332 = kk_string_contains(_x_x574,_x_x575,kk_context()); /*bool*/
    if (_match_x332) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x577, 4, "stop", _ctx)
      return kk_string_dup(_s_x577, _ctx);
    }
    {
      bool _match_x333;
      kk_string_t _x_x578 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x579;
      kk_define_string_literal(, _s_x580, 9, "\"restart\"", _ctx)
      _x_x579 = kk_string_dup(_s_x580, _ctx); /*string*/
      _match_x333 = kk_string_contains(_x_x578,_x_x579,kk_context()); /*bool*/
      if (_match_x333) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x581, 7, "restart", _ctx)
        return kk_string_dup(_s_x581, _ctx);
      }
      {
        bool _match_x334;
        kk_string_t _x_x582 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x583;
        kk_define_string_literal(, _s_x584, 8, "\"status\"", _ctx)
        _x_x583 = kk_string_dup(_s_x584, _ctx); /*string*/
        _match_x334 = kk_string_contains(_x_x582,_x_x583,kk_context()); /*bool*/
        if (_match_x334) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x585, 6, "status", _ctx)
          return kk_string_dup(_s_x585, _ctx);
        }
        {
          bool _match_x335;
          kk_string_t _x_x586 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x587;
          kk_define_string_literal(, _s_x588, 8, "\"health\"", _ctx)
          _x_x587 = kk_string_dup(_s_x588, _ctx); /*string*/
          _match_x335 = kk_string_contains(_x_x586,_x_x587,kk_context()); /*bool*/
          if (_match_x335) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x589, 6, "health", _ctx)
            return kk_string_dup(_s_x589, _ctx);
          }
          {
            bool _match_x336;
            kk_string_t _x_x590 = kk_string_dup(line, _ctx); /*string*/
            kk_string_t _x_x591;
            kk_define_string_literal(, _s_x592, 6, "\"list\"", _ctx)
            _x_x591 = kk_string_dup(_s_x592, _ctx); /*string*/
            _match_x336 = kk_string_contains(_x_x590,_x_x591,kk_context()); /*bool*/
            if (_match_x336) {
              kk_string_drop(line, _ctx);
              kk_define_string_literal(, _s_x593, 4, "list", _ctx)
              return kk_string_dup(_s_x593, _ctx);
            }
            {
              bool _match_x337;
              kk_string_t _x_x594;
              kk_define_string_literal(, _s_x595, 6, "\"quit\"", _ctx)
              _x_x594 = kk_string_dup(_s_x595, _ctx); /*string*/
              _match_x337 = kk_string_contains(line,_x_x594,kk_context()); /*bool*/
              if (_match_x337) {
                kk_define_string_literal(, _s_x596, 4, "quit", _ctx)
                return kk_string_dup(_s_x596, _ctx);
              }
              {
                kk_define_string_literal(, _s_x597, 7, "unknown", _ctx)
                return kk_string_dup(_s_x597, _ctx);
              }
            }
          }
        }
      }
    }
  }
}

kk_string_t kk_src_orchestrator_extract_binary(kk_string_t cmd_line, kk_context_t* _ctx) { /* (cmd-line : string) -> string */ 
  bool _match_x325;
  kk_string_t _x_x598 = kk_string_dup(cmd_line, _ctx); /*string*/
  kk_string_t _x_x599;
  kk_define_string_literal(, _s_x600, 18, "unified_runtime_v3", _ctx)
  _x_x599 = kk_string_dup(_s_x600, _ctx); /*string*/
  _match_x325 = kk_string_contains(_x_x598,_x_x599,kk_context()); /*bool*/
  if (_match_x325) {
    kk_string_drop(cmd_line, _ctx);
    kk_define_string_literal(, _s_x601, 18, "unified_runtime_v3", _ctx)
    return kk_string_dup(_s_x601, _ctx);
  }
  {
    bool _match_x326;
    kk_string_t _x_x602 = kk_string_dup(cmd_line, _ctx); /*string*/
    kk_string_t _x_x603;
    kk_define_string_literal(, _s_x604, 14, "effect_runtime", _ctx)
    _x_x603 = kk_string_dup(_s_x604, _ctx); /*string*/
    _match_x326 = kk_string_contains(_x_x602,_x_x603,kk_context()); /*bool*/
    if (_match_x326) {
      kk_string_drop(cmd_line, _ctx);
      kk_define_string_literal(, _s_x605, 14, "effect_runtime", _ctx)
      return kk_string_dup(_s_x605, _ctx);
    }
    {
      bool _match_x327;
      kk_string_t _x_x606 = kk_string_dup(cmd_line, _ctx); /*string*/
      kk_string_t _x_x607;
      kk_define_string_literal(, _s_x608, 11, "ring_buffer", _ctx)
      _x_x607 = kk_string_dup(_s_x608, _ctx); /*string*/
      _match_x327 = kk_string_contains(_x_x606,_x_x607,kk_context()); /*bool*/
      if (_match_x327) {
        kk_string_drop(cmd_line, _ctx);
        kk_define_string_literal(, _s_x609, 11, "ring_buffer", _ctx)
        return kk_string_dup(_s_x609, _ctx);
      }
      {
        bool _match_x328;
        kk_string_t _x_x610 = kk_string_dup(cmd_line, _ctx); /*string*/
        kk_string_t _x_x611;
        kk_define_string_literal(, _s_x612, 11, "rust_bridge", _ctx)
        _x_x611 = kk_string_dup(_s_x612, _ctx); /*string*/
        _match_x328 = kk_string_contains(_x_x610,_x_x611,kk_context()); /*bool*/
        if (_match_x328) {
          kk_string_drop(cmd_line, _ctx);
          kk_define_string_literal(, _s_x613, 11, "rust_bridge", _ctx)
          return kk_string_dup(_s_x613, _ctx);
        }
        {
          bool _match_x329;
          kk_string_t _x_x614 = kk_string_dup(cmd_line, _ctx); /*string*/
          kk_string_t _x_x615;
          kk_define_string_literal(, _s_x616, 4, "prat", _ctx)
          _x_x615 = kk_string_dup(_s_x616, _ctx); /*string*/
          _match_x329 = kk_string_contains(_x_x614,_x_x615,kk_context()); /*bool*/
          if (_match_x329) {
            kk_string_drop(cmd_line, _ctx);
            kk_define_string_literal(, _s_x617, 4, "prat", _ctx)
            return kk_string_dup(_s_x617, _ctx);
          }
          {
            bool _match_x330;
            kk_string_t _x_x618;
            kk_define_string_literal(, _s_x619, 8, "gan_ying", _ctx)
            _x_x618 = kk_string_dup(_s_x619, _ctx); /*string*/
            _match_x330 = kk_string_contains(cmd_line,_x_x618,kk_context()); /*bool*/
            if (_match_x330) {
              kk_define_string_literal(, _s_x620, 8, "gan_ying", _ctx)
              return kk_string_dup(_s_x620, _ctx);
            }
            {
              kk_define_string_literal(, _s_x621, 7, "unknown", _ctx)
              return kk_string_dup(_s_x621, _ctx);
            }
          }
        }
      }
    }
  }
}
 
// lifted local: @lift-server-loop@10249, response, server-loop, @spec-x10209
// specialized: std/core/list/@unroll-foreach-while@10009, on parameters @uniq-action@10202, using:
// @uniq-action@10202 = fn(@uniq-x@10196: src/orchestrator/managed-process){
//   match (val p@10200 : src/orchestrator/managed-process
//                = @uniq-x@10196;
//   (std/core/string/(==)((match (p@10200) {
//       ((@skip src/orchestrator/Managed-process((@x@4: string) : string, (@pat@0@5: int) : int, (@pat@1@7: string) : string, (@pat@2@1: string) : string, (@pat@3@1: float64) : float64, (@pat@4@0: int) : int) : src/orchestrator/managed-process ) as @pat@15: src/orchestrator/managed-process)
//          -> @x@4;
//     }), proc-name))) {
//     ((std/core/types/True() : bool ) as @uniq-pat@1@10197: bool)
//        -> std/core/types/Just<src/orchestrator/managed-process>(@uniq-x@10196);
//     ((@skip std/core/types/False() : bool ) as @uniq-pat@0@0@10198: bool)
//        -> std/core/types/Nothing<src/orchestrator/managed-process>;
//   };
// }

kk_std_core_types__maybe kk_src_orchestrator__lift_server_loop_10250(kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10201, kk_context_t* _ctx) { /* (proc-name : string, list<managed-process>) -> maybe<managed-process> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_xs_10201, _ctx)) {
    kk_string_drop(proc_name, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x622 = kk_std_core_types__as_Cons(_uniq_xs_10201, _ctx);
    kk_box_t _box_x139 = _con_x622->head;
    kk_std_core_types__list _uniq_xx_10206 = _con_x622->tail;
    kk_src_orchestrator__managed_process _uniq_x_10205 = kk_src_orchestrator__managed_process_unbox(_box_x139, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10201, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10201, _ctx);
    }
    else {
      kk_src_orchestrator__managed_process_dup(_uniq_x_10205, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10206, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10201, _ctx);
    }
    bool _match_x324;
    kk_string_t _x_x623;
    {
      struct kk_src_orchestrator_Managed_process* _con_x624 = kk_src_orchestrator__as_Managed_process(_uniq_x_10205, _ctx);
      kk_string_t _x_4 = _con_x624->name;
      kk_string_dup(_x_4, _ctx);
      _x_x623 = _x_4; /*string*/
    }
    kk_string_t _x_x625 = kk_string_dup(proc_name, _ctx); /*string*/
    _match_x324 = kk_string_is_eq(_x_x623,_x_x625,kk_context()); /*bool*/
    if (_match_x324) {
      kk_string_drop(proc_name, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10206, _ctx);
      return kk_std_core_types__new_Just(kk_src_orchestrator__managed_process_box(_uniq_x_10205, _ctx), _ctx);
    }
    {
      kk_datatype_ptr_dropn(_uniq_x_10205, (KK_I32(5)), _ctx);
      { // tailcall
        _uniq_xs_10201 = _uniq_xx_10206;
        goto kk__tailcall;
      }
    }
  }
}
 
// lifted local: response, server-loop, @spec-x10199
// specialized: std/core/list/find, on parameters @uniq-pred@10193, using:
// @uniq-pred@10193 = fn(p: src/orchestrator/managed-process){
//   std/core/string/(==)((match (p) {
//       ((@skip src/orchestrator/Managed-process((@x@4: string) : string, (@pat@0@5: int) : int, (@pat@1@7: string) : string, (@pat@2@1: string) : string, (@pat@3@1: float64) : float64, (@pat@4@0: int) : int) : src/orchestrator/managed-process ) as @pat@15: src/orchestrator/managed-process)
//          -> @x@4;
//     }), proc-name);
// }

kk_std_core_types__maybe kk_src_orchestrator__lift_server_loop_10249(kk_string_t proc_name, kk_std_core_types__list _uniq_xs_10192, kk_context_t* _ctx) { /* (proc-name : string, list<managed-process>) -> maybe<managed-process> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10192, _ctx)) {
    kk_string_drop(proc_name, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    return kk_src_orchestrator__lift_server_loop_10250(proc_name, _uniq_xs_10192, _ctx);
  }
}
 
// lifted local: @lift-server-loop@10251, response, server-loop, @spec-x10222
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10217, using:
// @uniq-f@10217 = fn<<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>(p@0@0: src/orchestrator/managed-process){
//   std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(x : string, y : string) -> string,(x : string, y : string) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>(std/core/types/(++))("\x22", (std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(x : string, y : string) -> string,(x : string, y : string) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>(std/core/types/(++))((std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(src/orchestrator/managed-process) -> string,(src/orchestrator/managed-process) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>((fn(@this@10: src/orchestrator/managed-process){
//         (match (@this@10) {
//           ((@skip src/orchestrator/Managed-process((@x@10: string) : string, (@pat@0@11: int) : int, (@pat@1@13: string) : string, (@pat@2@5: string) : string, (@pat@3@5: float64) : float64, (@pat@4@4: int) : int) : src/orchestrator/managed-process ) as @pat@27: src/orchestrator/managed-process)
//              -> @x@10;
//         });
//       }))(p@0@0)), "\x22")));
// }

kk_std_core_types__list kk_src_orchestrator__trmc_lift_server_loop_10252(kk_std_core_types__list _uniq_xs_10216, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<managed-process>, ctx<list<string>>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10216, _ctx)) {
    struct kk_std_core_types_Cons* _con_x626 = kk_std_core_types__as_Cons(_uniq_xs_10216, _ctx);
    kk_box_t _box_x142 = _con_x626->head;
    kk_std_core_types__list _uniq_xx_10220 = _con_x626->tail;
    kk_src_orchestrator__managed_process _uniq_x_10219 = kk_src_orchestrator__managed_process_unbox(_box_x142, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x368 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10216, _ctx)) {
      _ru_x368 = (kk_datatype_ptr_reuse(_uniq_xs_10216, _ctx));
    }
    else {
      kk_src_orchestrator__managed_process_dup(_uniq_x_10219, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10220, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10216, _ctx);
    }
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_string_t _trmc_x10265;
    kk_string_t _x_x627;
    kk_define_string_literal(, _s_x628, 1, "\"", _ctx)
    _x_x627 = kk_string_dup(_s_x628, _ctx); /*string*/
    kk_string_t _x_x629;
    kk_string_t _x_x630;
    {
      struct kk_src_orchestrator_Managed_process* _con_x631 = kk_src_orchestrator__as_Managed_process(_uniq_x_10219, _ctx);
      kk_string_t _x_10 = _con_x631->name;
      kk_integer_t _pat_0_11 = _con_x631->pid;
      kk_string_t _pat_1_13 = _con_x631->binary_path;
      kk_string_t _pat_2_5 = _con_x631->status;
      kk_integer_t _pat_4_4 = _con_x631->restart_count;
      if kk_likely(kk_datatype_ptr_is_unique(_uniq_x_10219, _ctx)) {
        kk_integer_drop(_pat_4_4, _ctx);
        kk_string_drop(_pat_2_5, _ctx);
        kk_string_drop(_pat_1_13, _ctx);
        kk_integer_drop(_pat_0_11, _ctx);
        kk_datatype_ptr_free(_uniq_x_10219, _ctx);
      }
      else {
        kk_string_dup(_x_10, _ctx);
        kk_datatype_ptr_decref(_uniq_x_10219, _ctx);
      }
      _x_x630 = _x_10; /*string*/
    }
    kk_string_t _x_x632;
    kk_define_string_literal(, _s_x633, 1, "\"", _ctx)
    _x_x632 = kk_string_dup(_s_x633, _ctx); /*string*/
    _x_x629 = kk_std_core_types__lp__plus__plus__rp_(_x_x630, _x_x632, _ctx); /*string*/
    _trmc_x10265 = kk_std_core_types__lp__plus__plus__rp_(_x_x627, _x_x629, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10266 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10267 = kk_std_core_types__new_Cons(_ru_x368, 0, kk_string_box(_trmc_x10265), _trmc_x10266, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x152_157 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10267, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x322;
    kk_std_core_types__cctx _x_x634 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x322 = kk_cctx_extend_linear(_x_x634,(kk_std_core_types__list_box(_trmc_x10267, _ctx)),_b_x152_157,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x323 = kk_src_orchestrator__trmc_lift_server_loop_10252(_uniq_xx_10220, _brw_x322, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x322, _ctx);
    return _brw_x323;
  }
  {
    kk_box_t _x_x635;
    kk_std_core_types__cctx _x_x636 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x635 = kk_cctx_apply_linear(_x_x636,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x635, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-server-loop@10251, response, server-loop, @spec-x10222
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10217, using:
// @uniq-f@10217 = fn<<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>(p@0@0: src/orchestrator/managed-process){
//   std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(x : string, y : string) -> string,(x : string, y : string) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>(std/core/types/(++))("\x22", (std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(x : string, y : string) -> string,(x : string, y : string) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>(std/core/types/(++))((std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(src/orchestrator/managed-process) -> string,(src/orchestrator/managed-process) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>((fn(@this@10: src/orchestrator/managed-process){
//         (match (@this@10) {
//           ((@skip src/orchestrator/Managed-process((@x@10: string) : string, (@pat@0@11: int) : int, (@pat@1@13: string) : string, (@pat@2@5: string) : string, (@pat@3@5: float64) : float64, (@pat@4@4: int) : int) : src/orchestrator/managed-process ) as @pat@27: src/orchestrator/managed-process)
//              -> @x@10;
//         });
//       }))(p@0@0)), "\x22")));
// }

kk_std_core_types__list kk_src_orchestrator__lift_server_loop_10252(kk_std_core_types__list _uniq_xs_10216_0, kk_context_t* _ctx) { /* (list<managed-process>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<string> */ 
  kk_std_core_types__cctx _brw_x320 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x321 = kk_src_orchestrator__trmc_lift_server_loop_10252(_uniq_xs_10216_0, _brw_x320, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x320, _ctx);
  return _brw_x321;
}
 
// lifted local: response, server-loop, @spec-x10215
// specialized: std/core/list/map, on parameters @uniq-f@10212, using:
// @uniq-f@10212 = fn<<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>(p@0@0: src/orchestrator/managed-process){
//   std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(x : string, y : string) -> string,(x : string, y : string) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>(std/core/types/(++))("\x22", (std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(x : string, y : string) -> string,(x : string, y : string) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>(std/core/types/(++))((std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(src/orchestrator/managed-process) -> string,(src/orchestrator/managed-process) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>((fn(@this@10: src/orchestrator/managed-process){
//         (match (@this@10) {
//           ((@skip src/orchestrator/Managed-process((@x@10: string) : string, (@pat@0@11: int) : int, (@pat@1@13: string) : string, (@pat@2@5: string) : string, (@pat@3@5: float64) : float64, (@pat@4@4: int) : int) : src/orchestrator/managed-process ) as @pat@27: src/orchestrator/managed-process)
//              -> @x@10;
//         });
//       }))(p@0@0)), "\x22")));
// }

kk_std_core_types__list kk_src_orchestrator__lift_server_loop_10251(kk_std_core_types__list _uniq_xs_10211, kk_context_t* _ctx) { /* (list<managed-process>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10211, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x318 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x319 = kk_src_orchestrator__trmc_lift_server_loop_10252(_uniq_xs_10211, _brw_x318, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x318, _ctx);
    return _brw_x319;
  }
}
 
// monadic lift

kk_string_t kk_src_orchestrator__mlift_lift_server_loop_10253_10350(kk_std_core_types__list _c_x10274, kk_context_t* _ctx) { /* (list<string>) -> string */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_string_t x;
  if (kk_std_core_types__is_Nil(_c_x10274, _ctx)) {
    x = kk_string_empty(); /*string*/
    goto _match_x637;
  }
  {
    struct kk_std_core_types_Cons* _con_x639 = kk_std_core_types__as_Cons(_c_x10274, _ctx);
    kk_box_t _box_x163 = _con_x639->head;
    kk_std_core_types__list _uniq_pat_1_10231 = _con_x639->tail;
    if (kk_std_core_types__is_Nil(_uniq_pat_1_10231, _ctx)) {
      kk_string_t _uniq_x_10230 = kk_string_unbox(_box_x163);
      if kk_likely(kk_datatype_ptr_is_unique(_c_x10274, _ctx)) {
        kk_datatype_ptr_free(_c_x10274, _ctx);
      }
      else {
        kk_string_dup(_uniq_x_10230, _ctx);
        kk_datatype_ptr_decref(_c_x10274, _ctx);
      }
      x = _uniq_x_10230; /*string*/
      goto _match_x637;
    }
  }
  if (kk_std_core_types__is_Cons(_c_x10274, _ctx)) {
    struct kk_std_core_types_Cons* _con_x640 = kk_std_core_types__as_Cons(_c_x10274, _ctx);
    kk_box_t _box_x164 = _con_x640->head;
    kk_std_core_types__list _uniq_pat_3_10234 = _con_x640->tail;
    if (kk_std_core_types__is_Cons(_uniq_pat_3_10234, _ctx)) {
      struct kk_std_core_types_Cons* _con_x641 = kk_std_core_types__as_Cons(_uniq_pat_3_10234, _ctx);
      kk_box_t _box_x165 = _con_x641->head;
      kk_std_core_types__list _uniq_pat_4_10236 = _con_x641->tail;
      if (kk_std_core_types__is_Nil(_uniq_pat_4_10236, _ctx)) {
        kk_string_t _x_x642;
        kk_define_string_literal(, _s_x643, 1, ",", _ctx)
        _x_x642 = kk_string_dup(_s_x643, _ctx); /*string*/
        kk_string_t _x_x644 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x642,_x_x644,kk_context())) {
          kk_string_t _uniq_x_0_10233 = kk_string_unbox(_box_x164);
          kk_string_t _uniq_y_10235 = kk_string_unbox(_box_x165);
          if kk_likely(kk_datatype_ptr_is_unique(_c_x10274, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_uniq_pat_3_10234, _ctx)) {
              kk_datatype_ptr_free(_uniq_pat_3_10234, _ctx);
            }
            else {
              kk_string_dup(_uniq_y_10235, _ctx);
              kk_datatype_ptr_decref(_uniq_pat_3_10234, _ctx);
            }
            kk_datatype_ptr_free(_c_x10274, _ctx);
          }
          else {
            kk_string_dup(_uniq_x_0_10233, _ctx);
            kk_string_dup(_uniq_y_10235, _ctx);
            kk_datatype_ptr_decref(_c_x10274, _ctx);
          }
          x = kk_std_core_types__lp__plus__plus__rp_(_uniq_x_0_10233, _uniq_y_10235, _ctx); /*string*/
          goto _match_x637;
        }
      }
    }
  }
  {
    kk_vector_t _x_x646 = kk_std_core_vector_unvlist(_c_x10274, _ctx); /*vector<10000>*/
    kk_string_t _x_x647;
    kk_define_string_literal(, _s_x648, 1, ",", _ctx)
    _x_x647 = kk_string_dup(_s_x648, _ctx); /*string*/
    x = kk_string_join_with(_x_x646,_x_x647,kk_context()); /*string*/
  }
  _match_x637: ;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_string_t _x_x649;
  kk_define_string_literal(, _s_x650, 1, "[", _ctx)
  _x_x649 = kk_string_dup(_s_x650, _ctx); /*string*/
  kk_string_t _x_x651;
  kk_string_t _x_x652;
  kk_define_string_literal(, _s_x653, 1, "]", _ctx)
  _x_x652 = kk_string_dup(_s_x653, _ctx); /*string*/
  _x_x651 = kk_std_core_types__lp__plus__plus__rp_(x, _x_x652, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x649, _x_x651, _ctx);
}
 
// lifted local: response, server-loop, @spec-x10240
// specialized: std/core/list/show, on parameters @implicit/@uniq-show@10225, using:
// @implicit/@uniq-show@10225 = std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(s : string) -> string,(s : string) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>(std/core/show/string/show)


// lift anonymous function
struct kk_src_orchestrator__lift_server_loop_10253_fun654__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator__lift_server_loop_10253_fun654(kk_function_t _fself, kk_box_t _b_x168, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_lift_server_loop_10253_fun654(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator__lift_server_loop_10253_fun654, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator__lift_server_loop_10253_fun654(kk_function_t _fself, kk_box_t _b_x168, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x655;
  kk_string_t _x_x656 = kk_string_unbox(_b_x168); /*string*/
  _x_x655 = kk_std_core_show_string_fs_show(_x_x656, _ctx); /*string*/
  return kk_string_box(_x_x655);
}


// lift anonymous function
struct kk_src_orchestrator__lift_server_loop_10253_fun658__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator__lift_server_loop_10253_fun658(kk_function_t _fself, kk_box_t _b_x172, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_lift_server_loop_10253_fun658(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator__lift_server_loop_10253_fun658, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator__lift_server_loop_10253_fun658(kk_function_t _fself, kk_box_t _b_x172, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x659;
  kk_std_core_types__list _x_x660 = kk_std_core_types__list_unbox(_b_x172, KK_OWNED, _ctx); /*list<string>*/
  _x_x659 = kk_src_orchestrator__mlift_lift_server_loop_10253_10350(_x_x660, _ctx); /*string*/
  return kk_string_box(_x_x659);
}

kk_string_t kk_src_orchestrator__lift_server_loop_10253(kk_std_core_types__list _uniq_xs_10224, kk_context_t* _ctx) { /* (list<string>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */ 
  kk_std_core_types__list x_0_10366;
  if (kk_std_core_types__is_Nil(_uniq_xs_10224, _ctx)) {
    x_0_10366 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  else {
    kk_function_t _brw_x316 = kk_src_orchestrator__new_lift_server_loop_10253_fun654(_ctx); /*(10001) -> 10003 10002*/;
    kk_std_core_types__list _brw_x317 = kk_std_core_list__unroll_map_10010(_uniq_xs_10224, _brw_x316, _ctx); /*list<10002>*/;
    kk_function_drop(_brw_x316, _ctx);
    x_0_10366 = _brw_x317; /*list<string>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10366, _ctx);
    kk_box_t _x_x657 = kk_std_core_hnd_yield_extend(kk_src_orchestrator__new_lift_server_loop_10253_fun658(_ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x657);
  }
  {
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_string_t x_1;
    if (kk_std_core_types__is_Nil(x_0_10366, _ctx)) {
      x_1 = kk_string_empty(); /*string*/
      goto _match_x661;
    }
    {
      struct kk_std_core_types_Cons* _con_x663 = kk_std_core_types__as_Cons(x_0_10366, _ctx);
      kk_box_t _box_x173 = _con_x663->head;
      kk_std_core_types__list _uniq_pat_1_10231_0 = _con_x663->tail;
      if (kk_std_core_types__is_Nil(_uniq_pat_1_10231_0, _ctx)) {
        kk_string_t _uniq_x_10230_0 = kk_string_unbox(_box_x173);
        if kk_likely(kk_datatype_ptr_is_unique(x_0_10366, _ctx)) {
          kk_datatype_ptr_free(x_0_10366, _ctx);
        }
        else {
          kk_string_dup(_uniq_x_10230_0, _ctx);
          kk_datatype_ptr_decref(x_0_10366, _ctx);
        }
        x_1 = _uniq_x_10230_0; /*string*/
        goto _match_x661;
      }
    }
    if (kk_std_core_types__is_Cons(x_0_10366, _ctx)) {
      struct kk_std_core_types_Cons* _con_x664 = kk_std_core_types__as_Cons(x_0_10366, _ctx);
      kk_box_t _box_x174 = _con_x664->head;
      kk_std_core_types__list _uniq_pat_3_10234_0 = _con_x664->tail;
      if (kk_std_core_types__is_Cons(_uniq_pat_3_10234_0, _ctx)) {
        struct kk_std_core_types_Cons* _con_x665 = kk_std_core_types__as_Cons(_uniq_pat_3_10234_0, _ctx);
        kk_box_t _box_x175 = _con_x665->head;
        kk_std_core_types__list _uniq_pat_4_10236_0 = _con_x665->tail;
        if (kk_std_core_types__is_Nil(_uniq_pat_4_10236_0, _ctx)) {
          kk_string_t _x_x666;
          kk_define_string_literal(, _s_x667, 1, ",", _ctx)
          _x_x666 = kk_string_dup(_s_x667, _ctx); /*string*/
          kk_string_t _x_x668 = kk_string_empty(); /*string*/
          if (kk_string_is_eq(_x_x666,_x_x668,kk_context())) {
            kk_string_t _uniq_x_0_10233_0 = kk_string_unbox(_box_x174);
            kk_string_t _uniq_y_10235_0 = kk_string_unbox(_box_x175);
            if kk_likely(kk_datatype_ptr_is_unique(x_0_10366, _ctx)) {
              if kk_likely(kk_datatype_ptr_is_unique(_uniq_pat_3_10234_0, _ctx)) {
                kk_datatype_ptr_free(_uniq_pat_3_10234_0, _ctx);
              }
              else {
                kk_string_dup(_uniq_y_10235_0, _ctx);
                kk_datatype_ptr_decref(_uniq_pat_3_10234_0, _ctx);
              }
              kk_datatype_ptr_free(x_0_10366, _ctx);
            }
            else {
              kk_string_dup(_uniq_x_0_10233_0, _ctx);
              kk_string_dup(_uniq_y_10235_0, _ctx);
              kk_datatype_ptr_decref(x_0_10366, _ctx);
            }
            x_1 = kk_std_core_types__lp__plus__plus__rp_(_uniq_x_0_10233_0, _uniq_y_10235_0, _ctx); /*string*/
            goto _match_x661;
          }
        }
      }
    }
    {
      kk_vector_t _x_x670 = kk_std_core_vector_unvlist(x_0_10366, _ctx); /*vector<10000>*/
      kk_string_t _x_x671;
      kk_define_string_literal(, _s_x672, 1, ",", _ctx)
      _x_x671 = kk_string_dup(_s_x672, _ctx); /*string*/
      x_1 = kk_string_join_with(_x_x670,_x_x671,kk_context()); /*string*/
    }
    _match_x661: ;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    kk_string_t _x_x673;
    kk_define_string_literal(, _s_x674, 1, "[", _ctx)
    _x_x673 = kk_string_dup(_s_x674, _ctx); /*string*/
    kk_string_t _x_x675;
    kk_string_t _x_x676;
    kk_define_string_literal(, _s_x677, 1, "]", _ctx)
    _x_x676 = kk_string_dup(_s_x677, _ctx); /*string*/
    _x_x675 = kk_std_core_types__lp__plus__plus__rp_(x_1, _x_x676, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x673, _x_x675, _ctx);
  }
}
 
// monadic lift

kk_string_t kk_src_orchestrator__mlift_server_loop_10351(kk_src_orchestrator__orchestrator_state state, kk_string_t _y_x10282, kk_context_t* _ctx) { /* (state : orchestrator-state, string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_integer_t x_0;
  {
    struct kk_src_orchestrator_Orchestrator_state* _con_x678 = kk_src_orchestrator__as_Orchestrator_state(state, _ctx);
    kk_std_core_types__list _x_11 = _con_x678->processes;
    kk_integer_t _pat_0_12 = _con_x678->total_restarts;
    kk_std_core_types__list_dup(_x_11, _ctx);
    if (kk_std_core_types__is_Nil(_x_11, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
        kk_integer_drop(_pat_0_12, _ctx);
        kk_datatype_ptr_free(state, _ctx);
      }
      else {
        kk_datatype_ptr_decref(state, _ctx);
      }
      x_0 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_std_core_types__list_drop(_x_11, _ctx);
      kk_std_core_types__list _x_x679;
      {
        struct kk_src_orchestrator_Orchestrator_state* _con_x680 = kk_src_orchestrator__as_Orchestrator_state(state, _ctx);
        kk_std_core_types__list _x_11_0 = _con_x680->processes;
        kk_integer_t _pat_0_12_0 = _con_x680->total_restarts;
        if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
          kk_integer_drop(_pat_0_12_0, _ctx);
          kk_datatype_ptr_free(state, _ctx);
        }
        else {
          kk_std_core_types__list_dup(_x_11_0, _ctx);
          kk_datatype_ptr_decref(state, _ctx);
        }
        _x_x679 = _x_11_0; /*list<src/orchestrator/managed-process>*/
      }
      x_0 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x679, kk_integer_from_small(0), _ctx); /*int*/
    }
  }
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_string_t _x_x681;
  kk_define_string_literal(, _s_x682, 13, "{\"processes\":", _ctx)
  _x_x681 = kk_string_dup(_s_x682, _ctx); /*string*/
  kk_string_t _x_x683;
  kk_string_t _x_x684;
  kk_string_t _x_x685;
  kk_define_string_literal(, _s_x686, 9, ",\"count\":", _ctx)
  _x_x685 = kk_string_dup(_s_x686, _ctx); /*string*/
  kk_string_t _x_x687;
  kk_string_t _x_x688 = kk_std_core_int_show(x_0, _ctx); /*string*/
  kk_string_t _x_x689;
  kk_define_string_literal(, _s_x690, 1, "}", _ctx)
  _x_x689 = kk_string_dup(_s_x690, _ctx); /*string*/
  _x_x687 = kk_std_core_types__lp__plus__plus__rp_(_x_x688, _x_x689, _ctx); /*string*/
  _x_x684 = kk_std_core_types__lp__plus__plus__rp_(_x_x685, _x_x687, _ctx); /*string*/
  _x_x683 = kk_std_core_types__lp__plus__plus__rp_(_y_x10282, _x_x684, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x681, _x_x683, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_src_orchestrator__mlift_server_loop_10352_fun692__t {
  struct kk_function_s _base;
  kk_src_orchestrator__orchestrator_state state_0;
};
static kk_box_t kk_src_orchestrator__mlift_server_loop_10352_fun692(kk_function_t _fself, kk_box_t _b_x178, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_mlift_server_loop_10352_fun692(kk_src_orchestrator__orchestrator_state state_0, kk_context_t* _ctx) {
  struct kk_src_orchestrator__mlift_server_loop_10352_fun692__t* _self = kk_function_alloc_as(struct kk_src_orchestrator__mlift_server_loop_10352_fun692__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_orchestrator__mlift_server_loop_10352_fun692, kk_context());
  _self->state_0 = state_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_orchestrator__mlift_server_loop_10352_fun692(kk_function_t _fself, kk_box_t _b_x178, kk_context_t* _ctx) {
  struct kk_src_orchestrator__mlift_server_loop_10352_fun692__t* _self = kk_function_as(struct kk_src_orchestrator__mlift_server_loop_10352_fun692__t*, _fself, _ctx);
  kk_src_orchestrator__orchestrator_state state_0 = _self->state_0; /* src/orchestrator/orchestrator-state */
  kk_drop_match(_self, {kk_src_orchestrator__orchestrator_state_dup(state_0, _ctx);}, {}, _ctx)
  kk_string_t _y_x10282_0_180 = kk_string_unbox(_b_x178); /*string*/;
  kk_string_t _x_x693 = kk_src_orchestrator__mlift_server_loop_10351(state_0, _y_x10282_0_180, _ctx); /*string*/
  return kk_string_box(_x_x693);
}

kk_string_t kk_src_orchestrator__mlift_server_loop_10352(kk_src_orchestrator__orchestrator_state state_0, kk_std_core_types__list names, kk_context_t* _ctx) { /* (state : orchestrator-state, names : list<string>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */ 
  kk_string_t x_0_10374 = kk_src_orchestrator__lift_server_loop_10253(names, _ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10374, _ctx);
    kk_box_t _x_x691 = kk_std_core_hnd_yield_extend(kk_src_orchestrator__new_mlift_server_loop_10352_fun692(state_0, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x691);
  }
  {
    return kk_src_orchestrator__mlift_server_loop_10351(state_0, x_0_10374, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_orchestrator__mlift_server_loop_10353_fun717__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator__mlift_server_loop_10353_fun717(kk_function_t _fself, kk_box_t _b_x186, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_mlift_server_loop_10353_fun717(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator__mlift_server_loop_10353_fun717, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator__mlift_server_loop_10353_fun717(kk_function_t _fself, kk_box_t _b_x186, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x718 = kk_Unit;
  kk_src_orchestrator__orchestrator_state _x_x719 = kk_src_orchestrator__orchestrator_state_unbox(_b_x186, KK_OWNED, _ctx); /*src/orchestrator/orchestrator-state*/
  kk_src_orchestrator_server_loop(_x_x719, _ctx);
  return kk_unit_box(_x_x718);
}

kk_unit_t kk_src_orchestrator__mlift_server_loop_10353(kk_string_t binary, kk_string_t op, kk_src_orchestrator__orchestrator_state state_1, kk_string_t _c_x10283, kk_context_t* _ctx) { /* (binary : string, op : string, state : orchestrator-state, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10283, _ctx);
  kk_src_orchestrator__orchestrator_state x_1_10376;
  if (kk_string_cmp_cstr_borrow(op, "spawn", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    bool _match_x313;
    kk_string_t _x_x695 = kk_string_dup(binary, _ctx); /*string*/
    kk_string_t _x_x696;
    kk_define_string_literal(, _s_x697, 7, "unknown", _ctx)
    _x_x696 = kk_string_dup(_s_x697, _ctx); /*string*/
    _match_x313 = kk_string_is_neq(_x_x695,_x_x696,kk_context()); /*bool*/
    if (_match_x313) {
      kk_src_orchestrator__managed_process new_process_0;
      kk_string_t _x_x698 = kk_string_dup(binary, _ctx); /*string*/
      kk_string_t _x_x699;
      kk_string_t _x_x700;
      kk_define_string_literal(, _s_x701, 2, "./", _ctx)
      _x_x700 = kk_string_dup(_s_x701, _ctx); /*string*/
      _x_x699 = kk_std_core_types__lp__plus__plus__rp_(_x_x700, binary, _ctx); /*string*/
      kk_string_t _x_x702;
      kk_define_string_literal(, _s_x703, 7, "running", _ctx)
      _x_x702 = kk_string_dup(_s_x703, _ctx); /*string*/
      new_process_0 = kk_src_orchestrator__new_Managed_process(kk_reuse_null, 0, _x_x698, kk_integer_from_small(0), _x_x699, _x_x702, 0x0p+0, kk_integer_from_small(0), _ctx); /*src/orchestrator/managed-process*/
      kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_1 = kk_Unit;
      kk_evv_set(w_1,kk_context());
      kk_evv_t w_0_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_0_0 = kk_Unit;
      kk_evv_set(w_0_0,kk_context());
      kk_std_core_types__list _x_x704;
      kk_std_core_types__list _x_x705;
      {
        struct kk_src_orchestrator_Orchestrator_state* _con_x706 = kk_src_orchestrator__as_Orchestrator_state(state_1, _ctx);
        kk_std_core_types__list _x_12 = _con_x706->processes;
        kk_std_core_types__list_dup(_x_12, _ctx);
        _x_x705 = _x_12; /*list<src/orchestrator/managed-process>*/
      }
      _x_x704 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_src_orchestrator__managed_process_box(new_process_0, _ctx), _x_x705, _ctx); /*list<10021>*/
      kk_integer_t _x_x707;
      {
        struct kk_src_orchestrator_Orchestrator_state* _con_x708 = kk_src_orchestrator__as_Orchestrator_state(state_1, _ctx);
        kk_std_core_types__list _pat_0_14 = _con_x708->processes;
        kk_integer_t _x_13 = _con_x708->total_restarts;
        if kk_likely(kk_datatype_ptr_is_unique(state_1, _ctx)) {
          kk_std_core_types__list_drop(_pat_0_14, _ctx);
          kk_datatype_ptr_free(state_1, _ctx);
        }
        else {
          kk_integer_dup(_x_13, _ctx);
          kk_datatype_ptr_decref(state_1, _ctx);
        }
        _x_x707 = _x_13; /*int*/
      }
      x_1_10376 = kk_src_orchestrator__new_Orchestrator_state(kk_reuse_null, 0, _x_x704, _x_x707, 0x0p+0, _ctx); /*src/orchestrator/orchestrator-state*/
      goto _match_x694;
    }
    {
      kk_string_drop(binary, _ctx);
      x_1_10376 = state_1; /*src/orchestrator/orchestrator-state*/
      goto _match_x694;
    }
  }
  if (kk_string_cmp_cstr_borrow(op, "restart", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_string_drop(binary, _ctx);
    kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_2 = kk_Unit;
    kk_evv_set(w_2,kk_context());
    kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_3 = kk_Unit;
    kk_evv_set(w_3,kk_context());
    kk_evv_t w_4 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_4 = kk_Unit;
    kk_evv_set(w_4,kk_context());
    kk_std_core_types__list _x_x709;
    {
      struct kk_src_orchestrator_Orchestrator_state* _con_x710 = kk_src_orchestrator__as_Orchestrator_state(state_1, _ctx);
      kk_std_core_types__list _x_14 = _con_x710->processes;
      kk_std_core_types__list_dup(_x_14, _ctx);
      _x_x709 = _x_14; /*list<src/orchestrator/managed-process>*/
    }
    kk_integer_t _x_x711;
    kk_integer_t _x_x712;
    {
      struct kk_src_orchestrator_Orchestrator_state* _con_x713 = kk_src_orchestrator__as_Orchestrator_state(state_1, _ctx);
      kk_integer_t _x_15 = _con_x713->total_restarts;
      kk_integer_dup(_x_15, _ctx);
      _x_x712 = _x_15; /*int*/
    }
    _x_x711 = kk_integer_add_small_const(_x_x712, 1, _ctx); /*int*/
    double _x_x714;
    {
      struct kk_src_orchestrator_Orchestrator_state* _con_x715 = kk_src_orchestrator__as_Orchestrator_state(state_1, _ctx);
      kk_std_core_types__list _pat_0_17 = _con_x715->processes;
      kk_integer_t _pat_1_20 = _con_x715->total_restarts;
      double _x_16 = _con_x715->last_health_check;
      if kk_likely(kk_datatype_ptr_is_unique(state_1, _ctx)) {
        kk_integer_drop(_pat_1_20, _ctx);
        kk_std_core_types__list_drop(_pat_0_17, _ctx);
        kk_datatype_ptr_free(state_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(state_1, _ctx);
      }
      _x_x714 = _x_16; /*float64*/
    }
    x_1_10376 = kk_src_orchestrator__new_Orchestrator_state(kk_reuse_null, 0, _x_x709, _x_x711, _x_x714, _ctx); /*src/orchestrator/orchestrator-state*/
    goto _match_x694;
  }
  {
    kk_string_drop(op, _ctx);
    kk_string_drop(binary, _ctx);
    x_1_10376 = state_1; /*src/orchestrator/orchestrator-state*/
  }
  _match_x694: ;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_1_10376, (KK_I32(2)), _ctx);
    kk_box_t _x_x716 = kk_std_core_hnd_yield_extend(kk_src_orchestrator__new_mlift_server_loop_10353_fun717(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x716); return kk_Unit;
  }
  {
    kk_src_orchestrator_server_loop(x_1_10376, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_orchestrator__mlift_server_loop_10354_fun737__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun737(kk_function_t _fself, kk_box_t _b_x190, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_mlift_server_loop_10354_fun737(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator__mlift_server_loop_10354_fun737, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun737(kk_function_t _fself, kk_box_t _b_x190, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x738;
  kk_string_t _x_x739 = kk_string_unbox(_b_x190); /*string*/
  _x_x738 = kk_src_orchestrator_extract_op(_x_x739, _ctx); /*string*/
  return kk_string_box(_x_x738);
}


// lift anonymous function
struct kk_src_orchestrator__mlift_server_loop_10354_fun743__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun743(kk_function_t _fself, kk_box_t _b_x195, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_mlift_server_loop_10354_fun743(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator__mlift_server_loop_10354_fun743, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun743(kk_function_t _fself, kk_box_t _b_x195, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x744;
  kk_string_t _x_x745 = kk_string_unbox(_b_x195); /*string*/
  _x_x744 = kk_src_orchestrator_extract_binary(_x_x745, _ctx); /*string*/
  return kk_string_box(_x_x744);
}


// lift anonymous function
struct kk_src_orchestrator__mlift_server_loop_10354_fun803__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun803(kk_function_t _fself, kk_box_t _b_x204, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_mlift_server_loop_10354_fun803(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator__mlift_server_loop_10354_fun803, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun803(kk_function_t _fself, kk_box_t _b_x204, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x804;
  kk_src_orchestrator__orchestrator_state _x_x805 = kk_src_orchestrator__orchestrator_state_unbox(_b_x204, KK_OWNED, _ctx); /*src/orchestrator/orchestrator-state*/
  _x_x804 = kk_src_orchestrator_health_summary(_x_x805, _ctx); /*string*/
  return kk_string_box(_x_x804);
}


// lift anonymous function
struct kk_src_orchestrator__mlift_server_loop_10354_fun809__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun809(kk_function_t _fself, kk_box_t _b_x208, kk_box_t _b_x209, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_mlift_server_loop_10354_fun809(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator__mlift_server_loop_10354_fun809, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun809(kk_function_t _fself, kk_box_t _b_x208, kk_box_t _b_x209, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x810;
  kk_string_t _x_x811 = kk_string_unbox(_b_x208); /*string*/
  kk_std_core_types__list _x_x812 = kk_std_core_types__list_unbox(_b_x209, KK_OWNED, _ctx); /*list<src/orchestrator/managed-process>*/
  _x_x810 = kk_src_orchestrator__lift_server_loop_10249(_x_x811, _x_x812, _ctx); /*maybe<src/orchestrator/managed-process>*/
  return kk_std_core_types__maybe_box(_x_x810, _ctx);
}


// lift anonymous function
struct kk_src_orchestrator__mlift_server_loop_10354_fun826__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_src_orchestrator__mlift_server_loop_10354_fun826(kk_function_t _fself, kk_src_orchestrator__managed_process _this_8, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_mlift_server_loop_10354_fun826(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator__mlift_server_loop_10354_fun826, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_src_orchestrator__mlift_server_loop_10354_fun826(kk_function_t _fself, kk_src_orchestrator__managed_process _this_8, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_src_orchestrator_Managed_process* _con_x827 = kk_src_orchestrator__as_Managed_process(_this_8, _ctx);
    kk_string_t _pat_0_9 = _con_x827->name;
    kk_integer_t _pat_1_11 = _con_x827->pid;
    kk_string_t _pat_2_4 = _con_x827->binary_path;
    kk_string_t _pat_3_4 = _con_x827->status;
    kk_integer_t _x_8 = _con_x827->restart_count;
    if kk_likely(kk_datatype_ptr_is_unique(_this_8, _ctx)) {
      kk_string_drop(_pat_3_4, _ctx);
      kk_string_drop(_pat_2_4, _ctx);
      kk_integer_drop(_pat_1_11, _ctx);
      kk_string_drop(_pat_0_9, _ctx);
      kk_datatype_ptr_free(_this_8, _ctx);
    }
    else {
      kk_integer_dup(_x_8, _ctx);
      kk_datatype_ptr_decref(_this_8, _ctx);
    }
    return _x_8;
  }
}


// lift anonymous function
struct kk_src_orchestrator__mlift_server_loop_10354_fun840__t {
  struct kk_function_s _base;
  kk_function_t _b_x211_224;
};
static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun840(kk_function_t _fself, kk_box_t _b_x213, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_mlift_server_loop_10354_fun840(kk_function_t _b_x211_224, kk_context_t* _ctx) {
  struct kk_src_orchestrator__mlift_server_loop_10354_fun840__t* _self = kk_function_alloc_as(struct kk_src_orchestrator__mlift_server_loop_10354_fun840__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_orchestrator__mlift_server_loop_10354_fun840, kk_context());
  _self->_b_x211_224 = _b_x211_224;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun840(kk_function_t _fself, kk_box_t _b_x213, kk_context_t* _ctx) {
  struct kk_src_orchestrator__mlift_server_loop_10354_fun840__t* _self = kk_function_as(struct kk_src_orchestrator__mlift_server_loop_10354_fun840__t*, _fself, _ctx);
  kk_function_t _b_x211_224 = _self->_b_x211_224; /* (src/orchestrator/managed-process) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x211_224, _ctx);}, {}, _ctx)
  kk_integer_t _x_x841;
  kk_src_orchestrator__managed_process _x_x842 = kk_src_orchestrator__managed_process_unbox(_b_x213, KK_OWNED, _ctx); /*src/orchestrator/managed-process*/
  _x_x841 = kk_function_call(kk_integer_t, (kk_function_t, kk_src_orchestrator__managed_process, kk_context_t*), _b_x211_224, (_b_x211_224, _x_x842, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x841, _ctx);
}


// lift anonymous function
struct kk_src_orchestrator__mlift_server_loop_10354_fun846__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun846(kk_function_t _fself, kk_box_t _b_x216, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_mlift_server_loop_10354_fun846(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator__mlift_server_loop_10354_fun846, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun846(kk_function_t _fself, kk_box_t _b_x216, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x847;
  kk_src_orchestrator__orchestrator_state _x_x848 = kk_src_orchestrator__orchestrator_state_unbox(_b_x216, KK_OWNED, _ctx); /*src/orchestrator/orchestrator-state*/
  _x_x847 = kk_src_orchestrator_health_summary(_x_x848, _ctx); /*string*/
  return kk_string_box(_x_x847);
}


// lift anonymous function
struct kk_src_orchestrator__mlift_server_loop_10354_fun855__t {
  struct kk_function_s _base;
  kk_src_orchestrator__orchestrator_state state_2;
};
static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun855(kk_function_t _fself, kk_box_t _b_x218, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_mlift_server_loop_10354_fun855(kk_src_orchestrator__orchestrator_state state_2, kk_context_t* _ctx) {
  struct kk_src_orchestrator__mlift_server_loop_10354_fun855__t* _self = kk_function_alloc_as(struct kk_src_orchestrator__mlift_server_loop_10354_fun855__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_orchestrator__mlift_server_loop_10354_fun855, kk_context());
  _self->state_2 = state_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun855(kk_function_t _fself, kk_box_t _b_x218, kk_context_t* _ctx) {
  struct kk_src_orchestrator__mlift_server_loop_10354_fun855__t* _self = kk_function_as(struct kk_src_orchestrator__mlift_server_loop_10354_fun855__t*, _fself, _ctx);
  kk_src_orchestrator__orchestrator_state state_2 = _self->state_2; /* src/orchestrator/orchestrator-state */
  kk_drop_match(_self, {kk_src_orchestrator__orchestrator_state_dup(state_2, _ctx);}, {}, _ctx)
  kk_string_t _x_x856;
  kk_std_core_types__list _x_x857 = kk_std_core_types__list_unbox(_b_x218, KK_OWNED, _ctx); /*list<string>*/
  _x_x856 = kk_src_orchestrator__mlift_server_loop_10352(state_2, _x_x857, _ctx); /*string*/
  return kk_string_box(_x_x856);
}


// lift anonymous function
struct kk_src_orchestrator__mlift_server_loop_10354_fun861__t {
  struct kk_function_s _base;
  kk_string_t binary_0;
  kk_string_t op_0;
  kk_src_orchestrator__orchestrator_state state_2;
};
static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun861(kk_function_t _fself, kk_box_t _b_x231, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator__new_mlift_server_loop_10354_fun861(kk_string_t binary_0, kk_string_t op_0, kk_src_orchestrator__orchestrator_state state_2, kk_context_t* _ctx) {
  struct kk_src_orchestrator__mlift_server_loop_10354_fun861__t* _self = kk_function_alloc_as(struct kk_src_orchestrator__mlift_server_loop_10354_fun861__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_orchestrator__mlift_server_loop_10354_fun861, kk_context());
  _self->binary_0 = binary_0;
  _self->op_0 = op_0;
  _self->state_2 = state_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_orchestrator__mlift_server_loop_10354_fun861(kk_function_t _fself, kk_box_t _b_x231, kk_context_t* _ctx) {
  struct kk_src_orchestrator__mlift_server_loop_10354_fun861__t* _self = kk_function_as(struct kk_src_orchestrator__mlift_server_loop_10354_fun861__t*, _fself, _ctx);
  kk_string_t binary_0 = _self->binary_0; /* string */
  kk_string_t op_0 = _self->op_0; /* string */
  kk_src_orchestrator__orchestrator_state state_2 = _self->state_2; /* src/orchestrator/orchestrator-state */
  kk_drop_match(_self, {kk_string_dup(binary_0, _ctx);kk_string_dup(op_0, _ctx);kk_src_orchestrator__orchestrator_state_dup(state_2, _ctx);}, {}, _ctx)
  kk_string_t _c_x10283_0_233 = kk_string_unbox(_b_x231); /*string*/;
  kk_unit_t _x_x862 = kk_Unit;
  kk_src_orchestrator__mlift_server_loop_10353(binary_0, op_0, state_2, _c_x10283_0_233, _ctx);
  return kk_unit_box(_x_x862);
}

kk_unit_t kk_src_orchestrator__mlift_server_loop_10354(kk_src_orchestrator__orchestrator_state state_2, kk_string_t line, kk_context_t* _ctx) { /* (state : orchestrator-state, line : string) -> <console/console,exn> () */ 
  bool _match_x303;
  kk_string_t _x_x720 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x721 = kk_string_empty(); /*string*/
  _match_x303 = kk_string_is_eq(_x_x720,_x_x721,kk_context()); /*bool*/
  if (_match_x303) {
    kk_datatype_ptr_dropn(state_2, (KK_I32(2)), _ctx);
    kk_string_drop(line, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    bool _match_x304;
    kk_string_t _x_x723 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x724;
    kk_define_string_literal(, _s_x725, 6, "\"quit\"", _ctx)
    _x_x724 = kk_string_dup(_s_x725, _ctx); /*string*/
    _match_x304 = kk_string_contains(_x_x723,_x_x724,kk_context()); /*bool*/
    if (_match_x304) {
      kk_string_drop(line, _ctx);
      kk_evv_t w_5 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_5 = kk_Unit;
      kk_evv_set(w_5,kk_context());
      kk_evv_t w_6 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_integer_t x_1;
      {
        struct kk_src_orchestrator_Orchestrator_state* _con_x726 = kk_src_orchestrator__as_Orchestrator_state(state_2, _ctx);
        kk_std_core_types__list _x = _con_x726->processes;
        kk_integer_t _pat_0_0_0 = _con_x726->total_restarts;
        kk_std_core_types__list_dup(_x, _ctx);
        if (kk_std_core_types__is_Nil(_x, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(state_2, _ctx)) {
            kk_integer_drop(_pat_0_0_0, _ctx);
            kk_datatype_ptr_free(state_2, _ctx);
          }
          else {
            kk_datatype_ptr_decref(state_2, _ctx);
          }
          x_1 = kk_integer_from_small(0); /*int*/
        }
        else {
          kk_std_core_types__list_drop(_x, _ctx);
          kk_std_core_types__list _x_x727;
          {
            struct kk_src_orchestrator_Orchestrator_state* _con_x728 = kk_src_orchestrator__as_Orchestrator_state(state_2, _ctx);
            kk_std_core_types__list _x_0 = _con_x728->processes;
            kk_integer_t _pat_0_0_0_0 = _con_x728->total_restarts;
            if kk_likely(kk_datatype_ptr_is_unique(state_2, _ctx)) {
              kk_integer_drop(_pat_0_0_0_0, _ctx);
              kk_datatype_ptr_free(state_2, _ctx);
            }
            else {
              kk_std_core_types__list_dup(_x_0, _ctx);
              kk_datatype_ptr_decref(state_2, _ctx);
            }
            _x_x727 = _x_0; /*list<src/orchestrator/managed-process>*/
          }
          x_1 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x727, kk_integer_from_small(0), _ctx); /*int*/
        }
      }
      kk_unit_t keep_6 = kk_Unit;
      kk_evv_set(w_6,kk_context());
      kk_string_t _x_x729;
      kk_string_t _x_x730;
      kk_define_string_literal(, _s_x731, 41, "{\"status\":\"stopped\",\"processes_shutdown\":", _ctx)
      _x_x730 = kk_string_dup(_s_x731, _ctx); /*string*/
      kk_string_t _x_x732;
      kk_string_t _x_x733 = kk_std_core_int_show(x_1, _ctx); /*string*/
      kk_string_t _x_x734;
      kk_define_string_literal(, _s_x735, 1, "}", _ctx)
      _x_x734 = kk_string_dup(_s_x735, _ctx); /*string*/
      _x_x732 = kk_std_core_types__lp__plus__plus__rp_(_x_x733, _x_x734, _ctx); /*string*/
      _x_x729 = kk_std_core_types__lp__plus__plus__rp_(_x_x730, _x_x732, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x729, _ctx); return kk_Unit;
    }
    {
      kk_string_t op_0;
      kk_box_t _x_x736;
      kk_box_t _x_x740;
      kk_string_t _x_x741 = kk_string_dup(line, _ctx); /*string*/
      _x_x740 = kk_string_box(_x_x741); /*10000*/
      _x_x736 = kk_std_core_hnd__open_none1(kk_src_orchestrator__new_mlift_server_loop_10354_fun737(_ctx), _x_x740, _ctx); /*10001*/
      op_0 = kk_string_unbox(_x_x736); /*string*/
      kk_string_t binary_0;
      kk_box_t _x_x742 = kk_std_core_hnd__open_none1(kk_src_orchestrator__new_mlift_server_loop_10354_fun743(_ctx), kk_string_box(line), _ctx); /*10001*/
      binary_0 = kk_string_unbox(_x_x742); /*string*/
      kk_string_t x_8_10390;
      if (kk_string_cmp_cstr_borrow(op_0, "spawn", _ctx) == 0) {
        bool _match_x311;
        kk_string_t _x_x747 = kk_string_dup(binary_0, _ctx); /*string*/
        kk_string_t _x_x748;
        kk_define_string_literal(, _s_x749, 7, "unknown", _ctx)
        _x_x748 = kk_string_dup(_s_x749, _ctx); /*string*/
        _match_x311 = kk_string_is_eq(_x_x747,_x_x748,kk_context()); /*bool*/
        if (_match_x311) {
          kk_define_string_literal(, _s_x750, 26, "{\"error\":\"unknown binary\"}", _ctx)
          x_8_10390 = kk_string_dup(_s_x750, _ctx); /*string*/
          goto _match_x746;
        }
        {
          kk_src_orchestrator__managed_process new_process;
          kk_string_t _x_x751 = kk_string_dup(binary_0, _ctx); /*string*/
          kk_string_t _x_x752;
          kk_string_t _x_x753;
          kk_define_string_literal(, _s_x754, 2, "./", _ctx)
          _x_x753 = kk_string_dup(_s_x754, _ctx); /*string*/
          kk_string_t _x_x755 = kk_string_dup(binary_0, _ctx); /*string*/
          _x_x752 = kk_std_core_types__lp__plus__plus__rp_(_x_x753, _x_x755, _ctx); /*string*/
          kk_string_t _x_x756;
          kk_define_string_literal(, _s_x757, 7, "running", _ctx)
          _x_x756 = kk_string_dup(_s_x757, _ctx); /*string*/
          new_process = kk_src_orchestrator__new_Managed_process(kk_reuse_null, 0, _x_x751, kk_integer_from_small(0), _x_x752, _x_x756, 0x0p+0, kk_integer_from_small(0), _ctx); /*src/orchestrator/managed-process*/
          kk_evv_t w_7 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_7 = kk_Unit;
          kk_evv_set(w_7,kk_context());
          kk_evv_t w_6_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_6_0 = kk_Unit;
          kk_evv_set(w_6_0,kk_context());
          kk_evv_t w_8 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_8 = kk_Unit;
          kk_evv_set(w_8,kk_context());
          kk_evv_t w_9 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_std_core_types__list xs_0_10473;
          kk_std_core_types__list _x_x758;
          {
            struct kk_src_orchestrator_Orchestrator_state* _con_x759 = kk_src_orchestrator__as_Orchestrator_state(state_2, _ctx);
            kk_std_core_types__list _x_0_0 = _con_x759->processes;
            kk_std_core_types__list_dup(_x_0_0, _ctx);
            _x_x758 = _x_0_0; /*list<src/orchestrator/managed-process>*/
          }
          xs_0_10473 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_src_orchestrator__managed_process_box(new_process, _ctx), _x_x758, _ctx); /*list<src/orchestrator/managed-process>*/
          kk_integer_t x_8;
          if (kk_std_core_types__is_Nil(xs_0_10473, _ctx)) {
            x_8 = kk_integer_from_small(0); /*int*/
          }
          else {
            x_8 = kk_std_core_list__unroll_lift_length_5730_10000(xs_0_10473, kk_integer_from_small(0), _ctx); /*int*/
          }
          kk_unit_t keep_9 = kk_Unit;
          kk_evv_set(w_9,kk_context());
          kk_string_t _x_x760;
          kk_define_string_literal(, _s_x761, 12, "{\"spawned\":\"", _ctx)
          _x_x760 = kk_string_dup(_s_x761, _ctx); /*string*/
          kk_string_t _x_x762;
          kk_string_t _x_x763 = kk_string_dup(binary_0, _ctx); /*string*/
          kk_string_t _x_x764;
          kk_string_t _x_x765;
          kk_define_string_literal(, _s_x766, 39, "\",\"status\":\"running\",\"total_processes\":", _ctx)
          _x_x765 = kk_string_dup(_s_x766, _ctx); /*string*/
          kk_string_t _x_x767;
          kk_string_t _x_x768 = kk_std_core_int_show(x_8, _ctx); /*string*/
          kk_string_t _x_x769;
          kk_define_string_literal(, _s_x770, 1, "}", _ctx)
          _x_x769 = kk_string_dup(_s_x770, _ctx); /*string*/
          _x_x767 = kk_std_core_types__lp__plus__plus__rp_(_x_x768, _x_x769, _ctx); /*string*/
          _x_x764 = kk_std_core_types__lp__plus__plus__rp_(_x_x765, _x_x767, _ctx); /*string*/
          _x_x762 = kk_std_core_types__lp__plus__plus__rp_(_x_x763, _x_x764, _ctx); /*string*/
          x_8_10390 = kk_std_core_types__lp__plus__plus__rp_(_x_x760, _x_x762, _ctx); /*string*/
          goto _match_x746;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_0, "stop", _ctx) == 0) {
        bool _match_x310;
        kk_string_t _x_x771 = kk_string_dup(binary_0, _ctx); /*string*/
        kk_string_t _x_x772;
        kk_define_string_literal(, _s_x773, 7, "unknown", _ctx)
        _x_x772 = kk_string_dup(_s_x773, _ctx); /*string*/
        _match_x310 = kk_string_is_eq(_x_x771,_x_x772,kk_context()); /*bool*/
        if (_match_x310) {
          kk_define_string_literal(, _s_x774, 26, "{\"error\":\"unknown binary\"}", _ctx)
          x_8_10390 = kk_string_dup(_s_x774, _ctx); /*string*/
          goto _match_x746;
        }
        {
          kk_string_t _x_x775;
          kk_define_string_literal(, _s_x776, 12, "{\"stopped\":\"", _ctx)
          _x_x775 = kk_string_dup(_s_x776, _ctx); /*string*/
          kk_string_t _x_x777;
          kk_string_t _x_x778 = kk_string_dup(binary_0, _ctx); /*string*/
          kk_string_t _x_x779;
          kk_define_string_literal(, _s_x780, 2, "\"}", _ctx)
          _x_x779 = kk_string_dup(_s_x780, _ctx); /*string*/
          _x_x777 = kk_std_core_types__lp__plus__plus__rp_(_x_x778, _x_x779, _ctx); /*string*/
          x_8_10390 = kk_std_core_types__lp__plus__plus__rp_(_x_x775, _x_x777, _ctx); /*string*/
          goto _match_x746;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_0, "restart", _ctx) == 0) {
        bool _match_x309;
        kk_string_t _x_x781 = kk_string_dup(binary_0, _ctx); /*string*/
        kk_string_t _x_x782;
        kk_define_string_literal(, _s_x783, 7, "unknown", _ctx)
        _x_x782 = kk_string_dup(_s_x783, _ctx); /*string*/
        _match_x309 = kk_string_is_eq(_x_x781,_x_x782,kk_context()); /*bool*/
        if (_match_x309) {
          kk_define_string_literal(, _s_x784, 26, "{\"error\":\"unknown binary\"}", _ctx)
          x_8_10390 = kk_string_dup(_s_x784, _ctx); /*string*/
          goto _match_x746;
        }
        {
          kk_evv_t w_9_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_9_0 = kk_Unit;
          kk_evv_set(w_9_0,kk_context());
          kk_string_t _x_x785;
          kk_define_string_literal(, _s_x786, 14, "{\"restarted\":\"", _ctx)
          _x_x785 = kk_string_dup(_s_x786, _ctx); /*string*/
          kk_string_t _x_x787;
          kk_string_t _x_x788 = kk_string_dup(binary_0, _ctx); /*string*/
          kk_string_t _x_x789;
          kk_string_t _x_x790;
          kk_define_string_literal(, _s_x791, 18, "\",\"restart_count\":", _ctx)
          _x_x790 = kk_string_dup(_s_x791, _ctx); /*string*/
          kk_string_t _x_x792;
          kk_string_t _x_x793;
          kk_integer_t _x_x794;
          kk_integer_t _x_x795;
          {
            struct kk_src_orchestrator_Orchestrator_state* _con_x796 = kk_src_orchestrator__as_Orchestrator_state(state_2, _ctx);
            kk_integer_t _x_3 = _con_x796->total_restarts;
            kk_integer_dup(_x_3, _ctx);
            _x_x795 = _x_3; /*int*/
          }
          _x_x794 = kk_integer_add_small_const(_x_x795, 1, _ctx); /*int*/
          _x_x793 = kk_std_core_int_show(_x_x794, _ctx); /*string*/
          kk_string_t _x_x797;
          kk_define_string_literal(, _s_x798, 1, "}", _ctx)
          _x_x797 = kk_string_dup(_s_x798, _ctx); /*string*/
          _x_x792 = kk_std_core_types__lp__plus__plus__rp_(_x_x793, _x_x797, _ctx); /*string*/
          _x_x789 = kk_std_core_types__lp__plus__plus__rp_(_x_x790, _x_x792, _ctx); /*string*/
          _x_x787 = kk_std_core_types__lp__plus__plus__rp_(_x_x788, _x_x789, _ctx); /*string*/
          x_8_10390 = kk_std_core_types__lp__plus__plus__rp_(_x_x785, _x_x787, _ctx); /*string*/
          goto _match_x746;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
        bool _match_x307;
        kk_string_t _x_x799 = kk_string_dup(binary_0, _ctx); /*string*/
        kk_string_t _x_x800;
        kk_define_string_literal(, _s_x801, 7, "unknown", _ctx)
        _x_x800 = kk_string_dup(_s_x801, _ctx); /*string*/
        _match_x307 = kk_string_is_eq(_x_x799,_x_x800,kk_context()); /*bool*/
        if (_match_x307) {
          kk_box_t _x_x802;
          kk_box_t _x_x806;
          kk_src_orchestrator__orchestrator_state _x_x807 = kk_src_orchestrator__orchestrator_state_dup(state_2, _ctx); /*src/orchestrator/orchestrator-state*/
          _x_x806 = kk_src_orchestrator__orchestrator_state_box(_x_x807, _ctx); /*10000*/
          _x_x802 = kk_std_core_hnd__open_none1(kk_src_orchestrator__new_mlift_server_loop_10354_fun803(_ctx), _x_x806, _ctx); /*10001*/
          x_8_10390 = kk_string_unbox(_x_x802); /*string*/
          goto _match_x746;
        }
        {
          kk_evv_t w_10 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_10 = kk_Unit;
          kk_evv_set(w_10,kk_context());
          kk_std_core_types__maybe _match_x308;
          kk_box_t _x_x808;
          kk_box_t _x_x813;
          kk_string_t _x_x814 = kk_string_dup(binary_0, _ctx); /*string*/
          _x_x813 = kk_string_box(_x_x814); /*10000*/
          kk_box_t _x_x815;
          kk_std_core_types__list _x_x816;
          {
            struct kk_src_orchestrator_Orchestrator_state* _con_x817 = kk_src_orchestrator__as_Orchestrator_state(state_2, _ctx);
            kk_std_core_types__list _x_5 = _con_x817->processes;
            kk_std_core_types__list_dup(_x_5, _ctx);
            _x_x816 = _x_5; /*list<src/orchestrator/managed-process>*/
          }
          _x_x815 = kk_std_core_types__list_box(_x_x816, _ctx); /*10001*/
          _x_x808 = kk_std_core_hnd__open_none2(kk_src_orchestrator__new_mlift_server_loop_10354_fun809(_ctx), _x_x813, _x_x815, _ctx); /*10002*/
          _match_x308 = kk_std_core_types__maybe_unbox(_x_x808, KK_OWNED, _ctx); /*maybe<src/orchestrator/managed-process>*/
          if (kk_std_core_types__is_Nothing(_match_x308, _ctx)) {
            kk_define_string_literal(, _s_x818, 29, "{\"error\":\"process not found\"}", _ctx)
            x_8_10390 = kk_string_dup(_s_x818, _ctx); /*string*/
            goto _match_x746;
          }
          {
            kk_box_t _box_x210 = _match_x308._cons.Just.value;
            kk_src_orchestrator__managed_process p_0 = kk_src_orchestrator__managed_process_unbox(_box_x210, KK_BORROWED, _ctx);
            struct kk_src_orchestrator_Managed_process* _con_x819 = kk_src_orchestrator__as_Managed_process(p_0, _ctx);
            kk_src_orchestrator__managed_process_dup(p_0, _ctx);
            kk_std_core_types__maybe_drop(_match_x308, _ctx);
            kk_evv_t w_11 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_11 = kk_Unit;
            kk_evv_set(w_11,kk_context());
            kk_evv_t w_12 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_12 = kk_Unit;
            kk_evv_set(w_12,kk_context());
            kk_string_t _x_x820;
            kk_define_string_literal(, _s_x821, 9, "{\"name\":\"", _ctx)
            _x_x820 = kk_string_dup(_s_x821, _ctx); /*string*/
            kk_string_t _x_x822;
            kk_string_t _x_x823;
            {
              struct kk_src_orchestrator_Managed_process* _con_x824 = kk_src_orchestrator__as_Managed_process(p_0, _ctx);
              kk_string_t _x_6 = _con_x824->name;
              kk_string_dup(_x_6, _ctx);
              _x_x823 = _x_6; /*string*/
            }
            kk_string_t _x_x825;
            kk_function_t _b_x211_224 = kk_src_orchestrator__new_mlift_server_loop_10354_fun826(_ctx); /*(src/orchestrator/managed-process) -> int*/;
            kk_src_orchestrator__managed_process _b_x212_225 = kk_src_orchestrator__managed_process_dup(p_0, _ctx); /*src/orchestrator/managed-process*/;
            kk_string_t _x_x828;
            kk_define_string_literal(, _s_x829, 12, "\",\"status\":\"", _ctx)
            _x_x828 = kk_string_dup(_s_x829, _ctx); /*string*/
            kk_string_t _x_x830;
            kk_string_t _x_x831;
            {
              struct kk_src_orchestrator_Managed_process* _con_x832 = kk_src_orchestrator__as_Managed_process(p_0, _ctx);
              kk_string_t _pat_0_8 = _con_x832->name;
              kk_integer_t _pat_1_10 = _con_x832->pid;
              kk_string_t _pat_2_3 = _con_x832->binary_path;
              kk_string_t _x_7 = _con_x832->status;
              kk_integer_t _pat_4_2 = _con_x832->restart_count;
              if kk_likely(kk_datatype_ptr_is_unique(p_0, _ctx)) {
                kk_integer_drop(_pat_4_2, _ctx);
                kk_string_drop(_pat_2_3, _ctx);
                kk_integer_drop(_pat_1_10, _ctx);
                kk_string_drop(_pat_0_8, _ctx);
                kk_datatype_ptr_free(p_0, _ctx);
              }
              else {
                kk_string_dup(_x_7, _ctx);
                kk_datatype_ptr_decref(p_0, _ctx);
              }
              _x_x831 = _x_7; /*string*/
            }
            kk_string_t _x_x833;
            kk_string_t _x_x834;
            kk_define_string_literal(, _s_x835, 13, "\",\"restarts\":", _ctx)
            _x_x834 = kk_string_dup(_s_x835, _ctx); /*string*/
            kk_string_t _x_x836;
            kk_string_t _x_x837;
            kk_integer_t _x_x838;
            kk_box_t _x_x839 = kk_std_core_hnd__open_none1(kk_src_orchestrator__new_mlift_server_loop_10354_fun840(_b_x211_224, _ctx), kk_src_orchestrator__managed_process_box(_b_x212_225, _ctx), _ctx); /*10001*/
            _x_x838 = kk_integer_unbox(_x_x839, _ctx); /*int*/
            _x_x837 = kk_std_core_int_show(_x_x838, _ctx); /*string*/
            kk_string_t _x_x843;
            kk_define_string_literal(, _s_x844, 1, "}", _ctx)
            _x_x843 = kk_string_dup(_s_x844, _ctx); /*string*/
            _x_x836 = kk_std_core_types__lp__plus__plus__rp_(_x_x837, _x_x843, _ctx); /*string*/
            _x_x833 = kk_std_core_types__lp__plus__plus__rp_(_x_x834, _x_x836, _ctx); /*string*/
            _x_x830 = kk_std_core_types__lp__plus__plus__rp_(_x_x831, _x_x833, _ctx); /*string*/
            _x_x825 = kk_std_core_types__lp__plus__plus__rp_(_x_x828, _x_x830, _ctx); /*string*/
            _x_x822 = kk_std_core_types__lp__plus__plus__rp_(_x_x823, _x_x825, _ctx); /*string*/
            x_8_10390 = kk_std_core_types__lp__plus__plus__rp_(_x_x820, _x_x822, _ctx); /*string*/
            goto _match_x746;
          }
        }
      }
      if (kk_string_cmp_cstr_borrow(op_0, "health", _ctx) == 0) {
        kk_box_t _x_x845;
        kk_box_t _x_x849;
        kk_src_orchestrator__orchestrator_state _x_x850 = kk_src_orchestrator__orchestrator_state_dup(state_2, _ctx); /*src/orchestrator/orchestrator-state*/
        _x_x849 = kk_src_orchestrator__orchestrator_state_box(_x_x850, _ctx); /*10000*/
        _x_x845 = kk_std_core_hnd__open_none1(kk_src_orchestrator__new_mlift_server_loop_10354_fun846(_ctx), _x_x849, _ctx); /*10001*/
        x_8_10390 = kk_string_unbox(_x_x845); /*string*/
        goto _match_x746;
      }
      if (kk_string_cmp_cstr_borrow(op_0, "list", _ctx) == 0) {
        kk_evv_t w_12_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_12_0 = kk_Unit;
        kk_evv_set(w_12_0,kk_context());
        kk_std_core_types__list x_15_10404;
        kk_std_core_types__list _x_x851;
        {
          struct kk_src_orchestrator_Orchestrator_state* _con_x852 = kk_src_orchestrator__as_Orchestrator_state(state_2, _ctx);
          kk_std_core_types__list _x_9 = _con_x852->processes;
          kk_std_core_types__list_dup(_x_9, _ctx);
          _x_x851 = _x_9; /*list<src/orchestrator/managed-process>*/
        }
        x_15_10404 = kk_src_orchestrator__lift_server_loop_10251(_x_x851, _ctx); /*list<string>*/
        if (kk_yielding(kk_context())) {
          kk_std_core_types__list_drop(x_15_10404, _ctx);
          kk_box_t _x_x853;
          kk_function_t _x_x854;
          kk_src_orchestrator__orchestrator_state_dup(state_2, _ctx);
          _x_x854 = kk_src_orchestrator__new_mlift_server_loop_10354_fun855(state_2, _ctx); /*(10000) -> 10002 10001*/
          _x_x853 = kk_std_core_hnd_yield_extend(_x_x854, _ctx); /*10001*/
          x_8_10390 = kk_string_unbox(_x_x853); /*string*/
          goto _match_x746;
        }
        {
          kk_src_orchestrator__orchestrator_state _x_x858 = kk_src_orchestrator__orchestrator_state_dup(state_2, _ctx); /*src/orchestrator/orchestrator-state*/
          x_8_10390 = kk_src_orchestrator__mlift_server_loop_10352(_x_x858, x_15_10404, _ctx); /*string*/
          goto _match_x746;
        }
      }
      {
        kk_define_string_literal(, _s_x859, 27, "{\"error\":\"unknown command\"}", _ctx)
        x_8_10390 = kk_string_dup(_s_x859, _ctx); /*string*/
      }
      _match_x746: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_8_10390, _ctx);
        kk_box_t _x_x860 = kk_std_core_hnd_yield_extend(kk_src_orchestrator__new_mlift_server_loop_10354_fun861(binary_0, op_0, state_2, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x860); return kk_Unit;
      }
      {
        kk_src_orchestrator__mlift_server_loop_10353(binary_0, op_0, state_2, x_8_10390, _ctx); return kk_Unit;
      }
    }
  }
}


// lift anonymous function
struct kk_src_orchestrator_server_loop_fun864__t {
  struct kk_function_s _base;
  kk_src_orchestrator__orchestrator_state state_3;
};
static kk_box_t kk_src_orchestrator_server_loop_fun864(kk_function_t _fself, kk_box_t _b_x235, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator_new_server_loop_fun864(kk_src_orchestrator__orchestrator_state state_3, kk_context_t* _ctx) {
  struct kk_src_orchestrator_server_loop_fun864__t* _self = kk_function_alloc_as(struct kk_src_orchestrator_server_loop_fun864__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_orchestrator_server_loop_fun864, kk_context());
  _self->state_3 = state_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_orchestrator_server_loop_fun864(kk_function_t _fself, kk_box_t _b_x235, kk_context_t* _ctx) {
  struct kk_src_orchestrator_server_loop_fun864__t* _self = kk_function_as(struct kk_src_orchestrator_server_loop_fun864__t*, _fself, _ctx);
  kk_src_orchestrator__orchestrator_state state_3 = _self->state_3; /* src/orchestrator/orchestrator-state */
  kk_drop_match(_self, {kk_src_orchestrator__orchestrator_state_dup(state_3, _ctx);}, {}, _ctx)
  kk_string_t line_0_289 = kk_string_unbox(_b_x235); /*string*/;
  kk_unit_t _x_x865 = kk_Unit;
  kk_src_orchestrator__mlift_server_loop_10354(state_3, line_0_289, _ctx);
  return kk_unit_box(_x_x865);
}


// lift anonymous function
struct kk_src_orchestrator_server_loop_fun883__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator_server_loop_fun883(kk_function_t _fself, kk_box_t _b_x238, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator_new_server_loop_fun883(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator_server_loop_fun883, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator_server_loop_fun883(kk_function_t _fself, kk_box_t _b_x238, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x884;
  kk_string_t _x_x885 = kk_string_unbox(_b_x238); /*string*/
  _x_x884 = kk_src_orchestrator_extract_op(_x_x885, _ctx); /*string*/
  return kk_string_box(_x_x884);
}


// lift anonymous function
struct kk_src_orchestrator_server_loop_fun889__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator_server_loop_fun889(kk_function_t _fself, kk_box_t _b_x243, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator_new_server_loop_fun889(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator_server_loop_fun889, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator_server_loop_fun889(kk_function_t _fself, kk_box_t _b_x243, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x890;
  kk_string_t _x_x891 = kk_string_unbox(_b_x243); /*string*/
  _x_x890 = kk_src_orchestrator_extract_binary(_x_x891, _ctx); /*string*/
  return kk_string_box(_x_x890);
}


// lift anonymous function
struct kk_src_orchestrator_server_loop_fun949__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator_server_loop_fun949(kk_function_t _fself, kk_box_t _b_x252, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator_new_server_loop_fun949(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator_server_loop_fun949, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator_server_loop_fun949(kk_function_t _fself, kk_box_t _b_x252, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x950;
  kk_src_orchestrator__orchestrator_state _x_x951 = kk_src_orchestrator__orchestrator_state_unbox(_b_x252, KK_OWNED, _ctx); /*src/orchestrator/orchestrator-state*/
  _x_x950 = kk_src_orchestrator_health_summary(_x_x951, _ctx); /*string*/
  return kk_string_box(_x_x950);
}


// lift anonymous function
struct kk_src_orchestrator_server_loop_fun955__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator_server_loop_fun955(kk_function_t _fself, kk_box_t _b_x256, kk_box_t _b_x257, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator_new_server_loop_fun955(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator_server_loop_fun955, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator_server_loop_fun955(kk_function_t _fself, kk_box_t _b_x256, kk_box_t _b_x257, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x956;
  kk_string_t _x_x957 = kk_string_unbox(_b_x256); /*string*/
  kk_std_core_types__list _x_x958 = kk_std_core_types__list_unbox(_b_x257, KK_OWNED, _ctx); /*list<src/orchestrator/managed-process>*/
  _x_x956 = kk_src_orchestrator__lift_server_loop_10249(_x_x957, _x_x958, _ctx); /*maybe<src/orchestrator/managed-process>*/
  return kk_std_core_types__maybe_box(_x_x956, _ctx);
}


// lift anonymous function
struct kk_src_orchestrator_server_loop_fun972__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_src_orchestrator_server_loop_fun972(kk_function_t _fself, kk_src_orchestrator__managed_process _this_8_0, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator_new_server_loop_fun972(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator_server_loop_fun972, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_src_orchestrator_server_loop_fun972(kk_function_t _fself, kk_src_orchestrator__managed_process _this_8_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_src_orchestrator_Managed_process* _con_x973 = kk_src_orchestrator__as_Managed_process(_this_8_0, _ctx);
    kk_string_t _pat_0_9_0 = _con_x973->name;
    kk_integer_t _pat_1_11_0 = _con_x973->pid;
    kk_string_t _pat_2_4_0 = _con_x973->binary_path;
    kk_string_t _pat_3_4_0 = _con_x973->status;
    kk_integer_t _x_8_0 = _con_x973->restart_count;
    if kk_likely(kk_datatype_ptr_is_unique(_this_8_0, _ctx)) {
      kk_string_drop(_pat_3_4_0, _ctx);
      kk_string_drop(_pat_2_4_0, _ctx);
      kk_integer_drop(_pat_1_11_0, _ctx);
      kk_string_drop(_pat_0_9_0, _ctx);
      kk_datatype_ptr_free(_this_8_0, _ctx);
    }
    else {
      kk_integer_dup(_x_8_0, _ctx);
      kk_datatype_ptr_decref(_this_8_0, _ctx);
    }
    return _x_8_0;
  }
}


// lift anonymous function
struct kk_src_orchestrator_server_loop_fun986__t {
  struct kk_function_s _base;
  kk_function_t _b_x259_272;
};
static kk_box_t kk_src_orchestrator_server_loop_fun986(kk_function_t _fself, kk_box_t _b_x261, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator_new_server_loop_fun986(kk_function_t _b_x259_272, kk_context_t* _ctx) {
  struct kk_src_orchestrator_server_loop_fun986__t* _self = kk_function_alloc_as(struct kk_src_orchestrator_server_loop_fun986__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_orchestrator_server_loop_fun986, kk_context());
  _self->_b_x259_272 = _b_x259_272;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_orchestrator_server_loop_fun986(kk_function_t _fself, kk_box_t _b_x261, kk_context_t* _ctx) {
  struct kk_src_orchestrator_server_loop_fun986__t* _self = kk_function_as(struct kk_src_orchestrator_server_loop_fun986__t*, _fself, _ctx);
  kk_function_t _b_x259_272 = _self->_b_x259_272; /* (src/orchestrator/managed-process) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x259_272, _ctx);}, {}, _ctx)
  kk_integer_t _x_x987;
  kk_src_orchestrator__managed_process _x_x988 = kk_src_orchestrator__managed_process_unbox(_b_x261, KK_OWNED, _ctx); /*src/orchestrator/managed-process*/
  _x_x987 = kk_function_call(kk_integer_t, (kk_function_t, kk_src_orchestrator__managed_process, kk_context_t*), _b_x259_272, (_b_x259_272, _x_x988, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x987, _ctx);
}


// lift anonymous function
struct kk_src_orchestrator_server_loop_fun992__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator_server_loop_fun992(kk_function_t _fself, kk_box_t _b_x264, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator_new_server_loop_fun992(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator_server_loop_fun992, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator_server_loop_fun992(kk_function_t _fself, kk_box_t _b_x264, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x993;
  kk_src_orchestrator__orchestrator_state _x_x994 = kk_src_orchestrator__orchestrator_state_unbox(_b_x264, KK_OWNED, _ctx); /*src/orchestrator/orchestrator-state*/
  _x_x993 = kk_src_orchestrator_health_summary(_x_x994, _ctx); /*string*/
  return kk_string_box(_x_x993);
}


// lift anonymous function
struct kk_src_orchestrator_server_loop_fun1001__t {
  struct kk_function_s _base;
  kk_src_orchestrator__orchestrator_state state_3;
};
static kk_box_t kk_src_orchestrator_server_loop_fun1001(kk_function_t _fself, kk_box_t _b_x266, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator_new_server_loop_fun1001(kk_src_orchestrator__orchestrator_state state_3, kk_context_t* _ctx) {
  struct kk_src_orchestrator_server_loop_fun1001__t* _self = kk_function_alloc_as(struct kk_src_orchestrator_server_loop_fun1001__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_orchestrator_server_loop_fun1001, kk_context());
  _self->state_3 = state_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_orchestrator_server_loop_fun1001(kk_function_t _fself, kk_box_t _b_x266, kk_context_t* _ctx) {
  struct kk_src_orchestrator_server_loop_fun1001__t* _self = kk_function_as(struct kk_src_orchestrator_server_loop_fun1001__t*, _fself, _ctx);
  kk_src_orchestrator__orchestrator_state state_3 = _self->state_3; /* src/orchestrator/orchestrator-state */
  kk_drop_match(_self, {kk_src_orchestrator__orchestrator_state_dup(state_3, _ctx);}, {}, _ctx)
  kk_string_t _x_x1002;
  kk_std_core_types__list _x_x1003 = kk_std_core_types__list_unbox(_b_x266, KK_OWNED, _ctx); /*list<string>*/
  _x_x1002 = kk_src_orchestrator__mlift_server_loop_10352(state_3, _x_x1003, _ctx); /*string*/
  return kk_string_box(_x_x1002);
}


// lift anonymous function
struct kk_src_orchestrator_server_loop_fun1007__t {
  struct kk_function_s _base;
  kk_string_t binary_1;
  kk_string_t op_1;
  kk_src_orchestrator__orchestrator_state state_3;
};
static kk_box_t kk_src_orchestrator_server_loop_fun1007(kk_function_t _fself, kk_box_t _b_x279, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator_new_server_loop_fun1007(kk_string_t binary_1, kk_string_t op_1, kk_src_orchestrator__orchestrator_state state_3, kk_context_t* _ctx) {
  struct kk_src_orchestrator_server_loop_fun1007__t* _self = kk_function_alloc_as(struct kk_src_orchestrator_server_loop_fun1007__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_orchestrator_server_loop_fun1007, kk_context());
  _self->binary_1 = binary_1;
  _self->op_1 = op_1;
  _self->state_3 = state_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_orchestrator_server_loop_fun1007(kk_function_t _fself, kk_box_t _b_x279, kk_context_t* _ctx) {
  struct kk_src_orchestrator_server_loop_fun1007__t* _self = kk_function_as(struct kk_src_orchestrator_server_loop_fun1007__t*, _fself, _ctx);
  kk_string_t binary_1 = _self->binary_1; /* string */
  kk_string_t op_1 = _self->op_1; /* string */
  kk_src_orchestrator__orchestrator_state state_3 = _self->state_3; /* src/orchestrator/orchestrator-state */
  kk_drop_match(_self, {kk_string_dup(binary_1, _ctx);kk_string_dup(op_1, _ctx);kk_src_orchestrator__orchestrator_state_dup(state_3, _ctx);}, {}, _ctx)
  kk_string_t _c_x10283_1_290 = kk_string_unbox(_b_x279); /*string*/;
  kk_unit_t _x_x1008 = kk_Unit;
  kk_src_orchestrator__mlift_server_loop_10353(binary_1, op_1, state_3, _c_x10283_1_290, _ctx);
  return kk_unit_box(_x_x1008);
}


// lift anonymous function
struct kk_src_orchestrator_server_loop_fun1032__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_orchestrator_server_loop_fun1032(kk_function_t _fself, kk_box_t _b_x285, kk_context_t* _ctx);
static kk_function_t kk_src_orchestrator_new_server_loop_fun1032(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_orchestrator_server_loop_fun1032, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_orchestrator_server_loop_fun1032(kk_function_t _fself, kk_box_t _b_x285, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1033 = kk_Unit;
  kk_src_orchestrator__orchestrator_state _x_x1034 = kk_src_orchestrator__orchestrator_state_unbox(_b_x285, KK_OWNED, _ctx); /*src/orchestrator/orchestrator-state*/
  kk_src_orchestrator_server_loop(_x_x1034, _ctx);
  return kk_unit_box(_x_x1033);
}

kk_unit_t kk_src_orchestrator_server_loop(kk_src_orchestrator__orchestrator_state state_3, kk_context_t* _ctx) { /* (state : orchestrator-state) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_17_10408 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_17_10408, _ctx);
    kk_box_t _x_x863 = kk_std_core_hnd_yield_extend(kk_src_orchestrator_new_server_loop_fun864(state_3, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x863); return kk_Unit;
  }
  {
    bool _match_x292;
    kk_string_t _x_x866 = kk_string_dup(x_17_10408, _ctx); /*string*/
    kk_string_t _x_x867 = kk_string_empty(); /*string*/
    _match_x292 = kk_string_is_eq(_x_x866,_x_x867,kk_context()); /*bool*/
    if (_match_x292) {
      kk_string_drop(x_17_10408, _ctx);
      kk_datatype_ptr_dropn(state_3, (KK_I32(2)), _ctx);
      kk_Unit; return kk_Unit;
    }
    {
      bool _match_x293;
      kk_string_t _x_x869 = kk_string_dup(x_17_10408, _ctx); /*string*/
      kk_string_t _x_x870;
      kk_define_string_literal(, _s_x871, 6, "\"quit\"", _ctx)
      _x_x870 = kk_string_dup(_s_x871, _ctx); /*string*/
      _match_x293 = kk_string_contains(_x_x869,_x_x870,kk_context()); /*bool*/
      if (_match_x293) {
        kk_string_drop(x_17_10408, _ctx);
        kk_evv_t w_13 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_13 = kk_Unit;
        kk_evv_set(w_13,kk_context());
        kk_evv_t w_14 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_integer_t x_17;
        {
          struct kk_src_orchestrator_Orchestrator_state* _con_x872 = kk_src_orchestrator__as_Orchestrator_state(state_3, _ctx);
          kk_std_core_types__list _x_4 = _con_x872->processes;
          kk_integer_t _pat_0_0_1 = _con_x872->total_restarts;
          kk_std_core_types__list_dup(_x_4, _ctx);
          if (kk_std_core_types__is_Nil(_x_4, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(state_3, _ctx)) {
              kk_integer_drop(_pat_0_0_1, _ctx);
              kk_datatype_ptr_free(state_3, _ctx);
            }
            else {
              kk_datatype_ptr_decref(state_3, _ctx);
            }
            x_17 = kk_integer_from_small(0); /*int*/
          }
          else {
            kk_std_core_types__list_drop(_x_4, _ctx);
            kk_std_core_types__list _x_x873;
            {
              struct kk_src_orchestrator_Orchestrator_state* _con_x874 = kk_src_orchestrator__as_Orchestrator_state(state_3, _ctx);
              kk_std_core_types__list _x_4_0 = _con_x874->processes;
              kk_integer_t _pat_0_0_1_0 = _con_x874->total_restarts;
              if kk_likely(kk_datatype_ptr_is_unique(state_3, _ctx)) {
                kk_integer_drop(_pat_0_0_1_0, _ctx);
                kk_datatype_ptr_free(state_3, _ctx);
              }
              else {
                kk_std_core_types__list_dup(_x_4_0, _ctx);
                kk_datatype_ptr_decref(state_3, _ctx);
              }
              _x_x873 = _x_4_0; /*list<src/orchestrator/managed-process>*/
            }
            x_17 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x873, kk_integer_from_small(0), _ctx); /*int*/
          }
        }
        kk_unit_t keep_14 = kk_Unit;
        kk_evv_set(w_14,kk_context());
        kk_string_t _x_x875;
        kk_string_t _x_x876;
        kk_define_string_literal(, _s_x877, 41, "{\"status\":\"stopped\",\"processes_shutdown\":", _ctx)
        _x_x876 = kk_string_dup(_s_x877, _ctx); /*string*/
        kk_string_t _x_x878;
        kk_string_t _x_x879 = kk_std_core_int_show(x_17, _ctx); /*string*/
        kk_string_t _x_x880;
        kk_define_string_literal(, _s_x881, 1, "}", _ctx)
        _x_x880 = kk_string_dup(_s_x881, _ctx); /*string*/
        _x_x878 = kk_std_core_types__lp__plus__plus__rp_(_x_x879, _x_x880, _ctx); /*string*/
        _x_x875 = kk_std_core_types__lp__plus__plus__rp_(_x_x876, _x_x878, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x875, _ctx); return kk_Unit;
      }
      {
        kk_string_t op_1;
        kk_box_t _x_x882;
        kk_box_t _x_x886;
        kk_string_t _x_x887 = kk_string_dup(x_17_10408, _ctx); /*string*/
        _x_x886 = kk_string_box(_x_x887); /*10000*/
        _x_x882 = kk_std_core_hnd__open_none1(kk_src_orchestrator_new_server_loop_fun883(_ctx), _x_x886, _ctx); /*10001*/
        op_1 = kk_string_unbox(_x_x882); /*string*/
        kk_string_t binary_1;
        kk_box_t _x_x888 = kk_std_core_hnd__open_none1(kk_src_orchestrator_new_server_loop_fun889(_ctx), kk_string_box(x_17_10408), _ctx); /*10001*/
        binary_1 = kk_string_unbox(_x_x888); /*string*/
        kk_string_t x_19_10413;
        if (kk_string_cmp_cstr_borrow(op_1, "spawn", _ctx) == 0) {
          bool _match_x302;
          kk_string_t _x_x893 = kk_string_dup(binary_1, _ctx); /*string*/
          kk_string_t _x_x894;
          kk_define_string_literal(, _s_x895, 7, "unknown", _ctx)
          _x_x894 = kk_string_dup(_s_x895, _ctx); /*string*/
          _match_x302 = kk_string_is_eq(_x_x893,_x_x894,kk_context()); /*bool*/
          if (_match_x302) {
            kk_define_string_literal(, _s_x896, 26, "{\"error\":\"unknown binary\"}", _ctx)
            x_19_10413 = kk_string_dup(_s_x896, _ctx); /*string*/
            goto _match_x892;
          }
          {
            kk_src_orchestrator__managed_process new_process_1;
            kk_string_t _x_x897 = kk_string_dup(binary_1, _ctx); /*string*/
            kk_string_t _x_x898;
            kk_string_t _x_x899;
            kk_define_string_literal(, _s_x900, 2, "./", _ctx)
            _x_x899 = kk_string_dup(_s_x900, _ctx); /*string*/
            kk_string_t _x_x901 = kk_string_dup(binary_1, _ctx); /*string*/
            _x_x898 = kk_std_core_types__lp__plus__plus__rp_(_x_x899, _x_x901, _ctx); /*string*/
            kk_string_t _x_x902;
            kk_define_string_literal(, _s_x903, 7, "running", _ctx)
            _x_x902 = kk_string_dup(_s_x903, _ctx); /*string*/
            new_process_1 = kk_src_orchestrator__new_Managed_process(kk_reuse_null, 0, _x_x897, kk_integer_from_small(0), _x_x898, _x_x902, 0x0p+0, kk_integer_from_small(0), _ctx); /*src/orchestrator/managed-process*/
            kk_evv_t w_15 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_15 = kk_Unit;
            kk_evv_set(w_15,kk_context());
            kk_evv_t w_14_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_14_0 = kk_Unit;
            kk_evv_set(w_14_0,kk_context());
            kk_evv_t w_16 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_16 = kk_Unit;
            kk_evv_set(w_16,kk_context());
            kk_evv_t w_17 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_std_core_types__list xs_0_0_10474;
            kk_std_core_types__list _x_x904;
            {
              struct kk_src_orchestrator_Orchestrator_state* _con_x905 = kk_src_orchestrator__as_Orchestrator_state(state_3, _ctx);
              kk_std_core_types__list _x_0_0_0 = _con_x905->processes;
              kk_std_core_types__list_dup(_x_0_0_0, _ctx);
              _x_x904 = _x_0_0_0; /*list<src/orchestrator/managed-process>*/
            }
            xs_0_0_10474 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_src_orchestrator__managed_process_box(new_process_1, _ctx), _x_x904, _ctx); /*list<src/orchestrator/managed-process>*/
            kk_integer_t x_19;
            if (kk_std_core_types__is_Nil(xs_0_0_10474, _ctx)) {
              x_19 = kk_integer_from_small(0); /*int*/
            }
            else {
              x_19 = kk_std_core_list__unroll_lift_length_5730_10000(xs_0_0_10474, kk_integer_from_small(0), _ctx); /*int*/
            }
            kk_unit_t keep_17 = kk_Unit;
            kk_evv_set(w_17,kk_context());
            kk_string_t _x_x906;
            kk_define_string_literal(, _s_x907, 12, "{\"spawned\":\"", _ctx)
            _x_x906 = kk_string_dup(_s_x907, _ctx); /*string*/
            kk_string_t _x_x908;
            kk_string_t _x_x909 = kk_string_dup(binary_1, _ctx); /*string*/
            kk_string_t _x_x910;
            kk_string_t _x_x911;
            kk_define_string_literal(, _s_x912, 39, "\",\"status\":\"running\",\"total_processes\":", _ctx)
            _x_x911 = kk_string_dup(_s_x912, _ctx); /*string*/
            kk_string_t _x_x913;
            kk_string_t _x_x914 = kk_std_core_int_show(x_19, _ctx); /*string*/
            kk_string_t _x_x915;
            kk_define_string_literal(, _s_x916, 1, "}", _ctx)
            _x_x915 = kk_string_dup(_s_x916, _ctx); /*string*/
            _x_x913 = kk_std_core_types__lp__plus__plus__rp_(_x_x914, _x_x915, _ctx); /*string*/
            _x_x910 = kk_std_core_types__lp__plus__plus__rp_(_x_x911, _x_x913, _ctx); /*string*/
            _x_x908 = kk_std_core_types__lp__plus__plus__rp_(_x_x909, _x_x910, _ctx); /*string*/
            x_19_10413 = kk_std_core_types__lp__plus__plus__rp_(_x_x906, _x_x908, _ctx); /*string*/
            goto _match_x892;
          }
        }
        if (kk_string_cmp_cstr_borrow(op_1, "stop", _ctx) == 0) {
          bool _match_x301;
          kk_string_t _x_x917 = kk_string_dup(binary_1, _ctx); /*string*/
          kk_string_t _x_x918;
          kk_define_string_literal(, _s_x919, 7, "unknown", _ctx)
          _x_x918 = kk_string_dup(_s_x919, _ctx); /*string*/
          _match_x301 = kk_string_is_eq(_x_x917,_x_x918,kk_context()); /*bool*/
          if (_match_x301) {
            kk_define_string_literal(, _s_x920, 26, "{\"error\":\"unknown binary\"}", _ctx)
            x_19_10413 = kk_string_dup(_s_x920, _ctx); /*string*/
            goto _match_x892;
          }
          {
            kk_string_t _x_x921;
            kk_define_string_literal(, _s_x922, 12, "{\"stopped\":\"", _ctx)
            _x_x921 = kk_string_dup(_s_x922, _ctx); /*string*/
            kk_string_t _x_x923;
            kk_string_t _x_x924 = kk_string_dup(binary_1, _ctx); /*string*/
            kk_string_t _x_x925;
            kk_define_string_literal(, _s_x926, 2, "\"}", _ctx)
            _x_x925 = kk_string_dup(_s_x926, _ctx); /*string*/
            _x_x923 = kk_std_core_types__lp__plus__plus__rp_(_x_x924, _x_x925, _ctx); /*string*/
            x_19_10413 = kk_std_core_types__lp__plus__plus__rp_(_x_x921, _x_x923, _ctx); /*string*/
            goto _match_x892;
          }
        }
        if (kk_string_cmp_cstr_borrow(op_1, "restart", _ctx) == 0) {
          bool _match_x300;
          kk_string_t _x_x927 = kk_string_dup(binary_1, _ctx); /*string*/
          kk_string_t _x_x928;
          kk_define_string_literal(, _s_x929, 7, "unknown", _ctx)
          _x_x928 = kk_string_dup(_s_x929, _ctx); /*string*/
          _match_x300 = kk_string_is_eq(_x_x927,_x_x928,kk_context()); /*bool*/
          if (_match_x300) {
            kk_define_string_literal(, _s_x930, 26, "{\"error\":\"unknown binary\"}", _ctx)
            x_19_10413 = kk_string_dup(_s_x930, _ctx); /*string*/
            goto _match_x892;
          }
          {
            kk_evv_t w_17_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_17_0 = kk_Unit;
            kk_evv_set(w_17_0,kk_context());
            kk_string_t _x_x931;
            kk_define_string_literal(, _s_x932, 14, "{\"restarted\":\"", _ctx)
            _x_x931 = kk_string_dup(_s_x932, _ctx); /*string*/
            kk_string_t _x_x933;
            kk_string_t _x_x934 = kk_string_dup(binary_1, _ctx); /*string*/
            kk_string_t _x_x935;
            kk_string_t _x_x936;
            kk_define_string_literal(, _s_x937, 18, "\",\"restart_count\":", _ctx)
            _x_x936 = kk_string_dup(_s_x937, _ctx); /*string*/
            kk_string_t _x_x938;
            kk_string_t _x_x939;
            kk_integer_t _x_x940;
            kk_integer_t _x_x941;
            {
              struct kk_src_orchestrator_Orchestrator_state* _con_x942 = kk_src_orchestrator__as_Orchestrator_state(state_3, _ctx);
              kk_integer_t _x_3_0 = _con_x942->total_restarts;
              kk_integer_dup(_x_3_0, _ctx);
              _x_x941 = _x_3_0; /*int*/
            }
            _x_x940 = kk_integer_add_small_const(_x_x941, 1, _ctx); /*int*/
            _x_x939 = kk_std_core_int_show(_x_x940, _ctx); /*string*/
            kk_string_t _x_x943;
            kk_define_string_literal(, _s_x944, 1, "}", _ctx)
            _x_x943 = kk_string_dup(_s_x944, _ctx); /*string*/
            _x_x938 = kk_std_core_types__lp__plus__plus__rp_(_x_x939, _x_x943, _ctx); /*string*/
            _x_x935 = kk_std_core_types__lp__plus__plus__rp_(_x_x936, _x_x938, _ctx); /*string*/
            _x_x933 = kk_std_core_types__lp__plus__plus__rp_(_x_x934, _x_x935, _ctx); /*string*/
            x_19_10413 = kk_std_core_types__lp__plus__plus__rp_(_x_x931, _x_x933, _ctx); /*string*/
            goto _match_x892;
          }
        }
        if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
          bool _match_x298;
          kk_string_t _x_x945 = kk_string_dup(binary_1, _ctx); /*string*/
          kk_string_t _x_x946;
          kk_define_string_literal(, _s_x947, 7, "unknown", _ctx)
          _x_x946 = kk_string_dup(_s_x947, _ctx); /*string*/
          _match_x298 = kk_string_is_eq(_x_x945,_x_x946,kk_context()); /*bool*/
          if (_match_x298) {
            kk_box_t _x_x948;
            kk_box_t _x_x952;
            kk_src_orchestrator__orchestrator_state _x_x953 = kk_src_orchestrator__orchestrator_state_dup(state_3, _ctx); /*src/orchestrator/orchestrator-state*/
            _x_x952 = kk_src_orchestrator__orchestrator_state_box(_x_x953, _ctx); /*10000*/
            _x_x948 = kk_std_core_hnd__open_none1(kk_src_orchestrator_new_server_loop_fun949(_ctx), _x_x952, _ctx); /*10001*/
            x_19_10413 = kk_string_unbox(_x_x948); /*string*/
            goto _match_x892;
          }
          {
            kk_evv_t w_18 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_18 = kk_Unit;
            kk_evv_set(w_18,kk_context());
            kk_std_core_types__maybe _match_x299;
            kk_box_t _x_x954;
            kk_box_t _x_x959;
            kk_string_t _x_x960 = kk_string_dup(binary_1, _ctx); /*string*/
            _x_x959 = kk_string_box(_x_x960); /*10000*/
            kk_box_t _x_x961;
            kk_std_core_types__list _x_x962;
            {
              struct kk_src_orchestrator_Orchestrator_state* _con_x963 = kk_src_orchestrator__as_Orchestrator_state(state_3, _ctx);
              kk_std_core_types__list _x_5_0 = _con_x963->processes;
              kk_std_core_types__list_dup(_x_5_0, _ctx);
              _x_x962 = _x_5_0; /*list<src/orchestrator/managed-process>*/
            }
            _x_x961 = kk_std_core_types__list_box(_x_x962, _ctx); /*10001*/
            _x_x954 = kk_std_core_hnd__open_none2(kk_src_orchestrator_new_server_loop_fun955(_ctx), _x_x959, _x_x961, _ctx); /*10002*/
            _match_x299 = kk_std_core_types__maybe_unbox(_x_x954, KK_OWNED, _ctx); /*maybe<src/orchestrator/managed-process>*/
            if (kk_std_core_types__is_Nothing(_match_x299, _ctx)) {
              kk_define_string_literal(, _s_x964, 29, "{\"error\":\"process not found\"}", _ctx)
              x_19_10413 = kk_string_dup(_s_x964, _ctx); /*string*/
              goto _match_x892;
            }
            {
              kk_box_t _box_x258 = _match_x299._cons.Just.value;
              kk_src_orchestrator__managed_process p_0_0 = kk_src_orchestrator__managed_process_unbox(_box_x258, KK_BORROWED, _ctx);
              struct kk_src_orchestrator_Managed_process* _con_x965 = kk_src_orchestrator__as_Managed_process(p_0_0, _ctx);
              kk_src_orchestrator__managed_process_dup(p_0_0, _ctx);
              kk_std_core_types__maybe_drop(_match_x299, _ctx);
              kk_evv_t w_19 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
              kk_unit_t keep_19 = kk_Unit;
              kk_evv_set(w_19,kk_context());
              kk_evv_t w_20 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
              kk_unit_t keep_20 = kk_Unit;
              kk_evv_set(w_20,kk_context());
              kk_string_t _x_x966;
              kk_define_string_literal(, _s_x967, 9, "{\"name\":\"", _ctx)
              _x_x966 = kk_string_dup(_s_x967, _ctx); /*string*/
              kk_string_t _x_x968;
              kk_string_t _x_x969;
              {
                struct kk_src_orchestrator_Managed_process* _con_x970 = kk_src_orchestrator__as_Managed_process(p_0_0, _ctx);
                kk_string_t _x_6_0 = _con_x970->name;
                kk_string_dup(_x_6_0, _ctx);
                _x_x969 = _x_6_0; /*string*/
              }
              kk_string_t _x_x971;
              kk_function_t _b_x259_272 = kk_src_orchestrator_new_server_loop_fun972(_ctx); /*(src/orchestrator/managed-process) -> int*/;
              kk_src_orchestrator__managed_process _b_x260_273 = kk_src_orchestrator__managed_process_dup(p_0_0, _ctx); /*src/orchestrator/managed-process*/;
              kk_string_t _x_x974;
              kk_define_string_literal(, _s_x975, 12, "\",\"status\":\"", _ctx)
              _x_x974 = kk_string_dup(_s_x975, _ctx); /*string*/
              kk_string_t _x_x976;
              kk_string_t _x_x977;
              {
                struct kk_src_orchestrator_Managed_process* _con_x978 = kk_src_orchestrator__as_Managed_process(p_0_0, _ctx);
                kk_string_t _pat_0_8_0 = _con_x978->name;
                kk_integer_t _pat_1_10_0 = _con_x978->pid;
                kk_string_t _pat_2_3_0 = _con_x978->binary_path;
                kk_string_t _x_7_0 = _con_x978->status;
                kk_integer_t _pat_4_2_0 = _con_x978->restart_count;
                if kk_likely(kk_datatype_ptr_is_unique(p_0_0, _ctx)) {
                  kk_integer_drop(_pat_4_2_0, _ctx);
                  kk_string_drop(_pat_2_3_0, _ctx);
                  kk_integer_drop(_pat_1_10_0, _ctx);
                  kk_string_drop(_pat_0_8_0, _ctx);
                  kk_datatype_ptr_free(p_0_0, _ctx);
                }
                else {
                  kk_string_dup(_x_7_0, _ctx);
                  kk_datatype_ptr_decref(p_0_0, _ctx);
                }
                _x_x977 = _x_7_0; /*string*/
              }
              kk_string_t _x_x979;
              kk_string_t _x_x980;
              kk_define_string_literal(, _s_x981, 13, "\",\"restarts\":", _ctx)
              _x_x980 = kk_string_dup(_s_x981, _ctx); /*string*/
              kk_string_t _x_x982;
              kk_string_t _x_x983;
              kk_integer_t _x_x984;
              kk_box_t _x_x985 = kk_std_core_hnd__open_none1(kk_src_orchestrator_new_server_loop_fun986(_b_x259_272, _ctx), kk_src_orchestrator__managed_process_box(_b_x260_273, _ctx), _ctx); /*10001*/
              _x_x984 = kk_integer_unbox(_x_x985, _ctx); /*int*/
              _x_x983 = kk_std_core_int_show(_x_x984, _ctx); /*string*/
              kk_string_t _x_x989;
              kk_define_string_literal(, _s_x990, 1, "}", _ctx)
              _x_x989 = kk_string_dup(_s_x990, _ctx); /*string*/
              _x_x982 = kk_std_core_types__lp__plus__plus__rp_(_x_x983, _x_x989, _ctx); /*string*/
              _x_x979 = kk_std_core_types__lp__plus__plus__rp_(_x_x980, _x_x982, _ctx); /*string*/
              _x_x976 = kk_std_core_types__lp__plus__plus__rp_(_x_x977, _x_x979, _ctx); /*string*/
              _x_x971 = kk_std_core_types__lp__plus__plus__rp_(_x_x974, _x_x976, _ctx); /*string*/
              _x_x968 = kk_std_core_types__lp__plus__plus__rp_(_x_x969, _x_x971, _ctx); /*string*/
              x_19_10413 = kk_std_core_types__lp__plus__plus__rp_(_x_x966, _x_x968, _ctx); /*string*/
              goto _match_x892;
            }
          }
        }
        if (kk_string_cmp_cstr_borrow(op_1, "health", _ctx) == 0) {
          kk_box_t _x_x991;
          kk_box_t _x_x995;
          kk_src_orchestrator__orchestrator_state _x_x996 = kk_src_orchestrator__orchestrator_state_dup(state_3, _ctx); /*src/orchestrator/orchestrator-state*/
          _x_x995 = kk_src_orchestrator__orchestrator_state_box(_x_x996, _ctx); /*10000*/
          _x_x991 = kk_std_core_hnd__open_none1(kk_src_orchestrator_new_server_loop_fun992(_ctx), _x_x995, _ctx); /*10001*/
          x_19_10413 = kk_string_unbox(_x_x991); /*string*/
          goto _match_x892;
        }
        if (kk_string_cmp_cstr_borrow(op_1, "list", _ctx) == 0) {
          kk_evv_t w_20_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_20_0 = kk_Unit;
          kk_evv_set(w_20_0,kk_context());
          kk_std_core_types__list x_26_10428;
          kk_std_core_types__list _x_x997;
          {
            struct kk_src_orchestrator_Orchestrator_state* _con_x998 = kk_src_orchestrator__as_Orchestrator_state(state_3, _ctx);
            kk_std_core_types__list _x_9_0 = _con_x998->processes;
            kk_std_core_types__list_dup(_x_9_0, _ctx);
            _x_x997 = _x_9_0; /*list<src/orchestrator/managed-process>*/
          }
          x_26_10428 = kk_src_orchestrator__lift_server_loop_10251(_x_x997, _ctx); /*list<string>*/
          if (kk_yielding(kk_context())) {
            kk_std_core_types__list_drop(x_26_10428, _ctx);
            kk_box_t _x_x999;
            kk_function_t _x_x1000;
            kk_src_orchestrator__orchestrator_state_dup(state_3, _ctx);
            _x_x1000 = kk_src_orchestrator_new_server_loop_fun1001(state_3, _ctx); /*(10000) -> 10002 10001*/
            _x_x999 = kk_std_core_hnd_yield_extend(_x_x1000, _ctx); /*10001*/
            x_19_10413 = kk_string_unbox(_x_x999); /*string*/
            goto _match_x892;
          }
          {
            kk_src_orchestrator__orchestrator_state _x_x1004 = kk_src_orchestrator__orchestrator_state_dup(state_3, _ctx); /*src/orchestrator/orchestrator-state*/
            x_19_10413 = kk_src_orchestrator__mlift_server_loop_10352(_x_x1004, x_26_10428, _ctx); /*string*/
            goto _match_x892;
          }
        }
        {
          kk_define_string_literal(, _s_x1005, 27, "{\"error\":\"unknown command\"}", _ctx)
          x_19_10413 = kk_string_dup(_s_x1005, _ctx); /*string*/
        }
        _match_x892: ;
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_19_10413, _ctx);
          kk_box_t _x_x1006 = kk_std_core_hnd_yield_extend(kk_src_orchestrator_new_server_loop_fun1007(binary_1, op_1, state_3, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x1006); return kk_Unit;
        }
        {
          kk_unit_t ___0 = kk_Unit;
          kk_std_core_console_printsln(x_19_10413, _ctx);
          kk_src_orchestrator__orchestrator_state x_28_10432;
          if (kk_string_cmp_cstr_borrow(op_1, "spawn", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            bool _match_x296;
            kk_string_t _x_x1010 = kk_string_dup(binary_1, _ctx); /*string*/
            kk_string_t _x_x1011;
            kk_define_string_literal(, _s_x1012, 7, "unknown", _ctx)
            _x_x1011 = kk_string_dup(_s_x1012, _ctx); /*string*/
            _match_x296 = kk_string_is_neq(_x_x1010,_x_x1011,kk_context()); /*bool*/
            if (_match_x296) {
              kk_src_orchestrator__managed_process new_process_0_0;
              kk_string_t _x_x1013 = kk_string_dup(binary_1, _ctx); /*string*/
              kk_string_t _x_x1014;
              kk_string_t _x_x1015;
              kk_define_string_literal(, _s_x1016, 2, "./", _ctx)
              _x_x1015 = kk_string_dup(_s_x1016, _ctx); /*string*/
              _x_x1014 = kk_std_core_types__lp__plus__plus__rp_(_x_x1015, binary_1, _ctx); /*string*/
              kk_string_t _x_x1017;
              kk_define_string_literal(, _s_x1018, 7, "running", _ctx)
              _x_x1017 = kk_string_dup(_s_x1018, _ctx); /*string*/
              new_process_0_0 = kk_src_orchestrator__new_Managed_process(kk_reuse_null, 0, _x_x1013, kk_integer_from_small(0), _x_x1014, _x_x1017, 0x0p+0, kk_integer_from_small(0), _ctx); /*src/orchestrator/managed-process*/
              kk_evv_t w_22 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
              kk_unit_t keep_22 = kk_Unit;
              kk_evv_set(w_22,kk_context());
              kk_evv_t w_21 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
              kk_unit_t keep_21 = kk_Unit;
              kk_evv_set(w_21,kk_context());
              kk_std_core_types__list _x_x1019;
              kk_std_core_types__list _x_x1020;
              {
                struct kk_src_orchestrator_Orchestrator_state* _con_x1021 = kk_src_orchestrator__as_Orchestrator_state(state_3, _ctx);
                kk_std_core_types__list _x_12_0 = _con_x1021->processes;
                kk_std_core_types__list_dup(_x_12_0, _ctx);
                _x_x1020 = _x_12_0; /*list<src/orchestrator/managed-process>*/
              }
              _x_x1019 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_src_orchestrator__managed_process_box(new_process_0_0, _ctx), _x_x1020, _ctx); /*list<10021>*/
              kk_integer_t _x_x1022;
              {
                struct kk_src_orchestrator_Orchestrator_state* _con_x1023 = kk_src_orchestrator__as_Orchestrator_state(state_3, _ctx);
                kk_std_core_types__list _pat_0_14_0 = _con_x1023->processes;
                kk_integer_t _x_13_0 = _con_x1023->total_restarts;
                if kk_likely(kk_datatype_ptr_is_unique(state_3, _ctx)) {
                  kk_std_core_types__list_drop(_pat_0_14_0, _ctx);
                  kk_datatype_ptr_free(state_3, _ctx);
                }
                else {
                  kk_integer_dup(_x_13_0, _ctx);
                  kk_datatype_ptr_decref(state_3, _ctx);
                }
                _x_x1022 = _x_13_0; /*int*/
              }
              x_28_10432 = kk_src_orchestrator__new_Orchestrator_state(kk_reuse_null, 0, _x_x1019, _x_x1022, 0x0p+0, _ctx); /*src/orchestrator/orchestrator-state*/
              goto _match_x1009;
            }
            {
              kk_string_drop(binary_1, _ctx);
              x_28_10432 = state_3; /*src/orchestrator/orchestrator-state*/
              goto _match_x1009;
            }
          }
          if (kk_string_cmp_cstr_borrow(op_1, "restart", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_string_drop(binary_1, _ctx);
            kk_evv_t w_23 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_23 = kk_Unit;
            kk_evv_set(w_23,kk_context());
            kk_evv_t w_24 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_24 = kk_Unit;
            kk_evv_set(w_24,kk_context());
            kk_evv_t w_25 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_25 = kk_Unit;
            kk_evv_set(w_25,kk_context());
            kk_std_core_types__list _x_x1024;
            {
              struct kk_src_orchestrator_Orchestrator_state* _con_x1025 = kk_src_orchestrator__as_Orchestrator_state(state_3, _ctx);
              kk_std_core_types__list _x_14_0 = _con_x1025->processes;
              kk_std_core_types__list_dup(_x_14_0, _ctx);
              _x_x1024 = _x_14_0; /*list<src/orchestrator/managed-process>*/
            }
            kk_integer_t _x_x1026;
            kk_integer_t _x_x1027;
            {
              struct kk_src_orchestrator_Orchestrator_state* _con_x1028 = kk_src_orchestrator__as_Orchestrator_state(state_3, _ctx);
              kk_integer_t _x_15_0 = _con_x1028->total_restarts;
              kk_integer_dup(_x_15_0, _ctx);
              _x_x1027 = _x_15_0; /*int*/
            }
            _x_x1026 = kk_integer_add_small_const(_x_x1027, 1, _ctx); /*int*/
            double _x_x1029;
            {
              struct kk_src_orchestrator_Orchestrator_state* _con_x1030 = kk_src_orchestrator__as_Orchestrator_state(state_3, _ctx);
              kk_std_core_types__list _pat_0_17_0 = _con_x1030->processes;
              kk_integer_t _pat_1_20_0 = _con_x1030->total_restarts;
              double _x_16_0 = _con_x1030->last_health_check;
              if kk_likely(kk_datatype_ptr_is_unique(state_3, _ctx)) {
                kk_integer_drop(_pat_1_20_0, _ctx);
                kk_std_core_types__list_drop(_pat_0_17_0, _ctx);
                kk_datatype_ptr_free(state_3, _ctx);
              }
              else {
                kk_datatype_ptr_decref(state_3, _ctx);
              }
              _x_x1029 = _x_16_0; /*float64*/
            }
            x_28_10432 = kk_src_orchestrator__new_Orchestrator_state(kk_reuse_null, 0, _x_x1024, _x_x1026, _x_x1029, _ctx); /*src/orchestrator/orchestrator-state*/
            goto _match_x1009;
          }
          {
            kk_string_drop(op_1, _ctx);
            kk_string_drop(binary_1, _ctx);
            x_28_10432 = state_3; /*src/orchestrator/orchestrator-state*/
          }
          _match_x1009: ;
          if (kk_yielding(kk_context())) {
            kk_datatype_ptr_dropn(x_28_10432, (KK_I32(2)), _ctx);
            kk_box_t _x_x1031 = kk_std_core_hnd_yield_extend(kk_src_orchestrator_new_server_loop_fun1032(_ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x1031); return kk_Unit;
          }
          { // tailcall
            state_3 = x_28_10432;
            goto kk__tailcall;
          }
        }
      }
    }
  }
}

kk_unit_t kk_src_orchestrator_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_integer_t x;
  kk_std_core_types__list _x_x1035 = kk_src_orchestrator_binary_registry; /*list<(string, string)>*/
  if (kk_std_core_types__is_Nil(_x_x1035, _ctx)) {
    x = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_std_core_types__list _x_x1036 = kk_std_core_types__list_dup(kk_src_orchestrator_binary_registry, _ctx); /*list<(string, string)>*/
    x = kk_std_core_list__unroll_lift_length_5730_10000(_x_x1036, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x1037;
  kk_string_t _x_x1038;
  kk_define_string_literal(, _s_x1039, 75, "{\"status\":\"started\",\"orchestrator\":true,\"version\":\"7.0\",\"managed_binaries\":", _ctx)
  _x_x1038 = kk_string_dup(_s_x1039, _ctx); /*string*/
  kk_string_t _x_x1040;
  kk_string_t _x_x1041 = kk_std_core_int_show(x, _ctx); /*string*/
  kk_string_t _x_x1042;
  kk_define_string_literal(, _s_x1043, 55, ",\"features\":[\"spawn\",\"stop\",\"restart\",\"health\",\"list\"]}", _ctx)
  _x_x1042 = kk_string_dup(_s_x1043, _ctx); /*string*/
  _x_x1040 = kk_std_core_types__lp__plus__plus__rp_(_x_x1041, _x_x1042, _ctx); /*string*/
  _x_x1037 = kk_std_core_types__lp__plus__plus__rp_(_x_x1038, _x_x1040, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x1037, _ctx);
  kk_src_orchestrator__orchestrator_state _x_x1044 = kk_src_orchestrator__new_Orchestrator_state(kk_reuse_null, 0, kk_std_core_types__new_Nil(_ctx), kk_integer_from_small(0), 0x0p+0, _ctx); /*src/orchestrator/orchestrator-state*/
  kk_src_orchestrator_server_loop(_x_x1044, _ctx); return kk_Unit;
}

// initialization
void kk_src_orchestrator__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_bool__init(_ctx);
  kk_std_core_order__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_vector__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_sslice__init(_ctx);
  kk_std_core_list__init(_ctx);
  kk_std_core_maybe__init(_ctx);
  kk_std_core_maybe2__init(_ctx);
  kk_std_core_either__init(_ctx);
  kk_std_core_tuple__init(_ctx);
  kk_std_core_lazy__init(_ctx);
  kk_std_core_show__init(_ctx);
  kk_std_core_debug__init(_ctx);
  kk_std_core_delayed__init(_ctx);
  kk_std_core_console__init(_ctx);
  kk_std_time_duration__init(_ctx);
  kk_std_time_instant__init(_ctx);
  kk_std_time_utc__init(_ctx);
  kk_std_time_chrono__init(_ctx);
  kk_std_time_timer__init(_ctx);
  kk_std_time_date__init(_ctx);
  kk_std_time_calendar__init(_ctx);
  kk_std_time_calendars__init(_ctx);
  kk_std_time_time__init(_ctx);
  kk_std_time_locale__init(_ctx);
  kk_std_time_format__init(_ctx);
  kk_std_time_parse__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_os_readline__init(_ctx);
  kk_std_os_process__init(_ctx);
  kk_std_num_float64__init(_ctx);
  kk_std_num_int64__init(_ctx);
  kk_std_time__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_box_t _x_x419;
    kk_std_core_types__tuple2 _x_x420;
    kk_box_t _x_x421;
    kk_string_t _x_x422;
    kk_define_string_literal(, _s_x423, 18, "unified_runtime_v3", _ctx)
    _x_x422 = kk_string_dup(_s_x423, _ctx); /*string*/
    _x_x421 = kk_string_box(_x_x422); /*10037*/
    kk_box_t _x_x424;
    kk_string_t _x_x425;
    kk_define_string_literal(, _s_x426, 20, "./unified_runtime_v3", _ctx)
    _x_x425 = kk_string_dup(_s_x426, _ctx); /*string*/
    _x_x424 = kk_string_box(_x_x425); /*10038*/
    _x_x420 = kk_std_core_types__new_Tuple2(_x_x421, _x_x424, _ctx); /*(10037, 10038)*/
    _x_x419 = kk_std_core_types__tuple2_box(_x_x420, _ctx); /*10021*/
    kk_std_core_types__list _x_x427;
    kk_box_t _x_x428;
    kk_std_core_types__tuple2 _x_x429;
    kk_box_t _x_x430;
    kk_string_t _x_x431;
    kk_define_string_literal(, _s_x432, 14, "effect_runtime", _ctx)
    _x_x431 = kk_string_dup(_s_x432, _ctx); /*string*/
    _x_x430 = kk_string_box(_x_x431); /*10037*/
    kk_box_t _x_x433;
    kk_string_t _x_x434;
    kk_define_string_literal(, _s_x435, 16, "./effect_runtime", _ctx)
    _x_x434 = kk_string_dup(_s_x435, _ctx); /*string*/
    _x_x433 = kk_string_box(_x_x434); /*10038*/
    _x_x429 = kk_std_core_types__new_Tuple2(_x_x430, _x_x433, _ctx); /*(10037, 10038)*/
    _x_x428 = kk_std_core_types__tuple2_box(_x_x429, _ctx); /*10021*/
    kk_std_core_types__list _x_x436;
    kk_box_t _x_x437;
    kk_std_core_types__tuple2 _x_x438;
    kk_box_t _x_x439;
    kk_string_t _x_x440;
    kk_define_string_literal(, _s_x441, 11, "ring_buffer", _ctx)
    _x_x440 = kk_string_dup(_s_x441, _ctx); /*string*/
    _x_x439 = kk_string_box(_x_x440); /*10037*/
    kk_box_t _x_x442;
    kk_string_t _x_x443;
    kk_define_string_literal(, _s_x444, 13, "./ring_buffer", _ctx)
    _x_x443 = kk_string_dup(_s_x444, _ctx); /*string*/
    _x_x442 = kk_string_box(_x_x443); /*10038*/
    _x_x438 = kk_std_core_types__new_Tuple2(_x_x439, _x_x442, _ctx); /*(10037, 10038)*/
    _x_x437 = kk_std_core_types__tuple2_box(_x_x438, _ctx); /*10021*/
    kk_std_core_types__list _x_x445;
    kk_box_t _x_x446;
    kk_std_core_types__tuple2 _x_x447;
    kk_box_t _x_x448;
    kk_string_t _x_x449;
    kk_define_string_literal(, _s_x450, 11, "rust_bridge", _ctx)
    _x_x449 = kk_string_dup(_s_x450, _ctx); /*string*/
    _x_x448 = kk_string_box(_x_x449); /*10037*/
    kk_box_t _x_x451;
    kk_string_t _x_x452;
    kk_define_string_literal(, _s_x453, 13, "./rust_bridge", _ctx)
    _x_x452 = kk_string_dup(_s_x453, _ctx); /*string*/
    _x_x451 = kk_string_box(_x_x452); /*10038*/
    _x_x447 = kk_std_core_types__new_Tuple2(_x_x448, _x_x451, _ctx); /*(10037, 10038)*/
    _x_x446 = kk_std_core_types__tuple2_box(_x_x447, _ctx); /*10021*/
    kk_std_core_types__list _x_x454;
    kk_box_t _x_x455;
    kk_std_core_types__tuple2 _x_x456;
    kk_box_t _x_x457;
    kk_string_t _x_x458;
    kk_define_string_literal(, _s_x459, 4, "prat", _ctx)
    _x_x458 = kk_string_dup(_s_x459, _ctx); /*string*/
    _x_x457 = kk_string_box(_x_x458); /*10037*/
    kk_box_t _x_x460;
    kk_string_t _x_x461;
    kk_define_string_literal(, _s_x462, 6, "./prat", _ctx)
    _x_x461 = kk_string_dup(_s_x462, _ctx); /*string*/
    _x_x460 = kk_string_box(_x_x461); /*10038*/
    _x_x456 = kk_std_core_types__new_Tuple2(_x_x457, _x_x460, _ctx); /*(10037, 10038)*/
    _x_x455 = kk_std_core_types__tuple2_box(_x_x456, _ctx); /*10021*/
    kk_std_core_types__list _x_x463;
    kk_box_t _x_x464;
    kk_std_core_types__tuple2 _x_x465;
    kk_box_t _x_x466;
    kk_string_t _x_x467;
    kk_define_string_literal(, _s_x468, 8, "gan_ying", _ctx)
    _x_x467 = kk_string_dup(_s_x468, _ctx); /*string*/
    _x_x466 = kk_string_box(_x_x467); /*10037*/
    kk_box_t _x_x469;
    kk_string_t _x_x470;
    kk_define_string_literal(, _s_x471, 10, "./gan_ying", _ctx)
    _x_x470 = kk_string_dup(_s_x471, _ctx); /*string*/
    _x_x469 = kk_string_box(_x_x470); /*10038*/
    _x_x465 = kk_std_core_types__new_Tuple2(_x_x466, _x_x469, _ctx); /*(10037, 10038)*/
    _x_x464 = kk_std_core_types__tuple2_box(_x_x465, _ctx); /*10021*/
    kk_std_core_types__list _x_x472;
    kk_box_t _x_x473;
    kk_std_core_types__tuple2 _x_x474;
    kk_box_t _x_x475;
    kk_string_t _x_x476;
    kk_define_string_literal(, _s_x477, 9, "hot_paths", _ctx)
    _x_x476 = kk_string_dup(_s_x477, _ctx); /*string*/
    _x_x475 = kk_string_box(_x_x476); /*10037*/
    kk_box_t _x_x478;
    kk_string_t _x_x479;
    kk_define_string_literal(, _s_x480, 11, "./hot_paths", _ctx)
    _x_x479 = kk_string_dup(_s_x480, _ctx); /*string*/
    _x_x478 = kk_string_box(_x_x479); /*10038*/
    _x_x474 = kk_std_core_types__new_Tuple2(_x_x475, _x_x478, _ctx); /*(10037, 10038)*/
    _x_x473 = kk_std_core_types__tuple2_box(_x_x474, _ctx); /*10021*/
    kk_std_core_types__list _x_x481;
    kk_box_t _x_x482;
    kk_std_core_types__tuple2 _x_x483;
    kk_box_t _x_x484;
    kk_string_t _x_x485;
    kk_define_string_literal(, _s_x486, 9, "resonance", _ctx)
    _x_x485 = kk_string_dup(_s_x486, _ctx); /*string*/
    _x_x484 = kk_string_box(_x_x485); /*10037*/
    kk_box_t _x_x487;
    kk_string_t _x_x488;
    kk_define_string_literal(, _s_x489, 11, "./resonance", _ctx)
    _x_x488 = kk_string_dup(_s_x489, _ctx); /*string*/
    _x_x487 = kk_string_box(_x_x488); /*10038*/
    _x_x483 = kk_std_core_types__new_Tuple2(_x_x484, _x_x487, _ctx); /*(10037, 10038)*/
    _x_x482 = kk_std_core_types__tuple2_box(_x_x483, _ctx); /*10021*/
    _x_x481 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x482, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x472 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x473, _x_x481, _ctx); /*list<10021>*/
    _x_x463 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x464, _x_x472, _ctx); /*list<10021>*/
    _x_x454 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x455, _x_x463, _ctx); /*list<10021>*/
    _x_x445 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x446, _x_x454, _ctx); /*list<10021>*/
    _x_x436 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x437, _x_x445, _ctx); /*list<10021>*/
    _x_x427 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x428, _x_x436, _ctx); /*list<10021>*/
    kk_src_orchestrator_binary_registry = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x419, _x_x427, _ctx); /*list<(string, string)>*/
  }
}

// termination
void kk_src_orchestrator__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_types__list_drop(kk_src_orchestrator_binary_registry, _ctx);
  kk_std_time__done(_ctx);
  kk_std_num_int64__done(_ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_os_process__done(_ctx);
  kk_std_os_readline__done(_ctx);
  kk_std_core__done(_ctx);
  kk_std_time_parse__done(_ctx);
  kk_std_time_format__done(_ctx);
  kk_std_time_locale__done(_ctx);
  kk_std_time_time__done(_ctx);
  kk_std_time_calendars__done(_ctx);
  kk_std_time_calendar__done(_ctx);
  kk_std_time_date__done(_ctx);
  kk_std_time_timer__done(_ctx);
  kk_std_time_chrono__done(_ctx);
  kk_std_time_utc__done(_ctx);
  kk_std_time_instant__done(_ctx);
  kk_std_time_duration__done(_ctx);
  kk_std_core_console__done(_ctx);
  kk_std_core_delayed__done(_ctx);
  kk_std_core_debug__done(_ctx);
  kk_std_core_show__done(_ctx);
  kk_std_core_lazy__done(_ctx);
  kk_std_core_tuple__done(_ctx);
  kk_std_core_either__done(_ctx);
  kk_std_core_maybe2__done(_ctx);
  kk_std_core_maybe__done(_ctx);
  kk_std_core_list__done(_ctx);
  kk_std_core_sslice__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_vector__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_order__done(_ctx);
  kk_std_core_bool__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
