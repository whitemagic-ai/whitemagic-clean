// Koka generated module: gan_ying, koka version: 3.2.2, platform: 64-bit
#include "gan__ying.h"

kk_gan__ying__resonance_event kk_gan__ying_resonance_event_fs__copy(kk_gan__ying__resonance_event _this, kk_std_core_types__optional source, kk_std_core_types__optional event_type, kk_std_core_types__optional data, kk_std_core_types__optional timestamp, kk_std_core_types__optional confidence, kk_context_t* _ctx) { /* (resonance-event, source : ? string, event-type : ? event-type, data : ? string, timestamp : ? int, confidence : ? float64) -> resonance-event */ 
  kk_string_t _x_x129;
  if (kk_std_core_types__is_Optional(source, _ctx)) {
    kk_box_t _box_x0 = source._cons._Optional.value;
    kk_string_t _uniq_source_229 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_source_229, _ctx);
    kk_std_core_types__optional_drop(source, _ctx);
    _x_x129 = _uniq_source_229; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(source, _ctx);
    {
      struct kk_gan__ying_Resonance_event* _con_x130 = kk_gan__ying__as_Resonance_event(_this, _ctx);
      kk_string_t _x = _con_x130->source;
      kk_string_dup(_x, _ctx);
      _x_x129 = _x; /*string*/
    }
  }
  kk_gan__ying__event_type _x_x131;
  if (kk_std_core_types__is_Optional(event_type, _ctx)) {
    kk_box_t _box_x1 = event_type._cons._Optional.value;
    kk_gan__ying__event_type _uniq_event_type_237 = kk_gan__ying__event_type_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(event_type, _ctx);
    _x_x131 = _uniq_event_type_237; /*gan_ying/event-type*/
  }
  else {
    kk_std_core_types__optional_drop(event_type, _ctx);
    {
      struct kk_gan__ying_Resonance_event* _con_x132 = kk_gan__ying__as_Resonance_event(_this, _ctx);
      kk_gan__ying__event_type _x_0 = _con_x132->event_type;
      _x_x131 = _x_0; /*gan_ying/event-type*/
    }
  }
  kk_string_t _x_x133;
  if (kk_std_core_types__is_Optional(data, _ctx)) {
    kk_box_t _box_x2 = data._cons._Optional.value;
    kk_string_t _uniq_data_245 = kk_string_unbox(_box_x2);
    kk_string_dup(_uniq_data_245, _ctx);
    kk_std_core_types__optional_drop(data, _ctx);
    _x_x133 = _uniq_data_245; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(data, _ctx);
    {
      struct kk_gan__ying_Resonance_event* _con_x134 = kk_gan__ying__as_Resonance_event(_this, _ctx);
      kk_string_t _x_1 = _con_x134->data;
      kk_string_dup(_x_1, _ctx);
      _x_x133 = _x_1; /*string*/
    }
  }
  kk_integer_t _x_x135;
  if (kk_std_core_types__is_Optional(timestamp, _ctx)) {
    kk_box_t _box_x3 = timestamp._cons._Optional.value;
    kk_integer_t _uniq_timestamp_253 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_timestamp_253, _ctx);
    kk_std_core_types__optional_drop(timestamp, _ctx);
    _x_x135 = _uniq_timestamp_253; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(timestamp, _ctx);
    {
      struct kk_gan__ying_Resonance_event* _con_x136 = kk_gan__ying__as_Resonance_event(_this, _ctx);
      kk_integer_t _x_2 = _con_x136->timestamp;
      kk_integer_dup(_x_2, _ctx);
      _x_x135 = _x_2; /*int*/
    }
  }
  double _x_x137;
  if (kk_std_core_types__is_Optional(confidence, _ctx)) {
    kk_box_t _box_x4 = confidence._cons._Optional.value;
    double _uniq_confidence_261 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(confidence, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x137 = _uniq_confidence_261; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(confidence, _ctx);
    {
      struct kk_gan__ying_Resonance_event* _con_x138 = kk_gan__ying__as_Resonance_event(_this, _ctx);
      kk_string_t _pat_0_4 = _con_x138->source;
      kk_string_t _pat_2_4 = _con_x138->data;
      kk_integer_t _pat_3_4 = _con_x138->timestamp;
      double _x_3 = _con_x138->confidence;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_3_4, _ctx);
        kk_string_drop(_pat_2_4, _ctx);
        kk_string_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x137 = _x_3; /*float64*/
    }
  }
  return kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x129, _x_x131, _x_x133, _x_x135, _x_x137, _ctx);
}

