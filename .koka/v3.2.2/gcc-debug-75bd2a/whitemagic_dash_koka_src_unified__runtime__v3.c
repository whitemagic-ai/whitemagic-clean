// Koka generated module: whitemagic-koka/src/unified_runtime_v3, koka version: 3.2.2, platform: 64-bit
#include "whitemagic_dash_koka_src_unified__runtime__v3.h"

kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state kk_whitemagic_dash_koka_src_unified__runtime__v3_unified_state_fs__copy(kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _this, kk_std_core_types__optional events, kk_std_core_types__optional profiles, kk_std_core_types__optional total_ops, kk_std_core_types__optional batch_count, kk_std_core_types__optional session_start, kk_context_t* _ctx) { /* (unified-state, events : ? (list<gan_ying/resonance-event>), profiles : ? (list<hot_paths/path-profile>), total-ops : ? int, batch-count : ? int, session-start : ? float64) -> unified-state */ 
  kk_std_core_types__list _x_x502;
  if (kk_std_core_types__is_Optional(events, _ctx)) {
    kk_box_t _box_x0 = events._cons._Optional.value;
    kk_std_core_types__list _uniq_events_79 = kk_std_core_types__list_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_events_79, _ctx);
    kk_std_core_types__optional_drop(events, _ctx);
    _x_x502 = _uniq_events_79; /*list<gan_ying/resonance-event>*/
  }
  else {
    kk_std_core_types__optional_drop(events, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x503 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _x = _con_x503->events;
      kk_std_core_types__list_dup(_x, _ctx);
      _x_x502 = _x; /*list<gan_ying/resonance-event>*/
    }
  }
  kk_std_core_types__list _x_x504;
  if (kk_std_core_types__is_Optional(profiles, _ctx)) {
    kk_box_t _box_x1 = profiles._cons._Optional.value;
    kk_std_core_types__list _uniq_profiles_87 = kk_std_core_types__list_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_profiles_87, _ctx);
    kk_std_core_types__optional_drop(profiles, _ctx);
    _x_x504 = _uniq_profiles_87; /*list<hot_paths/path-profile>*/
  }
  else {
    kk_std_core_types__optional_drop(profiles, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x505 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x505->profiles;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x504 = _x_0; /*list<hot_paths/path-profile>*/
    }
  }
  kk_integer_t _x_x506;
  if (kk_std_core_types__is_Optional(total_ops, _ctx)) {
    kk_box_t _box_x2 = total_ops._cons._Optional.value;
    kk_integer_t _uniq_total_ops_95 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_total_ops_95, _ctx);
    kk_std_core_types__optional_drop(total_ops, _ctx);
    _x_x506 = _uniq_total_ops_95; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(total_ops, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x507 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
      kk_integer_t _x_1 = _con_x507->total_ops;
      kk_integer_dup(_x_1, _ctx);
      _x_x506 = _x_1; /*int*/
    }
  }
  kk_integer_t _x_x508;
  if (kk_std_core_types__is_Optional(batch_count, _ctx)) {
    kk_box_t _box_x3 = batch_count._cons._Optional.value;
    kk_integer_t _uniq_batch_count_103 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_batch_count_103, _ctx);
    kk_std_core_types__optional_drop(batch_count, _ctx);
    _x_x508 = _uniq_batch_count_103; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(batch_count, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x509 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
      kk_integer_t _x_2 = _con_x509->batch_count;
      kk_integer_dup(_x_2, _ctx);
      _x_x508 = _x_2; /*int*/
    }
  }
  double _x_x510;
  if (kk_std_core_types__is_Optional(session_start, _ctx)) {
    kk_box_t _box_x4 = session_start._cons._Optional.value;
    double _uniq_session_start_111 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(session_start, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(4)), _ctx);
    _x_x510 = _uniq_session_start_111; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(session_start, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x511 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_this, _ctx);
      kk_std_core_types__list _pat_0_4 = _con_x511->events;
      kk_std_core_types__list _pat_1_5 = _con_x511->profiles;
      kk_integer_t _pat_2_4 = _con_x511->total_ops;
      kk_integer_t _pat_3_4 = _con_x511->batch_count;
      double _x_3 = _con_x511->session_start;
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
      _x_x510 = _x_3; /*float64*/
    }
  }
  return kk_whitemagic_dash_koka_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x502, _x_x504, _x_x506, _x_x508, _x_x510, _ctx);
}

kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state kk_whitemagic_dash_koka_src_unified__runtime__v3_emit_profiled(kk_gan__ying__event_type et, kk_string_t source, kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state, kk_context_t* _ctx) { /* (et : gan_ying/event-type, source : string, state : unified-state) -> unified-state */ 
  kk_hot__paths__path_profile profile;
  kk_string_t _x_x512 = kk_gan__ying_event_type_to_string(et, _ctx); /*string*/
  profile = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x512, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_std_core_types__list _x_x513;
  kk_box_t _x_x514;
  kk_gan__ying__resonance_event _x_x515;
  kk_string_t _x_x516 = kk_string_empty(); /*string*/
  _x_x515 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, source, et, _x_x516, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x514 = kk_gan__ying__resonance_event_box(_x_x515, _ctx); /*10021*/
  kk_std_core_types__list _x_x518;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x519 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x = _con_x519->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x518 = _x; /*list<gan_ying/resonance-event>*/
  }
  _x_x513 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x514, _x_x518, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x520;
  kk_std_core_types__list _x_x521;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x522 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x_0 = _con_x522->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x521 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x520 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile, _ctx), _x_x521, _ctx); /*list<10021>*/
  kk_integer_t _x_x523;
  kk_integer_t _x_x524;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x525 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_integer_t _x_1 = _con_x525->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x524 = _x_1; /*int*/
  }
  _x_x523 = kk_integer_add_small_const(_x_x524, 1, _ctx); /*int*/
  kk_integer_t _x_x526;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x527 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_integer_t _x_2 = _con_x527->batch_count;
    kk_integer_dup(_x_2, _ctx);
    _x_x526 = _x_2; /*int*/
  }
  double _x_x528;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x529 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _pat_0_3 = _con_x529->events;
    kk_std_core_types__list _pat_1_3 = _con_x529->profiles;
    kk_integer_t _pat_2_3 = _con_x529->total_ops;
    kk_integer_t _pat_3_3 = _con_x529->batch_count;
    double _x_3 = _con_x529->session_start;
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
    _x_x528 = _x_3; /*float64*/
  }
  return kk_whitemagic_dash_koka_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x513, _x_x520, _x_x523, _x_x526, _x_x528, _ctx);
}

kk_std_core_types__tuple2 kk_whitemagic_dash_koka_src_unified__runtime__v3_cascade_profiled(kk_gan__ying__event_type et, kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state, kk_context_t* _ctx) { /* (et : gan_ying/event-type, state : unified-state) -> (int, unified-state) */ 
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state new_state;
  kk_std_core_types__list _x_x530;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x531 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x = _con_x531->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x530 = _x; /*list<gan_ying/resonance-event>*/
  }
  kk_std_core_types__list _x_x532;
  kk_box_t _x_x533;
  kk_hot__paths__path_profile _x_x534;
  kk_string_t _x_x535;
  kk_define_string_literal(, _s_x536, 13, "cascade_check", _ctx)
  _x_x535 = kk_string_dup(_s_x536, _ctx); /*string*/
  _x_x534 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x535, kk_integer_from_small(1), 0x1p-1, 0x1p-1, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_Compute(_ctx), _ctx); /*hot_paths/path-profile*/
  _x_x533 = kk_hot__paths__path_profile_box(_x_x534, _ctx); /*10021*/
  kk_std_core_types__list _x_x537;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x538 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _x_0 = _con_x538->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x537 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x532 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x533, _x_x537, _ctx); /*list<10021>*/
  kk_integer_t _x_x539;
  kk_integer_t _x_x540;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x541 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_integer_t _x_1 = _con_x541->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x540 = _x_1; /*int*/
  }
  _x_x539 = kk_integer_add_small_const(_x_x540, 1, _ctx); /*int*/
  kk_integer_t _x_x542;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x543 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_integer_t _x_2 = _con_x543->batch_count;
    kk_integer_dup(_x_2, _ctx);
    _x_x542 = _x_2; /*int*/
  }
  double _x_x544;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x545 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state, _ctx);
    kk_std_core_types__list _pat_0_3 = _con_x545->events;
    kk_std_core_types__list _pat_1_3 = _con_x545->profiles;
    kk_integer_t _pat_2_3 = _con_x545->total_ops;
    kk_integer_t _pat_3_3 = _con_x545->batch_count;
    double _x_3 = _con_x545->session_start;
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
    _x_x544 = _x_3; /*float64*/
  }
  new_state = kk_whitemagic_dash_koka_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x530, _x_x532, _x_x539, _x_x542, _x_x544, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  kk_box_t _x_x546;
  kk_integer_t _x_x547;
  if (kk_gan__ying__is_MemoryCreated(et, _ctx)) {
    _x_x547 = kk_integer_from_small(3); /*int*/
    goto _match_x548;
  }
  if (kk_gan__ying__is_MemoryUpdated(et, _ctx)) {
    _x_x547 = kk_integer_from_small(2); /*int*/
    goto _match_x548;
  }
  if (kk_gan__ying__is_ThreatDetected(et, _ctx)) {
    _x_x547 = kk_integer_from_small(5); /*int*/
    goto _match_x548;
  }
  if (kk_gan__ying__is_FlowStateEntered(et, _ctx)) {
    _x_x547 = kk_integer_from_small(2); /*int*/
    goto _match_x548;
  }
  {
    _x_x547 = kk_integer_from_small(1); /*int*/
  }
  _match_x548: ;
  _x_x546 = kk_integer_box(_x_x547, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x546, kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(new_state, _ctx), _ctx);
}
 
// Extract request ID from batch

kk_string_t kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_request_id(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  kk_vector_t v_10011;
  kk_string_t _x_x553;
  kk_define_string_literal(, _s_x554, 14, "\"request_id\":\"", _ctx)
  _x_x553 = kk_string_dup(_s_x554, _ctx); /*string*/
  v_10011 = kk_string_splitv(line,_x_x553,kk_context()); /*vector<string>*/
  kk_std_core_types__list parts = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  if (kk_std_core_types__is_Cons(parts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x555 = kk_std_core_types__as_Cons(parts, _ctx);
    kk_box_t _box_x21 = _con_x555->head;
    kk_std_core_types__list _pat_1 = _con_x555->tail;
    if (kk_std_core_types__is_Cons(_pat_1, _ctx)) {
      struct kk_std_core_types_Cons* _con_x556 = kk_std_core_types__as_Cons(_pat_1, _ctx);
      kk_box_t _box_x22 = _con_x556->head;
      kk_string_t _pat_0 = kk_string_unbox(_box_x21);
      kk_std_core_types__list _pat_2 = _con_x556->tail;
      kk_string_t rest = kk_string_unbox(_box_x22);
      if kk_likely(kk_datatype_ptr_is_unique(parts, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_1, _ctx)) {
          kk_std_core_types__list_drop(_pat_2, _ctx);
          kk_datatype_ptr_free(_pat_1, _ctx);
        }
        else {
          kk_string_dup(rest, _ctx);
          kk_datatype_ptr_decref(_pat_1, _ctx);
        }
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(parts, _ctx);
      }
      else {
        kk_string_dup(rest, _ctx);
        kk_datatype_ptr_decref(parts, _ctx);
      }
      kk_vector_t v_10011_0;
      kk_string_t _x_x557;
      kk_define_string_literal(, _s_x558, 1, "\"", _ctx)
      _x_x557 = kk_string_dup(_s_x558, _ctx); /*string*/
      v_10011_0 = kk_string_splitv(rest,_x_x557,kk_context()); /*vector<string>*/
      kk_std_core_types__list _match_x455 = kk_std_core_vector_vlist(v_10011_0, kk_std_core_types__new_None(_ctx), _ctx); /*list<10000>*/;
      if (kk_std_core_types__is_Cons(_match_x455, _ctx)) {
        struct kk_std_core_types_Cons* _con_x559 = kk_std_core_types__as_Cons(_match_x455, _ctx);
        kk_box_t _box_x23 = _con_x559->head;
        kk_std_core_types__list _pat_4 = _con_x559->tail;
        kk_string_t id = kk_string_unbox(_box_x23);
        if kk_likely(kk_datatype_ptr_is_unique(_match_x455, _ctx)) {
          kk_std_core_types__list_drop(_pat_4, _ctx);
          kk_datatype_ptr_free(_match_x455, _ctx);
        }
        else {
          kk_string_dup(id, _ctx);
          kk_datatype_ptr_decref(_match_x455, _ctx);
        }
        return id;
      }
      {
        kk_define_string_literal(, _s_x560, 7, "unknown", _ctx)
        return kk_string_dup(_s_x560, _ctx);
      }
    }
  }
  {
    kk_std_core_types__list_drop(parts, _ctx);
    kk_define_string_literal(, _s_x561, 7, "unknown", _ctx)
    return kk_string_dup(_s_x561, _ctx);
  }
}

