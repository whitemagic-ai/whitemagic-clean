// Koka generated module: src/unified_runtime_v3, koka version: 3.2.2, platform: 64-bit
#include "src_unified__runtime__v3.h"

kk_src_unified__runtime__v3__unified_state kk_src_unified__runtime__v3_unified_state_fs__copy(kk_src_unified__runtime__v3__unified_state _this, kk_std_core_types__optional events, kk_std_core_types__optional profiles, kk_std_core_types__optional total_ops, kk_std_core_types__optional batch_count, kk_std_core_types__optional session_start, kk_context_t* _ctx) { /* (unified-state, events : ? (list<gan_ying/resonance-event>), profiles : ? (list<hot_paths/path-profile>), total-ops : ? int, batch-count : ? int, session-start : ? float64) -> unified-state */ 
  kk_std_core_types__list _x_x310;
  if (kk_std_core_types__is_Optional(events, _ctx)) {
    kk_box_t _box_x0 = events._cons._Optional.value;
    kk_std_core_types__list _uniq_events_75 = kk_std_core_types__list_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_events_75, _ctx);
    kk_std_core_types__optional_drop(events, _ctx);
    _x_x310 = _uniq_events_75; /*list<gan_ying/resonance-event>*/
  }
  else {
    kk_std_core_types__optional_drop(events, _ctx);
    {
      struct kk_src_unified__runtime__v3_Unified_state* _con_x311 = kk_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _x = _con_x311->events;
      kk_std_core_types__list_dup(_x, _ctx);
      _x_x310 = _x; /*list<gan_ying/resonance-event>*/
    }
  }
  kk_std_core_types__list _x_x312;
  if (kk_std_core_types__is_Optional(profiles, _ctx)) {
    kk_box_t _box_x1 = profiles._cons._Optional.value;
    kk_std_core_types__list _uniq_profiles_83 = kk_std_core_types__list_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_profiles_83, _ctx);
    kk_std_core_types__optional_drop(profiles, _ctx);
    _x_x312 = _uniq_profiles_83; /*list<hot_paths/path-profile>*/
  }
  else {
    kk_std_core_types__optional_drop(profiles, _ctx);
    {
      struct kk_src_unified__runtime__v3_Unified_state* _con_x313 = kk_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x313->profiles;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x312 = _x_0; /*list<hot_paths/path-profile>*/
    }
  }
  kk_integer_t _x_x314;
  if (kk_std_core_types__is_Optional(total_ops, _ctx)) {
    kk_box_t _box_x2 = total_ops._cons._Optional.value;
    kk_integer_t _uniq_total_ops_91 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_total_ops_91, _ctx);
    kk_std_core_types__optional_drop(total_ops, _ctx);
    _x_x314 = _uniq_total_ops_91; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(total_ops, _ctx);
    {
      struct kk_src_unified__runtime__v3_Unified_state* _con_x315 = kk_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
      kk_integer_t _x_1 = _con_x315->total_ops;
      kk_integer_dup(_x_1, _ctx);
      _x_x314 = _x_1; /*int*/
    }
  }
  kk_integer_t _x_x316;
  if (kk_std_core_types__is_Optional(batch_count, _ctx)) {
    kk_box_t _box_x3 = batch_count._cons._Optional.value;
    kk_integer_t _uniq_batch_count_99 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_batch_count_99, _ctx);
    kk_std_core_types__optional_drop(batch_count, _ctx);
    _x_x316 = _uniq_batch_count_99; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(batch_count, _ctx);
    {
      struct kk_src_unified__runtime__v3_Unified_state* _con_x317 = kk_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
      kk_integer_t _x_2 = _con_x317->batch_count;
      kk_integer_dup(_x_2, _ctx);
      _x_x316 = _x_2; /*int*/
    }
  }
  double _x_x318;
  if (kk_std_core_types__is_Optional(session_start, _ctx)) {
    kk_box_t _box_x4 = session_start._cons._Optional.value;
    double _uniq_session_start_107 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(session_start, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(4)), _ctx);
    _x_x318 = _uniq_session_start_107; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(session_start, _ctx);
    {
      struct kk_src_unified__runtime__v3_Unified_state* _con_x319 = kk_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _pat_0_4 = _con_x319->events;
      kk_std_core_types__list _pat_1_5 = _con_x319->profiles;
      kk_integer_t _pat_2_4 = _con_x319->total_ops;
      kk_integer_t _pat_3_4 = _con_x319->batch_count;
      double _x_3 = _con_x319->session_start;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_3_4, _ctx);
        kk_integer_drop(_pat_2_4, _ctx);
        kk_std_core_types__list_drop(_pat_1_5, _ctx);
        kk_std_core_types__list_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x318 = _x_3; /*float64*/
    }
  }
  return kk_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x310, _x_x312, _x_x314, _x_x316, _x_x318, _ctx);
}

kk_src_unified__runtime__v3__unified_state kk_src_unified__runtime__v3_emit_profiled(kk_gan__ying__event_type et, kk_string_t source, kk_src_unified__runtime__v3__unified_state state, kk_context_t* _ctx) { /* (et : gan_ying/event-type, source : string, state : unified-state) -> unified-state */ 
  kk_hot__paths__path_profile profile;
  kk_string_t _x_x320 = kk_gan__ying_event_type_to_string(et, _ctx); /*string*/
  profile = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x320, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_std_core_types__list _x_x321;
  kk_box_t _x_x322;
  kk_gan__ying__resonance_event _x_x323;
  kk_string_t _x_x324 = kk_string_empty(); /*string*/
  _x_x323 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, source, et, _x_x324, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x322 = kk_gan__ying__resonance_event_box(_x_x323, _ctx); /*10021*/
  kk_std_core_types__list _x_x326;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x327 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x = _con_x327->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x326 = _x; /*list<gan_ying/resonance-event>*/
  }
  _x_x321 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x322, _x_x326, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x328;
  kk_std_core_types__list _x_x329;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x330 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x_0 = _con_x330->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x329 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x328 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile, _ctx), _x_x329, _ctx); /*list<10021>*/
  kk_integer_t _x_x331;
  kk_integer_t _x_x332;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x333 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_integer_t _x_1 = _con_x333->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x332 = _x_1; /*int*/
  }
  _x_x331 = kk_integer_add_small_const(_x_x332, 1, _ctx); /*int*/
  kk_integer_t _x_x334;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x335 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_integer_t _x_2 = _con_x335->batch_count;
    kk_integer_dup(_x_2, _ctx);
    _x_x334 = _x_2; /*int*/
  }
  double _x_x336;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x337 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _pat_0_3 = _con_x337->events;
    kk_std_core_types__list _pat_1_3 = _con_x337->profiles;
    kk_integer_t _pat_2_3 = _con_x337->total_ops;
    kk_integer_t _pat_3_3 = _con_x337->batch_count;
    double _x_3 = _con_x337->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_3_3, _ctx);
      kk_integer_drop(_pat_2_3, _ctx);
      kk_std_core_types__list_drop(_pat_1_3, _ctx);
      kk_std_core_types__list_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x336 = _x_3; /*float64*/
  }
  return kk_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x321, _x_x328, _x_x331, _x_x334, _x_x336, _ctx);
}

kk_std_core_types__tuple2 kk_src_unified__runtime__v3_cascade_profiled(kk_gan__ying__event_type et, kk_src_unified__runtime__v3__unified_state state, kk_context_t* _ctx) { /* (et : gan_ying/event-type, state : unified-state) -> (int, unified-state) */ 
  kk_src_unified__runtime__v3__unified_state new_state;
  kk_std_core_types__list _x_x338;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x339 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x = _con_x339->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x338 = _x; /*list<gan_ying/resonance-event>*/
  }
  kk_std_core_types__list _x_x340;
  kk_box_t _x_x341;
  kk_hot__paths__path_profile _x_x342;
  kk_string_t _x_x343;
  kk_define_string_literal(, _s_x344, 13, "cascade_check", _ctx)
  _x_x343 = kk_string_dup(_s_x344, _ctx); /*string*/
  _x_x342 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x343, kk_integer_from_small(1), 0x1p-1, 0x1p-1, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_Compute(_ctx), _ctx); /*hot_paths/path-profile*/
  _x_x341 = kk_hot__paths__path_profile_box(_x_x342, _ctx); /*10021*/
  kk_std_core_types__list _x_x345;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x346 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x_0 = _con_x346->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x345 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x340 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x341, _x_x345, _ctx); /*list<10021>*/
  kk_integer_t _x_x347;
  kk_integer_t _x_x348;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x349 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_integer_t _x_1 = _con_x349->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x348 = _x_1; /*int*/
  }
  _x_x347 = kk_integer_add_small_const(_x_x348, 1, _ctx); /*int*/
  kk_integer_t _x_x350;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x351 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_integer_t _x_2 = _con_x351->batch_count;
    kk_integer_dup(_x_2, _ctx);
    _x_x350 = _x_2; /*int*/
  }
  double _x_x352;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x353 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _pat_0_3 = _con_x353->events;
    kk_std_core_types__list _pat_1_3 = _con_x353->profiles;
    kk_integer_t _pat_2_3 = _con_x353->total_ops;
    kk_integer_t _pat_3_3 = _con_x353->batch_count;
    double _x_3 = _con_x353->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_3_3, _ctx);
      kk_integer_drop(_pat_2_3, _ctx);
      kk_std_core_types__list_drop(_pat_1_3, _ctx);
      kk_std_core_types__list_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x352 = _x_3; /*float64*/
  }
  new_state = kk_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x338, _x_x340, _x_x347, _x_x350, _x_x352, _ctx); /*src/unified_runtime_v3/unified-state*/
  kk_box_t _x_x354;
  kk_integer_t _x_x355;
  if (kk_gan__ying__is_MemoryCreated(et, _ctx)) {
    _x_x355 = kk_integer_from_small(3); /*int*/
    goto _match_x356;
  }
  if (kk_gan__ying__is_MemoryUpdated(et, _ctx)) {
    _x_x355 = kk_integer_from_small(2); /*int*/
    goto _match_x356;
  }
  if (kk_gan__ying__is_ThreatDetected(et, _ctx)) {
    _x_x355 = kk_integer_from_small(5); /*int*/
    goto _match_x356;
  }
  if (kk_gan__ying__is_FlowStateEntered(et, _ctx)) {
    _x_x355 = kk_integer_from_small(2); /*int*/
    goto _match_x356;
  }
  {
    _x_x355 = kk_integer_from_small(1); /*int*/
  }
  _match_x356: ;
  _x_x354 = kk_integer_box(_x_x355, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x354, kk_src_unified__runtime__v3__unified_state_box(new_state, _ctx), _ctx);
}
 
// Build batch response for n commands

kk_string_t kk_src_unified__runtime__v3_batch_response(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> string */ 
  bool _match_x281 = kk_integer_eq_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x281) {
    kk_integer_drop(n, _ctx);
    kk_define_string_literal(, _s_x361, 58, "{\"request_id\":\"batch\",\"results\":[],\"commands_processed\":0}", _ctx)
    return kk_string_dup(_s_x361, _ctx);
  }
  {
    bool _match_x282 = kk_integer_eq_borrow(n,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x282) {
      kk_integer_drop(n, _ctx);
      kk_define_string_literal(, _s_x362, 103, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":1}", _ctx)
      return kk_string_dup(_s_x362, _ctx);
    }
    {
      bool _match_x283 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
      if (_match_x283) {
        kk_integer_drop(n, _ctx);
        kk_define_string_literal(, _s_x363, 149, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":2}", _ctx)
        return kk_string_dup(_s_x363, _ctx);
      }
      {
        bool _match_x284;
        bool _brw_x285 = kk_integer_eq_borrow(n,(kk_integer_from_small(3)),kk_context()); /*bool*/;
        kk_integer_drop(n, _ctx);
        _match_x284 = _brw_x285; /*bool*/
        if (_match_x284) {
          kk_define_string_literal(, _s_x364, 195, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":3,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":3}", _ctx)
          return kk_string_dup(_s_x364, _ctx);
        }
        {
          kk_define_string_literal(, _s_x365, 287, "{\"request_id\":\"batch\",\"results\":[{\"id\":1,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":2,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":3,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":4,\"status\":\"ok\",\"result\":{\"pong\":true}},{\"id\":5,\"status\":\"ok\",\"result\":{\"pong\":true}}],\"commands_processed\":5}", _ctx)
          return kk_string_dup(_s_x365, _ctx);
        }
      }
    }
  }
}

