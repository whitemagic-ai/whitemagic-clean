// Koka generated module: std/num/ddouble, koka version: 3.2.2, platform: 64-bit
#include "std_num_ddouble.h"

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_fs__copy(kk_std_num_ddouble__ddouble _this, kk_std_core_types__optional hi, kk_std_core_types__optional lo, kk_context_t* _ctx) { /* (ddouble, hi : ? float64, lo : ? float64) -> ddouble */ 
  double _x_x769;
  if (kk_std_core_types__is_Optional(hi, _ctx)) {
    kk_box_t _box_x0 = hi._cons._Optional.value;
    double _uniq_hi_185 = kk_double_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(hi, _ctx);
    _x_x769 = _uniq_hi_185; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(hi, _ctx);
    {
      double _x = _this.hi;
      _x_x769 = _x; /*float64*/
    }
  }
  double _x_x770;
  if (kk_std_core_types__is_Optional(lo, _ctx)) {
    kk_box_t _box_x1 = lo._cons._Optional.value;
    double _uniq_lo_193 = kk_double_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(lo, _ctx);
    _x_x770 = _uniq_lo_193; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(lo, _ctx);
    {
      double _x_0 = _this.lo;
      _x_x770 = _x_0; /*float64*/
    }
  }
  return kk_std_num_ddouble__new_Ddouble(_x_x769, _x_x770, _ctx);
}

kk_integer_t kk_std_num_ddouble_maxprecise;

kk_integer_t kk_std_num_ddouble_minprecise;

bool kk_std_num_ddouble_is_precise(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  bool _match_x759 = kk_integer_gte_borrow(i,kk_std_num_ddouble_minprecise,kk_context()); /*bool*/;
  if (_match_x759) {
    kk_integer_t _brw_x760 = kk_integer_from_str("9007199254740991", _ctx); /*int*/;
    bool _brw_x761 = kk_integer_lte_borrow(i,_brw_x760,kk_context()); /*bool*/;
    kk_integer_drop(i, _ctx);
    kk_integer_drop(_brw_x760, _ctx);
    return _brw_x761;
  }
  {
    kk_integer_drop(i, _ctx);
    return false;
  }
}
 
// Not-A-Number

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_nan;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dquicksum(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> ddouble */ 
  bool b_10018 = isfinite(x); /*bool*/;
  if (b_10018) {
    double z = (x + y); /*float64*/;
    double err;
    double _x_x808 = (z - x); /*float64*/
    err = (y - _x_x808); /*float64*/
    double _x_x809;
    bool _match_x755 = isfinite(z); /*bool*/;
    if (_match_x755) {
      _x_x809 = err; /*float64*/
    }
    else {
      _x_x809 = z; /*float64*/
    }
    return kk_std_num_ddouble__new_Ddouble(z, _x_x809, _ctx);
  }
  {
    return kk_std_num_ddouble__new_Ddouble(x, 0x0p+0, _ctx);
  }
}
 
// Multiply two `:ddouble`s

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  double z;
  double _x_x811;
  {
    double _x = x.hi;
    _x_x811 = _x; /*float64*/
  }
  double _x_x812;
  {
    double _x_0 = y.hi;
    _x_x812 = _x_0; /*float64*/
  }
  z = (_x_x811 * _x_x812); /*float64*/
  double err;
  double _x_x813;
  {
    double _x_1 = x.hi;
    _x_x813 = _x_1; /*float64*/
  }
  double _x_x814;
  {
    double _x_0_0 = y.hi;
    _x_x814 = _x_0_0; /*float64*/
  }
  double _x_x815 = (-z); /*float64*/
  err = kk_std_num_float64_fmadd(_x_x813, _x_x814, _x_x815, _ctx); /*float64*/
  kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
  double e;
  double _x_x816;
  {
    double _x_1_0 = z_0.err;
    _x_x816 = _x_1_0; /*float64*/
  }
  double _x_x817;
  double _x_x818;
  double _x_x819;
  {
    double _x_2 = x.hi;
    _x_x819 = _x_2; /*float64*/
  }
  double _x_x820;
  {
    double _x_3 = y.lo;
    _x_x820 = _x_3; /*float64*/
  }
  _x_x818 = (_x_x819 * _x_x820); /*float64*/
  double _x_x821;
  double _x_x822;
  {
    double _x_4 = x.lo;
    _x_x822 = _x_4; /*float64*/
  }
  double _x_x823;
  {
    double _x_5 = y.hi;
    _x_x823 = _x_5; /*float64*/
  }
  _x_x821 = (_x_x822 * _x_x823); /*float64*/
  _x_x817 = (_x_x818 + _x_x821); /*float64*/
  e = (_x_x816 + _x_x817); /*float64*/
  double _x_x824;
  {
    double _x_6 = z_0.num;
    _x_x824 = _x_6; /*float64*/
  }
  return kk_std_num_ddouble_dquicksum(_x_x824, e, _ctx);
}
 
// As `sum` but with `x.abs >= y.abs`

kk_std_num_ddouble__edouble kk_std_num_ddouble_quicksum(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> edouble */ 
  double z = (x + y); /*float64*/;
  double err;
  double _x_x825 = (z - x); /*float64*/
  err = (y - _x_x825); /*float64*/
  double _x_x826;
  bool _match_x754 = isfinite(z); /*bool*/;
  if (_match_x754) {
    _x_x826 = err; /*float64*/
  }
  else {
    _x_x826 = z; /*float64*/
  }
  return kk_std_num_ddouble__new_Edouble(z, _x_x826, _ctx);
}
 
// often called `twosum` in literature (see [@shewchuk])

kk_std_num_ddouble__edouble kk_std_num_ddouble_sum(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> edouble */ 
  double z = (x + y); /*float64*/;
  double diff = (z - x); /*float64*/;
  double err;
  double _x_x827;
  double _x_x828 = (z - diff); /*float64*/
  _x_x827 = (x - _x_x828); /*float64*/
  double _x_x829 = (y - diff); /*float64*/
  err = (_x_x827 + _x_x829); /*float64*/
  double _x_x830;
  bool _match_x753 = isfinite(z); /*bool*/;
  if (_match_x753) {
    _x_x830 = err; /*float64*/
  }
  else {
    _x_x830 = z; /*float64*/
  }
  return kk_std_num_ddouble__new_Edouble(z, _x_x830, _ctx);
}
 
// Add two `:ddouble`s

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__edouble z1;
  double _x_x831;
  {
    double _x = x.hi;
    _x_x831 = _x; /*float64*/
  }
  double _x_x832;
  {
    double _x_0 = y.hi;
    _x_x832 = _x_0; /*float64*/
  }
  z1 = kk_std_num_ddouble_sum(_x_x831, _x_x832, _ctx); /*std/num/ddouble/edouble*/
  kk_std_num_ddouble__edouble lo;
  double _x_x833;
  {
    double _x_1 = x.lo;
    _x_x833 = _x_1; /*float64*/
  }
  double _x_x834;
  {
    double _x_2 = y.lo;
    _x_x834 = _x_2; /*float64*/
  }
  lo = kk_std_num_ddouble_sum(_x_x833, _x_x834, _ctx); /*std/num/ddouble/edouble*/
  double e1;
  double _x_x835;
  {
    double _x_3 = z1.err;
    _x_x835 = _x_3; /*float64*/
  }
  double _x_x836;
  {
    double _x_4 = lo.num;
    _x_x836 = _x_4; /*float64*/
  }
  e1 = (_x_x835 + _x_x836); /*float64*/
  double z;
  double _x_x837;
  {
    double _x_5 = z1.num;
    _x_x837 = _x_5; /*float64*/
  }
  z = (_x_x837 + e1); /*float64*/
  double err;
  double _x_x838;
  double _x_x839;
  {
    double _x_5_0 = z1.num;
    _x_x839 = _x_5_0; /*float64*/
  }
  _x_x838 = (z - _x_x839); /*float64*/
  err = (e1 - _x_x838); /*float64*/
  kk_std_num_ddouble__edouble z2;
  double _x_x840;
  bool _match_x752 = isfinite(z); /*bool*/;
  if (_match_x752) {
    _x_x840 = err; /*float64*/
  }
  else {
    _x_x840 = z; /*float64*/
  }
  z2 = kk_std_num_ddouble__new_Edouble(z, _x_x840, _ctx); /*std/num/ddouble/edouble*/
  double e2;
  double _x_x841;
  {
    double _x_6 = z2.err;
    _x_x841 = _x_6; /*float64*/
  }
  double _x_x842;
  {
    double _x_7 = lo.err;
    _x_x842 = _x_7; /*float64*/
  }
  e2 = (_x_x841 + _x_x842); /*float64*/
  double _x_x843;
  {
    double _x_8 = z2.num;
    _x_x843 = _x_8; /*float64*/
  }
  return kk_std_num_ddouble_dquicksum(_x_x843, e2, _ctx);
}
 
