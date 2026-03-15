// Koka generated module: src/unified_runtime_v2, koka version: 3.2.2, platform: 64-bit
#include "src_unified__runtime__v2.h"

kk_src_unified__runtime__v2__unified_state kk_src_unified__runtime__v2_unified_state_fs__copy(kk_src_unified__runtime__v2__unified_state _this, kk_std_core_types__optional events, kk_std_core_types__optional profiles, kk_std_core_types__optional total_ops, kk_std_core_types__optional session_start, kk_context_t* _ctx) { /* (unified-state, events : ? (list<gan_ying/resonance-event>), profiles : ? (list<hot_paths/path-profile>), total-ops : ? int, session-start : ? float64) -> unified-state */ 
  kk_std_core_types__list _x_x376;
  if (kk_std_core_types__is_Optional(events, _ctx)) {
    kk_box_t _box_x0 = events._cons._Optional.value;
    kk_std_core_types__list _uniq_events_63 = kk_std_core_types__list_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_events_63, _ctx);
    kk_std_core_types__optional_drop(events, _ctx);
    _x_x376 = _uniq_events_63; /*list<gan_ying/resonance-event>*/
  }
  else {
    kk_std_core_types__optional_drop(events, _ctx);
    {
      struct kk_src_unified__runtime__v2_Unified_state* _con_x377 = kk_src_unified__runtime__v2__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _x = _con_x377->events;
      kk_std_core_types__list_dup(_x, _ctx);
      _x_x376 = _x; /*list<gan_ying/resonance-event>*/
    }
  }
  kk_std_core_types__list _x_x378;
  if (kk_std_core_types__is_Optional(profiles, _ctx)) {
    kk_box_t _box_x1 = profiles._cons._Optional.value;
    kk_std_core_types__list _uniq_profiles_71 = kk_std_core_types__list_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_profiles_71, _ctx);
    kk_std_core_types__optional_drop(profiles, _ctx);
    _x_x378 = _uniq_profiles_71; /*list<hot_paths/path-profile>*/
  }
  else {
    kk_std_core_types__optional_drop(profiles, _ctx);
    {
      struct kk_src_unified__runtime__v2_Unified_state* _con_x379 = kk_src_unified__runtime__v2__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x379->profiles;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x378 = _x_0; /*list<hot_paths/path-profile>*/
    }
  }
  kk_integer_t _x_x380;
  if (kk_std_core_types__is_Optional(total_ops, _ctx)) {
    kk_box_t _box_x2 = total_ops._cons._Optional.value;
    kk_integer_t _uniq_total_ops_79 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_total_ops_79, _ctx);
    kk_std_core_types__optional_drop(total_ops, _ctx);
    _x_x380 = _uniq_total_ops_79; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(total_ops, _ctx);
    {
      struct kk_src_unified__runtime__v2_Unified_state* _con_x381 = kk_src_unified__runtime__v2__as_Unified_state(_this, _ctx);
      kk_integer_t _x_1 = _con_x381->total_ops;
      kk_integer_dup(_x_1, _ctx);
      _x_x380 = _x_1; /*int*/
    }
  }
  double _x_x382;
  if (kk_std_core_types__is_Optional(session_start, _ctx)) {
    kk_box_t _box_x3 = session_start._cons._Optional.value;
    double _uniq_session_start_87 = kk_double_unbox(_box_x3, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(session_start, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x382 = _uniq_session_start_87; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(session_start, _ctx);
    {
      struct kk_src_unified__runtime__v2_Unified_state* _con_x383 = kk_src_unified__runtime__v2__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _pat_0_3 = _con_x383->events;
      kk_std_core_types__list _pat_1_4 = _con_x383->profiles;
      kk_integer_t _pat_2_3 = _con_x383->total_ops;
      double _x_2 = _con_x383->session_start;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_2_3, _ctx);
        kk_std_core_types__list_drop(_pat_1_4, _ctx);
        kk_std_core_types__list_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x382 = _x_2; /*float64*/
    }
  }
  return kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x376, _x_x378, _x_x380, _x_x382, _ctx);
}
 
// Emit event and profile the operation atomically

kk_src_unified__runtime__v2__unified_state kk_src_unified__runtime__v2_emit_profiled(kk_gan__ying__event_type et, kk_string_t source, kk_src_unified__runtime__v2__unified_state state, kk_context_t* _ctx) { /* (et : gan_ying/event-type, source : string, state : unified-state) -> unified-state */ 
  kk_hot__paths__path_profile profile;
  kk_string_t _x_x384 = kk_gan__ying_event_type_to_string(et, _ctx); /*string*/
  profile = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x384, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_std_core_types__list _x_x385;
  kk_box_t _x_x386;
  kk_gan__ying__resonance_event _x_x387;
  kk_string_t _x_x388 = kk_string_empty(); /*string*/
  _x_x387 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, source, et, _x_x388, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x386 = kk_gan__ying__resonance_event_box(_x_x387, _ctx); /*10021*/
  kk_std_core_types__list _x_x390;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x391 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x = _con_x391->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x390 = _x; /*list<gan_ying/resonance-event>*/
  }
  _x_x385 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x386, _x_x390, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x392;
  kk_std_core_types__list _x_x393;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x394 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x_0 = _con_x394->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x393 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x392 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile, _ctx), _x_x393, _ctx); /*list<10021>*/
  kk_integer_t _x_x395;
  kk_integer_t _x_x396;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x397 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_integer_t _x_1 = _con_x397->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x396 = _x_1; /*int*/
  }
  _x_x395 = kk_integer_add_small_const(_x_x396, 1, _ctx); /*int*/
  double _x_x398;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x399 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _pat_0_2 = _con_x399->events;
    kk_std_core_types__list _pat_1_2 = _con_x399->profiles;
    kk_integer_t _pat_2_2 = _con_x399->total_ops;
    double _x_2 = _con_x399->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_2_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_2, _ctx);
      kk_std_core_types__list_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x398 = _x_2; /*float64*/
  }
  return kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x385, _x_x392, _x_x395, _x_x398, _ctx);
}
 
// Check cascade handlers using gan_ying logic, profile with hot_paths

kk_std_core_types__tuple2 kk_src_unified__runtime__v2_cascade_profiled(kk_gan__ying__event_type et, kk_src_unified__runtime__v2__unified_state state, kk_context_t* _ctx) { /* (et : gan_ying/event-type, state : unified-state) -> (int, unified-state) */ 
  kk_src_unified__runtime__v2__unified_state new_state;
  kk_std_core_types__list _x_x400;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x401 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x = _con_x401->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x400 = _x; /*list<gan_ying/resonance-event>*/
  }
  kk_std_core_types__list _x_x402;
  kk_box_t _x_x403;
  kk_hot__paths__path_profile _x_x404;
  kk_string_t _x_x405;
  kk_define_string_literal(, _s_x406, 13, "cascade_check", _ctx)
  _x_x405 = kk_string_dup(_s_x406, _ctx); /*string*/
  _x_x404 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x405, kk_integer_from_small(1), 0x1p-1, 0x1p-1, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_Compute(_ctx), _ctx); /*hot_paths/path-profile*/
  _x_x403 = kk_hot__paths__path_profile_box(_x_x404, _ctx); /*10021*/
  kk_std_core_types__list _x_x407;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x408 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x_0 = _con_x408->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x407 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x402 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x403, _x_x407, _ctx); /*list<10021>*/
  kk_integer_t _x_x409;
  kk_integer_t _x_x410;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x411 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_integer_t _x_1 = _con_x411->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x410 = _x_1; /*int*/
  }
  _x_x409 = kk_integer_add_small_const(_x_x410, 1, _ctx); /*int*/
  double _x_x412;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x413 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _pat_0_2 = _con_x413->events;
    kk_std_core_types__list _pat_1_2 = _con_x413->profiles;
    kk_integer_t _pat_2_2 = _con_x413->total_ops;
    double _x_2 = _con_x413->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_2_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_2, _ctx);
      kk_std_core_types__list_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x412 = _x_2; /*float64*/
  }
  new_state = kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x400, _x_x402, _x_x409, _x_x412, _ctx); /*src/unified_runtime_v2/unified-state*/
  kk_box_t _x_x414;
  kk_integer_t _x_x415;
  if (kk_gan__ying__is_MemoryCreated(et, _ctx)) {
    _x_x415 = kk_integer_from_small(3); /*int*/
    goto _match_x416;
  }
  if (kk_gan__ying__is_MemoryUpdated(et, _ctx)) {
    _x_x415 = kk_integer_from_small(2); /*int*/
    goto _match_x416;
  }
  if (kk_gan__ying__is_ThreatDetected(et, _ctx)) {
    _x_x415 = kk_integer_from_small(5); /*int*/
    goto _match_x416;
  }
  if (kk_gan__ying__is_FlowStateEntered(et, _ctx)) {
    _x_x415 = kk_integer_from_small(2); /*int*/
    goto _match_x416;
  }
  {
    _x_x415 = kk_integer_from_small(1); /*int*/
  }
  _match_x416: ;
  _x_x414 = kk_integer_box(_x_x415, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x414, kk_src_unified__runtime__v2__unified_state_box(new_state, _ctx), _ctx);
}

kk_string_t kk_src_unified__runtime__v2_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x345;
  kk_string_t _x_x417 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x418;
  kk_define_string_literal(, _s_x419, 6, "\"emit\"", _ctx)
  _x_x418 = kk_string_dup(_s_x419, _ctx); /*string*/
  _match_x345 = kk_string_contains(_x_x417,_x_x418,kk_context()); /*bool*/
  if (_match_x345) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x420, 4, "emit", _ctx)
    return kk_string_dup(_s_x420, _ctx);
  }
  {
    bool _match_x346;
    kk_string_t _x_x421 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x422;
    kk_define_string_literal(, _s_x423, 9, "\"cascade\"", _ctx)
    _x_x422 = kk_string_dup(_s_x423, _ctx); /*string*/
    _match_x346 = kk_string_contains(_x_x421,_x_x422,kk_context()); /*bool*/
    if (_match_x346) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x424, 7, "cascade", _ctx)
      return kk_string_dup(_s_x424, _ctx);
    }
    {
      bool _match_x347;
      kk_string_t _x_x425 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x426;
      kk_define_string_literal(, _s_x427, 9, "\"profile\"", _ctx)
      _x_x426 = kk_string_dup(_s_x427, _ctx); /*string*/
      _match_x347 = kk_string_contains(_x_x425,_x_x426,kk_context()); /*bool*/
      if (_match_x347) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x428, 7, "profile", _ctx)
        return kk_string_dup(_s_x428, _ctx);
      }
      {
        bool _match_x348;
        kk_string_t _x_x429 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x430;
        kk_define_string_literal(, _s_x431, 8, "\"status\"", _ctx)
        _x_x430 = kk_string_dup(_s_x431, _ctx); /*string*/
        _match_x348 = kk_string_contains(_x_x429,_x_x430,kk_context()); /*bool*/
        if (_match_x348) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x432, 6, "status", _ctx)
          return kk_string_dup(_s_x432, _ctx);
        }
        {
          bool _match_x349;
          kk_string_t _x_x433 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x434;
          kk_define_string_literal(, _s_x435, 5, "\"hot\"", _ctx)
          _x_x434 = kk_string_dup(_s_x435, _ctx); /*string*/
          _match_x349 = kk_string_contains(_x_x433,_x_x434,kk_context()); /*bool*/
          if (_match_x349) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x436, 3, "hot", _ctx)
            return kk_string_dup(_s_x436, _ctx);
          }
          {
            bool _match_x350;
            kk_string_t _x_x437;
            kk_define_string_literal(, _s_x438, 6, "\"quit\"", _ctx)
            _x_x437 = kk_string_dup(_s_x438, _ctx); /*string*/
            _match_x350 = kk_string_contains(line,_x_x437,kk_context()); /*bool*/
            if (_match_x350) {
              kk_define_string_literal(, _s_x439, 4, "quit", _ctx)
              return kk_string_dup(_s_x439, _ctx);
            }
            {
              kk_define_string_literal(, _s_x440, 7, "unknown", _ctx)
              return kk_string_dup(_s_x440, _ctx);
            }
          }
        }
      }
    }
  }
}

