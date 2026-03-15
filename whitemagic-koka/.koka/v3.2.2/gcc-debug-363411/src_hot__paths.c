// Koka generated module: src/hot_paths, koka version: 3.2.2, platform: 64-bit
#include "src_hot__paths.h"

kk_src_hot__paths__path_profile kk_src_hot__paths_path_profile_fs__copy(kk_src_hot__paths__path_profile _this, kk_std_core_types__optional name, kk_std_core_types__optional call_count, kk_std_core_types__optional total_time_ms, kk_std_core_types__optional avg_time_ms, kk_std_core_types__optional complexity, kk_std_core_types__optional category, kk_context_t* _ctx) { /* (path-profile, name : ? string, call-count : ? int, total-time-ms : ? float64, avg-time-ms : ? float64, complexity : ? complexity, category : ? path-category) -> path-profile */ 
  kk_string_t _x_x112;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x0 = name._cons._Optional.value;
    kk_string_t _uniq_name_162 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_name_162, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x112 = _uniq_name_162; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_src_hot__paths_Path_profile* _con_x113 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
      kk_string_t _x = _con_x113->name;
      kk_string_dup(_x, _ctx);
      _x_x112 = _x; /*string*/
    }
  }
  kk_integer_t _x_x114;
  if (kk_std_core_types__is_Optional(call_count, _ctx)) {
    kk_box_t _box_x1 = call_count._cons._Optional.value;
    kk_integer_t _uniq_call_count_170 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_call_count_170, _ctx);
    kk_std_core_types__optional_drop(call_count, _ctx);
    _x_x114 = _uniq_call_count_170; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(call_count, _ctx);
    {
      struct kk_src_hot__paths_Path_profile* _con_x115 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
      kk_integer_t _x_0 = _con_x115->call_count;
      kk_integer_dup(_x_0, _ctx);
      _x_x114 = _x_0; /*int*/
    }
  }
  double _x_x116;
  if (kk_std_core_types__is_Optional(total_time_ms, _ctx)) {
    kk_box_t _box_x2 = total_time_ms._cons._Optional.value;
    double _uniq_total_time_ms_178 = kk_double_unbox(_box_x2, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    _x_x116 = _uniq_total_time_ms_178; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    {
      struct kk_src_hot__paths_Path_profile* _con_x117 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
      double _x_1 = _con_x117->total_time_ms;
      _x_x116 = _x_1; /*float64*/
    }
  }
  double _x_x118;
  if (kk_std_core_types__is_Optional(avg_time_ms, _ctx)) {
    kk_box_t _box_x3 = avg_time_ms._cons._Optional.value;
    double _uniq_avg_time_ms_186 = kk_double_unbox(_box_x3, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(avg_time_ms, _ctx);
    _x_x118 = _uniq_avg_time_ms_186; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(avg_time_ms, _ctx);
    {
      struct kk_src_hot__paths_Path_profile* _con_x119 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
      double _x_2 = _con_x119->avg_time_ms;
      _x_x118 = _x_2; /*float64*/
    }
  }
  kk_src_hot__paths__complexity _x_x120;
  if (kk_std_core_types__is_Optional(complexity, _ctx)) {
    kk_box_t _box_x4 = complexity._cons._Optional.value;
    kk_src_hot__paths__complexity _uniq_complexity_194 = kk_src_hot__paths__complexity_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(complexity, _ctx);
    _x_x120 = _uniq_complexity_194; /*src/hot_paths/complexity*/
  }
  else {
    kk_std_core_types__optional_drop(complexity, _ctx);
    {
      struct kk_src_hot__paths_Path_profile* _con_x121 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
      kk_src_hot__paths__complexity _x_3 = _con_x121->complexity;
      _x_x120 = _x_3; /*src/hot_paths/complexity*/
    }
  }
  kk_src_hot__paths__path_category _x_x122;
  if (kk_std_core_types__is_Optional(category, _ctx)) {
    kk_box_t _box_x5 = category._cons._Optional.value;
    kk_src_hot__paths__path_category _uniq_category_202 = kk_src_hot__paths__path_category_unbox(_box_x5, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(category, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x122 = _uniq_category_202; /*src/hot_paths/path-category*/
  }
  else {
    kk_std_core_types__optional_drop(category, _ctx);
    {
      struct kk_src_hot__paths_Path_profile* _con_x123 = kk_src_hot__paths__as_Path_profile(_this, _ctx);
      kk_string_t _pat_0_5 = _con_x123->name;
      kk_integer_t _pat_1_6 = _con_x123->call_count;
      kk_src_hot__paths__path_category _x_4 = _con_x123->category;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_6, _ctx);
        kk_string_drop(_pat_0_5, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x122 = _x_4; /*src/hot_paths/path-category*/
    }
  }
  return kk_src_hot__paths__new_Path_profile(kk_reuse_null, 0, _x_x112, _x_x114, _x_x116, _x_x118, _x_x120, _x_x122, _ctx);
}

kk_src_hot__paths__profiling_session kk_src_hot__paths_profiling_session_fs__copy(kk_src_hot__paths__profiling_session _this, kk_std_core_types__optional paths, kk_std_core_types__optional total_calls, kk_std_core_types__optional total_time_ms, kk_std_core_types__optional hot_threshold_ms, kk_context_t* _ctx) { /* (profiling-session, paths : ? (list<path-profile>), total-calls : ? int, total-time-ms : ? float64, hot-threshold-ms : ? float64) -> profiling-session */ 
  kk_std_core_types__list _x_x128;
  if (kk_std_core_types__is_Optional(paths, _ctx)) {
    kk_box_t _box_x6 = paths._cons._Optional.value;
    kk_std_core_types__list _uniq_paths_255 = kk_std_core_types__list_unbox(_box_x6, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_paths_255, _ctx);
    kk_std_core_types__optional_drop(paths, _ctx);
    _x_x128 = _uniq_paths_255; /*list<src/hot_paths/path-profile>*/
  }
  else {
    kk_std_core_types__optional_drop(paths, _ctx);
    {
      struct kk_src_hot__paths_Profiling_session* _con_x129 = kk_src_hot__paths__as_Profiling_session(_this, _ctx);
      kk_std_core_types__list _x = _con_x129->paths;
      kk_std_core_types__list_dup(_x, _ctx);
      _x_x128 = _x; /*list<src/hot_paths/path-profile>*/
    }
  }
  kk_integer_t _x_x130;
  if (kk_std_core_types__is_Optional(total_calls, _ctx)) {
    kk_box_t _box_x7 = total_calls._cons._Optional.value;
    kk_integer_t _uniq_total_calls_263 = kk_integer_unbox(_box_x7, _ctx);
    kk_integer_dup(_uniq_total_calls_263, _ctx);
    kk_std_core_types__optional_drop(total_calls, _ctx);
    _x_x130 = _uniq_total_calls_263; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(total_calls, _ctx);
    {
      struct kk_src_hot__paths_Profiling_session* _con_x131 = kk_src_hot__paths__as_Profiling_session(_this, _ctx);
      kk_integer_t _x_0 = _con_x131->total_calls;
      kk_integer_dup(_x_0, _ctx);
      _x_x130 = _x_0; /*int*/
    }
  }
  double _x_x132;
  if (kk_std_core_types__is_Optional(total_time_ms, _ctx)) {
    kk_box_t _box_x8 = total_time_ms._cons._Optional.value;
    double _uniq_total_time_ms_271 = kk_double_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    _x_x132 = _uniq_total_time_ms_271; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(total_time_ms, _ctx);
    {
      struct kk_src_hot__paths_Profiling_session* _con_x133 = kk_src_hot__paths__as_Profiling_session(_this, _ctx);
      double _x_1 = _con_x133->total_time_ms;
      _x_x132 = _x_1; /*float64*/
    }
  }
  double _x_x134;
  if (kk_std_core_types__is_Optional(hot_threshold_ms, _ctx)) {
    kk_box_t _box_x9 = hot_threshold_ms._cons._Optional.value;
    double _uniq_hot_threshold_ms_279 = kk_double_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(hot_threshold_ms, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x134 = _uniq_hot_threshold_ms_279; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(hot_threshold_ms, _ctx);
    {
      struct kk_src_hot__paths_Profiling_session* _con_x135 = kk_src_hot__paths__as_Profiling_session(_this, _ctx);
      kk_std_core_types__list _pat_0_3 = _con_x135->paths;
      kk_integer_t _pat_1_4 = _con_x135->total_calls;
      double _x_2 = _con_x135->hot_threshold_ms;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_4, _ctx);
        kk_std_core_types__list_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x134 = _x_2; /*float64*/
    }
  }
  return kk_src_hot__paths__new_Profiling_session(kk_reuse_null, 0, _x_x128, _x_x130, _x_x132, _x_x134, _ctx);
}

kk_src_hot__paths__complexity kk_src_hot__paths_estimate_complexity(double avg_time_ms, kk_integer_t call_count, kk_context_t* _ctx) { /* (avg-time-ms : float64, call-count : int) -> complexity */ 
  bool _match_x93 = kk_integer_gt_borrow(call_count,(kk_integer_from_small(100)),kk_context()); /*bool*/;
  if (_match_x93) {
    bool _match_x97 = (avg_time_ms > (0x1.4p3)); /*bool*/;
    if (_match_x97) {
      kk_integer_drop(call_count, _ctx);
      return kk_src_hot__paths__new_High(_ctx);
    }
    {
      bool _match_x98;
      bool _brw_x100 = kk_integer_gt_borrow(call_count,(kk_integer_from_small(10)),kk_context()); /*bool*/;
      kk_integer_drop(call_count, _ctx);
      _match_x98 = _brw_x100; /*bool*/
      if (_match_x98) {
        return kk_src_hot__paths__new_Medium(_ctx);
      }
      {
        bool _match_x99 = (avg_time_ms > (0x1.4p2)); /*bool*/;
        if (_match_x99) {
          return kk_src_hot__paths__new_Medium(_ctx);
        }
        {
          return kk_src_hot__paths__new_Low(_ctx);
        }
      }
    }
  }
  {
    bool _match_x94;
    bool _brw_x96 = kk_integer_gt_borrow(call_count,(kk_integer_from_small(10)),kk_context()); /*bool*/;
    kk_integer_drop(call_count, _ctx);
    _match_x94 = _brw_x96; /*bool*/
    if (_match_x94) {
      return kk_src_hot__paths__new_Medium(_ctx);
    }
    {
      bool _match_x95 = (avg_time_ms > (0x1.4p2)); /*bool*/;
      if (_match_x95) {
        return kk_src_hot__paths__new_Medium(_ctx);
      }
      {
        return kk_src_hot__paths__new_Low(_ctx);
      }
    }
  }
}

kk_src_hot__paths__path_category kk_src_hot__paths_estimate_category(kk_string_t name, kk_context_t* _ctx) { /* (name : string) -> path-category */ 
  bool _match_x84;
  kk_string_t _x_x143 = kk_string_dup(name, _ctx); /*string*/
  kk_string_t _x_x144;
  kk_define_string_literal(, _s_x145, 5, "embed", _ctx)
  _x_x144 = kk_string_dup(_s_x145, _ctx); /*string*/
  _match_x84 = kk_string_contains(_x_x143,_x_x144,kk_context()); /*bool*/
  if (_match_x84) {
    kk_string_drop(name, _ctx);
    return kk_src_hot__paths__new_Compute(_ctx);
  }
  {
    bool _match_x85;
    kk_string_t _x_x146 = kk_string_dup(name, _ctx); /*string*/
    kk_string_t _x_x147;
    kk_define_string_literal(, _s_x148, 6, "vector", _ctx)
    _x_x147 = kk_string_dup(_s_x148, _ctx); /*string*/
    _match_x85 = kk_string_contains(_x_x146,_x_x147,kk_context()); /*bool*/
    if (_match_x85) {
      kk_string_drop(name, _ctx);
      return kk_src_hot__paths__new_Compute(_ctx);
    }
    {
      bool _match_x86;
      kk_string_t _x_x149 = kk_string_dup(name, _ctx); /*string*/
      kk_string_t _x_x150;
      kk_define_string_literal(, _s_x151, 7, "compute", _ctx)
      _x_x150 = kk_string_dup(_s_x151, _ctx); /*string*/
      _match_x86 = kk_string_contains(_x_x149,_x_x150,kk_context()); /*bool*/
      if (_match_x86) {
        kk_string_drop(name, _ctx);
        return kk_src_hot__paths__new_Compute(_ctx);
      }
      {
        bool _match_x87;
        kk_string_t _x_x152 = kk_string_dup(name, _ctx); /*string*/
        kk_string_t _x_x153;
        kk_define_string_literal(, _s_x154, 6, "memory", _ctx)
        _x_x153 = kk_string_dup(_s_x154, _ctx); /*string*/
        _match_x87 = kk_string_contains(_x_x152,_x_x153,kk_context()); /*bool*/
        if (_match_x87) {
          kk_string_drop(name, _ctx);
          return kk_src_hot__paths__new_Memory(_ctx);
        }
        {
          bool _match_x88;
          kk_string_t _x_x155 = kk_string_dup(name, _ctx); /*string*/
          kk_string_t _x_x156;
          kk_define_string_literal(, _s_x157, 5, "cache", _ctx)
          _x_x156 = kk_string_dup(_s_x157, _ctx); /*string*/
          _match_x88 = kk_string_contains(_x_x155,_x_x156,kk_context()); /*bool*/
          if (_match_x88) {
            kk_string_drop(name, _ctx);
            return kk_src_hot__paths__new_Memory(_ctx);
          }
          {
            bool _match_x89;
            kk_string_t _x_x158 = kk_string_dup(name, _ctx); /*string*/
            kk_string_t _x_x159;
            kk_define_string_literal(, _s_x160, 5, "store", _ctx)
            _x_x159 = kk_string_dup(_s_x160, _ctx); /*string*/
            _match_x89 = kk_string_contains(_x_x158,_x_x159,kk_context()); /*bool*/
            if (_match_x89) {
              kk_string_drop(name, _ctx);
              return kk_src_hot__paths__new_Memory(_ctx);
            }
            {
              bool _match_x90;
              kk_string_t _x_x161 = kk_string_dup(name, _ctx); /*string*/
              kk_string_t _x_x162;
              kk_define_string_literal(, _s_x163, 4, "read", _ctx)
              _x_x162 = kk_string_dup(_s_x163, _ctx); /*string*/
              _match_x90 = kk_string_contains(_x_x161,_x_x162,kk_context()); /*bool*/
              if (_match_x90) {
                kk_string_drop(name, _ctx);
                return kk_src_hot__paths__new_IO(_ctx);
              }
              {
                bool _match_x91;
                kk_string_t _x_x164 = kk_string_dup(name, _ctx); /*string*/
                kk_string_t _x_x165;
                kk_define_string_literal(, _s_x166, 5, "write", _ctx)
                _x_x165 = kk_string_dup(_s_x166, _ctx); /*string*/
                _match_x91 = kk_string_contains(_x_x164,_x_x165,kk_context()); /*bool*/
                if (_match_x91) {
                  kk_string_drop(name, _ctx);
                  return kk_src_hot__paths__new_IO(_ctx);
                }
                {
                  bool _match_x92;
                  kk_string_t _x_x167;
                  kk_define_string_literal(, _s_x168, 4, "load", _ctx)
                  _x_x167 = kk_string_dup(_s_x168, _ctx); /*string*/
                  _match_x92 = kk_string_contains(name,_x_x167,kk_context()); /*bool*/
                  if (_match_x92) {
                    return kk_src_hot__paths__new_IO(_ctx);
                  }
                  {
                    return kk_src_hot__paths__new_Mixed(_ctx);
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

kk_string_t kk_src_hot__paths_json_profile(kk_src_hot__paths__path_profile p, kk_context_t* _ctx) { /* (p : path-profile) -> string */ 
  kk_string_t _x_x172;
  kk_define_string_literal(, _s_x173, 9, "{\"name\":\"", _ctx)
  _x_x172 = kk_string_dup(_s_x173, _ctx); /*string*/
  kk_string_t _x_x174;
  kk_string_t _x_x175;
  {
    struct kk_src_hot__paths_Path_profile* _con_x176 = kk_src_hot__paths__as_Path_profile(p, _ctx);
    kk_string_t _x = _con_x176->name;
    kk_string_dup(_x, _ctx);
    _x_x175 = _x; /*string*/
  }
  kk_string_t _x_x177;
  kk_string_t _x_x178;
  kk_define_string_literal(, _s_x179, 10, "\",\"calls\":", _ctx)
  _x_x178 = kk_string_dup(_s_x179, _ctx); /*string*/
  kk_string_t _x_x180;
  kk_string_t _x_x181;
  kk_integer_t _x_x182;
  {
    struct kk_src_hot__paths_Path_profile* _con_x183 = kk_src_hot__paths__as_Path_profile(p, _ctx);
    kk_integer_t _x_0 = _con_x183->call_count;
    kk_integer_dup(_x_0, _ctx);
    _x_x182 = _x_0; /*int*/
  }
  _x_x181 = kk_std_core_int_show(_x_x182, _ctx); /*string*/
  kk_string_t _x_x184;
  kk_string_t _x_x185;
  kk_define_string_literal(, _s_x186, 10, ",\"avg_ms\":", _ctx)
  _x_x185 = kk_string_dup(_s_x186, _ctx); /*string*/
  kk_string_t _x_x187;
  kk_string_t _x_x188;
  double _x_x189;
  {
    struct kk_src_hot__paths_Path_profile* _con_x190 = kk_src_hot__paths__as_Path_profile(p, _ctx);
    double _x_1 = _con_x190->avg_time_ms;
    _x_x189 = _x_1; /*float64*/
  }
  _x_x188 = kk_std_num_float64_show(_x_x189, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x191;
  kk_string_t _x_x192;
  kk_define_string_literal(, _s_x193, 15, ",\"complexity\":\"", _ctx)
  _x_x192 = kk_string_dup(_s_x193, _ctx); /*string*/
  kk_string_t _x_x194;
  kk_string_t _x_x195;
  {
    struct kk_src_hot__paths_Path_profile* _con_x196 = kk_src_hot__paths__as_Path_profile(p, _ctx);
    kk_src_hot__paths__complexity _x_2 = _con_x196->complexity;
    if (kk_src_hot__paths__is_Low(_x_2, _ctx)) {
      kk_define_string_literal(, _s_x198, 3, "low", _ctx)
      _x_x195 = kk_string_dup(_s_x198, _ctx); /*string*/
      goto _match_x197;
    }
    if (kk_src_hot__paths__is_Medium(_x_2, _ctx)) {
      kk_define_string_literal(, _s_x199, 6, "medium", _ctx)
      _x_x195 = kk_string_dup(_s_x199, _ctx); /*string*/
      goto _match_x197;
    }
    {
      kk_define_string_literal(, _s_x200, 4, "high", _ctx)
      _x_x195 = kk_string_dup(_s_x200, _ctx); /*string*/
    }
    _match_x197: ;
  }
  kk_string_t _x_x201;
  kk_string_t _x_x202;
  kk_define_string_literal(, _s_x203, 1, "\"", _ctx)
  _x_x202 = kk_string_dup(_s_x203, _ctx); /*string*/
  kk_string_t _x_x204;
  kk_string_t _x_x205;
  kk_define_string_literal(, _s_x206, 13, ",\"category\":\"", _ctx)
  _x_x205 = kk_string_dup(_s_x206, _ctx); /*string*/
  kk_string_t _x_x207;
  kk_string_t _x_x208;
  {
    struct kk_src_hot__paths_Path_profile* _con_x209 = kk_src_hot__paths__as_Path_profile(p, _ctx);
    kk_string_t _pat_0_5 = _con_x209->name;
    kk_integer_t _pat_1_5 = _con_x209->call_count;
    kk_src_hot__paths__path_category _x_3 = _con_x209->category;
    if kk_likely(kk_datatype_ptr_is_unique(p, _ctx)) {
      kk_integer_drop(_pat_1_5, _ctx);
      kk_string_drop(_pat_0_5, _ctx);
      kk_datatype_ptr_free(p, _ctx);
    }
    else {
      kk_datatype_ptr_decref(p, _ctx);
    }
    if (kk_src_hot__paths__is_Compute(_x_3, _ctx)) {
      kk_define_string_literal(, _s_x211, 7, "compute", _ctx)
      _x_x208 = kk_string_dup(_s_x211, _ctx); /*string*/
      goto _match_x210;
    }
    if (kk_src_hot__paths__is_Memory(_x_3, _ctx)) {
      kk_define_string_literal(, _s_x212, 6, "memory", _ctx)
      _x_x208 = kk_string_dup(_s_x212, _ctx); /*string*/
      goto _match_x210;
    }
    if (kk_src_hot__paths__is_IO(_x_3, _ctx)) {
      kk_define_string_literal(, _s_x213, 2, "io", _ctx)
      _x_x208 = kk_string_dup(_s_x213, _ctx); /*string*/
      goto _match_x210;
    }
    {
      kk_define_string_literal(, _s_x214, 5, "mixed", _ctx)
      _x_x208 = kk_string_dup(_s_x214, _ctx); /*string*/
    }
    _match_x210: ;
  }
  kk_string_t _x_x215;
  kk_define_string_literal(, _s_x216, 2, "\"}", _ctx)
  _x_x215 = kk_string_dup(_s_x216, _ctx); /*string*/
  _x_x207 = kk_std_core_types__lp__plus__plus__rp_(_x_x208, _x_x215, _ctx); /*string*/
  _x_x204 = kk_std_core_types__lp__plus__plus__rp_(_x_x205, _x_x207, _ctx); /*string*/
  _x_x201 = kk_std_core_types__lp__plus__plus__rp_(_x_x202, _x_x204, _ctx); /*string*/
  _x_x194 = kk_std_core_types__lp__plus__plus__rp_(_x_x195, _x_x201, _ctx); /*string*/
  _x_x191 = kk_std_core_types__lp__plus__plus__rp_(_x_x192, _x_x194, _ctx); /*string*/
  _x_x187 = kk_std_core_types__lp__plus__plus__rp_(_x_x188, _x_x191, _ctx); /*string*/
  _x_x184 = kk_std_core_types__lp__plus__plus__rp_(_x_x185, _x_x187, _ctx); /*string*/
  _x_x180 = kk_std_core_types__lp__plus__plus__rp_(_x_x181, _x_x184, _ctx); /*string*/
  _x_x177 = kk_std_core_types__lp__plus__plus__rp_(_x_x178, _x_x180, _ctx); /*string*/
  _x_x174 = kk_std_core_types__lp__plus__plus__rp_(_x_x175, _x_x177, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x172, _x_x174, _ctx);
}

kk_string_t kk_src_hot__paths_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x79;
  kk_string_t _x_x217 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x218;
  kk_define_string_literal(, _s_x219, 8, "\"record\"", _ctx)
  _x_x218 = kk_string_dup(_s_x219, _ctx); /*string*/
  _match_x79 = kk_string_contains(_x_x217,_x_x218,kk_context()); /*bool*/
  if (_match_x79) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x220, 6, "record", _ctx)
    return kk_string_dup(_s_x220, _ctx);
  }
  {
    bool _match_x80;
    kk_string_t _x_x221 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x222;
    kk_define_string_literal(, _s_x223, 9, "\"profile\"", _ctx)
    _x_x222 = kk_string_dup(_s_x223, _ctx); /*string*/
    _match_x80 = kk_string_contains(_x_x221,_x_x222,kk_context()); /*bool*/
    if (_match_x80) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x224, 7, "profile", _ctx)
      return kk_string_dup(_s_x224, _ctx);
    }
    {
      bool _match_x81;
      kk_string_t _x_x225 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x226;
      kk_define_string_literal(, _s_x227, 5, "\"hot\"", _ctx)
      _x_x226 = kk_string_dup(_s_x227, _ctx); /*string*/
      _match_x81 = kk_string_contains(_x_x225,_x_x226,kk_context()); /*bool*/
      if (_match_x81) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x228, 3, "hot", _ctx)
        return kk_string_dup(_s_x228, _ctx);
      }
      {
        bool _match_x82;
        kk_string_t _x_x229 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x230;
        kk_define_string_literal(, _s_x231, 8, "\"status\"", _ctx)
        _x_x230 = kk_string_dup(_s_x231, _ctx); /*string*/
        _match_x82 = kk_string_contains(_x_x229,_x_x230,kk_context()); /*bool*/
        if (_match_x82) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x232, 6, "status", _ctx)
          return kk_string_dup(_s_x232, _ctx);
        }
        {
          bool _match_x83;
          kk_string_t _x_x233;
          kk_define_string_literal(, _s_x234, 6, "\"quit\"", _ctx)
          _x_x233 = kk_string_dup(_s_x234, _ctx); /*string*/
          _match_x83 = kk_string_contains(line,_x_x233,kk_context()); /*bool*/
          if (_match_x83) {
            kk_define_string_literal(, _s_x235, 4, "quit", _ctx)
            return kk_string_dup(_s_x235, _ctx);
          }
          {
            kk_define_string_literal(, _s_x236, 7, "unknown", _ctx)
            return kk_string_dup(_s_x236, _ctx);
          }
        }
      }
    }
  }
}

kk_string_t kk_src_hot__paths_extract_name(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x75;
  kk_string_t _x_x237 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x238;
  kk_define_string_literal(, _s_x239, 5, "embed", _ctx)
  _x_x238 = kk_string_dup(_s_x239, _ctx); /*string*/
  _match_x75 = kk_string_contains(_x_x237,_x_x238,kk_context()); /*bool*/
  if (_match_x75) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x240, 12, "embedding_op", _ctx)
    return kk_string_dup(_s_x240, _ctx);
  }
  {
    bool _match_x76;
    kk_string_t _x_x241 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x242;
    kk_define_string_literal(, _s_x243, 7, "compute", _ctx)
    _x_x242 = kk_string_dup(_s_x243, _ctx); /*string*/
    _match_x76 = kk_string_contains(_x_x241,_x_x242,kk_context()); /*bool*/
    if (_match_x76) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x244, 10, "compute_op", _ctx)
      return kk_string_dup(_s_x244, _ctx);
    }
    {
      bool _match_x77;
      kk_string_t _x_x245 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x246;
      kk_define_string_literal(, _s_x247, 6, "memory", _ctx)
      _x_x246 = kk_string_dup(_s_x247, _ctx); /*string*/
      _match_x77 = kk_string_contains(_x_x245,_x_x246,kk_context()); /*bool*/
      if (_match_x77) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x248, 9, "memory_op", _ctx)
        return kk_string_dup(_s_x248, _ctx);
      }
      {
        bool _match_x78;
        kk_string_t _x_x249;
        kk_define_string_literal(, _s_x250, 6, "vector", _ctx)
        _x_x249 = kk_string_dup(_s_x250, _ctx); /*string*/
        _match_x78 = kk_string_contains(line,_x_x249,kk_context()); /*bool*/
        if (_match_x78) {
          kk_define_string_literal(, _s_x251, 9, "vector_op", _ctx)
          return kk_string_dup(_s_x251, _ctx);
        }
        {
          kk_define_string_literal(, _s_x252, 10, "unknown_op", _ctx)
          return kk_string_dup(_s_x252, _ctx);
        }
      }
    }
  }
}
 
