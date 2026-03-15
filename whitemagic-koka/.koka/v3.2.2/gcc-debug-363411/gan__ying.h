#pragma once
#ifndef kk_gan__ying_H
#define kk_gan__ying_H
// Koka generated module: gan_ying, koka version: 3.2.2, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"
#include "std_core_bool.h"
#include "std_core_order.h"
#include "std_core_char.h"
#include "std_core_int.h"
#include "std_core_vector.h"
#include "std_core_string.h"
#include "std_core_sslice.h"
#include "std_core_list.h"
#include "std_core_maybe.h"
#include "std_core_maybe2.h"
#include "std_core_either.h"
#include "std_core_tuple.h"
#include "std_core_lazy.h"
#include "std_core_show.h"
#include "std_core_debug.h"
#include "std_core_delayed.h"
#include "std_core_console.h"
#include "std_core.h"
#include "std_os_readline.h"
#include "std_num_float64.h"

// type declarations

// value type gan_ying/event-type
enum kk_gan__ying__event_type_e {
  kk_gan__ying_SystemStarted,
  kk_gan__ying_SystemStopped,
  kk_gan__ying_SystemHealthChanged,
  kk_gan__ying_MemoryCreated,
  kk_gan__ying_MemoryUpdated,
  kk_gan__ying_MemoryRecalled,
  kk_gan__ying_MemoryConsolidated,
  kk_gan__ying_GardenActivated,
  kk_gan__ying_JoyTriggered,
  kk_gan__ying_WisdomIntegrated,
  kk_gan__ying_ThreatDetected,
  kk_gan__ying_AnomalyDetected,
  kk_gan__ying_FlowStateEntered,
  kk_gan__ying_FlowStateExited
};
typedef uint8_t kk_gan__ying__event_type;

