// Koka generated module: std/time/date, koka version: 3.2.2, platform: 64-bit
#include "std_time_date.h"

kk_std_time_date__date kk_std_time_date_date_fs__copy(kk_std_time_date__date _this, kk_std_core_types__optional year, kk_std_core_types__optional month, kk_std_core_types__optional day, kk_context_t* _ctx) { /* (date, year : ? int, month : ? int, day : ? int) -> date */ 
  kk_integer_t _x_x231;
  if (kk_std_core_types__is_Optional(year, _ctx)) {
    kk_box_t _box_x0 = year._cons._Optional.value;
    kk_integer_t _uniq_year_102 = kk_integer_unbox(_box_x0, _ctx);
    kk_integer_dup(_uniq_year_102, _ctx);
    kk_std_core_types__optional_drop(year, _ctx);
    _x_x231 = _uniq_year_102; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(year, _ctx);
    {
      kk_integer_t _x = _this.year;
      kk_integer_dup(_x, _ctx);
      _x_x231 = _x; /*int*/
    }
  }
  kk_integer_t _x_x232;
  if (kk_std_core_types__is_Optional(month, _ctx)) {
    kk_box_t _box_x1 = month._cons._Optional.value;
    kk_integer_t _uniq_month_110 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_month_110, _ctx);
    kk_std_core_types__optional_drop(month, _ctx);
    _x_x232 = _uniq_month_110; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(month, _ctx);
    {
      kk_integer_t _x_0 = _this.month;
      kk_integer_dup(_x_0, _ctx);
      _x_x232 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x233;
  if (kk_std_core_types__is_Optional(day, _ctx)) {
    kk_box_t _box_x2 = day._cons._Optional.value;
    kk_integer_t _uniq_day_118 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_day_118, _ctx);
    kk_std_core_types__optional_drop(day, _ctx);
    kk_std_time_date__date_drop(_this, _ctx);
    _x_x233 = _uniq_day_118; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(day, _ctx);
    {
      kk_integer_t _x_1 = _this.day;
      kk_integer_dup(_x_1, _ctx);
      kk_std_time_date__date_drop(_this, _ctx);
      _x_x233 = _x_1; /*int*/
    }
  }
  return kk_std_time_date__new_Date(_x_x231, _x_x232, _x_x233, _ctx);
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
  kk_integer_t _x_x238;
  kk_integer_t _x_x239;
  {
    kk_integer_t _x = d1.year;
    kk_integer_dup(_x, _ctx);
    _x_x239 = _x; /*int*/
  }
  kk_integer_t _x_x240;
  {
    kk_integer_t _x_0 = d2.year;
    kk_integer_dup(_x_0, _ctx);
    _x_x240 = _x_0; /*int*/
  }
  _x_x238 = kk_integer_add(_x_x239,_x_x240,kk_context()); /*int*/
  kk_integer_t _x_x241;
  kk_integer_t _x_x242;
  {
    kk_integer_t _x_1 = d1.month;
    kk_integer_dup(_x_1, _ctx);
    _x_x242 = _x_1; /*int*/
  }
  kk_integer_t _x_x243;
  {
    kk_integer_t _x_2 = d2.month;
    kk_integer_dup(_x_2, _ctx);
    _x_x243 = _x_2; /*int*/
  }
  _x_x241 = kk_integer_add(_x_x242,_x_x243,kk_context()); /*int*/
  kk_integer_t _x_x244;
  kk_integer_t _x_x245;
  {
    kk_integer_t _x_3 = d1.day;
    kk_integer_dup(_x_3, _ctx);
    kk_std_time_date__date_drop(d1, _ctx);
    _x_x245 = _x_3; /*int*/
  }
  kk_integer_t _x_x246;
  {
    kk_integer_t _x_4 = d2.day;
    kk_integer_dup(_x_4, _ctx);
    kk_std_time_date__date_drop(d2, _ctx);
    _x_x246 = _x_4; /*int*/
  }
  _x_x244 = kk_integer_add(_x_x245,_x_x246,kk_context()); /*int*/
  return kk_std_time_date__new_Date(_x_x238, _x_x241, _x_x244, _ctx);
}
 
// Add two clock together.