kk_string_t kk_src_unified__runtime__v3_json_state(kk_src_unified__runtime__v3__unified_state s, kk_context_t* _ctx) { /* (s : unified-state) -> string */ 
  kk_string_t _x_x366;
  kk_define_string_literal(, _s_x367, 10, "{\"events\":", _ctx)
  _x_x366 = kk_string_dup(_s_x367, _ctx); /*string*/
  kk_string_t _x_x368;
  kk_string_t _x_x369;
  kk_integer_t _x_x370;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x371 = kk_src_unified__runtime__v3__as_Unified_state(s, _ctx);
    kk_std_core_types__list _x = _con_x371->events;
    kk_std_core_types__list_dup(_x, _ctx);
    if (kk_std_core_types__is_Nil(_x, _ctx)) {
      _x_x370 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_std_core_types__list_drop(_x, _ctx);
      kk_std_core_types__list _x_x372;
      {
        struct kk_src_unified__runtime__v3_Unified_state* _con_x373 = kk_src_unified__runtime__v3__as_Unified_state(s, _ctx);
        kk_std_core_types__list _x_0 = _con_x373->events;
        kk_std_core_types__list_dup(_x_0, _ctx);
        _x_x372 = _x_0; /*list<gan_ying/resonance-event>*/
      }
      _x_x370 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x372, kk_integer_from_small(0), _ctx); /*int*/
    }
  }
  _x_x369 = kk_std_core_int_show(_x_x370, _ctx); /*string*/
  kk_string_t _x_x374;
  kk_string_t _x_x375;
  kk_define_string_literal(, _s_x376, 12, ",\"profiles\":", _ctx)
  _x_x375 = kk_string_dup(_s_x376, _ctx); /*string*/
  kk_string_t _x_x377;
  kk_string_t _x_x378;
  kk_integer_t _x_x379;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x380 = kk_src_unified__runtime__v3__as_Unified_state(s, _ctx);
    kk_std_core_types__list _x_0_0 = _con_x380->profiles;
    kk_std_core_types__list_dup(_x_0_0, _ctx);
    if (kk_std_core_types__is_Nil(_x_0_0, _ctx)) {
      _x_x379 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_std_core_types__list_drop(_x_0_0, _ctx);
      kk_std_core_types__list _x_x381;
      {
        struct kk_src_unified__runtime__v3_Unified_state* _con_x382 = kk_src_unified__runtime__v3__as_Unified_state(s, _ctx);
        kk_std_core_types__list _x_0_1 = _con_x382->profiles;
        kk_std_core_types__list_dup(_x_0_1, _ctx);
        _x_x381 = _x_0_1; /*list<hot_paths/path-profile>*/
      }
      _x_x379 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x381, kk_integer_from_small(0), _ctx); /*int*/
    }
  }
  _x_x378 = kk_std_core_int_show(_x_x379, _ctx); /*string*/
  kk_string_t _x_x383;
  kk_string_t _x_x384;
  kk_define_string_literal(, _s_x385, 13, ",\"total_ops\":", _ctx)
  _x_x384 = kk_string_dup(_s_x385, _ctx); /*string*/
  kk_string_t _x_x386;
  kk_string_t _x_x387;
  kk_integer_t _x_x388;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x389 = kk_src_unified__runtime__v3__as_Unified_state(s, _ctx);
    kk_integer_t _x_1 = _con_x389->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x388 = _x_1; /*int*/
  }
  _x_x387 = kk_std_core_int_show(_x_x388, _ctx); /*string*/
  kk_string_t _x_x390;
  kk_string_t _x_x391;
  kk_define_string_literal(, _s_x392, 11, ",\"batches\":", _ctx)
  _x_x391 = kk_string_dup(_s_x392, _ctx); /*string*/
  kk_string_t _x_x393;
  kk_string_t _x_x394;
  kk_integer_t _x_x395;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x396 = kk_src_unified__runtime__v3__as_Unified_state(s, _ctx);
    kk_integer_t _x_2 = _con_x396->batch_count;
    kk_integer_dup(_x_2, _ctx);
    _x_x395 = _x_2; /*int*/
  }
  _x_x394 = kk_std_core_int_show(_x_x395, _ctx); /*string*/
  kk_string_t _x_x397;
  kk_string_t _x_x398;
  kk_define_string_literal(, _s_x399, 17, ",\"session_start\":", _ctx)
  _x_x398 = kk_string_dup(_s_x399, _ctx); /*string*/
  kk_string_t _x_x400;
  kk_string_t _x_x401;
  double _x_x402;
  {
    struct kk_src_unified__runtime__v3_Unified_state* _con_x403 = kk_src_unified__runtime__v3__as_Unified_state(s, _ctx);
    kk_std_core_types__list _pat_0_4 = _con_x403->events;
    kk_std_core_types__list _pat_1_5 = _con_x403->profiles;
    kk_integer_t _pat_2_3 = _con_x403->total_ops;
    kk_integer_t _pat_3_3 = _con_x403->batch_count;
    double _x_3 = _con_x403->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(s, _ctx)) {
      kk_integer_drop(_pat_3_3, _ctx);
      kk_integer_drop(_pat_2_3, _ctx);
      kk_std_core_types__list_drop(_pat_1_5, _ctx);
      kk_std_core_types__list_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(s, _ctx);
    }
    else {
      kk_datatype_ptr_decref(s, _ctx);
    }
    _x_x402 = _x_3; /*float64*/
  }
  _x_x401 = kk_std_num_float64_show(_x_x402, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x404;
  kk_define_string_literal(, _s_x405, 1, "}", _ctx)
  _x_x404 = kk_string_dup(_s_x405, _ctx); /*string*/
  _x_x400 = kk_std_core_types__lp__plus__plus__rp_(_x_x401, _x_x404, _ctx); /*string*/
  _x_x397 = kk_std_core_types__lp__plus__plus__rp_(_x_x398, _x_x400, _ctx); /*string*/
  _x_x393 = kk_std_core_types__lp__plus__plus__rp_(_x_x394, _x_x397, _ctx); /*string*/
  _x_x390 = kk_std_core_types__lp__plus__plus__rp_(_x_x391, _x_x393, _ctx); /*string*/
  _x_x386 = kk_std_core_types__lp__plus__plus__rp_(_x_x387, _x_x390, _ctx); /*string*/
  _x_x383 = kk_std_core_types__lp__plus__plus__rp_(_x_x384, _x_x386, _ctx); /*string*/
  _x_x377 = kk_std_core_types__lp__plus__plus__rp_(_x_x378, _x_x383, _ctx); /*string*/
  _x_x374 = kk_std_core_types__lp__plus__plus__rp_(_x_x375, _x_x377, _ctx); /*string*/
  _x_x368 = kk_std_core_types__lp__plus__plus__rp_(_x_x369, _x_x374, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x366, _x_x368, _ctx);
}
 
// Execute single command

kk_string_t kk_src_unified__runtime__v3_execute_cmd(kk_string_t op, kk_src_unified__runtime__v3__unified_state state, kk_context_t* _ctx) { /* (op : string, state : unified-state) -> string */ 
  if (kk_string_cmp_cstr_borrow(op, "ping", _ctx) == 0) {
    kk_datatype_ptr_dropn(state, (KK_I32(4)), _ctx);
    kk_string_drop(op, _ctx);
    kk_define_string_literal(, _s_x406, 13, "{\"pong\":true}", _ctx)
    return kk_string_dup(_s_x406, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(op, "status", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    return kk_src_unified__runtime__v3_json_state(state, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(op, "emit", _ctx) == 0) {
    kk_datatype_ptr_dropn(state, (KK_I32(4)), _ctx);
    kk_string_drop(op, _ctx);
    kk_define_string_literal(, _s_x407, 16, "{\"emitted\":true}", _ctx)
    return kk_string_dup(_s_x407, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(op, "count", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_string_t _x_x408;
    kk_define_string_literal(, _s_x409, 9, "{\"count\":", _ctx)
    _x_x408 = kk_string_dup(_s_x409, _ctx); /*string*/
    kk_string_t _x_x410;
    kk_string_t _x_x411;
    kk_integer_t _x_x412;
    {
      struct kk_src_unified__runtime__v3_Unified_state* _con_x413 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
      kk_std_core_types__list _x = _con_x413->events;
      kk_std_core_types__list _pat_0_0 = _con_x413->profiles;
      kk_integer_t _pat_1_1 = _con_x413->total_ops;
      kk_integer_t _pat_2_0 = _con_x413->batch_count;
      kk_std_core_types__list_dup(_x, _ctx);
      if (kk_std_core_types__is_Nil(_x, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
          kk_integer_drop(_pat_2_0, _ctx);
          kk_integer_drop(_pat_1_1, _ctx);
          kk_std_core_types__list_drop(_pat_0_0, _ctx);
          kk_datatype_ptr_free(state, _ctx);
        }
        else {
          kk_datatype_ptr_decref(state, _ctx);
        }
        _x_x412 = kk_integer_from_small(0); /*int*/
      }
      else {
        kk_std_core_types__list_drop(_x, _ctx);
        kk_std_core_types__list _x_x414;
        {
          struct kk_src_unified__runtime__v3_Unified_state* _con_x415 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
          kk_std_core_types__list _x_0 = _con_x415->events;
          kk_std_core_types__list _pat_0_0_0 = _con_x415->profiles;
          kk_integer_t _pat_1_1_0 = _con_x415->total_ops;
          kk_integer_t _pat_2_0_0 = _con_x415->batch_count;
          if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
            kk_integer_drop(_pat_2_0_0, _ctx);
            kk_integer_drop(_pat_1_1_0, _ctx);
            kk_std_core_types__list_drop(_pat_0_0_0, _ctx);
            kk_datatype_ptr_free(state, _ctx);
          }
          else {
            kk_std_core_types__list_dup(_x_0, _ctx);
            kk_datatype_ptr_decref(state, _ctx);
          }
          _x_x414 = _x_0; /*list<gan_ying/resonance-event>*/
        }
        _x_x412 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x414, kk_integer_from_small(0), _ctx); /*int*/
      }
    }
    _x_x411 = kk_std_core_int_show(_x_x412, _ctx); /*string*/
    kk_string_t _x_x416;
    kk_define_string_literal(, _s_x417, 1, "}", _ctx)
    _x_x416 = kk_string_dup(_s_x417, _ctx); /*string*/
    _x_x410 = kk_std_core_types__lp__plus__plus__rp_(_x_x411, _x_x416, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x408, _x_x410, _ctx);
  }
  {
    kk_datatype_ptr_dropn(state, (KK_I32(4)), _ctx);
    kk_string_drop(op, _ctx);
    kk_define_string_literal(, _s_x418, 19, "{\"error\":\"unknown\"}", _ctx)
    return kk_string_dup(_s_x418, _ctx);
  }
}

kk_string_t kk_src_unified__runtime__v3_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x273;
  kk_string_t _x_x419 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x420;
  kk_define_string_literal(, _s_x421, 6, "\"ping\"", _ctx)
  _x_x420 = kk_string_dup(_s_x421, _ctx); /*string*/
  _match_x273 = kk_string_contains(_x_x419,_x_x420,kk_context()); /*bool*/
  if (_match_x273) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x422, 4, "ping", _ctx)
    return kk_string_dup(_s_x422, _ctx);
  }
  {
    bool _match_x274;
    kk_string_t _x_x423 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x424;
    kk_define_string_literal(, _s_x425, 6, "\"emit\"", _ctx)
    _x_x424 = kk_string_dup(_s_x425, _ctx); /*string*/
    _match_x274 = kk_string_contains(_x_x423,_x_x424,kk_context()); /*bool*/
    if (_match_x274) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x426, 4, "emit", _ctx)
      return kk_string_dup(_s_x426, _ctx);
    }
    {
      bool _match_x275;
      kk_string_t _x_x427 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x428;
      kk_define_string_literal(, _s_x429, 9, "\"cascade\"", _ctx)
      _x_x428 = kk_string_dup(_s_x429, _ctx); /*string*/
      _match_x275 = kk_string_contains(_x_x427,_x_x428,kk_context()); /*bool*/
      if (_match_x275) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x430, 7, "cascade", _ctx)
        return kk_string_dup(_s_x430, _ctx);
      }
      {
        bool _match_x276;
        kk_string_t _x_x431 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x432;
        kk_define_string_literal(, _s_x433, 9, "\"profile\"", _ctx)
        _x_x432 = kk_string_dup(_s_x433, _ctx); /*string*/
        _match_x276 = kk_string_contains(_x_x431,_x_x432,kk_context()); /*bool*/
        if (_match_x276) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x434, 7, "profile", _ctx)
          return kk_string_dup(_s_x434, _ctx);
        }
        {
          bool _match_x277;
          kk_string_t _x_x435 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x436;
          kk_define_string_literal(, _s_x437, 8, "\"status\"", _ctx)
          _x_x436 = kk_string_dup(_s_x437, _ctx); /*string*/
          _match_x277 = kk_string_contains(_x_x435,_x_x436,kk_context()); /*bool*/
          if (_match_x277) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x438, 6, "status", _ctx)
            return kk_string_dup(_s_x438, _ctx);
          }
          {
            bool _match_x278;
            kk_string_t _x_x439 = kk_string_dup(line, _ctx); /*string*/
            kk_string_t _x_x440;
            kk_define_string_literal(, _s_x441, 5, "\"hot\"", _ctx)
            _x_x440 = kk_string_dup(_s_x441, _ctx); /*string*/
            _match_x278 = kk_string_contains(_x_x439,_x_x440,kk_context()); /*bool*/
            if (_match_x278) {
              kk_string_drop(line, _ctx);
              kk_define_string_literal(, _s_x442, 3, "hot", _ctx)
              return kk_string_dup(_s_x442, _ctx);
            }
            {
              bool _match_x279;
              kk_string_t _x_x443 = kk_string_dup(line, _ctx); /*string*/
              kk_string_t _x_x444;
              kk_define_string_literal(, _s_x445, 7, "\"count\"", _ctx)
              _x_x444 = kk_string_dup(_s_x445, _ctx); /*string*/
              _match_x279 = kk_string_contains(_x_x443,_x_x444,kk_context()); /*bool*/
              if (_match_x279) {
                kk_string_drop(line, _ctx);
                kk_define_string_literal(, _s_x446, 5, "count", _ctx)
                return kk_string_dup(_s_x446, _ctx);
              }
              {
                bool _match_x280;
                kk_string_t _x_x447;
                kk_define_string_literal(, _s_x448, 6, "\"quit\"", _ctx)
                _x_x447 = kk_string_dup(_s_x448, _ctx); /*string*/
                _match_x280 = kk_string_contains(line,_x_x447,kk_context()); /*bool*/
                if (_match_x280) {
                  kk_define_string_literal(, _s_x449, 4, "quit", _ctx)
                  return kk_string_dup(_s_x449, _ctx);
                }
                {
                  kk_define_string_literal(, _s_x450, 7, "unknown", _ctx)
                  return kk_string_dup(_s_x450, _ctx);
                }
              }
            }
          }
        }
      }
    }
  }
}