kk_gan__ying__event_type kk_src_unified__runtime__v2_extract_event_type(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> gan_ying/event-type */ 
  bool _match_x341;
  kk_string_t _x_x441 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x442;
  kk_define_string_literal(, _s_x443, 14, "memory_created", _ctx)
  _x_x442 = kk_string_dup(_s_x443, _ctx); /*string*/
  _match_x341 = kk_string_contains(_x_x441,_x_x442,kk_context()); /*bool*/
  if (_match_x341) {
    kk_string_drop(line, _ctx);
    return kk_gan__ying__new_MemoryCreated(_ctx);
  }
  {
    bool _match_x342;
    kk_string_t _x_x444 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x445;
    kk_define_string_literal(, _s_x446, 14, "memory_updated", _ctx)
    _x_x445 = kk_string_dup(_s_x446, _ctx); /*string*/
    _match_x342 = kk_string_contains(_x_x444,_x_x445,kk_context()); /*bool*/
    if (_match_x342) {
      kk_string_drop(line, _ctx);
      return kk_gan__ying__new_MemoryUpdated(_ctx);
    }
    {
      bool _match_x343;
      kk_string_t _x_x447 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x448;
      kk_define_string_literal(, _s_x449, 15, "threat_detected", _ctx)
      _x_x448 = kk_string_dup(_s_x449, _ctx); /*string*/
      _match_x343 = kk_string_contains(_x_x447,_x_x448,kk_context()); /*bool*/
      if (_match_x343) {
        kk_string_drop(line, _ctx);
        return kk_gan__ying__new_ThreatDetected(_ctx);
      }
      {
        bool _match_x344;
        kk_string_t _x_x450;
        kk_define_string_literal(, _s_x451, 10, "flow_state", _ctx)
        _x_x450 = kk_string_dup(_s_x451, _ctx); /*string*/
        _match_x344 = kk_string_contains(line,_x_x450,kk_context()); /*bool*/
        if (_match_x344) {
          return kk_gan__ying__new_FlowStateEntered(_ctx);
        }
        {
          return kk_gan__ying__new_SystemStarted(_ctx);
        }
      }
    }
  }
}

kk_string_t kk_src_unified__runtime__v2_json_state(kk_src_unified__runtime__v2__unified_state s, kk_context_t* _ctx) { /* (s : unified-state) -> string */ 
  kk_string_t _x_x452;
  kk_define_string_literal(, _s_x453, 10, "{\"events\":", _ctx)
  _x_x452 = kk_string_dup(_s_x453, _ctx); /*string*/
  kk_string_t _x_x454;
  kk_string_t _x_x455;
  kk_integer_t _x_x456;
  kk_std_core_types__list _x_x457;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x458 = kk_src_unified__runtime__v2__as_Unified_state(s, _ctx);
    kk_std_core_types__list _x = _con_x458->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x457 = _x; /*list<gan_ying/resonance-event>*/
  }
  _x_x456 = kk_std_core_list__lift_length_5730(_x_x457, kk_integer_from_small(0), _ctx); /*int*/
  _x_x455 = kk_std_core_int_show(_x_x456, _ctx); /*string*/
  kk_string_t _x_x459;
  kk_string_t _x_x460;
  kk_define_string_literal(, _s_x461, 12, ",\"profiles\":", _ctx)
  _x_x460 = kk_string_dup(_s_x461, _ctx); /*string*/
  kk_string_t _x_x462;
  kk_string_t _x_x463;
  kk_integer_t _x_x464;
  kk_std_core_types__list _x_x465;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x466 = kk_src_unified__runtime__v2__as_Unified_state(s, _ctx);
    kk_std_core_types__list _x_0 = _con_x466->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x465 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x464 = kk_std_core_list__lift_length_5730(_x_x465, kk_integer_from_small(0), _ctx); /*int*/
  _x_x463 = kk_std_core_int_show(_x_x464, _ctx); /*string*/
  kk_string_t _x_x467;
  kk_string_t _x_x468;
  kk_define_string_literal(, _s_x469, 13, ",\"total_ops\":", _ctx)
  _x_x468 = kk_string_dup(_s_x469, _ctx); /*string*/
  kk_string_t _x_x470;
  kk_string_t _x_x471;
  kk_integer_t _x_x472;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x473 = kk_src_unified__runtime__v2__as_Unified_state(s, _ctx);
    kk_integer_t _x_1 = _con_x473->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x472 = _x_1; /*int*/
  }
  _x_x471 = kk_std_core_int_show(_x_x472, _ctx); /*string*/
  kk_string_t _x_x474;
  kk_string_t _x_x475;
  kk_define_string_literal(, _s_x476, 17, ",\"session_start\":", _ctx)
  _x_x475 = kk_string_dup(_s_x476, _ctx); /*string*/
  kk_string_t _x_x477;
  kk_string_t _x_x478;
  double _x_x479;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x480 = kk_src_unified__runtime__v2__as_Unified_state(s, _ctx);
    kk_std_core_types__list _pat_0_2 = _con_x480->events;
    kk_std_core_types__list _pat_1_2 = _con_x480->profiles;
    kk_integer_t _pat_2_2 = _con_x480->total_ops;
    double _x_2 = _con_x480->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(s, _ctx)) {
      kk_integer_drop(_pat_2_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_2, _ctx);
      kk_std_core_types__list_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(s, _ctx);
    }
    else {
      kk_datatype_ptr_decref(s, _ctx);
    }
    _x_x479 = _x_2; /*float64*/
  }
  _x_x478 = kk_std_num_float64_show(_x_x479, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x481;
  kk_define_string_literal(, _s_x482, 1, "}", _ctx)
  _x_x481 = kk_string_dup(_s_x482, _ctx); /*string*/
  _x_x477 = kk_std_core_types__lp__plus__plus__rp_(_x_x478, _x_x481, _ctx); /*string*/
  _x_x474 = kk_std_core_types__lp__plus__plus__rp_(_x_x475, _x_x477, _ctx); /*string*/
  _x_x470 = kk_std_core_types__lp__plus__plus__rp_(_x_x471, _x_x474, _ctx); /*string*/
  _x_x467 = kk_std_core_types__lp__plus__plus__rp_(_x_x468, _x_x470, _ctx); /*string*/
  _x_x462 = kk_std_core_types__lp__plus__plus__rp_(_x_x463, _x_x467, _ctx); /*string*/
  _x_x459 = kk_std_core_types__lp__plus__plus__rp_(_x_x460, _x_x462, _ctx); /*string*/
  _x_x454 = kk_std_core_types__lp__plus__plus__rp_(_x_x455, _x_x459, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x452, _x_x454, _ctx);
}
 
// monadic lift

