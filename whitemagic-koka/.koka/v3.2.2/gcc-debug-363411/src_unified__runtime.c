// Koka generated module: src/unified_runtime, koka version: 3.2.2, platform: 64-bit
#include "src_unified__runtime.h"

kk_src_unified__runtime__runtime_state kk_src_unified__runtime_runtime_state_fs__copy(kk_src_unified__runtime__runtime_state _this, kk_std_core_types__optional event_count, kk_std_core_types__optional total_calls, kk_std_core_types__optional total_time_ms, kk_std_core_types__optional last_event, kk_std_core_types__optional hot_paths_count, kk_context_t* _ctx) { /* (runtime-state, event-count : ? int, total-calls : ? int, total-time-ms : ? float64, last-event : ? string, hot-paths-count : ? int) -> runtime-state */ 
  kk_integer_t _x_x300;
  if (kk_std_core_types__is_Optional(event_count, _ctx)) {
    kk_box_t _box_x0 = event_count._cons._Optional.value;
    kk_integer_t _uniq_event_count_186 = kk_integer_unbox(_box_x0, _ctx);
    kk_integer_dup(_uniq_event_count_186, _ctx);
    kk_std_core_types__optional_drop(event_count, _ctx);
    _x_x300 = _uniq_event_count_186; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(event_count, _ctx);
    {
      struct kk_src_unified__runtime_Runtime_state* _con_x301 = kk_src_unified__runtime__as_Runtime_state(_this, _ctx);
      kk_integer_t _x = _con_x301->event_count;
      kk_integer_dup(_x, _ctx);
      _x_x300 = _x; /*int*/
    }
  }
  kk_integer_t _x_x302;
  if (kk_std_core_types__is_Optional(total_calls, _ctx)) {
    kk_box_t _box_x1 = total_calls._cons._Optional.value;
    kk_integer_t _uniq_total_calls_194 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_total_calls_194, _ctx);
    kk_std_core_types__optional_drop(total_calls, _ctx);
    _x_x302 = _uniq_total_calls_194; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(total_calls, _ctx);
    {
      struct kk_src_unified__runtime_Runtime_state* _con_x303 = kk_src_unified__runtime__as_Runtime_state(_this, _ctx);
      kk_integer_t _x_0 = _con_x303->total_calls;
      kk_integer_dup(_x_0, _ctx);
      _x_x302 = _x_0; /*int*/
    }
  }
  double _x_x304;
  if (kk_std_core_types__is_Optional(total_time_ms, _ctx)) {
    kk_box_t _box_x2 = total_time_ms._cons._Optional.value;
    double _uniq_total_time_ms_202 = kk_double_unbox(_box_x2, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    _x_x304 = _uniq_total_time_ms_202; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    {
      struct kk_src_unified__runtime_Runtime_state* _con_x305 = kk_src_unified__runtime__as_Runtime_state(_this, _ctx);
      double _x_1 = _con_x305->total_time_ms;
      _x_x304 = _x_1; /*float64*/
    }
  }
  kk_string_t _x_x306;
  if (kk_std_core_types__is_Optional(last_event, _ctx)) {
    kk_box_t _box_x3 = last_event._cons._Optional.value;
    kk_string_t _uniq_last_event_210 = kk_string_unbox(_box_x3);
    kk_string_dup(_uniq_last_event_210, _ctx);
    kk_std_core_types__optional_drop(last_event, _ctx);
    _x_x306 = _uniq_last_event_210; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(last_event, _ctx);
    {
      struct kk_src_unified__runtime_Runtime_state* _con_x307 = kk_src_unified__runtime__as_Runtime_state(_this, _ctx);
      kk_string_t _x_2 = _con_x307->last_event;
      kk_string_dup(_x_2, _ctx);
      _x_x306 = _x_2; /*string*/
    }
  }
  kk_integer_t _x_x308;
  if (kk_std_core_types__is_Optional(hot_paths_count, _ctx)) {
    kk_box_t _box_x4 = hot_paths_count._cons._Optional.value;
    kk_integer_t _uniq_hot_paths_count_218 = kk_integer_unbox(_box_x4, _ctx);
    kk_integer_dup(_uniq_hot_paths_count_218, _ctx);
    kk_std_core_types__optional_drop(hot_paths_count, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(4)), _ctx);
    _x_x308 = _uniq_hot_paths_count_218; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hot_paths_count, _ctx);
    {
      struct kk_src_unified__runtime_Runtime_state* _con_x309 = kk_src_unified__runtime__as_Runtime_state(_this, _ctx);
      kk_integer_t _pat_0_4 = _con_x309->event_count;
      kk_integer_t _pat_1_5 = _con_x309->total_calls;
      kk_string_t _pat_3_4 = _con_x309->last_event;
      kk_integer_t _x_3 = _con_x309->hot_paths_count;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_3_4, _ctx);
        kk_integer_drop(_pat_1_5, _ctx);
        kk_integer_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_3, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x308 = _x_3; /*int*/
    }
  }
  return kk_src_unified__runtime__new_Runtime_state(kk_reuse_null, 0, _x_x300, _x_x302, _x_x304, _x_x306, _x_x308, _ctx);
}

kk_string_t kk_src_unified__runtime_event_type_to_string(kk_src_unified__runtime__event_type et, kk_context_t* _ctx) { /* (et : event-type) -> string */ 
  if (kk_src_unified__runtime__is_SystemStarted(et, _ctx)) {
    kk_define_string_literal(, _s_x310, 14, "system_started", _ctx)
    return kk_string_dup(_s_x310, _ctx);
  }
  if (kk_src_unified__runtime__is_SystemStopped(et, _ctx)) {
    kk_define_string_literal(, _s_x311, 14, "system_stopped", _ctx)
    return kk_string_dup(_s_x311, _ctx);
  }
  if (kk_src_unified__runtime__is_MemoryCreated(et, _ctx)) {
    kk_define_string_literal(, _s_x312, 14, "memory_created", _ctx)
    return kk_string_dup(_s_x312, _ctx);
  }
  if (kk_src_unified__runtime__is_MemoryUpdated(et, _ctx)) {
    kk_define_string_literal(, _s_x313, 14, "memory_updated", _ctx)
    return kk_string_dup(_s_x313, _ctx);
  }
  if (kk_src_unified__runtime__is_ThreatDetected(et, _ctx)) {
    kk_define_string_literal(, _s_x314, 15, "threat_detected", _ctx)
    return kk_string_dup(_s_x314, _ctx);
  }
  if (kk_src_unified__runtime__is_FlowStateEntered(et, _ctx)) {
    kk_define_string_literal(, _s_x315, 18, "flow_state_entered", _ctx)
    return kk_string_dup(_s_x315, _ctx);
  }
  {
    kk_define_string_literal(, _s_x316, 17, "flow_state_exited", _ctx)
    return kk_string_dup(_s_x316, _ctx);
  }
}

kk_src_unified__runtime__event_type kk_src_unified__runtime_string_to_event_type(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> event-type */ 
  if (kk_string_cmp_cstr_borrow(s, "system_started", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_src_unified__runtime__new_SystemStarted(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "system_stopped", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_src_unified__runtime__new_SystemStopped(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "memory_created", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_src_unified__runtime__new_MemoryCreated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "memory_updated", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_src_unified__runtime__new_MemoryUpdated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "threat_detected", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_src_unified__runtime__new_ThreatDetected(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "flow_state_entered", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_src_unified__runtime__new_FlowStateEntered(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "flow_state_exited", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_src_unified__runtime__new_FlowStateExited(_ctx);
  }
  {
    kk_string_drop(s, _ctx);
    return kk_src_unified__runtime__new_SystemStarted(_ctx);
  }
}

kk_src_unified__runtime__complexity kk_src_unified__runtime_estimate_complexity(double avg_time_ms, kk_integer_t call_count, kk_context_t* _ctx) { /* (avg-time-ms : float64, call-count : int) -> complexity */ 
  bool _match_x265 = kk_integer_gt_borrow(call_count,(kk_integer_from_small(100)),kk_context()); /*bool*/;
  if (_match_x265) {
    bool _match_x269 = (avg_time_ms > (0x1.4p3)); /*bool*/;
    if (_match_x269) {
      kk_integer_drop(call_count, _ctx);
      return kk_src_unified__runtime__new_High(_ctx);
    }
    {
      bool _match_x270;
      bool _brw_x272 = kk_integer_gt_borrow(call_count,(kk_integer_from_small(10)),kk_context()); /*bool*/;
      kk_integer_drop(call_count, _ctx);
      _match_x270 = _brw_x272; /*bool*/
      if (_match_x270) {
        return kk_src_unified__runtime__new_Medium(_ctx);
      }
      {
        bool _match_x271 = (avg_time_ms > (0x1.4p2)); /*bool*/;
        if (_match_x271) {
          return kk_src_unified__runtime__new_Medium(_ctx);
        }
        {
          return kk_src_unified__runtime__new_Low(_ctx);
        }
      }
    }
  }
  {
    bool _match_x266;
    bool _brw_x268 = kk_integer_gt_borrow(call_count,(kk_integer_from_small(10)),kk_context()); /*bool*/;
    kk_integer_drop(call_count, _ctx);
    _match_x266 = _brw_x268; /*bool*/
    if (_match_x266) {
      return kk_src_unified__runtime__new_Medium(_ctx);
    }
    {
      bool _match_x267 = (avg_time_ms > (0x1.4p2)); /*bool*/;
      if (_match_x267) {
        return kk_src_unified__runtime__new_Medium(_ctx);
      }
      {
        return kk_src_unified__runtime__new_Low(_ctx);
      }
    }
  }
}
 
// Emit event and profile it atomically

kk_src_unified__runtime__runtime_state kk_src_unified__runtime_emit_and_profile(kk_src_unified__runtime__event_type et, double time_ms, kk_src_unified__runtime__runtime_state state, kk_context_t* _ctx) { /* (et : event-type, time-ms : float64, state : runtime-state) -> runtime-state */ 
  kk_integer_t new_event_count;
  kk_integer_t _x_x320;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x321 = kk_src_unified__runtime__as_Runtime_state(state, _ctx);
    kk_integer_t _x = _con_x321->event_count;
    kk_integer_dup(_x, _ctx);
    _x_x320 = _x; /*int*/
  }
  new_event_count = kk_integer_add_small_const(_x_x320, 1, _ctx); /*int*/
  kk_integer_t new_total_calls;
  kk_integer_t _x_x322;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x323 = kk_src_unified__runtime__as_Runtime_state(state, _ctx);
    kk_integer_t _x_0 = _con_x323->total_calls;
    kk_integer_dup(_x_0, _ctx);
    _x_x322 = _x_0; /*int*/
  }
  new_total_calls = kk_integer_add_small_const(_x_x322, 1, _ctx); /*int*/
  double new_total_time;
  double _x_x324;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x325 = kk_src_unified__runtime__as_Runtime_state(state, _ctx);
    double _x_1 = _con_x325->total_time_ms;
    _x_x324 = _x_1; /*float64*/
  }
  new_total_time = (_x_x324 + time_ms); /*float64*/
  kk_string_t event_name = kk_src_unified__runtime_event_type_to_string(et, _ctx); /*string*/;
  kk_integer_t new_hot_count;
  bool _match_x264 = (time_ms > (0x1.4p3)); /*bool*/;
  if (_match_x264) {
    kk_integer_t _x_x326;
    {
      struct kk_src_unified__runtime_Runtime_state* _con_x327 = kk_src_unified__runtime__as_Runtime_state(state, _ctx);
      kk_integer_t _pat_0_2 = _con_x327->event_count;
      kk_integer_t _pat_1_2 = _con_x327->total_calls;
      kk_string_t _pat_3_2 = _con_x327->last_event;
      kk_integer_t _x_2 = _con_x327->hot_paths_count;
      if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
        kk_string_drop(_pat_3_2, _ctx);
        kk_integer_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(state, _ctx);
      }
      else {
        kk_integer_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(state, _ctx);
      }
      _x_x326 = _x_2; /*int*/
    }
    new_hot_count = kk_integer_add_small_const(_x_x326, 1, _ctx); /*int*/
  }
  else {
    struct kk_src_unified__runtime_Runtime_state* _con_x328 = kk_src_unified__runtime__as_Runtime_state(state, _ctx);
    kk_integer_t _pat_0_4 = _con_x328->event_count;
    kk_integer_t _pat_1_3 = _con_x328->total_calls;
    kk_string_t _pat_3_3 = _con_x328->last_event;
    kk_integer_t _x_3 = _con_x328->hot_paths_count;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_string_drop(_pat_3_3, _ctx);
      kk_integer_drop(_pat_1_3, _ctx);
      kk_integer_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_integer_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    new_hot_count = _x_3; /*int*/
  }
  return kk_src_unified__runtime__new_Runtime_state(kk_reuse_null, 0, new_event_count, new_total_calls, new_total_time, event_name, new_hot_count, _ctx);
}
 
// Check cascade and profile the check

kk_std_core_types__tuple2 kk_src_unified__runtime_check_cascade_profiled(kk_src_unified__runtime__event_type et, kk_src_unified__runtime__runtime_state state, kk_context_t* _ctx) { /* (et : event-type, state : runtime-state) -> (int, runtime-state) */ 
  kk_src_unified__runtime__runtime_state new_state;
  kk_integer_t _x_x329;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x330 = kk_src_unified__runtime__as_Runtime_state(state, _ctx);
    kk_integer_t _x = _con_x330->event_count;
    kk_integer_dup(_x, _ctx);
    _x_x329 = _x; /*int*/
  }
  kk_integer_t _x_x331;
  kk_integer_t _x_x332;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x333 = kk_src_unified__runtime__as_Runtime_state(state, _ctx);
    kk_integer_t _x_0 = _con_x333->total_calls;
    kk_integer_dup(_x_0, _ctx);
    _x_x332 = _x_0; /*int*/
  }
  _x_x331 = kk_integer_add_small_const(_x_x332, 1, _ctx); /*int*/
  double _x_x334;
  double _x_x335;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x336 = kk_src_unified__runtime__as_Runtime_state(state, _ctx);
    double _x_1 = _con_x336->total_time_ms;
    _x_x335 = _x_1; /*float64*/
  }
  _x_x334 = (_x_x335 + (0x1p-1)); /*float64*/
  kk_string_t _x_x337;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x338 = kk_src_unified__runtime__as_Runtime_state(state, _ctx);
    kk_string_t _x_2 = _con_x338->last_event;
    kk_string_dup(_x_2, _ctx);
    _x_x337 = _x_2; /*string*/
  }
  kk_integer_t _x_x339;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x340 = kk_src_unified__runtime__as_Runtime_state(state, _ctx);
    kk_integer_t _pat_0_3 = _con_x340->event_count;
    kk_integer_t _pat_1_3 = _con_x340->total_calls;
    kk_string_t _pat_3_3 = _con_x340->last_event;
    kk_integer_t _x_3 = _con_x340->hot_paths_count;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_string_drop(_pat_3_3, _ctx);
      kk_integer_drop(_pat_1_3, _ctx);
      kk_integer_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_integer_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x339 = _x_3; /*int*/
  }
  new_state = kk_src_unified__runtime__new_Runtime_state(kk_reuse_null, 0, _x_x329, _x_x331, _x_x334, _x_x337, _x_x339, _ctx); /*src/unified_runtime/runtime-state*/
  kk_box_t _x_x341;
  kk_integer_t _x_x342;
  if (kk_src_unified__runtime__is_MemoryCreated(et, _ctx)) {
    _x_x342 = kk_integer_from_small(3); /*int*/
    goto _match_x343;
  }
  if (kk_src_unified__runtime__is_MemoryUpdated(et, _ctx)) {
    _x_x342 = kk_integer_from_small(2); /*int*/
    goto _match_x343;
  }
  if (kk_src_unified__runtime__is_ThreatDetected(et, _ctx)) {
    _x_x342 = kk_integer_from_small(5); /*int*/
    goto _match_x343;
  }
  {
    _x_x342 = kk_integer_from_small(1); /*int*/
  }
  _match_x343: ;
  _x_x341 = kk_integer_box(_x_x342, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x341, kk_src_unified__runtime__runtime_state_box(new_state, _ctx), _ctx);
}

