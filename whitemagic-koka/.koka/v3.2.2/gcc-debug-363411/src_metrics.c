// Koka generated module: src/metrics, koka version: 3.2.2, platform: 64-bit
#include "src_metrics.h"

kk_src_metrics__counter kk_src_metrics_counter_fs__copy(kk_src_metrics__counter _this, kk_std_core_types__optional name, kk_std_core_types__optional value, kk_std_core_types__optional help, kk_context_t* _ctx) { /* (counter, name : ? string, value : ? int64, help : ? string) -> counter */ 
  kk_string_t _x_x155;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x0 = name._cons._Optional.value;
    kk_string_t _uniq_name_66 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_name_66, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x155 = _uniq_name_66; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_src_metrics_Counter* _con_x156 = kk_src_metrics__as_Counter(_this, _ctx);
      kk_string_t _x = _con_x156->name;
      kk_string_dup(_x, _ctx);
      _x_x155 = _x; /*string*/
    }
  }
  int64_t _x_x157;
  if (kk_std_core_types__is_Optional(value, _ctx)) {
    kk_box_t _box_x1 = value._cons._Optional.value;
    int64_t _uniq_value_74 = kk_int64_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(value, _ctx);
    _x_x157 = _uniq_value_74; /*int64*/
  }
  else {
    kk_std_core_types__optional_drop(value, _ctx);
    {
      struct kk_src_metrics_Counter* _con_x158 = kk_src_metrics__as_Counter(_this, _ctx);
      int64_t _x_0 = _con_x158->value;
      _x_x157 = _x_0; /*int64*/
    }
  }
  kk_string_t _x_x159;
  if (kk_std_core_types__is_Optional(help, _ctx)) {
    kk_box_t _box_x2 = help._cons._Optional.value;
    kk_string_t _uniq_help_82 = kk_string_unbox(_box_x2);
    kk_string_dup(_uniq_help_82, _ctx);
    kk_std_core_types__optional_drop(help, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x159 = _uniq_help_82; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(help, _ctx);
    {
      struct kk_src_metrics_Counter* _con_x160 = kk_src_metrics__as_Counter(_this, _ctx);
      kk_string_t _pat_0_2 = _con_x160->name;
      kk_string_t _x_1 = _con_x160->help;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_string_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x159 = _x_1; /*string*/
    }
  }
  return kk_src_metrics__new_Counter(kk_reuse_null, 0, _x_x155, _x_x157, _x_x159, _ctx);
}

kk_src_metrics__gauge kk_src_metrics_gauge_fs__copy(kk_src_metrics__gauge _this, kk_std_core_types__optional name, kk_std_core_types__optional value, kk_std_core_types__optional help, kk_context_t* _ctx) { /* (gauge, name : ? string, value : ? float64, help : ? string) -> gauge */ 
  kk_string_t _x_x164;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x3 = name._cons._Optional.value;
    kk_string_t _uniq_name_124 = kk_string_unbox(_box_x3);
    kk_string_dup(_uniq_name_124, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x164 = _uniq_name_124; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_src_metrics_Gauge* _con_x165 = kk_src_metrics__as_Gauge(_this, _ctx);
      kk_string_t _x = _con_x165->name;
      kk_string_dup(_x, _ctx);
      _x_x164 = _x; /*string*/
    }
  }
  double _x_x166;
  if (kk_std_core_types__is_Optional(value, _ctx)) {
    kk_box_t _box_x4 = value._cons._Optional.value;
    double _uniq_value_132 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(value, _ctx);
    _x_x166 = _uniq_value_132; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(value, _ctx);
    {
      struct kk_src_metrics_Gauge* _con_x167 = kk_src_metrics__as_Gauge(_this, _ctx);
      double _x_0 = _con_x167->value;
      _x_x166 = _x_0; /*float64*/
    }
  }
  kk_string_t _x_x168;
  if (kk_std_core_types__is_Optional(help, _ctx)) {
    kk_box_t _box_x5 = help._cons._Optional.value;
    kk_string_t _uniq_help_140 = kk_string_unbox(_box_x5);
    kk_string_dup(_uniq_help_140, _ctx);
    kk_std_core_types__optional_drop(help, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x168 = _uniq_help_140; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(help, _ctx);
    {
      struct kk_src_metrics_Gauge* _con_x169 = kk_src_metrics__as_Gauge(_this, _ctx);
      kk_string_t _pat_0_2 = _con_x169->name;
      kk_string_t _x_1 = _con_x169->help;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_string_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x168 = _x_1; /*string*/
    }
  }
  return kk_src_metrics__new_Gauge(kk_reuse_null, 0, _x_x164, _x_x166, _x_x168, _ctx);
}