kk_gan__ying__cascade_trigger kk_gan__ying_cascade_trigger_fs__copy(kk_gan__ying__cascade_trigger _this, kk_std_core_types__optional event_type, kk_std_core_types__optional handler_count, kk_std_core_types__optional priority, kk_context_t* _ctx) { /* (cascade-trigger, event-type : ? event-type, handler-count : ? int, priority : ? int) -> cascade-trigger */ 
  kk_gan__ying__event_type _x_x142;
  if (kk_std_core_types__is_Optional(event_type, _ctx)) {
    kk_box_t _box_x5 = event_type._cons._Optional.value;
    kk_gan__ying__event_type _uniq_event_type_305 = kk_gan__ying__event_type_unbox(_box_x5, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(event_type, _ctx);
    _x_x142 = _uniq_event_type_305; /*gan_ying/event-type*/
  }
  else {
    kk_std_core_types__optional_drop(event_type, _ctx);
    {
      struct kk_gan__ying_Cascade_trigger* _con_x143 = kk_gan__ying__as_Cascade_trigger(_this, _ctx);
      kk_gan__ying__event_type _x = _con_x143->event_type;
      _x_x142 = _x; /*gan_ying/event-type*/
    }
  }
  kk_integer_t _x_x144;
  if (kk_std_core_types__is_Optional(handler_count, _ctx)) {
    kk_box_t _box_x6 = handler_count._cons._Optional.value;
    kk_integer_t _uniq_handler_count_313 = kk_integer_unbox(_box_x6, _ctx);
    kk_integer_dup(_uniq_handler_count_313, _ctx);
    kk_std_core_types__optional_drop(handler_count, _ctx);
    _x_x144 = _uniq_handler_count_313; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(handler_count, _ctx);
    {
      struct kk_gan__ying_Cascade_trigger* _con_x145 = kk_gan__ying__as_Cascade_trigger(_this, _ctx);
      kk_integer_t _x_0 = _con_x145->handler_count;
      kk_integer_dup(_x_0, _ctx);
      _x_x144 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x146;
  if (kk_std_core_types__is_Optional(priority, _ctx)) {
    kk_box_t _box_x7 = priority._cons._Optional.value;
    kk_integer_t _uniq_priority_321 = kk_integer_unbox(_box_x7, _ctx);
    kk_integer_dup(_uniq_priority_321, _ctx);
    kk_std_core_types__optional_drop(priority, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x146 = _uniq_priority_321; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(priority, _ctx);
    {
      struct kk_gan__ying_Cascade_trigger* _con_x147 = kk_gan__ying__as_Cascade_trigger(_this, _ctx);
      kk_integer_t _pat_1_3 = _con_x147->handler_count;
      kk_integer_t _x_1 = _con_x147->priority;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x146 = _x_1; /*int*/
    }
  }
  return kk_gan__ying__new_Cascade_trigger(kk_reuse_null, 0, _x_x142, _x_x144, _x_x146, _ctx);
}

kk_string_t kk_gan__ying_event_type_to_string(kk_gan__ying__event_type et, kk_context_t* _ctx) { /* (et : event-type) -> string */ 
  if (kk_gan__ying__is_SystemStarted(et, _ctx)) {
    kk_define_string_literal(, _s_x148, 14, "system_started", _ctx)
    return kk_string_dup(_s_x148, _ctx);
  }
  if (kk_gan__ying__is_SystemStopped(et, _ctx)) {
    kk_define_string_literal(, _s_x149, 14, "system_stopped", _ctx)
    return kk_string_dup(_s_x149, _ctx);
  }
  if (kk_gan__ying__is_SystemHealthChanged(et, _ctx)) {
    kk_define_string_literal(, _s_x150, 21, "system_health_changed", _ctx)
    return kk_string_dup(_s_x150, _ctx);
  }
  if (kk_gan__ying__is_MemoryCreated(et, _ctx)) {
    kk_define_string_literal(, _s_x151, 14, "memory_created", _ctx)
    return kk_string_dup(_s_x151, _ctx);
  }
  if (kk_gan__ying__is_MemoryUpdated(et, _ctx)) {
    kk_define_string_literal(, _s_x152, 14, "memory_updated", _ctx)
    return kk_string_dup(_s_x152, _ctx);
  }
  if (kk_gan__ying__is_MemoryRecalled(et, _ctx)) {
    kk_define_string_literal(, _s_x153, 15, "memory_recalled", _ctx)
    return kk_string_dup(_s_x153, _ctx);
  }
  if (kk_gan__ying__is_MemoryConsolidated(et, _ctx)) {
    kk_define_string_literal(, _s_x154, 19, "memory_consolidated", _ctx)
    return kk_string_dup(_s_x154, _ctx);
  }
  if (kk_gan__ying__is_GardenActivated(et, _ctx)) {
    kk_define_string_literal(, _s_x155, 16, "garden_activated", _ctx)
    return kk_string_dup(_s_x155, _ctx);
  }
  if (kk_gan__ying__is_JoyTriggered(et, _ctx)) {
    kk_define_string_literal(, _s_x156, 13, "joy_triggered", _ctx)
    return kk_string_dup(_s_x156, _ctx);
  }
  if (kk_gan__ying__is_WisdomIntegrated(et, _ctx)) {
    kk_define_string_literal(, _s_x157, 17, "wisdom_integrated", _ctx)
    return kk_string_dup(_s_x157, _ctx);
  }
  if (kk_gan__ying__is_ThreatDetected(et, _ctx)) {
    kk_define_string_literal(, _s_x158, 15, "threat_detected", _ctx)
    return kk_string_dup(_s_x158, _ctx);
  }
  if (kk_gan__ying__is_AnomalyDetected(et, _ctx)) {
    kk_define_string_literal(, _s_x159, 16, "anomaly_detected", _ctx)
    return kk_string_dup(_s_x159, _ctx);
  }
  if (kk_gan__ying__is_FlowStateEntered(et, _ctx)) {
    kk_define_string_literal(, _s_x160, 18, "flow_state_entered", _ctx)
    return kk_string_dup(_s_x160, _ctx);
  }
  {
    kk_define_string_literal(, _s_x161, 17, "flow_state_exited", _ctx)
    return kk_string_dup(_s_x161, _ctx);
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
  kk_integer_t _x_x164;
  if (kk_gan__ying__is_MemoryCreated(et, _ctx)) {
    _x_x164 = kk_integer_from_small(3); /*int*/
    goto _match_x165;
  }
  if (kk_gan__ying__is_MemoryUpdated(et, _ctx)) {
    _x_x164 = kk_integer_from_small(2); /*int*/
    goto _match_x165;
  }
  if (kk_gan__ying__is_ThreatDetected(et, _ctx)) {
    _x_x164 = kk_integer_from_small(5); /*int*/
    goto _match_x165;
  }
  {
    _x_x164 = kk_integer_from_small(1); /*int*/
  }
  _match_x165: ;
  kk_integer_t _x_x166;
  if (kk_gan__ying__is_ThreatDetected(et, _ctx)) {
    _x_x166 = kk_integer_from_small(10); /*int*/
    goto _match_x167;
  }
  if (kk_gan__ying__is_MemoryCreated(et, _ctx)) {
    _x_x166 = kk_integer_from_small(5); /*int*/
    goto _match_x167;
  }
  {
    _x_x166 = kk_integer_from_small(1); /*int*/
  }
  _match_x167: ;
  return kk_gan__ying__new_Cascade_trigger(kk_reuse_null, 0, et, _x_x164, _x_x166, _ctx);
}

kk_string_t kk_gan__ying_json_event_response(kk_gan__ying__resonance_event event, kk_context_t* _ctx) { /* (event : resonance-event) -> string */ 
  kk_string_t _x_x177;
  kk_define_string_literal(, _s_x178, 11, "{\"source\":\"", _ctx)
  _x_x177 = kk_string_dup(_s_x178, _ctx); /*string*/
  kk_string_t _x_x179;
  kk_string_t _x_x180;
  {
    struct kk_gan__ying_Resonance_event* _con_x181 = kk_gan__ying__as_Resonance_event(event, _ctx);
    kk_string_t _x = _con_x181->source;
    kk_string_dup(_x, _ctx);
    _x_x180 = _x; /*string*/
  }
  kk_string_t _x_x182;
  kk_string_t _x_x183;
  kk_define_string_literal(, _s_x184, 10, "\",\"type\":\"", _ctx)
  _x_x183 = kk_string_dup(_s_x184, _ctx); /*string*/
  kk_string_t _x_x185;
  kk_string_t _x_x186;
  {
    struct kk_gan__ying_Resonance_event* _con_x187 = kk_gan__ying__as_Resonance_event(event, _ctx);
    kk_gan__ying__event_type _x_0 = _con_x187->event_type;
    if (kk_gan__ying__is_SystemStarted(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x189, 14, "system_started", _ctx)
      _x_x186 = kk_string_dup(_s_x189, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_SystemStopped(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x190, 14, "system_stopped", _ctx)
      _x_x186 = kk_string_dup(_s_x190, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_SystemHealthChanged(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x191, 21, "system_health_changed", _ctx)
      _x_x186 = kk_string_dup(_s_x191, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_MemoryCreated(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x192, 14, "memory_created", _ctx)
      _x_x186 = kk_string_dup(_s_x192, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_MemoryUpdated(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x193, 14, "memory_updated", _ctx)
      _x_x186 = kk_string_dup(_s_x193, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_MemoryRecalled(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x194, 15, "memory_recalled", _ctx)
      _x_x186 = kk_string_dup(_s_x194, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_MemoryConsolidated(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x195, 19, "memory_consolidated", _ctx)
      _x_x186 = kk_string_dup(_s_x195, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_GardenActivated(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x196, 16, "garden_activated", _ctx)
      _x_x186 = kk_string_dup(_s_x196, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_JoyTriggered(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x197, 13, "joy_triggered", _ctx)
      _x_x186 = kk_string_dup(_s_x197, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_WisdomIntegrated(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x198, 17, "wisdom_integrated", _ctx)
      _x_x186 = kk_string_dup(_s_x198, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_ThreatDetected(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x199, 15, "threat_detected", _ctx)
      _x_x186 = kk_string_dup(_s_x199, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_AnomalyDetected(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x200, 16, "anomaly_detected", _ctx)
      _x_x186 = kk_string_dup(_s_x200, _ctx); /*string*/
      goto _match_x188;
    }
    if (kk_gan__ying__is_FlowStateEntered(_x_0, _ctx)) {
      kk_define_string_literal(, _s_x201, 18, "flow_state_entered", _ctx)
      _x_x186 = kk_string_dup(_s_x201, _ctx); /*string*/
      goto _match_x188;
    }
    {
      kk_define_string_literal(, _s_x202, 17, "flow_state_exited", _ctx)
      _x_x186 = kk_string_dup(_s_x202, _ctx); /*string*/
    }
    _match_x188: ;
  }
  kk_string_t _x_x203;
  kk_string_t _x_x204;
  kk_define_string_literal(, _s_x205, 15, "\",\"confidence\":", _ctx)
  _x_x204 = kk_string_dup(_s_x205, _ctx); /*string*/
  kk_string_t _x_x206;
  kk_string_t _x_x207;
  double _x_x208;
  {
    struct kk_gan__ying_Resonance_event* _con_x209 = kk_gan__ying__as_Resonance_event(event, _ctx);
    kk_string_t _pat_0_2 = _con_x209->source;
    kk_string_t _pat_2_2 = _con_x209->data;
    kk_integer_t _pat_3_2 = _con_x209->timestamp;
    double _x_1 = _con_x209->confidence;
    if kk_likely(kk_datatype_ptr_is_unique(event, _ctx)) {
      kk_integer_drop(_pat_3_2, _ctx);
      kk_string_drop(_pat_2_2, _ctx);
      kk_string_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(event, _ctx);
    }
    else {
      kk_datatype_ptr_decref(event, _ctx);
    }
    _x_x208 = _x_1; /*float64*/
  }
  _x_x207 = kk_std_num_float64_show(_x_x208, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x210;
  kk_define_string_literal(, _s_x211, 1, "}", _ctx)
  _x_x210 = kk_string_dup(_s_x211, _ctx); /*string*/
  _x_x206 = kk_std_core_types__lp__plus__plus__rp_(_x_x207, _x_x210, _ctx); /*string*/
  _x_x203 = kk_std_core_types__lp__plus__plus__rp_(_x_x204, _x_x206, _ctx); /*string*/
  _x_x185 = kk_std_core_types__lp__plus__plus__rp_(_x_x186, _x_x203, _ctx); /*string*/
  _x_x182 = kk_std_core_types__lp__plus__plus__rp_(_x_x183, _x_x185, _ctx); /*string*/
  _x_x179 = kk_std_core_types__lp__plus__plus__rp_(_x_x180, _x_x182, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x177, _x_x179, _ctx);
}

kk_string_t kk_gan__ying_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x109;
  kk_string_t _x_x212 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x213;
  kk_define_string_literal(, _s_x214, 6, "\"emit\"", _ctx)
  _x_x213 = kk_string_dup(_s_x214, _ctx); /*string*/
  _match_x109 = kk_string_contains(_x_x212,_x_x213,kk_context()); /*bool*/
  if (_match_x109) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x215, 4, "emit", _ctx)
    return kk_string_dup(_s_x215, _ctx);
  }
  {
    bool _match_x110;
    kk_string_t _x_x216 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x217;
    kk_define_string_literal(, _s_x218, 7, "\"count\"", _ctx)
    _x_x217 = kk_string_dup(_s_x218, _ctx); /*string*/
    _match_x110 = kk_string_contains(_x_x216,_x_x217,kk_context()); /*bool*/
    if (_match_x110) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x219, 5, "count", _ctx)
      return kk_string_dup(_s_x219, _ctx);
    }
    {
      bool _match_x111;
      kk_string_t _x_x220 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x221;
      kk_define_string_literal(, _s_x222, 7, "\"reset\"", _ctx)
      _x_x221 = kk_string_dup(_s_x222, _ctx); /*string*/
      _match_x111 = kk_string_contains(_x_x220,_x_x221,kk_context()); /*bool*/
      if (_match_x111) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x223, 5, "reset", _ctx)
        return kk_string_dup(_s_x223, _ctx);
      }
      {
        bool _match_x112;
        kk_string_t _x_x224 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x225;
        kk_define_string_literal(, _s_x226, 9, "\"cascade\"", _ctx)
        _x_x225 = kk_string_dup(_s_x226, _ctx); /*string*/
        _match_x112 = kk_string_contains(_x_x224,_x_x225,kk_context()); /*bool*/
        if (_match_x112) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x227, 7, "cascade", _ctx)
          return kk_string_dup(_s_x227, _ctx);
        }
        {
          bool _match_x113;
          kk_string_t _x_x228 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x229;
          kk_define_string_literal(, _s_x230, 8, "\"status\"", _ctx)
          _x_x229 = kk_string_dup(_s_x230, _ctx); /*string*/
          _match_x113 = kk_string_contains(_x_x228,_x_x229,kk_context()); /*bool*/
          if (_match_x113) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x231, 6, "status", _ctx)
            return kk_string_dup(_s_x231, _ctx);
          }
          {
            bool _match_x114;
            kk_string_t _x_x232;
            kk_define_string_literal(, _s_x233, 6, "\"quit\"", _ctx)
            _x_x232 = kk_string_dup(_s_x233, _ctx); /*string*/
            _match_x114 = kk_string_contains(line,_x_x232,kk_context()); /*bool*/
            if (_match_x114) {
              kk_define_string_literal(, _s_x234, 4, "quit", _ctx)
              return kk_string_dup(_s_x234, _ctx);
            }
            {
              kk_define_string_literal(, _s_x235, 7, "unknown", _ctx)
              return kk_string_dup(_s_x235, _ctx);
            }
          }
        }
      }
    }
  }
}

kk_gan__ying__event_type kk_gan__ying_extract_type(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> event-type */ 
  bool _match_x103;
  kk_string_t _x_x236 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x237;
  kk_define_string_literal(, _s_x238, 16, "\"system_started\"", _ctx)
  _x_x237 = kk_string_dup(_s_x238, _ctx); /*string*/
  _match_x103 = kk_string_contains(_x_x236,_x_x237,kk_context()); /*bool*/
  if (_match_x103) {
    kk_string_drop(line, _ctx);
    return kk_gan__ying__new_SystemStarted(_ctx);
  }
  {
    bool _match_x104;
    kk_string_t _x_x239 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x240;
    kk_define_string_literal(, _s_x241, 16, "\"system_stopped\"", _ctx)
    _x_x240 = kk_string_dup(_s_x241, _ctx); /*string*/
    _match_x104 = kk_string_contains(_x_x239,_x_x240,kk_context()); /*bool*/
    if (_match_x104) {
      kk_string_drop(line, _ctx);
      return kk_gan__ying__new_SystemStopped(_ctx);
    }
    {
      bool _match_x105;
      kk_string_t _x_x242 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x243;
      kk_define_string_literal(, _s_x244, 16, "\"memory_created\"", _ctx)
      _x_x243 = kk_string_dup(_s_x244, _ctx); /*string*/
      _match_x105 = kk_string_contains(_x_x242,_x_x243,kk_context()); /*bool*/
      if (_match_x105) {
        kk_string_drop(line, _ctx);
        return kk_gan__ying__new_MemoryCreated(_ctx);
      }
      {
        bool _match_x106;
        kk_string_t _x_x245 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x246;
        kk_define_string_literal(, _s_x247, 16, "\"memory_updated\"", _ctx)
        _x_x246 = kk_string_dup(_s_x247, _ctx); /*string*/
        _match_x106 = kk_string_contains(_x_x245,_x_x246,kk_context()); /*bool*/
        if (_match_x106) {
          kk_string_drop(line, _ctx);
          return kk_gan__ying__new_MemoryUpdated(_ctx);
        }
        {
          bool _match_x107;
          kk_string_t _x_x248 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x249;
          kk_define_string_literal(, _s_x250, 17, "\"threat_detected\"", _ctx)
          _x_x249 = kk_string_dup(_s_x250, _ctx); /*string*/
          _match_x107 = kk_string_contains(_x_x248,_x_x249,kk_context()); /*bool*/
          if (_match_x107) {
            kk_string_drop(line, _ctx);
            return kk_gan__ying__new_ThreatDetected(_ctx);
          }
          {
            bool _match_x108;
            kk_string_t _x_x251;
            kk_define_string_literal(, _s_x252, 15, "\"joy_triggered\"", _ctx)
            _x_x251 = kk_string_dup(_s_x252, _ctx); /*string*/
            _match_x108 = kk_string_contains(line,_x_x251,kk_context()); /*bool*/
            if (_match_x108) {
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
struct kk_gan__ying__mlift_server_loop_10157_fun262__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10157_fun262(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10157_fun262(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10157_fun262, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10157_fun262(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x263 = kk_Unit;
  kk_integer_t _x_x264 = kk_integer_unbox(_b_x13, _ctx); /*int*/
  kk_gan__ying_server_loop(_x_x264, _ctx);
  return kk_unit_box(_x_x263);
}

kk_unit_t kk_gan__ying__mlift_server_loop_10157(kk_integer_t event_count, kk_string_t op, kk_string_t _c_x10118, kk_context_t* _ctx) { /* (event-count : int, op : string, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10118, _ctx);
  bool _match_x99;
  kk_string_t _x_x253 = kk_string_dup(op, _ctx); /*string*/
  kk_string_t _x_x254;
  kk_define_string_literal(, _s_x255, 4, "quit", _ctx)
  _x_x254 = kk_string_dup(_s_x255, _ctx); /*string*/
  _match_x99 = kk_string_is_neq(_x_x253,_x_x254,kk_context()); /*bool*/
  if (_match_x99) {
    kk_integer_t x_10159;
    bool _match_x101;
    kk_string_t _x_x256 = kk_string_dup(op, _ctx); /*string*/
    kk_string_t _x_x257;
    kk_define_string_literal(, _s_x258, 4, "emit", _ctx)
    _x_x257 = kk_string_dup(_s_x258, _ctx); /*string*/
    _match_x101 = kk_string_is_eq(_x_x256,_x_x257,kk_context()); /*bool*/
    if (_match_x101) {
      kk_string_drop(op, _ctx);
      kk_integer_drop(event_count, _ctx);
      x_10159 = kk_integer_from_small(0); /*int*/
    }
    else {
      bool _match_x102;
      kk_string_t _x_x259;
      kk_define_string_literal(, _s_x260, 5, "reset", _ctx)
      _x_x259 = kk_string_dup(_s_x260, _ctx); /*string*/
      _match_x102 = kk_string_is_eq(op,_x_x259,kk_context()); /*bool*/
      if (_match_x102) {
        kk_integer_drop(event_count, _ctx);
        x_10159 = kk_integer_from_small(0); /*int*/
      }
      else {
        x_10159 = event_count; /*int*/
      }
    }
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_10159, _ctx);
      kk_box_t _x_x261 = kk_std_core_hnd_yield_extend(kk_gan__ying__new_mlift_server_loop_10157_fun262(_ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x261); return kk_Unit;
    }
    {
      kk_gan__ying_server_loop(x_10159, _ctx); return kk_Unit;
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
struct kk_gan__ying__mlift_server_loop_10158_fun269__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun269(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10158_fun269(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10158_fun269, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun269(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x270;
  kk_string_t _x_x271 = kk_string_unbox(_b_x17); /*string*/
  _x_x270 = kk_gan__ying_extract_op(_x_x271, _ctx); /*string*/
  return kk_string_box(_x_x270);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10158_fun276__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun276(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10158_fun276(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10158_fun276, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun276(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x277;
  kk_string_t _x_x278 = kk_string_unbox(_b_x22); /*string*/
  _x_x277 = kk_gan__ying_extract_type(_x_x278, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x277, _ctx);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10158_fun281__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun281(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10158_fun281(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10158_fun281, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun281(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x282;
  kk_gan__ying__resonance_event _x_x283 = kk_gan__ying__resonance_event_unbox(_b_x27, KK_OWNED, _ctx); /*gan_ying/resonance-event*/
  _x_x282 = kk_gan__ying_json_event_response(_x_x283, _ctx); /*string*/
  return kk_string_box(_x_x282);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10158_fun315__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun315(kk_function_t _fself, kk_box_t _b_x30, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10158_fun315(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10158_fun315, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun315(kk_function_t _fself, kk_box_t _b_x30, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x316;
  kk_string_t _x_x317 = kk_string_unbox(_b_x30); /*string*/
  _x_x316 = kk_gan__ying_extract_type(_x_x317, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x316, _ctx);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10158_fun319__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun319(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10158_fun319(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10158_fun319, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun319(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__cascade_trigger _x_x320;
  kk_gan__ying__event_type _x_x321 = kk_gan__ying__event_type_unbox(_b_x35, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x320 = kk_gan__ying_check_cascade(_x_x321, _ctx); /*gan_ying/cascade-trigger*/
  return kk_gan__ying__cascade_trigger_box(_x_x320, _ctx);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10158_fun343__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_gan__ying__mlift_server_loop_10158_fun343(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_1, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10158_fun343(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying__mlift_server_loop_10158_fun343, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_gan__ying__mlift_server_loop_10158_fun343(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_1, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_gan__ying_Cascade_trigger* _con_x344 = kk_gan__ying__as_Cascade_trigger(_this_1, _ctx);
    kk_integer_t _pat_1_3 = _con_x344->handler_count;
    kk_integer_t _x_1 = _con_x344->priority;
    if kk_likely(kk_datatype_ptr_is_unique(_this_1, _ctx)) {
      kk_integer_drop(_pat_1_3, _ctx);
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
struct kk_gan__ying__mlift_server_loop_10158_fun358__t {
  struct kk_function_s _base;
  kk_function_t _b_x38_43;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun358(kk_function_t _fself, kk_box_t _b_x40, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10158_fun358(kk_function_t _b_x38_43, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10158_fun358__t* _self = kk_function_alloc_as(struct kk_gan__ying__mlift_server_loop_10158_fun358__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying__mlift_server_loop_10158_fun358, kk_context());
  _self->_b_x38_43 = _b_x38_43;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun358(kk_function_t _fself, kk_box_t _b_x40, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10158_fun358__t* _self = kk_function_as(struct kk_gan__ying__mlift_server_loop_10158_fun358__t*, _fself, _ctx);
  kk_function_t _b_x38_43 = _self->_b_x38_43; /* (gan_ying/cascade-trigger) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x38_43, _ctx);}, {}, _ctx)
  kk_integer_t _x_x359;
  kk_gan__ying__cascade_trigger _x_x360 = kk_gan__ying__cascade_trigger_unbox(_b_x40, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/
  _x_x359 = kk_function_call(kk_integer_t, (kk_function_t, kk_gan__ying__cascade_trigger, kk_context_t*), _b_x38_43, (_b_x38_43, _x_x360, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x359, _ctx);
}


// lift anonymous function
struct kk_gan__ying__mlift_server_loop_10158_fun373__t {
  struct kk_function_s _base;
  kk_integer_t event_count_0;
  kk_string_t op_0;
};
static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun373(kk_function_t _fself, kk_box_t _b_x46, kk_context_t* _ctx);
static kk_function_t kk_gan__ying__new_mlift_server_loop_10158_fun373(kk_integer_t event_count_0, kk_string_t op_0, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10158_fun373__t* _self = kk_function_alloc_as(struct kk_gan__ying__mlift_server_loop_10158_fun373__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying__mlift_server_loop_10158_fun373, kk_context());
  _self->event_count_0 = event_count_0;
  _self->op_0 = op_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying__mlift_server_loop_10158_fun373(kk_function_t _fself, kk_box_t _b_x46, kk_context_t* _ctx) {
  struct kk_gan__ying__mlift_server_loop_10158_fun373__t* _self = kk_function_as(struct kk_gan__ying__mlift_server_loop_10158_fun373__t*, _fself, _ctx);
  kk_integer_t event_count_0 = _self->event_count_0; /* int */
  kk_string_t op_0 = _self->op_0; /* string */
  kk_drop_match(_self, {kk_integer_dup(event_count_0, _ctx);kk_string_dup(op_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10118_0_48 = kk_string_unbox(_b_x46); /*string*/;
  kk_unit_t _x_x374 = kk_Unit;
  kk_gan__ying__mlift_server_loop_10157(event_count_0, op_0, _c_x10118_0_48, _ctx);
  return kk_unit_box(_x_x374);
}

kk_unit_t kk_gan__ying__mlift_server_loop_10158(kk_integer_t event_count_0, kk_string_t line, kk_context_t* _ctx) { /* (event-count : int, line : string) -> <console/console,exn> () */ 
  bool _match_x97;
  kk_string_t _x_x265 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x266 = kk_string_empty(); /*string*/
  _match_x97 = kk_string_is_neq(_x_x265,_x_x266,kk_context()); /*bool*/
  if (_match_x97) {
    kk_string_t op_0;
    kk_box_t _x_x268;
    kk_box_t _x_x272;
    kk_string_t _x_x273 = kk_string_dup(line, _ctx); /*string*/
    _x_x272 = kk_string_box(_x_x273); /*9903*/
    _x_x268 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10158_fun269(_ctx), _x_x272, _ctx); /*9904*/
    op_0 = kk_string_unbox(_x_x268); /*string*/
    kk_string_t x_0_10161;
    if (kk_string_cmp_cstr_borrow(op_0, "emit", _ctx) == 0) {
      kk_gan__ying__event_type et;
      kk_box_t _x_x275 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10158_fun276(_ctx), kk_string_box(line), _ctx); /*9904*/
      et = kk_gan__ying__event_type_unbox(_x_x275, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_integer_t new_count;
      kk_integer_t _x_x279 = kk_integer_dup(event_count_0, _ctx); /*int*/
      new_count = kk_integer_add_small_const(_x_x279, 1, _ctx); /*int*/
      kk_integer_drop(new_count, _ctx);
      kk_unit_t keep = kk_Unit;
      kk_evv_set(w,kk_context());
      kk_box_t _x_x280;
      kk_box_t _x_x284;
      kk_gan__ying__resonance_event _x_x285;
      kk_string_t _x_x286;
      kk_define_string_literal(, _s_x287, 3, "ipc", _ctx)
      _x_x286 = kk_string_dup(_s_x287, _ctx); /*string*/
      kk_string_t _x_x288;
      kk_define_string_literal(, _s_x289, 2, "{}", _ctx)
      _x_x288 = kk_string_dup(_s_x289, _ctx); /*string*/
      _x_x285 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x286, et, _x_x288, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
      _x_x284 = kk_gan__ying__resonance_event_box(_x_x285, _ctx); /*9903*/
      _x_x280 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10158_fun281(_ctx), _x_x284, _ctx); /*9904*/
      x_0_10161 = kk_string_unbox(_x_x280); /*string*/
      goto _match_x274;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "count", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_string_t result_10129;
      kk_integer_t _x_x290 = kk_integer_dup(event_count_0, _ctx); /*int*/
      result_10129 = kk_std_core_int_show(_x_x290, _ctx); /*string*/
      kk_string_t _x_x291;
      kk_define_string_literal(, _s_x292, 7, "{\"op\":\"", _ctx)
      _x_x291 = kk_string_dup(_s_x292, _ctx); /*string*/
      kk_string_t _x_x293;
      kk_string_t _x_x294;
      kk_define_string_literal(, _s_x295, 5, "count", _ctx)
      _x_x294 = kk_string_dup(_s_x295, _ctx); /*string*/
      kk_string_t _x_x296;
      kk_string_t _x_x297;
      kk_define_string_literal(, _s_x298, 12, "\",\"result\":\"", _ctx)
      _x_x297 = kk_string_dup(_s_x298, _ctx); /*string*/
      kk_string_t _x_x299;
      kk_string_t _x_x300;
      kk_define_string_literal(, _s_x301, 2, "\"}", _ctx)
      _x_x300 = kk_string_dup(_s_x301, _ctx); /*string*/
      _x_x299 = kk_std_core_types__lp__plus__plus__rp_(result_10129, _x_x300, _ctx); /*string*/
      _x_x296 = kk_std_core_types__lp__plus__plus__rp_(_x_x297, _x_x299, _ctx); /*string*/
      _x_x293 = kk_std_core_types__lp__plus__plus__rp_(_x_x294, _x_x296, _ctx); /*string*/
      x_0_10161 = kk_std_core_types__lp__plus__plus__rp_(_x_x291, _x_x293, _ctx); /*string*/
      goto _match_x274;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "reset", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_string_t result_0_10131;
      kk_integer_t _x_x302 = kk_integer_dup(event_count_0, _ctx); /*int*/
      result_0_10131 = kk_std_core_int_show(_x_x302, _ctx); /*string*/
      kk_string_t _x_x303;
      kk_define_string_literal(, _s_x304, 7, "{\"op\":\"", _ctx)
      _x_x303 = kk_string_dup(_s_x304, _ctx); /*string*/
      kk_string_t _x_x305;
      kk_string_t _x_x306;
      kk_define_string_literal(, _s_x307, 5, "reset", _ctx)
      _x_x306 = kk_string_dup(_s_x307, _ctx); /*string*/
      kk_string_t _x_x308;
      kk_string_t _x_x309;
      kk_define_string_literal(, _s_x310, 12, "\",\"result\":\"", _ctx)
      _x_x309 = kk_string_dup(_s_x310, _ctx); /*string*/
      kk_string_t _x_x311;
      kk_string_t _x_x312;
      kk_define_string_literal(, _s_x313, 2, "\"}", _ctx)
      _x_x312 = kk_string_dup(_s_x313, _ctx); /*string*/
      _x_x311 = kk_std_core_types__lp__plus__plus__rp_(result_0_10131, _x_x312, _ctx); /*string*/
      _x_x308 = kk_std_core_types__lp__plus__plus__rp_(_x_x309, _x_x311, _ctx); /*string*/
      _x_x305 = kk_std_core_types__lp__plus__plus__rp_(_x_x306, _x_x308, _ctx); /*string*/
      x_0_10161 = kk_std_core_types__lp__plus__plus__rp_(_x_x303, _x_x305, _ctx); /*string*/
      goto _match_x274;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "cascade", _ctx) == 0) {
      kk_gan__ying__event_type et_0_0;
      kk_box_t _x_x314 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10158_fun315(_ctx), kk_string_box(line), _ctx); /*9904*/
      et_0_0 = kk_gan__ying__event_type_unbox(_x_x314, KK_OWNED, _ctx); /*gan_ying/event-type*/
      kk_gan__ying__cascade_trigger trigger;
      kk_box_t _x_x318 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10158_fun319(_ctx), kk_gan__ying__event_type_box(et_0_0, _ctx), _ctx); /*9904*/
      trigger = kk_gan__ying__cascade_trigger_unbox(_x_x318, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/
      kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_0 = kk_Unit;
      kk_evv_set(w_0,kk_context());
      kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_1 = kk_Unit;
      kk_evv_set(w_1,kk_context());
      kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_2 = kk_Unit;
      kk_evv_set(w_2,kk_context());
      kk_string_t _x_x322;
      kk_define_string_literal(, _s_x323, 9, "{\"type\":\"", _ctx)
      _x_x322 = kk_string_dup(_s_x323, _ctx); /*string*/
      kk_string_t _x_x324;
      kk_string_t _x_x325;
      {
        struct kk_gan__ying_Cascade_trigger* _con_x326 = kk_gan__ying__as_Cascade_trigger(trigger, _ctx);
        kk_gan__ying__event_type _x = _con_x326->event_type;
        if (kk_gan__ying__is_SystemStarted(_x, _ctx)) {
          kk_define_string_literal(, _s_x328, 14, "system_started", _ctx)
          _x_x325 = kk_string_dup(_s_x328, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_SystemStopped(_x, _ctx)) {
          kk_define_string_literal(, _s_x329, 14, "system_stopped", _ctx)
          _x_x325 = kk_string_dup(_s_x329, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_SystemHealthChanged(_x, _ctx)) {
          kk_define_string_literal(, _s_x330, 21, "system_health_changed", _ctx)
          _x_x325 = kk_string_dup(_s_x330, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_MemoryCreated(_x, _ctx)) {
          kk_define_string_literal(, _s_x331, 14, "memory_created", _ctx)
          _x_x325 = kk_string_dup(_s_x331, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_MemoryUpdated(_x, _ctx)) {
          kk_define_string_literal(, _s_x332, 14, "memory_updated", _ctx)
          _x_x325 = kk_string_dup(_s_x332, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_MemoryRecalled(_x, _ctx)) {
          kk_define_string_literal(, _s_x333, 15, "memory_recalled", _ctx)
          _x_x325 = kk_string_dup(_s_x333, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_MemoryConsolidated(_x, _ctx)) {
          kk_define_string_literal(, _s_x334, 19, "memory_consolidated", _ctx)
          _x_x325 = kk_string_dup(_s_x334, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_GardenActivated(_x, _ctx)) {
          kk_define_string_literal(, _s_x335, 16, "garden_activated", _ctx)
          _x_x325 = kk_string_dup(_s_x335, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_JoyTriggered(_x, _ctx)) {
          kk_define_string_literal(, _s_x336, 13, "joy_triggered", _ctx)
          _x_x325 = kk_string_dup(_s_x336, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_WisdomIntegrated(_x, _ctx)) {
          kk_define_string_literal(, _s_x337, 17, "wisdom_integrated", _ctx)
          _x_x325 = kk_string_dup(_s_x337, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_ThreatDetected(_x, _ctx)) {
          kk_define_string_literal(, _s_x338, 15, "threat_detected", _ctx)
          _x_x325 = kk_string_dup(_s_x338, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_AnomalyDetected(_x, _ctx)) {
          kk_define_string_literal(, _s_x339, 16, "anomaly_detected", _ctx)
          _x_x325 = kk_string_dup(_s_x339, _ctx); /*string*/
          goto _match_x327;
        }
        if (kk_gan__ying__is_FlowStateEntered(_x, _ctx)) {
          kk_define_string_literal(, _s_x340, 18, "flow_state_entered", _ctx)
          _x_x325 = kk_string_dup(_s_x340, _ctx); /*string*/
          goto _match_x327;
        }
        {
          kk_define_string_literal(, _s_x341, 17, "flow_state_exited", _ctx)
          _x_x325 = kk_string_dup(_s_x341, _ctx); /*string*/
        }
        _match_x327: ;
      }
      kk_string_t _x_x342;
      kk_function_t _b_x38_43 = kk_gan__ying__new_mlift_server_loop_10158_fun343(_ctx); /*(gan_ying/cascade-trigger) -> int*/;
      kk_gan__ying__cascade_trigger _b_x39_44 = kk_gan__ying__cascade_trigger_dup(trigger, _ctx); /*gan_ying/cascade-trigger*/;
      kk_string_t _x_x345;
      kk_define_string_literal(, _s_x346, 13, "\",\"handlers\":", _ctx)
      _x_x345 = kk_string_dup(_s_x346, _ctx); /*string*/
      kk_string_t _x_x347;
      kk_string_t _x_x348;
      kk_integer_t _x_x349;
      {
        struct kk_gan__ying_Cascade_trigger* _con_x350 = kk_gan__ying__as_Cascade_trigger(trigger, _ctx);
        kk_integer_t _x_0 = _con_x350->handler_count;
        kk_integer_t _pat_1_2 = _con_x350->priority;
        if kk_likely(kk_datatype_ptr_is_unique(trigger, _ctx)) {
          kk_integer_drop(_pat_1_2, _ctx);
          kk_datatype_ptr_free(trigger, _ctx);
        }
        else {
          kk_integer_dup(_x_0, _ctx);
          kk_datatype_ptr_decref(trigger, _ctx);
        }
        _x_x349 = _x_0; /*int*/
      }
      _x_x348 = kk_std_core_int_show(_x_x349, _ctx); /*string*/
      kk_string_t _x_x351;
      kk_string_t _x_x352;
      kk_define_string_literal(, _s_x353, 12, ",\"priority\":", _ctx)
      _x_x352 = kk_string_dup(_s_x353, _ctx); /*string*/
      kk_string_t _x_x354;
      kk_string_t _x_x355;
      kk_integer_t _x_x356;
      kk_box_t _x_x357 = kk_std_core_hnd__open_none1(kk_gan__ying__new_mlift_server_loop_10158_fun358(_b_x38_43, _ctx), kk_gan__ying__cascade_trigger_box(_b_x39_44, _ctx), _ctx); /*9904*/
      _x_x356 = kk_integer_unbox(_x_x357, _ctx); /*int*/
      _x_x355 = kk_std_core_int_show(_x_x356, _ctx); /*string*/
      kk_string_t _x_x361;
      kk_define_string_literal(, _s_x362, 1, "}", _ctx)
      _x_x361 = kk_string_dup(_s_x362, _ctx); /*string*/
      _x_x354 = kk_std_core_types__lp__plus__plus__rp_(_x_x355, _x_x361, _ctx); /*string*/
      _x_x351 = kk_std_core_types__lp__plus__plus__rp_(_x_x352, _x_x354, _ctx); /*string*/
      _x_x347 = kk_std_core_types__lp__plus__plus__rp_(_x_x348, _x_x351, _ctx); /*string*/
      _x_x342 = kk_std_core_types__lp__plus__plus__rp_(_x_x345, _x_x347, _ctx); /*string*/
      _x_x324 = kk_std_core_types__lp__plus__plus__rp_(_x_x325, _x_x342, _ctx); /*string*/
      x_0_10161 = kk_std_core_types__lp__plus__plus__rp_(_x_x322, _x_x324, _ctx); /*string*/
      goto _match_x274;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_string_t _x_x363;
      kk_define_string_literal(, _s_x364, 24, "{\"status\":\"ok\",\"events\":", _ctx)
      _x_x363 = kk_string_dup(_s_x364, _ctx); /*string*/
      kk_string_t _x_x365;
      kk_string_t _x_x366;
      kk_integer_t _x_x367 = kk_integer_dup(event_count_0, _ctx); /*int*/
      _x_x366 = kk_std_core_int_show(_x_x367, _ctx); /*string*/
      kk_string_t _x_x368;
      kk_define_string_literal(, _s_x369, 1, "}", _ctx)
      _x_x368 = kk_string_dup(_s_x369, _ctx); /*string*/
      _x_x365 = kk_std_core_types__lp__plus__plus__rp_(_x_x366, _x_x368, _ctx); /*string*/
      x_0_10161 = kk_std_core_types__lp__plus__plus__rp_(_x_x363, _x_x365, _ctx); /*string*/
      goto _match_x274;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "quit", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x370, 20, "{\"status\":\"stopped\"}", _ctx)
      x_0_10161 = kk_string_dup(_s_x370, _ctx); /*string*/
      goto _match_x274;
    }
    {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x371, 22, "{\"error\":\"unknown op\"}", _ctx)
      x_0_10161 = kk_string_dup(_s_x371, _ctx); /*string*/
    }
    _match_x274: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10161, _ctx);
      kk_box_t _x_x372 = kk_std_core_hnd_yield_extend(kk_gan__ying__new_mlift_server_loop_10158_fun373(event_count_0, op_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x372); return kk_Unit;
    }
    {
      kk_gan__ying__mlift_server_loop_10157(event_count_0, op_0, x_0_10161, _ctx); return kk_Unit;
    }
  }
  {
    kk_string_drop(line, _ctx);
    kk_integer_drop(event_count_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun376__t {
  struct kk_function_s _base;
  kk_integer_t event_count_1;
};
static kk_box_t kk_gan__ying_server_loop_fun376(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun376(kk_integer_t event_count_1, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun376__t* _self = kk_function_alloc_as(struct kk_gan__ying_server_loop_fun376__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying_server_loop_fun376, kk_context());
  _self->event_count_1 = event_count_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun376(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun376__t* _self = kk_function_as(struct kk_gan__ying_server_loop_fun376__t*, _fself, _ctx);
  kk_integer_t event_count_1 = _self->event_count_1; /* int */
  kk_drop_match(_self, {kk_integer_dup(event_count_1, _ctx);}, {}, _ctx)
  kk_string_t line_0_88 = kk_string_unbox(_b_x50); /*string*/;
  kk_unit_t _x_x377 = kk_Unit;
  kk_gan__ying__mlift_server_loop_10158(event_count_1, line_0_88, _ctx);
  return kk_unit_box(_x_x377);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun382__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun382(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun382(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun382, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun382(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x383;
  kk_string_t _x_x384 = kk_string_unbox(_b_x53); /*string*/
  _x_x383 = kk_gan__ying_extract_op(_x_x384, _ctx); /*string*/
  return kk_string_box(_x_x383);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun389__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun389(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun389(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun389, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun389(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x390;
  kk_string_t _x_x391 = kk_string_unbox(_b_x58); /*string*/
  _x_x390 = kk_gan__ying_extract_type(_x_x391, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x390, _ctx);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun394__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun394(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun394(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun394, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun394(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x395;
  kk_gan__ying__resonance_event _x_x396 = kk_gan__ying__resonance_event_unbox(_b_x63, KK_OWNED, _ctx); /*gan_ying/resonance-event*/
  _x_x395 = kk_gan__ying_json_event_response(_x_x396, _ctx); /*string*/
  return kk_string_box(_x_x395);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun428__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun428(kk_function_t _fself, kk_box_t _b_x66, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun428(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun428, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun428(kk_function_t _fself, kk_box_t _b_x66, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__event_type _x_x429;
  kk_string_t _x_x430 = kk_string_unbox(_b_x66); /*string*/
  _x_x429 = kk_gan__ying_extract_type(_x_x430, _ctx); /*gan_ying/event-type*/
  return kk_gan__ying__event_type_box(_x_x429, _ctx);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun432__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun432(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun432(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun432, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun432(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_gan__ying__cascade_trigger _x_x433;
  kk_gan__ying__event_type _x_x434 = kk_gan__ying__event_type_unbox(_b_x71, KK_OWNED, _ctx); /*gan_ying/event-type*/
  _x_x433 = kk_gan__ying_check_cascade(_x_x434, _ctx); /*gan_ying/cascade-trigger*/
  return kk_gan__ying__cascade_trigger_box(_x_x433, _ctx);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun456__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_gan__ying_server_loop_fun456(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_1_0, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun456(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun456, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_gan__ying_server_loop_fun456(kk_function_t _fself, kk_gan__ying__cascade_trigger _this_1_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_gan__ying_Cascade_trigger* _con_x457 = kk_gan__ying__as_Cascade_trigger(_this_1_0, _ctx);
    kk_integer_t _pat_1_3_0 = _con_x457->handler_count;
    kk_integer_t _x_1_0 = _con_x457->priority;
    if kk_likely(kk_datatype_ptr_is_unique(_this_1_0, _ctx)) {
      kk_integer_drop(_pat_1_3_0, _ctx);
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
struct kk_gan__ying_server_loop_fun471__t {
  struct kk_function_s _base;
  kk_function_t _b_x74_79;
};
static kk_box_t kk_gan__ying_server_loop_fun471(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun471(kk_function_t _b_x74_79, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun471__t* _self = kk_function_alloc_as(struct kk_gan__ying_server_loop_fun471__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying_server_loop_fun471, kk_context());
  _self->_b_x74_79 = _b_x74_79;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun471(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun471__t* _self = kk_function_as(struct kk_gan__ying_server_loop_fun471__t*, _fself, _ctx);
  kk_function_t _b_x74_79 = _self->_b_x74_79; /* (gan_ying/cascade-trigger) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x74_79, _ctx);}, {}, _ctx)
  kk_integer_t _x_x472;
  kk_gan__ying__cascade_trigger _x_x473 = kk_gan__ying__cascade_trigger_unbox(_b_x76, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/
  _x_x472 = kk_function_call(kk_integer_t, (kk_function_t, kk_gan__ying__cascade_trigger, kk_context_t*), _b_x74_79, (_b_x74_79, _x_x473, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x472, _ctx);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun486__t {
  struct kk_function_s _base;
  kk_integer_t event_count_1;
  kk_string_t op_1;
};
static kk_box_t kk_gan__ying_server_loop_fun486(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun486(kk_integer_t event_count_1, kk_string_t op_1, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun486__t* _self = kk_function_alloc_as(struct kk_gan__ying_server_loop_fun486__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_gan__ying_server_loop_fun486, kk_context());
  _self->event_count_1 = event_count_1;
  _self->op_1 = op_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun486(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx) {
  struct kk_gan__ying_server_loop_fun486__t* _self = kk_function_as(struct kk_gan__ying_server_loop_fun486__t*, _fself, _ctx);
  kk_integer_t event_count_1 = _self->event_count_1; /* int */
  kk_string_t op_1 = _self->op_1; /* string */
  kk_drop_match(_self, {kk_integer_dup(event_count_1, _ctx);kk_string_dup(op_1, _ctx);}, {}, _ctx)
  kk_string_t _c_x10118_1_89 = kk_string_unbox(_b_x82); /*string*/;
  kk_unit_t _x_x487 = kk_Unit;
  kk_gan__ying__mlift_server_loop_10157(event_count_1, op_1, _c_x10118_1_89, _ctx);
  return kk_unit_box(_x_x487);
}


// lift anonymous function
struct kk_gan__ying_server_loop_fun497__t {
  struct kk_function_s _base;
};
static kk_box_t kk_gan__ying_server_loop_fun497(kk_function_t _fself, kk_box_t _b_x84, kk_context_t* _ctx);
static kk_function_t kk_gan__ying_new_server_loop_fun497(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_gan__ying_server_loop_fun497, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_gan__ying_server_loop_fun497(kk_function_t _fself, kk_box_t _b_x84, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x498 = kk_Unit;
  kk_integer_t _x_x499 = kk_integer_unbox(_b_x84, _ctx); /*int*/
  kk_gan__ying_server_loop(_x_x499, _ctx);
  return kk_unit_box(_x_x498);
}

kk_unit_t kk_gan__ying_server_loop(kk_integer_t event_count_1, kk_context_t* _ctx) { /* (event-count : int) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_4_10168 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_4_10168, _ctx);
    kk_box_t _x_x375 = kk_std_core_hnd_yield_extend(kk_gan__ying_new_server_loop_fun376(event_count_1, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x375); return kk_Unit;
  }
  {
    bool _match_x91;
    kk_string_t _x_x378 = kk_string_dup(x_4_10168, _ctx); /*string*/
    kk_string_t _x_x379 = kk_string_empty(); /*string*/
    _match_x91 = kk_string_is_neq(_x_x378,_x_x379,kk_context()); /*bool*/
    if (_match_x91) {
      kk_string_t op_1;
      kk_box_t _x_x381;
      kk_box_t _x_x385;
      kk_string_t _x_x386 = kk_string_dup(x_4_10168, _ctx); /*string*/
      _x_x385 = kk_string_box(_x_x386); /*9903*/
      _x_x381 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun382(_ctx), _x_x385, _ctx); /*9904*/
      op_1 = kk_string_unbox(_x_x381); /*string*/
      kk_string_t x_5_10171;
      if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
        kk_gan__ying__event_type et_0;
        kk_box_t _x_x388 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun389(_ctx), kk_string_box(x_4_10168), _ctx); /*9904*/
        et_0 = kk_gan__ying__event_type_unbox(_x_x388, KK_OWNED, _ctx); /*gan_ying/event-type*/
        kk_evv_t w_2_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_integer_t new_count_0;
        kk_integer_t _x_x392 = kk_integer_dup(event_count_1, _ctx); /*int*/
        new_count_0 = kk_integer_add_small_const(_x_x392, 1, _ctx); /*int*/
        kk_integer_drop(new_count_0, _ctx);
        kk_unit_t keep_2_0 = kk_Unit;
        kk_evv_set(w_2_0,kk_context());
        kk_box_t _x_x393;
        kk_box_t _x_x397;
        kk_gan__ying__resonance_event _x_x398;
        kk_string_t _x_x399;
        kk_define_string_literal(, _s_x400, 3, "ipc", _ctx)
        _x_x399 = kk_string_dup(_s_x400, _ctx); /*string*/
        kk_string_t _x_x401;
        kk_define_string_literal(, _s_x402, 2, "{}", _ctx)
        _x_x401 = kk_string_dup(_s_x402, _ctx); /*string*/
        _x_x398 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x399, et_0, _x_x401, kk_integer_from_small(0), 0x1p0, _ctx); /*gan_ying/resonance-event*/
        _x_x397 = kk_gan__ying__resonance_event_box(_x_x398, _ctx); /*9903*/
        _x_x393 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun394(_ctx), _x_x397, _ctx); /*9904*/
        x_5_10171 = kk_string_unbox(_x_x393); /*string*/
        goto _match_x387;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "count", _ctx) == 0) {
        kk_string_drop(x_4_10168, _ctx);
        kk_string_t result_10129_0;
        kk_integer_t _x_x403 = kk_integer_dup(event_count_1, _ctx); /*int*/
        result_10129_0 = kk_std_core_int_show(_x_x403, _ctx); /*string*/
        kk_string_t _x_x404;
        kk_define_string_literal(, _s_x405, 7, "{\"op\":\"", _ctx)
        _x_x404 = kk_string_dup(_s_x405, _ctx); /*string*/
        kk_string_t _x_x406;
        kk_string_t _x_x407;
        kk_define_string_literal(, _s_x408, 5, "count", _ctx)
        _x_x407 = kk_string_dup(_s_x408, _ctx); /*string*/
        kk_string_t _x_x409;
        kk_string_t _x_x410;
        kk_define_string_literal(, _s_x411, 12, "\",\"result\":\"", _ctx)
        _x_x410 = kk_string_dup(_s_x411, _ctx); /*string*/
        kk_string_t _x_x412;
        kk_string_t _x_x413;
        kk_define_string_literal(, _s_x414, 2, "\"}", _ctx)
        _x_x413 = kk_string_dup(_s_x414, _ctx); /*string*/
        _x_x412 = kk_std_core_types__lp__plus__plus__rp_(result_10129_0, _x_x413, _ctx); /*string*/
        _x_x409 = kk_std_core_types__lp__plus__plus__rp_(_x_x410, _x_x412, _ctx); /*string*/
        _x_x406 = kk_std_core_types__lp__plus__plus__rp_(_x_x407, _x_x409, _ctx); /*string*/
        x_5_10171 = kk_std_core_types__lp__plus__plus__rp_(_x_x404, _x_x406, _ctx); /*string*/
        goto _match_x387;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "reset", _ctx) == 0) {
        kk_string_drop(x_4_10168, _ctx);
        kk_string_t result_0_10131_0;
        kk_integer_t _x_x415 = kk_integer_dup(event_count_1, _ctx); /*int*/
        result_0_10131_0 = kk_std_core_int_show(_x_x415, _ctx); /*string*/
        kk_string_t _x_x416;
        kk_define_string_literal(, _s_x417, 7, "{\"op\":\"", _ctx)
        _x_x416 = kk_string_dup(_s_x417, _ctx); /*string*/
        kk_string_t _x_x418;
        kk_string_t _x_x419;
        kk_define_string_literal(, _s_x420, 5, "reset", _ctx)
        _x_x419 = kk_string_dup(_s_x420, _ctx); /*string*/
        kk_string_t _x_x421;
        kk_string_t _x_x422;
        kk_define_string_literal(, _s_x423, 12, "\",\"result\":\"", _ctx)
        _x_x422 = kk_string_dup(_s_x423, _ctx); /*string*/
        kk_string_t _x_x424;
        kk_string_t _x_x425;
        kk_define_string_literal(, _s_x426, 2, "\"}", _ctx)
        _x_x425 = kk_string_dup(_s_x426, _ctx); /*string*/
        _x_x424 = kk_std_core_types__lp__plus__plus__rp_(result_0_10131_0, _x_x425, _ctx); /*string*/
        _x_x421 = kk_std_core_types__lp__plus__plus__rp_(_x_x422, _x_x424, _ctx); /*string*/
        _x_x418 = kk_std_core_types__lp__plus__plus__rp_(_x_x419, _x_x421, _ctx); /*string*/
        x_5_10171 = kk_std_core_types__lp__plus__plus__rp_(_x_x416, _x_x418, _ctx); /*string*/
        goto _match_x387;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
        kk_gan__ying__event_type et_0_0_0;
        kk_box_t _x_x427 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun428(_ctx), kk_string_box(x_4_10168), _ctx); /*9904*/
        et_0_0_0 = kk_gan__ying__event_type_unbox(_x_x427, KK_OWNED, _ctx); /*gan_ying/event-type*/
        kk_gan__ying__cascade_trigger trigger_0;
        kk_box_t _x_x431 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun432(_ctx), kk_gan__ying__event_type_box(et_0_0_0, _ctx), _ctx); /*9904*/
        trigger_0 = kk_gan__ying__cascade_trigger_unbox(_x_x431, KK_OWNED, _ctx); /*gan_ying/cascade-trigger*/
        kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_3 = kk_Unit;
        kk_evv_set(w_3,kk_context());
        kk_evv_t w_4 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_4 = kk_Unit;
        kk_evv_set(w_4,kk_context());
        kk_evv_t w_5 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_5 = kk_Unit;
        kk_evv_set(w_5,kk_context());
        kk_string_t _x_x435;
        kk_define_string_literal(, _s_x436, 9, "{\"type\":\"", _ctx)
        _x_x435 = kk_string_dup(_s_x436, _ctx); /*string*/
        kk_string_t _x_x437;
        kk_string_t _x_x438;
        {
          struct kk_gan__ying_Cascade_trigger* _con_x439 = kk_gan__ying__as_Cascade_trigger(trigger_0, _ctx);
          kk_gan__ying__event_type _x_2 = _con_x439->event_type;
          if (kk_gan__ying__is_SystemStarted(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x441, 14, "system_started", _ctx)
            _x_x438 = kk_string_dup(_s_x441, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_SystemStopped(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x442, 14, "system_stopped", _ctx)
            _x_x438 = kk_string_dup(_s_x442, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_SystemHealthChanged(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x443, 21, "system_health_changed", _ctx)
            _x_x438 = kk_string_dup(_s_x443, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_MemoryCreated(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x444, 14, "memory_created", _ctx)
            _x_x438 = kk_string_dup(_s_x444, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_MemoryUpdated(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x445, 14, "memory_updated", _ctx)
            _x_x438 = kk_string_dup(_s_x445, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_MemoryRecalled(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x446, 15, "memory_recalled", _ctx)
            _x_x438 = kk_string_dup(_s_x446, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_MemoryConsolidated(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x447, 19, "memory_consolidated", _ctx)
            _x_x438 = kk_string_dup(_s_x447, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_GardenActivated(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x448, 16, "garden_activated", _ctx)
            _x_x438 = kk_string_dup(_s_x448, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_JoyTriggered(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x449, 13, "joy_triggered", _ctx)
            _x_x438 = kk_string_dup(_s_x449, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_WisdomIntegrated(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x450, 17, "wisdom_integrated", _ctx)
            _x_x438 = kk_string_dup(_s_x450, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_ThreatDetected(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x451, 15, "threat_detected", _ctx)
            _x_x438 = kk_string_dup(_s_x451, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_AnomalyDetected(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x452, 16, "anomaly_detected", _ctx)
            _x_x438 = kk_string_dup(_s_x452, _ctx); /*string*/
            goto _match_x440;
          }
          if (kk_gan__ying__is_FlowStateEntered(_x_2, _ctx)) {
            kk_define_string_literal(, _s_x453, 18, "flow_state_entered", _ctx)
            _x_x438 = kk_string_dup(_s_x453, _ctx); /*string*/
            goto _match_x440;
          }
          {
            kk_define_string_literal(, _s_x454, 17, "flow_state_exited", _ctx)
            _x_x438 = kk_string_dup(_s_x454, _ctx); /*string*/
          }
          _match_x440: ;
        }
        kk_string_t _x_x455;
        kk_function_t _b_x74_79 = kk_gan__ying_new_server_loop_fun456(_ctx); /*(gan_ying/cascade-trigger) -> int*/;
        kk_gan__ying__cascade_trigger _b_x75_80 = kk_gan__ying__cascade_trigger_dup(trigger_0, _ctx); /*gan_ying/cascade-trigger*/;
        kk_string_t _x_x458;
        kk_define_string_literal(, _s_x459, 13, "\",\"handlers\":", _ctx)
        _x_x458 = kk_string_dup(_s_x459, _ctx); /*string*/
        kk_string_t _x_x460;
        kk_string_t _x_x461;
        kk_integer_t _x_x462;
        {
          struct kk_gan__ying_Cascade_trigger* _con_x463 = kk_gan__ying__as_Cascade_trigger(trigger_0, _ctx);
          kk_integer_t _x_0_0 = _con_x463->handler_count;
          kk_integer_t _pat_1_2_0 = _con_x463->priority;
          if kk_likely(kk_datatype_ptr_is_unique(trigger_0, _ctx)) {
            kk_integer_drop(_pat_1_2_0, _ctx);
            kk_datatype_ptr_free(trigger_0, _ctx);
          }
          else {
            kk_integer_dup(_x_0_0, _ctx);
            kk_datatype_ptr_decref(trigger_0, _ctx);
          }
          _x_x462 = _x_0_0; /*int*/
        }
        _x_x461 = kk_std_core_int_show(_x_x462, _ctx); /*string*/
        kk_string_t _x_x464;
        kk_string_t _x_x465;
        kk_define_string_literal(, _s_x466, 12, ",\"priority\":", _ctx)
        _x_x465 = kk_string_dup(_s_x466, _ctx); /*string*/
        kk_string_t _x_x467;
        kk_string_t _x_x468;
        kk_integer_t _x_x469;
        kk_box_t _x_x470 = kk_std_core_hnd__open_none1(kk_gan__ying_new_server_loop_fun471(_b_x74_79, _ctx), kk_gan__ying__cascade_trigger_box(_b_x75_80, _ctx), _ctx); /*9904*/
        _x_x469 = kk_integer_unbox(_x_x470, _ctx); /*int*/
        _x_x468 = kk_std_core_int_show(_x_x469, _ctx); /*string*/
        kk_string_t _x_x474;
        kk_define_string_literal(, _s_x475, 1, "}", _ctx)
        _x_x474 = kk_string_dup(_s_x475, _ctx); /*string*/
        _x_x467 = kk_std_core_types__lp__plus__plus__rp_(_x_x468, _x_x474, _ctx); /*string*/
        _x_x464 = kk_std_core_types__lp__plus__plus__rp_(_x_x465, _x_x467, _ctx); /*string*/
        _x_x460 = kk_std_core_types__lp__plus__plus__rp_(_x_x461, _x_x464, _ctx); /*string*/
        _x_x455 = kk_std_core_types__lp__plus__plus__rp_(_x_x458, _x_x460, _ctx); /*string*/
        _x_x437 = kk_std_core_types__lp__plus__plus__rp_(_x_x438, _x_x455, _ctx); /*string*/
        x_5_10171 = kk_std_core_types__lp__plus__plus__rp_(_x_x435, _x_x437, _ctx); /*string*/
        goto _match_x387;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
        kk_string_drop(x_4_10168, _ctx);
        kk_string_t _x_x476;
        kk_define_string_literal(, _s_x477, 24, "{\"status\":\"ok\",\"events\":", _ctx)
        _x_x476 = kk_string_dup(_s_x477, _ctx); /*string*/
        kk_string_t _x_x478;
        kk_string_t _x_x479;
        kk_integer_t _x_x480 = kk_integer_dup(event_count_1, _ctx); /*int*/
        _x_x479 = kk_std_core_int_show(_x_x480, _ctx); /*string*/
        kk_string_t _x_x481;
        kk_define_string_literal(, _s_x482, 1, "}", _ctx)
        _x_x481 = kk_string_dup(_s_x482, _ctx); /*string*/
        _x_x478 = kk_std_core_types__lp__plus__plus__rp_(_x_x479, _x_x481, _ctx); /*string*/
        x_5_10171 = kk_std_core_types__lp__plus__plus__rp_(_x_x476, _x_x478, _ctx); /*string*/
        goto _match_x387;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "quit", _ctx) == 0) {
        kk_string_drop(x_4_10168, _ctx);
        kk_define_string_literal(, _s_x483, 20, "{\"status\":\"stopped\"}", _ctx)
        x_5_10171 = kk_string_dup(_s_x483, _ctx); /*string*/
        goto _match_x387;
      }
      {
        kk_string_drop(x_4_10168, _ctx);
        kk_define_string_literal(, _s_x484, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_5_10171 = kk_string_dup(_s_x484, _ctx); /*string*/
      }
      _match_x387: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_5_10171, _ctx);
        kk_box_t _x_x485 = kk_std_core_hnd_yield_extend(kk_gan__ying_new_server_loop_fun486(event_count_1, op_1, _ctx), _ctx); /*2419*/
        kk_unit_unbox(_x_x485); return kk_Unit;
      }
      {
        kk_unit_t ___0 = kk_Unit;
        kk_std_core_console_printsln(x_5_10171, _ctx);
        bool _match_x93;
        kk_string_t _x_x488 = kk_string_dup(op_1, _ctx); /*string*/
        kk_string_t _x_x489;
        kk_define_string_literal(, _s_x490, 4, "quit", _ctx)
        _x_x489 = kk_string_dup(_s_x490, _ctx); /*string*/
        _match_x93 = kk_string_is_neq(_x_x488,_x_x489,kk_context()); /*bool*/
        if (_match_x93) {
          kk_integer_t x_9_10179;
          bool _match_x95;
          kk_string_t _x_x491 = kk_string_dup(op_1, _ctx); /*string*/
          kk_string_t _x_x492;
          kk_define_string_literal(, _s_x493, 4, "emit", _ctx)
          _x_x492 = kk_string_dup(_s_x493, _ctx); /*string*/
          _match_x95 = kk_string_is_eq(_x_x491,_x_x492,kk_context()); /*bool*/
          if (_match_x95) {
            kk_string_drop(op_1, _ctx);
            kk_integer_drop(event_count_1, _ctx);
            x_9_10179 = kk_integer_from_small(0); /*int*/
          }
          else {
            bool _match_x96;
            kk_string_t _x_x494;
            kk_define_string_literal(, _s_x495, 5, "reset", _ctx)
            _x_x494 = kk_string_dup(_s_x495, _ctx); /*string*/
            _match_x96 = kk_string_is_eq(op_1,_x_x494,kk_context()); /*bool*/
            if (_match_x96) {
              kk_integer_drop(event_count_1, _ctx);
              x_9_10179 = kk_integer_from_small(0); /*int*/
            }
            else {
              x_9_10179 = event_count_1; /*int*/
            }
          }
          if (kk_yielding(kk_context())) {
            kk_integer_drop(x_9_10179, _ctx);
            kk_box_t _x_x496 = kk_std_core_hnd_yield_extend(kk_gan__ying_new_server_loop_fun497(_ctx), _ctx); /*2419*/
            kk_unit_unbox(_x_x496); return kk_Unit;
          }
          { // tailcall
            event_count_1 = x_9_10179;
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
      kk_string_drop(x_4_10168, _ctx);
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
