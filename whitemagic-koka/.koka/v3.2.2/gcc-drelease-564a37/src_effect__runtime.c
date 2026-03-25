// Koka generated module: src/effect_runtime, koka version: 3.2.2, platform: 64-bit
#include "src_effect__runtime.h"

kk_src_effect__runtime__runtime_state kk_src_effect__runtime_runtime_state_fs__copy(kk_src_effect__runtime__runtime_state _this, kk_std_core_types__optional events, kk_std_core_types__optional profiles, kk_std_core_types__optional total_ops, kk_context_t* _ctx) { /* (runtime-state, events : ? (list<gan_ying/resonance-event>), profiles : ? (list<hot_paths/path-profile>), total-ops : ? int) -> runtime-state */ 
  kk_std_core_types__list _x_x266;
  if (kk_std_core_types__is_Optional(events, _ctx)) {
    kk_box_t _box_x8 = events._cons._Optional.value;
    kk_std_core_types__list _uniq_events_178 = kk_std_core_types__list_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_events_178, _ctx);
    kk_std_core_types__optional_drop(events, _ctx);
    _x_x266 = _uniq_events_178; /*list<gan_ying/resonance-event>*/
  }
  else {
    kk_std_core_types__optional_drop(events, _ctx);
    {
      struct kk_src_effect__runtime_Runtime_state* _con_x267 = kk_src_effect__runtime__as_Runtime_state(_this, _ctx);
      kk_std_core_types__list _x = _con_x267->events;
      kk_std_core_types__list_dup(_x, _ctx);
      _x_x266 = _x; /*list<gan_ying/resonance-event>*/
    }
  }
  kk_std_core_types__list _x_x268;
  if (kk_std_core_types__is_Optional(profiles, _ctx)) {
    kk_box_t _box_x9 = profiles._cons._Optional.value;
    kk_std_core_types__list _uniq_profiles_186 = kk_std_core_types__list_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_profiles_186, _ctx);
    kk_std_core_types__optional_drop(profiles, _ctx);
    _x_x268 = _uniq_profiles_186; /*list<hot_paths/path-profile>*/
  }
  else {
    kk_std_core_types__optional_drop(profiles, _ctx);
    {
      struct kk_src_effect__runtime_Runtime_state* _con_x269 = kk_src_effect__runtime__as_Runtime_state(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x269->profiles;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x268 = _x_0; /*list<hot_paths/path-profile>*/
    }
  }
  kk_integer_t _x_x270;
  if (kk_std_core_types__is_Optional(total_ops, _ctx)) {
    kk_box_t _box_x10 = total_ops._cons._Optional.value;
    kk_integer_t _uniq_total_ops_194 = kk_integer_unbox(_box_x10, _ctx);
    kk_integer_dup(_uniq_total_ops_194, _ctx);
    kk_std_core_types__optional_drop(total_ops, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x270 = _uniq_total_ops_194; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(total_ops, _ctx);
    {
      struct kk_src_effect__runtime_Runtime_state* _con_x271 = kk_src_effect__runtime__as_Runtime_state(_this, _ctx);
      kk_std_core_types__list _pat_0_2 = _con_x271->events;
      kk_std_core_types__list _pat_1_3 = _con_x271->profiles;
      kk_integer_t _x_1 = _con_x271->total_ops;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_std_core_types__list_drop(_pat_1_3, _ctx);
        kk_std_core_types__list_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x270 = _x_1; /*int*/
    }
  }
  return kk_src_effect__runtime__new_Runtime_state(kk_reuse_null, 0, _x_x266, _x_x268, _x_x270, _ctx);
}
 
// Emit with automatic profiling

kk_src_effect__runtime__runtime_state kk_src_effect__runtime_emit_profiled(kk_string_t source, kk_gan__ying__event_type et, kk_src_effect__runtime__runtime_state state, kk_context_t* _ctx) { /* (source : string, et : gan_ying/event-type, state : runtime-state) -> runtime-state */ 
  kk_string_t name_10003;
  kk_string_t _x_x272;
  kk_define_string_literal(, _s_x273, 5, "emit_", _ctx)
  _x_x272 = kk_string_dup(_s_x273, _ctx); /*string*/
  kk_string_t _x_x274 = kk_gan__ying_event_type_to_string(et, _ctx); /*string*/
  name_10003 = kk_std_core_types__lp__plus__plus__rp_(_x_x272, _x_x274, _ctx); /*string*/
  kk_std_core_types__list _x_x275;
  kk_box_t _x_x276;
  kk_gan__ying__resonance_event _x_x277;
  kk_string_t _x_x278 = kk_string_empty(); /*string*/
  _x_x277 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, source, et, _x_x278, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x276 = kk_gan__ying__resonance_event_box(_x_x277, _ctx); /*10021*/
  kk_std_core_types__list _x_x280;
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x281 = kk_src_effect__runtime__as_Runtime_state(state, _ctx);
    kk_std_core_types__list _x = _con_x281->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x280 = _x; /*list<gan_ying/resonance-event>*/
  }
  _x_x275 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x276, _x_x280, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x282;
  kk_box_t _x_x283;
  kk_hot__paths__path_profile _x_x284 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, name_10003, kk_integer_from_small(1), 0x1.0624dd2f1a9fcp-10, 0x1.0624dd2f1a9fcp-10, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_Compute(_ctx), _ctx); /*hot_paths/path-profile*/
  _x_x283 = kk_hot__paths__path_profile_box(_x_x284, _ctx); /*10021*/
  kk_std_core_types__list _x_x285;
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x286 = kk_src_effect__runtime__as_Runtime_state(state, _ctx);
    kk_std_core_types__list _x_0 = _con_x286->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x285 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x282 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x283, _x_x285, _ctx); /*list<10021>*/
  kk_integer_t _x_x287;
  kk_integer_t _x_x288;
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x289 = kk_src_effect__runtime__as_Runtime_state(state, _ctx);
    kk_std_core_types__list _pat_0_1 = _con_x289->events;
    kk_std_core_types__list _pat_1_1 = _con_x289->profiles;
    kk_integer_t _x_1 = _con_x289->total_ops;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_std_core_types__list_drop(_pat_1_1, _ctx);
      kk_std_core_types__list_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_integer_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x288 = _x_1; /*int*/
  }
  _x_x287 = kk_integer_add_small_const(_x_x288, 1, _ctx); /*int*/
  return kk_src_effect__runtime__new_Runtime_state(kk_reuse_null, 0, _x_x275, _x_x282, _x_x287, _ctx);
}
 
// Cascade check with profiling

kk_std_core_types__tuple2 kk_src_effect__runtime_cascade_profiled(kk_gan__ying__event_type et, kk_src_effect__runtime__runtime_state state, kk_context_t* _ctx) { /* (et : gan_ying/event-type, state : runtime-state) -> (int, runtime-state) */ 
  kk_src_effect__runtime__runtime_state _b_x22_24;
  kk_std_core_types__list _x_x290;
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x291 = kk_src_effect__runtime__as_Runtime_state(state, _ctx);
    kk_std_core_types__list _x_0 = _con_x291->events;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x290 = _x_0; /*list<gan_ying/resonance-event>*/
  }
  kk_std_core_types__list _x_x292;
  kk_box_t _x_x293;
  kk_hot__paths__path_profile _x_x294;
  kk_string_t _x_x295;
  kk_define_string_literal(, _s_x296, 13, "cascade_check", _ctx)
  _x_x295 = kk_string_dup(_s_x296, _ctx); /*string*/
  _x_x294 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x295, kk_integer_from_small(1), 0x1.0624dd2f1a9fcp-11, 0x1.0624dd2f1a9fcp-11, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_Compute(_ctx), _ctx); /*hot_paths/path-profile*/
  _x_x293 = kk_hot__paths__path_profile_box(_x_x294, _ctx); /*10021*/
  kk_std_core_types__list _x_x297;
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x298 = kk_src_effect__runtime__as_Runtime_state(state, _ctx);
    kk_std_core_types__list _x = _con_x298->profiles;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x297 = _x; /*list<hot_paths/path-profile>*/
  }
  _x_x292 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x293, _x_x297, _ctx); /*list<10021>*/
  kk_integer_t _x_x299;
  kk_integer_t _x_x300;
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x301 = kk_src_effect__runtime__as_Runtime_state(state, _ctx);
    kk_std_core_types__list _pat_0_2 = _con_x301->events;
    kk_std_core_types__list _pat_1_2 = _con_x301->profiles;
    kk_integer_t _x_1 = _con_x301->total_ops;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_std_core_types__list_drop(_pat_1_2, _ctx);
      kk_std_core_types__list_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_integer_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x300 = _x_1; /*int*/
  }
  _x_x299 = kk_integer_add_small_const(_x_x300, 1, _ctx); /*int*/
  _b_x22_24 = kk_src_effect__runtime__new_Runtime_state(kk_reuse_null, 0, _x_x290, _x_x292, _x_x299, _ctx); /*src/effect_runtime/runtime-state*/
  kk_box_t _x_x302;
  kk_integer_t _x_x303;
  if (kk_gan__ying__is_MemoryCreated(et, _ctx)) {
    _x_x303 = kk_integer_from_small(3); /*int*/
    goto _match_x304;
  }
  if (kk_gan__ying__is_MemoryUpdated(et, _ctx)) {
    _x_x303 = kk_integer_from_small(2); /*int*/
    goto _match_x304;
  }
  if (kk_gan__ying__is_ThreatDetected(et, _ctx)) {
    _x_x303 = kk_integer_from_small(5); /*int*/
    goto _match_x304;
  }
  if (kk_gan__ying__is_FlowStateEntered(et, _ctx)) {
    _x_x303 = kk_integer_from_small(2); /*int*/
    goto _match_x304;
  }
  {
    _x_x303 = kk_integer_from_small(1); /*int*/
  }
  _match_x304: ;
  _x_x302 = kk_integer_box(_x_x303, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x302, kk_src_effect__runtime__runtime_state_box(_b_x22_24, _ctx), _ctx);
}

