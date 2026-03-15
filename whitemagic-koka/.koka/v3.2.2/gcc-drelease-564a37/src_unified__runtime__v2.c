// Koka generated module: src/unified_runtime_v2, koka version: 3.2.2, platform: 64-bit
#include "src_unified__runtime__v2.h"

kk_src_unified__runtime__v2__unified_state kk_src_unified__runtime__v2_unified_state_fs__copy(kk_src_unified__runtime__v2__unified_state _this, kk_std_core_types__optional events, kk_std_core_types__optional profiles, kk_std_core_types__optional total_ops, kk_std_core_types__optional session_start, kk_context_t* _ctx) { /* (unified-state, events : ? (list<gan_ying/resonance-event>), profiles : ? (list<hot_paths/path-profile>), total-ops : ? int, session-start : ? float64) -> unified-state */ 
  kk_std_core_types__list _x_x254;
  if (kk_std_core_types__is_Optional(events, _ctx)) {
    kk_box_t _box_x0 = events._cons._Optional.value;
    kk_std_core_types__list _uniq_events_63 = kk_std_core_types__list_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_events_63, _ctx);
    kk_std_core_types__optional_drop(events, _ctx);
    _x_x254 = _uniq_events_63; /*list<gan_ying/resonance-event>*/
  }
  else {
    kk_std_core_types__optional_drop(events, _ctx);
    {
      struct kk_src_unified__runtime__v2_Unified_state* _con_x255 = kk_src_unified__runtime__v2__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _x = _con_x255->events;
      kk_std_core_types__list_dup(_x, _ctx);
      _x_x254 = _x; /*list<gan_ying/resonance-event>*/
    }
  }
  kk_std_core_types__list _x_x256;
  if (kk_std_core_types__is_Optional(profiles, _ctx)) {
    kk_box_t _box_x1 = profiles._cons._Optional.value;
    kk_std_core_types__list _uniq_profiles_71 = kk_std_core_types__list_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_profiles_71, _ctx);
    kk_std_core_types__optional_drop(profiles, _ctx);
    _x_x256 = _uniq_profiles_71; /*list<hot_paths/path-profile>*/
  }
  else {
    kk_std_core_types__optional_drop(profiles, _ctx);
    {
      struct kk_src_unified__runtime__v2_Unified_state* _con_x257 = kk_src_unified__runtime__v2__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x257->profiles;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x256 = _x_0; /*list<hot_paths/path-profile>*/
    }
  }
  kk_integer_t _x_x258;
  if (kk_std_core_types__is_Optional(total_ops, _ctx)) {
    kk_box_t _box_x2 = total_ops._cons._Optional.value;
    kk_integer_t _uniq_total_ops_79 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_total_ops_79, _ctx);
    kk_std_core_types__optional_drop(total_ops, _ctx);
    _x_x258 = _uniq_total_ops_79; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(total_ops, _ctx);
    {
      struct kk_src_unified__runtime__v2_Unified_state* _con_x259 = kk_src_unified__runtime__v2__as_Unified_state(_this, _ctx);
      kk_integer_t _x_1 = _con_x259->total_ops;
      kk_integer_dup(_x_1, _ctx);
      _x_x258 = _x_1; /*int*/
    }
  }
  double _x_x260;
  if (kk_std_core_types__is_Optional(session_start, _ctx)) {
    kk_box_t _box_x3 = session_start._cons._Optional.value;
    double _uniq_session_start_87 = kk_double_unbox(_box_x3, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(session_start, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x260 = _uniq_session_start_87; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(session_start, _ctx);
    {
      struct kk_src_unified__runtime__v2_Unified_state* _con_x261 = kk_src_unified__runtime__v2__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _pat_0_3 = _con_x261->events;
      kk_std_core_types__list _pat_1_4 = _con_x261->profiles;
      kk_integer_t _pat_2_3 = _con_x261->total_ops;
      double _x_2 = _con_x261->session_start;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_2_3, _ctx);
        kk_std_core_types__list_drop(_pat_1_4, _ctx);
        kk_std_core_types__list_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x260 = _x_2; /*float64*/
    }
  }
  return kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x254, _x_x256, _x_x258, _x_x260, _ctx);
}
 
// Emit event and profile the operation atomically

kk_src_unified__runtime__v2__unified_state kk_src_unified__runtime__v2_emit_profiled(kk_gan__ying__event_type et, kk_string_t source, kk_src_unified__runtime__v2__unified_state state, kk_context_t* _ctx) { /* (et : gan_ying/event-type, source : string, state : unified-state) -> unified-state */ 
  kk_hot__paths__path_profile profile;
  kk_string_t _x_x262 = kk_gan__ying_event_type_to_string(et, _ctx); /*string*/
  profile = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x262, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_std_core_types__list _x_x263;
  kk_box_t _x_x264;
  kk_gan__ying__resonance_event _x_x265;
  kk_string_t _x_x266 = kk_string_empty(); /*string*/
  _x_x265 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, source, et, _x_x266, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x264 = kk_gan__ying__resonance_event_box(_x_x265, _ctx); /*10021*/
  kk_std_core_types__list _x_x268;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x269 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x = _con_x269->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x268 = _x; /*list<gan_ying/resonance-event>*/
  }
  _x_x263 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x264, _x_x268, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x270;
  kk_std_core_types__list _x_x271;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x272 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x_0 = _con_x272->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x271 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x270 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile, _ctx), _x_x271, _ctx); /*list<10021>*/
  kk_integer_t _x_x273;
  kk_integer_t _x_x274;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x275 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_integer_t _x_1 = _con_x275->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x274 = _x_1; /*int*/
  }
  _x_x273 = kk_integer_add_small_const(_x_x274, 1, _ctx); /*int*/
  double _x_x276;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x277 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _pat_0_2 = _con_x277->events;
    kk_std_core_types__list _pat_1_2 = _con_x277->profiles;
    kk_integer_t _pat_2_2 = _con_x277->total_ops;
    double _x_2 = _con_x277->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_2_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_2, _ctx);
      kk_std_core_types__list_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x276 = _x_2; /*float64*/
  }
  return kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x263, _x_x270, _x_x273, _x_x276, _ctx);
}
 
// Check cascade handlers using gan_ying logic, profile with hot_paths

kk_std_core_types__tuple2 kk_src_unified__runtime__v2_cascade_profiled(kk_gan__ying__event_type et, kk_src_unified__runtime__v2__unified_state state, kk_context_t* _ctx) { /* (et : gan_ying/event-type, state : unified-state) -> (int, unified-state) */ 
  kk_src_unified__runtime__v2__unified_state new_state;
  kk_std_core_types__list _x_x278;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x279 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x = _con_x279->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x278 = _x; /*list<gan_ying/resonance-event>*/
  }
  kk_std_core_types__list _x_x280;
  kk_box_t _x_x281;
  kk_hot__paths__path_profile _x_x282;
  kk_string_t _x_x283;
  kk_define_string_literal(, _s_x284, 13, "cascade_check", _ctx)
  _x_x283 = kk_string_dup(_s_x284, _ctx); /*string*/
  _x_x282 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x283, kk_integer_from_small(1), 0x1p-1, 0x1p-1, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_Compute(_ctx), _ctx); /*hot_paths/path-profile*/
  _x_x281 = kk_hot__paths__path_profile_box(_x_x282, _ctx); /*10021*/
  kk_std_core_types__list _x_x285;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x286 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x_0 = _con_x286->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x285 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x280 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x281, _x_x285, _ctx); /*list<10021>*/
  kk_integer_t _x_x287;
  kk_integer_t _x_x288;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x289 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_integer_t _x_1 = _con_x289->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x288 = _x_1; /*int*/
  }
  _x_x287 = kk_integer_add_small_const(_x_x288, 1, _ctx); /*int*/
  double _x_x290;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x291 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
    kk_std_core_types__list _pat_0_2 = _con_x291->events;
    kk_std_core_types__list _pat_1_2 = _con_x291->profiles;
    kk_integer_t _pat_2_2 = _con_x291->total_ops;
    double _x_2 = _con_x291->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_2_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_2, _ctx);
      kk_std_core_types__list_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x290 = _x_2; /*float64*/
  }
  new_state = kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x278, _x_x280, _x_x287, _x_x290, _ctx); /*src/unified_runtime_v2/unified-state*/
  kk_box_t _x_x292;
  kk_integer_t _x_x293;
  if (kk_gan__ying__is_MemoryCreated(et, _ctx)) {
    _x_x293 = kk_integer_from_small(3); /*int*/
    goto _match_x294;
  }
  if (kk_gan__ying__is_MemoryUpdated(et, _ctx)) {
    _x_x293 = kk_integer_from_small(2); /*int*/
    goto _match_x294;
  }
  if (kk_gan__ying__is_ThreatDetected(et, _ctx)) {
    _x_x293 = kk_integer_from_small(5); /*int*/
    goto _match_x294;
  }
  if (kk_gan__ying__is_FlowStateEntered(et, _ctx)) {
    _x_x293 = kk_integer_from_small(2); /*int*/
    goto _match_x294;
  }
  {
    _x_x293 = kk_integer_from_small(1); /*int*/
  }
  _match_x294: ;
  _x_x292 = kk_integer_box(_x_x293, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x292, kk_src_unified__runtime__v2__unified_state_box(new_state, _ctx), _ctx);
}

