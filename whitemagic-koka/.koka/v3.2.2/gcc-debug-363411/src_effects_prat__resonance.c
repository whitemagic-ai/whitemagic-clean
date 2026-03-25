// Koka generated module: src/effects/prat_resonance, koka version: 3.2.2, platform: 64-bit
#include "src_effects_prat__resonance.h"
 
// runtime tag for the effect `:resonance`

kk_std_core_hnd__htag kk_src_effects_prat__resonance_resonance_fs__tag;
 
// handler for the effect `:resonance`

kk_box_t kk_src_effects_prat__resonance_resonance_fs__handle(kk_src_effects_prat__resonance__resonance hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : resonance<e,b>, ret : (res : a) -> e b, action : () -> <resonance|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x947 = kk_std_core_hnd__htag_dup(kk_src_effects_prat__resonance_resonance_fs__tag, _ctx); /*hnd/htag<src/effects/prat_resonance/resonance>*/
  return kk_std_core_hnd__hhandle(_x_x947, kk_src_effects_prat__resonance__resonance_box(hnd, _ctx), ret, action, _ctx);
}

kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance_snapshot_fs__copy(kk_src_effects_prat__resonance__snapshot _this, kk_std_core_types__optional gana_name, kk_std_core_types__optional tool_name, kk_std_core_types__optional operation, kk_std_core_types__optional output_preview, kk_std_core_types__optional timestamp, kk_std_core_types__optional lunar_phase, kk_std_core_types__optional lunar_mansion_num, kk_std_core_types__optional harmony_score, kk_std_core_types__optional guna_tag, kk_std_core_types__optional quadrant, kk_std_core_types__optional successor_hint, kk_context_t* _ctx) { /* (snapshot, gana-name : ? string, tool-name : ? string, operation : ? string, output-preview : ? string, timestamp : ? float64, lunar-phase : ? float64, lunar-mansion-num : ? int, harmony-score : ? float64, guna-tag : ? string, quadrant : ? string, successor-hint : ? string) -> snapshot */ 
  kk_string_t _x_x1009;
  if (kk_std_core_types__is_Optional(gana_name, _ctx)) {
    kk_box_t _box_x72 = gana_name._cons._Optional.value;
    kk_string_t _uniq_gana_name_1461 = kk_string_unbox(_box_x72);
    kk_string_dup(_uniq_gana_name_1461, _ctx);
    kk_std_core_types__optional_drop(gana_name, _ctx);
    _x_x1009 = _uniq_gana_name_1461; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(gana_name, _ctx);
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1010 = kk_src_effects_prat__resonance__as_Snapshot(_this, _ctx);
      kk_string_t _x = _con_x1010->gana_name;
      kk_string_dup(_x, _ctx);
      _x_x1009 = _x; /*string*/
    }
  }
  kk_string_t _x_x1011;
  if (kk_std_core_types__is_Optional(tool_name, _ctx)) {
    kk_box_t _box_x73 = tool_name._cons._Optional.value;
    kk_string_t _uniq_tool_name_1469 = kk_string_unbox(_box_x73);
    kk_string_dup(_uniq_tool_name_1469, _ctx);
    kk_std_core_types__optional_drop(tool_name, _ctx);
    _x_x1011 = _uniq_tool_name_1469; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(tool_name, _ctx);
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1012 = kk_src_effects_prat__resonance__as_Snapshot(_this, _ctx);
      kk_string_t _x_0 = _con_x1012->tool_name;
      kk_string_dup(_x_0, _ctx);
      _x_x1011 = _x_0; /*string*/
    }
  }
  kk_string_t _x_x1013;
  if (kk_std_core_types__is_Optional(operation, _ctx)) {
    kk_box_t _box_x74 = operation._cons._Optional.value;
    kk_string_t _uniq_operation_1477 = kk_string_unbox(_box_x74);
    kk_string_dup(_uniq_operation_1477, _ctx);
    kk_std_core_types__optional_drop(operation, _ctx);
    _x_x1013 = _uniq_operation_1477; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(operation, _ctx);
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1014 = kk_src_effects_prat__resonance__as_Snapshot(_this, _ctx);
      kk_string_t _x_1 = _con_x1014->operation;
      kk_string_dup(_x_1, _ctx);
      _x_x1013 = _x_1; /*string*/
    }
  }
  kk_string_t _x_x1015;
  if (kk_std_core_types__is_Optional(output_preview, _ctx)) {
    kk_box_t _box_x75 = output_preview._cons._Optional.value;
    kk_string_t _uniq_output_preview_1485 = kk_string_unbox(_box_x75);
    kk_string_dup(_uniq_output_preview_1485, _ctx);
    kk_std_core_types__optional_drop(output_preview, _ctx);
    _x_x1015 = _uniq_output_preview_1485; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(output_preview, _ctx);
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1016 = kk_src_effects_prat__resonance__as_Snapshot(_this, _ctx);
      kk_string_t _x_2 = _con_x1016->output_preview;
      kk_string_dup(_x_2, _ctx);
      _x_x1015 = _x_2; /*string*/
    }
  }
  double _x_x1017;
  if (kk_std_core_types__is_Optional(timestamp, _ctx)) {
    kk_box_t _box_x76 = timestamp._cons._Optional.value;
    double _uniq_timestamp_1493 = kk_double_unbox(_box_x76, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(timestamp, _ctx);
    _x_x1017 = _uniq_timestamp_1493; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(timestamp, _ctx);
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1018 = kk_src_effects_prat__resonance__as_Snapshot(_this, _ctx);
      double _x_3 = _con_x1018->timestamp;
      _x_x1017 = _x_3; /*float64*/
    }
  }
  double _x_x1019;
  if (kk_std_core_types__is_Optional(lunar_phase, _ctx)) {
    kk_box_t _box_x77 = lunar_phase._cons._Optional.value;
    double _uniq_lunar_phase_1501 = kk_double_unbox(_box_x77, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(lunar_phase, _ctx);
    _x_x1019 = _uniq_lunar_phase_1501; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(lunar_phase, _ctx);
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1020 = kk_src_effects_prat__resonance__as_Snapshot(_this, _ctx);
      double _x_4 = _con_x1020->lunar_phase;
      _x_x1019 = _x_4; /*float64*/
    }
  }
  kk_integer_t _x_x1021;
  if (kk_std_core_types__is_Optional(lunar_mansion_num, _ctx)) {
    kk_box_t _box_x78 = lunar_mansion_num._cons._Optional.value;
    kk_integer_t _uniq_lunar_mansion_num_1509 = kk_integer_unbox(_box_x78, _ctx);
    kk_integer_dup(_uniq_lunar_mansion_num_1509, _ctx);
    kk_std_core_types__optional_drop(lunar_mansion_num, _ctx);
    _x_x1021 = _uniq_lunar_mansion_num_1509; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(lunar_mansion_num, _ctx);
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1022 = kk_src_effects_prat__resonance__as_Snapshot(_this, _ctx);
      kk_integer_t _x_5 = _con_x1022->lunar_mansion_num;
      kk_integer_dup(_x_5, _ctx);
      _x_x1021 = _x_5; /*int*/
    }
  }
  double _x_x1023;
  if (kk_std_core_types__is_Optional(harmony_score, _ctx)) {
    kk_box_t _box_x79 = harmony_score._cons._Optional.value;
    double _uniq_harmony_score_1517 = kk_double_unbox(_box_x79, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(harmony_score, _ctx);
    _x_x1023 = _uniq_harmony_score_1517; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(harmony_score, _ctx);
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1024 = kk_src_effects_prat__resonance__as_Snapshot(_this, _ctx);
      double _x_6 = _con_x1024->harmony_score;
      _x_x1023 = _x_6; /*float64*/
    }
  }
  kk_string_t _x_x1025;
  if (kk_std_core_types__is_Optional(guna_tag, _ctx)) {
    kk_box_t _box_x80 = guna_tag._cons._Optional.value;
    kk_string_t _uniq_guna_tag_1525 = kk_string_unbox(_box_x80);
    kk_string_dup(_uniq_guna_tag_1525, _ctx);
    kk_std_core_types__optional_drop(guna_tag, _ctx);
    _x_x1025 = _uniq_guna_tag_1525; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(guna_tag, _ctx);
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1026 = kk_src_effects_prat__resonance__as_Snapshot(_this, _ctx);
      kk_string_t _x_7 = _con_x1026->guna_tag;
      kk_string_dup(_x_7, _ctx);
      _x_x1025 = _x_7; /*string*/
    }
  }
  kk_string_t _x_x1027;
  if (kk_std_core_types__is_Optional(quadrant, _ctx)) {
    kk_box_t _box_x81 = quadrant._cons._Optional.value;
    kk_string_t _uniq_quadrant_1533 = kk_string_unbox(_box_x81);
    kk_string_dup(_uniq_quadrant_1533, _ctx);
    kk_std_core_types__optional_drop(quadrant, _ctx);
    _x_x1027 = _uniq_quadrant_1533; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(quadrant, _ctx);
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1028 = kk_src_effects_prat__resonance__as_Snapshot(_this, _ctx);
      kk_string_t _x_8 = _con_x1028->quadrant;
      kk_string_dup(_x_8, _ctx);
      _x_x1027 = _x_8; /*string*/
    }
  }
  kk_string_t _x_x1029;
  if (kk_std_core_types__is_Optional(successor_hint, _ctx)) {
    kk_box_t _box_x82 = successor_hint._cons._Optional.value;
    kk_string_t _uniq_successor_hint_1541 = kk_string_unbox(_box_x82);
    kk_string_dup(_uniq_successor_hint_1541, _ctx);
    kk_std_core_types__optional_drop(successor_hint, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(8)), _ctx);
    _x_x1029 = _uniq_successor_hint_1541; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(successor_hint, _ctx);
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1030 = kk_src_effects_prat__resonance__as_Snapshot(_this, _ctx);
      kk_string_t _pat_0_10 = _con_x1030->gana_name;
      kk_string_t _pat_1_11 = _con_x1030->tool_name;
      kk_string_t _pat_2_10 = _con_x1030->operation;
      kk_string_t _pat_3_10 = _con_x1030->output_preview;
      kk_integer_t _pat_6_10 = _con_x1030->lunar_mansion_num;
      kk_string_t _pat_8_10 = _con_x1030->guna_tag;
      kk_string_t _pat_9_10 = _con_x1030->quadrant;
      kk_string_t _x_9 = _con_x1030->successor_hint;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_9_10, _ctx);
        kk_string_drop(_pat_8_10, _ctx);
        kk_integer_drop(_pat_6_10, _ctx);
        kk_string_drop(_pat_3_10, _ctx);
        kk_string_drop(_pat_2_10, _ctx);
        kk_string_drop(_pat_1_11, _ctx);
        kk_string_drop(_pat_0_10, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_string_dup(_x_9, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1029 = _x_9; /*string*/
    }
  }
  return kk_src_effects_prat__resonance__new_Snapshot(kk_reuse_null, 0, _x_x1009, _x_x1011, _x_x1013, _x_x1015, _x_x1017, _x_x1019, _x_x1021, _x_x1023, _x_x1025, _x_x1027, _x_x1029, _ctx);
}

kk_src_effects_prat__resonance__ganainfo kk_src_effects_prat__resonance_ganainfo_fs__copy(kk_src_effects_prat__resonance__ganainfo _this, kk_std_core_types__optional mansion_num, kk_std_core_types__optional quadrant, kk_std_core_types__optional meaning, kk_std_core_types__optional garden, kk_std_core_types__optional chinese, kk_std_core_types__optional pinyin, kk_context_t* _ctx) { /* (ganainfo, mansion-num : ? int, quadrant : ? string, meaning : ? string, garden : ? string, chinese : ? string, pinyin : ? string) -> ganainfo */ 
  kk_integer_t _x_x1037;
  if (kk_std_core_types__is_Optional(mansion_num, _ctx)) {
    kk_box_t _box_x83 = mansion_num._cons._Optional.value;
    kk_integer_t _uniq_mansion_num_1615 = kk_integer_unbox(_box_x83, _ctx);
    kk_integer_dup(_uniq_mansion_num_1615, _ctx);
    kk_std_core_types__optional_drop(mansion_num, _ctx);
    _x_x1037 = _uniq_mansion_num_1615; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(mansion_num, _ctx);
    {
      struct kk_src_effects_prat__resonance_Ganainfo* _con_x1038 = kk_src_effects_prat__resonance__as_Ganainfo(_this, _ctx);
      kk_integer_t _x = _con_x1038->mansion_num;
      kk_integer_dup(_x, _ctx);
      _x_x1037 = _x; /*int*/
    }
  }
  kk_string_t _x_x1039;
  if (kk_std_core_types__is_Optional(quadrant, _ctx)) {
    kk_box_t _box_x84 = quadrant._cons._Optional.value;
    kk_string_t _uniq_quadrant_1623 = kk_string_unbox(_box_x84);
    kk_string_dup(_uniq_quadrant_1623, _ctx);
    kk_std_core_types__optional_drop(quadrant, _ctx);
    _x_x1039 = _uniq_quadrant_1623; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(quadrant, _ctx);
    {
      struct kk_src_effects_prat__resonance_Ganainfo* _con_x1040 = kk_src_effects_prat__resonance__as_Ganainfo(_this, _ctx);
      kk_string_t _x_0 = _con_x1040->quadrant;
      kk_string_dup(_x_0, _ctx);
      _x_x1039 = _x_0; /*string*/
    }
  }
  kk_string_t _x_x1041;
  if (kk_std_core_types__is_Optional(meaning, _ctx)) {
    kk_box_t _box_x85 = meaning._cons._Optional.value;
    kk_string_t _uniq_meaning_1631 = kk_string_unbox(_box_x85);
    kk_string_dup(_uniq_meaning_1631, _ctx);
    kk_std_core_types__optional_drop(meaning, _ctx);
    _x_x1041 = _uniq_meaning_1631; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(meaning, _ctx);
    {
      struct kk_src_effects_prat__resonance_Ganainfo* _con_x1042 = kk_src_effects_prat__resonance__as_Ganainfo(_this, _ctx);
      kk_string_t _x_1 = _con_x1042->meaning;
      kk_string_dup(_x_1, _ctx);
      _x_x1041 = _x_1; /*string*/
    }
  }
  kk_string_t _x_x1043;
  if (kk_std_core_types__is_Optional(garden, _ctx)) {
    kk_box_t _box_x86 = garden._cons._Optional.value;
    kk_string_t _uniq_garden_1639 = kk_string_unbox(_box_x86);
    kk_string_dup(_uniq_garden_1639, _ctx);
    kk_std_core_types__optional_drop(garden, _ctx);
    _x_x1043 = _uniq_garden_1639; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(garden, _ctx);
    {
      struct kk_src_effects_prat__resonance_Ganainfo* _con_x1044 = kk_src_effects_prat__resonance__as_Ganainfo(_this, _ctx);
      kk_string_t _x_2 = _con_x1044->garden;
      kk_string_dup(_x_2, _ctx);
      _x_x1043 = _x_2; /*string*/
    }
  }
  kk_string_t _x_x1045;
  if (kk_std_core_types__is_Optional(chinese, _ctx)) {
    kk_box_t _box_x87 = chinese._cons._Optional.value;
    kk_string_t _uniq_chinese_1647 = kk_string_unbox(_box_x87);
    kk_string_dup(_uniq_chinese_1647, _ctx);
    kk_std_core_types__optional_drop(chinese, _ctx);
    _x_x1045 = _uniq_chinese_1647; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(chinese, _ctx);
    {
      struct kk_src_effects_prat__resonance_Ganainfo* _con_x1046 = kk_src_effects_prat__resonance__as_Ganainfo(_this, _ctx);
      kk_string_t _x_3 = _con_x1046->chinese;
      kk_string_dup(_x_3, _ctx);
      _x_x1045 = _x_3; /*string*/
    }
  }
  kk_string_t _x_x1047;
  if (kk_std_core_types__is_Optional(pinyin, _ctx)) {
    kk_box_t _box_x88 = pinyin._cons._Optional.value;
    kk_string_t _uniq_pinyin_1655 = kk_string_unbox(_box_x88);
    kk_string_dup(_uniq_pinyin_1655, _ctx);
    kk_std_core_types__optional_drop(pinyin, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(6)), _ctx);
    _x_x1047 = _uniq_pinyin_1655; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(pinyin, _ctx);
    {
      struct kk_src_effects_prat__resonance_Ganainfo* _con_x1048 = kk_src_effects_prat__resonance__as_Ganainfo(_this, _ctx);
      kk_integer_t _pat_0_5 = _con_x1048->mansion_num;
      kk_string_t _pat_1_6 = _con_x1048->quadrant;
      kk_string_t _pat_2_5 = _con_x1048->meaning;
      kk_string_t _pat_3_5 = _con_x1048->garden;
      kk_string_t _pat_4_5 = _con_x1048->chinese;
      kk_string_t _x_4 = _con_x1048->pinyin;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_4_5, _ctx);
        kk_string_drop(_pat_3_5, _ctx);
        kk_string_drop(_pat_2_5, _ctx);
        kk_string_drop(_pat_1_6, _ctx);
        kk_integer_drop(_pat_0_5, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_string_dup(_x_4, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1047 = _x_4; /*string*/
    }
  }
  return kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, _x_x1037, _x_x1039, _x_x1041, _x_x1043, _x_x1045, _x_x1047, _ctx);
}

kk_std_core_types__list kk_src_effects_prat__resonance_gana_metadata;

kk_std_core_types__list kk_src_effects_prat__resonance_gana_order;