static inline kk_gan__ying__event_type kk_gan__ying__new_SystemStarted(kk_context_t* _ctx) {
  return kk_gan__ying_SystemStarted;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_SystemStopped(kk_context_t* _ctx) {
  return kk_gan__ying_SystemStopped;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_SystemHealthChanged(kk_context_t* _ctx) {
  return kk_gan__ying_SystemHealthChanged;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_MemoryCreated(kk_context_t* _ctx) {
  return kk_gan__ying_MemoryCreated;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_MemoryUpdated(kk_context_t* _ctx) {
  return kk_gan__ying_MemoryUpdated;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_MemoryRecalled(kk_context_t* _ctx) {
  return kk_gan__ying_MemoryRecalled;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_MemoryConsolidated(kk_context_t* _ctx) {
  return kk_gan__ying_MemoryConsolidated;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_GardenActivated(kk_context_t* _ctx) {
  return kk_gan__ying_GardenActivated;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_JoyTriggered(kk_context_t* _ctx) {
  return kk_gan__ying_JoyTriggered;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_WisdomIntegrated(kk_context_t* _ctx) {
  return kk_gan__ying_WisdomIntegrated;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_ThreatDetected(kk_context_t* _ctx) {
  return kk_gan__ying_ThreatDetected;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_AnomalyDetected(kk_context_t* _ctx) {
  return kk_gan__ying_AnomalyDetected;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_FlowStateEntered(kk_context_t* _ctx) {
  return kk_gan__ying_FlowStateEntered;
}
static inline kk_gan__ying__event_type kk_gan__ying__new_FlowStateExited(kk_context_t* _ctx) {
  return kk_gan__ying_FlowStateExited;
}
static inline bool kk_gan__ying__is_SystemStarted(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_SystemStarted);
}
static inline bool kk_gan__ying__is_SystemStopped(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_SystemStopped);
}
static inline bool kk_gan__ying__is_SystemHealthChanged(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_SystemHealthChanged);
}
static inline bool kk_gan__ying__is_MemoryCreated(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_MemoryCreated);
}
static inline bool kk_gan__ying__is_MemoryUpdated(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_MemoryUpdated);
}
static inline bool kk_gan__ying__is_MemoryRecalled(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_MemoryRecalled);
}
static inline bool kk_gan__ying__is_MemoryConsolidated(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_MemoryConsolidated);
}
static inline bool kk_gan__ying__is_GardenActivated(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_GardenActivated);
}
static inline bool kk_gan__ying__is_JoyTriggered(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_JoyTriggered);
}
static inline bool kk_gan__ying__is_WisdomIntegrated(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_WisdomIntegrated);
}
static inline bool kk_gan__ying__is_ThreatDetected(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_ThreatDetected);
}
static inline bool kk_gan__ying__is_AnomalyDetected(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_AnomalyDetected);
}
static inline bool kk_gan__ying__is_FlowStateEntered(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_FlowStateEntered);
}
static inline bool kk_gan__ying__is_FlowStateExited(kk_gan__ying__event_type x, kk_context_t* _ctx) {
  return (x == kk_gan__ying_FlowStateExited);
}
static inline kk_gan__ying__event_type kk_gan__ying__event_type_dup(kk_gan__ying__event_type _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_gan__ying__event_type_drop(kk_gan__ying__event_type _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_gan__ying__event_type_box(kk_gan__ying__event_type _x, kk_context_t* _ctx) {
  return kk_enum_box(_x);
}
static inline kk_gan__ying__event_type kk_gan__ying__event_type_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return (kk_gan__ying__event_type)kk_enum_unbox(_x);
}

// type gan_ying/cascade-trigger
struct kk_gan__ying__cascade_trigger_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_gan__ying__cascade_trigger;
struct kk_gan__ying_Cascade_trigger {
  struct kk_gan__ying__cascade_trigger_s _base;
  kk_integer_t handler_count;
  kk_integer_t priority;
  kk_gan__ying__event_type event_type;
};
static inline kk_gan__ying__cascade_trigger kk_gan__ying__base_Cascade_trigger(struct kk_gan__ying_Cascade_trigger* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_gan__ying__cascade_trigger kk_gan__ying__new_Cascade_trigger(kk_reuse_t _at, int32_t _cpath, kk_gan__ying__event_type event_type, kk_integer_t handler_count, kk_integer_t priority, kk_context_t* _ctx) {
  struct kk_gan__ying_Cascade_trigger* _con = kk_block_alloc_at_as(struct kk_gan__ying_Cascade_trigger, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->handler_count = handler_count;
  _con->priority = priority;
  _con->event_type = event_type;
  return kk_gan__ying__base_Cascade_trigger(_con, _ctx);
}
static inline struct kk_gan__ying_Cascade_trigger* kk_gan__ying__as_Cascade_trigger(kk_gan__ying__cascade_trigger x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_gan__ying_Cascade_trigger*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_gan__ying__is_Cascade_trigger(kk_gan__ying__cascade_trigger x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_gan__ying__cascade_trigger kk_gan__ying__cascade_trigger_dup(kk_gan__ying__cascade_trigger _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_gan__ying__cascade_trigger_drop(kk_gan__ying__cascade_trigger _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_gan__ying__cascade_trigger_box(kk_gan__ying__cascade_trigger _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_gan__ying__cascade_trigger kk_gan__ying__cascade_trigger_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type gan_ying/resonance-event
struct kk_gan__ying__resonance_event_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_gan__ying__resonance_event;
struct kk_gan__ying_Resonance_event {
  struct kk_gan__ying__resonance_event_s _base;
  kk_string_t source;
  kk_string_t data;
  kk_integer_t timestamp;
  double confidence;
  kk_gan__ying__event_type event_type;
};
static inline kk_gan__ying__resonance_event kk_gan__ying__base_Resonance_event(struct kk_gan__ying_Resonance_event* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_gan__ying__resonance_event kk_gan__ying__new_Resonance_event(kk_reuse_t _at, int32_t _cpath, kk_string_t source, kk_gan__ying__event_type event_type, kk_string_t data, kk_integer_t timestamp, double confidence, kk_context_t* _ctx) {
  struct kk_gan__ying_Resonance_event* _con = kk_block_alloc_at_as(struct kk_gan__ying_Resonance_event, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->source = source;
  _con->data = data;
  _con->timestamp = timestamp;
  _con->confidence = confidence;
  _con->event_type = event_type;
  return kk_gan__ying__base_Resonance_event(_con, _ctx);
}
static inline struct kk_gan__ying_Resonance_event* kk_gan__ying__as_Resonance_event(kk_gan__ying__resonance_event x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_gan__ying_Resonance_event*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_gan__ying__is_Resonance_event(kk_gan__ying__resonance_event x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_gan__ying__resonance_event kk_gan__ying__resonance_event_dup(kk_gan__ying__resonance_event _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_gan__ying__resonance_event_drop(kk_gan__ying__resonance_event _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_gan__ying__resonance_event_box(kk_gan__ying__resonance_event _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_gan__ying__resonance_event kk_gan__ying__resonance_event_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Tests for the `SystemStarted` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_systemStarted(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_SystemStarted(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `SystemStopped` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_systemStopped(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_SystemStopped(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `SystemHealthChanged` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_systemHealthChanged(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_SystemHealthChanged(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `MemoryCreated` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_memoryCreated(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_MemoryCreated(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `MemoryUpdated` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_memoryUpdated(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_MemoryUpdated(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `MemoryRecalled` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_memoryRecalled(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_MemoryRecalled(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `MemoryConsolidated` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_memoryConsolidated(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_MemoryConsolidated(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GardenActivated` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_gardenActivated(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_GardenActivated(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `JoyTriggered` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_joyTriggered(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_JoyTriggered(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `WisdomIntegrated` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_wisdomIntegrated(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_WisdomIntegrated(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `ThreatDetected` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_threatDetected(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_ThreatDetected(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `AnomalyDetected` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_anomalyDetected(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_AnomalyDetected(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `FlowStateEntered` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_flowStateEntered(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_FlowStateEntered(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `FlowStateExited` constructor of the `:event-type` type.

static inline bool kk_gan__ying_is_flowStateExited(kk_gan__ying__event_type event_type, kk_context_t* _ctx) { /* (event-type : event-type) -> bool */ 
  if (kk_gan__ying__is_FlowStateExited(event_type, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Retrieves the `source` constructor field of the `:resonance-event` type.

static inline kk_string_t kk_gan__ying_resonance_event_fs_source(kk_gan__ying__resonance_event _this, kk_context_t* _ctx) { /* (resonance-event) -> string */ 
  {
    struct kk_gan__ying_Resonance_event* _con_x178 = kk_gan__ying__as_Resonance_event(_this, _ctx);
    kk_string_t _x = _con_x178->source;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `event-type` constructor field of the `:resonance-event` type.

static inline kk_gan__ying__event_type kk_gan__ying_resonance_event_fs_event_type(kk_gan__ying__resonance_event _this, kk_context_t* _ctx) { /* (resonance-event) -> event-type */ 
  {
    struct kk_gan__ying_Resonance_event* _con_x179 = kk_gan__ying__as_Resonance_event(_this, _ctx);
    kk_gan__ying__event_type _x = _con_x179->event_type;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `data` constructor field of the `:resonance-event` type.

static inline kk_string_t kk_gan__ying_resonance_event_fs_data(kk_gan__ying__resonance_event _this, kk_context_t* _ctx) { /* (resonance-event) -> string */ 
  {
    struct kk_gan__ying_Resonance_event* _con_x180 = kk_gan__ying__as_Resonance_event(_this, _ctx);
    kk_string_t _x = _con_x180->data;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `timestamp` constructor field of the `:resonance-event` type.

static inline kk_integer_t kk_gan__ying_resonance_event_fs_timestamp(kk_gan__ying__resonance_event _this, kk_context_t* _ctx) { /* (resonance-event) -> int */ 
  {
    struct kk_gan__ying_Resonance_event* _con_x181 = kk_gan__ying__as_Resonance_event(_this, _ctx);
    kk_integer_t _x = _con_x181->timestamp;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `confidence` constructor field of the `:resonance-event` type.

static inline double kk_gan__ying_resonance_event_fs_confidence(kk_gan__ying__resonance_event _this, kk_context_t* _ctx) { /* (resonance-event) -> float64 */ 
  {
    struct kk_gan__ying_Resonance_event* _con_x182 = kk_gan__ying__as_Resonance_event(_this, _ctx);
    double _x = _con_x182->confidence;
    return _x;
  }
}

kk_gan__ying__resonance_event kk_gan__ying_resonance_event_fs__copy(kk_gan__ying__resonance_event _this, kk_std_core_types__optional source, kk_std_core_types__optional event_type, kk_std_core_types__optional data, kk_std_core_types__optional timestamp, kk_std_core_types__optional confidence, kk_context_t* _ctx); /* (resonance-event, source : ? string, event-type : ? event-type, data : ? string, timestamp : ? int, confidence : ? float64) -> resonance-event */ 
 
// Automatically generated. Retrieves the `event-type` constructor field of the `:cascade-trigger` type.

static inline kk_gan__ying__event_type kk_gan__ying_cascade_trigger_fs_event_type(kk_gan__ying__cascade_trigger _this, kk_context_t* _ctx) { /* (cascade-trigger) -> event-type */ 
  {
    struct kk_gan__ying_Cascade_trigger* _con_x193 = kk_gan__ying__as_Cascade_trigger(_this, _ctx);
    kk_gan__ying__event_type _x = _con_x193->event_type;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `handler-count` constructor field of the `:cascade-trigger` type.

static inline kk_integer_t kk_gan__ying_cascade_trigger_fs_handler_count(kk_gan__ying__cascade_trigger _this, kk_context_t* _ctx) { /* (cascade-trigger) -> int */ 
  {
    struct kk_gan__ying_Cascade_trigger* _con_x194 = kk_gan__ying__as_Cascade_trigger(_this, _ctx);
    kk_integer_t _x = _con_x194->handler_count;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `priority` constructor field of the `:cascade-trigger` type.

static inline kk_integer_t kk_gan__ying_cascade_trigger_fs_priority(kk_gan__ying__cascade_trigger _this, kk_context_t* _ctx) { /* (cascade-trigger) -> int */ 
  {
    struct kk_gan__ying_Cascade_trigger* _con_x195 = kk_gan__ying__as_Cascade_trigger(_this, _ctx);
    kk_integer_t _x = _con_x195->priority;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_gan__ying__cascade_trigger kk_gan__ying_cascade_trigger_fs__copy(kk_gan__ying__cascade_trigger _this, kk_std_core_types__optional event_type, kk_std_core_types__optional handler_count, kk_std_core_types__optional priority, kk_context_t* _ctx); /* (cascade-trigger, event-type : ? event-type, handler-count : ? int, priority : ? int) -> cascade-trigger */ 

kk_string_t kk_gan__ying_event_type_to_string(kk_gan__ying__event_type et, kk_context_t* _ctx); /* (et : event-type) -> string */ 

kk_gan__ying__event_type kk_gan__ying_string_to_event_type(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> event-type */ 

static inline kk_std_core_types__tuple2 kk_gan__ying_emit_event(kk_string_t source, kk_gan__ying__event_type et, kk_string_t data, double confidence, kk_integer_t count, kk_context_t* _ctx) { /* (source : string, et : event-type, data : string, confidence : float64, count : int) -> (resonance-event, int) */ 
  kk_integer_t new_count = kk_integer_add_small_const(count, 1, _ctx); /*int*/;
  kk_box_t _x_x216;
  kk_gan__ying__resonance_event _x_x217 = kk_gan__ying__new_Resonance_event(kk_reuse_null, 0, source, et, data, kk_integer_from_small(0), confidence, _ctx); /*gan_ying/resonance-event*/
  _x_x216 = kk_gan__ying__resonance_event_box(_x_x217, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x216, kk_integer_box(new_count, _ctx), _ctx);
}

kk_gan__ying__cascade_trigger kk_gan__ying_check_cascade(kk_gan__ying__event_type et, kk_context_t* _ctx); /* (et : event-type) -> cascade-trigger */ 

static inline kk_string_t kk_gan__ying_json_response(kk_string_t op, kk_string_t result, kk_context_t* _ctx) { /* (op : string, result : string) -> string */ 
  kk_string_t _x_x222;
  kk_define_string_literal(, _s_x223, 7, "{\"op\":\"", _ctx)
  _x_x222 = kk_string_dup(_s_x223, _ctx); /*string*/
  kk_string_t _x_x224;
  kk_string_t _x_x225;
  kk_string_t _x_x226;
  kk_define_string_literal(, _s_x227, 12, "\",\"result\":\"", _ctx)
  _x_x226 = kk_string_dup(_s_x227, _ctx); /*string*/
  kk_string_t _x_x228;
  kk_string_t _x_x229;
  kk_define_string_literal(, _s_x230, 2, "\"}", _ctx)
  _x_x229 = kk_string_dup(_s_x230, _ctx); /*string*/
  _x_x228 = kk_std_core_types__lp__plus__plus__rp_(result, _x_x229, _ctx); /*string*/
  _x_x225 = kk_std_core_types__lp__plus__plus__rp_(_x_x226, _x_x228, _ctx); /*string*/
  _x_x224 = kk_std_core_types__lp__plus__plus__rp_(op, _x_x225, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x222, _x_x224, _ctx);
}

kk_string_t kk_gan__ying_json_event_response(kk_gan__ying__resonance_event event, kk_context_t* _ctx); /* (event : resonance-event) -> string */ 

kk_string_t kk_gan__ying_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_gan__ying__event_type kk_gan__ying_extract_type(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> event-type */ 

kk_unit_t kk_gan__ying__mlift_server_loop_10056(kk_integer_t event_count, kk_string_t op, kk_string_t _c_x10017, kk_context_t* _ctx); /* (event-count : int, op : string, string) -> () */ 

kk_unit_t kk_gan__ying__mlift_server_loop_10057(kk_integer_t event_count_0, kk_string_t line, kk_context_t* _ctx); /* (event-count : int, line : string) -> <console/console,exn> () */ 

kk_unit_t kk_gan__ying_server_loop(kk_integer_t event_count_1, kk_context_t* _ctx); /* (event-count : int) -> io () */ 

static inline kk_unit_t kk_gan__ying_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_gan__ying_server_loop(kk_integer_from_small(0), _ctx); return kk_Unit;
}

void kk_gan__ying__init(kk_context_t* _ctx);


void kk_gan__ying__done(kk_context_t* _ctx);

#endif // header