kk_string_t kk_whitemagic_dash_koka_src_unified__runtime__v3_json_state(kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state s, kk_context_t* _ctx) { /* (s : unified-state) -> string */ 
  kk_string_t _x_x562;
  kk_define_string_literal(, _s_x563, 10, "{\"events\":", _ctx)
  _x_x562 = kk_string_dup(_s_x563, _ctx); /*string*/
  kk_string_t _x_x564;
  kk_string_t _x_x565;
  kk_integer_t _x_x566;
  kk_std_core_types__list _x_x567;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x568 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(s, _ctx);
    kk_std_core_types__list _x = _con_x568->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x567 = _x; /*list<gan_ying/resonance-event>*/
  }
  _x_x566 = kk_std_core_list__lift_length_5730(_x_x567, kk_integer_from_small(0), _ctx); /*int*/
  _x_x565 = kk_std_core_int_show(_x_x566, _ctx); /*string*/
  kk_string_t _x_x569;
  kk_string_t _x_x570;
  kk_define_string_literal(, _s_x571, 12, ",\"profiles\":", _ctx)
  _x_x570 = kk_string_dup(_s_x571, _ctx); /*string*/
  kk_string_t _x_x572;
  kk_string_t _x_x573;
  kk_integer_t _x_x574;
  kk_std_core_types__list _x_x575;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x576 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(s, _ctx);
    kk_std_core_types__list _x_0 = _con_x576->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x575 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x574 = kk_std_core_list__lift_length_5730(_x_x575, kk_integer_from_small(0), _ctx); /*int*/
  _x_x573 = kk_std_core_int_show(_x_x574, _ctx); /*string*/
  kk_string_t _x_x577;
  kk_string_t _x_x578;
  kk_define_string_literal(, _s_x579, 13, ",\"total_ops\":", _ctx)
  _x_x578 = kk_string_dup(_s_x579, _ctx); /*string*/
  kk_string_t _x_x580;
  kk_string_t _x_x581;
  kk_integer_t _x_x582;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x583 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(s, _ctx);
    kk_integer_t _x_1 = _con_x583->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x582 = _x_1; /*int*/
  }
  _x_x581 = kk_std_core_int_show(_x_x582, _ctx); /*string*/
  kk_string_t _x_x584;
  kk_string_t _x_x585;
  kk_define_string_literal(, _s_x586, 11, ",\"batches\":", _ctx)
  _x_x585 = kk_string_dup(_s_x586, _ctx); /*string*/
  kk_string_t _x_x587;
  kk_string_t _x_x588;
  kk_integer_t _x_x589;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x590 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(s, _ctx);
    kk_integer_t _x_2 = _con_x590->batch_count;
    kk_integer_dup(_x_2, _ctx);
    _x_x589 = _x_2; /*int*/
  }
  _x_x588 = kk_std_core_int_show(_x_x589, _ctx); /*string*/
  kk_string_t _x_x591;
  kk_string_t _x_x592;
  kk_define_string_literal(, _s_x593, 17, ",\"session_start\":", _ctx)
  _x_x592 = kk_string_dup(_s_x593, _ctx); /*string*/
  kk_string_t _x_x594;
  kk_string_t _x_x595;
  double _x_x596;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x597 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(s, _ctx);
    kk_std_core_types__list _pat_0_3 = _con_x597->events;
    kk_std_core_types__list _pat_1_3 = _con_x597->profiles;
    kk_integer_t _pat_2_3 = _con_x597->total_ops;
    kk_integer_t _pat_3_3 = _con_x597->batch_count;
    double _x_3 = _con_x597->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(s, _ctx)) {
      kk_integer_drop(_pat_3_3, _ctx);
      kk_integer_drop(_pat_2_3, _ctx);
      kk_std_core_types__list_drop(_pat_1_3, _ctx);
      kk_std_core_types__list_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(s, _ctx);
    }
    else {
      kk_datatype_ptr_decref(s, _ctx);
    }
    _x_x596 = _x_3; /*float64*/
  }
  _x_x595 = kk_std_num_float64_show(_x_x596, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x598;
  kk_define_string_literal(, _s_x599, 1, "}", _ctx)
  _x_x598 = kk_string_dup(_s_x599, _ctx); /*string*/
  _x_x594 = kk_std_core_types__lp__plus__plus__rp_(_x_x595, _x_x598, _ctx); /*string*/
  _x_x591 = kk_std_core_types__lp__plus__plus__rp_(_x_x592, _x_x594, _ctx); /*string*/
  _x_x587 = kk_std_core_types__lp__plus__plus__rp_(_x_x588, _x_x591, _ctx); /*string*/
  _x_x584 = kk_std_core_types__lp__plus__plus__rp_(_x_x585, _x_x587, _ctx); /*string*/
  _x_x580 = kk_std_core_types__lp__plus__plus__rp_(_x_x581, _x_x584, _ctx); /*string*/
  _x_x577 = kk_std_core_types__lp__plus__plus__rp_(_x_x578, _x_x580, _ctx); /*string*/
  _x_x572 = kk_std_core_types__lp__plus__plus__rp_(_x_x573, _x_x577, _ctx); /*string*/
  _x_x569 = kk_std_core_types__lp__plus__plus__rp_(_x_x570, _x_x572, _ctx); /*string*/
  _x_x564 = kk_std_core_types__lp__plus__plus__rp_(_x_x565, _x_x569, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x562, _x_x564, _ctx);
}
 
// Execute single command

kk_string_t kk_whitemagic_dash_koka_src_unified__runtime__v3_execute_cmd(kk_string_t op, kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state, kk_context_t* _ctx) { /* (op : string, state : unified-state) -> string */ 
  if (kk_string_cmp_cstr_borrow(op, "ping", _ctx) == 0) {
    kk_datatype_ptr_dropn(state, (KK_I32(4)), _ctx);
    kk_string_drop(op, _ctx);
    kk_define_string_literal(, _s_x600, 13, "{\"pong\":true}", _ctx)
    return kk_string_dup(_s_x600, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(op, "status", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    return kk_whitemagic_dash_koka_src_unified__runtime__v3_json_state(state, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(op, "emit", _ctx) == 0) {
    kk_datatype_ptr_dropn(state, (KK_I32(4)), _ctx);
    kk_string_drop(op, _ctx);
    kk_define_string_literal(, _s_x601, 16, "{\"emitted\":true}", _ctx)
    return kk_string_dup(_s_x601, _ctx);
  }
  if (kk_string_cmp_cstr_borrow(op, "count", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_string_t _x_x602;
    kk_define_string_literal(, _s_x603, 9, "{\"count\":", _ctx)
    _x_x602 = kk_string_dup(_s_x603, _ctx); /*string*/
    kk_string_t _x_x604;
    kk_string_t _x_x605;
    kk_integer_t _x_x606;
    kk_std_core_types__list _x_x607;
    {
      struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x608 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state, _ctx);
      kk_std_core_types__list _x = _con_x608->events;
      kk_std_core_types__list _pat_0_0 = _con_x608->profiles;
      kk_integer_t _pat_1_0 = _con_x608->total_ops;
      kk_integer_t _pat_2_0 = _con_x608->batch_count;
      if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
        kk_integer_drop(_pat_2_0, _ctx);
        kk_integer_drop(_pat_1_0, _ctx);
        kk_std_core_types__list_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(state, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x, _ctx);
        kk_datatype_ptr_decref(state, _ctx);
      }
      _x_x607 = _x; /*list<gan_ying/resonance-event>*/
    }
    _x_x606 = kk_std_core_list__lift_length_5730(_x_x607, kk_integer_from_small(0), _ctx); /*int*/
    _x_x605 = kk_std_core_int_show(_x_x606, _ctx); /*string*/
    kk_string_t _x_x609;
    kk_define_string_literal(, _s_x610, 1, "}", _ctx)
    _x_x609 = kk_string_dup(_s_x610, _ctx); /*string*/
    _x_x604 = kk_std_core_types__lp__plus__plus__rp_(_x_x605, _x_x609, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x602, _x_x604, _ctx);
  }
  {
    kk_datatype_ptr_dropn(state, (KK_I32(4)), _ctx);
    kk_string_drop(op, _ctx);
    kk_define_string_literal(, _s_x611, 19, "{\"error\":\"unknown\"}", _ctx)
    return kk_string_dup(_s_x611, _ctx);
  }
}
 
// Extract command operation from a specific command string

kk_string_t kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_cmd_op(kk_string_t cmd_str, kk_context_t* _ctx) { /* (cmd-str : string) -> string */ 
  bool _match_x451;
  kk_string_t _x_x612 = kk_string_dup(cmd_str, _ctx); /*string*/
  kk_string_t _x_x613;
  kk_define_string_literal(, _s_x614, 11, "\"op\":\"ping\"", _ctx)
  _x_x613 = kk_string_dup(_s_x614, _ctx); /*string*/
  _match_x451 = kk_string_contains(_x_x612,_x_x613,kk_context()); /*bool*/
  if (_match_x451) {
    kk_string_drop(cmd_str, _ctx);
    kk_define_string_literal(, _s_x615, 4, "ping", _ctx)
    return kk_string_dup(_s_x615, _ctx);
  }
  {
    bool _match_x452;
    kk_string_t _x_x616 = kk_string_dup(cmd_str, _ctx); /*string*/
    kk_string_t _x_x617;
    kk_define_string_literal(, _s_x618, 11, "\"op\":\"emit\"", _ctx)
    _x_x617 = kk_string_dup(_s_x618, _ctx); /*string*/
    _match_x452 = kk_string_contains(_x_x616,_x_x617,kk_context()); /*bool*/
    if (_match_x452) {
      kk_string_drop(cmd_str, _ctx);
      kk_define_string_literal(, _s_x619, 4, "emit", _ctx)
      return kk_string_dup(_s_x619, _ctx);
    }
    {
      bool _match_x453;
      kk_string_t _x_x620 = kk_string_dup(cmd_str, _ctx); /*string*/
      kk_string_t _x_x621;
      kk_define_string_literal(, _s_x622, 13, "\"op\":\"status\"", _ctx)
      _x_x621 = kk_string_dup(_s_x622, _ctx); /*string*/
      _match_x453 = kk_string_contains(_x_x620,_x_x621,kk_context()); /*bool*/
      if (_match_x453) {
        kk_string_drop(cmd_str, _ctx);
        kk_define_string_literal(, _s_x623, 6, "status", _ctx)
        return kk_string_dup(_s_x623, _ctx);
      }
      {
        bool _match_x454;
        kk_string_t _x_x624;
        kk_define_string_literal(, _s_x625, 12, "\"op\":\"count\"", _ctx)
        _x_x624 = kk_string_dup(_s_x625, _ctx); /*string*/
        _match_x454 = kk_string_contains(cmd_str,_x_x624,kk_context()); /*bool*/
        if (_match_x454) {
          kk_define_string_literal(, _s_x626, 5, "count", _ctx)
          return kk_string_dup(_s_x626, _ctx);
        }
        {
          kk_define_string_literal(, _s_x627, 7, "unknown", _ctx)
          return kk_string_dup(_s_x627, _ctx);
        }
      }
    }
  }
}
 
// Extract command ID

kk_string_t kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_cmd_id(kk_string_t cmd_str, kk_context_t* _ctx) { /* (cmd-str : string) -> string */ 
  kk_vector_t v_10011;
  kk_string_t _x_x628;
  kk_define_string_literal(, _s_x629, 5, "\"id\":", _ctx)
  _x_x628 = kk_string_dup(_s_x629, _ctx); /*string*/
  v_10011 = kk_string_splitv(cmd_str,_x_x628,kk_context()); /*vector<string>*/
  kk_std_core_types__list parts = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  if (kk_std_core_types__is_Cons(parts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x630 = kk_std_core_types__as_Cons(parts, _ctx);
    kk_box_t _box_x24 = _con_x630->head;
    kk_std_core_types__list _pat_1 = _con_x630->tail;
    if (kk_std_core_types__is_Cons(_pat_1, _ctx)) {
      struct kk_std_core_types_Cons* _con_x631 = kk_std_core_types__as_Cons(_pat_1, _ctx);
      kk_box_t _box_x25 = _con_x631->head;
      kk_string_t _pat_0 = kk_string_unbox(_box_x24);
      kk_std_core_types__list _pat_2 = _con_x631->tail;
      kk_string_t rest = kk_string_unbox(_box_x25);
      if kk_likely(kk_datatype_ptr_is_unique(parts, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_1, _ctx)) {
          kk_std_core_types__list_drop(_pat_2, _ctx);
          kk_datatype_ptr_free(_pat_1, _ctx);
        }
        else {
          kk_string_dup(rest, _ctx);
          kk_datatype_ptr_decref(_pat_1, _ctx);
        }
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(parts, _ctx);
      }
      else {
        kk_string_dup(rest, _ctx);
        kk_datatype_ptr_decref(parts, _ctx);
      }
      kk_vector_t v_10011_0;
      kk_string_t _x_x632;
      kk_define_string_literal(, _s_x633, 1, ",", _ctx)
      _x_x632 = kk_string_dup(_s_x633, _ctx); /*string*/
      v_10011_0 = kk_string_splitv(rest,_x_x632,kk_context()); /*vector<string>*/
      kk_std_core_types__list _match_x450 = kk_std_core_vector_vlist(v_10011_0, kk_std_core_types__new_None(_ctx), _ctx); /*list<10000>*/;
      if (kk_std_core_types__is_Cons(_match_x450, _ctx)) {
        struct kk_std_core_types_Cons* _con_x634 = kk_std_core_types__as_Cons(_match_x450, _ctx);
        kk_box_t _box_x26 = _con_x634->head;
        kk_std_core_types__list _pat_4 = _con_x634->tail;
        kk_string_t id = kk_string_unbox(_box_x26);
        if kk_likely(kk_datatype_ptr_is_unique(_match_x450, _ctx)) {
          kk_std_core_types__list_drop(_pat_4, _ctx);
          kk_datatype_ptr_free(_match_x450, _ctx);
        }
        else {
          kk_string_dup(id, _ctx);
          kk_datatype_ptr_decref(_match_x450, _ctx);
        }
        return id;
      }
      {
        kk_define_string_literal(, _s_x635, 1, "0", _ctx)
        return kk_string_dup(_s_x635, _ctx);
      }
    }
  }
  {
    kk_std_core_types__list_drop(parts, _ctx);
    kk_define_string_literal(, _s_x636, 1, "0", _ctx)
    return kk_string_dup(_s_x636, _ctx);
  }
}
 
// Process a list of command strings

kk_string_t kk_whitemagic_dash_koka_src_unified__runtime__v3_process_commands(kk_std_core_types__list cmds, kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state, kk_context_t* _ctx) { /* (cmds : list<string>, state : unified-state) -> string */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(cmds, _ctx)) {
    kk_datatype_ptr_dropn(state, (KK_I32(4)), _ctx);
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x638 = kk_std_core_types__as_Cons(cmds, _ctx);
    kk_box_t _box_x27 = _con_x638->head;
    kk_std_core_types__list rest = _con_x638->tail;
    kk_string_t c = kk_string_unbox(_box_x27);
    if kk_likely(kk_datatype_ptr_is_unique(cmds, _ctx)) {
      kk_datatype_ptr_free(cmds, _ctx);
    }
    else {
      kk_string_dup(c, _ctx);
      kk_std_core_types__list_dup(rest, _ctx);
      kk_datatype_ptr_decref(cmds, _ctx);
    }
    bool _match_x448;
    kk_string_t _x_x639;
    kk_string_t _x_x640;
    kk_string_t _x_x641 = kk_string_dup(c, _ctx); /*string*/
    _x_x640 = kk_string_trim_left(_x_x641,kk_context()); /*string*/
    _x_x639 = kk_string_trim_right(_x_x640,kk_context()); /*string*/
    kk_string_t _x_x642 = kk_string_empty(); /*string*/
    _match_x448 = kk_string_is_eq(_x_x639,_x_x642,kk_context()); /*bool*/
    if (_match_x448) {
      kk_string_drop(c, _ctx);
      { // tailcall
        cmds = rest;
        goto kk__tailcall;
      }
    }
    {
      kk_string_t id;
      kk_string_t _x_x644 = kk_string_dup(c, _ctx); /*string*/
      id = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_cmd_id(_x_x644, _ctx); /*string*/
      kk_string_t op = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_cmd_op(c, _ctx); /*string*/;
      kk_string_t result;
      kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x645 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
      result = kk_whitemagic_dash_koka_src_unified__runtime__v3_execute_cmd(op, _x_x645, _ctx); /*string*/
      kk_string_t response;
      kk_string_t _x_x646;
      kk_define_string_literal(, _s_x647, 6, "{\"id\":", _ctx)
      _x_x646 = kk_string_dup(_s_x647, _ctx); /*string*/
      kk_string_t _x_x648;
      kk_string_t _x_x649;
      kk_string_t _x_x650;
      kk_define_string_literal(, _s_x651, 24, ",\"status\":\"ok\",\"result\":", _ctx)
      _x_x650 = kk_string_dup(_s_x651, _ctx); /*string*/
      kk_string_t _x_x652;
      kk_string_t _x_x653;
      kk_define_string_literal(, _s_x654, 1, "}", _ctx)
      _x_x653 = kk_string_dup(_s_x654, _ctx); /*string*/
      _x_x652 = kk_std_core_types__lp__plus__plus__rp_(result, _x_x653, _ctx); /*string*/
      _x_x649 = kk_std_core_types__lp__plus__plus__rp_(_x_x650, _x_x652, _ctx); /*string*/
      _x_x648 = kk_std_core_types__lp__plus__plus__rp_(id, _x_x649, _ctx); /*string*/
      response = kk_std_core_types__lp__plus__plus__rp_(_x_x646, _x_x648, _ctx); /*string*/
      kk_string_t rest_resp = kk_whitemagic_dash_koka_src_unified__runtime__v3_process_commands(rest, state, _ctx); /*string*/;
      bool _match_x449;
      kk_string_t _x_x655 = kk_string_dup(rest_resp, _ctx); /*string*/
      kk_string_t _x_x656 = kk_string_empty(); /*string*/
      _match_x449 = kk_string_is_eq(_x_x655,_x_x656,kk_context()); /*bool*/
      if (_match_x449) {
        kk_string_drop(rest_resp, _ctx);
        return response;
      }
      {
        kk_string_t _x_x658;
        kk_string_t _x_x659;
        kk_define_string_literal(, _s_x660, 1, ",", _ctx)
        _x_x659 = kk_string_dup(_s_x660, _ctx); /*string*/
        _x_x658 = kk_std_core_types__lp__plus__plus__rp_(_x_x659, rest_resp, _ctx); /*string*/
        return kk_std_core_types__lp__plus__plus__rp_(response, _x_x658, _ctx);
      }
    }
  }
}
 
// Generate a real batch response

kk_string_t kk_whitemagic_dash_koka_src_unified__runtime__v3_batch_response_real(kk_string_t line, kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state, kk_context_t* _ctx) { /* (line : string, state : unified-state) -> string */ 
  kk_string_t req_id;
  kk_string_t _x_x661 = kk_string_dup(line, _ctx); /*string*/
  req_id = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_request_id(_x_x661, _ctx); /*string*/
  kk_vector_t v_10011;
  kk_string_t _x_x662;
  kk_define_string_literal(, _s_x663, 1, "[", _ctx)
  _x_x662 = kk_string_dup(_s_x663, _ctx); /*string*/
  v_10011 = kk_string_splitv(line,_x_x662,kk_context()); /*vector<string>*/
  kk_std_core_types__list parts = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  if (kk_std_core_types__is_Cons(parts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x664 = kk_std_core_types__as_Cons(parts, _ctx);
    kk_box_t _box_x28 = _con_x664->head;
    kk_std_core_types__list _pat_1 = _con_x664->tail;
    if (kk_std_core_types__is_Cons(_pat_1, _ctx)) {
      struct kk_std_core_types_Cons* _con_x665 = kk_std_core_types__as_Cons(_pat_1, _ctx);
      kk_box_t _box_x29 = _con_x665->head;
      kk_string_t _pat_0 = kk_string_unbox(_box_x28);
      kk_std_core_types__list _pat_2 = _con_x665->tail;
      kk_string_t rest = kk_string_unbox(_box_x29);
      if kk_likely(kk_datatype_ptr_is_unique(parts, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_1, _ctx)) {
          kk_std_core_types__list_drop(_pat_2, _ctx);
          kk_datatype_ptr_free(_pat_1, _ctx);
        }
        else {
          kk_string_dup(rest, _ctx);
          kk_datatype_ptr_decref(_pat_1, _ctx);
        }
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(parts, _ctx);
      }
      else {
        kk_string_dup(rest, _ctx);
        kk_datatype_ptr_decref(parts, _ctx);
      }
      kk_vector_t v_10011_0;
      kk_string_t _x_x666;
      kk_define_string_literal(, _s_x667, 1, "]", _ctx)
      _x_x666 = kk_string_dup(_s_x667, _ctx); /*string*/
      v_10011_0 = kk_string_splitv(rest,_x_x666,kk_context()); /*vector<string>*/
      kk_std_core_types__list _match_x447 = kk_std_core_vector_vlist(v_10011_0, kk_std_core_types__new_None(_ctx), _ctx); /*list<10000>*/;
      if (kk_std_core_types__is_Cons(_match_x447, _ctx)) {
        struct kk_std_core_types_Cons* _con_x668 = kk_std_core_types__as_Cons(_match_x447, _ctx);
        kk_box_t _box_x30 = _con_x668->head;
        kk_std_core_types__list _pat_4 = _con_x668->tail;
        kk_string_t cmd_array_str = kk_string_unbox(_box_x30);
        if kk_likely(kk_datatype_ptr_is_unique(_match_x447, _ctx)) {
          kk_std_core_types__list_drop(_pat_4, _ctx);
          kk_datatype_ptr_free(_match_x447, _ctx);
        }
        else {
          kk_string_dup(cmd_array_str, _ctx);
          kk_datatype_ptr_decref(_match_x447, _ctx);
        }
        kk_vector_t v_10011_1;
        kk_string_t _x_x669;
        kk_define_string_literal(, _s_x670, 3, "},{", _ctx)
        _x_x669 = kk_string_dup(_s_x670, _ctx); /*string*/
        v_10011_1 = kk_string_splitv(cmd_array_str,_x_x669,kk_context()); /*vector<string>*/
        kk_std_core_types__list cmds = kk_std_core_vector_vlist(v_10011_1, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
        kk_string_t results;
        kk_std_core_types__list _x_x671 = kk_std_core_types__list_dup(cmds, _ctx); /*list<string>*/
        results = kk_whitemagic_dash_koka_src_unified__runtime__v3_process_commands(_x_x671, state, _ctx); /*string*/
        kk_string_t count;
        kk_integer_t _x_x672 = kk_std_core_list__lift_length_5730(cmds, kk_integer_from_small(0), _ctx); /*int*/
        count = kk_std_core_int_show(_x_x672, _ctx); /*string*/
        kk_string_t _x_x673;
        kk_define_string_literal(, _s_x674, 15, "{\"request_id\":\"", _ctx)
        _x_x673 = kk_string_dup(_s_x674, _ctx); /*string*/
        kk_string_t _x_x675;
        kk_string_t _x_x676;
        kk_string_t _x_x677;
        kk_define_string_literal(, _s_x678, 13, "\",\"results\":[", _ctx)
        _x_x677 = kk_string_dup(_s_x678, _ctx); /*string*/
        kk_string_t _x_x679;
        kk_string_t _x_x680;
        kk_string_t _x_x681;
        kk_define_string_literal(, _s_x682, 23, "],\"commands_processed\":", _ctx)
        _x_x681 = kk_string_dup(_s_x682, _ctx); /*string*/
        kk_string_t _x_x683;
        kk_string_t _x_x684;
        kk_define_string_literal(, _s_x685, 1, "}", _ctx)
        _x_x684 = kk_string_dup(_s_x685, _ctx); /*string*/
        _x_x683 = kk_std_core_types__lp__plus__plus__rp_(count, _x_x684, _ctx); /*string*/
        _x_x680 = kk_std_core_types__lp__plus__plus__rp_(_x_x681, _x_x683, _ctx); /*string*/
        _x_x679 = kk_std_core_types__lp__plus__plus__rp_(results, _x_x680, _ctx); /*string*/
        _x_x676 = kk_std_core_types__lp__plus__plus__rp_(_x_x677, _x_x679, _ctx); /*string*/
        _x_x675 = kk_std_core_types__lp__plus__plus__rp_(req_id, _x_x676, _ctx); /*string*/
        return kk_std_core_types__lp__plus__plus__rp_(_x_x673, _x_x675, _ctx);
      }
      {
        kk_datatype_ptr_dropn(state, (KK_I32(4)), _ctx);
        kk_string_t _x_x686;
        kk_define_string_literal(, _s_x687, 15, "{\"request_id\":\"", _ctx)
        _x_x686 = kk_string_dup(_s_x687, _ctx); /*string*/
        kk_string_t _x_x688;
        kk_string_t _x_x689;
        kk_define_string_literal(, _s_x690, 38, "\",\"results\":[],\"commands_processed\":0}", _ctx)
        _x_x689 = kk_string_dup(_s_x690, _ctx); /*string*/
        _x_x688 = kk_std_core_types__lp__plus__plus__rp_(req_id, _x_x689, _ctx); /*string*/
        return kk_std_core_types__lp__plus__plus__rp_(_x_x686, _x_x688, _ctx);
      }
    }
  }
  {
    kk_datatype_ptr_dropn(state, (KK_I32(4)), _ctx);
    kk_std_core_types__list_drop(parts, _ctx);
    kk_string_t _x_x691;
    kk_define_string_literal(, _s_x692, 15, "{\"request_id\":\"", _ctx)
    _x_x691 = kk_string_dup(_s_x692, _ctx); /*string*/
    kk_string_t _x_x693;
    kk_string_t _x_x694;
    kk_define_string_literal(, _s_x695, 38, "\",\"results\":[],\"commands_processed\":0}", _ctx)
    _x_x694 = kk_string_dup(_s_x695, _ctx); /*string*/
    _x_x693 = kk_std_core_types__lp__plus__plus__rp_(req_id, _x_x694, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x691, _x_x693, _ctx);
  }
}

kk_string_t kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x439;
  kk_string_t _x_x696 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x697;
  kk_define_string_literal(, _s_x698, 6, "\"ping\"", _ctx)
  _x_x697 = kk_string_dup(_s_x698, _ctx); /*string*/
  _match_x439 = kk_string_contains(_x_x696,_x_x697,kk_context()); /*bool*/
  if (_match_x439) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x699, 4, "ping", _ctx)
    return kk_string_dup(_s_x699, _ctx);
  }
  {
    bool _match_x440;
    kk_string_t _x_x700 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x701;
    kk_define_string_literal(, _s_x702, 6, "\"emit\"", _ctx)
    _x_x701 = kk_string_dup(_s_x702, _ctx); /*string*/
    _match_x440 = kk_string_contains(_x_x700,_x_x701,kk_context()); /*bool*/
    if (_match_x440) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x703, 4, "emit", _ctx)
      return kk_string_dup(_s_x703, _ctx);
    }
    {
      bool _match_x441;
      kk_string_t _x_x704 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x705;
      kk_define_string_literal(, _s_x706, 9, "\"cascade\"", _ctx)
      _x_x705 = kk_string_dup(_s_x706, _ctx); /*string*/
      _match_x441 = kk_string_contains(_x_x704,_x_x705,kk_context()); /*bool*/
      if (_match_x441) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x707, 7, "cascade", _ctx)
        return kk_string_dup(_s_x707, _ctx);
      }
      {
        bool _match_x442;
        kk_string_t _x_x708 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x709;
        kk_define_string_literal(, _s_x710, 9, "\"profile\"", _ctx)
        _x_x709 = kk_string_dup(_s_x710, _ctx); /*string*/
        _match_x442 = kk_string_contains(_x_x708,_x_x709,kk_context()); /*bool*/
        if (_match_x442) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x711, 7, "profile", _ctx)
          return kk_string_dup(_s_x711, _ctx);
        }
        {
          bool _match_x443;
          kk_string_t _x_x712 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x713;
          kk_define_string_literal(, _s_x714, 8, "\"status\"", _ctx)
          _x_x713 = kk_string_dup(_s_x714, _ctx); /*string*/
          _match_x443 = kk_string_contains(_x_x712,_x_x713,kk_context()); /*bool*/
          if (_match_x443) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x715, 6, "status", _ctx)
            return kk_string_dup(_s_x715, _ctx);
          }
          {
            bool _match_x444;
            kk_string_t _x_x716 = kk_string_dup(line, _ctx); /*string*/
            kk_string_t _x_x717;
            kk_define_string_literal(, _s_x718, 5, "\"hot\"", _ctx)
            _x_x717 = kk_string_dup(_s_x718, _ctx); /*string*/
            _match_x444 = kk_string_contains(_x_x716,_x_x717,kk_context()); /*bool*/
            if (_match_x444) {
              kk_string_drop(line, _ctx);
              kk_define_string_literal(, _s_x719, 3, "hot", _ctx)
              return kk_string_dup(_s_x719, _ctx);
            }
            {
              bool _match_x445;
              kk_string_t _x_x720 = kk_string_dup(line, _ctx); /*string*/
              kk_string_t _x_x721;
              kk_define_string_literal(, _s_x722, 7, "\"count\"", _ctx)
              _x_x721 = kk_string_dup(_s_x722, _ctx); /*string*/
              _match_x445 = kk_string_contains(_x_x720,_x_x721,kk_context()); /*bool*/
              if (_match_x445) {
                kk_string_drop(line, _ctx);
                kk_define_string_literal(, _s_x723, 5, "count", _ctx)
                return kk_string_dup(_s_x723, _ctx);
              }
              {
                bool _match_x446;
                kk_string_t _x_x724;
                kk_define_string_literal(, _s_x725, 6, "\"quit\"", _ctx)
                _x_x724 = kk_string_dup(_s_x725, _ctx); /*string*/
                _match_x446 = kk_string_contains(line,_x_x724,kk_context()); /*bool*/
                if (_match_x446) {
                  kk_define_string_literal(, _s_x726, 4, "quit", _ctx)
                  return kk_string_dup(_s_x726, _ctx);
                }
                {
                  kk_define_string_literal(, _s_x727, 7, "unknown", _ctx)
                  return kk_string_dup(_s_x727, _ctx);
                }
              }
            }
          }
        }
      }
    }
  }
}