kk_std_time_date__clock kk_std_time_date_clock_fs__lp__plus__rp_(kk_std_time_date__clock c, kk_std_time_date__clock d, kk_context_t* _ctx) { /* (c : clock, d : clock) -> clock */ 
  kk_integer_t _x_x247;
  kk_integer_t _x_x248;
  {
    struct kk_std_time_date_Clock* _con_x249 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1 = _con_x249->seconds;
    kk_integer_t _x = _con_x249->hours;
    kk_integer_dup(_x, _ctx);
    _x_x248 = _x; /*int*/
  }
  kk_integer_t _x_x250;
  {
    struct kk_std_time_date_Clock* _con_x251 = kk_std_time_date__as_Clock(d, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_0 = _con_x251->seconds;
    kk_integer_t _x_0 = _con_x251->hours;
    kk_integer_dup(_x_0, _ctx);
    _x_x250 = _x_0; /*int*/
  }
  _x_x247 = kk_integer_add(_x_x248,_x_x250,kk_context()); /*int*/
  kk_integer_t _x_x252;
  kk_integer_t _x_x253;
  {
    struct kk_std_time_date_Clock* _con_x254 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_1 = _con_x254->seconds;
    kk_integer_t _x_1 = _con_x254->minutes;
    kk_integer_dup(_x_1, _ctx);
    _x_x253 = _x_1; /*int*/
  }
  kk_integer_t _x_x255;
  {
    struct kk_std_time_date_Clock* _con_x256 = kk_std_time_date__as_Clock(d, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_2 = _con_x256->seconds;
    kk_integer_t _x_2 = _con_x256->minutes;
    kk_integer_dup(_x_2, _ctx);
    _x_x255 = _x_2; /*int*/
  }
  _x_x252 = kk_integer_add(_x_x253,_x_x255,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x257;
  kk_std_num_ddouble__ddouble _x_x258;
  {
    struct kk_std_time_date_Clock* _con_x259 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_3 = _con_x259->seconds;
    kk_integer_t _pat_0_3 = _con_x259->hours;
    kk_integer_t _pat_1_3 = _con_x259->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_3, _ctx);
      kk_integer_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x258 = _x_3; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x260;
  {
    struct kk_std_time_date_Clock* _con_x261 = kk_std_time_date__as_Clock(d, _ctx);
    kk_std_num_ddouble__ddouble _x_4 = _con_x261->seconds;
    kk_integer_t _pat_0_4 = _con_x261->hours;
    kk_integer_t _pat_1_4 = _con_x261->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(d, _ctx)) {
      kk_integer_drop(_pat_1_4, _ctx);
      kk_integer_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(d, _ctx);
    }
    else {
      kk_datatype_ptr_decref(d, _ctx);
    }
    _x_x260 = _x_4; /*std/num/ddouble/ddouble*/
  }
  _x_x257 = kk_std_num_ddouble__lp__plus__rp_(_x_x258, _x_x260, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x247, _x_x252, _x_x257, _ctx);
}
 
// Convert a weekday number to a `:weekday`(starting at Monday (=1) up to Sunday (=7)).
// Takes the integer `i - 1` modulo 7, so `0` or `14` also become Sunday etc.

kk_std_time_date__weekday kk_std_time_date_weekday(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> weekday */ 
  kk_integer_t d;
  kk_integer_t _x_x262 = kk_integer_add_small_const(i, -1, _ctx); /*int*/
  d = kk_integer_mod(_x_x262,(kk_integer_from_small(7)),kk_context()); /*int*/
  bool _match_x208 = kk_integer_eq_borrow(d,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x208) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Mon(_ctx);
  }
  {
    bool _match_x209 = kk_integer_eq_borrow(d,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x209) {
      kk_integer_drop(d, _ctx);
      return kk_std_time_date__new_Tue(_ctx);
    }
    {
      bool _match_x210 = kk_integer_eq_borrow(d,(kk_integer_from_small(2)),kk_context()); /*bool*/;
      if (_match_x210) {
        kk_integer_drop(d, _ctx);
        return kk_std_time_date__new_Wed(_ctx);
      }
      {
        bool _match_x211 = kk_integer_eq_borrow(d,(kk_integer_from_small(3)),kk_context()); /*bool*/;
        if (_match_x211) {
          kk_integer_drop(d, _ctx);
          return kk_std_time_date__new_Thu(_ctx);
        }
        {
          bool _match_x212 = kk_integer_eq_borrow(d,(kk_integer_from_small(4)),kk_context()); /*bool*/;
          if (_match_x212) {
            kk_integer_drop(d, _ctx);
            return kk_std_time_date__new_Fri(_ctx);
          }
          {
            bool _match_x213;
            bool _brw_x214 = kk_integer_eq_borrow(d,(kk_integer_from_small(5)),kk_context()); /*bool*/;
            kk_integer_drop(d, _ctx);
            _match_x213 = _brw_x214; /*bool*/
            if (_match_x213) {
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
 
// Return the `:weekday` that comes `n` days after week day `wd`.

kk_std_time_date__weekday kk_std_time_date_weekday_fs__lp__plus__rp_(kk_std_time_date__weekday wd, kk_integer_t n, kk_context_t* _ctx) { /* (wd : weekday, n : int) -> weekday */ 
  kk_integer_t x_0_10028 = kk_std_time_date_int(wd, _ctx); /*int*/;
  kk_integer_t i_10027 = kk_integer_add(x_0_10028,n,kk_context()); /*int*/;
  kk_integer_t d;
  kk_integer_t _x_x263 = kk_integer_add_small_const(i_10027, -1, _ctx); /*int*/
  d = kk_integer_mod(_x_x263,(kk_integer_from_small(7)),kk_context()); /*int*/
  bool _match_x201 = kk_integer_eq_borrow(d,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x201) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Mon(_ctx);
  }
  {
    bool _match_x202 = kk_integer_eq_borrow(d,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x202) {
      kk_integer_drop(d, _ctx);
      return kk_std_time_date__new_Tue(_ctx);
    }
    {
      bool _match_x203 = kk_integer_eq_borrow(d,(kk_integer_from_small(2)),kk_context()); /*bool*/;
      if (_match_x203) {
        kk_integer_drop(d, _ctx);
        return kk_std_time_date__new_Wed(_ctx);
      }
      {
        bool _match_x204 = kk_integer_eq_borrow(d,(kk_integer_from_small(3)),kk_context()); /*bool*/;
        if (_match_x204) {
          kk_integer_drop(d, _ctx);
          return kk_std_time_date__new_Thu(_ctx);
        }
        {
          bool _match_x205 = kk_integer_eq_borrow(d,(kk_integer_from_small(4)),kk_context()); /*bool*/;
          if (_match_x205) {
            kk_integer_drop(d, _ctx);
            return kk_std_time_date__new_Fri(_ctx);
          }
          {
            bool _match_x206;
            bool _brw_x207 = kk_integer_eq_borrow(d,(kk_integer_from_small(5)),kk_context()); /*bool*/;
            kk_integer_drop(d, _ctx);
            _match_x206 = _brw_x207; /*bool*/
            if (_match_x206) {
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
 
// Return the `:weekday` that comes `n` days before week day `wd`.

kk_std_time_date__weekday kk_std_time_date_weekdayint_fs__lp__dash__rp_(kk_std_time_date__weekday wd, kk_integer_t n, kk_context_t* _ctx) { /* (wd : weekday, n : int) -> weekday */ 
  kk_integer_t x_0_10035 = kk_std_time_date_int(wd, _ctx); /*int*/;
  kk_integer_t i_10034 = kk_integer_sub(x_0_10035,n,kk_context()); /*int*/;
  kk_integer_t d;
  kk_integer_t _x_x265 = kk_integer_add_small_const(i_10034, -1, _ctx); /*int*/
  d = kk_integer_mod(_x_x265,(kk_integer_from_small(7)),kk_context()); /*int*/
  bool _match_x194 = kk_integer_eq_borrow(d,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x194) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Mon(_ctx);
  }
  {
    bool _match_x195 = kk_integer_eq_borrow(d,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x195) {
      kk_integer_drop(d, _ctx);
      return kk_std_time_date__new_Tue(_ctx);
    }
    {
      bool _match_x196 = kk_integer_eq_borrow(d,(kk_integer_from_small(2)),kk_context()); /*bool*/;
      if (_match_x196) {
        kk_integer_drop(d, _ctx);
        return kk_std_time_date__new_Wed(_ctx);
      }
      {
        bool _match_x197 = kk_integer_eq_borrow(d,(kk_integer_from_small(3)),kk_context()); /*bool*/;
        if (_match_x197) {
          kk_integer_drop(d, _ctx);
          return kk_std_time_date__new_Thu(_ctx);
        }
        {
          bool _match_x198 = kk_integer_eq_borrow(d,(kk_integer_from_small(4)),kk_context()); /*bool*/;
          if (_match_x198) {
            kk_integer_drop(d, _ctx);
            return kk_std_time_date__new_Fri(_ctx);
          }
          {
            bool _match_x199;
            bool _brw_x200 = kk_integer_eq_borrow(d,(kk_integer_from_small(5)),kk_context()); /*bool*/;
            kk_integer_drop(d, _ctx);
            _match_x199 = _brw_x200; /*bool*/
            if (_match_x199) {
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
  bool _match_x170;
  kk_integer_t _brw_x192;
  {
    kk_integer_t _x = d.year;
    kk_integer_dup(_x, _ctx);
    _brw_x192 = _x; /*int*/
  }
  kk_integer_t _brw_x191;
  {
    kk_integer_t _x_0 = e.year;
    kk_integer_dup(_x_0, _ctx);
    _brw_x191 = _x_0; /*int*/
  }
  bool _brw_x193 = kk_integer_eq_borrow(_brw_x192,_brw_x191,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x192, _ctx);
  kk_integer_drop(_brw_x191, _ctx);
  _match_x170 = _brw_x193; /*bool*/
  if (_match_x170) {
    bool _match_x175;
    kk_integer_t _brw_x189;
    {
      kk_integer_t _x_1 = d.month;
      kk_integer_dup(_x_1, _ctx);
      _brw_x189 = _x_1; /*int*/
    }
    kk_integer_t _brw_x188;
    {
      kk_integer_t _x_2 = e.month;
      kk_integer_dup(_x_2, _ctx);
      _brw_x188 = _x_2; /*int*/
    }
    bool _brw_x190 = kk_integer_eq_borrow(_brw_x189,_brw_x188,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x189, _ctx);
    kk_integer_drop(_brw_x188, _ctx);
    _match_x175 = _brw_x190; /*bool*/
    if (_match_x175) {
      bool _match_x180;
      kk_integer_t _brw_x186;
      {
        kk_integer_t _x_3 = d.day;
        kk_integer_dup(_x_3, _ctx);
        _brw_x186 = _x_3; /*int*/
      }
      kk_integer_t _brw_x185;
      {
        kk_integer_t _x_4 = e.day;
        kk_integer_dup(_x_4, _ctx);
        _brw_x185 = _x_4; /*int*/
      }
      bool _brw_x187 = kk_integer_eq_borrow(_brw_x186,_brw_x185,kk_context()); /*bool*/;
      kk_integer_drop(_brw_x186, _ctx);
      kk_integer_drop(_brw_x185, _ctx);
      _match_x180 = _brw_x187; /*bool*/
      if (_match_x180) {
        kk_std_time_date__date_drop(e, _ctx);
        kk_std_time_date__date_drop(d, _ctx);
        return kk_std_core_types__new_Eq(_ctx);
      }
      {
        bool _match_x181;
        kk_integer_t _brw_x183;
        {
          kk_integer_t _x_3_0 = d.day;
          kk_integer_dup(_x_3_0, _ctx);
          kk_std_time_date__date_drop(d, _ctx);
          _brw_x183 = _x_3_0; /*int*/
        }
        kk_integer_t _brw_x182;
        {
          kk_integer_t _x_4_0 = e.day;
          kk_integer_dup(_x_4_0, _ctx);
          kk_std_time_date__date_drop(e, _ctx);
          _brw_x182 = _x_4_0; /*int*/
        }
        bool _brw_x184 = kk_integer_gt_borrow(_brw_x183,_brw_x182,kk_context()); /*bool*/;
        kk_integer_drop(_brw_x183, _ctx);
        kk_integer_drop(_brw_x182, _ctx);
        _match_x181 = _brw_x184; /*bool*/
        if (_match_x181) {
          return kk_std_core_types__new_Gt(_ctx);
        }
        {
          return kk_std_core_types__new_Lt(_ctx);
        }
      }
    }
    {
      bool _match_x176;
      kk_integer_t _brw_x178;
      {
        kk_integer_t _x_1_0 = d.month;
        kk_integer_dup(_x_1_0, _ctx);
        kk_std_time_date__date_drop(d, _ctx);
        _brw_x178 = _x_1_0; /*int*/
      }
      kk_integer_t _brw_x177;
      {
        kk_integer_t _x_2_0 = e.month;
        kk_integer_dup(_x_2_0, _ctx);
        kk_std_time_date__date_drop(e, _ctx);
        _brw_x177 = _x_2_0; /*int*/
      }
      bool _brw_x179 = kk_integer_gt_borrow(_brw_x178,_brw_x177,kk_context()); /*bool*/;
      kk_integer_drop(_brw_x178, _ctx);
      kk_integer_drop(_brw_x177, _ctx);
      _match_x176 = _brw_x179; /*bool*/
      if (_match_x176) {
        return kk_std_core_types__new_Gt(_ctx);
      }
      {
        return kk_std_core_types__new_Lt(_ctx);
      }
    }
  }
  {
    bool _match_x171;
    kk_integer_t _brw_x173;
    {
      kk_integer_t _x_5 = d.year;
      kk_integer_dup(_x_5, _ctx);
      kk_std_time_date__date_drop(d, _ctx);
      _brw_x173 = _x_5; /*int*/
    }
    kk_integer_t _brw_x172;
    {
      kk_integer_t _x_0_0 = e.year;
      kk_integer_dup(_x_0_0, _ctx);
      kk_std_time_date__date_drop(e, _ctx);
      _brw_x172 = _x_0_0; /*int*/
    }
    bool _brw_x174 = kk_integer_gt_borrow(_brw_x173,_brw_x172,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x173, _ctx);
    kk_integer_drop(_brw_x172, _ctx);
    _match_x171 = _brw_x174; /*bool*/
    if (_match_x171) {
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
  kk_integer_t x_10054;
  kk_integer_t _x_x267;
  {
    struct kk_std_time_date_Clock* _con_x268 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1 = _con_x268->seconds;
    kk_integer_t _x = _con_x268->hours;
    kk_integer_dup(_x, _ctx);
    _x_x267 = _x; /*int*/
  }
  x_10054 = kk_integer_mul(_x_x267,(kk_integer_from_small(60)),kk_context()); /*int*/
  kk_integer_t i_10053;
  kk_integer_t _x_x269;
  kk_integer_t _x_x270;
  {
    struct kk_std_time_date_Clock* _con_x271 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_0 = _con_x271->seconds;
    kk_integer_t _x_0 = _con_x271->minutes;
    kk_integer_dup(_x_0, _ctx);
    _x_x270 = _x_0; /*int*/
  }
  _x_x269 = kk_integer_add(x_10054,_x_x270,kk_context()); /*int*/
  i_10053 = kk_integer_mul(_x_x269,(kk_integer_from_small(60)),kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x272 = kk_std_num_ddouble_ddouble_int_exp(i_10053, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x273;
  {
    struct kk_std_time_date_Clock* _con_x274 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x274->seconds;
    kk_integer_t _pat_0_1 = _con_x274->hours;
    kk_integer_t _pat_1_1 = _con_x274->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_1, _ctx);
      kk_integer_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x273 = _x_1; /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__lp__plus__rp_(_x_x272, _x_x273, _ctx);
}
 
// Compare weekdays.

kk_std_core_types__order kk_std_time_date_weekday_fs_cmp(kk_std_time_date__weekday wd1, kk_std_time_date__weekday wd2, kk_context_t* _ctx) { /* (wd1 : weekday, wd2 : weekday) -> order */ 
  kk_integer_t x_10063 = kk_std_time_date_int(wd1, _ctx); /*int*/;
  kk_integer_t y_10064 = kk_std_time_date_int(wd2, _ctx); /*int*/;
  bool _match_x162 = kk_integer_eq_borrow(x_10063,y_10064,kk_context()); /*bool*/;
  if (_match_x162) {
    kk_integer_drop(y_10064, _ctx);
    kk_integer_drop(x_10063, _ctx);
    return kk_std_core_types__new_Eq(_ctx);
  }
  {
    bool _match_x163;
    bool _brw_x164 = kk_integer_gt_borrow(x_10063,y_10064,kk_context()); /*bool*/;
    kk_integer_drop(x_10063, _ctx);
    kk_integer_drop(y_10064, _ctx);
    _match_x163 = _brw_x164; /*bool*/
    if (_match_x163) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}

kk_std_time_date__clock kk_std_time_date_clock_fs__copy(kk_std_time_date__clock _this, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional seconds, kk_context_t* _ctx) { /* (clock, hours : ? int, minutes : ? int, seconds : ? std/num/ddouble/ddouble) -> clock */ 
  kk_integer_t _x_x288;
  if (kk_std_core_types__is_Optional(hours, _ctx)) {
    kk_box_t _box_x3 = hours._cons._Optional.value;
    kk_integer_t _uniq_hours_2866 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_hours_2866, _ctx);
    kk_std_core_types__optional_drop(hours, _ctx);
    _x_x288 = _uniq_hours_2866; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hours, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x289 = kk_std_time_date__as_Clock(_this, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_0 = _con_x289->seconds;
      kk_integer_t _x = _con_x289->hours;
      kk_integer_dup(_x, _ctx);
      _x_x288 = _x; /*int*/
    }
  }
  kk_integer_t _x_x290;
  if (kk_std_core_types__is_Optional(minutes, _ctx)) {
    kk_box_t _box_x4 = minutes._cons._Optional.value;
    kk_integer_t _uniq_minutes_2874 = kk_integer_unbox(_box_x4, _ctx);
    kk_integer_dup(_uniq_minutes_2874, _ctx);
    kk_std_core_types__optional_drop(minutes, _ctx);
    _x_x290 = _uniq_minutes_2874; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(minutes, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x291 = kk_std_time_date__as_Clock(_this, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_2 = _con_x291->seconds;
      kk_integer_t _x_0 = _con_x291->minutes;
      kk_integer_dup(_x_0, _ctx);
      _x_x290 = _x_0; /*int*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x292;
  if (kk_std_core_types__is_Optional(seconds, _ctx)) {
    kk_box_t _box_x5 = seconds._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_seconds_2882 = kk_std_num_ddouble__ddouble_unbox(_box_x5, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(seconds, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x292 = _uniq_seconds_2882; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_core_types__optional_drop(seconds, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x293 = kk_std_time_date__as_Clock(_this, _ctx);
      kk_std_num_ddouble__ddouble _x_1 = _con_x293->seconds;
      kk_integer_t _pat_0_2 = _con_x293->hours;
      kk_integer_t _pat_1_3 = _con_x293->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_3, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x292 = _x_1; /*std/num/ddouble/ddouble*/
    }
  }
  return kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x288, _x_x290, _x_x292, _ctx);
}
 
// Create a clock from a seconds as an `:int` with an optional fraction.
// Normalizes the clock with seconds and minutes under 60 but
// adds the fraction as is to the final seconds, so that might
// be `>= 60` if the fraction `>= 1.0`;

kk_std_time_date__clock kk_std_time_date_intddouble_fs_clock(kk_integer_t seconds, kk_std_core_types__optional frac, kk_context_t* _ctx) { /* (seconds : int, frac : ? std/num/ddouble/ddouble) -> clock */ 
  kk_std_core_types__tuple2 _match_x144 = kk_std_core_int_divmod(seconds, kk_integer_from_small(60), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x6 = _match_x144.fst;
    kk_box_t _box_x7 = _match_x144.snd;
    kk_integer_t hm = kk_integer_unbox(_box_x6, _ctx);
    kk_integer_t s = kk_integer_unbox(_box_x7, _ctx);
    kk_integer_dup(hm, _ctx);
    kk_integer_dup(s, _ctx);
    kk_std_core_types__tuple2_drop(_match_x144, _ctx);
    kk_std_core_types__tuple2 _match_x145 = kk_std_core_int_divmod(hm, kk_integer_from_small(60), _ctx); /*(int, int)*/;
    {
      kk_box_t _box_x8 = _match_x145.fst;
      kk_box_t _box_x9 = _match_x145.snd;
      kk_integer_t h = kk_integer_unbox(_box_x8, _ctx);
      kk_integer_t m = kk_integer_unbox(_box_x9, _ctx);
      kk_integer_dup(h, _ctx);
      kk_integer_dup(m, _ctx);
      kk_std_core_types__tuple2_drop(_match_x145, _ctx);
      kk_std_num_ddouble__ddouble _x_x294;
      kk_std_num_ddouble__ddouble _x_x295 = kk_std_num_ddouble_ddouble_int_exp(s, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x296;
      if (kk_std_core_types__is_Optional(frac, _ctx)) {
        kk_box_t _box_x10 = frac._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_frac_2896 = kk_std_num_ddouble__ddouble_unbox(_box_x10, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(frac, _ctx);
        _x_x296 = _uniq_frac_2896; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_core_types__optional_drop(frac, _ctx);
        _x_x296 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
      }
      _x_x294 = kk_std_num_ddouble__lp__plus__rp_(_x_x295, _x_x296, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_time_date__new_Clock(kk_reuse_null, 0, h, m, _x_x294, _ctx);
    }
  }
}
 
// Create a clock from seconds; normalizes the clock with seconds and minutes under 60.

kk_std_time_date__clock kk_std_time_date_ddouble_fs_clock(kk_std_num_ddouble__ddouble seconds, kk_context_t* _ctx) { /* (seconds : std/num/ddouble/ddouble) -> clock */ 
  kk_integer_t seconds_0_10085;
  kk_std_num_ddouble__ddouble _x_x297 = kk_std_num_ddouble_floor(seconds, _ctx); /*std/num/ddouble/ddouble*/
  seconds_0_10085 = kk_std_num_ddouble_int(_x_x297, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_std_num_ddouble__ddouble _b_x11_12 = kk_std_num_ddouble_ffraction(seconds, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_core_types__tuple2 _match_x141 = kk_std_core_int_divmod(seconds_0_10085, kk_integer_from_small(60), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x13 = _match_x141.fst;
    kk_box_t _box_x14 = _match_x141.snd;
    kk_integer_t hm = kk_integer_unbox(_box_x13, _ctx);
    kk_integer_t s = kk_integer_unbox(_box_x14, _ctx);
    kk_integer_dup(hm, _ctx);
    kk_integer_dup(s, _ctx);
    kk_std_core_types__tuple2_drop(_match_x141, _ctx);
    kk_std_core_types__tuple2 _match_x142 = kk_std_core_int_divmod(hm, kk_integer_from_small(60), _ctx); /*(int, int)*/;
    {
      kk_box_t _box_x15 = _match_x142.fst;
      kk_box_t _box_x16 = _match_x142.snd;
      kk_integer_t h = kk_integer_unbox(_box_x15, _ctx);
      kk_integer_t m = kk_integer_unbox(_box_x16, _ctx);
      kk_integer_dup(h, _ctx);
      kk_integer_dup(m, _ctx);
      kk_std_core_types__tuple2_drop(_match_x142, _ctx);
      kk_std_num_ddouble__ddouble _x_x298;
      kk_std_num_ddouble__ddouble _x_x299 = kk_std_num_ddouble_ddouble_int_exp(s, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x300;
      kk_std_core_types__optional _match_x143 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(_b_x11_12, _ctx), _ctx); /*? 0*/;
      if (kk_std_core_types__is_Optional(_match_x143, _ctx)) {
        kk_box_t _box_x17 = _match_x143._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_frac_2896 = kk_std_num_ddouble__ddouble_unbox(_box_x17, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x143, _ctx);
        _x_x300 = _uniq_frac_2896; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x143, _ctx);
        _x_x300 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
      }
      _x_x298 = kk_std_num_ddouble__lp__plus__rp_(_x_x299, _x_x300, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_time_date__new_Clock(kk_reuse_null, 0, h, m, _x_x298, _ctx);
    }
  }
}
 
// Create a clock from a seconds as an `:int` with an optional fraction.
// Normalizes the clock with seconds and minutes under 60 but
// adds the fraction as is to the final seconds, so that might
// be `>= 60` if the fraction `>= 1.0`;

kk_std_time_date__clock kk_std_time_date_intfloat64_fs_clock(kk_integer_t seconds, double frac, kk_context_t* _ctx) { /* (seconds : int, frac : float64) -> clock */ 
  kk_std_core_types__tuple2 _match_x139 = kk_std_core_int_divmod(seconds, kk_integer_from_small(60), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x18 = _match_x139.fst;
    kk_box_t _box_x19 = _match_x139.snd;
    kk_integer_t hm = kk_integer_unbox(_box_x18, _ctx);
    kk_integer_t s = kk_integer_unbox(_box_x19, _ctx);
    kk_integer_dup(hm, _ctx);
    kk_integer_dup(s, _ctx);
    kk_std_core_types__tuple2_drop(_match_x139, _ctx);
    kk_std_core_types__tuple2 _match_x140 = kk_std_core_int_divmod(hm, kk_integer_from_small(60), _ctx); /*(int, int)*/;
    {
      kk_box_t _box_x20 = _match_x140.fst;
      kk_box_t _box_x21 = _match_x140.snd;
      kk_integer_t h = kk_integer_unbox(_box_x20, _ctx);
      kk_integer_t m = kk_integer_unbox(_box_x21, _ctx);
      kk_integer_dup(h, _ctx);
      kk_integer_dup(m, _ctx);
      kk_std_core_types__tuple2_drop(_match_x140, _ctx);
      kk_std_num_ddouble__ddouble _x_x301;
      kk_std_num_ddouble__ddouble _x_x302 = kk_std_num_ddouble_ddouble_int_exp(s, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x303 = kk_std_num_ddouble__new_Ddouble(frac, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      _x_x301 = kk_std_num_ddouble__lp__plus__rp_(_x_x302, _x_x303, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_time_date__new_Clock(kk_reuse_null, 0, h, m, _x_x301, _ctx);
    }
  }
}

kk_std_time_date__clock kk_std_time_date_leap_fs_clock(kk_std_num_ddouble__ddouble seconds, kk_integer_t leap, kk_context_t* _ctx) { /* (seconds : std/num/ddouble/ddouble, leap : int) -> clock */ 
  kk_integer_t seconds_0_10092;
  kk_std_num_ddouble__ddouble _x_x304 = kk_std_num_ddouble_floor(seconds, _ctx); /*std/num/ddouble/ddouble*/
  seconds_0_10092 = kk_std_num_ddouble_int(_x_x304, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_std_num_ddouble__ddouble _b_x22_23;
  kk_std_num_ddouble__ddouble _x_x305 = kk_std_num_ddouble_ffraction(seconds, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x306 = kk_std_num_ddouble_ddouble_int_exp(leap, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  _b_x22_23 = kk_std_num_ddouble__lp__plus__rp_(_x_x305, _x_x306, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__tuple2 _match_x136 = kk_std_core_int_divmod(seconds_0_10092, kk_integer_from_small(60), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x24 = _match_x136.fst;
    kk_box_t _box_x25 = _match_x136.snd;
    kk_integer_t hm = kk_integer_unbox(_box_x24, _ctx);
    kk_integer_t s = kk_integer_unbox(_box_x25, _ctx);
    kk_integer_dup(hm, _ctx);
    kk_integer_dup(s, _ctx);
    kk_std_core_types__tuple2_drop(_match_x136, _ctx);
    kk_std_core_types__tuple2 _match_x137 = kk_std_core_int_divmod(hm, kk_integer_from_small(60), _ctx); /*(int, int)*/;
    {
      kk_box_t _box_x26 = _match_x137.fst;
      kk_box_t _box_x27 = _match_x137.snd;
      kk_integer_t h = kk_integer_unbox(_box_x26, _ctx);
      kk_integer_t m = kk_integer_unbox(_box_x27, _ctx);
      kk_integer_dup(h, _ctx);
      kk_integer_dup(m, _ctx);
      kk_std_core_types__tuple2_drop(_match_x137, _ctx);
      kk_std_num_ddouble__ddouble _x_x307;
      kk_std_num_ddouble__ddouble _x_x308 = kk_std_num_ddouble_ddouble_int_exp(s, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x309;
      kk_std_core_types__optional _match_x138 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(_b_x22_23, _ctx), _ctx); /*? 0*/;
      if (kk_std_core_types__is_Optional(_match_x138, _ctx)) {
        kk_box_t _box_x28 = _match_x138._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_frac_2896 = kk_std_num_ddouble__ddouble_unbox(_box_x28, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x138, _ctx);
        _x_x309 = _uniq_frac_2896; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x138, _ctx);
        _x_x309 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
      }
      _x_x307 = kk_std_num_ddouble__lp__plus__rp_(_x_x308, _x_x309, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_time_date__new_Clock(kk_reuse_null, 0, h, m, _x_x307, _ctx);
    }
  }
}
 
// The zero clock

kk_std_time_date__clock kk_std_time_date_clock0;
 
// Is this a zero clock?

bool kk_std_time_date_is_zero(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> bool */ 
  bool _match_x130;
  kk_integer_t _brw_x134;
  {
    struct kk_std_time_date_Clock* _con_x310 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1 = _con_x310->seconds;
    kk_integer_t _x = _con_x310->hours;
    kk_integer_dup(_x, _ctx);
    _brw_x134 = _x; /*int*/
  }
  bool _brw_x135 = kk_integer_is_zero_borrow(_brw_x134); /*bool*/;
  kk_integer_drop(_brw_x134, _ctx);
  _match_x130 = _brw_x135; /*bool*/
  if (_match_x130) {
    bool _match_x131;
    kk_integer_t _brw_x132;
    {
      struct kk_std_time_date_Clock* _con_x311 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_0 = _con_x311->seconds;
      kk_integer_t _x_0 = _con_x311->minutes;
      kk_integer_dup(_x_0, _ctx);
      _brw_x132 = _x_0; /*int*/
    }
    bool _brw_x133 = kk_integer_is_zero_borrow(_brw_x132); /*bool*/;
    kk_integer_drop(_brw_x132, _ctx);
    _match_x131 = _brw_x133; /*bool*/
    if (_match_x131) {
      double _x_x312;
      {
        struct kk_std_time_date_Clock* _con_x313 = kk_std_time_date__as_Clock(c, _ctx);
        kk_std_num_ddouble__ddouble _x_2 = _con_x313->seconds;
        kk_integer_t _pat_0_3 = _con_x313->hours;
        kk_integer_t _pat_1_1 = _con_x313->minutes;
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
          _x_x312 = _x_1; /*float64*/
        }
      }
      return (_x_x312 == (0x0p+0));
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
  kk_std_num_ddouble__ddouble y_10247;
  bool _match_x129;
  double _x_x314;
  {
    struct kk_std_time_date_Clock* _con_x315 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x315->seconds;
    {
      double _x_0 = _x_1.hi;
      _x_x314 = _x_0; /*float64*/
    }
  }
  _match_x129 = (_x_x314 < (0x0p+0)); /*bool*/
  if (_match_x129) {
    kk_std_num_ddouble__ddouble _x_x316;
    {
      struct kk_std_time_date_Clock* _con_x317 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _x_1_0 = _con_x317->seconds;
      _x_x316 = _x_1_0; /*std/num/ddouble/ddouble*/
    }
    y_10247 = kk_std_num_ddouble_ceiling(_x_x316, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x318;
    {
      struct kk_std_time_date_Clock* _con_x319 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _x_1_1 = _con_x319->seconds;
      _x_x318 = _x_1_1; /*std/num/ddouble/ddouble*/
    }
    y_10247 = kk_std_num_ddouble_floor(_x_x318, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble x_10101;
  kk_std_num_ddouble__ddouble _x_x320;
  {
    struct kk_std_time_date_Clock* _con_x321 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_1_2 = _con_x321->seconds;
    kk_integer_t _pat_0_2_2 = _con_x321->hours;
    kk_integer_t _pat_1_1_2 = _con_x321->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_1_2, _ctx);
      kk_integer_drop(_pat_0_2_2, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x320 = _x_1_2; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x322;
  double _x_x323;
  double _x_x324;
  {
    double _x_0_0 = y_10247.hi;
    _x_x324 = _x_0_0; /*float64*/
  }
  _x_x323 = (-_x_x324); /*float64*/
  double _x_x325;
  double _x_x326;
  {
    double _x_0_0_0 = y_10247.lo;
    _x_x326 = _x_0_0_0; /*float64*/
  }
  _x_x325 = (-_x_x326); /*float64*/
  _x_x322 = kk_std_num_ddouble__new_Ddouble(_x_x323, _x_x325, _ctx); /*std/num/ddouble/ddouble*/
  x_10101 = kk_std_num_ddouble__lp__plus__rp_(_x_x320, _x_x322, _ctx); /*std/num/ddouble/ddouble*/
  double d_10100;
  double _x_x327;
  {
    double _x = x_10101.hi;
    _x_x327 = _x; /*float64*/
  }
  d_10100 = (_x_x327 * (0x1.f4p9)); /*float64*/
  double _x_x328;
  bool _match_x128 = (d_10100 >= (0x0p+0)); /*bool*/;
  if (_match_x128) {
    _x_x328 = floor(d_10100); /*float64*/
  }
  else {
    _x_x328 = ceil(d_10100); /*float64*/
  }
  return kk_integer_from_double(_x_x328,kk_context());
}
 
// Return the fraction of seconds as nano-seconds ((10^-9^).

kk_integer_t kk_std_time_date_nano_seconds(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> int */ 
  kk_std_num_ddouble__ddouble y_10247;
  bool _match_x127;
  double _x_x329;
  {
    struct kk_std_time_date_Clock* _con_x330 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x330->seconds;
    {
      double _x_0 = _x_1.hi;
      _x_x329 = _x_0; /*float64*/
    }
  }
  _match_x127 = (_x_x329 < (0x0p+0)); /*bool*/
  if (_match_x127) {
    kk_std_num_ddouble__ddouble _x_x331;
    {
      struct kk_std_time_date_Clock* _con_x332 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _x_1_0 = _con_x332->seconds;
      _x_x331 = _x_1_0; /*std/num/ddouble/ddouble*/
    }
    y_10247 = kk_std_num_ddouble_ceiling(_x_x331, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x333;
    {
      struct kk_std_time_date_Clock* _con_x334 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _x_1_1 = _con_x334->seconds;
      _x_x333 = _x_1_1; /*std/num/ddouble/ddouble*/
    }
    y_10247 = kk_std_num_ddouble_floor(_x_x333, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble x_10105;
  kk_std_num_ddouble__ddouble _x_x335;
  {
    struct kk_std_time_date_Clock* _con_x336 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_1_2 = _con_x336->seconds;
    kk_integer_t _pat_0_2_2 = _con_x336->hours;
    kk_integer_t _pat_1_1_2 = _con_x336->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_1_2, _ctx);
      kk_integer_drop(_pat_0_2_2, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x335 = _x_1_2; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x337;
  double _x_x338;
  double _x_x339;
  {
    double _x_0_0 = y_10247.hi;
    _x_x339 = _x_0_0; /*float64*/
  }
  _x_x338 = (-_x_x339); /*float64*/
  double _x_x340;
  double _x_x341;
  {
    double _x_0_0_0 = y_10247.lo;
    _x_x341 = _x_0_0_0; /*float64*/
  }
  _x_x340 = (-_x_x341); /*float64*/
  _x_x337 = kk_std_num_ddouble__new_Ddouble(_x_x338, _x_x340, _ctx); /*std/num/ddouble/ddouble*/
  x_10105 = kk_std_num_ddouble__lp__plus__rp_(_x_x335, _x_x337, _ctx); /*std/num/ddouble/ddouble*/
  double d_10104;
  double _x_x342;
  {
    double _x = x_10105.hi;
    _x_x342 = _x; /*float64*/
  }
  d_10104 = (_x_x342 * (0x1.dcd65p29)); /*float64*/
  double _x_x343;
  bool _match_x126 = (d_10104 >= (0x0p+0)); /*bool*/;
  if (_match_x126) {
    _x_x343 = floor(d_10104); /*float64*/
  }
  else {
    _x_x343 = ceil(d_10104); /*float64*/
  }
  return kk_integer_from_double(_x_x343,kk_context());
}
 
// Round a clock time to a certain number of digits precision (of the fraction of seconds) (default `9`, nano seconds).

kk_std_time_date__clock kk_std_time_date_round_to_prec(kk_std_time_date__clock c, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (c : clock, prec : ? int) -> clock */ 
  kk_integer_t _x_x344;
  {
    struct kk_std_time_date_Clock* _con_x345 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1 = _con_x345->seconds;
    kk_integer_t _x = _con_x345->hours;
    kk_integer_dup(_x, _ctx);
    _x_x344 = _x; /*int*/
  }
  kk_integer_t _x_x346;
  {
    struct kk_std_time_date_Clock* _con_x347 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_0 = _con_x347->seconds;
    kk_integer_t _x_0 = _con_x347->minutes;
    kk_integer_dup(_x_0, _ctx);
    _x_x346 = _x_0; /*int*/
  }
  kk_std_num_ddouble__ddouble _x_x348;
  bool _match_x120;
  kk_integer_t _brw_x124;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x29 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_3135 = kk_integer_unbox(_box_x29, _ctx);
    kk_integer_dup(_uniq_prec_3135, _ctx);
    _brw_x124 = _uniq_prec_3135; /*int*/
  }
  else {
    _brw_x124 = kk_integer_from_small(9); /*int*/
  }
  bool _brw_x125 = kk_integer_lte_borrow(_brw_x124,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x124, _ctx);
  _match_x120 = _brw_x125; /*bool*/
  if (_match_x120) {
    kk_std_core_types__optional_drop(prec, _ctx);
    kk_std_num_ddouble__ddouble _x_x349;
    {
      struct kk_std_time_date_Clock* _con_x350 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _x_1 = _con_x350->seconds;
      kk_integer_t _pat_0_2 = _con_x350->hours;
      kk_integer_t _pat_1_2 = _con_x350->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
        kk_integer_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(c, _ctx);
      }
      else {
        kk_datatype_ptr_decref(c, _ctx);
      }
      _x_x349 = _x_1; /*std/num/ddouble/ddouble*/
    }
    _x_x348 = kk_std_num_ddouble_round(_x_x349, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_x121;
    kk_integer_t _brw_x122;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x30 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_3135_0 = kk_integer_unbox(_box_x30, _ctx);
      kk_integer_dup(_uniq_prec_3135_0, _ctx);
      _brw_x122 = _uniq_prec_3135_0; /*int*/
    }
    else {
      _brw_x122 = kk_integer_from_small(9); /*int*/
    }
    bool _brw_x123 = kk_integer_gt_borrow(_brw_x122,(kk_integer_from_small(31)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x122, _ctx);
    _match_x121 = _brw_x123; /*bool*/
    if (_match_x121) {
      kk_std_core_types__optional_drop(prec, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x351 = kk_std_time_date__as_Clock(c, _ctx);
        kk_std_num_ddouble__ddouble _x_1_0 = _con_x351->seconds;
        kk_integer_t _pat_0_2_0 = _con_x351->hours;
        kk_integer_t _pat_1_2_0 = _con_x351->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
          kk_integer_drop(_pat_1_2_0, _ctx);
          kk_integer_drop(_pat_0_2_0, _ctx);
          kk_datatype_ptr_free(c, _ctx);
        }
        else {
          kk_datatype_ptr_decref(c, _ctx);
        }
        _x_x348 = _x_1_0; /*std/num/ddouble/ddouble*/
      }
    }
    else {
      kk_std_num_ddouble__ddouble p;
      kk_integer_t _x_x352;
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x31 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3135_1 = kk_integer_unbox(_box_x31, _ctx);
        kk_integer_dup(_uniq_prec_3135_1, _ctx);
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x352 = _uniq_prec_3135_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x352 = kk_integer_from_small(9); /*int*/
      }
      p = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, _x_x352, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x353;
      kk_std_num_ddouble__ddouble _x_x354;
      kk_std_num_ddouble__ddouble _x_x355;
      {
        struct kk_std_time_date_Clock* _con_x356 = kk_std_time_date__as_Clock(c, _ctx);
        kk_std_num_ddouble__ddouble _x_1_1 = _con_x356->seconds;
        kk_integer_t _pat_0_2_1 = _con_x356->hours;
        kk_integer_t _pat_1_2_1 = _con_x356->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
          kk_integer_drop(_pat_1_2_1, _ctx);
          kk_integer_drop(_pat_0_2_1, _ctx);
          kk_datatype_ptr_free(c, _ctx);
        }
        else {
          kk_datatype_ptr_decref(c, _ctx);
        }
        _x_x355 = _x_1_1; /*std/num/ddouble/ddouble*/
      }
      _x_x354 = kk_std_num_ddouble__lp__star__rp_(_x_x355, p, _ctx); /*std/num/ddouble/ddouble*/
      _x_x353 = kk_std_num_ddouble_round(_x_x354, _ctx); /*std/num/ddouble/ddouble*/
      _x_x348 = kk_std_num_ddouble__lp__fs__rp_(_x_x353, p, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  return kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x344, _x_x346, _x_x348, _ctx);
}
 
// Show seconds

kk_string_t kk_std_time_date_show_seconds(kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx) { /* (secs : std/num/ddouble/ddouble, max-prec : ? int, secs-width : ? int, unit : ? string) -> string */ 
  kk_integer_t _b_x33_34;
  kk_integer_t _x_x357;
  kk_integer_t _x_x358;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x32 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_3168 = kk_integer_unbox(_box_x32, _ctx);
    kk_integer_dup(_uniq_max_prec_3168, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x358 = _uniq_max_prec_3168; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x358 = kk_integer_from_small(9); /*int*/
  }
  _x_x357 = kk_integer_abs(_x_x358,kk_context()); /*int*/
  _b_x33_34 = kk_integer_neg(_x_x357,kk_context()); /*int*/
  kk_string_t s;
  kk_std_core_types__optional _x_x359 = kk_std_core_types__new_Optional(kk_integer_box(_b_x33_34, _ctx), _ctx); /*? 10003*/
  s = kk_std_num_ddouble_show_fixed(secs, _x_x359, _ctx); /*string*/
  kk_integer_t i;
  kk_ssize_t _x_x360;
  kk_string_t _x_x361 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x362;
  kk_define_string_literal(, _s_x363, 1, ".", _ctx)
  _x_x362 = kk_string_dup(_s_x363, _ctx); /*string*/
  _x_x360 = kk_string_index_of1(_x_x361,_x_x362,kk_context()); /*ssize_t*/
  i = kk_integer_from_ssize_t(_x_x360,kk_context()); /*int*/
  bool _match_x112 = kk_integer_is_zero_borrow(i); /*bool*/;
  if (_match_x112) {
    kk_std_core_types__optional_drop(unit, _ctx);
    kk_integer_drop(i, _ctx);
    kk_integer_t n;
    kk_string_t _x_x364 = kk_string_dup(s, _ctx); /*string*/
    n = kk_std_core_string_chars_fs_count(_x_x364, _ctx); /*int*/
    bool _match_x117;
    kk_integer_t _brw_x118;
    if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
      kk_box_t _box_x35 = secs_width._cons._Optional.value;
      kk_integer_t _uniq_secs_width_3172 = kk_integer_unbox(_box_x35, _ctx);
      kk_integer_dup(_uniq_secs_width_3172, _ctx);
      _brw_x118 = _uniq_secs_width_3172; /*int*/
    }
    else {
      _brw_x118 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x119 = kk_integer_lte_borrow(_brw_x118,n,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x118, _ctx);
    _match_x117 = _brw_x119; /*bool*/
    if (_match_x117) {
      kk_std_core_types__optional_drop(secs_width, _ctx);
      kk_integer_drop(n, _ctx);
      return s;
    }
    {
      kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10012;
      kk_integer_t _x_x365;
      if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
        kk_box_t _box_x36 = secs_width._cons._Optional.value;
        kk_integer_t _uniq_secs_width_3172_0 = kk_integer_unbox(_box_x36, _ctx);
        kk_integer_dup(_uniq_secs_width_3172_0, _ctx);
        kk_std_core_types__optional_drop(secs_width, _ctx);
        _x_x365 = _uniq_secs_width_3172_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(secs_width, _ctx);
        _x_x365 = kk_integer_from_small(1); /*int*/
      }
      n_0_10012 = kk_integer_sub(_x_x365,n,kk_context()); /*int*/
      kk_string_t _x_x366 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(_x_x366, s, _ctx);
    }
  }
  {
    kk_integer_t _pat_8_0 = kk_integer_add_small_const(i, -1, _ctx); /*int*/;
    kk_integer_t _pat_9_0;
    kk_string_t _x_x367;
    kk_define_string_literal(, _s_x368, 1, ".", _ctx)
    _x_x367 = kk_string_dup(_s_x368, _ctx); /*string*/
    _pat_9_0 = kk_string_len_int(_x_x367,kk_context()); /*int*/
    kk_std_core_sslice__sslice dot_0 = kk_std_core_sslice__new_Sslice(s, _pat_8_0, _pat_9_0, _ctx); /*sslice/sslice*/;
    kk_string_t f_0;
    kk_std_core_sslice__sslice _x_x369;
    kk_std_core_sslice__sslice _x_x370 = kk_std_core_sslice__sslice_dup(dot_0, _ctx); /*sslice/sslice*/
    _x_x369 = kk_std_core_sslice_after(_x_x370, _ctx); /*sslice/sslice*/
    f_0 = kk_std_core_sslice_string(_x_x369, _ctx); /*string*/
    kk_integer_t x_10118_0;
    kk_string_t _x_x371 = kk_string_dup(f_0, _ctx); /*string*/
    x_10118_0 = kk_std_core_string_chars_fs_count(_x_x371, _ctx); /*int*/
    kk_integer_t len3_0;
    kk_integer_t _x_x372;
    kk_integer_t _x_x373 = kk_integer_add_small_const(x_10118_0, 2, _ctx); /*int*/
    _x_x372 = kk_integer_div(_x_x373,(kk_integer_from_small(3)),kk_context()); /*int*/
    len3_0 = kk_integer_mul(_x_x372,(kk_integer_from_small(3)),kk_context()); /*int*/
    kk_string_t s_2_10120_0;
    kk_std_core_sslice__sslice _x_x374;
    {
      kk_string_t s_3_0 = dot_0.str;
      kk_integer_t start_0 = dot_0.start;
      kk_string_dup(s_3_0, _ctx);
      kk_integer_dup(start_0, _ctx);
      kk_std_core_sslice__sslice_drop(dot_0, _ctx);
      _x_x374 = kk_std_core_sslice__new_Sslice(s_3_0, kk_integer_from_small(0), start_0, _ctx); /*sslice/sslice*/
    }
    s_2_10120_0 = kk_std_core_sslice_string(_x_x374, _ctx); /*string*/
    kk_integer_t n_0_0;
    kk_string_t _x_x375 = kk_string_dup(s_2_10120_0, _ctx); /*string*/
    n_0_0 = kk_std_core_string_chars_fs_count(_x_x375, _ctx); /*int*/
    kk_integer_t n_1_0;
    kk_string_t _x_x376 = kk_string_dup(f_0, _ctx); /*string*/
    n_1_0 = kk_std_core_string_chars_fs_count(_x_x376, _ctx); /*int*/
    kk_string_t _x_x377;
    bool _match_x114;
    kk_integer_t _brw_x115;
    if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
      kk_box_t _box_x41 = secs_width._cons._Optional.value;
      kk_integer_t _uniq_secs_width_3172_3 = kk_integer_unbox(_box_x41, _ctx);
      kk_integer_dup(_uniq_secs_width_3172_3, _ctx);
      _brw_x115 = _uniq_secs_width_3172_3; /*int*/
    }
    else {
      _brw_x115 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x116 = kk_integer_lte_borrow(_brw_x115,n_0_0,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x115, _ctx);
    _match_x114 = _brw_x116; /*bool*/
    if (_match_x114) {
      kk_std_core_types__optional_drop(secs_width, _ctx);
      kk_integer_drop(n_0_0, _ctx);
      _x_x377 = s_2_10120_0; /*string*/
    }
    else {
      kk_string_t s_0_10011_0_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10012_0_0;
      kk_integer_t _x_x378;
      if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
        kk_box_t _box_x42 = secs_width._cons._Optional.value;
        kk_integer_t _uniq_secs_width_3172_4 = kk_integer_unbox(_box_x42, _ctx);
        kk_integer_dup(_uniq_secs_width_3172_4, _ctx);
        kk_std_core_types__optional_drop(secs_width, _ctx);
        _x_x378 = _uniq_secs_width_3172_4; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(secs_width, _ctx);
        _x_x378 = kk_integer_from_small(1); /*int*/
      }
      n_0_10012_0_0 = kk_integer_sub(_x_x378,n_0_0,kk_context()); /*int*/
      kk_string_t _x_x379 = kk_std_core_string_repeatz(s_0_10011_0_0, kk_std_core_int_ssize__t(n_0_10012_0_0, _ctx), _ctx); /*string*/
      _x_x377 = kk_std_core_types__lp__plus__plus__rp_(_x_x379, s_2_10120_0, _ctx); /*string*/
    }
    kk_string_t _x_x380;
    kk_string_t _x_x381;
    kk_define_string_literal(, _s_x382, 1, ".", _ctx)
    _x_x381 = kk_string_dup(_s_x382, _ctx); /*string*/
    kk_string_t _x_x383;
    kk_string_t _x_x384;
    bool _match_x113 = kk_integer_lte_borrow(len3_0,n_1_0,kk_context()); /*bool*/;
    if (_match_x113) {
      kk_integer_drop(n_1_0, _ctx);
      kk_integer_drop(len3_0, _ctx);
      _x_x384 = f_0; /*string*/
    }
    else {
      kk_string_t s_0_10015_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10016_0 = kk_integer_sub(len3_0,n_1_0,kk_context()); /*int*/;
      kk_string_t _x_x385 = kk_std_core_string_repeatz(s_0_10015_0, kk_std_core_int_ssize__t(n_0_10016_0, _ctx), _ctx); /*string*/
      _x_x384 = kk_std_core_types__lp__plus__plus__rp_(f_0, _x_x385, _ctx); /*string*/
    }
    kk_string_t _x_x386;
    if (kk_std_core_types__is_Optional(unit, _ctx)) {
      kk_box_t _box_x43 = unit._cons._Optional.value;
      kk_string_t _uniq_unit_3176_0 = kk_string_unbox(_box_x43);
      kk_string_dup(_uniq_unit_3176_0, _ctx);
      kk_std_core_types__optional_drop(unit, _ctx);
      _x_x386 = _uniq_unit_3176_0; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(unit, _ctx);
      _x_x386 = kk_string_empty(); /*string*/
    }
    _x_x383 = kk_std_core_types__lp__plus__plus__rp_(_x_x384, _x_x386, _ctx); /*string*/
    _x_x380 = kk_std_core_types__lp__plus__plus__rp_(_x_x381, _x_x383, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x377, _x_x380, _ctx);
  }
}
 
// Show a `:weekday` as an English string (`Sun.show == "Sunday"`).

kk_string_t kk_std_time_date_weekday_fs_show(kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (wd : weekday) -> string */ 
  if (kk_std_time_date__is_Mon(wd, _ctx)) {
    kk_define_string_literal(, _s_x392, 6, "Monday", _ctx)
    return kk_string_dup(_s_x392, _ctx);
  }
  if (kk_std_time_date__is_Tue(wd, _ctx)) {
    kk_define_string_literal(, _s_x393, 7, "Tuesday", _ctx)
    return kk_string_dup(_s_x393, _ctx);
  }
  if (kk_std_time_date__is_Wed(wd, _ctx)) {
    kk_define_string_literal(, _s_x394, 9, "Wednesday", _ctx)
    return kk_string_dup(_s_x394, _ctx);
  }
  if (kk_std_time_date__is_Thu(wd, _ctx)) {
    kk_define_string_literal(, _s_x395, 8, "Thursday", _ctx)
    return kk_string_dup(_s_x395, _ctx);
  }
  if (kk_std_time_date__is_Fri(wd, _ctx)) {
    kk_define_string_literal(, _s_x396, 6, "Friday", _ctx)
    return kk_string_dup(_s_x396, _ctx);
  }
  if (kk_std_time_date__is_Sat(wd, _ctx)) {
    kk_define_string_literal(, _s_x397, 8, "Saturday", _ctx)
    return kk_string_dup(_s_x397, _ctx);
  }
  {
    kk_define_string_literal(, _s_x398, 6, "Sunday", _ctx)
    return kk_string_dup(_s_x398, _ctx);
  }
}
 
// pad with zeros

kk_string_t kk_std_time_date_show0(kk_integer_t i, kk_std_core_types__optional width, kk_context_t* _ctx) { /* (i : int, width : ? int) -> string */ 
  kk_string_t s_10141 = kk_std_core_int_show(i, _ctx); /*string*/;
  kk_integer_t n;
  kk_string_t _x_x402 = kk_string_dup(s_10141, _ctx); /*string*/
  n = kk_std_core_string_chars_fs_count(_x_x402, _ctx); /*int*/
  bool _match_x95;
  kk_integer_t _brw_x96;
  if (kk_std_core_types__is_Optional(width, _ctx)) {
    kk_box_t _box_x44 = width._cons._Optional.value;
    kk_integer_t _uniq_width_4546 = kk_integer_unbox(_box_x44, _ctx);
    kk_integer_dup(_uniq_width_4546, _ctx);
    _brw_x96 = _uniq_width_4546; /*int*/
  }
  else {
    _brw_x96 = kk_integer_from_small(2); /*int*/
  }
  bool _brw_x97 = kk_integer_lte_borrow(_brw_x96,n,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x96, _ctx);
  _match_x95 = _brw_x97; /*bool*/
  if (_match_x95) {
    kk_std_core_types__optional_drop(width, _ctx);
    kk_integer_drop(n, _ctx);
    return s_10141;
  }
  {
    kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
    kk_integer_t n_0_10012;
    kk_integer_t _x_x403;
    if (kk_std_core_types__is_Optional(width, _ctx)) {
      kk_box_t _box_x45 = width._cons._Optional.value;
      kk_integer_t _uniq_width_4546_0 = kk_integer_unbox(_box_x45, _ctx);
      kk_integer_dup(_uniq_width_4546_0, _ctx);
      kk_std_core_types__optional_drop(width, _ctx);
      _x_x403 = _uniq_width_4546_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(width, _ctx);
      _x_x403 = kk_integer_from_small(2); /*int*/
    }
    n_0_10012 = kk_integer_sub(_x_x403,n,kk_context()); /*int*/
    kk_string_t _x_x404 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x404, s_10141, _ctx);
  }
}
 
// Show a year in ISO format (using 5+ digits and explicit sign for years < 0 or years > 9999)).

kk_string_t kk_std_time_date_show_year(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> string */ 
  bool _match_x88;
  kk_integer_t _brw_x93 = kk_integer_from_int(9999, _ctx); /*int*/;
  bool _brw_x94 = kk_integer_gt_borrow(year,_brw_x93,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x93, _ctx);
  _match_x88 = _brw_x94; /*bool*/
  if (_match_x88) {
    kk_integer_t i_10144 = kk_integer_abs(year,kk_context()); /*int*/;
    kk_string_t s_10146 = kk_std_core_int_show(i_10144, _ctx); /*string*/;
    kk_integer_t n;
    kk_string_t _x_x405 = kk_string_dup(s_10146, _ctx); /*string*/
    n = kk_std_core_string_chars_fs_count(_x_x405, _ctx); /*int*/
    kk_string_t _x_x406;
    kk_define_string_literal(, _s_x407, 1, "+", _ctx)
    _x_x406 = kk_string_dup(_s_x407, _ctx); /*string*/
    kk_string_t _x_x408;
    bool _match_x92 = kk_integer_lte_borrow((kk_integer_from_small(5)),n,kk_context()); /*bool*/;
    if (_match_x92) {
      kk_integer_drop(n, _ctx);
      _x_x408 = s_10146; /*string*/
    }
    else {
      kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10012 = kk_integer_sub((kk_integer_from_small(5)),n,kk_context()); /*int*/;
      kk_string_t _x_x409 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
      _x_x408 = kk_std_core_types__lp__plus__plus__rp_(_x_x409, s_10146, _ctx); /*string*/
    }
    return kk_std_core_types__lp__plus__plus__rp_(_x_x406, _x_x408, _ctx);
  }
  {
    bool _match_x89 = kk_integer_lt_borrow(year,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x89) {
      kk_integer_t i_1_10150 = kk_integer_abs(year,kk_context()); /*int*/;
      kk_string_t s_0_10152 = kk_std_core_int_show(i_1_10150, _ctx); /*string*/;
      kk_integer_t n_0;
      kk_string_t _x_x410 = kk_string_dup(s_0_10152, _ctx); /*string*/
      n_0 = kk_std_core_string_chars_fs_count(_x_x410, _ctx); /*int*/
      kk_string_t _x_x411;
      kk_define_string_literal(, _s_x412, 1, "-", _ctx)
      _x_x411 = kk_string_dup(_s_x412, _ctx); /*string*/
      kk_string_t _x_x413;
      bool _match_x91 = kk_integer_lte_borrow((kk_integer_from_small(5)),n_0,kk_context()); /*bool*/;
      if (_match_x91) {
        kk_integer_drop(n_0, _ctx);
        _x_x413 = s_0_10152; /*string*/
      }
      else {
        kk_string_t s_0_10011_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
        kk_integer_t n_0_10012_0 = kk_integer_sub((kk_integer_from_small(5)),n_0,kk_context()); /*int*/;
        kk_string_t _x_x414 = kk_std_core_string_repeatz(s_0_10011_0, kk_std_core_int_ssize__t(n_0_10012_0, _ctx), _ctx); /*string*/
        _x_x413 = kk_std_core_types__lp__plus__plus__rp_(_x_x414, s_0_10152, _ctx); /*string*/
      }
      return kk_std_core_types__lp__plus__plus__rp_(_x_x411, _x_x413, _ctx);
    }
    {
      kk_integer_t i_2_10155 = kk_integer_abs(year,kk_context()); /*int*/;
      kk_string_t s_1_10157 = kk_std_core_int_show(i_2_10155, _ctx); /*string*/;
      kk_integer_t n_1;
      kk_string_t _x_x415 = kk_string_dup(s_1_10157, _ctx); /*string*/
      n_1 = kk_std_core_string_chars_fs_count(_x_x415, _ctx); /*int*/
      kk_string_t _x_x416 = kk_string_empty(); /*string*/
      kk_string_t _x_x418;
      bool _match_x90 = kk_integer_lte_borrow((kk_integer_from_small(4)),n_1,kk_context()); /*bool*/;
      if (_match_x90) {
        kk_integer_drop(n_1, _ctx);
        _x_x418 = s_1_10157; /*string*/
      }
      else {
        kk_string_t s_0_10011_1 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
        kk_integer_t n_0_10012_1 = kk_integer_sub((kk_integer_from_small(4)),n_1,kk_context()); /*int*/;
        kk_string_t _x_x419 = kk_std_core_string_repeatz(s_0_10011_1, kk_std_core_int_ssize__t(n_0_10012_1, _ctx), _ctx); /*string*/
        _x_x418 = kk_std_core_types__lp__plus__plus__rp_(_x_x419, s_1_10157, _ctx); /*string*/
      }
      return kk_std_core_types__lp__plus__plus__rp_(_x_x416, _x_x418, _ctx);
    }
  }
}
 
// Show a date in ISO format. `Date(2000,1,1).show == "2000-01-01"`.
// Takes an optional `month-prefix` (=`""`) that is used by the ISO week
// and month calendar to add a `"W"` or `"M"` prefix respectively.

kk_string_t kk_std_time_date_show(kk_std_time_date__date d, kk_std_core_types__optional month_prefix, kk_context_t* _ctx) { /* (d : date, month-prefix : ? string) -> string */ 
  kk_integer_t day_width;
  bool _match_x87;
  kk_string_t _x_x420;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x46 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_4332 = kk_string_unbox(_box_x46);
    kk_string_dup(_uniq_month_prefix_4332, _ctx);
    _x_x420 = _uniq_month_prefix_4332; /*string*/
  }
  else {
    _x_x420 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x422;
  kk_define_string_literal(, _s_x423, 1, "W", _ctx)
  _x_x422 = kk_string_dup(_s_x423, _ctx); /*string*/
  _match_x87 = kk_string_is_eq(_x_x420,_x_x422,kk_context()); /*bool*/
  if (_match_x87) {
    day_width = kk_integer_from_small(1); /*int*/
  }
  else {
    day_width = kk_integer_from_small(2); /*int*/
  }
  kk_string_t s_10164;
  kk_integer_t _x_x424;
  {
    kk_integer_t _x_0 = d.month;
    kk_integer_dup(_x_0, _ctx);
    _x_x424 = _x_0; /*int*/
  }
  s_10164 = kk_std_core_int_show(_x_x424, _ctx); /*string*/
  kk_integer_t n;
  kk_string_t _x_x425 = kk_string_dup(s_10164, _ctx); /*string*/
  n = kk_std_core_string_chars_fs_count(_x_x425, _ctx); /*int*/
  kk_string_t s_0_10170;
  kk_integer_t _x_x426;
  {
    kk_integer_t _x_1 = d.day;
    kk_integer_dup(_x_1, _ctx);
    _x_x426 = _x_1; /*int*/
  }
  s_0_10170 = kk_std_core_int_show(_x_x426, _ctx); /*string*/
  kk_integer_t n_0;
  kk_string_t _x_x427 = kk_string_dup(s_0_10170, _ctx); /*string*/
  n_0 = kk_std_core_string_chars_fs_count(_x_x427, _ctx); /*int*/
  kk_string_t _x_x428;
  kk_integer_t _x_x429;
  {
    kk_integer_t _x = d.year;
    kk_integer_dup(_x, _ctx);
    kk_std_time_date__date_drop(d, _ctx);
    _x_x429 = _x; /*int*/
  }
  _x_x428 = kk_std_time_date_show_year(_x_x429, _ctx); /*string*/
  kk_string_t _x_x430;
  kk_string_t _x_x431;
  kk_define_string_literal(, _s_x432, 1, "-", _ctx)
  _x_x431 = kk_string_dup(_s_x432, _ctx); /*string*/
  kk_string_t _x_x433;
  kk_string_t _x_x434;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x47 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_4332_0 = kk_string_unbox(_box_x47);
    kk_string_dup(_uniq_month_prefix_4332_0, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x434 = _uniq_month_prefix_4332_0; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x434 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x436;
  kk_string_t _x_x437;
  bool _match_x82;
  kk_integer_t _brw_x85;
  kk_std_core_types__optional _match_x84 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x84, _ctx)) {
    kk_box_t _box_x48 = _match_x84._cons._Optional.value;
    kk_integer_t _uniq_width_4546 = kk_integer_unbox(_box_x48, _ctx);
    kk_integer_dup(_uniq_width_4546, _ctx);
    kk_std_core_types__optional_drop(_match_x84, _ctx);
    _brw_x85 = _uniq_width_4546; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x84, _ctx);
    _brw_x85 = kk_integer_from_small(2); /*int*/
  }
  bool _brw_x86 = kk_integer_lte_borrow(_brw_x85,n,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x85, _ctx);
  _match_x82 = _brw_x86; /*bool*/
  if (_match_x82) {
    kk_integer_drop(n, _ctx);
    _x_x437 = s_10164; /*string*/
  }
  else {
    kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
    kk_integer_t n_0_10012;
    kk_integer_t _x_x438;
    kk_std_core_types__optional _match_x83 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x83, _ctx)) {
      kk_box_t _box_x49 = _match_x83._cons._Optional.value;
      kk_integer_t _uniq_width_4546_0 = kk_integer_unbox(_box_x49, _ctx);
      kk_integer_dup(_uniq_width_4546_0, _ctx);
      kk_std_core_types__optional_drop(_match_x83, _ctx);
      _x_x438 = _uniq_width_4546_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x83, _ctx);
      _x_x438 = kk_integer_from_small(2); /*int*/
    }
    n_0_10012 = kk_integer_sub(_x_x438,n,kk_context()); /*int*/
    kk_string_t _x_x439 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
    _x_x437 = kk_std_core_types__lp__plus__plus__rp_(_x_x439, s_10164, _ctx); /*string*/
  }
  kk_string_t _x_x440;
  kk_string_t _x_x441;
  kk_define_string_literal(, _s_x442, 1, "-", _ctx)
  _x_x441 = kk_string_dup(_s_x442, _ctx); /*string*/
  kk_string_t _x_x443;
  bool _match_x81 = kk_integer_lte_borrow(day_width,n_0,kk_context()); /*bool*/;
  if (_match_x81) {
    kk_integer_drop(n_0, _ctx);
    kk_integer_drop(day_width, _ctx);
    _x_x443 = s_0_10170; /*string*/
  }
  else {
    kk_string_t s_0_10011_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
    kk_integer_t n_0_10012_0 = kk_integer_sub(day_width,n_0,kk_context()); /*int*/;
    kk_string_t _x_x444 = kk_std_core_string_repeatz(s_0_10011_0, kk_std_core_int_ssize__t(n_0_10012_0, _ctx), _ctx); /*string*/
    _x_x443 = kk_std_core_types__lp__plus__plus__rp_(_x_x444, s_0_10170, _ctx); /*string*/
  }
  _x_x440 = kk_std_core_types__lp__plus__plus__rp_(_x_x441, _x_x443, _ctx); /*string*/
  _x_x436 = kk_std_core_types__lp__plus__plus__rp_(_x_x437, _x_x440, _ctx); /*string*/
  _x_x433 = kk_std_core_types__lp__plus__plus__rp_(_x_x434, _x_x436, _ctx); /*string*/
  _x_x430 = kk_std_core_types__lp__plus__plus__rp_(_x_x431, _x_x433, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x428, _x_x430, _ctx);
}
 
// Show a clock in ISO format up to an optional maximum precision (=`9`).
// `Clock(23,30,fixed(1.123)).show == "23:30:01.123"`
// `Clock(23,30,fixed(1.123)).show(0) == "23:30:01"`

kk_string_t kk_std_time_date_clock_fs_show(kk_std_time_date__clock c, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (c : clock, prec : ? int) -> string */ 
  kk_string_t s_10176;
  kk_integer_t _x_x445;
  {
    struct kk_std_time_date_Clock* _con_x446 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_0 = _con_x446->seconds;
    kk_integer_t _x = _con_x446->hours;
    kk_integer_dup(_x, _ctx);
    _x_x445 = _x; /*int*/
  }
  s_10176 = kk_std_core_int_show(_x_x445, _ctx); /*string*/
  kk_integer_t n;
  kk_string_t _x_x447 = kk_string_dup(s_10176, _ctx); /*string*/
  n = kk_std_core_string_chars_fs_count(_x_x447, _ctx); /*int*/
  kk_string_t s_0_10182;
  kk_integer_t _x_x448;
  {
    struct kk_std_time_date_Clock* _con_x449 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_2 = _con_x449->seconds;
    kk_integer_t _x_0 = _con_x449->minutes;
    kk_integer_dup(_x_0, _ctx);
    _x_x448 = _x_0; /*int*/
  }
  s_0_10182 = kk_std_core_int_show(_x_x448, _ctx); /*string*/
  kk_integer_t n_0;
  kk_string_t _x_x450 = kk_string_dup(s_0_10182, _ctx); /*string*/
  n_0 = kk_std_core_string_chars_fs_count(_x_x450, _ctx); /*int*/
  kk_string_t _x_x451;
  bool _match_x76;
  kk_integer_t _brw_x79;
  kk_std_core_types__optional _match_x78 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x78, _ctx)) {
    kk_box_t _box_x50 = _match_x78._cons._Optional.value;
    kk_integer_t _uniq_width_4546 = kk_integer_unbox(_box_x50, _ctx);
    kk_integer_dup(_uniq_width_4546, _ctx);
    kk_std_core_types__optional_drop(_match_x78, _ctx);
    _brw_x79 = _uniq_width_4546; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x78, _ctx);
    _brw_x79 = kk_integer_from_small(2); /*int*/
  }
  bool _brw_x80 = kk_integer_lte_borrow(_brw_x79,n,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x79, _ctx);
  _match_x76 = _brw_x80; /*bool*/
  if (_match_x76) {
    kk_integer_drop(n, _ctx);
    _x_x451 = s_10176; /*string*/
  }
  else {
    kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
    kk_integer_t n_0_10012;
    kk_integer_t _x_x452;
    kk_std_core_types__optional _match_x77 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x77, _ctx)) {
      kk_box_t _box_x51 = _match_x77._cons._Optional.value;
      kk_integer_t _uniq_width_4546_0 = kk_integer_unbox(_box_x51, _ctx);
      kk_integer_dup(_uniq_width_4546_0, _ctx);
      kk_std_core_types__optional_drop(_match_x77, _ctx);
      _x_x452 = _uniq_width_4546_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x77, _ctx);
      _x_x452 = kk_integer_from_small(2); /*int*/
    }
    n_0_10012 = kk_integer_sub(_x_x452,n,kk_context()); /*int*/
    kk_string_t _x_x453 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
    _x_x451 = kk_std_core_types__lp__plus__plus__rp_(_x_x453, s_10176, _ctx); /*string*/
  }
  kk_string_t _x_x454;
  kk_string_t _x_x455;
  kk_define_string_literal(, _s_x456, 1, ":", _ctx)
  _x_x455 = kk_string_dup(_s_x456, _ctx); /*string*/
  kk_string_t _x_x457;
  kk_string_t _x_x458;
  bool _match_x71;
  kk_integer_t _brw_x74;
  kk_std_core_types__optional _match_x73 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x73, _ctx)) {
    kk_box_t _box_x52 = _match_x73._cons._Optional.value;
    kk_integer_t _uniq_width_4546_0_0 = kk_integer_unbox(_box_x52, _ctx);
    kk_integer_dup(_uniq_width_4546_0_0, _ctx);
    kk_std_core_types__optional_drop(_match_x73, _ctx);
    _brw_x74 = _uniq_width_4546_0_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x73, _ctx);
    _brw_x74 = kk_integer_from_small(2); /*int*/
  }
  bool _brw_x75 = kk_integer_lte_borrow(_brw_x74,n_0,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x74, _ctx);
  _match_x71 = _brw_x75; /*bool*/
  if (_match_x71) {
    kk_integer_drop(n_0, _ctx);
    _x_x458 = s_0_10182; /*string*/
  }
  else {
    kk_string_t s_0_10011_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
    kk_integer_t n_0_10012_0;
    kk_integer_t _x_x459;
    kk_std_core_types__optional _match_x72 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x72, _ctx)) {
      kk_box_t _box_x53 = _match_x72._cons._Optional.value;
      kk_integer_t _uniq_width_4546_0_1 = kk_integer_unbox(_box_x53, _ctx);
      kk_integer_dup(_uniq_width_4546_0_1, _ctx);
      kk_std_core_types__optional_drop(_match_x72, _ctx);
      _x_x459 = _uniq_width_4546_0_1; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x72, _ctx);
      _x_x459 = kk_integer_from_small(2); /*int*/
    }
    n_0_10012_0 = kk_integer_sub(_x_x459,n_0,kk_context()); /*int*/
    kk_string_t _x_x460 = kk_std_core_string_repeatz(s_0_10011_0, kk_std_core_int_ssize__t(n_0_10012_0, _ctx), _ctx); /*string*/
    _x_x458 = kk_std_core_types__lp__plus__plus__rp_(_x_x460, s_0_10182, _ctx); /*string*/
  }
  kk_string_t _x_x461;
  kk_integer_t _b_x55_57;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x54 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_4745 = kk_integer_unbox(_box_x54, _ctx);
    kk_integer_dup(_uniq_prec_4745, _ctx);
    kk_std_core_types__optional_drop(prec, _ctx);
    _b_x55_57 = _uniq_prec_4745; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(prec, _ctx);
    _b_x55_57 = kk_integer_from_small(9); /*int*/
  }
  kk_integer_t _b_x56_58 = kk_integer_from_small(2); /*int*/;
  kk_string_t _x_x462;
  kk_define_string_literal(, _s_x463, 1, ":", _ctx)
  _x_x462 = kk_string_dup(_s_x463, _ctx); /*string*/
  kk_string_t _x_x464;
  kk_std_num_ddouble__ddouble _x_x465;
  {
    struct kk_std_time_date_Clock* _con_x466 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x466->seconds;
    kk_integer_t _pat_0_5 = _con_x466->hours;
    kk_integer_t _pat_1_3 = _con_x466->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_3, _ctx);
      kk_integer_drop(_pat_0_5, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x465 = _x_1; /*std/num/ddouble/ddouble*/
  }
  kk_std_core_types__optional _x_x467 = kk_std_core_types__new_Optional(kk_integer_box(_b_x55_57, _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x468 = kk_std_core_types__new_Optional(kk_integer_box(_b_x56_58, _ctx), _ctx); /*? 10003*/
  _x_x464 = kk_std_time_date_show_seconds(_x_x465, _x_x467, _x_x468, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  _x_x461 = kk_std_core_types__lp__plus__plus__rp_(_x_x462, _x_x464, _ctx); /*string*/
  _x_x457 = kk_std_core_types__lp__plus__plus__rp_(_x_x458, _x_x461, _ctx); /*string*/
  _x_x454 = kk_std_core_types__lp__plus__plus__rp_(_x_x455, _x_x457, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x451, _x_x454, _ctx);
}
 
// Return the whole seconds part of a `:clock`.

kk_integer_t kk_std_time_date_whole_seconds(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> int */ 
  kk_std_num_ddouble__ddouble _x_x469;
  bool _match_x70;
  double _x_x470;
  {
    struct kk_std_time_date_Clock* _con_x471 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_0 = _con_x471->seconds;
    {
      double _x = _x_0.hi;
      _x_x470 = _x; /*float64*/
    }
  }
  _match_x70 = (_x_x470 < (0x0p+0)); /*bool*/
  if (_match_x70) {
    kk_std_num_ddouble__ddouble _x_x472;
    {
      struct kk_std_time_date_Clock* _con_x473 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _x_0_0 = _con_x473->seconds;
      kk_integer_t _pat_0_1_0 = _con_x473->hours;
      kk_integer_t _pat_1_0_0 = _con_x473->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
        kk_integer_drop(_pat_1_0_0, _ctx);
        kk_integer_drop(_pat_0_1_0, _ctx);
        kk_datatype_ptr_free(c, _ctx);
      }
      else {
        kk_datatype_ptr_decref(c, _ctx);
      }
      _x_x472 = _x_0_0; /*std/num/ddouble/ddouble*/
    }
    _x_x469 = kk_std_num_ddouble_ceiling(_x_x472, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x474;
    {
      struct kk_std_time_date_Clock* _con_x475 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _x_0_1 = _con_x475->seconds;
      kk_integer_t _pat_0_1_1 = _con_x475->hours;
      kk_integer_t _pat_1_0_1 = _con_x475->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
        kk_integer_drop(_pat_1_0_1, _ctx);
        kk_integer_drop(_pat_0_1_1, _ctx);
        kk_datatype_ptr_free(c, _ctx);
      }
      else {
        kk_datatype_ptr_decref(c, _ctx);
      }
      _x_x474 = _x_0_1; /*std/num/ddouble/ddouble*/
    }
    _x_x469 = kk_std_num_ddouble_floor(_x_x474, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble_int(_x_x469, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Show a `:weekday` as a 3 letter English string (`Sun.show-short == "Sun"`)

kk_string_t kk_std_time_date_show_short(kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (wd : weekday) -> string */ 
  kk_string_t s_10188 = kk_std_time_date_weekday_fs_show(wd, _ctx); /*string*/;
  kk_std_core_types__optional n_10189 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? int*/;
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s_10188, _ctx); /*sslice/sslice*/;
  kk_std_core_sslice__sslice _x_x476;
  bool _match_x65;
  kk_integer_t _brw_x68;
  if (kk_std_core_types__is_Optional(n_10189, _ctx)) {
    kk_box_t _box_x61 = n_10189._cons._Optional.value;
    kk_integer_t _uniq_n_414 = kk_integer_unbox(_box_x61, _ctx);
    kk_integer_dup(_uniq_n_414, _ctx);
    _brw_x68 = _uniq_n_414; /*int*/
  }
  else {
    _brw_x68 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x69 = kk_integer_eq_borrow(_brw_x68,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x68, _ctx);
  _match_x65 = _brw_x69; /*bool*/
  if (_match_x65) {
    kk_std_core_types__optional_drop(n_10189, _ctx);
    _x_x476 = slice_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x66;
    kk_integer_t _x_x477;
    if (kk_std_core_types__is_Optional(n_10189, _ctx)) {
      kk_box_t _box_x62 = n_10189._cons._Optional.value;
      kk_integer_t _uniq_n_414_0 = kk_integer_unbox(_box_x62, _ctx);
      kk_integer_dup(_uniq_n_414_0, _ctx);
      kk_std_core_types__optional_drop(n_10189, _ctx);
      _x_x477 = _uniq_n_414_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(n_10189, _ctx);
      _x_x477 = kk_integer_from_small(1); /*int*/
    }
    _brw_x66 = kk_integer_add_small_const(_x_x477, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x67 = kk_std_core_sslice_extend(slice_0, _brw_x66, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x66, _ctx);
    _x_x476 = _brw_x67; /*sslice/sslice*/
  }
  return kk_std_core_sslice_string(_x_x476, _ctx);
}
 
// Return the ISO calendar date of Easter in a given year (Algorithm by [J.M. Oudin](https://aa.usno.navy.mil/faq/docs/easter.php)).

kk_std_time_date__date kk_std_time_date_easter(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> date */ 
  kk_integer_t c;
  kk_integer_t _x_x479 = kk_integer_dup(year, _ctx); /*int*/
  c = kk_integer_div(_x_x479,(kk_integer_from_small(100)),kk_context()); /*int*/
  kk_integer_t y_10193;
  kk_integer_t _x_x480;
  kk_integer_t _x_x481 = kk_integer_dup(year, _ctx); /*int*/
  _x_x480 = kk_integer_div(_x_x481,(kk_integer_from_small(19)),kk_context()); /*int*/
  y_10193 = kk_integer_mul((kk_integer_from_small(19)),_x_x480,kk_context()); /*int*/
  kk_integer_t n;
  kk_integer_t _x_x482 = kk_integer_dup(year, _ctx); /*int*/
  n = kk_integer_sub(_x_x482,y_10193,kk_context()); /*int*/
  kk_integer_t k;
  kk_integer_t _x_x483;
  kk_integer_t _x_x484 = kk_integer_dup(c, _ctx); /*int*/
  _x_x483 = kk_integer_add_small_const(_x_x484, -17, _ctx); /*int*/
  k = kk_integer_div(_x_x483,(kk_integer_from_small(25)),kk_context()); /*int*/
  kk_integer_t y_4_10203;
  kk_integer_t _x_x485 = kk_integer_dup(c, _ctx); /*int*/
  y_4_10203 = kk_integer_div(_x_x485,(kk_integer_from_small(4)),kk_context()); /*int*/
  kk_integer_t x_3_10200;
  kk_integer_t _x_x486 = kk_integer_dup(c, _ctx); /*int*/
  x_3_10200 = kk_integer_sub(_x_x486,y_4_10203,kk_context()); /*int*/
  kk_integer_t y_3_10201;
  kk_integer_t _x_x487;
  kk_integer_t _x_x488 = kk_integer_dup(c, _ctx); /*int*/
  _x_x487 = kk_integer_sub(_x_x488,k,kk_context()); /*int*/
  y_3_10201 = kk_integer_div(_x_x487,(kk_integer_from_small(3)),kk_context()); /*int*/
  kk_integer_t x_2_10198 = kk_integer_sub(x_3_10200,y_3_10201,kk_context()); /*int*/;
  kk_integer_t y_2_10199;
  kk_integer_t _x_x489 = kk_integer_dup(n, _ctx); /*int*/
  y_2_10199 = kk_integer_mul((kk_integer_from_small(19)),_x_x489,kk_context()); /*int*/
  kk_integer_t x_1_10196 = kk_integer_add(x_2_10198,y_2_10199,kk_context()); /*int*/;
  kk_integer_t i0 = kk_integer_add_small_const(x_1_10196, 15, _ctx); /*int*/;
  kk_integer_t y_6_10207;
  kk_integer_t _x_x490;
  kk_integer_t _x_x491 = kk_integer_dup(i0, _ctx); /*int*/
  _x_x490 = kk_integer_div(_x_x491,(kk_integer_from_small(30)),kk_context()); /*int*/
  y_6_10207 = kk_integer_mul((kk_integer_from_small(30)),_x_x490,kk_context()); /*int*/
  kk_integer_t i1 = kk_integer_sub(i0,y_6_10207,kk_context()); /*int*/;
  kk_integer_t y_8_10211;
  kk_integer_t _x_x492;
  kk_integer_t _x_x493;
  kk_integer_t _x_x494 = kk_integer_dup(i1, _ctx); /*int*/
  _x_x493 = kk_integer_div(_x_x494,(kk_integer_from_small(28)),kk_context()); /*int*/
  kk_integer_t _x_x495;
  kk_integer_t _x_x496;
  kk_integer_t _x_x497 = kk_integer_dup(i1, _ctx); /*int*/
  _x_x496 = kk_integer_add_small_const(_x_x497, 1, _ctx); /*int*/
  _x_x495 = kk_integer_div((kk_integer_from_small(29)),_x_x496,kk_context()); /*int*/
  _x_x492 = kk_integer_mul(_x_x493,_x_x495,kk_context()); /*int*/
  kk_integer_t _x_x498;
  kk_integer_t _x_x499 = kk_integer_sub((kk_integer_from_small(21)),n,kk_context()); /*int*/
  _x_x498 = kk_integer_div(_x_x499,(kk_integer_from_small(11)),kk_context()); /*int*/
  y_8_10211 = kk_integer_mul(_x_x492,_x_x498,kk_context()); /*int*/
  kk_integer_t y_7_10209;
  kk_integer_t _x_x500;
  kk_integer_t _x_x501 = kk_integer_dup(i1, _ctx); /*int*/
  _x_x500 = kk_integer_div(_x_x501,(kk_integer_from_small(28)),kk_context()); /*int*/
  kk_integer_t _x_x502 = kk_integer_sub((kk_integer_from_small(1)),y_8_10211,kk_context()); /*int*/
  y_7_10209 = kk_integer_mul(_x_x500,_x_x502,kk_context()); /*int*/
  kk_integer_t i = kk_integer_sub(i1,y_7_10209,kk_context()); /*int*/;
  kk_integer_t y_15_10225;
  kk_integer_t _x_x503 = kk_integer_dup(year, _ctx); /*int*/
  y_15_10225 = kk_integer_div(_x_x503,(kk_integer_from_small(4)),kk_context()); /*int*/
  kk_integer_t x_14_10222;
  kk_integer_t _x_x504 = kk_integer_dup(year, _ctx); /*int*/
  x_14_10222 = kk_integer_add(_x_x504,y_15_10225,kk_context()); /*int*/
  kk_integer_t x_13_10220;
  kk_integer_t _x_x505 = kk_integer_dup(i, _ctx); /*int*/
  x_13_10220 = kk_integer_add(x_14_10222,_x_x505,kk_context()); /*int*/
  kk_integer_t x_12_10218 = kk_integer_add_small_const(x_13_10220, 2, _ctx); /*int*/;
  kk_integer_t x_11_10216;
  kk_integer_t _x_x506 = kk_integer_dup(c, _ctx); /*int*/
  x_11_10216 = kk_integer_sub(x_12_10218,_x_x506,kk_context()); /*int*/
  kk_integer_t y_11_10217 = kk_integer_div(c,(kk_integer_from_small(4)),kk_context()); /*int*/;
  kk_integer_t j0 = kk_integer_add(x_11_10216,y_11_10217,kk_context()); /*int*/;
  kk_integer_t y_16_10227;
  kk_integer_t _x_x507;
  kk_integer_t _x_x508 = kk_integer_dup(j0, _ctx); /*int*/
  _x_x507 = kk_integer_div(_x_x508,(kk_integer_from_small(7)),kk_context()); /*int*/
  y_16_10227 = kk_integer_mul((kk_integer_from_small(7)),_x_x507,kk_context()); /*int*/
  kk_integer_t j = kk_integer_sub(j0,y_16_10227,kk_context()); /*int*/;
  kk_integer_t l = kk_integer_sub(i,j,kk_context()); /*int*/;
  kk_integer_t y_18_10231;
  kk_integer_t _x_x509;
  kk_integer_t _x_x510 = kk_integer_dup(l, _ctx); /*int*/
  _x_x509 = kk_integer_add_small_const(_x_x510, 40, _ctx); /*int*/
  y_18_10231 = kk_integer_div(_x_x509,(kk_integer_from_small(44)),kk_context()); /*int*/
  kk_integer_t m = kk_integer_add_small_const(y_18_10231, 3, _ctx); /*int*/;
  kk_integer_t x_20_10234 = kk_integer_add_small_const(l, 28, _ctx); /*int*/;
  kk_integer_t y_20_10235;
  kk_integer_t _x_x511;
  kk_integer_t _x_x512 = kk_integer_dup(m, _ctx); /*int*/
  _x_x511 = kk_integer_div(_x_x512,(kk_integer_from_small(4)),kk_context()); /*int*/
  y_20_10235 = kk_integer_mul((kk_integer_from_small(31)),_x_x511,kk_context()); /*int*/
  kk_integer_t d = kk_integer_sub(x_20_10234,y_20_10235,kk_context()); /*int*/;
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
