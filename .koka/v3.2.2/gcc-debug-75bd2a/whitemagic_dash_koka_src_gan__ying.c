// Koka generated module: whitemagic-koka/src/gan_ying, koka version: 3.2.2, platform: 64-bit
#include "whitemagic_dash_koka_src_gan__ying.h"

kk_whitemagic_dash_koka_src_gan__ying__resonance_event kk_whitemagic_dash_koka_src_gan__ying_resonance_event_fs__copy(kk_whitemagic_dash_koka_src_gan__ying__resonance_event _this, kk_std_core_types__optional source, kk_std_core_types__optional event_type, kk_std_core_types__optional data, kk_std_core_types__optional timestamp, kk_std_core_types__optional confidence, kk_context_t* _ctx) { /* (resonance-event, source : ? string, event-type : ? event-type, data : ? string, timestamp : ? int, confidence : ? float64) -> resonance-event */ 
  kk_string_t _x_x176;
  if (kk_std_core_types__is_Optional(source, _ctx)) {
    kk_box_t _box_x0 = source._cons._Optional.value;
    kk_string_t _uniq_source_231 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_source_231, _ctx);
    kk_std_core_types__optional_drop(source, _ctx);
    _x_x176 = _uniq_source_231; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(source, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_gan__ying_Resonance_event* _con_x177 = kk_whitemagic_dash_koka_src_gan__ying__as_Resonance_event(_this, _ctx);
      kk_string_t _x = _con_x177->source;
      kk_string_dup(_x, _ctx);
      _x_x176 = _x; /*string*/
    }
  }
  kk_whitemagic_dash_koka_src_gan__ying__event_type _x_x178;
  if (kk_std_core_types__is_Optional(event_type, _ctx)) {
    kk_box_t _box_x1 = event_type._cons._Optional.value;
    kk_whitemagic_dash_koka_src_gan__ying__event_type _uniq_event_type_239 = kk_whitemagic_dash_koka_src_gan__ying__event_type_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(event_type, _ctx);
    _x_x178 = _uniq_event_type_239; /*whitemagic-koka/src/gan_ying/event-type*/
  }
  else {
    kk_std_core_types__optional_drop(event_type, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_gan__ying_Resonance_event* _con_x179 = kk_whitemagic_dash_koka_src_gan__ying__as_Resonance_event(_this, _ctx);
      kk_whitemagic_dash_koka_src_gan__ying__event_type _x_0 = _con_x179->event_type;
      _x_x178 = _x_0; /*whitemagic-koka/src/gan_ying/event-type*/
    }
  }
  kk_string_t _x_x180;
  if (kk_std_core_types__is_Optional(data, _ctx)) {
    kk_box_t _box_x2 = data._cons._Optional.value;
    kk_string_t _uniq_data_247 = kk_string_unbox(_box_x2);
    kk_string_dup(_uniq_data_247, _ctx);
    kk_std_core_types__optional_drop(data, _ctx);
    _x_x180 = _uniq_data_247; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(data, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_gan__ying_Resonance_event* _con_x181 = kk_whitemagic_dash_koka_src_gan__ying__as_Resonance_event(_this, _ctx);
      kk_string_t _x_1 = _con_x181->data;
      kk_string_dup(_x_1, _ctx);
      _x_x180 = _x_1; /*string*/
    }
  }
  kk_integer_t _x_x182;
  if (kk_std_core_types__is_Optional(timestamp, _ctx)) {
    kk_box_t _box_x3 = timestamp._cons._Optional.value;
    kk_integer_t _uniq_timestamp_255 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_timestamp_255, _ctx);
    kk_std_core_types__optional_drop(timestamp, _ctx);
    _x_x182 = _uniq_timestamp_255; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(timestamp, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_gan__ying_Resonance_event* _con_x183 = kk_whitemagic_dash_koka_src_gan__ying__as_Resonance_event(_this, _ctx);
      kk_integer_t _x_2 = _con_x183->timestamp;
      kk_integer_dup(_x_2, _ctx);
      _x_x182 = _x_2; /*int*/
    }
  }
  double _x_x184;
  if (kk_std_core_types__is_Optional(confidence, _ctx)) {
    kk_box_t _box_x4 = confidence._cons._Optional.value;
    double _uniq_confidence_263 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(confidence, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x184 = _uniq_confidence_263; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(confidence, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_gan__ying_Resonance_event* _con_x185 = kk_whitemagic_dash_koka_src_gan__ying__as_Resonance_event(_this, _ctx);
      kk_string_t _pat_0_4 = _con_x185->source;
      kk_string_t _pat_2_4 = _con_x185->data;
      kk_integer_t _pat_3_4 = _con_x185->timestamp;
      double _x_3 = _con_x185->confidence;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_3_4, _ctx);
        kk_string_drop(_pat_2_4, _ctx);
        kk_string_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x184 = _x_3; /*float64*/
    }
  }
  return kk_whitemagic_dash_koka_src_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x176, _x_x178, _x_x180, _x_x182, _x_x184, _ctx);
}

kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger kk_whitemagic_dash_koka_src_gan__ying_cascade_trigger_fs__copy(kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _this, kk_std_core_types__optional event_type, kk_std_core_types__optional handler_count, kk_std_core_types__optional priority, kk_context_t* _ctx) { /* (cascade-trigger, event-type : ? event-type, handler-count : ? int, priority : ? int) -> cascade-trigger */ 
  kk_whitemagic_dash_koka_src_gan__ying__event_type _x_x189;
  if (kk_std_core_types__is_Optional(event_type, _ctx)) {
    kk_box_t _box_x5 = event_type._cons._Optional.value;
    kk_whitemagic_dash_koka_src_gan__ying__event_type _uniq_event_type_307 = kk_whitemagic_dash_koka_src_gan__ying__event_type_unbox(_box_x5, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(event_type, _ctx);
    _x_x189 = _uniq_event_type_307; /*whitemagic-koka/src/gan_ying/event-type*/
  }
  else {
    kk_std_core_types__optional_drop(event_type, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_gan__ying_Cascade_trigger* _con_x190 = kk_whitemagic_dash_koka_src_gan__ying__as_Cascade_trigger(_this, _ctx);
      kk_whitemagic_dash_koka_src_gan__ying__event_type _x = _con_x190->event_type;
      _x_x189 = _x; /*whitemagic-koka/src/gan_ying/event-type*/
    }
  }
  kk_integer_t _x_x191;
  if (kk_std_core_types__is_Optional(handler_count, _ctx)) {
    kk_box_t _box_x6 = handler_count._cons._Optional.value;
    kk_integer_t _uniq_handler_count_315 = kk_integer_unbox(_box_x6, _ctx);
    kk_integer_dup(_uniq_handler_count_315, _ctx);
    kk_std_core_types__optional_drop(handler_count, _ctx);
    _x_x191 = _uniq_handler_count_315; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(handler_count, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_gan__ying_Cascade_trigger* _con_x192 = kk_whitemagic_dash_koka_src_gan__ying__as_Cascade_trigger(_this, _ctx);
      kk_integer_t _x_0 = _con_x192->handler_count;
      kk_integer_dup(_x_0, _ctx);
      _x_x191 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x193;
  if (kk_std_core_types__is_Optional(priority, _ctx)) {
    kk_box_t _box_x7 = priority._cons._Optional.value;
    kk_integer_t _uniq_priority_323 = kk_integer_unbox(_box_x7, _ctx);
    kk_integer_dup(_uniq_priority_323, _ctx);
    kk_std_core_types__optional_drop(priority, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x193 = _uniq_priority_323; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(priority, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_gan__ying_Cascade_trigger* _con_x194 = kk_whitemagic_dash_koka_src_gan__ying__as_Cascade_trigger(_this, _ctx);
      kk_integer_t _pat_1_3 = _con_x194->handler_count;
      kk_integer_t _x_1 = _con_x194->priority;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x193 = _x_1; /*int*/
    }
  }
  return kk_whitemagic_dash_koka_src_gan__ying__new_Cascade_trigger(kk_reuse_null, 0, _x_x189, _x_x191, _x_x193, _ctx);
}

kk_string_t kk_whitemagic_dash_koka_src_gan__ying_event_type_to_string(kk_whitemagic_dash_koka_src_gan__ying__event_type et, kk_context_t* _ctx) { /* (et : event-type) -> string */ 
  if (kk_whitemagic_dash_koka_src_gan__ying__is_SystemStarted(et, _ctx)) {
    kk_define_string_literal(, _s_x195, 14, "system_started", _ctx)
    return kk_string_dup(_s_x195, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_SystemStopped(et, _ctx)) {
    kk_define_string_literal(, _s_x196, 14, "system_stopped", _ctx)
    return kk_string_dup(_s_x196, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_SystemHealthChanged(et, _ctx)) {
    kk_define_string_literal(, _s_x197, 21, "system_health_changed", _ctx)
    return kk_string_dup(_s_x197, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_MemoryCreated(et, _ctx)) {
    kk_define_string_literal(, _s_x198, 14, "memory_created", _ctx)
    return kk_string_dup(_s_x198, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_MemoryUpdated(et, _ctx)) {
    kk_define_string_literal(, _s_x199, 14, "memory_updated", _ctx)
    return kk_string_dup(_s_x199, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_MemoryRecalled(et, _ctx)) {
    kk_define_string_literal(, _s_x200, 15, "memory_recalled", _ctx)
    return kk_string_dup(_s_x200, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_MemoryConsolidated(et, _ctx)) {
    kk_define_string_literal(, _s_x201, 19, "memory_consolidated", _ctx)
    return kk_string_dup(_s_x201, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_GardenActivated(et, _ctx)) {
    kk_define_string_literal(, _s_x202, 16, "garden_activated", _ctx)
    return kk_string_dup(_s_x202, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_JoyTriggered(et, _ctx)) {
    kk_define_string_literal(, _s_x203, 13, "joy_triggered", _ctx)
    return kk_string_dup(_s_x203, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_WisdomIntegrated(et, _ctx)) {
    kk_define_string_literal(, _s_x204, 17, "wisdom_integrated", _ctx)
    return kk_string_dup(_s_x204, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_ThreatDetected(et, _ctx)) {
    kk_define_string_literal(, _s_x205, 15, "threat_detected", _ctx)
    return kk_string_dup(_s_x205, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_AnomalyDetected(et, _ctx)) {
    kk_define_string_literal(, _s_x206, 16, "anomaly_detected", _ctx)
    return kk_string_dup(_s_x206, _ctx);
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_FlowStateEntered(et, _ctx)) {
    kk_define_string_literal(, _s_x207, 18, "flow_state_entered", _ctx)
    return kk_string_dup(_s_x207, _ctx);
  }
  {
    kk_define_string_literal(, _s_x208, 17, "flow_state_exited", _ctx)
    return kk_string_dup(_s_x208, _ctx);
  }
}

kk_whitemagic_dash_koka_src_gan__ying__event_type kk_whitemagic_dash_koka_src_gan__ying_string_to_event_type(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> event-type */ 
  if (kk_string_cmp_cstr_borrow(s, "system_started", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_SystemStarted(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "system_stopped", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_SystemStopped(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "system_health_changed", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_SystemHealthChanged(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "memory_created", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_MemoryCreated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "memory_updated", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_MemoryUpdated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "memory_recalled", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_MemoryRecalled(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "memory_consolidated", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_MemoryConsolidated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "garden_activated", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_GardenActivated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "joy_triggered", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_JoyTriggered(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "wisdom_integrated", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_WisdomIntegrated(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "threat_detected", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_ThreatDetected(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "anomaly_detected", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_AnomalyDetected(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "flow_state_entered", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_FlowStateEntered(_ctx);
  }
  if (kk_string_cmp_cstr_borrow(s, "flow_state_exited", _ctx) == 0) {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_FlowStateExited(_ctx);
  }
  {
    kk_string_drop(s, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_SystemStarted(_ctx);
  }
}

kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger kk_whitemagic_dash_koka_src_gan__ying_check_cascade(kk_whitemagic_dash_koka_src_gan__ying__event_type et, kk_context_t* _ctx) { /* (et : event-type) -> cascade-trigger */ 
  kk_integer_t _x_x211;
  if (kk_whitemagic_dash_koka_src_gan__ying__is_MemoryCreated(et, _ctx)) {
    _x_x211 = kk_integer_from_small(3); /*int*/
    goto _match_x212;
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_MemoryUpdated(et, _ctx)) {
    _x_x211 = kk_integer_from_small(2); /*int*/
    goto _match_x212;
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_ThreatDetected(et, _ctx)) {
    _x_x211 = kk_integer_from_small(5); /*int*/
    goto _match_x212;
  }
  {
    _x_x211 = kk_integer_from_small(1); /*int*/
  }
  _match_x212: ;
  kk_integer_t _x_x213;
  if (kk_whitemagic_dash_koka_src_gan__ying__is_ThreatDetected(et, _ctx)) {
    _x_x213 = kk_integer_from_small(10); /*int*/
    goto _match_x214;
  }
  if (kk_whitemagic_dash_koka_src_gan__ying__is_MemoryCreated(et, _ctx)) {
    _x_x213 = kk_integer_from_small(5); /*int*/
    goto _match_x214;
  }
  {
    _x_x213 = kk_integer_from_small(1); /*int*/
  }
  _match_x214: ;
  return kk_whitemagic_dash_koka_src_gan__ying__new_Cascade_trigger(kk_reuse_null, 0, et, _x_x211, _x_x213, _ctx);
}

kk_string_t kk_whitemagic_dash_koka_src_gan__ying_json_event_response(kk_whitemagic_dash_koka_src_gan__ying__resonance_event event, kk_context_t* _ctx) { /* (event : resonance-event) -> string */ 
  kk_string_t _x_x224;
  kk_define_string_literal(, _s_x225, 11, "{\"source\":\"", _ctx)
  _x_x224 = kk_string_dup(_s_x225, _ctx); /*string*/
  kk_string_t _x_x226;
  kk_string_t _x_x227;
  {
    struct kk_whitemagic_dash_koka_src_gan__ying_Resonance_event* _con_x228 = kk_whitemagic_dash_koka_src_gan__ying__as_Resonance_event(event, _ctx);
    kk_string_t _x = _con_x228->source;
    kk_string_dup(_x, _ctx);
    _x_x227 = _x; /*string*/
  }
  kk_string_t _x_x229;
  kk_string_t _x_x230;
  kk_define_string_literal(, _s_x231, 10, "\",\"type\":\"", _ctx)
  _x_x230 = kk_string_dup(_s_x231, _ctx); /*string*/
  kk_string_t _x_x232;
  kk_string_t _x_x233;
  kk_whitemagic_dash_koka_src_gan__ying__event_type _x_x234;
  {
    struct kk_whitemagic_dash_koka_src_gan__ying_Resonance_event* _con_x235 = kk_whitemagic_dash_koka_src_gan__ying__as_Resonance_event(event, _ctx);
    kk_whitemagic_dash_koka_src_gan__ying__event_type _x_0 = _con_x235->event_type;
    _x_x234 = _x_0; /*whitemagic-koka/src/gan_ying/event-type*/
  }
  _x_x233 = kk_whitemagic_dash_koka_src_gan__ying_event_type_to_string(_x_x234, _ctx); /*string*/
  kk_string_t _x_x236;
  kk_string_t _x_x237;
  kk_define_string_literal(, _s_x238, 15, "\",\"confidence\":", _ctx)
  _x_x237 = kk_string_dup(_s_x238, _ctx); /*string*/
  kk_string_t _x_x239;
  kk_string_t _x_x240;
  double _x_x241;
  {
    struct kk_whitemagic_dash_koka_src_gan__ying_Resonance_event* _con_x242 = kk_whitemagic_dash_koka_src_gan__ying__as_Resonance_event(event, _ctx);
    kk_string_t _pat_0_1 = _con_x242->source;
    kk_string_t _pat_2_1 = _con_x242->data;
    kk_integer_t _pat_3_1 = _con_x242->timestamp;
    double _x_1 = _con_x242->confidence;
    if kk_likely(kk_datatype_ptr_is_unique(event, _ctx)) {
      kk_integer_drop(_pat_3_1, _ctx);
      kk_string_drop(_pat_2_1, _ctx);
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(event, _ctx);
    }
    else {
      kk_datatype_ptr_decref(event, _ctx);
    }
    _x_x241 = _x_1; /*float64*/
  }
  _x_x240 = kk_std_num_float64_show(_x_x241, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x243;
  kk_define_string_literal(, _s_x244, 1, "}", _ctx)
  _x_x243 = kk_string_dup(_s_x244, _ctx); /*string*/
  _x_x239 = kk_std_core_types__lp__plus__plus__rp_(_x_x240, _x_x243, _ctx); /*string*/
  _x_x236 = kk_std_core_types__lp__plus__plus__rp_(_x_x237, _x_x239, _ctx); /*string*/
  _x_x232 = kk_std_core_types__lp__plus__plus__rp_(_x_x233, _x_x236, _ctx); /*string*/
  _x_x229 = kk_std_core_types__lp__plus__plus__rp_(_x_x230, _x_x232, _ctx); /*string*/
  _x_x226 = kk_std_core_types__lp__plus__plus__rp_(_x_x227, _x_x229, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x224, _x_x226, _ctx);
}

kk_string_t kk_whitemagic_dash_koka_src_gan__ying_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x153;
  kk_string_t _x_x245 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x246;
  kk_define_string_literal(, _s_x247, 6, "\"emit\"", _ctx)
  _x_x246 = kk_string_dup(_s_x247, _ctx); /*string*/
  _match_x153 = kk_string_contains(_x_x245,_x_x246,kk_context()); /*bool*/
  if (_match_x153) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x248, 4, "emit", _ctx)
    return kk_string_dup(_s_x248, _ctx);
  }
  {
    bool _match_x154;
    kk_string_t _x_x249 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x250;
    kk_define_string_literal(, _s_x251, 7, "\"count\"", _ctx)
    _x_x250 = kk_string_dup(_s_x251, _ctx); /*string*/
    _match_x154 = kk_string_contains(_x_x249,_x_x250,kk_context()); /*bool*/
    if (_match_x154) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x252, 5, "count", _ctx)
      return kk_string_dup(_s_x252, _ctx);
    }
    {
      bool _match_x155;
      kk_string_t _x_x253 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x254;
      kk_define_string_literal(, _s_x255, 7, "\"reset\"", _ctx)
      _x_x254 = kk_string_dup(_s_x255, _ctx); /*string*/
      _match_x155 = kk_string_contains(_x_x253,_x_x254,kk_context()); /*bool*/
      if (_match_x155) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x256, 5, "reset", _ctx)
        return kk_string_dup(_s_x256, _ctx);
      }
      {
        bool _match_x156;
        kk_string_t _x_x257 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x258;
        kk_define_string_literal(, _s_x259, 9, "\"cascade\"", _ctx)
        _x_x258 = kk_string_dup(_s_x259, _ctx); /*string*/
        _match_x156 = kk_string_contains(_x_x257,_x_x258,kk_context()); /*bool*/
        if (_match_x156) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x260, 7, "cascade", _ctx)
          return kk_string_dup(_s_x260, _ctx);
        }
        {
          bool _match_x157;
          kk_string_t _x_x261 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x262;
          kk_define_string_literal(, _s_x263, 8, "\"status\"", _ctx)
          _x_x262 = kk_string_dup(_s_x263, _ctx); /*string*/
          _match_x157 = kk_string_contains(_x_x261,_x_x262,kk_context()); /*bool*/
          if (_match_x157) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x264, 6, "status", _ctx)
            return kk_string_dup(_s_x264, _ctx);
          }
          {
            bool _match_x158;
            kk_string_t _x_x265 = kk_string_dup(line, _ctx); /*string*/
            kk_string_t _x_x266;
            kk_define_string_literal(, _s_x267, 6, "\"quit\"", _ctx)
            _x_x266 = kk_string_dup(_s_x267, _ctx); /*string*/
            _match_x158 = kk_string_contains(_x_x265,_x_x266,kk_context()); /*bool*/
            if (_match_x158) {
              kk_string_drop(line, _ctx);
              kk_define_string_literal(, _s_x268, 4, "quit", _ctx)
              return kk_string_dup(_s_x268, _ctx);
            }
            {
              bool _match_x159;
              kk_string_t _x_x269 = kk_string_dup(line, _ctx); /*string*/
              kk_string_t _x_x270;
              kk_define_string_literal(, _s_x271, 13, "\"invoke-gana\"", _ctx)
              _x_x270 = kk_string_dup(_s_x271, _ctx); /*string*/
              _match_x159 = kk_string_contains(_x_x269,_x_x270,kk_context()); /*bool*/
              if (_match_x159) {
                kk_string_drop(line, _ctx);
                kk_define_string_literal(, _s_x272, 11, "invoke-gana", _ctx)
                return kk_string_dup(_s_x272, _ctx);
              }
              {
                bool _match_x160;
                kk_string_t _x_x273;
                kk_define_string_literal(, _s_x274, 12, "\"route-prat\"", _ctx)
                _x_x273 = kk_string_dup(_s_x274, _ctx); /*string*/
                _match_x160 = kk_string_contains(line,_x_x273,kk_context()); /*bool*/
                if (_match_x160) {
                  kk_define_string_literal(, _s_x275, 10, "route-prat", _ctx)
                  return kk_string_dup(_s_x275, _ctx);
                }
                {
                  kk_define_string_literal(, _s_x276, 7, "unknown", _ctx)
                  return kk_string_dup(_s_x276, _ctx);
                }
              }
            }
          }
        }
      }
    }
  }
}

kk_whitemagic_dash_koka_src_gan__ying__event_type kk_whitemagic_dash_koka_src_gan__ying_extract_type(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> event-type */ 
  bool _match_x147;
  kk_string_t _x_x277 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x278;
  kk_define_string_literal(, _s_x279, 16, "\"system_started\"", _ctx)
  _x_x278 = kk_string_dup(_s_x279, _ctx); /*string*/
  _match_x147 = kk_string_contains(_x_x277,_x_x278,kk_context()); /*bool*/
  if (_match_x147) {
    kk_string_drop(line, _ctx);
    return kk_whitemagic_dash_koka_src_gan__ying__new_SystemStarted(_ctx);
  }
  {
    bool _match_x148;
    kk_string_t _x_x280 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x281;
    kk_define_string_literal(, _s_x282, 16, "\"system_stopped\"", _ctx)
    _x_x281 = kk_string_dup(_s_x282, _ctx); /*string*/
    _match_x148 = kk_string_contains(_x_x280,_x_x281,kk_context()); /*bool*/
    if (_match_x148) {
      kk_string_drop(line, _ctx);
      return kk_whitemagic_dash_koka_src_gan__ying__new_SystemStopped(_ctx);
    }
    {
      bool _match_x149;
      kk_string_t _x_x283 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x284;
      kk_define_string_literal(, _s_x285, 16, "\"memory_created\"", _ctx)
      _x_x284 = kk_string_dup(_s_x285, _ctx); /*string*/
      _match_x149 = kk_string_contains(_x_x283,_x_x284,kk_context()); /*bool*/
      if (_match_x149) {
        kk_string_drop(line, _ctx);
        return kk_whitemagic_dash_koka_src_gan__ying__new_MemoryCreated(_ctx);
      }
      {
        bool _match_x150;
        kk_string_t _x_x286 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x287;
        kk_define_string_literal(, _s_x288, 16, "\"memory_updated\"", _ctx)
        _x_x287 = kk_string_dup(_s_x288, _ctx); /*string*/
        _match_x150 = kk_string_contains(_x_x286,_x_x287,kk_context()); /*bool*/
        if (_match_x150) {
          kk_string_drop(line, _ctx);
          return kk_whitemagic_dash_koka_src_gan__ying__new_MemoryUpdated(_ctx);
        }
        {
          bool _match_x151;
          kk_string_t _x_x289 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x290;
          kk_define_string_literal(, _s_x291, 17, "\"threat_detected\"", _ctx)
          _x_x290 = kk_string_dup(_s_x291, _ctx); /*string*/
          _match_x151 = kk_string_contains(_x_x289,_x_x290,kk_context()); /*bool*/
          if (_match_x151) {
            kk_string_drop(line, _ctx);
            return kk_whitemagic_dash_koka_src_gan__ying__new_ThreatDetected(_ctx);
          }
          {
            bool _match_x152;
            kk_string_t _x_x292;
            kk_define_string_literal(, _s_x293, 15, "\"joy_triggered\"", _ctx)
            _x_x292 = kk_string_dup(_s_x293, _ctx); /*string*/
            _match_x152 = kk_string_contains(line,_x_x292,kk_context()); /*bool*/
            if (_match_x152) {
              return kk_whitemagic_dash_koka_src_gan__ying__new_JoyTriggered(_ctx);
            }
            {
              return kk_whitemagic_dash_koka_src_gan__ying__new_SystemStarted(_ctx);
            }
          }
        }
      }
    }
  }
}

kk_unit_t kk_whitemagic_dash_koka_src_gan__ying_flush_stdout(kk_context_t* _ctx) { /* () -> console/console () */ 
  fflush(stdout); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10067_fun297__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10067_fun297(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10067_fun297(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10067_fun297, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10067_fun297(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x298 = kk_Unit;
  kk_integer_t _x_x299 = kk_integer_unbox(_b_x15, _ctx); /*int*/
  kk_whitemagic_dash_koka_src_gan__ying_server_loop(_x_x299, _ctx);
  return kk_unit_box(_x_x298);
}

kk_unit_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10067(kk_string_t op, kk_integer_t _c_x10018, kk_context_t* _ctx) { /* (op : string, int) -> () */ 
  bool _match_x146;
  kk_string_t _x_x294;
  kk_define_string_literal(, _s_x295, 4, "quit", _ctx)
  _x_x294 = kk_string_dup(_s_x295, _ctx); /*string*/
  _match_x146 = kk_string_is_neq(op,_x_x294,kk_context()); /*bool*/
  if (_match_x146) {
    kk_ssize_t _b_x12_16 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_box_t _x_x296 = kk_std_core_hnd__open_at1(_b_x12_16, kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10067_fun297(_ctx), kk_integer_box(_c_x10018, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x296); return kk_Unit;
  }
  {
    kk_integer_drop(_c_x10018, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun301__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun301(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10068_fun301(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun301, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun301(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x302 = kk_Unit;
  kk_whitemagic_dash_koka_src_gan__ying_flush_stdout(_ctx);
  return kk_unit_box(_x_x302);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun305__t {
  struct kk_function_s _base;
  kk_string_t op_0;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun305(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10068_fun305(kk_string_t op_0, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun305__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun305__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun305, kk_context());
  _self->op_0 = op_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun305(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun305__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068_fun305__t*, _fself, _ctx);
  kk_string_t op_0 = _self->op_0; /* string */
  kk_drop_match(_self, {kk_string_dup(op_0, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10018_0_24 = kk_integer_unbox(_b_x22, _ctx); /*int*/;
  kk_unit_t _x_x306 = kk_Unit;
  kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10067(op_0, _c_x10018_0_24, _ctx);
  return kk_unit_box(_x_x306);
}

kk_unit_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068(kk_integer_t event_count, kk_string_t op_0, kk_string_t _c_x10017, kk_context_t* _ctx) { /* (event-count : int, op : string, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10017, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x300 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10068_fun301(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x300);
  kk_integer_t x_10070;
  if (kk_string_cmp_cstr_borrow(op_0, "emit", _ctx) == 0) {
    x_10070 = kk_integer_add_small_const(event_count, 1, _ctx); /*int*/
    goto _match_x303;
  }
  if (kk_string_cmp_cstr_borrow(op_0, "reset", _ctx) == 0) {
    kk_integer_drop(event_count, _ctx);
    x_10070 = kk_integer_from_small(0); /*int*/
    goto _match_x303;
  }
  {
    x_10070 = event_count; /*int*/
  }
  _match_x303: ;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10070, _ctx);
    kk_box_t _x_x304 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10068_fun305(op_0, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x304); return kk_Unit;
  }
  {
    kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10067(op_0, x_10070, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun311__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun311(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun311(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun311, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun311(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x312;
  kk_string_t _x_x313 = kk_string_unbox(_b_x27); /*string*/
  _x_x312 = kk_whitemagic_dash_koka_src_gan__ying_extract_op(_x_x313, _ctx); /*string*/
  return kk_string_box(_x_x312);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun318__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun318(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun318(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun318, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun318(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_gan__ying__event_type _x_x319;
  kk_string_t _x_x320 = kk_string_unbox(_b_x32); /*string*/
  _x_x319 = kk_whitemagic_dash_koka_src_gan__ying_extract_type(_x_x320, _ctx); /*whitemagic-koka/src/gan_ying/event-type*/
  return kk_whitemagic_dash_koka_src_gan__ying__event_type_box(_x_x319, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun324__t {
  struct kk_function_s _base;
  kk_integer_t event_count_0;
  kk_whitemagic_dash_koka_src_gan__ying__event_type et;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun324(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun324(kk_integer_t event_count_0, kk_whitemagic_dash_koka_src_gan__ying__event_type et, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun324__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun324__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun324, kk_context());
  _self->event_count_0 = event_count_0;
  _self->et = et;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun324(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun324__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun324__t*, _fself, _ctx);
  kk_integer_t event_count_0 = _self->event_count_0; /* int */
  kk_whitemagic_dash_koka_src_gan__ying__event_type et = _self->et; /* whitemagic-koka/src/gan_ying/event-type */
  kk_drop_match(_self, {kk_integer_dup(event_count_0, _ctx);kk_whitemagic_dash_koka_src_gan__ying__event_type_dup(et, _ctx);}, {}, _ctx)
  kk_integer_t new_count = kk_integer_add_small_const(event_count_0, 1, _ctx); /*int*/;
  kk_std_core_types__tuple2 _x_x325;
  kk_box_t _x_x326;
  kk_whitemagic_dash_koka_src_gan__ying__resonance_event _x_x327;
  kk_string_t _x_x328;
  kk_define_string_literal(, _s_x329, 3, "ipc", _ctx)
  _x_x328 = kk_string_dup(_s_x329, _ctx); /*string*/
  kk_string_t _x_x330;
  kk_define_string_literal(, _s_x331, 2, "{}", _ctx)
  _x_x330 = kk_string_dup(_s_x331, _ctx); /*string*/
  _x_x327 = kk_whitemagic_dash_koka_src_gan__ying__new_Resonance_event(kk_reuse_null, 0, _x_x328, et, _x_x330, kk_integer_from_small(0), 0x1p0, _ctx); /*whitemagic-koka/src/gan_ying/resonance-event*/
  _x_x326 = kk_whitemagic_dash_koka_src_gan__ying__resonance_event_box(_x_x327, _ctx); /*10037*/
  _x_x325 = kk_std_core_types__new_Tuple2(_x_x326, kk_integer_box(new_count, _ctx), _ctx); /*(10037, 10038)*/
  return kk_std_core_types__tuple2_box(_x_x325, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun333__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun333(kk_function_t _fself, kk_box_t _b_x42, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun333(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun333, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun333(kk_function_t _fself, kk_box_t _b_x42, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x334;
  kk_whitemagic_dash_koka_src_gan__ying__resonance_event _x_x335 = kk_whitemagic_dash_koka_src_gan__ying__resonance_event_unbox(_b_x42, KK_OWNED, _ctx); /*whitemagic-koka/src/gan_ying/resonance-event*/
  _x_x334 = kk_whitemagic_dash_koka_src_gan__ying_json_event_response(_x_x335, _ctx); /*string*/
  return kk_string_box(_x_x334);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun361__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun361(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun361(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun361, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun361(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_gan__ying__event_type _x_x362;
  kk_string_t _x_x363 = kk_string_unbox(_b_x45); /*string*/
  _x_x362 = kk_whitemagic_dash_koka_src_gan__ying_extract_type(_x_x363, _ctx); /*whitemagic-koka/src/gan_ying/event-type*/
  return kk_whitemagic_dash_koka_src_gan__ying__event_type_box(_x_x362, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun365__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun365(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun365(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun365, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun365(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _x_x366;
  kk_whitemagic_dash_koka_src_gan__ying__event_type _x_x367 = kk_whitemagic_dash_koka_src_gan__ying__event_type_unbox(_b_x50, KK_OWNED, _ctx); /*whitemagic-koka/src/gan_ying/event-type*/
  _x_x366 = kk_whitemagic_dash_koka_src_gan__ying_check_cascade(_x_x367, _ctx); /*whitemagic-koka/src/gan_ying/cascade-trigger*/
  return kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger_box(_x_x366, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun369__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun369(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun369(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun369, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun369(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_gan__ying__event_type _x_x370;
  kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _match_x143 = kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger_unbox(_b_x55, KK_OWNED, _ctx); /*whitemagic-koka/src/gan_ying/cascade-trigger*/;
  {
    struct kk_whitemagic_dash_koka_src_gan__ying_Cascade_trigger* _con_x371 = kk_whitemagic_dash_koka_src_gan__ying__as_Cascade_trigger(_match_x143, _ctx);
    kk_whitemagic_dash_koka_src_gan__ying__event_type _x = _con_x371->event_type;
    kk_integer_t _pat_0_0_0 = _con_x371->handler_count;
    kk_integer_t _pat_1_0_0 = _con_x371->priority;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x143, _ctx)) {
      kk_integer_drop(_pat_1_0_0, _ctx);
      kk_integer_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(_match_x143, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x143, _ctx);
    }
    _x_x370 = _x; /*whitemagic-koka/src/gan_ying/event-type*/
  }
  return kk_whitemagic_dash_koka_src_gan__ying__event_type_box(_x_x370, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun374__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun374(kk_function_t _fself, kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _this_0, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun374(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun374, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun374(kk_function_t _fself, kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _this_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_whitemagic_dash_koka_src_gan__ying_Cascade_trigger* _con_x375 = kk_whitemagic_dash_koka_src_gan__ying__as_Cascade_trigger(_this_0, _ctx);
    kk_integer_t _x_0 = _con_x375->handler_count;
    kk_integer_t _pat_1_1 = _con_x375->priority;
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
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun381__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun381(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun381(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun381, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun381(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x382;
  kk_whitemagic_dash_koka_src_gan__ying__event_type _x_x383 = kk_whitemagic_dash_koka_src_gan__ying__event_type_unbox(_b_x61, KK_OWNED, _ctx); /*whitemagic-koka/src/gan_ying/event-type*/
  _x_x382 = kk_whitemagic_dash_koka_src_gan__ying_event_type_to_string(_x_x383, _ctx); /*string*/
  return kk_string_box(_x_x382);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun385__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun385(kk_function_t _fself, kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _this_1, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun385(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun385, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun385(kk_function_t _fself, kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _this_1, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_whitemagic_dash_koka_src_gan__ying_Cascade_trigger* _con_x386 = kk_whitemagic_dash_koka_src_gan__ying__as_Cascade_trigger(_this_1, _ctx);
    kk_integer_t _pat_1_2 = _con_x386->handler_count;
    kk_integer_t _x_1 = _con_x386->priority;
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
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun393__t {
  struct kk_function_s _base;
  kk_function_t _b_x62_75;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun393(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun393(kk_function_t _b_x62_75, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun393__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun393__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun393, kk_context());
  _self->_b_x62_75 = _b_x62_75;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun393(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun393__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun393__t*, _fself, _ctx);
  kk_function_t _b_x62_75 = _self->_b_x62_75; /* (whitemagic-koka/src/gan_ying/cascade-trigger) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x62_75, _ctx);}, {}, _ctx)
  kk_integer_t _x_x394;
  kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _x_x395 = kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger_unbox(_b_x64, KK_OWNED, _ctx); /*whitemagic-koka/src/gan_ying/cascade-trigger*/
  _x_x394 = kk_function_call(kk_integer_t, (kk_function_t, kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger, kk_context_t*), _b_x62_75, (_b_x62_75, _x_x395, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x394, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun403__t {
  struct kk_function_s _base;
  kk_function_t _b_x65_77;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun403(kk_function_t _fself, kk_box_t _b_x67, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun403(kk_function_t _b_x65_77, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun403__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun403__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun403, kk_context());
  _self->_b_x65_77 = _b_x65_77;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun403(kk_function_t _fself, kk_box_t _b_x67, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun403__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun403__t*, _fself, _ctx);
  kk_function_t _b_x65_77 = _self->_b_x65_77; /* (whitemagic-koka/src/gan_ying/cascade-trigger) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x65_77, _ctx);}, {}, _ctx)
  kk_integer_t _x_x404;
  kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _x_x405 = kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger_unbox(_b_x67, KK_OWNED, _ctx); /*whitemagic-koka/src/gan_ying/cascade-trigger*/
  _x_x404 = kk_function_call(kk_integer_t, (kk_function_t, kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger, kk_context_t*), _b_x65_77, (_b_x65_77, _x_x405, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x404, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun420__t {
  struct kk_function_s _base;
  kk_integer_t event_count_0;
  kk_string_t op_1;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun420(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun420(kk_integer_t event_count_0, kk_string_t op_1, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun420__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun420__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun420, kk_context());
  _self->event_count_0 = event_count_0;
  _self->op_1 = op_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun420(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun420__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069_fun420__t*, _fself, _ctx);
  kk_integer_t event_count_0 = _self->event_count_0; /* int */
  kk_string_t op_1 = _self->op_1; /* string */
  kk_drop_match(_self, {kk_integer_dup(event_count_0, _ctx);kk_string_dup(op_1, _ctx);}, {}, _ctx)
  kk_string_t _c_x10017_0_82 = kk_string_unbox(_b_x80); /*string*/;
  kk_unit_t _x_x421 = kk_Unit;
  kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068(event_count_0, op_1, _c_x10017_0_82, _ctx);
  return kk_unit_box(_x_x421);
}

kk_unit_t kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069(kk_integer_t event_count_0, kk_string_t line, kk_context_t* _ctx) { /* (event-count : int, line : string) -> <console/console,exn,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>,exn> () */ 
  bool _match_x141;
  kk_string_t _x_x307 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x308 = kk_string_empty(); /*string*/
  _match_x141 = kk_string_is_neq(_x_x307,_x_x308,kk_context()); /*bool*/
  if (_match_x141) {
    kk_string_t op_1;
    kk_box_t _x_x310;
    kk_box_t _x_x314;
    kk_string_t _x_x315 = kk_string_dup(line, _ctx); /*string*/
    _x_x314 = kk_string_box(_x_x315); /*10000*/
    _x_x310 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun311(_ctx), _x_x314, _ctx); /*10001*/
    op_1 = kk_string_unbox(_x_x310); /*string*/
    kk_string_t x_0_10072;
    if (kk_string_cmp_cstr_borrow(op_1, "emit", _ctx) == 0) {
      kk_whitemagic_dash_koka_src_gan__ying__event_type et;
      kk_box_t _x_x317 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun318(_ctx), kk_string_box(line), _ctx); /*10001*/
      et = kk_whitemagic_dash_koka_src_gan__ying__event_type_unbox(_x_x317, KK_OWNED, _ctx); /*whitemagic-koka/src/gan_ying/event-type*/
      kk_box_t _x_x321;
      kk_std_core_types__tuple2 _match_x144;
      kk_box_t _x_x322;
      kk_function_t _x_x323;
      kk_integer_dup(event_count_0, _ctx);
      _x_x323 = kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun324(event_count_0, et, _ctx); /*() -> 10001 10000*/
      _x_x322 = kk_std_core_hnd__open_none0(_x_x323, _ctx); /*10000*/
      _match_x144 = kk_std_core_types__tuple2_unbox(_x_x322, KK_OWNED, _ctx); /*(whitemagic-koka/src/gan_ying/resonance-event, int)*/
      {
        kk_box_t _box_x38 = _match_x144.fst;
        kk_box_t _box_x39 = _match_x144.snd;
        kk_whitemagic_dash_koka_src_gan__ying__resonance_event event = kk_whitemagic_dash_koka_src_gan__ying__resonance_event_unbox(_box_x38, KK_BORROWED, _ctx);
        struct kk_whitemagic_dash_koka_src_gan__ying_Resonance_event* _con_x332 = kk_whitemagic_dash_koka_src_gan__ying__as_Resonance_event(event, _ctx);
        kk_whitemagic_dash_koka_src_gan__ying__resonance_event_dup(event, _ctx);
        kk_std_core_types__tuple2_drop(_match_x144, _ctx);
        _x_x321 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun333(_ctx), kk_whitemagic_dash_koka_src_gan__ying__resonance_event_box(event, _ctx), _ctx); /*10001*/
      }
      x_0_10072 = kk_string_unbox(_x_x321); /*string*/
      goto _match_x316;
    }
    if (kk_string_cmp_cstr_borrow(op_1, "count", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_string_t result_10031;
      kk_integer_t _x_x336 = kk_integer_dup(event_count_0, _ctx); /*int*/
      result_10031 = kk_std_core_int_show(_x_x336, _ctx); /*string*/
      kk_string_t _x_x337;
      kk_define_string_literal(, _s_x338, 7, "{\"op\":\"", _ctx)
      _x_x337 = kk_string_dup(_s_x338, _ctx); /*string*/
      kk_string_t _x_x339;
      kk_string_t _x_x340;
      kk_define_string_literal(, _s_x341, 5, "count", _ctx)
      _x_x340 = kk_string_dup(_s_x341, _ctx); /*string*/
      kk_string_t _x_x342;
      kk_string_t _x_x343;
      kk_define_string_literal(, _s_x344, 12, "\",\"result\":\"", _ctx)
      _x_x343 = kk_string_dup(_s_x344, _ctx); /*string*/
      kk_string_t _x_x345;
      kk_string_t _x_x346;
      kk_define_string_literal(, _s_x347, 2, "\"}", _ctx)
      _x_x346 = kk_string_dup(_s_x347, _ctx); /*string*/
      _x_x345 = kk_std_core_types__lp__plus__plus__rp_(result_10031, _x_x346, _ctx); /*string*/
      _x_x342 = kk_std_core_types__lp__plus__plus__rp_(_x_x343, _x_x345, _ctx); /*string*/
      _x_x339 = kk_std_core_types__lp__plus__plus__rp_(_x_x340, _x_x342, _ctx); /*string*/
      x_0_10072 = kk_std_core_types__lp__plus__plus__rp_(_x_x337, _x_x339, _ctx); /*string*/
      goto _match_x316;
    }
    if (kk_string_cmp_cstr_borrow(op_1, "reset", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_string_t result_0_10033;
      kk_integer_t _x_x348 = kk_integer_dup(event_count_0, _ctx); /*int*/
      result_0_10033 = kk_std_core_int_show(_x_x348, _ctx); /*string*/
      kk_string_t _x_x349;
      kk_define_string_literal(, _s_x350, 7, "{\"op\":\"", _ctx)
      _x_x349 = kk_string_dup(_s_x350, _ctx); /*string*/
      kk_string_t _x_x351;
      kk_string_t _x_x352;
      kk_define_string_literal(, _s_x353, 5, "reset", _ctx)
      _x_x352 = kk_string_dup(_s_x353, _ctx); /*string*/
      kk_string_t _x_x354;
      kk_string_t _x_x355;
      kk_define_string_literal(, _s_x356, 12, "\",\"result\":\"", _ctx)
      _x_x355 = kk_string_dup(_s_x356, _ctx); /*string*/
      kk_string_t _x_x357;
      kk_string_t _x_x358;
      kk_define_string_literal(, _s_x359, 2, "\"}", _ctx)
      _x_x358 = kk_string_dup(_s_x359, _ctx); /*string*/
      _x_x357 = kk_std_core_types__lp__plus__plus__rp_(result_0_10033, _x_x358, _ctx); /*string*/
      _x_x354 = kk_std_core_types__lp__plus__plus__rp_(_x_x355, _x_x357, _ctx); /*string*/
      _x_x351 = kk_std_core_types__lp__plus__plus__rp_(_x_x352, _x_x354, _ctx); /*string*/
      x_0_10072 = kk_std_core_types__lp__plus__plus__rp_(_x_x349, _x_x351, _ctx); /*string*/
      goto _match_x316;
    }
    if (kk_string_cmp_cstr_borrow(op_1, "cascade", _ctx) == 0) {
      kk_whitemagic_dash_koka_src_gan__ying__event_type et_0_0;
      kk_box_t _x_x360 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun361(_ctx), kk_string_box(line), _ctx); /*10001*/
      et_0_0 = kk_whitemagic_dash_koka_src_gan__ying__event_type_unbox(_x_x360, KK_OWNED, _ctx); /*whitemagic-koka/src/gan_ying/event-type*/
      kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger trigger;
      kk_box_t _x_x364 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun365(_ctx), kk_whitemagic_dash_koka_src_gan__ying__event_type_box(et_0_0, _ctx), _ctx); /*10001*/
      trigger = kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger_unbox(_x_x364, KK_OWNED, _ctx); /*whitemagic-koka/src/gan_ying/cascade-trigger*/
      kk_whitemagic_dash_koka_src_gan__ying__event_type _x_x1_5_10056;
      kk_box_t _x_x368;
      kk_box_t _x_x372;
      kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _x_x373 = kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger_dup(trigger, _ctx); /*whitemagic-koka/src/gan_ying/cascade-trigger*/
      _x_x372 = kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger_box(_x_x373, _ctx); /*10000*/
      _x_x368 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun369(_ctx), _x_x372, _ctx); /*10001*/
      _x_x1_5_10056 = kk_whitemagic_dash_koka_src_gan__ying__event_type_unbox(_x_x368, KK_OWNED, _ctx); /*whitemagic-koka/src/gan_ying/event-type*/
      kk_function_t _b_x62_75 = kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun374(_ctx); /*(whitemagic-koka/src/gan_ying/cascade-trigger) -> int*/;
      kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _b_x63_76 = kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger_dup(trigger, _ctx); /*whitemagic-koka/src/gan_ying/cascade-trigger*/;
      kk_string_t _x_x376;
      kk_define_string_literal(, _s_x377, 9, "{\"type\":\"", _ctx)
      _x_x376 = kk_string_dup(_s_x377, _ctx); /*string*/
      kk_string_t _x_x378;
      kk_string_t _x_x379;
      kk_box_t _x_x380 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun381(_ctx), kk_whitemagic_dash_koka_src_gan__ying__event_type_box(_x_x1_5_10056, _ctx), _ctx); /*10001*/
      _x_x379 = kk_string_unbox(_x_x380); /*string*/
      kk_string_t _x_x384;
      kk_function_t _b_x65_77 = kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun385(_ctx); /*(whitemagic-koka/src/gan_ying/cascade-trigger) -> int*/;
      kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger _b_x66_78 = trigger; /*whitemagic-koka/src/gan_ying/cascade-trigger*/;
      kk_string_t _x_x387;
      kk_define_string_literal(, _s_x388, 13, "\",\"handlers\":", _ctx)
      _x_x387 = kk_string_dup(_s_x388, _ctx); /*string*/
      kk_string_t _x_x389;
      kk_string_t _x_x390;
      kk_integer_t _x_x391;
      kk_box_t _x_x392 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun393(_b_x62_75, _ctx), kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger_box(_b_x63_76, _ctx), _ctx); /*10001*/
      _x_x391 = kk_integer_unbox(_x_x392, _ctx); /*int*/
      _x_x390 = kk_std_core_int_show(_x_x391, _ctx); /*string*/
      kk_string_t _x_x396;
      kk_string_t _x_x397;
      kk_define_string_literal(, _s_x398, 12, ",\"priority\":", _ctx)
      _x_x397 = kk_string_dup(_s_x398, _ctx); /*string*/
      kk_string_t _x_x399;
      kk_string_t _x_x400;
      kk_integer_t _x_x401;
      kk_box_t _x_x402 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun403(_b_x65_77, _ctx), kk_whitemagic_dash_koka_src_gan__ying__cascade_trigger_box(_b_x66_78, _ctx), _ctx); /*10001*/
      _x_x401 = kk_integer_unbox(_x_x402, _ctx); /*int*/
      _x_x400 = kk_std_core_int_show(_x_x401, _ctx); /*string*/
      kk_string_t _x_x406;
      kk_define_string_literal(, _s_x407, 1, "}", _ctx)
      _x_x406 = kk_string_dup(_s_x407, _ctx); /*string*/
      _x_x399 = kk_std_core_types__lp__plus__plus__rp_(_x_x400, _x_x406, _ctx); /*string*/
      _x_x396 = kk_std_core_types__lp__plus__plus__rp_(_x_x397, _x_x399, _ctx); /*string*/
      _x_x389 = kk_std_core_types__lp__plus__plus__rp_(_x_x390, _x_x396, _ctx); /*string*/
      _x_x384 = kk_std_core_types__lp__plus__plus__rp_(_x_x387, _x_x389, _ctx); /*string*/
      _x_x378 = kk_std_core_types__lp__plus__plus__rp_(_x_x379, _x_x384, _ctx); /*string*/
      x_0_10072 = kk_std_core_types__lp__plus__plus__rp_(_x_x376, _x_x378, _ctx); /*string*/
      goto _match_x316;
    }
    if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_string_t _x_x408;
      kk_define_string_literal(, _s_x409, 24, "{\"status\":\"ok\",\"events\":", _ctx)
      _x_x408 = kk_string_dup(_s_x409, _ctx); /*string*/
      kk_string_t _x_x410;
      kk_string_t _x_x411;
      kk_integer_t _x_x412 = kk_integer_dup(event_count_0, _ctx); /*int*/
      _x_x411 = kk_std_core_int_show(_x_x412, _ctx); /*string*/
      kk_string_t _x_x413;
      kk_define_string_literal(, _s_x414, 1, "}", _ctx)
      _x_x413 = kk_string_dup(_s_x414, _ctx); /*string*/
      _x_x410 = kk_std_core_types__lp__plus__plus__rp_(_x_x411, _x_x413, _ctx); /*string*/
      x_0_10072 = kk_std_core_types__lp__plus__plus__rp_(_x_x408, _x_x410, _ctx); /*string*/
      goto _match_x316;
    }
    if (kk_string_cmp_cstr_borrow(op_1, "ping", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x415, 13, "{\"pong\":true}", _ctx)
      x_0_10072 = kk_string_dup(_s_x415, _ctx); /*string*/
      goto _match_x316;
    }
    if (kk_string_cmp_cstr_borrow(op_1, "invoke-gana", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x416, 39, "{\"status\":\"ok\",\"result\":\"gana invoked\"}", _ctx)
      x_0_10072 = kk_string_dup(_s_x416, _ctx); /*string*/
      goto _match_x316;
    }
    if (kk_string_cmp_cstr_borrow(op_1, "route-prat", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x417, 29, "{\"status\":\"ok\",\"routed\":true}", _ctx)
      x_0_10072 = kk_string_dup(_s_x417, _ctx); /*string*/
      goto _match_x316;
    }
    {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x418, 29, "{\"error\":\"unknown_operation\"}", _ctx)
      x_0_10072 = kk_string_dup(_s_x418, _ctx); /*string*/
    }
    _match_x316: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10072, _ctx);
      kk_box_t _x_x419 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_gan__ying__new_mlift_server_loop_10069_fun420(event_count_0, op_1, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x419); return kk_Unit;
    }
    {
      kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10068(event_count_0, op_1, x_0_10072, _ctx); return kk_Unit;
    }
  }
  {
    kk_string_drop(line, _ctx);
    kk_integer_drop(event_count_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun423__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun423(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x_1, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun423(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun423, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun424__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun424(kk_function_t _fself, kk_function_t _b_x85, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun424(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun424, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun425__t {
  struct kk_function_s _base;
  kk_function_t _b_x85;
};
static kk_unit_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun425(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x86, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun425(kk_function_t _b_x85, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun425__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun425__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun425, kk_context());
  _self->_b_x85 = _b_x85;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun425(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x86, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun425__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun425__t*, _fself, _ctx);
  kk_function_t _b_x85 = _self->_b_x85; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x85, _ctx);}, {}, _ctx)
  kk_box_t _x_x426 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x85, (_b_x85, _b_x86, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x426); return kk_Unit;
}
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun424(kk_function_t _fself, kk_function_t _b_x85, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t ___wildcard_x653__45_108 = kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun425(_b_x85, _ctx); /*(hnd/resume-result<858,()>) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> ()*/;
  kk_function_drop(___wildcard_x653__45_108, _ctx);
  return kk_unit_box(kk_Unit);
}
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun423(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x_1, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  kk_std_core_exn__exception_drop(x_1, _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun424(_ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun429__t {
  struct kk_function_s _base;
  kk_function_t _b_x87_104;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun429(kk_function_t _fself, int32_t _b_x88, kk_std_core_hnd__ev _b_x89, kk_box_t _b_x90, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun429(kk_function_t _b_x87_104, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun429__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun429__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun429, kk_context());
  _self->_b_x87_104 = _b_x87_104;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun429(kk_function_t _fself, int32_t _b_x88, kk_std_core_hnd__ev _b_x89, kk_box_t _b_x90, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun429__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun429__t*, _fself, _ctx);
  kk_function_t _b_x87_104 = _self->_b_x87_104; /* (m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x@1 : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 858 */
  kk_drop_match(_self, {kk_function_dup(_b_x87_104, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x430 = kk_std_core_exn__exception_unbox(_b_x90, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x87_104, (_b_x87_104, _b_x88, _b_x89, _x_x430, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun431__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun431(kk_function_t _fself, kk_box_t _b_x100, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun431(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun431, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun431(kk_function_t _fself, kk_box_t _b_x100, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_109 = kk_Unit;
  kk_unit_unbox(_b_x100);
  return kk_unit_box(_res_109);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun432__t {
  struct kk_function_s _base;
  kk_integer_t event_count_1;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun432(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun432(kk_integer_t event_count_1, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun432__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun432__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun432, kk_context());
  _self->event_count_1 = event_count_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun434__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun434(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun434(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun434, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun434(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x435 = kk_std_os_readline_readline(_ctx); /*string*/
  return kk_string_box(_x_x435);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun438__t {
  struct kk_function_s _base;
  kk_integer_t event_count_1;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun438(kk_function_t _fself, kk_box_t _b_x96, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun438(kk_integer_t event_count_1, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun438__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun438__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun438, kk_context());
  _self->event_count_1 = event_count_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun438(kk_function_t _fself, kk_box_t _b_x96, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun438__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun438__t*, _fself, _ctx);
  kk_integer_t event_count_1 = _self->event_count_1; /* int */
  kk_drop_match(_self, {kk_integer_dup(event_count_1, _ctx);}, {}, _ctx)
  kk_string_t line_0_110 = kk_string_unbox(_b_x96); /*string*/;
  kk_unit_t _x_x439 = kk_Unit;
  kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069(event_count_1, line_0_110, _ctx);
  return kk_unit_box(_x_x439);
}
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun432(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun432__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_gan__ying_server_loop_fun432__t*, _fself, _ctx);
  kk_integer_t event_count_1 = _self->event_count_1; /* int */
  kk_drop_match(_self, {kk_integer_dup(event_count_1, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x91_93 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_string_t x_2_10075;
  kk_box_t _x_x433 = kk_std_core_hnd__open_at0(_b_x91_93, kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun434(_ctx), _ctx); /*10000*/
  x_2_10075 = kk_string_unbox(_x_x433); /*string*/
  kk_unit_t _x_x436 = kk_Unit;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2_10075, _ctx);
    kk_box_t _x_x437 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun438(event_count_1, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x437);
  }
  else {
    kk_whitemagic_dash_koka_src_gan__ying__mlift_server_loop_10069(event_count_1, x_2_10075, _ctx);
  }
  return kk_unit_box(_x_x436);
}

kk_unit_t kk_whitemagic_dash_koka_src_gan__ying_server_loop(kk_integer_t event_count_1, kk_context_t* _ctx) { /* (event-count : int) -> io () */ 
  kk_box_t _x_x422;
  kk_function_t _b_x87_104 = kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun423(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x@1 : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 858*/;
  kk_std_core_exn__exn _x_x427;
  kk_std_core_hnd__clause1 _x_x428 = kk_std_core_hnd__new_Clause1(kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun429(_b_x87_104, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x427 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x428, _ctx); /*exn<10005,10006>*/
  _x_x422 = kk_std_core_exn_exn_fs__handle(_x_x427, kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun431(_ctx), kk_whitemagic_dash_koka_src_gan__ying_new_server_loop_fun432(event_count_1, _ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x422); return kk_Unit;
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_main_fun441__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun441(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_main_fun441(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying_main_fun441, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_main_fun442__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun442(kk_function_t _fself, kk_function_t _b_x113, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_main_fun442(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying_main_fun442, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_main_fun443__t {
  struct kk_function_s _base;
  kk_function_t _b_x113;
};
static kk_unit_t kk_whitemagic_dash_koka_src_gan__ying_main_fun443(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x114, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_main_fun443(kk_function_t _b_x113, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_main_fun443__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_gan__ying_main_fun443__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_gan__ying_main_fun443, kk_context());
  _self->_b_x113 = _b_x113;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_whitemagic_dash_koka_src_gan__ying_main_fun443(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x114, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_main_fun443__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_gan__ying_main_fun443__t*, _fself, _ctx);
  kk_function_t _b_x113 = _self->_b_x113; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x113, _ctx);}, {}, _ctx)
  kk_box_t _x_x444 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x113, (_b_x113, _b_x114, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x444); return kk_Unit;
}
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun442(kk_function_t _fself, kk_function_t _b_x113, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t ___wildcard_x653__45_138 = kk_whitemagic_dash_koka_src_gan__ying_new_main_fun443(_b_x113, _ctx); /*(hnd/resume-result<1561,()>) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> ()*/;
  kk_function_drop(___wildcard_x653__45_138, _ctx);
  return kk_unit_box(kk_Unit);
}
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun441(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  kk_std_core_exn__exception_drop(x, _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_whitemagic_dash_koka_src_gan__ying_new_main_fun442(_ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_main_fun447__t {
  struct kk_function_s _base;
  kk_function_t _b_x115_132;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun447(kk_function_t _fself, int32_t _b_x116, kk_std_core_hnd__ev _b_x117, kk_box_t _b_x118, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_main_fun447(kk_function_t _b_x115_132, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_main_fun447__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_gan__ying_main_fun447__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_gan__ying_main_fun447, kk_context());
  _self->_b_x115_132 = _b_x115_132;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun447(kk_function_t _fself, int32_t _b_x116, kk_std_core_hnd__ev _b_x117, kk_box_t _b_x118, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_gan__ying_main_fun447__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_gan__ying_main_fun447__t*, _fself, _ctx);
  kk_function_t _b_x115_132 = _self->_b_x115_132; /* (m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 1561 */
  kk_drop_match(_self, {kk_function_dup(_b_x115_132, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x448 = kk_std_core_exn__exception_unbox(_b_x118, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x115_132, (_b_x115_132, _b_x116, _b_x117, _x_x448, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_main_fun449__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun449(kk_function_t _fself, kk_box_t _b_x128, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_main_fun449(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying_main_fun449, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun449(kk_function_t _fself, kk_box_t _b_x128, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_139 = kk_Unit;
  kk_unit_unbox(_b_x128);
  return kk_unit_box(_res_139);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_main_fun450__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun450(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_main_fun450(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying_main_fun450, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_main_fun454__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun454(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_main_fun454(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying_main_fun454, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun454(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x455 = kk_Unit;
  kk_whitemagic_dash_koka_src_gan__ying_flush_stdout(_ctx);
  return kk_unit_box(_x_x455);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_gan__ying_main_fun456__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun456(kk_function_t _fself, kk_box_t _b_x124, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_gan__ying_new_main_fun456(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_gan__ying_main_fun456, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun456(kk_function_t _fself, kk_box_t _b_x124, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x457 = kk_Unit;
  kk_integer_t _x_x458 = kk_integer_unbox(_b_x124, _ctx); /*int*/
  kk_whitemagic_dash_koka_src_gan__ying_server_loop(_x_x458, _ctx);
  return kk_unit_box(_x_x457);
}
static kk_box_t kk_whitemagic_dash_koka_src_gan__ying_main_fun450(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x451;
  kk_define_string_literal(, _s_x452, 43, "{\"status\":\"started\",\"component\":\"gan_ying\"}", _ctx)
  _x_x451 = kk_string_dup(_s_x452, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x451, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x453 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_gan__ying_new_main_fun454(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x453);
  kk_ssize_t _b_x121_135 = (KK_IZ(0)); /*hnd/ev-index*/;
  return kk_std_core_hnd__open_at1(_b_x121_135, kk_whitemagic_dash_koka_src_gan__ying_new_main_fun456(_ctx), kk_integer_box(kk_integer_from_small(0), _ctx), _ctx);
}

kk_unit_t kk_whitemagic_dash_koka_src_gan__ying_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_box_t _x_x440;
  kk_function_t _b_x115_132 = kk_whitemagic_dash_koka_src_gan__ying_new_main_fun441(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 1561*/;
  kk_std_core_exn__exn _x_x445;
  kk_std_core_hnd__clause1 _x_x446 = kk_std_core_hnd__new_Clause1(kk_whitemagic_dash_koka_src_gan__ying_new_main_fun447(_b_x115_132, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x445 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x446, _ctx); /*exn<10005,10006>*/
  _x_x440 = kk_std_core_exn_exn_fs__handle(_x_x445, kk_whitemagic_dash_koka_src_gan__ying_new_main_fun449(_ctx), kk_whitemagic_dash_koka_src_gan__ying_new_main_fun450(_ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x440); return kk_Unit;
}

// initialization
void kk_whitemagic_dash_koka_src_gan__ying__init(kk_context_t* _ctx){
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
void kk_whitemagic_dash_koka_src_gan__ying__done(kk_context_t* _ctx){
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
