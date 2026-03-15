#pragma once
#ifndef kk_src_effects_prat__resonance_H
#define kk_src_effects_prat__resonance_H
// Koka generated module: src/effects/prat_resonance, koka version: 3.2.2, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"
#include "std_core_bool.h"
#include "std_core_order.h"
#include "std_core_char.h"
#include "std_core_int.h"
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
#include "std_time_duration.h"
#include "std_time_instant.h"
#include "std_time_utc.h"
#include "std_time_chrono.h"
#include "std_time_timer.h"
#include "std_time_date.h"
#include "std_time_calendar.h"
#include "std_time_calendars.h"
#include "std_time_time.h"
#include "std_time_locale.h"
#include "std_time_format.h"
#include "std_time_parse.h"
#include "std_core.h"
#include "std_time.h"
#include "std_num_random.h"
#include "std_core_vector.h"
#include "std_num_float64.h"

// type declarations

// type src/effects/prat_resonance/ganainfo
struct kk_src_effects_prat__resonance__ganainfo_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_effects_prat__resonance__ganainfo;
struct kk_src_effects_prat__resonance_Ganainfo {
  struct kk_src_effects_prat__resonance__ganainfo_s _base;
  kk_integer_t mansion_num;
  kk_string_t quadrant;
  kk_string_t meaning;
  kk_string_t garden;
  kk_string_t chinese;
  kk_string_t pinyin;
};
static inline kk_src_effects_prat__resonance__ganainfo kk_src_effects_prat__resonance__base_Ganainfo(struct kk_src_effects_prat__resonance_Ganainfo* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_effects_prat__resonance__ganainfo kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_t _at, int32_t _cpath, kk_integer_t mansion_num, kk_string_t quadrant, kk_string_t meaning, kk_string_t garden, kk_string_t chinese, kk_string_t pinyin, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_Ganainfo* _con = kk_block_alloc_at_as(struct kk_src_effects_prat__resonance_Ganainfo, _at, 6 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->mansion_num = mansion_num;
  _con->quadrant = quadrant;
  _con->meaning = meaning;
  _con->garden = garden;
  _con->chinese = chinese;
  _con->pinyin = pinyin;
  return kk_src_effects_prat__resonance__base_Ganainfo(_con, _ctx);
}
static inline struct kk_src_effects_prat__resonance_Ganainfo* kk_src_effects_prat__resonance__as_Ganainfo(kk_src_effects_prat__resonance__ganainfo x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_effects_prat__resonance_Ganainfo*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_effects_prat__resonance__is_Ganainfo(kk_src_effects_prat__resonance__ganainfo x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_effects_prat__resonance__ganainfo kk_src_effects_prat__resonance__ganainfo_dup(kk_src_effects_prat__resonance__ganainfo _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_effects_prat__resonance__ganainfo_drop(kk_src_effects_prat__resonance__ganainfo _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_effects_prat__resonance__ganainfo_box(kk_src_effects_prat__resonance__ganainfo _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_effects_prat__resonance__ganainfo kk_src_effects_prat__resonance__ganainfo_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/effects/prat_resonance/snapshot
struct kk_src_effects_prat__resonance__snapshot_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_effects_prat__resonance__snapshot;
struct kk_src_effects_prat__resonance_Snapshot {
  struct kk_src_effects_prat__resonance__snapshot_s _base;
  kk_string_t gana_name;
  kk_string_t tool_name;
  kk_string_t operation;
  kk_string_t output_preview;
  kk_integer_t lunar_mansion_num;
  kk_string_t guna_tag;
  kk_string_t quadrant;
  kk_string_t successor_hint;
  double timestamp;
  double lunar_phase;
  double harmony_score;
};
static inline kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance__base_Snapshot(struct kk_src_effects_prat__resonance_Snapshot* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance__new_Snapshot(kk_reuse_t _at, int32_t _cpath, kk_string_t gana_name, kk_string_t tool_name, kk_string_t operation, kk_string_t output_preview, double timestamp, double lunar_phase, kk_integer_t lunar_mansion_num, double harmony_score, kk_string_t guna_tag, kk_string_t quadrant, kk_string_t successor_hint, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_Snapshot* _con = kk_block_alloc_at_as(struct kk_src_effects_prat__resonance_Snapshot, _at, 8 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->gana_name = gana_name;
  _con->tool_name = tool_name;
  _con->operation = operation;
  _con->output_preview = output_preview;
  _con->lunar_mansion_num = lunar_mansion_num;
  _con->guna_tag = guna_tag;
  _con->quadrant = quadrant;
  _con->successor_hint = successor_hint;
  _con->timestamp = timestamp;
  _con->lunar_phase = lunar_phase;
  _con->harmony_score = harmony_score;
  return kk_src_effects_prat__resonance__base_Snapshot(_con, _ctx);
}
static inline struct kk_src_effects_prat__resonance_Snapshot* kk_src_effects_prat__resonance__as_Snapshot(kk_src_effects_prat__resonance__snapshot x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_effects_prat__resonance_Snapshot*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_effects_prat__resonance__is_Snapshot(kk_src_effects_prat__resonance__snapshot x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance__snapshot_dup(kk_src_effects_prat__resonance__snapshot _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_effects_prat__resonance__snapshot_drop(kk_src_effects_prat__resonance__snapshot _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_effects_prat__resonance__snapshot_box(kk_src_effects_prat__resonance__snapshot _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance__snapshot_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/effects/prat_resonance/resonance
struct kk_src_effects_prat__resonance__resonance_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_effects_prat__resonance__resonance;
struct kk_src_effects_prat__resonance__Hnd_resonance {
  struct kk_src_effects_prat__resonance__resonance_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause0 _fun_get_call_count;
  kk_std_core_hnd__clause0 _fun_get_gana_counts;
  kk_std_core_hnd__clause0 _fun_get_guna_tag;
  kk_std_core_hnd__clause0 _fun_get_harmony_score;
  kk_std_core_hnd__clause0 _fun_get_last_snapshot;
  kk_std_core_hnd__clause0 _fun_get_lunar_mansion;
  kk_std_core_hnd__clause0 _fun_get_lunar_phase;
  kk_std_core_hnd__clause1 _fun_get_recent_history;
  kk_std_core_hnd__clause1 _fun_record_snapshot;
  kk_std_core_hnd__clause0 _fun_reset_state;
};
static inline kk_src_effects_prat__resonance__resonance kk_src_effects_prat__resonance__base_Hnd_resonance(struct kk_src_effects_prat__resonance__Hnd_resonance* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_effects_prat__resonance__resonance kk_src_effects_prat__resonance__new_Hnd_resonance(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause0 _fun_get_call_count, kk_std_core_hnd__clause0 _fun_get_gana_counts, kk_std_core_hnd__clause0 _fun_get_guna_tag, kk_std_core_hnd__clause0 _fun_get_harmony_score, kk_std_core_hnd__clause0 _fun_get_last_snapshot, kk_std_core_hnd__clause0 _fun_get_lunar_mansion, kk_std_core_hnd__clause0 _fun_get_lunar_phase, kk_std_core_hnd__clause1 _fun_get_recent_history, kk_std_core_hnd__clause1 _fun_record_snapshot, kk_std_core_hnd__clause0 _fun_reset_state, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance__Hnd_resonance* _con = kk_block_alloc_at_as(struct kk_src_effects_prat__resonance__Hnd_resonance, _at, 11 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_get_call_count = _fun_get_call_count;
  _con->_fun_get_gana_counts = _fun_get_gana_counts;
  _con->_fun_get_guna_tag = _fun_get_guna_tag;
  _con->_fun_get_harmony_score = _fun_get_harmony_score;
  _con->_fun_get_last_snapshot = _fun_get_last_snapshot;
  _con->_fun_get_lunar_mansion = _fun_get_lunar_mansion;
  _con->_fun_get_lunar_phase = _fun_get_lunar_phase;
  _con->_fun_get_recent_history = _fun_get_recent_history;
  _con->_fun_record_snapshot = _fun_record_snapshot;
  _con->_fun_reset_state = _fun_reset_state;
  return kk_src_effects_prat__resonance__base_Hnd_resonance(_con, _ctx);
}
static inline struct kk_src_effects_prat__resonance__Hnd_resonance* kk_src_effects_prat__resonance__as_Hnd_resonance(kk_src_effects_prat__resonance__resonance x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_effects_prat__resonance__Hnd_resonance*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_effects_prat__resonance__is_Hnd_resonance(kk_src_effects_prat__resonance__resonance x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_effects_prat__resonance__resonance kk_src_effects_prat__resonance__resonance_dup(kk_src_effects_prat__resonance__resonance _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_effects_prat__resonance__resonance_drop(kk_src_effects_prat__resonance__resonance _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_effects_prat__resonance__resonance_box(kk_src_effects_prat__resonance__resonance _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_effects_prat__resonance__resonance kk_src_effects_prat__resonance__resonance_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/effects/prat_resonance/resonance-hints
struct kk_src_effects_prat__resonance__resonance_hints_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_effects_prat__resonance__resonance_hints;
struct kk_src_effects_prat__resonance_Resonance_hints {
  struct kk_src_effects_prat__resonance__resonance_hints_s _base;
  kk_string_t predecessor;
  kk_string_t successor;
  kk_integer_t lunar_mansion_num;
  kk_string_t guna_tag;
  kk_string_t quadrant;
  double lunar_phase;
  double harmony_score;
};
static inline kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__base_Resonance_hints(struct kk_src_effects_prat__resonance_Resonance_hints* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__new_Resonance_hints(kk_reuse_t _at, int32_t _cpath, kk_string_t predecessor, kk_string_t successor, double lunar_phase, kk_integer_t lunar_mansion_num, double harmony_score, kk_string_t guna_tag, kk_string_t quadrant, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_Resonance_hints* _con = kk_block_alloc_at_as(struct kk_src_effects_prat__resonance_Resonance_hints, _at, 5 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->predecessor = predecessor;
  _con->successor = successor;
  _con->lunar_mansion_num = lunar_mansion_num;
  _con->guna_tag = guna_tag;
  _con->quadrant = quadrant;
  _con->lunar_phase = lunar_phase;
  _con->harmony_score = harmony_score;
  return kk_src_effects_prat__resonance__base_Resonance_hints(_con, _ctx);
}
static inline struct kk_src_effects_prat__resonance_Resonance_hints* kk_src_effects_prat__resonance__as_Resonance_hints(kk_src_effects_prat__resonance__resonance_hints x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_effects_prat__resonance_Resonance_hints*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_effects_prat__resonance__is_Resonance_hints(kk_src_effects_prat__resonance__resonance_hints x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__resonance_hints_dup(kk_src_effects_prat__resonance__resonance_hints _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_effects_prat__resonance__resonance_hints_drop(kk_src_effects_prat__resonance__resonance_hints _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_effects_prat__resonance__resonance_hints_box(kk_src_effects_prat__resonance__resonance_hints _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__resonance_hints_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/effects/prat_resonance/resonance-state
struct kk_src_effects_prat__resonance__resonance_state_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_effects_prat__resonance__resonance_state;
struct kk_src_effects_prat__resonance_Resonance_state {
  struct kk_src_effects_prat__resonance__resonance_state_s _base;
  kk_std_core_types__maybe last_snapshot;
  kk_std_core_types__list history;
  kk_std_core_types__list gana_counts;
  kk_integer_t session_calls;
};
static inline kk_src_effects_prat__resonance__resonance_state kk_src_effects_prat__resonance__base_Resonance_state(struct kk_src_effects_prat__resonance_Resonance_state* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_effects_prat__resonance__resonance_state kk_src_effects_prat__resonance__new_Resonance_state(kk_reuse_t _at, int32_t _cpath, kk_std_core_types__maybe last_snapshot, kk_std_core_types__list history, kk_std_core_types__list gana_counts, kk_integer_t session_calls, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_Resonance_state* _con = kk_block_alloc_at_as(struct kk_src_effects_prat__resonance_Resonance_state, _at, 5 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->last_snapshot = last_snapshot;
  _con->history = history;
  _con->gana_counts = gana_counts;
  _con->session_calls = session_calls;
  return kk_src_effects_prat__resonance__base_Resonance_state(_con, _ctx);
}
static inline struct kk_src_effects_prat__resonance_Resonance_state* kk_src_effects_prat__resonance__as_Resonance_state(kk_src_effects_prat__resonance__resonance_state x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_effects_prat__resonance_Resonance_state*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_effects_prat__resonance__is_Resonance_state(kk_src_effects_prat__resonance__resonance_state x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_effects_prat__resonance__resonance_state kk_src_effects_prat__resonance__resonance_state_dup(kk_src_effects_prat__resonance__resonance_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_effects_prat__resonance__resonance_state_drop(kk_src_effects_prat__resonance__resonance_state _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_effects_prat__resonance__resonance_state_box(kk_src_effects_prat__resonance__resonance_state _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_effects_prat__resonance__resonance_state kk_src_effects_prat__resonance__resonance_state_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:resonance` type.

static inline kk_integer_t kk_src_effects_prat__resonance_resonance_fs__cfc(kk_src_effects_prat__resonance__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> int */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x944 = kk_src_effects_prat__resonance__as_Hnd_resonance(resonance, _ctx);
    kk_integer_t _x = _con_x944->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_src_effects_prat__resonance_resonance_fs__tag;

kk_box_t kk_src_effects_prat__resonance_resonance_fs__handle(kk_src_effects_prat__resonance__resonance hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : resonance<e,b>, ret : (res : a) -> e b, action : () -> <resonance|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-get-last-snapshot` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_resonance_fs__fun_get_last_snapshot(kk_src_effects_prat__resonance__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause0<snapshot,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x948 = kk_src_effects_prat__resonance__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x948->_fun_get_last_snapshot;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-last-snapshot` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_get_last_snapshot_fs__select(kk_src_effects_prat__resonance__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause0<snapshot,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x949 = kk_src_effects_prat__resonance__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_last_snapshot = _con_x949->_fun_get_last_snapshot;
    return kk_std_core_hnd__clause0_dup(_fun_get_last_snapshot, _ctx);
  }
}
 
// Core resonance operations
// Call the `fun get-last-snapshot` operation of the effect `:resonance`

static inline kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance_get_last_snapshot(kk_context_t* _ctx) { /* () -> resonance snapshot */ 
  kk_std_core_hnd__ev ev_10122 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_box_t _x_x950;
  {
    struct kk_std_core_hnd_Ev* _con_x951 = kk_std_core_hnd__as_Ev(ev_10122, _ctx);
    kk_box_t _box_x8 = _con_x951->hnd;
    int32_t m = _con_x951->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x952 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x952->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x952->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x952->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_3 = _con_x952->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_4 = _con_x952->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _fun_get_last_snapshot = _con_x952->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_5 = _con_x952->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_6 = _con_x952->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_7 = _con_x952->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8 = _con_x952->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x952->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_last_snapshot, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x11 = _fun_get_last_snapshot.clause;
        _x_x950 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x11, (_fun_unbox_x11, m, ev_10122, _ctx), _ctx); /*35*/
      }
    }
  }
  return kk_src_effects_prat__resonance__snapshot_unbox(_x_x950, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-record-snapshot` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause1 kk_src_effects_prat__resonance_resonance_fs__fun_record_snapshot(kk_src_effects_prat__resonance__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause1<snapshot,(),resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x953 = kk_src_effects_prat__resonance__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x953->_fun_record_snapshot;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `record-snapshot` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause1 kk_src_effects_prat__resonance_record_snapshot_fs__select(kk_src_effects_prat__resonance__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause1<snapshot,(),resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x954 = kk_src_effects_prat__resonance__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_record_snapshot = _con_x954->_fun_record_snapshot;
    return kk_std_core_hnd__clause1_dup(_fun_record_snapshot, _ctx);
  }
}
 
// Call the `fun record-snapshot` operation of the effect `:resonance`

static inline kk_unit_t kk_src_effects_prat__resonance_record_snapshot(kk_src_effects_prat__resonance__snapshot snap, kk_context_t* _ctx) { /* (snap : snapshot) -> resonance () */ 
  kk_std_core_hnd__ev ev_10124 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_box_t _x_x955;
  {
    struct kk_std_core_hnd_Ev* _con_x956 = kk_std_core_hnd__as_Ev(ev_10124, _ctx);
    kk_box_t _box_x14 = _con_x956->hnd;
    int32_t m = _con_x956->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x14, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x957 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x957->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x957->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x957->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_3 = _con_x957->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_4 = _con_x957->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_5 = _con_x957->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_6 = _con_x957->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_7 = _con_x957->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_8 = _con_x957->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _fun_record_snapshot = _con_x957->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x957->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_record_snapshot, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x18 = _fun_record_snapshot.clause;
        _x_x955 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x18, (_fun_unbox_x18, m, ev_10124, kk_src_effects_prat__resonance__snapshot_box(snap, _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  kk_unit_unbox(_x_x955); return kk_Unit;
}
 
// Automatically generated. Retrieves the `@fun-get-call-count` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_resonance_fs__fun_get_call_count(kk_src_effects_prat__resonance__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause0<int,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x958 = kk_src_effects_prat__resonance__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x958->_fun_get_call_count;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-call-count` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_get_call_count_fs__select(kk_src_effects_prat__resonance__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause0<int,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x959 = kk_src_effects_prat__resonance__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_call_count = _con_x959->_fun_get_call_count;
    return kk_std_core_hnd__clause0_dup(_fun_get_call_count, _ctx);
  }
}
 
// Call the `fun get-call-count` operation of the effect `:resonance`

static inline kk_integer_t kk_src_effects_prat__resonance_get_call_count(kk_context_t* _ctx) { /* () -> resonance int */ 
  kk_std_core_hnd__ev ev_10127 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_box_t _x_x960;
  {
    struct kk_std_core_hnd_Ev* _con_x961 = kk_std_core_hnd__as_Ev(ev_10127, _ctx);
    kk_box_t _box_x22 = _con_x961->hnd;
    int32_t m = _con_x961->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x22, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x962 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x962->_cfc;
      kk_std_core_hnd__clause0 _fun_get_call_count = _con_x962->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x962->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x962->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_3 = _con_x962->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_4 = _con_x962->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_5 = _con_x962->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_6 = _con_x962->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_7 = _con_x962->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8 = _con_x962->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x962->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_call_count, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x25 = _fun_get_call_count.clause;
        _x_x960 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x25, (_fun_unbox_x25, m, ev_10127, _ctx), _ctx); /*35*/
      }
    }
  }
  return kk_integer_unbox(_x_x960, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-get-gana-counts` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_resonance_fs__fun_get_gana_counts(kk_src_effects_prat__resonance__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause0<list<(string, int)>,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x963 = kk_src_effects_prat__resonance__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x963->_fun_get_gana_counts;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-gana-counts` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_get_gana_counts_fs__select(kk_src_effects_prat__resonance__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause0<list<(string, int)>,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x964 = kk_src_effects_prat__resonance__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_gana_counts = _con_x964->_fun_get_gana_counts;
    return kk_std_core_hnd__clause0_dup(_fun_get_gana_counts, _ctx);
  }
}
 
// Call the `fun get-gana-counts` operation of the effect `:resonance`

static inline kk_std_core_types__list kk_src_effects_prat__resonance_get_gana_counts(kk_context_t* _ctx) { /* () -> resonance list<(string, int)> */ 
  kk_std_core_hnd__ev ev_10129 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_box_t _x_x965;
  {
    struct kk_std_core_hnd_Ev* _con_x966 = kk_std_core_hnd__as_Ev(ev_10129, _ctx);
    kk_box_t _box_x28 = _con_x966->hnd;
    int32_t m = _con_x966->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x28, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x967 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x967->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x967->_fun_get_call_count;
      kk_std_core_hnd__clause0 _fun_get_gana_counts = _con_x967->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x967->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_3 = _con_x967->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_4 = _con_x967->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_5 = _con_x967->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_6 = _con_x967->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_7 = _con_x967->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8 = _con_x967->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x967->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_gana_counts, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x31 = _fun_get_gana_counts.clause;
        _x_x965 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x31, (_fun_unbox_x31, m, ev_10129, _ctx), _ctx); /*35*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x965, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-get-recent-history` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause1 kk_src_effects_prat__resonance_resonance_fs__fun_get_recent_history(kk_src_effects_prat__resonance__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause1<int,list<snapshot>,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x968 = kk_src_effects_prat__resonance__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x968->_fun_get_recent_history;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `get-recent-history` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause1 kk_src_effects_prat__resonance_get_recent_history_fs__select(kk_src_effects_prat__resonance__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause1<int,list<snapshot>,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x969 = kk_src_effects_prat__resonance__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_get_recent_history = _con_x969->_fun_get_recent_history;
    return kk_std_core_hnd__clause1_dup(_fun_get_recent_history, _ctx);
  }
}
 
// Call the `fun get-recent-history` operation of the effect `:resonance`

static inline kk_std_core_types__list kk_src_effects_prat__resonance_get_recent_history(kk_integer_t limit, kk_context_t* _ctx) { /* (limit : int) -> resonance list<snapshot> */ 
  kk_std_core_hnd__ev ev_10131 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_box_t _x_x970;
  {
    struct kk_std_core_hnd_Ev* _con_x971 = kk_std_core_hnd__as_Ev(ev_10131, _ctx);
    kk_box_t _box_x34 = _con_x971->hnd;
    int32_t m = _con_x971->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x34, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x972 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x972->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x972->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x972->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_3 = _con_x972->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_4 = _con_x972->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_5 = _con_x972->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_6 = _con_x972->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_7 = _con_x972->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _fun_get_recent_history = _con_x972->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8 = _con_x972->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x972->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_get_recent_history, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x38 = _fun_get_recent_history.clause;
        _x_x970 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x38, (_fun_unbox_x38, m, ev_10131, kk_integer_box(limit, _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x970, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-reset-state` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_resonance_fs__fun_reset_state(kk_src_effects_prat__resonance__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause0<(),resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x973 = kk_src_effects_prat__resonance__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x973->_fun_reset_state;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `reset-state` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_reset_state_fs__select(kk_src_effects_prat__resonance__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause0<(),resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x974 = kk_src_effects_prat__resonance__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_reset_state = _con_x974->_fun_reset_state;
    return kk_std_core_hnd__clause0_dup(_fun_reset_state, _ctx);
  }
}
 
// Call the `fun reset-state` operation of the effect `:resonance`

static inline kk_unit_t kk_src_effects_prat__resonance_reset_state(kk_context_t* _ctx) { /* () -> resonance () */ 
  kk_std_core_hnd__ev ev_10134 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_box_t _x_x975;
  {
    struct kk_std_core_hnd_Ev* _con_x976 = kk_std_core_hnd__as_Ev(ev_10134, _ctx);
    kk_box_t _box_x42 = _con_x976->hnd;
    int32_t m = _con_x976->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x42, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x977 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x977->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x977->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x977->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_3 = _con_x977->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_4 = _con_x977->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_5 = _con_x977->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_6 = _con_x977->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_7 = _con_x977->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_8 = _con_x977->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_9 = _con_x977->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _fun_reset_state = _con_x977->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_reset_state, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x45 = _fun_reset_state.clause;
        _x_x975 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x45, (_fun_unbox_x45, m, ev_10134, _ctx), _ctx); /*35*/
      }
    }
  }
  kk_unit_unbox(_x_x975); return kk_Unit;
}
 
// Automatically generated. Retrieves the `@fun-get-lunar-phase` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_resonance_fs__fun_get_lunar_phase(kk_src_effects_prat__resonance__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause0<float64,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x978 = kk_src_effects_prat__resonance__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x978->_fun_get_lunar_phase;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-lunar-phase` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_get_lunar_phase_fs__select(kk_src_effects_prat__resonance__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause0<float64,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x979 = kk_src_effects_prat__resonance__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_lunar_phase = _con_x979->_fun_get_lunar_phase;
    return kk_std_core_hnd__clause0_dup(_fun_get_lunar_phase, _ctx);
  }
}
 
// Lunar and harmony state
// Call the `fun get-lunar-phase` operation of the effect `:resonance`

static inline double kk_src_effects_prat__resonance_get_lunar_phase(kk_context_t* _ctx) { /* () -> resonance float64 */ 
  kk_std_core_hnd__ev ev_10136 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_box_t _x_x980;
  {
    struct kk_std_core_hnd_Ev* _con_x981 = kk_std_core_hnd__as_Ev(ev_10136, _ctx);
    kk_box_t _box_x48 = _con_x981->hnd;
    int32_t m = _con_x981->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x48, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x982 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x982->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x982->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x982->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_3 = _con_x982->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_4 = _con_x982->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_5 = _con_x982->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_6 = _con_x982->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _fun_get_lunar_phase = _con_x982->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_7 = _con_x982->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8 = _con_x982->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x982->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_lunar_phase, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x51 = _fun_get_lunar_phase.clause;
        _x_x980 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x51, (_fun_unbox_x51, m, ev_10136, _ctx), _ctx); /*35*/
      }
    }
  }
  return kk_double_unbox(_x_x980, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-get-lunar-mansion` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_resonance_fs__fun_get_lunar_mansion(kk_src_effects_prat__resonance__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause0<int,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x983 = kk_src_effects_prat__resonance__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x983->_fun_get_lunar_mansion;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-lunar-mansion` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_get_lunar_mansion_fs__select(kk_src_effects_prat__resonance__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause0<int,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x984 = kk_src_effects_prat__resonance__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_lunar_mansion = _con_x984->_fun_get_lunar_mansion;
    return kk_std_core_hnd__clause0_dup(_fun_get_lunar_mansion, _ctx);
  }
}
 
// Call the `fun get-lunar-mansion` operation of the effect `:resonance`

static inline kk_integer_t kk_src_effects_prat__resonance_get_lunar_mansion(kk_context_t* _ctx) { /* () -> resonance int */ 
  kk_std_core_hnd__ev ev_10138 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_box_t _x_x985;
  {
    struct kk_std_core_hnd_Ev* _con_x986 = kk_std_core_hnd__as_Ev(ev_10138, _ctx);
    kk_box_t _box_x54 = _con_x986->hnd;
    int32_t m = _con_x986->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x54, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x987 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x987->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x987->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x987->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_3 = _con_x987->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_4 = _con_x987->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_5 = _con_x987->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _fun_get_lunar_mansion = _con_x987->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_6 = _con_x987->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_7 = _con_x987->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8 = _con_x987->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x987->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_lunar_mansion, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x57 = _fun_get_lunar_mansion.clause;
        _x_x985 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x57, (_fun_unbox_x57, m, ev_10138, _ctx), _ctx); /*35*/
      }
    }
  }
  return kk_integer_unbox(_x_x985, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-get-harmony-score` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_resonance_fs__fun_get_harmony_score(kk_src_effects_prat__resonance__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause0<float64,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x988 = kk_src_effects_prat__resonance__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x988->_fun_get_harmony_score;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-harmony-score` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_get_harmony_score_fs__select(kk_src_effects_prat__resonance__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause0<float64,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x989 = kk_src_effects_prat__resonance__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_harmony_score = _con_x989->_fun_get_harmony_score;
    return kk_std_core_hnd__clause0_dup(_fun_get_harmony_score, _ctx);
  }
}
 
// Call the `fun get-harmony-score` operation of the effect `:resonance`

static inline double kk_src_effects_prat__resonance_get_harmony_score(kk_context_t* _ctx) { /* () -> resonance float64 */ 
  kk_std_core_hnd__ev ev_10140 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_box_t _x_x990;
  {
    struct kk_std_core_hnd_Ev* _con_x991 = kk_std_core_hnd__as_Ev(ev_10140, _ctx);
    kk_box_t _box_x60 = _con_x991->hnd;
    int32_t m = _con_x991->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x60, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x992 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x992->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x992->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x992->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_3 = _con_x992->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _fun_get_harmony_score = _con_x992->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_4 = _con_x992->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_5 = _con_x992->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_6 = _con_x992->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_7 = _con_x992->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8 = _con_x992->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x992->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_harmony_score, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x63 = _fun_get_harmony_score.clause;
        _x_x990 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x63, (_fun_unbox_x63, m, ev_10140, _ctx), _ctx); /*35*/
      }
    }
  }
  return kk_double_unbox(_x_x990, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-get-guna-tag` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_resonance_fs__fun_get_guna_tag(kk_src_effects_prat__resonance__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause0<string,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x993 = kk_src_effects_prat__resonance__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x993->_fun_get_guna_tag;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-guna-tag` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause0 kk_src_effects_prat__resonance_get_guna_tag_fs__select(kk_src_effects_prat__resonance__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause0<string,resonance,e,a> */ 
  {
    struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x994 = kk_src_effects_prat__resonance__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_guna_tag = _con_x994->_fun_get_guna_tag;
    return kk_std_core_hnd__clause0_dup(_fun_get_guna_tag, _ctx);
  }
}
 
// Call the `fun get-guna-tag` operation of the effect `:resonance`

static inline kk_string_t kk_src_effects_prat__resonance_get_guna_tag(kk_context_t* _ctx) { /* () -> resonance string */ 
  kk_std_core_hnd__ev ev_10142 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_box_t _x_x995;
  {
    struct kk_std_core_hnd_Ev* _con_x996 = kk_std_core_hnd__as_Ev(ev_10142, _ctx);
    kk_box_t _box_x66 = _con_x996->hnd;
    int32_t m = _con_x996->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x66, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x997 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x997->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x997->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x997->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _fun_get_guna_tag = _con_x997->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_3 = _con_x997->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_4 = _con_x997->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_5 = _con_x997->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_6 = _con_x997->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_7 = _con_x997->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8 = _con_x997->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x997->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_guna_tag, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x69 = _fun_get_guna_tag.clause;
        _x_x995 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x69, (_fun_unbox_x69, m, ev_10142, _ctx), _ctx); /*35*/
      }
    }
  }
  return kk_string_unbox(_x_x995);
}
 
// Automatically generated. Retrieves the `gana-name` constructor field of the `:snapshot` type.

static inline kk_string_t kk_src_effects_prat__resonance_snapshot_fs_gana_name(kk_src_effects_prat__resonance__snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : snapshot) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x998 = kk_src_effects_prat__resonance__as_Snapshot(snapshot, _ctx);
    kk_string_t _x = _con_x998->gana_name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `tool-name` constructor field of the `:snapshot` type.

static inline kk_string_t kk_src_effects_prat__resonance_snapshot_fs_tool_name(kk_src_effects_prat__resonance__snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : snapshot) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x999 = kk_src_effects_prat__resonance__as_Snapshot(snapshot, _ctx);
    kk_string_t _x = _con_x999->tool_name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `operation` constructor field of the `:snapshot` type.

static inline kk_string_t kk_src_effects_prat__resonance_snapshot_fs_operation(kk_src_effects_prat__resonance__snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : snapshot) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1000 = kk_src_effects_prat__resonance__as_Snapshot(snapshot, _ctx);
    kk_string_t _x = _con_x1000->operation;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `output-preview` constructor field of the `:snapshot` type.

static inline kk_string_t kk_src_effects_prat__resonance_snapshot_fs_output_preview(kk_src_effects_prat__resonance__snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : snapshot) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1001 = kk_src_effects_prat__resonance__as_Snapshot(snapshot, _ctx);
    kk_string_t _x = _con_x1001->output_preview;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `timestamp` constructor field of the `:snapshot` type.

static inline double kk_src_effects_prat__resonance_snapshot_fs_timestamp(kk_src_effects_prat__resonance__snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : snapshot) -> float64 */ 
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1002 = kk_src_effects_prat__resonance__as_Snapshot(snapshot, _ctx);
    double _x = _con_x1002->timestamp;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `lunar-phase` constructor field of the `:snapshot` type.

static inline double kk_src_effects_prat__resonance_snapshot_fs_lunar_phase(kk_src_effects_prat__resonance__snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : snapshot) -> float64 */ 
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1003 = kk_src_effects_prat__resonance__as_Snapshot(snapshot, _ctx);
    double _x = _con_x1003->lunar_phase;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `lunar-mansion-num` constructor field of the `:snapshot` type.

static inline kk_integer_t kk_src_effects_prat__resonance_snapshot_fs_lunar_mansion_num(kk_src_effects_prat__resonance__snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : snapshot) -> int */ 
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1004 = kk_src_effects_prat__resonance__as_Snapshot(snapshot, _ctx);
    kk_integer_t _x = _con_x1004->lunar_mansion_num;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `harmony-score` constructor field of the `:snapshot` type.

static inline double kk_src_effects_prat__resonance_snapshot_fs_harmony_score(kk_src_effects_prat__resonance__snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : snapshot) -> float64 */ 
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1005 = kk_src_effects_prat__resonance__as_Snapshot(snapshot, _ctx);
    double _x = _con_x1005->harmony_score;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `guna-tag` constructor field of the `:snapshot` type.

static inline kk_string_t kk_src_effects_prat__resonance_snapshot_fs_guna_tag(kk_src_effects_prat__resonance__snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : snapshot) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1006 = kk_src_effects_prat__resonance__as_Snapshot(snapshot, _ctx);
    kk_string_t _x = _con_x1006->guna_tag;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `quadrant` constructor field of the `:snapshot` type.

static inline kk_string_t kk_src_effects_prat__resonance_snapshot_fs_quadrant(kk_src_effects_prat__resonance__snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : snapshot) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1007 = kk_src_effects_prat__resonance__as_Snapshot(snapshot, _ctx);
    kk_string_t _x = _con_x1007->quadrant;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `successor-hint` constructor field of the `:snapshot` type.

static inline kk_string_t kk_src_effects_prat__resonance_snapshot_fs_successor_hint(kk_src_effects_prat__resonance__snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : snapshot) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1008 = kk_src_effects_prat__resonance__as_Snapshot(snapshot, _ctx);
    kk_string_t _x = _con_x1008->successor_hint;
    return kk_string_dup(_x, _ctx);
  }
}

kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance_snapshot_fs__copy(kk_src_effects_prat__resonance__snapshot _this, kk_std_core_types__optional gana_name, kk_std_core_types__optional tool_name, kk_std_core_types__optional operation, kk_std_core_types__optional output_preview, kk_std_core_types__optional timestamp, kk_std_core_types__optional lunar_phase, kk_std_core_types__optional lunar_mansion_num, kk_std_core_types__optional harmony_score, kk_std_core_types__optional guna_tag, kk_std_core_types__optional quadrant, kk_std_core_types__optional successor_hint, kk_context_t* _ctx); /* (snapshot, gana-name : ? string, tool-name : ? string, operation : ? string, output-preview : ? string, timestamp : ? float64, lunar-phase : ? float64, lunar-mansion-num : ? int, harmony-score : ? float64, guna-tag : ? string, quadrant : ? string, successor-hint : ? string) -> snapshot */ 
 
// Automatically generated. Retrieves the `mansion-num` constructor field of the `:ganainfo` type.

static inline kk_integer_t kk_src_effects_prat__resonance_ganainfo_fs_mansion_num(kk_src_effects_prat__resonance__ganainfo ganainfo, kk_context_t* _ctx) { /* (ganainfo : ganainfo) -> int */ 
  {
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x1031 = kk_src_effects_prat__resonance__as_Ganainfo(ganainfo, _ctx);
    kk_integer_t _x = _con_x1031->mansion_num;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `quadrant` constructor field of the `:ganainfo` type.

static inline kk_string_t kk_src_effects_prat__resonance_ganainfo_fs_quadrant(kk_src_effects_prat__resonance__ganainfo ganainfo, kk_context_t* _ctx) { /* (ganainfo : ganainfo) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x1032 = kk_src_effects_prat__resonance__as_Ganainfo(ganainfo, _ctx);
    kk_string_t _x = _con_x1032->quadrant;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `meaning` constructor field of the `:ganainfo` type.

static inline kk_string_t kk_src_effects_prat__resonance_ganainfo_fs_meaning(kk_src_effects_prat__resonance__ganainfo ganainfo, kk_context_t* _ctx) { /* (ganainfo : ganainfo) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x1033 = kk_src_effects_prat__resonance__as_Ganainfo(ganainfo, _ctx);
    kk_string_t _x = _con_x1033->meaning;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `garden` constructor field of the `:ganainfo` type.

static inline kk_string_t kk_src_effects_prat__resonance_ganainfo_fs_garden(kk_src_effects_prat__resonance__ganainfo ganainfo, kk_context_t* _ctx) { /* (ganainfo : ganainfo) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x1034 = kk_src_effects_prat__resonance__as_Ganainfo(ganainfo, _ctx);
    kk_string_t _x = _con_x1034->garden;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `chinese` constructor field of the `:ganainfo` type.

static inline kk_string_t kk_src_effects_prat__resonance_ganainfo_fs_chinese(kk_src_effects_prat__resonance__ganainfo ganainfo, kk_context_t* _ctx) { /* (ganainfo : ganainfo) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x1035 = kk_src_effects_prat__resonance__as_Ganainfo(ganainfo, _ctx);
    kk_string_t _x = _con_x1035->chinese;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `pinyin` constructor field of the `:ganainfo` type.

static inline kk_string_t kk_src_effects_prat__resonance_ganainfo_fs_pinyin(kk_src_effects_prat__resonance__ganainfo ganainfo, kk_context_t* _ctx) { /* (ganainfo : ganainfo) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x1036 = kk_src_effects_prat__resonance__as_Ganainfo(ganainfo, _ctx);
    kk_string_t _x = _con_x1036->pinyin;
    return kk_string_dup(_x, _ctx);
  }
}

kk_src_effects_prat__resonance__ganainfo kk_src_effects_prat__resonance_ganainfo_fs__copy(kk_src_effects_prat__resonance__ganainfo _this, kk_std_core_types__optional mansion_num, kk_std_core_types__optional quadrant, kk_std_core_types__optional meaning, kk_std_core_types__optional garden, kk_std_core_types__optional chinese, kk_std_core_types__optional pinyin, kk_context_t* _ctx); /* (ganainfo, mansion-num : ? int, quadrant : ? string, meaning : ? string, garden : ? string, chinese : ? string, pinyin : ? string) -> ganainfo */ 

extern kk_std_core_types__list kk_src_effects_prat__resonance_gana_metadata;

extern kk_std_core_types__list kk_src_effects_prat__resonance_gana_order;

kk_src_effects_prat__resonance__ganainfo kk_src_effects_prat__resonance_get_gana_meta(kk_string_t gana_name, kk_context_t* _ctx); /* (gana-name : string) -> ganainfo */ 

kk_string_t kk_src_effects_prat__resonance_get_predecessor(kk_string_t gana_name, kk_context_t* _ctx); /* (gana-name : string) -> string */ 

kk_string_t kk_src_effects_prat__resonance_get_successor(kk_string_t gana_name, kk_context_t* _ctx); /* (gana-name : string) -> string */ 
 
// Automatically generated. Retrieves the `last-snapshot` constructor field of the `:resonance-state` type.

static inline kk_std_core_types__maybe kk_src_effects_prat__resonance_resonance_state_fs_last_snapshot(kk_src_effects_prat__resonance__resonance_state _this, kk_context_t* _ctx) { /* (resonance-state) -> maybe<snapshot> */ 
  {
    struct kk_src_effects_prat__resonance_Resonance_state* _con_x1694 = kk_src_effects_prat__resonance__as_Resonance_state(_this, _ctx);
    kk_std_core_types__maybe _x = _con_x1694->last_snapshot;
    return kk_std_core_types__maybe_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `history` constructor field of the `:resonance-state` type.

static inline kk_std_core_types__list kk_src_effects_prat__resonance_resonance_state_fs_history(kk_src_effects_prat__resonance__resonance_state _this, kk_context_t* _ctx) { /* (resonance-state) -> list<snapshot> */ 
  {
    struct kk_src_effects_prat__resonance_Resonance_state* _con_x1695 = kk_src_effects_prat__resonance__as_Resonance_state(_this, _ctx);
    kk_std_core_types__list _x = _con_x1695->history;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `gana-counts` constructor field of the `:resonance-state` type.

static inline kk_std_core_types__list kk_src_effects_prat__resonance_resonance_state_fs_gana_counts(kk_src_effects_prat__resonance__resonance_state _this, kk_context_t* _ctx) { /* (resonance-state) -> list<(string, int)> */ 
  {
    struct kk_src_effects_prat__resonance_Resonance_state* _con_x1696 = kk_src_effects_prat__resonance__as_Resonance_state(_this, _ctx);
    kk_std_core_types__list _x = _con_x1696->gana_counts;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `session-calls` constructor field of the `:resonance-state` type.

static inline kk_integer_t kk_src_effects_prat__resonance_resonance_state_fs_session_calls(kk_src_effects_prat__resonance__resonance_state _this, kk_context_t* _ctx) { /* (resonance-state) -> int */ 
  {
    struct kk_src_effects_prat__resonance_Resonance_state* _con_x1697 = kk_src_effects_prat__resonance__as_Resonance_state(_this, _ctx);
    kk_integer_t _x = _con_x1697->session_calls;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_effects_prat__resonance__resonance_state kk_src_effects_prat__resonance_resonance_state_fs__copy(kk_src_effects_prat__resonance__resonance_state _this, kk_std_core_types__optional last_snapshot, kk_std_core_types__optional history, kk_std_core_types__optional gana_counts, kk_std_core_types__optional session_calls, kk_context_t* _ctx); /* (resonance-state, last-snapshot : ? (maybe<snapshot>), history : ? (list<snapshot>), gana-counts : ? (list<(string, int)>), session-calls : ? int) -> resonance-state */ 

static inline kk_src_effects_prat__resonance__resonance_state kk_src_effects_prat__resonance_empty_state(kk_context_t* _ctx) { /* () -> resonance-state */ 
  return kk_src_effects_prat__resonance__new_Resonance_state(kk_reuse_null, 0, kk_std_core_types__new_Nothing(_ctx), kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), kk_integer_from_small(0), _ctx);
}

kk_src_effects_prat__resonance__resonance_state kk_src_effects_prat__resonance_record_in_state(kk_src_effects_prat__resonance__resonance_state st, kk_src_effects_prat__resonance__snapshot snap, kk_context_t* _ctx); /* (st : resonance-state, snap : snapshot) -> resonance-state */ 

static inline double kk_src_effects_prat__resonance_calculate_lunar_phase(kk_context_t* _ctx) { /* () -> float64 */ 
  return 0x1p-1;
}

static inline kk_integer_t kk_src_effects_prat__resonance_calculate_lunar_mansion(kk_context_t* _ctx) { /* () -> int */ 
  return kk_integer_from_small(14);
}

double kk_src_effects_prat__resonance_calculate_harmony_score(kk_std_core_types__list counts, kk_context_t* _ctx); /* (counts : list<(string, int)>) -> float64 */ 

static inline kk_string_t kk_src_effects_prat__resonance_calculate_guna_tag(double phase, kk_context_t* _ctx) { /* (phase : float64) -> string */ 
  kk_define_string_literal(, _s_x1754, 7, "rajasic", _ctx)
  return kk_string_dup(_s_x1754, _ctx);
}

kk_box_t kk_src_effects_prat__resonance_handle_resonance(kk_function_t action, kk_context_t* _ctx); /* forall<a> (action : () -> resonance a) -> a */ 
 
// Automatically generated. Retrieves the `predecessor` constructor field of the `:resonance-hints` type.

static inline kk_string_t kk_src_effects_prat__resonance_resonance_hints_fs_predecessor(kk_src_effects_prat__resonance__resonance_hints _this, kk_context_t* _ctx) { /* (resonance-hints) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1824 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
    kk_string_t _x = _con_x1824->predecessor;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `successor` constructor field of the `:resonance-hints` type.

static inline kk_string_t kk_src_effects_prat__resonance_resonance_hints_fs_successor(kk_src_effects_prat__resonance__resonance_hints _this, kk_context_t* _ctx) { /* (resonance-hints) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1825 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
    kk_string_t _x = _con_x1825->successor;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `lunar-phase` constructor field of the `:resonance-hints` type.

static inline double kk_src_effects_prat__resonance_resonance_hints_fs_lunar_phase(kk_src_effects_prat__resonance__resonance_hints _this, kk_context_t* _ctx) { /* (resonance-hints) -> float64 */ 
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1826 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
    double _x = _con_x1826->lunar_phase;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `lunar-mansion-num` constructor field of the `:resonance-hints` type.

static inline kk_integer_t kk_src_effects_prat__resonance_resonance_hints_fs_lunar_mansion_num(kk_src_effects_prat__resonance__resonance_hints _this, kk_context_t* _ctx) { /* (resonance-hints) -> int */ 
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1827 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
    kk_integer_t _x = _con_x1827->lunar_mansion_num;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `harmony-score` constructor field of the `:resonance-hints` type.

static inline double kk_src_effects_prat__resonance_resonance_hints_fs_harmony_score(kk_src_effects_prat__resonance__resonance_hints _this, kk_context_t* _ctx) { /* (resonance-hints) -> float64 */ 
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1828 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
    double _x = _con_x1828->harmony_score;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `guna-tag` constructor field of the `:resonance-hints` type.

static inline kk_string_t kk_src_effects_prat__resonance_resonance_hints_fs_guna_tag(kk_src_effects_prat__resonance__resonance_hints _this, kk_context_t* _ctx) { /* (resonance-hints) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1829 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
    kk_string_t _x = _con_x1829->guna_tag;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `quadrant` constructor field of the `:resonance-hints` type.

static inline kk_string_t kk_src_effects_prat__resonance_resonance_hints_fs_quadrant(kk_src_effects_prat__resonance__resonance_hints _this, kk_context_t* _ctx) { /* (resonance-hints) -> string */ 
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1830 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
    kk_string_t _x = _con_x1830->quadrant;
    return kk_string_dup(_x, _ctx);
  }
}

kk_string_t kk_src_effects_prat__resonance_snapshot_to_json(kk_src_effects_prat__resonance__snapshot s, kk_context_t* _ctx); /* (s : snapshot) -> string */ 

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance_resonance_hints_fs__copy(kk_src_effects_prat__resonance__resonance_hints _this, kk_std_core_types__optional predecessor, kk_std_core_types__optional successor, kk_std_core_types__optional lunar_phase, kk_std_core_types__optional lunar_mansion_num, kk_std_core_types__optional harmony_score, kk_std_core_types__optional guna_tag, kk_std_core_types__optional quadrant, kk_context_t* _ctx); /* (resonance-hints, predecessor : ? string, successor : ? string, lunar-phase : ? float64, lunar-mansion-num : ? int, harmony-score : ? float64, guna-tag : ? string, quadrant : ? string) -> resonance-hints */ 

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__mlift_generate_hints_10115(double _y_x10089, kk_integer_t _y_x10090, double _y_x10091, kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, kk_string_t _y_x10092, kk_context_t* _ctx); /* (float64, int, float64, meta@0 : ganainfo, pred : string, succ : string, string) -> resonance resonance-hints */ 

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__mlift_generate_hints_10116(double _y_x10089, kk_integer_t _y_x10090, kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, double _y_x10091, kk_context_t* _ctx); /* (float64, int, meta@0 : ganainfo, pred : string, succ : string, float64) -> resonance resonance-hints */ 

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__mlift_generate_hints_10117(double _y_x10089, kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, kk_integer_t _y_x10090, kk_context_t* _ctx); /* (float64, meta@0 : ganainfo, pred : string, succ : string, int) -> resonance resonance-hints */ 

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__mlift_generate_hints_10118(kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, double _y_x10089, kk_context_t* _ctx); /* (meta@0 : ganainfo, pred : string, succ : string, float64) -> resonance resonance-hints */ 

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance_generate_hints(kk_string_t gana_name, kk_context_t* _ctx); /* (gana-name : string) -> resonance resonance-hints */ 

kk_string_t kk_src_effects_prat__resonance_hints_to_json(kk_src_effects_prat__resonance__resonance_hints h, kk_context_t* _ctx); /* (h : resonance-hints) -> string */ 
 
// monadic lift

static inline kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance__mlift_track_prat_invocation_10119(kk_src_effects_prat__resonance__snapshot snap, kk_unit_t wild__, kk_context_t* _ctx) { /* (snap : snapshot, wild_ : ()) -> resonance snapshot */ 
  return snap;
}

kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120(kk_string_t gana_name, kk_string_t operation, kk_string_t output, kk_string_t tool_name, kk_src_effects_prat__resonance__resonance_hints hints, kk_context_t* _ctx); /* (gana-name : string, operation : string, output : string, tool-name : string, hints : resonance-hints) -> resonance snapshot */ 

kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance_track_prat_invocation(kk_string_t gana_name, kk_string_t tool_name, kk_string_t operation, kk_string_t output, kk_context_t* _ctx); /* (gana-name : string, tool-name : string, operation : string, output : string) -> resonance snapshot */ 

void kk_src_effects_prat__resonance__init(kk_context_t* _ctx);


void kk_src_effects_prat__resonance__done(kk_context_t* _ctx);

#endif // header
