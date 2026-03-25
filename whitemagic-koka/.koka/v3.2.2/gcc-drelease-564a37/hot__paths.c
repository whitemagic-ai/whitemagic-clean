// Koka generated module: hot_paths, koka version: 3.2.2, platform: 64-bit
#include "hot__paths.h"

kk_hot__paths__path_profile kk_hot__paths_path_profile_fs__copy(kk_hot__paths__path_profile _this, kk_std_core_types__optional name, kk_std_core_types__optional call_count, kk_std_core_types__optional total_time_ms, kk_std_core_types__optional avg_time_ms, kk_std_core_types__optional complexity, kk_std_core_types__optional category, kk_context_t* _ctx) { /* (path-profile, name : ? string, call-count : ? int, total-time-ms : ? float64, avg-time-ms : ? float64, complexity : ? complexity, category : ? path-category) -> path-profile */ 
  kk_string_t _x_x102;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x0 = name._cons._Optional.value;
    kk_string_t _uniq_name_162 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_name_162, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x102 = _uniq_name_162; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_hot__paths_Path_profile* _con_x103 = kk_hot__paths__as_Path_profile(_this, _ctx);
      kk_string_t _x = _con_x103->name;
      kk_string_dup(_x, _ctx);
      _x_x102 = _x; /*string*/
    }
  }
  kk_integer_t _x_x104;
  if (kk_std_core_types__is_Optional(call_count, _ctx)) {
    kk_box_t _box_x1 = call_count._cons._Optional.value;
    kk_integer_t _uniq_call_count_170 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_call_count_170, _ctx);
    kk_std_core_types__optional_drop(call_count, _ctx);
    _x_x104 = _uniq_call_count_170; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(call_count, _ctx);
    {
      struct kk_hot__paths_Path_profile* _con_x105 = kk_hot__paths__as_Path_profile(_this, _ctx);
      kk_integer_t _x_0 = _con_x105->call_count;
      kk_integer_dup(_x_0, _ctx);
      _x_x104 = _x_0; /*int*/
    }
  }
  double _x_x106;
  if (kk_std_core_types__is_Optional(total_time_ms, _ctx)) {
    kk_box_t _box_x2 = total_time_ms._cons._Optional.value;
    double _uniq_total_time_ms_178 = kk_double_unbox(_box_x2, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    _x_x106 = _uniq_total_time_ms_178; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    {
      struct kk_hot__paths_Path_profile* _con_x107 = kk_hot__paths__as_Path_profile(_this, _ctx);
      double _x_1 = _con_x107->total_time_ms;
      _x_x106 = _x_1; /*float64*/
    }
  }
  double _x_x108;
  if (kk_std_core_types__is_Optional(avg_time_ms, _ctx)) {
    kk_box_t _box_x3 = avg_time_ms._cons._Optional.value;
    double _uniq_avg_time_ms_186 = kk_double_unbox(_box_x3, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(avg_time_ms, _ctx);
    _x_x108 = _uniq_avg_time_ms_186; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(avg_time_ms, _ctx);
    {
      struct kk_hot__paths_Path_profile* _con_x109 = kk_hot__paths__as_Path_profile(_this, _ctx);
      double _x_2 = _con_x109->avg_time_ms;
      _x_x108 = _x_2; /*float64*/
    }
  }
  kk_hot__paths__complexity _x_x110;
  if (kk_std_core_types__is_Optional(complexity, _ctx)) {
    kk_box_t _box_x4 = complexity._cons._Optional.value;
    kk_hot__paths__complexity _uniq_complexity_194 = kk_hot__paths__complexity_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(complexity, _ctx);
    _x_x110 = _uniq_complexity_194; /*hot_paths/complexity*/
  }
  else {
    kk_std_core_types__optional_drop(complexity, _ctx);
    {
      struct kk_hot__paths_Path_profile* _con_x111 = kk_hot__paths__as_Path_profile(_this, _ctx);
      kk_hot__paths__complexity _x_3 = _con_x111->complexity;
      _x_x110 = _x_3; /*hot_paths/complexity*/
    }
  }
  kk_hot__paths__path_category _x_x112;
  if (kk_std_core_types__is_Optional(category, _ctx)) {
    kk_box_t _box_x5 = category._cons._Optional.value;
    kk_hot__paths__path_category _uniq_category_202 = kk_hot__paths__path_category_unbox(_box_x5, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(category, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x112 = _uniq_category_202; /*hot_paths/path-category*/
  }
  else {
    kk_std_core_types__optional_drop(category, _ctx);
    {
      struct kk_hot__paths_Path_profile* _con_x113 = kk_hot__paths__as_Path_profile(_this, _ctx);
      kk_string_t _pat_0_5 = _con_x113->name;
      kk_integer_t _pat_1_6 = _con_x113->call_count;
      kk_hot__paths__path_category _x_4 = _con_x113->category;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_6, _ctx);
        kk_string_drop(_pat_0_5, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x112 = _x_4; /*hot_paths/path-category*/
    }
  }
  return kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x102, _x_x104, _x_x106, _x_x108, _x_x110, _x_x112, _ctx);
}

kk_hot__paths__profiling_session kk_hot__paths_profiling_session_fs__copy(kk_hot__paths__profiling_session _this, kk_std_core_types__optional paths, kk_std_core_types__optional total_calls, kk_std_core_types__optional total_time_ms, kk_std_core_types__optional hot_threshold_ms, kk_context_t* _ctx) { /* (profiling-session, paths : ? (list<path-profile>), total-calls : ? int, total-time-ms : ? float64, hot-threshold-ms : ? float64) -> profiling-session */ 
  kk_std_core_types__list _x_x118;
  if (kk_std_core_types__is_Optional(paths, _ctx)) {
    kk_box_t _box_x6 = paths._cons._Optional.value;
    kk_std_core_types__list _uniq_paths_255 = kk_std_core_types__list_unbox(_box_x6, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_paths_255, _ctx);
    kk_std_core_types__optional_drop(paths, _ctx);
    _x_x118 = _uniq_paths_255; /*list<hot_paths/path-profile>*/
  }
  else {
    kk_std_core_types__optional_drop(paths, _ctx);
    {
      struct kk_hot__paths_Profiling_session* _con_x119 = kk_hot__paths__as_Profiling_session(_this, _ctx);
      kk_std_core_types__list _x = _con_x119->paths;
      kk_std_core_types__list_dup(_x, _ctx);
      _x_x118 = _x; /*list<hot_paths/path-profile>*/
    }
  }
  kk_integer_t _x_x120;
  if (kk_std_core_types__is_Optional(total_calls, _ctx)) {
    kk_box_t _box_x7 = total_calls._cons._Optional.value;
    kk_integer_t _uniq_total_calls_263 = kk_integer_unbox(_box_x7, _ctx);
    kk_integer_dup(_uniq_total_calls_263, _ctx);
    kk_std_core_types__optional_drop(total_calls, _ctx);
    _x_x120 = _uniq_total_calls_263; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(total_calls, _ctx);
    {
      struct kk_hot__paths_Profiling_session* _con_x121 = kk_hot__paths__as_Profiling_session(_this, _ctx);
      kk_integer_t _x_0 = _con_x121->total_calls;
      kk_integer_dup(_x_0, _ctx);
      _x_x120 = _x_0; /*int*/
    }
  }
  double _x_x122;
  if (kk_std_core_types__is_Optional(total_time_ms, _ctx)) {
    kk_box_t _box_x8 = total_time_ms._cons._Optional.value;
    double _uniq_total_time_ms_271 = kk_double_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    _x_x122 = _uniq_total_time_ms_271; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    {
      struct kk_hot__paths_Profiling_session* _con_x123 = kk_hot__paths__as_Profiling_session(_this, _ctx);
      double _x_1 = _con_x123->total_time_ms;
      _x_x122 = _x_1; /*float64*/
    }
  }
  double _x_x124;
  if (kk_std_core_types__is_Optional(hot_threshold_ms, _ctx)) {
    kk_box_t _box_x9 = hot_threshold_ms._cons._Optional.value;
    double _uniq_hot_threshold_ms_279 = kk_double_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(hot_threshold_ms, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x124 = _uniq_hot_threshold_ms_279; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(hot_threshold_ms, _ctx);
    {
      struct kk_hot__paths_Profiling_session* _con_x125 = kk_hot__paths__as_Profiling_session(_this, _ctx);
      kk_std_core_types__list _pat_0_3 = _con_x125->paths;
      kk_integer_t _pat_1_4 = _con_x125->total_calls;
      double _x_2 = _con_x125->hot_threshold_ms;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_4, _ctx);
        kk_std_core_types__list_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x124 = _x_2; /*float64*/
    }
  }
  return kk_hot__paths__new_Profiling_session(kk_reuse_null, 0, _x_x118, _x_x120, _x_x122, _x_x124, _ctx);
}

kk_hot__paths__complexity kk_hot__paths_estimate_complexity(double avg_time_ms, kk_integer_t call_count, kk_context_t* _ctx) { /* (avg-time-ms : float64, call-count : int) -> complexity */ 
  bool _match_x83 = kk_integer_gt_borrow(call_count,(kk_integer_from_small(100)),kk_context()); /*bool*/;
  if (_match_x83) {
    bool _match_x87 = (avg_time_ms > (0x1.4p3)); /*bool*/;
    if (_match_x87) {
      kk_integer_drop(call_count, _ctx);
      return kk_hot__paths__new_High(_ctx);
    }
    {
      bool _match_x88;
      bool _brw_x90 = kk_integer_gt_borrow(call_count,(kk_integer_from_small(10)),kk_context()); /*bool*/;
      kk_integer_drop(call_count, _ctx);
      _match_x88 = _brw_x90; /*bool*/
      if (_match_x88) {
        return kk_hot__paths__new_Medium(_ctx);
      }
      {
        bool _match_x89 = (avg_time_ms > (0x1.4p2)); /*bool*/;
        if (_match_x89) {
          return kk_hot__paths__new_Medium(_ctx);
        }
        {
          return kk_hot__paths__new_Low(_ctx);
        }
      }
    }
  }
  {
    bool _match_x84;
    bool _brw_x86 = kk_integer_gt_borrow(call_count,(kk_integer_from_small(10)),kk_context()); /*bool*/;
    kk_integer_drop(call_count, _ctx);
    _match_x84 = _brw_x86; /*bool*/
    if (_match_x84) {
      return kk_hot__paths__new_Medium(_ctx);
    }
    {
      bool _match_x85 = (avg_time_ms > (0x1.4p2)); /*bool*/;
      if (_match_x85) {
        return kk_hot__paths__new_Medium(_ctx);
      }
      {
        return kk_hot__paths__new_Low(_ctx);
      }
    }
  }
}

kk_hot__paths__path_category kk_hot__paths_estimate_category(kk_string_t name, kk_context_t* _ctx) { /* (name : string) -> path-category */ 
  bool _match_x74;
  kk_string_t _x_x133 = kk_string_dup(name, _ctx); /*string*/
  kk_string_t _x_x134;
  kk_define_string_literal(, _s_x135, 5, "embed", _ctx)
  _x_x134 = kk_string_dup(_s_x135, _ctx); /*string*/
  _match_x74 = kk_string_contains(_x_x133,_x_x134,kk_context()); /*bool*/
  if (_match_x74) {
    kk_string_drop(name, _ctx);
    return kk_hot__paths__new_Compute(_ctx);
  }
  {
    bool _match_x75;
    kk_string_t _x_x136 = kk_string_dup(name, _ctx); /*string*/
    kk_string_t _x_x137;
    kk_define_string_literal(, _s_x138, 6, "vector", _ctx)
    _x_x137 = kk_string_dup(_s_x138, _ctx); /*string*/
    _match_x75 = kk_string_contains(_x_x136,_x_x137,kk_context()); /*bool*/
    if (_match_x75) {
      kk_string_drop(name, _ctx);
      return kk_hot__paths__new_Compute(_ctx);
    }
    {
      bool _match_x76;
      kk_string_t _x_x139 = kk_string_dup(name, _ctx); /*string*/
      kk_string_t _x_x140;
      kk_define_string_literal(, _s_x141, 7, "compute", _ctx)
      _x_x140 = kk_string_dup(_s_x141, _ctx); /*string*/
      _match_x76 = kk_string_contains(_x_x139,_x_x140,kk_context()); /*bool*/
      if (_match_x76) {
        kk_string_drop(name, _ctx);
        return kk_hot__paths__new_Compute(_ctx);
      }
      {
        bool _match_x77;
        kk_string_t _x_x142 = kk_string_dup(name, _ctx); /*string*/
        kk_string_t _x_x143;
        kk_define_string_literal(, _s_x144, 6, "memory", _ctx)
        _x_x143 = kk_string_dup(_s_x144, _ctx); /*string*/
        _match_x77 = kk_string_contains(_x_x142,_x_x143,kk_context()); /*bool*/
        if (_match_x77) {
          kk_string_drop(name, _ctx);
          return kk_hot__paths__new_Memory(_ctx);
        }
        {
          bool _match_x78;
          kk_string_t _x_x145 = kk_string_dup(name, _ctx); /*string*/
          kk_string_t _x_x146;
          kk_define_string_literal(, _s_x147, 5, "cache", _ctx)
          _x_x146 = kk_string_dup(_s_x147, _ctx); /*string*/
          _match_x78 = kk_string_contains(_x_x145,_x_x146,kk_context()); /*bool*/
          if (_match_x78) {
            kk_string_drop(name, _ctx);
            return kk_hot__paths__new_Memory(_ctx);
          }
          {
            bool _match_x79;
            kk_string_t _x_x148 = kk_string_dup(name, _ctx); /*string*/
            kk_string_t _x_x149;
            kk_define_string_literal(, _s_x150, 5, "store", _ctx)
            _x_x149 = kk_string_dup(_s_x150, _ctx); /*string*/
            _match_x79 = kk_string_contains(_x_x148,_x_x149,kk_context()); /*bool*/
            if (_match_x79) {
              kk_string_drop(name, _ctx);
              return kk_hot__paths__new_Memory(_ctx);
            }
            {
              bool _match_x80;
              kk_string_t _x_x151 = kk_string_dup(name, _ctx); /*string*/
              kk_string_t _x_x152;
              kk_define_string_literal(, _s_x153, 4, "read", _ctx)
              _x_x152 = kk_string_dup(_s_x153, _ctx); /*string*/
              _match_x80 = kk_string_contains(_x_x151,_x_x152,kk_context()); /*bool*/
              if (_match_x80) {
                kk_string_drop(name, _ctx);
                return kk_hot__paths__new_IO(_ctx);
              }
              {
                bool _match_x81;
                kk_string_t _x_x154 = kk_string_dup(name, _ctx); /*string*/
                kk_string_t _x_x155;
                kk_define_string_literal(, _s_x156, 5, "write", _ctx)
                _x_x155 = kk_string_dup(_s_x156, _ctx); /*string*/
                _match_x81 = kk_string_contains(_x_x154,_x_x155,kk_context()); /*bool*/
                if (_match_x81) {
                  kk_string_drop(name, _ctx);
                  return kk_hot__paths__new_IO(_ctx);
                }
                {
                  bool _match_x82;
                  kk_string_t _x_x157;
                  kk_define_string_literal(, _s_x158, 4, "load", _ctx)
                  _x_x157 = kk_string_dup(_s_x158, _ctx); /*string*/
                  _match_x82 = kk_string_contains(name,_x_x157,kk_context()); /*bool*/
                  if (_match_x82) {
                    return kk_hot__paths__new_IO(_ctx);
                  }
                  {
                    return kk_hot__paths__new_Mixed(_ctx);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

kk_hot__paths__path_profile kk_hot__paths_create_profile(kk_string_t name, double time_ms, kk_context_t* _ctx) { /* (name : string, time-ms : float64) -> path-profile */ 
  kk_string_t _x_x159 = kk_string_dup(name, _ctx); /*string*/
  kk_hot__paths__complexity _x_x160;
  bool _match_x68 = kk_integer_gt_borrow((kk_integer_from_small(1)),(kk_integer_from_small(100)),kk_context()); /*bool*/;
  if (_match_x68) {
    bool _match_x71 = (time_ms > (0x1.4p3)); /*bool*/;
    if (_match_x71) {
      _x_x160 = kk_hot__paths__new_High(_ctx); /*hot_paths/complexity*/
    }
    else {
      bool _match_x72 = kk_integer_gt_borrow((kk_integer_from_small(1)),(kk_integer_from_small(10)),kk_context()); /*bool*/;
      if (_match_x72) {
        _x_x160 = kk_hot__paths__new_Medium(_ctx); /*hot_paths/complexity*/
      }
      else {
        bool _match_x73 = (time_ms > (0x1.4p2)); /*bool*/;
        if (_match_x73) {
          _x_x160 = kk_hot__paths__new_Medium(_ctx); /*hot_paths/complexity*/
        }
        else {
          _x_x160 = kk_hot__paths__new_Low(_ctx); /*hot_paths/complexity*/
        }
      }
    }
  }
  else {
    bool _match_x69 = kk_integer_gt_borrow((kk_integer_from_small(1)),(kk_integer_from_small(10)),kk_context()); /*bool*/;
    if (_match_x69) {
      _x_x160 = kk_hot__paths__new_Medium(_ctx); /*hot_paths/complexity*/
    }
    else {
      bool _match_x70 = (time_ms > (0x1.4p2)); /*bool*/;
      if (_match_x70) {
        _x_x160 = kk_hot__paths__new_Medium(_ctx); /*hot_paths/complexity*/
      }
      else {
        _x_x160 = kk_hot__paths__new_Low(_ctx); /*hot_paths/complexity*/
      }
    }
  }
  kk_hot__paths__path_category _x_x161 = kk_hot__paths_estimate_category(name, _ctx); /*hot_paths/path-category*/
  return kk_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x159, kk_integer_from_small(1), time_ms, time_ms, _x_x160, _x_x161, _ctx);
}

kk_string_t kk_hot__paths_json_profile(kk_hot__paths__path_profile p, kk_context_t* _ctx) { /* (p : path-profile) -> string */ 
  kk_string_t _x_x162;
  kk_define_string_literal(, _s_x163, 9, "{\"name\":\"", _ctx)
  _x_x162 = kk_string_dup(_s_x163, _ctx); /*string*/
  kk_string_t _x_x164;
  kk_string_t _x_x165;
  {
    struct kk_hot__paths_Path_profile* _con_x166 = kk_hot__paths__as_Path_profile(p, _ctx);
    kk_string_t _x = _con_x166->name;
    kk_string_dup(_x, _ctx);
    _x_x165 = _x; /*string*/
  }
  kk_string_t _x_x167;
  kk_string_t _x_x168;
  kk_define_string_literal(, _s_x169, 10, "\",\"calls\":", _ctx)
  _x_x168 = kk_string_dup(_s_x169, _ctx); /*string*/
  kk_string_t _x_x170;
  kk_string_t _x_x171;
  kk_integer_t _x_x172;
  {
    struct kk_hot__paths_Path_profile* _con_x173 = kk_hot__paths__as_Path_profile(p, _ctx);
    kk_integer_t _x_0 = _con_x173->call_count;
    kk_integer_dup(_x_0, _ctx);
    _x_x172 = _x_0; /*int*/
  }
  _x_x171 = kk_std_core_int_show(_x_x172, _ctx); /*string*/
  kk_string_t _x_x174;
  kk_string_t _x_x175;
  kk_define_string_literal(, _s_x176, 10, ",\"avg_ms\":", _ctx)
  _x_x175 = kk_string_dup(_s_x176, _ctx); /*string*/
  kk_string_t _x_x177;
  kk_string_t _x_x178;
  double _x_x179;
  {
    struct kk_hot__paths_Path_profile* _con_x180 = kk_hot__paths__as_Path_profile(p, _ctx);
    double _x_1 = _con_x180->avg_time_ms;
    _x_x179 = _x_1; /*float64*/
  }
  _x_x178 = kk_std_num_float64_show(_x_x179, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x181;
  kk_string_t _x_x182;
  kk_define_string_literal(, _s_x183, 15, ",\"complexity\":\"", _ctx)
  _x_x182 = kk_string_dup(_s_x183, _ctx); /*string*/
  kk_string_t _x_x184;
  kk_string_t _x_x185;
  {
    struct kk_hot__paths_Path_profile* _con_x186 = kk_hot__paths__as_Path_profile(p, _ctx);
    kk_hot__paths__complexity _x_2 = _con_x186->complexity;
    if (kk_hot__paths__is_Low(_x_2, _ctx)) {
      kk_define_string_literal(, _s_x188, 3, "low", _ctx)
      _x_x185 = kk_string_dup(_s_x188, _ctx); /*string*/
      goto _match_x187;
    }
    if (kk_hot__paths__is_Medium(_x_2, _ctx)) {
      kk_define_string_literal(, _s_x189, 6, "medium", _ctx)
      _x_x185 = kk_string_dup(_s_x189, _ctx); /*string*/
      goto _match_x187;
    }
    {
      kk_define_string_literal(, _s_x190, 4, "high", _ctx)
      _x_x185 = kk_string_dup(_s_x190, _ctx); /*string*/
    }
    _match_x187: ;
  }
  kk_string_t _x_x191;
  kk_string_t _x_x192;
  kk_define_string_literal(, _s_x193, 1, "\"", _ctx)
  _x_x192 = kk_string_dup(_s_x193, _ctx); /*string*/
  kk_string_t _x_x194;
  kk_string_t _x_x195;
  kk_define_string_literal(, _s_x196, 13, ",\"category\":\"", _ctx)
  _x_x195 = kk_string_dup(_s_x196, _ctx); /*string*/
  kk_string_t _x_x197;
  kk_string_t _x_x198;
  {
    struct kk_hot__paths_Path_profile* _con_x199 = kk_hot__paths__as_Path_profile(p, _ctx);
    kk_string_t _pat_0_5 = _con_x199->name;
    kk_integer_t _pat_1_5 = _con_x199->call_count;
    kk_hot__paths__path_category _x_3 = _con_x199->category;
    if kk_likely(kk_datatype_ptr_is_unique(p, _ctx)) {
      kk_integer_drop(_pat_1_5, _ctx);
      kk_string_drop(_pat_0_5, _ctx);
      kk_datatype_ptr_free(p, _ctx);
    }
    else {
      kk_datatype_ptr_decref(p, _ctx);
    }
    if (kk_hot__paths__is_Compute(_x_3, _ctx)) {
      kk_define_string_literal(, _s_x201, 7, "compute", _ctx)
      _x_x198 = kk_string_dup(_s_x201, _ctx); /*string*/
      goto _match_x200;
    }
    if (kk_hot__paths__is_Memory(_x_3, _ctx)) {
      kk_define_string_literal(, _s_x202, 6, "memory", _ctx)
      _x_x198 = kk_string_dup(_s_x202, _ctx); /*string*/
      goto _match_x200;
    }
    if (kk_hot__paths__is_IO(_x_3, _ctx)) {
      kk_define_string_literal(, _s_x203, 2, "io", _ctx)
      _x_x198 = kk_string_dup(_s_x203, _ctx); /*string*/
      goto _match_x200;
    }
    {
      kk_define_string_literal(, _s_x204, 5, "mixed", _ctx)
      _x_x198 = kk_string_dup(_s_x204, _ctx); /*string*/
    }
    _match_x200: ;
  }
  kk_string_t _x_x205;
  kk_define_string_literal(, _s_x206, 2, "\"}", _ctx)
  _x_x205 = kk_string_dup(_s_x206, _ctx); /*string*/
  _x_x197 = kk_std_core_types__lp__plus__plus__rp_(_x_x198, _x_x205, _ctx); /*string*/
  _x_x194 = kk_std_core_types__lp__plus__plus__rp_(_x_x195, _x_x197, _ctx); /*string*/
  _x_x191 = kk_std_core_types__lp__plus__plus__rp_(_x_x192, _x_x194, _ctx); /*string*/
  _x_x184 = kk_std_core_types__lp__plus__plus__rp_(_x_x185, _x_x191, _ctx); /*string*/
  _x_x181 = kk_std_core_types__lp__plus__plus__rp_(_x_x182, _x_x184, _ctx); /*string*/
  _x_x177 = kk_std_core_types__lp__plus__plus__rp_(_x_x178, _x_x181, _ctx); /*string*/
  _x_x174 = kk_std_core_types__lp__plus__plus__rp_(_x_x175, _x_x177, _ctx); /*string*/
  _x_x170 = kk_std_core_types__lp__plus__plus__rp_(_x_x171, _x_x174, _ctx); /*string*/
  _x_x167 = kk_std_core_types__lp__plus__plus__rp_(_x_x168, _x_x170, _ctx); /*string*/
  _x_x164 = kk_std_core_types__lp__plus__plus__rp_(_x_x165, _x_x167, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x162, _x_x164, _ctx);
}

kk_string_t kk_hot__paths_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x63;
  kk_string_t _x_x207 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x208;
  kk_define_string_literal(, _s_x209, 8, "\"record\"", _ctx)
  _x_x208 = kk_string_dup(_s_x209, _ctx); /*string*/
  _match_x63 = kk_string_contains(_x_x207,_x_x208,kk_context()); /*bool*/
  if (_match_x63) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x210, 6, "record", _ctx)
    return kk_string_dup(_s_x210, _ctx);
  }
  {
    bool _match_x64;
    kk_string_t _x_x211 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x212;
    kk_define_string_literal(, _s_x213, 9, "\"profile\"", _ctx)
    _x_x212 = kk_string_dup(_s_x213, _ctx); /*string*/
    _match_x64 = kk_string_contains(_x_x211,_x_x212,kk_context()); /*bool*/
    if (_match_x64) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x214, 7, "profile", _ctx)
      return kk_string_dup(_s_x214, _ctx);
    }
    {
      bool _match_x65;
      kk_string_t _x_x215 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x216;
      kk_define_string_literal(, _s_x217, 5, "\"hot\"", _ctx)
      _x_x216 = kk_string_dup(_s_x217, _ctx); /*string*/
      _match_x65 = kk_string_contains(_x_x215,_x_x216,kk_context()); /*bool*/
      if (_match_x65) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x218, 3, "hot", _ctx)
        return kk_string_dup(_s_x218, _ctx);
      }
      {
        bool _match_x66;
        kk_string_t _x_x219 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x220;
        kk_define_string_literal(, _s_x221, 8, "\"status\"", _ctx)
        _x_x220 = kk_string_dup(_s_x221, _ctx); /*string*/
        _match_x66 = kk_string_contains(_x_x219,_x_x220,kk_context()); /*bool*/
        if (_match_x66) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x222, 6, "status", _ctx)
          return kk_string_dup(_s_x222, _ctx);
        }
        {
          bool _match_x67;
          kk_string_t _x_x223;
          kk_define_string_literal(, _s_x224, 6, "\"quit\"", _ctx)
          _x_x223 = kk_string_dup(_s_x224, _ctx); /*string*/
          _match_x67 = kk_string_contains(line,_x_x223,kk_context()); /*bool*/
          if (_match_x67) {
            kk_define_string_literal(, _s_x225, 4, "quit", _ctx)
            return kk_string_dup(_s_x225, _ctx);
          }
          {
            kk_define_string_literal(, _s_x226, 7, "unknown", _ctx)
            return kk_string_dup(_s_x226, _ctx);
          }
        }
      }
    }
  }
}

kk_string_t kk_hot__paths_extract_name(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x59;
  kk_string_t _x_x227 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x228;
  kk_define_string_literal(, _s_x229, 5, "embed", _ctx)
  _x_x228 = kk_string_dup(_s_x229, _ctx); /*string*/
  _match_x59 = kk_string_contains(_x_x227,_x_x228,kk_context()); /*bool*/
  if (_match_x59) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x230, 12, "embedding_op", _ctx)
    return kk_string_dup(_s_x230, _ctx);
  }
  {
    bool _match_x60;
    kk_string_t _x_x231 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x232;
    kk_define_string_literal(, _s_x233, 7, "compute", _ctx)
    _x_x232 = kk_string_dup(_s_x233, _ctx); /*string*/
    _match_x60 = kk_string_contains(_x_x231,_x_x232,kk_context()); /*bool*/
    if (_match_x60) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x234, 10, "compute_op", _ctx)
      return kk_string_dup(_s_x234, _ctx);
    }
    {
      bool _match_x61;
      kk_string_t _x_x235 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x236;
      kk_define_string_literal(, _s_x237, 6, "memory", _ctx)
      _x_x236 = kk_string_dup(_s_x237, _ctx); /*string*/
      _match_x61 = kk_string_contains(_x_x235,_x_x236,kk_context()); /*bool*/
      if (_match_x61) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x238, 9, "memory_op", _ctx)
        return kk_string_dup(_s_x238, _ctx);
      }
      {
        bool _match_x62;
        kk_string_t _x_x239;
        kk_define_string_literal(, _s_x240, 6, "vector", _ctx)
        _x_x239 = kk_string_dup(_s_x240, _ctx); /*string*/
        _match_x62 = kk_string_contains(line,_x_x239,kk_context()); /*bool*/
        if (_match_x62) {
          kk_define_string_literal(, _s_x241, 9, "vector_op", _ctx)
          return kk_string_dup(_s_x241, _ctx);
        }
        {
          kk_define_string_literal(, _s_x242, 10, "unknown_op", _ctx)
          return kk_string_dup(_s_x242, _ctx);
        }
      }
    }
  }
}
 
