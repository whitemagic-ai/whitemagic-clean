// Koka generated module: gan_ying, koka version: 3.2.2, platform: 64-bit
#include "gan__ying.h"

kk_gan__ying__resonance_event kk_gan__ying_resonance_event_fs__copy(kk_gan__ying__resonance_event _this, kk_std_core_types__optional source, kk_std_core_types__optional event_type, kk_std_core_types__optional data, kk_std_core_types__optional timestamp, kk_std_core_types__optional confidence, kk_context_t* _ctx) { /* (resonance-event, source : ? string, event-type : ? event-type, data : ? string, timestamp : ? int, confidence : ? float64) -> resonance-event */ 
  kk_string_t _x_x183;
  if (kk_std_core_types__is_Optional(source, _ctx)) {
    kk_box_t _box_x0 = source._cons._Optional.value;
    kk_string_t _uniq_source_229 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_source_229, _ctx);
    kk_std_core_types__optional_drop(source, _ctx);
    _x_x183 = _uniq_source_229; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(source, _ctx);
    {
      struct kk_gan__ying_Resonance_event* _con_x184 = kk_gan__ying__as_Resonance_event(_this, _ctx);
      kk_string_t _x = _con_x184->source;
      kk_string_dup(_x, _ctx);
      _x_x183 = _x; /*string*/
    }
  }
  kk_gan__ying__event_type _x_x185;
  if (kk_std_core_types__is_Optional(event_type, _ctx)) {
    kk_box_t _box_x1 = event_type._cons._Optional.value;
    kk_gan__ying__event_type _uniq_event_type_237 = kk_gan__ying__event_type_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(event_type, _ctx);
    _x_x185 = _uniq_event_type_237; /*gan_ying/event-type*/
  }
  else {
    kk_std_core_types__optional_drop(event_type, _ctx);
    {
      struct kk_gan__ying_Resonance_event* _con_x186 = kk_gan__ying__as_Resonance_event(_this, _ctx);
      kk_gan__ying__event_type _x_0 = _con_x186->event_type;
      _x_x185 = _x_0; /*gan_ying/event-type*/
    }
  }
  kk_string_t _x_x187;
  if (kk_std_core_types__is_Optional(data, _ctx)) {
    kk_box_t _box_x2 = data._cons._Optional.value;
    kk_string_t _uniq_data_245 = kk_string_unbox(_box_x2);
    kk_string_dup(_uniq_data_245, _ctx);
    kk_std_core_types__optional_drop(data, _ctx);
    _x_x187 = _uniq_data_245; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(data, _ctx);
    {
      struct kk_gan__ying_Resonance_event* _con_x188 = kk_gan__ying__as_Resonance_event(_this, _ctx);
      kk_string_t _x_1 = _con_x188->data;
      kk_string_dup(_x_1, _ctx);
      _x_x187 = _x_1; /*string*/
    }
  }
  kk_integer_t _x_x189;
  if (kk_std_core_types__is_Optional(timestamp, _ctx)) {
    kk_box_t _box_x3 = timestamp._cons._Optional.value;
    kk_integer_t _uniq_timestamp_253 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_timestamp_253, _ctx);
    kk_std_core_types__optional_drop(timestamp, _ctx);
    _x_x189 = _uniq_timestamp_253; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(timestamp, _ctx);
    {
      struct kk_gan__ying_Resonance_event* _con_x190 = kk_gan__ying__as_Resonance_event(_this, _ctx);
      kk_integer_t _x_2 = _con_x190->timestamp;
      kk_integer_dup(_x_2, _ctx);
      _x_x189 = _x_2; /*int*/
    }
  }
  double _x_x191;
  if (kk_std_core_types__is_Optional(confidence, _ctx)) {
    kk_box_t _box_x4 = confidence._cons._Optional.value;
    double _uniq_confidence_261 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(confidence, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x191 = _uniq_confidence_261; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(confidence, _ctx);
    {
      struct kk_gan__ying_Resonance_event* _con_x192 = kk_gan__ying__as_Resonance_event(_this, _ctx);
      kk_string_t _pat_0_4 = _con_x192->source;
      kk_string_t _pat_2_4 = _con_x192->data;
      kk_integer_t _pat_3_4 = _con_x192->timestamp;
      double _x_3 = _con_x192->confidence;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_3_4, _ctx);
        kk_string_drop(_pat_2_4, _ctx);
        kk_string_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x191 = _x_3; /*float64*/
    }
  }
  return kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x183, _x_x185, _x_x187, _x_x189, _x_x191, _ctx);
}

