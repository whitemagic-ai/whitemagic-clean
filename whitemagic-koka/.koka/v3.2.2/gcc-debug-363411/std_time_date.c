// Koka generated module: std/time/date, koka version: 3.2.2, platform: 64-bit
#include "std_time_date.h"

kk_std_time_date__date kk_std_time_date_date_fs__copy(kk_std_time_date__date _this, kk_std_core_types__optional year, kk_std_core_types__optional month, kk_std_core_types__optional day, kk_context_t* _ctx) { /* (date, year : ? int, month : ? int, day : ? int) -> date */ 
  kk_integer_t _x_x172;
  if (kk_std_core_types__is_Optional(year, _ctx)) {
    kk_box_t _box_x0 = year._cons._Optional.value;
    kk_integer_t _uniq_year_102 = kk_integer_unbox(_box_x0, _ctx);
    kk_integer_dup(_uniq_year_102, _ctx);
    kk_std_core_types__optional_drop(year, _ctx);
    _x_x172 = _uniq_year_102; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(year, _ctx);
    {
      kk_integer_t _x = _this.year;
      kk_integer_dup(_x, _ctx);
      _x_x172 = _x; /*int*/
    }
  }
  kk_integer_t _x_x173;
  if (kk_std_core_types__is_Optional(month, _ctx)) {
    kk_box_t _box_x1 = month._cons._Optional.value;
    kk_integer_t _uniq_month_110 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_month_110, _ctx);
    kk_std_core_types__optional_drop(month, _ctx);
    _x_x173 = _uniq_month_110; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(month, _ctx);
    {
      kk_integer_t _x_0 = _this.month;
      kk_integer_dup(_x_0, _ctx);
      _x_x173 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x174;
  if (kk_std_core_types__is_Optional(day, _ctx)) {
    kk_box_t _box_x2 = day._cons._Optional.value;
    kk_integer_t _uniq_day_118 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_day_118, _ctx);
    kk_std_core_types__optional_drop(day, _ctx);
    kk_std_time_date__date_drop(_this, _ctx);
    _x_x174 = _uniq_day_118; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(day, _ctx);
    {
      kk_integer_t _x_1 = _this.day;
      kk_integer_dup(_x_1, _ctx);
      kk_std_time_date__date_drop(_this, _ctx);
      _x_x174 = _x_1; /*int*/
    }
  }
  return kk_std_time_date__new_Date(_x_x172, _x_x173, _x_x174, _ctx);
}
 
// Convert a `:weekday` to an `:int` using the ISO definition which starts at Monday as 1,
// up to Sunday as 7.

kk_integer_t kk_std_time_date_int(kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (wd : weekday) -> int */ 
  if (kk_std_time_date__is_Mon(wd, _ctx)) {
    return kk_integer_from_small(1);
  }
  if (kk_std_time_date__is_Tue(wd, _ctx)) {
    return kk_integer_from_small(2);
  }
  if (kk_std_time_date__is_Wed(wd, _ctx)) {
    return kk_integer_from_small(3);
  }
  if (kk_std_time_date__is_Thu(wd, _ctx)) {
    return kk_integer_from_small(4);
  }
  if (kk_std_time_date__is_Fri(wd, _ctx)) {
    return kk_integer_from_small(5);
  }
  if (kk_std_time_date__is_Sat(wd, _ctx)) {
    return kk_integer_from_small(6);
  }
  {
    return kk_integer_from_small(7);
  }
}
 
// Add two dates field-wise together.

kk_std_time_date__date kk_std_time_date__lp__plus__rp_(kk_std_time_date__date d1, kk_std_time_date__date d2, kk_context_t* _ctx) { /* (d1 : date, d2 : date) -> date */ 
  kk_integer_t _x_x179;
  kk_integer_t _x_x180;
  {
    kk_integer_t _x = d1.year;
    kk_integer_dup(_x, _ctx);
    _x_x180 = _x; /*int*/
  }
  kk_integer_t _x_x181;
  {
    kk_integer_t _x_0 = d2.year;
    kk_integer_dup(_x_0, _ctx);
    _x_x181 = _x_0; /*int*/
  }
  _x_x179 = kk_integer_add(_x_x180,_x_x181,kk_context()); /*int*/
  kk_integer_t _x_x182;
  kk_integer_t _x_x183;
  {
    kk_integer_t _x_1 = d1.month;
    kk_integer_dup(_x_1, _ctx);
    _x_x183 = _x_1; /*int*/
  }
  kk_integer_t _x_x184;
  {
    kk_integer_t _x_2 = d2.month;
    kk_integer_dup(_x_2, _ctx);
    _x_x184 = _x_2; /*int*/
  }
  _x_x182 = kk_integer_add(_x_x183,_x_x184,kk_context()); /*int*/
  kk_integer_t _x_x185;
  kk_integer_t _x_x186;
  {
    kk_integer_t _x_3 = d1.day;
    kk_integer_dup(_x_3, _ctx);
    kk_std_time_date__date_drop(d1, _ctx);
    _x_x186 = _x_3; /*int*/
  }
  kk_integer_t _x_x187;
  {
    kk_integer_t _x_4 = d2.day;
    kk_integer_dup(_x_4, _ctx);
    kk_std_time_date__date_drop(d2, _ctx);
    _x_x187 = _x_4; /*int*/
  }
  _x_x185 = kk_integer_add(_x_x186,_x_x187,kk_context()); /*int*/
  return kk_std_time_date__new_Date(_x_x179, _x_x182, _x_x185, _ctx);
}
 
// Add two clock together.