// monadic lift

kk_unit_t kk_src_hot__paths__mlift_server_loop_10034(kk_string_t op, kk_std_core_types__list profiles, kk_integer_t total_calls, double total_time, kk_string_t _c_x10018, kk_context_t* _ctx) { /* (op : string, profiles : list<path-profile>, total-calls : int, total-time : float64, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10018, _ctx);
  bool _match_x74;
  kk_string_t _x_x253;
  kk_define_string_literal(, _s_x254, 4, "quit", _ctx)
  _x_x253 = kk_string_dup(_s_x254, _ctx); /*string*/
  _match_x74 = kk_string_is_neq(op,_x_x253,kk_context()); /*bool*/
  if (_match_x74) {
    kk_integer_t _x_x255 = kk_integer_add_small_const(total_calls, 1, _ctx); /*int*/
    double _x_x256 = (total_time + 0x1p0); /*float64*/
    kk_src_hot__paths_server_loop(_x_x255, _x_x256, profiles, _ctx); return kk_Unit;
  }
  {
    kk_integer_drop(total_calls, _ctx);
    kk_std_core_types__list_drop(profiles, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_hot__paths__mlift_server_loop_10035_fun261__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_hot__paths__mlift_server_loop_10035_fun261(kk_function_t _fself, kk_box_t _b_x12, kk_context_t* _ctx);
static kk_function_t kk_src_hot__paths__new_mlift_server_loop_10035_fun261(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_hot__paths__mlift_server_loop_10035_fun261, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_hot__paths__mlift_server_loop_10035_fun261(kk_function_t _fself, kk_box_t _b_x12, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x262;
  kk_string_t _x_x263 = kk_string_unbox(_b_x12); /*string*/
  _x_x262 = kk_src_hot__paths_extract_op(_x_x263, _ctx); /*string*/
  return kk_string_box(_x_x262);
}


// lift anonymous function
struct kk_src_hot__paths__mlift_server_loop_10035_fun268__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_hot__paths__mlift_server_loop_10035_fun268(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_src_hot__paths__new_mlift_server_loop_10035_fun268(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_hot__paths__mlift_server_loop_10035_fun268, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_hot__paths__mlift_server_loop_10035_fun268(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x269;
  kk_string_t _x_x270 = kk_string_unbox(_b_x17); /*string*/
  _x_x269 = kk_src_hot__paths_extract_name(_x_x270, _ctx); /*string*/
  return kk_string_box(_x_x269);
}


// lift anonymous function
struct kk_src_hot__paths__mlift_server_loop_10035_fun277__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_hot__paths__mlift_server_loop_10035_fun277(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static kk_function_t kk_src_hot__paths__new_mlift_server_loop_10035_fun277(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_hot__paths__mlift_server_loop_10035_fun277, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_hot__paths__mlift_server_loop_10035_fun277(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x278;
  kk_string_t _x_x279 = kk_string_unbox(_b_x22); /*string*/
  _x_x278 = kk_src_hot__paths_extract_name(_x_x279, _ctx); /*string*/
  return kk_string_box(_x_x278);
}


// lift anonymous function
struct kk_src_hot__paths__mlift_server_loop_10035_fun297__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_hot__paths__mlift_server_loop_10035_fun297(kk_function_t _fself, kk_box_t _b_x28, kk_box_t _b_x29, kk_context_t* _ctx);
static kk_function_t kk_src_hot__paths__new_mlift_server_loop_10035_fun297(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_hot__paths__mlift_server_loop_10035_fun297, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_hot__paths__mlift_server_loop_10035_fun297(kk_function_t _fself, kk_box_t _b_x28, kk_box_t _b_x29, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x298;
  double _x_x299 = kk_double_unbox(_b_x28, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x300 = kk_std_core_types__optional_unbox(_b_x29, KK_OWNED, _ctx); /*? int*/
  _x_x298 = kk_std_num_float64_show(_x_x299, _x_x300, _ctx); /*string*/
  return kk_string_box(_x_x298);
}


// lift anonymous function
struct kk_src_hot__paths__mlift_server_loop_10035_fun306__t {
  struct kk_function_s _base;
  kk_string_t op_0;
  kk_std_core_types__list profiles_0;
  kk_integer_t total_calls_0;
  double total_time_0;
};
static kk_box_t kk_src_hot__paths__mlift_server_loop_10035_fun306(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx);
static kk_function_t kk_src_hot__paths__new_mlift_server_loop_10035_fun306(kk_string_t op_0, kk_std_core_types__list profiles_0, kk_integer_t total_calls_0, double total_time_0, kk_context_t* _ctx) {
  struct kk_src_hot__paths__mlift_server_loop_10035_fun306__t* _self = kk_function_alloc_as(struct kk_src_hot__paths__mlift_server_loop_10035_fun306__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_hot__paths__mlift_server_loop_10035_fun306, kk_context());
  _self->op_0 = op_0;
  _self->profiles_0 = profiles_0;
  _self->total_calls_0 = total_calls_0;
  _self->total_time_0 = total_time_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_hot__paths__mlift_server_loop_10035_fun306(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx) {
  struct kk_src_hot__paths__mlift_server_loop_10035_fun306__t* _self = kk_function_as(struct kk_src_hot__paths__mlift_server_loop_10035_fun306__t*, _fself, _ctx);
  kk_string_t op_0 = _self->op_0; /* string */
  kk_std_core_types__list profiles_0 = _self->profiles_0; /* list<src/hot_paths/path-profile> */
  kk_integer_t total_calls_0 = _self->total_calls_0; /* int */
  double total_time_0 = _self->total_time_0; /* float64 */
  kk_drop_match(_self, {kk_string_dup(op_0, _ctx);kk_std_core_types__list_dup(profiles_0, _ctx);kk_integer_dup(total_calls_0, _ctx);kk_skip_dup(total_time_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10018_0_36 = kk_string_unbox(_b_x34); /*string*/;
  kk_unit_t _x_x307 = kk_Unit;
  kk_src_hot__paths__mlift_server_loop_10034(op_0, profiles_0, total_calls_0, total_time_0, _c_x10018_0_36, _ctx);
  return kk_unit_box(_x_x307);
}

kk_unit_t kk_src_hot__paths__mlift_server_loop_10035(kk_std_core_types__list profiles_0, kk_integer_t total_calls_0, double total_time_0, kk_string_t line, kk_context_t* _ctx) { /* (profiles : list<path-profile>, total-calls : int, total-time : float64, line : string) -> <console/console,exn> () */ 
  bool _match_x72;
  kk_string_t _x_x257 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x258 = kk_string_empty(); /*string*/
  _match_x72 = kk_string_is_neq(_x_x257,_x_x258,kk_context()); /*bool*/
  if (_match_x72) {
    kk_string_t op_0;
    kk_box_t _x_x260;
    kk_box_t _x_x264;
    kk_string_t _x_x265 = kk_string_dup(line, _ctx); /*string*/
    _x_x264 = kk_string_box(_x_x265); /*10000*/
    _x_x260 = kk_std_core_hnd__open_none1(kk_src_hot__paths__new_mlift_server_loop_10035_fun261(_ctx), _x_x264, _ctx); /*10001*/
    op_0 = kk_string_unbox(_x_x260); /*string*/
    kk_string_t x_10036;
    if (kk_string_cmp_cstr_borrow(op_0, "record", _ctx) == 0) {
      kk_string_t name;
      kk_box_t _x_x267 = kk_std_core_hnd__open_none1(kk_src_hot__paths__new_mlift_server_loop_10035_fun268(_ctx), kk_string_box(line), _ctx); /*10001*/
      name = kk_string_unbox(_x_x267); /*string*/
      kk_string_t _x_x271;
      kk_define_string_literal(, _s_x272, 29, "{\"status\":\"recorded\",\"name\":\"", _ctx)
      _x_x271 = kk_string_dup(_s_x272, _ctx); /*string*/
      kk_string_t _x_x273;
      kk_string_t _x_x274;
      kk_define_string_literal(, _s_x275, 2, "\"}", _ctx)
      _x_x274 = kk_string_dup(_s_x275, _ctx); /*string*/
      _x_x273 = kk_std_core_types__lp__plus__plus__rp_(name, _x_x274, _ctx); /*string*/
      x_10036 = kk_std_core_types__lp__plus__plus__rp_(_x_x271, _x_x273, _ctx); /*string*/
      goto _match_x266;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "profile", _ctx) == 0) {
      kk_string_t name_0;
      kk_box_t _x_x276 = kk_std_core_hnd__open_none1(kk_src_hot__paths__new_mlift_server_loop_10035_fun277(_ctx), kk_string_box(line), _ctx); /*10001*/
      name_0 = kk_string_unbox(_x_x276); /*string*/
      kk_string_t _x_x280;
      kk_define_string_literal(, _s_x281, 28, "{\"status\":\"profile\",\"name\":\"", _ctx)
      _x_x280 = kk_string_dup(_s_x281, _ctx); /*string*/
      kk_string_t _x_x282;
      kk_string_t _x_x283;
      kk_define_string_literal(, _s_x284, 2, "\"}", _ctx)
      _x_x283 = kk_string_dup(_s_x284, _ctx); /*string*/
      _x_x282 = kk_std_core_types__lp__plus__plus__rp_(name_0, _x_x283, _ctx); /*string*/
      x_10036 = kk_std_core_types__lp__plus__plus__rp_(_x_x280, _x_x282, _ctx); /*string*/
      goto _match_x266;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "hot", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x285, 36, "{\"hot_paths\":[],\"threshold_ms\":10.0}", _ctx)
      x_10036 = kk_string_dup(_s_x285, _ctx); /*string*/
      goto _match_x266;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_string_t _x_x286;
      kk_define_string_literal(, _s_x287, 29, "{\"status\":\"ok\",\"total_calls\":", _ctx)
      _x_x286 = kk_string_dup(_s_x287, _ctx); /*string*/
      kk_string_t _x_x288;
      kk_string_t _x_x289;
      kk_integer_t _x_x290 = kk_integer_dup(total_calls_0, _ctx); /*int*/
      _x_x289 = kk_std_core_int_show(_x_x290, _ctx); /*string*/
      kk_string_t _x_x291;
      kk_string_t _x_x292;
      kk_define_string_literal(, _s_x293, 17, ",\"total_time_ms\":", _ctx)
      _x_x292 = kk_string_dup(_s_x293, _ctx); /*string*/
      kk_string_t _x_x294;
      kk_string_t _x_x295;
      kk_box_t _x_x296 = kk_std_core_hnd__open_none2(kk_src_hot__paths__new_mlift_server_loop_10035_fun297(_ctx), kk_double_box(total_time_0, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
      _x_x295 = kk_string_unbox(_x_x296); /*string*/
      kk_string_t _x_x301;
      kk_define_string_literal(, _s_x302, 1, "}", _ctx)
      _x_x301 = kk_string_dup(_s_x302, _ctx); /*string*/
      _x_x294 = kk_std_core_types__lp__plus__plus__rp_(_x_x295, _x_x301, _ctx); /*string*/
      _x_x291 = kk_std_core_types__lp__plus__plus__rp_(_x_x292, _x_x294, _ctx); /*string*/
      _x_x288 = kk_std_core_types__lp__plus__plus__rp_(_x_x289, _x_x291, _ctx); /*string*/
      x_10036 = kk_std_core_types__lp__plus__plus__rp_(_x_x286, _x_x288, _ctx); /*string*/
      goto _match_x266;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "quit", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x303, 20, "{\"status\":\"stopped\"}", _ctx)
      x_10036 = kk_string_dup(_s_x303, _ctx); /*string*/
      goto _match_x266;
    }
    {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x304, 22, "{\"error\":\"unknown op\"}", _ctx)
      x_10036 = kk_string_dup(_s_x304, _ctx); /*string*/
    }
    _match_x266: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_10036, _ctx);
      kk_box_t _x_x305 = kk_std_core_hnd_yield_extend(kk_src_hot__paths__new_mlift_server_loop_10035_fun306(op_0, profiles_0, total_calls_0, total_time_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x305); return kk_Unit;
    }
    {
      kk_src_hot__paths__mlift_server_loop_10034(op_0, profiles_0, total_calls_0, total_time_0, x_10036, _ctx); return kk_Unit;
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
struct kk_src_hot__paths_server_loop_fun309__t {
  struct kk_function_s _base;
  kk_std_core_types__list profiles_1;
  kk_integer_t total_calls_1;
  double total_time_1;
};
static kk_box_t kk_src_hot__paths_server_loop_fun309(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx);
static kk_function_t kk_src_hot__paths_new_server_loop_fun309(kk_std_core_types__list profiles_1, kk_integer_t total_calls_1, double total_time_1, kk_context_t* _ctx) {
  struct kk_src_hot__paths_server_loop_fun309__t* _self = kk_function_alloc_as(struct kk_src_hot__paths_server_loop_fun309__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_hot__paths_server_loop_fun309, kk_context());
  _self->profiles_1 = profiles_1;
  _self->total_calls_1 = total_calls_1;
  _self->total_time_1 = total_time_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_hot__paths_server_loop_fun309(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx) {
  struct kk_src_hot__paths_server_loop_fun309__t* _self = kk_function_as(struct kk_src_hot__paths_server_loop_fun309__t*, _fself, _ctx);
  kk_std_core_types__list profiles_1 = _self->profiles_1; /* list<src/hot_paths/path-profile> */
  kk_integer_t total_calls_1 = _self->total_calls_1; /* int */
  double total_time_1 = _self->total_time_1; /* float64 */
  kk_drop_match(_self, {kk_std_core_types__list_dup(profiles_1, _ctx);kk_integer_dup(total_calls_1, _ctx);kk_skip_dup(total_time_1, _ctx);}, {}, _ctx)
  kk_string_t line_0_66 = kk_string_unbox(_b_x38); /*string*/;
  kk_unit_t _x_x310 = kk_Unit;
  kk_src_hot__paths__mlift_server_loop_10035(profiles_1, total_calls_1, total_time_1, line_0_66, _ctx);
  return kk_unit_box(_x_x310);
}


// lift anonymous function
struct kk_src_hot__paths_server_loop_fun315__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_hot__paths_server_loop_fun315(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx);
static kk_function_t kk_src_hot__paths_new_server_loop_fun315(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_hot__paths_server_loop_fun315, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_hot__paths_server_loop_fun315(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x316;
  kk_string_t _x_x317 = kk_string_unbox(_b_x41); /*string*/
  _x_x316 = kk_src_hot__paths_extract_op(_x_x317, _ctx); /*string*/
  return kk_string_box(_x_x316);
}


// lift anonymous function
struct kk_src_hot__paths_server_loop_fun322__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_hot__paths_server_loop_fun322(kk_function_t _fself, kk_box_t _b_x46, kk_context_t* _ctx);
static kk_function_t kk_src_hot__paths_new_server_loop_fun322(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_hot__paths_server_loop_fun322, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_hot__paths_server_loop_fun322(kk_function_t _fself, kk_box_t _b_x46, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x323;
  kk_string_t _x_x324 = kk_string_unbox(_b_x46); /*string*/
  _x_x323 = kk_src_hot__paths_extract_name(_x_x324, _ctx); /*string*/
  return kk_string_box(_x_x323);
}


// lift anonymous function
struct kk_src_hot__paths_server_loop_fun331__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_hot__paths_server_loop_fun331(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx);
static kk_function_t kk_src_hot__paths_new_server_loop_fun331(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_hot__paths_server_loop_fun331, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_hot__paths_server_loop_fun331(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x332;
  kk_string_t _x_x333 = kk_string_unbox(_b_x51); /*string*/
  _x_x332 = kk_src_hot__paths_extract_name(_x_x333, _ctx); /*string*/
  return kk_string_box(_x_x332);
}


// lift anonymous function
struct kk_src_hot__paths_server_loop_fun351__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_hot__paths_server_loop_fun351(kk_function_t _fself, kk_box_t _b_x57, kk_box_t _b_x58, kk_context_t* _ctx);
static kk_function_t kk_src_hot__paths_new_server_loop_fun351(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_hot__paths_server_loop_fun351, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_hot__paths_server_loop_fun351(kk_function_t _fself, kk_box_t _b_x57, kk_box_t _b_x58, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x352;
  double _x_x353 = kk_double_unbox(_b_x57, KK_OWNED, _ctx); /*float64*/
  kk_std_core_types__optional _x_x354 = kk_std_core_types__optional_unbox(_b_x58, KK_OWNED, _ctx); /*? int*/
  _x_x352 = kk_std_num_float64_show(_x_x353, _x_x354, _ctx); /*string*/
  return kk_string_box(_x_x352);
}


// lift anonymous function
struct kk_src_hot__paths_server_loop_fun360__t {
  struct kk_function_s _base;
  kk_string_t op_1;
  kk_std_core_types__list profiles_1;
  kk_integer_t total_calls_1;
  double total_time_1;
};
static kk_box_t kk_src_hot__paths_server_loop_fun360(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx);
static kk_function_t kk_src_hot__paths_new_server_loop_fun360(kk_string_t op_1, kk_std_core_types__list profiles_1, kk_integer_t total_calls_1, double total_time_1, kk_context_t* _ctx) {
  struct kk_src_hot__paths_server_loop_fun360__t* _self = kk_function_alloc_as(struct kk_src_hot__paths_server_loop_fun360__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_hot__paths_server_loop_fun360, kk_context());
  _self->op_1 = op_1;
  _self->profiles_1 = profiles_1;
  _self->total_calls_1 = total_calls_1;
  _self->total_time_1 = total_time_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_hot__paths_server_loop_fun360(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx) {
  struct kk_src_hot__paths_server_loop_fun360__t* _self = kk_function_as(struct kk_src_hot__paths_server_loop_fun360__t*, _fself, _ctx);
  kk_string_t op_1 = _self->op_1; /* string */
  kk_std_core_types__list profiles_1 = _self->profiles_1; /* list<src/hot_paths/path-profile> */
  kk_integer_t total_calls_1 = _self->total_calls_1; /* int */
  double total_time_1 = _self->total_time_1; /* float64 */
  kk_drop_match(_self, {kk_string_dup(op_1, _ctx);kk_std_core_types__list_dup(profiles_1, _ctx);kk_integer_dup(total_calls_1, _ctx);kk_skip_dup(total_time_1, _ctx);}, {}, _ctx)
  kk_string_t _c_x10018_1_67 = kk_string_unbox(_b_x63); /*string*/;
  kk_unit_t _x_x361 = kk_Unit;
  kk_src_hot__paths__mlift_server_loop_10034(op_1, profiles_1, total_calls_1, total_time_1, _c_x10018_1_67, _ctx);
  return kk_unit_box(_x_x361);
}

kk_unit_t kk_src_hot__paths_server_loop(kk_integer_t total_calls_1, double total_time_1, kk_std_core_types__list profiles_1, kk_context_t* _ctx) { /* (total-calls : int, total-time : float64, profiles : list<path-profile>) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_0_10038 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10038, _ctx);
    kk_box_t _x_x308 = kk_std_core_hnd_yield_extend(kk_src_hot__paths_new_server_loop_fun309(profiles_1, total_calls_1, total_time_1, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x308); return kk_Unit;
  }
  {
    bool _match_x69;
    kk_string_t _x_x311 = kk_string_dup(x_0_10038, _ctx); /*string*/
    kk_string_t _x_x312 = kk_string_empty(); /*string*/
    _match_x69 = kk_string_is_neq(_x_x311,_x_x312,kk_context()); /*bool*/
    if (_match_x69) {
      kk_string_t op_1;
      kk_box_t _x_x314;
      kk_box_t _x_x318;
      kk_string_t _x_x319 = kk_string_dup(x_0_10038, _ctx); /*string*/
      _x_x318 = kk_string_box(_x_x319); /*10000*/
      _x_x314 = kk_std_core_hnd__open_none1(kk_src_hot__paths_new_server_loop_fun315(_ctx), _x_x318, _ctx); /*10001*/
      op_1 = kk_string_unbox(_x_x314); /*string*/
      kk_string_t x_1_10041;
      if (kk_string_cmp_cstr_borrow(op_1, "record", _ctx) == 0) {
        kk_string_t name_1;
        kk_box_t _x_x321 = kk_std_core_hnd__open_none1(kk_src_hot__paths_new_server_loop_fun322(_ctx), kk_string_box(x_0_10038), _ctx); /*10001*/
        name_1 = kk_string_unbox(_x_x321); /*string*/
        kk_string_t _x_x325;
        kk_define_string_literal(, _s_x326, 29, "{\"status\":\"recorded\",\"name\":\"", _ctx)
        _x_x325 = kk_string_dup(_s_x326, _ctx); /*string*/
        kk_string_t _x_x327;
        kk_string_t _x_x328;
        kk_define_string_literal(, _s_x329, 2, "\"}", _ctx)
        _x_x328 = kk_string_dup(_s_x329, _ctx); /*string*/
        _x_x327 = kk_std_core_types__lp__plus__plus__rp_(name_1, _x_x328, _ctx); /*string*/
        x_1_10041 = kk_std_core_types__lp__plus__plus__rp_(_x_x325, _x_x327, _ctx); /*string*/
        goto _match_x320;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "profile", _ctx) == 0) {
        kk_string_t name_0_0;
        kk_box_t _x_x330 = kk_std_core_hnd__open_none1(kk_src_hot__paths_new_server_loop_fun331(_ctx), kk_string_box(x_0_10038), _ctx); /*10001*/
        name_0_0 = kk_string_unbox(_x_x330); /*string*/
        kk_string_t _x_x334;
        kk_define_string_literal(, _s_x335, 28, "{\"status\":\"profile\",\"name\":\"", _ctx)
        _x_x334 = kk_string_dup(_s_x335, _ctx); /*string*/
        kk_string_t _x_x336;
        kk_string_t _x_x337;
        kk_define_string_literal(, _s_x338, 2, "\"}", _ctx)
        _x_x337 = kk_string_dup(_s_x338, _ctx); /*string*/
        _x_x336 = kk_std_core_types__lp__plus__plus__rp_(name_0_0, _x_x337, _ctx); /*string*/
        x_1_10041 = kk_std_core_types__lp__plus__plus__rp_(_x_x334, _x_x336, _ctx); /*string*/
        goto _match_x320;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "hot", _ctx) == 0) {
        kk_string_drop(x_0_10038, _ctx);
        kk_define_string_literal(, _s_x339, 36, "{\"hot_paths\":[],\"threshold_ms\":10.0}", _ctx)
        x_1_10041 = kk_string_dup(_s_x339, _ctx); /*string*/
        goto _match_x320;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
        kk_string_drop(x_0_10038, _ctx);
        kk_string_t _x_x340;
        kk_define_string_literal(, _s_x341, 29, "{\"status\":\"ok\",\"total_calls\":", _ctx)
        _x_x340 = kk_string_dup(_s_x341, _ctx); /*string*/
        kk_string_t _x_x342;
        kk_string_t _x_x343;
        kk_integer_t _x_x344 = kk_integer_dup(total_calls_1, _ctx); /*int*/
        _x_x343 = kk_std_core_int_show(_x_x344, _ctx); /*string*/
        kk_string_t _x_x345;
        kk_string_t _x_x346;
        kk_define_string_literal(, _s_x347, 17, ",\"total_time_ms\":", _ctx)
        _x_x346 = kk_string_dup(_s_x347, _ctx); /*string*/
        kk_string_t _x_x348;
        kk_string_t _x_x349;
        kk_box_t _x_x350 = kk_std_core_hnd__open_none2(kk_src_hot__paths_new_server_loop_fun351(_ctx), kk_double_box(total_time_1, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
        _x_x349 = kk_string_unbox(_x_x350); /*string*/
        kk_string_t _x_x355;
        kk_define_string_literal(, _s_x356, 1, "}", _ctx)
        _x_x355 = kk_string_dup(_s_x356, _ctx); /*string*/
        _x_x348 = kk_std_core_types__lp__plus__plus__rp_(_x_x349, _x_x355, _ctx); /*string*/
        _x_x345 = kk_std_core_types__lp__plus__plus__rp_(_x_x346, _x_x348, _ctx); /*string*/
        _x_x342 = kk_std_core_types__lp__plus__plus__rp_(_x_x343, _x_x345, _ctx); /*string*/
        x_1_10041 = kk_std_core_types__lp__plus__plus__rp_(_x_x340, _x_x342, _ctx); /*string*/
        goto _match_x320;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "quit", _ctx) == 0) {
        kk_string_drop(x_0_10038, _ctx);
        kk_define_string_literal(, _s_x357, 20, "{\"status\":\"stopped\"}", _ctx)
        x_1_10041 = kk_string_dup(_s_x357, _ctx); /*string*/
        goto _match_x320;
      }
      {
        kk_string_drop(x_0_10038, _ctx);
        kk_define_string_literal(, _s_x358, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_1_10041 = kk_string_dup(_s_x358, _ctx); /*string*/
      }
      _match_x320: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_1_10041, _ctx);
        kk_box_t _x_x359 = kk_std_core_hnd_yield_extend(kk_src_hot__paths_new_server_loop_fun360(op_1, profiles_1, total_calls_1, total_time_1, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x359); return kk_Unit;
      }
      {
        kk_unit_t ___0 = kk_Unit;
        kk_std_core_console_printsln(x_1_10041, _ctx);
        bool _match_x71;
        kk_string_t _x_x362;
        kk_define_string_literal(, _s_x363, 4, "quit", _ctx)
        _x_x362 = kk_string_dup(_s_x363, _ctx); /*string*/
        _match_x71 = kk_string_is_neq(op_1,_x_x362,kk_context()); /*bool*/
        if (_match_x71) { // tailcall
                          kk_integer_t _x_x364 = kk_integer_add_small_const(total_calls_1, 1, _ctx); /*int*/
                          double _x_x365 = (total_time_1 + 0x1p0); /*float64*/
                          total_calls_1 = _x_x364;
                          total_time_1 = _x_x365;
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
      kk_string_drop(x_0_10038, _ctx);
      kk_integer_drop(total_calls_1, _ctx);
      kk_std_core_types__list_drop(profiles_1, _ctx);
      kk_Unit; return kk_Unit;
    }
  }
}

// initialization
void kk_src_hot__paths__init(kk_context_t* _ctx){
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
void kk_src_hot__paths__done(kk_context_t* _ctx){
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
