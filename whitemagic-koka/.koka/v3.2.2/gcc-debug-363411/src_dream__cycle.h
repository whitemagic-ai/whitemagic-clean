#pragma once
#ifndef kk_src_dream__cycle_H
#define kk_src_dream__cycle_H
// Koka generated module: src/dream_cycle, koka version: 3.2.2, platform: 64-bit
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

// type src/dream_cycle/consolidation-result
struct kk_src_dream__cycle__consolidation_result_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__consolidation_result;
struct kk_src_dream__cycle_Consolidation_result {
  struct kk_src_dream__cycle__consolidation_result_s _base;
  kk_integer_t constellations;
  kk_integer_t memberships;
};
static inline kk_src_dream__cycle__consolidation_result kk_src_dream__cycle__base_Consolidation_result(struct kk_src_dream__cycle_Consolidation_result* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__consolidation_result kk_src_dream__cycle__new_Consolidation_result(kk_reuse_t _at, int32_t _cpath, kk_integer_t constellations, kk_integer_t memberships, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_Consolidation_result* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle_Consolidation_result, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->constellations = constellations;
  _con->memberships = memberships;
  return kk_src_dream__cycle__base_Consolidation_result(_con, _ctx);
}
static inline struct kk_src_dream__cycle_Consolidation_result* kk_src_dream__cycle__as_Consolidation_result(kk_src_dream__cycle__consolidation_result x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle_Consolidation_result*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Consolidation_result(kk_src_dream__cycle__consolidation_result x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__consolidation_result kk_src_dream__cycle__consolidation_result_dup(kk_src_dream__cycle__consolidation_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__consolidation_result_drop(kk_src_dream__cycle__consolidation_result _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__consolidation_result_box(kk_src_dream__cycle__consolidation_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__consolidation_result kk_src_dream__cycle__consolidation_result_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/constellation-ops
struct kk_src_dream__cycle__constellation_ops_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__constellation_ops;
struct kk_src_dream__cycle__Hnd_constellation_ops {
  struct kk_src_dream__cycle__constellation_ops_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause2 _fun_add_to_constellation;
  kk_std_core_hnd__clause1 _fun_detect_constellations;
  kk_std_core_hnd__clause2 _fun_merge_constellations;
};
static inline kk_src_dream__cycle__constellation_ops kk_src_dream__cycle__base_Hnd_constellation_ops(struct kk_src_dream__cycle__Hnd_constellation_ops* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__constellation_ops kk_src_dream__cycle__new_Hnd_constellation_ops(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause2 _fun_add_to_constellation, kk_std_core_hnd__clause1 _fun_detect_constellations, kk_std_core_hnd__clause2 _fun_merge_constellations, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__Hnd_constellation_ops* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle__Hnd_constellation_ops, _at, 4 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_add_to_constellation = _fun_add_to_constellation;
  _con->_fun_detect_constellations = _fun_detect_constellations;
  _con->_fun_merge_constellations = _fun_merge_constellations;
  return kk_src_dream__cycle__base_Hnd_constellation_ops(_con, _ctx);
}
static inline struct kk_src_dream__cycle__Hnd_constellation_ops* kk_src_dream__cycle__as_Hnd_constellation_ops(kk_src_dream__cycle__constellation_ops x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle__Hnd_constellation_ops*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Hnd_constellation_ops(kk_src_dream__cycle__constellation_ops x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__constellation_ops kk_src_dream__cycle__constellation_ops_dup(kk_src_dream__cycle__constellation_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__constellation_ops_drop(kk_src_dream__cycle__constellation_ops _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__constellation_ops_box(kk_src_dream__cycle__constellation_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__constellation_ops kk_src_dream__cycle__constellation_ops_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/decay-ops
struct kk_src_dream__cycle__decay_ops_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__decay_ops;
struct kk_src_dream__cycle__Hnd_decay_ops {
  struct kk_src_dream__cycle__decay_ops_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _fun_archive_memory;
  kk_std_core_hnd__clause1 _fun_get_decay_candidates;
  kk_std_core_hnd__clause2 _fun_sweep_old_memories;
};
static inline kk_src_dream__cycle__decay_ops kk_src_dream__cycle__base_Hnd_decay_ops(struct kk_src_dream__cycle__Hnd_decay_ops* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__decay_ops kk_src_dream__cycle__new_Hnd_decay_ops(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _fun_archive_memory, kk_std_core_hnd__clause1 _fun_get_decay_candidates, kk_std_core_hnd__clause2 _fun_sweep_old_memories, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__Hnd_decay_ops* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle__Hnd_decay_ops, _at, 4 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_archive_memory = _fun_archive_memory;
  _con->_fun_get_decay_candidates = _fun_get_decay_candidates;
  _con->_fun_sweep_old_memories = _fun_sweep_old_memories;
  return kk_src_dream__cycle__base_Hnd_decay_ops(_con, _ctx);
}
static inline struct kk_src_dream__cycle__Hnd_decay_ops* kk_src_dream__cycle__as_Hnd_decay_ops(kk_src_dream__cycle__decay_ops x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle__Hnd_decay_ops*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Hnd_decay_ops(kk_src_dream__cycle__decay_ops x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__decay_ops kk_src_dream__cycle__decay_ops_dup(kk_src_dream__cycle__decay_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__decay_ops_drop(kk_src_dream__cycle__decay_ops _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__decay_ops_box(kk_src_dream__cycle__decay_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__decay_ops kk_src_dream__cycle__decay_ops_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value type src/dream_cycle/decay-result
struct kk_src_dream__cycle_Decay_result {
  kk_integer_t swept;
};
typedef struct kk_src_dream__cycle_Decay_result kk_src_dream__cycle__decay_result;
static inline kk_src_dream__cycle__decay_result kk_src_dream__cycle__new_Decay_result(kk_integer_t swept, kk_context_t* _ctx) {
  kk_src_dream__cycle__decay_result _con = { swept };
  return _con;
}
static inline bool kk_src_dream__cycle__is_Decay_result(kk_src_dream__cycle__decay_result x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__decay_result kk_src_dream__cycle__decay_result_dup(kk_src_dream__cycle__decay_result _x, kk_context_t* _ctx) {
  kk_integer_dup(_x.swept, _ctx);
  return _x;
}
static inline void kk_src_dream__cycle__decay_result_drop(kk_src_dream__cycle__decay_result _x, kk_context_t* _ctx) {
  kk_integer_drop(_x.swept, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__decay_result_box(kk_src_dream__cycle__decay_result _x, kk_context_t* _ctx) {
  return kk_integer_box(_x.swept, _ctx);
}
static inline kk_src_dream__cycle__decay_result kk_src_dream__cycle__decay_result_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_src_dream__cycle__new_Decay_result(kk_integer_unbox(_x, _ctx), _ctx);
}

// type src/dream_cycle/governance-result
struct kk_src_dream__cycle__governance_result_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__governance_result;
struct kk_src_dream__cycle_Governance_result {
  struct kk_src_dream__cycle__governance_result_s _base;
  kk_integer_t communities;
  kk_integer_t echo_chambers;
  double health;
};
static inline kk_src_dream__cycle__governance_result kk_src_dream__cycle__base_Governance_result(struct kk_src_dream__cycle_Governance_result* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__governance_result kk_src_dream__cycle__new_Governance_result(kk_reuse_t _at, int32_t _cpath, kk_integer_t communities, kk_integer_t echo_chambers, double health, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_Governance_result* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle_Governance_result, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->communities = communities;
  _con->echo_chambers = echo_chambers;
  _con->health = health;
  return kk_src_dream__cycle__base_Governance_result(_con, _ctx);
}
static inline struct kk_src_dream__cycle_Governance_result* kk_src_dream__cycle__as_Governance_result(kk_src_dream__cycle__governance_result x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle_Governance_result*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Governance_result(kk_src_dream__cycle__governance_result x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__governance_result kk_src_dream__cycle__governance_result_dup(kk_src_dream__cycle__governance_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__governance_result_drop(kk_src_dream__cycle__governance_result _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__governance_result_box(kk_src_dream__cycle__governance_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__governance_result kk_src_dream__cycle__governance_result_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/kaizen-result
struct kk_src_dream__cycle__kaizen_result_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__kaizen_result;
struct kk_src_dream__cycle_Kaizen_result {
  struct kk_src_dream__cycle__kaizen_result_s _base;
  kk_integer_t emergence_insights;
  kk_integer_t persisted;
};
static inline kk_src_dream__cycle__kaizen_result kk_src_dream__cycle__base_Kaizen_result(struct kk_src_dream__cycle_Kaizen_result* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__kaizen_result kk_src_dream__cycle__new_Kaizen_result(kk_reuse_t _at, int32_t _cpath, kk_integer_t emergence_insights, kk_integer_t persisted, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_Kaizen_result* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle_Kaizen_result, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->emergence_insights = emergence_insights;
  _con->persisted = persisted;
  return kk_src_dream__cycle__base_Kaizen_result(_con, _ctx);
}
static inline struct kk_src_dream__cycle_Kaizen_result* kk_src_dream__cycle__as_Kaizen_result(kk_src_dream__cycle__kaizen_result x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle_Kaizen_result*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Kaizen_result(kk_src_dream__cycle__kaizen_result x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__kaizen_result kk_src_dream__cycle__kaizen_result_dup(kk_src_dream__cycle__kaizen_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__kaizen_result_drop(kk_src_dream__cycle__kaizen_result _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__kaizen_result_box(kk_src_dream__cycle__kaizen_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__kaizen_result kk_src_dream__cycle__kaizen_result_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/narrative-result
struct kk_src_dream__cycle__narrative_result_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__narrative_result;
struct kk_src_dream__cycle_Narrative_result {
  struct kk_src_dream__cycle__narrative_result_s _base;
  kk_integer_t clusters;
  kk_integer_t narratives;
  kk_integer_t compressed;
};
static inline kk_src_dream__cycle__narrative_result kk_src_dream__cycle__base_Narrative_result(struct kk_src_dream__cycle_Narrative_result* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__narrative_result kk_src_dream__cycle__new_Narrative_result(kk_reuse_t _at, int32_t _cpath, kk_integer_t clusters, kk_integer_t narratives, kk_integer_t compressed, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_Narrative_result* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle_Narrative_result, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->clusters = clusters;
  _con->narratives = narratives;
  _con->compressed = compressed;
  return kk_src_dream__cycle__base_Narrative_result(_con, _ctx);
}
static inline struct kk_src_dream__cycle_Narrative_result* kk_src_dream__cycle__as_Narrative_result(kk_src_dream__cycle__narrative_result x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle_Narrative_result*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Narrative_result(kk_src_dream__cycle__narrative_result x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__narrative_result kk_src_dream__cycle__narrative_result_dup(kk_src_dream__cycle__narrative_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__narrative_result_drop(kk_src_dream__cycle__narrative_result _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__narrative_result_box(kk_src_dream__cycle__narrative_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__narrative_result kk_src_dream__cycle__narrative_result_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value type src/dream_cycle/oracle-result
struct kk_src_dream__cycle_Oracle_result {
  kk_std_core_types__list suggestions;
};
typedef struct kk_src_dream__cycle_Oracle_result kk_src_dream__cycle__oracle_result;
static inline kk_src_dream__cycle__oracle_result kk_src_dream__cycle__new_Oracle_result(kk_std_core_types__list suggestions, kk_context_t* _ctx) {
  kk_src_dream__cycle__oracle_result _con = { suggestions };
  return _con;
}
static inline bool kk_src_dream__cycle__is_Oracle_result(kk_src_dream__cycle__oracle_result x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__oracle_result kk_src_dream__cycle__oracle_result_dup(kk_src_dream__cycle__oracle_result _x, kk_context_t* _ctx) {
  kk_std_core_types__list_dup(_x.suggestions, _ctx);
  return _x;
}
static inline void kk_src_dream__cycle__oracle_result_drop(kk_src_dream__cycle__oracle_result _x, kk_context_t* _ctx) {
  kk_std_core_types__list_drop(_x.suggestions, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__oracle_result_box(kk_src_dream__cycle__oracle_result _x, kk_context_t* _ctx) {
  return kk_std_core_types__list_box(_x.suggestions, _ctx);
}
static inline kk_src_dream__cycle__oracle_result kk_src_dream__cycle__oracle_result_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_src_dream__cycle__new_Oracle_result(kk_std_core_types__list_unbox(_x, _borrow, _ctx), _ctx);
}

// type src/dream_cycle/serendipity-result
struct kk_src_dream__cycle__serendipity_result_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__serendipity_result;
struct kk_src_dream__cycle_Serendipity_result {
  struct kk_src_dream__cycle__serendipity_result_s _base;
  kk_integer_t bridges;
  kk_integer_t insights;
  kk_integer_t connections;
};
static inline kk_src_dream__cycle__serendipity_result kk_src_dream__cycle__base_Serendipity_result(struct kk_src_dream__cycle_Serendipity_result* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__serendipity_result kk_src_dream__cycle__new_Serendipity_result(kk_reuse_t _at, int32_t _cpath, kk_integer_t bridges, kk_integer_t insights, kk_integer_t connections, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_Serendipity_result* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle_Serendipity_result, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->bridges = bridges;
  _con->insights = insights;
  _con->connections = connections;
  return kk_src_dream__cycle__base_Serendipity_result(_con, _ctx);
}
static inline struct kk_src_dream__cycle_Serendipity_result* kk_src_dream__cycle__as_Serendipity_result(kk_src_dream__cycle__serendipity_result x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle_Serendipity_result*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Serendipity_result(kk_src_dream__cycle__serendipity_result x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__serendipity_result kk_src_dream__cycle__serendipity_result_dup(kk_src_dream__cycle__serendipity_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__serendipity_result_drop(kk_src_dream__cycle__serendipity_result _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__serendipity_result_box(kk_src_dream__cycle__serendipity_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__serendipity_result kk_src_dream__cycle__serendipity_result_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/triage-result
struct kk_src_dream__cycle__triage_result_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__triage_result;
struct kk_src_dream__cycle_Triage_result {
  struct kk_src_dream__cycle__triage_result_s _base;
  kk_integer_t tagged;
  kk_integer_t drift_corrected;
};
static inline kk_src_dream__cycle__triage_result kk_src_dream__cycle__base_Triage_result(struct kk_src_dream__cycle_Triage_result* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__triage_result kk_src_dream__cycle__new_Triage_result(kk_reuse_t _at, int32_t _cpath, kk_integer_t tagged, kk_integer_t drift_corrected, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_Triage_result* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle_Triage_result, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->tagged = tagged;
  _con->drift_corrected = drift_corrected;
  return kk_src_dream__cycle__base_Triage_result(_con, _ctx);
}
static inline struct kk_src_dream__cycle_Triage_result* kk_src_dream__cycle__as_Triage_result(kk_src_dream__cycle__triage_result x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle_Triage_result*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Triage_result(kk_src_dream__cycle__triage_result x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__triage_result kk_src_dream__cycle__triage_result_dup(kk_src_dream__cycle__triage_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__triage_result_drop(kk_src_dream__cycle__triage_result _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__triage_result_box(kk_src_dream__cycle__triage_result _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__triage_result kk_src_dream__cycle__triage_result_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/dream-summary
struct kk_src_dream__cycle__dream_summary_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__dream_summary;
struct kk_src_dream__cycle_Dream_summary {
  struct kk_src_dream__cycle__dream_summary_s _base;
  kk_src_dream__cycle__triage_result triage;
  kk_src_dream__cycle__consolidation_result consolidation;
  kk_src_dream__cycle__serendipity_result serendipity;
  kk_src_dream__cycle__governance_result governance;
  kk_src_dream__cycle__narrative_result narrative;
  kk_src_dream__cycle__kaizen_result kaizen;
  kk_src_dream__cycle__oracle_result oracle;
  kk_src_dream__cycle__decay_result decay;
  kk_integer_t duration_ms;
};
static inline kk_src_dream__cycle__dream_summary kk_src_dream__cycle__base_Dream_summary(struct kk_src_dream__cycle_Dream_summary* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__dream_summary kk_src_dream__cycle__new_Dream_summary(kk_reuse_t _at, int32_t _cpath, kk_src_dream__cycle__triage_result triage, kk_src_dream__cycle__consolidation_result consolidation, kk_src_dream__cycle__serendipity_result serendipity, kk_src_dream__cycle__governance_result governance, kk_src_dream__cycle__narrative_result narrative, kk_src_dream__cycle__kaizen_result kaizen, kk_src_dream__cycle__oracle_result oracle, kk_src_dream__cycle__decay_result decay, kk_integer_t duration_ms, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_Dream_summary* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle_Dream_summary, _at, 9 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->triage = triage;
  _con->consolidation = consolidation;
  _con->serendipity = serendipity;
  _con->governance = governance;
  _con->narrative = narrative;
  _con->kaizen = kaizen;
  _con->oracle = oracle;
  _con->decay = decay;
  _con->duration_ms = duration_ms;
  return kk_src_dream__cycle__base_Dream_summary(_con, _ctx);
}
static inline struct kk_src_dream__cycle_Dream_summary* kk_src_dream__cycle__as_Dream_summary(kk_src_dream__cycle__dream_summary x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle_Dream_summary*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Dream_summary(kk_src_dream__cycle__dream_summary x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__dream_summary kk_src_dream__cycle__dream_summary_dup(kk_src_dream__cycle__dream_summary _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__dream_summary_drop(kk_src_dream__cycle__dream_summary _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__dream_summary_box(kk_src_dream__cycle__dream_summary _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__dream_summary kk_src_dream__cycle__dream_summary_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/governance-ops
struct kk_src_dream__cycle__governance_ops_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__governance_ops;
struct kk_src_dream__cycle__Hnd_governance_ops {
  struct kk_src_dream__cycle__governance_ops_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _fun_check_echo_chambers;
  kk_std_core_hnd__clause0 _fun_get_community_health;
  kk_std_core_hnd__clause1 _fun_rebalance_community;
};
static inline kk_src_dream__cycle__governance_ops kk_src_dream__cycle__base_Hnd_governance_ops(struct kk_src_dream__cycle__Hnd_governance_ops* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__governance_ops kk_src_dream__cycle__new_Hnd_governance_ops(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _fun_check_echo_chambers, kk_std_core_hnd__clause0 _fun_get_community_health, kk_std_core_hnd__clause1 _fun_rebalance_community, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__Hnd_governance_ops* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle__Hnd_governance_ops, _at, 4 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_check_echo_chambers = _fun_check_echo_chambers;
  _con->_fun_get_community_health = _fun_get_community_health;
  _con->_fun_rebalance_community = _fun_rebalance_community;
  return kk_src_dream__cycle__base_Hnd_governance_ops(_con, _ctx);
}
static inline struct kk_src_dream__cycle__Hnd_governance_ops* kk_src_dream__cycle__as_Hnd_governance_ops(kk_src_dream__cycle__governance_ops x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle__Hnd_governance_ops*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Hnd_governance_ops(kk_src_dream__cycle__governance_ops x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__governance_ops kk_src_dream__cycle__governance_ops_dup(kk_src_dream__cycle__governance_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__governance_ops_drop(kk_src_dream__cycle__governance_ops _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__governance_ops_box(kk_src_dream__cycle__governance_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__governance_ops kk_src_dream__cycle__governance_ops_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/insight-ops
struct kk_src_dream__cycle__insight_ops_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__insight_ops;
struct kk_src_dream__cycle__Hnd_insight_ops {
  struct kk_src_dream__cycle__insight_ops_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _fun_create_bridge;
  kk_std_core_hnd__clause2 _fun_emit_insight;
  kk_std_core_hnd__clause1 _fun_get_serendipity_candidates;
};
static inline kk_src_dream__cycle__insight_ops kk_src_dream__cycle__base_Hnd_insight_ops(struct kk_src_dream__cycle__Hnd_insight_ops* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__insight_ops kk_src_dream__cycle__new_Hnd_insight_ops(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _fun_create_bridge, kk_std_core_hnd__clause2 _fun_emit_insight, kk_std_core_hnd__clause1 _fun_get_serendipity_candidates, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__Hnd_insight_ops* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle__Hnd_insight_ops, _at, 4 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_create_bridge = _fun_create_bridge;
  _con->_fun_emit_insight = _fun_emit_insight;
  _con->_fun_get_serendipity_candidates = _fun_get_serendipity_candidates;
  return kk_src_dream__cycle__base_Hnd_insight_ops(_con, _ctx);
}
static inline struct kk_src_dream__cycle__Hnd_insight_ops* kk_src_dream__cycle__as_Hnd_insight_ops(kk_src_dream__cycle__insight_ops x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle__Hnd_insight_ops*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Hnd_insight_ops(kk_src_dream__cycle__insight_ops x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__insight_ops kk_src_dream__cycle__insight_ops_dup(kk_src_dream__cycle__insight_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__insight_ops_drop(kk_src_dream__cycle__insight_ops _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__insight_ops_box(kk_src_dream__cycle__insight_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__insight_ops kk_src_dream__cycle__insight_ops_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/kaizen-ops
struct kk_src_dream__cycle__kaizen_ops_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__kaizen_ops;
struct kk_src_dream__cycle__Hnd_kaizen_ops {
  struct kk_src_dream__cycle__kaizen_ops_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause0 _fun_get_improvement_candidates;
  kk_std_core_hnd__clause2 _fun_persist_insight;
  kk_std_core_hnd__clause1 _fun_scan_emergence;
};
static inline kk_src_dream__cycle__kaizen_ops kk_src_dream__cycle__base_Hnd_kaizen_ops(struct kk_src_dream__cycle__Hnd_kaizen_ops* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__kaizen_ops kk_src_dream__cycle__new_Hnd_kaizen_ops(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause0 _fun_get_improvement_candidates, kk_std_core_hnd__clause2 _fun_persist_insight, kk_std_core_hnd__clause1 _fun_scan_emergence, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__Hnd_kaizen_ops* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle__Hnd_kaizen_ops, _at, 4 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_get_improvement_candidates = _fun_get_improvement_candidates;
  _con->_fun_persist_insight = _fun_persist_insight;
  _con->_fun_scan_emergence = _fun_scan_emergence;
  return kk_src_dream__cycle__base_Hnd_kaizen_ops(_con, _ctx);
}
static inline struct kk_src_dream__cycle__Hnd_kaizen_ops* kk_src_dream__cycle__as_Hnd_kaizen_ops(kk_src_dream__cycle__kaizen_ops x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle__Hnd_kaizen_ops*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Hnd_kaizen_ops(kk_src_dream__cycle__kaizen_ops x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__kaizen_ops kk_src_dream__cycle__kaizen_ops_dup(kk_src_dream__cycle__kaizen_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__kaizen_ops_drop(kk_src_dream__cycle__kaizen_ops _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__kaizen_ops_box(kk_src_dream__cycle__kaizen_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__kaizen_ops kk_src_dream__cycle__kaizen_ops_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/memory-ops
struct kk_src_dream__cycle__memory_ops_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__memory_ops;
struct kk_src_dream__cycle__Hnd_memory_ops {
  struct kk_src_dream__cycle__memory_ops_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause2 _fun_decay_memory;
  kk_std_core_hnd__clause2 _fun_recall_memories;
  kk_std_core_hnd__clause2 _fun_store_memory;
  kk_std_core_hnd__clause2 _fun_tag_memory;
};
static inline kk_src_dream__cycle__memory_ops kk_src_dream__cycle__base_Hnd_memory_ops(struct kk_src_dream__cycle__Hnd_memory_ops* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__memory_ops kk_src_dream__cycle__new_Hnd_memory_ops(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause2 _fun_decay_memory, kk_std_core_hnd__clause2 _fun_recall_memories, kk_std_core_hnd__clause2 _fun_store_memory, kk_std_core_hnd__clause2 _fun_tag_memory, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__Hnd_memory_ops* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle__Hnd_memory_ops, _at, 5 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_decay_memory = _fun_decay_memory;
  _con->_fun_recall_memories = _fun_recall_memories;
  _con->_fun_store_memory = _fun_store_memory;
  _con->_fun_tag_memory = _fun_tag_memory;
  return kk_src_dream__cycle__base_Hnd_memory_ops(_con, _ctx);
}
static inline struct kk_src_dream__cycle__Hnd_memory_ops* kk_src_dream__cycle__as_Hnd_memory_ops(kk_src_dream__cycle__memory_ops x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle__Hnd_memory_ops*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Hnd_memory_ops(kk_src_dream__cycle__memory_ops x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__memory_ops kk_src_dream__cycle__memory_ops_dup(kk_src_dream__cycle__memory_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__memory_ops_drop(kk_src_dream__cycle__memory_ops _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__memory_ops_box(kk_src_dream__cycle__memory_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__memory_ops kk_src_dream__cycle__memory_ops_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/narrative-ops
struct kk_src_dream__cycle__narrative_ops_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__narrative_ops;
struct kk_src_dream__cycle__Hnd_narrative_ops {
  struct kk_src_dream__cycle__narrative_ops_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _fun_cluster_narratives;
  kk_std_core_hnd__clause1 _fun_compress_narrative;
  kk_std_core_hnd__clause1 _fun_get_narrative_threads;
};
static inline kk_src_dream__cycle__narrative_ops kk_src_dream__cycle__base_Hnd_narrative_ops(struct kk_src_dream__cycle__Hnd_narrative_ops* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__narrative_ops kk_src_dream__cycle__new_Hnd_narrative_ops(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _fun_cluster_narratives, kk_std_core_hnd__clause1 _fun_compress_narrative, kk_std_core_hnd__clause1 _fun_get_narrative_threads, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__Hnd_narrative_ops* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle__Hnd_narrative_ops, _at, 4 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_cluster_narratives = _fun_cluster_narratives;
  _con->_fun_compress_narrative = _fun_compress_narrative;
  _con->_fun_get_narrative_threads = _fun_get_narrative_threads;
  return kk_src_dream__cycle__base_Hnd_narrative_ops(_con, _ctx);
}
static inline struct kk_src_dream__cycle__Hnd_narrative_ops* kk_src_dream__cycle__as_Hnd_narrative_ops(kk_src_dream__cycle__narrative_ops x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle__Hnd_narrative_ops*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Hnd_narrative_ops(kk_src_dream__cycle__narrative_ops x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__narrative_ops kk_src_dream__cycle__narrative_ops_dup(kk_src_dream__cycle__narrative_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__narrative_ops_drop(kk_src_dream__cycle__narrative_ops _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__narrative_ops_box(kk_src_dream__cycle__narrative_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__narrative_ops kk_src_dream__cycle__narrative_ops_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/dream_cycle/oracle-ops
struct kk_src_dream__cycle__oracle_ops_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_dream__cycle__oracle_ops;
struct kk_src_dream__cycle__Hnd_oracle_ops {
  struct kk_src_dream__cycle__oracle_ops_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _fun_generate_suggestion;
  kk_std_core_hnd__clause1 _fun_predict_next_session;
};
static inline kk_src_dream__cycle__oracle_ops kk_src_dream__cycle__base_Hnd_oracle_ops(struct kk_src_dream__cycle__Hnd_oracle_ops* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_dream__cycle__oracle_ops kk_src_dream__cycle__new_Hnd_oracle_ops(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _fun_generate_suggestion, kk_std_core_hnd__clause1 _fun_predict_next_session, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__Hnd_oracle_ops* _con = kk_block_alloc_at_as(struct kk_src_dream__cycle__Hnd_oracle_ops, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_generate_suggestion = _fun_generate_suggestion;
  _con->_fun_predict_next_session = _fun_predict_next_session;
  return kk_src_dream__cycle__base_Hnd_oracle_ops(_con, _ctx);
}
static inline struct kk_src_dream__cycle__Hnd_oracle_ops* kk_src_dream__cycle__as_Hnd_oracle_ops(kk_src_dream__cycle__oracle_ops x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_dream__cycle__Hnd_oracle_ops*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_dream__cycle__is_Hnd_oracle_ops(kk_src_dream__cycle__oracle_ops x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_dream__cycle__oracle_ops kk_src_dream__cycle__oracle_ops_dup(kk_src_dream__cycle__oracle_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_dream__cycle__oracle_ops_drop(kk_src_dream__cycle__oracle_ops _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_dream__cycle__oracle_ops_box(kk_src_dream__cycle__oracle_ops _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_dream__cycle__oracle_ops kk_src_dream__cycle__oracle_ops_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:memory-ops` type.

static inline kk_integer_t kk_src_dream__cycle_memory_ops_fs__cfc(kk_src_dream__cycle__memory_ops _this, kk_context_t* _ctx) { /* forall<e,a> (memory-ops<e,a>) -> int */ 
  {
    struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1188 = kk_src_dream__cycle__as_Hnd_memory_ops(_this, _ctx);
    kk_integer_t _x = _con_x1188->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_src_dream__cycle_memory_ops_fs__tag;

kk_box_t kk_src_dream__cycle_memory_ops_fs__handle(kk_src_dream__cycle__memory_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : memory-ops<e,b>, ret : (res : a) -> e b, action : () -> <memory-ops|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-store-memory` constructor field of the `:memory-ops` type.

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_memory_ops_fs__fun_store_memory(kk_src_dream__cycle__memory_ops _this, kk_context_t* _ctx) { /* forall<e,a> (memory-ops<e,a>) -> hnd/clause2<string,float64,string,memory-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1192 = kk_src_dream__cycle__as_Hnd_memory_ops(_this, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x1192->_fun_store_memory;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `store-memory` operation out of effect `:memory-ops`

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_store_memory_fs__select(kk_src_dream__cycle__memory_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : memory-ops<e,a>) -> hnd/clause2<string,float64,string,memory-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1193 = kk_src_dream__cycle__as_Hnd_memory_ops(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_store_memory = _con_x1193->_fun_store_memory;
    return kk_std_core_hnd__clause2_dup(_fun_store_memory, _ctx);
  }
}
 
// Call the `fun store-memory` operation of the effect `:memory-ops`

static inline kk_string_t kk_src_dream__cycle_store_memory(kk_string_t content, double importance, kk_context_t* _ctx) { /* (content : string, importance : float64) -> memory-ops string */ 
  kk_std_core_hnd__ev evx_10199 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/memory-ops>*/;
  kk_box_t _x_x1194;
  {
    struct kk_std_core_hnd_Ev* _con_x1195 = kk_std_core_hnd__as_Ev(evx_10199, _ctx);
    kk_box_t _box_x8 = _con_x1195->hnd;
    int32_t m = _con_x1195->marker;
    kk_src_dream__cycle__memory_ops h = kk_src_dream__cycle__memory_ops_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_src_dream__cycle__memory_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1196 = kk_src_dream__cycle__as_Hnd_memory_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1196->_cfc;
      kk_std_core_hnd__clause2 _pat_1_0 = _con_x1196->_fun_decay_memory;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1196->_fun_recall_memories;
      kk_std_core_hnd__clause2 _fun_store_memory = _con_x1196->_fun_store_memory;
      kk_std_core_hnd__clause2 _pat_3 = _con_x1196->_fun_tag_memory;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_store_memory, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x13 = _fun_store_memory.clause;
        _x_x1194 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x13, (_fun_unbox_x13, m, evx_10199, kk_string_box(content), kk_double_box(importance, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_string_unbox(_x_x1194);
}
 
// Automatically generated. Retrieves the `@fun-recall-memories` constructor field of the `:memory-ops` type.

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_memory_ops_fs__fun_recall_memories(kk_src_dream__cycle__memory_ops _this, kk_context_t* _ctx) { /* forall<e,a> (memory-ops<e,a>) -> hnd/clause2<string,int,list<string>,memory-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1197 = kk_src_dream__cycle__as_Hnd_memory_ops(_this, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x1197->_fun_recall_memories;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `recall-memories` operation out of effect `:memory-ops`

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_recall_memories_fs__select(kk_src_dream__cycle__memory_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : memory-ops<e,a>) -> hnd/clause2<string,int,list<string>,memory-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1198 = kk_src_dream__cycle__as_Hnd_memory_ops(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_recall_memories = _con_x1198->_fun_recall_memories;
    return kk_std_core_hnd__clause2_dup(_fun_recall_memories, _ctx);
  }
}
 
// returns id
// Call the `fun recall-memories` operation of the effect `:memory-ops`

static inline kk_std_core_types__list kk_src_dream__cycle_recall_memories(kk_string_t query, kk_integer_t limit, kk_context_t* _ctx) { /* (query : string, limit : int) -> memory-ops list<string> */ 
  kk_std_core_hnd__ev evx_10203 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/memory-ops>*/;
  kk_box_t _x_x1199;
  {
    struct kk_std_core_hnd_Ev* _con_x1200 = kk_std_core_hnd__as_Ev(evx_10203, _ctx);
    kk_box_t _box_x18 = _con_x1200->hnd;
    int32_t m = _con_x1200->marker;
    kk_src_dream__cycle__memory_ops h = kk_src_dream__cycle__memory_ops_unbox(_box_x18, KK_BORROWED, _ctx);
    kk_src_dream__cycle__memory_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1201 = kk_src_dream__cycle__as_Hnd_memory_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1201->_cfc;
      kk_std_core_hnd__clause2 _pat_1_0 = _con_x1201->_fun_decay_memory;
      kk_std_core_hnd__clause2 _fun_recall_memories = _con_x1201->_fun_recall_memories;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1201->_fun_store_memory;
      kk_std_core_hnd__clause2 _pat_3 = _con_x1201->_fun_tag_memory;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_recall_memories, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x23 = _fun_recall_memories.clause;
        _x_x1199 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x23, (_fun_unbox_x23, m, evx_10203, kk_string_box(query), kk_integer_box(limit, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x1199, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-tag-memory` constructor field of the `:memory-ops` type.

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_memory_ops_fs__fun_tag_memory(kk_src_dream__cycle__memory_ops _this, kk_context_t* _ctx) { /* forall<e,a> (memory-ops<e,a>) -> hnd/clause2<string,string,bool,memory-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1202 = kk_src_dream__cycle__as_Hnd_memory_ops(_this, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x1202->_fun_tag_memory;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `tag-memory` operation out of effect `:memory-ops`

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_tag_memory_fs__select(kk_src_dream__cycle__memory_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : memory-ops<e,a>) -> hnd/clause2<string,string,bool,memory-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1203 = kk_src_dream__cycle__as_Hnd_memory_ops(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_tag_memory = _con_x1203->_fun_tag_memory;
    return kk_std_core_hnd__clause2_dup(_fun_tag_memory, _ctx);
  }
}
 
// Call the `fun tag-memory` operation of the effect `:memory-ops`

static inline bool kk_src_dream__cycle_tag_memory(kk_string_t id, kk_string_t tag, kk_context_t* _ctx) { /* (id : string, tag : string) -> memory-ops bool */ 
  kk_std_core_hnd__ev evx_10207 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/memory-ops>*/;
  kk_box_t _x_x1204;
  {
    struct kk_std_core_hnd_Ev* _con_x1205 = kk_std_core_hnd__as_Ev(evx_10207, _ctx);
    kk_box_t _box_x28 = _con_x1205->hnd;
    int32_t m = _con_x1205->marker;
    kk_src_dream__cycle__memory_ops h = kk_src_dream__cycle__memory_ops_unbox(_box_x28, KK_BORROWED, _ctx);
    kk_src_dream__cycle__memory_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1206 = kk_src_dream__cycle__as_Hnd_memory_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1206->_cfc;
      kk_std_core_hnd__clause2 _pat_1_0 = _con_x1206->_fun_decay_memory;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1206->_fun_recall_memories;
      kk_std_core_hnd__clause2 _pat_3 = _con_x1206->_fun_store_memory;
      kk_std_core_hnd__clause2 _fun_tag_memory = _con_x1206->_fun_tag_memory;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_tag_memory, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x33 = _fun_tag_memory.clause;
        _x_x1204 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x33, (_fun_unbox_x33, m, evx_10207, kk_string_box(id), kk_string_box(tag), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_bool_unbox(_x_x1204);
}
 
// Automatically generated. Retrieves the `@fun-decay-memory` constructor field of the `:memory-ops` type.

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_memory_ops_fs__fun_decay_memory(kk_src_dream__cycle__memory_ops _this, kk_context_t* _ctx) { /* forall<e,a> (memory-ops<e,a>) -> hnd/clause2<string,float64,bool,memory-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1207 = kk_src_dream__cycle__as_Hnd_memory_ops(_this, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x1207->_fun_decay_memory;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `decay-memory` operation out of effect `:memory-ops`

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_decay_memory_fs__select(kk_src_dream__cycle__memory_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : memory-ops<e,a>) -> hnd/clause2<string,float64,bool,memory-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1208 = kk_src_dream__cycle__as_Hnd_memory_ops(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_decay_memory = _con_x1208->_fun_decay_memory;
    return kk_std_core_hnd__clause2_dup(_fun_decay_memory, _ctx);
  }
}
 
// Call the `fun decay-memory` operation of the effect `:memory-ops`

static inline bool kk_src_dream__cycle_decay_memory(kk_string_t id, double factor, kk_context_t* _ctx) { /* (id : string, factor : float64) -> memory-ops bool */ 
  kk_std_core_hnd__ev evx_10211 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/memory-ops>*/;
  kk_box_t _x_x1209;
  {
    struct kk_std_core_hnd_Ev* _con_x1210 = kk_std_core_hnd__as_Ev(evx_10211, _ctx);
    kk_box_t _box_x38 = _con_x1210->hnd;
    int32_t m = _con_x1210->marker;
    kk_src_dream__cycle__memory_ops h = kk_src_dream__cycle__memory_ops_unbox(_box_x38, KK_BORROWED, _ctx);
    kk_src_dream__cycle__memory_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1211 = kk_src_dream__cycle__as_Hnd_memory_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1211->_cfc;
      kk_std_core_hnd__clause2 _fun_decay_memory = _con_x1211->_fun_decay_memory;
      kk_std_core_hnd__clause2 _pat_1_0 = _con_x1211->_fun_recall_memories;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1211->_fun_store_memory;
      kk_std_core_hnd__clause2 _pat_3 = _con_x1211->_fun_tag_memory;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_decay_memory, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x43 = _fun_decay_memory.clause;
        _x_x1209 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x43, (_fun_unbox_x43, m, evx_10211, kk_string_box(id), kk_double_box(factor, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_bool_unbox(_x_x1209);
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:constellation-ops` type.

static inline kk_integer_t kk_src_dream__cycle_constellation_ops_fs__cfc(kk_src_dream__cycle__constellation_ops _this, kk_context_t* _ctx) { /* forall<e,a> (constellation-ops<e,a>) -> int */ 
  {
    struct kk_src_dream__cycle__Hnd_constellation_ops* _con_x1212 = kk_src_dream__cycle__as_Hnd_constellation_ops(_this, _ctx);
    kk_integer_t _x = _con_x1212->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_src_dream__cycle_constellation_ops_fs__tag;

kk_box_t kk_src_dream__cycle_constellation_ops_fs__handle(kk_src_dream__cycle__constellation_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : constellation-ops<e,b>, ret : (res : a) -> e b, action : () -> <constellation-ops|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-detect-constellations` constructor field of the `:constellation-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_constellation_ops_fs__fun_detect_constellations(kk_src_dream__cycle__constellation_ops _this, kk_context_t* _ctx) { /* forall<e,a> (constellation-ops<e,a>) -> hnd/clause1<int,list<string>,constellation-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_constellation_ops* _con_x1216 = kk_src_dream__cycle__as_Hnd_constellation_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1216->_fun_detect_constellations;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `detect-constellations` operation out of effect `:constellation-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_detect_constellations_fs__select(kk_src_dream__cycle__constellation_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : constellation-ops<e,a>) -> hnd/clause1<int,list<string>,constellation-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_constellation_ops* _con_x1217 = kk_src_dream__cycle__as_Hnd_constellation_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_detect_constellations = _con_x1217->_fun_detect_constellations;
    return kk_std_core_hnd__clause1_dup(_fun_detect_constellations, _ctx);
  }
}
 
// Call the `fun detect-constellations` operation of the effect `:constellation-ops`

static inline kk_std_core_types__list kk_src_dream__cycle_detect_constellations(kk_integer_t min_size, kk_context_t* _ctx) { /* (min-size : int) -> constellation-ops list<string> */ 
  kk_std_core_hnd__ev ev_10216 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/constellation-ops>*/;
  kk_box_t _x_x1218;
  {
    struct kk_std_core_hnd_Ev* _con_x1219 = kk_std_core_hnd__as_Ev(ev_10216, _ctx);
    kk_box_t _box_x56 = _con_x1219->hnd;
    int32_t m = _con_x1219->marker;
    kk_src_dream__cycle__constellation_ops h = kk_src_dream__cycle__constellation_ops_unbox(_box_x56, KK_BORROWED, _ctx);
    kk_src_dream__cycle__constellation_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_constellation_ops* _con_x1220 = kk_src_dream__cycle__as_Hnd_constellation_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1220->_cfc;
      kk_std_core_hnd__clause2 _pat_1_0 = _con_x1220->_fun_add_to_constellation;
      kk_std_core_hnd__clause1 _fun_detect_constellations = _con_x1220->_fun_detect_constellations;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1220->_fun_merge_constellations;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_detect_constellations, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x60 = _fun_detect_constellations.clause;
        _x_x1218 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x60, (_fun_unbox_x60, m, ev_10216, kk_integer_box(min_size, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x1218, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-add-to-constellation` constructor field of the `:constellation-ops` type.

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_constellation_ops_fs__fun_add_to_constellation(kk_src_dream__cycle__constellation_ops _this, kk_context_t* _ctx) { /* forall<e,a> (constellation-ops<e,a>) -> hnd/clause2<string,string,bool,constellation-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_constellation_ops* _con_x1221 = kk_src_dream__cycle__as_Hnd_constellation_ops(_this, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x1221->_fun_add_to_constellation;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `add-to-constellation` operation out of effect `:constellation-ops`

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_add_to_constellation_fs__select(kk_src_dream__cycle__constellation_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : constellation-ops<e,a>) -> hnd/clause2<string,string,bool,constellation-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_constellation_ops* _con_x1222 = kk_src_dream__cycle__as_Hnd_constellation_ops(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_add_to_constellation = _con_x1222->_fun_add_to_constellation;
    return kk_std_core_hnd__clause2_dup(_fun_add_to_constellation, _ctx);
  }
}
 
// returns cluster ids
// Call the `fun add-to-constellation` operation of the effect `:constellation-ops`

static inline bool kk_src_dream__cycle_add_to_constellation(kk_string_t memory_id, kk_string_t cluster_id, kk_context_t* _ctx) { /* (memory-id : string, cluster-id : string) -> constellation-ops bool */ 
  kk_std_core_hnd__ev evx_10219 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/constellation-ops>*/;
  kk_box_t _x_x1223;
  {
    struct kk_std_core_hnd_Ev* _con_x1224 = kk_std_core_hnd__as_Ev(evx_10219, _ctx);
    kk_box_t _box_x64 = _con_x1224->hnd;
    int32_t m = _con_x1224->marker;
    kk_src_dream__cycle__constellation_ops h = kk_src_dream__cycle__constellation_ops_unbox(_box_x64, KK_BORROWED, _ctx);
    kk_src_dream__cycle__constellation_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_constellation_ops* _con_x1225 = kk_src_dream__cycle__as_Hnd_constellation_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1225->_cfc;
      kk_std_core_hnd__clause2 _fun_add_to_constellation = _con_x1225->_fun_add_to_constellation;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1225->_fun_detect_constellations;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1225->_fun_merge_constellations;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_add_to_constellation, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x69 = _fun_add_to_constellation.clause;
        _x_x1223 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x69, (_fun_unbox_x69, m, evx_10219, kk_string_box(memory_id), kk_string_box(cluster_id), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_bool_unbox(_x_x1223);
}
 
// Automatically generated. Retrieves the `@fun-merge-constellations` constructor field of the `:constellation-ops` type.

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_constellation_ops_fs__fun_merge_constellations(kk_src_dream__cycle__constellation_ops _this, kk_context_t* _ctx) { /* forall<e,a> (constellation-ops<e,a>) -> hnd/clause2<string,string,string,constellation-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_constellation_ops* _con_x1226 = kk_src_dream__cycle__as_Hnd_constellation_ops(_this, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x1226->_fun_merge_constellations;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `merge-constellations` operation out of effect `:constellation-ops`

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_merge_constellations_fs__select(kk_src_dream__cycle__constellation_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : constellation-ops<e,a>) -> hnd/clause2<string,string,string,constellation-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_constellation_ops* _con_x1227 = kk_src_dream__cycle__as_Hnd_constellation_ops(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_merge_constellations = _con_x1227->_fun_merge_constellations;
    return kk_std_core_hnd__clause2_dup(_fun_merge_constellations, _ctx);
  }
}
 
// Call the `fun merge-constellations` operation of the effect `:constellation-ops`

static inline kk_string_t kk_src_dream__cycle_merge_constellations(kk_string_t a, kk_string_t b, kk_context_t* _ctx) { /* (a : string, b : string) -> constellation-ops string */ 
  kk_std_core_hnd__ev evx_10223 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/constellation-ops>*/;
  kk_box_t _x_x1228;
  {
    struct kk_std_core_hnd_Ev* _con_x1229 = kk_std_core_hnd__as_Ev(evx_10223, _ctx);
    kk_box_t _box_x74 = _con_x1229->hnd;
    int32_t m = _con_x1229->marker;
    kk_src_dream__cycle__constellation_ops h = kk_src_dream__cycle__constellation_ops_unbox(_box_x74, KK_BORROWED, _ctx);
    kk_src_dream__cycle__constellation_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_constellation_ops* _con_x1230 = kk_src_dream__cycle__as_Hnd_constellation_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1230->_cfc;
      kk_std_core_hnd__clause2 _pat_1_0 = _con_x1230->_fun_add_to_constellation;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1230->_fun_detect_constellations;
      kk_std_core_hnd__clause2 _fun_merge_constellations = _con_x1230->_fun_merge_constellations;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_merge_constellations, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x79 = _fun_merge_constellations.clause;
        _x_x1228 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x79, (_fun_unbox_x79, m, evx_10223, kk_string_box(a), kk_string_box(b), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_string_unbox(_x_x1228);
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:insight-ops` type.

static inline kk_integer_t kk_src_dream__cycle_insight_ops_fs__cfc(kk_src_dream__cycle__insight_ops _this, kk_context_t* _ctx) { /* forall<e,a> (insight-ops<e,a>) -> int */ 
  {
    struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1231 = kk_src_dream__cycle__as_Hnd_insight_ops(_this, _ctx);
    kk_integer_t _x = _con_x1231->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_src_dream__cycle_insight_ops_fs__tag;

kk_box_t kk_src_dream__cycle_insight_ops_fs__handle(kk_src_dream__cycle__insight_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : insight-ops<e,b>, ret : (res : a) -> e b, action : () -> <insight-ops|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-create-bridge` constructor field of the `:insight-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_insight_ops_fs__fun_create_bridge(kk_src_dream__cycle__insight_ops _this, kk_context_t* _ctx) { /* forall<e,a> (insight-ops<e,a>) -> hnd/clause1<(string, string, float64),string,insight-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1235 = kk_src_dream__cycle__as_Hnd_insight_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1235->_fun_create_bridge;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `create-bridge` operation out of effect `:insight-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_create_bridge_fs__select(kk_src_dream__cycle__insight_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : insight-ops<e,a>) -> hnd/clause1<(string, string, float64),string,insight-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1236 = kk_src_dream__cycle__as_Hnd_insight_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_create_bridge = _con_x1236->_fun_create_bridge;
    return kk_std_core_hnd__clause1_dup(_fun_create_bridge, _ctx);
  }
}
 
// Call the `fun create-bridge` operation of the effect `:insight-ops`


// lift anonymous function
struct kk_src_dream__cycle_create_bridge_fun1238__t {
  struct kk_function_s _base;
};
extern kk_std_core_hnd__clause1 kk_src_dream__cycle_create_bridge_fun1238(kk_function_t _fself, kk_box_t _b_x97, kk_context_t* _ctx);
static inline kk_function_t kk_src_dream__cycle_new_create_bridge_fun1238(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_create_bridge_fun1238, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}


static inline kk_string_t kk_src_dream__cycle_create_bridge(kk_string_t source, kk_string_t target, double strength, kk_context_t* _ctx) { /* (source : string, target : string, strength : float64) -> insight-ops string */ 
  kk_std_core_hnd__ev _b_x92_98 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/insight-ops>*/;
  kk_box_t _x_x1237 = kk_std_core_hnd__perform3(_b_x92_98, kk_src_dream__cycle_new_create_bridge_fun1238(_ctx), kk_string_box(source), kk_string_box(target), kk_double_box(strength, _ctx), _ctx); /*10003*/
  return kk_string_unbox(_x_x1237);
}
 
// Automatically generated. Retrieves the `@fun-emit-insight` constructor field of the `:insight-ops` type.

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_insight_ops_fs__fun_emit_insight(kk_src_dream__cycle__insight_ops _this, kk_context_t* _ctx) { /* forall<e,a> (insight-ops<e,a>) -> hnd/clause2<string,float64,bool,insight-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1239 = kk_src_dream__cycle__as_Hnd_insight_ops(_this, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x1239->_fun_emit_insight;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `emit-insight` operation out of effect `:insight-ops`

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_emit_insight_fs__select(kk_src_dream__cycle__insight_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : insight-ops<e,a>) -> hnd/clause2<string,float64,bool,insight-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1240 = kk_src_dream__cycle__as_Hnd_insight_ops(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_emit_insight = _con_x1240->_fun_emit_insight;
    return kk_std_core_hnd__clause2_dup(_fun_emit_insight, _ctx);
  }
}
 
// Call the `fun emit-insight` operation of the effect `:insight-ops`

static inline bool kk_src_dream__cycle_emit_insight(kk_string_t content, double confidence, kk_context_t* _ctx) { /* (content : string, confidence : float64) -> insight-ops bool */ 
  kk_std_core_hnd__ev evx_10228 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/insight-ops>*/;
  kk_box_t _x_x1241;
  {
    struct kk_std_core_hnd_Ev* _con_x1242 = kk_std_core_hnd__as_Ev(evx_10228, _ctx);
    kk_box_t _box_x103 = _con_x1242->hnd;
    int32_t m = _con_x1242->marker;
    kk_src_dream__cycle__insight_ops h = kk_src_dream__cycle__insight_ops_unbox(_box_x103, KK_BORROWED, _ctx);
    kk_src_dream__cycle__insight_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1243 = kk_src_dream__cycle__as_Hnd_insight_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1243->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1243->_fun_create_bridge;
      kk_std_core_hnd__clause2 _fun_emit_insight = _con_x1243->_fun_emit_insight;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1243->_fun_get_serendipity_candidates;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_emit_insight, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x108 = _fun_emit_insight.clause;
        _x_x1241 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x108, (_fun_unbox_x108, m, evx_10228, kk_string_box(content), kk_double_box(confidence, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_bool_unbox(_x_x1241);
}
 
// Automatically generated. Retrieves the `@fun-get-serendipity-candidates` constructor field of the `:insight-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_insight_ops_fs__fun_get_serendipity_candidates(kk_src_dream__cycle__insight_ops _this, kk_context_t* _ctx) { /* forall<e,a> (insight-ops<e,a>) -> hnd/clause1<int,list<string>,insight-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1244 = kk_src_dream__cycle__as_Hnd_insight_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1244->_fun_get_serendipity_candidates;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `get-serendipity-candidates` operation out of effect `:insight-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_get_serendipity_candidates_fs__select(kk_src_dream__cycle__insight_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : insight-ops<e,a>) -> hnd/clause1<int,list<string>,insight-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1245 = kk_src_dream__cycle__as_Hnd_insight_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_get_serendipity_candidates = _con_x1245->_fun_get_serendipity_candidates;
    return kk_std_core_hnd__clause1_dup(_fun_get_serendipity_candidates, _ctx);
  }
}
 
// Call the `fun get-serendipity-candidates` operation of the effect `:insight-ops`

static inline kk_std_core_types__list kk_src_dream__cycle_get_serendipity_candidates(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> insight-ops list<string> */ 
  kk_std_core_hnd__ev ev_10232 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/insight-ops>*/;
  kk_box_t _x_x1246;
  {
    struct kk_std_core_hnd_Ev* _con_x1247 = kk_std_core_hnd__as_Ev(ev_10232, _ctx);
    kk_box_t _box_x113 = _con_x1247->hnd;
    int32_t m = _con_x1247->marker;
    kk_src_dream__cycle__insight_ops h = kk_src_dream__cycle__insight_ops_unbox(_box_x113, KK_BORROWED, _ctx);
    kk_src_dream__cycle__insight_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1248 = kk_src_dream__cycle__as_Hnd_insight_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1248->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1248->_fun_create_bridge;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1248->_fun_emit_insight;
      kk_std_core_hnd__clause1 _fun_get_serendipity_candidates = _con_x1248->_fun_get_serendipity_candidates;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_get_serendipity_candidates, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x117 = _fun_get_serendipity_candidates.clause;
        _x_x1246 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x117, (_fun_unbox_x117, m, ev_10232, kk_integer_box(n, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x1246, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:governance-ops` type.

static inline kk_integer_t kk_src_dream__cycle_governance_ops_fs__cfc(kk_src_dream__cycle__governance_ops _this, kk_context_t* _ctx) { /* forall<e,a> (governance-ops<e,a>) -> int */ 
  {
    struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1249 = kk_src_dream__cycle__as_Hnd_governance_ops(_this, _ctx);
    kk_integer_t _x = _con_x1249->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_src_dream__cycle_governance_ops_fs__tag;

kk_box_t kk_src_dream__cycle_governance_ops_fs__handle(kk_src_dream__cycle__governance_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : governance-ops<e,b>, ret : (res : a) -> e b, action : () -> <governance-ops|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-check-echo-chambers` constructor field of the `:governance-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_governance_ops_fs__fun_check_echo_chambers(kk_src_dream__cycle__governance_ops _this, kk_context_t* _ctx) { /* forall<e,a> (governance-ops<e,a>) -> hnd/clause1<float64,list<string>,governance-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1253 = kk_src_dream__cycle__as_Hnd_governance_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1253->_fun_check_echo_chambers;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `check-echo-chambers` operation out of effect `:governance-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_check_echo_chambers_fs__select(kk_src_dream__cycle__governance_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : governance-ops<e,a>) -> hnd/clause1<float64,list<string>,governance-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1254 = kk_src_dream__cycle__as_Hnd_governance_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_check_echo_chambers = _con_x1254->_fun_check_echo_chambers;
    return kk_std_core_hnd__clause1_dup(_fun_check_echo_chambers, _ctx);
  }
}
 
// Call the `fun check-echo-chambers` operation of the effect `:governance-ops`

static inline kk_std_core_types__list kk_src_dream__cycle_check_echo_chambers(double threshold, kk_context_t* _ctx) { /* (threshold : float64) -> governance-ops list<string> */ 
  kk_std_core_hnd__ev ev_10236 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/governance-ops>*/;
  kk_box_t _x_x1255;
  {
    struct kk_std_core_hnd_Ev* _con_x1256 = kk_std_core_hnd__as_Ev(ev_10236, _ctx);
    kk_box_t _box_x129 = _con_x1256->hnd;
    int32_t m = _con_x1256->marker;
    kk_src_dream__cycle__governance_ops h = kk_src_dream__cycle__governance_ops_unbox(_box_x129, KK_BORROWED, _ctx);
    kk_src_dream__cycle__governance_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1257 = kk_src_dream__cycle__as_Hnd_governance_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1257->_cfc;
      kk_std_core_hnd__clause1 _fun_check_echo_chambers = _con_x1257->_fun_check_echo_chambers;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x1257->_fun_get_community_health;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1257->_fun_rebalance_community;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_check_echo_chambers, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x133 = _fun_check_echo_chambers.clause;
        _x_x1255 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x133, (_fun_unbox_x133, m, ev_10236, kk_double_box(threshold, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x1255, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-rebalance-community` constructor field of the `:governance-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_governance_ops_fs__fun_rebalance_community(kk_src_dream__cycle__governance_ops _this, kk_context_t* _ctx) { /* forall<e,a> (governance-ops<e,a>) -> hnd/clause1<string,bool,governance-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1258 = kk_src_dream__cycle__as_Hnd_governance_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1258->_fun_rebalance_community;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `rebalance-community` operation out of effect `:governance-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_rebalance_community_fs__select(kk_src_dream__cycle__governance_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : governance-ops<e,a>) -> hnd/clause1<string,bool,governance-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1259 = kk_src_dream__cycle__as_Hnd_governance_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_rebalance_community = _con_x1259->_fun_rebalance_community;
    return kk_std_core_hnd__clause1_dup(_fun_rebalance_community, _ctx);
  }
}
 
// Call the `fun rebalance-community` operation of the effect `:governance-ops`

static inline bool kk_src_dream__cycle_rebalance_community(kk_string_t community_id, kk_context_t* _ctx) { /* (community-id : string) -> governance-ops bool */ 
  kk_std_core_hnd__ev ev_10239 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/governance-ops>*/;
  kk_box_t _x_x1260;
  {
    struct kk_std_core_hnd_Ev* _con_x1261 = kk_std_core_hnd__as_Ev(ev_10239, _ctx);
    kk_box_t _box_x137 = _con_x1261->hnd;
    int32_t m = _con_x1261->marker;
    kk_src_dream__cycle__governance_ops h = kk_src_dream__cycle__governance_ops_unbox(_box_x137, KK_BORROWED, _ctx);
    kk_src_dream__cycle__governance_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1262 = kk_src_dream__cycle__as_Hnd_governance_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1262->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1262->_fun_check_echo_chambers;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x1262->_fun_get_community_health;
      kk_std_core_hnd__clause1 _fun_rebalance_community = _con_x1262->_fun_rebalance_community;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_rebalance_community, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x141 = _fun_rebalance_community.clause;
        _x_x1260 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x141, (_fun_unbox_x141, m, ev_10239, kk_string_box(community_id), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_bool_unbox(_x_x1260);
}
 
// Automatically generated. Retrieves the `@fun-get-community-health` constructor field of the `:governance-ops` type.

static inline kk_std_core_hnd__clause0 kk_src_dream__cycle_governance_ops_fs__fun_get_community_health(kk_src_dream__cycle__governance_ops _this, kk_context_t* _ctx) { /* forall<e,a> (governance-ops<e,a>) -> hnd/clause0<float64,governance-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1263 = kk_src_dream__cycle__as_Hnd_governance_ops(_this, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x1263->_fun_get_community_health;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-community-health` operation out of effect `:governance-ops`

static inline kk_std_core_hnd__clause0 kk_src_dream__cycle_get_community_health_fs__select(kk_src_dream__cycle__governance_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : governance-ops<e,a>) -> hnd/clause0<float64,governance-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1264 = kk_src_dream__cycle__as_Hnd_governance_ops(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_community_health = _con_x1264->_fun_get_community_health;
    return kk_std_core_hnd__clause0_dup(_fun_get_community_health, _ctx);
  }
}
 
// Call the `fun get-community-health` operation of the effect `:governance-ops`

static inline double kk_src_dream__cycle_get_community_health(kk_context_t* _ctx) { /* () -> governance-ops float64 */ 
  kk_std_core_hnd__ev ev_10242 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/governance-ops>*/;
  kk_box_t _x_x1265;
  {
    struct kk_std_core_hnd_Ev* _con_x1266 = kk_std_core_hnd__as_Ev(ev_10242, _ctx);
    kk_box_t _box_x145 = _con_x1266->hnd;
    int32_t m = _con_x1266->marker;
    kk_src_dream__cycle__governance_ops h = kk_src_dream__cycle__governance_ops_unbox(_box_x145, KK_BORROWED, _ctx);
    kk_src_dream__cycle__governance_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1267 = kk_src_dream__cycle__as_Hnd_governance_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1267->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1267->_fun_check_echo_chambers;
      kk_std_core_hnd__clause0 _fun_get_community_health = _con_x1267->_fun_get_community_health;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1267->_fun_rebalance_community;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_community_health, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x148 = _fun_get_community_health.clause;
        _x_x1265 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x148, (_fun_unbox_x148, m, ev_10242, _ctx), _ctx); /*10005*/
      }
    }
  }
  return kk_double_unbox(_x_x1265, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:narrative-ops` type.

static inline kk_integer_t kk_src_dream__cycle_narrative_ops_fs__cfc(kk_src_dream__cycle__narrative_ops _this, kk_context_t* _ctx) { /* forall<e,a> (narrative-ops<e,a>) -> int */ 
  {
    struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1268 = kk_src_dream__cycle__as_Hnd_narrative_ops(_this, _ctx);
    kk_integer_t _x = _con_x1268->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_src_dream__cycle_narrative_ops_fs__tag;

kk_box_t kk_src_dream__cycle_narrative_ops_fs__handle(kk_src_dream__cycle__narrative_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : narrative-ops<e,b>, ret : (res : a) -> e b, action : () -> <narrative-ops|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-cluster-narratives` constructor field of the `:narrative-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_narrative_ops_fs__fun_cluster_narratives(kk_src_dream__cycle__narrative_ops _this, kk_context_t* _ctx) { /* forall<e,a> (narrative-ops<e,a>) -> hnd/clause1<list<string>,list<string>,narrative-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1272 = kk_src_dream__cycle__as_Hnd_narrative_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1272->_fun_cluster_narratives;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `cluster-narratives` operation out of effect `:narrative-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_cluster_narratives_fs__select(kk_src_dream__cycle__narrative_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : narrative-ops<e,a>) -> hnd/clause1<list<string>,list<string>,narrative-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1273 = kk_src_dream__cycle__as_Hnd_narrative_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_cluster_narratives = _con_x1273->_fun_cluster_narratives;
    return kk_std_core_hnd__clause1_dup(_fun_cluster_narratives, _ctx);
  }
}
 
// Call the `fun cluster-narratives` operation of the effect `:narrative-ops`

static inline kk_std_core_types__list kk_src_dream__cycle_cluster_narratives(kk_std_core_types__list memories, kk_context_t* _ctx) { /* (memories : list<string>) -> narrative-ops list<string> */ 
  kk_std_core_hnd__ev ev_10245 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/narrative-ops>*/;
  kk_box_t _x_x1274;
  {
    struct kk_std_core_hnd_Ev* _con_x1275 = kk_std_core_hnd__as_Ev(ev_10245, _ctx);
    kk_box_t _box_x159 = _con_x1275->hnd;
    int32_t m = _con_x1275->marker;
    kk_src_dream__cycle__narrative_ops h = kk_src_dream__cycle__narrative_ops_unbox(_box_x159, KK_BORROWED, _ctx);
    kk_src_dream__cycle__narrative_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1276 = kk_src_dream__cycle__as_Hnd_narrative_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1276->_cfc;
      kk_std_core_hnd__clause1 _fun_cluster_narratives = _con_x1276->_fun_cluster_narratives;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1276->_fun_compress_narrative;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1276->_fun_get_narrative_threads;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_cluster_narratives, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x163 = _fun_cluster_narratives.clause;
        _x_x1274 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x163, (_fun_unbox_x163, m, ev_10245, kk_std_core_types__list_box(memories, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x1274, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-compress-narrative` constructor field of the `:narrative-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_narrative_ops_fs__fun_compress_narrative(kk_src_dream__cycle__narrative_ops _this, kk_context_t* _ctx) { /* forall<e,a> (narrative-ops<e,a>) -> hnd/clause1<string,string,narrative-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1277 = kk_src_dream__cycle__as_Hnd_narrative_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1277->_fun_compress_narrative;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `compress-narrative` operation out of effect `:narrative-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_compress_narrative_fs__select(kk_src_dream__cycle__narrative_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : narrative-ops<e,a>) -> hnd/clause1<string,string,narrative-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1278 = kk_src_dream__cycle__as_Hnd_narrative_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_compress_narrative = _con_x1278->_fun_compress_narrative;
    return kk_std_core_hnd__clause1_dup(_fun_compress_narrative, _ctx);
  }
}
 
// Call the `fun compress-narrative` operation of the effect `:narrative-ops`

static inline kk_string_t kk_src_dream__cycle_compress_narrative(kk_string_t cluster_id, kk_context_t* _ctx) { /* (cluster-id : string) -> narrative-ops string */ 
  kk_std_core_hnd__ev ev_10248 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/narrative-ops>*/;
  kk_box_t _x_x1279;
  {
    struct kk_std_core_hnd_Ev* _con_x1280 = kk_std_core_hnd__as_Ev(ev_10248, _ctx);
    kk_box_t _box_x167 = _con_x1280->hnd;
    int32_t m = _con_x1280->marker;
    kk_src_dream__cycle__narrative_ops h = kk_src_dream__cycle__narrative_ops_unbox(_box_x167, KK_BORROWED, _ctx);
    kk_src_dream__cycle__narrative_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1281 = kk_src_dream__cycle__as_Hnd_narrative_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1281->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1281->_fun_cluster_narratives;
      kk_std_core_hnd__clause1 _fun_compress_narrative = _con_x1281->_fun_compress_narrative;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1281->_fun_get_narrative_threads;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_compress_narrative, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x171 = _fun_compress_narrative.clause;
        _x_x1279 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x171, (_fun_unbox_x171, m, ev_10248, kk_string_box(cluster_id), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_string_unbox(_x_x1279);
}
 
// Automatically generated. Retrieves the `@fun-get-narrative-threads` constructor field of the `:narrative-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_narrative_ops_fs__fun_get_narrative_threads(kk_src_dream__cycle__narrative_ops _this, kk_context_t* _ctx) { /* forall<e,a> (narrative-ops<e,a>) -> hnd/clause1<int,list<string>,narrative-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1282 = kk_src_dream__cycle__as_Hnd_narrative_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1282->_fun_get_narrative_threads;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `get-narrative-threads` operation out of effect `:narrative-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_get_narrative_threads_fs__select(kk_src_dream__cycle__narrative_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : narrative-ops<e,a>) -> hnd/clause1<int,list<string>,narrative-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1283 = kk_src_dream__cycle__as_Hnd_narrative_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_get_narrative_threads = _con_x1283->_fun_get_narrative_threads;
    return kk_std_core_hnd__clause1_dup(_fun_get_narrative_threads, _ctx);
  }
}
 
// Call the `fun get-narrative-threads` operation of the effect `:narrative-ops`

static inline kk_std_core_types__list kk_src_dream__cycle_get_narrative_threads(kk_integer_t limit, kk_context_t* _ctx) { /* (limit : int) -> narrative-ops list<string> */ 
  kk_std_core_hnd__ev ev_10251 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/narrative-ops>*/;
  kk_box_t _x_x1284;
  {
    struct kk_std_core_hnd_Ev* _con_x1285 = kk_std_core_hnd__as_Ev(ev_10251, _ctx);
    kk_box_t _box_x175 = _con_x1285->hnd;
    int32_t m = _con_x1285->marker;
    kk_src_dream__cycle__narrative_ops h = kk_src_dream__cycle__narrative_ops_unbox(_box_x175, KK_BORROWED, _ctx);
    kk_src_dream__cycle__narrative_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1286 = kk_src_dream__cycle__as_Hnd_narrative_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1286->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1286->_fun_cluster_narratives;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1286->_fun_compress_narrative;
      kk_std_core_hnd__clause1 _fun_get_narrative_threads = _con_x1286->_fun_get_narrative_threads;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_get_narrative_threads, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x179 = _fun_get_narrative_threads.clause;
        _x_x1284 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x179, (_fun_unbox_x179, m, ev_10251, kk_integer_box(limit, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x1284, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:kaizen-ops` type.

static inline kk_integer_t kk_src_dream__cycle_kaizen_ops_fs__cfc(kk_src_dream__cycle__kaizen_ops _this, kk_context_t* _ctx) { /* forall<e,a> (kaizen-ops<e,a>) -> int */ 
  {
    struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1287 = kk_src_dream__cycle__as_Hnd_kaizen_ops(_this, _ctx);
    kk_integer_t _x = _con_x1287->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_src_dream__cycle_kaizen_ops_fs__tag;

kk_box_t kk_src_dream__cycle_kaizen_ops_fs__handle(kk_src_dream__cycle__kaizen_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : kaizen-ops<e,b>, ret : (res : a) -> e b, action : () -> <kaizen-ops|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-scan-emergence` constructor field of the `:kaizen-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_kaizen_ops_fs__fun_scan_emergence(kk_src_dream__cycle__kaizen_ops _this, kk_context_t* _ctx) { /* forall<e,a> (kaizen-ops<e,a>) -> hnd/clause1<int,list<string>,kaizen-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1291 = kk_src_dream__cycle__as_Hnd_kaizen_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1291->_fun_scan_emergence;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `scan-emergence` operation out of effect `:kaizen-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_scan_emergence_fs__select(kk_src_dream__cycle__kaizen_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : kaizen-ops<e,a>) -> hnd/clause1<int,list<string>,kaizen-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1292 = kk_src_dream__cycle__as_Hnd_kaizen_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_scan_emergence = _con_x1292->_fun_scan_emergence;
    return kk_std_core_hnd__clause1_dup(_fun_scan_emergence, _ctx);
  }
}
 
// Call the `fun scan-emergence` operation of the effect `:kaizen-ops`

static inline kk_std_core_types__list kk_src_dream__cycle_scan_emergence(kk_integer_t depth, kk_context_t* _ctx) { /* (depth : int) -> kaizen-ops list<string> */ 
  kk_std_core_hnd__ev ev_10255 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/kaizen-ops>*/;
  kk_box_t _x_x1293;
  {
    struct kk_std_core_hnd_Ev* _con_x1294 = kk_std_core_hnd__as_Ev(ev_10255, _ctx);
    kk_box_t _box_x191 = _con_x1294->hnd;
    int32_t m = _con_x1294->marker;
    kk_src_dream__cycle__kaizen_ops h = kk_src_dream__cycle__kaizen_ops_unbox(_box_x191, KK_BORROWED, _ctx);
    kk_src_dream__cycle__kaizen_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1295 = kk_src_dream__cycle__as_Hnd_kaizen_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1295->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x1295->_fun_get_improvement_candidates;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1295->_fun_persist_insight;
      kk_std_core_hnd__clause1 _fun_scan_emergence = _con_x1295->_fun_scan_emergence;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_scan_emergence, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x195 = _fun_scan_emergence.clause;
        _x_x1293 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x195, (_fun_unbox_x195, m, ev_10255, kk_integer_box(depth, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x1293, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-persist-insight` constructor field of the `:kaizen-ops` type.

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_kaizen_ops_fs__fun_persist_insight(kk_src_dream__cycle__kaizen_ops _this, kk_context_t* _ctx) { /* forall<e,a> (kaizen-ops<e,a>) -> hnd/clause2<string,list<string>,bool,kaizen-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1296 = kk_src_dream__cycle__as_Hnd_kaizen_ops(_this, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x1296->_fun_persist_insight;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `persist-insight` operation out of effect `:kaizen-ops`

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_persist_insight_fs__select(kk_src_dream__cycle__kaizen_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : kaizen-ops<e,a>) -> hnd/clause2<string,list<string>,bool,kaizen-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1297 = kk_src_dream__cycle__as_Hnd_kaizen_ops(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_persist_insight = _con_x1297->_fun_persist_insight;
    return kk_std_core_hnd__clause2_dup(_fun_persist_insight, _ctx);
  }
}
 
// Call the `fun persist-insight` operation of the effect `:kaizen-ops`

static inline bool kk_src_dream__cycle_persist_insight(kk_string_t insight, kk_std_core_types__list tags, kk_context_t* _ctx) { /* (insight : string, tags : list<string>) -> kaizen-ops bool */ 
  kk_std_core_hnd__ev evx_10258 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/kaizen-ops>*/;
  kk_box_t _x_x1298;
  {
    struct kk_std_core_hnd_Ev* _con_x1299 = kk_std_core_hnd__as_Ev(evx_10258, _ctx);
    kk_box_t _box_x199 = _con_x1299->hnd;
    int32_t m = _con_x1299->marker;
    kk_src_dream__cycle__kaizen_ops h = kk_src_dream__cycle__kaizen_ops_unbox(_box_x199, KK_BORROWED, _ctx);
    kk_src_dream__cycle__kaizen_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1300 = kk_src_dream__cycle__as_Hnd_kaizen_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1300->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x1300->_fun_get_improvement_candidates;
      kk_std_core_hnd__clause2 _fun_persist_insight = _con_x1300->_fun_persist_insight;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1300->_fun_scan_emergence;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_persist_insight, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x204 = _fun_persist_insight.clause;
        _x_x1298 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x204, (_fun_unbox_x204, m, evx_10258, kk_string_box(insight), kk_std_core_types__list_box(tags, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_bool_unbox(_x_x1298);
}
 
// Automatically generated. Retrieves the `@fun-get-improvement-candidates` constructor field of the `:kaizen-ops` type.

static inline kk_std_core_hnd__clause0 kk_src_dream__cycle_kaizen_ops_fs__fun_get_improvement_candidates(kk_src_dream__cycle__kaizen_ops _this, kk_context_t* _ctx) { /* forall<e,a> (kaizen-ops<e,a>) -> hnd/clause0<list<string>,kaizen-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1301 = kk_src_dream__cycle__as_Hnd_kaizen_ops(_this, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x1301->_fun_get_improvement_candidates;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-improvement-candidates` operation out of effect `:kaizen-ops`

static inline kk_std_core_hnd__clause0 kk_src_dream__cycle_get_improvement_candidates_fs__select(kk_src_dream__cycle__kaizen_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : kaizen-ops<e,a>) -> hnd/clause0<list<string>,kaizen-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1302 = kk_src_dream__cycle__as_Hnd_kaizen_ops(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_improvement_candidates = _con_x1302->_fun_get_improvement_candidates;
    return kk_std_core_hnd__clause0_dup(_fun_get_improvement_candidates, _ctx);
  }
}
 
// Call the `fun get-improvement-candidates` operation of the effect `:kaizen-ops`

static inline kk_std_core_types__list kk_src_dream__cycle_get_improvement_candidates(kk_context_t* _ctx) { /* () -> kaizen-ops list<string> */ 
  kk_std_core_hnd__ev ev_10262 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/kaizen-ops>*/;
  kk_box_t _x_x1303;
  {
    struct kk_std_core_hnd_Ev* _con_x1304 = kk_std_core_hnd__as_Ev(ev_10262, _ctx);
    kk_box_t _box_x209 = _con_x1304->hnd;
    int32_t m = _con_x1304->marker;
    kk_src_dream__cycle__kaizen_ops h = kk_src_dream__cycle__kaizen_ops_unbox(_box_x209, KK_BORROWED, _ctx);
    kk_src_dream__cycle__kaizen_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1305 = kk_src_dream__cycle__as_Hnd_kaizen_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1305->_cfc;
      kk_std_core_hnd__clause0 _fun_get_improvement_candidates = _con_x1305->_fun_get_improvement_candidates;
      kk_std_core_hnd__clause2 _pat_1_0 = _con_x1305->_fun_persist_insight;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1305->_fun_scan_emergence;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_improvement_candidates, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x212 = _fun_get_improvement_candidates.clause;
        _x_x1303 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x212, (_fun_unbox_x212, m, ev_10262, _ctx), _ctx); /*10005*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x1303, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:oracle-ops` type.

static inline kk_integer_t kk_src_dream__cycle_oracle_ops_fs__cfc(kk_src_dream__cycle__oracle_ops _this, kk_context_t* _ctx) { /* forall<e,a> (oracle-ops<e,a>) -> int */ 
  {
    struct kk_src_dream__cycle__Hnd_oracle_ops* _con_x1306 = kk_src_dream__cycle__as_Hnd_oracle_ops(_this, _ctx);
    kk_integer_t _x = _con_x1306->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_src_dream__cycle_oracle_ops_fs__tag;

kk_box_t kk_src_dream__cycle_oracle_ops_fs__handle(kk_src_dream__cycle__oracle_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : oracle-ops<e,b>, ret : (res : a) -> e b, action : () -> <oracle-ops|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-generate-suggestion` constructor field of the `:oracle-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_oracle_ops_fs__fun_generate_suggestion(kk_src_dream__cycle__oracle_ops _this, kk_context_t* _ctx) { /* forall<e,a> (oracle-ops<e,a>) -> hnd/clause1<string,string,oracle-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_oracle_ops* _con_x1310 = kk_src_dream__cycle__as_Hnd_oracle_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1310->_fun_generate_suggestion;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `generate-suggestion` operation out of effect `:oracle-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_generate_suggestion_fs__select(kk_src_dream__cycle__oracle_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : oracle-ops<e,a>) -> hnd/clause1<string,string,oracle-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_oracle_ops* _con_x1311 = kk_src_dream__cycle__as_Hnd_oracle_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_generate_suggestion = _con_x1311->_fun_generate_suggestion;
    return kk_std_core_hnd__clause1_dup(_fun_generate_suggestion, _ctx);
  }
}
 
// Call the `fun generate-suggestion` operation of the effect `:oracle-ops`

static inline kk_string_t kk_src_dream__cycle_generate_suggestion(kk_string_t input_str, kk_context_t* _ctx) { /* (input-str : string) -> oracle-ops string */ 
  kk_std_core_hnd__ev ev_10265 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/oracle-ops>*/;
  kk_box_t _x_x1312;
  {
    struct kk_std_core_hnd_Ev* _con_x1313 = kk_std_core_hnd__as_Ev(ev_10265, _ctx);
    kk_box_t _box_x223 = _con_x1313->hnd;
    int32_t m = _con_x1313->marker;
    kk_src_dream__cycle__oracle_ops h = kk_src_dream__cycle__oracle_ops_unbox(_box_x223, KK_BORROWED, _ctx);
    kk_src_dream__cycle__oracle_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_oracle_ops* _con_x1314 = kk_src_dream__cycle__as_Hnd_oracle_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1314->_cfc;
      kk_std_core_hnd__clause1 _fun_generate_suggestion = _con_x1314->_fun_generate_suggestion;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1314->_fun_predict_next_session;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_generate_suggestion, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x227 = _fun_generate_suggestion.clause;
        _x_x1312 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x227, (_fun_unbox_x227, m, ev_10265, kk_string_box(input_str), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_string_unbox(_x_x1312);
}
 
// Automatically generated. Retrieves the `@fun-predict-next-session` constructor field of the `:oracle-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_oracle_ops_fs__fun_predict_next_session(kk_src_dream__cycle__oracle_ops _this, kk_context_t* _ctx) { /* forall<e,a> (oracle-ops<e,a>) -> hnd/clause1<list<string>,list<string>,oracle-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_oracle_ops* _con_x1315 = kk_src_dream__cycle__as_Hnd_oracle_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1315->_fun_predict_next_session;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `predict-next-session` operation out of effect `:oracle-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_predict_next_session_fs__select(kk_src_dream__cycle__oracle_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : oracle-ops<e,a>) -> hnd/clause1<list<string>,list<string>,oracle-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_oracle_ops* _con_x1316 = kk_src_dream__cycle__as_Hnd_oracle_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_predict_next_session = _con_x1316->_fun_predict_next_session;
    return kk_std_core_hnd__clause1_dup(_fun_predict_next_session, _ctx);
  }
}
 
// Call the `fun predict-next-session` operation of the effect `:oracle-ops`

static inline kk_std_core_types__list kk_src_dream__cycle_predict_next_session(kk_std_core_types__list history, kk_context_t* _ctx) { /* (history : list<string>) -> oracle-ops list<string> */ 
  kk_std_core_hnd__ev ev_10268 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/oracle-ops>*/;
  kk_box_t _x_x1317;
  {
    struct kk_std_core_hnd_Ev* _con_x1318 = kk_std_core_hnd__as_Ev(ev_10268, _ctx);
    kk_box_t _box_x231 = _con_x1318->hnd;
    int32_t m = _con_x1318->marker;
    kk_src_dream__cycle__oracle_ops h = kk_src_dream__cycle__oracle_ops_unbox(_box_x231, KK_BORROWED, _ctx);
    kk_src_dream__cycle__oracle_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_oracle_ops* _con_x1319 = kk_src_dream__cycle__as_Hnd_oracle_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1319->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1319->_fun_generate_suggestion;
      kk_std_core_hnd__clause1 _fun_predict_next_session = _con_x1319->_fun_predict_next_session;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_predict_next_session, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x235 = _fun_predict_next_session.clause;
        _x_x1317 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x235, (_fun_unbox_x235, m, ev_10268, kk_std_core_types__list_box(history, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x1317, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:decay-ops` type.

static inline kk_integer_t kk_src_dream__cycle_decay_ops_fs__cfc(kk_src_dream__cycle__decay_ops _this, kk_context_t* _ctx) { /* forall<e,a> (decay-ops<e,a>) -> int */ 
  {
    struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1320 = kk_src_dream__cycle__as_Hnd_decay_ops(_this, _ctx);
    kk_integer_t _x = _con_x1320->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_src_dream__cycle_decay_ops_fs__tag;

kk_box_t kk_src_dream__cycle_decay_ops_fs__handle(kk_src_dream__cycle__decay_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : decay-ops<e,b>, ret : (res : a) -> e b, action : () -> <decay-ops|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-sweep-old-memories` constructor field of the `:decay-ops` type.

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_decay_ops_fs__fun_sweep_old_memories(kk_src_dream__cycle__decay_ops _this, kk_context_t* _ctx) { /* forall<e,a> (decay-ops<e,a>) -> hnd/clause2<int,float64,int,decay-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1324 = kk_src_dream__cycle__as_Hnd_decay_ops(_this, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x1324->_fun_sweep_old_memories;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `sweep-old-memories` operation out of effect `:decay-ops`

static inline kk_std_core_hnd__clause2 kk_src_dream__cycle_sweep_old_memories_fs__select(kk_src_dream__cycle__decay_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : decay-ops<e,a>) -> hnd/clause2<int,float64,int,decay-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1325 = kk_src_dream__cycle__as_Hnd_decay_ops(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_sweep_old_memories = _con_x1325->_fun_sweep_old_memories;
    return kk_std_core_hnd__clause2_dup(_fun_sweep_old_memories, _ctx);
  }
}
 
// Call the `fun sweep-old-memories` operation of the effect `:decay-ops`

static inline kk_integer_t kk_src_dream__cycle_sweep_old_memories(kk_integer_t age_threshold, double importance_floor, kk_context_t* _ctx) { /* (age-threshold : int, importance-floor : float64) -> decay-ops int */ 
  kk_std_core_hnd__ev evx_10272 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/decay-ops>*/;
  kk_box_t _x_x1326;
  {
    struct kk_std_core_hnd_Ev* _con_x1327 = kk_std_core_hnd__as_Ev(evx_10272, _ctx);
    kk_box_t _box_x247 = _con_x1327->hnd;
    int32_t m = _con_x1327->marker;
    kk_src_dream__cycle__decay_ops h = kk_src_dream__cycle__decay_ops_unbox(_box_x247, KK_BORROWED, _ctx);
    kk_src_dream__cycle__decay_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1328 = kk_src_dream__cycle__as_Hnd_decay_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1328->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1328->_fun_archive_memory;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1328->_fun_get_decay_candidates;
      kk_std_core_hnd__clause2 _fun_sweep_old_memories = _con_x1328->_fun_sweep_old_memories;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_sweep_old_memories, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x252 = _fun_sweep_old_memories.clause;
        _x_x1326 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x252, (_fun_unbox_x252, m, evx_10272, kk_integer_box(age_threshold, _ctx), kk_double_box(importance_floor, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_integer_unbox(_x_x1326, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-archive-memory` constructor field of the `:decay-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_decay_ops_fs__fun_archive_memory(kk_src_dream__cycle__decay_ops _this, kk_context_t* _ctx) { /* forall<e,a> (decay-ops<e,a>) -> hnd/clause1<string,bool,decay-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1329 = kk_src_dream__cycle__as_Hnd_decay_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1329->_fun_archive_memory;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `archive-memory` operation out of effect `:decay-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_archive_memory_fs__select(kk_src_dream__cycle__decay_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : decay-ops<e,a>) -> hnd/clause1<string,bool,decay-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1330 = kk_src_dream__cycle__as_Hnd_decay_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_archive_memory = _con_x1330->_fun_archive_memory;
    return kk_std_core_hnd__clause1_dup(_fun_archive_memory, _ctx);
  }
}
 
// Call the `fun archive-memory` operation of the effect `:decay-ops`

static inline bool kk_src_dream__cycle_archive_memory(kk_string_t id, kk_context_t* _ctx) { /* (id : string) -> decay-ops bool */ 
  kk_std_core_hnd__ev ev_10276 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/decay-ops>*/;
  kk_box_t _x_x1331;
  {
    struct kk_std_core_hnd_Ev* _con_x1332 = kk_std_core_hnd__as_Ev(ev_10276, _ctx);
    kk_box_t _box_x257 = _con_x1332->hnd;
    int32_t m = _con_x1332->marker;
    kk_src_dream__cycle__decay_ops h = kk_src_dream__cycle__decay_ops_unbox(_box_x257, KK_BORROWED, _ctx);
    kk_src_dream__cycle__decay_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1333 = kk_src_dream__cycle__as_Hnd_decay_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1333->_cfc;
      kk_std_core_hnd__clause1 _fun_archive_memory = _con_x1333->_fun_archive_memory;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1333->_fun_get_decay_candidates;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1333->_fun_sweep_old_memories;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_archive_memory, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x261 = _fun_archive_memory.clause;
        _x_x1331 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x261, (_fun_unbox_x261, m, ev_10276, kk_string_box(id), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_bool_unbox(_x_x1331);
}
 
// Automatically generated. Retrieves the `@fun-get-decay-candidates` constructor field of the `:decay-ops` type.

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_decay_ops_fs__fun_get_decay_candidates(kk_src_dream__cycle__decay_ops _this, kk_context_t* _ctx) { /* forall<e,a> (decay-ops<e,a>) -> hnd/clause1<int,list<string>,decay-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1334 = kk_src_dream__cycle__as_Hnd_decay_ops(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x1334->_fun_get_decay_candidates;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `get-decay-candidates` operation out of effect `:decay-ops`

static inline kk_std_core_hnd__clause1 kk_src_dream__cycle_get_decay_candidates_fs__select(kk_src_dream__cycle__decay_ops hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : decay-ops<e,a>) -> hnd/clause1<int,list<string>,decay-ops,e,a> */ 
  {
    struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1335 = kk_src_dream__cycle__as_Hnd_decay_ops(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_get_decay_candidates = _con_x1335->_fun_get_decay_candidates;
    return kk_std_core_hnd__clause1_dup(_fun_get_decay_candidates, _ctx);
  }
}
 
// Call the `fun get-decay-candidates` operation of the effect `:decay-ops`

static inline kk_std_core_types__list kk_src_dream__cycle_get_decay_candidates(kk_integer_t limit, kk_context_t* _ctx) { /* (limit : int) -> decay-ops list<string> */ 
  kk_std_core_hnd__ev ev_10279 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/decay-ops>*/;
  kk_box_t _x_x1336;
  {
    struct kk_std_core_hnd_Ev* _con_x1337 = kk_std_core_hnd__as_Ev(ev_10279, _ctx);
    kk_box_t _box_x265 = _con_x1337->hnd;
    int32_t m = _con_x1337->marker;
    kk_src_dream__cycle__decay_ops h = kk_src_dream__cycle__decay_ops_unbox(_box_x265, KK_BORROWED, _ctx);
    kk_src_dream__cycle__decay_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1338 = kk_src_dream__cycle__as_Hnd_decay_ops(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1338->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x1338->_fun_archive_memory;
      kk_std_core_hnd__clause1 _fun_get_decay_candidates = _con_x1338->_fun_get_decay_candidates;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1338->_fun_sweep_old_memories;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_get_decay_candidates, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x269 = _fun_get_decay_candidates.clause;
        _x_x1336 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x269, (_fun_unbox_x269, m, ev_10279, kk_integer_box(limit, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x1336, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `tagged` constructor field of the `:triage-result` type.

static inline kk_integer_t kk_src_dream__cycle_triage_result_fs_tagged(kk_src_dream__cycle__triage_result _this, kk_context_t* _ctx) { /* (triage-result) -> int */ 
  {
    struct kk_src_dream__cycle_Triage_result* _con_x1339 = kk_src_dream__cycle__as_Triage_result(_this, _ctx);
    kk_integer_t _x = _con_x1339->tagged;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `drift-corrected` constructor field of the `:triage-result` type.

static inline kk_integer_t kk_src_dream__cycle_triage_result_fs_drift_corrected(kk_src_dream__cycle__triage_result _this, kk_context_t* _ctx) { /* (triage-result) -> int */ 
  {
    struct kk_src_dream__cycle_Triage_result* _con_x1340 = kk_src_dream__cycle__as_Triage_result(_this, _ctx);
    kk_integer_t _x = _con_x1340->drift_corrected;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_dream__cycle__triage_result kk_src_dream__cycle_triage_result_fs__copy(kk_src_dream__cycle__triage_result _this, kk_std_core_types__optional tagged, kk_std_core_types__optional drift_corrected, kk_context_t* _ctx); /* (triage-result, tagged : ? int, drift-corrected : ? int) -> triage-result */ 
 
// Automatically generated. Retrieves the `constellations` constructor field of the `:consolidation-result` type.

static inline kk_integer_t kk_src_dream__cycle_consolidation_result_fs_constellations(kk_src_dream__cycle__consolidation_result _this, kk_context_t* _ctx) { /* (consolidation-result) -> int */ 
  {
    struct kk_src_dream__cycle_Consolidation_result* _con_x1345 = kk_src_dream__cycle__as_Consolidation_result(_this, _ctx);
    kk_integer_t _x = _con_x1345->constellations;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `memberships` constructor field of the `:consolidation-result` type.

static inline kk_integer_t kk_src_dream__cycle_consolidation_result_fs_memberships(kk_src_dream__cycle__consolidation_result _this, kk_context_t* _ctx) { /* (consolidation-result) -> int */ 
  {
    struct kk_src_dream__cycle_Consolidation_result* _con_x1346 = kk_src_dream__cycle__as_Consolidation_result(_this, _ctx);
    kk_integer_t _x = _con_x1346->memberships;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_dream__cycle__consolidation_result kk_src_dream__cycle_consolidation_result_fs__copy(kk_src_dream__cycle__consolidation_result _this, kk_std_core_types__optional constellations, kk_std_core_types__optional memberships, kk_context_t* _ctx); /* (consolidation-result, constellations : ? int, memberships : ? int) -> consolidation-result */ 
 
// Automatically generated. Retrieves the `bridges` constructor field of the `:serendipity-result` type.

static inline kk_integer_t kk_src_dream__cycle_serendipity_result_fs_bridges(kk_src_dream__cycle__serendipity_result _this, kk_context_t* _ctx) { /* (serendipity-result) -> int */ 
  {
    struct kk_src_dream__cycle_Serendipity_result* _con_x1351 = kk_src_dream__cycle__as_Serendipity_result(_this, _ctx);
    kk_integer_t _x = _con_x1351->bridges;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `insights` constructor field of the `:serendipity-result` type.

static inline kk_integer_t kk_src_dream__cycle_serendipity_result_fs_insights(kk_src_dream__cycle__serendipity_result _this, kk_context_t* _ctx) { /* (serendipity-result) -> int */ 
  {
    struct kk_src_dream__cycle_Serendipity_result* _con_x1352 = kk_src_dream__cycle__as_Serendipity_result(_this, _ctx);
    kk_integer_t _x = _con_x1352->insights;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `connections` constructor field of the `:serendipity-result` type.

static inline kk_integer_t kk_src_dream__cycle_serendipity_result_fs_connections(kk_src_dream__cycle__serendipity_result _this, kk_context_t* _ctx) { /* (serendipity-result) -> int */ 
  {
    struct kk_src_dream__cycle_Serendipity_result* _con_x1353 = kk_src_dream__cycle__as_Serendipity_result(_this, _ctx);
    kk_integer_t _x = _con_x1353->connections;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_dream__cycle__serendipity_result kk_src_dream__cycle_serendipity_result_fs__copy(kk_src_dream__cycle__serendipity_result _this, kk_std_core_types__optional bridges, kk_std_core_types__optional insights, kk_std_core_types__optional connections, kk_context_t* _ctx); /* (serendipity-result, bridges : ? int, insights : ? int, connections : ? int) -> serendipity-result */ 
 
// Automatically generated. Retrieves the `communities` constructor field of the `:governance-result` type.

static inline kk_integer_t kk_src_dream__cycle_governance_result_fs_communities(kk_src_dream__cycle__governance_result _this, kk_context_t* _ctx) { /* (governance-result) -> int */ 
  {
    struct kk_src_dream__cycle_Governance_result* _con_x1360 = kk_src_dream__cycle__as_Governance_result(_this, _ctx);
    kk_integer_t _x = _con_x1360->communities;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `echo-chambers` constructor field of the `:governance-result` type.

static inline kk_integer_t kk_src_dream__cycle_governance_result_fs_echo_chambers(kk_src_dream__cycle__governance_result _this, kk_context_t* _ctx) { /* (governance-result) -> int */ 
  {
    struct kk_src_dream__cycle_Governance_result* _con_x1361 = kk_src_dream__cycle__as_Governance_result(_this, _ctx);
    kk_integer_t _x = _con_x1361->echo_chambers;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `health` constructor field of the `:governance-result` type.

static inline double kk_src_dream__cycle_governance_result_fs_health(kk_src_dream__cycle__governance_result _this, kk_context_t* _ctx) { /* (governance-result) -> float64 */ 
  {
    struct kk_src_dream__cycle_Governance_result* _con_x1362 = kk_src_dream__cycle__as_Governance_result(_this, _ctx);
    double _x = _con_x1362->health;
    return _x;
  }
}

kk_src_dream__cycle__governance_result kk_src_dream__cycle_governance_result_fs__copy(kk_src_dream__cycle__governance_result _this, kk_std_core_types__optional communities, kk_std_core_types__optional echo_chambers, kk_std_core_types__optional health, kk_context_t* _ctx); /* (governance-result, communities : ? int, echo-chambers : ? int, health : ? float64) -> governance-result */ 
 
// Automatically generated. Retrieves the `clusters` constructor field of the `:narrative-result` type.

static inline kk_integer_t kk_src_dream__cycle_narrative_result_fs_clusters(kk_src_dream__cycle__narrative_result _this, kk_context_t* _ctx) { /* (narrative-result) -> int */ 
  {
    struct kk_src_dream__cycle_Narrative_result* _con_x1369 = kk_src_dream__cycle__as_Narrative_result(_this, _ctx);
    kk_integer_t _x = _con_x1369->clusters;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `narratives` constructor field of the `:narrative-result` type.

static inline kk_integer_t kk_src_dream__cycle_narrative_result_fs_narratives(kk_src_dream__cycle__narrative_result _this, kk_context_t* _ctx) { /* (narrative-result) -> int */ 
  {
    struct kk_src_dream__cycle_Narrative_result* _con_x1370 = kk_src_dream__cycle__as_Narrative_result(_this, _ctx);
    kk_integer_t _x = _con_x1370->narratives;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `compressed` constructor field of the `:narrative-result` type.

static inline kk_integer_t kk_src_dream__cycle_narrative_result_fs_compressed(kk_src_dream__cycle__narrative_result _this, kk_context_t* _ctx) { /* (narrative-result) -> int */ 
  {
    struct kk_src_dream__cycle_Narrative_result* _con_x1371 = kk_src_dream__cycle__as_Narrative_result(_this, _ctx);
    kk_integer_t _x = _con_x1371->compressed;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_dream__cycle__narrative_result kk_src_dream__cycle_narrative_result_fs__copy(kk_src_dream__cycle__narrative_result _this, kk_std_core_types__optional clusters, kk_std_core_types__optional narratives, kk_std_core_types__optional compressed, kk_context_t* _ctx); /* (narrative-result, clusters : ? int, narratives : ? int, compressed : ? int) -> narrative-result */ 
 
// Automatically generated. Retrieves the `emergence-insights` constructor field of the `:kaizen-result` type.

static inline kk_integer_t kk_src_dream__cycle_kaizen_result_fs_emergence_insights(kk_src_dream__cycle__kaizen_result _this, kk_context_t* _ctx) { /* (kaizen-result) -> int */ 
  {
    struct kk_src_dream__cycle_Kaizen_result* _con_x1378 = kk_src_dream__cycle__as_Kaizen_result(_this, _ctx);
    kk_integer_t _x = _con_x1378->emergence_insights;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `persisted` constructor field of the `:kaizen-result` type.

static inline kk_integer_t kk_src_dream__cycle_kaizen_result_fs_persisted(kk_src_dream__cycle__kaizen_result _this, kk_context_t* _ctx) { /* (kaizen-result) -> int */ 
  {
    struct kk_src_dream__cycle_Kaizen_result* _con_x1379 = kk_src_dream__cycle__as_Kaizen_result(_this, _ctx);
    kk_integer_t _x = _con_x1379->persisted;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_dream__cycle__kaizen_result kk_src_dream__cycle_kaizen_result_fs__copy(kk_src_dream__cycle__kaizen_result _this, kk_std_core_types__optional emergence_insights, kk_std_core_types__optional persisted, kk_context_t* _ctx); /* (kaizen-result, emergence-insights : ? int, persisted : ? int) -> kaizen-result */ 
 
// Automatically generated. Retrieves the `suggestions` constructor field of the `:oracle-result` type.

static inline kk_std_core_types__list kk_src_dream__cycle_oracle_result_fs_suggestions(kk_src_dream__cycle__oracle_result _this, kk_context_t* _ctx) { /* (oracle-result) -> list<string> */ 
  {
    kk_std_core_types__list _x = _this.suggestions;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}

kk_src_dream__cycle__oracle_result kk_src_dream__cycle_oracle_result_fs__copy(kk_src_dream__cycle__oracle_result _this, kk_std_core_types__optional suggestions, kk_context_t* _ctx); /* (oracle-result, suggestions : ? (list<string>)) -> oracle-result */ 
 
// Automatically generated. Retrieves the `swept` constructor field of the `:decay-result` type.

static inline kk_integer_t kk_src_dream__cycle_decay_result_fs_swept(kk_src_dream__cycle__decay_result _this, kk_context_t* _ctx) { /* (decay-result) -> int */ 
  {
    kk_integer_t _x = _this.swept;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_dream__cycle__decay_result kk_src_dream__cycle_decay_result_fs__copy(kk_src_dream__cycle__decay_result _this, kk_std_core_types__optional swept, kk_context_t* _ctx); /* (decay-result, swept : ? int) -> decay-result */ 
 
// Automatically generated. Retrieves the `triage` constructor field of the `:dream-summary` type.

static inline kk_src_dream__cycle__triage_result kk_src_dream__cycle_dream_summary_fs_triage(kk_src_dream__cycle__dream_summary _this, kk_context_t* _ctx) { /* (dream-summary) -> triage-result */ 
  {
    struct kk_src_dream__cycle_Dream_summary* _con_x1386 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
    kk_src_dream__cycle__triage_result _x = _con_x1386->triage;
    kk_src_dream__cycle__consolidation_result _pat_2 = _con_x1386->consolidation;
    kk_src_dream__cycle__serendipity_result _pat_5 = _con_x1386->serendipity;
    kk_src_dream__cycle__governance_result _pat_9 = _con_x1386->governance;
    kk_src_dream__cycle__narrative_result _pat_13 = _con_x1386->narrative;
    kk_src_dream__cycle__kaizen_result _pat_17 = _con_x1386->kaizen;
    kk_src_dream__cycle__oracle_result _pat_20 = _con_x1386->oracle;
    kk_src_dream__cycle__decay_result _pat_22 = _con_x1386->decay;
    struct kk_src_dream__cycle_Triage_result* _con_x1387 = kk_src_dream__cycle__as_Triage_result(_x, _ctx);
    struct kk_src_dream__cycle_Consolidation_result* _con_x1388 = kk_src_dream__cycle__as_Consolidation_result(_pat_2, _ctx);
    struct kk_src_dream__cycle_Serendipity_result* _con_x1389 = kk_src_dream__cycle__as_Serendipity_result(_pat_5, _ctx);
    struct kk_src_dream__cycle_Governance_result* _con_x1390 = kk_src_dream__cycle__as_Governance_result(_pat_9, _ctx);
    struct kk_src_dream__cycle_Narrative_result* _con_x1391 = kk_src_dream__cycle__as_Narrative_result(_pat_13, _ctx);
    struct kk_src_dream__cycle_Kaizen_result* _con_x1392 = kk_src_dream__cycle__as_Kaizen_result(_pat_17, _ctx);
    return kk_src_dream__cycle__triage_result_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `consolidation` constructor field of the `:dream-summary` type.

static inline kk_src_dream__cycle__consolidation_result kk_src_dream__cycle_dream_summary_fs_consolidation(kk_src_dream__cycle__dream_summary _this, kk_context_t* _ctx) { /* (dream-summary) -> consolidation-result */ 
  {
    struct kk_src_dream__cycle_Dream_summary* _con_x1393 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
    kk_src_dream__cycle__triage_result _pat_0 = _con_x1393->triage;
    kk_src_dream__cycle__consolidation_result _x = _con_x1393->consolidation;
    kk_src_dream__cycle__serendipity_result _pat_5 = _con_x1393->serendipity;
    kk_src_dream__cycle__governance_result _pat_9 = _con_x1393->governance;
    kk_src_dream__cycle__narrative_result _pat_13 = _con_x1393->narrative;
    kk_src_dream__cycle__kaizen_result _pat_17 = _con_x1393->kaizen;
    kk_src_dream__cycle__oracle_result _pat_20 = _con_x1393->oracle;
    kk_src_dream__cycle__decay_result _pat_22 = _con_x1393->decay;
    struct kk_src_dream__cycle_Triage_result* _con_x1394 = kk_src_dream__cycle__as_Triage_result(_pat_0, _ctx);
    struct kk_src_dream__cycle_Consolidation_result* _con_x1395 = kk_src_dream__cycle__as_Consolidation_result(_x, _ctx);
    struct kk_src_dream__cycle_Serendipity_result* _con_x1396 = kk_src_dream__cycle__as_Serendipity_result(_pat_5, _ctx);
    struct kk_src_dream__cycle_Governance_result* _con_x1397 = kk_src_dream__cycle__as_Governance_result(_pat_9, _ctx);
    struct kk_src_dream__cycle_Narrative_result* _con_x1398 = kk_src_dream__cycle__as_Narrative_result(_pat_13, _ctx);
    struct kk_src_dream__cycle_Kaizen_result* _con_x1399 = kk_src_dream__cycle__as_Kaizen_result(_pat_17, _ctx);
    return kk_src_dream__cycle__consolidation_result_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `serendipity` constructor field of the `:dream-summary` type.

static inline kk_src_dream__cycle__serendipity_result kk_src_dream__cycle_dream_summary_fs_serendipity(kk_src_dream__cycle__dream_summary _this, kk_context_t* _ctx) { /* (dream-summary) -> serendipity-result */ 
  {
    struct kk_src_dream__cycle_Dream_summary* _con_x1400 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
    kk_src_dream__cycle__triage_result _pat_0 = _con_x1400->triage;
    kk_src_dream__cycle__consolidation_result _pat_3 = _con_x1400->consolidation;
    kk_src_dream__cycle__serendipity_result _x = _con_x1400->serendipity;
    kk_src_dream__cycle__governance_result _pat_9 = _con_x1400->governance;
    kk_src_dream__cycle__narrative_result _pat_13 = _con_x1400->narrative;
    kk_src_dream__cycle__kaizen_result _pat_17 = _con_x1400->kaizen;
    kk_src_dream__cycle__oracle_result _pat_20 = _con_x1400->oracle;
    kk_src_dream__cycle__decay_result _pat_22 = _con_x1400->decay;
    struct kk_src_dream__cycle_Triage_result* _con_x1401 = kk_src_dream__cycle__as_Triage_result(_pat_0, _ctx);
    struct kk_src_dream__cycle_Consolidation_result* _con_x1402 = kk_src_dream__cycle__as_Consolidation_result(_pat_3, _ctx);
    struct kk_src_dream__cycle_Serendipity_result* _con_x1403 = kk_src_dream__cycle__as_Serendipity_result(_x, _ctx);
    struct kk_src_dream__cycle_Governance_result* _con_x1404 = kk_src_dream__cycle__as_Governance_result(_pat_9, _ctx);
    struct kk_src_dream__cycle_Narrative_result* _con_x1405 = kk_src_dream__cycle__as_Narrative_result(_pat_13, _ctx);
    struct kk_src_dream__cycle_Kaizen_result* _con_x1406 = kk_src_dream__cycle__as_Kaizen_result(_pat_17, _ctx);
    return kk_src_dream__cycle__serendipity_result_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `governance` constructor field of the `:dream-summary` type.

static inline kk_src_dream__cycle__governance_result kk_src_dream__cycle_dream_summary_fs_governance(kk_src_dream__cycle__dream_summary _this, kk_context_t* _ctx) { /* (dream-summary) -> governance-result */ 
  {
    struct kk_src_dream__cycle_Dream_summary* _con_x1407 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
    kk_src_dream__cycle__triage_result _pat_0 = _con_x1407->triage;
    kk_src_dream__cycle__consolidation_result _pat_3 = _con_x1407->consolidation;
    kk_src_dream__cycle__serendipity_result _pat_6 = _con_x1407->serendipity;
    kk_src_dream__cycle__governance_result _x = _con_x1407->governance;
    kk_src_dream__cycle__narrative_result _pat_13 = _con_x1407->narrative;
    kk_src_dream__cycle__kaizen_result _pat_17 = _con_x1407->kaizen;
    kk_src_dream__cycle__oracle_result _pat_20 = _con_x1407->oracle;
    kk_src_dream__cycle__decay_result _pat_22 = _con_x1407->decay;
    struct kk_src_dream__cycle_Triage_result* _con_x1408 = kk_src_dream__cycle__as_Triage_result(_pat_0, _ctx);
    struct kk_src_dream__cycle_Consolidation_result* _con_x1409 = kk_src_dream__cycle__as_Consolidation_result(_pat_3, _ctx);
    struct kk_src_dream__cycle_Serendipity_result* _con_x1410 = kk_src_dream__cycle__as_Serendipity_result(_pat_6, _ctx);
    struct kk_src_dream__cycle_Governance_result* _con_x1411 = kk_src_dream__cycle__as_Governance_result(_x, _ctx);
    struct kk_src_dream__cycle_Narrative_result* _con_x1412 = kk_src_dream__cycle__as_Narrative_result(_pat_13, _ctx);
    struct kk_src_dream__cycle_Kaizen_result* _con_x1413 = kk_src_dream__cycle__as_Kaizen_result(_pat_17, _ctx);
    return kk_src_dream__cycle__governance_result_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `narrative` constructor field of the `:dream-summary` type.

static inline kk_src_dream__cycle__narrative_result kk_src_dream__cycle_dream_summary_fs_narrative(kk_src_dream__cycle__dream_summary _this, kk_context_t* _ctx) { /* (dream-summary) -> narrative-result */ 
  {
    struct kk_src_dream__cycle_Dream_summary* _con_x1414 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
    kk_src_dream__cycle__triage_result _pat_0 = _con_x1414->triage;
    kk_src_dream__cycle__consolidation_result _pat_3 = _con_x1414->consolidation;
    kk_src_dream__cycle__serendipity_result _pat_6 = _con_x1414->serendipity;
    kk_src_dream__cycle__governance_result _pat_10 = _con_x1414->governance;
    kk_src_dream__cycle__narrative_result _x = _con_x1414->narrative;
    kk_src_dream__cycle__kaizen_result _pat_17 = _con_x1414->kaizen;
    kk_src_dream__cycle__oracle_result _pat_20 = _con_x1414->oracle;
    kk_src_dream__cycle__decay_result _pat_22 = _con_x1414->decay;
    struct kk_src_dream__cycle_Triage_result* _con_x1415 = kk_src_dream__cycle__as_Triage_result(_pat_0, _ctx);
    struct kk_src_dream__cycle_Consolidation_result* _con_x1416 = kk_src_dream__cycle__as_Consolidation_result(_pat_3, _ctx);
    struct kk_src_dream__cycle_Serendipity_result* _con_x1417 = kk_src_dream__cycle__as_Serendipity_result(_pat_6, _ctx);
    struct kk_src_dream__cycle_Governance_result* _con_x1418 = kk_src_dream__cycle__as_Governance_result(_pat_10, _ctx);
    struct kk_src_dream__cycle_Narrative_result* _con_x1419 = kk_src_dream__cycle__as_Narrative_result(_x, _ctx);
    struct kk_src_dream__cycle_Kaizen_result* _con_x1420 = kk_src_dream__cycle__as_Kaizen_result(_pat_17, _ctx);
    return kk_src_dream__cycle__narrative_result_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `kaizen` constructor field of the `:dream-summary` type.

static inline kk_src_dream__cycle__kaizen_result kk_src_dream__cycle_dream_summary_fs_kaizen(kk_src_dream__cycle__dream_summary _this, kk_context_t* _ctx) { /* (dream-summary) -> kaizen-result */ 
  {
    struct kk_src_dream__cycle_Dream_summary* _con_x1421 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
    kk_src_dream__cycle__triage_result _pat_0 = _con_x1421->triage;
    kk_src_dream__cycle__consolidation_result _pat_3 = _con_x1421->consolidation;
    kk_src_dream__cycle__serendipity_result _pat_6 = _con_x1421->serendipity;
    kk_src_dream__cycle__governance_result _pat_10 = _con_x1421->governance;
    kk_src_dream__cycle__narrative_result _pat_14 = _con_x1421->narrative;
    kk_src_dream__cycle__kaizen_result _x = _con_x1421->kaizen;
    kk_src_dream__cycle__oracle_result _pat_20 = _con_x1421->oracle;
    kk_src_dream__cycle__decay_result _pat_22 = _con_x1421->decay;
    struct kk_src_dream__cycle_Triage_result* _con_x1422 = kk_src_dream__cycle__as_Triage_result(_pat_0, _ctx);
    struct kk_src_dream__cycle_Consolidation_result* _con_x1423 = kk_src_dream__cycle__as_Consolidation_result(_pat_3, _ctx);
    struct kk_src_dream__cycle_Serendipity_result* _con_x1424 = kk_src_dream__cycle__as_Serendipity_result(_pat_6, _ctx);
    struct kk_src_dream__cycle_Governance_result* _con_x1425 = kk_src_dream__cycle__as_Governance_result(_pat_10, _ctx);
    struct kk_src_dream__cycle_Narrative_result* _con_x1426 = kk_src_dream__cycle__as_Narrative_result(_pat_14, _ctx);
    struct kk_src_dream__cycle_Kaizen_result* _con_x1427 = kk_src_dream__cycle__as_Kaizen_result(_x, _ctx);
    return kk_src_dream__cycle__kaizen_result_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `oracle` constructor field of the `:dream-summary` type.

static inline kk_src_dream__cycle__oracle_result kk_src_dream__cycle_dream_summary_fs_oracle(kk_src_dream__cycle__dream_summary _this, kk_context_t* _ctx) { /* (dream-summary) -> oracle-result */ 
  {
    struct kk_src_dream__cycle_Dream_summary* _con_x1428 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
    kk_src_dream__cycle__triage_result _pat_0 = _con_x1428->triage;
    kk_src_dream__cycle__consolidation_result _pat_3 = _con_x1428->consolidation;
    kk_src_dream__cycle__serendipity_result _pat_6 = _con_x1428->serendipity;
    kk_src_dream__cycle__governance_result _pat_10 = _con_x1428->governance;
    kk_src_dream__cycle__narrative_result _pat_14 = _con_x1428->narrative;
    kk_src_dream__cycle__kaizen_result _pat_18 = _con_x1428->kaizen;
    kk_src_dream__cycle__oracle_result _x = _con_x1428->oracle;
    kk_src_dream__cycle__decay_result _pat_22 = _con_x1428->decay;
    struct kk_src_dream__cycle_Triage_result* _con_x1429 = kk_src_dream__cycle__as_Triage_result(_pat_0, _ctx);
    struct kk_src_dream__cycle_Consolidation_result* _con_x1430 = kk_src_dream__cycle__as_Consolidation_result(_pat_3, _ctx);
    struct kk_src_dream__cycle_Serendipity_result* _con_x1431 = kk_src_dream__cycle__as_Serendipity_result(_pat_6, _ctx);
    struct kk_src_dream__cycle_Governance_result* _con_x1432 = kk_src_dream__cycle__as_Governance_result(_pat_10, _ctx);
    struct kk_src_dream__cycle_Narrative_result* _con_x1433 = kk_src_dream__cycle__as_Narrative_result(_pat_14, _ctx);
    struct kk_src_dream__cycle_Kaizen_result* _con_x1434 = kk_src_dream__cycle__as_Kaizen_result(_pat_18, _ctx);
    return kk_src_dream__cycle__oracle_result_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `decay` constructor field of the `:dream-summary` type.

static inline kk_src_dream__cycle__decay_result kk_src_dream__cycle_dream_summary_fs_decay(kk_src_dream__cycle__dream_summary _this, kk_context_t* _ctx) { /* (dream-summary) -> decay-result */ 
  {
    struct kk_src_dream__cycle_Dream_summary* _con_x1435 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
    kk_src_dream__cycle__triage_result _pat_0 = _con_x1435->triage;
    kk_src_dream__cycle__consolidation_result _pat_3 = _con_x1435->consolidation;
    kk_src_dream__cycle__serendipity_result _pat_6 = _con_x1435->serendipity;
    kk_src_dream__cycle__governance_result _pat_10 = _con_x1435->governance;
    kk_src_dream__cycle__narrative_result _pat_14 = _con_x1435->narrative;
    kk_src_dream__cycle__kaizen_result _pat_18 = _con_x1435->kaizen;
    kk_src_dream__cycle__oracle_result _pat_21 = _con_x1435->oracle;
    kk_src_dream__cycle__decay_result _x = _con_x1435->decay;
    struct kk_src_dream__cycle_Triage_result* _con_x1436 = kk_src_dream__cycle__as_Triage_result(_pat_0, _ctx);
    struct kk_src_dream__cycle_Consolidation_result* _con_x1437 = kk_src_dream__cycle__as_Consolidation_result(_pat_3, _ctx);
    struct kk_src_dream__cycle_Serendipity_result* _con_x1438 = kk_src_dream__cycle__as_Serendipity_result(_pat_6, _ctx);
    struct kk_src_dream__cycle_Governance_result* _con_x1439 = kk_src_dream__cycle__as_Governance_result(_pat_10, _ctx);
    struct kk_src_dream__cycle_Narrative_result* _con_x1440 = kk_src_dream__cycle__as_Narrative_result(_pat_14, _ctx);
    struct kk_src_dream__cycle_Kaizen_result* _con_x1441 = kk_src_dream__cycle__as_Kaizen_result(_pat_18, _ctx);
    return kk_src_dream__cycle__decay_result_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `duration-ms` constructor field of the `:dream-summary` type.

static inline kk_integer_t kk_src_dream__cycle_dream_summary_fs_duration_ms(kk_src_dream__cycle__dream_summary _this, kk_context_t* _ctx) { /* (dream-summary) -> int */ 
  {
    struct kk_src_dream__cycle_Dream_summary* _con_x1442 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
    kk_src_dream__cycle__triage_result _pat_0 = _con_x1442->triage;
    kk_src_dream__cycle__consolidation_result _pat_3 = _con_x1442->consolidation;
    kk_src_dream__cycle__serendipity_result _pat_6 = _con_x1442->serendipity;
    kk_src_dream__cycle__governance_result _pat_10 = _con_x1442->governance;
    kk_src_dream__cycle__narrative_result _pat_14 = _con_x1442->narrative;
    kk_src_dream__cycle__kaizen_result _pat_18 = _con_x1442->kaizen;
    kk_src_dream__cycle__oracle_result _pat_21 = _con_x1442->oracle;
    kk_src_dream__cycle__decay_result _pat_23 = _con_x1442->decay;
    struct kk_src_dream__cycle_Triage_result* _con_x1443 = kk_src_dream__cycle__as_Triage_result(_pat_0, _ctx);
    struct kk_src_dream__cycle_Consolidation_result* _con_x1444 = kk_src_dream__cycle__as_Consolidation_result(_pat_3, _ctx);
    struct kk_src_dream__cycle_Serendipity_result* _con_x1445 = kk_src_dream__cycle__as_Serendipity_result(_pat_6, _ctx);
    struct kk_src_dream__cycle_Governance_result* _con_x1446 = kk_src_dream__cycle__as_Governance_result(_pat_10, _ctx);
    struct kk_src_dream__cycle_Narrative_result* _con_x1447 = kk_src_dream__cycle__as_Narrative_result(_pat_14, _ctx);
    struct kk_src_dream__cycle_Kaizen_result* _con_x1448 = kk_src_dream__cycle__as_Kaizen_result(_pat_18, _ctx);
    kk_integer_t _x = _con_x1442->duration_ms;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_src_dream__cycle__dream_summary kk_src_dream__cycle_dream_summary_fs__copy(kk_src_dream__cycle__dream_summary _this, kk_std_core_types__optional triage, kk_std_core_types__optional consolidation, kk_std_core_types__optional serendipity, kk_std_core_types__optional governance, kk_std_core_types__optional narrative, kk_std_core_types__optional kaizen, kk_std_core_types__optional oracle, kk_std_core_types__optional decay, kk_std_core_types__optional duration_ms, kk_context_t* _ctx); /* (dream-summary, triage : ? triage-result, consolidation : ? consolidation-result, serendipity : ? serendipity-result, governance : ? governance-result, narrative : ? narrative-result, kaizen : ? kaizen-result, oracle : ? oracle-result, decay : ? decay-result, duration-ms : ? int) -> dream-summary */ 
 
// monadic lift

static inline kk_integer_t kk_src_dream__cycle__mlift_phase_triage_10163(kk_integer_t acc, bool _y_x10076, kk_context_t* _ctx) { /* (acc : int, bool) -> memory-ops int */ 
  if (_y_x10076) {
    return kk_integer_add_small_const(acc, 1, _ctx);
  }
  {
    return acc;
  }
}
 
// monadic lift

static inline kk_src_dream__cycle__triage_result kk_src_dream__cycle__mlift_phase_triage_10164(kk_integer_t tagged, kk_context_t* _ctx) { /* (tagged : int) -> memory-ops triage-result */ 
  return kk_src_dream__cycle__new_Triage_result(kk_reuse_null, 0, tagged, kk_integer_from_small(2), _ctx);
}

kk_src_dream__cycle__triage_result kk_src_dream__cycle__mlift_phase_triage_10165(kk_std_core_types__list recent, kk_context_t* _ctx); /* (recent : list<string>) -> memory-ops triage-result */ 

kk_src_dream__cycle__triage_result kk_src_dream__cycle_phase_triage(kk_context_t* _ctx); /* () -> memory-ops triage-result */ 
 
// monadic lift

static inline kk_src_dream__cycle__consolidation_result kk_src_dream__cycle__mlift_phase_consolidation_10166(kk_std_core_types__list clusters, kk_context_t* _ctx) { /* (clusters : list<string>) -> constellation-ops consolidation-result */ 
  kk_integer_t _x_x1569;
  kk_std_core_types__list _x_x1570 = kk_std_core_types__list_dup(clusters, _ctx); /*list<string>*/
  _x_x1569 = kk_std_core_list__lift_length_5730(_x_x1570, kk_integer_from_small(0), _ctx); /*int*/
  kk_integer_t _x_x1571;
  kk_integer_t _x_x1572 = kk_std_core_list__lift_length_5730(clusters, kk_integer_from_small(0), _ctx); /*int*/
  _x_x1571 = kk_integer_mul(_x_x1572,(kk_integer_from_small(5)),kk_context()); /*int*/
  return kk_src_dream__cycle__new_Consolidation_result(kk_reuse_null, 0, _x_x1569, _x_x1571, _ctx);
}

kk_src_dream__cycle__consolidation_result kk_src_dream__cycle_phase_consolidation(kk_context_t* _ctx); /* () -> constellation-ops consolidation-result */ 
 
// monadic lift

static inline kk_src_dream__cycle__serendipity_result kk_src_dream__cycle__mlift_phase_serendipity_10167(kk_integer_t bridges, bool insights, kk_context_t* _ctx) { /* (bridges : int, insights : bool) -> <insight-ops,memory-ops> serendipity-result */ 
  kk_integer_t _x_x1584 = kk_integer_dup(bridges, _ctx); /*int*/
  kk_integer_t _x_x1585;
  if (insights) {
    _x_x1585 = kk_integer_from_small(3); /*int*/
  }
  else {
    _x_x1585 = kk_integer_from_small(0); /*int*/
  }
  kk_integer_t _x_x1586 = kk_integer_mul(bridges,(kk_integer_from_small(2)),kk_context()); /*int*/
  return kk_src_dream__cycle__new_Serendipity_result(kk_reuse_null, 0, _x_x1584, _x_x1585, _x_x1586, _ctx);
}
 
// monadic lift

static inline kk_integer_t kk_src_dream__cycle__mlift_phase_serendipity_10168(kk_integer_t acc2, kk_string_t b, kk_context_t* _ctx) { /* (acc2 : int, b : string) -> <insight-ops,memory-ops> int */ 
  bool _match_x1110;
  kk_string_t _x_x1587 = kk_string_empty(); /*string*/
  _match_x1110 = kk_string_is_neq(b,_x_x1587,kk_context()); /*bool*/
  if (_match_x1110) {
    return kk_integer_add_small_const(acc2, 1, _ctx);
  }
  {
    return acc2;
  }
}

kk_integer_t kk_src_dream__cycle__mlift_phase_serendipity_10169(kk_integer_t acc, kk_string_t cid, kk_std_core_types__list related, kk_context_t* _ctx); /* (acc : int, cid : string, related : list<string>) -> <memory-ops,insight-ops> int */ 

kk_src_dream__cycle__serendipity_result kk_src_dream__cycle__mlift_phase_serendipity_10170(kk_integer_t bridges, kk_context_t* _ctx); /* (bridges : int) -> <insight-ops,memory-ops> serendipity-result */ 

kk_src_dream__cycle__serendipity_result kk_src_dream__cycle__mlift_phase_serendipity_10171(kk_std_core_types__list candidates, kk_context_t* _ctx); /* (candidates : list<string>) -> <insight-ops,memory-ops> serendipity-result */ 

kk_src_dream__cycle__serendipity_result kk_src_dream__cycle_phase_serendipity(kk_context_t* _ctx); /* () -> <insight-ops,memory-ops> serendipity-result */ 
 
// monadic lift

static inline kk_src_dream__cycle__governance_result kk_src_dream__cycle__mlift_phase_governance_10172(kk_std_core_types__list chambers, double health, kk_context_t* _ctx) { /* (chambers : list<string>, health : float64) -> governance-ops governance-result */ 
  kk_integer_t _x_x1681 = kk_std_core_list__lift_length_5730(chambers, kk_integer_from_small(0), _ctx); /*int*/
  return kk_src_dream__cycle__new_Governance_result(kk_reuse_null, 0, kk_integer_from_small(181), _x_x1681, health, _ctx);
}

kk_src_dream__cycle__governance_result kk_src_dream__cycle__mlift_phase_governance_10173(kk_std_core_types__list chambers, kk_context_t* _ctx); /* (chambers : list<string>) -> governance-ops governance-result */ 

kk_src_dream__cycle__governance_result kk_src_dream__cycle_phase_governance(kk_context_t* _ctx); /* () -> governance-ops governance-result */ 
 
// monadic lift

static inline kk_integer_t kk_src_dream__cycle__mlift_phase_narrative_10174(kk_integer_t acc, kk_string_t _pat, kk_context_t* _ctx) { /* (acc : int, string) -> narrative-ops int */ 
  kk_string_drop(_pat, _ctx);
  return kk_integer_add_small_const(acc, 1, _ctx);
}
 
// monadic lift

static inline kk_src_dream__cycle__narrative_result kk_src_dream__cycle__mlift_phase_narrative_10175(kk_std_core_types__list clusters, kk_integer_t narratives, kk_context_t* _ctx) { /* (clusters : list<string>, narratives : int) -> narrative-ops narrative-result */ 
  kk_integer_t _x_x1705 = kk_std_core_list__lift_length_5730(clusters, kk_integer_from_small(0), _ctx); /*int*/
  kk_integer_t _x_x1706 = kk_integer_dup(narratives, _ctx); /*int*/
  kk_integer_t _x_x1707 = kk_integer_mul(narratives,(kk_integer_from_small(30)),kk_context()); /*int*/
  return kk_src_dream__cycle__new_Narrative_result(kk_reuse_null, 0, _x_x1705, _x_x1706, _x_x1707, _ctx);
}

kk_src_dream__cycle__narrative_result kk_src_dream__cycle__mlift_phase_narrative_10176(kk_std_core_types__list clusters, kk_context_t* _ctx); /* (clusters : list<string>) -> narrative-ops narrative-result */ 

kk_src_dream__cycle__narrative_result kk_src_dream__cycle__mlift_phase_narrative_10177(kk_std_core_types__list threads, kk_context_t* _ctx); /* (threads : list<string>) -> narrative-ops narrative-result */ 

kk_src_dream__cycle__narrative_result kk_src_dream__cycle_phase_narrative(kk_context_t* _ctx); /* () -> narrative-ops narrative-result */ 
 
// monadic lift

static inline kk_integer_t kk_src_dream__cycle__mlift_phase_kaizen_10178(kk_integer_t acc, bool _y_x10098, kk_context_t* _ctx) { /* (acc : int, bool) -> kaizen-ops int */ 
  if (_y_x10098) {
    return kk_integer_add_small_const(acc, 1, _ctx);
  }
  {
    return acc;
  }
}
 
// monadic lift

static inline kk_src_dream__cycle__kaizen_result kk_src_dream__cycle__mlift_phase_kaizen_10179(kk_std_core_types__list insights, kk_integer_t persisted, kk_context_t* _ctx) { /* (insights : list<string>, persisted : int) -> kaizen-ops kaizen-result */ 
  kk_integer_t _x_x1770 = kk_std_core_list__lift_length_5730(insights, kk_integer_from_small(0), _ctx); /*int*/
  return kk_src_dream__cycle__new_Kaizen_result(kk_reuse_null, 0, _x_x1770, persisted, _ctx);
}

kk_src_dream__cycle__kaizen_result kk_src_dream__cycle__mlift_phase_kaizen_10180(kk_std_core_types__list insights, kk_context_t* _ctx); /* (insights : list<string>) -> kaizen-ops kaizen-result */ 

kk_src_dream__cycle__kaizen_result kk_src_dream__cycle_phase_kaizen(kk_context_t* _ctx); /* () -> kaizen-ops kaizen-result */ 
 
// monadic lift

static inline kk_src_dream__cycle__oracle_result kk_src_dream__cycle__mlift_phase_oracle_10181(kk_std_core_types__list suggestions, kk_context_t* _ctx) { /* (suggestions : list<string>) -> oracle-ops oracle-result */ 
  return kk_src_dream__cycle__new_Oracle_result(suggestions, _ctx);
}

kk_src_dream__cycle__oracle_result kk_src_dream__cycle_phase_oracle(kk_context_t* _ctx); /* () -> oracle-ops oracle-result */ 
 
// monadic lift

static inline kk_src_dream__cycle__decay_result kk_src_dream__cycle__mlift_phase_decay_10182(kk_integer_t swept, kk_context_t* _ctx) { /* (swept : int) -> decay-ops decay-result */ 
  return kk_src_dream__cycle__new_Decay_result(swept, _ctx);
}

kk_src_dream__cycle__decay_result kk_src_dream__cycle_phase_decay(kk_context_t* _ctx); /* () -> decay-ops decay-result */ 
 
// monadic lift

static inline kk_src_dream__cycle__decay_result kk_src_dream__cycle__mlift_run_dream_cycle_10183(kk_integer_t swept, kk_context_t* _ctx) { /* (swept : int) -> decay-ops decay-result */ 
  return kk_src_dream__cycle__new_Decay_result(swept, _ctx);
}
 
// monadic lift

static inline kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10184(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_src_dream__cycle__narrative_result t5, kk_src_dream__cycle__kaizen_result t6, kk_src_dream__cycle__oracle_result t7, kk_src_dream__cycle__decay_result t8, kk_context_t* _ctx) { /* (t1 : triage-result, t2 : consolidation-result, t3 : serendipity-result, t4 : governance-result, t5 : narrative-result, t6 : kaizen-result, t7 : oracle-result, t8 : decay-result) -> <decay-ops,oracle-ops,kaizen-ops,narrative-ops,governance-ops,insight-ops,memory-ops,constellation-ops> dream-summary */ 
  return kk_src_dream__cycle__new_Dream_summary(kk_reuse_null, 0, t1, t2, t3, t4, t5, t6, t7, t8, kk_integer_from_small(0), _ctx);
}
 
// monadic lift

static inline kk_src_dream__cycle__oracle_result kk_src_dream__cycle__mlift_run_dream_cycle_10185(kk_std_core_types__list suggestions, kk_context_t* _ctx) { /* (suggestions : list<string>) -> oracle-ops oracle-result */ 
  return kk_src_dream__cycle__new_Oracle_result(suggestions, _ctx);
}

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10186(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_src_dream__cycle__narrative_result t5, kk_src_dream__cycle__kaizen_result t6, kk_src_dream__cycle__oracle_result t7, kk_context_t* _ctx); /* (t1 : triage-result, t2 : consolidation-result, t3 : serendipity-result, t4 : governance-result, t5 : narrative-result, t6 : kaizen-result, t7 : oracle-result) -> <oracle-ops,decay-ops,kaizen-ops,narrative-ops,governance-ops,insight-ops,memory-ops,constellation-ops> dream-summary */ 

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10187(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_src_dream__cycle__narrative_result t5, kk_src_dream__cycle__kaizen_result t6, kk_context_t* _ctx); /* (t1 : triage-result, t2 : consolidation-result, t3 : serendipity-result, t4 : governance-result, t5 : narrative-result, t6 : kaizen-result) -> <kaizen-ops,decay-ops,oracle-ops,narrative-ops,governance-ops,insight-ops,memory-ops,constellation-ops> dream-summary */ 

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10188(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_src_dream__cycle__narrative_result t5, kk_context_t* _ctx); /* (t1 : triage-result, t2 : consolidation-result, t3 : serendipity-result, t4 : governance-result, t5 : narrative-result) -> <narrative-ops,decay-ops,kaizen-ops,oracle-ops,governance-ops,insight-ops,memory-ops,constellation-ops> dream-summary */ 

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10189(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_context_t* _ctx); /* (t1 : triage-result, t2 : consolidation-result, t3 : serendipity-result, t4 : governance-result) -> <governance-ops,decay-ops,kaizen-ops,narrative-ops,oracle-ops,insight-ops,memory-ops,constellation-ops> dream-summary */ 

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10190(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_context_t* _ctx); /* (t1 : triage-result, t2 : consolidation-result, t3 : serendipity-result) -> <insight-ops,memory-ops,decay-ops,governance-ops,kaizen-ops,narrative-ops,oracle-ops,constellation-ops> dream-summary */ 

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10191(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_context_t* _ctx); /* (t1 : triage-result, t2 : consolidation-result) -> <constellation-ops,decay-ops,governance-ops,insight-ops,kaizen-ops,memory-ops,narrative-ops,oracle-ops> dream-summary */ 

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10192(kk_src_dream__cycle__triage_result t1, kk_context_t* _ctx); /* (t1 : triage-result) -> <memory-ops,constellation-ops,decay-ops,governance-ops,insight-ops,kaizen-ops,narrative-ops,oracle-ops> dream-summary */ 

kk_src_dream__cycle__dream_summary kk_src_dream__cycle_run_dream_cycle(kk_context_t* _ctx); /* () -> <constellation-ops,decay-ops,governance-ops,insight-ops,kaizen-ops,memory-ops,narrative-ops,oracle-ops> dream-summary */ 

kk_unit_t kk_src_dream__cycle_flush_stdout(kk_context_t* _ctx); /* () -> console/console () */ 

kk_string_t kk_src_dream__cycle_extract_op(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_unit_t kk_src_dream__cycle__mlift_server_loop_10193(kk_string_t _c_x10114, kk_integer_t _c_x10115, kk_integer_t _c_x10116, kk_integer_t _c_x10117, kk_context_t* _ctx); /* (string, int, int, int) -> () */ 

kk_unit_t kk_src_dream__cycle__mlift_server_loop_10194(kk_string_t _c_x10114_0, kk_integer_t _c_x10115_0, kk_integer_t insights, kk_string_t op, kk_integer_t _c_x10116_0, kk_context_t* _ctx); /* (string, int, insights : int, op : string, int) -> () */ 

kk_unit_t kk_src_dream__cycle__mlift_server_loop_10195(kk_string_t _c_x10114_1, kk_integer_t insights_0, kk_integer_t memories, kk_string_t op_0, kk_integer_t _c_x10115_1, kk_context_t* _ctx); /* (string, insights : int, memories : int, op : string, int) -> () */ 

kk_unit_t kk_src_dream__cycle__mlift_server_loop_10196(kk_integer_t cycles, kk_integer_t insights_1, kk_integer_t memories_0, kk_string_t op_1, kk_string_t _c_x10114_2, kk_context_t* _ctx); /* (cycles : int, insights : int, memories : int, op : string, string) -> () */ 

kk_unit_t kk_src_dream__cycle__mlift_server_loop_10197(kk_integer_t cycles_0, kk_integer_t insights_2, kk_integer_t memories_1, kk_string_t line, kk_context_t* _ctx); /* (cycles : int, insights : int, memories : int, line : string) -> <console/console,exn> () */ 

kk_unit_t kk_src_dream__cycle_server_loop(kk_integer_t cycles_1, kk_integer_t memories_2, kk_integer_t insights_3, kk_context_t* _ctx); /* (cycles : int, memories : int, insights : int) -> io () */ 

static inline kk_unit_t kk_src_dream__cycle_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_src_dream__cycle_server_loop(kk_integer_from_small(0), kk_integer_from_small(0), kk_integer_from_small(0), _ctx); return kk_Unit;
}

void kk_src_dream__cycle__init(kk_context_t* _ctx);


void kk_src_dream__cycle__done(kk_context_t* _ctx);

#endif // header