kk_string_t kk_src_unified__runtime__v2__mlift_server_loop_10073(kk_std_core_types__list _y_x10025, kk_context_t* _ctx) { /* (list<hot_paths/path-profile>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */ 
  kk_integer_t hot_count = kk_std_core_list__lift_length_5730(_y_x10025, kk_integer_from_small(0), _ctx); /*int*/;
  kk_string_t _x_x483;
  kk_define_string_literal(, _s_x484, 13, "{\"hot_paths\":", _ctx)
  _x_x483 = kk_string_dup(_s_x484, _ctx); /*string*/
  kk_string_t _x_x485;
  kk_string_t _x_x486 = kk_std_core_int_show(hot_count, _ctx); /*string*/
  kk_string_t _x_x487;
  kk_define_string_literal(, _s_x488, 21, ",\"threshold_ms\":10.0}", _ctx)
  _x_x487 = kk_string_dup(_s_x488, _ctx); /*string*/
  _x_x485 = kk_std_core_types__lp__plus__plus__rp_(_x_x486, _x_x487, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x483, _x_x485, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10074_fun494__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10074_fun494(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10074_fun494(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10074_fun494, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10074_fun494(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x495;
  kk_string_t _x_x496 = kk_string_unbox(_b_x22); /*string*/
  _x_x495 = kk_src_unified__runtime__v2_extract_event_type(_x_x496, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x495, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10074_fun498__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10074_fun498(kk_function_t _fself, kk_box_t _b_x33, kk_box_t _b_x34, kk_box_t _b_x35, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10074_fun498(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10074_fun498, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10074_fun498(kk_function_t _fself, kk_box_t _b_x33, kk_box_t _b_x34, kk_box_t _b_x35, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__v2__unified_state state_1_61 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x35, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/;
  kk_hot__paths__path_profile profile_0;
  kk_string_t _x_x499;
  kk_gan__ying__event_type _x_x500;
  kk_box_t _x_x501 = kk_box_dup(_b_x33, _ctx); /*10000*/
  _x_x500 = kk_gan__ying__event_type_unbox(_x_x501, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x499 = kk_gan__ying_event_type_to_string(_x_x500, _ctx); /*string*/
  profile_0 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x499, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_src_unified__runtime__v2__unified_state _x_x502;
  kk_std_core_types__list _x_x503;
  kk_box_t _x_x504;
  kk_gan__ying__resonance_event _x_x505;
  kk_string_t _x_x506 = kk_string_unbox(_b_x34); /*string*/
  kk_gan__ying__event_type _x_x507 = kk_gan__ying__event_type_unbox(_b_x33, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_string_t _x_x508 = kk_string_empty(); /*string*/
  _x_x505 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x506, _x_x507, _x_x508, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x504 = kk_gan__ying__resonance_event_box(_x_x505, _ctx); /*10021*/
  kk_std_core_types__list _x_x510;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x511 = kk_src_unified__runtime__v2__as_Unified_state(state_1_61, _ctx);
    kk_std_core_types__list _x_4 = _con_x511->events;
    kk_std_core_types__list_dup(_x_4, _ctx);
    _x_x510 = _x_4; /*list<gan_ying/resonance-event>*/
  }
  _x_x503 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x504, _x_x510, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x512;
  kk_std_core_types__list _x_x513;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x514 = kk_src_unified__runtime__v2__as_Unified_state(state_1_61, _ctx);
    kk_std_core_types__list _x_0_1 = _con_x514->profiles;
    kk_std_core_types__list_dup(_x_0_1, _ctx);
    _x_x513 = _x_0_1; /*list<hot_paths/path-profile>*/
  }
  _x_x512 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_0, _ctx), _x_x513, _ctx); /*list<10021>*/
  kk_integer_t _x_x515;
  kk_integer_t _x_x516;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x517 = kk_src_unified__runtime__v2__as_Unified_state(state_1_61, _ctx);
    kk_integer_t _x_1_1 = _con_x517->total_ops;
    kk_integer_dup(_x_1_1, _ctx);
    _x_x516 = _x_1_1; /*int*/
  }
  _x_x515 = kk_integer_add_small_const(_x_x516, 1, _ctx); /*int*/
  double _x_x518;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x519 = kk_src_unified__runtime__v2__as_Unified_state(state_1_61, _ctx);
    kk_std_core_types__list _pat_0_2_1 = _con_x519->events;
    kk_std_core_types__list _pat_1_2_1 = _con_x519->profiles;
    kk_integer_t _pat_2_2_1 = _con_x519->total_ops;
    double _x_2_1 = _con_x519->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state_1_61, _ctx)) {
      kk_integer_drop(_pat_2_2_1, _ctx);
      kk_std_core_types__list_drop(_pat_1_2_1, _ctx);
      kk_std_core_types__list_drop(_pat_0_2_1, _ctx);
      kk_datatype_ptr_free(state_1_61, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state_1_61, _ctx);
    }
    _x_x518 = _x_2_1; /*float64*/
  }
  _x_x502 = kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x503, _x_x512, _x_x515, _x_x518, _ctx); /*src/unified_runtime_v2/unified-state*/
  return kk_src_unified__runtime__v2__unified_state_box(_x_x502, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10074_fun524__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10074_fun524(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10074_fun524(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10074_fun524, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10074_fun524(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x525;
  kk_string_t _x_x526 = kk_string_unbox(_b_x38); /*string*/
  _x_x525 = kk_src_unified__runtime__v2_extract_event_type(_x_x526, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x525, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10074_fun528__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10074_fun528(kk_function_t _fself, kk_box_t _b_x44, kk_box_t _b_x45, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10074_fun528(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10074_fun528, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10074_fun528(kk_function_t _fself, kk_box_t _b_x44, kk_box_t _b_x45, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x529;
  kk_gan__ying__event_type _x_x530 = kk_gan__ying__event_type_unbox(_b_x44, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v2__unified_state _x_x531 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x45, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x529 = kk_src_unified__runtime__v2_cascade_profiled(_x_x530, _x_x531, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x529, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10074_fun534__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10074_fun534(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10074_fun534(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10074_fun534, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10074_fun534(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x535 = kk_Unit;
  kk_src_unified__runtime__v2__unified_state _x_x536 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x63, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  kk_src_unified__runtime__v2_server_loop(_x_x536, _ctx);
  return kk_unit_box(_x_x535);
}

kk_unit_t kk_src_unified__runtime__v2__mlift_server_loop_10074(kk_string_t line, kk_string_t op, kk_src_unified__runtime__v2__unified_state state, kk_string_t _c_x10026, kk_context_t* _ctx) { /* (line : string, op : string, state : unified-state, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10026, _ctx);
  bool _match_x338;
  kk_string_t _x_x489 = kk_string_dup(op, _ctx); /*string*/
  kk_string_t _x_x490;
  kk_define_string_literal(, _s_x491, 4, "quit", _ctx)
  _x_x490 = kk_string_dup(_s_x491, _ctx); /*string*/
  _match_x338 = kk_string_is_neq(_x_x489,_x_x490,kk_context()); /*bool*/
  if (_match_x338) {
    kk_src_unified__runtime__v2__unified_state x_10076;
    if (kk_string_cmp_cstr_borrow(op, "emit", _ctx) == 0) {
      kk_string_drop(op, _ctx);
      kk_gan__ying__event_type et_1;
      kk_box_t _x_x493 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10074_fun494(_ctx), kk_string_box(line), _ctx); /*10001*/
      et_1 = kk_gan__ying__event_type_unbox(_x_x493, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_box_t _x_x497;
      kk_box_t _x_x520;
      kk_string_t _x_x521;
      kk_define_string_literal(, _s_x522, 15, "unified_runtime", _ctx)
      _x_x521 = kk_string_dup(_s_x522, _ctx); /*string*/
      _x_x520 = kk_string_box(_x_x521); /*10001*/
      _x_x497 = kk_std_core_hnd__open_none3(kk_src_unified__runtime__v2__new_mlift_server_loop_10074_fun498(_ctx), kk_gan__ying__event_type_box(et_1, _ctx), _x_x520, kk_src_unified__runtime__v2__unified_state_box(state, _ctx), _ctx); /*10003*/
      x_10076 = kk_src_unified__runtime__v2__unified_state_unbox(_x_x497, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
      goto _match_x492;
    }
    if (kk_string_cmp_cstr_borrow(op, "cascade", _ctx) == 0) {
      kk_string_drop(op, _ctx);
      kk_gan__ying__event_type et_2_0;
      kk_box_t _x_x523 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10074_fun524(_ctx), kk_string_box(line), _ctx); /*10001*/
      et_2_0 = kk_gan__ying__event_type_unbox(_x_x523, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_std_core_types__tuple2 _match_x340;
      kk_box_t _x_x527 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v2__new_mlift_server_loop_10074_fun528(_ctx), kk_gan__ying__event_type_box(et_2_0, _ctx), kk_src_unified__runtime__v2__unified_state_box(state, _ctx), _ctx); /*10002*/
      _match_x340 = kk_std_core_types__tuple2_unbox(_x_x527, KK_OWNED, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
      {
        kk_box_t _box_x46 = _match_x340.fst;
        kk_box_t _box_x47 = _match_x340.snd;
        kk_src_unified__runtime__v2__unified_state ns = kk_src_unified__runtime__v2__unified_state_unbox(_box_x47, KK_BORROWED, _ctx);
        struct kk_src_unified__runtime__v2_Unified_state* _con_x532 = kk_src_unified__runtime__v2__as_Unified_state(ns, _ctx);
        kk_src_unified__runtime__v2__unified_state_dup(ns, _ctx);
        kk_std_core_types__tuple2_drop(_match_x340, _ctx);
        x_10076 = ns; /*src/unified_runtime_v2/unified-state*/
        goto _match_x492;
      }
    }
    {
      kk_string_drop(op, _ctx);
      kk_string_drop(line, _ctx);
      x_10076 = state; /*src/unified_runtime_v2/unified-state*/
    }
    _match_x492: ;
    if (kk_yielding(kk_context())) {
      kk_datatype_ptr_dropn(x_10076, (KK_I32(3)), _ctx);
      kk_box_t _x_x533 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2__new_mlift_server_loop_10074_fun534(_ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x533); return kk_Unit;
    }
    {
      kk_src_unified__runtime__v2_server_loop(x_10076, _ctx); return kk_Unit;
    }
  }
  {
    kk_datatype_ptr_dropn(state, (KK_I32(3)), _ctx);
    kk_string_drop(op, _ctx);
    kk_string_drop(line, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun541__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun541(kk_function_t _fself, kk_box_t _b_x67, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun541(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun541, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun541(kk_function_t _fself, kk_box_t _b_x67, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x542;
  kk_string_t _x_x543 = kk_string_unbox(_b_x67); /*string*/
  _x_x542 = kk_src_unified__runtime__v2_extract_op(_x_x543, _ctx); /*string*/
  return kk_string_box(_x_x542);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun548__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun548(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun548(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun548, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun548(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x549;
  kk_string_t _x_x550 = kk_string_unbox(_b_x72); /*string*/
  _x_x549 = kk_src_unified__runtime__v2_extract_event_type(_x_x550, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x549, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun554__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun554(kk_function_t _fself, kk_box_t _b_x83, kk_box_t _b_x84, kk_box_t _b_x85, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun554(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun554, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun554(kk_function_t _fself, kk_box_t _b_x83, kk_box_t _b_x84, kk_box_t _b_x85, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__v2__unified_state state_0_0_96 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x85, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/;
  kk_hot__paths__path_profile profile;
  kk_string_t _x_x555;
  kk_gan__ying__event_type _x_x556;
  kk_box_t _x_x557 = kk_box_dup(_b_x83, _ctx); /*10000*/
  _x_x556 = kk_gan__ying__event_type_unbox(_x_x557, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x555 = kk_gan__ying_event_type_to_string(_x_x556, _ctx); /*string*/
  profile = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x555, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_src_unified__runtime__v2__unified_state _x_x558;
  kk_std_core_types__list _x_x559;
  kk_box_t _x_x560;
  kk_gan__ying__resonance_event _x_x561;
  kk_string_t _x_x562 = kk_string_unbox(_b_x84); /*string*/
  kk_gan__ying__event_type _x_x563 = kk_gan__ying__event_type_unbox(_b_x83, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_string_t _x_x564 = kk_string_empty(); /*string*/
  _x_x561 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x562, _x_x563, _x_x564, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x560 = kk_gan__ying__resonance_event_box(_x_x561, _ctx); /*10021*/
  kk_std_core_types__list _x_x566;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x567 = kk_src_unified__runtime__v2__as_Unified_state(state_0_0_96, _ctx);
    kk_std_core_types__list _x = _con_x567->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x566 = _x; /*list<gan_ying/resonance-event>*/
  }
  _x_x559 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x560, _x_x566, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x568;
  kk_std_core_types__list _x_x569;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x570 = kk_src_unified__runtime__v2__as_Unified_state(state_0_0_96, _ctx);
    kk_std_core_types__list _x_0 = _con_x570->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x569 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x568 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile, _ctx), _x_x569, _ctx); /*list<10021>*/
  kk_integer_t _x_x571;
  kk_integer_t _x_x572;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x573 = kk_src_unified__runtime__v2__as_Unified_state(state_0_0_96, _ctx);
    kk_integer_t _x_1 = _con_x573->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x572 = _x_1; /*int*/
  }
  _x_x571 = kk_integer_add_small_const(_x_x572, 1, _ctx); /*int*/
  double _x_x574;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x575 = kk_src_unified__runtime__v2__as_Unified_state(state_0_0_96, _ctx);
    kk_std_core_types__list _pat_0_2 = _con_x575->events;
    kk_std_core_types__list _pat_1_2 = _con_x575->profiles;
    kk_integer_t _pat_2_2 = _con_x575->total_ops;
    double _x_2 = _con_x575->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state_0_0_96, _ctx)) {
      kk_integer_drop(_pat_2_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_2, _ctx);
      kk_std_core_types__list_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(state_0_0_96, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state_0_0_96, _ctx);
    }
    _x_x574 = _x_2; /*float64*/
  }
  _x_x558 = kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x559, _x_x568, _x_x571, _x_x574, _ctx); /*src/unified_runtime_v2/unified-state*/
  return kk_src_unified__runtime__v2__unified_state_box(_x_x558, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun586__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun586(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun586(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun586, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun586(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x587;
  kk_gan__ying__event_type _x_x588 = kk_gan__ying__event_type_unbox(_b_x99, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x587 = kk_gan__ying_event_type_to_string(_x_x588, _ctx); /*string*/
  return kk_string_box(_x_x587);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun595__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun595(kk_function_t _fself, kk_box_t _b_x102, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun595(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun595, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun595(kk_function_t _fself, kk_box_t _b_x102, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x596;
  kk_src_unified__runtime__v2__unified_state _x_x597 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x102, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x596 = kk_src_unified__runtime__v2_json_state(_x_x597, _ctx); /*string*/
  return kk_string_box(_x_x596);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun601__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun601(kk_function_t _fself, kk_box_t _b_x105, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun601(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun601, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun601(kk_function_t _fself, kk_box_t _b_x105, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x602;
  kk_string_t _x_x603 = kk_string_unbox(_b_x105); /*string*/
  _x_x602 = kk_src_unified__runtime__v2_extract_event_type(_x_x603, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x602, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun607__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun607(kk_function_t _fself, kk_box_t _b_x111, kk_box_t _b_x112, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun607(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun607, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun607(kk_function_t _fself, kk_box_t _b_x111, kk_box_t _b_x112, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x608;
  kk_gan__ying__event_type _x_x609 = kk_gan__ying__event_type_unbox(_b_x111, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v2__unified_state _x_x610 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x112, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x608 = kk_src_unified__runtime__v2_cascade_profiled(_x_x609, _x_x610, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x608, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun619__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun619(kk_function_t _fself, kk_box_t _b_x117, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun619(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun619, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun619(kk_function_t _fself, kk_box_t _b_x117, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x620;
  kk_gan__ying__event_type _x_x621 = kk_gan__ying__event_type_unbox(_b_x117, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x620 = kk_gan__ying_event_type_to_string(_x_x621, _ctx); /*string*/
  return kk_string_box(_x_x620);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun630__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun630(kk_function_t _fself, kk_box_t _b_x120, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun630(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun630, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun630(kk_function_t _fself, kk_box_t _b_x120, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x631;
  kk_src_unified__runtime__v2__unified_state _match_x336 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x120, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x632 = kk_src_unified__runtime__v2__as_Unified_state(_match_x336, _ctx);
    kk_std_core_types__list _pat_0_0_1 = _con_x632->events;
    kk_std_core_types__list _x_3 = _con_x632->profiles;
    kk_integer_t _pat_1_0_1 = _con_x632->total_ops;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x336, _ctx)) {
      kk_integer_drop(_pat_1_0_1, _ctx);
      kk_std_core_types__list_drop(_pat_0_0_1, _ctx);
      kk_datatype_ptr_free(_match_x336, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(_match_x336, _ctx);
    }
    _x_x631 = _x_3; /*list<hot_paths/path-profile>*/
  }
  return kk_std_core_types__list_box(_x_x631, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun635__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun635(kk_function_t _fself, kk_src_unified__runtime__v2__unified_state _this_0, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun635(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun635, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun635(kk_function_t _fself, kk_src_unified__runtime__v2__unified_state _this_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x636 = kk_src_unified__runtime__v2__as_Unified_state(_this_0, _ctx);
    kk_std_core_types__list _pat_0_1_0_0 = _con_x636->events;
    kk_std_core_types__list _pat_1_1_0 = _con_x636->profiles;
    kk_integer_t _x_0_0 = _con_x636->total_ops;
    if kk_likely(kk_datatype_ptr_is_unique(_this_0, _ctx)) {
      kk_std_core_types__list_drop(_pat_1_1_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_1_0_0, _ctx);
      kk_datatype_ptr_free(_this_0, _ctx);
    }
    else {
      kk_integer_dup(_x_0_0, _ctx);
      kk_datatype_ptr_decref(_this_0, _ctx);
    }
    return _x_0_0;
  }
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun649__t {
  struct kk_function_s _base;
  kk_function_t _b_x124_159;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun649(kk_function_t _fself, kk_box_t _b_x126, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun649(kk_function_t _b_x124_159, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun649__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun649__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v2__mlift_server_loop_10075_fun649, kk_context());
  _self->_b_x124_159 = _b_x124_159;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun649(kk_function_t _fself, kk_box_t _b_x126, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun649__t* _self = kk_function_as(struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun649__t*, _fself, _ctx);
  kk_function_t _b_x124_159 = _self->_b_x124_159; /* (src/unified_runtime_v2/unified-state) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x124_159, _ctx);}, {}, _ctx)
  kk_integer_t _x_x650;
  kk_src_unified__runtime__v2__unified_state _x_x651 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x126, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x650 = kk_function_call(kk_integer_t, (kk_function_t, kk_src_unified__runtime__v2__unified_state, kk_context_t*), _b_x124_159, (_b_x124_159, _x_x651, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x650, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun655__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun655(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun655(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun655, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun655(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x656;
  kk_src_unified__runtime__v2__unified_state _x_x657 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x129, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x656 = kk_src_unified__runtime__v2_json_state(_x_x657, _ctx); /*string*/
  return kk_string_box(_x_x656);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun661__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun661(kk_function_t _fself, kk_box_t _b_x132, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun661(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun661, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun661(kk_function_t _fself, kk_box_t _b_x132, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x662;
  kk_src_unified__runtime__v2__unified_state _match_x335 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x132, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x663 = kk_src_unified__runtime__v2__as_Unified_state(_match_x335, _ctx);
    kk_std_core_types__list _pat_0_2_0 = _con_x663->events;
    kk_std_core_types__list _x_1_0 = _con_x663->profiles;
    kk_integer_t _pat_1_2_0 = _con_x663->total_ops;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x335, _ctx)) {
      kk_integer_drop(_pat_1_2_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_2_0, _ctx);
      kk_datatype_ptr_free(_match_x335, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_1_0, _ctx);
      kk_datatype_ptr_decref(_match_x335, _ctx);
    }
    _x_x662 = _x_1_0; /*list<hot_paths/path-profile>*/
  }
  return kk_std_core_types__list_box(_x_x662, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun666__t {
  struct kk_function_s _base;
};
static bool kk_src_unified__runtime__v2__mlift_server_loop_10075_fun666(kk_function_t _fself, kk_box_t _b_x138, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun666(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun666, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun668__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun668(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun668(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun668, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun668(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x669;
  kk_hot__paths__path_profile _match_x334 = kk_hot__paths__path_profile_unbox(_b_x135, KK_OWNED, _ctx); /*hot_paths/path-profile*/;
  {
    struct kk_hot__paths_Path_profile* _con_x670 = kk_hot__paths__as_Path_profile(_match_x334, _ctx);
    kk_string_t _pat_0_3_0 = _con_x670->name;
    kk_integer_t _pat_1_3_0 = _con_x670->call_count;
    kk_hot__paths__complexity _x_2_0 = _con_x670->complexity;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x334, _ctx)) {
      kk_integer_drop(_pat_1_3_0, _ctx);
      kk_string_drop(_pat_0_3_0, _ctx);
      kk_datatype_ptr_free(_match_x334, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x334, _ctx);
    }
    if (kk_hot__paths__is_High(_x_2_0, _ctx)) {
      _x_x669 = true; /*bool*/
    }
    else {
      _x_x669 = false; /*bool*/
    }
  }
  return kk_bool_box(_x_x669);
}
static bool kk_src_unified__runtime__v2__mlift_server_loop_10075_fun666(kk_function_t _fself, kk_box_t _b_x138, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x667 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun668(_ctx), _b_x138, _ctx); /*10001*/
  return kk_bool_unbox(_x_x667);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun672__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun672(kk_function_t _fself, kk_box_t _b_x149, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun672(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10075_fun672, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun672(kk_function_t _fself, kk_box_t _b_x149, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x673;
  kk_std_core_types__list _x_x674 = kk_std_core_types__list_unbox(_b_x149, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
  _x_x673 = kk_src_unified__runtime__v2__mlift_server_loop_10073(_x_x674, _ctx); /*string*/
  return kk_string_box(_x_x673);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun678__t {
  struct kk_function_s _base;
  kk_string_t line_0;
  kk_string_t op_0;
  kk_src_unified__runtime__v2__unified_state state_0;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun678(kk_function_t _fself, kk_box_t _b_x165, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun678(kk_string_t line_0, kk_string_t op_0, kk_src_unified__runtime__v2__unified_state state_0, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun678__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun678__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v2__mlift_server_loop_10075_fun678, kk_context());
  _self->line_0 = line_0;
  _self->op_0 = op_0;
  _self->state_0 = state_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10075_fun678(kk_function_t _fself, kk_box_t _b_x165, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun678__t* _self = kk_function_as(struct kk_src_unified__runtime__v2__mlift_server_loop_10075_fun678__t*, _fself, _ctx);
  kk_string_t line_0 = _self->line_0; /* string */
  kk_string_t op_0 = _self->op_0; /* string */
  kk_src_unified__runtime__v2__unified_state state_0 = _self->state_0; /* src/unified_runtime_v2/unified-state */
  kk_drop_match(_self, {kk_string_dup(line_0, _ctx);kk_string_dup(op_0, _ctx);kk_src_unified__runtime__v2__unified_state_dup(state_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10026_0_167 = kk_string_unbox(_b_x165); /*string*/;
  kk_unit_t _x_x679 = kk_Unit;
  kk_src_unified__runtime__v2__mlift_server_loop_10074(line_0, op_0, state_0, _c_x10026_0_167, _ctx);
  return kk_unit_box(_x_x679);
}

kk_unit_t kk_src_unified__runtime__v2__mlift_server_loop_10075(kk_src_unified__runtime__v2__unified_state state_0, kk_string_t line_0, kk_context_t* _ctx) { /* (state : unified-state, line : string) -> <console/console,exn> () */ 
  bool _match_x331;
  kk_string_t _x_x537 = kk_string_dup(line_0, _ctx); /*string*/
  kk_string_t _x_x538 = kk_string_empty(); /*string*/
  _match_x331 = kk_string_is_neq(_x_x537,_x_x538,kk_context()); /*bool*/
  if (_match_x331) {
    kk_string_t op_0;
    kk_box_t _x_x540;
    kk_box_t _x_x544;
    kk_string_t _x_x545 = kk_string_dup(line_0, _ctx); /*string*/
    _x_x544 = kk_string_box(_x_x545); /*10000*/
    _x_x540 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun541(_ctx), _x_x544, _ctx); /*10001*/
    op_0 = kk_string_unbox(_x_x540); /*string*/
    kk_string_t x_0_10078;
    if (kk_string_cmp_cstr_borrow(op_0, "emit", _ctx) == 0) {
      kk_gan__ying__event_type et;
      kk_box_t _x_x547;
      kk_box_t _x_x551;
      kk_string_t _x_x552 = kk_string_dup(line_0, _ctx); /*string*/
      _x_x551 = kk_string_box(_x_x552); /*10000*/
      _x_x547 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun548(_ctx), _x_x551, _ctx); /*10001*/
      et = kk_gan__ying__event_type_unbox(_x_x547, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_src_unified__runtime__v2__unified_state new_state;
      kk_box_t _x_x553;
      kk_box_t _x_x576;
      kk_string_t _x_x577;
      kk_define_string_literal(, _s_x578, 15, "unified_runtime", _ctx)
      _x_x577 = kk_string_dup(_s_x578, _ctx); /*string*/
      _x_x576 = kk_string_box(_x_x577); /*10001*/
      kk_box_t _x_x579;
      kk_src_unified__runtime__v2__unified_state _x_x580 = kk_src_unified__runtime__v2__unified_state_dup(state_0, _ctx); /*src/unified_runtime_v2/unified-state*/
      _x_x579 = kk_src_unified__runtime__v2__unified_state_box(_x_x580, _ctx); /*10002*/
      _x_x553 = kk_std_core_hnd__open_none3(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun554(_ctx), kk_gan__ying__event_type_box(et, _ctx), _x_x576, _x_x579, _ctx); /*10003*/
      new_state = kk_src_unified__runtime__v2__unified_state_unbox(_x_x553, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
      kk_string_t _x_x581;
      kk_define_string_literal(, _s_x582, 12, "{\"emitted\":\"", _ctx)
      _x_x581 = kk_string_dup(_s_x582, _ctx); /*string*/
      kk_string_t _x_x583;
      kk_string_t _x_x584;
      kk_box_t _x_x585 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun586(_ctx), kk_gan__ying__event_type_box(et, _ctx), _ctx); /*10001*/
      _x_x584 = kk_string_unbox(_x_x585); /*string*/
      kk_string_t _x_x589;
      kk_string_t _x_x590;
      kk_define_string_literal(, _s_x591, 10, "\",\"state\":", _ctx)
      _x_x590 = kk_string_dup(_s_x591, _ctx); /*string*/
      kk_string_t _x_x592;
      kk_string_t _x_x593;
      kk_box_t _x_x594 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun595(_ctx), kk_src_unified__runtime__v2__unified_state_box(new_state, _ctx), _ctx); /*10001*/
      _x_x593 = kk_string_unbox(_x_x594); /*string*/
      kk_string_t _x_x598;
      kk_define_string_literal(, _s_x599, 1, "}", _ctx)
      _x_x598 = kk_string_dup(_s_x599, _ctx); /*string*/
      _x_x592 = kk_std_core_types__lp__plus__plus__rp_(_x_x593, _x_x598, _ctx); /*string*/
      _x_x589 = kk_std_core_types__lp__plus__plus__rp_(_x_x590, _x_x592, _ctx); /*string*/
      _x_x583 = kk_std_core_types__lp__plus__plus__rp_(_x_x584, _x_x589, _ctx); /*string*/
      x_0_10078 = kk_std_core_types__lp__plus__plus__rp_(_x_x581, _x_x583, _ctx); /*string*/
      goto _match_x546;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "cascade", _ctx) == 0) {
      kk_gan__ying__event_type et_0_0;
      kk_box_t _x_x600;
      kk_box_t _x_x604;
      kk_string_t _x_x605 = kk_string_dup(line_0, _ctx); /*string*/
      _x_x604 = kk_string_box(_x_x605); /*10000*/
      _x_x600 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun601(_ctx), _x_x604, _ctx); /*10001*/
      et_0_0 = kk_gan__ying__event_type_unbox(_x_x600, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_std_core_types__tuple2 _match_x337;
      kk_box_t _x_x606;
      kk_box_t _x_x611;
      kk_src_unified__runtime__v2__unified_state _x_x612 = kk_src_unified__runtime__v2__unified_state_dup(state_0, _ctx); /*src/unified_runtime_v2/unified-state*/
      _x_x611 = kk_src_unified__runtime__v2__unified_state_box(_x_x612, _ctx); /*10001*/
      _x_x606 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun607(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _x_x611, _ctx); /*10002*/
      _match_x337 = kk_std_core_types__tuple2_unbox(_x_x606, KK_OWNED, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
      {
        kk_box_t _box_x113 = _match_x337.fst;
        kk_box_t _box_x114 = _match_x337.snd;
        kk_src_unified__runtime__v2__unified_state new_state_0 = kk_src_unified__runtime__v2__unified_state_unbox(_box_x114, KK_BORROWED, _ctx);
        struct kk_src_unified__runtime__v2_Unified_state* _con_x613 = kk_src_unified__runtime__v2__as_Unified_state(new_state_0, _ctx);
        kk_integer_t handlers = kk_integer_unbox(_box_x113, _ctx);
        kk_integer_dup(handlers, _ctx);
        kk_std_core_types__tuple2_drop(_match_x337, _ctx);
        kk_string_t _x_x614;
        kk_define_string_literal(, _s_x615, 12, "{\"cascade\":\"", _ctx)
        _x_x614 = kk_string_dup(_s_x615, _ctx); /*string*/
        kk_string_t _x_x616;
        kk_string_t _x_x617;
        kk_box_t _x_x618 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun619(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _ctx); /*10001*/
        _x_x617 = kk_string_unbox(_x_x618); /*string*/
        kk_string_t _x_x622;
        kk_string_t _x_x623;
        kk_define_string_literal(, _s_x624, 13, "\",\"handlers\":", _ctx)
        _x_x623 = kk_string_dup(_s_x624, _ctx); /*string*/
        kk_string_t _x_x625;
        kk_string_t _x_x626 = kk_std_core_int_show(handlers, _ctx); /*string*/
        kk_string_t _x_x627;
        kk_define_string_literal(, _s_x628, 1, "}", _ctx)
        _x_x627 = kk_string_dup(_s_x628, _ctx); /*string*/
        _x_x625 = kk_std_core_types__lp__plus__plus__rp_(_x_x626, _x_x627, _ctx); /*string*/
        _x_x622 = kk_std_core_types__lp__plus__plus__rp_(_x_x623, _x_x625, _ctx); /*string*/
        _x_x616 = kk_std_core_types__lp__plus__plus__rp_(_x_x617, _x_x622, _ctx); /*string*/
        x_0_10078 = kk_std_core_types__lp__plus__plus__rp_(_x_x614, _x_x616, _ctx); /*string*/
        goto _match_x546;
      }
    }
    if (kk_string_cmp_cstr_borrow(op_0, "profile", _ctx) == 0) {
      kk_std_core_types__list xs_10040;
      kk_box_t _x_x629;
      kk_box_t _x_x633;
      kk_src_unified__runtime__v2__unified_state _x_x634 = kk_src_unified__runtime__v2__unified_state_dup(state_0, _ctx); /*src/unified_runtime_v2/unified-state*/
      _x_x633 = kk_src_unified__runtime__v2__unified_state_box(_x_x634, _ctx); /*10000*/
      _x_x629 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun630(_ctx), _x_x633, _ctx); /*10001*/
      xs_10040 = kk_std_core_types__list_unbox(_x_x629, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
      kk_function_t _b_x124_159 = kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun635(_ctx); /*(src/unified_runtime_v2/unified-state) -> int*/;
      kk_src_unified__runtime__v2__unified_state _b_x125_160 = kk_src_unified__runtime__v2__unified_state_dup(state_0, _ctx); /*src/unified_runtime_v2/unified-state*/;
      kk_string_t _x_x637;
      kk_define_string_literal(, _s_x638, 12, "{\"profiles\":", _ctx)
      _x_x637 = kk_string_dup(_s_x638, _ctx); /*string*/
      kk_string_t _x_x639;
      kk_string_t _x_x640;
      kk_integer_t _x_x641 = kk_std_core_list__lift_length_5730(xs_10040, kk_integer_from_small(0), _ctx); /*int*/
      _x_x640 = kk_std_core_int_show(_x_x641, _ctx); /*string*/
      kk_string_t _x_x642;
      kk_string_t _x_x643;
      kk_define_string_literal(, _s_x644, 13, ",\"total_ops\":", _ctx)
      _x_x643 = kk_string_dup(_s_x644, _ctx); /*string*/
      kk_string_t _x_x645;
      kk_string_t _x_x646;
      kk_integer_t _x_x647;
      kk_box_t _x_x648 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun649(_b_x124_159, _ctx), kk_src_unified__runtime__v2__unified_state_box(_b_x125_160, _ctx), _ctx); /*10001*/
      _x_x647 = kk_integer_unbox(_x_x648, _ctx); /*int*/
      _x_x646 = kk_std_core_int_show(_x_x647, _ctx); /*string*/
      kk_string_t _x_x652;
      kk_define_string_literal(, _s_x653, 1, "}", _ctx)
      _x_x652 = kk_string_dup(_s_x653, _ctx); /*string*/
      _x_x645 = kk_std_core_types__lp__plus__plus__rp_(_x_x646, _x_x652, _ctx); /*string*/
      _x_x642 = kk_std_core_types__lp__plus__plus__rp_(_x_x643, _x_x645, _ctx); /*string*/
      _x_x639 = kk_std_core_types__lp__plus__plus__rp_(_x_x640, _x_x642, _ctx); /*string*/
      x_0_10078 = kk_std_core_types__lp__plus__plus__rp_(_x_x637, _x_x639, _ctx); /*string*/
      goto _match_x546;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_box_t _x_x654;
      kk_box_t _x_x658;
      kk_src_unified__runtime__v2__unified_state _x_x659 = kk_src_unified__runtime__v2__unified_state_dup(state_0, _ctx); /*src/unified_runtime_v2/unified-state*/
      _x_x658 = kk_src_unified__runtime__v2__unified_state_box(_x_x659, _ctx); /*10000*/
      _x_x654 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun655(_ctx), _x_x658, _ctx); /*10001*/
      x_0_10078 = kk_string_unbox(_x_x654); /*string*/
      goto _match_x546;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "hot", _ctx) == 0) {
      kk_std_core_types__list _b_x136_139;
      kk_box_t _x_x660;
      kk_box_t _x_x664;
      kk_src_unified__runtime__v2__unified_state _x_x665 = kk_src_unified__runtime__v2__unified_state_dup(state_0, _ctx); /*src/unified_runtime_v2/unified-state*/
      _x_x664 = kk_src_unified__runtime__v2__unified_state_box(_x_x665, _ctx); /*10000*/
      _x_x660 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun661(_ctx), _x_x664, _ctx); /*10001*/
      _b_x136_139 = kk_std_core_types__list_unbox(_x_x660, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
      kk_std_core_types__list x_1_10080 = kk_std_core_list_filter(_b_x136_139, kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun666(_ctx), _ctx); /*list<hot_paths/path-profile>*/;
      if (kk_yielding(kk_context())) {
        kk_std_core_types__list_drop(x_1_10080, _ctx);
        kk_box_t _x_x671 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun672(_ctx), _ctx); /*10001*/
        x_0_10078 = kk_string_unbox(_x_x671); /*string*/
        goto _match_x546;
      }
      {
        x_0_10078 = kk_src_unified__runtime__v2__mlift_server_loop_10073(x_1_10080, _ctx); /*string*/
        goto _match_x546;
      }
    }
    if (kk_string_cmp_cstr_borrow(op_0, "quit", _ctx) == 0) {
      kk_define_string_literal(, _s_x675, 20, "{\"status\":\"stopped\"}", _ctx)
      x_0_10078 = kk_string_dup(_s_x675, _ctx); /*string*/
      goto _match_x546;
    }
    {
      kk_define_string_literal(, _s_x676, 22, "{\"error\":\"unknown op\"}", _ctx)
      x_0_10078 = kk_string_dup(_s_x676, _ctx); /*string*/
    }
    _match_x546: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10078, _ctx);
      kk_box_t _x_x677 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2__new_mlift_server_loop_10075_fun678(line_0, op_0, state_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x677); return kk_Unit;
    }
    {
      kk_src_unified__runtime__v2__mlift_server_loop_10074(line_0, op_0, state_0, x_0_10078, _ctx); return kk_Unit;
    }
  }
  {
    kk_datatype_ptr_dropn(state_0, (KK_I32(3)), _ctx);
    kk_string_drop(line_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun681__t {
  struct kk_function_s _base;
  kk_src_unified__runtime__v2__unified_state state_2;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun681(kk_function_t _fself, kk_box_t _b_x169, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun681(kk_src_unified__runtime__v2__unified_state state_2, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2_server_loop_fun681__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v2_server_loop_fun681__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v2_server_loop_fun681, kk_context());
  _self->state_2 = state_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun681(kk_function_t _fself, kk_box_t _b_x169, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2_server_loop_fun681__t* _self = kk_function_as(struct kk_src_unified__runtime__v2_server_loop_fun681__t*, _fself, _ctx);
  kk_src_unified__runtime__v2__unified_state state_2 = _self->state_2; /* src/unified_runtime_v2/unified-state */
  kk_drop_match(_self, {kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx);}, {}, _ctx)
  kk_string_t line_1_318 = kk_string_unbox(_b_x169); /*string*/;
  kk_unit_t _x_x682 = kk_Unit;
  kk_src_unified__runtime__v2__mlift_server_loop_10075(state_2, line_1_318, _ctx);
  return kk_unit_box(_x_x682);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun687__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun687(kk_function_t _fself, kk_box_t _b_x172, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun687(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun687, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun687(kk_function_t _fself, kk_box_t _b_x172, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x688;
  kk_string_t _x_x689 = kk_string_unbox(_b_x172); /*string*/
  _x_x688 = kk_src_unified__runtime__v2_extract_op(_x_x689, _ctx); /*string*/
  return kk_string_box(_x_x688);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun694__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun694(kk_function_t _fself, kk_box_t _b_x177, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun694(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun694, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun694(kk_function_t _fself, kk_box_t _b_x177, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x695;
  kk_string_t _x_x696 = kk_string_unbox(_b_x177); /*string*/
  _x_x695 = kk_src_unified__runtime__v2_extract_event_type(_x_x696, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x695, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun700__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun700(kk_function_t _fself, kk_box_t _b_x188, kk_box_t _b_x189, kk_box_t _b_x190, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun700(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun700, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun700(kk_function_t _fself, kk_box_t _b_x188, kk_box_t _b_x189, kk_box_t _b_x190, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__v2__unified_state state_0_1_201 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x190, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/;
  kk_hot__paths__path_profile profile_1;
  kk_string_t _x_x701;
  kk_gan__ying__event_type _x_x702;
  kk_box_t _x_x703 = kk_box_dup(_b_x188, _ctx); /*10000*/
  _x_x702 = kk_gan__ying__event_type_unbox(_x_x703, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x701 = kk_gan__ying_event_type_to_string(_x_x702, _ctx); /*string*/
  profile_1 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x701, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_src_unified__runtime__v2__unified_state _x_x704;
  kk_std_core_types__list _x_x705;
  kk_box_t _x_x706;
  kk_gan__ying__resonance_event _x_x707;
  kk_string_t _x_x708 = kk_string_unbox(_b_x189); /*string*/
  kk_gan__ying__event_type _x_x709 = kk_gan__ying__event_type_unbox(_b_x188, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_string_t _x_x710 = kk_string_empty(); /*string*/
  _x_x707 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x708, _x_x709, _x_x710, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x706 = kk_gan__ying__resonance_event_box(_x_x707, _ctx); /*10021*/
  kk_std_core_types__list _x_x712;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x713 = kk_src_unified__runtime__v2__as_Unified_state(state_0_1_201, _ctx);
    kk_std_core_types__list _x_5 = _con_x713->events;
    kk_std_core_types__list_dup(_x_5, _ctx);
    _x_x712 = _x_5; /*list<gan_ying/resonance-event>*/
  }
  _x_x705 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x706, _x_x712, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x714;
  kk_std_core_types__list _x_x715;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x716 = kk_src_unified__runtime__v2__as_Unified_state(state_0_1_201, _ctx);
    kk_std_core_types__list _x_0_2 = _con_x716->profiles;
    kk_std_core_types__list_dup(_x_0_2, _ctx);
    _x_x715 = _x_0_2; /*list<hot_paths/path-profile>*/
  }
  _x_x714 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_1, _ctx), _x_x715, _ctx); /*list<10021>*/
  kk_integer_t _x_x717;
  kk_integer_t _x_x718;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x719 = kk_src_unified__runtime__v2__as_Unified_state(state_0_1_201, _ctx);
    kk_integer_t _x_1_2 = _con_x719->total_ops;
    kk_integer_dup(_x_1_2, _ctx);
    _x_x718 = _x_1_2; /*int*/
  }
  _x_x717 = kk_integer_add_small_const(_x_x718, 1, _ctx); /*int*/
  double _x_x720;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x721 = kk_src_unified__runtime__v2__as_Unified_state(state_0_1_201, _ctx);
    kk_std_core_types__list _pat_0_2_2 = _con_x721->events;
    kk_std_core_types__list _pat_1_2_2 = _con_x721->profiles;
    kk_integer_t _pat_2_2_2 = _con_x721->total_ops;
    double _x_2_2 = _con_x721->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state_0_1_201, _ctx)) {
      kk_integer_drop(_pat_2_2_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_2_2, _ctx);
      kk_std_core_types__list_drop(_pat_0_2_2, _ctx);
      kk_datatype_ptr_free(state_0_1_201, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state_0_1_201, _ctx);
    }
    _x_x720 = _x_2_2; /*float64*/
  }
  _x_x704 = kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x705, _x_x714, _x_x717, _x_x720, _ctx); /*src/unified_runtime_v2/unified-state*/
  return kk_src_unified__runtime__v2__unified_state_box(_x_x704, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun732__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun732(kk_function_t _fself, kk_box_t _b_x204, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun732(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun732, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun732(kk_function_t _fself, kk_box_t _b_x204, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x733;
  kk_gan__ying__event_type _x_x734 = kk_gan__ying__event_type_unbox(_b_x204, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x733 = kk_gan__ying_event_type_to_string(_x_x734, _ctx); /*string*/
  return kk_string_box(_x_x733);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun741__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun741(kk_function_t _fself, kk_box_t _b_x207, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun741(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun741, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun741(kk_function_t _fself, kk_box_t _b_x207, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x742;
  kk_src_unified__runtime__v2__unified_state _x_x743 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x207, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x742 = kk_src_unified__runtime__v2_json_state(_x_x743, _ctx); /*string*/
  return kk_string_box(_x_x742);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun747__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun747(kk_function_t _fself, kk_box_t _b_x210, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun747(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun747, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun747(kk_function_t _fself, kk_box_t _b_x210, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x748;
  kk_string_t _x_x749 = kk_string_unbox(_b_x210); /*string*/
  _x_x748 = kk_src_unified__runtime__v2_extract_event_type(_x_x749, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x748, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun753__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun753(kk_function_t _fself, kk_box_t _b_x216, kk_box_t _b_x217, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun753(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun753, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun753(kk_function_t _fself, kk_box_t _b_x216, kk_box_t _b_x217, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x754;
  kk_gan__ying__event_type _x_x755 = kk_gan__ying__event_type_unbox(_b_x216, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v2__unified_state _x_x756 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x217, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x754 = kk_src_unified__runtime__v2_cascade_profiled(_x_x755, _x_x756, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x754, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun765__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun765(kk_function_t _fself, kk_box_t _b_x222, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun765(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun765, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun765(kk_function_t _fself, kk_box_t _b_x222, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x766;
  kk_gan__ying__event_type _x_x767 = kk_gan__ying__event_type_unbox(_b_x222, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x766 = kk_gan__ying_event_type_to_string(_x_x767, _ctx); /*string*/
  return kk_string_box(_x_x766);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun776__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun776(kk_function_t _fself, kk_box_t _b_x225, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun776(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun776, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun776(kk_function_t _fself, kk_box_t _b_x225, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x777;
  kk_src_unified__runtime__v2__unified_state _match_x329 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x225, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x778 = kk_src_unified__runtime__v2__as_Unified_state(_match_x329, _ctx);
    kk_std_core_types__list _pat_0_0_1_0 = _con_x778->events;
    kk_std_core_types__list _x_3_0 = _con_x778->profiles;
    kk_integer_t _pat_1_0_1_0 = _con_x778->total_ops;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x329, _ctx)) {
      kk_integer_drop(_pat_1_0_1_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_0_1_0, _ctx);
      kk_datatype_ptr_free(_match_x329, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_3_0, _ctx);
      kk_datatype_ptr_decref(_match_x329, _ctx);
    }
    _x_x777 = _x_3_0; /*list<hot_paths/path-profile>*/
  }
  return kk_std_core_types__list_box(_x_x777, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun781__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_src_unified__runtime__v2_server_loop_fun781(kk_function_t _fself, kk_src_unified__runtime__v2__unified_state _this_0_0, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun781(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun781, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_src_unified__runtime__v2_server_loop_fun781(kk_function_t _fself, kk_src_unified__runtime__v2__unified_state _this_0_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x782 = kk_src_unified__runtime__v2__as_Unified_state(_this_0_0, _ctx);
    kk_std_core_types__list _pat_0_1_0_1 = _con_x782->events;
    kk_std_core_types__list _pat_1_1_0_0 = _con_x782->profiles;
    kk_integer_t _x_0_0_0 = _con_x782->total_ops;
    if kk_likely(kk_datatype_ptr_is_unique(_this_0_0, _ctx)) {
      kk_std_core_types__list_drop(_pat_1_1_0_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_1_0_1, _ctx);
      kk_datatype_ptr_free(_this_0_0, _ctx);
    }
    else {
      kk_integer_dup(_x_0_0_0, _ctx);
      kk_datatype_ptr_decref(_this_0_0, _ctx);
    }
    return _x_0_0_0;
  }
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun795__t {
  struct kk_function_s _base;
  kk_function_t _b_x229_264;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun795(kk_function_t _fself, kk_box_t _b_x231, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun795(kk_function_t _b_x229_264, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2_server_loop_fun795__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v2_server_loop_fun795__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v2_server_loop_fun795, kk_context());
  _self->_b_x229_264 = _b_x229_264;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun795(kk_function_t _fself, kk_box_t _b_x231, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2_server_loop_fun795__t* _self = kk_function_as(struct kk_src_unified__runtime__v2_server_loop_fun795__t*, _fself, _ctx);
  kk_function_t _b_x229_264 = _self->_b_x229_264; /* (src/unified_runtime_v2/unified-state) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x229_264, _ctx);}, {}, _ctx)
  kk_integer_t _x_x796;
  kk_src_unified__runtime__v2__unified_state _x_x797 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x231, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x796 = kk_function_call(kk_integer_t, (kk_function_t, kk_src_unified__runtime__v2__unified_state, kk_context_t*), _b_x229_264, (_b_x229_264, _x_x797, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x796, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun801__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun801(kk_function_t _fself, kk_box_t _b_x234, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun801(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun801, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun801(kk_function_t _fself, kk_box_t _b_x234, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x802;
  kk_src_unified__runtime__v2__unified_state _x_x803 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x234, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x802 = kk_src_unified__runtime__v2_json_state(_x_x803, _ctx); /*string*/
  return kk_string_box(_x_x802);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun807__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun807(kk_function_t _fself, kk_box_t _b_x237, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun807(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun807, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun807(kk_function_t _fself, kk_box_t _b_x237, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x808;
  kk_src_unified__runtime__v2__unified_state _match_x328 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x237, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x809 = kk_src_unified__runtime__v2__as_Unified_state(_match_x328, _ctx);
    kk_std_core_types__list _pat_0_2_0_0 = _con_x809->events;
    kk_std_core_types__list _x_1_0_0 = _con_x809->profiles;
    kk_integer_t _pat_1_2_0_0 = _con_x809->total_ops;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x328, _ctx)) {
      kk_integer_drop(_pat_1_2_0_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_2_0_0, _ctx);
      kk_datatype_ptr_free(_match_x328, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_1_0_0, _ctx);
      kk_datatype_ptr_decref(_match_x328, _ctx);
    }
    _x_x808 = _x_1_0_0; /*list<hot_paths/path-profile>*/
  }
  return kk_std_core_types__list_box(_x_x808, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun812__t {
  struct kk_function_s _base;
};
static bool kk_src_unified__runtime__v2_server_loop_fun812(kk_function_t _fself, kk_box_t _b_x243, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun812(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun812, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun814__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun814(kk_function_t _fself, kk_box_t _b_x240, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun814(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun814, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun814(kk_function_t _fself, kk_box_t _b_x240, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x815;
  kk_hot__paths__path_profile _match_x327 = kk_hot__paths__path_profile_unbox(_b_x240, KK_OWNED, _ctx); /*hot_paths/path-profile*/;
  {
    struct kk_hot__paths_Path_profile* _con_x816 = kk_hot__paths__as_Path_profile(_match_x327, _ctx);
    kk_string_t _pat_0_3_1 = _con_x816->name;
    kk_integer_t _pat_1_3_0_0 = _con_x816->call_count;
    kk_hot__paths__complexity _x_2_0_0 = _con_x816->complexity;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x327, _ctx)) {
      kk_integer_drop(_pat_1_3_0_0, _ctx);
      kk_string_drop(_pat_0_3_1, _ctx);
      kk_datatype_ptr_free(_match_x327, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x327, _ctx);
    }
    if (kk_hot__paths__is_High(_x_2_0_0, _ctx)) {
      _x_x815 = true; /*bool*/
    }
    else {
      _x_x815 = false; /*bool*/
    }
  }
  return kk_bool_box(_x_x815);
}
static bool kk_src_unified__runtime__v2_server_loop_fun812(kk_function_t _fself, kk_box_t _b_x243, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x813 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun814(_ctx), _b_x243, _ctx); /*10001*/
  return kk_bool_unbox(_x_x813);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun818__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun818(kk_function_t _fself, kk_box_t _b_x254, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun818(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun818, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun818(kk_function_t _fself, kk_box_t _b_x254, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x819;
  kk_std_core_types__list _x_x820 = kk_std_core_types__list_unbox(_b_x254, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
  _x_x819 = kk_src_unified__runtime__v2__mlift_server_loop_10073(_x_x820, _ctx); /*string*/
  return kk_string_box(_x_x819);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun824__t {
  struct kk_function_s _base;
  kk_string_t op_1;
  kk_src_unified__runtime__v2__unified_state state_2;
  kk_string_t x_2_10082;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun824(kk_function_t _fself, kk_box_t _b_x270, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun824(kk_string_t op_1, kk_src_unified__runtime__v2__unified_state state_2, kk_string_t x_2_10082, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2_server_loop_fun824__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v2_server_loop_fun824__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v2_server_loop_fun824, kk_context());
  _self->op_1 = op_1;
  _self->state_2 = state_2;
  _self->x_2_10082 = x_2_10082;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun824(kk_function_t _fself, kk_box_t _b_x270, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2_server_loop_fun824__t* _self = kk_function_as(struct kk_src_unified__runtime__v2_server_loop_fun824__t*, _fself, _ctx);
  kk_string_t op_1 = _self->op_1; /* string */
  kk_src_unified__runtime__v2__unified_state state_2 = _self->state_2; /* src/unified_runtime_v2/unified-state */
  kk_string_t x_2_10082 = _self->x_2_10082; /* string */
  kk_drop_match(_self, {kk_string_dup(op_1, _ctx);kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx);kk_string_dup(x_2_10082, _ctx);}, {}, _ctx)
  kk_string_t _c_x10026_1_319 = kk_string_unbox(_b_x270); /*string*/;
  kk_unit_t _x_x825 = kk_Unit;
  kk_src_unified__runtime__v2__mlift_server_loop_10074(x_2_10082, op_1, state_2, _c_x10026_1_319, _ctx);
  return kk_unit_box(_x_x825);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun831__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun831(kk_function_t _fself, kk_box_t _b_x273, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun831(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun831, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun831(kk_function_t _fself, kk_box_t _b_x273, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x832;
  kk_string_t _x_x833 = kk_string_unbox(_b_x273); /*string*/
  _x_x832 = kk_src_unified__runtime__v2_extract_event_type(_x_x833, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x832, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun835__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun835(kk_function_t _fself, kk_box_t _b_x284, kk_box_t _b_x285, kk_box_t _b_x286, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun835(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun835, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun835(kk_function_t _fself, kk_box_t _b_x284, kk_box_t _b_x285, kk_box_t _b_x286, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_unified__runtime__v2__unified_state state_1_0_312 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x286, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/;
  kk_hot__paths__path_profile profile_0_0;
  kk_string_t _x_x836;
  kk_gan__ying__event_type _x_x837;
  kk_box_t _x_x838 = kk_box_dup(_b_x284, _ctx); /*10000*/
  _x_x837 = kk_gan__ying__event_type_unbox(_x_x838, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x836 = kk_gan__ying_event_type_to_string(_x_x837, _ctx); /*string*/
  profile_0_0 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x836, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_src_unified__runtime__v2__unified_state _x_x839;
  kk_std_core_types__list _x_x840;
  kk_box_t _x_x841;
  kk_gan__ying__resonance_event _x_x842;
  kk_string_t _x_x843 = kk_string_unbox(_b_x285); /*string*/
  kk_gan__ying__event_type _x_x844 = kk_gan__ying__event_type_unbox(_b_x284, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_string_t _x_x845 = kk_string_empty(); /*string*/
  _x_x842 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x843, _x_x844, _x_x845, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x841 = kk_gan__ying__resonance_event_box(_x_x842, _ctx); /*10021*/
  kk_std_core_types__list _x_x847;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x848 = kk_src_unified__runtime__v2__as_Unified_state(state_1_0_312, _ctx);
    kk_std_core_types__list _x_4_0 = _con_x848->events;
    kk_std_core_types__list_dup(_x_4_0, _ctx);
    _x_x847 = _x_4_0; /*list<gan_ying/resonance-event>*/
  }
  _x_x840 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x841, _x_x847, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x849;
  kk_std_core_types__list _x_x850;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x851 = kk_src_unified__runtime__v2__as_Unified_state(state_1_0_312, _ctx);
    kk_std_core_types__list _x_0_1_0 = _con_x851->profiles;
    kk_std_core_types__list_dup(_x_0_1_0, _ctx);
    _x_x850 = _x_0_1_0; /*list<hot_paths/path-profile>*/
  }
  _x_x849 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_0_0, _ctx), _x_x850, _ctx); /*list<10021>*/
  kk_integer_t _x_x852;
  kk_integer_t _x_x853;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x854 = kk_src_unified__runtime__v2__as_Unified_state(state_1_0_312, _ctx);
    kk_integer_t _x_1_1_0 = _con_x854->total_ops;
    kk_integer_dup(_x_1_1_0, _ctx);
    _x_x853 = _x_1_1_0; /*int*/
  }
  _x_x852 = kk_integer_add_small_const(_x_x853, 1, _ctx); /*int*/
  double _x_x855;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x856 = kk_src_unified__runtime__v2__as_Unified_state(state_1_0_312, _ctx);
    kk_std_core_types__list _pat_0_2_1_0 = _con_x856->events;
    kk_std_core_types__list _pat_1_2_1_0 = _con_x856->profiles;
    kk_integer_t _pat_2_2_1_0 = _con_x856->total_ops;
    double _x_2_1_0 = _con_x856->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state_1_0_312, _ctx)) {
      kk_integer_drop(_pat_2_2_1_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_2_1_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_2_1_0, _ctx);
      kk_datatype_ptr_free(state_1_0_312, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state_1_0_312, _ctx);
    }
    _x_x855 = _x_2_1_0; /*float64*/
  }
  _x_x839 = kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x840, _x_x849, _x_x852, _x_x855, _ctx); /*src/unified_runtime_v2/unified-state*/
  return kk_src_unified__runtime__v2__unified_state_box(_x_x839, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun861__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun861(kk_function_t _fself, kk_box_t _b_x289, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun861(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun861, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun861(kk_function_t _fself, kk_box_t _b_x289, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x862;
  kk_string_t _x_x863 = kk_string_unbox(_b_x289); /*string*/
  _x_x862 = kk_src_unified__runtime__v2_extract_event_type(_x_x863, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x862, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun865__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun865(kk_function_t _fself, kk_box_t _b_x295, kk_box_t _b_x296, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun865(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun865, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun865(kk_function_t _fself, kk_box_t _b_x295, kk_box_t _b_x296, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x866;
  kk_gan__ying__event_type _x_x867 = kk_gan__ying__event_type_unbox(_b_x295, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v2__unified_state _x_x868 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x296, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x866 = kk_src_unified__runtime__v2_cascade_profiled(_x_x867, _x_x868, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x866, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun871__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun871(kk_function_t _fself, kk_box_t _b_x314, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun871(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun871, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun871(kk_function_t _fself, kk_box_t _b_x314, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x872 = kk_Unit;
  kk_src_unified__runtime__v2__unified_state _x_x873 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x314, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  kk_src_unified__runtime__v2_server_loop(_x_x873, _ctx);
  return kk_unit_box(_x_x872);
}

kk_unit_t kk_src_unified__runtime__v2_server_loop(kk_src_unified__runtime__v2__unified_state state_2, kk_context_t* _ctx) { /* (state : unified-state) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_2_10082 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2_10082, _ctx);
    kk_box_t _x_x680 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2_new_server_loop_fun681(state_2, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x680); return kk_Unit;
  }
  {
    bool _match_x321;
    kk_string_t _x_x683 = kk_string_dup(x_2_10082, _ctx); /*string*/
    kk_string_t _x_x684 = kk_string_empty(); /*string*/
    _match_x321 = kk_string_is_neq(_x_x683,_x_x684,kk_context()); /*bool*/
    if (_match_x321) {
      kk_string_t op_1;
      kk_box_t _x_x686;
      kk_box_t _x_x690;
      kk_string_t _x_x691 = kk_string_dup(x_2_10082, _ctx); /*string*/
      _x_x690 = kk_string_box(_x_x691); /*10000*/
      _x_x686 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun687(_ctx), _x_x690, _ctx); /*10001*/
      op_1 = kk_string_unbox(_x_x686); /*string*/
      kk_string_t x_3_10085;
      if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
        kk_gan__ying__event_type et_3;
        kk_box_t _x_x693;
        kk_box_t _x_x697;
        kk_string_t _x_x698 = kk_string_dup(x_2_10082, _ctx); /*string*/
        _x_x697 = kk_string_box(_x_x698); /*10000*/
        _x_x693 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun694(_ctx), _x_x697, _ctx); /*10001*/
        et_3 = kk_gan__ying__event_type_unbox(_x_x693, KK_OWNED, _ctx); /*gan_ying/event-type*/
        kk_src_unified__runtime__v2__unified_state new_state_1;
        kk_box_t _x_x699;
        kk_box_t _x_x722;
        kk_string_t _x_x723;
        kk_define_string_literal(, _s_x724, 15, "unified_runtime", _ctx)
        _x_x723 = kk_string_dup(_s_x724, _ctx); /*string*/
        _x_x722 = kk_string_box(_x_x723); /*10001*/
        kk_box_t _x_x725;
        kk_src_unified__runtime__v2__unified_state _x_x726 = kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx); /*src/unified_runtime_v2/unified-state*/
        _x_x725 = kk_src_unified__runtime__v2__unified_state_box(_x_x726, _ctx); /*10002*/
        _x_x699 = kk_std_core_hnd__open_none3(kk_src_unified__runtime__v2_new_server_loop_fun700(_ctx), kk_gan__ying__event_type_box(et_3, _ctx), _x_x722, _x_x725, _ctx); /*10003*/
        new_state_1 = kk_src_unified__runtime__v2__unified_state_unbox(_x_x699, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
        kk_string_t _x_x727;
        kk_define_string_literal(, _s_x728, 12, "{\"emitted\":\"", _ctx)
        _x_x727 = kk_string_dup(_s_x728, _ctx); /*string*/
        kk_string_t _x_x729;
        kk_string_t _x_x730;
        kk_box_t _x_x731 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun732(_ctx), kk_gan__ying__event_type_box(et_3, _ctx), _ctx); /*10001*/
        _x_x730 = kk_string_unbox(_x_x731); /*string*/
        kk_string_t _x_x735;
        kk_string_t _x_x736;
        kk_define_string_literal(, _s_x737, 10, "\",\"state\":", _ctx)
        _x_x736 = kk_string_dup(_s_x737, _ctx); /*string*/
        kk_string_t _x_x738;
        kk_string_t _x_x739;
        kk_box_t _x_x740 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun741(_ctx), kk_src_unified__runtime__v2__unified_state_box(new_state_1, _ctx), _ctx); /*10001*/
        _x_x739 = kk_string_unbox(_x_x740); /*string*/
        kk_string_t _x_x744;
        kk_define_string_literal(, _s_x745, 1, "}", _ctx)
        _x_x744 = kk_string_dup(_s_x745, _ctx); /*string*/
        _x_x738 = kk_std_core_types__lp__plus__plus__rp_(_x_x739, _x_x744, _ctx); /*string*/
        _x_x735 = kk_std_core_types__lp__plus__plus__rp_(_x_x736, _x_x738, _ctx); /*string*/
        _x_x729 = kk_std_core_types__lp__plus__plus__rp_(_x_x730, _x_x735, _ctx); /*string*/
        x_3_10085 = kk_std_core_types__lp__plus__plus__rp_(_x_x727, _x_x729, _ctx); /*string*/
        goto _match_x692;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
        kk_gan__ying__event_type et_0_0_0;
        kk_box_t _x_x746;
        kk_box_t _x_x750;
        kk_string_t _x_x751 = kk_string_dup(x_2_10082, _ctx); /*string*/
        _x_x750 = kk_string_box(_x_x751); /*10000*/
        _x_x746 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun747(_ctx), _x_x750, _ctx); /*10001*/
        et_0_0_0 = kk_gan__ying__event_type_unbox(_x_x746, KK_OWNED, _ctx); /*gan_ying/event-type*/
        kk_std_core_types__tuple2 _match_x330;
        kk_box_t _x_x752;
        kk_box_t _x_x757;
        kk_src_unified__runtime__v2__unified_state _x_x758 = kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx); /*src/unified_runtime_v2/unified-state*/
        _x_x757 = kk_src_unified__runtime__v2__unified_state_box(_x_x758, _ctx); /*10001*/
        _x_x752 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v2_new_server_loop_fun753(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _x_x757, _ctx); /*10002*/
        _match_x330 = kk_std_core_types__tuple2_unbox(_x_x752, KK_OWNED, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
        {
          kk_box_t _box_x218 = _match_x330.fst;
          kk_box_t _box_x219 = _match_x330.snd;
          kk_src_unified__runtime__v2__unified_state new_state_0_0 = kk_src_unified__runtime__v2__unified_state_unbox(_box_x219, KK_BORROWED, _ctx);
          struct kk_src_unified__runtime__v2_Unified_state* _con_x759 = kk_src_unified__runtime__v2__as_Unified_state(new_state_0_0, _ctx);
          kk_integer_t handlers_0 = kk_integer_unbox(_box_x218, _ctx);
          kk_integer_dup(handlers_0, _ctx);
          kk_std_core_types__tuple2_drop(_match_x330, _ctx);
          kk_string_t _x_x760;
          kk_define_string_literal(, _s_x761, 12, "{\"cascade\":\"", _ctx)
          _x_x760 = kk_string_dup(_s_x761, _ctx); /*string*/
          kk_string_t _x_x762;
          kk_string_t _x_x763;
          kk_box_t _x_x764 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun765(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _ctx); /*10001*/
          _x_x763 = kk_string_unbox(_x_x764); /*string*/
          kk_string_t _x_x768;
          kk_string_t _x_x769;
          kk_define_string_literal(, _s_x770, 13, "\",\"handlers\":", _ctx)
          _x_x769 = kk_string_dup(_s_x770, _ctx); /*string*/
          kk_string_t _x_x771;
          kk_string_t _x_x772 = kk_std_core_int_show(handlers_0, _ctx); /*string*/
          kk_string_t _x_x773;
          kk_define_string_literal(, _s_x774, 1, "}", _ctx)
          _x_x773 = kk_string_dup(_s_x774, _ctx); /*string*/
          _x_x771 = kk_std_core_types__lp__plus__plus__rp_(_x_x772, _x_x773, _ctx); /*string*/
          _x_x768 = kk_std_core_types__lp__plus__plus__rp_(_x_x769, _x_x771, _ctx); /*string*/
          _x_x762 = kk_std_core_types__lp__plus__plus__rp_(_x_x763, _x_x768, _ctx); /*string*/
          x_3_10085 = kk_std_core_types__lp__plus__plus__rp_(_x_x760, _x_x762, _ctx); /*string*/
          goto _match_x692;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_1, "profile", _ctx) == 0) {
        kk_std_core_types__list xs_10040_0;
        kk_box_t _x_x775;
        kk_box_t _x_x779;
        kk_src_unified__runtime__v2__unified_state _x_x780 = kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx); /*src/unified_runtime_v2/unified-state*/
        _x_x779 = kk_src_unified__runtime__v2__unified_state_box(_x_x780, _ctx); /*10000*/
        _x_x775 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun776(_ctx), _x_x779, _ctx); /*10001*/
        xs_10040_0 = kk_std_core_types__list_unbox(_x_x775, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
        kk_function_t _b_x229_264 = kk_src_unified__runtime__v2_new_server_loop_fun781(_ctx); /*(src/unified_runtime_v2/unified-state) -> int*/;
        kk_src_unified__runtime__v2__unified_state _b_x230_265 = kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx); /*src/unified_runtime_v2/unified-state*/;
        kk_string_t _x_x783;
        kk_define_string_literal(, _s_x784, 12, "{\"profiles\":", _ctx)
        _x_x783 = kk_string_dup(_s_x784, _ctx); /*string*/
        kk_string_t _x_x785;
        kk_string_t _x_x786;
        kk_integer_t _x_x787 = kk_std_core_list__lift_length_5730(xs_10040_0, kk_integer_from_small(0), _ctx); /*int*/
        _x_x786 = kk_std_core_int_show(_x_x787, _ctx); /*string*/
        kk_string_t _x_x788;
        kk_string_t _x_x789;
        kk_define_string_literal(, _s_x790, 13, ",\"total_ops\":", _ctx)
        _x_x789 = kk_string_dup(_s_x790, _ctx); /*string*/
        kk_string_t _x_x791;
        kk_string_t _x_x792;
        kk_integer_t _x_x793;
        kk_box_t _x_x794 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun795(_b_x229_264, _ctx), kk_src_unified__runtime__v2__unified_state_box(_b_x230_265, _ctx), _ctx); /*10001*/
        _x_x793 = kk_integer_unbox(_x_x794, _ctx); /*int*/
        _x_x792 = kk_std_core_int_show(_x_x793, _ctx); /*string*/
        kk_string_t _x_x798;
        kk_define_string_literal(, _s_x799, 1, "}", _ctx)
        _x_x798 = kk_string_dup(_s_x799, _ctx); /*string*/
        _x_x791 = kk_std_core_types__lp__plus__plus__rp_(_x_x792, _x_x798, _ctx); /*string*/
        _x_x788 = kk_std_core_types__lp__plus__plus__rp_(_x_x789, _x_x791, _ctx); /*string*/
        _x_x785 = kk_std_core_types__lp__plus__plus__rp_(_x_x786, _x_x788, _ctx); /*string*/
        x_3_10085 = kk_std_core_types__lp__plus__plus__rp_(_x_x783, _x_x785, _ctx); /*string*/
        goto _match_x692;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
        kk_box_t _x_x800;
        kk_box_t _x_x804;
        kk_src_unified__runtime__v2__unified_state _x_x805 = kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx); /*src/unified_runtime_v2/unified-state*/
        _x_x804 = kk_src_unified__runtime__v2__unified_state_box(_x_x805, _ctx); /*10000*/
        _x_x800 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun801(_ctx), _x_x804, _ctx); /*10001*/
        x_3_10085 = kk_string_unbox(_x_x800); /*string*/
        goto _match_x692;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "hot", _ctx) == 0) {
        kk_std_core_types__list _b_x241_244;
        kk_box_t _x_x806;
        kk_box_t _x_x810;
        kk_src_unified__runtime__v2__unified_state _x_x811 = kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx); /*src/unified_runtime_v2/unified-state*/
        _x_x810 = kk_src_unified__runtime__v2__unified_state_box(_x_x811, _ctx); /*10000*/
        _x_x806 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun807(_ctx), _x_x810, _ctx); /*10001*/
        _b_x241_244 = kk_std_core_types__list_unbox(_x_x806, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
        kk_std_core_types__list x_4_10088 = kk_std_core_list_filter(_b_x241_244, kk_src_unified__runtime__v2_new_server_loop_fun812(_ctx), _ctx); /*list<hot_paths/path-profile>*/;
        if (kk_yielding(kk_context())) {
          kk_std_core_types__list_drop(x_4_10088, _ctx);
          kk_box_t _x_x817 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2_new_server_loop_fun818(_ctx), _ctx); /*10001*/
          x_3_10085 = kk_string_unbox(_x_x817); /*string*/
          goto _match_x692;
        }
        {
          x_3_10085 = kk_src_unified__runtime__v2__mlift_server_loop_10073(x_4_10088, _ctx); /*string*/
          goto _match_x692;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_1, "quit", _ctx) == 0) {
        kk_define_string_literal(, _s_x821, 20, "{\"status\":\"stopped\"}", _ctx)
        x_3_10085 = kk_string_dup(_s_x821, _ctx); /*string*/
        goto _match_x692;
      }
      {
        kk_define_string_literal(, _s_x822, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_3_10085 = kk_string_dup(_s_x822, _ctx); /*string*/
      }
      _match_x692: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_3_10085, _ctx);
        kk_box_t _x_x823 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2_new_server_loop_fun824(op_1, state_2, x_2_10082, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x823); return kk_Unit;
      }
      {
        kk_unit_t ___0 = kk_Unit;
        kk_std_core_console_printsln(x_3_10085, _ctx);
        bool _match_x323;
        kk_string_t _x_x826 = kk_string_dup(op_1, _ctx); /*string*/
        kk_string_t _x_x827;
        kk_define_string_literal(, _s_x828, 4, "quit", _ctx)
        _x_x827 = kk_string_dup(_s_x828, _ctx); /*string*/
        _match_x323 = kk_string_is_neq(_x_x826,_x_x827,kk_context()); /*bool*/
        if (_match_x323) {
          kk_src_unified__runtime__v2__unified_state x_5_10090;
          if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_gan__ying__event_type et_1_0;
            kk_box_t _x_x830 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun831(_ctx), kk_string_box(x_2_10082), _ctx); /*10001*/
            et_1_0 = kk_gan__ying__event_type_unbox(_x_x830, KK_OWNED, _ctx); /*gan_ying/event-type*/
            kk_box_t _x_x834;
            kk_box_t _x_x857;
            kk_string_t _x_x858;
            kk_define_string_literal(, _s_x859, 15, "unified_runtime", _ctx)
            _x_x858 = kk_string_dup(_s_x859, _ctx); /*string*/
            _x_x857 = kk_string_box(_x_x858); /*10001*/
            _x_x834 = kk_std_core_hnd__open_none3(kk_src_unified__runtime__v2_new_server_loop_fun835(_ctx), kk_gan__ying__event_type_box(et_1_0, _ctx), _x_x857, kk_src_unified__runtime__v2__unified_state_box(state_2, _ctx), _ctx); /*10003*/
            x_5_10090 = kk_src_unified__runtime__v2__unified_state_unbox(_x_x834, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
            goto _match_x829;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_gan__ying__event_type et_2_0_0;
            kk_box_t _x_x860 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun861(_ctx), kk_string_box(x_2_10082), _ctx); /*10001*/
            et_2_0_0 = kk_gan__ying__event_type_unbox(_x_x860, KK_OWNED, _ctx); /*gan_ying/event-type*/
            kk_std_core_types__tuple2 _match_x325;
            kk_box_t _x_x864 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v2_new_server_loop_fun865(_ctx), kk_gan__ying__event_type_box(et_2_0_0, _ctx), kk_src_unified__runtime__v2__unified_state_box(state_2, _ctx), _ctx); /*10002*/
            _match_x325 = kk_std_core_types__tuple2_unbox(_x_x864, KK_OWNED, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
            {
              kk_box_t _box_x297 = _match_x325.fst;
              kk_box_t _box_x298 = _match_x325.snd;
              kk_src_unified__runtime__v2__unified_state ns_0 = kk_src_unified__runtime__v2__unified_state_unbox(_box_x298, KK_BORROWED, _ctx);
              struct kk_src_unified__runtime__v2_Unified_state* _con_x869 = kk_src_unified__runtime__v2__as_Unified_state(ns_0, _ctx);
              kk_src_unified__runtime__v2__unified_state_dup(ns_0, _ctx);
              kk_std_core_types__tuple2_drop(_match_x325, _ctx);
              x_5_10090 = ns_0; /*src/unified_runtime_v2/unified-state*/
              goto _match_x829;
            }
          }
          {
            kk_string_drop(x_2_10082, _ctx);
            kk_string_drop(op_1, _ctx);
            x_5_10090 = state_2; /*src/unified_runtime_v2/unified-state*/
          }
          _match_x829: ;
          if (kk_yielding(kk_context())) {
            kk_datatype_ptr_dropn(x_5_10090, (KK_I32(3)), _ctx);
            kk_box_t _x_x870 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2_new_server_loop_fun871(_ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x870); return kk_Unit;
          }
          { // tailcall
            state_2 = x_5_10090;
            goto kk__tailcall;
          }
        }
        {
          kk_string_drop(x_2_10082, _ctx);
          kk_datatype_ptr_dropn(state_2, (KK_I32(3)), _ctx);
          kk_string_drop(op_1, _ctx);
          kk_Unit; return kk_Unit;
        }
      }
    }
    {
      kk_string_drop(x_2_10082, _ctx);
      kk_datatype_ptr_dropn(state_2, (KK_I32(3)), _ctx);
      kk_Unit; return kk_Unit;
    }
  }
}

// initialization
void kk_src_unified__runtime__v2__init(kk_context_t* _ctx){
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
  kk_gan__ying__init(_ctx);
  kk_hot__paths__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_src_unified__runtime__v2__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_hot__paths__done(_ctx);
  kk_gan__ying__done(_ctx);
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