kk_src_metrics__histogram kk_src_metrics_histogram_fs__copy(kk_src_metrics__histogram _this, kk_std_core_types__optional name, kk_std_core_types__optional buckets, kk_std_core_types__optional sum, kk_std_core_types__optional count, kk_std_core_types__optional help, kk_context_t* _ctx) { /* (histogram, name : ? string, buckets : ? (list<(float64, int64)>), sum : ? float64, count : ? int64, help : ? string) -> histogram */ 
  kk_string_t _x_x175;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x6 = name._cons._Optional.value;
    kk_string_t _uniq_name_198 = kk_string_unbox(_box_x6);
    kk_string_dup(_uniq_name_198, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x175 = _uniq_name_198; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_src_metrics_Histogram* _con_x176 = kk_src_metrics__as_Histogram(_this, _ctx);
      kk_string_t _x = _con_x176->name;
      kk_string_dup(_x, _ctx);
      _x_x175 = _x; /*string*/
    }
  }
  kk_std_core_types__list _x_x177;
  if (kk_std_core_types__is_Optional(buckets, _ctx)) {
    kk_box_t _box_x7 = buckets._cons._Optional.value;
    kk_std_core_types__list _uniq_buckets_206 = kk_std_core_types__list_unbox(_box_x7, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_buckets_206, _ctx);
    kk_std_core_types__optional_drop(buckets, _ctx);
    _x_x177 = _uniq_buckets_206; /*list<(float64, int64)>*/
  }
  else {
    kk_std_core_types__optional_drop(buckets, _ctx);
    {
      struct kk_src_metrics_Histogram* _con_x178 = kk_src_metrics__as_Histogram(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x178->buckets;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x177 = _x_0; /*list<(float64, int64)>*/
    }
  }
  double _x_x179;
  if (kk_std_core_types__is_Optional(sum, _ctx)) {
    kk_box_t _box_x8 = sum._cons._Optional.value;
    double _uniq_sum_214 = kk_double_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(sum, _ctx);
    _x_x179 = _uniq_sum_214; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(sum, _ctx);
    {
      struct kk_src_metrics_Histogram* _con_x180 = kk_src_metrics__as_Histogram(_this, _ctx);
      double _x_1 = _con_x180->sum;
      _x_x179 = _x_1; /*float64*/
    }
  }
  int64_t _x_x181;
  if (kk_std_core_types__is_Optional(count, _ctx)) {
    kk_box_t _box_x9 = count._cons._Optional.value;
    int64_t _uniq_count_222 = kk_int64_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(count, _ctx);
    _x_x181 = _uniq_count_222; /*int64*/
  }
  else {
    kk_std_core_types__optional_drop(count, _ctx);
    {
      struct kk_src_metrics_Histogram* _con_x182 = kk_src_metrics__as_Histogram(_this, _ctx);
      int64_t _x_2 = _con_x182->count;
      _x_x181 = _x_2; /*int64*/
    }
  }
  kk_string_t _x_x183;
  if (kk_std_core_types__is_Optional(help, _ctx)) {
    kk_box_t _box_x10 = help._cons._Optional.value;
    kk_string_t _uniq_help_230 = kk_string_unbox(_box_x10);
    kk_string_dup(_uniq_help_230, _ctx);
    kk_std_core_types__optional_drop(help, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x183 = _uniq_help_230; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(help, _ctx);
    {
      struct kk_src_metrics_Histogram* _con_x184 = kk_src_metrics__as_Histogram(_this, _ctx);
      kk_string_t _pat_0_4 = _con_x184->name;
      kk_std_core_types__list _pat_1_5 = _con_x184->buckets;
      kk_string_t _x_3 = _con_x184->help;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_std_core_types__list_drop(_pat_1_5, _ctx);
        kk_string_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_string_dup(_x_3, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x183 = _x_3; /*string*/
    }
  }
  return kk_src_metrics__new_Histogram(kk_reuse_null, 0, _x_x175, _x_x177, _x_x179, _x_x181, _x_x183, _ctx);
}

kk_src_metrics__metrics_snapshot kk_src_metrics_metrics_snapshot_fs__copy(kk_src_metrics__metrics_snapshot _this, kk_std_core_types__optional counters, kk_std_core_types__optional gauges, kk_std_core_types__optional histograms, kk_std_core_types__optional timestamp, kk_context_t* _ctx) { /* (metrics-snapshot, counters : ? (list<counter>), gauges : ? (list<gauge>), histograms : ? (list<histogram>), timestamp : ? float64) -> metrics-snapshot */ 
  kk_std_core_types__list _x_x189;
  if (kk_std_core_types__is_Optional(counters, _ctx)) {
    kk_box_t _box_x11 = counters._cons._Optional.value;
    kk_std_core_types__list _uniq_counters_282 = kk_std_core_types__list_unbox(_box_x11, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_counters_282, _ctx);
    kk_std_core_types__optional_drop(counters, _ctx);
    _x_x189 = _uniq_counters_282; /*list<src/metrics/counter>*/
  }
  else {
    kk_std_core_types__optional_drop(counters, _ctx);
    {
      struct kk_src_metrics_Metrics_snapshot* _con_x190 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
      kk_std_core_types__list _x = _con_x190->counters;
      kk_std_core_types__list_dup(_x, _ctx);
      _x_x189 = _x; /*list<src/metrics/counter>*/
    }
  }
  kk_std_core_types__list _x_x191;
  if (kk_std_core_types__is_Optional(gauges, _ctx)) {
    kk_box_t _box_x12 = gauges._cons._Optional.value;
    kk_std_core_types__list _uniq_gauges_290 = kk_std_core_types__list_unbox(_box_x12, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_gauges_290, _ctx);
    kk_std_core_types__optional_drop(gauges, _ctx);
    _x_x191 = _uniq_gauges_290; /*list<src/metrics/gauge>*/
  }
  else {
    kk_std_core_types__optional_drop(gauges, _ctx);
    {
      struct kk_src_metrics_Metrics_snapshot* _con_x192 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x192->gauges;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x191 = _x_0; /*list<src/metrics/gauge>*/
    }
  }
  kk_std_core_types__list _x_x193;
  if (kk_std_core_types__is_Optional(histograms, _ctx)) {
    kk_box_t _box_x13 = histograms._cons._Optional.value;
    kk_std_core_types__list _uniq_histograms_298 = kk_std_core_types__list_unbox(_box_x13, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_histograms_298, _ctx);
    kk_std_core_types__optional_drop(histograms, _ctx);
    _x_x193 = _uniq_histograms_298; /*list<src/metrics/histogram>*/
  }
  else {
    kk_std_core_types__optional_drop(histograms, _ctx);
    {
      struct kk_src_metrics_Metrics_snapshot* _con_x194 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
      kk_std_core_types__list _x_1 = _con_x194->histograms;
      kk_std_core_types__list_dup(_x_1, _ctx);
      _x_x193 = _x_1; /*list<src/metrics/histogram>*/
    }
  }
  double _x_x195;
  if (kk_std_core_types__is_Optional(timestamp, _ctx)) {
    kk_box_t _box_x14 = timestamp._cons._Optional.value;
    double _uniq_timestamp_306 = kk_double_unbox(_box_x14, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(timestamp, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x195 = _uniq_timestamp_306; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(timestamp, _ctx);
    {
      struct kk_src_metrics_Metrics_snapshot* _con_x196 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
      kk_std_core_types__list _pat_0_3 = _con_x196->counters;
      kk_std_core_types__list _pat_1_4 = _con_x196->gauges;
      kk_std_core_types__list _pat_2_3 = _con_x196->histograms;
      double _x_2 = _con_x196->timestamp;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_std_core_types__list_drop(_pat_2_3, _ctx);
        kk_std_core_types__list_drop(_pat_1_4, _ctx);
        kk_std_core_types__list_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x195 = _x_2; /*float64*/
    }
  }
  return kk_src_metrics__new_Metrics_snapshot(kk_reuse_null, 0, _x_x189, _x_x191, _x_x193, _x_x195, _ctx);
}

kk_src_metrics__counter kk_src_metrics_increment(kk_src_metrics__counter c, kk_context_t* _ctx) { /* (c : counter) -> counter */ 
  kk_string_t _x_x197;
  {
    struct kk_src_metrics_Counter* _con_x198 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x = _con_x198->name;
    kk_string_dup(_x, _ctx);
    _x_x197 = _x; /*string*/
  }
  int64_t _x_x199;
  int64_t _x_x200;
  {
    struct kk_src_metrics_Counter* _con_x201 = kk_src_metrics__as_Counter(c, _ctx);
    int64_t _x_0 = _con_x201->value;
    _x_x200 = _x_0; /*int64*/
  }
  int64_t _x_x202 = (KK_I64(1)); /*int64*/
  _x_x199 = (int64_t)((uint64_t)_x_x200 + (uint64_t)_x_x202); /*int64*/
  kk_string_t _x_x203;
  {
    struct kk_src_metrics_Counter* _con_x204 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _pat_0_1 = _con_x204->name;
    kk_string_t _x_1 = _con_x204->help;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_string_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x203 = _x_1; /*string*/
  }
  return kk_src_metrics__new_Counter(kk_reuse_null, 0, _x_x197, _x_x199, _x_x203, _ctx);
}

kk_src_metrics__counter kk_src_metrics_add(kk_src_metrics__counter c, kk_integer_t n, kk_context_t* _ctx) { /* (c : counter, n : int) -> counter */ 
  kk_string_t _x_x205;
  {
    struct kk_src_metrics_Counter* _con_x206 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x = _con_x206->name;
    kk_string_dup(_x, _ctx);
    _x_x205 = _x; /*string*/
  }
  int64_t _x_x207;
  int64_t _x_x208;
  {
    struct kk_src_metrics_Counter* _con_x209 = kk_src_metrics__as_Counter(c, _ctx);
    int64_t _x_0 = _con_x209->value;
    _x_x208 = _x_0; /*int64*/
  }
  int64_t _x_x210 = kk_std_num_int64_int64(n, _ctx); /*int64*/
  _x_x207 = (int64_t)((uint64_t)_x_x208 + (uint64_t)_x_x210); /*int64*/
  kk_string_t _x_x211;
  {
    struct kk_src_metrics_Counter* _con_x212 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _pat_0_1 = _con_x212->name;
    kk_string_t _x_1 = _con_x212->help;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_string_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x211 = _x_1; /*string*/
  }
  return kk_src_metrics__new_Counter(kk_reuse_null, 0, _x_x205, _x_x207, _x_x211, _ctx);
}

kk_src_metrics__gauge kk_src_metrics_set(kk_src_metrics__gauge g, double v, kk_context_t* _ctx) { /* (g : gauge, v : float64) -> gauge */ 
  kk_string_t _x_x213;
  {
    struct kk_src_metrics_Gauge* _con_x214 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _x = _con_x214->name;
    kk_string_dup(_x, _ctx);
    _x_x213 = _x; /*string*/
  }
  kk_string_t _x_x215;
  {
    struct kk_src_metrics_Gauge* _con_x216 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _pat_0_0 = _con_x216->name;
    kk_string_t _x_0 = _con_x216->help;
    if kk_likely(kk_datatype_ptr_is_unique(g, _ctx)) {
      kk_string_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(g, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(g, _ctx);
    }
    _x_x215 = _x_0; /*string*/
  }
  return kk_src_metrics__new_Gauge(kk_reuse_null, 0, _x_x213, v, _x_x215, _ctx);
}


// lift anonymous function
struct kk_src_metrics_observe_fun217__t {
  struct kk_function_s _base;
  double v;
};
static kk_box_t kk_src_metrics_observe_fun217(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_src_metrics_new_observe_fun217(double v, kk_context_t* _ctx) {
  struct kk_src_metrics_observe_fun217__t* _self = kk_function_alloc_as(struct kk_src_metrics_observe_fun217__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_metrics_observe_fun217, kk_context());
  _self->v = v;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_metrics_observe_fun217(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  struct kk_src_metrics_observe_fun217__t* _self = kk_function_as(struct kk_src_metrics_observe_fun217__t*, _fself, _ctx);
  double v = _self->v; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(v, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x218;
  kk_std_core_types__tuple2 _match_x129;
  kk_box_t _x_x219 = kk_box_dup(_b_x21, _ctx); /*10001*/
  _match_x129 = kk_std_core_types__tuple2_unbox(_x_x219, KK_OWNED, _ctx); /*(float64, int64)*/
  {
    kk_box_t _box_x15 = _match_x129.fst;
    kk_box_t _box_x16 = _match_x129.snd;
    double upper = kk_double_unbox(_box_x15, KK_BORROWED, _ctx);
    int64_t count = kk_int64_unbox(_box_x16, KK_BORROWED, _ctx);
    kk_std_core_types__tuple2_drop(_match_x129, _ctx);
    bool _match_x130 = (v <= upper); /*bool*/;
    if (_match_x130) {
      kk_box_drop(_b_x21, _ctx);
      int64_t _b_x18_25;
      int64_t _x_x220 = (KK_I64(1)); /*int64*/
      _b_x18_25 = (int64_t)((uint64_t)count + (uint64_t)_x_x220); /*int64*/
      _x_x218 = kk_std_core_types__new_Tuple2(kk_double_box(upper, _ctx), kk_int64_box(_b_x18_25, _ctx), _ctx); /*(10037, 10038)*/
    }
    else {
      _x_x218 = kk_std_core_types__tuple2_unbox(_b_x21, KK_OWNED, _ctx); /*(10037, 10038)*/
    }
  }
  return kk_std_core_types__tuple2_box(_x_x218, _ctx);
}

kk_src_metrics__histogram kk_src_metrics_observe(kk_src_metrics__histogram h, double v, kk_context_t* _ctx) { /* (h : histogram, v : float64) -> histogram */ 
  kk_std_core_types__list new_buckets;
  kk_function_t _brw_x131 = kk_src_metrics_new_observe_fun217(v, _ctx); /*(10001) -> 10003 10002*/;
  kk_std_core_types__list _brw_x132;
  kk_std_core_types__list _x_x221;
  {
    struct kk_src_metrics_Histogram* _con_x222 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_std_core_types__list _x = _con_x222->buckets;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x221 = _x; /*list<(float64, int64)>*/
  }
  _brw_x132 = kk_std_core_list_map(_x_x221, _brw_x131, _ctx); /*list<10002>*/
  kk_function_drop(_brw_x131, _ctx);
  new_buckets = _brw_x132; /*list<(float64, int64)>*/
  kk_string_t _x_x223;
  {
    struct kk_src_metrics_Histogram* _con_x224 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_0 = _con_x224->name;
    kk_string_dup(_x_0, _ctx);
    _x_x223 = _x_0; /*string*/
  }
  double _x_x225;
  double _x_x226;
  {
    struct kk_src_metrics_Histogram* _con_x227 = kk_src_metrics__as_Histogram(h, _ctx);
    double _x_1 = _con_x227->sum;
    _x_x226 = _x_1; /*float64*/
  }
  _x_x225 = (_x_x226 + v); /*float64*/
  int64_t _x_x228;
  int64_t _x_x229;
  {
    struct kk_src_metrics_Histogram* _con_x230 = kk_src_metrics__as_Histogram(h, _ctx);
    int64_t _x_2 = _con_x230->count;
    _x_x229 = _x_2; /*int64*/
  }
  int64_t _x_x231 = (KK_I64(1)); /*int64*/
  _x_x228 = (int64_t)((uint64_t)_x_x229 + (uint64_t)_x_x231); /*int64*/
  kk_string_t _x_x232;
  {
    struct kk_src_metrics_Histogram* _con_x233 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _pat_0_4 = _con_x233->name;
    kk_std_core_types__list _pat_1_4 = _con_x233->buckets;
    kk_string_t _x_3 = _con_x233->help;
    if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
      kk_std_core_types__list_drop(_pat_1_4, _ctx);
      kk_string_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(h, _ctx);
    }
    else {
      kk_string_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(h, _ctx);
    }
    _x_x232 = _x_3; /*string*/
  }
  return kk_src_metrics__new_Histogram(kk_reuse_null, 0, _x_x223, new_buckets, _x_x225, _x_x228, _x_x232, _ctx);
}

kk_string_t kk_src_metrics_export_counter(kk_src_metrics__counter c, kk_context_t* _ctx) { /* (c : counter) -> string */ 
  kk_string_t _x_x234;
  kk_define_string_literal(, _s_x235, 7, "# HELP ", _ctx)
  _x_x234 = kk_string_dup(_s_x235, _ctx); /*string*/
  kk_string_t _x_x236;
  kk_string_t _x_x237;
  {
    struct kk_src_metrics_Counter* _con_x238 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x = _con_x238->name;
    kk_string_dup(_x, _ctx);
    _x_x237 = _x; /*string*/
  }
  kk_string_t _x_x239;
  kk_string_t _x_x240;
  kk_define_string_literal(, _s_x241, 1, " ", _ctx)
  _x_x240 = kk_string_dup(_s_x241, _ctx); /*string*/
  kk_string_t _x_x242;
  kk_string_t _x_x243;
  {
    struct kk_src_metrics_Counter* _con_x244 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x_0 = _con_x244->help;
    kk_string_dup(_x_0, _ctx);
    _x_x243 = _x_0; /*string*/
  }
  kk_string_t _x_x245;
  kk_string_t _x_x246;
  kk_define_string_literal(, _s_x247, 1, "\n", _ctx)
  _x_x246 = kk_string_dup(_s_x247, _ctx); /*string*/
  kk_string_t _x_x248;
  kk_string_t _x_x249;
  kk_define_string_literal(, _s_x250, 7, "# TYPE ", _ctx)
  _x_x249 = kk_string_dup(_s_x250, _ctx); /*string*/
  kk_string_t _x_x251;
  kk_string_t _x_x252;
  {
    struct kk_src_metrics_Counter* _con_x253 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x_1 = _con_x253->name;
    kk_string_dup(_x_1, _ctx);
    _x_x252 = _x_1; /*string*/
  }
  kk_string_t _x_x254;
  kk_string_t _x_x255;
  kk_define_string_literal(, _s_x256, 9, " counter\n", _ctx)
  _x_x255 = kk_string_dup(_s_x256, _ctx); /*string*/
  kk_string_t _x_x257;
  kk_string_t _x_x258;
  {
    struct kk_src_metrics_Counter* _con_x259 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x_2 = _con_x259->name;
    kk_string_dup(_x_2, _ctx);
    _x_x258 = _x_2; /*string*/
  }
  kk_string_t _x_x260;
  kk_string_t _x_x261;
  kk_define_string_literal(, _s_x262, 1, " ", _ctx)
  _x_x261 = kk_string_dup(_s_x262, _ctx); /*string*/
  kk_string_t _x_x263;
  kk_integer_t _x_x264;
  int64_t _x_x265;
  {
    struct kk_src_metrics_Counter* _con_x266 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _pat_0_3 = _con_x266->name;
    int64_t _x_3 = _con_x266->value;
    kk_string_t _pat_1_3 = _con_x266->help;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_string_drop(_pat_1_3, _ctx);
      kk_string_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x265 = _x_3; /*int64*/
  }
  _x_x264 = kk_integer_from_int64(_x_x265,kk_context()); /*int*/
  _x_x263 = kk_std_core_int_show(_x_x264, _ctx); /*string*/
  _x_x260 = kk_std_core_types__lp__plus__plus__rp_(_x_x261, _x_x263, _ctx); /*string*/
  _x_x257 = kk_std_core_types__lp__plus__plus__rp_(_x_x258, _x_x260, _ctx); /*string*/
  _x_x254 = kk_std_core_types__lp__plus__plus__rp_(_x_x255, _x_x257, _ctx); /*string*/
  _x_x251 = kk_std_core_types__lp__plus__plus__rp_(_x_x252, _x_x254, _ctx); /*string*/
  _x_x248 = kk_std_core_types__lp__plus__plus__rp_(_x_x249, _x_x251, _ctx); /*string*/
  _x_x245 = kk_std_core_types__lp__plus__plus__rp_(_x_x246, _x_x248, _ctx); /*string*/
  _x_x242 = kk_std_core_types__lp__plus__plus__rp_(_x_x243, _x_x245, _ctx); /*string*/
  _x_x239 = kk_std_core_types__lp__plus__plus__rp_(_x_x240, _x_x242, _ctx); /*string*/
  _x_x236 = kk_std_core_types__lp__plus__plus__rp_(_x_x237, _x_x239, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x234, _x_x236, _ctx);
}

kk_string_t kk_src_metrics_export_gauge(kk_src_metrics__gauge g, kk_context_t* _ctx) { /* (g : gauge) -> string */ 
  kk_string_t _x_x267;
  kk_define_string_literal(, _s_x268, 7, "# HELP ", _ctx)
  _x_x267 = kk_string_dup(_s_x268, _ctx); /*string*/
  kk_string_t _x_x269;
  kk_string_t _x_x270;
  {
    struct kk_src_metrics_Gauge* _con_x271 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _x = _con_x271->name;
    kk_string_dup(_x, _ctx);
    _x_x270 = _x; /*string*/
  }
  kk_string_t _x_x272;
  kk_string_t _x_x273;
  kk_define_string_literal(, _s_x274, 1, " ", _ctx)
  _x_x273 = kk_string_dup(_s_x274, _ctx); /*string*/
  kk_string_t _x_x275;
  kk_string_t _x_x276;
  {
    struct kk_src_metrics_Gauge* _con_x277 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _x_0 = _con_x277->help;
    kk_string_dup(_x_0, _ctx);
    _x_x276 = _x_0; /*string*/
  }
  kk_string_t _x_x278;
  kk_string_t _x_x279;
  kk_define_string_literal(, _s_x280, 1, "\n", _ctx)
  _x_x279 = kk_string_dup(_s_x280, _ctx); /*string*/
  kk_string_t _x_x281;
  kk_string_t _x_x282;
  kk_define_string_literal(, _s_x283, 7, "# TYPE ", _ctx)
  _x_x282 = kk_string_dup(_s_x283, _ctx); /*string*/
  kk_string_t _x_x284;
  kk_string_t _x_x285;
  {
    struct kk_src_metrics_Gauge* _con_x286 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _x_1 = _con_x286->name;
    kk_string_dup(_x_1, _ctx);
    _x_x285 = _x_1; /*string*/
  }
  kk_string_t _x_x287;
  kk_string_t _x_x288;
  kk_define_string_literal(, _s_x289, 7, " gauge\n", _ctx)
  _x_x288 = kk_string_dup(_s_x289, _ctx); /*string*/
  kk_string_t _x_x290;
  kk_string_t _x_x291;
  {
    struct kk_src_metrics_Gauge* _con_x292 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _x_2 = _con_x292->name;
    kk_string_dup(_x_2, _ctx);
    _x_x291 = _x_2; /*string*/
  }
  kk_string_t _x_x293;
  kk_string_t _x_x294;
  kk_define_string_literal(, _s_x295, 1, " ", _ctx)
  _x_x294 = kk_string_dup(_s_x295, _ctx); /*string*/
  kk_string_t _x_x296;
  double _x_x297;
  {
    struct kk_src_metrics_Gauge* _con_x298 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _pat_0_3 = _con_x298->name;
    double _x_3 = _con_x298->value;
    kk_string_t _pat_1_3 = _con_x298->help;
    if kk_likely(kk_datatype_ptr_is_unique(g, _ctx)) {
      kk_string_drop(_pat_1_3, _ctx);
      kk_string_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(g, _ctx);
    }
    else {
      kk_datatype_ptr_decref(g, _ctx);
    }
    _x_x297 = _x_3; /*float64*/
  }
  _x_x296 = kk_std_num_float64_show(_x_x297, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  _x_x293 = kk_std_core_types__lp__plus__plus__rp_(_x_x294, _x_x296, _ctx); /*string*/
  _x_x290 = kk_std_core_types__lp__plus__plus__rp_(_x_x291, _x_x293, _ctx); /*string*/
  _x_x287 = kk_std_core_types__lp__plus__plus__rp_(_x_x288, _x_x290, _ctx); /*string*/
  _x_x284 = kk_std_core_types__lp__plus__plus__rp_(_x_x285, _x_x287, _ctx); /*string*/
  _x_x281 = kk_std_core_types__lp__plus__plus__rp_(_x_x282, _x_x284, _ctx); /*string*/
  _x_x278 = kk_std_core_types__lp__plus__plus__rp_(_x_x279, _x_x281, _ctx); /*string*/
  _x_x275 = kk_std_core_types__lp__plus__plus__rp_(_x_x276, _x_x278, _ctx); /*string*/
  _x_x272 = kk_std_core_types__lp__plus__plus__rp_(_x_x273, _x_x275, _ctx); /*string*/
  _x_x269 = kk_std_core_types__lp__plus__plus__rp_(_x_x270, _x_x272, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x267, _x_x269, _ctx);
}

kk_string_t kk_src_metrics_list_fs_join(kk_std_core_types__list xs, kk_string_t sep, kk_context_t* _ctx) { /* (xs : list<string>, sep : string) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_string_drop(sep, _ctx);
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x300 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x27 = _con_x300->head;
    kk_std_core_types__list _pat_1 = _con_x300->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t s = kk_string_unbox(_box_x27);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(s, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_string_drop(sep, _ctx);
      return s;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x301 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x28 = _con_x301->head;
    kk_std_core_types__list rest = _con_x301->tail;
    kk_string_t s_0 = kk_string_unbox(_box_x28);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(rest, _ctx);
      kk_string_dup(s_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_string_t _x_x302;
    kk_string_t _x_x303 = kk_string_dup(sep, _ctx); /*string*/
    kk_string_t _x_x304 = kk_src_metrics_list_fs_join(rest, sep, _ctx); /*string*/
    _x_x302 = kk_std_core_types__lp__plus__plus__rp_(_x_x303, _x_x304, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(s_0, _x_x302, _ctx);
  }
}


// lift anonymous function
struct kk_src_metrics_export_histogram_fun305__t {
  struct kk_function_s _base;
  kk_src_metrics__histogram h;
};
static kk_box_t kk_src_metrics_export_histogram_fun305(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx);
static kk_function_t kk_src_metrics_new_export_histogram_fun305(kk_src_metrics__histogram h, kk_context_t* _ctx) {
  struct kk_src_metrics_export_histogram_fun305__t* _self = kk_function_alloc_as(struct kk_src_metrics_export_histogram_fun305__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_metrics_export_histogram_fun305, kk_context());
  _self->h = h;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_metrics_export_histogram_fun305(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx) {
  struct kk_src_metrics_export_histogram_fun305__t* _self = kk_function_as(struct kk_src_metrics_export_histogram_fun305__t*, _fself, _ctx);
  kk_src_metrics__histogram h = _self->h; /* src/metrics/histogram */
  kk_drop_match(_self, {kk_src_metrics__histogram_dup(h, _ctx);}, {}, _ctx)
  kk_string_t _x_x306;
  kk_std_core_types__tuple2 _match_x126 = kk_std_core_types__tuple2_unbox(_b_x33, KK_OWNED, _ctx); /*(float64, int64)*/;
  {
    kk_box_t _box_x29 = _match_x126.fst;
    kk_box_t _box_x30 = _match_x126.snd;
    double upper = kk_double_unbox(_box_x29, KK_BORROWED, _ctx);
    int64_t count = kk_int64_unbox(_box_x30, KK_BORROWED, _ctx);
    kk_std_core_types__tuple2_drop(_match_x126, _ctx);
    kk_string_t _x_x307;
    {
      struct kk_src_metrics_Histogram* _con_x308 = kk_src_metrics__as_Histogram(h, _ctx);
      kk_string_t _x_0 = _con_x308->name;
      kk_std_core_types__list _pat_0_0 = _con_x308->buckets;
      kk_string_t _pat_3_0 = _con_x308->help;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_string_drop(_pat_3_0, _ctx);
        kk_std_core_types__list_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_string_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      _x_x307 = _x_0; /*string*/
    }
    kk_string_t _x_x309;
    kk_string_t _x_x310;
    kk_define_string_literal(, _s_x311, 12, "_bucket{le=\"", _ctx)
    _x_x310 = kk_string_dup(_s_x311, _ctx); /*string*/
    kk_string_t _x_x312;
    kk_string_t _x_x313 = kk_std_num_float64_show(upper, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
    kk_string_t _x_x314;
    kk_string_t _x_x315;
    kk_define_string_literal(, _s_x316, 3, "\"} ", _ctx)
    _x_x315 = kk_string_dup(_s_x316, _ctx); /*string*/
    kk_string_t _x_x317;
    kk_integer_t _x_x318 = kk_integer_from_int64(count,kk_context()); /*int*/
    _x_x317 = kk_std_core_int_show(_x_x318, _ctx); /*string*/
    _x_x314 = kk_std_core_types__lp__plus__plus__rp_(_x_x315, _x_x317, _ctx); /*string*/
    _x_x312 = kk_std_core_types__lp__plus__plus__rp_(_x_x313, _x_x314, _ctx); /*string*/
    _x_x309 = kk_std_core_types__lp__plus__plus__rp_(_x_x310, _x_x312, _ctx); /*string*/
    _x_x306 = kk_std_core_types__lp__plus__plus__rp_(_x_x307, _x_x309, _ctx); /*string*/
  }
  return kk_string_box(_x_x306);
}

kk_string_t kk_src_metrics_export_histogram(kk_src_metrics__histogram h, kk_context_t* _ctx) { /* (h : histogram) -> string */ 
  kk_std_core_types__list bucket_lines;
  kk_function_t _brw_x127;
  kk_src_metrics__histogram_dup(h, _ctx);
  _brw_x127 = kk_src_metrics_new_export_histogram_fun305(h, _ctx); /*(10001) -> 10003 10002*/
  kk_std_core_types__list _brw_x128;
  kk_std_core_types__list _x_x319;
  {
    struct kk_src_metrics_Histogram* _con_x320 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_std_core_types__list _x = _con_x320->buckets;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x319 = _x; /*list<(float64, int64)>*/
  }
  _brw_x128 = kk_std_core_list_map(_x_x319, _brw_x127, _ctx); /*list<10002>*/
  kk_function_drop(_brw_x127, _ctx);
  bucket_lines = _brw_x128; /*list<string>*/
  kk_string_t _b_x39_41;
  kk_string_t _x_x321;
  kk_define_string_literal(, _s_x322, 7, "# HELP ", _ctx)
  _x_x321 = kk_string_dup(_s_x322, _ctx); /*string*/
  kk_string_t _x_x323;
  kk_string_t _x_x324;
  {
    struct kk_src_metrics_Histogram* _con_x325 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_1 = _con_x325->name;
    kk_string_dup(_x_1, _ctx);
    _x_x324 = _x_1; /*string*/
  }
  kk_string_t _x_x326;
  kk_string_t _x_x327;
  kk_define_string_literal(, _s_x328, 1, " ", _ctx)
  _x_x327 = kk_string_dup(_s_x328, _ctx); /*string*/
  kk_string_t _x_x329;
  {
    struct kk_src_metrics_Histogram* _con_x330 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_2 = _con_x330->help;
    kk_string_dup(_x_2, _ctx);
    _x_x329 = _x_2; /*string*/
  }
  _x_x326 = kk_std_core_types__lp__plus__plus__rp_(_x_x327, _x_x329, _ctx); /*string*/
  _x_x323 = kk_std_core_types__lp__plus__plus__rp_(_x_x324, _x_x326, _ctx); /*string*/
  _b_x39_41 = kk_std_core_types__lp__plus__plus__rp_(_x_x321, _x_x323, _ctx); /*string*/
  kk_string_t _b_x37_43;
  kk_string_t _x_x331;
  kk_define_string_literal(, _s_x332, 7, "# TYPE ", _ctx)
  _x_x331 = kk_string_dup(_s_x332, _ctx); /*string*/
  kk_string_t _x_x333;
  kk_string_t _x_x334;
  {
    struct kk_src_metrics_Histogram* _con_x335 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_3 = _con_x335->name;
    kk_string_dup(_x_3, _ctx);
    _x_x334 = _x_3; /*string*/
  }
  kk_string_t _x_x336;
  kk_define_string_literal(, _s_x337, 10, " histogram", _ctx)
  _x_x336 = kk_string_dup(_s_x337, _ctx); /*string*/
  _x_x333 = kk_std_core_types__lp__plus__plus__rp_(_x_x334, _x_x336, _ctx); /*string*/
  _b_x37_43 = kk_std_core_types__lp__plus__plus__rp_(_x_x331, _x_x333, _ctx); /*string*/
  kk_string_t _b_x47_49;
  kk_string_t _x_x338;
  {
    struct kk_src_metrics_Histogram* _con_x339 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_4 = _con_x339->name;
    kk_string_dup(_x_4, _ctx);
    _x_x338 = _x_4; /*string*/
  }
  kk_string_t _x_x340;
  kk_string_t _x_x341;
  kk_define_string_literal(, _s_x342, 5, "_sum ", _ctx)
  _x_x341 = kk_string_dup(_s_x342, _ctx); /*string*/
  kk_string_t _x_x343;
  double _x_x344;
  {
    struct kk_src_metrics_Histogram* _con_x345 = kk_src_metrics__as_Histogram(h, _ctx);
    double _x_5 = _con_x345->sum;
    _x_x344 = _x_5; /*float64*/
  }
  _x_x343 = kk_std_num_float64_show(_x_x344, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  _x_x340 = kk_std_core_types__lp__plus__plus__rp_(_x_x341, _x_x343, _ctx); /*string*/
  _b_x47_49 = kk_std_core_types__lp__plus__plus__rp_(_x_x338, _x_x340, _ctx); /*string*/
  kk_string_t _b_x45_51;
  kk_string_t _x_x346;
  {
    struct kk_src_metrics_Histogram* _con_x347 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_6 = _con_x347->name;
    kk_string_dup(_x_6, _ctx);
    _x_x346 = _x_6; /*string*/
  }
  kk_string_t _x_x348;
  kk_string_t _x_x349;
  kk_define_string_literal(, _s_x350, 7, "_count ", _ctx)
  _x_x349 = kk_string_dup(_s_x350, _ctx); /*string*/
  kk_string_t _x_x351;
  kk_integer_t _x_x352;
  int64_t _x_x353;
  {
    struct kk_src_metrics_Histogram* _con_x354 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _pat_0_7 = _con_x354->name;
    kk_std_core_types__list _pat_1_7 = _con_x354->buckets;
    int64_t _x_7 = _con_x354->count;
    kk_string_t _pat_3_7 = _con_x354->help;
    if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
      kk_string_drop(_pat_3_7, _ctx);
      kk_std_core_types__list_drop(_pat_1_7, _ctx);
      kk_string_drop(_pat_0_7, _ctx);
      kk_datatype_ptr_free(h, _ctx);
    }
    else {
      kk_datatype_ptr_decref(h, _ctx);
    }
    _x_x353 = _x_7; /*int64*/
  }
  _x_x352 = kk_integer_from_int64(_x_x353,kk_context()); /*int*/
  _x_x351 = kk_std_core_int_show(_x_x352, _ctx); /*string*/
  _x_x348 = kk_std_core_types__lp__plus__plus__rp_(_x_x349, _x_x351, _ctx); /*string*/
  _b_x45_51 = kk_std_core_types__lp__plus__plus__rp_(_x_x346, _x_x348, _ctx); /*string*/
  kk_std_core_types__list ys_10043;
  kk_std_core_types__list _x_x355;
  kk_std_core_types__list _x_x356 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x45_51), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x355 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x47_49), _x_x356, _ctx); /*list<10021>*/
  ys_10043 = kk_std_core_list_append(bucket_lines, _x_x355, _ctx); /*list<string>*/
  kk_std_core_types__list lines;
  kk_std_core_types__list _x_x357;
  kk_std_core_types__list _x_x358 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x37_43), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x357 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x39_41), _x_x358, _ctx); /*list<10021>*/
  lines = kk_std_core_list_append(_x_x357, ys_10043, _ctx); /*list<string>*/
  kk_string_t _x_x359;
  kk_define_string_literal(, _s_x360, 1, "\n", _ctx)
  _x_x359 = kk_string_dup(_s_x360, _ctx); /*string*/
  return kk_src_metrics_list_fs_join(lines, _x_x359, _ctx);
}


// lift anonymous function
struct kk_src_metrics_export_all_fun361__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_metrics_export_all_fun361(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx);
static kk_function_t kk_src_metrics_new_export_all_fun361(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_metrics_export_all_fun361, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_metrics_export_all_fun361(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x362;
  kk_src_metrics__counter _x_x363 = kk_src_metrics__counter_unbox(_b_x55, KK_OWNED, _ctx); /*src/metrics/counter*/
  _x_x362 = kk_src_metrics_export_counter(_x_x363, _ctx); /*string*/
  return kk_string_box(_x_x362);
}


// lift anonymous function
struct kk_src_metrics_export_all_fun366__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_metrics_export_all_fun366(kk_function_t _fself, kk_box_t _b_x60, kk_context_t* _ctx);
static kk_function_t kk_src_metrics_new_export_all_fun366(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_metrics_export_all_fun366, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_metrics_export_all_fun366(kk_function_t _fself, kk_box_t _b_x60, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x367;
  kk_src_metrics__gauge _x_x368 = kk_src_metrics__gauge_unbox(_b_x60, KK_OWNED, _ctx); /*src/metrics/gauge*/
  _x_x367 = kk_src_metrics_export_gauge(_x_x368, _ctx); /*string*/
  return kk_string_box(_x_x367);
}


// lift anonymous function
struct kk_src_metrics_export_all_fun371__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_metrics_export_all_fun371(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx);
static kk_function_t kk_src_metrics_new_export_all_fun371(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_metrics_export_all_fun371, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_metrics_export_all_fun371(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x372;
  kk_src_metrics__histogram _x_x373 = kk_src_metrics__histogram_unbox(_b_x65, KK_OWNED, _ctx); /*src/metrics/histogram*/
  _x_x372 = kk_src_metrics_export_histogram(_x_x373, _ctx); /*string*/
  return kk_string_box(_x_x372);
}

kk_string_t kk_src_metrics_export_all(kk_src_metrics__metrics_snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : metrics-snapshot) -> string */ 
  kk_std_core_types__list counter_lines;
  kk_function_t _brw_x124 = kk_src_metrics_new_export_all_fun361(_ctx); /*(10001) -> 10003 10002*/;
  kk_std_core_types__list _brw_x125;
  kk_std_core_types__list _x_x364;
  {
    struct kk_src_metrics_Metrics_snapshot* _con_x365 = kk_src_metrics__as_Metrics_snapshot(snapshot, _ctx);
    kk_std_core_types__list _x = _con_x365->counters;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x364 = _x; /*list<src/metrics/counter>*/
  }
  _brw_x125 = kk_std_core_list_map(_x_x364, _brw_x124, _ctx); /*list<10002>*/
  kk_function_drop(_brw_x124, _ctx);
  counter_lines = _brw_x125; /*list<string>*/
  kk_std_core_types__list gauge_lines;
  kk_function_t _brw_x122 = kk_src_metrics_new_export_all_fun366(_ctx); /*(10001) -> 10003 10002*/;
  kk_std_core_types__list _brw_x123;
  kk_std_core_types__list _x_x369;
  {
    struct kk_src_metrics_Metrics_snapshot* _con_x370 = kk_src_metrics__as_Metrics_snapshot(snapshot, _ctx);
    kk_std_core_types__list _x_0 = _con_x370->gauges;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x369 = _x_0; /*list<src/metrics/gauge>*/
  }
  _brw_x123 = kk_std_core_list_map(_x_x369, _brw_x122, _ctx); /*list<10002>*/
  kk_function_drop(_brw_x122, _ctx);
  gauge_lines = _brw_x123; /*list<string>*/
  kk_std_core_types__list hist_lines;
  kk_function_t _brw_x120 = kk_src_metrics_new_export_all_fun371(_ctx); /*(10001) -> 10003 10002*/;
  kk_std_core_types__list _brw_x121;
  kk_std_core_types__list _x_x374;
  {
    struct kk_src_metrics_Metrics_snapshot* _con_x375 = kk_src_metrics__as_Metrics_snapshot(snapshot, _ctx);
    kk_std_core_types__list _pat_0_1 = _con_x375->counters;
    kk_std_core_types__list _pat_1_1 = _con_x375->gauges;
    kk_std_core_types__list _x_1 = _con_x375->histograms;
    if kk_likely(kk_datatype_ptr_is_unique(snapshot, _ctx)) {
      kk_std_core_types__list_drop(_pat_1_1, _ctx);
      kk_std_core_types__list_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(snapshot, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(snapshot, _ctx);
    }
    _x_x374 = _x_1; /*list<src/metrics/histogram>*/
  }
  _brw_x121 = kk_std_core_list_map(_x_x374, _brw_x120, _ctx); /*list<10002>*/
  kk_function_drop(_brw_x120, _ctx);
  hist_lines = _brw_x121; /*list<string>*/
  kk_std_core_types__list ys_10058 = kk_std_core_list_append(gauge_lines, hist_lines, _ctx); /*list<string>*/;
  kk_std_core_types__list _x_x376 = kk_std_core_list_append(counter_lines, ys_10058, _ctx); /*list<10001>*/
  kk_string_t _x_x377;
  kk_define_string_literal(, _s_x378, 2, "\n\n", _ctx)
  _x_x377 = kk_string_dup(_s_x378, _ctx); /*string*/
  return kk_src_metrics_list_fs_join(_x_x376, _x_x377, _ctx);
}

kk_src_metrics__metrics_snapshot kk_src_metrics_standard_ipc_metrics(kk_string_t binary_name, kk_context_t* _ctx) { /* (binary-name : string) -> metrics-snapshot */ 
  kk_string_drop(binary_name, _ctx);
  kk_src_metrics__counter _b_x70_94;
  kk_string_t _x_x379;
  kk_define_string_literal(, _s_x380, 23, "koka_ipc_commands_total", _ctx)
  _x_x379 = kk_string_dup(_s_x380, _ctx); /*string*/
  int64_t _x_x381 = (KK_I64(0)); /*int64*/
  kk_string_t _x_x382;
  kk_define_string_literal(, _s_x383, 28, "Total IPC commands processed", _ctx)
  _x_x382 = kk_string_dup(_s_x383, _ctx); /*string*/
  _b_x70_94 = kk_src_metrics__new_Counter(kk_reuse_null, 0, _x_x379, _x_x381, _x_x382, _ctx); /*src/metrics/counter*/
  kk_src_metrics__counter _b_x68_96;
  kk_string_t _x_x384;
  kk_define_string_literal(, _s_x385, 21, "koka_ipc_errors_total", _ctx)
  _x_x384 = kk_string_dup(_s_x385, _ctx); /*string*/
  int64_t _x_x386 = (KK_I64(0)); /*int64*/
  kk_string_t _x_x387;
  kk_define_string_literal(, _s_x388, 16, "Total IPC errors", _ctx)
  _x_x387 = kk_string_dup(_s_x388, _ctx); /*string*/
  _b_x68_96 = kk_src_metrics__new_Counter(kk_reuse_null, 0, _x_x384, _x_x386, _x_x387, _ctx); /*src/metrics/counter*/
  int64_t _b_x77_107 = (KK_I64(0)); /*int64*/;
  int64_t _b_x79_111 = (KK_I64(0)); /*int64*/;
  int64_t _b_x81_115 = (KK_I64(0)); /*int64*/;
  int64_t _b_x83_119 = (KK_I64(0)); /*int64*/;
  kk_src_metrics__histogram _b_x92_102;
  kk_string_t _x_x389;
  kk_define_string_literal(, _s_x390, 20, "koka_ipc_duration_ms", _ctx)
  _x_x389 = kk_string_dup(_s_x390, _ctx); /*string*/
  kk_std_core_types__list _x_x391;
  kk_box_t _x_x392;
  kk_std_core_types__tuple2 _x_x393 = kk_std_core_types__new_Tuple2(kk_double_box(0x1.999999999999ap-4, _ctx), kk_int64_box(_b_x77_107, _ctx), _ctx); /*(10037, 10038)*/
  _x_x392 = kk_std_core_types__tuple2_box(_x_x393, _ctx); /*10021*/
  kk_std_core_types__list _x_x394;
  kk_box_t _x_x395;
  kk_std_core_types__tuple2 _x_x396 = kk_std_core_types__new_Tuple2(kk_double_box(0x1p0, _ctx), kk_int64_box(_b_x79_111, _ctx), _ctx); /*(10037, 10038)*/
  _x_x395 = kk_std_core_types__tuple2_box(_x_x396, _ctx); /*10021*/
  kk_std_core_types__list _x_x397;
  kk_box_t _x_x398;
  kk_std_core_types__tuple2 _x_x399 = kk_std_core_types__new_Tuple2(kk_double_box(0x1.4p3, _ctx), kk_int64_box(_b_x81_115, _ctx), _ctx); /*(10037, 10038)*/
  _x_x398 = kk_std_core_types__tuple2_box(_x_x399, _ctx); /*10021*/
  kk_std_core_types__list _x_x400;
  kk_box_t _x_x401;
  kk_std_core_types__tuple2 _x_x402 = kk_std_core_types__new_Tuple2(kk_double_box(0x1.9p6, _ctx), kk_int64_box(_b_x83_119, _ctx), _ctx); /*(10037, 10038)*/
  _x_x401 = kk_std_core_types__tuple2_box(_x_x402, _ctx); /*10021*/
  _x_x400 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x401, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x397 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x398, _x_x400, _ctx); /*list<10021>*/
  _x_x394 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x395, _x_x397, _ctx); /*list<10021>*/
  _x_x391 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x392, _x_x394, _ctx); /*list<10021>*/
  int64_t _x_x403 = (KK_I64(0)); /*int64*/
  kk_string_t _x_x404;
  kk_define_string_literal(, _s_x405, 36, "IPC command duration in milliseconds", _ctx)
  _x_x404 = kk_string_dup(_s_x405, _ctx); /*string*/
  _b_x92_102 = kk_src_metrics__new_Histogram(kk_reuse_null, 0, _x_x389, _x_x391, 0x0p+0, _x_x403, _x_x404, _ctx); /*src/metrics/histogram*/
  kk_std_core_types__list _x_x406;
  kk_std_core_types__list _x_x407 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_src_metrics__counter_box(_b_x68_96, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x406 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_src_metrics__counter_box(_b_x70_94, _ctx), _x_x407, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x408;
  kk_box_t _x_x409;
  kk_src_metrics__gauge _x_x410;
  kk_string_t _x_x411;
  kk_define_string_literal(, _s_x412, 19, "koka_ipc_latency_ms", _ctx)
  _x_x411 = kk_string_dup(_s_x412, _ctx); /*string*/
  kk_string_t _x_x413;
  kk_define_string_literal(, _s_x414, 35, "Current IPC latency in milliseconds", _ctx)
  _x_x413 = kk_string_dup(_s_x414, _ctx); /*string*/
  _x_x410 = kk_src_metrics__new_Gauge(kk_reuse_null, 0, _x_x411, 0x0p+0, _x_x413, _ctx); /*src/metrics/gauge*/
  _x_x409 = kk_src_metrics__gauge_box(_x_x410, _ctx); /*10021*/
  kk_std_core_types__list _x_x415;
  kk_box_t _x_x416;
  kk_src_metrics__gauge _x_x417;
  kk_string_t _x_x418;
  kk_define_string_literal(, _s_x419, 27, "koka_process_uptime_seconds", _ctx)
  _x_x418 = kk_string_dup(_s_x419, _ctx); /*string*/
  kk_string_t _x_x420;
  kk_define_string_literal(, _s_x421, 25, "Process uptime in seconds", _ctx)
  _x_x420 = kk_string_dup(_s_x421, _ctx); /*string*/
  _x_x417 = kk_src_metrics__new_Gauge(kk_reuse_null, 0, _x_x418, 0x0p+0, _x_x420, _ctx); /*src/metrics/gauge*/
  _x_x416 = kk_src_metrics__gauge_box(_x_x417, _ctx); /*10021*/
  _x_x415 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x416, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x408 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x409, _x_x415, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x422 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_src_metrics__histogram_box(_b_x92_102, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  return kk_src_metrics__new_Metrics_snapshot(kk_reuse_null, 0, _x_x406, _x_x408, _x_x422, 0x0p+0, _ctx);
}

// initialization
void kk_src_metrics__init(kk_context_t* _ctx){
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
  kk_std_time_duration__init(_ctx);
  kk_std_time_instant__init(_ctx);
  kk_std_time_utc__init(_ctx);
  kk_std_time_chrono__init(_ctx);
  kk_std_time_timer__init(_ctx);
  kk_std_time_date__init(_ctx);
  kk_std_time_calendar__init(_ctx);
  kk_std_time_calendars__init(_ctx);
  kk_std_time_time__init(_ctx);
  kk_std_time_locale__init(_ctx);
  kk_std_time_format__init(_ctx);
  kk_std_time_parse__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_float64__init(_ctx);
  kk_std_num_int64__init(_ctx);
  kk_std_time__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_src_metrics__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_time__done(_ctx);
  kk_std_num_int64__done(_ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_core__done(_ctx);
  kk_std_time_parse__done(_ctx);
  kk_std_time_format__done(_ctx);
  kk_std_time_locale__done(_ctx);
  kk_std_time_time__done(_ctx);
  kk_std_time_calendars__done(_ctx);
  kk_std_time_calendar__done(_ctx);
  kk_std_time_date__done(_ctx);
  kk_std_time_timer__done(_ctx);
  kk_std_time_chrono__done(_ctx);
  kk_std_time_utc__done(_ctx);
  kk_std_time_instant__done(_ctx);
  kk_std_time_duration__done(_ctx);
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