kk_string_t kk_src_unified__runtime__v2_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x232;
  kk_string_t _x_x295 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x296;
  kk_define_string_literal(, _s_x297, 6, "\"emit\"", _ctx)
  _x_x296 = kk_string_dup(_s_x297, _ctx); /*string*/
  _match_x232 = kk_string_contains(_x_x295,_x_x296,kk_context()); /*bool*/
  if (_match_x232) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x298, 4, "emit", _ctx)
    return kk_string_dup(_s_x298, _ctx);
  }
  {
    bool _match_x233;
    kk_string_t _x_x299 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x300;
    kk_define_string_literal(, _s_x301, 9, "\"cascade\"", _ctx)
    _x_x300 = kk_string_dup(_s_x301, _ctx); /*string*/
    _match_x233 = kk_string_contains(_x_x299,_x_x300,kk_context()); /*bool*/
    if (_match_x233) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x302, 7, "cascade", _ctx)
      return kk_string_dup(_s_x302, _ctx);
    }
    {
      bool _match_x234;
      kk_string_t _x_x303 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x304;
      kk_define_string_literal(, _s_x305, 9, "\"profile\"", _ctx)
      _x_x304 = kk_string_dup(_s_x305, _ctx); /*string*/
      _match_x234 = kk_string_contains(_x_x303,_x_x304,kk_context()); /*bool*/
      if (_match_x234) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x306, 7, "profile", _ctx)
        return kk_string_dup(_s_x306, _ctx);
      }
      {
        bool _match_x235;
        kk_string_t _x_x307 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x308;
        kk_define_string_literal(, _s_x309, 8, "\"status\"", _ctx)
        _x_x308 = kk_string_dup(_s_x309, _ctx); /*string*/
        _match_x235 = kk_string_contains(_x_x307,_x_x308,kk_context()); /*bool*/
        if (_match_x235) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x310, 6, "status", _ctx)
          return kk_string_dup(_s_x310, _ctx);
        }
        {
          bool _match_x236;
          kk_string_t _x_x311 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x312;
          kk_define_string_literal(, _s_x313, 5, "\"hot\"", _ctx)
          _x_x312 = kk_string_dup(_s_x313, _ctx); /*string*/
          _match_x236 = kk_string_contains(_x_x311,_x_x312,kk_context()); /*bool*/
          if (_match_x236) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x314, 3, "hot", _ctx)
            return kk_string_dup(_s_x314, _ctx);
          }
          {
            bool _match_x237;
            kk_string_t _x_x315;
            kk_define_string_literal(, _s_x316, 6, "\"quit\"", _ctx)
            _x_x315 = kk_string_dup(_s_x316, _ctx); /*string*/
            _match_x237 = kk_string_contains(line,_x_x315,kk_context()); /*bool*/
            if (_match_x237) {
              kk_define_string_literal(, _s_x317, 4, "quit", _ctx)
              return kk_string_dup(_s_x317, _ctx);
            }
            {
              kk_define_string_literal(, _s_x318, 7, "unknown", _ctx)
              return kk_string_dup(_s_x318, _ctx);
            }
          }
        }
      }
    }
  }
}

kk_gan__ying__event_type kk_src_unified__runtime__v2_extract_event_type(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> gan_ying/event-type */ 
  bool _match_x228;
  kk_string_t _x_x319 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x320;
  kk_define_string_literal(, _s_x321, 14, "memory_created", _ctx)
  _x_x320 = kk_string_dup(_s_x321, _ctx); /*string*/
  _match_x228 = kk_string_contains(_x_x319,_x_x320,kk_context()); /*bool*/
  if (_match_x228) {
    kk_string_drop(line, _ctx);
    return kk_gan__ying__new_MemoryCreated(_ctx);
  }
  {
    bool _match_x229;
    kk_string_t _x_x322 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x323;
    kk_define_string_literal(, _s_x324, 14, "memory_updated", _ctx)
    _x_x323 = kk_string_dup(_s_x324, _ctx); /*string*/
    _match_x229 = kk_string_contains(_x_x322,_x_x323,kk_context()); /*bool*/
    if (_match_x229) {
      kk_string_drop(line, _ctx);
      return kk_gan__ying__new_MemoryUpdated(_ctx);
    }
    {
      bool _match_x230;
      kk_string_t _x_x325 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x326;
      kk_define_string_literal(, _s_x327, 15, "threat_detected", _ctx)
      _x_x326 = kk_string_dup(_s_x327, _ctx); /*string*/
      _match_x230 = kk_string_contains(_x_x325,_x_x326,kk_context()); /*bool*/
      if (_match_x230) {
        kk_string_drop(line, _ctx);
        return kk_gan__ying__new_ThreatDetected(_ctx);
      }
      {
        bool _match_x231;
        kk_string_t _x_x328;
        kk_define_string_literal(, _s_x329, 10, "flow_state", _ctx)
        _x_x328 = kk_string_dup(_s_x329, _ctx); /*string*/
        _match_x231 = kk_string_contains(line,_x_x328,kk_context()); /*bool*/
        if (_match_x231) {
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
  kk_string_t _x_x330;
  kk_define_string_literal(, _s_x331, 10, "{\"events\":", _ctx)
  _x_x330 = kk_string_dup(_s_x331, _ctx); /*string*/
  kk_string_t _x_x332;
  kk_string_t _x_x333;
  kk_integer_t _x_x334;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x335 = kk_src_unified__runtime__v2__as_Unified_state(s, _ctx);
    kk_std_core_types__list _x = _con_x335->events;
    kk_std_core_types__list_dup(_x, _ctx);
    if (kk_std_core_types__is_Nil(_x, _ctx)) {
      _x_x334 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_std_core_types__list_drop(_x, _ctx);
      kk_std_core_types__list _x_x336;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x337 = kk_src_unified__runtime__v2__as_Unified_state(s, _ctx);
        kk_std_core_types__list _x_0 = _con_x337->events;
        kk_std_core_types__list_dup(_x_0, _ctx);
        _x_x336 = _x_0; /*list<gan_ying/resonance-event>*/
      }
      _x_x334 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x336, kk_integer_from_small(0), _ctx); /*int*/
    }
  }
  _x_x333 = kk_std_core_int_show(_x_x334, _ctx); /*string*/
  kk_string_t _x_x338;
  kk_string_t _x_x339;
  kk_define_string_literal(, _s_x340, 12, ",\"profiles\":", _ctx)
  _x_x339 = kk_string_dup(_s_x340, _ctx); /*string*/
  kk_string_t _x_x341;
  kk_string_t _x_x342;
  kk_integer_t _x_x343;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x344 = kk_src_unified__runtime__v2__as_Unified_state(s, _ctx);
    kk_std_core_types__list _x_0_0 = _con_x344->profiles;
    kk_std_core_types__list_dup(_x_0_0, _ctx);
    if (kk_std_core_types__is_Nil(_x_0_0, _ctx)) {
      _x_x343 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_std_core_types__list_drop(_x_0_0, _ctx);
      kk_std_core_types__list _x_x345;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x346 = kk_src_unified__runtime__v2__as_Unified_state(s, _ctx);
        kk_std_core_types__list _x_0_1 = _con_x346->profiles;
        kk_std_core_types__list_dup(_x_0_1, _ctx);
        _x_x345 = _x_0_1; /*list<hot_paths/path-profile>*/
      }
      _x_x343 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x345, kk_integer_from_small(0), _ctx); /*int*/
    }
  }
  _x_x342 = kk_std_core_int_show(_x_x343, _ctx); /*string*/
  kk_string_t _x_x347;
  kk_string_t _x_x348;
  kk_define_string_literal(, _s_x349, 13, ",\"total_ops\":", _ctx)
  _x_x348 = kk_string_dup(_s_x349, _ctx); /*string*/
  kk_string_t _x_x350;
  kk_string_t _x_x351;
  kk_integer_t _x_x352;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x353 = kk_src_unified__runtime__v2__as_Unified_state(s, _ctx);
    kk_integer_t _x_1 = _con_x353->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x352 = _x_1; /*int*/
  }
  _x_x351 = kk_std_core_int_show(_x_x352, _ctx); /*string*/
  kk_string_t _x_x354;
  kk_string_t _x_x355;
  kk_define_string_literal(, _s_x356, 17, ",\"session_start\":", _ctx)
  _x_x355 = kk_string_dup(_s_x356, _ctx); /*string*/
  kk_string_t _x_x357;
  kk_string_t _x_x358;
  double _x_x359;
  {
    struct kk_src_unified__runtime__v2_Unified_state* _con_x360 = kk_src_unified__runtime__v2__as_Unified_state(s, _ctx);
    kk_std_core_types__list _pat_0_3 = _con_x360->events;
    kk_std_core_types__list _pat_1_4 = _con_x360->profiles;
    kk_integer_t _pat_2_2 = _con_x360->total_ops;
    double _x_2 = _con_x360->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(s, _ctx)) {
      kk_integer_drop(_pat_2_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_4, _ctx);
      kk_std_core_types__list_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(s, _ctx);
    }
    else {
      kk_datatype_ptr_decref(s, _ctx);
    }
    _x_x359 = _x_2; /*float64*/
  }
  _x_x358 = kk_std_num_float64_show(_x_x359, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x361;
  kk_define_string_literal(, _s_x362, 1, "}", _ctx)
  _x_x361 = kk_string_dup(_s_x362, _ctx); /*string*/
  _x_x357 = kk_std_core_types__lp__plus__plus__rp_(_x_x358, _x_x361, _ctx); /*string*/
  _x_x354 = kk_std_core_types__lp__plus__plus__rp_(_x_x355, _x_x357, _ctx); /*string*/
  _x_x350 = kk_std_core_types__lp__plus__plus__rp_(_x_x351, _x_x354, _ctx); /*string*/
  _x_x347 = kk_std_core_types__lp__plus__plus__rp_(_x_x348, _x_x350, _ctx); /*string*/
  _x_x341 = kk_std_core_types__lp__plus__plus__rp_(_x_x342, _x_x347, _ctx); /*string*/
  _x_x338 = kk_std_core_types__lp__plus__plus__rp_(_x_x339, _x_x341, _ctx); /*string*/
  _x_x332 = kk_std_core_types__lp__plus__plus__rp_(_x_x333, _x_x338, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x330, _x_x332, _ctx);
}
 
// lifted local: response, server-loop, @spec-x10139
// specialized: std/core/list/filter, on parameters @uniq-pred@10136, using:
// @uniq-pred@10136 = std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(p : hot_paths/path-profile) -> bool,(p : hot_paths/path-profile) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> bool>((fn(p: hot_paths/path-profile){
//   (match (p) {
//     ((@skip hot_paths/Path-profile((@pat@0@7: string) : string, (@pat@1@10: int) : int, (@pat@2@7: float64) : float64, (@pat@3@1: float64) : float64, (@x@6: hot_paths/complexity) : hot_paths/complexity, (@pat@4@1: hot_paths/path-category) : hot_paths/path-category) : hot_paths/path-profile ) as @pat@14: hot_paths/path-profile)
//        -> (match (@x@6) {
//         ((hot_paths/High() : hot_paths/complexity ) as @pat@11@0: hot_paths/complexity)
//            -> std/core/types/True;
//         (@pat@12@0: hot_paths/complexity)
//            -> std/core/types/False;
//       });
//   });
// }))