kk_gan__ying__event_type kk_src_unified__runtime__v3_extract_event_type(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> gan_ying/event-type */ 
  bool _match_x269;
  kk_string_t _x_x451 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x452;
  kk_define_string_literal(, _s_x453, 14, "memory_created", _ctx)
  _x_x452 = kk_string_dup(_s_x453, _ctx); /*string*/
  _match_x269 = kk_string_contains(_x_x451,_x_x452,kk_context()); /*bool*/
  if (_match_x269) {
    kk_string_drop(line, _ctx);
    return kk_gan__ying__new_MemoryCreated(_ctx);
  }
  {
    bool _match_x270;
    kk_string_t _x_x454 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x455;
    kk_define_string_literal(, _s_x456, 14, "memory_updated", _ctx)
    _x_x455 = kk_string_dup(_s_x456, _ctx); /*string*/
    _match_x270 = kk_string_contains(_x_x454,_x_x455,kk_context()); /*bool*/
    if (_match_x270) {
      kk_string_drop(line, _ctx);
      return kk_gan__ying__new_MemoryUpdated(_ctx);
    }
    {
      bool _match_x271;
      kk_string_t _x_x457 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x458;
      kk_define_string_literal(, _s_x459, 15, "threat_detected", _ctx)
      _x_x458 = kk_string_dup(_s_x459, _ctx); /*string*/
      _match_x271 = kk_string_contains(_x_x457,_x_x458,kk_context()); /*bool*/
      if (_match_x271) {
        kk_string_drop(line, _ctx);
        return kk_gan__ying__new_ThreatDetected(_ctx);
      }
      {
        bool _match_x272;
        kk_string_t _x_x460;
        kk_define_string_literal(, _s_x461, 10, "flow_state", _ctx)
        _x_x460 = kk_string_dup(_s_x461, _ctx); /*string*/
        _match_x272 = kk_string_contains(line,_x_x460,kk_context()); /*bool*/
        if (_match_x272) {
          return kk_gan__ying__new_FlowStateEntered(_ctx);
        }
        {
          return kk_gan__ying__new_SystemStarted(_ctx);
        }
      }
    }
  }
}
 
// lifted local: response, server-loop, @spec-x10147
// specialized: std/core/list/filter, on parameters @uniq-pred@10144, using:
// @uniq-pred@10144 = std/core/types/@open<(total :: E),<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(p : hot_paths/path-profile) -> bool,(p : hot_paths/path-profile) -> <(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> bool>((fn(p: hot_paths/path-profile){
//   (match (p) {
//     ((@skip hot_paths/Path-profile((@pat@0@8: string) : string, (@pat@1@10: int) : int, (@pat@2@8: float64) : float64, (@pat@3@8: float64) : float64, (@x@7: hot_paths/complexity) : hot_paths/complexity, (@pat@4@0: hot_paths/path-category) : hot_paths/path-category) : hot_paths/path-profile ) as @pat@20: hot_paths/path-profile)
//        -> (match (@x@7) {
//         ((hot_paths/High() : hot_paths/complexity ) as @pat@17@0: hot_paths/complexity)
//            -> std/core/types/True;
//         (@pat@18@0: hot_paths/complexity)
//            -> std/core/types/False;
//       });
//   });
// }))


// lift anonymous function
struct kk_src_unified__runtime__v3__lift_server_loop_10148_fun462__t {
  struct kk_function_s _base;
};
static bool kk_src_unified__runtime__v3__lift_server_loop_10148_fun462(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_lift_server_loop_10148_fun462(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__lift_server_loop_10148_fun462, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static bool kk_src_unified__runtime__v3__lift_server_loop_10148_fun462(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_hot__paths__path_profile _match_x268 = kk_hot__paths__path_profile_unbox(_b_x23, KK_OWNED, _ctx); /*hot_paths/path-profile*/;
  {
    struct kk_hot__paths_Path_profile* _con_x463 = kk_hot__paths__as_Path_profile(_match_x268, _ctx);
    kk_string_t _pat_0_8 = _con_x463->name;
    kk_integer_t _pat_1_10 = _con_x463->call_count;
    kk_hot__paths__complexity _x_7 = _con_x463->complexity;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x268, _ctx)) {
      kk_integer_drop(_pat_1_10, _ctx);
      kk_string_drop(_pat_0_8, _ctx);
      kk_datatype_ptr_free(_match_x268, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x268, _ctx);
    }
    if (kk_hot__paths__is_High(_x_7, _ctx)) {
      return true;
    }
    {
      return false;
    }
  }
}