kk_gan__ying__event_type kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_event_type(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> gan_ying/event-type */ 
  bool _match_x435;
  kk_string_t _x_x728 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x729;
  kk_define_string_literal(, _s_x730, 14, "memory_created", _ctx)
  _x_x729 = kk_string_dup(_s_x730, _ctx); /*string*/
  _match_x435 = kk_string_contains(_x_x728,_x_x729,kk_context()); /*bool*/
  if (_match_x435) {
    kk_string_drop(line, _ctx);
    return kk_gan__ying__new_MemoryCreated(_ctx);
  }
  {
    bool _match_x436;
    kk_string_t _x_x731 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x732;
    kk_define_string_literal(, _s_x733, 14, "memory_updated", _ctx)
    _x_x732 = kk_string_dup(_s_x733, _ctx); /*string*/
    _match_x436 = kk_string_contains(_x_x731,_x_x732,kk_context()); /*bool*/
    if (_match_x436) {
      kk_string_drop(line, _ctx);
      return kk_gan__ying__new_MemoryUpdated(_ctx);
    }
    {
      bool _match_x437;
      kk_string_t _x_x734 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x735;
      kk_define_string_literal(, _s_x736, 15, "threat_detected", _ctx)
      _x_x735 = kk_string_dup(_s_x736, _ctx); /*string*/
      _match_x437 = kk_string_contains(_x_x734,_x_x735,kk_context()); /*bool*/
      if (_match_x437) {
        kk_string_drop(line, _ctx);
        return kk_gan__ying__new_ThreatDetected(_ctx);
      }
      {
        bool _match_x438;
        kk_string_t _x_x737;
        kk_define_string_literal(, _s_x738, 10, "flow_state", _ctx)
        _x_x737 = kk_string_dup(_s_x738, _ctx); /*string*/
        _match_x438 = kk_string_contains(line,_x_x737,kk_context()); /*bool*/
        if (_match_x438) {
          return kk_gan__ying__new_FlowStateEntered(_ctx);
        }
        {
          return kk_gan__ying__new_SystemStarted(_ctx);
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun743__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun743(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun743(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun743, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun743(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x744;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _match_x434 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x33, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x745 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_match_x434, _ctx);
    kk_std_core_types__list _pat_0_3_0 = _con_x745->events;
    kk_std_core_types__list _pat_1_3_0 = _con_x745->profiles;
    kk_integer_t _pat_2_3_0 = _con_x745->total_ops;
    kk_integer_t _x_2_0 = _con_x745->batch_count;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x434, _ctx)) {
      kk_integer_drop(_pat_2_3_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_3_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_3_0, _ctx);
      kk_datatype_ptr_free(_match_x434, _ctx);
    }
    else {
      kk_integer_dup(_x_2_0, _ctx);
      kk_datatype_ptr_decref(_match_x434, _ctx);
    }
    _x_x744 = _x_2_0; /*int*/
  }
  return kk_integer_box(_x_x744, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun750__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun750(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun750(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun750, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun750(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x751;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _match_x433 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x39, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x752 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_match_x433, _ctx);
    kk_std_core_types__list _x_4 = _con_x752->events;
    kk_std_core_types__list _pat_0_0_1 = _con_x752->profiles;
    kk_integer_t _pat_1_0_1 = _con_x752->total_ops;
    kk_integer_t _pat_2_0_1 = _con_x752->batch_count;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x433, _ctx)) {
      kk_integer_drop(_pat_2_0_1, _ctx);
      kk_integer_drop(_pat_1_0_1, _ctx);
      kk_std_core_types__list_drop(_pat_0_0_1, _ctx);
      kk_datatype_ptr_free(_match_x433, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_4, _ctx);
      kk_datatype_ptr_decref(_match_x433, _ctx);
    }
    _x_x751 = _x_4; /*list<gan_ying/resonance-event>*/
  }
  return kk_std_core_types__list_box(_x_x751, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun757__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun757(kk_function_t _fself, kk_box_t _b_x42, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun757(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun757, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun757(kk_function_t _fself, kk_box_t _b_x42, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x758;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _match_x432 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x42, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x759 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_match_x432, _ctx);
    kk_std_core_types__list _pat_0_1_0 = _con_x759->events;
    kk_std_core_types__list _x_0_0 = _con_x759->profiles;
    kk_integer_t _pat_1_1_0 = _con_x759->total_ops;
    kk_integer_t _pat_2_1_0 = _con_x759->batch_count;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x432, _ctx)) {
      kk_integer_drop(_pat_2_1_0, _ctx);
      kk_integer_drop(_pat_1_1_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_1_0, _ctx);
      kk_datatype_ptr_free(_match_x432, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_0_0, _ctx);
      kk_datatype_ptr_decref(_match_x432, _ctx);
    }
    _x_x758 = _x_0_0; /*list<hot_paths/path-profile>*/
  }
  return kk_std_core_types__list_box(_x_x758, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun764__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun764(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun764(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun764, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun764(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x765;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _match_x431 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x45, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x766 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_match_x431, _ctx);
    kk_std_core_types__list _pat_0_2_0 = _con_x766->events;
    kk_std_core_types__list _pat_1_2_0 = _con_x766->profiles;
    kk_integer_t _x_1_0 = _con_x766->total_ops;
    kk_integer_t _pat_2_2_0 = _con_x766->batch_count;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x431, _ctx)) {
      kk_integer_drop(_pat_2_2_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_2_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_2_0, _ctx);
      kk_datatype_ptr_free(_match_x431, _ctx);
    }
    else {
      kk_integer_dup(_x_1_0, _ctx);
      kk_datatype_ptr_decref(_match_x431, _ctx);
    }
    _x_x765 = _x_1_0; /*int*/
  }
  return kk_integer_box(_x_x765, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun772__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun772(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun772(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun772, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun772(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x773;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _match_x430 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x48, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x774 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_match_x430, _ctx);
    kk_std_core_types__list _pat_0_4 = _con_x774->events;
    kk_std_core_types__list _pat_1_4 = _con_x774->profiles;
    kk_integer_t _pat_2_4 = _con_x774->total_ops;
    kk_integer_t _pat_3_4 = _con_x774->batch_count;
    double _x_3_0 = _con_x774->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x430, _ctx)) {
      kk_integer_drop(_pat_3_4, _ctx);
      kk_integer_drop(_pat_2_4, _ctx);
      kk_std_core_types__list_drop(_pat_1_4, _ctx);
      kk_std_core_types__list_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(_match_x430, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x430, _ctx);
    }
    _x_x773 = _x_3_0; /*float64*/
  }
  return kk_double_box(_x_x773, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun776__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun776(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun776(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun776, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun776(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x777;
  kk_string_t _x_x778 = kk_string_unbox(_b_x51); /*string*/
  _x_x777 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_op(_x_x778, _ctx); /*string*/
  return kk_string_box(_x_x777);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun783__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun783(kk_function_t _fself, kk_box_t _b_x56, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun783(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun783, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun783(kk_function_t _fself, kk_box_t _b_x56, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x784;
  kk_string_t _x_x785 = kk_string_unbox(_b_x56); /*string*/
  _x_x784 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_event_type(_x_x785, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x784, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun787__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun787(kk_function_t _fself, kk_box_t _b_x67, kk_box_t _b_x68, kk_box_t _b_x69, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun787(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun787, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun787(kk_function_t _fself, kk_box_t _b_x67, kk_box_t _b_x68, kk_box_t _b_x69, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_1_103 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x69, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  kk_hot__paths__path_profile profile_0;
  kk_string_t _x_x788;
  kk_gan__ying__event_type _x_x789;
  kk_box_t _x_x790 = kk_box_dup(_b_x67, _ctx); /*10000*/
  _x_x789 = kk_gan__ying__event_type_unbox(_x_x790, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x788 = kk_gan__ying_event_type_to_string(_x_x789, _ctx); /*string*/
  profile_0 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x788, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x791;
  kk_std_core_types__list _x_x792;
  kk_box_t _x_x793;
  kk_gan__ying__resonance_event _x_x794;
  kk_string_t _x_x795 = kk_string_unbox(_b_x68); /*string*/
  kk_gan__ying__event_type _x_x796 = kk_gan__ying__event_type_unbox(_b_x67, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_string_t _x_x797 = kk_string_empty(); /*string*/
  _x_x794 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x795, _x_x796, _x_x797, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x793 = kk_gan__ying__resonance_event_box(_x_x794, _ctx); /*10021*/
  kk_std_core_types__list _x_x799;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x800 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_1_103, _ctx);
    kk_std_core_types__list _x_5 = _con_x800->events;
    kk_std_core_types__list_dup(_x_5, _ctx);
    _x_x799 = _x_5; /*list<gan_ying/resonance-event>*/
  }
  _x_x792 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x793, _x_x799, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x801;
  kk_std_core_types__list _x_x802;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x803 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_1_103, _ctx);
    kk_std_core_types__list _x_0_1 = _con_x803->profiles;
    kk_std_core_types__list_dup(_x_0_1, _ctx);
    _x_x802 = _x_0_1; /*list<hot_paths/path-profile>*/
  }
  _x_x801 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_0, _ctx), _x_x802, _ctx); /*list<10021>*/
  kk_integer_t _x_x804;
  kk_integer_t _x_x805;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x806 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_1_103, _ctx);
    kk_integer_t _x_1_1 = _con_x806->total_ops;
    kk_integer_dup(_x_1_1, _ctx);
    _x_x805 = _x_1_1; /*int*/
  }
  _x_x804 = kk_integer_add_small_const(_x_x805, 1, _ctx); /*int*/
  kk_integer_t _x_x807;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x808 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_1_103, _ctx);
    kk_integer_t _x_2_1 = _con_x808->batch_count;
    kk_integer_dup(_x_2_1, _ctx);
    _x_x807 = _x_2_1; /*int*/
  }
  double _x_x809;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x810 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_1_103, _ctx);
    kk_std_core_types__list _pat_0_3_1 = _con_x810->events;
    kk_std_core_types__list _pat_1_3_1 = _con_x810->profiles;
    kk_integer_t _pat_2_3_1 = _con_x810->total_ops;
    kk_integer_t _pat_3_3_1 = _con_x810->batch_count;
    double _x_3_1 = _con_x810->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state_1_103, _ctx)) {
      kk_integer_drop(_pat_3_3_1, _ctx);
      kk_integer_drop(_pat_2_3_1, _ctx);
      kk_std_core_types__list_drop(_pat_1_3_1, _ctx);
      kk_std_core_types__list_drop(_pat_0_3_1, _ctx);
      kk_datatype_ptr_free(state_1_103, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state_1_103, _ctx);
    }
    _x_x809 = _x_3_1; /*float64*/
  }
  _x_x791 = kk_whitemagic_dash_koka_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x792, _x_x801, _x_x804, _x_x807, _x_x809, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  return kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x791, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun815__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun815(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun815(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun815, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun815(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x816;
  kk_string_t _x_x817 = kk_string_unbox(_b_x72); /*string*/
  _x_x816 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_event_type(_x_x817, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x816, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun819__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun819(kk_function_t _fself, kk_box_t _b_x78, kk_box_t _b_x79, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun819(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun819, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun819(kk_function_t _fself, kk_box_t _b_x78, kk_box_t _b_x79, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x820;
  kk_gan__ying__event_type _x_x821 = kk_gan__ying__event_type_unbox(_b_x78, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x822 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x79, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x820 = kk_whitemagic_dash_koka_src_unified__runtime__v3_cascade_profiled(_x_x821, _x_x822, _ctx); /*(int, whitemagic-koka/src/unified_runtime_v3/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x820, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun825__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun825(kk_function_t _fself, kk_box_t _b_x109, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun825(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun825, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113_fun825(kk_function_t _fself, kk_box_t _b_x109, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x826 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x827 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x109, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop(_x_x827, _ctx);
  return kk_unit_box(_x_x826);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113(kk_string_t line, kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state, kk_string_t _c_x10047, kk_context_t* _ctx) { /* (line : string, state : unified-state, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10047, _ctx);
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state x_10115;
  bool _match_x428;
  kk_string_t _x_x739 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x740;
  kk_define_string_literal(, _s_x741, 11, "\"commands\":", _ctx)
  _x_x740 = kk_string_dup(_s_x741, _ctx); /*string*/
  _match_x428 = kk_string_contains(_x_x739,_x_x740,kk_context()); /*bool*/
  if (_match_x428) {
    kk_string_drop(line, _ctx);
    kk_integer_t x_10071;
    kk_box_t _x_x742;
    kk_box_t _x_x746;
    kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x747 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
    _x_x746 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x747, _ctx); /*10000*/
    _x_x742 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun743(_ctx), _x_x746, _ctx); /*10001*/
    x_10071 = kk_integer_unbox(_x_x742, _ctx); /*int*/
    kk_std_core_types__list _x_x748;
    kk_box_t _x_x749;
    kk_box_t _x_x753;
    kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x754 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
    _x_x753 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x754, _ctx); /*10000*/
    _x_x749 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun750(_ctx), _x_x753, _ctx); /*10001*/
    _x_x748 = kk_std_core_types__list_unbox(_x_x749, KK_OWNED, _ctx); /*list<gan_ying/resonance-event>*/
    kk_std_core_types__list _x_x755;
    kk_box_t _x_x756;
    kk_box_t _x_x760;
    kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x761 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
    _x_x760 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x761, _ctx); /*10000*/
    _x_x756 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun757(_ctx), _x_x760, _ctx); /*10001*/
    _x_x755 = kk_std_core_types__list_unbox(_x_x756, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
    kk_integer_t _x_x762;
    kk_box_t _x_x763;
    kk_box_t _x_x767;
    kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x768 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
    _x_x767 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x768, _ctx); /*10000*/
    _x_x763 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun764(_ctx), _x_x767, _ctx); /*10001*/
    _x_x762 = kk_integer_unbox(_x_x763, _ctx); /*int*/
    kk_integer_t _x_x769 = kk_integer_add_small_const(x_10071, 1, _ctx); /*int*/
    double _x_x770;
    kk_box_t _x_x771 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun772(_ctx), kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(state, _ctx), _ctx); /*10001*/
    _x_x770 = kk_double_unbox(_x_x771, KK_OWNED, _ctx); /*float64*/
    x_10115 = kk_whitemagic_dash_koka_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x748, _x_x755, _x_x762, _x_x769, _x_x770, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  }
  else {
    kk_string_t op_0;
    kk_box_t _x_x775;
    kk_box_t _x_x779;
    kk_string_t _x_x780 = kk_string_dup(line, _ctx); /*string*/
    _x_x779 = kk_string_box(_x_x780); /*10000*/
    _x_x775 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun776(_ctx), _x_x779, _ctx); /*10001*/
    op_0 = kk_string_unbox(_x_x775); /*string*/
    if (kk_string_cmp_cstr_borrow(op_0, "emit", _ctx) == 0) {
      kk_string_drop(op_0, _ctx);
      kk_gan__ying__event_type et_1;
      kk_box_t _x_x782 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun783(_ctx), kk_string_box(line), _ctx); /*10001*/
      et_1 = kk_gan__ying__event_type_unbox(_x_x782, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_box_t _x_x786;
      kk_box_t _x_x811;
      kk_string_t _x_x812;
      kk_define_string_literal(, _s_x813, 18, "unified_runtime_v3", _ctx)
      _x_x812 = kk_string_dup(_s_x813, _ctx); /*string*/
      _x_x811 = kk_string_box(_x_x812); /*10001*/
      _x_x786 = kk_std_core_hnd__open_none3(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun787(_ctx), kk_gan__ying__event_type_box(et_1, _ctx), _x_x811, kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(state, _ctx), _ctx); /*10003*/
      x_10115 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_x_x786, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
      goto _match_x781;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "cascade", _ctx) == 0) {
      kk_string_drop(op_0, _ctx);
      kk_gan__ying__event_type et_2_0;
      kk_box_t _x_x814 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun815(_ctx), kk_string_box(line), _ctx); /*10001*/
      et_2_0 = kk_gan__ying__event_type_unbox(_x_x814, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_std_core_types__tuple2 _match_x429;
      kk_box_t _x_x818 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun819(_ctx), kk_gan__ying__event_type_box(et_2_0, _ctx), kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(state, _ctx), _ctx); /*10002*/
      _match_x429 = kk_std_core_types__tuple2_unbox(_x_x818, KK_OWNED, _ctx); /*(int, whitemagic-koka/src/unified_runtime_v3/unified-state)*/
      {
        kk_box_t _box_x80 = _match_x429.fst;
        kk_box_t _box_x81 = _match_x429.snd;
        kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state ns = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_box_x81, KK_BORROWED, _ctx);
        struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x823 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(ns, _ctx);
        kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(ns, _ctx);
        kk_std_core_types__tuple2_drop(_match_x429, _ctx);
        x_10115 = ns; /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
        goto _match_x781;
      }
    }
    {
      kk_string_drop(op_0, _ctx);
      kk_string_drop(line, _ctx);
      x_10115 = state; /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
    }
    _match_x781: ;
  }
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10115, (KK_I32(4)), _ctx);
    kk_box_t _x_x824 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10113_fun825(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x824); return kk_Unit;
  }
  {
    kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop(x_10115, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun840__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun840(kk_function_t _fself, kk_box_t _b_x114, kk_box_t _b_x115, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun840(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun840, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun840(kk_function_t _fself, kk_box_t _b_x114, kk_box_t _b_x115, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x841;
  kk_string_t _x_x842 = kk_string_unbox(_b_x114); /*string*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x843 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x115, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x841 = kk_whitemagic_dash_koka_src_unified__runtime__v3_batch_response_real(_x_x842, _x_x843, _ctx); /*string*/
  return kk_string_box(_x_x841);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun849__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun849(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun849(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun849, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun849(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x850;
  kk_string_t _x_x851 = kk_string_unbox(_b_x118); /*string*/
  _x_x850 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_op(_x_x851, _ctx); /*string*/
  return kk_string_box(_x_x850);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun856__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun856(kk_function_t _fself, kk_box_t _b_x123, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun856(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun856, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun856(kk_function_t _fself, kk_box_t _b_x123, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x857;
  kk_string_t _x_x858 = kk_string_unbox(_b_x123); /*string*/
  _x_x857 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_event_type(_x_x858, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x857, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun862__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun862(kk_function_t _fself, kk_box_t _b_x134, kk_box_t _b_x135, kk_box_t _b_x136, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun862(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun862, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun862(kk_function_t _fself, kk_box_t _b_x134, kk_box_t _b_x135, kk_box_t _b_x136, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_0_0_147 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x136, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  kk_hot__paths__path_profile profile;
  kk_string_t _x_x863;
  kk_gan__ying__event_type _x_x864;
  kk_box_t _x_x865 = kk_box_dup(_b_x134, _ctx); /*10000*/
  _x_x864 = kk_gan__ying__event_type_unbox(_x_x865, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x863 = kk_gan__ying_event_type_to_string(_x_x864, _ctx); /*string*/
  profile = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x863, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x866;
  kk_std_core_types__list _x_x867;
  kk_box_t _x_x868;
  kk_gan__ying__resonance_event _x_x869;
  kk_string_t _x_x870 = kk_string_unbox(_b_x135); /*string*/
  kk_gan__ying__event_type _x_x871 = kk_gan__ying__event_type_unbox(_b_x134, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_string_t _x_x872 = kk_string_empty(); /*string*/
  _x_x869 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x870, _x_x871, _x_x872, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x868 = kk_gan__ying__resonance_event_box(_x_x869, _ctx); /*10021*/
  kk_std_core_types__list _x_x874;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x875 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_0_0_147, _ctx);
    kk_std_core_types__list _x = _con_x875->events;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x874 = _x; /*list<gan_ying/resonance-event>*/
  }
  _x_x867 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x868, _x_x874, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x876;
  kk_std_core_types__list _x_x877;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x878 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_0_0_147, _ctx);
    kk_std_core_types__list _x_0 = _con_x878->profiles;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x877 = _x_0; /*list<hot_paths/path-profile>*/
  }
  _x_x876 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile, _ctx), _x_x877, _ctx); /*list<10021>*/
  kk_integer_t _x_x879;
  kk_integer_t _x_x880;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x881 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_0_0_147, _ctx);
    kk_integer_t _x_1 = _con_x881->total_ops;
    kk_integer_dup(_x_1, _ctx);
    _x_x880 = _x_1; /*int*/
  }
  _x_x879 = kk_integer_add_small_const(_x_x880, 1, _ctx); /*int*/
  kk_integer_t _x_x882;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x883 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_0_0_147, _ctx);
    kk_integer_t _x_2 = _con_x883->batch_count;
    kk_integer_dup(_x_2, _ctx);
    _x_x882 = _x_2; /*int*/
  }
  double _x_x884;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x885 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_0_0_147, _ctx);
    kk_std_core_types__list _pat_0_3 = _con_x885->events;
    kk_std_core_types__list _pat_1_3 = _con_x885->profiles;
    kk_integer_t _pat_2_3 = _con_x885->total_ops;
    kk_integer_t _pat_3_3 = _con_x885->batch_count;
    double _x_3 = _con_x885->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state_0_0_147, _ctx)) {
      kk_integer_drop(_pat_3_3, _ctx);
      kk_integer_drop(_pat_2_3, _ctx);
      kk_std_core_types__list_drop(_pat_1_3, _ctx);
      kk_std_core_types__list_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(state_0_0_147, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state_0_0_147, _ctx);
    }
    _x_x884 = _x_3; /*float64*/
  }
  _x_x866 = kk_whitemagic_dash_koka_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x867, _x_x876, _x_x879, _x_x882, _x_x884, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  return kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x866, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun896__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun896(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun896(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun896, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun896(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x897;
  kk_gan__ying__event_type _x_x898 = kk_gan__ying__event_type_unbox(_b_x150, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x897 = kk_gan__ying_event_type_to_string(_x_x898, _ctx); /*string*/
  return kk_string_box(_x_x897);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun905__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun905(kk_function_t _fself, kk_box_t _b_x153, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun905(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun905, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun905(kk_function_t _fself, kk_box_t _b_x153, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x906;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x907 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x153, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x906 = kk_whitemagic_dash_koka_src_unified__runtime__v3_json_state(_x_x907, _ctx); /*string*/
  return kk_string_box(_x_x906);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun911__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun911(kk_function_t _fself, kk_box_t _b_x156, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun911(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun911, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun911(kk_function_t _fself, kk_box_t _b_x156, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x912;
  kk_string_t _x_x913 = kk_string_unbox(_b_x156); /*string*/
  _x_x912 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_event_type(_x_x913, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x912, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun917__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun917(kk_function_t _fself, kk_box_t _b_x162, kk_box_t _b_x163, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun917(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun917, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun917(kk_function_t _fself, kk_box_t _b_x162, kk_box_t _b_x163, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x918;
  kk_gan__ying__event_type _x_x919 = kk_gan__ying__event_type_unbox(_b_x162, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x920 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x163, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x918 = kk_whitemagic_dash_koka_src_unified__runtime__v3_cascade_profiled(_x_x919, _x_x920, _ctx); /*(int, whitemagic-koka/src/unified_runtime_v3/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x918, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun933__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun933(kk_function_t _fself, kk_box_t _b_x169, kk_box_t _b_x170, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun933(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun933, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun933(kk_function_t _fself, kk_box_t _b_x169, kk_box_t _b_x170, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x934;
  kk_string_t _x_x935 = kk_string_unbox(_b_x169); /*string*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x936 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x170, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x934 = kk_whitemagic_dash_koka_src_unified__runtime__v3_execute_cmd(_x_x935, _x_x936, _ctx); /*string*/
  return kk_string_box(_x_x934);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun943__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun943(kk_function_t _fself, kk_box_t _b_x174, kk_box_t _b_x175, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun943(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun943, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun943(kk_function_t _fself, kk_box_t _b_x174, kk_box_t _b_x175, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x944;
  kk_string_t _x_x945 = kk_string_unbox(_b_x174); /*string*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x946 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x175, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x944 = kk_whitemagic_dash_koka_src_unified__runtime__v3_execute_cmd(_x_x945, _x_x946, _ctx); /*string*/
  return kk_string_box(_x_x944);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun953__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun953(kk_function_t _fself, kk_box_t _b_x179, kk_box_t _b_x180, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun953(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun953, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun953(kk_function_t _fself, kk_box_t _b_x179, kk_box_t _b_x180, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x954;
  kk_string_t _x_x955 = kk_string_unbox(_b_x179); /*string*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x956 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x180, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x954 = kk_whitemagic_dash_koka_src_unified__runtime__v3_execute_cmd(_x_x955, _x_x956, _ctx); /*string*/
  return kk_string_box(_x_x954);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun964__t {
  struct kk_function_s _base;
  kk_string_t line_0;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_0;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun964(kk_function_t _fself, kk_box_t _b_x201, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun964(kk_string_t line_0, kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_0, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun964__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun964__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun964, kk_context());
  _self->line_0 = line_0;
  _self->state_0 = state_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun964(kk_function_t _fself, kk_box_t _b_x201, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun964__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114_fun964__t*, _fself, _ctx);
  kk_string_t line_0 = _self->line_0; /* string */
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_0 = _self->state_0; /* whitemagic-koka/src/unified_runtime_v3/unified-state */
  kk_drop_match(_self, {kk_string_dup(line_0, _ctx);kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10047_0_203 = kk_string_unbox(_b_x201); /*string*/;
  kk_unit_t _x_x965 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113(line_0, state_0, _c_x10047_0_203, _ctx);
  return kk_unit_box(_x_x965);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114(kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_0, kk_string_t line_0, kk_context_t* _ctx) { /* (state : unified-state, line : string) -> <console/console,exn> () */ 
  bool _match_x422;
  kk_string_t _x_x828 = kk_string_dup(line_0, _ctx); /*string*/
  kk_string_t _x_x829 = kk_string_empty(); /*string*/
  _match_x422 = kk_string_is_eq(_x_x828,_x_x829,kk_context()); /*bool*/
  if (_match_x422) {
    kk_datatype_ptr_dropn(state_0, (KK_I32(4)), _ctx);
    kk_string_drop(line_0, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    bool _match_x423;
    kk_string_t _x_x831 = kk_string_dup(line_0, _ctx); /*string*/
    kk_string_t _x_x832;
    kk_define_string_literal(, _s_x833, 6, "\"quit\"", _ctx)
    _x_x832 = kk_string_dup(_s_x833, _ctx); /*string*/
    _match_x423 = kk_string_contains(_x_x831,_x_x832,kk_context()); /*bool*/
    if (_match_x423) {
      kk_datatype_ptr_dropn(state_0, (KK_I32(4)), _ctx);
      kk_string_drop(line_0, _ctx);
      kk_string_t _x_x834;
      kk_define_string_literal(, _s_x835, 20, "{\"status\":\"stopped\"}", _ctx)
      _x_x834 = kk_string_dup(_s_x835, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x834, _ctx); return kk_Unit;
    }
    {
      kk_string_t x_0_10117;
      bool _match_x425;
      kk_string_t _x_x836 = kk_string_dup(line_0, _ctx); /*string*/
      kk_string_t _x_x837;
      kk_define_string_literal(, _s_x838, 11, "\"commands\":", _ctx)
      _x_x837 = kk_string_dup(_s_x838, _ctx); /*string*/
      _match_x425 = kk_string_contains(_x_x836,_x_x837,kk_context()); /*bool*/
      if (_match_x425) {
        kk_box_t _x_x839;
        kk_box_t _x_x844;
        kk_string_t _x_x845 = kk_string_dup(line_0, _ctx); /*string*/
        _x_x844 = kk_string_box(_x_x845); /*10000*/
        kk_box_t _x_x846;
        kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x847 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_0, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
        _x_x846 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x847, _ctx); /*10001*/
        _x_x839 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun840(_ctx), _x_x844, _x_x846, _ctx); /*10002*/
        x_0_10117 = kk_string_unbox(_x_x839); /*string*/
      }
      else {
        kk_string_t op;
        kk_box_t _x_x848;
        kk_box_t _x_x852;
        kk_string_t _x_x853 = kk_string_dup(line_0, _ctx); /*string*/
        _x_x852 = kk_string_box(_x_x853); /*10000*/
        _x_x848 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun849(_ctx), _x_x852, _ctx); /*10001*/
        op = kk_string_unbox(_x_x848); /*string*/
        if (kk_string_cmp_cstr_borrow(op, "emit", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_gan__ying__event_type et;
          kk_box_t _x_x855;
          kk_box_t _x_x859;
          kk_string_t _x_x860 = kk_string_dup(line_0, _ctx); /*string*/
          _x_x859 = kk_string_box(_x_x860); /*10000*/
          _x_x855 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun856(_ctx), _x_x859, _ctx); /*10001*/
          et = kk_gan__ying__event_type_unbox(_x_x855, KK_OWNED, _ctx); /*gan_ying/event-type*/
          kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state new_state;
          kk_box_t _x_x861;
          kk_box_t _x_x886;
          kk_string_t _x_x887;
          kk_define_string_literal(, _s_x888, 18, "unified_runtime_v3", _ctx)
          _x_x887 = kk_string_dup(_s_x888, _ctx); /*string*/
          _x_x886 = kk_string_box(_x_x887); /*10001*/
          kk_box_t _x_x889;
          kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x890 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_0, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
          _x_x889 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x890, _ctx); /*10002*/
          _x_x861 = kk_std_core_hnd__open_none3(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun862(_ctx), kk_gan__ying__event_type_box(et, _ctx), _x_x886, _x_x889, _ctx); /*10003*/
          new_state = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_x_x861, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
          kk_string_t _x_x891;
          kk_define_string_literal(, _s_x892, 12, "{\"emitted\":\"", _ctx)
          _x_x891 = kk_string_dup(_s_x892, _ctx); /*string*/
          kk_string_t _x_x893;
          kk_string_t _x_x894;
          kk_box_t _x_x895 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun896(_ctx), kk_gan__ying__event_type_box(et, _ctx), _ctx); /*10001*/
          _x_x894 = kk_string_unbox(_x_x895); /*string*/
          kk_string_t _x_x899;
          kk_string_t _x_x900;
          kk_define_string_literal(, _s_x901, 10, "\",\"state\":", _ctx)
          _x_x900 = kk_string_dup(_s_x901, _ctx); /*string*/
          kk_string_t _x_x902;
          kk_string_t _x_x903;
          kk_box_t _x_x904 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun905(_ctx), kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(new_state, _ctx), _ctx); /*10001*/
          _x_x903 = kk_string_unbox(_x_x904); /*string*/
          kk_string_t _x_x908;
          kk_define_string_literal(, _s_x909, 1, "}", _ctx)
          _x_x908 = kk_string_dup(_s_x909, _ctx); /*string*/
          _x_x902 = kk_std_core_types__lp__plus__plus__rp_(_x_x903, _x_x908, _ctx); /*string*/
          _x_x899 = kk_std_core_types__lp__plus__plus__rp_(_x_x900, _x_x902, _ctx); /*string*/
          _x_x893 = kk_std_core_types__lp__plus__plus__rp_(_x_x894, _x_x899, _ctx); /*string*/
          x_0_10117 = kk_std_core_types__lp__plus__plus__rp_(_x_x891, _x_x893, _ctx); /*string*/
          goto _match_x854;
        }
        if (kk_string_cmp_cstr_borrow(op, "cascade", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_gan__ying__event_type et_0_0;
          kk_box_t _x_x910;
          kk_box_t _x_x914;
          kk_string_t _x_x915 = kk_string_dup(line_0, _ctx); /*string*/
          _x_x914 = kk_string_box(_x_x915); /*10000*/
          _x_x910 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun911(_ctx), _x_x914, _ctx); /*10001*/
          et_0_0 = kk_gan__ying__event_type_unbox(_x_x910, KK_OWNED, _ctx); /*gan_ying/event-type*/
          kk_std_core_types__tuple2 _match_x426;
          kk_box_t _x_x916;
          kk_box_t _x_x921;
          kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x922 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_0, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
          _x_x921 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x922, _ctx); /*10001*/
          _x_x916 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun917(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _x_x921, _ctx); /*10002*/
          _match_x426 = kk_std_core_types__tuple2_unbox(_x_x916, KK_OWNED, _ctx); /*(int, whitemagic-koka/src/unified_runtime_v3/unified-state)*/
          {
            kk_box_t _box_x164 = _match_x426.fst;
            kk_box_t _box_x165 = _match_x426.snd;
            kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _pat_8 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_box_x165, KK_BORROWED, _ctx);
            struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x923 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_pat_8, _ctx);
            kk_integer_t handlers = kk_integer_unbox(_box_x164, _ctx);
            kk_integer_dup(handlers, _ctx);
            kk_std_core_types__tuple2_drop(_match_x426, _ctx);
            kk_string_t _x_x924;
            kk_define_string_literal(, _s_x925, 22, "{\"handlers_triggered\":", _ctx)
            _x_x924 = kk_string_dup(_s_x925, _ctx); /*string*/
            kk_string_t _x_x926;
            kk_string_t _x_x927 = kk_std_core_int_show(handlers, _ctx); /*string*/
            kk_string_t _x_x928;
            kk_define_string_literal(, _s_x929, 1, "}", _ctx)
            _x_x928 = kk_string_dup(_s_x929, _ctx); /*string*/
            _x_x926 = kk_std_core_types__lp__plus__plus__rp_(_x_x927, _x_x928, _ctx); /*string*/
            x_0_10117 = kk_std_core_types__lp__plus__plus__rp_(_x_x924, _x_x926, _ctx); /*string*/
            goto _match_x854;
          }
        }
        if (kk_string_cmp_cstr_borrow(op, "profile", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_define_string_literal(, _s_x930, 17, "{\"profiled\":true}", _ctx)
          x_0_10117 = kk_string_dup(_s_x930, _ctx); /*string*/
          goto _match_x854;
        }
        if (kk_string_cmp_cstr_borrow(op, "hot", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_define_string_literal(, _s_x931, 26, "{\"hot_paths_registered\":0}", _ctx)
          x_0_10117 = kk_string_dup(_s_x931, _ctx); /*string*/
          goto _match_x854;
        }
        if (kk_string_cmp_cstr_borrow(op, "status", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_box_t _x_x932;
          kk_box_t _x_x937;
          kk_string_t _x_x938;
          kk_define_string_literal(, _s_x939, 6, "status", _ctx)
          _x_x938 = kk_string_dup(_s_x939, _ctx); /*string*/
          _x_x937 = kk_string_box(_x_x938); /*10000*/
          kk_box_t _x_x940;
          kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x941 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_0, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
          _x_x940 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x941, _ctx); /*10001*/
          _x_x932 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun933(_ctx), _x_x937, _x_x940, _ctx); /*10002*/
          x_0_10117 = kk_string_unbox(_x_x932); /*string*/
          goto _match_x854;
        }
        if (kk_string_cmp_cstr_borrow(op, "count", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_box_t _x_x942;
          kk_box_t _x_x947;
          kk_string_t _x_x948;
          kk_define_string_literal(, _s_x949, 5, "count", _ctx)
          _x_x948 = kk_string_dup(_s_x949, _ctx); /*string*/
          _x_x947 = kk_string_box(_x_x948); /*10000*/
          kk_box_t _x_x950;
          kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x951 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_0, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
          _x_x950 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x951, _ctx); /*10001*/
          _x_x942 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun943(_ctx), _x_x947, _x_x950, _ctx); /*10002*/
          x_0_10117 = kk_string_unbox(_x_x942); /*string*/
          goto _match_x854;
        }
        if (kk_string_cmp_cstr_borrow(op, "ping", _ctx) == 0) {
          kk_string_drop(op, _ctx);
          kk_box_t _x_x952;
          kk_box_t _x_x957;
          kk_string_t _x_x958;
          kk_define_string_literal(, _s_x959, 4, "ping", _ctx)
          _x_x958 = kk_string_dup(_s_x959, _ctx); /*string*/
          _x_x957 = kk_string_box(_x_x958); /*10000*/
          kk_box_t _x_x960;
          kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x961 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_0, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
          _x_x960 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x961, _ctx); /*10001*/
          _x_x952 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun953(_ctx), _x_x957, _x_x960, _ctx); /*10002*/
          x_0_10117 = kk_string_unbox(_x_x952); /*string*/
          goto _match_x854;
        }
        {
          kk_string_drop(op, _ctx);
          kk_define_string_literal(, _s_x962, 22, "{\"error\":\"unknown op\"}", _ctx)
          x_0_10117 = kk_string_dup(_s_x962, _ctx); /*string*/
        }
        _match_x854: ;
      }
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_0_10117, _ctx);
        kk_box_t _x_x963 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__runtime__v3__new_mlift_server_loop_10114_fun964(line_0, state_0, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x963); return kk_Unit;
      }
      {
        kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113(line_0, state_0, x_0_10117, _ctx); return kk_Unit;
      }
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun967__t {
  struct kk_function_s _base;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_2;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun967(kk_function_t _fself, kk_box_t _b_x205, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun967(kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_2, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun967__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun967__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun967, kk_context());
  _self->state_2 = state_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun967(kk_function_t _fself, kk_box_t _b_x205, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun967__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun967__t*, _fself, _ctx);
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_2 = _self->state_2; /* whitemagic-koka/src/unified_runtime_v3/unified-state */
  kk_drop_match(_self, {kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx);}, {}, _ctx)
  kk_string_t line_1_379 = kk_string_unbox(_b_x205); /*string*/;
  kk_unit_t _x_x968 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10114(state_2, line_1_379, _ctx);
  return kk_unit_box(_x_x968);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun981__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun981(kk_function_t _fself, kk_box_t _b_x209, kk_box_t _b_x210, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun981(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun981, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun981(kk_function_t _fself, kk_box_t _b_x209, kk_box_t _b_x210, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x982;
  kk_string_t _x_x983 = kk_string_unbox(_b_x209); /*string*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x984 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x210, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x982 = kk_whitemagic_dash_koka_src_unified__runtime__v3_batch_response_real(_x_x983, _x_x984, _ctx); /*string*/
  return kk_string_box(_x_x982);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun990__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun990(kk_function_t _fself, kk_box_t _b_x213, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun990(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun990, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun990(kk_function_t _fself, kk_box_t _b_x213, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x991;
  kk_string_t _x_x992 = kk_string_unbox(_b_x213); /*string*/
  _x_x991 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_op(_x_x992, _ctx); /*string*/
  return kk_string_box(_x_x991);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun997__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun997(kk_function_t _fself, kk_box_t _b_x218, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun997(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun997, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun997(kk_function_t _fself, kk_box_t _b_x218, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x998;
  kk_string_t _x_x999 = kk_string_unbox(_b_x218); /*string*/
  _x_x998 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_event_type(_x_x999, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x998, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1003__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1003(kk_function_t _fself, kk_box_t _b_x229, kk_box_t _b_x230, kk_box_t _b_x231, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1003(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1003, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1003(kk_function_t _fself, kk_box_t _b_x229, kk_box_t _b_x230, kk_box_t _b_x231, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_0_1_242 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x231, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  kk_hot__paths__path_profile profile_1;
  kk_string_t _x_x1004;
  kk_gan__ying__event_type _x_x1005;
  kk_box_t _x_x1006 = kk_box_dup(_b_x229, _ctx); /*10000*/
  _x_x1005 = kk_gan__ying__event_type_unbox(_x_x1006, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x1004 = kk_gan__ying_event_type_to_string(_x_x1005, _ctx); /*string*/
  profile_1 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x1004, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1007;
  kk_std_core_types__list _x_x1008;
  kk_box_t _x_x1009;
  kk_gan__ying__resonance_event _x_x1010;
  kk_string_t _x_x1011 = kk_string_unbox(_b_x230); /*string*/
  kk_gan__ying__event_type _x_x1012 = kk_gan__ying__event_type_unbox(_b_x229, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_string_t _x_x1013 = kk_string_empty(); /*string*/
  _x_x1010 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x1011, _x_x1012, _x_x1013, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x1009 = kk_gan__ying__resonance_event_box(_x_x1010, _ctx); /*10021*/
  kk_std_core_types__list _x_x1015;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1016 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_0_1_242, _ctx);
    kk_std_core_types__list _x_6 = _con_x1016->events;
    kk_std_core_types__list_dup(_x_6, _ctx);
    _x_x1015 = _x_6; /*list<gan_ying/resonance-event>*/
  }
  _x_x1008 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1009, _x_x1015, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x1017;
  kk_std_core_types__list _x_x1018;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1019 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_0_1_242, _ctx);
    kk_std_core_types__list _x_0_2 = _con_x1019->profiles;
    kk_std_core_types__list_dup(_x_0_2, _ctx);
    _x_x1018 = _x_0_2; /*list<hot_paths/path-profile>*/
  }
  _x_x1017 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_1, _ctx), _x_x1018, _ctx); /*list<10021>*/
  kk_integer_t _x_x1020;
  kk_integer_t _x_x1021;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1022 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_0_1_242, _ctx);
    kk_integer_t _x_1_2 = _con_x1022->total_ops;
    kk_integer_dup(_x_1_2, _ctx);
    _x_x1021 = _x_1_2; /*int*/
  }
  _x_x1020 = kk_integer_add_small_const(_x_x1021, 1, _ctx); /*int*/
  kk_integer_t _x_x1023;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1024 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_0_1_242, _ctx);
    kk_integer_t _x_2_2 = _con_x1024->batch_count;
    kk_integer_dup(_x_2_2, _ctx);
    _x_x1023 = _x_2_2; /*int*/
  }
  double _x_x1025;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1026 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_0_1_242, _ctx);
    kk_std_core_types__list _pat_0_3_2 = _con_x1026->events;
    kk_std_core_types__list _pat_1_3_2 = _con_x1026->profiles;
    kk_integer_t _pat_2_3_2 = _con_x1026->total_ops;
    kk_integer_t _pat_3_3_2 = _con_x1026->batch_count;
    double _x_3_2 = _con_x1026->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state_0_1_242, _ctx)) {
      kk_integer_drop(_pat_3_3_2, _ctx);
      kk_integer_drop(_pat_2_3_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_3_2, _ctx);
      kk_std_core_types__list_drop(_pat_0_3_2, _ctx);
      kk_datatype_ptr_free(state_0_1_242, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state_0_1_242, _ctx);
    }
    _x_x1025 = _x_3_2; /*float64*/
  }
  _x_x1007 = kk_whitemagic_dash_koka_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x1008, _x_x1017, _x_x1020, _x_x1023, _x_x1025, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  return kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1007, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1037__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1037(kk_function_t _fself, kk_box_t _b_x245, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1037(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1037, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1037(kk_function_t _fself, kk_box_t _b_x245, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1038;
  kk_gan__ying__event_type _x_x1039 = kk_gan__ying__event_type_unbox(_b_x245, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x1038 = kk_gan__ying_event_type_to_string(_x_x1039, _ctx); /*string*/
  return kk_string_box(_x_x1038);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1046__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1046(kk_function_t _fself, kk_box_t _b_x248, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1046(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1046, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1046(kk_function_t _fself, kk_box_t _b_x248, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1047;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1048 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x248, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x1047 = kk_whitemagic_dash_koka_src_unified__runtime__v3_json_state(_x_x1048, _ctx); /*string*/
  return kk_string_box(_x_x1047);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1052__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1052(kk_function_t _fself, kk_box_t _b_x251, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1052(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1052, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1052(kk_function_t _fself, kk_box_t _b_x251, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x1053;
  kk_string_t _x_x1054 = kk_string_unbox(_b_x251); /*string*/
  _x_x1053 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_event_type(_x_x1054, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x1053, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1058__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1058(kk_function_t _fself, kk_box_t _b_x257, kk_box_t _b_x258, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1058(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1058, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1058(kk_function_t _fself, kk_box_t _b_x257, kk_box_t _b_x258, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x1059;
  kk_gan__ying__event_type _x_x1060 = kk_gan__ying__event_type_unbox(_b_x257, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1061 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x258, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x1059 = kk_whitemagic_dash_koka_src_unified__runtime__v3_cascade_profiled(_x_x1060, _x_x1061, _ctx); /*(int, whitemagic-koka/src/unified_runtime_v3/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x1059, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1074__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1074(kk_function_t _fself, kk_box_t _b_x264, kk_box_t _b_x265, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1074(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1074, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1074(kk_function_t _fself, kk_box_t _b_x264, kk_box_t _b_x265, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1075;
  kk_string_t _x_x1076 = kk_string_unbox(_b_x264); /*string*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1077 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x265, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x1075 = kk_whitemagic_dash_koka_src_unified__runtime__v3_execute_cmd(_x_x1076, _x_x1077, _ctx); /*string*/
  return kk_string_box(_x_x1075);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1084__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1084(kk_function_t _fself, kk_box_t _b_x269, kk_box_t _b_x270, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1084(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1084, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1084(kk_function_t _fself, kk_box_t _b_x269, kk_box_t _b_x270, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1085;
  kk_string_t _x_x1086 = kk_string_unbox(_b_x269); /*string*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1087 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x270, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x1085 = kk_whitemagic_dash_koka_src_unified__runtime__v3_execute_cmd(_x_x1086, _x_x1087, _ctx); /*string*/
  return kk_string_box(_x_x1085);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1094__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1094(kk_function_t _fself, kk_box_t _b_x274, kk_box_t _b_x275, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1094(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1094, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1094(kk_function_t _fself, kk_box_t _b_x274, kk_box_t _b_x275, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1095;
  kk_string_t _x_x1096 = kk_string_unbox(_b_x274); /*string*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1097 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x275, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x1095 = kk_whitemagic_dash_koka_src_unified__runtime__v3_execute_cmd(_x_x1096, _x_x1097, _ctx); /*string*/
  return kk_string_box(_x_x1095);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1105__t {
  struct kk_function_s _base;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_2;
  kk_string_t x_1_10119;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1105(kk_function_t _fself, kk_box_t _b_x296, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1105(kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_2, kk_string_t x_1_10119, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1105__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1105__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1105, kk_context());
  _self->state_2 = state_2;
  _self->x_1_10119 = x_1_10119;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1105(kk_function_t _fself, kk_box_t _b_x296, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1105__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1105__t*, _fself, _ctx);
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_2 = _self->state_2; /* whitemagic-koka/src/unified_runtime_v3/unified-state */
  kk_string_t x_1_10119 = _self->x_1_10119; /* string */
  kk_drop_match(_self, {kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx);kk_string_dup(x_1_10119, _ctx);}, {}, _ctx)
  kk_string_t _c_x10047_1_380 = kk_string_unbox(_b_x296); /*string*/;
  kk_unit_t _x_x1106 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__mlift_server_loop_10113(x_1_10119, state_2, _c_x10047_1_380, _ctx);
  return kk_unit_box(_x_x1106);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1111__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1111(kk_function_t _fself, kk_box_t _b_x299, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1111(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1111, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1111(kk_function_t _fself, kk_box_t _b_x299, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1112;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _match_x419 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x299, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1113 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_match_x419, _ctx);
    kk_std_core_types__list _pat_0_3_0_0 = _con_x1113->events;
    kk_std_core_types__list _pat_1_3_0_0 = _con_x1113->profiles;
    kk_integer_t _pat_2_3_0_0 = _con_x1113->total_ops;
    kk_integer_t _x_2_0_0 = _con_x1113->batch_count;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x419, _ctx)) {
      kk_integer_drop(_pat_2_3_0_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_3_0_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_3_0_0, _ctx);
      kk_datatype_ptr_free(_match_x419, _ctx);
    }
    else {
      kk_integer_dup(_x_2_0_0, _ctx);
      kk_datatype_ptr_decref(_match_x419, _ctx);
    }
    _x_x1112 = _x_2_0_0; /*int*/
  }
  return kk_integer_box(_x_x1112, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1118__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1118(kk_function_t _fself, kk_box_t _b_x305, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1118(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1118, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1118(kk_function_t _fself, kk_box_t _b_x305, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x1119;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _match_x418 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x305, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1120 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_match_x418, _ctx);
    kk_std_core_types__list _x_4_0 = _con_x1120->events;
    kk_std_core_types__list _pat_0_0_1_0 = _con_x1120->profiles;
    kk_integer_t _pat_1_0_1_0 = _con_x1120->total_ops;
    kk_integer_t _pat_2_0_1_0 = _con_x1120->batch_count;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x418, _ctx)) {
      kk_integer_drop(_pat_2_0_1_0, _ctx);
      kk_integer_drop(_pat_1_0_1_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_0_1_0, _ctx);
      kk_datatype_ptr_free(_match_x418, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_4_0, _ctx);
      kk_datatype_ptr_decref(_match_x418, _ctx);
    }
    _x_x1119 = _x_4_0; /*list<gan_ying/resonance-event>*/
  }
  return kk_std_core_types__list_box(_x_x1119, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1125__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1125(kk_function_t _fself, kk_box_t _b_x308, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1125(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1125, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1125(kk_function_t _fself, kk_box_t _b_x308, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x1126;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _match_x417 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x308, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1127 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_match_x417, _ctx);
    kk_std_core_types__list _pat_0_1_0_0 = _con_x1127->events;
    kk_std_core_types__list _x_0_0_0 = _con_x1127->profiles;
    kk_integer_t _pat_1_1_0_0 = _con_x1127->total_ops;
    kk_integer_t _pat_2_1_0_0 = _con_x1127->batch_count;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x417, _ctx)) {
      kk_integer_drop(_pat_2_1_0_0, _ctx);
      kk_integer_drop(_pat_1_1_0_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_1_0_0, _ctx);
      kk_datatype_ptr_free(_match_x417, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_0_0_0, _ctx);
      kk_datatype_ptr_decref(_match_x417, _ctx);
    }
    _x_x1126 = _x_0_0_0; /*list<hot_paths/path-profile>*/
  }
  return kk_std_core_types__list_box(_x_x1126, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1132__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1132(kk_function_t _fself, kk_box_t _b_x311, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1132(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1132, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1132(kk_function_t _fself, kk_box_t _b_x311, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1133;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _match_x416 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x311, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1134 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_match_x416, _ctx);
    kk_std_core_types__list _pat_0_2_0_0 = _con_x1134->events;
    kk_std_core_types__list _pat_1_2_0_0 = _con_x1134->profiles;
    kk_integer_t _x_1_0_0 = _con_x1134->total_ops;
    kk_integer_t _pat_2_2_0_0 = _con_x1134->batch_count;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x416, _ctx)) {
      kk_integer_drop(_pat_2_2_0_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_2_0_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_2_0_0, _ctx);
      kk_datatype_ptr_free(_match_x416, _ctx);
    }
    else {
      kk_integer_dup(_x_1_0_0, _ctx);
      kk_datatype_ptr_decref(_match_x416, _ctx);
    }
    _x_x1133 = _x_1_0_0; /*int*/
  }
  return kk_integer_box(_x_x1133, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1140__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1140(kk_function_t _fself, kk_box_t _b_x314, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1140(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1140, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1140(kk_function_t _fself, kk_box_t _b_x314, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1141;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _match_x415 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x314, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1142 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_match_x415, _ctx);
    kk_std_core_types__list _pat_0_4_0 = _con_x1142->events;
    kk_std_core_types__list _pat_1_4_0 = _con_x1142->profiles;
    kk_integer_t _pat_2_4_0 = _con_x1142->total_ops;
    kk_integer_t _pat_3_4_0 = _con_x1142->batch_count;
    double _x_3_0_0 = _con_x1142->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x415, _ctx)) {
      kk_integer_drop(_pat_3_4_0, _ctx);
      kk_integer_drop(_pat_2_4_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_4_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_4_0, _ctx);
      kk_datatype_ptr_free(_match_x415, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x415, _ctx);
    }
    _x_x1141 = _x_3_0_0; /*float64*/
  }
  return kk_double_box(_x_x1141, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1144__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1144(kk_function_t _fself, kk_box_t _b_x317, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1144(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1144, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1144(kk_function_t _fself, kk_box_t _b_x317, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1145;
  kk_string_t _x_x1146 = kk_string_unbox(_b_x317); /*string*/
  _x_x1145 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_op(_x_x1146, _ctx); /*string*/
  return kk_string_box(_x_x1145);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1151__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1151(kk_function_t _fself, kk_box_t _b_x322, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1151(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1151, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1151(kk_function_t _fself, kk_box_t _b_x322, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x1152;
  kk_string_t _x_x1153 = kk_string_unbox(_b_x322); /*string*/
  _x_x1152 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_event_type(_x_x1153, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x1152, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1155__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1155(kk_function_t _fself, kk_box_t _b_x333, kk_box_t _b_x334, kk_box_t _b_x335, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1155(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1155, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1155(kk_function_t _fself, kk_box_t _b_x333, kk_box_t _b_x334, kk_box_t _b_x335, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_1_0_369 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x335, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/;
  kk_hot__paths__path_profile profile_0_0;
  kk_string_t _x_x1156;
  kk_gan__ying__event_type _x_x1157;
  kk_box_t _x_x1158 = kk_box_dup(_b_x333, _ctx); /*10000*/
  _x_x1157 = kk_gan__ying__event_type_unbox(_x_x1158, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x1156 = kk_gan__ying_event_type_to_string(_x_x1157, _ctx); /*string*/
  profile_0_0 = kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x1156, kk_integer_from_small(1), 0x1p0, 0x1p0, kk_hot__paths__new_Low(_ctx), kk_hot__paths__new_IO(_ctx), _ctx); /*hot_paths/path-profile*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1159;
  kk_std_core_types__list _x_x1160;
  kk_box_t _x_x1161;
  kk_gan__ying__resonance_event _x_x1162;
  kk_string_t _x_x1163 = kk_string_unbox(_b_x334); /*string*/
  kk_gan__ying__event_type _x_x1164 = kk_gan__ying__event_type_unbox(_b_x333, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_string_t _x_x1165 = kk_string_empty(); /*string*/
  _x_x1162 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x1163, _x_x1164, _x_x1165, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x1161 = kk_gan__ying__resonance_event_box(_x_x1162, _ctx); /*10021*/
  kk_std_core_types__list _x_x1167;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1168 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_1_0_369, _ctx);
    kk_std_core_types__list _x_5_0 = _con_x1168->events;
    kk_std_core_types__list_dup(_x_5_0, _ctx);
    _x_x1167 = _x_5_0; /*list<gan_ying/resonance-event>*/
  }
  _x_x1160 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1161, _x_x1167, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x1169;
  kk_std_core_types__list _x_x1170;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1171 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_1_0_369, _ctx);
    kk_std_core_types__list _x_0_1_0 = _con_x1171->profiles;
    kk_std_core_types__list_dup(_x_0_1_0, _ctx);
    _x_x1170 = _x_0_1_0; /*list<hot_paths/path-profile>*/
  }
  _x_x1169 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_hot__paths__path_profile_box(profile_0_0, _ctx), _x_x1170, _ctx); /*list<10021>*/
  kk_integer_t _x_x1172;
  kk_integer_t _x_x1173;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1174 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_1_0_369, _ctx);
    kk_integer_t _x_1_1_0 = _con_x1174->total_ops;
    kk_integer_dup(_x_1_1_0, _ctx);
    _x_x1173 = _x_1_1_0; /*int*/
  }
  _x_x1172 = kk_integer_add_small_const(_x_x1173, 1, _ctx); /*int*/
  kk_integer_t _x_x1175;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1176 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_1_0_369, _ctx);
    kk_integer_t _x_2_1_0 = _con_x1176->batch_count;
    kk_integer_dup(_x_2_1_0, _ctx);
    _x_x1175 = _x_2_1_0; /*int*/
  }
  double _x_x1177;
  {
    struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1178 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(state_1_0_369, _ctx);
    kk_std_core_types__list _pat_0_3_1_0 = _con_x1178->events;
    kk_std_core_types__list _pat_1_3_1_0 = _con_x1178->profiles;
    kk_integer_t _pat_2_3_1_0 = _con_x1178->total_ops;
    kk_integer_t _pat_3_3_1_0 = _con_x1178->batch_count;
    double _x_3_1_0 = _con_x1178->session_start;
    if kk_likely(kk_datatype_ptr_is_unique(state_1_0_369, _ctx)) {
      kk_integer_drop(_pat_3_3_1_0, _ctx);
      kk_integer_drop(_pat_2_3_1_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_3_1_0, _ctx);
      kk_std_core_types__list_drop(_pat_0_3_1_0, _ctx);
      kk_datatype_ptr_free(state_1_0_369, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state_1_0_369, _ctx);
    }
    _x_x1177 = _x_3_1_0; /*float64*/
  }
  _x_x1159 = kk_whitemagic_dash_koka_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x1160, _x_x1169, _x_x1172, _x_x1175, _x_x1177, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  return kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1159, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1183__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1183(kk_function_t _fself, kk_box_t _b_x338, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1183(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1183, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1183(kk_function_t _fself, kk_box_t _b_x338, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x1184;
  kk_string_t _x_x1185 = kk_string_unbox(_b_x338); /*string*/
  _x_x1184 = kk_whitemagic_dash_koka_src_unified__runtime__v3_extract_event_type(_x_x1185, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x1184, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1187__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1187(kk_function_t _fself, kk_box_t _b_x344, kk_box_t _b_x345, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1187(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1187, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1187(kk_function_t _fself, kk_box_t _b_x344, kk_box_t _b_x345, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x1188;
  kk_gan__ying__event_type _x_x1189 = kk_gan__ying__event_type_unbox(_b_x344, KK_OWNED, _ctx); /*gan_ying/event-type*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1190 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x345, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x1188 = kk_whitemagic_dash_koka_src_unified__runtime__v3_cascade_profiled(_x_x1189, _x_x1190, _ctx); /*(int, whitemagic-koka/src/unified_runtime_v3/unified-state)*/
  return kk_std_core_types__tuple2_box(_x_x1188, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1193__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1193(kk_function_t _fself, kk_box_t _b_x375, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1193(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1193, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop_fun1193(kk_function_t _fself, kk_box_t _b_x375, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1194 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1195 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x375, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop(_x_x1195, _ctx);
  return kk_unit_box(_x_x1194);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop(kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state state_2, kk_context_t* _ctx) { /* (state : unified-state) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_1_10119 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_1_10119, _ctx);
    kk_box_t _x_x966 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun967(state_2, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x966); return kk_Unit;
  }
  {
    bool _match_x409;
    kk_string_t _x_x969 = kk_string_dup(x_1_10119, _ctx); /*string*/
    kk_string_t _x_x970 = kk_string_empty(); /*string*/
    _match_x409 = kk_string_is_eq(_x_x969,_x_x970,kk_context()); /*bool*/
    if (_match_x409) {
      kk_string_drop(x_1_10119, _ctx);
      kk_datatype_ptr_dropn(state_2, (KK_I32(4)), _ctx);
      kk_Unit; return kk_Unit;
    }
    {
      bool _match_x410;
      kk_string_t _x_x972 = kk_string_dup(x_1_10119, _ctx); /*string*/
      kk_string_t _x_x973;
      kk_define_string_literal(, _s_x974, 6, "\"quit\"", _ctx)
      _x_x973 = kk_string_dup(_s_x974, _ctx); /*string*/
      _match_x410 = kk_string_contains(_x_x972,_x_x973,kk_context()); /*bool*/
      if (_match_x410) {
        kk_string_drop(x_1_10119, _ctx);
        kk_datatype_ptr_dropn(state_2, (KK_I32(4)), _ctx);
        kk_string_t _x_x975;
        kk_define_string_literal(, _s_x976, 20, "{\"status\":\"stopped\"}", _ctx)
        _x_x975 = kk_string_dup(_s_x976, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x975, _ctx); return kk_Unit;
      }
      {
        kk_string_t x_2_10122;
        bool _match_x420;
        kk_string_t _x_x977 = kk_string_dup(x_1_10119, _ctx); /*string*/
        kk_string_t _x_x978;
        kk_define_string_literal(, _s_x979, 11, "\"commands\":", _ctx)
        _x_x978 = kk_string_dup(_s_x979, _ctx); /*string*/
        _match_x420 = kk_string_contains(_x_x977,_x_x978,kk_context()); /*bool*/
        if (_match_x420) {
          kk_box_t _x_x980;
          kk_box_t _x_x985;
          kk_string_t _x_x986 = kk_string_dup(x_1_10119, _ctx); /*string*/
          _x_x985 = kk_string_box(_x_x986); /*10000*/
          kk_box_t _x_x987;
          kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x988 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
          _x_x987 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x988, _ctx); /*10001*/
          _x_x980 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun981(_ctx), _x_x985, _x_x987, _ctx); /*10002*/
          x_2_10122 = kk_string_unbox(_x_x980); /*string*/
        }
        else {
          kk_string_t op_1;
          kk_box_t _x_x989;
          kk_box_t _x_x993;
          kk_string_t _x_x994 = kk_string_dup(x_1_10119, _ctx); /*string*/
          _x_x993 = kk_string_box(_x_x994); /*10000*/
          _x_x989 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun990(_ctx), _x_x993, _ctx); /*10001*/
          op_1 = kk_string_unbox(_x_x989); /*string*/
          if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_gan__ying__event_type et_3;
            kk_box_t _x_x996;
            kk_box_t _x_x1000;
            kk_string_t _x_x1001 = kk_string_dup(x_1_10119, _ctx); /*string*/
            _x_x1000 = kk_string_box(_x_x1001); /*10000*/
            _x_x996 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun997(_ctx), _x_x1000, _ctx); /*10001*/
            et_3 = kk_gan__ying__event_type_unbox(_x_x996, KK_OWNED, _ctx); /*gan_ying/event-type*/
            kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state new_state_0;
            kk_box_t _x_x1002;
            kk_box_t _x_x1027;
            kk_string_t _x_x1028;
            kk_define_string_literal(, _s_x1029, 18, "unified_runtime_v3", _ctx)
            _x_x1028 = kk_string_dup(_s_x1029, _ctx); /*string*/
            _x_x1027 = kk_string_box(_x_x1028); /*10001*/
            kk_box_t _x_x1030;
            kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1031 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
            _x_x1030 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1031, _ctx); /*10002*/
            _x_x1002 = kk_std_core_hnd__open_none3(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1003(_ctx), kk_gan__ying__event_type_box(et_3, _ctx), _x_x1027, _x_x1030, _ctx); /*10003*/
            new_state_0 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_x_x1002, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
            kk_string_t _x_x1032;
            kk_define_string_literal(, _s_x1033, 12, "{\"emitted\":\"", _ctx)
            _x_x1032 = kk_string_dup(_s_x1033, _ctx); /*string*/
            kk_string_t _x_x1034;
            kk_string_t _x_x1035;
            kk_box_t _x_x1036 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1037(_ctx), kk_gan__ying__event_type_box(et_3, _ctx), _ctx); /*10001*/
            _x_x1035 = kk_string_unbox(_x_x1036); /*string*/
            kk_string_t _x_x1040;
            kk_string_t _x_x1041;
            kk_define_string_literal(, _s_x1042, 10, "\",\"state\":", _ctx)
            _x_x1041 = kk_string_dup(_s_x1042, _ctx); /*string*/
            kk_string_t _x_x1043;
            kk_string_t _x_x1044;
            kk_box_t _x_x1045 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1046(_ctx), kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(new_state_0, _ctx), _ctx); /*10001*/
            _x_x1044 = kk_string_unbox(_x_x1045); /*string*/
            kk_string_t _x_x1049;
            kk_define_string_literal(, _s_x1050, 1, "}", _ctx)
            _x_x1049 = kk_string_dup(_s_x1050, _ctx); /*string*/
            _x_x1043 = kk_std_core_types__lp__plus__plus__rp_(_x_x1044, _x_x1049, _ctx); /*string*/
            _x_x1040 = kk_std_core_types__lp__plus__plus__rp_(_x_x1041, _x_x1043, _ctx); /*string*/
            _x_x1034 = kk_std_core_types__lp__plus__plus__rp_(_x_x1035, _x_x1040, _ctx); /*string*/
            x_2_10122 = kk_std_core_types__lp__plus__plus__rp_(_x_x1032, _x_x1034, _ctx); /*string*/
            goto _match_x995;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_gan__ying__event_type et_0_0_0;
            kk_box_t _x_x1051;
            kk_box_t _x_x1055;
            kk_string_t _x_x1056 = kk_string_dup(x_1_10119, _ctx); /*string*/
            _x_x1055 = kk_string_box(_x_x1056); /*10000*/
            _x_x1051 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1052(_ctx), _x_x1055, _ctx); /*10001*/
            et_0_0_0 = kk_gan__ying__event_type_unbox(_x_x1051, KK_OWNED, _ctx); /*gan_ying/event-type*/
            kk_std_core_types__tuple2 _match_x421;
            kk_box_t _x_x1057;
            kk_box_t _x_x1062;
            kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1063 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
            _x_x1062 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1063, _ctx); /*10001*/
            _x_x1057 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1058(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _x_x1062, _ctx); /*10002*/
            _match_x421 = kk_std_core_types__tuple2_unbox(_x_x1057, KK_OWNED, _ctx); /*(int, whitemagic-koka/src/unified_runtime_v3/unified-state)*/
            {
              kk_box_t _box_x259 = _match_x421.fst;
              kk_box_t _box_x260 = _match_x421.snd;
              kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _pat_8_0 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_box_x260, KK_BORROWED, _ctx);
              struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1064 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(_pat_8_0, _ctx);
              kk_integer_t handlers_0 = kk_integer_unbox(_box_x259, _ctx);
              kk_integer_dup(handlers_0, _ctx);
              kk_std_core_types__tuple2_drop(_match_x421, _ctx);
              kk_string_t _x_x1065;
              kk_define_string_literal(, _s_x1066, 22, "{\"handlers_triggered\":", _ctx)
              _x_x1065 = kk_string_dup(_s_x1066, _ctx); /*string*/
              kk_string_t _x_x1067;
              kk_string_t _x_x1068 = kk_std_core_int_show(handlers_0, _ctx); /*string*/
              kk_string_t _x_x1069;
              kk_define_string_literal(, _s_x1070, 1, "}", _ctx)
              _x_x1069 = kk_string_dup(_s_x1070, _ctx); /*string*/
              _x_x1067 = kk_std_core_types__lp__plus__plus__rp_(_x_x1068, _x_x1069, _ctx); /*string*/
              x_2_10122 = kk_std_core_types__lp__plus__plus__rp_(_x_x1065, _x_x1067, _ctx); /*string*/
              goto _match_x995;
            }
          }
          if (kk_string_cmp_cstr_borrow(op_1, "profile", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_define_string_literal(, _s_x1071, 17, "{\"profiled\":true}", _ctx)
            x_2_10122 = kk_string_dup(_s_x1071, _ctx); /*string*/
            goto _match_x995;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "hot", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_define_string_literal(, _s_x1072, 26, "{\"hot_paths_registered\":0}", _ctx)
            x_2_10122 = kk_string_dup(_s_x1072, _ctx); /*string*/
            goto _match_x995;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_box_t _x_x1073;
            kk_box_t _x_x1078;
            kk_string_t _x_x1079;
            kk_define_string_literal(, _s_x1080, 6, "status", _ctx)
            _x_x1079 = kk_string_dup(_s_x1080, _ctx); /*string*/
            _x_x1078 = kk_string_box(_x_x1079); /*10000*/
            kk_box_t _x_x1081;
            kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1082 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
            _x_x1081 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1082, _ctx); /*10001*/
            _x_x1073 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1074(_ctx), _x_x1078, _x_x1081, _ctx); /*10002*/
            x_2_10122 = kk_string_unbox(_x_x1073); /*string*/
            goto _match_x995;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "count", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_box_t _x_x1083;
            kk_box_t _x_x1088;
            kk_string_t _x_x1089;
            kk_define_string_literal(, _s_x1090, 5, "count", _ctx)
            _x_x1089 = kk_string_dup(_s_x1090, _ctx); /*string*/
            _x_x1088 = kk_string_box(_x_x1089); /*10000*/
            kk_box_t _x_x1091;
            kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1092 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
            _x_x1091 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1092, _ctx); /*10001*/
            _x_x1083 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1084(_ctx), _x_x1088, _x_x1091, _ctx); /*10002*/
            x_2_10122 = kk_string_unbox(_x_x1083); /*string*/
            goto _match_x995;
          }
          if (kk_string_cmp_cstr_borrow(op_1, "ping", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_box_t _x_x1093;
            kk_box_t _x_x1098;
            kk_string_t _x_x1099;
            kk_define_string_literal(, _s_x1100, 4, "ping", _ctx)
            _x_x1099 = kk_string_dup(_s_x1100, _ctx); /*string*/
            _x_x1098 = kk_string_box(_x_x1099); /*10000*/
            kk_box_t _x_x1101;
            kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1102 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
            _x_x1101 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1102, _ctx); /*10001*/
            _x_x1093 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1094(_ctx), _x_x1098, _x_x1101, _ctx); /*10002*/
            x_2_10122 = kk_string_unbox(_x_x1093); /*string*/
            goto _match_x995;
          }
          {
            kk_string_drop(op_1, _ctx);
            kk_define_string_literal(, _s_x1103, 22, "{\"error\":\"unknown op\"}", _ctx)
            x_2_10122 = kk_string_dup(_s_x1103, _ctx); /*string*/
          }
          _match_x995: ;
        }
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_2_10122, _ctx);
          kk_box_t _x_x1104 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1105(state_2, x_1_10119, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x1104); return kk_Unit;
        }
        {
          kk_unit_t ___0 = kk_Unit;
          kk_std_core_console_printsln(x_2_10122, _ctx);
          kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state x_3_10125;
          bool _match_x413;
          kk_string_t _x_x1107 = kk_string_dup(x_1_10119, _ctx); /*string*/
          kk_string_t _x_x1108;
          kk_define_string_literal(, _s_x1109, 11, "\"commands\":", _ctx)
          _x_x1108 = kk_string_dup(_s_x1109, _ctx); /*string*/
          _match_x413 = kk_string_contains(_x_x1107,_x_x1108,kk_context()); /*bool*/
          if (_match_x413) {
            kk_string_drop(x_1_10119, _ctx);
            kk_integer_t x_10071_0;
            kk_box_t _x_x1110;
            kk_box_t _x_x1114;
            kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1115 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
            _x_x1114 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1115, _ctx); /*10000*/
            _x_x1110 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1111(_ctx), _x_x1114, _ctx); /*10001*/
            x_10071_0 = kk_integer_unbox(_x_x1110, _ctx); /*int*/
            kk_std_core_types__list _x_x1116;
            kk_box_t _x_x1117;
            kk_box_t _x_x1121;
            kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1122 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
            _x_x1121 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1122, _ctx); /*10000*/
            _x_x1117 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1118(_ctx), _x_x1121, _ctx); /*10001*/
            _x_x1116 = kk_std_core_types__list_unbox(_x_x1117, KK_OWNED, _ctx); /*list<gan_ying/resonance-event>*/
            kk_std_core_types__list _x_x1123;
            kk_box_t _x_x1124;
            kk_box_t _x_x1128;
            kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1129 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
            _x_x1128 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1129, _ctx); /*10000*/
            _x_x1124 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1125(_ctx), _x_x1128, _ctx); /*10001*/
            _x_x1123 = kk_std_core_types__list_unbox(_x_x1124, KK_OWNED, _ctx); /*list<hot_paths/path-profile>*/
            kk_integer_t _x_x1130;
            kk_box_t _x_x1131;
            kk_box_t _x_x1135;
            kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1136 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(state_2, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
            _x_x1135 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1136, _ctx); /*10000*/
            _x_x1131 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1132(_ctx), _x_x1135, _ctx); /*10001*/
            _x_x1130 = kk_integer_unbox(_x_x1131, _ctx); /*int*/
            kk_integer_t _x_x1137 = kk_integer_add_small_const(x_10071_0, 1, _ctx); /*int*/
            double _x_x1138;
            kk_box_t _x_x1139 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1140(_ctx), kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(state_2, _ctx), _ctx); /*10001*/
            _x_x1138 = kk_double_unbox(_x_x1139, KK_OWNED, _ctx); /*float64*/
            x_3_10125 = kk_whitemagic_dash_koka_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, _x_x1116, _x_x1123, _x_x1130, _x_x1137, _x_x1138, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
          }
          else {
            kk_string_t op_0_0;
            kk_box_t _x_x1143;
            kk_box_t _x_x1147;
            kk_string_t _x_x1148 = kk_string_dup(x_1_10119, _ctx); /*string*/
            _x_x1147 = kk_string_box(_x_x1148); /*10000*/
            _x_x1143 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1144(_ctx), _x_x1147, _ctx); /*10001*/
            op_0_0 = kk_string_unbox(_x_x1143); /*string*/
            if (kk_string_cmp_cstr_borrow(op_0_0, "emit", _ctx) == 0) {
              kk_string_drop(op_0_0, _ctx);
              kk_gan__ying__event_type et_1_0;
              kk_box_t _x_x1150 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1151(_ctx), kk_string_box(x_1_10119), _ctx); /*10001*/
              et_1_0 = kk_gan__ying__event_type_unbox(_x_x1150, KK_OWNED, _ctx); /*gan_ying/event-type*/
              kk_box_t _x_x1154;
              kk_box_t _x_x1179;
              kk_string_t _x_x1180;
              kk_define_string_literal(, _s_x1181, 18, "unified_runtime_v3", _ctx)
              _x_x1180 = kk_string_dup(_s_x1181, _ctx); /*string*/
              _x_x1179 = kk_string_box(_x_x1180); /*10001*/
              _x_x1154 = kk_std_core_hnd__open_none3(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1155(_ctx), kk_gan__ying__event_type_box(et_1_0, _ctx), _x_x1179, kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(state_2, _ctx), _ctx); /*10003*/
              x_3_10125 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_x_x1154, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
              goto _match_x1149;
            }
            if (kk_string_cmp_cstr_borrow(op_0_0, "cascade", _ctx) == 0) {
              kk_string_drop(op_0_0, _ctx);
              kk_gan__ying__event_type et_2_0_0;
              kk_box_t _x_x1182 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1183(_ctx), kk_string_box(x_1_10119), _ctx); /*10001*/
              et_2_0_0 = kk_gan__ying__event_type_unbox(_x_x1182, KK_OWNED, _ctx); /*gan_ying/event-type*/
              kk_std_core_types__tuple2 _match_x414;
              kk_box_t _x_x1186 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1187(_ctx), kk_gan__ying__event_type_box(et_2_0_0, _ctx), kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(state_2, _ctx), _ctx); /*10002*/
              _match_x414 = kk_std_core_types__tuple2_unbox(_x_x1186, KK_OWNED, _ctx); /*(int, whitemagic-koka/src/unified_runtime_v3/unified-state)*/
              {
                kk_box_t _box_x346 = _match_x414.fst;
                kk_box_t _box_x347 = _match_x414.snd;
                kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state ns_0 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_box_x347, KK_BORROWED, _ctx);
                struct kk_whitemagic_dash_koka_src_unified__runtime__v3_Unified_state* _con_x1191 = kk_whitemagic_dash_koka_src_unified__runtime__v3__as_Unified_state(ns_0, _ctx);
                kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_dup(ns_0, _ctx);
                kk_std_core_types__tuple2_drop(_match_x414, _ctx);
                x_3_10125 = ns_0; /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
                goto _match_x1149;
              }
            }
            {
              kk_string_drop(x_1_10119, _ctx);
              kk_string_drop(op_0_0, _ctx);
              x_3_10125 = state_2; /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
            }
            _match_x1149: ;
          }
          if (kk_yielding(kk_context())) {
            kk_datatype_ptr_dropn(x_3_10125, (KK_I32(4)), _ctx);
            kk_box_t _x_x1192 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_server_loop_fun1193(_ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x1192); return kk_Unit;
          }
          { // tailcall
            state_2 = x_3_10125;
            goto kk__tailcall;
          }
        }
      }
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1197__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1197(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1197(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1197, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1198__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1198(kk_function_t _fself, kk_function_t _b_x383, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1198(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1198, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1199__t {
  struct kk_function_s _base;
  kk_function_t _b_x383;
};
static kk_unit_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1199(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x384, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1199(kk_function_t _b_x383, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1199__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1199__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1199, kk_context());
  _self->_b_x383 = _b_x383;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1199(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x384, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1199__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1199__t*, _fself, _ctx);
  kk_function_t _b_x383 = _self->_b_x383; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x383, _ctx);}, {}, _ctx)
  kk_box_t _x_x1200 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x383, (_b_x383, _b_x384, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x1200); return kk_Unit;
}
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1198(kk_function_t _fself, kk_function_t _b_x383, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t ___wildcard_x653__45_406 = kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1199(_b_x383, _ctx); /*(hnd/resume-result<2284,()>) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> ()*/;
  kk_function_drop(___wildcard_x653__45_406, _ctx);
  return kk_unit_box(kk_Unit);
}
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1197(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  kk_std_core_exn__exception_drop(x, _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1198(_ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1203__t {
  struct kk_function_s _base;
  kk_function_t _b_x385_400;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1203(kk_function_t _fself, int32_t _b_x386, kk_std_core_hnd__ev _b_x387, kk_box_t _b_x388, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1203(kk_function_t _b_x385_400, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1203__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1203__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1203, kk_context());
  _self->_b_x385_400 = _b_x385_400;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1203(kk_function_t _fself, int32_t _b_x386, kk_std_core_hnd__ev _b_x387, kk_box_t _b_x388, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1203__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1203__t*, _fself, _ctx);
  kk_function_t _b_x385_400 = _self->_b_x385_400; /* (m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 2284 */
  kk_drop_match(_self, {kk_function_dup(_b_x385_400, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x1204 = kk_std_core_exn__exception_unbox(_b_x388, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x385_400, (_b_x385_400, _b_x386, _b_x387, _x_x1204, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1205__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1205(kk_function_t _fself, kk_box_t _b_x396, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1205(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1205, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1205(kk_function_t _fself, kk_box_t _b_x396, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_407 = kk_Unit;
  kk_unit_unbox(_b_x396);
  return kk_unit_box(_res_407);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1206__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1206(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1206(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1206, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1209__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1209(kk_function_t _fself, kk_box_t _b_x392, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1209(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1209, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1209(kk_function_t _fself, kk_box_t _b_x392, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x1210 = kk_Unit;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1211 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_unbox(_b_x392, KK_OWNED, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  kk_whitemagic_dash_koka_src_unified__runtime__v3_server_loop(_x_x1211, _ctx);
  return kk_unit_box(_x_x1210);
}
static kk_box_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main_fun1206(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x1207;
  kk_define_string_literal(, _s_x1208, 117, "{\"status\":\"started\",\"unified_runtime\":true,\"version\":\"3.0\",\"features\":[\"batch_ipc\",\"events\",\"profiling\",\"hot_paths\"]}", _ctx)
  _x_x1207 = kk_string_dup(_s_x1208, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x1207, _ctx);
  kk_ssize_t _b_x389_403 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_box_t _x_x1212;
  kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state _x_x1213 = kk_whitemagic_dash_koka_src_unified__runtime__v3__new_Unified_state(kk_reuse_null, 0, kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), kk_integer_from_small(0), kk_integer_from_small(0), 0x0p+0, _ctx); /*whitemagic-koka/src/unified_runtime_v3/unified-state*/
  _x_x1212 = kk_whitemagic_dash_koka_src_unified__runtime__v3__unified_state_box(_x_x1213, _ctx); /*10000*/
  return kk_std_core_hnd__open_at1(_b_x389_403, kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1209(_ctx), _x_x1212, _ctx);
}

kk_unit_t kk_whitemagic_dash_koka_src_unified__runtime__v3_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_box_t _x_x1196;
  kk_function_t _b_x385_400 = kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1197(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 2284*/;
  kk_std_core_exn__exn _x_x1201;
  kk_std_core_hnd__clause1 _x_x1202 = kk_std_core_hnd__new_Clause1(kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1203(_b_x385_400, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x1201 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x1202, _ctx); /*exn<10005,10006>*/
  _x_x1196 = kk_std_core_exn_exn_fs__handle(_x_x1201, kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1205(_ctx), kk_whitemagic_dash_koka_src_unified__runtime__v3_new_main_fun1206(_ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x1196); return kk_Unit;
}

// initialization
void kk_whitemagic_dash_koka_src_unified__runtime__v3__init(kk_context_t* _ctx){
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
  kk_std_core_list__init(_ctx);
  kk_gan__ying__init(_ctx);
  kk_hot__paths__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_whitemagic_dash_koka_src_unified__runtime__v3__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_hot__paths__done(_ctx);
  kk_gan__ying__done(_ctx);
  kk_std_core_list__done(_ctx);
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
