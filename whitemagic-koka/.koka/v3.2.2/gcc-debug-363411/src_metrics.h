#pragma once
#ifndef kk_src_metrics_H
#define kk_src_metrics_H
// Koka generated module: src/metrics, koka version: 3.2.2, platform: 64-bit
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
#include "std_num_float64.h"
#include "std_num_int64.h"
#include "std_time.h"

// type declarations

// type src/metrics/counter
struct kk_src_metrics__counter_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_metrics__counter;
struct kk_src_metrics_Counter {
  struct kk_src_metrics__counter_s _base;
  kk_string_t name;
  kk_string_t help;
  int64_t value;
};
static inline kk_src_metrics__counter kk_src_metrics__base_Counter(struct kk_src_metrics_Counter* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_metrics__counter kk_src_metrics__new_Counter(kk_reuse_t _at, int32_t _cpath, kk_string_t name, int64_t value, kk_string_t help, kk_context_t* _ctx) {
  struct kk_src_metrics_Counter* _con = kk_block_alloc_at_as(struct kk_src_metrics_Counter, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->name = name;
  _con->help = help;
  _con->value = value;
  return kk_src_metrics__base_Counter(_con, _ctx);
}
static inline struct kk_src_metrics_Counter* kk_src_metrics__as_Counter(kk_src_metrics__counter x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_metrics_Counter*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_metrics__is_Counter(kk_src_metrics__counter x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_metrics__counter kk_src_metrics__counter_dup(kk_src_metrics__counter _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_metrics__counter_drop(kk_src_metrics__counter _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_metrics__counter_box(kk_src_metrics__counter _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_metrics__counter kk_src_metrics__counter_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/metrics/gauge
struct kk_src_metrics__gauge_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_metrics__gauge;
struct kk_src_metrics_Gauge {
  struct kk_src_metrics__gauge_s _base;
  kk_string_t name;
  kk_string_t help;
  double value;
};
static inline kk_src_metrics__gauge kk_src_metrics__base_Gauge(struct kk_src_metrics_Gauge* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_metrics__gauge kk_src_metrics__new_Gauge(kk_reuse_t _at, int32_t _cpath, kk_string_t name, double value, kk_string_t help, kk_context_t* _ctx) {
  struct kk_src_metrics_Gauge* _con = kk_block_alloc_at_as(struct kk_src_metrics_Gauge, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->name = name;
  _con->help = help;
  _con->value = value;
  return kk_src_metrics__base_Gauge(_con, _ctx);
}
static inline struct kk_src_metrics_Gauge* kk_src_metrics__as_Gauge(kk_src_metrics__gauge x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_metrics_Gauge*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_metrics__is_Gauge(kk_src_metrics__gauge x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_metrics__gauge kk_src_metrics__gauge_dup(kk_src_metrics__gauge _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_metrics__gauge_drop(kk_src_metrics__gauge _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_metrics__gauge_box(kk_src_metrics__gauge _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_metrics__gauge kk_src_metrics__gauge_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/metrics/histogram
struct kk_src_metrics__histogram_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_metrics__histogram;
struct kk_src_metrics_Histogram {
  struct kk_src_metrics__histogram_s _base;
  kk_string_t name;
  kk_std_core_types__list buckets;
  kk_string_t help;
  double sum;
  int64_t count;
};
static inline kk_src_metrics__histogram kk_src_metrics__base_Histogram(struct kk_src_metrics_Histogram* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_metrics__histogram kk_src_metrics__new_Histogram(kk_reuse_t _at, int32_t _cpath, kk_string_t name, kk_std_core_types__list buckets, double sum, int64_t count, kk_string_t help, kk_context_t* _ctx) {
  struct kk_src_metrics_Histogram* _con = kk_block_alloc_at_as(struct kk_src_metrics_Histogram, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->name = name;
  _con->buckets = buckets;
  _con->help = help;
  _con->sum = sum;
  _con->count = count;
  return kk_src_metrics__base_Histogram(_con, _ctx);
}
static inline struct kk_src_metrics_Histogram* kk_src_metrics__as_Histogram(kk_src_metrics__histogram x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_metrics_Histogram*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_metrics__is_Histogram(kk_src_metrics__histogram x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_metrics__histogram kk_src_metrics__histogram_dup(kk_src_metrics__histogram _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_metrics__histogram_drop(kk_src_metrics__histogram _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_metrics__histogram_box(kk_src_metrics__histogram _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_metrics__histogram kk_src_metrics__histogram_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type src/metrics/metrics-snapshot
struct kk_src_metrics__metrics_snapshot_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_src_metrics__metrics_snapshot;
struct kk_src_metrics_Metrics_snapshot {
  struct kk_src_metrics__metrics_snapshot_s _base;
  kk_std_core_types__list counters;
  kk_std_core_types__list gauges;
  kk_std_core_types__list histograms;
  double timestamp;
};
static inline kk_src_metrics__metrics_snapshot kk_src_metrics__base_Metrics_snapshot(struct kk_src_metrics_Metrics_snapshot* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_src_metrics__metrics_snapshot kk_src_metrics__new_Metrics_snapshot(kk_reuse_t _at, int32_t _cpath, kk_std_core_types__list counters, kk_std_core_types__list gauges, kk_std_core_types__list histograms, double timestamp, kk_context_t* _ctx) {
  struct kk_src_metrics_Metrics_snapshot* _con = kk_block_alloc_at_as(struct kk_src_metrics_Metrics_snapshot, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->counters = counters;
  _con->gauges = gauges;
  _con->histograms = histograms;
  _con->timestamp = timestamp;
  return kk_src_metrics__base_Metrics_snapshot(_con, _ctx);
}
static inline struct kk_src_metrics_Metrics_snapshot* kk_src_metrics__as_Metrics_snapshot(kk_src_metrics__metrics_snapshot x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_src_metrics_Metrics_snapshot*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_src_metrics__is_Metrics_snapshot(kk_src_metrics__metrics_snapshot x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_src_metrics__metrics_snapshot kk_src_metrics__metrics_snapshot_dup(kk_src_metrics__metrics_snapshot _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_src_metrics__metrics_snapshot_drop(kk_src_metrics__metrics_snapshot _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_src_metrics__metrics_snapshot_box(kk_src_metrics__metrics_snapshot _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_src_metrics__metrics_snapshot kk_src_metrics__metrics_snapshot_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `name` constructor field of the `:counter` type.

static inline kk_string_t kk_src_metrics_counter_fs_name(kk_src_metrics__counter counter, kk_context_t* _ctx) { /* (counter : counter) -> string */ 
  {
    struct kk_src_metrics_Counter* _con_x152 = kk_src_metrics__as_Counter(counter, _ctx);
    kk_string_t _x = _con_x152->name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `value` constructor field of the `:counter` type.

static inline int64_t kk_src_metrics_counter_fs_value(kk_src_metrics__counter counter, kk_context_t* _ctx) { /* (counter : counter) -> int64 */ 
  {
    struct kk_src_metrics_Counter* _con_x153 = kk_src_metrics__as_Counter(counter, _ctx);
    int64_t _x = _con_x153->value;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `help` constructor field of the `:counter` type.

static inline kk_string_t kk_src_metrics_counter_fs_help(kk_src_metrics__counter counter, kk_context_t* _ctx) { /* (counter : counter) -> string */ 
  {
    struct kk_src_metrics_Counter* _con_x154 = kk_src_metrics__as_Counter(counter, _ctx);
    kk_string_t _x = _con_x154->help;
    return kk_string_dup(_x, _ctx);
  }
}

kk_src_metrics__counter kk_src_metrics_counter_fs__copy(kk_src_metrics__counter _this, kk_std_core_types__optional name, kk_std_core_types__optional value, kk_std_core_types__optional help, kk_context_t* _ctx); /* (counter, name : ? string, value : ? int64, help : ? string) -> counter */ 
 
// Automatically generated. Retrieves the `name` constructor field of the `:gauge` type.

static inline kk_string_t kk_src_metrics_gauge_fs_name(kk_src_metrics__gauge gauge, kk_context_t* _ctx) { /* (gauge : gauge) -> string */ 
  {
    struct kk_src_metrics_Gauge* _con_x161 = kk_src_metrics__as_Gauge(gauge, _ctx);
    kk_string_t _x = _con_x161->name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `value` constructor field of the `:gauge` type.

static inline double kk_src_metrics_gauge_fs_value(kk_src_metrics__gauge gauge, kk_context_t* _ctx) { /* (gauge : gauge) -> float64 */ 
  {
    struct kk_src_metrics_Gauge* _con_x162 = kk_src_metrics__as_Gauge(gauge, _ctx);
    double _x = _con_x162->value;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `help` constructor field of the `:gauge` type.

static inline kk_string_t kk_src_metrics_gauge_fs_help(kk_src_metrics__gauge gauge, kk_context_t* _ctx) { /* (gauge : gauge) -> string */ 
  {
    struct kk_src_metrics_Gauge* _con_x163 = kk_src_metrics__as_Gauge(gauge, _ctx);
    kk_string_t _x = _con_x163->help;
    return kk_string_dup(_x, _ctx);
  }
}

kk_src_metrics__gauge kk_src_metrics_gauge_fs__copy(kk_src_metrics__gauge _this, kk_std_core_types__optional name, kk_std_core_types__optional value, kk_std_core_types__optional help, kk_context_t* _ctx); /* (gauge, name : ? string, value : ? float64, help : ? string) -> gauge */ 
 
// Automatically generated. Retrieves the `name` constructor field of the `:histogram` type.

static inline kk_string_t kk_src_metrics_histogram_fs_name(kk_src_metrics__histogram histogram, kk_context_t* _ctx) { /* (histogram : histogram) -> string */ 
  {
    struct kk_src_metrics_Histogram* _con_x170 = kk_src_metrics__as_Histogram(histogram, _ctx);
    kk_string_t _x = _con_x170->name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `buckets` constructor field of the `:histogram` type.

static inline kk_std_core_types__list kk_src_metrics_histogram_fs_buckets(kk_src_metrics__histogram histogram, kk_context_t* _ctx) { /* (histogram : histogram) -> list<(float64, int64)> */ 
  {
    struct kk_src_metrics_Histogram* _con_x171 = kk_src_metrics__as_Histogram(histogram, _ctx);
    kk_std_core_types__list _x = _con_x171->buckets;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `sum` constructor field of the `:histogram` type.

static inline double kk_src_metrics_histogram_fs_sum(kk_src_metrics__histogram histogram, kk_context_t* _ctx) { /* (histogram : histogram) -> float64 */ 
  {
    struct kk_src_metrics_Histogram* _con_x172 = kk_src_metrics__as_Histogram(histogram, _ctx);
    double _x = _con_x172->sum;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `count` constructor field of the `:histogram` type.

static inline int64_t kk_src_metrics_histogram_fs_count(kk_src_metrics__histogram histogram, kk_context_t* _ctx) { /* (histogram : histogram) -> int64 */ 
  {
    struct kk_src_metrics_Histogram* _con_x173 = kk_src_metrics__as_Histogram(histogram, _ctx);
    int64_t _x = _con_x173->count;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `help` constructor field of the `:histogram` type.

static inline kk_string_t kk_src_metrics_histogram_fs_help(kk_src_metrics__histogram histogram, kk_context_t* _ctx) { /* (histogram : histogram) -> string */ 
  {
    struct kk_src_metrics_Histogram* _con_x174 = kk_src_metrics__as_Histogram(histogram, _ctx);
    kk_string_t _x = _con_x174->help;
    return kk_string_dup(_x, _ctx);
  }
}

kk_src_metrics__histogram kk_src_metrics_histogram_fs__copy(kk_src_metrics__histogram _this, kk_std_core_types__optional name, kk_std_core_types__optional buckets, kk_std_core_types__optional sum, kk_std_core_types__optional count, kk_std_core_types__optional help, kk_context_t* _ctx); /* (histogram, name : ? string, buckets : ? (list<(float64, int64)>), sum : ? float64, count : ? int64, help : ? string) -> histogram */ 
 
// Automatically generated. Retrieves the `counters` constructor field of the `:metrics-snapshot` type.

static inline kk_std_core_types__list kk_src_metrics_metrics_snapshot_fs_counters(kk_src_metrics__metrics_snapshot _this, kk_context_t* _ctx) { /* (metrics-snapshot) -> list<counter> */ 
  {
    struct kk_src_metrics_Metrics_snapshot* _con_x185 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
    kk_std_core_types__list _x = _con_x185->counters;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `gauges` constructor field of the `:metrics-snapshot` type.

static inline kk_std_core_types__list kk_src_metrics_metrics_snapshot_fs_gauges(kk_src_metrics__metrics_snapshot _this, kk_context_t* _ctx) { /* (metrics-snapshot) -> list<gauge> */ 
  {
    struct kk_src_metrics_Metrics_snapshot* _con_x186 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
    kk_std_core_types__list _x = _con_x186->gauges;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `histograms` constructor field of the `:metrics-snapshot` type.

static inline kk_std_core_types__list kk_src_metrics_metrics_snapshot_fs_histograms(kk_src_metrics__metrics_snapshot _this, kk_context_t* _ctx) { /* (metrics-snapshot) -> list<histogram> */ 
  {
    struct kk_src_metrics_Metrics_snapshot* _con_x187 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
    kk_std_core_types__list _x = _con_x187->histograms;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `timestamp` constructor field of the `:metrics-snapshot` type.

static inline double kk_src_metrics_metrics_snapshot_fs_timestamp(kk_src_metrics__metrics_snapshot _this, kk_context_t* _ctx) { /* (metrics-snapshot) -> float64 */ 
  {
    struct kk_src_metrics_Metrics_snapshot* _con_x188 = kk_src_metrics__as_Metrics_snapshot(_this, _ctx);
    double _x = _con_x188->timestamp;
    return _x;
  }
}

kk_src_metrics__metrics_snapshot kk_src_metrics_metrics_snapshot_fs__copy(kk_src_metrics__metrics_snapshot _this, kk_std_core_types__optional counters, kk_std_core_types__optional gauges, kk_std_core_types__optional histograms, kk_std_core_types__optional timestamp, kk_context_t* _ctx); /* (metrics-snapshot, counters : ? (list<counter>), gauges : ? (list<gauge>), histograms : ? (list<histogram>), timestamp : ? float64) -> metrics-snapshot */ 

kk_src_metrics__counter kk_src_metrics_increment(kk_src_metrics__counter c, kk_context_t* _ctx); /* (c : counter) -> counter */ 

kk_src_metrics__counter kk_src_metrics_add(kk_src_metrics__counter c, kk_integer_t n, kk_context_t* _ctx); /* (c : counter, n : int) -> counter */ 

kk_src_metrics__gauge kk_src_metrics_set(kk_src_metrics__gauge g, double v, kk_context_t* _ctx); /* (g : gauge, v : float64) -> gauge */ 

kk_src_metrics__histogram kk_src_metrics_observe(kk_src_metrics__histogram h, double v, kk_context_t* _ctx); /* (h : histogram, v : float64) -> histogram */ 

kk_string_t kk_src_metrics_export_counter(kk_src_metrics__counter c, kk_context_t* _ctx); /* (c : counter) -> string */ 

kk_string_t kk_src_metrics_export_gauge(kk_src_metrics__gauge g, kk_context_t* _ctx); /* (g : gauge) -> string */ 

kk_string_t kk_src_metrics_list_fs_join(kk_std_core_types__list xs, kk_string_t sep, kk_context_t* _ctx); /* (xs : list<string>, sep : string) -> string */ 

kk_string_t kk_src_metrics_export_histogram(kk_src_metrics__histogram h, kk_context_t* _ctx); /* (h : histogram) -> string */ 

kk_string_t kk_src_metrics_export_all(kk_src_metrics__metrics_snapshot snapshot, kk_context_t* _ctx); /* (snapshot : metrics-snapshot) -> string */ 

kk_src_metrics__metrics_snapshot kk_src_metrics_standard_ipc_metrics(kk_string_t binary_name, kk_context_t* _ctx); /* (binary-name : string) -> metrics-snapshot */ 

void kk_src_metrics__init(kk_context_t* _ctx);


void kk_src_metrics__done(kk_context_t* _ctx);

#endif // header