kk_string_t kk_src_effect__runtime_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x234;
  kk_string_t _x_x305 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x306;
  kk_define_string_literal(, _s_x307, 6, "\"emit\"", _ctx)
  _x_x306 = kk_string_dup(_s_x307, _ctx); /*string*/
  _match_x234 = kk_string_contains(_x_x305,_x_x306,kk_context()); /*bool*/
  if (_match_x234) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x308, 4, "emit", _ctx)
    return kk_string_dup(_s_x308, _ctx);
  }
  {
    bool _match_x235;
    kk_string_t _x_x309 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x310;
    kk_define_string_literal(, _s_x311, 9, "\"cascade\"", _ctx)
    _x_x310 = kk_string_dup(_s_x311, _ctx); /*string*/
    _match_x235 = kk_string_contains(_x_x309,_x_x310,kk_context()); /*bool*/
    if (_match_x235) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x312, 7, "cascade", _ctx)
      return kk_string_dup(_s_x312, _ctx);
    }
    {
      bool _match_x236;
      kk_string_t _x_x313 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x314;
      kk_define_string_literal(, _s_x315, 8, "\"status\"", _ctx)
      _x_x314 = kk_string_dup(_s_x315, _ctx); /*string*/
      _match_x236 = kk_string_contains(_x_x313,_x_x314,kk_context()); /*bool*/
      if (_match_x236) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x316, 6, "status", _ctx)
        return kk_string_dup(_s_x316, _ctx);
      }
      {
        bool _match_x237;
        kk_string_t _x_x317 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x318;
        kk_define_string_literal(, _s_x319, 9, "\"profile\"", _ctx)
        _x_x318 = kk_string_dup(_s_x319, _ctx); /*string*/
        _match_x237 = kk_string_contains(_x_x317,_x_x318,kk_context()); /*bool*/
        if (_match_x237) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x320, 7, "profile", _ctx)
          return kk_string_dup(_s_x320, _ctx);
        }
        {
          bool _match_x238;
          kk_string_t _x_x321;
          kk_define_string_literal(, _s_x322, 6, "\"quit\"", _ctx)
          _x_x321 = kk_string_dup(_s_x322, _ctx); /*string*/
          _match_x238 = kk_string_contains(line,_x_x321,kk_context()); /*bool*/
          if (_match_x238) {
            kk_define_string_literal(, _s_x323, 4, "quit", _ctx)
            return kk_string_dup(_s_x323, _ctx);
          }
          {
            kk_define_string_literal(, _s_x324, 7, "unknown", _ctx)
            return kk_string_dup(_s_x324, _ctx);
          }
        }
      }
    }
  }
}

kk_gan__ying__event_type kk_src_effect__runtime_extract_event_type(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> gan_ying/event-type */ 
  bool _match_x230;
  kk_string_t _x_x325 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x326;
  kk_define_string_literal(, _s_x327, 14, "memory_created", _ctx)
  _x_x326 = kk_string_dup(_s_x327, _ctx); /*string*/
  _match_x230 = kk_string_contains(_x_x325,_x_x326,kk_context()); /*bool*/
  if (_match_x230) {
    kk_string_drop(line, _ctx);
    return kk_gan__ying__new_MemoryCreated(_ctx);
  }
  {
    bool _match_x231;
    kk_string_t _x_x328 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x329;
    kk_define_string_literal(, _s_x330, 14, "memory_updated", _ctx)
    _x_x329 = kk_string_dup(_s_x330, _ctx); /*string*/
    _match_x231 = kk_string_contains(_x_x328,_x_x329,kk_context()); /*bool*/
    if (_match_x231) {
      kk_string_drop(line, _ctx);
      return kk_gan__ying__new_MemoryUpdated(_ctx);
    }
    {
      bool _match_x232;
      kk_string_t _x_x331 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x332;
      kk_define_string_literal(, _s_x333, 15, "threat_detected", _ctx)
      _x_x332 = kk_string_dup(_s_x333, _ctx); /*string*/
      _match_x232 = kk_string_contains(_x_x331,_x_x332,kk_context()); /*bool*/
      if (_match_x232) {
        kk_string_drop(line, _ctx);
        return kk_gan__ying__new_ThreatDetected(_ctx);
      }
      {
        bool _match_x233;
        kk_string_t _x_x334;
        kk_define_string_literal(, _s_x335, 10, "flow_state", _ctx)
        _x_x334 = kk_string_dup(_s_x335, _ctx); /*string*/
        _match_x233 = kk_string_contains(line,_x_x334,kk_context()); /*bool*/
        if (_match_x233) {
          return kk_gan__ying__new_FlowStateEntered(_ctx);
        }
        {
          return kk_gan__ying__new_SystemStarted(_ctx);
        }
      }
    }
  }
}