kk_string_t kk_src_unified__runtime_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x258;
  kk_string_t _x_x344 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x345;
  kk_define_string_literal(, _s_x346, 6, "\"emit\"", _ctx)
  _x_x345 = kk_string_dup(_s_x346, _ctx); /*string*/
  _match_x258 = kk_string_contains(_x_x344,_x_x345,kk_context()); /*bool*/
  if (_match_x258) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x347, 4, "emit", _ctx)
    return kk_string_dup(_s_x347, _ctx);
  }
  {
    bool _match_x259;
    kk_string_t _x_x348 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x349;
    kk_define_string_literal(, _s_x350, 9, "\"cascade\"", _ctx)
    _x_x349 = kk_string_dup(_s_x350, _ctx); /*string*/
    _match_x259 = kk_string_contains(_x_x348,_x_x349,kk_context()); /*bool*/
    if (_match_x259) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x351, 7, "cascade", _ctx)
      return kk_string_dup(_s_x351, _ctx);
    }
    {
      bool _match_x260;
      kk_string_t _x_x352 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x353;
      kk_define_string_literal(, _s_x354, 9, "\"profile\"", _ctx)
      _x_x353 = kk_string_dup(_s_x354, _ctx); /*string*/
      _match_x260 = kk_string_contains(_x_x352,_x_x353,kk_context()); /*bool*/
      if (_match_x260) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x355, 7, "profile", _ctx)
        return kk_string_dup(_s_x355, _ctx);
      }
      {
        bool _match_x261;
        kk_string_t _x_x356 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x357;
        kk_define_string_literal(, _s_x358, 8, "\"status\"", _ctx)
        _x_x357 = kk_string_dup(_s_x358, _ctx); /*string*/
        _match_x261 = kk_string_contains(_x_x356,_x_x357,kk_context()); /*bool*/
        if (_match_x261) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x359, 6, "status", _ctx)
          return kk_string_dup(_s_x359, _ctx);
        }
        {
          bool _match_x262;
          kk_string_t _x_x360 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x361;
          kk_define_string_literal(, _s_x362, 5, "\"hot\"", _ctx)
          _x_x361 = kk_string_dup(_s_x362, _ctx); /*string*/
          _match_x262 = kk_string_contains(_x_x360,_x_x361,kk_context()); /*bool*/
          if (_match_x262) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x363, 3, "hot", _ctx)
            return kk_string_dup(_s_x363, _ctx);
          }
          {
            bool _match_x263;
            kk_string_t _x_x364;
            kk_define_string_literal(, _s_x365, 6, "\"quit\"", _ctx)
            _x_x364 = kk_string_dup(_s_x365, _ctx); /*string*/
            _match_x263 = kk_string_contains(line,_x_x364,kk_context()); /*bool*/
            if (_match_x263) {
              kk_define_string_literal(, _s_x366, 4, "quit", _ctx)
              return kk_string_dup(_s_x366, _ctx);
            }
            {
              kk_define_string_literal(, _s_x367, 7, "unknown", _ctx)
              return kk_string_dup(_s_x367, _ctx);
            }
          }
        }
      }
    }
  }
}

kk_src_unified__runtime__event_type kk_src_unified__runtime_extract_event_type(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> event-type */ 
  bool _match_x254;
  kk_string_t _x_x368 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x369;
  kk_define_string_literal(, _s_x370, 14, "memory_created", _ctx)
  _x_x369 = kk_string_dup(_s_x370, _ctx); /*string*/
  _match_x254 = kk_string_contains(_x_x368,_x_x369,kk_context()); /*bool*/
  if (_match_x254) {
    kk_string_drop(line, _ctx);
    return kk_src_unified__runtime__new_MemoryCreated(_ctx);
  }
  {
    bool _match_x255;
    kk_string_t _x_x371 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x372;
    kk_define_string_literal(, _s_x373, 14, "memory_updated", _ctx)
    _x_x372 = kk_string_dup(_s_x373, _ctx); /*string*/
    _match_x255 = kk_string_contains(_x_x371,_x_x372,kk_context()); /*bool*/
    if (_match_x255) {
      kk_string_drop(line, _ctx);
      return kk_src_unified__runtime__new_MemoryUpdated(_ctx);
    }
    {
      bool _match_x256;
      kk_string_t _x_x374 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x375;
      kk_define_string_literal(, _s_x376, 15, "threat_detected", _ctx)
      _x_x375 = kk_string_dup(_s_x376, _ctx); /*string*/
      _match_x256 = kk_string_contains(_x_x374,_x_x375,kk_context()); /*bool*/
      if (_match_x256) {
        kk_string_drop(line, _ctx);
        return kk_src_unified__runtime__new_ThreatDetected(_ctx);
      }
      {
        bool _match_x257;
        kk_string_t _x_x377;
        kk_define_string_literal(, _s_x378, 10, "flow_state", _ctx)
        _x_x377 = kk_string_dup(_s_x378, _ctx); /*string*/
        _match_x257 = kk_string_contains(line,_x_x377,kk_context()); /*bool*/
        if (_match_x257) {
          return kk_src_unified__runtime__new_FlowStateEntered(_ctx);
        }
        {
          return kk_src_unified__runtime__new_SystemStarted(_ctx);
        }
      }
    }
  }
}