kk_gan__ying__cascade_trigger kk_gan__ying_cascade_trigger_fs__copy(kk_gan__ying__cascade_trigger _this, kk_std_core_types__optional event_type, kk_std_core_types__optional handler_count, kk_std_core_types__optional priority, kk_context_t* _ctx) { /* (cascade-trigger, event-type : ? event-type, handler-count : ? int, priority : ? int) -> cascade-trigger */ 
  kk_gan__ying__event_type _x_x196;
  if (kk_std_core_types__is_Optional(event_type, _ctx)) {
    kk_box_t _box_x5 = event_type._cons._Optional.value;
    kk_gan__ying__event_type _uniq_event_type_305 = kk_gan__ying__event_type_unbox(_box_x5, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(event_type, _ctx);
    _x_x196 = _uniq_event_type_305; /*gan_ying/event-type*/
  }
  else {
    kk_std_core_types__optional_drop(event_type, _ctx);
    {
      struct kk_gan__ying_Cascade_trigger* _con_x197 = kk_gan__ying__as_Cascade_trigger(_this, _ctx);
      kk_gan__ying__event_type _x = _con_x197->event_type;
      _x_x196 = _x; /*gan_ying/event-type*/
    }
  }
  kk_integer_t _x_x198;
  if (kk_std_core_types__is_Optional(handler_count, _ctx)) {
    kk_box_t _box_x6 = handler_count._cons._Optional.value;
    kk_integer_t _uniq_handler_count_313 = kk_integer_unbox(_box_x6, _ctx);
    kk_integer_dup(_uniq_handler_count_313, _ctx);
    kk_std_core_types__optional_drop(handler_count, _ctx);
    _x_x198 = _uniq_handler_count_313; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(handler_count, _ctx);
    {
      struct kk_gan__ying_Cascade_trigger* _con_x199 = kk_gan__ying__as_Cascade_trigger(_this, _ctx);
      kk_integer_t _x_0 = _con_x199->handler_count;
      kk_integer_dup(_x_0, _ctx);
      _x_x198 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x200;
  if (kk_std_core_types__is_Optional(priority, _ctx)) {
    kk_box_t _box_x7 = priority._cons._Optional.value;
    kk_integer_t _uniq_priority_321 = kk_integer_unbox(_box_x7, _ctx);
    kk_integer_dup(_uniq_priority_321, _ctx);
    kk_std_core_types__optional_drop(priority, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x200 = _uniq_priority_321; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(priority, _ctx);
    {
      struct kk_gan__ying_Cascade_trigger* _con_x201 = kk_gan__ying__as_Cascade_trigger(_this, _ctx);
      kk_integer_t _pat_1_3 = _con_x201->handler_count;
      kk_integer_t _x_1 = _con_x201->priority;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x200 = _x_1; /*int*/
    }
  }
  return kk_gan__ying__new_Cascade_trigger(kk_reuse_null, 0, _x_x196, _x_x198, _x_x200, _ctx);
}

kk_string_t kk_gan__ying_event_type_to_string(kk_gan__ying__event_type et, kk_context_t* _ctx) { /* (et : event-type) -> string */ 
  if (kk_gan__ying__is_SystemStarted(et, _ctx)) {
    kk_define_string_literal(, _s_x202, 14, "system_started", _ctx)
    return kk_string_dup(_s_x202, _ctx);
  }
  if (kk_gan__ying__is_SystemStopped(et, _ctx)) {
    kk_define_string_literal(, _s_x203, 14, "system_stopped", _ctx)
    return kk_string_dup(_s_x203, _ctx);
  }
  if (kk_gan__ying__is_SystemHealthChanged(et, _ctx)) {
    kk_define_string_literal(, _s_x204, 21, "system_health_changed", _ctx)
    return kk_string_dup(_s_x204, _ctx);
  }
  if (kk_gan__ying__is_MemoryCreated(et, _ctx)) {
    kk_define_string_literal(, _s_x205, 14, "memory_created", _ctx)
    return kk_string_dup(_s_x205, _ctx);
  }
  if (kk_gan__ying__is_MemoryUpdated(et, _ctx)) {
    kk_define_string_literal(, _s_x206, 14, "memory_updated", _ctx)
    return kk_string_dup(_s_x206, _ctx);
  }
  if (kk_gan__ying__is_MemoryRecalled(et, _ctx)) {
    kk_define_string_literal(, _s_x207, 15, "memory_recalled", _ctx)
    return kk_string_dup(_s_x207, _ctx);
  }
  if (kk_gan__ying__is_MemoryConsolidated(et, _ctx)) {
    kk_define_string_literal(, _s_x208, 19, "memory_consolidated", _ctx)
    return kk_string_dup(_s_x208, _ctx);
  }
  if (kk_gan__ying__is_GardenActivated(et, _ctx)) {
    kk_define_string_literal(, _s_x209, 16, "garden_activated", _ctx)
    return kk_string_dup(_s_x209, _ctx);
  }
  if (kk_gan__ying__is_JoyTriggered(et, _ctx)) {
    kk_define_string_literal(, _s_x210, 13, "joy_triggered", _ctx)
    return kk_string_dup(_s_x210, _ctx);
  }
  if (kk_gan__ying__is_WisdomIntegrated(et, _ctx)) {
    kk_define_string_literal(, _s_x211, 17, "wisdom_integrated", _ctx)
    return kk_string_dup(_s_x211, _ctx);
  }
  if (kk_gan__ying__is_ThreatDetected(et, _ctx)) {
    kk_define_string_literal(, _s_x212, 15, "threat_detected", _ctx)
    return kk_string_dup(_s_x212, _ctx);
  }
  if (kk_gan__ying__is_AnomalyDetected(et, _ctx)) {
    kk_define_string_literal(, _s_x213, 16, "anomaly_detected", _ctx)
    return kk_string_dup(_s_x213, _ctx);
  }
  if (kk_gan__ying__is_FlowStateEntered(et, _ctx)) {
    kk_define_string_literal(, _s_x214, 18, "flow_state_entered", _ctx)
    return kk_string_dup(_s_x214, _ctx);
  }
  {
    kk_define_string_literal(, _s_x215, 17, "flow_state_exited", _ctx)
    return kk_string_dup(_s_x215, _ctx);
  }
}

kk_gan__ying__event_type kk_gan__ying_string_to_event_type(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> event-type */ 
  if (kk_string_cmp_cstr_borrow(s, "system_started", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_SystemStarted(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "system_stopped", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_SystemStopped(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "system_health_changed", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_SystemHealthChanged(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "memory_created", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_MemoryCreated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "memory_updated", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_MemoryUpdated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "memory_recalled", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_MemoryRecalled(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "memory_consolidated", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_MemoryConsolidated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "garden_activated", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_GardenActivated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "joy_triggered", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_JoyTriggered(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "wisdom_integrated", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_WisdomIntegrated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "threat_detected", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_ThreatDetected(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "anomaly_detected", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_AnomalyDetected(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "flow_state_entered", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_FlowStateEntered(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "flow_state_exited", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_FlowStateExited(_ctx);
  }
  {
    kk_string_drop(s, _ctx);
    return kk_gan__ying__new_SystemStarted(_ctx);
  }
}

kk_gan__ying__cascade_trigger kk_gan__ying_check_cascade(kk_gan__ying__event_type et, kk_context_t* _ctx) { /* (et : event-type) -> cascade-trigger */ 
  kk_integer_t _x_x218;
  if (kk_gan__ying__is_MemoryCreated(et, _ctx)) {
    _x_x218 = kk_integer_from_small(3); /*int*/
    goto _match_x219;
  }
  if (kk_gan__ying__is_MemoryUpdated(et, _ctx)) {
    _x_x218 = kk_integer_from_small(2); /*int*/
    goto _match_x219;
  }
  if (kk_gan__ying__is_ThreatDetected(et, _ctx)) {
    _x_x218 = kk_integer_from_small(5); /*int*/
    goto _match_x219;
  }
  {
    _x_x218 = kk_integer_from_small(1); /*int*/
  }
  _match_x219: ;
  kk_integer_t _x_x220;
  if (kk_gan__ying__is_ThreatDetected(et, _ctx)) {
    _x_x220 = kk_integer_from_small(10); /*int*/
    goto _match_x221;
  }
  if (kk_gan__ying__is_MemoryCreated(et, _ctx)) {
    _x_x220 = kk_integer_from_small(5); /*int*/
    goto _match_x221;
  }
  {
    _x_x220 = kk_integer_from_small(1); /*int*/
  }
  _match_x221: ;
  return kk_gan__ying__new_Cascade_trigger(kk_reuse_null, 0, et, _x_x218, _x_x220, _ctx);
}

kk_string_t kk_gan__ying_json_event_response(kk_gan__ying__resonance_event event, kk_context_t* _ctx) { /* (event : resonance-event) -> string */ 
  kk_string_t _x_x231;
  kk_define_string_literal(, _s_x232, 11, "{\"source\":\"", _ctx)
  _x_x231 = kk_string_dup(_s_x232, _ctx); /*string*/
  kk_string_t _x_x233;
  kk_string_t _x_x234;
  {
    struct kk_gan__ying_Resonance_event* _con_x235 = kk_gan__ying__as_Resonance_event(event, _ctx);
    kk_string_t _x = _con_x235->source;
    kk_string_dup(_x, _ctx);
    _x_x234 = _x; /*string*/
  }
  kk_string_t _x_x236;
  kk_string_t _x_x237;
  kk_define_string_literal(, _s_x238, 10, "\",\"type\":\"", _ctx)
  _x_x237 = kk_string_dup(_s_x238, _ctx); /*string*/
  kk_string_t _x_x239;
  kk_string_t _x_x240;
  kk_gan__ying__event_type _x_x241;
  {
    struct kk_gan__ying_Resonance_event* _con_x242 = kk_gan__ying__as_Resonance_event(event, _ctx);
    kk_gan__ying__event_type _x_0 = _con_x242->event_type;
    _x_x241 = _x_0; /*gan_ying/event-type*/
  }
  _x_x240 = kk_gan__ying_event_type_to_string(_x_x241, _ctx); /*string*/
  kk_string_t _x_x243;
  kk_string_t _x_x244;
  kk_define_string_literal(, _s_x245, 15, "\",\"confidence\":", _ctx)
  _x_x244 = kk_string_dup(_s_x245, _ctx); /*string*/
  kk_string_t _x_x246;
  kk_string_t _x_x247;
  double _x_x248;
  {
    struct kk_gan__ying_Resonance_event* _con_x249 = kk_gan__ying__as_Resonance_event(event, _ctx);
    kk_string_t _pat_0_1 = _con_x249->source;
    kk_string_t _pat_2_1 = _con_x249->data;
    kk_integer_t _pat_3_1 = _con_x249->timestamp;
    double _x_1 = _con_x249->confidence;
    if kk_likely(kk_datatype_ptr_is_unique(event, _ctx)) {
      kk_integer_drop(_pat_3_1, _ctx);
      kk_string_drop(_pat_2_1, _ctx);
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(event, _ctx);
    }
    else {
      kk_datatype_ptr_decref(event, _ctx);
    }
    _x_x248 = _x_1; /*float64*/
  }
  _x_x247 = kk_std_num_float64_show(_x_x248, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x250;
  kk_define_string_literal(, _s_x251, 1, "}", _ctx)
  _x_x250 = kk_string_dup(_s_x251, _ctx); /*string*/
  _x_x246 = kk_std_core_types__lp__plus__plus__rp_(_x_x247, _x_x250, _ctx); /*string*/
  _x_x243 = kk_std_core_types__lp__plus__plus__rp_(_x_x244, _x_x246, _ctx); /*string*/
  _x_x239 = kk_std_core_types__lp__plus__plus__rp_(_x_x240, _x_x243, _ctx); /*string*/
  _x_x236 = kk_std_core_types__lp__plus__plus__rp_(_x_x237, _x_x239, _ctx); /*string*/
  _x_x233 = kk_std_core_types__lp__plus__plus__rp_(_x_x234, _x_x236, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x231, _x_x233, _ctx);
}

kk_string_t kk_gan__ying_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x161;
  kk_string_t _x_x252 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x253;
  kk_define_string_literal(, _s_x254, 6, "\"emit\"", _ctx)
  _x_x253 = kk_string_dup(_s_x254, _ctx); /*string*/
  _match_x161 = kk_string_contains(_x_x252,_x_x253,kk_context()); /*bool*/
  if (_match_x161) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x255, 4, "emit", _ctx)
    return kk_string_dup(_s_x255, _ctx);
  }
  {
    bool _match_x162;
    kk_string_t _x_x256 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x257;
    kk_define_string_literal(, _s_x258, 7, "\"count\"", _ctx)
    _x_x257 = kk_string_dup(_s_x258, _ctx); /*string*/
    _match_x162 = kk_string_contains(_x_x256,_x_x257,kk_context()); /*bool*/
    if (_match_x162) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x259, 5, "count", _ctx)
      return kk_string_dup(_s_x259, _ctx);
    }
    {
      bool _match_x163;
      kk_string_t _x_x260 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x261;
      kk_define_string_literal(, _s_x262, 7, "\"reset\"", _ctx)
      _x_x261 = kk_string_dup(_s_x262, _ctx); /*string*/
      _match_x163 = kk_string_contains(_x_x260,_x_x261,kk_context()); /*bool*/
      if (_match_x163) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x263, 5, "reset", _ctx)
        return kk_string_dup(_s_x263, _ctx);
      }
      {
        bool _match_x164;
        kk_string_t _x_x264 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x265;
        kk_define_string_literal(, _s_x266, 9, "\"cascade\"", _ctx)
        _x_x265 = kk_string_dup(_s_x266, _ctx); /*string*/
        _match_x164 = kk_string_contains(_x_x264,_x_x265,kk_context()); /*bool*/
        if (_match_x164) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x267, 7, "cascade", _ctx)
          return kk_string_dup(_s_x267, _ctx);
        }
        {
          bool _match_x165;
          kk_string_t _x_x268 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x269;
          kk_define_string_literal(, _s_x270, 8, "\"status\"", _ctx)
          _x_x269 = kk_string_dup(_s_x270, _ctx); /*string*/
          _match_x165 = kk_string_contains(_x_x268,_x_x269,kk_context()); /*bool*/
          if (_match_x165) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x271, 6, "status", _ctx)
            return kk_string_dup(_s_x271, _ctx);
          }
          {
            bool _match_x166;
            kk_string_t _x_x272;
            kk_define_string_literal(, _s_x273, 6, "\"quit\"", _ctx)
            _x_x272 = kk_string_dup(_s_x273, _ctx); /*string*/
            _match_x166 = kk_string_contains(line,_x_x272,kk_context()); /*bool*/
            if (_match_x166) {
              kk_define_string_literal(, _s_x274, 4, "quit", _ctx)
              return kk_string_dup(_s_x274, _ctx);
            }
            {
              kk_define_string_literal(, _s_x275, 7, "unknown", _ctx)
              return kk_string_dup(_s_x275, _ctx);
            }
          }
        }
      }
    }
  }
}

kk_gan__ying__event_type kk_gan__ying_extract_type(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> event-type */ 
  bool _match_x155;
  kk_string_t _x_x276 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x277;
  kk_define_string_literal(, _s_x278, 16, "\"system_started\"", _ctx)
  _x_x277 = kk_string_dup(_s_x278, _ctx); /*string*/
  _match_x155 = kk_string_contains(_x_x276,_x_x277,kk_context()); /*bool*/
  if (_match_x155) {
    kk_string_drop(line, _ctx);
    return kk_gan__ying__new_SystemStarted(_ctx);
  }
  {
    bool _match_x156;
    kk_string_t _x_x279 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x280;
    kk_define_string_literal(, _s_x281, 16, "\"system_stopped\"", _ctx)
    _x_x280 = kk_string_dup(_s_x281, _ctx); /*string*/
    _match_x156 = kk_string_contains(_x_x279,_x_x280,kk_context()); /*bool*/
    if (_match_x156) {
      kk_string_drop(line, _ctx);
      return kk_gan__ying__new_SystemStopped(_ctx);
    }
    {
      bool _match_x157;
      kk_string_t _x_x282 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x283;
      kk_define_string_literal(, _s_x284, 16, "\"memory_created\"", _ctx)
      _x_x283 = kk_string_dup(_s_x284, _ctx); /*string*/
      _match_x157 = kk_string_contains(_x_x282,_x_x283,kk_context()); /*bool*/
      if (_match_x157) {
        kk_string_drop(line, _ctx);
        return kk_gan__ying__new_MemoryCreated(_ctx);
      }
      {
        bool _match_x158;
        kk_string_t _x_x285 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x286;
        kk_define_string_literal(, _s_x287, 16, "\"memory_updated\"", _ctx)
        _x_x286 = kk_string_dup(_s_x287, _ctx); /*string*/
        _match_x158 = kk_string_contains(_x_x285,_x_x286,kk_context()); /*bool*/
        if (_match_x158) {
          kk_string_drop(line, _ctx);
          return kk_gan__ying__new_MemoryUpdated(_ctx);
        }
        {
          bool _match_x159;
          kk_string_t _x_x288 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x289;
          kk_define_string_literal(, _s_x290, 17, "\"threat_detected\"", _ctx)
          _x_x289 = kk_string_dup(_s_x290, _ctx); /*string*/
          _match_x159 = kk_string_contains(_x_x288,_x_x289,kk_context()); /*bool*/
          if (_match_x159) {
            kk_string_drop(line, _ctx);
            return kk_gan__ying__new_ThreatDetected(_ctx);
          }
          {
            bool _match_x160;
            kk_string_t _x_x291;
            kk_define_string_literal(, _s_x292, 15, "\"joy_triggered\"", _ctx)
            _x_x291 = kk_string_dup(_s_x292, _ctx); /*string*/
            _match_x160 = kk_string_contains(line,_x_x291,kk_context()); /*bool*/
            if (_match_x160) {
              return kk_gan__ying__new_JoyTriggered(_ctx);
            }
            {
              return kk_gan__ying__new_SystemStarted(_ctx);
            }
          }
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10056_fun302__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10056_fun302(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10056_fun302(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10056_fun302, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10056_fun302(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x303 = kk_Unit;
  kk_integer_t _x_x304 = kk_integer_unbox(_b_x13, _ctx); /*int*/
  kk_gan__ying_server_loop(_x_x304, _ctx);
  return kk_unit_box(_x_x303);
}

kk_unit_t kk_gan__ying__mlift_server_loop_10056(kk_integer_t event_count, kk_string_t op, kk_string_t _c_x10017, kk_context_t* _ctx) { /* (event-count : int, op : string, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10017, _ctx);
  bool _match_x151;
  kk_string_t _x_x293 = kk_string_dup(op, _ctx); /*string*/
  kk_string_t _x_x294;
  kk_define_string_literal(, _s_x295, 4, "quit", _ctx)
  _x_x294 = kk_string_dup(_s_x295, _ctx); /*string*/
  _match_x151 = kk_string_is_neq(_x_x293,_x_x294,kk_context()); /*bool*/
  if (_match_x151) {
    kk_integer_t x_10058;
    bool _match_x153;
    kk_string_t _x_x296 = kk_string_dup(op, _ctx); /*string*/
    kk_string_t _x_x297;
    kk_define_string_literal(, _s_x298, 4, "emit", _ctx)
    _x_x297 = kk_string_dup(_s_x298, _ctx); /*string*/
    _match_x153 = kk_string_is_eq(_x_x296,_x_x297,kk_context()); /*bool*/
    if (_match_x153) {
      kk_string_drop(op, _ctx);
      kk_integer_drop(event_count, _ctx);
      x_10058 = kk_integer_from_small(0); /*int*/
    }
    else {
      bool _match_x154;
      kk_string_t _x_x299;
      kk_define_string_literal(, _s_x300, 5, "reset", _ctx)
      _x_x299 = kk_string_dup(_s_x300, _ctx); /*string*/
      _match_x154 = kk_string_is_eq(op,_x_x299,kk_context()); /*bool*/
      if (_match_x154) {
        kk_integer_drop(event_count, _ctx);
        x_10058 = kk_integer_from_small(0); /*int*/
      }
      else {
        x_10058 = event_count; /*int*/
      }
    }
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_10058, _ctx);
      kk_box_t _x_x301 = kk_std_core_hnd_yield_extend(kk_gan__ying__new_mlift_server_loop_10056_fun302(_ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x301); return kk_Unit;
    }
    {
      kk_gan__ying_server_loop(x_10058, _ctx); return kk_Unit;
    }
  }
  {
    kk_string_drop(op, _ctx);
    kk_integer_drop(event_count, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun309__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun309(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun309(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10057_fun309, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun309(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x310;
  kk_string_t _x_x311 = kk_string_unbox(_b_x17); /*string*/
  _x_x310 = kk_gan__ying_extract_op(_x_x311, _ctx); /*string*/
  return kk_string_box(_x_x310);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun316__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun316(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun316(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10057_fun316, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun316(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x317;
  kk_string_t _x_x318 = kk_string_unbox(_b_x22); /*string*/
  _x_x317 = kk_gan__ying_extract_type(_x_x318, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x317, _ctx);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun322__t {
  struct kk_function_s _base;
  kk_integer_t event_count_0;
  kk_gan__ying__event_type et;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun322(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun322(kk_integer_t event_count_0, kk_gan__ying__event_type et, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10057_fun322__t* _self = kk_function_alloc_as(struct kk_gan__ying__mlift_server_loop_10057_fun322__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying__mlift_server_loop_10057_fun322, kk_context());
  _self->event_count_0 = event_count_0;
  _self->et = et;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun322(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10057_fun322__t* _self = kk_function_as(struct kk_gan__ying__mlift_server_loop_10057_fun322__t*, _fself, _ctx);
  kk_integer_t event_count_0 = _self->event_count_0; /* int */
  kk_gan__ying__event_type et = _self->et; /* gan_ying/event-type */
  kk_drop_match(_self, {kk_integer_dup(event_count_0, _ctx);kk_gan__ying__event_type_dup(et, _ctx);}, {}, _ctx)
  kk_integer_t new_count = kk_integer_add_small_const(event_count_0, 1, _ctx); /*int*/;
  kk_std_core_types__tuple2 _x_x323;
  kk_box_t _x_x324;
  kk_gan__ying__resonance_event _x_x325;
  kk_string_t _x_x326;
  kk_define_string_literal(, _s_x327, 3, "ipc", _ctx)
  _x_x326 = kk_string_dup(_s_x327, _ctx); /*string*/
  kk_string_t _x_x328;
  kk_define_string_literal(, _s_x329, 2, "{}", _ctx)
  _x_x328 = kk_string_dup(_s_x329, _ctx); /*string*/
  _x_x325 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x326, et, _x_x328, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x324 = kk_gan__ying__resonance_event_box(_x_x325, _ctx); /*134*/
  _x_x323 = kk_std_core_types__new_Tuple2(_x_x324, kk_integer_box(new_count, _ctx), _ctx); /*(134, 135)*/
  return kk_std_core_types__tuple2_box(_x_x323, _ctx);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun331__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun331(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun331(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10057_fun331, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun331(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x332;
  kk_gan__ying__resonance_event _x_x333 = kk_gan__ying__resonance_event_unbox(_b_x32, KK_OWNED, _ctx); /*gan_ying/resonance-event*/
  _x_x332 = kk_gan__ying_json_event_response(_x_x333, _ctx); /*string*/
  return kk_string_box(_x_x332);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun359__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun359(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun359(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10057_fun359, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun359(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x360;
  kk_string_t _x_x361 = kk_string_unbox(_b_x35); /*string*/
  _x_x360 = kk_gan__ying_extract_type(_x_x361, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x360, _ctx);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun363__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun363(kk_function_t _fself, kk_box_t _b_x40, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun363(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10057_fun363, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun363(kk_function_t _fself, kk_box_t _b_x40, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__cascade_trigger _x_x364;
  kk_gan__ying__event_type _x_x365 = kk_gan__ying__event_type_unbox(_b_x40, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x364 = kk_gan__ying_check_cascade(_x_x365, _ctx); /*gan_ying/cascade-trigger*/
  return kk_gan__ying__cascade_trigger_box(_x_x364, _ctx);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun367__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun367(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun367(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10057_fun367, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun367(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x368;
  kk_gan__ying__cascade_trigger _match_x149 = kk_gan__ying__cascade_trigger_unbox(_b_x45, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/;
  {
    struct kk_gan__ying_Cascade_trigger* _con_x369 = kk_gan__ying__as_Cascade_trigger(_match_x149, _ctx);
    kk_gan__ying__event_type _x = _con_x369->event_type;
    kk_integer_t _pat_0_0_0 = _con_x369->handler_count;
    kk_integer_t _pat_1_0_0 = _con_x369->priority;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x149, _ctx)) {
      kk_integer_drop(_pat_1_0_0, _ctx);
      kk_integer_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(_match_x149, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x149, _ctx);
    }
    _x_x368 = _x; /*gan_ying/event-type*/
  }
  return kk_gan__ying__event_type_box(_x_x368, _ctx);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun372__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_gan__ying__mlift_server_loop_10057_fun372(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_0, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun372(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10057_fun372, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_gan__ying__mlift_server_loop_10057_fun372(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_gan__ying_Cascade_trigger* _con_x373 = kk_gan__ying__as_Cascade_trigger(_this_0, _ctx);
    kk_integer_t _x_0 = _con_x373->handler_count;
    kk_integer_t _pat_1_1 = _con_x373->priority;
    if kk_likely(kk_datatype_ptr_is_unique(_this_0, _ctx)) {
      kk_integer_drop(_pat_1_1, _ctx);
      kk_datatype_ptr_free(_this_0, _ctx);
    }
    else {
      kk_integer_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_this_0, _ctx);
    }
    return _x_0;
  }
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun379__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun379(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun379(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10057_fun379, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun379(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x380;
  kk_gan__ying__event_type _x_x381 = kk_gan__ying__event_type_unbox(_b_x51, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x380 = kk_gan__ying_event_type_to_string(_x_x381, _ctx); /*string*/
  return kk_string_box(_x_x380);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun383__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_gan__ying__mlift_server_loop_10057_fun383(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_1, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun383(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10057_fun383, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_gan__ying__mlift_server_loop_10057_fun383(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_1, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_gan__ying_Cascade_trigger* _con_x384 = kk_gan__ying__as_Cascade_trigger(_this_1, _ctx);
    kk_integer_t _pat_1_2 = _con_x384->handler_count;
    kk_integer_t _x_1 = _con_x384->priority;
    if kk_likely(kk_datatype_ptr_is_unique(_this_1, _ctx)) {
      kk_integer_drop(_pat_1_2, _ctx);
      kk_datatype_ptr_free(_this_1, _ctx);
    }
    else {
      kk_integer_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_this_1, _ctx);
    }
    return _x_1;
  }
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun391__t {
  struct kk_function_s _base;
  kk_function_t _b_x52_65;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun391(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun391(kk_function_t _b_x52_65, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10057_fun391__t* _self = kk_function_alloc_as(struct kk_gan__ying__mlift_server_loop_10057_fun391__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying__mlift_server_loop_10057_fun391, kk_context());
  _self->_b_x52_65 = _b_x52_65;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun391(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10057_fun391__t* _self = kk_function_as(struct kk_gan__ying__mlift_server_loop_10057_fun391__t*, _fself, _ctx);
  kk_function_t _b_x52_65 = _self->_b_x52_65; /* (gan_ying/cascade-trigger) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x52_65, _ctx);}, {}, _ctx)
  kk_integer_t _x_x392;
  kk_gan__ying__cascade_trigger _x_x393 = kk_gan__ying__cascade_trigger_unbox(_b_x54, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/
  _x_x392 = kk_function_call(kk_integer_t, (kk_function_t, kk_gan__ying__cascade_trigger, kk_context_t*), _b_x52_65, (_b_x52_65, _x_x393, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x392, _ctx);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun401__t {
  struct kk_function_s _base;
  kk_function_t _b_x55_67;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun401(kk_function_t _fself, kk_box_t _b_x57, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun401(kk_function_t _b_x55_67, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10057_fun401__t* _self = kk_function_alloc_as(struct kk_gan__ying__mlift_server_loop_10057_fun401__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying__mlift_server_loop_10057_fun401, kk_context());
  _self->_b_x55_67 = _b_x55_67;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun401(kk_function_t _fself, kk_box_t _b_x57, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10057_fun401__t* _self = kk_function_as(struct kk_gan__ying__mlift_server_loop_10057_fun401__t*, _fself, _ctx);
  kk_function_t _b_x55_67 = _self->_b_x55_67; /* (gan_ying/cascade-trigger) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x55_67, _ctx);}, {}, _ctx)
  kk_integer_t _x_x402;
  kk_gan__ying__cascade_trigger _x_x403 = kk_gan__ying__cascade_trigger_unbox(_b_x57, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/
  _x_x402 = kk_function_call(kk_integer_t, (kk_function_t, kk_gan__ying__cascade_trigger, kk_context_t*), _b_x55_67, (_b_x55_67, _x_x403, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x402, _ctx);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10057_fun416__t {
  struct kk_function_s _base;
  kk_integer_t event_count_0;
  kk_string_t op_0;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun416(kk_function_t _fself, kk_box_t _b_x70, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10057_fun416(kk_integer_t event_count_0, kk_string_t op_0, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10057_fun416__t* _self = kk_function_alloc_as(struct kk_gan__ying__mlift_server_loop_10057_fun416__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying__mlift_server_loop_10057_fun416, kk_context());
  _self->event_count_0 = event_count_0;
  _self->op_0 = op_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10057_fun416(kk_function_t _fself, kk_box_t _b_x70, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10057_fun416__t* _self = kk_function_as(struct kk_gan__ying__mlift_server_loop_10057_fun416__t*, _fself, _ctx);
  kk_integer_t event_count_0 = _self->event_count_0; /* int */
  kk_string_t op_0 = _self->op_0; /* string */
  kk_drop_match(_self, {kk_integer_dup(event_count_0, _ctx);kk_string_dup(op_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10017_0_72 = kk_string_unbox(_b_x70); /*string*/;
  kk_unit_t _x_x417 = kk_Unit;
  kk_gan__ying__mlift_server_loop_10056(event_count_0, op_0, _c_x10017_0_72, _ctx);
  return kk_unit_box(_x_x417);
}

kk_unit_t kk_gan__ying__mlift_server_loop_10057(kk_integer_t event_count_0, kk_string_t line, kk_context_t* _ctx) { /* (event-count : int, line : string) -> <console/console,exn> () */ 
  bool _match_x147;
  kk_string_t _x_x305 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x306 = kk_string_empty(); /*string*/
  _match_x147 = kk_string_is_neq(_x_x305,_x_x306,kk_context()); /*bool*/
  if (_match_x147) {
    kk_string_t op_0;
    kk_box_t _x_x308;
    kk_box_t _x_x312;
    kk_string_t _x_x313 = kk_string_dup(line, _ctx); /*string*/
    _x_x312 = kk_string_box(_x_x313); /*9903*/
    _x_x308 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10057_fun309(_ctx), _x_x312, _ctx); /*9904*/
    op_0 = kk_string_unbox(_x_x308); /*string*/
    kk_string_t x_0_10060;
    if (kk_string_cmp_cstr_borrow(op_0, "emit", _ctx) == 0) {
      kk_gan__ying__event_type et;
      kk_box_t _x_x315 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10057_fun316(_ctx), kk_string_box(line), _ctx); /*9904*/
      et = kk_gan__ying__event_type_unbox(_x_x315, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_box_t _x_x319;
      kk_std_core_types__tuple2 _match_x150;
      kk_box_t _x_x320;
      kk_function_t _x_x321;
      kk_integer_dup(event_count_0, _ctx);
      _x_x321 = kk_gan__ying__new_mlift_server_loop_10057_fun322(event_count_0, et, _ctx); /*() -> 9837 9836*/
      _x_x320 = kk_std_core_hnd__open_none0(_x_x321, _ctx); /*9836*/
      _match_x150 = kk_std_core_types__tuple2_unbox(_x_x320, KK_OWNED, _ctx); /*(gan_ying/resonance-event, int)*/
      {
        kk_box_t _box_x28 = _match_x150.fst;
        kk_box_t _box_x29 = _match_x150.snd;
        kk_gan__ying__resonance_event event = kk_gan__ying__resonance_event_unbox(_box_x28, KK_BORROWED, _ctx);
        struct kk_gan__ying_Resonance_event* _con_x330 = kk_gan__ying__as_Resonance_event(event, _ctx);
        kk_gan__ying__resonance_event_dup(event, _ctx);
        kk_std_core_types__tuple2_drop(_match_x150, _ctx);
        _x_x319 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10057_fun331(_ctx), kk_gan__ying__resonance_event_box(event, _ctx), _ctx); /*9904*/
      }
      x_0_10060 = kk_string_unbox(_x_x319); /*string*/
      goto _match_x314;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "count", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_string_t result_10028;
      kk_integer_t _x_x334 = kk_integer_dup(event_count_0, _ctx); /*int*/
      result_10028 = kk_std_core_int_show(_x_x334, _ctx); /*string*/
      kk_string_t _x_x335;
      kk_define_string_literal(, _s_x336, 7, "{\"op\":\"", _ctx)
      _x_x335 = kk_string_dup(_s_x336, _ctx); /*string*/
      kk_string_t _x_x337;
      kk_string_t _x_x338;
      kk_define_string_literal(, _s_x339, 5, "count", _ctx)
      _x_x338 = kk_string_dup(_s_x339, _ctx); /*string*/
      kk_string_t _x_x340;
      kk_string_t _x_x341;
      kk_define_string_literal(, _s_x342, 12, "\",\"result\":\"", _ctx)
      _x_x341 = kk_string_dup(_s_x342, _ctx); /*string*/
      kk_string_t _x_x343;
      kk_string_t _x_x344;
      kk_define_string_literal(, _s_x345, 2, "\"}", _ctx)
      _x_x344 = kk_string_dup(_s_x345, _ctx); /*string*/
      _x_x343 = kk_std_core_types__lp__plus__plus__rp_(result_10028, _x_x344, _ctx); /*string*/
      _x_x340 = kk_std_core_types__lp__plus__plus__rp_(_x_x341, _x_x343, _ctx); /*string*/
      _x_x337 = kk_std_core_types__lp__plus__plus__rp_(_x_x338, _x_x340, _ctx); /*string*/
      x_0_10060 = kk_std_core_types__lp__plus__plus__rp_(_x_x335, _x_x337, _ctx); /*string*/
      goto _match_x314;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "reset", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_string_t result_0_10030;
      kk_integer_t _x_x346 = kk_integer_dup(event_count_0, _ctx); /*int*/
      result_0_10030 = kk_std_core_int_show(_x_x346, _ctx); /*string*/
      kk_string_t _x_x347;
      kk_define_string_literal(, _s_x348, 7, "{\"op\":\"", _ctx)
      _x_x347 = kk_string_dup(_s_x348, _ctx); /*string*/
      kk_string_t _x_x349;
      kk_string_t _x_x350;
      kk_define_string_literal(, _s_x351, 5, "reset", _ctx)
      _x_x350 = kk_string_dup(_s_x351, _ctx); /*string*/
      kk_string_t _x_x352;
      kk_string_t _x_x353;
      kk_define_string_literal(, _s_x354, 12, "\",\"result\":\"", _ctx)
      _x_x353 = kk_string_dup(_s_x354, _ctx); /*string*/
      kk_string_t _x_x355;
      kk_string_t _x_x356;
      kk_define_string_literal(, _s_x357, 2, "\"}", _ctx)
      _x_x356 = kk_string_dup(_s_x357, _ctx); /*string*/
      _x_x355 = kk_std_core_types__lp__plus__plus__rp_(result_0_10030, _x_x356, _ctx); /*string*/
      _x_x352 = kk_std_core_types__lp__plus__plus__rp_(_x_x353, _x_x355, _ctx); /*string*/
      _x_x349 = kk_std_core_types__lp__plus__plus__rp_(_x_x350, _x_x352, _ctx); /*string*/
      x_0_10060 = kk_std_core_types__lp__plus__plus__rp_(_x_x347, _x_x349, _ctx); /*string*/
      goto _match_x314;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "cascade", _ctx) == 0) {
      kk_gan__ying__event_type et_0_0;
      kk_box_t _x_x358 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10057_fun359(_ctx), kk_string_box(line), _ctx); /*9904*/
      et_0_0 = kk_gan__ying__event_type_unbox(_x_x358, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_gan__ying__cascade_trigger trigger;
      kk_box_t _x_x362 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10057_fun363(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _ctx); /*9904*/
      trigger = kk_gan__ying__cascade_trigger_unbox(_x_x362, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/
      kk_gan__ying__event_type _x_x1_5_10047;
      kk_box_t _x_x366;
      kk_box_t _x_x370;
      kk_gan__ying__cascade_trigger _x_x371 = kk_gan__ying__cascade_trigger_dup(trigger, _ctx); /*gan_ying/cascade-trigger*/
      _x_x370 = kk_gan__ying__cascade_trigger_box(_x_x371, _ctx); /*9903*/
      _x_x366 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10057_fun367(_ctx), _x_x370, _ctx); /*9904*/
      _x_x1_5_10047 = kk_gan__ying__event_type_unbox(_x_x366, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_function_t _b_x52_65 = kk_gan__ying__new_mlift_server_loop_10057_fun372(_ctx); /*(gan_ying/cascade-trigger) -> int*/;
      kk_gan__ying__cascade_trigger _b_x53_66 = kk_gan__ying__cascade_trigger_dup(trigger, _ctx); /*gan_ying/cascade-trigger*/;
      kk_string_t _x_x374;
      kk_define_string_literal(, _s_x375, 9, "{\"type\":\"", _ctx)
      _x_x374 = kk_string_dup(_s_x375, _ctx); /*string*/
      kk_string_t _x_x376;
      kk_string_t _x_x377;
      kk_box_t _x_x378 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10057_fun379(_ctx), kk_gan__ying__event_type_box(_x_x1_5_10047, _ctx), _ctx); /*9904*/
      _x_x377 = kk_string_unbox(_x_x378); /*string*/
      kk_string_t _x_x382;
      kk_function_t _b_x55_67 = kk_gan__ying__new_mlift_server_loop_10057_fun383(_ctx); /*(gan_ying/cascade-trigger) -> int*/;
      kk_gan__ying__cascade_trigger _b_x56_68 = trigger; /*gan_ying/cascade-trigger*/;
      kk_string_t _x_x385;
      kk_define_string_literal(, _s_x386, 13, "\",\"handlers\":", _ctx)
      _x_x385 = kk_string_dup(_s_x386, _ctx); /*string*/
      kk_string_t _x_x387;
      kk_string_t _x_x388;
      kk_integer_t _x_x389;
      kk_box_t _x_x390 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10057_fun391(_b_x52_65, _ctx), kk_gan__ying__cascade_trigger_box(_b_x53_66, _ctx), _ctx); /*9904*/
      _x_x389 = kk_integer_unbox(_x_x390, _ctx); /*int*/
      _x_x388 = kk_std_core_int_show(_x_x389, _ctx); /*string*/
      kk_string_t _x_x394;
      kk_string_t _x_x395;
      kk_define_string_literal(, _s_x396, 12, ",\"priority\":", _ctx)
      _x_x395 = kk_string_dup(_s_x396, _ctx); /*string*/
      kk_string_t _x_x397;
      kk_string_t _x_x398;
      kk_integer_t _x_x399;
      kk_box_t _x_x400 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10057_fun401(_b_x55_67, _ctx), kk_gan__ying__cascade_trigger_box(_b_x56_68, _ctx), _ctx); /*9904*/
      _x_x399 = kk_integer_unbox(_x_x400, _ctx); /*int*/
      _x_x398 = kk_std_core_int_show(_x_x399, _ctx); /*string*/
      kk_string_t _x_x404;
      kk_define_string_literal(, _s_x405, 1, "}", _ctx)
      _x_x404 = kk_string_dup(_s_x405, _ctx); /*string*/
      _x_x397 = kk_std_core_types__lp__plus__plus__rp_(_x_x398, _x_x404, _ctx); /*string*/
      _x_x394 = kk_std_core_types__lp__plus__plus__rp_(_x_x395, _x_x397, _ctx); /*string*/
      _x_x387 = kk_std_core_types__lp__plus__plus__rp_(_x_x388, _x_x394, _ctx); /*string*/
      _x_x382 = kk_std_core_types__lp__plus__plus__rp_(_x_x385, _x_x387, _ctx); /*string*/
      _x_x376 = kk_std_core_types__lp__plus__plus__rp_(_x_x377, _x_x382, _ctx); /*string*/
      x_0_10060 = kk_std_core_types__lp__plus__plus__rp_(_x_x374, _x_x376, _ctx); /*string*/
      goto _match_x314;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_string_t _x_x406;
      kk_define_string_literal(, _s_x407, 24, "{\"status\":\"ok\",\"events\":", _ctx)
      _x_x406 = kk_string_dup(_s_x407, _ctx); /*string*/
      kk_string_t _x_x408;
      kk_string_t _x_x409;
      kk_integer_t _x_x410 = kk_integer_dup(event_count_0, _ctx); /*int*/
      _x_x409 = kk_std_core_int_show(_x_x410, _ctx); /*string*/
      kk_string_t _x_x411;
      kk_define_string_literal(, _s_x412, 1, "}", _ctx)
      _x_x411 = kk_string_dup(_s_x412, _ctx); /*string*/
      _x_x408 = kk_std_core_types__lp__plus__plus__rp_(_x_x409, _x_x411, _ctx); /*string*/
      x_0_10060 = kk_std_core_types__lp__plus__plus__rp_(_x_x406, _x_x408, _ctx); /*string*/
      goto _match_x314;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "quit", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x413, 20, "{\"status\":\"stopped\"}", _ctx)
      x_0_10060 = kk_string_dup(_s_x413, _ctx); /*string*/
      goto _match_x314;
    }
    {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x414, 22, "{\"error\":\"unknown op\"}", _ctx)
      x_0_10060 = kk_string_dup(_s_x414, _ctx); /*string*/
    }
    _match_x314: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10060, _ctx);
      kk_box_t _x_x415 = kk_std_core_hnd_yield_extend(kk_gan__ying__new_mlift_server_loop_10057_fun416(event_count_0, op_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x415); return kk_Unit;
    }
    {
      kk_gan__ying__mlift_server_loop_10056(event_count_0, op_0, x_0_10060, _ctx); return kk_Unit;
    }
  }
  {
    kk_string_drop(line, _ctx);
    kk_integer_drop(event_count_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun419__t {
  struct kk_function_s _base;
  kk_integer_t event_count_1;
};
static kk_box_t kk_gan__ying_server_loop_fun419(kk_function_t _fself, kk_box_t _b_x74, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun419(kk_integer_t event_count_1, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun419__t* _self = kk_function_alloc_as(struct kk_gan__ying_server_loop_fun419__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying_server_loop_fun419, kk_context());
  _self->event_count_1 = event_count_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun419(kk_function_t _fself, kk_box_t _b_x74, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun419__t* _self = kk_function_as(struct kk_gan__ying_server_loop_fun419__t*, _fself, _ctx);
  kk_integer_t event_count_1 = _self->event_count_1; /* int */
  kk_drop_match(_self, {kk_integer_dup(event_count_1, _ctx);}, {}, _ctx)
  kk_string_t line_0_136 = kk_string_unbox(_b_x74); /*string*/;
  kk_unit_t _x_x420 = kk_Unit;
  kk_gan__ying__mlift_server_loop_10057(event_count_1, line_0_136, _ctx);
  return kk_unit_box(_x_x420);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun425__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun425(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun425(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun425, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun425(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x426;
  kk_string_t _x_x427 = kk_string_unbox(_b_x77); /*string*/
  _x_x426 = kk_gan__ying_extract_op(_x_x427, _ctx); /*string*/
  return kk_string_box(_x_x426);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun432__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun432(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun432(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun432, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun432(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x433;
  kk_string_t _x_x434 = kk_string_unbox(_b_x82); /*string*/
  _x_x433 = kk_gan__ying_extract_type(_x_x434, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x433, _ctx);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun438__t {
  struct kk_function_s _base;
  kk_integer_t event_count_1;
  kk_gan__ying__event_type et_0;
};
static kk_box_t kk_gan__ying_server_loop_fun438(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun438(kk_integer_t event_count_1, kk_gan__ying__event_type et_0, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun438__t* _self = kk_function_alloc_as(struct kk_gan__ying_server_loop_fun438__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying_server_loop_fun438, kk_context());
  _self->event_count_1 = event_count_1;
  _self->et_0 = et_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun438(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun438__t* _self = kk_function_as(struct kk_gan__ying_server_loop_fun438__t*, _fself, _ctx);
  kk_integer_t event_count_1 = _self->event_count_1; /* int */
  kk_gan__ying__event_type et_0 = _self->et_0; /* gan_ying/event-type */
  kk_drop_match(_self, {kk_integer_dup(event_count_1, _ctx);kk_gan__ying__event_type_dup(et_0, _ctx);}, {}, _ctx)
  kk_integer_t new_count_0 = kk_integer_add_small_const(event_count_1, 1, _ctx); /*int*/;
  kk_std_core_types__tuple2 _x_x439;
  kk_box_t _x_x440;
  kk_gan__ying__resonance_event _x_x441;
  kk_string_t _x_x442;
  kk_define_string_literal(, _s_x443, 3, "ipc", _ctx)
  _x_x442 = kk_string_dup(_s_x443, _ctx); /*string*/
  kk_string_t _x_x444;
  kk_define_string_literal(, _s_x445, 2, "{}", _ctx)
  _x_x444 = kk_string_dup(_s_x445, _ctx); /*string*/
  _x_x441 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x442, et_0, _x_x444, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
  _x_x440 = kk_gan__ying__resonance_event_box(_x_x441, _ctx); /*134*/
  _x_x439 = kk_std_core_types__new_Tuple2(_x_x440, kk_integer_box(new_count_0, _ctx), _ctx); /*(134, 135)*/
  return kk_std_core_types__tuple2_box(_x_x439, _ctx);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun447__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun447(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun447(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun447, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun447(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x448;
  kk_gan__ying__resonance_event _x_x449 = kk_gan__ying__resonance_event_unbox(_b_x92, KK_OWNED, _ctx); /*gan_ying/resonance-event*/
  _x_x448 = kk_gan__ying_json_event_response(_x_x449, _ctx); /*string*/
  return kk_string_box(_x_x448);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun475__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun475(kk_function_t _fself, kk_box_t _b_x95, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun475(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun475, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun475(kk_function_t _fself, kk_box_t _b_x95, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x476;
  kk_string_t _x_x477 = kk_string_unbox(_b_x95); /*string*/
  _x_x476 = kk_gan__ying_extract_type(_x_x477, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x476, _ctx);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun479__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun479(kk_function_t _fself, kk_box_t _b_x100, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun479(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun479, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun479(kk_function_t _fself, kk_box_t _b_x100, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__cascade_trigger _x_x480;
  kk_gan__ying__event_type _x_x481 = kk_gan__ying__event_type_unbox(_b_x100, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x480 = kk_gan__ying_check_cascade(_x_x481, _ctx); /*gan_ying/cascade-trigger*/
  return kk_gan__ying__cascade_trigger_box(_x_x480, _ctx);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun483__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun483(kk_function_t _fself, kk_box_t _b_x105, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun483(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun483, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun483(kk_function_t _fself, kk_box_t _b_x105, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x484;
  kk_gan__ying__cascade_trigger _match_x145 = kk_gan__ying__cascade_trigger_unbox(_b_x105, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/;
  {
    struct kk_gan__ying_Cascade_trigger* _con_x485 = kk_gan__ying__as_Cascade_trigger(_match_x145, _ctx);
    kk_gan__ying__event_type _x_2 = _con_x485->event_type;
    kk_integer_t _pat_0_0_1 = _con_x485->handler_count;
    kk_integer_t _pat_1_0_1 = _con_x485->priority;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x145, _ctx)) {
      kk_integer_drop(_pat_1_0_1, _ctx);
      kk_integer_drop(_pat_0_0_1, _ctx);
      kk_datatype_ptr_free(_match_x145, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x145, _ctx);
    }
    _x_x484 = _x_2; /*gan_ying/event-type*/
  }
  return kk_gan__ying__event_type_box(_x_x484, _ctx);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun488__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_gan__ying_server_loop_fun488(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_0_0, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun488(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun488, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_gan__ying_server_loop_fun488(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_0_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_gan__ying_Cascade_trigger* _con_x489 = kk_gan__ying__as_Cascade_trigger(_this_0_0, _ctx);
    kk_integer_t _x_0_0 = _con_x489->handler_count;
    kk_integer_t _pat_1_1_0 = _con_x489->priority;
    if kk_likely(kk_datatype_ptr_is_unique(_this_0_0, _ctx)) {
      kk_integer_drop(_pat_1_1_0, _ctx);
      kk_datatype_ptr_free(_this_0_0, _ctx);
    }
    else {
      kk_integer_dup(_x_0_0, _ctx);
      kk_datatype_ptr_decref(_this_0_0, _ctx);
    }
    return _x_0_0;
  }
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun495__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun495(kk_function_t _fself, kk_box_t _b_x111, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun495(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun495, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun495(kk_function_t _fself, kk_box_t _b_x111, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x496;
  kk_gan__ying__event_type _x_x497 = kk_gan__ying__event_type_unbox(_b_x111, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x496 = kk_gan__ying_event_type_to_string(_x_x497, _ctx); /*string*/
  return kk_string_box(_x_x496);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun499__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_gan__ying_server_loop_fun499(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_1_0, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun499(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun499, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_gan__ying_server_loop_fun499(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_1_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_gan__ying_Cascade_trigger* _con_x500 = kk_gan__ying__as_Cascade_trigger(_this_1_0, _ctx);
    kk_integer_t _pat_1_2_0 = _con_x500->handler_count;
    kk_integer_t _x_1_0 = _con_x500->priority;
    if kk_likely(kk_datatype_ptr_is_unique(_this_1_0, _ctx)) {
      kk_integer_drop(_pat_1_2_0, _ctx);
      kk_datatype_ptr_free(_this_1_0, _ctx);
    }
    else {
      kk_integer_dup(_x_1_0, _ctx);
      kk_datatype_ptr_decref(_this_1_0, _ctx);
    }
    return _x_1_0;
  }
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun507__t {
  struct kk_function_s _base;
  kk_function_t _b_x112_125;
};
static kk_box_t kk_gan__ying_server_loop_fun507(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun507(kk_function_t _b_x112_125, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun507__t* _self = kk_function_alloc_as(struct kk_gan__ying_server_loop_fun507__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying_server_loop_fun507, kk_context());
  _self->_b_x112_125 = _b_x112_125;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun507(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun507__t* _self = kk_function_as(struct kk_gan__ying_server_loop_fun507__t*, _fself, _ctx);
  kk_function_t _b_x112_125 = _self->_b_x112_125; /* (gan_ying/cascade-trigger) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x112_125, _ctx);}, {}, _ctx)
  kk_integer_t _x_x508;
  kk_gan__ying__cascade_trigger _x_x509 = kk_gan__ying__cascade_trigger_unbox(_b_x114, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/
  _x_x508 = kk_function_call(kk_integer_t, (kk_function_t, kk_gan__ying__cascade_trigger, kk_context_t*), _b_x112_125, (_b_x112_125, _x_x509, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x508, _ctx);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun517__t {
  struct kk_function_s _base;
  kk_function_t _b_x115_127;
};
static kk_box_t kk_gan__ying_server_loop_fun517(kk_function_t _fself, kk_box_t _b_x117, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun517(kk_function_t _b_x115_127, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun517__t* _self = kk_function_alloc_as(struct kk_gan__ying_server_loop_fun517__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying_server_loop_fun517, kk_context());
  _self->_b_x115_127 = _b_x115_127;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun517(kk_function_t _fself, kk_box_t _b_x117, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun517__t* _self = kk_function_as(struct kk_gan__ying_server_loop_fun517__t*, _fself, _ctx);
  kk_function_t _b_x115_127 = _self->_b_x115_127; /* (gan_ying/cascade-trigger) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x115_127, _ctx);}, {}, _ctx)
  kk_integer_t _x_x518;
  kk_gan__ying__cascade_trigger _x_x519 = kk_gan__ying__cascade_trigger_unbox(_b_x117, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/
  _x_x518 = kk_function_call(kk_integer_t, (kk_function_t, kk_gan__ying__cascade_trigger, kk_context_t*), _b_x115_127, (_b_x115_127, _x_x519, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x518, _ctx);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun532__t {
  struct kk_function_s _base;
  kk_integer_t event_count_1;
  kk_string_t op_1;
};
static kk_box_t kk_gan__ying_server_loop_fun532(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun532(kk_integer_t event_count_1, kk_string_t op_1, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun532__t* _self = kk_function_alloc_as(struct kk_gan__ying_server_loop_fun532__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying_server_loop_fun532, kk_context());
  _self->event_count_1 = event_count_1;
  _self->op_1 = op_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun532(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun532__t* _self = kk_function_as(struct kk_gan__ying_server_loop_fun532__t*, _fself, _ctx);
  kk_integer_t event_count_1 = _self->event_count_1; /* int */
  kk_string_t op_1 = _self->op_1; /* string */
  kk_drop_match(_self, {kk_integer_dup(event_count_1, _ctx);kk_string_dup(op_1, _ctx);}, {}, _ctx)
  kk_string_t _c_x10017_1_137 = kk_string_unbox(_b_x130); /*string*/;
  kk_unit_t _x_x533 = kk_Unit;
  kk_gan__ying__mlift_server_loop_10056(event_count_1, op_1, _c_x10017_1_137, _ctx);
  return kk_unit_box(_x_x533);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun543__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun543(kk_function_t _fself, kk_box_t _b_x132, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun543(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun543, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun543(kk_function_t _fself, kk_box_t _b_x132, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x544 = kk_Unit;
  kk_integer_t _x_x545 = kk_integer_unbox(_b_x132, _ctx); /*int*/
  kk_gan__ying_server_loop(_x_x545, _ctx);
  return kk_unit_box(_x_x544);
}

kk_unit_t kk_gan__ying_server_loop(kk_integer_t event_count_1, kk_context_t* _ctx) { /* (event-count : int) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_1_10062 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_1_10062, _ctx);
    kk_box_t _x_x418 = kk_std_core_hnd_yield_extend(kk_gan__ying_new_server_loop_fun419(event_count_1, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x418); return kk_Unit;
  }
  {
    bool _match_x139;
    kk_string_t _x_x421 = kk_string_dup(x_1_10062, _ctx); /*string*/
    kk_string_t _x_x422 = kk_string_empty(); /*string*/
    _match_x139 = kk_string_is_neq(_x_x421,_x_x422,kk_context()); /*bool*/
    if (_match_x139) {
      kk_string_t op_1;
      kk_box_t _x_x424;
      kk_box_t _x_x428;
      kk_string_t _x_x429 = kk_string_dup(x_1_10062, _ctx); /*string*/
      _x_x428 = kk_string_box(_x_x429); /*9903*/
      _x_x424 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun425(_ctx), _x_x428, _ctx); /*9904*/
      op_1 = kk_string_unbox(_x_x424); /*string*/
      kk_string_t x_2_10065;
      if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
        kk_gan__ying__event_type et_0;
        kk_box_t _x_x431 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun432(_ctx), kk_string_box(x_1_10062), _ctx); /*9904*/
        et_0 = kk_gan__ying__event_type_unbox(_x_x431, KK_OWNED, _ctx); /*gan_ying/event-type*/
        kk_box_t _x_x435;
        kk_std_core_types__tuple2 _match_x146;
        kk_box_t _x_x436;
        kk_function_t _x_x437;
        kk_integer_dup(event_count_1, _ctx);
        _x_x437 = kk_gan__ying_new_server_loop_fun438(event_count_1, et_0, _ctx); /*() -> 9837 9836*/
        _x_x436 = kk_std_core_hnd__open_none0(_x_x437, _ctx); /*9836*/
        _match_x146 = kk_std_core_types__tuple2_unbox(_x_x436, KK_OWNED, _ctx); /*(gan_ying/resonance-event, int)*/
        {
          kk_box_t _box_x88 = _match_x146.fst;
          kk_box_t _box_x89 = _match_x146.snd;
          kk_gan__ying__resonance_event event_0 = kk_gan__ying__resonance_event_unbox(_box_x88, KK_BORROWED, _ctx);
          struct kk_gan__ying_Resonance_event* _con_x446 = kk_gan__ying__as_Resonance_event(event_0, _ctx);
          kk_gan__ying__resonance_event_dup(event_0, _ctx);
          kk_std_core_types__tuple2_drop(_match_x146, _ctx);
          _x_x435 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun447(_ctx), kk_gan__ying__resonance_event_box(event_0, _ctx), _ctx); /*9904*/
        }
        x_2_10065 = kk_string_unbox(_x_x435); /*string*/
        goto _match_x430;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "count", _ctx) == 0) {
        kk_string_drop(x_1_10062, _ctx);
        kk_string_t result_10028_0;
        kk_integer_t _x_x450 = kk_integer_dup(event_count_1, _ctx); /*int*/
        result_10028_0 = kk_std_core_int_show(_x_x450, _ctx); /*string*/
        kk_string_t _x_x451;
        kk_define_string_literal(, _s_x452, 7, "{\"op\":\"", _ctx)
        _x_x451 = kk_string_dup(_s_x452, _ctx); /*string*/
        kk_string_t _x_x453;
        kk_string_t _x_x454;
        kk_define_string_literal(, _s_x455, 5, "count", _ctx)
        _x_x454 = kk_string_dup(_s_x455, _ctx); /*string*/
        kk_string_t _x_x456;
        kk_string_t _x_x457;
        kk_define_string_literal(, _s_x458, 12, "\",\"result\":\"", _ctx)
        _x_x457 = kk_string_dup(_s_x458, _ctx); /*string*/
        kk_string_t _x_x459;
        kk_string_t _x_x460;
        kk_define_string_literal(, _s_x461, 2, "\"}", _ctx)
        _x_x460 = kk_string_dup(_s_x461, _ctx); /*string*/
        _x_x459 = kk_std_core_types__lp__plus__plus__rp_(result_10028_0, _x_x460, _ctx); /*string*/
        _x_x456 = kk_std_core_types__lp__plus__plus__rp_(_x_x457, _x_x459, _ctx); /*string*/
        _x_x453 = kk_std_core_types__lp__plus__plus__rp_(_x_x454, _x_x456, _ctx); /*string*/
        x_2_10065 = kk_std_core_types__lp__plus__plus__rp_(_x_x451, _x_x453, _ctx); /*string*/
        goto _match_x430;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "reset", _ctx) == 0) {
        kk_string_drop(x_1_10062, _ctx);
        kk_string_t result_0_10030_0;
        kk_integer_t _x_x462 = kk_integer_dup(event_count_1, _ctx); /*int*/
        result_0_10030_0 = kk_std_core_int_show(_x_x462, _ctx); /*string*/
        kk_string_t _x_x463;
        kk_define_string_literal(, _s_x464, 7, "{\"op\":\"", _ctx)
        _x_x463 = kk_string_dup(_s_x464, _ctx); /*string*/
        kk_string_t _x_x465;
        kk_string_t _x_x466;
        kk_define_string_literal(, _s_x467, 5, "reset", _ctx)
        _x_x466 = kk_string_dup(_s_x467, _ctx); /*string*/
        kk_string_t _x_x468;
        kk_string_t _x_x469;
        kk_define_string_literal(, _s_x470, 12, "\",\"result\":\"", _ctx)
        _x_x469 = kk_string_dup(_s_x470, _ctx); /*string*/
        kk_string_t _x_x471;
        kk_string_t _x_x472;
        kk_define_string_literal(, _s_x473, 2, "\"}", _ctx)
        _x_x472 = kk_string_dup(_s_x473, _ctx); /*string*/
        _x_x471 = kk_std_core_types__lp__plus__plus__rp_(result_0_10030_0, _x_x472, _ctx); /*string*/
        _x_x468 = kk_std_core_types__lp__plus__plus__rp_(_x_x469, _x_x471, _ctx); /*string*/
        _x_x465 = kk_std_core_types__lp__plus__plus__rp_(_x_x466, _x_x468, _ctx); /*string*/
        x_2_10065 = kk_std_core_types__lp__plus__plus__rp_(_x_x463, _x_x465, _ctx); /*string*/
        goto _match_x430;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
        kk_gan__ying__event_type et_0_0_0;
        kk_box_t _x_x474 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun475(_ctx), kk_string_box(x_1_10062), _ctx); /*9904*/
        et_0_0_0 = kk_gan__ying__event_type_unbox(_x_x474, KK_OWNED, _ctx); /*gan_ying/event-type*/
        kk_gan__ying__cascade_trigger trigger_0;
        kk_box_t _x_x478 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun479(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _ctx); /*9904*/
        trigger_0 = kk_gan__ying__cascade_trigger_unbox(_x_x478, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/
        kk_gan__ying__event_type _x_x1_5_10047_0;
        kk_box_t _x_x482;
        kk_box_t _x_x486;
        kk_gan__ying__cascade_trigger _x_x487 = kk_gan__ying__cascade_trigger_dup(trigger_0, _ctx); /*gan_ying/cascade-trigger*/
        _x_x486 = kk_gan__ying__cascade_trigger_box(_x_x487, _ctx); /*9903*/
        _x_x482 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun483(_ctx), _x_x486, _ctx); /*9904*/
        _x_x1_5_10047_0 = kk_gan__ying__event_type_unbox(_x_x482, KK_OWNED, _ctx); /*gan_ying/event-type*/
        kk_function_t _b_x112_125 = kk_gan__ying_new_server_loop_fun488(_ctx); /*(gan_ying/cascade-trigger) -> int*/;
        kk_gan__ying__cascade_trigger _b_x113_126 = kk_gan__ying__cascade_trigger_dup(trigger_0, _ctx); /*gan_ying/cascade-trigger*/;
        kk_string_t _x_x490;
        kk_define_string_literal(, _s_x491, 9, "{\"type\":\"", _ctx)
        _x_x490 = kk_string_dup(_s_x491, _ctx); /*string*/
        kk_string_t _x_x492;
        kk_string_t _x_x493;
        kk_box_t _x_x494 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun495(_ctx), kk_gan__ying__event_type_box(_x_x1_5_10047_0, _ctx), _ctx); /*9904*/
        _x_x493 = kk_string_unbox(_x_x494); /*string*/
        kk_string_t _x_x498;
        kk_function_t _b_x115_127 = kk_gan__ying_new_server_loop_fun499(_ctx); /*(gan_ying/cascade-trigger) -> int*/;
        kk_gan__ying__cascade_trigger _b_x116_128 = trigger_0; /*gan_ying/cascade-trigger*/;
        kk_string_t _x_x501;
        kk_define_string_literal(, _s_x502, 13, "\",\"handlers\":", _ctx)
        _x_x501 = kk_string_dup(_s_x502, _ctx); /*string*/
        kk_string_t _x_x503;
        kk_string_t _x_x504;
        kk_integer_t _x_x505;
        kk_box_t _x_x506 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun507(_b_x112_125, _ctx), kk_gan__ying__cascade_trigger_box(_b_x113_126, _ctx), _ctx); /*9904*/
        _x_x505 = kk_integer_unbox(_x_x506, _ctx); /*int*/
        _x_x504 = kk_std_core_int_show(_x_x505, _ctx); /*string*/
        kk_string_t _x_x510;
        kk_string_t _x_x511;
        kk_define_string_literal(, _s_x512, 12, ",\"priority\":", _ctx)
        _x_x511 = kk_string_dup(_s_x512, _ctx); /*string*/
        kk_string_t _x_x513;
        kk_string_t _x_x514;
        kk_integer_t _x_x515;
        kk_box_t _x_x516 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun517(_b_x115_127, _ctx), kk_gan__ying__cascade_trigger_box(_b_x116_128, _ctx), _ctx); /*9904*/
        _x_x515 = kk_integer_unbox(_x_x516, _ctx); /*int*/
        _x_x514 = kk_std_core_int_show(_x_x515, _ctx); /*string*/
        kk_string_t _x_x520;
        kk_define_string_literal(, _s_x521, 1, "}", _ctx)
        _x_x520 = kk_string_dup(_s_x521, _ctx); /*string*/
        _x_x513 = kk_std_core_types__lp__plus__plus__rp_(_x_x514, _x_x520, _ctx); /*string*/
        _x_x510 = kk_std_core_types__lp__plus__plus__rp_(_x_x511, _x_x513, _ctx); /*string*/
        _x_x503 = kk_std_core_types__lp__plus__plus__rp_(_x_x504, _x_x510, _ctx); /*string*/
        _x_x498 = kk_std_core_types__lp__plus__plus__rp_(_x_x501, _x_x503, _ctx); /*string*/
        _x_x492 = kk_std_core_types__lp__plus__plus__rp_(_x_x493, _x_x498, _ctx); /*string*/
        x_2_10065 = kk_std_core_types__lp__plus__plus__rp_(_x_x490, _x_x492, _ctx); /*string*/
        goto _match_x430;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
        kk_string_drop(x_1_10062, _ctx);
        kk_string_t _x_x522;
        kk_define_string_literal(, _s_x523, 24, "{\"status\":\"ok\",\"events\":", _ctx)
        _x_x522 = kk_string_dup(_s_x523, _ctx); /*string*/
        kk_string_t _x_x524;
        kk_string_t _x_x525;
        kk_integer_t _x_x526 = kk_integer_dup(event_count_1, _ctx); /*int*/
        _x_x525 = kk_std_core_int_show(_x_x526, _ctx); /*string*/
        kk_string_t _x_x527;
        kk_define_string_literal(, _s_x528, 1, "}", _ctx)
        _x_x527 = kk_string_dup(_s_x528, _ctx); /*string*/
        _x_x524 = kk_std_core_types__lp__plus__plus__rp_(_x_x525, _x_x527, _ctx); /*string*/
        x_2_10065 = kk_std_core_types__lp__plus__plus__rp_(_x_x522, _x_x524, _ctx); /*string*/
        goto _match_x430;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "quit", _ctx) == 0) {
        kk_string_drop(x_1_10062, _ctx);
        kk_define_string_literal(, _s_x529, 20, "{\"status\":\"stopped\"}", _ctx)
        x_2_10065 = kk_string_dup(_s_x529, _ctx); /*string*/
        goto _match_x430;
      }
      {
        kk_string_drop(x_1_10062, _ctx);
        kk_define_string_literal(, _s_x530, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_2_10065 = kk_string_dup(_s_x530, _ctx); /*string*/
      }
      _match_x430: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_2_10065, _ctx);
        kk_box_t _x_x531 = kk_std_core_hnd_yield_extend(kk_gan__ying_new_server_loop_fun532(event_count_1, op_1, _ctx), _ctx); /*2419*/
        kk_unit_unbox(_x_x531); return kk_Unit;
      }
      {
        kk_unit_t ___0 = kk_Unit;
        kk_std_core_console_printsln(x_2_10065, _ctx);
        bool _match_x141;
        kk_string_t _x_x534 = kk_string_dup(op_1, _ctx); /*string*/
        kk_string_t _x_x535;
        kk_define_string_literal(, _s_x536, 4, "quit", _ctx)
        _x_x535 = kk_string_dup(_s_x536, _ctx); /*string*/
        _match_x141 = kk_string_is_neq(_x_x534,_x_x535,kk_context()); /*bool*/
        if (_match_x141) {
          kk_integer_t x_3_10068;
          bool _match_x143;
          kk_string_t _x_x537 = kk_string_dup(op_1, _ctx); /*string*/
          kk_string_t _x_x538;
          kk_define_string_literal(, _s_x539, 4, "emit", _ctx)
          _x_x538 = kk_string_dup(_s_x539, _ctx); /*string*/
          _match_x143 = kk_string_is_eq(_x_x537,_x_x538,kk_context()); /*bool*/
          if (_match_x143) {
            kk_string_drop(op_1, _ctx);
            kk_integer_drop(event_count_1, _ctx);
            x_3_10068 = kk_integer_from_small(0); /*int*/
          }
          else {
            bool _match_x144;
            kk_string_t _x_x540;
            kk_define_string_literal(, _s_x541, 5, "reset", _ctx)
            _x_x540 = kk_string_dup(_s_x541, _ctx); /*string*/
            _match_x144 = kk_string_is_eq(op_1,_x_x540,kk_context()); /*bool*/
            if (_match_x144) {
              kk_integer_drop(event_count_1, _ctx);
              x_3_10068 = kk_integer_from_small(0); /*int*/
            }
            else {
              x_3_10068 = event_count_1; /*int*/
            }
          }
          if (kk_yielding(kk_context())) {
            kk_integer_drop(x_3_10068, _ctx);
            kk_box_t _x_x542 = kk_std_core_hnd_yield_extend(kk_gan__ying_new_server_loop_fun543(_ctx), _ctx); /*2419*/
            kk_unit_unbox(_x_x542); return kk_Unit;
          }
          { // tailcall
            event_count_1 = x_3_10068;
            goto kk__tailcall;
          }
        }
        {
          kk_string_drop(op_1, _ctx);
          kk_integer_drop(event_count_1, _ctx);
          kk_Unit; return kk_Unit;
        }
      }
    }
    {
      kk_string_drop(x_1_10062, _ctx);
      kk_integer_drop(event_count_1, _ctx);
      kk_Unit; return kk_Unit;
    }
  }
}

// initialization
void kk_gan__ying__init(kk_context_t* _ctx){
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
void kk_gan__ying__done(kk_context_t* _ctx){
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
