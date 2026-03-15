// Koka generated module: src/dream_cycle, koka version: 3.2.2, platform: 64-bit
#include "src_dream__cycle.h"
 
// runtime tag for the effect `:memory-ops`

kk_std_core_hnd__htag kk_src_dream__cycle_memory_ops_fs__tag;
 
// handler for the effect `:memory-ops`

kk_box_t kk_src_dream__cycle_memory_ops_fs__handle(kk_src_dream__cycle__memory_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : memory-ops<e,b>, ret : (res : a) -> e b, action : () -> <memory-ops|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x1191 = kk_std_core_hnd__htag_dup(kk_src_dream__cycle_memory_ops_fs__tag, _ctx); /*hnd/htag<src/dream_cycle/memory-ops>*/
  return kk_std_core_hnd__hhandle(_x_x1191, kk_src_dream__cycle__memory_ops_box(hnd, _ctx), ret, action, _ctx);
}
 
// runtime tag for the effect `:constellation-ops`

kk_std_core_hnd__htag kk_src_dream__cycle_constellation_ops_fs__tag;
 
// handler for the effect `:constellation-ops`

kk_box_t kk_src_dream__cycle_constellation_ops_fs__handle(kk_src_dream__cycle__constellation_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : constellation-ops<e,b>, ret : (res : a) -> e b, action : () -> <constellation-ops|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x1215 = kk_std_core_hnd__htag_dup(kk_src_dream__cycle_constellation_ops_fs__tag, _ctx); /*hnd/htag<src/dream_cycle/constellation-ops>*/
  return kk_std_core_hnd__hhandle(_x_x1215, kk_src_dream__cycle__constellation_ops_box(hnd, _ctx), ret, action, _ctx);
}
 
// runtime tag for the effect `:insight-ops`

kk_std_core_hnd__htag kk_src_dream__cycle_insight_ops_fs__tag;
 
// handler for the effect `:insight-ops`

kk_box_t kk_src_dream__cycle_insight_ops_fs__handle(kk_src_dream__cycle__insight_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : insight-ops<e,b>, ret : (res : a) -> e b, action : () -> <insight-ops|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x1234 = kk_std_core_hnd__htag_dup(kk_src_dream__cycle_insight_ops_fs__tag, _ctx); /*hnd/htag<src/dream_cycle/insight-ops>*/
  return kk_std_core_hnd__hhandle(_x_x1234, kk_src_dream__cycle__insight_ops_box(hnd, _ctx), ret, action, _ctx);
}
extern kk_std_core_hnd__clause1 kk_src_dream__cycle_create_bridge_fun1238(kk_function_t _fself, kk_box_t _b_x97, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__insight_ops _brw_x1117 = kk_src_dream__cycle__insight_ops_unbox(_b_x97, KK_OWNED, _ctx); /*src/dream_cycle/insight-ops<1748,1749>*/;
  kk_std_core_hnd__clause1 _brw_x1118 = kk_src_dream__cycle_create_bridge_fs__select(_brw_x1117, _ctx); /*hnd/clause1<(string, string, float64),string,src/dream_cycle/insight-ops,1748,1749>*/;
  kk_datatype_ptr_dropn(_brw_x1117, (KK_I32(4)), _ctx);
  return _brw_x1118;
}
 
// runtime tag for the effect `:governance-ops`

kk_std_core_hnd__htag kk_src_dream__cycle_governance_ops_fs__tag;
 
// handler for the effect `:governance-ops`

kk_box_t kk_src_dream__cycle_governance_ops_fs__handle(kk_src_dream__cycle__governance_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : governance-ops<e,b>, ret : (res : a) -> e b, action : () -> <governance-ops|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x1252 = kk_std_core_hnd__htag_dup(kk_src_dream__cycle_governance_ops_fs__tag, _ctx); /*hnd/htag<src/dream_cycle/governance-ops>*/
  return kk_std_core_hnd__hhandle(_x_x1252, kk_src_dream__cycle__governance_ops_box(hnd, _ctx), ret, action, _ctx);
}
 
// runtime tag for the effect `:narrative-ops`

kk_std_core_hnd__htag kk_src_dream__cycle_narrative_ops_fs__tag;
 
// handler for the effect `:narrative-ops`

kk_box_t kk_src_dream__cycle_narrative_ops_fs__handle(kk_src_dream__cycle__narrative_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : narrative-ops<e,b>, ret : (res : a) -> e b, action : () -> <narrative-ops|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x1271 = kk_std_core_hnd__htag_dup(kk_src_dream__cycle_narrative_ops_fs__tag, _ctx); /*hnd/htag<src/dream_cycle/narrative-ops>*/
  return kk_std_core_hnd__hhandle(_x_x1271, kk_src_dream__cycle__narrative_ops_box(hnd, _ctx), ret, action, _ctx);
}
 
// runtime tag for the effect `:kaizen-ops`

kk_std_core_hnd__htag kk_src_dream__cycle_kaizen_ops_fs__tag;
 
// handler for the effect `:kaizen-ops`

kk_box_t kk_src_dream__cycle_kaizen_ops_fs__handle(kk_src_dream__cycle__kaizen_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : kaizen-ops<e,b>, ret : (res : a) -> e b, action : () -> <kaizen-ops|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x1290 = kk_std_core_hnd__htag_dup(kk_src_dream__cycle_kaizen_ops_fs__tag, _ctx); /*hnd/htag<src/dream_cycle/kaizen-ops>*/
  return kk_std_core_hnd__hhandle(_x_x1290, kk_src_dream__cycle__kaizen_ops_box(hnd, _ctx), ret, action, _ctx);
}
 
// runtime tag for the effect `:oracle-ops`

kk_std_core_hnd__htag kk_src_dream__cycle_oracle_ops_fs__tag;
 
// handler for the effect `:oracle-ops`

kk_box_t kk_src_dream__cycle_oracle_ops_fs__handle(kk_src_dream__cycle__oracle_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : oracle-ops<e,b>, ret : (res : a) -> e b, action : () -> <oracle-ops|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x1309 = kk_std_core_hnd__htag_dup(kk_src_dream__cycle_oracle_ops_fs__tag, _ctx); /*hnd/htag<src/dream_cycle/oracle-ops>*/
  return kk_std_core_hnd__hhandle(_x_x1309, kk_src_dream__cycle__oracle_ops_box(hnd, _ctx), ret, action, _ctx);
}
 
// runtime tag for the effect `:decay-ops`

kk_std_core_hnd__htag kk_src_dream__cycle_decay_ops_fs__tag;
 
// handler for the effect `:decay-ops`

kk_box_t kk_src_dream__cycle_decay_ops_fs__handle(kk_src_dream__cycle__decay_ops hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : decay-ops<e,b>, ret : (res : a) -> e b, action : () -> <decay-ops|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x1323 = kk_std_core_hnd__htag_dup(kk_src_dream__cycle_decay_ops_fs__tag, _ctx); /*hnd/htag<src/dream_cycle/decay-ops>*/
  return kk_std_core_hnd__hhandle(_x_x1323, kk_src_dream__cycle__decay_ops_box(hnd, _ctx), ret, action, _ctx);
}