// lift anonymous function
struct kk_src_unified__runtime__v2__lift_server_loop_10140_fun363__t {
  struct kk_function_s _base;
};
static bool kk_src_unified__runtime__v2__lift_server_loop_10140_fun363(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_lift_server_loop_10140_fun363(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__lift_server_loop_10140_fun363, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static bool kk_src_unified__runtime__v2__lift_server_loop_10140_fun363(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_hot__paths__path_profile _match_x227 = kk_hot__paths__path_profile_unbox(_b_x22, KK_OWNED, _ctx); /*hot_paths/path-profile*/;
  {
    struct kk_hot__paths_Path_profile* _con_x364 = kk_hot__paths__as_Path_profile(_match_x227, _ctx);
    kk_string_t _pat_0_7 = _con_x364->name;
    kk_integer_t _pat_1_10 = _con_x364->call_count;
    kk_hot__paths__complexity _x_6 = _con_x364->complexity;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x227, _ctx)) {
      kk_integer_drop(_pat_1_10, _ctx);
      kk_string_drop(_pat_0_7, _ctx);
      kk_datatype_ptr_free(_match_x227, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x227, _ctx);
    }
    if (kk_hot__paths__is_High(_x_6, _ctx)) {
      return true;
    }
    {
      return false;
    }
  }
}

