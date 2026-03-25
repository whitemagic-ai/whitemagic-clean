// Koka generated module: src/metrics, koka version: 3.2.2, platform: 64-bit
#include "src_metrics.h"

kk_src_metrics__counter kk_src_metrics_counter_fs__copy(kk_src_metrics__counter _this, kk_std_core_types__optional name, kk_std_core_types__optional value, kk_std_core_types__optional help, kk_context_t* _ctx) { /* (counter, name : ? string, value : ? int64, help : ? string) -> counter */ 
  kk_string_t _x_x262;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x0 = name._cons._Optional.value;
    kk_string_t _uniq_name_67 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_name_67, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x262 = _uniq_name_67; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_src_metrics_Counter* _con_x263 = kk_src_metrics__as_Counter(_this, _ctx);
      kk_string_t _x = _con_x263->name;
      kk_string_dup(_x, _ctx);
      _x_x262 = _x; /*string*/
    }
  }
  int64_t _x_x264;
  if (kk_std_core_types__is_Optional(value, _ctx)) {
    kk_box_t _box_x1 = value._cons._Optional.value;
    int64_t _uniq_value_75 = kk_int64_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(value, _ctx);
    _x_x264 = _uniq_value_75; /*int64*/
  }
  else {
    kk_std_core_types__optional_drop(value, _ctx);
    {
      struct kk_src_metrics_Counter* _con_x265 = kk_src_metrics__as_Counter(_this, _ctx);
      int64_t _x_0 = _con_x265->value;
      _x_x264 = _x_0; /*int64*/
    }
  }
  kk_string_t _x_x266;
  if (kk_std_core_types__is_Optional(help, _ctx)) {
    kk_box_t _box_x2 = help._cons._Optional.value;
    kk_string_t _uniq_help_83 = kk_string_unbox(_box_x2);
    kk_string_dup(_uniq_help_83, _ctx);
    kk_std_core_types__optional_drop(help, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x266 = _uniq_help_83; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(help, _ctx);
    {
      struct kk_src_metrics_Counter* _con_x267 = kk_src_metrics__as_Counter(_this, _ctx);
      kk_string_t _pat_0_2 = _con_x267->name;
      kk_string_t _x_1 = _con_x267->help;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_string_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x266 = _x_1; /*string*/
    }
  }
  return kk_src_metrics__new_Counter(kk_reuse_null, 0, _x_x262, _x_x264, _x_x266, _ctx);
}

kk_src_metrics__gauge kk_src_metrics_gauge_fs__copy(kk_src_metrics__gauge _this, kk_std_core_types__optional name, kk_std_core_types__optional value, kk_std_core_types__optional help, kk_context_t* _ctx) { /* (gauge, name : ? string, value : ? float64, help : ? string) -> gauge */ 
  kk_string_t _x_x271;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x3 = name._cons._Optional.value;
    kk_string_t _uniq_name_125 = kk_string_unbox(_box_x3);
    kk_string_dup(_uniq_name_125, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x271 = _uniq_name_125; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_src_metrics_Gauge* _con_x272 = kk_src_metrics__as_Gauge(_this, _ctx);
      kk_string_t _x = _con_x272->name;
      kk_string_dup(_x, _ctx);
      _x_x271 = _x; /*string*/
    }
  }
  double _x_x273;
  if (kk_std_core_types__is_Optional(value, _ctx)) {
    kk_box_t _box_x4 = value._cons._Optional.value;
    double _uniq_value_133 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(value, _ctx);
    _x_x273 = _uniq_value_133; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(value, _ctx);
    {
      struct kk_src_metrics_Gauge* _con_x274 = kk_src_metrics__as_Gauge(_this, _ctx);
      double _x_0 = _con_x274->value;
      _x_x273 = _x_0; /*float64*/
    }
  }
  kk_string_t _x_x275;
  if (kk_std_core_types__is_Optional(help, _ctx)) {
    kk_box_t _box_x5 = help._cons._Optional.value;
    kk_string_t _uniq_help_141 = kk_string_unbox(_box_x5);
    kk_string_dup(_uniq_help_141, _ctx);
    kk_std_core_types__optional_drop(help, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x275 = _uniq_help_141; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(help, _ctx);
    {
      struct kk_src_metrics_Gauge* _con_x276 = kk_src_metrics__as_Gauge(_this, _ctx);
      kk_string_t _pat_0_2 = _con_x276->name;
      kk_string_t _x_1 = _con_x276->help;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_string_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x275 = _x_1; /*string*/
    }
  }
  return kk_src_metrics__new_Gauge(kk_reuse_null, 0, _x_x271, _x_x273, _x_x275, _ctx);
}