kk_std_core_types__list kk_src_unified__runtime__v3__lift_server_loop_10148(kk_std_core_types__list _uniq_xs_10143, kk_context_t* _ctx) { /* (list<hot_paths/path-profile>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<hot_paths/path-profile> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10143, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_filter_10007(_uniq_xs_10143, kk_src_unified__runtime__v3__new_lift_server_loop_10148_fun462(_ctx), _ctx);
  }
}
 
// monadic lift

kk_string_t kk_src_unified__runtime__v3__mlift_server_loop_10227(kk_std_core_types__list _y_x10153, kk_context_t* _ctx) { /* (list<hot_paths/path-profile>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_integer_t x;
  if (kk_std_core_types__is_Nil(_y_x10153, _ctx)) {
    x = kk_integer_from_small(0); /*int*/
  }
  else {
    x = kk_std_core_list__unroll_lift_length_5730_10000(_y_x10153, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_string_t _x_x464;
  kk_define_string_literal(, _s_x465, 13, "{\"hot_paths\":", _ctx)
  _x_x464 = kk_string_dup(_s_x465, _ctx); /*string*/
  kk_string_t _x_x466;
  kk_string_t _x_x467 = kk_std_core_int_show(x, _ctx); /*string*/
  kk_string_t _x_x468;
  kk_define_string_literal(, _s_x469, 21, ",\"threshold_ms\":10.0}", _ctx)
  _x_x468 = kk_string_dup(_s_x469, _ctx); /*string*/
  _x_x466 = kk_std_core_types__lp__plus__plus__rp_(_x_x467, _x_x468, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x464, _x_x466, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10228_fun485__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10228_fun485(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10228_fun485(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10228_fun485, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10228_fun485(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x486;
  kk_string_t _x_x487 = kk_string_unbox(_b_x29); /*string*/
  _x_x486 = kk_src_unified__runtime__v3_extract_op(_x_x487, _ctx); /*string*/
  return kk_string_box(_x_x486);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10228_fun492__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10228_fun492(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10228_fun492(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10228_fun492, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10228_fun492(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x493;
  kk_string_t _x_x494 = kk_string_unbox(_b_x34); /*string*/
  _x_x493 = kk_src_unified__runtime__v3_extract_event_type(_x_x494, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x493, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10228_fun516__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10228_fun516(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10228_fun516(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10228_fun516, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10228_fun516(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x517;
  kk_string_t _x_x518 = kk_string_unbox(_b_x47); /*string*/
  _x_x517 = kk_src_unified__runtime__v3_extract_event_type(_x_x518, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x517, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10228_fun520__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10228_fun520(kk_function_t _fself, kk_box_t _b_x53, kk_box_t _b_x54, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10228_fun520(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10228_fun520, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10228_fun520(kk_function_t _fself, kk_box_t _b_x53, kk_box_t _b_x54, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x521;
  kk_gan__ying__event_type _x_x522 = kk_gan__ying__event_type_unbox(_b_x53, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v3__unified_state _x_x523 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x54, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  _x_x521 = kk_src_unified__runtime__v3_cascade_profiled(_x_x522, _x_x523, _ctx); /*(int, src/unified_runtime_v3/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x521, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10228_fun526__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10228_fun526(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10228_fun526(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10228_fun526, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10228_fun526(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x527 = kk_Unit;
  kk_src_unified__runtime__v3__unified_state _x_x528 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x61, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  kk_src_unified__runtime__v3_server_loop(_x_x528, _ctx);
  return kk_unit_box(_x_x527);
}

kk_unit_t kk_src_unified__runtime__v3__mlift_server_loop_10228(kk_string_t line, kk_src_unified__runtime__v3__unified_state state, kk_string_t _c_x10155, kk_context_t* _ctx) { /* (line : string, state : unified-state, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10155, _ctx);
  kk_src_unified__runtime__v3__unified_state x_0_10234;
  bool _match_x266;
  kk_string_t _x_x470 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x471;
  kk_define_string_literal(, _s_x472, 11, "\"commands\":", _ctx)
  _x_x471 = kk_string_dup(_s_x472, _ctx); /*string*/
  _match_x266 = kk_string_contains(_x_x470,_x_x471,kk_context()); /*bool*/
  if (_match_x266) {
    kk_string_drop(line, _ctx);
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_1 = kk_Unit;
    kk_evv_set(w_1,kk_context());
    kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_2 = kk_Unit;
    kk_evv_set(w_2,kk_context());
    kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_3 = kk_Unit;
    kk_evv_set(w_3,kk_context());
    kk_evv_t w_4 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_4 = kk_Unit;
    kk_evv_set(w_4,kk_context());
    kk_std_core_types__list _x_x473;
    {
      struct kk_src_unified__runtime__v3_Unified_state* _con_x474 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
      kk_std_core_types__list _x_8 = _con_x474->events;
      kk_std_core_types__list_dup(_x_8, _ctx);
      _x_x473 = _x_8; /*list<gan_ying/resonance-event>*/
    }
    kk_std_core_types__list _x_x475;
    {
      struct kk_src_unified__runtime__v3_Unified_state* _con_x476 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
      kk_std_core_types__list _x_9 = _con_x476->profiles;
      kk_std_core_types__list_dup(_x_9, _ctx);
      _x_x475 = _x_9; /*list<hot_paths/path-profile>*/
    }
    kk_integer_t _x_x477;
    {
      struct kk_src_unified__runtime__v3_Unified_state* _con_x478 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
      kk_integer_t _x_10 = _con_x478->total_ops;
      kk_integer_dup(_x_10, _ctx);
      _x_x477 = _x_10; /*int*/
    }
    kk_integer_t _x_x479;
    kk_integer_t _x_x480;
    {
      struct kk_src_unified__runtime__v3_Unified_state* _con_x481 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
      kk_integer_t _x_11 = _con_x481->batch_count;
      kk_integer_dup(_x_11, _ctx);
      _x_x480 = _x_11; /*int*/
    }
    _x_x479 = kk_integer_add_small_const(_x_x480, 1, _ctx); /*int*/
    double _x_x482;
    {
      struct kk_src_unified__runtime__v3_Unified_state* _con_x483 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
      kk_std_core_types__list _pat_0_13 = _con_x483->events;
      kk_std_core_types__list _pat_1_15 = _con_x483->profiles;
      kk_integer_t _pat_2_13 = _con_x483->total_ops;
      kk_integer_t _pat_3_13 = _con_x483->batch_count;
      double _x_12 = _con_x483->session_start;
      if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
        kk_integer_drop(_pat_3_13, _ctx);
        kk_integer_drop(_pat_2_13, _ctx);
        kk_std_core_types__list_drop(_pat_1_15, _ctx);
        kk_std_core_types__list_drop(_pat_0_13, _ctx);
        kk_datatype_ptr_free(state, _ctx);
      }
      else {
        kk_datatype_ptr_decref(state, _ctx);
      }
      _x_x482 = _x_12; /*float64*/
    }
    x_0_10234 = kk_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x473, _x_x475, _x_x477, _x_x479, _x_x482, _ctx); /*src/unified_runtime_v3/unified-state*/
  }
  else {
    kk_string_t op_0;
    kk_box_t _x_x484;
    kk_box_t _x_x488;
    kk_string_t _x_x489 = kk_string_dup(line, _ctx); /*string*/
    _x_x488 = kk_string_box(_x_x489); /*10000*/
    _x_x484 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3__new_mlift_server_loop_10228_fun485(_ctx), _x_x488, _ctx); /*10001*/
    op_0 = kk_string_unbox(_x_x484); /*string*/
    if (kk_string_cmp_cstr_borrow(op_0, "emit", _ctx) == 0) {
      kk_string_drop(op_0, _ctx);
      kk_gan__ying__event_type et_1;
      kk_box_t _x_x491 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3__new_mlift_server_loop_10228_fun492(_ctx), kk_string_box(line), _ctx); /*10001*/
      et_1 = kk_gan__ying__event_type_unbox(_x_x491, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_evv_t w_5 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_hot__paths__path_profile profile_0;
      kk_string_t _x_x495 = kk_gan__ying_event_type_to_string(et_1, _ctx); /*string*/
      profile_0 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x495, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
      kk_src_unified__runtime__v3__unified_state x_6;
      kk_std_core_types__list _x_x496;
      kk_box_t _x_x497;
      kk_gan__ying__resonance_event _x_x498;
      kk_string_t _x_x499;
      kk_define_string_literal(, _s_x500, 18, "unified_runtime_v3", _ctx)
      _x_x499 = kk_string_dup(_s_x500, _ctx); /*string*/
      kk_string_t _x_x501 = kk_string_empty(); /*string*/
      _x_x498 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x499, et_1, _x_x501, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
      _x_x497 = kk_gan__ying__resonance_event_box(_x_x498, _ctx); /*10021*/
      kk_std_core_types__list _x_x503;
      {
        struct kk_src_unified__runtime__v3_Unified_state* _con_x504 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
        kk_std_core_types__list _x_13 = _con_x504->events;
        kk_std_core_types__list_dup(_x_13, _ctx);
        _x_x503 = _x_13; /*list<gan_ying/resonance-event>*/
      }
      _x_x496 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x497, _x_x503, _ctx); /*list<10021>*/
      kk_std_core_types__list _x_x505;
      kk_std_core_types__list _x_x506;
      {
        struct kk_src_unified__runtime__v3_Unified_state* _con_x507 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
        kk_std_core_types__list _x_14 = _con_x507->profiles;
        kk_std_core_types__list_dup(_x_14, _ctx);
        _x_x506 = _x_14; /*list<hot_paths/path-profile>*/
      }
      _x_x505 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_0, _ctx), _x_x506, _ctx); /*list<10021>*/
      kk_integer_t _x_x508;
      kk_integer_t _x_x509;
      {
        struct kk_src_unified__runtime__v3_Unified_state* _con_x510 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
        kk_integer_t _x_15 = _con_x510->total_ops;
        kk_integer_dup(_x_15, _ctx);
        _x_x509 = _x_15; /*int*/
      }
      _x_x508 = kk_integer_add_small_const(_x_x509, 1, _ctx); /*int*/
      kk_integer_t _x_x511;
      {
        struct kk_src_unified__runtime__v3_Unified_state* _con_x512 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
        kk_integer_t _x_16 = _con_x512->batch_count;
        kk_integer_dup(_x_16, _ctx);
        _x_x511 = _x_16; /*int*/
      }
      double _x_x513;
      {
        struct kk_src_unified__runtime__v3_Unified_state* _con_x514 = kk_src_unified__runtime__v3__as_Unified_state(state, _ctx);
        kk_std_core_types__list _pat_0_18 = _con_x514->events;
        kk_std_core_types__list _pat_1_20 = _con_x514->profiles;
        kk_integer_t _pat_2_18 = _con_x514->total_ops;
        kk_integer_t _pat_3_18 = _con_x514->batch_count;
        double _x_17 = _con_x514->session_start;
        if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
          kk_integer_drop(_pat_3_18, _ctx);
          kk_integer_drop(_pat_2_18, _ctx);
          kk_std_core_types__list_drop(_pat_1_20, _ctx);
          kk_std_core_types__list_drop(_pat_0_18, _ctx);
          kk_datatype_ptr_free(state, _ctx);
        }
        else {
          kk_datatype_ptr_decref(state, _ctx);
        }
        _x_x513 = _x_17; /*float64*/
      }
      x_6 = kk_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x496, _x_x505, _x_x508, _x_x511, _x_x513, _ctx); /*src/unified_runtime_v3/unified-state*/
      kk_unit_t keep_5 = kk_Unit;
      kk_evv_set(w_5,kk_context());
      x_0_10234 = x_6; /*src/unified_runtime_v3/unified-state*/
      goto _match_x490;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "cascade", _ctx) == 0) {
      kk_string_drop(op_0, _ctx);
      kk_gan__ying__event_type et_2_0;
      kk_box_t _x_x515 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3__new_mlift_server_loop_10228_fun516(_ctx), kk_string_box(line), _ctx); /*10001*/
      et_2_0 = kk_gan__ying__event_type_unbox(_x_x515, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_std_core_types__tuple2 _match_x267;
      kk_box_t _x_x519 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v3__new_mlift_server_loop_10228_fun520(_ctx), kk_gan__ying__event_type_box(et_2_0, _ctx), kk_src_unified__runtime__v3__unified_state_box(state, _ctx), _ctx); /*10002*/
      _match_x267 = kk_std_core_types__tuple2_unbox(_x_x519, KK_OWNED, _ctx); /*(int, src/unified_runtime_v3/unified-state)*/
      {
        kk_box_t _box_x55 = _match_x267.fst;
        kk_box_t _box_x56 = _match_x267.snd;
        kk_src_unified__runtime__v3__unified_state ns = kk_src_unified__runtime__v3__unified_state_unbox(_box_x56, KK_BORROWED, _ctx);
        struct kk_src_unified__runtime__v3_Unified_state* _con_x524 = kk_src_unified__runtime__v3__as_Unified_state(ns, _ctx);
        kk_src_unified__runtime__v3__unified_state_dup(ns, _ctx);
        kk_std_core_types__tuple2_drop(_match_x267, _ctx);
        x_0_10234 = ns; /*src/unified_runtime_v3/unified-state*/
        goto _match_x490;
      }
    }
    {
      kk_string_drop(op_0, _ctx);
      kk_string_drop(line, _ctx);
      x_0_10234 = state; /*src/unified_runtime_v3/unified-state*/
    }
    _match_x490: ;
  }
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_0_10234, (KK_I32(4)), _ctx);
    kk_box_t _x_x525 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v3__new_mlift_server_loop_10228_fun526(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x525); return kk_Unit;
  }
  {
    kk_src_unified__runtime__v3_server_loop(x_0_10234, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun544__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun544(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun544(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10229_fun544, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun544(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x545;
  kk_integer_t _x_x546 = kk_integer_unbox(_b_x65, _ctx); /*int*/
  _x_x545 = kk_src_unified__runtime__v3_batch_response(_x_x546, _ctx); /*string*/
  return kk_string_box(_x_x545);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun548__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun548(kk_function_t _fself, kk_box_t _b_x68, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun548(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10229_fun548, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun548(kk_function_t _fself, kk_box_t _b_x68, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x549;
  kk_string_t _x_x550 = kk_string_unbox(_b_x68); /*string*/
  _x_x549 = kk_src_unified__runtime__v3_extract_op(_x_x550, _ctx); /*string*/
  return kk_string_box(_x_x549);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun555__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun555(kk_function_t _fself, kk_box_t _b_x73, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun555(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10229_fun555, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun555(kk_function_t _fself, kk_box_t _b_x73, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x556;
  kk_string_t _x_x557 = kk_string_unbox(_b_x73); /*string*/
  _x_x556 = kk_src_unified__runtime__v3_extract_event_type(_x_x557, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x556, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun585__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun585(kk_function_t _fself, kk_box_t _b_x86, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun585(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10229_fun585, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun585(kk_function_t _fself, kk_box_t _b_x86, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x586;
  kk_gan__ying__event_type _x_x587 = kk_gan__ying__event_type_unbox(_b_x86, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x586 = kk_gan__ying_event_type_to_string(_x_x587, _ctx); /*string*/
  return kk_string_box(_x_x586);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun594__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun594(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun594(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10229_fun594, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun594(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x595;
  kk_src_unified__runtime__v3__unified_state _x_x596 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x89, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  _x_x595 = kk_src_unified__runtime__v3_json_state(_x_x596, _ctx); /*string*/
  return kk_string_box(_x_x595);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun600__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun600(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun600(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10229_fun600, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun600(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x601;
  kk_string_t _x_x602 = kk_string_unbox(_b_x92); /*string*/
  _x_x601 = kk_src_unified__runtime__v3_extract_event_type(_x_x602, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x601, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun606__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun606(kk_function_t _fself, kk_box_t _b_x98, kk_box_t _b_x99, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun606(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10229_fun606, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun606(kk_function_t _fself, kk_box_t _b_x98, kk_box_t _b_x99, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x607;
  kk_gan__ying__event_type _x_x608 = kk_gan__ying__event_type_unbox(_b_x98, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v3__unified_state _x_x609 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x99, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  _x_x607 = kk_src_unified__runtime__v3_cascade_profiled(_x_x608, _x_x609, _ctx); /*(int, src/unified_runtime_v3/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x607, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun618__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun618(kk_function_t _fself, kk_box_t _b_x104, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun618(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10229_fun618, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun618(kk_function_t _fself, kk_box_t _b_x104, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x619;
  kk_gan__ying__event_type _x_x620 = kk_gan__ying__event_type_unbox(_b_x104, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x619 = kk_gan__ying_event_type_to_string(_x_x620, _ctx); /*string*/
  return kk_string_box(_x_x619);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun645__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun645(kk_function_t _fself, kk_box_t _b_x107, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun645(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10229_fun645, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun645(kk_function_t _fself, kk_box_t _b_x107, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x646;
  kk_src_unified__runtime__v3__unified_state _x_x647 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x107, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  _x_x646 = kk_src_unified__runtime__v3_json_state(_x_x647, _ctx); /*string*/
  return kk_string_box(_x_x646);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun653__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun653(kk_function_t _fself, kk_box_t _b_x109, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun653(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10229_fun653, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun653(kk_function_t _fself, kk_box_t _b_x109, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x654;
  kk_std_core_types__list _x_x655 = kk_std_core_types__list_unbox(_b_x109, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
  _x_x654 = kk_src_unified__runtime__v3__mlift_server_loop_10227(_x_x655, _ctx); /*string*/
  return kk_string_box(_x_x654);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun657__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun657(kk_function_t _fself, kk_box_t _b_x113, kk_box_t _b_x114, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun657(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3__mlift_server_loop_10229_fun657, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun657(kk_function_t _fself, kk_box_t _b_x113, kk_box_t _b_x114, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x658;
  kk_string_t _x_x659 = kk_string_unbox(_b_x113); /*string*/
  kk_src_unified__runtime__v3__unified_state _x_x660 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x114, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  _x_x658 = kk_src_unified__runtime__v3_execute_cmd(_x_x659, _x_x660, _ctx); /*string*/
  return kk_string_box(_x_x658);
}


// lift anonymous function
struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun664__t {
  struct kk_function_s _base;
  kk_string_t line_0;
  kk_src_unified__runtime__v3__unified_state state_0;
};
static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun664(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun664(kk_string_t line_0, kk_src_unified__runtime__v3__unified_state state_0, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun664__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun664__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v3__mlift_server_loop_10229_fun664, kk_context());
  _self->line_0 = line_0;
  _self->state_0 = state_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v3__mlift_server_loop_10229_fun664(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun664__t* _self = kk_function_as(struct kk_src_unified__runtime__v3__mlift_server_loop_10229_fun664__t*, _fself, _ctx);
  kk_string_t line_0 = _self->line_0; /* string */
  kk_src_unified__runtime__v3__unified_state state_0 = _self->state_0; /* src/unified_runtime_v3/unified-state */
  kk_drop_match(_self, {kk_string_dup(line_0, _ctx);kk_src_unified__runtime__v3__unified_state_dup(state_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10155_0_135 = kk_string_unbox(_b_x133); /*string*/;
  kk_unit_t _x_x665 = kk_Unit;
  kk_src_unified__runtime__v3__mlift_server_loop_10228(line_0, state_0, _c_x10155_0_135, _ctx);
  return kk_unit_box(_x_x665);
}

kk_unit_t kk_src_unified__runtime__v3__mlift_server_loop_10229(kk_src_unified__runtime__v3__unified_state state_0, kk_string_t line_0, kk_context_t* _ctx) { /* (state : unified-state, line : string) -> <console/console,exn> () */ 
  bool _match_x259;
  kk_string_t _x_x529 = kk_string_dup(line_0, _ctx); /*string*/
  kk_string_t _x_x530 = kk_string_empty(); /*string*/
  _match_x259 = kk_string_is_eq(_x_x529,_x_x530,kk_context()); /*bool*/
  if (_match_x259) {
    kk_datatype_ptr_dropn(state_0, (KK_I32(4)), _ctx);
    kk_string_drop(line_0, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    bool _match_x260;
    kk_string_t _x_x532 = kk_string_dup(line_0, _ctx); /*string*/
    kk_string_t _x_x533;
    kk_define_string_literal(, _s_x534, 6, "\"quit\"", _ctx)
    _x_x533 = kk_string_dup(_s_x534, _ctx); /*string*/
    _match_x260 = kk_string_contains(_x_x532,_x_x533,kk_context()); /*bool*/
    if (_match_x260) {
      kk_datatype_ptr_dropn(state_0, (KK_I32(4)), _ctx);
      kk_string_drop(line_0, _ctx);
      kk_string_t _x_x535;
      kk_define_string_literal(, _s_x536, 20, "{\"status\":\"stopped\"}", _ctx)
      _x_x535 = kk_string_dup(_s_x536, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x535, _ctx); return kk_Unit;
    }
    {
      kk_string_t x_7_10250;
      bool _match_x262;
      kk_string_t _x_x537 = kk_string_dup(line_0, _ctx); /*string*/
      kk_string_t _x_x538;
      kk_define_string_literal(, _s_x539, 11, "\"commands\":", _ctx)
      _x_x538 = kk_string_dup(_s_x539, _ctx); /*string*/
      _match_x262 = kk_string_contains(_x_x537,_x_x538,kk_context()); /*bool*/
      if (_match_x262) {
        kk_integer_t n;
        kk_string_t _x_x540 = kk_string_dup(line_0, _ctx); /*string*/
        kk_string_t _x_x541;
        kk_define_string_literal(, _s_x542, 6, "{\"id\":", _ctx)
        _x_x541 = kk_string_dup(_s_x542, _ctx); /*string*/
        n = kk_string_count_pattern(_x_x540,_x_x541,kk_context()); /*int*/
        kk_box_t _x_x543 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun544(_ctx), kk_integer_box(n, _ctx), _ctx); /*10001*/
        x_7_10250 = kk_string_unbox(_x_x543); /*string*/
      }
      else {
        kk_string_t op;
        kk_box_t _x_x547;
        kk_box_t _x_x551;
        kk_string_t _x_x552 = kk_string_dup(line_0, _ctx); /*string*/
        _x_x551 = kk_string_box(_x_x552); /*10000*/
        _x_x547 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun548(_ctx), _x_x551, _ctx); /*10001*/
        op = kk_string_unbox(_x_x547); /*string*/
        if (kk_string_cmp_cstr_borrow(op, "emit", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_gan__ying__event_type et;
          kk_box_t _x_x554;
          kk_box_t _x_x558;
          kk_string_t _x_x559 = kk_string_dup(line_0, _ctx); /*string*/
          _x_x558 = kk_string_box(_x_x559); /*10000*/
          _x_x554 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun555(_ctx), _x_x558, _ctx); /*10001*/
          et = kk_gan__ying__event_type_unbox(_x_x554, KK_OWNED, _ctx); /*gan_ying/event-type*/
          kk_evv_t w_6 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_hot__paths__path_profile profile;
          kk_string_t _x_x560 = kk_gan__ying_event_type_to_string(et, _ctx); /*string*/
          profile = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x560, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
          kk_src_unified__runtime__v3__unified_state x_8;
          kk_std_core_types__list _x_x561;
          kk_box_t _x_x562;
          kk_gan__ying__resonance_event _x_x563;
          kk_string_t _x_x564;
          kk_define_string_literal(, _s_x565, 18, "unified_runtime_v3", _ctx)
          _x_x564 = kk_string_dup(_s_x565, _ctx); /*string*/
          kk_string_t _x_x566 = kk_string_empty(); /*string*/
          _x_x563 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x564, et, _x_x566, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
          _x_x562 = kk_gan__ying__resonance_event_box(_x_x563, _ctx); /*10021*/
          kk_std_core_types__list _x_x568;
          {
            struct kk_src_unified__runtime__v3_Unified_state* _con_x569 = kk_src_unified__runtime__v3__as_Unified_state(state_0, _ctx);
            kk_std_core_types__list _x = _con_x569->events;
            kk_std_core_types__list_dup(_x, _ctx);
            _x_x568 = _x; /*list<gan_ying/resonance-event>*/
          }
          _x_x561 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x562, _x_x568, _ctx); /*list<10021>*/
          kk_std_core_types__list _x_x570;
          kk_std_core_types__list _x_x571;
          {
            struct kk_src_unified__runtime__v3_Unified_state* _con_x572 = kk_src_unified__runtime__v3__as_Unified_state(state_0, _ctx);
            kk_std_core_types__list _x_0 = _con_x572->profiles;
            kk_std_core_types__list_dup(_x_0, _ctx);
            _x_x571 = _x_0; /*list<hot_paths/path-profile>*/
          }
          _x_x570 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile, _ctx), _x_x571, _ctx); /*list<10021>*/
          kk_integer_t _x_x573;
          kk_integer_t _x_x574;
          {
            struct kk_src_unified__runtime__v3_Unified_state* _con_x575 = kk_src_unified__runtime__v3__as_Unified_state(state_0, _ctx);
            kk_integer_t _x_1 = _con_x575->total_ops;
            kk_integer_dup(_x_1, _ctx);
            _x_x574 = _x_1; /*int*/
          }
          _x_x573 = kk_integer_add_small_const(_x_x574, 1, _ctx); /*int*/
          kk_integer_t _x_x576;
          {
            struct kk_src_unified__runtime__v3_Unified_state* _con_x577 = kk_src_unified__runtime__v3__as_Unified_state(state_0, _ctx);
            kk_integer_t _x_2 = _con_x577->batch_count;
            kk_integer_dup(_x_2, _ctx);
            _x_x576 = _x_2; /*int*/
          }
          double _x_x578;
          {
            struct kk_src_unified__runtime__v3_Unified_state* _con_x579 = kk_src_unified__runtime__v3__as_Unified_state(state_0, _ctx);
            double _x_3 = _con_x579->session_start;
            _x_x578 = _x_3; /*float64*/
          }
          x_8 = kk_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x561, _x_x570, _x_x573, _x_x576, _x_x578, _ctx); /*src/unified_runtime_v3/unified-state*/
          kk_unit_t keep_6 = kk_Unit;
          kk_evv_set(w_6,kk_context());
          kk_string_t _x_x580;
          kk_define_string_literal(, _s_x581, 12, "{\"emitted\":\"", _ctx)
          _x_x580 = kk_string_dup(_s_x581, _ctx); /*string*/
          kk_string_t _x_x582;
          kk_string_t _x_x583;
          kk_box_t _x_x584 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun585(_ctx), kk_gan__ying__event_type_box(et, _ctx), _ctx); /*10001*/
          _x_x583 = kk_string_unbox(_x_x584); /*string*/
          kk_string_t _x_x588;
          kk_string_t _x_x589;
          kk_define_string_literal(, _s_x590, 10, "\",\"state\":", _ctx)
          _x_x589 = kk_string_dup(_s_x590, _ctx); /*string*/
          kk_string_t _x_x591;
          kk_string_t _x_x592;
          kk_box_t _x_x593 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun594(_ctx), kk_src_unified__runtime__v3__unified_state_box(x_8, _ctx), _ctx); /*10001*/
          _x_x592 = kk_string_unbox(_x_x593); /*string*/
          kk_string_t _x_x597;
          kk_define_string_literal(, _s_x598, 1, "}", _ctx)
          _x_x597 = kk_string_dup(_s_x598, _ctx); /*string*/
          _x_x591 = kk_std_core_types__lp__plus__plus__rp_(_x_x592, _x_x597, _ctx); /*string*/
          _x_x588 = kk_std_core_types__lp__plus__plus__rp_(_x_x589, _x_x591, _ctx); /*string*/
          _x_x582 = kk_std_core_types__lp__plus__plus__rp_(_x_x583, _x_x588, _ctx); /*string*/
          x_7_10250 = kk_std_core_types__lp__plus__plus__rp_(_x_x580, _x_x582, _ctx); /*string*/
          goto _match_x553;
        }
        if (kk_string_cmp_cstr_borrow(op, "cascade", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_gan__ying__event_type et_0_0;
          kk_box_t _x_x599;
          kk_box_t _x_x603;
          kk_string_t _x_x604 = kk_string_dup(line_0, _ctx); /*string*/
          _x_x603 = kk_string_box(_x_x604); /*10000*/
          _x_x599 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun600(_ctx), _x_x603, _ctx); /*10001*/
          et_0_0 = kk_gan__ying__event_type_unbox(_x_x599, KK_OWNED, _ctx); /*gan_ying/event-type*/
          kk_std_core_types__tuple2 _match_x264;
          kk_box_t _x_x605;
          kk_box_t _x_x610;
          kk_src_unified__runtime__v3__unified_state _x_x611 = kk_src_unified__runtime__v3__unified_state_dup(state_0, _ctx); /*src/unified_runtime_v3/unified-state*/
          _x_x610 = kk_src_unified__runtime__v3__unified_state_box(_x_x611, _ctx); /*10001*/
          _x_x605 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun606(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _x_x610, _ctx); /*10002*/
          _match_x264 = kk_std_core_types__tuple2_unbox(_x_x605, KK_OWNED, _ctx); /*(int, src/unified_runtime_v3/unified-state)*/
          {
            kk_box_t _box_x100 = _match_x264.fst;
            kk_box_t _box_x101 = _match_x264.snd;
            kk_src_unified__runtime__v3__unified_state _pat_8_0 = kk_src_unified__runtime__v3__unified_state_unbox(_box_x101, KK_BORROWED, _ctx);
            struct kk_src_unified__runtime__v3_Unified_state* _con_x612 = kk_src_unified__runtime__v3__as_Unified_state(_pat_8_0, _ctx);
            kk_integer_t handlers = kk_integer_unbox(_box_x100, _ctx);
            kk_integer_dup(handlers, _ctx);
            kk_std_core_types__tuple2_drop(_match_x264, _ctx);
            kk_string_t _x_x613;
            kk_define_string_literal(, _s_x614, 12, "{\"cascade\":\"", _ctx)
            _x_x613 = kk_string_dup(_s_x614, _ctx); /*string*/
            kk_string_t _x_x615;
            kk_string_t _x_x616;
            kk_box_t _x_x617 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun618(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _ctx); /*10001*/
            _x_x616 = kk_string_unbox(_x_x617); /*string*/
            kk_string_t _x_x621;
            kk_string_t _x_x622;
            kk_define_string_literal(, _s_x623, 13, "\",\"handlers\":", _ctx)
            _x_x622 = kk_string_dup(_s_x623, _ctx); /*string*/
            kk_string_t _x_x624;
            kk_string_t _x_x625 = kk_std_core_int_show(handlers, _ctx); /*string*/
            kk_string_t _x_x626;
            kk_define_string_literal(, _s_x627, 1, "}", _ctx)
            _x_x626 = kk_string_dup(_s_x627, _ctx); /*string*/
            _x_x624 = kk_std_core_types__lp__plus__plus__rp_(_x_x625, _x_x626, _ctx); /*string*/
            _x_x621 = kk_std_core_types__lp__plus__plus__rp_(_x_x622, _x_x624, _ctx); /*string*/
            _x_x615 = kk_std_core_types__lp__plus__plus__rp_(_x_x616, _x_x621, _ctx); /*string*/
            x_7_10250 = kk_std_core_types__lp__plus__plus__rp_(_x_x613, _x_x615, _ctx); /*string*/
            goto _match_x553;
          }
        }
        if (kk_string_cmp_cstr_borrow(op, "profile", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_evv_t w_7 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_7 = kk_Unit;
          kk_evv_set(w_7,kk_context());
          kk_evv_t w_8 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_integer_t x_0;
          {
            struct kk_src_unified__runtime__v3_Unified_state* _con_x628 = kk_src_unified__runtime__v3__as_Unified_state(state_0, _ctx);
            kk_std_core_types__list _x_4 = _con_x628->profiles;
            kk_std_core_types__list_dup(_x_4, _ctx);
            if (kk_std_core_types__is_Nil(_x_4, _ctx)) {
              x_0 = kk_integer_from_small(0); /*int*/
            }
            else {
              kk_std_core_types__list_drop(_x_4, _ctx);
              kk_std_core_types__list _x_x629;
              {
                struct kk_src_unified__runtime__v3_Unified_state* _con_x630 = kk_src_unified__runtime__v3__as_Unified_state(state_0, _ctx);
                kk_std_core_types__list _x_4_0 = _con_x630->profiles;
                kk_std_core_types__list_dup(_x_4_0, _ctx);
                _x_x629 = _x_4_0; /*list<hot_paths/path-profile>*/
              }
              x_0 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x629, kk_integer_from_small(0), _ctx); /*int*/
            }
          }
          kk_unit_t keep_8 = kk_Unit;
          kk_evv_set(w_8,kk_context());
          kk_evv_t w_9 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_9 = kk_Unit;
          kk_evv_set(w_9,kk_context());
          kk_string_t _x_x631;
          kk_define_string_literal(, _s_x632, 12, "{\"profiles\":", _ctx)
          _x_x631 = kk_string_dup(_s_x632, _ctx); /*string*/
          kk_string_t _x_x633;
          kk_string_t _x_x634 = kk_std_core_int_show(x_0, _ctx); /*string*/
          kk_string_t _x_x635;
          kk_string_t _x_x636;
          kk_define_string_literal(, _s_x637, 13, ",\"total_ops\":", _ctx)
          _x_x636 = kk_string_dup(_s_x637, _ctx); /*string*/
          kk_string_t _x_x638;
          kk_string_t _x_x639;
          kk_integer_t _x_x640;
          {
            struct kk_src_unified__runtime__v3_Unified_state* _con_x641 = kk_src_unified__runtime__v3__as_Unified_state(state_0, _ctx);
            kk_integer_t _x_5 = _con_x641->total_ops;
            kk_integer_dup(_x_5, _ctx);
            _x_x640 = _x_5; /*int*/
          }
          _x_x639 = kk_std_core_int_show(_x_x640, _ctx); /*string*/
          kk_string_t _x_x642;
          kk_define_string_literal(, _s_x643, 1, "}", _ctx)
          _x_x642 = kk_string_dup(_s_x643, _ctx); /*string*/
          _x_x638 = kk_std_core_types__lp__plus__plus__rp_(_x_x639, _x_x642, _ctx); /*string*/
          _x_x635 = kk_std_core_types__lp__plus__plus__rp_(_x_x636, _x_x638, _ctx); /*string*/
          _x_x633 = kk_std_core_types__lp__plus__plus__rp_(_x_x634, _x_x635, _ctx); /*string*/
          x_7_10250 = kk_std_core_types__lp__plus__plus__rp_(_x_x631, _x_x633, _ctx); /*string*/
          goto _match_x553;
        }
        if (kk_string_cmp_cstr_borrow(op, "status", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_box_t _x_x644;
          kk_box_t _x_x648;
          kk_src_unified__runtime__v3__unified_state _x_x649 = kk_src_unified__runtime__v3__unified_state_dup(state_0, _ctx); /*src/unified_runtime_v3/unified-state*/
          _x_x648 = kk_src_unified__runtime__v3__unified_state_box(_x_x649, _ctx); /*10000*/
          _x_x644 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun645(_ctx), _x_x648, _ctx); /*10001*/
          x_7_10250 = kk_string_unbox(_x_x644); /*string*/
          goto _match_x553;
        }
        if (kk_string_cmp_cstr_borrow(op, "hot", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_evv_t w_8_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_8_0 = kk_Unit;
          kk_evv_set(w_8_0,kk_context());
          kk_std_core_types__list x_10_10258;
          kk_std_core_types__list _x_x650;
          {
            struct kk_src_unified__runtime__v3_Unified_state* _con_x651 = kk_src_unified__runtime__v3__as_Unified_state(state_0, _ctx);
            kk_std_core_types__list _x_6 = _con_x651->profiles;
            kk_std_core_types__list_dup(_x_6, _ctx);
            _x_x650 = _x_6; /*list<hot_paths/path-profile>*/
          }
          x_10_10258 = kk_src_unified__runtime__v3__lift_server_loop_10148(_x_x650, _ctx); /*list<hot_paths/path-profile>*/
          if (kk_yielding(kk_context())) {
            kk_std_core_types__list_drop(x_10_10258, _ctx);
            kk_box_t _x_x652 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun653(_ctx), _ctx); /*10001*/
            x_7_10250 = kk_string_unbox(_x_x652); /*string*/
            goto _match_x553;
          }
          {
            x_7_10250 = kk_src_unified__runtime__v3__mlift_server_loop_10227(x_10_10258, _ctx); /*string*/
            goto _match_x553;
          }
        }
        {
          kk_box_t _x_x656;
          kk_box_t _x_x661;
          kk_src_unified__runtime__v3__unified_state _x_x662 = kk_src_unified__runtime__v3__unified_state_dup(state_0, _ctx); /*src/unified_runtime_v3/unified-state*/
          _x_x661 = kk_src_unified__runtime__v3__unified_state_box(_x_x662, _ctx); /*10001*/
          _x_x656 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun657(_ctx), kk_string_box(op), _x_x661, _ctx); /*10002*/
          x_7_10250 = kk_string_unbox(_x_x656); /*string*/
        }
        _match_x553: ;
      }
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_7_10250, _ctx);
        kk_box_t _x_x663 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v3__new_mlift_server_loop_10229_fun664(line_0, state_0, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x663); return kk_Unit;
      }
      {
        kk_src_unified__runtime__v3__mlift_server_loop_10228(line_0, state_0, x_7_10250, _ctx); return kk_Unit;
      }
    }
  }
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun667__t {
  struct kk_function_s _base;
  kk_src_unified__runtime__v3__unified_state state_2;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun667(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun667(kk_src_unified__runtime__v3__unified_state state_2, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v3_server_loop_fun667__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v3_server_loop_fun667__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v3_server_loop_fun667, kk_context());
  _self->state_2 = state_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun667(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v3_server_loop_fun667__t* _self = kk_function_as(struct kk_src_unified__runtime__v3_server_loop_fun667__t*, _fself, _ctx);
  kk_src_unified__runtime__v3__unified_state state_2 = _self->state_2; /* src/unified_runtime_v3/unified-state */
  kk_drop_match(_self, {kk_src_unified__runtime__v3__unified_state_dup(state_2, _ctx);}, {}, _ctx)
  kk_string_t line_1_247 = kk_string_unbox(_b_x137); /*string*/;
  kk_unit_t _x_x668 = kk_Unit;
  kk_src_unified__runtime__v3__mlift_server_loop_10229(state_2, line_1_247, _ctx);
  return kk_unit_box(_x_x668);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun684__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun684(kk_function_t _fself, kk_box_t _b_x140, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun684(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun684, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun684(kk_function_t _fself, kk_box_t _b_x140, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x685;
  kk_integer_t _x_x686 = kk_integer_unbox(_b_x140, _ctx); /*int*/
  _x_x685 = kk_src_unified__runtime__v3_batch_response(_x_x686, _ctx); /*string*/
  return kk_string_box(_x_x685);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun688__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun688(kk_function_t _fself, kk_box_t _b_x143, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun688(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun688, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun688(kk_function_t _fself, kk_box_t _b_x143, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x689;
  kk_string_t _x_x690 = kk_string_unbox(_b_x143); /*string*/
  _x_x689 = kk_src_unified__runtime__v3_extract_op(_x_x690, _ctx); /*string*/
  return kk_string_box(_x_x689);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun695__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun695(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun695(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun695, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun695(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x696;
  kk_string_t _x_x697 = kk_string_unbox(_b_x148); /*string*/
  _x_x696 = kk_src_unified__runtime__v3_extract_event_type(_x_x697, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x696, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun725__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun725(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun725(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun725, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun725(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x726;
  kk_gan__ying__event_type _x_x727 = kk_gan__ying__event_type_unbox(_b_x161, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x726 = kk_gan__ying_event_type_to_string(_x_x727, _ctx); /*string*/
  return kk_string_box(_x_x726);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun734__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun734(kk_function_t _fself, kk_box_t _b_x164, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun734(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun734, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun734(kk_function_t _fself, kk_box_t _b_x164, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x735;
  kk_src_unified__runtime__v3__unified_state _x_x736 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x164, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  _x_x735 = kk_src_unified__runtime__v3_json_state(_x_x736, _ctx); /*string*/
  return kk_string_box(_x_x735);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun740__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun740(kk_function_t _fself, kk_box_t _b_x167, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun740(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun740, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun740(kk_function_t _fself, kk_box_t _b_x167, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x741;
  kk_string_t _x_x742 = kk_string_unbox(_b_x167); /*string*/
  _x_x741 = kk_src_unified__runtime__v3_extract_event_type(_x_x742, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x741, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun746__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun746(kk_function_t _fself, kk_box_t _b_x173, kk_box_t _b_x174, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun746(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun746, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun746(kk_function_t _fself, kk_box_t _b_x173, kk_box_t _b_x174, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x747;
  kk_gan__ying__event_type _x_x748 = kk_gan__ying__event_type_unbox(_b_x173, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v3__unified_state _x_x749 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x174, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  _x_x747 = kk_src_unified__runtime__v3_cascade_profiled(_x_x748, _x_x749, _ctx); /*(int, src/unified_runtime_v3/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x747, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun758__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun758(kk_function_t _fself, kk_box_t _b_x179, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun758(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun758, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun758(kk_function_t _fself, kk_box_t _b_x179, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x759;
  kk_gan__ying__event_type _x_x760 = kk_gan__ying__event_type_unbox(_b_x179, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x759 = kk_gan__ying_event_type_to_string(_x_x760, _ctx); /*string*/
  return kk_string_box(_x_x759);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun785__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun785(kk_function_t _fself, kk_box_t _b_x182, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun785(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun785, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun785(kk_function_t _fself, kk_box_t _b_x182, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x786;
  kk_src_unified__runtime__v3__unified_state _x_x787 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x182, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  _x_x786 = kk_src_unified__runtime__v3_json_state(_x_x787, _ctx); /*string*/
  return kk_string_box(_x_x786);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun793__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun793(kk_function_t _fself, kk_box_t _b_x184, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun793(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun793, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun793(kk_function_t _fself, kk_box_t _b_x184, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x794;
  kk_std_core_types__list _x_x795 = kk_std_core_types__list_unbox(_b_x184, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
  _x_x794 = kk_src_unified__runtime__v3__mlift_server_loop_10227(_x_x795, _ctx); /*string*/
  return kk_string_box(_x_x794);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun797__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun797(kk_function_t _fself, kk_box_t _b_x188, kk_box_t _b_x189, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun797(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun797, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun797(kk_function_t _fself, kk_box_t _b_x188, kk_box_t _b_x189, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x798;
  kk_string_t _x_x799 = kk_string_unbox(_b_x188); /*string*/
  kk_src_unified__runtime__v3__unified_state _x_x800 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x189, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  _x_x798 = kk_src_unified__runtime__v3_execute_cmd(_x_x799, _x_x800, _ctx); /*string*/
  return kk_string_box(_x_x798);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun804__t {
  struct kk_function_s _base;
  kk_src_unified__runtime__v3__unified_state state_2;
  kk_string_t x_12_10262;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun804(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun804(kk_src_unified__runtime__v3__unified_state state_2, kk_string_t x_12_10262, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v3_server_loop_fun804__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v3_server_loop_fun804__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v3_server_loop_fun804, kk_context());
  _self->state_2 = state_2;
  _self->x_12_10262 = x_12_10262;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun804(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v3_server_loop_fun804__t* _self = kk_function_as(struct kk_src_unified__runtime__v3_server_loop_fun804__t*, _fself, _ctx);
  kk_src_unified__runtime__v3__unified_state state_2 = _self->state_2; /* src/unified_runtime_v3/unified-state */
  kk_string_t x_12_10262 = _self->x_12_10262; /* string */
  kk_drop_match(_self, {kk_src_unified__runtime__v3__unified_state_dup(state_2, _ctx);kk_string_dup(x_12_10262, _ctx);}, {}, _ctx)
  kk_string_t _c_x10155_1_248 = kk_string_unbox(_b_x208); /*string*/;
  kk_unit_t _x_x805 = kk_Unit;
  kk_src_unified__runtime__v3__mlift_server_loop_10228(x_12_10262, state_2, _c_x10155_1_248, _ctx);
  return kk_unit_box(_x_x805);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun821__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun821(kk_function_t _fself, kk_box_t _b_x211, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun821(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun821, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun821(kk_function_t _fself, kk_box_t _b_x211, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x822;
  kk_string_t _x_x823 = kk_string_unbox(_b_x211); /*string*/
  _x_x822 = kk_src_unified__runtime__v3_extract_op(_x_x823, _ctx); /*string*/
  return kk_string_box(_x_x822);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun828__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun828(kk_function_t _fself, kk_box_t _b_x216, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun828(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun828, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun828(kk_function_t _fself, kk_box_t _b_x216, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x829;
  kk_string_t _x_x830 = kk_string_unbox(_b_x216); /*string*/
  _x_x829 = kk_src_unified__runtime__v3_extract_event_type(_x_x830, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x829, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun852__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun852(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun852(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun852, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun852(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x853;
  kk_string_t _x_x854 = kk_string_unbox(_b_x229); /*string*/
  _x_x853 = kk_src_unified__runtime__v3_extract_event_type(_x_x854, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x853, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun856__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun856(kk_function_t _fself, kk_box_t _b_x235, kk_box_t _b_x236, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun856(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun856, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun856(kk_function_t _fself, kk_box_t _b_x235, kk_box_t _b_x236, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x857;
  kk_gan__ying__event_type _x_x858 = kk_gan__ying__event_type_unbox(_b_x235, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_src_unified__runtime__v3__unified_state _x_x859 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x236, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  _x_x857 = kk_src_unified__runtime__v3_cascade_profiled(_x_x858, _x_x859, _ctx); /*(int, src/unified_runtime_v3/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x857, _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v3_server_loop_fun862__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v3_server_loop_fun862(kk_function_t _fself, kk_box_t _b_x243, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v3_new_server_loop_fun862(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v3_server_loop_fun862, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v3_server_loop_fun862(kk_function_t _fself, kk_box_t _b_x243, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x863 = kk_Unit;
  kk_src_unified__runtime__v3__unified_state _x_x864 = kk_src_unified__runtime__v3__unified_state_unbox(_b_x243, KK_OWNED, _ctx); /*src/unified_runtime_v3/unified-state*/
  kk_src_unified__runtime__v3_server_loop(_x_x864, _ctx);
  return kk_unit_box(_x_x863);
}

kk_unit_t kk_src_unified__runtime__v3_server_loop(kk_src_unified__runtime__v3__unified_state state_2, kk_context_t* _ctx) { /* (state : unified-state) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_12_10262 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_12_10262, _ctx);
    kk_box_t _x_x666 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v3_new_server_loop_fun667(state_2, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x666); return kk_Unit;
  }
  {
    bool _match_x250;
    kk_string_t _x_x669 = kk_string_dup(x_12_10262, _ctx); /*string*/
    kk_string_t _x_x670 = kk_string_empty(); /*string*/
    _match_x250 = kk_string_is_eq(_x_x669,_x_x670,kk_context()); /*bool*/
    if (_match_x250) {
      kk_string_drop(x_12_10262, _ctx);
      kk_datatype_ptr_dropn(state_2, (KK_I32(4)), _ctx);
      kk_Unit; return kk_Unit;
    }
    {
      bool _match_x251;
      kk_string_t _x_x672 = kk_string_dup(x_12_10262, _ctx); /*string*/
      kk_string_t _x_x673;
      kk_define_string_literal(, _s_x674, 6, "\"quit\"", _ctx)
      _x_x673 = kk_string_dup(_s_x674, _ctx); /*string*/
      _match_x251 = kk_string_contains(_x_x672,_x_x673,kk_context()); /*bool*/
      if (_match_x251) {
        kk_string_drop(x_12_10262, _ctx);
        kk_datatype_ptr_dropn(state_2, (KK_I32(4)), _ctx);
        kk_string_t _x_x675;
        kk_define_string_literal(, _s_x676, 20, "{\"status\":\"stopped\"}", _ctx)
        _x_x675 = kk_string_dup(_s_x676, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x675, _ctx); return kk_Unit;
      }
      {
        kk_string_t x_13_10265;
        bool _match_x256;
        kk_string_t _x_x677 = kk_string_dup(x_12_10262, _ctx); /*string*/
        kk_string_t _x_x678;
        kk_define_string_literal(, _s_x679, 11, "\"commands\":", _ctx)
        _x_x678 = kk_string_dup(_s_x679, _ctx); /*string*/
        _match_x256 = kk_string_contains(_x_x677,_x_x678,kk_context()); /*bool*/
        if (_match_x256) {
          kk_integer_t n_0;
          kk_string_t _x_x680 = kk_string_dup(x_12_10262, _ctx); /*string*/
          kk_string_t _x_x681;
          kk_define_string_literal(, _s_x682, 6, "{\"id\":", _ctx)
          _x_x681 = kk_string_dup(_s_x682, _ctx); /*string*/
          n_0 = kk_string_count_pattern(_x_x680,_x_x681,kk_context()); /*int*/
          kk_box_t _x_x683 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3_new_server_loop_fun684(_ctx), kk_integer_box(n_0, _ctx), _ctx); /*10001*/
          x_13_10265 = kk_string_unbox(_x_x683); /*string*/
        }
        else {
          kk_string_t op_1;
          kk_box_t _x_x687;
          kk_box_t _x_x691;
          kk_string_t _x_x692 = kk_string_dup(x_12_10262, _ctx); /*string*/
          _x_x691 = kk_string_box(_x_x692); /*10000*/
          _x_x687 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3_new_server_loop_fun688(_ctx), _x_x691, _ctx); /*10001*/
          op_1 = kk_string_unbox(_x_x687); /*string*/
          if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_gan__ying__event_type et_3;
            kk_box_t _x_x694;
            kk_box_t _x_x698;
            kk_string_t _x_x699 = kk_string_dup(x_12_10262, _ctx); /*string*/
            _x_x698 = kk_string_box(_x_x699); /*10000*/
            _x_x694 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3_new_server_loop_fun695(_ctx), _x_x698, _ctx); /*10001*/
            et_3 = kk_gan__ying__event_type_unbox(_x_x694, KK_OWNED, _ctx); /*gan_ying/event-type*/
            kk_evv_t w_9_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_hot__paths__path_profile profile_1;
            kk_string_t _x_x700 = kk_gan__ying_event_type_to_string(et_3, _ctx); /*string*/
            profile_1 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x700, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
            kk_src_unified__runtime__v3__unified_state x_14;
            kk_std_core_types__list _x_x701;
            kk_box_t _x_x702;
            kk_gan__ying__resonance_event _x_x703;
            kk_string_t _x_x704;
            kk_define_string_literal(, _s_x705, 18, "unified_runtime_v3", _ctx)
            _x_x704 = kk_string_dup(_s_x705, _ctx); /*string*/
            kk_string_t _x_x706 = kk_string_empty(); /*string*/
            _x_x703 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x704, et_3, _x_x706, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
            _x_x702 = kk_gan__ying__resonance_event_box(_x_x703, _ctx); /*10021*/
            kk_std_core_types__list _x_x708;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x709 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_std_core_types__list _x_7 = _con_x709->events;
              kk_std_core_types__list_dup(_x_7, _ctx);
              _x_x708 = _x_7; /*list<gan_ying/resonance-event>*/
            }
            _x_x701 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x702, _x_x708, _ctx); /*list<10021>*/
            kk_std_core_types__list _x_x710;
            kk_std_core_types__list _x_x711;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x712 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_std_core_types__list _x_0_0 = _con_x712->profiles;
              kk_std_core_types__list_dup(_x_0_0, _ctx);
              _x_x711 = _x_0_0; /*list<hot_paths/path-profile>*/
            }
            _x_x710 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_1, _ctx), _x_x711, _ctx); /*list<10021>*/
            kk_integer_t _x_x713;
            kk_integer_t _x_x714;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x715 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_integer_t _x_1_0 = _con_x715->total_ops;
              kk_integer_dup(_x_1_0, _ctx);
              _x_x714 = _x_1_0; /*int*/
            }
            _x_x713 = kk_integer_add_small_const(_x_x714, 1, _ctx); /*int*/
            kk_integer_t _x_x716;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x717 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_integer_t _x_2_0 = _con_x717->batch_count;
              kk_integer_dup(_x_2_0, _ctx);
              _x_x716 = _x_2_0; /*int*/
            }
            double _x_x718;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x719 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              double _x_3_0 = _con_x719->session_start;
              _x_x718 = _x_3_0; /*float64*/
            }
            x_14 = kk_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x701, _x_x710, _x_x713, _x_x716, _x_x718, _ctx); /*src/unified_runtime_v3/unified-state*/
            kk_unit_t keep_9_0 = kk_Unit;
            kk_evv_set(w_9_0,kk_context());
            kk_string_t _x_x720;
            kk_define_string_literal(, _s_x721, 12, "{\"emitted\":\"", _ctx)
            _x_x720 = kk_string_dup(_s_x721, _ctx); /*string*/
            kk_string_t _x_x722;
            kk_string_t _x_x723;
            kk_box_t _x_x724 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3_new_server_loop_fun725(_ctx), kk_gan__ying__event_type_box(et_3, _ctx), _ctx); /*10001*/
            _x_x723 = kk_string_unbox(_x_x724); /*string*/
            kk_string_t _x_x728;
            kk_string_t _x_x729;
            kk_define_string_literal(, _s_x730, 10, "\",\"state\":", _ctx)
            _x_x729 = kk_string_dup(_s_x730, _ctx); /*string*/
            kk_string_t _x_x731;
            kk_string_t _x_x732;
            kk_box_t _x_x733 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3_new_server_loop_fun734(_ctx), kk_src_unified__runtime__v3__unified_state_box(x_14, _ctx), _ctx); /*10001*/
            _x_x732 = kk_string_unbox(_x_x733); /*string*/
            kk_string_t _x_x737;
            kk_define_string_literal(, _s_x738, 1, "}", _ctx)
            _x_x737 = kk_string_dup(_s_x738, _ctx); /*string*/
            _x_x731 = kk_std_core_types__lp__plus__plus__rp_(_x_x732, _x_x737, _ctx); /*string*/
            _x_x728 = kk_std_core_types__lp__plus__plus__rp_(_x_x729, _x_x731, _ctx); /*string*/
            _x_x722 = kk_std_core_types__lp__plus__plus__rp_(_x_x723, _x_x728, _ctx); /*string*/
            x_13_10265 = kk_std_core_types__lp__plus__plus__rp_(_x_x720, _x_x722, _ctx); /*string*/
            goto _match_x693;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_gan__ying__event_type et_0_0_0;
            kk_box_t _x_x739;
            kk_box_t _x_x743;
            kk_string_t _x_x744 = kk_string_dup(x_12_10262, _ctx); /*string*/
            _x_x743 = kk_string_box(_x_x744); /*10000*/
            _x_x739 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3_new_server_loop_fun740(_ctx), _x_x743, _ctx); /*10001*/
            et_0_0_0 = kk_gan__ying__event_type_unbox(_x_x739, KK_OWNED, _ctx); /*gan_ying/event-type*/
            kk_std_core_types__tuple2 _match_x258;
            kk_box_t _x_x745;
            kk_box_t _x_x750;
            kk_src_unified__runtime__v3__unified_state _x_x751 = kk_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*src/unified_runtime_v3/unified-state*/
            _x_x750 = kk_src_unified__runtime__v3__unified_state_box(_x_x751, _ctx); /*10001*/
            _x_x745 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v3_new_server_loop_fun746(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _x_x750, _ctx); /*10002*/
            _match_x258 = kk_std_core_types__tuple2_unbox(_x_x745, KK_OWNED, _ctx); /*(int, src/unified_runtime_v3/unified-state)*/
            {
              kk_box_t _box_x175 = _match_x258.fst;
              kk_box_t _box_x176 = _match_x258.snd;
              kk_src_unified__runtime__v3__unified_state _pat_8_0_0 = kk_src_unified__runtime__v3__unified_state_unbox(_box_x176, KK_BORROWED, _ctx);
              struct kk_src_unified__runtime__v3_Unified_state* _con_x752 = kk_src_unified__runtime__v3__as_Unified_state(_pat_8_0_0, _ctx);
              kk_integer_t handlers_0 = kk_integer_unbox(_box_x175, _ctx);
              kk_integer_dup(handlers_0, _ctx);
              kk_std_core_types__tuple2_drop(_match_x258, _ctx);
              kk_string_t _x_x753;
              kk_define_string_literal(, _s_x754, 12, "{\"cascade\":\"", _ctx)
              _x_x753 = kk_string_dup(_s_x754, _ctx); /*string*/
              kk_string_t _x_x755;
              kk_string_t _x_x756;
              kk_box_t _x_x757 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3_new_server_loop_fun758(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _ctx); /*10001*/
              _x_x756 = kk_string_unbox(_x_x757); /*string*/
              kk_string_t _x_x761;
              kk_string_t _x_x762;
              kk_define_string_literal(, _s_x763, 13, "\",\"handlers\":", _ctx)
              _x_x762 = kk_string_dup(_s_x763, _ctx); /*string*/
              kk_string_t _x_x764;
              kk_string_t _x_x765 = kk_std_core_int_show(handlers_0, _ctx); /*string*/
              kk_string_t _x_x766;
              kk_define_string_literal(, _s_x767, 1, "}", _ctx)
              _x_x766 = kk_string_dup(_s_x767, _ctx); /*string*/
              _x_x764 = kk_std_core_types__lp__plus__plus__rp_(_x_x765, _x_x766, _ctx); /*string*/
              _x_x761 = kk_std_core_types__lp__plus__plus__rp_(_x_x762, _x_x764, _ctx); /*string*/
              _x_x755 = kk_std_core_types__lp__plus__plus__rp_(_x_x756, _x_x761, _ctx); /*string*/
              x_13_10265 = kk_std_core_types__lp__plus__plus__rp_(_x_x753, _x_x755, _ctx); /*string*/
              goto _match_x693;
            }
          }
          if (kk_string_cmp_cstr_borrow(op_1, "profile", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_evv_t w_10 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_10 = kk_Unit;
            kk_evv_set(w_10,kk_context());
            kk_evv_t w_11 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_integer_t x_10;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x768 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_std_core_types__list _x_4_0_0 = _con_x768->profiles;
              kk_std_core_types__list_dup(_x_4_0_0, _ctx);
              if (kk_std_core_types__is_Nil(_x_4_0_0, _ctx)) {
                x_10 = kk_integer_from_small(0); /*int*/
              }
              else {
                kk_std_core_types__list_drop(_x_4_0_0, _ctx);
                kk_std_core_types__list _x_x769;
                {
                  struct kk_src_unified__runtime__v3_Unified_state* _con_x770 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
                  kk_std_core_types__list _x_4_0_1 = _con_x770->profiles;
                  kk_std_core_types__list_dup(_x_4_0_1, _ctx);
                  _x_x769 = _x_4_0_1; /*list<hot_paths/path-profile>*/
                }
                x_10 = kk_std_core_list__unroll_lift_length_5730_10000(_x_x769, kk_integer_from_small(0), _ctx); /*int*/
              }
            }
            kk_unit_t keep_11 = kk_Unit;
            kk_evv_set(w_11,kk_context());
            kk_evv_t w_12 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_12 = kk_Unit;
            kk_evv_set(w_12,kk_context());
            kk_string_t _x_x771;
            kk_define_string_literal(, _s_x772, 12, "{\"profiles\":", _ctx)
            _x_x771 = kk_string_dup(_s_x772, _ctx); /*string*/
            kk_string_t _x_x773;
            kk_string_t _x_x774 = kk_std_core_int_show(x_10, _ctx); /*string*/
            kk_string_t _x_x775;
            kk_string_t _x_x776;
            kk_define_string_literal(, _s_x777, 13, ",\"total_ops\":", _ctx)
            _x_x776 = kk_string_dup(_s_x777, _ctx); /*string*/
            kk_string_t _x_x778;
            kk_string_t _x_x779;
            kk_integer_t _x_x780;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x781 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_integer_t _x_5_0 = _con_x781->total_ops;
              kk_integer_dup(_x_5_0, _ctx);
              _x_x780 = _x_5_0; /*int*/
            }
            _x_x779 = kk_std_core_int_show(_x_x780, _ctx); /*string*/
            kk_string_t _x_x782;
            kk_define_string_literal(, _s_x783, 1, "}", _ctx)
            _x_x782 = kk_string_dup(_s_x783, _ctx); /*string*/
            _x_x778 = kk_std_core_types__lp__plus__plus__rp_(_x_x779, _x_x782, _ctx); /*string*/
            _x_x775 = kk_std_core_types__lp__plus__plus__rp_(_x_x776, _x_x778, _ctx); /*string*/
            _x_x773 = kk_std_core_types__lp__plus__plus__rp_(_x_x774, _x_x775, _ctx); /*string*/
            x_13_10265 = kk_std_core_types__lp__plus__plus__rp_(_x_x771, _x_x773, _ctx); /*string*/
            goto _match_x693;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_box_t _x_x784;
            kk_box_t _x_x788;
            kk_src_unified__runtime__v3__unified_state _x_x789 = kk_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*src/unified_runtime_v3/unified-state*/
            _x_x788 = kk_src_unified__runtime__v3__unified_state_box(_x_x789, _ctx); /*10000*/
            _x_x784 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3_new_server_loop_fun785(_ctx), _x_x788, _ctx); /*10001*/
            x_13_10265 = kk_string_unbox(_x_x784); /*string*/
            goto _match_x693;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "hot", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_evv_t w_11_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_11_0 = kk_Unit;
            kk_evv_set(w_11_0,kk_context());
            kk_std_core_types__list x_16_10274;
            kk_std_core_types__list _x_x790;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x791 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_std_core_types__list _x_6_0 = _con_x791->profiles;
              kk_std_core_types__list_dup(_x_6_0, _ctx);
              _x_x790 = _x_6_0; /*list<hot_paths/path-profile>*/
            }
            x_16_10274 = kk_src_unified__runtime__v3__lift_server_loop_10148(_x_x790, _ctx); /*list<hot_paths/path-profile>*/
            if (kk_yielding(kk_context())) {
              kk_std_core_types__list_drop(x_16_10274, _ctx);
              kk_box_t _x_x792 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v3_new_server_loop_fun793(_ctx), _ctx); /*10001*/
              x_13_10265 = kk_string_unbox(_x_x792); /*string*/
              goto _match_x693;
            }
            {
              x_13_10265 = kk_src_unified__runtime__v3__mlift_server_loop_10227(x_16_10274, _ctx); /*string*/
              goto _match_x693;
            }
          }
          {
            kk_box_t _x_x796;
            kk_box_t _x_x801;
            kk_src_unified__runtime__v3__unified_state _x_x802 = kk_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*src/unified_runtime_v3/unified-state*/
            _x_x801 = kk_src_unified__runtime__v3__unified_state_box(_x_x802, _ctx); /*10001*/
            _x_x796 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v3_new_server_loop_fun797(_ctx), kk_string_box(op_1), _x_x801, _ctx); /*10002*/
            x_13_10265 = kk_string_unbox(_x_x796); /*string*/
          }
          _match_x693: ;
        }
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_13_10265, _ctx);
          kk_box_t _x_x803 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v3_new_server_loop_fun804(state_2, x_12_10262, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x803); return kk_Unit;
        }
        {
          kk_unit_t ___0 = kk_Unit;
          kk_std_core_console_printsln(x_13_10265, _ctx);
          kk_src_unified__runtime__v3__unified_state x_18_10278;
          bool _match_x254;
          kk_string_t _x_x806 = kk_string_dup(x_12_10262, _ctx); /*string*/
          kk_string_t _x_x807;
          kk_define_string_literal(, _s_x808, 11, "\"commands\":", _ctx)
          _x_x807 = kk_string_dup(_s_x808, _ctx); /*string*/
          _match_x254 = kk_string_contains(_x_x806,_x_x807,kk_context()); /*bool*/
          if (_match_x254) {
            kk_string_drop(x_12_10262, _ctx);
            kk_evv_t w_12_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_12_0 = kk_Unit;
            kk_evv_set(w_12_0,kk_context());
            kk_evv_t w_13 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_13 = kk_Unit;
            kk_evv_set(w_13,kk_context());
            kk_evv_t w_14 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_14 = kk_Unit;
            kk_evv_set(w_14,kk_context());
            kk_evv_t w_15 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_15 = kk_Unit;
            kk_evv_set(w_15,kk_context());
            kk_evv_t w_16 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_16 = kk_Unit;
            kk_evv_set(w_16,kk_context());
            kk_std_core_types__list _x_x809;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x810 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_std_core_types__list _x_8_0 = _con_x810->events;
              kk_std_core_types__list_dup(_x_8_0, _ctx);
              _x_x809 = _x_8_0; /*list<gan_ying/resonance-event>*/
            }
            kk_std_core_types__list _x_x811;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x812 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_std_core_types__list _x_9_0 = _con_x812->profiles;
              kk_std_core_types__list_dup(_x_9_0, _ctx);
              _x_x811 = _x_9_0; /*list<hot_paths/path-profile>*/
            }
            kk_integer_t _x_x813;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x814 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_integer_t _x_10_0 = _con_x814->total_ops;
              kk_integer_dup(_x_10_0, _ctx);
              _x_x813 = _x_10_0; /*int*/
            }
            kk_integer_t _x_x815;
            kk_integer_t _x_x816;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x817 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_integer_t _x_11_0 = _con_x817->batch_count;
              kk_integer_dup(_x_11_0, _ctx);
              _x_x816 = _x_11_0; /*int*/
            }
            _x_x815 = kk_integer_add_small_const(_x_x816, 1, _ctx); /*int*/
            double _x_x818;
            {
              struct kk_src_unified__runtime__v3_Unified_state* _con_x819 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
              kk_std_core_types__list _pat_0_13_0 = _con_x819->events;
              kk_std_core_types__list _pat_1_15_0 = _con_x819->profiles;
              kk_integer_t _pat_2_13_0 = _con_x819->total_ops;
              kk_integer_t _pat_3_13_0 = _con_x819->batch_count;
              double _x_12_0 = _con_x819->session_start;
              if kk_likely(kk_datatype_ptr_is_unique(state_2, _ctx)) {
                kk_integer_drop(_pat_3_13_0, _ctx);
                kk_integer_drop(_pat_2_13_0, _ctx);
                kk_std_core_types__list_drop(_pat_1_15_0, _ctx);
                kk_std_core_types__list_drop(_pat_0_13_0, _ctx);
                kk_datatype_ptr_free(state_2, _ctx);
              }
              else {
                kk_datatype_ptr_decref(state_2, _ctx);
              }
              _x_x818 = _x_12_0; /*float64*/
            }
            x_18_10278 = kk_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x809, _x_x811, _x_x813, _x_x815, _x_x818, _ctx); /*src/unified_runtime_v3/unified-state*/
          }
          else {
            kk_string_t op_0_0;
            kk_box_t _x_x820;
            kk_box_t _x_x824;
            kk_string_t _x_x825 = kk_string_dup(x_12_10262, _ctx); /*string*/
            _x_x824 = kk_string_box(_x_x825); /*10000*/
            _x_x820 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3_new_server_loop_fun821(_ctx), _x_x824, _ctx); /*10001*/
            op_0_0 = kk_string_unbox(_x_x820); /*string*/
            if (kk_string_cmp_cstr_borrow(op_0_0, "emit", _ctx) == 0) {
              kk_string_drop(op_0_0, _ctx);
              kk_gan__ying__event_type et_1_0;
              kk_box_t _x_x827 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3_new_server_loop_fun828(_ctx), kk_string_box(x_12_10262), _ctx); /*10001*/
              et_1_0 = kk_gan__ying__event_type_unbox(_x_x827, KK_OWNED, _ctx); /*gan_ying/event-type*/
              kk_evv_t w_17 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
              kk_hot__paths__path_profile profile_0_0;
              kk_string_t _x_x831 = kk_gan__ying_event_type_to_string(et_1_0, _ctx); /*string*/
              profile_0_0 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x831, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
              kk_src_unified__runtime__v3__unified_state x_24;
              kk_std_core_types__list _x_x832;
              kk_box_t _x_x833;
              kk_gan__ying__resonance_event _x_x834;
              kk_string_t _x_x835;
              kk_define_string_literal(, _s_x836, 18, "unified_runtime_v3", _ctx)
              _x_x835 = kk_string_dup(_s_x836, _ctx); /*string*/
              kk_string_t _x_x837 = kk_string_empty(); /*string*/
              _x_x834 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x835, et_1_0, _x_x837, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
              _x_x833 = kk_gan__ying__resonance_event_box(_x_x834, _ctx); /*10021*/
              kk_std_core_types__list _x_x839;
              {
                struct kk_src_unified__runtime__v3_Unified_state* _con_x840 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
                kk_std_core_types__list _x_13_0 = _con_x840->events;
                kk_std_core_types__list_dup(_x_13_0, _ctx);
                _x_x839 = _x_13_0; /*list<gan_ying/resonance-event>*/
              }
              _x_x832 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x833, _x_x839, _ctx); /*list<10021>*/
              kk_std_core_types__list _x_x841;
              kk_std_core_types__list _x_x842;
              {
                struct kk_src_unified__runtime__v3_Unified_state* _con_x843 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
                kk_std_core_types__list _x_14_0 = _con_x843->profiles;
                kk_std_core_types__list_dup(_x_14_0, _ctx);
                _x_x842 = _x_14_0; /*list<hot_paths/path-profile>*/
              }
              _x_x841 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_0_0, _ctx), _x_x842, _ctx); /*list<10021>*/
              kk_integer_t _x_x844;
              kk_integer_t _x_x845;
              {
                struct kk_src_unified__runtime__v3_Unified_state* _con_x846 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
                kk_integer_t _x_15_0 = _con_x846->total_ops;
                kk_integer_dup(_x_15_0, _ctx);
                _x_x845 = _x_15_0; /*int*/
              }
              _x_x844 = kk_integer_add_small_const(_x_x845, 1, _ctx); /*int*/
              kk_integer_t _x_x847;
              {
                struct kk_src_unified__runtime__v3_Unified_state* _con_x848 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
                kk_integer_t _x_16_0 = _con_x848->batch_count;
                kk_integer_dup(_x_16_0, _ctx);
                _x_x847 = _x_16_0; /*int*/
              }
              double _x_x849;
              {
                struct kk_src_unified__runtime__v3_Unified_state* _con_x850 = kk_src_unified__runtime__v3__as_Unified_state(state_2, _ctx);
                kk_std_core_types__list _pat_0_18_0 = _con_x850->events;
                kk_std_core_types__list _pat_1_20_0 = _con_x850->profiles;
                kk_integer_t _pat_2_18_0 = _con_x850->total_ops;
                kk_integer_t _pat_3_18_0 = _con_x850->batch_count;
                double _x_17_0 = _con_x850->session_start;
                if kk_likely(kk_datatype_ptr_is_unique(state_2, _ctx)) {
                  kk_integer_drop(_pat_3_18_0, _ctx);
                  kk_integer_drop(_pat_2_18_0, _ctx);
                  kk_std_core_types__list_drop(_pat_1_20_0, _ctx);
                  kk_std_core_types__list_drop(_pat_0_18_0, _ctx);
                  kk_datatype_ptr_free(state_2, _ctx);
                }
                else {
                  kk_datatype_ptr_decref(state_2, _ctx);
                }
                _x_x849 = _x_17_0; /*float64*/
              }
              x_24 = kk_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x832, _x_x841, _x_x844, _x_x847, _x_x849, _ctx); /*src/unified_runtime_v3/unified-state*/
              kk_unit_t keep_17 = kk_Unit;
              kk_evv_set(w_17,kk_context());
              x_18_10278 = x_24; /*src/unified_runtime_v3/unified-state*/
              goto _match_x826;
            }
            if (kk_string_cmp_cstr_borrow(op_0_0, "cascade", _ctx) == 0) {
              kk_string_drop(op_0_0, _ctx);
              kk_gan__ying__event_type et_2_0_0;
              kk_box_t _x_x851 = kk_std_core_hnd__open_none1(kk_src_unified__runtime__v3_new_server_loop_fun852(_ctx), kk_string_box(x_12_10262), _ctx); /*10001*/
              et_2_0_0 = kk_gan__ying__event_type_unbox(_x_x851, KK_OWNED, _ctx); /*gan_ying/event-type*/
              kk_std_core_types__tuple2 _match_x255;
              kk_box_t _x_x855 = kk_std_core_hnd__open_none2(kk_src_unified__runtime__v3_new_server_loop_fun856(_ctx), kk_gan__ying__event_type_box(et_2_0_0, _ctx), kk_src_unified__runtime__v3__unified_state_box(state_2, _ctx), _ctx); /*10002*/
              _match_x255 = kk_std_core_types__tuple2_unbox(_x_x855, KK_OWNED, _ctx); /*(int, src/unified_runtime_v3/unified-state)*/
              {
                kk_box_t _box_x237 = _match_x255.fst;
                kk_box_t _box_x238 = _match_x255.snd;
                kk_src_unified__runtime__v3__unified_state ns_0 = kk_src_unified__runtime__v3__unified_state_unbox(_box_x238, KK_BORROWED, _ctx);
                struct kk_src_unified__runtime__v3_Unified_state* _con_x860 = kk_src_unified__runtime__v3__as_Unified_state(ns_0, _ctx);
                kk_src_unified__runtime__v3__unified_state_dup(ns_0, _ctx);
                kk_std_core_types__tuple2_drop(_match_x255, _ctx);
                x_18_10278 = ns_0; /*src/unified_runtime_v3/unified-state*/
                goto _match_x826;
              }
            }
            {
              kk_string_drop(x_12_10262, _ctx);
              kk_string_drop(op_0_0, _ctx);
              x_18_10278 = state_2; /*src/unified_runtime_v3/unified-state*/
            }
            _match_x826: ;
          }
          if (kk_yielding(kk_context())) {
            kk_datatype_ptr_dropn(x_18_10278, (KK_I32(4)), _ctx);
            kk_box_t _x_x861 = kk_std_core_hnd_yield_extend(kk_src_unified__runtime__v3_new_server_loop_fun862(_ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x861); return kk_Unit;
          }
          { // tailcall
            state_2 = x_18_10278;
            goto kk__tailcall;
          }
        }
      }
    }
  }
}

// initialization
void kk_src_unified__runtime__v3__init(kk_context_t* _ctx){
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
void kk_src_unified__runtime__v3__done(kk_context_t* _ctx){
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