// monadic lift

kk_unit_t kk_hot__paths__mlift_server_loop_10136(kk_string_t op, kk_std_core_types__list profiles, kk_integer_t total_calls, double total_time, kk_string_t _c_x10120, kk_context_t* _ctx) { /* (op : string, profiles : list<path-profile>, total-calls : int, total-time : float64, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10120, _ctx);
  bool _match_x58;
  kk_string_t _x_x243;
  kk_define_string_literal(, _s_x244, 4, "quit", _ctx)
  _x_x243 = kk_string_dup(_s_x244, _ctx); /*string*/
  _match_x58 = kk_string_is_neq(op,_x_x243,kk_context()); /*bool*/
  if (_match_x58) {
    kk_integer_t _x_x245 = kk_integer_add_small_const(total_calls, 1, _ctx); /*int*/
    double _x_x246 = (total_time + 0x1p0); /*float64*/
    kk_hot__paths_server_loop(_x_x245, _x_x246, profiles, _ctx); return kk_Unit;
  }
  {
    kk_integer_drop(total_calls, _ctx);
    kk_std_core_types__list_drop(profiles, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_hot__paths__mlift_server_loop_10137_fun251__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hot__paths__mlift_server_loop_10137_fun251(kk_function_t _fself, kk_box_t _b_x12, kk_context_t* _ctx);
static kk_function_t kk_hot__paths__new_mlift_server_loop_10137_fun251(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hot__paths__mlift_server_loop_10137_fun251, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_hot__paths__mlift_server_loop_10137_fun251(kk_function_t _fself, kk_box_t _b_x12, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x252;
  kk_string_t _x_x253 = kk_string_unbox(_b_x12); /*string*/
  _x_x252 = kk_hot__paths_extract_op(_x_x253, _ctx); /*string*/
  return kk_string_box(_x_x252);
}


// lift anonymous function
struct kk_hot__paths__mlift_server_loop_10137_fun258__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hot__paths__mlift_server_loop_10137_fun258(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_hot__paths__new_mlift_server_loop_10137_fun258(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hot__paths__mlift_server_loop_10137_fun258, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_hot__paths__mlift_server_loop_10137_fun258(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x259;
  kk_string_t _x_x260 = kk_string_unbox(_b_x17); /*string*/
  _x_x259 = kk_hot__paths_extract_name(_x_x260, _ctx); /*string*/
  return kk_string_box(_x_x259);
}


// lift anonymous function
struct kk_hot__paths__mlift_server_loop_10137_fun267__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hot__paths__mlift_server_loop_10137_fun267(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static kk_function_t kk_hot__paths__new_mlift_server_loop_10137_fun267(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hot__paths__mlift_server_loop_10137_fun267, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_hot__paths__mlift_server_loop_10137_fun267(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x268;
  kk_string_t _x_x269 = kk_string_unbox(_b_x22); /*string*/
  _x_x268 = kk_hot__paths_extract_name(_x_x269, _ctx); /*string*/
  return kk_string_box(_x_x268);
}


// lift anonymous function
struct kk_hot__paths__mlift_server_loop_10137_fun290__t {
  struct kk_function_s _base;
  kk_string_t op_0;
  kk_std_core_types__list profiles_0;
  kk_integer_t total_calls_0;
  double total_time_0;
};
static kk_box_t kk_hot__paths__mlift_server_loop_10137_fun290(kk_function_t _fself, kk_box_t _b_x26, kk_context_t* _ctx);
static kk_function_t kk_hot__paths__new_mlift_server_loop_10137_fun290(kk_string_t op_0, kk_std_core_types__list profiles_0, kk_integer_t total_calls_0, double total_time_0, kk_context_t* _ctx) {
  struct kk_hot__paths__mlift_server_loop_10137_fun290__t* _self = kk_function_alloc_as(struct kk_hot__paths__mlift_server_loop_10137_fun290__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hot__paths__mlift_server_loop_10137_fun290, kk_context());
  _self->op_0 = op_0;
  _self->profiles_0 = profiles_0;
  _self->total_calls_0 = total_calls_0;
  _self->total_time_0 = total_time_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hot__paths__mlift_server_loop_10137_fun290(kk_function_t _fself, kk_box_t _b_x26, kk_context_t* _ctx) {
  struct kk_hot__paths__mlift_server_loop_10137_fun290__t* _self = kk_function_as(struct kk_hot__paths__mlift_server_loop_10137_fun290__t*, _fself, _ctx);
  kk_string_t op_0 = _self->op_0; /* string */
  kk_std_core_types__list profiles_0 = _self->profiles_0; /* list<hot_paths/path-profile> */
  kk_integer_t total_calls_0 = _self->total_calls_0; /* int */
  double total_time_0 = _self->total_time_0; /* float64 */
  kk_drop_match(_self, {kk_string_dup(op_0, _ctx);kk_std_core_types__list_dup(profiles_0, _ctx);kk_integer_dup(total_calls_0, _ctx);kk_skip_dup(total_time_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10120_0_28 = kk_string_unbox(_b_x26); /*string*/;
  kk_unit_t _x_x291 = kk_Unit;
  kk_hot__paths__mlift_server_loop_10136(op_0, profiles_0, total_calls_0, total_time_0, _c_x10120_0_28, _ctx);
  return kk_unit_box(_x_x291);
}

kk_unit_t kk_hot__paths__mlift_server_loop_10137(kk_std_core_types__list profiles_0, kk_integer_t total_calls_0, double total_time_0, kk_string_t line, kk_context_t* _ctx) { /* (profiles : list<path-profile>, total-calls : int, total-time : float64, line : string) -> <console/console,exn> () */ 
  bool _match_x56;
  kk_string_t _x_x247 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x248 = kk_string_empty(); /*string*/
  _match_x56 = kk_string_is_neq(_x_x247,_x_x248,kk_context()); /*bool*/
  if (_match_x56) {
    kk_string_t op_0;
    kk_box_t _x_x250;
    kk_box_t _x_x254;
    kk_string_t _x_x255 = kk_string_dup(line, _ctx); /*string*/
    _x_x254 = kk_string_box(_x_x255); /*9903*/
    _x_x250 = kk_std_core_hnd__open_none1(kk_hot__paths__new_mlift_server_loop_10137_fun251(_ctx), _x_x254, _ctx); /*9904*/
    op_0 = kk_string_unbox(_x_x250); /*string*/
    kk_string_t x_10138;
    if (kk_string_cmp_cstr_borrow(op_0, "record", _ctx) == 0) {
      kk_string_t name;
      kk_box_t _x_x257 = kk_std_core_hnd__open_none1(kk_hot__paths__new_mlift_server_loop_10137_fun258(_ctx), kk_string_box(line), _ctx); /*9904*/
      name = kk_string_unbox(_x_x257); /*string*/
      kk_string_t _x_x261;
      kk_define_string_literal(, _s_x262, 29, "{\"status\":\"recorded\",\"name\":\"", _ctx)
      _x_x261 = kk_string_dup(_s_x262, _ctx); /*string*/
      kk_string_t _x_x263;
      kk_string_t _x_x264;
      kk_define_string_literal(, _s_x265, 2, "\"}", _ctx)
      _x_x264 = kk_string_dup(_s_x265, _ctx); /*string*/
      _x_x263 = kk_std_core_types__lp__plus__plus__rp_(name, _x_x264, _ctx); /*string*/
      x_10138 = kk_std_core_types__lp__plus__plus__rp_(_x_x261, _x_x263, _ctx); /*string*/
      goto _match_x256;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "profile", _ctx) == 0) {
      kk_string_t name_0;
      kk_box_t _x_x266 = kk_std_core_hnd__open_none1(kk_hot__paths__new_mlift_server_loop_10137_fun267(_ctx), kk_string_box(line), _ctx); /*9904*/
      name_0 = kk_string_unbox(_x_x266); /*string*/
      kk_string_t _x_x270;
      kk_define_string_literal(, _s_x271, 28, "{\"status\":\"profile\",\"name\":\"", _ctx)
      _x_x270 = kk_string_dup(_s_x271, _ctx); /*string*/
      kk_string_t _x_x272;
      kk_string_t _x_x273;
      kk_define_string_literal(, _s_x274, 2, "\"}", _ctx)
      _x_x273 = kk_string_dup(_s_x274, _ctx); /*string*/
      _x_x272 = kk_std_core_types__lp__plus__plus__rp_(name_0, _x_x273, _ctx); /*string*/
      x_10138 = kk_std_core_types__lp__plus__plus__rp_(_x_x270, _x_x272, _ctx); /*string*/
      goto _match_x256;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "hot", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x275, 36, "{\"hot_paths\":[],\"threshold_ms\":10.0}", _ctx)
      x_10138 = kk_string_dup(_s_x275, _ctx); /*string*/
      goto _match_x256;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_string_t x = kk_std_num_float64_show(total_time_0, kk_std_core_types__new_None(_ctx), _ctx); /*string*/;
      kk_unit_t keep = kk_Unit;
      kk_evv_set(w,kk_context());
      kk_string_t _x_x276;
      kk_define_string_literal(, _s_x277, 29, "{\"status\":\"ok\",\"total_calls\":", _ctx)
      _x_x276 = kk_string_dup(_s_x277, _ctx); /*string*/
      kk_string_t _x_x278;
      kk_string_t _x_x279;
      kk_integer_t _x_x280 = kk_integer_dup(total_calls_0, _ctx); /*int*/
      _x_x279 = kk_std_core_int_show(_x_x280, _ctx); /*string*/
      kk_string_t _x_x281;
      kk_string_t _x_x282;
      kk_define_string_literal(, _s_x283, 17, ",\"total_time_ms\":", _ctx)
      _x_x282 = kk_string_dup(_s_x283, _ctx); /*string*/
      kk_string_t _x_x284;
      kk_string_t _x_x285;
      kk_define_string_literal(, _s_x286, 1, "}", _ctx)
      _x_x285 = kk_string_dup(_s_x286, _ctx); /*string*/
      _x_x284 = kk_std_core_types__lp__plus__plus__rp_(x, _x_x285, _ctx); /*string*/
      _x_x281 = kk_std_core_types__lp__plus__plus__rp_(_x_x282, _x_x284, _ctx); /*string*/
      _x_x278 = kk_std_core_types__lp__plus__plus__rp_(_x_x279, _x_x281, _ctx); /*string*/
      x_10138 = kk_std_core_types__lp__plus__plus__rp_(_x_x276, _x_x278, _ctx); /*string*/
      goto _match_x256;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "quit", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x287, 20, "{\"status\":\"stopped\"}", _ctx)
      x_10138 = kk_string_dup(_s_x287, _ctx); /*string*/
      goto _match_x256;
    }
    {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x288, 22, "{\"error\":\"unknown op\"}", _ctx)
      x_10138 = kk_string_dup(_s_x288, _ctx); /*string*/
    }
    _match_x256: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_10138, _ctx);
      kk_box_t _x_x289 = kk_std_core_hnd_yield_extend(kk_hot__paths__new_mlift_server_loop_10137_fun290(op_0, profiles_0, total_calls_0, total_time_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x289); return kk_Unit;
    }
    {
      kk_hot__paths__mlift_server_loop_10136(op_0, profiles_0, total_calls_0, total_time_0, x_10138, _ctx); return kk_Unit;
    }
  }
  {
    kk_integer_drop(total_calls_0, _ctx);
    kk_std_core_types__list_drop(profiles_0, _ctx);
    kk_string_drop(line, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_hot__paths_server_loop_fun293__t {
  struct kk_function_s _base;
  kk_std_core_types__list profiles_1;
  kk_integer_t total_calls_1;
  double total_time_1;
};
static kk_box_t kk_hot__paths_server_loop_fun293(kk_function_t _fself, kk_box_t _b_x30, kk_context_t* _ctx);
static kk_function_t kk_hot__paths_new_server_loop_fun293(kk_std_core_types__list profiles_1, kk_integer_t total_calls_1, double total_time_1, kk_context_t* _ctx) {
  struct kk_hot__paths_server_loop_fun293__t* _self = kk_function_alloc_as(struct kk_hot__paths_server_loop_fun293__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hot__paths_server_loop_fun293, kk_context());
  _self->profiles_1 = profiles_1;
  _self->total_calls_1 = total_calls_1;
  _self->total_time_1 = total_time_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hot__paths_server_loop_fun293(kk_function_t _fself, kk_box_t _b_x30, kk_context_t* _ctx) {
  struct kk_hot__paths_server_loop_fun293__t* _self = kk_function_as(struct kk_hot__paths_server_loop_fun293__t*, _fself, _ctx);
  kk_std_core_types__list profiles_1 = _self->profiles_1; /* list<hot_paths/path-profile> */
  kk_integer_t total_calls_1 = _self->total_calls_1; /* int */
  double total_time_1 = _self->total_time_1; /* float64 */
  kk_drop_match(_self, {kk_std_core_types__list_dup(profiles_1, _ctx);kk_integer_dup(total_calls_1, _ctx);kk_skip_dup(total_time_1, _ctx);}, {}, _ctx)
  kk_string_t line_0_50 = kk_string_unbox(_b_x30); /*string*/;
  kk_unit_t _x_x294 = kk_Unit;
  kk_hot__paths__mlift_server_loop_10137(profiles_1, total_calls_1, total_time_1, line_0_50, _ctx);
  return kk_unit_box(_x_x294);
}


// lift anonymous function
struct kk_hot__paths_server_loop_fun299__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hot__paths_server_loop_fun299(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx);
static kk_function_t kk_hot__paths_new_server_loop_fun299(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hot__paths_server_loop_fun299, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_hot__paths_server_loop_fun299(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x300;
  kk_string_t _x_x301 = kk_string_unbox(_b_x33); /*string*/
  _x_x300 = kk_hot__paths_extract_op(_x_x301, _ctx); /*string*/
  return kk_string_box(_x_x300);
}


// lift anonymous function
struct kk_hot__paths_server_loop_fun306__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hot__paths_server_loop_fun306(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx);
static kk_function_t kk_hot__paths_new_server_loop_fun306(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hot__paths_server_loop_fun306, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_hot__paths_server_loop_fun306(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x307;
  kk_string_t _x_x308 = kk_string_unbox(_b_x38); /*string*/
  _x_x307 = kk_hot__paths_extract_name(_x_x308, _ctx); /*string*/
  return kk_string_box(_x_x307);
}


// lift anonymous function
struct kk_hot__paths_server_loop_fun315__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hot__paths_server_loop_fun315(kk_function_t _fself, kk_box_t _b_x43, kk_context_t* _ctx);
static kk_function_t kk_hot__paths_new_server_loop_fun315(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hot__paths_server_loop_fun315, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_hot__paths_server_loop_fun315(kk_function_t _fself, kk_box_t _b_x43, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x316;
  kk_string_t _x_x317 = kk_string_unbox(_b_x43); /*string*/
  _x_x316 = kk_hot__paths_extract_name(_x_x317, _ctx); /*string*/
  return kk_string_box(_x_x316);
}


// lift anonymous function
struct kk_hot__paths_server_loop_fun338__t {
  struct kk_function_s _base;
  kk_string_t op_1;
  kk_std_core_types__list profiles_1;
  kk_integer_t total_calls_1;
  double total_time_1;
};
static kk_box_t kk_hot__paths_server_loop_fun338(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_hot__paths_new_server_loop_fun338(kk_string_t op_1, kk_std_core_types__list profiles_1, kk_integer_t total_calls_1, double total_time_1, kk_context_t* _ctx) {
  struct kk_hot__paths_server_loop_fun338__t* _self = kk_function_alloc_as(struct kk_hot__paths_server_loop_fun338__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hot__paths_server_loop_fun338, kk_context());
  _self->op_1 = op_1;
  _self->profiles_1 = profiles_1;
  _self->total_calls_1 = total_calls_1;
  _self->total_time_1 = total_time_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hot__paths_server_loop_fun338(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx) {
  struct kk_hot__paths_server_loop_fun338__t* _self = kk_function_as(struct kk_hot__paths_server_loop_fun338__t*, _fself, _ctx);
  kk_string_t op_1 = _self->op_1; /* string */
  kk_std_core_types__list profiles_1 = _self->profiles_1; /* list<hot_paths/path-profile> */
  kk_integer_t total_calls_1 = _self->total_calls_1; /* int */
  double total_time_1 = _self->total_time_1; /* float64 */
  kk_drop_match(_self, {kk_string_dup(op_1, _ctx);kk_std_core_types__list_dup(profiles_1, _ctx);kk_integer_dup(total_calls_1, _ctx);kk_skip_dup(total_time_1, _ctx);}, {}, _ctx)
  kk_string_t _c_x10120_1_51 = kk_string_unbox(_b_x47); /*string*/;
  kk_unit_t _x_x339 = kk_Unit;
  kk_hot__paths__mlift_server_loop_10136(op_1, profiles_1, total_calls_1, total_time_1, _c_x10120_1_51, _ctx);
  return kk_unit_box(_x_x339);
}

kk_unit_t kk_hot__paths_server_loop(kk_integer_t total_calls_1, double total_time_1, kk_std_core_types__list profiles_1, kk_context_t* _ctx) { /* (total-calls : int, total-time : float64, profiles : list<path-profile>) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_0_10140 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10140, _ctx);
    kk_box_t _x_x292 = kk_std_core_hnd_yield_extend(kk_hot__paths_new_server_loop_fun293(profiles_1, total_calls_1, total_time_1, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x292); return kk_Unit;
  }
  {
    bool _match_x53;
    kk_string_t _x_x295 = kk_string_dup(x_0_10140, _ctx); /*string*/
    kk_string_t _x_x296 = kk_string_empty(); /*string*/
    _match_x53 = kk_string_is_neq(_x_x295,_x_x296,kk_context()); /*bool*/
    if (_match_x53) {
      kk_string_t op_1;
      kk_box_t _x_x298;
      kk_box_t _x_x302;
      kk_string_t _x_x303 = kk_string_dup(x_0_10140, _ctx); /*string*/
      _x_x302 = kk_string_box(_x_x303); /*9903*/
      _x_x298 = kk_std_core_hnd__open_none1(kk_hot__paths_new_server_loop_fun299(_ctx), _x_x302, _ctx); /*9904*/
      op_1 = kk_string_unbox(_x_x298); /*string*/
      kk_string_t x_1_10143;
      if (kk_string_cmp_cstr_borrow(op_1, "record", _ctx) == 0) {
        kk_string_t name_1;
        kk_box_t _x_x305 = kk_std_core_hnd__open_none1(kk_hot__paths_new_server_loop_fun306(_ctx), kk_string_box(x_0_10140), _ctx); /*9904*/
        name_1 = kk_string_unbox(_x_x305); /*string*/
        kk_string_t _x_x309;
        kk_define_string_literal(, _s_x310, 29, "{\"status\":\"recorded\",\"name\":\"", _ctx)
        _x_x309 = kk_string_dup(_s_x310, _ctx); /*string*/
        kk_string_t _x_x311;
        kk_string_t _x_x312;
        kk_define_string_literal(, _s_x313, 2, "\"}", _ctx)
        _x_x312 = kk_string_dup(_s_x313, _ctx); /*string*/
        _x_x311 = kk_std_core_types__lp__plus__plus__rp_(name_1, _x_x312, _ctx); /*string*/
        x_1_10143 = kk_std_core_types__lp__plus__plus__rp_(_x_x309, _x_x311, _ctx); /*string*/
        goto _match_x304;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "profile", _ctx) == 0) {
        kk_string_t name_0_0;
        kk_box_t _x_x314 = kk_std_core_hnd__open_none1(kk_hot__paths_new_server_loop_fun315(_ctx), kk_string_box(x_0_10140), _ctx); /*9904*/
        name_0_0 = kk_string_unbox(_x_x314); /*string*/
        kk_string_t _x_x318;
        kk_define_string_literal(, _s_x319, 28, "{\"status\":\"profile\",\"name\":\"", _ctx)
        _x_x318 = kk_string_dup(_s_x319, _ctx); /*string*/
        kk_string_t _x_x320;
        kk_string_t _x_x321;
        kk_define_string_literal(, _s_x322, 2, "\"}", _ctx)
        _x_x321 = kk_string_dup(_s_x322, _ctx); /*string*/
        _x_x320 = kk_std_core_types__lp__plus__plus__rp_(name_0_0, _x_x321, _ctx); /*string*/
        x_1_10143 = kk_std_core_types__lp__plus__plus__rp_(_x_x318, _x_x320, _ctx); /*string*/
        goto _match_x304;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "hot", _ctx) == 0) {
        kk_string_drop(x_0_10140, _ctx);
        kk_define_string_literal(, _s_x323, 36, "{\"hot_paths\":[],\"threshold_ms\":10.0}", _ctx)
        x_1_10143 = kk_string_dup(_s_x323, _ctx); /*string*/
        goto _match_x304;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
        kk_string_drop(x_0_10140, _ctx);
        kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_string_t x_0 = kk_std_num_float64_show(total_time_1, kk_std_core_types__new_None(_ctx), _ctx); /*string*/;
        kk_unit_t keep_0 = kk_Unit;
        kk_evv_set(w_0,kk_context());
        kk_string_t _x_x324;
        kk_define_string_literal(, _s_x325, 29, "{\"status\":\"ok\",\"total_calls\":", _ctx)
        _x_x324 = kk_string_dup(_s_x325, _ctx); /*string*/
        kk_string_t _x_x326;
        kk_string_t _x_x327;
        kk_integer_t _x_x328 = kk_integer_dup(total_calls_1, _ctx); /*int*/
        _x_x327 = kk_std_core_int_show(_x_x328, _ctx); /*string*/
        kk_string_t _x_x329;
        kk_string_t _x_x330;
        kk_define_string_literal(, _s_x331, 17, ",\"total_time_ms\":", _ctx)
        _x_x330 = kk_string_dup(_s_x331, _ctx); /*string*/
        kk_string_t _x_x332;
        kk_string_t _x_x333;
        kk_define_string_literal(, _s_x334, 1, "}", _ctx)
        _x_x333 = kk_string_dup(_s_x334, _ctx); /*string*/
        _x_x332 = kk_std_core_types__lp__plus__plus__rp_(x_0, _x_x333, _ctx); /*string*/
        _x_x329 = kk_std_core_types__lp__plus__plus__rp_(_x_x330, _x_x332, _ctx); /*string*/
        _x_x326 = kk_std_core_types__lp__plus__plus__rp_(_x_x327, _x_x329, _ctx); /*string*/
        x_1_10143 = kk_std_core_types__lp__plus__plus__rp_(_x_x324, _x_x326, _ctx); /*string*/
        goto _match_x304;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "quit", _ctx) == 0) {
        kk_string_drop(x_0_10140, _ctx);
        kk_define_string_literal(, _s_x335, 20, "{\"status\":\"stopped\"}", _ctx)
        x_1_10143 = kk_string_dup(_s_x335, _ctx); /*string*/
        goto _match_x304;
      }
      {
        kk_string_drop(x_0_10140, _ctx);
        kk_define_string_literal(, _s_x336, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_1_10143 = kk_string_dup(_s_x336, _ctx); /*string*/
      }
      _match_x304: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_1_10143, _ctx);
        kk_box_t _x_x337 = kk_std_core_hnd_yield_extend(kk_hot__paths_new_server_loop_fun338(op_1, profiles_1, total_calls_1, total_time_1, _ctx), _ctx); /*2419*/
        kk_unit_unbox(_x_x337); return kk_Unit;
      }
      {
        kk_unit_t ___0 = kk_Unit;
        kk_std_core_console_printsln(x_1_10143, _ctx);
        bool _match_x55;
        kk_string_t _x_x340;
        kk_define_string_literal(, _s_x341, 4, "quit", _ctx)
        _x_x340 = kk_string_dup(_s_x341, _ctx); /*string*/
        _match_x55 = kk_string_is_neq(op_1,_x_x340,kk_context()); /*bool*/
        if (_match_x55) { // tailcall
                          kk_integer_t _x_x342 = kk_integer_add_small_const(total_calls_1, 1, _ctx); /*int*/
                          double _x_x343 = (total_time_1 + 0x1p0); /*float64*/
                          total_calls_1 = _x_x342;
                          total_time_1 = _x_x343;
                          goto kk__tailcall;
        }
        {
          kk_integer_drop(total_calls_1, _ctx);
          kk_std_core_types__list_drop(profiles_1, _ctx);
          kk_Unit; return kk_Unit;
        }
      }
    }
    {
      kk_string_drop(x_0_10140, _ctx);
      kk_integer_drop(total_calls_1, _ctx);
      kk_std_core_types__list_drop(profiles_1, _ctx);
      kk_Unit; return kk_Unit;
    }
  }
}

// initialization
void kk_hot__paths__init(kk_context_t* _ctx){
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
void kk_hot__paths__done(kk_context_t* _ctx){
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