// lift anonymous function
struct kk_src_effects_prat__resonance_get_gana_meta_fun1665__t {
  struct kk_function_s _base;
  kk_string_t gana_name;
};
static bool kk_src_effects_prat__resonance_get_gana_meta_fun1665(kk_function_t _fself, kk_box_t _b_x429, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_get_gana_meta_fun1665(kk_string_t gana_name, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_get_gana_meta_fun1665__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_get_gana_meta_fun1665__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_get_gana_meta_fun1665, kk_context());
  _self->gana_name = gana_name;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_src_effects_prat__resonance_get_gana_meta_fun1665(kk_function_t _fself, kk_box_t _b_x429, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_get_gana_meta_fun1665__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_get_gana_meta_fun1665__t*, _fself, _ctx);
  kk_string_t gana_name = _self->gana_name; /* string */
  kk_drop_match(_self, {kk_string_dup(gana_name, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 p_435 = kk_std_core_types__tuple2_unbox(_b_x429, KK_OWNED, _ctx); /*(string, src/effects/prat_resonance/ganainfo)*/;
  kk_string_t _x_x1666;
  {
    kk_box_t _box_x425 = p_435.fst;
    kk_box_t _box_x426 = p_435.snd;
    kk_string_t _x = kk_string_unbox(_box_x425);
    kk_string_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(p_435, _ctx);
    _x_x1666 = _x; /*string*/
  }
  return kk_string_is_eq(_x_x1666,gana_name,kk_context());
}

kk_src_effects_prat__resonance__ganainfo kk_src_effects_prat__resonance_get_gana_meta(kk_string_t gana_name, kk_context_t* _ctx) { /* (gana-name : string) -> ganainfo */ 
  kk_std_core_types__maybe _match_x879;
  kk_std_core_types__list _x_x1663 = kk_std_core_types__list_dup(kk_src_effects_prat__resonance_gana_metadata, _ctx); /*list<(string, src/effects/prat_resonance/ganainfo)>*/
  kk_function_t _x_x1664;
  kk_string_dup(gana_name, _ctx);
  _x_x1664 = kk_src_effects_prat__resonance_new_get_gana_meta_fun1665(gana_name, _ctx); /*(10001) -> 10002 bool*/
  _match_x879 = kk_std_core_list_find(_x_x1663, _x_x1664, _ctx); /*maybe<10001>*/
  if (kk_std_core_types__is_Just(_match_x879, _ctx)) {
    kk_box_t _box_x430 = _match_x879._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0 = kk_std_core_types__tuple2_unbox(_box_x430, KK_BORROWED, _ctx);
    kk_box_t _box_x431 = _pat_0_0.fst;
    kk_box_t _box_x432 = _pat_0_0.snd;
    kk_src_effects_prat__resonance__ganainfo meta = kk_src_effects_prat__resonance__ganainfo_unbox(_box_x432, KK_BORROWED, _ctx);
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x1667 = kk_src_effects_prat__resonance__as_Ganainfo(meta, _ctx);
    kk_string_drop(gana_name, _ctx);
    kk_src_effects_prat__resonance__ganainfo_dup(meta, _ctx);
    kk_std_core_types__maybe_drop(_match_x879, _ctx);
    return meta;
  }
  {
    kk_string_t _x_x1668;
    kk_define_string_literal(, _s_x1669, 7, "Unknown", _ctx)
    _x_x1668 = kk_string_dup(_s_x1669, _ctx); /*string*/
    kk_string_t _x_x1670;
    kk_define_string_literal(, _s_x1671, 4, "None", _ctx)
    _x_x1670 = kk_string_dup(_s_x1671, _ctx); /*string*/
    kk_string_t _x_x1672;
    kk_define_string_literal(, _s_x1673, 1, "\?", _ctx)
    _x_x1672 = kk_string_dup(_s_x1673, _ctx); /*string*/
    kk_string_t _x_x1674;
    kk_define_string_literal(, _s_x1675, 1, "\?", _ctx)
    _x_x1674 = kk_string_dup(_s_x1675, _ctx); /*string*/
    return kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(0), _x_x1668, gana_name, _x_x1670, _x_x1672, _x_x1674, _ctx);
  }
}


// lift anonymous function
struct kk_src_effects_prat__resonance_get_predecessor_fun1677__t {
  struct kk_function_s _base;
  kk_string_t gana_name;
};
static bool kk_src_effects_prat__resonance_get_predecessor_fun1677(kk_function_t _fself, kk_box_t _b_x438, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_get_predecessor_fun1677(kk_string_t gana_name, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_get_predecessor_fun1677__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_get_predecessor_fun1677__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_get_predecessor_fun1677, kk_context());
  _self->gana_name = gana_name;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_src_effects_prat__resonance_get_predecessor_fun1677(kk_function_t _fself, kk_box_t _b_x438, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_get_predecessor_fun1677__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_get_predecessor_fun1677__t*, _fself, _ctx);
  kk_string_t gana_name = _self->gana_name; /* string */
  kk_drop_match(_self, {kk_string_dup(gana_name, _ctx);}, {}, _ctx)
  kk_string_t _x_x1678 = kk_string_unbox(_b_x438); /*string*/
  return kk_string_is_eq(_x_x1678,gana_name,kk_context());
}

kk_string_t kk_src_effects_prat__resonance_get_predecessor(kk_string_t gana_name, kk_context_t* _ctx) { /* (gana-name : string) -> string */ 
  kk_integer_t idx;
  kk_std_core_types__list _x_x1676 = kk_std_core_types__list_dup(kk_src_effects_prat__resonance_gana_order, _ctx); /*list<string>*/
  idx = kk_std_core_list_index_of(_x_x1676, kk_src_effects_prat__resonance_new_get_predecessor_fun1677(gana_name, _ctx), _ctx); /*int*/
  bool _match_x877 = kk_integer_gte_borrow(idx,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x877) {
    kk_integer_t x_0_10019 = kk_integer_add_small_const(idx, -1, _ctx); /*int*/;
    kk_std_core_types__list xs_10018;
    kk_std_core_types__list _x_x1679 = kk_std_core_types__list_dup(kk_src_effects_prat__resonance_gana_order, _ctx); /*list<string>*/
    kk_integer_t _x_x1680;
    kk_integer_t _x_x1681 = kk_integer_add_small_const(x_0_10019, 28, _ctx); /*int*/
    _x_x1680 = kk_integer_mod(_x_x1681,(kk_integer_from_small(28)),kk_context()); /*int*/
    xs_10018 = kk_std_core_list_drop(_x_x1679, _x_x1680, _ctx); /*list<string>*/
    if (kk_std_core_types__is_Cons(xs_10018, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1682 = kk_std_core_types__as_Cons(xs_10018, _ctx);
      kk_box_t _box_x442 = _con_x1682->head;
      kk_std_core_types__list _pat_0_0 = _con_x1682->tail;
      kk_string_t x = kk_string_unbox(_box_x442);
      if kk_likely(kk_datatype_ptr_is_unique(xs_10018, _ctx)) {
        kk_std_core_types__list_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(xs_10018, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_10018, _ctx);
      }
      return x;
    }
    {
      kk_std_core_types__maybe _match_x878 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/;
      if (kk_std_core_types__is_Just(_match_x878, _ctx)) {
        kk_box_t _box_x443 = _match_x878._cons.Just.value;
        kk_string_t g_0 = kk_string_unbox(_box_x443);
        kk_string_dup(g_0, _ctx);
        kk_std_core_types__maybe_drop(_match_x878, _ctx);
        return g_0;
      }
      {
        kk_define_string_literal(, _s_x1683, 9, "gana_horn", _ctx)
        return kk_string_dup(_s_x1683, _ctx);
      }
    }
  }
  {
    kk_integer_drop(idx, _ctx);
    kk_define_string_literal(, _s_x1684, 9, "gana_horn", _ctx)
    return kk_string_dup(_s_x1684, _ctx);
  }
}


// lift anonymous function
struct kk_src_effects_prat__resonance_get_successor_fun1686__t {
  struct kk_function_s _base;
  kk_string_t gana_name;
};
static bool kk_src_effects_prat__resonance_get_successor_fun1686(kk_function_t _fself, kk_box_t _b_x446, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_get_successor_fun1686(kk_string_t gana_name, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_get_successor_fun1686__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_get_successor_fun1686__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_get_successor_fun1686, kk_context());
  _self->gana_name = gana_name;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_src_effects_prat__resonance_get_successor_fun1686(kk_function_t _fself, kk_box_t _b_x446, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_get_successor_fun1686__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_get_successor_fun1686__t*, _fself, _ctx);
  kk_string_t gana_name = _self->gana_name; /* string */
  kk_drop_match(_self, {kk_string_dup(gana_name, _ctx);}, {}, _ctx)
  kk_string_t _x_x1687 = kk_string_unbox(_b_x446); /*string*/
  return kk_string_is_eq(_x_x1687,gana_name,kk_context());
}

kk_string_t kk_src_effects_prat__resonance_get_successor(kk_string_t gana_name, kk_context_t* _ctx) { /* (gana-name : string) -> string */ 
  kk_integer_t idx;
  kk_std_core_types__list _x_x1685 = kk_std_core_types__list_dup(kk_src_effects_prat__resonance_gana_order, _ctx); /*list<string>*/
  idx = kk_std_core_list_index_of(_x_x1685, kk_src_effects_prat__resonance_new_get_successor_fun1686(gana_name, _ctx), _ctx); /*int*/
  bool _match_x875 = kk_integer_gte_borrow(idx,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x875) {
    kk_std_core_types__list xs_10023;
    kk_std_core_types__list _x_x1688 = kk_std_core_types__list_dup(kk_src_effects_prat__resonance_gana_order, _ctx); /*list<string>*/
    kk_integer_t _x_x1689;
    kk_integer_t _x_x1690 = kk_integer_add_small_const(idx, 1, _ctx); /*int*/
    _x_x1689 = kk_integer_mod(_x_x1690,(kk_integer_from_small(28)),kk_context()); /*int*/
    xs_10023 = kk_std_core_list_drop(_x_x1688, _x_x1689, _ctx); /*list<string>*/
    if (kk_std_core_types__is_Cons(xs_10023, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1691 = kk_std_core_types__as_Cons(xs_10023, _ctx);
      kk_box_t _box_x450 = _con_x1691->head;
      kk_std_core_types__list _pat_0_0 = _con_x1691->tail;
      kk_string_t x = kk_string_unbox(_box_x450);
      if kk_likely(kk_datatype_ptr_is_unique(xs_10023, _ctx)) {
        kk_std_core_types__list_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(xs_10023, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_10023, _ctx);
      }
      return x;
    }
    {
      kk_std_core_types__maybe _match_x876 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/;
      if (kk_std_core_types__is_Just(_match_x876, _ctx)) {
        kk_box_t _box_x451 = _match_x876._cons.Just.value;
        kk_string_t g_0 = kk_string_unbox(_box_x451);
        kk_string_dup(g_0, _ctx);
        kk_std_core_types__maybe_drop(_match_x876, _ctx);
        return g_0;
      }
      {
        kk_define_string_literal(, _s_x1692, 9, "gana_horn", _ctx)
        return kk_string_dup(_s_x1692, _ctx);
      }
    }
  }
  {
    kk_integer_drop(idx, _ctx);
    kk_define_string_literal(, _s_x1693, 9, "gana_horn", _ctx)
    return kk_string_dup(_s_x1693, _ctx);
  }
}

kk_src_effects_prat__resonance__resonance_state kk_src_effects_prat__resonance_resonance_state_fs__copy(kk_src_effects_prat__resonance__resonance_state _this, kk_std_core_types__optional last_snapshot, kk_std_core_types__optional history, kk_std_core_types__optional gana_counts, kk_std_core_types__optional session_calls, kk_context_t* _ctx) { /* (resonance-state, last-snapshot : ? (maybe<snapshot>), history : ? (list<snapshot>), gana-counts : ? (list<(string, int)>), session-calls : ? int) -> resonance-state */ 
  kk_std_core_types__maybe _x_x1698;
  if (kk_std_core_types__is_Optional(last_snapshot, _ctx)) {
    kk_box_t _box_x452 = last_snapshot._cons._Optional.value;
    kk_std_core_types__maybe _uniq_last_snapshot_3359 = kk_std_core_types__maybe_unbox(_box_x452, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_last_snapshot_3359, _ctx);
    kk_std_core_types__optional_drop(last_snapshot, _ctx);
    _x_x1698 = _uniq_last_snapshot_3359; /*maybe<src/effects/prat_resonance/snapshot>*/
  }
  else {
    kk_std_core_types__optional_drop(last_snapshot, _ctx);
    {
      struct kk_src_effects_prat__resonance_Resonance_state* _con_x1699 = kk_src_effects_prat__resonance__as_Resonance_state(_this, _ctx);
      kk_std_core_types__maybe _x = _con_x1699->last_snapshot;
      kk_std_core_types__maybe_dup(_x, _ctx);
      _x_x1698 = _x; /*maybe<src/effects/prat_resonance/snapshot>*/
    }
  }
  kk_std_core_types__list _x_x1700;
  if (kk_std_core_types__is_Optional(history, _ctx)) {
    kk_box_t _box_x453 = history._cons._Optional.value;
    kk_std_core_types__list _uniq_history_3367 = kk_std_core_types__list_unbox(_box_x453, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_history_3367, _ctx);
    kk_std_core_types__optional_drop(history, _ctx);
    _x_x1700 = _uniq_history_3367; /*list<src/effects/prat_resonance/snapshot>*/
  }
  else {
    kk_std_core_types__optional_drop(history, _ctx);
    {
      struct kk_src_effects_prat__resonance_Resonance_state* _con_x1701 = kk_src_effects_prat__resonance__as_Resonance_state(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x1701->history;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x1700 = _x_0; /*list<src/effects/prat_resonance/snapshot>*/
    }
  }
  kk_std_core_types__list _x_x1702;
  if (kk_std_core_types__is_Optional(gana_counts, _ctx)) {
    kk_box_t _box_x454 = gana_counts._cons._Optional.value;
    kk_std_core_types__list _uniq_gana_counts_3375 = kk_std_core_types__list_unbox(_box_x454, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_gana_counts_3375, _ctx);
    kk_std_core_types__optional_drop(gana_counts, _ctx);
    _x_x1702 = _uniq_gana_counts_3375; /*list<(string, int)>*/
  }
  else {
    kk_std_core_types__optional_drop(gana_counts, _ctx);
    {
      struct kk_src_effects_prat__resonance_Resonance_state* _con_x1703 = kk_src_effects_prat__resonance__as_Resonance_state(_this, _ctx);
      kk_std_core_types__list _x_1 = _con_x1703->gana_counts;
      kk_std_core_types__list_dup(_x_1, _ctx);
      _x_x1702 = _x_1; /*list<(string, int)>*/
    }
  }
  kk_integer_t _x_x1704;
  if (kk_std_core_types__is_Optional(session_calls, _ctx)) {
    kk_box_t _box_x455 = session_calls._cons._Optional.value;
    kk_integer_t _uniq_session_calls_3383 = kk_integer_unbox(_box_x455, _ctx);
    kk_integer_dup(_uniq_session_calls_3383, _ctx);
    kk_std_core_types__optional_drop(session_calls, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(5)), _ctx);
    _x_x1704 = _uniq_session_calls_3383; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(session_calls, _ctx);
    {
      struct kk_src_effects_prat__resonance_Resonance_state* _con_x1705 = kk_src_effects_prat__resonance__as_Resonance_state(_this, _ctx);
      kk_std_core_types__maybe _pat_0_3 = _con_x1705->last_snapshot;
      kk_std_core_types__list _pat_1_4 = _con_x1705->history;
      kk_std_core_types__list _pat_2_3 = _con_x1705->gana_counts;
      kk_integer_t _x_2 = _con_x1705->session_calls;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_std_core_types__list_drop(_pat_2_3, _ctx);
        kk_std_core_types__list_drop(_pat_1_4, _ctx);
        kk_std_core_types__maybe_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1704 = _x_2; /*int*/
    }
  }
  return kk_src_effects_prat__resonance__new_Resonance_state(kk_reuse_null, 0, _x_x1698, _x_x1700, _x_x1702, _x_x1704, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_record_in_state_fun1709__t {
  struct kk_function_s _base;
  kk_src_effects_prat__resonance__snapshot snap;
};
static bool kk_src_effects_prat__resonance_record_in_state_fun1709(kk_function_t _fself, kk_box_t _b_x460, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_record_in_state_fun1709(kk_src_effects_prat__resonance__snapshot snap, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_record_in_state_fun1709__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_record_in_state_fun1709__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_record_in_state_fun1709, kk_context());
  _self->snap = snap;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_src_effects_prat__resonance_record_in_state_fun1709(kk_function_t _fself, kk_box_t _b_x460, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_record_in_state_fun1709__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_record_in_state_fun1709__t*, _fself, _ctx);
  kk_src_effects_prat__resonance__snapshot snap = _self->snap; /* src/effects/prat_resonance/snapshot */
  kk_drop_match(_self, {kk_src_effects_prat__resonance__snapshot_dup(snap, _ctx);}, {}, _ctx)
  kk_string_t _x_x1710;
  kk_std_core_types__tuple2 _match_x874 = kk_std_core_types__tuple2_unbox(_b_x460, KK_OWNED, _ctx); /*(string, int)*/;
  {
    kk_box_t _box_x456 = _match_x874.fst;
    kk_box_t _box_x457 = _match_x874.snd;
    kk_string_t _x_0 = kk_string_unbox(_box_x456);
    kk_string_dup(_x_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x874, _ctx);
    _x_x1710 = _x_0; /*string*/
  }
  kk_string_t _x_x1711;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1712 = kk_src_effects_prat__resonance__as_Snapshot(snap, _ctx);
    kk_string_t _x_1 = _con_x1712->gana_name;
    kk_string_t _pat_0_1 = _con_x1712->tool_name;
    kk_string_t _pat_1_0 = _con_x1712->operation;
    kk_string_t _pat_2_0 = _con_x1712->output_preview;
    kk_integer_t _pat_5 = _con_x1712->lunar_mansion_num;
    kk_string_t _pat_7 = _con_x1712->guna_tag;
    kk_string_t _pat_8 = _con_x1712->quadrant;
    kk_string_t _pat_9 = _con_x1712->successor_hint;
    if kk_likely(kk_datatype_ptr_is_unique(snap, _ctx)) {
      kk_string_drop(_pat_9, _ctx);
      kk_string_drop(_pat_8, _ctx);
      kk_string_drop(_pat_7, _ctx);
      kk_integer_drop(_pat_5, _ctx);
      kk_string_drop(_pat_2_0, _ctx);
      kk_string_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(snap, _ctx);
    }
    else {
      kk_string_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(snap, _ctx);
    }
    _x_x1711 = _x_1; /*string*/
  }
  return kk_string_is_eq(_x_x1710,_x_x1711,kk_context());
}


// lift anonymous function
struct kk_src_effects_prat__resonance_record_in_state_fun1716__t {
  struct kk_function_s _base;
  kk_string_t name;
};
static bool kk_src_effects_prat__resonance_record_in_state_fun1716(kk_function_t _fself, kk_box_t _b_x470, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_record_in_state_fun1716(kk_string_t name, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_record_in_state_fun1716__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_record_in_state_fun1716__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_record_in_state_fun1716, kk_context());
  _self->name = name;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_src_effects_prat__resonance_record_in_state_fun1716(kk_function_t _fself, kk_box_t _b_x470, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_record_in_state_fun1716__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_record_in_state_fun1716__t*, _fself, _ctx);
  kk_string_t name = _self->name; /* string */
  kk_drop_match(_self, {kk_string_dup(name, _ctx);}, {}, _ctx)
  kk_string_t _x_x1717;
  kk_std_core_types__tuple2 _match_x873 = kk_std_core_types__tuple2_unbox(_b_x470, KK_OWNED, _ctx); /*(string, int)*/;
  {
    kk_box_t _box_x466 = _match_x873.fst;
    kk_box_t _box_x467 = _match_x873.snd;
    kk_string_t _x_3 = kk_string_unbox(_box_x466);
    kk_string_dup(_x_3, _ctx);
    kk_std_core_types__tuple2_drop(_match_x873, _ctx);
    _x_x1717 = _x_3; /*string*/
  }
  return kk_string_is_neq(_x_x1717,name,kk_context());
}

kk_src_effects_prat__resonance__resonance_state kk_src_effects_prat__resonance_record_in_state(kk_src_effects_prat__resonance__resonance_state st, kk_src_effects_prat__resonance__snapshot snap, kk_context_t* _ctx) { /* (st : resonance-state, snap : snapshot) -> resonance-state */ 
  kk_std_core_types__list new_counts;
  kk_std_core_types__maybe _match_x872;
  kk_std_core_types__list _x_x1706;
  {
    struct kk_src_effects_prat__resonance_Resonance_state* _con_x1707 = kk_src_effects_prat__resonance__as_Resonance_state(st, _ctx);
    kk_std_core_types__list _x = _con_x1707->gana_counts;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x1706 = _x; /*list<(string, int)>*/
  }
  kk_function_t _x_x1708;
  kk_src_effects_prat__resonance__snapshot_dup(snap, _ctx);
  _x_x1708 = kk_src_effects_prat__resonance_new_record_in_state_fun1709(snap, _ctx); /*(10001) -> 10002 bool*/
  _match_x872 = kk_std_core_list_find(_x_x1706, _x_x1708, _ctx); /*maybe<10001>*/
  if (kk_std_core_types__is_Just(_match_x872, _ctx)) {
    kk_box_t _box_x461 = _match_x872._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_2 = kk_std_core_types__tuple2_unbox(_box_x461, KK_BORROWED, _ctx);
    kk_box_t _box_x462 = _pat_0_2.fst;
    kk_box_t _box_x463 = _pat_0_2.snd;
    kk_string_t name = kk_string_unbox(_box_x462);
    kk_integer_t count = kk_integer_unbox(_box_x463, _ctx);
    kk_integer_dup(count, _ctx);
    kk_string_dup(name, _ctx);
    kk_std_core_types__maybe_drop(_match_x872, _ctx);
    kk_integer_t _b_x465_482 = kk_integer_add_small_const(count, 1, _ctx); /*int*/;
    kk_std_core_types__list _b_x472_480;
    kk_std_core_types__list _x_x1713;
    {
      struct kk_src_effects_prat__resonance_Resonance_state* _con_x1714 = kk_src_effects_prat__resonance__as_Resonance_state(st, _ctx);
      kk_std_core_types__list _x_2 = _con_x1714->gana_counts;
      kk_std_core_types__list_dup(_x_2, _ctx);
      _x_x1713 = _x_2; /*list<(string, int)>*/
    }
    kk_function_t _x_x1715;
    kk_string_dup(name, _ctx);
    _x_x1715 = kk_src_effects_prat__resonance_new_record_in_state_fun1716(name, _ctx); /*(10001) -> 10002 bool*/
    _b_x472_480 = kk_std_core_list_filter(_x_x1713, _x_x1715, _ctx); /*list<(string, int)>*/
    kk_box_t _x_x1718;
    kk_std_core_types__tuple2 _x_x1719 = kk_std_core_types__new_Tuple2(kk_string_box(name), kk_integer_box(_b_x465_482, _ctx), _ctx); /*(10037, 10038)*/
    _x_x1718 = kk_std_core_types__tuple2_box(_x_x1719, _ctx); /*10021*/
    new_counts = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1718, _b_x472_480, _ctx); /*list<(string, int)>*/
  }
  else {
    kk_box_t _x_x1720;
    kk_std_core_types__tuple2 _x_x1721;
    kk_box_t _x_x1722;
    kk_string_t _x_x1723;
    {
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1724 = kk_src_effects_prat__resonance__as_Snapshot(snap, _ctx);
      kk_string_t _x_4 = _con_x1724->gana_name;
      kk_string_dup(_x_4, _ctx);
      _x_x1723 = _x_4; /*string*/
    }
    _x_x1722 = kk_string_box(_x_x1723); /*10037*/
    _x_x1721 = kk_std_core_types__new_Tuple2(_x_x1722, kk_integer_box(kk_integer_from_small(1), _ctx), _ctx); /*(10037, 10038)*/
    _x_x1720 = kk_std_core_types__tuple2_box(_x_x1721, _ctx); /*10021*/
    kk_std_core_types__list _x_x1725;
    {
      struct kk_src_effects_prat__resonance_Resonance_state* _con_x1726 = kk_src_effects_prat__resonance__as_Resonance_state(st, _ctx);
      kk_std_core_types__list _x_5 = _con_x1726->gana_counts;
      kk_std_core_types__list_dup(_x_5, _ctx);
      _x_x1725 = _x_5; /*list<(string, int)>*/
    }
    new_counts = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1720, _x_x1725, _ctx); /*list<(string, int)>*/
  }
  kk_src_effects_prat__resonance__snapshot _b_x492_495 = kk_src_effects_prat__resonance__snapshot_dup(snap, _ctx); /*src/effects/prat_resonance/snapshot*/;
  kk_std_core_types__list _b_x493_496;
  {
    struct kk_src_effects_prat__resonance_Resonance_state* _con_x1727 = kk_src_effects_prat__resonance__as_Resonance_state(st, _ctx);
    kk_std_core_types__list _x_6 = _con_x1727->history;
    kk_std_core_types__list_dup(_x_6, _ctx);
    _b_x493_496 = _x_6; /*list<src/effects/prat_resonance/snapshot>*/
  }
  kk_std_core_types__maybe _x_x1728 = kk_std_core_types__new_Just(kk_src_effects_prat__resonance__snapshot_box(snap, _ctx), _ctx); /*maybe<10024>*/
  kk_std_core_types__list _x_x1729;
  kk_std_core_types__list _x_x1730 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_src_effects_prat__resonance__snapshot_box(_b_x492_495, _ctx), _b_x493_496, _ctx); /*list<10021>*/
  _x_x1729 = kk_std_core_list_take(_x_x1730, kk_integer_from_small(50), _ctx); /*list<10001>*/
  kk_integer_t _x_x1731;
  kk_integer_t _x_x1732;
  {
    struct kk_src_effects_prat__resonance_Resonance_state* _con_x1733 = kk_src_effects_prat__resonance__as_Resonance_state(st, _ctx);
    kk_std_core_types__maybe _pat_0_8 = _con_x1733->last_snapshot;
    kk_std_core_types__list _pat_1_6 = _con_x1733->history;
    kk_std_core_types__list _pat_2_5 = _con_x1733->gana_counts;
    kk_integer_t _x_7 = _con_x1733->session_calls;
    if kk_likely(kk_datatype_ptr_is_unique(st, _ctx)) {
      kk_std_core_types__list_drop(_pat_2_5, _ctx);
      kk_std_core_types__list_drop(_pat_1_6, _ctx);
      kk_std_core_types__maybe_drop(_pat_0_8, _ctx);
      kk_datatype_ptr_free(st, _ctx);
    }
    else {
      kk_integer_dup(_x_7, _ctx);
      kk_datatype_ptr_decref(st, _ctx);
    }
    _x_x1732 = _x_7; /*int*/
  }
  _x_x1731 = kk_integer_add_small_const(_x_x1732, 1, _ctx); /*int*/
  return kk_src_effects_prat__resonance__new_Resonance_state(kk_reuse_null, 0, _x_x1728, _x_x1729, new_counts, _x_x1731, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_calculate_harmony_score_fun1736__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_calculate_harmony_score_fun1736(kk_function_t _fself, kk_box_t _b_x502, kk_box_t _b_x503, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_calculate_harmony_score_fun1736(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_calculate_harmony_score_fun1736, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_calculate_harmony_score_fun1736(kk_function_t _fself, kk_box_t _b_x502, kk_box_t _b_x503, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1737;
  kk_integer_t _x_x1738 = kk_integer_unbox(_b_x502, _ctx); /*int*/
  kk_integer_t _x_x1739;
  kk_std_core_types__tuple2 _match_x871 = kk_std_core_types__tuple2_unbox(_b_x503, KK_OWNED, _ctx); /*(string, int)*/;
  {
    kk_box_t _box_x497 = _match_x871.fst;
    kk_box_t _box_x498 = _match_x871.snd;
    kk_integer_t _x = kk_integer_unbox(_box_x498, _ctx);
    kk_integer_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(_match_x871, _ctx);
    _x_x1739 = _x; /*int*/
  }
  _x_x1737 = kk_integer_add(_x_x1738,_x_x1739,kk_context()); /*int*/
  return kk_integer_box(_x_x1737, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_calculate_harmony_score_fun1742__t {
  struct kk_function_s _base;
  kk_integer_t total;
};
static kk_box_t kk_src_effects_prat__resonance_calculate_harmony_score_fun1742(kk_function_t _fself, kk_box_t _b_x514, kk_box_t _b_x515, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_calculate_harmony_score_fun1742(kk_integer_t total, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_calculate_harmony_score_fun1742__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_calculate_harmony_score_fun1742__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_calculate_harmony_score_fun1742, kk_context());
  _self->total = total;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_calculate_harmony_score_fun1742(kk_function_t _fself, kk_box_t _b_x514, kk_box_t _b_x515, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_calculate_harmony_score_fun1742__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_calculate_harmony_score_fun1742__t*, _fself, _ctx);
  kk_integer_t total = _self->total; /* int */
  kk_drop_match(_self, {kk_integer_dup(total, _ctx);}, {}, _ctx)
  double diff;
  double _x_x1743;
  kk_integer_t _x_x1744;
  kk_std_core_types__tuple2 _match_x870 = kk_std_core_types__tuple2_unbox(_b_x515, KK_OWNED, _ctx); /*(string, int)*/;
  {
    kk_box_t _box_x509 = _match_x870.fst;
    kk_box_t _box_x510 = _match_x870.snd;
    kk_integer_t _x_0 = kk_integer_unbox(_box_x510, _ctx);
    kk_integer_dup(_x_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x870, _ctx);
    _x_x1744 = _x_0; /*int*/
  }
  _x_x1743 = kk_integer_as_double(_x_x1744,kk_context()); /*float64*/
  double _x_x1745;
  double _x_x1746 = kk_integer_as_double(total,kk_context()); /*float64*/
  _x_x1745 = (_x_x1746 / (0x1.cp4)); /*float64*/
  diff = (_x_x1743 - _x_x1745); /*float64*/
  double _x_x1747;
  double _x_x1748 = kk_double_unbox(_b_x514, KK_OWNED, _ctx); /*float64*/
  double _x_x1749 = (diff * diff); /*float64*/
  _x_x1747 = (_x_x1748 + _x_x1749); /*float64*/
  return kk_double_box(_x_x1747, _ctx);
}

double kk_src_effects_prat__resonance_calculate_harmony_score(kk_std_core_types__list counts, kk_context_t* _ctx) { /* (counts : list<(string, int)>) -> float64 */ 
  kk_integer_t total;
  kk_box_t _x_x1734;
  kk_std_core_types__list _x_x1735 = kk_std_core_types__list_dup(counts, _ctx); /*list<(string, int)>*/
  _x_x1734 = kk_std_core_list_foldl(_x_x1735, kk_integer_box(kk_integer_from_small(0), _ctx), kk_src_effects_prat__resonance_new_calculate_harmony_score_fun1736(_ctx), _ctx); /*10002*/
  total = kk_integer_unbox(_x_x1734, _ctx); /*int*/
  bool _match_x869 = kk_integer_eq_borrow(total,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x869) {
    kk_integer_drop(total, _ctx);
    kk_std_core_types__list_drop(counts, _ctx);
    return 0x1p0;
  }
  {
    double variance;
    kk_box_t _x_x1740;
    kk_function_t _x_x1741;
    kk_integer_dup(total, _ctx);
    _x_x1741 = kk_src_effects_prat__resonance_new_calculate_harmony_score_fun1742(total, _ctx); /*(10002, 10001) -> 10003 10002*/
    _x_x1740 = kk_std_core_list_foldl(counts, kk_double_box(0x0p+0, _ctx), _x_x1741, _ctx); /*10002*/
    variance = kk_double_unbox(_x_x1740, KK_OWNED, _ctx); /*float64*/
    double _x_x1750;
    double _x_x1751;
    kk_integer_t _x_x1752;
    kk_integer_t _x_x1753 = kk_integer_dup(total, _ctx); /*int*/
    _x_x1752 = kk_integer_mul(_x_x1753,total,kk_context()); /*int*/
    _x_x1751 = kk_integer_as_double(_x_x1752,kk_context()); /*float64*/
    _x_x1750 = (variance / _x_x1751); /*float64*/
    return (0x1p0 - _x_x1750);
  }
}


// lift anonymous function
struct kk_src_effects_prat__resonance_handle_resonance_fun1760__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1760(kk_function_t _fself, int32_t _b_x528, kk_std_core_hnd__ev _b_x529, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_handle_resonance_fun1760(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1760__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1760__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_handle_resonance_fun1760, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1760(kk_function_t _fself, int32_t _b_x528, kk_std_core_hnd__ev _b_x529, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1760__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1760__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<4524,src/effects/prat_resonance/resonance-state> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x529, (KK_I32(3)), _ctx);
  kk_src_effects_prat__resonance__resonance_state _this_10048;
  kk_box_t _x_x1761 = kk_ref_get(loc,kk_context()); /*10000*/
  _this_10048 = kk_src_effects_prat__resonance__resonance_state_unbox(_x_x1761, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-state*/
  kk_integer_t _x_x1762;
  {
    struct kk_src_effects_prat__resonance_Resonance_state* _con_x1763 = kk_src_effects_prat__resonance__as_Resonance_state(_this_10048, _ctx);
    kk_std_core_types__maybe _pat_0 = _con_x1763->last_snapshot;
    kk_std_core_types__list _pat_1 = _con_x1763->history;
    kk_std_core_types__list _pat_2 = _con_x1763->gana_counts;
    kk_integer_t _x = _con_x1763->session_calls;
    if kk_likely(kk_datatype_ptr_is_unique(_this_10048, _ctx)) {
      kk_std_core_types__list_drop(_pat_2, _ctx);
      kk_std_core_types__list_drop(_pat_1, _ctx);
      kk_std_core_types__maybe_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_this_10048, _ctx);
    }
    else {
      kk_integer_dup(_x, _ctx);
      kk_datatype_ptr_decref(_this_10048, _ctx);
    }
    _x_x1762 = _x; /*int*/
  }
  return kk_integer_box(_x_x1762, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_handle_resonance_fun1766__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1766(kk_function_t _fself, int32_t _b_x535, kk_std_core_hnd__ev _b_x536, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_handle_resonance_fun1766(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1766__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1766__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_handle_resonance_fun1766, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1766(kk_function_t _fself, int32_t _b_x535, kk_std_core_hnd__ev _b_x536, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1766__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1766__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<4524,src/effects/prat_resonance/resonance-state> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x536, (KK_I32(3)), _ctx);
  kk_src_effects_prat__resonance__resonance_state _this_0_10049;
  kk_box_t _x_x1767 = kk_ref_get(loc,kk_context()); /*10000*/
  _this_0_10049 = kk_src_effects_prat__resonance__resonance_state_unbox(_x_x1767, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-state*/
  kk_std_core_types__list _x_x1768;
  {
    struct kk_src_effects_prat__resonance_Resonance_state* _con_x1769 = kk_src_effects_prat__resonance__as_Resonance_state(_this_0_10049, _ctx);
    kk_std_core_types__maybe _pat_0_0 = _con_x1769->last_snapshot;
    kk_std_core_types__list _pat_1_0 = _con_x1769->history;
    kk_std_core_types__list _x_0 = _con_x1769->gana_counts;
    kk_integer_t _pat_2_0 = _con_x1769->session_calls;
    if kk_likely(kk_datatype_ptr_is_unique(_this_0_10049, _ctx)) {
      kk_integer_drop(_pat_2_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_0, _ctx);
      kk_std_core_types__maybe_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(_this_0_10049, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_this_0_10049, _ctx);
    }
    _x_x1768 = _x_0; /*list<(string, int)>*/
  }
  return kk_std_core_types__list_box(_x_x1768, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_handle_resonance_fun1771__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1771(kk_function_t _fself, int32_t _b_x538, kk_std_core_hnd__ev _b_x539, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_handle_resonance_fun1771(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_handle_resonance_fun1771, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1771(kk_function_t _fself, int32_t _b_x538, kk_std_core_hnd__ev _b_x539, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(_b_x539, (KK_I32(3)), _ctx);
  kk_string_t _x_x1772;
  kk_define_string_literal(, _s_x1773, 7, "rajasic", _ctx)
  _x_x1772 = kk_string_dup(_s_x1773, _ctx); /*string*/
  return kk_string_box(_x_x1772);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_handle_resonance_fun1775__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1775(kk_function_t _fself, int32_t _b_x541, kk_std_core_hnd__ev _b_x542, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_handle_resonance_fun1775(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_handle_resonance_fun1775, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1775(kk_function_t _fself, int32_t _b_x541, kk_std_core_hnd__ev _b_x542, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(_b_x542, (KK_I32(3)), _ctx);
  return kk_double_box(0x1p0, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_handle_resonance_fun1778__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1778(kk_function_t _fself, int32_t _b_x549, kk_std_core_hnd__ev _b_x550, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_handle_resonance_fun1778(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1778__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1778__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_handle_resonance_fun1778, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1778(kk_function_t _fself, int32_t _b_x549, kk_std_core_hnd__ev _b_x550, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1778__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1778__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<4524,src/effects/prat_resonance/resonance-state> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x550, (KK_I32(3)), _ctx);
  kk_src_effects_prat__resonance__resonance_state _this_1_10050;
  kk_box_t _x_x1779 = kk_ref_get(loc,kk_context()); /*10000*/
  _this_1_10050 = kk_src_effects_prat__resonance__resonance_state_unbox(_x_x1779, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-state*/
  kk_src_effects_prat__resonance__snapshot _x_x1780;
  {
    struct kk_src_effects_prat__resonance_Resonance_state* _con_x1781 = kk_src_effects_prat__resonance__as_Resonance_state(_this_1_10050, _ctx);
    kk_std_core_types__maybe _x_1 = _con_x1781->last_snapshot;
    kk_std_core_types__list _pat_0_1 = _con_x1781->history;
    kk_std_core_types__list _pat_1_1 = _con_x1781->gana_counts;
    kk_integer_t _pat_2_1 = _con_x1781->session_calls;
    if kk_likely(kk_datatype_ptr_is_unique(_this_1_10050, _ctx)) {
      kk_integer_drop(_pat_2_1, _ctx);
      kk_std_core_types__list_drop(_pat_1_1, _ctx);
      kk_std_core_types__list_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(_this_1_10050, _ctx);
    }
    else {
      kk_std_core_types__maybe_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_this_1_10050, _ctx);
    }
    if (kk_std_core_types__is_Just(_x_1, _ctx)) {
      kk_box_t _box_x547 = _x_1._cons.Just.value;
      kk_src_effects_prat__resonance__snapshot s = kk_src_effects_prat__resonance__snapshot_unbox(_box_x547, KK_BORROWED, _ctx);
      struct kk_src_effects_prat__resonance_Snapshot* _con_x1782 = kk_src_effects_prat__resonance__as_Snapshot(s, _ctx);
      kk_src_effects_prat__resonance__snapshot_dup(s, _ctx);
      kk_std_core_types__maybe_drop(_x_1, _ctx);
      _x_x1780 = s; /*src/effects/prat_resonance/snapshot*/
    }
    else {
      kk_string_t _x_x1783 = kk_string_empty(); /*string*/
      kk_string_t _x_x1785 = kk_string_empty(); /*string*/
      kk_string_t _x_x1787 = kk_string_empty(); /*string*/
      kk_string_t _x_x1789 = kk_string_empty(); /*string*/
      kk_string_t _x_x1791;
      kk_define_string_literal(, _s_x1792, 7, "sattvic", _ctx)
      _x_x1791 = kk_string_dup(_s_x1792, _ctx); /*string*/
      kk_string_t _x_x1793;
      kk_define_string_literal(, _s_x1794, 4, "East", _ctx)
      _x_x1793 = kk_string_dup(_s_x1794, _ctx); /*string*/
      kk_string_t _x_x1795 = kk_string_empty(); /*string*/
      _x_x1780 = kk_src_effects_prat__resonance__new_Snapshot(kk_reuse_null, 0, _x_x1783, _x_x1785, _x_x1787, _x_x1789, 0x0p+0, 0x0p+0, kk_integer_from_small(0), 0x1p0, _x_x1791, _x_x1793, _x_x1795, _ctx); /*src/effects/prat_resonance/snapshot*/
    }
  }
  return kk_src_effects_prat__resonance__snapshot_box(_x_x1780, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_handle_resonance_fun1798__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1798(kk_function_t _fself, int32_t _b_x552, kk_std_core_hnd__ev _b_x553, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_handle_resonance_fun1798(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_handle_resonance_fun1798, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1798(kk_function_t _fself, int32_t _b_x552, kk_std_core_hnd__ev _b_x553, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(_b_x553, (KK_I32(3)), _ctx);
  return kk_integer_box(kk_integer_from_small(14), _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_handle_resonance_fun1800__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1800(kk_function_t _fself, int32_t _b_x555, kk_std_core_hnd__ev _b_x556, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_handle_resonance_fun1800(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_handle_resonance_fun1800, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1800(kk_function_t _fself, int32_t _b_x555, kk_std_core_hnd__ev _b_x556, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(_b_x556, (KK_I32(3)), _ctx);
  return kk_double_box(0x1p-1, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_handle_resonance_fun1803__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1803(kk_function_t _fself, int32_t _b_x562, kk_std_core_hnd__ev _b_x563, kk_box_t _b_x564, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_handle_resonance_fun1803(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1803__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1803__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_handle_resonance_fun1803, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1803(kk_function_t _fself, int32_t _b_x562, kk_std_core_hnd__ev _b_x563, kk_box_t _b_x564, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1803__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1803__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<4524,src/effects/prat_resonance/resonance-state> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x563, (KK_I32(3)), _ctx);
  kk_src_effects_prat__resonance__resonance_state _this_2_10051;
  kk_box_t _x_x1804 = kk_ref_get(loc,kk_context()); /*10000*/
  _this_2_10051 = kk_src_effects_prat__resonance__resonance_state_unbox(_x_x1804, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-state*/
  kk_std_core_types__list _x_x1805;
  kk_std_core_types__list _x_x1806;
  {
    struct kk_src_effects_prat__resonance_Resonance_state* _con_x1807 = kk_src_effects_prat__resonance__as_Resonance_state(_this_2_10051, _ctx);
    kk_std_core_types__maybe _pat_0_3 = _con_x1807->last_snapshot;
    kk_std_core_types__list _x_2 = _con_x1807->history;
    kk_std_core_types__list _pat_1_3 = _con_x1807->gana_counts;
    kk_integer_t _pat_2_3 = _con_x1807->session_calls;
    if kk_likely(kk_datatype_ptr_is_unique(_this_2_10051, _ctx)) {
      kk_integer_drop(_pat_2_3, _ctx);
      kk_std_core_types__list_drop(_pat_1_3, _ctx);
      kk_std_core_types__maybe_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(_this_2_10051, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x_2, _ctx);
      kk_datatype_ptr_decref(_this_2_10051, _ctx);
    }
    _x_x1806 = _x_2; /*list<src/effects/prat_resonance/snapshot>*/
  }
  kk_integer_t _x_x1808 = kk_integer_unbox(_b_x564, _ctx); /*int*/
  _x_x1805 = kk_std_core_list_take(_x_x1806, _x_x1808, _ctx); /*list<10001>*/
  return kk_std_core_types__list_box(_x_x1805, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_handle_resonance_fun1811__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1811(kk_function_t _fself, int32_t _b_x570, kk_std_core_hnd__ev _b_x571, kk_box_t _b_x572, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_handle_resonance_fun1811(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1811__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1811__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_handle_resonance_fun1811, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1811(kk_function_t _fself, int32_t _b_x570, kk_std_core_hnd__ev _b_x571, kk_box_t _b_x572, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1811__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1811__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<4524,src/effects/prat_resonance/resonance-state> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x571, (KK_I32(3)), _ctx);
  kk_src_effects_prat__resonance__resonance_state _b_x568_588;
  kk_src_effects_prat__resonance__resonance_state _x_x1812;
  kk_box_t _x_x1813;
  kk_ref_t _x_x1814 = kk_ref_dup(loc, _ctx); /*local-var<4524,src/effects/prat_resonance/resonance-state>*/
  _x_x1813 = kk_ref_get(_x_x1814,kk_context()); /*10000*/
  _x_x1812 = kk_src_effects_prat__resonance__resonance_state_unbox(_x_x1813, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-state*/
  kk_src_effects_prat__resonance__snapshot _x_x1815 = kk_src_effects_prat__resonance__snapshot_unbox(_b_x572, KK_OWNED, _ctx); /*src/effects/prat_resonance/snapshot*/
  _b_x568_588 = kk_src_effects_prat__resonance_record_in_state(_x_x1812, _x_x1815, _ctx); /*src/effects/prat_resonance/resonance-state*/
  kk_unit_t _x_x1816 = kk_Unit;
  kk_unit_t _brw_x868 = kk_Unit;
  kk_ref_set_borrow(loc,(kk_src_effects_prat__resonance__resonance_state_box(_b_x568_588, _ctx)),kk_context());
  kk_ref_drop(loc, _ctx);
  _brw_x868;
  return kk_unit_box(_x_x1816);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_handle_resonance_fun1819__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1819(kk_function_t _fself, int32_t _b_x576, kk_std_core_hnd__ev _b_x577, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_handle_resonance_fun1819(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1819__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1819__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_handle_resonance_fun1819, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1819(kk_function_t _fself, int32_t _b_x576, kk_std_core_hnd__ev _b_x577, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_handle_resonance_fun1819__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_handle_resonance_fun1819__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<4524,src/effects/prat_resonance/resonance-state> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x577, (KK_I32(3)), _ctx);
  kk_unit_t _x_x1820 = kk_Unit;
  kk_unit_t _brw_x867 = kk_Unit;
  kk_box_t _x_x1821;
  kk_src_effects_prat__resonance__resonance_state _x_x1822 = kk_src_effects_prat__resonance__new_Resonance_state(kk_reuse_null, 0, kk_std_core_types__new_Nothing(_ctx), kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), kk_integer_from_small(0), _ctx); /*src/effects/prat_resonance/resonance-state*/
  _x_x1821 = kk_src_effects_prat__resonance__resonance_state_box(_x_x1822, _ctx); /*10000*/
  kk_ref_set_borrow(loc,_x_x1821,kk_context());
  kk_ref_drop(loc, _ctx);
  _brw_x867;
  return kk_unit_box(_x_x1820);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_handle_resonance_fun1823__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1823(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_handle_resonance_fun1823(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_handle_resonance_fun1823, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_handle_resonance_fun1823(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}

kk_box_t kk_src_effects_prat__resonance_handle_resonance(kk_function_t action, kk_context_t* _ctx) { /* forall<a> (action : () -> resonance a) -> a */ 
  kk_ref_t loc;
  kk_box_t _x_x1755;
  kk_src_effects_prat__resonance__resonance_state _x_x1756 = kk_src_effects_prat__resonance__new_Resonance_state(kk_reuse_null, 0, kk_std_core_types__new_Nothing(_ctx), kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), kk_integer_from_small(0), _ctx); /*src/effects/prat_resonance/resonance-state*/
  _x_x1755 = kk_src_effects_prat__resonance__resonance_state_box(_x_x1756, _ctx); /*10000*/
  loc = kk_ref_alloc(_x_x1755,kk_context()); /*local-var<4524,src/effects/prat_resonance/resonance-state>*/
  kk_box_t res;
  kk_src_effects_prat__resonance__resonance _x_x1757;
  kk_std_core_hnd__clause0 _x_x1758;
  kk_function_t _x_x1759;
  kk_ref_dup(loc, _ctx);
  _x_x1759 = kk_src_effects_prat__resonance_new_handle_resonance_fun1760(loc, _ctx); /*(hnd/marker<10012,10013>, hnd/ev<10011>) -> 10012 10010*/
  _x_x1758 = kk_std_core_hnd__new_Clause0(_x_x1759, _ctx); /*hnd/clause0<10010,10011,10012,10013>*/
  kk_std_core_hnd__clause0 _x_x1764;
  kk_function_t _x_x1765;
  kk_ref_dup(loc, _ctx);
  _x_x1765 = kk_src_effects_prat__resonance_new_handle_resonance_fun1766(loc, _ctx); /*(hnd/marker<10012,10013>, hnd/ev<10011>) -> 10012 10010*/
  _x_x1764 = kk_std_core_hnd__new_Clause0(_x_x1765, _ctx); /*hnd/clause0<10010,10011,10012,10013>*/
  kk_std_core_hnd__clause0 _x_x1770 = kk_std_core_hnd__new_Clause0(kk_src_effects_prat__resonance_new_handle_resonance_fun1771(_ctx), _ctx); /*hnd/clause0<10010,10011,10012,10013>*/
  kk_std_core_hnd__clause0 _x_x1774 = kk_std_core_hnd__new_Clause0(kk_src_effects_prat__resonance_new_handle_resonance_fun1775(_ctx), _ctx); /*hnd/clause0<10010,10011,10012,10013>*/
  kk_std_core_hnd__clause0 _x_x1776;
  kk_function_t _x_x1777;
  kk_ref_dup(loc, _ctx);
  _x_x1777 = kk_src_effects_prat__resonance_new_handle_resonance_fun1778(loc, _ctx); /*(hnd/marker<10012,10013>, hnd/ev<10011>) -> 10012 10010*/
  _x_x1776 = kk_std_core_hnd__new_Clause0(_x_x1777, _ctx); /*hnd/clause0<10010,10011,10012,10013>*/
  kk_std_core_hnd__clause0 _x_x1797 = kk_std_core_hnd__new_Clause0(kk_src_effects_prat__resonance_new_handle_resonance_fun1798(_ctx), _ctx); /*hnd/clause0<10010,10011,10012,10013>*/
  kk_std_core_hnd__clause0 _x_x1799 = kk_std_core_hnd__new_Clause0(kk_src_effects_prat__resonance_new_handle_resonance_fun1800(_ctx), _ctx); /*hnd/clause0<10010,10011,10012,10013>*/
  kk_std_core_hnd__clause1 _x_x1801;
  kk_function_t _x_x1802;
  kk_ref_dup(loc, _ctx);
  _x_x1802 = kk_src_effects_prat__resonance_new_handle_resonance_fun1803(loc, _ctx); /*(hnd/marker<10018,10019>, hnd/ev<10017>, 10015) -> 10018 10016*/
  _x_x1801 = kk_std_core_hnd__new_Clause1(_x_x1802, _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  kk_std_core_hnd__clause1 _x_x1809;
  kk_function_t _x_x1810;
  kk_ref_dup(loc, _ctx);
  _x_x1810 = kk_src_effects_prat__resonance_new_handle_resonance_fun1811(loc, _ctx); /*(hnd/marker<10018,10019>, hnd/ev<10017>, 10015) -> 10018 10016*/
  _x_x1809 = kk_std_core_hnd__new_Clause1(_x_x1810, _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  kk_std_core_hnd__clause0 _x_x1817;
  kk_function_t _x_x1818;
  kk_ref_dup(loc, _ctx);
  _x_x1818 = kk_src_effects_prat__resonance_new_handle_resonance_fun1819(loc, _ctx); /*(hnd/marker<10012,10013>, hnd/ev<10011>) -> 10012 10010*/
  _x_x1817 = kk_std_core_hnd__new_Clause0(_x_x1818, _ctx); /*hnd/clause0<10010,10011,10012,10013>*/
  _x_x1757 = kk_src_effects_prat__resonance__new_Hnd_resonance(kk_reuse_null, 0, kk_integer_from_small(1), _x_x1758, _x_x1764, _x_x1770, _x_x1774, _x_x1776, _x_x1797, _x_x1799, _x_x1801, _x_x1809, _x_x1817, _ctx); /*src/effects/prat_resonance/resonance<51,52>*/
  res = kk_src_effects_prat__resonance_resonance_fs__handle(_x_x1757, kk_src_effects_prat__resonance_new_handle_resonance_fun1823(_ctx), action, _ctx); /*4531*/
  return kk_std_core_hnd_prompt_local_var(loc, res, _ctx);
}

kk_string_t kk_src_effects_prat__resonance_snapshot_to_json(kk_src_effects_prat__resonance__snapshot s, kk_context_t* _ctx) { /* (s : snapshot) -> string */ 
  kk_src_effects_prat__resonance__snapshot snapshot_9_10062 = kk_src_effects_prat__resonance__snapshot_dup(s, _ctx); /*src/effects/prat_resonance/snapshot*/;
  kk_string_t _x_x1831;
  kk_define_string_literal(, _s_x1832, 1, "{", _ctx)
  _x_x1831 = kk_string_dup(_s_x1832, _ctx); /*string*/
  kk_string_t _x_x1833;
  kk_string_t _x_x1834;
  kk_define_string_literal(, _s_x1835, 14, "\"gana_name\": \"", _ctx)
  _x_x1834 = kk_string_dup(_s_x1835, _ctx); /*string*/
  kk_string_t _x_x1836;
  kk_string_t _x_x1837;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1838 = kk_src_effects_prat__resonance__as_Snapshot(s, _ctx);
    kk_string_t _x = _con_x1838->gana_name;
    kk_string_dup(_x, _ctx);
    _x_x1837 = _x; /*string*/
  }
  kk_string_t _x_x1839;
  kk_string_t _x_x1840;
  kk_define_string_literal(, _s_x1841, 2, "\",", _ctx)
  _x_x1840 = kk_string_dup(_s_x1841, _ctx); /*string*/
  kk_string_t _x_x1842;
  kk_string_t _x_x1843;
  kk_define_string_literal(, _s_x1844, 14, "\"tool_name\": \"", _ctx)
  _x_x1843 = kk_string_dup(_s_x1844, _ctx); /*string*/
  kk_string_t _x_x1845;
  kk_string_t _x_x1846;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1847 = kk_src_effects_prat__resonance__as_Snapshot(s, _ctx);
    kk_string_t _x_0 = _con_x1847->tool_name;
    kk_string_dup(_x_0, _ctx);
    _x_x1846 = _x_0; /*string*/
  }
  kk_string_t _x_x1848;
  kk_string_t _x_x1849;
  kk_define_string_literal(, _s_x1850, 2, "\",", _ctx)
  _x_x1849 = kk_string_dup(_s_x1850, _ctx); /*string*/
  kk_string_t _x_x1851;
  kk_string_t _x_x1852;
  kk_define_string_literal(, _s_x1853, 14, "\"operation\": \"", _ctx)
  _x_x1852 = kk_string_dup(_s_x1853, _ctx); /*string*/
  kk_string_t _x_x1854;
  kk_string_t _x_x1855;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1856 = kk_src_effects_prat__resonance__as_Snapshot(s, _ctx);
    kk_string_t _x_1 = _con_x1856->operation;
    kk_string_dup(_x_1, _ctx);
    _x_x1855 = _x_1; /*string*/
  }
  kk_string_t _x_x1857;
  kk_string_t _x_x1858;
  kk_define_string_literal(, _s_x1859, 2, "\",", _ctx)
  _x_x1858 = kk_string_dup(_s_x1859, _ctx); /*string*/
  kk_string_t _x_x1860;
  kk_string_t _x_x1861;
  kk_define_string_literal(, _s_x1862, 19, "\"output_preview\": \"", _ctx)
  _x_x1861 = kk_string_dup(_s_x1862, _ctx); /*string*/
  kk_string_t _x_x1863;
  kk_string_t _x_x1864;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1865 = kk_src_effects_prat__resonance__as_Snapshot(s, _ctx);
    kk_string_t _x_2 = _con_x1865->output_preview;
    kk_string_dup(_x_2, _ctx);
    _x_x1864 = _x_2; /*string*/
  }
  kk_string_t _x_x1866;
  kk_string_t _x_x1867;
  kk_define_string_literal(, _s_x1868, 2, "\",", _ctx)
  _x_x1867 = kk_string_dup(_s_x1868, _ctx); /*string*/
  kk_string_t _x_x1869;
  kk_string_t _x_x1870;
  kk_define_string_literal(, _s_x1871, 13, "\"timestamp\": ", _ctx)
  _x_x1870 = kk_string_dup(_s_x1871, _ctx); /*string*/
  kk_string_t _x_x1872;
  kk_string_t _x_x1873;
  double _x_x1874;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1875 = kk_src_effects_prat__resonance__as_Snapshot(s, _ctx);
    double _x_3 = _con_x1875->timestamp;
    _x_x1874 = _x_3; /*float64*/
  }
  _x_x1873 = kk_std_num_float64_show(_x_x1874, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x1876;
  kk_string_t _x_x1877;
  kk_define_string_literal(, _s_x1878, 1, ",", _ctx)
  _x_x1877 = kk_string_dup(_s_x1878, _ctx); /*string*/
  kk_string_t _x_x1879;
  kk_string_t _x_x1880;
  kk_define_string_literal(, _s_x1881, 15, "\"lunar_phase\": ", _ctx)
  _x_x1880 = kk_string_dup(_s_x1881, _ctx); /*string*/
  kk_string_t _x_x1882;
  kk_string_t _x_x1883;
  double _x_x1884;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1885 = kk_src_effects_prat__resonance__as_Snapshot(s, _ctx);
    double _x_4 = _con_x1885->lunar_phase;
    _x_x1884 = _x_4; /*float64*/
  }
  _x_x1883 = kk_std_num_float64_show(_x_x1884, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x1886;
  kk_string_t _x_x1887;
  kk_define_string_literal(, _s_x1888, 1, ",", _ctx)
  _x_x1887 = kk_string_dup(_s_x1888, _ctx); /*string*/
  kk_string_t _x_x1889;
  kk_string_t _x_x1890;
  kk_define_string_literal(, _s_x1891, 21, "\"lunar_mansion_num\": ", _ctx)
  _x_x1890 = kk_string_dup(_s_x1891, _ctx); /*string*/
  kk_string_t _x_x1892;
  kk_string_t _x_x1893;
  kk_integer_t _x_x1894;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1895 = kk_src_effects_prat__resonance__as_Snapshot(s, _ctx);
    kk_integer_t _x_5 = _con_x1895->lunar_mansion_num;
    kk_integer_dup(_x_5, _ctx);
    _x_x1894 = _x_5; /*int*/
  }
  _x_x1893 = kk_std_core_int_show(_x_x1894, _ctx); /*string*/
  kk_string_t _x_x1896;
  kk_string_t _x_x1897;
  kk_define_string_literal(, _s_x1898, 1, ",", _ctx)
  _x_x1897 = kk_string_dup(_s_x1898, _ctx); /*string*/
  kk_string_t _x_x1899;
  kk_string_t _x_x1900;
  kk_define_string_literal(, _s_x1901, 17, "\"harmony_score\": ", _ctx)
  _x_x1900 = kk_string_dup(_s_x1901, _ctx); /*string*/
  kk_string_t _x_x1902;
  kk_string_t _x_x1903;
  double _x_x1904;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1905 = kk_src_effects_prat__resonance__as_Snapshot(s, _ctx);
    double _x_6 = _con_x1905->harmony_score;
    _x_x1904 = _x_6; /*float64*/
  }
  _x_x1903 = kk_std_num_float64_show(_x_x1904, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x1906;
  kk_string_t _x_x1907;
  kk_define_string_literal(, _s_x1908, 1, ",", _ctx)
  _x_x1907 = kk_string_dup(_s_x1908, _ctx); /*string*/
  kk_string_t _x_x1909;
  kk_string_t _x_x1910;
  kk_define_string_literal(, _s_x1911, 13, "\"guna_tag\": \"", _ctx)
  _x_x1910 = kk_string_dup(_s_x1911, _ctx); /*string*/
  kk_string_t _x_x1912;
  kk_string_t _x_x1913;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1914 = kk_src_effects_prat__resonance__as_Snapshot(s, _ctx);
    kk_string_t _x_7 = _con_x1914->guna_tag;
    kk_string_dup(_x_7, _ctx);
    _x_x1913 = _x_7; /*string*/
  }
  kk_string_t _x_x1915;
  kk_string_t _x_x1916;
  kk_define_string_literal(, _s_x1917, 2, "\",", _ctx)
  _x_x1916 = kk_string_dup(_s_x1917, _ctx); /*string*/
  kk_string_t _x_x1918;
  kk_string_t _x_x1919;
  kk_define_string_literal(, _s_x1920, 13, "\"quadrant\": \"", _ctx)
  _x_x1919 = kk_string_dup(_s_x1920, _ctx); /*string*/
  kk_string_t _x_x1921;
  kk_string_t _x_x1922;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1923 = kk_src_effects_prat__resonance__as_Snapshot(s, _ctx);
    kk_string_t _pat_0_8 = _con_x1923->gana_name;
    kk_string_t _pat_1_8 = _con_x1923->tool_name;
    kk_string_t _pat_2_8 = _con_x1923->operation;
    kk_string_t _pat_3_8 = _con_x1923->output_preview;
    kk_integer_t _pat_6_8 = _con_x1923->lunar_mansion_num;
    kk_string_t _pat_8_8 = _con_x1923->guna_tag;
    kk_string_t _x_8 = _con_x1923->quadrant;
    kk_string_t _pat_9_8 = _con_x1923->successor_hint;
    if kk_likely(kk_datatype_ptr_is_unique(s, _ctx)) {
      kk_string_drop(_pat_9_8, _ctx);
      kk_string_drop(_pat_8_8, _ctx);
      kk_integer_drop(_pat_6_8, _ctx);
      kk_string_drop(_pat_3_8, _ctx);
      kk_string_drop(_pat_2_8, _ctx);
      kk_string_drop(_pat_1_8, _ctx);
      kk_string_drop(_pat_0_8, _ctx);
      kk_datatype_ptr_free(s, _ctx);
    }
    else {
      kk_string_dup(_x_8, _ctx);
      kk_datatype_ptr_decref(s, _ctx);
    }
    _x_x1922 = _x_8; /*string*/
  }
  kk_string_t _x_x1924;
  kk_string_t _x_x1925;
  kk_define_string_literal(, _s_x1926, 2, "\",", _ctx)
  _x_x1925 = kk_string_dup(_s_x1926, _ctx); /*string*/
  kk_string_t _x_x1927;
  kk_string_t _x_x1928;
  kk_define_string_literal(, _s_x1929, 19, "\"successor_hint\": \"", _ctx)
  _x_x1928 = kk_string_dup(_s_x1929, _ctx); /*string*/
  kk_string_t _x_x1930;
  kk_string_t _x_x1931;
  {
    struct kk_src_effects_prat__resonance_Snapshot* _con_x1932 = kk_src_effects_prat__resonance__as_Snapshot(snapshot_9_10062, _ctx);
    kk_string_t _pat_0_9 = _con_x1932->gana_name;
    kk_string_t _pat_1_9 = _con_x1932->tool_name;
    kk_string_t _pat_2_9 = _con_x1932->operation;
    kk_string_t _pat_3_9 = _con_x1932->output_preview;
    kk_integer_t _pat_6_9 = _con_x1932->lunar_mansion_num;
    kk_string_t _pat_8_9 = _con_x1932->guna_tag;
    kk_string_t _pat_9_9 = _con_x1932->quadrant;
    kk_string_t _x_9 = _con_x1932->successor_hint;
    if kk_likely(kk_datatype_ptr_is_unique(snapshot_9_10062, _ctx)) {
      kk_string_drop(_pat_9_9, _ctx);
      kk_string_drop(_pat_8_9, _ctx);
      kk_integer_drop(_pat_6_9, _ctx);
      kk_string_drop(_pat_3_9, _ctx);
      kk_string_drop(_pat_2_9, _ctx);
      kk_string_drop(_pat_1_9, _ctx);
      kk_string_drop(_pat_0_9, _ctx);
      kk_datatype_ptr_free(snapshot_9_10062, _ctx);
    }
    else {
      kk_string_dup(_x_9, _ctx);
      kk_datatype_ptr_decref(snapshot_9_10062, _ctx);
    }
    _x_x1931 = _x_9; /*string*/
  }
  kk_string_t _x_x1933;
  kk_string_t _x_x1934;
  kk_define_string_literal(, _s_x1935, 1, "\"", _ctx)
  _x_x1934 = kk_string_dup(_s_x1935, _ctx); /*string*/
  kk_string_t _x_x1936;
  kk_define_string_literal(, _s_x1937, 1, "}", _ctx)
  _x_x1936 = kk_string_dup(_s_x1937, _ctx); /*string*/
  _x_x1933 = kk_std_core_types__lp__plus__plus__rp_(_x_x1934, _x_x1936, _ctx); /*string*/
  _x_x1930 = kk_std_core_types__lp__plus__plus__rp_(_x_x1931, _x_x1933, _ctx); /*string*/
  _x_x1927 = kk_std_core_types__lp__plus__plus__rp_(_x_x1928, _x_x1930, _ctx); /*string*/
  _x_x1924 = kk_std_core_types__lp__plus__plus__rp_(_x_x1925, _x_x1927, _ctx); /*string*/
  _x_x1921 = kk_std_core_types__lp__plus__plus__rp_(_x_x1922, _x_x1924, _ctx); /*string*/
  _x_x1918 = kk_std_core_types__lp__plus__plus__rp_(_x_x1919, _x_x1921, _ctx); /*string*/
  _x_x1915 = kk_std_core_types__lp__plus__plus__rp_(_x_x1916, _x_x1918, _ctx); /*string*/
  _x_x1912 = kk_std_core_types__lp__plus__plus__rp_(_x_x1913, _x_x1915, _ctx); /*string*/
  _x_x1909 = kk_std_core_types__lp__plus__plus__rp_(_x_x1910, _x_x1912, _ctx); /*string*/
  _x_x1906 = kk_std_core_types__lp__plus__plus__rp_(_x_x1907, _x_x1909, _ctx); /*string*/
  _x_x1902 = kk_std_core_types__lp__plus__plus__rp_(_x_x1903, _x_x1906, _ctx); /*string*/
  _x_x1899 = kk_std_core_types__lp__plus__plus__rp_(_x_x1900, _x_x1902, _ctx); /*string*/
  _x_x1896 = kk_std_core_types__lp__plus__plus__rp_(_x_x1897, _x_x1899, _ctx); /*string*/
  _x_x1892 = kk_std_core_types__lp__plus__plus__rp_(_x_x1893, _x_x1896, _ctx); /*string*/
  _x_x1889 = kk_std_core_types__lp__plus__plus__rp_(_x_x1890, _x_x1892, _ctx); /*string*/
  _x_x1886 = kk_std_core_types__lp__plus__plus__rp_(_x_x1887, _x_x1889, _ctx); /*string*/
  _x_x1882 = kk_std_core_types__lp__plus__plus__rp_(_x_x1883, _x_x1886, _ctx); /*string*/
  _x_x1879 = kk_std_core_types__lp__plus__plus__rp_(_x_x1880, _x_x1882, _ctx); /*string*/
  _x_x1876 = kk_std_core_types__lp__plus__plus__rp_(_x_x1877, _x_x1879, _ctx); /*string*/
  _x_x1872 = kk_std_core_types__lp__plus__plus__rp_(_x_x1873, _x_x1876, _ctx); /*string*/
  _x_x1869 = kk_std_core_types__lp__plus__plus__rp_(_x_x1870, _x_x1872, _ctx); /*string*/
  _x_x1866 = kk_std_core_types__lp__plus__plus__rp_(_x_x1867, _x_x1869, _ctx); /*string*/
  _x_x1863 = kk_std_core_types__lp__plus__plus__rp_(_x_x1864, _x_x1866, _ctx); /*string*/
  _x_x1860 = kk_std_core_types__lp__plus__plus__rp_(_x_x1861, _x_x1863, _ctx); /*string*/
  _x_x1857 = kk_std_core_types__lp__plus__plus__rp_(_x_x1858, _x_x1860, _ctx); /*string*/
  _x_x1854 = kk_std_core_types__lp__plus__plus__rp_(_x_x1855, _x_x1857, _ctx); /*string*/
  _x_x1851 = kk_std_core_types__lp__plus__plus__rp_(_x_x1852, _x_x1854, _ctx); /*string*/
  _x_x1848 = kk_std_core_types__lp__plus__plus__rp_(_x_x1849, _x_x1851, _ctx); /*string*/
  _x_x1845 = kk_std_core_types__lp__plus__plus__rp_(_x_x1846, _x_x1848, _ctx); /*string*/
  _x_x1842 = kk_std_core_types__lp__plus__plus__rp_(_x_x1843, _x_x1845, _ctx); /*string*/
  _x_x1839 = kk_std_core_types__lp__plus__plus__rp_(_x_x1840, _x_x1842, _ctx); /*string*/
  _x_x1836 = kk_std_core_types__lp__plus__plus__rp_(_x_x1837, _x_x1839, _ctx); /*string*/
  _x_x1833 = kk_std_core_types__lp__plus__plus__rp_(_x_x1834, _x_x1836, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1831, _x_x1833, _ctx);
}

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance_resonance_hints_fs__copy(kk_src_effects_prat__resonance__resonance_hints _this, kk_std_core_types__optional predecessor, kk_std_core_types__optional successor, kk_std_core_types__optional lunar_phase, kk_std_core_types__optional lunar_mansion_num, kk_std_core_types__optional harmony_score, kk_std_core_types__optional guna_tag, kk_std_core_types__optional quadrant, kk_context_t* _ctx) { /* (resonance-hints, predecessor : ? string, successor : ? string, lunar-phase : ? float64, lunar-mansion-num : ? int, harmony-score : ? float64, guna-tag : ? string, quadrant : ? string) -> resonance-hints */ 
  kk_string_t _x_x1938;
  if (kk_std_core_types__is_Optional(predecessor, _ctx)) {
    kk_box_t _box_x616 = predecessor._cons._Optional.value;
    kk_string_t _uniq_predecessor_5210 = kk_string_unbox(_box_x616);
    kk_string_dup(_uniq_predecessor_5210, _ctx);
    kk_std_core_types__optional_drop(predecessor, _ctx);
    _x_x1938 = _uniq_predecessor_5210; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(predecessor, _ctx);
    {
      struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1939 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
      kk_string_t _x = _con_x1939->predecessor;
      kk_string_dup(_x, _ctx);
      _x_x1938 = _x; /*string*/
    }
  }
  kk_string_t _x_x1940;
  if (kk_std_core_types__is_Optional(successor, _ctx)) {
    kk_box_t _box_x617 = successor._cons._Optional.value;
    kk_string_t _uniq_successor_5218 = kk_string_unbox(_box_x617);
    kk_string_dup(_uniq_successor_5218, _ctx);
    kk_std_core_types__optional_drop(successor, _ctx);
    _x_x1940 = _uniq_successor_5218; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(successor, _ctx);
    {
      struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1941 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
      kk_string_t _x_0 = _con_x1941->successor;
      kk_string_dup(_x_0, _ctx);
      _x_x1940 = _x_0; /*string*/
    }
  }
  double _x_x1942;
  if (kk_std_core_types__is_Optional(lunar_phase, _ctx)) {
    kk_box_t _box_x618 = lunar_phase._cons._Optional.value;
    double _uniq_lunar_phase_5226 = kk_double_unbox(_box_x618, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(lunar_phase, _ctx);
    _x_x1942 = _uniq_lunar_phase_5226; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(lunar_phase, _ctx);
    {
      struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1943 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
      double _x_1 = _con_x1943->lunar_phase;
      _x_x1942 = _x_1; /*float64*/
    }
  }
  kk_integer_t _x_x1944;
  if (kk_std_core_types__is_Optional(lunar_mansion_num, _ctx)) {
    kk_box_t _box_x619 = lunar_mansion_num._cons._Optional.value;
    kk_integer_t _uniq_lunar_mansion_num_5234 = kk_integer_unbox(_box_x619, _ctx);
    kk_integer_dup(_uniq_lunar_mansion_num_5234, _ctx);
    kk_std_core_types__optional_drop(lunar_mansion_num, _ctx);
    _x_x1944 = _uniq_lunar_mansion_num_5234; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(lunar_mansion_num, _ctx);
    {
      struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1945 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
      kk_integer_t _x_2 = _con_x1945->lunar_mansion_num;
      kk_integer_dup(_x_2, _ctx);
      _x_x1944 = _x_2; /*int*/
    }
  }
  double _x_x1946;
  if (kk_std_core_types__is_Optional(harmony_score, _ctx)) {
    kk_box_t _box_x620 = harmony_score._cons._Optional.value;
    double _uniq_harmony_score_5242 = kk_double_unbox(_box_x620, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(harmony_score, _ctx);
    _x_x1946 = _uniq_harmony_score_5242; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(harmony_score, _ctx);
    {
      struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1947 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
      double _x_3 = _con_x1947->harmony_score;
      _x_x1946 = _x_3; /*float64*/
    }
  }
  kk_string_t _x_x1948;
  if (kk_std_core_types__is_Optional(guna_tag, _ctx)) {
    kk_box_t _box_x621 = guna_tag._cons._Optional.value;
    kk_string_t _uniq_guna_tag_5250 = kk_string_unbox(_box_x621);
    kk_string_dup(_uniq_guna_tag_5250, _ctx);
    kk_std_core_types__optional_drop(guna_tag, _ctx);
    _x_x1948 = _uniq_guna_tag_5250; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(guna_tag, _ctx);
    {
      struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1949 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
      kk_string_t _x_4 = _con_x1949->guna_tag;
      kk_string_dup(_x_4, _ctx);
      _x_x1948 = _x_4; /*string*/
    }
  }
  kk_string_t _x_x1950;
  if (kk_std_core_types__is_Optional(quadrant, _ctx)) {
    kk_box_t _box_x622 = quadrant._cons._Optional.value;
    kk_string_t _uniq_quadrant_5258 = kk_string_unbox(_box_x622);
    kk_string_dup(_uniq_quadrant_5258, _ctx);
    kk_std_core_types__optional_drop(quadrant, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(5)), _ctx);
    _x_x1950 = _uniq_quadrant_5258; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(quadrant, _ctx);
    {
      struct kk_src_effects_prat__resonance_Resonance_hints* _con_x1951 = kk_src_effects_prat__resonance__as_Resonance_hints(_this, _ctx);
      kk_string_t _pat_0_6 = _con_x1951->predecessor;
      kk_string_t _pat_1_7 = _con_x1951->successor;
      kk_integer_t _pat_3_6 = _con_x1951->lunar_mansion_num;
      kk_string_t _pat_5_6 = _con_x1951->guna_tag;
      kk_string_t _x_5 = _con_x1951->quadrant;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_5_6, _ctx);
        kk_integer_drop(_pat_3_6, _ctx);
        kk_string_drop(_pat_1_7, _ctx);
        kk_string_drop(_pat_0_6, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_string_dup(_x_5, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1950 = _x_5; /*string*/
    }
  }
  return kk_src_effects_prat__resonance__new_Resonance_hints(kk_reuse_null, 0, _x_x1938, _x_x1940, _x_x1942, _x_x1944, _x_x1946, _x_x1948, _x_x1950, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_generate_hints_10115_fun1954__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_generate_hints_10115_fun1954(kk_function_t _fself, kk_box_t _b_x625, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_generate_hints_10115_fun1954(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance__mlift_generate_hints_10115_fun1954, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_generate_hints_10115_fun1954(kk_function_t _fself, kk_box_t _b_x625, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1955;
  kk_src_effects_prat__resonance__ganainfo ganainfo_628 = kk_src_effects_prat__resonance__ganainfo_unbox(_b_x625, KK_OWNED, _ctx); /*src/effects/prat_resonance/ganainfo*/;
  {
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x1956 = kk_src_effects_prat__resonance__as_Ganainfo(ganainfo_628, _ctx);
    kk_integer_t _pat_0_1 = _con_x1956->mansion_num;
    kk_string_t _x_0 = _con_x1956->quadrant;
    kk_string_t _pat_1_1 = _con_x1956->meaning;
    kk_string_t _pat_2_0 = _con_x1956->garden;
    kk_string_t _pat_3_0 = _con_x1956->chinese;
    kk_string_t _pat_4_0 = _con_x1956->pinyin;
    if kk_likely(kk_datatype_ptr_is_unique(ganainfo_628, _ctx)) {
      kk_string_drop(_pat_4_0, _ctx);
      kk_string_drop(_pat_3_0, _ctx);
      kk_string_drop(_pat_2_0, _ctx);
      kk_string_drop(_pat_1_1, _ctx);
      kk_integer_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(ganainfo_628, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(ganainfo_628, _ctx);
    }
    _x_x1955 = _x_0; /*string*/
  }
  return kk_string_box(_x_x1955);
}

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__mlift_generate_hints_10115(double _y_x10089, kk_integer_t _y_x10090, double _y_x10091, kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, kk_string_t _y_x10092, kk_context_t* _ctx) { /* (float64, int, float64, meta@0 : ganainfo, pred : string, succ : string, string) -> resonance resonance-hints */ 
  kk_string_t _x_x1952;
  kk_box_t _x_x1953 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance__new_mlift_generate_hints_10115_fun1954(_ctx), kk_src_effects_prat__resonance__ganainfo_box(meta_0, _ctx), _ctx); /*10001*/
  _x_x1952 = kk_string_unbox(_x_x1953); /*string*/
  return kk_src_effects_prat__resonance__new_Resonance_hints(kk_reuse_null, 0, pred, succ, _y_x10089, _y_x10090, _y_x10091, _y_x10092, _x_x1952, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1960__t {
  struct kk_function_s _base;
  kk_integer_t _y_x10090;
  kk_src_effects_prat__resonance__ganainfo meta_0;
  kk_string_t pred;
  kk_string_t succ;
  double _y_x10089;
  double _y_x10091;
};
static kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1960(kk_function_t _fself, kk_string_t _y_x10092, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_generate_hints_10116_fun1960(kk_integer_t _y_x10090, kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, double _y_x10089, double _y_x10091, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1960__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1960__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1960, kk_context());
  _self->_y_x10090 = _y_x10090;
  _self->meta_0 = meta_0;
  _self->pred = pred;
  _self->succ = succ;
  _self->_y_x10089 = _y_x10089;
  _self->_y_x10091 = _y_x10091;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1963__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1963(kk_function_t _fself, kk_box_t _b_x637, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_generate_hints_10116_fun1963(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1963, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1963(kk_function_t _fself, kk_box_t _b_x637, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1964;
  kk_src_effects_prat__resonance__ganainfo _match_x866 = kk_src_effects_prat__resonance__ganainfo_unbox(_b_x637, KK_OWNED, _ctx); /*src/effects/prat_resonance/ganainfo*/;
  {
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x1965 = kk_src_effects_prat__resonance__as_Ganainfo(_match_x866, _ctx);
    kk_integer_t _pat_0_1 = _con_x1965->mansion_num;
    kk_string_t _x_0 = _con_x1965->quadrant;
    kk_string_t _pat_1_1_0 = _con_x1965->meaning;
    kk_string_t _pat_2_0_0 = _con_x1965->garden;
    kk_string_t _pat_3_0 = _con_x1965->chinese;
    kk_string_t _pat_4_0 = _con_x1965->pinyin;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x866, _ctx)) {
      kk_string_drop(_pat_4_0, _ctx);
      kk_string_drop(_pat_3_0, _ctx);
      kk_string_drop(_pat_2_0_0, _ctx);
      kk_string_drop(_pat_1_1_0, _ctx);
      kk_integer_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(_match_x866, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x866, _ctx);
    }
    _x_x1964 = _x_0; /*string*/
  }
  return kk_string_box(_x_x1964);
}
static kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1960(kk_function_t _fself, kk_string_t _y_x10092, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1960__t* _self = kk_function_as(struct kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1960__t*, _fself, _ctx);
  kk_integer_t _y_x10090 = _self->_y_x10090; /* int */
  kk_src_effects_prat__resonance__ganainfo meta_0 = _self->meta_0; /* src/effects/prat_resonance/ganainfo */
  kk_string_t pred = _self->pred; /* string */
  kk_string_t succ = _self->succ; /* string */
  double _y_x10089 = _self->_y_x10089; /* float64 */
  double _y_x10091 = _self->_y_x10091; /* float64 */
  kk_drop_match(_self, {kk_integer_dup(_y_x10090, _ctx);kk_src_effects_prat__resonance__ganainfo_dup(meta_0, _ctx);kk_string_dup(pred, _ctx);kk_string_dup(succ, _ctx);kk_skip_dup(_y_x10089, _ctx);kk_skip_dup(_y_x10091, _ctx);}, {}, _ctx)
  kk_string_t _x_x1961;
  kk_box_t _x_x1962 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance__new_mlift_generate_hints_10116_fun1963(_ctx), kk_src_effects_prat__resonance__ganainfo_box(meta_0, _ctx), _ctx); /*10001*/
  _x_x1961 = kk_string_unbox(_x_x1962); /*string*/
  return kk_src_effects_prat__resonance__new_Resonance_hints(kk_reuse_null, 0, pred, succ, _y_x10089, _y_x10090, _y_x10091, _y_x10092, _x_x1961, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1967__t {
  struct kk_function_s _base;
  kk_function_t next_10157;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1967(kk_function_t _fself, kk_box_t _b_x642, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_generate_hints_10116_fun1967(kk_function_t next_10157, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1967__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1967__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1967, kk_context());
  _self->next_10157 = next_10157;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1967(kk_function_t _fself, kk_box_t _b_x642, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1967__t* _self = kk_function_as(struct kk_src_effects_prat__resonance__mlift_generate_hints_10116_fun1967__t*, _fself, _ctx);
  kk_function_t next_10157 = _self->next_10157; /* (string) -> src/effects/prat_resonance/resonance src/effects/prat_resonance/resonance-hints */
  kk_drop_match(_self, {kk_function_dup(next_10157, _ctx);}, {}, _ctx)
  kk_src_effects_prat__resonance__resonance_hints _x_x1968;
  kk_string_t _x_x1969 = kk_string_unbox(_b_x642); /*string*/
  _x_x1968 = kk_function_call(kk_src_effects_prat__resonance__resonance_hints, (kk_function_t, kk_string_t, kk_context_t*), next_10157, (next_10157, _x_x1969, _ctx), _ctx); /*src/effects/prat_resonance/resonance-hints*/
  return kk_src_effects_prat__resonance__resonance_hints_box(_x_x1968, _ctx);
}

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__mlift_generate_hints_10116(double _y_x10089, kk_integer_t _y_x10090, kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, double _y_x10091, kk_context_t* _ctx) { /* (float64, int, meta@0 : ganainfo, pred : string, succ : string, float64) -> resonance resonance-hints */ 
  kk_std_core_hnd__ev ev_10158 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_string_t x_10156;
  kk_box_t _x_x1957;
  {
    struct kk_std_core_hnd_Ev* _con_x1958 = kk_std_core_hnd__as_Ev(ev_10158, _ctx);
    kk_box_t _box_x629 = _con_x1958->hnd;
    int32_t m = _con_x1958->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x629, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x1959 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0 = _con_x1959->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x1959->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2 = _con_x1959->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _fun_get_guna_tag = _con_x1959->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_3 = _con_x1959->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_4 = _con_x1959->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_5 = _con_x1959->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_6 = _con_x1959->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_7 = _con_x1959->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8 = _con_x1959->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x1959->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_guna_tag, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x632 = _fun_get_guna_tag.clause;
        _x_x1957 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x632, (_fun_unbox_x632, m, ev_10158, _ctx), _ctx); /*10005*/
      }
    }
  }
  x_10156 = kk_string_unbox(_x_x1957); /*string*/
  kk_function_t next_10157 = kk_src_effects_prat__resonance__new_mlift_generate_hints_10116_fun1960(_y_x10090, meta_0, pred, succ, _y_x10089, _y_x10091, _ctx); /*(string) -> src/effects/prat_resonance/resonance src/effects/prat_resonance/resonance-hints*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10156, _ctx);
    kk_box_t _x_x1966 = kk_std_core_hnd_yield_extend(kk_src_effects_prat__resonance__new_mlift_generate_hints_10116_fun1967(next_10157, _ctx), _ctx); /*10001*/
    return kk_src_effects_prat__resonance__resonance_hints_unbox(_x_x1966, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_src_effects_prat__resonance__resonance_hints, (kk_function_t, kk_string_t, kk_context_t*), next_10157, (next_10157, x_10156, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_generate_hints_10117_fun1974__t {
  struct kk_function_s _base;
  kk_integer_t _y_x10090;
  kk_src_effects_prat__resonance__ganainfo meta_0;
  kk_string_t pred;
  kk_string_t succ;
  double _y_x10089;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_generate_hints_10117_fun1974(kk_function_t _fself, kk_box_t _b_x651, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_generate_hints_10117_fun1974(kk_integer_t _y_x10090, kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, double _y_x10089, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance__mlift_generate_hints_10117_fun1974__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance__mlift_generate_hints_10117_fun1974__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance__mlift_generate_hints_10117_fun1974, kk_context());
  _self->_y_x10090 = _y_x10090;
  _self->meta_0 = meta_0;
  _self->pred = pred;
  _self->succ = succ;
  _self->_y_x10089 = _y_x10089;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_generate_hints_10117_fun1974(kk_function_t _fself, kk_box_t _b_x651, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance__mlift_generate_hints_10117_fun1974__t* _self = kk_function_as(struct kk_src_effects_prat__resonance__mlift_generate_hints_10117_fun1974__t*, _fself, _ctx);
  kk_integer_t _y_x10090 = _self->_y_x10090; /* int */
  kk_src_effects_prat__resonance__ganainfo meta_0 = _self->meta_0; /* src/effects/prat_resonance/ganainfo */
  kk_string_t pred = _self->pred; /* string */
  kk_string_t succ = _self->succ; /* string */
  double _y_x10089 = _self->_y_x10089; /* float64 */
  kk_drop_match(_self, {kk_integer_dup(_y_x10090, _ctx);kk_src_effects_prat__resonance__ganainfo_dup(meta_0, _ctx);kk_string_dup(pred, _ctx);kk_string_dup(succ, _ctx);kk_skip_dup(_y_x10089, _ctx);}, {}, _ctx)
  double _y_x10091_653 = kk_double_unbox(_b_x651, KK_OWNED, _ctx); /*float64*/;
  kk_src_effects_prat__resonance__resonance_hints _x_x1975 = kk_src_effects_prat__resonance__mlift_generate_hints_10116(_y_x10089, _y_x10090, meta_0, pred, succ, _y_x10091_653, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  return kk_src_effects_prat__resonance__resonance_hints_box(_x_x1975, _ctx);
}

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__mlift_generate_hints_10117(double _y_x10089, kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, kk_integer_t _y_x10090, kk_context_t* _ctx) { /* (float64, meta@0 : ganainfo, pred : string, succ : string, int) -> resonance resonance-hints */ 
  kk_std_core_hnd__ev ev_10169 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  double x_10167;
  kk_box_t _x_x1970;
  {
    struct kk_std_core_hnd_Ev* _con_x1971 = kk_std_core_hnd__as_Ev(ev_10169, _ctx);
    kk_box_t _box_x644 = _con_x1971->hnd;
    int32_t m = _con_x1971->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x644, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x1972 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0 = _con_x1972->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x1972->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2 = _con_x1972->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_3 = _con_x1972->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _fun_get_harmony_score = _con_x1972->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_4 = _con_x1972->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_5 = _con_x1972->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_6 = _con_x1972->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_7 = _con_x1972->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8 = _con_x1972->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x1972->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_harmony_score, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x647 = _fun_get_harmony_score.clause;
        _x_x1970 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x647, (_fun_unbox_x647, m, ev_10169, _ctx), _ctx); /*10005*/
      }
    }
  }
  x_10167 = kk_double_unbox(_x_x1970, KK_OWNED, _ctx); /*float64*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1973 = kk_std_core_hnd_yield_extend(kk_src_effects_prat__resonance__new_mlift_generate_hints_10117_fun1974(_y_x10090, meta_0, pred, succ, _y_x10089, _ctx), _ctx); /*10001*/
    return kk_src_effects_prat__resonance__resonance_hints_unbox(_x_x1973, KK_OWNED, _ctx);
  }
  {
    return kk_src_effects_prat__resonance__mlift_generate_hints_10116(_y_x10089, _y_x10090, meta_0, pred, succ, x_10167, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_generate_hints_10118_fun1980__t {
  struct kk_function_s _base;
  kk_src_effects_prat__resonance__ganainfo meta_0;
  kk_string_t pred;
  kk_string_t succ;
  double _y_x10089;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_generate_hints_10118_fun1980(kk_function_t _fself, kk_box_t _b_x661, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_generate_hints_10118_fun1980(kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, double _y_x10089, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance__mlift_generate_hints_10118_fun1980__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance__mlift_generate_hints_10118_fun1980__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance__mlift_generate_hints_10118_fun1980, kk_context());
  _self->meta_0 = meta_0;
  _self->pred = pred;
  _self->succ = succ;
  _self->_y_x10089 = _y_x10089;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_generate_hints_10118_fun1980(kk_function_t _fself, kk_box_t _b_x661, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance__mlift_generate_hints_10118_fun1980__t* _self = kk_function_as(struct kk_src_effects_prat__resonance__mlift_generate_hints_10118_fun1980__t*, _fself, _ctx);
  kk_src_effects_prat__resonance__ganainfo meta_0 = _self->meta_0; /* src/effects/prat_resonance/ganainfo */
  kk_string_t pred = _self->pred; /* string */
  kk_string_t succ = _self->succ; /* string */
  double _y_x10089 = _self->_y_x10089; /* float64 */
  kk_drop_match(_self, {kk_src_effects_prat__resonance__ganainfo_dup(meta_0, _ctx);kk_string_dup(pred, _ctx);kk_string_dup(succ, _ctx);kk_skip_dup(_y_x10089, _ctx);}, {}, _ctx)
  kk_integer_t _y_x10090_663 = kk_integer_unbox(_b_x661, _ctx); /*int*/;
  kk_src_effects_prat__resonance__resonance_hints _x_x1981 = kk_src_effects_prat__resonance__mlift_generate_hints_10117(_y_x10089, meta_0, pred, succ, _y_x10090_663, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  return kk_src_effects_prat__resonance__resonance_hints_box(_x_x1981, _ctx);
}

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance__mlift_generate_hints_10118(kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, double _y_x10089, kk_context_t* _ctx) { /* (meta@0 : ganainfo, pred : string, succ : string, float64) -> resonance resonance-hints */ 
  kk_std_core_hnd__ev ev_10173 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_integer_t x_10171;
  kk_box_t _x_x1976;
  {
    struct kk_std_core_hnd_Ev* _con_x1977 = kk_std_core_hnd__as_Ev(ev_10173, _ctx);
    kk_box_t _box_x654 = _con_x1977->hnd;
    int32_t m = _con_x1977->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x654, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x1978 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0 = _con_x1978->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x1978->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2 = _con_x1978->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_3 = _con_x1978->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_4 = _con_x1978->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_5 = _con_x1978->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _fun_get_lunar_mansion = _con_x1978->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_6 = _con_x1978->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_7 = _con_x1978->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8 = _con_x1978->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9 = _con_x1978->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_7, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_lunar_mansion, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x657 = _fun_get_lunar_mansion.clause;
        _x_x1976 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x657, (_fun_unbox_x657, m, ev_10173, _ctx), _ctx); /*10005*/
      }
    }
  }
  x_10171 = kk_integer_unbox(_x_x1976, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10171, _ctx);
    kk_box_t _x_x1979 = kk_std_core_hnd_yield_extend(kk_src_effects_prat__resonance__new_mlift_generate_hints_10118_fun1980(meta_0, pred, succ, _y_x10089, _ctx), _ctx); /*10001*/
    return kk_src_effects_prat__resonance__resonance_hints_unbox(_x_x1979, KK_OWNED, _ctx);
  }
  {
    return kk_src_effects_prat__resonance__mlift_generate_hints_10117(_y_x10089, meta_0, pred, succ, x_10171, _ctx);
  }
}


// lift anonymous function
struct kk_src_effects_prat__resonance_generate_hints_fun1983__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun1983(kk_function_t _fself, kk_box_t _b_x666, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_generate_hints_fun1983(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_generate_hints_fun1983, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun1983(kk_function_t _fself, kk_box_t _b_x666, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1984;
  kk_string_t _x_x1985 = kk_string_unbox(_b_x666); /*string*/
  _x_x1984 = kk_src_effects_prat__resonance_get_predecessor(_x_x1985, _ctx); /*string*/
  return kk_string_box(_x_x1984);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_generate_hints_fun1989__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun1989(kk_function_t _fself, kk_box_t _b_x671, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_generate_hints_fun1989(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_generate_hints_fun1989, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun1989(kk_function_t _fself, kk_box_t _b_x671, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1990;
  kk_string_t _x_x1991 = kk_string_unbox(_b_x671); /*string*/
  _x_x1990 = kk_src_effects_prat__resonance_get_successor(_x_x1991, _ctx); /*string*/
  return kk_string_box(_x_x1990);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_generate_hints_fun1995__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun1995(kk_function_t _fself, kk_box_t _b_x684, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_generate_hints_fun1995(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_generate_hints_fun1995, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_effects_prat__resonance_generate_hints_fun1999__t {
  struct kk_function_s _base;
  kk_box_t _b_x684;
};
static bool kk_src_effects_prat__resonance_generate_hints_fun1999(kk_function_t _fself, kk_box_t _b_x678, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_generate_hints_fun1999(kk_box_t _b_x684, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun1999__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_generate_hints_fun1999__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_generate_hints_fun1999, kk_context());
  _self->_b_x684 = _b_x684;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_src_effects_prat__resonance_generate_hints_fun1999(kk_function_t _fself, kk_box_t _b_x678, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun1999__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_generate_hints_fun1999__t*, _fself, _ctx);
  kk_box_t _b_x684 = _self->_b_x684; /* 10000 */
  kk_drop_match(_self, {kk_box_dup(_b_x684, _ctx);}, {}, _ctx)
  kk_string_t _x_x2000;
  kk_std_core_types__tuple2 _match_x862 = kk_std_core_types__tuple2_unbox(_b_x678, KK_OWNED, _ctx); /*(string, src/effects/prat_resonance/ganainfo)*/;
  {
    kk_box_t _box_x674 = _match_x862.fst;
    kk_box_t _box_x675 = _match_x862.snd;
    kk_string_t _x = kk_string_unbox(_box_x674);
    kk_string_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(_match_x862, _ctx);
    _x_x2000 = _x; /*string*/
  }
  kk_string_t _x_x2001 = kk_string_unbox(_b_x684); /*string*/
  return kk_string_is_eq(_x_x2000,_x_x2001,kk_context());
}
static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun1995(kk_function_t _fself, kk_box_t _b_x684, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_effects_prat__resonance__ganainfo _x_x1996;
  kk_std_core_types__maybe _match_x861;
  kk_std_core_types__list _x_x1997 = kk_std_core_types__list_dup(kk_src_effects_prat__resonance_gana_metadata, _ctx); /*list<(string, src/effects/prat_resonance/ganainfo)>*/
  kk_function_t _x_x1998;
  kk_box_dup(_b_x684, _ctx);
  _x_x1998 = kk_src_effects_prat__resonance_new_generate_hints_fun1999(_b_x684, _ctx); /*(10001) -> 10002 bool*/
  _match_x861 = kk_std_core_list_find(_x_x1997, _x_x1998, _ctx); /*maybe<10001>*/
  if (kk_std_core_types__is_Just(_match_x861, _ctx)) {
    kk_box_t _box_x679 = _match_x861._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0 = kk_std_core_types__tuple2_unbox(_box_x679, KK_BORROWED, _ctx);
    kk_box_t _box_x680 = _pat_0_0.fst;
    kk_box_t _box_x681 = _pat_0_0.snd;
    kk_src_effects_prat__resonance__ganainfo meta = kk_src_effects_prat__resonance__ganainfo_unbox(_box_x681, KK_BORROWED, _ctx);
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x2002 = kk_src_effects_prat__resonance__as_Ganainfo(meta, _ctx);
    kk_src_effects_prat__resonance__ganainfo_dup(meta, _ctx);
    kk_std_core_types__maybe_drop(_match_x861, _ctx);
    kk_box_drop(_b_x684, _ctx);
    _x_x1996 = meta; /*src/effects/prat_resonance/ganainfo*/
  }
  else {
    kk_string_t _x_x2003;
    kk_define_string_literal(, _s_x2004, 7, "Unknown", _ctx)
    _x_x2003 = kk_string_dup(_s_x2004, _ctx); /*string*/
    kk_string_t _x_x2005 = kk_string_unbox(_b_x684); /*string*/
    kk_string_t _x_x2006;
    kk_define_string_literal(, _s_x2007, 4, "None", _ctx)
    _x_x2006 = kk_string_dup(_s_x2007, _ctx); /*string*/
    kk_string_t _x_x2008;
    kk_define_string_literal(, _s_x2009, 1, "\?", _ctx)
    _x_x2008 = kk_string_dup(_s_x2009, _ctx); /*string*/
    kk_string_t _x_x2010;
    kk_define_string_literal(, _s_x2011, 1, "\?", _ctx)
    _x_x2010 = kk_string_dup(_s_x2011, _ctx); /*string*/
    _x_x1996 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(0), _x_x2003, _x_x2005, _x_x2006, _x_x2008, _x_x2010, _ctx); /*src/effects/prat_resonance/ganainfo*/
  }
  return kk_src_effects_prat__resonance__ganainfo_box(_x_x1996, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_generate_hints_fun2016__t {
  struct kk_function_s _base;
  kk_src_effects_prat__resonance__ganainfo meta_0;
  kk_string_t pred;
  kk_string_t succ;
};
static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2016(kk_function_t _fself, kk_box_t _b_x697, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_generate_hints_fun2016(kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun2016__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_generate_hints_fun2016__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_generate_hints_fun2016, kk_context());
  _self->meta_0 = meta_0;
  _self->pred = pred;
  _self->succ = succ;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2016(kk_function_t _fself, kk_box_t _b_x697, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun2016__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_generate_hints_fun2016__t*, _fself, _ctx);
  kk_src_effects_prat__resonance__ganainfo meta_0 = _self->meta_0; /* src/effects/prat_resonance/ganainfo */
  kk_string_t pred = _self->pred; /* string */
  kk_string_t succ = _self->succ; /* string */
  kk_drop_match(_self, {kk_src_effects_prat__resonance__ganainfo_dup(meta_0, _ctx);kk_string_dup(pred, _ctx);kk_string_dup(succ, _ctx);}, {}, _ctx)
  double _y_x10089_737 = kk_double_unbox(_b_x697, KK_OWNED, _ctx); /*float64*/;
  kk_src_effects_prat__resonance__resonance_hints _x_x2017 = kk_src_effects_prat__resonance__mlift_generate_hints_10118(meta_0, pred, succ, _y_x10089_737, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  return kk_src_effects_prat__resonance__resonance_hints_box(_x_x2017, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_generate_hints_fun2022__t {
  struct kk_function_s _base;
  kk_src_effects_prat__resonance__ganainfo meta_0;
  kk_string_t pred;
  kk_string_t succ;
  double x_10175;
};
static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2022(kk_function_t _fself, kk_box_t _b_x705, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_generate_hints_fun2022(kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, double x_10175, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun2022__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_generate_hints_fun2022__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_generate_hints_fun2022, kk_context());
  _self->meta_0 = meta_0;
  _self->pred = pred;
  _self->succ = succ;
  _self->x_10175 = x_10175;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2022(kk_function_t _fself, kk_box_t _b_x705, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun2022__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_generate_hints_fun2022__t*, _fself, _ctx);
  kk_src_effects_prat__resonance__ganainfo meta_0 = _self->meta_0; /* src/effects/prat_resonance/ganainfo */
  kk_string_t pred = _self->pred; /* string */
  kk_string_t succ = _self->succ; /* string */
  double x_10175 = _self->x_10175; /* float64 */
  kk_drop_match(_self, {kk_src_effects_prat__resonance__ganainfo_dup(meta_0, _ctx);kk_string_dup(pred, _ctx);kk_string_dup(succ, _ctx);kk_skip_dup(x_10175, _ctx);}, {}, _ctx)
  kk_integer_t _y_x10090_738 = kk_integer_unbox(_b_x705, _ctx); /*int*/;
  kk_src_effects_prat__resonance__resonance_hints _x_x2023 = kk_src_effects_prat__resonance__mlift_generate_hints_10117(x_10175, meta_0, pred, succ, _y_x10090_738, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  return kk_src_effects_prat__resonance__resonance_hints_box(_x_x2023, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_generate_hints_fun2028__t {
  struct kk_function_s _base;
  kk_src_effects_prat__resonance__ganainfo meta_0;
  kk_string_t pred;
  kk_string_t succ;
  kk_integer_t x_0_10180;
  double x_10175;
};
static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2028(kk_function_t _fself, kk_box_t _b_x713, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_generate_hints_fun2028(kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, kk_integer_t x_0_10180, double x_10175, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun2028__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_generate_hints_fun2028__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_generate_hints_fun2028, kk_context());
  _self->meta_0 = meta_0;
  _self->pred = pred;
  _self->succ = succ;
  _self->x_0_10180 = x_0_10180;
  _self->x_10175 = x_10175;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2028(kk_function_t _fself, kk_box_t _b_x713, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun2028__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_generate_hints_fun2028__t*, _fself, _ctx);
  kk_src_effects_prat__resonance__ganainfo meta_0 = _self->meta_0; /* src/effects/prat_resonance/ganainfo */
  kk_string_t pred = _self->pred; /* string */
  kk_string_t succ = _self->succ; /* string */
  kk_integer_t x_0_10180 = _self->x_0_10180; /* int */
  double x_10175 = _self->x_10175; /* float64 */
  kk_drop_match(_self, {kk_src_effects_prat__resonance__ganainfo_dup(meta_0, _ctx);kk_string_dup(pred, _ctx);kk_string_dup(succ, _ctx);kk_integer_dup(x_0_10180, _ctx);kk_skip_dup(x_10175, _ctx);}, {}, _ctx)
  double _y_x10091_739 = kk_double_unbox(_b_x713, KK_OWNED, _ctx); /*float64*/;
  kk_src_effects_prat__resonance__resonance_hints _x_x2029 = kk_src_effects_prat__resonance__mlift_generate_hints_10116(x_10175, x_0_10180, meta_0, pred, succ, _y_x10091_739, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  return kk_src_effects_prat__resonance__resonance_hints_box(_x_x2029, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_generate_hints_fun2034__t {
  struct kk_function_s _base;
  kk_src_effects_prat__resonance__ganainfo meta_0;
  kk_string_t pred;
  kk_string_t succ;
  kk_integer_t x_0_10180;
  double x_10175;
  double x_1_10185;
};
static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2034(kk_function_t _fself, kk_box_t _b_x724, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_generate_hints_fun2034(kk_src_effects_prat__resonance__ganainfo meta_0, kk_string_t pred, kk_string_t succ, kk_integer_t x_0_10180, double x_10175, double x_1_10185, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun2034__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_generate_hints_fun2034__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_generate_hints_fun2034, kk_context());
  _self->meta_0 = meta_0;
  _self->pred = pred;
  _self->succ = succ;
  _self->x_0_10180 = x_0_10180;
  _self->x_10175 = x_10175;
  _self->x_1_10185 = x_1_10185;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_src_effects_prat__resonance_generate_hints_fun2035__t {
  struct kk_function_s _base;
};
static kk_string_t kk_src_effects_prat__resonance_generate_hints_fun2035(kk_function_t _fself, kk_src_effects_prat__resonance__ganainfo ganainfo, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_generate_hints_fun2035(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_generate_hints_fun2035, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_string_t kk_src_effects_prat__resonance_generate_hints_fun2035(kk_function_t _fself, kk_src_effects_prat__resonance__ganainfo ganainfo, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x2036 = kk_src_effects_prat__resonance__as_Ganainfo(ganainfo, _ctx);
    kk_integer_t _pat_0_1_0_0 = _con_x2036->mansion_num;
    kk_string_t _x_0 = _con_x2036->quadrant;
    kk_string_t _pat_1_1_0 = _con_x2036->meaning;
    kk_string_t _pat_2_0_0_0 = _con_x2036->garden;
    kk_string_t _pat_3_0_0 = _con_x2036->chinese;
    kk_string_t _pat_4_0_0 = _con_x2036->pinyin;
    if kk_likely(kk_datatype_ptr_is_unique(ganainfo, _ctx)) {
      kk_string_drop(_pat_4_0_0, _ctx);
      kk_string_drop(_pat_3_0_0, _ctx);
      kk_string_drop(_pat_2_0_0_0, _ctx);
      kk_string_drop(_pat_1_1_0, _ctx);
      kk_integer_drop(_pat_0_1_0_0, _ctx);
      kk_datatype_ptr_free(ganainfo, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(ganainfo, _ctx);
    }
    return _x_0;
  }
}


// lift anonymous function
struct kk_src_effects_prat__resonance_generate_hints_fun2040__t {
  struct kk_function_s _base;
  kk_function_t _b_x720_733;
};
static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2040(kk_function_t _fself, kk_box_t _b_x722, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_generate_hints_fun2040(kk_function_t _b_x720_733, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun2040__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_generate_hints_fun2040__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_generate_hints_fun2040, kk_context());
  _self->_b_x720_733 = _b_x720_733;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2040(kk_function_t _fself, kk_box_t _b_x722, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun2040__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_generate_hints_fun2040__t*, _fself, _ctx);
  kk_function_t _b_x720_733 = _self->_b_x720_733; /* (ganainfo : src/effects/prat_resonance/ganainfo) -> string */
  kk_drop_match(_self, {kk_function_dup(_b_x720_733, _ctx);}, {}, _ctx)
  kk_string_t _x_x2041;
  kk_src_effects_prat__resonance__ganainfo _x_x2042 = kk_src_effects_prat__resonance__ganainfo_unbox(_b_x722, KK_OWNED, _ctx); /*src/effects/prat_resonance/ganainfo*/
  _x_x2041 = kk_function_call(kk_string_t, (kk_function_t, kk_src_effects_prat__resonance__ganainfo, kk_context_t*), _b_x720_733, (_b_x720_733, _x_x2042, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x2041);
}
static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2034(kk_function_t _fself, kk_box_t _b_x724, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_generate_hints_fun2034__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_generate_hints_fun2034__t*, _fself, _ctx);
  kk_src_effects_prat__resonance__ganainfo meta_0 = _self->meta_0; /* src/effects/prat_resonance/ganainfo */
  kk_string_t pred = _self->pred; /* string */
  kk_string_t succ = _self->succ; /* string */
  kk_integer_t x_0_10180 = _self->x_0_10180; /* int */
  double x_10175 = _self->x_10175; /* float64 */
  double x_1_10185 = _self->x_1_10185; /* float64 */
  kk_drop_match(_self, {kk_src_effects_prat__resonance__ganainfo_dup(meta_0, _ctx);kk_string_dup(pred, _ctx);kk_string_dup(succ, _ctx);kk_integer_dup(x_0_10180, _ctx);kk_skip_dup(x_10175, _ctx);kk_skip_dup(x_1_10185, _ctx);}, {}, _ctx)
  kk_string_t _y_x10092_740 = kk_string_unbox(_b_x724); /*string*/;
  kk_function_t _b_x720_733 = kk_src_effects_prat__resonance_new_generate_hints_fun2035(_ctx); /*(ganainfo : src/effects/prat_resonance/ganainfo) -> string*/;
  kk_src_effects_prat__resonance__ganainfo _b_x721_734 = meta_0; /*src/effects/prat_resonance/ganainfo*/;
  kk_src_effects_prat__resonance__resonance_hints _x_x2037;
  kk_string_t _x_x2038;
  kk_box_t _x_x2039 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance_new_generate_hints_fun2040(_b_x720_733, _ctx), kk_src_effects_prat__resonance__ganainfo_box(_b_x721_734, _ctx), _ctx); /*10001*/
  _x_x2038 = kk_string_unbox(_x_x2039); /*string*/
  _x_x2037 = kk_src_effects_prat__resonance__new_Resonance_hints(kk_reuse_null, 0, pred, succ, x_10175, x_0_10180, x_1_10185, _y_x10092_740, _x_x2038, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  return kk_src_effects_prat__resonance__resonance_hints_box(_x_x2037, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_generate_hints_fun2045__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2045(kk_function_t _fself, kk_box_t _b_x727, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_generate_hints_fun2045(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_generate_hints_fun2045, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_generate_hints_fun2045(kk_function_t _fself, kk_box_t _b_x727, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2046;
  kk_src_effects_prat__resonance__ganainfo ganainfo_0_741 = kk_src_effects_prat__resonance__ganainfo_unbox(_b_x727, KK_OWNED, _ctx); /*src/effects/prat_resonance/ganainfo*/;
  {
    struct kk_src_effects_prat__resonance_Ganainfo* _con_x2047 = kk_src_effects_prat__resonance__as_Ganainfo(ganainfo_0_741, _ctx);
    kk_integer_t _pat_0_1_1 = _con_x2047->mansion_num;
    kk_string_t _x_0_0 = _con_x2047->quadrant;
    kk_string_t _pat_1_1_1 = _con_x2047->meaning;
    kk_string_t _pat_2_0_1 = _con_x2047->garden;
    kk_string_t _pat_3_0_0_0 = _con_x2047->chinese;
    kk_string_t _pat_4_0_0_0 = _con_x2047->pinyin;
    if kk_likely(kk_datatype_ptr_is_unique(ganainfo_0_741, _ctx)) {
      kk_string_drop(_pat_4_0_0_0, _ctx);
      kk_string_drop(_pat_3_0_0_0, _ctx);
      kk_string_drop(_pat_2_0_1, _ctx);
      kk_string_drop(_pat_1_1_1, _ctx);
      kk_integer_drop(_pat_0_1_1, _ctx);
      kk_datatype_ptr_free(ganainfo_0_741, _ctx);
    }
    else {
      kk_string_dup(_x_0_0, _ctx);
      kk_datatype_ptr_decref(ganainfo_0_741, _ctx);
    }
    _x_x2046 = _x_0_0; /*string*/
  }
  return kk_string_box(_x_x2046);
}

kk_src_effects_prat__resonance__resonance_hints kk_src_effects_prat__resonance_generate_hints(kk_string_t gana_name, kk_context_t* _ctx) { /* (gana-name : string) -> resonance resonance-hints */ 
  kk_string_t pred;
  kk_box_t _x_x1982;
  kk_box_t _x_x1986;
  kk_string_t _x_x1987 = kk_string_dup(gana_name, _ctx); /*string*/
  _x_x1986 = kk_string_box(_x_x1987); /*10000*/
  _x_x1982 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance_new_generate_hints_fun1983(_ctx), _x_x1986, _ctx); /*10001*/
  pred = kk_string_unbox(_x_x1982); /*string*/
  kk_string_t succ;
  kk_box_t _x_x1988;
  kk_box_t _x_x1992;
  kk_string_t _x_x1993 = kk_string_dup(gana_name, _ctx); /*string*/
  _x_x1992 = kk_string_box(_x_x1993); /*10000*/
  _x_x1988 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance_new_generate_hints_fun1989(_ctx), _x_x1992, _ctx); /*10001*/
  succ = kk_string_unbox(_x_x1988); /*string*/
  kk_src_effects_prat__resonance__ganainfo meta_0;
  kk_box_t _x_x1994 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance_new_generate_hints_fun1995(_ctx), kk_string_box(gana_name), _ctx); /*10001*/
  meta_0 = kk_src_effects_prat__resonance__ganainfo_unbox(_x_x1994, KK_OWNED, _ctx); /*src/effects/prat_resonance/ganainfo*/
  kk_std_core_hnd__ev ev_10178 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  double x_10175;
  kk_box_t _x_x2012;
  {
    struct kk_std_core_hnd_Ev* _con_x2013 = kk_std_core_hnd__as_Ev(ev_10178, _ctx);
    kk_box_t _box_x690 = _con_x2013->hnd;
    int32_t m = _con_x2013->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x690, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x2014 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_1 = _con_x2014->_cfc;
      kk_std_core_hnd__clause0 _pat_1_2 = _con_x2014->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x2014->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_3_0 = _con_x2014->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_4_0 = _con_x2014->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_5_0 = _con_x2014->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_6_0 = _con_x2014->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _fun_get_lunar_phase = _con_x2014->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_7_0 = _con_x2014->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _pat_8_0 = _con_x2014->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9_0 = _con_x2014->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_7_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_lunar_phase, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x693 = _fun_get_lunar_phase.clause;
        _x_x2012 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x693, (_fun_unbox_x693, m, ev_10178, _ctx), _ctx); /*10005*/
      }
    }
  }
  x_10175 = kk_double_unbox(_x_x2012, KK_OWNED, _ctx); /*float64*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2015 = kk_std_core_hnd_yield_extend(kk_src_effects_prat__resonance_new_generate_hints_fun2016(meta_0, pred, succ, _ctx), _ctx); /*10001*/
    return kk_src_effects_prat__resonance__resonance_hints_unbox(_x_x2015, KK_OWNED, _ctx);
  }
  {
    kk_std_core_hnd__ev ev_0_10183 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
    kk_integer_t x_0_10180;
    kk_box_t _x_x2018;
    {
      struct kk_std_core_hnd_Ev* _con_x2019 = kk_std_core_hnd__as_Ev(ev_0_10183, _ctx);
      kk_box_t _box_x698 = _con_x2019->hnd;
      int32_t m_0 = _con_x2019->marker;
      kk_src_effects_prat__resonance__resonance h_0 = kk_src_effects_prat__resonance__resonance_unbox(_box_x698, KK_BORROWED, _ctx);
      kk_src_effects_prat__resonance__resonance_dup(h_0, _ctx);
      {
        struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x2020 = kk_src_effects_prat__resonance__as_Hnd_resonance(h_0, _ctx);
        kk_integer_t _pat_0_3 = _con_x2020->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2020->_fun_get_call_count;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2020->_fun_get_gana_counts;
        kk_std_core_hnd__clause0 _pat_3_1 = _con_x2020->_fun_get_guna_tag;
        kk_std_core_hnd__clause0 _pat_4_1 = _con_x2020->_fun_get_harmony_score;
        kk_std_core_hnd__clause0 _pat_5_1 = _con_x2020->_fun_get_last_snapshot;
        kk_std_core_hnd__clause0 _fun_get_lunar_mansion = _con_x2020->_fun_get_lunar_mansion;
        kk_std_core_hnd__clause0 _pat_6_1 = _con_x2020->_fun_get_lunar_phase;
        kk_std_core_hnd__clause1 _pat_7_1 = _con_x2020->_fun_get_recent_history;
        kk_std_core_hnd__clause1 _pat_8_1 = _con_x2020->_fun_record_snapshot;
        kk_std_core_hnd__clause0 _pat_9_2 = _con_x2020->_fun_reset_state;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause0_drop(_pat_9_2, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_8_1, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_7_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_6_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_5_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_4_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause0_dup(_fun_get_lunar_mansion, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x701 = _fun_get_lunar_mansion.clause;
          _x_x2018 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x701, (_fun_unbox_x701, m_0, ev_0_10183, _ctx), _ctx); /*10005*/
        }
      }
    }
    x_0_10180 = kk_integer_unbox(_x_x2018, _ctx); /*int*/
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_10180, _ctx);
      kk_box_t _x_x2021 = kk_std_core_hnd_yield_extend(kk_src_effects_prat__resonance_new_generate_hints_fun2022(meta_0, pred, succ, x_10175, _ctx), _ctx); /*10001*/
      return kk_src_effects_prat__resonance__resonance_hints_unbox(_x_x2021, KK_OWNED, _ctx);
    }
    {
      kk_std_core_hnd__ev ev_1_10188 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
      double x_1_10185;
      kk_box_t _x_x2024;
      {
        struct kk_std_core_hnd_Ev* _con_x2025 = kk_std_core_hnd__as_Ev(ev_1_10188, _ctx);
        kk_box_t _box_x706 = _con_x2025->hnd;
        int32_t m_1 = _con_x2025->marker;
        kk_src_effects_prat__resonance__resonance h_1 = kk_src_effects_prat__resonance__resonance_unbox(_box_x706, KK_BORROWED, _ctx);
        kk_src_effects_prat__resonance__resonance_dup(h_1, _ctx);
        {
          struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x2026 = kk_src_effects_prat__resonance__as_Hnd_resonance(h_1, _ctx);
          kk_integer_t _pat_0_5 = _con_x2026->_cfc;
          kk_std_core_hnd__clause0 _pat_1_4 = _con_x2026->_fun_get_call_count;
          kk_std_core_hnd__clause0 _pat_2_2 = _con_x2026->_fun_get_gana_counts;
          kk_std_core_hnd__clause0 _pat_3_2 = _con_x2026->_fun_get_guna_tag;
          kk_std_core_hnd__clause0 _fun_get_harmony_score = _con_x2026->_fun_get_harmony_score;
          kk_std_core_hnd__clause0 _pat_4_2 = _con_x2026->_fun_get_last_snapshot;
          kk_std_core_hnd__clause0 _pat_5_2 = _con_x2026->_fun_get_lunar_mansion;
          kk_std_core_hnd__clause0 _pat_6_2 = _con_x2026->_fun_get_lunar_phase;
          kk_std_core_hnd__clause1 _pat_7_2 = _con_x2026->_fun_get_recent_history;
          kk_std_core_hnd__clause1 _pat_8_2 = _con_x2026->_fun_record_snapshot;
          kk_std_core_hnd__clause0 _pat_9_3 = _con_x2026->_fun_reset_state;
          if kk_likely(kk_datatype_ptr_is_unique(h_1, _ctx)) {
            kk_std_core_hnd__clause0_drop(_pat_9_3, _ctx);
            kk_std_core_hnd__clause1_drop(_pat_8_2, _ctx);
            kk_std_core_hnd__clause1_drop(_pat_7_2, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_6_2, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_5_2, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_4_2, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_3_2, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_2_2, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_1_4, _ctx);
            kk_integer_drop(_pat_0_5, _ctx);
            kk_datatype_ptr_free(h_1, _ctx);
          }
          else {
            kk_std_core_hnd__clause0_dup(_fun_get_harmony_score, _ctx);
            kk_datatype_ptr_decref(h_1, _ctx);
          }
          {
            kk_function_t _fun_unbox_x709 = _fun_get_harmony_score.clause;
            _x_x2024 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x709, (_fun_unbox_x709, m_1, ev_1_10188, _ctx), _ctx); /*10005*/
          }
        }
      }
      x_1_10185 = kk_double_unbox(_x_x2024, KK_OWNED, _ctx); /*float64*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x2027 = kk_std_core_hnd_yield_extend(kk_src_effects_prat__resonance_new_generate_hints_fun2028(meta_0, pred, succ, x_0_10180, x_10175, _ctx), _ctx); /*10001*/
        return kk_src_effects_prat__resonance__resonance_hints_unbox(_x_x2027, KK_OWNED, _ctx);
      }
      {
        kk_std_core_hnd__ev ev_2_10193 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
        kk_string_t x_2_10190;
        kk_box_t _x_x2030;
        {
          struct kk_std_core_hnd_Ev* _con_x2031 = kk_std_core_hnd__as_Ev(ev_2_10193, _ctx);
          kk_box_t _box_x714 = _con_x2031->hnd;
          int32_t m_2 = _con_x2031->marker;
          kk_src_effects_prat__resonance__resonance h_2 = kk_src_effects_prat__resonance__resonance_unbox(_box_x714, KK_BORROWED, _ctx);
          kk_src_effects_prat__resonance__resonance_dup(h_2, _ctx);
          {
            struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x2032 = kk_src_effects_prat__resonance__as_Hnd_resonance(h_2, _ctx);
            kk_integer_t _pat_0_7 = _con_x2032->_cfc;
            kk_std_core_hnd__clause0 _pat_1_5 = _con_x2032->_fun_get_call_count;
            kk_std_core_hnd__clause0 _pat_2_3 = _con_x2032->_fun_get_gana_counts;
            kk_std_core_hnd__clause0 _fun_get_guna_tag = _con_x2032->_fun_get_guna_tag;
            kk_std_core_hnd__clause0 _pat_3_3 = _con_x2032->_fun_get_harmony_score;
            kk_std_core_hnd__clause0 _pat_4_3 = _con_x2032->_fun_get_last_snapshot;
            kk_std_core_hnd__clause0 _pat_5_3 = _con_x2032->_fun_get_lunar_mansion;
            kk_std_core_hnd__clause0 _pat_6_3 = _con_x2032->_fun_get_lunar_phase;
            kk_std_core_hnd__clause1 _pat_7_3 = _con_x2032->_fun_get_recent_history;
            kk_std_core_hnd__clause1 _pat_8_3 = _con_x2032->_fun_record_snapshot;
            kk_std_core_hnd__clause0 _pat_9_4 = _con_x2032->_fun_reset_state;
            if kk_likely(kk_datatype_ptr_is_unique(h_2, _ctx)) {
              kk_std_core_hnd__clause0_drop(_pat_9_4, _ctx);
              kk_std_core_hnd__clause1_drop(_pat_8_3, _ctx);
              kk_std_core_hnd__clause1_drop(_pat_7_3, _ctx);
              kk_std_core_hnd__clause0_drop(_pat_6_3, _ctx);
              kk_std_core_hnd__clause0_drop(_pat_5_3, _ctx);
              kk_std_core_hnd__clause0_drop(_pat_4_3, _ctx);
              kk_std_core_hnd__clause0_drop(_pat_3_3, _ctx);
              kk_std_core_hnd__clause0_drop(_pat_2_3, _ctx);
              kk_std_core_hnd__clause0_drop(_pat_1_5, _ctx);
              kk_integer_drop(_pat_0_7, _ctx);
              kk_datatype_ptr_free(h_2, _ctx);
            }
            else {
              kk_std_core_hnd__clause0_dup(_fun_get_guna_tag, _ctx);
              kk_datatype_ptr_decref(h_2, _ctx);
            }
            {
              kk_function_t _fun_unbox_x717 = _fun_get_guna_tag.clause;
              _x_x2030 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x717, (_fun_unbox_x717, m_2, ev_2_10193, _ctx), _ctx); /*10005*/
            }
          }
        }
        x_2_10190 = kk_string_unbox(_x_x2030); /*string*/
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_2_10190, _ctx);
          kk_box_t _x_x2033 = kk_std_core_hnd_yield_extend(kk_src_effects_prat__resonance_new_generate_hints_fun2034(meta_0, pred, succ, x_0_10180, x_10175, x_1_10185, _ctx), _ctx); /*10001*/
          return kk_src_effects_prat__resonance__resonance_hints_unbox(_x_x2033, KK_OWNED, _ctx);
        }
        {
          kk_string_t _x_x2043;
          kk_box_t _x_x2044 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance_new_generate_hints_fun2045(_ctx), kk_src_effects_prat__resonance__ganainfo_box(meta_0, _ctx), _ctx); /*10001*/
          _x_x2043 = kk_string_unbox(_x_x2044); /*string*/
          return kk_src_effects_prat__resonance__new_Resonance_hints(kk_reuse_null, 0, pred, succ, x_10175, x_0_10180, x_1_10185, x_2_10190, _x_x2043, _ctx);
        }
      }
    }
  }
}

kk_string_t kk_src_effects_prat__resonance_hints_to_json(kk_src_effects_prat__resonance__resonance_hints h, kk_context_t* _ctx) { /* (h : resonance-hints) -> string */ 
  kk_string_t _x_x2048;
  kk_define_string_literal(, _s_x2049, 1, "{", _ctx)
  _x_x2048 = kk_string_dup(_s_x2049, _ctx); /*string*/
  kk_string_t _x_x2050;
  kk_string_t _x_x2051;
  kk_define_string_literal(, _s_x2052, 16, "\"predecessor\": \"", _ctx)
  _x_x2051 = kk_string_dup(_s_x2052, _ctx); /*string*/
  kk_string_t _x_x2053;
  kk_string_t _x_x2054;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2055 = kk_src_effects_prat__resonance__as_Resonance_hints(h, _ctx);
    kk_string_t _x = _con_x2055->predecessor;
    kk_string_dup(_x, _ctx);
    _x_x2054 = _x; /*string*/
  }
  kk_string_t _x_x2056;
  kk_string_t _x_x2057;
  kk_define_string_literal(, _s_x2058, 2, "\",", _ctx)
  _x_x2057 = kk_string_dup(_s_x2058, _ctx); /*string*/
  kk_string_t _x_x2059;
  kk_string_t _x_x2060;
  kk_define_string_literal(, _s_x2061, 14, "\"successor\": \"", _ctx)
  _x_x2060 = kk_string_dup(_s_x2061, _ctx); /*string*/
  kk_string_t _x_x2062;
  kk_string_t _x_x2063;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2064 = kk_src_effects_prat__resonance__as_Resonance_hints(h, _ctx);
    kk_string_t _x_0 = _con_x2064->successor;
    kk_string_dup(_x_0, _ctx);
    _x_x2063 = _x_0; /*string*/
  }
  kk_string_t _x_x2065;
  kk_string_t _x_x2066;
  kk_define_string_literal(, _s_x2067, 2, "\",", _ctx)
  _x_x2066 = kk_string_dup(_s_x2067, _ctx); /*string*/
  kk_string_t _x_x2068;
  kk_string_t _x_x2069;
  kk_define_string_literal(, _s_x2070, 15, "\"lunar_phase\": ", _ctx)
  _x_x2069 = kk_string_dup(_s_x2070, _ctx); /*string*/
  kk_string_t _x_x2071;
  kk_string_t _x_x2072;
  double _x_x2073;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2074 = kk_src_effects_prat__resonance__as_Resonance_hints(h, _ctx);
    double _x_1 = _con_x2074->lunar_phase;
    _x_x2073 = _x_1; /*float64*/
  }
  _x_x2072 = kk_std_num_float64_show(_x_x2073, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x2075;
  kk_string_t _x_x2076;
  kk_define_string_literal(, _s_x2077, 1, ",", _ctx)
  _x_x2076 = kk_string_dup(_s_x2077, _ctx); /*string*/
  kk_string_t _x_x2078;
  kk_string_t _x_x2079;
  kk_define_string_literal(, _s_x2080, 21, "\"lunar_mansion_num\": ", _ctx)
  _x_x2079 = kk_string_dup(_s_x2080, _ctx); /*string*/
  kk_string_t _x_x2081;
  kk_string_t _x_x2082;
  kk_integer_t _x_x2083;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2084 = kk_src_effects_prat__resonance__as_Resonance_hints(h, _ctx);
    kk_integer_t _x_2 = _con_x2084->lunar_mansion_num;
    kk_integer_dup(_x_2, _ctx);
    _x_x2083 = _x_2; /*int*/
  }
  _x_x2082 = kk_std_core_int_show(_x_x2083, _ctx); /*string*/
  kk_string_t _x_x2085;
  kk_string_t _x_x2086;
  kk_define_string_literal(, _s_x2087, 1, ",", _ctx)
  _x_x2086 = kk_string_dup(_s_x2087, _ctx); /*string*/
  kk_string_t _x_x2088;
  kk_string_t _x_x2089;
  kk_define_string_literal(, _s_x2090, 17, "\"harmony_score\": ", _ctx)
  _x_x2089 = kk_string_dup(_s_x2090, _ctx); /*string*/
  kk_string_t _x_x2091;
  kk_string_t _x_x2092;
  double _x_x2093;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2094 = kk_src_effects_prat__resonance__as_Resonance_hints(h, _ctx);
    double _x_3 = _con_x2094->harmony_score;
    _x_x2093 = _x_3; /*float64*/
  }
  _x_x2092 = kk_std_num_float64_show(_x_x2093, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x2095;
  kk_string_t _x_x2096;
  kk_define_string_literal(, _s_x2097, 1, ",", _ctx)
  _x_x2096 = kk_string_dup(_s_x2097, _ctx); /*string*/
  kk_string_t _x_x2098;
  kk_string_t _x_x2099;
  kk_define_string_literal(, _s_x2100, 13, "\"guna_tag\": \"", _ctx)
  _x_x2099 = kk_string_dup(_s_x2100, _ctx); /*string*/
  kk_string_t _x_x2101;
  kk_string_t _x_x2102;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2103 = kk_src_effects_prat__resonance__as_Resonance_hints(h, _ctx);
    kk_string_t _x_4 = _con_x2103->guna_tag;
    kk_string_dup(_x_4, _ctx);
    _x_x2102 = _x_4; /*string*/
  }
  kk_string_t _x_x2104;
  kk_string_t _x_x2105;
  kk_define_string_literal(, _s_x2106, 2, "\",", _ctx)
  _x_x2105 = kk_string_dup(_s_x2106, _ctx); /*string*/
  kk_string_t _x_x2107;
  kk_string_t _x_x2108;
  kk_define_string_literal(, _s_x2109, 13, "\"quadrant\": \"", _ctx)
  _x_x2108 = kk_string_dup(_s_x2109, _ctx); /*string*/
  kk_string_t _x_x2110;
  kk_string_t _x_x2111;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2112 = kk_src_effects_prat__resonance__as_Resonance_hints(h, _ctx);
    kk_string_t _pat_0_5 = _con_x2112->predecessor;
    kk_string_t _pat_1_5 = _con_x2112->successor;
    kk_integer_t _pat_3_5 = _con_x2112->lunar_mansion_num;
    kk_string_t _pat_5_5 = _con_x2112->guna_tag;
    kk_string_t _x_5 = _con_x2112->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
      kk_string_drop(_pat_5_5, _ctx);
      kk_integer_drop(_pat_3_5, _ctx);
      kk_string_drop(_pat_1_5, _ctx);
      kk_string_drop(_pat_0_5, _ctx);
      kk_datatype_ptr_free(h, _ctx);
    }
    else {
      kk_string_dup(_x_5, _ctx);
      kk_datatype_ptr_decref(h, _ctx);
    }
    _x_x2111 = _x_5; /*string*/
  }
  kk_string_t _x_x2113;
  kk_string_t _x_x2114;
  kk_define_string_literal(, _s_x2115, 1, "\"", _ctx)
  _x_x2114 = kk_string_dup(_s_x2115, _ctx); /*string*/
  kk_string_t _x_x2116;
  kk_define_string_literal(, _s_x2117, 1, "}", _ctx)
  _x_x2116 = kk_string_dup(_s_x2117, _ctx); /*string*/
  _x_x2113 = kk_std_core_types__lp__plus__plus__rp_(_x_x2114, _x_x2116, _ctx); /*string*/
  _x_x2110 = kk_std_core_types__lp__plus__plus__rp_(_x_x2111, _x_x2113, _ctx); /*string*/
  _x_x2107 = kk_std_core_types__lp__plus__plus__rp_(_x_x2108, _x_x2110, _ctx); /*string*/
  _x_x2104 = kk_std_core_types__lp__plus__plus__rp_(_x_x2105, _x_x2107, _ctx); /*string*/
  _x_x2101 = kk_std_core_types__lp__plus__plus__rp_(_x_x2102, _x_x2104, _ctx); /*string*/
  _x_x2098 = kk_std_core_types__lp__plus__plus__rp_(_x_x2099, _x_x2101, _ctx); /*string*/
  _x_x2095 = kk_std_core_types__lp__plus__plus__rp_(_x_x2096, _x_x2098, _ctx); /*string*/
  _x_x2091 = kk_std_core_types__lp__plus__plus__rp_(_x_x2092, _x_x2095, _ctx); /*string*/
  _x_x2088 = kk_std_core_types__lp__plus__plus__rp_(_x_x2089, _x_x2091, _ctx); /*string*/
  _x_x2085 = kk_std_core_types__lp__plus__plus__rp_(_x_x2086, _x_x2088, _ctx); /*string*/
  _x_x2081 = kk_std_core_types__lp__plus__plus__rp_(_x_x2082, _x_x2085, _ctx); /*string*/
  _x_x2078 = kk_std_core_types__lp__plus__plus__rp_(_x_x2079, _x_x2081, _ctx); /*string*/
  _x_x2075 = kk_std_core_types__lp__plus__plus__rp_(_x_x2076, _x_x2078, _ctx); /*string*/
  _x_x2071 = kk_std_core_types__lp__plus__plus__rp_(_x_x2072, _x_x2075, _ctx); /*string*/
  _x_x2068 = kk_std_core_types__lp__plus__plus__rp_(_x_x2069, _x_x2071, _ctx); /*string*/
  _x_x2065 = kk_std_core_types__lp__plus__plus__rp_(_x_x2066, _x_x2068, _ctx); /*string*/
  _x_x2062 = kk_std_core_types__lp__plus__plus__rp_(_x_x2063, _x_x2065, _ctx); /*string*/
  _x_x2059 = kk_std_core_types__lp__plus__plus__rp_(_x_x2060, _x_x2062, _ctx); /*string*/
  _x_x2056 = kk_std_core_types__lp__plus__plus__rp_(_x_x2057, _x_x2059, _ctx); /*string*/
  _x_x2053 = kk_std_core_types__lp__plus__plus__rp_(_x_x2054, _x_x2056, _ctx); /*string*/
  _x_x2050 = kk_std_core_types__lp__plus__plus__rp_(_x_x2051, _x_x2053, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x2048, _x_x2050, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2120__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2120(kk_function_t _fself, kk_box_t _b_x744, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2120(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2120, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2120(kk_function_t _fself, kk_box_t _b_x744, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x2121;
  kk_src_effects_prat__resonance__resonance_hints _match_x856 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x744, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2122 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x856, _ctx);
    kk_string_t _pat_0 = _con_x2122->predecessor;
    kk_string_t _pat_1 = _con_x2122->successor;
    double _x = _con_x2122->lunar_phase;
    kk_integer_t _pat_2 = _con_x2122->lunar_mansion_num;
    kk_string_t _pat_4 = _con_x2122->guna_tag;
    kk_string_t _pat_5 = _con_x2122->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x856, _ctx)) {
      kk_string_drop(_pat_5, _ctx);
      kk_string_drop(_pat_4, _ctx);
      kk_integer_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x856, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x856, _ctx);
    }
    _x_x2121 = _x; /*float64*/
  }
  return kk_double_box(_x_x2121, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2127__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2127(kk_function_t _fself, kk_box_t _b_x747, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2127(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2127, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2127(kk_function_t _fself, kk_box_t _b_x747, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2128;
  kk_src_effects_prat__resonance__resonance_hints _match_x855 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x747, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2129 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x855, _ctx);
    kk_string_t _pat_0_0 = _con_x2129->predecessor;
    kk_string_t _pat_1_0 = _con_x2129->successor;
    kk_integer_t _x_0 = _con_x2129->lunar_mansion_num;
    kk_string_t _pat_4_0 = _con_x2129->guna_tag;
    kk_string_t _pat_5_0 = _con_x2129->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x855, _ctx)) {
      kk_string_drop(_pat_5_0, _ctx);
      kk_string_drop(_pat_4_0, _ctx);
      kk_string_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(_match_x855, _ctx);
    }
    else {
      kk_integer_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x855, _ctx);
    }
    _x_x2128 = _x_0; /*int*/
  }
  return kk_integer_box(_x_x2128, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2134__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2134(kk_function_t _fself, kk_box_t _b_x750, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2134(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2134, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2134(kk_function_t _fself, kk_box_t _b_x750, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x2135;
  kk_src_effects_prat__resonance__resonance_hints _match_x854 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x750, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2136 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x854, _ctx);
    kk_string_t _pat_0_1 = _con_x2136->predecessor;
    kk_string_t _pat_1_1 = _con_x2136->successor;
    kk_integer_t _pat_3_1 = _con_x2136->lunar_mansion_num;
    double _x_1 = _con_x2136->harmony_score;
    kk_string_t _pat_4_1 = _con_x2136->guna_tag;
    kk_string_t _pat_5_1 = _con_x2136->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x854, _ctx)) {
      kk_string_drop(_pat_5_1, _ctx);
      kk_string_drop(_pat_4_1, _ctx);
      kk_integer_drop(_pat_3_1, _ctx);
      kk_string_drop(_pat_1_1, _ctx);
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(_match_x854, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x854, _ctx);
    }
    _x_x2135 = _x_1; /*float64*/
  }
  return kk_double_box(_x_x2135, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2141__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2141(kk_function_t _fself, kk_box_t _b_x753, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2141(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2141, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2141(kk_function_t _fself, kk_box_t _b_x753, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2142;
  kk_src_effects_prat__resonance__resonance_hints _match_x853 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x753, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2143 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x853, _ctx);
    kk_string_t _pat_0_2 = _con_x2143->predecessor;
    kk_string_t _pat_1_2 = _con_x2143->successor;
    kk_integer_t _pat_3_2 = _con_x2143->lunar_mansion_num;
    kk_string_t _x_2 = _con_x2143->guna_tag;
    kk_string_t _pat_5_2 = _con_x2143->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x853, _ctx)) {
      kk_string_drop(_pat_5_2, _ctx);
      kk_integer_drop(_pat_3_2, _ctx);
      kk_string_drop(_pat_1_2, _ctx);
      kk_string_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(_match_x853, _ctx);
    }
    else {
      kk_string_dup(_x_2, _ctx);
      kk_datatype_ptr_decref(_match_x853, _ctx);
    }
    _x_x2142 = _x_2; /*string*/
  }
  return kk_string_box(_x_x2142);
}


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2148__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2148(kk_function_t _fself, kk_box_t _b_x756, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2148(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2148, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2148(kk_function_t _fself, kk_box_t _b_x756, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2149;
  kk_src_effects_prat__resonance__resonance_hints _match_x852 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x756, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2150 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x852, _ctx);
    kk_string_t _pat_0_3 = _con_x2150->predecessor;
    kk_string_t _pat_1_3 = _con_x2150->successor;
    kk_integer_t _pat_3_3 = _con_x2150->lunar_mansion_num;
    kk_string_t _pat_5_3 = _con_x2150->guna_tag;
    kk_string_t _x_3 = _con_x2150->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x852, _ctx)) {
      kk_string_drop(_pat_5_3, _ctx);
      kk_integer_drop(_pat_3_3, _ctx);
      kk_string_drop(_pat_1_3, _ctx);
      kk_string_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(_match_x852, _ctx);
    }
    else {
      kk_string_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(_match_x852, _ctx);
    }
    _x_x2149 = _x_3; /*string*/
  }
  return kk_string_box(_x_x2149);
}


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2155__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2155(kk_function_t _fself, kk_box_t _b_x759, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2155(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2155, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2155(kk_function_t _fself, kk_box_t _b_x759, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2156;
  kk_src_effects_prat__resonance__resonance_hints _match_x851 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x759, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2157 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x851, _ctx);
    kk_string_t _pat_0_4 = _con_x2157->predecessor;
    kk_string_t _x_4 = _con_x2157->successor;
    kk_integer_t _pat_2_4 = _con_x2157->lunar_mansion_num;
    kk_string_t _pat_4_4 = _con_x2157->guna_tag;
    kk_string_t _pat_5_4 = _con_x2157->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x851, _ctx)) {
      kk_string_drop(_pat_5_4, _ctx);
      kk_string_drop(_pat_4_4, _ctx);
      kk_integer_drop(_pat_2_4, _ctx);
      kk_string_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(_match_x851, _ctx);
    }
    else {
      kk_string_dup(_x_4, _ctx);
      kk_datatype_ptr_decref(_match_x851, _ctx);
    }
    _x_x2156 = _x_4; /*string*/
  }
  return kk_string_box(_x_x2156);
}


// lift anonymous function
struct kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2164__t {
  struct kk_function_s _base;
  kk_src_effects_prat__resonance__snapshot snap;
};
static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2164(kk_function_t _fself, kk_box_t _b_x787, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2164(kk_src_effects_prat__resonance__snapshot snap, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2164__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2164__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2164, kk_context());
  _self->snap = snap;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2164(kk_function_t _fself, kk_box_t _b_x787, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2164__t* _self = kk_function_as(struct kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120_fun2164__t*, _fself, _ctx);
  kk_src_effects_prat__resonance__snapshot snap = _self->snap; /* src/effects/prat_resonance/snapshot */
  kk_drop_match(_self, {kk_src_effects_prat__resonance__snapshot_dup(snap, _ctx);}, {}, _ctx)
  kk_unit_t wild___789 = kk_Unit;
  kk_unit_unbox(_b_x787);
  return kk_src_effects_prat__resonance__snapshot_box(snap, _ctx);
}

kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120(kk_string_t gana_name, kk_string_t operation, kk_string_t output, kk_string_t tool_name, kk_src_effects_prat__resonance__resonance_hints hints, kk_context_t* _ctx) { /* (gana-name : string, operation : string, output : string, tool-name : string, hints : resonance-hints) -> resonance snapshot */ 
  kk_src_effects_prat__resonance__snapshot snap;
  double _x_x2118;
  kk_box_t _x_x2119;
  kk_box_t _x_x2123;
  kk_src_effects_prat__resonance__resonance_hints _x_x2124 = kk_src_effects_prat__resonance__resonance_hints_dup(hints, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  _x_x2123 = kk_src_effects_prat__resonance__resonance_hints_box(_x_x2124, _ctx); /*10000*/
  _x_x2119 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2120(_ctx), _x_x2123, _ctx); /*10001*/
  _x_x2118 = kk_double_unbox(_x_x2119, KK_OWNED, _ctx); /*float64*/
  kk_integer_t _x_x2125;
  kk_box_t _x_x2126;
  kk_box_t _x_x2130;
  kk_src_effects_prat__resonance__resonance_hints _x_x2131 = kk_src_effects_prat__resonance__resonance_hints_dup(hints, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  _x_x2130 = kk_src_effects_prat__resonance__resonance_hints_box(_x_x2131, _ctx); /*10000*/
  _x_x2126 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2127(_ctx), _x_x2130, _ctx); /*10001*/
  _x_x2125 = kk_integer_unbox(_x_x2126, _ctx); /*int*/
  double _x_x2132;
  kk_box_t _x_x2133;
  kk_box_t _x_x2137;
  kk_src_effects_prat__resonance__resonance_hints _x_x2138 = kk_src_effects_prat__resonance__resonance_hints_dup(hints, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  _x_x2137 = kk_src_effects_prat__resonance__resonance_hints_box(_x_x2138, _ctx); /*10000*/
  _x_x2133 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2134(_ctx), _x_x2137, _ctx); /*10001*/
  _x_x2132 = kk_double_unbox(_x_x2133, KK_OWNED, _ctx); /*float64*/
  kk_string_t _x_x2139;
  kk_box_t _x_x2140;
  kk_box_t _x_x2144;
  kk_src_effects_prat__resonance__resonance_hints _x_x2145 = kk_src_effects_prat__resonance__resonance_hints_dup(hints, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  _x_x2144 = kk_src_effects_prat__resonance__resonance_hints_box(_x_x2145, _ctx); /*10000*/
  _x_x2140 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2141(_ctx), _x_x2144, _ctx); /*10001*/
  _x_x2139 = kk_string_unbox(_x_x2140); /*string*/
  kk_string_t _x_x2146;
  kk_box_t _x_x2147;
  kk_box_t _x_x2151;
  kk_src_effects_prat__resonance__resonance_hints _x_x2152 = kk_src_effects_prat__resonance__resonance_hints_dup(hints, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  _x_x2151 = kk_src_effects_prat__resonance__resonance_hints_box(_x_x2152, _ctx); /*10000*/
  _x_x2147 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2148(_ctx), _x_x2151, _ctx); /*10001*/
  _x_x2146 = kk_string_unbox(_x_x2147); /*string*/
  kk_string_t _x_x2153;
  kk_box_t _x_x2154 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2155(_ctx), kk_src_effects_prat__resonance__resonance_hints_box(hints, _ctx), _ctx); /*10001*/
  _x_x2153 = kk_string_unbox(_x_x2154); /*string*/
  snap = kk_src_effects_prat__resonance__new_Snapshot(kk_reuse_null, 0, gana_name, tool_name, operation, output, 0x0p+0, _x_x2118, _x_x2125, _x_x2132, _x_x2139, _x_x2146, _x_x2153, _ctx); /*src/effects/prat_resonance/snapshot*/
  kk_std_core_hnd__ev ev_10204 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
  kk_unit_t x_10202 = kk_Unit;
  kk_box_t _x_x2158;
  {
    struct kk_std_core_hnd_Ev* _con_x2159 = kk_std_core_hnd__as_Ev(ev_10204, _ctx);
    kk_box_t _box_x778 = _con_x2159->hnd;
    int32_t m = _con_x2159->marker;
    kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x778, KK_BORROWED, _ctx);
    kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
    {
      struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x2160 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_5 = _con_x2160->_cfc;
      kk_std_core_hnd__clause0 _pat_1_6 = _con_x2160->_fun_get_call_count;
      kk_std_core_hnd__clause0 _pat_2_5 = _con_x2160->_fun_get_gana_counts;
      kk_std_core_hnd__clause0 _pat_3_5 = _con_x2160->_fun_get_guna_tag;
      kk_std_core_hnd__clause0 _pat_4_5 = _con_x2160->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_5_5 = _con_x2160->_fun_get_last_snapshot;
      kk_std_core_hnd__clause0 _pat_6_0 = _con_x2160->_fun_get_lunar_mansion;
      kk_std_core_hnd__clause0 _pat_7_0 = _con_x2160->_fun_get_lunar_phase;
      kk_std_core_hnd__clause1 _pat_8_0 = _con_x2160->_fun_get_recent_history;
      kk_std_core_hnd__clause1 _fun_record_snapshot = _con_x2160->_fun_record_snapshot;
      kk_std_core_hnd__clause0 _pat_9_0 = _con_x2160->_fun_reset_state;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_9_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_8_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_7_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_6_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_5_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_4_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_3_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_5, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_6, _ctx);
        kk_integer_drop(_pat_0_5, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_record_snapshot, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x782 = _fun_record_snapshot.clause;
        kk_box_t _x_x2161;
        kk_src_effects_prat__resonance__snapshot _x_x2162 = kk_src_effects_prat__resonance__snapshot_dup(snap, _ctx); /*src/effects/prat_resonance/snapshot*/
        _x_x2161 = kk_src_effects_prat__resonance__snapshot_box(_x_x2162, _ctx); /*10009*/
        _x_x2158 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x782, (_fun_unbox_x782, m, ev_10204, _x_x2161, _ctx), _ctx); /*10010*/
      }
    }
  }
  kk_unit_unbox(_x_x2158);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2163 = kk_std_core_hnd_yield_extend(kk_src_effects_prat__resonance__new_mlift_track_prat_invocation_10120_fun2164(snap, _ctx), _ctx); /*10001*/
    return kk_src_effects_prat__resonance__snapshot_unbox(_x_x2163, KK_OWNED, _ctx);
  }
  {
    return snap;
  }
}


// lift anonymous function
struct kk_src_effects_prat__resonance_track_prat_invocation_fun2167__t {
  struct kk_function_s _base;
  kk_string_t gana_name;
  kk_string_t operation;
  kk_string_t output;
  kk_string_t tool_name;
};
static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2167(kk_function_t _fself, kk_box_t _b_x791, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_track_prat_invocation_fun2167(kk_string_t gana_name, kk_string_t operation, kk_string_t output, kk_string_t tool_name, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_track_prat_invocation_fun2167__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_track_prat_invocation_fun2167__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_track_prat_invocation_fun2167, kk_context());
  _self->gana_name = gana_name;
  _self->operation = operation;
  _self->output = output;
  _self->tool_name = tool_name;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2167(kk_function_t _fself, kk_box_t _b_x791, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_track_prat_invocation_fun2167__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_track_prat_invocation_fun2167__t*, _fself, _ctx);
  kk_string_t gana_name = _self->gana_name; /* string */
  kk_string_t operation = _self->operation; /* string */
  kk_string_t output = _self->output; /* string */
  kk_string_t tool_name = _self->tool_name; /* string */
  kk_drop_match(_self, {kk_string_dup(gana_name, _ctx);kk_string_dup(operation, _ctx);kk_string_dup(output, _ctx);kk_string_dup(tool_name, _ctx);}, {}, _ctx)
  kk_src_effects_prat__resonance__resonance_hints hints_840 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x791, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  kk_src_effects_prat__resonance__snapshot _x_x2168 = kk_src_effects_prat__resonance__mlift_track_prat_invocation_10120(gana_name, operation, output, tool_name, hints_840, _ctx); /*src/effects/prat_resonance/snapshot*/
  return kk_src_effects_prat__resonance__snapshot_box(_x_x2168, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_track_prat_invocation_fun2171__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2171(kk_function_t _fself, kk_box_t _b_x794, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_track_prat_invocation_fun2171(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_track_prat_invocation_fun2171, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2171(kk_function_t _fself, kk_box_t _b_x794, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x2172;
  kk_src_effects_prat__resonance__resonance_hints _match_x849 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x794, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2173 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x849, _ctx);
    kk_string_t _pat_0_0 = _con_x2173->predecessor;
    kk_string_t _pat_1_0 = _con_x2173->successor;
    double _x = _con_x2173->lunar_phase;
    kk_integer_t _pat_2 = _con_x2173->lunar_mansion_num;
    kk_string_t _pat_4 = _con_x2173->guna_tag;
    kk_string_t _pat_5 = _con_x2173->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x849, _ctx)) {
      kk_string_drop(_pat_5, _ctx);
      kk_string_drop(_pat_4, _ctx);
      kk_integer_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(_match_x849, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x849, _ctx);
    }
    _x_x2172 = _x; /*float64*/
  }
  return kk_double_box(_x_x2172, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_track_prat_invocation_fun2178__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2178(kk_function_t _fself, kk_box_t _b_x797, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_track_prat_invocation_fun2178(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_track_prat_invocation_fun2178, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2178(kk_function_t _fself, kk_box_t _b_x797, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2179;
  kk_src_effects_prat__resonance__resonance_hints _match_x848 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x797, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2180 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x848, _ctx);
    kk_string_t _pat_0_0_0 = _con_x2180->predecessor;
    kk_string_t _pat_1_0_0 = _con_x2180->successor;
    kk_integer_t _x_0 = _con_x2180->lunar_mansion_num;
    kk_string_t _pat_4_0 = _con_x2180->guna_tag;
    kk_string_t _pat_5_0 = _con_x2180->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x848, _ctx)) {
      kk_string_drop(_pat_5_0, _ctx);
      kk_string_drop(_pat_4_0, _ctx);
      kk_string_drop(_pat_1_0_0, _ctx);
      kk_string_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(_match_x848, _ctx);
    }
    else {
      kk_integer_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x848, _ctx);
    }
    _x_x2179 = _x_0; /*int*/
  }
  return kk_integer_box(_x_x2179, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_track_prat_invocation_fun2185__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2185(kk_function_t _fself, kk_box_t _b_x800, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_track_prat_invocation_fun2185(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_track_prat_invocation_fun2185, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2185(kk_function_t _fself, kk_box_t _b_x800, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x2186;
  kk_src_effects_prat__resonance__resonance_hints _match_x847 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x800, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2187 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x847, _ctx);
    kk_string_t _pat_0_1 = _con_x2187->predecessor;
    kk_string_t _pat_1_1 = _con_x2187->successor;
    kk_integer_t _pat_3_1 = _con_x2187->lunar_mansion_num;
    double _x_1 = _con_x2187->harmony_score;
    kk_string_t _pat_4_1 = _con_x2187->guna_tag;
    kk_string_t _pat_5_1 = _con_x2187->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x847, _ctx)) {
      kk_string_drop(_pat_5_1, _ctx);
      kk_string_drop(_pat_4_1, _ctx);
      kk_integer_drop(_pat_3_1, _ctx);
      kk_string_drop(_pat_1_1, _ctx);
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(_match_x847, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x847, _ctx);
    }
    _x_x2186 = _x_1; /*float64*/
  }
  return kk_double_box(_x_x2186, _ctx);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_track_prat_invocation_fun2192__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2192(kk_function_t _fself, kk_box_t _b_x803, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_track_prat_invocation_fun2192(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_track_prat_invocation_fun2192, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2192(kk_function_t _fself, kk_box_t _b_x803, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2193;
  kk_src_effects_prat__resonance__resonance_hints _match_x846 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x803, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2194 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x846, _ctx);
    kk_string_t _pat_0_2 = _con_x2194->predecessor;
    kk_string_t _pat_1_2 = _con_x2194->successor;
    kk_integer_t _pat_3_2 = _con_x2194->lunar_mansion_num;
    kk_string_t _x_2 = _con_x2194->guna_tag;
    kk_string_t _pat_5_2 = _con_x2194->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x846, _ctx)) {
      kk_string_drop(_pat_5_2, _ctx);
      kk_integer_drop(_pat_3_2, _ctx);
      kk_string_drop(_pat_1_2, _ctx);
      kk_string_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(_match_x846, _ctx);
    }
    else {
      kk_string_dup(_x_2, _ctx);
      kk_datatype_ptr_decref(_match_x846, _ctx);
    }
    _x_x2193 = _x_2; /*string*/
  }
  return kk_string_box(_x_x2193);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_track_prat_invocation_fun2199__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2199(kk_function_t _fself, kk_box_t _b_x806, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_track_prat_invocation_fun2199(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_track_prat_invocation_fun2199, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2199(kk_function_t _fself, kk_box_t _b_x806, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2200;
  kk_src_effects_prat__resonance__resonance_hints _match_x845 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x806, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2201 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x845, _ctx);
    kk_string_t _pat_0_3 = _con_x2201->predecessor;
    kk_string_t _pat_1_3 = _con_x2201->successor;
    kk_integer_t _pat_3_3 = _con_x2201->lunar_mansion_num;
    kk_string_t _pat_5_3 = _con_x2201->guna_tag;
    kk_string_t _x_3 = _con_x2201->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x845, _ctx)) {
      kk_string_drop(_pat_5_3, _ctx);
      kk_integer_drop(_pat_3_3, _ctx);
      kk_string_drop(_pat_1_3, _ctx);
      kk_string_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(_match_x845, _ctx);
    }
    else {
      kk_string_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(_match_x845, _ctx);
    }
    _x_x2200 = _x_3; /*string*/
  }
  return kk_string_box(_x_x2200);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_track_prat_invocation_fun2206__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2206(kk_function_t _fself, kk_box_t _b_x809, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_track_prat_invocation_fun2206(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_effects_prat__resonance_track_prat_invocation_fun2206, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2206(kk_function_t _fself, kk_box_t _b_x809, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2207;
  kk_src_effects_prat__resonance__resonance_hints _match_x844 = kk_src_effects_prat__resonance__resonance_hints_unbox(_b_x809, KK_OWNED, _ctx); /*src/effects/prat_resonance/resonance-hints*/;
  {
    struct kk_src_effects_prat__resonance_Resonance_hints* _con_x2208 = kk_src_effects_prat__resonance__as_Resonance_hints(_match_x844, _ctx);
    kk_string_t _pat_0_4 = _con_x2208->predecessor;
    kk_string_t _x_4 = _con_x2208->successor;
    kk_integer_t _pat_2_4 = _con_x2208->lunar_mansion_num;
    kk_string_t _pat_4_4 = _con_x2208->guna_tag;
    kk_string_t _pat_5_4 = _con_x2208->quadrant;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x844, _ctx)) {
      kk_string_drop(_pat_5_4, _ctx);
      kk_string_drop(_pat_4_4, _ctx);
      kk_integer_drop(_pat_2_4, _ctx);
      kk_string_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(_match_x844, _ctx);
    }
    else {
      kk_string_dup(_x_4, _ctx);
      kk_datatype_ptr_decref(_match_x844, _ctx);
    }
    _x_x2207 = _x_4; /*string*/
  }
  return kk_string_box(_x_x2207);
}


// lift anonymous function
struct kk_src_effects_prat__resonance_track_prat_invocation_fun2215__t {
  struct kk_function_s _base;
  kk_src_effects_prat__resonance__snapshot snap;
};
static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2215(kk_function_t _fself, kk_box_t _b_x837, kk_context_t* _ctx);
static kk_function_t kk_src_effects_prat__resonance_new_track_prat_invocation_fun2215(kk_src_effects_prat__resonance__snapshot snap, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_track_prat_invocation_fun2215__t* _self = kk_function_alloc_as(struct kk_src_effects_prat__resonance_track_prat_invocation_fun2215__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_effects_prat__resonance_track_prat_invocation_fun2215, kk_context());
  _self->snap = snap;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_effects_prat__resonance_track_prat_invocation_fun2215(kk_function_t _fself, kk_box_t _b_x837, kk_context_t* _ctx) {
  struct kk_src_effects_prat__resonance_track_prat_invocation_fun2215__t* _self = kk_function_as(struct kk_src_effects_prat__resonance_track_prat_invocation_fun2215__t*, _fself, _ctx);
  kk_src_effects_prat__resonance__snapshot snap = _self->snap; /* src/effects/prat_resonance/snapshot */
  kk_drop_match(_self, {kk_src_effects_prat__resonance__snapshot_dup(snap, _ctx);}, {}, _ctx)
  kk_unit_t wild___841 = kk_Unit;
  kk_unit_unbox(_b_x837);
  return kk_src_effects_prat__resonance__snapshot_box(snap, _ctx);
}

kk_src_effects_prat__resonance__snapshot kk_src_effects_prat__resonance_track_prat_invocation(kk_string_t gana_name, kk_string_t tool_name, kk_string_t operation, kk_string_t output, kk_context_t* _ctx) { /* (gana-name : string, tool-name : string, operation : string, output : string) -> resonance snapshot */ 
  kk_src_effects_prat__resonance__resonance_hints x_10209;
  kk_string_t _x_x2165 = kk_string_dup(gana_name, _ctx); /*string*/
  x_10209 = kk_src_effects_prat__resonance_generate_hints(_x_x2165, _ctx); /*src/effects/prat_resonance/resonance-hints*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10209, (KK_I32(5)), _ctx);
    kk_box_t _x_x2166 = kk_std_core_hnd_yield_extend(kk_src_effects_prat__resonance_new_track_prat_invocation_fun2167(gana_name, operation, output, tool_name, _ctx), _ctx); /*10001*/
    return kk_src_effects_prat__resonance__snapshot_unbox(_x_x2166, KK_OWNED, _ctx);
  }
  {
    kk_src_effects_prat__resonance__snapshot snap;
    double _x_x2169;
    kk_box_t _x_x2170;
    kk_box_t _x_x2174;
    kk_src_effects_prat__resonance__resonance_hints _x_x2175 = kk_src_effects_prat__resonance__resonance_hints_dup(x_10209, _ctx); /*src/effects/prat_resonance/resonance-hints*/
    _x_x2174 = kk_src_effects_prat__resonance__resonance_hints_box(_x_x2175, _ctx); /*10000*/
    _x_x2170 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance_new_track_prat_invocation_fun2171(_ctx), _x_x2174, _ctx); /*10001*/
    _x_x2169 = kk_double_unbox(_x_x2170, KK_OWNED, _ctx); /*float64*/
    kk_integer_t _x_x2176;
    kk_box_t _x_x2177;
    kk_box_t _x_x2181;
    kk_src_effects_prat__resonance__resonance_hints _x_x2182 = kk_src_effects_prat__resonance__resonance_hints_dup(x_10209, _ctx); /*src/effects/prat_resonance/resonance-hints*/
    _x_x2181 = kk_src_effects_prat__resonance__resonance_hints_box(_x_x2182, _ctx); /*10000*/
    _x_x2177 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance_new_track_prat_invocation_fun2178(_ctx), _x_x2181, _ctx); /*10001*/
    _x_x2176 = kk_integer_unbox(_x_x2177, _ctx); /*int*/
    double _x_x2183;
    kk_box_t _x_x2184;
    kk_box_t _x_x2188;
    kk_src_effects_prat__resonance__resonance_hints _x_x2189 = kk_src_effects_prat__resonance__resonance_hints_dup(x_10209, _ctx); /*src/effects/prat_resonance/resonance-hints*/
    _x_x2188 = kk_src_effects_prat__resonance__resonance_hints_box(_x_x2189, _ctx); /*10000*/
    _x_x2184 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance_new_track_prat_invocation_fun2185(_ctx), _x_x2188, _ctx); /*10001*/
    _x_x2183 = kk_double_unbox(_x_x2184, KK_OWNED, _ctx); /*float64*/
    kk_string_t _x_x2190;
    kk_box_t _x_x2191;
    kk_box_t _x_x2195;
    kk_src_effects_prat__resonance__resonance_hints _x_x2196 = kk_src_effects_prat__resonance__resonance_hints_dup(x_10209, _ctx); /*src/effects/prat_resonance/resonance-hints*/
    _x_x2195 = kk_src_effects_prat__resonance__resonance_hints_box(_x_x2196, _ctx); /*10000*/
    _x_x2191 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance_new_track_prat_invocation_fun2192(_ctx), _x_x2195, _ctx); /*10001*/
    _x_x2190 = kk_string_unbox(_x_x2191); /*string*/
    kk_string_t _x_x2197;
    kk_box_t _x_x2198;
    kk_box_t _x_x2202;
    kk_src_effects_prat__resonance__resonance_hints _x_x2203 = kk_src_effects_prat__resonance__resonance_hints_dup(x_10209, _ctx); /*src/effects/prat_resonance/resonance-hints*/
    _x_x2202 = kk_src_effects_prat__resonance__resonance_hints_box(_x_x2203, _ctx); /*10000*/
    _x_x2198 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance_new_track_prat_invocation_fun2199(_ctx), _x_x2202, _ctx); /*10001*/
    _x_x2197 = kk_string_unbox(_x_x2198); /*string*/
    kk_string_t _x_x2204;
    kk_box_t _x_x2205 = kk_std_core_hnd__open_none1(kk_src_effects_prat__resonance_new_track_prat_invocation_fun2206(_ctx), kk_src_effects_prat__resonance__resonance_hints_box(x_10209, _ctx), _ctx); /*10001*/
    _x_x2204 = kk_string_unbox(_x_x2205); /*string*/
    snap = kk_src_effects_prat__resonance__new_Snapshot(kk_reuse_null, 0, gana_name, tool_name, operation, output, 0x0p+0, _x_x2169, _x_x2176, _x_x2183, _x_x2190, _x_x2197, _x_x2204, _ctx); /*src/effects/prat_resonance/snapshot*/
    kk_std_core_hnd__ev ev_10215 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<src/effects/prat_resonance/resonance>*/;
    kk_unit_t x_0_10212 = kk_Unit;
    kk_box_t _x_x2209;
    {
      struct kk_std_core_hnd_Ev* _con_x2210 = kk_std_core_hnd__as_Ev(ev_10215, _ctx);
      kk_box_t _box_x828 = _con_x2210->hnd;
      int32_t m = _con_x2210->marker;
      kk_src_effects_prat__resonance__resonance h = kk_src_effects_prat__resonance__resonance_unbox(_box_x828, KK_BORROWED, _ctx);
      kk_src_effects_prat__resonance__resonance_dup(h, _ctx);
      {
        struct kk_src_effects_prat__resonance__Hnd_resonance* _con_x2211 = kk_src_effects_prat__resonance__as_Hnd_resonance(h, _ctx);
        kk_integer_t _pat_0_5 = _con_x2211->_cfc;
        kk_std_core_hnd__clause0 _pat_1_6 = _con_x2211->_fun_get_call_count;
        kk_std_core_hnd__clause0 _pat_2_5 = _con_x2211->_fun_get_gana_counts;
        kk_std_core_hnd__clause0 _pat_3_5 = _con_x2211->_fun_get_guna_tag;
        kk_std_core_hnd__clause0 _pat_4_5 = _con_x2211->_fun_get_harmony_score;
        kk_std_core_hnd__clause0 _pat_5_5 = _con_x2211->_fun_get_last_snapshot;
        kk_std_core_hnd__clause0 _pat_6_0 = _con_x2211->_fun_get_lunar_mansion;
        kk_std_core_hnd__clause0 _pat_7_0 = _con_x2211->_fun_get_lunar_phase;
        kk_std_core_hnd__clause1 _pat_8_0 = _con_x2211->_fun_get_recent_history;
        kk_std_core_hnd__clause1 _fun_record_snapshot = _con_x2211->_fun_record_snapshot;
        kk_std_core_hnd__clause0 _pat_9_0 = _con_x2211->_fun_reset_state;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause0_drop(_pat_9_0, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_8_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_7_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_6_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_5_5, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_4_5, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_3_5, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_5, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_6, _ctx);
          kk_integer_drop(_pat_0_5, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_fun_record_snapshot, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x832 = _fun_record_snapshot.clause;
          kk_box_t _x_x2212;
          kk_src_effects_prat__resonance__snapshot _x_x2213 = kk_src_effects_prat__resonance__snapshot_dup(snap, _ctx); /*src/effects/prat_resonance/snapshot*/
          _x_x2212 = kk_src_effects_prat__resonance__snapshot_box(_x_x2213, _ctx); /*10009*/
          _x_x2209 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x832, (_fun_unbox_x832, m, ev_10215, _x_x2212, _ctx), _ctx); /*10010*/
        }
      }
    }
    kk_unit_unbox(_x_x2209);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2214 = kk_std_core_hnd_yield_extend(kk_src_effects_prat__resonance_new_track_prat_invocation_fun2215(snap, _ctx), _ctx); /*10001*/
      return kk_src_effects_prat__resonance__snapshot_unbox(_x_x2214, KK_OWNED, _ctx);
    }
    {
      return snap;
    }
  }
}

// initialization
void kk_src_effects_prat__resonance__init(kk_context_t* _ctx){
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
  kk_std_time__init(_ctx);
  kk_std_num_random__init(_ctx);
  kk_std_core_vector__init(_ctx);
  kk_std_num_float64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x945;
    kk_define_string_literal(, _s_x946, 24, "resonance@prat_resonance", _ctx)
    _x_x945 = kk_string_dup(_s_x946, _ctx); /*string*/
    kk_src_effects_prat__resonance_resonance_fs__tag = kk_std_core_hnd__new_Htag(_x_x945, _ctx); /*hnd/htag<src/effects/prat_resonance/resonance>*/
  }
  {
    kk_box_t _x_x1049;
    kk_std_core_types__tuple2 _x_x1050;
    kk_box_t _x_x1051;
    kk_string_t _x_x1052;
    kk_define_string_literal(, _s_x1053, 9, "gana_horn", _ctx)
    _x_x1052 = kk_string_dup(_s_x1053, _ctx); /*string*/
    _x_x1051 = kk_string_box(_x_x1052); /*10037*/
    kk_box_t _x_x1054;
    kk_src_effects_prat__resonance__ganainfo _x_x1055;
    kk_string_t _x_x1056;
    kk_define_string_literal(, _s_x1057, 4, "East", _ctx)
    _x_x1056 = kk_string_dup(_s_x1057, _ctx); /*string*/
    kk_string_t _x_x1058;
    kk_define_string_literal(, _s_x1059, 16, "Sharp initiation", _ctx)
    _x_x1058 = kk_string_dup(_s_x1059, _ctx); /*string*/
    kk_string_t _x_x1060;
    kk_define_string_literal(, _s_x1061, 7, "Courage", _ctx)
    _x_x1060 = kk_string_dup(_s_x1061, _ctx); /*string*/
    kk_string_t _x_x1062;
    kk_define_string_literal(, _s_x1063, 3, "" "\xE8\xA7\x92" "", _ctx)
    _x_x1062 = kk_string_dup(_s_x1063, _ctx); /*string*/
    kk_string_t _x_x1064;
    kk_define_string_literal(, _s_x1065, 4, "Jiao", _ctx)
    _x_x1064 = kk_string_dup(_s_x1065, _ctx); /*string*/
    _x_x1055 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(1), _x_x1056, _x_x1058, _x_x1060, _x_x1062, _x_x1064, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1054 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1055, _ctx); /*10038*/
    _x_x1050 = kk_std_core_types__new_Tuple2(_x_x1051, _x_x1054, _ctx); /*(10037, 10038)*/
    _x_x1049 = kk_std_core_types__tuple2_box(_x_x1050, _ctx); /*10021*/
    kk_std_core_types__list _x_x1066;
    kk_box_t _x_x1067;
    kk_std_core_types__tuple2 _x_x1068;
    kk_box_t _x_x1069;
    kk_string_t _x_x1070;
    kk_define_string_literal(, _s_x1071, 9, "gana_neck", _ctx)
    _x_x1070 = kk_string_dup(_s_x1071, _ctx); /*string*/
    _x_x1069 = kk_string_box(_x_x1070); /*10037*/
    kk_box_t _x_x1072;
    kk_src_effects_prat__resonance__ganainfo _x_x1073;
    kk_string_t _x_x1074;
    kk_define_string_literal(, _s_x1075, 4, "East", _ctx)
    _x_x1074 = kk_string_dup(_s_x1075, _ctx); /*string*/
    kk_string_t _x_x1076;
    kk_define_string_literal(, _s_x1077, 9, "Stability", _ctx)
    _x_x1076 = kk_string_dup(_s_x1077, _ctx); /*string*/
    kk_string_t _x_x1078;
    kk_define_string_literal(, _s_x1079, 8, "Practice", _ctx)
    _x_x1078 = kk_string_dup(_s_x1079, _ctx); /*string*/
    kk_string_t _x_x1080;
    kk_define_string_literal(, _s_x1081, 3, "" "\xE4\xBA\xA2" "", _ctx)
    _x_x1080 = kk_string_dup(_s_x1081, _ctx); /*string*/
    kk_string_t _x_x1082;
    kk_define_string_literal(, _s_x1083, 4, "Kang", _ctx)
    _x_x1082 = kk_string_dup(_s_x1083, _ctx); /*string*/
    _x_x1073 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(2), _x_x1074, _x_x1076, _x_x1078, _x_x1080, _x_x1082, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1072 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1073, _ctx); /*10038*/
    _x_x1068 = kk_std_core_types__new_Tuple2(_x_x1069, _x_x1072, _ctx); /*(10037, 10038)*/
    _x_x1067 = kk_std_core_types__tuple2_box(_x_x1068, _ctx); /*10021*/
    kk_std_core_types__list _x_x1084;
    kk_box_t _x_x1085;
    kk_std_core_types__tuple2 _x_x1086;
    kk_box_t _x_x1087;
    kk_string_t _x_x1088;
    kk_define_string_literal(, _s_x1089, 9, "gana_root", _ctx)
    _x_x1088 = kk_string_dup(_s_x1089, _ctx); /*string*/
    _x_x1087 = kk_string_box(_x_x1088); /*10037*/
    kk_box_t _x_x1090;
    kk_src_effects_prat__resonance__ganainfo _x_x1091;
    kk_string_t _x_x1092;
    kk_define_string_literal(, _s_x1093, 4, "East", _ctx)
    _x_x1092 = kk_string_dup(_s_x1093, _ctx); /*string*/
    kk_string_t _x_x1094;
    kk_define_string_literal(, _s_x1095, 10, "Foundation", _ctx)
    _x_x1094 = kk_string_dup(_s_x1095, _ctx); /*string*/
    kk_string_t _x_x1096;
    kk_define_string_literal(, _s_x1097, 5, "Truth", _ctx)
    _x_x1096 = kk_string_dup(_s_x1097, _ctx); /*string*/
    kk_string_t _x_x1098;
    kk_define_string_literal(, _s_x1099, 3, "" "\xE6\xB0\x90" "", _ctx)
    _x_x1098 = kk_string_dup(_s_x1099, _ctx); /*string*/
    kk_string_t _x_x1100;
    kk_define_string_literal(, _s_x1101, 2, "Di", _ctx)
    _x_x1100 = kk_string_dup(_s_x1101, _ctx); /*string*/
    _x_x1091 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(3), _x_x1092, _x_x1094, _x_x1096, _x_x1098, _x_x1100, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1090 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1091, _ctx); /*10038*/
    _x_x1086 = kk_std_core_types__new_Tuple2(_x_x1087, _x_x1090, _ctx); /*(10037, 10038)*/
    _x_x1085 = kk_std_core_types__tuple2_box(_x_x1086, _ctx); /*10021*/
    kk_std_core_types__list _x_x1102;
    kk_box_t _x_x1103;
    kk_std_core_types__tuple2 _x_x1104;
    kk_box_t _x_x1105;
    kk_string_t _x_x1106;
    kk_define_string_literal(, _s_x1107, 9, "gana_room", _ctx)
    _x_x1106 = kk_string_dup(_s_x1107, _ctx); /*string*/
    _x_x1105 = kk_string_box(_x_x1106); /*10037*/
    kk_box_t _x_x1108;
    kk_src_effects_prat__resonance__ganainfo _x_x1109;
    kk_string_t _x_x1110;
    kk_define_string_literal(, _s_x1111, 4, "East", _ctx)
    _x_x1110 = kk_string_dup(_s_x1111, _ctx); /*string*/
    kk_string_t _x_x1112;
    kk_define_string_literal(, _s_x1113, 9, "Enclosure", _ctx)
    _x_x1112 = kk_string_dup(_s_x1113, _ctx); /*string*/
    kk_string_t _x_x1114;
    kk_define_string_literal(, _s_x1115, 9, "Sanctuary", _ctx)
    _x_x1114 = kk_string_dup(_s_x1115, _ctx); /*string*/
    kk_string_t _x_x1116;
    kk_define_string_literal(, _s_x1117, 3, "" "\xE6\x88\xBF" "", _ctx)
    _x_x1116 = kk_string_dup(_s_x1117, _ctx); /*string*/
    kk_string_t _x_x1118;
    kk_define_string_literal(, _s_x1119, 4, "Fang", _ctx)
    _x_x1118 = kk_string_dup(_s_x1119, _ctx); /*string*/
    _x_x1109 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(4), _x_x1110, _x_x1112, _x_x1114, _x_x1116, _x_x1118, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1108 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1109, _ctx); /*10038*/
    _x_x1104 = kk_std_core_types__new_Tuple2(_x_x1105, _x_x1108, _ctx); /*(10037, 10038)*/
    _x_x1103 = kk_std_core_types__tuple2_box(_x_x1104, _ctx); /*10021*/
    kk_std_core_types__list _x_x1120;
    kk_box_t _x_x1121;
    kk_std_core_types__tuple2 _x_x1122;
    kk_box_t _x_x1123;
    kk_string_t _x_x1124;
    kk_define_string_literal(, _s_x1125, 10, "gana_heart", _ctx)
    _x_x1124 = kk_string_dup(_s_x1125, _ctx); /*string*/
    _x_x1123 = kk_string_box(_x_x1124); /*10037*/
    kk_box_t _x_x1126;
    kk_src_effects_prat__resonance__ganainfo _x_x1127;
    kk_string_t _x_x1128;
    kk_define_string_literal(, _s_x1129, 4, "East", _ctx)
    _x_x1128 = kk_string_dup(_s_x1129, _ctx); /*string*/
    kk_string_t _x_x1130;
    kk_define_string_literal(, _s_x1131, 11, "Vital pulse", _ctx)
    _x_x1130 = kk_string_dup(_s_x1131, _ctx); /*string*/
    kk_string_t _x_x1132;
    kk_define_string_literal(, _s_x1133, 4, "Love", _ctx)
    _x_x1132 = kk_string_dup(_s_x1133, _ctx); /*string*/
    kk_string_t _x_x1134;
    kk_define_string_literal(, _s_x1135, 3, "" "\xE5\xBF\x83" "", _ctx)
    _x_x1134 = kk_string_dup(_s_x1135, _ctx); /*string*/
    kk_string_t _x_x1136;
    kk_define_string_literal(, _s_x1137, 3, "Xin", _ctx)
    _x_x1136 = kk_string_dup(_s_x1137, _ctx); /*string*/
    _x_x1127 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(5), _x_x1128, _x_x1130, _x_x1132, _x_x1134, _x_x1136, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1126 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1127, _ctx); /*10038*/
    _x_x1122 = kk_std_core_types__new_Tuple2(_x_x1123, _x_x1126, _ctx); /*(10037, 10038)*/
    _x_x1121 = kk_std_core_types__tuple2_box(_x_x1122, _ctx); /*10021*/
    kk_std_core_types__list _x_x1138;
    kk_box_t _x_x1139;
    kk_std_core_types__tuple2 _x_x1140;
    kk_box_t _x_x1141;
    kk_string_t _x_x1142;
    kk_define_string_literal(, _s_x1143, 9, "gana_tail", _ctx)
    _x_x1142 = kk_string_dup(_s_x1143, _ctx); /*string*/
    _x_x1141 = kk_string_box(_x_x1142); /*10037*/
    kk_box_t _x_x1144;
    kk_src_effects_prat__resonance__ganainfo _x_x1145;
    kk_string_t _x_x1146;
    kk_define_string_literal(, _s_x1147, 4, "East", _ctx)
    _x_x1146 = kk_string_dup(_s_x1147, _ctx); /*string*/
    kk_string_t _x_x1148;
    kk_define_string_literal(, _s_x1149, 16, "Passionate drive", _ctx)
    _x_x1148 = kk_string_dup(_s_x1149, _ctx); /*string*/
    kk_string_t _x_x1150;
    kk_define_string_literal(, _s_x1151, 5, "Metal", _ctx)
    _x_x1150 = kk_string_dup(_s_x1151, _ctx); /*string*/
    kk_string_t _x_x1152;
    kk_define_string_literal(, _s_x1153, 3, "" "\xE5\xB0\xBE" "", _ctx)
    _x_x1152 = kk_string_dup(_s_x1153, _ctx); /*string*/
    kk_string_t _x_x1154;
    kk_define_string_literal(, _s_x1155, 3, "Wei", _ctx)
    _x_x1154 = kk_string_dup(_s_x1155, _ctx); /*string*/
    _x_x1145 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(6), _x_x1146, _x_x1148, _x_x1150, _x_x1152, _x_x1154, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1144 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1145, _ctx); /*10038*/
    _x_x1140 = kk_std_core_types__new_Tuple2(_x_x1141, _x_x1144, _ctx); /*(10037, 10038)*/
    _x_x1139 = kk_std_core_types__tuple2_box(_x_x1140, _ctx); /*10021*/
    kk_std_core_types__list _x_x1156;
    kk_box_t _x_x1157;
    kk_std_core_types__tuple2 _x_x1158;
    kk_box_t _x_x1159;
    kk_string_t _x_x1160;
    kk_define_string_literal(, _s_x1161, 21, "gana_winnowing_basket", _ctx)
    _x_x1160 = kk_string_dup(_s_x1161, _ctx); /*string*/
    _x_x1159 = kk_string_box(_x_x1160); /*10037*/
    kk_box_t _x_x1162;
    kk_src_effects_prat__resonance__ganainfo _x_x1163;
    kk_string_t _x_x1164;
    kk_define_string_literal(, _s_x1165, 4, "East", _ctx)
    _x_x1164 = kk_string_dup(_s_x1165, _ctx); /*string*/
    kk_string_t _x_x1166;
    kk_define_string_literal(, _s_x1167, 10, "Separation", _ctx)
    _x_x1166 = kk_string_dup(_s_x1167, _ctx); /*string*/
    kk_string_t _x_x1168;
    kk_define_string_literal(, _s_x1169, 6, "Wisdom", _ctx)
    _x_x1168 = kk_string_dup(_s_x1169, _ctx); /*string*/
    kk_string_t _x_x1170;
    kk_define_string_literal(, _s_x1171, 3, "" "\xE7\xAE\x95" "", _ctx)
    _x_x1170 = kk_string_dup(_s_x1171, _ctx); /*string*/
    kk_string_t _x_x1172;
    kk_define_string_literal(, _s_x1173, 2, "Ji", _ctx)
    _x_x1172 = kk_string_dup(_s_x1173, _ctx); /*string*/
    _x_x1163 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(7), _x_x1164, _x_x1166, _x_x1168, _x_x1170, _x_x1172, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1162 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1163, _ctx); /*10038*/
    _x_x1158 = kk_std_core_types__new_Tuple2(_x_x1159, _x_x1162, _ctx); /*(10037, 10038)*/
    _x_x1157 = kk_std_core_types__tuple2_box(_x_x1158, _ctx); /*10021*/
    kk_std_core_types__list _x_x1174;
    kk_box_t _x_x1175;
    kk_std_core_types__tuple2 _x_x1176;
    kk_box_t _x_x1177;
    kk_string_t _x_x1178;
    kk_define_string_literal(, _s_x1179, 10, "gana_ghost", _ctx)
    _x_x1178 = kk_string_dup(_s_x1179, _ctx); /*string*/
    _x_x1177 = kk_string_box(_x_x1178); /*10037*/
    kk_box_t _x_x1180;
    kk_src_effects_prat__resonance__ganainfo _x_x1181;
    kk_string_t _x_x1182;
    kk_define_string_literal(, _s_x1183, 5, "South", _ctx)
    _x_x1182 = kk_string_dup(_s_x1183, _ctx); /*string*/
    kk_string_t _x_x1184;
    kk_define_string_literal(, _s_x1185, 13, "Introspection", _ctx)
    _x_x1184 = kk_string_dup(_s_x1185, _ctx); /*string*/
    kk_string_t _x_x1186;
    kk_define_string_literal(, _s_x1187, 5, "Grief", _ctx)
    _x_x1186 = kk_string_dup(_s_x1187, _ctx); /*string*/
    kk_string_t _x_x1188;
    kk_define_string_literal(, _s_x1189, 3, "" "\xE9\xAC\xBC" "", _ctx)
    _x_x1188 = kk_string_dup(_s_x1189, _ctx); /*string*/
    kk_string_t _x_x1190;
    kk_define_string_literal(, _s_x1191, 3, "Gui", _ctx)
    _x_x1190 = kk_string_dup(_s_x1191, _ctx); /*string*/
    _x_x1181 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(8), _x_x1182, _x_x1184, _x_x1186, _x_x1188, _x_x1190, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1180 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1181, _ctx); /*10038*/
    _x_x1176 = kk_std_core_types__new_Tuple2(_x_x1177, _x_x1180, _ctx); /*(10037, 10038)*/
    _x_x1175 = kk_std_core_types__tuple2_box(_x_x1176, _ctx); /*10021*/
    kk_std_core_types__list _x_x1192;
    kk_box_t _x_x1193;
    kk_std_core_types__tuple2 _x_x1194;
    kk_box_t _x_x1195;
    kk_string_t _x_x1196;
    kk_define_string_literal(, _s_x1197, 11, "gana_willow", _ctx)
    _x_x1196 = kk_string_dup(_s_x1197, _ctx); /*string*/
    _x_x1195 = kk_string_box(_x_x1196); /*10037*/
    kk_box_t _x_x1198;
    kk_src_effects_prat__resonance__ganainfo _x_x1199;
    kk_string_t _x_x1200;
    kk_define_string_literal(, _s_x1201, 5, "South", _ctx)
    _x_x1200 = kk_string_dup(_s_x1201, _ctx); /*string*/
    kk_string_t _x_x1202;
    kk_define_string_literal(, _s_x1203, 11, "Flexibility", _ctx)
    _x_x1202 = kk_string_dup(_s_x1203, _ctx); /*string*/
    kk_string_t _x_x1204;
    kk_define_string_literal(, _s_x1205, 4, "Play", _ctx)
    _x_x1204 = kk_string_dup(_s_x1205, _ctx); /*string*/
    kk_string_t _x_x1206;
    kk_define_string_literal(, _s_x1207, 3, "" "\xE6\x9F\xB3" "", _ctx)
    _x_x1206 = kk_string_dup(_s_x1207, _ctx); /*string*/
    kk_string_t _x_x1208;
    kk_define_string_literal(, _s_x1209, 3, "Liu", _ctx)
    _x_x1208 = kk_string_dup(_s_x1209, _ctx); /*string*/
    _x_x1199 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(9), _x_x1200, _x_x1202, _x_x1204, _x_x1206, _x_x1208, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1198 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1199, _ctx); /*10038*/
    _x_x1194 = kk_std_core_types__new_Tuple2(_x_x1195, _x_x1198, _ctx); /*(10037, 10038)*/
    _x_x1193 = kk_std_core_types__tuple2_box(_x_x1194, _ctx); /*10021*/
    kk_std_core_types__list _x_x1210;
    kk_box_t _x_x1211;
    kk_std_core_types__tuple2 _x_x1212;
    kk_box_t _x_x1213;
    kk_string_t _x_x1214;
    kk_define_string_literal(, _s_x1215, 9, "gana_star", _ctx)
    _x_x1214 = kk_string_dup(_s_x1215, _ctx); /*string*/
    _x_x1213 = kk_string_box(_x_x1214); /*10037*/
    kk_box_t _x_x1216;
    kk_src_effects_prat__resonance__ganainfo _x_x1217;
    kk_string_t _x_x1218;
    kk_define_string_literal(, _s_x1219, 5, "South", _ctx)
    _x_x1218 = kk_string_dup(_s_x1219, _ctx); /*string*/
    kk_string_t _x_x1220;
    kk_define_string_literal(, _s_x1221, 12, "Illumination", _ctx)
    _x_x1220 = kk_string_dup(_s_x1221, _ctx); /*string*/
    kk_string_t _x_x1222;
    kk_define_string_literal(, _s_x1223, 6, "Beauty", _ctx)
    _x_x1222 = kk_string_dup(_s_x1223, _ctx); /*string*/
    kk_string_t _x_x1224;
    kk_define_string_literal(, _s_x1225, 3, "" "\xE6\x98\x9F" "", _ctx)
    _x_x1224 = kk_string_dup(_s_x1225, _ctx); /*string*/
    kk_string_t _x_x1226;
    kk_define_string_literal(, _s_x1227, 4, "Xing", _ctx)
    _x_x1226 = kk_string_dup(_s_x1227, _ctx); /*string*/
    _x_x1217 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(10), _x_x1218, _x_x1220, _x_x1222, _x_x1224, _x_x1226, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1216 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1217, _ctx); /*10038*/
    _x_x1212 = kk_std_core_types__new_Tuple2(_x_x1213, _x_x1216, _ctx); /*(10037, 10038)*/
    _x_x1211 = kk_std_core_types__tuple2_box(_x_x1212, _ctx); /*10021*/
    kk_std_core_types__list _x_x1228;
    kk_box_t _x_x1229;
    kk_std_core_types__tuple2 _x_x1230;
    kk_box_t _x_x1231;
    kk_string_t _x_x1232;
    kk_define_string_literal(, _s_x1233, 17, "gana_extended_net", _ctx)
    _x_x1232 = kk_string_dup(_s_x1233, _ctx); /*string*/
    _x_x1231 = kk_string_box(_x_x1232); /*10037*/
    kk_box_t _x_x1234;
    kk_src_effects_prat__resonance__ganainfo _x_x1235;
    kk_string_t _x_x1236;
    kk_define_string_literal(, _s_x1237, 5, "South", _ctx)
    _x_x1236 = kk_string_dup(_s_x1237, _ctx); /*string*/
    kk_string_t _x_x1238;
    kk_define_string_literal(, _s_x1239, 12, "Connectivity", _ctx)
    _x_x1238 = kk_string_dup(_s_x1239, _ctx); /*string*/
    kk_string_t _x_x1240;
    kk_define_string_literal(, _s_x1241, 10, "Connection", _ctx)
    _x_x1240 = kk_string_dup(_s_x1241, _ctx); /*string*/
    kk_string_t _x_x1242;
    kk_define_string_literal(, _s_x1243, 3, "" "\xE5\xBC\xA0" "", _ctx)
    _x_x1242 = kk_string_dup(_s_x1243, _ctx); /*string*/
    kk_string_t _x_x1244;
    kk_define_string_literal(, _s_x1245, 5, "Zhang", _ctx)
    _x_x1244 = kk_string_dup(_s_x1245, _ctx); /*string*/
    _x_x1235 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(11), _x_x1236, _x_x1238, _x_x1240, _x_x1242, _x_x1244, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1234 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1235, _ctx); /*10038*/
    _x_x1230 = kk_std_core_types__new_Tuple2(_x_x1231, _x_x1234, _ctx); /*(10037, 10038)*/
    _x_x1229 = kk_std_core_types__tuple2_box(_x_x1230, _ctx); /*10021*/
    kk_std_core_types__list _x_x1246;
    kk_box_t _x_x1247;
    kk_std_core_types__tuple2 _x_x1248;
    kk_box_t _x_x1249;
    kk_string_t _x_x1250;
    kk_define_string_literal(, _s_x1251, 10, "gana_wings", _ctx)
    _x_x1250 = kk_string_dup(_s_x1251, _ctx); /*string*/
    _x_x1249 = kk_string_box(_x_x1250); /*10037*/
    kk_box_t _x_x1252;
    kk_src_effects_prat__resonance__ganainfo _x_x1253;
    kk_string_t _x_x1254;
    kk_define_string_literal(, _s_x1255, 5, "South", _ctx)
    _x_x1254 = kk_string_dup(_s_x1255, _ctx); /*string*/
    kk_string_t _x_x1256;
    kk_define_string_literal(, _s_x1257, 9, "Expansion", _ctx)
    _x_x1256 = kk_string_dup(_s_x1257, _ctx); /*string*/
    kk_string_t _x_x1258;
    kk_define_string_literal(, _s_x1259, 9, "Adventure", _ctx)
    _x_x1258 = kk_string_dup(_s_x1259, _ctx); /*string*/
    kk_string_t _x_x1260;
    kk_define_string_literal(, _s_x1261, 3, "" "\xE7\xBF\xBC" "", _ctx)
    _x_x1260 = kk_string_dup(_s_x1261, _ctx); /*string*/
    kk_string_t _x_x1262;
    kk_define_string_literal(, _s_x1263, 2, "Yi", _ctx)
    _x_x1262 = kk_string_dup(_s_x1263, _ctx); /*string*/
    _x_x1253 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(12), _x_x1254, _x_x1256, _x_x1258, _x_x1260, _x_x1262, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1252 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1253, _ctx); /*10038*/
    _x_x1248 = kk_std_core_types__new_Tuple2(_x_x1249, _x_x1252, _ctx); /*(10037, 10038)*/
    _x_x1247 = kk_std_core_types__tuple2_box(_x_x1248, _ctx); /*10021*/
    kk_std_core_types__list _x_x1264;
    kk_box_t _x_x1265;
    kk_std_core_types__tuple2 _x_x1266;
    kk_box_t _x_x1267;
    kk_string_t _x_x1268;
    kk_define_string_literal(, _s_x1269, 12, "gana_chariot", _ctx)
    _x_x1268 = kk_string_dup(_s_x1269, _ctx); /*string*/
    _x_x1267 = kk_string_box(_x_x1268); /*10037*/
    kk_box_t _x_x1270;
    kk_src_effects_prat__resonance__ganainfo _x_x1271;
    kk_string_t _x_x1272;
    kk_define_string_literal(, _s_x1273, 5, "South", _ctx)
    _x_x1272 = kk_string_dup(_s_x1273, _ctx); /*string*/
    kk_string_t _x_x1274;
    kk_define_string_literal(, _s_x1275, 8, "Movement", _ctx)
    _x_x1274 = kk_string_dup(_s_x1275, _ctx); /*string*/
    kk_string_t _x_x1276;
    kk_define_string_literal(, _s_x1277, 14, "Transformation", _ctx)
    _x_x1276 = kk_string_dup(_s_x1277, _ctx); /*string*/
    kk_string_t _x_x1278;
    kk_define_string_literal(, _s_x1279, 3, "" "\xE8\xBD\xB8" "", _ctx)
    _x_x1278 = kk_string_dup(_s_x1279, _ctx); /*string*/
    kk_string_t _x_x1280;
    kk_define_string_literal(, _s_x1281, 4, "Zhen", _ctx)
    _x_x1280 = kk_string_dup(_s_x1281, _ctx); /*string*/
    _x_x1271 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(13), _x_x1272, _x_x1274, _x_x1276, _x_x1278, _x_x1280, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1270 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1271, _ctx); /*10038*/
    _x_x1266 = kk_std_core_types__new_Tuple2(_x_x1267, _x_x1270, _ctx); /*(10037, 10038)*/
    _x_x1265 = kk_std_core_types__tuple2_box(_x_x1266, _ctx); /*10021*/
    kk_std_core_types__list _x_x1282;
    kk_box_t _x_x1283;
    kk_std_core_types__tuple2 _x_x1284;
    kk_box_t _x_x1285;
    kk_string_t _x_x1286;
    kk_define_string_literal(, _s_x1287, 14, "gana_abundance", _ctx)
    _x_x1286 = kk_string_dup(_s_x1287, _ctx); /*string*/
    _x_x1285 = kk_string_box(_x_x1286); /*10037*/
    kk_box_t _x_x1288;
    kk_src_effects_prat__resonance__ganainfo _x_x1289;
    kk_string_t _x_x1290;
    kk_define_string_literal(, _s_x1291, 5, "South", _ctx)
    _x_x1290 = kk_string_dup(_s_x1291, _ctx); /*string*/
    kk_string_t _x_x1292;
    kk_define_string_literal(, _s_x1293, 7, "Surplus", _ctx)
    _x_x1292 = kk_string_dup(_s_x1293, _ctx); /*string*/
    kk_string_t _x_x1294;
    kk_define_string_literal(, _s_x1295, 3, "Joy", _ctx)
    _x_x1294 = kk_string_dup(_s_x1295, _ctx); /*string*/
    kk_string_t _x_x1296;
    kk_define_string_literal(, _s_x1297, 3, "" "\xE8\xB1\x90" "", _ctx)
    _x_x1296 = kk_string_dup(_s_x1297, _ctx); /*string*/
    kk_string_t _x_x1298;
    kk_define_string_literal(, _s_x1299, 4, "Feng", _ctx)
    _x_x1298 = kk_string_dup(_s_x1299, _ctx); /*string*/
    _x_x1289 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(14), _x_x1290, _x_x1292, _x_x1294, _x_x1296, _x_x1298, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1288 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1289, _ctx); /*10038*/
    _x_x1284 = kk_std_core_types__new_Tuple2(_x_x1285, _x_x1288, _ctx); /*(10037, 10038)*/
    _x_x1283 = kk_std_core_types__tuple2_box(_x_x1284, _ctx); /*10021*/
    kk_std_core_types__list _x_x1300;
    kk_box_t _x_x1301;
    kk_std_core_types__tuple2 _x_x1302;
    kk_box_t _x_x1303;
    kk_string_t _x_x1304;
    kk_define_string_literal(, _s_x1305, 20, "gana_straddling_legs", _ctx)
    _x_x1304 = kk_string_dup(_s_x1305, _ctx); /*string*/
    _x_x1303 = kk_string_box(_x_x1304); /*10037*/
    kk_box_t _x_x1306;
    kk_src_effects_prat__resonance__ganainfo _x_x1307;
    kk_string_t _x_x1308;
    kk_define_string_literal(, _s_x1309, 4, "West", _ctx)
    _x_x1308 = kk_string_dup(_s_x1309, _ctx); /*string*/
    kk_string_t _x_x1310;
    kk_define_string_literal(, _s_x1311, 7, "Balance", _ctx)
    _x_x1310 = kk_string_dup(_s_x1311, _ctx); /*string*/
    kk_string_t _x_x1312;
    kk_define_string_literal(, _s_x1313, 8, "Patience", _ctx)
    _x_x1312 = kk_string_dup(_s_x1313, _ctx); /*string*/
    kk_string_t _x_x1314;
    kk_define_string_literal(, _s_x1315, 3, "" "\xE5\xA5\x8E" "", _ctx)
    _x_x1314 = kk_string_dup(_s_x1315, _ctx); /*string*/
    kk_string_t _x_x1316;
    kk_define_string_literal(, _s_x1317, 3, "Kui", _ctx)
    _x_x1316 = kk_string_dup(_s_x1317, _ctx); /*string*/
    _x_x1307 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(15), _x_x1308, _x_x1310, _x_x1312, _x_x1314, _x_x1316, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1306 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1307, _ctx); /*10038*/
    _x_x1302 = kk_std_core_types__new_Tuple2(_x_x1303, _x_x1306, _ctx); /*(10037, 10038)*/
    _x_x1301 = kk_std_core_types__tuple2_box(_x_x1302, _ctx); /*10021*/
    kk_std_core_types__list _x_x1318;
    kk_box_t _x_x1319;
    kk_std_core_types__tuple2 _x_x1320;
    kk_box_t _x_x1321;
    kk_string_t _x_x1322;
    kk_define_string_literal(, _s_x1323, 10, "gana_mound", _ctx)
    _x_x1322 = kk_string_dup(_s_x1323, _ctx); /*string*/
    _x_x1321 = kk_string_box(_x_x1322); /*10037*/
    kk_box_t _x_x1324;
    kk_src_effects_prat__resonance__ganainfo _x_x1325;
    kk_string_t _x_x1326;
    kk_define_string_literal(, _s_x1327, 4, "West", _ctx)
    _x_x1326 = kk_string_dup(_s_x1327, _ctx); /*string*/
    kk_string_t _x_x1328;
    kk_define_string_literal(, _s_x1329, 12, "Accumulation", _ctx)
    _x_x1328 = kk_string_dup(_s_x1329, _ctx); /*string*/
    kk_string_t _x_x1330;
    kk_define_string_literal(, _s_x1331, 9, "Gratitude", _ctx)
    _x_x1330 = kk_string_dup(_s_x1331, _ctx); /*string*/
    kk_string_t _x_x1332;
    kk_define_string_literal(, _s_x1333, 3, "" "\xE5\xA8\x84" "", _ctx)
    _x_x1332 = kk_string_dup(_s_x1333, _ctx); /*string*/
    kk_string_t _x_x1334;
    kk_define_string_literal(, _s_x1335, 3, "Lou", _ctx)
    _x_x1334 = kk_string_dup(_s_x1335, _ctx); /*string*/
    _x_x1325 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(16), _x_x1326, _x_x1328, _x_x1330, _x_x1332, _x_x1334, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1324 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1325, _ctx); /*10038*/
    _x_x1320 = kk_std_core_types__new_Tuple2(_x_x1321, _x_x1324, _ctx); /*(10037, 10038)*/
    _x_x1319 = kk_std_core_types__tuple2_box(_x_x1320, _ctx); /*10021*/
    kk_std_core_types__list _x_x1336;
    kk_box_t _x_x1337;
    kk_std_core_types__tuple2 _x_x1338;
    kk_box_t _x_x1339;
    kk_string_t _x_x1340;
    kk_define_string_literal(, _s_x1341, 12, "gana_stomach", _ctx)
    _x_x1340 = kk_string_dup(_s_x1341, _ctx); /*string*/
    _x_x1339 = kk_string_box(_x_x1340); /*10037*/
    kk_box_t _x_x1342;
    kk_src_effects_prat__resonance__ganainfo _x_x1343;
    kk_string_t _x_x1344;
    kk_define_string_literal(, _s_x1345, 4, "West", _ctx)
    _x_x1344 = kk_string_dup(_s_x1345, _ctx); /*string*/
    kk_string_t _x_x1346;
    kk_define_string_literal(, _s_x1347, 11, "Nourishment", _ctx)
    _x_x1346 = kk_string_dup(_s_x1347, _ctx); /*string*/
    kk_string_t _x_x1348;
    kk_define_string_literal(, _s_x1349, 7, "Healing", _ctx)
    _x_x1348 = kk_string_dup(_s_x1349, _ctx); /*string*/
    kk_string_t _x_x1350;
    kk_define_string_literal(, _s_x1351, 3, "" "\xE8\x83\x83" "", _ctx)
    _x_x1350 = kk_string_dup(_s_x1351, _ctx); /*string*/
    kk_string_t _x_x1352;
    kk_define_string_literal(, _s_x1353, 3, "Wei", _ctx)
    _x_x1352 = kk_string_dup(_s_x1353, _ctx); /*string*/
    _x_x1343 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(17), _x_x1344, _x_x1346, _x_x1348, _x_x1350, _x_x1352, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1342 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1343, _ctx); /*10038*/
    _x_x1338 = kk_std_core_types__new_Tuple2(_x_x1339, _x_x1342, _ctx); /*(10037, 10038)*/
    _x_x1337 = kk_std_core_types__tuple2_box(_x_x1338, _ctx); /*10021*/
    kk_std_core_types__list _x_x1354;
    kk_box_t _x_x1355;
    kk_std_core_types__tuple2 _x_x1356;
    kk_box_t _x_x1357;
    kk_string_t _x_x1358;
    kk_define_string_literal(, _s_x1359, 15, "gana_hairy_head", _ctx)
    _x_x1358 = kk_string_dup(_s_x1359, _ctx); /*string*/
    _x_x1357 = kk_string_box(_x_x1358); /*10037*/
    kk_box_t _x_x1360;
    kk_src_effects_prat__resonance__ganainfo _x_x1361;
    kk_string_t _x_x1362;
    kk_define_string_literal(, _s_x1363, 4, "West", _ctx)
    _x_x1362 = kk_string_dup(_s_x1363, _ctx); /*string*/
    kk_string_t _x_x1364;
    kk_define_string_literal(, _s_x1365, 6, "Detail", _ctx)
    _x_x1364 = kk_string_dup(_s_x1365, _ctx); /*string*/
    kk_string_t _x_x1366;
    kk_define_string_literal(, _s_x1367, 8, "Presence", _ctx)
    _x_x1366 = kk_string_dup(_s_x1367, _ctx); /*string*/
    kk_string_t _x_x1368;
    kk_define_string_literal(, _s_x1369, 3, "" "\xE6\x98\xB4" "", _ctx)
    _x_x1368 = kk_string_dup(_s_x1369, _ctx); /*string*/
    kk_string_t _x_x1370;
    kk_define_string_literal(, _s_x1371, 3, "Mao", _ctx)
    _x_x1370 = kk_string_dup(_s_x1371, _ctx); /*string*/
    _x_x1361 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(18), _x_x1362, _x_x1364, _x_x1366, _x_x1368, _x_x1370, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1360 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1361, _ctx); /*10038*/
    _x_x1356 = kk_std_core_types__new_Tuple2(_x_x1357, _x_x1360, _ctx); /*(10037, 10038)*/
    _x_x1355 = kk_std_core_types__tuple2_box(_x_x1356, _ctx); /*10021*/
    kk_std_core_types__list _x_x1372;
    kk_box_t _x_x1373;
    kk_std_core_types__tuple2 _x_x1374;
    kk_box_t _x_x1375;
    kk_string_t _x_x1376;
    kk_define_string_literal(, _s_x1377, 8, "gana_net", _ctx)
    _x_x1376 = kk_string_dup(_s_x1377, _ctx); /*string*/
    _x_x1375 = kk_string_box(_x_x1376); /*10037*/
    kk_box_t _x_x1378;
    kk_src_effects_prat__resonance__ganainfo _x_x1379;
    kk_string_t _x_x1380;
    kk_define_string_literal(, _s_x1381, 4, "West", _ctx)
    _x_x1380 = kk_string_dup(_s_x1381, _ctx); /*string*/
    kk_string_t _x_x1382;
    kk_define_string_literal(, _s_x1383, 7, "Capture", _ctx)
    _x_x1382 = kk_string_dup(_s_x1383, _ctx); /*string*/
    kk_string_t _x_x1384;
    kk_define_string_literal(, _s_x1385, 7, "Mystery", _ctx)
    _x_x1384 = kk_string_dup(_s_x1385, _ctx); /*string*/
    kk_string_t _x_x1386;
    kk_define_string_literal(, _s_x1387, 3, "" "\xE6\xAF\x95" "", _ctx)
    _x_x1386 = kk_string_dup(_s_x1387, _ctx); /*string*/
    kk_string_t _x_x1388;
    kk_define_string_literal(, _s_x1389, 2, "Bi", _ctx)
    _x_x1388 = kk_string_dup(_s_x1389, _ctx); /*string*/
    _x_x1379 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(19), _x_x1380, _x_x1382, _x_x1384, _x_x1386, _x_x1388, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1378 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1379, _ctx); /*10038*/
    _x_x1374 = kk_std_core_types__new_Tuple2(_x_x1375, _x_x1378, _ctx); /*(10037, 10038)*/
    _x_x1373 = kk_std_core_types__tuple2_box(_x_x1374, _ctx); /*10021*/
    kk_std_core_types__list _x_x1390;
    kk_box_t _x_x1391;
    kk_std_core_types__tuple2 _x_x1392;
    kk_box_t _x_x1393;
    kk_string_t _x_x1394;
    kk_define_string_literal(, _s_x1395, 16, "gana_turtle_beak", _ctx)
    _x_x1394 = kk_string_dup(_s_x1395, _ctx); /*string*/
    _x_x1393 = kk_string_box(_x_x1394); /*10037*/
    kk_box_t _x_x1396;
    kk_src_effects_prat__resonance__ganainfo _x_x1397;
    kk_string_t _x_x1398;
    kk_define_string_literal(, _s_x1399, 4, "West", _ctx)
    _x_x1398 = kk_string_dup(_s_x1399, _ctx); /*string*/
    kk_string_t _x_x1400;
    kk_define_string_literal(, _s_x1401, 9, "Precision", _ctx)
    _x_x1400 = kk_string_dup(_s_x1401, _ctx); /*string*/
    kk_string_t _x_x1402;
    kk_define_string_literal(, _s_x1403, 5, "Voice", _ctx)
    _x_x1402 = kk_string_dup(_s_x1403, _ctx); /*string*/
    kk_string_t _x_x1404;
    kk_define_string_literal(, _s_x1405, 3, "" "\xE8\xA7\x9C" "", _ctx)
    _x_x1404 = kk_string_dup(_s_x1405, _ctx); /*string*/
    kk_string_t _x_x1406;
    kk_define_string_literal(, _s_x1407, 3, "Zui", _ctx)
    _x_x1406 = kk_string_dup(_s_x1407, _ctx); /*string*/
    _x_x1397 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(20), _x_x1398, _x_x1400, _x_x1402, _x_x1404, _x_x1406, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1396 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1397, _ctx); /*10038*/
    _x_x1392 = kk_std_core_types__new_Tuple2(_x_x1393, _x_x1396, _ctx); /*(10037, 10038)*/
    _x_x1391 = kk_std_core_types__tuple2_box(_x_x1392, _ctx); /*10021*/
    kk_std_core_types__list _x_x1408;
    kk_box_t _x_x1409;
    kk_std_core_types__tuple2 _x_x1410;
    kk_box_t _x_x1411;
    kk_string_t _x_x1412;
    kk_define_string_literal(, _s_x1413, 16, "gana_three_stars", _ctx)
    _x_x1412 = kk_string_dup(_s_x1413, _ctx); /*string*/
    _x_x1411 = kk_string_box(_x_x1412); /*10037*/
    kk_box_t _x_x1414;
    kk_src_effects_prat__resonance__ganainfo _x_x1415;
    kk_string_t _x_x1416;
    kk_define_string_literal(, _s_x1417, 4, "West", _ctx)
    _x_x1416 = kk_string_dup(_s_x1417, _ctx); /*string*/
    kk_string_t _x_x1418;
    kk_define_string_literal(, _s_x1419, 8, "Judgment", _ctx)
    _x_x1418 = kk_string_dup(_s_x1419, _ctx); /*string*/
    kk_string_t _x_x1420;
    kk_define_string_literal(, _s_x1421, 6, "Dharma", _ctx)
    _x_x1420 = kk_string_dup(_s_x1421, _ctx); /*string*/
    kk_string_t _x_x1422;
    kk_define_string_literal(, _s_x1423, 3, "" "\xE5\x8F\x82" "", _ctx)
    _x_x1422 = kk_string_dup(_s_x1423, _ctx); /*string*/
    kk_string_t _x_x1424;
    kk_define_string_literal(, _s_x1425, 4, "Shen", _ctx)
    _x_x1424 = kk_string_dup(_s_x1425, _ctx); /*string*/
    _x_x1415 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(21), _x_x1416, _x_x1418, _x_x1420, _x_x1422, _x_x1424, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1414 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1415, _ctx); /*10038*/
    _x_x1410 = kk_std_core_types__new_Tuple2(_x_x1411, _x_x1414, _ctx); /*(10037, 10038)*/
    _x_x1409 = kk_std_core_types__tuple2_box(_x_x1410, _ctx); /*10021*/
    kk_std_core_types__list _x_x1426;
    kk_box_t _x_x1427;
    kk_std_core_types__tuple2 _x_x1428;
    kk_box_t _x_x1429;
    kk_string_t _x_x1430;
    kk_define_string_literal(, _s_x1431, 11, "gana_dipper", _ctx)
    _x_x1430 = kk_string_dup(_s_x1431, _ctx); /*string*/
    _x_x1429 = kk_string_box(_x_x1430); /*10037*/
    kk_box_t _x_x1432;
    kk_src_effects_prat__resonance__ganainfo _x_x1433;
    kk_string_t _x_x1434;
    kk_define_string_literal(, _s_x1435, 5, "North", _ctx)
    _x_x1434 = kk_string_dup(_s_x1435, _ctx); /*string*/
    kk_string_t _x_x1436;
    kk_define_string_literal(, _s_x1437, 10, "Governance", _ctx)
    _x_x1436 = kk_string_dup(_s_x1437, _ctx); /*string*/
    kk_string_t _x_x1438;
    kk_define_string_literal(, _s_x1439, 3, "Awe", _ctx)
    _x_x1438 = kk_string_dup(_s_x1439, _ctx); /*string*/
    kk_string_t _x_x1440;
    kk_define_string_literal(, _s_x1441, 3, "" "\xE6\x96\x97" "", _ctx)
    _x_x1440 = kk_string_dup(_s_x1441, _ctx); /*string*/
    kk_string_t _x_x1442;
    kk_define_string_literal(, _s_x1443, 3, "Dou", _ctx)
    _x_x1442 = kk_string_dup(_s_x1443, _ctx); /*string*/
    _x_x1433 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(22), _x_x1434, _x_x1436, _x_x1438, _x_x1440, _x_x1442, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1432 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1433, _ctx); /*10038*/
    _x_x1428 = kk_std_core_types__new_Tuple2(_x_x1429, _x_x1432, _ctx); /*(10037, 10038)*/
    _x_x1427 = kk_std_core_types__tuple2_box(_x_x1428, _ctx); /*10021*/
    kk_std_core_types__list _x_x1444;
    kk_box_t _x_x1445;
    kk_std_core_types__tuple2 _x_x1446;
    kk_box_t _x_x1447;
    kk_string_t _x_x1448;
    kk_define_string_literal(, _s_x1449, 7, "gana_ox", _ctx)
    _x_x1448 = kk_string_dup(_s_x1449, _ctx); /*string*/
    _x_x1447 = kk_string_box(_x_x1448); /*10037*/
    kk_box_t _x_x1450;
    kk_src_effects_prat__resonance__ganainfo _x_x1451;
    kk_string_t _x_x1452;
    kk_define_string_literal(, _s_x1453, 5, "North", _ctx)
    _x_x1452 = kk_string_dup(_s_x1453, _ctx); /*string*/
    kk_string_t _x_x1454;
    kk_define_string_literal(, _s_x1455, 9, "Endurance", _ctx)
    _x_x1454 = kk_string_dup(_s_x1455, _ctx); /*string*/
    kk_string_t _x_x1456;
    kk_define_string_literal(, _s_x1457, 9, "Reverence", _ctx)
    _x_x1456 = kk_string_dup(_s_x1457, _ctx); /*string*/
    kk_string_t _x_x1458;
    kk_define_string_literal(, _s_x1459, 3, "" "\xE7\x89\x9B" "", _ctx)
    _x_x1458 = kk_string_dup(_s_x1459, _ctx); /*string*/
    kk_string_t _x_x1460;
    kk_define_string_literal(, _s_x1461, 3, "Niu", _ctx)
    _x_x1460 = kk_string_dup(_s_x1461, _ctx); /*string*/
    _x_x1451 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(23), _x_x1452, _x_x1454, _x_x1456, _x_x1458, _x_x1460, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1450 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1451, _ctx); /*10038*/
    _x_x1446 = kk_std_core_types__new_Tuple2(_x_x1447, _x_x1450, _ctx); /*(10037, 10038)*/
    _x_x1445 = kk_std_core_types__tuple2_box(_x_x1446, _ctx); /*10021*/
    kk_std_core_types__list _x_x1462;
    kk_box_t _x_x1463;
    kk_std_core_types__tuple2 _x_x1464;
    kk_box_t _x_x1465;
    kk_string_t _x_x1466;
    kk_define_string_literal(, _s_x1467, 9, "gana_girl", _ctx)
    _x_x1466 = kk_string_dup(_s_x1467, _ctx); /*string*/
    _x_x1465 = kk_string_box(_x_x1466); /*10037*/
    kk_box_t _x_x1468;
    kk_src_effects_prat__resonance__ganainfo _x_x1469;
    kk_string_t _x_x1470;
    kk_define_string_literal(, _s_x1471, 5, "North", _ctx)
    _x_x1470 = kk_string_dup(_s_x1471, _ctx); /*string*/
    kk_string_t _x_x1472;
    kk_define_string_literal(, _s_x1473, 7, "Nurture", _ctx)
    _x_x1472 = kk_string_dup(_s_x1473, _ctx); /*string*/
    kk_string_t _x_x1474;
    kk_define_string_literal(, _s_x1475, 6, "Wonder", _ctx)
    _x_x1474 = kk_string_dup(_s_x1475, _ctx); /*string*/
    kk_string_t _x_x1476;
    kk_define_string_literal(, _s_x1477, 3, "" "\xE5\xA5\xB3" "", _ctx)
    _x_x1476 = kk_string_dup(_s_x1477, _ctx); /*string*/
    kk_string_t _x_x1478;
    kk_define_string_literal(, _s_x1479, 2, "Nu", _ctx)
    _x_x1478 = kk_string_dup(_s_x1479, _ctx); /*string*/
    _x_x1469 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(24), _x_x1470, _x_x1472, _x_x1474, _x_x1476, _x_x1478, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1468 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1469, _ctx); /*10038*/
    _x_x1464 = kk_std_core_types__new_Tuple2(_x_x1465, _x_x1468, _ctx); /*(10037, 10038)*/
    _x_x1463 = kk_std_core_types__tuple2_box(_x_x1464, _ctx); /*10021*/
    kk_std_core_types__list _x_x1480;
    kk_box_t _x_x1481;
    kk_std_core_types__tuple2 _x_x1482;
    kk_box_t _x_x1483;
    kk_string_t _x_x1484;
    kk_define_string_literal(, _s_x1485, 9, "gana_void", _ctx)
    _x_x1484 = kk_string_dup(_s_x1485, _ctx); /*string*/
    _x_x1483 = kk_string_box(_x_x1484); /*10037*/
    kk_box_t _x_x1486;
    kk_src_effects_prat__resonance__ganainfo _x_x1487;
    kk_string_t _x_x1488;
    kk_define_string_literal(, _s_x1489, 5, "North", _ctx)
    _x_x1488 = kk_string_dup(_s_x1489, _ctx); /*string*/
    kk_string_t _x_x1490;
    kk_define_string_literal(, _s_x1491, 9, "Emptiness", _ctx)
    _x_x1490 = kk_string_dup(_s_x1491, _ctx); /*string*/
    kk_string_t _x_x1492;
    kk_define_string_literal(, _s_x1493, 9, "Stillness", _ctx)
    _x_x1492 = kk_string_dup(_s_x1493, _ctx); /*string*/
    kk_string_t _x_x1494;
    kk_define_string_literal(, _s_x1495, 3, "" "\xE8\x99\x9A" "", _ctx)
    _x_x1494 = kk_string_dup(_s_x1495, _ctx); /*string*/
    kk_string_t _x_x1496;
    kk_define_string_literal(, _s_x1497, 2, "Xu", _ctx)
    _x_x1496 = kk_string_dup(_s_x1497, _ctx); /*string*/
    _x_x1487 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(25), _x_x1488, _x_x1490, _x_x1492, _x_x1494, _x_x1496, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1486 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1487, _ctx); /*10038*/
    _x_x1482 = kk_std_core_types__new_Tuple2(_x_x1483, _x_x1486, _ctx); /*(10037, 10038)*/
    _x_x1481 = kk_std_core_types__tuple2_box(_x_x1482, _ctx); /*10021*/
    kk_std_core_types__list _x_x1498;
    kk_box_t _x_x1499;
    kk_std_core_types__tuple2 _x_x1500;
    kk_box_t _x_x1501;
    kk_string_t _x_x1502;
    kk_define_string_literal(, _s_x1503, 9, "gana_roof", _ctx)
    _x_x1502 = kk_string_dup(_s_x1503, _ctx); /*string*/
    _x_x1501 = kk_string_box(_x_x1502); /*10037*/
    kk_box_t _x_x1504;
    kk_src_effects_prat__resonance__ganainfo _x_x1505;
    kk_string_t _x_x1506;
    kk_define_string_literal(, _s_x1507, 5, "North", _ctx)
    _x_x1506 = kk_string_dup(_s_x1507, _ctx); /*string*/
    kk_string_t _x_x1508;
    kk_define_string_literal(, _s_x1509, 7, "Shelter", _ctx)
    _x_x1508 = kk_string_dup(_s_x1509, _ctx); /*string*/
    kk_string_t _x_x1510;
    kk_define_string_literal(, _s_x1511, 10, "Protection", _ctx)
    _x_x1510 = kk_string_dup(_s_x1511, _ctx); /*string*/
    kk_string_t _x_x1512;
    kk_define_string_literal(, _s_x1513, 3, "" "\xE5\x8D\xB1" "", _ctx)
    _x_x1512 = kk_string_dup(_s_x1513, _ctx); /*string*/
    kk_string_t _x_x1514;
    kk_define_string_literal(, _s_x1515, 3, "Wei", _ctx)
    _x_x1514 = kk_string_dup(_s_x1515, _ctx); /*string*/
    _x_x1505 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(26), _x_x1506, _x_x1508, _x_x1510, _x_x1512, _x_x1514, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1504 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1505, _ctx); /*10038*/
    _x_x1500 = kk_std_core_types__new_Tuple2(_x_x1501, _x_x1504, _ctx); /*(10037, 10038)*/
    _x_x1499 = kk_std_core_types__tuple2_box(_x_x1500, _ctx); /*10021*/
    kk_std_core_types__list _x_x1516;
    kk_box_t _x_x1517;
    kk_std_core_types__tuple2 _x_x1518;
    kk_box_t _x_x1519;
    kk_string_t _x_x1520;
    kk_define_string_literal(, _s_x1521, 15, "gana_encampment", _ctx)
    _x_x1520 = kk_string_dup(_s_x1521, _ctx); /*string*/
    _x_x1519 = kk_string_box(_x_x1520); /*10037*/
    kk_box_t _x_x1522;
    kk_src_effects_prat__resonance__ganainfo _x_x1523;
    kk_string_t _x_x1524;
    kk_define_string_literal(, _s_x1525, 5, "North", _ctx)
    _x_x1524 = kk_string_dup(_s_x1525, _ctx); /*string*/
    kk_string_t _x_x1526;
    kk_define_string_literal(, _s_x1527, 9, "Structure", _ctx)
    _x_x1526 = kk_string_dup(_s_x1527, _ctx); /*string*/
    kk_string_t _x_x1528;
    kk_define_string_literal(, _s_x1529, 6, "Sangha", _ctx)
    _x_x1528 = kk_string_dup(_s_x1529, _ctx); /*string*/
    kk_string_t _x_x1530;
    kk_define_string_literal(, _s_x1531, 3, "" "\xE5\xAE\xA4" "", _ctx)
    _x_x1530 = kk_string_dup(_s_x1531, _ctx); /*string*/
    kk_string_t _x_x1532;
    kk_define_string_literal(, _s_x1533, 3, "Shi", _ctx)
    _x_x1532 = kk_string_dup(_s_x1533, _ctx); /*string*/
    _x_x1523 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(27), _x_x1524, _x_x1526, _x_x1528, _x_x1530, _x_x1532, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1522 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1523, _ctx); /*10038*/
    _x_x1518 = kk_std_core_types__new_Tuple2(_x_x1519, _x_x1522, _ctx); /*(10037, 10038)*/
    _x_x1517 = kk_std_core_types__tuple2_box(_x_x1518, _ctx); /*10021*/
    kk_std_core_types__list _x_x1534;
    kk_box_t _x_x1535;
    kk_std_core_types__tuple2 _x_x1536;
    kk_box_t _x_x1537;
    kk_string_t _x_x1538;
    kk_define_string_literal(, _s_x1539, 9, "gana_wall", _ctx)
    _x_x1538 = kk_string_dup(_s_x1539, _ctx); /*string*/
    _x_x1537 = kk_string_box(_x_x1538); /*10037*/
    kk_box_t _x_x1540;
    kk_src_effects_prat__resonance__ganainfo _x_x1541;
    kk_string_t _x_x1542;
    kk_define_string_literal(, _s_x1543, 5, "North", _ctx)
    _x_x1542 = kk_string_dup(_s_x1543, _ctx); /*string*/
    kk_string_t _x_x1544;
    kk_define_string_literal(, _s_x1545, 10, "Boundaries", _ctx)
    _x_x1544 = kk_string_dup(_s_x1545, _ctx); /*string*/
    kk_string_t _x_x1546;
    kk_define_string_literal(, _s_x1547, 3, "Air", _ctx)
    _x_x1546 = kk_string_dup(_s_x1547, _ctx); /*string*/
    kk_string_t _x_x1548;
    kk_define_string_literal(, _s_x1549, 3, "" "\xE5\xA3\x81" "", _ctx)
    _x_x1548 = kk_string_dup(_s_x1549, _ctx); /*string*/
    kk_string_t _x_x1550;
    kk_define_string_literal(, _s_x1551, 2, "Bi", _ctx)
    _x_x1550 = kk_string_dup(_s_x1551, _ctx); /*string*/
    _x_x1541 = kk_src_effects_prat__resonance__new_Ganainfo(kk_reuse_null, 0, kk_integer_from_small(28), _x_x1542, _x_x1544, _x_x1546, _x_x1548, _x_x1550, _ctx); /*src/effects/prat_resonance/ganainfo*/
    _x_x1540 = kk_src_effects_prat__resonance__ganainfo_box(_x_x1541, _ctx); /*10038*/
    _x_x1536 = kk_std_core_types__new_Tuple2(_x_x1537, _x_x1540, _ctx); /*(10037, 10038)*/
    _x_x1535 = kk_std_core_types__tuple2_box(_x_x1536, _ctx); /*10021*/
    _x_x1534 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1535, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1516 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1517, _x_x1534, _ctx); /*list<10021>*/
    _x_x1498 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1499, _x_x1516, _ctx); /*list<10021>*/
    _x_x1480 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1481, _x_x1498, _ctx); /*list<10021>*/
    _x_x1462 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1463, _x_x1480, _ctx); /*list<10021>*/
    _x_x1444 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1445, _x_x1462, _ctx); /*list<10021>*/
    _x_x1426 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1427, _x_x1444, _ctx); /*list<10021>*/
    _x_x1408 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1409, _x_x1426, _ctx); /*list<10021>*/
    _x_x1390 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1391, _x_x1408, _ctx); /*list<10021>*/
    _x_x1372 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1373, _x_x1390, _ctx); /*list<10021>*/
    _x_x1354 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1355, _x_x1372, _ctx); /*list<10021>*/
    _x_x1336 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1337, _x_x1354, _ctx); /*list<10021>*/
    _x_x1318 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1319, _x_x1336, _ctx); /*list<10021>*/
    _x_x1300 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1301, _x_x1318, _ctx); /*list<10021>*/
    _x_x1282 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1283, _x_x1300, _ctx); /*list<10021>*/
    _x_x1264 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1265, _x_x1282, _ctx); /*list<10021>*/
    _x_x1246 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1247, _x_x1264, _ctx); /*list<10021>*/
    _x_x1228 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1229, _x_x1246, _ctx); /*list<10021>*/
    _x_x1210 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1211, _x_x1228, _ctx); /*list<10021>*/
    _x_x1192 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1193, _x_x1210, _ctx); /*list<10021>*/
    _x_x1174 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1175, _x_x1192, _ctx); /*list<10021>*/
    _x_x1156 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1157, _x_x1174, _ctx); /*list<10021>*/
    _x_x1138 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1139, _x_x1156, _ctx); /*list<10021>*/
    _x_x1120 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1121, _x_x1138, _ctx); /*list<10021>*/
    _x_x1102 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1103, _x_x1120, _ctx); /*list<10021>*/
    _x_x1084 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1085, _x_x1102, _ctx); /*list<10021>*/
    _x_x1066 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1067, _x_x1084, _ctx); /*list<10021>*/
    kk_src_effects_prat__resonance_gana_metadata = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1049, _x_x1066, _ctx); /*list<(string, src/effects/prat_resonance/ganainfo)>*/
  }
  {
    kk_box_t _x_x1552;
    kk_string_t _x_x1553;
    kk_define_string_literal(, _s_x1554, 9, "gana_horn", _ctx)
    _x_x1553 = kk_string_dup(_s_x1554, _ctx); /*string*/
    _x_x1552 = kk_string_box(_x_x1553); /*10021*/
    kk_std_core_types__list _x_x1555;
    kk_box_t _x_x1556;
    kk_string_t _x_x1557;
    kk_define_string_literal(, _s_x1558, 9, "gana_neck", _ctx)
    _x_x1557 = kk_string_dup(_s_x1558, _ctx); /*string*/
    _x_x1556 = kk_string_box(_x_x1557); /*10021*/
    kk_std_core_types__list _x_x1559;
    kk_box_t _x_x1560;
    kk_string_t _x_x1561;
    kk_define_string_literal(, _s_x1562, 9, "gana_root", _ctx)
    _x_x1561 = kk_string_dup(_s_x1562, _ctx); /*string*/
    _x_x1560 = kk_string_box(_x_x1561); /*10021*/
    kk_std_core_types__list _x_x1563;
    kk_box_t _x_x1564;
    kk_string_t _x_x1565;
    kk_define_string_literal(, _s_x1566, 9, "gana_room", _ctx)
    _x_x1565 = kk_string_dup(_s_x1566, _ctx); /*string*/
    _x_x1564 = kk_string_box(_x_x1565); /*10021*/
    kk_std_core_types__list _x_x1567;
    kk_box_t _x_x1568;
    kk_string_t _x_x1569;
    kk_define_string_literal(, _s_x1570, 10, "gana_heart", _ctx)
    _x_x1569 = kk_string_dup(_s_x1570, _ctx); /*string*/
    _x_x1568 = kk_string_box(_x_x1569); /*10021*/
    kk_std_core_types__list _x_x1571;
    kk_box_t _x_x1572;
    kk_string_t _x_x1573;
    kk_define_string_literal(, _s_x1574, 9, "gana_tail", _ctx)
    _x_x1573 = kk_string_dup(_s_x1574, _ctx); /*string*/
    _x_x1572 = kk_string_box(_x_x1573); /*10021*/
    kk_std_core_types__list _x_x1575;
    kk_box_t _x_x1576;
    kk_string_t _x_x1577;
    kk_define_string_literal(, _s_x1578, 21, "gana_winnowing_basket", _ctx)
    _x_x1577 = kk_string_dup(_s_x1578, _ctx); /*string*/
    _x_x1576 = kk_string_box(_x_x1577); /*10021*/
    kk_std_core_types__list _x_x1579;
    kk_box_t _x_x1580;
    kk_string_t _x_x1581;
    kk_define_string_literal(, _s_x1582, 10, "gana_ghost", _ctx)
    _x_x1581 = kk_string_dup(_s_x1582, _ctx); /*string*/
    _x_x1580 = kk_string_box(_x_x1581); /*10021*/
    kk_std_core_types__list _x_x1583;
    kk_box_t _x_x1584;
    kk_string_t _x_x1585;
    kk_define_string_literal(, _s_x1586, 11, "gana_willow", _ctx)
    _x_x1585 = kk_string_dup(_s_x1586, _ctx); /*string*/
    _x_x1584 = kk_string_box(_x_x1585); /*10021*/
    kk_std_core_types__list _x_x1587;
    kk_box_t _x_x1588;
    kk_string_t _x_x1589;
    kk_define_string_literal(, _s_x1590, 9, "gana_star", _ctx)
    _x_x1589 = kk_string_dup(_s_x1590, _ctx); /*string*/
    _x_x1588 = kk_string_box(_x_x1589); /*10021*/
    kk_std_core_types__list _x_x1591;
    kk_box_t _x_x1592;
    kk_string_t _x_x1593;
    kk_define_string_literal(, _s_x1594, 17, "gana_extended_net", _ctx)
    _x_x1593 = kk_string_dup(_s_x1594, _ctx); /*string*/
    _x_x1592 = kk_string_box(_x_x1593); /*10021*/
    kk_std_core_types__list _x_x1595;
    kk_box_t _x_x1596;
    kk_string_t _x_x1597;
    kk_define_string_literal(, _s_x1598, 10, "gana_wings", _ctx)
    _x_x1597 = kk_string_dup(_s_x1598, _ctx); /*string*/
    _x_x1596 = kk_string_box(_x_x1597); /*10021*/
    kk_std_core_types__list _x_x1599;
    kk_box_t _x_x1600;
    kk_string_t _x_x1601;
    kk_define_string_literal(, _s_x1602, 12, "gana_chariot", _ctx)
    _x_x1601 = kk_string_dup(_s_x1602, _ctx); /*string*/
    _x_x1600 = kk_string_box(_x_x1601); /*10021*/
    kk_std_core_types__list _x_x1603;
    kk_box_t _x_x1604;
    kk_string_t _x_x1605;
    kk_define_string_literal(, _s_x1606, 14, "gana_abundance", _ctx)
    _x_x1605 = kk_string_dup(_s_x1606, _ctx); /*string*/
    _x_x1604 = kk_string_box(_x_x1605); /*10021*/
    kk_std_core_types__list _x_x1607;
    kk_box_t _x_x1608;
    kk_string_t _x_x1609;
    kk_define_string_literal(, _s_x1610, 20, "gana_straddling_legs", _ctx)
    _x_x1609 = kk_string_dup(_s_x1610, _ctx); /*string*/
    _x_x1608 = kk_string_box(_x_x1609); /*10021*/
    kk_std_core_types__list _x_x1611;
    kk_box_t _x_x1612;
    kk_string_t _x_x1613;
    kk_define_string_literal(, _s_x1614, 10, "gana_mound", _ctx)
    _x_x1613 = kk_string_dup(_s_x1614, _ctx); /*string*/
    _x_x1612 = kk_string_box(_x_x1613); /*10021*/
    kk_std_core_types__list _x_x1615;
    kk_box_t _x_x1616;
    kk_string_t _x_x1617;
    kk_define_string_literal(, _s_x1618, 12, "gana_stomach", _ctx)
    _x_x1617 = kk_string_dup(_s_x1618, _ctx); /*string*/
    _x_x1616 = kk_string_box(_x_x1617); /*10021*/
    kk_std_core_types__list _x_x1619;
    kk_box_t _x_x1620;
    kk_string_t _x_x1621;
    kk_define_string_literal(, _s_x1622, 15, "gana_hairy_head", _ctx)
    _x_x1621 = kk_string_dup(_s_x1622, _ctx); /*string*/
    _x_x1620 = kk_string_box(_x_x1621); /*10021*/
    kk_std_core_types__list _x_x1623;
    kk_box_t _x_x1624;
    kk_string_t _x_x1625;
    kk_define_string_literal(, _s_x1626, 8, "gana_net", _ctx)
    _x_x1625 = kk_string_dup(_s_x1626, _ctx); /*string*/
    _x_x1624 = kk_string_box(_x_x1625); /*10021*/
    kk_std_core_types__list _x_x1627;
    kk_box_t _x_x1628;
    kk_string_t _x_x1629;
    kk_define_string_literal(, _s_x1630, 16, "gana_turtle_beak", _ctx)
    _x_x1629 = kk_string_dup(_s_x1630, _ctx); /*string*/
    _x_x1628 = kk_string_box(_x_x1629); /*10021*/
    kk_std_core_types__list _x_x1631;
    kk_box_t _x_x1632;
    kk_string_t _x_x1633;
    kk_define_string_literal(, _s_x1634, 16, "gana_three_stars", _ctx)
    _x_x1633 = kk_string_dup(_s_x1634, _ctx); /*string*/
    _x_x1632 = kk_string_box(_x_x1633); /*10021*/
    kk_std_core_types__list _x_x1635;
    kk_box_t _x_x1636;
    kk_string_t _x_x1637;
    kk_define_string_literal(, _s_x1638, 11, "gana_dipper", _ctx)
    _x_x1637 = kk_string_dup(_s_x1638, _ctx); /*string*/
    _x_x1636 = kk_string_box(_x_x1637); /*10021*/
    kk_std_core_types__list _x_x1639;
    kk_box_t _x_x1640;
    kk_string_t _x_x1641;
    kk_define_string_literal(, _s_x1642, 7, "gana_ox", _ctx)
    _x_x1641 = kk_string_dup(_s_x1642, _ctx); /*string*/
    _x_x1640 = kk_string_box(_x_x1641); /*10021*/
    kk_std_core_types__list _x_x1643;
    kk_box_t _x_x1644;
    kk_string_t _x_x1645;
    kk_define_string_literal(, _s_x1646, 9, "gana_girl", _ctx)
    _x_x1645 = kk_string_dup(_s_x1646, _ctx); /*string*/
    _x_x1644 = kk_string_box(_x_x1645); /*10021*/
    kk_std_core_types__list _x_x1647;
    kk_box_t _x_x1648;
    kk_string_t _x_x1649;
    kk_define_string_literal(, _s_x1650, 9, "gana_void", _ctx)
    _x_x1649 = kk_string_dup(_s_x1650, _ctx); /*string*/
    _x_x1648 = kk_string_box(_x_x1649); /*10021*/
    kk_std_core_types__list _x_x1651;
    kk_box_t _x_x1652;
    kk_string_t _x_x1653;
    kk_define_string_literal(, _s_x1654, 9, "gana_roof", _ctx)
    _x_x1653 = kk_string_dup(_s_x1654, _ctx); /*string*/
    _x_x1652 = kk_string_box(_x_x1653); /*10021*/
    kk_std_core_types__list _x_x1655;
    kk_box_t _x_x1656;
    kk_string_t _x_x1657;
    kk_define_string_literal(, _s_x1658, 15, "gana_encampment", _ctx)
    _x_x1657 = kk_string_dup(_s_x1658, _ctx); /*string*/
    _x_x1656 = kk_string_box(_x_x1657); /*10021*/
    kk_std_core_types__list _x_x1659;
    kk_box_t _x_x1660;
    kk_string_t _x_x1661;
    kk_define_string_literal(, _s_x1662, 9, "gana_wall", _ctx)
    _x_x1661 = kk_string_dup(_s_x1662, _ctx); /*string*/
    _x_x1660 = kk_string_box(_x_x1661); /*10021*/
    _x_x1659 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1660, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1655 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1656, _x_x1659, _ctx); /*list<10021>*/
    _x_x1651 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1652, _x_x1655, _ctx); /*list<10021>*/
    _x_x1647 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1648, _x_x1651, _ctx); /*list<10021>*/
    _x_x1643 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1644, _x_x1647, _ctx); /*list<10021>*/
    _x_x1639 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1640, _x_x1643, _ctx); /*list<10021>*/
    _x_x1635 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1636, _x_x1639, _ctx); /*list<10021>*/
    _x_x1631 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1632, _x_x1635, _ctx); /*list<10021>*/
    _x_x1627 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1628, _x_x1631, _ctx); /*list<10021>*/
    _x_x1623 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1624, _x_x1627, _ctx); /*list<10021>*/
    _x_x1619 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1620, _x_x1623, _ctx); /*list<10021>*/
    _x_x1615 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1616, _x_x1619, _ctx); /*list<10021>*/
    _x_x1611 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1612, _x_x1615, _ctx); /*list<10021>*/
    _x_x1607 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1608, _x_x1611, _ctx); /*list<10021>*/
    _x_x1603 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1604, _x_x1607, _ctx); /*list<10021>*/
    _x_x1599 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1600, _x_x1603, _ctx); /*list<10021>*/
    _x_x1595 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1596, _x_x1599, _ctx); /*list<10021>*/
    _x_x1591 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1592, _x_x1595, _ctx); /*list<10021>*/
    _x_x1587 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1588, _x_x1591, _ctx); /*list<10021>*/
    _x_x1583 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1584, _x_x1587, _ctx); /*list<10021>*/
    _x_x1579 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1580, _x_x1583, _ctx); /*list<10021>*/
    _x_x1575 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1576, _x_x1579, _ctx); /*list<10021>*/
    _x_x1571 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1572, _x_x1575, _ctx); /*list<10021>*/
    _x_x1567 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1568, _x_x1571, _ctx); /*list<10021>*/
    _x_x1563 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1564, _x_x1567, _ctx); /*list<10021>*/
    _x_x1559 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1560, _x_x1563, _ctx); /*list<10021>*/
    _x_x1555 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1556, _x_x1559, _ctx); /*list<10021>*/
    kk_src_effects_prat__resonance_gana_order = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1552, _x_x1555, _ctx); /*list<string>*/
  }
}

// termination
void kk_src_effects_prat__resonance__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_types__list_drop(kk_src_effects_prat__resonance_gana_order, _ctx);
  kk_std_core_types__list_drop(kk_src_effects_prat__resonance_gana_metadata, _ctx);
  kk_std_core_hnd__htag_drop(kk_src_effects_prat__resonance_resonance_fs__tag, _ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_core_vector__done(_ctx);
  kk_std_num_random__done(_ctx);
  kk_std_time__done(_ctx);
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
  kk_std_core_int__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_order__done(_ctx);
  kk_std_core_bool__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