kk_string_t kk_src_effect__runtime_json_state(kk_src_effect__runtime__runtime_state s, kk_context_t* _ctx) { /* (s : runtime-state) -> string */ 
  kk_string_t _x_x336;
  kk_define_string_literal(, _s_x337, 10, "{\"events\":", _ctx)
  _x_x336 = kk_string_dup(_s_x337, _ctx); /*string*/
  kk_string_t _x_x338;
  kk_string_t _x_x339;
  kk_integer_t _x_x340;
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x341 = kk_src_effect__runtime__as_Runtime_state(s, _ctx);
    kk_std_core_types__list _x = _con_x341->events;
    kk_std_core_types__list_dup(_x, _ctx);
    if (kk_std_core_types__is_Nil(_x, _ctx)) {
      _x_x340 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_std_core_types__list_drop(_x, _ctx);
      kk_std_core_types__list _x_x342;
      {
        struct kk_src_effect__runtime_Runtime_state* _con_x343 = kk_src_effect__runtime__as_Runtime_state(s, _ctx);
        kk_std_core_types__list _x_0 = _con_x343->events;
        kk_std_core_types__list_dup(_x_0, _ctx);
        _x_x342 = _x_0; /*list<gan_ying/resonance-event>*/
      }
      _x_x340 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x342, kk_integer_from_small(0), _ctx); /*int*/
    }
  }
  _x_x339 = kk_std_core_int_show(_x_x340, _ctx); /*string*/
  kk_string_t _x_x344;
  kk_string_t _x_x345;
  kk_define_string_literal(, _s_x346, 12, ",\"profiles\":", _ctx)
  _x_x345 = kk_string_dup(_s_x346, _ctx); /*string*/
  kk_string_t _x_x347;
  kk_string_t _x_x348;
  kk_integer_t _x_x349;
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x350 = kk_src_effect__runtime__as_Runtime_state(s, _ctx);
    kk_std_core_types__list _x_0_0 = _con_x350->profiles;
    kk_std_core_types__list_dup(_x_0_0, _ctx);
    if (kk_std_core_types__is_Nil(_x_0_0, _ctx)) {
      _x_x349 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_std_core_types__list_drop(_x_0_0, _ctx);
      kk_std_core_types__list _x_x351;
      {
        struct kk_src_effect__runtime_Runtime_state* _con_x352 = kk_src_effect__runtime__as_Runtime_state(s, _ctx);
        kk_std_core_types__list _x_0_1 = _con_x352->profiles;
        kk_std_core_types__list_dup(_x_0_1, _ctx);
        _x_x351 = _x_0_1; /*list<hot_paths/path-profile>*/
      }
      _x_x349 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x351, kk_integer_from_small(0), _ctx); /*int*/
    }
  }
  _x_x348 = kk_std_core_int_show(_x_x349, _ctx); /*string*/
  kk_string_t _x_x353;
  kk_string_t _x_x354;
  kk_define_string_literal(, _s_x355, 13, ",\"total_ops\":", _ctx)
  _x_x354 = kk_string_dup(_s_x355, _ctx); /*string*/
  kk_string_t _x_x356;
  kk_string_t _x_x357;
  kk_integer_t _x_x358;
  {
    struct kk_src_effect__runtime_Runtime_state* _con_x359 = kk_src_effect__runtime__as_Runtime_state(s, _ctx);
    kk_std_core_types__list _pat_0_2 = _con_x359->events;
    kk_std_core_types__list _pat_1_3 = _con_x359->profiles;
    kk_integer_t _x_1 = _con_x359->total_ops;
    if kk_likely(kk_datatype_ptr_is_unique(s, _ctx)) {
      kk_std_core_types__list_drop(_pat_1_3, _ctx);
      kk_std_core_types__list_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(s, _ctx);
    }
    else {
      kk_integer_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(s, _ctx);
    }
    _x_x358 = _x_1; /*int*/
  }
  _x_x357 = kk_std_core_int_show(_x_x358, _ctx); /*string*/
  kk_string_t _x_x360;
  kk_define_string_literal(, _s_x361, 1, "}", _ctx)
  _x_x360 = kk_string_dup(_s_x361, _ctx); /*string*/
  _x_x356 = kk_std_core_types__lp__plus__plus__rp_(_x_x357, _x_x360, _ctx); /*string*/
  _x_x353 = kk_std_core_types__lp__plus__plus__rp_(_x_x354, _x_x356, _ctx); /*string*/
  _x_x347 = kk_std_core_types__lp__plus__plus__rp_(_x_x348, _x_x353, _ctx); /*string*/
  _x_x344 = kk_std_core_types__lp__plus__plus__rp_(_x_x345, _x_x347, _ctx); /*string*/
  _x_x338 = kk_std_core_types__lp__plus__plus__rp_(_x_x339, _x_x344, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x336, _x_x338, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10201_fun364__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10201_fun364(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10201_fun364(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10201_fun364, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10201_fun364(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x365;
  kk_string_t _x_x366 = kk_string_unbox(_b_x29); /*string*/
  _x_x365 = kk_src_effect__runtime_extract_event_type(_x_x366, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x365, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10201_fun388__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10201_fun388(kk_function_t _fself, kk_box_t _b_x42, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10201_fun388(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10201_fun388, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10201_fun388(kk_function_t _fself, kk_box_t _b_x42, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x389;
  kk_string_t _x_x390 = kk_string_unbox(_b_x42); /*string*/
  _x_x389 = kk_src_effect__runtime_extract_event_type(_x_x390, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x389, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10201_fun392__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10201_fun392(kk_function_t _fself, kk_box_t _b_x48, kk_box_t _b_x49, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10201_fun392(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10201_fun392, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10201_fun392(kk_function_t _fself, kk_box_t _b_x48, kk_box_t _b_x49, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x393;
  kk_gan__ying__event_type _x_x394 = kk_gan__ying__event_type_unbox(_b_x48, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_effect__runtime__runtime_state _x_x395 = kk_src_effect__runtime__runtime_state_unbox(_b_x49, KK_OWNED, _ctx); /*src/effect_runtime/runtime-state*/
  _x_x393 = kk_src_effect__runtime_cascade_profiled(_x_x394, _x_x395, _ctx); /*(int, src/effect_runtime/runtime-state)*/
  return kk_std_core_types__tuple2_box(_x_x393, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10201_fun398__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10201_fun398(kk_function_t _fself, kk_box_t _b_x56, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10201_fun398(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10201_fun398, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10201_fun398(kk_function_t _fself, kk_box_t _b_x56, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x399 = kk_Unit;
  kk_src_effect__runtime__runtime_state _x_x400 = kk_src_effect__runtime__runtime_state_unbox(_b_x56, KK_OWNED, _ctx); /*src/effect_runtime/runtime-state*/
  kk_src_effect__runtime_server_loop(_x_x400, _ctx);
  return kk_unit_box(_x_x399);
}

kk_unit_t kk_src_effect__runtime__mlift_server_loop_10201(kk_string_t line, kk_string_t op, kk_src_effect__runtime__runtime_state state, kk_string_t _c_x10155, kk_context_t* _ctx) { /* (line : string, op : string, state : runtime-state, string) -> () */ 
  kk_unit_t ___1 = kk_Unit;
  kk_std_core_console_printsln(_c_x10155, _ctx);
  kk_src_effect__runtime__runtime_state x_10203;
  if (kk_string_cmp_cstr_borrow(op, "emit", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_gan__ying__event_type et_1_0;
    kk_box_t _x_x363 = kk_std_core_hnd__open_none1(kk_src_effect__runtime__new_mlift_server_loop_10201_fun364(_ctx), kk_string_box(line), _ctx); /*10001*/
    et_1_0 = kk_gan__ying__event_type_unbox(_x_x363, KK_OWNED, _ctx); /*gan_ying/event-type*/
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_string_t name_0_10042;
    kk_string_t _x_x367;
    kk_define_string_literal(, _s_x368, 5, "emit_", _ctx)
    _x_x367 = kk_string_dup(_s_x368, _ctx); /*string*/
    kk_string_t _x_x369 = kk_gan__ying_event_type_to_string(et_1_0, _ctx); /*string*/
    name_0_10042 = kk_std_core_types__lp__plus__plus__rp_(_x_x367, _x_x369, _ctx); /*string*/
    kk_src_effect__runtime__runtime_state x_0;
    kk_std_core_types__list _x_x370;
    kk_box_t _x_x371;
    kk_gan__ying__resonance_event _x_x372;
    kk_string_t _x_x373;
    kk_define_string_literal(, _s_x374, 14, "effect_runtime", _ctx)
    _x_x373 = kk_string_dup(_s_x374, _ctx); /*string*/
    kk_string_t _x_x375 = kk_string_empty(); /*string*/
    _x_x372 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x373, et_1_0, _x_x375, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
    _x_x371 = kk_gan__ying__resonance_event_box(_x_x372, _ctx); /*10021*/
    kk_std_core_types__list _x_x377;
    {
      struct kk_src_effect__runtime_Runtime_state* _con_x378 = kk_src_effect__runtime__as_Runtime_state(state, _ctx);
      kk_std_core_types__list _x_4 = _con_x378->events;
      kk_std_core_types__list_dup(_x_4, _ctx);
      _x_x377 = _x_4; /*list<gan_ying/resonance-event>*/
    }
    _x_x370 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x371, _x_x377, _ctx); /*list<10021>*/
    kk_std_core_types__list _x_x379;
    kk_box_t _x_x380;
    kk_hot__paths__path_profile _x_x381 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, name_0_10042, kk_integer_from_small(1), 0x1.0624dd2f1a9fcp-10, 0x1.0624dd2f1a9fcp-10, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_Compute(_ctx), _ctx); /*hot_paths/path-profile*/
    _x_x380 = kk_hot__paths__path_profile_box(_x_x381, _ctx); /*10021*/
    kk_std_core_types__list _x_x382;
    {
      struct kk_src_effect__runtime_Runtime_state* _con_x383 = kk_src_effect__runtime__as_Runtime_state(state, _ctx);
      kk_std_core_types__list _x_5 = _con_x383->profiles;
      kk_std_core_types__list_dup(_x_5, _ctx);
      _x_x382 = _x_5; /*list<hot_paths/path-profile>*/
    }
    _x_x379 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x380, _x_x382, _ctx); /*list<10021>*/
    kk_integer_t _x_x384;
    kk_integer_t _x_x385;
    {
      struct kk_src_effect__runtime_Runtime_state* _con_x386 = kk_src_effect__runtime__as_Runtime_state(state, _ctx);
      kk_std_core_types__list _pat_0_7 = _con_x386->events;
      kk_std_core_types__list _pat_1_8 = _con_x386->profiles;
      kk_integer_t _x_6 = _con_x386->total_ops;
      if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
        kk_std_core_types__list_drop(_pat_1_8, _ctx);
        kk_std_core_types__list_drop(_pat_0_7, _ctx);
        kk_datatype_ptr_free(state, _ctx);
      }
      else {
        kk_integer_dup(_x_6, _ctx);
        kk_datatype_ptr_decref(state, _ctx);
      }
      _x_x385 = _x_6; /*int*/
    }
    _x_x384 = kk_integer_add_small_const(_x_x385, 1, _ctx); /*int*/
    x_0 = kk_src_effect__runtime__new_Runtime_state(kk_reuse_null, 0, _x_x370, _x_x379, _x_x384, _ctx); /*src/effect_runtime/runtime-state*/
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    x_10203 = x_0; /*src/effect_runtime/runtime-state*/
    goto _match_x362;
  }
  if (kk_string_cmp_cstr_borrow(op, "cascade", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_gan__ying__event_type et_2_0;
    kk_box_t _x_x387 = kk_std_core_hnd__open_none1(kk_src_effect__runtime__new_mlift_server_loop_10201_fun388(_ctx), kk_string_box(line), _ctx); /*10001*/
    et_2_0 = kk_gan__ying__event_type_unbox(_x_x387, KK_OWNED, _ctx); /*gan_ying/event-type*/
    kk_std_core_types__tuple2 _match_x229;
    kk_box_t _x_x391 = kk_std_core_hnd__open_none2(kk_src_effect__runtime__new_mlift_server_loop_10201_fun392(_ctx), kk_gan__ying__event_type_box(et_2_0, _ctx), kk_src_effect__runtime__runtime_state_box(state, _ctx), _ctx); /*10002*/
    _match_x229 = kk_std_core_types__tuple2_unbox(_x_x391, KK_OWNED, _ctx); /*(int, src/effect_runtime/runtime-state)*/
    {
      kk_box_t _box_x50 = _match_x229.fst;
      kk_box_t _box_x51 = _match_x229.snd;
      kk_src_effect__runtime__runtime_state ns = kk_src_effect__runtime__runtime_state_unbox(_box_x51, KK_BORROWED, _ctx);
      struct kk_src_effect__runtime_Runtime_state* _con_x396 = kk_src_effect__runtime__as_Runtime_state(ns, _ctx);
      kk_src_effect__runtime__runtime_state_dup(ns, _ctx);
      kk_std_core_types__tuple2_drop(_match_x229, _ctx);
      x_10203 = ns; /*src/effect_runtime/runtime-state*/
      goto _match_x362;
    }
  }
  {
    kk_string_drop(op, _ctx);
    kk_string_drop(line, _ctx);
    x_10203 = state; /*src/effect_runtime/runtime-state*/
  }
  _match_x362: ;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10203, (KK_I32(3)), _ctx);
    kk_box_t _x_x397 = kk_std_core_hnd_yield_extend(kk_src_effect__runtime__new_mlift_server_loop_10201_fun398(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x397); return kk_Unit;
  }
  {
    kk_src_effect__runtime_server_loop(x_10203, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10202_fun410__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun410(kk_function_t _fself, kk_box_t _b_x60, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10202_fun410(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10202_fun410, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun410(kk_function_t _fself, kk_box_t _b_x60, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x411;
  kk_string_t _x_x412 = kk_string_unbox(_b_x60); /*string*/
  _x_x411 = kk_src_effect__runtime_extract_op(_x_x412, _ctx); /*string*/
  return kk_string_box(_x_x411);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10202_fun417__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun417(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10202_fun417(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10202_fun417, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun417(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x418;
  kk_string_t _x_x419 = kk_string_unbox(_b_x65); /*string*/
  _x_x418 = kk_src_effect__runtime_extract_event_type(_x_x419, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x418, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10202_fun447__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun447(kk_function_t _fself, kk_box_t _b_x78, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10202_fun447(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10202_fun447, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun447(kk_function_t _fself, kk_box_t _b_x78, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x448;
  kk_gan__ying__event_type _x_x449 = kk_gan__ying__event_type_unbox(_b_x78, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x448 = kk_gan__ying_event_type_to_string(_x_x449, _ctx); /*string*/
  return kk_string_box(_x_x448);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10202_fun456__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun456(kk_function_t _fself, kk_box_t _b_x81, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10202_fun456(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10202_fun456, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun456(kk_function_t _fself, kk_box_t _b_x81, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x457;
  kk_src_effect__runtime__runtime_state _x_x458 = kk_src_effect__runtime__runtime_state_unbox(_b_x81, KK_OWNED, _ctx); /*src/effect_runtime/runtime-state*/
  _x_x457 = kk_src_effect__runtime_json_state(_x_x458, _ctx); /*string*/
  return kk_string_box(_x_x457);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10202_fun462__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun462(kk_function_t _fself, kk_box_t _b_x84, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10202_fun462(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10202_fun462, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun462(kk_function_t _fself, kk_box_t _b_x84, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x463;
  kk_string_t _x_x464 = kk_string_unbox(_b_x84); /*string*/
  _x_x463 = kk_src_effect__runtime_extract_event_type(_x_x464, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x463, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10202_fun468__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun468(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10202_fun468(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10202_fun468, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun468(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x469;
  kk_gan__ying__event_type _x_x470 = kk_gan__ying__event_type_unbox(_b_x89, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x469 = kk_gan__ying_event_type_to_string(_x_x470, _ctx); /*string*/
  return kk_string_box(_x_x469);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10202_fun481__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun481(kk_function_t _fself, kk_box_t _b_x95, kk_box_t _b_x96, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10202_fun481(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10202_fun481, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun481(kk_function_t _fself, kk_box_t _b_x95, kk_box_t _b_x96, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x482;
  kk_gan__ying__event_type _x_x483 = kk_gan__ying__event_type_unbox(_b_x95, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_effect__runtime__runtime_state _x_x484 = kk_src_effect__runtime__runtime_state_unbox(_b_x96, KK_OWNED, _ctx); /*src/effect_runtime/runtime-state*/
  _x_x482 = kk_src_effect__runtime_cascade_profiled(_x_x483, _x_x484, _ctx); /*(int, src/effect_runtime/runtime-state)*/
  return kk_std_core_types__tuple2_box(_x_x482, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10202_fun503__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun503(kk_function_t _fself, kk_box_t _b_x101, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10202_fun503(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10202_fun503, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun503(kk_function_t _fself, kk_box_t _b_x101, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x504;
  kk_gan__ying__event_type _x_x505 = kk_gan__ying__event_type_unbox(_b_x101, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x504 = kk_gan__ying_event_type_to_string(_x_x505, _ctx); /*string*/
  return kk_string_box(_x_x504);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10202_fun514__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun514(kk_function_t _fself, kk_box_t _b_x104, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10202_fun514(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime__mlift_server_loop_10202_fun514, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun514(kk_function_t _fself, kk_box_t _b_x104, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x515;
  kk_src_effect__runtime__runtime_state _x_x516 = kk_src_effect__runtime__runtime_state_unbox(_b_x104, KK_OWNED, _ctx); /*src/effect_runtime/runtime-state*/
  _x_x515 = kk_src_effect__runtime_json_state(_x_x516, _ctx); /*string*/
  return kk_string_box(_x_x515);
}


// lift anonymous function
struct kk_src_effect__runtime__mlift_server_loop_10202_fun537__t {
  struct kk_function_s _base;
  kk_string_t line_0;
  kk_string_t op_0;
  kk_src_effect__runtime__runtime_state state_0;
};
static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun537(kk_function_t _fself, kk_box_t _b_x117, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime__new_mlift_server_loop_10202_fun537(kk_string_t line_0, kk_string_t op_0, kk_src_effect__runtime__runtime_state state_0, kk_context_t* _ctx) {
  struct kk_src_effect__runtime__mlift_server_loop_10202_fun537__t* _self = kk_function_alloc_as(struct kk_src_effect__runtime__mlift_server_loop_10202_fun537__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effect__runtime__mlift_server_loop_10202_fun537, kk_context());
  _self->line_0 = line_0;
  _self->op_0 = op_0;
  _self->state_0 = state_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effect__runtime__mlift_server_loop_10202_fun537(kk_function_t _fself, kk_box_t _b_x117, kk_context_t* _ctx) {
  struct kk_src_effect__runtime__mlift_server_loop_10202_fun537__t* _self = kk_function_as(struct kk_src_effect__runtime__mlift_server_loop_10202_fun537__t*, _fself, _ctx);
  kk_string_t line_0 = _self->line_0; /* string */
  kk_string_t op_0 = _self->op_0; /* string */
  kk_src_effect__runtime__runtime_state state_0 = _self->state_0; /* src/effect_runtime/runtime-state */
  kk_drop_match(_self, {kk_string_dup(line_0, _ctx);kk_string_dup(op_0, _ctx);kk_src_effect__runtime__runtime_state_dup(state_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10155_0_119 = kk_string_unbox(_b_x117); /*string*/;
  kk_unit_t _x_x538 = kk_Unit;
  kk_src_effect__runtime__mlift_server_loop_10201(line_0, op_0, state_0, _c_x10155_0_119, _ctx);
  return kk_unit_box(_x_x538);
}

kk_unit_t kk_src_effect__runtime__mlift_server_loop_10202(kk_src_effect__runtime__runtime_state state_0, kk_string_t line_0, kk_context_t* _ctx) { /* (state : runtime-state, line : string) -> <console/console,exn> () */ 
  bool _match_x224;
  kk_string_t _x_x401 = kk_string_dup(line_0, _ctx); /*string*/
  kk_string_t _x_x402 = kk_string_empty(); /*string*/
  _match_x224 = kk_string_is_eq(_x_x401,_x_x402,kk_context()); /*bool*/
  if (_match_x224) {
    kk_datatype_ptr_dropn(state_0, (KK_I32(3)), _ctx);
    kk_string_drop(line_0, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    bool _match_x225;
    kk_string_t _x_x404 = kk_string_dup(line_0, _ctx); /*string*/
    kk_string_t _x_x405;
    kk_define_string_literal(, _s_x406, 6, "\"quit\"", _ctx)
    _x_x405 = kk_string_dup(_s_x406, _ctx); /*string*/
    _match_x225 = kk_string_contains(_x_x404,_x_x405,kk_context()); /*bool*/
    if (_match_x225) {
      kk_datatype_ptr_dropn(state_0, (KK_I32(3)), _ctx);
      kk_string_drop(line_0, _ctx);
      kk_string_t _x_x407;
      kk_define_string_literal(, _s_x408, 20, "{\"status\":\"stopped\"}", _ctx)
      _x_x407 = kk_string_dup(_s_x408, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x407, _ctx); return kk_Unit;
    }
    {
      kk_string_t op_0;
      kk_box_t _x_x409;
      kk_box_t _x_x413;
      kk_string_t _x_x414 = kk_string_dup(line_0, _ctx); /*string*/
      _x_x413 = kk_string_box(_x_x414); /*10000*/
      _x_x409 = kk_std_core_hnd__open_none1(kk_src_effect__runtime__new_mlift_server_loop_10202_fun410(_ctx), _x_x413, _ctx); /*10001*/
      op_0 = kk_string_unbox(_x_x409); /*string*/
      kk_string_t x_1_10209;
      if (kk_string_cmp_cstr_borrow(op_0, "emit", _ctx) == 0) {
        kk_gan__ying__event_type et;
        kk_box_t _x_x416;
        kk_box_t _x_x420;
        kk_string_t _x_x421 = kk_string_dup(line_0, _ctx); /*string*/
        _x_x420 = kk_string_box(_x_x421); /*10000*/
        _x_x416 = kk_std_core_hnd__open_none1(kk_src_effect__runtime__new_mlift_server_loop_10202_fun417(_ctx), _x_x420, _ctx); /*10001*/
        et = kk_gan__ying__event_type_unbox(_x_x416, KK_OWNED, _ctx); /*gan_ying/event-type*/
        kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_string_t name_10027;
        kk_string_t _x_x422;
        kk_define_string_literal(, _s_x423, 5, "emit_", _ctx)
        _x_x422 = kk_string_dup(_s_x423, _ctx); /*string*/
        kk_string_t _x_x424 = kk_gan__ying_event_type_to_string(et, _ctx); /*string*/
        name_10027 = kk_std_core_types__lp__plus__plus__rp_(_x_x422, _x_x424, _ctx); /*string*/
        kk_src_effect__runtime__runtime_state x_2;
        kk_std_core_types__list _x_x425;
        kk_box_t _x_x426;
        kk_gan__ying__resonance_event _x_x427;
        kk_string_t _x_x428;
        kk_define_string_literal(, _s_x429, 14, "effect_runtime", _ctx)
        _x_x428 = kk_string_dup(_s_x429, _ctx); /*string*/
        kk_string_t _x_x430 = kk_string_empty(); /*string*/
        _x_x427 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x428, et, _x_x430, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
        _x_x426 = kk_gan__ying__resonance_event_box(_x_x427, _ctx); /*10021*/
        kk_std_core_types__list _x_x432;
        {
          struct kk_src_effect__runtime_Runtime_state* _con_x433 = kk_src_effect__runtime__as_Runtime_state(state_0, _ctx);
          kk_std_core_types__list _x = _con_x433->events;
          kk_std_core_types__list_dup(_x, _ctx);
          _x_x432 = _x; /*list<gan_ying/resonance-event>*/
        }
        _x_x425 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x426, _x_x432, _ctx); /*list<10021>*/
        kk_std_core_types__list _x_x434;
        kk_box_t _x_x435;
        kk_hot__paths__path_profile _x_x436 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, name_10027, kk_integer_from_small(1), 0x1.0624dd2f1a9fcp-10, 0x1.0624dd2f1a9fcp-10, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_Compute(_ctx), _ctx); /*hot_paths/path-profile*/
        _x_x435 = kk_hot__paths__path_profile_box(_x_x436, _ctx); /*10021*/
        kk_std_core_types__list _x_x437;
        {
          struct kk_src_effect__runtime_Runtime_state* _con_x438 = kk_src_effect__runtime__as_Runtime_state(state_0, _ctx);
          kk_std_core_types__list _x_0 = _con_x438->profiles;
          kk_std_core_types__list_dup(_x_0, _ctx);
          _x_x437 = _x_0; /*list<hot_paths/path-profile>*/
        }
        _x_x434 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x435, _x_x437, _ctx); /*list<10021>*/
        kk_integer_t _x_x439;
        kk_integer_t _x_x440;
        {
          struct kk_src_effect__runtime_Runtime_state* _con_x441 = kk_src_effect__runtime__as_Runtime_state(state_0, _ctx);
          kk_integer_t _x_1 = _con_x441->total_ops;
          kk_integer_dup(_x_1, _ctx);
          _x_x440 = _x_1; /*int*/
        }
        _x_x439 = kk_integer_add_small_const(_x_x440, 1, _ctx); /*int*/
        x_2 = kk_src_effect__runtime__new_Runtime_state(kk_reuse_null, 0, _x_x425, _x_x434, _x_x439, _ctx); /*src/effect_runtime/runtime-state*/
        kk_unit_t keep_0 = kk_Unit;
        kk_evv_set(w_0,kk_context());
        kk_string_t _x_x442;
        kk_define_string_literal(, _s_x443, 12, "{\"emitted\":\"", _ctx)
        _x_x442 = kk_string_dup(_s_x443, _ctx); /*string*/
        kk_string_t _x_x444;
        kk_string_t _x_x445;
        kk_box_t _x_x446 = kk_std_core_hnd__open_none1(kk_src_effect__runtime__new_mlift_server_loop_10202_fun447(_ctx), kk_gan__ying__event_type_box(et, _ctx), _ctx); /*10001*/
        _x_x445 = kk_string_unbox(_x_x446); /*string*/
        kk_string_t _x_x450;
        kk_string_t _x_x451;
        kk_define_string_literal(, _s_x452, 10, "\",\"state\":", _ctx)
        _x_x451 = kk_string_dup(_s_x452, _ctx); /*string*/
        kk_string_t _x_x453;
        kk_string_t _x_x454;
        kk_box_t _x_x455 = kk_std_core_hnd__open_none1(kk_src_effect__runtime__new_mlift_server_loop_10202_fun456(_ctx), kk_src_effect__runtime__runtime_state_box(x_2, _ctx), _ctx); /*10001*/
        _x_x454 = kk_string_unbox(_x_x455); /*string*/
        kk_string_t _x_x459;
        kk_define_string_literal(, _s_x460, 1, "}", _ctx)
        _x_x459 = kk_string_dup(_s_x460, _ctx); /*string*/
        _x_x453 = kk_std_core_types__lp__plus__plus__rp_(_x_x454, _x_x459, _ctx); /*string*/
        _x_x450 = kk_std_core_types__lp__plus__plus__rp_(_x_x451, _x_x453, _ctx); /*string*/
        _x_x444 = kk_std_core_types__lp__plus__plus__rp_(_x_x445, _x_x450, _ctx); /*string*/
        x_1_10209 = kk_std_core_types__lp__plus__plus__rp_(_x_x442, _x_x444, _ctx); /*string*/
        goto _match_x415;
      }
      if (kk_string_cmp_cstr_borrow(op_0, "cascade", _ctx) == 0) {
        kk_gan__ying__event_type et_0_0;
        kk_box_t _x_x461;
        kk_box_t _x_x465;
        kk_string_t _x_x466 = kk_string_dup(line_0, _ctx); /*string*/
        _x_x465 = kk_string_box(_x_x466); /*10000*/
        _x_x461 = kk_std_core_hnd__open_none1(kk_src_effect__runtime__new_mlift_server_loop_10202_fun462(_ctx), _x_x465, _ctx); /*10001*/
        et_0_0 = kk_gan__ying__event_type_unbox(_x_x461, KK_OWNED, _ctx); /*gan_ying/event-type*/
        kk_string_t details_10039;
        kk_box_t _x_x467 = kk_std_core_hnd__open_none1(kk_src_effect__runtime__new_mlift_server_loop_10202_fun468(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _ctx); /*10001*/
        details_10039 = kk_string_unbox(_x_x467); /*string*/
        kk_unit_t __ = kk_Unit;
        kk_string_t _x_x471;
        kk_string_t _x_x472;
        kk_define_string_literal(, _s_x473, 8, "[TRACE] ", _ctx)
        _x_x472 = kk_string_dup(_s_x473, _ctx); /*string*/
        kk_string_t _x_x474;
        kk_string_t _x_x475;
        kk_define_string_literal(, _s_x476, 13, "cascade_start", _ctx)
        _x_x475 = kk_string_dup(_s_x476, _ctx); /*string*/
        kk_string_t _x_x477;
        kk_string_t _x_x478;
        kk_define_string_literal(, _s_x479, 2, ": ", _ctx)
        _x_x478 = kk_string_dup(_s_x479, _ctx); /*string*/
        _x_x477 = kk_std_core_types__lp__plus__plus__rp_(_x_x478, details_10039, _ctx); /*string*/
        _x_x474 = kk_std_core_types__lp__plus__plus__rp_(_x_x475, _x_x477, _ctx); /*string*/
        _x_x471 = kk_std_core_types__lp__plus__plus__rp_(_x_x472, _x_x474, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x471, _ctx);
        kk_std_core_types__tuple2 _match_x227;
        kk_box_t _x_x480;
        kk_box_t _x_x485;
        kk_src_effect__runtime__runtime_state _x_x486 = kk_src_effect__runtime__runtime_state_dup(state_0, _ctx); /*src/effect_runtime/runtime-state*/
        _x_x485 = kk_src_effect__runtime__runtime_state_box(_x_x486, _ctx); /*10001*/
        _x_x480 = kk_std_core_hnd__open_none2(kk_src_effect__runtime__new_mlift_server_loop_10202_fun481(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _x_x485, _ctx); /*10002*/
        _match_x227 = kk_std_core_types__tuple2_unbox(_x_x480, KK_OWNED, _ctx); /*(int, src/effect_runtime/runtime-state)*/
        {
          kk_box_t _box_x97 = _match_x227.fst;
          kk_box_t _box_x98 = _match_x227.snd;
          kk_src_effect__runtime__runtime_state new_state_0 = kk_src_effect__runtime__runtime_state_unbox(_box_x98, KK_BORROWED, _ctx);
          struct kk_src_effect__runtime_Runtime_state* _con_x487 = kk_src_effect__runtime__as_Runtime_state(new_state_0, _ctx);
          kk_integer_t handlers = kk_integer_unbox(_box_x97, _ctx);
          kk_integer_dup(handlers, _ctx);
          kk_std_core_types__tuple2_drop(_match_x227, _ctx);
          kk_string_t details_0_10041;
          kk_integer_t _x_x488 = kk_integer_dup(handlers, _ctx); /*int*/
          details_0_10041 = kk_std_core_int_show(_x_x488, _ctx); /*string*/
          kk_unit_t ___0 = kk_Unit;
          kk_string_t _x_x489;
          kk_string_t _x_x490;
          kk_define_string_literal(, _s_x491, 8, "[TRACE] ", _ctx)
          _x_x490 = kk_string_dup(_s_x491, _ctx); /*string*/
          kk_string_t _x_x492;
          kk_string_t _x_x493;
          kk_define_string_literal(, _s_x494, 11, "cascade_end", _ctx)
          _x_x493 = kk_string_dup(_s_x494, _ctx); /*string*/
          kk_string_t _x_x495;
          kk_string_t _x_x496;
          kk_define_string_literal(, _s_x497, 2, ": ", _ctx)
          _x_x496 = kk_string_dup(_s_x497, _ctx); /*string*/
          _x_x495 = kk_std_core_types__lp__plus__plus__rp_(_x_x496, details_0_10041, _ctx); /*string*/
          _x_x492 = kk_std_core_types__lp__plus__plus__rp_(_x_x493, _x_x495, _ctx); /*string*/
          _x_x489 = kk_std_core_types__lp__plus__plus__rp_(_x_x490, _x_x492, _ctx); /*string*/
          kk_std_core_console_printsln(_x_x489, _ctx);
          kk_string_t _x_x498;
          kk_define_string_literal(, _s_x499, 12, "{\"cascade\":\"", _ctx)
          _x_x498 = kk_string_dup(_s_x499, _ctx); /*string*/
          kk_string_t _x_x500;
          kk_string_t _x_x501;
          kk_box_t _x_x502 = kk_std_core_hnd__open_none1(kk_src_effect__runtime__new_mlift_server_loop_10202_fun503(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _ctx); /*10001*/
          _x_x501 = kk_string_unbox(_x_x502); /*string*/
          kk_string_t _x_x506;
          kk_string_t _x_x507;
          kk_define_string_literal(, _s_x508, 13, "\",\"handlers\":", _ctx)
          _x_x507 = kk_string_dup(_s_x508, _ctx); /*string*/
          kk_string_t _x_x509;
          kk_string_t _x_x510 = kk_std_core_int_show(handlers, _ctx); /*string*/
          kk_string_t _x_x511;
          kk_define_string_literal(, _s_x512, 1, "}", _ctx)
          _x_x511 = kk_string_dup(_s_x512, _ctx); /*string*/
          _x_x509 = kk_std_core_types__lp__plus__plus__rp_(_x_x510, _x_x511, _ctx); /*string*/
          _x_x506 = kk_std_core_types__lp__plus__plus__rp_(_x_x507, _x_x509, _ctx); /*string*/
          _x_x500 = kk_std_core_types__lp__plus__plus__rp_(_x_x501, _x_x506, _ctx); /*string*/
          x_1_10209 = kk_std_core_types__lp__plus__plus__rp_(_x_x498, _x_x500, _ctx); /*string*/
          goto _match_x415;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
        kk_box_t _x_x513;
        kk_box_t _x_x517;
        kk_src_effect__runtime__runtime_state _x_x518 = kk_src_effect__runtime__runtime_state_dup(state_0, _ctx); /*src/effect_runtime/runtime-state*/
        _x_x517 = kk_src_effect__runtime__runtime_state_box(_x_x518, _ctx); /*10000*/
        _x_x513 = kk_std_core_hnd__open_none1(kk_src_effect__runtime__new_mlift_server_loop_10202_fun514(_ctx), _x_x517, _ctx); /*10001*/
        x_1_10209 = kk_string_unbox(_x_x513); /*string*/
        goto _match_x415;
      }
      if (kk_string_cmp_cstr_borrow(op_0, "profile", _ctx) == 0) {
        kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_1 = kk_Unit;
        kk_evv_set(w_1,kk_context());
        kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_integer_t x;
        {
          struct kk_src_effect__runtime_Runtime_state* _con_x519 = kk_src_effect__runtime__as_Runtime_state(state_0, _ctx);
          kk_std_core_types__list _x_2 = _con_x519->profiles;
          kk_std_core_types__list_dup(_x_2, _ctx);
          if (kk_std_core_types__is_Nil(_x_2, _ctx)) {
            x = kk_integer_from_small(0); /*int*/
          }
          else {
            kk_std_core_types__list_drop(_x_2, _ctx);
            kk_std_core_types__list _x_x520;
            {
              struct kk_src_effect__runtime_Runtime_state* _con_x521 = kk_src_effect__runtime__as_Runtime_state(state_0, _ctx);
              kk_std_core_types__list _x_2_0 = _con_x521->profiles;
              kk_std_core_types__list_dup(_x_2_0, _ctx);
              _x_x520 = _x_2_0; /*list<hot_paths/path-profile>*/
            }
            x = kk_std_core_list__unroll_lift_length_5730_10000(_x_x520, kk_integer_from_small(0), _ctx); /*int*/
          }
        }
        kk_unit_t keep_2 = kk_Unit;
        kk_evv_set(w_2,kk_context());
        kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_3 = kk_Unit;
        kk_evv_set(w_3,kk_context());
        kk_string_t _x_x522;
        kk_define_string_literal(, _s_x523, 12, "{\"profiles\":", _ctx)
        _x_x522 = kk_string_dup(_s_x523, _ctx); /*string*/
        kk_string_t _x_x524;
        kk_string_t _x_x525 = kk_std_core_int_show(x, _ctx); /*string*/
        kk_string_t _x_x526;
        kk_string_t _x_x527;
        kk_define_string_literal(, _s_x528, 13, ",\"total_ops\":", _ctx)
        _x_x527 = kk_string_dup(_s_x528, _ctx); /*string*/
        kk_string_t _x_x529;
        kk_string_t _x_x530;
        kk_integer_t _x_x531;
        {
          struct kk_src_effect__runtime_Runtime_state* _con_x532 = kk_src_effect__runtime__as_Runtime_state(state_0, _ctx);
          kk_integer_t _x_3 = _con_x532->total_ops;
          kk_integer_dup(_x_3, _ctx);
          _x_x531 = _x_3; /*int*/
        }
        _x_x530 = kk_std_core_int_show(_x_x531, _ctx); /*string*/
        kk_string_t _x_x533;
        kk_define_string_literal(, _s_x534, 1, "}", _ctx)
        _x_x533 = kk_string_dup(_s_x534, _ctx); /*string*/
        _x_x529 = kk_std_core_types__lp__plus__plus__rp_(_x_x530, _x_x533, _ctx); /*string*/
        _x_x526 = kk_std_core_types__lp__plus__plus__rp_(_x_x527, _x_x529, _ctx); /*string*/
        _x_x524 = kk_std_core_types__lp__plus__plus__rp_(_x_x525, _x_x526, _ctx); /*string*/
        x_1_10209 = kk_std_core_types__lp__plus__plus__rp_(_x_x522, _x_x524, _ctx); /*string*/
        goto _match_x415;
      }
      {
        kk_define_string_literal(, _s_x535, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_1_10209 = kk_string_dup(_s_x535, _ctx); /*string*/
      }
      _match_x415: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_1_10209, _ctx);
        kk_box_t _x_x536 = kk_std_core_hnd_yield_extend(kk_src_effect__runtime__new_mlift_server_loop_10202_fun537(line_0, op_0, state_0, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x536); return kk_Unit;
      }
      {
        kk_src_effect__runtime__mlift_server_loop_10201(line_0, op_0, state_0, x_1_10209, _ctx); return kk_Unit;
      }
    }
  }
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun540__t {
  struct kk_function_s _base;
  kk_src_effect__runtime__runtime_state state_1;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun540(kk_function_t _fself, kk_box_t _b_x121, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun540(kk_src_effect__runtime__runtime_state state_1, kk_context_t* _ctx) {
  struct kk_src_effect__runtime_server_loop_fun540__t* _self = kk_function_alloc_as(struct kk_src_effect__runtime_server_loop_fun540__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effect__runtime_server_loop_fun540, kk_context());
  _self->state_1 = state_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun540(kk_function_t _fself, kk_box_t _b_x121, kk_context_t* _ctx) {
  struct kk_src_effect__runtime_server_loop_fun540__t* _self = kk_function_as(struct kk_src_effect__runtime_server_loop_fun540__t*, _fself, _ctx);
  kk_src_effect__runtime__runtime_state state_1 = _self->state_1; /* src/effect_runtime/runtime-state */
  kk_drop_match(_self, {kk_src_effect__runtime__runtime_state_dup(state_1, _ctx);}, {}, _ctx)
  kk_string_t line_1_215 = kk_string_unbox(_b_x121); /*string*/;
  kk_unit_t _x_x541 = kk_Unit;
  kk_src_effect__runtime__mlift_server_loop_10202(state_1, line_1_215, _ctx);
  return kk_unit_box(_x_x541);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun551__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun551(kk_function_t _fself, kk_box_t _b_x124, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun551(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun551, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun551(kk_function_t _fself, kk_box_t _b_x124, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x552;
  kk_string_t _x_x553 = kk_string_unbox(_b_x124); /*string*/
  _x_x552 = kk_src_effect__runtime_extract_op(_x_x553, _ctx); /*string*/
  return kk_string_box(_x_x552);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun558__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun558(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun558(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun558, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun558(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x559;
  kk_string_t _x_x560 = kk_string_unbox(_b_x129); /*string*/
  _x_x559 = kk_src_effect__runtime_extract_event_type(_x_x560, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x559, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun588__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun588(kk_function_t _fself, kk_box_t _b_x142, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun588(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun588, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun588(kk_function_t _fself, kk_box_t _b_x142, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x589;
  kk_gan__ying__event_type _x_x590 = kk_gan__ying__event_type_unbox(_b_x142, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x589 = kk_gan__ying_event_type_to_string(_x_x590, _ctx); /*string*/
  return kk_string_box(_x_x589);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun597__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun597(kk_function_t _fself, kk_box_t _b_x145, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun597(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun597, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun597(kk_function_t _fself, kk_box_t _b_x145, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x598;
  kk_src_effect__runtime__runtime_state _x_x599 = kk_src_effect__runtime__runtime_state_unbox(_b_x145, KK_OWNED, _ctx); /*src/effect_runtime/runtime-state*/
  _x_x598 = kk_src_effect__runtime_json_state(_x_x599, _ctx); /*string*/
  return kk_string_box(_x_x598);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun603__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun603(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun603(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun603, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun603(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x604;
  kk_string_t _x_x605 = kk_string_unbox(_b_x148); /*string*/
  _x_x604 = kk_src_effect__runtime_extract_event_type(_x_x605, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x604, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun609__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun609(kk_function_t _fself, kk_box_t _b_x153, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun609(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun609, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun609(kk_function_t _fself, kk_box_t _b_x153, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x610;
  kk_gan__ying__event_type _x_x611 = kk_gan__ying__event_type_unbox(_b_x153, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x610 = kk_gan__ying_event_type_to_string(_x_x611, _ctx); /*string*/
  return kk_string_box(_x_x610);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun622__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun622(kk_function_t _fself, kk_box_t _b_x159, kk_box_t _b_x160, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun622(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun622, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun622(kk_function_t _fself, kk_box_t _b_x159, kk_box_t _b_x160, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x623;
  kk_gan__ying__event_type _x_x624 = kk_gan__ying__event_type_unbox(_b_x159, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_effect__runtime__runtime_state _x_x625 = kk_src_effect__runtime__runtime_state_unbox(_b_x160, KK_OWNED, _ctx); /*src/effect_runtime/runtime-state*/
  _x_x623 = kk_src_effect__runtime_cascade_profiled(_x_x624, _x_x625, _ctx); /*(int, src/effect_runtime/runtime-state)*/
  return kk_std_core_types__tuple2_box(_x_x623, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun644__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun644(kk_function_t _fself, kk_box_t _b_x165, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun644(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun644, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun644(kk_function_t _fself, kk_box_t _b_x165, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x645;
  kk_gan__ying__event_type _x_x646 = kk_gan__ying__event_type_unbox(_b_x165, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x645 = kk_gan__ying_event_type_to_string(_x_x646, _ctx); /*string*/
  return kk_string_box(_x_x645);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun655__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun655(kk_function_t _fself, kk_box_t _b_x168, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun655(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun655, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun655(kk_function_t _fself, kk_box_t _b_x168, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x656;
  kk_src_effect__runtime__runtime_state _x_x657 = kk_src_effect__runtime__runtime_state_unbox(_b_x168, KK_OWNED, _ctx); /*src/effect_runtime/runtime-state*/
  _x_x656 = kk_src_effect__runtime_json_state(_x_x657, _ctx); /*string*/
  return kk_string_box(_x_x656);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun678__t {
  struct kk_function_s _base;
  kk_string_t op_1;
  kk_src_effect__runtime__runtime_state state_1;
  kk_string_t x_4_10217;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun678(kk_function_t _fself, kk_box_t _b_x181, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun678(kk_string_t op_1, kk_src_effect__runtime__runtime_state state_1, kk_string_t x_4_10217, kk_context_t* _ctx) {
  struct kk_src_effect__runtime_server_loop_fun678__t* _self = kk_function_alloc_as(struct kk_src_effect__runtime_server_loop_fun678__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effect__runtime_server_loop_fun678, kk_context());
  _self->op_1 = op_1;
  _self->state_1 = state_1;
  _self->x_4_10217 = x_4_10217;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun678(kk_function_t _fself, kk_box_t _b_x181, kk_context_t* _ctx) {
  struct kk_src_effect__runtime_server_loop_fun678__t* _self = kk_function_as(struct kk_src_effect__runtime_server_loop_fun678__t*, _fself, _ctx);
  kk_string_t op_1 = _self->op_1; /* string */
  kk_src_effect__runtime__runtime_state state_1 = _self->state_1; /* src/effect_runtime/runtime-state */
  kk_string_t x_4_10217 = _self->x_4_10217; /* string */
  kk_drop_match(_self, {kk_string_dup(op_1, _ctx);kk_src_effect__runtime__runtime_state_dup(state_1, _ctx);kk_string_dup(x_4_10217, _ctx);}, {}, _ctx)
  kk_string_t _c_x10155_1_216 = kk_string_unbox(_b_x181); /*string*/;
  kk_unit_t _x_x679 = kk_Unit;
  kk_src_effect__runtime__mlift_server_loop_10201(x_4_10217, op_1, state_1, _c_x10155_1_216, _ctx);
  return kk_unit_box(_x_x679);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun682__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun682(kk_function_t _fself, kk_box_t _b_x184, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun682(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun682, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun682(kk_function_t _fself, kk_box_t _b_x184, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x683;
  kk_string_t _x_x684 = kk_string_unbox(_b_x184); /*string*/
  _x_x683 = kk_src_effect__runtime_extract_event_type(_x_x684, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x683, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun706__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun706(kk_function_t _fself, kk_box_t _b_x197, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun706(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun706, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun706(kk_function_t _fself, kk_box_t _b_x197, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x707;
  kk_string_t _x_x708 = kk_string_unbox(_b_x197); /*string*/
  _x_x707 = kk_src_effect__runtime_extract_event_type(_x_x708, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x707, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun710__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun710(kk_function_t _fself, kk_box_t _b_x203, kk_box_t _b_x204, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun710(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun710, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun710(kk_function_t _fself, kk_box_t _b_x203, kk_box_t _b_x204, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x711;
  kk_gan__ying__event_type _x_x712 = kk_gan__ying__event_type_unbox(_b_x203, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_effect__runtime__runtime_state _x_x713 = kk_src_effect__runtime__runtime_state_unbox(_b_x204, KK_OWNED, _ctx); /*src/effect_runtime/runtime-state*/
  _x_x711 = kk_src_effect__runtime_cascade_profiled(_x_x712, _x_x713, _ctx); /*(int, src/effect_runtime/runtime-state)*/
  return kk_std_core_types__tuple2_box(_x_x711, _ctx);
}


// lift anonymous function
struct kk_src_effect__runtime_server_loop_fun716__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effect__runtime_server_loop_fun716(kk_function_t _fself, kk_box_t _b_x211, kk_context_t* _ctx);
static kk_function_t kk_src_effect__runtime_new_server_loop_fun716(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effect__runtime_server_loop_fun716, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effect__runtime_server_loop_fun716(kk_function_t _fself, kk_box_t _b_x211, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x717 = kk_Unit;
  kk_src_effect__runtime__runtime_state _x_x718 = kk_src_effect__runtime__runtime_state_unbox(_b_x211, KK_OWNED, _ctx); /*src/effect_runtime/runtime-state*/
  kk_src_effect__runtime_server_loop(_x_x718, _ctx);
  return kk_unit_box(_x_x717);
}

kk_unit_t kk_src_effect__runtime_server_loop(kk_src_effect__runtime__runtime_state state_1, kk_context_t* _ctx) { /* (state : runtime-state) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_4_10217 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_4_10217, _ctx);
    kk_box_t _x_x539 = kk_std_core_hnd_yield_extend(kk_src_effect__runtime_new_server_loop_fun540(state_1, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x539); return kk_Unit;
  }
  {
    bool _match_x218;
    kk_string_t _x_x542 = kk_string_dup(x_4_10217, _ctx); /*string*/
    kk_string_t _x_x543 = kk_string_empty(); /*string*/
    _match_x218 = kk_string_is_eq(_x_x542,_x_x543,kk_context()); /*bool*/
    if (_match_x218) {
      kk_string_drop(x_4_10217, _ctx);
      kk_datatype_ptr_dropn(state_1, (KK_I32(3)), _ctx);
      kk_Unit; return kk_Unit;
    }
    {
      bool _match_x219;
      kk_string_t _x_x545 = kk_string_dup(x_4_10217, _ctx); /*string*/
      kk_string_t _x_x546;
      kk_define_string_literal(, _s_x547, 6, "\"quit\"", _ctx)
      _x_x546 = kk_string_dup(_s_x547, _ctx); /*string*/
      _match_x219 = kk_string_contains(_x_x545,_x_x546,kk_context()); /*bool*/
      if (_match_x219) {
        kk_string_drop(x_4_10217, _ctx);
        kk_datatype_ptr_dropn(state_1, (KK_I32(3)), _ctx);
        kk_string_t _x_x548;
        kk_define_string_literal(, _s_x549, 20, "{\"status\":\"stopped\"}", _ctx)
        _x_x548 = kk_string_dup(_s_x549, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x548, _ctx); return kk_Unit;
      }
      {
        kk_string_t op_1;
        kk_box_t _x_x550;
        kk_box_t _x_x554;
        kk_string_t _x_x555 = kk_string_dup(x_4_10217, _ctx); /*string*/
        _x_x554 = kk_string_box(_x_x555); /*10000*/
        _x_x550 = kk_std_core_hnd__open_none1(kk_src_effect__runtime_new_server_loop_fun551(_ctx), _x_x554, _ctx); /*10001*/
        op_1 = kk_string_unbox(_x_x550); /*string*/
        kk_string_t x_5_10220;
        if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
          kk_gan__ying__event_type et_1;
          kk_box_t _x_x557;
          kk_box_t _x_x561;
          kk_string_t _x_x562 = kk_string_dup(x_4_10217, _ctx); /*string*/
          _x_x561 = kk_string_box(_x_x562); /*10000*/
          _x_x557 = kk_std_core_hnd__open_none1(kk_src_effect__runtime_new_server_loop_fun558(_ctx), _x_x561, _ctx); /*10001*/
          et_1 = kk_gan__ying__event_type_unbox(_x_x557, KK_OWNED, _ctx); /*gan_ying/event-type*/
          kk_evv_t w_2_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_string_t name_10027_0;
          kk_string_t _x_x563;
          kk_define_string_literal(, _s_x564, 5, "emit_", _ctx)
          _x_x563 = kk_string_dup(_s_x564, _ctx); /*string*/
          kk_string_t _x_x565 = kk_gan__ying_event_type_to_string(et_1, _ctx); /*string*/
          name_10027_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x563, _x_x565, _ctx); /*string*/
          kk_src_effect__runtime__runtime_state x_6;
          kk_std_core_types__list _x_x566;
          kk_box_t _x_x567;
          kk_gan__ying__resonance_event _x_x568;
          kk_string_t _x_x569;
          kk_define_string_literal(, _s_x570, 14, "effect_runtime", _ctx)
          _x_x569 = kk_string_dup(_s_x570, _ctx); /*string*/
          kk_string_t _x_x571 = kk_string_empty(); /*string*/
          _x_x568 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x569, et_1, _x_x571, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
          _x_x567 = kk_gan__ying__resonance_event_box(_x_x568, _ctx); /*10021*/
          kk_std_core_types__list _x_x573;
          {
            struct kk_src_effect__runtime_Runtime_state* _con_x574 = kk_src_effect__runtime__as_Runtime_state(state_1, _ctx);
            kk_std_core_types__list _x_7 = _con_x574->events;
            kk_std_core_types__list_dup(_x_7, _ctx);
            _x_x573 = _x_7; /*list<gan_ying/resonance-event>*/
          }
          _x_x566 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x567, _x_x573, _ctx); /*list<10021>*/
          kk_std_core_types__list _x_x575;
          kk_box_t _x_x576;
          kk_hot__paths__path_profile _x_x577 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, name_10027_0, kk_integer_from_small(1), 0x1.0624dd2f1a9fcp-10, 0x1.0624dd2f1a9fcp-10, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_Compute(_ctx), _ctx); /*hot_paths/path-profile*/
          _x_x576 = kk_hot__paths__path_profile_box(_x_x577, _ctx); /*10021*/
          kk_std_core_types__list _x_x578;
          {
            struct kk_src_effect__runtime_Runtime_state* _con_x579 = kk_src_effect__runtime__as_Runtime_state(state_1, _ctx);
            kk_std_core_types__list _x_0_0 = _con_x579->profiles;
            kk_std_core_types__list_dup(_x_0_0, _ctx);
            _x_x578 = _x_0_0; /*list<hot_paths/path-profile>*/
          }
          _x_x575 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x576, _x_x578, _ctx); /*list<10021>*/
          kk_integer_t _x_x580;
          kk_integer_t _x_x581;
          {
            struct kk_src_effect__runtime_Runtime_state* _con_x582 = kk_src_effect__runtime__as_Runtime_state(state_1, _ctx);
            kk_integer_t _x_1_0 = _con_x582->total_ops;
            kk_integer_dup(_x_1_0, _ctx);
            _x_x581 = _x_1_0; /*int*/
          }
          _x_x580 = kk_integer_add_small_const(_x_x581, 1, _ctx); /*int*/
          x_6 = kk_src_effect__runtime__new_Runtime_state(kk_reuse_null, 0, _x_x566, _x_x575, _x_x580, _ctx); /*src/effect_runtime/runtime-state*/
          kk_unit_t keep_2_0 = kk_Unit;
          kk_evv_set(w_2_0,kk_context());
          kk_string_t _x_x583;
          kk_define_string_literal(, _s_x584, 12, "{\"emitted\":\"", _ctx)
          _x_x583 = kk_string_dup(_s_x584, _ctx); /*string*/
          kk_string_t _x_x585;
          kk_string_t _x_x586;
          kk_box_t _x_x587 = kk_std_core_hnd__open_none1(kk_src_effect__runtime_new_server_loop_fun588(_ctx), kk_gan__ying__event_type_box(et_1, _ctx), _ctx); /*10001*/
          _x_x586 = kk_string_unbox(_x_x587); /*string*/
          kk_string_t _x_x591;
          kk_string_t _x_x592;
          kk_define_string_literal(, _s_x593, 10, "\",\"state\":", _ctx)
          _x_x592 = kk_string_dup(_s_x593, _ctx); /*string*/
          kk_string_t _x_x594;
          kk_string_t _x_x595;
          kk_box_t _x_x596 = kk_std_core_hnd__open_none1(kk_src_effect__runtime_new_server_loop_fun597(_ctx), kk_src_effect__runtime__runtime_state_box(x_6, _ctx), _ctx); /*10001*/
          _x_x595 = kk_string_unbox(_x_x596); /*string*/
          kk_string_t _x_x600;
          kk_define_string_literal(, _s_x601, 1, "}", _ctx)
          _x_x600 = kk_string_dup(_s_x601, _ctx); /*string*/
          _x_x594 = kk_std_core_types__lp__plus__plus__rp_(_x_x595, _x_x600, _ctx); /*string*/
          _x_x591 = kk_std_core_types__lp__plus__plus__rp_(_x_x592, _x_x594, _ctx); /*string*/
          _x_x585 = kk_std_core_types__lp__plus__plus__rp_(_x_x586, _x_x591, _ctx); /*string*/
          x_5_10220 = kk_std_core_types__lp__plus__plus__rp_(_x_x583, _x_x585, _ctx); /*string*/
          goto _match_x556;
        }
        if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
          kk_gan__ying__event_type et_0_0_0;
          kk_box_t _x_x602;
          kk_box_t _x_x606;
          kk_string_t _x_x607 = kk_string_dup(x_4_10217, _ctx); /*string*/
          _x_x606 = kk_string_box(_x_x607); /*10000*/
          _x_x602 = kk_std_core_hnd__open_none1(kk_src_effect__runtime_new_server_loop_fun603(_ctx), _x_x606, _ctx); /*10001*/
          et_0_0_0 = kk_gan__ying__event_type_unbox(_x_x602, KK_OWNED, _ctx); /*gan_ying/event-type*/
          kk_string_t details_10039_0;
          kk_box_t _x_x608 = kk_std_core_hnd__open_none1(kk_src_effect__runtime_new_server_loop_fun609(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _ctx); /*10001*/
          details_10039_0 = kk_string_unbox(_x_x608); /*string*/
          kk_unit_t ___2 = kk_Unit;
          kk_string_t _x_x612;
          kk_string_t _x_x613;
          kk_define_string_literal(, _s_x614, 8, "[TRACE] ", _ctx)
          _x_x613 = kk_string_dup(_s_x614, _ctx); /*string*/
          kk_string_t _x_x615;
          kk_string_t _x_x616;
          kk_define_string_literal(, _s_x617, 13, "cascade_start", _ctx)
          _x_x616 = kk_string_dup(_s_x617, _ctx); /*string*/
          kk_string_t _x_x618;
          kk_string_t _x_x619;
          kk_define_string_literal(, _s_x620, 2, ": ", _ctx)
          _x_x619 = kk_string_dup(_s_x620, _ctx); /*string*/
          _x_x618 = kk_std_core_types__lp__plus__plus__rp_(_x_x619, details_10039_0, _ctx); /*string*/
          _x_x615 = kk_std_core_types__lp__plus__plus__rp_(_x_x616, _x_x618, _ctx); /*string*/
          _x_x612 = kk_std_core_types__lp__plus__plus__rp_(_x_x613, _x_x615, _ctx); /*string*/
          kk_std_core_console_printsln(_x_x612, _ctx);
          kk_std_core_types__tuple2 _match_x223;
          kk_box_t _x_x621;
          kk_box_t _x_x626;
          kk_src_effect__runtime__runtime_state _x_x627 = kk_src_effect__runtime__runtime_state_dup(state_1, _ctx); /*src/effect_runtime/runtime-state*/
          _x_x626 = kk_src_effect__runtime__runtime_state_box(_x_x627, _ctx); /*10001*/
          _x_x621 = kk_std_core_hnd__open_none2(kk_src_effect__runtime_new_server_loop_fun622(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _x_x626, _ctx); /*10002*/
          _match_x223 = kk_std_core_types__tuple2_unbox(_x_x621, KK_OWNED, _ctx); /*(int, src/effect_runtime/runtime-state)*/
          {
            kk_box_t _box_x161 = _match_x223.fst;
            kk_box_t _box_x162 = _match_x223.snd;
            kk_src_effect__runtime__runtime_state new_state_0_0 = kk_src_effect__runtime__runtime_state_unbox(_box_x162, KK_BORROWED, _ctx);
            struct kk_src_effect__runtime_Runtime_state* _con_x628 = kk_src_effect__runtime__as_Runtime_state(new_state_0_0, _ctx);
            kk_integer_t handlers_0 = kk_integer_unbox(_box_x161, _ctx);
            kk_integer_dup(handlers_0, _ctx);
            kk_std_core_types__tuple2_drop(_match_x223, _ctx);
            kk_string_t details_0_10041_0;
            kk_integer_t _x_x629 = kk_integer_dup(handlers_0, _ctx); /*int*/
            details_0_10041_0 = kk_std_core_int_show(_x_x629, _ctx); /*string*/
            kk_unit_t ___0_0 = kk_Unit;
            kk_string_t _x_x630;
            kk_string_t _x_x631;
            kk_define_string_literal(, _s_x632, 8, "[TRACE] ", _ctx)
            _x_x631 = kk_string_dup(_s_x632, _ctx); /*string*/
            kk_string_t _x_x633;
            kk_string_t _x_x634;
            kk_define_string_literal(, _s_x635, 11, "cascade_end", _ctx)
            _x_x634 = kk_string_dup(_s_x635, _ctx); /*string*/
            kk_string_t _x_x636;
            kk_string_t _x_x637;
            kk_define_string_literal(, _s_x638, 2, ": ", _ctx)
            _x_x637 = kk_string_dup(_s_x638, _ctx); /*string*/
            _x_x636 = kk_std_core_types__lp__plus__plus__rp_(_x_x637, details_0_10041_0, _ctx); /*string*/
            _x_x633 = kk_std_core_types__lp__plus__plus__rp_(_x_x634, _x_x636, _ctx); /*string*/
            _x_x630 = kk_std_core_types__lp__plus__plus__rp_(_x_x631, _x_x633, _ctx); /*string*/
            kk_std_core_console_printsln(_x_x630, _ctx);
            kk_string_t _x_x639;
            kk_define_string_literal(, _s_x640, 12, "{\"cascade\":\"", _ctx)
            _x_x639 = kk_string_dup(_s_x640, _ctx); /*string*/
            kk_string_t _x_x641;
            kk_string_t _x_x642;
            kk_box_t _x_x643 = kk_std_core_hnd__open_none1(kk_src_effect__runtime_new_server_loop_fun644(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _ctx); /*10001*/
            _x_x642 = kk_string_unbox(_x_x643); /*string*/
            kk_string_t _x_x647;
            kk_string_t _x_x648;
            kk_define_string_literal(, _s_x649, 13, "\",\"handlers\":", _ctx)
            _x_x648 = kk_string_dup(_s_x649, _ctx); /*string*/
            kk_string_t _x_x650;
            kk_string_t _x_x651 = kk_std_core_int_show(handlers_0, _ctx); /*string*/
            kk_string_t _x_x652;
            kk_define_string_literal(, _s_x653, 1, "}", _ctx)
            _x_x652 = kk_string_dup(_s_x653, _ctx); /*string*/
            _x_x650 = kk_std_core_types__lp__plus__plus__rp_(_x_x651, _x_x652, _ctx); /*string*/
            _x_x647 = kk_std_core_types__lp__plus__plus__rp_(_x_x648, _x_x650, _ctx); /*string*/
            _x_x641 = kk_std_core_types__lp__plus__plus__rp_(_x_x642, _x_x647, _ctx); /*string*/
            x_5_10220 = kk_std_core_types__lp__plus__plus__rp_(_x_x639, _x_x641, _ctx); /*string*/
            goto _match_x556;
          }
        }
        if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
          kk_box_t _x_x654;
          kk_box_t _x_x658;
          kk_src_effect__runtime__runtime_state _x_x659 = kk_src_effect__runtime__runtime_state_dup(state_1, _ctx); /*src/effect_runtime/runtime-state*/
          _x_x658 = kk_src_effect__runtime__runtime_state_box(_x_x659, _ctx); /*10000*/
          _x_x654 = kk_std_core_hnd__open_none1(kk_src_effect__runtime_new_server_loop_fun655(_ctx), _x_x658, _ctx); /*10001*/
          x_5_10220 = kk_string_unbox(_x_x654); /*string*/
          goto _match_x556;
        }
        if (kk_string_cmp_cstr_borrow(op_1, "profile", _ctx) == 0) {
          kk_evv_t w_3_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_3_0 = kk_Unit;
          kk_evv_set(w_3_0,kk_context());
          kk_evv_t w_4 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_integer_t x_4;
          {
            struct kk_src_effect__runtime_Runtime_state* _con_x660 = kk_src_effect__runtime__as_Runtime_state(state_1, _ctx);
            kk_std_core_types__list _x_2_0_0 = _con_x660->profiles;
            kk_std_core_types__list_dup(_x_2_0_0, _ctx);
            if (kk_std_core_types__is_Nil(_x_2_0_0, _ctx)) {
              x_4 = kk_integer_from_small(0); /*int*/
            }
            else {
              kk_std_core_types__list_drop(_x_2_0_0, _ctx);
              kk_std_core_types__list _x_x661;
              {
                struct kk_src_effect__runtime_Runtime_state* _con_x662 = kk_src_effect__runtime__as_Runtime_state(state_1, _ctx);
                kk_std_core_types__list _x_2_0_1 = _con_x662->profiles;
                kk_std_core_types__list_dup(_x_2_0_1, _ctx);
                _x_x661 = _x_2_0_1; /*list<hot_paths/path-profile>*/
              }
              x_4 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x661, kk_integer_from_small(0), _ctx); /*int*/
            }
          }
          kk_unit_t keep_4 = kk_Unit;
          kk_evv_set(w_4,kk_context());
          kk_evv_t w_5 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_5 = kk_Unit;
          kk_evv_set(w_5,kk_context());
          kk_string_t _x_x663;
          kk_define_string_literal(, _s_x664, 12, "{\"profiles\":", _ctx)
          _x_x663 = kk_string_dup(_s_x664, _ctx); /*string*/
          kk_string_t _x_x665;
          kk_string_t _x_x666 = kk_std_core_int_show(x_4, _ctx); /*string*/
          kk_string_t _x_x667;
          kk_string_t _x_x668;
          kk_define_string_literal(, _s_x669, 13, ",\"total_ops\":", _ctx)
          _x_x668 = kk_string_dup(_s_x669, _ctx); /*string*/
          kk_string_t _x_x670;
          kk_string_t _x_x671;
          kk_integer_t _x_x672;
          {
            struct kk_src_effect__runtime_Runtime_state* _con_x673 = kk_src_effect__runtime__as_Runtime_state(state_1, _ctx);
            kk_integer_t _x_3_0 = _con_x673->total_ops;
            kk_integer_dup(_x_3_0, _ctx);
            _x_x672 = _x_3_0; /*int*/
          }
          _x_x671 = kk_std_core_int_show(_x_x672, _ctx); /*string*/
          kk_string_t _x_x674;
          kk_define_string_literal(, _s_x675, 1, "}", _ctx)
          _x_x674 = kk_string_dup(_s_x675, _ctx); /*string*/
          _x_x670 = kk_std_core_types__lp__plus__plus__rp_(_x_x671, _x_x674, _ctx); /*string*/
          _x_x667 = kk_std_core_types__lp__plus__plus__rp_(_x_x668, _x_x670, _ctx); /*string*/
          _x_x665 = kk_std_core_types__lp__plus__plus__rp_(_x_x666, _x_x667, _ctx); /*string*/
          x_5_10220 = kk_std_core_types__lp__plus__plus__rp_(_x_x663, _x_x665, _ctx); /*string*/
          goto _match_x556;
        }
        {
          kk_define_string_literal(, _s_x676, 22, "{\"error\":\"unknown op\"}", _ctx)
          x_5_10220 = kk_string_dup(_s_x676, _ctx); /*string*/
        }
        _match_x556: ;
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_5_10220, _ctx);
          kk_box_t _x_x677 = kk_std_core_hnd_yield_extend(kk_src_effect__runtime_new_server_loop_fun678(op_1, state_1, x_4_10217, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x677); return kk_Unit;
        }
        {
          kk_unit_t ___1_0 = kk_Unit;
          kk_std_core_console_printsln(x_5_10220, _ctx);
          kk_src_effect__runtime__runtime_state x_8_10229;
          if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_gan__ying__event_type et_1_0_0;
            kk_box_t _x_x681 = kk_std_core_hnd__open_none1(kk_src_effect__runtime_new_server_loop_fun682(_ctx), kk_string_box(x_4_10217), _ctx); /*10001*/
            et_1_0_0 = kk_gan__ying__event_type_unbox(_x_x681, KK_OWNED, _ctx); /*gan_ying/event-type*/
            kk_evv_t w_4_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_string_t name_0_10042_0;
            kk_string_t _x_x685;
            kk_define_string_literal(, _s_x686, 5, "emit_", _ctx)
            _x_x685 = kk_string_dup(_s_x686, _ctx); /*string*/
            kk_string_t _x_x687 = kk_gan__ying_event_type_to_string(et_1_0_0, _ctx); /*string*/
            name_0_10042_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x685, _x_x687, _ctx); /*string*/
            kk_src_effect__runtime__runtime_state x_9;
            kk_std_core_types__list _x_x688;
            kk_box_t _x_x689;
            kk_gan__ying__resonance_event _x_x690;
            kk_string_t _x_x691;
            kk_define_string_literal(, _s_x692, 14, "effect_runtime", _ctx)
            _x_x691 = kk_string_dup(_s_x692, _ctx); /*string*/
            kk_string_t _x_x693 = kk_string_empty(); /*string*/
            _x_x690 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x691, et_1_0_0, _x_x693, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
            _x_x689 = kk_gan__ying__resonance_event_box(_x_x690, _ctx); /*10021*/
            kk_std_core_types__list _x_x695;
            {
              struct kk_src_effect__runtime_Runtime_state* _con_x696 = kk_src_effect__runtime__as_Runtime_state(state_1, _ctx);
              kk_std_core_types__list _x_4_0 = _con_x696->events;
              kk_std_core_types__list_dup(_x_4_0, _ctx);
              _x_x695 = _x_4_0; /*list<gan_ying/resonance-event>*/
            }
            _x_x688 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x689, _x_x695, _ctx); /*list<10021>*/
            kk_std_core_types__list _x_x697;
            kk_box_t _x_x698;
            kk_hot__paths__path_profile _x_x699 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, name_0_10042_0, kk_integer_from_small(1), 0x1.0624dd2f1a9fcp-10, 0x1.0624dd2f1a9fcp-10, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_Compute(_ctx), _ctx); /*hot_paths/path-profile*/
            _x_x698 = kk_hot__paths__path_profile_box(_x_x699, _ctx); /*10021*/
            kk_std_core_types__list _x_x700;
            {
              struct kk_src_effect__runtime_Runtime_state* _con_x701 = kk_src_effect__runtime__as_Runtime_state(state_1, _ctx);
              kk_std_core_types__list _x_5_0 = _con_x701->profiles;
              kk_std_core_types__list_dup(_x_5_0, _ctx);
              _x_x700 = _x_5_0; /*list<hot_paths/path-profile>*/
            }
            _x_x697 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x698, _x_x700, _ctx); /*list<10021>*/
            kk_integer_t _x_x702;
            kk_integer_t _x_x703;
            {
              struct kk_src_effect__runtime_Runtime_state* _con_x704 = kk_src_effect__runtime__as_Runtime_state(state_1, _ctx);
              kk_std_core_types__list _pat_0_7_0 = _con_x704->events;
              kk_std_core_types__list _pat_1_8_0 = _con_x704->profiles;
              kk_integer_t _x_6_0 = _con_x704->total_ops;
              if kk_likely(kk_datatype_ptr_is_unique(state_1, _ctx)) {
                kk_std_core_types__list_drop(_pat_1_8_0, _ctx);
                kk_std_core_types__list_drop(_pat_0_7_0, _ctx);
                kk_datatype_ptr_free(state_1, _ctx);
              }
              else {
                kk_integer_dup(_x_6_0, _ctx);
                kk_datatype_ptr_decref(state_1, _ctx);
              }
              _x_x703 = _x_6_0; /*int*/
            }
            _x_x702 = kk_integer_add_small_const(_x_x703, 1, _ctx); /*int*/
            x_9 = kk_src_effect__runtime__new_Runtime_state(kk_reuse_null, 0, _x_x688, _x_x697, _x_x702, _ctx); /*src/effect_runtime/runtime-state*/
            kk_unit_t keep_4_0 = kk_Unit;
            kk_evv_set(w_4_0,kk_context());
            x_8_10229 = x_9; /*src/effect_runtime/runtime-state*/
            goto _match_x680;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_gan__ying__event_type et_2_0_0;
            kk_box_t _x_x705 = kk_std_core_hnd__open_none1(kk_src_effect__runtime_new_server_loop_fun706(_ctx), kk_string_box(x_4_10217), _ctx); /*10001*/
            et_2_0_0 = kk_gan__ying__event_type_unbox(_x_x705, KK_OWNED, _ctx); /*gan_ying/event-type*/
            kk_std_core_types__tuple2 _match_x222;
            kk_box_t _x_x709 = kk_std_core_hnd__open_none2(kk_src_effect__runtime_new_server_loop_fun710(_ctx), kk_gan__ying__event_type_box(et_2_0_0, _ctx), kk_src_effect__runtime__runtime_state_box(state_1, _ctx), _ctx); /*10002*/
            _match_x222 = kk_std_core_types__tuple2_unbox(_x_x709, KK_OWNED, _ctx); /*(int, src/effect_runtime/runtime-state)*/
            {
              kk_box_t _box_x205 = _match_x222.fst;
              kk_box_t _box_x206 = _match_x222.snd;
              kk_src_effect__runtime__runtime_state ns_0 = kk_src_effect__runtime__runtime_state_unbox(_box_x206, KK_BORROWED, _ctx);
              struct kk_src_effect__runtime_Runtime_state* _con_x714 = kk_src_effect__runtime__as_Runtime_state(ns_0, _ctx);
              kk_src_effect__runtime__runtime_state_dup(ns_0, _ctx);
              kk_std_core_types__tuple2_drop(_match_x222, _ctx);
              x_8_10229 = ns_0; /*src/effect_runtime/runtime-state*/
              goto _match_x680;
            }
          }
          {
            kk_string_drop(x_4_10217, _ctx);
            kk_string_drop(op_1, _ctx);
            x_8_10229 = state_1; /*src/effect_runtime/runtime-state*/
          }
          _match_x680: ;
          if (kk_yielding(kk_context())) {
            kk_datatype_ptr_dropn(x_8_10229, (KK_I32(3)), _ctx);
            kk_box_t _x_x715 = kk_std_core_hnd_yield_extend(kk_src_effect__runtime_new_server_loop_fun716(_ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x715); return kk_Unit;
          }
          { // tailcall
            state_1 = x_8_10229;
            goto kk__tailcall;
          }
        }
      }
    }
  }
}

// initialization
void kk_src_effect__runtime__init(kk_context_t* _ctx){
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
void kk_src_effect__runtime__done(kk_context_t* _ctx){
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