// Divide two `:ddouble`s

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  double d_10042;
  double _x_x849;
  {
    double _x = x.hi;
    _x_x849 = _x; /*float64*/
  }
  double _x_x850;
  {
    double _x_0 = y.hi;
    _x_x850 = _x_0; /*float64*/
  }
  d_10042 = (_x_x849 / _x_x850); /*float64*/
  kk_std_num_ddouble__ddouble q1 = kk_std_num_ddouble__new_Ddouble(d_10042, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  bool b_10045;
  bool _match_x751;
  double _x_x851;
  {
    double _x_1 = q1.hi;
    _x_x851 = _x_1; /*float64*/
  }
  _match_x751 = isfinite(_x_x851); /*bool*/
  if (_match_x751) {
    double _x_x852;
    {
      double _x_0_0 = q1.lo;
      _x_x852 = _x_0_0; /*float64*/
    }
    b_10045 = isfinite(_x_x852); /*bool*/
  }
  else {
    b_10045 = false; /*bool*/
  }
  if (b_10045) {
    bool b_0_10046;
    double _x_x853;
    {
      double _x_1_0 = y.hi;
      _x_x853 = _x_1_0; /*float64*/
    }
    b_0_10046 = isfinite(_x_x853); /*bool*/
    if (b_0_10046) {
      kk_std_num_ddouble__ddouble y_0_10049 = kk_std_num_ddouble__lp__star__rp_(y, q1, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble r1;
      kk_std_num_ddouble__ddouble _x_x854;
      double _x_x855;
      double _x_x856;
      {
        double _x_2 = y_0_10049.hi;
        _x_x856 = _x_2; /*float64*/
      }
      _x_x855 = (-_x_x856); /*float64*/
      double _x_x857;
      double _x_x858;
      {
        double _x_0_1 = y_0_10049.lo;
        _x_x858 = _x_0_1; /*float64*/
      }
      _x_x857 = (-_x_x858); /*float64*/
      _x_x854 = kk_std_num_ddouble__new_Ddouble(_x_x855, _x_x857, _ctx); /*std/num/ddouble/ddouble*/
      r1 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x854, _ctx); /*std/num/ddouble/ddouble*/
      double d_0_10050;
      double _x_x859;
      {
        double _x_2_0 = r1.hi;
        _x_x859 = _x_2_0; /*float64*/
      }
      double _x_x860;
      {
        double _x_3 = y.hi;
        _x_x860 = _x_3; /*float64*/
      }
      d_0_10050 = (_x_x859 / _x_x860); /*float64*/
      kk_std_num_ddouble__ddouble q2 = kk_std_num_ddouble__new_Ddouble(d_0_10050, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble y_1_10054 = kk_std_num_ddouble__lp__star__rp_(y, q2, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble r2;
      kk_std_num_ddouble__ddouble _x_x861;
      double _x_x862;
      double _x_x863;
      {
        double _x_4 = y_1_10054.hi;
        _x_x863 = _x_4; /*float64*/
      }
      _x_x862 = (-_x_x863); /*float64*/
      double _x_x864;
      double _x_x865;
      {
        double _x_0_2 = y_1_10054.lo;
        _x_x865 = _x_0_2; /*float64*/
      }
      _x_x864 = (-_x_x865); /*float64*/
      _x_x861 = kk_std_num_ddouble__new_Ddouble(_x_x862, _x_x864, _ctx); /*std/num/ddouble/ddouble*/
      r2 = kk_std_num_ddouble__lp__plus__rp_(r1, _x_x861, _ctx); /*std/num/ddouble/ddouble*/
      double d_1_10055;
      double _x_x866;
      {
        double _x_4_0 = r2.hi;
        _x_x866 = _x_4_0; /*float64*/
      }
      double _x_x867;
      {
        double _x_5 = y.hi;
        _x_x867 = _x_5; /*float64*/
      }
      d_1_10055 = (_x_x866 / _x_x867); /*float64*/
      kk_std_num_ddouble__ddouble q;
      double _x_x868;
      {
        double _x_6 = q1.hi;
        _x_x868 = _x_6; /*float64*/
      }
      double _x_x869;
      {
        double _x_7 = q2.hi;
        _x_x869 = _x_7; /*float64*/
      }
      q = kk_std_num_ddouble_dquicksum(_x_x868, _x_x869, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x870 = kk_std_num_ddouble__new_Ddouble(d_1_10055, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__plus__rp_(q, _x_x870, _ctx);
    }
    {
      return q1;
    }
  }
  {
    return q1;
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dsum(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> ddouble */ 
  double z = (x + y); /*float64*/;
  double diff = (z - x); /*float64*/;
  double err;
  double _x_x871;
  double _x_x872 = (z - diff); /*float64*/
  _x_x871 = (x - _x_x872); /*float64*/
  double _x_x873 = (y - diff); /*float64*/
  err = (_x_x871 + _x_x873); /*float64*/
  double _x_x874;
  bool _match_x750 = isfinite(z); /*bool*/;
  if (_match_x750) {
    _x_x874 = err; /*float64*/
  }
  else {
    _x_x874 = z; /*float64*/
  }
  return kk_std_num_ddouble__new_Ddouble(z, _x_x874, _ctx);
}
 
// Multiply `x` with itself.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sqr(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double z;
  double _x_x876;
  {
    double _x = x.hi;
    _x_x876 = _x; /*float64*/
  }
  double _x_x877;
  {
    double _x_0 = x.hi;
    _x_x877 = _x_0; /*float64*/
  }
  z = (_x_x876 * _x_x877); /*float64*/
  double err;
  double _x_x878;
  {
    double _x_1 = x.hi;
    _x_x878 = _x_1; /*float64*/
  }
  double _x_x879;
  {
    double _x_2 = x.hi;
    _x_x879 = _x_2; /*float64*/
  }
  double _x_x880 = (-z); /*float64*/
  err = kk_std_num_float64_fmadd(_x_x878, _x_x879, _x_x880, _ctx); /*float64*/
  kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
  double e;
  double _x_x881;
  double _x_x882;
  {
    double _x_0_0 = z_0.err;
    _x_x882 = _x_0_0; /*float64*/
  }
  double _x_x883;
  double _x_x884;
  double _x_x885;
  {
    double _x_1_0 = x.hi;
    _x_x885 = _x_1_0; /*float64*/
  }
  _x_x884 = (0x1p1 * _x_x885); /*float64*/
  double _x_x886;
  {
    double _x_2_0 = x.lo;
    _x_x886 = _x_2_0; /*float64*/
  }
  _x_x883 = (_x_x884 * _x_x886); /*float64*/
  _x_x881 = (_x_x882 + _x_x883); /*float64*/
  double _x_x887;
  double _x_x888;
  {
    double _x_3 = x.lo;
    _x_x888 = _x_3; /*float64*/
  }
  double _x_x889;
  {
    double _x_4 = x.lo;
    _x_x889 = _x_4; /*float64*/
  }
  _x_x887 = (_x_x888 * _x_x889); /*float64*/
  e = (_x_x881 + _x_x887); /*float64*/
  double _x_x890;
  {
    double _x_5 = z_0.num;
    _x_x890 = _x_5; /*float64*/
  }
  return kk_std_num_ddouble_dquicksum(_x_x890, e, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_npwr_acc(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble acc, kk_integer_t n, kk_context_t* _ctx) { /* (x : ddouble, acc : ddouble, n : int) -> ddouble */ 
  kk__tailcall: ;
  bool _match_x748 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x748) {
    kk_integer_drop(n, _ctx);
    return acc;
  }
  {
    bool b_10014;
    kk_integer_t _x_x891 = kk_integer_dup(n, _ctx); /*int*/
    b_10014 = kk_integer_is_odd(_x_x891,kk_context()); /*bool*/
    if (b_10014) { // tailcall
                   kk_std_num_ddouble__ddouble _x_x892 = kk_std_num_ddouble__lp__star__rp_(x, acc, _ctx); /*std/num/ddouble/ddouble*/
                   kk_integer_t _x_x893 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
                   acc = _x_x892;
                   n = _x_x893;
                   goto kk__tailcall;
    }
    { // tailcall
      kk_std_num_ddouble__ddouble _x_x894 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/
      kk_integer_t _x_x895 = kk_integer_div(n,(kk_integer_from_small(2)),kk_context()); /*int*/
      x = _x_x894;
      n = _x_x895;
      goto kk__tailcall;
    }
  }
}
 
// One

kk_std_num_ddouble__ddouble kk_std_num_ddouble_one;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_npwr(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx) { /* (x : ddouble, n : int) -> ddouble */ 
  bool _match_x745 = kk_integer_eq_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x745) {
    kk_integer_drop(n, _ctx);
    bool _match_x747;
    double _x_x896;
    {
      double _x = x.hi;
      _x_x896 = _x; /*float64*/
    }
    _match_x747 = (_x_x896 == (0x0p+0)); /*bool*/
    if (_match_x747) {
      return kk_std_num_ddouble_dd_nan;
    }
    {
      return kk_std_num_ddouble_one;
    }
  }
  {
    bool _match_x746 = kk_integer_eq_borrow(n,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x746) {
      kk_integer_drop(n, _ctx);
      return x;
    }
    {
      return kk_std_num_ddouble_npwr_acc(x, kk_std_num_ddouble_one, n, _ctx);
    }
  }
}
 
// Return `x` to the power of `n`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_powi(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx) { /* (x : ddouble, n : int) -> ddouble */ 
  kk_integer_t n_0_10594;
  kk_integer_t _x_x897 = kk_integer_dup(n, _ctx); /*int*/
  n_0_10594 = kk_integer_abs(_x_x897,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble p;
  bool _match_x742 = kk_integer_eq_borrow(n_0_10594,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x742) {
    kk_integer_drop(n_0_10594, _ctx);
    bool _match_x744;
    double _x_x898;
    {
      double _x = x.hi;
      _x_x898 = _x; /*float64*/
    }
    _match_x744 = (_x_x898 == (0x0p+0)); /*bool*/
    if (_match_x744) {
      p = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      p = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    }
  }
  else {
    bool _match_x743 = kk_integer_eq_borrow(n_0_10594,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x743) {
      kk_integer_drop(n_0_10594, _ctx);
      p = x; /*std/num/ddouble/ddouble*/
    }
    else {
      p = kk_std_num_ddouble_npwr_acc(x, kk_std_num_ddouble_one, n_0_10594, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  bool _match_x740;
  bool _brw_x741 = kk_integer_lt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(n, _ctx);
  _match_x740 = _brw_x741; /*bool*/
  if (_match_x740) {
    return kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble_one, p, _ctx);
  }
  {
    return p;
  }
}
 
// Ten (`10.ddouble`)

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ten;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_small_exp(kk_integer_t i, kk_integer_t e, kk_context_t* _ctx) { /* (i : int, e : int) -> ddouble */ 
  double d_10079 = kk_integer_as_double(i,kk_context()); /*float64*/;
  kk_std_num_ddouble__ddouble dd = kk_std_num_ddouble__new_Ddouble(d_10079, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x737 = kk_integer_is_zero_borrow(e); /*bool*/;
  if (_match_x737) {
    kk_integer_drop(e, _ctx);
    return dd;
  }
  {
    bool _match_x738 = kk_integer_is_zero_borrow(e); /*bool*/;
    if (_match_x738) {
      kk_integer_drop(e, _ctx);
      return dd;
    }
    {
      kk_std_num_ddouble__ddouble _x_x900 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__star__rp_(dd, _x_x900, _ctx);
    }
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_int_exp(kk_integer_t i, kk_integer_t e, kk_context_t* _ctx) { /* (i : int, e : int) -> ddouble */ 
  bool _match_x697 = kk_integer_gte_borrow(i,kk_std_num_ddouble_minprecise,kk_context()); /*bool*/;
  if (_match_x697) {
    bool _match_x716;
    kk_integer_t _brw_x735 = kk_integer_from_str("9007199254740991", _ctx); /*int*/;
    bool _brw_x736 = kk_integer_lte_borrow(i,_brw_x735,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x735, _ctx);
    _match_x716 = _brw_x736; /*bool*/
    if (_match_x716) {
      return kk_std_num_ddouble_small_exp(i, e, _ctx);
    }
    {
      kk_integer_t p;
      kk_integer_t _x_x901 = kk_integer_dup(i, _ctx); /*int*/
      p = kk_std_core_int_count_digits(_x_x901, _ctx); /*int*/
      kk_integer_t px = kk_integer_add_small_const(p, -14, _ctx); /*int*/;
      kk_std_core_types__tuple2 _match_x717;
      kk_integer_t _x_x902 = kk_integer_dup(px, _ctx); /*int*/
      _match_x717 = kk_std_core_int_cdivmod_exp10(i, _x_x902, _ctx); /*(int, int)*/
      {
        kk_box_t _box_x2 = _match_x717.fst;
        kk_box_t _box_x3 = _match_x717.snd;
        kk_integer_t hi = kk_integer_unbox(_box_x2, _ctx);
        kk_integer_t y_0 = kk_integer_unbox(_box_x3, _ctx);
        kk_integer_dup(hi, _ctx);
        kk_integer_dup(y_0, _ctx);
        kk_std_core_types__tuple2_drop(_match_x717, _ctx);
        kk_integer_t py;
        kk_integer_t _x_x903 = kk_integer_dup(px, _ctx); /*int*/
        py = kk_integer_add_small_const(_x_x903, -14, _ctx); /*int*/
        bool _match_x718 = kk_integer_lte_borrow(py,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (_match_x718) {
          kk_integer_drop(py, _ctx);
          kk_integer_t e_0_10086;
          kk_integer_t _x_x904 = kk_integer_dup(e, _ctx); /*int*/
          e_0_10086 = kk_integer_add(px,_x_x904,kk_context()); /*int*/
          double d_10089 = kk_integer_as_double(hi,kk_context()); /*float64*/;
          kk_std_num_ddouble__ddouble dd = kk_std_num_ddouble__new_Ddouble(d_10089, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble _x_x905;
          bool _match_x733 = kk_integer_is_zero_borrow(e_0_10086); /*bool*/;
          if (_match_x733) {
            kk_integer_drop(e_0_10086, _ctx);
            _x_x905 = dd; /*std/num/ddouble/ddouble*/
          }
          else {
            bool _match_x734 = kk_integer_is_zero_borrow(e_0_10086); /*bool*/;
            if (_match_x734) {
              kk_integer_drop(e_0_10086, _ctx);
              _x_x905 = dd; /*std/num/ddouble/ddouble*/
            }
            else {
              kk_std_num_ddouble__ddouble _x_x906 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_0_10086, _ctx); /*std/num/ddouble/ddouble*/
              _x_x905 = kk_std_num_ddouble__lp__star__rp_(dd, _x_x906, _ctx); /*std/num/ddouble/ddouble*/
            }
          }
          kk_std_num_ddouble__ddouble _x_x907 = kk_std_num_ddouble_small_exp(y_0, e, _ctx); /*std/num/ddouble/ddouble*/
          return kk_std_num_ddouble__lp__plus__rp_(_x_x905, _x_x907, _ctx);
        }
        {
          kk_std_core_types__tuple2 _match_x719;
          kk_integer_t _x_x908 = kk_integer_dup(py, _ctx); /*int*/
          _match_x719 = kk_std_core_int_cdivmod_exp10(y_0, _x_x908, _ctx); /*(int, int)*/
          {
            kk_box_t _box_x4 = _match_x719.fst;
            kk_box_t _box_x5 = _match_x719.snd;
            kk_integer_t mid = kk_integer_unbox(_box_x4, _ctx);
            kk_integer_t z = kk_integer_unbox(_box_x5, _ctx);
            kk_integer_dup(mid, _ctx);
            kk_integer_dup(z, _ctx);
            kk_std_core_types__tuple2_drop(_match_x719, _ctx);
            kk_integer_t pz;
            kk_integer_t _x_x909 = kk_integer_dup(py, _ctx); /*int*/
            pz = kk_integer_add_small_const(_x_x909, -14, _ctx); /*int*/
            bool _match_x720 = kk_integer_lte_borrow(pz,(kk_integer_from_small(0)),kk_context()); /*bool*/;
            if (_match_x720) {
              kk_integer_drop(pz, _ctx);
              kk_integer_t e_1_10093;
              kk_integer_t _x_x910 = kk_integer_dup(e, _ctx); /*int*/
              e_1_10093 = kk_integer_add(px,_x_x910,kk_context()); /*int*/
              double d_0_10096 = kk_integer_as_double(hi,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_0 = kk_std_num_ddouble__new_Ddouble(d_0_10096, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_integer_t e_2_10098;
              kk_integer_t _x_x911 = kk_integer_dup(e, _ctx); /*int*/
              e_2_10098 = kk_integer_add(py,_x_x911,kk_context()); /*int*/
              double d_1_10101 = kk_integer_as_double(mid,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_1 = kk_std_num_ddouble__new_Ddouble(d_1_10101, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_integer_t e_3_10103 = kk_integer_add_small_const(e, 0, _ctx); /*int*/;
              double d_2_10106 = kk_integer_as_double(z,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_2 = kk_std_num_ddouble__new_Ddouble(d_2_10106, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_std_num_ddouble__ddouble _x_x912;
              bool _match_x731 = kk_integer_is_zero_borrow(e_1_10093); /*bool*/;
              if (_match_x731) {
                kk_integer_drop(e_1_10093, _ctx);
                _x_x912 = dd_0; /*std/num/ddouble/ddouble*/
              }
              else {
                bool _match_x732 = kk_integer_is_zero_borrow(e_1_10093); /*bool*/;
                if (_match_x732) {
                  kk_integer_drop(e_1_10093, _ctx);
                  _x_x912 = dd_0; /*std/num/ddouble/ddouble*/
                }
                else {
                  kk_std_num_ddouble__ddouble _x_x913 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_1_10093, _ctx); /*std/num/ddouble/ddouble*/
                  _x_x912 = kk_std_num_ddouble__lp__star__rp_(dd_0, _x_x913, _ctx); /*std/num/ddouble/ddouble*/
                }
              }
              kk_std_num_ddouble__ddouble _x_x914;
              kk_std_num_ddouble__ddouble _x_x915;
              bool _match_x729 = kk_integer_is_zero_borrow(e_2_10098); /*bool*/;
              if (_match_x729) {
                kk_integer_drop(e_2_10098, _ctx);
                _x_x915 = dd_1; /*std/num/ddouble/ddouble*/
              }
              else {
                bool _match_x730 = kk_integer_is_zero_borrow(e_2_10098); /*bool*/;
                if (_match_x730) {
                  kk_integer_drop(e_2_10098, _ctx);
                  _x_x915 = dd_1; /*std/num/ddouble/ddouble*/
                }
                else {
                  kk_std_num_ddouble__ddouble _x_x916 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_2_10098, _ctx); /*std/num/ddouble/ddouble*/
                  _x_x915 = kk_std_num_ddouble__lp__star__rp_(dd_1, _x_x916, _ctx); /*std/num/ddouble/ddouble*/
                }
              }
              kk_std_num_ddouble__ddouble _x_x917;
              bool _match_x727 = kk_integer_is_zero_borrow(e_3_10103); /*bool*/;
              if (_match_x727) {
                kk_integer_drop(e_3_10103, _ctx);
                _x_x917 = dd_2; /*std/num/ddouble/ddouble*/
              }
              else {
                bool _match_x728 = kk_integer_is_zero_borrow(e_3_10103); /*bool*/;
                if (_match_x728) {
                  kk_integer_drop(e_3_10103, _ctx);
                  _x_x917 = dd_2; /*std/num/ddouble/ddouble*/
                }
                else {
                  kk_std_num_ddouble__ddouble _x_x918 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_3_10103, _ctx); /*std/num/ddouble/ddouble*/
                  _x_x917 = kk_std_num_ddouble__lp__star__rp_(dd_2, _x_x918, _ctx); /*std/num/ddouble/ddouble*/
                }
              }
              _x_x914 = kk_std_num_ddouble__lp__plus__rp_(_x_x915, _x_x917, _ctx); /*std/num/ddouble/ddouble*/
              return kk_std_num_ddouble__lp__plus__rp_(_x_x912, _x_x914, _ctx);
            }
            {
              kk_integer_t lo;
              kk_integer_t _x_x919 = kk_integer_dup(pz, _ctx); /*int*/
              lo = kk_std_core_int_cdiv_exp10(z, _x_x919, _ctx); /*int*/
              kk_integer_t e_4_10108;
              kk_integer_t _x_x920 = kk_integer_dup(e, _ctx); /*int*/
              e_4_10108 = kk_integer_add(px,_x_x920,kk_context()); /*int*/
              double d_3_10111 = kk_integer_as_double(hi,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_3 = kk_std_num_ddouble__new_Ddouble(d_3_10111, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_integer_t e_5_10113;
              kk_integer_t _x_x921 = kk_integer_dup(e, _ctx); /*int*/
              e_5_10113 = kk_integer_add(py,_x_x921,kk_context()); /*int*/
              double d_4_10116 = kk_integer_as_double(mid,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_4 = kk_std_num_ddouble__new_Ddouble(d_4_10116, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_integer_t e_6_10118 = kk_integer_add(pz,e,kk_context()); /*int*/;
              double d_5_10121 = kk_integer_as_double(lo,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_5 = kk_std_num_ddouble__new_Ddouble(d_5_10121, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_std_num_ddouble__ddouble _x_x922;
              bool _match_x725 = kk_integer_is_zero_borrow(e_4_10108); /*bool*/;
              if (_match_x725) {
                kk_integer_drop(e_4_10108, _ctx);
                _x_x922 = dd_3; /*std/num/ddouble/ddouble*/
              }
              else {
                bool _match_x726 = kk_integer_is_zero_borrow(e_4_10108); /*bool*/;
                if (_match_x726) {
                  kk_integer_drop(e_4_10108, _ctx);
                  _x_x922 = dd_3; /*std/num/ddouble/ddouble*/
                }
                else {
                  kk_std_num_ddouble__ddouble _x_x923 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_4_10108, _ctx); /*std/num/ddouble/ddouble*/
                  _x_x922 = kk_std_num_ddouble__lp__star__rp_(dd_3, _x_x923, _ctx); /*std/num/ddouble/ddouble*/
                }
              }
              kk_std_num_ddouble__ddouble _x_x924;
              kk_std_num_ddouble__ddouble _x_x925;
              bool _match_x723 = kk_integer_is_zero_borrow(e_5_10113); /*bool*/;
              if (_match_x723) {
                kk_integer_drop(e_5_10113, _ctx);
                _x_x925 = dd_4; /*std/num/ddouble/ddouble*/
              }
              else {
                bool _match_x724 = kk_integer_is_zero_borrow(e_5_10113); /*bool*/;
                if (_match_x724) {
                  kk_integer_drop(e_5_10113, _ctx);
                  _x_x925 = dd_4; /*std/num/ddouble/ddouble*/
                }
                else {
                  kk_std_num_ddouble__ddouble _x_x926 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_5_10113, _ctx); /*std/num/ddouble/ddouble*/
                  _x_x925 = kk_std_num_ddouble__lp__star__rp_(dd_4, _x_x926, _ctx); /*std/num/ddouble/ddouble*/
                }
              }
              kk_std_num_ddouble__ddouble _x_x927;
              bool _match_x721 = kk_integer_is_zero_borrow(e_6_10118); /*bool*/;
              if (_match_x721) {
                kk_integer_drop(e_6_10118, _ctx);
                _x_x927 = dd_5; /*std/num/ddouble/ddouble*/
              }
              else {
                bool _match_x722 = kk_integer_is_zero_borrow(e_6_10118); /*bool*/;
                if (_match_x722) {
                  kk_integer_drop(e_6_10118, _ctx);
                  _x_x927 = dd_5; /*std/num/ddouble/ddouble*/
                }
                else {
                  kk_std_num_ddouble__ddouble _x_x928 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_6_10118, _ctx); /*std/num/ddouble/ddouble*/
                  _x_x927 = kk_std_num_ddouble__lp__star__rp_(dd_5, _x_x928, _ctx); /*std/num/ddouble/ddouble*/
                }
              }
              _x_x924 = kk_std_num_ddouble__lp__plus__rp_(_x_x925, _x_x927, _ctx); /*std/num/ddouble/ddouble*/
              return kk_std_num_ddouble__lp__plus__rp_(_x_x922, _x_x924, _ctx);
            }
          }
        }
      }
    }
  }
  {
    kk_integer_t p_0;
    kk_integer_t _x_x929 = kk_integer_dup(i, _ctx); /*int*/
    p_0 = kk_std_core_int_count_digits(_x_x929, _ctx); /*int*/
    kk_integer_t px_0 = kk_integer_add_small_const(p_0, -14, _ctx); /*int*/;
    kk_std_core_types__tuple2 _match_x698;
    kk_integer_t _x_x930 = kk_integer_dup(px_0, _ctx); /*int*/
    _match_x698 = kk_std_core_int_cdivmod_exp10(i, _x_x930, _ctx); /*(int, int)*/
    {
      kk_box_t _box_x6 = _match_x698.fst;
      kk_box_t _box_x7 = _match_x698.snd;
      kk_integer_t hi_0 = kk_integer_unbox(_box_x6, _ctx);
      kk_integer_t y_0_0 = kk_integer_unbox(_box_x7, _ctx);
      kk_integer_dup(hi_0, _ctx);
      kk_integer_dup(y_0_0, _ctx);
      kk_std_core_types__tuple2_drop(_match_x698, _ctx);
      kk_integer_t py_0;
      kk_integer_t _x_x931 = kk_integer_dup(px_0, _ctx); /*int*/
      py_0 = kk_integer_add_small_const(_x_x931, -14, _ctx); /*int*/
      bool _match_x699 = kk_integer_lte_borrow(py_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x699) {
        kk_integer_drop(py_0, _ctx);
        kk_integer_t e_0_10086_0;
        kk_integer_t _x_x932 = kk_integer_dup(e, _ctx); /*int*/
        e_0_10086_0 = kk_integer_add(px_0,_x_x932,kk_context()); /*int*/
        double d_10089_0 = kk_integer_as_double(hi_0,kk_context()); /*float64*/;
        kk_std_num_ddouble__ddouble dd_6 = kk_std_num_ddouble__new_Ddouble(d_10089_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble _x_x933;
        bool _match_x714 = kk_integer_is_zero_borrow(e_0_10086_0); /*bool*/;
        if (_match_x714) {
          kk_integer_drop(e_0_10086_0, _ctx);
          _x_x933 = dd_6; /*std/num/ddouble/ddouble*/
        }
        else {
          bool _match_x715 = kk_integer_is_zero_borrow(e_0_10086_0); /*bool*/;
          if (_match_x715) {
            kk_integer_drop(e_0_10086_0, _ctx);
            _x_x933 = dd_6; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_std_num_ddouble__ddouble _x_x934 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_0_10086_0, _ctx); /*std/num/ddouble/ddouble*/
            _x_x933 = kk_std_num_ddouble__lp__star__rp_(dd_6, _x_x934, _ctx); /*std/num/ddouble/ddouble*/
          }
        }
        kk_std_num_ddouble__ddouble _x_x935 = kk_std_num_ddouble_small_exp(y_0_0, e, _ctx); /*std/num/ddouble/ddouble*/
        return kk_std_num_ddouble__lp__plus__rp_(_x_x933, _x_x935, _ctx);
      }
      {
        kk_std_core_types__tuple2 _match_x700;
        kk_integer_t _x_x936 = kk_integer_dup(py_0, _ctx); /*int*/
        _match_x700 = kk_std_core_int_cdivmod_exp10(y_0_0, _x_x936, _ctx); /*(int, int)*/
        {
          kk_box_t _box_x8 = _match_x700.fst;
          kk_box_t _box_x9 = _match_x700.snd;
          kk_integer_t mid_0 = kk_integer_unbox(_box_x8, _ctx);
          kk_integer_t z_0 = kk_integer_unbox(_box_x9, _ctx);
          kk_integer_dup(mid_0, _ctx);
          kk_integer_dup(z_0, _ctx);
          kk_std_core_types__tuple2_drop(_match_x700, _ctx);
          kk_integer_t pz_0;
          kk_integer_t _x_x937 = kk_integer_dup(py_0, _ctx); /*int*/
          pz_0 = kk_integer_add_small_const(_x_x937, -14, _ctx); /*int*/
          bool _match_x701 = kk_integer_lte_borrow(pz_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
          if (_match_x701) {
            kk_integer_drop(pz_0, _ctx);
            kk_integer_t e_1_10093_0;
            kk_integer_t _x_x938 = kk_integer_dup(e, _ctx); /*int*/
            e_1_10093_0 = kk_integer_add(px_0,_x_x938,kk_context()); /*int*/
            double d_0_10096_0 = kk_integer_as_double(hi_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_0_0 = kk_std_num_ddouble__new_Ddouble(d_0_10096_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_integer_t e_2_10098_0;
            kk_integer_t _x_x939 = kk_integer_dup(e, _ctx); /*int*/
            e_2_10098_0 = kk_integer_add(py_0,_x_x939,kk_context()); /*int*/
            double d_1_10101_0 = kk_integer_as_double(mid_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_1_0 = kk_std_num_ddouble__new_Ddouble(d_1_10101_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_integer_t e_3_10103_0 = kk_integer_add_small_const(e, 0, _ctx); /*int*/;
            double d_2_10106_0 = kk_integer_as_double(z_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_2_0 = kk_std_num_ddouble__new_Ddouble(d_2_10106_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_std_num_ddouble__ddouble _x_x940;
            bool _match_x712 = kk_integer_is_zero_borrow(e_1_10093_0); /*bool*/;
            if (_match_x712) {
              kk_integer_drop(e_1_10093_0, _ctx);
              _x_x940 = dd_0_0; /*std/num/ddouble/ddouble*/
            }
            else {
              bool _match_x713 = kk_integer_is_zero_borrow(e_1_10093_0); /*bool*/;
              if (_match_x713) {
                kk_integer_drop(e_1_10093_0, _ctx);
                _x_x940 = dd_0_0; /*std/num/ddouble/ddouble*/
              }
              else {
                kk_std_num_ddouble__ddouble _x_x941 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_1_10093_0, _ctx); /*std/num/ddouble/ddouble*/
                _x_x940 = kk_std_num_ddouble__lp__star__rp_(dd_0_0, _x_x941, _ctx); /*std/num/ddouble/ddouble*/
              }
            }
            kk_std_num_ddouble__ddouble _x_x942;
            kk_std_num_ddouble__ddouble _x_x943;
            bool _match_x710 = kk_integer_is_zero_borrow(e_2_10098_0); /*bool*/;
            if (_match_x710) {
              kk_integer_drop(e_2_10098_0, _ctx);
              _x_x943 = dd_1_0; /*std/num/ddouble/ddouble*/
            }
            else {
              bool _match_x711 = kk_integer_is_zero_borrow(e_2_10098_0); /*bool*/;
              if (_match_x711) {
                kk_integer_drop(e_2_10098_0, _ctx);
                _x_x943 = dd_1_0; /*std/num/ddouble/ddouble*/
              }
              else {
                kk_std_num_ddouble__ddouble _x_x944 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_2_10098_0, _ctx); /*std/num/ddouble/ddouble*/
                _x_x943 = kk_std_num_ddouble__lp__star__rp_(dd_1_0, _x_x944, _ctx); /*std/num/ddouble/ddouble*/
              }
            }
            kk_std_num_ddouble__ddouble _x_x945;
            bool _match_x708 = kk_integer_is_zero_borrow(e_3_10103_0); /*bool*/;
            if (_match_x708) {
              kk_integer_drop(e_3_10103_0, _ctx);
              _x_x945 = dd_2_0; /*std/num/ddouble/ddouble*/
            }
            else {
              bool _match_x709 = kk_integer_is_zero_borrow(e_3_10103_0); /*bool*/;
              if (_match_x709) {
                kk_integer_drop(e_3_10103_0, _ctx);
                _x_x945 = dd_2_0; /*std/num/ddouble/ddouble*/
              }
              else {
                kk_std_num_ddouble__ddouble _x_x946 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_3_10103_0, _ctx); /*std/num/ddouble/ddouble*/
                _x_x945 = kk_std_num_ddouble__lp__star__rp_(dd_2_0, _x_x946, _ctx); /*std/num/ddouble/ddouble*/
              }
            }
            _x_x942 = kk_std_num_ddouble__lp__plus__rp_(_x_x943, _x_x945, _ctx); /*std/num/ddouble/ddouble*/
            return kk_std_num_ddouble__lp__plus__rp_(_x_x940, _x_x942, _ctx);
          }
          {
            kk_integer_t lo_0;
            kk_integer_t _x_x947 = kk_integer_dup(pz_0, _ctx); /*int*/
            lo_0 = kk_std_core_int_cdiv_exp10(z_0, _x_x947, _ctx); /*int*/
            kk_integer_t e_4_10108_0;
            kk_integer_t _x_x948 = kk_integer_dup(e, _ctx); /*int*/
            e_4_10108_0 = kk_integer_add(px_0,_x_x948,kk_context()); /*int*/
            double d_3_10111_0 = kk_integer_as_double(hi_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_3_0 = kk_std_num_ddouble__new_Ddouble(d_3_10111_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_integer_t e_5_10113_0;
            kk_integer_t _x_x949 = kk_integer_dup(e, _ctx); /*int*/
            e_5_10113_0 = kk_integer_add(py_0,_x_x949,kk_context()); /*int*/
            double d_4_10116_0 = kk_integer_as_double(mid_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_4_0 = kk_std_num_ddouble__new_Ddouble(d_4_10116_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_integer_t e_6_10118_0 = kk_integer_add(pz_0,e,kk_context()); /*int*/;
            double d_5_10121_0 = kk_integer_as_double(lo_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_5_0 = kk_std_num_ddouble__new_Ddouble(d_5_10121_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_std_num_ddouble__ddouble _x_x950;
            bool _match_x706 = kk_integer_is_zero_borrow(e_4_10108_0); /*bool*/;
            if (_match_x706) {
              kk_integer_drop(e_4_10108_0, _ctx);
              _x_x950 = dd_3_0; /*std/num/ddouble/ddouble*/
            }
            else {
              bool _match_x707 = kk_integer_is_zero_borrow(e_4_10108_0); /*bool*/;
              if (_match_x707) {
                kk_integer_drop(e_4_10108_0, _ctx);
                _x_x950 = dd_3_0; /*std/num/ddouble/ddouble*/
              }
              else {
                kk_std_num_ddouble__ddouble _x_x951 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_4_10108_0, _ctx); /*std/num/ddouble/ddouble*/
                _x_x950 = kk_std_num_ddouble__lp__star__rp_(dd_3_0, _x_x951, _ctx); /*std/num/ddouble/ddouble*/
              }
            }
            kk_std_num_ddouble__ddouble _x_x952;
            kk_std_num_ddouble__ddouble _x_x953;
            bool _match_x704 = kk_integer_is_zero_borrow(e_5_10113_0); /*bool*/;
            if (_match_x704) {
              kk_integer_drop(e_5_10113_0, _ctx);
              _x_x953 = dd_4_0; /*std/num/ddouble/ddouble*/
            }
            else {
              bool _match_x705 = kk_integer_is_zero_borrow(e_5_10113_0); /*bool*/;
              if (_match_x705) {
                kk_integer_drop(e_5_10113_0, _ctx);
                _x_x953 = dd_4_0; /*std/num/ddouble/ddouble*/
              }
              else {
                kk_std_num_ddouble__ddouble _x_x954 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_5_10113_0, _ctx); /*std/num/ddouble/ddouble*/
                _x_x953 = kk_std_num_ddouble__lp__star__rp_(dd_4_0, _x_x954, _ctx); /*std/num/ddouble/ddouble*/
              }
            }
            kk_std_num_ddouble__ddouble _x_x955;
            bool _match_x702 = kk_integer_is_zero_borrow(e_6_10118_0); /*bool*/;
            if (_match_x702) {
              kk_integer_drop(e_6_10118_0, _ctx);
              _x_x955 = dd_5_0; /*std/num/ddouble/ddouble*/
            }
            else {
              bool _match_x703 = kk_integer_is_zero_borrow(e_6_10118_0); /*bool*/;
              if (_match_x703) {
                kk_integer_drop(e_6_10118_0, _ctx);
                _x_x955 = dd_5_0; /*std/num/ddouble/ddouble*/
              }
              else {
                kk_std_num_ddouble__ddouble _x_x956 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e_6_10118_0, _ctx); /*std/num/ddouble/ddouble*/
                _x_x955 = kk_std_num_ddouble__lp__star__rp_(dd_5_0, _x_x956, _ctx); /*std/num/ddouble/ddouble*/
              }
            }
            _x_x952 = kk_std_num_ddouble__lp__plus__rp_(_x_x953, _x_x955, _ctx); /*std/num/ddouble/ddouble*/
            return kk_std_num_ddouble__lp__plus__rp_(_x_x950, _x_x952, _ctx);
          }
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10798_fun963__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10798_fun963(kk_function_t _fself, kk_box_t _b_x14, kk_box_t _b_x15, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10798_fun963(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_10798_fun963, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10798_fun963(kk_function_t _fself, kk_box_t _b_x14, kk_box_t _b_x15, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x964;
  kk_string_t _x_x965 = kk_string_unbox(_b_x14); /*string*/
  bool _x_x966;
  kk_std_core_types__optional _match_x696 = kk_std_core_types__optional_unbox(_b_x15, KK_OWNED, _ctx); /*? bool*/;
  if (kk_std_core_types__is_Optional(_match_x696, _ctx)) {
    kk_box_t _box_x10 = _match_x696._cons._Optional.value;
    bool _uniq_hex_581 = kk_bool_unbox(_box_x10);
    kk_std_core_types__optional_drop(_match_x696, _ctx);
    _x_x966 = _uniq_hex_581; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x696, _ctx);
    _x_x966 = false; /*bool*/
  }
  _x_x964 = kk_std_core_int_xparse(_x_x965, _x_x966, _ctx); /*maybe<int>*/
  return kk_std_core_types__maybe_box(_x_x964, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10798_fun968__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10798_fun968(kk_function_t _fself, kk_box_t _b_x25, kk_box_t _b_x26, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10798_fun968(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_10798_fun968, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10798_fun968(kk_function_t _fself, kk_box_t _b_x25, kk_box_t _b_x26, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x969;
  kk_std_core_types__maybe _match_x695 = kk_std_core_types__maybe_unbox(_b_x25, KK_OWNED, _ctx); /*maybe<int>*/;
  if (kk_std_core_types__is_Nothing(_match_x695, _ctx)) {
    _x_x969 = kk_integer_unbox(_b_x26, _ctx); /*int*/
  }
  else {
    kk_box_t _box_x21 = _match_x695._cons.Just.value;
    kk_integer_t x = kk_integer_unbox(_box_x21, _ctx);
    kk_integer_dup(x, _ctx);
    kk_std_core_types__maybe_drop(_match_x695, _ctx);
    kk_box_drop(_b_x26, _ctx);
    _x_x969 = x; /*int*/
  }
  return kk_integer_box(_x_x969, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10798_fun971__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10798_fun971(kk_function_t _fself, kk_box_t _b_x35, kk_box_t _b_x36, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10798_fun971(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_10798_fun971, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10798_fun971(kk_function_t _fself, kk_box_t _b_x35, kk_box_t _b_x36, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x972;
  kk_integer_t _x_x973 = kk_integer_unbox(_b_x35, _ctx); /*int*/
  kk_integer_t _x_x974 = kk_integer_unbox(_b_x36, _ctx); /*int*/
  _x_x972 = kk_std_num_ddouble_ddouble_int_exp(_x_x973, _x_x974, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x972, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_10798(kk_string_t frac, bool neg, kk_string_t whole, kk_integer_t exp_0, kk_context_t* _ctx) { /* (frac : string, neg : bool, whole : string, exp@0 : int) -> std/text/parse/parse ddouble */ 
  kk_string_t _x_x1_0_10790;
  kk_string_t _x_x957;
  if (neg) {
    kk_define_string_literal(, _s_x958, 1, "-", _ctx)
    _x_x957 = kk_string_dup(_s_x958, _ctx); /*string*/
  }
  else {
    _x_x957 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x960;
  kk_string_t _x_x961 = kk_string_dup(frac, _ctx); /*string*/
  _x_x960 = kk_std_core_types__lp__plus__plus__rp_(whole, _x_x961, _ctx); /*string*/
  _x_x1_0_10790 = kk_std_core_types__lp__plus__plus__rp_(_x_x957, _x_x960, _ctx); /*string*/
  kk_std_core_types__maybe _x_x1_10788;
  kk_box_t _x_x962 = kk_std_core_hnd__open_none2(kk_std_num_ddouble__new_mlift_pddouble_normal_10798_fun963(_ctx), kk_string_box(_x_x1_0_10790), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
  _x_x1_10788 = kk_std_core_types__maybe_unbox(_x_x962, KK_OWNED, _ctx); /*maybe<int>*/
  kk_integer_t w;
  kk_box_t _x_x967 = kk_std_core_hnd__open_none2(kk_std_num_ddouble__new_mlift_pddouble_normal_10798_fun968(_ctx), kk_std_core_types__maybe_box(_x_x1_10788, _ctx), kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*10002*/
  w = kk_integer_unbox(_x_x967, _ctx); /*int*/
  kk_integer_t y_10781 = kk_std_core_string_chars_fs_count(frac, _ctx); /*int*/;
  kk_integer_t e = kk_integer_sub(exp_0,y_10781,kk_context()); /*int*/;
  kk_box_t _x_x970 = kk_std_core_hnd__open_none2(kk_std_num_ddouble__new_mlift_pddouble_normal_10798_fun971(_ctx), kk_integer_box(w, _ctx), kk_integer_box(e, _ctx), _ctx); /*10002*/
  return kk_std_num_ddouble__ddouble_unbox(_x_x970, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10800_fun978__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10800_fun978(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10800_fun978(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_10800_fun978, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10800_fun981__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10800_fun981(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10800_fun981(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_10800_fun981, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10800_fun981(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x982;
  kk_char_t _x_x983 = kk_char_unbox(_b_x41, KK_OWNED, _ctx); /*char*/
  _x_x982 = kk_std_num_ddouble__mlift_pddouble_normal_10797(_x_x983, _ctx); /*int*/
  return kk_integer_box(_x_x982, _ctx);
}
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10800_fun978(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_0_10810 = kk_std_text_parse_char('e', _ctx); /*char*/;
  kk_integer_t _x_x979;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x980 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_10800_fun981(_ctx), _ctx); /*10001*/
    _x_x979 = kk_integer_unbox(_x_x980, _ctx); /*int*/
  }
  else {
    _x_x979 = kk_std_text_parse_pint(_ctx); /*int*/
  }
  return kk_integer_box(_x_x979, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10800_fun984__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10800_fun984(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10800_fun984(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_10800_fun984, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10800_fun984(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_integer_box(kk_integer_from_small(0), _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10800_fun986__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10800_fun986(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10800_fun986(kk_string_t frac, kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_10800_fun986__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_normal_10800_fun986__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_normal_10800_fun986, kk_context());
  _self->frac = frac;
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10800_fun986(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_10800_fun986__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_normal_10800_fun986__t*, _fself, _ctx);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(frac, _ctx);kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_integer_t exp_0_50 = kk_integer_unbox(_b_x48, _ctx); /*int*/;
  kk_std_num_ddouble__ddouble _x_x987 = kk_std_num_ddouble__mlift_pddouble_normal_10798(frac, neg, whole, exp_0_50, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x987, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_10800(bool neg, kk_string_t whole, kk_string_t _y_x10767, kk_context_t* _ctx) { /* (neg : bool, whole : string, string) -> std/text/parse/parse ddouble */ 
  kk_string_t frac;
  kk_string_t _x_x975;
  kk_define_string_literal(, _s_x976, 1, "0", _ctx)
  _x_x975 = kk_string_dup(_s_x976, _ctx); /*string*/
  frac = kk_std_core_sslice_trim_right(_y_x10767, _x_x975, _ctx); /*string*/
  kk_integer_t x_10808;
  kk_box_t _x_x977 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_ddouble__new_mlift_pddouble_normal_10800_fun978(_ctx), kk_std_num_ddouble__new_mlift_pddouble_normal_10800_fun984(_ctx), _ctx); /*10000*/
  x_10808 = kk_integer_unbox(_x_x977, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10808, _ctx);
    kk_box_t _x_x985 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_10800_fun986(frac, whole, neg, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x985, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_ddouble__mlift_pddouble_normal_10798(frac, neg, whole, x_10808, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10801_fun989__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10801_fun989(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10801_fun989(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_10801_fun989, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10801_fun992__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10801_fun992(kk_function_t _fself, kk_box_t _b_x52, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10801_fun992(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_10801_fun992, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10801_fun992(kk_function_t _fself, kk_box_t _b_x52, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x993;
  kk_char_t _x_x994 = kk_char_unbox(_b_x52, KK_OWNED, _ctx); /*char*/
  _x_x993 = kk_std_num_ddouble__mlift_pddouble_normal_10799(_x_x994, _ctx); /*string*/
  return kk_string_box(_x_x993);
}
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10801_fun989(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_0_10814 = kk_std_text_parse_char('.', _ctx); /*char*/;
  kk_string_t _x_x990;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x991 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_10801_fun992(_ctx), _ctx); /*10001*/
    _x_x990 = kk_string_unbox(_x_x991); /*string*/
  }
  else {
    _x_x990 = kk_std_text_parse_digits(_ctx); /*string*/
  }
  return kk_string_box(_x_x990);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10801_fun995__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10801_fun995(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10801_fun995(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_10801_fun995, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10801_fun995(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x996 = kk_string_empty(); /*string*/
  return kk_string_box(_x_x996);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10801_fun999__t {
  struct kk_function_s _base;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10801_fun999(kk_function_t _fself, kk_box_t _b_x59, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10801_fun999(kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_10801_fun999__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_normal_10801_fun999__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_normal_10801_fun999, kk_context());
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10801_fun999(kk_function_t _fself, kk_box_t _b_x59, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_10801_fun999__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_normal_10801_fun999__t*, _fself, _ctx);
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_string_t _y_x10767_61 = kk_string_unbox(_b_x59); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1000 = kk_std_num_ddouble__mlift_pddouble_normal_10800(neg, whole, _y_x10767_61, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1000, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_10801(bool neg, kk_string_t whole, kk_context_t* _ctx) { /* (neg : bool, whole : string) -> std/text/parse/parse ddouble */ 
  kk_string_t x_10812;
  kk_box_t _x_x988 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_ddouble__new_mlift_pddouble_normal_10801_fun989(_ctx), kk_std_num_ddouble__new_mlift_pddouble_normal_10801_fun995(_ctx), _ctx); /*10000*/
  x_10812 = kk_string_unbox(_x_x988); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10812, _ctx);
    kk_box_t _x_x998 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_10801_fun999(whole, neg, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x998, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_ddouble__mlift_pddouble_normal_10800(neg, whole, x_10812, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_10802_fun1002__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10802_fun1002(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_10802_fun1002(bool neg, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_10802_fun1002__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_normal_10802_fun1002__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_normal_10802_fun1002, kk_context());
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_10802_fun1002(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_10802_fun1002__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_normal_10802_fun1002__t*, _fself, _ctx);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_string_t whole_65 = kk_string_unbox(_b_x63); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1003 = kk_std_num_ddouble__mlift_pddouble_normal_10801(neg, whole_65, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1003, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_10802(bool neg, kk_context_t* _ctx) { /* (neg : bool) -> std/text/parse/parse ddouble */ 
  kk_string_t x_10816 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10816, _ctx);
    kk_box_t _x_x1001 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_10802_fun1002(neg, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1001, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_ddouble__mlift_pddouble_normal_10801(neg, x_10816, _ctx);
  }
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1005__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1005(kk_function_t _fself, kk_box_t _b_x67, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1005(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1005, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1005(kk_function_t _fself, kk_box_t _b_x67, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1006;
  bool _x_x1007 = kk_bool_unbox(_b_x67); /*bool*/
  _x_x1006 = kk_std_num_ddouble__mlift_pddouble_normal_10802(_x_x1007, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1006, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1009__t {
  struct kk_function_s _base;
  bool x_10818;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1009(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1009(bool x_10818, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1009__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_normal_fun1009__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_normal_fun1009, kk_context());
  _self->x_10818 = x_10818;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1009(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1009__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_normal_fun1009__t*, _fself, _ctx);
  bool x_10818 = _self->x_10818; /* bool */
  kk_drop_match(_self, {kk_skip_dup(x_10818, _ctx);}, {}, _ctx)
  kk_string_t whole_122 = kk_string_unbox(_b_x69); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1010 = kk_std_num_ddouble__mlift_pddouble_normal_10801(x_10818, whole_122, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1010, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1012__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1012(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1012(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1012, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1015__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1015(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1015(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1015, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1015(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1016;
  kk_char_t _x_x1017 = kk_char_unbox(_b_x71, KK_OWNED, _ctx); /*char*/
  _x_x1016 = kk_std_num_ddouble__mlift_pddouble_normal_10799(_x_x1017, _ctx); /*string*/
  return kk_string_box(_x_x1016);
}
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1012(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_2_10827 = kk_std_text_parse_char('.', _ctx); /*char*/;
  kk_string_t _x_x1013;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1014 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1015(_ctx), _ctx); /*10001*/
    _x_x1013 = kk_string_unbox(_x_x1014); /*string*/
  }
  else {
    _x_x1013 = kk_std_text_parse_digits(_ctx); /*string*/
  }
  return kk_string_box(_x_x1013);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1018__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1018(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1018(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1018, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1018(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1019 = kk_string_empty(); /*string*/
  return kk_string_box(_x_x1019);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1022__t {
  struct kk_function_s _base;
  kk_string_t x_0_10821;
  bool x_10818;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1022(kk_function_t _fself, kk_box_t _b_x78, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1022(kk_string_t x_0_10821, bool x_10818, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1022__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_normal_fun1022__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_normal_fun1022, kk_context());
  _self->x_0_10821 = x_0_10821;
  _self->x_10818 = x_10818;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1022(kk_function_t _fself, kk_box_t _b_x78, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1022__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_normal_fun1022__t*, _fself, _ctx);
  kk_string_t x_0_10821 = _self->x_0_10821; /* string */
  bool x_10818 = _self->x_10818; /* bool */
  kk_drop_match(_self, {kk_string_dup(x_0_10821, _ctx);kk_skip_dup(x_10818, _ctx);}, {}, _ctx)
  kk_string_t _y_x10767_123 = kk_string_unbox(_b_x78); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1023 = kk_std_num_ddouble__mlift_pddouble_normal_10800(x_10818, x_0_10821, _y_x10767_123, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1023, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1027__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1027(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1027(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1027, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1030__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1030(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1030(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1030, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1030(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1031;
  kk_char_t _x_x1032 = kk_char_unbox(_b_x80, KK_OWNED, _ctx); /*char*/
  _x_x1031 = kk_std_num_ddouble__mlift_pddouble_normal_10797(_x_x1032, _ctx); /*int*/
  return kk_integer_box(_x_x1031, _ctx);
}
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1027(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_4_10832 = kk_std_text_parse_char('e', _ctx); /*char*/;
  kk_integer_t _x_x1028;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1029 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1030(_ctx), _ctx); /*10001*/
    _x_x1028 = kk_integer_unbox(_x_x1029, _ctx); /*int*/
  }
  else {
    _x_x1028 = kk_std_text_parse_pint(_ctx); /*int*/
  }
  return kk_integer_box(_x_x1028, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1033__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1033(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1033(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1033, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1033(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_integer_box(kk_integer_from_small(0), _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1035__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t x_0_10821;
  bool x_10818;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1035(kk_function_t _fself, kk_box_t _b_x87, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1035(kk_string_t frac, kk_string_t x_0_10821, bool x_10818, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1035__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_normal_fun1035__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_normal_fun1035, kk_context());
  _self->frac = frac;
  _self->x_0_10821 = x_0_10821;
  _self->x_10818 = x_10818;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1035(kk_function_t _fself, kk_box_t _b_x87, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1035__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_normal_fun1035__t*, _fself, _ctx);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t x_0_10821 = _self->x_0_10821; /* string */
  bool x_10818 = _self->x_10818; /* bool */
  kk_drop_match(_self, {kk_string_dup(frac, _ctx);kk_string_dup(x_0_10821, _ctx);kk_skip_dup(x_10818, _ctx);}, {}, _ctx)
  kk_integer_t exp_0_124 = kk_integer_unbox(_b_x87, _ctx); /*int*/;
  kk_std_num_ddouble__ddouble _x_x1036 = kk_std_num_ddouble__mlift_pddouble_normal_10798(frac, x_10818, x_0_10821, exp_0_124, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1036, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1043__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1043(kk_function_t _fself, kk_box_t _b_x92, kk_box_t _b_x93, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1043(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1043, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1043(kk_function_t _fself, kk_box_t _b_x92, kk_box_t _b_x93, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x1044;
  kk_string_t _x_x1045 = kk_string_unbox(_b_x92); /*string*/
  bool _x_x1046;
  kk_std_core_types__optional _match_x687 = kk_std_core_types__optional_unbox(_b_x93, KK_OWNED, _ctx); /*? bool*/;
  if (kk_std_core_types__is_Optional(_match_x687, _ctx)) {
    kk_box_t _box_x88 = _match_x687._cons._Optional.value;
    bool _uniq_hex_581 = kk_bool_unbox(_box_x88);
    kk_std_core_types__optional_drop(_match_x687, _ctx);
    _x_x1046 = _uniq_hex_581; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x687, _ctx);
    _x_x1046 = false; /*bool*/
  }
  _x_x1044 = kk_std_core_int_xparse(_x_x1045, _x_x1046, _ctx); /*maybe<int>*/
  return kk_std_core_types__maybe_box(_x_x1044, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1048__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1048(kk_function_t _fself, kk_box_t _b_x103, kk_box_t _b_x104, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1048(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1048, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1048(kk_function_t _fself, kk_box_t _b_x103, kk_box_t _b_x104, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1049;
  kk_std_core_types__maybe _match_x686 = kk_std_core_types__maybe_unbox(_b_x103, KK_OWNED, _ctx); /*maybe<int>*/;
  if (kk_std_core_types__is_Nothing(_match_x686, _ctx)) {
    _x_x1049 = kk_integer_unbox(_b_x104, _ctx); /*int*/
  }
  else {
    kk_box_t _box_x99 = _match_x686._cons.Just.value;
    kk_integer_t x_5 = kk_integer_unbox(_box_x99, _ctx);
    kk_integer_dup(x_5, _ctx);
    kk_std_core_types__maybe_drop(_match_x686, _ctx);
    kk_box_drop(_b_x104, _ctx);
    _x_x1049 = x_5; /*int*/
  }
  return kk_integer_box(_x_x1049, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1051__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1051(kk_function_t _fself, kk_box_t _b_x113, kk_box_t _b_x114, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1051(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1051, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1051(kk_function_t _fself, kk_box_t _b_x113, kk_box_t _b_x114, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1052;
  kk_integer_t _x_x1053 = kk_integer_unbox(_b_x113, _ctx); /*int*/
  kk_integer_t _x_x1054 = kk_integer_unbox(_b_x114, _ctx); /*int*/
  _x_x1052 = kk_std_num_ddouble_ddouble_int_exp(_x_x1053, _x_x1054, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1052, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_normal(kk_context_t* _ctx) { /* () -> std/text/parse/parse ddouble */ 
  bool x_10818 = kk_std_text_parse_sign(_ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1004 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1005(_ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1004, KK_OWNED, _ctx);
  }
  {
    kk_string_t x_0_10821 = kk_std_text_parse_digits(_ctx); /*string*/;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10821, _ctx);
      kk_box_t _x_x1008 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1009(x_10818, _ctx), _ctx); /*10001*/
      return kk_std_num_ddouble__ddouble_unbox(_x_x1008, KK_OWNED, _ctx);
    }
    {
      kk_string_t x_1_10824;
      kk_box_t _x_x1011 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_ddouble_new_pddouble_normal_fun1012(_ctx), kk_std_num_ddouble_new_pddouble_normal_fun1018(_ctx), _ctx); /*10000*/
      x_1_10824 = kk_string_unbox(_x_x1011); /*string*/
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_1_10824, _ctx);
        kk_box_t _x_x1021 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1022(x_0_10821, x_10818, _ctx), _ctx); /*10001*/
        return kk_std_num_ddouble__ddouble_unbox(_x_x1021, KK_OWNED, _ctx);
      }
      {
        kk_string_t frac;
        kk_string_t _x_x1024;
        kk_define_string_literal(, _s_x1025, 1, "0", _ctx)
        _x_x1024 = kk_string_dup(_s_x1025, _ctx); /*string*/
        frac = kk_std_core_sslice_trim_right(x_1_10824, _x_x1024, _ctx); /*string*/
        kk_integer_t x_3_10829;
        kk_box_t _x_x1026 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_ddouble_new_pddouble_normal_fun1027(_ctx), kk_std_num_ddouble_new_pddouble_normal_fun1033(_ctx), _ctx); /*10000*/
        x_3_10829 = kk_integer_unbox(_x_x1026, _ctx); /*int*/
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_3_10829, _ctx);
          kk_box_t _x_x1034 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1035(frac, x_0_10821, x_10818, _ctx), _ctx); /*10001*/
          return kk_std_num_ddouble__ddouble_unbox(_x_x1034, KK_OWNED, _ctx);
        }
        {
          kk_string_t _x_x1_0_10790;
          kk_string_t _x_x1037;
          if (x_10818) {
            kk_define_string_literal(, _s_x1038, 1, "-", _ctx)
            _x_x1037 = kk_string_dup(_s_x1038, _ctx); /*string*/
          }
          else {
            _x_x1037 = kk_string_empty(); /*string*/
          }
          kk_string_t _x_x1040;
          kk_string_t _x_x1041 = kk_string_dup(frac, _ctx); /*string*/
          _x_x1040 = kk_std_core_types__lp__plus__plus__rp_(x_0_10821, _x_x1041, _ctx); /*string*/
          _x_x1_0_10790 = kk_std_core_types__lp__plus__plus__rp_(_x_x1037, _x_x1040, _ctx); /*string*/
          kk_std_core_types__maybe _x_x1_10788;
          kk_box_t _x_x1042 = kk_std_core_hnd__open_none2(kk_std_num_ddouble_new_pddouble_normal_fun1043(_ctx), kk_string_box(_x_x1_0_10790), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*10002*/
          _x_x1_10788 = kk_std_core_types__maybe_unbox(_x_x1042, KK_OWNED, _ctx); /*maybe<int>*/
          kk_integer_t w;
          kk_box_t _x_x1047 = kk_std_core_hnd__open_none2(kk_std_num_ddouble_new_pddouble_normal_fun1048(_ctx), kk_std_core_types__maybe_box(_x_x1_10788, _ctx), kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*10002*/
          w = kk_integer_unbox(_x_x1047, _ctx); /*int*/
          kk_integer_t y_10781 = kk_std_core_string_chars_fs_count(frac, _ctx); /*int*/;
          kk_integer_t e = kk_integer_sub(x_3_10829,y_10781,kk_context()); /*int*/;
          kk_box_t _x_x1050 = kk_std_core_hnd__open_none2(kk_std_num_ddouble_new_pddouble_normal_fun1051(_ctx), kk_integer_box(w, _ctx), kk_integer_box(e, _ctx), _ctx); /*10002*/
          return kk_std_num_ddouble__ddouble_unbox(_x_x1050, KK_OWNED, _ctx);
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_sum_10803_fun1056__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_10803_fun1056(kk_function_t _fself, kk_box_t _b_x128, kk_box_t _b_x129, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_sum_10803_fun1056(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_sum_10803_fun1056, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_10803_fun1056(kk_function_t _fself, kk_box_t _b_x128, kk_box_t _b_x129, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1057;
  kk_std_num_ddouble__ddouble _x_x1058 = kk_std_num_ddouble__ddouble_unbox(_b_x128, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1059 = kk_std_num_ddouble__ddouble_unbox(_b_x129, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1057 = kk_std_num_ddouble__lp__plus__rp_(_x_x1058, _x_x1059, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1057, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_sum_10803(double hi, double lo, kk_context_t* _ctx) { /* (hi : float64, lo : float64) -> std/text/parse/parse ddouble */ 
  kk_box_t _x_x1055;
  kk_box_t _x_x1060;
  kk_std_num_ddouble__ddouble _x_x1061 = kk_std_num_ddouble__new_Ddouble(hi, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1060 = kk_std_num_ddouble__ddouble_box(_x_x1061, _ctx); /*10000*/
  kk_box_t _x_x1062;
  kk_std_num_ddouble__ddouble _x_x1063 = kk_std_num_ddouble__new_Ddouble(lo, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1062 = kk_std_num_ddouble__ddouble_box(_x_x1063, _ctx); /*10001*/
  _x_x1055 = kk_std_core_hnd__open_none2(kk_std_num_ddouble__new_mlift_pddouble_sum_10803_fun1056(_ctx), _x_x1060, _x_x1062, _ctx); /*10002*/
  return kk_std_num_ddouble__ddouble_unbox(_x_x1055, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1064__t {
  struct kk_function_s _base;
  double hi;
};
static kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1064(kk_function_t _fself, double lo, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_sum_10804_fun1064(double hi, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1064__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1064__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1064, kk_context());
  _self->hi = hi;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1066__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1066(kk_function_t _fself, kk_box_t _b_x136, kk_box_t _b_x137, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_sum_10804_fun1066(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1066, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1066(kk_function_t _fself, kk_box_t _b_x136, kk_box_t _b_x137, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1067;
  kk_std_num_ddouble__ddouble _x_x1068 = kk_std_num_ddouble__ddouble_unbox(_b_x136, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1069 = kk_std_num_ddouble__ddouble_unbox(_b_x137, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1067 = kk_std_num_ddouble__lp__plus__rp_(_x_x1068, _x_x1069, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1067, _ctx);
}
static kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1064(kk_function_t _fself, double lo, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1064__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1064__t*, _fself, _ctx);
  double hi = _self->hi; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(hi, _ctx);}, {}, _ctx)
  kk_box_t _x_x1065;
  kk_box_t _x_x1070;
  kk_std_num_ddouble__ddouble _x_x1071 = kk_std_num_ddouble__new_Ddouble(hi, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1070 = kk_std_num_ddouble__ddouble_box(_x_x1071, _ctx); /*10000*/
  kk_box_t _x_x1072;
  kk_std_num_ddouble__ddouble _x_x1073 = kk_std_num_ddouble__new_Ddouble(lo, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1072 = kk_std_num_ddouble__ddouble_box(_x_x1073, _ctx); /*10001*/
  _x_x1065 = kk_std_core_hnd__open_none2(kk_std_num_ddouble__new_mlift_pddouble_sum_10804_fun1066(_ctx), _x_x1070, _x_x1072, _ctx); /*10002*/
  return kk_std_num_ddouble__ddouble_unbox(_x_x1065, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1075__t {
  struct kk_function_s _base;
  kk_function_t next_10835;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1075(kk_function_t _fself, kk_box_t _b_x142, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_sum_10804_fun1075(kk_function_t next_10835, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1075__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1075__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1075, kk_context());
  _self->next_10835 = next_10835;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1075(kk_function_t _fself, kk_box_t _b_x142, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1075__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_sum_10804_fun1075__t*, _fself, _ctx);
  kk_function_t next_10835 = _self->next_10835; /* (float64) -> std/text/parse/parse std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_function_dup(next_10835, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x_x1076;
  double _x_x1077 = kk_double_unbox(_b_x142, KK_OWNED, _ctx); /*float64*/
  _x_x1076 = kk_function_call(kk_std_num_ddouble__ddouble, (kk_function_t, double, kk_context_t*), next_10835, (next_10835, _x_x1077, _ctx), _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1076, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_sum_10804(double hi, kk_string_t wild___0, kk_context_t* _ctx) { /* (hi : float64, wild_@0 : string) -> std/text/parse/parse ddouble */ 
  kk_string_drop(wild___0, _ctx);
  double x_10834 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
  kk_function_t next_10835 = kk_std_num_ddouble__new_mlift_pddouble_sum_10804_fun1064(hi, _ctx); /*(float64) -> std/text/parse/parse std/num/ddouble/ddouble*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1074 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_sum_10804_fun1075(next_10835, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1074, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_num_ddouble__ddouble, (kk_function_t, double, kk_context_t*), next_10835, (next_10835, x_10834, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1079__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1079(kk_function_t _fself, kk_box_t _b_x146, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_sum_10805_fun1079(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1079, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1079(kk_function_t _fself, kk_box_t _b_x146, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x1080;
  bool b_153 = kk_bool_unbox(_b_x146); /*bool*/;
  if (b_153) {
    _x_x1080 = false; /*bool*/
  }
  else {
    _x_x1080 = true; /*bool*/
  }
  return kk_bool_box(_x_x1080);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1084__t {
  struct kk_function_s _base;
  double hi;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1084(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_sum_10805_fun1084(double hi, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1084__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1084__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1084, kk_context());
  _self->hi = hi;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1084(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1084__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_sum_10805_fun1084__t*, _fself, _ctx);
  double hi = _self->hi; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(hi, _ctx);}, {}, _ctx)
  kk_string_t wild___0_152 = kk_string_unbox(_b_x148); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1085 = kk_std_num_ddouble__mlift_pddouble_sum_10804(hi, wild___0_152, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1085, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_sum_10805(double hi, kk_context_t* _ctx) { /* (hi : float64) -> std/text/parse/parse ddouble */ 
  bool _x_x1_10794 = isfinite(hi); /*bool*/;
  bool _match_x679;
  kk_box_t _x_x1078 = kk_std_core_hnd__open_none1(kk_std_num_ddouble__new_mlift_pddouble_sum_10805_fun1079(_ctx), kk_bool_box(_x_x1_10794), _ctx); /*10001*/
  _match_x679 = kk_bool_unbox(_x_x1078); /*bool*/
  if (_match_x679) {
    return kk_std_num_ddouble__new_Ddouble(hi, 0x0p+0, _ctx);
  }
  {
    kk_string_t x_10838;
    kk_string_t _x_x1081;
    kk_define_string_literal(, _s_x1082, 3, " + ", _ctx)
    _x_x1081 = kk_string_dup(_s_x1082, _ctx); /*string*/
    x_10838 = kk_std_text_parse_pstring(_x_x1081, _ctx); /*string*/
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_10838, _ctx);
      kk_box_t _x_x1083 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_sum_10805_fun1084(hi, _ctx), _ctx); /*10001*/
      return kk_std_num_ddouble__ddouble_unbox(_x_x1083, KK_OWNED, _ctx);
    }
    {
      return kk_std_num_ddouble__mlift_pddouble_sum_10804(hi, x_10838, _ctx);
    }
  }
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun1087__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1087(kk_function_t _fself, kk_box_t _b_x155, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun1087(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_sum_fun1087, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1087(kk_function_t _fself, kk_box_t _b_x155, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1088;
  double _x_x1089 = kk_double_unbox(_b_x155, KK_OWNED, _ctx); /*float64*/
  _x_x1088 = kk_std_num_ddouble__mlift_pddouble_sum_10805(_x_x1089, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1088, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun1091__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1091(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun1091(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_sum_fun1091, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1091(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x1092;
  bool b_186 = kk_bool_unbox(_b_x158); /*bool*/;
  if (b_186) {
    _x_x1092 = false; /*bool*/
  }
  else {
    _x_x1092 = true; /*bool*/
  }
  return kk_bool_box(_x_x1092);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun1096__t {
  struct kk_function_s _base;
  double x_10840;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1096(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun1096(double x_10840, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun1096__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_sum_fun1096__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_sum_fun1096, kk_context());
  _self->x_10840 = x_10840;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1096(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun1096__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_sum_fun1096__t*, _fself, _ctx);
  double x_10840 = _self->x_10840; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(x_10840, _ctx);}, {}, _ctx)
  kk_string_t wild___0_184 = kk_string_unbox(_b_x160); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1097 = kk_std_num_ddouble__mlift_pddouble_sum_10804(x_10840, wild___0_184, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1097, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun1099__t {
  struct kk_function_s _base;
  double x_10840;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1099(kk_function_t _fself, kk_box_t _b_x167, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun1099(double x_10840, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun1099__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_sum_fun1099__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_sum_fun1099, kk_context());
  _self->x_10840 = x_10840;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun1102__t {
  struct kk_function_s _base;
};
static kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_sum_fun1102(kk_function_t _fself, kk_std_num_ddouble__ddouble _x1_x1100, kk_std_num_ddouble__ddouble _x2_x1101, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun1102(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_sum_fun1102, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_sum_fun1102(kk_function_t _fself, kk_std_num_ddouble__ddouble _x1_x1100, kk_std_num_ddouble__ddouble _x2_x1101, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_ddouble__lp__plus__rp_(_x1_x1100, _x2_x1101, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun1103__t {
  struct kk_function_s _base;
  kk_function_t _b_x161_178;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1103(kk_function_t _fself, kk_box_t _b_x164, kk_box_t _b_x165, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun1103(kk_function_t _b_x161_178, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun1103__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_sum_fun1103__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_sum_fun1103, kk_context());
  _self->_b_x161_178 = _b_x161_178;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1103(kk_function_t _fself, kk_box_t _b_x164, kk_box_t _b_x165, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun1103__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_sum_fun1103__t*, _fself, _ctx);
  kk_function_t _b_x161_178 = _self->_b_x161_178; /* (x : std/num/ddouble/ddouble, y : std/num/ddouble/ddouble) -> std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_function_dup(_b_x161_178, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x_x1104;
  kk_std_num_ddouble__ddouble _x_x1105 = kk_std_num_ddouble__ddouble_unbox(_b_x164, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1106 = kk_std_num_ddouble__ddouble_unbox(_b_x165, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1104 = kk_function_call(kk_std_num_ddouble__ddouble, (kk_function_t, kk_std_num_ddouble__ddouble, kk_std_num_ddouble__ddouble, kk_context_t*), _b_x161_178, (_b_x161_178, _x_x1105, _x_x1106, _ctx), _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1104, _ctx);
}
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1099(kk_function_t _fself, kk_box_t _b_x167, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun1099__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_sum_fun1099__t*, _fself, _ctx);
  double x_10840 = _self->x_10840; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(x_10840, _ctx);}, {}, _ctx)
  double lo_185 = kk_double_unbox(_b_x167, KK_OWNED, _ctx); /*float64*/;
  kk_function_t _b_x161_178 = kk_std_num_ddouble_new_pddouble_sum_fun1102(_ctx); /*(x : std/num/ddouble/ddouble, y : std/num/ddouble/ddouble) -> std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _b_x162_179 = kk_std_num_ddouble__new_Ddouble(x_10840, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _b_x163_180 = kk_std_num_ddouble__new_Ddouble(lo_185, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  return kk_std_core_hnd__open_none2(kk_std_num_ddouble_new_pddouble_sum_fun1103(_b_x161_178, _ctx), kk_std_num_ddouble__ddouble_box(_b_x162_179, _ctx), kk_std_num_ddouble__ddouble_box(_b_x163_180, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun1107__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1107(kk_function_t _fself, kk_box_t _b_x171, kk_box_t _b_x172, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun1107(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_sum_fun1107, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1107(kk_function_t _fself, kk_box_t _b_x171, kk_box_t _b_x172, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1108;
  kk_std_num_ddouble__ddouble _x_x1109 = kk_std_num_ddouble__ddouble_unbox(_b_x171, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1110 = kk_std_num_ddouble__ddouble_unbox(_b_x172, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1108 = kk_std_num_ddouble__lp__plus__rp_(_x_x1109, _x_x1110, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1108, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_sum(kk_context_t* _ctx) { /* () -> std/text/parse/parse ddouble */ 
  double x_10840 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1086 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_sum_fun1087(_ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1086, KK_OWNED, _ctx);
  }
  {
    bool _x_x1_10794 = isfinite(x_10840); /*bool*/;
    bool _match_x676;
    kk_box_t _x_x1090 = kk_std_core_hnd__open_none1(kk_std_num_ddouble_new_pddouble_sum_fun1091(_ctx), kk_bool_box(_x_x1_10794), _ctx); /*10001*/
    _match_x676 = kk_bool_unbox(_x_x1090); /*bool*/
    if (_match_x676) {
      return kk_std_num_ddouble__new_Ddouble(x_10840, 0x0p+0, _ctx);
    }
    {
      kk_string_t x_0_10843;
      kk_string_t _x_x1093;
      kk_define_string_literal(, _s_x1094, 3, " + ", _ctx)
      _x_x1093 = kk_string_dup(_s_x1094, _ctx); /*string*/
      x_0_10843 = kk_std_text_parse_pstring(_x_x1093, _ctx); /*string*/
      kk_string_drop(x_0_10843, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1095 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_sum_fun1096(x_10840, _ctx), _ctx); /*10001*/
        return kk_std_num_ddouble__ddouble_unbox(_x_x1095, KK_OWNED, _ctx);
      }
      {
        double x_1_10846 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
        kk_box_t _x_x1098;
        if (kk_yielding(kk_context())) {
          _x_x1098 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_sum_fun1099(x_10840, _ctx), _ctx); /*10001*/
        }
        else {
          kk_box_t _x_x1111;
          kk_std_num_ddouble__ddouble _x_x1112 = kk_std_num_ddouble__new_Ddouble(x_10840, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          _x_x1111 = kk_std_num_ddouble__ddouble_box(_x_x1112, _ctx); /*10000*/
          kk_box_t _x_x1113;
          kk_std_num_ddouble__ddouble _x_x1114 = kk_std_num_ddouble__new_Ddouble(x_1_10846, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          _x_x1113 = kk_std_num_ddouble__ddouble_box(_x_x1114, _ctx); /*10001*/
          _x_x1098 = kk_std_core_hnd__open_none2(kk_std_num_ddouble_new_pddouble_sum_fun1107(_ctx), _x_x1111, _x_x1113, _ctx); /*10001*/
        }
        return kk_std_num_ddouble__ddouble_unbox(_x_x1098, KK_OWNED, _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_fun1116__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_fun1116(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_fun1116(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_fun1116, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_fun1116(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1117 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1117, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_fun1118__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_fun1118(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_fun1118(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_fun1118, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_fun1118(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1119 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1119, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse ddouble */ 
  kk_box_t _x_x1115 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_ddouble_new_pddouble_fun1116(_ctx), kk_std_num_ddouble_new_pddouble_fun1118(_ctx), _ctx); /*10000*/
  return kk_std_num_ddouble__ddouble_unbox(_x_x1115, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_parse_ddouble_10807_fun1121__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x;
};
static kk_box_t kk_std_num_ddouble__mlift_parse_ddouble_10807_fun1121(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_parse_ddouble_10807_fun1121(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_parse_ddouble_10807_fun1121__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_parse_ddouble_10807_fun1121__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_parse_ddouble_10807_fun1121, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_parse_ddouble_10807_fun1121(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_parse_ddouble_10807_fun1121__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_parse_ddouble_10807_fun1121__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x = _self->x; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x, _ctx);}, {}, _ctx)
  kk_unit_t wild_194 = kk_Unit;
  kk_unit_unbox(_b_x192);
  return kk_std_num_ddouble__ddouble_box(x, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_parse_ddouble_10807(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> std/text/parse/parse ddouble */ 
  kk_unit_t x_0_10851 = kk_Unit;
  kk_std_text_parse_eof(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1120 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_parse_ddouble_10807_fun1121(x, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1120, KK_OWNED, _ctx);
  }
  {
    return x;
  }
}


// lift anonymous function
struct kk_std_num_ddouble_parse_ddouble_fun1126__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1126(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_parse_ddouble_fun1126(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_parse_ddouble_fun1126, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_ddouble_parse_ddouble_fun1128__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1128(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_parse_ddouble_fun1128(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_parse_ddouble_fun1128, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1128(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1129 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1129, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_parse_ddouble_fun1130__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1130(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_parse_ddouble_fun1130(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_parse_ddouble_fun1130, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1130(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1131 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1131, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_parse_ddouble_fun1134__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1134(kk_function_t _fself, kk_box_t _b_x200, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_parse_ddouble_fun1134(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_parse_ddouble_fun1134, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1134(kk_function_t _fself, kk_box_t _b_x200, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1135;
  kk_std_num_ddouble__ddouble _x_x1136 = kk_std_num_ddouble__ddouble_unbox(_b_x200, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1135 = kk_std_num_ddouble__mlift_parse_ddouble_10807(_x_x1136, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1135, _ctx);
}
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1126(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble x_10855;
  kk_box_t _x_x1127 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_ddouble_new_parse_ddouble_fun1128(_ctx), kk_std_num_ddouble_new_parse_ddouble_fun1130(_ctx), _ctx); /*10000*/
  x_10855 = kk_std_num_ddouble__ddouble_unbox(_x_x1127, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1132;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1133 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_parse_ddouble_fun1134(_ctx), _ctx); /*10001*/
    _x_x1132 = kk_std_num_ddouble__ddouble_unbox(_x_x1133, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    _x_x1132 = kk_std_num_ddouble__mlift_parse_ddouble_10807(x_10855, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__ddouble_box(_x_x1132, _ctx);
}

kk_std_core_types__maybe kk_std_num_ddouble_parse_ddouble(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<ddouble> */ 
  kk_string_t s_0_10129;
  kk_string_t _x_x1122;
  kk_string_t _x_x1123 = kk_string_trim_left(s,kk_context()); /*string*/
  _x_x1122 = kk_string_trim_right(_x_x1123,kk_context()); /*string*/
  s_0_10129 = kk_std_core_string_to_lower(_x_x1122, _ctx); /*string*/
  kk_std_core_sslice__sslice input_10127;
  kk_string_t _x_x1124 = kk_string_dup(s_0_10129, _ctx); /*string*/
  kk_integer_t _x_x1125 = kk_string_len_int(s_0_10129,kk_context()); /*int*/
  input_10127 = kk_std_core_sslice__new_Sslice(_x_x1124, kk_integer_from_small(0), _x_x1125, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10126 = kk_std_text_parse_parse(input_10127, kk_std_num_ddouble_new_parse_ddouble_fun1126(_ctx), _ctx); /*std/text/parse/parse-error<std/num/ddouble/ddouble>*/;
  if (kk_std_text_parse__is_ParseOk(perr_10126, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x1137 = kk_std_text_parse__as_ParseOk(perr_10126, _ctx);
    kk_box_t _box_x206 = _con_x1137->result;
    kk_std_core_sslice__sslice _pat_0_0 = _con_x1137->rest;
    kk_std_num_ddouble__ddouble x_0 = kk_std_num_ddouble__ddouble_unbox(_box_x206, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10126, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
      kk_box_drop(_box_x206, _ctx);
      kk_datatype_ptr_free(perr_10126, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10126, _ctx);
    }
    return kk_std_core_types__new_Just(kk_std_num_ddouble__ddouble_box(x_0, _ctx), _ctx);
  }
  {
    struct kk_std_text_parse_ParseError* _con_x1138 = kk_std_text_parse__as_ParseError(perr_10126, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x1138->rest;
    kk_string_t msg = _con_x1138->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10126, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr_10126, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10126, _ctx);
    }
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Zero constant

kk_std_num_ddouble__ddouble kk_std_num_ddouble_zero;
 
// Return the sum of a list of doubles.
// Uses [Kahan-Babu&scaron;kan-Neumaier summation](https://en.wikipedia.org/wiki/Kahan_summation_algorithm#Further_enhancements)
// to minimize rounding errors. This
// is more precise as Kahan summation and about as fast.
// `[1.0e3,1.0e97,1.0e3,-1.0e97].sum == 2000.0`
// A. Neumaier, _Rundungsfehleranalyse einiger Verfahren zur Summation endlicher Summen_.
// Math. Mechanik, 54:39--51, 1974.


// lift anonymous function
struct kk_std_num_ddouble_list_fs_sum_fun1147__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc_0;
};
static kk_unit_t kk_std_num_ddouble_list_fs_sum_fun1147(kk_function_t _fself, kk_box_t _b_x242, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_list_fs_new_sum_fun1147(kk_ref_t loc, kk_ref_t loc_0, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_list_fs_sum_fun1147__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_list_fs_sum_fun1147__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_list_fs_sum_fun1147, kk_context());
  _self->loc = loc;
  _self->loc_0 = loc_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_std_num_ddouble_list_fs_sum_fun1147(kk_function_t _fself, kk_box_t _b_x242, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_list_fs_sum_fun1147__t* _self = kk_function_as(struct kk_std_num_ddouble_list_fs_sum_fun1147__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<2804,std/num/ddouble/ddouble> */
  kk_ref_t loc_0 = _self->loc_0; /* local-var<2804,std/num/ddouble/ddouble> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);kk_ref_dup(loc_0, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble x_247 = kk_std_num_ddouble__ddouble_unbox(_b_x242, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble t;
  kk_std_num_ddouble__ddouble _x_x1148;
  kk_box_t _x_x1149;
  kk_ref_t _x_x1150 = kk_ref_dup(loc, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
  _x_x1149 = kk_ref_get(_x_x1150,kk_context()); /*10000*/
  _x_x1148 = kk_std_num_ddouble__ddouble_unbox(_x_x1149, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  t = kk_std_num_ddouble__lp__plus__rp_(_x_x1148, x_247, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble x_1_10139;
  kk_box_t _x_x1151;
  kk_ref_t _x_x1152 = kk_ref_dup(loc, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
  _x_x1151 = kk_ref_get(_x_x1152,kk_context()); /*10000*/
  x_1_10139 = kk_std_num_ddouble__ddouble_unbox(_x_x1151, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble x_0_10137;
  bool _match_x672;
  double _x_x1153;
  {
    double _x = x_1_10139.hi;
    _x_x1153 = _x; /*float64*/
  }
  _match_x672 = (_x_x1153 < (0x0p+0)); /*bool*/
  if (_match_x672) {
    double _x_x1154;
    double _x_x1155;
    {
      double _x_0 = x_1_10139.hi;
      _x_x1155 = _x_0; /*float64*/
    }
    _x_x1154 = (-_x_x1155); /*float64*/
    double _x_x1156;
    double _x_x1157;
    {
      double _x_0_0 = x_1_10139.lo;
      _x_x1157 = _x_0_0; /*float64*/
    }
    _x_x1156 = (-_x_x1157); /*float64*/
    x_0_10137 = kk_std_num_ddouble__new_Ddouble(_x_x1154, _x_x1156, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    x_0_10137 = x_1_10139; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble y_10138 = kk_std_num_ddouble_abs(x_247, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble c;
  bool _match_x670;
  kk_std_core_types__order _x_x1158;
  kk_std_core_types__order _match_x671;
  double _x_x1159;
  {
    double _x_1 = x_0_10137.hi;
    _x_x1159 = _x_1; /*float64*/
  }
  double _x_x1160;
  {
    double _x_0_1 = y_10138.hi;
    _x_x1160 = _x_0_1; /*float64*/
  }
  _match_x671 = kk_std_num_float64_cmp(_x_x1159, _x_x1160, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x671, _ctx)) {
    double _x_x1161;
    {
      double _x_1_0 = x_0_10137.lo;
      _x_x1161 = _x_1_0; /*float64*/
    }
    double _x_x1162;
    {
      double _x_2 = y_10138.lo;
      _x_x1162 = _x_2; /*float64*/
    }
    _x_x1158 = kk_std_num_float64_cmp(_x_x1161, _x_x1162, _ctx); /*order*/
  }
  else {
    _x_x1158 = _match_x671; /*order*/
  }
  _match_x670 = kk_std_core_order__lp__excl__eq__rp_(_x_x1158, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x670) {
    kk_std_num_ddouble__ddouble x_3_10143;
    kk_box_t _x_x1163;
    kk_ref_t _x_x1164 = kk_ref_dup(loc, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
    _x_x1163 = kk_ref_get(_x_x1164,kk_context()); /*10000*/
    x_3_10143 = kk_std_num_ddouble__ddouble_unbox(_x_x1163, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1165;
    kk_std_num_ddouble__ddouble _x_x1166;
    double _x_x1167;
    double _x_x1168;
    {
      double _x_3 = t.hi;
      _x_x1168 = _x_3; /*float64*/
    }
    _x_x1167 = (-_x_x1168); /*float64*/
    double _x_x1169;
    double _x_x1170;
    {
      double _x_0_2 = t.lo;
      _x_x1170 = _x_0_2; /*float64*/
    }
    _x_x1169 = (-_x_x1170); /*float64*/
    _x_x1166 = kk_std_num_ddouble__new_Ddouble(_x_x1167, _x_x1169, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1165 = kk_std_num_ddouble__lp__plus__rp_(x_3_10143, _x_x1166, _ctx); /*std/num/ddouble/ddouble*/
    c = kk_std_num_ddouble__lp__plus__rp_(_x_x1165, x_247, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x1171;
    kk_std_num_ddouble__ddouble _x_x1172;
    double _x_x1173;
    double _x_x1174;
    {
      double _x_4 = t.hi;
      _x_x1174 = _x_4; /*float64*/
    }
    _x_x1173 = (-_x_x1174); /*float64*/
    double _x_x1175;
    double _x_x1176;
    {
      double _x_0_3 = t.lo;
      _x_x1176 = _x_0_3; /*float64*/
    }
    _x_x1175 = (-_x_x1176); /*float64*/
    _x_x1172 = kk_std_num_ddouble__new_Ddouble(_x_x1173, _x_x1175, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1171 = kk_std_num_ddouble__lp__plus__rp_(x_247, _x_x1172, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1177;
    kk_box_t _x_x1178;
    kk_ref_t _x_x1179 = kk_ref_dup(loc, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
    _x_x1178 = kk_ref_get(_x_x1179,kk_context()); /*10000*/
    _x_x1177 = kk_std_num_ddouble__ddouble_unbox(_x_x1178, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    c = kk_std_num_ddouble__lp__plus__rp_(_x_x1171, _x_x1177, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _b_x233_235;
  kk_std_num_ddouble__ddouble _x_x1180;
  kk_box_t _x_x1181;
  kk_ref_t _x_x1182 = kk_ref_dup(loc_0, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
  _x_x1181 = kk_ref_get(_x_x1182,kk_context()); /*10000*/
  _x_x1180 = kk_std_num_ddouble__ddouble_unbox(_x_x1181, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _b_x233_235 = kk_std_num_ddouble__lp__plus__rp_(_x_x1180, c, _ctx); /*std/num/ddouble/ddouble*/
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x669 = kk_Unit;
  kk_ref_set_borrow(loc_0,(kk_std_num_ddouble__ddouble_box(_b_x233_235, _ctx)),kk_context());
  kk_ref_drop(loc_0, _ctx);
  _brw_x669;
  kk_unit_t _brw_x668 = kk_Unit;
  kk_ref_set_borrow(loc,(kk_std_num_ddouble__ddouble_box(t, _ctx)),kk_context());
  kk_ref_drop(loc, _ctx);
  _brw_x668; return kk_Unit;
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs_sum(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<ddouble>) -> ddouble */ 
  kk_ref_t loc = kk_ref_alloc((kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx)),kk_context()); /*local-var<2804,std/num/ddouble/ddouble>*/;
  kk_ref_t loc_0 = kk_ref_alloc((kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx)),kk_context()); /*local-var<2804,std/num/ddouble/ddouble>*/;
  kk_unit_t ___0 = kk_Unit;
  kk_function_t _x_x1146;
  kk_ref_dup(loc, _ctx);
  kk_ref_dup(loc_0, _ctx);
  _x_x1146 = kk_std_num_ddouble_list_fs_new_sum_fun1147(loc, loc_0, _ctx); /*(10001) -> 10002 ()*/
  kk_std_core_list_foreach(xs, _x_x1146, _ctx);
  kk_std_num_ddouble__ddouble res_0;
  kk_std_num_ddouble__ddouble _x_x1183;
  kk_box_t _x_x1184;
  kk_ref_t _x_x1185 = kk_ref_dup(loc, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
  _x_x1184 = kk_ref_get(_x_x1185,kk_context()); /*10000*/
  _x_x1183 = kk_std_num_ddouble__ddouble_unbox(_x_x1184, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1186;
  kk_box_t _x_x1187;
  kk_ref_t _x_x1188 = kk_ref_dup(loc_0, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
  _x_x1187 = kk_ref_get(_x_x1188,kk_context()); /*10000*/
  _x_x1186 = kk_std_num_ddouble__ddouble_unbox(_x_x1187, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  res_0 = kk_std_num_ddouble__lp__plus__rp_(_x_x1183, _x_x1186, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble res;
  kk_box_t _x_x1189 = kk_std_core_hnd_prompt_local_var(loc_0, kk_std_num_ddouble__ddouble_box(res_0, _ctx), _ctx); /*10001*/
  res = kk_std_num_ddouble__ddouble_unbox(_x_x1189, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_box_t _x_x1190 = kk_std_core_hnd_prompt_local_var(loc, kk_std_num_ddouble__ddouble_box(res, _ctx), _ctx); /*10001*/
  return kk_std_num_ddouble__ddouble_unbox(_x_x1190, KK_OWNED, _ctx);
}
 
// &pi;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi;
 
// 2&pi;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_twopi;
 
// &pi;/2

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi2;
 
// &pi;/4

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi4;
 
// &pi;/16

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi16;
 
// 3&pi;/4

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi34;
 
// The _e_ constant.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_e;
 
// The natural logarithm of 2

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_ln2;
 
// The natural logarithm of 10

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_ln10;
 
// The base-2 logarithm of _e_.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log2e;
 
// The base-10 logarithm of _e_.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log10e;
 
// The square-root of 2

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_sqrt2;
 
// `1.0 / sqrt(2.0)`

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_sqrt12;
 
// [Euler's constant](https://en.wikipedia.org/wiki/Euler%E2%80%93Mascheroni_constant)

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_euler;
 
// The 'machine epsilon': this is not well-defined for a `:ddouble` in general since
// the difference between 1.0 and the next representable `:ddouble` value is `dd-true-min`.
// Instead, we take the square of `flt-epsilon`, i.e. 2^-104^.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_epsilon;
 
// 8*dd-epsilon

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_epsilon8;
 
// The maximum representable `:ddouble`

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_max;
 
// The smallest positive `:ddouble` that is still normalized

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_min;
 
// The smallest positive `:ddouble`  (which is subnormal).

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_true_min;
 
// Positive infinity

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_posinf;
 
// Negative infinity

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_neginf;

kk_integer_t kk_std_num_ddouble_dd_max_prec;

kk_integer_t kk_std_num_ddouble_dd_default_prec;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_two;

kk_std_num_ddouble__edouble kk_std_num_ddouble_edouble_fs__copy(kk_std_num_ddouble__edouble _this, kk_std_core_types__optional num, kk_std_core_types__optional err, kk_context_t* _ctx) { /* (edouble, num : ? float64, err : ? float64) -> edouble */ 
  double _x_x1219;
  if (kk_std_core_types__is_Optional(num, _ctx)) {
    kk_box_t _box_x264 = num._cons._Optional.value;
    double _uniq_num_3869 = kk_double_unbox(_box_x264, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(num, _ctx);
    _x_x1219 = _uniq_num_3869; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(num, _ctx);
    {
      double _x = _this.num;
      _x_x1219 = _x; /*float64*/
    }
  }
  double _x_x1220;
  if (kk_std_core_types__is_Optional(err, _ctx)) {
    kk_box_t _box_x265 = err._cons._Optional.value;
    double _uniq_err_3877 = kk_double_unbox(_box_x265, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(err, _ctx);
    _x_x1220 = _uniq_err_3877; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(err, _ctx);
    {
      double _x_0 = _this.err;
      _x_x1220 = _x_0; /*float64*/
    }
  }
  return kk_std_num_ddouble__new_Edouble(_x_x1219, _x_x1220, _ctx);
}
 
// Round a `:ddouble` to the nearest integer, rounding to the nearest even number in case of a tie.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_round(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double r;
  double _x_x1221;
  {
    double _x = x.hi;
    _x_x1221 = _x; /*float64*/
  }
  r = kk_double_round_even(_x_x1221,kk_context()); /*float64*/
  double diff;
  double _x_x1222;
  {
    double _x_0 = x.hi;
    _x_x1222 = _x_0; /*float64*/
  }
  diff = (r - _x_x1222); /*float64*/
  bool _match_x652 = (diff == (0x0p+0)); /*bool*/;
  if (_match_x652) {
    double _x_x1223;
    double _x_x1224;
    {
      double _x_1 = x.lo;
      _x_x1224 = _x_1; /*float64*/
    }
    _x_x1223 = kk_double_round_even(_x_x1224,kk_context()); /*float64*/
    return kk_std_num_ddouble_dquicksum(r, _x_x1223, _ctx);
  }
  {
    double d_10166;
    bool _match_x653 = (diff == (0x1p-1)); /*bool*/;
    if (_match_x653) {
      bool _match_x656;
      double _x_x1225;
      {
        double _x_2 = x.lo;
        _x_x1225 = _x_2; /*float64*/
      }
      _match_x656 = (_x_x1225 < (0x0p+0)); /*bool*/
      if (_match_x656) {
        d_10166 = (r - 0x1p0); /*float64*/
      }
      else {
        bool _match_x657 = (diff == (-0x1p-1)); /*bool*/;
        if (_match_x657) {
          bool _match_x658;
          double _x_x1226;
          {
            double _x_3 = x.lo;
            _x_x1226 = _x_3; /*float64*/
          }
          _match_x658 = (_x_x1226 > (0x0p+0)); /*bool*/
          if (_match_x658) {
            d_10166 = (r + 0x1p0); /*float64*/
          }
          else {
            d_10166 = r; /*float64*/
          }
        }
        else {
          d_10166 = r; /*float64*/
        }
      }
    }
    else {
      bool _match_x654 = (diff == (-0x1p-1)); /*bool*/;
      if (_match_x654) {
        bool _match_x655;
        double _x_x1227;
        {
          double _x_4 = x.lo;
          _x_x1227 = _x_4; /*float64*/
        }
        _match_x655 = (_x_x1227 > (0x0p+0)); /*bool*/
        if (_match_x655) {
          d_10166 = (r + 0x1p0); /*float64*/
        }
        else {
          d_10166 = r; /*float64*/
        }
      }
      else {
        d_10166 = r; /*float64*/
      }
    }
    return kk_std_num_ddouble__new_Ddouble(d_10166, 0x0p+0, _ctx);
  }
}
 
// Remainder of two `:ddouble`s

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__perc__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble n;
  kk_std_num_ddouble__ddouble _x_x1228 = kk_std_num_ddouble__lp__fs__rp_(x, y, _ctx); /*std/num/ddouble/ddouble*/
  n = kk_std_num_ddouble_round(_x_x1228, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble y_0_10174 = kk_std_num_ddouble__lp__star__rp_(n, y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x_x1229;
  double _x_x1230;
  double _x_x1231;
  {
    double _x = y_0_10174.hi;
    _x_x1231 = _x; /*float64*/
  }
  _x_x1230 = (-_x_x1231); /*float64*/
  double _x_x1232;
  double _x_x1233;
  {
    double _x_0 = y_0_10174.lo;
    _x_x1233 = _x_0; /*float64*/
  }
  _x_x1232 = (-_x_x1233); /*float64*/
  _x_x1229 = kk_std_num_ddouble__new_Ddouble(_x_x1230, _x_x1232, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x_x1229, _ctx);
}
 
// Division and remainder of two `:ddouble`s

kk_std_core_types__tuple2 kk_std_num_ddouble_divrem(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> (ddouble, ddouble) */ 
  kk_std_num_ddouble__ddouble n;
  kk_std_num_ddouble__ddouble _x_x1234 = kk_std_num_ddouble__lp__fs__rp_(x, y, _ctx); /*std/num/ddouble/ddouble*/
  n = kk_std_num_ddouble_round(_x_x1234, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble y_0_10176 = kk_std_num_ddouble__lp__star__rp_(n, y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _b_x267_269;
  kk_std_num_ddouble__ddouble _x_x1235;
  double _x_x1236;
  double _x_x1237;
  {
    double _x = y_0_10176.hi;
    _x_x1237 = _x; /*float64*/
  }
  _x_x1236 = (-_x_x1237); /*float64*/
  double _x_x1238;
  double _x_x1239;
  {
    double _x_0 = y_0_10176.lo;
    _x_x1239 = _x_0; /*float64*/
  }
  _x_x1238 = (-_x_x1239); /*float64*/
  _x_x1235 = kk_std_num_ddouble__new_Ddouble(_x_x1236, _x_x1238, _ctx); /*std/num/ddouble/ddouble*/
  _b_x267_269 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x1235, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(n, _ctx), kk_std_num_ddouble__ddouble_box(_b_x267_269, _ctx), _ctx);
}
 
// Convert a `:ddouble` to a `:decimal` up to a given precision `prec` (= `-1`).
// A negative precision converts precisely. Returns 0 for non-finite `:ddouble`'s.

kk_std_num_decimal__decimal kk_std_num_ddouble_decimal(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : ? int) -> std/num/decimal/decimal */ 
  bool b_10177;
  bool _match_x651;
  double _x_x1240;
  {
    double _x = x.hi;
    _x_x1240 = _x; /*float64*/
  }
  _match_x651 = isfinite(_x_x1240); /*bool*/
  if (_match_x651) {
    double _x_x1241;
    {
      double _x_0 = x.lo;
      _x_x1241 = _x_0; /*float64*/
    }
    b_10177 = isfinite(_x_x1241); /*bool*/
  }
  else {
    b_10177 = false; /*bool*/
  }
  if (b_10177) {
    kk_integer_t _b_x271_276;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x270 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_4427 = kk_integer_unbox(_box_x270, _ctx);
      kk_integer_dup(_uniq_prec_4427, _ctx);
      _b_x271_276 = _uniq_prec_4427; /*int*/
    }
    else {
      _b_x271_276 = kk_integer_from_small(-1); /*int*/
    }
    kk_integer_t _b_x273_277;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x272 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_4427_0 = kk_integer_unbox(_box_x272, _ctx);
      kk_integer_dup(_uniq_prec_4427_0, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _b_x273_277 = _uniq_prec_4427_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _b_x273_277 = kk_integer_from_small(-1); /*int*/
    }
    kk_std_num_decimal__decimal _x_x1242;
    double _x_x1243;
    {
      double _x_1 = x.hi;
      _x_x1243 = _x_1; /*float64*/
    }
    kk_std_core_types__optional _x_x1244 = kk_std_core_types__new_Optional(kk_integer_box(_b_x271_276, _ctx), _ctx); /*? 10003*/
    _x_x1242 = kk_std_num_decimal_float64_fs_decimal(_x_x1243, _x_x1244, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal _x_x1245;
    double _x_x1246;
    {
      double _x_0_0 = x.lo;
      _x_x1246 = _x_0_0; /*float64*/
    }
    kk_std_core_types__optional _x_x1247 = kk_std_core_types__new_Optional(kk_integer_box(_b_x273_277, _ctx), _ctx); /*? 10003*/
    _x_x1245 = kk_std_num_decimal_float64_fs_decimal(_x_x1246, _x_x1247, _ctx); /*std/num/decimal/decimal*/
    return kk_std_num_decimal__lp__plus__rp_(_x_x1242, _x_x1245, _ctx);
  }
  {
    kk_std_core_types__optional_drop(prec, _ctx);
    kk_std_core_types__optional _x_x1248;
    kk_box_t _x_x1249;
    kk_integer_t _x_x1250;
    kk_std_core_types__optional _match_x650 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x650, _ctx)) {
      kk_box_t _box_x274 = _match_x650._cons._Optional.value;
      kk_integer_t _uniq_exp_1807 = kk_integer_unbox(_box_x274, _ctx);
      kk_integer_dup(_uniq_exp_1807, _ctx);
      kk_std_core_types__optional_drop(_match_x650, _ctx);
      _x_x1250 = _uniq_exp_1807; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x650, _ctx);
      _x_x1250 = kk_integer_from_small(0); /*int*/
    }
    _x_x1249 = kk_integer_box(_x_x1250, _ctx); /*10003*/
    _x_x1248 = kk_std_core_types__new_Optional(_x_x1249, _ctx); /*? 10003*/
    return kk_std_num_decimal_decimal_exp(kk_integer_from_small(0), _x_x1248, _ctx);
  }
}
 
// Convert a `:ddouble` to the nearest integer (rounding to the nearest even number in case of a tie)

kk_integer_t kk_std_num_ddouble_int(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional nonfin, kk_context_t* _ctx) { /* (x : ddouble, nonfin : ? int) -> int */ 
  bool b_10182;
  bool _match_x649;
  double _x_x1251;
  {
    double _x = x.hi;
    _x_x1251 = _x; /*float64*/
  }
  _match_x649 = isfinite(_x_x1251); /*bool*/
  if (_match_x649) {
    double _x_x1252;
    {
      double _x_0 = x.lo;
      _x_x1252 = _x_0; /*float64*/
    }
    b_10182 = isfinite(_x_x1252); /*bool*/
  }
  else {
    b_10182 = false; /*bool*/
  }
  if (b_10182) {
    kk_std_core_types__optional_drop(nonfin, _ctx);
    kk_std_num_decimal__decimal _x_x1253;
    kk_std_num_ddouble__ddouble _x_x1254 = kk_std_num_ddouble_round(x, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1253 = kk_std_num_ddouble_decimal(_x_x1254, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
    return kk_std_num_decimal_int(_x_x1253, kk_std_core_types__new_None(_ctx), _ctx);
  }
  if (kk_std_core_types__is_Optional(nonfin, _ctx)) {
    kk_box_t _box_x279 = nonfin._cons._Optional.value;
    kk_integer_t _uniq_nonfin_4504 = kk_integer_unbox(_box_x279, _ctx);
    kk_integer_dup(_uniq_nonfin_4504, _ctx);
    kk_std_core_types__optional_drop(nonfin, _ctx);
    return _uniq_nonfin_4504;
  }
  {
    kk_std_core_types__optional_drop(nonfin, _ctx);
    return kk_integer_from_small(0);
  }
}
 
// Round to negative infinity.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_floor(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double r;
  double _x_x1255;
  {
    double _x = x.hi;
    _x_x1255 = _x; /*float64*/
  }
  r = floor(_x_x1255); /*float64*/
  bool _match_x648;
  double _x_x1256;
  {
    double _x_0 = x.hi;
    _x_x1256 = _x_0; /*float64*/
  }
  _match_x648 = (r == _x_x1256); /*bool*/
  if (_match_x648) {
    double _x_x1257;
    double _x_x1258;
    {
      double _x_1 = x.lo;
      _x_x1258 = _x_1; /*float64*/
    }
    _x_x1257 = floor(_x_x1258); /*float64*/
    return kk_std_num_ddouble_dquicksum(r, _x_x1257, _ctx);
  }
  {
    return kk_std_num_ddouble__new_Ddouble(r, 0x0p+0, _ctx);
  }
}
 
// Round to positive infinity.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ceiling(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double r;
  double _x_x1259;
  {
    double _x = x.hi;
    _x_x1259 = _x; /*float64*/
  }
  r = ceil(_x_x1259); /*float64*/
  bool _match_x647;
  double _x_x1260;
  {
    double _x_0 = x.hi;
    _x_x1260 = _x_0; /*float64*/
  }
  _match_x647 = (r == _x_x1260); /*bool*/
  if (_match_x647) {
    double _x_x1261;
    double _x_x1262;
    {
      double _x_1 = x.lo;
      _x_x1262 = _x_1; /*float64*/
    }
    _x_x1261 = ceil(_x_x1262); /*float64*/
    return kk_std_num_ddouble_dquicksum(r, _x_x1261, _ctx);
  }
  {
    return kk_std_num_ddouble__new_Ddouble(r, 0x0p+0, _ctx);
  }
}
 
// The fraction of `x` such that `x.truncate + x.fraction == x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_fraction(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble y_10193;
  bool _match_x645;
  double _x_x1264;
  {
    double _x = x.hi;
    _x_x1264 = _x; /*float64*/
  }
  _match_x645 = (_x_x1264 < (0x0p+0)); /*bool*/
  if (_match_x645) {
    y_10193 = kk_std_num_ddouble_ceiling(x, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    y_10193 = kk_std_num_ddouble_floor(x, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x1265;
  double _x_x1266;
  double _x_x1267;
  {
    double _x_0 = y_10193.hi;
    _x_x1267 = _x_0; /*float64*/
  }
  _x_x1266 = (-_x_x1267); /*float64*/
  double _x_x1268;
  double _x_x1269;
  {
    double _x_0_0 = y_10193.lo;
    _x_x1269 = _x_0_0; /*float64*/
  }
  _x_x1268 = (-_x_x1269); /*float64*/
  _x_x1265 = kk_std_num_ddouble__new_Ddouble(_x_x1266, _x_x1268, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x_x1265, _ctx);
}
 
// Round a `:ddouble` to a specified precision.
// Uses `round` if the precision is smaller or equal to zero.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_round_to_prec(kk_std_num_ddouble__ddouble x, kk_integer_t prec, kk_context_t* _ctx) { /* (x : ddouble, prec : int) -> ddouble */ 
  bool _match_x643 = kk_integer_lte_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x643) {
    kk_integer_drop(prec, _ctx);
    return kk_std_num_ddouble_round(x, _ctx);
  }
  {
    bool _match_x644 = kk_integer_gt_borrow(prec,(kk_integer_from_small(31)),kk_context()); /*bool*/;
    if (_match_x644) {
      kk_integer_drop(prec, _ctx);
      return x;
    }
    {
      kk_std_num_ddouble__ddouble p = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, prec, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x_x1275;
      kk_std_num_ddouble__ddouble _x_x1276 = kk_std_num_ddouble__lp__star__rp_(x, p, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1275 = kk_std_num_ddouble_round(_x_x1276, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__fs__rp_(_x_x1275, p, _ctx);
    }
  }
}
 
// Create a `:ddouble` `x` such that `x` equals `d`&middot;10^`e`^.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_float64_fs_ddouble_exp(double d, kk_integer_t e, kk_context_t* _ctx) { /* (d : float64, e : int) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_10199 = kk_std_num_ddouble__new_Ddouble(d, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x642 = kk_integer_is_zero_borrow(e); /*bool*/;
  if (_match_x642) {
    kk_integer_drop(e, _ctx);
    return x_10199;
  }
  {
    kk_std_num_ddouble__ddouble _x_x1282 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__star__rp_(x_10199, _x_x1282, _ctx);
  }
}
 
// Create a `:ddouble` `x` such that `x` equals `i`&middot;10^`e`^.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_int_fs_ddouble_exp(kk_integer_t i, kk_integer_t exp_0, kk_context_t* _ctx) { /* (i : int, exp : int) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_10203 = kk_std_num_ddouble_ddouble_int_exp(i, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x641 = kk_integer_is_zero_borrow(exp_0); /*bool*/;
  if (_match_x641) {
    kk_integer_drop(exp_0, _ctx);
    return x_10203;
  }
  {
    kk_std_num_ddouble__ddouble _x_x1283 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, exp_0, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__star__rp_(x_10203, _x_x1283, _ctx);
  }
}
 
// The square root of a non-negative `:ddouble` `x`.
// For negative `x`, `dd-nan` is returned.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sqrt(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x639;
  double _x_x1290;
  {
    double _x = x.hi;
    _x_x1290 = _x; /*float64*/
  }
  _match_x639 = (_x_x1290 == (0x0p+0)); /*bool*/
  if (_match_x639) {
    return kk_std_num_ddouble_zero;
  }
  {
    bool _match_x640;
    double _x_x1291;
    {
      double _x_0 = x.hi;
      _x_x1291 = _x_0; /*float64*/
    }
    _match_x640 = (_x_x1291 < (0x0p+0)); /*bool*/
    if (_match_x640) {
      return kk_std_num_ddouble_dd_nan;
    }
    {
      double a;
      double _x_x1292;
      double _x_x1293;
      {
        double _x_1 = x.hi;
        _x_x1293 = _x_1; /*float64*/
      }
      _x_x1292 = sqrt(_x_x1293); /*float64*/
      a = (0x1p0 / _x_x1292); /*float64*/
      double t1;
      double _x_x1294;
      {
        double _x_2 = x.hi;
        _x_x1294 = _x_2; /*float64*/
      }
      t1 = (_x_x1294 * a); /*float64*/
      kk_std_num_ddouble__ddouble y_10221;
      kk_std_num_ddouble__ddouble _x_x1295 = kk_std_num_ddouble__new_Ddouble(t1, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      y_10221 = kk_std_num_ddouble_sqr(_x_x1295, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble ddouble_0_3_10219;
      kk_std_num_ddouble__ddouble _x_x1296;
      double _x_x1297;
      double _x_x1298;
      {
        double _x_3 = y_10221.hi;
        _x_x1298 = _x_3; /*float64*/
      }
      _x_x1297 = (-_x_x1298); /*float64*/
      double _x_x1299;
      double _x_x1300;
      {
        double _x_0_0 = y_10221.lo;
        _x_x1300 = _x_0_0; /*float64*/
      }
      _x_x1299 = (-_x_x1300); /*float64*/
      _x_x1296 = kk_std_num_ddouble__new_Ddouble(_x_x1297, _x_x1299, _ctx); /*std/num/ddouble/ddouble*/
      ddouble_0_3_10219 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x1296, _ctx); /*std/num/ddouble/ddouble*/
      double t2;
      double _x_x1301;
      double _x_x1302;
      {
        double _x_3_0 = ddouble_0_3_10219.hi;
        _x_x1302 = _x_3_0; /*float64*/
      }
      _x_x1301 = (_x_x1302 * a); /*float64*/
      t2 = (_x_x1301 * (0x1p-1)); /*float64*/
      return kk_std_num_ddouble_dsum(t1, t2, _ctx);
    }
  }
}

kk_std_core_types__list kk_std_num_ddouble_exp_factors;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp_approx(kk_std_num_ddouble__ddouble p, kk_std_num_ddouble__ddouble t, kk_std_num_ddouble__ddouble r, double eps, kk_std_core_types__list fs, kk_std_core_types__optional s, kk_context_t* _ctx) { /* (p : ddouble, t : ddouble, r : ddouble, eps : float64, fs : list<ddouble>, s : ? ddouble) -> ddouble */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(fs, _ctx)) {
    kk_std_num_ddouble__ddouble _x_x1332;
    if (kk_std_core_types__is_Optional(s, _ctx)) {
      kk_box_t _box_x308 = s._cons._Optional.value;
      kk_std_num_ddouble__ddouble _uniq_s_5346 = kk_std_num_ddouble__ddouble_unbox(_box_x308, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(s, _ctx);
      _x_x1332 = _uniq_s_5346; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_core_types__optional_drop(s, _ctx);
      _x_x1332 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
    }
    return kk_std_num_ddouble__lp__plus__rp_(_x_x1332, t, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1333 = kk_std_core_types__as_Cons(fs, _ctx);
    kk_box_t _box_x309 = _con_x1333->head;
    kk_std_num_ddouble__ddouble f = kk_std_num_ddouble__ddouble_unbox(_box_x309, KK_BORROWED, _ctx);
    kk_std_core_types__list fs1 = _con_x1333->tail;
    if kk_likely(kk_datatype_ptr_is_unique(fs, _ctx)) {
      kk_box_drop(_box_x309, _ctx);
      kk_datatype_ptr_free(fs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(fs1, _ctx);
      kk_datatype_ptr_decref(fs, _ctx);
    }
    kk_std_num_ddouble__ddouble s1;
    kk_std_num_ddouble__ddouble _x_x1334;
    if (kk_std_core_types__is_Optional(s, _ctx)) {
      kk_box_t _box_x310 = s._cons._Optional.value;
      kk_std_num_ddouble__ddouble _uniq_s_5346_0 = kk_std_num_ddouble__ddouble_unbox(_box_x310, KK_BORROWED, _ctx);
      _x_x1334 = _uniq_s_5346_0; /*std/num/ddouble/ddouble*/
    }
    else {
      _x_x1334 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
    }
    s1 = kk_std_num_ddouble__lp__plus__rp_(_x_x1334, t, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble p1 = kk_std_num_ddouble__lp__star__rp_(p, r, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble t1 = kk_std_num_ddouble__lp__star__rp_(p1, f, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_x638;
    double _x_x1335;
    double _x_x1336;
    {
      double _x = t1.hi;
      _x_x1336 = _x; /*float64*/
    }
    _x_x1335 = kk_double_abs(_x_x1336); /*float64*/
    _match_x638 = (_x_x1335 <= eps); /*bool*/
    if (_match_x638) {
      kk_std_core_types__list_drop(fs1, _ctx);
      kk_std_num_ddouble__ddouble _x_x1337;
      if (kk_std_core_types__is_Optional(s, _ctx)) {
        kk_box_t _box_x311 = s._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_s_5346_1 = kk_std_num_ddouble__ddouble_unbox(_box_x311, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(s, _ctx);
        _x_x1337 = _uniq_s_5346_1; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_core_types__optional_drop(s, _ctx);
        _x_x1337 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
      }
      return kk_std_num_ddouble__lp__plus__rp_(_x_x1337, t, _ctx);
    }
    {
      kk_std_core_types__optional_drop(s, _ctx);
      { // tailcall
        kk_std_core_types__optional _x_x1338 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(s1, _ctx), _ctx); /*? 10003*/
        p = p1;
        t = t1;
        fs = fs1;
        s = _x_x1338;
        goto kk__tailcall;
      }
    }
  }
}
 
// Return _e_ (`dd-e`) to the power of `x`.


// lift anonymous function
struct kk_std_num_ddouble_exp_fun1376__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_unit_t kk_std_num_ddouble_exp_fun1376(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_exp_fun1376(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_exp_fun1376__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_exp_fun1376__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_exp_fun1376, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_std_num_ddouble_exp_fun1376(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_exp_fun1376__t* _self = kk_function_as(struct kk_std_num_ddouble_exp_fun1376__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<5910,std/num/ddouble/ddouble> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble x_4_10253;
  kk_box_t _x_x1377;
  kk_ref_t _x_x1378 = kk_ref_dup(loc, _ctx); /*local-var<5910,std/num/ddouble/ddouble>*/
  _x_x1377 = kk_ref_get(_x_x1378,kk_context()); /*10000*/
  x_4_10253 = kk_std_num_ddouble__ddouble_unbox(_x_x1377, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _b_x323_325;
  kk_std_num_ddouble__ddouble _x_x1379;
  double _x_x1380;
  double _x_x1381;
  {
    double _x_7 = x_4_10253.hi;
    _x_x1381 = _x_7; /*float64*/
  }
  _x_x1380 = (_x_x1381 * 0x1p1); /*float64*/
  double _x_x1382;
  double _x_x1383;
  {
    double _x_8 = x_4_10253.lo;
    _x_x1383 = _x_8; /*float64*/
  }
  _x_x1382 = (_x_x1383 * 0x1p1); /*float64*/
  _x_x1379 = kk_std_num_ddouble__new_Ddouble(_x_x1380, _x_x1382, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1384;
  kk_std_num_ddouble__ddouble _x_x1385;
  kk_box_t _x_x1386;
  kk_ref_t _x_x1387 = kk_ref_dup(loc, _ctx); /*local-var<5910,std/num/ddouble/ddouble>*/
  _x_x1386 = kk_ref_get(_x_x1387,kk_context()); /*10000*/
  _x_x1385 = kk_std_num_ddouble__ddouble_unbox(_x_x1386, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1384 = kk_std_num_ddouble_sqr(_x_x1385, _ctx); /*std/num/ddouble/ddouble*/
  _b_x323_325 = kk_std_num_ddouble__lp__plus__rp_(_x_x1379, _x_x1384, _ctx); /*std/num/ddouble/ddouble*/
  kk_unit_t _brw_x636 = kk_Unit;
  kk_ref_set_borrow(loc,(kk_std_num_ddouble__ddouble_box(_b_x323_325, _ctx)),kk_context());
  kk_ref_drop(loc, _ctx);
  _brw_x636; return kk_Unit;
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double inv_k = (0x1p0 / 0x1p9); /*float64*/;
  bool _match_x632;
  double _x_x1339;
  {
    double _x = x.hi;
    _x_x1339 = _x; /*float64*/
  }
  _match_x632 = (_x_x1339 <= (-0x1.628p9)); /*bool*/
  if (_match_x632) {
    return kk_std_num_ddouble_zero;
  }
  {
    bool _match_x633;
    double _x_x1340;
    {
      double _x_0 = x.hi;
      _x_x1340 = _x_0; /*float64*/
    }
    _match_x633 = (_x_x1340 >= (0x1.628p9)); /*bool*/
    if (_match_x633) {
      return kk_std_num_ddouble_dd_posinf;
    }
    {
      bool _match_x634;
      double _x_x1341;
      {
        double _x_1 = x.hi;
        _x_x1341 = _x_1; /*float64*/
      }
      _match_x634 = (_x_x1341 == (0x0p+0)); /*bool*/
      if (_match_x634) {
        return kk_std_num_ddouble_one;
      }
      {
        bool _match_x635;
        kk_std_core_types__order _x_x1342;
        kk_std_core_types__order _match_x637;
        double _x_x1343;
        {
          double _x_2 = x.hi;
          _x_x1343 = _x_2; /*float64*/
        }
        double _x_x1344;
        kk_std_num_ddouble__ddouble _x_x1345 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_0_0 = _x_x1345.hi;
          _x_x1344 = _x_0_0; /*float64*/
        }
        _match_x637 = kk_std_num_float64_cmp(_x_x1343, _x_x1344, _ctx); /*order*/
        if (kk_std_core_types__is_Eq(_match_x637, _ctx)) {
          double _x_x1346;
          {
            double _x_1_0 = x.lo;
            _x_x1346 = _x_1_0; /*float64*/
          }
          double _x_x1347;
          kk_std_num_ddouble__ddouble _x_x1348 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
          {
            double _x_2_0 = _x_x1348.lo;
            _x_x1347 = _x_2_0; /*float64*/
          }
          _x_x1342 = kk_std_num_float64_cmp(_x_x1346, _x_x1347, _ctx); /*order*/
        }
        else {
          _x_x1342 = _match_x637; /*order*/
        }
        _match_x635 = kk_std_core_order__lp__eq__eq__rp_(_x_x1342, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
        if (_match_x635) {
          return kk_std_num_ddouble_dd_e;
        }
        {
          kk_integer_t m;
          double _x_x1349;
          double _x_x1350;
          double _x_x1351;
          double _x_x1352;
          {
            double _x_2_1 = x.hi;
            _x_x1352 = _x_2_1; /*float64*/
          }
          double _x_x1353;
          kk_std_num_ddouble__ddouble _x_x1354 = kk_std_num_ddouble_dd_ln2; /*std/num/ddouble/ddouble*/
          {
            double _x_3 = _x_x1354.hi;
            _x_x1353 = _x_3; /*float64*/
          }
          _x_x1351 = (_x_x1352 / _x_x1353); /*float64*/
          _x_x1350 = (_x_x1351 + (0x1p-1)); /*float64*/
          _x_x1349 = floor(_x_x1350); /*float64*/
          m = kk_integer_from_double(_x_x1349,kk_context()); /*int*/
          kk_std_num_ddouble__ddouble y_0_10248;
          kk_std_num_ddouble__ddouble _x_x1355;
          kk_integer_t _x_x1356 = kk_integer_dup(m, _ctx); /*int*/
          _x_x1355 = kk_std_num_ddouble_ddouble_int_exp(_x_x1356, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
          y_0_10248 = kk_std_num_ddouble__lp__star__rp_(_x_x1355, kk_std_num_ddouble_dd_ln2, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble x_2_10245;
          kk_std_num_ddouble__ddouble _x_x1357;
          double _x_x1358;
          double _x_x1359;
          {
            double _x_4 = y_0_10248.hi;
            _x_x1359 = _x_4; /*float64*/
          }
          _x_x1358 = (-_x_x1359); /*float64*/
          double _x_x1360;
          double _x_x1361;
          {
            double _x_0_1 = y_0_10248.lo;
            _x_x1361 = _x_0_1; /*float64*/
          }
          _x_x1360 = (-_x_x1361); /*float64*/
          _x_x1357 = kk_std_num_ddouble__new_Ddouble(_x_x1358, _x_x1360, _ctx); /*std/num/ddouble/ddouble*/
          x_2_10245 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x1357, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble r;
          double _x_x1362;
          double _x_x1363;
          {
            double _x_4_0 = x_2_10245.hi;
            _x_x1363 = _x_4_0; /*float64*/
          }
          _x_x1362 = (_x_x1363 * inv_k); /*float64*/
          double _x_x1364;
          double _x_x1365;
          {
            double _x_5 = x_2_10245.lo;
            _x_x1365 = _x_5; /*float64*/
          }
          _x_x1364 = (_x_x1365 * inv_k); /*float64*/
          r = kk_std_num_ddouble__new_Ddouble(_x_x1362, _x_x1364, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble p_0 = kk_std_num_ddouble_sqr(r, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble t;
          kk_std_num_ddouble__ddouble _x_x1366;
          double _x_x1367;
          double _x_x1368;
          {
            double _x_6 = p_0.hi;
            _x_x1368 = _x_6; /*float64*/
          }
          _x_x1367 = (_x_x1368 * (0x1p-1)); /*float64*/
          double _x_x1369;
          double _x_x1370;
          {
            double _x_0_2 = p_0.lo;
            _x_x1370 = _x_0_2; /*float64*/
          }
          _x_x1369 = (_x_x1370 * (0x1p-1)); /*float64*/
          _x_x1366 = kk_std_num_ddouble__new_Ddouble(_x_x1367, _x_x1369, _ctx); /*std/num/ddouble/ddouble*/
          t = kk_std_num_ddouble__lp__plus__rp_(r, _x_x1366, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble init_10861;
          double _x_x1371;
          double _x_x1372;
          kk_std_num_ddouble__ddouble _x_x1373 = kk_std_num_ddouble_dd_epsilon; /*std/num/ddouble/ddouble*/
          {
            double _x_6_0 = _x_x1373.hi;
            _x_x1372 = _x_6_0; /*float64*/
          }
          _x_x1371 = (inv_k * _x_x1372); /*float64*/
          kk_std_core_types__list _x_x1374 = kk_std_core_types__list_dup(kk_std_num_ddouble_exp_factors, _ctx); /*list<std/num/ddouble/ddouble>*/
          init_10861 = kk_std_num_ddouble_exp_approx(p_0, t, r, _x_x1371, _x_x1374, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/ddouble/ddouble*/
          kk_ref_t loc = kk_ref_alloc((kk_std_num_ddouble__ddouble_box(init_10861, _ctx)),kk_context()); /*local-var<5910,std/num/ddouble/ddouble>*/;
          kk_unit_t __ = kk_Unit;
          kk_function_t _x_x1375;
          kk_ref_dup(loc, _ctx);
          _x_x1375 = kk_std_num_ddouble_new_exp_fun1376(loc, _ctx); /*() -> (local<5910>) ()*/
          kk_std_core_repeat(kk_integer_from_small(9), _x_x1375, _ctx);
          kk_std_num_ddouble__ddouble _b_x331_333;
          kk_std_num_ddouble__ddouble _x_x1388;
          kk_box_t _x_x1389;
          kk_ref_t _x_x1390 = kk_ref_dup(loc, _ctx); /*local-var<5910,std/num/ddouble/ddouble>*/
          _x_x1389 = kk_ref_get(_x_x1390,kk_context()); /*10000*/
          _x_x1388 = kk_std_num_ddouble__ddouble_unbox(_x_x1389, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
          _b_x331_333 = kk_std_num_ddouble__lp__plus__rp_(_x_x1388, kk_std_num_ddouble_one, _ctx); /*std/num/ddouble/ddouble*/
          kk_unit_t ___0 = kk_Unit;
          kk_ref_set_borrow(loc,(kk_std_num_ddouble__ddouble_box(_b_x331_333, _ctx)),kk_context());
          kk_std_num_ddouble__ddouble x_6_10258;
          kk_box_t _x_x1391;
          kk_ref_t _x_x1392 = kk_ref_dup(loc, _ctx); /*local-var<5910,std/num/ddouble/ddouble>*/
          _x_x1391 = kk_ref_get(_x_x1392,kk_context()); /*10000*/
          x_6_10258 = kk_std_num_ddouble__ddouble_unbox(_x_x1391, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble res;
          double _x_x1393;
          double _x_x1394;
          {
            double _x_9 = x_6_10258.hi;
            _x_x1394 = _x_9; /*float64*/
          }
          kk_integer_t _x_x1395 = kk_integer_dup(m, _ctx); /*int*/
          _x_x1393 = kk_std_num_float64_ldexp(_x_x1394, _x_x1395, _ctx); /*float64*/
          double _x_x1396;
          double _x_x1397;
          {
            double _x_10 = x_6_10258.lo;
            _x_x1397 = _x_10; /*float64*/
          }
          _x_x1396 = kk_std_num_float64_ldexp(_x_x1397, m, _ctx); /*float64*/
          res = kk_std_num_ddouble__new_Ddouble(_x_x1393, _x_x1396, _ctx); /*std/num/ddouble/ddouble*/
          kk_box_t _x_x1398 = kk_std_core_hnd_prompt_local_var(loc, kk_std_num_ddouble__ddouble_box(res, _ctx), _ctx); /*10001*/
          return kk_std_num_ddouble__ddouble_unbox(_x_x1398, KK_OWNED, _ctx);
        }
      }
    }
  }
}
 
// The natural logarithm (in base _e_) of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ln(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x623;
  kk_std_core_types__order _x_x1399;
  kk_std_core_types__order _match_x631;
  double _x_x1400;
  {
    double _x = x.hi;
    _x_x1400 = _x; /*float64*/
  }
  double _x_x1401;
  kk_std_num_ddouble__ddouble _x_x1402 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
  {
    double _x_0 = _x_x1402.hi;
    _x_x1401 = _x_0; /*float64*/
  }
  _match_x631 = kk_std_num_float64_cmp(_x_x1400, _x_x1401, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x631, _ctx)) {
    double _x_x1403;
    {
      double _x_1 = x.lo;
      _x_x1403 = _x_1; /*float64*/
    }
    double _x_x1404;
    kk_std_num_ddouble__ddouble _x_x1405 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
    {
      double _x_2 = _x_x1405.lo;
      _x_x1404 = _x_2; /*float64*/
    }
    _x_x1399 = kk_std_num_float64_cmp(_x_x1403, _x_x1404, _ctx); /*order*/
  }
  else {
    _x_x1399 = _match_x631; /*order*/
  }
  _match_x623 = kk_std_core_order__lp__excl__eq__rp_(_x_x1399, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
  if (_match_x623) {
    bool _match_x629;
    kk_std_core_types__order _x_x1406;
    kk_std_core_types__order _match_x630;
    double _x_x1407;
    {
      double _x_3 = x.hi;
      _x_x1407 = _x_3; /*float64*/
    }
    double _x_x1408;
    kk_std_num_ddouble__ddouble _x_x1409 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
    {
      double _x_0_0 = _x_x1409.hi;
      _x_x1408 = _x_0_0; /*float64*/
    }
    _match_x630 = kk_std_num_float64_cmp(_x_x1407, _x_x1408, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x630, _ctx)) {
      double _x_x1410;
      {
        double _x_1_0 = x.lo;
        _x_x1410 = _x_1_0; /*float64*/
      }
      double _x_x1411;
      kk_std_num_ddouble__ddouble _x_x1412 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
      {
        double _x_2_0 = _x_x1412.lo;
        _x_x1411 = _x_2_0; /*float64*/
      }
      _x_x1406 = kk_std_num_float64_cmp(_x_x1410, _x_x1411, _ctx); /*order*/
    }
    else {
      _x_x1406 = _match_x630; /*order*/
    }
    _match_x629 = kk_std_core_order__lp__eq__eq__rp_(_x_x1406, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
    if (_match_x629) {
      return kk_std_num_ddouble_dd_neginf;
    }
    {
      return kk_std_num_ddouble_dd_nan;
    }
  }
  {
    bool _match_x624;
    kk_std_core_types__order _x_x1413;
    kk_std_core_types__order _match_x628;
    double _x_x1414;
    {
      double _x_4 = x.hi;
      _x_x1414 = _x_4; /*float64*/
    }
    double _x_x1415;
    kk_std_num_ddouble__ddouble _x_x1416 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_0_1 = _x_x1416.hi;
      _x_x1415 = _x_0_1; /*float64*/
    }
    _match_x628 = kk_std_num_float64_cmp(_x_x1414, _x_x1415, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x628, _ctx)) {
      double _x_x1417;
      {
        double _x_1_1 = x.lo;
        _x_x1417 = _x_1_1; /*float64*/
      }
      double _x_x1418;
      kk_std_num_ddouble__ddouble _x_x1419 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_2_1 = _x_x1419.lo;
        _x_x1418 = _x_2_1; /*float64*/
      }
      _x_x1413 = kk_std_num_float64_cmp(_x_x1417, _x_x1418, _ctx); /*order*/
    }
    else {
      _x_x1413 = _match_x628; /*order*/
    }
    _match_x624 = kk_std_core_order__lp__eq__eq__rp_(_x_x1413, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
    if (_match_x624) {
      return kk_std_num_ddouble_zero;
    }
    {
      bool _match_x625;
      kk_std_core_types__order _x_x1420;
      kk_std_core_types__order _match_x627;
      double _x_x1421;
      {
        double _x_5 = x.hi;
        _x_x1421 = _x_5; /*float64*/
      }
      double _x_x1422;
      kk_std_num_ddouble__ddouble _x_x1423 = kk_std_num_ddouble_dd_e; /*std/num/ddouble/ddouble*/
      {
        double _x_0_2 = _x_x1423.hi;
        _x_x1422 = _x_0_2; /*float64*/
      }
      _match_x627 = kk_std_num_float64_cmp(_x_x1421, _x_x1422, _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x627, _ctx)) {
        double _x_x1424;
        {
          double _x_1_2 = x.lo;
          _x_x1424 = _x_1_2; /*float64*/
        }
        double _x_x1425;
        kk_std_num_ddouble__ddouble _x_x1426 = kk_std_num_ddouble_dd_e; /*std/num/ddouble/ddouble*/
        {
          double _x_2_2 = _x_x1426.lo;
          _x_x1425 = _x_2_2; /*float64*/
        }
        _x_x1420 = kk_std_num_float64_cmp(_x_x1424, _x_x1425, _ctx); /*order*/
      }
      else {
        _x_x1420 = _match_x627; /*order*/
      }
      _match_x625 = kk_std_core_order__lp__eq__eq__rp_(_x_x1420, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
      if (_match_x625) {
        return kk_std_num_ddouble_one;
      }
      {
        bool _match_x626;
        double _x_x1427;
        {
          double _x_6 = x.hi;
          _x_x1427 = _x_6; /*float64*/
        }
        _match_x626 = (isinf(_x_x1427) && !signbit(_x_x1427)); /*bool*/
        if (_match_x626) {
          return x;
        }
        {
          double d_10272;
          double _x_x1428;
          {
            double _x_0_3 = x.hi;
            _x_x1428 = _x_0_3; /*float64*/
          }
          d_10272 = log(_x_x1428); /*float64*/
          kk_std_num_ddouble__ddouble a0 = kk_std_num_ddouble__new_Ddouble(d_10272, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble x_5_10274;
          kk_std_num_ddouble__ddouble _x_x1429;
          kk_std_num_ddouble__ddouble _x_x1430;
          double _x_x1431;
          double _x_x1432;
          {
            double _x_7 = a0.hi;
            _x_x1432 = _x_7; /*float64*/
          }
          _x_x1431 = (-_x_x1432); /*float64*/
          double _x_x1433;
          double _x_x1434;
          {
            double _x_0_4 = a0.lo;
            _x_x1434 = _x_0_4; /*float64*/
          }
          _x_x1433 = (-_x_x1434); /*float64*/
          _x_x1430 = kk_std_num_ddouble__new_Ddouble(_x_x1431, _x_x1433, _ctx); /*std/num/ddouble/ddouble*/
          _x_x1429 = kk_std_num_ddouble_exp(_x_x1430, _ctx); /*std/num/ddouble/ddouble*/
          x_5_10274 = kk_std_num_ddouble__lp__star__rp_(x, _x_x1429, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x1435;
          kk_std_num_ddouble__ddouble _x_x1436;
          double _x_x1437;
          double _x_x1438;
          kk_std_num_ddouble__ddouble _x_x1439 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
          {
            double _x_8 = _x_x1439.hi;
            _x_x1438 = _x_8; /*float64*/
          }
          _x_x1437 = (-_x_x1438); /*float64*/
          double _x_x1440;
          double _x_x1441;
          kk_std_num_ddouble__ddouble _x_x1442 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
          {
            double _x_0_5 = _x_x1442.lo;
            _x_x1441 = _x_0_5; /*float64*/
          }
          _x_x1440 = (-_x_x1441); /*float64*/
          _x_x1436 = kk_std_num_ddouble__new_Ddouble(_x_x1437, _x_x1440, _ctx); /*std/num/ddouble/ddouble*/
          _x_x1435 = kk_std_num_ddouble__lp__plus__rp_(x_5_10274, _x_x1436, _ctx); /*std/num/ddouble/ddouble*/
          return kk_std_num_ddouble__lp__plus__rp_(a0, _x_x1435, _ctx);
        }
      }
    }
  }
}
 
// Show a `:ddouble` `x` with a given precision `prec` (=`-31`).
// The precision specifies the  number of digits after the dot (in either scientific of fixed-point notation).
// If the precision is negative, _at most_ `prec` digits are displayed, while for a positive
// precision, exactly `prec` digits behind the dot are displayed.
// This uses `show-fixed` when the exponent of `x` in scientific notation is larger than -5
// and smaller than the precision (or 15 in case of a negative precision), otherwise it uses `show-exp`.

kk_string_t kk_std_num_ddouble_show(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : ? int) -> string */ 
  bool b_10280;
  bool _match_x622;
  double _x_x1449;
  {
    double _x = x.hi;
    _x_x1449 = _x; /*float64*/
  }
  _match_x622 = isfinite(_x_x1449); /*bool*/
  if (_match_x622) {
    double _x_x1450;
    {
      double _x_0 = x.lo;
      _x_x1450 = _x_0; /*float64*/
    }
    b_10280 = isfinite(_x_x1450); /*bool*/
  }
  else {
    b_10280 = false; /*bool*/
  }
  if (b_10280) {
    kk_std_num_decimal__decimal _x_x1451 = kk_std_num_ddouble_decimal(x, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
    kk_std_core_types__optional _x_x1452;
    kk_box_t _x_x1453;
    kk_integer_t _x_x1454;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x344 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_6425 = kk_integer_unbox(_box_x344, _ctx);
      kk_integer_dup(_uniq_prec_6425, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1454 = _uniq_prec_6425; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1454 = kk_integer_from_small(-31); /*int*/
    }
    _x_x1453 = kk_integer_box(_x_x1454, _ctx); /*10003*/
    _x_x1452 = kk_std_core_types__new_Optional(_x_x1453, _ctx); /*? 10003*/
    return kk_std_num_decimal_show(_x_x1451, _x_x1452, _ctx);
  }
  {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x_x1455;
    {
      double _x_1 = x.hi;
      _x_x1455 = _x_1; /*float64*/
    }
    return kk_std_num_float64_show(_x_x1455, kk_std_core_types__new_None(_ctx), _ctx);
  }
}
 
// /* Show a `:ddouble` `x` precisely as the sum of two `:float64`s
// in [hexadecimal notation](https://books.google.com/books?id=FgMsCwAAQBAJ&pg=PA41).
// Use this if you need to guarantee that you can parse back `:ddouble`s exactly,
// i.e. `x == x.show-hex.ddouble`.
// ```
// > 0.1.ddouble.show-hex
// "0x1.999999999999Ap-4 + 0x0.0p+0"
// > "0.1".ddouble.show-hex
// "0x1.999999999999Ap-4 + -0x1.999999999999Ap-58"
// > dd-pi.show-hex
// "0x1.921FB54442D18p+1 + 0x1.1A62633145C07p-53"
// > dd-max.show-hex
// "0x1.FFFFFFFFFFFFFp+1023 + 0x1.FFFFFFFFFFFFFp+969"
// ```
// .
// */

kk_string_t kk_std_num_ddouble_show_hex(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (x : ddouble, width : ? int, use-capitals : ? bool, pre : ? string) -> string */ 
  bool b_10282;
  bool _match_x621;
  double _x_x1456;
  {
    double _x = x.hi;
    _x_x1456 = _x; /*float64*/
  }
  _match_x621 = isfinite(_x_x1456); /*bool*/
  if (_match_x621) {
    double _x_x1457;
    {
      double _x_0 = x.lo;
      _x_x1457 = _x_0; /*float64*/
    }
    b_10282 = isfinite(_x_x1457); /*bool*/
  }
  else {
    b_10282 = false; /*bool*/
  }
  if (b_10282) {
    kk_integer_t _b_x348_359;
    if (kk_std_core_types__is_Optional(width, _ctx)) {
      kk_box_t _box_x347 = width._cons._Optional.value;
      kk_integer_t _uniq_width_6640 = kk_integer_unbox(_box_x347, _ctx);
      kk_integer_dup(_uniq_width_6640, _ctx);
      _b_x348_359 = _uniq_width_6640; /*int*/
    }
    else {
      _b_x348_359 = kk_integer_from_small(1); /*int*/
    }
    bool _b_x350_360;
    if (kk_std_core_types__is_Optional(use_capitals, _ctx)) {
      kk_box_t _box_x349 = use_capitals._cons._Optional.value;
      bool _uniq_use_capitals_6644 = kk_bool_unbox(_box_x349);
      _b_x350_360 = _uniq_use_capitals_6644; /*bool*/
    }
    else {
      _b_x350_360 = true; /*bool*/
    }
    kk_string_t _b_x352_361;
    if (kk_std_core_types__is_Optional(pre, _ctx)) {
      kk_box_t _box_x351 = pre._cons._Optional.value;
      kk_string_t _uniq_pre_6648 = kk_string_unbox(_box_x351);
      kk_string_dup(_uniq_pre_6648, _ctx);
      _b_x352_361 = _uniq_pre_6648; /*string*/
    }
    else {
      kk_define_string_literal(, _s_x1458, 2, "0x", _ctx)
      _b_x352_361 = kk_string_dup(_s_x1458, _ctx); /*string*/
    }
    kk_string_t _x_x1459;
    double _x_x1460;
    {
      double _x_0_0 = x.hi;
      _x_x1460 = _x_0_0; /*float64*/
    }
    kk_std_core_types__optional _x_x1461 = kk_std_core_types__new_Optional(kk_integer_box(_b_x348_359, _ctx), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1462 = kk_std_core_types__new_Optional(kk_bool_box(_b_x350_360), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1463 = kk_std_core_types__new_Optional(kk_string_box(_b_x352_361), _ctx); /*? 10003*/
    _x_x1459 = kk_std_num_float64_show_hex(_x_x1460, _x_x1461, _x_x1462, _x_x1463, _ctx); /*string*/
    kk_string_t _x_x1464;
    kk_integer_t _b_x354_362;
    if (kk_std_core_types__is_Optional(width, _ctx)) {
      kk_box_t _box_x353 = width._cons._Optional.value;
      kk_integer_t _uniq_width_6640_0 = kk_integer_unbox(_box_x353, _ctx);
      kk_integer_dup(_uniq_width_6640_0, _ctx);
      kk_std_core_types__optional_drop(width, _ctx);
      _b_x354_362 = _uniq_width_6640_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(width, _ctx);
      _b_x354_362 = kk_integer_from_small(1); /*int*/
    }
    bool _b_x356_363;
    if (kk_std_core_types__is_Optional(use_capitals, _ctx)) {
      kk_box_t _box_x355 = use_capitals._cons._Optional.value;
      bool _uniq_use_capitals_6644_0 = kk_bool_unbox(_box_x355);
      kk_std_core_types__optional_drop(use_capitals, _ctx);
      _b_x356_363 = _uniq_use_capitals_6644_0; /*bool*/
    }
    else {
      kk_std_core_types__optional_drop(use_capitals, _ctx);
      _b_x356_363 = true; /*bool*/
    }
    kk_string_t _b_x358_364;
    if (kk_std_core_types__is_Optional(pre, _ctx)) {
      kk_box_t _box_x357 = pre._cons._Optional.value;
      kk_string_t _uniq_pre_6648_0 = kk_string_unbox(_box_x357);
      kk_string_dup(_uniq_pre_6648_0, _ctx);
      kk_std_core_types__optional_drop(pre, _ctx);
      _b_x358_364 = _uniq_pre_6648_0; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(pre, _ctx);
      kk_define_string_literal(, _s_x1465, 2, "0x", _ctx)
      _b_x358_364 = kk_string_dup(_s_x1465, _ctx); /*string*/
    }
    kk_string_t _x_x1466;
    kk_define_string_literal(, _s_x1467, 3, " + ", _ctx)
    _x_x1466 = kk_string_dup(_s_x1467, _ctx); /*string*/
    kk_string_t _x_x1468;
    double _x_x1469;
    {
      double _x_1 = x.lo;
      _x_x1469 = _x_1; /*float64*/
    }
    kk_std_core_types__optional _x_x1470 = kk_std_core_types__new_Optional(kk_integer_box(_b_x354_362, _ctx), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1471 = kk_std_core_types__new_Optional(kk_bool_box(_b_x356_363), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1472 = kk_std_core_types__new_Optional(kk_string_box(_b_x358_364), _ctx); /*? 10003*/
    _x_x1468 = kk_std_num_float64_show_hex(_x_x1469, _x_x1470, _x_x1471, _x_x1472, _ctx); /*string*/
    _x_x1464 = kk_std_core_types__lp__plus__plus__rp_(_x_x1466, _x_x1468, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x1459, _x_x1464, _ctx);
  }
  {
    kk_std_core_types__optional_drop(width, _ctx);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    kk_std_core_types__optional_drop(pre, _ctx);
    double _x_x1473;
    {
      double _x_2 = x.hi;
      _x_x1473 = _x_2; /*float64*/
    }
    return kk_std_num_float64_show(_x_x1473, kk_std_core_types__new_None(_ctx), _ctx);
  }
}
 
// /* Show a ddouble `x` with a given precision `prec` (=`-31`) in scientific notation.
// The precision specifies the  number of digits after the dot, i.e.
// the number of significant digits is `prec+1`.
// If the precision is negative, _at most_ `prec` digits are displayed, and if
// it is positive exactly `prec` digits are used.
// ```
// > 1.1.ddouble.show-exp
// "1.1000000000000000888178419700125"
// > 1.1.ddouble.show-exp(-100)
// "1.100000000000000088817841970012523233890533447265625"
// > 1.1.ddouble.show-exp(5)
// "1.10000"
// > 1.1.ddouble.show-exp(-5)
// "1.1"
// ```
// .
// */

kk_string_t kk_std_num_ddouble_show_exp(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : ? int) -> string */ 
  bool b_10286;
  bool _match_x620;
  double _x_x1474;
  {
    double _x = x.hi;
    _x_x1474 = _x; /*float64*/
  }
  _match_x620 = isfinite(_x_x1474); /*bool*/
  if (_match_x620) {
    double _x_x1475;
    {
      double _x_0 = x.lo;
      _x_x1475 = _x_0; /*float64*/
    }
    b_10286 = isfinite(_x_x1475); /*bool*/
  }
  else {
    b_10286 = false; /*bool*/
  }
  if (b_10286) {
    kk_std_num_decimal__decimal _x_x1476 = kk_std_num_ddouble_decimal(x, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
    kk_std_core_types__optional _x_x1477;
    kk_box_t _x_x1478;
    kk_integer_t _x_x1479;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x365 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_6836 = kk_integer_unbox(_box_x365, _ctx);
      kk_integer_dup(_uniq_prec_6836, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1479 = _uniq_prec_6836; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1479 = kk_integer_from_small(-31); /*int*/
    }
    _x_x1478 = kk_integer_box(_x_x1479, _ctx); /*10003*/
    _x_x1477 = kk_std_core_types__new_Optional(_x_x1478, _ctx); /*? 10003*/
    return kk_std_num_decimal_show_exp(_x_x1476, _x_x1477, _ctx);
  }
  {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x_x1480;
    {
      double _x_1 = x.hi;
      _x_x1480 = _x_1; /*float64*/
    }
    return kk_std_num_float64_show(_x_x1480, kk_std_core_types__new_None(_ctx), _ctx);
  }
}
 
// /* Show a ddouble `x` with a given precision `prec` (=`-31`) in fixed-point notation.
// The precision specifies the  number of digits after the dot.
// If the precision is negative, _at most_  `prec` digits after the dot are displayed,
// while for a positive precision, exactly `prec` digits are used.
// ```
// > 0.1.ddouble.show-fixed
// "0.1000000000000000055511151231258"
// > 0.1.ddouble.show-fixed(-100)
// "0.1000000000000000055511151231257827021181583404541015625"
// > 0.1.ddouble.show-fixed(5)
// "0.10000"
// > 0.1.ddouble.show-fixed(-5)
// "0.1"
// ```
// .
// */

kk_string_t kk_std_num_ddouble_show_fixed(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : ? int) -> string */ 
  bool b_10288;
  bool _match_x619;
  double _x_x1481;
  {
    double _x = x.hi;
    _x_x1481 = _x; /*float64*/
  }
  _match_x619 = isfinite(_x_x1481); /*bool*/
  if (_match_x619) {
    double _x_x1482;
    {
      double _x_0 = x.lo;
      _x_x1482 = _x_0; /*float64*/
    }
    b_10288 = isfinite(_x_x1482); /*bool*/
  }
  else {
    b_10288 = false; /*bool*/
  }
  if (b_10288) {
    kk_std_num_decimal__decimal _x_x1483 = kk_std_num_ddouble_decimal(x, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
    kk_std_core_types__optional _x_x1484;
    kk_box_t _x_x1485;
    kk_integer_t _x_x1486;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x368 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_6956 = kk_integer_unbox(_box_x368, _ctx);
      kk_integer_dup(_uniq_prec_6956, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1486 = _uniq_prec_6956; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1486 = kk_integer_from_small(-31); /*int*/
    }
    _x_x1485 = kk_integer_box(_x_x1486, _ctx); /*10003*/
    _x_x1484 = kk_std_core_types__new_Optional(_x_x1485, _ctx); /*? 10003*/
    return kk_std_num_decimal_show_fixed(_x_x1483, _x_x1484, _ctx);
  }
  {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x_x1487;
    {
      double _x_1 = x.hi;
      _x_x1487 = _x_1; /*float64*/
    }
    return kk_std_num_float64_show(_x_x1487, kk_std_core_types__new_None(_ctx), _ctx);
  }
}
 
// Show a `:ddouble` as the sum of  `:float64`s with an optional precision.
// Note: use `show-hex` for reliable round-trip parsing.

kk_string_t kk_std_num_ddouble_show_sum(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : ? int) -> string */ 
  bool b_10290;
  bool _match_x618;
  double _x_x1488;
  {
    double _x = x.hi;
    _x_x1488 = _x; /*float64*/
  }
  _match_x618 = isfinite(_x_x1488); /*bool*/
  if (_match_x618) {
    double _x_x1489;
    {
      double _x_0 = x.lo;
      _x_x1489 = _x_0; /*float64*/
    }
    b_10290 = isfinite(_x_x1489); /*bool*/
  }
  else {
    b_10290 = false; /*bool*/
  }
  if (b_10290) {
    kk_integer_t _b_x372_375;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x371 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_7076 = kk_integer_unbox(_box_x371, _ctx);
      kk_integer_dup(_uniq_prec_7076, _ctx);
      _b_x372_375 = _uniq_prec_7076; /*int*/
    }
    else {
      _b_x372_375 = kk_integer_from_small(-17); /*int*/
    }
    kk_string_t _x_x1490;
    double _x_x1491;
    {
      double _x_0_0 = x.hi;
      _x_x1491 = _x_0_0; /*float64*/
    }
    kk_std_core_types__optional _x_x1492 = kk_std_core_types__new_Optional(kk_integer_box(_b_x372_375, _ctx), _ctx); /*? 10003*/
    _x_x1490 = kk_std_num_float64_show(_x_x1491, _x_x1492, _ctx); /*string*/
    kk_string_t _x_x1493;
    kk_integer_t _b_x374_376;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x373 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_7076_0 = kk_integer_unbox(_box_x373, _ctx);
      kk_integer_dup(_uniq_prec_7076_0, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _b_x374_376 = _uniq_prec_7076_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _b_x374_376 = kk_integer_from_small(-17); /*int*/
    }
    kk_string_t _x_x1494;
    kk_define_string_literal(, _s_x1495, 3, " + ", _ctx)
    _x_x1494 = kk_string_dup(_s_x1495, _ctx); /*string*/
    kk_string_t _x_x1496;
    double _x_x1497;
    {
      double _x_1 = x.lo;
      _x_x1497 = _x_1; /*float64*/
    }
    kk_std_core_types__optional _x_x1498 = kk_std_core_types__new_Optional(kk_integer_box(_b_x374_376, _ctx), _ctx); /*? 10003*/
    _x_x1496 = kk_std_num_float64_show(_x_x1497, _x_x1498, _ctx); /*string*/
    _x_x1493 = kk_std_core_types__lp__plus__plus__rp_(_x_x1494, _x_x1496, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x1490, _x_x1493, _ctx);
  }
  {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x_x1499;
    {
      double _x_2 = x.hi;
      _x_x1499 = _x_2; /*float64*/
    }
    return kk_std_num_float64_show(_x_x1499, kk_std_core_types__new_None(_ctx), _ctx);
  }
}
 
// The `n`-th root of a `:ddouble` number `x`.
// `n` must be positive, and if `n` is even, then
// `x` must not be negative.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_nroot(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx) { /* (x : ddouble, n : int) -> ddouble */ 
  bool _match_x610 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  if (_match_x610) {
    kk_integer_drop(n, _ctx);
    return kk_std_num_ddouble_sqrt(x, _ctx);
  }
  {
    bool _match_x611 = kk_integer_eq_borrow(n,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x611) {
      kk_integer_drop(n, _ctx);
      return x;
    }
    {
      bool _match_x612 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x612) {
        kk_integer_drop(n, _ctx);
        return kk_std_num_ddouble_dd_nan;
      }
      {
        bool b_10014;
        kk_integer_t _x_x1500 = kk_integer_dup(n, _ctx); /*int*/
        b_10014 = kk_integer_is_odd(_x_x1500,kk_context()); /*bool*/
        if (b_10014) {
          bool _match_x616;
          double _x_x1501;
          {
            double _x_3 = x.hi;
            _x_x1501 = _x_3; /*float64*/
          }
          _match_x616 = (_x_x1501 == (0x0p+0)); /*bool*/
          if (_match_x616) {
            kk_integer_drop(n, _ctx);
            return kk_std_num_ddouble_zero;
          }
          {
            kk_std_num_ddouble__ddouble r_0 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
            double d_4_10311;
            double _x_x1502;
            double _x_x1503;
            double _x_x1504;
            double _x_x1505;
            {
              double _x_4 = r_0.hi;
              _x_x1505 = _x_4; /*float64*/
            }
            _x_x1504 = log(_x_x1505); /*float64*/
            _x_x1503 = (-_x_x1504); /*float64*/
            double _x_x1506;
            kk_integer_t _x_x1507 = kk_integer_dup(n, _ctx); /*int*/
            _x_x1506 = kk_integer_as_double(_x_x1507,kk_context()); /*float64*/
            _x_x1502 = (_x_x1503 / _x_x1506); /*float64*/
            d_4_10311 = exp(_x_x1502); /*float64*/
            kk_std_num_ddouble__ddouble a0_0 = kk_std_num_ddouble__new_Ddouble(d_4_10311, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_std_num_ddouble__ddouble y_0_10314;
            kk_std_num_ddouble__ddouble _x_x1508;
            kk_integer_t _x_x1509 = kk_integer_dup(n, _ctx); /*int*/
            _x_x1508 = kk_std_num_ddouble_powi(a0_0, _x_x1509, _ctx); /*std/num/ddouble/ddouble*/
            y_0_10314 = kk_std_num_ddouble__lp__star__rp_(r_0, _x_x1508, _ctx); /*std/num/ddouble/ddouble*/
            kk_std_num_ddouble__ddouble a1_0;
            kk_std_num_ddouble__ddouble _x_x1510;
            kk_std_num_ddouble__ddouble _x_x1511;
            kk_std_num_ddouble__ddouble _x_x1512;
            kk_std_num_ddouble__ddouble _x_x1513;
            double _x_x1514;
            double _x_x1515;
            {
              double _x = y_0_10314.hi;
              _x_x1515 = _x; /*float64*/
            }
            _x_x1514 = (-_x_x1515); /*float64*/
            double _x_x1516;
            double _x_x1517;
            {
              double _x_0 = y_0_10314.lo;
              _x_x1517 = _x_0; /*float64*/
            }
            _x_x1516 = (-_x_x1517); /*float64*/
            _x_x1513 = kk_std_num_ddouble__new_Ddouble(_x_x1514, _x_x1516, _ctx); /*std/num/ddouble/ddouble*/
            _x_x1512 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x1513, _ctx); /*std/num/ddouble/ddouble*/
            _x_x1511 = kk_std_num_ddouble__lp__star__rp_(a0_0, _x_x1512, _ctx); /*std/num/ddouble/ddouble*/
            kk_std_num_ddouble__ddouble _x_x1518 = kk_std_num_ddouble_ddouble_int_exp(n, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
            _x_x1510 = kk_std_num_ddouble__lp__fs__rp_(_x_x1511, _x_x1518, _ctx); /*std/num/ddouble/ddouble*/
            a1_0 = kk_std_num_ddouble__lp__plus__rp_(a0_0, _x_x1510, _ctx); /*std/num/ddouble/ddouble*/
            kk_std_num_ddouble__ddouble _x_x1519;
            bool _match_x617;
            double _x_x1520;
            {
              double _x_5 = x.hi;
              _x_x1520 = _x_5; /*float64*/
            }
            _match_x617 = (_x_x1520 < (0x0p+0)); /*bool*/
            if (_match_x617) {
              double _x_x1521;
              double _x_x1522;
              kk_std_num_ddouble__ddouble _x_x1523 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
              {
                double _x_1 = _x_x1523.hi;
                _x_x1522 = _x_1; /*float64*/
              }
              _x_x1521 = (-_x_x1522); /*float64*/
              double _x_x1524;
              double _x_x1525;
              kk_std_num_ddouble__ddouble _x_x1526 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
              {
                double _x_0_0 = _x_x1526.lo;
                _x_x1525 = _x_0_0; /*float64*/
              }
              _x_x1524 = (-_x_x1525); /*float64*/
              _x_x1519 = kk_std_num_ddouble__new_Ddouble(_x_x1521, _x_x1524, _ctx); /*std/num/ddouble/ddouble*/
            }
            else {
              _x_x1519 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
            }
            return kk_std_num_ddouble__lp__fs__rp_(_x_x1519, a1_0, _ctx);
          }
        }
        {
          bool _match_x613;
          double _x_x1527;
          {
            double _x_2 = x.hi;
            _x_x1527 = _x_2; /*float64*/
          }
          _match_x613 = (_x_x1527 < (0x0p+0)); /*bool*/
          if (_match_x613) {
            kk_integer_drop(n, _ctx);
            return kk_std_num_ddouble_dd_nan;
          }
          {
            bool _match_x614;
            double _x_x1528;
            {
              double _x_0_1 = x.hi;
              _x_x1528 = _x_0_1; /*float64*/
            }
            _match_x614 = (_x_x1528 == (0x0p+0)); /*bool*/
            if (_match_x614) {
              kk_integer_drop(n, _ctx);
              return kk_std_num_ddouble_zero;
            }
            {
              kk_std_num_ddouble__ddouble r = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
              double d_1_10301;
              double _x_x1529;
              double _x_x1530;
              double _x_x1531;
              double _x_x1532;
              {
                double _x_1_0 = r.hi;
                _x_x1532 = _x_1_0; /*float64*/
              }
              _x_x1531 = log(_x_x1532); /*float64*/
              _x_x1530 = (-_x_x1531); /*float64*/
              double _x_x1533;
              kk_integer_t _x_x1534 = kk_integer_dup(n, _ctx); /*int*/
              _x_x1533 = kk_integer_as_double(_x_x1534,kk_context()); /*float64*/
              _x_x1529 = (_x_x1530 / _x_x1533); /*float64*/
              d_1_10301 = exp(_x_x1529); /*float64*/
              kk_std_num_ddouble__ddouble a0 = kk_std_num_ddouble__new_Ddouble(d_1_10301, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_std_num_ddouble__ddouble y_10304;
              kk_std_num_ddouble__ddouble _x_x1535;
              kk_integer_t _x_x1536 = kk_integer_dup(n, _ctx); /*int*/
              _x_x1535 = kk_std_num_ddouble_powi(a0, _x_x1536, _ctx); /*std/num/ddouble/ddouble*/
              y_10304 = kk_std_num_ddouble__lp__star__rp_(r, _x_x1535, _ctx); /*std/num/ddouble/ddouble*/
              kk_std_num_ddouble__ddouble a1;
              kk_std_num_ddouble__ddouble _x_x1537;
              kk_std_num_ddouble__ddouble _x_x1538;
              kk_std_num_ddouble__ddouble _x_x1539;
              kk_std_num_ddouble__ddouble _x_x1540;
              double _x_x1541;
              double _x_x1542;
              {
                double _x_6 = y_10304.hi;
                _x_x1542 = _x_6; /*float64*/
              }
              _x_x1541 = (-_x_x1542); /*float64*/
              double _x_x1543;
              double _x_x1544;
              {
                double _x_0_2 = y_10304.lo;
                _x_x1544 = _x_0_2; /*float64*/
              }
              _x_x1543 = (-_x_x1544); /*float64*/
              _x_x1540 = kk_std_num_ddouble__new_Ddouble(_x_x1541, _x_x1543, _ctx); /*std/num/ddouble/ddouble*/
              _x_x1539 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x1540, _ctx); /*std/num/ddouble/ddouble*/
              _x_x1538 = kk_std_num_ddouble__lp__star__rp_(a0, _x_x1539, _ctx); /*std/num/ddouble/ddouble*/
              kk_std_num_ddouble__ddouble _x_x1545 = kk_std_num_ddouble_ddouble_int_exp(n, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
              _x_x1537 = kk_std_num_ddouble__lp__fs__rp_(_x_x1538, _x_x1545, _ctx); /*std/num/ddouble/ddouble*/
              a1 = kk_std_num_ddouble__lp__plus__rp_(a0, _x_x1537, _ctx); /*std/num/ddouble/ddouble*/
              kk_std_num_ddouble__ddouble _x_x1546;
              bool _match_x615;
              double _x_x1547;
              {
                double _x_2_0 = x.hi;
                _x_x1547 = _x_2_0; /*float64*/
              }
              _match_x615 = (_x_x1547 < (0x0p+0)); /*bool*/
              if (_match_x615) {
                double _x_x1548;
                double _x_x1549;
                kk_std_num_ddouble__ddouble _x_x1550 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
                {
                  double _x_7 = _x_x1550.hi;
                  _x_x1549 = _x_7; /*float64*/
                }
                _x_x1548 = (-_x_x1549); /*float64*/
                double _x_x1551;
                double _x_x1552;
                kk_std_num_ddouble__ddouble _x_x1553 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
                {
                  double _x_0_3 = _x_x1553.lo;
                  _x_x1552 = _x_0_3; /*float64*/
                }
                _x_x1551 = (-_x_x1552); /*float64*/
                _x_x1546 = kk_std_num_ddouble__new_Ddouble(_x_x1548, _x_x1551, _ctx); /*std/num/ddouble/ddouble*/
              }
              else {
                _x_x1546 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
              }
              return kk_std_num_ddouble__lp__fs__rp_(_x_x1546, a1, _ctx);
            }
          }
        }
      }
    }
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_one_half;
 
// Return `ln(1.0 + x)`.
// Avoids potential imprecision for small `x` where adding `1.0` explicitly
// may lead to rounding errors.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ln1p(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x608;
  double _x_x1558;
  {
    double _x = x.hi;
    _x_x1558 = _x; /*float64*/
  }
  _match_x608 = (isinf(_x_x1558) && !signbit(_x_x1558)); /*bool*/
  if (_match_x608) {
    return x;
  }
  {
    kk_std_num_ddouble__ddouble y = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, x, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble z;
    kk_std_num_ddouble__ddouble _x_x1559;
    double _x_x1560;
    double _x_x1561;
    kk_std_num_ddouble__ddouble _x_x1562 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_0 = _x_x1562.hi;
      _x_x1561 = _x_0; /*float64*/
    }
    _x_x1560 = (-_x_x1561); /*float64*/
    double _x_x1563;
    double _x_x1564;
    kk_std_num_ddouble__ddouble _x_x1565 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_0_0 = _x_x1565.lo;
      _x_x1564 = _x_0_0; /*float64*/
    }
    _x_x1563 = (-_x_x1564); /*float64*/
    _x_x1559 = kk_std_num_ddouble__new_Ddouble(_x_x1560, _x_x1563, _ctx); /*std/num/ddouble/ddouble*/
    z = kk_std_num_ddouble__lp__plus__rp_(y, _x_x1559, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_x609;
    double _x_x1566;
    {
      double _x_0_1 = z.hi;
      _x_x1566 = _x_0_1; /*float64*/
    }
    _match_x609 = (_x_x1566 == (0x0p+0)); /*bool*/
    if (_match_x609) {
      return x;
    }
    {
      kk_std_num_ddouble__ddouble _x_x1567 = kk_std_num_ddouble_ln(y, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1568 = kk_std_num_ddouble__lp__fs__rp_(x, z, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__star__rp_(_x_x1567, _x_x1568, _ctx);
    }
  }
}
 
// Return `exp(x - 1.0)`.
// Avoids rounding errors for values of `x` very close to `1.0`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_expm1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x603;
  double _x_x1569;
  {
    double _x = x.hi;
    _x_x1569 = _x; /*float64*/
  }
  _match_x603 = (isinf(_x_x1569) && !signbit(_x_x1569)); /*bool*/
  if (_match_x603) {
    return x;
  }
  {
    kk_std_num_ddouble__ddouble y = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_x604;
    kk_std_core_types__order _x_x1570;
    kk_std_core_types__order _match_x607;
    double _x_x1571;
    {
      double _x_0 = y.hi;
      _x_x1571 = _x_0; /*float64*/
    }
    double _x_x1572;
    kk_std_num_ddouble__ddouble _x_x1573 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_0_0 = _x_x1573.hi;
      _x_x1572 = _x_0_0; /*float64*/
    }
    _match_x607 = kk_std_num_float64_cmp(_x_x1571, _x_x1572, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x607, _ctx)) {
      double _x_x1574;
      {
        double _x_1 = y.lo;
        _x_x1574 = _x_1; /*float64*/
      }
      double _x_x1575;
      kk_std_num_ddouble__ddouble _x_x1576 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_2 = _x_x1576.lo;
        _x_x1575 = _x_2; /*float64*/
      }
      _x_x1570 = kk_std_num_float64_cmp(_x_x1574, _x_x1575, _ctx); /*order*/
    }
    else {
      _x_x1570 = _match_x607; /*order*/
    }
    _match_x604 = kk_std_core_order__lp__eq__eq__rp_(_x_x1570, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
    if (_match_x604) {
      return x;
    }
    {
      kk_std_num_ddouble__ddouble ym;
      kk_std_num_ddouble__ddouble _x_x1577;
      double _x_x1578;
      double _x_x1579;
      kk_std_num_ddouble__ddouble _x_x1580 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_3 = _x_x1580.hi;
        _x_x1579 = _x_3; /*float64*/
      }
      _x_x1578 = (-_x_x1579); /*float64*/
      double _x_x1581;
      double _x_x1582;
      kk_std_num_ddouble__ddouble _x_x1583 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_0_1 = _x_x1583.lo;
        _x_x1582 = _x_0_1; /*float64*/
      }
      _x_x1581 = (-_x_x1582); /*float64*/
      _x_x1577 = kk_std_num_ddouble__new_Ddouble(_x_x1578, _x_x1581, _ctx); /*std/num/ddouble/ddouble*/
      ym = kk_std_num_ddouble__lp__plus__rp_(y, _x_x1577, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble y_2_10333;
      double _x_x1584;
      double _x_x1585;
      kk_std_num_ddouble__ddouble _x_x1586 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_4 = _x_x1586.hi;
        _x_x1585 = _x_4; /*float64*/
      }
      _x_x1584 = (-_x_x1585); /*float64*/
      double _x_x1587;
      double _x_x1588;
      kk_std_num_ddouble__ddouble _x_x1589 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_0_2 = _x_x1589.lo;
        _x_x1588 = _x_0_2; /*float64*/
      }
      _x_x1587 = (-_x_x1588); /*float64*/
      y_2_10333 = kk_std_num_ddouble__new_Ddouble(_x_x1584, _x_x1587, _ctx); /*std/num/ddouble/ddouble*/
      bool _match_x605;
      kk_std_core_types__order _x_x1590;
      kk_std_core_types__order _match_x606;
      double _x_x1591;
      {
        double _x_5 = ym.hi;
        _x_x1591 = _x_5; /*float64*/
      }
      double _x_x1592;
      {
        double _x_0_3 = y_2_10333.hi;
        _x_x1592 = _x_0_3; /*float64*/
      }
      _match_x606 = kk_std_num_float64_cmp(_x_x1591, _x_x1592, _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x606, _ctx)) {
        double _x_x1593;
        {
          double _x_1_0 = ym.lo;
          _x_x1593 = _x_1_0; /*float64*/
        }
        double _x_x1594;
        {
          double _x_2_0 = y_2_10333.lo;
          _x_x1594 = _x_2_0; /*float64*/
        }
        _x_x1590 = kk_std_num_float64_cmp(_x_x1593, _x_x1594, _ctx); /*order*/
      }
      else {
        _x_x1590 = _match_x606; /*order*/
      }
      _match_x605 = kk_std_core_order__lp__eq__eq__rp_(_x_x1590, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
      if (_match_x605) {
        double _x_x1595;
        double _x_x1596;
        kk_std_num_ddouble__ddouble _x_x1597 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_6 = _x_x1597.hi;
          _x_x1596 = _x_6; /*float64*/
        }
        _x_x1595 = (-_x_x1596); /*float64*/
        double _x_x1598;
        double _x_x1599;
        kk_std_num_ddouble__ddouble _x_x1600 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_0_4 = _x_x1600.lo;
          _x_x1599 = _x_0_4; /*float64*/
        }
        _x_x1598 = (-_x_x1599); /*float64*/
        return kk_std_num_ddouble__new_Ddouble(_x_x1595, _x_x1598, _ctx);
      }
      {
        kk_std_num_ddouble__ddouble _x_x1601;
        kk_std_num_ddouble__ddouble _x_x1602 = kk_std_num_ddouble_ln(y, _ctx); /*std/num/ddouble/ddouble*/
        _x_x1601 = kk_std_num_ddouble__lp__fs__rp_(x, _x_x1602, _ctx); /*std/num/ddouble/ddouble*/
        return kk_std_num_ddouble__lp__star__rp_(ym, _x_x1601, _ctx);
      }
    }
  }
}
 
// Returns `ln(exp(x) + exp(y))`.
// Avoids overlow/underflow errors.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_lnaddexp(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_x600;
  kk_std_core_types__order _x_x1605;
  kk_std_core_types__order _match_x602;
  double _x_x1606;
  {
    double _x = x.hi;
    _x_x1606 = _x; /*float64*/
  }
  double _x_x1607;
  {
    double _x_0 = y.hi;
    _x_x1607 = _x_0; /*float64*/
  }
  _match_x602 = kk_std_num_float64_cmp(_x_x1606, _x_x1607, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x602, _ctx)) {
    double _x_x1608;
    {
      double _x_1 = x.lo;
      _x_x1608 = _x_1; /*float64*/
    }
    double _x_x1609;
    {
      double _x_2 = y.lo;
      _x_x1609 = _x_2; /*float64*/
    }
    _x_x1605 = kk_std_num_float64_cmp(_x_x1608, _x_x1609, _ctx); /*order*/
  }
  else {
    _x_x1605 = _match_x602; /*order*/
  }
  _match_x600 = kk_std_core_order__lp__eq__eq__rp_(_x_x1605, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
  if (_match_x600) {
    return kk_std_num_ddouble__lp__plus__rp_(x, kk_std_num_ddouble_dd_ln2, _ctx);
  }
  {
    kk_std_num_ddouble__ddouble z;
    kk_std_num_ddouble__ddouble _x_x1610;
    double _x_x1611;
    double _x_x1612;
    {
      double _x_3 = y.hi;
      _x_x1612 = _x_3; /*float64*/
    }
    _x_x1611 = (-_x_x1612); /*float64*/
    double _x_x1613;
    double _x_x1614;
    {
      double _x_0_0 = y.lo;
      _x_x1614 = _x_0_0; /*float64*/
    }
    _x_x1613 = (-_x_x1614); /*float64*/
    _x_x1610 = kk_std_num_ddouble__new_Ddouble(_x_x1611, _x_x1613, _ctx); /*std/num/ddouble/ddouble*/
    z = kk_std_num_ddouble__lp__plus__rp_(x, _x_x1610, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_x601;
    double _x_x1615;
    {
      double _x_4 = z.hi;
      _x_x1615 = _x_4; /*float64*/
    }
    _match_x601 = (_x_x1615 > (0x0p+0)); /*bool*/
    if (_match_x601) {
      kk_std_num_ddouble__ddouble _x_x1616;
      kk_std_num_ddouble__ddouble _x_x1617;
      kk_std_num_ddouble__ddouble _x_x1618;
      double _x_x1619;
      double _x_x1620;
      {
        double _x_5 = z.hi;
        _x_x1620 = _x_5; /*float64*/
      }
      _x_x1619 = (-_x_x1620); /*float64*/
      double _x_x1621;
      double _x_x1622;
      {
        double _x_0_1 = z.lo;
        _x_x1622 = _x_0_1; /*float64*/
      }
      _x_x1621 = (-_x_x1622); /*float64*/
      _x_x1618 = kk_std_num_ddouble__new_Ddouble(_x_x1619, _x_x1621, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1617 = kk_std_num_ddouble_exp(_x_x1618, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1616 = kk_std_num_ddouble_ln1p(_x_x1617, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__plus__rp_(x, _x_x1616, _ctx);
    }
    {
      kk_std_num_ddouble__ddouble _x_x1623;
      kk_std_num_ddouble__ddouble _x_x1624 = kk_std_num_ddouble_exp(z, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1623 = kk_std_num_ddouble_ln1p(_x_x1624, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__plus__rp_(y, _x_x1623, _ctx);
    }
  }
}
 
// Returns `log2( exp2(x) + exp2(y) )`.
// Avoids overlow/underflow errors.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_logaddexp2(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_x597;
  kk_std_core_types__order _x_x1625;
  kk_std_core_types__order _match_x599;
  double _x_x1626;
  {
    double _x = x.hi;
    _x_x1626 = _x; /*float64*/
  }
  double _x_x1627;
  {
    double _x_0 = y.hi;
    _x_x1627 = _x_0; /*float64*/
  }
  _match_x599 = kk_std_num_float64_cmp(_x_x1626, _x_x1627, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x599, _ctx)) {
    double _x_x1628;
    {
      double _x_1 = x.lo;
      _x_x1628 = _x_1; /*float64*/
    }
    double _x_x1629;
    {
      double _x_2 = y.lo;
      _x_x1629 = _x_2; /*float64*/
    }
    _x_x1625 = kk_std_num_float64_cmp(_x_x1628, _x_x1629, _ctx); /*order*/
  }
  else {
    _x_x1625 = _match_x599; /*order*/
  }
  _match_x597 = kk_std_core_order__lp__eq__eq__rp_(_x_x1625, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
  if (_match_x597) {
    return kk_std_num_ddouble__lp__plus__rp_(x, kk_std_num_ddouble_one, _ctx);
  }
  {
    kk_std_num_ddouble__ddouble z;
    kk_std_num_ddouble__ddouble _x_x1630;
    double _x_x1631;
    double _x_x1632;
    {
      double _x_3 = y.hi;
      _x_x1632 = _x_3; /*float64*/
    }
    _x_x1631 = (-_x_x1632); /*float64*/
    double _x_x1633;
    double _x_x1634;
    {
      double _x_0_0 = y.lo;
      _x_x1634 = _x_0_0; /*float64*/
    }
    _x_x1633 = (-_x_x1634); /*float64*/
    _x_x1630 = kk_std_num_ddouble__new_Ddouble(_x_x1631, _x_x1633, _ctx); /*std/num/ddouble/ddouble*/
    z = kk_std_num_ddouble__lp__plus__rp_(x, _x_x1630, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_x598;
    double _x_x1635;
    {
      double _x_4 = z.hi;
      _x_x1635 = _x_4; /*float64*/
    }
    _match_x598 = (_x_x1635 > (0x0p+0)); /*bool*/
    if (_match_x598) {
      kk_std_num_ddouble__ddouble exp_0_10349;
      double _x_x1636;
      double _x_x1637;
      {
        double _x_5 = z.hi;
        _x_x1637 = _x_5; /*float64*/
      }
      _x_x1636 = (-_x_x1637); /*float64*/
      double _x_x1638;
      double _x_x1639;
      {
        double _x_0_1 = z.lo;
        _x_x1639 = _x_0_1; /*float64*/
      }
      _x_x1638 = (-_x_x1639); /*float64*/
      exp_0_10349 = kk_std_num_ddouble__new_Ddouble(_x_x1636, _x_x1638, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble x_3_10348;
      kk_std_num_ddouble__ddouble _x_x1640;
      kk_std_num_ddouble__ddouble _x_x1641 = kk_std_num_ddouble_ln(kk_std_num_ddouble_two, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1640 = kk_std_num_ddouble__lp__star__rp_(exp_0_10349, _x_x1641, _ctx); /*std/num/ddouble/ddouble*/
      x_3_10348 = kk_std_num_ddouble_exp(_x_x1640, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1642;
      kk_std_num_ddouble__ddouble _x_x1643 = kk_std_num_ddouble_ln1p(x_3_10348, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1642 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_dd_log2e, _x_x1643, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__plus__rp_(x, _x_x1642, _ctx);
    }
    {
      kk_std_num_ddouble__ddouble x_5_10352;
      kk_std_num_ddouble__ddouble _x_x1644;
      kk_std_num_ddouble__ddouble _x_x1645 = kk_std_num_ddouble_ln(kk_std_num_ddouble_two, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1644 = kk_std_num_ddouble__lp__star__rp_(z, _x_x1645, _ctx); /*std/num/ddouble/ddouble*/
      x_5_10352 = kk_std_num_ddouble_exp(_x_x1644, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1646;
      kk_std_num_ddouble__ddouble _x_x1647 = kk_std_num_ddouble_ln1p(x_5_10352, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1646 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_dd_log2e, _x_x1647, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__plus__rp_(y, _x_x1646, _ctx);
    }
  }
}
 
// Return if two `:ddouble`s are nearly equal with respect to some `epsilon` (=`8*dd-epsilon`).
// The epsilon is the nearest difference for numbers around 1.0. The routine automatically
// scales the epsilon for larger and smaller numbers, and for numbers close to zero.

bool kk_std_num_ddouble_nearly_eq(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_core_types__optional epsilon, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble, epsilon : ? ddouble) -> bool */ 
  bool _match_x582;
  kk_std_core_types__order _x_x1648;
  kk_std_core_types__order _match_x596;
  double _x_x1649;
  {
    double _x = x.hi;
    _x_x1649 = _x; /*float64*/
  }
  double _x_x1650;
  {
    double _x_0 = y.hi;
    _x_x1650 = _x_0; /*float64*/
  }
  _match_x596 = kk_std_num_float64_cmp(_x_x1649, _x_x1650, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x596, _ctx)) {
    double _x_x1651;
    {
      double _x_1 = x.lo;
      _x_x1651 = _x_1; /*float64*/
    }
    double _x_x1652;
    {
      double _x_2 = y.lo;
      _x_x1652 = _x_2; /*float64*/
    }
    _x_x1648 = kk_std_num_float64_cmp(_x_x1651, _x_x1652, _ctx); /*order*/
  }
  else {
    _x_x1648 = _match_x596; /*order*/
  }
  _match_x582 = kk_std_core_order__lp__eq__eq__rp_(_x_x1648, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
  if (_match_x582) {
    kk_std_core_types__optional_drop(epsilon, _ctx);
    return true;
  }
  {
    kk_std_num_ddouble__ddouble x_1_10358;
    kk_std_num_ddouble__ddouble _x_x1653;
    double _x_x1654;
    double _x_x1655;
    {
      double _x_3 = y.hi;
      _x_x1655 = _x_3; /*float64*/
    }
    _x_x1654 = (-_x_x1655); /*float64*/
    double _x_x1656;
    double _x_x1657;
    {
      double _x_0_0 = y.lo;
      _x_x1657 = _x_0_0; /*float64*/
    }
    _x_x1656 = (-_x_x1657); /*float64*/
    _x_x1653 = kk_std_num_ddouble__new_Ddouble(_x_x1654, _x_x1656, _ctx); /*std/num/ddouble/ddouble*/
    x_1_10358 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x1653, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble diff;
    bool _match_x595;
    double _x_x1658;
    {
      double _x_4 = x_1_10358.hi;
      _x_x1658 = _x_4; /*float64*/
    }
    _match_x595 = (_x_x1658 < (0x0p+0)); /*bool*/
    if (_match_x595) {
      double _x_x1659;
      double _x_x1660;
      {
        double _x_5 = x_1_10358.hi;
        _x_x1660 = _x_5; /*float64*/
      }
      _x_x1659 = (-_x_x1660); /*float64*/
      double _x_x1661;
      double _x_x1662;
      {
        double _x_0_1 = x_1_10358.lo;
        _x_x1662 = _x_0_1; /*float64*/
      }
      _x_x1661 = (-_x_x1662); /*float64*/
      diff = kk_std_num_ddouble__new_Ddouble(_x_x1659, _x_x1661, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      diff = x_1_10358; /*std/num/ddouble/ddouble*/
    }
    bool _match_x583;
    double _x_x1663;
    {
      double _x_0_2 = x.hi;
      _x_x1663 = _x_0_2; /*float64*/
    }
    _match_x583 = (_x_x1663 == (0x0p+0)); /*bool*/
    if (_match_x583) {
      kk_std_num_ddouble__ddouble x_5_10367 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_two, diff, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble y_2_10368;
      kk_std_num_ddouble__ddouble _x_x1664;
      if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
        kk_box_t _box_x377 = epsilon._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_epsilon_8558 = kk_std_num_ddouble__ddouble_unbox(_box_x377, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(epsilon, _ctx);
        _x_x1664 = _uniq_epsilon_8558; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_core_types__optional_drop(epsilon, _ctx);
        _x_x1664 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
      }
      y_2_10368 = kk_std_num_ddouble__lp__star__rp_(_x_x1664, kk_std_num_ddouble_dd_min, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_core_types__order _x_x1665;
      kk_std_core_types__order _match_x594;
      double _x_x1666;
      {
        double _x_6 = x_5_10367.hi;
        _x_x1666 = _x_6; /*float64*/
      }
      double _x_x1667;
      {
        double _x_0_3 = y_2_10368.hi;
        _x_x1667 = _x_0_3; /*float64*/
      }
      _match_x594 = kk_std_num_float64_cmp(_x_x1666, _x_x1667, _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x594, _ctx)) {
        double _x_x1668;
        {
          double _x_1_0 = x_5_10367.lo;
          _x_x1668 = _x_1_0; /*float64*/
        }
        double _x_x1669;
        {
          double _x_2_0 = y_2_10368.lo;
          _x_x1669 = _x_2_0; /*float64*/
        }
        _x_x1665 = kk_std_num_float64_cmp(_x_x1668, _x_x1669, _ctx); /*order*/
      }
      else {
        _x_x1665 = _match_x594; /*order*/
      }
      return kk_std_core_order__lp__eq__eq__rp_(_x_x1665, kk_std_core_types__new_Lt(_ctx), _ctx);
    }
    {
      bool _match_x584;
      double _x_x1670;
      {
        double _x_1_1 = y.hi;
        _x_x1670 = _x_1_1; /*float64*/
      }
      _match_x584 = (_x_x1670 == (0x0p+0)); /*bool*/
      if (_match_x584) {
        kk_std_num_ddouble__ddouble x_7_10372 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_two, diff, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble y_3_10373;
        kk_std_num_ddouble__ddouble _x_x1671;
        if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
          kk_box_t _box_x378 = epsilon._cons._Optional.value;
          kk_std_num_ddouble__ddouble _uniq_epsilon_8558_0 = kk_std_num_ddouble__ddouble_unbox(_box_x378, KK_BORROWED, _ctx);
          kk_std_core_types__optional_drop(epsilon, _ctx);
          _x_x1671 = _uniq_epsilon_8558_0; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_std_core_types__optional_drop(epsilon, _ctx);
          _x_x1671 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
        }
        y_3_10373 = kk_std_num_ddouble__lp__star__rp_(_x_x1671, kk_std_num_ddouble_dd_min, _ctx); /*std/num/ddouble/ddouble*/
        kk_std_core_types__order _x_x1672;
        kk_std_core_types__order _match_x593;
        double _x_x1673;
        {
          double _x_7 = x_7_10372.hi;
          _x_x1673 = _x_7; /*float64*/
        }
        double _x_x1674;
        {
          double _x_0_4 = y_3_10373.hi;
          _x_x1674 = _x_0_4; /*float64*/
        }
        _match_x593 = kk_std_num_float64_cmp(_x_x1673, _x_x1674, _ctx); /*order*/
        if (kk_std_core_types__is_Eq(_match_x593, _ctx)) {
          double _x_x1675;
          {
            double _x_1_2 = x_7_10372.lo;
            _x_x1675 = _x_1_2; /*float64*/
          }
          double _x_x1676;
          {
            double _x_2_1 = y_3_10373.lo;
            _x_x1676 = _x_2_1; /*float64*/
          }
          _x_x1672 = kk_std_num_float64_cmp(_x_x1675, _x_x1676, _ctx); /*order*/
        }
        else {
          _x_x1672 = _match_x593; /*order*/
        }
        return kk_std_core_order__lp__eq__eq__rp_(_x_x1672, kk_std_core_types__new_Lt(_ctx), _ctx);
      }
      {
        bool _match_x585;
        kk_std_core_types__order _x_x1677;
        kk_std_core_types__order _match_x592;
        double _x_x1678;
        {
          double _x_8 = diff.hi;
          _x_x1678 = _x_8; /*float64*/
        }
        double _x_x1679;
        kk_std_num_ddouble__ddouble _x_x1680 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
        {
          double _x_0_5 = _x_x1680.hi;
          _x_x1679 = _x_0_5; /*float64*/
        }
        _match_x592 = kk_std_num_float64_cmp(_x_x1678, _x_x1679, _ctx); /*order*/
        if (kk_std_core_types__is_Eq(_match_x592, _ctx)) {
          double _x_x1681;
          {
            double _x_1_3 = diff.lo;
            _x_x1681 = _x_1_3; /*float64*/
          }
          double _x_x1682;
          kk_std_num_ddouble__ddouble _x_x1683 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
          {
            double _x_2_2 = _x_x1683.lo;
            _x_x1682 = _x_2_2; /*float64*/
          }
          _x_x1677 = kk_std_num_float64_cmp(_x_x1681, _x_x1682, _ctx); /*order*/
        }
        else {
          _x_x1677 = _match_x592; /*order*/
        }
        _match_x585 = kk_std_core_order__lp__eq__eq__rp_(_x_x1677, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
        if (_match_x585) {
          kk_std_num_ddouble__ddouble x_9_10376 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_two, diff, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble y_5_10377;
          kk_std_num_ddouble__ddouble _x_x1684;
          if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
            kk_box_t _box_x379 = epsilon._cons._Optional.value;
            kk_std_num_ddouble__ddouble _uniq_epsilon_8558_1 = kk_std_num_ddouble__ddouble_unbox(_box_x379, KK_BORROWED, _ctx);
            kk_std_core_types__optional_drop(epsilon, _ctx);
            _x_x1684 = _uniq_epsilon_8558_1; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_std_core_types__optional_drop(epsilon, _ctx);
            _x_x1684 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
          }
          y_5_10377 = kk_std_num_ddouble__lp__star__rp_(_x_x1684, kk_std_num_ddouble_dd_min, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_core_types__order _x_x1685;
          kk_std_core_types__order _match_x591;
          double _x_x1686;
          {
            double _x_9 = x_9_10376.hi;
            _x_x1686 = _x_9; /*float64*/
          }
          double _x_x1687;
          {
            double _x_0_6 = y_5_10377.hi;
            _x_x1687 = _x_0_6; /*float64*/
          }
          _match_x591 = kk_std_num_float64_cmp(_x_x1686, _x_x1687, _ctx); /*order*/
          if (kk_std_core_types__is_Eq(_match_x591, _ctx)) {
            double _x_x1688;
            {
              double _x_1_4 = x_9_10376.lo;
              _x_x1688 = _x_1_4; /*float64*/
            }
            double _x_x1689;
            {
              double _x_2_3 = y_5_10377.lo;
              _x_x1689 = _x_2_3; /*float64*/
            }
            _x_x1685 = kk_std_num_float64_cmp(_x_x1688, _x_x1689, _ctx); /*order*/
          }
          else {
            _x_x1685 = _match_x591; /*order*/
          }
          return kk_std_core_order__lp__eq__eq__rp_(_x_x1685, kk_std_core_types__new_Lt(_ctx), _ctx);
        }
        {
          kk_std_num_ddouble__ddouble sum_0;
          kk_std_num_ddouble__ddouble _x_x1690 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x1691 = kk_std_num_ddouble_abs(y, _ctx); /*std/num/ddouble/ddouble*/
          sum_0 = kk_std_num_ddouble__lp__plus__rp_(_x_x1690, _x_x1691, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble x_10_10378;
          kk_std_num_ddouble__ddouble _x_x1692 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_two, diff, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x1693;
          bool _match_x589;
          kk_std_core_types__order _x_x1694;
          kk_std_core_types__order _match_x590;
          double _x_x1695;
          {
            double _x_10 = sum_0.hi;
            _x_x1695 = _x_10; /*float64*/
          }
          double _x_x1696;
          kk_std_num_ddouble__ddouble _x_x1697 = kk_std_num_ddouble_dd_max; /*std/num/ddouble/ddouble*/
          {
            double _x_0_7 = _x_x1697.hi;
            _x_x1696 = _x_0_7; /*float64*/
          }
          _match_x590 = kk_std_num_float64_cmp(_x_x1695, _x_x1696, _ctx); /*order*/
          if (kk_std_core_types__is_Eq(_match_x590, _ctx)) {
            double _x_x1698;
            {
              double _x_1_5 = sum_0.lo;
              _x_x1698 = _x_1_5; /*float64*/
            }
            double _x_x1699;
            kk_std_num_ddouble__ddouble _x_x1700 = kk_std_num_ddouble_dd_max; /*std/num/ddouble/ddouble*/
            {
              double _x_2_4 = _x_x1700.lo;
              _x_x1699 = _x_2_4; /*float64*/
            }
            _x_x1694 = kk_std_num_float64_cmp(_x_x1698, _x_x1699, _ctx); /*order*/
          }
          else {
            _x_x1694 = _match_x590; /*order*/
          }
          _match_x589 = kk_std_core_order__lp__eq__eq__rp_(_x_x1694, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
          if (_match_x589) {
            _x_x1693 = kk_std_num_ddouble_dd_max; /*std/num/ddouble/ddouble*/
          }
          else {
            _x_x1693 = sum_0; /*std/num/ddouble/ddouble*/
          }
          x_10_10378 = kk_std_num_ddouble__lp__fs__rp_(_x_x1692, _x_x1693, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_core_types__order _x_x1701;
          kk_std_core_types__order _match_x586;
          double _x_x1702;
          {
            double _x_11 = x_10_10378.hi;
            _x_x1702 = _x_11; /*float64*/
          }
          double _x_x1703;
          kk_std_num_ddouble__ddouble _match_x588;
          if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
            kk_box_t _box_x380 = epsilon._cons._Optional.value;
            kk_std_num_ddouble__ddouble _uniq_epsilon_8558_2 = kk_std_num_ddouble__ddouble_unbox(_box_x380, KK_BORROWED, _ctx);
            _match_x588 = _uniq_epsilon_8558_2; /*std/num/ddouble/ddouble*/
          }
          else {
            _match_x588 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_0_8 = _match_x588.hi;
            _x_x1703 = _x_0_8; /*float64*/
          }
          _match_x586 = kk_std_num_float64_cmp(_x_x1702, _x_x1703, _ctx); /*order*/
          if (kk_std_core_types__is_Eq(_match_x586, _ctx)) {
            double _x_x1704;
            {
              double _x_1_6 = x_10_10378.lo;
              _x_x1704 = _x_1_6; /*float64*/
            }
            double _x_x1705;
            kk_std_num_ddouble__ddouble _match_x587;
            if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
              kk_box_t _box_x381 = epsilon._cons._Optional.value;
              kk_std_num_ddouble__ddouble _uniq_epsilon_8558_3 = kk_std_num_ddouble__ddouble_unbox(_box_x381, KK_BORROWED, _ctx);
              kk_std_core_types__optional_drop(epsilon, _ctx);
              _match_x587 = _uniq_epsilon_8558_3; /*std/num/ddouble/ddouble*/
            }
            else {
              kk_std_core_types__optional_drop(epsilon, _ctx);
              _match_x587 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
            }
            {
              double _x_2_5 = _match_x587.lo;
              _x_x1705 = _x_2_5; /*float64*/
            }
            _x_x1701 = kk_std_num_float64_cmp(_x_x1704, _x_x1705, _ctx); /*order*/
          }
          else {
            kk_std_core_types__optional_drop(epsilon, _ctx);
            _x_x1701 = _match_x586; /*order*/
          }
          return kk_std_core_order__lp__eq__eq__rp_(_x_x1701, kk_std_core_types__new_Lt(_ctx), _ctx);
        }
      }
    }
  }
}
 
// The hypotenuse of `x` and `y`: `sqrt(x*x + y*y)`.
// Prevents overflow for large numbers.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_hypot(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble xx = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble yy = kk_std_num_ddouble_abs(y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble lo;
  bool _match_x580;
  kk_std_core_types__order _x_x1706;
  kk_std_core_types__order _match_x581;
  double _x_x1707;
  {
    double _x = xx.hi;
    _x_x1707 = _x; /*float64*/
  }
  double _x_x1708;
  {
    double _x_0 = yy.hi;
    _x_x1708 = _x_0; /*float64*/
  }
  _match_x581 = kk_std_num_float64_cmp(_x_x1707, _x_x1708, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x581, _ctx)) {
    double _x_x1709;
    {
      double _x_1 = xx.lo;
      _x_x1709 = _x_1; /*float64*/
    }
    double _x_x1710;
    {
      double _x_2 = yy.lo;
      _x_x1710 = _x_2; /*float64*/
    }
    _x_x1706 = kk_std_num_float64_cmp(_x_x1709, _x_x1710, _ctx); /*order*/
  }
  else {
    _x_x1706 = _match_x581; /*order*/
  }
  _match_x580 = kk_std_core_order__lp__excl__eq__rp_(_x_x1706, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
  if (_match_x580) {
    lo = xx; /*std/num/ddouble/ddouble*/
  }
  else {
    lo = yy; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble hi;
  bool _match_x578;
  kk_std_core_types__order _x_x1711;
  kk_std_core_types__order _match_x579;
  double _x_x1712;
  {
    double _x_3 = xx.hi;
    _x_x1712 = _x_3; /*float64*/
  }
  double _x_x1713;
  {
    double _x_0_0 = yy.hi;
    _x_x1713 = _x_0_0; /*float64*/
  }
  _match_x579 = kk_std_num_float64_cmp(_x_x1712, _x_x1713, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x579, _ctx)) {
    double _x_x1714;
    {
      double _x_1_0 = xx.lo;
      _x_x1714 = _x_1_0; /*float64*/
    }
    double _x_x1715;
    {
      double _x_2_0 = yy.lo;
      _x_x1715 = _x_2_0; /*float64*/
    }
    _x_x1711 = kk_std_num_float64_cmp(_x_x1714, _x_x1715, _ctx); /*order*/
  }
  else {
    _x_x1711 = _match_x579; /*order*/
  }
  _match_x578 = kk_std_core_order__lp__excl__eq__rp_(_x_x1711, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x578) {
    hi = xx; /*std/num/ddouble/ddouble*/
  }
  else {
    hi = yy; /*std/num/ddouble/ddouble*/
  }
  bool _match_x577;
  double _x_x1716;
  {
    double _x_4 = hi.hi;
    _x_x1716 = _x_4; /*float64*/
  }
  _match_x577 = (_x_x1716 == (0x0p+0)); /*bool*/
  if (_match_x577) {
    return kk_std_num_ddouble_zero;
  }
  {
    kk_std_num_ddouble__ddouble z = kk_std_num_ddouble__lp__fs__rp_(lo, hi, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble _x_x1717;
    kk_std_num_ddouble__ddouble _x_x1718;
    kk_std_num_ddouble__ddouble _x_x1719 = kk_std_num_ddouble__lp__star__rp_(z, z, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1718 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x1719, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1717 = kk_std_num_ddouble_sqrt(_x_x1718, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__star__rp_(hi, _x_x1717, _ctx);
  }
}
 
// The square root of the sum of the squares of three doubles.
// Prevents overflow for large numbers.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_xyz_fs_hypot(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_num_ddouble__ddouble z, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble, z : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble xx = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble yy = kk_std_num_ddouble_abs(y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble zz = kk_std_num_ddouble_abs(z, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble x_0_10393;
  bool _match_x575;
  kk_std_core_types__order _x_x1720;
  kk_std_core_types__order _match_x576;
  double _x_x1721;
  {
    double _x = xx.hi;
    _x_x1721 = _x; /*float64*/
  }
  double _x_x1722;
  {
    double _x_0 = yy.hi;
    _x_x1722 = _x_0; /*float64*/
  }
  _match_x576 = kk_std_num_float64_cmp(_x_x1721, _x_x1722, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x576, _ctx)) {
    double _x_x1723;
    {
      double _x_1 = xx.lo;
      _x_x1723 = _x_1; /*float64*/
    }
    double _x_x1724;
    {
      double _x_2 = yy.lo;
      _x_x1724 = _x_2; /*float64*/
    }
    _x_x1720 = kk_std_num_float64_cmp(_x_x1723, _x_x1724, _ctx); /*order*/
  }
  else {
    _x_x1720 = _match_x576; /*order*/
  }
  _match_x575 = kk_std_core_order__lp__excl__eq__rp_(_x_x1720, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x575) {
    x_0_10393 = xx; /*std/num/ddouble/ddouble*/
  }
  else {
    x_0_10393 = yy; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble hi;
  bool _match_x573;
  kk_std_core_types__order _x_x1725;
  kk_std_core_types__order _match_x574;
  double _x_x1726;
  {
    double _x_3 = x_0_10393.hi;
    _x_x1726 = _x_3; /*float64*/
  }
  double _x_x1727;
  {
    double _x_0_0 = zz.hi;
    _x_x1727 = _x_0_0; /*float64*/
  }
  _match_x574 = kk_std_num_float64_cmp(_x_x1726, _x_x1727, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x574, _ctx)) {
    double _x_x1728;
    {
      double _x_1_0 = x_0_10393.lo;
      _x_x1728 = _x_1_0; /*float64*/
    }
    double _x_x1729;
    {
      double _x_2_0 = zz.lo;
      _x_x1729 = _x_2_0; /*float64*/
    }
    _x_x1725 = kk_std_num_float64_cmp(_x_x1728, _x_x1729, _ctx); /*order*/
  }
  else {
    _x_x1725 = _match_x574; /*order*/
  }
  _match_x573 = kk_std_core_order__lp__excl__eq__rp_(_x_x1725, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x573) {
    hi = x_0_10393; /*std/num/ddouble/ddouble*/
  }
  else {
    hi = zz; /*std/num/ddouble/ddouble*/
  }
  bool _match_x572;
  double _x_x1730;
  {
    double _x_4 = hi.hi;
    _x_x1730 = _x_4; /*float64*/
  }
  _match_x572 = (_x_x1730 == (0x0p+0)); /*bool*/
  if (_match_x572) {
    return kk_std_num_ddouble_zero;
  }
  {
    kk_std_num_ddouble__ddouble _x_x1731;
    kk_std_num_ddouble__ddouble _x_x1732;
    kk_std_num_ddouble__ddouble _x_x1733;
    kk_std_num_ddouble__ddouble _x_x1734;
    kk_std_num_ddouble__ddouble _x_x1735 = kk_std_num_ddouble__lp__fs__rp_(xx, hi, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1734 = kk_std_num_ddouble_sqr(_x_x1735, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1736;
    kk_std_num_ddouble__ddouble _x_x1737 = kk_std_num_ddouble__lp__fs__rp_(yy, hi, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1736 = kk_std_num_ddouble_sqr(_x_x1737, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1733 = kk_std_num_ddouble__lp__plus__rp_(_x_x1734, _x_x1736, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1738;
    kk_std_num_ddouble__ddouble _x_x1739 = kk_std_num_ddouble__lp__fs__rp_(zz, hi, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1738 = kk_std_num_ddouble_sqr(_x_x1739, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1732 = kk_std_num_ddouble__lp__plus__rp_(_x_x1733, _x_x1738, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1731 = kk_std_num_ddouble_sqrt(_x_x1732, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__star__rp_(hi, _x_x1731, _ctx);
  }
}
 
// The maximum of the absolute values.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_abs_max(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_0_10404 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y_0_10405 = kk_std_num_ddouble_abs(y, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x570;
  kk_std_core_types__order _x_x1740;
  kk_std_core_types__order _match_x571;
  double _x_x1741;
  {
    double _x = x_0_10404.hi;
    _x_x1741 = _x; /*float64*/
  }
  double _x_x1742;
  {
    double _x_0 = y_0_10405.hi;
    _x_x1742 = _x_0; /*float64*/
  }
  _match_x571 = kk_std_num_float64_cmp(_x_x1741, _x_x1742, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x571, _ctx)) {
    double _x_x1743;
    {
      double _x_1 = x_0_10404.lo;
      _x_x1743 = _x_1; /*float64*/
    }
    double _x_x1744;
    {
      double _x_2 = y_0_10405.lo;
      _x_x1744 = _x_2; /*float64*/
    }
    _x_x1740 = kk_std_num_float64_cmp(_x_x1743, _x_x1744, _ctx); /*order*/
  }
  else {
    _x_x1740 = _match_x571; /*order*/
  }
  _match_x570 = kk_std_core_order__lp__excl__eq__rp_(_x_x1740, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x570) {
    return x_0_10404;
  }
  {
    return y_0_10405;
  }
}
 
// The maximum of a list of absolute values.


// lift anonymous function
struct kk_std_num_ddouble_list_fs_abs_max_fun1746__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_list_fs_abs_max_fun1746(kk_function_t _fself, kk_box_t _b_x385, kk_box_t _b_x386, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_list_fs_new_abs_max_fun1746(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_list_fs_abs_max_fun1746, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_list_fs_abs_max_fun1746(kk_function_t _fself, kk_box_t _b_x385, kk_box_t _b_x386, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble x_390 = kk_std_num_ddouble__ddouble_unbox(_b_x385, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble m_391 = kk_std_num_ddouble__ddouble_unbox(_b_x386, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble x_0_10408 = kk_std_num_ddouble_abs(x_390, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x_x1747;
  bool _match_x568;
  kk_std_core_types__order _x_x1748;
  kk_std_core_types__order _match_x569;
  double _x_x1749;
  {
    double _x = x_0_10408.hi;
    _x_x1749 = _x; /*float64*/
  }
  double _x_x1750;
  {
    double _x_0 = m_391.hi;
    _x_x1750 = _x_0; /*float64*/
  }
  _match_x569 = kk_std_num_float64_cmp(_x_x1749, _x_x1750, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x569, _ctx)) {
    double _x_x1751;
    {
      double _x_1 = x_0_10408.lo;
      _x_x1751 = _x_1; /*float64*/
    }
    double _x_x1752;
    {
      double _x_2 = m_391.lo;
      _x_x1752 = _x_2; /*float64*/
    }
    _x_x1748 = kk_std_num_float64_cmp(_x_x1751, _x_x1752, _ctx); /*order*/
  }
  else {
    _x_x1748 = _match_x569; /*order*/
  }
  _match_x568 = kk_std_core_order__lp__excl__eq__rp_(_x_x1748, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x568) {
    _x_x1747 = x_0_10408; /*std/num/ddouble/ddouble*/
  }
  else {
    _x_x1747 = m_391; /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__ddouble_box(_x_x1747, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs_abs_max(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<ddouble>) -> ddouble */ 
  kk_box_t _x_x1745 = kk_std_core_list_foldr(xs, kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx), kk_std_num_ddouble_list_fs_new_abs_max_fun1746(_ctx), _ctx); /*10002*/
  return kk_std_num_ddouble__ddouble_unbox(_x_x1745, KK_OWNED, _ctx);
}
 
// The square root of the sum of squares of a list of doubles.
// Prevents overflow for large numbers and uses Kahan-Babu&scaron;kan-Neumaier summation
// for precision.


// lift anonymous function
struct kk_std_num_ddouble_list_fs_hypot_fun1756__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble hi;
};
static kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs_hypot_fun1756(kk_function_t _fself, kk_std_num_ddouble__ddouble x_0, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_list_fs_new_hypot_fun1756(kk_std_num_ddouble__ddouble hi, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_list_fs_hypot_fun1756__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_list_fs_hypot_fun1756__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_list_fs_hypot_fun1756, kk_context());
  _self->hi = hi;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs_hypot_fun1756(kk_function_t _fself, kk_std_num_ddouble__ddouble x_0, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_list_fs_hypot_fun1756__t* _self = kk_function_as(struct kk_std_num_ddouble_list_fs_hypot_fun1756__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble hi = _self->hi; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(hi, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x_x1757 = kk_std_num_ddouble__lp__fs__rp_(x_0, hi, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_sqr(_x_x1757, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_list_fs_hypot_fun1760__t {
  struct kk_function_s _base;
  kk_function_t _b_x393_396;
};
static kk_box_t kk_std_num_ddouble_list_fs_hypot_fun1760(kk_function_t _fself, kk_box_t _b_x394, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_list_fs_new_hypot_fun1760(kk_function_t _b_x393_396, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_list_fs_hypot_fun1760__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_list_fs_hypot_fun1760__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_list_fs_hypot_fun1760, kk_context());
  _self->_b_x393_396 = _b_x393_396;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_list_fs_hypot_fun1760(kk_function_t _fself, kk_box_t _b_x394, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_list_fs_hypot_fun1760__t* _self = kk_function_as(struct kk_std_num_ddouble_list_fs_hypot_fun1760__t*, _fself, _ctx);
  kk_function_t _b_x393_396 = _self->_b_x393_396; /* (x@0 : std/num/ddouble/ddouble) -> std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_function_dup(_b_x393_396, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x_x1761;
  kk_std_num_ddouble__ddouble _x_x1762 = kk_std_num_ddouble__ddouble_unbox(_b_x394, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1761 = kk_function_call(kk_std_num_ddouble__ddouble, (kk_function_t, kk_std_num_ddouble__ddouble, kk_context_t*), _b_x393_396, (_b_x393_396, _x_x1762, _ctx), _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1761, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs_hypot(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<ddouble>) -> ddouble */ 
  kk_std_num_ddouble__ddouble hi;
  kk_std_core_types__list _x_x1753 = kk_std_core_types__list_dup(xs, _ctx); /*list<std/num/ddouble/ddouble>*/
  hi = kk_std_num_ddouble_list_fs_abs_max(_x_x1753, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_x565;
  double _x_x1754;
  {
    double _x = hi.hi;
    _x_x1754 = _x; /*float64*/
  }
  _match_x565 = (_x_x1754 == (0x0p+0)); /*bool*/
  if (_match_x565) {
    kk_std_core_types__list_drop(xs, _ctx);
    return kk_std_num_ddouble_zero;
  }
  {
    kk_std_num_ddouble__ddouble _x_x1755;
    kk_std_core_types__list _b_x392_395 = xs; /*list<std/num/ddouble/ddouble>*/;
    kk_function_t _b_x393_396 = kk_std_num_ddouble_list_fs_new_hypot_fun1756(hi, _ctx); /*(x@0 : std/num/ddouble/ddouble) -> std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble _x_x1758;
    kk_std_core_types__list _x_x1759;
    kk_function_t _brw_x566 = kk_std_num_ddouble_list_fs_new_hypot_fun1760(_b_x393_396, _ctx); /*(10001) -> 10003 10002*/;
    kk_std_core_types__list _brw_x567 = kk_std_core_list_map(_b_x392_395, _brw_x566, _ctx); /*list<10002>*/;
    kk_function_drop(_brw_x566, _ctx);
    _x_x1759 = _brw_x567; /*list<10002>*/
    _x_x1758 = kk_std_num_ddouble_list_fs_sum(_x_x1759, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1755 = kk_std_num_ddouble_sqrt(_x_x1758, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__star__rp_(hi, _x_x1755, _ctx);
  }
}

kk_std_core_types__list kk_std_num_ddouble_ch_factors;

kk_vector_t kk_std_num_ddouble_sin16_table;
 
// Calculate sine and cosine on an angle in radians.


// lift anonymous function
struct kk_std_num_ddouble_sincos_fun1849__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble s2;
};
static kk_box_t kk_std_num_ddouble_sincos_fun1849(kk_function_t _fself, kk_box_t _b_x469, kk_box_t _b_x470, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_sincos_fun1849(kk_std_num_ddouble__ddouble s2, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_sincos_fun1849__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_sincos_fun1849__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_sincos_fun1849, kk_context());
  _self->s2 = s2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_sincos_fun1849(kk_function_t _fself, kk_box_t _b_x469, kk_box_t _b_x470, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_sincos_fun1849__t* _self = kk_function_as(struct kk_std_num_ddouble_sincos_fun1849__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble s2 = _self->s2; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(s2, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x_x1850;
  kk_std_num_ddouble__ddouble _x_x1851 = kk_std_num_ddouble__ddouble_unbox(_b_x470, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1852;
  kk_std_num_ddouble__ddouble _x_x1853 = kk_std_num_ddouble__ddouble_unbox(_b_x469, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1852 = kk_std_num_ddouble__lp__star__rp_(_x_x1853, s2, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1850 = kk_std_num_ddouble__lp__plus__rp_(_x_x1851, _x_x1852, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1850, _ctx);
}

kk_std_core_types__tuple2 kk_std_num_ddouble_sincos(kk_std_num_ddouble__ddouble rad, kk_context_t* _ctx) { /* (rad : ddouble) -> (ddouble, ddouble) */ 
  bool _match_x550;
  double _x_x1799;
  double _x_x1800;
  {
    double _x = rad.hi;
    _x_x1800 = _x; /*float64*/
  }
  _x_x1799 = kk_double_abs(_x_x1800); /*float64*/
  _match_x550 = (_x_x1799 < (0x1.5fd7fe1796495p-37)); /*bool*/
  if (_match_x550) {
    kk_std_num_ddouble__ddouble y_10420;
    kk_std_num_ddouble__ddouble _x_x1801 = kk_std_num_ddouble_sqr(rad, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1802 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(3), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    y_10420 = kk_std_num_ddouble__lp__fs__rp_(_x_x1801, _x_x1802, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble s;
    kk_std_num_ddouble__ddouble _x_x1803;
    kk_std_num_ddouble__ddouble _x_x1804;
    double _x_x1805;
    double _x_x1806;
    {
      double _x_0 = y_10420.hi;
      _x_x1806 = _x_0; /*float64*/
    }
    _x_x1805 = (-_x_x1806); /*float64*/
    double _x_x1807;
    double _x_x1808;
    {
      double _x_0_0 = y_10420.lo;
      _x_x1808 = _x_0_0; /*float64*/
    }
    _x_x1807 = (-_x_x1808); /*float64*/
    _x_x1804 = kk_std_num_ddouble__new_Ddouble(_x_x1805, _x_x1807, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1803 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x1804, _ctx); /*std/num/ddouble/ddouble*/
    s = kk_std_num_ddouble__lp__star__rp_(rad, _x_x1803, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble y_0_10423 = kk_std_num_ddouble_sqr(s, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble c;
    kk_std_num_ddouble__ddouble _x_x1809;
    kk_std_num_ddouble__ddouble _x_x1810;
    double _x_x1811;
    double _x_x1812;
    {
      double _x_1 = y_0_10423.hi;
      _x_x1812 = _x_1; /*float64*/
    }
    _x_x1811 = (-_x_x1812); /*float64*/
    double _x_x1813;
    double _x_x1814;
    {
      double _x_0_1 = y_0_10423.lo;
      _x_x1814 = _x_0_1; /*float64*/
    }
    _x_x1813 = (-_x_x1814); /*float64*/
    _x_x1810 = kk_std_num_ddouble__new_Ddouble(_x_x1811, _x_x1813, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1809 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x1810, _ctx); /*std/num/ddouble/ddouble*/
    c = kk_std_num_ddouble_sqrt(_x_x1809, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(s, _ctx), kk_std_num_ddouble__ddouble_box(c, _ctx), _ctx);
  }
  {
    kk_std_num_ddouble__ddouble x1 = kk_std_num_ddouble__lp__fs__rp_(rad, kk_std_num_ddouble_dd_twopi, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble y_1_10425 = kk_std_num_ddouble_round(x1, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble x3;
    kk_std_num_ddouble__ddouble _x_x1815;
    double _x_x1816;
    double _x_x1817;
    {
      double _x_2 = y_1_10425.hi;
      _x_x1817 = _x_2; /*float64*/
    }
    _x_x1816 = (-_x_x1817); /*float64*/
    double _x_x1818;
    double _x_x1819;
    {
      double _x_0_2 = y_1_10425.lo;
      _x_x1819 = _x_0_2; /*float64*/
    }
    _x_x1818 = (-_x_x1819); /*float64*/
    _x_x1815 = kk_std_num_ddouble__new_Ddouble(_x_x1816, _x_x1818, _ctx); /*std/num/ddouble/ddouble*/
    x3 = kk_std_num_ddouble__lp__plus__rp_(x1, _x_x1815, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble x32 = kk_std_num_ddouble__lp__plus__rp_(x3, x3, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble x34 = kk_std_num_ddouble__lp__plus__rp_(x32, x32, _ctx); /*std/num/ddouble/ddouble*/;
    bool b_10428;
    bool _match_x563;
    double _x_x1820;
    {
      double _x_3 = x34.hi;
      _x_x1820 = _x_3; /*float64*/
    }
    _match_x563 = isfinite(_x_x1820); /*bool*/
    if (_match_x563) {
      double _x_x1821;
      {
        double _x_0_3 = x34.lo;
        _x_x1821 = _x_0_3; /*float64*/
      }
      b_10428 = isfinite(_x_x1821); /*bool*/
    }
    else {
      b_10428 = false; /*bool*/
    }
    kk_integer_t a;
    if (b_10428) {
      kk_std_num_decimal__decimal _x_x1822;
      kk_std_num_ddouble__ddouble _x_x1823 = kk_std_num_ddouble_round(x34, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1822 = kk_std_num_ddouble_decimal(_x_x1823, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
      a = kk_std_num_decimal_int(_x_x1822, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
    }
    else {
      kk_std_core_types__optional _match_x562 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x562, _ctx)) {
        kk_box_t _box_x464 = _match_x562._cons._Optional.value;
        kk_integer_t _uniq_nonfin_4504 = kk_integer_unbox(_box_x464, _ctx);
        kk_integer_dup(_uniq_nonfin_4504, _ctx);
        kk_std_core_types__optional_drop(_match_x562, _ctx);
        a = _uniq_nonfin_4504; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x562, _ctx);
        a = kk_integer_from_small(0); /*int*/
      }
    }
    kk_std_num_ddouble__ddouble y_2_10433;
    kk_integer_t _x_x1824 = kk_integer_dup(a, _ctx); /*int*/
    y_2_10433 = kk_std_num_ddouble_ddouble_int_exp(_x_x1824, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble x_3_10429;
    kk_std_num_ddouble__ddouble _x_x1825 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(8), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1826;
    kk_std_num_ddouble__ddouble _x_x1827;
    double _x_x1828;
    double _x_x1829;
    {
      double _x_4 = y_2_10433.hi;
      _x_x1829 = _x_4; /*float64*/
    }
    _x_x1828 = (-_x_x1829); /*float64*/
    double _x_x1830;
    double _x_x1831;
    {
      double _x_0_4 = y_2_10433.lo;
      _x_x1831 = _x_0_4; /*float64*/
    }
    _x_x1830 = (-_x_x1831); /*float64*/
    _x_x1827 = kk_std_num_ddouble__new_Ddouble(_x_x1828, _x_x1830, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1826 = kk_std_num_ddouble__lp__plus__rp_(x34, _x_x1827, _ctx); /*std/num/ddouble/ddouble*/
    x_3_10429 = kk_std_num_ddouble__lp__star__rp_(_x_x1825, _x_x1826, _ctx); /*std/num/ddouble/ddouble*/
    bool b_0_10435;
    bool _match_x561;
    double _x_x1832;
    {
      double _x_5 = x_3_10429.hi;
      _x_x1832 = _x_5; /*float64*/
    }
    _match_x561 = isfinite(_x_x1832); /*bool*/
    if (_match_x561) {
      double _x_x1833;
      {
        double _x_0_5 = x_3_10429.lo;
        _x_x1833 = _x_0_5; /*float64*/
      }
      b_0_10435 = isfinite(_x_x1833); /*bool*/
    }
    else {
      b_0_10435 = false; /*bool*/
    }
    kk_integer_t b_1;
    if (b_0_10435) {
      kk_std_num_decimal__decimal _x_x1834;
      kk_std_num_ddouble__ddouble _x_x1835 = kk_std_num_ddouble_round(x_3_10429, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1834 = kk_std_num_ddouble_decimal(_x_x1835, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
      b_1 = kk_std_num_decimal_int(_x_x1834, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
    }
    else {
      kk_std_core_types__optional _match_x560 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x560, _ctx)) {
        kk_box_t _box_x465 = _match_x560._cons._Optional.value;
        kk_integer_t _uniq_nonfin_4504_0 = kk_integer_unbox(_box_x465, _ctx);
        kk_integer_dup(_uniq_nonfin_4504_0, _ctx);
        kk_std_core_types__optional_drop(_match_x560, _ctx);
        b_1 = _uniq_nonfin_4504_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x560, _ctx);
        b_1 = kk_integer_from_small(0); /*int*/
      }
    }
    kk_integer_t x_6_10439;
    kk_integer_t _x_x1836 = kk_integer_dup(a, _ctx); /*int*/
    x_6_10439 = kk_integer_mul((kk_integer_from_small(8)),_x_x1836,kk_context()); /*int*/
    kk_integer_t i_2_10438;
    kk_integer_t _x_x1837 = kk_integer_dup(b_1, _ctx); /*int*/
    i_2_10438 = kk_integer_add(x_6_10439,_x_x1837,kk_context()); /*int*/
    kk_std_num_ddouble__ddouble y_3_10437;
    kk_std_num_ddouble__ddouble _x_x1838 = kk_std_num_ddouble_ddouble_int_exp(i_2_10438, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1839 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(16), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    y_3_10437 = kk_std_num_ddouble__lp__fs__rp_(_x_x1838, _x_x1839, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble s_0;
    kk_std_num_ddouble__ddouble _x_x1840;
    kk_std_num_ddouble__ddouble _x_x1841;
    double _x_x1842;
    double _x_x1843;
    {
      double _x_6 = y_3_10437.hi;
      _x_x1843 = _x_6; /*float64*/
    }
    _x_x1842 = (-_x_x1843); /*float64*/
    double _x_x1844;
    double _x_x1845;
    {
      double _x_0_6 = y_3_10437.lo;
      _x_x1845 = _x_0_6; /*float64*/
    }
    _x_x1844 = (-_x_x1845); /*float64*/
    _x_x1841 = kk_std_num_ddouble__new_Ddouble(_x_x1842, _x_x1844, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1840 = kk_std_num_ddouble__lp__plus__rp_(x32, _x_x1841, _ctx); /*std/num/ddouble/ddouble*/
    s_0 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_dd_pi, _x_x1840, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble s2 = kk_std_num_ddouble_sqr(s_0, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble sins;
    kk_std_num_ddouble__ddouble _x_x1846;
    kk_box_t _x_x1847;
    kk_std_core_types__list _x_x1848 = kk_std_core_types__list_dup(kk_std_num_ddouble_ch_factors, _ctx); /*list<std/num/ddouble/ddouble>*/
    _x_x1847 = kk_std_core_list_foldl(_x_x1848, kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx), kk_std_num_ddouble_new_sincos_fun1849(s2, _ctx), _ctx); /*10002*/
    _x_x1846 = kk_std_num_ddouble__ddouble_unbox(_x_x1847, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    sins = kk_std_num_ddouble__lp__star__rp_(s_0, _x_x1846, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble y_5_10443 = kk_std_num_ddouble_sqr(sins, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble coss;
    kk_std_num_ddouble__ddouble _x_x1854;
    kk_std_num_ddouble__ddouble _x_x1855;
    double _x_x1856;
    double _x_x1857;
    {
      double _x_7 = y_5_10443.hi;
      _x_x1857 = _x_7; /*float64*/
    }
    _x_x1856 = (-_x_x1857); /*float64*/
    double _x_x1858;
    double _x_x1859;
    {
      double _x_0_7 = y_5_10443.lo;
      _x_x1859 = _x_0_7; /*float64*/
    }
    _x_x1858 = (-_x_x1859); /*float64*/
    _x_x1855 = kk_std_num_ddouble__new_Ddouble(_x_x1856, _x_x1858, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1854 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x1855, _ctx); /*std/num/ddouble/ddouble*/
    coss = kk_std_num_ddouble_sqrt(_x_x1854, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble sinb;
    bool _match_x556 = kk_integer_gte_borrow(b_1,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x556) {
      kk_std_core_types__maybe m_10445 = kk_std_core_vector_at(kk_std_num_ddouble_sin16_table, b_1, _ctx); /*maybe<std/num/ddouble/ddouble>*/;
      if (kk_std_core_types__is_Nothing(m_10445, _ctx)) {
        sinb = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x476 = m_10445._cons.Just.value;
        kk_std_num_ddouble__ddouble x_8 = kk_std_num_ddouble__ddouble_unbox(_box_x476, KK_BORROWED, _ctx);
        kk_std_core_types__maybe_drop(m_10445, _ctx);
        sinb = x_8; /*std/num/ddouble/ddouble*/
      }
    }
    else {
      kk_integer_t i_5_10448;
      kk_integer_t _x_x1860 = kk_integer_dup(b_1, _ctx); /*int*/
      i_5_10448 = kk_integer_neg(_x_x1860,kk_context()); /*int*/
      kk_std_core_types__maybe m_0_10449;
      kk_std_core_types__maybe _brw_x559 = kk_std_core_vector_at(kk_std_num_ddouble_sin16_table, i_5_10448, _ctx); /*maybe<10000>*/;
      kk_integer_drop(i_5_10448, _ctx);
      m_0_10449 = _brw_x559; /*maybe<std/num/ddouble/ddouble>*/
      double _x_x1861;
      double _x_x1862;
      kk_std_num_ddouble__ddouble _match_x558;
      if (kk_std_core_types__is_Nothing(m_0_10449, _ctx)) {
        _match_x558 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x477 = m_0_10449._cons.Just.value;
        kk_std_num_ddouble__ddouble x_10 = kk_std_num_ddouble__ddouble_unbox(_box_x477, KK_BORROWED, _ctx);
        _match_x558 = x_10; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_0_8 = _match_x558.hi;
        _x_x1862 = _x_0_8; /*float64*/
      }
      _x_x1861 = (-_x_x1862); /*float64*/
      double _x_x1863;
      double _x_x1864;
      kk_std_num_ddouble__ddouble _match_x557;
      if (kk_std_core_types__is_Nothing(m_0_10449, _ctx)) {
        _match_x557 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x478 = m_0_10449._cons.Just.value;
        kk_std_num_ddouble__ddouble x_10_0 = kk_std_num_ddouble__ddouble_unbox(_box_x478, KK_BORROWED, _ctx);
        kk_std_core_types__maybe_drop(m_0_10449, _ctx);
        _match_x557 = x_10_0; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_1_0 = _match_x557.lo;
        _x_x1864 = _x_1_0; /*float64*/
      }
      _x_x1863 = (-_x_x1864); /*float64*/
      sinb = kk_std_num_ddouble__new_Ddouble(_x_x1861, _x_x1863, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_integer_t y_6_10455 = kk_integer_abs(b_1,kk_context()); /*int*/;
    kk_integer_t i_6_10453 = kk_integer_sub((kk_integer_from_small(8)),y_6_10455,kk_context()); /*int*/;
    kk_std_core_types__maybe m_1_10456;
    kk_std_core_types__maybe _brw_x555 = kk_std_core_vector_at(kk_std_num_ddouble_sin16_table, i_6_10453, _ctx); /*maybe<10000>*/;
    kk_integer_drop(i_6_10453, _ctx);
    m_1_10456 = _brw_x555; /*maybe<std/num/ddouble/ddouble>*/
    bool _match_x551 = kk_integer_eq_borrow(a,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x551) {
      kk_integer_drop(a, _ctx);
      kk_std_num_ddouble__ddouble x_13_10458;
      kk_std_num_ddouble__ddouble _x_x1865;
      if (kk_std_core_types__is_Nothing(m_1_10456, _ctx)) {
        _x_x1865 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x479 = m_1_10456._cons.Just.value;
        kk_std_num_ddouble__ddouble x_11 = kk_std_num_ddouble__ddouble_unbox(_box_x479, KK_BORROWED, _ctx);
        _x_x1865 = x_11; /*std/num/ddouble/ddouble*/
      }
      x_13_10458 = kk_std_num_ddouble__lp__star__rp_(coss, _x_x1865, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble y_7_10459 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _b_x481_497;
      kk_std_num_ddouble__ddouble _x_x1866;
      kk_std_num_ddouble__ddouble _x_x1867;
      if (kk_std_core_types__is_Nothing(m_1_10456, _ctx)) {
        _x_x1867 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x480 = m_1_10456._cons.Just.value;
        kk_std_num_ddouble__ddouble x_11_0 = kk_std_num_ddouble__ddouble_unbox(_box_x480, KK_BORROWED, _ctx);
        kk_std_core_types__maybe_drop(m_1_10456, _ctx);
        _x_x1867 = x_11_0; /*std/num/ddouble/ddouble*/
      }
      _x_x1866 = kk_std_num_ddouble__lp__star__rp_(sins, _x_x1867, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1868 = kk_std_num_ddouble__lp__star__rp_(coss, sinb, _ctx); /*std/num/ddouble/ddouble*/
      _b_x481_497 = kk_std_num_ddouble__lp__plus__rp_(_x_x1866, _x_x1868, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _b_x482_498;
      kk_std_num_ddouble__ddouble _x_x1869;
      double _x_x1870;
      double _x_x1871;
      {
        double _x_8 = y_7_10459.hi;
        _x_x1871 = _x_8; /*float64*/
      }
      _x_x1870 = (-_x_x1871); /*float64*/
      double _x_x1872;
      double _x_x1873;
      {
        double _x_0_9 = y_7_10459.lo;
        _x_x1873 = _x_0_9; /*float64*/
      }
      _x_x1872 = (-_x_x1873); /*float64*/
      _x_x1869 = kk_std_num_ddouble__new_Ddouble(_x_x1870, _x_x1872, _ctx); /*std/num/ddouble/ddouble*/
      _b_x482_498 = kk_std_num_ddouble__lp__plus__rp_(x_13_10458, _x_x1869, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(_b_x481_497, _ctx), kk_std_num_ddouble__ddouble_box(_b_x482_498, _ctx), _ctx);
    }
    {
      bool _match_x552 = kk_integer_eq_borrow(a,(kk_integer_from_small(1)),kk_context()); /*bool*/;
      if (_match_x552) {
        kk_integer_drop(a, _ctx);
        kk_std_num_ddouble__ddouble x_14_10460;
        kk_std_num_ddouble__ddouble _x_x1874;
        if (kk_std_core_types__is_Nothing(m_1_10456, _ctx)) {
          _x_x1874 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_box_t _box_x483 = m_1_10456._cons.Just.value;
          kk_std_num_ddouble__ddouble x_11_1 = kk_std_num_ddouble__ddouble_unbox(_box_x483, KK_BORROWED, _ctx);
          _x_x1874 = x_11_1; /*std/num/ddouble/ddouble*/
        }
        x_14_10460 = kk_std_num_ddouble__lp__star__rp_(coss, _x_x1874, _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble y_8_10461 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble x_15_10462;
        kk_std_num_ddouble__ddouble _x_x1875;
        double _x_x1876;
        double _x_x1877;
        {
          double _x_9 = coss.hi;
          _x_x1877 = _x_9; /*float64*/
        }
        _x_x1876 = (-_x_x1877); /*float64*/
        double _x_x1878;
        double _x_x1879;
        {
          double _x_0_10 = coss.lo;
          _x_x1879 = _x_0_10; /*float64*/
        }
        _x_x1878 = (-_x_x1879); /*float64*/
        _x_x1875 = kk_std_num_ddouble__new_Ddouble(_x_x1876, _x_x1878, _ctx); /*std/num/ddouble/ddouble*/
        x_15_10462 = kk_std_num_ddouble__lp__star__rp_(_x_x1875, sinb, _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble y_9_10463;
        kk_std_num_ddouble__ddouble _x_x1880;
        if (kk_std_core_types__is_Nothing(m_1_10456, _ctx)) {
          _x_x1880 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_box_t _box_x484 = m_1_10456._cons.Just.value;
          kk_std_num_ddouble__ddouble x_11_2 = kk_std_num_ddouble__ddouble_unbox(_box_x484, KK_BORROWED, _ctx);
          kk_std_core_types__maybe_drop(m_1_10456, _ctx);
          _x_x1880 = x_11_2; /*std/num/ddouble/ddouble*/
        }
        y_9_10463 = kk_std_num_ddouble__lp__star__rp_(sins, _x_x1880, _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble _b_x485_499;
        kk_std_num_ddouble__ddouble _x_x1881;
        double _x_x1882;
        double _x_x1883;
        {
          double _x_10 = y_8_10461.hi;
          _x_x1883 = _x_10; /*float64*/
        }
        _x_x1882 = (-_x_x1883); /*float64*/
        double _x_x1884;
        double _x_x1885;
        {
          double _x_0_11 = y_8_10461.lo;
          _x_x1885 = _x_0_11; /*float64*/
        }
        _x_x1884 = (-_x_x1885); /*float64*/
        _x_x1881 = kk_std_num_ddouble__new_Ddouble(_x_x1882, _x_x1884, _ctx); /*std/num/ddouble/ddouble*/
        _b_x485_499 = kk_std_num_ddouble__lp__plus__rp_(x_14_10460, _x_x1881, _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble _b_x486_500;
        kk_std_num_ddouble__ddouble _x_x1886;
        double _x_x1887;
        double _x_x1888;
        {
          double _x_11 = y_9_10463.hi;
          _x_x1888 = _x_11; /*float64*/
        }
        _x_x1887 = (-_x_x1888); /*float64*/
        double _x_x1889;
        double _x_x1890;
        {
          double _x_0_12 = y_9_10463.lo;
          _x_x1890 = _x_0_12; /*float64*/
        }
        _x_x1889 = (-_x_x1890); /*float64*/
        _x_x1886 = kk_std_num_ddouble__new_Ddouble(_x_x1887, _x_x1889, _ctx); /*std/num/ddouble/ddouble*/
        _b_x486_500 = kk_std_num_ddouble__lp__plus__rp_(x_15_10462, _x_x1886, _ctx); /*std/num/ddouble/ddouble*/
        return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(_b_x485_499, _ctx), kk_std_num_ddouble__ddouble_box(_b_x486_500, _ctx), _ctx);
      }
      {
        bool _match_x553;
        bool _brw_x554 = kk_integer_eq_borrow(a,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
        kk_integer_drop(a, _ctx);
        _match_x553 = _brw_x554; /*bool*/
        if (_match_x553) {
          kk_std_num_ddouble__ddouble x_16_10464 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble y_10_10465;
          kk_std_num_ddouble__ddouble _x_x1891;
          if (kk_std_core_types__is_Nothing(m_1_10456, _ctx)) {
            _x_x1891 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x487 = m_1_10456._cons.Just.value;
            kk_std_num_ddouble__ddouble x_11_3 = kk_std_num_ddouble__ddouble_unbox(_box_x487, KK_BORROWED, _ctx);
            _x_x1891 = x_11_3; /*std/num/ddouble/ddouble*/
          }
          y_10_10465 = kk_std_num_ddouble__lp__star__rp_(coss, _x_x1891, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _b_x489_501;
          kk_std_num_ddouble__ddouble _x_x1892;
          double _x_x1893;
          double _x_x1894;
          {
            double _x_12 = y_10_10465.hi;
            _x_x1894 = _x_12; /*float64*/
          }
          _x_x1893 = (-_x_x1894); /*float64*/
          double _x_x1895;
          double _x_x1896;
          {
            double _x_0_13 = y_10_10465.lo;
            _x_x1896 = _x_0_13; /*float64*/
          }
          _x_x1895 = (-_x_x1896); /*float64*/
          _x_x1892 = kk_std_num_ddouble__new_Ddouble(_x_x1893, _x_x1895, _ctx); /*std/num/ddouble/ddouble*/
          _b_x489_501 = kk_std_num_ddouble__lp__plus__rp_(x_16_10464, _x_x1892, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _b_x490_502;
          kk_std_num_ddouble__ddouble _x_x1897 = kk_std_num_ddouble__lp__star__rp_(coss, sinb, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x1898;
          kk_std_num_ddouble__ddouble _x_x1899;
          if (kk_std_core_types__is_Nothing(m_1_10456, _ctx)) {
            _x_x1899 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x488 = m_1_10456._cons.Just.value;
            kk_std_num_ddouble__ddouble x_11_4 = kk_std_num_ddouble__ddouble_unbox(_box_x488, KK_BORROWED, _ctx);
            kk_std_core_types__maybe_drop(m_1_10456, _ctx);
            _x_x1899 = x_11_4; /*std/num/ddouble/ddouble*/
          }
          _x_x1898 = kk_std_num_ddouble__lp__star__rp_(sins, _x_x1899, _ctx); /*std/num/ddouble/ddouble*/
          _b_x490_502 = kk_std_num_ddouble__lp__plus__rp_(_x_x1897, _x_x1898, _ctx); /*std/num/ddouble/ddouble*/
          return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(_b_x489_501, _ctx), kk_std_num_ddouble__ddouble_box(_b_x490_502, _ctx), _ctx);
        }
        {
          kk_std_num_ddouble__ddouble x_17_10466;
          kk_std_num_ddouble__ddouble _x_x1900;
          double _x_x1901;
          double _x_x1902;
          {
            double _x_13 = sins.hi;
            _x_x1902 = _x_13; /*float64*/
          }
          _x_x1901 = (-_x_x1902); /*float64*/
          double _x_x1903;
          double _x_x1904;
          {
            double _x_0_14 = sins.lo;
            _x_x1904 = _x_0_14; /*float64*/
          }
          _x_x1903 = (-_x_x1904); /*float64*/
          _x_x1900 = kk_std_num_ddouble__new_Ddouble(_x_x1901, _x_x1903, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x1905;
          if (kk_std_core_types__is_Nothing(m_1_10456, _ctx)) {
            _x_x1905 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x491 = m_1_10456._cons.Just.value;
            kk_std_num_ddouble__ddouble x_11_5 = kk_std_num_ddouble__ddouble_unbox(_box_x491, KK_BORROWED, _ctx);
            _x_x1905 = x_11_5; /*std/num/ddouble/ddouble*/
          }
          x_17_10466 = kk_std_num_ddouble__lp__star__rp_(_x_x1900, _x_x1905, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble y_11_10467 = kk_std_num_ddouble__lp__star__rp_(coss, sinb, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble x_18_10468 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble y_12_10469;
          kk_std_num_ddouble__ddouble _x_x1906;
          if (kk_std_core_types__is_Nothing(m_1_10456, _ctx)) {
            _x_x1906 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x492 = m_1_10456._cons.Just.value;
            kk_std_num_ddouble__ddouble x_11_6 = kk_std_num_ddouble__ddouble_unbox(_box_x492, KK_BORROWED, _ctx);
            kk_std_core_types__maybe_drop(m_1_10456, _ctx);
            _x_x1906 = x_11_6; /*std/num/ddouble/ddouble*/
          }
          y_12_10469 = kk_std_num_ddouble__lp__star__rp_(coss, _x_x1906, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _b_x493_503;
          kk_std_num_ddouble__ddouble _x_x1907;
          double _x_x1908;
          double _x_x1909;
          {
            double _x_14 = y_11_10467.hi;
            _x_x1909 = _x_14; /*float64*/
          }
          _x_x1908 = (-_x_x1909); /*float64*/
          double _x_x1910;
          double _x_x1911;
          {
            double _x_0_15 = y_11_10467.lo;
            _x_x1911 = _x_0_15; /*float64*/
          }
          _x_x1910 = (-_x_x1911); /*float64*/
          _x_x1907 = kk_std_num_ddouble__new_Ddouble(_x_x1908, _x_x1910, _ctx); /*std/num/ddouble/ddouble*/
          _b_x493_503 = kk_std_num_ddouble__lp__plus__rp_(x_17_10466, _x_x1907, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _b_x494_504;
          kk_std_num_ddouble__ddouble _x_x1912;
          double _x_x1913;
          double _x_x1914;
          {
            double _x_15 = y_12_10469.hi;
            _x_x1914 = _x_15; /*float64*/
          }
          _x_x1913 = (-_x_x1914); /*float64*/
          double _x_x1915;
          double _x_x1916;
          {
            double _x_0_16 = y_12_10469.lo;
            _x_x1916 = _x_0_16; /*float64*/
          }
          _x_x1915 = (-_x_x1916); /*float64*/
          _x_x1912 = kk_std_num_ddouble__new_Ddouble(_x_x1913, _x_x1915, _ctx); /*std/num/ddouble/ddouble*/
          _b_x494_504 = kk_std_num_ddouble__lp__plus__rp_(x_18_10468, _x_x1912, _ctx); /*std/num/ddouble/ddouble*/
          return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(_b_x493_503, _ctx), kk_std_num_ddouble__ddouble_box(_b_x494_504, _ctx), _ctx);
        }
      }
    }
  }
}
 
// Return `x` with the sign of `y`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_with_sign_of(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_x548;
  double _x_x1917;
  {
    double _x = y.hi;
    _x_x1917 = _x; /*float64*/
  }
  _match_x548 = (_x_x1917 < (0x0p+0)); /*bool*/
  if (_match_x548) {
    kk_std_num_ddouble__ddouble x_1_10475 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
    double _x_x1918;
    double _x_x1919;
    {
      double _x_0 = x_1_10475.hi;
      _x_x1919 = _x_0; /*float64*/
    }
    _x_x1918 = (-_x_x1919); /*float64*/
    double _x_x1920;
    double _x_x1921;
    {
      double _x_1 = x_1_10475.lo;
      _x_x1921 = _x_1; /*float64*/
    }
    _x_x1920 = (-_x_x1921); /*float64*/
    return kk_std_num_ddouble__new_Ddouble(_x_x1918, _x_x1920, _ctx);
  }
  {
    return kk_std_num_ddouble_abs(x, _ctx);
  }
}
 
// The arc-tangent of a point (`x`,`y`). Returns the angle with respect to the x-axis in radians between -&pi; and &pi;.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_atan2(kk_std_num_ddouble__ddouble y, kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (y : ddouble, x : ddouble) -> ddouble */ 
  bool _match_x536;
  double _x_x1922;
  {
    double _x = x.hi;
    _x_x1922 = _x; /*float64*/
  }
  _match_x536 = (_x_x1922 == (0x0p+0)); /*bool*/
  if (_match_x536) {
    bool _match_x547;
    double _x_x1923;
    {
      double _x_0 = y.hi;
      _x_x1923 = _x_0; /*float64*/
    }
    _match_x547 = (_x_x1923 == (0x0p+0)); /*bool*/
    if (_match_x547) {
      return kk_std_num_ddouble_zero;
    }
    {
      return kk_std_num_ddouble_with_sign_of(kk_std_num_ddouble_dd_pi2, y, _ctx);
    }
  }
  {
    bool _match_x537;
    double _x_x1924;
    {
      double _x_1 = y.hi;
      _x_x1924 = _x_1; /*float64*/
    }
    _match_x537 = (_x_x1924 == (0x0p+0)); /*bool*/
    if (_match_x537) {
      bool _match_x546;
      double _x_x1925;
      {
        double _x_2 = x.hi;
        _x_x1925 = _x_2; /*float64*/
      }
      _match_x546 = (_x_x1925 > (0x0p+0)); /*bool*/
      if (_match_x546) {
        return kk_std_num_ddouble_zero;
      }
      {
        return kk_std_num_ddouble_dd_pi;
      }
    }
    {
      bool _match_x538;
      kk_std_core_types__order _x_x1926;
      kk_std_core_types__order _match_x545;
      double _x_x1927;
      {
        double _x_3 = x.hi;
        _x_x1927 = _x_3; /*float64*/
      }
      double _x_x1928;
      {
        double _x_0_0 = y.hi;
        _x_x1928 = _x_0_0; /*float64*/
      }
      _match_x545 = kk_std_num_float64_cmp(_x_x1927, _x_x1928, _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x545, _ctx)) {
        double _x_x1929;
        {
          double _x_1_0 = x.lo;
          _x_x1929 = _x_1_0; /*float64*/
        }
        double _x_x1930;
        {
          double _x_2_0 = y.lo;
          _x_x1930 = _x_2_0; /*float64*/
        }
        _x_x1926 = kk_std_num_float64_cmp(_x_x1929, _x_x1930, _ctx); /*order*/
      }
      else {
        _x_x1926 = _match_x545; /*order*/
      }
      _match_x538 = kk_std_core_order__lp__eq__eq__rp_(_x_x1926, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
      if (_match_x538) {
        bool _match_x544;
        double _x_x1931;
        {
          double _x_3_0 = y.hi;
          _x_x1931 = _x_3_0; /*float64*/
        }
        _match_x544 = (_x_x1931 > (0x0p+0)); /*bool*/
        if (_match_x544) {
          return kk_std_num_ddouble_dd_pi4;
        }
        {
          double _x_x1932;
          double _x_x1933;
          kk_std_num_ddouble__ddouble _x_x1934 = kk_std_num_ddouble_dd_pi34; /*std/num/ddouble/ddouble*/
          {
            double _x_4 = _x_x1934.hi;
            _x_x1933 = _x_4; /*float64*/
          }
          _x_x1932 = (-_x_x1933); /*float64*/
          double _x_x1935;
          double _x_x1936;
          kk_std_num_ddouble__ddouble _x_x1937 = kk_std_num_ddouble_dd_pi34; /*std/num/ddouble/ddouble*/
          {
            double _x_0_1 = _x_x1937.lo;
            _x_x1936 = _x_0_1; /*float64*/
          }
          _x_x1935 = (-_x_x1936); /*float64*/
          return kk_std_num_ddouble__new_Ddouble(_x_x1932, _x_x1935, _ctx);
        }
      }
      {
        kk_std_num_ddouble__ddouble y_1_10496;
        double _x_x1938;
        double _x_x1939;
        {
          double _x_5 = y.hi;
          _x_x1939 = _x_5; /*float64*/
        }
        _x_x1938 = (-_x_x1939); /*float64*/
        double _x_x1940;
        double _x_x1941;
        {
          double _x_0_2 = y.lo;
          _x_x1941 = _x_0_2; /*float64*/
        }
        _x_x1940 = (-_x_x1941); /*float64*/
        y_1_10496 = kk_std_num_ddouble__new_Ddouble(_x_x1938, _x_x1940, _ctx); /*std/num/ddouble/ddouble*/
        bool _match_x539;
        kk_std_core_types__order _x_x1942;
        kk_std_core_types__order _match_x543;
        double _x_x1943;
        {
          double _x_6 = x.hi;
          _x_x1943 = _x_6; /*float64*/
        }
        double _x_x1944;
        {
          double _x_0_3 = y_1_10496.hi;
          _x_x1944 = _x_0_3; /*float64*/
        }
        _match_x543 = kk_std_num_float64_cmp(_x_x1943, _x_x1944, _ctx); /*order*/
        if (kk_std_core_types__is_Eq(_match_x543, _ctx)) {
          double _x_x1945;
          {
            double _x_1_1 = x.lo;
            _x_x1945 = _x_1_1; /*float64*/
          }
          double _x_x1946;
          {
            double _x_2_1 = y_1_10496.lo;
            _x_x1946 = _x_2_1; /*float64*/
          }
          _x_x1942 = kk_std_num_float64_cmp(_x_x1945, _x_x1946, _ctx); /*order*/
        }
        else {
          _x_x1942 = _match_x543; /*order*/
        }
        _match_x539 = kk_std_core_order__lp__eq__eq__rp_(_x_x1942, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
        if (_match_x539) {
          bool _match_x542;
          double _x_x1947;
          {
            double _x_4_0 = y.hi;
            _x_x1947 = _x_4_0; /*float64*/
          }
          _match_x542 = (_x_x1947 > (0x0p+0)); /*bool*/
          if (_match_x542) {
            return kk_std_num_ddouble_dd_pi34;
          }
          {
            double _x_x1948;
            double _x_x1949;
            kk_std_num_ddouble__ddouble _x_x1950 = kk_std_num_ddouble_dd_pi4; /*std/num/ddouble/ddouble*/
            {
              double _x_7 = _x_x1950.hi;
              _x_x1949 = _x_7; /*float64*/
            }
            _x_x1948 = (-_x_x1949); /*float64*/
            double _x_x1951;
            double _x_x1952;
            kk_std_num_ddouble__ddouble _x_x1953 = kk_std_num_ddouble_dd_pi4; /*std/num/ddouble/ddouble*/
            {
              double _x_0_4 = _x_x1953.lo;
              _x_x1952 = _x_0_4; /*float64*/
            }
            _x_x1951 = (-_x_x1952); /*float64*/
            return kk_std_num_ddouble__new_Ddouble(_x_x1948, _x_x1951, _ctx);
          }
        }
        {
          kk_std_num_ddouble__ddouble r;
          kk_std_num_ddouble__ddouble _x_x1954;
          kk_std_num_ddouble__ddouble _x_x1955 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x1956 = kk_std_num_ddouble_sqr(y, _ctx); /*std/num/ddouble/ddouble*/
          _x_x1954 = kk_std_num_ddouble__lp__plus__rp_(_x_x1955, _x_x1956, _ctx); /*std/num/ddouble/ddouble*/
          r = kk_std_num_ddouble_sqrt(_x_x1954, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble xr = kk_std_num_ddouble__lp__fs__rp_(x, r, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble yr = kk_std_num_ddouble__lp__fs__rp_(y, r, _ctx); /*std/num/ddouble/ddouble*/;
          double d_5_10500;
          double _x_x1957;
          {
            double _x_5_0 = y.hi;
            _x_x1957 = _x_5_0; /*float64*/
          }
          double _x_x1958;
          {
            double _x_6_0 = x.hi;
            _x_x1958 = _x_6_0; /*float64*/
          }
          d_5_10500 = atan2(_x_x1957,_x_x1958); /*float64*/
          kk_std_num_ddouble__ddouble z = kk_std_num_ddouble__new_Ddouble(d_5_10500, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_core_types__tuple2 _match_x540 = kk_std_num_ddouble_sincos(z, _ctx); /*(std/num/ddouble/ddouble, std/num/ddouble/ddouble)*/;
          {
            kk_box_t _box_x511 = _match_x540.fst;
            kk_box_t _box_x512 = _match_x540.snd;
            kk_std_num_ddouble__ddouble sinz = kk_std_num_ddouble__ddouble_unbox(_box_x511, KK_BORROWED, _ctx);
            kk_std_num_ddouble__ddouble cosz = kk_std_num_ddouble__ddouble_unbox(_box_x512, KK_BORROWED, _ctx);
            kk_std_core_types__tuple2_drop(_match_x540, _ctx);
            kk_std_num_ddouble__ddouble ddouble_0_8_10506 = kk_std_num_ddouble_abs(yr, _ctx); /*std/num/ddouble/ddouble*/;
            bool _match_x541;
            double _x_x1959;
            double _x_x1960;
            {
              double _x_7_0 = xr.hi;
              _x_x1960 = _x_7_0; /*float64*/
            }
            _x_x1959 = kk_double_abs(_x_x1960); /*float64*/
            double _x_x1961;
            {
              double _x_8 = ddouble_0_8_10506.hi;
              _x_x1961 = _x_8; /*float64*/
            }
            _match_x541 = (_x_x1959 > _x_x1961); /*bool*/
            if (_match_x541) {
              kk_std_num_ddouble__ddouble _x_x1962;
              kk_std_num_ddouble__ddouble _x_x1963;
              kk_std_num_ddouble__ddouble _x_x1964;
              double _x_x1965;
              double _x_x1966;
              {
                double _x_9 = sinz.hi;
                _x_x1966 = _x_9; /*float64*/
              }
              _x_x1965 = (-_x_x1966); /*float64*/
              double _x_x1967;
              double _x_x1968;
              {
                double _x_0_5 = sinz.lo;
                _x_x1968 = _x_0_5; /*float64*/
              }
              _x_x1967 = (-_x_x1968); /*float64*/
              _x_x1964 = kk_std_num_ddouble__new_Ddouble(_x_x1965, _x_x1967, _ctx); /*std/num/ddouble/ddouble*/
              _x_x1963 = kk_std_num_ddouble__lp__plus__rp_(yr, _x_x1964, _ctx); /*std/num/ddouble/ddouble*/
              _x_x1962 = kk_std_num_ddouble__lp__fs__rp_(_x_x1963, cosz, _ctx); /*std/num/ddouble/ddouble*/
              return kk_std_num_ddouble__lp__plus__rp_(z, _x_x1962, _ctx);
            }
            {
              kk_std_num_ddouble__ddouble y_3_10510;
              kk_std_num_ddouble__ddouble _x_x1969;
              kk_std_num_ddouble__ddouble _x_x1970;
              double _x_x1971;
              double _x_x1972;
              {
                double _x_10 = cosz.hi;
                _x_x1972 = _x_10; /*float64*/
              }
              _x_x1971 = (-_x_x1972); /*float64*/
              double _x_x1973;
              double _x_x1974;
              {
                double _x_0_6 = cosz.lo;
                _x_x1974 = _x_0_6; /*float64*/
              }
              _x_x1973 = (-_x_x1974); /*float64*/
              _x_x1970 = kk_std_num_ddouble__new_Ddouble(_x_x1971, _x_x1973, _ctx); /*std/num/ddouble/ddouble*/
              _x_x1969 = kk_std_num_ddouble__lp__plus__rp_(xr, _x_x1970, _ctx); /*std/num/ddouble/ddouble*/
              y_3_10510 = kk_std_num_ddouble__lp__fs__rp_(_x_x1969, sinz, _ctx); /*std/num/ddouble/ddouble*/
              kk_std_num_ddouble__ddouble _x_x1975;
              double _x_x1976;
              double _x_x1977;
              {
                double _x_11 = y_3_10510.hi;
                _x_x1977 = _x_11; /*float64*/
              }
              _x_x1976 = (-_x_x1977); /*float64*/
              double _x_x1978;
              double _x_x1979;
              {
                double _x_0_7 = y_3_10510.lo;
                _x_x1979 = _x_0_7; /*float64*/
              }
              _x_x1978 = (-_x_x1979); /*float64*/
              _x_x1975 = kk_std_num_ddouble__new_Ddouble(_x_x1976, _x_x1978, _ctx); /*std/num/ddouble/ddouble*/
              return kk_std_num_ddouble__lp__plus__rp_(z, _x_x1975, _ctx);
            }
          }
        }
      }
    }
  }
}
 
// The arc-sine of `x`. Returns the angle in radians.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_asin(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble a = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x532;
  kk_std_core_types__order _x_x1980;
  kk_std_core_types__order _match_x535;
  double _x_x1981;
  {
    double _x = a.hi;
    _x_x1981 = _x; /*float64*/
  }
  double _x_x1982;
  kk_std_num_ddouble__ddouble _x_x1983 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
  {
    double _x_0 = _x_x1983.hi;
    _x_x1982 = _x_0; /*float64*/
  }
  _match_x535 = kk_std_num_float64_cmp(_x_x1981, _x_x1982, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x535, _ctx)) {
    double _x_x1984;
    {
      double _x_1 = a.lo;
      _x_x1984 = _x_1; /*float64*/
    }
    double _x_x1985;
    kk_std_num_ddouble__ddouble _x_x1986 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_2 = _x_x1986.lo;
      _x_x1985 = _x_2; /*float64*/
    }
    _x_x1980 = kk_std_num_float64_cmp(_x_x1984, _x_x1985, _ctx); /*order*/
  }
  else {
    _x_x1980 = _match_x535; /*order*/
  }
  _match_x532 = kk_std_core_order__lp__eq__eq__rp_(_x_x1980, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
  if (_match_x532) {
    return kk_std_num_ddouble_dd_nan;
  }
  {
    bool _match_x533;
    kk_std_core_types__order _x_x1987;
    kk_std_core_types__order _match_x534;
    double _x_x1988;
    {
      double _x_3 = a.hi;
      _x_x1988 = _x_3; /*float64*/
    }
    double _x_x1989;
    kk_std_num_ddouble__ddouble _x_x1990 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_0_0 = _x_x1990.hi;
      _x_x1989 = _x_0_0; /*float64*/
    }
    _match_x534 = kk_std_num_float64_cmp(_x_x1988, _x_x1989, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x534, _ctx)) {
      double _x_x1991;
      {
        double _x_1_0 = a.lo;
        _x_x1991 = _x_1_0; /*float64*/
      }
      double _x_x1992;
      kk_std_num_ddouble__ddouble _x_x1993 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_2_0 = _x_x1993.lo;
        _x_x1992 = _x_2_0; /*float64*/
      }
      _x_x1987 = kk_std_num_float64_cmp(_x_x1991, _x_x1992, _ctx); /*order*/
    }
    else {
      _x_x1987 = _match_x534; /*order*/
    }
    _match_x533 = kk_std_core_order__lp__eq__eq__rp_(_x_x1987, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
    if (_match_x533) {
      return kk_std_num_ddouble_with_sign_of(kk_std_num_ddouble_dd_pi2, x, _ctx);
    }
    {
      kk_std_num_ddouble__ddouble y_1_10518 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x_x1994;
      kk_std_num_ddouble__ddouble _x_x1995;
      kk_std_num_ddouble__ddouble _x_x1996;
      double _x_x1997;
      double _x_x1998;
      {
        double _x_4 = y_1_10518.hi;
        _x_x1998 = _x_4; /*float64*/
      }
      _x_x1997 = (-_x_x1998); /*float64*/
      double _x_x1999;
      double _x_x2000;
      {
        double _x_0_1 = y_1_10518.lo;
        _x_x2000 = _x_0_1; /*float64*/
      }
      _x_x1999 = (-_x_x2000); /*float64*/
      _x_x1996 = kk_std_num_ddouble__new_Ddouble(_x_x1997, _x_x1999, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1995 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x1996, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1994 = kk_std_num_ddouble_sqrt(_x_x1995, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble_atan2(x, _x_x1994, _ctx);
    }
  }
}
 
// The arc-cosine of `x`. Returns the angle in radians.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_acos(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble a = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x527;
  kk_std_core_types__order _x_x2001;
  kk_std_core_types__order _match_x531;
  double _x_x2002;
  {
    double _x = a.hi;
    _x_x2002 = _x; /*float64*/
  }
  double _x_x2003;
  kk_std_num_ddouble__ddouble _x_x2004 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
  {
    double _x_0 = _x_x2004.hi;
    _x_x2003 = _x_0; /*float64*/
  }
  _match_x531 = kk_std_num_float64_cmp(_x_x2002, _x_x2003, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x531, _ctx)) {
    double _x_x2005;
    {
      double _x_1 = a.lo;
      _x_x2005 = _x_1; /*float64*/
    }
    double _x_x2006;
    kk_std_num_ddouble__ddouble _x_x2007 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_2 = _x_x2007.lo;
      _x_x2006 = _x_2; /*float64*/
    }
    _x_x2001 = kk_std_num_float64_cmp(_x_x2005, _x_x2006, _ctx); /*order*/
  }
  else {
    _x_x2001 = _match_x531; /*order*/
  }
  _match_x527 = kk_std_core_order__lp__eq__eq__rp_(_x_x2001, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
  if (_match_x527) {
    return kk_std_num_ddouble_dd_nan;
  }
  {
    bool _match_x528;
    kk_std_core_types__order _x_x2008;
    kk_std_core_types__order _match_x530;
    double _x_x2009;
    {
      double _x_3 = a.hi;
      _x_x2009 = _x_3; /*float64*/
    }
    double _x_x2010;
    kk_std_num_ddouble__ddouble _x_x2011 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_0_0 = _x_x2011.hi;
      _x_x2010 = _x_0_0; /*float64*/
    }
    _match_x530 = kk_std_num_float64_cmp(_x_x2009, _x_x2010, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x530, _ctx)) {
      double _x_x2012;
      {
        double _x_1_0 = a.lo;
        _x_x2012 = _x_1_0; /*float64*/
      }
      double _x_x2013;
      kk_std_num_ddouble__ddouble _x_x2014 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_2_0 = _x_x2014.lo;
        _x_x2013 = _x_2_0; /*float64*/
      }
      _x_x2008 = kk_std_num_float64_cmp(_x_x2012, _x_x2013, _ctx); /*order*/
    }
    else {
      _x_x2008 = _match_x530; /*order*/
    }
    _match_x528 = kk_std_core_order__lp__eq__eq__rp_(_x_x2008, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
    if (_match_x528) {
      bool _match_x529;
      double _x_x2015;
      {
        double _x_4 = x.hi;
        _x_x2015 = _x_4; /*float64*/
      }
      _match_x529 = (_x_x2015 > (0x0p+0)); /*bool*/
      if (_match_x529) {
        return kk_std_num_ddouble_zero;
      }
      {
        return kk_std_num_ddouble_dd_pi;
      }
    }
    {
      kk_std_num_ddouble__ddouble y_1_10527 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x_x2016;
      kk_std_num_ddouble__ddouble _x_x2017;
      kk_std_num_ddouble__ddouble _x_x2018;
      double _x_x2019;
      double _x_x2020;
      {
        double _x_5 = y_1_10527.hi;
        _x_x2020 = _x_5; /*float64*/
      }
      _x_x2019 = (-_x_x2020); /*float64*/
      double _x_x2021;
      double _x_x2022;
      {
        double _x_0_1 = y_1_10527.lo;
        _x_x2022 = _x_0_1; /*float64*/
      }
      _x_x2021 = (-_x_x2022); /*float64*/
      _x_x2018 = kk_std_num_ddouble__new_Ddouble(_x_x2019, _x_x2021, _ctx); /*std/num/ddouble/ddouble*/
      _x_x2017 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2018, _ctx); /*std/num/ddouble/ddouble*/
      _x_x2016 = kk_std_num_ddouble_sqrt(_x_x2017, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble_atan2(_x_x2016, x, _ctx);
    }
  }
}
 
// The hyperbolic sine of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sinh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x524;
  double _x_x2023;
  {
    double _x = x.hi;
    _x_x2023 = _x; /*float64*/
  }
  _match_x524 = (_x_x2023 == (0x0p+0)); /*bool*/
  if (_match_x524) {
    return kk_std_num_ddouble_zero;
  }
  {
    kk_std_num_ddouble__ddouble x_1_10531 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_x525;
    double _x_x2024;
    {
      double _x_0 = x_1_10531.hi;
      _x_x2024 = _x_0; /*float64*/
    }
    _match_x525 = (_x_x2024 > (0x1.999999999999ap-5)); /*bool*/
    if (_match_x525) {
      kk_std_num_ddouble__ddouble ex = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
      bool b_10533;
      bool _match_x526;
      double _x_x2025;
      {
        double _x_1 = ex.hi;
        _x_x2025 = _x_1; /*float64*/
      }
      _match_x526 = isfinite(_x_x2025); /*bool*/
      if (_match_x526) {
        double _x_x2026;
        {
          double _x_0_0 = ex.lo;
          _x_x2026 = _x_0_0; /*float64*/
        }
        b_10533 = isfinite(_x_x2026); /*bool*/
      }
      else {
        b_10533 = false; /*bool*/
      }
      if (b_10533) {
        kk_std_num_ddouble__ddouble y_10536 = kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble_one, ex, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble x_2_10534;
        kk_std_num_ddouble__ddouble _x_x2027;
        double _x_x2028;
        double _x_x2029;
        {
          double _x_2 = y_10536.hi;
          _x_x2029 = _x_2; /*float64*/
        }
        _x_x2028 = (-_x_x2029); /*float64*/
        double _x_x2030;
        double _x_x2031;
        {
          double _x_0_1 = y_10536.lo;
          _x_x2031 = _x_0_1; /*float64*/
        }
        _x_x2030 = (-_x_x2031); /*float64*/
        _x_x2027 = kk_std_num_ddouble__new_Ddouble(_x_x2028, _x_x2030, _ctx); /*std/num/ddouble/ddouble*/
        x_2_10534 = kk_std_num_ddouble__lp__plus__rp_(ex, _x_x2027, _ctx); /*std/num/ddouble/ddouble*/
        double _x_x2032;
        double _x_x2033;
        {
          double _x_1_0 = x_2_10534.hi;
          _x_x2033 = _x_1_0; /*float64*/
        }
        _x_x2032 = (_x_x2033 * (0x1p-1)); /*float64*/
        double _x_x2034;
        double _x_x2035;
        {
          double _x_2_0 = x_2_10534.lo;
          _x_x2035 = _x_2_0; /*float64*/
        }
        _x_x2034 = (_x_x2035 * (0x1p-1)); /*float64*/
        return kk_std_num_ddouble__new_Ddouble(_x_x2032, _x_x2034, _ctx);
      }
      {
        return ex;
      }
    }
    {
      kk_std_num_ddouble__ddouble x2 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x_x2036;
      kk_std_num_ddouble__ddouble _x_x2037;
      kk_std_num_ddouble__ddouble _x_x2038;
      kk_std_num_ddouble__ddouble _x_x2039 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(6), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      _x_x2038 = kk_std_num_ddouble__lp__fs__rp_(x2, _x_x2039, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x2040;
      kk_std_num_ddouble__ddouble _x_x2041;
      kk_std_num_ddouble__ddouble _x_x2042;
      kk_std_num_ddouble__ddouble _x_x2043 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(20), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      _x_x2042 = kk_std_num_ddouble__lp__fs__rp_(x2, _x_x2043, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x2044;
      kk_std_num_ddouble__ddouble _x_x2045;
      kk_std_num_ddouble__ddouble _x_x2046 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(42), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      _x_x2045 = kk_std_num_ddouble__lp__fs__rp_(x2, _x_x2046, _ctx); /*std/num/ddouble/ddouble*/
      _x_x2044 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2045, _ctx); /*std/num/ddouble/ddouble*/
      _x_x2041 = kk_std_num_ddouble__lp__star__rp_(_x_x2042, _x_x2044, _ctx); /*std/num/ddouble/ddouble*/
      _x_x2040 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2041, _ctx); /*std/num/ddouble/ddouble*/
      _x_x2037 = kk_std_num_ddouble__lp__star__rp_(_x_x2038, _x_x2040, _ctx); /*std/num/ddouble/ddouble*/
      _x_x2036 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2037, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__star__rp_(x, _x_x2036, _ctx);
    }
  }
}
 
// The hyperbolic cosine of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_cosh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x521;
  double _x_x2047;
  {
    double _x = x.hi;
    _x_x2047 = _x; /*float64*/
  }
  _match_x521 = (_x_x2047 == (0x0p+0)); /*bool*/
  if (_match_x521) {
    return kk_std_num_ddouble_one;
  }
  {
    kk_std_num_ddouble__ddouble x_1_10547 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_x522;
    double _x_x2048;
    {
      double _x_0 = x_1_10547.hi;
      _x_x2048 = _x_0; /*float64*/
    }
    _match_x522 = (_x_x2048 > (0x1.999999999999ap-5)); /*bool*/
    if (_match_x522) {
      kk_std_num_ddouble__ddouble ex = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
      bool b_10549;
      bool _match_x523;
      double _x_x2049;
      {
        double _x_1 = ex.hi;
        _x_x2049 = _x_1; /*float64*/
      }
      _match_x523 = isfinite(_x_x2049); /*bool*/
      if (_match_x523) {
        double _x_x2050;
        {
          double _x_0_0 = ex.lo;
          _x_x2050 = _x_0_0; /*float64*/
        }
        b_10549 = isfinite(_x_x2050); /*bool*/
      }
      else {
        b_10549 = false; /*bool*/
      }
      if (b_10549) {
        kk_std_num_ddouble__ddouble x_2_10550;
        kk_std_num_ddouble__ddouble _x_x2051 = kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble_one, ex, _ctx); /*std/num/ddouble/ddouble*/
        x_2_10550 = kk_std_num_ddouble__lp__plus__rp_(ex, _x_x2051, _ctx); /*std/num/ddouble/ddouble*/
        double _x_x2052;
        double _x_x2053;
        {
          double _x_1_0 = x_2_10550.hi;
          _x_x2053 = _x_1_0; /*float64*/
        }
        _x_x2052 = (_x_x2053 * (0x1p-1)); /*float64*/
        double _x_x2054;
        double _x_x2055;
        {
          double _x_2 = x_2_10550.lo;
          _x_x2055 = _x_2; /*float64*/
        }
        _x_x2054 = (_x_x2055 * (0x1p-1)); /*float64*/
        return kk_std_num_ddouble__new_Ddouble(_x_x2052, _x_x2054, _ctx);
      }
      {
        return ex;
      }
    }
    {
      kk_std_num_ddouble__ddouble s = kk_std_num_ddouble_sinh(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x_x2056;
      kk_std_num_ddouble__ddouble _x_x2057 = kk_std_num_ddouble_sqr(s, _ctx); /*std/num/ddouble/ddouble*/
      _x_x2056 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2057, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble_sqrt(_x_x2056, _ctx);
    }
  }
}
 
// The hyperbolic tangent of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_tanh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x517;
  double _x_x2058;
  {
    double _x = x.hi;
    _x_x2058 = _x; /*float64*/
  }
  _match_x517 = (_x_x2058 == (0x0p+0)); /*bool*/
  if (_match_x517) {
    return kk_std_num_ddouble_zero;
  }
  {
    kk_std_num_ddouble__ddouble x_1_10558 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_x518;
    double _x_x2059;
    {
      double _x_0 = x_1_10558.hi;
      _x_x2059 = _x_0; /*float64*/
    }
    _match_x518 = (_x_x2059 > (0x1.999999999999ap-5)); /*bool*/
    if (_match_x518) {
      kk_std_num_ddouble__ddouble ex = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble iex = kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble_one, ex, _ctx); /*std/num/ddouble/ddouble*/;
      bool _match_x519;
      double _x_x2060;
      {
        double _x_1 = ex.hi;
        _x_x2060 = _x_1; /*float64*/
      }
      _match_x519 = (_x_x2060 == (0x0p+0)); /*bool*/
      if (_match_x519) {
        double _x_x2061;
        double _x_x2062;
        kk_std_num_ddouble__ddouble _x_x2063 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_2 = _x_x2063.hi;
          _x_x2062 = _x_2; /*float64*/
        }
        _x_x2061 = (-_x_x2062); /*float64*/
        double _x_x2064;
        double _x_x2065;
        kk_std_num_ddouble__ddouble _x_x2066 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_0_0 = _x_x2066.lo;
          _x_x2065 = _x_0_0; /*float64*/
        }
        _x_x2064 = (-_x_x2065); /*float64*/
        return kk_std_num_ddouble__new_Ddouble(_x_x2061, _x_x2064, _ctx);
      }
      {
        bool _match_x520;
        double _x_x2067;
        {
          double _x_2_0 = ex.hi;
          _x_x2067 = _x_2_0; /*float64*/
        }
        _match_x520 = (isinf(_x_x2067) && !signbit(_x_x2067)); /*bool*/
        if (_match_x520) {
          return kk_std_num_ddouble_one;
        }
        {
          kk_std_num_ddouble__ddouble _x_x2068;
          kk_std_num_ddouble__ddouble _x_x2069;
          double _x_x2070;
          double _x_x2071;
          {
            double _x_3 = iex.hi;
            _x_x2071 = _x_3; /*float64*/
          }
          _x_x2070 = (-_x_x2071); /*float64*/
          double _x_x2072;
          double _x_x2073;
          {
            double _x_0_1 = iex.lo;
            _x_x2073 = _x_0_1; /*float64*/
          }
          _x_x2072 = (-_x_x2073); /*float64*/
          _x_x2069 = kk_std_num_ddouble__new_Ddouble(_x_x2070, _x_x2072, _ctx); /*std/num/ddouble/ddouble*/
          _x_x2068 = kk_std_num_ddouble__lp__plus__rp_(ex, _x_x2069, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x2074 = kk_std_num_ddouble__lp__plus__rp_(ex, iex, _ctx); /*std/num/ddouble/ddouble*/
          return kk_std_num_ddouble__lp__fs__rp_(_x_x2068, _x_x2074, _ctx);
        }
      }
    }
    {
      kk_std_num_ddouble__ddouble s = kk_std_num_ddouble_sinh(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble c;
      kk_std_num_ddouble__ddouble _x_x2075;
      kk_std_num_ddouble__ddouble _x_x2076 = kk_std_num_ddouble_sqr(s, _ctx); /*std/num/ddouble/ddouble*/
      _x_x2075 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2076, _ctx); /*std/num/ddouble/ddouble*/
      c = kk_std_num_ddouble_sqrt(_x_x2075, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__fs__rp_(s, c, _ctx);
    }
  }
}
 
// The area hyperbolic cosine of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_acosh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x515;
  kk_std_core_types__order _x_x2081;
  kk_std_core_types__order _match_x516;
  double _x_x2082;
  {
    double _x = x.hi;
    _x_x2082 = _x; /*float64*/
  }
  double _x_x2083;
  kk_std_num_ddouble__ddouble _x_x2084 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
  {
    double _x_0 = _x_x2084.hi;
    _x_x2083 = _x_0; /*float64*/
  }
  _match_x516 = kk_std_num_float64_cmp(_x_x2082, _x_x2083, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x516, _ctx)) {
    double _x_x2085;
    {
      double _x_1 = x.lo;
      _x_x2085 = _x_1; /*float64*/
    }
    double _x_x2086;
    kk_std_num_ddouble__ddouble _x_x2087 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_2 = _x_x2087.lo;
      _x_x2086 = _x_2; /*float64*/
    }
    _x_x2081 = kk_std_num_float64_cmp(_x_x2085, _x_x2086, _ctx); /*order*/
  }
  else {
    _x_x2081 = _match_x516; /*order*/
  }
  _match_x515 = kk_std_core_order__lp__eq__eq__rp_(_x_x2081, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x515) {
    return kk_std_num_ddouble_dd_nan;
  }
  {
    kk_std_num_ddouble__ddouble x_1_10569 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble _x_x2088;
    kk_std_num_ddouble__ddouble _x_x2089;
    kk_std_num_ddouble__ddouble _x_x2090;
    kk_std_num_ddouble__ddouble _x_x2091;
    double _x_x2092;
    double _x_x2093;
    kk_std_num_ddouble__ddouble _x_x2094 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_3 = _x_x2094.hi;
      _x_x2093 = _x_3; /*float64*/
    }
    _x_x2092 = (-_x_x2093); /*float64*/
    double _x_x2095;
    double _x_x2096;
    kk_std_num_ddouble__ddouble _x_x2097 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_0_0 = _x_x2097.lo;
      _x_x2096 = _x_0_0; /*float64*/
    }
    _x_x2095 = (-_x_x2096); /*float64*/
    _x_x2091 = kk_std_num_ddouble__new_Ddouble(_x_x2092, _x_x2095, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2090 = kk_std_num_ddouble__lp__plus__rp_(x_1_10569, _x_x2091, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2089 = kk_std_num_ddouble_sqrt(_x_x2090, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2088 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x2089, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble_ln(_x_x2088, _ctx);
  }
}
 
// The area hyperbolic tangent of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_atanh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_0_10571 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x513;
  kk_std_core_types__order _x_x2098;
  kk_std_core_types__order _match_x514;
  double _x_x2099;
  {
    double _x = x_0_10571.hi;
    _x_x2099 = _x; /*float64*/
  }
  double _x_x2100;
  kk_std_num_ddouble__ddouble _x_x2101 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
  {
    double _x_0 = _x_x2101.hi;
    _x_x2100 = _x_0; /*float64*/
  }
  _match_x514 = kk_std_num_float64_cmp(_x_x2099, _x_x2100, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x514, _ctx)) {
    double _x_x2102;
    {
      double _x_1 = x_0_10571.lo;
      _x_x2102 = _x_1; /*float64*/
    }
    double _x_x2103;
    kk_std_num_ddouble__ddouble _x_x2104 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_2 = _x_x2104.lo;
      _x_x2103 = _x_2; /*float64*/
    }
    _x_x2098 = kk_std_num_float64_cmp(_x_x2102, _x_x2103, _ctx); /*order*/
  }
  else {
    _x_x2098 = _match_x514; /*order*/
  }
  _match_x513 = kk_std_core_order__lp__eq__eq__rp_(_x_x2098, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
  if (_match_x513) {
    return kk_std_num_ddouble_dd_nan;
  }
  {
    kk_std_num_ddouble__ddouble x_1_10573;
    kk_std_num_ddouble__ddouble _x_x2105;
    kk_std_num_ddouble__ddouble _x_x2106 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, x, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x2107;
    kk_std_num_ddouble__ddouble _x_x2108;
    double _x_x2109;
    double _x_x2110;
    {
      double _x_3 = x.hi;
      _x_x2110 = _x_3; /*float64*/
    }
    _x_x2109 = (-_x_x2110); /*float64*/
    double _x_x2111;
    double _x_x2112;
    {
      double _x_0_0 = x.lo;
      _x_x2112 = _x_0_0; /*float64*/
    }
    _x_x2111 = (-_x_x2112); /*float64*/
    _x_x2108 = kk_std_num_ddouble__new_Ddouble(_x_x2109, _x_x2111, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2107 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2108, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2105 = kk_std_num_ddouble__lp__fs__rp_(_x_x2106, _x_x2107, _ctx); /*std/num/ddouble/ddouble*/
    x_1_10573 = kk_std_num_ddouble_ln(_x_x2105, _ctx); /*std/num/ddouble/ddouble*/
    double _x_x2113;
    double _x_x2114;
    {
      double _x_4 = x_1_10573.hi;
      _x_x2114 = _x_4; /*float64*/
    }
    _x_x2113 = (_x_x2114 * (0x1p-1)); /*float64*/
    double _x_x2115;
    double _x_x2116;
    {
      double _x_0_1 = x_1_10573.lo;
      _x_x2116 = _x_0_1; /*float64*/
    }
    _x_x2115 = (_x_x2116 * (0x1p-1)); /*float64*/
    return kk_std_num_ddouble__new_Ddouble(_x_x2113, _x_x2115, _ctx);
  }
}

// initialization
void kk_std_num_ddouble__init(kk_context_t* _ctx){
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
  kk_std_core_undiv__init(_ctx);
  kk_std_num_float64__init(_ctx);
  kk_std_num_decimal__init(_ctx);
  kk_std_text_parse__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_num_ddouble_maxprecise = kk_integer_from_str("9007199254740991", _ctx); /*int*/
  }
  {
    kk_std_num_ddouble_minprecise = kk_integer_neg((kk_integer_from_str("9007199254740991", _ctx)),kk_context()); /*int*/
  }
  {
    kk_std_num_ddouble_dd_nan = kk_std_num_ddouble__new_Ddouble(kk_std_num_float64_nan, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_one = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_ten = kk_std_num_ddouble__new_Ddouble(0x1.4p3, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_zero = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_pi = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p1, 0x1.1a62633145c07p-53, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_twopi = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p2, 0x1.1a62633145c07p-52, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_pi2 = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p0, 0x1.1a62633145c07p-54, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_pi4 = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p-1, 0x1.1a62633145c07p-55, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_pi16 = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p1, 0x1.1a62633145c07p-53, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_pi34 = kk_std_num_ddouble__new_Ddouble(0x1.2d97c7f3321d2p1, 0x1.a79394c9e8a0bp-54, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_e = kk_std_num_ddouble__new_Ddouble(0x1.5bf0a8b145769p1, 0x1.4d57ee2b1013ap-53, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_ln2 = kk_std_num_ddouble__new_Ddouble(0x1.62e42fefa39efp-1, 0x1.abc9e3b39803fp-56, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_ln10 = kk_std_num_ddouble__new_Ddouble(0x1.26bb1bbb55516p1, -0x1.f48ad494ea3e9p-53, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_log2e = kk_std_num_ddouble__new_Ddouble(0x1.71547652b82fep0, 0x1.777d0ffda0d23p-56, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_log10e = kk_std_num_ddouble__new_Ddouble(0x1.bcb7b1526e50ep-2, 0x1.95355baaafad3p-57, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_sqrt2 = kk_std_num_ddouble__new_Ddouble(0x1.6a09e667f3bcdp0, -0x1.bdd3413b26456p-54, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_sqrt12 = kk_std_num_ddouble__new_Ddouble(0x1.6a09e667f3bcdp-1, -0x1.bdd3413b26456p-55, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_euler = kk_std_num_ddouble__new_Ddouble(0x1.2788cfc6fb619p-1, -0x1.6cb90701fbfabp-58, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_epsilon = kk_std_num_ddouble__new_Ddouble(0x1p-104, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_epsilon8 = kk_std_num_ddouble__new_Ddouble(0x1p-101, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_max = kk_std_num_ddouble__new_Ddouble(0x1.fffffffffffffp1023, 0x1.fffffffffffffp969, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_min = kk_std_num_ddouble__new_Ddouble(0x1p-1022, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_true_min = kk_std_num_ddouble__new_Ddouble(0x1p-1074, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_posinf = kk_std_num_ddouble__new_Ddouble(kk_std_num_float64_posinf, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_neginf = kk_std_num_ddouble__new_Ddouble(kk_std_num_float64_neginf, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_max_prec = kk_integer_from_small(31); /*int*/
  }
  {
    kk_std_num_ddouble_dd_default_prec = kk_integer_from_small(-31); /*int*/
  }
  {
    kk_std_num_ddouble_two = kk_std_num_ddouble__new_Ddouble(0x1p1, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_box_t _x_x1315;
    kk_std_num_ddouble__ddouble _x_x1316 = kk_std_num_ddouble__new_Ddouble(0x1.5555555555555p-3, 0x1.5555555555555p-57, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1315 = kk_std_num_ddouble__ddouble_box(_x_x1316, _ctx); /*10021*/
    kk_std_core_types__list _x_x1317;
    kk_box_t _x_x1318;
    kk_std_num_ddouble__ddouble _x_x1319 = kk_std_num_ddouble__new_Ddouble(0x1.5555555555555p-5, 0x1.5555555555555p-59, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1318 = kk_std_num_ddouble__ddouble_box(_x_x1319, _ctx); /*10021*/
    kk_std_core_types__list _x_x1320;
    kk_box_t _x_x1321;
    kk_std_num_ddouble__ddouble _x_x1322 = kk_std_num_ddouble__new_Ddouble(0x1.1111111111111p-7, 0x1.1111111111111p-63, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1321 = kk_std_num_ddouble__ddouble_box(_x_x1322, _ctx); /*10021*/
    kk_std_core_types__list _x_x1323;
    kk_box_t _x_x1324;
    kk_std_num_ddouble__ddouble _x_x1325 = kk_std_num_ddouble__new_Ddouble(0x1.6c16c16c16c17p-10, -0x1.f49f49f49f49fp-65, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1324 = kk_std_num_ddouble__ddouble_box(_x_x1325, _ctx); /*10021*/
    kk_std_core_types__list _x_x1326;
    kk_box_t _x_x1327;
    kk_std_num_ddouble__ddouble _x_x1328 = kk_std_num_ddouble__new_Ddouble(0x1.a01a01a01a01ap-13, 0x1.a01a01a01a01ap-73, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1327 = kk_std_num_ddouble__ddouble_box(_x_x1328, _ctx); /*10021*/
    kk_std_core_types__list _x_x1329;
    kk_box_t _x_x1330;
    kk_std_num_ddouble__ddouble _x_x1331 = kk_std_num_ddouble__new_Ddouble(0x1.a01a01a01a01ap-16, 0x1.a01a01a01a01ap-76, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1330 = kk_std_num_ddouble__ddouble_box(_x_x1331, _ctx); /*10021*/
    _x_x1329 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1330, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1326 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1327, _x_x1329, _ctx); /*list<10021>*/
    _x_x1323 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1324, _x_x1326, _ctx); /*list<10021>*/
    _x_x1320 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1321, _x_x1323, _ctx); /*list<10021>*/
    _x_x1317 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1318, _x_x1320, _ctx); /*list<10021>*/
    kk_std_num_ddouble_exp_factors = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1315, _x_x1317, _ctx); /*list<std/num/ddouble/ddouble>*/
  }
  {
    kk_std_num_ddouble_one_half = kk_std_num_ddouble__new_Ddouble(0x1p-1, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_box_t _x_x1763;
    kk_std_num_ddouble__ddouble _x_x1764 = kk_std_num_ddouble__new_Ddouble(0x1.6116039167de1p-33, 0x1.ea9f4c1702653p-88, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1763 = kk_std_num_ddouble__ddouble_box(_x_x1764, _ctx); /*10021*/
    kk_std_core_types__list _x_x1765;
    kk_box_t _x_x1766;
    kk_std_num_ddouble__ddouble _x_x1767 = kk_std_num_ddouble__new_Ddouble(-0x1.ae64561f4804fp-26, -0x1.c5104f49cf934p-82, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1766 = kk_std_num_ddouble__ddouble_box(_x_x1767, _ctx); /*10021*/
    kk_std_core_types__list _x_x1768;
    kk_box_t _x_x1769;
    kk_std_num_ddouble__ddouble _x_x1770 = kk_std_num_ddouble__new_Ddouble(0x1.71de3a556b36bp-19, -0x1.eb33da7509008p-73, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1769 = kk_std_num_ddouble__ddouble_box(_x_x1770, _ctx); /*10021*/
    kk_std_core_types__list _x_x1771;
    kk_box_t _x_x1772;
    kk_std_num_ddouble__ddouble _x_x1773 = kk_std_num_ddouble__new_Ddouble(-0x1.a01a01a01a01ap-13, 0x1.0313e2634850bp-67, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1772 = kk_std_num_ddouble__ddouble_box(_x_x1773, _ctx); /*10021*/
    kk_std_core_types__list _x_x1774;
    kk_box_t _x_x1775;
    kk_std_num_ddouble__ddouble _x_x1776 = kk_std_num_ddouble__new_Ddouble(0x1.1111111111111p-7, 0x1.110a7e6657814p-63, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1775 = kk_std_num_ddouble__ddouble_box(_x_x1776, _ctx); /*10021*/
    kk_std_core_types__list _x_x1777;
    kk_box_t _x_x1778;
    kk_std_num_ddouble__ddouble _x_x1779 = kk_std_num_ddouble__new_Ddouble(-0x1.5555555555555p-3, -0x1.5555555162e8fp-57, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1778 = kk_std_num_ddouble__ddouble_box(_x_x1779, _ctx); /*10021*/
    kk_std_core_types__list _x_x1780;
    kk_box_t _x_x1781;
    kk_std_num_ddouble__ddouble _x_x1782 = kk_std_num_ddouble__new_Ddouble(0x1p0, -0x1.86fa265ab5ed7p-101, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1781 = kk_std_num_ddouble__ddouble_box(_x_x1782, _ctx); /*10021*/
    _x_x1780 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1781, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1777 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1778, _x_x1780, _ctx); /*list<10021>*/
    _x_x1774 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1775, _x_x1777, _ctx); /*list<10021>*/
    _x_x1771 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1772, _x_x1774, _ctx); /*list<10021>*/
    _x_x1768 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1769, _x_x1771, _ctx); /*list<10021>*/
    _x_x1765 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1766, _x_x1768, _ctx); /*list<10021>*/
    kk_std_num_ddouble_ch_factors = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1763, _x_x1765, _ctx); /*list<std/num/ddouble/ddouble>*/
  }
  {
    kk_box_t _x_x1783;
    kk_std_num_ddouble__ddouble _x_x1784 = kk_std_num_ddouble__new_Ddouble(0x1.8f8b83c69a60bp-3, -0x1.26d19b9ff8d82p-57, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1783 = kk_std_num_ddouble__ddouble_box(_x_x1784, _ctx); /*10021*/
    kk_box_t _x_x1785;
    kk_std_num_ddouble__ddouble _x_x1786 = kk_std_num_ddouble__new_Ddouble(0x1.87de2a6aea963p-2, -0x1.72cedd3d5a61p-57, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1785 = kk_std_num_ddouble__ddouble_box(_x_x1786, _ctx); /*10021*/
    kk_box_t _x_x1787;
    kk_std_num_ddouble__ddouble _x_x1788 = kk_std_num_ddouble__new_Ddouble(0x1.1c73b39ae68c8p-1, 0x1.b25dd267f66p-55, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1787 = kk_std_num_ddouble__ddouble_box(_x_x1788, _ctx); /*10021*/
    kk_box_t _x_x1789;
    kk_std_num_ddouble__ddouble _x_x1790 = kk_std_num_ddouble__new_Ddouble(0x1.6a09e667f3bcdp-1, -0x1.bdd3413b26455p-55, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1789 = kk_std_num_ddouble__ddouble_box(_x_x1790, _ctx); /*10021*/
    kk_box_t _x_x1791;
    kk_std_num_ddouble__ddouble _x_x1792 = kk_std_num_ddouble__new_Ddouble(0x1.a9b66290ea1a3p-1, 0x1.9f630e8b6dafp-60, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1791 = kk_std_num_ddouble__ddouble_box(_x_x1792, _ctx); /*10021*/
    kk_box_t _x_x1793;
    kk_std_num_ddouble__ddouble _x_x1794 = kk_std_num_ddouble__new_Ddouble(0x1.d906bcf328d46p-1, 0x1.457e610231ac4p-56, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1793 = kk_std_num_ddouble__ddouble_box(_x_x1794, _ctx); /*10021*/
    kk_box_t _x_x1795;
    kk_std_num_ddouble__ddouble _x_x1796 = kk_std_num_ddouble__new_Ddouble(0x1.f6297cff75cbp-1, 0x1.562172a361fd6p-56, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1795 = kk_std_num_ddouble__ddouble_box(_x_x1796, _ctx); /*10021*/
    kk_vector_t _vec_x1797 = kk_std_core_vector__unsafe_vector((KK_IZ(9)), _ctx);
    kk_box_t* _buf_x1798 = kk_vector_buf_borrow(_vec_x1797, NULL, _ctx);
    _buf_x1798[0] = kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx);
    _buf_x1798[1] = _x_x1783;
    _buf_x1798[2] = _x_x1785;
    _buf_x1798[3] = _x_x1787;
    _buf_x1798[4] = _x_x1789;
    _buf_x1798[5] = _x_x1791;
    _buf_x1798[6] = _x_x1793;
    _buf_x1798[7] = _x_x1795;
    _buf_x1798[8] = kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_one, _ctx);
    kk_std_num_ddouble_sin16_table = _vec_x1797; /*vector<std/num/ddouble/ddouble>*/
  }
}

// termination
void kk_std_num_ddouble__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_vector_drop(kk_std_num_ddouble_sin16_table, _ctx);
  kk_std_core_types__list_drop(kk_std_num_ddouble_ch_factors, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_one_half, _ctx);
  kk_std_core_types__list_drop(kk_std_num_ddouble_exp_factors, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_two, _ctx);
  kk_integer_drop(kk_std_num_ddouble_dd_default_prec, _ctx);
  kk_integer_drop(kk_std_num_ddouble_dd_max_prec, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_neginf, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_posinf, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_true_min, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_min, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_max, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_epsilon8, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_epsilon, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_euler, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_sqrt12, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_sqrt2, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_log10e, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_log2e, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_ln10, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_ln2, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_e, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_pi34, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_pi16, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_pi4, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_pi2, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_twopi, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_pi, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_zero, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_ten, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_one, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble_dd_nan, _ctx);
  kk_integer_drop(kk_std_num_ddouble_minprecise, _ctx);
  kk_integer_drop(kk_std_num_ddouble_maxprecise, _ctx);
  kk_std_text_parse__done(_ctx);
  kk_std_num_decimal__done(_ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_core_undiv__done(_ctx);
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