kk_src_dream__cycle__triage_result kk_src_dream__cycle_triage_result_fs__copy(kk_src_dream__cycle__triage_result _this, kk_std_core_types__optional tagged, kk_std_core_types__optional drift_corrected, kk_context_t* _ctx) { /* (triage-result, tagged : ? int, drift-corrected : ? int) -> triage-result */ 
  kk_integer_t _x_x1341;
  if (kk_std_core_types__is_Optional(tagged, _ctx)) {
    kk_box_t _box_x273 = tagged._cons._Optional.value;
    kk_integer_t _uniq_tagged_3986 = kk_integer_unbox(_box_x273, _ctx);
    kk_integer_dup(_uniq_tagged_3986, _ctx);
    kk_std_core_types__optional_drop(tagged, _ctx);
    _x_x1341 = _uniq_tagged_3986; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(tagged, _ctx);
    {
      struct kk_src_dream__cycle_Triage_result* _con_x1342 = kk_src_dream__cycle__as_Triage_result(_this, _ctx);
      kk_integer_t _x = _con_x1342->tagged;
      kk_integer_dup(_x, _ctx);
      _x_x1341 = _x; /*int*/
    }
  }
  kk_integer_t _x_x1343;
  if (kk_std_core_types__is_Optional(drift_corrected, _ctx)) {
    kk_box_t _box_x274 = drift_corrected._cons._Optional.value;
    kk_integer_t _uniq_drift_corrected_3994 = kk_integer_unbox(_box_x274, _ctx);
    kk_integer_dup(_uniq_drift_corrected_3994, _ctx);
    kk_std_core_types__optional_drop(drift_corrected, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x1343 = _uniq_drift_corrected_3994; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(drift_corrected, _ctx);
    {
      struct kk_src_dream__cycle_Triage_result* _con_x1344 = kk_src_dream__cycle__as_Triage_result(_this, _ctx);
      kk_integer_t _pat_0_1 = _con_x1344->tagged;
      kk_integer_t _x_0 = _con_x1344->drift_corrected;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1343 = _x_0; /*int*/
    }
  }
  return kk_src_dream__cycle__new_Triage_result(kk_reuse_null, 0, _x_x1341, _x_x1343, _ctx);
}

kk_src_dream__cycle__consolidation_result kk_src_dream__cycle_consolidation_result_fs__copy(kk_src_dream__cycle__consolidation_result _this, kk_std_core_types__optional constellations, kk_std_core_types__optional memberships, kk_context_t* _ctx) { /* (consolidation-result, constellations : ? int, memberships : ? int) -> consolidation-result */ 
  kk_integer_t _x_x1347;
  if (kk_std_core_types__is_Optional(constellations, _ctx)) {
    kk_box_t _box_x275 = constellations._cons._Optional.value;
    kk_integer_t _uniq_constellations_4027 = kk_integer_unbox(_box_x275, _ctx);
    kk_integer_dup(_uniq_constellations_4027, _ctx);
    kk_std_core_types__optional_drop(constellations, _ctx);
    _x_x1347 = _uniq_constellations_4027; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(constellations, _ctx);
    {
      struct kk_src_dream__cycle_Consolidation_result* _con_x1348 = kk_src_dream__cycle__as_Consolidation_result(_this, _ctx);
      kk_integer_t _x = _con_x1348->constellations;
      kk_integer_dup(_x, _ctx);
      _x_x1347 = _x; /*int*/
    }
  }
  kk_integer_t _x_x1349;
  if (kk_std_core_types__is_Optional(memberships, _ctx)) {
    kk_box_t _box_x276 = memberships._cons._Optional.value;
    kk_integer_t _uniq_memberships_4035 = kk_integer_unbox(_box_x276, _ctx);
    kk_integer_dup(_uniq_memberships_4035, _ctx);
    kk_std_core_types__optional_drop(memberships, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x1349 = _uniq_memberships_4035; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(memberships, _ctx);
    {
      struct kk_src_dream__cycle_Consolidation_result* _con_x1350 = kk_src_dream__cycle__as_Consolidation_result(_this, _ctx);
      kk_integer_t _pat_0_1 = _con_x1350->constellations;
      kk_integer_t _x_0 = _con_x1350->memberships;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1349 = _x_0; /*int*/
    }
  }
  return kk_src_dream__cycle__new_Consolidation_result(kk_reuse_null, 0, _x_x1347, _x_x1349, _ctx);
}

kk_src_dream__cycle__serendipity_result kk_src_dream__cycle_serendipity_result_fs__copy(kk_src_dream__cycle__serendipity_result _this, kk_std_core_types__optional bridges, kk_std_core_types__optional insights, kk_std_core_types__optional connections, kk_context_t* _ctx) { /* (serendipity-result, bridges : ? int, insights : ? int, connections : ? int) -> serendipity-result */ 
  kk_integer_t _x_x1354;
  if (kk_std_core_types__is_Optional(bridges, _ctx)) {
    kk_box_t _box_x277 = bridges._cons._Optional.value;
    kk_integer_t _uniq_bridges_4076 = kk_integer_unbox(_box_x277, _ctx);
    kk_integer_dup(_uniq_bridges_4076, _ctx);
    kk_std_core_types__optional_drop(bridges, _ctx);
    _x_x1354 = _uniq_bridges_4076; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(bridges, _ctx);
    {
      struct kk_src_dream__cycle_Serendipity_result* _con_x1355 = kk_src_dream__cycle__as_Serendipity_result(_this, _ctx);
      kk_integer_t _x = _con_x1355->bridges;
      kk_integer_dup(_x, _ctx);
      _x_x1354 = _x; /*int*/
    }
  }
  kk_integer_t _x_x1356;
  if (kk_std_core_types__is_Optional(insights, _ctx)) {
    kk_box_t _box_x278 = insights._cons._Optional.value;
    kk_integer_t _uniq_insights_4084 = kk_integer_unbox(_box_x278, _ctx);
    kk_integer_dup(_uniq_insights_4084, _ctx);
    kk_std_core_types__optional_drop(insights, _ctx);
    _x_x1356 = _uniq_insights_4084; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(insights, _ctx);
    {
      struct kk_src_dream__cycle_Serendipity_result* _con_x1357 = kk_src_dream__cycle__as_Serendipity_result(_this, _ctx);
      kk_integer_t _x_0 = _con_x1357->insights;
      kk_integer_dup(_x_0, _ctx);
      _x_x1356 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x1358;
  if (kk_std_core_types__is_Optional(connections, _ctx)) {
    kk_box_t _box_x279 = connections._cons._Optional.value;
    kk_integer_t _uniq_connections_4092 = kk_integer_unbox(_box_x279, _ctx);
    kk_integer_dup(_uniq_connections_4092, _ctx);
    kk_std_core_types__optional_drop(connections, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x1358 = _uniq_connections_4092; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(connections, _ctx);
    {
      struct kk_src_dream__cycle_Serendipity_result* _con_x1359 = kk_src_dream__cycle__as_Serendipity_result(_this, _ctx);
      kk_integer_t _pat_0_2 = _con_x1359->bridges;
      kk_integer_t _pat_1_3 = _con_x1359->insights;
      kk_integer_t _x_1 = _con_x1359->connections;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_3, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1358 = _x_1; /*int*/
    }
  }
  return kk_src_dream__cycle__new_Serendipity_result(kk_reuse_null, 0, _x_x1354, _x_x1356, _x_x1358, _ctx);
}

kk_src_dream__cycle__governance_result kk_src_dream__cycle_governance_result_fs__copy(kk_src_dream__cycle__governance_result _this, kk_std_core_types__optional communities, kk_std_core_types__optional echo_chambers, kk_std_core_types__optional health, kk_context_t* _ctx) { /* (governance-result, communities : ? int, echo-chambers : ? int, health : ? float64) -> governance-result */ 
  kk_integer_t _x_x1363;
  if (kk_std_core_types__is_Optional(communities, _ctx)) {
    kk_box_t _box_x280 = communities._cons._Optional.value;
    kk_integer_t _uniq_communities_4134 = kk_integer_unbox(_box_x280, _ctx);
    kk_integer_dup(_uniq_communities_4134, _ctx);
    kk_std_core_types__optional_drop(communities, _ctx);
    _x_x1363 = _uniq_communities_4134; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(communities, _ctx);
    {
      struct kk_src_dream__cycle_Governance_result* _con_x1364 = kk_src_dream__cycle__as_Governance_result(_this, _ctx);
      kk_integer_t _x = _con_x1364->communities;
      kk_integer_dup(_x, _ctx);
      _x_x1363 = _x; /*int*/
    }
  }
  kk_integer_t _x_x1365;
  if (kk_std_core_types__is_Optional(echo_chambers, _ctx)) {
    kk_box_t _box_x281 = echo_chambers._cons._Optional.value;
    kk_integer_t _uniq_echo_chambers_4142 = kk_integer_unbox(_box_x281, _ctx);
    kk_integer_dup(_uniq_echo_chambers_4142, _ctx);
    kk_std_core_types__optional_drop(echo_chambers, _ctx);
    _x_x1365 = _uniq_echo_chambers_4142; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(echo_chambers, _ctx);
    {
      struct kk_src_dream__cycle_Governance_result* _con_x1366 = kk_src_dream__cycle__as_Governance_result(_this, _ctx);
      kk_integer_t _x_0 = _con_x1366->echo_chambers;
      kk_integer_dup(_x_0, _ctx);
      _x_x1365 = _x_0; /*int*/
    }
  }
  double _x_x1367;
  if (kk_std_core_types__is_Optional(health, _ctx)) {
    kk_box_t _box_x282 = health._cons._Optional.value;
    double _uniq_health_4150 = kk_double_unbox(_box_x282, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(health, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x1367 = _uniq_health_4150; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(health, _ctx);
    {
      struct kk_src_dream__cycle_Governance_result* _con_x1368 = kk_src_dream__cycle__as_Governance_result(_this, _ctx);
      kk_integer_t _pat_0_2 = _con_x1368->communities;
      kk_integer_t _pat_1_3 = _con_x1368->echo_chambers;
      double _x_1 = _con_x1368->health;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_3, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1367 = _x_1; /*float64*/
    }
  }
  return kk_src_dream__cycle__new_Governance_result(kk_reuse_null, 0, _x_x1363, _x_x1365, _x_x1367, _ctx);
}

kk_src_dream__cycle__narrative_result kk_src_dream__cycle_narrative_result_fs__copy(kk_src_dream__cycle__narrative_result _this, kk_std_core_types__optional clusters, kk_std_core_types__optional narratives, kk_std_core_types__optional compressed, kk_context_t* _ctx) { /* (narrative-result, clusters : ? int, narratives : ? int, compressed : ? int) -> narrative-result */ 
  kk_integer_t _x_x1372;
  if (kk_std_core_types__is_Optional(clusters, _ctx)) {
    kk_box_t _box_x283 = clusters._cons._Optional.value;
    kk_integer_t _uniq_clusters_4192 = kk_integer_unbox(_box_x283, _ctx);
    kk_integer_dup(_uniq_clusters_4192, _ctx);
    kk_std_core_types__optional_drop(clusters, _ctx);
    _x_x1372 = _uniq_clusters_4192; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(clusters, _ctx);
    {
      struct kk_src_dream__cycle_Narrative_result* _con_x1373 = kk_src_dream__cycle__as_Narrative_result(_this, _ctx);
      kk_integer_t _x = _con_x1373->clusters;
      kk_integer_dup(_x, _ctx);
      _x_x1372 = _x; /*int*/
    }
  }
  kk_integer_t _x_x1374;
  if (kk_std_core_types__is_Optional(narratives, _ctx)) {
    kk_box_t _box_x284 = narratives._cons._Optional.value;
    kk_integer_t _uniq_narratives_4200 = kk_integer_unbox(_box_x284, _ctx);
    kk_integer_dup(_uniq_narratives_4200, _ctx);
    kk_std_core_types__optional_drop(narratives, _ctx);
    _x_x1374 = _uniq_narratives_4200; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(narratives, _ctx);
    {
      struct kk_src_dream__cycle_Narrative_result* _con_x1375 = kk_src_dream__cycle__as_Narrative_result(_this, _ctx);
      kk_integer_t _x_0 = _con_x1375->narratives;
      kk_integer_dup(_x_0, _ctx);
      _x_x1374 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x1376;
  if (kk_std_core_types__is_Optional(compressed, _ctx)) {
    kk_box_t _box_x285 = compressed._cons._Optional.value;
    kk_integer_t _uniq_compressed_4208 = kk_integer_unbox(_box_x285, _ctx);
    kk_integer_dup(_uniq_compressed_4208, _ctx);
    kk_std_core_types__optional_drop(compressed, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x1376 = _uniq_compressed_4208; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(compressed, _ctx);
    {
      struct kk_src_dream__cycle_Narrative_result* _con_x1377 = kk_src_dream__cycle__as_Narrative_result(_this, _ctx);
      kk_integer_t _pat_0_2 = _con_x1377->clusters;
      kk_integer_t _pat_1_3 = _con_x1377->narratives;
      kk_integer_t _x_1 = _con_x1377->compressed;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_3, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1376 = _x_1; /*int*/
    }
  }
  return kk_src_dream__cycle__new_Narrative_result(kk_reuse_null, 0, _x_x1372, _x_x1374, _x_x1376, _ctx);
}

kk_src_dream__cycle__kaizen_result kk_src_dream__cycle_kaizen_result_fs__copy(kk_src_dream__cycle__kaizen_result _this, kk_std_core_types__optional emergence_insights, kk_std_core_types__optional persisted, kk_context_t* _ctx) { /* (kaizen-result, emergence-insights : ? int, persisted : ? int) -> kaizen-result */ 
  kk_integer_t _x_x1380;
  if (kk_std_core_types__is_Optional(emergence_insights, _ctx)) {
    kk_box_t _box_x286 = emergence_insights._cons._Optional.value;
    kk_integer_t _uniq_emergence_insights_4242 = kk_integer_unbox(_box_x286, _ctx);
    kk_integer_dup(_uniq_emergence_insights_4242, _ctx);
    kk_std_core_types__optional_drop(emergence_insights, _ctx);
    _x_x1380 = _uniq_emergence_insights_4242; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(emergence_insights, _ctx);
    {
      struct kk_src_dream__cycle_Kaizen_result* _con_x1381 = kk_src_dream__cycle__as_Kaizen_result(_this, _ctx);
      kk_integer_t _x = _con_x1381->emergence_insights;
      kk_integer_dup(_x, _ctx);
      _x_x1380 = _x; /*int*/
    }
  }
  kk_integer_t _x_x1382;
  if (kk_std_core_types__is_Optional(persisted, _ctx)) {
    kk_box_t _box_x287 = persisted._cons._Optional.value;
    kk_integer_t _uniq_persisted_4250 = kk_integer_unbox(_box_x287, _ctx);
    kk_integer_dup(_uniq_persisted_4250, _ctx);
    kk_std_core_types__optional_drop(persisted, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x1382 = _uniq_persisted_4250; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(persisted, _ctx);
    {
      struct kk_src_dream__cycle_Kaizen_result* _con_x1383 = kk_src_dream__cycle__as_Kaizen_result(_this, _ctx);
      kk_integer_t _pat_0_1 = _con_x1383->emergence_insights;
      kk_integer_t _x_0 = _con_x1383->persisted;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1382 = _x_0; /*int*/
    }
  }
  return kk_src_dream__cycle__new_Kaizen_result(kk_reuse_null, 0, _x_x1380, _x_x1382, _ctx);
}

kk_src_dream__cycle__oracle_result kk_src_dream__cycle_oracle_result_fs__copy(kk_src_dream__cycle__oracle_result _this, kk_std_core_types__optional suggestions, kk_context_t* _ctx) { /* (oracle-result, suggestions : ? (list<string>)) -> oracle-result */ 
  kk_std_core_types__list _x_x1384;
  if (kk_std_core_types__is_Optional(suggestions, _ctx)) {
    kk_box_t _box_x288 = suggestions._cons._Optional.value;
    kk_std_core_types__list _uniq_suggestions_4275 = kk_std_core_types__list_unbox(_box_x288, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_suggestions_4275, _ctx);
    kk_std_core_types__optional_drop(suggestions, _ctx);
    kk_src_dream__cycle__oracle_result_drop(_this, _ctx);
    _x_x1384 = _uniq_suggestions_4275; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(suggestions, _ctx);
    {
      kk_std_core_types__list _x = _this.suggestions;
      _x_x1384 = _x; /*list<string>*/
    }
  }
  return kk_src_dream__cycle__new_Oracle_result(_x_x1384, _ctx);
}

kk_src_dream__cycle__decay_result kk_src_dream__cycle_decay_result_fs__copy(kk_src_dream__cycle__decay_result _this, kk_std_core_types__optional swept, kk_context_t* _ctx) { /* (decay-result, swept : ? int) -> decay-result */ 
  kk_integer_t _x_x1385;
  if (kk_std_core_types__is_Optional(swept, _ctx)) {
    kk_box_t _box_x289 = swept._cons._Optional.value;
    kk_integer_t _uniq_swept_4299 = kk_integer_unbox(_box_x289, _ctx);
    kk_integer_dup(_uniq_swept_4299, _ctx);
    kk_std_core_types__optional_drop(swept, _ctx);
    kk_src_dream__cycle__decay_result_drop(_this, _ctx);
    _x_x1385 = _uniq_swept_4299; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(swept, _ctx);
    {
      kk_integer_t _x = _this.swept;
      _x_x1385 = _x; /*int*/
    }
  }
  return kk_src_dream__cycle__new_Decay_result(_x_x1385, _ctx);
}

kk_src_dream__cycle__dream_summary kk_src_dream__cycle_dream_summary_fs__copy(kk_src_dream__cycle__dream_summary _this, kk_std_core_types__optional triage, kk_std_core_types__optional consolidation, kk_std_core_types__optional serendipity, kk_std_core_types__optional governance, kk_std_core_types__optional narrative, kk_std_core_types__optional kaizen, kk_std_core_types__optional oracle, kk_std_core_types__optional decay, kk_std_core_types__optional duration_ms, kk_context_t* _ctx) { /* (dream-summary, triage : ? triage-result, consolidation : ? consolidation-result, serendipity : ? serendipity-result, governance : ? governance-result, narrative : ? narrative-result, kaizen : ? kaizen-result, oracle : ? oracle-result, decay : ? decay-result, duration-ms : ? int) -> dream-summary */ 
  kk_src_dream__cycle__triage_result _x_x1449;
  if (kk_std_core_types__is_Optional(triage, _ctx)) {
    kk_box_t _box_x290 = triage._cons._Optional.value;
    kk_src_dream__cycle__triage_result _uniq_triage_4387 = kk_src_dream__cycle__triage_result_unbox(_box_x290, KK_BORROWED, _ctx);
    kk_src_dream__cycle__triage_result_dup(_uniq_triage_4387, _ctx);
    kk_std_core_types__optional_drop(triage, _ctx);
    _x_x1449 = _uniq_triage_4387; /*src/dream_cycle/triage-result*/
  }
  else {
    kk_std_core_types__optional_drop(triage, _ctx);
    {
      struct kk_src_dream__cycle_Dream_summary* _con_x1450 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
      kk_src_dream__cycle__triage_result _x = _con_x1450->triage;
      kk_src_dream__cycle__consolidation_result _pat_2 = _con_x1450->consolidation;
      kk_src_dream__cycle__serendipity_result _pat_5 = _con_x1450->serendipity;
      kk_src_dream__cycle__governance_result _pat_9 = _con_x1450->governance;
      kk_src_dream__cycle__narrative_result _pat_13 = _con_x1450->narrative;
      kk_src_dream__cycle__kaizen_result _pat_17 = _con_x1450->kaizen;
      kk_src_dream__cycle__oracle_result _pat_20 = _con_x1450->oracle;
      kk_src_dream__cycle__decay_result _pat_22 = _con_x1450->decay;
      struct kk_src_dream__cycle_Triage_result* _con_x1451 = kk_src_dream__cycle__as_Triage_result(_x, _ctx);
      struct kk_src_dream__cycle_Consolidation_result* _con_x1452 = kk_src_dream__cycle__as_Consolidation_result(_pat_2, _ctx);
      struct kk_src_dream__cycle_Serendipity_result* _con_x1453 = kk_src_dream__cycle__as_Serendipity_result(_pat_5, _ctx);
      struct kk_src_dream__cycle_Governance_result* _con_x1454 = kk_src_dream__cycle__as_Governance_result(_pat_9, _ctx);
      struct kk_src_dream__cycle_Narrative_result* _con_x1455 = kk_src_dream__cycle__as_Narrative_result(_pat_13, _ctx);
      struct kk_src_dream__cycle_Kaizen_result* _con_x1456 = kk_src_dream__cycle__as_Kaizen_result(_pat_17, _ctx);
      kk_src_dream__cycle__triage_result_dup(_x, _ctx);
      _x_x1449 = _x; /*src/dream_cycle/triage-result*/
    }
  }
  kk_src_dream__cycle__consolidation_result _x_x1457;
  if (kk_std_core_types__is_Optional(consolidation, _ctx)) {
    kk_box_t _box_x291 = consolidation._cons._Optional.value;
    kk_src_dream__cycle__consolidation_result _uniq_consolidation_4395 = kk_src_dream__cycle__consolidation_result_unbox(_box_x291, KK_BORROWED, _ctx);
    kk_src_dream__cycle__consolidation_result_dup(_uniq_consolidation_4395, _ctx);
    kk_std_core_types__optional_drop(consolidation, _ctx);
    _x_x1457 = _uniq_consolidation_4395; /*src/dream_cycle/consolidation-result*/
  }
  else {
    kk_std_core_types__optional_drop(consolidation, _ctx);
    {
      struct kk_src_dream__cycle_Dream_summary* _con_x1458 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
      kk_src_dream__cycle__triage_result _pat_0_1 = _con_x1458->triage;
      kk_src_dream__cycle__consolidation_result _x_0 = _con_x1458->consolidation;
      kk_src_dream__cycle__serendipity_result _pat_5_0 = _con_x1458->serendipity;
      kk_src_dream__cycle__governance_result _pat_9_0 = _con_x1458->governance;
      kk_src_dream__cycle__narrative_result _pat_13_0 = _con_x1458->narrative;
      kk_src_dream__cycle__kaizen_result _pat_17_0 = _con_x1458->kaizen;
      kk_src_dream__cycle__oracle_result _pat_20_0 = _con_x1458->oracle;
      kk_src_dream__cycle__decay_result _pat_22_0 = _con_x1458->decay;
      struct kk_src_dream__cycle_Triage_result* _con_x1459 = kk_src_dream__cycle__as_Triage_result(_pat_0_1, _ctx);
      struct kk_src_dream__cycle_Consolidation_result* _con_x1460 = kk_src_dream__cycle__as_Consolidation_result(_x_0, _ctx);
      struct kk_src_dream__cycle_Serendipity_result* _con_x1461 = kk_src_dream__cycle__as_Serendipity_result(_pat_5_0, _ctx);
      struct kk_src_dream__cycle_Governance_result* _con_x1462 = kk_src_dream__cycle__as_Governance_result(_pat_9_0, _ctx);
      struct kk_src_dream__cycle_Narrative_result* _con_x1463 = kk_src_dream__cycle__as_Narrative_result(_pat_13_0, _ctx);
      struct kk_src_dream__cycle_Kaizen_result* _con_x1464 = kk_src_dream__cycle__as_Kaizen_result(_pat_17_0, _ctx);
      kk_src_dream__cycle__consolidation_result_dup(_x_0, _ctx);
      _x_x1457 = _x_0; /*src/dream_cycle/consolidation-result*/
    }
  }
  kk_src_dream__cycle__serendipity_result _x_x1465;
  if (kk_std_core_types__is_Optional(serendipity, _ctx)) {
    kk_box_t _box_x292 = serendipity._cons._Optional.value;
    kk_src_dream__cycle__serendipity_result _uniq_serendipity_4403 = kk_src_dream__cycle__serendipity_result_unbox(_box_x292, KK_BORROWED, _ctx);
    kk_src_dream__cycle__serendipity_result_dup(_uniq_serendipity_4403, _ctx);
    kk_std_core_types__optional_drop(serendipity, _ctx);
    _x_x1465 = _uniq_serendipity_4403; /*src/dream_cycle/serendipity-result*/
  }
  else {
    kk_std_core_types__optional_drop(serendipity, _ctx);
    {
      struct kk_src_dream__cycle_Dream_summary* _con_x1466 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
      kk_src_dream__cycle__triage_result _pat_0_2 = _con_x1466->triage;
      kk_src_dream__cycle__consolidation_result _pat_3_2 = _con_x1466->consolidation;
      kk_src_dream__cycle__serendipity_result _x_1 = _con_x1466->serendipity;
      kk_src_dream__cycle__governance_result _pat_9_1 = _con_x1466->governance;
      kk_src_dream__cycle__narrative_result _pat_13_1 = _con_x1466->narrative;
      kk_src_dream__cycle__kaizen_result _pat_17_1 = _con_x1466->kaizen;
      kk_src_dream__cycle__oracle_result _pat_20_1 = _con_x1466->oracle;
      kk_src_dream__cycle__decay_result _pat_22_1 = _con_x1466->decay;
      struct kk_src_dream__cycle_Triage_result* _con_x1467 = kk_src_dream__cycle__as_Triage_result(_pat_0_2, _ctx);
      struct kk_src_dream__cycle_Consolidation_result* _con_x1468 = kk_src_dream__cycle__as_Consolidation_result(_pat_3_2, _ctx);
      struct kk_src_dream__cycle_Serendipity_result* _con_x1469 = kk_src_dream__cycle__as_Serendipity_result(_x_1, _ctx);
      struct kk_src_dream__cycle_Governance_result* _con_x1470 = kk_src_dream__cycle__as_Governance_result(_pat_9_1, _ctx);
      struct kk_src_dream__cycle_Narrative_result* _con_x1471 = kk_src_dream__cycle__as_Narrative_result(_pat_13_1, _ctx);
      struct kk_src_dream__cycle_Kaizen_result* _con_x1472 = kk_src_dream__cycle__as_Kaizen_result(_pat_17_1, _ctx);
      kk_src_dream__cycle__serendipity_result_dup(_x_1, _ctx);
      _x_x1465 = _x_1; /*src/dream_cycle/serendipity-result*/
    }
  }
  kk_src_dream__cycle__governance_result _x_x1473;
  if (kk_std_core_types__is_Optional(governance, _ctx)) {
    kk_box_t _box_x293 = governance._cons._Optional.value;
    kk_src_dream__cycle__governance_result _uniq_governance_4411 = kk_src_dream__cycle__governance_result_unbox(_box_x293, KK_BORROWED, _ctx);
    kk_src_dream__cycle__governance_result_dup(_uniq_governance_4411, _ctx);
    kk_std_core_types__optional_drop(governance, _ctx);
    _x_x1473 = _uniq_governance_4411; /*src/dream_cycle/governance-result*/
  }
  else {
    kk_std_core_types__optional_drop(governance, _ctx);
    {
      struct kk_src_dream__cycle_Dream_summary* _con_x1474 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
      kk_src_dream__cycle__triage_result _pat_0_3 = _con_x1474->triage;
      kk_src_dream__cycle__consolidation_result _pat_3_3 = _con_x1474->consolidation;
      kk_src_dream__cycle__serendipity_result _pat_6_3 = _con_x1474->serendipity;
      kk_src_dream__cycle__governance_result _x_2 = _con_x1474->governance;
      kk_src_dream__cycle__narrative_result _pat_13_2 = _con_x1474->narrative;
      kk_src_dream__cycle__kaizen_result _pat_17_2 = _con_x1474->kaizen;
      kk_src_dream__cycle__oracle_result _pat_20_2 = _con_x1474->oracle;
      kk_src_dream__cycle__decay_result _pat_22_2 = _con_x1474->decay;
      struct kk_src_dream__cycle_Triage_result* _con_x1475 = kk_src_dream__cycle__as_Triage_result(_pat_0_3, _ctx);
      struct kk_src_dream__cycle_Consolidation_result* _con_x1476 = kk_src_dream__cycle__as_Consolidation_result(_pat_3_3, _ctx);
      struct kk_src_dream__cycle_Serendipity_result* _con_x1477 = kk_src_dream__cycle__as_Serendipity_result(_pat_6_3, _ctx);
      struct kk_src_dream__cycle_Governance_result* _con_x1478 = kk_src_dream__cycle__as_Governance_result(_x_2, _ctx);
      struct kk_src_dream__cycle_Narrative_result* _con_x1479 = kk_src_dream__cycle__as_Narrative_result(_pat_13_2, _ctx);
      struct kk_src_dream__cycle_Kaizen_result* _con_x1480 = kk_src_dream__cycle__as_Kaizen_result(_pat_17_2, _ctx);
      kk_src_dream__cycle__governance_result_dup(_x_2, _ctx);
      _x_x1473 = _x_2; /*src/dream_cycle/governance-result*/
    }
  }
  kk_src_dream__cycle__narrative_result _x_x1481;
  if (kk_std_core_types__is_Optional(narrative, _ctx)) {
    kk_box_t _box_x294 = narrative._cons._Optional.value;
    kk_src_dream__cycle__narrative_result _uniq_narrative_4419 = kk_src_dream__cycle__narrative_result_unbox(_box_x294, KK_BORROWED, _ctx);
    kk_src_dream__cycle__narrative_result_dup(_uniq_narrative_4419, _ctx);
    kk_std_core_types__optional_drop(narrative, _ctx);
    _x_x1481 = _uniq_narrative_4419; /*src/dream_cycle/narrative-result*/
  }
  else {
    kk_std_core_types__optional_drop(narrative, _ctx);
    {
      struct kk_src_dream__cycle_Dream_summary* _con_x1482 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
      kk_src_dream__cycle__triage_result _pat_0_4 = _con_x1482->triage;
      kk_src_dream__cycle__consolidation_result _pat_3_4 = _con_x1482->consolidation;
      kk_src_dream__cycle__serendipity_result _pat_6_4 = _con_x1482->serendipity;
      kk_src_dream__cycle__governance_result _pat_10_3 = _con_x1482->governance;
      kk_src_dream__cycle__narrative_result _x_3 = _con_x1482->narrative;
      kk_src_dream__cycle__kaizen_result _pat_17_3 = _con_x1482->kaizen;
      kk_src_dream__cycle__oracle_result _pat_20_3 = _con_x1482->oracle;
      kk_src_dream__cycle__decay_result _pat_22_3 = _con_x1482->decay;
      struct kk_src_dream__cycle_Triage_result* _con_x1483 = kk_src_dream__cycle__as_Triage_result(_pat_0_4, _ctx);
      struct kk_src_dream__cycle_Consolidation_result* _con_x1484 = kk_src_dream__cycle__as_Consolidation_result(_pat_3_4, _ctx);
      struct kk_src_dream__cycle_Serendipity_result* _con_x1485 = kk_src_dream__cycle__as_Serendipity_result(_pat_6_4, _ctx);
      struct kk_src_dream__cycle_Governance_result* _con_x1486 = kk_src_dream__cycle__as_Governance_result(_pat_10_3, _ctx);
      struct kk_src_dream__cycle_Narrative_result* _con_x1487 = kk_src_dream__cycle__as_Narrative_result(_x_3, _ctx);
      struct kk_src_dream__cycle_Kaizen_result* _con_x1488 = kk_src_dream__cycle__as_Kaizen_result(_pat_17_3, _ctx);
      kk_src_dream__cycle__narrative_result_dup(_x_3, _ctx);
      _x_x1481 = _x_3; /*src/dream_cycle/narrative-result*/
    }
  }
  kk_src_dream__cycle__kaizen_result _x_x1489;
  if (kk_std_core_types__is_Optional(kaizen, _ctx)) {
    kk_box_t _box_x295 = kaizen._cons._Optional.value;
    kk_src_dream__cycle__kaizen_result _uniq_kaizen_4427 = kk_src_dream__cycle__kaizen_result_unbox(_box_x295, KK_BORROWED, _ctx);
    kk_src_dream__cycle__kaizen_result_dup(_uniq_kaizen_4427, _ctx);
    kk_std_core_types__optional_drop(kaizen, _ctx);
    _x_x1489 = _uniq_kaizen_4427; /*src/dream_cycle/kaizen-result*/
  }
  else {
    kk_std_core_types__optional_drop(kaizen, _ctx);
    {
      struct kk_src_dream__cycle_Dream_summary* _con_x1490 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
      kk_src_dream__cycle__triage_result _pat_0_5 = _con_x1490->triage;
      kk_src_dream__cycle__consolidation_result _pat_3_5 = _con_x1490->consolidation;
      kk_src_dream__cycle__serendipity_result _pat_6_5 = _con_x1490->serendipity;
      kk_src_dream__cycle__governance_result _pat_10_5 = _con_x1490->governance;
      kk_src_dream__cycle__narrative_result _pat_14_4 = _con_x1490->narrative;
      kk_src_dream__cycle__kaizen_result _x_4 = _con_x1490->kaizen;
      kk_src_dream__cycle__oracle_result _pat_20_4 = _con_x1490->oracle;
      kk_src_dream__cycle__decay_result _pat_22_4 = _con_x1490->decay;
      struct kk_src_dream__cycle_Triage_result* _con_x1491 = kk_src_dream__cycle__as_Triage_result(_pat_0_5, _ctx);
      struct kk_src_dream__cycle_Consolidation_result* _con_x1492 = kk_src_dream__cycle__as_Consolidation_result(_pat_3_5, _ctx);
      struct kk_src_dream__cycle_Serendipity_result* _con_x1493 = kk_src_dream__cycle__as_Serendipity_result(_pat_6_5, _ctx);
      struct kk_src_dream__cycle_Governance_result* _con_x1494 = kk_src_dream__cycle__as_Governance_result(_pat_10_5, _ctx);
      struct kk_src_dream__cycle_Narrative_result* _con_x1495 = kk_src_dream__cycle__as_Narrative_result(_pat_14_4, _ctx);
      struct kk_src_dream__cycle_Kaizen_result* _con_x1496 = kk_src_dream__cycle__as_Kaizen_result(_x_4, _ctx);
      kk_src_dream__cycle__kaizen_result_dup(_x_4, _ctx);
      _x_x1489 = _x_4; /*src/dream_cycle/kaizen-result*/
    }
  }
  kk_src_dream__cycle__oracle_result _x_x1497;
  if (kk_std_core_types__is_Optional(oracle, _ctx)) {
    kk_box_t _box_x296 = oracle._cons._Optional.value;
    kk_src_dream__cycle__oracle_result _uniq_oracle_4435 = kk_src_dream__cycle__oracle_result_unbox(_box_x296, KK_BORROWED, _ctx);
    kk_src_dream__cycle__oracle_result_dup(_uniq_oracle_4435, _ctx);
    kk_std_core_types__optional_drop(oracle, _ctx);
    _x_x1497 = _uniq_oracle_4435; /*src/dream_cycle/oracle-result*/
  }
  else {
    kk_std_core_types__optional_drop(oracle, _ctx);
    {
      struct kk_src_dream__cycle_Dream_summary* _con_x1498 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
      kk_src_dream__cycle__triage_result _pat_0_6 = _con_x1498->triage;
      kk_src_dream__cycle__consolidation_result _pat_3_6 = _con_x1498->consolidation;
      kk_src_dream__cycle__serendipity_result _pat_6_6 = _con_x1498->serendipity;
      kk_src_dream__cycle__governance_result _pat_10_6 = _con_x1498->governance;
      kk_src_dream__cycle__narrative_result _pat_14_5 = _con_x1498->narrative;
      kk_src_dream__cycle__kaizen_result _pat_18_5 = _con_x1498->kaizen;
      kk_src_dream__cycle__oracle_result _x_5 = _con_x1498->oracle;
      kk_src_dream__cycle__decay_result _pat_22_5 = _con_x1498->decay;
      struct kk_src_dream__cycle_Triage_result* _con_x1499 = kk_src_dream__cycle__as_Triage_result(_pat_0_6, _ctx);
      struct kk_src_dream__cycle_Consolidation_result* _con_x1500 = kk_src_dream__cycle__as_Consolidation_result(_pat_3_6, _ctx);
      struct kk_src_dream__cycle_Serendipity_result* _con_x1501 = kk_src_dream__cycle__as_Serendipity_result(_pat_6_6, _ctx);
      struct kk_src_dream__cycle_Governance_result* _con_x1502 = kk_src_dream__cycle__as_Governance_result(_pat_10_6, _ctx);
      struct kk_src_dream__cycle_Narrative_result* _con_x1503 = kk_src_dream__cycle__as_Narrative_result(_pat_14_5, _ctx);
      struct kk_src_dream__cycle_Kaizen_result* _con_x1504 = kk_src_dream__cycle__as_Kaizen_result(_pat_18_5, _ctx);
      kk_src_dream__cycle__oracle_result_dup(_x_5, _ctx);
      _x_x1497 = _x_5; /*src/dream_cycle/oracle-result*/
    }
  }
  kk_src_dream__cycle__decay_result _x_x1505;
  if (kk_std_core_types__is_Optional(decay, _ctx)) {
    kk_box_t _box_x297 = decay._cons._Optional.value;
    kk_src_dream__cycle__decay_result _uniq_decay_4443 = kk_src_dream__cycle__decay_result_unbox(_box_x297, KK_BORROWED, _ctx);
    kk_src_dream__cycle__decay_result_dup(_uniq_decay_4443, _ctx);
    kk_std_core_types__optional_drop(decay, _ctx);
    _x_x1505 = _uniq_decay_4443; /*src/dream_cycle/decay-result*/
  }
  else {
    kk_std_core_types__optional_drop(decay, _ctx);
    {
      struct kk_src_dream__cycle_Dream_summary* _con_x1506 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
      kk_src_dream__cycle__triage_result _pat_0_7 = _con_x1506->triage;
      kk_src_dream__cycle__consolidation_result _pat_3_7 = _con_x1506->consolidation;
      kk_src_dream__cycle__serendipity_result _pat_6_7 = _con_x1506->serendipity;
      kk_src_dream__cycle__governance_result _pat_10_7 = _con_x1506->governance;
      kk_src_dream__cycle__narrative_result _pat_14_7 = _con_x1506->narrative;
      kk_src_dream__cycle__kaizen_result _pat_18_6 = _con_x1506->kaizen;
      kk_src_dream__cycle__oracle_result _pat_21_6 = _con_x1506->oracle;
      kk_src_dream__cycle__decay_result _x_6 = _con_x1506->decay;
      struct kk_src_dream__cycle_Triage_result* _con_x1507 = kk_src_dream__cycle__as_Triage_result(_pat_0_7, _ctx);
      struct kk_src_dream__cycle_Consolidation_result* _con_x1508 = kk_src_dream__cycle__as_Consolidation_result(_pat_3_7, _ctx);
      struct kk_src_dream__cycle_Serendipity_result* _con_x1509 = kk_src_dream__cycle__as_Serendipity_result(_pat_6_7, _ctx);
      struct kk_src_dream__cycle_Governance_result* _con_x1510 = kk_src_dream__cycle__as_Governance_result(_pat_10_7, _ctx);
      struct kk_src_dream__cycle_Narrative_result* _con_x1511 = kk_src_dream__cycle__as_Narrative_result(_pat_14_7, _ctx);
      struct kk_src_dream__cycle_Kaizen_result* _con_x1512 = kk_src_dream__cycle__as_Kaizen_result(_pat_18_6, _ctx);
      kk_src_dream__cycle__decay_result_dup(_x_6, _ctx);
      _x_x1505 = _x_6; /*src/dream_cycle/decay-result*/
    }
  }
  kk_integer_t _x_x1513;
  if (kk_std_core_types__is_Optional(duration_ms, _ctx)) {
    kk_box_t _box_x298 = duration_ms._cons._Optional.value;
    kk_integer_t _uniq_duration_ms_4451 = kk_integer_unbox(_box_x298, _ctx);
    kk_integer_dup(_uniq_duration_ms_4451, _ctx);
    kk_std_core_types__optional_drop(duration_ms, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(9)), _ctx);
    _x_x1513 = _uniq_duration_ms_4451; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(duration_ms, _ctx);
    {
      struct kk_src_dream__cycle_Dream_summary* _con_x1514 = kk_src_dream__cycle__as_Dream_summary(_this, _ctx);
      kk_src_dream__cycle__triage_result _pat_0_8 = _con_x1514->triage;
      kk_src_dream__cycle__consolidation_result _pat_3_8 = _con_x1514->consolidation;
      kk_src_dream__cycle__serendipity_result _pat_6_8 = _con_x1514->serendipity;
      kk_src_dream__cycle__governance_result _pat_10_8 = _con_x1514->governance;
      kk_src_dream__cycle__narrative_result _pat_14_8 = _con_x1514->narrative;
      kk_src_dream__cycle__kaizen_result _pat_18_7 = _con_x1514->kaizen;
      kk_src_dream__cycle__oracle_result _pat_21_7 = _con_x1514->oracle;
      kk_src_dream__cycle__decay_result _pat_23_7 = _con_x1514->decay;
      struct kk_src_dream__cycle_Triage_result* _con_x1515 = kk_src_dream__cycle__as_Triage_result(_pat_0_8, _ctx);
      struct kk_src_dream__cycle_Consolidation_result* _con_x1516 = kk_src_dream__cycle__as_Consolidation_result(_pat_3_8, _ctx);
      struct kk_src_dream__cycle_Serendipity_result* _con_x1517 = kk_src_dream__cycle__as_Serendipity_result(_pat_6_8, _ctx);
      struct kk_src_dream__cycle_Governance_result* _con_x1518 = kk_src_dream__cycle__as_Governance_result(_pat_10_8, _ctx);
      struct kk_src_dream__cycle_Narrative_result* _con_x1519 = kk_src_dream__cycle__as_Narrative_result(_pat_14_8, _ctx);
      struct kk_src_dream__cycle_Kaizen_result* _con_x1520 = kk_src_dream__cycle__as_Kaizen_result(_pat_18_7, _ctx);
      kk_integer_t _x_7 = _con_x1514->duration_ms;
      kk_integer_t _pat_1_9 = _con_x1515->tagged;
      kk_integer_t _pat_2_8 = _con_x1515->drift_corrected;
      kk_integer_t _pat_4_8 = _con_x1516->constellations;
      kk_integer_t _pat_5_8 = _con_x1516->memberships;
      kk_integer_t _pat_7_8 = _con_x1517->bridges;
      kk_integer_t _pat_8_8 = _con_x1517->insights;
      kk_integer_t _pat_9_8 = _con_x1517->connections;
      kk_integer_t _pat_11_8 = _con_x1518->communities;
      kk_integer_t _pat_12_8 = _con_x1518->echo_chambers;
      kk_integer_t _pat_15_8 = _con_x1519->clusters;
      kk_integer_t _pat_16_8 = _con_x1519->narratives;
      kk_integer_t _pat_17_7 = _con_x1519->compressed;
      kk_integer_t _pat_19_7 = _con_x1520->emergence_insights;
      kk_integer_t _pat_20_7 = _con_x1520->persisted;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_6_8, _ctx)) {
          kk_integer_drop(_pat_9_8, _ctx);
          kk_integer_drop(_pat_8_8, _ctx);
          kk_integer_drop(_pat_7_8, _ctx);
          kk_datatype_ptr_free(_pat_6_8, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_6_8, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3_8, _ctx)) {
          kk_integer_drop(_pat_5_8, _ctx);
          kk_integer_drop(_pat_4_8, _ctx);
          kk_datatype_ptr_free(_pat_3_8, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_3_8, _ctx);
        }
        kk_src_dream__cycle__decay_result_drop(_pat_23_7, _ctx);
        kk_src_dream__cycle__oracle_result_drop(_pat_21_7, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_pat_18_7, _ctx)) {
          kk_integer_drop(_pat_20_7, _ctx);
          kk_integer_drop(_pat_19_7, _ctx);
          kk_datatype_ptr_free(_pat_18_7, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_18_7, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_14_8, _ctx)) {
          kk_integer_drop(_pat_17_7, _ctx);
          kk_integer_drop(_pat_16_8, _ctx);
          kk_integer_drop(_pat_15_8, _ctx);
          kk_datatype_ptr_free(_pat_14_8, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_14_8, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_10_8, _ctx)) {
          kk_integer_drop(_pat_12_8, _ctx);
          kk_integer_drop(_pat_11_8, _ctx);
          kk_datatype_ptr_free(_pat_10_8, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_10_8, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_0_8, _ctx)) {
          kk_integer_drop(_pat_2_8, _ctx);
          kk_integer_drop(_pat_1_9, _ctx);
          kk_datatype_ptr_free(_pat_0_8, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_0_8, _ctx);
        }
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_7, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1513 = _x_7; /*int*/
    }
  }
  return kk_src_dream__cycle__new_Dream_summary(kk_reuse_null, 0, _x_x1449, _x_x1457, _x_x1465, _x_x1473, _x_x1481, _x_x1489, _x_x1497, _x_x1505, _x_x1513, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1522__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_triage_10165_fun1522(kk_function_t _fself, kk_box_t _b_x314, kk_box_t _b_x315, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_triage_10165_fun1522(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_phase_triage_10165_fun1522, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1529__t {
  struct kk_function_s _base;
  kk_box_t _b_x314;
};
static kk_integer_t kk_src_dream__cycle__mlift_phase_triage_10165_fun1529(kk_function_t _fself, bool _y_x10076, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_triage_10165_fun1529(kk_box_t _b_x314, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1529__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1529__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_triage_10165_fun1529, kk_context());
  _self->_b_x314 = _b_x314;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_src_dream__cycle__mlift_phase_triage_10165_fun1529(kk_function_t _fself, bool _y_x10076, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1529__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1529__t*, _fself, _ctx);
  kk_box_t _b_x314 = _self->_b_x314; /* 10002 */
  kk_drop_match(_self, {kk_box_dup(_b_x314, _ctx);}, {}, _ctx)
  if (_y_x10076) {
    kk_integer_t _x_x1530 = kk_integer_unbox(_b_x314, _ctx); /*int*/
    return kk_integer_add_small_const(_x_x1530, 1, _ctx);
  }
  {
    return kk_integer_unbox(_b_x314, _ctx);
  }
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1533__t {
  struct kk_function_s _base;
  kk_function_t next_0_10285;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_triage_10165_fun1533(kk_function_t _fself, kk_box_t _b_x310, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_triage_10165_fun1533(kk_function_t next_0_10285, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1533__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1533__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_triage_10165_fun1533, kk_context());
  _self->next_0_10285 = next_0_10285;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_triage_10165_fun1533(kk_function_t _fself, kk_box_t _b_x310, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1533__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1533__t*, _fself, _ctx);
  kk_function_t next_0_10285 = _self->next_0_10285; /* (bool) -> src/dream_cycle/memory-ops int */
  kk_drop_match(_self, {kk_function_dup(next_0_10285, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1534;
  bool _x_x1535 = kk_bool_unbox(_b_x310); /*bool*/
  _x_x1534 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), next_0_10285, (next_0_10285, _x_x1535, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x1534, _ctx);
}
static kk_box_t kk_src_dream__cycle__mlift_phase_triage_10165_fun1522(kk_function_t _fself, kk_box_t _b_x314, kk_box_t _b_x315, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10286 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/memory-ops>*/;
  bool x_0_10284;
  kk_box_t _x_x1523;
  {
    struct kk_std_core_hnd_Ev* _con_x1524 = kk_std_core_hnd__as_Ev(evx_10286, _ctx);
    kk_box_t _box_x299 = _con_x1524->hnd;
    int32_t m = _con_x1524->marker;
    kk_src_dream__cycle__memory_ops h = kk_src_dream__cycle__memory_ops_unbox(_box_x299, KK_BORROWED, _ctx);
    kk_src_dream__cycle__memory_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1525 = kk_src_dream__cycle__as_Hnd_memory_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1525->_cfc;
      kk_std_core_hnd__clause2 _pat_1 = _con_x1525->_fun_decay_memory;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1525->_fun_recall_memories;
      kk_std_core_hnd__clause2 _pat_3 = _con_x1525->_fun_store_memory;
      kk_std_core_hnd__clause2 _fun_tag_memory = _con_x1525->_fun_tag_memory;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_tag_memory, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x304 = _fun_tag_memory.clause;
        kk_box_t _x_x1526;
        kk_string_t _x_x1527;
        kk_define_string_literal(, _s_x1528, 12, "auto-triaged", _ctx)
        _x_x1527 = kk_string_dup(_s_x1528, _ctx); /*string*/
        _x_x1526 = kk_string_box(_x_x1527); /*10015*/
        _x_x1523 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x304, (_fun_unbox_x304, m, evx_10286, _b_x315, _x_x1526, _ctx), _ctx); /*10016*/
      }
    }
  }
  x_0_10284 = kk_bool_unbox(_x_x1523); /*bool*/
  kk_function_t next_0_10285 = kk_src_dream__cycle__new_mlift_phase_triage_10165_fun1529(_b_x314, _ctx); /*(bool) -> src/dream_cycle/memory-ops int*/;
  kk_integer_t _x_x1531;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1532 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_triage_10165_fun1533(next_0_10285, _ctx), _ctx); /*10001*/
    _x_x1531 = kk_integer_unbox(_x_x1532, _ctx); /*int*/
  }
  else {
    _x_x1531 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), next_0_10285, (next_0_10285, x_0_10284, _ctx), _ctx); /*int*/
  }
  return kk_integer_box(_x_x1531, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_triage_10165_fun1537__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_triage_10165_fun1537(kk_function_t _fself, kk_box_t _b_x323, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_triage_10165_fun1537(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_phase_triage_10165_fun1537, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_triage_10165_fun1537(kk_function_t _fself, kk_box_t _b_x323, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__triage_result _x_x1538;
  kk_integer_t _x_x1539 = kk_integer_unbox(_b_x323, _ctx); /*int*/
  _x_x1538 = kk_src_dream__cycle__mlift_phase_triage_10164(_x_x1539, _ctx); /*src/dream_cycle/triage-result*/
  return kk_src_dream__cycle__triage_result_box(_x_x1538, _ctx);
}

kk_src_dream__cycle__triage_result kk_src_dream__cycle__mlift_phase_triage_10165(kk_std_core_types__list recent, kk_context_t* _ctx) { /* (recent : list<string>) -> memory-ops triage-result */ 
  kk_integer_t x_10282;
  kk_box_t _x_x1521 = kk_std_core_list_foldl(recent, kk_integer_box(kk_integer_from_small(0), _ctx), kk_src_dream__cycle__new_mlift_phase_triage_10165_fun1522(_ctx), _ctx); /*10002*/
  x_10282 = kk_integer_unbox(_x_x1521, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10282, _ctx);
    kk_box_t _x_x1536 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_triage_10165_fun1537(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__triage_result_unbox(_x_x1536, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__new_Triage_result(kk_reuse_null, 0, x_10282, kk_integer_from_small(2), _ctx);
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_triage_fun1547__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_triage_fun1547(kk_function_t _fself, kk_box_t _b_x336, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_triage_fun1547(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_triage_fun1547, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_triage_fun1547(kk_function_t _fself, kk_box_t _b_x336, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__triage_result _x_x1548;
  kk_std_core_types__list _x_x1549 = kk_std_core_types__list_unbox(_b_x336, KK_OWNED, _ctx); /*list<string>*/
  _x_x1548 = kk_src_dream__cycle__mlift_phase_triage_10165(_x_x1549, _ctx); /*src/dream_cycle/triage-result*/
  return kk_src_dream__cycle__triage_result_box(_x_x1548, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_phase_triage_fun1551__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_triage_fun1551(kk_function_t _fself, kk_box_t _b_x352, kk_box_t _b_x353, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_triage_fun1551(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_triage_fun1551, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle_phase_triage_fun1558__t {
  struct kk_function_s _base;
  kk_box_t _b_x352;
};
static kk_integer_t kk_src_dream__cycle_phase_triage_fun1558(kk_function_t _fself, bool _y_x10076, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_triage_fun1558(kk_box_t _b_x352, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_triage_fun1558__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_phase_triage_fun1558__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_phase_triage_fun1558, kk_context());
  _self->_b_x352 = _b_x352;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_src_dream__cycle_phase_triage_fun1558(kk_function_t _fself, bool _y_x10076, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_triage_fun1558__t* _self = kk_function_as(struct kk_src_dream__cycle_phase_triage_fun1558__t*, _fself, _ctx);
  kk_box_t _b_x352 = _self->_b_x352; /* 10002 */
  kk_drop_match(_self, {kk_box_dup(_b_x352, _ctx);}, {}, _ctx)
  if (_y_x10076) {
    kk_integer_t _x_x1559 = kk_integer_unbox(_b_x352, _ctx); /*int*/
    return kk_integer_add_small_const(_x_x1559, 1, _ctx);
  }
  {
    return kk_integer_unbox(_b_x352, _ctx);
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_triage_fun1562__t {
  struct kk_function_s _base;
  kk_function_t next_1_10303;
};
static kk_box_t kk_src_dream__cycle_phase_triage_fun1562(kk_function_t _fself, kk_box_t _b_x348, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_triage_fun1562(kk_function_t next_1_10303, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_triage_fun1562__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_phase_triage_fun1562__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_phase_triage_fun1562, kk_context());
  _self->next_1_10303 = next_1_10303;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_triage_fun1562(kk_function_t _fself, kk_box_t _b_x348, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_triage_fun1562__t* _self = kk_function_as(struct kk_src_dream__cycle_phase_triage_fun1562__t*, _fself, _ctx);
  kk_function_t next_1_10303 = _self->next_1_10303; /* (bool) -> src/dream_cycle/memory-ops int */
  kk_drop_match(_self, {kk_function_dup(next_1_10303, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1563;
  bool _x_x1564 = kk_bool_unbox(_b_x348); /*bool*/
  _x_x1563 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), next_1_10303, (next_1_10303, _x_x1564, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x1563, _ctx);
}
static kk_box_t kk_src_dream__cycle_phase_triage_fun1551(kk_function_t _fself, kk_box_t _b_x352, kk_box_t _b_x353, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_0_10304 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/memory-ops>*/;
  bool x_2_10302;
  kk_box_t _x_x1552;
  {
    struct kk_std_core_hnd_Ev* _con_x1553 = kk_std_core_hnd__as_Ev(evx_0_10304, _ctx);
    kk_box_t _box_x337 = _con_x1553->hnd;
    int32_t m_0 = _con_x1553->marker;
    kk_src_dream__cycle__memory_ops h_0 = kk_src_dream__cycle__memory_ops_unbox(_box_x337, KK_BORROWED, _ctx);
    kk_src_dream__cycle__memory_ops_dup(h_0, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1554 = kk_src_dream__cycle__as_Hnd_memory_ops(h_0, _ctx);
      kk_integer_t _pat_0_2 = _con_x1554->_cfc;
      kk_std_core_hnd__clause2 _pat_1_2 = _con_x1554->_fun_decay_memory;
      kk_std_core_hnd__clause2 _pat_2_1 = _con_x1554->_fun_recall_memories;
      kk_std_core_hnd__clause2 _pat_3_0 = _con_x1554->_fun_store_memory;
      kk_std_core_hnd__clause2 _fun_tag_memory = _con_x1554->_fun_tag_memory;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_1, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_tag_memory, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x342 = _fun_tag_memory.clause;
        kk_box_t _x_x1555;
        kk_string_t _x_x1556;
        kk_define_string_literal(, _s_x1557, 12, "auto-triaged", _ctx)
        _x_x1556 = kk_string_dup(_s_x1557, _ctx); /*string*/
        _x_x1555 = kk_string_box(_x_x1556); /*10015*/
        _x_x1552 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x342, (_fun_unbox_x342, m_0, evx_0_10304, _b_x353, _x_x1555, _ctx), _ctx); /*10016*/
      }
    }
  }
  x_2_10302 = kk_bool_unbox(_x_x1552); /*bool*/
  kk_function_t next_1_10303 = kk_src_dream__cycle_new_phase_triage_fun1558(_b_x352, _ctx); /*(bool) -> src/dream_cycle/memory-ops int*/;
  kk_integer_t _x_x1560;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1561 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_triage_fun1562(next_1_10303, _ctx), _ctx); /*10001*/
    _x_x1560 = kk_integer_unbox(_x_x1561, _ctx); /*int*/
  }
  else {
    _x_x1560 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), next_1_10303, (next_1_10303, x_2_10302, _ctx), _ctx); /*int*/
  }
  return kk_integer_box(_x_x1560, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_phase_triage_fun1566__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_triage_fun1566(kk_function_t _fself, kk_box_t _b_x361, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_triage_fun1566(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_triage_fun1566, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_triage_fun1566(kk_function_t _fself, kk_box_t _b_x361, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__triage_result _x_x1567;
  kk_integer_t _x_x1568 = kk_integer_unbox(_b_x361, _ctx); /*int*/
  _x_x1567 = kk_src_dream__cycle__mlift_phase_triage_10164(_x_x1568, _ctx); /*src/dream_cycle/triage-result*/
  return kk_src_dream__cycle__triage_result_box(_x_x1567, _ctx);
}

kk_src_dream__cycle__triage_result kk_src_dream__cycle_phase_triage(kk_context_t* _ctx) { /* () -> memory-ops triage-result */ 
  kk_std_core_hnd__ev evx_10295 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/memory-ops>*/;
  kk_std_core_types__list x_10292;
  kk_box_t _x_x1540;
  {
    struct kk_std_core_hnd_Ev* _con_x1541 = kk_std_core_hnd__as_Ev(evx_10295, _ctx);
    kk_box_t _box_x325 = _con_x1541->hnd;
    int32_t m = _con_x1541->marker;
    kk_src_dream__cycle__memory_ops h = kk_src_dream__cycle__memory_ops_unbox(_box_x325, KK_BORROWED, _ctx);
    kk_src_dream__cycle__memory_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1542 = kk_src_dream__cycle__as_Hnd_memory_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1542->_cfc;
      kk_std_core_hnd__clause2 _pat_1_1 = _con_x1542->_fun_decay_memory;
      kk_std_core_hnd__clause2 _fun_recall_memories = _con_x1542->_fun_recall_memories;
      kk_std_core_hnd__clause2 _pat_2 = _con_x1542->_fun_store_memory;
      kk_std_core_hnd__clause2 _pat_3 = _con_x1542->_fun_tag_memory;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_recall_memories, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x330 = _fun_recall_memories.clause;
        kk_box_t _x_x1543;
        kk_string_t _x_x1544 = kk_string_empty(); /*string*/
        _x_x1543 = kk_string_box(_x_x1544); /*10014*/
        _x_x1540 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x330, (_fun_unbox_x330, m, evx_10295, _x_x1543, kk_integer_box(kk_integer_from_small(40), _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  x_10292 = kk_std_core_types__list_unbox(_x_x1540, KK_OWNED, _ctx); /*list<string>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10292, _ctx);
    kk_box_t _x_x1546 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_triage_fun1547(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__triage_result_unbox(_x_x1546, KK_OWNED, _ctx);
  }
  {
    kk_integer_t x_1_10299;
    kk_box_t _x_x1550 = kk_std_core_list_foldl(x_10292, kk_integer_box(kk_integer_from_small(0), _ctx), kk_src_dream__cycle_new_phase_triage_fun1551(_ctx), _ctx); /*10002*/
    x_1_10299 = kk_integer_unbox(_x_x1550, _ctx); /*int*/
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_1_10299, _ctx);
      kk_box_t _x_x1565 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_triage_fun1566(_ctx), _ctx); /*10001*/
      return kk_src_dream__cycle__triage_result_unbox(_x_x1565, KK_OWNED, _ctx);
    }
    {
      return kk_src_dream__cycle__new_Triage_result(kk_reuse_null, 0, x_1_10299, kk_integer_from_small(2), _ctx);
    }
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_consolidation_fun1577__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_consolidation_fun1577(kk_function_t _fself, kk_box_t _b_x373, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_consolidation_fun1577(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_consolidation_fun1577, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_consolidation_fun1577(kk_function_t _fself, kk_box_t _b_x373, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__consolidation_result _x_x1578;
  kk_std_core_types__list _x_x1579 = kk_std_core_types__list_unbox(_b_x373, KK_OWNED, _ctx); /*list<string>*/
  _x_x1578 = kk_src_dream__cycle__mlift_phase_consolidation_10166(_x_x1579, _ctx); /*src/dream_cycle/consolidation-result*/
  return kk_src_dream__cycle__consolidation_result_box(_x_x1578, _ctx);
}

kk_src_dream__cycle__consolidation_result kk_src_dream__cycle_phase_consolidation(kk_context_t* _ctx) { /* () -> constellation-ops consolidation-result */ 
  kk_std_core_hnd__ev ev_10313 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/constellation-ops>*/;
  kk_std_core_types__list x_10310;
  kk_box_t _x_x1573;
  {
    struct kk_std_core_hnd_Ev* _con_x1574 = kk_std_core_hnd__as_Ev(ev_10313, _ctx);
    kk_box_t _box_x364 = _con_x1574->hnd;
    int32_t m = _con_x1574->marker;
    kk_src_dream__cycle__constellation_ops h = kk_src_dream__cycle__constellation_ops_unbox(_box_x364, KK_BORROWED, _ctx);
    kk_src_dream__cycle__constellation_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_constellation_ops* _con_x1575 = kk_src_dream__cycle__as_Hnd_constellation_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1575->_cfc;
      kk_std_core_hnd__clause2 _pat_1_1 = _con_x1575->_fun_add_to_constellation;
      kk_std_core_hnd__clause1 _fun_detect_constellations = _con_x1575->_fun_detect_constellations;
      kk_std_core_hnd__clause2 _pat_2 = _con_x1575->_fun_merge_constellations;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_detect_constellations, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x368 = _fun_detect_constellations.clause;
        _x_x1573 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x368, (_fun_unbox_x368, m, ev_10313, kk_integer_box(kk_integer_from_small(3), _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  x_10310 = kk_std_core_types__list_unbox(_x_x1573, KK_OWNED, _ctx); /*list<string>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10310, _ctx);
    kk_box_t _x_x1576 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_consolidation_fun1577(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__consolidation_result_unbox(_x_x1576, KK_OWNED, _ctx);
  }
  {
    kk_integer_t _x_x1580;
    kk_std_core_types__list _x_x1581 = kk_std_core_types__list_dup(x_10310, _ctx); /*list<string>*/
    _x_x1580 = kk_std_core_list__lift_length_5730(_x_x1581, kk_integer_from_small(0), _ctx); /*int*/
    kk_integer_t _x_x1582;
    kk_integer_t _x_x1583 = kk_std_core_list__lift_length_5730(x_10310, kk_integer_from_small(0), _ctx); /*int*/
    _x_x1582 = kk_integer_mul(_x_x1583,(kk_integer_from_small(5)),kk_context()); /*int*/
    return kk_src_dream__cycle__new_Consolidation_result(kk_reuse_null, 0, _x_x1580, _x_x1582, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1590__t {
  struct kk_function_s _base;
  kk_string_t cid;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1590(kk_function_t _fself, kk_box_t _b_x407, kk_box_t _b_x408, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10169_fun1590(kk_string_t cid, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1590__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1590__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1590, kk_context());
  _self->cid = cid;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1592__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1592(kk_function_t _fself, kk_box_t _b_x386, kk_box_t _b_x387, kk_box_t _b_x388, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10169_fun1592(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1592, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1593__t {
  struct kk_function_s _base;
};
static kk_std_core_hnd__clause1 kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1593(kk_function_t _fself, kk_box_t _b_x380, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10169_fun1593(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1593, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_hnd__clause1 kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1593(kk_function_t _fself, kk_box_t _b_x380, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__insight_ops _brw_x1108 = kk_src_dream__cycle__insight_ops_unbox(_b_x380, KK_OWNED, _ctx); /*src/dream_cycle/insight-ops<1748,1749>*/;
  kk_std_core_hnd__clause1 _brw_x1109 = kk_src_dream__cycle_create_bridge_fs__select(_brw_x1108, _ctx); /*hnd/clause1<(string, string, float64),string,src/dream_cycle/insight-ops,1748,1749>*/;
  kk_datatype_ptr_dropn(_brw_x1108, (KK_I32(4)), _ctx);
  return _brw_x1109;
}
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1592(kk_function_t _fself, kk_box_t _b_x386, kk_box_t _b_x387, kk_box_t _b_x388, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev _b_x375_394 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/insight-ops>*/;
  return kk_std_core_hnd__perform3(_b_x375_394, kk_src_dream__cycle__new_mlift_phase_serendipity_10169_fun1593(_ctx), _b_x386, _b_x387, _b_x388, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1594__t {
  struct kk_function_s _base;
  kk_integer_t acc2_413;
};
static kk_integer_t kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1594(kk_function_t _fself, kk_string_t b, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10169_fun1594(kk_integer_t acc2_413, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1594__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1594__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1594, kk_context());
  _self->acc2_413 = acc2_413;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1594(kk_function_t _fself, kk_string_t b, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1594__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1594__t*, _fself, _ctx);
  kk_integer_t acc2_413 = _self->acc2_413; /* int */
  kk_drop_match(_self, {kk_integer_dup(acc2_413, _ctx);}, {}, _ctx)
  bool _match_x1107;
  kk_string_t _x_x1595 = kk_string_empty(); /*string*/
  _match_x1107 = kk_string_is_neq(b,_x_x1595,kk_context()); /*bool*/
  if (_match_x1107) {
    return kk_integer_add_small_const(acc2_413, 1, _ctx);
  }
  {
    return acc2_413;
  }
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1599__t {
  struct kk_function_s _base;
  kk_function_t next_10317;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1599(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10169_fun1599(kk_function_t next_10317, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1599__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1599__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1599, kk_context());
  _self->next_10317 = next_10317;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1599(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1599__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1599__t*, _fself, _ctx);
  kk_function_t next_10317 = _self->next_10317; /* (string) -> <src/dream_cycle/insight-ops,src/dream_cycle/memory-ops> int */
  kk_drop_match(_self, {kk_function_dup(next_10317, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1600;
  kk_string_t _x_x1601 = kk_string_unbox(_b_x403); /*string*/
  _x_x1600 = kk_function_call(kk_integer_t, (kk_function_t, kk_string_t, kk_context_t*), next_10317, (next_10317, _x_x1601, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x1600, _ctx);
}
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1590(kk_function_t _fself, kk_box_t _b_x407, kk_box_t _b_x408, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1590__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10169_fun1590__t*, _fself, _ctx);
  kk_string_t cid = _self->cid; /* string */
  kk_drop_match(_self, {kk_string_dup(cid, _ctx);}, {}, _ctx)
  kk_integer_t acc2_413 = kk_integer_unbox(_b_x407, _ctx); /*int*/;
  kk_string_t rid_414 = kk_string_unbox(_b_x408); /*string*/;
  kk_ssize_t _b_x381_389 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_string_t x_10316;
  kk_box_t _x_x1591 = kk_std_core_hnd__open_at3(_b_x381_389, kk_src_dream__cycle__new_mlift_phase_serendipity_10169_fun1592(_ctx), kk_string_box(cid), kk_string_box(rid_414), kk_double_box(0x1.3333333333333p-1, _ctx), _ctx); /*10003*/
  x_10316 = kk_string_unbox(_x_x1591); /*string*/
  kk_function_t next_10317 = kk_src_dream__cycle__new_mlift_phase_serendipity_10169_fun1594(acc2_413, _ctx); /*(string) -> <src/dream_cycle/insight-ops,src/dream_cycle/memory-ops> int*/;
  kk_integer_t _x_x1597;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10316, _ctx);
    kk_box_t _x_x1598 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_serendipity_10169_fun1599(next_10317, _ctx), _ctx); /*10001*/
    _x_x1597 = kk_integer_unbox(_x_x1598, _ctx); /*int*/
  }
  else {
    _x_x1597 = kk_function_call(kk_integer_t, (kk_function_t, kk_string_t, kk_context_t*), next_10317, (next_10317, x_10316, _ctx), _ctx); /*int*/
  }
  return kk_integer_box(_x_x1597, _ctx);
}

kk_integer_t kk_src_dream__cycle__mlift_phase_serendipity_10169(kk_integer_t acc, kk_string_t cid, kk_std_core_types__list related, kk_context_t* _ctx) { /* (acc : int, cid : string, related : list<string>) -> <memory-ops,insight-ops> int */ 
  kk_box_t _x_x1589 = kk_std_core_list_foldl(related, kk_integer_box(acc, _ctx), kk_src_dream__cycle__new_mlift_phase_serendipity_10169_fun1590(cid, _ctx), _ctx); /*10002*/
  return kk_integer_unbox(_x_x1589, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1603__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1603(kk_function_t _fself, kk_box_t _b_x429, kk_box_t _b_x430, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10170_fun1603(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1603, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1603(kk_function_t _fself, kk_box_t _b_x429, kk_box_t _b_x430, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10322 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/insight-ops>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x1604 = kk_std_core_hnd__as_Ev(evx_10322, _ctx);
    kk_box_t _box_x415 = _con_x1604->hnd;
    int32_t m = _con_x1604->marker;
    kk_src_dream__cycle__insight_ops h = kk_src_dream__cycle__insight_ops_unbox(_box_x415, KK_BORROWED, _ctx);
    kk_src_dream__cycle__insight_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1605 = kk_src_dream__cycle__as_Hnd_insight_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1605->_cfc;
      kk_std_core_hnd__clause1 _pat_1_1 = _con_x1605->_fun_create_bridge;
      kk_std_core_hnd__clause2 _fun_emit_insight = _con_x1605->_fun_emit_insight;
      kk_std_core_hnd__clause1 _pat_2 = _con_x1605->_fun_get_serendipity_candidates;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_emit_insight, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x420 = _fun_emit_insight.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x420, (_fun_unbox_x420, m, evx_10322, _b_x429, _b_x430, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1609__t {
  struct kk_function_s _base;
  kk_integer_t bridges;
};
static kk_src_dream__cycle__serendipity_result kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1609(kk_function_t _fself, bool insights, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10170_fun1609(kk_integer_t bridges, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1609__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1609__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1609, kk_context());
  _self->bridges = bridges;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_src_dream__cycle__serendipity_result kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1609(kk_function_t _fself, bool insights, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1609__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1609__t*, _fself, _ctx);
  kk_integer_t bridges = _self->bridges; /* int */
  kk_drop_match(_self, {kk_integer_dup(bridges, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1610 = kk_integer_dup(bridges, _ctx); /*int*/
  kk_integer_t _x_x1611;
  if (insights) {
    _x_x1611 = kk_integer_from_small(3); /*int*/
  }
  else {
    _x_x1611 = kk_integer_from_small(0); /*int*/
  }
  kk_integer_t _x_x1612 = kk_integer_mul(bridges,(kk_integer_from_small(2)),kk_context()); /*int*/
  return kk_src_dream__cycle__new_Serendipity_result(kk_reuse_null, 0, _x_x1610, _x_x1611, _x_x1612, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1614__t {
  struct kk_function_s _base;
  kk_function_t next_10321;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1614(kk_function_t _fself, kk_box_t _b_x438, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10170_fun1614(kk_function_t next_10321, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1614__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1614__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1614, kk_context());
  _self->next_10321 = next_10321;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1614(kk_function_t _fself, kk_box_t _b_x438, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1614__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10170_fun1614__t*, _fself, _ctx);
  kk_function_t next_10321 = _self->next_10321; /* (bool) -> <src/dream_cycle/insight-ops,src/dream_cycle/memory-ops> src/dream_cycle/serendipity-result */
  kk_drop_match(_self, {kk_function_dup(next_10321, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__serendipity_result _x_x1615;
  bool _x_x1616 = kk_bool_unbox(_b_x438); /*bool*/
  _x_x1615 = kk_function_call(kk_src_dream__cycle__serendipity_result, (kk_function_t, bool, kk_context_t*), next_10321, (next_10321, _x_x1616, _ctx), _ctx); /*src/dream_cycle/serendipity-result*/
  return kk_src_dream__cycle__serendipity_result_box(_x_x1615, _ctx);
}

kk_src_dream__cycle__serendipity_result kk_src_dream__cycle__mlift_phase_serendipity_10170(kk_integer_t bridges, kk_context_t* _ctx) { /* (bridges : int) -> <insight-ops,memory-ops> serendipity-result */ 
  kk_ssize_t _b_x425_431 = (KK_IZ(0)); /*hnd/ev-index*/;
  bool x_10320;
  kk_box_t _x_x1602;
  kk_box_t _x_x1606;
  kk_string_t _x_x1607;
  kk_define_string_literal(, _s_x1608, 26, "Serendipity phase complete", _ctx)
  _x_x1607 = kk_string_dup(_s_x1608, _ctx); /*string*/
  _x_x1606 = kk_string_box(_x_x1607); /*10000*/
  _x_x1602 = kk_std_core_hnd__open_at2(_b_x425_431, kk_src_dream__cycle__new_mlift_phase_serendipity_10170_fun1603(_ctx), _x_x1606, kk_double_box(0x1.999999999999ap-1, _ctx), _ctx); /*10002*/
  x_10320 = kk_bool_unbox(_x_x1602); /*bool*/
  kk_function_t next_10321 = kk_src_dream__cycle__new_mlift_phase_serendipity_10170_fun1609(bridges, _ctx); /*(bool) -> <src/dream_cycle/insight-ops,src/dream_cycle/memory-ops> src/dream_cycle/serendipity-result*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1613 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_serendipity_10170_fun1614(next_10321, _ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__serendipity_result_unbox(_x_x1613, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_src_dream__cycle__serendipity_result, (kk_function_t, bool, kk_context_t*), next_10321, (next_10321, x_10320, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1618__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1618(kk_function_t _fself, kk_box_t _b_x467, kk_box_t _b_x468, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10171_fun1618(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1618, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1620__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1620(kk_function_t _fself, kk_box_t _b_x454, kk_box_t _b_x455, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10171_fun1620(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1620, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1620(kk_function_t _fself, kk_box_t _b_x454, kk_box_t _b_x455, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10332 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/memory-ops>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x1621 = kk_std_core_hnd__as_Ev(evx_10332, _ctx);
    kk_box_t _box_x440 = _con_x1621->hnd;
    int32_t m = _con_x1621->marker;
    kk_src_dream__cycle__memory_ops h = kk_src_dream__cycle__memory_ops_unbox(_box_x440, KK_BORROWED, _ctx);
    kk_src_dream__cycle__memory_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1622 = kk_src_dream__cycle__as_Hnd_memory_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1622->_cfc;
      kk_std_core_hnd__clause2 _pat_1 = _con_x1622->_fun_decay_memory;
      kk_std_core_hnd__clause2 _fun_recall_memories = _con_x1622->_fun_recall_memories;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x1622->_fun_store_memory;
      kk_std_core_hnd__clause2 _pat_3 = _con_x1622->_fun_tag_memory;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_recall_memories, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x445 = _fun_recall_memories.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x445, (_fun_unbox_x445, m, evx_10332, _b_x454, _b_x455, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1626__t {
  struct kk_function_s _base;
  kk_box_t _b_x467;
  kk_box_t _b_x468;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1626(kk_function_t _fself, kk_box_t _b_x463, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10171_fun1626(kk_box_t _b_x467, kk_box_t _b_x468, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1626__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1626__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1626, kk_context());
  _self->_b_x467 = _b_x467;
  _self->_b_x468 = _b_x468;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1626(kk_function_t _fself, kk_box_t _b_x463, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1626__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1626__t*, _fself, _ctx);
  kk_box_t _b_x467 = _self->_b_x467; /* 10002 */
  kk_box_t _b_x468 = _self->_b_x468; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_b_x467, _ctx);kk_box_dup(_b_x468, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1627;
  kk_integer_t _x_x1628 = kk_integer_unbox(_b_x467, _ctx); /*int*/
  kk_string_t _x_x1629 = kk_string_unbox(_b_x468); /*string*/
  kk_std_core_types__list _x_x1630 = kk_std_core_types__list_unbox(_b_x463, KK_OWNED, _ctx); /*list<string>*/
  _x_x1627 = kk_src_dream__cycle__mlift_phase_serendipity_10169(_x_x1628, _x_x1629, _x_x1630, _ctx); /*int*/
  return kk_integer_box(_x_x1627, _ctx);
}
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1618(kk_function_t _fself, kk_box_t _b_x467, kk_box_t _b_x468, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x450_456 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_std_core_types__list x_0_10330;
  kk_box_t _x_x1619;
  kk_box_t _x_x1623 = kk_box_dup(_b_x468, _ctx); /*10001*/
  _x_x1619 = kk_std_core_hnd__open_at2(_b_x450_456, kk_src_dream__cycle__new_mlift_phase_serendipity_10171_fun1620(_ctx), _x_x1623, kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*10002*/
  x_0_10330 = kk_std_core_types__list_unbox(_x_x1619, KK_OWNED, _ctx); /*list<string>*/
  kk_integer_t _x_x1624;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10330, _ctx);
    kk_box_t _x_x1625 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_serendipity_10171_fun1626(_b_x467, _b_x468, _ctx), _ctx); /*10001*/
    _x_x1624 = kk_integer_unbox(_x_x1625, _ctx); /*int*/
  }
  else {
    kk_integer_t _x_x1631 = kk_integer_unbox(_b_x467, _ctx); /*int*/
    kk_string_t _x_x1632 = kk_string_unbox(_b_x468); /*string*/
    _x_x1624 = kk_src_dream__cycle__mlift_phase_serendipity_10169(_x_x1631, _x_x1632, x_0_10330, _ctx); /*int*/
  }
  return kk_integer_box(_x_x1624, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1634__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1634(kk_function_t _fself, kk_box_t _b_x477, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_serendipity_10171_fun1634(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1634, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_serendipity_10171_fun1634(kk_function_t _fself, kk_box_t _b_x477, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__serendipity_result _x_x1635;
  kk_integer_t _x_x1636 = kk_integer_unbox(_b_x477, _ctx); /*int*/
  _x_x1635 = kk_src_dream__cycle__mlift_phase_serendipity_10170(_x_x1636, _ctx); /*src/dream_cycle/serendipity-result*/
  return kk_src_dream__cycle__serendipity_result_box(_x_x1635, _ctx);
}

kk_src_dream__cycle__serendipity_result kk_src_dream__cycle__mlift_phase_serendipity_10171(kk_std_core_types__list candidates, kk_context_t* _ctx) { /* (candidates : list<string>) -> <insight-ops,memory-ops> serendipity-result */ 
  kk_integer_t x_10328;
  kk_box_t _x_x1617 = kk_std_core_list_foldl(candidates, kk_integer_box(kk_integer_from_small(0), _ctx), kk_src_dream__cycle__new_mlift_phase_serendipity_10171_fun1618(_ctx), _ctx); /*10002*/
  x_10328 = kk_integer_unbox(_x_x1617, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10328, _ctx);
    kk_box_t _x_x1633 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_serendipity_10171_fun1634(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__serendipity_result_unbox(_x_x1633, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__mlift_phase_serendipity_10170(x_10328, _ctx);
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_serendipity_fun1638__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1638(kk_function_t _fself, kk_box_t _b_x490, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_serendipity_fun1638(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_serendipity_fun1638, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1638(kk_function_t _fself, kk_box_t _b_x490, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev ev_10339 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/insight-ops>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x1639 = kk_std_core_hnd__as_Ev(ev_10339, _ctx);
    kk_box_t _box_x479 = _con_x1639->hnd;
    int32_t m = _con_x1639->marker;
    kk_src_dream__cycle__insight_ops h = kk_src_dream__cycle__insight_ops_unbox(_box_x479, KK_BORROWED, _ctx);
    kk_src_dream__cycle__insight_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1640 = kk_src_dream__cycle__as_Hnd_insight_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1640->_cfc;
      kk_std_core_hnd__clause1 _pat_1_1 = _con_x1640->_fun_create_bridge;
      kk_std_core_hnd__clause2 _pat_2 = _con_x1640->_fun_emit_insight;
      kk_std_core_hnd__clause1 _fun_get_serendipity_candidates = _con_x1640->_fun_get_serendipity_candidates;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_get_serendipity_candidates, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x483 = _fun_get_serendipity_candidates.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x483, (_fun_unbox_x483, m, ev_10339, _b_x490, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_serendipity_fun1642__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1642(kk_function_t _fself, kk_box_t _b_x496, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_serendipity_fun1642(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_serendipity_fun1642, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1642(kk_function_t _fself, kk_box_t _b_x496, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__serendipity_result _x_x1643;
  kk_std_core_types__list _x_x1644 = kk_std_core_types__list_unbox(_b_x496, KK_OWNED, _ctx); /*list<string>*/
  _x_x1643 = kk_src_dream__cycle__mlift_phase_serendipity_10171(_x_x1644, _ctx); /*src/dream_cycle/serendipity-result*/
  return kk_src_dream__cycle__serendipity_result_box(_x_x1643, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_phase_serendipity_fun1646__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1646(kk_function_t _fself, kk_box_t _b_x524, kk_box_t _b_x525, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_serendipity_fun1646(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_serendipity_fun1646, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle_phase_serendipity_fun1648__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1648(kk_function_t _fself, kk_box_t _b_x511, kk_box_t _b_x512, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_serendipity_fun1648(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_serendipity_fun1648, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1648(kk_function_t _fself, kk_box_t _b_x511, kk_box_t _b_x512, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10347 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/memory-ops>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x1649 = kk_std_core_hnd__as_Ev(evx_10347, _ctx);
    kk_box_t _box_x497 = _con_x1649->hnd;
    int32_t m_0 = _con_x1649->marker;
    kk_src_dream__cycle__memory_ops h_0 = kk_src_dream__cycle__memory_ops_unbox(_box_x497, KK_BORROWED, _ctx);
    kk_src_dream__cycle__memory_ops_dup(h_0, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_memory_ops* _con_x1650 = kk_src_dream__cycle__as_Hnd_memory_ops(h_0, _ctx);
      kk_integer_t _pat_0_2 = _con_x1650->_cfc;
      kk_std_core_hnd__clause2 _pat_1_2 = _con_x1650->_fun_decay_memory;
      kk_std_core_hnd__clause2 _fun_recall_memories = _con_x1650->_fun_recall_memories;
      kk_std_core_hnd__clause2 _pat_2_1 = _con_x1650->_fun_store_memory;
      kk_std_core_hnd__clause2 _pat_3_0 = _con_x1650->_fun_tag_memory;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_1, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_recall_memories, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x502 = _fun_recall_memories.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x502, (_fun_unbox_x502, m_0, evx_10347, _b_x511, _b_x512, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_serendipity_fun1654__t {
  struct kk_function_s _base;
  kk_box_t _b_x524;
  kk_box_t _b_x525;
};
static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1654(kk_function_t _fself, kk_box_t _b_x520, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_serendipity_fun1654(kk_box_t _b_x524, kk_box_t _b_x525, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_serendipity_fun1654__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_phase_serendipity_fun1654__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_phase_serendipity_fun1654, kk_context());
  _self->_b_x524 = _b_x524;
  _self->_b_x525 = _b_x525;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1654(kk_function_t _fself, kk_box_t _b_x520, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_serendipity_fun1654__t* _self = kk_function_as(struct kk_src_dream__cycle_phase_serendipity_fun1654__t*, _fself, _ctx);
  kk_box_t _b_x524 = _self->_b_x524; /* 10002 */
  kk_box_t _b_x525 = _self->_b_x525; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_b_x524, _ctx);kk_box_dup(_b_x525, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1655;
  kk_integer_t _x_x1656 = kk_integer_unbox(_b_x524, _ctx); /*int*/
  kk_string_t _x_x1657 = kk_string_unbox(_b_x525); /*string*/
  kk_std_core_types__list _x_x1658 = kk_std_core_types__list_unbox(_b_x520, KK_OWNED, _ctx); /*list<string>*/
  _x_x1655 = kk_src_dream__cycle__mlift_phase_serendipity_10169(_x_x1656, _x_x1657, _x_x1658, _ctx); /*int*/
  return kk_integer_box(_x_x1655, _ctx);
}
static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1646(kk_function_t _fself, kk_box_t _b_x524, kk_box_t _b_x525, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t _b_x507_513 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_std_core_types__list x_2_10345;
  kk_box_t _x_x1647;
  kk_box_t _x_x1651 = kk_box_dup(_b_x525, _ctx); /*10001*/
  _x_x1647 = kk_std_core_hnd__open_at2(_b_x507_513, kk_src_dream__cycle_new_phase_serendipity_fun1648(_ctx), _x_x1651, kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*10002*/
  x_2_10345 = kk_std_core_types__list_unbox(_x_x1647, KK_OWNED, _ctx); /*list<string>*/
  kk_integer_t _x_x1652;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_2_10345, _ctx);
    kk_box_t _x_x1653 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_serendipity_fun1654(_b_x524, _b_x525, _ctx), _ctx); /*10001*/
    _x_x1652 = kk_integer_unbox(_x_x1653, _ctx); /*int*/
  }
  else {
    kk_integer_t _x_x1659 = kk_integer_unbox(_b_x524, _ctx); /*int*/
    kk_string_t _x_x1660 = kk_string_unbox(_b_x525); /*string*/
    _x_x1652 = kk_src_dream__cycle__mlift_phase_serendipity_10169(_x_x1659, _x_x1660, x_2_10345, _ctx); /*int*/
  }
  return kk_integer_box(_x_x1652, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_phase_serendipity_fun1662__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1662(kk_function_t _fself, kk_box_t _b_x534, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_serendipity_fun1662(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_serendipity_fun1662, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1662(kk_function_t _fself, kk_box_t _b_x534, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__serendipity_result _x_x1663;
  kk_integer_t _x_x1664 = kk_integer_unbox(_b_x534, _ctx); /*int*/
  _x_x1663 = kk_src_dream__cycle__mlift_phase_serendipity_10170(_x_x1664, _ctx); /*src/dream_cycle/serendipity-result*/
  return kk_src_dream__cycle__serendipity_result_box(_x_x1663, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_phase_serendipity_fun1666__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1666(kk_function_t _fself, kk_box_t _b_x549, kk_box_t _b_x550, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_serendipity_fun1666(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_serendipity_fun1666, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1666(kk_function_t _fself, kk_box_t _b_x549, kk_box_t _b_x550, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_0_10354 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/insight-ops>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x1667 = kk_std_core_hnd__as_Ev(evx_0_10354, _ctx);
    kk_box_t _box_x535 = _con_x1667->hnd;
    int32_t m_1 = _con_x1667->marker;
    kk_src_dream__cycle__insight_ops h_1 = kk_src_dream__cycle__insight_ops_unbox(_box_x535, KK_BORROWED, _ctx);
    kk_src_dream__cycle__insight_ops_dup(h_1, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_insight_ops* _con_x1668 = kk_src_dream__cycle__as_Hnd_insight_ops(h_1, _ctx);
      kk_integer_t _pat_0_4 = _con_x1668->_cfc;
      kk_std_core_hnd__clause1 _pat_1_3 = _con_x1668->_fun_create_bridge;
      kk_std_core_hnd__clause2 _fun_emit_insight = _con_x1668->_fun_emit_insight;
      kk_std_core_hnd__clause1 _pat_2_2 = _con_x1668->_fun_get_serendipity_candidates;
      if kk_likely(kk_datatype_ptr_is_unique(h_1, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_2, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_3, _ctx);
        kk_integer_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(h_1, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_emit_insight, _ctx);
        kk_datatype_ptr_decref(h_1, _ctx);
      }
      {
        kk_function_t _fun_unbox_x540 = _fun_emit_insight.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x540, (_fun_unbox_x540, m_1, evx_0_10354, _b_x549, _b_x550, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_serendipity_fun1673__t {
  struct kk_function_s _base;
  kk_integer_t x_1_10342;
};
static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1673(kk_function_t _fself, kk_box_t _b_x558, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_serendipity_fun1673(kk_integer_t x_1_10342, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_serendipity_fun1673__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_phase_serendipity_fun1673__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_phase_serendipity_fun1673, kk_context());
  _self->x_1_10342 = x_1_10342;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_serendipity_fun1673(kk_function_t _fself, kk_box_t _b_x558, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_serendipity_fun1673__t* _self = kk_function_as(struct kk_src_dream__cycle_phase_serendipity_fun1673__t*, _fself, _ctx);
  kk_integer_t x_1_10342 = _self->x_1_10342; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_1_10342, _ctx);}, {}, _ctx)
  bool insights_562 = kk_bool_unbox(_b_x558); /*bool*/;
  kk_src_dream__cycle__serendipity_result _x_x1674;
  kk_integer_t _x_x1675 = kk_integer_dup(x_1_10342, _ctx); /*int*/
  kk_integer_t _x_x1676;
  if (insights_562) {
    _x_x1676 = kk_integer_from_small(3); /*int*/
  }
  else {
    _x_x1676 = kk_integer_from_small(0); /*int*/
  }
  kk_integer_t _x_x1677 = kk_integer_mul(x_1_10342,(kk_integer_from_small(2)),kk_context()); /*int*/
  _x_x1674 = kk_src_dream__cycle__new_Serendipity_result(kk_reuse_null, 0, _x_x1675, _x_x1676, _x_x1677, _ctx); /*src/dream_cycle/serendipity-result*/
  return kk_src_dream__cycle__serendipity_result_box(_x_x1674, _ctx);
}

kk_src_dream__cycle__serendipity_result kk_src_dream__cycle_phase_serendipity(kk_context_t* _ctx) { /* () -> <insight-ops,memory-ops> serendipity-result */ 
  kk_ssize_t _b_x487_491 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_std_core_types__list x_10336;
  kk_box_t _x_x1637 = kk_std_core_hnd__open_at1(_b_x487_491, kk_src_dream__cycle_new_phase_serendipity_fun1638(_ctx), kk_integer_box(kk_integer_from_small(10), _ctx), _ctx); /*10001*/
  x_10336 = kk_std_core_types__list_unbox(_x_x1637, KK_OWNED, _ctx); /*list<string>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10336, _ctx);
    kk_box_t _x_x1641 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_serendipity_fun1642(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__serendipity_result_unbox(_x_x1641, KK_OWNED, _ctx);
  }
  {
    kk_integer_t x_1_10342;
    kk_box_t _x_x1645 = kk_std_core_list_foldl(x_10336, kk_integer_box(kk_integer_from_small(0), _ctx), kk_src_dream__cycle_new_phase_serendipity_fun1646(_ctx), _ctx); /*10002*/
    x_1_10342 = kk_integer_unbox(_x_x1645, _ctx); /*int*/
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_1_10342, _ctx);
      kk_box_t _x_x1661 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_serendipity_fun1662(_ctx), _ctx); /*10001*/
      return kk_src_dream__cycle__serendipity_result_unbox(_x_x1661, KK_OWNED, _ctx);
    }
    {
      kk_ssize_t _b_x545_551 = (KK_IZ(0)); /*hnd/ev-index*/;
      bool x_4_10351;
      kk_box_t _x_x1665;
      kk_box_t _x_x1669;
      kk_string_t _x_x1670;
      kk_define_string_literal(, _s_x1671, 26, "Serendipity phase complete", _ctx)
      _x_x1670 = kk_string_dup(_s_x1671, _ctx); /*string*/
      _x_x1669 = kk_string_box(_x_x1670); /*10000*/
      _x_x1665 = kk_std_core_hnd__open_at2(_b_x545_551, kk_src_dream__cycle_new_phase_serendipity_fun1666(_ctx), _x_x1669, kk_double_box(0x1.999999999999ap-1, _ctx), _ctx); /*10002*/
      x_4_10351 = kk_bool_unbox(_x_x1665); /*bool*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1672 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_serendipity_fun1673(x_1_10342, _ctx), _ctx); /*10001*/
        return kk_src_dream__cycle__serendipity_result_unbox(_x_x1672, KK_OWNED, _ctx);
      }
      {
        kk_integer_t _x_x1678 = kk_integer_dup(x_1_10342, _ctx); /*int*/
        kk_integer_t _x_x1679;
        if (x_4_10351) {
          _x_x1679 = kk_integer_from_small(3); /*int*/
        }
        else {
          _x_x1679 = kk_integer_from_small(0); /*int*/
        }
        kk_integer_t _x_x1680 = kk_integer_mul(x_1_10342,(kk_integer_from_small(2)),kk_context()); /*int*/
        return kk_src_dream__cycle__new_Serendipity_result(kk_reuse_null, 0, _x_x1678, _x_x1679, _x_x1680, _ctx);
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_governance_10173_fun1686__t {
  struct kk_function_s _base;
  kk_std_core_types__list chambers;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_governance_10173_fun1686(kk_function_t _fself, kk_box_t _b_x570, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_governance_10173_fun1686(kk_std_core_types__list chambers, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_governance_10173_fun1686__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_governance_10173_fun1686__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_governance_10173_fun1686, kk_context());
  _self->chambers = chambers;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_governance_10173_fun1686(kk_function_t _fself, kk_box_t _b_x570, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_governance_10173_fun1686__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_governance_10173_fun1686__t*, _fself, _ctx);
  kk_std_core_types__list chambers = _self->chambers; /* list<string> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(chambers, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__governance_result _x_x1687;
  double health_572 = kk_double_unbox(_b_x570, KK_OWNED, _ctx); /*float64*/;
  kk_integer_t _x_x1688 = kk_std_core_list__lift_length_5730(chambers, kk_integer_from_small(0), _ctx); /*int*/
  _x_x1687 = kk_src_dream__cycle__new_Governance_result(kk_reuse_null, 0, kk_integer_from_small(181), _x_x1688, health_572, _ctx); /*src/dream_cycle/governance-result*/
  return kk_src_dream__cycle__governance_result_box(_x_x1687, _ctx);
}

kk_src_dream__cycle__governance_result kk_src_dream__cycle__mlift_phase_governance_10173(kk_std_core_types__list chambers, kk_context_t* _ctx) { /* (chambers : list<string>) -> governance-ops governance-result */ 
  kk_std_core_hnd__ev ev_10362 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/governance-ops>*/;
  double x_10360;
  kk_box_t _x_x1682;
  {
    struct kk_std_core_hnd_Ev* _con_x1683 = kk_std_core_hnd__as_Ev(ev_10362, _ctx);
    kk_box_t _box_x563 = _con_x1683->hnd;
    int32_t m = _con_x1683->marker;
    kk_src_dream__cycle__governance_ops h = kk_src_dream__cycle__governance_ops_unbox(_box_x563, KK_BORROWED, _ctx);
    kk_src_dream__cycle__governance_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1684 = kk_src_dream__cycle__as_Hnd_governance_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1684->_cfc;
      kk_std_core_hnd__clause1 _pat_1_1 = _con_x1684->_fun_check_echo_chambers;
      kk_std_core_hnd__clause0 _fun_get_community_health = _con_x1684->_fun_get_community_health;
      kk_std_core_hnd__clause1 _pat_2 = _con_x1684->_fun_rebalance_community;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_community_health, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x566 = _fun_get_community_health.clause;
        _x_x1682 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x566, (_fun_unbox_x566, m, ev_10362, _ctx), _ctx); /*10005*/
      }
    }
  }
  x_10360 = kk_double_unbox(_x_x1682, KK_OWNED, _ctx); /*float64*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1685 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_governance_10173_fun1686(chambers, _ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__governance_result_unbox(_x_x1685, KK_OWNED, _ctx);
  }
  {
    double health_573 = x_10360; /*float64*/;
    kk_integer_t _x_x1689 = kk_std_core_list__lift_length_5730(chambers, kk_integer_from_small(0), _ctx); /*int*/
    return kk_src_dream__cycle__new_Governance_result(kk_reuse_null, 0, kk_integer_from_small(181), _x_x1689, health_573, _ctx);
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_governance_fun1694__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_governance_fun1694(kk_function_t _fself, kk_box_t _b_x583, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_governance_fun1694(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_governance_fun1694, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_governance_fun1694(kk_function_t _fself, kk_box_t _b_x583, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__governance_result _x_x1695;
  kk_std_core_types__list _x_x1696 = kk_std_core_types__list_unbox(_b_x583, KK_OWNED, _ctx); /*list<string>*/
  _x_x1695 = kk_src_dream__cycle__mlift_phase_governance_10173(_x_x1696, _ctx); /*src/dream_cycle/governance-result*/
  return kk_src_dream__cycle__governance_result_box(_x_x1695, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_phase_governance_fun1701__t {
  struct kk_function_s _base;
  kk_std_core_types__list x_10366;
};
static kk_box_t kk_src_dream__cycle_phase_governance_fun1701(kk_function_t _fself, kk_box_t _b_x591, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_governance_fun1701(kk_std_core_types__list x_10366, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_governance_fun1701__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_phase_governance_fun1701__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_phase_governance_fun1701, kk_context());
  _self->x_10366 = x_10366;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_governance_fun1701(kk_function_t _fself, kk_box_t _b_x591, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_governance_fun1701__t* _self = kk_function_as(struct kk_src_dream__cycle_phase_governance_fun1701__t*, _fself, _ctx);
  kk_std_core_types__list x_10366 = _self->x_10366; /* list<string> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(x_10366, _ctx);}, {}, _ctx)
  double health_594 = kk_double_unbox(_b_x591, KK_OWNED, _ctx); /*float64*/;
  kk_src_dream__cycle__governance_result _x_x1702;
  kk_integer_t _x_x1703 = kk_std_core_list__lift_length_5730(x_10366, kk_integer_from_small(0), _ctx); /*int*/
  _x_x1702 = kk_src_dream__cycle__new_Governance_result(kk_reuse_null, 0, kk_integer_from_small(181), _x_x1703, health_594, _ctx); /*src/dream_cycle/governance-result*/
  return kk_src_dream__cycle__governance_result_box(_x_x1702, _ctx);
}

kk_src_dream__cycle__governance_result kk_src_dream__cycle_phase_governance(kk_context_t* _ctx) { /* () -> governance-ops governance-result */ 
  kk_std_core_hnd__ev ev_10369 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/governance-ops>*/;
  kk_std_core_types__list x_10366;
  kk_box_t _x_x1690;
  {
    struct kk_std_core_hnd_Ev* _con_x1691 = kk_std_core_hnd__as_Ev(ev_10369, _ctx);
    kk_box_t _box_x574 = _con_x1691->hnd;
    int32_t m = _con_x1691->marker;
    kk_src_dream__cycle__governance_ops h = kk_src_dream__cycle__governance_ops_unbox(_box_x574, KK_BORROWED, _ctx);
    kk_src_dream__cycle__governance_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1692 = kk_src_dream__cycle__as_Hnd_governance_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1692->_cfc;
      kk_std_core_hnd__clause1 _fun_check_echo_chambers = _con_x1692->_fun_check_echo_chambers;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x1692->_fun_get_community_health;
      kk_std_core_hnd__clause1 _pat_2 = _con_x1692->_fun_rebalance_community;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_check_echo_chambers, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x578 = _fun_check_echo_chambers.clause;
        _x_x1690 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x578, (_fun_unbox_x578, m, ev_10369, kk_double_box(0x1.b333333333333p-1, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  x_10366 = kk_std_core_types__list_unbox(_x_x1690, KK_OWNED, _ctx); /*list<string>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10366, _ctx);
    kk_box_t _x_x1693 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_governance_fun1694(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__governance_result_unbox(_x_x1693, KK_OWNED, _ctx);
  }
  {
    kk_std_core_hnd__ev ev_0_10375 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/governance-ops>*/;
    double x_1_10372;
    kk_box_t _x_x1697;
    {
      struct kk_std_core_hnd_Ev* _con_x1698 = kk_std_core_hnd__as_Ev(ev_0_10375, _ctx);
      kk_box_t _box_x584 = _con_x1698->hnd;
      int32_t m_0 = _con_x1698->marker;
      kk_src_dream__cycle__governance_ops h_0 = kk_src_dream__cycle__governance_ops_unbox(_box_x584, KK_BORROWED, _ctx);
      kk_src_dream__cycle__governance_ops_dup(h_0, _ctx);
      {
        struct kk_src_dream__cycle__Hnd_governance_ops* _con_x1699 = kk_src_dream__cycle__as_Hnd_governance_ops(h_0, _ctx);
        kk_integer_t _pat_0_3 = _con_x1699->_cfc;
        kk_std_core_hnd__clause1 _pat_1_2 = _con_x1699->_fun_check_echo_chambers;
        kk_std_core_hnd__clause0 _fun_get_community_health = _con_x1699->_fun_get_community_health;
        kk_std_core_hnd__clause1 _pat_2_1 = _con_x1699->_fun_rebalance_community;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_1_2, _ctx);
          kk_integer_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause0_dup(_fun_get_community_health, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x587 = _fun_get_community_health.clause;
          _x_x1697 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x587, (_fun_unbox_x587, m_0, ev_0_10375, _ctx), _ctx); /*10005*/
        }
      }
    }
    x_1_10372 = kk_double_unbox(_x_x1697, KK_OWNED, _ctx); /*float64*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1700 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_governance_fun1701(x_10366, _ctx), _ctx); /*10001*/
      return kk_src_dream__cycle__governance_result_unbox(_x_x1700, KK_OWNED, _ctx);
    }
    {
      kk_integer_t _x_x1704 = kk_std_core_list__lift_length_5730(x_10366, kk_integer_from_small(0), _ctx); /*int*/
      return kk_src_dream__cycle__new_Governance_result(kk_reuse_null, 0, kk_integer_from_small(181), _x_x1704, x_1_10372, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1710__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_narrative_10176_fun1710(kk_function_t _fself, kk_box_t _b_x608, kk_box_t _b_x609, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_narrative_10176_fun1710(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_phase_narrative_10176_fun1710, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1716__t {
  struct kk_function_s _base;
  kk_box_t _b_x608;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_narrative_10176_fun1716(kk_function_t _fself, kk_box_t _b_x604, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_narrative_10176_fun1716(kk_box_t _b_x608, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1716__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1716__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_narrative_10176_fun1716, kk_context());
  _self->_b_x608 = _b_x608;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_narrative_10176_fun1716(kk_function_t _fself, kk_box_t _b_x604, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1716__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1716__t*, _fself, _ctx);
  kk_box_t _b_x608 = _self->_b_x608; /* 10002 */
  kk_drop_match(_self, {kk_box_dup(_b_x608, _ctx);}, {}, _ctx)
  kk_box_drop(_b_x604, _ctx);
  kk_integer_t _x_x1717;
  kk_integer_t _x_x1718 = kk_integer_unbox(_b_x608, _ctx); /*int*/
  _x_x1717 = kk_integer_add_small_const(_x_x1718, 1, _ctx); /*int*/
  return kk_integer_box(_x_x1717, _ctx);
}
static kk_box_t kk_src_dream__cycle__mlift_phase_narrative_10176_fun1710(kk_function_t _fself, kk_box_t _b_x608, kk_box_t _b_x609, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev ev_10383 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/narrative-ops>*/;
  kk_string_t x_0_10381;
  kk_box_t _x_x1711;
  {
    struct kk_std_core_hnd_Ev* _con_x1712 = kk_std_core_hnd__as_Ev(ev_10383, _ctx);
    kk_box_t _box_x595 = _con_x1712->hnd;
    int32_t m = _con_x1712->marker;
    kk_src_dream__cycle__narrative_ops h = kk_src_dream__cycle__narrative_ops_unbox(_box_x595, KK_BORROWED, _ctx);
    kk_src_dream__cycle__narrative_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1713 = kk_src_dream__cycle__as_Hnd_narrative_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1713->_cfc;
      kk_std_core_hnd__clause1 _pat_1 = _con_x1713->_fun_cluster_narratives;
      kk_std_core_hnd__clause1 _fun_compress_narrative = _con_x1713->_fun_compress_narrative;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1713->_fun_get_narrative_threads;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_compress_narrative, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x599 = _fun_compress_narrative.clause;
        _x_x1711 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x599, (_fun_unbox_x599, m, ev_10383, _b_x609, _ctx), _ctx); /*10010*/
      }
    }
  }
  x_0_10381 = kk_string_unbox(_x_x1711); /*string*/
  kk_string_drop(x_0_10381, _ctx);
  kk_integer_t _x_x1714;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1715 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_narrative_10176_fun1716(_b_x608, _ctx), _ctx); /*10001*/
    _x_x1714 = kk_integer_unbox(_x_x1715, _ctx); /*int*/
  }
  else {
    kk_integer_t _x_x1719 = kk_integer_unbox(_b_x608, _ctx); /*int*/
    _x_x1714 = kk_integer_add_small_const(_x_x1719, 1, _ctx); /*int*/
  }
  return kk_integer_box(_x_x1714, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1720__t {
  struct kk_function_s _base;
  kk_std_core_types__list clusters;
};
static kk_src_dream__cycle__narrative_result kk_src_dream__cycle__mlift_phase_narrative_10176_fun1720(kk_function_t _fself, kk_integer_t narratives, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_narrative_10176_fun1720(kk_std_core_types__list clusters, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1720__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1720__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_narrative_10176_fun1720, kk_context());
  _self->clusters = clusters;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_src_dream__cycle__narrative_result kk_src_dream__cycle__mlift_phase_narrative_10176_fun1720(kk_function_t _fself, kk_integer_t narratives, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1720__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1720__t*, _fself, _ctx);
  kk_std_core_types__list clusters = _self->clusters; /* list<string> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(clusters, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1721 = kk_std_core_list__lift_length_5730(clusters, kk_integer_from_small(0), _ctx); /*int*/
  kk_integer_t _x_x1722 = kk_integer_dup(narratives, _ctx); /*int*/
  kk_integer_t _x_x1723 = kk_integer_mul(narratives,(kk_integer_from_small(30)),kk_context()); /*int*/
  return kk_src_dream__cycle__new_Narrative_result(kk_reuse_null, 0, _x_x1721, _x_x1722, _x_x1723, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1725__t {
  struct kk_function_s _base;
  kk_function_t next_10380;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_narrative_10176_fun1725(kk_function_t _fself, kk_box_t _b_x618, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_narrative_10176_fun1725(kk_function_t next_10380, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1725__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1725__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_narrative_10176_fun1725, kk_context());
  _self->next_10380 = next_10380;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_narrative_10176_fun1725(kk_function_t _fself, kk_box_t _b_x618, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1725__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_narrative_10176_fun1725__t*, _fself, _ctx);
  kk_function_t next_10380 = _self->next_10380; /* (int) -> src/dream_cycle/narrative-ops src/dream_cycle/narrative-result */
  kk_drop_match(_self, {kk_function_dup(next_10380, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__narrative_result _x_x1726;
  kk_integer_t _x_x1727 = kk_integer_unbox(_b_x618, _ctx); /*int*/
  _x_x1726 = kk_function_call(kk_src_dream__cycle__narrative_result, (kk_function_t, kk_integer_t, kk_context_t*), next_10380, (next_10380, _x_x1727, _ctx), _ctx); /*src/dream_cycle/narrative-result*/
  return kk_src_dream__cycle__narrative_result_box(_x_x1726, _ctx);
}

kk_src_dream__cycle__narrative_result kk_src_dream__cycle__mlift_phase_narrative_10176(kk_std_core_types__list clusters, kk_context_t* _ctx) { /* (clusters : list<string>) -> narrative-ops narrative-result */ 
  kk_integer_t x_10379;
  kk_box_t _x_x1708;
  kk_std_core_types__list _x_x1709 = kk_std_core_types__list_dup(clusters, _ctx); /*list<string>*/
  _x_x1708 = kk_std_core_list_foldl(_x_x1709, kk_integer_box(kk_integer_from_small(0), _ctx), kk_src_dream__cycle__new_mlift_phase_narrative_10176_fun1710(_ctx), _ctx); /*10002*/
  x_10379 = kk_integer_unbox(_x_x1708, _ctx); /*int*/
  kk_function_t next_10380 = kk_src_dream__cycle__new_mlift_phase_narrative_10176_fun1720(clusters, _ctx); /*(int) -> src/dream_cycle/narrative-ops src/dream_cycle/narrative-result*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10379, _ctx);
    kk_box_t _x_x1724 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_narrative_10176_fun1725(next_10380, _ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__narrative_result_unbox(_x_x1724, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_src_dream__cycle__narrative_result, (kk_function_t, kk_integer_t, kk_context_t*), next_10380, (next_10380, x_10379, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_narrative_10177_fun1732__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_narrative_10177_fun1732(kk_function_t _fself, kk_box_t _b_x629, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_narrative_10177_fun1732(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_phase_narrative_10177_fun1732, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_narrative_10177_fun1732(kk_function_t _fself, kk_box_t _b_x629, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__narrative_result _x_x1733;
  kk_std_core_types__list _x_x1734 = kk_std_core_types__list_unbox(_b_x629, KK_OWNED, _ctx); /*list<string>*/
  _x_x1733 = kk_src_dream__cycle__mlift_phase_narrative_10176(_x_x1734, _ctx); /*src/dream_cycle/narrative-result*/
  return kk_src_dream__cycle__narrative_result_box(_x_x1733, _ctx);
}

kk_src_dream__cycle__narrative_result kk_src_dream__cycle__mlift_phase_narrative_10177(kk_std_core_types__list threads, kk_context_t* _ctx) { /* (threads : list<string>) -> narrative-ops narrative-result */ 
  kk_std_core_hnd__ev ev_10392 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/narrative-ops>*/;
  kk_std_core_types__list x_10390;
  kk_box_t _x_x1728;
  {
    struct kk_std_core_hnd_Ev* _con_x1729 = kk_std_core_hnd__as_Ev(ev_10392, _ctx);
    kk_box_t _box_x620 = _con_x1729->hnd;
    int32_t m = _con_x1729->marker;
    kk_src_dream__cycle__narrative_ops h = kk_src_dream__cycle__narrative_ops_unbox(_box_x620, KK_BORROWED, _ctx);
    kk_src_dream__cycle__narrative_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1730 = kk_src_dream__cycle__as_Hnd_narrative_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1730->_cfc;
      kk_std_core_hnd__clause1 _fun_cluster_narratives = _con_x1730->_fun_cluster_narratives;
      kk_std_core_hnd__clause1 _pat_1_1 = _con_x1730->_fun_compress_narrative;
      kk_std_core_hnd__clause1 _pat_2 = _con_x1730->_fun_get_narrative_threads;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_cluster_narratives, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x624 = _fun_cluster_narratives.clause;
        _x_x1728 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x624, (_fun_unbox_x624, m, ev_10392, kk_std_core_types__list_box(threads, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  x_10390 = kk_std_core_types__list_unbox(_x_x1728, KK_OWNED, _ctx); /*list<string>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10390, _ctx);
    kk_box_t _x_x1731 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_narrative_10177_fun1732(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__narrative_result_unbox(_x_x1731, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__mlift_phase_narrative_10176(x_10390, _ctx);
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_narrative_fun1739__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_narrative_fun1739(kk_function_t _fself, kk_box_t _b_x640, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_narrative_fun1739(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_narrative_fun1739, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_narrative_fun1739(kk_function_t _fself, kk_box_t _b_x640, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__narrative_result _x_x1740;
  kk_std_core_types__list _x_x1741 = kk_std_core_types__list_unbox(_b_x640, KK_OWNED, _ctx); /*list<string>*/
  _x_x1740 = kk_src_dream__cycle__mlift_phase_narrative_10177(_x_x1741, _ctx); /*src/dream_cycle/narrative-result*/
  return kk_src_dream__cycle__narrative_result_box(_x_x1740, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_phase_narrative_fun1746__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_narrative_fun1746(kk_function_t _fself, kk_box_t _b_x650, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_narrative_fun1746(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_narrative_fun1746, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_narrative_fun1746(kk_function_t _fself, kk_box_t _b_x650, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__narrative_result _x_x1747;
  kk_std_core_types__list _x_x1748 = kk_std_core_types__list_unbox(_b_x650, KK_OWNED, _ctx); /*list<string>*/
  _x_x1747 = kk_src_dream__cycle__mlift_phase_narrative_10176(_x_x1748, _ctx); /*src/dream_cycle/narrative-result*/
  return kk_src_dream__cycle__narrative_result_box(_x_x1747, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_phase_narrative_fun1751__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_narrative_fun1751(kk_function_t _fself, kk_box_t _b_x664, kk_box_t _b_x665, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_narrative_fun1751(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_narrative_fun1751, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle_phase_narrative_fun1757__t {
  struct kk_function_s _base;
  kk_box_t _b_x664;
};
static kk_box_t kk_src_dream__cycle_phase_narrative_fun1757(kk_function_t _fself, kk_box_t _b_x660, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_narrative_fun1757(kk_box_t _b_x664, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_narrative_fun1757__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_phase_narrative_fun1757__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_phase_narrative_fun1757, kk_context());
  _self->_b_x664 = _b_x664;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_narrative_fun1757(kk_function_t _fself, kk_box_t _b_x660, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_narrative_fun1757__t* _self = kk_function_as(struct kk_src_dream__cycle_phase_narrative_fun1757__t*, _fself, _ctx);
  kk_box_t _b_x664 = _self->_b_x664; /* 10002 */
  kk_drop_match(_self, {kk_box_dup(_b_x664, _ctx);}, {}, _ctx)
  kk_box_drop(_b_x660, _ctx);
  kk_integer_t _x_x1758;
  kk_integer_t _x_x1759 = kk_integer_unbox(_b_x664, _ctx); /*int*/
  _x_x1758 = kk_integer_add_small_const(_x_x1759, 1, _ctx); /*int*/
  return kk_integer_box(_x_x1758, _ctx);
}
static kk_box_t kk_src_dream__cycle_phase_narrative_fun1751(kk_function_t _fself, kk_box_t _b_x664, kk_box_t _b_x665, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev ev_1_10412 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/narrative-ops>*/;
  kk_string_t x_4_10410;
  kk_box_t _x_x1752;
  {
    struct kk_std_core_hnd_Ev* _con_x1753 = kk_std_core_hnd__as_Ev(ev_1_10412, _ctx);
    kk_box_t _box_x651 = _con_x1753->hnd;
    int32_t m_1 = _con_x1753->marker;
    kk_src_dream__cycle__narrative_ops h_1 = kk_src_dream__cycle__narrative_ops_unbox(_box_x651, KK_BORROWED, _ctx);
    kk_src_dream__cycle__narrative_ops_dup(h_1, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1754 = kk_src_dream__cycle__as_Hnd_narrative_ops(h_1, _ctx);
      kk_integer_t _pat_0_4 = _con_x1754->_cfc;
      kk_std_core_hnd__clause1 _pat_1_3 = _con_x1754->_fun_cluster_narratives;
      kk_std_core_hnd__clause1 _fun_compress_narrative = _con_x1754->_fun_compress_narrative;
      kk_std_core_hnd__clause1 _pat_2_2 = _con_x1754->_fun_get_narrative_threads;
      if kk_likely(kk_datatype_ptr_is_unique(h_1, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_2, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_3, _ctx);
        kk_integer_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(h_1, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_compress_narrative, _ctx);
        kk_datatype_ptr_decref(h_1, _ctx);
      }
      {
        kk_function_t _fun_unbox_x655 = _fun_compress_narrative.clause;
        _x_x1752 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x655, (_fun_unbox_x655, m_1, ev_1_10412, _b_x665, _ctx), _ctx); /*10010*/
      }
    }
  }
  x_4_10410 = kk_string_unbox(_x_x1752); /*string*/
  kk_string_drop(x_4_10410, _ctx);
  kk_integer_t _x_x1755;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1756 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_narrative_fun1757(_b_x664, _ctx), _ctx); /*10001*/
    _x_x1755 = kk_integer_unbox(_x_x1756, _ctx); /*int*/
  }
  else {
    kk_integer_t _x_x1760 = kk_integer_unbox(_b_x664, _ctx); /*int*/
    _x_x1755 = kk_integer_add_small_const(_x_x1760, 1, _ctx); /*int*/
  }
  return kk_integer_box(_x_x1755, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_phase_narrative_fun1762__t {
  struct kk_function_s _base;
  kk_std_core_types__list x_1_10401;
};
static kk_box_t kk_src_dream__cycle_phase_narrative_fun1762(kk_function_t _fself, kk_box_t _b_x674, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_narrative_fun1762(kk_std_core_types__list x_1_10401, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_narrative_fun1762__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_phase_narrative_fun1762__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_phase_narrative_fun1762, kk_context());
  _self->x_1_10401 = x_1_10401;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_narrative_fun1762(kk_function_t _fself, kk_box_t _b_x674, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_narrative_fun1762__t* _self = kk_function_as(struct kk_src_dream__cycle_phase_narrative_fun1762__t*, _fself, _ctx);
  kk_std_core_types__list x_1_10401 = _self->x_1_10401; /* list<string> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(x_1_10401, _ctx);}, {}, _ctx)
  kk_integer_t narratives_678 = kk_integer_unbox(_b_x674, _ctx); /*int*/;
  kk_src_dream__cycle__narrative_result _x_x1763;
  kk_integer_t _x_x1764 = kk_std_core_list__lift_length_5730(x_1_10401, kk_integer_from_small(0), _ctx); /*int*/
  kk_integer_t _x_x1765 = kk_integer_dup(narratives_678, _ctx); /*int*/
  kk_integer_t _x_x1766 = kk_integer_mul(narratives_678,(kk_integer_from_small(30)),kk_context()); /*int*/
  _x_x1763 = kk_src_dream__cycle__new_Narrative_result(kk_reuse_null, 0, _x_x1764, _x_x1765, _x_x1766, _ctx); /*src/dream_cycle/narrative-result*/
  return kk_src_dream__cycle__narrative_result_box(_x_x1763, _ctx);
}

kk_src_dream__cycle__narrative_result kk_src_dream__cycle_phase_narrative(kk_context_t* _ctx) { /* () -> narrative-ops narrative-result */ 
  kk_std_core_hnd__ev ev_10398 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/narrative-ops>*/;
  kk_std_core_types__list x_10395;
  kk_box_t _x_x1735;
  {
    struct kk_std_core_hnd_Ev* _con_x1736 = kk_std_core_hnd__as_Ev(ev_10398, _ctx);
    kk_box_t _box_x631 = _con_x1736->hnd;
    int32_t m = _con_x1736->marker;
    kk_src_dream__cycle__narrative_ops h = kk_src_dream__cycle__narrative_ops_unbox(_box_x631, KK_BORROWED, _ctx);
    kk_src_dream__cycle__narrative_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1737 = kk_src_dream__cycle__as_Hnd_narrative_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1737->_cfc;
      kk_std_core_hnd__clause1 _pat_1_1 = _con_x1737->_fun_cluster_narratives;
      kk_std_core_hnd__clause1 _pat_2 = _con_x1737->_fun_compress_narrative;
      kk_std_core_hnd__clause1 _fun_get_narrative_threads = _con_x1737->_fun_get_narrative_threads;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_get_narrative_threads, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x635 = _fun_get_narrative_threads.clause;
        _x_x1735 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x635, (_fun_unbox_x635, m, ev_10398, kk_integer_box(kk_integer_from_small(20), _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  x_10395 = kk_std_core_types__list_unbox(_x_x1735, KK_OWNED, _ctx); /*list<string>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10395, _ctx);
    kk_box_t _x_x1738 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_narrative_fun1739(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__narrative_result_unbox(_x_x1738, KK_OWNED, _ctx);
  }
  {
    kk_std_core_hnd__ev ev_0_10404 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/narrative-ops>*/;
    kk_std_core_types__list x_1_10401;
    kk_box_t _x_x1742;
    {
      struct kk_std_core_hnd_Ev* _con_x1743 = kk_std_core_hnd__as_Ev(ev_0_10404, _ctx);
      kk_box_t _box_x641 = _con_x1743->hnd;
      int32_t m_0 = _con_x1743->marker;
      kk_src_dream__cycle__narrative_ops h_0 = kk_src_dream__cycle__narrative_ops_unbox(_box_x641, KK_BORROWED, _ctx);
      kk_src_dream__cycle__narrative_ops_dup(h_0, _ctx);
      {
        struct kk_src_dream__cycle__Hnd_narrative_ops* _con_x1744 = kk_src_dream__cycle__as_Hnd_narrative_ops(h_0, _ctx);
        kk_integer_t _pat_0_3 = _con_x1744->_cfc;
        kk_std_core_hnd__clause1 _fun_cluster_narratives = _con_x1744->_fun_cluster_narratives;
        kk_std_core_hnd__clause1 _pat_1_2 = _con_x1744->_fun_compress_narrative;
        kk_std_core_hnd__clause1 _pat_2_1 = _con_x1744->_fun_get_narrative_threads;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_1_2, _ctx);
          kk_integer_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_fun_cluster_narratives, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x645 = _fun_cluster_narratives.clause;
          _x_x1742 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x645, (_fun_unbox_x645, m_0, ev_0_10404, kk_std_core_types__list_box(x_10395, _ctx), _ctx), _ctx); /*10010*/
        }
      }
    }
    x_1_10401 = kk_std_core_types__list_unbox(_x_x1742, KK_OWNED, _ctx); /*list<string>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_1_10401, _ctx);
      kk_box_t _x_x1745 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_narrative_fun1746(_ctx), _ctx); /*10001*/
      return kk_src_dream__cycle__narrative_result_unbox(_x_x1745, KK_OWNED, _ctx);
    }
    {
      kk_integer_t x_3_10407;
      kk_box_t _x_x1749;
      kk_std_core_types__list _x_x1750 = kk_std_core_types__list_dup(x_1_10401, _ctx); /*list<string>*/
      _x_x1749 = kk_std_core_list_foldl(_x_x1750, kk_integer_box(kk_integer_from_small(0), _ctx), kk_src_dream__cycle_new_phase_narrative_fun1751(_ctx), _ctx); /*10002*/
      x_3_10407 = kk_integer_unbox(_x_x1749, _ctx); /*int*/
      if (kk_yielding(kk_context())) {
        kk_integer_drop(x_3_10407, _ctx);
        kk_box_t _x_x1761 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_narrative_fun1762(x_1_10401, _ctx), _ctx); /*10001*/
        return kk_src_dream__cycle__narrative_result_unbox(_x_x1761, KK_OWNED, _ctx);
      }
      {
        kk_integer_t _x_x1767 = kk_std_core_list__lift_length_5730(x_1_10401, kk_integer_from_small(0), _ctx); /*int*/
        kk_integer_t _x_x1768 = kk_integer_dup(x_3_10407, _ctx); /*int*/
        kk_integer_t _x_x1769 = kk_integer_mul(x_3_10407,(kk_integer_from_small(30)),kk_context()); /*int*/
        return kk_src_dream__cycle__new_Narrative_result(kk_reuse_null, 0, _x_x1767, _x_x1768, _x_x1769, _ctx);
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1773__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1773(kk_function_t _fself, kk_box_t _b_x702, kk_box_t _b_x703, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_kaizen_10180_fun1773(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1773, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1786__t {
  struct kk_function_s _base;
  kk_box_t _b_x702;
};
static kk_integer_t kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1786(kk_function_t _fself, bool _y_x10098, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_kaizen_10180_fun1786(kk_box_t _b_x702, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1786__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1786__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1786, kk_context());
  _self->_b_x702 = _b_x702;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1786(kk_function_t _fself, bool _y_x10098, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1786__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1786__t*, _fself, _ctx);
  kk_box_t _b_x702 = _self->_b_x702; /* 10002 */
  kk_drop_match(_self, {kk_box_dup(_b_x702, _ctx);}, {}, _ctx)
  if (_y_x10098) {
    kk_integer_t _x_x1787 = kk_integer_unbox(_b_x702, _ctx); /*int*/
    return kk_integer_add_small_const(_x_x1787, 1, _ctx);
  }
  {
    return kk_integer_unbox(_b_x702, _ctx);
  }
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1790__t {
  struct kk_function_s _base;
  kk_function_t next_0_10422;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1790(kk_function_t _fself, kk_box_t _b_x698, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_kaizen_10180_fun1790(kk_function_t next_0_10422, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1790__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1790__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1790, kk_context());
  _self->next_0_10422 = next_0_10422;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1790(kk_function_t _fself, kk_box_t _b_x698, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1790__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1790__t*, _fself, _ctx);
  kk_function_t next_0_10422 = _self->next_0_10422; /* (bool) -> src/dream_cycle/kaizen-ops int */
  kk_drop_match(_self, {kk_function_dup(next_0_10422, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1791;
  bool _x_x1792 = kk_bool_unbox(_b_x698); /*bool*/
  _x_x1791 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), next_0_10422, (next_0_10422, _x_x1792, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x1791, _ctx);
}
static kk_box_t kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1773(kk_function_t _fself, kk_box_t _b_x702, kk_box_t _b_x703, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10423 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/kaizen-ops>*/;
  bool x_0_10421;
  kk_box_t _x_x1774;
  {
    struct kk_std_core_hnd_Ev* _con_x1775 = kk_std_core_hnd__as_Ev(evx_10423, _ctx);
    kk_box_t _box_x679 = _con_x1775->hnd;
    int32_t m = _con_x1775->marker;
    kk_src_dream__cycle__kaizen_ops h = kk_src_dream__cycle__kaizen_ops_unbox(_box_x679, KK_BORROWED, _ctx);
    kk_src_dream__cycle__kaizen_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1776 = kk_src_dream__cycle__as_Hnd_kaizen_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1776->_cfc;
      kk_std_core_hnd__clause0 _pat_1 = _con_x1776->_fun_get_improvement_candidates;
      kk_std_core_hnd__clause2 _fun_persist_insight = _con_x1776->_fun_persist_insight;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1776->_fun_scan_emergence;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_persist_insight, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x684 = _fun_persist_insight.clause;
        kk_box_t _x_x1777;
        kk_std_core_types__list _x_x1778;
        kk_box_t _x_x1779;
        kk_string_t _x_x1780;
        kk_define_string_literal(, _s_x1781, 9, "emergence", _ctx)
        _x_x1780 = kk_string_dup(_s_x1781, _ctx); /*string*/
        _x_x1779 = kk_string_box(_x_x1780); /*10021*/
        kk_std_core_types__list _x_x1782;
        kk_box_t _x_x1783;
        kk_string_t _x_x1784;
        kk_define_string_literal(, _s_x1785, 6, "kaizen", _ctx)
        _x_x1784 = kk_string_dup(_s_x1785, _ctx); /*string*/
        _x_x1783 = kk_string_box(_x_x1784); /*10021*/
        _x_x1782 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1783, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
        _x_x1778 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1779, _x_x1782, _ctx); /*list<10021>*/
        _x_x1777 = kk_std_core_types__list_box(_x_x1778, _ctx); /*10015*/
        _x_x1774 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x684, (_fun_unbox_x684, m, evx_10423, _b_x703, _x_x1777, _ctx), _ctx); /*10016*/
      }
    }
  }
  x_0_10421 = kk_bool_unbox(_x_x1774); /*bool*/
  kk_function_t next_0_10422 = kk_src_dream__cycle__new_mlift_phase_kaizen_10180_fun1786(_b_x702, _ctx); /*(bool) -> src/dream_cycle/kaizen-ops int*/;
  kk_integer_t _x_x1788;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1789 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_kaizen_10180_fun1790(next_0_10422, _ctx), _ctx); /*10001*/
    _x_x1788 = kk_integer_unbox(_x_x1789, _ctx); /*int*/
  }
  else {
    _x_x1788 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), next_0_10422, (next_0_10422, x_0_10421, _ctx), _ctx); /*int*/
  }
  return kk_integer_box(_x_x1788, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1794__t {
  struct kk_function_s _base;
  kk_std_core_types__list insights;
};
static kk_box_t kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1794(kk_function_t _fself, kk_box_t _b_x711, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_phase_kaizen_10180_fun1794(kk_std_core_types__list insights, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1794__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1794__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1794, kk_context());
  _self->insights = insights;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1794(kk_function_t _fself, kk_box_t _b_x711, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1794__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_phase_kaizen_10180_fun1794__t*, _fself, _ctx);
  kk_std_core_types__list insights = _self->insights; /* list<string> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(insights, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__kaizen_result _x_x1795;
  kk_integer_t persisted_713 = kk_integer_unbox(_b_x711, _ctx); /*int*/;
  kk_integer_t _x_x1796 = kk_std_core_list__lift_length_5730(insights, kk_integer_from_small(0), _ctx); /*int*/
  _x_x1795 = kk_src_dream__cycle__new_Kaizen_result(kk_reuse_null, 0, _x_x1796, persisted_713, _ctx); /*src/dream_cycle/kaizen-result*/
  return kk_src_dream__cycle__kaizen_result_box(_x_x1795, _ctx);
}

kk_src_dream__cycle__kaizen_result kk_src_dream__cycle__mlift_phase_kaizen_10180(kk_std_core_types__list insights, kk_context_t* _ctx) { /* (insights : list<string>) -> kaizen-ops kaizen-result */ 
  kk_integer_t x_10419;
  kk_box_t _x_x1771;
  kk_std_core_types__list _x_x1772 = kk_std_core_types__list_dup(insights, _ctx); /*list<string>*/
  _x_x1771 = kk_std_core_list_foldl(_x_x1772, kk_integer_box(kk_integer_from_small(0), _ctx), kk_src_dream__cycle__new_mlift_phase_kaizen_10180_fun1773(_ctx), _ctx); /*10002*/
  x_10419 = kk_integer_unbox(_x_x1771, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10419, _ctx);
    kk_box_t _x_x1793 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_phase_kaizen_10180_fun1794(insights, _ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__kaizen_result_unbox(_x_x1793, KK_OWNED, _ctx);
  }
  {
    kk_integer_t persisted_714 = x_10419; /*int*/;
    kk_integer_t _x_x1797 = kk_std_core_list__lift_length_5730(insights, kk_integer_from_small(0), _ctx); /*int*/
    return kk_src_dream__cycle__new_Kaizen_result(kk_reuse_null, 0, _x_x1797, persisted_714, _ctx);
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_kaizen_fun1802__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_kaizen_fun1802(kk_function_t _fself, kk_box_t _b_x724, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_kaizen_fun1802(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_kaizen_fun1802, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_kaizen_fun1802(kk_function_t _fself, kk_box_t _b_x724, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__kaizen_result _x_x1803;
  kk_std_core_types__list _x_x1804 = kk_std_core_types__list_unbox(_b_x724, KK_OWNED, _ctx); /*list<string>*/
  _x_x1803 = kk_src_dream__cycle__mlift_phase_kaizen_10180(_x_x1804, _ctx); /*src/dream_cycle/kaizen-result*/
  return kk_src_dream__cycle__kaizen_result_box(_x_x1803, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_phase_kaizen_fun1807__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_kaizen_fun1807(kk_function_t _fself, kk_box_t _b_x748, kk_box_t _b_x749, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_kaizen_fun1807(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_kaizen_fun1807, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle_phase_kaizen_fun1820__t {
  struct kk_function_s _base;
  kk_box_t _b_x748;
};
static kk_integer_t kk_src_dream__cycle_phase_kaizen_fun1820(kk_function_t _fself, bool _y_x10098, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_kaizen_fun1820(kk_box_t _b_x748, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_kaizen_fun1820__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_phase_kaizen_fun1820__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_phase_kaizen_fun1820, kk_context());
  _self->_b_x748 = _b_x748;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_src_dream__cycle_phase_kaizen_fun1820(kk_function_t _fself, bool _y_x10098, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_kaizen_fun1820__t* _self = kk_function_as(struct kk_src_dream__cycle_phase_kaizen_fun1820__t*, _fself, _ctx);
  kk_box_t _b_x748 = _self->_b_x748; /* 10002 */
  kk_drop_match(_self, {kk_box_dup(_b_x748, _ctx);}, {}, _ctx)
  if (_y_x10098) {
    kk_integer_t _x_x1821 = kk_integer_unbox(_b_x748, _ctx); /*int*/
    return kk_integer_add_small_const(_x_x1821, 1, _ctx);
  }
  {
    return kk_integer_unbox(_b_x748, _ctx);
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_kaizen_fun1824__t {
  struct kk_function_s _base;
  kk_function_t next_1_10441;
};
static kk_box_t kk_src_dream__cycle_phase_kaizen_fun1824(kk_function_t _fself, kk_box_t _b_x744, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_kaizen_fun1824(kk_function_t next_1_10441, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_kaizen_fun1824__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_phase_kaizen_fun1824__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_phase_kaizen_fun1824, kk_context());
  _self->next_1_10441 = next_1_10441;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_kaizen_fun1824(kk_function_t _fself, kk_box_t _b_x744, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_kaizen_fun1824__t* _self = kk_function_as(struct kk_src_dream__cycle_phase_kaizen_fun1824__t*, _fself, _ctx);
  kk_function_t next_1_10441 = _self->next_1_10441; /* (bool) -> src/dream_cycle/kaizen-ops int */
  kk_drop_match(_self, {kk_function_dup(next_1_10441, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1825;
  bool _x_x1826 = kk_bool_unbox(_b_x744); /*bool*/
  _x_x1825 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), next_1_10441, (next_1_10441, _x_x1826, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x1825, _ctx);
}
static kk_box_t kk_src_dream__cycle_phase_kaizen_fun1807(kk_function_t _fself, kk_box_t _b_x748, kk_box_t _b_x749, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10442 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/kaizen-ops>*/;
  bool x_2_10440;
  kk_box_t _x_x1808;
  {
    struct kk_std_core_hnd_Ev* _con_x1809 = kk_std_core_hnd__as_Ev(evx_10442, _ctx);
    kk_box_t _box_x725 = _con_x1809->hnd;
    int32_t m_0 = _con_x1809->marker;
    kk_src_dream__cycle__kaizen_ops h_0 = kk_src_dream__cycle__kaizen_ops_unbox(_box_x725, KK_BORROWED, _ctx);
    kk_src_dream__cycle__kaizen_ops_dup(h_0, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1810 = kk_src_dream__cycle__as_Hnd_kaizen_ops(h_0, _ctx);
      kk_integer_t _pat_0_2 = _con_x1810->_cfc;
      kk_std_core_hnd__clause0 _pat_1_2 = _con_x1810->_fun_get_improvement_candidates;
      kk_std_core_hnd__clause2 _fun_persist_insight = _con_x1810->_fun_persist_insight;
      kk_std_core_hnd__clause1 _pat_2_1 = _con_x1810->_fun_scan_emergence;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_1, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_persist_insight, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x730 = _fun_persist_insight.clause;
        kk_box_t _x_x1811;
        kk_std_core_types__list _x_x1812;
        kk_box_t _x_x1813;
        kk_string_t _x_x1814;
        kk_define_string_literal(, _s_x1815, 9, "emergence", _ctx)
        _x_x1814 = kk_string_dup(_s_x1815, _ctx); /*string*/
        _x_x1813 = kk_string_box(_x_x1814); /*10021*/
        kk_std_core_types__list _x_x1816;
        kk_box_t _x_x1817;
        kk_string_t _x_x1818;
        kk_define_string_literal(, _s_x1819, 6, "kaizen", _ctx)
        _x_x1818 = kk_string_dup(_s_x1819, _ctx); /*string*/
        _x_x1817 = kk_string_box(_x_x1818); /*10021*/
        _x_x1816 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1817, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
        _x_x1812 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1813, _x_x1816, _ctx); /*list<10021>*/
        _x_x1811 = kk_std_core_types__list_box(_x_x1812, _ctx); /*10015*/
        _x_x1808 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x730, (_fun_unbox_x730, m_0, evx_10442, _b_x749, _x_x1811, _ctx), _ctx); /*10016*/
      }
    }
  }
  x_2_10440 = kk_bool_unbox(_x_x1808); /*bool*/
  kk_function_t next_1_10441 = kk_src_dream__cycle_new_phase_kaizen_fun1820(_b_x748, _ctx); /*(bool) -> src/dream_cycle/kaizen-ops int*/;
  kk_integer_t _x_x1822;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1823 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_kaizen_fun1824(next_1_10441, _ctx), _ctx); /*10001*/
    _x_x1822 = kk_integer_unbox(_x_x1823, _ctx); /*int*/
  }
  else {
    _x_x1822 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), next_1_10441, (next_1_10441, x_2_10440, _ctx), _ctx); /*int*/
  }
  return kk_integer_box(_x_x1822, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_phase_kaizen_fun1828__t {
  struct kk_function_s _base;
  kk_std_core_types__list x_10431;
};
static kk_box_t kk_src_dream__cycle_phase_kaizen_fun1828(kk_function_t _fself, kk_box_t _b_x757, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_kaizen_fun1828(kk_std_core_types__list x_10431, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_kaizen_fun1828__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_phase_kaizen_fun1828__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_phase_kaizen_fun1828, kk_context());
  _self->x_10431 = x_10431;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_kaizen_fun1828(kk_function_t _fself, kk_box_t _b_x757, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_phase_kaizen_fun1828__t* _self = kk_function_as(struct kk_src_dream__cycle_phase_kaizen_fun1828__t*, _fself, _ctx);
  kk_std_core_types__list x_10431 = _self->x_10431; /* list<string> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(x_10431, _ctx);}, {}, _ctx)
  kk_integer_t persisted_760 = kk_integer_unbox(_b_x757, _ctx); /*int*/;
  kk_src_dream__cycle__kaizen_result _x_x1829;
  kk_integer_t _x_x1830 = kk_std_core_list__lift_length_5730(x_10431, kk_integer_from_small(0), _ctx); /*int*/
  _x_x1829 = kk_src_dream__cycle__new_Kaizen_result(kk_reuse_null, 0, _x_x1830, persisted_760, _ctx); /*src/dream_cycle/kaizen-result*/
  return kk_src_dream__cycle__kaizen_result_box(_x_x1829, _ctx);
}

kk_src_dream__cycle__kaizen_result kk_src_dream__cycle_phase_kaizen(kk_context_t* _ctx) { /* () -> kaizen-ops kaizen-result */ 
  kk_std_core_hnd__ev ev_10434 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/kaizen-ops>*/;
  kk_std_core_types__list x_10431;
  kk_box_t _x_x1798;
  {
    struct kk_std_core_hnd_Ev* _con_x1799 = kk_std_core_hnd__as_Ev(ev_10434, _ctx);
    kk_box_t _box_x715 = _con_x1799->hnd;
    int32_t m = _con_x1799->marker;
    kk_src_dream__cycle__kaizen_ops h = kk_src_dream__cycle__kaizen_ops_unbox(_box_x715, KK_BORROWED, _ctx);
    kk_src_dream__cycle__kaizen_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_kaizen_ops* _con_x1800 = kk_src_dream__cycle__as_Hnd_kaizen_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1800->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x1800->_fun_get_improvement_candidates;
      kk_std_core_hnd__clause2 _pat_2 = _con_x1800->_fun_persist_insight;
      kk_std_core_hnd__clause1 _fun_scan_emergence = _con_x1800->_fun_scan_emergence;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_scan_emergence, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x719 = _fun_scan_emergence.clause;
        _x_x1798 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x719, (_fun_unbox_x719, m, ev_10434, kk_integer_box(kk_integer_from_small(3), _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  x_10431 = kk_std_core_types__list_unbox(_x_x1798, KK_OWNED, _ctx); /*list<string>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10431, _ctx);
    kk_box_t _x_x1801 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_kaizen_fun1802(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__kaizen_result_unbox(_x_x1801, KK_OWNED, _ctx);
  }
  {
    kk_integer_t x_1_10437;
    kk_box_t _x_x1805;
    kk_std_core_types__list _x_x1806 = kk_std_core_types__list_dup(x_10431, _ctx); /*list<string>*/
    _x_x1805 = kk_std_core_list_foldl(_x_x1806, kk_integer_box(kk_integer_from_small(0), _ctx), kk_src_dream__cycle_new_phase_kaizen_fun1807(_ctx), _ctx); /*10002*/
    x_1_10437 = kk_integer_unbox(_x_x1805, _ctx); /*int*/
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_1_10437, _ctx);
      kk_box_t _x_x1827 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_kaizen_fun1828(x_10431, _ctx), _ctx); /*10001*/
      return kk_src_dream__cycle__kaizen_result_unbox(_x_x1827, KK_OWNED, _ctx);
    }
    {
      kk_integer_t _x_x1831 = kk_std_core_list__lift_length_5730(x_10431, kk_integer_from_small(0), _ctx); /*int*/
      return kk_src_dream__cycle__new_Kaizen_result(kk_reuse_null, 0, _x_x1831, x_1_10437, _ctx);
    }
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_oracle_fun1845__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_oracle_fun1845(kk_function_t _fself, kk_box_t _b_x778, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_oracle_fun1845(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_oracle_fun1845, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_oracle_fun1845(kk_function_t _fself, kk_box_t _b_x778, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__oracle_result _x_x1846;
  kk_std_core_types__list _x_x1847 = kk_std_core_types__list_unbox(_b_x778, KK_OWNED, _ctx); /*list<string>*/
  _x_x1846 = kk_src_dream__cycle__mlift_phase_oracle_10181(_x_x1847, _ctx); /*src/dream_cycle/oracle-result*/
  return kk_src_dream__cycle__oracle_result_box(_x_x1846, _ctx);
}

kk_src_dream__cycle__oracle_result kk_src_dream__cycle_phase_oracle(kk_context_t* _ctx) { /* () -> oracle-ops oracle-result */ 
  kk_std_core_hnd__ev ev_10453 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/oracle-ops>*/;
  kk_std_core_types__list x_10450;
  kk_box_t _x_x1832;
  {
    struct kk_std_core_hnd_Ev* _con_x1833 = kk_std_core_hnd__as_Ev(ev_10453, _ctx);
    kk_box_t _box_x761 = _con_x1833->hnd;
    int32_t m = _con_x1833->marker;
    kk_src_dream__cycle__oracle_ops h = kk_src_dream__cycle__oracle_ops_unbox(_box_x761, KK_BORROWED, _ctx);
    kk_src_dream__cycle__oracle_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_oracle_ops* _con_x1834 = kk_src_dream__cycle__as_Hnd_oracle_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1834->_cfc;
      kk_std_core_hnd__clause1 _pat_1_1 = _con_x1834->_fun_generate_suggestion;
      kk_std_core_hnd__clause1 _fun_predict_next_session = _con_x1834->_fun_predict_next_session;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_predict_next_session, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x765 = _fun_predict_next_session.clause;
        kk_box_t _x_x1835;
        kk_std_core_types__list _x_x1836;
        kk_box_t _x_x1837;
        kk_string_t _x_x1838;
        kk_define_string_literal(, _s_x1839, 11, "recent-work", _ctx)
        _x_x1838 = kk_string_dup(_s_x1839, _ctx); /*string*/
        _x_x1837 = kk_string_box(_x_x1838); /*10021*/
        kk_std_core_types__list _x_x1840;
        kk_box_t _x_x1841;
        kk_string_t _x_x1842;
        kk_define_string_literal(, _s_x1843, 14, "open-campaigns", _ctx)
        _x_x1842 = kk_string_dup(_s_x1843, _ctx); /*string*/
        _x_x1841 = kk_string_box(_x_x1842); /*10021*/
        _x_x1840 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1841, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
        _x_x1836 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1837, _x_x1840, _ctx); /*list<10021>*/
        _x_x1835 = kk_std_core_types__list_box(_x_x1836, _ctx); /*10009*/
        _x_x1832 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x765, (_fun_unbox_x765, m, ev_10453, _x_x1835, _ctx), _ctx); /*10010*/
      }
    }
  }
  x_10450 = kk_std_core_types__list_unbox(_x_x1832, KK_OWNED, _ctx); /*list<string>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10450, _ctx);
    kk_box_t _x_x1844 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_oracle_fun1845(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__oracle_result_unbox(_x_x1844, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__new_Oracle_result(x_10450, _ctx);
  }
}


// lift anonymous function
struct kk_src_dream__cycle_phase_decay_fun1852__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_phase_decay_fun1852(kk_function_t _fself, kk_box_t _b_x791, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_phase_decay_fun1852(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_phase_decay_fun1852, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_phase_decay_fun1852(kk_function_t _fself, kk_box_t _b_x791, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__decay_result _x_x1853;
  kk_integer_t _x_x1854 = kk_integer_unbox(_b_x791, _ctx); /*int*/
  _x_x1853 = kk_src_dream__cycle__mlift_phase_decay_10182(_x_x1854, _ctx); /*src/dream_cycle/decay-result*/
  return kk_src_dream__cycle__decay_result_box(_x_x1853, _ctx);
}

kk_src_dream__cycle__decay_result kk_src_dream__cycle_phase_decay(kk_context_t* _ctx) { /* () -> decay-ops decay-result */ 
  kk_std_core_hnd__ev evx_10459 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/decay-ops>*/;
  kk_integer_t x_10456;
  kk_box_t _x_x1848;
  {
    struct kk_std_core_hnd_Ev* _con_x1849 = kk_std_core_hnd__as_Ev(evx_10459, _ctx);
    kk_box_t _box_x780 = _con_x1849->hnd;
    int32_t m = _con_x1849->marker;
    kk_src_dream__cycle__decay_ops h = kk_src_dream__cycle__decay_ops_unbox(_box_x780, KK_BORROWED, _ctx);
    kk_src_dream__cycle__decay_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1850 = kk_src_dream__cycle__as_Hnd_decay_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1850->_cfc;
      kk_std_core_hnd__clause1 _pat_1_1 = _con_x1850->_fun_archive_memory;
      kk_std_core_hnd__clause1 _pat_2 = _con_x1850->_fun_get_decay_candidates;
      kk_std_core_hnd__clause2 _fun_sweep_old_memories = _con_x1850->_fun_sweep_old_memories;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_sweep_old_memories, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x785 = _fun_sweep_old_memories.clause;
        _x_x1848 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x785, (_fun_unbox_x785, m, evx_10459, kk_integer_box(kk_integer_from_small(90), _ctx), kk_double_box(0x1.999999999999ap-3, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  x_10456 = kk_integer_unbox(_x_x1848, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10456, _ctx);
    kk_box_t _x_x1851 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_phase_decay_fun1852(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__decay_result_unbox(_x_x1851, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__new_Decay_result(x_10456, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1856__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1856(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10186_fun1856(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1856, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1862__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1862(kk_function_t _fself, kk_box_t _b_x804, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10186_fun1862(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1862, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1862(kk_function_t _fself, kk_box_t _b_x804, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__decay_result _x_x1863;
  kk_integer_t _x_x1864 = kk_integer_unbox(_b_x804, _ctx); /*int*/
  _x_x1863 = kk_src_dream__cycle__mlift_run_dream_cycle_10183(_x_x1864, _ctx); /*src/dream_cycle/decay-result*/
  return kk_src_dream__cycle__decay_result_box(_x_x1863, _ctx);
}
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1856(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10467 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/decay-ops>*/;
  kk_integer_t x_0_10465;
  kk_box_t _x_x1857;
  {
    struct kk_std_core_hnd_Ev* _con_x1858 = kk_std_core_hnd__as_Ev(evx_10467, _ctx);
    kk_box_t _box_x793 = _con_x1858->hnd;
    int32_t m = _con_x1858->marker;
    kk_src_dream__cycle__decay_ops h = kk_src_dream__cycle__decay_ops_unbox(_box_x793, KK_BORROWED, _ctx);
    kk_src_dream__cycle__decay_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1859 = kk_src_dream__cycle__as_Hnd_decay_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1859->_cfc;
      kk_std_core_hnd__clause1 _pat_1 = _con_x1859->_fun_archive_memory;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x1859->_fun_get_decay_candidates;
      kk_std_core_hnd__clause2 _fun_sweep_old_memories = _con_x1859->_fun_sweep_old_memories;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_sweep_old_memories, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x798 = _fun_sweep_old_memories.clause;
        _x_x1857 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x798, (_fun_unbox_x798, m, evx_10467, kk_integer_box(kk_integer_from_small(90), _ctx), kk_double_box(0x1.999999999999ap-3, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  x_0_10465 = kk_integer_unbox(_x_x1857, _ctx); /*int*/
  kk_src_dream__cycle__decay_result _x_x1860;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_0_10465, _ctx);
    kk_box_t _x_x1861 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_run_dream_cycle_10186_fun1862(_ctx), _ctx); /*10001*/
    _x_x1860 = kk_src_dream__cycle__decay_result_unbox(_x_x1861, KK_OWNED, _ctx); /*src/dream_cycle/decay-result*/
  }
  else {
    _x_x1860 = kk_src_dream__cycle__new_Decay_result(x_0_10465, _ctx); /*src/dream_cycle/decay-result*/
  }
  return kk_src_dream__cycle__decay_result_box(_x_x1860, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1866__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__triage_result t1;
  kk_src_dream__cycle__consolidation_result t2;
  kk_src_dream__cycle__serendipity_result t3;
  kk_src_dream__cycle__governance_result t4;
  kk_src_dream__cycle__narrative_result t5;
  kk_src_dream__cycle__kaizen_result t6;
  kk_src_dream__cycle__oracle_result t7;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1866(kk_function_t _fself, kk_box_t _b_x811, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10186_fun1866(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_src_dream__cycle__narrative_result t5, kk_src_dream__cycle__kaizen_result t6, kk_src_dream__cycle__oracle_result t7, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1866__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1866__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1866, kk_context());
  _self->t1 = t1;
  _self->t2 = t2;
  _self->t3 = t3;
  _self->t4 = t4;
  _self->t5 = t5;
  _self->t6 = t6;
  _self->t7 = t7;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1866(kk_function_t _fself, kk_box_t _b_x811, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1866__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10186_fun1866__t*, _fself, _ctx);
  kk_src_dream__cycle__triage_result t1 = _self->t1; /* src/dream_cycle/triage-result */
  kk_src_dream__cycle__consolidation_result t2 = _self->t2; /* src/dream_cycle/consolidation-result */
  kk_src_dream__cycle__serendipity_result t3 = _self->t3; /* src/dream_cycle/serendipity-result */
  kk_src_dream__cycle__governance_result t4 = _self->t4; /* src/dream_cycle/governance-result */
  kk_src_dream__cycle__narrative_result t5 = _self->t5; /* src/dream_cycle/narrative-result */
  kk_src_dream__cycle__kaizen_result t6 = _self->t6; /* src/dream_cycle/kaizen-result */
  kk_src_dream__cycle__oracle_result t7 = _self->t7; /* src/dream_cycle/oracle-result */
  kk_drop_match(_self, {kk_src_dream__cycle__triage_result_dup(t1, _ctx);kk_src_dream__cycle__consolidation_result_dup(t2, _ctx);kk_src_dream__cycle__serendipity_result_dup(t3, _ctx);kk_src_dream__cycle__governance_result_dup(t4, _ctx);kk_src_dream__cycle__narrative_result_dup(t5, _ctx);kk_src_dream__cycle__kaizen_result_dup(t6, _ctx);kk_src_dream__cycle__oracle_result_dup(t7, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__decay_result t8_813 = kk_src_dream__cycle__decay_result_unbox(_b_x811, KK_OWNED, _ctx); /*src/dream_cycle/decay-result*/;
  kk_src_dream__cycle__dream_summary _x_x1867 = kk_src_dream__cycle__new_Dream_summary(kk_reuse_null, 0, t1, t2, t3, t4, t5, t6, t7, t8_813, kk_integer_from_small(0), _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1867, _ctx);
}

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10186(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_src_dream__cycle__narrative_result t5, kk_src_dream__cycle__kaizen_result t6, kk_src_dream__cycle__oracle_result t7, kk_context_t* _ctx) { /* (t1 : triage-result, t2 : consolidation-result, t3 : serendipity-result, t4 : governance-result, t5 : narrative-result, t6 : kaizen-result, t7 : oracle-result) -> <oracle-ops,decay-ops,kaizen-ops,narrative-ops,governance-ops,insight-ops,memory-ops,constellation-ops> dream-summary */ 
  kk_ssize_t _b_x805_807 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_src_dream__cycle__decay_result x_10463;
  kk_box_t _x_x1855 = kk_std_core_hnd__open_at0(_b_x805_807, kk_src_dream__cycle__new_mlift_run_dream_cycle_10186_fun1856(_ctx), _ctx); /*10000*/
  x_10463 = kk_src_dream__cycle__decay_result_unbox(_x_x1855, KK_OWNED, _ctx); /*src/dream_cycle/decay-result*/
  if (kk_yielding(kk_context())) {
    kk_src_dream__cycle__decay_result_drop(x_10463, _ctx);
    kk_box_t _x_x1865 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_run_dream_cycle_10186_fun1866(t1, t2, t3, t4, t5, t6, t7, _ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__dream_summary_unbox(_x_x1865, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__new_Dream_summary(kk_reuse_null, 0, t1, t2, t3, t4, t5, t6, t7, x_10463, kk_integer_from_small(0), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1869__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1869(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10187_fun1869(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1869, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1884__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1884(kk_function_t _fself, kk_box_t _b_x831, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10187_fun1884(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1884, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1884(kk_function_t _fself, kk_box_t _b_x831, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__oracle_result _x_x1885;
  kk_std_core_types__list _x_x1886 = kk_std_core_types__list_unbox(_b_x831, KK_OWNED, _ctx); /*list<string>*/
  _x_x1885 = kk_src_dream__cycle__mlift_run_dream_cycle_10185(_x_x1886, _ctx); /*src/dream_cycle/oracle-result*/
  return kk_src_dream__cycle__oracle_result_box(_x_x1885, _ctx);
}
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1869(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev ev_10483 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/oracle-ops>*/;
  kk_std_core_types__list x_0_10481;
  kk_box_t _x_x1870;
  {
    struct kk_std_core_hnd_Ev* _con_x1871 = kk_std_core_hnd__as_Ev(ev_10483, _ctx);
    kk_box_t _box_x814 = _con_x1871->hnd;
    int32_t m = _con_x1871->marker;
    kk_src_dream__cycle__oracle_ops h = kk_src_dream__cycle__oracle_ops_unbox(_box_x814, KK_BORROWED, _ctx);
    kk_src_dream__cycle__oracle_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_oracle_ops* _con_x1872 = kk_src_dream__cycle__as_Hnd_oracle_ops(h, _ctx);
      kk_integer_t _pat_0 = _con_x1872->_cfc;
      kk_std_core_hnd__clause1 _pat_1 = _con_x1872->_fun_generate_suggestion;
      kk_std_core_hnd__clause1 _fun_predict_next_session = _con_x1872->_fun_predict_next_session;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_predict_next_session, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x818 = _fun_predict_next_session.clause;
        kk_box_t _x_x1873;
        kk_std_core_types__list _x_x1874;
        kk_box_t _x_x1875;
        kk_string_t _x_x1876;
        kk_define_string_literal(, _s_x1877, 11, "recent-work", _ctx)
        _x_x1876 = kk_string_dup(_s_x1877, _ctx); /*string*/
        _x_x1875 = kk_string_box(_x_x1876); /*10021*/
        kk_std_core_types__list _x_x1878;
        kk_box_t _x_x1879;
        kk_string_t _x_x1880;
        kk_define_string_literal(, _s_x1881, 14, "open-campaigns", _ctx)
        _x_x1880 = kk_string_dup(_s_x1881, _ctx); /*string*/
        _x_x1879 = kk_string_box(_x_x1880); /*10021*/
        _x_x1878 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1879, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
        _x_x1874 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1875, _x_x1878, _ctx); /*list<10021>*/
        _x_x1873 = kk_std_core_types__list_box(_x_x1874, _ctx); /*10009*/
        _x_x1870 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x818, (_fun_unbox_x818, m, ev_10483, _x_x1873, _ctx), _ctx); /*10010*/
      }
    }
  }
  x_0_10481 = kk_std_core_types__list_unbox(_x_x1870, KK_OWNED, _ctx); /*list<string>*/
  kk_src_dream__cycle__oracle_result _x_x1882;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10481, _ctx);
    kk_box_t _x_x1883 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_run_dream_cycle_10187_fun1884(_ctx), _ctx); /*10001*/
    _x_x1882 = kk_src_dream__cycle__oracle_result_unbox(_x_x1883, KK_OWNED, _ctx); /*src/dream_cycle/oracle-result*/
  }
  else {
    _x_x1882 = kk_src_dream__cycle__new_Oracle_result(x_0_10481, _ctx); /*src/dream_cycle/oracle-result*/
  }
  return kk_src_dream__cycle__oracle_result_box(_x_x1882, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1888__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__triage_result t1;
  kk_src_dream__cycle__consolidation_result t2;
  kk_src_dream__cycle__serendipity_result t3;
  kk_src_dream__cycle__governance_result t4;
  kk_src_dream__cycle__narrative_result t5;
  kk_src_dream__cycle__kaizen_result t6;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1888(kk_function_t _fself, kk_box_t _b_x838, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10187_fun1888(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_src_dream__cycle__narrative_result t5, kk_src_dream__cycle__kaizen_result t6, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1888__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1888__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1888, kk_context());
  _self->t1 = t1;
  _self->t2 = t2;
  _self->t3 = t3;
  _self->t4 = t4;
  _self->t5 = t5;
  _self->t6 = t6;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1888(kk_function_t _fself, kk_box_t _b_x838, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1888__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10187_fun1888__t*, _fself, _ctx);
  kk_src_dream__cycle__triage_result t1 = _self->t1; /* src/dream_cycle/triage-result */
  kk_src_dream__cycle__consolidation_result t2 = _self->t2; /* src/dream_cycle/consolidation-result */
  kk_src_dream__cycle__serendipity_result t3 = _self->t3; /* src/dream_cycle/serendipity-result */
  kk_src_dream__cycle__governance_result t4 = _self->t4; /* src/dream_cycle/governance-result */
  kk_src_dream__cycle__narrative_result t5 = _self->t5; /* src/dream_cycle/narrative-result */
  kk_src_dream__cycle__kaizen_result t6 = _self->t6; /* src/dream_cycle/kaizen-result */
  kk_drop_match(_self, {kk_src_dream__cycle__triage_result_dup(t1, _ctx);kk_src_dream__cycle__consolidation_result_dup(t2, _ctx);kk_src_dream__cycle__serendipity_result_dup(t3, _ctx);kk_src_dream__cycle__governance_result_dup(t4, _ctx);kk_src_dream__cycle__narrative_result_dup(t5, _ctx);kk_src_dream__cycle__kaizen_result_dup(t6, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__oracle_result t7_840 = kk_src_dream__cycle__oracle_result_unbox(_b_x838, KK_OWNED, _ctx); /*src/dream_cycle/oracle-result*/;
  kk_src_dream__cycle__dream_summary _x_x1889 = kk_src_dream__cycle__mlift_run_dream_cycle_10186(t1, t2, t3, t4, t5, t6, t7_840, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1889, _ctx);
}

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10187(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_src_dream__cycle__narrative_result t5, kk_src_dream__cycle__kaizen_result t6, kk_context_t* _ctx) { /* (t1 : triage-result, t2 : consolidation-result, t3 : serendipity-result, t4 : governance-result, t5 : narrative-result, t6 : kaizen-result) -> <kaizen-ops,decay-ops,oracle-ops,narrative-ops,governance-ops,insight-ops,memory-ops,constellation-ops> dream-summary */ 
  kk_ssize_t _b_x832_834 = (KK_IZ(7)); /*hnd/ev-index*/;
  kk_src_dream__cycle__oracle_result x_10479;
  kk_box_t _x_x1868 = kk_std_core_hnd__open_at0(_b_x832_834, kk_src_dream__cycle__new_mlift_run_dream_cycle_10187_fun1869(_ctx), _ctx); /*10000*/
  x_10479 = kk_src_dream__cycle__oracle_result_unbox(_x_x1868, KK_OWNED, _ctx); /*src/dream_cycle/oracle-result*/
  if (kk_yielding(kk_context())) {
    kk_src_dream__cycle__oracle_result_drop(x_10479, _ctx);
    kk_box_t _x_x1887 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_run_dream_cycle_10187_fun1888(t1, t2, t3, t4, t5, t6, _ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__dream_summary_unbox(_x_x1887, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__mlift_run_dream_cycle_10186(t1, t2, t3, t4, t5, t6, x_10479, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1891__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1891(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10188_fun1891(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1891, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1891(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__kaizen_result _x_x1892 = kk_src_dream__cycle_phase_kaizen(_ctx); /*src/dream_cycle/kaizen-result*/
  return kk_src_dream__cycle__kaizen_result_box(_x_x1892, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1894__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__triage_result t1;
  kk_src_dream__cycle__consolidation_result t2;
  kk_src_dream__cycle__serendipity_result t3;
  kk_src_dream__cycle__governance_result t4;
  kk_src_dream__cycle__narrative_result t5;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1894(kk_function_t _fself, kk_box_t _b_x846, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10188_fun1894(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_src_dream__cycle__narrative_result t5, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1894__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1894__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1894, kk_context());
  _self->t1 = t1;
  _self->t2 = t2;
  _self->t3 = t3;
  _self->t4 = t4;
  _self->t5 = t5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1894(kk_function_t _fself, kk_box_t _b_x846, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1894__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10188_fun1894__t*, _fself, _ctx);
  kk_src_dream__cycle__triage_result t1 = _self->t1; /* src/dream_cycle/triage-result */
  kk_src_dream__cycle__consolidation_result t2 = _self->t2; /* src/dream_cycle/consolidation-result */
  kk_src_dream__cycle__serendipity_result t3 = _self->t3; /* src/dream_cycle/serendipity-result */
  kk_src_dream__cycle__governance_result t4 = _self->t4; /* src/dream_cycle/governance-result */
  kk_src_dream__cycle__narrative_result t5 = _self->t5; /* src/dream_cycle/narrative-result */
  kk_drop_match(_self, {kk_src_dream__cycle__triage_result_dup(t1, _ctx);kk_src_dream__cycle__consolidation_result_dup(t2, _ctx);kk_src_dream__cycle__serendipity_result_dup(t3, _ctx);kk_src_dream__cycle__governance_result_dup(t4, _ctx);kk_src_dream__cycle__narrative_result_dup(t5, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__kaizen_result t6_848 = kk_src_dream__cycle__kaizen_result_unbox(_b_x846, KK_OWNED, _ctx); /*src/dream_cycle/kaizen-result*/;
  kk_src_dream__cycle__dream_summary _x_x1895 = kk_src_dream__cycle__mlift_run_dream_cycle_10187(t1, t2, t3, t4, t5, t6_848, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1895, _ctx);
}

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10188(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_src_dream__cycle__narrative_result t5, kk_context_t* _ctx) { /* (t1 : triage-result, t2 : consolidation-result, t3 : serendipity-result, t4 : governance-result, t5 : narrative-result) -> <narrative-ops,decay-ops,kaizen-ops,oracle-ops,governance-ops,insight-ops,memory-ops,constellation-ops> dream-summary */ 
  kk_ssize_t _b_x841_843 = (KK_IZ(4)); /*hnd/ev-index*/;
  kk_src_dream__cycle__kaizen_result x_10486;
  kk_box_t _x_x1890 = kk_std_core_hnd__open_at0(_b_x841_843, kk_src_dream__cycle__new_mlift_run_dream_cycle_10188_fun1891(_ctx), _ctx); /*10000*/
  x_10486 = kk_src_dream__cycle__kaizen_result_unbox(_x_x1890, KK_OWNED, _ctx); /*src/dream_cycle/kaizen-result*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10486, (KK_I32(2)), _ctx);
    kk_box_t _x_x1893 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_run_dream_cycle_10188_fun1894(t1, t2, t3, t4, t5, _ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__dream_summary_unbox(_x_x1893, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__mlift_run_dream_cycle_10187(t1, t2, t3, t4, t5, x_10486, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1897__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1897(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10189_fun1897(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1897, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1897(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__narrative_result _x_x1898 = kk_src_dream__cycle_phase_narrative(_ctx); /*src/dream_cycle/narrative-result*/
  return kk_src_dream__cycle__narrative_result_box(_x_x1898, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1900__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__triage_result t1;
  kk_src_dream__cycle__consolidation_result t2;
  kk_src_dream__cycle__serendipity_result t3;
  kk_src_dream__cycle__governance_result t4;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1900(kk_function_t _fself, kk_box_t _b_x854, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10189_fun1900(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1900__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1900__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1900, kk_context());
  _self->t1 = t1;
  _self->t2 = t2;
  _self->t3 = t3;
  _self->t4 = t4;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1900(kk_function_t _fself, kk_box_t _b_x854, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1900__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10189_fun1900__t*, _fself, _ctx);
  kk_src_dream__cycle__triage_result t1 = _self->t1; /* src/dream_cycle/triage-result */
  kk_src_dream__cycle__consolidation_result t2 = _self->t2; /* src/dream_cycle/consolidation-result */
  kk_src_dream__cycle__serendipity_result t3 = _self->t3; /* src/dream_cycle/serendipity-result */
  kk_src_dream__cycle__governance_result t4 = _self->t4; /* src/dream_cycle/governance-result */
  kk_drop_match(_self, {kk_src_dream__cycle__triage_result_dup(t1, _ctx);kk_src_dream__cycle__consolidation_result_dup(t2, _ctx);kk_src_dream__cycle__serendipity_result_dup(t3, _ctx);kk_src_dream__cycle__governance_result_dup(t4, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__narrative_result t5_856 = kk_src_dream__cycle__narrative_result_unbox(_b_x854, KK_OWNED, _ctx); /*src/dream_cycle/narrative-result*/;
  kk_src_dream__cycle__dream_summary _x_x1901 = kk_src_dream__cycle__mlift_run_dream_cycle_10188(t1, t2, t3, t4, t5_856, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1901, _ctx);
}

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10189(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_src_dream__cycle__governance_result t4, kk_context_t* _ctx) { /* (t1 : triage-result, t2 : consolidation-result, t3 : serendipity-result, t4 : governance-result) -> <governance-ops,decay-ops,kaizen-ops,narrative-ops,oracle-ops,insight-ops,memory-ops,constellation-ops> dream-summary */ 
  kk_ssize_t _b_x849_851 = (KK_IZ(6)); /*hnd/ev-index*/;
  kk_src_dream__cycle__narrative_result x_10488;
  kk_box_t _x_x1896 = kk_std_core_hnd__open_at0(_b_x849_851, kk_src_dream__cycle__new_mlift_run_dream_cycle_10189_fun1897(_ctx), _ctx); /*10000*/
  x_10488 = kk_src_dream__cycle__narrative_result_unbox(_x_x1896, KK_OWNED, _ctx); /*src/dream_cycle/narrative-result*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10488, (KK_I32(3)), _ctx);
    kk_box_t _x_x1899 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_run_dream_cycle_10189_fun1900(t1, t2, t3, t4, _ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__dream_summary_unbox(_x_x1899, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__mlift_run_dream_cycle_10188(t1, t2, t3, t4, x_10488, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1903__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1903(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10190_fun1903(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1903, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1903(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__governance_result _x_x1904 = kk_src_dream__cycle_phase_governance(_ctx); /*src/dream_cycle/governance-result*/
  return kk_src_dream__cycle__governance_result_box(_x_x1904, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1906__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__triage_result t1;
  kk_src_dream__cycle__consolidation_result t2;
  kk_src_dream__cycle__serendipity_result t3;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1906(kk_function_t _fself, kk_box_t _b_x862, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10190_fun1906(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1906__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1906__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1906, kk_context());
  _self->t1 = t1;
  _self->t2 = t2;
  _self->t3 = t3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1906(kk_function_t _fself, kk_box_t _b_x862, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1906__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10190_fun1906__t*, _fself, _ctx);
  kk_src_dream__cycle__triage_result t1 = _self->t1; /* src/dream_cycle/triage-result */
  kk_src_dream__cycle__consolidation_result t2 = _self->t2; /* src/dream_cycle/consolidation-result */
  kk_src_dream__cycle__serendipity_result t3 = _self->t3; /* src/dream_cycle/serendipity-result */
  kk_drop_match(_self, {kk_src_dream__cycle__triage_result_dup(t1, _ctx);kk_src_dream__cycle__consolidation_result_dup(t2, _ctx);kk_src_dream__cycle__serendipity_result_dup(t3, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__governance_result t4_864 = kk_src_dream__cycle__governance_result_unbox(_b_x862, KK_OWNED, _ctx); /*src/dream_cycle/governance-result*/;
  kk_src_dream__cycle__dream_summary _x_x1907 = kk_src_dream__cycle__mlift_run_dream_cycle_10189(t1, t2, t3, t4_864, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1907, _ctx);
}

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10190(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_src_dream__cycle__serendipity_result t3, kk_context_t* _ctx) { /* (t1 : triage-result, t2 : consolidation-result, t3 : serendipity-result) -> <insight-ops,memory-ops,decay-ops,governance-ops,kaizen-ops,narrative-ops,oracle-ops,constellation-ops> dream-summary */ 
  kk_ssize_t _b_x857_859 = (KK_IZ(2)); /*hnd/ev-index*/;
  kk_src_dream__cycle__governance_result x_10490;
  kk_box_t _x_x1902 = kk_std_core_hnd__open_at0(_b_x857_859, kk_src_dream__cycle__new_mlift_run_dream_cycle_10190_fun1903(_ctx), _ctx); /*10000*/
  x_10490 = kk_src_dream__cycle__governance_result_unbox(_x_x1902, KK_OWNED, _ctx); /*src/dream_cycle/governance-result*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10490, (KK_I32(2)), _ctx);
    kk_box_t _x_x1905 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_run_dream_cycle_10190_fun1906(t1, t2, t3, _ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__dream_summary_unbox(_x_x1905, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__mlift_run_dream_cycle_10189(t1, t2, t3, x_10490, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1911__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1911(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10191_fun1911(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1911, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1911(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__serendipity_result _x_x1912 = kk_src_dream__cycle_phase_serendipity(_ctx); /*src/dream_cycle/serendipity-result*/
  return kk_src_dream__cycle__serendipity_result_box(_x_x1912, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1914__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__triage_result t1;
  kk_src_dream__cycle__consolidation_result t2;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1914(kk_function_t _fself, kk_box_t _b_x878, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10191_fun1914(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1914__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1914__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1914, kk_context());
  _self->t1 = t1;
  _self->t2 = t2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1914(kk_function_t _fself, kk_box_t _b_x878, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1914__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10191_fun1914__t*, _fself, _ctx);
  kk_src_dream__cycle__triage_result t1 = _self->t1; /* src/dream_cycle/triage-result */
  kk_src_dream__cycle__consolidation_result t2 = _self->t2; /* src/dream_cycle/consolidation-result */
  kk_drop_match(_self, {kk_src_dream__cycle__triage_result_dup(t1, _ctx);kk_src_dream__cycle__consolidation_result_dup(t2, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__serendipity_result t3_880 = kk_src_dream__cycle__serendipity_result_unbox(_b_x878, KK_OWNED, _ctx); /*src/dream_cycle/serendipity-result*/;
  kk_src_dream__cycle__dream_summary _x_x1915 = kk_src_dream__cycle__mlift_run_dream_cycle_10190(t1, t2, t3_880, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1915, _ctx);
}

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10191(kk_src_dream__cycle__triage_result t1, kk_src_dream__cycle__consolidation_result t2, kk_context_t* _ctx) { /* (t1 : triage-result, t2 : consolidation-result) -> <constellation-ops,decay-ops,governance-ops,insight-ops,kaizen-ops,memory-ops,narrative-ops,oracle-ops> dream-summary */ 
  kk_ssize_t _b_x867_873 = (KK_IZ(3)); /*hnd/ev-index*/;
  kk_ssize_t _b_x865_875 = (KK_IZ(5)); /*hnd/ev-index*/;
  kk_vector_t _b_x869_871;
  kk_vector_t _vec_x1908 = kk_std_core_vector__unsafe_vector((KK_IZ(2)), _ctx);
  kk_box_t* _buf_x1909 = kk_vector_buf_borrow(_vec_x1908, NULL, _ctx);
  _buf_x1909[0] = kk_ssize_box(_b_x867_873, _ctx);
  _buf_x1909[1] = kk_ssize_box(_b_x865_875, _ctx);
  _b_x869_871 = _vec_x1908; /*vector<hnd/ev-index>*/
  kk_src_dream__cycle__serendipity_result x_10492;
  kk_box_t _x_x1910 = kk_std_core_hnd__open0(_b_x869_871, kk_src_dream__cycle__new_mlift_run_dream_cycle_10191_fun1911(_ctx), _ctx); /*10000*/
  x_10492 = kk_src_dream__cycle__serendipity_result_unbox(_x_x1910, KK_OWNED, _ctx); /*src/dream_cycle/serendipity-result*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10492, (KK_I32(3)), _ctx);
    kk_box_t _x_x1913 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_run_dream_cycle_10191_fun1914(t1, t2, _ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__dream_summary_unbox(_x_x1913, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__mlift_run_dream_cycle_10190(t1, t2, x_10492, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1917__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1917(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10192_fun1917(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1917, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1917(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__consolidation_result _x_x1918 = kk_src_dream__cycle_phase_consolidation(_ctx); /*src/dream_cycle/consolidation-result*/
  return kk_src_dream__cycle__consolidation_result_box(_x_x1918, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1920__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__triage_result t1;
};
static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1920(kk_function_t _fself, kk_box_t _b_x886, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_run_dream_cycle_10192_fun1920(kk_src_dream__cycle__triage_result t1, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1920__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1920__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1920, kk_context());
  _self->t1 = t1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1920(kk_function_t _fself, kk_box_t _b_x886, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1920__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_run_dream_cycle_10192_fun1920__t*, _fself, _ctx);
  kk_src_dream__cycle__triage_result t1 = _self->t1; /* src/dream_cycle/triage-result */
  kk_drop_match(_self, {kk_src_dream__cycle__triage_result_dup(t1, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__consolidation_result t2_888 = kk_src_dream__cycle__consolidation_result_unbox(_b_x886, KK_OWNED, _ctx); /*src/dream_cycle/consolidation-result*/;
  kk_src_dream__cycle__dream_summary _x_x1921 = kk_src_dream__cycle__mlift_run_dream_cycle_10191(t1, t2_888, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1921, _ctx);
}

kk_src_dream__cycle__dream_summary kk_src_dream__cycle__mlift_run_dream_cycle_10192(kk_src_dream__cycle__triage_result t1, kk_context_t* _ctx) { /* (t1 : triage-result) -> <memory-ops,constellation-ops,decay-ops,governance-ops,insight-ops,kaizen-ops,narrative-ops,oracle-ops> dream-summary */ 
  kk_ssize_t _b_x881_883 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_src_dream__cycle__consolidation_result x_10494;
  kk_box_t _x_x1916 = kk_std_core_hnd__open_at0(_b_x881_883, kk_src_dream__cycle__new_mlift_run_dream_cycle_10192_fun1917(_ctx), _ctx); /*10000*/
  x_10494 = kk_src_dream__cycle__consolidation_result_unbox(_x_x1916, KK_OWNED, _ctx); /*src/dream_cycle/consolidation-result*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10494, (KK_I32(2)), _ctx);
    kk_box_t _x_x1919 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_run_dream_cycle_10192_fun1920(t1, _ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__dream_summary_unbox(_x_x1919, KK_OWNED, _ctx);
  }
  {
    return kk_src_dream__cycle__mlift_run_dream_cycle_10191(t1, x_10494, _ctx);
  }
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1923__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1923(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1923(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_run_dream_cycle_fun1923, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1923(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__triage_result _x_x1924 = kk_src_dream__cycle_phase_triage(_ctx); /*src/dream_cycle/triage-result*/
  return kk_src_dream__cycle__triage_result_box(_x_x1924, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1926__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1926(kk_function_t _fself, kk_box_t _b_x894, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1926(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_run_dream_cycle_fun1926, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1926(kk_function_t _fself, kk_box_t _b_x894, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__dream_summary _x_x1927;
  kk_src_dream__cycle__triage_result _x_x1928 = kk_src_dream__cycle__triage_result_unbox(_b_x894, KK_OWNED, _ctx); /*src/dream_cycle/triage-result*/
  _x_x1927 = kk_src_dream__cycle__mlift_run_dream_cycle_10192(_x_x1928, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1927, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1930__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1930(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1930(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_run_dream_cycle_fun1930, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1930(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__consolidation_result _x_x1931 = kk_src_dream__cycle_phase_consolidation(_ctx); /*src/dream_cycle/consolidation-result*/
  return kk_src_dream__cycle__consolidation_result_box(_x_x1931, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1933__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__triage_result x_10496;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1933(kk_function_t _fself, kk_box_t _b_x900, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1933(kk_src_dream__cycle__triage_result x_10496, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1933__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_run_dream_cycle_fun1933__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_run_dream_cycle_fun1933, kk_context());
  _self->x_10496 = x_10496;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1933(kk_function_t _fself, kk_box_t _b_x900, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1933__t* _self = kk_function_as(struct kk_src_dream__cycle_run_dream_cycle_fun1933__t*, _fself, _ctx);
  kk_src_dream__cycle__triage_result x_10496 = _self->x_10496; /* src/dream_cycle/triage-result */
  kk_drop_match(_self, {kk_src_dream__cycle__triage_result_dup(x_10496, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__consolidation_result t2_985 = kk_src_dream__cycle__consolidation_result_unbox(_b_x900, KK_OWNED, _ctx); /*src/dream_cycle/consolidation-result*/;
  kk_src_dream__cycle__dream_summary _x_x1934 = kk_src_dream__cycle__mlift_run_dream_cycle_10191(x_10496, t2_985, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1934, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1938__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1938(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1938(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_run_dream_cycle_fun1938, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1938(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__serendipity_result _x_x1939 = kk_src_dream__cycle_phase_serendipity(_ctx); /*src/dream_cycle/serendipity-result*/
  return kk_src_dream__cycle__serendipity_result_box(_x_x1939, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1941__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__consolidation_result x_0_10499;
  kk_src_dream__cycle__triage_result x_10496;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1941(kk_function_t _fself, kk_box_t _b_x914, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1941(kk_src_dream__cycle__consolidation_result x_0_10499, kk_src_dream__cycle__triage_result x_10496, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1941__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_run_dream_cycle_fun1941__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_run_dream_cycle_fun1941, kk_context());
  _self->x_0_10499 = x_0_10499;
  _self->x_10496 = x_10496;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1941(kk_function_t _fself, kk_box_t _b_x914, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1941__t* _self = kk_function_as(struct kk_src_dream__cycle_run_dream_cycle_fun1941__t*, _fself, _ctx);
  kk_src_dream__cycle__consolidation_result x_0_10499 = _self->x_0_10499; /* src/dream_cycle/consolidation-result */
  kk_src_dream__cycle__triage_result x_10496 = _self->x_10496; /* src/dream_cycle/triage-result */
  kk_drop_match(_self, {kk_src_dream__cycle__consolidation_result_dup(x_0_10499, _ctx);kk_src_dream__cycle__triage_result_dup(x_10496, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__serendipity_result t3_986 = kk_src_dream__cycle__serendipity_result_unbox(_b_x914, KK_OWNED, _ctx); /*src/dream_cycle/serendipity-result*/;
  kk_src_dream__cycle__dream_summary _x_x1942 = kk_src_dream__cycle__mlift_run_dream_cycle_10190(x_10496, x_0_10499, t3_986, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1942, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1944__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1944(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1944(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_run_dream_cycle_fun1944, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1944(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__governance_result _x_x1945 = kk_src_dream__cycle_phase_governance(_ctx); /*src/dream_cycle/governance-result*/
  return kk_src_dream__cycle__governance_result_box(_x_x1945, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1947__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__consolidation_result x_0_10499;
  kk_src_dream__cycle__triage_result x_10496;
  kk_src_dream__cycle__serendipity_result x_1_10502;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1947(kk_function_t _fself, kk_box_t _b_x920, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1947(kk_src_dream__cycle__consolidation_result x_0_10499, kk_src_dream__cycle__triage_result x_10496, kk_src_dream__cycle__serendipity_result x_1_10502, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1947__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_run_dream_cycle_fun1947__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_run_dream_cycle_fun1947, kk_context());
  _self->x_0_10499 = x_0_10499;
  _self->x_10496 = x_10496;
  _self->x_1_10502 = x_1_10502;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1947(kk_function_t _fself, kk_box_t _b_x920, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1947__t* _self = kk_function_as(struct kk_src_dream__cycle_run_dream_cycle_fun1947__t*, _fself, _ctx);
  kk_src_dream__cycle__consolidation_result x_0_10499 = _self->x_0_10499; /* src/dream_cycle/consolidation-result */
  kk_src_dream__cycle__triage_result x_10496 = _self->x_10496; /* src/dream_cycle/triage-result */
  kk_src_dream__cycle__serendipity_result x_1_10502 = _self->x_1_10502; /* src/dream_cycle/serendipity-result */
  kk_drop_match(_self, {kk_src_dream__cycle__consolidation_result_dup(x_0_10499, _ctx);kk_src_dream__cycle__triage_result_dup(x_10496, _ctx);kk_src_dream__cycle__serendipity_result_dup(x_1_10502, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__governance_result t4_987 = kk_src_dream__cycle__governance_result_unbox(_b_x920, KK_OWNED, _ctx); /*src/dream_cycle/governance-result*/;
  kk_src_dream__cycle__dream_summary _x_x1948 = kk_src_dream__cycle__mlift_run_dream_cycle_10189(x_10496, x_0_10499, x_1_10502, t4_987, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1948, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1950__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1950(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1950(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_run_dream_cycle_fun1950, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1950(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__narrative_result _x_x1951 = kk_src_dream__cycle_phase_narrative(_ctx); /*src/dream_cycle/narrative-result*/
  return kk_src_dream__cycle__narrative_result_box(_x_x1951, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1953__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__consolidation_result x_0_10499;
  kk_src_dream__cycle__triage_result x_10496;
  kk_src_dream__cycle__serendipity_result x_1_10502;
  kk_src_dream__cycle__governance_result x_2_10505;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1953(kk_function_t _fself, kk_box_t _b_x926, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1953(kk_src_dream__cycle__consolidation_result x_0_10499, kk_src_dream__cycle__triage_result x_10496, kk_src_dream__cycle__serendipity_result x_1_10502, kk_src_dream__cycle__governance_result x_2_10505, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1953__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_run_dream_cycle_fun1953__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_run_dream_cycle_fun1953, kk_context());
  _self->x_0_10499 = x_0_10499;
  _self->x_10496 = x_10496;
  _self->x_1_10502 = x_1_10502;
  _self->x_2_10505 = x_2_10505;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1953(kk_function_t _fself, kk_box_t _b_x926, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1953__t* _self = kk_function_as(struct kk_src_dream__cycle_run_dream_cycle_fun1953__t*, _fself, _ctx);
  kk_src_dream__cycle__consolidation_result x_0_10499 = _self->x_0_10499; /* src/dream_cycle/consolidation-result */
  kk_src_dream__cycle__triage_result x_10496 = _self->x_10496; /* src/dream_cycle/triage-result */
  kk_src_dream__cycle__serendipity_result x_1_10502 = _self->x_1_10502; /* src/dream_cycle/serendipity-result */
  kk_src_dream__cycle__governance_result x_2_10505 = _self->x_2_10505; /* src/dream_cycle/governance-result */
  kk_drop_match(_self, {kk_src_dream__cycle__consolidation_result_dup(x_0_10499, _ctx);kk_src_dream__cycle__triage_result_dup(x_10496, _ctx);kk_src_dream__cycle__serendipity_result_dup(x_1_10502, _ctx);kk_src_dream__cycle__governance_result_dup(x_2_10505, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__narrative_result t5_988 = kk_src_dream__cycle__narrative_result_unbox(_b_x926, KK_OWNED, _ctx); /*src/dream_cycle/narrative-result*/;
  kk_src_dream__cycle__dream_summary _x_x1954 = kk_src_dream__cycle__mlift_run_dream_cycle_10188(x_10496, x_0_10499, x_1_10502, x_2_10505, t5_988, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1954, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1956__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1956(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1956(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_run_dream_cycle_fun1956, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1956(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__kaizen_result _x_x1957 = kk_src_dream__cycle_phase_kaizen(_ctx); /*src/dream_cycle/kaizen-result*/
  return kk_src_dream__cycle__kaizen_result_box(_x_x1957, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1959__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__consolidation_result x_0_10499;
  kk_src_dream__cycle__triage_result x_10496;
  kk_src_dream__cycle__serendipity_result x_1_10502;
  kk_src_dream__cycle__governance_result x_2_10505;
  kk_src_dream__cycle__narrative_result x_3_10508;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1959(kk_function_t _fself, kk_box_t _b_x932, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1959(kk_src_dream__cycle__consolidation_result x_0_10499, kk_src_dream__cycle__triage_result x_10496, kk_src_dream__cycle__serendipity_result x_1_10502, kk_src_dream__cycle__governance_result x_2_10505, kk_src_dream__cycle__narrative_result x_3_10508, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1959__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_run_dream_cycle_fun1959__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_run_dream_cycle_fun1959, kk_context());
  _self->x_0_10499 = x_0_10499;
  _self->x_10496 = x_10496;
  _self->x_1_10502 = x_1_10502;
  _self->x_2_10505 = x_2_10505;
  _self->x_3_10508 = x_3_10508;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1959(kk_function_t _fself, kk_box_t _b_x932, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1959__t* _self = kk_function_as(struct kk_src_dream__cycle_run_dream_cycle_fun1959__t*, _fself, _ctx);
  kk_src_dream__cycle__consolidation_result x_0_10499 = _self->x_0_10499; /* src/dream_cycle/consolidation-result */
  kk_src_dream__cycle__triage_result x_10496 = _self->x_10496; /* src/dream_cycle/triage-result */
  kk_src_dream__cycle__serendipity_result x_1_10502 = _self->x_1_10502; /* src/dream_cycle/serendipity-result */
  kk_src_dream__cycle__governance_result x_2_10505 = _self->x_2_10505; /* src/dream_cycle/governance-result */
  kk_src_dream__cycle__narrative_result x_3_10508 = _self->x_3_10508; /* src/dream_cycle/narrative-result */
  kk_drop_match(_self, {kk_src_dream__cycle__consolidation_result_dup(x_0_10499, _ctx);kk_src_dream__cycle__triage_result_dup(x_10496, _ctx);kk_src_dream__cycle__serendipity_result_dup(x_1_10502, _ctx);kk_src_dream__cycle__governance_result_dup(x_2_10505, _ctx);kk_src_dream__cycle__narrative_result_dup(x_3_10508, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__kaizen_result t6_989 = kk_src_dream__cycle__kaizen_result_unbox(_b_x932, KK_OWNED, _ctx); /*src/dream_cycle/kaizen-result*/;
  kk_src_dream__cycle__dream_summary _x_x1960 = kk_src_dream__cycle__mlift_run_dream_cycle_10187(x_10496, x_0_10499, x_1_10502, x_2_10505, x_3_10508, t6_989, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1960, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1962__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1962(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1962(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_run_dream_cycle_fun1962, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1977__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1977(kk_function_t _fself, kk_box_t _b_x950, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1977(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_run_dream_cycle_fun1977, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1977(kk_function_t _fself, kk_box_t _b_x950, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__oracle_result _x_x1978;
  kk_std_core_types__list _x_x1979 = kk_std_core_types__list_unbox(_b_x950, KK_OWNED, _ctx); /*list<string>*/
  _x_x1978 = kk_src_dream__cycle__mlift_run_dream_cycle_10185(_x_x1979, _ctx); /*src/dream_cycle/oracle-result*/
  return kk_src_dream__cycle__oracle_result_box(_x_x1978, _ctx);
}
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1962(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev ev_10519 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/oracle-ops>*/;
  kk_std_core_types__list x_6_10517;
  kk_box_t _x_x1963;
  {
    struct kk_std_core_hnd_Ev* _con_x1964 = kk_std_core_hnd__as_Ev(ev_10519, _ctx);
    kk_box_t _box_x933 = _con_x1964->hnd;
    int32_t m = _con_x1964->marker;
    kk_src_dream__cycle__oracle_ops h = kk_src_dream__cycle__oracle_ops_unbox(_box_x933, KK_BORROWED, _ctx);
    kk_src_dream__cycle__oracle_ops_dup(h, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_oracle_ops* _con_x1965 = kk_src_dream__cycle__as_Hnd_oracle_ops(h, _ctx);
      kk_integer_t _pat_0_5 = _con_x1965->_cfc;
      kk_std_core_hnd__clause1 _pat_1_1 = _con_x1965->_fun_generate_suggestion;
      kk_std_core_hnd__clause1 _fun_predict_next_session = _con_x1965->_fun_predict_next_session;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0_5, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_predict_next_session, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x937 = _fun_predict_next_session.clause;
        kk_box_t _x_x1966;
        kk_std_core_types__list _x_x1967;
        kk_box_t _x_x1968;
        kk_string_t _x_x1969;
        kk_define_string_literal(, _s_x1970, 11, "recent-work", _ctx)
        _x_x1969 = kk_string_dup(_s_x1970, _ctx); /*string*/
        _x_x1968 = kk_string_box(_x_x1969); /*10021*/
        kk_std_core_types__list _x_x1971;
        kk_box_t _x_x1972;
        kk_string_t _x_x1973;
        kk_define_string_literal(, _s_x1974, 14, "open-campaigns", _ctx)
        _x_x1973 = kk_string_dup(_s_x1974, _ctx); /*string*/
        _x_x1972 = kk_string_box(_x_x1973); /*10021*/
        _x_x1971 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1972, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
        _x_x1967 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1968, _x_x1971, _ctx); /*list<10021>*/
        _x_x1966 = kk_std_core_types__list_box(_x_x1967, _ctx); /*10009*/
        _x_x1963 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x937, (_fun_unbox_x937, m, ev_10519, _x_x1966, _ctx), _ctx); /*10010*/
      }
    }
  }
  x_6_10517 = kk_std_core_types__list_unbox(_x_x1963, KK_OWNED, _ctx); /*list<string>*/
  kk_src_dream__cycle__oracle_result _x_x1975;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_6_10517, _ctx);
    kk_box_t _x_x1976 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_run_dream_cycle_fun1977(_ctx), _ctx); /*10001*/
    _x_x1975 = kk_src_dream__cycle__oracle_result_unbox(_x_x1976, KK_OWNED, _ctx); /*src/dream_cycle/oracle-result*/
  }
  else {
    _x_x1975 = kk_src_dream__cycle__new_Oracle_result(x_6_10517, _ctx); /*src/dream_cycle/oracle-result*/
  }
  return kk_src_dream__cycle__oracle_result_box(_x_x1975, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1981__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__consolidation_result x_0_10499;
  kk_src_dream__cycle__triage_result x_10496;
  kk_src_dream__cycle__serendipity_result x_1_10502;
  kk_src_dream__cycle__governance_result x_2_10505;
  kk_src_dream__cycle__narrative_result x_3_10508;
  kk_src_dream__cycle__kaizen_result x_4_10511;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1981(kk_function_t _fself, kk_box_t _b_x957, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1981(kk_src_dream__cycle__consolidation_result x_0_10499, kk_src_dream__cycle__triage_result x_10496, kk_src_dream__cycle__serendipity_result x_1_10502, kk_src_dream__cycle__governance_result x_2_10505, kk_src_dream__cycle__narrative_result x_3_10508, kk_src_dream__cycle__kaizen_result x_4_10511, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1981__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_run_dream_cycle_fun1981__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_run_dream_cycle_fun1981, kk_context());
  _self->x_0_10499 = x_0_10499;
  _self->x_10496 = x_10496;
  _self->x_1_10502 = x_1_10502;
  _self->x_2_10505 = x_2_10505;
  _self->x_3_10508 = x_3_10508;
  _self->x_4_10511 = x_4_10511;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1981(kk_function_t _fself, kk_box_t _b_x957, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1981__t* _self = kk_function_as(struct kk_src_dream__cycle_run_dream_cycle_fun1981__t*, _fself, _ctx);
  kk_src_dream__cycle__consolidation_result x_0_10499 = _self->x_0_10499; /* src/dream_cycle/consolidation-result */
  kk_src_dream__cycle__triage_result x_10496 = _self->x_10496; /* src/dream_cycle/triage-result */
  kk_src_dream__cycle__serendipity_result x_1_10502 = _self->x_1_10502; /* src/dream_cycle/serendipity-result */
  kk_src_dream__cycle__governance_result x_2_10505 = _self->x_2_10505; /* src/dream_cycle/governance-result */
  kk_src_dream__cycle__narrative_result x_3_10508 = _self->x_3_10508; /* src/dream_cycle/narrative-result */
  kk_src_dream__cycle__kaizen_result x_4_10511 = _self->x_4_10511; /* src/dream_cycle/kaizen-result */
  kk_drop_match(_self, {kk_src_dream__cycle__consolidation_result_dup(x_0_10499, _ctx);kk_src_dream__cycle__triage_result_dup(x_10496, _ctx);kk_src_dream__cycle__serendipity_result_dup(x_1_10502, _ctx);kk_src_dream__cycle__governance_result_dup(x_2_10505, _ctx);kk_src_dream__cycle__narrative_result_dup(x_3_10508, _ctx);kk_src_dream__cycle__kaizen_result_dup(x_4_10511, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__oracle_result t7_990 = kk_src_dream__cycle__oracle_result_unbox(_b_x957, KK_OWNED, _ctx); /*src/dream_cycle/oracle-result*/;
  kk_src_dream__cycle__dream_summary _x_x1982 = kk_src_dream__cycle__mlift_run_dream_cycle_10186(x_10496, x_0_10499, x_1_10502, x_2_10505, x_3_10508, x_4_10511, t7_990, _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1982, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1984__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1984(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1984(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_run_dream_cycle_fun1984, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1990__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1990(kk_function_t _fself, kk_box_t _b_x969, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1990(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_run_dream_cycle_fun1990, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1990(kk_function_t _fself, kk_box_t _b_x969, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_dream__cycle__decay_result _x_x1991;
  kk_integer_t _x_x1992 = kk_integer_unbox(_b_x969, _ctx); /*int*/
  _x_x1991 = kk_src_dream__cycle__mlift_run_dream_cycle_10183(_x_x1992, _ctx); /*src/dream_cycle/decay-result*/
  return kk_src_dream__cycle__decay_result_box(_x_x1991, _ctx);
}
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1984(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev evx_10527 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/dream_cycle/decay-ops>*/;
  kk_integer_t x_9_10525;
  kk_box_t _x_x1985;
  {
    struct kk_std_core_hnd_Ev* _con_x1986 = kk_std_core_hnd__as_Ev(evx_10527, _ctx);
    kk_box_t _box_x958 = _con_x1986->hnd;
    int32_t m_0 = _con_x1986->marker;
    kk_src_dream__cycle__decay_ops h_0 = kk_src_dream__cycle__decay_ops_unbox(_box_x958, KK_BORROWED, _ctx);
    kk_src_dream__cycle__decay_ops_dup(h_0, _ctx);
    {
      struct kk_src_dream__cycle__Hnd_decay_ops* _con_x1987 = kk_src_dream__cycle__as_Hnd_decay_ops(h_0, _ctx);
      kk_integer_t _pat_0_8 = _con_x1987->_cfc;
      kk_std_core_hnd__clause1 _pat_1_2 = _con_x1987->_fun_archive_memory;
      kk_std_core_hnd__clause1 _pat_2_1 = _con_x1987->_fun_get_decay_candidates;
      kk_std_core_hnd__clause2 _fun_sweep_old_memories = _con_x1987->_fun_sweep_old_memories;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_1, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_8, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_sweep_old_memories, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x963 = _fun_sweep_old_memories.clause;
        _x_x1985 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x963, (_fun_unbox_x963, m_0, evx_10527, kk_integer_box(kk_integer_from_small(90), _ctx), kk_double_box(0x1.999999999999ap-3, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  x_9_10525 = kk_integer_unbox(_x_x1985, _ctx); /*int*/
  kk_src_dream__cycle__decay_result _x_x1988;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_9_10525, _ctx);
    kk_box_t _x_x1989 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_run_dream_cycle_fun1990(_ctx), _ctx); /*10001*/
    _x_x1988 = kk_src_dream__cycle__decay_result_unbox(_x_x1989, KK_OWNED, _ctx); /*src/dream_cycle/decay-result*/
  }
  else {
    _x_x1988 = kk_src_dream__cycle__new_Decay_result(x_9_10525, _ctx); /*src/dream_cycle/decay-result*/
  }
  return kk_src_dream__cycle__decay_result_box(_x_x1988, _ctx);
}


// lift anonymous function
struct kk_src_dream__cycle_run_dream_cycle_fun1994__t {
  struct kk_function_s _base;
  kk_src_dream__cycle__consolidation_result x_0_10499;
  kk_src_dream__cycle__triage_result x_10496;
  kk_src_dream__cycle__serendipity_result x_1_10502;
  kk_src_dream__cycle__governance_result x_2_10505;
  kk_src_dream__cycle__narrative_result x_3_10508;
  kk_src_dream__cycle__kaizen_result x_4_10511;
  kk_src_dream__cycle__oracle_result x_5_10514;
};
static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1994(kk_function_t _fself, kk_box_t _b_x976, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_run_dream_cycle_fun1994(kk_src_dream__cycle__consolidation_result x_0_10499, kk_src_dream__cycle__triage_result x_10496, kk_src_dream__cycle__serendipity_result x_1_10502, kk_src_dream__cycle__governance_result x_2_10505, kk_src_dream__cycle__narrative_result x_3_10508, kk_src_dream__cycle__kaizen_result x_4_10511, kk_src_dream__cycle__oracle_result x_5_10514, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1994__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_run_dream_cycle_fun1994__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_run_dream_cycle_fun1994, kk_context());
  _self->x_0_10499 = x_0_10499;
  _self->x_10496 = x_10496;
  _self->x_1_10502 = x_1_10502;
  _self->x_2_10505 = x_2_10505;
  _self->x_3_10508 = x_3_10508;
  _self->x_4_10511 = x_4_10511;
  _self->x_5_10514 = x_5_10514;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_run_dream_cycle_fun1994(kk_function_t _fself, kk_box_t _b_x976, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_run_dream_cycle_fun1994__t* _self = kk_function_as(struct kk_src_dream__cycle_run_dream_cycle_fun1994__t*, _fself, _ctx);
  kk_src_dream__cycle__consolidation_result x_0_10499 = _self->x_0_10499; /* src/dream_cycle/consolidation-result */
  kk_src_dream__cycle__triage_result x_10496 = _self->x_10496; /* src/dream_cycle/triage-result */
  kk_src_dream__cycle__serendipity_result x_1_10502 = _self->x_1_10502; /* src/dream_cycle/serendipity-result */
  kk_src_dream__cycle__governance_result x_2_10505 = _self->x_2_10505; /* src/dream_cycle/governance-result */
  kk_src_dream__cycle__narrative_result x_3_10508 = _self->x_3_10508; /* src/dream_cycle/narrative-result */
  kk_src_dream__cycle__kaizen_result x_4_10511 = _self->x_4_10511; /* src/dream_cycle/kaizen-result */
  kk_src_dream__cycle__oracle_result x_5_10514 = _self->x_5_10514; /* src/dream_cycle/oracle-result */
  kk_drop_match(_self, {kk_src_dream__cycle__consolidation_result_dup(x_0_10499, _ctx);kk_src_dream__cycle__triage_result_dup(x_10496, _ctx);kk_src_dream__cycle__serendipity_result_dup(x_1_10502, _ctx);kk_src_dream__cycle__governance_result_dup(x_2_10505, _ctx);kk_src_dream__cycle__narrative_result_dup(x_3_10508, _ctx);kk_src_dream__cycle__kaizen_result_dup(x_4_10511, _ctx);kk_src_dream__cycle__oracle_result_dup(x_5_10514, _ctx);}, {}, _ctx)
  kk_src_dream__cycle__decay_result t8_991 = kk_src_dream__cycle__decay_result_unbox(_b_x976, KK_OWNED, _ctx); /*src/dream_cycle/decay-result*/;
  kk_src_dream__cycle__dream_summary _x_x1995 = kk_src_dream__cycle__new_Dream_summary(kk_reuse_null, 0, x_10496, x_0_10499, x_1_10502, x_2_10505, x_3_10508, x_4_10511, x_5_10514, t8_991, kk_integer_from_small(0), _ctx); /*src/dream_cycle/dream-summary*/
  return kk_src_dream__cycle__dream_summary_box(_x_x1995, _ctx);
}

kk_src_dream__cycle__dream_summary kk_src_dream__cycle_run_dream_cycle(kk_context_t* _ctx) { /* () -> <constellation-ops,decay-ops,governance-ops,insight-ops,kaizen-ops,memory-ops,narrative-ops,oracle-ops> dream-summary */ 
  kk_ssize_t _b_x889_891 = (KK_IZ(5)); /*hnd/ev-index*/;
  kk_src_dream__cycle__triage_result x_10496;
  kk_box_t _x_x1922 = kk_std_core_hnd__open_at0(_b_x889_891, kk_src_dream__cycle_new_run_dream_cycle_fun1923(_ctx), _ctx); /*10000*/
  x_10496 = kk_src_dream__cycle__triage_result_unbox(_x_x1922, KK_OWNED, _ctx); /*src/dream_cycle/triage-result*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10496, (KK_I32(2)), _ctx);
    kk_box_t _x_x1925 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_run_dream_cycle_fun1926(_ctx), _ctx); /*10001*/
    return kk_src_dream__cycle__dream_summary_unbox(_x_x1925, KK_OWNED, _ctx);
  }
  {
    kk_ssize_t _b_x895_897 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_src_dream__cycle__consolidation_result x_0_10499;
    kk_box_t _x_x1929 = kk_std_core_hnd__open_at0(_b_x895_897, kk_src_dream__cycle_new_run_dream_cycle_fun1930(_ctx), _ctx); /*10000*/
    x_0_10499 = kk_src_dream__cycle__consolidation_result_unbox(_x_x1929, KK_OWNED, _ctx); /*src/dream_cycle/consolidation-result*/
    if (kk_yielding(kk_context())) {
      kk_datatype_ptr_dropn(x_0_10499, (KK_I32(2)), _ctx);
      kk_box_t _x_x1932 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_run_dream_cycle_fun1933(x_10496, _ctx), _ctx); /*10001*/
      return kk_src_dream__cycle__dream_summary_unbox(_x_x1932, KK_OWNED, _ctx);
    }
    {
      kk_ssize_t _b_x903_909 = (KK_IZ(3)); /*hnd/ev-index*/;
      kk_ssize_t _b_x901_911 = (KK_IZ(5)); /*hnd/ev-index*/;
      kk_vector_t _b_x905_907;
      kk_vector_t _vec_x1935 = kk_std_core_vector__unsafe_vector((KK_IZ(2)), _ctx);
      kk_box_t* _buf_x1936 = kk_vector_buf_borrow(_vec_x1935, NULL, _ctx);
      _buf_x1936[0] = kk_ssize_box(_b_x903_909, _ctx);
      _buf_x1936[1] = kk_ssize_box(_b_x901_911, _ctx);
      _b_x905_907 = _vec_x1935; /*vector<hnd/ev-index>*/
      kk_src_dream__cycle__serendipity_result x_1_10502;
      kk_box_t _x_x1937 = kk_std_core_hnd__open0(_b_x905_907, kk_src_dream__cycle_new_run_dream_cycle_fun1938(_ctx), _ctx); /*10000*/
      x_1_10502 = kk_src_dream__cycle__serendipity_result_unbox(_x_x1937, KK_OWNED, _ctx); /*src/dream_cycle/serendipity-result*/
      if (kk_yielding(kk_context())) {
        kk_datatype_ptr_dropn(x_1_10502, (KK_I32(3)), _ctx);
        kk_box_t _x_x1940 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_run_dream_cycle_fun1941(x_0_10499, x_10496, _ctx), _ctx); /*10001*/
        return kk_src_dream__cycle__dream_summary_unbox(_x_x1940, KK_OWNED, _ctx);
      }
      {
        kk_ssize_t _b_x915_917 = (KK_IZ(2)); /*hnd/ev-index*/;
        kk_src_dream__cycle__governance_result x_2_10505;
        kk_box_t _x_x1943 = kk_std_core_hnd__open_at0(_b_x915_917, kk_src_dream__cycle_new_run_dream_cycle_fun1944(_ctx), _ctx); /*10000*/
        x_2_10505 = kk_src_dream__cycle__governance_result_unbox(_x_x1943, KK_OWNED, _ctx); /*src/dream_cycle/governance-result*/
        if (kk_yielding(kk_context())) {
          kk_datatype_ptr_dropn(x_2_10505, (KK_I32(2)), _ctx);
          kk_box_t _x_x1946 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_run_dream_cycle_fun1947(x_0_10499, x_10496, x_1_10502, _ctx), _ctx); /*10001*/
          return kk_src_dream__cycle__dream_summary_unbox(_x_x1946, KK_OWNED, _ctx);
        }
        {
          kk_ssize_t _b_x921_923 = (KK_IZ(6)); /*hnd/ev-index*/;
          kk_src_dream__cycle__narrative_result x_3_10508;
          kk_box_t _x_x1949 = kk_std_core_hnd__open_at0(_b_x921_923, kk_src_dream__cycle_new_run_dream_cycle_fun1950(_ctx), _ctx); /*10000*/
          x_3_10508 = kk_src_dream__cycle__narrative_result_unbox(_x_x1949, KK_OWNED, _ctx); /*src/dream_cycle/narrative-result*/
          if (kk_yielding(kk_context())) {
            kk_datatype_ptr_dropn(x_3_10508, (KK_I32(3)), _ctx);
            kk_box_t _x_x1952 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_run_dream_cycle_fun1953(x_0_10499, x_10496, x_1_10502, x_2_10505, _ctx), _ctx); /*10001*/
            return kk_src_dream__cycle__dream_summary_unbox(_x_x1952, KK_OWNED, _ctx);
          }
          {
            kk_ssize_t _b_x927_929 = (KK_IZ(4)); /*hnd/ev-index*/;
            kk_src_dream__cycle__kaizen_result x_4_10511;
            kk_box_t _x_x1955 = kk_std_core_hnd__open_at0(_b_x927_929, kk_src_dream__cycle_new_run_dream_cycle_fun1956(_ctx), _ctx); /*10000*/
            x_4_10511 = kk_src_dream__cycle__kaizen_result_unbox(_x_x1955, KK_OWNED, _ctx); /*src/dream_cycle/kaizen-result*/
            if (kk_yielding(kk_context())) {
              kk_datatype_ptr_dropn(x_4_10511, (KK_I32(2)), _ctx);
              kk_box_t _x_x1958 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_run_dream_cycle_fun1959(x_0_10499, x_10496, x_1_10502, x_2_10505, x_3_10508, _ctx), _ctx); /*10001*/
              return kk_src_dream__cycle__dream_summary_unbox(_x_x1958, KK_OWNED, _ctx);
            }
            {
              kk_ssize_t _b_x951_953 = (KK_IZ(7)); /*hnd/ev-index*/;
              kk_src_dream__cycle__oracle_result x_5_10514;
              kk_box_t _x_x1961 = kk_std_core_hnd__open_at0(_b_x951_953, kk_src_dream__cycle_new_run_dream_cycle_fun1962(_ctx), _ctx); /*10000*/
              x_5_10514 = kk_src_dream__cycle__oracle_result_unbox(_x_x1961, KK_OWNED, _ctx); /*src/dream_cycle/oracle-result*/
              if (kk_yielding(kk_context())) {
                kk_src_dream__cycle__oracle_result_drop(x_5_10514, _ctx);
                kk_box_t _x_x1980 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_run_dream_cycle_fun1981(x_0_10499, x_10496, x_1_10502, x_2_10505, x_3_10508, x_4_10511, _ctx), _ctx); /*10001*/
                return kk_src_dream__cycle__dream_summary_unbox(_x_x1980, KK_OWNED, _ctx);
              }
              {
                kk_ssize_t _b_x970_972 = (KK_IZ(1)); /*hnd/ev-index*/;
                kk_src_dream__cycle__decay_result x_8_10522;
                kk_box_t _x_x1983 = kk_std_core_hnd__open_at0(_b_x970_972, kk_src_dream__cycle_new_run_dream_cycle_fun1984(_ctx), _ctx); /*10000*/
                x_8_10522 = kk_src_dream__cycle__decay_result_unbox(_x_x1983, KK_OWNED, _ctx); /*src/dream_cycle/decay-result*/
                if (kk_yielding(kk_context())) {
                  kk_src_dream__cycle__decay_result_drop(x_8_10522, _ctx);
                  kk_box_t _x_x1993 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_run_dream_cycle_fun1994(x_0_10499, x_10496, x_1_10502, x_2_10505, x_3_10508, x_4_10511, x_5_10514, _ctx), _ctx); /*10001*/
                  return kk_src_dream__cycle__dream_summary_unbox(_x_x1993, KK_OWNED, _ctx);
                }
                {
                  return kk_src_dream__cycle__new_Dream_summary(kk_reuse_null, 0, x_10496, x_0_10499, x_1_10502, x_2_10505, x_3_10508, x_4_10511, x_5_10514, x_8_10522, kk_integer_from_small(0), _ctx);
                }
              }
            }
          }
        }
      }
    }
  }
}

kk_unit_t kk_src_dream__cycle_flush_stdout(kk_context_t* _ctx) { /* () -> console/console () */ 
  fflush(stdout); return kk_Unit;
}

kk_string_t kk_src_dream__cycle_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x1059;
  kk_string_t _x_x1996 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x1997 = kk_string_empty(); /*string*/
  _match_x1059 = kk_string_is_eq(_x_x1996,_x_x1997,kk_context()); /*bool*/
  if (_match_x1059) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x1999, 7, "unknown", _ctx)
    return kk_string_dup(_s_x1999, _ctx);
  }
  {
    bool _match_x1060;
    kk_string_t _x_x2000 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x2001;
    kk_define_string_literal(, _s_x2002, 8, "\"status\"", _ctx)
    _x_x2001 = kk_string_dup(_s_x2002, _ctx); /*string*/
    _match_x1060 = kk_string_contains(_x_x2000,_x_x2001,kk_context()); /*bool*/
    if (_match_x1060) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x2003, 6, "status", _ctx)
      return kk_string_dup(_s_x2003, _ctx);
    }
    {
      bool _match_x1061;
      kk_string_t _x_x2004 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x2005;
      kk_define_string_literal(, _s_x2006, 7, "\"reset\"", _ctx)
      _x_x2005 = kk_string_dup(_s_x2006, _ctx); /*string*/
      _match_x1061 = kk_string_contains(_x_x2004,_x_x2005,kk_context()); /*bool*/
      if (_match_x1061) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x2007, 5, "reset", _ctx)
        return kk_string_dup(_s_x2007, _ctx);
      }
      {
        bool _match_x1062;
        kk_string_t _x_x2008;
        kk_define_string_literal(, _s_x2009, 5, "\"run\"", _ctx)
        _x_x2008 = kk_string_dup(_s_x2009, _ctx); /*string*/
        _match_x1062 = kk_string_contains(line,_x_x2008,kk_context()); /*bool*/
        if (_match_x1062) {
          kk_define_string_literal(, _s_x2010, 3, "run", _ctx)
          return kk_string_dup(_s_x2010, _ctx);
        }
        {
          kk_define_string_literal(, _s_x2011, 7, "unknown", _ctx)
          return kk_string_dup(_s_x2011, _ctx);
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_server_loop_10193_fun2013__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_server_loop_10193_fun2013(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_server_loop_10193_fun2013(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_server_loop_10193_fun2013, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_server_loop_10193_fun2013(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x2014 = kk_Unit;
  kk_src_dream__cycle_flush_stdout(_ctx);
  return kk_unit_box(_x_x2014);
}

kk_unit_t kk_src_dream__cycle__mlift_server_loop_10193(kk_string_t _c_x10114, kk_integer_t _c_x10115, kk_integer_t _c_x10116, kk_integer_t _c_x10117, kk_context_t* _ctx) { /* (string, int, int, int) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10114, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x2012 = kk_std_core_hnd__open_none0(kk_src_dream__cycle__new_mlift_server_loop_10193_fun2013(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x2012);
  kk_src_dream__cycle_server_loop(_c_x10115, _c_x10116, _c_x10117, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_server_loop_10194_fun2018__t {
  struct kk_function_s _base;
  kk_string_t _c_x10114_0;
  kk_integer_t _c_x10115_0;
  kk_integer_t _c_x10116_0;
};
static kk_box_t kk_src_dream__cycle__mlift_server_loop_10194_fun2018(kk_function_t _fself, kk_box_t _b_x995, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_server_loop_10194_fun2018(kk_string_t _c_x10114_0, kk_integer_t _c_x10115_0, kk_integer_t _c_x10116_0, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_server_loop_10194_fun2018__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_server_loop_10194_fun2018__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_server_loop_10194_fun2018, kk_context());
  _self->_c_x10114_0 = _c_x10114_0;
  _self->_c_x10115_0 = _c_x10115_0;
  _self->_c_x10116_0 = _c_x10116_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_server_loop_10194_fun2018(kk_function_t _fself, kk_box_t _b_x995, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_server_loop_10194_fun2018__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_server_loop_10194_fun2018__t*, _fself, _ctx);
  kk_string_t _c_x10114_0 = _self->_c_x10114_0; /* string */
  kk_integer_t _c_x10115_0 = _self->_c_x10115_0; /* int */
  kk_integer_t _c_x10116_0 = _self->_c_x10116_0; /* int */
  kk_drop_match(_self, {kk_string_dup(_c_x10114_0, _ctx);kk_integer_dup(_c_x10115_0, _ctx);kk_integer_dup(_c_x10116_0, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10117_0_997 = kk_integer_unbox(_b_x995, _ctx); /*int*/;
  kk_unit_t _x_x2019 = kk_Unit;
  kk_src_dream__cycle__mlift_server_loop_10193(_c_x10114_0, _c_x10115_0, _c_x10116_0, _c_x10117_0_997, _ctx);
  return kk_unit_box(_x_x2019);
}

kk_unit_t kk_src_dream__cycle__mlift_server_loop_10194(kk_string_t _c_x10114_0, kk_integer_t _c_x10115_0, kk_integer_t insights, kk_string_t op, kk_integer_t _c_x10116_0, kk_context_t* _ctx) { /* (string, int, insights : int, op : string, int) -> () */ 
  kk_integer_t x_10539;
  bool _match_x1058;
  kk_string_t _x_x2015;
  kk_define_string_literal(, _s_x2016, 3, "run", _ctx)
  _x_x2015 = kk_string_dup(_s_x2016, _ctx); /*string*/
  _match_x1058 = kk_string_is_eq(op,_x_x2015,kk_context()); /*bool*/
  if (_match_x1058) {
    x_10539 = kk_integer_add_small_const(insights, 3, _ctx); /*int*/
  }
  else {
    x_10539 = insights; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10539, _ctx);
    kk_box_t _x_x2017 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_server_loop_10194_fun2018(_c_x10114_0, _c_x10115_0, _c_x10116_0, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x2017); return kk_Unit;
  }
  {
    kk_src_dream__cycle__mlift_server_loop_10193(_c_x10114_0, _c_x10115_0, _c_x10116_0, x_10539, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_server_loop_10195_fun2024__t {
  struct kk_function_s _base;
  kk_string_t _c_x10114_1;
  kk_integer_t _c_x10115_1;
  kk_integer_t insights_0;
  kk_string_t op_0;
};
static kk_box_t kk_src_dream__cycle__mlift_server_loop_10195_fun2024(kk_function_t _fself, kk_box_t _b_x999, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_server_loop_10195_fun2024(kk_string_t _c_x10114_1, kk_integer_t _c_x10115_1, kk_integer_t insights_0, kk_string_t op_0, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_server_loop_10195_fun2024__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_server_loop_10195_fun2024__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_server_loop_10195_fun2024, kk_context());
  _self->_c_x10114_1 = _c_x10114_1;
  _self->_c_x10115_1 = _c_x10115_1;
  _self->insights_0 = insights_0;
  _self->op_0 = op_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_server_loop_10195_fun2024(kk_function_t _fself, kk_box_t _b_x999, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_server_loop_10195_fun2024__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_server_loop_10195_fun2024__t*, _fself, _ctx);
  kk_string_t _c_x10114_1 = _self->_c_x10114_1; /* string */
  kk_integer_t _c_x10115_1 = _self->_c_x10115_1; /* int */
  kk_integer_t insights_0 = _self->insights_0; /* int */
  kk_string_t op_0 = _self->op_0; /* string */
  kk_drop_match(_self, {kk_string_dup(_c_x10114_1, _ctx);kk_integer_dup(_c_x10115_1, _ctx);kk_integer_dup(insights_0, _ctx);kk_string_dup(op_0, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10116_1_1001 = kk_integer_unbox(_b_x999, _ctx); /*int*/;
  kk_unit_t _x_x2025 = kk_Unit;
  kk_src_dream__cycle__mlift_server_loop_10194(_c_x10114_1, _c_x10115_1, insights_0, op_0, _c_x10116_1_1001, _ctx);
  return kk_unit_box(_x_x2025);
}

kk_unit_t kk_src_dream__cycle__mlift_server_loop_10195(kk_string_t _c_x10114_1, kk_integer_t insights_0, kk_integer_t memories, kk_string_t op_0, kk_integer_t _c_x10115_1, kk_context_t* _ctx) { /* (string, insights : int, memories : int, op : string, int) -> () */ 
  kk_integer_t x_0_10541;
  bool _match_x1056;
  kk_string_t _x_x2020 = kk_string_dup(op_0, _ctx); /*string*/
  kk_string_t _x_x2021;
  kk_define_string_literal(, _s_x2022, 3, "run", _ctx)
  _x_x2021 = kk_string_dup(_s_x2022, _ctx); /*string*/
  _match_x1056 = kk_string_is_eq(_x_x2020,_x_x2021,kk_context()); /*bool*/
  if (_match_x1056) {
    x_0_10541 = kk_integer_add_small_const(memories, 40, _ctx); /*int*/
  }
  else {
    x_0_10541 = memories; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_0_10541, _ctx);
    kk_box_t _x_x2023 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_server_loop_10195_fun2024(_c_x10114_1, _c_x10115_1, insights_0, op_0, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x2023); return kk_Unit;
  }
  {
    kk_src_dream__cycle__mlift_server_loop_10194(_c_x10114_1, _c_x10115_1, insights_0, op_0, x_0_10541, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_server_loop_10196_fun2030__t {
  struct kk_function_s _base;
  kk_string_t _c_x10114_2;
  kk_integer_t insights_1;
  kk_integer_t memories_0;
  kk_string_t op_1;
};
static kk_box_t kk_src_dream__cycle__mlift_server_loop_10196_fun2030(kk_function_t _fself, kk_box_t _b_x1003, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_server_loop_10196_fun2030(kk_string_t _c_x10114_2, kk_integer_t insights_1, kk_integer_t memories_0, kk_string_t op_1, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_server_loop_10196_fun2030__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_server_loop_10196_fun2030__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_server_loop_10196_fun2030, kk_context());
  _self->_c_x10114_2 = _c_x10114_2;
  _self->insights_1 = insights_1;
  _self->memories_0 = memories_0;
  _self->op_1 = op_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_server_loop_10196_fun2030(kk_function_t _fself, kk_box_t _b_x1003, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_server_loop_10196_fun2030__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_server_loop_10196_fun2030__t*, _fself, _ctx);
  kk_string_t _c_x10114_2 = _self->_c_x10114_2; /* string */
  kk_integer_t insights_1 = _self->insights_1; /* int */
  kk_integer_t memories_0 = _self->memories_0; /* int */
  kk_string_t op_1 = _self->op_1; /* string */
  kk_drop_match(_self, {kk_string_dup(_c_x10114_2, _ctx);kk_integer_dup(insights_1, _ctx);kk_integer_dup(memories_0, _ctx);kk_string_dup(op_1, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10115_2_1005 = kk_integer_unbox(_b_x1003, _ctx); /*int*/;
  kk_unit_t _x_x2031 = kk_Unit;
  kk_src_dream__cycle__mlift_server_loop_10195(_c_x10114_2, insights_1, memories_0, op_1, _c_x10115_2_1005, _ctx);
  return kk_unit_box(_x_x2031);
}

kk_unit_t kk_src_dream__cycle__mlift_server_loop_10196(kk_integer_t cycles, kk_integer_t insights_1, kk_integer_t memories_0, kk_string_t op_1, kk_string_t _c_x10114_2, kk_context_t* _ctx) { /* (cycles : int, insights : int, memories : int, op : string, string) -> () */ 
  kk_integer_t x_1_10543;
  bool _match_x1054;
  kk_string_t _x_x2026 = kk_string_dup(op_1, _ctx); /*string*/
  kk_string_t _x_x2027;
  kk_define_string_literal(, _s_x2028, 3, "run", _ctx)
  _x_x2027 = kk_string_dup(_s_x2028, _ctx); /*string*/
  _match_x1054 = kk_string_is_eq(_x_x2026,_x_x2027,kk_context()); /*bool*/
  if (_match_x1054) {
    x_1_10543 = kk_integer_add_small_const(cycles, 1, _ctx); /*int*/
  }
  else {
    x_1_10543 = cycles; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_1_10543, _ctx);
    kk_box_t _x_x2029 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_server_loop_10196_fun2030(_c_x10114_2, insights_1, memories_0, op_1, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x2029); return kk_Unit;
  }
  {
    kk_src_dream__cycle__mlift_server_loop_10195(_c_x10114_2, insights_1, memories_0, op_1, x_1_10543, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_dream__cycle__mlift_server_loop_10197_fun2036__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle__mlift_server_loop_10197_fun2036(kk_function_t _fself, kk_box_t _b_x1008, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_server_loop_10197_fun2036(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle__mlift_server_loop_10197_fun2036, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_server_loop_10197_fun2036(kk_function_t _fself, kk_box_t _b_x1008, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2037;
  kk_string_t _x_x2038 = kk_string_unbox(_b_x1008); /*string*/
  _x_x2037 = kk_src_dream__cycle_extract_op(_x_x2038, _ctx); /*string*/
  return kk_string_box(_x_x2037);
}


// lift anonymous function
struct kk_src_dream__cycle__mlift_server_loop_10197_fun2063__t {
  struct kk_function_s _base;
  kk_integer_t cycles_0;
  kk_integer_t insights_2;
  kk_integer_t memories_1;
  kk_string_t op_2;
};
static kk_box_t kk_src_dream__cycle__mlift_server_loop_10197_fun2063(kk_function_t _fself, kk_box_t _b_x1012, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle__new_mlift_server_loop_10197_fun2063(kk_integer_t cycles_0, kk_integer_t insights_2, kk_integer_t memories_1, kk_string_t op_2, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_server_loop_10197_fun2063__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle__mlift_server_loop_10197_fun2063__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle__mlift_server_loop_10197_fun2063, kk_context());
  _self->cycles_0 = cycles_0;
  _self->insights_2 = insights_2;
  _self->memories_1 = memories_1;
  _self->op_2 = op_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle__mlift_server_loop_10197_fun2063(kk_function_t _fself, kk_box_t _b_x1012, kk_context_t* _ctx) {
  struct kk_src_dream__cycle__mlift_server_loop_10197_fun2063__t* _self = kk_function_as(struct kk_src_dream__cycle__mlift_server_loop_10197_fun2063__t*, _fself, _ctx);
  kk_integer_t cycles_0 = _self->cycles_0; /* int */
  kk_integer_t insights_2 = _self->insights_2; /* int */
  kk_integer_t memories_1 = _self->memories_1; /* int */
  kk_string_t op_2 = _self->op_2; /* string */
  kk_drop_match(_self, {kk_integer_dup(cycles_0, _ctx);kk_integer_dup(insights_2, _ctx);kk_integer_dup(memories_1, _ctx);kk_string_dup(op_2, _ctx);}, {}, _ctx)
  kk_string_t _c_x10114_3_1014 = kk_string_unbox(_b_x1012); /*string*/;
  kk_unit_t _x_x2064 = kk_Unit;
  kk_src_dream__cycle__mlift_server_loop_10196(cycles_0, insights_2, memories_1, op_2, _c_x10114_3_1014, _ctx);
  return kk_unit_box(_x_x2064);
}

kk_unit_t kk_src_dream__cycle__mlift_server_loop_10197(kk_integer_t cycles_0, kk_integer_t insights_2, kk_integer_t memories_1, kk_string_t line, kk_context_t* _ctx) { /* (cycles : int, insights : int, memories : int, line : string) -> <console/console,exn> () */ 
  bool _match_x1051;
  kk_string_t _x_x2032 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x2033 = kk_string_empty(); /*string*/
  _match_x1051 = kk_string_is_neq(_x_x2032,_x_x2033,kk_context()); /*bool*/
  if (_match_x1051) {
    kk_string_t op_2;
    kk_box_t _x_x2035 = kk_std_core_hnd__open_none1(kk_src_dream__cycle__new_mlift_server_loop_10197_fun2036(_ctx), kk_string_box(line), _ctx); /*10001*/
    op_2 = kk_string_unbox(_x_x2035); /*string*/
    kk_string_t x_2_10545;
    if (kk_string_cmp_cstr_borrow(op_2, "status", _ctx) == 0) {
      kk_string_t _x_x2040;
      kk_define_string_literal(, _s_x2041, 11, "{\"cycles\": ", _ctx)
      _x_x2040 = kk_string_dup(_s_x2041, _ctx); /*string*/
      kk_string_t _x_x2042;
      kk_string_t _x_x2043;
      kk_integer_t _x_x2044 = kk_integer_dup(cycles_0, _ctx); /*int*/
      _x_x2043 = kk_std_core_int_show(_x_x2044, _ctx); /*string*/
      kk_string_t _x_x2045;
      kk_string_t _x_x2046;
      kk_define_string_literal(, _s_x2047, 14, ", \"memories\": ", _ctx)
      _x_x2046 = kk_string_dup(_s_x2047, _ctx); /*string*/
      kk_string_t _x_x2048;
      kk_string_t _x_x2049;
      kk_integer_t _x_x2050 = kk_integer_dup(memories_1, _ctx); /*int*/
      _x_x2049 = kk_std_core_int_show(_x_x2050, _ctx); /*string*/
      kk_string_t _x_x2051;
      kk_string_t _x_x2052;
      kk_define_string_literal(, _s_x2053, 14, ", \"insights\": ", _ctx)
      _x_x2052 = kk_string_dup(_s_x2053, _ctx); /*string*/
      kk_string_t _x_x2054;
      kk_string_t _x_x2055;
      kk_integer_t _x_x2056 = kk_integer_dup(insights_2, _ctx); /*int*/
      _x_x2055 = kk_std_core_int_show(_x_x2056, _ctx); /*string*/
      kk_string_t _x_x2057;
      kk_define_string_literal(, _s_x2058, 1, "}", _ctx)
      _x_x2057 = kk_string_dup(_s_x2058, _ctx); /*string*/
      _x_x2054 = kk_std_core_types__lp__plus__plus__rp_(_x_x2055, _x_x2057, _ctx); /*string*/
      _x_x2051 = kk_std_core_types__lp__plus__plus__rp_(_x_x2052, _x_x2054, _ctx); /*string*/
      _x_x2048 = kk_std_core_types__lp__plus__plus__rp_(_x_x2049, _x_x2051, _ctx); /*string*/
      _x_x2045 = kk_std_core_types__lp__plus__plus__rp_(_x_x2046, _x_x2048, _ctx); /*string*/
      _x_x2042 = kk_std_core_types__lp__plus__plus__rp_(_x_x2043, _x_x2045, _ctx); /*string*/
      x_2_10545 = kk_std_core_types__lp__plus__plus__rp_(_x_x2040, _x_x2042, _ctx); /*string*/
      goto _match_x2039;
    }
    if (kk_string_cmp_cstr_borrow(op_2, "reset", _ctx) == 0) {
      kk_define_string_literal(, _s_x2059, 38, "{\"operation\": \"reset\", \"result\": \"ok\"}", _ctx)
      x_2_10545 = kk_string_dup(_s_x2059, _ctx); /*string*/
      goto _match_x2039;
    }
    if (kk_string_cmp_cstr_borrow(op_2, "run", _ctx) == 0) {
      kk_define_string_literal(, _s_x2060, 56, "{\"operation\": \"run\", \"phases\": 8, \"status\": \"simulated\"}", _ctx)
      x_2_10545 = kk_string_dup(_s_x2060, _ctx); /*string*/
      goto _match_x2039;
    }
    {
      kk_define_string_literal(, _s_x2061, 20, "{\"error\": \"unknown\"}", _ctx)
      x_2_10545 = kk_string_dup(_s_x2061, _ctx); /*string*/
    }
    _match_x2039: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_2_10545, _ctx);
      kk_box_t _x_x2062 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle__new_mlift_server_loop_10197_fun2063(cycles_0, insights_2, memories_1, op_2, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x2062); return kk_Unit;
    }
    {
      kk_src_dream__cycle__mlift_server_loop_10196(cycles_0, insights_2, memories_1, op_2, x_2_10545, _ctx); return kk_Unit;
    }
  }
  {
    kk_integer_drop(memories_1, _ctx);
    kk_string_drop(line, _ctx);
    kk_integer_drop(insights_2, _ctx);
    kk_integer_drop(cycles_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_src_dream__cycle_server_loop_fun2066__t {
  struct kk_function_s _base;
  kk_integer_t cycles_1;
  kk_integer_t insights_3;
  kk_integer_t memories_2;
};
static kk_box_t kk_src_dream__cycle_server_loop_fun2066(kk_function_t _fself, kk_box_t _b_x1016, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_server_loop_fun2066(kk_integer_t cycles_1, kk_integer_t insights_3, kk_integer_t memories_2, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_server_loop_fun2066__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_server_loop_fun2066__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_server_loop_fun2066, kk_context());
  _self->cycles_1 = cycles_1;
  _self->insights_3 = insights_3;
  _self->memories_2 = memories_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_server_loop_fun2066(kk_function_t _fself, kk_box_t _b_x1016, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_server_loop_fun2066__t* _self = kk_function_as(struct kk_src_dream__cycle_server_loop_fun2066__t*, _fself, _ctx);
  kk_integer_t cycles_1 = _self->cycles_1; /* int */
  kk_integer_t insights_3 = _self->insights_3; /* int */
  kk_integer_t memories_2 = _self->memories_2; /* int */
  kk_drop_match(_self, {kk_integer_dup(cycles_1, _ctx);kk_integer_dup(insights_3, _ctx);kk_integer_dup(memories_2, _ctx);}, {}, _ctx)
  kk_string_t line_0_1037 = kk_string_unbox(_b_x1016); /*string*/;
  kk_unit_t _x_x2067 = kk_Unit;
  kk_src_dream__cycle__mlift_server_loop_10197(cycles_1, insights_3, memories_2, line_0_1037, _ctx);
  return kk_unit_box(_x_x2067);
}


// lift anonymous function
struct kk_src_dream__cycle_server_loop_fun2072__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_server_loop_fun2072(kk_function_t _fself, kk_box_t _b_x1019, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_server_loop_fun2072(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_server_loop_fun2072, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_server_loop_fun2072(kk_function_t _fself, kk_box_t _b_x1019, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2073;
  kk_string_t _x_x2074 = kk_string_unbox(_b_x1019); /*string*/
  _x_x2073 = kk_src_dream__cycle_extract_op(_x_x2074, _ctx); /*string*/
  return kk_string_box(_x_x2073);
}


// lift anonymous function
struct kk_src_dream__cycle_server_loop_fun2099__t {
  struct kk_function_s _base;
  kk_integer_t cycles_1;
  kk_integer_t insights_3;
  kk_integer_t memories_2;
  kk_string_t op_3;
};
static kk_box_t kk_src_dream__cycle_server_loop_fun2099(kk_function_t _fself, kk_box_t _b_x1023, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_server_loop_fun2099(kk_integer_t cycles_1, kk_integer_t insights_3, kk_integer_t memories_2, kk_string_t op_3, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_server_loop_fun2099__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_server_loop_fun2099__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_server_loop_fun2099, kk_context());
  _self->cycles_1 = cycles_1;
  _self->insights_3 = insights_3;
  _self->memories_2 = memories_2;
  _self->op_3 = op_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_server_loop_fun2099(kk_function_t _fself, kk_box_t _b_x1023, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_server_loop_fun2099__t* _self = kk_function_as(struct kk_src_dream__cycle_server_loop_fun2099__t*, _fself, _ctx);
  kk_integer_t cycles_1 = _self->cycles_1; /* int */
  kk_integer_t insights_3 = _self->insights_3; /* int */
  kk_integer_t memories_2 = _self->memories_2; /* int */
  kk_string_t op_3 = _self->op_3; /* string */
  kk_drop_match(_self, {kk_integer_dup(cycles_1, _ctx);kk_integer_dup(insights_3, _ctx);kk_integer_dup(memories_2, _ctx);kk_string_dup(op_3, _ctx);}, {}, _ctx)
  kk_string_t _c_x10114_4_1038 = kk_string_unbox(_b_x1023); /*string*/;
  kk_unit_t _x_x2100 = kk_Unit;
  kk_src_dream__cycle__mlift_server_loop_10196(cycles_1, insights_3, memories_2, op_3, _c_x10114_4_1038, _ctx);
  return kk_unit_box(_x_x2100);
}


// lift anonymous function
struct kk_src_dream__cycle_server_loop_fun2105__t {
  struct kk_function_s _base;
  kk_integer_t insights_3;
  kk_integer_t memories_2;
  kk_string_t op_3;
  kk_string_t x_4_10550;
};
static kk_box_t kk_src_dream__cycle_server_loop_fun2105(kk_function_t _fself, kk_box_t _b_x1025, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_server_loop_fun2105(kk_integer_t insights_3, kk_integer_t memories_2, kk_string_t op_3, kk_string_t x_4_10550, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_server_loop_fun2105__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_server_loop_fun2105__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_server_loop_fun2105, kk_context());
  _self->insights_3 = insights_3;
  _self->memories_2 = memories_2;
  _self->op_3 = op_3;
  _self->x_4_10550 = x_4_10550;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_server_loop_fun2105(kk_function_t _fself, kk_box_t _b_x1025, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_server_loop_fun2105__t* _self = kk_function_as(struct kk_src_dream__cycle_server_loop_fun2105__t*, _fself, _ctx);
  kk_integer_t insights_3 = _self->insights_3; /* int */
  kk_integer_t memories_2 = _self->memories_2; /* int */
  kk_string_t op_3 = _self->op_3; /* string */
  kk_string_t x_4_10550 = _self->x_4_10550; /* string */
  kk_drop_match(_self, {kk_integer_dup(insights_3, _ctx);kk_integer_dup(memories_2, _ctx);kk_string_dup(op_3, _ctx);kk_string_dup(x_4_10550, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10115_3_1039 = kk_integer_unbox(_b_x1025, _ctx); /*int*/;
  kk_unit_t _x_x2106 = kk_Unit;
  kk_src_dream__cycle__mlift_server_loop_10195(x_4_10550, insights_3, memories_2, op_3, _c_x10115_3_1039, _ctx);
  return kk_unit_box(_x_x2106);
}


// lift anonymous function
struct kk_src_dream__cycle_server_loop_fun2111__t {
  struct kk_function_s _base;
  kk_integer_t insights_3;
  kk_string_t op_3;
  kk_string_t x_4_10550;
  kk_integer_t x_5_10553;
};
static kk_box_t kk_src_dream__cycle_server_loop_fun2111(kk_function_t _fself, kk_box_t _b_x1027, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_server_loop_fun2111(kk_integer_t insights_3, kk_string_t op_3, kk_string_t x_4_10550, kk_integer_t x_5_10553, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_server_loop_fun2111__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_server_loop_fun2111__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_server_loop_fun2111, kk_context());
  _self->insights_3 = insights_3;
  _self->op_3 = op_3;
  _self->x_4_10550 = x_4_10550;
  _self->x_5_10553 = x_5_10553;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_server_loop_fun2111(kk_function_t _fself, kk_box_t _b_x1027, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_server_loop_fun2111__t* _self = kk_function_as(struct kk_src_dream__cycle_server_loop_fun2111__t*, _fself, _ctx);
  kk_integer_t insights_3 = _self->insights_3; /* int */
  kk_string_t op_3 = _self->op_3; /* string */
  kk_string_t x_4_10550 = _self->x_4_10550; /* string */
  kk_integer_t x_5_10553 = _self->x_5_10553; /* int */
  kk_drop_match(_self, {kk_integer_dup(insights_3, _ctx);kk_string_dup(op_3, _ctx);kk_string_dup(x_4_10550, _ctx);kk_integer_dup(x_5_10553, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10116_2_1040 = kk_integer_unbox(_b_x1027, _ctx); /*int*/;
  kk_unit_t _x_x2112 = kk_Unit;
  kk_src_dream__cycle__mlift_server_loop_10194(x_4_10550, x_5_10553, insights_3, op_3, _c_x10116_2_1040, _ctx);
  return kk_unit_box(_x_x2112);
}


// lift anonymous function
struct kk_src_dream__cycle_server_loop_fun2116__t {
  struct kk_function_s _base;
  kk_string_t x_4_10550;
  kk_integer_t x_5_10553;
  kk_integer_t x_6_10556;
};
static kk_box_t kk_src_dream__cycle_server_loop_fun2116(kk_function_t _fself, kk_box_t _b_x1029, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_server_loop_fun2116(kk_string_t x_4_10550, kk_integer_t x_5_10553, kk_integer_t x_6_10556, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_server_loop_fun2116__t* _self = kk_function_alloc_as(struct kk_src_dream__cycle_server_loop_fun2116__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_dream__cycle_server_loop_fun2116, kk_context());
  _self->x_4_10550 = x_4_10550;
  _self->x_5_10553 = x_5_10553;
  _self->x_6_10556 = x_6_10556;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_dream__cycle_server_loop_fun2116(kk_function_t _fself, kk_box_t _b_x1029, kk_context_t* _ctx) {
  struct kk_src_dream__cycle_server_loop_fun2116__t* _self = kk_function_as(struct kk_src_dream__cycle_server_loop_fun2116__t*, _fself, _ctx);
  kk_string_t x_4_10550 = _self->x_4_10550; /* string */
  kk_integer_t x_5_10553 = _self->x_5_10553; /* int */
  kk_integer_t x_6_10556 = _self->x_6_10556; /* int */
  kk_drop_match(_self, {kk_string_dup(x_4_10550, _ctx);kk_integer_dup(x_5_10553, _ctx);kk_integer_dup(x_6_10556, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10117_1_1041 = kk_integer_unbox(_b_x1029, _ctx); /*int*/;
  kk_unit_t _x_x2117 = kk_Unit;
  kk_src_dream__cycle__mlift_server_loop_10193(x_4_10550, x_5_10553, x_6_10556, _c_x10117_1_1041, _ctx);
  return kk_unit_box(_x_x2117);
}


// lift anonymous function
struct kk_src_dream__cycle_server_loop_fun2119__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_dream__cycle_server_loop_fun2119(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_dream__cycle_new_server_loop_fun2119(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_dream__cycle_server_loop_fun2119, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_dream__cycle_server_loop_fun2119(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x2120 = kk_Unit;
  kk_src_dream__cycle_flush_stdout(_ctx);
  return kk_unit_box(_x_x2120);
}

kk_unit_t kk_src_dream__cycle_server_loop(kk_integer_t cycles_1, kk_integer_t memories_2, kk_integer_t insights_3, kk_context_t* _ctx) { /* (cycles : int, memories : int, insights : int) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_3_10547 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_3_10547, _ctx);
    kk_box_t _x_x2065 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_server_loop_fun2066(cycles_1, insights_3, memories_2, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x2065); return kk_Unit;
  }
  {
    bool _match_x1043;
    kk_string_t _x_x2068 = kk_string_dup(x_3_10547, _ctx); /*string*/
    kk_string_t _x_x2069 = kk_string_empty(); /*string*/
    _match_x1043 = kk_string_is_neq(_x_x2068,_x_x2069,kk_context()); /*bool*/
    if (_match_x1043) {
      kk_string_t op_3;
      kk_box_t _x_x2071 = kk_std_core_hnd__open_none1(kk_src_dream__cycle_new_server_loop_fun2072(_ctx), kk_string_box(x_3_10547), _ctx); /*10001*/
      op_3 = kk_string_unbox(_x_x2071); /*string*/
      kk_string_t x_4_10550;
      if (kk_string_cmp_cstr_borrow(op_3, "status", _ctx) == 0) {
        kk_string_t _x_x2076;
        kk_define_string_literal(, _s_x2077, 11, "{\"cycles\": ", _ctx)
        _x_x2076 = kk_string_dup(_s_x2077, _ctx); /*string*/
        kk_string_t _x_x2078;
        kk_string_t _x_x2079;
        kk_integer_t _x_x2080 = kk_integer_dup(cycles_1, _ctx); /*int*/
        _x_x2079 = kk_std_core_int_show(_x_x2080, _ctx); /*string*/
        kk_string_t _x_x2081;
        kk_string_t _x_x2082;
        kk_define_string_literal(, _s_x2083, 14, ", \"memories\": ", _ctx)
        _x_x2082 = kk_string_dup(_s_x2083, _ctx); /*string*/
        kk_string_t _x_x2084;
        kk_string_t _x_x2085;
        kk_integer_t _x_x2086 = kk_integer_dup(memories_2, _ctx); /*int*/
        _x_x2085 = kk_std_core_int_show(_x_x2086, _ctx); /*string*/
        kk_string_t _x_x2087;
        kk_string_t _x_x2088;
        kk_define_string_literal(, _s_x2089, 14, ", \"insights\": ", _ctx)
        _x_x2088 = kk_string_dup(_s_x2089, _ctx); /*string*/
        kk_string_t _x_x2090;
        kk_string_t _x_x2091;
        kk_integer_t _x_x2092 = kk_integer_dup(insights_3, _ctx); /*int*/
        _x_x2091 = kk_std_core_int_show(_x_x2092, _ctx); /*string*/
        kk_string_t _x_x2093;
        kk_define_string_literal(, _s_x2094, 1, "}", _ctx)
        _x_x2093 = kk_string_dup(_s_x2094, _ctx); /*string*/
        _x_x2090 = kk_std_core_types__lp__plus__plus__rp_(_x_x2091, _x_x2093, _ctx); /*string*/
        _x_x2087 = kk_std_core_types__lp__plus__plus__rp_(_x_x2088, _x_x2090, _ctx); /*string*/
        _x_x2084 = kk_std_core_types__lp__plus__plus__rp_(_x_x2085, _x_x2087, _ctx); /*string*/
        _x_x2081 = kk_std_core_types__lp__plus__plus__rp_(_x_x2082, _x_x2084, _ctx); /*string*/
        _x_x2078 = kk_std_core_types__lp__plus__plus__rp_(_x_x2079, _x_x2081, _ctx); /*string*/
        x_4_10550 = kk_std_core_types__lp__plus__plus__rp_(_x_x2076, _x_x2078, _ctx); /*string*/
        goto _match_x2075;
      }
      if (kk_string_cmp_cstr_borrow(op_3, "reset", _ctx) == 0) {
        kk_define_string_literal(, _s_x2095, 38, "{\"operation\": \"reset\", \"result\": \"ok\"}", _ctx)
        x_4_10550 = kk_string_dup(_s_x2095, _ctx); /*string*/
        goto _match_x2075;
      }
      if (kk_string_cmp_cstr_borrow(op_3, "run", _ctx) == 0) {
        kk_define_string_literal(, _s_x2096, 56, "{\"operation\": \"run\", \"phases\": 8, \"status\": \"simulated\"}", _ctx)
        x_4_10550 = kk_string_dup(_s_x2096, _ctx); /*string*/
        goto _match_x2075;
      }
      {
        kk_define_string_literal(, _s_x2097, 20, "{\"error\": \"unknown\"}", _ctx)
        x_4_10550 = kk_string_dup(_s_x2097, _ctx); /*string*/
      }
      _match_x2075: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_4_10550, _ctx);
        kk_box_t _x_x2098 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_server_loop_fun2099(cycles_1, insights_3, memories_2, op_3, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x2098); return kk_Unit;
      }
      {
        kk_integer_t x_5_10553;
        bool _match_x1050;
        kk_string_t _x_x2101 = kk_string_dup(op_3, _ctx); /*string*/
        kk_string_t _x_x2102;
        kk_define_string_literal(, _s_x2103, 3, "run", _ctx)
        _x_x2102 = kk_string_dup(_s_x2103, _ctx); /*string*/
        _match_x1050 = kk_string_is_eq(_x_x2101,_x_x2102,kk_context()); /*bool*/
        if (_match_x1050) {
          x_5_10553 = kk_integer_add_small_const(cycles_1, 1, _ctx); /*int*/
        }
        else {
          x_5_10553 = cycles_1; /*int*/
        }
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_5_10553, _ctx);
          kk_box_t _x_x2104 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_server_loop_fun2105(insights_3, memories_2, op_3, x_4_10550, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x2104); return kk_Unit;
        }
        {
          kk_integer_t x_6_10556;
          bool _match_x1049;
          kk_string_t _x_x2107 = kk_string_dup(op_3, _ctx); /*string*/
          kk_string_t _x_x2108;
          kk_define_string_literal(, _s_x2109, 3, "run", _ctx)
          _x_x2108 = kk_string_dup(_s_x2109, _ctx); /*string*/
          _match_x1049 = kk_string_is_eq(_x_x2107,_x_x2108,kk_context()); /*bool*/
          if (_match_x1049) {
            x_6_10556 = kk_integer_add_small_const(memories_2, 40, _ctx); /*int*/
          }
          else {
            x_6_10556 = memories_2; /*int*/
          }
          if (kk_yielding(kk_context())) {
            kk_integer_drop(x_6_10556, _ctx);
            kk_box_t _x_x2110 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_server_loop_fun2111(insights_3, op_3, x_4_10550, x_5_10553, _ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x2110); return kk_Unit;
          }
          {
            kk_integer_t x_7_10559;
            bool _match_x1048;
            kk_string_t _x_x2113;
            kk_define_string_literal(, _s_x2114, 3, "run", _ctx)
            _x_x2113 = kk_string_dup(_s_x2114, _ctx); /*string*/
            _match_x1048 = kk_string_is_eq(op_3,_x_x2113,kk_context()); /*bool*/
            if (_match_x1048) {
              x_7_10559 = kk_integer_add_small_const(insights_3, 3, _ctx); /*int*/
            }
            else {
              x_7_10559 = insights_3; /*int*/
            }
            if (kk_yielding(kk_context())) {
              kk_integer_drop(x_7_10559, _ctx);
              kk_box_t _x_x2115 = kk_std_core_hnd_yield_extend(kk_src_dream__cycle_new_server_loop_fun2116(x_4_10550, x_5_10553, x_6_10556, _ctx), _ctx); /*10001*/
              kk_unit_unbox(_x_x2115); return kk_Unit;
            }
            {
              kk_unit_t ___1 = kk_Unit;
              kk_std_core_console_printsln(x_4_10550, _ctx);
              kk_unit_t ___0_0 = kk_Unit;
              kk_box_t _x_x2118 = kk_std_core_hnd__open_none0(kk_src_dream__cycle_new_server_loop_fun2119(_ctx), _ctx); /*10000*/
              kk_unit_unbox(_x_x2118);
              { // tailcall
                cycles_1 = x_5_10553;
                memories_2 = x_6_10556;
                insights_3 = x_7_10559;
                goto kk__tailcall;
              }
            }
          }
        }
      }
    }
    {
      kk_string_drop(x_3_10547, _ctx);
      kk_integer_drop(memories_2, _ctx);
      kk_integer_drop(insights_3, _ctx);
      kk_integer_drop(cycles_1, _ctx);
      kk_Unit; return kk_Unit;
    }
  }
}

// initialization
void kk_src_dream__cycle__init(kk_context_t* _ctx){
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
  {
    kk_string_t _x_x1189;
    kk_define_string_literal(, _s_x1190, 22, "memory-ops@dream_cycle", _ctx)
    _x_x1189 = kk_string_dup(_s_x1190, _ctx); /*string*/
    kk_src_dream__cycle_memory_ops_fs__tag = kk_std_core_hnd__new_Htag(_x_x1189, _ctx); /*hnd/htag<src/dream_cycle/memory-ops>*/
  }
  {
    kk_string_t _x_x1213;
    kk_define_string_literal(, _s_x1214, 29, "constellation-ops@dream_cycle", _ctx)
    _x_x1213 = kk_string_dup(_s_x1214, _ctx); /*string*/
    kk_src_dream__cycle_constellation_ops_fs__tag = kk_std_core_hnd__new_Htag(_x_x1213, _ctx); /*hnd/htag<src/dream_cycle/constellation-ops>*/
  }
  {
    kk_string_t _x_x1232;
    kk_define_string_literal(, _s_x1233, 23, "insight-ops@dream_cycle", _ctx)
    _x_x1232 = kk_string_dup(_s_x1233, _ctx); /*string*/
    kk_src_dream__cycle_insight_ops_fs__tag = kk_std_core_hnd__new_Htag(_x_x1232, _ctx); /*hnd/htag<src/dream_cycle/insight-ops>*/
  }
  {
    kk_string_t _x_x1250;
    kk_define_string_literal(, _s_x1251, 26, "governance-ops@dream_cycle", _ctx)
    _x_x1250 = kk_string_dup(_s_x1251, _ctx); /*string*/
    kk_src_dream__cycle_governance_ops_fs__tag = kk_std_core_hnd__new_Htag(_x_x1250, _ctx); /*hnd/htag<src/dream_cycle/governance-ops>*/
  }
  {
    kk_string_t _x_x1269;
    kk_define_string_literal(, _s_x1270, 25, "narrative-ops@dream_cycle", _ctx)
    _x_x1269 = kk_string_dup(_s_x1270, _ctx); /*string*/
    kk_src_dream__cycle_narrative_ops_fs__tag = kk_std_core_hnd__new_Htag(_x_x1269, _ctx); /*hnd/htag<src/dream_cycle/narrative-ops>*/
  }
  {
    kk_string_t _x_x1288;
    kk_define_string_literal(, _s_x1289, 22, "kaizen-ops@dream_cycle", _ctx)
    _x_x1288 = kk_string_dup(_s_x1289, _ctx); /*string*/
    kk_src_dream__cycle_kaizen_ops_fs__tag = kk_std_core_hnd__new_Htag(_x_x1288, _ctx); /*hnd/htag<src/dream_cycle/kaizen-ops>*/
  }
  {
    kk_string_t _x_x1307;
    kk_define_string_literal(, _s_x1308, 22, "oracle-ops@dream_cycle", _ctx)
    _x_x1307 = kk_string_dup(_s_x1308, _ctx); /*string*/
    kk_src_dream__cycle_oracle_ops_fs__tag = kk_std_core_hnd__new_Htag(_x_x1307, _ctx); /*hnd/htag<src/dream_cycle/oracle-ops>*/
  }
  {
    kk_string_t _x_x1321;
    kk_define_string_literal(, _s_x1322, 21, "decay-ops@dream_cycle", _ctx)
    _x_x1321 = kk_string_dup(_s_x1322, _ctx); /*string*/
    kk_src_dream__cycle_decay_ops_fs__tag = kk_std_core_hnd__new_Htag(_x_x1321, _ctx); /*hnd/htag<src/dream_cycle/decay-ops>*/
  }
}

// termination
void kk_src_dream__cycle__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__htag_drop(kk_src_dream__cycle_decay_ops_fs__tag, _ctx);
  kk_std_core_hnd__htag_drop(kk_src_dream__cycle_oracle_ops_fs__tag, _ctx);
  kk_std_core_hnd__htag_drop(kk_src_dream__cycle_kaizen_ops_fs__tag, _ctx);
  kk_std_core_hnd__htag_drop(kk_src_dream__cycle_narrative_ops_fs__tag, _ctx);
  kk_std_core_hnd__htag_drop(kk_src_dream__cycle_governance_ops_fs__tag, _ctx);
  kk_std_core_hnd__htag_drop(kk_src_dream__cycle_insight_ops_fs__tag, _ctx);
  kk_std_core_hnd__htag_drop(kk_src_dream__cycle_constellation_ops_fs__tag, _ctx);
  kk_std_core_hnd__htag_drop(kk_src_dream__cycle_memory_ops_fs__tag, _ctx);
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