kk_std_core_types__list kk_src_unified__runtime__v2__lift_server_loop_10140(kk_std_core_types__list _uniq_xs_10135, kk_context_t* _ctx) { /* (list<hot_paths/path-profile>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<hot_paths/path-profile> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10135, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_filter_10007(_uniq_xs_10135, kk_src_unified__runtime__v2__new_lift_server_loop_10140_fun363(_ctx), _ctx);
  }
}
 
// monadic lift

kk_string_t kk_src_unified__runtime__v2__mlift_server_loop_10195(kk_std_core_types__list _y_x10145, kk_context_t* _ctx) { /* (list<hot_paths/path-profile>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_integer_t x;
  if (kk_std_core_types__is_Nil(_y_x10145, _ctx)) {
    x = kk_integer_from_small(0); /*int*/
  }
  else {
    x = kk_std_core_list__unroll_lift_length_5730_10000(_y_x10145, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_string_t _x_x365;
  kk_define_string_literal(, _s_x366, 13, "{\"hot_paths\":", _ctx)
  _x_x365 = kk_string_dup(_s_x366, _ctx); /*string*/
  kk_string_t _x_x367;
  kk_string_t _x_x368 = kk_std_core_int_show(x, _ctx); /*string*/
  kk_string_t _x_x369;
  kk_define_string_literal(, _s_x370, 21, ",\"threshold_ms\":10.0}", _ctx)
  _x_x369 = kk_string_dup(_s_x370, _ctx); /*string*/
  _x_x367 = kk_std_core_types__lp__plus__plus__rp_(_x_x368, _x_x369, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x365, _x_x367, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10196_fun376__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10196_fun376(kk_function_t _fself, kk_box_t _b_x28, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10196_fun376(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10196_fun376, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10196_fun376(kk_function_t _fself, kk_box_t _b_x28, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x377;
  kk_string_t _x_x378 = kk_string_unbox(_b_x28); /*string*/
  _x_x377 = kk_src_unified__runtime__v2_extract_event_type(_x_x378, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x377, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10196_fun398__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10196_fun398(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10196_fun398(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10196_fun398, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10196_fun398(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x399;
  kk_string_t _x_x400 = kk_string_unbox(_b_x41); /*string*/
  _x_x399 = kk_src_unified__runtime__v2_extract_event_type(_x_x400, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x399, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10196_fun402__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10196_fun402(kk_function_t _fself, kk_box_t _b_x47, kk_box_t _b_x48, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10196_fun402(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10196_fun402, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10196_fun402(kk_function_t _fself, kk_box_t _b_x47, kk_box_t _b_x48, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x403;
  kk_gan__ying__event_type _x_x404 = kk_gan__ying__event_type_unbox(_b_x47, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v2__unified_state _x_x405 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x48, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x403 = kk_src_unified__runtime__v2_cascade_profiled(_x_x404, _x_x405, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x403, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10196_fun408__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10196_fun408(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10196_fun408(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10196_fun408, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10196_fun408(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x409 = kk_Unit;
  kk_src_unified__runtime__v2__unified_state _x_x410 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x55, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  kk_src_unified__runtime__v2_server_loop(_x_x410, _ctx);
  return kk_unit_box(_x_x409);
}

kk_unit_t kk_src_unified__runtime__v2__mlift_server_loop_10196(kk_string_t line, kk_string_t op, kk_src_unified__runtime__v2__unified_state state, kk_string_t _c_x10146, kk_context_t* _ctx) { /* (line : string, op : string, state : unified-state, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10146, _ctx);
  bool _match_x224;
  kk_string_t _x_x371 = kk_string_dup(op, _ctx); /*string*/
  kk_string_t _x_x372;
  kk_define_string_literal(, _s_x373, 4, "quit", _ctx)
  _x_x372 = kk_string_dup(_s_x373, _ctx); /*string*/
  _match_x224 = kk_string_is_neq(_x_x371,_x_x372,kk_context()); /*bool*/
  if (_match_x224) {
    kk_src_unified__runtime__v2__unified_state x_0_10202;
    if (kk_string_cmp_cstr_borrow(op, "emit", _ctx) == 0) {
      kk_string_drop(op, _ctx);
      kk_gan__ying__event_type et_1;
      kk_box_t _x_x375 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10196_fun376(_ctx), kk_string_box(line), _ctx); /*10001*/
      et_1 = kk_gan__ying__event_type_unbox(_x_x375, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_hot__paths__path_profile profile_0;
      kk_string_t _x_x379 = kk_gan__ying_event_type_to_string(et_1, _ctx); /*string*/
      profile_0 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x379, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
      kk_src_unified__runtime__v2__unified_state x_1;
      kk_std_core_types__list _x_x380;
      kk_box_t _x_x381;
      kk_gan__ying__resonance_event _x_x382;
      kk_string_t _x_x383;
      kk_define_string_literal(, _s_x384, 15, "unified_runtime", _ctx)
      _x_x383 = kk_string_dup(_s_x384, _ctx); /*string*/
      kk_string_t _x_x385 = kk_string_empty(); /*string*/
      _x_x382 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x383, et_1, _x_x385, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
      _x_x381 = kk_gan__ying__resonance_event_box(_x_x382, _ctx); /*10021*/
      kk_std_core_types__list _x_x387;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x388 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
        kk_std_core_types__list _x_7 = _con_x388->events;
        kk_std_core_types__list_dup(_x_7, _ctx);
        _x_x387 = _x_7; /*list<gan_ying/resonance-event>*/
      }
      _x_x380 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x381, _x_x387, _ctx); /*list<10021>*/
      kk_std_core_types__list _x_x389;
      kk_std_core_types__list _x_x390;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x391 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
        kk_std_core_types__list _x_8 = _con_x391->profiles;
        kk_std_core_types__list_dup(_x_8, _ctx);
        _x_x390 = _x_8; /*list<hot_paths/path-profile>*/
      }
      _x_x389 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_0, _ctx), _x_x390, _ctx); /*list<10021>*/
      kk_integer_t _x_x392;
      kk_integer_t _x_x393;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x394 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
        kk_integer_t _x_9 = _con_x394->total_ops;
        kk_integer_dup(_x_9, _ctx);
        _x_x393 = _x_9; /*int*/
      }
      _x_x392 = kk_integer_add_small_const(_x_x393, 1, _ctx); /*int*/
      double _x_x395;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x396 = kk_src_unified__runtime__v2__as_Unified_state(state, _ctx);
        kk_std_core_types__list _pat_0_11 = _con_x396->events;
        kk_std_core_types__list _pat_1_14 = _con_x396->profiles;
        kk_integer_t _pat_2_11 = _con_x396->total_ops;
        double _x_10 = _con_x396->session_start;
        if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
          kk_integer_drop(_pat_2_11, _ctx);
          kk_std_core_types__list_drop(_pat_1_14, _ctx);
          kk_std_core_types__list_drop(_pat_0_11, _ctx);
          kk_datatype_ptr_free(state, _ctx);
        }
        else {
          kk_datatype_ptr_decref(state, _ctx);
        }
        _x_x395 = _x_10; /*float64*/
      }
      x_1 = kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x380, _x_x389, _x_x392, _x_x395, _ctx); /*src/unified_runtime_v2/unified-state*/
      kk_unit_t keep_0 = kk_Unit;
      kk_evv_set(w_0,kk_context());
      x_0_10202 = x_1; /*src/unified_runtime_v2/unified-state*/
      goto _match_x374;
    }
    if (kk_string_cmp_cstr_borrow(op, "cascade", _ctx) == 0) {
      kk_string_drop(op, _ctx);
      kk_gan__ying__event_type et_2_0;
      kk_box_t _x_x397 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10196_fun398(_ctx), kk_string_box(line), _ctx); /*10001*/
      et_2_0 = kk_gan__ying__event_type_unbox(_x_x397, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_std_core_types__tuple2 _match_x226;
      kk_box_t _x_x401 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v2__new_mlift_server_loop_10196_fun402(_ctx), kk_gan__ying__event_type_box(et_2_0, _ctx), kk_src_unified__runtime__v2__unified_state_box(state, _ctx), _ctx); /*10002*/
      _match_x226 = kk_std_core_types__tuple2_unbox(_x_x401, KK_OWNED, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
      {
        kk_box_t _box_x49 = _match_x226.fst;
        kk_box_t _box_x50 = _match_x226.snd;
        kk_src_unified__runtime__v2__unified_state ns = kk_src_unified__runtime__v2__unified_state_unbox(_box_x50, KK_BORROWED, _ctx);
        struct kk_src_unified__runtime__v2_Unified_state* _con_x406 = kk_src_unified__runtime__v2__as_Unified_state(ns, _ctx);
        kk_src_unified__runtime__v2__unified_state_dup(ns, _ctx);
        kk_std_core_types__tuple2_drop(_match_x226, _ctx);
        x_0_10202 = ns; /*src/unified_runtime_v2/unified-state*/
        goto _match_x374;
      }
    }
    {
      kk_string_drop(op, _ctx);
      kk_string_drop(line, _ctx);
      x_0_10202 = state; /*src/unified_runtime_v2/unified-state*/
    }
    _match_x374: ;
    if (kk_yielding(kk_context())) {
      kk_datatype_ptr_dropn(x_0_10202, (KK_I32(3)), _ctx);
      kk_box_t _x_x407 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2__new_mlift_server_loop_10196_fun408(_ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x407); return kk_Unit;
    }
    {
      kk_src_unified__runtime__v2_server_loop(x_0_10202, _ctx); return kk_Unit;
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
struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun415__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun415(kk_function_t _fself, kk_box_t _b_x59, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun415(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10197_fun415, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun415(kk_function_t _fself, kk_box_t _b_x59, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x416;
  kk_string_t _x_x417 = kk_string_unbox(_b_x59); /*string*/
  _x_x416 = kk_src_unified__runtime__v2_extract_op(_x_x417, _ctx); /*string*/
  return kk_string_box(_x_x416);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun422__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun422(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun422(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10197_fun422, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun422(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x423;
  kk_string_t _x_x424 = kk_string_unbox(_b_x64); /*string*/
  _x_x423 = kk_src_unified__runtime__v2_extract_event_type(_x_x424, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x423, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun450__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun450(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun450(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10197_fun450, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun450(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x451;
  kk_gan__ying__event_type _x_x452 = kk_gan__ying__event_type_unbox(_b_x77, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x451 = kk_gan__ying_event_type_to_string(_x_x452, _ctx); /*string*/
  return kk_string_box(_x_x451);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun459__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun459(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun459(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10197_fun459, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun459(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x460;
  kk_src_unified__runtime__v2__unified_state _x_x461 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x80, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x460 = kk_src_unified__runtime__v2_json_state(_x_x461, _ctx); /*string*/
  return kk_string_box(_x_x460);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun465__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun465(kk_function_t _fself, kk_box_t _b_x83, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun465(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10197_fun465, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun465(kk_function_t _fself, kk_box_t _b_x83, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x466;
  kk_string_t _x_x467 = kk_string_unbox(_b_x83); /*string*/
  _x_x466 = kk_src_unified__runtime__v2_extract_event_type(_x_x467, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x466, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun471__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun471(kk_function_t _fself, kk_box_t _b_x89, kk_box_t _b_x90, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun471(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10197_fun471, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun471(kk_function_t _fself, kk_box_t _b_x89, kk_box_t _b_x90, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x472;
  kk_gan__ying__event_type _x_x473 = kk_gan__ying__event_type_unbox(_b_x89, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v2__unified_state _x_x474 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x90, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x472 = kk_src_unified__runtime__v2_cascade_profiled(_x_x473, _x_x474, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x472, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun483__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun483(kk_function_t _fself, kk_box_t _b_x95, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun483(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10197_fun483, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun483(kk_function_t _fself, kk_box_t _b_x95, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x484;
  kk_gan__ying__event_type _x_x485 = kk_gan__ying__event_type_unbox(_b_x95, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x484 = kk_gan__ying_event_type_to_string(_x_x485, _ctx); /*string*/
  return kk_string_box(_x_x484);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun510__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun510(kk_function_t _fself, kk_box_t _b_x98, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun510(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10197_fun510, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun510(kk_function_t _fself, kk_box_t _b_x98, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x511;
  kk_src_unified__runtime__v2__unified_state _x_x512 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x98, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x511 = kk_src_unified__runtime__v2_json_state(_x_x512, _ctx); /*string*/
  return kk_string_box(_x_x511);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun518__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun518(kk_function_t _fself, kk_box_t _b_x100, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun518(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__mlift_server_loop_10197_fun518, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun518(kk_function_t _fself, kk_box_t _b_x100, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x519;
  kk_std_core_types__list _x_x520 = kk_std_core_types__list_unbox(_b_x100, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
  _x_x519 = kk_src_unified__runtime__v2__mlift_server_loop_10195(_x_x520, _ctx); /*string*/
  return kk_string_box(_x_x519);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun524__t {
  struct kk_function_s _base;
  kk_string_t line_0;
  kk_string_t op_0;
  kk_src_unified__runtime__v2__unified_state state_0;
};
static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun524(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun524(kk_string_t line_0, kk_string_t op_0, kk_src_unified__runtime__v2__unified_state state_0, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun524__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun524__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v2__mlift_server_loop_10197_fun524, kk_context());
  _self->line_0 = line_0;
  _self->op_0 = op_0;
  _self->state_0 = state_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__mlift_server_loop_10197_fun524(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun524__t* _self = kk_function_as(struct kk_src_unified__runtime__v2__mlift_server_loop_10197_fun524__t*, _fself, _ctx);
  kk_string_t line_0 = _self->line_0; /* string */
  kk_string_t op_0 = _self->op_0; /* string */
  kk_src_unified__runtime__v2__unified_state state_0 = _self->state_0; /* src/unified_runtime_v2/unified-state */
  kk_drop_match(_self, {kk_string_dup(line_0, _ctx);kk_string_dup(op_0, _ctx);kk_src_unified__runtime__v2__unified_state_dup(state_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10146_0_116 = kk_string_unbox(_b_x114); /*string*/;
  kk_unit_t _x_x525 = kk_Unit;
  kk_src_unified__runtime__v2__mlift_server_loop_10196(line_0, op_0, state_0, _c_x10146_0_116, _ctx);
  return kk_unit_box(_x_x525);
}

kk_unit_t kk_src_unified__runtime__v2__mlift_server_loop_10197(kk_src_unified__runtime__v2__unified_state state_0, kk_string_t line_0, kk_context_t* _ctx) { /* (state : unified-state, line : string) -> <console/console,exn> () */ 
  bool _match_x220;
  kk_string_t _x_x411 = kk_string_dup(line_0, _ctx); /*string*/
  kk_string_t _x_x412 = kk_string_empty(); /*string*/
  _match_x220 = kk_string_is_neq(_x_x411,_x_x412,kk_context()); /*bool*/
  if (_match_x220) {
    kk_string_t op_0;
    kk_box_t _x_x414;
    kk_box_t _x_x418;
    kk_string_t _x_x419 = kk_string_dup(line_0, _ctx); /*string*/
    _x_x418 = kk_string_box(_x_x419); /*10000*/
    _x_x414 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun415(_ctx), _x_x418, _ctx); /*10001*/
    op_0 = kk_string_unbox(_x_x414); /*string*/
    kk_string_t x_2_10208;
    if (kk_string_cmp_cstr_borrow(op_0, "emit", _ctx) == 0) {
      kk_gan__ying__event_type et;
      kk_box_t _x_x421;
      kk_box_t _x_x425;
      kk_string_t _x_x426 = kk_string_dup(line_0, _ctx); /*string*/
      _x_x425 = kk_string_box(_x_x426); /*10000*/
      _x_x421 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun422(_ctx), _x_x425, _ctx); /*10001*/
      et = kk_gan__ying__event_type_unbox(_x_x421, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_hot__paths__path_profile profile;
      kk_string_t _x_x427 = kk_gan__ying_event_type_to_string(et, _ctx); /*string*/
      profile = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x427, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
      kk_src_unified__runtime__v2__unified_state x_3;
      kk_std_core_types__list _x_x428;
      kk_box_t _x_x429;
      kk_gan__ying__resonance_event _x_x430;
      kk_string_t _x_x431;
      kk_define_string_literal(, _s_x432, 15, "unified_runtime", _ctx)
      _x_x431 = kk_string_dup(_s_x432, _ctx); /*string*/
      kk_string_t _x_x433 = kk_string_empty(); /*string*/
      _x_x430 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x431, et, _x_x433, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
      _x_x429 = kk_gan__ying__resonance_event_box(_x_x430, _ctx); /*10021*/
      kk_std_core_types__list _x_x435;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x436 = kk_src_unified__runtime__v2__as_Unified_state(state_0, _ctx);
        kk_std_core_types__list _x = _con_x436->events;
        kk_std_core_types__list_dup(_x, _ctx);
        _x_x435 = _x; /*list<gan_ying/resonance-event>*/
      }
      _x_x428 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x429, _x_x435, _ctx); /*list<10021>*/
      kk_std_core_types__list _x_x437;
      kk_std_core_types__list _x_x438;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x439 = kk_src_unified__runtime__v2__as_Unified_state(state_0, _ctx);
        kk_std_core_types__list _x_0 = _con_x439->profiles;
        kk_std_core_types__list_dup(_x_0, _ctx);
        _x_x438 = _x_0; /*list<hot_paths/path-profile>*/
      }
      _x_x437 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile, _ctx), _x_x438, _ctx); /*list<10021>*/
      kk_integer_t _x_x440;
      kk_integer_t _x_x441;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x442 = kk_src_unified__runtime__v2__as_Unified_state(state_0, _ctx);
        kk_integer_t _x_1 = _con_x442->total_ops;
        kk_integer_dup(_x_1, _ctx);
        _x_x441 = _x_1; /*int*/
      }
      _x_x440 = kk_integer_add_small_const(_x_x441, 1, _ctx); /*int*/
      double _x_x443;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x444 = kk_src_unified__runtime__v2__as_Unified_state(state_0, _ctx);
        double _x_2 = _con_x444->session_start;
        _x_x443 = _x_2; /*float64*/
      }
      x_3 = kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x428, _x_x437, _x_x440, _x_x443, _ctx); /*src/unified_runtime_v2/unified-state*/
      kk_unit_t keep_1 = kk_Unit;
      kk_evv_set(w_1,kk_context());
      kk_string_t _x_x445;
      kk_define_string_literal(, _s_x446, 12, "{\"emitted\":\"", _ctx)
      _x_x445 = kk_string_dup(_s_x446, _ctx); /*string*/
      kk_string_t _x_x447;
      kk_string_t _x_x448;
      kk_box_t _x_x449 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun450(_ctx), kk_gan__ying__event_type_box(et, _ctx), _ctx); /*10001*/
      _x_x448 = kk_string_unbox(_x_x449); /*string*/
      kk_string_t _x_x453;
      kk_string_t _x_x454;
      kk_define_string_literal(, _s_x455, 10, "\",\"state\":", _ctx)
      _x_x454 = kk_string_dup(_s_x455, _ctx); /*string*/
      kk_string_t _x_x456;
      kk_string_t _x_x457;
      kk_box_t _x_x458 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun459(_ctx), kk_src_unified__runtime__v2__unified_state_box(x_3, _ctx), _ctx); /*10001*/
      _x_x457 = kk_string_unbox(_x_x458); /*string*/
      kk_string_t _x_x462;
      kk_define_string_literal(, _s_x463, 1, "}", _ctx)
      _x_x462 = kk_string_dup(_s_x463, _ctx); /*string*/
      _x_x456 = kk_std_core_types__lp__plus__plus__rp_(_x_x457, _x_x462, _ctx); /*string*/
      _x_x453 = kk_std_core_types__lp__plus__plus__rp_(_x_x454, _x_x456, _ctx); /*string*/
      _x_x447 = kk_std_core_types__lp__plus__plus__rp_(_x_x448, _x_x453, _ctx); /*string*/
      x_2_10208 = kk_std_core_types__lp__plus__plus__rp_(_x_x445, _x_x447, _ctx); /*string*/
      goto _match_x420;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "cascade", _ctx) == 0) {
      kk_gan__ying__event_type et_0_0;
      kk_box_t _x_x464;
      kk_box_t _x_x468;
      kk_string_t _x_x469 = kk_string_dup(line_0, _ctx); /*string*/
      _x_x468 = kk_string_box(_x_x469); /*10000*/
      _x_x464 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun465(_ctx), _x_x468, _ctx); /*10001*/
      et_0_0 = kk_gan__ying__event_type_unbox(_x_x464, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_std_core_types__tuple2 _match_x223;
      kk_box_t _x_x470;
      kk_box_t _x_x475;
      kk_src_unified__runtime__v2__unified_state _x_x476 = kk_src_unified__runtime__v2__unified_state_dup(state_0, _ctx); /*src/unified_runtime_v2/unified-state*/
      _x_x475 = kk_src_unified__runtime__v2__unified_state_box(_x_x476, _ctx); /*10001*/
      _x_x470 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun471(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _x_x475, _ctx); /*10002*/
      _match_x223 = kk_std_core_types__tuple2_unbox(_x_x470, KK_OWNED, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
      {
        kk_box_t _box_x91 = _match_x223.fst;
        kk_box_t _box_x92 = _match_x223.snd;
        kk_src_unified__runtime__v2__unified_state _pat_3_0 = kk_src_unified__runtime__v2__unified_state_unbox(_box_x92, KK_BORROWED, _ctx);
        struct kk_src_unified__runtime__v2_Unified_state* _con_x477 = kk_src_unified__runtime__v2__as_Unified_state(_pat_3_0, _ctx);
        kk_integer_t handlers = kk_integer_unbox(_box_x91, _ctx);
        kk_integer_dup(handlers, _ctx);
        kk_std_core_types__tuple2_drop(_match_x223, _ctx);
        kk_string_t _x_x478;
        kk_define_string_literal(, _s_x479, 12, "{\"cascade\":\"", _ctx)
        _x_x478 = kk_string_dup(_s_x479, _ctx); /*string*/
        kk_string_t _x_x480;
        kk_string_t _x_x481;
        kk_box_t _x_x482 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun483(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _ctx); /*10001*/
        _x_x481 = kk_string_unbox(_x_x482); /*string*/
        kk_string_t _x_x486;
        kk_string_t _x_x487;
        kk_define_string_literal(, _s_x488, 13, "\",\"handlers\":", _ctx)
        _x_x487 = kk_string_dup(_s_x488, _ctx); /*string*/
        kk_string_t _x_x489;
        kk_string_t _x_x490 = kk_std_core_int_show(handlers, _ctx); /*string*/
        kk_string_t _x_x491;
        kk_define_string_literal(, _s_x492, 1, "}", _ctx)
        _x_x491 = kk_string_dup(_s_x492, _ctx); /*string*/
        _x_x489 = kk_std_core_types__lp__plus__plus__rp_(_x_x490, _x_x491, _ctx); /*string*/
        _x_x486 = kk_std_core_types__lp__plus__plus__rp_(_x_x487, _x_x489, _ctx); /*string*/
        _x_x480 = kk_std_core_types__lp__plus__plus__rp_(_x_x481, _x_x486, _ctx); /*string*/
        x_2_10208 = kk_std_core_types__lp__plus__plus__rp_(_x_x478, _x_x480, _ctx); /*string*/
        goto _match_x420;
      }
    }
    if (kk_string_cmp_cstr_borrow(op_0, "profile", _ctx) == 0) {
      kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_2 = kk_Unit;
      kk_evv_set(w_2,kk_context());
      kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_integer_t x_0;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x493 = kk_src_unified__runtime__v2__as_Unified_state(state_0, _ctx);
        kk_std_core_types__list _x_3 = _con_x493->profiles;
        kk_std_core_types__list_dup(_x_3, _ctx);
        if (kk_std_core_types__is_Nil(_x_3, _ctx)) {
          x_0 = kk_integer_from_small(0); /*int*/
        }
        else {
          kk_std_core_types__list_drop(_x_3, _ctx);
          kk_std_core_types__list _x_x494;
          {
            struct kk_src_unified__runtime__v2_Unified_state* _con_x495 = kk_src_unified__runtime__v2__as_Unified_state(state_0, _ctx);
            kk_std_core_types__list _x_3_0 = _con_x495->profiles;
            kk_std_core_types__list_dup(_x_3_0, _ctx);
            _x_x494 = _x_3_0; /*list<hot_paths/path-profile>*/
          }
          x_0 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x494, kk_integer_from_small(0), _ctx); /*int*/
        }
      }
      kk_unit_t keep_3 = kk_Unit;
      kk_evv_set(w_3,kk_context());
      kk_evv_t w_4 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_4 = kk_Unit;
      kk_evv_set(w_4,kk_context());
      kk_string_t _x_x496;
      kk_define_string_literal(, _s_x497, 12, "{\"profiles\":", _ctx)
      _x_x496 = kk_string_dup(_s_x497, _ctx); /*string*/
      kk_string_t _x_x498;
      kk_string_t _x_x499 = kk_std_core_int_show(x_0, _ctx); /*string*/
      kk_string_t _x_x500;
      kk_string_t _x_x501;
      kk_define_string_literal(, _s_x502, 13, ",\"total_ops\":", _ctx)
      _x_x501 = kk_string_dup(_s_x502, _ctx); /*string*/
      kk_string_t _x_x503;
      kk_string_t _x_x504;
      kk_integer_t _x_x505;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x506 = kk_src_unified__runtime__v2__as_Unified_state(state_0, _ctx);
        kk_integer_t _x_4 = _con_x506->total_ops;
        kk_integer_dup(_x_4, _ctx);
        _x_x505 = _x_4; /*int*/
      }
      _x_x504 = kk_std_core_int_show(_x_x505, _ctx); /*string*/
      kk_string_t _x_x507;
      kk_define_string_literal(, _s_x508, 1, "}", _ctx)
      _x_x507 = kk_string_dup(_s_x508, _ctx); /*string*/
      _x_x503 = kk_std_core_types__lp__plus__plus__rp_(_x_x504, _x_x507, _ctx); /*string*/
      _x_x500 = kk_std_core_types__lp__plus__plus__rp_(_x_x501, _x_x503, _ctx); /*string*/
      _x_x498 = kk_std_core_types__lp__plus__plus__rp_(_x_x499, _x_x500, _ctx); /*string*/
      x_2_10208 = kk_std_core_types__lp__plus__plus__rp_(_x_x496, _x_x498, _ctx); /*string*/
      goto _match_x420;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_box_t _x_x509;
      kk_box_t _x_x513;
      kk_src_unified__runtime__v2__unified_state _x_x514 = kk_src_unified__runtime__v2__unified_state_dup(state_0, _ctx); /*src/unified_runtime_v2/unified-state*/
      _x_x513 = kk_src_unified__runtime__v2__unified_state_box(_x_x514, _ctx); /*10000*/
      _x_x509 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun510(_ctx), _x_x513, _ctx); /*10001*/
      x_2_10208 = kk_string_unbox(_x_x509); /*string*/
      goto _match_x420;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "hot", _ctx) == 0) {
      kk_evv_t w_3_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_3_0 = kk_Unit;
      kk_evv_set(w_3_0,kk_context());
      kk_std_core_types__list x_5_10216;
      kk_std_core_types__list _x_x515;
      {
        struct kk_src_unified__runtime__v2_Unified_state* _con_x516 = kk_src_unified__runtime__v2__as_Unified_state(state_0, _ctx);
        kk_std_core_types__list _x_5 = _con_x516->profiles;
        kk_std_core_types__list_dup(_x_5, _ctx);
        _x_x515 = _x_5; /*list<hot_paths/path-profile>*/
      }
      x_5_10216 = kk_src_unified__runtime__v2__lift_server_loop_10140(_x_x515, _ctx); /*list<hot_paths/path-profile>*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__list_drop(x_5_10216, _ctx);
        kk_box_t _x_x517 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun518(_ctx), _ctx); /*10001*/
        x_2_10208 = kk_string_unbox(_x_x517); /*string*/
        goto _match_x420;
      }
      {
        x_2_10208 = kk_src_unified__runtime__v2__mlift_server_loop_10195(x_5_10216, _ctx); /*string*/
        goto _match_x420;
      }
    }
    if (kk_string_cmp_cstr_borrow(op_0, "quit", _ctx) == 0) {
      kk_define_string_literal(, _s_x521, 20, "{\"status\":\"stopped\"}", _ctx)
      x_2_10208 = kk_string_dup(_s_x521, _ctx); /*string*/
      goto _match_x420;
    }
    {
      kk_define_string_literal(, _s_x522, 22, "{\"error\":\"unknown op\"}", _ctx)
      x_2_10208 = kk_string_dup(_s_x522, _ctx); /*string*/
    }
    _match_x420: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_2_10208, _ctx);
      kk_box_t _x_x523 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2__new_mlift_server_loop_10197_fun524(line_0, op_0, state_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x523); return kk_Unit;
    }
    {
      kk_src_unified__runtime__v2__mlift_server_loop_10196(line_0, op_0, state_0, x_2_10208, _ctx); return kk_Unit;
    }
  }
  {
    kk_datatype_ptr_dropn(state_0, (KK_I32(3)), _ctx);
    kk_string_drop(line_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun527__t {
  struct kk_function_s _base;
  kk_src_unified__runtime__v2__unified_state state_2;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun527(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun527(kk_src_unified__runtime__v2__unified_state state_2, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2_server_loop_fun527__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v2_server_loop_fun527__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v2_server_loop_fun527, kk_context());
  _self->state_2 = state_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun527(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2_server_loop_fun527__t* _self = kk_function_as(struct kk_src_unified__runtime__v2_server_loop_fun527__t*, _fself, _ctx);
  kk_src_unified__runtime__v2__unified_state state_2 = _self->state_2; /* src/unified_runtime_v2/unified-state */
  kk_drop_match(_self, {kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx);}, {}, _ctx)
  kk_string_t line_1_210 = kk_string_unbox(_b_x118); /*string*/;
  kk_unit_t _x_x528 = kk_Unit;
  kk_src_unified__runtime__v2__mlift_server_loop_10197(state_2, line_1_210, _ctx);
  return kk_unit_box(_x_x528);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun533__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun533(kk_function_t _fself, kk_box_t _b_x121, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun533(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun533, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun533(kk_function_t _fself, kk_box_t _b_x121, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x534;
  kk_string_t _x_x535 = kk_string_unbox(_b_x121); /*string*/
  _x_x534 = kk_src_unified__runtime__v2_extract_op(_x_x535, _ctx); /*string*/
  return kk_string_box(_x_x534);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun540__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun540(kk_function_t _fself, kk_box_t _b_x126, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun540(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun540, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun540(kk_function_t _fself, kk_box_t _b_x126, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x541;
  kk_string_t _x_x542 = kk_string_unbox(_b_x126); /*string*/
  _x_x541 = kk_src_unified__runtime__v2_extract_event_type(_x_x542, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x541, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun568__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun568(kk_function_t _fself, kk_box_t _b_x139, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun568(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun568, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun568(kk_function_t _fself, kk_box_t _b_x139, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x569;
  kk_gan__ying__event_type _x_x570 = kk_gan__ying__event_type_unbox(_b_x139, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x569 = kk_gan__ying_event_type_to_string(_x_x570, _ctx); /*string*/
  return kk_string_box(_x_x569);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun577__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun577(kk_function_t _fself, kk_box_t _b_x142, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun577(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun577, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun577(kk_function_t _fself, kk_box_t _b_x142, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x578;
  kk_src_unified__runtime__v2__unified_state _x_x579 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x142, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x578 = kk_src_unified__runtime__v2_json_state(_x_x579, _ctx); /*string*/
  return kk_string_box(_x_x578);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun583__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun583(kk_function_t _fself, kk_box_t _b_x145, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun583(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun583, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun583(kk_function_t _fself, kk_box_t _b_x145, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x584;
  kk_string_t _x_x585 = kk_string_unbox(_b_x145); /*string*/
  _x_x584 = kk_src_unified__runtime__v2_extract_event_type(_x_x585, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x584, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun589__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun589(kk_function_t _fself, kk_box_t _b_x151, kk_box_t _b_x152, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun589(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun589, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun589(kk_function_t _fself, kk_box_t _b_x151, kk_box_t _b_x152, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x590;
  kk_gan__ying__event_type _x_x591 = kk_gan__ying__event_type_unbox(_b_x151, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v2__unified_state _x_x592 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x152, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x590 = kk_src_unified__runtime__v2_cascade_profiled(_x_x591, _x_x592, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x590, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun601__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun601(kk_function_t _fself, kk_box_t _b_x157, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun601(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun601, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun601(kk_function_t _fself, kk_box_t _b_x157, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x602;
  kk_gan__ying__event_type _x_x603 = kk_gan__ying__event_type_unbox(_b_x157, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x602 = kk_gan__ying_event_type_to_string(_x_x603, _ctx); /*string*/
  return kk_string_box(_x_x602);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun628__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun628(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun628(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun628, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun628(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x629;
  kk_src_unified__runtime__v2__unified_state _x_x630 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x160, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x629 = kk_src_unified__runtime__v2_json_state(_x_x630, _ctx); /*string*/
  return kk_string_box(_x_x629);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun636__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun636(kk_function_t _fself, kk_box_t _b_x162, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun636(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun636, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun636(kk_function_t _fself, kk_box_t _b_x162, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x637;
  kk_std_core_types__list _x_x638 = kk_std_core_types__list_unbox(_b_x162, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
  _x_x637 = kk_src_unified__runtime__v2__mlift_server_loop_10195(_x_x638, _ctx); /*string*/
  return kk_string_box(_x_x637);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun642__t {
  struct kk_function_s _base;
  kk_string_t op_1;
  kk_src_unified__runtime__v2__unified_state state_2;
  kk_string_t x_7_10220;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun642(kk_function_t _fself, kk_box_t _b_x176, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun642(kk_string_t op_1, kk_src_unified__runtime__v2__unified_state state_2, kk_string_t x_7_10220, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2_server_loop_fun642__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v2_server_loop_fun642__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v2_server_loop_fun642, kk_context());
  _self->op_1 = op_1;
  _self->state_2 = state_2;
  _self->x_7_10220 = x_7_10220;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun642(kk_function_t _fself, kk_box_t _b_x176, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2_server_loop_fun642__t* _self = kk_function_as(struct kk_src_unified__runtime__v2_server_loop_fun642__t*, _fself, _ctx);
  kk_string_t op_1 = _self->op_1; /* string */
  kk_src_unified__runtime__v2__unified_state state_2 = _self->state_2; /* src/unified_runtime_v2/unified-state */
  kk_string_t x_7_10220 = _self->x_7_10220; /* string */
  kk_drop_match(_self, {kk_string_dup(op_1, _ctx);kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx);kk_string_dup(x_7_10220, _ctx);}, {}, _ctx)
  kk_string_t _c_x10146_1_211 = kk_string_unbox(_b_x176); /*string*/;
  kk_unit_t _x_x643 = kk_Unit;
  kk_src_unified__runtime__v2__mlift_server_loop_10196(x_7_10220, op_1, state_2, _c_x10146_1_211, _ctx);
  return kk_unit_box(_x_x643);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun649__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun649(kk_function_t _fself, kk_box_t _b_x179, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun649(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun649, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun649(kk_function_t _fself, kk_box_t _b_x179, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x650;
  kk_string_t _x_x651 = kk_string_unbox(_b_x179); /*string*/
  _x_x650 = kk_src_unified__runtime__v2_extract_event_type(_x_x651, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x650, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun671__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun671(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun671(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun671, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun671(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x672;
  kk_string_t _x_x673 = kk_string_unbox(_b_x192); /*string*/
  _x_x672 = kk_src_unified__runtime__v2_extract_event_type(_x_x673, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x672, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun675__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun675(kk_function_t _fself, kk_box_t _b_x198, kk_box_t _b_x199, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun675(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun675, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun675(kk_function_t _fself, kk_box_t _b_x198, kk_box_t _b_x199, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x676;
  kk_gan__ying__event_type _x_x677 = kk_gan__ying__event_type_unbox(_b_x198, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v2__unified_state _x_x678 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x199, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  _x_x676 = kk_src_unified__runtime__v2_cascade_profiled(_x_x677, _x_x678, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x676, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2_server_loop_fun681__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2_server_loop_fun681(kk_function_t _fself, kk_box_t _b_x206, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2_new_server_loop_fun681(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2_server_loop_fun681, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2_server_loop_fun681(kk_function_t _fself, kk_box_t _b_x206, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x682 = kk_Unit;
  kk_src_unified__runtime__v2__unified_state _x_x683 = kk_src_unified__runtime__v2__unified_state_unbox(_b_x206, KK_OWNED, _ctx); /*src/unified_runtime_v2/unified-state*/
  kk_src_unified__runtime__v2_server_loop(_x_x683, _ctx);
  return kk_unit_box(_x_x682);
}

kk_unit_t kk_src_unified__runtime__v2_server_loop(kk_src_unified__runtime__v2__unified_state state_2, kk_context_t* _ctx) { /* (state : unified-state) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_7_10220 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_7_10220, _ctx);
    kk_box_t _x_x526 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2_new_server_loop_fun527(state_2, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x526); return kk_Unit;
  }
  {
    bool _match_x213;
    kk_string_t _x_x529 = kk_string_dup(x_7_10220, _ctx); /*string*/
    kk_string_t _x_x530 = kk_string_empty(); /*string*/
    _match_x213 = kk_string_is_neq(_x_x529,_x_x530,kk_context()); /*bool*/
    if (_match_x213) {
      kk_string_t op_1;
      kk_box_t _x_x532;
      kk_box_t _x_x536;
      kk_string_t _x_x537 = kk_string_dup(x_7_10220, _ctx); /*string*/
      _x_x536 = kk_string_box(_x_x537); /*10000*/
      _x_x532 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun533(_ctx), _x_x536, _ctx); /*10001*/
      op_1 = kk_string_unbox(_x_x532); /*string*/
      kk_string_t x_8_10223;
      if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
        kk_gan__ying__event_type et_3;
        kk_box_t _x_x539;
        kk_box_t _x_x543;
        kk_string_t _x_x544 = kk_string_dup(x_7_10220, _ctx); /*string*/
        _x_x543 = kk_string_box(_x_x544); /*10000*/
        _x_x539 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun540(_ctx), _x_x543, _ctx); /*10001*/
        et_3 = kk_gan__ying__event_type_unbox(_x_x539, KK_OWNED, _ctx); /*gan_ying/event-type*/
        kk_evv_t w_4_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_hot__paths__path_profile profile_1;
        kk_string_t _x_x545 = kk_gan__ying_event_type_to_string(et_3, _ctx); /*string*/
        profile_1 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x545, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
        kk_src_unified__runtime__v2__unified_state x_9;
        kk_std_core_types__list _x_x546;
        kk_box_t _x_x547;
        kk_gan__ying__resonance_event _x_x548;
        kk_string_t _x_x549;
        kk_define_string_literal(, _s_x550, 15, "unified_runtime", _ctx)
        _x_x549 = kk_string_dup(_s_x550, _ctx); /*string*/
        kk_string_t _x_x551 = kk_string_empty(); /*string*/
        _x_x548 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x549, et_3, _x_x551, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
        _x_x547 = kk_gan__ying__resonance_event_box(_x_x548, _ctx); /*10021*/
        kk_std_core_types__list _x_x553;
        {
          struct kk_src_unified__runtime__v2_Unified_state* _con_x554 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
          kk_std_core_types__list _x_6 = _con_x554->events;
          kk_std_core_types__list_dup(_x_6, _ctx);
          _x_x553 = _x_6; /*list<gan_ying/resonance-event>*/
        }
        _x_x546 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x547, _x_x553, _ctx); /*list<10021>*/
        kk_std_core_types__list _x_x555;
        kk_std_core_types__list _x_x556;
        {
          struct kk_src_unified__runtime__v2_Unified_state* _con_x557 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
          kk_std_core_types__list _x_0_0 = _con_x557->profiles;
          kk_std_core_types__list_dup(_x_0_0, _ctx);
          _x_x556 = _x_0_0; /*list<hot_paths/path-profile>*/
        }
        _x_x555 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_1, _ctx), _x_x556, _ctx); /*list<10021>*/
        kk_integer_t _x_x558;
        kk_integer_t _x_x559;
        {
          struct kk_src_unified__runtime__v2_Unified_state* _con_x560 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
          kk_integer_t _x_1_0 = _con_x560->total_ops;
          kk_integer_dup(_x_1_0, _ctx);
          _x_x559 = _x_1_0; /*int*/
        }
        _x_x558 = kk_integer_add_small_const(_x_x559, 1, _ctx); /*int*/
        double _x_x561;
        {
          struct kk_src_unified__runtime__v2_Unified_state* _con_x562 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
          double _x_2_0 = _con_x562->session_start;
          _x_x561 = _x_2_0; /*float64*/
        }
        x_9 = kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x546, _x_x555, _x_x558, _x_x561, _ctx); /*src/unified_runtime_v2/unified-state*/
        kk_unit_t keep_4_0 = kk_Unit;
        kk_evv_set(w_4_0,kk_context());
        kk_string_t _x_x563;
        kk_define_string_literal(, _s_x564, 12, "{\"emitted\":\"", _ctx)
        _x_x563 = kk_string_dup(_s_x564, _ctx); /*string*/
        kk_string_t _x_x565;
        kk_string_t _x_x566;
        kk_box_t _x_x567 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun568(_ctx), kk_gan__ying__event_type_box(et_3, _ctx), _ctx); /*10001*/
        _x_x566 = kk_string_unbox(_x_x567); /*string*/
        kk_string_t _x_x571;
        kk_string_t _x_x572;
        kk_define_string_literal(, _s_x573, 10, "\",\"state\":", _ctx)
        _x_x572 = kk_string_dup(_s_x573, _ctx); /*string*/
        kk_string_t _x_x574;
        kk_string_t _x_x575;
        kk_box_t _x_x576 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun577(_ctx), kk_src_unified__runtime__v2__unified_state_box(x_9, _ctx), _ctx); /*10001*/
        _x_x575 = kk_string_unbox(_x_x576); /*string*/
        kk_string_t _x_x580;
        kk_define_string_literal(, _s_x581, 1, "}", _ctx)
        _x_x580 = kk_string_dup(_s_x581, _ctx); /*string*/
        _x_x574 = kk_std_core_types__lp__plus__plus__rp_(_x_x575, _x_x580, _ctx); /*string*/
        _x_x571 = kk_std_core_types__lp__plus__plus__rp_(_x_x572, _x_x574, _ctx); /*string*/
        _x_x565 = kk_std_core_types__lp__plus__plus__rp_(_x_x566, _x_x571, _ctx); /*string*/
        x_8_10223 = kk_std_core_types__lp__plus__plus__rp_(_x_x563, _x_x565, _ctx); /*string*/
        goto _match_x538;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
        kk_gan__ying__event_type et_0_0_0;
        kk_box_t _x_x582;
        kk_box_t _x_x586;
        kk_string_t _x_x587 = kk_string_dup(x_7_10220, _ctx); /*string*/
        _x_x586 = kk_string_box(_x_x587); /*10000*/
        _x_x582 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun583(_ctx), _x_x586, _ctx); /*10001*/
        et_0_0_0 = kk_gan__ying__event_type_unbox(_x_x582, KK_OWNED, _ctx); /*gan_ying/event-type*/
        kk_std_core_types__tuple2 _match_x219;
        kk_box_t _x_x588;
        kk_box_t _x_x593;
        kk_src_unified__runtime__v2__unified_state _x_x594 = kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx); /*src/unified_runtime_v2/unified-state*/
        _x_x593 = kk_src_unified__runtime__v2__unified_state_box(_x_x594, _ctx); /*10001*/
        _x_x588 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v2_new_server_loop_fun589(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _x_x593, _ctx); /*10002*/
        _match_x219 = kk_std_core_types__tuple2_unbox(_x_x588, KK_OWNED, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
        {
          kk_box_t _box_x153 = _match_x219.fst;
          kk_box_t _box_x154 = _match_x219.snd;
          kk_src_unified__runtime__v2__unified_state _pat_3_0_0 = kk_src_unified__runtime__v2__unified_state_unbox(_box_x154, KK_BORROWED, _ctx);
          struct kk_src_unified__runtime__v2_Unified_state* _con_x595 = kk_src_unified__runtime__v2__as_Unified_state(_pat_3_0_0, _ctx);
          kk_integer_t handlers_0 = kk_integer_unbox(_box_x153, _ctx);
          kk_integer_dup(handlers_0, _ctx);
          kk_std_core_types__tuple2_drop(_match_x219, _ctx);
          kk_string_t _x_x596;
          kk_define_string_literal(, _s_x597, 12, "{\"cascade\":\"", _ctx)
          _x_x596 = kk_string_dup(_s_x597, _ctx); /*string*/
          kk_string_t _x_x598;
          kk_string_t _x_x599;
          kk_box_t _x_x600 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun601(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _ctx); /*10001*/
          _x_x599 = kk_string_unbox(_x_x600); /*string*/
          kk_string_t _x_x604;
          kk_string_t _x_x605;
          kk_define_string_literal(, _s_x606, 13, "\",\"handlers\":", _ctx)
          _x_x605 = kk_string_dup(_s_x606, _ctx); /*string*/
          kk_string_t _x_x607;
          kk_string_t _x_x608 = kk_std_core_int_show(handlers_0, _ctx); /*string*/
          kk_string_t _x_x609;
          kk_define_string_literal(, _s_x610, 1, "}", _ctx)
          _x_x609 = kk_string_dup(_s_x610, _ctx); /*string*/
          _x_x607 = kk_std_core_types__lp__plus__plus__rp_(_x_x608, _x_x609, _ctx); /*string*/
          _x_x604 = kk_std_core_types__lp__plus__plus__rp_(_x_x605, _x_x607, _ctx); /*string*/
          _x_x598 = kk_std_core_types__lp__plus__plus__rp_(_x_x599, _x_x604, _ctx); /*string*/
          x_8_10223 = kk_std_core_types__lp__plus__plus__rp_(_x_x596, _x_x598, _ctx); /*string*/
          goto _match_x538;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_1, "profile", _ctx) == 0) {
        kk_evv_t w_5 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_5 = kk_Unit;
        kk_evv_set(w_5,kk_context());
        kk_evv_t w_6 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_integer_t x_5;
        {
          struct kk_src_unified__runtime__v2_Unified_state* _con_x611 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
          kk_std_core_types__list _x_3_0_0 = _con_x611->profiles;
          kk_std_core_types__list_dup(_x_3_0_0, _ctx);
          if (kk_std_core_types__is_Nil(_x_3_0_0, _ctx)) {
            x_5 = kk_integer_from_small(0); /*int*/
          }
          else {
            kk_std_core_types__list_drop(_x_3_0_0, _ctx);
            kk_std_core_types__list _x_x612;
            {
              struct kk_src_unified__runtime__v2_Unified_state* _con_x613 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
              kk_std_core_types__list _x_3_0_1 = _con_x613->profiles;
              kk_std_core_types__list_dup(_x_3_0_1, _ctx);
              _x_x612 = _x_3_0_1; /*list<hot_paths/path-profile>*/
            }
            x_5 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x612, kk_integer_from_small(0), _ctx); /*int*/
          }
        }
        kk_unit_t keep_6 = kk_Unit;
        kk_evv_set(w_6,kk_context());
        kk_evv_t w_7 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_7 = kk_Unit;
        kk_evv_set(w_7,kk_context());
        kk_string_t _x_x614;
        kk_define_string_literal(, _s_x615, 12, "{\"profiles\":", _ctx)
        _x_x614 = kk_string_dup(_s_x615, _ctx); /*string*/
        kk_string_t _x_x616;
        kk_string_t _x_x617 = kk_std_core_int_show(x_5, _ctx); /*string*/
        kk_string_t _x_x618;
        kk_string_t _x_x619;
        kk_define_string_literal(, _s_x620, 13, ",\"total_ops\":", _ctx)
        _x_x619 = kk_string_dup(_s_x620, _ctx); /*string*/
        kk_string_t _x_x621;
        kk_string_t _x_x622;
        kk_integer_t _x_x623;
        {
          struct kk_src_unified__runtime__v2_Unified_state* _con_x624 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
          kk_integer_t _x_4_0 = _con_x624->total_ops;
          kk_integer_dup(_x_4_0, _ctx);
          _x_x623 = _x_4_0; /*int*/
        }
        _x_x622 = kk_std_core_int_show(_x_x623, _ctx); /*string*/
        kk_string_t _x_x625;
        kk_define_string_literal(, _s_x626, 1, "}", _ctx)
        _x_x625 = kk_string_dup(_s_x626, _ctx); /*string*/
        _x_x621 = kk_std_core_types__lp__plus__plus__rp_(_x_x622, _x_x625, _ctx); /*string*/
        _x_x618 = kk_std_core_types__lp__plus__plus__rp_(_x_x619, _x_x621, _ctx); /*string*/
        _x_x616 = kk_std_core_types__lp__plus__plus__rp_(_x_x617, _x_x618, _ctx); /*string*/
        x_8_10223 = kk_std_core_types__lp__plus__plus__rp_(_x_x614, _x_x616, _ctx); /*string*/
        goto _match_x538;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
        kk_box_t _x_x627;
        kk_box_t _x_x631;
        kk_src_unified__runtime__v2__unified_state _x_x632 = kk_src_unified__runtime__v2__unified_state_dup(state_2, _ctx); /*src/unified_runtime_v2/unified-state*/
        _x_x631 = kk_src_unified__runtime__v2__unified_state_box(_x_x632, _ctx); /*10000*/
        _x_x627 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun628(_ctx), _x_x631, _ctx); /*10001*/
        x_8_10223 = kk_string_unbox(_x_x627); /*string*/
        goto _match_x538;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "hot", _ctx) == 0) {
        kk_evv_t w_6_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_6_0 = kk_Unit;
        kk_evv_set(w_6_0,kk_context());
        kk_std_core_types__list x_11_10232;
        kk_std_core_types__list _x_x633;
        {
          struct kk_src_unified__runtime__v2_Unified_state* _con_x634 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
          kk_std_core_types__list _x_5_0 = _con_x634->profiles;
          kk_std_core_types__list_dup(_x_5_0, _ctx);
          _x_x633 = _x_5_0; /*list<hot_paths/path-profile>*/
        }
        x_11_10232 = kk_src_unified__runtime__v2__lift_server_loop_10140(_x_x633, _ctx); /*list<hot_paths/path-profile>*/
        if (kk_yielding(kk_context())) {
          kk_std_core_types__list_drop(x_11_10232, _ctx);
          kk_box_t _x_x635 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2_new_server_loop_fun636(_ctx), _ctx); /*10001*/
          x_8_10223 = kk_string_unbox(_x_x635); /*string*/
          goto _match_x538;
        }
        {
          x_8_10223 = kk_src_unified__runtime__v2__mlift_server_loop_10195(x_11_10232, _ctx); /*string*/
          goto _match_x538;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_1, "quit", _ctx) == 0) {
        kk_define_string_literal(, _s_x639, 20, "{\"status\":\"stopped\"}", _ctx)
        x_8_10223 = kk_string_dup(_s_x639, _ctx); /*string*/
        goto _match_x538;
      }
      {
        kk_define_string_literal(, _s_x640, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_8_10223 = kk_string_dup(_s_x640, _ctx); /*string*/
      }
      _match_x538: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_8_10223, _ctx);
        kk_box_t _x_x641 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2_new_server_loop_fun642(op_1, state_2, x_7_10220, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x641); return kk_Unit;
      }
      {
        kk_unit_t ___0 = kk_Unit;
        kk_std_core_console_printsln(x_8_10223, _ctx);
        bool _match_x215;
        kk_string_t _x_x644 = kk_string_dup(op_1, _ctx); /*string*/
        kk_string_t _x_x645;
        kk_define_string_literal(, _s_x646, 4, "quit", _ctx)
        _x_x645 = kk_string_dup(_s_x646, _ctx); /*string*/
        _match_x215 = kk_string_is_neq(_x_x644,_x_x645,kk_context()); /*bool*/
        if (_match_x215) {
          kk_src_unified__runtime__v2__unified_state x_13_10236;
          if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_gan__ying__event_type et_1_0;
            kk_box_t _x_x648 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun649(_ctx), kk_string_box(x_7_10220), _ctx); /*10001*/
            et_1_0 = kk_gan__ying__event_type_unbox(_x_x648, KK_OWNED, _ctx); /*gan_ying/event-type*/
            kk_evv_t w_7_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_hot__paths__path_profile profile_0_0;
            kk_string_t _x_x652 = kk_gan__ying_event_type_to_string(et_1_0, _ctx); /*string*/
            profile_0_0 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x652, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
            kk_src_unified__runtime__v2__unified_state x_14;
            kk_std_core_types__list _x_x653;
            kk_box_t _x_x654;
            kk_gan__ying__resonance_event _x_x655;
            kk_string_t _x_x656;
            kk_define_string_literal(, _s_x657, 15, "unified_runtime", _ctx)
            _x_x656 = kk_string_dup(_s_x657, _ctx); /*string*/
            kk_string_t _x_x658 = kk_string_empty(); /*string*/
            _x_x655 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x656, et_1_0, _x_x658, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
            _x_x654 = kk_gan__ying__resonance_event_box(_x_x655, _ctx); /*10021*/
            kk_std_core_types__list _x_x660;
            {
              struct kk_src_unified__runtime__v2_Unified_state* _con_x661 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
              kk_std_core_types__list _x_7_0 = _con_x661->events;
              kk_std_core_types__list_dup(_x_7_0, _ctx);
              _x_x660 = _x_7_0; /*list<gan_ying/resonance-event>*/
            }
            _x_x653 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x654, _x_x660, _ctx); /*list<10021>*/
            kk_std_core_types__list _x_x662;
            kk_std_core_types__list _x_x663;
            {
              struct kk_src_unified__runtime__v2_Unified_state* _con_x664 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
              kk_std_core_types__list _x_8_0 = _con_x664->profiles;
              kk_std_core_types__list_dup(_x_8_0, _ctx);
              _x_x663 = _x_8_0; /*list<hot_paths/path-profile>*/
            }
            _x_x662 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_0_0, _ctx), _x_x663, _ctx); /*list<10021>*/
            kk_integer_t _x_x665;
            kk_integer_t _x_x666;
            {
              struct kk_src_unified__runtime__v2_Unified_state* _con_x667 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
              kk_integer_t _x_9_0 = _con_x667->total_ops;
              kk_integer_dup(_x_9_0, _ctx);
              _x_x666 = _x_9_0; /*int*/
            }
            _x_x665 = kk_integer_add_small_const(_x_x666, 1, _ctx); /*int*/
            double _x_x668;
            {
              struct kk_src_unified__runtime__v2_Unified_state* _con_x669 = kk_src_unified__runtime__v2__as_Unified_state(state_2, _ctx);
              kk_std_core_types__list _pat_0_11_0 = _con_x669->events;
              kk_std_core_types__list _pat_1_14_0 = _con_x669->profiles;
              kk_integer_t _pat_2_11_0 = _con_x669->total_ops;
              double _x_10_0 = _con_x669->session_start;
              if kk_likely(kk_datatype_ptr_is_unique(state_2, _ctx)) {
                kk_integer_drop(_pat_2_11_0, _ctx);
                kk_std_core_types__list_drop(_pat_1_14_0, _ctx);
                kk_std_core_types__list_drop(_pat_0_11_0, _ctx);
                kk_datatype_ptr_free(state_2, _ctx);
              }
              else {
                kk_datatype_ptr_decref(state_2, _ctx);
              }
              _x_x668 = _x_10_0; /*float64*/
            }
            x_14 = kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, _x_x653, _x_x662, _x_x665, _x_x668, _ctx); /*src/unified_runtime_v2/unified-state*/
            kk_unit_t keep_7_0 = kk_Unit;
            kk_evv_set(w_7_0,kk_context());
            x_13_10236 = x_14; /*src/unified_runtime_v2/unified-state*/
            goto _match_x647;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_gan__ying__event_type et_2_0_0;
            kk_box_t _x_x670 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v2_new_server_loop_fun671(_ctx), kk_string_box(x_7_10220), _ctx); /*10001*/
            et_2_0_0 = kk_gan__ying__event_type_unbox(_x_x670, KK_OWNED, _ctx); /*gan_ying/event-type*/
            kk_std_core_types__tuple2 _match_x217;
            kk_box_t _x_x674 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v2_new_server_loop_fun675(_ctx), kk_gan__ying__event_type_box(et_2_0_0, _ctx), kk_src_unified__runtime__v2__unified_state_box(state_2, _ctx), _ctx); /*10002*/
            _match_x217 = kk_std_core_types__tuple2_unbox(_x_x674, KK_OWNED, _ctx); /*(int, src/unified_runtime_v2/unified-state)*/
            {
              kk_box_t _box_x200 = _match_x217.fst;
              kk_box_t _box_x201 = _match_x217.snd;
              kk_src_unified__runtime__v2__unified_state ns_0 = kk_src_unified__runtime__v2__unified_state_unbox(_box_x201, KK_BORROWED, _ctx);
              struct kk_src_unified__runtime__v2_Unified_state* _con_x679 = kk_src_unified__runtime__v2__as_Unified_state(ns_0, _ctx);
              kk_src_unified__runtime__v2__unified_state_dup(ns_0, _ctx);
              kk_std_core_types__tuple2_drop(_match_x217, _ctx);
              x_13_10236 = ns_0; /*src/unified_runtime_v2/unified-state*/
              goto _match_x647;
            }
          }
          {
            kk_string_drop(x_7_10220, _ctx);
            kk_string_drop(op_1, _ctx);
            x_13_10236 = state_2; /*src/unified_runtime_v2/unified-state*/
          }
          _match_x647: ;
          if (kk_yielding(kk_context())) {
            kk_datatype_ptr_dropn(x_13_10236, (KK_I32(3)), _ctx);
            kk_box_t _x_x680 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v2_new_server_loop_fun681(_ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x680); return kk_Unit;
          }
          { // tailcall
            state_2 = x_13_10236;
            goto kk__tailcall;
          }
        }
        {
          kk_string_drop(x_7_10220, _ctx);
          kk_datatype_ptr_dropn(state_2, (KK_I32(3)), _ctx);
          kk_string_drop(op_1, _ctx);
          kk_Unit; return kk_Unit;
        }
      }
    }
    {
      kk_string_drop(x_7_10220, _ctx);
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