kk_src_metrics__histogram kk_src_metrics_histogram_fs__copy(kk_src_metrics__histogram _this, kk_std_core_types__optional name, kk_std_core_types__optional buckets, kk_std_core_types__optional sum, kk_std_core_types__optional count, kk_std_core_types__optional help, kk_context_t* _ctx) { /* (histogram, name : ? string, buckets : ? (list<(float64, int64)>), sum : ? float64, count : ? int64, help : ? string) -> histogram */ 
  kk_string_t _x_x282;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x6 = name._cons._Optional.value;
    kk_string_t _uniq_name_199 = kk_string_unbox(_box_x6);
    kk_string_dup(_uniq_name_199, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x282 = _uniq_name_199; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_src_metrics_Histogram* _con_x283 = kk_src_metrics__as_Histogram(_this, _ctx);
      kk_string_t _x = _con_x283->name;
      kk_string_dup(_x, _ctx);
      _x_x282 = _x; /*string*/
    }
  }
  kk_std_core_types__list _x_x284;
  if (kk_std_core_types__is_Optional(buckets, _ctx)) {
    kk_box_t _box_x7 = buckets._cons._Optional.value;
    kk_std_core_types__list _uniq_buckets_207 = kk_std_core_types__list_unbox(_box_x7, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_buckets_207, _ctx);
    kk_std_core_types__optional_drop(buckets, _ctx);
    _x_x284 = _uniq_buckets_207; /*list<(float64, int64)>*/
  }
  else {
    kk_std_core_types__optional_drop(buckets, _ctx);
    {
      struct kk_src_metrics_Histogram* _con_x285 = kk_src_metrics__as_Histogram(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x285->buckets;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x284 = _x_0; /*list<(float64, int64)>*/
    }
  }
  double _x_x286;
  if (kk_std_core_types__is_Optional(sum, _ctx)) {
    kk_box_t _box_x8 = sum._cons._Optional.value;
    double _uniq_sum_215 = kk_double_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(sum, _ctx);
    _x_x286 = _uniq_sum_215; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(sum, _ctx);
    {
      struct kk_src_metrics_Histogram* _con_x287 = kk_src_metrics__as_Histogram(_this, _ctx);
      double _x_1 = _con_x287->sum;
      _x_x286 = _x_1; /*float64*/
    }
  }
  int64_t _x_x288;
  if (kk_std_core_types__is_Optional(count, _ctx)) {
    kk_box_t _box_x9 = count._cons._Optional.value;
    int64_t _uniq_count_223 = kk_int64_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(count, _ctx);
    _x_x288 = _uniq_count_223; /*int64*/
  }
  else {
    kk_std_core_types__optional_drop(count, _ctx);
    {
      struct kk_src_metrics_Histogram* _con_x289 = kk_src_metrics__as_Histogram(_this, _ctx);
      int64_t _x_2 = _con_x289->count;
      _x_x288 = _x_2; /*int64*/
    }
  }
  kk_string_t _x_x290;
  if (kk_std_core_types__is_Optional(help, _ctx)) {
    kk_box_t _box_x10 = help._cons._Optional.value;
    kk_string_t _uniq_help_231 = kk_string_unbox(_box_x10);
    kk_string_dup(_uniq_help_231, _ctx);
    kk_std_core_types__optional_drop(help, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x290 = _uniq_help_231; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(help, _ctx);
    {
      struct kk_src_metrics_Histogram* _con_x291 = kk_src_metrics__as_Histogram(_this, _ctx);
      kk_string_t _pat_0_4 = _con_x291->name;
      kk_std_core_types__list _pat_1_5 = _con_x291->buckets;
      kk_string_t _x_3 = _con_x291->help;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_std_core_types__list_drop(_pat_1_5, _ctx);
        kk_string_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_string_dup(_x_3, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x290 = _x_3; /*string*/
    }
  }
  return kk_src_metrics__new_Histogram(kk_reuse_null, 0, _x_x282, _x_x284, _x_x286, _x_x288, _x_x290, _ctx);
}

kk_src_metrics__metrics_snapshot kk_src_metrics_metrics_snapshot_fs__copy(kk_src_metrics__metrics_snapshot _this, kk_std_core_types__optional counters, kk_std_core_types__optional gauges, kk_std_core_types__optional histograms, kk_std_core_types__optional timestamp, kk_context_t* _ctx) { /* (metrics-snapshot, counters : ? (list<counter>), gauges : ? (list<gauge>), histograms : ? (list<histogram>), timestamp : ? float64) -> metrics-snapshot */ 
  kk_std_core_types__list _x_x296;
  if (kk_std_core_types__is_Optional(counters, _ctx)) {
    kk_box_t _box_x11 = counters._cons._Optional.value;
    kk_std_core_types__list _uniq_counters_283 = kk_std_core_types__list_unbox(_box_x11, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_counters_283, _ctx);
    kk_std_core_types__optional_drop(counters, _ctx);
    _x_x296 = _uniq_counters_283; /*list<src/metrics/counter>*/
  }
  else {
    kk_std_core_types__optional_drop(counters, _ctx);
    {
      struct kk_src_metrics_Metrics_snapshot* _con_x297 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
      kk_std_core_types__list _x = _con_x297->counters;
      kk_std_core_types__list_dup(_x, _ctx);
      _x_x296 = _x; /*list<src/metrics/counter>*/
    }
  }
  kk_std_core_types__list _x_x298;
  if (kk_std_core_types__is_Optional(gauges, _ctx)) {
    kk_box_t _box_x12 = gauges._cons._Optional.value;
    kk_std_core_types__list _uniq_gauges_291 = kk_std_core_types__list_unbox(_box_x12, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_gauges_291, _ctx);
    kk_std_core_types__optional_drop(gauges, _ctx);
    _x_x298 = _uniq_gauges_291; /*list<src/metrics/gauge>*/
  }
  else {
    kk_std_core_types__optional_drop(gauges, _ctx);
    {
      struct kk_src_metrics_Metrics_snapshot* _con_x299 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x299->gauges;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x298 = _x_0; /*list<src/metrics/gauge>*/
    }
  }
  kk_std_core_types__list _x_x300;
  if (kk_std_core_types__is_Optional(histograms, _ctx)) {
    kk_box_t _box_x13 = histograms._cons._Optional.value;
    kk_std_core_types__list _uniq_histograms_299 = kk_std_core_types__list_unbox(_box_x13, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_histograms_299, _ctx);
    kk_std_core_types__optional_drop(histograms, _ctx);
    _x_x300 = _uniq_histograms_299; /*list<src/metrics/histogram>*/
  }
  else {
    kk_std_core_types__optional_drop(histograms, _ctx);
    {
      struct kk_src_metrics_Metrics_snapshot* _con_x301 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
      kk_std_core_types__list _x_1 = _con_x301->histograms;
      kk_std_core_types__list_dup(_x_1, _ctx);
      _x_x300 = _x_1; /*list<src/metrics/histogram>*/
    }
  }
  double _x_x302;
  if (kk_std_core_types__is_Optional(timestamp, _ctx)) {
    kk_box_t _box_x14 = timestamp._cons._Optional.value;
    double _uniq_timestamp_307 = kk_double_unbox(_box_x14, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(timestamp, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x302 = _uniq_timestamp_307; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(timestamp, _ctx);
    {
      struct kk_src_metrics_Metrics_snapshot* _con_x303 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
      kk_std_core_types__list _pat_0_3 = _con_x303->counters;
      kk_std_core_types__list _pat_1_4 = _con_x303->gauges;
      kk_std_core_types__list _pat_2_3 = _con_x303->histograms;
      double _x_2 = _con_x303->timestamp;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_std_core_types__list_drop(_pat_2_3, _ctx);
        kk_std_core_types__list_drop(_pat_1_4, _ctx);
        kk_std_core_types__list_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x302 = _x_2; /*float64*/
    }
  }
  return kk_src_metrics__new_Metrics_snapshot(kk_reuse_null, 0, _x_x296, _x_x298, _x_x300, _x_x302, _ctx);
}

kk_src_metrics__counter kk_src_metrics_increment(kk_src_metrics__counter c, kk_context_t* _ctx) { /* (c : counter) -> counter */ 
  kk_string_t _x_x304;
  {
    struct kk_src_metrics_Counter* _con_x305 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x = _con_x305->name;
    kk_string_dup(_x, _ctx);
    _x_x304 = _x; /*string*/
  }
  int64_t _x_x306;
  int64_t _x_x307;
  {
    struct kk_src_metrics_Counter* _con_x308 = kk_src_metrics__as_Counter(c, _ctx);
    int64_t _x_0 = _con_x308->value;
    _x_x307 = _x_0; /*int64*/
  }
  int64_t _x_x309 = (KK_I64(1)); /*int64*/
  _x_x306 = (int64_t)((uint64_t)_x_x307 + (uint64_t)_x_x309); /*int64*/
  kk_string_t _x_x310;
  {
    struct kk_src_metrics_Counter* _con_x311 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _pat_0_1 = _con_x311->name;
    kk_string_t _x_1 = _con_x311->help;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_string_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x310 = _x_1; /*string*/
  }
  return kk_src_metrics__new_Counter(kk_reuse_null, 0, _x_x304, _x_x306, _x_x310, _ctx);
}

kk_src_metrics__counter kk_src_metrics_add(kk_src_metrics__counter c, kk_integer_t n, kk_context_t* _ctx) { /* (c : counter, n : int) -> counter */ 
  kk_string_t _x_x312;
  {
    struct kk_src_metrics_Counter* _con_x313 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x = _con_x313->name;
    kk_string_dup(_x, _ctx);
    _x_x312 = _x; /*string*/
  }
  int64_t _x_x314;
  int64_t _x_x315;
  {
    struct kk_src_metrics_Counter* _con_x316 = kk_src_metrics__as_Counter(c, _ctx);
    int64_t _x_0 = _con_x316->value;
    _x_x315 = _x_0; /*int64*/
  }
  int64_t _x_x317 = kk_std_num_int64_int64(n, _ctx); /*int64*/
  _x_x314 = (int64_t)((uint64_t)_x_x315 + (uint64_t)_x_x317); /*int64*/
  kk_string_t _x_x318;
  {
    struct kk_src_metrics_Counter* _con_x319 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _pat_0_1 = _con_x319->name;
    kk_string_t _x_1 = _con_x319->help;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_string_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x318 = _x_1; /*string*/
  }
  return kk_src_metrics__new_Counter(kk_reuse_null, 0, _x_x312, _x_x314, _x_x318, _ctx);
}

kk_src_metrics__gauge kk_src_metrics_set(kk_src_metrics__gauge g, double v, kk_context_t* _ctx) { /* (g : gauge, v : float64) -> gauge */ 
  kk_string_t _x_x320;
  {
    struct kk_src_metrics_Gauge* _con_x321 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _x = _con_x321->name;
    kk_string_dup(_x, _ctx);
    _x_x320 = _x; /*string*/
  }
  kk_string_t _x_x322;
  {
    struct kk_src_metrics_Gauge* _con_x323 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _pat_0_0 = _con_x323->name;
    kk_string_t _x_0 = _con_x323->help;
    if kk_likely(kk_datatype_ptr_is_unique(g, _ctx)) {
      kk_string_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(g, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(g, _ctx);
    }
    _x_x322 = _x_0; /*string*/
  }
  return kk_src_metrics__new_Gauge(kk_reuse_null, 0, _x_x320, v, _x_x322, _ctx);
}
 
// lifted local: @lift-observe@10228, observe, @spec-x10177
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10172, using:
// @uniq-f@10172 = fn(bucket: (float64, int64)){
//   match (bucket) {
//     ((@skip std/core/types/Tuple2((upper: float64) : float64, (count: int64) : int64) : (float64, int64) ) as @pat@4: (float64, int64))
//        -> (match ((std/num/float64/(<=)(v, upper))) {
//         ((std/core/types/True() : bool ) as @pat@0@0: bool)
//            -> std/core/types/Tuple2<float64,int64>(upper, (std/num/int64/(+)(count, (std/num/int64/int64(1)))));
//         ((@skip std/core/types/False() : bool ) as @pat@1@0: bool)
//            -> bucket;
//       });
//   };
// }

kk_std_core_types__list kk_src_metrics__trmc_lift_observe_10229(double v, kk_std_core_types__list _uniq_xs_10171, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (v : float64, list<(float64, int64)>, ctx<list<(float64, int64)>>) -> list<(float64, int64)> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10171, _ctx)) {
    struct kk_std_core_types_Cons* _con_x324 = kk_std_core_types__as_Cons(_uniq_xs_10171, _ctx);
    kk_box_t _box_x15 = _con_x324->head;
    kk_std_core_types__list _uniq_xx_10175 = _con_x324->tail;
    kk_std_core_types__tuple2 _uniq_x_10174 = kk_std_core_types__tuple2_unbox(_box_x15, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x245 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10171, _ctx)) {
      kk_std_core_types__tuple2_dup(_uniq_x_10174, _ctx);
      kk_box_drop(_box_x15, _ctx);
      _ru_x245 = (kk_datatype_ptr_reuse(_uniq_xs_10171, _ctx));
    }
    else {
      kk_std_core_types__tuple2_dup(_uniq_x_10174, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10175, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10171, _ctx);
    }
    kk_std_core_types__tuple2 _trmc_x10242;
    {
      kk_box_t _box_x16 = _uniq_x_10174.fst;
      kk_box_t _box_x17 = _uniq_x_10174.snd;
      double upper = kk_double_unbox(_box_x16, KK_BORROWED, _ctx);
      int64_t count = kk_int64_unbox(_box_x17, KK_BORROWED, _ctx);
      bool _match_x233 = (v <= upper); /*bool*/;
      if (_match_x233) {
        kk_std_core_types__tuple2_drop(_uniq_x_10174, _ctx);
        int64_t _b_x19_21;
        int64_t _x_x325 = (KK_I64(1)); /*int64*/
        _b_x19_21 = (int64_t)((uint64_t)count + (uint64_t)_x_x325); /*int64*/
        _trmc_x10242 = kk_std_core_types__new_Tuple2(kk_double_box(upper, _ctx), kk_int64_box(_b_x19_21, _ctx), _ctx); /*(float64, int64)*/
      }
      else {
        _trmc_x10242 = _uniq_x_10174; /*(float64, int64)*/
      }
    }
    kk_std_core_types__list _trmc_x10243 = kk_datatype_null(); /*list<(float64, int64)>*/;
    kk_std_core_types__list _trmc_x10244 = kk_std_core_types__new_Cons(_ru_x245, 0, kk_std_core_types__tuple2_box(_trmc_x10242, _ctx), _trmc_x10243, _ctx); /*list<(float64, int64)>*/;
    kk_field_addr_t _b_x31_36 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10244, _ctx)->tail, _ctx); /*@field-addr<list<(float64, int64)>>*/;
    kk_std_core_types__cctx _brw_x231;
    kk_std_core_types__cctx _x_x326 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<(float64, int64)>>*/
    _brw_x231 = kk_cctx_extend_linear(_x_x326,(kk_std_core_types__list_box(_trmc_x10244, _ctx)),_b_x31_36,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x232 = kk_src_metrics__trmc_lift_observe_10229(v, _uniq_xx_10175, _brw_x231, _ctx); /*list<(float64, int64)>*/;
    kk_std_core_types__cctx_drop(_brw_x231, _ctx);
    return _brw_x232;
  }
  {
    kk_box_t _x_x327;
    kk_std_core_types__cctx _x_x328 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<(float64, int64)>>*/
    _x_x327 = kk_cctx_apply_linear(_x_x328,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x327, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-observe@10228, observe, @spec-x10177
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10172, using:
// @uniq-f@10172 = fn(bucket: (float64, int64)){
//   match (bucket) {
//     ((@skip std/core/types/Tuple2((upper: float64) : float64, (count: int64) : int64) : (float64, int64) ) as @pat@4: (float64, int64))
//        -> (match ((std/num/float64/(<=)(v, upper))) {
//         ((std/core/types/True() : bool ) as @pat@0@0: bool)
//            -> std/core/types/Tuple2<float64,int64>(upper, (std/num/int64/(+)(count, (std/num/int64/int64(1)))));
//         ((@skip std/core/types/False() : bool ) as @pat@1@0: bool)
//            -> bucket;
//       });
//   };
// }

kk_std_core_types__list kk_src_metrics__lift_observe_10229(double v_0, kk_std_core_types__list _uniq_xs_10171_0, kk_context_t* _ctx) { /* (v : float64, list<(float64, int64)>) -> list<(float64, int64)> */ 
  kk_std_core_types__cctx _brw_x229 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x230 = kk_src_metrics__trmc_lift_observe_10229(v_0, _uniq_xs_10171_0, _brw_x229, _ctx); /*list<(float64, int64)>*/;
  kk_std_core_types__cctx_drop(_brw_x229, _ctx);
  return _brw_x230;
}
 
// lifted local: observe, @spec-x10170
// specialized: std/core/list/map, on parameters @uniq-f@10167, using:
// @uniq-f@10167 = fn(bucket: (float64, int64)){
//   match (bucket) {
//     ((@skip std/core/types/Tuple2((upper: float64) : float64, (count: int64) : int64) : (float64, int64) ) as @pat@4: (float64, int64))
//        -> (match ((std/num/float64/(<=)(v, upper))) {
//         ((std/core/types/True() : bool ) as @pat@0@0: bool)
//            -> std/core/types/Tuple2<float64,int64>(upper, (std/num/int64/(+)(count, (std/num/int64/int64(1)))));
//         ((@skip std/core/types/False() : bool ) as @pat@1@0: bool)
//            -> bucket;
//       });
//   };
// }

kk_std_core_types__list kk_src_metrics__lift_observe_10228(double v, kk_std_core_types__list _uniq_xs_10166, kk_context_t* _ctx) { /* (v : float64, list<(float64, int64)>) -> list<(float64, int64)> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10166, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x227 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x228 = kk_src_metrics__trmc_lift_observe_10229(v, _uniq_xs_10166, _brw_x227, _ctx); /*list<(float64, int64)>*/;
    kk_std_core_types__cctx_drop(_brw_x227, _ctx);
    return _brw_x228;
  }
}

kk_src_metrics__histogram kk_src_metrics_observe(kk_src_metrics__histogram h, double v, kk_context_t* _ctx) { /* (h : histogram, v : float64) -> histogram */ 
  kk_std_core_types__list new_buckets;
  kk_std_core_types__list _x_x329;
  {
    struct kk_src_metrics_Histogram* _con_x330 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_std_core_types__list _x = _con_x330->buckets;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x329 = _x; /*list<(float64, int64)>*/
  }
  new_buckets = kk_src_metrics__lift_observe_10228(v, _x_x329, _ctx); /*list<(float64, int64)>*/
  kk_string_t _x_x331;
  {
    struct kk_src_metrics_Histogram* _con_x332 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_0 = _con_x332->name;
    kk_string_dup(_x_0, _ctx);
    _x_x331 = _x_0; /*string*/
  }
  double _x_x333;
  double _x_x334;
  {
    struct kk_src_metrics_Histogram* _con_x335 = kk_src_metrics__as_Histogram(h, _ctx);
    double _x_1 = _con_x335->sum;
    _x_x334 = _x_1; /*float64*/
  }
  _x_x333 = (_x_x334 + v); /*float64*/
  int64_t _x_x336;
  int64_t _x_x337;
  {
    struct kk_src_metrics_Histogram* _con_x338 = kk_src_metrics__as_Histogram(h, _ctx);
    int64_t _x_2 = _con_x338->count;
    _x_x337 = _x_2; /*int64*/
  }
  int64_t _x_x339 = (KK_I64(1)); /*int64*/
  _x_x336 = (int64_t)((uint64_t)_x_x337 + (uint64_t)_x_x339); /*int64*/
  kk_string_t _x_x340;
  {
    struct kk_src_metrics_Histogram* _con_x341 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _pat_0_4 = _con_x341->name;
    kk_std_core_types__list _pat_1_4 = _con_x341->buckets;
    kk_string_t _x_3 = _con_x341->help;
    if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
      kk_std_core_types__list_drop(_pat_1_4, _ctx);
      kk_string_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(h, _ctx);
    }
    else {
      kk_string_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(h, _ctx);
    }
    _x_x340 = _x_3; /*string*/
  }
  return kk_src_metrics__new_Histogram(kk_reuse_null, 0, _x_x331, new_buckets, _x_x333, _x_x336, _x_x340, _ctx);
}

kk_string_t kk_src_metrics_export_counter(kk_src_metrics__counter c, kk_context_t* _ctx) { /* (c : counter) -> string */ 
  kk_string_t _x_x342;
  kk_define_string_literal(, _s_x343, 7, "# HELP ", _ctx)
  _x_x342 = kk_string_dup(_s_x343, _ctx); /*string*/
  kk_string_t _x_x344;
  kk_string_t _x_x345;
  {
    struct kk_src_metrics_Counter* _con_x346 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x = _con_x346->name;
    kk_string_dup(_x, _ctx);
    _x_x345 = _x; /*string*/
  }
  kk_string_t _x_x347;
  kk_string_t _x_x348;
  kk_define_string_literal(, _s_x349, 1, " ", _ctx)
  _x_x348 = kk_string_dup(_s_x349, _ctx); /*string*/
  kk_string_t _x_x350;
  kk_string_t _x_x351;
  {
    struct kk_src_metrics_Counter* _con_x352 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x_0 = _con_x352->help;
    kk_string_dup(_x_0, _ctx);
    _x_x351 = _x_0; /*string*/
  }
  kk_string_t _x_x353;
  kk_string_t _x_x354;
  kk_define_string_literal(, _s_x355, 1, "\n", _ctx)
  _x_x354 = kk_string_dup(_s_x355, _ctx); /*string*/
  kk_string_t _x_x356;
  kk_string_t _x_x357;
  kk_define_string_literal(, _s_x358, 7, "# TYPE ", _ctx)
  _x_x357 = kk_string_dup(_s_x358, _ctx); /*string*/
  kk_string_t _x_x359;
  kk_string_t _x_x360;
  {
    struct kk_src_metrics_Counter* _con_x361 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x_1 = _con_x361->name;
    kk_string_dup(_x_1, _ctx);
    _x_x360 = _x_1; /*string*/
  }
  kk_string_t _x_x362;
  kk_string_t _x_x363;
  kk_define_string_literal(, _s_x364, 9, " counter\n", _ctx)
  _x_x363 = kk_string_dup(_s_x364, _ctx); /*string*/
  kk_string_t _x_x365;
  kk_string_t _x_x366;
  {
    struct kk_src_metrics_Counter* _con_x367 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _x_2 = _con_x367->name;
    kk_string_dup(_x_2, _ctx);
    _x_x366 = _x_2; /*string*/
  }
  kk_string_t _x_x368;
  kk_string_t _x_x369;
  kk_define_string_literal(, _s_x370, 1, " ", _ctx)
  _x_x369 = kk_string_dup(_s_x370, _ctx); /*string*/
  kk_string_t _x_x371;
  kk_integer_t _x_x372;
  int64_t _x_x373;
  {
    struct kk_src_metrics_Counter* _con_x374 = kk_src_metrics__as_Counter(c, _ctx);
    kk_string_t _pat_0_3 = _con_x374->name;
    int64_t _x_3 = _con_x374->value;
    kk_string_t _pat_1_3 = _con_x374->help;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_string_drop(_pat_1_3, _ctx);
      kk_string_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x373 = _x_3; /*int64*/
  }
  _x_x372 = kk_integer_from_int64(_x_x373,kk_context()); /*int*/
  _x_x371 = kk_std_core_int_show(_x_x372, _ctx); /*string*/
  _x_x368 = kk_std_core_types__lp__plus__plus__rp_(_x_x369, _x_x371, _ctx); /*string*/
  _x_x365 = kk_std_core_types__lp__plus__plus__rp_(_x_x366, _x_x368, _ctx); /*string*/
  _x_x362 = kk_std_core_types__lp__plus__plus__rp_(_x_x363, _x_x365, _ctx); /*string*/
  _x_x359 = kk_std_core_types__lp__plus__plus__rp_(_x_x360, _x_x362, _ctx); /*string*/
  _x_x356 = kk_std_core_types__lp__plus__plus__rp_(_x_x357, _x_x359, _ctx); /*string*/
  _x_x353 = kk_std_core_types__lp__plus__plus__rp_(_x_x354, _x_x356, _ctx); /*string*/
  _x_x350 = kk_std_core_types__lp__plus__plus__rp_(_x_x351, _x_x353, _ctx); /*string*/
  _x_x347 = kk_std_core_types__lp__plus__plus__rp_(_x_x348, _x_x350, _ctx); /*string*/
  _x_x344 = kk_std_core_types__lp__plus__plus__rp_(_x_x345, _x_x347, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x342, _x_x344, _ctx);
}

kk_string_t kk_src_metrics_export_gauge(kk_src_metrics__gauge g, kk_context_t* _ctx) { /* (g : gauge) -> string */ 
  kk_string_t _x_x375;
  kk_define_string_literal(, _s_x376, 7, "# HELP ", _ctx)
  _x_x375 = kk_string_dup(_s_x376, _ctx); /*string*/
  kk_string_t _x_x377;
  kk_string_t _x_x378;
  {
    struct kk_src_metrics_Gauge* _con_x379 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _x = _con_x379->name;
    kk_string_dup(_x, _ctx);
    _x_x378 = _x; /*string*/
  }
  kk_string_t _x_x380;
  kk_string_t _x_x381;
  kk_define_string_literal(, _s_x382, 1, " ", _ctx)
  _x_x381 = kk_string_dup(_s_x382, _ctx); /*string*/
  kk_string_t _x_x383;
  kk_string_t _x_x384;
  {
    struct kk_src_metrics_Gauge* _con_x385 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _x_0 = _con_x385->help;
    kk_string_dup(_x_0, _ctx);
    _x_x384 = _x_0; /*string*/
  }
  kk_string_t _x_x386;
  kk_string_t _x_x387;
  kk_define_string_literal(, _s_x388, 1, "\n", _ctx)
  _x_x387 = kk_string_dup(_s_x388, _ctx); /*string*/
  kk_string_t _x_x389;
  kk_string_t _x_x390;
  kk_define_string_literal(, _s_x391, 7, "# TYPE ", _ctx)
  _x_x390 = kk_string_dup(_s_x391, _ctx); /*string*/
  kk_string_t _x_x392;
  kk_string_t _x_x393;
  {
    struct kk_src_metrics_Gauge* _con_x394 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _x_1 = _con_x394->name;
    kk_string_dup(_x_1, _ctx);
    _x_x393 = _x_1; /*string*/
  }
  kk_string_t _x_x395;
  kk_string_t _x_x396;
  kk_define_string_literal(, _s_x397, 7, " gauge\n", _ctx)
  _x_x396 = kk_string_dup(_s_x397, _ctx); /*string*/
  kk_string_t _x_x398;
  kk_string_t _x_x399;
  {
    struct kk_src_metrics_Gauge* _con_x400 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _x_2 = _con_x400->name;
    kk_string_dup(_x_2, _ctx);
    _x_x399 = _x_2; /*string*/
  }
  kk_string_t _x_x401;
  kk_string_t _x_x402;
  kk_define_string_literal(, _s_x403, 1, " ", _ctx)
  _x_x402 = kk_string_dup(_s_x403, _ctx); /*string*/
  kk_string_t _x_x404;
  double _x_x405;
  {
    struct kk_src_metrics_Gauge* _con_x406 = kk_src_metrics__as_Gauge(g, _ctx);
    kk_string_t _pat_0_3 = _con_x406->name;
    double _x_3 = _con_x406->value;
    kk_string_t _pat_1_3 = _con_x406->help;
    if kk_likely(kk_datatype_ptr_is_unique(g, _ctx)) {
      kk_string_drop(_pat_1_3, _ctx);
      kk_string_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(g, _ctx);
    }
    else {
      kk_datatype_ptr_decref(g, _ctx);
    }
    _x_x405 = _x_3; /*float64*/
  }
  _x_x404 = kk_std_num_float64_show(_x_x405, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  _x_x401 = kk_std_core_types__lp__plus__plus__rp_(_x_x402, _x_x404, _ctx); /*string*/
  _x_x398 = kk_std_core_types__lp__plus__plus__rp_(_x_x399, _x_x401, _ctx); /*string*/
  _x_x395 = kk_std_core_types__lp__plus__plus__rp_(_x_x396, _x_x398, _ctx); /*string*/
  _x_x392 = kk_std_core_types__lp__plus__plus__rp_(_x_x393, _x_x395, _ctx); /*string*/
  _x_x389 = kk_std_core_types__lp__plus__plus__rp_(_x_x390, _x_x392, _ctx); /*string*/
  _x_x386 = kk_std_core_types__lp__plus__plus__rp_(_x_x387, _x_x389, _ctx); /*string*/
  _x_x383 = kk_std_core_types__lp__plus__plus__rp_(_x_x384, _x_x386, _ctx); /*string*/
  _x_x380 = kk_std_core_types__lp__plus__plus__rp_(_x_x381, _x_x383, _ctx); /*string*/
  _x_x377 = kk_std_core_types__lp__plus__plus__rp_(_x_x378, _x_x380, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x375, _x_x377, _ctx);
}

kk_string_t kk_src_metrics_list_fs__unroll_join_10000(kk_std_core_types__list xs, kk_string_t sep, kk_context_t* _ctx) { /* (xs : list<string>, sep : string) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_string_drop(sep, _ctx);
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x408 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x42 = _con_x408->head;
    kk_std_core_types__list _pat_1 = _con_x408->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t s = kk_string_unbox(_box_x42);
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
    struct kk_std_core_types_Cons* _con_x409 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x43 = _con_x409->head;
    kk_std_core_types__list rest = _con_x409->tail;
    kk_string_t s_0 = kk_string_unbox(_box_x43);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(rest, _ctx);
      kk_string_dup(s_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_string_t _x_x410;
    kk_string_t _x_x411 = kk_string_dup(sep, _ctx); /*string*/
    kk_string_t _x_x412 = kk_src_metrics_list_fs__unroll_join_10000(rest, sep, _ctx); /*string*/
    _x_x410 = kk_std_core_types__lp__plus__plus__rp_(_x_x411, _x_x412, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(s_0, _x_x410, _ctx);
  }
}
 
// lifted local: @lift-export-histogram@10230, export-histogram, @spec-x10190
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10185, using:
// @uniq-f@10185 = fn(b: (float64, int64)){
//   match (b) {
//     ((@skip std/core/types/Tuple2((upper: float64) : float64, (count: int64) : int64) : (float64, int64) ) as @pat@4: (float64, int64))
//        -> std/core/types/(++)((match (h) {
//           ((@skip src/metrics/Histogram((@x@0: string) : string, (@pat@0@0: (list :: V -> V)<(float64, int64)>) : (list :: V -> V)<(float64, int64)>, (@pat@1@0: float64) : float64, (@pat@2@0: int64) : int64, (@pat@3@0: string) : string) : src/metrics/histogram ) as @pat@5: src/metrics/histogram)
//              -> @x@0;
//         }), (std/core/types/(++)("_bucket{le=\x22", (std/core/types/(++)((std/num/float64/show(upper, (std/core/types/@None<int>))), (std/core/types/(++)("\x22} ", (std/core/int/show((std/num/int64/int(count)))))))))));
//   };
// }

kk_std_core_types__list kk_src_metrics__trmc_lift_export_histogram_10231(kk_src_metrics__histogram h, kk_std_core_types__list _uniq_xs_10184, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (h : histogram, list<(float64, int64)>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10184, _ctx)) {
    struct kk_std_core_types_Cons* _con_x414 = kk_std_core_types__as_Cons(_uniq_xs_10184, _ctx);
    kk_box_t _box_x44 = _con_x414->head;
    kk_std_core_types__list _uniq_xx_10188 = _con_x414->tail;
    kk_std_core_types__tuple2 _uniq_x_10187 = kk_std_core_types__tuple2_unbox(_box_x44, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x251 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10184, _ctx)) {
      kk_std_core_types__tuple2_dup(_uniq_x_10187, _ctx);
      kk_box_drop(_box_x44, _ctx);
      _ru_x251 = (kk_datatype_ptr_reuse(_uniq_xs_10184, _ctx));
    }
    else {
      kk_std_core_types__tuple2_dup(_uniq_x_10187, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10188, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10184, _ctx);
    }
    kk_string_t _trmc_x10245;
    {
      kk_box_t _box_x45 = _uniq_x_10187.fst;
      kk_box_t _box_x46 = _uniq_x_10187.snd;
      double upper = kk_double_unbox(_box_x45, KK_BORROWED, _ctx);
      int64_t count = kk_int64_unbox(_box_x46, KK_BORROWED, _ctx);
      kk_std_core_types__tuple2_drop(_uniq_x_10187, _ctx);
      kk_string_t _x_x415;
      {
        struct kk_src_metrics_Histogram* _con_x416 = kk_src_metrics__as_Histogram(h, _ctx);
        kk_string_t _x_0 = _con_x416->name;
        kk_string_dup(_x_0, _ctx);
        _x_x415 = _x_0; /*string*/
      }
      kk_string_t _x_x417;
      kk_string_t _x_x418;
      kk_define_string_literal(, _s_x419, 12, "_bucket{le=\"", _ctx)
      _x_x418 = kk_string_dup(_s_x419, _ctx); /*string*/
      kk_string_t _x_x420;
      kk_string_t _x_x421 = kk_std_num_float64_show(upper, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
      kk_string_t _x_x422;
      kk_string_t _x_x423;
      kk_define_string_literal(, _s_x424, 3, "\"} ", _ctx)
      _x_x423 = kk_string_dup(_s_x424, _ctx); /*string*/
      kk_string_t _x_x425;
      kk_integer_t _x_x426 = kk_integer_from_int64(count,kk_context()); /*int*/
      _x_x425 = kk_std_core_int_show(_x_x426, _ctx); /*string*/
      _x_x422 = kk_std_core_types__lp__plus__plus__rp_(_x_x423, _x_x425, _ctx); /*string*/
      _x_x420 = kk_std_core_types__lp__plus__plus__rp_(_x_x421, _x_x422, _ctx); /*string*/
      _x_x417 = kk_std_core_types__lp__plus__plus__rp_(_x_x418, _x_x420, _ctx); /*string*/
      _trmc_x10245 = kk_std_core_types__lp__plus__plus__rp_(_x_x415, _x_x417, _ctx); /*string*/
    }
    kk_std_core_types__list _trmc_x10246 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10247 = kk_std_core_types__new_Cons(_ru_x251, 0, kk_string_box(_trmc_x10245), _trmc_x10246, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x56_61 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10247, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x225;
    kk_std_core_types__cctx _x_x427 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x225 = kk_cctx_extend_linear(_x_x427,(kk_std_core_types__list_box(_trmc_x10247, _ctx)),_b_x56_61,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x226 = kk_src_metrics__trmc_lift_export_histogram_10231(h, _uniq_xx_10188, _brw_x225, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x225, _ctx);
    return _brw_x226;
  }
  {
    kk_datatype_ptr_dropn(h, (KK_I32(3)), _ctx);
    kk_box_t _x_x428;
    kk_std_core_types__cctx _x_x429 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x428 = kk_cctx_apply_linear(_x_x429,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x428, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-export-histogram@10230, export-histogram, @spec-x10190
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10185, using:
// @uniq-f@10185 = fn(b: (float64, int64)){
//   match (b) {
//     ((@skip std/core/types/Tuple2((upper: float64) : float64, (count: int64) : int64) : (float64, int64) ) as @pat@4: (float64, int64))
//        -> std/core/types/(++)((match (h) {
//           ((@skip src/metrics/Histogram((@x@0: string) : string, (@pat@0@0: (list :: V -> V)<(float64, int64)>) : (list :: V -> V)<(float64, int64)>, (@pat@1@0: float64) : float64, (@pat@2@0: int64) : int64, (@pat@3@0: string) : string) : src/metrics/histogram ) as @pat@5: src/metrics/histogram)
//              -> @x@0;
//         }), (std/core/types/(++)("_bucket{le=\x22", (std/core/types/(++)((std/num/float64/show(upper, (std/core/types/@None<int>))), (std/core/types/(++)("\x22} ", (std/core/int/show((std/num/int64/int(count)))))))))));
//   };
// }

kk_std_core_types__list kk_src_metrics__lift_export_histogram_10231(kk_src_metrics__histogram h_0, kk_std_core_types__list _uniq_xs_10184_0, kk_context_t* _ctx) { /* (h : histogram, list<(float64, int64)>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x223 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x224 = kk_src_metrics__trmc_lift_export_histogram_10231(h_0, _uniq_xs_10184_0, _brw_x223, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x223, _ctx);
  return _brw_x224;
}
 
// lifted local: export-histogram, @spec-x10183
// specialized: std/core/list/map, on parameters @uniq-f@10180, using:
// @uniq-f@10180 = fn(b: (float64, int64)){
//   match (b) {
//     ((@skip std/core/types/Tuple2((upper: float64) : float64, (count: int64) : int64) : (float64, int64) ) as @pat@4: (float64, int64))
//        -> std/core/types/(++)((match (h) {
//           ((@skip src/metrics/Histogram((@x@0: string) : string, (@pat@0@0: (list :: V -> V)<(float64, int64)>) : (list :: V -> V)<(float64, int64)>, (@pat@1@0: float64) : float64, (@pat@2@0: int64) : int64, (@pat@3@0: string) : string) : src/metrics/histogram ) as @pat@5: src/metrics/histogram)
//              -> @x@0;
//         }), (std/core/types/(++)("_bucket{le=\x22", (std/core/types/(++)((std/num/float64/show(upper, (std/core/types/@None<int>))), (std/core/types/(++)("\x22} ", (std/core/int/show((std/num/int64/int(count)))))))))));
//   };
// }

kk_std_core_types__list kk_src_metrics__lift_export_histogram_10230(kk_src_metrics__histogram h, kk_std_core_types__list _uniq_xs_10179, kk_context_t* _ctx) { /* (h : histogram, list<(float64, int64)>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10179, _ctx)) {
    kk_datatype_ptr_dropn(h, (KK_I32(3)), _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x221 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x222 = kk_src_metrics__trmc_lift_export_histogram_10231(h, _uniq_xs_10179, _brw_x221, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x221, _ctx);
    return _brw_x222;
  }
}

kk_string_t kk_src_metrics_export_histogram(kk_src_metrics__histogram h, kk_context_t* _ctx) { /* (h : histogram) -> string */ 
  kk_std_core_types__list bucket_lines;
  kk_src_metrics__histogram _x_x430 = kk_src_metrics__histogram_dup(h, _ctx); /*src/metrics/histogram*/
  kk_std_core_types__list _x_x431;
  {
    struct kk_src_metrics_Histogram* _con_x432 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_std_core_types__list _x = _con_x432->buckets;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x431 = _x; /*list<(float64, int64)>*/
  }
  bucket_lines = kk_src_metrics__lift_export_histogram_10230(_x_x430, _x_x431, _ctx); /*list<string>*/
  kk_string_t _b_x69_71;
  kk_string_t _x_x433;
  kk_define_string_literal(, _s_x434, 7, "# HELP ", _ctx)
  _x_x433 = kk_string_dup(_s_x434, _ctx); /*string*/
  kk_string_t _x_x435;
  kk_string_t _x_x436;
  {
    struct kk_src_metrics_Histogram* _con_x437 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_1 = _con_x437->name;
    kk_string_dup(_x_1, _ctx);
    _x_x436 = _x_1; /*string*/
  }
  kk_string_t _x_x438;
  kk_string_t _x_x439;
  kk_define_string_literal(, _s_x440, 1, " ", _ctx)
  _x_x439 = kk_string_dup(_s_x440, _ctx); /*string*/
  kk_string_t _x_x441;
  {
    struct kk_src_metrics_Histogram* _con_x442 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_2 = _con_x442->help;
    kk_string_dup(_x_2, _ctx);
    _x_x441 = _x_2; /*string*/
  }
  _x_x438 = kk_std_core_types__lp__plus__plus__rp_(_x_x439, _x_x441, _ctx); /*string*/
  _x_x435 = kk_std_core_types__lp__plus__plus__rp_(_x_x436, _x_x438, _ctx); /*string*/
  _b_x69_71 = kk_std_core_types__lp__plus__plus__rp_(_x_x433, _x_x435, _ctx); /*string*/
  kk_string_t _b_x67_73;
  kk_string_t _x_x443;
  kk_define_string_literal(, _s_x444, 7, "# TYPE ", _ctx)
  _x_x443 = kk_string_dup(_s_x444, _ctx); /*string*/
  kk_string_t _x_x445;
  kk_string_t _x_x446;
  {
    struct kk_src_metrics_Histogram* _con_x447 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_3 = _con_x447->name;
    kk_string_dup(_x_3, _ctx);
    _x_x446 = _x_3; /*string*/
  }
  kk_string_t _x_x448;
  kk_define_string_literal(, _s_x449, 10, " histogram", _ctx)
  _x_x448 = kk_string_dup(_s_x449, _ctx); /*string*/
  _x_x445 = kk_std_core_types__lp__plus__plus__rp_(_x_x446, _x_x448, _ctx); /*string*/
  _b_x67_73 = kk_std_core_types__lp__plus__plus__rp_(_x_x443, _x_x445, _ctx); /*string*/
  kk_std_core_types__list xs_10043;
  kk_std_core_types__list _x_x450 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x67_73), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  xs_10043 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x69_71), _x_x450, _ctx); /*list<string>*/
  kk_string_t _b_x77_79;
  kk_string_t _x_x451;
  {
    struct kk_src_metrics_Histogram* _con_x452 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_4 = _con_x452->name;
    kk_string_dup(_x_4, _ctx);
    _x_x451 = _x_4; /*string*/
  }
  kk_string_t _x_x453;
  kk_string_t _x_x454;
  kk_define_string_literal(, _s_x455, 5, "_sum ", _ctx)
  _x_x454 = kk_string_dup(_s_x455, _ctx); /*string*/
  kk_string_t _x_x456;
  double _x_x457;
  {
    struct kk_src_metrics_Histogram* _con_x458 = kk_src_metrics__as_Histogram(h, _ctx);
    double _x_5 = _con_x458->sum;
    _x_x457 = _x_5; /*float64*/
  }
  _x_x456 = kk_std_num_float64_show(_x_x457, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  _x_x453 = kk_std_core_types__lp__plus__plus__rp_(_x_x454, _x_x456, _ctx); /*string*/
  _b_x77_79 = kk_std_core_types__lp__plus__plus__rp_(_x_x451, _x_x453, _ctx); /*string*/
  kk_string_t _b_x75_81;
  kk_string_t _x_x459;
  {
    struct kk_src_metrics_Histogram* _con_x460 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _x_6 = _con_x460->name;
    kk_string_dup(_x_6, _ctx);
    _x_x459 = _x_6; /*string*/
  }
  kk_string_t _x_x461;
  kk_string_t _x_x462;
  kk_define_string_literal(, _s_x463, 7, "_count ", _ctx)
  _x_x462 = kk_string_dup(_s_x463, _ctx); /*string*/
  kk_string_t _x_x464;
  kk_integer_t _x_x465;
  int64_t _x_x466;
  {
    struct kk_src_metrics_Histogram* _con_x467 = kk_src_metrics__as_Histogram(h, _ctx);
    kk_string_t _pat_0_9 = _con_x467->name;
    kk_std_core_types__list _pat_1_7 = _con_x467->buckets;
    int64_t _x_7 = _con_x467->count;
    kk_string_t _pat_3_7 = _con_x467->help;
    if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
      kk_string_drop(_pat_3_7, _ctx);
      kk_std_core_types__list_drop(_pat_1_7, _ctx);
      kk_string_drop(_pat_0_9, _ctx);
      kk_datatype_ptr_free(h, _ctx);
    }
    else {
      kk_datatype_ptr_decref(h, _ctx);
    }
    _x_x466 = _x_7; /*int64*/
  }
  _x_x465 = kk_integer_from_int64(_x_x466,kk_context()); /*int*/
  _x_x464 = kk_std_core_int_show(_x_x465, _ctx); /*string*/
  _x_x461 = kk_std_core_types__lp__plus__plus__rp_(_x_x462, _x_x464, _ctx); /*string*/
  _b_x75_81 = kk_std_core_types__lp__plus__plus__rp_(_x_x459, _x_x461, _ctx); /*string*/
  kk_std_core_types__list ys_0_10049;
  kk_std_core_types__list _x_x468 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x75_81), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  ys_0_10049 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x77_79), _x_x468, _ctx); /*list<string>*/
  kk_std_core_types__list ys_10044;
  if (kk_std_core_types__is_Nil(bucket_lines, _ctx)) {
    ys_10044 = ys_0_10049; /*list<string>*/
  }
  else {
    ys_10044 = kk_std_core_list__unroll_append_10004(bucket_lines, ys_0_10049, _ctx); /*list<string>*/
  }
  kk_std_core_types__list lines;
  if (kk_std_core_types__is_Nil(xs_10043, _ctx)) {
    lines = ys_10044; /*list<string>*/
  }
  else {
    lines = kk_std_core_list__unroll_append_10004(xs_10043, ys_10044, _ctx); /*list<string>*/
  }
  if (kk_std_core_types__is_Nil(lines, _ctx)) {
    return kk_string_empty();
  }
  {
    kk_string_t _x_x470;
    kk_define_string_literal(, _s_x471, 1, "\n", _ctx)
    _x_x470 = kk_string_dup(_s_x471, _ctx); /*string*/
    return kk_src_metrics_list_fs__unroll_join_10000(lines, _x_x470, _ctx);
  }
}
 
// lifted local: @lift-export-all@10232, export-all, @spec-x10203
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10198, using:
// @uniq-f@10198 = src/metrics/export-counter

kk_std_core_types__list kk_src_metrics__trmc_lift_export_all_10233(kk_std_core_types__list _uniq_xs_10197, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<counter>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10197, _ctx)) {
    struct kk_std_core_types_Cons* _con_x472 = kk_std_core_types__as_Cons(_uniq_xs_10197, _ctx);
    kk_box_t _box_x83 = _con_x472->head;
    kk_std_core_types__list _uniq_xx_10201 = _con_x472->tail;
    kk_src_metrics__counter _uniq_x_10200 = kk_src_metrics__counter_unbox(_box_x83, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x255 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10197, _ctx)) {
      _ru_x255 = (kk_datatype_ptr_reuse(_uniq_xs_10197, _ctx));
    }
    else {
      kk_src_metrics__counter_dup(_uniq_x_10200, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10201, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10197, _ctx);
    }
    kk_string_t _trmc_x10248 = kk_src_metrics_export_counter(_uniq_x_10200, _ctx); /*string*/;
    kk_std_core_types__list _trmc_x10249 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10250 = kk_std_core_types__new_Cons(_ru_x255, 0, kk_string_box(_trmc_x10248), _trmc_x10249, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x93_98 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10250, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x219;
    kk_std_core_types__cctx _x_x473 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x219 = kk_cctx_extend_linear(_x_x473,(kk_std_core_types__list_box(_trmc_x10250, _ctx)),_b_x93_98,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x220 = kk_src_metrics__trmc_lift_export_all_10233(_uniq_xx_10201, _brw_x219, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x219, _ctx);
    return _brw_x220;
  }
  {
    kk_box_t _x_x474;
    kk_std_core_types__cctx _x_x475 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x474 = kk_cctx_apply_linear(_x_x475,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x474, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-export-all@10232, export-all, @spec-x10203
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10198, using:
// @uniq-f@10198 = src/metrics/export-counter

kk_std_core_types__list kk_src_metrics__lift_export_all_10233(kk_std_core_types__list _uniq_xs_10197_0, kk_context_t* _ctx) { /* (list<counter>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x217 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x218 = kk_src_metrics__trmc_lift_export_all_10233(_uniq_xs_10197_0, _brw_x217, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x217, _ctx);
  return _brw_x218;
}
 
// lifted local: export-all, @spec-x10196
// specialized: std/core/list/map, on parameters @uniq-f@10193, using:
// @uniq-f@10193 = src/metrics/export-counter

kk_std_core_types__list kk_src_metrics__lift_export_all_10232(kk_std_core_types__list _uniq_xs_10192, kk_context_t* _ctx) { /* (list<counter>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10192, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x215 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x216 = kk_src_metrics__trmc_lift_export_all_10233(_uniq_xs_10192, _brw_x215, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x215, _ctx);
    return _brw_x216;
  }
}
 
// lifted local: @lift-export-all@10234, export-all, @spec-x10215
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10210, using:
// @uniq-f@10210 = src/metrics/export-gauge

kk_std_core_types__list kk_src_metrics__trmc_lift_export_all_10235(kk_std_core_types__list _uniq_xs_10209, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<gauge>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10209, _ctx)) {
    struct kk_std_core_types_Cons* _con_x476 = kk_std_core_types__as_Cons(_uniq_xs_10209, _ctx);
    kk_box_t _box_x104 = _con_x476->head;
    kk_std_core_types__list _uniq_xx_10213 = _con_x476->tail;
    kk_src_metrics__gauge _uniq_x_10212 = kk_src_metrics__gauge_unbox(_box_x104, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x256 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10209, _ctx)) {
      _ru_x256 = (kk_datatype_ptr_reuse(_uniq_xs_10209, _ctx));
    }
    else {
      kk_src_metrics__gauge_dup(_uniq_x_10212, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10213, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10209, _ctx);
    }
    kk_string_t _trmc_x10251 = kk_src_metrics_export_gauge(_uniq_x_10212, _ctx); /*string*/;
    kk_std_core_types__list _trmc_x10252 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10253 = kk_std_core_types__new_Cons(_ru_x256, 0, kk_string_box(_trmc_x10251), _trmc_x10252, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x114_119 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10253, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x213;
    kk_std_core_types__cctx _x_x477 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x213 = kk_cctx_extend_linear(_x_x477,(kk_std_core_types__list_box(_trmc_x10253, _ctx)),_b_x114_119,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x214 = kk_src_metrics__trmc_lift_export_all_10235(_uniq_xx_10213, _brw_x213, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x213, _ctx);
    return _brw_x214;
  }
  {
    kk_box_t _x_x478;
    kk_std_core_types__cctx _x_x479 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x478 = kk_cctx_apply_linear(_x_x479,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x478, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-export-all@10234, export-all, @spec-x10215
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10210, using:
// @uniq-f@10210 = src/metrics/export-gauge

kk_std_core_types__list kk_src_metrics__lift_export_all_10235(kk_std_core_types__list _uniq_xs_10209_0, kk_context_t* _ctx) { /* (list<gauge>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x211 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x212 = kk_src_metrics__trmc_lift_export_all_10235(_uniq_xs_10209_0, _brw_x211, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x211, _ctx);
  return _brw_x212;
}
 
// lifted local: export-all, @spec-x10208
// specialized: std/core/list/map, on parameters @uniq-f@10205, using:
// @uniq-f@10205 = src/metrics/export-gauge

kk_std_core_types__list kk_src_metrics__lift_export_all_10234(kk_std_core_types__list _uniq_xs_10204, kk_context_t* _ctx) { /* (list<gauge>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10204, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x209 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x210 = kk_src_metrics__trmc_lift_export_all_10235(_uniq_xs_10204, _brw_x209, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x209, _ctx);
    return _brw_x210;
  }
}
 
// lifted local: @lift-export-all@10236, export-all, @spec-x10227
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10222, using:
// @uniq-f@10222 = src/metrics/export-histogram

kk_std_core_types__list kk_src_metrics__trmc_lift_export_all_10237(kk_std_core_types__list _uniq_xs_10221, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<histogram>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10221, _ctx)) {
    struct kk_std_core_types_Cons* _con_x480 = kk_std_core_types__as_Cons(_uniq_xs_10221, _ctx);
    kk_box_t _box_x125 = _con_x480->head;
    kk_std_core_types__list _uniq_xx_10225 = _con_x480->tail;
    kk_src_metrics__histogram _uniq_x_10224 = kk_src_metrics__histogram_unbox(_box_x125, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x257 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10221, _ctx)) {
      _ru_x257 = (kk_datatype_ptr_reuse(_uniq_xs_10221, _ctx));
    }
    else {
      kk_src_metrics__histogram_dup(_uniq_x_10224, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10225, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10221, _ctx);
    }
    kk_string_t _trmc_x10254 = kk_src_metrics_export_histogram(_uniq_x_10224, _ctx); /*string*/;
    kk_std_core_types__list _trmc_x10255 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10256 = kk_std_core_types__new_Cons(_ru_x257, 0, kk_string_box(_trmc_x10254), _trmc_x10255, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x135_140 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10256, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x207;
    kk_std_core_types__cctx _x_x481 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x207 = kk_cctx_extend_linear(_x_x481,(kk_std_core_types__list_box(_trmc_x10256, _ctx)),_b_x135_140,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x208 = kk_src_metrics__trmc_lift_export_all_10237(_uniq_xx_10225, _brw_x207, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x207, _ctx);
    return _brw_x208;
  }
  {
    kk_box_t _x_x482;
    kk_std_core_types__cctx _x_x483 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x482 = kk_cctx_apply_linear(_x_x483,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x482, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-export-all@10236, export-all, @spec-x10227
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10222, using:
// @uniq-f@10222 = src/metrics/export-histogram

kk_std_core_types__list kk_src_metrics__lift_export_all_10237(kk_std_core_types__list _uniq_xs_10221_0, kk_context_t* _ctx) { /* (list<histogram>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x205 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x206 = kk_src_metrics__trmc_lift_export_all_10237(_uniq_xs_10221_0, _brw_x205, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x205, _ctx);
  return _brw_x206;
}
 
// lifted local: export-all, @spec-x10220
// specialized: std/core/list/map, on parameters @uniq-f@10217, using:
// @uniq-f@10217 = src/metrics/export-histogram

kk_std_core_types__list kk_src_metrics__lift_export_all_10236(kk_std_core_types__list _uniq_xs_10216, kk_context_t* _ctx) { /* (list<histogram>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10216, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x203 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x204 = kk_src_metrics__trmc_lift_export_all_10237(_uniq_xs_10216, _brw_x203, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x203, _ctx);
    return _brw_x204;
  }
}

kk_string_t kk_src_metrics_export_all(kk_src_metrics__metrics_snapshot snapshot, kk_context_t* _ctx) { /* (snapshot : metrics-snapshot) -> string */ 
  kk_std_core_types__list counter_lines;
  kk_std_core_types__list _x_x484;
  {
    struct kk_src_metrics_Metrics_snapshot* _con_x485 = kk_src_metrics__as_Metrics_snapshot(snapshot, _ctx);
    kk_std_core_types__list _x = _con_x485->counters;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x484 = _x; /*list<src/metrics/counter>*/
  }
  counter_lines = kk_src_metrics__lift_export_all_10232(_x_x484, _ctx); /*list<string>*/
  kk_std_core_types__list gauge_lines;
  kk_std_core_types__list _x_x486;
  {
    struct kk_src_metrics_Metrics_snapshot* _con_x487 = kk_src_metrics__as_Metrics_snapshot(snapshot, _ctx);
    kk_std_core_types__list _x_0 = _con_x487->gauges;
    kk_std_core_types__list_dup(_x_0, _ctx);
    _x_x486 = _x_0; /*list<src/metrics/gauge>*/
  }
  gauge_lines = kk_src_metrics__lift_export_all_10234(_x_x486, _ctx); /*list<string>*/
  kk_std_core_types__list hist_lines;
  kk_std_core_types__list _x_x488;
  {
    struct kk_src_metrics_Metrics_snapshot* _con_x489 = kk_src_metrics__as_Metrics_snapshot(snapshot, _ctx);
    kk_std_core_types__list _pat_0_1 = _con_x489->counters;
    kk_std_core_types__list _pat_1_1 = _con_x489->gauges;
    kk_std_core_types__list _x_1 = _con_x489->histograms;
    if kk_likely(kk_datatype_ptr_is_unique(snapshot, _ctx)) {
      kk_std_core_types__list_drop(_pat_1_1, _ctx);
      kk_std_core_types__list_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(snapshot, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(snapshot, _ctx);
    }
    _x_x488 = _x_1; /*list<src/metrics/histogram>*/
  }
  hist_lines = kk_src_metrics__lift_export_all_10236(_x_x488, _ctx); /*list<string>*/
  kk_std_core_types__list ys_10063;
  if (kk_std_core_types__is_Nil(gauge_lines, _ctx)) {
    ys_10063 = hist_lines; /*list<string>*/
  }
  else {
    ys_10063 = kk_std_core_list__unroll_append_10004(gauge_lines, hist_lines, _ctx); /*list<string>*/
  }
  kk_std_core_types__list xs_10060;
  if (kk_std_core_types__is_Nil(counter_lines, _ctx)) {
    xs_10060 = ys_10063; /*list<string>*/
  }
  else {
    xs_10060 = kk_std_core_list__unroll_append_10004(counter_lines, ys_10063, _ctx); /*list<string>*/
  }
  if (kk_std_core_types__is_Nil(xs_10060, _ctx)) {
    return kk_string_empty();
  }
  {
    kk_string_t _x_x491;
    kk_define_string_literal(, _s_x492, 2, "\n\n", _ctx)
    _x_x491 = kk_string_dup(_s_x492, _ctx); /*string*/
    return kk_src_metrics_list_fs__unroll_join_10000(xs_10060, _x_x491, _ctx);
  }
}

kk_src_metrics__metrics_snapshot kk_src_metrics_standard_ipc_metrics(kk_string_t binary_name, kk_context_t* _ctx) { /* (binary-name : string) -> metrics-snapshot */ 
  kk_string_drop(binary_name, _ctx);
  kk_src_metrics__counter _b_x148_172;
  kk_string_t _x_x493;
  kk_define_string_literal(, _s_x494, 23, "koka_ipc_commands_total", _ctx)
  _x_x493 = kk_string_dup(_s_x494, _ctx); /*string*/
  int64_t _x_x495 = (KK_I64(0)); /*int64*/
  kk_string_t _x_x496;
  kk_define_string_literal(, _s_x497, 28, "Total IPC commands processed", _ctx)
  _x_x496 = kk_string_dup(_s_x497, _ctx); /*string*/
  _b_x148_172 = kk_src_metrics__new_Counter(kk_reuse_null, 0, _x_x493, _x_x495, _x_x496, _ctx); /*src/metrics/counter*/
  kk_src_metrics__counter _b_x146_174;
  kk_string_t _x_x498;
  kk_define_string_literal(, _s_x499, 21, "koka_ipc_errors_total", _ctx)
  _x_x498 = kk_string_dup(_s_x499, _ctx); /*string*/
  int64_t _x_x500 = (KK_I64(0)); /*int64*/
  kk_string_t _x_x501;
  kk_define_string_literal(, _s_x502, 16, "Total IPC errors", _ctx)
  _x_x501 = kk_string_dup(_s_x502, _ctx); /*string*/
  _b_x146_174 = kk_src_metrics__new_Counter(kk_reuse_null, 0, _x_x498, _x_x500, _x_x501, _ctx); /*src/metrics/counter*/
  int64_t _b_x155_185 = (KK_I64(0)); /*int64*/;
  int64_t _b_x157_189 = (KK_I64(0)); /*int64*/;
  int64_t _b_x159_193 = (KK_I64(0)); /*int64*/;
  int64_t _b_x161_197 = (KK_I64(0)); /*int64*/;
  kk_src_metrics__histogram _b_x170_180;
  kk_string_t _x_x503;
  kk_define_string_literal(, _s_x504, 20, "koka_ipc_duration_ms", _ctx)
  _x_x503 = kk_string_dup(_s_x504, _ctx); /*string*/
  kk_std_core_types__list _x_x505;
  kk_box_t _x_x506;
  kk_std_core_types__tuple2 _x_x507 = kk_std_core_types__new_Tuple2(kk_double_box(0x1.999999999999ap-4, _ctx), kk_int64_box(_b_x155_185, _ctx), _ctx); /*(10037, 10038)*/
  _x_x506 = kk_std_core_types__tuple2_box(_x_x507, _ctx); /*10021*/
  kk_std_core_types__list _x_x508;
  kk_box_t _x_x509;
  kk_std_core_types__tuple2 _x_x510 = kk_std_core_types__new_Tuple2(kk_double_box(0x1p0, _ctx), kk_int64_box(_b_x157_189, _ctx), _ctx); /*(10037, 10038)*/
  _x_x509 = kk_std_core_types__tuple2_box(_x_x510, _ctx); /*10021*/
  kk_std_core_types__list _x_x511;
  kk_box_t _x_x512;
  kk_std_core_types__tuple2 _x_x513 = kk_std_core_types__new_Tuple2(kk_double_box(0x1.4p3, _ctx), kk_int64_box(_b_x159_193, _ctx), _ctx); /*(10037, 10038)*/
  _x_x512 = kk_std_core_types__tuple2_box(_x_x513, _ctx); /*10021*/
  kk_std_core_types__list _x_x514;
  kk_box_t _x_x515;
  kk_std_core_types__tuple2 _x_x516 = kk_std_core_types__new_Tuple2(kk_double_box(0x1.9p6, _ctx), kk_int64_box(_b_x161_197, _ctx), _ctx); /*(10037, 10038)*/
  _x_x515 = kk_std_core_types__tuple2_box(_x_x516, _ctx); /*10021*/
  _x_x514 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x515, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x511 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x512, _x_x514, _ctx); /*list<10021>*/
  _x_x508 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x509, _x_x511, _ctx); /*list<10021>*/
  _x_x505 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x506, _x_x508, _ctx); /*list<10021>*/
  int64_t _x_x517 = (KK_I64(0)); /*int64*/
  kk_string_t _x_x518;
  kk_define_string_literal(, _s_x519, 36, "IPC command duration in milliseconds", _ctx)
  _x_x518 = kk_string_dup(_s_x519, _ctx); /*string*/
  _b_x170_180 = kk_src_metrics__new_Histogram(kk_reuse_null, 0, _x_x503, _x_x505, 0x0p+0, _x_x517, _x_x518, _ctx); /*src/metrics/histogram*/
  kk_std_core_types__list _x_x520;
  kk_std_core_types__list _x_x521 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_src_metrics__counter_box(_b_x146_174, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x520 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_src_metrics__counter_box(_b_x148_172, _ctx), _x_x521, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x522;
  kk_box_t _x_x523;
  kk_src_metrics__gauge _x_x524;
  kk_string_t _x_x525;
  kk_define_string_literal(, _s_x526, 19, "koka_ipc_latency_ms", _ctx)
  _x_x525 = kk_string_dup(_s_x526, _ctx); /*string*/
  kk_string_t _x_x527;
  kk_define_string_literal(, _s_x528, 35, "Current IPC latency in milliseconds", _ctx)
  _x_x527 = kk_string_dup(_s_x528, _ctx); /*string*/
  _x_x524 = kk_src_metrics__new_Gauge(kk_reuse_null, 0, _x_x525, 0x0p+0, _x_x527, _ctx); /*src/metrics/gauge*/
  _x_x523 = kk_src_metrics__gauge_box(_x_x524, _ctx); /*10021*/
  kk_std_core_types__list _x_x529;
  kk_box_t _x_x530;
  kk_src_metrics__gauge _x_x531;
  kk_string_t _x_x532;
  kk_define_string_literal(, _s_x533, 27, "koka_process_uptime_seconds", _ctx)
  _x_x532 = kk_string_dup(_s_x533, _ctx); /*string*/
  kk_string_t _x_x534;
  kk_define_string_literal(, _s_x535, 25, "Process uptime in seconds", _ctx)
  _x_x534 = kk_string_dup(_s_x535, _ctx); /*string*/
  _x_x531 = kk_src_metrics__new_Gauge(kk_reuse_null, 0, _x_x532, 0x0p+0, _x_x534, _ctx); /*src/metrics/gauge*/
  _x_x530 = kk_src_metrics__gauge_box(_x_x531, _ctx); /*10021*/
  _x_x529 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x530, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x522 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x523, _x_x529, _ctx); /*list<10021>*/
  kk_std_core_types__list _x_x536 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_src_metrics__histogram_box(_b_x170_180, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  return kk_src_metrics__new_Metrics_snapshot(kk_reuse_null, 0, _x_x520, _x_x522, _x_x536, 0x0p+0, _ctx);
}


// lift anonymous function
struct kk_src_metrics_main_fun541__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_metrics_main_fun541(kk_function_t _fself, kk_box_t _b_x200, kk_context_t* _ctx);
static kk_function_t kk_src_metrics_new_main_fun541(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_metrics_main_fun541, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_metrics_main_fun541(kk_function_t _fself, kk_box_t _b_x200, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x542;
  kk_src_metrics__metrics_snapshot _x_x543 = kk_src_metrics__metrics_snapshot_unbox(_b_x200, KK_OWNED, _ctx); /*src/metrics/metrics-snapshot*/
  _x_x542 = kk_src_metrics_export_all(_x_x543, _ctx); /*string*/
  return kk_string_box(_x_x542);
}

kk_unit_t kk_src_metrics_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_src_metrics__metrics_snapshot x;
  kk_string_t _x_x537;
  kk_define_string_literal(, _s_x538, 4, "test", _ctx)
  _x_x537 = kk_string_dup(_s_x538, _ctx); /*string*/
  x = kk_src_metrics_standard_ipc_metrics(_x_x537, _ctx); /*src/metrics/metrics-snapshot*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_string_t _x_x539;
  kk_box_t _x_x540 = kk_std_core_hnd__open_none1(kk_src_metrics_new_main_fun541(_ctx), kk_src_metrics__metrics_snapshot_box(x, _ctx), _ctx); /*10001*/
  _x_x539 = kk_string_unbox(_x_x540); /*string*/
  kk_std_core_console_printsln(_x_x539, _ctx); return kk_Unit;
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