kk_string_t kk_src_unified__runtime_json_state(kk_src_unified__runtime__runtime_state s, kk_context_t* _ctx) { /* (s : runtime-state) -> string */ 
  kk_string_t _x_x379;
  kk_define_string_literal(, _s_x380, 10, "{\"events\":", _ctx)
  _x_x379 = kk_string_dup(_s_x380, _ctx); /*string*/
  kk_string_t _x_x381;
  kk_string_t _x_x382;
  kk_integer_t _x_x383;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x384 = kk_src_unified__runtime__as_Runtime_state(s, _ctx);
    kk_integer_t _x = _con_x384->event_count;
    kk_integer_dup(_x, _ctx);
    _x_x383 = _x; /*int*/
  }
  _x_x382 = kk_std_core_int_show(_x_x383, _ctx); /*string*/
  kk_string_t _x_x385;
  kk_string_t _x_x386;
  kk_define_string_literal(, _s_x387, 15, ",\"total_calls\":", _ctx)
  _x_x386 = kk_string_dup(_s_x387, _ctx); /*string*/
  kk_string_t _x_x388;
  kk_string_t _x_x389;
  kk_integer_t _x_x390;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x391 = kk_src_unified__runtime__as_Runtime_state(s, _ctx);
    kk_integer_t _x_0 = _con_x391->total_calls;
    kk_integer_dup(_x_0, _ctx);
    _x_x390 = _x_0; /*int*/
  }
  _x_x389 = kk_std_core_int_show(_x_x390, _ctx); /*string*/
  kk_string_t _x_x392;
  kk_string_t _x_x393;
  kk_define_string_literal(, _s_x394, 17, ",\"total_time_ms\":", _ctx)
  _x_x393 = kk_string_dup(_s_x394, _ctx); /*string*/
  kk_string_t _x_x395;
  kk_string_t _x_x396;
  double _x_x397;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x398 = kk_src_unified__runtime__as_Runtime_state(s, _ctx);
    double _x_1 = _con_x398->total_time_ms;
    _x_x397 = _x_1; /*float64*/
  }
  _x_x396 = kk_std_num_float64_show(_x_x397, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x399;
  kk_string_t _x_x400;
  kk_define_string_literal(, _s_x401, 15, ",\"last_event\":\"", _ctx)
  _x_x400 = kk_string_dup(_s_x401, _ctx); /*string*/
  kk_string_t _x_x402;
  kk_string_t _x_x403;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x404 = kk_src_unified__runtime__as_Runtime_state(s, _ctx);
    kk_string_t _x_2 = _con_x404->last_event;
    kk_string_dup(_x_2, _ctx);
    _x_x403 = _x_2; /*string*/
  }
  kk_string_t _x_x405;
  kk_string_t _x_x406;
  kk_define_string_literal(, _s_x407, 1, "\"", _ctx)
  _x_x406 = kk_string_dup(_s_x407, _ctx); /*string*/
  kk_string_t _x_x408;
  kk_string_t _x_x409;
  kk_define_string_literal(, _s_x410, 13, ",\"hot_paths\":", _ctx)
  _x_x409 = kk_string_dup(_s_x410, _ctx); /*string*/
  kk_string_t _x_x411;
  kk_string_t _x_x412;
  kk_integer_t _x_x413;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x414 = kk_src_unified__runtime__as_Runtime_state(s, _ctx);
    kk_integer_t _pat_0_3 = _con_x414->event_count;
    kk_integer_t _pat_1_3 = _con_x414->total_calls;
    kk_string_t _pat_3_3 = _con_x414->last_event;
    kk_integer_t _x_3 = _con_x414->hot_paths_count;
    if kk_likely(kk_datatype_ptr_is_unique(s, _ctx)) {
      kk_string_drop(_pat_3_3, _ctx);
      kk_integer_drop(_pat_1_3, _ctx);
      kk_integer_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(s, _ctx);
    }
    else {
      kk_integer_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(s, _ctx);
    }
    _x_x413 = _x_3; /*int*/
  }
  _x_x412 = kk_std_core_int_show(_x_x413, _ctx); /*string*/
  kk_string_t _x_x415;
  kk_define_string_literal(, _s_x416, 1, "}", _ctx)
  _x_x415 = kk_string_dup(_s_x416, _ctx); /*string*/
  _x_x411 = kk_std_core_types__lp__plus__plus__rp_(_x_x412, _x_x415, _ctx); /*string*/
  _x_x408 = kk_std_core_types__lp__plus__plus__rp_(_x_x409, _x_x411, _ctx); /*string*/
  _x_x405 = kk_std_core_types__lp__plus__plus__rp_(_x_x406, _x_x408, _ctx); /*string*/
  _x_x402 = kk_std_core_types__lp__plus__plus__rp_(_x_x403, _x_x405, _ctx); /*string*/
  _x_x399 = kk_std_core_types__lp__plus__plus__rp_(_x_x400, _x_x402, _ctx); /*string*/
  _x_x395 = kk_std_core_types__lp__plus__plus__rp_(_x_x396, _x_x399, _ctx); /*string*/
  _x_x392 = kk_std_core_types__lp__plus__plus__rp_(_x_x393, _x_x395, _ctx); /*string*/
  _x_x388 = kk_std_core_types__lp__plus__plus__rp_(_x_x389, _x_x392, _ctx); /*string*/
  _x_x385 = kk_std_core_types__lp__plus__plus__rp_(_x_x386, _x_x388, _ctx); /*string*/
  _x_x381 = kk_std_core_types__lp__plus__plus__rp_(_x_x382, _x_x385, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x379, _x_x381, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10072_fun422__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10072_fun422(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10072_fun422(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10072_fun422, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10072_fun422(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__event_type _x_x423;
  kk_string_t _x_x424 = kk_string_unbox(_b_x11); /*string*/
  _x_x423 = kk_src_unified__runtime_extract_event_type(_x_x424, _ctx); /*src/unified_runtime/event-type*/
  return kk_src_unified__runtime__event_type_box(_x_x423, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10072_fun426__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10072_fun426(kk_function_t _fself, kk_box_t _b_x18, kk_box_t _b_x19, kk_box_t _b_x20, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10072_fun426(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10072_fun426, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10072_fun426(kk_function_t _fself, kk_box_t _b_x18, kk_box_t _b_x19, kk_box_t _b_x20, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__runtime_state state_1_42 = kk_src_unified__runtime__runtime_state_unbox(_b_x20, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/;
  kk_integer_t new_event_count_0;
  kk_integer_t _x_x427;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x428 = kk_src_unified__runtime__as_Runtime_state(state_1_42, _ctx);
    kk_integer_t _x_5 = _con_x428->event_count;
    kk_integer_dup(_x_5, _ctx);
    _x_x427 = _x_5; /*int*/
  }
  new_event_count_0 = kk_integer_add_small_const(_x_x427, 1, _ctx); /*int*/
  kk_integer_t new_total_calls_0;
  kk_integer_t _x_x429;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x430 = kk_src_unified__runtime__as_Runtime_state(state_1_42, _ctx);
    kk_integer_t _x_0_1 = _con_x430->total_calls;
    kk_integer_dup(_x_0_1, _ctx);
    _x_x429 = _x_0_1; /*int*/
  }
  new_total_calls_0 = kk_integer_add_small_const(_x_x429, 1, _ctx); /*int*/
  double new_total_time_0;
  double _x_x431;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x432 = kk_src_unified__runtime__as_Runtime_state(state_1_42, _ctx);
    double _x_1_0 = _con_x432->total_time_ms;
    _x_x431 = _x_1_0; /*float64*/
  }
  double _x_x433;
  kk_box_t _x_x434 = kk_box_dup(_b_x19, _ctx); /*10001*/
  _x_x433 = kk_double_unbox(_x_x434, KK_OWNED, _ctx); /*float64*/
  new_total_time_0 = (_x_x431 + _x_x433); /*float64*/
  kk_string_t event_name_0;
  kk_src_unified__runtime__event_type _x_x435 = kk_src_unified__runtime__event_type_unbox(_b_x18, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  event_name_0 = kk_src_unified__runtime_event_type_to_string(_x_x435, _ctx); /*string*/
  kk_integer_t new_hot_count_0;
  bool _match_x253;
  double _x_x436 = kk_double_unbox(_b_x19, KK_OWNED, _ctx); /*float64*/
  _match_x253 = (_x_x436 > (0x1.4p3)); /*bool*/
  if (_match_x253) {
    kk_integer_t _x_x437;
    {
      struct kk_src_unified__runtime_Runtime_state* _con_x438 = kk_src_unified__runtime__as_Runtime_state(state_1_42, _ctx);
      kk_integer_t _pat_0_2_0 = _con_x438->event_count;
      kk_integer_t _pat_1_2_0 = _con_x438->total_calls;
      kk_string_t _pat_3_2_0 = _con_x438->last_event;
      kk_integer_t _x_2_0 = _con_x438->hot_paths_count;
      if kk_likely(kk_datatype_ptr_is_unique(state_1_42, _ctx)) {
        kk_string_drop(_pat_3_2_0, _ctx);
        kk_integer_drop(_pat_1_2_0, _ctx);
        kk_integer_drop(_pat_0_2_0, _ctx);
        kk_datatype_ptr_free(state_1_42, _ctx);
      }
      else {
        kk_integer_dup(_x_2_0, _ctx);
        kk_datatype_ptr_decref(state_1_42, _ctx);
      }
      _x_x437 = _x_2_0; /*int*/
    }
    new_hot_count_0 = kk_integer_add_small_const(_x_x437, 1, _ctx); /*int*/
  }
  else {
    struct kk_src_unified__runtime_Runtime_state* _con_x439 = kk_src_unified__runtime__as_Runtime_state(state_1_42, _ctx);
    kk_integer_t _pat_0_4_0 = _con_x439->event_count;
    kk_integer_t _pat_1_3_0 = _con_x439->total_calls;
    kk_string_t _pat_3_3_0 = _con_x439->last_event;
    kk_integer_t _x_3_0 = _con_x439->hot_paths_count;
    if kk_likely(kk_datatype_ptr_is_unique(state_1_42, _ctx)) {
      kk_string_drop(_pat_3_3_0, _ctx);
      kk_integer_drop(_pat_1_3_0, _ctx);
      kk_integer_drop(_pat_0_4_0, _ctx);
      kk_datatype_ptr_free(state_1_42, _ctx);
    }
    else {
      kk_integer_dup(_x_3_0, _ctx);
      kk_datatype_ptr_decref(state_1_42, _ctx);
    }
    new_hot_count_0 = _x_3_0; /*int*/
  }
  kk_src_unified__runtime__runtime_state _x_x440 = kk_src_unified__runtime__new_Runtime_state(kk_reuse_null, 0, new_event_count_0, new_total_calls_0, new_total_time_0, event_name_0, new_hot_count_0, _ctx); /*src/unified_runtime/runtime-state*/
  return kk_src_unified__runtime__runtime_state_box(_x_x440, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10072_fun442__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10072_fun442(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10072_fun442(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10072_fun442, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10072_fun442(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__event_type _x_x443;
  kk_string_t _x_x444 = kk_string_unbox(_b_x23); /*string*/
  _x_x443 = kk_src_unified__runtime_extract_event_type(_x_x444, _ctx); /*src/unified_runtime/event-type*/
  return kk_src_unified__runtime__event_type_box(_x_x443, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10072_fun446__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10072_fun446(kk_function_t _fself, kk_box_t _b_x29, kk_box_t _b_x30, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10072_fun446(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10072_fun446, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10072_fun446(kk_function_t _fself, kk_box_t _b_x29, kk_box_t _b_x30, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x447;
  kk_src_unified__runtime__event_type _x_x448 = kk_src_unified__runtime__event_type_unbox(_b_x29, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  kk_src_unified__runtime__runtime_state _x_x449 = kk_src_unified__runtime__runtime_state_unbox(_b_x30, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
  _x_x447 = kk_src_unified__runtime_check_cascade_profiled(_x_x448, _x_x449, _ctx); /*(int, src/unified_runtime/runtime-state)*/
  return kk_std_core_types__tuple2_box(_x_x447, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10072_fun452__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10072_fun452(kk_function_t _fself, kk_box_t _b_x44, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10072_fun452(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10072_fun452, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10072_fun452(kk_function_t _fself, kk_box_t _b_x44, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x453 = kk_Unit;
  kk_src_unified__runtime__runtime_state _x_x454 = kk_src_unified__runtime__runtime_state_unbox(_b_x44, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
  kk_src_unified__runtime_server_loop(_x_x454, _ctx);
  return kk_unit_box(_x_x453);
}

kk_unit_t kk_src_unified__runtime__mlift_server_loop_10072(kk_string_t line, kk_string_t op, kk_src_unified__runtime__runtime_state state, kk_string_t _c_x10030, kk_context_t* _ctx) { /* (line : string, op : string, state : runtime-state, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10030, _ctx);
  bool _match_x250;
  kk_string_t _x_x417 = kk_string_dup(op, _ctx); /*string*/
  kk_string_t _x_x418;
  kk_define_string_literal(, _s_x419, 4, "quit", _ctx)
  _x_x418 = kk_string_dup(_s_x419, _ctx); /*string*/
  _match_x250 = kk_string_is_neq(_x_x417,_x_x418,kk_context()); /*bool*/
  if (_match_x250) {
    kk_src_unified__runtime__runtime_state x_10074;
    if (kk_string_cmp_cstr_borrow(op, "emit", _ctx) == 0) {
      kk_string_drop(op, _ctx);
      kk_src_unified__runtime__event_type et_1;
      kk_box_t _x_x421 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__new_mlift_server_loop_10072_fun422(_ctx), kk_string_box(line), _ctx); /*10001*/
      et_1 = kk_src_unified__runtime__event_type_unbox(_x_x421, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
      kk_box_t _x_x425 = kk_std_core_hnd__open_none3(kk_src_unified__runtime__new_mlift_server_loop_10072_fun426(_ctx), kk_src_unified__runtime__event_type_box(et_1, _ctx), kk_double_box(0x1.8p0, _ctx), kk_src_unified__runtime__runtime_state_box(state, _ctx), _ctx); /*10003*/
      x_10074 = kk_src_unified__runtime__runtime_state_unbox(_x_x425, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
      goto _match_x420;
    }
    if (kk_string_cmp_cstr_borrow(op, "cascade", _ctx) == 0) {
      kk_string_drop(op, _ctx);
      kk_src_unified__runtime__event_type et_2_0;
      kk_box_t _x_x441 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__new_mlift_server_loop_10072_fun442(_ctx), kk_string_box(line), _ctx); /*10001*/
      et_2_0 = kk_src_unified__runtime__event_type_unbox(_x_x441, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
      kk_std_core_types__tuple2 _match_x252;
      kk_box_t _x_x445 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__new_mlift_server_loop_10072_fun446(_ctx), kk_src_unified__runtime__event_type_box(et_2_0, _ctx), kk_src_unified__runtime__runtime_state_box(state, _ctx), _ctx); /*10002*/
      _match_x252 = kk_std_core_types__tuple2_unbox(_x_x445, KK_OWNED, _ctx); /*(int, src/unified_runtime/runtime-state)*/
      {
        kk_box_t _box_x31 = _match_x252.fst;
        kk_box_t _box_x32 = _match_x252.snd;
        kk_src_unified__runtime__runtime_state ns = kk_src_unified__runtime__runtime_state_unbox(_box_x32, KK_BORROWED, _ctx);
        struct kk_src_unified__runtime_Runtime_state* _con_x450 = kk_src_unified__runtime__as_Runtime_state(ns, _ctx);
        kk_src_unified__runtime__runtime_state_dup(ns, _ctx);
        kk_std_core_types__tuple2_drop(_match_x252, _ctx);
        x_10074 = ns; /*src/unified_runtime/runtime-state*/
        goto _match_x420;
      }
    }
    {
      kk_string_drop(op, _ctx);
      kk_string_drop(line, _ctx);
      x_10074 = state; /*src/unified_runtime/runtime-state*/
    }
    _match_x420: ;
    if (kk_yielding(kk_context())) {
      kk_datatype_ptr_dropn(x_10074, (KK_I32(4)), _ctx);
      kk_box_t _x_x451 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__new_mlift_server_loop_10072_fun452(_ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x451); return kk_Unit;
    }
    {
      kk_src_unified__runtime_server_loop(x_10074, _ctx); return kk_Unit;
    }
  }
  {
    kk_datatype_ptr_dropn(state, (KK_I32(4)), _ctx);
    kk_string_drop(op, _ctx);
    kk_string_drop(line, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun459__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun459(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun459(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10073_fun459, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun459(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x460;
  kk_string_t _x_x461 = kk_string_unbox(_b_x48); /*string*/
  _x_x460 = kk_src_unified__runtime_extract_op(_x_x461, _ctx); /*string*/
  return kk_string_box(_x_x460);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun466__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun466(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun466(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10073_fun466, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun466(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__event_type _x_x467;
  kk_string_t _x_x468 = kk_string_unbox(_b_x53); /*string*/
  _x_x467 = kk_src_unified__runtime_extract_event_type(_x_x468, _ctx); /*src/unified_runtime/event-type*/
  return kk_src_unified__runtime__event_type_box(_x_x467, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun472__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun472(kk_function_t _fself, kk_box_t _b_x60, kk_box_t _b_x61, kk_box_t _b_x62, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun472(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10073_fun472, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun472(kk_function_t _fself, kk_box_t _b_x60, kk_box_t _b_x61, kk_box_t _b_x62, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__runtime_state state_0_0_69 = kk_src_unified__runtime__runtime_state_unbox(_b_x62, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/;
  kk_integer_t new_event_count;
  kk_integer_t _x_x473;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x474 = kk_src_unified__runtime__as_Runtime_state(state_0_0_69, _ctx);
    kk_integer_t _x = _con_x474->event_count;
    kk_integer_dup(_x, _ctx);
    _x_x473 = _x; /*int*/
  }
  new_event_count = kk_integer_add_small_const(_x_x473, 1, _ctx); /*int*/
  kk_integer_t new_total_calls;
  kk_integer_t _x_x475;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x476 = kk_src_unified__runtime__as_Runtime_state(state_0_0_69, _ctx);
    kk_integer_t _x_0 = _con_x476->total_calls;
    kk_integer_dup(_x_0, _ctx);
    _x_x475 = _x_0; /*int*/
  }
  new_total_calls = kk_integer_add_small_const(_x_x475, 1, _ctx); /*int*/
  double new_total_time;
  double _x_x477;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x478 = kk_src_unified__runtime__as_Runtime_state(state_0_0_69, _ctx);
    double _x_1 = _con_x478->total_time_ms;
    _x_x477 = _x_1; /*float64*/
  }
  double _x_x479;
  kk_box_t _x_x480 = kk_box_dup(_b_x61, _ctx); /*10001*/
  _x_x479 = kk_double_unbox(_x_x480, KK_OWNED, _ctx); /*float64*/
  new_total_time = (_x_x477 + _x_x479); /*float64*/
  kk_string_t event_name;
  kk_src_unified__runtime__event_type _x_x481 = kk_src_unified__runtime__event_type_unbox(_b_x60, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  event_name = kk_src_unified__runtime_event_type_to_string(_x_x481, _ctx); /*string*/
  kk_integer_t new_hot_count;
  bool _match_x249;
  double _x_x482 = kk_double_unbox(_b_x61, KK_OWNED, _ctx); /*float64*/
  _match_x249 = (_x_x482 > (0x1.4p3)); /*bool*/
  if (_match_x249) {
    kk_integer_t _x_x483;
    {
      struct kk_src_unified__runtime_Runtime_state* _con_x484 = kk_src_unified__runtime__as_Runtime_state(state_0_0_69, _ctx);
      kk_integer_t _pat_0_2 = _con_x484->event_count;
      kk_integer_t _pat_1_2 = _con_x484->total_calls;
      kk_string_t _pat_3_2 = _con_x484->last_event;
      kk_integer_t _x_2 = _con_x484->hot_paths_count;
      if kk_likely(kk_datatype_ptr_is_unique(state_0_0_69, _ctx)) {
        kk_string_drop(_pat_3_2, _ctx);
        kk_integer_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(state_0_0_69, _ctx);
      }
      else {
        kk_integer_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(state_0_0_69, _ctx);
      }
      _x_x483 = _x_2; /*int*/
    }
    new_hot_count = kk_integer_add_small_const(_x_x483, 1, _ctx); /*int*/
  }
  else {
    struct kk_src_unified__runtime_Runtime_state* _con_x485 = kk_src_unified__runtime__as_Runtime_state(state_0_0_69, _ctx);
    kk_integer_t _pat_0_4 = _con_x485->event_count;
    kk_integer_t _pat_1_3 = _con_x485->total_calls;
    kk_string_t _pat_3_3 = _con_x485->last_event;
    kk_integer_t _x_3 = _con_x485->hot_paths_count;
    if kk_likely(kk_datatype_ptr_is_unique(state_0_0_69, _ctx)) {
      kk_string_drop(_pat_3_3, _ctx);
      kk_integer_drop(_pat_1_3, _ctx);
      kk_integer_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(state_0_0_69, _ctx);
    }
    else {
      kk_integer_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(state_0_0_69, _ctx);
    }
    new_hot_count = _x_3; /*int*/
  }
  kk_src_unified__runtime__runtime_state _x_x486 = kk_src_unified__runtime__new_Runtime_state(kk_reuse_null, 0, new_event_count, new_total_calls, new_total_time, event_name, new_hot_count, _ctx); /*src/unified_runtime/runtime-state*/
  return kk_src_unified__runtime__runtime_state_box(_x_x486, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun494__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun494(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun494(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10073_fun494, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun494(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x495;
  kk_src_unified__runtime__event_type _x_x496 = kk_src_unified__runtime__event_type_unbox(_b_x72, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  _x_x495 = kk_src_unified__runtime_event_type_to_string(_x_x496, _ctx); /*string*/
  return kk_string_box(_x_x495);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun503__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun503(kk_function_t _fself, kk_box_t _b_x75, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun503(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10073_fun503, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun503(kk_function_t _fself, kk_box_t _b_x75, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x504;
  kk_src_unified__runtime__runtime_state _x_x505 = kk_src_unified__runtime__runtime_state_unbox(_b_x75, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
  _x_x504 = kk_src_unified__runtime_json_state(_x_x505, _ctx); /*string*/
  return kk_string_box(_x_x504);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun509__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun509(kk_function_t _fself, kk_box_t _b_x78, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun509(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10073_fun509, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun509(kk_function_t _fself, kk_box_t _b_x78, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__event_type _x_x510;
  kk_string_t _x_x511 = kk_string_unbox(_b_x78); /*string*/
  _x_x510 = kk_src_unified__runtime_extract_event_type(_x_x511, _ctx); /*src/unified_runtime/event-type*/
  return kk_src_unified__runtime__event_type_box(_x_x510, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun515__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun515(kk_function_t _fself, kk_box_t _b_x84, kk_box_t _b_x85, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun515(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10073_fun515, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun515(kk_function_t _fself, kk_box_t _b_x84, kk_box_t _b_x85, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x516;
  kk_src_unified__runtime__event_type _x_x517 = kk_src_unified__runtime__event_type_unbox(_b_x84, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  kk_src_unified__runtime__runtime_state _x_x518 = kk_src_unified__runtime__runtime_state_unbox(_b_x85, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
  _x_x516 = kk_src_unified__runtime_check_cascade_profiled(_x_x517, _x_x518, _ctx); /*(int, src/unified_runtime/runtime-state)*/
  return kk_std_core_types__tuple2_box(_x_x516, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun527__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun527(kk_function_t _fself, kk_box_t _b_x90, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun527(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10073_fun527, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun527(kk_function_t _fself, kk_box_t _b_x90, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x528;
  kk_src_unified__runtime__event_type _x_x529 = kk_src_unified__runtime__event_type_unbox(_b_x90, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  _x_x528 = kk_src_unified__runtime_event_type_to_string(_x_x529, _ctx); /*string*/
  return kk_string_box(_x_x528);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun543__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun543(kk_function_t _fself, kk_box_t _b_x93, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun543(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10073_fun543, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun543(kk_function_t _fself, kk_box_t _b_x93, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__runtime_state _this_118 = kk_src_unified__runtime__runtime_state_unbox(_b_x93, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/;
  kk_integer_t _x_x544;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x545 = kk_src_unified__runtime__as_Runtime_state(_this_118, _ctx);
    kk_integer_t _pat_0_0_1 = _con_x545->event_count;
    kk_integer_t _x_4 = _con_x545->total_calls;
    kk_string_t _pat_2_0_0_0 = _con_x545->last_event;
    kk_integer_t _pat_3_0_0 = _con_x545->hot_paths_count;
    if kk_likely(kk_datatype_ptr_is_unique(_this_118, _ctx)) {
      kk_integer_drop(_pat_3_0_0, _ctx);
      kk_string_drop(_pat_2_0_0_0, _ctx);
      kk_integer_drop(_pat_0_0_1, _ctx);
      kk_datatype_ptr_free(_this_118, _ctx);
    }
    else {
      kk_integer_dup(_x_4, _ctx);
      kk_datatype_ptr_decref(_this_118, _ctx);
    }
    _x_x544 = _x_4; /*int*/
  }
  return kk_integer_box(_x_x544, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun551__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun551(kk_function_t _fself, kk_box_t _b_x96, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun551(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10073_fun551, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun551(kk_function_t _fself, kk_box_t _b_x96, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x552;
  kk_src_unified__runtime__runtime_state _x_x553 = kk_src_unified__runtime__runtime_state_unbox(_b_x96, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
  _x_x552 = kk_src_unified__runtime_json_state(_x_x553, _ctx); /*string*/
  return kk_string_box(_x_x552);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun562__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun562(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun562(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__mlift_server_loop_10073_fun562, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun562(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__runtime_state _this_0_119 = kk_src_unified__runtime__runtime_state_unbox(_b_x99, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/;
  kk_integer_t _x_x563;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x564 = kk_src_unified__runtime__as_Runtime_state(_this_0_119, _ctx);
    kk_integer_t _pat_0_1_0_0 = _con_x564->event_count;
    kk_integer_t _pat_1_1_0 = _con_x564->total_calls;
    kk_string_t _pat_3_1_0 = _con_x564->last_event;
    kk_integer_t _x_0_0 = _con_x564->hot_paths_count;
    if kk_likely(kk_datatype_ptr_is_unique(_this_0_119, _ctx)) {
      kk_string_drop(_pat_3_1_0, _ctx);
      kk_integer_drop(_pat_1_1_0, _ctx);
      kk_integer_drop(_pat_0_1_0_0, _ctx);
      kk_datatype_ptr_free(_this_0_119, _ctx);
    }
    else {
      kk_integer_dup(_x_0_0, _ctx);
      kk_datatype_ptr_decref(_this_0_119, _ctx);
    }
    _x_x563 = _x_0_0; /*int*/
  }
  return kk_integer_box(_x_x563, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__mlift_server_loop_10073_fun572__t {
  struct kk_function_s _base;
  kk_string_t line_0;
  kk_string_t op_0;
  kk_src_unified__runtime__runtime_state state_0;
};
static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun572(kk_function_t _fself, kk_box_t _b_x116, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__new_mlift_server_loop_10073_fun572(kk_string_t line_0, kk_string_t op_0, kk_src_unified__runtime__runtime_state state_0, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__mlift_server_loop_10073_fun572__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__mlift_server_loop_10073_fun572__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__mlift_server_loop_10073_fun572, kk_context());
  _self->line_0 = line_0;
  _self->op_0 = op_0;
  _self->state_0 = state_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__mlift_server_loop_10073_fun572(kk_function_t _fself, kk_box_t _b_x116, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__mlift_server_loop_10073_fun572__t* _self = kk_function_as(struct kk_src_unified__runtime__mlift_server_loop_10073_fun572__t*, _fself, _ctx);
  kk_string_t line_0 = _self->line_0; /* string */
  kk_string_t op_0 = _self->op_0; /* string */
  kk_src_unified__runtime__runtime_state state_0 = _self->state_0; /* src/unified_runtime/runtime-state */
  kk_drop_match(_self, {kk_string_dup(line_0, _ctx);kk_string_dup(op_0, _ctx);kk_src_unified__runtime__runtime_state_dup(state_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10030_0_120 = kk_string_unbox(_b_x116); /*string*/;
  kk_unit_t _x_x573 = kk_Unit;
  kk_src_unified__runtime__mlift_server_loop_10072(line_0, op_0, state_0, _c_x10030_0_120, _ctx);
  return kk_unit_box(_x_x573);
}

kk_unit_t kk_src_unified__runtime__mlift_server_loop_10073(kk_src_unified__runtime__runtime_state state_0, kk_string_t line_0, kk_context_t* _ctx) { /* (state : runtime-state, line : string) -> <console/console,exn> () */ 
  bool _match_x246;
  kk_string_t _x_x455 = kk_string_dup(line_0, _ctx); /*string*/
  kk_string_t _x_x456 = kk_string_empty(); /*string*/
  _match_x246 = kk_string_is_neq(_x_x455,_x_x456,kk_context()); /*bool*/
  if (_match_x246) {
    kk_string_t op_0;
    kk_box_t _x_x458;
    kk_box_t _x_x462;
    kk_string_t _x_x463 = kk_string_dup(line_0, _ctx); /*string*/
    _x_x462 = kk_string_box(_x_x463); /*10000*/
    _x_x458 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__new_mlift_server_loop_10073_fun459(_ctx), _x_x462, _ctx); /*10001*/
    op_0 = kk_string_unbox(_x_x458); /*string*/
    kk_string_t x_0_10076;
    if (kk_string_cmp_cstr_borrow(op_0, "emit", _ctx) == 0) {
      kk_src_unified__runtime__event_type et;
      kk_box_t _x_x465;
      kk_box_t _x_x469;
      kk_string_t _x_x470 = kk_string_dup(line_0, _ctx); /*string*/
      _x_x469 = kk_string_box(_x_x470); /*10000*/
      _x_x465 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__new_mlift_server_loop_10073_fun466(_ctx), _x_x469, _ctx); /*10001*/
      et = kk_src_unified__runtime__event_type_unbox(_x_x465, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
      kk_src_unified__runtime__runtime_state new_state;
      kk_box_t _x_x471;
      kk_box_t _x_x487;
      kk_src_unified__runtime__runtime_state _x_x488 = kk_src_unified__runtime__runtime_state_dup(state_0, _ctx); /*src/unified_runtime/runtime-state*/
      _x_x487 = kk_src_unified__runtime__runtime_state_box(_x_x488, _ctx); /*10002*/
      _x_x471 = kk_std_core_hnd__open_none3(kk_src_unified__runtime__new_mlift_server_loop_10073_fun472(_ctx), kk_src_unified__runtime__event_type_box(et, _ctx), kk_double_box(0x1.8p0, _ctx), _x_x487, _ctx); /*10003*/
      new_state = kk_src_unified__runtime__runtime_state_unbox(_x_x471, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
      kk_string_t _x_x489;
      kk_define_string_literal(, _s_x490, 12, "{\"emitted\":\"", _ctx)
      _x_x489 = kk_string_dup(_s_x490, _ctx); /*string*/
      kk_string_t _x_x491;
      kk_string_t _x_x492;
      kk_box_t _x_x493 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__new_mlift_server_loop_10073_fun494(_ctx), kk_src_unified__runtime__event_type_box(et, _ctx), _ctx); /*10001*/
      _x_x492 = kk_string_unbox(_x_x493); /*string*/
      kk_string_t _x_x497;
      kk_string_t _x_x498;
      kk_define_string_literal(, _s_x499, 10, "\",\"state\":", _ctx)
      _x_x498 = kk_string_dup(_s_x499, _ctx); /*string*/
      kk_string_t _x_x500;
      kk_string_t _x_x501;
      kk_box_t _x_x502 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__new_mlift_server_loop_10073_fun503(_ctx), kk_src_unified__runtime__runtime_state_box(new_state, _ctx), _ctx); /*10001*/
      _x_x501 = kk_string_unbox(_x_x502); /*string*/
      kk_string_t _x_x506;
      kk_define_string_literal(, _s_x507, 1, "}", _ctx)
      _x_x506 = kk_string_dup(_s_x507, _ctx); /*string*/
      _x_x500 = kk_std_core_types__lp__plus__plus__rp_(_x_x501, _x_x506, _ctx); /*string*/
      _x_x497 = kk_std_core_types__lp__plus__plus__rp_(_x_x498, _x_x500, _ctx); /*string*/
      _x_x491 = kk_std_core_types__lp__plus__plus__rp_(_x_x492, _x_x497, _ctx); /*string*/
      x_0_10076 = kk_std_core_types__lp__plus__plus__rp_(_x_x489, _x_x491, _ctx); /*string*/
      goto _match_x464;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "cascade", _ctx) == 0) {
      kk_src_unified__runtime__event_type et_0_0;
      kk_box_t _x_x508;
      kk_box_t _x_x512;
      kk_string_t _x_x513 = kk_string_dup(line_0, _ctx); /*string*/
      _x_x512 = kk_string_box(_x_x513); /*10000*/
      _x_x508 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__new_mlift_server_loop_10073_fun509(_ctx), _x_x512, _ctx); /*10001*/
      et_0_0 = kk_src_unified__runtime__event_type_unbox(_x_x508, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
      kk_std_core_types__tuple2 _match_x248;
      kk_box_t _x_x514;
      kk_box_t _x_x519;
      kk_src_unified__runtime__runtime_state _x_x520 = kk_src_unified__runtime__runtime_state_dup(state_0, _ctx); /*src/unified_runtime/runtime-state*/
      _x_x519 = kk_src_unified__runtime__runtime_state_box(_x_x520, _ctx); /*10001*/
      _x_x514 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__new_mlift_server_loop_10073_fun515(_ctx), kk_src_unified__runtime__event_type_box(et_0_0, _ctx), _x_x519, _ctx); /*10002*/
      _match_x248 = kk_std_core_types__tuple2_unbox(_x_x514, KK_OWNED, _ctx); /*(int, src/unified_runtime/runtime-state)*/
      {
        kk_box_t _box_x86 = _match_x248.fst;
        kk_box_t _box_x87 = _match_x248.snd;
        kk_src_unified__runtime__runtime_state _pat_3_4 = kk_src_unified__runtime__runtime_state_unbox(_box_x87, KK_BORROWED, _ctx);
        struct kk_src_unified__runtime_Runtime_state* _con_x521 = kk_src_unified__runtime__as_Runtime_state(_pat_3_4, _ctx);
        kk_integer_t handlers = kk_integer_unbox(_box_x86, _ctx);
        kk_integer_dup(handlers, _ctx);
        kk_std_core_types__tuple2_drop(_match_x248, _ctx);
        kk_string_t _x_x522;
        kk_define_string_literal(, _s_x523, 12, "{\"cascade\":\"", _ctx)
        _x_x522 = kk_string_dup(_s_x523, _ctx); /*string*/
        kk_string_t _x_x524;
        kk_string_t _x_x525;
        kk_box_t _x_x526 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__new_mlift_server_loop_10073_fun527(_ctx), kk_src_unified__runtime__event_type_box(et_0_0, _ctx), _ctx); /*10001*/
        _x_x525 = kk_string_unbox(_x_x526); /*string*/
        kk_string_t _x_x530;
        kk_string_t _x_x531;
        kk_define_string_literal(, _s_x532, 13, "\",\"handlers\":", _ctx)
        _x_x531 = kk_string_dup(_s_x532, _ctx); /*string*/
        kk_string_t _x_x533;
        kk_string_t _x_x534 = kk_std_core_int_show(handlers, _ctx); /*string*/
        kk_string_t _x_x535;
        kk_define_string_literal(, _s_x536, 1, "}", _ctx)
        _x_x535 = kk_string_dup(_s_x536, _ctx); /*string*/
        _x_x533 = kk_std_core_types__lp__plus__plus__rp_(_x_x534, _x_x535, _ctx); /*string*/
        _x_x530 = kk_std_core_types__lp__plus__plus__rp_(_x_x531, _x_x533, _ctx); /*string*/
        _x_x524 = kk_std_core_types__lp__plus__plus__rp_(_x_x525, _x_x530, _ctx); /*string*/
        x_0_10076 = kk_std_core_types__lp__plus__plus__rp_(_x_x522, _x_x524, _ctx); /*string*/
        goto _match_x464;
      }
    }
    if (kk_string_cmp_cstr_borrow(op_0, "profile", _ctx) == 0) {
      kk_string_t _x_x537;
      kk_define_string_literal(, _s_x538, 29, "{\"profile\":\"enabled\",\"calls\":", _ctx)
      _x_x537 = kk_string_dup(_s_x538, _ctx); /*string*/
      kk_string_t _x_x539;
      kk_string_t _x_x540;
      kk_integer_t _x_x541;
      kk_box_t _x_x542;
      kk_box_t _x_x546;
      kk_src_unified__runtime__runtime_state _x_x547 = kk_src_unified__runtime__runtime_state_dup(state_0, _ctx); /*src/unified_runtime/runtime-state*/
      _x_x546 = kk_src_unified__runtime__runtime_state_box(_x_x547, _ctx); /*10000*/
      _x_x542 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__new_mlift_server_loop_10073_fun543(_ctx), _x_x546, _ctx); /*10001*/
      _x_x541 = kk_integer_unbox(_x_x542, _ctx); /*int*/
      _x_x540 = kk_std_core_int_show(_x_x541, _ctx); /*string*/
      kk_string_t _x_x548;
      kk_define_string_literal(, _s_x549, 1, "}", _ctx)
      _x_x548 = kk_string_dup(_s_x549, _ctx); /*string*/
      _x_x539 = kk_std_core_types__lp__plus__plus__rp_(_x_x540, _x_x548, _ctx); /*string*/
      x_0_10076 = kk_std_core_types__lp__plus__plus__rp_(_x_x537, _x_x539, _ctx); /*string*/
      goto _match_x464;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_box_t _x_x550;
      kk_box_t _x_x554;
      kk_src_unified__runtime__runtime_state _x_x555 = kk_src_unified__runtime__runtime_state_dup(state_0, _ctx); /*src/unified_runtime/runtime-state*/
      _x_x554 = kk_src_unified__runtime__runtime_state_box(_x_x555, _ctx); /*10000*/
      _x_x550 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__new_mlift_server_loop_10073_fun551(_ctx), _x_x554, _ctx); /*10001*/
      x_0_10076 = kk_string_unbox(_x_x550); /*string*/
      goto _match_x464;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "hot", _ctx) == 0) {
      kk_string_t _x_x556;
      kk_define_string_literal(, _s_x557, 13, "{\"hot_paths\":", _ctx)
      _x_x556 = kk_string_dup(_s_x557, _ctx); /*string*/
      kk_string_t _x_x558;
      kk_string_t _x_x559;
      kk_integer_t _x_x560;
      kk_box_t _x_x561;
      kk_box_t _x_x565;
      kk_src_unified__runtime__runtime_state _x_x566 = kk_src_unified__runtime__runtime_state_dup(state_0, _ctx); /*src/unified_runtime/runtime-state*/
      _x_x565 = kk_src_unified__runtime__runtime_state_box(_x_x566, _ctx); /*10000*/
      _x_x561 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__new_mlift_server_loop_10073_fun562(_ctx), _x_x565, _ctx); /*10001*/
      _x_x560 = kk_integer_unbox(_x_x561, _ctx); /*int*/
      _x_x559 = kk_std_core_int_show(_x_x560, _ctx); /*string*/
      kk_string_t _x_x567;
      kk_define_string_literal(, _s_x568, 21, ",\"threshold_ms\":10.0}", _ctx)
      _x_x567 = kk_string_dup(_s_x568, _ctx); /*string*/
      _x_x558 = kk_std_core_types__lp__plus__plus__rp_(_x_x559, _x_x567, _ctx); /*string*/
      x_0_10076 = kk_std_core_types__lp__plus__plus__rp_(_x_x556, _x_x558, _ctx); /*string*/
      goto _match_x464;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "quit", _ctx) == 0) {
      kk_define_string_literal(, _s_x569, 20, "{\"status\":\"stopped\"}", _ctx)
      x_0_10076 = kk_string_dup(_s_x569, _ctx); /*string*/
      goto _match_x464;
    }
    {
      kk_define_string_literal(, _s_x570, 22, "{\"error\":\"unknown op\"}", _ctx)
      x_0_10076 = kk_string_dup(_s_x570, _ctx); /*string*/
    }
    _match_x464: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10076, _ctx);
      kk_box_t _x_x571 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__new_mlift_server_loop_10073_fun572(line_0, op_0, state_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x571); return kk_Unit;
    }
    {
      kk_src_unified__runtime__mlift_server_loop_10072(line_0, op_0, state_0, x_0_10076, _ctx); return kk_Unit;
    }
  }
  {
    kk_datatype_ptr_dropn(state_0, (KK_I32(4)), _ctx);
    kk_string_drop(line_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun575__t {
  struct kk_function_s _base;
  kk_src_unified__runtime__runtime_state state_2;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun575(kk_function_t _fself, kk_box_t _b_x122, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun575(kk_src_unified__runtime__runtime_state state_2, kk_context_t* _ctx) {
  struct kk_src_unified__runtime_server_loop_fun575__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime_server_loop_fun575__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime_server_loop_fun575, kk_context());
  _self->state_2 = state_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun575(kk_function_t _fself, kk_box_t _b_x122, kk_context_t* _ctx) {
  struct kk_src_unified__runtime_server_loop_fun575__t* _self = kk_function_as(struct kk_src_unified__runtime_server_loop_fun575__t*, _fself, _ctx);
  kk_src_unified__runtime__runtime_state state_2 = _self->state_2; /* src/unified_runtime/runtime-state */
  kk_drop_match(_self, {kk_src_unified__runtime__runtime_state_dup(state_2, _ctx);}, {}, _ctx)
  kk_string_t line_1_233 = kk_string_unbox(_b_x122); /*string*/;
  kk_unit_t _x_x576 = kk_Unit;
  kk_src_unified__runtime__mlift_server_loop_10073(state_2, line_1_233, _ctx);
  return kk_unit_box(_x_x576);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun581__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun581(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun581(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun581, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun581(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x582;
  kk_string_t _x_x583 = kk_string_unbox(_b_x125); /*string*/
  _x_x582 = kk_src_unified__runtime_extract_op(_x_x583, _ctx); /*string*/
  return kk_string_box(_x_x582);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun588__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun588(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun588(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun588, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun588(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__event_type _x_x589;
  kk_string_t _x_x590 = kk_string_unbox(_b_x130); /*string*/
  _x_x589 = kk_src_unified__runtime_extract_event_type(_x_x590, _ctx); /*src/unified_runtime/event-type*/
  return kk_src_unified__runtime__event_type_box(_x_x589, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun594__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun594(kk_function_t _fself, kk_box_t _b_x137, kk_box_t _b_x138, kk_box_t _b_x139, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun594(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun594, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun594(kk_function_t _fself, kk_box_t _b_x137, kk_box_t _b_x138, kk_box_t _b_x139, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__runtime_state state_0_1_146 = kk_src_unified__runtime__runtime_state_unbox(_b_x139, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/;
  kk_integer_t new_event_count_1;
  kk_integer_t _x_x595;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x596 = kk_src_unified__runtime__as_Runtime_state(state_0_1_146, _ctx);
    kk_integer_t _x_6 = _con_x596->event_count;
    kk_integer_dup(_x_6, _ctx);
    _x_x595 = _x_6; /*int*/
  }
  new_event_count_1 = kk_integer_add_small_const(_x_x595, 1, _ctx); /*int*/
  kk_integer_t new_total_calls_1;
  kk_integer_t _x_x597;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x598 = kk_src_unified__runtime__as_Runtime_state(state_0_1_146, _ctx);
    kk_integer_t _x_0_2 = _con_x598->total_calls;
    kk_integer_dup(_x_0_2, _ctx);
    _x_x597 = _x_0_2; /*int*/
  }
  new_total_calls_1 = kk_integer_add_small_const(_x_x597, 1, _ctx); /*int*/
  double new_total_time_1;
  double _x_x599;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x600 = kk_src_unified__runtime__as_Runtime_state(state_0_1_146, _ctx);
    double _x_1_1 = _con_x600->total_time_ms;
    _x_x599 = _x_1_1; /*float64*/
  }
  double _x_x601;
  kk_box_t _x_x602 = kk_box_dup(_b_x138, _ctx); /*10001*/
  _x_x601 = kk_double_unbox(_x_x602, KK_OWNED, _ctx); /*float64*/
  new_total_time_1 = (_x_x599 + _x_x601); /*float64*/
  kk_string_t event_name_1;
  kk_src_unified__runtime__event_type _x_x603 = kk_src_unified__runtime__event_type_unbox(_b_x137, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  event_name_1 = kk_src_unified__runtime_event_type_to_string(_x_x603, _ctx); /*string*/
  kk_integer_t new_hot_count_1;
  bool _match_x245;
  double _x_x604 = kk_double_unbox(_b_x138, KK_OWNED, _ctx); /*float64*/
  _match_x245 = (_x_x604 > (0x1.4p3)); /*bool*/
  if (_match_x245) {
    kk_integer_t _x_x605;
    {
      struct kk_src_unified__runtime_Runtime_state* _con_x606 = kk_src_unified__runtime__as_Runtime_state(state_0_1_146, _ctx);
      kk_integer_t _pat_0_2_1 = _con_x606->event_count;
      kk_integer_t _pat_1_2_1 = _con_x606->total_calls;
      kk_string_t _pat_3_2_1 = _con_x606->last_event;
      kk_integer_t _x_2_1 = _con_x606->hot_paths_count;
      if kk_likely(kk_datatype_ptr_is_unique(state_0_1_146, _ctx)) {
        kk_string_drop(_pat_3_2_1, _ctx);
        kk_integer_drop(_pat_1_2_1, _ctx);
        kk_integer_drop(_pat_0_2_1, _ctx);
        kk_datatype_ptr_free(state_0_1_146, _ctx);
      }
      else {
        kk_integer_dup(_x_2_1, _ctx);
        kk_datatype_ptr_decref(state_0_1_146, _ctx);
      }
      _x_x605 = _x_2_1; /*int*/
    }
    new_hot_count_1 = kk_integer_add_small_const(_x_x605, 1, _ctx); /*int*/
  }
  else {
    struct kk_src_unified__runtime_Runtime_state* _con_x607 = kk_src_unified__runtime__as_Runtime_state(state_0_1_146, _ctx);
    kk_integer_t _pat_0_4_1 = _con_x607->event_count;
    kk_integer_t _pat_1_3_1 = _con_x607->total_calls;
    kk_string_t _pat_3_3_1 = _con_x607->last_event;
    kk_integer_t _x_3_1 = _con_x607->hot_paths_count;
    if kk_likely(kk_datatype_ptr_is_unique(state_0_1_146, _ctx)) {
      kk_string_drop(_pat_3_3_1, _ctx);
      kk_integer_drop(_pat_1_3_1, _ctx);
      kk_integer_drop(_pat_0_4_1, _ctx);
      kk_datatype_ptr_free(state_0_1_146, _ctx);
    }
    else {
      kk_integer_dup(_x_3_1, _ctx);
      kk_datatype_ptr_decref(state_0_1_146, _ctx);
    }
    new_hot_count_1 = _x_3_1; /*int*/
  }
  kk_src_unified__runtime__runtime_state _x_x608 = kk_src_unified__runtime__new_Runtime_state(kk_reuse_null, 0, new_event_count_1, new_total_calls_1, new_total_time_1, event_name_1, new_hot_count_1, _ctx); /*src/unified_runtime/runtime-state*/
  return kk_src_unified__runtime__runtime_state_box(_x_x608, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun616__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun616(kk_function_t _fself, kk_box_t _b_x149, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun616(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun616, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun616(kk_function_t _fself, kk_box_t _b_x149, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x617;
  kk_src_unified__runtime__event_type _x_x618 = kk_src_unified__runtime__event_type_unbox(_b_x149, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  _x_x617 = kk_src_unified__runtime_event_type_to_string(_x_x618, _ctx); /*string*/
  return kk_string_box(_x_x617);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun625__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun625(kk_function_t _fself, kk_box_t _b_x152, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun625(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun625, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun625(kk_function_t _fself, kk_box_t _b_x152, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x626;
  kk_src_unified__runtime__runtime_state _x_x627 = kk_src_unified__runtime__runtime_state_unbox(_b_x152, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
  _x_x626 = kk_src_unified__runtime_json_state(_x_x627, _ctx); /*string*/
  return kk_string_box(_x_x626);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun631__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun631(kk_function_t _fself, kk_box_t _b_x155, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun631(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun631, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun631(kk_function_t _fself, kk_box_t _b_x155, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__event_type _x_x632;
  kk_string_t _x_x633 = kk_string_unbox(_b_x155); /*string*/
  _x_x632 = kk_src_unified__runtime_extract_event_type(_x_x633, _ctx); /*src/unified_runtime/event-type*/
  return kk_src_unified__runtime__event_type_box(_x_x632, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun637__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun637(kk_function_t _fself, kk_box_t _b_x161, kk_box_t _b_x162, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun637(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun637, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun637(kk_function_t _fself, kk_box_t _b_x161, kk_box_t _b_x162, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x638;
  kk_src_unified__runtime__event_type _x_x639 = kk_src_unified__runtime__event_type_unbox(_b_x161, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  kk_src_unified__runtime__runtime_state _x_x640 = kk_src_unified__runtime__runtime_state_unbox(_b_x162, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
  _x_x638 = kk_src_unified__runtime_check_cascade_profiled(_x_x639, _x_x640, _ctx); /*(int, src/unified_runtime/runtime-state)*/
  return kk_std_core_types__tuple2_box(_x_x638, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun649__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun649(kk_function_t _fself, kk_box_t _b_x167, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun649(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun649, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun649(kk_function_t _fself, kk_box_t _b_x167, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x650;
  kk_src_unified__runtime__event_type _x_x651 = kk_src_unified__runtime__event_type_unbox(_b_x167, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  _x_x650 = kk_src_unified__runtime_event_type_to_string(_x_x651, _ctx); /*string*/
  return kk_string_box(_x_x650);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun665__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun665(kk_function_t _fself, kk_box_t _b_x170, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun665(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun665, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun665(kk_function_t _fself, kk_box_t _b_x170, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__runtime_state _this_1_234 = kk_src_unified__runtime__runtime_state_unbox(_b_x170, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/;
  kk_integer_t _x_x666;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x667 = kk_src_unified__runtime__as_Runtime_state(_this_1_234, _ctx);
    kk_integer_t _pat_0_0_1_0 = _con_x667->event_count;
    kk_integer_t _x_4_0 = _con_x667->total_calls;
    kk_string_t _pat_2_0_0_1 = _con_x667->last_event;
    kk_integer_t _pat_3_0_0_0 = _con_x667->hot_paths_count;
    if kk_likely(kk_datatype_ptr_is_unique(_this_1_234, _ctx)) {
      kk_integer_drop(_pat_3_0_0_0, _ctx);
      kk_string_drop(_pat_2_0_0_1, _ctx);
      kk_integer_drop(_pat_0_0_1_0, _ctx);
      kk_datatype_ptr_free(_this_1_234, _ctx);
    }
    else {
      kk_integer_dup(_x_4_0, _ctx);
      kk_datatype_ptr_decref(_this_1_234, _ctx);
    }
    _x_x666 = _x_4_0; /*int*/
  }
  return kk_integer_box(_x_x666, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun673__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun673(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun673(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun673, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun673(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x674;
  kk_src_unified__runtime__runtime_state _x_x675 = kk_src_unified__runtime__runtime_state_unbox(_b_x173, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
  _x_x674 = kk_src_unified__runtime_json_state(_x_x675, _ctx); /*string*/
  return kk_string_box(_x_x674);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun684__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun684(kk_function_t _fself, kk_box_t _b_x176, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun684(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun684, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun684(kk_function_t _fself, kk_box_t _b_x176, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__runtime_state _this_0_0_235 = kk_src_unified__runtime__runtime_state_unbox(_b_x176, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/;
  kk_integer_t _x_x685;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x686 = kk_src_unified__runtime__as_Runtime_state(_this_0_0_235, _ctx);
    kk_integer_t _pat_0_1_0_1 = _con_x686->event_count;
    kk_integer_t _pat_1_1_0_0 = _con_x686->total_calls;
    kk_string_t _pat_3_1_0_0 = _con_x686->last_event;
    kk_integer_t _x_0_0_0 = _con_x686->hot_paths_count;
    if kk_likely(kk_datatype_ptr_is_unique(_this_0_0_235, _ctx)) {
      kk_string_drop(_pat_3_1_0_0, _ctx);
      kk_integer_drop(_pat_1_1_0_0, _ctx);
      kk_integer_drop(_pat_0_1_0_1, _ctx);
      kk_datatype_ptr_free(_this_0_0_235, _ctx);
    }
    else {
      kk_integer_dup(_x_0_0_0, _ctx);
      kk_datatype_ptr_decref(_this_0_0_235, _ctx);
    }
    _x_x685 = _x_0_0_0; /*int*/
  }
  return kk_integer_box(_x_x685, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun694__t {
  struct kk_function_s _base;
  kk_string_t op_1;
  kk_src_unified__runtime__runtime_state state_2;
  kk_string_t x_1_10078;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun694(kk_function_t _fself, kk_box_t _b_x193, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun694(kk_string_t op_1, kk_src_unified__runtime__runtime_state state_2, kk_string_t x_1_10078, kk_context_t* _ctx) {
  struct kk_src_unified__runtime_server_loop_fun694__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime_server_loop_fun694__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime_server_loop_fun694, kk_context());
  _self->op_1 = op_1;
  _self->state_2 = state_2;
  _self->x_1_10078 = x_1_10078;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun694(kk_function_t _fself, kk_box_t _b_x193, kk_context_t* _ctx) {
  struct kk_src_unified__runtime_server_loop_fun694__t* _self = kk_function_as(struct kk_src_unified__runtime_server_loop_fun694__t*, _fself, _ctx);
  kk_string_t op_1 = _self->op_1; /* string */
  kk_src_unified__runtime__runtime_state state_2 = _self->state_2; /* src/unified_runtime/runtime-state */
  kk_string_t x_1_10078 = _self->x_1_10078; /* string */
  kk_drop_match(_self, {kk_string_dup(op_1, _ctx);kk_src_unified__runtime__runtime_state_dup(state_2, _ctx);kk_string_dup(x_1_10078, _ctx);}, {}, _ctx)
  kk_string_t _c_x10030_1_236 = kk_string_unbox(_b_x193); /*string*/;
  kk_unit_t _x_x695 = kk_Unit;
  kk_src_unified__runtime__mlift_server_loop_10072(x_1_10078, op_1, state_2, _c_x10030_1_236, _ctx);
  return kk_unit_box(_x_x695);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun701__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun701(kk_function_t _fself, kk_box_t _b_x196, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun701(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun701, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun701(kk_function_t _fself, kk_box_t _b_x196, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__event_type _x_x702;
  kk_string_t _x_x703 = kk_string_unbox(_b_x196); /*string*/
  _x_x702 = kk_src_unified__runtime_extract_event_type(_x_x703, _ctx); /*src/unified_runtime/event-type*/
  return kk_src_unified__runtime__event_type_box(_x_x702, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun705__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun705(kk_function_t _fself, kk_box_t _b_x203, kk_box_t _b_x204, kk_box_t _b_x205, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun705(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun705, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun705(kk_function_t _fself, kk_box_t _b_x203, kk_box_t _b_x204, kk_box_t _b_x205, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__runtime_state state_1_0_227 = kk_src_unified__runtime__runtime_state_unbox(_b_x205, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/;
  kk_integer_t new_event_count_0_0;
  kk_integer_t _x_x706;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x707 = kk_src_unified__runtime__as_Runtime_state(state_1_0_227, _ctx);
    kk_integer_t _x_5_0 = _con_x707->event_count;
    kk_integer_dup(_x_5_0, _ctx);
    _x_x706 = _x_5_0; /*int*/
  }
  new_event_count_0_0 = kk_integer_add_small_const(_x_x706, 1, _ctx); /*int*/
  kk_integer_t new_total_calls_0_0;
  kk_integer_t _x_x708;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x709 = kk_src_unified__runtime__as_Runtime_state(state_1_0_227, _ctx);
    kk_integer_t _x_0_1_0 = _con_x709->total_calls;
    kk_integer_dup(_x_0_1_0, _ctx);
    _x_x708 = _x_0_1_0; /*int*/
  }
  new_total_calls_0_0 = kk_integer_add_small_const(_x_x708, 1, _ctx); /*int*/
  double new_total_time_0_0;
  double _x_x710;
  {
    struct kk_src_unified__runtime_Runtime_state* _con_x711 = kk_src_unified__runtime__as_Runtime_state(state_1_0_227, _ctx);
    double _x_1_0_0 = _con_x711->total_time_ms;
    _x_x710 = _x_1_0_0; /*float64*/
  }
  double _x_x712;
  kk_box_t _x_x713 = kk_box_dup(_b_x204, _ctx); /*10001*/
  _x_x712 = kk_double_unbox(_x_x713, KK_OWNED, _ctx); /*float64*/
  new_total_time_0_0 = (_x_x710 + _x_x712); /*float64*/
  kk_string_t event_name_0_0;
  kk_src_unified__runtime__event_type _x_x714 = kk_src_unified__runtime__event_type_unbox(_b_x203, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  event_name_0_0 = kk_src_unified__runtime_event_type_to_string(_x_x714, _ctx); /*string*/
  kk_integer_t new_hot_count_0_0;
  bool _match_x243;
  double _x_x715 = kk_double_unbox(_b_x204, KK_OWNED, _ctx); /*float64*/
  _match_x243 = (_x_x715 > (0x1.4p3)); /*bool*/
  if (_match_x243) {
    kk_integer_t _x_x716;
    {
      struct kk_src_unified__runtime_Runtime_state* _con_x717 = kk_src_unified__runtime__as_Runtime_state(state_1_0_227, _ctx);
      kk_integer_t _pat_0_2_0_0 = _con_x717->event_count;
      kk_integer_t _pat_1_2_0_0 = _con_x717->total_calls;
      kk_string_t _pat_3_2_0_0 = _con_x717->last_event;
      kk_integer_t _x_2_0_0 = _con_x717->hot_paths_count;
      if kk_likely(kk_datatype_ptr_is_unique(state_1_0_227, _ctx)) {
        kk_string_drop(_pat_3_2_0_0, _ctx);
        kk_integer_drop(_pat_1_2_0_0, _ctx);
        kk_integer_drop(_pat_0_2_0_0, _ctx);
        kk_datatype_ptr_free(state_1_0_227, _ctx);
      }
      else {
        kk_integer_dup(_x_2_0_0, _ctx);
        kk_datatype_ptr_decref(state_1_0_227, _ctx);
      }
      _x_x716 = _x_2_0_0; /*int*/
    }
    new_hot_count_0_0 = kk_integer_add_small_const(_x_x716, 1, _ctx); /*int*/
  }
  else {
    struct kk_src_unified__runtime_Runtime_state* _con_x718 = kk_src_unified__runtime__as_Runtime_state(state_1_0_227, _ctx);
    kk_integer_t _pat_0_4_0_0 = _con_x718->event_count;
    kk_integer_t _pat_1_3_0_0 = _con_x718->total_calls;
    kk_string_t _pat_3_3_0_0 = _con_x718->last_event;
    kk_integer_t _x_3_0_0 = _con_x718->hot_paths_count;
    if kk_likely(kk_datatype_ptr_is_unique(state_1_0_227, _ctx)) {
      kk_string_drop(_pat_3_3_0_0, _ctx);
      kk_integer_drop(_pat_1_3_0_0, _ctx);
      kk_integer_drop(_pat_0_4_0_0, _ctx);
      kk_datatype_ptr_free(state_1_0_227, _ctx);
    }
    else {
      kk_integer_dup(_x_3_0_0, _ctx);
      kk_datatype_ptr_decref(state_1_0_227, _ctx);
    }
    new_hot_count_0_0 = _x_3_0_0; /*int*/
  }
  kk_src_unified__runtime__runtime_state _x_x719 = kk_src_unified__runtime__new_Runtime_state(kk_reuse_null, 0, new_event_count_0_0, new_total_calls_0_0, new_total_time_0_0, event_name_0_0, new_hot_count_0_0, _ctx); /*src/unified_runtime/runtime-state*/
  return kk_src_unified__runtime__runtime_state_box(_x_x719, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun721__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun721(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun721(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun721, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun721(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__event_type _x_x722;
  kk_string_t _x_x723 = kk_string_unbox(_b_x208); /*string*/
  _x_x722 = kk_src_unified__runtime_extract_event_type(_x_x723, _ctx); /*src/unified_runtime/event-type*/
  return kk_src_unified__runtime__event_type_box(_x_x722, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun725__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun725(kk_function_t _fself, kk_box_t _b_x214, kk_box_t _b_x215, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun725(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun725, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun725(kk_function_t _fself, kk_box_t _b_x214, kk_box_t _b_x215, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x726;
  kk_src_unified__runtime__event_type _x_x727 = kk_src_unified__runtime__event_type_unbox(_b_x214, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
  kk_src_unified__runtime__runtime_state _x_x728 = kk_src_unified__runtime__runtime_state_unbox(_b_x215, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
  _x_x726 = kk_src_unified__runtime_check_cascade_profiled(_x_x727, _x_x728, _ctx); /*(int, src/unified_runtime/runtime-state)*/
  return kk_std_core_types__tuple2_box(_x_x726, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime_server_loop_fun731__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime_server_loop_fun731(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime_new_server_loop_fun731(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime_server_loop_fun731, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime_server_loop_fun731(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x732 = kk_Unit;
  kk_src_unified__runtime__runtime_state _x_x733 = kk_src_unified__runtime__runtime_state_unbox(_b_x229, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
  kk_src_unified__runtime_server_loop(_x_x733, _ctx);
  return kk_unit_box(_x_x732);
}

kk_unit_t kk_src_unified__runtime_server_loop(kk_src_unified__runtime__runtime_state state_2, kk_context_t* _ctx) { /* (state : runtime-state) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_1_10078 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_1_10078, _ctx);
    kk_box_t _x_x574 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime_new_server_loop_fun575(state_2, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x574); return kk_Unit;
  }
  {
    bool _match_x238;
    kk_string_t _x_x577 = kk_string_dup(x_1_10078, _ctx); /*string*/
    kk_string_t _x_x578 = kk_string_empty(); /*string*/
    _match_x238 = kk_string_is_neq(_x_x577,_x_x578,kk_context()); /*bool*/
    if (_match_x238) {
      kk_string_t op_1;
      kk_box_t _x_x580;
      kk_box_t _x_x584;
      kk_string_t _x_x585 = kk_string_dup(x_1_10078, _ctx); /*string*/
      _x_x584 = kk_string_box(_x_x585); /*10000*/
      _x_x580 = kk_std_core_hnd__open_none1(kk_src_unified__runtime_new_server_loop_fun581(_ctx), _x_x584, _ctx); /*10001*/
      op_1 = kk_string_unbox(_x_x580); /*string*/
      kk_string_t x_2_10081;
      if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
        kk_src_unified__runtime__event_type et_3;
        kk_box_t _x_x587;
        kk_box_t _x_x591;
        kk_string_t _x_x592 = kk_string_dup(x_1_10078, _ctx); /*string*/
        _x_x591 = kk_string_box(_x_x592); /*10000*/
        _x_x587 = kk_std_core_hnd__open_none1(kk_src_unified__runtime_new_server_loop_fun588(_ctx), _x_x591, _ctx); /*10001*/
        et_3 = kk_src_unified__runtime__event_type_unbox(_x_x587, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
        kk_src_unified__runtime__runtime_state new_state_0;
        kk_box_t _x_x593;
        kk_box_t _x_x609;
        kk_src_unified__runtime__runtime_state _x_x610 = kk_src_unified__runtime__runtime_state_dup(state_2, _ctx); /*src/unified_runtime/runtime-state*/
        _x_x609 = kk_src_unified__runtime__runtime_state_box(_x_x610, _ctx); /*10002*/
        _x_x593 = kk_std_core_hnd__open_none3(kk_src_unified__runtime_new_server_loop_fun594(_ctx), kk_src_unified__runtime__event_type_box(et_3, _ctx), kk_double_box(0x1.8p0, _ctx), _x_x609, _ctx); /*10003*/
        new_state_0 = kk_src_unified__runtime__runtime_state_unbox(_x_x593, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
        kk_string_t _x_x611;
        kk_define_string_literal(, _s_x612, 12, "{\"emitted\":\"", _ctx)
        _x_x611 = kk_string_dup(_s_x612, _ctx); /*string*/
        kk_string_t _x_x613;
        kk_string_t _x_x614;
        kk_box_t _x_x615 = kk_std_core_hnd__open_none1(kk_src_unified__runtime_new_server_loop_fun616(_ctx), kk_src_unified__runtime__event_type_box(et_3, _ctx), _ctx); /*10001*/
        _x_x614 = kk_string_unbox(_x_x615); /*string*/
        kk_string_t _x_x619;
        kk_string_t _x_x620;
        kk_define_string_literal(, _s_x621, 10, "\",\"state\":", _ctx)
        _x_x620 = kk_string_dup(_s_x621, _ctx); /*string*/
        kk_string_t _x_x622;
        kk_string_t _x_x623;
        kk_box_t _x_x624 = kk_std_core_hnd__open_none1(kk_src_unified__runtime_new_server_loop_fun625(_ctx), kk_src_unified__runtime__runtime_state_box(new_state_0, _ctx), _ctx); /*10001*/
        _x_x623 = kk_string_unbox(_x_x624); /*string*/
        kk_string_t _x_x628;
        kk_define_string_literal(, _s_x629, 1, "}", _ctx)
        _x_x628 = kk_string_dup(_s_x629, _ctx); /*string*/
        _x_x622 = kk_std_core_types__lp__plus__plus__rp_(_x_x623, _x_x628, _ctx); /*string*/
        _x_x619 = kk_std_core_types__lp__plus__plus__rp_(_x_x620, _x_x622, _ctx); /*string*/
        _x_x613 = kk_std_core_types__lp__plus__plus__rp_(_x_x614, _x_x619, _ctx); /*string*/
        x_2_10081 = kk_std_core_types__lp__plus__plus__rp_(_x_x611, _x_x613, _ctx); /*string*/
        goto _match_x586;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
        kk_src_unified__runtime__event_type et_0_0_0;
        kk_box_t _x_x630;
        kk_box_t _x_x634;
        kk_string_t _x_x635 = kk_string_dup(x_1_10078, _ctx); /*string*/
        _x_x634 = kk_string_box(_x_x635); /*10000*/
        _x_x630 = kk_std_core_hnd__open_none1(kk_src_unified__runtime_new_server_loop_fun631(_ctx), _x_x634, _ctx); /*10001*/
        et_0_0_0 = kk_src_unified__runtime__event_type_unbox(_x_x630, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
        kk_std_core_types__tuple2 _match_x244;
        kk_box_t _x_x636;
        kk_box_t _x_x641;
        kk_src_unified__runtime__runtime_state _x_x642 = kk_src_unified__runtime__runtime_state_dup(state_2, _ctx); /*src/unified_runtime/runtime-state*/
        _x_x641 = kk_src_unified__runtime__runtime_state_box(_x_x642, _ctx); /*10001*/
        _x_x636 = kk_std_core_hnd__open_none2(kk_src_unified__runtime_new_server_loop_fun637(_ctx), kk_src_unified__runtime__event_type_box(et_0_0_0, _ctx), _x_x641, _ctx); /*10002*/
        _match_x244 = kk_std_core_types__tuple2_unbox(_x_x636, KK_OWNED, _ctx); /*(int, src/unified_runtime/runtime-state)*/
        {
          kk_box_t _box_x163 = _match_x244.fst;
          kk_box_t _box_x164 = _match_x244.snd;
          kk_src_unified__runtime__runtime_state _pat_3_4_0 = kk_src_unified__runtime__runtime_state_unbox(_box_x164, KK_BORROWED, _ctx);
          struct kk_src_unified__runtime_Runtime_state* _con_x643 = kk_src_unified__runtime__as_Runtime_state(_pat_3_4_0, _ctx);
          kk_integer_t handlers_0 = kk_integer_unbox(_box_x163, _ctx);
          kk_integer_dup(handlers_0, _ctx);
          kk_std_core_types__tuple2_drop(_match_x244, _ctx);
          kk_string_t _x_x644;
          kk_define_string_literal(, _s_x645, 12, "{\"cascade\":\"", _ctx)
          _x_x644 = kk_string_dup(_s_x645, _ctx); /*string*/
          kk_string_t _x_x646;
          kk_string_t _x_x647;
          kk_box_t _x_x648 = kk_std_core_hnd__open_none1(kk_src_unified__runtime_new_server_loop_fun649(_ctx), kk_src_unified__runtime__event_type_box(et_0_0_0, _ctx), _ctx); /*10001*/
          _x_x647 = kk_string_unbox(_x_x648); /*string*/
          kk_string_t _x_x652;
          kk_string_t _x_x653;
          kk_define_string_literal(, _s_x654, 13, "\",\"handlers\":", _ctx)
          _x_x653 = kk_string_dup(_s_x654, _ctx); /*string*/
          kk_string_t _x_x655;
          kk_string_t _x_x656 = kk_std_core_int_show(handlers_0, _ctx); /*string*/
          kk_string_t _x_x657;
          kk_define_string_literal(, _s_x658, 1, "}", _ctx)
          _x_x657 = kk_string_dup(_s_x658, _ctx); /*string*/
          _x_x655 = kk_std_core_types__lp__plus__plus__rp_(_x_x656, _x_x657, _ctx); /*string*/
          _x_x652 = kk_std_core_types__lp__plus__plus__rp_(_x_x653, _x_x655, _ctx); /*string*/
          _x_x646 = kk_std_core_types__lp__plus__plus__rp_(_x_x647, _x_x652, _ctx); /*string*/
          x_2_10081 = kk_std_core_types__lp__plus__plus__rp_(_x_x644, _x_x646, _ctx); /*string*/
          goto _match_x586;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_1, "profile", _ctx) == 0) {
        kk_string_t _x_x659;
        kk_define_string_literal(, _s_x660, 29, "{\"profile\":\"enabled\",\"calls\":", _ctx)
        _x_x659 = kk_string_dup(_s_x660, _ctx); /*string*/
        kk_string_t _x_x661;
        kk_string_t _x_x662;
        kk_integer_t _x_x663;
        kk_box_t _x_x664;
        kk_box_t _x_x668;
        kk_src_unified__runtime__runtime_state _x_x669 = kk_src_unified__runtime__runtime_state_dup(state_2, _ctx); /*src/unified_runtime/runtime-state*/
        _x_x668 = kk_src_unified__runtime__runtime_state_box(_x_x669, _ctx); /*10000*/
        _x_x664 = kk_std_core_hnd__open_none1(kk_src_unified__runtime_new_server_loop_fun665(_ctx), _x_x668, _ctx); /*10001*/
        _x_x663 = kk_integer_unbox(_x_x664, _ctx); /*int*/
        _x_x662 = kk_std_core_int_show(_x_x663, _ctx); /*string*/
        kk_string_t _x_x670;
        kk_define_string_literal(, _s_x671, 1, "}", _ctx)
        _x_x670 = kk_string_dup(_s_x671, _ctx); /*string*/
        _x_x661 = kk_std_core_types__lp__plus__plus__rp_(_x_x662, _x_x670, _ctx); /*string*/
        x_2_10081 = kk_std_core_types__lp__plus__plus__rp_(_x_x659, _x_x661, _ctx); /*string*/
        goto _match_x586;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
        kk_box_t _x_x672;
        kk_box_t _x_x676;
        kk_src_unified__runtime__runtime_state _x_x677 = kk_src_unified__runtime__runtime_state_dup(state_2, _ctx); /*src/unified_runtime/runtime-state*/
        _x_x676 = kk_src_unified__runtime__runtime_state_box(_x_x677, _ctx); /*10000*/
        _x_x672 = kk_std_core_hnd__open_none1(kk_src_unified__runtime_new_server_loop_fun673(_ctx), _x_x676, _ctx); /*10001*/
        x_2_10081 = kk_string_unbox(_x_x672); /*string*/
        goto _match_x586;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "hot", _ctx) == 0) {
        kk_string_t _x_x678;
        kk_define_string_literal(, _s_x679, 13, "{\"hot_paths\":", _ctx)
        _x_x678 = kk_string_dup(_s_x679, _ctx); /*string*/
        kk_string_t _x_x680;
        kk_string_t _x_x681;
        kk_integer_t _x_x682;
        kk_box_t _x_x683;
        kk_box_t _x_x687;
        kk_src_unified__runtime__runtime_state _x_x688 = kk_src_unified__runtime__runtime_state_dup(state_2, _ctx); /*src/unified_runtime/runtime-state*/
        _x_x687 = kk_src_unified__runtime__runtime_state_box(_x_x688, _ctx); /*10000*/
        _x_x683 = kk_std_core_hnd__open_none1(kk_src_unified__runtime_new_server_loop_fun684(_ctx), _x_x687, _ctx); /*10001*/
        _x_x682 = kk_integer_unbox(_x_x683, _ctx); /*int*/
        _x_x681 = kk_std_core_int_show(_x_x682, _ctx); /*string*/
        kk_string_t _x_x689;
        kk_define_string_literal(, _s_x690, 21, ",\"threshold_ms\":10.0}", _ctx)
        _x_x689 = kk_string_dup(_s_x690, _ctx); /*string*/
        _x_x680 = kk_std_core_types__lp__plus__plus__rp_(_x_x681, _x_x689, _ctx); /*string*/
        x_2_10081 = kk_std_core_types__lp__plus__plus__rp_(_x_x678, _x_x680, _ctx); /*string*/
        goto _match_x586;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "quit", _ctx) == 0) {
        kk_define_string_literal(, _s_x691, 20, "{\"status\":\"stopped\"}", _ctx)
        x_2_10081 = kk_string_dup(_s_x691, _ctx); /*string*/
        goto _match_x586;
      }
      {
        kk_define_string_literal(, _s_x692, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_2_10081 = kk_string_dup(_s_x692, _ctx); /*string*/
      }
      _match_x586: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_2_10081, _ctx);
        kk_box_t _x_x693 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime_new_server_loop_fun694(op_1, state_2, x_1_10078, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x693); return kk_Unit;
      }
      {
        kk_unit_t ___0 = kk_Unit;
        kk_std_core_console_printsln(x_2_10081, _ctx);
        bool _match_x240;
        kk_string_t _x_x696 = kk_string_dup(op_1, _ctx); /*string*/
        kk_string_t _x_x697;
        kk_define_string_literal(, _s_x698, 4, "quit", _ctx)
        _x_x697 = kk_string_dup(_s_x698, _ctx); /*string*/
        _match_x240 = kk_string_is_neq(_x_x696,_x_x697,kk_context()); /*bool*/
        if (_match_x240) {
          kk_src_unified__runtime__runtime_state x_3_10084;
          if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_src_unified__runtime__event_type et_1_0;
            kk_box_t _x_x700 = kk_std_core_hnd__open_none1(kk_src_unified__runtime_new_server_loop_fun701(_ctx), kk_string_box(x_1_10078), _ctx); /*10001*/
            et_1_0 = kk_src_unified__runtime__event_type_unbox(_x_x700, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
            kk_box_t _x_x704 = kk_std_core_hnd__open_none3(kk_src_unified__runtime_new_server_loop_fun705(_ctx), kk_src_unified__runtime__event_type_box(et_1_0, _ctx), kk_double_box(0x1.8p0, _ctx), kk_src_unified__runtime__runtime_state_box(state_2, _ctx), _ctx); /*10003*/
            x_3_10084 = kk_src_unified__runtime__runtime_state_unbox(_x_x704, KK_OWNED, _ctx); /*src/unified_runtime/runtime-state*/
            goto _match_x699;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_src_unified__runtime__event_type et_2_0_0;
            kk_box_t _x_x720 = kk_std_core_hnd__open_none1(kk_src_unified__runtime_new_server_loop_fun721(_ctx), kk_string_box(x_1_10078), _ctx); /*10001*/
            et_2_0_0 = kk_src_unified__runtime__event_type_unbox(_x_x720, KK_OWNED, _ctx); /*src/unified_runtime/event-type*/
            kk_std_core_types__tuple2 _match_x242;
            kk_box_t _x_x724 = kk_std_core_hnd__open_none2(kk_src_unified__runtime_new_server_loop_fun725(_ctx), kk_src_unified__runtime__event_type_box(et_2_0_0, _ctx), kk_src_unified__runtime__runtime_state_box(state_2, _ctx), _ctx); /*10002*/
            _match_x242 = kk_std_core_types__tuple2_unbox(_x_x724, KK_OWNED, _ctx); /*(int, src/unified_runtime/runtime-state)*/
            {
              kk_box_t _box_x216 = _match_x242.fst;
              kk_box_t _box_x217 = _match_x242.snd;
              kk_src_unified__runtime__runtime_state ns_0 = kk_src_unified__runtime__runtime_state_unbox(_box_x217, KK_BORROWED, _ctx);
              struct kk_src_unified__runtime_Runtime_state* _con_x729 = kk_src_unified__runtime__as_Runtime_state(ns_0, _ctx);
              kk_src_unified__runtime__runtime_state_dup(ns_0, _ctx);
              kk_std_core_types__tuple2_drop(_match_x242, _ctx);
              x_3_10084 = ns_0; /*src/unified_runtime/runtime-state*/
              goto _match_x699;
            }
          }
          {
            kk_string_drop(x_1_10078, _ctx);
            kk_string_drop(op_1, _ctx);
            x_3_10084 = state_2; /*src/unified_runtime/runtime-state*/
          }
          _match_x699: ;
          if (kk_yielding(kk_context())) {
            kk_datatype_ptr_dropn(x_3_10084, (KK_I32(4)), _ctx);
            kk_box_t _x_x730 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime_new_server_loop_fun731(_ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x730); return kk_Unit;
          }
          { // tailcall
            state_2 = x_3_10084;
            goto kk__tailcall;
          }
        }
        {
          kk_string_drop(x_1_10078, _ctx);
          kk_datatype_ptr_dropn(state_2, (KK_I32(4)), _ctx);
          kk_string_drop(op_1, _ctx);
          kk_Unit; return kk_Unit;
        }
      }
    }
    {
      kk_string_drop(x_1_10078, _ctx);
      kk_datatype_ptr_dropn(state_2, (KK_I32(4)), _ctx);
      kk_Unit; return kk_Unit;
    }
  }
}

// initialization
void kk_src_unified__runtime__init(kk_context_t* _ctx){
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
  kk_std_core__init(_ctx);
  kk_std_os_readline__init(_ctx);
  kk_std_num_float64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_src_unified__runtime__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_num_float64__done(_ctx);
  kk_std_os_readline__done(_ctx);
  kk_std_core__done(_ctx);
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