kk_std_time_date__clock kk_std_time_date_clock_fs__lp__plus__rp_(kk_std_time_date__clock c, kk_std_time_date__clock d, kk_context_t* _ctx) { /* (c : clock, d : clock) -> clock */ 
  kk_integer_t _x_x188;
  kk_integer_t _x_x189;
  {
    struct kk_std_time_date_Clock* _con_x190 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1 = _con_x190->seconds;
    kk_integer_t _x = _con_x190->hours;
    kk_integer_dup(_x, _ctx);
    _x_x189 = _x; /*int*/
  }
  kk_integer_t _x_x191;
  {
    struct kk_std_time_date_Clock* _con_x192 = kk_std_time_date__as_Clock(d, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_0 = _con_x192->seconds;
    kk_integer_t _x_0 = _con_x192->hours;
    kk_integer_dup(_x_0, _ctx);
    _x_x191 = _x_0; /*int*/
  }
  _x_x188 = kk_integer_add(_x_x189,_x_x191,kk_context()); /*int*/
  kk_integer_t _x_x193;
  kk_integer_t _x_x194;
  {
    struct kk_std_time_date_Clock* _con_x195 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_1 = _con_x195->seconds;
    kk_integer_t _x_1 = _con_x195->minutes;
    kk_integer_dup(_x_1, _ctx);
    _x_x194 = _x_1; /*int*/
  }
  kk_integer_t _x_x196;
  {
    struct kk_std_time_date_Clock* _con_x197 = kk_std_time_date__as_Clock(d, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_2 = _con_x197->seconds;
    kk_integer_t _x_2 = _con_x197->minutes;
    kk_integer_dup(_x_2, _ctx);
    _x_x196 = _x_2; /*int*/
  }
  _x_x193 = kk_integer_add(_x_x194,_x_x196,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x198;
  kk_std_num_ddouble__ddouble _x_x199;
  {
    struct kk_std_time_date_Clock* _con_x200 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_3 = _con_x200->seconds;
    kk_integer_t _pat_0_3 = _con_x200->hours;
    kk_integer_t _pat_1_3 = _con_x200->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_3, _ctx);
      kk_integer_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x199 = _x_3; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x201;
  {
    struct kk_std_time_date_Clock* _con_x202 = kk_std_time_date__as_Clock(d, _ctx);
    kk_std_num_ddouble__ddouble _x_4 = _con_x202->seconds;
    kk_integer_t _pat_0_4 = _con_x202->hours;
    kk_integer_t _pat_1_4 = _con_x202->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(d, _ctx)) {
      kk_integer_drop(_pat_1_4, _ctx);
      kk_integer_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(d, _ctx);
    }
    else {
      kk_datatype_ptr_decref(d, _ctx);
    }
    _x_x201 = _x_4; /*std/num/ddouble/ddouble*/
  }
  _x_x198 = kk_std_num_ddouble__lp__plus__rp_(_x_x199, _x_x201, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x188, _x_x193, _x_x198, _ctx);
}
 
// Convert a weekday number to a `:weekday`(starting at Monday (=1) up to Sunday (=7)).
// Takes the integer `i - 1` modulo 7, so `0` or `14` also become Sunday etc.

kk_std_time_date__weekday kk_std_time_date_weekday(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> weekday */ 
  kk_integer_t d;
  kk_integer_t _x_x203 = kk_integer_add_small_const(i, -1, _ctx); /*int*/
  d = kk_integer_mod(_x_x203,(kk_integer_from_small(7)),kk_context()); /*int*/
  bool _match_x151 = kk_integer_eq_borrow(d,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x151) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Mon(_ctx);
  }
  {
    bool _match_x152 = kk_integer_eq_borrow(d,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x152) {
      kk_integer_drop(d, _ctx);
      return kk_std_time_date__new_Tue(_ctx);
    }
    {
      bool _match_x153 = kk_integer_eq_borrow(d,(kk_integer_from_small(2)),kk_context()); /*bool*/;
      if (_match_x153) {
        kk_integer_drop(d, _ctx);
        return kk_std_time_date__new_Wed(_ctx);
      }
      {
        bool _match_x154 = kk_integer_eq_borrow(d,(kk_integer_from_small(3)),kk_context()); /*bool*/;
        if (_match_x154) {
          kk_integer_drop(d, _ctx);
          return kk_std_time_date__new_Thu(_ctx);
        }
        {
          bool _match_x155 = kk_integer_eq_borrow(d,(kk_integer_from_small(4)),kk_context()); /*bool*/;
          if (_match_x155) {
            kk_integer_drop(d, _ctx);
            return kk_std_time_date__new_Fri(_ctx);
          }
          {
            bool _match_x156;
            bool _brw_x157 = kk_integer_eq_borrow(d,(kk_integer_from_small(5)),kk_context()); /*bool*/;
            kk_integer_drop(d, _ctx);
            _match_x156 = _brw_x157; /*bool*/
            if (_match_x156) {
              return kk_std_time_date__new_Sat(_ctx);
            }
            {
              return kk_std_time_date__new_Sun(_ctx);
            }
          }
        }
      }
    }
  }
}
 
// Compare two dates by fields.

kk_std_core_types__order kk_std_time_date_cmp(kk_std_time_date__date d, kk_std_time_date__date e, kk_context_t* _ctx) { /* (d : date, e : date) -> order */ 
  bool _match_x127;
  kk_integer_t _brw_x149;
  {
    kk_integer_t _x = d.year;
    kk_integer_dup(_x, _ctx);
    _brw_x149 = _x; /*int*/
  }
  kk_integer_t _brw_x148;
  {
    kk_integer_t _x_0 = e.year;
    kk_integer_dup(_x_0, _ctx);
    _brw_x148 = _x_0; /*int*/
  }
  bool _brw_x150 = kk_integer_eq_borrow(_brw_x149,_brw_x148,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x149, _ctx);
  kk_integer_drop(_brw_x148, _ctx);
  _match_x127 = _brw_x150; /*bool*/
  if (_match_x127) {
    bool _match_x132;
    kk_integer_t _brw_x146;
    {
      kk_integer_t _x_1 = d.month;
      kk_integer_dup(_x_1, _ctx);
      _brw_x146 = _x_1; /*int*/
    }
    kk_integer_t _brw_x145;
    {
      kk_integer_t _x_2 = e.month;
      kk_integer_dup(_x_2, _ctx);
      _brw_x145 = _x_2; /*int*/
    }
    bool _brw_x147 = kk_integer_eq_borrow(_brw_x146,_brw_x145,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x146, _ctx);
    kk_integer_drop(_brw_x145, _ctx);
    _match_x132 = _brw_x147; /*bool*/
    if (_match_x132) {
      bool _match_x137;
      kk_integer_t _brw_x143;
      {
        kk_integer_t _x_3 = d.day;
        kk_integer_dup(_x_3, _ctx);
        _brw_x143 = _x_3; /*int*/
      }
      kk_integer_t _brw_x142;
      {
        kk_integer_t _x_4 = e.day;
        kk_integer_dup(_x_4, _ctx);
        _brw_x142 = _x_4; /*int*/
      }
      bool _brw_x144 = kk_integer_eq_borrow(_brw_x143,_brw_x142,kk_context()); /*bool*/;
      kk_integer_drop(_brw_x143, _ctx);
      kk_integer_drop(_brw_x142, _ctx);
      _match_x137 = _brw_x144; /*bool*/
      if (_match_x137) {
        kk_std_time_date__date_drop(e, _ctx);
        kk_std_time_date__date_drop(d, _ctx);
        return kk_std_core_types__new_Eq(_ctx);
      }
      {
        bool _match_x138;
        kk_integer_t _brw_x140;
        {
          kk_integer_t _x_3_0 = d.day;
          kk_integer_dup(_x_3_0, _ctx);
          kk_std_time_date__date_drop(d, _ctx);
          _brw_x140 = _x_3_0; /*int*/
        }
        kk_integer_t _brw_x139;
        {
          kk_integer_t _x_4_0 = e.day;
          kk_integer_dup(_x_4_0, _ctx);
          kk_std_time_date__date_drop(e, _ctx);
          _brw_x139 = _x_4_0; /*int*/
        }
        bool _brw_x141 = kk_integer_gt_borrow(_brw_x140,_brw_x139,kk_context()); /*bool*/;
        kk_integer_drop(_brw_x140, _ctx);
        kk_integer_drop(_brw_x139, _ctx);
        _match_x138 = _brw_x141; /*bool*/
        if (_match_x138) {
          return kk_std_core_types__new_Gt(_ctx);
        }
        {
          return kk_std_core_types__new_Lt(_ctx);
        }
      }
    }
    {
      bool _match_x133;
      kk_integer_t _brw_x135;
      {
        kk_integer_t _x_1_0 = d.month;
        kk_integer_dup(_x_1_0, _ctx);
        kk_std_time_date__date_drop(d, _ctx);
        _brw_x135 = _x_1_0; /*int*/
      }
      kk_integer_t _brw_x134;
      {
        kk_integer_t _x_2_0 = e.month;
        kk_integer_dup(_x_2_0, _ctx);
        kk_std_time_date__date_drop(e, _ctx);
        _brw_x134 = _x_2_0; /*int*/
      }
      bool _brw_x136 = kk_integer_gt_borrow(_brw_x135,_brw_x134,kk_context()); /*bool*/;
      kk_integer_drop(_brw_x135, _ctx);
      kk_integer_drop(_brw_x134, _ctx);
      _match_x133 = _brw_x136; /*bool*/
      if (_match_x133) {
        return kk_std_core_types__new_Gt(_ctx);
      }
      {
        return kk_std_core_types__new_Lt(_ctx);
      }
    }
  }
  {
    bool _match_x128;
    kk_integer_t _brw_x130;
    {
      kk_integer_t _x_5 = d.year;
      kk_integer_dup(_x_5, _ctx);
      kk_std_time_date__date_drop(d, _ctx);
      _brw_x130 = _x_5; /*int*/
    }
    kk_integer_t _brw_x129;
    {
      kk_integer_t _x_0_0 = e.year;
      kk_integer_dup(_x_0_0, _ctx);
      kk_std_time_date__date_drop(e, _ctx);
      _brw_x129 = _x_0_0; /*int*/
    }
    bool _brw_x131 = kk_integer_gt_borrow(_brw_x130,_brw_x129,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x130, _ctx);
    kk_integer_drop(_brw_x129, _ctx);
    _match_x128 = _brw_x131; /*bool*/
    if (_match_x128) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// Return the total seconds of a `:clock` assuming 60 seconds per
// minute and 60 minutes per hour.

kk_std_num_ddouble__ddouble kk_std_time_date_total_seconds(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> std/num/ddouble/ddouble */ 
  kk_integer_t x_10046;
  kk_integer_t _x_x208;
  {
    struct kk_std_time_date_Clock* _con_x209 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1 = _con_x209->seconds;
    kk_integer_t _x = _con_x209->hours;
    kk_integer_dup(_x, _ctx);
    _x_x208 = _x; /*int*/
  }
  x_10046 = kk_integer_mul(_x_x208,(kk_integer_from_small(60)),kk_context()); /*int*/
  kk_integer_t i_10045;
  kk_integer_t _x_x210;
  kk_integer_t _x_x211;
  {
    struct kk_std_time_date_Clock* _con_x212 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_0 = _con_x212->seconds;
    kk_integer_t _x_0 = _con_x212->minutes;
    kk_integer_dup(_x_0, _ctx);
    _x_x211 = _x_0; /*int*/
  }
  _x_x210 = kk_integer_add(x_10046,_x_x211,kk_context()); /*int*/
  i_10045 = kk_integer_mul(_x_x210,(kk_integer_from_small(60)),kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x213 = kk_std_num_ddouble_ddouble_int_exp(i_10045, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x214;
  {
    struct kk_std_time_date_Clock* _con_x215 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x215->seconds;
    kk_integer_t _pat_0_1 = _con_x215->hours;
    kk_integer_t _pat_1_1 = _con_x215->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_1, _ctx);
      kk_integer_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x214 = _x_1; /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__lp__plus__rp_(_x_x213, _x_x214, _ctx);
}
 
// Compare weekdays.

kk_std_core_types__order kk_std_time_date_weekday_fs_cmp(kk_std_time_date__weekday wd1, kk_std_time_date__weekday wd2, kk_context_t* _ctx) { /* (wd1 : weekday, wd2 : weekday) -> order */ 
  kk_integer_t x_10053 = kk_std_time_date_int(wd1, _ctx); /*int*/;
  kk_integer_t y_10054 = kk_std_time_date_int(wd2, _ctx); /*int*/;
  bool _match_x123 = kk_integer_eq_borrow(x_10053,y_10054,kk_context()); /*bool*/;
  if (_match_x123) {
    kk_integer_drop(y_10054, _ctx);
    kk_integer_drop(x_10053, _ctx);
    return kk_std_core_types__new_Eq(_ctx);
  }
  {
    bool _match_x124;
    bool _brw_x125 = kk_integer_gt_borrow(x_10053,y_10054,kk_context()); /*bool*/;
    kk_integer_drop(x_10053, _ctx);
    kk_integer_drop(y_10054, _ctx);
    _match_x124 = _brw_x125; /*bool*/
    if (_match_x124) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}

kk_std_time_date__clock kk_std_time_date_clock_fs__copy(kk_std_time_date__clock _this, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional seconds, kk_context_t* _ctx) { /* (clock, hours : ? int, minutes : ? int, seconds : ? std/num/ddouble/ddouble) -> clock */ 
  kk_integer_t _x_x229;
  if (kk_std_core_types__is_Optional(hours, _ctx)) {
    kk_box_t _box_x3 = hours._cons._Optional.value;
    kk_integer_t _uniq_hours_2877 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_hours_2877, _ctx);
    kk_std_core_types__optional_drop(hours, _ctx);
    _x_x229 = _uniq_hours_2877; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hours, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x230 = kk_std_time_date__as_Clock(_this, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_0 = _con_x230->seconds;
      kk_integer_t _x = _con_x230->hours;
      kk_integer_dup(_x, _ctx);
      _x_x229 = _x; /*int*/
    }
  }
  kk_integer_t _x_x231;
  if (kk_std_core_types__is_Optional(minutes, _ctx)) {
    kk_box_t _box_x4 = minutes._cons._Optional.value;
    kk_integer_t _uniq_minutes_2885 = kk_integer_unbox(_box_x4, _ctx);
    kk_integer_dup(_uniq_minutes_2885, _ctx);
    kk_std_core_types__optional_drop(minutes, _ctx);
    _x_x231 = _uniq_minutes_2885; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(minutes, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x232 = kk_std_time_date__as_Clock(_this, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_2 = _con_x232->seconds;
      kk_integer_t _x_0 = _con_x232->minutes;
      kk_integer_dup(_x_0, _ctx);
      _x_x231 = _x_0; /*int*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x233;
  if (kk_std_core_types__is_Optional(seconds, _ctx)) {
    kk_box_t _box_x5 = seconds._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_seconds_2893 = kk_std_num_ddouble__ddouble_unbox(_box_x5, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(seconds, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x233 = _uniq_seconds_2893; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_core_types__optional_drop(seconds, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x234 = kk_std_time_date__as_Clock(_this, _ctx);
      kk_std_num_ddouble__ddouble _x_1 = _con_x234->seconds;
      kk_integer_t _pat_0_2 = _con_x234->hours;
      kk_integer_t _pat_1_3 = _con_x234->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_3, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x233 = _x_1; /*std/num/ddouble/ddouble*/
    }
  }
  return kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x229, _x_x231, _x_x233, _ctx);
}
 
// Create a clock from a seconds as an `:int` with an optional fraction.
// Normalizes the clock with seconds and minutes under 60 but
// adds the fraction as is to the final seconds, so that might
// be `>= 60` if the fraction `>= 1.0`;

kk_std_time_date__clock kk_std_time_date_intddouble_fs_clock(kk_integer_t seconds, kk_std_core_types__optional frac, kk_context_t* _ctx) { /* (seconds : int, frac : ? std/num/ddouble/ddouble) -> clock */ 
  kk_std_core_types__tuple2 _match_x121 = kk_std_core_int_divmod(seconds, kk_integer_from_small(60), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x6 = _match_x121.fst;
    kk_box_t _box_x7 = _match_x121.snd;
    kk_integer_t hm = kk_integer_unbox(_box_x6, _ctx);
    kk_integer_t s = kk_integer_unbox(_box_x7, _ctx);
    kk_integer_dup(hm, _ctx);
    kk_integer_dup(s, _ctx);
    kk_std_core_types__tuple2_drop(_match_x121, _ctx);
    kk_std_core_types__tuple2 _match_x122 = kk_std_core_int_divmod(hm, kk_integer_from_small(60), _ctx); /*(int, int)*/;
    {
      kk_box_t _box_x8 = _match_x122.fst;
      kk_box_t _box_x9 = _match_x122.snd;
      kk_integer_t h = kk_integer_unbox(_box_x8, _ctx);
      kk_integer_t m = kk_integer_unbox(_box_x9, _ctx);
      kk_integer_dup(h, _ctx);
      kk_integer_dup(m, _ctx);
      kk_std_core_types__tuple2_drop(_match_x122, _ctx);
      kk_std_num_ddouble__ddouble _x_x235;
      kk_std_num_ddouble__ddouble _x_x236 = kk_std_num_ddouble_ddouble_int_exp(s, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x237;
      if (kk_std_core_types__is_Optional(frac, _ctx)) {
        kk_box_t _box_x10 = frac._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_frac_2907 = kk_std_num_ddouble__ddouble_unbox(_box_x10, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(frac, _ctx);
        _x_x237 = _uniq_frac_2907; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_core_types__optional_drop(frac, _ctx);
        _x_x237 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
      }
      _x_x235 = kk_std_num_ddouble__lp__plus__rp_(_x_x236, _x_x237, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_time_date__new_Clock(kk_reuse_null, 0, h, m, _x_x235, _ctx);
    }
  }
}
 
// Create a clock from seconds; normalizes the clock with seconds and minutes under 60.

kk_std_time_date__clock kk_std_time_date_ddouble_fs_clock(kk_std_num_ddouble__ddouble seconds, kk_context_t* _ctx) { /* (seconds : std/num/ddouble/ddouble) -> clock */ 
  kk_integer_t seconds_0_10059;
  kk_std_num_ddouble__ddouble _x_x238 = kk_std_num_ddouble_floor(seconds, _ctx); /*std/num/ddouble/ddouble*/
  seconds_0_10059 = kk_std_num_ddouble_int(_x_x238, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_std_num_ddouble__ddouble _b_x11_12 = kk_std_num_ddouble_ffraction(seconds, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_core_types__tuple2 _match_x118 = kk_std_core_int_divmod(seconds_0_10059, kk_integer_from_small(60), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x13 = _match_x118.fst;
    kk_box_t _box_x14 = _match_x118.snd;
    kk_integer_t hm = kk_integer_unbox(_box_x13, _ctx);
    kk_integer_t s = kk_integer_unbox(_box_x14, _ctx);
    kk_integer_dup(hm, _ctx);
    kk_integer_dup(s, _ctx);
    kk_std_core_types__tuple2_drop(_match_x118, _ctx);
    kk_std_core_types__tuple2 _match_x119 = kk_std_core_int_divmod(hm, kk_integer_from_small(60), _ctx); /*(int, int)*/;
    {
      kk_box_t _box_x15 = _match_x119.fst;
      kk_box_t _box_x16 = _match_x119.snd;
      kk_integer_t h = kk_integer_unbox(_box_x15, _ctx);
      kk_integer_t m = kk_integer_unbox(_box_x16, _ctx);
      kk_integer_dup(h, _ctx);
      kk_integer_dup(m, _ctx);
      kk_std_core_types__tuple2_drop(_match_x119, _ctx);
      kk_std_num_ddouble__ddouble _x_x239;
      kk_std_num_ddouble__ddouble _x_x240 = kk_std_num_ddouble_ddouble_int_exp(s, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x241;
      kk_std_core_types__optional _match_x120 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(_b_x11_12, _ctx), _ctx); /*? 0*/;
      if (kk_std_core_types__is_Optional(_match_x120, _ctx)) {
        kk_box_t _box_x17 = _match_x120._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_frac_2907 = kk_std_num_ddouble__ddouble_unbox(_box_x17, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x120, _ctx);
        _x_x241 = _uniq_frac_2907; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x120, _ctx);
        _x_x241 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
      }
      _x_x239 = kk_std_num_ddouble__lp__plus__rp_(_x_x240, _x_x241, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_time_date__new_Clock(kk_reuse_null, 0, h, m, _x_x239, _ctx);
    }
  }
}
 
// Create a clock from a seconds as an `:int` with an optional fraction.
// Normalizes the clock with seconds and minutes under 60 but
// adds the fraction as is to the final seconds, so that might
// be `>= 60` if the fraction `>= 1.0`;

kk_std_time_date__clock kk_std_time_date_intfloat64_fs_clock(kk_integer_t seconds, double frac, kk_context_t* _ctx) { /* (seconds : int, frac : float64) -> clock */ 
  kk_std_core_types__tuple2 _match_x116 = kk_std_core_int_divmod(seconds, kk_integer_from_small(60), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x18 = _match_x116.fst;
    kk_box_t _box_x19 = _match_x116.snd;
    kk_integer_t hm = kk_integer_unbox(_box_x18, _ctx);
    kk_integer_t s = kk_integer_unbox(_box_x19, _ctx);
    kk_integer_dup(hm, _ctx);
    kk_integer_dup(s, _ctx);
    kk_std_core_types__tuple2_drop(_match_x116, _ctx);
    kk_std_core_types__tuple2 _match_x117 = kk_std_core_int_divmod(hm, kk_integer_from_small(60), _ctx); /*(int, int)*/;
    {
      kk_box_t _box_x20 = _match_x117.fst;
      kk_box_t _box_x21 = _match_x117.snd;
      kk_integer_t h = kk_integer_unbox(_box_x20, _ctx);
      kk_integer_t m = kk_integer_unbox(_box_x21, _ctx);
      kk_integer_dup(h, _ctx);
      kk_integer_dup(m, _ctx);
      kk_std_core_types__tuple2_drop(_match_x117, _ctx);
      kk_std_num_ddouble__ddouble _x_x242;
      kk_std_num_ddouble__ddouble _x_x243 = kk_std_num_ddouble_ddouble_int_exp(s, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x244 = kk_std_num_ddouble__new_Ddouble(frac, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      _x_x242 = kk_std_num_ddouble__lp__plus__rp_(_x_x243, _x_x244, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_time_date__new_Clock(kk_reuse_null, 0, h, m, _x_x242, _ctx);
    }
  }
}

kk_std_time_date__clock kk_std_time_date_leap_fs_clock(kk_std_num_ddouble__ddouble seconds, kk_integer_t leap, kk_context_t* _ctx) { /* (seconds : std/num/ddouble/ddouble, leap : int) -> clock */ 
  kk_integer_t seconds_0_10066;
  kk_std_num_ddouble__ddouble _x_x245 = kk_std_num_ddouble_floor(seconds, _ctx); /*std/num/ddouble/ddouble*/
  seconds_0_10066 = kk_std_num_ddouble_int(_x_x245, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_std_num_ddouble__ddouble _b_x22_23;
  kk_std_num_ddouble__ddouble _x_x246 = kk_std_num_ddouble_ffraction(seconds, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x247 = kk_std_num_ddouble_ddouble_int_exp(leap, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  _b_x22_23 = kk_std_num_ddouble__lp__plus__rp_(_x_x246, _x_x247, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__tuple2 _match_x113 = kk_std_core_int_divmod(seconds_0_10066, kk_integer_from_small(60), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x24 = _match_x113.fst;
    kk_box_t _box_x25 = _match_x113.snd;
    kk_integer_t hm = kk_integer_unbox(_box_x24, _ctx);
    kk_integer_t s = kk_integer_unbox(_box_x25, _ctx);
    kk_integer_dup(hm, _ctx);
    kk_integer_dup(s, _ctx);
    kk_std_core_types__tuple2_drop(_match_x113, _ctx);
    kk_std_core_types__tuple2 _match_x114 = kk_std_core_int_divmod(hm, kk_integer_from_small(60), _ctx); /*(int, int)*/;
    {
      kk_box_t _box_x26 = _match_x114.fst;
      kk_box_t _box_x27 = _match_x114.snd;
      kk_integer_t h = kk_integer_unbox(_box_x26, _ctx);
      kk_integer_t m = kk_integer_unbox(_box_x27, _ctx);
      kk_integer_dup(h, _ctx);
      kk_integer_dup(m, _ctx);
      kk_std_core_types__tuple2_drop(_match_x114, _ctx);
      kk_std_num_ddouble__ddouble _x_x248;
      kk_std_num_ddouble__ddouble _x_x249 = kk_std_num_ddouble_ddouble_int_exp(s, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x250;
      kk_std_core_types__optional _match_x115 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(_b_x22_23, _ctx), _ctx); /*? 0*/;
      if (kk_std_core_types__is_Optional(_match_x115, _ctx)) {
        kk_box_t _box_x28 = _match_x115._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_frac_2907 = kk_std_num_ddouble__ddouble_unbox(_box_x28, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x115, _ctx);
        _x_x250 = _uniq_frac_2907; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x115, _ctx);
        _x_x250 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
      }
      _x_x248 = kk_std_num_ddouble__lp__plus__rp_(_x_x249, _x_x250, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_time_date__new_Clock(kk_reuse_null, 0, h, m, _x_x248, _ctx);
    }
  }
}
 
// The zero clock

kk_std_time_date__clock kk_std_time_date_clock0;
 
// Is this a zero clock?

bool kk_std_time_date_is_zero(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> bool */ 
  bool _match_x107;
  kk_integer_t _brw_x111;
  {
    struct kk_std_time_date_Clock* _con_x251 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1 = _con_x251->seconds;
    kk_integer_t _x = _con_x251->hours;
    kk_integer_dup(_x, _ctx);
    _brw_x111 = _x; /*int*/
  }
  bool _brw_x112 = kk_integer_is_zero_borrow(_brw_x111); /*bool*/;
  kk_integer_drop(_brw_x111, _ctx);
  _match_x107 = _brw_x112; /*bool*/
  if (_match_x107) {
    bool _match_x108;
    kk_integer_t _brw_x109;
    {
      struct kk_std_time_date_Clock* _con_x252 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_0 = _con_x252->seconds;
      kk_integer_t _x_0 = _con_x252->minutes;
      kk_integer_dup(_x_0, _ctx);
      _brw_x109 = _x_0; /*int*/
    }
    bool _brw_x110 = kk_integer_is_zero_borrow(_brw_x109); /*bool*/;
    kk_integer_drop(_brw_x109, _ctx);
    _match_x108 = _brw_x110; /*bool*/
    if (_match_x108) {
      double _x_x253;
      {
        struct kk_std_time_date_Clock* _con_x254 = kk_std_time_date__as_Clock(c, _ctx);
        kk_std_num_ddouble__ddouble _x_2 = _con_x254->seconds;
        kk_integer_t _pat_0_3 = _con_x254->hours;
        kk_integer_t _pat_1_1 = _con_x254->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
          kk_integer_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(c, _ctx);
        }
        else {
          kk_datatype_ptr_decref(c, _ctx);
        }
        {
          double _x_1 = _x_2.hi;
          _x_x253 = _x_1; /*float64*/
        }
      }
      return (_x_x253 == (0x0p+0));
    }
    {
      kk_datatype_ptr_dropn(c, (KK_I32(2)), _ctx);
      return false;
    }
  }
  {
    kk_datatype_ptr_dropn(c, (KK_I32(2)), _ctx);
    return false;
  }
}
 
// Return the fraction of the seconds as milli-seconds (10^-3^).

kk_integer_t kk_std_time_date_milli_seconds(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> int */ 
  kk_std_num_ddouble__ddouble x_10075;
  kk_std_num_ddouble__ddouble _x_x255;
  {
    struct kk_std_time_date_Clock* _con_x256 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_0 = _con_x256->seconds;
    kk_integer_t _pat_0_1 = _con_x256->hours;
    kk_integer_t _pat_1_0 = _con_x256->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_0, _ctx);
      kk_integer_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x255 = _x_0; /*std/num/ddouble/ddouble*/
  }
  x_10075 = kk_std_num_ddouble_fraction(_x_x255, _ctx); /*std/num/ddouble/ddouble*/
  double d_10074;
  double _x_x257;
  {
    double _x = x_10075.hi;
    _x_x257 = _x; /*float64*/
  }
  d_10074 = (_x_x257 * (0x1.f4p9)); /*float64*/
  double _x_x258;
  bool _match_x106 = (d_10074 >= (0x0p+0)); /*bool*/;
  if (_match_x106) {
    _x_x258 = floor(d_10074); /*float64*/
  }
  else {
    _x_x258 = ceil(d_10074); /*float64*/
  }
  return kk_integer_from_double(_x_x258,kk_context());
}
 
// Return the fraction of seconds as nano-seconds ((10^-9^).

kk_integer_t kk_std_time_date_nano_seconds(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> int */ 
  kk_std_num_ddouble__ddouble x_10078;
  kk_std_num_ddouble__ddouble _x_x259;
  {
    struct kk_std_time_date_Clock* _con_x260 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_0 = _con_x260->seconds;
    kk_integer_t _pat_0_1 = _con_x260->hours;
    kk_integer_t _pat_1_0 = _con_x260->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_0, _ctx);
      kk_integer_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x259 = _x_0; /*std/num/ddouble/ddouble*/
  }
  x_10078 = kk_std_num_ddouble_fraction(_x_x259, _ctx); /*std/num/ddouble/ddouble*/
  double d_10077;
  double _x_x261;
  {
    double _x = x_10078.hi;
    _x_x261 = _x; /*float64*/
  }
  d_10077 = (_x_x261 * (0x1.dcd65p29)); /*float64*/
  double _x_x262;
  bool _match_x105 = (d_10077 >= (0x0p+0)); /*bool*/;
  if (_match_x105) {
    _x_x262 = floor(d_10077); /*float64*/
  }
  else {
    _x_x262 = ceil(d_10077); /*float64*/
  }
  return kk_integer_from_double(_x_x262,kk_context());
}
 
// Round a clock time to a certain number of digits precision (of the fraction of seconds) (default `9`, nano seconds).

kk_std_time_date__clock kk_std_time_date_round_to_prec(kk_std_time_date__clock c, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (c : clock, prec : ? int) -> clock */ 
  kk_integer_t _x_x263;
  {
    struct kk_std_time_date_Clock* _con_x264 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1 = _con_x264->seconds;
    kk_integer_t _x = _con_x264->hours;
    kk_integer_dup(_x, _ctx);
    _x_x263 = _x; /*int*/
  }
  kk_integer_t _x_x265;
  {
    struct kk_std_time_date_Clock* _con_x266 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_0 = _con_x266->seconds;
    kk_integer_t _x_0 = _con_x266->minutes;
    kk_integer_dup(_x_0, _ctx);
    _x_x265 = _x_0; /*int*/
  }
  kk_std_num_ddouble__ddouble _x_x267;
  kk_std_num_ddouble__ddouble _x_x268;
  {
    struct kk_std_time_date_Clock* _con_x269 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x269->seconds;
    kk_integer_t _pat_0_1 = _con_x269->hours;
    kk_integer_t _pat_1_1 = _con_x269->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_1, _ctx);
      kk_integer_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x268 = _x_1; /*std/num/ddouble/ddouble*/
  }
  kk_integer_t _x_x270;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x29 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_3146 = kk_integer_unbox(_box_x29, _ctx);
    kk_integer_dup(_uniq_prec_3146, _ctx);
    kk_std_core_types__optional_drop(prec, _ctx);
    _x_x270 = _uniq_prec_3146; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(prec, _ctx);
    _x_x270 = kk_integer_from_small(9); /*int*/
  }
  _x_x267 = kk_std_num_ddouble_round_to_prec(_x_x268, _x_x270, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x263, _x_x265, _x_x267, _ctx);
}
 
// Show seconds

kk_string_t kk_std_time_date_show_seconds(kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx) { /* (secs : std/num/ddouble/ddouble, max-prec : ? int, secs-width : ? int, unit : ? string) -> string */ 
  kk_integer_t _b_x31_32;
  kk_integer_t _x_x271;
  kk_integer_t _x_x272;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x30 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_3179 = kk_integer_unbox(_box_x30, _ctx);
    kk_integer_dup(_uniq_max_prec_3179, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x272 = _uniq_max_prec_3179; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x272 = kk_integer_from_small(9); /*int*/
  }
  _x_x271 = kk_integer_abs(_x_x272,kk_context()); /*int*/
  _b_x31_32 = kk_integer_neg(_x_x271,kk_context()); /*int*/
  kk_string_t s;
  kk_std_core_types__optional _x_x273 = kk_std_core_types__new_Optional(kk_integer_box(_b_x31_32, _ctx), _ctx); /*? 7*/
  s = kk_std_num_ddouble_show_fixed(secs, _x_x273, _ctx); /*string*/
  kk_std_core_types__maybe _match_x98;
  kk_string_t _x_x274 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x275;
  kk_define_string_literal(, _s_x276, 1, ".", _ctx)
  _x_x275 = kk_string_dup(_s_x276, _ctx); /*string*/
  _match_x98 = kk_std_core_sslice_find(_x_x274, _x_x275, _ctx); /*maybe<sslice/sslice>*/
  if (kk_std_core_types__is_Nothing(_match_x98, _ctx)) {
    kk_std_core_types__optional_drop(unit, _ctx);
    kk_integer_t _brw_x103;
    if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
      kk_box_t _box_x33 = secs_width._cons._Optional.value;
      kk_integer_t _uniq_secs_width_3183 = kk_integer_unbox(_box_x33, _ctx);
      kk_integer_dup(_uniq_secs_width_3183, _ctx);
      kk_std_core_types__optional_drop(secs_width, _ctx);
      _brw_x103 = _uniq_secs_width_3183; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(secs_width, _ctx);
      _brw_x103 = kk_integer_from_small(1); /*int*/
    }
    kk_string_t _brw_x104;
    kk_std_core_types__optional _x_x277 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
    _brw_x104 = kk_std_core_string_pad_left(s, _brw_x103, _x_x277, _ctx); /*string*/
    kk_integer_drop(_brw_x103, _ctx);
    return _brw_x104;
  }
  {
    kk_box_t _box_x35 = _match_x98._cons.Just.value;
    kk_std_core_sslice__sslice dot = kk_std_core_sslice__sslice_unbox(_box_x35, KK_BORROWED, _ctx);
    kk_string_drop(s, _ctx);
    kk_std_core_sslice__sslice_dup(dot, _ctx);
    kk_std_core_types__maybe_drop(_match_x98, _ctx);
    kk_string_t f;
    kk_std_core_sslice__sslice _x_x278;
    kk_std_core_sslice__sslice _x_x279 = kk_std_core_sslice__sslice_dup(dot, _ctx); /*sslice/sslice*/
    _x_x278 = kk_std_core_sslice_after(_x_x279, _ctx); /*sslice/sslice*/
    f = kk_std_core_sslice_string(_x_x278, _ctx); /*string*/
    kk_integer_t x_10083;
    kk_string_t _x_x280 = kk_string_dup(f, _ctx); /*string*/
    x_10083 = kk_std_core_string_chars_fs_count(_x_x280, _ctx); /*int*/
    kk_integer_t len3;
    kk_integer_t _x_x281;
    kk_integer_t _x_x282 = kk_integer_add_small_const(x_10083, 2, _ctx); /*int*/
    _x_x281 = kk_integer_div(_x_x282,(kk_integer_from_small(3)),kk_context()); /*int*/
    len3 = kk_integer_mul(_x_x281,(kk_integer_from_small(3)),kk_context()); /*int*/
    kk_char_t _b_x37_41 = '0'; /*char*/;
    kk_string_t _x_x283;
    kk_string_t _own_x101;
    kk_std_core_sslice__sslice _x_x284;
    {
      kk_string_t s_0 = dot.str;
      kk_integer_t start = dot.start;
      kk_string_dup(s_0, _ctx);
      kk_integer_dup(start, _ctx);
      kk_std_core_sslice__sslice_drop(dot, _ctx);
      _x_x284 = kk_std_core_sslice__new_Sslice(s_0, kk_integer_from_small(0), start, _ctx); /*sslice/sslice*/
    }
    _own_x101 = kk_std_core_sslice_string(_x_x284, _ctx); /*string*/
    kk_integer_t _brw_x100;
    if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
      kk_box_t _box_x36 = secs_width._cons._Optional.value;
      kk_integer_t _uniq_secs_width_3183_0 = kk_integer_unbox(_box_x36, _ctx);
      kk_integer_dup(_uniq_secs_width_3183_0, _ctx);
      kk_std_core_types__optional_drop(secs_width, _ctx);
      _brw_x100 = _uniq_secs_width_3183_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(secs_width, _ctx);
      _brw_x100 = kk_integer_from_small(1); /*int*/
    }
    kk_string_t _brw_x102;
    kk_std_core_types__optional _x_x285 = kk_std_core_types__new_Optional(kk_char_box(_b_x37_41, _ctx), _ctx); /*? 7*/
    _brw_x102 = kk_std_core_string_pad_left(_own_x101, _brw_x100, _x_x285, _ctx); /*string*/
    kk_integer_drop(_brw_x100, _ctx);
    _x_x283 = _brw_x102; /*string*/
    kk_string_t _x_x286;
    kk_string_t _x_x287;
    kk_define_string_literal(, _s_x288, 1, ".", _ctx)
    _x_x287 = kk_string_dup(_s_x288, _ctx); /*string*/
    kk_string_t _x_x289;
    kk_char_t _b_x38_42 = '0'; /*char*/;
    kk_string_t _x_x290;
    kk_string_t _brw_x99;
    kk_std_core_types__optional _x_x291 = kk_std_core_types__new_Optional(kk_char_box(_b_x38_42, _ctx), _ctx); /*? 7*/
    _brw_x99 = kk_std_core_string_pad_right(f, len3, _x_x291, _ctx); /*string*/
    kk_integer_drop(len3, _ctx);
    _x_x290 = _brw_x99; /*string*/
    kk_string_t _x_x292;
    if (kk_std_core_types__is_Optional(unit, _ctx)) {
      kk_box_t _box_x39 = unit._cons._Optional.value;
      kk_string_t _uniq_unit_3187 = kk_string_unbox(_box_x39);
      kk_string_dup(_uniq_unit_3187, _ctx);
      kk_std_core_types__optional_drop(unit, _ctx);
      _x_x292 = _uniq_unit_3187; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(unit, _ctx);
      _x_x292 = kk_string_empty(); /*string*/
    }
    _x_x289 = kk_std_core_types__lp__plus__plus__rp_(_x_x290, _x_x292, _ctx); /*string*/
    _x_x286 = kk_std_core_types__lp__plus__plus__rp_(_x_x287, _x_x289, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x283, _x_x286, _ctx);
  }
}
 
// Show a `:weekday` as an English string (`Sun.show == "Sunday"`).

kk_string_t kk_std_time_date_weekday_fs_show(kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (wd : weekday) -> string */ 
  if (kk_std_time_date__is_Mon(wd, _ctx)) {
    kk_define_string_literal(, _s_x298, 6, "Monday", _ctx)
    return kk_string_dup(_s_x298, _ctx);
  }
  if (kk_std_time_date__is_Tue(wd, _ctx)) {
    kk_define_string_literal(, _s_x299, 7, "Tuesday", _ctx)
    return kk_string_dup(_s_x299, _ctx);
  }
  if (kk_std_time_date__is_Wed(wd, _ctx)) {
    kk_define_string_literal(, _s_x300, 9, "Wednesday", _ctx)
    return kk_string_dup(_s_x300, _ctx);
  }
  if (kk_std_time_date__is_Thu(wd, _ctx)) {
    kk_define_string_literal(, _s_x301, 8, "Thursday", _ctx)
    return kk_string_dup(_s_x301, _ctx);
  }
  if (kk_std_time_date__is_Fri(wd, _ctx)) {
    kk_define_string_literal(, _s_x302, 6, "Friday", _ctx)
    return kk_string_dup(_s_x302, _ctx);
  }
  if (kk_std_time_date__is_Sat(wd, _ctx)) {
    kk_define_string_literal(, _s_x303, 8, "Saturday", _ctx)
    return kk_string_dup(_s_x303, _ctx);
  }
  {
    kk_define_string_literal(, _s_x304, 6, "Sunday", _ctx)
    return kk_string_dup(_s_x304, _ctx);
  }
}
 
// pad with zeros

kk_string_t kk_std_time_date_show0(kk_integer_t i, kk_std_core_types__optional width, kk_context_t* _ctx) { /* (i : int, width : ? int) -> string */ 
  kk_string_t _own_x96 = kk_std_core_int_show(i, _ctx); /*string*/;
  kk_integer_t _brw_x95;
  if (kk_std_core_types__is_Optional(width, _ctx)) {
    kk_box_t _box_x43 = width._cons._Optional.value;
    kk_integer_t _uniq_width_4557 = kk_integer_unbox(_box_x43, _ctx);
    kk_integer_dup(_uniq_width_4557, _ctx);
    kk_std_core_types__optional_drop(width, _ctx);
    _brw_x95 = _uniq_width_4557; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(width, _ctx);
    _brw_x95 = kk_integer_from_small(2); /*int*/
  }
  kk_string_t _brw_x97;
  kk_std_core_types__optional _x_x308 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
  _brw_x97 = kk_std_core_string_pad_left(_own_x96, _brw_x95, _x_x308, _ctx); /*string*/
  kk_integer_drop(_brw_x95, _ctx);
  return _brw_x97;
}
 
// Show a year in ISO format (using 5+ digits and explicit sign for years < 0 or years > 9999)).

kk_string_t kk_std_time_date_show_year(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> string */ 
  bool _match_x88;
  kk_integer_t _brw_x93 = kk_integer_from_int(9999, _ctx); /*int*/;
  bool _brw_x94 = kk_integer_gt_borrow(year,_brw_x93,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x93, _ctx);
  _match_x88 = _brw_x94; /*bool*/
  if (_match_x88) {
    kk_integer_t i_10086 = kk_integer_abs(year,kk_context()); /*int*/;
    kk_char_t _b_x46_49 = '0'; /*char*/;
    kk_string_t _x_x309;
    kk_define_string_literal(, _s_x310, 1, "+", _ctx)
    _x_x309 = kk_string_dup(_s_x310, _ctx); /*string*/
    kk_string_t _x_x311;
    kk_string_t _own_x92 = kk_std_core_int_show(i_10086, _ctx); /*string*/;
    kk_std_core_types__optional _x_x312 = kk_std_core_types__new_Optional(kk_char_box(_b_x46_49, _ctx), _ctx); /*? 7*/
    _x_x311 = kk_std_core_string_pad_left(_own_x92, kk_integer_from_small(5), _x_x312, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x309, _x_x311, _ctx);
  }
  {
    bool _match_x89 = kk_integer_lt_borrow(year,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x89) {
      kk_integer_t i_1_10089 = kk_integer_abs(year,kk_context()); /*int*/;
      kk_char_t _b_x47_50 = '0'; /*char*/;
      kk_string_t _x_x313;
      kk_define_string_literal(, _s_x314, 1, "-", _ctx)
      _x_x313 = kk_string_dup(_s_x314, _ctx); /*string*/
      kk_string_t _x_x315;
      kk_string_t _own_x91 = kk_std_core_int_show(i_1_10089, _ctx); /*string*/;
      kk_std_core_types__optional _x_x316 = kk_std_core_types__new_Optional(kk_char_box(_b_x47_50, _ctx), _ctx); /*? 7*/
      _x_x315 = kk_std_core_string_pad_left(_own_x91, kk_integer_from_small(5), _x_x316, _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(_x_x313, _x_x315, _ctx);
    }
    {
      kk_integer_t i_2_10091 = kk_integer_abs(year,kk_context()); /*int*/;
      kk_char_t _b_x48_51 = '0'; /*char*/;
      kk_string_t _x_x317 = kk_string_empty(); /*string*/
      kk_string_t _x_x319;
      kk_string_t _own_x90 = kk_std_core_int_show(i_2_10091, _ctx); /*string*/;
      kk_std_core_types__optional _x_x320 = kk_std_core_types__new_Optional(kk_char_box(_b_x48_51, _ctx), _ctx); /*? 7*/
      _x_x319 = kk_std_core_string_pad_left(_own_x90, kk_integer_from_small(4), _x_x320, _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(_x_x317, _x_x319, _ctx);
    }
  }
}
 
// Show a date in ISO format. `Date(2000,1,1).show == "2000-01-01"`.
// Takes an optional `month-prefix` (=`""`) that is used by the ISO week
// and month calendar to add a `"W"` or `"M"` prefix respectively.

kk_string_t kk_std_time_date_show(kk_std_time_date__date d, kk_std_core_types__optional month_prefix, kk_context_t* _ctx) { /* (d : date, month-prefix : ? string) -> string */ 
  kk_integer_t day_width;
  bool _match_x87;
  kk_string_t _x_x321;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x52 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_4343 = kk_string_unbox(_box_x52);
    kk_string_dup(_uniq_month_prefix_4343, _ctx);
    _x_x321 = _uniq_month_prefix_4343; /*string*/
  }
  else {
    _x_x321 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x323;
  kk_define_string_literal(, _s_x324, 1, "W", _ctx)
  _x_x323 = kk_string_dup(_s_x324, _ctx); /*string*/
  _match_x87 = kk_string_is_eq(_x_x321,_x_x323,kk_context()); /*bool*/
  if (_match_x87) {
    day_width = kk_integer_from_small(1); /*int*/
  }
  else {
    day_width = kk_integer_from_small(2); /*int*/
  }
  kk_string_t _x_x325;
  kk_integer_t _x_x326;
  {
    kk_integer_t _x = d.year;
    kk_integer_dup(_x, _ctx);
    _x_x326 = _x; /*int*/
  }
  _x_x325 = kk_std_time_date_show_year(_x_x326, _ctx); /*string*/
  kk_string_t _x_x327;
  kk_string_t _x_x328;
  kk_define_string_literal(, _s_x329, 1, "-", _ctx)
  _x_x328 = kk_string_dup(_s_x329, _ctx); /*string*/
  kk_string_t _x_x330;
  kk_string_t _x_x331;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x53 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_4343_0 = kk_string_unbox(_box_x53);
    kk_string_dup(_uniq_month_prefix_4343_0, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x331 = _uniq_month_prefix_4343_0; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x331 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x333;
  kk_char_t _b_x55_57 = '0'; /*char*/;
  kk_string_t _x_x334;
  kk_string_t _own_x85;
  kk_integer_t _x_x335;
  {
    kk_integer_t _x_0 = d.month;
    kk_integer_dup(_x_0, _ctx);
    _x_x335 = _x_0; /*int*/
  }
  _own_x85 = kk_std_core_int_show(_x_x335, _ctx); /*string*/
  kk_integer_t _brw_x84;
  kk_std_core_types__optional _match_x83 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x83, _ctx)) {
    kk_box_t _box_x54 = _match_x83._cons._Optional.value;
    kk_integer_t _uniq_width_4557 = kk_integer_unbox(_box_x54, _ctx);
    kk_integer_dup(_uniq_width_4557, _ctx);
    kk_std_core_types__optional_drop(_match_x83, _ctx);
    _brw_x84 = _uniq_width_4557; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x83, _ctx);
    _brw_x84 = kk_integer_from_small(2); /*int*/
  }
  kk_string_t _brw_x86;
  kk_std_core_types__optional _x_x336 = kk_std_core_types__new_Optional(kk_char_box(_b_x55_57, _ctx), _ctx); /*? 7*/
  _brw_x86 = kk_std_core_string_pad_left(_own_x85, _brw_x84, _x_x336, _ctx); /*string*/
  kk_integer_drop(_brw_x84, _ctx);
  _x_x334 = _brw_x86; /*string*/
  kk_string_t _x_x337;
  kk_char_t _b_x56_58 = '0'; /*char*/;
  kk_string_t _x_x338;
  kk_define_string_literal(, _s_x339, 1, "-", _ctx)
  _x_x338 = kk_string_dup(_s_x339, _ctx); /*string*/
  kk_string_t _x_x340;
  kk_string_t _own_x81;
  kk_integer_t _x_x341;
  {
    kk_integer_t _x_1 = d.day;
    kk_integer_dup(_x_1, _ctx);
    kk_std_time_date__date_drop(d, _ctx);
    _x_x341 = _x_1; /*int*/
  }
  _own_x81 = kk_std_core_int_show(_x_x341, _ctx); /*string*/
  kk_string_t _brw_x82;
  kk_std_core_types__optional _x_x342 = kk_std_core_types__new_Optional(kk_char_box(_b_x56_58, _ctx), _ctx); /*? 7*/
  _brw_x82 = kk_std_core_string_pad_left(_own_x81, day_width, _x_x342, _ctx); /*string*/
  kk_integer_drop(day_width, _ctx);
  _x_x340 = _brw_x82; /*string*/
  _x_x337 = kk_std_core_types__lp__plus__plus__rp_(_x_x338, _x_x340, _ctx); /*string*/
  _x_x333 = kk_std_core_types__lp__plus__plus__rp_(_x_x334, _x_x337, _ctx); /*string*/
  _x_x330 = kk_std_core_types__lp__plus__plus__rp_(_x_x331, _x_x333, _ctx); /*string*/
  _x_x327 = kk_std_core_types__lp__plus__plus__rp_(_x_x328, _x_x330, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x325, _x_x327, _ctx);
}
 
// Show a clock in ISO format up to an optional maximum precision (=`9`).
// `Clock(23,30,fixed(1.123)).show == "23:30:01.123"`
// `Clock(23,30,fixed(1.123)).show(0) == "23:30:01"`

kk_string_t kk_std_time_date_clock_fs_show(kk_std_time_date__clock c, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (c : clock, prec : ? int) -> string */ 
  kk_char_t _b_x60_66 = '0'; /*char*/;
  kk_string_t _x_x343;
  kk_string_t _own_x79;
  kk_integer_t _x_x344;
  {
    struct kk_std_time_date_Clock* _con_x345 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_0 = _con_x345->seconds;
    kk_integer_t _x = _con_x345->hours;
    kk_integer_dup(_x, _ctx);
    _x_x344 = _x; /*int*/
  }
  _own_x79 = kk_std_core_int_show(_x_x344, _ctx); /*string*/
  kk_integer_t _brw_x78;
  kk_std_core_types__optional _match_x77 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x77, _ctx)) {
    kk_box_t _box_x59 = _match_x77._cons._Optional.value;
    kk_integer_t _uniq_width_4557 = kk_integer_unbox(_box_x59, _ctx);
    kk_integer_dup(_uniq_width_4557, _ctx);
    kk_std_core_types__optional_drop(_match_x77, _ctx);
    _brw_x78 = _uniq_width_4557; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x77, _ctx);
    _brw_x78 = kk_integer_from_small(2); /*int*/
  }
  kk_string_t _brw_x80;
  kk_std_core_types__optional _x_x346 = kk_std_core_types__new_Optional(kk_char_box(_b_x60_66, _ctx), _ctx); /*? 7*/
  _brw_x80 = kk_std_core_string_pad_left(_own_x79, _brw_x78, _x_x346, _ctx); /*string*/
  kk_integer_drop(_brw_x78, _ctx);
  _x_x343 = _brw_x80; /*string*/
  kk_string_t _x_x347;
  kk_string_t _x_x348;
  kk_define_string_literal(, _s_x349, 1, ":", _ctx)
  _x_x348 = kk_string_dup(_s_x349, _ctx); /*string*/
  kk_string_t _x_x350;
  kk_char_t _b_x62_67 = '0'; /*char*/;
  kk_string_t _x_x351;
  kk_string_t _own_x75;
  kk_integer_t _x_x352;
  {
    struct kk_std_time_date_Clock* _con_x353 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_1 = _con_x353->seconds;
    kk_integer_t _x_0 = _con_x353->minutes;
    kk_integer_dup(_x_0, _ctx);
    _x_x352 = _x_0; /*int*/
  }
  _own_x75 = kk_std_core_int_show(_x_x352, _ctx); /*string*/
  kk_integer_t _brw_x74;
  kk_std_core_types__optional _match_x73 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x73, _ctx)) {
    kk_box_t _box_x61 = _match_x73._cons._Optional.value;
    kk_integer_t _uniq_width_4557_0 = kk_integer_unbox(_box_x61, _ctx);
    kk_integer_dup(_uniq_width_4557_0, _ctx);
    kk_std_core_types__optional_drop(_match_x73, _ctx);
    _brw_x74 = _uniq_width_4557_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x73, _ctx);
    _brw_x74 = kk_integer_from_small(2); /*int*/
  }
  kk_string_t _brw_x76;
  kk_std_core_types__optional _x_x354 = kk_std_core_types__new_Optional(kk_char_box(_b_x62_67, _ctx), _ctx); /*? 7*/
  _brw_x76 = kk_std_core_string_pad_left(_own_x75, _brw_x74, _x_x354, _ctx); /*string*/
  kk_integer_drop(_brw_x74, _ctx);
  _x_x351 = _brw_x76; /*string*/
  kk_string_t _x_x355;
  kk_integer_t _b_x64_68;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x63 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_4756 = kk_integer_unbox(_box_x63, _ctx);
    kk_integer_dup(_uniq_prec_4756, _ctx);
    kk_std_core_types__optional_drop(prec, _ctx);
    _b_x64_68 = _uniq_prec_4756; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(prec, _ctx);
    _b_x64_68 = kk_integer_from_small(9); /*int*/
  }
  kk_integer_t _b_x65_69 = kk_integer_from_small(2); /*int*/;
  kk_string_t _x_x356;
  kk_define_string_literal(, _s_x357, 1, ":", _ctx)
  _x_x356 = kk_string_dup(_s_x357, _ctx); /*string*/
  kk_string_t _x_x358;
  kk_std_num_ddouble__ddouble _x_x359;
  {
    struct kk_std_time_date_Clock* _con_x360 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x360->seconds;
    kk_integer_t _pat_0_3 = _con_x360->hours;
    kk_integer_t _pat_1_2 = _con_x360->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_2, _ctx);
      kk_integer_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x359 = _x_1; /*std/num/ddouble/ddouble*/
  }
  kk_std_core_types__optional _x_x361 = kk_std_core_types__new_Optional(kk_integer_box(_b_x64_68, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x362 = kk_std_core_types__new_Optional(kk_integer_box(_b_x65_69, _ctx), _ctx); /*? 7*/
  _x_x358 = kk_std_time_date_show_seconds(_x_x359, _x_x361, _x_x362, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  _x_x355 = kk_std_core_types__lp__plus__plus__rp_(_x_x356, _x_x358, _ctx); /*string*/
  _x_x350 = kk_std_core_types__lp__plus__plus__rp_(_x_x351, _x_x355, _ctx); /*string*/
  _x_x347 = kk_std_core_types__lp__plus__plus__rp_(_x_x348, _x_x350, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x343, _x_x347, _ctx);
}
 
// Return the whole seconds part of a `:clock`.

kk_integer_t kk_std_time_date_whole_seconds(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> int */ 
  kk_std_num_ddouble__ddouble _x_x363;
  bool _match_x72;
  double _x_x364;
  {
    struct kk_std_time_date_Clock* _con_x365 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_0 = _con_x365->seconds;
    {
      double _x = _x_0.hi;
      _x_x364 = _x; /*float64*/
    }
  }
  _match_x72 = (_x_x364 < (0x0p+0)); /*bool*/
  if (_match_x72) {
    kk_std_num_ddouble__ddouble _x_x366;
    {
      struct kk_std_time_date_Clock* _con_x367 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _x_0_0 = _con_x367->seconds;
      kk_integer_t _pat_0_1_0 = _con_x367->hours;
      kk_integer_t _pat_1_0_0 = _con_x367->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
        kk_integer_drop(_pat_1_0_0, _ctx);
        kk_integer_drop(_pat_0_1_0, _ctx);
        kk_datatype_ptr_free(c, _ctx);
      }
      else {
        kk_datatype_ptr_decref(c, _ctx);
      }
      _x_x366 = _x_0_0; /*std/num/ddouble/ddouble*/
    }
    _x_x363 = kk_std_num_ddouble_ceiling(_x_x366, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x368;
    {
      struct kk_std_time_date_Clock* _con_x369 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _x_0_1 = _con_x369->seconds;
      kk_integer_t _pat_0_1_1 = _con_x369->hours;
      kk_integer_t _pat_1_0_1 = _con_x369->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
        kk_integer_drop(_pat_1_0_1, _ctx);
        kk_integer_drop(_pat_0_1_1, _ctx);
        kk_datatype_ptr_free(c, _ctx);
      }
      else {
        kk_datatype_ptr_decref(c, _ctx);
      }
      _x_x368 = _x_0_1; /*std/num/ddouble/ddouble*/
    }
    _x_x363 = kk_std_num_ddouble_floor(_x_x368, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble_int(_x_x363, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Return the ISO calendar date of Easter in a given year (Algorithm by [J.M. Oudin](https://aa.usno.navy.mil/faq/docs/easter.php)).

kk_std_time_date__date kk_std_time_date_easter(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> date */ 
  kk_integer_t c;
  kk_integer_t _x_x374 = kk_integer_dup(year, _ctx); /*int*/
  c = kk_integer_div(_x_x374,(kk_integer_from_small(100)),kk_context()); /*int*/
  kk_integer_t y_10110;
  kk_integer_t _x_x375;
  kk_integer_t _x_x376 = kk_integer_dup(year, _ctx); /*int*/
  _x_x375 = kk_integer_div(_x_x376,(kk_integer_from_small(19)),kk_context()); /*int*/
  y_10110 = kk_integer_mul((kk_integer_from_small(19)),_x_x375,kk_context()); /*int*/
  kk_integer_t n;
  kk_integer_t _x_x377 = kk_integer_dup(year, _ctx); /*int*/
  n = kk_integer_sub(_x_x377,y_10110,kk_context()); /*int*/
  kk_integer_t k;
  kk_integer_t _x_x378;
  kk_integer_t _x_x379 = kk_integer_dup(c, _ctx); /*int*/
  _x_x378 = kk_integer_add_small_const(_x_x379, -17, _ctx); /*int*/
  k = kk_integer_div(_x_x378,(kk_integer_from_small(25)),kk_context()); /*int*/
  kk_integer_t y_4_10120;
  kk_integer_t _x_x380 = kk_integer_dup(c, _ctx); /*int*/
  y_4_10120 = kk_integer_div(_x_x380,(kk_integer_from_small(4)),kk_context()); /*int*/
  kk_integer_t x_3_10117;
  kk_integer_t _x_x381 = kk_integer_dup(c, _ctx); /*int*/
  x_3_10117 = kk_integer_sub(_x_x381,y_4_10120,kk_context()); /*int*/
  kk_integer_t y_3_10118;
  kk_integer_t _x_x382;
  kk_integer_t _x_x383 = kk_integer_dup(c, _ctx); /*int*/
  _x_x382 = kk_integer_sub(_x_x383,k,kk_context()); /*int*/
  y_3_10118 = kk_integer_div(_x_x382,(kk_integer_from_small(3)),kk_context()); /*int*/
  kk_integer_t x_2_10115 = kk_integer_sub(x_3_10117,y_3_10118,kk_context()); /*int*/;
  kk_integer_t y_2_10116;
  kk_integer_t _x_x384 = kk_integer_dup(n, _ctx); /*int*/
  y_2_10116 = kk_integer_mul((kk_integer_from_small(19)),_x_x384,kk_context()); /*int*/
  kk_integer_t x_1_10113 = kk_integer_add(x_2_10115,y_2_10116,kk_context()); /*int*/;
  kk_integer_t i0 = kk_integer_add_small_const(x_1_10113, 15, _ctx); /*int*/;
  kk_integer_t y_6_10124;
  kk_integer_t _x_x385;
  kk_integer_t _x_x386 = kk_integer_dup(i0, _ctx); /*int*/
  _x_x385 = kk_integer_div(_x_x386,(kk_integer_from_small(30)),kk_context()); /*int*/
  y_6_10124 = kk_integer_mul((kk_integer_from_small(30)),_x_x385,kk_context()); /*int*/
  kk_integer_t i1 = kk_integer_sub(i0,y_6_10124,kk_context()); /*int*/;
  kk_integer_t y_8_10128;
  kk_integer_t _x_x387;
  kk_integer_t _x_x388;
  kk_integer_t _x_x389 = kk_integer_dup(i1, _ctx); /*int*/
  _x_x388 = kk_integer_div(_x_x389,(kk_integer_from_small(28)),kk_context()); /*int*/
  kk_integer_t _x_x390;
  kk_integer_t _x_x391;
  kk_integer_t _x_x392 = kk_integer_dup(i1, _ctx); /*int*/
  _x_x391 = kk_integer_add_small_const(_x_x392, 1, _ctx); /*int*/
  _x_x390 = kk_integer_div((kk_integer_from_small(29)),_x_x391,kk_context()); /*int*/
  _x_x387 = kk_integer_mul(_x_x388,_x_x390,kk_context()); /*int*/
  kk_integer_t _x_x393;
  kk_integer_t _x_x394 = kk_integer_sub((kk_integer_from_small(21)),n,kk_context()); /*int*/
  _x_x393 = kk_integer_div(_x_x394,(kk_integer_from_small(11)),kk_context()); /*int*/
  y_8_10128 = kk_integer_mul(_x_x387,_x_x393,kk_context()); /*int*/
  kk_integer_t y_7_10126;
  kk_integer_t _x_x395;
  kk_integer_t _x_x396 = kk_integer_dup(i1, _ctx); /*int*/
  _x_x395 = kk_integer_div(_x_x396,(kk_integer_from_small(28)),kk_context()); /*int*/
  kk_integer_t _x_x397 = kk_integer_sub((kk_integer_from_small(1)),y_8_10128,kk_context()); /*int*/
  y_7_10126 = kk_integer_mul(_x_x395,_x_x397,kk_context()); /*int*/
  kk_integer_t i = kk_integer_sub(i1,y_7_10126,kk_context()); /*int*/;
  kk_integer_t y_15_10142;
  kk_integer_t _x_x398 = kk_integer_dup(year, _ctx); /*int*/
  y_15_10142 = kk_integer_div(_x_x398,(kk_integer_from_small(4)),kk_context()); /*int*/
  kk_integer_t x_14_10139;
  kk_integer_t _x_x399 = kk_integer_dup(year, _ctx); /*int*/
  x_14_10139 = kk_integer_add(_x_x399,y_15_10142,kk_context()); /*int*/
  kk_integer_t x_13_10137;
  kk_integer_t _x_x400 = kk_integer_dup(i, _ctx); /*int*/
  x_13_10137 = kk_integer_add(x_14_10139,_x_x400,kk_context()); /*int*/
  kk_integer_t x_12_10135 = kk_integer_add_small_const(x_13_10137, 2, _ctx); /*int*/;
  kk_integer_t x_11_10133;
  kk_integer_t _x_x401 = kk_integer_dup(c, _ctx); /*int*/
  x_11_10133 = kk_integer_sub(x_12_10135,_x_x401,kk_context()); /*int*/
  kk_integer_t y_11_10134 = kk_integer_div(c,(kk_integer_from_small(4)),kk_context()); /*int*/;
  kk_integer_t j0 = kk_integer_add(x_11_10133,y_11_10134,kk_context()); /*int*/;
  kk_integer_t y_16_10144;
  kk_integer_t _x_x402;
  kk_integer_t _x_x403 = kk_integer_dup(j0, _ctx); /*int*/
  _x_x402 = kk_integer_div(_x_x403,(kk_integer_from_small(7)),kk_context()); /*int*/
  y_16_10144 = kk_integer_mul((kk_integer_from_small(7)),_x_x402,kk_context()); /*int*/
  kk_integer_t j = kk_integer_sub(j0,y_16_10144,kk_context()); /*int*/;
  kk_integer_t l = kk_integer_sub(i,j,kk_context()); /*int*/;
  kk_integer_t y_18_10148;
  kk_integer_t _x_x404;
  kk_integer_t _x_x405 = kk_integer_dup(l, _ctx); /*int*/
  _x_x404 = kk_integer_add_small_const(_x_x405, 40, _ctx); /*int*/
  y_18_10148 = kk_integer_div(_x_x404,(kk_integer_from_small(44)),kk_context()); /*int*/
  kk_integer_t m = kk_integer_add_small_const(y_18_10148, 3, _ctx); /*int*/;
  kk_integer_t x_20_10151 = kk_integer_add_small_const(l, 28, _ctx); /*int*/;
  kk_integer_t y_20_10152;
  kk_integer_t _x_x406;
  kk_integer_t _x_x407 = kk_integer_dup(m, _ctx); /*int*/
  _x_x406 = kk_integer_div(_x_x407,(kk_integer_from_small(4)),kk_context()); /*int*/
  y_20_10152 = kk_integer_mul((kk_integer_from_small(31)),_x_x406,kk_context()); /*int*/
  kk_integer_t d = kk_integer_sub(x_20_10151,y_20_10152,kk_context()); /*int*/;
  return kk_std_time_date__new_Date(year, m, d, _ctx);
}

// initialization
void kk_std_time_date__init(kk_context_t* _ctx){
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
  kk_std_num_float64__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_time_date_clock0 = kk_std_time_date__new_Clock(kk_reuse_null, 0, kk_integer_from_small(0), kk_integer_from_small(0), kk_std_num_ddouble_zero, _ctx); /*std/time/date/clock*/
  }
}

// termination
void kk_std_time_date__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_time_date__clock_drop(kk_std_time_date_clock0, _ctx);
  kk_std_num_ddouble__done(_ctx);
  kk_std_num_float64__done(_ctx);
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
