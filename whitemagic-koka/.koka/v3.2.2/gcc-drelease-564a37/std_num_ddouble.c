// Koka generated module: std/num/ddouble, koka version: 3.2.2, platform: 64-bit
#include "std_num_ddouble.h"

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_fs__copy(kk_std_num_ddouble__ddouble _this, kk_std_core_types__optional hi, kk_std_core_types__optional lo, kk_context_t* _ctx) { /* (ddouble, hi : ? float64, lo : ? float64) -> ddouble */ 
  double _x_x1002;
  if (kk_std_core_types__is_Optional(hi, _ctx)) {
    kk_box_t _box_x0 = hi._cons._Optional.value;
    double _uniq_hi_185 = kk_double_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(hi, _ctx);
    _x_x1002 = _uniq_hi_185; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(hi, _ctx);
    {
      double _x = _this.hi;
      _x_x1002 = _x; /*float64*/
    }
  }
  double _x_x1003;
  if (kk_std_core_types__is_Optional(lo, _ctx)) {
    kk_box_t _box_x1 = lo._cons._Optional.value;
    double _uniq_lo_193 = kk_double_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(lo, _ctx);
    _x_x1003 = _uniq_lo_193; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(lo, _ctx);
    {
      double _x_0 = _this.lo;
      _x_x1003 = _x_0; /*float64*/
    }
  }
  return kk_std_num_ddouble__new_Ddouble(_x_x1002, _x_x1003, _ctx);
}

kk_integer_t kk_std_num_ddouble_maxprecise;

bool kk_std_num_ddouble__lp__excl__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x_0_10006;
  kk_std_core_types__order _match_x986;
  double _x_x1008;
  {
    double _x = x.hi;
    _x_x1008 = _x; /*float64*/
  }
  double _x_x1009;
  {
    double _x_0 = y.hi;
    _x_x1009 = _x_0; /*float64*/
  }
  _match_x986 = kk_std_num_float64_cmp(_x_x1008, _x_x1009, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x986, _ctx)) {
    double _x_x1010;
    {
      double _x_1 = x.lo;
      _x_x1010 = _x_1; /*float64*/
    }
    double _x_x1011;
    {
      double _x_2 = y.lo;
      _x_x1011 = _x_2; /*float64*/
    }
    x_0_10006 = kk_std_num_float64_cmp(_x_x1010, _x_x1011, _ctx); /*order*/
  }
  else {
    x_0_10006 = _match_x986; /*order*/
  }
  kk_integer_t _brw_x984;
  if (kk_std_core_types__is_Lt(x_0_10006, _ctx)) {
    _brw_x984 = kk_integer_from_small(-1); /*int*/
    goto _match_x1012;
  }
  if (kk_std_core_types__is_Eq(x_0_10006, _ctx)) {
    _brw_x984 = kk_integer_from_small(0); /*int*/
    goto _match_x1012;
  }
  {
    _brw_x984 = kk_integer_from_small(1); /*int*/
  }
  _match_x1012: ;
  bool _brw_x985 = kk_integer_neq_borrow(_brw_x984,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x984, _ctx);
  return _brw_x985;
}

bool kk_std_num_ddouble__lp__gt__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x_0_10008;
  kk_std_core_types__order _match_x983;
  double _x_x1013;
  {
    double _x = x.hi;
    _x_x1013 = _x; /*float64*/
  }
  double _x_x1014;
  {
    double _x_0 = y.hi;
    _x_x1014 = _x_0; /*float64*/
  }
  _match_x983 = kk_std_num_float64_cmp(_x_x1013, _x_x1014, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x983, _ctx)) {
    double _x_x1015;
    {
      double _x_1 = x.lo;
      _x_x1015 = _x_1; /*float64*/
    }
    double _x_x1016;
    {
      double _x_2 = y.lo;
      _x_x1016 = _x_2; /*float64*/
    }
    x_0_10008 = kk_std_num_float64_cmp(_x_x1015, _x_x1016, _ctx); /*order*/
  }
  else {
    x_0_10008 = _match_x983; /*order*/
  }
  kk_integer_t _brw_x981;
  if (kk_std_core_types__is_Lt(x_0_10008, _ctx)) {
    _brw_x981 = kk_integer_from_small(-1); /*int*/
    goto _match_x1017;
  }
  if (kk_std_core_types__is_Eq(x_0_10008, _ctx)) {
    _brw_x981 = kk_integer_from_small(0); /*int*/
    goto _match_x1017;
  }
  {
    _brw_x981 = kk_integer_from_small(1); /*int*/
  }
  _match_x1017: ;
  bool _brw_x982 = kk_integer_neq_borrow(_brw_x981,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x981, _ctx);
  return _brw_x982;
}

bool kk_std_num_ddouble__lp__lt__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x_0_10010;
  kk_std_core_types__order _match_x980;
  double _x_x1018;
  {
    double _x = x.hi;
    _x_x1018 = _x; /*float64*/
  }
  double _x_x1019;
  {
    double _x_0 = y.hi;
    _x_x1019 = _x_0; /*float64*/
  }
  _match_x980 = kk_std_num_float64_cmp(_x_x1018, _x_x1019, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x980, _ctx)) {
    double _x_x1020;
    {
      double _x_1 = x.lo;
      _x_x1020 = _x_1; /*float64*/
    }
    double _x_x1021;
    {
      double _x_2 = y.lo;
      _x_x1021 = _x_2; /*float64*/
    }
    x_0_10010 = kk_std_num_float64_cmp(_x_x1020, _x_x1021, _ctx); /*order*/
  }
  else {
    x_0_10010 = _match_x980; /*order*/
  }
  kk_integer_t _brw_x978;
  if (kk_std_core_types__is_Lt(x_0_10010, _ctx)) {
    _brw_x978 = kk_integer_from_small(-1); /*int*/
    goto _match_x1022;
  }
  if (kk_std_core_types__is_Eq(x_0_10010, _ctx)) {
    _brw_x978 = kk_integer_from_small(0); /*int*/
    goto _match_x1022;
  }
  {
    _brw_x978 = kk_integer_from_small(1); /*int*/
  }
  _match_x1022: ;
  bool _brw_x979 = kk_integer_neq_borrow(_brw_x978,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x978, _ctx);
  return _brw_x979;
}

kk_integer_t kk_std_num_ddouble_minprecise;

bool kk_std_num_ddouble_is_precise(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  bool _match_x975 = kk_integer_gte_borrow(i,kk_std_num_ddouble_minprecise,kk_context()); /*bool*/;
  if (_match_x975) {
    kk_integer_t _brw_x976 = kk_integer_from_str("9007199254740991", _ctx); /*int*/;
    bool _brw_x977 = kk_integer_lte_borrow(i,_brw_x976,kk_context()); /*bool*/;
    kk_integer_drop(i, _ctx);
    kk_integer_drop(_brw_x976, _ctx);
    return _brw_x977;
  }
  {
    kk_integer_drop(i, _ctx);
    return false;
  }
}
 
// Not-A-Number

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_nan;

bool kk_std_num_ddouble__lp__eq__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x_0_10020;
  kk_std_core_types__order _match_x973;
  double _x_x1031;
  {
    double _x = x.hi;
    _x_x1031 = _x; /*float64*/
  }
  double _x_x1032;
  {
    double _x_0 = y.hi;
    _x_x1032 = _x_0; /*float64*/
  }
  _match_x973 = kk_std_num_float64_cmp(_x_x1031, _x_x1032, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x973, _ctx)) {
    double _x_x1033;
    {
      double _x_1 = x.lo;
      _x_x1033 = _x_1; /*float64*/
    }
    double _x_x1034;
    {
      double _x_2 = y.lo;
      _x_x1034 = _x_2; /*float64*/
    }
    x_0_10020 = kk_std_num_float64_cmp(_x_x1033, _x_x1034, _ctx); /*order*/
  }
  else {
    x_0_10020 = _match_x973; /*order*/
  }
  kk_integer_t _brw_x971;
  if (kk_std_core_types__is_Lt(x_0_10020, _ctx)) {
    _brw_x971 = kk_integer_from_small(-1); /*int*/
    goto _match_x1035;
  }
  if (kk_std_core_types__is_Eq(x_0_10020, _ctx)) {
    _brw_x971 = kk_integer_from_small(0); /*int*/
    goto _match_x1035;
  }
  {
    _brw_x971 = kk_integer_from_small(1); /*int*/
  }
  _match_x1035: ;
  bool _brw_x972 = kk_integer_eq_borrow(_brw_x971,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x971, _ctx);
  return _brw_x972;
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dquicksum(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> ddouble */ 
  bool b_10026 = isfinite(x); /*bool*/;
  if (b_10026) {
    double z = (x + y); /*float64*/;
    double err;
    double _x_x1041 = (z - x); /*float64*/
    err = (y - _x_x1041); /*float64*/
    double _x_x1042;
    bool _match_x969 = isfinite(z); /*bool*/;
    if (_match_x969) {
      _x_x1042 = err; /*float64*/
    }
    else {
      _x_x1042 = z; /*float64*/
    }
    return kk_std_num_ddouble__new_Ddouble(z, _x_x1042, _ctx);
  }
  {
    return kk_std_num_ddouble__new_Ddouble(x, 0x0p+0, _ctx);
  }
}
 
// Multiply two `:ddouble`s

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  double z;
  double _x_x1044;
  {
    double _x = x.hi;
    _x_x1044 = _x; /*float64*/
  }
  double _x_x1045;
  {
    double _x_0 = y.hi;
    _x_x1045 = _x_0; /*float64*/
  }
  z = (_x_x1044 * _x_x1045); /*float64*/
  double err;
  double _x_x1046;
  {
    double _x_1 = x.hi;
    _x_x1046 = _x_1; /*float64*/
  }
  double _x_x1047;
  {
    double _x_0_0 = y.hi;
    _x_x1047 = _x_0_0; /*float64*/
  }
  double _x_x1048 = (-z); /*float64*/
  err = kk_std_num_float64_fmadd(_x_x1046, _x_x1047, _x_x1048, _ctx); /*float64*/
  kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
  double e;
  double _x_x1049;
  {
    double _x_1_0 = z_0.err;
    _x_x1049 = _x_1_0; /*float64*/
  }
  double _x_x1050;
  double _x_x1051;
  double _x_x1052;
  {
    double _x_2 = x.hi;
    _x_x1052 = _x_2; /*float64*/
  }
  double _x_x1053;
  {
    double _x_3 = y.lo;
    _x_x1053 = _x_3; /*float64*/
  }
  _x_x1051 = (_x_x1052 * _x_x1053); /*float64*/
  double _x_x1054;
  double _x_x1055;
  {
    double _x_4 = x.lo;
    _x_x1055 = _x_4; /*float64*/
  }
  double _x_x1056;
  {
    double _x_5 = y.hi;
    _x_x1056 = _x_5; /*float64*/
  }
  _x_x1054 = (_x_x1055 * _x_x1056); /*float64*/
  _x_x1050 = (_x_x1051 + _x_x1054); /*float64*/
  e = (_x_x1049 + _x_x1050); /*float64*/
  bool b_10040;
  double _x_x1057;
  {
    double _x_6 = z_0.num;
    _x_x1057 = _x_6; /*float64*/
  }
  b_10040 = isfinite(_x_x1057); /*bool*/
  if (b_10040) {
    double z_1;
    double _x_x1058;
    {
      double _x_6_0 = z_0.num;
      _x_x1058 = _x_6_0; /*float64*/
    }
    z_1 = (_x_x1058 + e); /*float64*/
    double err_0;
    double _x_x1059;
    double _x_x1060;
    {
      double _x_6_1 = z_0.num;
      _x_x1060 = _x_6_1; /*float64*/
    }
    _x_x1059 = (z_1 - _x_x1060); /*float64*/
    err_0 = (e - _x_x1059); /*float64*/
    double _x_x1061;
    bool _match_x968 = isfinite(z_1); /*bool*/;
    if (_match_x968) {
      _x_x1061 = err_0; /*float64*/
    }
    else {
      _x_x1061 = z_1; /*float64*/
    }
    return kk_std_num_ddouble__new_Ddouble(z_1, _x_x1061, _ctx);
  }
  {
    double _x_x1062;
    {
      double _x_6_2 = z_0.num;
      _x_x1062 = _x_6_2; /*float64*/
    }
    return kk_std_num_ddouble__new_Ddouble(_x_x1062, 0x0p+0, _ctx);
  }
}
 
// As `sum` but with `x.abs >= y.abs`

kk_std_num_ddouble__edouble kk_std_num_ddouble_quicksum(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> edouble */ 
  double z = (x + y); /*float64*/;
  double err;
  double _x_x1063 = (z - x); /*float64*/
  err = (y - _x_x1063); /*float64*/
  double _x_x1064;
  bool _match_x967 = isfinite(z); /*bool*/;
  if (_match_x967) {
    _x_x1064 = err; /*float64*/
  }
  else {
    _x_x1064 = z; /*float64*/
  }
  return kk_std_num_ddouble__new_Edouble(z, _x_x1064, _ctx);
}
 
// often called `twosum` in literature (see [@shewchuk])

kk_std_num_ddouble__edouble kk_std_num_ddouble_sum(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> edouble */ 
  double z = (x + y); /*float64*/;
  double diff = (z - x); /*float64*/;
  double err;
  double _x_x1065;
  double _x_x1066 = (z - diff); /*float64*/
  _x_x1065 = (x - _x_x1066); /*float64*/
  double _x_x1067 = (y - diff); /*float64*/
  err = (_x_x1065 + _x_x1067); /*float64*/
  double _x_x1068;
  bool _match_x966 = isfinite(z); /*bool*/;
  if (_match_x966) {
    _x_x1068 = err; /*float64*/
  }
  else {
    _x_x1068 = z; /*float64*/
  }
  return kk_std_num_ddouble__new_Edouble(z, _x_x1068, _ctx);
}
 
// Add two `:ddouble`s

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  double z;
  double _x_x1069;
  {
    double _x = x.hi;
    _x_x1069 = _x; /*float64*/
  }
  double _x_x1070;
  {
    double _x_0 = y.hi;
    _x_x1070 = _x_0; /*float64*/
  }
  z = (_x_x1069 + _x_x1070); /*float64*/
  double diff;
  double _x_x1071;
  {
    double _x_1 = x.hi;
    _x_x1071 = _x_1; /*float64*/
  }
  diff = (z - _x_x1071); /*float64*/
  double err;
  double _x_x1072;
  double _x_x1073;
  {
    double _x_2 = x.hi;
    _x_x1073 = _x_2; /*float64*/
  }
  double _x_x1074 = (z - diff); /*float64*/
  _x_x1072 = (_x_x1073 - _x_x1074); /*float64*/
  double _x_x1075;
  double _x_x1076;
  {
    double _x_0_0 = y.hi;
    _x_x1076 = _x_0_0; /*float64*/
  }
  _x_x1075 = (_x_x1076 - diff); /*float64*/
  err = (_x_x1072 + _x_x1075); /*float64*/
  kk_std_num_ddouble__edouble z1;
  double _x_x1077;
  bool _match_x965 = isfinite(z); /*bool*/;
  if (_match_x965) {
    _x_x1077 = err; /*float64*/
  }
  else {
    _x_x1077 = z; /*float64*/
  }
  z1 = kk_std_num_ddouble__new_Edouble(z, _x_x1077, _ctx); /*std/num/ddouble/edouble*/
  double z_0;
  double _x_x1078;
  {
    double _x_1_0 = x.lo;
    _x_x1078 = _x_1_0; /*float64*/
  }
  double _x_x1079;
  {
    double _x_2_0 = y.lo;
    _x_x1079 = _x_2_0; /*float64*/
  }
  z_0 = (_x_x1078 + _x_x1079); /*float64*/
  double diff_0;
  double _x_x1080;
  {
    double _x_1_1 = x.lo;
    _x_x1080 = _x_1_1; /*float64*/
  }
  diff_0 = (z_0 - _x_x1080); /*float64*/
  double err_0;
  double _x_x1081;
  double _x_x1082;
  {
    double _x_1_2 = x.lo;
    _x_x1082 = _x_1_2; /*float64*/
  }
  double _x_x1083 = (z_0 - diff_0); /*float64*/
  _x_x1081 = (_x_x1082 - _x_x1083); /*float64*/
  double _x_x1084;
  double _x_x1085;
  {
    double _x_2_1 = y.lo;
    _x_x1085 = _x_2_1; /*float64*/
  }
  _x_x1084 = (_x_x1085 - diff_0); /*float64*/
  err_0 = (_x_x1081 + _x_x1084); /*float64*/
  kk_std_num_ddouble__edouble lo;
  double _x_x1086;
  bool _match_x964 = isfinite(z_0); /*bool*/;
  if (_match_x964) {
    _x_x1086 = err_0; /*float64*/
  }
  else {
    _x_x1086 = z_0; /*float64*/
  }
  lo = kk_std_num_ddouble__new_Edouble(z_0, _x_x1086, _ctx); /*std/num/ddouble/edouble*/
  double e1;
  double _x_x1087;
  {
    double _x_3 = z1.err;
    _x_x1087 = _x_3; /*float64*/
  }
  double _x_x1088;
  {
    double _x_4 = lo.num;
    _x_x1088 = _x_4; /*float64*/
  }
  e1 = (_x_x1087 + _x_x1088); /*float64*/
  double z_1;
  double _x_x1089;
  {
    double _x_5 = z1.num;
    _x_x1089 = _x_5; /*float64*/
  }
  z_1 = (_x_x1089 + e1); /*float64*/
  double err_1;
  double _x_x1090;
  double _x_x1091;
  {
    double _x_5_0 = z1.num;
    _x_x1091 = _x_5_0; /*float64*/
  }
  _x_x1090 = (z_1 - _x_x1091); /*float64*/
  err_1 = (e1 - _x_x1090); /*float64*/
  kk_std_num_ddouble__edouble z2;
  double _x_x1092;
  bool _match_x963 = isfinite(z_1); /*bool*/;
  if (_match_x963) {
    _x_x1092 = err_1; /*float64*/
  }
  else {
    _x_x1092 = z_1; /*float64*/
  }
  z2 = kk_std_num_ddouble__new_Edouble(z_1, _x_x1092, _ctx); /*std/num/ddouble/edouble*/
  double e2;
  double _x_x1093;
  {
    double _x_6 = z2.err;
    _x_x1093 = _x_6; /*float64*/
  }
  double _x_x1094;
  {
    double _x_7 = lo.err;
    _x_x1094 = _x_7; /*float64*/
  }
  e2 = (_x_x1093 + _x_x1094); /*float64*/
  bool b_10060;
  double _x_x1095;
  {
    double _x_8 = z2.num;
    _x_x1095 = _x_8; /*float64*/
  }
  b_10060 = isfinite(_x_x1095); /*bool*/
  if (b_10060) {
    double z_2;
    double _x_x1096;
    {
      double _x_8_0 = z2.num;
      _x_x1096 = _x_8_0; /*float64*/
    }
    z_2 = (_x_x1096 + e2); /*float64*/
    double err_2;
    double _x_x1097;
    double _x_x1098;
    {
      double _x_8_1 = z2.num;
      _x_x1098 = _x_8_1; /*float64*/
    }
    _x_x1097 = (z_2 - _x_x1098); /*float64*/
    err_2 = (e2 - _x_x1097); /*float64*/
    double _x_x1099;
    bool _match_x962 = isfinite(z_2); /*bool*/;
    if (_match_x962) {
      _x_x1099 = err_2; /*float64*/
    }
    else {
      _x_x1099 = z_2; /*float64*/
    }
    return kk_std_num_ddouble__new_Ddouble(z_2, _x_x1099, _ctx);
  }
  {
    double _x_x1100;
    {
      double _x_8_2 = z2.num;
      _x_x1100 = _x_8_2; /*float64*/
    }
    return kk_std_num_ddouble__new_Ddouble(_x_x1100, 0x0p+0, _ctx);
  }
}
 
// Divide two `:ddouble`s

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  double d_10062;
  double _x_x1106;
  {
    double _x = x.hi;
    _x_x1106 = _x; /*float64*/
  }
  double _x_x1107;
  {
    double _x_0 = y.hi;
    _x_x1107 = _x_0; /*float64*/
  }
  d_10062 = (_x_x1106 / _x_x1107); /*float64*/
  kk_std_num_ddouble__ddouble q1 = kk_std_num_ddouble__new_Ddouble(d_10062, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  bool b_10065;
  bool _match_x961;
  double _x_x1108;
  {
    double _x_1 = q1.hi;
    _x_x1108 = _x_1; /*float64*/
  }
  _match_x961 = isfinite(_x_x1108); /*bool*/
  if (_match_x961) {
    double _x_x1109;
    {
      double _x_0_0 = q1.lo;
      _x_x1109 = _x_0_0; /*float64*/
    }
    b_10065 = isfinite(_x_x1109); /*bool*/
  }
  else {
    b_10065 = false; /*bool*/
  }
  if (b_10065) {
    bool b_0_10066;
    double _x_x1110;
    {
      double _x_1_0 = y.hi;
      _x_x1110 = _x_1_0; /*float64*/
    }
    b_0_10066 = isfinite(_x_x1110); /*bool*/
    if (b_0_10066) {
      kk_std_num_ddouble__ddouble y_0_10069 = kk_std_num_ddouble__lp__star__rp_(y, q1, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble r1;
      kk_std_num_ddouble__ddouble _x_x1111;
      double _x_x1112;
      double _x_x1113;
      {
        double _x_2 = y_0_10069.hi;
        _x_x1113 = _x_2; /*float64*/
      }
      _x_x1112 = (-_x_x1113); /*float64*/
      double _x_x1114;
      double _x_x1115;
      {
        double _x_0_1 = y_0_10069.lo;
        _x_x1115 = _x_0_1; /*float64*/
      }
      _x_x1114 = (-_x_x1115); /*float64*/
      _x_x1111 = kk_std_num_ddouble__new_Ddouble(_x_x1112, _x_x1114, _ctx); /*std/num/ddouble/ddouble*/
      r1 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x1111, _ctx); /*std/num/ddouble/ddouble*/
      double d_0_10070;
      double _x_x1116;
      {
        double _x_2_0 = r1.hi;
        _x_x1116 = _x_2_0; /*float64*/
      }
      double _x_x1117;
      {
        double _x_3 = y.hi;
        _x_x1117 = _x_3; /*float64*/
      }
      d_0_10070 = (_x_x1116 / _x_x1117); /*float64*/
      kk_std_num_ddouble__ddouble q2 = kk_std_num_ddouble__new_Ddouble(d_0_10070, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble y_1_10074 = kk_std_num_ddouble__lp__star__rp_(y, q2, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble r2;
      kk_std_num_ddouble__ddouble _x_x1118;
      double _x_x1119;
      double _x_x1120;
      {
        double _x_4 = y_1_10074.hi;
        _x_x1120 = _x_4; /*float64*/
      }
      _x_x1119 = (-_x_x1120); /*float64*/
      double _x_x1121;
      double _x_x1122;
      {
        double _x_0_2 = y_1_10074.lo;
        _x_x1122 = _x_0_2; /*float64*/
      }
      _x_x1121 = (-_x_x1122); /*float64*/
      _x_x1118 = kk_std_num_ddouble__new_Ddouble(_x_x1119, _x_x1121, _ctx); /*std/num/ddouble/ddouble*/
      r2 = kk_std_num_ddouble__lp__plus__rp_(r1, _x_x1118, _ctx); /*std/num/ddouble/ddouble*/
      double d_1_10075;
      double _x_x1123;
      {
        double _x_4_0 = r2.hi;
        _x_x1123 = _x_4_0; /*float64*/
      }
      double _x_x1124;
      {
        double _x_5 = y.hi;
        _x_x1124 = _x_5; /*float64*/
      }
      d_1_10075 = (_x_x1123 / _x_x1124); /*float64*/
      bool b_1_10082;
      double _x_x1125;
      {
        double _x_6 = q1.hi;
        _x_x1125 = _x_6; /*float64*/
      }
      b_1_10082 = isfinite(_x_x1125); /*bool*/
      kk_std_num_ddouble__ddouble q;
      if (b_1_10082) {
        double z;
        double _x_x1126;
        {
          double _x_6_0 = q1.hi;
          _x_x1126 = _x_6_0; /*float64*/
        }
        double _x_x1127;
        {
          double _x_7 = q2.hi;
          _x_x1127 = _x_7; /*float64*/
        }
        z = (_x_x1126 + _x_x1127); /*float64*/
        double err;
        double _x_x1128;
        {
          double _x_7_0 = q2.hi;
          _x_x1128 = _x_7_0; /*float64*/
        }
        double _x_x1129;
        double _x_x1130;
        {
          double _x_6_1 = q1.hi;
          _x_x1130 = _x_6_1; /*float64*/
        }
        _x_x1129 = (z - _x_x1130); /*float64*/
        err = (_x_x1128 - _x_x1129); /*float64*/
        double _x_x1131;
        bool _match_x960 = isfinite(z); /*bool*/;
        if (_match_x960) {
          _x_x1131 = err; /*float64*/
        }
        else {
          _x_x1131 = z; /*float64*/
        }
        q = kk_std_num_ddouble__new_Ddouble(z, _x_x1131, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double _x_x1132;
        {
          double _x_6_2 = q1.hi;
          _x_x1132 = _x_6_2; /*float64*/
        }
        q = kk_std_num_ddouble__new_Ddouble(_x_x1132, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x_x1133 = kk_std_num_ddouble__new_Ddouble(d_1_10075, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__plus__rp_(q, _x_x1133, _ctx);
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
  double _x_x1134;
  double _x_x1135 = (z - diff); /*float64*/
  _x_x1134 = (x - _x_x1135); /*float64*/
  double _x_x1136 = (y - diff); /*float64*/
  err = (_x_x1134 + _x_x1136); /*float64*/
  double _x_x1137;
  bool _match_x959 = isfinite(z); /*bool*/;
  if (_match_x959) {
    _x_x1137 = err; /*float64*/
  }
  else {
    _x_x1137 = z; /*float64*/
  }
  return kk_std_num_ddouble__new_Ddouble(z, _x_x1137, _ctx);
}
 
// Multiply `x` with itself.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sqr(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double z;
  double _x_x1139;
  {
    double _x = x.hi;
    _x_x1139 = _x; /*float64*/
  }
  double _x_x1140;
  {
    double _x_0 = x.hi;
    _x_x1140 = _x_0; /*float64*/
  }
  z = (_x_x1139 * _x_x1140); /*float64*/
  double err;
  double _x_x1141;
  {
    double _x_1 = x.hi;
    _x_x1141 = _x_1; /*float64*/
  }
  double _x_x1142;
  {
    double _x_2 = x.hi;
    _x_x1142 = _x_2; /*float64*/
  }
  double _x_x1143 = (-z); /*float64*/
  err = kk_std_num_float64_fmadd(_x_x1141, _x_x1142, _x_x1143, _ctx); /*float64*/
  kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
  double e;
  double _x_x1144;
  double _x_x1145;
  {
    double _x_0_0 = z_0.err;
    _x_x1145 = _x_0_0; /*float64*/
  }
  double _x_x1146;
  double _x_x1147;
  double _x_x1148;
  {
    double _x_1_0 = x.hi;
    _x_x1148 = _x_1_0; /*float64*/
  }
  _x_x1147 = (0x1p1 * _x_x1148); /*float64*/
  double _x_x1149;
  {
    double _x_2_0 = x.lo;
    _x_x1149 = _x_2_0; /*float64*/
  }
  _x_x1146 = (_x_x1147 * _x_x1149); /*float64*/
  _x_x1144 = (_x_x1145 + _x_x1146); /*float64*/
  double _x_x1150;
  double _x_x1151;
  {
    double _x_3 = x.lo;
    _x_x1151 = _x_3; /*float64*/
  }
  double _x_x1152;
  {
    double _x_4 = x.lo;
    _x_x1152 = _x_4; /*float64*/
  }
  _x_x1150 = (_x_x1151 * _x_x1152); /*float64*/
  e = (_x_x1144 + _x_x1150); /*float64*/
  bool b_10096;
  double _x_x1153;
  {
    double _x_5 = z_0.num;
    _x_x1153 = _x_5; /*float64*/
  }
  b_10096 = isfinite(_x_x1153); /*bool*/
  if (b_10096) {
    double z_1;
    double _x_x1154;
    {
      double _x_5_0 = z_0.num;
      _x_x1154 = _x_5_0; /*float64*/
    }
    z_1 = (_x_x1154 + e); /*float64*/
    double err_0;
    double _x_x1155;
    double _x_x1156;
    {
      double _x_5_1 = z_0.num;
      _x_x1156 = _x_5_1; /*float64*/
    }
    _x_x1155 = (z_1 - _x_x1156); /*float64*/
    err_0 = (e - _x_x1155); /*float64*/
    double _x_x1157;
    bool _match_x957 = isfinite(z_1); /*bool*/;
    if (_match_x957) {
      _x_x1157 = err_0; /*float64*/
    }
    else {
      _x_x1157 = z_1; /*float64*/
    }
    return kk_std_num_ddouble__new_Ddouble(z_1, _x_x1157, _ctx);
  }
  {
    double _x_x1158;
    {
      double _x_5_2 = z_0.num;
      _x_x1158 = _x_5_2; /*float64*/
    }
    return kk_std_num_ddouble__new_Ddouble(_x_x1158, 0x0p+0, _ctx);
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_npwr_acc(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble acc, kk_integer_t n, kk_context_t* _ctx) { /* (x : ddouble, acc : ddouble, n : int) -> ddouble */ 
  kk__tailcall: ;
  bool _match_x956 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x956) {
    kk_integer_drop(n, _ctx);
    return acc;
  }
  {
    bool b_10014;
    kk_integer_t _x_x1159 = kk_integer_dup(n, _ctx); /*int*/
    b_10014 = kk_integer_is_odd(_x_x1159,kk_context()); /*bool*/
    if (b_10014) { // tailcall
                   kk_std_num_ddouble__ddouble _x_x1160 = kk_std_num_ddouble__lp__star__rp_(x, acc, _ctx); /*std/num/ddouble/ddouble*/
                   kk_integer_t _x_x1161 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
                   acc = _x_x1160;
                   n = _x_x1161;
                   goto kk__tailcall;
    }
    { // tailcall
      kk_std_num_ddouble__ddouble _x_x1162 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/
      kk_integer_t _x_x1163 = kk_integer_div(n,(kk_integer_from_small(2)),kk_context()); /*int*/
      x = _x_x1162;
      n = _x_x1163;
      goto kk__tailcall;
    }
  }
}
 
// One

kk_std_num_ddouble__ddouble kk_std_num_ddouble_one;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_npwr(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx) { /* (x : ddouble, n : int) -> ddouble */ 
  bool _match_x953 = kk_integer_eq_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x953) {
    kk_integer_drop(n, _ctx);
    bool _match_x955;
    double _x_x1164;
    {
      double _x = x.hi;
      _x_x1164 = _x; /*float64*/
    }
    _match_x955 = (_x_x1164 == (0x0p+0)); /*bool*/
    if (_match_x955) {
      return kk_std_num_ddouble_dd_nan;
    }
    {
      return kk_std_num_ddouble_one;
    }
  }
  {
    bool _match_x954 = kk_integer_eq_borrow(n,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x954) {
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
  kk_integer_t n_0_10105;
  kk_integer_t _x_x1165 = kk_integer_dup(n, _ctx); /*int*/
  n_0_10105 = kk_integer_abs(_x_x1165,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble p;
  bool _match_x950 = kk_integer_eq_borrow(n_0_10105,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x950) {
    kk_integer_drop(n_0_10105, _ctx);
    bool _match_x952;
    double _x_x1166;
    {
      double _x = x.hi;
      _x_x1166 = _x; /*float64*/
    }
    _match_x952 = (_x_x1166 == (0x0p+0)); /*bool*/
    if (_match_x952) {
      p = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      p = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    }
  }
  else {
    bool _match_x951 = kk_integer_eq_borrow(n_0_10105,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x951) {
      kk_integer_drop(n_0_10105, _ctx);
      p = x; /*std/num/ddouble/ddouble*/
    }
    else {
      p = kk_std_num_ddouble_npwr_acc(x, kk_std_num_ddouble_one, n_0_10105, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  bool _match_x948;
  bool _brw_x949 = kk_integer_lt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(n, _ctx);
  _match_x948 = _brw_x949; /*bool*/
  if (_match_x948) {
    return kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble_one, p, _ctx);
  }
  {
    return p;
  }
}
 
// Ten (`10.ddouble`)

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ten;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_mul_exp10(kk_std_num_ddouble__ddouble x, kk_integer_t exp_0, kk_context_t* _ctx) { /* (x : ddouble, exp : int) -> ddouble */ 
  bool _match_x946 = kk_integer_is_zero_borrow(exp_0); /*bool*/;
  if (_match_x946) {
    kk_integer_drop(exp_0, _ctx);
    return x;
  }
  {
    kk_std_num_ddouble__ddouble y_10677 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, exp_0, _ctx); /*std/num/ddouble/ddouble*/;
    double z;
    double _x_x1167;
    {
      double _x = x.hi;
      _x_x1167 = _x; /*float64*/
    }
    double _x_x1168;
    {
      double _x_0 = y_10677.hi;
      _x_x1168 = _x_0; /*float64*/
    }
    z = (_x_x1167 * _x_x1168); /*float64*/
    double err;
    double _x_x1169;
    {
      double _x_1 = x.hi;
      _x_x1169 = _x_1; /*float64*/
    }
    double _x_x1170;
    {
      double _x_0_0 = y_10677.hi;
      _x_x1170 = _x_0_0; /*float64*/
    }
    double _x_x1171 = (-z); /*float64*/
    err = kk_std_num_float64_fmadd(_x_x1169, _x_x1170, _x_x1171, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
    double e;
    double _x_x1172;
    {
      double _x_1_0 = z_0.err;
      _x_x1172 = _x_1_0; /*float64*/
    }
    double _x_x1173;
    double _x_x1174;
    double _x_x1175;
    {
      double _x_2 = x.hi;
      _x_x1175 = _x_2; /*float64*/
    }
    double _x_x1176;
    {
      double _x_3 = y_10677.lo;
      _x_x1176 = _x_3; /*float64*/
    }
    _x_x1174 = (_x_x1175 * _x_x1176); /*float64*/
    double _x_x1177;
    double _x_x1178;
    {
      double _x_4 = x.lo;
      _x_x1178 = _x_4; /*float64*/
    }
    double _x_x1179;
    {
      double _x_5 = y_10677.hi;
      _x_x1179 = _x_5; /*float64*/
    }
    _x_x1177 = (_x_x1178 * _x_x1179); /*float64*/
    _x_x1173 = (_x_x1174 + _x_x1177); /*float64*/
    e = (_x_x1172 + _x_x1173); /*float64*/
    bool b_10040;
    double _x_x1180;
    {
      double _x_6 = z_0.num;
      _x_x1180 = _x_6; /*float64*/
    }
    b_10040 = isfinite(_x_x1180); /*bool*/
    if (b_10040) {
      double z_1;
      double _x_x1181;
      {
        double _x_6_0 = z_0.num;
        _x_x1181 = _x_6_0; /*float64*/
      }
      z_1 = (_x_x1181 + e); /*float64*/
      double err_0;
      double _x_x1182;
      double _x_x1183;
      {
        double _x_6_1 = z_0.num;
        _x_x1183 = _x_6_1; /*float64*/
      }
      _x_x1182 = (z_1 - _x_x1183); /*float64*/
      err_0 = (e - _x_x1182); /*float64*/
      double _x_x1184;
      bool _match_x947 = isfinite(z_1); /*bool*/;
      if (_match_x947) {
        _x_x1184 = err_0; /*float64*/
      }
      else {
        _x_x1184 = z_1; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(z_1, _x_x1184, _ctx);
    }
    {
      double _x_x1185;
      {
        double _x_6_2 = z_0.num;
        _x_x1185 = _x_6_2; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(_x_x1185, 0x0p+0, _ctx);
    }
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_small_exp(kk_integer_t i, kk_integer_t e, kk_context_t* _ctx) { /* (i : int, e : int) -> ddouble */ 
  double d_10112 = kk_integer_as_double(i,kk_context()); /*float64*/;
  kk_std_num_ddouble__ddouble dd = kk_std_num_ddouble__new_Ddouble(d_10112, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x945 = kk_integer_is_zero_borrow(e); /*bool*/;
  if (_match_x945) {
    kk_integer_drop(e, _ctx);
    return dd;
  }
  {
    return kk_std_num_ddouble_mul_exp10(dd, e, _ctx);
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_int_exp(kk_integer_t i, kk_integer_t e, kk_context_t* _ctx) { /* (i : int, e : int) -> ddouble */ 
  bool _match_x919 = kk_integer_gte_borrow(i,kk_std_num_ddouble_minprecise,kk_context()); /*bool*/;
  if (_match_x919) {
    bool _match_x931;
    kk_integer_t _brw_x943 = kk_integer_from_str("9007199254740991", _ctx); /*int*/;
    bool _brw_x944 = kk_integer_lte_borrow(i,_brw_x943,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x943, _ctx);
    _match_x931 = _brw_x944; /*bool*/
    if (_match_x931) {
      return kk_std_num_ddouble_small_exp(i, e, _ctx);
    }
    {
      kk_integer_t p;
      kk_integer_t _x_x1186 = kk_integer_dup(i, _ctx); /*int*/
      p = kk_std_core_int_count_digits(_x_x1186, _ctx); /*int*/
      kk_integer_t px = kk_integer_add_small_const(p, -14, _ctx); /*int*/;
      kk_std_core_types__tuple2 _match_x932;
      kk_integer_t _x_x1187 = kk_integer_dup(px, _ctx); /*int*/
      _match_x932 = kk_std_core_int_cdivmod_exp10(i, _x_x1187, _ctx); /*(int, int)*/
      {
        kk_box_t _box_x2 = _match_x932.fst;
        kk_box_t _box_x3 = _match_x932.snd;
        kk_integer_t hi = kk_integer_unbox(_box_x2, _ctx);
        kk_integer_t y_0 = kk_integer_unbox(_box_x3, _ctx);
        kk_integer_dup(hi, _ctx);
        kk_integer_dup(y_0, _ctx);
        kk_std_core_types__tuple2_drop(_match_x932, _ctx);
        kk_integer_t py;
        kk_integer_t _x_x1188 = kk_integer_dup(px, _ctx); /*int*/
        py = kk_integer_add_small_const(_x_x1188, -14, _ctx); /*int*/
        bool _match_x933 = kk_integer_lte_borrow(py,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (_match_x933) {
          kk_integer_drop(py, _ctx);
          kk_integer_t e_0_10119;
          kk_integer_t _x_x1189 = kk_integer_dup(e, _ctx); /*int*/
          e_0_10119 = kk_integer_add(px,_x_x1189,kk_context()); /*int*/
          double d_10122 = kk_integer_as_double(hi,kk_context()); /*float64*/;
          kk_std_num_ddouble__ddouble dd = kk_std_num_ddouble__new_Ddouble(d_10122, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble _x_x1190;
          bool _match_x942 = kk_integer_is_zero_borrow(e_0_10119); /*bool*/;
          if (_match_x942) {
            kk_integer_drop(e_0_10119, _ctx);
            _x_x1190 = dd; /*std/num/ddouble/ddouble*/
          }
          else {
            _x_x1190 = kk_std_num_ddouble_mul_exp10(dd, e_0_10119, _ctx); /*std/num/ddouble/ddouble*/
          }
          kk_std_num_ddouble__ddouble _x_x1191 = kk_std_num_ddouble_small_exp(y_0, e, _ctx); /*std/num/ddouble/ddouble*/
          return kk_std_num_ddouble__lp__plus__rp_(_x_x1190, _x_x1191, _ctx);
        }
        {
          kk_std_core_types__tuple2 _match_x934;
          kk_integer_t _x_x1192 = kk_integer_dup(py, _ctx); /*int*/
          _match_x934 = kk_std_core_int_cdivmod_exp10(y_0, _x_x1192, _ctx); /*(int, int)*/
          {
            kk_box_t _box_x4 = _match_x934.fst;
            kk_box_t _box_x5 = _match_x934.snd;
            kk_integer_t mid = kk_integer_unbox(_box_x4, _ctx);
            kk_integer_t z = kk_integer_unbox(_box_x5, _ctx);
            kk_integer_dup(mid, _ctx);
            kk_integer_dup(z, _ctx);
            kk_std_core_types__tuple2_drop(_match_x934, _ctx);
            kk_integer_t pz;
            kk_integer_t _x_x1193 = kk_integer_dup(py, _ctx); /*int*/
            pz = kk_integer_add_small_const(_x_x1193, -14, _ctx); /*int*/
            bool _match_x935 = kk_integer_lte_borrow(pz,(kk_integer_from_small(0)),kk_context()); /*bool*/;
            if (_match_x935) {
              kk_integer_drop(pz, _ctx);
              kk_integer_t e_1_10126;
              kk_integer_t _x_x1194 = kk_integer_dup(e, _ctx); /*int*/
              e_1_10126 = kk_integer_add(px,_x_x1194,kk_context()); /*int*/
              double d_0_10129 = kk_integer_as_double(hi,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_0 = kk_std_num_ddouble__new_Ddouble(d_0_10129, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_integer_t e_2_10131;
              kk_integer_t _x_x1195 = kk_integer_dup(e, _ctx); /*int*/
              e_2_10131 = kk_integer_add(py,_x_x1195,kk_context()); /*int*/
              double d_1_10134 = kk_integer_as_double(mid,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_1 = kk_std_num_ddouble__new_Ddouble(d_1_10134, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_integer_t e_3_10136 = kk_integer_add_small_const(e, 0, _ctx); /*int*/;
              double d_2_10139 = kk_integer_as_double(z,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_2 = kk_std_num_ddouble__new_Ddouble(d_2_10139, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_std_num_ddouble__ddouble _x_x1196;
              bool _match_x941 = kk_integer_is_zero_borrow(e_1_10126); /*bool*/;
              if (_match_x941) {
                kk_integer_drop(e_1_10126, _ctx);
                _x_x1196 = dd_0; /*std/num/ddouble/ddouble*/
              }
              else {
                _x_x1196 = kk_std_num_ddouble_mul_exp10(dd_0, e_1_10126, _ctx); /*std/num/ddouble/ddouble*/
              }
              kk_std_num_ddouble__ddouble _x_x1197;
              kk_std_num_ddouble__ddouble _x_x1198;
              bool _match_x940 = kk_integer_is_zero_borrow(e_2_10131); /*bool*/;
              if (_match_x940) {
                kk_integer_drop(e_2_10131, _ctx);
                _x_x1198 = dd_1; /*std/num/ddouble/ddouble*/
              }
              else {
                _x_x1198 = kk_std_num_ddouble_mul_exp10(dd_1, e_2_10131, _ctx); /*std/num/ddouble/ddouble*/
              }
              kk_std_num_ddouble__ddouble _x_x1199;
              bool _match_x939 = kk_integer_is_zero_borrow(e_3_10136); /*bool*/;
              if (_match_x939) {
                kk_integer_drop(e_3_10136, _ctx);
                _x_x1199 = dd_2; /*std/num/ddouble/ddouble*/
              }
              else {
                _x_x1199 = kk_std_num_ddouble_mul_exp10(dd_2, e_3_10136, _ctx); /*std/num/ddouble/ddouble*/
              }
              _x_x1197 = kk_std_num_ddouble__lp__plus__rp_(_x_x1198, _x_x1199, _ctx); /*std/num/ddouble/ddouble*/
              return kk_std_num_ddouble__lp__plus__rp_(_x_x1196, _x_x1197, _ctx);
            }
            {
              kk_integer_t lo;
              kk_integer_t _x_x1200 = kk_integer_dup(pz, _ctx); /*int*/
              lo = kk_std_core_int_cdiv_exp10(z, _x_x1200, _ctx); /*int*/
              kk_integer_t e_4_10141;
              kk_integer_t _x_x1201 = kk_integer_dup(e, _ctx); /*int*/
              e_4_10141 = kk_integer_add(px,_x_x1201,kk_context()); /*int*/
              double d_3_10144 = kk_integer_as_double(hi,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_3 = kk_std_num_ddouble__new_Ddouble(d_3_10144, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_integer_t e_5_10146;
              kk_integer_t _x_x1202 = kk_integer_dup(e, _ctx); /*int*/
              e_5_10146 = kk_integer_add(py,_x_x1202,kk_context()); /*int*/
              double d_4_10149 = kk_integer_as_double(mid,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_4 = kk_std_num_ddouble__new_Ddouble(d_4_10149, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_integer_t e_6_10151 = kk_integer_add(pz,e,kk_context()); /*int*/;
              double d_5_10154 = kk_integer_as_double(lo,kk_context()); /*float64*/;
              kk_std_num_ddouble__ddouble dd_5 = kk_std_num_ddouble__new_Ddouble(d_5_10154, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_std_num_ddouble__ddouble _x_x1203;
              bool _match_x938 = kk_integer_is_zero_borrow(e_4_10141); /*bool*/;
              if (_match_x938) {
                kk_integer_drop(e_4_10141, _ctx);
                _x_x1203 = dd_3; /*std/num/ddouble/ddouble*/
              }
              else {
                _x_x1203 = kk_std_num_ddouble_mul_exp10(dd_3, e_4_10141, _ctx); /*std/num/ddouble/ddouble*/
              }
              kk_std_num_ddouble__ddouble _x_x1204;
              kk_std_num_ddouble__ddouble _x_x1205;
              bool _match_x937 = kk_integer_is_zero_borrow(e_5_10146); /*bool*/;
              if (_match_x937) {
                kk_integer_drop(e_5_10146, _ctx);
                _x_x1205 = dd_4; /*std/num/ddouble/ddouble*/
              }
              else {
                _x_x1205 = kk_std_num_ddouble_mul_exp10(dd_4, e_5_10146, _ctx); /*std/num/ddouble/ddouble*/
              }
              kk_std_num_ddouble__ddouble _x_x1206;
              bool _match_x936 = kk_integer_is_zero_borrow(e_6_10151); /*bool*/;
              if (_match_x936) {
                kk_integer_drop(e_6_10151, _ctx);
                _x_x1206 = dd_5; /*std/num/ddouble/ddouble*/
              }
              else {
                _x_x1206 = kk_std_num_ddouble_mul_exp10(dd_5, e_6_10151, _ctx); /*std/num/ddouble/ddouble*/
              }
              _x_x1204 = kk_std_num_ddouble__lp__plus__rp_(_x_x1205, _x_x1206, _ctx); /*std/num/ddouble/ddouble*/
              return kk_std_num_ddouble__lp__plus__rp_(_x_x1203, _x_x1204, _ctx);
            }
          }
        }
      }
    }
  }
  {
    kk_integer_t p_0;
    kk_integer_t _x_x1207 = kk_integer_dup(i, _ctx); /*int*/
    p_0 = kk_std_core_int_count_digits(_x_x1207, _ctx); /*int*/
    kk_integer_t px_0 = kk_integer_add_small_const(p_0, -14, _ctx); /*int*/;
    kk_std_core_types__tuple2 _match_x920;
    kk_integer_t _x_x1208 = kk_integer_dup(px_0, _ctx); /*int*/
    _match_x920 = kk_std_core_int_cdivmod_exp10(i, _x_x1208, _ctx); /*(int, int)*/
    {
      kk_box_t _box_x6 = _match_x920.fst;
      kk_box_t _box_x7 = _match_x920.snd;
      kk_integer_t hi_0 = kk_integer_unbox(_box_x6, _ctx);
      kk_integer_t y_0_0 = kk_integer_unbox(_box_x7, _ctx);
      kk_integer_dup(hi_0, _ctx);
      kk_integer_dup(y_0_0, _ctx);
      kk_std_core_types__tuple2_drop(_match_x920, _ctx);
      kk_integer_t py_0;
      kk_integer_t _x_x1209 = kk_integer_dup(px_0, _ctx); /*int*/
      py_0 = kk_integer_add_small_const(_x_x1209, -14, _ctx); /*int*/
      bool _match_x921 = kk_integer_lte_borrow(py_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x921) {
        kk_integer_drop(py_0, _ctx);
        kk_integer_t e_0_10119_0;
        kk_integer_t _x_x1210 = kk_integer_dup(e, _ctx); /*int*/
        e_0_10119_0 = kk_integer_add(px_0,_x_x1210,kk_context()); /*int*/
        double d_10122_0 = kk_integer_as_double(hi_0,kk_context()); /*float64*/;
        kk_std_num_ddouble__ddouble dd_6 = kk_std_num_ddouble__new_Ddouble(d_10122_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble _x_x1211;
        bool _match_x930 = kk_integer_is_zero_borrow(e_0_10119_0); /*bool*/;
        if (_match_x930) {
          kk_integer_drop(e_0_10119_0, _ctx);
          _x_x1211 = dd_6; /*std/num/ddouble/ddouble*/
        }
        else {
          _x_x1211 = kk_std_num_ddouble_mul_exp10(dd_6, e_0_10119_0, _ctx); /*std/num/ddouble/ddouble*/
        }
        kk_std_num_ddouble__ddouble _x_x1212 = kk_std_num_ddouble_small_exp(y_0_0, e, _ctx); /*std/num/ddouble/ddouble*/
        return kk_std_num_ddouble__lp__plus__rp_(_x_x1211, _x_x1212, _ctx);
      }
      {
        kk_std_core_types__tuple2 _match_x922;
        kk_integer_t _x_x1213 = kk_integer_dup(py_0, _ctx); /*int*/
        _match_x922 = kk_std_core_int_cdivmod_exp10(y_0_0, _x_x1213, _ctx); /*(int, int)*/
        {
          kk_box_t _box_x8 = _match_x922.fst;
          kk_box_t _box_x9 = _match_x922.snd;
          kk_integer_t mid_0 = kk_integer_unbox(_box_x8, _ctx);
          kk_integer_t z_0 = kk_integer_unbox(_box_x9, _ctx);
          kk_integer_dup(mid_0, _ctx);
          kk_integer_dup(z_0, _ctx);
          kk_std_core_types__tuple2_drop(_match_x922, _ctx);
          kk_integer_t pz_0;
          kk_integer_t _x_x1214 = kk_integer_dup(py_0, _ctx); /*int*/
          pz_0 = kk_integer_add_small_const(_x_x1214, -14, _ctx); /*int*/
          bool _match_x923 = kk_integer_lte_borrow(pz_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
          if (_match_x923) {
            kk_integer_drop(pz_0, _ctx);
            kk_integer_t e_1_10126_0;
            kk_integer_t _x_x1215 = kk_integer_dup(e, _ctx); /*int*/
            e_1_10126_0 = kk_integer_add(px_0,_x_x1215,kk_context()); /*int*/
            double d_0_10129_0 = kk_integer_as_double(hi_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_0_0 = kk_std_num_ddouble__new_Ddouble(d_0_10129_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_integer_t e_2_10131_0;
            kk_integer_t _x_x1216 = kk_integer_dup(e, _ctx); /*int*/
            e_2_10131_0 = kk_integer_add(py_0,_x_x1216,kk_context()); /*int*/
            double d_1_10134_0 = kk_integer_as_double(mid_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_1_0 = kk_std_num_ddouble__new_Ddouble(d_1_10134_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_integer_t e_3_10136_0 = kk_integer_add_small_const(e, 0, _ctx); /*int*/;
            double d_2_10139_0 = kk_integer_as_double(z_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_2_0 = kk_std_num_ddouble__new_Ddouble(d_2_10139_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_std_num_ddouble__ddouble _x_x1217;
            bool _match_x929 = kk_integer_is_zero_borrow(e_1_10126_0); /*bool*/;
            if (_match_x929) {
              kk_integer_drop(e_1_10126_0, _ctx);
              _x_x1217 = dd_0_0; /*std/num/ddouble/ddouble*/
            }
            else {
              _x_x1217 = kk_std_num_ddouble_mul_exp10(dd_0_0, e_1_10126_0, _ctx); /*std/num/ddouble/ddouble*/
            }
            kk_std_num_ddouble__ddouble _x_x1218;
            kk_std_num_ddouble__ddouble _x_x1219;
            bool _match_x928 = kk_integer_is_zero_borrow(e_2_10131_0); /*bool*/;
            if (_match_x928) {
              kk_integer_drop(e_2_10131_0, _ctx);
              _x_x1219 = dd_1_0; /*std/num/ddouble/ddouble*/
            }
            else {
              _x_x1219 = kk_std_num_ddouble_mul_exp10(dd_1_0, e_2_10131_0, _ctx); /*std/num/ddouble/ddouble*/
            }
            kk_std_num_ddouble__ddouble _x_x1220;
            bool _match_x927 = kk_integer_is_zero_borrow(e_3_10136_0); /*bool*/;
            if (_match_x927) {
              kk_integer_drop(e_3_10136_0, _ctx);
              _x_x1220 = dd_2_0; /*std/num/ddouble/ddouble*/
            }
            else {
              _x_x1220 = kk_std_num_ddouble_mul_exp10(dd_2_0, e_3_10136_0, _ctx); /*std/num/ddouble/ddouble*/
            }
            _x_x1218 = kk_std_num_ddouble__lp__plus__rp_(_x_x1219, _x_x1220, _ctx); /*std/num/ddouble/ddouble*/
            return kk_std_num_ddouble__lp__plus__rp_(_x_x1217, _x_x1218, _ctx);
          }
          {
            kk_integer_t lo_0;
            kk_integer_t _x_x1221 = kk_integer_dup(pz_0, _ctx); /*int*/
            lo_0 = kk_std_core_int_cdiv_exp10(z_0, _x_x1221, _ctx); /*int*/
            kk_integer_t e_4_10141_0;
            kk_integer_t _x_x1222 = kk_integer_dup(e, _ctx); /*int*/
            e_4_10141_0 = kk_integer_add(px_0,_x_x1222,kk_context()); /*int*/
            double d_3_10144_0 = kk_integer_as_double(hi_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_3_0 = kk_std_num_ddouble__new_Ddouble(d_3_10144_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_integer_t e_5_10146_0;
            kk_integer_t _x_x1223 = kk_integer_dup(e, _ctx); /*int*/
            e_5_10146_0 = kk_integer_add(py_0,_x_x1223,kk_context()); /*int*/
            double d_4_10149_0 = kk_integer_as_double(mid_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_4_0 = kk_std_num_ddouble__new_Ddouble(d_4_10149_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_integer_t e_6_10151_0 = kk_integer_add(pz_0,e,kk_context()); /*int*/;
            double d_5_10154_0 = kk_integer_as_double(lo_0,kk_context()); /*float64*/;
            kk_std_num_ddouble__ddouble dd_5_0 = kk_std_num_ddouble__new_Ddouble(d_5_10154_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_std_num_ddouble__ddouble _x_x1224;
            bool _match_x926 = kk_integer_is_zero_borrow(e_4_10141_0); /*bool*/;
            if (_match_x926) {
              kk_integer_drop(e_4_10141_0, _ctx);
              _x_x1224 = dd_3_0; /*std/num/ddouble/ddouble*/
            }
            else {
              _x_x1224 = kk_std_num_ddouble_mul_exp10(dd_3_0, e_4_10141_0, _ctx); /*std/num/ddouble/ddouble*/
            }
            kk_std_num_ddouble__ddouble _x_x1225;
            kk_std_num_ddouble__ddouble _x_x1226;
            bool _match_x925 = kk_integer_is_zero_borrow(e_5_10146_0); /*bool*/;
            if (_match_x925) {
              kk_integer_drop(e_5_10146_0, _ctx);
              _x_x1226 = dd_4_0; /*std/num/ddouble/ddouble*/
            }
            else {
              _x_x1226 = kk_std_num_ddouble_mul_exp10(dd_4_0, e_5_10146_0, _ctx); /*std/num/ddouble/ddouble*/
            }
            kk_std_num_ddouble__ddouble _x_x1227;
            bool _match_x924 = kk_integer_is_zero_borrow(e_6_10151_0); /*bool*/;
            if (_match_x924) {
              kk_integer_drop(e_6_10151_0, _ctx);
              _x_x1227 = dd_5_0; /*std/num/ddouble/ddouble*/
            }
            else {
              _x_x1227 = kk_std_num_ddouble_mul_exp10(dd_5_0, e_6_10151_0, _ctx); /*std/num/ddouble/ddouble*/
            }
            _x_x1225 = kk_std_num_ddouble__lp__plus__rp_(_x_x1226, _x_x1227, _ctx); /*std/num/ddouble/ddouble*/
            return kk_std_num_ddouble__lp__plus__rp_(_x_x1224, _x_x1225, _ctx);
          }
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_11162_fun1235__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11162_fun1235(kk_function_t _fself, kk_box_t _b_x15, kk_box_t _b_x16, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_11162_fun1235(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_11162_fun1235, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11162_fun1235(kk_function_t _fself, kk_box_t _b_x15, kk_box_t _b_x16, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1236;
  kk_integer_t _x_x1237 = kk_integer_unbox(_b_x15, _ctx); /*int*/
  kk_integer_t _x_x1238 = kk_integer_unbox(_b_x16, _ctx); /*int*/
  _x_x1236 = kk_std_num_ddouble_ddouble_int_exp(_x_x1237, _x_x1238, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1236, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11162(kk_string_t frac, bool neg, kk_string_t whole, kk_integer_t _c_x11107, kk_context_t* _ctx) { /* (frac : string, neg : bool, whole : string, int) -> ddouble */ 
  kk_string_t _x_x1_0_11148;
  kk_string_t _x_x1228;
  if (neg) {
    kk_define_string_literal(, _s_x1229, 1, "-", _ctx)
    _x_x1228 = kk_string_dup(_s_x1229, _ctx); /*string*/
  }
  else {
    _x_x1228 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x1231;
  kk_string_t _x_x1232 = kk_string_dup(frac, _ctx); /*string*/
  _x_x1231 = kk_std_core_types__lp__plus__plus__rp_(whole, _x_x1232, _ctx); /*string*/
  _x_x1_0_11148 = kk_std_core_types__lp__plus__plus__rp_(_x_x1228, _x_x1231, _ctx); /*string*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_core_types__maybe x;
  bool _x_x1233;
  kk_std_core_types__optional _match_x918 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x918, _ctx)) {
    kk_box_t _box_x10 = _match_x918._cons._Optional.value;
    bool _uniq_hex_581 = kk_bool_unbox(_box_x10);
    kk_std_core_types__optional_drop(_match_x918, _ctx);
    _x_x1233 = _uniq_hex_581; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x918, _ctx);
    _x_x1233 = false; /*bool*/
  }
  x = kk_std_core_int_xparse(_x_x1_0_11148, _x_x1233, _ctx); /*maybe<int>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_integer_t y_11129 = kk_std_core_string_chars_fs_count(frac, _ctx); /*int*/;
  kk_integer_t e = kk_integer_sub(_c_x11107,y_11129,kk_context()); /*int*/;
  kk_box_t _x_x1234;
  kk_box_t _x_x1239;
  kk_integer_t _x_x1240;
  if (kk_std_core_types__is_Nothing(x, _ctx)) {
    _x_x1240 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_box_t _box_x11 = x._cons.Just.value;
    kk_integer_t x_1 = kk_integer_unbox(_box_x11, _ctx);
    kk_integer_dup(x_1, _ctx);
    kk_std_core_types__maybe_drop(x, _ctx);
    _x_x1240 = x_1; /*int*/
  }
  _x_x1239 = kk_integer_box(_x_x1240, _ctx); /*10000*/
  _x_x1234 = kk_std_core_hnd__open_none2(kk_std_num_ddouble__new_mlift_pddouble_normal_11162_fun1235(_ctx), _x_x1239, kk_integer_box(e, _ctx), _ctx); /*10002*/
  return kk_std_num_ddouble__ddouble_unbox(_x_x1234, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1242__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1242(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_11163_fun1242(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1242, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1242(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1243;
  kk_char_t _x_x1244 = kk_char_unbox(_b_x21, KK_OWNED, _ctx); /*char*/
  _x_x1243 = kk_std_num_ddouble__mlift_pddouble_normal_11161(_x_x1244, _ctx); /*int*/
  return kk_integer_box(_x_x1243, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1246__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1246(kk_function_t _fself, kk_box_t _b_x24, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_11163_fun1246(kk_string_t frac, kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1246__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1246__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1246, kk_context());
  _self->frac = frac;
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1246(kk_function_t _fself, kk_box_t _b_x24, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1246__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_normal_11163_fun1246__t*, _fself, _ctx);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(frac, _ctx);kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_integer_t _c_x11107_26 = kk_integer_unbox(_b_x24, _ctx); /*int*/;
  kk_std_num_ddouble__ddouble _x_x1247 = kk_std_num_ddouble__mlift_pddouble_normal_11162(frac, neg, whole, _c_x11107_26, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1247, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11163(kk_string_t frac, bool neg, kk_string_t whole, bool _y_x11104, kk_context_t* _ctx) { /* (frac : string, neg : bool, whole : string, bool) -> std/text/parse/parse ddouble */ 
  kk_integer_t x_11186;
  if (_y_x11104) {
    kk_char_t x_0_11188 = kk_std_text_parse_char('e', _ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1241 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_11163_fun1242(_ctx), _ctx); /*10001*/
      x_11186 = kk_integer_unbox(_x_x1241, _ctx); /*int*/
    }
    else {
      x_11186 = kk_std_text_parse_pint(_ctx); /*int*/
    }
  }
  else {
    x_11186 = kk_integer_from_small(0); /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11186, _ctx);
    kk_box_t _x_x1245 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_11163_fun1246(frac, whole, neg, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1245, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_ddouble__mlift_pddouble_normal_11162(frac, neg, whole, x_11186, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_11165_fun1253__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11165_fun1253(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_11165_fun1253(kk_string_t frac, kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_11165_fun1253__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_normal_11165_fun1253__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_normal_11165_fun1253, kk_context());
  _self->frac = frac;
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11165_fun1253(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_11165_fun1253__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_normal_11165_fun1253__t*, _fself, _ctx);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(frac, _ctx);kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  bool _y_x11104_36 = kk_bool_unbox(_b_x34); /*bool*/;
  kk_std_num_ddouble__ddouble _x_x1254 = kk_std_num_ddouble__mlift_pddouble_normal_11163(frac, neg, whole, _y_x11104_36, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1254, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11165(bool neg, kk_string_t whole, kk_string_t _c_x11103, kk_context_t* _ctx) { /* (neg : bool, whole : string, string) -> ddouble */ 
  kk_string_t frac;
  kk_string_t _x_x1248;
  kk_define_string_literal(, _s_x1249, 1, "0", _ctx)
  _x_x1248 = kk_string_dup(_s_x1249, _ctx); /*string*/
  frac = kk_std_core_sslice_trim_right(_c_x11103, _x_x1248, _ctx); /*string*/
  kk_std_core_hnd__ev ev_11192 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_11190;
  kk_box_t _x_x1250;
  {
    struct kk_std_core_hnd_Ev* _con_x1251 = kk_std_core_hnd__as_Ev(ev_11192, _ctx);
    kk_box_t _box_x27 = _con_x1251->hnd;
    int32_t m = _con_x1251->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x27, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x914;
    kk_std_core_hnd__clause0 _brw_x915 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x914 = _brw_x915; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x30 = _match_x914.clause;
      _x_x1250 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x30, (_fun_unbox_x30, m, ev_11192, _ctx), _ctx); /*10005*/
    }
  }
  x_11190 = kk_bool_unbox(_x_x1250); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1252 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_11165_fun1253(frac, whole, neg, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1252, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_ddouble__mlift_pddouble_normal_11163(frac, neg, whole, x_11190, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1256__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1256(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_11166_fun1256(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1256, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1256(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1257;
  kk_char_t _x_x1258 = kk_char_unbox(_b_x38, KK_OWNED, _ctx); /*char*/
  _x_x1257 = kk_std_num_ddouble__mlift_pddouble_normal_11164(_x_x1258, _ctx); /*string*/
  return kk_string_box(_x_x1257);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1261__t {
  struct kk_function_s _base;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1261(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_11166_fun1261(kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1261__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1261__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1261, kk_context());
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1261(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1261__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_normal_11166_fun1261__t*, _fself, _ctx);
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_string_t _c_x11103_43 = kk_string_unbox(_b_x41); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1262 = kk_std_num_ddouble__mlift_pddouble_normal_11165(neg, whole, _c_x11103_43, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1262, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11166(bool neg, kk_string_t whole, bool _y_x11100, kk_context_t* _ctx) { /* (neg : bool, whole : string, bool) -> std/text/parse/parse ddouble */ 
  kk_string_t x_11194;
  if (_y_x11100) {
    kk_char_t x_0_11196 = kk_std_text_parse_char('.', _ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1255 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_11166_fun1256(_ctx), _ctx); /*10001*/
      x_11194 = kk_string_unbox(_x_x1255); /*string*/
    }
    else {
      x_11194 = kk_std_text_parse_digits(_ctx); /*string*/
    }
  }
  else {
    x_11194 = kk_string_empty(); /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_11194, _ctx);
    kk_box_t _x_x1260 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_11166_fun1261(whole, neg, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1260, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_ddouble__mlift_pddouble_normal_11165(neg, whole, x_11194, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_11167_fun1266__t {
  struct kk_function_s _base;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11167_fun1266(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_11167_fun1266(kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_11167_fun1266__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_normal_11167_fun1266__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_normal_11167_fun1266, kk_context());
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11167_fun1266(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_11167_fun1266__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_normal_11167_fun1266__t*, _fself, _ctx);
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  bool _y_x11100_53 = kk_bool_unbox(_b_x51); /*bool*/;
  kk_std_num_ddouble__ddouble _x_x1267 = kk_std_num_ddouble__mlift_pddouble_normal_11166(neg, whole, _y_x11100_53, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1267, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11167(bool neg, kk_string_t whole, kk_context_t* _ctx) { /* (neg : bool, whole : string) -> std/text/parse/parse ddouble */ 
  kk_std_core_hnd__ev ev_11200 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_11198;
  kk_box_t _x_x1263;
  {
    struct kk_std_core_hnd_Ev* _con_x1264 = kk_std_core_hnd__as_Ev(ev_11200, _ctx);
    kk_box_t _box_x44 = _con_x1264->hnd;
    int32_t m = _con_x1264->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x44, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x909;
    kk_std_core_hnd__clause0 _brw_x910 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x909 = _brw_x910; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x47 = _match_x909.clause;
      _x_x1263 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x47, (_fun_unbox_x47, m, ev_11200, _ctx), _ctx); /*10005*/
    }
  }
  x_11198 = kk_bool_unbox(_x_x1263); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1265 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_11167_fun1266(whole, neg, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1265, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_ddouble__mlift_pddouble_normal_11166(neg, whole, x_11198, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_normal_11168_fun1269__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11168_fun1269(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_normal_11168_fun1269(bool neg, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_11168_fun1269__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_normal_11168_fun1269__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_normal_11168_fun1269, kk_context());
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_normal_11168_fun1269(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_normal_11168_fun1269__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_normal_11168_fun1269__t*, _fself, _ctx);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_string_t whole_57 = kk_string_unbox(_b_x55); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1270 = kk_std_num_ddouble__mlift_pddouble_normal_11167(neg, whole_57, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1270, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11168(bool neg, kk_context_t* _ctx) { /* (neg : bool) -> std/text/parse/parse ddouble */ 
  kk_string_t x_11202 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_11202, _ctx);
    kk_box_t _x_x1268 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_normal_11168_fun1269(neg, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1268, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_ddouble__mlift_pddouble_normal_11167(neg, x_11202, _ctx);
  }
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1272__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1272(kk_function_t _fself, kk_box_t _b_x59, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1272(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1272, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1272(kk_function_t _fself, kk_box_t _b_x59, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1273;
  bool _x_x1274 = kk_bool_unbox(_b_x59); /*bool*/
  _x_x1273 = kk_std_num_ddouble__mlift_pddouble_normal_11168(_x_x1274, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1273, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1276__t {
  struct kk_function_s _base;
  bool x_11204;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1276(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1276(bool x_11204, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1276__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_normal_fun1276__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_normal_fun1276, kk_context());
  _self->x_11204 = x_11204;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1276(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1276__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_normal_fun1276__t*, _fself, _ctx);
  bool x_11204 = _self->x_11204; /* bool */
  kk_drop_match(_self, {kk_skip_dup(x_11204, _ctx);}, {}, _ctx)
  kk_string_t whole_104 = kk_string_unbox(_b_x61); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1277 = kk_std_num_ddouble__mlift_pddouble_normal_11167(x_11204, whole_104, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1277, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1281__t {
  struct kk_function_s _base;
  kk_string_t x_0_11207;
  bool x_11204;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1281(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1281(kk_string_t x_0_11207, bool x_11204, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1281__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_normal_fun1281__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_normal_fun1281, kk_context());
  _self->x_0_11207 = x_0_11207;
  _self->x_11204 = x_11204;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1281(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1281__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_normal_fun1281__t*, _fself, _ctx);
  kk_string_t x_0_11207 = _self->x_0_11207; /* string */
  bool x_11204 = _self->x_11204; /* bool */
  kk_drop_match(_self, {kk_string_dup(x_0_11207, _ctx);kk_skip_dup(x_11204, _ctx);}, {}, _ctx)
  bool _y_x11100_105 = kk_bool_unbox(_b_x69); /*bool*/;
  kk_std_num_ddouble__ddouble _x_x1282 = kk_std_num_ddouble__mlift_pddouble_normal_11166(x_11204, x_0_11207, _y_x11100_105, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1282, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1284__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1284(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1284(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1284, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1284(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1285;
  kk_char_t _x_x1286 = kk_char_unbox(_b_x71, KK_OWNED, _ctx); /*char*/
  _x_x1285 = kk_std_num_ddouble__mlift_pddouble_normal_11164(_x_x1286, _ctx); /*string*/
  return kk_string_box(_x_x1285);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1289__t {
  struct kk_function_s _base;
  kk_string_t x_0_11207;
  bool x_11204;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1289(kk_function_t _fself, kk_box_t _b_x74, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1289(kk_string_t x_0_11207, bool x_11204, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1289__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_normal_fun1289__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_normal_fun1289, kk_context());
  _self->x_0_11207 = x_0_11207;
  _self->x_11204 = x_11204;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1289(kk_function_t _fself, kk_box_t _b_x74, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1289__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_normal_fun1289__t*, _fself, _ctx);
  kk_string_t x_0_11207 = _self->x_0_11207; /* string */
  bool x_11204 = _self->x_11204; /* bool */
  kk_drop_match(_self, {kk_string_dup(x_0_11207, _ctx);kk_skip_dup(x_11204, _ctx);}, {}, _ctx)
  kk_string_t _c_x11103_106 = kk_string_unbox(_b_x74); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1290 = kk_std_num_ddouble__mlift_pddouble_normal_11165(x_11204, x_0_11207, _c_x11103_106, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1290, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1296__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t x_0_11207;
  bool x_11204;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1296(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1296(kk_string_t frac, kk_string_t x_0_11207, bool x_11204, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1296__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_normal_fun1296__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_normal_fun1296, kk_context());
  _self->frac = frac;
  _self->x_0_11207 = x_0_11207;
  _self->x_11204 = x_11204;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1296(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1296__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_normal_fun1296__t*, _fself, _ctx);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t x_0_11207 = _self->x_0_11207; /* string */
  bool x_11204 = _self->x_11204; /* bool */
  kk_drop_match(_self, {kk_string_dup(frac, _ctx);kk_string_dup(x_0_11207, _ctx);kk_skip_dup(x_11204, _ctx);}, {}, _ctx)
  bool _y_x11104_107 = kk_bool_unbox(_b_x82); /*bool*/;
  kk_std_num_ddouble__ddouble _x_x1297 = kk_std_num_ddouble__mlift_pddouble_normal_11163(frac, x_11204, x_0_11207, _y_x11104_107, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1297, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1299__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1299(kk_function_t _fself, kk_box_t _b_x84, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1299(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1299, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1299(kk_function_t _fself, kk_box_t _b_x84, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1300;
  kk_char_t _x_x1301 = kk_char_unbox(_b_x84, KK_OWNED, _ctx); /*char*/
  _x_x1300 = kk_std_num_ddouble__mlift_pddouble_normal_11161(_x_x1301, _ctx); /*int*/
  return kk_integer_box(_x_x1300, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1303__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t x_0_11207;
  bool x_11204;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1303(kk_function_t _fself, kk_box_t _b_x87, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1303(kk_string_t frac, kk_string_t x_0_11207, bool x_11204, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1303__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_normal_fun1303__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_normal_fun1303, kk_context());
  _self->frac = frac;
  _self->x_0_11207 = x_0_11207;
  _self->x_11204 = x_11204;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1303(kk_function_t _fself, kk_box_t _b_x87, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun1303__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_normal_fun1303__t*, _fself, _ctx);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t x_0_11207 = _self->x_0_11207; /* string */
  bool x_11204 = _self->x_11204; /* bool */
  kk_drop_match(_self, {kk_string_dup(frac, _ctx);kk_string_dup(x_0_11207, _ctx);kk_skip_dup(x_11204, _ctx);}, {}, _ctx)
  kk_integer_t _c_x11107_108 = kk_integer_unbox(_b_x87, _ctx); /*int*/;
  kk_std_num_ddouble__ddouble _x_x1304 = kk_std_num_ddouble__mlift_pddouble_normal_11162(frac, x_11204, x_0_11207, _c_x11107_108, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1304, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun1312__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1312(kk_function_t _fself, kk_box_t _b_x93, kk_box_t _b_x94, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun1312(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun1312, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun1312(kk_function_t _fself, kk_box_t _b_x93, kk_box_t _b_x94, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1313;
  kk_integer_t _x_x1314 = kk_integer_unbox(_b_x93, _ctx); /*int*/
  kk_integer_t _x_x1315 = kk_integer_unbox(_b_x94, _ctx); /*int*/
  _x_x1313 = kk_std_num_ddouble_ddouble_int_exp(_x_x1314, _x_x1315, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1313, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_normal(kk_context_t* _ctx) { /* () -> std/text/parse/parse ddouble */ 
  bool x_11204 = kk_std_text_parse_sign(_ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1271 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1272(_ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1271, KK_OWNED, _ctx);
  }
  {
    kk_string_t x_0_11207 = kk_std_text_parse_digits(_ctx); /*string*/;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_11207, _ctx);
      kk_box_t _x_x1275 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1276(x_11204, _ctx), _ctx); /*10001*/
      return kk_std_num_ddouble__ddouble_unbox(_x_x1275, KK_OWNED, _ctx);
    }
    {
      kk_std_core_hnd__ev ev_11213 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      bool x_1_11210;
      kk_box_t _x_x1278;
      {
        struct kk_std_core_hnd_Ev* _con_x1279 = kk_std_core_hnd__as_Ev(ev_11213, _ctx);
        kk_box_t _box_x62 = _con_x1279->hnd;
        int32_t m = _con_x1279->marker;
        kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x62, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h, _ctx);
        kk_std_core_hnd__clause0 _match_x905;
        kk_std_core_hnd__clause0 _brw_x906 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
        kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
        _match_x905 = _brw_x906; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
        {
          kk_function_t _fun_unbox_x65 = _match_x905.clause;
          _x_x1278 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x65, (_fun_unbox_x65, m, ev_11213, _ctx), _ctx); /*10005*/
        }
      }
      x_1_11210 = kk_bool_unbox(_x_x1278); /*bool*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1280 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1281(x_0_11207, x_11204, _ctx), _ctx); /*10001*/
        return kk_std_num_ddouble__ddouble_unbox(_x_x1280, KK_OWNED, _ctx);
      }
      {
        kk_string_t x_2_11215;
        if (x_1_11210) {
          kk_char_t x_3_11218 = kk_std_text_parse_char('.', _ctx); /*char*/;
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1283 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1284(_ctx), _ctx); /*10001*/
            x_2_11215 = kk_string_unbox(_x_x1283); /*string*/
          }
          else {
            x_2_11215 = kk_std_text_parse_digits(_ctx); /*string*/
          }
        }
        else {
          x_2_11215 = kk_string_empty(); /*string*/
        }
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_2_11215, _ctx);
          kk_box_t _x_x1288 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1289(x_0_11207, x_11204, _ctx), _ctx); /*10001*/
          return kk_std_num_ddouble__ddouble_unbox(_x_x1288, KK_OWNED, _ctx);
        }
        {
          kk_string_t frac;
          kk_string_t _x_x1291;
          kk_define_string_literal(, _s_x1292, 1, "0", _ctx)
          _x_x1291 = kk_string_dup(_s_x1292, _ctx); /*string*/
          frac = kk_std_core_sslice_trim_right(x_2_11215, _x_x1291, _ctx); /*string*/
          kk_std_core_hnd__ev ev_0_11223 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
          bool x_4_11220;
          kk_box_t _x_x1293;
          {
            struct kk_std_core_hnd_Ev* _con_x1294 = kk_std_core_hnd__as_Ev(ev_0_11223, _ctx);
            kk_box_t _box_x75 = _con_x1294->hnd;
            int32_t m_0 = _con_x1294->marker;
            kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x75, KK_BORROWED, _ctx);
            kk_std_text_parse__parse_dup(h_0, _ctx);
            kk_std_core_hnd__clause0 _match_x902;
            kk_std_core_hnd__clause0 _brw_x903 = kk_std_text_parse_pick_fs__select(h_0, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
            kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
            _match_x902 = _brw_x903; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
            {
              kk_function_t _fun_unbox_x78 = _match_x902.clause;
              _x_x1293 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x78, (_fun_unbox_x78, m_0, ev_0_11223, _ctx), _ctx); /*10005*/
            }
          }
          x_4_11220 = kk_bool_unbox(_x_x1293); /*bool*/
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1295 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1296(frac, x_0_11207, x_11204, _ctx), _ctx); /*10001*/
            return kk_std_num_ddouble__ddouble_unbox(_x_x1295, KK_OWNED, _ctx);
          }
          {
            kk_integer_t x_5_11225;
            if (x_4_11220) {
              kk_char_t x_6_11228 = kk_std_text_parse_char('e', _ctx); /*char*/;
              if (kk_yielding(kk_context())) {
                kk_box_t _x_x1298 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1299(_ctx), _ctx); /*10001*/
                x_5_11225 = kk_integer_unbox(_x_x1298, _ctx); /*int*/
              }
              else {
                x_5_11225 = kk_std_text_parse_pint(_ctx); /*int*/
              }
            }
            else {
              x_5_11225 = kk_integer_from_small(0); /*int*/
            }
            if (kk_yielding(kk_context())) {
              kk_integer_drop(x_5_11225, _ctx);
              kk_box_t _x_x1302 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun1303(frac, x_0_11207, x_11204, _ctx), _ctx); /*10001*/
              return kk_std_num_ddouble__ddouble_unbox(_x_x1302, KK_OWNED, _ctx);
            }
            {
              kk_string_t _x_x1_0_11148;
              kk_string_t _x_x1305;
              if (x_11204) {
                kk_define_string_literal(, _s_x1306, 1, "-", _ctx)
                _x_x1305 = kk_string_dup(_s_x1306, _ctx); /*string*/
              }
              else {
                _x_x1305 = kk_string_empty(); /*string*/
              }
              kk_string_t _x_x1308;
              kk_string_t _x_x1309 = kk_string_dup(frac, _ctx); /*string*/
              _x_x1308 = kk_std_core_types__lp__plus__plus__rp_(x_0_11207, _x_x1309, _ctx); /*string*/
              _x_x1_0_11148 = kk_std_core_types__lp__plus__plus__rp_(_x_x1305, _x_x1308, _ctx); /*string*/
              kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
              kk_std_core_types__maybe x_7;
              bool _x_x1310;
              kk_std_core_types__optional _match_x900 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
              if (kk_std_core_types__is_Optional(_match_x900, _ctx)) {
                kk_box_t _box_x88 = _match_x900._cons._Optional.value;
                bool _uniq_hex_581 = kk_bool_unbox(_box_x88);
                kk_std_core_types__optional_drop(_match_x900, _ctx);
                _x_x1310 = _uniq_hex_581; /*bool*/
              }
              else {
                kk_std_core_types__optional_drop(_match_x900, _ctx);
                _x_x1310 = false; /*bool*/
              }
              x_7 = kk_std_core_int_xparse(_x_x1_0_11148, _x_x1310, _ctx); /*maybe<int>*/
              kk_unit_t keep = kk_Unit;
              kk_evv_set(w,kk_context());
              kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
              kk_unit_t keep_0 = kk_Unit;
              kk_evv_set(w_0,kk_context());
              kk_integer_t y_11129 = kk_std_core_string_chars_fs_count(frac, _ctx); /*int*/;
              kk_integer_t e = kk_integer_sub(x_5_11225,y_11129,kk_context()); /*int*/;
              kk_box_t _x_x1311;
              kk_box_t _x_x1316;
              kk_integer_t _x_x1317;
              if (kk_std_core_types__is_Nothing(x_7, _ctx)) {
                _x_x1317 = kk_integer_from_small(0); /*int*/
              }
              else {
                kk_box_t _box_x89 = x_7._cons.Just.value;
                kk_integer_t x_9 = kk_integer_unbox(_box_x89, _ctx);
                kk_integer_dup(x_9, _ctx);
                kk_std_core_types__maybe_drop(x_7, _ctx);
                _x_x1317 = x_9; /*int*/
              }
              _x_x1316 = kk_integer_box(_x_x1317, _ctx); /*10000*/
              _x_x1311 = kk_std_core_hnd__open_none2(kk_std_num_ddouble_new_pddouble_normal_fun1312(_ctx), _x_x1316, kk_integer_box(e, _ctx), _ctx); /*10002*/
              return kk_std_num_ddouble__ddouble_unbox(_x_x1311, KK_OWNED, _ctx);
            }
          }
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_sum_11170_fun1321__t {
  struct kk_function_s _base;
  double hi;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_11170_fun1321(kk_function_t _fself, kk_box_t _b_x110, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_sum_11170_fun1321(double hi, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_sum_11170_fun1321__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_sum_11170_fun1321__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_sum_11170_fun1321, kk_context());
  _self->hi = hi;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_11170_fun1321(kk_function_t _fself, kk_box_t _b_x110, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_sum_11170_fun1321__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_sum_11170_fun1321__t*, _fself, _ctx);
  double hi = _self->hi; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(hi, _ctx);}, {}, _ctx)
  double lo_112 = kk_double_unbox(_b_x110, KK_OWNED, _ctx); /*float64*/;
  kk_std_num_ddouble__ddouble _x_x1322 = kk_std_num_ddouble__mlift_pddouble_sum_11169(hi, lo_112, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1322, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_sum_11170(double hi, kk_string_t wild___0, kk_context_t* _ctx) { /* (hi : float64, wild_@0 : string) -> std/text/parse/parse ddouble */ 
  kk_string_drop(wild___0, _ctx);
  double x_11239 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1320 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_sum_11170_fun1321(hi, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1320, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_ddouble__mlift_pddouble_sum_11169(hi, x_11239, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_sum_11171_fun1326__t {
  struct kk_function_s _base;
  double hi;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_11171_fun1326(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_sum_11171_fun1326(double hi, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_sum_11171_fun1326__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_sum_11171_fun1326__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_sum_11171_fun1326, kk_context());
  _self->hi = hi;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_sum_11171_fun1326(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_sum_11171_fun1326__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_sum_11171_fun1326__t*, _fself, _ctx);
  double hi = _self->hi; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(hi, _ctx);}, {}, _ctx)
  kk_string_t wild___0_116 = kk_string_unbox(_b_x114); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1327 = kk_std_num_ddouble__mlift_pddouble_sum_11170(hi, wild___0_116, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1327, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_sum_11171(double hi, kk_context_t* _ctx) { /* (hi : float64) -> std/text/parse/parse ddouble */ 
  bool _x_x1_11152 = isfinite(hi); /*bool*/;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  if (_x_x1_11152) {
    kk_string_t x_0_11243;
    kk_string_t _x_x1323;
    kk_define_string_literal(, _s_x1324, 3, " + ", _ctx)
    _x_x1323 = kk_string_dup(_s_x1324, _ctx); /*string*/
    x_0_11243 = kk_std_text_parse_pstring(_x_x1323, _ctx); /*string*/
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_11243, _ctx);
      kk_box_t _x_x1325 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_sum_11171_fun1326(hi, _ctx), _ctx); /*10001*/
      return kk_std_num_ddouble__ddouble_unbox(_x_x1325, KK_OWNED, _ctx);
    }
    {
      return kk_std_num_ddouble__mlift_pddouble_sum_11170(hi, x_0_11243, _ctx);
    }
  }
  {
    return kk_std_num_ddouble__new_Ddouble(hi, 0x0p+0, _ctx);
  }
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun1329__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1329(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun1329(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_sum_fun1329, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1329(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1330;
  double _x_x1331 = kk_double_unbox(_b_x118, KK_OWNED, _ctx); /*float64*/
  _x_x1330 = kk_std_num_ddouble__mlift_pddouble_sum_11171(_x_x1331, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1330, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun1335__t {
  struct kk_function_s _base;
  double x_11245;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1335(kk_function_t _fself, kk_box_t _b_x120, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun1335(double x_11245, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun1335__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_sum_fun1335__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_sum_fun1335, kk_context());
  _self->x_11245 = x_11245;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1335(kk_function_t _fself, kk_box_t _b_x120, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun1335__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_sum_fun1335__t*, _fself, _ctx);
  double x_11245 = _self->x_11245; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(x_11245, _ctx);}, {}, _ctx)
  kk_string_t wild___0_126 = kk_string_unbox(_b_x120); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1336 = kk_std_num_ddouble__mlift_pddouble_sum_11170(x_11245, wild___0_126, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1336, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun1338__t {
  struct kk_function_s _base;
  double x_11245;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1338(kk_function_t _fself, kk_box_t _b_x122, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun1338(double x_11245, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun1338__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_sum_fun1338__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_sum_fun1338, kk_context());
  _self->x_11245 = x_11245;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun1338(kk_function_t _fself, kk_box_t _b_x122, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun1338__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_sum_fun1338__t*, _fself, _ctx);
  double x_11245 = _self->x_11245; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(x_11245, _ctx);}, {}, _ctx)
  double lo_127 = kk_double_unbox(_b_x122, KK_OWNED, _ctx); /*float64*/;
  kk_std_num_ddouble__ddouble _x_x1339 = kk_std_num_ddouble__mlift_pddouble_sum_11169(x_11245, lo_127, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1339, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_sum(kk_context_t* _ctx) { /* () -> std/text/parse/parse ddouble */ 
  double x_11245 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1328 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_sum_fun1329(_ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1328, KK_OWNED, _ctx);
  }
  {
    bool _x_x1_11152 = isfinite(x_11245); /*bool*/;
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    if (_x_x1_11152) {
      kk_string_t x_1_11250;
      kk_string_t _x_x1332;
      kk_define_string_literal(, _s_x1333, 3, " + ", _ctx)
      _x_x1332 = kk_string_dup(_s_x1333, _ctx); /*string*/
      x_1_11250 = kk_std_text_parse_pstring(_x_x1332, _ctx); /*string*/
      kk_string_drop(x_1_11250, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1334 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_sum_fun1335(x_11245, _ctx), _ctx); /*10001*/
        return kk_std_num_ddouble__ddouble_unbox(_x_x1334, KK_OWNED, _ctx);
      }
      {
        double x_2_11253 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x1337 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_sum_fun1338(x_11245, _ctx), _ctx); /*10001*/
          return kk_std_num_ddouble__ddouble_unbox(_x_x1337, KK_OWNED, _ctx);
        }
        {
          kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
          kk_std_num_ddouble__ddouble x_3;
          kk_std_num_ddouble__ddouble _x_x1340 = kk_std_num_ddouble__new_Ddouble(x_11245, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x1341 = kk_std_num_ddouble__new_Ddouble(x_2_11253, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          x_3 = kk_std_num_ddouble__lp__plus__rp_(_x_x1340, _x_x1341, _ctx); /*std/num/ddouble/ddouble*/
          kk_unit_t keep_0 = kk_Unit;
          kk_evv_set(w_0,kk_context());
          return x_3;
        }
      }
    }
    {
      return kk_std_num_ddouble__new_Ddouble(x_11245, 0x0p+0, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_11173_fun1345__t {
  struct kk_function_s _base;
  double hi;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_11173_fun1345(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_11173_fun1345(double hi, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_11173_fun1345__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_11173_fun1345__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_11173_fun1345, kk_context());
  _self->hi = hi;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_11173_fun1345(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_11173_fun1345__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_11173_fun1345__t*, _fself, _ctx);
  double hi = _self->hi; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(hi, _ctx);}, {}, _ctx)
  double lo_131 = kk_double_unbox(_b_x129, KK_OWNED, _ctx); /*float64*/;
  kk_std_num_ddouble__ddouble _x_x1346 = kk_std_num_ddouble__mlift_pddouble_11172(hi, lo_131, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1346, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_11173(double hi, kk_string_t wild___0, kk_context_t* _ctx) { /* (hi : float64, wild_@0 : string) -> std/text/parse/parse ddouble */ 
  kk_string_drop(wild___0, _ctx);
  double x_11262 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1344 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_11173_fun1345(hi, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1344, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_ddouble__mlift_pddouble_11172(hi, x_11262, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_11174_fun1350__t {
  struct kk_function_s _base;
  double hi;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_11174_fun1350(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_11174_fun1350(double hi, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_11174_fun1350__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_pddouble_11174_fun1350__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_pddouble_11174_fun1350, kk_context());
  _self->hi = hi;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_11174_fun1350(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_pddouble_11174_fun1350__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_pddouble_11174_fun1350__t*, _fself, _ctx);
  double hi = _self->hi; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(hi, _ctx);}, {}, _ctx)
  kk_string_t wild___0_135 = kk_string_unbox(_b_x133); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1351 = kk_std_num_ddouble__mlift_pddouble_11173(hi, wild___0_135, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1351, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_11174(double hi, kk_context_t* _ctx) { /* (hi : float64) -> std/text/parse/parse ddouble */ 
  bool _x_x1_11155 = isfinite(hi); /*bool*/;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  if (_x_x1_11155) {
    kk_string_t x_0_11266;
    kk_string_t _x_x1347;
    kk_define_string_literal(, _s_x1348, 3, " + ", _ctx)
    _x_x1347 = kk_string_dup(_s_x1348, _ctx); /*string*/
    x_0_11266 = kk_std_text_parse_pstring(_x_x1347, _ctx); /*string*/
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_11266, _ctx);
      kk_box_t _x_x1349 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_11174_fun1350(hi, _ctx), _ctx); /*10001*/
      return kk_std_num_ddouble__ddouble_unbox(_x_x1349, KK_OWNED, _ctx);
    }
    {
      return kk_std_num_ddouble__mlift_pddouble_11173(hi, x_0_11266, _ctx);
    }
  }
  {
    return kk_std_num_ddouble__new_Ddouble(hi, 0x0p+0, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_pddouble_11175_fun1353__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_pddouble_11175_fun1353(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_pddouble_11175_fun1353(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_pddouble_11175_fun1353, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_pddouble_11175_fun1353(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1354;
  double _x_x1355 = kk_double_unbox(_b_x137, KK_OWNED, _ctx); /*float64*/
  _x_x1354 = kk_std_num_ddouble__mlift_pddouble_11174(_x_x1355, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1354, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_11175(bool _y_x11112, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse ddouble */ 
  if (_y_x11112) {
    double x_11268 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1352 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_pddouble_11175_fun1353(_ctx), _ctx); /*10001*/
      return kk_std_num_ddouble__ddouble_unbox(_x_x1352, KK_OWNED, _ctx);
    }
    {
      return kk_std_num_ddouble__mlift_pddouble_11174(x_11268, _ctx);
    }
  }
  {
    return kk_std_num_ddouble_pddouble_normal(_ctx);
  }
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_fun1359__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_fun1359(kk_function_t _fself, kk_box_t _b_x146, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_fun1359(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_fun1359, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_fun1359(kk_function_t _fself, kk_box_t _b_x146, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1360;
  bool _x_x1361 = kk_bool_unbox(_b_x146); /*bool*/
  _x_x1360 = kk_std_num_ddouble__mlift_pddouble_11175(_x_x1361, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1360, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_fun1363__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_fun1363(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_fun1363(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_fun1363, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_fun1363(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1364;
  double _x_x1365 = kk_double_unbox(_b_x148, KK_OWNED, _ctx); /*float64*/
  _x_x1364 = kk_std_num_ddouble__mlift_pddouble_11174(_x_x1365, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1364, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_fun1369__t {
  struct kk_function_s _base;
  double x_0_11275;
};
static kk_box_t kk_std_num_ddouble_pddouble_fun1369(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_fun1369(double x_0_11275, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_fun1369__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_fun1369__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_fun1369, kk_context());
  _self->x_0_11275 = x_0_11275;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_fun1369(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_fun1369__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_fun1369__t*, _fself, _ctx);
  double x_0_11275 = _self->x_0_11275; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(x_0_11275, _ctx);}, {}, _ctx)
  kk_string_t wild___0_157 = kk_string_unbox(_b_x150); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1370 = kk_std_num_ddouble__mlift_pddouble_11173(x_0_11275, wild___0_157, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1370, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_fun1372__t {
  struct kk_function_s _base;
  double x_0_11275;
};
static kk_box_t kk_std_num_ddouble_pddouble_fun1372(kk_function_t _fself, kk_box_t _b_x152, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_fun1372(double x_0_11275, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_fun1372__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_fun1372__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble_pddouble_fun1372, kk_context());
  _self->x_0_11275 = x_0_11275;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble_pddouble_fun1372(kk_function_t _fself, kk_box_t _b_x152, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_fun1372__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_fun1372__t*, _fself, _ctx);
  double x_0_11275 = _self->x_0_11275; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(x_0_11275, _ctx);}, {}, _ctx)
  double lo_158 = kk_double_unbox(_b_x152, KK_OWNED, _ctx); /*float64*/;
  kk_std_num_ddouble__ddouble _x_x1373 = kk_std_num_ddouble__mlift_pddouble_11172(x_0_11275, lo_158, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1373, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse ddouble */ 
  kk_std_core_hnd__ev ev_11273 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_11270;
  kk_box_t _x_x1356;
  {
    struct kk_std_core_hnd_Ev* _con_x1357 = kk_std_core_hnd__as_Ev(ev_11273, _ctx);
    kk_box_t _box_x139 = _con_x1357->hnd;
    int32_t m = _con_x1357->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x139, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x884;
    kk_std_core_hnd__clause0 _brw_x885 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x884 = _brw_x885; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x142 = _match_x884.clause;
      _x_x1356 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x142, (_fun_unbox_x142, m, ev_11273, _ctx), _ctx); /*10005*/
    }
  }
  x_11270 = kk_bool_unbox(_x_x1356); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1358 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_fun1359(_ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1358, KK_OWNED, _ctx);
  }
  if (x_11270) {
    double x_0_11275 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1362 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_fun1363(_ctx), _ctx); /*10001*/
      return kk_std_num_ddouble__ddouble_unbox(_x_x1362, KK_OWNED, _ctx);
    }
    {
      bool _x_x1_11155 = isfinite(x_0_11275); /*bool*/;
      kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
      kk_unit_t keep = kk_Unit;
      kk_evv_set(w,kk_context());
      if (_x_x1_11155) {
        kk_string_t x_2_11280;
        kk_string_t _x_x1366;
        kk_define_string_literal(, _s_x1367, 3, " + ", _ctx)
        _x_x1366 = kk_string_dup(_s_x1367, _ctx); /*string*/
        x_2_11280 = kk_std_text_parse_pstring(_x_x1366, _ctx); /*string*/
        kk_string_drop(x_2_11280, _ctx);
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x1368 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_fun1369(x_0_11275, _ctx), _ctx); /*10001*/
          return kk_std_num_ddouble__ddouble_unbox(_x_x1368, KK_OWNED, _ctx);
        }
        {
          double x_3_11283 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1371 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_fun1372(x_0_11275, _ctx), _ctx); /*10001*/
            return kk_std_num_ddouble__ddouble_unbox(_x_x1371, KK_OWNED, _ctx);
          }
          {
            kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
            kk_std_num_ddouble__ddouble x_4;
            kk_std_num_ddouble__ddouble _x_x1374 = kk_std_num_ddouble__new_Ddouble(x_0_11275, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
            kk_std_num_ddouble__ddouble _x_x1375 = kk_std_num_ddouble__new_Ddouble(x_3_11283, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
            x_4 = kk_std_num_ddouble__lp__plus__rp_(_x_x1374, _x_x1375, _ctx); /*std/num/ddouble/ddouble*/
            kk_unit_t keep_0 = kk_Unit;
            kk_evv_set(w_0,kk_context());
            return x_4;
          }
        }
      }
      {
        return kk_std_num_ddouble__new_Ddouble(x_0_11275, 0x0p+0, _ctx);
      }
    }
  }
  {
    return kk_std_num_ddouble_pddouble_normal(_ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_parse_ddouble_11177_fun1379__t {
  struct kk_function_s _base;
  double hi;
};
static kk_box_t kk_std_num_ddouble__mlift_parse_ddouble_11177_fun1379(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_parse_ddouble_11177_fun1379(double hi, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_parse_ddouble_11177_fun1379__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_parse_ddouble_11177_fun1379__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_parse_ddouble_11177_fun1379, kk_context());
  _self->hi = hi;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_parse_ddouble_11177_fun1379(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_parse_ddouble_11177_fun1379__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_parse_ddouble_11177_fun1379__t*, _fself, _ctx);
  double hi = _self->hi; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(hi, _ctx);}, {}, _ctx)
  double lo_162 = kk_double_unbox(_b_x160, KK_OWNED, _ctx); /*float64*/;
  kk_std_num_ddouble__ddouble _x_x1380 = kk_std_num_ddouble__mlift_parse_ddouble_11176(hi, lo_162, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1380, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_parse_ddouble_11177(double hi, kk_string_t wild___0, kk_context_t* _ctx) { /* (hi : float64, wild_@0 : string) -> std/text/parse/parse ddouble */ 
  kk_string_drop(wild___0, _ctx);
  double x_11292 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1378 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_parse_ddouble_11177_fun1379(hi, _ctx), _ctx); /*10001*/
    return kk_std_num_ddouble__ddouble_unbox(_x_x1378, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_ddouble__mlift_parse_ddouble_11176(hi, x_11292, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_parse_ddouble_11178_fun1384__t {
  struct kk_function_s _base;
  double hi;
};
static kk_box_t kk_std_num_ddouble__mlift_parse_ddouble_11178_fun1384(kk_function_t _fself, kk_box_t _b_x164, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_parse_ddouble_11178_fun1384(double hi, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_parse_ddouble_11178_fun1384__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift_parse_ddouble_11178_fun1384__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_ddouble__mlift_parse_ddouble_11178_fun1384, kk_context());
  _self->hi = hi;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_parse_ddouble_11178_fun1384(kk_function_t _fself, kk_box_t _b_x164, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift_parse_ddouble_11178_fun1384__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift_parse_ddouble_11178_fun1384__t*, _fself, _ctx);
  double hi = _self->hi; /* float64 */
  kk_drop_match(_self, {kk_skip_dup(hi, _ctx);}, {}, _ctx)
  kk_string_t wild___0_166 = kk_string_unbox(_b_x164); /*string*/;
  kk_std_num_ddouble__ddouble _x_x1385 = kk_std_num_ddouble__mlift_parse_ddouble_11177(hi, wild___0_166, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1385, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_parse_ddouble_11178(double hi, kk_context_t* _ctx) { /* (hi : float64) -> std/text/parse/parse ddouble */ 
  bool _x_x1_11158 = isfinite(hi); /*bool*/;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  if (_x_x1_11158) {
    kk_string_t x_0_11296;
    kk_string_t _x_x1381;
    kk_define_string_literal(, _s_x1382, 3, " + ", _ctx)
    _x_x1381 = kk_string_dup(_s_x1382, _ctx); /*string*/
    x_0_11296 = kk_std_text_parse_pstring(_x_x1381, _ctx); /*string*/
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_11296, _ctx);
      kk_box_t _x_x1383 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_parse_ddouble_11178_fun1384(hi, _ctx), _ctx); /*10001*/
      return kk_std_num_ddouble__ddouble_unbox(_x_x1383, KK_OWNED, _ctx);
    }
    {
      return kk_std_num_ddouble__mlift_parse_ddouble_11177(hi, x_0_11296, _ctx);
    }
  }
  {
    return kk_std_num_ddouble__new_Ddouble(hi, 0x0p+0, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift_parse_ddouble_11179_fun1387__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift_parse_ddouble_11179_fun1387(kk_function_t _fself, kk_box_t _b_x168, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift_parse_ddouble_11179_fun1387(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift_parse_ddouble_11179_fun1387, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble__mlift_parse_ddouble_11179_fun1387(kk_function_t _fself, kk_box_t _b_x168, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1388;
  double _x_x1389 = kk_double_unbox(_b_x168, KK_OWNED, _ctx); /*float64*/
  _x_x1388 = kk_std_num_ddouble__mlift_parse_ddouble_11178(_x_x1389, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1388, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_parse_ddouble_11179(bool _y_x11119, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse ddouble */ 
  if (_y_x11119) {
    double x_11298 = kk_std_num_float64_pdouble(_ctx); /*float64*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1386 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift_parse_ddouble_11179_fun1387(_ctx), _ctx); /*10001*/
      return kk_std_num_ddouble__ddouble_unbox(_x_x1386, KK_OWNED, _ctx);
    }
    {
      return kk_std_num_ddouble__mlift_parse_ddouble_11178(x_11298, _ctx);
    }
  }
  {
    return kk_std_num_ddouble_pddouble_normal(_ctx);
  }
}


// lift anonymous function
struct kk_std_num_ddouble_parse_ddouble_fun1394__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1394(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_parse_ddouble_fun1394(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_parse_ddouble_fun1394, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_ddouble_parse_ddouble_fun1399__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1399(kk_function_t _fself, kk_box_t _b_x177, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_parse_ddouble_fun1399(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_parse_ddouble_fun1399, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1399(kk_function_t _fself, kk_box_t _b_x177, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1400;
  bool _x_x1401 = kk_bool_unbox(_b_x177); /*bool*/
  _x_x1400 = kk_std_num_ddouble__mlift_parse_ddouble_11179(_x_x1401, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1400, _ctx);
}
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun1394(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_hnd__ev ev_11302 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_11300;
  kk_box_t _x_x1395;
  {
    struct kk_std_core_hnd_Ev* _con_x1396 = kk_std_core_hnd__as_Ev(ev_11302, _ctx);
    kk_box_t _box_x170 = _con_x1396->hnd;
    int32_t m = _con_x1396->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x170, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x875;
    kk_std_core_hnd__clause0 _brw_x876 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x875 = _brw_x876; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x173 = _match_x875.clause;
      _x_x1395 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x173, (_fun_unbox_x173, m, ev_11302, _ctx), _ctx); /*10005*/
    }
  }
  x_11300 = kk_bool_unbox(_x_x1395); /*bool*/
  kk_std_num_ddouble__ddouble _x_x1397;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1398 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_parse_ddouble_fun1399(_ctx), _ctx); /*10001*/
    _x_x1397 = kk_std_num_ddouble__ddouble_unbox(_x_x1398, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    _x_x1397 = kk_std_num_ddouble__mlift_parse_ddouble_11179(x_11300, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__ddouble_box(_x_x1397, _ctx);
}

kk_std_core_types__maybe kk_std_num_ddouble_parse_ddouble(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<ddouble> */ 
  kk_string_t s_0_10160;
  kk_string_t _x_x1390;
  kk_string_t _x_x1391 = kk_string_trim_left(s,kk_context()); /*string*/
  _x_x1390 = kk_string_trim_right(_x_x1391,kk_context()); /*string*/
  s_0_10160 = kk_std_core_string_to_lower(_x_x1390, _ctx); /*string*/
  kk_std_core_sslice__sslice _b_x178_180;
  kk_string_t _x_x1392 = kk_string_dup(s_0_10160, _ctx); /*string*/
  kk_integer_t _x_x1393 = kk_string_len_int(s_0_10160,kk_context()); /*int*/
  _b_x178_180 = kk_std_core_sslice__new_Sslice(_x_x1392, kk_integer_from_small(0), _x_x1393, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10159 = kk_std_text_parse_parse_eof(_b_x178_180, kk_std_num_ddouble_new_parse_ddouble_fun1394(_ctx), _ctx); /*std/text/parse/parse-error<std/num/ddouble/ddouble>*/;
  if (kk_std_text_parse__is_ParseOk(perr_10159, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x1402 = kk_std_text_parse__as_ParseOk(perr_10159, _ctx);
    kk_box_t _box_x183 = _con_x1402->result;
    kk_std_core_sslice__sslice _pat_0_0_0 = _con_x1402->rest;
    kk_std_num_ddouble__ddouble x_0 = kk_std_num_ddouble__ddouble_unbox(_box_x183, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10159, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0_0, _ctx);
      kk_box_drop(_box_x183, _ctx);
      kk_datatype_ptr_free(perr_10159, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10159, _ctx);
    }
    return kk_std_core_types__new_Just(kk_std_num_ddouble__ddouble_box(x_0, _ctx), _ctx);
  }
  {
    struct kk_std_text_parse_ParseError* _con_x1403 = kk_std_text_parse__as_ParseError(perr_10159, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x1403->rest;
    kk_string_t msg = _con_x1403->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10159, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr_10159, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10159, _ctx);
    }
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Zero constant

kk_std_num_ddouble__ddouble kk_std_num_ddouble_zero;
 
// lifted local: list/@lift-sum@11070, list/sum, @spec-x10975
// specialized: std/core/list/@unroll-foreach@10016, on parameters @uniq-action@10970, using:
// @uniq-action@10970 = fn<((local :: H -> X)<(h :: H)>)>(x: std/num/ddouble/ddouble){
//   val t : std/num/ddouble/ddouble;
//   val x@2@10170 : std/num/ddouble/ddouble;
//   val x@0@10168 : std/num/ddouble/ddouble;
//   val y@10169 : std/num/ddouble/ddouble;
//   val x@1@10174 : order;
//   val c : std/num/ddouble/ddouble;
//   val _ : ();
//   std/core/types/local-set<std/num/ddouble/ddouble,(total :: E),(h :: H)>(total, t);
// }

kk_unit_t kk_std_num_ddouble_list_fs__lift_sum_11071(kk_ref_t comp, kk_ref_t total, kk_std_core_types__list _uniq_xs_10969, kk_context_t* _ctx) { /* forall<h> (comp : local-var<h,ddouble>, total : local-var<h,ddouble>, list<ddouble>) -> (local<h>) () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10969, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1411 = kk_std_core_types__as_Cons(_uniq_xs_10969, _ctx);
    kk_box_t _box_x187 = _con_x1411->head;
    kk_std_core_types__list _uniq_xx_10973 = _con_x1411->tail;
    kk_std_num_ddouble__ddouble _uniq_x_10972 = kk_std_num_ddouble__ddouble_unbox(_box_x187, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10969, _ctx)) {
      kk_box_drop(_box_x187, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10969, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_10973, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10969, _ctx);
    }
    kk_std_num_ddouble__ddouble t;
    kk_std_num_ddouble__ddouble _x_x1412;
    kk_box_t _x_x1413;
    kk_ref_t _x_x1414 = kk_ref_dup(total, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
    _x_x1413 = kk_ref_get(_x_x1414,kk_context()); /*10000*/
    _x_x1412 = kk_std_num_ddouble__ddouble_unbox(_x_x1413, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    t = kk_std_num_ddouble__lp__plus__rp_(_x_x1412, _uniq_x_10972, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble x_2_10170;
    kk_box_t _x_x1415;
    kk_ref_t _x_x1416 = kk_ref_dup(total, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
    _x_x1415 = kk_ref_get(_x_x1416,kk_context()); /*10000*/
    x_2_10170 = kk_std_num_ddouble__ddouble_unbox(_x_x1415, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble x_0_10168;
    bool _match_x873;
    double _x_x1417;
    {
      double _x = x_2_10170.hi;
      _x_x1417 = _x; /*float64*/
    }
    _match_x873 = (_x_x1417 < (0x0p+0)); /*bool*/
    if (_match_x873) {
      double _x_x1418;
      double _x_x1419;
      {
        double _x_0 = x_2_10170.hi;
        _x_x1419 = _x_0; /*float64*/
      }
      _x_x1418 = (-_x_x1419); /*float64*/
      double _x_x1420;
      double _x_x1421;
      {
        double _x_0_0 = x_2_10170.lo;
        _x_x1421 = _x_0_0; /*float64*/
      }
      _x_x1420 = (-_x_x1421); /*float64*/
      x_0_10168 = kk_std_num_ddouble__new_Ddouble(_x_x1418, _x_x1420, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      x_0_10168 = x_2_10170; /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble y_10169 = kk_std_num_ddouble_abs(_uniq_x_10972, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core_types__order x_1_10174;
    kk_std_core_types__order _match_x872;
    double _x_x1422;
    {
      double _x_1 = x_0_10168.hi;
      _x_x1422 = _x_1; /*float64*/
    }
    double _x_x1423;
    {
      double _x_0_1 = y_10169.hi;
      _x_x1423 = _x_0_1; /*float64*/
    }
    _match_x872 = kk_std_num_float64_cmp(_x_x1422, _x_x1423, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x872, _ctx)) {
      double _x_x1424;
      {
        double _x_1_0 = x_0_10168.lo;
        _x_x1424 = _x_1_0; /*float64*/
      }
      double _x_x1425;
      {
        double _x_2 = y_10169.lo;
        _x_x1425 = _x_2; /*float64*/
      }
      x_1_10174 = kk_std_num_float64_cmp(_x_x1424, _x_x1425, _ctx); /*order*/
    }
    else {
      x_1_10174 = _match_x872; /*order*/
    }
    kk_std_num_ddouble__ddouble c;
    bool _match_x869;
    kk_integer_t _brw_x870;
    if (kk_std_core_types__is_Lt(x_1_10174, _ctx)) {
      _brw_x870 = kk_integer_from_small(-1); /*int*/
      goto _match_x1426;
    }
    if (kk_std_core_types__is_Eq(x_1_10174, _ctx)) {
      _brw_x870 = kk_integer_from_small(0); /*int*/
      goto _match_x1426;
    }
    {
      _brw_x870 = kk_integer_from_small(1); /*int*/
    }
    _match_x1426: ;
    bool _brw_x871 = kk_integer_neq_borrow(_brw_x870,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x870, _ctx);
    _match_x869 = _brw_x871; /*bool*/
    if (_match_x869) {
      kk_std_num_ddouble__ddouble x_4_10176;
      kk_box_t _x_x1427;
      kk_ref_t _x_x1428 = kk_ref_dup(total, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
      _x_x1427 = kk_ref_get(_x_x1428,kk_context()); /*10000*/
      x_4_10176 = kk_std_num_ddouble__ddouble_unbox(_x_x1427, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1429;
      kk_std_num_ddouble__ddouble _x_x1430;
      double _x_x1431;
      double _x_x1432;
      {
        double _x_3 = t.hi;
        _x_x1432 = _x_3; /*float64*/
      }
      _x_x1431 = (-_x_x1432); /*float64*/
      double _x_x1433;
      double _x_x1434;
      {
        double _x_0_2 = t.lo;
        _x_x1434 = _x_0_2; /*float64*/
      }
      _x_x1433 = (-_x_x1434); /*float64*/
      _x_x1430 = kk_std_num_ddouble__new_Ddouble(_x_x1431, _x_x1433, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1429 = kk_std_num_ddouble__lp__plus__rp_(x_4_10176, _x_x1430, _ctx); /*std/num/ddouble/ddouble*/
      c = kk_std_num_ddouble__lp__plus__rp_(_x_x1429, _uniq_x_10972, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x1435;
      kk_std_num_ddouble__ddouble _x_x1436;
      double _x_x1437;
      double _x_x1438;
      {
        double _x_4 = t.hi;
        _x_x1438 = _x_4; /*float64*/
      }
      _x_x1437 = (-_x_x1438); /*float64*/
      double _x_x1439;
      double _x_x1440;
      {
        double _x_0_3 = t.lo;
        _x_x1440 = _x_0_3; /*float64*/
      }
      _x_x1439 = (-_x_x1440); /*float64*/
      _x_x1436 = kk_std_num_ddouble__new_Ddouble(_x_x1437, _x_x1439, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1435 = kk_std_num_ddouble__lp__plus__rp_(_uniq_x_10972, _x_x1436, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1441;
      kk_box_t _x_x1442;
      kk_ref_t _x_x1443 = kk_ref_dup(total, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
      _x_x1442 = kk_ref_get(_x_x1443,kk_context()); /*10000*/
      _x_x1441 = kk_std_num_ddouble__ddouble_unbox(_x_x1442, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
      c = kk_std_num_ddouble__lp__plus__rp_(_x_x1435, _x_x1441, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble _b_x207_209;
    kk_std_num_ddouble__ddouble _x_x1444;
    kk_box_t _x_x1445;
    kk_ref_t _x_x1446 = kk_ref_dup(comp, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
    _x_x1445 = kk_ref_get(_x_x1446,kk_context()); /*10000*/
    _x_x1444 = kk_std_num_ddouble__ddouble_unbox(_x_x1445, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    _b_x207_209 = kk_std_num_ddouble__lp__plus__rp_(_x_x1444, c, _ctx); /*std/num/ddouble/ddouble*/
    kk_unit_t __ = kk_Unit;
    kk_ref_set_borrow(comp,(kk_std_num_ddouble__ddouble_box(_b_x207_209, _ctx)),kk_context());
    kk_ref_set_borrow(total,(kk_std_num_ddouble__ddouble_box(t, _ctx)),kk_context());
    { // tailcall
      _uniq_xs_10969 = _uniq_xx_10973;
      goto kk__tailcall;
    }
  }
  {
    kk_ref_drop(total, _ctx);
    kk_ref_drop(comp, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// lifted local: list/sum, @spec-x10968
// specialized: std/core/list/foreach, on parameters @uniq-action@10965, using:
// @uniq-action@10965 = fn<((local :: H -> X)<(h :: H)>)>(x: std/num/ddouble/ddouble){
//   val t : std/num/ddouble/ddouble;
//   val x@2@10170 : std/num/ddouble/ddouble;
//   val x@0@10168 : std/num/ddouble/ddouble;
//   val y@10169 : std/num/ddouble/ddouble;
//   val x@1@10174 : order;
//   val c : std/num/ddouble/ddouble;
//   val _ : ();
//   std/core/types/local-set<std/num/ddouble/ddouble,(total :: E),(h :: H)>(total, t);
// }

kk_unit_t kk_std_num_ddouble_list_fs__lift_sum_11070(kk_ref_t comp, kk_ref_t total, kk_std_core_types__list _uniq_xs_10964, kk_context_t* _ctx) { /* forall<h> (comp : local-var<h,ddouble>, total : local-var<h,ddouble>, list<ddouble>) -> (local<h>) () */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10964, _ctx)) {
    kk_ref_drop(total, _ctx);
    kk_ref_drop(comp, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_std_num_ddouble_list_fs__lift_sum_11071(comp, total, _uniq_xs_10964, _ctx); return kk_Unit;
  }
}
 
// Return the sum of a list of doubles.
// Uses [Kahan-Babu&scaron;kan-Neumaier summation](https://en.wikipedia.org/wiki/Kahan_summation_algorithm#Further_enhancements)
// to minimize rounding errors. This
// is more precise as Kahan summation and about as fast.
// `[1.0e3,1.0e97,1.0e3,-1.0e97].sum == 2000.0`
// A. Neumaier, _Rundungsfehleranalyse einiger Verfahren zur Summation endlicher Summen_.
// Math. Mechanik, 54:39--51, 1974.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs_sum(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<ddouble>) -> ddouble */ 
  kk_ref_t loc = kk_ref_alloc((kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx)),kk_context()); /*local-var<2804,std/num/ddouble/ddouble>*/;
  kk_ref_t loc_0 = kk_ref_alloc((kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx)),kk_context()); /*local-var<2804,std/num/ddouble/ddouble>*/;
  kk_unit_t ___0 = kk_Unit;
  kk_ref_t _x_x1447 = kk_ref_dup(loc_0, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
  kk_ref_t _x_x1448 = kk_ref_dup(loc, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
  kk_std_num_ddouble_list_fs__lift_sum_11070(_x_x1447, _x_x1448, xs, _ctx);
  kk_std_num_ddouble__ddouble res_0;
  kk_std_num_ddouble__ddouble _x_x1449;
  kk_box_t _x_x1450;
  kk_ref_t _x_x1451 = kk_ref_dup(loc, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
  _x_x1450 = kk_ref_get(_x_x1451,kk_context()); /*10000*/
  _x_x1449 = kk_std_num_ddouble__ddouble_unbox(_x_x1450, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1452;
  kk_box_t _x_x1453;
  kk_ref_t _x_x1454 = kk_ref_dup(loc_0, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
  _x_x1453 = kk_ref_get(_x_x1454,kk_context()); /*10000*/
  _x_x1452 = kk_std_num_ddouble__ddouble_unbox(_x_x1453, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  res_0 = kk_std_num_ddouble__lp__plus__rp_(_x_x1449, _x_x1452, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble res;
  kk_box_t _x_x1455 = kk_std_core_hnd_prompt_local_var(loc_0, kk_std_num_ddouble__ddouble_box(res_0, _ctx), _ctx); /*10001*/
  res = kk_std_num_ddouble__ddouble_unbox(_x_x1455, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_box_t _x_x1456 = kk_std_core_hnd_prompt_local_var(loc, kk_std_num_ddouble__ddouble_box(res, _ctx), _ctx); /*10001*/
  return kk_std_num_ddouble__ddouble_unbox(_x_x1456, KK_OWNED, _ctx);
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

bool kk_std_num_ddouble__lp__gt__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x_0_10188;
  kk_std_core_types__order _match_x867;
  double _x_x1463;
  {
    double _x = x.hi;
    _x_x1463 = _x; /*float64*/
  }
  double _x_x1464;
  {
    double _x_0 = y.hi;
    _x_x1464 = _x_0; /*float64*/
  }
  _match_x867 = kk_std_num_float64_cmp(_x_x1463, _x_x1464, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x867, _ctx)) {
    double _x_x1465;
    {
      double _x_1 = x.lo;
      _x_x1465 = _x_1; /*float64*/
    }
    double _x_x1466;
    {
      double _x_2 = y.lo;
      _x_x1466 = _x_2; /*float64*/
    }
    x_0_10188 = kk_std_num_float64_cmp(_x_x1465, _x_x1466, _ctx); /*order*/
  }
  else {
    x_0_10188 = _match_x867; /*order*/
  }
  kk_integer_t _brw_x865;
  if (kk_std_core_types__is_Lt(x_0_10188, _ctx)) {
    _brw_x865 = kk_integer_from_small(-1); /*int*/
    goto _match_x1467;
  }
  if (kk_std_core_types__is_Eq(x_0_10188, _ctx)) {
    _brw_x865 = kk_integer_from_small(0); /*int*/
    goto _match_x1467;
  }
  {
    _brw_x865 = kk_integer_from_small(1); /*int*/
  }
  _match_x1467: ;
  bool _brw_x866 = kk_integer_eq_borrow(_brw_x865,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x865, _ctx);
  return _brw_x866;
}

bool kk_std_num_ddouble__lp__lt__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x_0_10190;
  kk_std_core_types__order _match_x864;
  double _x_x1468;
  {
    double _x = x.hi;
    _x_x1468 = _x; /*float64*/
  }
  double _x_x1469;
  {
    double _x_0 = y.hi;
    _x_x1469 = _x_0; /*float64*/
  }
  _match_x864 = kk_std_num_float64_cmp(_x_x1468, _x_x1469, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x864, _ctx)) {
    double _x_x1470;
    {
      double _x_1 = x.lo;
      _x_x1470 = _x_1; /*float64*/
    }
    double _x_x1471;
    {
      double _x_2 = y.lo;
      _x_x1471 = _x_2; /*float64*/
    }
    x_0_10190 = kk_std_num_float64_cmp(_x_x1470, _x_x1471, _ctx); /*order*/
  }
  else {
    x_0_10190 = _match_x864; /*order*/
  }
  kk_integer_t _brw_x862;
  if (kk_std_core_types__is_Lt(x_0_10190, _ctx)) {
    _brw_x862 = kk_integer_from_small(-1); /*int*/
    goto _match_x1472;
  }
  if (kk_std_core_types__is_Eq(x_0_10190, _ctx)) {
    _brw_x862 = kk_integer_from_small(0); /*int*/
    goto _match_x1472;
  }
  {
    _brw_x862 = kk_integer_from_small(1); /*int*/
  }
  _match_x1472: ;
  bool _brw_x863 = kk_integer_eq_borrow(_brw_x862,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x862, _ctx);
  return _brw_x863;
}

kk_std_num_ddouble__edouble kk_std_num_ddouble_edouble_fs__copy(kk_std_num_ddouble__edouble _this, kk_std_core_types__optional num, kk_std_core_types__optional err, kk_context_t* _ctx) { /* (edouble, num : ? float64, err : ? float64) -> edouble */ 
  double _x_x1475;
  if (kk_std_core_types__is_Optional(num, _ctx)) {
    kk_box_t _box_x236 = num._cons._Optional.value;
    double _uniq_num_3869 = kk_double_unbox(_box_x236, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(num, _ctx);
    _x_x1475 = _uniq_num_3869; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(num, _ctx);
    {
      double _x = _this.num;
      _x_x1475 = _x; /*float64*/
    }
  }
  double _x_x1476;
  if (kk_std_core_types__is_Optional(err, _ctx)) {
    kk_box_t _box_x237 = err._cons._Optional.value;
    double _uniq_err_3877 = kk_double_unbox(_box_x237, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(err, _ctx);
    _x_x1476 = _uniq_err_3877; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(err, _ctx);
    {
      double _x_0 = _this.err;
      _x_x1476 = _x_0; /*float64*/
    }
  }
  return kk_std_num_ddouble__new_Edouble(_x_x1475, _x_x1476, _ctx);
}
 
// Round a `:ddouble` to the nearest integer, rounding to the nearest even number in case of a tie.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_round(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double r;
  double _x_x1477;
  {
    double _x = x.hi;
    _x_x1477 = _x; /*float64*/
  }
  r = kk_double_round_even(_x_x1477,kk_context()); /*float64*/
  double diff;
  double _x_x1478;
  {
    double _x_0 = x.hi;
    _x_x1478 = _x_0; /*float64*/
  }
  diff = (r - _x_x1478); /*float64*/
  bool _match_x850 = (diff == (0x0p+0)); /*bool*/;
  if (_match_x850) {
    double y_10199;
    double _x_x1479;
    {
      double _x_1 = x.lo;
      _x_x1479 = _x_1; /*float64*/
    }
    y_10199 = kk_double_round_even(_x_x1479,kk_context()); /*float64*/
    bool b_10201 = isfinite(r); /*bool*/;
    if (b_10201) {
      double z = (r + y_10199); /*float64*/;
      double err;
      double _x_x1480 = (z - r); /*float64*/
      err = (y_10199 - _x_x1480); /*float64*/
      double _x_x1481;
      bool _match_x857 = isfinite(z); /*bool*/;
      if (_match_x857) {
        _x_x1481 = err; /*float64*/
      }
      else {
        _x_x1481 = z; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(z, _x_x1481, _ctx);
    }
    {
      return kk_std_num_ddouble__new_Ddouble(r, 0x0p+0, _ctx);
    }
  }
  {
    double d_0_10203;
    bool _match_x851 = (diff == (0x1p-1)); /*bool*/;
    if (_match_x851) {
      bool _match_x854;
      double _x_x1482;
      {
        double _x_2 = x.lo;
        _x_x1482 = _x_2; /*float64*/
      }
      _match_x854 = (_x_x1482 < (0x0p+0)); /*bool*/
      if (_match_x854) {
        d_0_10203 = (r - 0x1p0); /*float64*/
      }
      else {
        bool _match_x855 = (diff == (-0x1p-1)); /*bool*/;
        if (_match_x855) {
          bool _match_x856;
          double _x_x1483;
          {
            double _x_3 = x.lo;
            _x_x1483 = _x_3; /*float64*/
          }
          _match_x856 = (_x_x1483 > (0x0p+0)); /*bool*/
          if (_match_x856) {
            d_0_10203 = (r + 0x1p0); /*float64*/
          }
          else {
            d_0_10203 = r; /*float64*/
          }
        }
        else {
          d_0_10203 = r; /*float64*/
        }
      }
    }
    else {
      bool _match_x852 = (diff == (-0x1p-1)); /*bool*/;
      if (_match_x852) {
        bool _match_x853;
        double _x_x1484;
        {
          double _x_4 = x.lo;
          _x_x1484 = _x_4; /*float64*/
        }
        _match_x853 = (_x_x1484 > (0x0p+0)); /*bool*/
        if (_match_x853) {
          d_0_10203 = (r + 0x1p0); /*float64*/
        }
        else {
          d_0_10203 = r; /*float64*/
        }
      }
      else {
        d_0_10203 = r; /*float64*/
      }
    }
    return kk_std_num_ddouble__new_Ddouble(d_0_10203, 0x0p+0, _ctx);
  }
}
 
// Remainder of two `:ddouble`s

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__perc__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble n;
  kk_std_num_ddouble__ddouble _x_x1485 = kk_std_num_ddouble__lp__fs__rp_(x, y, _ctx); /*std/num/ddouble/ddouble*/
  n = kk_std_num_ddouble_round(_x_x1485, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble y_0_10211 = kk_std_num_ddouble__lp__star__rp_(n, y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x_x1486;
  double _x_x1487;
  double _x_x1488;
  {
    double _x = y_0_10211.hi;
    _x_x1488 = _x; /*float64*/
  }
  _x_x1487 = (-_x_x1488); /*float64*/
  double _x_x1489;
  double _x_x1490;
  {
    double _x_0 = y_0_10211.lo;
    _x_x1490 = _x_0; /*float64*/
  }
  _x_x1489 = (-_x_x1490); /*float64*/
  _x_x1486 = kk_std_num_ddouble__new_Ddouble(_x_x1487, _x_x1489, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x_x1486, _ctx);
}
 
// Division and remainder of two `:ddouble`s

kk_std_core_types__tuple2 kk_std_num_ddouble_divrem(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> (ddouble, ddouble) */ 
  kk_std_num_ddouble__ddouble n;
  kk_std_num_ddouble__ddouble _x_x1491 = kk_std_num_ddouble__lp__fs__rp_(x, y, _ctx); /*std/num/ddouble/ddouble*/
  n = kk_std_num_ddouble_round(_x_x1491, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble y_0_10213 = kk_std_num_ddouble__lp__star__rp_(n, y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _b_x239_241;
  kk_std_num_ddouble__ddouble _x_x1492;
  double _x_x1493;
  double _x_x1494;
  {
    double _x = y_0_10213.hi;
    _x_x1494 = _x; /*float64*/
  }
  _x_x1493 = (-_x_x1494); /*float64*/
  double _x_x1495;
  double _x_x1496;
  {
    double _x_0 = y_0_10213.lo;
    _x_x1496 = _x_0; /*float64*/
  }
  _x_x1495 = (-_x_x1496); /*float64*/
  _x_x1492 = kk_std_num_ddouble__new_Ddouble(_x_x1493, _x_x1495, _ctx); /*std/num/ddouble/ddouble*/
  _b_x239_241 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x1492, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(n, _ctx), kk_std_num_ddouble__ddouble_box(_b_x239_241, _ctx), _ctx);
}
 
// Convert a `:ddouble` to a `:decimal` up to a given precision `prec` (= `-1`).
// A negative precision converts precisely. Returns 0 for non-finite `:ddouble`'s.

kk_std_num_decimal__decimal kk_std_num_ddouble_decimal(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : ? int) -> std/num/decimal/decimal */ 
  bool b_10214;
  bool _match_x849;
  double _x_x1497;
  {
    double _x = x.hi;
    _x_x1497 = _x; /*float64*/
  }
  _match_x849 = isfinite(_x_x1497); /*bool*/
  if (_match_x849) {
    double _x_x1498;
    {
      double _x_0 = x.lo;
      _x_x1498 = _x_0; /*float64*/
    }
    b_10214 = isfinite(_x_x1498); /*bool*/
  }
  else {
    b_10214 = false; /*bool*/
  }
  if (b_10214) {
    kk_std_num_decimal__decimal x_0_10215;
    double _x_x1499;
    {
      double _x_3 = x.hi;
      _x_x1499 = _x_3; /*float64*/
    }
    kk_std_core_types__optional _x_x1500;
    kk_box_t _x_x1501;
    kk_integer_t _x_x1502;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x242 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_4427 = kk_integer_unbox(_box_x242, _ctx);
      kk_integer_dup(_uniq_prec_4427, _ctx);
      _x_x1502 = _uniq_prec_4427; /*int*/
    }
    else {
      _x_x1502 = kk_integer_from_small(-1); /*int*/
    }
    _x_x1501 = kk_integer_box(_x_x1502, _ctx); /*10003*/
    _x_x1500 = kk_std_core_types__new_Optional(_x_x1501, _ctx); /*? 10003*/
    x_0_10215 = kk_std_num_decimal_float64_fs_decimal(_x_x1499, _x_x1500, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal y_10216;
    double _x_x1503;
    {
      double _x_4 = x.lo;
      _x_x1503 = _x_4; /*float64*/
    }
    kk_std_core_types__optional _x_x1504;
    kk_box_t _x_x1505;
    kk_integer_t _x_x1506;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x245 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_4427_0 = kk_integer_unbox(_box_x245, _ctx);
      kk_integer_dup(_uniq_prec_4427_0, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1506 = _uniq_prec_4427_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1506 = kk_integer_from_small(-1); /*int*/
    }
    _x_x1505 = kk_integer_box(_x_x1506, _ctx); /*10003*/
    _x_x1504 = kk_std_core_types__new_Optional(_x_x1505, _ctx); /*? 10003*/
    y_10216 = kk_std_num_decimal_float64_fs_decimal(_x_x1503, _x_x1504, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t e;
    bool _match_x845;
    kk_integer_t _brw_x847;
    {
      kk_integer_t _x_1 = x_0_10215.exp;
      kk_integer_dup(_x_1, _ctx);
      _brw_x847 = _x_1; /*int*/
    }
    kk_integer_t _brw_x846;
    {
      kk_integer_t _x_0_0 = y_10216.exp;
      kk_integer_dup(_x_0_0, _ctx);
      _brw_x846 = _x_0_0; /*int*/
    }
    bool _brw_x848 = kk_integer_lte_borrow(_brw_x847,_brw_x846,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x847, _ctx);
    kk_integer_drop(_brw_x846, _ctx);
    _match_x845 = _brw_x848; /*bool*/
    if (_match_x845) {
      kk_integer_t _x_1_0 = x_0_10215.exp;
      kk_integer_dup(_x_1_0, _ctx);
      e = _x_1_0; /*int*/
    }
    else {
      kk_integer_t _x_0_0_0 = y_10216.exp;
      kk_integer_dup(_x_0_0_0, _ctx);
      e = _x_0_0_0; /*int*/
    }
    kk_std_num_decimal__decimal xx;
    kk_integer_t _x_x1507 = kk_integer_dup(e, _ctx); /*int*/
    xx = kk_std_num_decimal_expand(x_0_10215, _x_x1507, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal yy;
    kk_integer_t _x_x1508 = kk_integer_dup(e, _ctx); /*int*/
    yy = kk_std_num_decimal_expand(y_10216, _x_x1508, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t _x_x1509;
    kk_integer_t _x_x1510;
    {
      kk_integer_t _x_1_0_0 = xx.num;
      kk_integer_dup(_x_1_0_0, _ctx);
      kk_std_num_decimal__decimal_drop(xx, _ctx);
      _x_x1510 = _x_1_0_0; /*int*/
    }
    kk_integer_t _x_x1511;
    {
      kk_integer_t _x_2 = yy.num;
      kk_integer_dup(_x_2, _ctx);
      kk_std_num_decimal__decimal_drop(yy, _ctx);
      _x_x1511 = _x_2; /*int*/
    }
    _x_x1509 = kk_integer_add(_x_x1510,_x_x1511,kk_context()); /*int*/
    return kk_std_num_decimal__new_Decimal(_x_x1509, e, _ctx);
  }
  {
    kk_std_core_types__optional_drop(prec, _ctx);
    return kk_std_num_decimal_int_fs_decimal(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx);
  }
}
 
// Convert a `:ddouble` to the nearest integer (rounding to the nearest even number in case of a tie)

kk_integer_t kk_std_num_ddouble_int(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional nonfin, kk_context_t* _ctx) { /* (x : ddouble, nonfin : ? int) -> int */ 
  bool b_10219;
  bool _match_x844;
  double _x_x1512;
  {
    double _x = x.hi;
    _x_x1512 = _x; /*float64*/
  }
  _match_x844 = isfinite(_x_x1512); /*bool*/
  if (_match_x844) {
    double _x_x1513;
    {
      double _x_0 = x.lo;
      _x_x1513 = _x_0; /*float64*/
    }
    b_10219 = isfinite(_x_x1513); /*bool*/
  }
  else {
    b_10219 = false; /*bool*/
  }
  if (b_10219) {
    kk_std_core_types__optional_drop(nonfin, _ctx);
    kk_std_num_ddouble__ddouble x_1_10222 = kk_std_num_ddouble_round(x, _ctx); /*std/num/ddouble/ddouble*/;
    bool b_0_10224;
    bool _match_x843;
    double _x_x1514;
    {
      double _x_1 = x_1_10222.hi;
      _x_x1514 = _x_1; /*float64*/
    }
    _match_x843 = isfinite(_x_x1514); /*bool*/
    if (_match_x843) {
      double _x_x1515;
      {
        double _x_0_0 = x_1_10222.lo;
        _x_x1515 = _x_0_0; /*float64*/
      }
      b_0_10224 = isfinite(_x_x1515); /*bool*/
    }
    else {
      b_0_10224 = false; /*bool*/
    }
    kk_std_num_decimal__decimal x_0_10220;
    if (b_0_10224) {
      kk_std_num_decimal__decimal x_2_10225;
      double _x_x1516;
      {
        double _x_4 = x_1_10222.hi;
        _x_x1516 = _x_4; /*float64*/
      }
      kk_std_core_types__optional _x_x1517;
      kk_box_t _x_x1518;
      kk_integer_t _x_x1519;
      kk_std_core_types__optional _match_x842 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x842, _ctx)) {
        kk_box_t _box_x248 = _match_x842._cons._Optional.value;
        kk_integer_t _uniq_prec_4427 = kk_integer_unbox(_box_x248, _ctx);
        kk_integer_dup(_uniq_prec_4427, _ctx);
        kk_std_core_types__optional_drop(_match_x842, _ctx);
        _x_x1519 = _uniq_prec_4427; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x842, _ctx);
        _x_x1519 = kk_integer_from_small(-1); /*int*/
      }
      _x_x1518 = kk_integer_box(_x_x1519, _ctx); /*10003*/
      _x_x1517 = kk_std_core_types__new_Optional(_x_x1518, _ctx); /*? 10003*/
      x_2_10225 = kk_std_num_decimal_float64_fs_decimal(_x_x1516, _x_x1517, _ctx); /*std/num/decimal/decimal*/
      kk_std_num_decimal__decimal y_0_10226;
      double _x_x1520;
      {
        double _x_5 = x_1_10222.lo;
        _x_x1520 = _x_5; /*float64*/
      }
      kk_std_core_types__optional _x_x1521;
      kk_box_t _x_x1522;
      kk_integer_t _x_x1523;
      kk_std_core_types__optional _match_x841 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x841, _ctx)) {
        kk_box_t _box_x251 = _match_x841._cons._Optional.value;
        kk_integer_t _uniq_prec_4427_0 = kk_integer_unbox(_box_x251, _ctx);
        kk_integer_dup(_uniq_prec_4427_0, _ctx);
        kk_std_core_types__optional_drop(_match_x841, _ctx);
        _x_x1523 = _uniq_prec_4427_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x841, _ctx);
        _x_x1523 = kk_integer_from_small(-1); /*int*/
      }
      _x_x1522 = kk_integer_box(_x_x1523, _ctx); /*10003*/
      _x_x1521 = kk_std_core_types__new_Optional(_x_x1522, _ctx); /*? 10003*/
      y_0_10226 = kk_std_num_decimal_float64_fs_decimal(_x_x1520, _x_x1521, _ctx); /*std/num/decimal/decimal*/
      kk_integer_t e;
      bool _match_x837;
      kk_integer_t _brw_x839;
      {
        kk_integer_t _x_3 = x_2_10225.exp;
        kk_integer_dup(_x_3, _ctx);
        _brw_x839 = _x_3; /*int*/
      }
      kk_integer_t _brw_x838;
      {
        kk_integer_t _x_0_0_0 = y_0_10226.exp;
        kk_integer_dup(_x_0_0_0, _ctx);
        _brw_x838 = _x_0_0_0; /*int*/
      }
      bool _brw_x840 = kk_integer_lte_borrow(_brw_x839,_brw_x838,kk_context()); /*bool*/;
      kk_integer_drop(_brw_x839, _ctx);
      kk_integer_drop(_brw_x838, _ctx);
      _match_x837 = _brw_x840; /*bool*/
      if (_match_x837) {
        kk_integer_t _x_1_0 = x_2_10225.exp;
        kk_integer_dup(_x_1_0, _ctx);
        e = _x_1_0; /*int*/
      }
      else {
        kk_integer_t _x_0_0_0_0 = y_0_10226.exp;
        kk_integer_dup(_x_0_0_0_0, _ctx);
        e = _x_0_0_0_0; /*int*/
      }
      kk_std_num_decimal__decimal xx;
      kk_integer_t _x_x1524 = kk_integer_dup(e, _ctx); /*int*/
      xx = kk_std_num_decimal_expand(x_2_10225, _x_x1524, _ctx); /*std/num/decimal/decimal*/
      kk_std_num_decimal__decimal yy;
      kk_integer_t _x_x1525 = kk_integer_dup(e, _ctx); /*int*/
      yy = kk_std_num_decimal_expand(y_0_10226, _x_x1525, _ctx); /*std/num/decimal/decimal*/
      kk_integer_t _x_x1526;
      kk_integer_t _x_x1527;
      {
        kk_integer_t _x_1_0_0 = xx.num;
        kk_integer_dup(_x_1_0_0, _ctx);
        kk_std_num_decimal__decimal_drop(xx, _ctx);
        _x_x1527 = _x_1_0_0; /*int*/
      }
      kk_integer_t _x_x1528;
      {
        kk_integer_t _x_2_0 = yy.num;
        kk_integer_dup(_x_2_0, _ctx);
        kk_std_num_decimal__decimal_drop(yy, _ctx);
        _x_x1528 = _x_2_0; /*int*/
      }
      _x_x1526 = kk_integer_add(_x_x1527,_x_x1528,kk_context()); /*int*/
      x_0_10220 = kk_std_num_decimal__new_Decimal(_x_x1526, e, _ctx); /*std/num/decimal/decimal*/
    }
    else {
      x_0_10220 = kk_std_num_decimal_int_fs_decimal(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
    }
    kk_std_num_decimal__decimal y;
    kk_std_core_types__optional _x_x1529 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1530;
    kk_box_t _x_x1531;
    kk_std_num_decimal__round _x_x1532;
    kk_std_core_types__optional _match_x836 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x836, _ctx)) {
      kk_box_t _box_x255 = _match_x836._cons._Optional.value;
      kk_std_num_decimal__round _uniq_rnd_2758 = kk_std_num_decimal__round_unbox(_box_x255, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x836, _ctx);
      _x_x1532 = _uniq_rnd_2758; /*std/num/decimal/round*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x836, _ctx);
      _x_x1532 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
    }
    _x_x1531 = kk_std_num_decimal__round_box(_x_x1532, _ctx); /*10003*/
    _x_x1530 = kk_std_core_types__new_Optional(_x_x1531, _ctx); /*? 10003*/
    y = kk_std_num_decimal_round_to_prec(x_0_10220, _x_x1529, _x_x1530, _ctx); /*std/num/decimal/decimal*/
    bool _match_x833;
    kk_integer_t _brw_x834;
    {
      kk_integer_t _x_2 = y.exp;
      kk_integer_dup(_x_2, _ctx);
      _brw_x834 = _x_2; /*int*/
    }
    bool _brw_x835 = kk_integer_gt_borrow(_brw_x834,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x834, _ctx);
    _match_x833 = _brw_x835; /*bool*/
    if (_match_x833) {
      kk_integer_t _x_x1533;
      {
        kk_integer_t _x_0_1 = y.num;
        kk_integer_dup(_x_0_1, _ctx);
        _x_x1533 = _x_0_1; /*int*/
      }
      kk_integer_t _x_x1534;
      {
        kk_integer_t _x_1_1 = y.exp;
        kk_integer_dup(_x_1_1, _ctx);
        kk_std_num_decimal__decimal_drop(y, _ctx);
        _x_x1534 = _x_1_1; /*int*/
      }
      return kk_std_core_int_mul_exp10(_x_x1533, _x_x1534, _ctx);
    }
    {
      kk_integer_t _x_2_1 = y.num;
      kk_integer_dup(_x_2_1, _ctx);
      kk_std_num_decimal__decimal_drop(y, _ctx);
      return _x_2_1;
    }
  }
  if (kk_std_core_types__is_Optional(nonfin, _ctx)) {
    kk_box_t _box_x259 = nonfin._cons._Optional.value;
    kk_integer_t _uniq_nonfin_4504 = kk_integer_unbox(_box_x259, _ctx);
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
  double _x_x1535;
  {
    double _x = x.hi;
    _x_x1535 = _x; /*float64*/
  }
  r = floor(_x_x1535); /*float64*/
  bool _match_x831;
  double _x_x1536;
  {
    double _x_0 = x.hi;
    _x_x1536 = _x_0; /*float64*/
  }
  _match_x831 = (r == _x_x1536); /*bool*/
  if (_match_x831) {
    double y_10232;
    double _x_x1537;
    {
      double _x_1 = x.lo;
      _x_x1537 = _x_1; /*float64*/
    }
    y_10232 = floor(_x_x1537); /*float64*/
    bool b_10234 = isfinite(r); /*bool*/;
    if (b_10234) {
      double z = (r + y_10232); /*float64*/;
      double err;
      double _x_x1538 = (z - r); /*float64*/
      err = (y_10232 - _x_x1538); /*float64*/
      double _x_x1539;
      bool _match_x832 = isfinite(z); /*bool*/;
      if (_match_x832) {
        _x_x1539 = err; /*float64*/
      }
      else {
        _x_x1539 = z; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(z, _x_x1539, _ctx);
    }
    {
      return kk_std_num_ddouble__new_Ddouble(r, 0x0p+0, _ctx);
    }
  }
  {
    return kk_std_num_ddouble__new_Ddouble(r, 0x0p+0, _ctx);
  }
}
 
// Round to positive infinity.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ceiling(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double r;
  double _x_x1540;
  {
    double _x = x.hi;
    _x_x1540 = _x; /*float64*/
  }
  r = ceil(_x_x1540); /*float64*/
  bool _match_x829;
  double _x_x1541;
  {
    double _x_0 = x.hi;
    _x_x1541 = _x_0; /*float64*/
  }
  _match_x829 = (r == _x_x1541); /*bool*/
  if (_match_x829) {
    double y_10239;
    double _x_x1542;
    {
      double _x_1 = x.lo;
      _x_x1542 = _x_1; /*float64*/
    }
    y_10239 = ceil(_x_x1542); /*float64*/
    bool b_10241 = isfinite(r); /*bool*/;
    if (b_10241) {
      double z = (r + y_10239); /*float64*/;
      double err;
      double _x_x1543 = (z - r); /*float64*/
      err = (y_10239 - _x_x1543); /*float64*/
      double _x_x1544;
      bool _match_x830 = isfinite(z); /*bool*/;
      if (_match_x830) {
        _x_x1544 = err; /*float64*/
      }
      else {
        _x_x1544 = z; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(z, _x_x1544, _ctx);
    }
    {
      return kk_std_num_ddouble__new_Ddouble(r, 0x0p+0, _ctx);
    }
  }
  {
    return kk_std_num_ddouble__new_Ddouble(r, 0x0p+0, _ctx);
  }
}
 
// The fraction of `x` such that `x.truncate + x.fraction == x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_fraction(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble y_10247;
  bool _match_x827;
  double _x_x1546;
  {
    double _x = x.hi;
    _x_x1546 = _x; /*float64*/
  }
  _match_x827 = (_x_x1546 < (0x0p+0)); /*bool*/
  if (_match_x827) {
    y_10247 = kk_std_num_ddouble_ceiling(x, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    y_10247 = kk_std_num_ddouble_floor(x, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x1547;
  double _x_x1548;
  double _x_x1549;
  {
    double _x_0 = y_10247.hi;
    _x_x1549 = _x_0; /*float64*/
  }
  _x_x1548 = (-_x_x1549); /*float64*/
  double _x_x1550;
  double _x_x1551;
  {
    double _x_0_0 = y_10247.lo;
    _x_x1551 = _x_0_0; /*float64*/
  }
  _x_x1550 = (-_x_x1551); /*float64*/
  _x_x1547 = kk_std_num_ddouble__new_Ddouble(_x_x1548, _x_x1550, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x_x1547, _ctx);
}
 
// Round a `:ddouble` to a specified precision.
// Uses `round` if the precision is smaller or equal to zero.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_round_to_prec(kk_std_num_ddouble__ddouble x, kk_integer_t prec, kk_context_t* _ctx) { /* (x : ddouble, prec : int) -> ddouble */ 
  bool _match_x825 = kk_integer_lte_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x825) {
    kk_integer_drop(prec, _ctx);
    return kk_std_num_ddouble_round(x, _ctx);
  }
  {
    bool _match_x826 = kk_integer_gt_borrow(prec,(kk_integer_from_small(31)),kk_context()); /*bool*/;
    if (_match_x826) {
      kk_integer_drop(prec, _ctx);
      return x;
    }
    {
      kk_std_num_ddouble__ddouble p = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, prec, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x_x1557;
      kk_std_num_ddouble__ddouble _x_x1558 = kk_std_num_ddouble__lp__star__rp_(x, p, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1557 = kk_std_num_ddouble_round(_x_x1558, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__fs__rp_(_x_x1557, p, _ctx);
    }
  }
}
 
// Create a `:ddouble` `x` such that `x` equals `d`&middot;10^`e`^.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_float64_fs_ddouble_exp(double d, kk_integer_t e, kk_context_t* _ctx) { /* (d : float64, e : int) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_10253 = kk_std_num_ddouble__new_Ddouble(d, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x823 = kk_integer_is_zero_borrow(e); /*bool*/;
  if (_match_x823) {
    kk_integer_drop(e, _ctx);
    return x_10253;
  }
  {
    kk_std_num_ddouble__ddouble y_10701 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, e, _ctx); /*std/num/ddouble/ddouble*/;
    double z;
    double _x_x1564;
    {
      double _x = x_10253.hi;
      _x_x1564 = _x; /*float64*/
    }
    double _x_x1565;
    {
      double _x_0 = y_10701.hi;
      _x_x1565 = _x_0; /*float64*/
    }
    z = (_x_x1564 * _x_x1565); /*float64*/
    double err;
    double _x_x1566;
    {
      double _x_1 = x_10253.hi;
      _x_x1566 = _x_1; /*float64*/
    }
    double _x_x1567;
    {
      double _x_0_0 = y_10701.hi;
      _x_x1567 = _x_0_0; /*float64*/
    }
    double _x_x1568 = (-z); /*float64*/
    err = kk_std_num_float64_fmadd(_x_x1566, _x_x1567, _x_x1568, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
    double e_0;
    double _x_x1569;
    {
      double _x_1_0 = z_0.err;
      _x_x1569 = _x_1_0; /*float64*/
    }
    double _x_x1570;
    double _x_x1571;
    double _x_x1572;
    {
      double _x_2 = x_10253.hi;
      _x_x1572 = _x_2; /*float64*/
    }
    double _x_x1573;
    {
      double _x_3 = y_10701.lo;
      _x_x1573 = _x_3; /*float64*/
    }
    _x_x1571 = (_x_x1572 * _x_x1573); /*float64*/
    double _x_x1574;
    double _x_x1575;
    {
      double _x_4 = x_10253.lo;
      _x_x1575 = _x_4; /*float64*/
    }
    double _x_x1576;
    {
      double _x_5 = y_10701.hi;
      _x_x1576 = _x_5; /*float64*/
    }
    _x_x1574 = (_x_x1575 * _x_x1576); /*float64*/
    _x_x1570 = (_x_x1571 + _x_x1574); /*float64*/
    e_0 = (_x_x1569 + _x_x1570); /*float64*/
    bool b_10040;
    double _x_x1577;
    {
      double _x_6 = z_0.num;
      _x_x1577 = _x_6; /*float64*/
    }
    b_10040 = isfinite(_x_x1577); /*bool*/
    if (b_10040) {
      double z_1;
      double _x_x1578;
      {
        double _x_6_0 = z_0.num;
        _x_x1578 = _x_6_0; /*float64*/
      }
      z_1 = (_x_x1578 + e_0); /*float64*/
      double err_0;
      double _x_x1579;
      double _x_x1580;
      {
        double _x_6_1 = z_0.num;
        _x_x1580 = _x_6_1; /*float64*/
      }
      _x_x1579 = (z_1 - _x_x1580); /*float64*/
      err_0 = (e_0 - _x_x1579); /*float64*/
      double _x_x1581;
      bool _match_x824 = isfinite(z_1); /*bool*/;
      if (_match_x824) {
        _x_x1581 = err_0; /*float64*/
      }
      else {
        _x_x1581 = z_1; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(z_1, _x_x1581, _ctx);
    }
    {
      double _x_x1582;
      {
        double _x_6_2 = z_0.num;
        _x_x1582 = _x_6_2; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(_x_x1582, 0x0p+0, _ctx);
    }
  }
}
 
// Create a `:ddouble` `x` such that `x` equals `i`&middot;10^`e`^.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_int_fs_ddouble_exp(kk_integer_t i, kk_integer_t exp_0, kk_context_t* _ctx) { /* (i : int, exp : int) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_10257 = kk_std_num_ddouble_ddouble_int_exp(i, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x821 = kk_integer_is_zero_borrow(exp_0); /*bool*/;
  if (_match_x821) {
    kk_integer_drop(exp_0, _ctx);
    return x_10257;
  }
  {
    kk_std_num_ddouble__ddouble y_10703 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, exp_0, _ctx); /*std/num/ddouble/ddouble*/;
    double z;
    double _x_x1583;
    {
      double _x = x_10257.hi;
      _x_x1583 = _x; /*float64*/
    }
    double _x_x1584;
    {
      double _x_0 = y_10703.hi;
      _x_x1584 = _x_0; /*float64*/
    }
    z = (_x_x1583 * _x_x1584); /*float64*/
    double err;
    double _x_x1585;
    {
      double _x_1 = x_10257.hi;
      _x_x1585 = _x_1; /*float64*/
    }
    double _x_x1586;
    {
      double _x_0_0 = y_10703.hi;
      _x_x1586 = _x_0_0; /*float64*/
    }
    double _x_x1587 = (-z); /*float64*/
    err = kk_std_num_float64_fmadd(_x_x1585, _x_x1586, _x_x1587, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
    double e;
    double _x_x1588;
    {
      double _x_1_0 = z_0.err;
      _x_x1588 = _x_1_0; /*float64*/
    }
    double _x_x1589;
    double _x_x1590;
    double _x_x1591;
    {
      double _x_2 = x_10257.hi;
      _x_x1591 = _x_2; /*float64*/
    }
    double _x_x1592;
    {
      double _x_3 = y_10703.lo;
      _x_x1592 = _x_3; /*float64*/
    }
    _x_x1590 = (_x_x1591 * _x_x1592); /*float64*/
    double _x_x1593;
    double _x_x1594;
    {
      double _x_4 = x_10257.lo;
      _x_x1594 = _x_4; /*float64*/
    }
    double _x_x1595;
    {
      double _x_5 = y_10703.hi;
      _x_x1595 = _x_5; /*float64*/
    }
    _x_x1593 = (_x_x1594 * _x_x1595); /*float64*/
    _x_x1589 = (_x_x1590 + _x_x1593); /*float64*/
    e = (_x_x1588 + _x_x1589); /*float64*/
    bool b_10040;
    double _x_x1596;
    {
      double _x_6 = z_0.num;
      _x_x1596 = _x_6; /*float64*/
    }
    b_10040 = isfinite(_x_x1596); /*bool*/
    if (b_10040) {
      double z_1;
      double _x_x1597;
      {
        double _x_6_0 = z_0.num;
        _x_x1597 = _x_6_0; /*float64*/
      }
      z_1 = (_x_x1597 + e); /*float64*/
      double err_0;
      double _x_x1598;
      double _x_x1599;
      {
        double _x_6_1 = z_0.num;
        _x_x1599 = _x_6_1; /*float64*/
      }
      _x_x1598 = (z_1 - _x_x1599); /*float64*/
      err_0 = (e - _x_x1598); /*float64*/
      double _x_x1600;
      bool _match_x822 = isfinite(z_1); /*bool*/;
      if (_match_x822) {
        _x_x1600 = err_0; /*float64*/
      }
      else {
        _x_x1600 = z_1; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(z_1, _x_x1600, _ctx);
    }
    {
      double _x_x1601;
      {
        double _x_6_2 = z_0.num;
        _x_x1601 = _x_6_2; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(_x_x1601, 0x0p+0, _ctx);
    }
  }
}
 
// The square root of a non-negative `:ddouble` `x`.
// For negative `x`, `dd-nan` is returned.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sqrt(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x818;
  double _x_x1608;
  {
    double _x = x.hi;
    _x_x1608 = _x; /*float64*/
  }
  _match_x818 = (_x_x1608 == (0x0p+0)); /*bool*/
  if (_match_x818) {
    return kk_std_num_ddouble_zero;
  }
  {
    bool _match_x819;
    double _x_x1609;
    {
      double _x_0 = x.hi;
      _x_x1609 = _x_0; /*float64*/
    }
    _match_x819 = (_x_x1609 < (0x0p+0)); /*bool*/
    if (_match_x819) {
      return kk_std_num_ddouble_dd_nan;
    }
    {
      double a;
      double _x_x1610;
      double _x_x1611;
      {
        double _x_1 = x.hi;
        _x_x1611 = _x_1; /*float64*/
      }
      _x_x1610 = sqrt(_x_x1611); /*float64*/
      a = (0x1p0 / _x_x1610); /*float64*/
      double t1;
      double _x_x1612;
      {
        double _x_2 = x.hi;
        _x_x1612 = _x_2; /*float64*/
      }
      t1 = (_x_x1612 * a); /*float64*/
      kk_std_num_ddouble__ddouble x_0_10704 = kk_std_num_ddouble__new_Ddouble(t1, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
      double z;
      double _x_x1613;
      {
        double _x_3 = x_0_10704.hi;
        _x_x1613 = _x_3; /*float64*/
      }
      double _x_x1614;
      {
        double _x_3_0 = x_0_10704.hi;
        _x_x1614 = _x_3_0; /*float64*/
      }
      z = (_x_x1613 * _x_x1614); /*float64*/
      double err;
      double _x_x1615;
      {
        double _x_3_1 = x_0_10704.hi;
        _x_x1615 = _x_3_1; /*float64*/
      }
      double _x_x1616;
      {
        double _x_3_2 = x_0_10704.hi;
        _x_x1616 = _x_3_2; /*float64*/
      }
      double _x_x1617 = (-z); /*float64*/
      err = kk_std_num_float64_fmadd(_x_x1615, _x_x1616, _x_x1617, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
      double e;
      double _x_x1618;
      double _x_x1619;
      {
        double _x_0_0 = z_0.err;
        _x_x1619 = _x_0_0; /*float64*/
      }
      double _x_x1620;
      double _x_x1621;
      double _x_x1622;
      {
        double _x_1_0 = x_0_10704.hi;
        _x_x1622 = _x_1_0; /*float64*/
      }
      _x_x1621 = (0x1p1 * _x_x1622); /*float64*/
      double _x_x1623;
      {
        double _x_2_0 = x_0_10704.lo;
        _x_x1623 = _x_2_0; /*float64*/
      }
      _x_x1620 = (_x_x1621 * _x_x1623); /*float64*/
      _x_x1618 = (_x_x1619 + _x_x1620); /*float64*/
      double _x_x1624;
      double _x_x1625;
      {
        double _x_3_0_0 = x_0_10704.lo;
        _x_x1625 = _x_3_0_0; /*float64*/
      }
      double _x_x1626;
      {
        double _x_4 = x_0_10704.lo;
        _x_x1626 = _x_4; /*float64*/
      }
      _x_x1624 = (_x_x1625 * _x_x1626); /*float64*/
      e = (_x_x1618 + _x_x1624); /*float64*/
      bool b_10096;
      double _x_x1627;
      {
        double _x_5 = z_0.num;
        _x_x1627 = _x_5; /*float64*/
      }
      b_10096 = isfinite(_x_x1627); /*bool*/
      kk_std_num_ddouble__ddouble y_10275;
      if (b_10096) {
        double z_1;
        double _x_x1628;
        {
          double _x_5_0 = z_0.num;
          _x_x1628 = _x_5_0; /*float64*/
        }
        z_1 = (_x_x1628 + e); /*float64*/
        double err_0;
        double _x_x1629;
        double _x_x1630;
        {
          double _x_5_1 = z_0.num;
          _x_x1630 = _x_5_1; /*float64*/
        }
        _x_x1629 = (z_1 - _x_x1630); /*float64*/
        err_0 = (e - _x_x1629); /*float64*/
        double _x_x1631;
        bool _match_x820 = isfinite(z_1); /*bool*/;
        if (_match_x820) {
          _x_x1631 = err_0; /*float64*/
        }
        else {
          _x_x1631 = z_1; /*float64*/
        }
        y_10275 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x1631, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double _x_x1632;
        {
          double _x_5_2 = z_0.num;
          _x_x1632 = _x_5_2; /*float64*/
        }
        y_10275 = kk_std_num_ddouble__new_Ddouble(_x_x1632, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble ddouble_0_3_10273;
      kk_std_num_ddouble__ddouble _x_x1633;
      double _x_x1634;
      double _x_x1635;
      {
        double _x_6 = y_10275.hi;
        _x_x1635 = _x_6; /*float64*/
      }
      _x_x1634 = (-_x_x1635); /*float64*/
      double _x_x1636;
      double _x_x1637;
      {
        double _x_0_1 = y_10275.lo;
        _x_x1637 = _x_0_1; /*float64*/
      }
      _x_x1636 = (-_x_x1637); /*float64*/
      _x_x1633 = kk_std_num_ddouble__new_Ddouble(_x_x1634, _x_x1636, _ctx); /*std/num/ddouble/ddouble*/
      ddouble_0_3_10273 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x1633, _ctx); /*std/num/ddouble/ddouble*/
      double t2;
      double _x_x1638;
      double _x_x1639;
      {
        double _x_3_1_0 = ddouble_0_3_10273.hi;
        _x_x1639 = _x_3_1_0; /*float64*/
      }
      _x_x1638 = (_x_x1639 * a); /*float64*/
      t2 = (_x_x1638 * (0x1p-1)); /*float64*/
      return kk_std_num_ddouble_dsum(t1, t2, _ctx);
    }
  }
}

kk_std_core_types__list kk_std_num_ddouble_exp_factors;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp_approx(kk_std_num_ddouble__ddouble p, kk_std_num_ddouble__ddouble t, kk_std_num_ddouble__ddouble r, double eps, kk_std_core_types__list fs, kk_std_core_types__optional s, kk_context_t* _ctx) { /* (p : ddouble, t : ddouble, r : ddouble, eps : float64, fs : list<ddouble>, s : ? ddouble) -> ddouble */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(fs, _ctx)) {
    kk_std_num_ddouble__ddouble _x_x1669;
    if (kk_std_core_types__is_Optional(s, _ctx)) {
      kk_box_t _box_x288 = s._cons._Optional.value;
      kk_std_num_ddouble__ddouble _uniq_s_5346 = kk_std_num_ddouble__ddouble_unbox(_box_x288, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(s, _ctx);
      _x_x1669 = _uniq_s_5346; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_core_types__optional_drop(s, _ctx);
      _x_x1669 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
    }
    return kk_std_num_ddouble__lp__plus__rp_(_x_x1669, t, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1670 = kk_std_core_types__as_Cons(fs, _ctx);
    kk_box_t _box_x289 = _con_x1670->head;
    kk_std_num_ddouble__ddouble f = kk_std_num_ddouble__ddouble_unbox(_box_x289, KK_BORROWED, _ctx);
    kk_std_core_types__list fs1 = _con_x1670->tail;
    if kk_likely(kk_datatype_ptr_is_unique(fs, _ctx)) {
      kk_box_drop(_box_x289, _ctx);
      kk_datatype_ptr_free(fs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(fs1, _ctx);
      kk_datatype_ptr_decref(fs, _ctx);
    }
    kk_std_num_ddouble__ddouble s1;
    kk_std_num_ddouble__ddouble _x_x1671;
    if (kk_std_core_types__is_Optional(s, _ctx)) {
      kk_box_t _box_x290 = s._cons._Optional.value;
      kk_std_num_ddouble__ddouble _uniq_s_5346_0 = kk_std_num_ddouble__ddouble_unbox(_box_x290, KK_BORROWED, _ctx);
      _x_x1671 = _uniq_s_5346_0; /*std/num/ddouble/ddouble*/
    }
    else {
      _x_x1671 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
    }
    s1 = kk_std_num_ddouble__lp__plus__rp_(_x_x1671, t, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble p1 = kk_std_num_ddouble__lp__star__rp_(p, r, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble t1 = kk_std_num_ddouble__lp__star__rp_(p1, f, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_x817;
    double _x_x1672;
    double _x_x1673;
    {
      double _x = t1.hi;
      _x_x1673 = _x; /*float64*/
    }
    _x_x1672 = kk_double_abs(_x_x1673); /*float64*/
    _match_x817 = (_x_x1672 <= eps); /*bool*/
    if (_match_x817) {
      kk_std_core_types__list_drop(fs1, _ctx);
      kk_std_num_ddouble__ddouble _x_x1674;
      if (kk_std_core_types__is_Optional(s, _ctx)) {
        kk_box_t _box_x291 = s._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_s_5346_1 = kk_std_num_ddouble__ddouble_unbox(_box_x291, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(s, _ctx);
        _x_x1674 = _uniq_s_5346_1; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_core_types__optional_drop(s, _ctx);
        _x_x1674 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
      }
      return kk_std_num_ddouble__lp__plus__rp_(_x_x1674, t, _ctx);
    }
    {
      kk_std_core_types__optional_drop(s, _ctx);
      { // tailcall
        kk_std_core_types__optional _x_x1675 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(s1, _ctx), _ctx); /*? 10003*/
        p = p1;
        t = t1;
        fs = fs1;
        s = _x_x1675;
        goto kk__tailcall;
      }
    }
  }
}
 
// lifted local: @lift-exp@11072, exp, @spec-x10991
// specialized: std/core/#range/@lift-for@1829, on parameters @uniq-action@10984, using:
// @uniq-action@10984 = fn<((local :: H -> X)<(h :: H)>)>(@uniq-i@0@10982: int){
//   val x@3@10305 : std/num/ddouble/ddouble;
//   val x@3@10710 : std/num/ddouble/ddouble;
//   val z@2 : float64;
//   val err@1 : float64;
//   val z@0@0 : std/num/ddouble/edouble;
//   val e@0 : float64;
//   val b@10096 : bool;
//   std/core/types/local-set<std/num/ddouble/ddouble,(total :: E),(h :: H)>(acc, (std/num/ddouble/(+)((std/num/ddouble/Ddouble((std/num/float64/(*)((match (x@3@10305) {
//             ((@skip std/num/ddouble/Ddouble((@x@7@0: float64) : float64, (@pat@0@8@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@12: std/num/ddouble/ddouble)
//                -> @x@7@0;
//           }), 2.0)), (std/num/float64/(*)((match (x@3@10305) {
//             ((@skip std/num/ddouble/Ddouble((@pat@0@9@0: float64) : float64, (@x@8@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@13: std/num/ddouble/ddouble)
//                -> @x@8@0;
//           }), 2.0)))), (match (b@10096) {
//         ((std/core/types/True() : bool ) as @pat@6@1: bool)
//            -> val z@1@0 : float64;
//               val err@0@0 : float64;
//           std/num/ddouble/Ddouble(z@1@0, (match ((std/num/float64/is-finite(z@1@0))) {
//               ((std/core/types/True() : bool ) as @pat@1@0@1: bool)
//                  -> err@0@0;
//               ((@skip std/core/types/False() : bool ) as @pat@2@0@1: bool)
//                  -> z@1@0;
//             }));
//         ((@skip std/core/types/False() : bool ) as @pat@0@5@2: bool)
//            -> std/num/ddouble/Ddouble((match (z@0@0) {
//               ((@skip std/num/ddouble/Edouble((@x@5@1: float64) : float64, (@pat@0@7@1: float64) : float64) : std/num/ddouble/edouble ) as @pat@8@0: std/num/ddouble/edouble)
//                  -> @x@5@1;
//             }), 0.0);
//       }))));
// }

kk_unit_t kk_std_num_ddouble__lift_exp_11073(kk_ref_t acc, kk_integer_t _uniq_end_10985, kk_integer_t _uniq_i_10986, kk_context_t* _ctx) { /* forall<h> (acc : local-var<h,ddouble>, int, int) -> (local<h>) () */ 
  kk__tailcall: ;
  bool _match_x815 = kk_integer_lte_borrow(_uniq_i_10986,_uniq_end_10985,kk_context()); /*bool*/;
  if (_match_x815) {
    kk_std_num_ddouble__ddouble x_3_10305;
    kk_box_t _x_x1676;
    kk_ref_t _x_x1677 = kk_ref_dup(acc, _ctx); /*local-var<5910,std/num/ddouble/ddouble>*/
    _x_x1676 = kk_ref_get(_x_x1677,kk_context()); /*10000*/
    x_3_10305 = kk_std_num_ddouble__ddouble_unbox(_x_x1676, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble x_3_10710;
    kk_box_t _x_x1678;
    kk_ref_t _x_x1679 = kk_ref_dup(acc, _ctx); /*local-var<5910,std/num/ddouble/ddouble>*/
    _x_x1678 = kk_ref_get(_x_x1679,kk_context()); /*10000*/
    x_3_10710 = kk_std_num_ddouble__ddouble_unbox(_x_x1678, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    double z_2;
    double _x_x1680;
    {
      double _x_9 = x_3_10710.hi;
      _x_x1680 = _x_9; /*float64*/
    }
    double _x_x1681;
    {
      double _x_9_0 = x_3_10710.hi;
      _x_x1681 = _x_9_0; /*float64*/
    }
    z_2 = (_x_x1680 * _x_x1681); /*float64*/
    double err_1;
    double _x_x1682;
    {
      double _x_9_1 = x_3_10710.hi;
      _x_x1682 = _x_9_1; /*float64*/
    }
    double _x_x1683;
    {
      double _x_9_2 = x_3_10710.hi;
      _x_x1683 = _x_9_2; /*float64*/
    }
    double _x_x1684 = (-z_2); /*float64*/
    err_1 = kk_std_num_float64_fmadd(_x_x1682, _x_x1683, _x_x1684, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0_0 = kk_std_num_ddouble__new_Edouble(z_2, err_1, _ctx); /*std/num/ddouble/edouble*/;
    double e_0;
    double _x_x1685;
    double _x_x1686;
    {
      double _x_0_3 = z_0_0.err;
      _x_x1686 = _x_0_3; /*float64*/
    }
    double _x_x1687;
    double _x_x1688;
    double _x_x1689;
    {
      double _x_1_1 = x_3_10710.hi;
      _x_x1689 = _x_1_1; /*float64*/
    }
    _x_x1688 = (0x1p1 * _x_x1689); /*float64*/
    double _x_x1690;
    {
      double _x_2_1 = x_3_10710.lo;
      _x_x1690 = _x_2_1; /*float64*/
    }
    _x_x1687 = (_x_x1688 * _x_x1690); /*float64*/
    _x_x1685 = (_x_x1686 + _x_x1687); /*float64*/
    double _x_x1691;
    double _x_x1692;
    {
      double _x_3_1 = x_3_10710.lo;
      _x_x1692 = _x_3_1; /*float64*/
    }
    double _x_x1693;
    {
      double _x_4_2 = x_3_10710.lo;
      _x_x1693 = _x_4_2; /*float64*/
    }
    _x_x1691 = (_x_x1692 * _x_x1693); /*float64*/
    e_0 = (_x_x1685 + _x_x1691); /*float64*/
    bool b_10096;
    double _x_x1694;
    {
      double _x_5_1 = z_0_0.num;
      _x_x1694 = _x_5_1; /*float64*/
    }
    b_10096 = isfinite(_x_x1694); /*bool*/
    kk_std_num_ddouble__ddouble _b_x303_305;
    kk_std_num_ddouble__ddouble _x_x1695;
    double _x_x1696;
    double _x_x1697;
    {
      double _x_7_0 = x_3_10305.hi;
      _x_x1697 = _x_7_0; /*float64*/
    }
    _x_x1696 = (_x_x1697 * 0x1p1); /*float64*/
    double _x_x1698;
    double _x_x1699;
    {
      double _x_8_0 = x_3_10305.lo;
      _x_x1699 = _x_8_0; /*float64*/
    }
    _x_x1698 = (_x_x1699 * 0x1p1); /*float64*/
    _x_x1695 = kk_std_num_ddouble__new_Ddouble(_x_x1696, _x_x1698, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1700;
    if (b_10096) {
      double z_1_0;
      double _x_x1701;
      {
        double _x_5_1_0 = z_0_0.num;
        _x_x1701 = _x_5_1_0; /*float64*/
      }
      z_1_0 = (_x_x1701 + e_0); /*float64*/
      double err_0_0;
      double _x_x1702;
      double _x_x1703;
      {
        double _x_5_1_1 = z_0_0.num;
        _x_x1703 = _x_5_1_1; /*float64*/
      }
      _x_x1702 = (z_1_0 - _x_x1703); /*float64*/
      err_0_0 = (e_0 - _x_x1702); /*float64*/
      double _x_x1704;
      bool _match_x816 = isfinite(z_1_0); /*bool*/;
      if (_match_x816) {
        _x_x1704 = err_0_0; /*float64*/
      }
      else {
        _x_x1704 = z_1_0; /*float64*/
      }
      _x_x1700 = kk_std_num_ddouble__new_Ddouble(z_1_0, _x_x1704, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double _x_x1705;
      {
        double _x_5_1_2 = z_0_0.num;
        _x_x1705 = _x_5_1_2; /*float64*/
      }
      _x_x1700 = kk_std_num_ddouble__new_Ddouble(_x_x1705, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    }
    _b_x303_305 = kk_std_num_ddouble__lp__plus__rp_(_x_x1695, _x_x1700, _ctx); /*std/num/ddouble/ddouble*/
    kk_ref_set_borrow(acc,(kk_std_num_ddouble__ddouble_box(_b_x303_305, _ctx)),kk_context());
    kk_integer_t _uniq_i_0_10005_10989 = kk_integer_add_small_const(_uniq_i_10986, 1, _ctx); /*int*/;
    { // tailcall
      _uniq_i_10986 = _uniq_i_0_10005_10989;
      goto kk__tailcall;
    }
  }
  {
    kk_ref_drop(acc, _ctx);
    kk_integer_drop(_uniq_i_10986, _ctx);
    kk_integer_drop(_uniq_end_10985, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// lifted local: exp, @spec-x10983
// specialized: std/core/repeat, on parameters @uniq-action@10978, using:
// @uniq-action@10978 = fn<((local :: H -> X)<(h :: H)>)>(){
//   val x@3@10305 : std/num/ddouble/ddouble;
//   val x@3@10710 : std/num/ddouble/ddouble;
//   val z@2 : float64;
//   val err@1 : float64;
//   val z@0@0 : std/num/ddouble/edouble;
//   val e@0 : float64;
//   val b@10096 : bool;
//   std/core/types/local-set<std/num/ddouble/ddouble,(total :: E),(h :: H)>(acc, (std/num/ddouble/(+)((std/num/ddouble/Ddouble((std/num/float64/(*)((match (x@3@10305) {
//             ((@skip std/num/ddouble/Ddouble((@x@7@0: float64) : float64, (@pat@0@8@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@12: std/num/ddouble/ddouble)
//                -> @x@7@0;
//           }), 2.0)), (std/num/float64/(*)((match (x@3@10305) {
//             ((@skip std/num/ddouble/Ddouble((@pat@0@9@0: float64) : float64, (@x@8@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@13: std/num/ddouble/ddouble)
//                -> @x@8@0;
//           }), 2.0)))), (match (b@10096) {
//         ((std/core/types/True() : bool ) as @pat@6@1: bool)
//            -> val z@1@0 : float64;
//               val err@0@0 : float64;
//           std/num/ddouble/Ddouble(z@1@0, (match ((std/num/float64/is-finite(z@1@0))) {
//               ((std/core/types/True() : bool ) as @pat@1@0@1: bool)
//                  -> err@0@0;
//               ((@skip std/core/types/False() : bool ) as @pat@2@0@1: bool)
//                  -> z@1@0;
//             }));
//         ((@skip std/core/types/False() : bool ) as @pat@0@5@2: bool)
//            -> std/num/ddouble/Ddouble((match (z@0@0) {
//               ((@skip std/num/ddouble/Edouble((@x@5@1: float64) : float64, (@pat@0@7@1: float64) : float64) : std/num/ddouble/edouble ) as @pat@8@0: std/num/ddouble/edouble)
//                  -> @x@5@1;
//             }), 0.0);
//       }))));
// }

kk_unit_t kk_std_num_ddouble__lift_exp_11072(kk_ref_t acc, kk_integer_t _uniq_n_10977, kk_context_t* _ctx) { /* forall<h> (acc : local-var<h,ddouble>, int) -> (local<h>) () */ 
  kk_integer_t _uniq_end_10012_10981;
  kk_integer_t _x_x1706 = kk_integer_dup(_uniq_n_10977, _ctx); /*int*/
  _uniq_end_10012_10981 = kk_integer_add_small_const(_x_x1706, -1, _ctx); /*int*/
  kk_std_num_ddouble__lift_exp_11073(acc, _uniq_end_10012_10981, kk_integer_from_small(0), _ctx); return kk_Unit;
}
 
// Return _e_ (`dd-e`) to the power of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double inv_k = (0x1p0 / 0x1p9); /*float64*/;
  bool _match_x810;
  double _x_x1707;
  {
    double _x = x.hi;
    _x_x1707 = _x; /*float64*/
  }
  _match_x810 = (_x_x1707 <= (-0x1.628p9)); /*bool*/
  if (_match_x810) {
    return kk_std_num_ddouble_zero;
  }
  {
    bool _match_x811;
    double _x_x1708;
    {
      double _x_0 = x.hi;
      _x_x1708 = _x_0; /*float64*/
    }
    _match_x811 = (_x_x1708 >= (0x1.628p9)); /*bool*/
    if (_match_x811) {
      return kk_std_num_ddouble_dd_posinf;
    }
    {
      bool _match_x812;
      double _x_x1709;
      {
        double _x_1 = x.hi;
        _x_x1709 = _x_1; /*float64*/
      }
      _match_x812 = (_x_x1709 == (0x0p+0)); /*bool*/
      if (_match_x812) {
        return kk_std_num_ddouble_one;
      }
      {
        bool _match_x813 = kk_std_num_ddouble__lp__eq__eq__rp_(x, kk_std_num_ddouble_one, _ctx); /*bool*/;
        if (_match_x813) {
          return kk_std_num_ddouble_dd_e;
        }
        {
          kk_integer_t m;
          double _x_x1710;
          double _x_x1711;
          double _x_x1712;
          double _x_x1713;
          {
            double _x_2 = x.hi;
            _x_x1713 = _x_2; /*float64*/
          }
          double _x_x1714;
          kk_std_num_ddouble__ddouble _x_x1715 = kk_std_num_ddouble_dd_ln2; /*std/num/ddouble/ddouble*/
          {
            double _x_3 = _x_x1715.hi;
            _x_x1714 = _x_3; /*float64*/
          }
          _x_x1712 = (_x_x1713 / _x_x1714); /*float64*/
          _x_x1711 = (_x_x1712 + (0x1p-1)); /*float64*/
          _x_x1710 = floor(_x_x1711); /*float64*/
          m = kk_integer_from_double(_x_x1710,kk_context()); /*int*/
          kk_std_num_ddouble__ddouble x_0_10706;
          kk_integer_t _x_x1716 = kk_integer_dup(m, _ctx); /*int*/
          x_0_10706 = kk_std_num_ddouble_ddouble_int_exp(_x_x1716, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
          double z;
          double _x_x1717;
          {
            double _x_4 = x_0_10706.hi;
            _x_x1717 = _x_4; /*float64*/
          }
          double _x_x1718;
          kk_std_num_ddouble__ddouble _x_x1719 = kk_std_num_ddouble_dd_ln2; /*std/num/ddouble/ddouble*/
          {
            double _x_0_0 = _x_x1719.hi;
            _x_x1718 = _x_0_0; /*float64*/
          }
          z = (_x_x1717 * _x_x1718); /*float64*/
          double err;
          double _x_x1720;
          {
            double _x_4_0 = x_0_10706.hi;
            _x_x1720 = _x_4_0; /*float64*/
          }
          double _x_x1721;
          kk_std_num_ddouble__ddouble _x_x1722 = kk_std_num_ddouble_dd_ln2; /*std/num/ddouble/ddouble*/
          {
            double _x_0_0_0 = _x_x1722.hi;
            _x_x1721 = _x_0_0_0; /*float64*/
          }
          double _x_x1723 = (-z); /*float64*/
          err = kk_std_num_float64_fmadd(_x_x1720, _x_x1721, _x_x1723, _ctx); /*float64*/
          kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
          double e;
          double _x_x1724;
          {
            double _x_1_0 = z_0.err;
            _x_x1724 = _x_1_0; /*float64*/
          }
          double _x_x1725;
          double _x_x1726;
          double _x_x1727;
          {
            double _x_2_0 = x_0_10706.hi;
            _x_x1727 = _x_2_0; /*float64*/
          }
          double _x_x1728;
          kk_std_num_ddouble__ddouble _x_x1729 = kk_std_num_ddouble_dd_ln2; /*std/num/ddouble/ddouble*/
          {
            double _x_3_0 = _x_x1729.lo;
            _x_x1728 = _x_3_0; /*float64*/
          }
          _x_x1726 = (_x_x1727 * _x_x1728); /*float64*/
          double _x_x1730;
          double _x_x1731;
          {
            double _x_4_0_0 = x_0_10706.lo;
            _x_x1731 = _x_4_0_0; /*float64*/
          }
          double _x_x1732;
          kk_std_num_ddouble__ddouble _x_x1733 = kk_std_num_ddouble_dd_ln2; /*std/num/ddouble/ddouble*/
          {
            double _x_5 = _x_x1733.hi;
            _x_x1732 = _x_5; /*float64*/
          }
          _x_x1730 = (_x_x1731 * _x_x1732); /*float64*/
          _x_x1725 = (_x_x1726 + _x_x1730); /*float64*/
          e = (_x_x1724 + _x_x1725); /*float64*/
          bool b_10040;
          double _x_x1734;
          {
            double _x_6 = z_0.num;
            _x_x1734 = _x_6; /*float64*/
          }
          b_10040 = isfinite(_x_x1734); /*bool*/
          kk_std_num_ddouble__ddouble y_10300;
          if (b_10040) {
            double z_1;
            double _x_x1735;
            {
              double _x_6_0 = z_0.num;
              _x_x1735 = _x_6_0; /*float64*/
            }
            z_1 = (_x_x1735 + e); /*float64*/
            double err_0;
            double _x_x1736;
            double _x_x1737;
            {
              double _x_6_1 = z_0.num;
              _x_x1737 = _x_6_1; /*float64*/
            }
            _x_x1736 = (z_1 - _x_x1737); /*float64*/
            err_0 = (e - _x_x1736); /*float64*/
            double _x_x1738;
            bool _match_x814 = isfinite(z_1); /*bool*/;
            if (_match_x814) {
              _x_x1738 = err_0; /*float64*/
            }
            else {
              _x_x1738 = z_1; /*float64*/
            }
            y_10300 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x1738, _ctx); /*std/num/ddouble/ddouble*/
          }
          else {
            double _x_x1739;
            {
              double _x_6_2 = z_0.num;
              _x_x1739 = _x_6_2; /*float64*/
            }
            y_10300 = kk_std_num_ddouble__new_Ddouble(_x_x1739, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          }
          kk_std_num_ddouble__ddouble x_1_10297;
          kk_std_num_ddouble__ddouble _x_x1740;
          double _x_x1741;
          double _x_x1742;
          {
            double _x_7 = y_10300.hi;
            _x_x1742 = _x_7; /*float64*/
          }
          _x_x1741 = (-_x_x1742); /*float64*/
          double _x_x1743;
          double _x_x1744;
          {
            double _x_0_1 = y_10300.lo;
            _x_x1744 = _x_0_1; /*float64*/
          }
          _x_x1743 = (-_x_x1744); /*float64*/
          _x_x1740 = kk_std_num_ddouble__new_Ddouble(_x_x1741, _x_x1743, _ctx); /*std/num/ddouble/ddouble*/
          x_1_10297 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x1740, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble r;
          double _x_x1745;
          double _x_x1746;
          {
            double _x_4_1 = x_1_10297.hi;
            _x_x1746 = _x_4_1; /*float64*/
          }
          _x_x1745 = (_x_x1746 * inv_k); /*float64*/
          double _x_x1747;
          double _x_x1748;
          {
            double _x_5_0 = x_1_10297.lo;
            _x_x1748 = _x_5_0; /*float64*/
          }
          _x_x1747 = (_x_x1748 * inv_k); /*float64*/
          r = kk_std_num_ddouble__new_Ddouble(_x_x1745, _x_x1747, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble p_0 = kk_std_num_ddouble_sqr(r, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble t;
          kk_std_num_ddouble__ddouble _x_x1749;
          double _x_x1750;
          double _x_x1751;
          {
            double _x_8 = p_0.hi;
            _x_x1751 = _x_8; /*float64*/
          }
          _x_x1750 = (_x_x1751 * (0x1p-1)); /*float64*/
          double _x_x1752;
          double _x_x1753;
          {
            double _x_0_2 = p_0.lo;
            _x_x1753 = _x_0_2; /*float64*/
          }
          _x_x1752 = (_x_x1753 * (0x1p-1)); /*float64*/
          _x_x1749 = kk_std_num_ddouble__new_Ddouble(_x_x1750, _x_x1752, _ctx); /*std/num/ddouble/ddouble*/
          t = kk_std_num_ddouble__lp__plus__rp_(r, _x_x1749, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble init_11308;
          double _x_x1754;
          double _x_x1755;
          kk_std_num_ddouble__ddouble _x_x1756 = kk_std_num_ddouble_dd_epsilon; /*std/num/ddouble/ddouble*/
          {
            double _x_6_0_0 = _x_x1756.hi;
            _x_x1755 = _x_6_0_0; /*float64*/
          }
          _x_x1754 = (inv_k * _x_x1755); /*float64*/
          kk_std_core_types__list _x_x1757 = kk_std_core_types__list_dup(kk_std_num_ddouble_exp_factors, _ctx); /*list<std/num/ddouble/ddouble>*/
          init_11308 = kk_std_num_ddouble_exp_approx(p_0, t, r, _x_x1754, _x_x1757, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/ddouble/ddouble*/
          kk_ref_t loc = kk_ref_alloc((kk_std_num_ddouble__ddouble_box(init_11308, _ctx)),kk_context()); /*local-var<5910,std/num/ddouble/ddouble>*/;
          kk_unit_t __ = kk_Unit;
          kk_ref_t _x_x1758 = kk_ref_dup(loc, _ctx); /*local-var<5910,std/num/ddouble/ddouble>*/
          kk_std_num_ddouble__lift_exp_11072(_x_x1758, kk_integer_from_small(9), _ctx);
          kk_std_num_ddouble__ddouble _b_x311_313;
          kk_std_num_ddouble__ddouble _x_x1759;
          kk_box_t _x_x1760;
          kk_ref_t _x_x1761 = kk_ref_dup(loc, _ctx); /*local-var<5910,std/num/ddouble/ddouble>*/
          _x_x1760 = kk_ref_get(_x_x1761,kk_context()); /*10000*/
          _x_x1759 = kk_std_num_ddouble__ddouble_unbox(_x_x1760, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
          _b_x311_313 = kk_std_num_ddouble__lp__plus__rp_(_x_x1759, kk_std_num_ddouble_one, _ctx); /*std/num/ddouble/ddouble*/
          kk_unit_t ___0 = kk_Unit;
          kk_ref_set_borrow(loc,(kk_std_num_ddouble__ddouble_box(_b_x311_313, _ctx)),kk_context());
          kk_std_num_ddouble__ddouble x_5_10310;
          kk_box_t _x_x1762;
          kk_ref_t _x_x1763 = kk_ref_dup(loc, _ctx); /*local-var<5910,std/num/ddouble/ddouble>*/
          _x_x1762 = kk_ref_get(_x_x1763,kk_context()); /*10000*/
          x_5_10310 = kk_std_num_ddouble__ddouble_unbox(_x_x1762, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble res;
          double _x_x1764;
          double _x_x1765;
          {
            double _x_9_0_0 = x_5_10310.hi;
            _x_x1765 = _x_9_0_0; /*float64*/
          }
          kk_integer_t _x_x1766 = kk_integer_dup(m, _ctx); /*int*/
          _x_x1764 = kk_std_num_float64_ldexp(_x_x1765, _x_x1766, _ctx); /*float64*/
          double _x_x1767;
          double _x_x1768;
          {
            double _x_10 = x_5_10310.lo;
            _x_x1768 = _x_10; /*float64*/
          }
          _x_x1767 = kk_std_num_float64_ldexp(_x_x1768, m, _ctx); /*float64*/
          res = kk_std_num_ddouble__new_Ddouble(_x_x1764, _x_x1767, _ctx); /*std/num/ddouble/ddouble*/
          kk_box_t _x_x1769 = kk_std_core_hnd_prompt_local_var(loc, kk_std_num_ddouble__ddouble_box(res, _ctx), _ctx); /*10001*/
          return kk_std_num_ddouble__ddouble_unbox(_x_x1769, KK_OWNED, _ctx);
        }
      }
    }
  }
}
 
// The natural logarithm (in base _e_) of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ln(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x804 = kk_std_num_ddouble__lp__lt__eq__rp_(x, kk_std_num_ddouble_zero, _ctx); /*bool*/;
  if (_match_x804) {
    bool _match_x809 = kk_std_num_ddouble__lp__eq__eq__rp_(x, kk_std_num_ddouble_zero, _ctx); /*bool*/;
    if (_match_x809) {
      return kk_std_num_ddouble_dd_neginf;
    }
    {
      return kk_std_num_ddouble_dd_nan;
    }
  }
  {
    bool _match_x805 = kk_std_num_ddouble__lp__eq__eq__rp_(x, kk_std_num_ddouble_one, _ctx); /*bool*/;
    if (_match_x805) {
      return kk_std_num_ddouble_zero;
    }
    {
      bool _match_x806 = kk_std_num_ddouble__lp__eq__eq__rp_(x, kk_std_num_ddouble_dd_e, _ctx); /*bool*/;
      if (_match_x806) {
        return kk_std_num_ddouble_one;
      }
      {
        bool _match_x807;
        double _x_x1770;
        {
          double _x = x.hi;
          _x_x1770 = _x; /*float64*/
        }
        _match_x807 = (isinf(_x_x1770) && !signbit(_x_x1770)); /*bool*/
        if (_match_x807) {
          return x;
        }
        {
          double d_10316;
          double _x_x1771;
          {
            double _x_0 = x.hi;
            _x_x1771 = _x_0; /*float64*/
          }
          d_10316 = log(_x_x1771); /*float64*/
          kk_std_num_ddouble__ddouble a0 = kk_std_num_ddouble__new_Ddouble(d_10316, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble y_10712;
          kk_std_num_ddouble__ddouble _x_x1772;
          double _x_x1773;
          double _x_x1774;
          {
            double _x_7 = a0.hi;
            _x_x1774 = _x_7; /*float64*/
          }
          _x_x1773 = (-_x_x1774); /*float64*/
          double _x_x1775;
          double _x_x1776;
          {
            double _x_0_1 = a0.lo;
            _x_x1776 = _x_0_1; /*float64*/
          }
          _x_x1775 = (-_x_x1776); /*float64*/
          _x_x1772 = kk_std_num_ddouble__new_Ddouble(_x_x1773, _x_x1775, _ctx); /*std/num/ddouble/ddouble*/
          y_10712 = kk_std_num_ddouble_exp(_x_x1772, _ctx); /*std/num/ddouble/ddouble*/
          double z;
          double _x_x1777;
          {
            double _x_1 = x.hi;
            _x_x1777 = _x_1; /*float64*/
          }
          double _x_x1778;
          {
            double _x_0_0 = y_10712.hi;
            _x_x1778 = _x_0_0; /*float64*/
          }
          z = (_x_x1777 * _x_x1778); /*float64*/
          double err;
          double _x_x1779;
          {
            double _x_1_0 = x.hi;
            _x_x1779 = _x_1_0; /*float64*/
          }
          double _x_x1780;
          {
            double _x_0_0_0 = y_10712.hi;
            _x_x1780 = _x_0_0_0; /*float64*/
          }
          double _x_x1781 = (-z); /*float64*/
          err = kk_std_num_float64_fmadd(_x_x1779, _x_x1780, _x_x1781, _ctx); /*float64*/
          kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
          double e;
          double _x_x1782;
          {
            double _x_1_0_0 = z_0.err;
            _x_x1782 = _x_1_0_0; /*float64*/
          }
          double _x_x1783;
          double _x_x1784;
          double _x_x1785;
          {
            double _x_2 = x.hi;
            _x_x1785 = _x_2; /*float64*/
          }
          double _x_x1786;
          {
            double _x_3 = y_10712.lo;
            _x_x1786 = _x_3; /*float64*/
          }
          _x_x1784 = (_x_x1785 * _x_x1786); /*float64*/
          double _x_x1787;
          double _x_x1788;
          {
            double _x_4 = x.lo;
            _x_x1788 = _x_4; /*float64*/
          }
          double _x_x1789;
          {
            double _x_5 = y_10712.hi;
            _x_x1789 = _x_5; /*float64*/
          }
          _x_x1787 = (_x_x1788 * _x_x1789); /*float64*/
          _x_x1783 = (_x_x1784 + _x_x1787); /*float64*/
          e = (_x_x1782 + _x_x1783); /*float64*/
          bool b_10040;
          double _x_x1790;
          {
            double _x_6 = z_0.num;
            _x_x1790 = _x_6; /*float64*/
          }
          b_10040 = isfinite(_x_x1790); /*bool*/
          kk_std_num_ddouble__ddouble x_1_10318;
          if (b_10040) {
            double z_1;
            double _x_x1791;
            {
              double _x_6_0 = z_0.num;
              _x_x1791 = _x_6_0; /*float64*/
            }
            z_1 = (_x_x1791 + e); /*float64*/
            double err_0;
            double _x_x1792;
            double _x_x1793;
            {
              double _x_6_1 = z_0.num;
              _x_x1793 = _x_6_1; /*float64*/
            }
            _x_x1792 = (z_1 - _x_x1793); /*float64*/
            err_0 = (e - _x_x1792); /*float64*/
            double _x_x1794;
            bool _match_x808 = isfinite(z_1); /*bool*/;
            if (_match_x808) {
              _x_x1794 = err_0; /*float64*/
            }
            else {
              _x_x1794 = z_1; /*float64*/
            }
            x_1_10318 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x1794, _ctx); /*std/num/ddouble/ddouble*/
          }
          else {
            double _x_x1795;
            {
              double _x_6_2 = z_0.num;
              _x_x1795 = _x_6_2; /*float64*/
            }
            x_1_10318 = kk_std_num_ddouble__new_Ddouble(_x_x1795, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          }
          kk_std_num_ddouble__ddouble _x_x1796;
          kk_std_num_ddouble__ddouble _x_x1797;
          double _x_x1798;
          double _x_x1799;
          kk_std_num_ddouble__ddouble _x_x1800 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
          {
            double _x_8 = _x_x1800.hi;
            _x_x1799 = _x_8; /*float64*/
          }
          _x_x1798 = (-_x_x1799); /*float64*/
          double _x_x1801;
          double _x_x1802;
          kk_std_num_ddouble__ddouble _x_x1803 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
          {
            double _x_0_2 = _x_x1803.lo;
            _x_x1802 = _x_0_2; /*float64*/
          }
          _x_x1801 = (-_x_x1802); /*float64*/
          _x_x1797 = kk_std_num_ddouble__new_Ddouble(_x_x1798, _x_x1801, _ctx); /*std/num/ddouble/ddouble*/
          _x_x1796 = kk_std_num_ddouble__lp__plus__rp_(x_1_10318, _x_x1797, _ctx); /*std/num/ddouble/ddouble*/
          return kk_std_num_ddouble__lp__plus__rp_(a0, _x_x1796, _ctx);
        }
      }
    }
  }
}
 
// `x` to the power of `y` both as `:ddouble`

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pow(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble y_0_10716 = kk_std_num_ddouble_ln(x, _ctx); /*std/num/ddouble/ddouble*/;
  double z;
  double _x_x1804;
  {
    double _x = y.hi;
    _x_x1804 = _x; /*float64*/
  }
  double _x_x1805;
  {
    double _x_0 = y_0_10716.hi;
    _x_x1805 = _x_0; /*float64*/
  }
  z = (_x_x1804 * _x_x1805); /*float64*/
  double err;
  double _x_x1806;
  {
    double _x_1 = y.hi;
    _x_x1806 = _x_1; /*float64*/
  }
  double _x_x1807;
  {
    double _x_0_0 = y_0_10716.hi;
    _x_x1807 = _x_0_0; /*float64*/
  }
  double _x_x1808 = (-z); /*float64*/
  err = kk_std_num_float64_fmadd(_x_x1806, _x_x1807, _x_x1808, _ctx); /*float64*/
  kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
  double e;
  double _x_x1809;
  {
    double _x_1_0 = z_0.err;
    _x_x1809 = _x_1_0; /*float64*/
  }
  double _x_x1810;
  double _x_x1811;
  double _x_x1812;
  {
    double _x_2 = y.hi;
    _x_x1812 = _x_2; /*float64*/
  }
  double _x_x1813;
  {
    double _x_3 = y_0_10716.lo;
    _x_x1813 = _x_3; /*float64*/
  }
  _x_x1811 = (_x_x1812 * _x_x1813); /*float64*/
  double _x_x1814;
  double _x_x1815;
  {
    double _x_4 = y.lo;
    _x_x1815 = _x_4; /*float64*/
  }
  double _x_x1816;
  {
    double _x_5 = y_0_10716.hi;
    _x_x1816 = _x_5; /*float64*/
  }
  _x_x1814 = (_x_x1815 * _x_x1816); /*float64*/
  _x_x1810 = (_x_x1811 + _x_x1814); /*float64*/
  e = (_x_x1809 + _x_x1810); /*float64*/
  bool b_10040;
  double _x_x1817;
  {
    double _x_6 = z_0.num;
    _x_x1817 = _x_6; /*float64*/
  }
  b_10040 = isfinite(_x_x1817); /*bool*/
  kk_std_num_ddouble__ddouble _x_x1818;
  if (b_10040) {
    double z_1;
    double _x_x1819;
    {
      double _x_6_0 = z_0.num;
      _x_x1819 = _x_6_0; /*float64*/
    }
    z_1 = (_x_x1819 + e); /*float64*/
    double err_0;
    double _x_x1820;
    double _x_x1821;
    {
      double _x_6_1 = z_0.num;
      _x_x1821 = _x_6_1; /*float64*/
    }
    _x_x1820 = (z_1 - _x_x1821); /*float64*/
    err_0 = (e - _x_x1820); /*float64*/
    double _x_x1822;
    bool _match_x803 = isfinite(z_1); /*bool*/;
    if (_match_x803) {
      _x_x1822 = err_0; /*float64*/
    }
    else {
      _x_x1822 = z_1; /*float64*/
    }
    _x_x1818 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x1822, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double _x_x1823;
    {
      double _x_6_2 = z_0.num;
      _x_x1823 = _x_6_2; /*float64*/
    }
    _x_x1818 = kk_std_num_ddouble__new_Ddouble(_x_x1823, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble_exp(_x_x1818, _ctx);
}
 
// Return 10 to the power of `exp`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp10(kk_std_num_ddouble__ddouble exp_0, kk_context_t* _ctx) { /* (exp : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble y_10718 = kk_std_num_ddouble_ln(kk_std_num_ddouble_ten, _ctx); /*std/num/ddouble/ddouble*/;
  double z;
  double _x_x1824;
  {
    double _x = exp_0.hi;
    _x_x1824 = _x; /*float64*/
  }
  double _x_x1825;
  {
    double _x_0 = y_10718.hi;
    _x_x1825 = _x_0; /*float64*/
  }
  z = (_x_x1824 * _x_x1825); /*float64*/
  double err;
  double _x_x1826;
  {
    double _x_1 = exp_0.hi;
    _x_x1826 = _x_1; /*float64*/
  }
  double _x_x1827;
  {
    double _x_0_0 = y_10718.hi;
    _x_x1827 = _x_0_0; /*float64*/
  }
  double _x_x1828 = (-z); /*float64*/
  err = kk_std_num_float64_fmadd(_x_x1826, _x_x1827, _x_x1828, _ctx); /*float64*/
  kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
  double e;
  double _x_x1829;
  {
    double _x_1_0 = z_0.err;
    _x_x1829 = _x_1_0; /*float64*/
  }
  double _x_x1830;
  double _x_x1831;
  double _x_x1832;
  {
    double _x_2 = exp_0.hi;
    _x_x1832 = _x_2; /*float64*/
  }
  double _x_x1833;
  {
    double _x_3 = y_10718.lo;
    _x_x1833 = _x_3; /*float64*/
  }
  _x_x1831 = (_x_x1832 * _x_x1833); /*float64*/
  double _x_x1834;
  double _x_x1835;
  {
    double _x_4 = exp_0.lo;
    _x_x1835 = _x_4; /*float64*/
  }
  double _x_x1836;
  {
    double _x_5 = y_10718.hi;
    _x_x1836 = _x_5; /*float64*/
  }
  _x_x1834 = (_x_x1835 * _x_x1836); /*float64*/
  _x_x1830 = (_x_x1831 + _x_x1834); /*float64*/
  e = (_x_x1829 + _x_x1830); /*float64*/
  bool b_10040;
  double _x_x1837;
  {
    double _x_6 = z_0.num;
    _x_x1837 = _x_6; /*float64*/
  }
  b_10040 = isfinite(_x_x1837); /*bool*/
  kk_std_num_ddouble__ddouble _x_x1838;
  if (b_10040) {
    double z_1;
    double _x_x1839;
    {
      double _x_6_0 = z_0.num;
      _x_x1839 = _x_6_0; /*float64*/
    }
    z_1 = (_x_x1839 + e); /*float64*/
    double err_0;
    double _x_x1840;
    double _x_x1841;
    {
      double _x_6_1 = z_0.num;
      _x_x1841 = _x_6_1; /*float64*/
    }
    _x_x1840 = (z_1 - _x_x1841); /*float64*/
    err_0 = (e - _x_x1840); /*float64*/
    double _x_x1842;
    bool _match_x802 = isfinite(z_1); /*bool*/;
    if (_match_x802) {
      _x_x1842 = err_0; /*float64*/
    }
    else {
      _x_x1842 = z_1; /*float64*/
    }
    _x_x1838 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x1842, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double _x_x1843;
    {
      double _x_6_2 = z_0.num;
      _x_x1843 = _x_6_2; /*float64*/
    }
    _x_x1838 = kk_std_num_ddouble__new_Ddouble(_x_x1843, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble_exp(_x_x1838, _ctx);
}
 
// Return 2 to the power of `exp`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp2(kk_std_num_ddouble__ddouble exp_0, kk_context_t* _ctx) { /* (exp : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble y_10720 = kk_std_num_ddouble_ln(kk_std_num_ddouble_two, _ctx); /*std/num/ddouble/ddouble*/;
  double z;
  double _x_x1844;
  {
    double _x = exp_0.hi;
    _x_x1844 = _x; /*float64*/
  }
  double _x_x1845;
  {
    double _x_0 = y_10720.hi;
    _x_x1845 = _x_0; /*float64*/
  }
  z = (_x_x1844 * _x_x1845); /*float64*/
  double err;
  double _x_x1846;
  {
    double _x_1 = exp_0.hi;
    _x_x1846 = _x_1; /*float64*/
  }
  double _x_x1847;
  {
    double _x_0_0 = y_10720.hi;
    _x_x1847 = _x_0_0; /*float64*/
  }
  double _x_x1848 = (-z); /*float64*/
  err = kk_std_num_float64_fmadd(_x_x1846, _x_x1847, _x_x1848, _ctx); /*float64*/
  kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
  double e;
  double _x_x1849;
  {
    double _x_1_0 = z_0.err;
    _x_x1849 = _x_1_0; /*float64*/
  }
  double _x_x1850;
  double _x_x1851;
  double _x_x1852;
  {
    double _x_2 = exp_0.hi;
    _x_x1852 = _x_2; /*float64*/
  }
  double _x_x1853;
  {
    double _x_3 = y_10720.lo;
    _x_x1853 = _x_3; /*float64*/
  }
  _x_x1851 = (_x_x1852 * _x_x1853); /*float64*/
  double _x_x1854;
  double _x_x1855;
  {
    double _x_4 = exp_0.lo;
    _x_x1855 = _x_4; /*float64*/
  }
  double _x_x1856;
  {
    double _x_5 = y_10720.hi;
    _x_x1856 = _x_5; /*float64*/
  }
  _x_x1854 = (_x_x1855 * _x_x1856); /*float64*/
  _x_x1850 = (_x_x1851 + _x_x1854); /*float64*/
  e = (_x_x1849 + _x_x1850); /*float64*/
  bool b_10040;
  double _x_x1857;
  {
    double _x_6 = z_0.num;
    _x_x1857 = _x_6; /*float64*/
  }
  b_10040 = isfinite(_x_x1857); /*bool*/
  kk_std_num_ddouble__ddouble _x_x1858;
  if (b_10040) {
    double z_1;
    double _x_x1859;
    {
      double _x_6_0 = z_0.num;
      _x_x1859 = _x_6_0; /*float64*/
    }
    z_1 = (_x_x1859 + e); /*float64*/
    double err_0;
    double _x_x1860;
    double _x_x1861;
    {
      double _x_6_1 = z_0.num;
      _x_x1861 = _x_6_1; /*float64*/
    }
    _x_x1860 = (z_1 - _x_x1861); /*float64*/
    err_0 = (e - _x_x1860); /*float64*/
    double _x_x1862;
    bool _match_x801 = isfinite(z_1); /*bool*/;
    if (_match_x801) {
      _x_x1862 = err_0; /*float64*/
    }
    else {
      _x_x1862 = z_1; /*float64*/
    }
    _x_x1858 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x1862, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double _x_x1863;
    {
      double _x_6_2 = z_0.num;
      _x_x1863 = _x_6_2; /*float64*/
    }
    _x_x1858 = kk_std_num_ddouble__new_Ddouble(_x_x1863, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble_exp(_x_x1858, _ctx);
}
 
// Show a `:ddouble` `x` with a given precision `prec` (=`-31`).
// The precision specifies the  number of digits after the dot (in either scientific of fixed-point notation).
// If the precision is negative, _at most_ `prec` digits are displayed, while for a positive
// precision, exactly `prec` digits behind the dot are displayed.
// This uses `show-fixed` when the exponent of `x` in scientific notation is larger than -5
// and smaller than the precision (or 15 in case of a negative precision), otherwise it uses `show-exp`.

kk_string_t kk_std_num_ddouble_show(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : ? int) -> string */ 
  bool b_10324;
  bool _match_x800;
  double _x_x1864;
  {
    double _x = x.hi;
    _x_x1864 = _x; /*float64*/
  }
  _match_x800 = isfinite(_x_x1864); /*bool*/
  if (_match_x800) {
    double _x_x1865;
    {
      double _x_0 = x.lo;
      _x_x1865 = _x_0; /*float64*/
    }
    b_10324 = isfinite(_x_x1865); /*bool*/
  }
  else {
    b_10324 = false; /*bool*/
  }
  if (b_10324) {
    bool b_0_10328;
    bool _match_x799;
    double _x_x1866;
    {
      double _x_1 = x.hi;
      _x_x1866 = _x_1; /*float64*/
    }
    _match_x799 = isfinite(_x_x1866); /*bool*/
    if (_match_x799) {
      double _x_x1867;
      {
        double _x_0_0 = x.lo;
        _x_x1867 = _x_0_0; /*float64*/
      }
      b_0_10328 = isfinite(_x_x1867); /*bool*/
    }
    else {
      b_0_10328 = false; /*bool*/
    }
    kk_std_num_decimal__decimal _x_x1868;
    if (b_0_10328) {
      kk_std_num_decimal__decimal x_1_10329;
      double _x_x1869;
      {
        double _x_3 = x.hi;
        _x_x1869 = _x_3; /*float64*/
      }
      kk_std_core_types__optional _x_x1870;
      kk_box_t _x_x1871;
      kk_integer_t _x_x1872;
      kk_std_core_types__optional _match_x798 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x798, _ctx)) {
        kk_box_t _box_x324 = _match_x798._cons._Optional.value;
        kk_integer_t _uniq_prec_4427 = kk_integer_unbox(_box_x324, _ctx);
        kk_integer_dup(_uniq_prec_4427, _ctx);
        kk_std_core_types__optional_drop(_match_x798, _ctx);
        _x_x1872 = _uniq_prec_4427; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x798, _ctx);
        _x_x1872 = kk_integer_from_small(-1); /*int*/
      }
      _x_x1871 = kk_integer_box(_x_x1872, _ctx); /*10003*/
      _x_x1870 = kk_std_core_types__new_Optional(_x_x1871, _ctx); /*? 10003*/
      x_1_10329 = kk_std_num_decimal_float64_fs_decimal(_x_x1869, _x_x1870, _ctx); /*std/num/decimal/decimal*/
      kk_std_num_decimal__decimal y_10330;
      double _x_x1873;
      {
        double _x_4 = x.lo;
        _x_x1873 = _x_4; /*float64*/
      }
      kk_std_core_types__optional _x_x1874;
      kk_box_t _x_x1875;
      kk_integer_t _x_x1876;
      kk_std_core_types__optional _match_x797 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x797, _ctx)) {
        kk_box_t _box_x327 = _match_x797._cons._Optional.value;
        kk_integer_t _uniq_prec_4427_0 = kk_integer_unbox(_box_x327, _ctx);
        kk_integer_dup(_uniq_prec_4427_0, _ctx);
        kk_std_core_types__optional_drop(_match_x797, _ctx);
        _x_x1876 = _uniq_prec_4427_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x797, _ctx);
        _x_x1876 = kk_integer_from_small(-1); /*int*/
      }
      _x_x1875 = kk_integer_box(_x_x1876, _ctx); /*10003*/
      _x_x1874 = kk_std_core_types__new_Optional(_x_x1875, _ctx); /*? 10003*/
      y_10330 = kk_std_num_decimal_float64_fs_decimal(_x_x1873, _x_x1874, _ctx); /*std/num/decimal/decimal*/
      kk_integer_t e;
      bool _match_x793;
      kk_integer_t _brw_x795;
      {
        kk_integer_t _x_0_1 = x_1_10329.exp;
        kk_integer_dup(_x_0_1, _ctx);
        _brw_x795 = _x_0_1; /*int*/
      }
      kk_integer_t _brw_x794;
      {
        kk_integer_t _x_0_0_0 = y_10330.exp;
        kk_integer_dup(_x_0_0_0, _ctx);
        _brw_x794 = _x_0_0_0; /*int*/
      }
      bool _brw_x796 = kk_integer_lte_borrow(_brw_x795,_brw_x794,kk_context()); /*bool*/;
      kk_integer_drop(_brw_x795, _ctx);
      kk_integer_drop(_brw_x794, _ctx);
      _match_x793 = _brw_x796; /*bool*/
      if (_match_x793) {
        kk_integer_t _x_1_0 = x_1_10329.exp;
        kk_integer_dup(_x_1_0, _ctx);
        e = _x_1_0; /*int*/
      }
      else {
        kk_integer_t _x_0_0_0_0 = y_10330.exp;
        kk_integer_dup(_x_0_0_0_0, _ctx);
        e = _x_0_0_0_0; /*int*/
      }
      kk_std_num_decimal__decimal xx;
      kk_integer_t _x_x1877 = kk_integer_dup(e, _ctx); /*int*/
      xx = kk_std_num_decimal_expand(x_1_10329, _x_x1877, _ctx); /*std/num/decimal/decimal*/
      kk_std_num_decimal__decimal yy;
      kk_integer_t _x_x1878 = kk_integer_dup(e, _ctx); /*int*/
      yy = kk_std_num_decimal_expand(y_10330, _x_x1878, _ctx); /*std/num/decimal/decimal*/
      kk_integer_t _x_x1879;
      kk_integer_t _x_x1880;
      {
        kk_integer_t _x_1_0_0 = xx.num;
        kk_integer_dup(_x_1_0_0, _ctx);
        kk_std_num_decimal__decimal_drop(xx, _ctx);
        _x_x1880 = _x_1_0_0; /*int*/
      }
      kk_integer_t _x_x1881;
      {
        kk_integer_t _x_2 = yy.num;
        kk_integer_dup(_x_2, _ctx);
        kk_std_num_decimal__decimal_drop(yy, _ctx);
        _x_x1881 = _x_2; /*int*/
      }
      _x_x1879 = kk_integer_add(_x_x1880,_x_x1881,kk_context()); /*int*/
      _x_x1868 = kk_std_num_decimal__new_Decimal(_x_x1879, e, _ctx); /*std/num/decimal/decimal*/
    }
    else {
      _x_x1868 = kk_std_num_decimal_int_fs_decimal(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
    }
    kk_std_core_types__optional _x_x1882;
    kk_box_t _x_x1883;
    kk_integer_t _x_x1884;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x330 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_6425 = kk_integer_unbox(_box_x330, _ctx);
      kk_integer_dup(_uniq_prec_6425, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1884 = _uniq_prec_6425; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1884 = kk_integer_from_small(-31); /*int*/
    }
    _x_x1883 = kk_integer_box(_x_x1884, _ctx); /*10003*/
    _x_x1882 = kk_std_core_types__new_Optional(_x_x1883, _ctx); /*? 10003*/
    return kk_std_num_decimal_show(_x_x1868, _x_x1882, _ctx);
  }
  {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x_x1885;
    {
      double _x_5 = x.hi;
      _x_x1885 = _x_5; /*float64*/
    }
    return kk_std_num_float64_show(_x_x1885, kk_std_core_types__new_None(_ctx), _ctx);
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
  bool b_10333;
  bool _match_x792;
  double _x_x1886;
  {
    double _x = x.hi;
    _x_x1886 = _x; /*float64*/
  }
  _match_x792 = isfinite(_x_x1886); /*bool*/
  if (_match_x792) {
    double _x_x1887;
    {
      double _x_0 = x.lo;
      _x_x1887 = _x_0; /*float64*/
    }
    b_10333 = isfinite(_x_x1887); /*bool*/
  }
  else {
    b_10333 = false; /*bool*/
  }
  if (b_10333) {
    kk_integer_t _b_x334_345;
    if (kk_std_core_types__is_Optional(width, _ctx)) {
      kk_box_t _box_x333 = width._cons._Optional.value;
      kk_integer_t _uniq_width_6640 = kk_integer_unbox(_box_x333, _ctx);
      kk_integer_dup(_uniq_width_6640, _ctx);
      _b_x334_345 = _uniq_width_6640; /*int*/
    }
    else {
      _b_x334_345 = kk_integer_from_small(1); /*int*/
    }
    bool _b_x336_346;
    if (kk_std_core_types__is_Optional(use_capitals, _ctx)) {
      kk_box_t _box_x335 = use_capitals._cons._Optional.value;
      bool _uniq_use_capitals_6644 = kk_bool_unbox(_box_x335);
      _b_x336_346 = _uniq_use_capitals_6644; /*bool*/
    }
    else {
      _b_x336_346 = true; /*bool*/
    }
    kk_string_t _b_x338_347;
    if (kk_std_core_types__is_Optional(pre, _ctx)) {
      kk_box_t _box_x337 = pre._cons._Optional.value;
      kk_string_t _uniq_pre_6648 = kk_string_unbox(_box_x337);
      kk_string_dup(_uniq_pre_6648, _ctx);
      _b_x338_347 = _uniq_pre_6648; /*string*/
    }
    else {
      kk_define_string_literal(, _s_x1888, 2, "0x", _ctx)
      _b_x338_347 = kk_string_dup(_s_x1888, _ctx); /*string*/
    }
    kk_string_t _x_x1889;
    double _x_x1890;
    {
      double _x_0_0 = x.hi;
      _x_x1890 = _x_0_0; /*float64*/
    }
    kk_std_core_types__optional _x_x1891 = kk_std_core_types__new_Optional(kk_integer_box(_b_x334_345, _ctx), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1892 = kk_std_core_types__new_Optional(kk_bool_box(_b_x336_346), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1893 = kk_std_core_types__new_Optional(kk_string_box(_b_x338_347), _ctx); /*? 10003*/
    _x_x1889 = kk_std_num_float64_show_hex(_x_x1890, _x_x1891, _x_x1892, _x_x1893, _ctx); /*string*/
    kk_string_t _x_x1894;
    kk_integer_t _b_x340_348;
    if (kk_std_core_types__is_Optional(width, _ctx)) {
      kk_box_t _box_x339 = width._cons._Optional.value;
      kk_integer_t _uniq_width_6640_0 = kk_integer_unbox(_box_x339, _ctx);
      kk_integer_dup(_uniq_width_6640_0, _ctx);
      kk_std_core_types__optional_drop(width, _ctx);
      _b_x340_348 = _uniq_width_6640_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(width, _ctx);
      _b_x340_348 = kk_integer_from_small(1); /*int*/
    }
    bool _b_x342_349;
    if (kk_std_core_types__is_Optional(use_capitals, _ctx)) {
      kk_box_t _box_x341 = use_capitals._cons._Optional.value;
      bool _uniq_use_capitals_6644_0 = kk_bool_unbox(_box_x341);
      kk_std_core_types__optional_drop(use_capitals, _ctx);
      _b_x342_349 = _uniq_use_capitals_6644_0; /*bool*/
    }
    else {
      kk_std_core_types__optional_drop(use_capitals, _ctx);
      _b_x342_349 = true; /*bool*/
    }
    kk_string_t _b_x344_350;
    if (kk_std_core_types__is_Optional(pre, _ctx)) {
      kk_box_t _box_x343 = pre._cons._Optional.value;
      kk_string_t _uniq_pre_6648_0 = kk_string_unbox(_box_x343);
      kk_string_dup(_uniq_pre_6648_0, _ctx);
      kk_std_core_types__optional_drop(pre, _ctx);
      _b_x344_350 = _uniq_pre_6648_0; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(pre, _ctx);
      kk_define_string_literal(, _s_x1895, 2, "0x", _ctx)
      _b_x344_350 = kk_string_dup(_s_x1895, _ctx); /*string*/
    }
    kk_string_t _x_x1896;
    kk_define_string_literal(, _s_x1897, 3, " + ", _ctx)
    _x_x1896 = kk_string_dup(_s_x1897, _ctx); /*string*/
    kk_string_t _x_x1898;
    double _x_x1899;
    {
      double _x_1 = x.lo;
      _x_x1899 = _x_1; /*float64*/
    }
    kk_std_core_types__optional _x_x1900 = kk_std_core_types__new_Optional(kk_integer_box(_b_x340_348, _ctx), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1901 = kk_std_core_types__new_Optional(kk_bool_box(_b_x342_349), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1902 = kk_std_core_types__new_Optional(kk_string_box(_b_x344_350), _ctx); /*? 10003*/
    _x_x1898 = kk_std_num_float64_show_hex(_x_x1899, _x_x1900, _x_x1901, _x_x1902, _ctx); /*string*/
    _x_x1894 = kk_std_core_types__lp__plus__plus__rp_(_x_x1896, _x_x1898, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x1889, _x_x1894, _ctx);
  }
  {
    kk_std_core_types__optional_drop(width, _ctx);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    kk_std_core_types__optional_drop(pre, _ctx);
    double _x_x1903;
    {
      double _x_2 = x.hi;
      _x_x1903 = _x_2; /*float64*/
    }
    return kk_std_num_float64_show(_x_x1903, kk_std_core_types__new_None(_ctx), _ctx);
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
  bool b_10337;
  bool _match_x791;
  double _x_x1904;
  {
    double _x = x.hi;
    _x_x1904 = _x; /*float64*/
  }
  _match_x791 = isfinite(_x_x1904); /*bool*/
  if (_match_x791) {
    double _x_x1905;
    {
      double _x_0 = x.lo;
      _x_x1905 = _x_0; /*float64*/
    }
    b_10337 = isfinite(_x_x1905); /*bool*/
  }
  else {
    b_10337 = false; /*bool*/
  }
  if (b_10337) {
    bool b_0_10341;
    bool _match_x790;
    double _x_x1906;
    {
      double _x_1 = x.hi;
      _x_x1906 = _x_1; /*float64*/
    }
    _match_x790 = isfinite(_x_x1906); /*bool*/
    if (_match_x790) {
      double _x_x1907;
      {
        double _x_0_0 = x.lo;
        _x_x1907 = _x_0_0; /*float64*/
      }
      b_0_10341 = isfinite(_x_x1907); /*bool*/
    }
    else {
      b_0_10341 = false; /*bool*/
    }
    kk_std_num_decimal__decimal _x_x1908;
    if (b_0_10341) {
      kk_std_num_decimal__decimal x_1_10342;
      double _x_x1909;
      {
        double _x_3 = x.hi;
        _x_x1909 = _x_3; /*float64*/
      }
      kk_std_core_types__optional _x_x1910;
      kk_box_t _x_x1911;
      kk_integer_t _x_x1912;
      kk_std_core_types__optional _match_x789 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x789, _ctx)) {
        kk_box_t _box_x351 = _match_x789._cons._Optional.value;
        kk_integer_t _uniq_prec_4427 = kk_integer_unbox(_box_x351, _ctx);
        kk_integer_dup(_uniq_prec_4427, _ctx);
        kk_std_core_types__optional_drop(_match_x789, _ctx);
        _x_x1912 = _uniq_prec_4427; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x789, _ctx);
        _x_x1912 = kk_integer_from_small(-1); /*int*/
      }
      _x_x1911 = kk_integer_box(_x_x1912, _ctx); /*10003*/
      _x_x1910 = kk_std_core_types__new_Optional(_x_x1911, _ctx); /*? 10003*/
      x_1_10342 = kk_std_num_decimal_float64_fs_decimal(_x_x1909, _x_x1910, _ctx); /*std/num/decimal/decimal*/
      kk_std_num_decimal__decimal y_10343;
      double _x_x1913;
      {
        double _x_4 = x.lo;
        _x_x1913 = _x_4; /*float64*/
      }
      kk_std_core_types__optional _x_x1914;
      kk_box_t _x_x1915;
      kk_integer_t _x_x1916;
      kk_std_core_types__optional _match_x788 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x788, _ctx)) {
        kk_box_t _box_x354 = _match_x788._cons._Optional.value;
        kk_integer_t _uniq_prec_4427_0 = kk_integer_unbox(_box_x354, _ctx);
        kk_integer_dup(_uniq_prec_4427_0, _ctx);
        kk_std_core_types__optional_drop(_match_x788, _ctx);
        _x_x1916 = _uniq_prec_4427_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x788, _ctx);
        _x_x1916 = kk_integer_from_small(-1); /*int*/
      }
      _x_x1915 = kk_integer_box(_x_x1916, _ctx); /*10003*/
      _x_x1914 = kk_std_core_types__new_Optional(_x_x1915, _ctx); /*? 10003*/
      y_10343 = kk_std_num_decimal_float64_fs_decimal(_x_x1913, _x_x1914, _ctx); /*std/num/decimal/decimal*/
      kk_integer_t e;
      bool _match_x784;
      kk_integer_t _brw_x786;
      {
        kk_integer_t _x_0_1 = x_1_10342.exp;
        kk_integer_dup(_x_0_1, _ctx);
        _brw_x786 = _x_0_1; /*int*/
      }
      kk_integer_t _brw_x785;
      {
        kk_integer_t _x_0_0_0 = y_10343.exp;
        kk_integer_dup(_x_0_0_0, _ctx);
        _brw_x785 = _x_0_0_0; /*int*/
      }
      bool _brw_x787 = kk_integer_lte_borrow(_brw_x786,_brw_x785,kk_context()); /*bool*/;
      kk_integer_drop(_brw_x786, _ctx);
      kk_integer_drop(_brw_x785, _ctx);
      _match_x784 = _brw_x787; /*bool*/
      if (_match_x784) {
        kk_integer_t _x_1_0 = x_1_10342.exp;
        kk_integer_dup(_x_1_0, _ctx);
        e = _x_1_0; /*int*/
      }
      else {
        kk_integer_t _x_0_0_0_0 = y_10343.exp;
        kk_integer_dup(_x_0_0_0_0, _ctx);
        e = _x_0_0_0_0; /*int*/
      }
      kk_std_num_decimal__decimal xx;
      kk_integer_t _x_x1917 = kk_integer_dup(e, _ctx); /*int*/
      xx = kk_std_num_decimal_expand(x_1_10342, _x_x1917, _ctx); /*std/num/decimal/decimal*/
      kk_std_num_decimal__decimal yy;
      kk_integer_t _x_x1918 = kk_integer_dup(e, _ctx); /*int*/
      yy = kk_std_num_decimal_expand(y_10343, _x_x1918, _ctx); /*std/num/decimal/decimal*/
      kk_integer_t _x_x1919;
      kk_integer_t _x_x1920;
      {
        kk_integer_t _x_1_0_0 = xx.num;
        kk_integer_dup(_x_1_0_0, _ctx);
        kk_std_num_decimal__decimal_drop(xx, _ctx);
        _x_x1920 = _x_1_0_0; /*int*/
      }
      kk_integer_t _x_x1921;
      {
        kk_integer_t _x_2 = yy.num;
        kk_integer_dup(_x_2, _ctx);
        kk_std_num_decimal__decimal_drop(yy, _ctx);
        _x_x1921 = _x_2; /*int*/
      }
      _x_x1919 = kk_integer_add(_x_x1920,_x_x1921,kk_context()); /*int*/
      _x_x1908 = kk_std_num_decimal__new_Decimal(_x_x1919, e, _ctx); /*std/num/decimal/decimal*/
    }
    else {
      _x_x1908 = kk_std_num_decimal_int_fs_decimal(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
    }
    kk_std_core_types__optional _x_x1922;
    kk_box_t _x_x1923;
    kk_integer_t _x_x1924;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x357 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_6836 = kk_integer_unbox(_box_x357, _ctx);
      kk_integer_dup(_uniq_prec_6836, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1924 = _uniq_prec_6836; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1924 = kk_integer_from_small(-31); /*int*/
    }
    _x_x1923 = kk_integer_box(_x_x1924, _ctx); /*10003*/
    _x_x1922 = kk_std_core_types__new_Optional(_x_x1923, _ctx); /*? 10003*/
    return kk_std_num_decimal_show_exp(_x_x1908, _x_x1922, _ctx);
  }
  {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x_x1925;
    {
      double _x_5 = x.hi;
      _x_x1925 = _x_5; /*float64*/
    }
    return kk_std_num_float64_show(_x_x1925, kk_std_core_types__new_None(_ctx), _ctx);
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
  bool b_10346;
  bool _match_x783;
  double _x_x1926;
  {
    double _x = x.hi;
    _x_x1926 = _x; /*float64*/
  }
  _match_x783 = isfinite(_x_x1926); /*bool*/
  if (_match_x783) {
    double _x_x1927;
    {
      double _x_0 = x.lo;
      _x_x1927 = _x_0; /*float64*/
    }
    b_10346 = isfinite(_x_x1927); /*bool*/
  }
  else {
    b_10346 = false; /*bool*/
  }
  if (b_10346) {
    bool b_0_10350;
    bool _match_x782;
    double _x_x1928;
    {
      double _x_1 = x.hi;
      _x_x1928 = _x_1; /*float64*/
    }
    _match_x782 = isfinite(_x_x1928); /*bool*/
    if (_match_x782) {
      double _x_x1929;
      {
        double _x_0_0 = x.lo;
        _x_x1929 = _x_0_0; /*float64*/
      }
      b_0_10350 = isfinite(_x_x1929); /*bool*/
    }
    else {
      b_0_10350 = false; /*bool*/
    }
    kk_std_num_decimal__decimal _x_x1930;
    if (b_0_10350) {
      kk_std_num_decimal__decimal x_1_10351;
      double _x_x1931;
      {
        double _x_3 = x.hi;
        _x_x1931 = _x_3; /*float64*/
      }
      kk_std_core_types__optional _x_x1932;
      kk_box_t _x_x1933;
      kk_integer_t _x_x1934;
      kk_std_core_types__optional _match_x781 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x781, _ctx)) {
        kk_box_t _box_x360 = _match_x781._cons._Optional.value;
        kk_integer_t _uniq_prec_4427 = kk_integer_unbox(_box_x360, _ctx);
        kk_integer_dup(_uniq_prec_4427, _ctx);
        kk_std_core_types__optional_drop(_match_x781, _ctx);
        _x_x1934 = _uniq_prec_4427; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x781, _ctx);
        _x_x1934 = kk_integer_from_small(-1); /*int*/
      }
      _x_x1933 = kk_integer_box(_x_x1934, _ctx); /*10003*/
      _x_x1932 = kk_std_core_types__new_Optional(_x_x1933, _ctx); /*? 10003*/
      x_1_10351 = kk_std_num_decimal_float64_fs_decimal(_x_x1931, _x_x1932, _ctx); /*std/num/decimal/decimal*/
      kk_std_num_decimal__decimal y_10352;
      double _x_x1935;
      {
        double _x_4 = x.lo;
        _x_x1935 = _x_4; /*float64*/
      }
      kk_std_core_types__optional _x_x1936;
      kk_box_t _x_x1937;
      kk_integer_t _x_x1938;
      kk_std_core_types__optional _match_x780 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x780, _ctx)) {
        kk_box_t _box_x363 = _match_x780._cons._Optional.value;
        kk_integer_t _uniq_prec_4427_0 = kk_integer_unbox(_box_x363, _ctx);
        kk_integer_dup(_uniq_prec_4427_0, _ctx);
        kk_std_core_types__optional_drop(_match_x780, _ctx);
        _x_x1938 = _uniq_prec_4427_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x780, _ctx);
        _x_x1938 = kk_integer_from_small(-1); /*int*/
      }
      _x_x1937 = kk_integer_box(_x_x1938, _ctx); /*10003*/
      _x_x1936 = kk_std_core_types__new_Optional(_x_x1937, _ctx); /*? 10003*/
      y_10352 = kk_std_num_decimal_float64_fs_decimal(_x_x1935, _x_x1936, _ctx); /*std/num/decimal/decimal*/
      kk_integer_t e;
      bool _match_x776;
      kk_integer_t _brw_x778;
      {
        kk_integer_t _x_0_1 = x_1_10351.exp;
        kk_integer_dup(_x_0_1, _ctx);
        _brw_x778 = _x_0_1; /*int*/
      }
      kk_integer_t _brw_x777;
      {
        kk_integer_t _x_0_0_0 = y_10352.exp;
        kk_integer_dup(_x_0_0_0, _ctx);
        _brw_x777 = _x_0_0_0; /*int*/
      }
      bool _brw_x779 = kk_integer_lte_borrow(_brw_x778,_brw_x777,kk_context()); /*bool*/;
      kk_integer_drop(_brw_x778, _ctx);
      kk_integer_drop(_brw_x777, _ctx);
      _match_x776 = _brw_x779; /*bool*/
      if (_match_x776) {
        kk_integer_t _x_1_0 = x_1_10351.exp;
        kk_integer_dup(_x_1_0, _ctx);
        e = _x_1_0; /*int*/
      }
      else {
        kk_integer_t _x_0_0_0_0 = y_10352.exp;
        kk_integer_dup(_x_0_0_0_0, _ctx);
        e = _x_0_0_0_0; /*int*/
      }
      kk_std_num_decimal__decimal xx;
      kk_integer_t _x_x1939 = kk_integer_dup(e, _ctx); /*int*/
      xx = kk_std_num_decimal_expand(x_1_10351, _x_x1939, _ctx); /*std/num/decimal/decimal*/
      kk_std_num_decimal__decimal yy;
      kk_integer_t _x_x1940 = kk_integer_dup(e, _ctx); /*int*/
      yy = kk_std_num_decimal_expand(y_10352, _x_x1940, _ctx); /*std/num/decimal/decimal*/
      kk_integer_t _x_x1941;
      kk_integer_t _x_x1942;
      {
        kk_integer_t _x_1_0_0 = xx.num;
        kk_integer_dup(_x_1_0_0, _ctx);
        kk_std_num_decimal__decimal_drop(xx, _ctx);
        _x_x1942 = _x_1_0_0; /*int*/
      }
      kk_integer_t _x_x1943;
      {
        kk_integer_t _x_2 = yy.num;
        kk_integer_dup(_x_2, _ctx);
        kk_std_num_decimal__decimal_drop(yy, _ctx);
        _x_x1943 = _x_2; /*int*/
      }
      _x_x1941 = kk_integer_add(_x_x1942,_x_x1943,kk_context()); /*int*/
      _x_x1930 = kk_std_num_decimal__new_Decimal(_x_x1941, e, _ctx); /*std/num/decimal/decimal*/
    }
    else {
      _x_x1930 = kk_std_num_decimal_int_fs_decimal(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
    }
    kk_std_core_types__optional _x_x1944;
    kk_box_t _x_x1945;
    kk_integer_t _x_x1946;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x366 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_6956 = kk_integer_unbox(_box_x366, _ctx);
      kk_integer_dup(_uniq_prec_6956, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1946 = _uniq_prec_6956; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1946 = kk_integer_from_small(-31); /*int*/
    }
    _x_x1945 = kk_integer_box(_x_x1946, _ctx); /*10003*/
    _x_x1944 = kk_std_core_types__new_Optional(_x_x1945, _ctx); /*? 10003*/
    return kk_std_num_decimal_show_fixed(_x_x1930, _x_x1944, _ctx);
  }
  {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x_x1947;
    {
      double _x_5 = x.hi;
      _x_x1947 = _x_5; /*float64*/
    }
    return kk_std_num_float64_show(_x_x1947, kk_std_core_types__new_None(_ctx), _ctx);
  }
}
 
// Show a `:ddouble` as the sum of  `:float64`s with an optional precision.
// Note: use `show-hex` for reliable round-trip parsing.

kk_string_t kk_std_num_ddouble_show_sum(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : ? int) -> string */ 
  bool b_10355;
  bool _match_x775;
  double _x_x1948;
  {
    double _x = x.hi;
    _x_x1948 = _x; /*float64*/
  }
  _match_x775 = isfinite(_x_x1948); /*bool*/
  if (_match_x775) {
    double _x_x1949;
    {
      double _x_0 = x.lo;
      _x_x1949 = _x_0; /*float64*/
    }
    b_10355 = isfinite(_x_x1949); /*bool*/
  }
  else {
    b_10355 = false; /*bool*/
  }
  if (b_10355) {
    kk_integer_t _b_x370_373;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x369 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_7076 = kk_integer_unbox(_box_x369, _ctx);
      kk_integer_dup(_uniq_prec_7076, _ctx);
      _b_x370_373 = _uniq_prec_7076; /*int*/
    }
    else {
      _b_x370_373 = kk_integer_from_small(-17); /*int*/
    }
    kk_string_t _x_x1950;
    double _x_x1951;
    {
      double _x_0_0 = x.hi;
      _x_x1951 = _x_0_0; /*float64*/
    }
    kk_std_core_types__optional _x_x1952 = kk_std_core_types__new_Optional(kk_integer_box(_b_x370_373, _ctx), _ctx); /*? 10003*/
    _x_x1950 = kk_std_num_float64_show(_x_x1951, _x_x1952, _ctx); /*string*/
    kk_string_t _x_x1953;
    kk_integer_t _b_x372_374;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x371 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_7076_0 = kk_integer_unbox(_box_x371, _ctx);
      kk_integer_dup(_uniq_prec_7076_0, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _b_x372_374 = _uniq_prec_7076_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _b_x372_374 = kk_integer_from_small(-17); /*int*/
    }
    kk_string_t _x_x1954;
    kk_define_string_literal(, _s_x1955, 3, " + ", _ctx)
    _x_x1954 = kk_string_dup(_s_x1955, _ctx); /*string*/
    kk_string_t _x_x1956;
    double _x_x1957;
    {
      double _x_1 = x.lo;
      _x_x1957 = _x_1; /*float64*/
    }
    kk_std_core_types__optional _x_x1958 = kk_std_core_types__new_Optional(kk_integer_box(_b_x372_374, _ctx), _ctx); /*? 10003*/
    _x_x1956 = kk_std_num_float64_show(_x_x1957, _x_x1958, _ctx); /*string*/
    _x_x1953 = kk_std_core_types__lp__plus__plus__rp_(_x_x1954, _x_x1956, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x1950, _x_x1953, _ctx);
  }
  {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x_x1959;
    {
      double _x_2 = x.hi;
      _x_x1959 = _x_2; /*float64*/
    }
    return kk_std_num_float64_show(_x_x1959, kk_std_core_types__new_None(_ctx), _ctx);
  }
}
 
// The `n`-th root of a `:ddouble` number `x`.
// `n` must be positive, and if `n` is even, then
// `x` must not be negative.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_nroot(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx) { /* (x : ddouble, n : int) -> ddouble */ 
  bool _match_x763 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  if (_match_x763) {
    kk_integer_drop(n, _ctx);
    return kk_std_num_ddouble_sqrt(x, _ctx);
  }
  {
    bool _match_x764 = kk_integer_eq_borrow(n,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    if (_match_x764) {
      kk_integer_drop(n, _ctx);
      return x;
    }
    {
      bool _match_x765 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x765) {
        kk_integer_drop(n, _ctx);
        return kk_std_num_ddouble_dd_nan;
      }
      {
        bool b_10014;
        kk_integer_t _x_x1960 = kk_integer_dup(n, _ctx); /*int*/
        b_10014 = kk_integer_is_odd(_x_x1960,kk_context()); /*bool*/
        if (b_10014) {
          bool _match_x771;
          double _x_x1961;
          {
            double _x_3 = x.hi;
            _x_x1961 = _x_3; /*float64*/
          }
          _match_x771 = (_x_x1961 == (0x0p+0)); /*bool*/
          if (_match_x771) {
            kk_integer_drop(n, _ctx);
            return kk_std_num_ddouble_zero;
          }
          {
            kk_std_num_ddouble__ddouble r_0 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
            double d_4_10376;
            double _x_x1962;
            double _x_x1963;
            double _x_x1964;
            double _x_x1965;
            {
              double _x_4 = r_0.hi;
              _x_x1965 = _x_4; /*float64*/
            }
            _x_x1964 = log(_x_x1965); /*float64*/
            _x_x1963 = (-_x_x1964); /*float64*/
            double _x_x1966;
            kk_integer_t _x_x1967 = kk_integer_dup(n, _ctx); /*int*/
            _x_x1966 = kk_integer_as_double(_x_x1967,kk_context()); /*float64*/
            _x_x1962 = (_x_x1963 / _x_x1966); /*float64*/
            d_4_10376 = exp(_x_x1962); /*float64*/
            kk_std_num_ddouble__ddouble a0_0 = kk_std_num_ddouble__new_Ddouble(d_4_10376, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_std_num_ddouble__ddouble y_10730;
            kk_integer_t _x_x1968 = kk_integer_dup(n, _ctx); /*int*/
            y_10730 = kk_std_num_ddouble_powi(a0_0, _x_x1968, _ctx); /*std/num/ddouble/ddouble*/
            double z;
            double _x_x1969;
            {
              double _x = r_0.hi;
              _x_x1969 = _x; /*float64*/
            }
            double _x_x1970;
            {
              double _x_0 = y_10730.hi;
              _x_x1970 = _x_0; /*float64*/
            }
            z = (_x_x1969 * _x_x1970); /*float64*/
            double err;
            double _x_x1971;
            {
              double _x_1 = r_0.hi;
              _x_x1971 = _x_1; /*float64*/
            }
            double _x_x1972;
            {
              double _x_0_0 = y_10730.hi;
              _x_x1972 = _x_0_0; /*float64*/
            }
            double _x_x1973 = (-z); /*float64*/
            err = kk_std_num_float64_fmadd(_x_x1971, _x_x1972, _x_x1973, _ctx); /*float64*/
            kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
            double e;
            double _x_x1974;
            {
              double _x_1_0 = z_0.err;
              _x_x1974 = _x_1_0; /*float64*/
            }
            double _x_x1975;
            double _x_x1976;
            double _x_x1977;
            {
              double _x_2 = r_0.hi;
              _x_x1977 = _x_2; /*float64*/
            }
            double _x_x1978;
            {
              double _x_3_0 = y_10730.lo;
              _x_x1978 = _x_3_0; /*float64*/
            }
            _x_x1976 = (_x_x1977 * _x_x1978); /*float64*/
            double _x_x1979;
            double _x_x1980;
            {
              double _x_4_0 = r_0.lo;
              _x_x1980 = _x_4_0; /*float64*/
            }
            double _x_x1981;
            {
              double _x_5 = y_10730.hi;
              _x_x1981 = _x_5; /*float64*/
            }
            _x_x1979 = (_x_x1980 * _x_x1981); /*float64*/
            _x_x1975 = (_x_x1976 + _x_x1979); /*float64*/
            e = (_x_x1974 + _x_x1975); /*float64*/
            bool b_10040;
            double _x_x1982;
            {
              double _x_6 = z_0.num;
              _x_x1982 = _x_6; /*float64*/
            }
            b_10040 = isfinite(_x_x1982); /*bool*/
            kk_std_num_ddouble__ddouble y_0_10379;
            if (b_10040) {
              double z_1;
              double _x_x1983;
              {
                double _x_6_0 = z_0.num;
                _x_x1983 = _x_6_0; /*float64*/
              }
              z_1 = (_x_x1983 + e); /*float64*/
              double err_0;
              double _x_x1984;
              double _x_x1985;
              {
                double _x_6_1 = z_0.num;
                _x_x1985 = _x_6_1; /*float64*/
              }
              _x_x1984 = (z_1 - _x_x1985); /*float64*/
              err_0 = (e - _x_x1984); /*float64*/
              double _x_x1986;
              bool _match_x774 = isfinite(z_1); /*bool*/;
              if (_match_x774) {
                _x_x1986 = err_0; /*float64*/
              }
              else {
                _x_x1986 = z_1; /*float64*/
              }
              y_0_10379 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x1986, _ctx); /*std/num/ddouble/ddouble*/
            }
            else {
              double _x_x1987;
              {
                double _x_6_2 = z_0.num;
                _x_x1987 = _x_6_2; /*float64*/
              }
              y_0_10379 = kk_std_num_ddouble__new_Ddouble(_x_x1987, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
            }
            kk_std_num_ddouble__ddouble y_0_10732;
            kk_std_num_ddouble__ddouble _x_x1988;
            double _x_x1989;
            double _x_x1990;
            {
              double _x_8 = y_0_10379.hi;
              _x_x1990 = _x_8; /*float64*/
            }
            _x_x1989 = (-_x_x1990); /*float64*/
            double _x_x1991;
            double _x_x1992;
            {
              double _x_0_1 = y_0_10379.lo;
              _x_x1992 = _x_0_1; /*float64*/
            }
            _x_x1991 = (-_x_x1992); /*float64*/
            _x_x1988 = kk_std_num_ddouble__new_Ddouble(_x_x1989, _x_x1991, _ctx); /*std/num/ddouble/ddouble*/
            y_0_10732 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x1988, _ctx); /*std/num/ddouble/ddouble*/
            double z_2;
            double _x_x1993;
            {
              double _x_7 = a0_0.hi;
              _x_x1993 = _x_7; /*float64*/
            }
            double _x_x1994;
            {
              double _x_0_0_0 = y_0_10732.hi;
              _x_x1994 = _x_0_0_0; /*float64*/
            }
            z_2 = (_x_x1993 * _x_x1994); /*float64*/
            double err_1;
            double _x_x1995;
            {
              double _x_7_0 = a0_0.hi;
              _x_x1995 = _x_7_0; /*float64*/
            }
            double _x_x1996;
            {
              double _x_0_0_1 = y_0_10732.hi;
              _x_x1996 = _x_0_0_1; /*float64*/
            }
            double _x_x1997 = (-z_2); /*float64*/
            err_1 = kk_std_num_float64_fmadd(_x_x1995, _x_x1996, _x_x1997, _ctx); /*float64*/
            kk_std_num_ddouble__edouble z_0_0 = kk_std_num_ddouble__new_Edouble(z_2, err_1, _ctx); /*std/num/ddouble/edouble*/;
            double e_0;
            double _x_x1998;
            {
              double _x_1_0_0 = z_0_0.err;
              _x_x1998 = _x_1_0_0; /*float64*/
            }
            double _x_x1999;
            double _x_x2000;
            double _x_x2001;
            {
              double _x_2_0 = a0_0.hi;
              _x_x2001 = _x_2_0; /*float64*/
            }
            double _x_x2002;
            {
              double _x_3_1 = y_0_10732.lo;
              _x_x2002 = _x_3_1; /*float64*/
            }
            _x_x2000 = (_x_x2001 * _x_x2002); /*float64*/
            double _x_x2003;
            double _x_x2004;
            {
              double _x_4_1 = a0_0.lo;
              _x_x2004 = _x_4_1; /*float64*/
            }
            double _x_x2005;
            {
              double _x_5_0 = y_0_10732.hi;
              _x_x2005 = _x_5_0; /*float64*/
            }
            _x_x2003 = (_x_x2004 * _x_x2005); /*float64*/
            _x_x1999 = (_x_x2000 + _x_x2003); /*float64*/
            e_0 = (_x_x1998 + _x_x1999); /*float64*/
            bool b_10040_0;
            double _x_x2006;
            {
              double _x_6_0_0 = z_0_0.num;
              _x_x2006 = _x_6_0_0; /*float64*/
            }
            b_10040_0 = isfinite(_x_x2006); /*bool*/
            kk_std_num_ddouble__ddouble a1_0;
            kk_std_num_ddouble__ddouble _x_x2007;
            kk_std_num_ddouble__ddouble _x_x2008;
            if (b_10040_0) {
              double z_1_0;
              double _x_x2009;
              {
                double _x_6_0_1 = z_0_0.num;
                _x_x2009 = _x_6_0_1; /*float64*/
              }
              z_1_0 = (_x_x2009 + e_0); /*float64*/
              double err_0_0;
              double _x_x2010;
              double _x_x2011;
              {
                double _x_6_0_2 = z_0_0.num;
                _x_x2011 = _x_6_0_2; /*float64*/
              }
              _x_x2010 = (z_1_0 - _x_x2011); /*float64*/
              err_0_0 = (e_0 - _x_x2010); /*float64*/
              double _x_x2012;
              bool _match_x773 = isfinite(z_1_0); /*bool*/;
              if (_match_x773) {
                _x_x2012 = err_0_0; /*float64*/
              }
              else {
                _x_x2012 = z_1_0; /*float64*/
              }
              _x_x2008 = kk_std_num_ddouble__new_Ddouble(z_1_0, _x_x2012, _ctx); /*std/num/ddouble/ddouble*/
            }
            else {
              double _x_x2013;
              {
                double _x_6_0_3 = z_0_0.num;
                _x_x2013 = _x_6_0_3; /*float64*/
              }
              _x_x2008 = kk_std_num_ddouble__new_Ddouble(_x_x2013, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
            }
            kk_std_num_ddouble__ddouble _x_x2014 = kk_std_num_ddouble_ddouble_int_exp(n, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
            _x_x2007 = kk_std_num_ddouble__lp__fs__rp_(_x_x2008, _x_x2014, _ctx); /*std/num/ddouble/ddouble*/
            a1_0 = kk_std_num_ddouble__lp__plus__rp_(a0_0, _x_x2007, _ctx); /*std/num/ddouble/ddouble*/
            kk_std_num_ddouble__ddouble _x_x2015;
            bool _match_x772;
            double _x_x2016;
            {
              double _x_5_1 = x.hi;
              _x_x2016 = _x_5_1; /*float64*/
            }
            _match_x772 = (_x_x2016 < (0x0p+0)); /*bool*/
            if (_match_x772) {
              double _x_x2017;
              double _x_x2018;
              kk_std_num_ddouble__ddouble _x_x2019 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
              {
                double _x_9 = _x_x2019.hi;
                _x_x2018 = _x_9; /*float64*/
              }
              _x_x2017 = (-_x_x2018); /*float64*/
              double _x_x2020;
              double _x_x2021;
              kk_std_num_ddouble__ddouble _x_x2022 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
              {
                double _x_0_2 = _x_x2022.lo;
                _x_x2021 = _x_0_2; /*float64*/
              }
              _x_x2020 = (-_x_x2021); /*float64*/
              _x_x2015 = kk_std_num_ddouble__new_Ddouble(_x_x2017, _x_x2020, _ctx); /*std/num/ddouble/ddouble*/
            }
            else {
              _x_x2015 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
            }
            return kk_std_num_ddouble__lp__fs__rp_(_x_x2015, a1_0, _ctx);
          }
        }
        {
          bool _match_x766;
          double _x_x2023;
          {
            double _x_10 = x.hi;
            _x_x2023 = _x_10; /*float64*/
          }
          _match_x766 = (_x_x2023 < (0x0p+0)); /*bool*/
          if (_match_x766) {
            kk_integer_drop(n, _ctx);
            return kk_std_num_ddouble_dd_nan;
          }
          {
            bool _match_x767;
            double _x_x2024;
            {
              double _x_0_3 = x.hi;
              _x_x2024 = _x_0_3; /*float64*/
            }
            _match_x767 = (_x_x2024 == (0x0p+0)); /*bool*/
            if (_match_x767) {
              kk_integer_drop(n, _ctx);
              return kk_std_num_ddouble_zero;
            }
            {
              kk_std_num_ddouble__ddouble r = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
              double d_1_10366;
              double _x_x2025;
              double _x_x2026;
              double _x_x2027;
              double _x_x2028;
              {
                double _x_1_1 = r.hi;
                _x_x2028 = _x_1_1; /*float64*/
              }
              _x_x2027 = log(_x_x2028); /*float64*/
              _x_x2026 = (-_x_x2027); /*float64*/
              double _x_x2029;
              kk_integer_t _x_x2030 = kk_integer_dup(n, _ctx); /*int*/
              _x_x2029 = kk_integer_as_double(_x_x2030,kk_context()); /*float64*/
              _x_x2025 = (_x_x2026 / _x_x2029); /*float64*/
              d_1_10366 = exp(_x_x2025); /*float64*/
              kk_std_num_ddouble__ddouble a0 = kk_std_num_ddouble__new_Ddouble(d_1_10366, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
              kk_std_num_ddouble__ddouble y_1_10736;
              kk_integer_t _x_x2031 = kk_integer_dup(n, _ctx); /*int*/
              y_1_10736 = kk_std_num_ddouble_powi(a0, _x_x2031, _ctx); /*std/num/ddouble/ddouble*/
              double z_3;
              double _x_x2032;
              {
                double _x_11 = r.hi;
                _x_x2032 = _x_11; /*float64*/
              }
              double _x_x2033;
              {
                double _x_0_4 = y_1_10736.hi;
                _x_x2033 = _x_0_4; /*float64*/
              }
              z_3 = (_x_x2032 * _x_x2033); /*float64*/
              double err_2;
              double _x_x2034;
              {
                double _x_11_0 = r.hi;
                _x_x2034 = _x_11_0; /*float64*/
              }
              double _x_x2035;
              {
                double _x_0_4_0 = y_1_10736.hi;
                _x_x2035 = _x_0_4_0; /*float64*/
              }
              double _x_x2036 = (-z_3); /*float64*/
              err_2 = kk_std_num_float64_fmadd(_x_x2034, _x_x2035, _x_x2036, _ctx); /*float64*/
              kk_std_num_ddouble__edouble z_0_1 = kk_std_num_ddouble__new_Edouble(z_3, err_2, _ctx); /*std/num/ddouble/edouble*/;
              double e_1;
              double _x_x2037;
              {
                double _x_1_2 = z_0_1.err;
                _x_x2037 = _x_1_2; /*float64*/
              }
              double _x_x2038;
              double _x_x2039;
              double _x_x2040;
              {
                double _x_2_1 = r.hi;
                _x_x2040 = _x_2_1; /*float64*/
              }
              double _x_x2041;
              {
                double _x_3_2 = y_1_10736.lo;
                _x_x2041 = _x_3_2; /*float64*/
              }
              _x_x2039 = (_x_x2040 * _x_x2041); /*float64*/
              double _x_x2042;
              double _x_x2043;
              {
                double _x_4_2 = r.lo;
                _x_x2043 = _x_4_2; /*float64*/
              }
              double _x_x2044;
              {
                double _x_5_2 = y_1_10736.hi;
                _x_x2044 = _x_5_2; /*float64*/
              }
              _x_x2042 = (_x_x2043 * _x_x2044); /*float64*/
              _x_x2038 = (_x_x2039 + _x_x2042); /*float64*/
              e_1 = (_x_x2037 + _x_x2038); /*float64*/
              bool b_10040_1;
              double _x_x2045;
              {
                double _x_6_1_0 = z_0_1.num;
                _x_x2045 = _x_6_1_0; /*float64*/
              }
              b_10040_1 = isfinite(_x_x2045); /*bool*/
              kk_std_num_ddouble__ddouble y_10369;
              if (b_10040_1) {
                double z_1_1;
                double _x_x2046;
                {
                  double _x_6_1_1 = z_0_1.num;
                  _x_x2046 = _x_6_1_1; /*float64*/
                }
                z_1_1 = (_x_x2046 + e_1); /*float64*/
                double err_0_1;
                double _x_x2047;
                double _x_x2048;
                {
                  double _x_6_1_2 = z_0_1.num;
                  _x_x2048 = _x_6_1_2; /*float64*/
                }
                _x_x2047 = (z_1_1 - _x_x2048); /*float64*/
                err_0_1 = (e_1 - _x_x2047); /*float64*/
                double _x_x2049;
                bool _match_x770 = isfinite(z_1_1); /*bool*/;
                if (_match_x770) {
                  _x_x2049 = err_0_1; /*float64*/
                }
                else {
                  _x_x2049 = z_1_1; /*float64*/
                }
                y_10369 = kk_std_num_ddouble__new_Ddouble(z_1_1, _x_x2049, _ctx); /*std/num/ddouble/ddouble*/
              }
              else {
                double _x_x2050;
                {
                  double _x_6_1_3 = z_0_1.num;
                  _x_x2050 = _x_6_1_3; /*float64*/
                }
                y_10369 = kk_std_num_ddouble__new_Ddouble(_x_x2050, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
              }
              kk_std_num_ddouble__ddouble y_2_10738;
              kk_std_num_ddouble__ddouble _x_x2051;
              double _x_x2052;
              double _x_x2053;
              {
                double _x_13 = y_10369.hi;
                _x_x2053 = _x_13; /*float64*/
              }
              _x_x2052 = (-_x_x2053); /*float64*/
              double _x_x2054;
              double _x_x2055;
              {
                double _x_0_6 = y_10369.lo;
                _x_x2055 = _x_0_6; /*float64*/
              }
              _x_x2054 = (-_x_x2055); /*float64*/
              _x_x2051 = kk_std_num_ddouble__new_Ddouble(_x_x2052, _x_x2054, _ctx); /*std/num/ddouble/ddouble*/
              y_2_10738 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2051, _ctx); /*std/num/ddouble/ddouble*/
              double z_4;
              double _x_x2056;
              {
                double _x_12 = a0.hi;
                _x_x2056 = _x_12; /*float64*/
              }
              double _x_x2057;
              {
                double _x_0_5 = y_2_10738.hi;
                _x_x2057 = _x_0_5; /*float64*/
              }
              z_4 = (_x_x2056 * _x_x2057); /*float64*/
              double err_3;
              double _x_x2058;
              {
                double _x_12_0 = a0.hi;
                _x_x2058 = _x_12_0; /*float64*/
              }
              double _x_x2059;
              {
                double _x_0_5_0 = y_2_10738.hi;
                _x_x2059 = _x_0_5_0; /*float64*/
              }
              double _x_x2060 = (-z_4); /*float64*/
              err_3 = kk_std_num_float64_fmadd(_x_x2058, _x_x2059, _x_x2060, _ctx); /*float64*/
              kk_std_num_ddouble__edouble z_0_2 = kk_std_num_ddouble__new_Edouble(z_4, err_3, _ctx); /*std/num/ddouble/edouble*/;
              double e_2;
              double _x_x2061;
              {
                double _x_1_3 = z_0_2.err;
                _x_x2061 = _x_1_3; /*float64*/
              }
              double _x_x2062;
              double _x_x2063;
              double _x_x2064;
              {
                double _x_2_2 = a0.hi;
                _x_x2064 = _x_2_2; /*float64*/
              }
              double _x_x2065;
              {
                double _x_3_3 = y_2_10738.lo;
                _x_x2065 = _x_3_3; /*float64*/
              }
              _x_x2063 = (_x_x2064 * _x_x2065); /*float64*/
              double _x_x2066;
              double _x_x2067;
              {
                double _x_4_3 = a0.lo;
                _x_x2067 = _x_4_3; /*float64*/
              }
              double _x_x2068;
              {
                double _x_5_3 = y_2_10738.hi;
                _x_x2068 = _x_5_3; /*float64*/
              }
              _x_x2066 = (_x_x2067 * _x_x2068); /*float64*/
              _x_x2062 = (_x_x2063 + _x_x2066); /*float64*/
              e_2 = (_x_x2061 + _x_x2062); /*float64*/
              bool b_10040_2;
              double _x_x2069;
              {
                double _x_6_2_0 = z_0_2.num;
                _x_x2069 = _x_6_2_0; /*float64*/
              }
              b_10040_2 = isfinite(_x_x2069); /*bool*/
              kk_std_num_ddouble__ddouble a1;
              kk_std_num_ddouble__ddouble _x_x2070;
              kk_std_num_ddouble__ddouble _x_x2071;
              if (b_10040_2) {
                double z_1_2;
                double _x_x2072;
                {
                  double _x_6_2_1 = z_0_2.num;
                  _x_x2072 = _x_6_2_1; /*float64*/
                }
                z_1_2 = (_x_x2072 + e_2); /*float64*/
                double err_0_2;
                double _x_x2073;
                double _x_x2074;
                {
                  double _x_6_2_2 = z_0_2.num;
                  _x_x2074 = _x_6_2_2; /*float64*/
                }
                _x_x2073 = (z_1_2 - _x_x2074); /*float64*/
                err_0_2 = (e_2 - _x_x2073); /*float64*/
                double _x_x2075;
                bool _match_x769 = isfinite(z_1_2); /*bool*/;
                if (_match_x769) {
                  _x_x2075 = err_0_2; /*float64*/
                }
                else {
                  _x_x2075 = z_1_2; /*float64*/
                }
                _x_x2071 = kk_std_num_ddouble__new_Ddouble(z_1_2, _x_x2075, _ctx); /*std/num/ddouble/ddouble*/
              }
              else {
                double _x_x2076;
                {
                  double _x_6_2_3 = z_0_2.num;
                  _x_x2076 = _x_6_2_3; /*float64*/
                }
                _x_x2071 = kk_std_num_ddouble__new_Ddouble(_x_x2076, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
              }
              kk_std_num_ddouble__ddouble _x_x2077 = kk_std_num_ddouble_ddouble_int_exp(n, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
              _x_x2070 = kk_std_num_ddouble__lp__fs__rp_(_x_x2071, _x_x2077, _ctx); /*std/num/ddouble/ddouble*/
              a1 = kk_std_num_ddouble__lp__plus__rp_(a0, _x_x2070, _ctx); /*std/num/ddouble/ddouble*/
              kk_std_num_ddouble__ddouble _x_x2078;
              bool _match_x768;
              double _x_x2079;
              {
                double _x_2_3 = x.hi;
                _x_x2079 = _x_2_3; /*float64*/
              }
              _match_x768 = (_x_x2079 < (0x0p+0)); /*bool*/
              if (_match_x768) {
                double _x_x2080;
                double _x_x2081;
                kk_std_num_ddouble__ddouble _x_x2082 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
                {
                  double _x_14 = _x_x2082.hi;
                  _x_x2081 = _x_14; /*float64*/
                }
                _x_x2080 = (-_x_x2081); /*float64*/
                double _x_x2083;
                double _x_x2084;
                kk_std_num_ddouble__ddouble _x_x2085 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
                {
                  double _x_0_7 = _x_x2085.lo;
                  _x_x2084 = _x_0_7; /*float64*/
                }
                _x_x2083 = (-_x_x2084); /*float64*/
                _x_x2078 = kk_std_num_ddouble__new_Ddouble(_x_x2080, _x_x2083, _ctx); /*std/num/ddouble/ddouble*/
              }
              else {
                _x_x2078 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
              }
              return kk_std_num_ddouble__lp__fs__rp_(_x_x2078, a1, _ctx);
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
  bool _match_x760;
  double _x_x2090;
  {
    double _x = x.hi;
    _x_x2090 = _x; /*float64*/
  }
  _match_x760 = (isinf(_x_x2090) && !signbit(_x_x2090)); /*bool*/
  if (_match_x760) {
    return x;
  }
  {
    kk_std_num_ddouble__ddouble y = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, x, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble z;
    kk_std_num_ddouble__ddouble _x_x2091;
    double _x_x2092;
    double _x_x2093;
    kk_std_num_ddouble__ddouble _x_x2094 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_0 = _x_x2094.hi;
      _x_x2093 = _x_0; /*float64*/
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
    z = kk_std_num_ddouble__lp__plus__rp_(y, _x_x2091, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_x761;
    double _x_x2098;
    {
      double _x_0_1 = z.hi;
      _x_x2098 = _x_0_1; /*float64*/
    }
    _match_x761 = (_x_x2098 == (0x0p+0)); /*bool*/
    if (_match_x761) {
      return x;
    }
    {
      kk_std_num_ddouble__ddouble x_1_10742 = kk_std_num_ddouble_ln(y, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble y_0_10743 = kk_std_num_ddouble__lp__fs__rp_(x, z, _ctx); /*std/num/ddouble/ddouble*/;
      double z_0;
      double _x_x2099;
      {
        double _x_1 = x_1_10742.hi;
        _x_x2099 = _x_1; /*float64*/
      }
      double _x_x2100;
      {
        double _x_0_2 = y_0_10743.hi;
        _x_x2100 = _x_0_2; /*float64*/
      }
      z_0 = (_x_x2099 * _x_x2100); /*float64*/
      double err;
      double _x_x2101;
      {
        double _x_1_0 = x_1_10742.hi;
        _x_x2101 = _x_1_0; /*float64*/
      }
      double _x_x2102;
      {
        double _x_0_2_0 = y_0_10743.hi;
        _x_x2102 = _x_0_2_0; /*float64*/
      }
      double _x_x2103 = (-z_0); /*float64*/
      err = kk_std_num_float64_fmadd(_x_x2101, _x_x2102, _x_x2103, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0_0 = kk_std_num_ddouble__new_Edouble(z_0, err, _ctx); /*std/num/ddouble/edouble*/;
      double e;
      double _x_x2104;
      {
        double _x_1_0_0 = z_0_0.err;
        _x_x2104 = _x_1_0_0; /*float64*/
      }
      double _x_x2105;
      double _x_x2106;
      double _x_x2107;
      {
        double _x_2 = x_1_10742.hi;
        _x_x2107 = _x_2; /*float64*/
      }
      double _x_x2108;
      {
        double _x_3 = y_0_10743.lo;
        _x_x2108 = _x_3; /*float64*/
      }
      _x_x2106 = (_x_x2107 * _x_x2108); /*float64*/
      double _x_x2109;
      double _x_x2110;
      {
        double _x_4 = x_1_10742.lo;
        _x_x2110 = _x_4; /*float64*/
      }
      double _x_x2111;
      {
        double _x_5 = y_0_10743.hi;
        _x_x2111 = _x_5; /*float64*/
      }
      _x_x2109 = (_x_x2110 * _x_x2111); /*float64*/
      _x_x2105 = (_x_x2106 + _x_x2109); /*float64*/
      e = (_x_x2104 + _x_x2105); /*float64*/
      bool b_10040;
      double _x_x2112;
      {
        double _x_6 = z_0_0.num;
        _x_x2112 = _x_6; /*float64*/
      }
      b_10040 = isfinite(_x_x2112); /*bool*/
      if (b_10040) {
        double z_1;
        double _x_x2113;
        {
          double _x_6_0 = z_0_0.num;
          _x_x2113 = _x_6_0; /*float64*/
        }
        z_1 = (_x_x2113 + e); /*float64*/
        double err_0;
        double _x_x2114;
        double _x_x2115;
        {
          double _x_6_1 = z_0_0.num;
          _x_x2115 = _x_6_1; /*float64*/
        }
        _x_x2114 = (z_1 - _x_x2115); /*float64*/
        err_0 = (e - _x_x2114); /*float64*/
        double _x_x2116;
        bool _match_x762 = isfinite(z_1); /*bool*/;
        if (_match_x762) {
          _x_x2116 = err_0; /*float64*/
        }
        else {
          _x_x2116 = z_1; /*float64*/
        }
        return kk_std_num_ddouble__new_Ddouble(z_1, _x_x2116, _ctx);
      }
      {
        double _x_x2117;
        {
          double _x_6_2 = z_0_0.num;
          _x_x2117 = _x_6_2; /*float64*/
        }
        return kk_std_num_ddouble__new_Ddouble(_x_x2117, 0x0p+0, _ctx);
      }
    }
  }
}
 
// Return `exp(x - 1.0)`.
// Avoids rounding errors for values of `x` very close to `1.0`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_expm1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x753;
  double _x_x2118;
  {
    double _x = x.hi;
    _x_x2118 = _x; /*float64*/
  }
  _match_x753 = (isinf(_x_x2118) && !signbit(_x_x2118)); /*bool*/
  if (_match_x753) {
    return x;
  }
  {
    kk_std_num_ddouble__ddouble y = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_x754 = kk_std_num_ddouble__lp__eq__eq__rp_(y, kk_std_num_ddouble_one, _ctx); /*bool*/;
    if (_match_x754) {
      return x;
    }
    {
      kk_std_num_ddouble__ddouble ym;
      kk_std_num_ddouble__ddouble _x_x2119;
      double _x_x2120;
      double _x_x2121;
      kk_std_num_ddouble__ddouble _x_x2122 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_0 = _x_x2122.hi;
        _x_x2121 = _x_0; /*float64*/
      }
      _x_x2120 = (-_x_x2121); /*float64*/
      double _x_x2123;
      double _x_x2124;
      kk_std_num_ddouble__ddouble _x_x2125 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_0_0 = _x_x2125.lo;
        _x_x2124 = _x_0_0; /*float64*/
      }
      _x_x2123 = (-_x_x2124); /*float64*/
      _x_x2119 = kk_std_num_ddouble__new_Ddouble(_x_x2120, _x_x2123, _ctx); /*std/num/ddouble/ddouble*/
      ym = kk_std_num_ddouble__lp__plus__rp_(y, _x_x2119, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble y_1_10396;
      double _x_x2126;
      double _x_x2127;
      kk_std_num_ddouble__ddouble _x_x2128 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_1 = _x_x2128.hi;
        _x_x2127 = _x_1; /*float64*/
      }
      _x_x2126 = (-_x_x2127); /*float64*/
      double _x_x2129;
      double _x_x2130;
      kk_std_num_ddouble__ddouble _x_x2131 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_0_1 = _x_x2131.lo;
        _x_x2130 = _x_0_1; /*float64*/
      }
      _x_x2129 = (-_x_x2130); /*float64*/
      y_1_10396 = kk_std_num_ddouble__new_Ddouble(_x_x2126, _x_x2129, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_core_types__order x_3_10397;
      kk_std_core_types__order _match_x759;
      double _x_x2132;
      {
        double _x_2 = ym.hi;
        _x_x2132 = _x_2; /*float64*/
      }
      double _x_x2133;
      {
        double _x_0_2 = y_1_10396.hi;
        _x_x2133 = _x_0_2; /*float64*/
      }
      _match_x759 = kk_std_num_float64_cmp(_x_x2132, _x_x2133, _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x759, _ctx)) {
        double _x_x2134;
        {
          double _x_1_0 = ym.lo;
          _x_x2134 = _x_1_0; /*float64*/
        }
        double _x_x2135;
        {
          double _x_2_0 = y_1_10396.lo;
          _x_x2135 = _x_2_0; /*float64*/
        }
        x_3_10397 = kk_std_num_float64_cmp(_x_x2134, _x_x2135, _ctx); /*order*/
      }
      else {
        x_3_10397 = _match_x759; /*order*/
      }
      bool _match_x755;
      kk_integer_t _brw_x757;
      if (kk_std_core_types__is_Lt(x_3_10397, _ctx)) {
        _brw_x757 = kk_integer_from_small(-1); /*int*/
        goto _match_x2136;
      }
      if (kk_std_core_types__is_Eq(x_3_10397, _ctx)) {
        _brw_x757 = kk_integer_from_small(0); /*int*/
        goto _match_x2136;
      }
      {
        _brw_x757 = kk_integer_from_small(1); /*int*/
      }
      _match_x2136: ;
      bool _brw_x758 = kk_integer_eq_borrow(_brw_x757,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x757, _ctx);
      _match_x755 = _brw_x758; /*bool*/
      if (_match_x755) {
        double _x_x2137;
        double _x_x2138;
        kk_std_num_ddouble__ddouble _x_x2139 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_3 = _x_x2139.hi;
          _x_x2138 = _x_3; /*float64*/
        }
        _x_x2137 = (-_x_x2138); /*float64*/
        double _x_x2140;
        double _x_x2141;
        kk_std_num_ddouble__ddouble _x_x2142 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_0_3 = _x_x2142.lo;
          _x_x2141 = _x_0_3; /*float64*/
        }
        _x_x2140 = (-_x_x2141); /*float64*/
        return kk_std_num_ddouble__new_Ddouble(_x_x2137, _x_x2140, _ctx);
      }
      {
        kk_std_num_ddouble__ddouble y_1_10750;
        kk_std_num_ddouble__ddouble _x_x2143 = kk_std_num_ddouble_ln(y, _ctx); /*std/num/ddouble/ddouble*/
        y_1_10750 = kk_std_num_ddouble__lp__fs__rp_(x, _x_x2143, _ctx); /*std/num/ddouble/ddouble*/
        double z;
        double _x_x2144;
        {
          double _x_4 = ym.hi;
          _x_x2144 = _x_4; /*float64*/
        }
        double _x_x2145;
        {
          double _x_0_4 = y_1_10750.hi;
          _x_x2145 = _x_0_4; /*float64*/
        }
        z = (_x_x2144 * _x_x2145); /*float64*/
        double err;
        double _x_x2146;
        {
          double _x_4_0 = ym.hi;
          _x_x2146 = _x_4_0; /*float64*/
        }
        double _x_x2147;
        {
          double _x_0_4_0 = y_1_10750.hi;
          _x_x2147 = _x_0_4_0; /*float64*/
        }
        double _x_x2148 = (-z); /*float64*/
        err = kk_std_num_float64_fmadd(_x_x2146, _x_x2147, _x_x2148, _ctx); /*float64*/
        kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
        double e;
        double _x_x2149;
        {
          double _x_1_1 = z_0.err;
          _x_x2149 = _x_1_1; /*float64*/
        }
        double _x_x2150;
        double _x_x2151;
        double _x_x2152;
        {
          double _x_2_1 = ym.hi;
          _x_x2152 = _x_2_1; /*float64*/
        }
        double _x_x2153;
        {
          double _x_3_0 = y_1_10750.lo;
          _x_x2153 = _x_3_0; /*float64*/
        }
        _x_x2151 = (_x_x2152 * _x_x2153); /*float64*/
        double _x_x2154;
        double _x_x2155;
        {
          double _x_4_0_0 = ym.lo;
          _x_x2155 = _x_4_0_0; /*float64*/
        }
        double _x_x2156;
        {
          double _x_5 = y_1_10750.hi;
          _x_x2156 = _x_5; /*float64*/
        }
        _x_x2154 = (_x_x2155 * _x_x2156); /*float64*/
        _x_x2150 = (_x_x2151 + _x_x2154); /*float64*/
        e = (_x_x2149 + _x_x2150); /*float64*/
        bool b_10040;
        double _x_x2157;
        {
          double _x_6 = z_0.num;
          _x_x2157 = _x_6; /*float64*/
        }
        b_10040 = isfinite(_x_x2157); /*bool*/
        if (b_10040) {
          double z_1;
          double _x_x2158;
          {
            double _x_6_0 = z_0.num;
            _x_x2158 = _x_6_0; /*float64*/
          }
          z_1 = (_x_x2158 + e); /*float64*/
          double err_0;
          double _x_x2159;
          double _x_x2160;
          {
            double _x_6_1 = z_0.num;
            _x_x2160 = _x_6_1; /*float64*/
          }
          _x_x2159 = (z_1 - _x_x2160); /*float64*/
          err_0 = (e - _x_x2159); /*float64*/
          double _x_x2161;
          bool _match_x756 = isfinite(z_1); /*bool*/;
          if (_match_x756) {
            _x_x2161 = err_0; /*float64*/
          }
          else {
            _x_x2161 = z_1; /*float64*/
          }
          return kk_std_num_ddouble__new_Ddouble(z_1, _x_x2161, _ctx);
        }
        {
          double _x_x2162;
          {
            double _x_6_2 = z_0.num;
            _x_x2162 = _x_6_2; /*float64*/
          }
          return kk_std_num_ddouble__new_Ddouble(_x_x2162, 0x0p+0, _ctx);
        }
      }
    }
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_log2p1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble y_10752 = kk_std_num_ddouble_ln1p(x, _ctx); /*std/num/ddouble/ddouble*/;
  double z;
  double _x_x2163;
  kk_std_num_ddouble__ddouble _x_x2164 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
  {
    double _x = _x_x2164.hi;
    _x_x2163 = _x; /*float64*/
  }
  double _x_x2165;
  {
    double _x_0 = y_10752.hi;
    _x_x2165 = _x_0; /*float64*/
  }
  z = (_x_x2163 * _x_x2165); /*float64*/
  double err;
  double _x_x2166;
  kk_std_num_ddouble__ddouble _x_x2167 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
  {
    double _x_1 = _x_x2167.hi;
    _x_x2166 = _x_1; /*float64*/
  }
  double _x_x2168;
  {
    double _x_0_0 = y_10752.hi;
    _x_x2168 = _x_0_0; /*float64*/
  }
  double _x_x2169 = (-z); /*float64*/
  err = kk_std_num_float64_fmadd(_x_x2166, _x_x2168, _x_x2169, _ctx); /*float64*/
  kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
  double e;
  double _x_x2170;
  {
    double _x_1_0 = z_0.err;
    _x_x2170 = _x_1_0; /*float64*/
  }
  double _x_x2171;
  double _x_x2172;
  double _x_x2173;
  kk_std_num_ddouble__ddouble _x_x2174 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
  {
    double _x_2 = _x_x2174.hi;
    _x_x2173 = _x_2; /*float64*/
  }
  double _x_x2175;
  {
    double _x_3 = y_10752.lo;
    _x_x2175 = _x_3; /*float64*/
  }
  _x_x2172 = (_x_x2173 * _x_x2175); /*float64*/
  double _x_x2176;
  double _x_x2177;
  kk_std_num_ddouble__ddouble _x_x2178 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
  {
    double _x_4 = _x_x2178.lo;
    _x_x2177 = _x_4; /*float64*/
  }
  double _x_x2179;
  {
    double _x_5 = y_10752.hi;
    _x_x2179 = _x_5; /*float64*/
  }
  _x_x2176 = (_x_x2177 * _x_x2179); /*float64*/
  _x_x2171 = (_x_x2172 + _x_x2176); /*float64*/
  e = (_x_x2170 + _x_x2171); /*float64*/
  bool b_10040;
  double _x_x2180;
  {
    double _x_6 = z_0.num;
    _x_x2180 = _x_6; /*float64*/
  }
  b_10040 = isfinite(_x_x2180); /*bool*/
  if (b_10040) {
    double z_1;
    double _x_x2181;
    {
      double _x_6_0 = z_0.num;
      _x_x2181 = _x_6_0; /*float64*/
    }
    z_1 = (_x_x2181 + e); /*float64*/
    double err_0;
    double _x_x2182;
    double _x_x2183;
    {
      double _x_6_1 = z_0.num;
      _x_x2183 = _x_6_1; /*float64*/
    }
    _x_x2182 = (z_1 - _x_x2183); /*float64*/
    err_0 = (e - _x_x2182); /*float64*/
    double _x_x2184;
    bool _match_x752 = isfinite(z_1); /*bool*/;
    if (_match_x752) {
      _x_x2184 = err_0; /*float64*/
    }
    else {
      _x_x2184 = z_1; /*float64*/
    }
    return kk_std_num_ddouble__new_Ddouble(z_1, _x_x2184, _ctx);
  }
  {
    double _x_x2185;
    {
      double _x_6_2 = z_0.num;
      _x_x2185 = _x_6_2; /*float64*/
    }
    return kk_std_num_ddouble__new_Ddouble(_x_x2185, 0x0p+0, _ctx);
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp2m1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_0_10399 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_dd_ln2, x, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x745;
  double _x_x2186;
  {
    double _x = x_0_10399.hi;
    _x_x2186 = _x; /*float64*/
  }
  _match_x745 = (isinf(_x_x2186) && !signbit(_x_x2186)); /*bool*/
  if (_match_x745) {
    return x_0_10399;
  }
  {
    kk_std_num_ddouble__ddouble y = kk_std_num_ddouble_exp(x_0_10399, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_x746 = kk_std_num_ddouble__lp__eq__eq__rp_(y, kk_std_num_ddouble_one, _ctx); /*bool*/;
    if (_match_x746) {
      return x_0_10399;
    }
    {
      kk_std_num_ddouble__ddouble ym;
      kk_std_num_ddouble__ddouble _x_x2187;
      double _x_x2188;
      double _x_x2189;
      kk_std_num_ddouble__ddouble _x_x2190 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_0 = _x_x2190.hi;
        _x_x2189 = _x_0; /*float64*/
      }
      _x_x2188 = (-_x_x2189); /*float64*/
      double _x_x2191;
      double _x_x2192;
      kk_std_num_ddouble__ddouble _x_x2193 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_0_0 = _x_x2193.lo;
        _x_x2192 = _x_0_0; /*float64*/
      }
      _x_x2191 = (-_x_x2192); /*float64*/
      _x_x2187 = kk_std_num_ddouble__new_Ddouble(_x_x2188, _x_x2191, _ctx); /*std/num/ddouble/ddouble*/
      ym = kk_std_num_ddouble__lp__plus__rp_(y, _x_x2187, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble y_1_10405;
      double _x_x2194;
      double _x_x2195;
      kk_std_num_ddouble__ddouble _x_x2196 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_1 = _x_x2196.hi;
        _x_x2195 = _x_1; /*float64*/
      }
      _x_x2194 = (-_x_x2195); /*float64*/
      double _x_x2197;
      double _x_x2198;
      kk_std_num_ddouble__ddouble _x_x2199 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
      {
        double _x_0_1 = _x_x2199.lo;
        _x_x2198 = _x_0_1; /*float64*/
      }
      _x_x2197 = (-_x_x2198); /*float64*/
      y_1_10405 = kk_std_num_ddouble__new_Ddouble(_x_x2194, _x_x2197, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_core_types__order x_4_10406;
      kk_std_core_types__order _match_x751;
      double _x_x2200;
      {
        double _x_2 = ym.hi;
        _x_x2200 = _x_2; /*float64*/
      }
      double _x_x2201;
      {
        double _x_0_2 = y_1_10405.hi;
        _x_x2201 = _x_0_2; /*float64*/
      }
      _match_x751 = kk_std_num_float64_cmp(_x_x2200, _x_x2201, _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x751, _ctx)) {
        double _x_x2202;
        {
          double _x_1_0 = ym.lo;
          _x_x2202 = _x_1_0; /*float64*/
        }
        double _x_x2203;
        {
          double _x_2_0 = y_1_10405.lo;
          _x_x2203 = _x_2_0; /*float64*/
        }
        x_4_10406 = kk_std_num_float64_cmp(_x_x2202, _x_x2203, _ctx); /*order*/
      }
      else {
        x_4_10406 = _match_x751; /*order*/
      }
      bool _match_x747;
      kk_integer_t _brw_x749;
      if (kk_std_core_types__is_Lt(x_4_10406, _ctx)) {
        _brw_x749 = kk_integer_from_small(-1); /*int*/
        goto _match_x2204;
      }
      if (kk_std_core_types__is_Eq(x_4_10406, _ctx)) {
        _brw_x749 = kk_integer_from_small(0); /*int*/
        goto _match_x2204;
      }
      {
        _brw_x749 = kk_integer_from_small(1); /*int*/
      }
      _match_x2204: ;
      bool _brw_x750 = kk_integer_eq_borrow(_brw_x749,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x749, _ctx);
      _match_x747 = _brw_x750; /*bool*/
      if (_match_x747) {
        double _x_x2205;
        double _x_x2206;
        kk_std_num_ddouble__ddouble _x_x2207 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_3 = _x_x2207.hi;
          _x_x2206 = _x_3; /*float64*/
        }
        _x_x2205 = (-_x_x2206); /*float64*/
        double _x_x2208;
        double _x_x2209;
        kk_std_num_ddouble__ddouble _x_x2210 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_0_3 = _x_x2210.lo;
          _x_x2209 = _x_0_3; /*float64*/
        }
        _x_x2208 = (-_x_x2209); /*float64*/
        return kk_std_num_ddouble__new_Ddouble(_x_x2205, _x_x2208, _ctx);
      }
      {
        kk_std_num_ddouble__ddouble y_1_10759;
        kk_std_num_ddouble__ddouble _x_x2211 = kk_std_num_ddouble_ln(y, _ctx); /*std/num/ddouble/ddouble*/
        y_1_10759 = kk_std_num_ddouble__lp__fs__rp_(x_0_10399, _x_x2211, _ctx); /*std/num/ddouble/ddouble*/
        double z;
        double _x_x2212;
        {
          double _x_4 = ym.hi;
          _x_x2212 = _x_4; /*float64*/
        }
        double _x_x2213;
        {
          double _x_0_4 = y_1_10759.hi;
          _x_x2213 = _x_0_4; /*float64*/
        }
        z = (_x_x2212 * _x_x2213); /*float64*/
        double err;
        double _x_x2214;
        {
          double _x_4_0 = ym.hi;
          _x_x2214 = _x_4_0; /*float64*/
        }
        double _x_x2215;
        {
          double _x_0_4_0 = y_1_10759.hi;
          _x_x2215 = _x_0_4_0; /*float64*/
        }
        double _x_x2216 = (-z); /*float64*/
        err = kk_std_num_float64_fmadd(_x_x2214, _x_x2215, _x_x2216, _ctx); /*float64*/
        kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
        double e;
        double _x_x2217;
        {
          double _x_1_1 = z_0.err;
          _x_x2217 = _x_1_1; /*float64*/
        }
        double _x_x2218;
        double _x_x2219;
        double _x_x2220;
        {
          double _x_2_1 = ym.hi;
          _x_x2220 = _x_2_1; /*float64*/
        }
        double _x_x2221;
        {
          double _x_3_0 = y_1_10759.lo;
          _x_x2221 = _x_3_0; /*float64*/
        }
        _x_x2219 = (_x_x2220 * _x_x2221); /*float64*/
        double _x_x2222;
        double _x_x2223;
        {
          double _x_4_0_0 = ym.lo;
          _x_x2223 = _x_4_0_0; /*float64*/
        }
        double _x_x2224;
        {
          double _x_5 = y_1_10759.hi;
          _x_x2224 = _x_5; /*float64*/
        }
        _x_x2222 = (_x_x2223 * _x_x2224); /*float64*/
        _x_x2218 = (_x_x2219 + _x_x2222); /*float64*/
        e = (_x_x2217 + _x_x2218); /*float64*/
        bool b_10040;
        double _x_x2225;
        {
          double _x_6 = z_0.num;
          _x_x2225 = _x_6; /*float64*/
        }
        b_10040 = isfinite(_x_x2225); /*bool*/
        if (b_10040) {
          double z_1;
          double _x_x2226;
          {
            double _x_6_0 = z_0.num;
            _x_x2226 = _x_6_0; /*float64*/
          }
          z_1 = (_x_x2226 + e); /*float64*/
          double err_0;
          double _x_x2227;
          double _x_x2228;
          {
            double _x_6_1 = z_0.num;
            _x_x2228 = _x_6_1; /*float64*/
          }
          _x_x2227 = (z_1 - _x_x2228); /*float64*/
          err_0 = (e - _x_x2227); /*float64*/
          double _x_x2229;
          bool _match_x748 = isfinite(z_1); /*bool*/;
          if (_match_x748) {
            _x_x2229 = err_0; /*float64*/
          }
          else {
            _x_x2229 = z_1; /*float64*/
          }
          return kk_std_num_ddouble__new_Ddouble(z_1, _x_x2229, _ctx);
        }
        {
          double _x_x2230;
          {
            double _x_6_2 = z_0.num;
            _x_x2230 = _x_6_2; /*float64*/
          }
          return kk_std_num_ddouble__new_Ddouble(_x_x2230, 0x0p+0, _ctx);
        }
      }
    }
  }
}
 
// Returns `ln(exp(x) + exp(y))`.
// Avoids overlow/underflow errors.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_lnaddexp(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_x737 = kk_std_num_ddouble__lp__eq__eq__rp_(x, y, _ctx); /*bool*/;
  if (_match_x737) {
    return kk_std_num_ddouble__lp__plus__rp_(x, kk_std_num_ddouble_dd_ln2, _ctx);
  }
  {
    kk_std_num_ddouble__ddouble z;
    kk_std_num_ddouble__ddouble _x_x2231;
    double _x_x2232;
    double _x_x2233;
    {
      double _x = y.hi;
      _x_x2233 = _x; /*float64*/
    }
    _x_x2232 = (-_x_x2233); /*float64*/
    double _x_x2234;
    double _x_x2235;
    {
      double _x_0 = y.lo;
      _x_x2235 = _x_0; /*float64*/
    }
    _x_x2234 = (-_x_x2235); /*float64*/
    _x_x2231 = kk_std_num_ddouble__new_Ddouble(_x_x2232, _x_x2234, _ctx); /*std/num/ddouble/ddouble*/
    z = kk_std_num_ddouble__lp__plus__rp_(x, _x_x2231, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_x738;
    double _x_x2236;
    {
      double _x_1 = z.hi;
      _x_x2236 = _x_1; /*float64*/
    }
    _match_x738 = (_x_x2236 > (0x0p+0)); /*bool*/
    if (_match_x738) {
      kk_std_num_ddouble__ddouble x_2_10413;
      kk_std_num_ddouble__ddouble _x_x2237;
      double _x_x2238;
      double _x_x2239;
      {
        double _x_2 = z.hi;
        _x_x2239 = _x_2; /*float64*/
      }
      _x_x2238 = (-_x_x2239); /*float64*/
      double _x_x2240;
      double _x_x2241;
      {
        double _x_0_0 = z.lo;
        _x_x2241 = _x_0_0; /*float64*/
      }
      _x_x2240 = (-_x_x2241); /*float64*/
      _x_x2237 = kk_std_num_ddouble__new_Ddouble(_x_x2238, _x_x2240, _ctx); /*std/num/ddouble/ddouble*/
      x_2_10413 = kk_std_num_ddouble_exp(_x_x2237, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x2242;
      bool _match_x742;
      double _x_x2243;
      {
        double _x_0_1 = x_2_10413.hi;
        _x_x2243 = _x_0_1; /*float64*/
      }
      _match_x742 = (isinf(_x_x2243) && !signbit(_x_x2243)); /*bool*/
      if (_match_x742) {
        _x_x2242 = x_2_10413; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_num_ddouble__ddouble y_1 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, x_2_10413, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble z_0;
        kk_std_num_ddouble__ddouble _x_x2244;
        double _x_x2245;
        double _x_x2246;
        kk_std_num_ddouble__ddouble _x_x2247 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_3 = _x_x2247.hi;
          _x_x2246 = _x_3; /*float64*/
        }
        _x_x2245 = (-_x_x2246); /*float64*/
        double _x_x2248;
        double _x_x2249;
        kk_std_num_ddouble__ddouble _x_x2250 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_0_2 = _x_x2250.lo;
          _x_x2249 = _x_0_2; /*float64*/
        }
        _x_x2248 = (-_x_x2249); /*float64*/
        _x_x2244 = kk_std_num_ddouble__new_Ddouble(_x_x2245, _x_x2248, _ctx); /*std/num/ddouble/ddouble*/
        z_0 = kk_std_num_ddouble__lp__plus__rp_(y_1, _x_x2244, _ctx); /*std/num/ddouble/ddouble*/
        bool _match_x743;
        double _x_x2251;
        {
          double _x_1_0 = z_0.hi;
          _x_x2251 = _x_1_0; /*float64*/
        }
        _match_x743 = (_x_x2251 == (0x0p+0)); /*bool*/
        if (_match_x743) {
          _x_x2242 = x_2_10413; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_std_num_ddouble__ddouble x_3_10763 = kk_std_num_ddouble_ln(y_1, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble y_0_10764 = kk_std_num_ddouble__lp__fs__rp_(x_2_10413, z_0, _ctx); /*std/num/ddouble/ddouble*/;
          double z_1;
          double _x_x2252;
          {
            double _x_4 = x_3_10763.hi;
            _x_x2252 = _x_4; /*float64*/
          }
          double _x_x2253;
          {
            double _x_0_3 = y_0_10764.hi;
            _x_x2253 = _x_0_3; /*float64*/
          }
          z_1 = (_x_x2252 * _x_x2253); /*float64*/
          double err;
          double _x_x2254;
          {
            double _x_4_0 = x_3_10763.hi;
            _x_x2254 = _x_4_0; /*float64*/
          }
          double _x_x2255;
          {
            double _x_0_3_0 = y_0_10764.hi;
            _x_x2255 = _x_0_3_0; /*float64*/
          }
          double _x_x2256 = (-z_1); /*float64*/
          err = kk_std_num_float64_fmadd(_x_x2254, _x_x2255, _x_x2256, _ctx); /*float64*/
          kk_std_num_ddouble__edouble z_0_0 = kk_std_num_ddouble__new_Edouble(z_1, err, _ctx); /*std/num/ddouble/edouble*/;
          double e;
          double _x_x2257;
          {
            double _x_1_1 = z_0_0.err;
            _x_x2257 = _x_1_1; /*float64*/
          }
          double _x_x2258;
          double _x_x2259;
          double _x_x2260;
          {
            double _x_2_0 = x_3_10763.hi;
            _x_x2260 = _x_2_0; /*float64*/
          }
          double _x_x2261;
          {
            double _x_3_0 = y_0_10764.lo;
            _x_x2261 = _x_3_0; /*float64*/
          }
          _x_x2259 = (_x_x2260 * _x_x2261); /*float64*/
          double _x_x2262;
          double _x_x2263;
          {
            double _x_4_0_0 = x_3_10763.lo;
            _x_x2263 = _x_4_0_0; /*float64*/
          }
          double _x_x2264;
          {
            double _x_5 = y_0_10764.hi;
            _x_x2264 = _x_5; /*float64*/
          }
          _x_x2262 = (_x_x2263 * _x_x2264); /*float64*/
          _x_x2258 = (_x_x2259 + _x_x2262); /*float64*/
          e = (_x_x2257 + _x_x2258); /*float64*/
          bool b_10040;
          double _x_x2265;
          {
            double _x_6 = z_0_0.num;
            _x_x2265 = _x_6; /*float64*/
          }
          b_10040 = isfinite(_x_x2265); /*bool*/
          if (b_10040) {
            double z_1_0;
            double _x_x2266;
            {
              double _x_6_0 = z_0_0.num;
              _x_x2266 = _x_6_0; /*float64*/
            }
            z_1_0 = (_x_x2266 + e); /*float64*/
            double err_0;
            double _x_x2267;
            double _x_x2268;
            {
              double _x_6_1 = z_0_0.num;
              _x_x2268 = _x_6_1; /*float64*/
            }
            _x_x2267 = (z_1_0 - _x_x2268); /*float64*/
            err_0 = (e - _x_x2267); /*float64*/
            double _x_x2269;
            bool _match_x744 = isfinite(z_1_0); /*bool*/;
            if (_match_x744) {
              _x_x2269 = err_0; /*float64*/
            }
            else {
              _x_x2269 = z_1_0; /*float64*/
            }
            _x_x2242 = kk_std_num_ddouble__new_Ddouble(z_1_0, _x_x2269, _ctx); /*std/num/ddouble/ddouble*/
          }
          else {
            double _x_x2270;
            {
              double _x_6_2 = z_0_0.num;
              _x_x2270 = _x_6_2; /*float64*/
            }
            _x_x2242 = kk_std_num_ddouble__new_Ddouble(_x_x2270, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          }
        }
      }
      return kk_std_num_ddouble__lp__plus__rp_(x, _x_x2242, _ctx);
    }
    {
      kk_std_num_ddouble__ddouble x_6_10421 = kk_std_num_ddouble_exp(z, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x_x2271;
      bool _match_x739;
      double _x_x2272;
      {
        double _x_2_1 = x_6_10421.hi;
        _x_x2272 = _x_2_1; /*float64*/
      }
      _match_x739 = (isinf(_x_x2272) && !signbit(_x_x2272)); /*bool*/
      if (_match_x739) {
        _x_x2271 = x_6_10421; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_num_ddouble__ddouble y_3 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, x_6_10421, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble z_1_1;
        kk_std_num_ddouble__ddouble _x_x2273;
        double _x_x2274;
        double _x_x2275;
        kk_std_num_ddouble__ddouble _x_x2276 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_7 = _x_x2276.hi;
          _x_x2275 = _x_7; /*float64*/
        }
        _x_x2274 = (-_x_x2275); /*float64*/
        double _x_x2277;
        double _x_x2278;
        kk_std_num_ddouble__ddouble _x_x2279 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_0_4 = _x_x2279.lo;
          _x_x2278 = _x_0_4; /*float64*/
        }
        _x_x2277 = (-_x_x2278); /*float64*/
        _x_x2273 = kk_std_num_ddouble__new_Ddouble(_x_x2274, _x_x2277, _ctx); /*std/num/ddouble/ddouble*/
        z_1_1 = kk_std_num_ddouble__lp__plus__rp_(y_3, _x_x2273, _ctx); /*std/num/ddouble/ddouble*/
        bool _match_x740;
        double _x_x2280;
        {
          double _x_3_1 = z_1_1.hi;
          _x_x2280 = _x_3_1; /*float64*/
        }
        _match_x740 = (_x_x2280 == (0x0p+0)); /*bool*/
        if (_match_x740) {
          _x_x2271 = x_6_10421; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_std_num_ddouble__ddouble x_5_10766 = kk_std_num_ddouble_ln(y_3, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble y_2_10767 = kk_std_num_ddouble__lp__fs__rp_(x_6_10421, z_1_1, _ctx); /*std/num/ddouble/ddouble*/;
          double z_2;
          double _x_x2281;
          {
            double _x_8 = x_5_10766.hi;
            _x_x2281 = _x_8; /*float64*/
          }
          double _x_x2282;
          {
            double _x_0_5 = y_2_10767.hi;
            _x_x2282 = _x_0_5; /*float64*/
          }
          z_2 = (_x_x2281 * _x_x2282); /*float64*/
          double err_1;
          double _x_x2283;
          {
            double _x_8_0 = x_5_10766.hi;
            _x_x2283 = _x_8_0; /*float64*/
          }
          double _x_x2284;
          {
            double _x_0_5_0 = y_2_10767.hi;
            _x_x2284 = _x_0_5_0; /*float64*/
          }
          double _x_x2285 = (-z_2); /*float64*/
          err_1 = kk_std_num_float64_fmadd(_x_x2283, _x_x2284, _x_x2285, _ctx); /*float64*/
          kk_std_num_ddouble__edouble z_0_1 = kk_std_num_ddouble__new_Edouble(z_2, err_1, _ctx); /*std/num/ddouble/edouble*/;
          double e_0;
          double _x_x2286;
          {
            double _x_1_2 = z_0_1.err;
            _x_x2286 = _x_1_2; /*float64*/
          }
          double _x_x2287;
          double _x_x2288;
          double _x_x2289;
          {
            double _x_2_2 = x_5_10766.hi;
            _x_x2289 = _x_2_2; /*float64*/
          }
          double _x_x2290;
          {
            double _x_3_2 = y_2_10767.lo;
            _x_x2290 = _x_3_2; /*float64*/
          }
          _x_x2288 = (_x_x2289 * _x_x2290); /*float64*/
          double _x_x2291;
          double _x_x2292;
          {
            double _x_4_1 = x_5_10766.lo;
            _x_x2292 = _x_4_1; /*float64*/
          }
          double _x_x2293;
          {
            double _x_5_0 = y_2_10767.hi;
            _x_x2293 = _x_5_0; /*float64*/
          }
          _x_x2291 = (_x_x2292 * _x_x2293); /*float64*/
          _x_x2287 = (_x_x2288 + _x_x2291); /*float64*/
          e_0 = (_x_x2286 + _x_x2287); /*float64*/
          bool b_10040_0;
          double _x_x2294;
          {
            double _x_6_0_0 = z_0_1.num;
            _x_x2294 = _x_6_0_0; /*float64*/
          }
          b_10040_0 = isfinite(_x_x2294); /*bool*/
          if (b_10040_0) {
            double z_1_2;
            double _x_x2295;
            {
              double _x_6_0_1 = z_0_1.num;
              _x_x2295 = _x_6_0_1; /*float64*/
            }
            z_1_2 = (_x_x2295 + e_0); /*float64*/
            double err_0_0;
            double _x_x2296;
            double _x_x2297;
            {
              double _x_6_0_2 = z_0_1.num;
              _x_x2297 = _x_6_0_2; /*float64*/
            }
            _x_x2296 = (z_1_2 - _x_x2297); /*float64*/
            err_0_0 = (e_0 - _x_x2296); /*float64*/
            double _x_x2298;
            bool _match_x741 = isfinite(z_1_2); /*bool*/;
            if (_match_x741) {
              _x_x2298 = err_0_0; /*float64*/
            }
            else {
              _x_x2298 = z_1_2; /*float64*/
            }
            _x_x2271 = kk_std_num_ddouble__new_Ddouble(z_1_2, _x_x2298, _ctx); /*std/num/ddouble/ddouble*/
          }
          else {
            double _x_x2299;
            {
              double _x_6_0_3 = z_0_1.num;
              _x_x2299 = _x_6_0_3; /*float64*/
            }
            _x_x2271 = kk_std_num_ddouble__new_Ddouble(_x_x2299, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          }
        }
      }
      return kk_std_num_ddouble__lp__plus__rp_(y, _x_x2271, _ctx);
    }
  }
}
 
// Returns `log2( exp2(x) + exp2(y) )`.
// Avoids overlow/underflow errors.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_logaddexp2(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_x731 = kk_std_num_ddouble__lp__eq__eq__rp_(x, y, _ctx); /*bool*/;
  if (_match_x731) {
    return kk_std_num_ddouble__lp__plus__rp_(x, kk_std_num_ddouble_one, _ctx);
  }
  {
    kk_std_num_ddouble__ddouble z;
    kk_std_num_ddouble__ddouble _x_x2300;
    double _x_x2301;
    double _x_x2302;
    {
      double _x = y.hi;
      _x_x2302 = _x; /*float64*/
    }
    _x_x2301 = (-_x_x2302); /*float64*/
    double _x_x2303;
    double _x_x2304;
    {
      double _x_0 = y.lo;
      _x_x2304 = _x_0; /*float64*/
    }
    _x_x2303 = (-_x_x2304); /*float64*/
    _x_x2300 = kk_std_num_ddouble__new_Ddouble(_x_x2301, _x_x2303, _ctx); /*std/num/ddouble/ddouble*/
    z = kk_std_num_ddouble__lp__plus__rp_(x, _x_x2300, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_x732;
    double _x_x2305;
    {
      double _x_1 = z.hi;
      _x_x2305 = _x_1; /*float64*/
    }
    _match_x732 = (_x_x2305 > (0x0p+0)); /*bool*/
    if (_match_x732) {
      kk_std_num_ddouble__ddouble exp_0_10435;
      double _x_x2306;
      double _x_x2307;
      {
        double _x_2 = z.hi;
        _x_x2307 = _x_2; /*float64*/
      }
      _x_x2306 = (-_x_x2307); /*float64*/
      double _x_x2308;
      double _x_x2309;
      {
        double _x_0_0 = z.lo;
        _x_x2309 = _x_0_0; /*float64*/
      }
      _x_x2308 = (-_x_x2309); /*float64*/
      exp_0_10435 = kk_std_num_ddouble__new_Ddouble(_x_x2306, _x_x2308, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble y_0_10771 = kk_std_num_ddouble_ln(kk_std_num_ddouble_two, _ctx); /*std/num/ddouble/ddouble*/;
      double z_0;
      double _x_x2310;
      {
        double _x_3 = exp_0_10435.hi;
        _x_x2310 = _x_3; /*float64*/
      }
      double _x_x2311;
      {
        double _x_0_1 = y_0_10771.hi;
        _x_x2311 = _x_0_1; /*float64*/
      }
      z_0 = (_x_x2310 * _x_x2311); /*float64*/
      double err;
      double _x_x2312;
      {
        double _x_3_0 = exp_0_10435.hi;
        _x_x2312 = _x_3_0; /*float64*/
      }
      double _x_x2313;
      {
        double _x_0_1_0 = y_0_10771.hi;
        _x_x2313 = _x_0_1_0; /*float64*/
      }
      double _x_x2314 = (-z_0); /*float64*/
      err = kk_std_num_float64_fmadd(_x_x2312, _x_x2313, _x_x2314, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0_0 = kk_std_num_ddouble__new_Edouble(z_0, err, _ctx); /*std/num/ddouble/edouble*/;
      double e;
      double _x_x2315;
      {
        double _x_1_0 = z_0_0.err;
        _x_x2315 = _x_1_0; /*float64*/
      }
      double _x_x2316;
      double _x_x2317;
      double _x_x2318;
      {
        double _x_2_0 = exp_0_10435.hi;
        _x_x2318 = _x_2_0; /*float64*/
      }
      double _x_x2319;
      {
        double _x_3_0_0 = y_0_10771.lo;
        _x_x2319 = _x_3_0_0; /*float64*/
      }
      _x_x2317 = (_x_x2318 * _x_x2319); /*float64*/
      double _x_x2320;
      double _x_x2321;
      {
        double _x_4 = exp_0_10435.lo;
        _x_x2321 = _x_4; /*float64*/
      }
      double _x_x2322;
      {
        double _x_5 = y_0_10771.hi;
        _x_x2322 = _x_5; /*float64*/
      }
      _x_x2320 = (_x_x2321 * _x_x2322); /*float64*/
      _x_x2316 = (_x_x2317 + _x_x2320); /*float64*/
      e = (_x_x2315 + _x_x2316); /*float64*/
      bool b_10040;
      double _x_x2323;
      {
        double _x_6 = z_0_0.num;
        _x_x2323 = _x_6; /*float64*/
      }
      b_10040 = isfinite(_x_x2323); /*bool*/
      kk_std_num_ddouble__ddouble x_2_10434;
      kk_std_num_ddouble__ddouble _x_x2324;
      if (b_10040) {
        double z_1;
        double _x_x2325;
        {
          double _x_6_0 = z_0_0.num;
          _x_x2325 = _x_6_0; /*float64*/
        }
        z_1 = (_x_x2325 + e); /*float64*/
        double err_0;
        double _x_x2326;
        double _x_x2327;
        {
          double _x_6_1 = z_0_0.num;
          _x_x2327 = _x_6_1; /*float64*/
        }
        _x_x2326 = (z_1 - _x_x2327); /*float64*/
        err_0 = (e - _x_x2326); /*float64*/
        double _x_x2328;
        bool _match_x736 = isfinite(z_1); /*bool*/;
        if (_match_x736) {
          _x_x2328 = err_0; /*float64*/
        }
        else {
          _x_x2328 = z_1; /*float64*/
        }
        _x_x2324 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x2328, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double _x_x2329;
        {
          double _x_6_2 = z_0_0.num;
          _x_x2329 = _x_6_2; /*float64*/
        }
        _x_x2324 = kk_std_num_ddouble__new_Ddouble(_x_x2329, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      }
      x_2_10434 = kk_std_num_ddouble_exp(_x_x2324, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble y_1_10773 = kk_std_num_ddouble_ln1p(x_2_10434, _ctx); /*std/num/ddouble/ddouble*/;
      double z_2;
      double _x_x2330;
      kk_std_num_ddouble__ddouble _x_x2331 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
      {
        double _x_7 = _x_x2331.hi;
        _x_x2330 = _x_7; /*float64*/
      }
      double _x_x2332;
      {
        double _x_0_2 = y_1_10773.hi;
        _x_x2332 = _x_0_2; /*float64*/
      }
      z_2 = (_x_x2330 * _x_x2332); /*float64*/
      double err_1;
      double _x_x2333;
      kk_std_num_ddouble__ddouble _x_x2334 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
      {
        double _x_7_0 = _x_x2334.hi;
        _x_x2333 = _x_7_0; /*float64*/
      }
      double _x_x2335;
      {
        double _x_0_2_0 = y_1_10773.hi;
        _x_x2335 = _x_0_2_0; /*float64*/
      }
      double _x_x2336 = (-z_2); /*float64*/
      err_1 = kk_std_num_float64_fmadd(_x_x2333, _x_x2335, _x_x2336, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0_1 = kk_std_num_ddouble__new_Edouble(z_2, err_1, _ctx); /*std/num/ddouble/edouble*/;
      double e_0;
      double _x_x2337;
      {
        double _x_1_1 = z_0_1.err;
        _x_x2337 = _x_1_1; /*float64*/
      }
      double _x_x2338;
      double _x_x2339;
      double _x_x2340;
      kk_std_num_ddouble__ddouble _x_x2341 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
      {
        double _x_2_1 = _x_x2341.hi;
        _x_x2340 = _x_2_1; /*float64*/
      }
      double _x_x2342;
      {
        double _x_3_1 = y_1_10773.lo;
        _x_x2342 = _x_3_1; /*float64*/
      }
      _x_x2339 = (_x_x2340 * _x_x2342); /*float64*/
      double _x_x2343;
      double _x_x2344;
      kk_std_num_ddouble__ddouble _x_x2345 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
      {
        double _x_4_0 = _x_x2345.lo;
        _x_x2344 = _x_4_0; /*float64*/
      }
      double _x_x2346;
      {
        double _x_5_0 = y_1_10773.hi;
        _x_x2346 = _x_5_0; /*float64*/
      }
      _x_x2343 = (_x_x2344 * _x_x2346); /*float64*/
      _x_x2338 = (_x_x2339 + _x_x2343); /*float64*/
      e_0 = (_x_x2337 + _x_x2338); /*float64*/
      bool b_10040_0;
      double _x_x2347;
      {
        double _x_6_0_0 = z_0_1.num;
        _x_x2347 = _x_6_0_0; /*float64*/
      }
      b_10040_0 = isfinite(_x_x2347); /*bool*/
      kk_std_num_ddouble__ddouble _x_x2348;
      if (b_10040_0) {
        double z_1_0;
        double _x_x2349;
        {
          double _x_6_0_1 = z_0_1.num;
          _x_x2349 = _x_6_0_1; /*float64*/
        }
        z_1_0 = (_x_x2349 + e_0); /*float64*/
        double err_0_0;
        double _x_x2350;
        double _x_x2351;
        {
          double _x_6_0_2 = z_0_1.num;
          _x_x2351 = _x_6_0_2; /*float64*/
        }
        _x_x2350 = (z_1_0 - _x_x2351); /*float64*/
        err_0_0 = (e_0 - _x_x2350); /*float64*/
        double _x_x2352;
        bool _match_x735 = isfinite(z_1_0); /*bool*/;
        if (_match_x735) {
          _x_x2352 = err_0_0; /*float64*/
        }
        else {
          _x_x2352 = z_1_0; /*float64*/
        }
        _x_x2348 = kk_std_num_ddouble__new_Ddouble(z_1_0, _x_x2352, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double _x_x2353;
        {
          double _x_6_0_3 = z_0_1.num;
          _x_x2353 = _x_6_0_3; /*float64*/
        }
        _x_x2348 = kk_std_num_ddouble__new_Ddouble(_x_x2353, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      }
      return kk_std_num_ddouble__lp__plus__rp_(x, _x_x2348, _ctx);
    }
    {
      kk_std_num_ddouble__ddouble y_2_10775 = kk_std_num_ddouble_ln(kk_std_num_ddouble_two, _ctx); /*std/num/ddouble/ddouble*/;
      double z_3;
      double _x_x2354;
      {
        double _x_8 = z.hi;
        _x_x2354 = _x_8; /*float64*/
      }
      double _x_x2355;
      {
        double _x_0_3 = y_2_10775.hi;
        _x_x2355 = _x_0_3; /*float64*/
      }
      z_3 = (_x_x2354 * _x_x2355); /*float64*/
      double err_2;
      double _x_x2356;
      {
        double _x_8_0 = z.hi;
        _x_x2356 = _x_8_0; /*float64*/
      }
      double _x_x2357;
      {
        double _x_0_3_0 = y_2_10775.hi;
        _x_x2357 = _x_0_3_0; /*float64*/
      }
      double _x_x2358 = (-z_3); /*float64*/
      err_2 = kk_std_num_float64_fmadd(_x_x2356, _x_x2357, _x_x2358, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0_2 = kk_std_num_ddouble__new_Edouble(z_3, err_2, _ctx); /*std/num/ddouble/edouble*/;
      double e_1;
      double _x_x2359;
      {
        double _x_1_2 = z_0_2.err;
        _x_x2359 = _x_1_2; /*float64*/
      }
      double _x_x2360;
      double _x_x2361;
      double _x_x2362;
      {
        double _x_2_2 = z.hi;
        _x_x2362 = _x_2_2; /*float64*/
      }
      double _x_x2363;
      {
        double _x_3_2 = y_2_10775.lo;
        _x_x2363 = _x_3_2; /*float64*/
      }
      _x_x2361 = (_x_x2362 * _x_x2363); /*float64*/
      double _x_x2364;
      double _x_x2365;
      {
        double _x_4_1 = z.lo;
        _x_x2365 = _x_4_1; /*float64*/
      }
      double _x_x2366;
      {
        double _x_5_1 = y_2_10775.hi;
        _x_x2366 = _x_5_1; /*float64*/
      }
      _x_x2364 = (_x_x2365 * _x_x2366); /*float64*/
      _x_x2360 = (_x_x2361 + _x_x2364); /*float64*/
      e_1 = (_x_x2359 + _x_x2360); /*float64*/
      bool b_10040_1;
      double _x_x2367;
      {
        double _x_6_1_0 = z_0_2.num;
        _x_x2367 = _x_6_1_0; /*float64*/
      }
      b_10040_1 = isfinite(_x_x2367); /*bool*/
      kk_std_num_ddouble__ddouble x_4_10438;
      kk_std_num_ddouble__ddouble _x_x2368;
      if (b_10040_1) {
        double z_1_1;
        double _x_x2369;
        {
          double _x_6_1_1 = z_0_2.num;
          _x_x2369 = _x_6_1_1; /*float64*/
        }
        z_1_1 = (_x_x2369 + e_1); /*float64*/
        double err_0_1;
        double _x_x2370;
        double _x_x2371;
        {
          double _x_6_1_2 = z_0_2.num;
          _x_x2371 = _x_6_1_2; /*float64*/
        }
        _x_x2370 = (z_1_1 - _x_x2371); /*float64*/
        err_0_1 = (e_1 - _x_x2370); /*float64*/
        double _x_x2372;
        bool _match_x734 = isfinite(z_1_1); /*bool*/;
        if (_match_x734) {
          _x_x2372 = err_0_1; /*float64*/
        }
        else {
          _x_x2372 = z_1_1; /*float64*/
        }
        _x_x2368 = kk_std_num_ddouble__new_Ddouble(z_1_1, _x_x2372, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double _x_x2373;
        {
          double _x_6_1_3 = z_0_2.num;
          _x_x2373 = _x_6_1_3; /*float64*/
        }
        _x_x2368 = kk_std_num_ddouble__new_Ddouble(_x_x2373, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      }
      x_4_10438 = kk_std_num_ddouble_exp(_x_x2368, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble y_3_10777 = kk_std_num_ddouble_ln1p(x_4_10438, _ctx); /*std/num/ddouble/ddouble*/;
      double z_4;
      double _x_x2374;
      kk_std_num_ddouble__ddouble _x_x2375 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
      {
        double _x_9 = _x_x2375.hi;
        _x_x2374 = _x_9; /*float64*/
      }
      double _x_x2376;
      {
        double _x_0_4 = y_3_10777.hi;
        _x_x2376 = _x_0_4; /*float64*/
      }
      z_4 = (_x_x2374 * _x_x2376); /*float64*/
      double err_3;
      double _x_x2377;
      kk_std_num_ddouble__ddouble _x_x2378 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
      {
        double _x_9_0 = _x_x2378.hi;
        _x_x2377 = _x_9_0; /*float64*/
      }
      double _x_x2379;
      {
        double _x_0_4_0 = y_3_10777.hi;
        _x_x2379 = _x_0_4_0; /*float64*/
      }
      double _x_x2380 = (-z_4); /*float64*/
      err_3 = kk_std_num_float64_fmadd(_x_x2377, _x_x2379, _x_x2380, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0_3 = kk_std_num_ddouble__new_Edouble(z_4, err_3, _ctx); /*std/num/ddouble/edouble*/;
      double e_2;
      double _x_x2381;
      {
        double _x_1_3 = z_0_3.err;
        _x_x2381 = _x_1_3; /*float64*/
      }
      double _x_x2382;
      double _x_x2383;
      double _x_x2384;
      kk_std_num_ddouble__ddouble _x_x2385 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
      {
        double _x_2_3 = _x_x2385.hi;
        _x_x2384 = _x_2_3; /*float64*/
      }
      double _x_x2386;
      {
        double _x_3_3 = y_3_10777.lo;
        _x_x2386 = _x_3_3; /*float64*/
      }
      _x_x2383 = (_x_x2384 * _x_x2386); /*float64*/
      double _x_x2387;
      double _x_x2388;
      kk_std_num_ddouble__ddouble _x_x2389 = kk_std_num_ddouble_dd_log2e; /*std/num/ddouble/ddouble*/
      {
        double _x_4_2 = _x_x2389.lo;
        _x_x2388 = _x_4_2; /*float64*/
      }
      double _x_x2390;
      {
        double _x_5_2 = y_3_10777.hi;
        _x_x2390 = _x_5_2; /*float64*/
      }
      _x_x2387 = (_x_x2388 * _x_x2390); /*float64*/
      _x_x2382 = (_x_x2383 + _x_x2387); /*float64*/
      e_2 = (_x_x2381 + _x_x2382); /*float64*/
      bool b_10040_2;
      double _x_x2391;
      {
        double _x_6_2_0 = z_0_3.num;
        _x_x2391 = _x_6_2_0; /*float64*/
      }
      b_10040_2 = isfinite(_x_x2391); /*bool*/
      kk_std_num_ddouble__ddouble _x_x2392;
      if (b_10040_2) {
        double z_1_2;
        double _x_x2393;
        {
          double _x_6_2_1 = z_0_3.num;
          _x_x2393 = _x_6_2_1; /*float64*/
        }
        z_1_2 = (_x_x2393 + e_2); /*float64*/
        double err_0_2;
        double _x_x2394;
        double _x_x2395;
        {
          double _x_6_2_2 = z_0_3.num;
          _x_x2395 = _x_6_2_2; /*float64*/
        }
        _x_x2394 = (z_1_2 - _x_x2395); /*float64*/
        err_0_2 = (e_2 - _x_x2394); /*float64*/
        double _x_x2396;
        bool _match_x733 = isfinite(z_1_2); /*bool*/;
        if (_match_x733) {
          _x_x2396 = err_0_2; /*float64*/
        }
        else {
          _x_x2396 = z_1_2; /*float64*/
        }
        _x_x2392 = kk_std_num_ddouble__new_Ddouble(z_1_2, _x_x2396, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double _x_x2397;
        {
          double _x_6_2_3 = z_0_3.num;
          _x_x2397 = _x_6_2_3; /*float64*/
        }
        _x_x2392 = kk_std_num_ddouble__new_Ddouble(_x_x2397, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      }
      return kk_std_num_ddouble__lp__plus__rp_(y, _x_x2392, _ctx);
    }
  }
}
 
// Return if two `:ddouble`s are nearly equal with respect to some `epsilon` (=`8*dd-epsilon`).
// The epsilon is the nearest difference for numbers around 1.0. The routine automatically
// scales the epsilon for larger and smaller numbers, and for numbers close to zero.

bool kk_std_num_ddouble_nearly_eq(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_core_types__optional epsilon, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble, epsilon : ? ddouble) -> bool */ 
  bool _match_x696 = kk_std_num_ddouble__lp__eq__eq__rp_(x, y, _ctx); /*bool*/;
  if (_match_x696) {
    kk_std_core_types__optional_drop(epsilon, _ctx);
    return true;
  }
  {
    kk_std_num_ddouble__ddouble x_0_10442;
    kk_std_num_ddouble__ddouble _x_x2398;
    double _x_x2399;
    double _x_x2400;
    {
      double _x = y.hi;
      _x_x2400 = _x; /*float64*/
    }
    _x_x2399 = (-_x_x2400); /*float64*/
    double _x_x2401;
    double _x_x2402;
    {
      double _x_0 = y.lo;
      _x_x2402 = _x_0; /*float64*/
    }
    _x_x2401 = (-_x_x2402); /*float64*/
    _x_x2398 = kk_std_num_ddouble__new_Ddouble(_x_x2399, _x_x2401, _ctx); /*std/num/ddouble/ddouble*/
    x_0_10442 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x2398, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble diff;
    bool _match_x730;
    double _x_x2403;
    {
      double _x_1 = x_0_10442.hi;
      _x_x2403 = _x_1; /*float64*/
    }
    _match_x730 = (_x_x2403 < (0x0p+0)); /*bool*/
    if (_match_x730) {
      double _x_x2404;
      double _x_x2405;
      {
        double _x_2 = x_0_10442.hi;
        _x_x2405 = _x_2; /*float64*/
      }
      _x_x2404 = (-_x_x2405); /*float64*/
      double _x_x2406;
      double _x_x2407;
      {
        double _x_0_0 = x_0_10442.lo;
        _x_x2407 = _x_0_0; /*float64*/
      }
      _x_x2406 = (-_x_x2407); /*float64*/
      diff = kk_std_num_ddouble__new_Ddouble(_x_x2404, _x_x2406, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      diff = x_0_10442; /*std/num/ddouble/ddouble*/
    }
    bool _match_x697;
    double _x_x2408;
    {
      double _x_0_1 = x.hi;
      _x_x2408 = _x_0_1; /*float64*/
    }
    _match_x697 = (_x_x2408 == (0x0p+0)); /*bool*/
    if (_match_x697) {
      kk_std_num_ddouble__ddouble x_4_10451 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_two, diff, _ctx); /*std/num/ddouble/ddouble*/;
      double z;
      double _x_x2409;
      kk_std_num_ddouble__ddouble _match_x729;
      if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
        kk_box_t _box_x375 = epsilon._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_epsilon_8558 = kk_std_num_ddouble__ddouble_unbox(_box_x375, KK_BORROWED, _ctx);
        _match_x729 = _uniq_epsilon_8558; /*std/num/ddouble/ddouble*/
      }
      else {
        _match_x729 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_3 = _match_x729.hi;
        _x_x2409 = _x_3; /*float64*/
      }
      double _x_x2410;
      kk_std_num_ddouble__ddouble _x_x2411 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
      {
        double _x_0_2 = _x_x2411.hi;
        _x_x2410 = _x_0_2; /*float64*/
      }
      z = (_x_x2409 * _x_x2410); /*float64*/
      double err;
      double _x_x2412;
      kk_std_num_ddouble__ddouble _match_x728;
      if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
        kk_box_t _box_x376 = epsilon._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_epsilon_8558_0 = kk_std_num_ddouble__ddouble_unbox(_box_x376, KK_BORROWED, _ctx);
        _match_x728 = _uniq_epsilon_8558_0; /*std/num/ddouble/ddouble*/
      }
      else {
        _match_x728 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_1_0 = _match_x728.hi;
        _x_x2412 = _x_1_0; /*float64*/
      }
      double _x_x2413;
      kk_std_num_ddouble__ddouble _x_x2414 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
      {
        double _x_0_0_0 = _x_x2414.hi;
        _x_x2413 = _x_0_0_0; /*float64*/
      }
      double _x_x2415 = (-z); /*float64*/
      err = kk_std_num_float64_fmadd(_x_x2412, _x_x2413, _x_x2415, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
      double e;
      double _x_x2416;
      {
        double _x_1_0_0 = z_0.err;
        _x_x2416 = _x_1_0_0; /*float64*/
      }
      double _x_x2417;
      double _x_x2418;
      double _x_x2419;
      kk_std_num_ddouble__ddouble _match_x727;
      if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
        kk_box_t _box_x377 = epsilon._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_epsilon_8558_1 = kk_std_num_ddouble__ddouble_unbox(_box_x377, KK_BORROWED, _ctx);
        _match_x727 = _uniq_epsilon_8558_1; /*std/num/ddouble/ddouble*/
      }
      else {
        _match_x727 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_2_0 = _match_x727.hi;
        _x_x2419 = _x_2_0; /*float64*/
      }
      double _x_x2420;
      kk_std_num_ddouble__ddouble _x_x2421 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
      {
        double _x_3_0 = _x_x2421.lo;
        _x_x2420 = _x_3_0; /*float64*/
      }
      _x_x2418 = (_x_x2419 * _x_x2420); /*float64*/
      double _x_x2422;
      double _x_x2423;
      kk_std_num_ddouble__ddouble _match_x726;
      if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
        kk_box_t _box_x378 = epsilon._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_epsilon_8558_2 = kk_std_num_ddouble__ddouble_unbox(_box_x378, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(epsilon, _ctx);
        _match_x726 = _uniq_epsilon_8558_2; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_core_types__optional_drop(epsilon, _ctx);
        _match_x726 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_4 = _match_x726.lo;
        _x_x2423 = _x_4; /*float64*/
      }
      double _x_x2424;
      kk_std_num_ddouble__ddouble _x_x2425 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
      {
        double _x_5 = _x_x2425.hi;
        _x_x2424 = _x_5; /*float64*/
      }
      _x_x2422 = (_x_x2423 * _x_x2424); /*float64*/
      _x_x2417 = (_x_x2418 + _x_x2422); /*float64*/
      e = (_x_x2416 + _x_x2417); /*float64*/
      bool b_10040;
      double _x_x2426;
      {
        double _x_6 = z_0.num;
        _x_x2426 = _x_6; /*float64*/
      }
      b_10040 = isfinite(_x_x2426); /*bool*/
      kk_std_num_ddouble__ddouble y_1_10452;
      if (b_10040) {
        double z_1;
        double _x_x2427;
        {
          double _x_6_0 = z_0.num;
          _x_x2427 = _x_6_0; /*float64*/
        }
        z_1 = (_x_x2427 + e); /*float64*/
        double err_0;
        double _x_x2428;
        double _x_x2429;
        {
          double _x_6_1 = z_0.num;
          _x_x2429 = _x_6_1; /*float64*/
        }
        _x_x2428 = (z_1 - _x_x2429); /*float64*/
        err_0 = (e - _x_x2428); /*float64*/
        double _x_x2430;
        bool _match_x725 = isfinite(z_1); /*bool*/;
        if (_match_x725) {
          _x_x2430 = err_0; /*float64*/
        }
        else {
          _x_x2430 = z_1; /*float64*/
        }
        y_1_10452 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x2430, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double _x_x2431;
        {
          double _x_6_2 = z_0.num;
          _x_x2431 = _x_6_2; /*float64*/
        }
        y_1_10452 = kk_std_num_ddouble__new_Ddouble(_x_x2431, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_core_types__order x_5_10453;
      kk_std_core_types__order _match_x724;
      double _x_x2432;
      {
        double _x_3_1 = x_4_10451.hi;
        _x_x2432 = _x_3_1; /*float64*/
      }
      double _x_x2433;
      {
        double _x_0_2_0 = y_1_10452.hi;
        _x_x2433 = _x_0_2_0; /*float64*/
      }
      _match_x724 = kk_std_num_float64_cmp(_x_x2432, _x_x2433, _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x724, _ctx)) {
        double _x_x2434;
        {
          double _x_1_0_1 = x_4_10451.lo;
          _x_x2434 = _x_1_0_1; /*float64*/
        }
        double _x_x2435;
        {
          double _x_2_0_0 = y_1_10452.lo;
          _x_x2435 = _x_2_0_0; /*float64*/
        }
        x_5_10453 = kk_std_num_float64_cmp(_x_x2434, _x_x2435, _ctx); /*order*/
      }
      else {
        x_5_10453 = _match_x724; /*order*/
      }
      kk_integer_t _brw_x722;
      if (kk_std_core_types__is_Lt(x_5_10453, _ctx)) {
        _brw_x722 = kk_integer_from_small(-1); /*int*/
        goto _match_x2436;
      }
      if (kk_std_core_types__is_Eq(x_5_10453, _ctx)) {
        _brw_x722 = kk_integer_from_small(0); /*int*/
        goto _match_x2436;
      }
      {
        _brw_x722 = kk_integer_from_small(1); /*int*/
      }
      _match_x2436: ;
      bool _brw_x723 = kk_integer_eq_borrow(_brw_x722,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x722, _ctx);
      return _brw_x723;
    }
    {
      bool _match_x698;
      double _x_x2437;
      {
        double _x_1_1 = y.hi;
        _x_x2437 = _x_1_1; /*float64*/
      }
      _match_x698 = (_x_x2437 == (0x0p+0)); /*bool*/
      if (_match_x698) {
        kk_std_num_ddouble__ddouble x_7_10458 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_two, diff, _ctx); /*std/num/ddouble/ddouble*/;
        double z_2;
        double _x_x2438;
        kk_std_num_ddouble__ddouble _match_x721;
        if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
          kk_box_t _box_x379 = epsilon._cons._Optional.value;
          kk_std_num_ddouble__ddouble _uniq_epsilon_8558_0_0 = kk_std_num_ddouble__ddouble_unbox(_box_x379, KK_BORROWED, _ctx);
          _match_x721 = _uniq_epsilon_8558_0_0; /*std/num/ddouble/ddouble*/
        }
        else {
          _match_x721 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_7 = _match_x721.hi;
          _x_x2438 = _x_7; /*float64*/
        }
        double _x_x2439;
        kk_std_num_ddouble__ddouble _x_x2440 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
        {
          double _x_0_3 = _x_x2440.hi;
          _x_x2439 = _x_0_3; /*float64*/
        }
        z_2 = (_x_x2438 * _x_x2439); /*float64*/
        double err_1;
        double _x_x2441;
        kk_std_num_ddouble__ddouble _match_x720;
        if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
          kk_box_t _box_x380 = epsilon._cons._Optional.value;
          kk_std_num_ddouble__ddouble _uniq_epsilon_8558_0_1 = kk_std_num_ddouble__ddouble_unbox(_box_x380, KK_BORROWED, _ctx);
          _match_x720 = _uniq_epsilon_8558_0_1; /*std/num/ddouble/ddouble*/
        }
        else {
          _match_x720 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_1_2 = _match_x720.hi;
          _x_x2441 = _x_1_2; /*float64*/
        }
        double _x_x2442;
        kk_std_num_ddouble__ddouble _x_x2443 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
        {
          double _x_0_0_1 = _x_x2443.hi;
          _x_x2442 = _x_0_0_1; /*float64*/
        }
        double _x_x2444 = (-z_2); /*float64*/
        err_1 = kk_std_num_float64_fmadd(_x_x2441, _x_x2442, _x_x2444, _ctx); /*float64*/
        kk_std_num_ddouble__edouble z_0_0 = kk_std_num_ddouble__new_Edouble(z_2, err_1, _ctx); /*std/num/ddouble/edouble*/;
        double e_0;
        double _x_x2445;
        {
          double _x_1_0_2 = z_0_0.err;
          _x_x2445 = _x_1_0_2; /*float64*/
        }
        double _x_x2446;
        double _x_x2447;
        double _x_x2448;
        kk_std_num_ddouble__ddouble _match_x719;
        if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
          kk_box_t _box_x381 = epsilon._cons._Optional.value;
          kk_std_num_ddouble__ddouble _uniq_epsilon_8558_0_2 = kk_std_num_ddouble__ddouble_unbox(_box_x381, KK_BORROWED, _ctx);
          _match_x719 = _uniq_epsilon_8558_0_2; /*std/num/ddouble/ddouble*/
        }
        else {
          _match_x719 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_2_1 = _match_x719.hi;
          _x_x2448 = _x_2_1; /*float64*/
        }
        double _x_x2449;
        kk_std_num_ddouble__ddouble _x_x2450 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
        {
          double _x_3_2 = _x_x2450.lo;
          _x_x2449 = _x_3_2; /*float64*/
        }
        _x_x2447 = (_x_x2448 * _x_x2449); /*float64*/
        double _x_x2451;
        double _x_x2452;
        kk_std_num_ddouble__ddouble _match_x718;
        if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
          kk_box_t _box_x382 = epsilon._cons._Optional.value;
          kk_std_num_ddouble__ddouble _uniq_epsilon_8558_0_3 = kk_std_num_ddouble__ddouble_unbox(_box_x382, KK_BORROWED, _ctx);
          kk_std_core_types__optional_drop(epsilon, _ctx);
          _match_x718 = _uniq_epsilon_8558_0_3; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_std_core_types__optional_drop(epsilon, _ctx);
          _match_x718 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_4_0 = _match_x718.lo;
          _x_x2452 = _x_4_0; /*float64*/
        }
        double _x_x2453;
        kk_std_num_ddouble__ddouble _x_x2454 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
        {
          double _x_5_0 = _x_x2454.hi;
          _x_x2453 = _x_5_0; /*float64*/
        }
        _x_x2451 = (_x_x2452 * _x_x2453); /*float64*/
        _x_x2446 = (_x_x2447 + _x_x2451); /*float64*/
        e_0 = (_x_x2445 + _x_x2446); /*float64*/
        bool b_10040_0;
        double _x_x2455;
        {
          double _x_6_3 = z_0_0.num;
          _x_x2455 = _x_6_3; /*float64*/
        }
        b_10040_0 = isfinite(_x_x2455); /*bool*/
        kk_std_num_ddouble__ddouble y_3_10459;
        if (b_10040_0) {
          double z_1_0;
          double _x_x2456;
          {
            double _x_6_0_0 = z_0_0.num;
            _x_x2456 = _x_6_0_0; /*float64*/
          }
          z_1_0 = (_x_x2456 + e_0); /*float64*/
          double err_0_0;
          double _x_x2457;
          double _x_x2458;
          {
            double _x_6_1_0 = z_0_0.num;
            _x_x2458 = _x_6_1_0; /*float64*/
          }
          _x_x2457 = (z_1_0 - _x_x2458); /*float64*/
          err_0_0 = (e_0 - _x_x2457); /*float64*/
          double _x_x2459;
          bool _match_x717 = isfinite(z_1_0); /*bool*/;
          if (_match_x717) {
            _x_x2459 = err_0_0; /*float64*/
          }
          else {
            _x_x2459 = z_1_0; /*float64*/
          }
          y_3_10459 = kk_std_num_ddouble__new_Ddouble(z_1_0, _x_x2459, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          double _x_x2460;
          {
            double _x_6_2_0 = z_0_0.num;
            _x_x2460 = _x_6_2_0; /*float64*/
          }
          y_3_10459 = kk_std_num_ddouble__new_Ddouble(_x_x2460, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
        }
        kk_std_core_types__order x_8_10460;
        kk_std_core_types__order _match_x716;
        double _x_x2461;
        {
          double _x_4_1 = x_7_10458.hi;
          _x_x2461 = _x_4_1; /*float64*/
        }
        double _x_x2462;
        {
          double _x_0_3_0 = y_3_10459.hi;
          _x_x2462 = _x_0_3_0; /*float64*/
        }
        _match_x716 = kk_std_num_float64_cmp(_x_x2461, _x_x2462, _ctx); /*order*/
        if (kk_std_core_types__is_Eq(_match_x716, _ctx)) {
          double _x_x2463;
          {
            double _x_1_2_0 = x_7_10458.lo;
            _x_x2463 = _x_1_2_0; /*float64*/
          }
          double _x_x2464;
          {
            double _x_2_1_0 = y_3_10459.lo;
            _x_x2464 = _x_2_1_0; /*float64*/
          }
          x_8_10460 = kk_std_num_float64_cmp(_x_x2463, _x_x2464, _ctx); /*order*/
        }
        else {
          x_8_10460 = _match_x716; /*order*/
        }
        kk_integer_t _brw_x714;
        if (kk_std_core_types__is_Lt(x_8_10460, _ctx)) {
          _brw_x714 = kk_integer_from_small(-1); /*int*/
          goto _match_x2465;
        }
        if (kk_std_core_types__is_Eq(x_8_10460, _ctx)) {
          _brw_x714 = kk_integer_from_small(0); /*int*/
          goto _match_x2465;
        }
        {
          _brw_x714 = kk_integer_from_small(1); /*int*/
        }
        _match_x2465: ;
        bool _brw_x715 = kk_integer_eq_borrow(_brw_x714,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
        kk_integer_drop(_brw_x714, _ctx);
        return _brw_x715;
      }
      {
        bool _match_x699 = kk_std_num_ddouble__lp__lt__rp_(diff, kk_std_num_ddouble_dd_min, _ctx); /*bool*/;
        if (_match_x699) {
          kk_std_num_ddouble__ddouble x_9_10462 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_two, diff, _ctx); /*std/num/ddouble/ddouble*/;
          double z_3;
          double _x_x2466;
          kk_std_num_ddouble__ddouble _match_x713;
          if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
            kk_box_t _box_x383 = epsilon._cons._Optional.value;
            kk_std_num_ddouble__ddouble _uniq_epsilon_8558_1_0 = kk_std_num_ddouble__ddouble_unbox(_box_x383, KK_BORROWED, _ctx);
            _match_x713 = _uniq_epsilon_8558_1_0; /*std/num/ddouble/ddouble*/
          }
          else {
            _match_x713 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_8 = _match_x713.hi;
            _x_x2466 = _x_8; /*float64*/
          }
          double _x_x2467;
          kk_std_num_ddouble__ddouble _x_x2468 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
          {
            double _x_0_4 = _x_x2468.hi;
            _x_x2467 = _x_0_4; /*float64*/
          }
          z_3 = (_x_x2466 * _x_x2467); /*float64*/
          double err_2;
          double _x_x2469;
          kk_std_num_ddouble__ddouble _match_x712;
          if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
            kk_box_t _box_x384 = epsilon._cons._Optional.value;
            kk_std_num_ddouble__ddouble _uniq_epsilon_8558_1_1 = kk_std_num_ddouble__ddouble_unbox(_box_x384, KK_BORROWED, _ctx);
            _match_x712 = _uniq_epsilon_8558_1_1; /*std/num/ddouble/ddouble*/
          }
          else {
            _match_x712 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_1_3 = _match_x712.hi;
            _x_x2469 = _x_1_3; /*float64*/
          }
          double _x_x2470;
          kk_std_num_ddouble__ddouble _x_x2471 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
          {
            double _x_0_0_2 = _x_x2471.hi;
            _x_x2470 = _x_0_0_2; /*float64*/
          }
          double _x_x2472 = (-z_3); /*float64*/
          err_2 = kk_std_num_float64_fmadd(_x_x2469, _x_x2470, _x_x2472, _ctx); /*float64*/
          kk_std_num_ddouble__edouble z_0_1 = kk_std_num_ddouble__new_Edouble(z_3, err_2, _ctx); /*std/num/ddouble/edouble*/;
          double e_1;
          double _x_x2473;
          {
            double _x_1_0_3 = z_0_1.err;
            _x_x2473 = _x_1_0_3; /*float64*/
          }
          double _x_x2474;
          double _x_x2475;
          double _x_x2476;
          kk_std_num_ddouble__ddouble _match_x711;
          if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
            kk_box_t _box_x385 = epsilon._cons._Optional.value;
            kk_std_num_ddouble__ddouble _uniq_epsilon_8558_1_2 = kk_std_num_ddouble__ddouble_unbox(_box_x385, KK_BORROWED, _ctx);
            _match_x711 = _uniq_epsilon_8558_1_2; /*std/num/ddouble/ddouble*/
          }
          else {
            _match_x711 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_2_2 = _match_x711.hi;
            _x_x2476 = _x_2_2; /*float64*/
          }
          double _x_x2477;
          kk_std_num_ddouble__ddouble _x_x2478 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
          {
            double _x_3_3 = _x_x2478.lo;
            _x_x2477 = _x_3_3; /*float64*/
          }
          _x_x2475 = (_x_x2476 * _x_x2477); /*float64*/
          double _x_x2479;
          double _x_x2480;
          kk_std_num_ddouble__ddouble _match_x710;
          if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
            kk_box_t _box_x386 = epsilon._cons._Optional.value;
            kk_std_num_ddouble__ddouble _uniq_epsilon_8558_1_3 = kk_std_num_ddouble__ddouble_unbox(_box_x386, KK_BORROWED, _ctx);
            kk_std_core_types__optional_drop(epsilon, _ctx);
            _match_x710 = _uniq_epsilon_8558_1_3; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_std_core_types__optional_drop(epsilon, _ctx);
            _match_x710 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_4_2 = _match_x710.lo;
            _x_x2480 = _x_4_2; /*float64*/
          }
          double _x_x2481;
          kk_std_num_ddouble__ddouble _x_x2482 = kk_std_num_ddouble_dd_min; /*std/num/ddouble/ddouble*/
          {
            double _x_5_1 = _x_x2482.hi;
            _x_x2481 = _x_5_1; /*float64*/
          }
          _x_x2479 = (_x_x2480 * _x_x2481); /*float64*/
          _x_x2474 = (_x_x2475 + _x_x2479); /*float64*/
          e_1 = (_x_x2473 + _x_x2474); /*float64*/
          bool b_10040_1;
          double _x_x2483;
          {
            double _x_6_4 = z_0_1.num;
            _x_x2483 = _x_6_4; /*float64*/
          }
          b_10040_1 = isfinite(_x_x2483); /*bool*/
          kk_std_num_ddouble__ddouble y_5_10463;
          if (b_10040_1) {
            double z_1_1;
            double _x_x2484;
            {
              double _x_6_0_1 = z_0_1.num;
              _x_x2484 = _x_6_0_1; /*float64*/
            }
            z_1_1 = (_x_x2484 + e_1); /*float64*/
            double err_0_1;
            double _x_x2485;
            double _x_x2486;
            {
              double _x_6_1_1 = z_0_1.num;
              _x_x2486 = _x_6_1_1; /*float64*/
            }
            _x_x2485 = (z_1_1 - _x_x2486); /*float64*/
            err_0_1 = (e_1 - _x_x2485); /*float64*/
            double _x_x2487;
            bool _match_x709 = isfinite(z_1_1); /*bool*/;
            if (_match_x709) {
              _x_x2487 = err_0_1; /*float64*/
            }
            else {
              _x_x2487 = z_1_1; /*float64*/
            }
            y_5_10463 = kk_std_num_ddouble__new_Ddouble(z_1_1, _x_x2487, _ctx); /*std/num/ddouble/ddouble*/
          }
          else {
            double _x_x2488;
            {
              double _x_6_2_1 = z_0_1.num;
              _x_x2488 = _x_6_2_1; /*float64*/
            }
            y_5_10463 = kk_std_num_ddouble__new_Ddouble(_x_x2488, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          }
          kk_std_core_types__order x_10_10464;
          kk_std_core_types__order _match_x708;
          double _x_x2489;
          {
            double _x_5_2 = x_9_10462.hi;
            _x_x2489 = _x_5_2; /*float64*/
          }
          double _x_x2490;
          {
            double _x_0_4_0 = y_5_10463.hi;
            _x_x2490 = _x_0_4_0; /*float64*/
          }
          _match_x708 = kk_std_num_float64_cmp(_x_x2489, _x_x2490, _ctx); /*order*/
          if (kk_std_core_types__is_Eq(_match_x708, _ctx)) {
            double _x_x2491;
            {
              double _x_1_3_0 = x_9_10462.lo;
              _x_x2491 = _x_1_3_0; /*float64*/
            }
            double _x_x2492;
            {
              double _x_2_2_0 = y_5_10463.lo;
              _x_x2492 = _x_2_2_0; /*float64*/
            }
            x_10_10464 = kk_std_num_float64_cmp(_x_x2491, _x_x2492, _ctx); /*order*/
          }
          else {
            x_10_10464 = _match_x708; /*order*/
          }
          kk_integer_t _brw_x706;
          if (kk_std_core_types__is_Lt(x_10_10464, _ctx)) {
            _brw_x706 = kk_integer_from_small(-1); /*int*/
            goto _match_x2493;
          }
          if (kk_std_core_types__is_Eq(x_10_10464, _ctx)) {
            _brw_x706 = kk_integer_from_small(0); /*int*/
            goto _match_x2493;
          }
          {
            _brw_x706 = kk_integer_from_small(1); /*int*/
          }
          _match_x2493: ;
          bool _brw_x707 = kk_integer_eq_borrow(_brw_x706,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
          kk_integer_drop(_brw_x706, _ctx);
          return _brw_x707;
        }
        {
          kk_std_num_ddouble__ddouble sum_0;
          kk_std_num_ddouble__ddouble _x_x2494 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x2495 = kk_std_num_ddouble_abs(y, _ctx); /*std/num/ddouble/ddouble*/
          sum_0 = kk_std_num_ddouble__lp__plus__rp_(_x_x2494, _x_x2495, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble x_11_10466;
          kk_std_num_ddouble__ddouble _x_x2496 = kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble_two, diff, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x2497;
          bool _match_x705 = kk_std_num_ddouble__lp__gt__rp_(sum_0, kk_std_num_ddouble_dd_max, _ctx); /*bool*/;
          if (_match_x705) {
            _x_x2497 = kk_std_num_ddouble_dd_max; /*std/num/ddouble/ddouble*/
          }
          else {
            _x_x2497 = sum_0; /*std/num/ddouble/ddouble*/
          }
          x_11_10466 = kk_std_num_ddouble__lp__fs__rp_(_x_x2496, _x_x2497, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_core_types__order x_12_10468;
          kk_std_core_types__order _match_x702;
          double _x_x2498;
          {
            double _x_6_5 = x_11_10466.hi;
            _x_x2498 = _x_6_5; /*float64*/
          }
          double _x_x2499;
          kk_std_num_ddouble__ddouble _match_x704;
          if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
            kk_box_t _box_x387 = epsilon._cons._Optional.value;
            kk_std_num_ddouble__ddouble _uniq_epsilon_8558_2_0 = kk_std_num_ddouble__ddouble_unbox(_box_x387, KK_BORROWED, _ctx);
            _match_x704 = _uniq_epsilon_8558_2_0; /*std/num/ddouble/ddouble*/
          }
          else {
            _match_x704 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_0_5 = _match_x704.hi;
            _x_x2499 = _x_0_5; /*float64*/
          }
          _match_x702 = kk_std_num_float64_cmp(_x_x2498, _x_x2499, _ctx); /*order*/
          if (kk_std_core_types__is_Eq(_match_x702, _ctx)) {
            double _x_x2500;
            {
              double _x_1_4 = x_11_10466.lo;
              _x_x2500 = _x_1_4; /*float64*/
            }
            double _x_x2501;
            kk_std_num_ddouble__ddouble _match_x703;
            if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
              kk_box_t _box_x388 = epsilon._cons._Optional.value;
              kk_std_num_ddouble__ddouble _uniq_epsilon_8558_3 = kk_std_num_ddouble__ddouble_unbox(_box_x388, KK_BORROWED, _ctx);
              kk_std_core_types__optional_drop(epsilon, _ctx);
              _match_x703 = _uniq_epsilon_8558_3; /*std/num/ddouble/ddouble*/
            }
            else {
              kk_std_core_types__optional_drop(epsilon, _ctx);
              _match_x703 = kk_std_num_ddouble_dd_epsilon8; /*std/num/ddouble/ddouble*/
            }
            {
              double _x_2_3 = _match_x703.lo;
              _x_x2501 = _x_2_3; /*float64*/
            }
            x_12_10468 = kk_std_num_float64_cmp(_x_x2500, _x_x2501, _ctx); /*order*/
          }
          else {
            kk_std_core_types__optional_drop(epsilon, _ctx);
            x_12_10468 = _match_x702; /*order*/
          }
          kk_integer_t _brw_x700;
          if (kk_std_core_types__is_Lt(x_12_10468, _ctx)) {
            _brw_x700 = kk_integer_from_small(-1); /*int*/
            goto _match_x2502;
          }
          if (kk_std_core_types__is_Eq(x_12_10468, _ctx)) {
            _brw_x700 = kk_integer_from_small(0); /*int*/
            goto _match_x2502;
          }
          {
            _brw_x700 = kk_integer_from_small(1); /*int*/
          }
          _match_x2502: ;
          bool _brw_x701 = kk_integer_eq_borrow(_brw_x700,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
          kk_integer_drop(_brw_x700, _ctx);
          return _brw_x701;
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
  bool _match_x695 = kk_std_num_ddouble__lp__lt__eq__rp_(xx, yy, _ctx); /*bool*/;
  if (_match_x695) {
    lo = xx; /*std/num/ddouble/ddouble*/
  }
  else {
    lo = yy; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble hi;
  bool _match_x694 = kk_std_num_ddouble__lp__gt__eq__rp_(xx, yy, _ctx); /*bool*/;
  if (_match_x694) {
    hi = xx; /*std/num/ddouble/ddouble*/
  }
  else {
    hi = yy; /*std/num/ddouble/ddouble*/
  }
  bool _match_x692;
  double _x_x2503;
  {
    double _x = hi.hi;
    _x_x2503 = _x; /*float64*/
  }
  _match_x692 = (_x_x2503 == (0x0p+0)); /*bool*/
  if (_match_x692) {
    return kk_std_num_ddouble_zero;
  }
  {
    kk_std_num_ddouble__ddouble z = kk_std_num_ddouble__lp__fs__rp_(lo, hi, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble y_0_10789;
    kk_std_num_ddouble__ddouble _x_x2504;
    kk_std_num_ddouble__ddouble _x_x2505 = kk_std_num_ddouble__lp__star__rp_(z, z, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2504 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2505, _ctx); /*std/num/ddouble/ddouble*/
    y_0_10789 = kk_std_num_ddouble_sqrt(_x_x2504, _ctx); /*std/num/ddouble/ddouble*/
    double z_0;
    double _x_x2506;
    {
      double _x_0 = hi.hi;
      _x_x2506 = _x_0; /*float64*/
    }
    double _x_x2507;
    {
      double _x_0_0 = y_0_10789.hi;
      _x_x2507 = _x_0_0; /*float64*/
    }
    z_0 = (_x_x2506 * _x_x2507); /*float64*/
    double err;
    double _x_x2508;
    {
      double _x_0_1 = hi.hi;
      _x_x2508 = _x_0_1; /*float64*/
    }
    double _x_x2509;
    {
      double _x_0_0_0 = y_0_10789.hi;
      _x_x2509 = _x_0_0_0; /*float64*/
    }
    double _x_x2510 = (-z_0); /*float64*/
    err = kk_std_num_float64_fmadd(_x_x2508, _x_x2509, _x_x2510, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0_0 = kk_std_num_ddouble__new_Edouble(z_0, err, _ctx); /*std/num/ddouble/edouble*/;
    double e;
    double _x_x2511;
    {
      double _x_1 = z_0_0.err;
      _x_x2511 = _x_1; /*float64*/
    }
    double _x_x2512;
    double _x_x2513;
    double _x_x2514;
    {
      double _x_2 = hi.hi;
      _x_x2514 = _x_2; /*float64*/
    }
    double _x_x2515;
    {
      double _x_3 = y_0_10789.lo;
      _x_x2515 = _x_3; /*float64*/
    }
    _x_x2513 = (_x_x2514 * _x_x2515); /*float64*/
    double _x_x2516;
    double _x_x2517;
    {
      double _x_4 = hi.lo;
      _x_x2517 = _x_4; /*float64*/
    }
    double _x_x2518;
    {
      double _x_5 = y_0_10789.hi;
      _x_x2518 = _x_5; /*float64*/
    }
    _x_x2516 = (_x_x2517 * _x_x2518); /*float64*/
    _x_x2512 = (_x_x2513 + _x_x2516); /*float64*/
    e = (_x_x2511 + _x_x2512); /*float64*/
    bool b_10040;
    double _x_x2519;
    {
      double _x_6 = z_0_0.num;
      _x_x2519 = _x_6; /*float64*/
    }
    b_10040 = isfinite(_x_x2519); /*bool*/
    if (b_10040) {
      double z_1;
      double _x_x2520;
      {
        double _x_6_0 = z_0_0.num;
        _x_x2520 = _x_6_0; /*float64*/
      }
      z_1 = (_x_x2520 + e); /*float64*/
      double err_0;
      double _x_x2521;
      double _x_x2522;
      {
        double _x_6_1 = z_0_0.num;
        _x_x2522 = _x_6_1; /*float64*/
      }
      _x_x2521 = (z_1 - _x_x2522); /*float64*/
      err_0 = (e - _x_x2521); /*float64*/
      double _x_x2523;
      bool _match_x693 = isfinite(z_1); /*bool*/;
      if (_match_x693) {
        _x_x2523 = err_0; /*float64*/
      }
      else {
        _x_x2523 = z_1; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(z_1, _x_x2523, _ctx);
    }
    {
      double _x_x2524;
      {
        double _x_6_2 = z_0_0.num;
        _x_x2524 = _x_6_2; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(_x_x2524, 0x0p+0, _ctx);
    }
  }
}
 
// The square root of the sum of the squares of three doubles.
// Prevents overflow for large numbers.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_xyz_fs_hypot(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_num_ddouble__ddouble z, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble, z : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble xx = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble yy = kk_std_num_ddouble_abs(y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble zz = kk_std_num_ddouble_abs(z, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble x_0_10477;
  bool _match_x691 = kk_std_num_ddouble__lp__gt__eq__rp_(xx, yy, _ctx); /*bool*/;
  if (_match_x691) {
    x_0_10477 = xx; /*std/num/ddouble/ddouble*/
  }
  else {
    x_0_10477 = yy; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble hi;
  bool _match_x690 = kk_std_num_ddouble__lp__gt__eq__rp_(x_0_10477, zz, _ctx); /*bool*/;
  if (_match_x690) {
    hi = x_0_10477; /*std/num/ddouble/ddouble*/
  }
  else {
    hi = zz; /*std/num/ddouble/ddouble*/
  }
  bool _match_x685;
  double _x_x2525;
  {
    double _x = hi.hi;
    _x_x2525 = _x; /*float64*/
  }
  _match_x685 = (_x_x2525 == (0x0p+0)); /*bool*/
  if (_match_x685) {
    return kk_std_num_ddouble_zero;
  }
  {
    kk_std_num_ddouble__ddouble x_3_10794 = kk_std_num_ddouble__lp__fs__rp_(zz, hi, _ctx); /*std/num/ddouble/ddouble*/;
    double z_4;
    double _x_x2526;
    {
      double _x_9 = x_3_10794.hi;
      _x_x2526 = _x_9; /*float64*/
    }
    double _x_x2527;
    {
      double _x_9_0 = x_3_10794.hi;
      _x_x2527 = _x_9_0; /*float64*/
    }
    z_4 = (_x_x2526 * _x_x2527); /*float64*/
    double err_3;
    double _x_x2528;
    {
      double _x_9_1 = x_3_10794.hi;
      _x_x2528 = _x_9_1; /*float64*/
    }
    double _x_x2529;
    {
      double _x_9_2 = x_3_10794.hi;
      _x_x2529 = _x_9_2; /*float64*/
    }
    double _x_x2530 = (-z_4); /*float64*/
    err_3 = kk_std_num_float64_fmadd(_x_x2528, _x_x2529, _x_x2530, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0_3 = kk_std_num_ddouble__new_Edouble(z_4, err_3, _ctx); /*std/num/ddouble/edouble*/;
    double e_2;
    double _x_x2531;
    double _x_x2532;
    {
      double _x_0_3 = z_0_3.err;
      _x_x2532 = _x_0_3; /*float64*/
    }
    double _x_x2533;
    double _x_x2534;
    double _x_x2535;
    {
      double _x_1_2 = x_3_10794.hi;
      _x_x2535 = _x_1_2; /*float64*/
    }
    _x_x2534 = (0x1p1 * _x_x2535); /*float64*/
    double _x_x2536;
    {
      double _x_2_2 = x_3_10794.lo;
      _x_x2536 = _x_2_2; /*float64*/
    }
    _x_x2533 = (_x_x2534 * _x_x2536); /*float64*/
    _x_x2531 = (_x_x2532 + _x_x2533); /*float64*/
    double _x_x2537;
    double _x_x2538;
    {
      double _x_3_2 = x_3_10794.lo;
      _x_x2538 = _x_3_2; /*float64*/
    }
    double _x_x2539;
    {
      double _x_4_2 = x_3_10794.lo;
      _x_x2539 = _x_4_2; /*float64*/
    }
    _x_x2537 = (_x_x2538 * _x_x2539); /*float64*/
    e_2 = (_x_x2531 + _x_x2537); /*float64*/
    bool b_10096_1;
    double _x_x2540;
    {
      double _x_5_2 = z_0_3.num;
      _x_x2540 = _x_5_2; /*float64*/
    }
    b_10096_1 = isfinite(_x_x2540); /*bool*/
    kk_std_num_ddouble__ddouble x_1_10792 = kk_std_num_ddouble__lp__fs__rp_(xx, hi, _ctx); /*std/num/ddouble/ddouble*/;
    double z_2;
    double _x_x2541;
    {
      double _x_7 = x_1_10792.hi;
      _x_x2541 = _x_7; /*float64*/
    }
    double _x_x2542;
    {
      double _x_7_0 = x_1_10792.hi;
      _x_x2542 = _x_7_0; /*float64*/
    }
    z_2 = (_x_x2541 * _x_x2542); /*float64*/
    double err_1;
    double _x_x2543;
    {
      double _x_7_1 = x_1_10792.hi;
      _x_x2543 = _x_7_1; /*float64*/
    }
    double _x_x2544;
    {
      double _x_7_2 = x_1_10792.hi;
      _x_x2544 = _x_7_2; /*float64*/
    }
    double _x_x2545 = (-z_2); /*float64*/
    err_1 = kk_std_num_float64_fmadd(_x_x2543, _x_x2544, _x_x2545, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0_1 = kk_std_num_ddouble__new_Edouble(z_2, err_1, _ctx); /*std/num/ddouble/edouble*/;
    double e_0;
    double _x_x2546;
    double _x_x2547;
    {
      double _x_0_1 = z_0_1.err;
      _x_x2547 = _x_0_1; /*float64*/
    }
    double _x_x2548;
    double _x_x2549;
    double _x_x2550;
    {
      double _x_1_0 = x_1_10792.hi;
      _x_x2550 = _x_1_0; /*float64*/
    }
    _x_x2549 = (0x1p1 * _x_x2550); /*float64*/
    double _x_x2551;
    {
      double _x_2_0 = x_1_10792.lo;
      _x_x2551 = _x_2_0; /*float64*/
    }
    _x_x2548 = (_x_x2549 * _x_x2551); /*float64*/
    _x_x2546 = (_x_x2547 + _x_x2548); /*float64*/
    double _x_x2552;
    double _x_x2553;
    {
      double _x_3_0 = x_1_10792.lo;
      _x_x2553 = _x_3_0; /*float64*/
    }
    double _x_x2554;
    {
      double _x_4_0 = x_1_10792.lo;
      _x_x2554 = _x_4_0; /*float64*/
    }
    _x_x2552 = (_x_x2553 * _x_x2554); /*float64*/
    e_0 = (_x_x2546 + _x_x2552); /*float64*/
    bool b_10096;
    double _x_x2555;
    {
      double _x_5_0 = z_0_1.num;
      _x_x2555 = _x_5_0; /*float64*/
    }
    b_10096 = isfinite(_x_x2555); /*bool*/
    kk_std_num_ddouble__ddouble x_2_10793 = kk_std_num_ddouble__lp__fs__rp_(yy, hi, _ctx); /*std/num/ddouble/ddouble*/;
    double z_3;
    double _x_x2556;
    {
      double _x_8 = x_2_10793.hi;
      _x_x2556 = _x_8; /*float64*/
    }
    double _x_x2557;
    {
      double _x_8_0 = x_2_10793.hi;
      _x_x2557 = _x_8_0; /*float64*/
    }
    z_3 = (_x_x2556 * _x_x2557); /*float64*/
    double err_2;
    double _x_x2558;
    {
      double _x_8_1 = x_2_10793.hi;
      _x_x2558 = _x_8_1; /*float64*/
    }
    double _x_x2559;
    {
      double _x_8_2 = x_2_10793.hi;
      _x_x2559 = _x_8_2; /*float64*/
    }
    double _x_x2560 = (-z_3); /*float64*/
    err_2 = kk_std_num_float64_fmadd(_x_x2558, _x_x2559, _x_x2560, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0_2 = kk_std_num_ddouble__new_Edouble(z_3, err_2, _ctx); /*std/num/ddouble/edouble*/;
    double e_1;
    double _x_x2561;
    double _x_x2562;
    {
      double _x_0_2 = z_0_2.err;
      _x_x2562 = _x_0_2; /*float64*/
    }
    double _x_x2563;
    double _x_x2564;
    double _x_x2565;
    {
      double _x_1_1 = x_2_10793.hi;
      _x_x2565 = _x_1_1; /*float64*/
    }
    _x_x2564 = (0x1p1 * _x_x2565); /*float64*/
    double _x_x2566;
    {
      double _x_2_1 = x_2_10793.lo;
      _x_x2566 = _x_2_1; /*float64*/
    }
    _x_x2563 = (_x_x2564 * _x_x2566); /*float64*/
    _x_x2561 = (_x_x2562 + _x_x2563); /*float64*/
    double _x_x2567;
    double _x_x2568;
    {
      double _x_3_1 = x_2_10793.lo;
      _x_x2568 = _x_3_1; /*float64*/
    }
    double _x_x2569;
    {
      double _x_4_1 = x_2_10793.lo;
      _x_x2569 = _x_4_1; /*float64*/
    }
    _x_x2567 = (_x_x2568 * _x_x2569); /*float64*/
    e_1 = (_x_x2561 + _x_x2567); /*float64*/
    bool b_10096_0;
    double _x_x2570;
    {
      double _x_5_1 = z_0_2.num;
      _x_x2570 = _x_5_1; /*float64*/
    }
    b_10096_0 = isfinite(_x_x2570); /*bool*/
    kk_std_num_ddouble__ddouble y_0_10791;
    kk_std_num_ddouble__ddouble _x_x2571;
    kk_std_num_ddouble__ddouble _x_x2572;
    kk_std_num_ddouble__ddouble _x_x2573;
    if (b_10096) {
      double z_1_0;
      double _x_x2574;
      {
        double _x_5_0_0 = z_0_1.num;
        _x_x2574 = _x_5_0_0; /*float64*/
      }
      z_1_0 = (_x_x2574 + e_0); /*float64*/
      double err_0_0;
      double _x_x2575;
      double _x_x2576;
      {
        double _x_5_0_1 = z_0_1.num;
        _x_x2576 = _x_5_0_1; /*float64*/
      }
      _x_x2575 = (z_1_0 - _x_x2576); /*float64*/
      err_0_0 = (e_0 - _x_x2575); /*float64*/
      double _x_x2577;
      bool _match_x689 = isfinite(z_1_0); /*bool*/;
      if (_match_x689) {
        _x_x2577 = err_0_0; /*float64*/
      }
      else {
        _x_x2577 = z_1_0; /*float64*/
      }
      _x_x2573 = kk_std_num_ddouble__new_Ddouble(z_1_0, _x_x2577, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double _x_x2578;
      {
        double _x_5_0_2 = z_0_1.num;
        _x_x2578 = _x_5_0_2; /*float64*/
      }
      _x_x2573 = kk_std_num_ddouble__new_Ddouble(_x_x2578, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble _x_x2579;
    if (b_10096_0) {
      double z_1_1;
      double _x_x2580;
      {
        double _x_5_1_0 = z_0_2.num;
        _x_x2580 = _x_5_1_0; /*float64*/
      }
      z_1_1 = (_x_x2580 + e_1); /*float64*/
      double err_0_1;
      double _x_x2581;
      double _x_x2582;
      {
        double _x_5_1_1 = z_0_2.num;
        _x_x2582 = _x_5_1_1; /*float64*/
      }
      _x_x2581 = (z_1_1 - _x_x2582); /*float64*/
      err_0_1 = (e_1 - _x_x2581); /*float64*/
      double _x_x2583;
      bool _match_x688 = isfinite(z_1_1); /*bool*/;
      if (_match_x688) {
        _x_x2583 = err_0_1; /*float64*/
      }
      else {
        _x_x2583 = z_1_1; /*float64*/
      }
      _x_x2579 = kk_std_num_ddouble__new_Ddouble(z_1_1, _x_x2583, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double _x_x2584;
      {
        double _x_5_1_2 = z_0_2.num;
        _x_x2584 = _x_5_1_2; /*float64*/
      }
      _x_x2579 = kk_std_num_ddouble__new_Ddouble(_x_x2584, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    }
    _x_x2572 = kk_std_num_ddouble__lp__plus__rp_(_x_x2573, _x_x2579, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x2585;
    if (b_10096_1) {
      double z_1_2;
      double _x_x2586;
      {
        double _x_5_2_0 = z_0_3.num;
        _x_x2586 = _x_5_2_0; /*float64*/
      }
      z_1_2 = (_x_x2586 + e_2); /*float64*/
      double err_0_2;
      double _x_x2587;
      double _x_x2588;
      {
        double _x_5_2_1 = z_0_3.num;
        _x_x2588 = _x_5_2_1; /*float64*/
      }
      _x_x2587 = (z_1_2 - _x_x2588); /*float64*/
      err_0_2 = (e_2 - _x_x2587); /*float64*/
      double _x_x2589;
      bool _match_x687 = isfinite(z_1_2); /*bool*/;
      if (_match_x687) {
        _x_x2589 = err_0_2; /*float64*/
      }
      else {
        _x_x2589 = z_1_2; /*float64*/
      }
      _x_x2585 = kk_std_num_ddouble__new_Ddouble(z_1_2, _x_x2589, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double _x_x2590;
      {
        double _x_5_2_2 = z_0_3.num;
        _x_x2590 = _x_5_2_2; /*float64*/
      }
      _x_x2585 = kk_std_num_ddouble__new_Ddouble(_x_x2590, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    }
    _x_x2571 = kk_std_num_ddouble__lp__plus__rp_(_x_x2572, _x_x2585, _ctx); /*std/num/ddouble/ddouble*/
    y_0_10791 = kk_std_num_ddouble_sqrt(_x_x2571, _ctx); /*std/num/ddouble/ddouble*/
    double z_0;
    double _x_x2591;
    {
      double _x_0 = hi.hi;
      _x_x2591 = _x_0; /*float64*/
    }
    double _x_x2592;
    {
      double _x_0_0 = y_0_10791.hi;
      _x_x2592 = _x_0_0; /*float64*/
    }
    z_0 = (_x_x2591 * _x_x2592); /*float64*/
    double err;
    double _x_x2593;
    {
      double _x_0_4 = hi.hi;
      _x_x2593 = _x_0_4; /*float64*/
    }
    double _x_x2594;
    {
      double _x_0_0_0 = y_0_10791.hi;
      _x_x2594 = _x_0_0_0; /*float64*/
    }
    double _x_x2595 = (-z_0); /*float64*/
    err = kk_std_num_float64_fmadd(_x_x2593, _x_x2594, _x_x2595, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0_0 = kk_std_num_ddouble__new_Edouble(z_0, err, _ctx); /*std/num/ddouble/edouble*/;
    double e;
    double _x_x2596;
    {
      double _x_1 = z_0_0.err;
      _x_x2596 = _x_1; /*float64*/
    }
    double _x_x2597;
    double _x_x2598;
    double _x_x2599;
    {
      double _x_2 = hi.hi;
      _x_x2599 = _x_2; /*float64*/
    }
    double _x_x2600;
    {
      double _x_3 = y_0_10791.lo;
      _x_x2600 = _x_3; /*float64*/
    }
    _x_x2598 = (_x_x2599 * _x_x2600); /*float64*/
    double _x_x2601;
    double _x_x2602;
    {
      double _x_4 = hi.lo;
      _x_x2602 = _x_4; /*float64*/
    }
    double _x_x2603;
    {
      double _x_5 = y_0_10791.hi;
      _x_x2603 = _x_5; /*float64*/
    }
    _x_x2601 = (_x_x2602 * _x_x2603); /*float64*/
    _x_x2597 = (_x_x2598 + _x_x2601); /*float64*/
    e = (_x_x2596 + _x_x2597); /*float64*/
    bool b_10040;
    double _x_x2604;
    {
      double _x_6 = z_0_0.num;
      _x_x2604 = _x_6; /*float64*/
    }
    b_10040 = isfinite(_x_x2604); /*bool*/
    if (b_10040) {
      double z_1;
      double _x_x2605;
      {
        double _x_6_0 = z_0_0.num;
        _x_x2605 = _x_6_0; /*float64*/
      }
      z_1 = (_x_x2605 + e); /*float64*/
      double err_0;
      double _x_x2606;
      double _x_x2607;
      {
        double _x_6_1 = z_0_0.num;
        _x_x2607 = _x_6_1; /*float64*/
      }
      _x_x2606 = (z_1 - _x_x2607); /*float64*/
      err_0 = (e - _x_x2606); /*float64*/
      double _x_x2608;
      bool _match_x686 = isfinite(z_1); /*bool*/;
      if (_match_x686) {
        _x_x2608 = err_0; /*float64*/
      }
      else {
        _x_x2608 = z_1; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(z_1, _x_x2608, _ctx);
    }
    {
      double _x_x2609;
      {
        double _x_6_2 = z_0_0.num;
        _x_x2609 = _x_6_2; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(_x_x2609, 0x0p+0, _ctx);
    }
  }
}
 
// lifted local: list/@lift-abs-max@11074, list/abs-max, @spec-x11014
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@11009, using:
// @uniq-f@11009 = fn(@uniq-x@11002: std/num/ddouble/ddouble, @uniq-y@11003: std/num/ddouble/ddouble){
//   val x@11005 : std/num/ddouble/ddouble;
//   val m@11006 : std/num/ddouble/ddouble;
//   val x@0@10486 : std/num/ddouble/ddouble;
//   match ((std/num/ddouble/(>=)(x@0@10486, m@11006))) {
//     ((std/core/types/True() : bool ) as @pat: bool)
//        -> x@0@10486;
//     ((@skip std/core/types/False() : bool ) as @pat@0: bool)
//        -> m@11006;
//   };
// }

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs__lift_abs_max_11075(kk_std_core_types__list _uniq_xs_11007, kk_std_num_ddouble__ddouble _uniq_z_11008, kk_context_t* _ctx) { /* (list<ddouble>, ddouble) -> ddouble */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_11007, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2610 = kk_std_core_types__as_Cons(_uniq_xs_11007, _ctx);
    kk_box_t _box_x389 = _con_x2610->head;
    kk_std_core_types__list _uniq_xx_11012 = _con_x2610->tail;
    kk_std_num_ddouble__ddouble _uniq_x_11011 = kk_std_num_ddouble__ddouble_unbox(_box_x389, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_11007, _ctx)) {
      kk_box_drop(_box_x389, _ctx);
      kk_datatype_ptr_free(_uniq_xs_11007, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_11012, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_11007, _ctx);
    }
    kk_std_num_ddouble__ddouble x_0_10486 = kk_std_num_ddouble_abs(_uniq_x_11011, _ctx); /*std/num/ddouble/ddouble*/;
    { // tailcall
      kk_std_num_ddouble__ddouble _x_x2611;
      bool _match_x683 = kk_std_num_ddouble__lp__gt__eq__rp_(x_0_10486, _uniq_z_11008, _ctx); /*bool*/;
      if (_match_x683) {
        _x_x2611 = x_0_10486; /*std/num/ddouble/ddouble*/
      }
      else {
        _x_x2611 = _uniq_z_11008; /*std/num/ddouble/ddouble*/
      }
      _uniq_xs_11007 = _uniq_xx_11012;
      _uniq_z_11008 = _x_x2611;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_11008;
  }
}
 
// lifted local: list/abs-max, @spec-x11004
// specialized: std/core/list/foldr, on parameters @uniq-f@10995, using:
// @uniq-f@10995 = fn(x: std/num/ddouble/ddouble, m: std/num/ddouble/ddouble){
//   val x@0@10486 : std/num/ddouble/ddouble
//         = std/num/ddouble/abs(x);
//   match ((std/num/ddouble/(>=)(x@0@10486, m))) {
//     ((std/core/types/True() : bool ) as @pat: bool)
//        -> x@0@10486;
//     ((@skip std/core/types/False() : bool ) as @pat@0: bool)
//        -> m;
//   };
// }

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs__lift_abs_max_11074(kk_std_core_types__list _uniq_xs_10993, kk_std_num_ddouble__ddouble _uniq_z_10994, kk_context_t* _ctx) { /* (list<ddouble>, ddouble) -> ddouble */ 
  kk_std_core_types__list _uniq_xs_0_10046_10999;
  if (kk_std_core_types__is_Nil(_uniq_xs_10993, _ctx)) {
    _uniq_xs_0_10046_10999 = kk_std_core_types__new_Nil(_ctx); /*list<std/num/ddouble/ddouble>*/
  }
  else {
    _uniq_xs_0_10046_10999 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_xs_10993, _ctx); /*list<std/num/ddouble/ddouble>*/
  }
  if (kk_std_core_types__is_Nil(_uniq_xs_0_10046_10999, _ctx)) {
    return _uniq_z_10994;
  }
  {
    return kk_std_num_ddouble_list_fs__lift_abs_max_11075(_uniq_xs_0_10046_10999, _uniq_z_10994, _ctx);
  }
}
 
// lifted local: list/@lift-hypot@11076, list/hypot, @spec-x11038
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@11033, using:
// @uniq-f@11033 = fn(@uniq-x@11026: std/num/ddouble/ddouble, @uniq-y@11027: std/num/ddouble/ddouble){
//   val x@11029 : std/num/ddouble/ddouble;
//   val m@11030 : std/num/ddouble/ddouble;
//   val x@0@10486 : std/num/ddouble/ddouble;
//   match ((std/num/ddouble/(>=)(x@0@10486, m@11030))) {
//     ((std/core/types/True() : bool ) as @pat: bool)
//        -> x@0@10486;
//     ((@skip std/core/types/False() : bool ) as @pat@0: bool)
//        -> m@11030;
//   };
// }

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs__lift_hypot_11077(kk_std_core_types__list _uniq_xs_11031, kk_std_num_ddouble__ddouble _uniq_z_11032, kk_context_t* _ctx) { /* (list<ddouble>, ddouble) -> ddouble */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_11031, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2612 = kk_std_core_types__as_Cons(_uniq_xs_11031, _ctx);
    kk_box_t _box_x390 = _con_x2612->head;
    kk_std_core_types__list _uniq_xx_11036 = _con_x2612->tail;
    kk_std_num_ddouble__ddouble _uniq_x_11035 = kk_std_num_ddouble__ddouble_unbox(_box_x390, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_11031, _ctx)) {
      kk_box_drop(_box_x390, _ctx);
      kk_datatype_ptr_free(_uniq_xs_11031, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_11036, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_11031, _ctx);
    }
    kk_std_num_ddouble__ddouble x_0_10486 = kk_std_num_ddouble_abs(_uniq_x_11035, _ctx); /*std/num/ddouble/ddouble*/;
    { // tailcall
      kk_std_num_ddouble__ddouble _x_x2613;
      bool _match_x682 = kk_std_num_ddouble__lp__gt__eq__rp_(x_0_10486, _uniq_z_11032, _ctx); /*bool*/;
      if (_match_x682) {
        _x_x2613 = x_0_10486; /*std/num/ddouble/ddouble*/
      }
      else {
        _x_x2613 = _uniq_z_11032; /*std/num/ddouble/ddouble*/
      }
      _uniq_xs_11031 = _uniq_xx_11036;
      _uniq_z_11032 = _x_x2613;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_11032;
  }
}
 
// lifted local: list/hypot, @spec-x11028
// specialized: std/core/list/foldr, on parameters @uniq-f@11019, using:
// @uniq-f@11019 = fn(x: std/num/ddouble/ddouble, m: std/num/ddouble/ddouble){
//   val x@0@10486 : std/num/ddouble/ddouble
//         = std/num/ddouble/abs(x);
//   match ((std/num/ddouble/(>=)(x@0@10486, m))) {
//     ((std/core/types/True() : bool ) as @pat: bool)
//        -> x@0@10486;
//     ((@skip std/core/types/False() : bool ) as @pat@0: bool)
//        -> m;
//   };
// }

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs__lift_hypot_11076(kk_std_core_types__list _uniq_xs_11017, kk_std_num_ddouble__ddouble _uniq_z_11018, kk_context_t* _ctx) { /* (list<ddouble>, ddouble) -> ddouble */ 
  kk_std_core_types__list _uniq_xs_0_10046_11023;
  if (kk_std_core_types__is_Nil(_uniq_xs_11017, _ctx)) {
    _uniq_xs_0_10046_11023 = kk_std_core_types__new_Nil(_ctx); /*list<std/num/ddouble/ddouble>*/
  }
  else {
    _uniq_xs_0_10046_11023 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_xs_11017, _ctx); /*list<std/num/ddouble/ddouble>*/
  }
  if (kk_std_core_types__is_Nil(_uniq_xs_0_10046_11023, _ctx)) {
    return _uniq_z_11018;
  }
  {
    return kk_std_num_ddouble_list_fs__lift_hypot_11077(_uniq_xs_0_10046_11023, _uniq_z_11018, _ctx);
  }
}
 
// lifted local: list/@lift-hypot@11078, list/hypot, @spec-x11052
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@11047, using:
// @uniq-f@11047 = fn(x@0@0: std/num/ddouble/ddouble){
//   val x@1@10798 : std/num/ddouble/ddouble;
//   val z@2 : float64;
//   val err@1 : float64;
//   val z@0@0 : std/num/ddouble/edouble;
//   val e@0 : float64;
//   val b@10096 : bool;
//   match (b@10096) {
//     ((std/core/types/True() : bool ) as @pat@6@0: bool)
//        -> val z@1@0 : float64;
//           val err@0@0 : float64;
//       std/num/ddouble/Ddouble(z@1@0, (match ((std/num/float64/is-finite(z@1@0))) {
//           ((std/core/types/True() : bool ) as @pat@1@0@1: bool)
//              -> err@0@0;
//           ((@skip std/core/types/False() : bool ) as @pat@2@0@1: bool)
//              -> z@1@0;
//         }));
//     ((@skip std/core/types/False() : bool ) as @pat@0@5@0: bool)
//        -> std/num/ddouble/Ddouble((match (z@0@0) {
//           ((@skip std/num/ddouble/Edouble((@x@5@0: float64) : float64, (@pat@0@7@0: float64) : float64) : std/num/ddouble/edouble ) as @pat@8@0: std/num/ddouble/edouble)
//              -> @x@5@0;
//         }), 0.0);
//   };
// }

kk_std_core_types__list kk_std_num_ddouble_list_fs__trmc_lift_hypot_11079(kk_std_num_ddouble__ddouble hi, kk_std_core_types__list _uniq_xs_11046, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (hi : ddouble, list<ddouble>, ctx<list<ddouble>>) -> list<ddouble> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_11046, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2614 = kk_std_core_types__as_Cons(_uniq_xs_11046, _ctx);
    kk_box_t _box_x391 = _con_x2614->head;
    kk_std_core_types__list _uniq_xx_11050 = _con_x2614->tail;
    kk_std_num_ddouble__ddouble _uniq_x_11049 = kk_std_num_ddouble__ddouble_unbox(_box_x391, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x1000 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_11046, _ctx)) {
      kk_box_drop(_box_x391, _ctx);
      _ru_x1000 = (kk_datatype_ptr_reuse(_uniq_xs_11046, _ctx));
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_11050, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_11046, _ctx);
    }
    kk_std_num_ddouble__ddouble x_1_10798 = kk_std_num_ddouble__lp__fs__rp_(_uniq_x_11049, hi, _ctx); /*std/num/ddouble/ddouble*/;
    double z_2;
    double _x_x2615;
    {
      double _x_7 = x_1_10798.hi;
      _x_x2615 = _x_7; /*float64*/
    }
    double _x_x2616;
    {
      double _x_7_0 = x_1_10798.hi;
      _x_x2616 = _x_7_0; /*float64*/
    }
    z_2 = (_x_x2615 * _x_x2616); /*float64*/
    double err_1;
    double _x_x2617;
    {
      double _x_7_1 = x_1_10798.hi;
      _x_x2617 = _x_7_1; /*float64*/
    }
    double _x_x2618;
    {
      double _x_7_2 = x_1_10798.hi;
      _x_x2618 = _x_7_2; /*float64*/
    }
    double _x_x2619 = (-z_2); /*float64*/
    err_1 = kk_std_num_float64_fmadd(_x_x2617, _x_x2618, _x_x2619, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0_0 = kk_std_num_ddouble__new_Edouble(z_2, err_1, _ctx); /*std/num/ddouble/edouble*/;
    double e_0;
    double _x_x2620;
    double _x_x2621;
    {
      double _x_0_1 = z_0_0.err;
      _x_x2621 = _x_0_1; /*float64*/
    }
    double _x_x2622;
    double _x_x2623;
    double _x_x2624;
    {
      double _x_1_0 = x_1_10798.hi;
      _x_x2624 = _x_1_0; /*float64*/
    }
    _x_x2623 = (0x1p1 * _x_x2624); /*float64*/
    double _x_x2625;
    {
      double _x_2_0 = x_1_10798.lo;
      _x_x2625 = _x_2_0; /*float64*/
    }
    _x_x2622 = (_x_x2623 * _x_x2625); /*float64*/
    _x_x2620 = (_x_x2621 + _x_x2622); /*float64*/
    double _x_x2626;
    double _x_x2627;
    {
      double _x_3_0 = x_1_10798.lo;
      _x_x2627 = _x_3_0; /*float64*/
    }
    double _x_x2628;
    {
      double _x_4_0 = x_1_10798.lo;
      _x_x2628 = _x_4_0; /*float64*/
    }
    _x_x2626 = (_x_x2627 * _x_x2628); /*float64*/
    e_0 = (_x_x2620 + _x_x2626); /*float64*/
    bool b_10096;
    double _x_x2629;
    {
      double _x_5_0 = z_0_0.num;
      _x_x2629 = _x_5_0; /*float64*/
    }
    b_10096 = isfinite(_x_x2629); /*bool*/
    kk_std_num_ddouble__ddouble _trmc_x11095;
    if (b_10096) {
      double z_1_0;
      double _x_x2630;
      {
        double _x_5_0_0 = z_0_0.num;
        _x_x2630 = _x_5_0_0; /*float64*/
      }
      z_1_0 = (_x_x2630 + e_0); /*float64*/
      double err_0_0;
      double _x_x2631;
      double _x_x2632;
      {
        double _x_5_0_1 = z_0_0.num;
        _x_x2632 = _x_5_0_1; /*float64*/
      }
      _x_x2631 = (z_1_0 - _x_x2632); /*float64*/
      err_0_0 = (e_0 - _x_x2631); /*float64*/
      double _x_x2633;
      bool _match_x681 = isfinite(z_1_0); /*bool*/;
      if (_match_x681) {
        _x_x2633 = err_0_0; /*float64*/
      }
      else {
        _x_x2633 = z_1_0; /*float64*/
      }
      _trmc_x11095 = kk_std_num_ddouble__new_Ddouble(z_1_0, _x_x2633, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double _x_x2634;
      {
        double _x_5_0_2 = z_0_0.num;
        _x_x2634 = _x_5_0_2; /*float64*/
      }
      _trmc_x11095 = kk_std_num_ddouble__new_Ddouble(_x_x2634, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_core_types__list _trmc_x11096 = kk_datatype_null(); /*list<std/num/ddouble/ddouble>*/;
    kk_std_core_types__list _trmc_x11097 = kk_std_core_types__new_Cons(_ru_x1000, 0, kk_std_num_ddouble__ddouble_box(_trmc_x11095, _ctx), _trmc_x11096, _ctx); /*list<std/num/ddouble/ddouble>*/;
    kk_field_addr_t _b_x401_406 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x11097, _ctx)->tail, _ctx); /*@field-addr<list<std/num/ddouble/ddouble>>*/;
    kk_std_core_types__cctx _brw_x679;
    kk_std_core_types__cctx _x_x2635 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<std/num/ddouble/ddouble>>*/
    _brw_x679 = kk_cctx_extend_linear(_x_x2635,(kk_std_core_types__list_box(_trmc_x11097, _ctx)),_b_x401_406,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x680 = kk_std_num_ddouble_list_fs__trmc_lift_hypot_11079(hi, _uniq_xx_11050, _brw_x679, _ctx); /*list<std/num/ddouble/ddouble>*/;
    kk_std_core_types__cctx_drop(_brw_x679, _ctx);
    return _brw_x680;
  }
  {
    kk_box_t _x_x2636;
    kk_std_core_types__cctx _x_x2637 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<std/num/ddouble/ddouble>>*/
    _x_x2636 = kk_cctx_apply_linear(_x_x2637,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2636, KK_OWNED, _ctx);
  }
}
 
// lifted local: list/@lift-hypot@11078, list/hypot, @spec-x11052
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@11047, using:
// @uniq-f@11047 = fn(x@0@0: std/num/ddouble/ddouble){
//   val x@1@10798 : std/num/ddouble/ddouble;
//   val z@2 : float64;
//   val err@1 : float64;
//   val z@0@0 : std/num/ddouble/edouble;
//   val e@0 : float64;
//   val b@10096 : bool;
//   match (b@10096) {
//     ((std/core/types/True() : bool ) as @pat@6@0: bool)
//        -> val z@1@0 : float64;
//           val err@0@0 : float64;
//       std/num/ddouble/Ddouble(z@1@0, (match ((std/num/float64/is-finite(z@1@0))) {
//           ((std/core/types/True() : bool ) as @pat@1@0@1: bool)
//              -> err@0@0;
//           ((@skip std/core/types/False() : bool ) as @pat@2@0@1: bool)
//              -> z@1@0;
//         }));
//     ((@skip std/core/types/False() : bool ) as @pat@0@5@0: bool)
//        -> std/num/ddouble/Ddouble((match (z@0@0) {
//           ((@skip std/num/ddouble/Edouble((@x@5@0: float64) : float64, (@pat@0@7@0: float64) : float64) : std/num/ddouble/edouble ) as @pat@8@0: std/num/ddouble/edouble)
//              -> @x@5@0;
//         }), 0.0);
//   };
// }

kk_std_core_types__list kk_std_num_ddouble_list_fs__lift_hypot_11079(kk_std_num_ddouble__ddouble hi_0, kk_std_core_types__list _uniq_xs_11046_0, kk_context_t* _ctx) { /* (hi : ddouble, list<ddouble>) -> list<ddouble> */ 
  kk_std_core_types__cctx _brw_x677 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x678 = kk_std_num_ddouble_list_fs__trmc_lift_hypot_11079(hi_0, _uniq_xs_11046_0, _brw_x677, _ctx); /*list<std/num/ddouble/ddouble>*/;
  kk_std_core_types__cctx_drop(_brw_x677, _ctx);
  return _brw_x678;
}
 
// lifted local: list/hypot, @spec-x11045
// specialized: std/core/list/map, on parameters @uniq-f@11042, using:
// @uniq-f@11042 = fn(x@0@0: std/num/ddouble/ddouble){
//   val x@1@10798 : std/num/ddouble/ddouble;
//   val z@2 : float64;
//   val err@1 : float64;
//   val z@0@0 : std/num/ddouble/edouble;
//   val e@0 : float64;
//   val b@10096 : bool;
//   match (b@10096) {
//     ((std/core/types/True() : bool ) as @pat@6@0: bool)
//        -> val z@1@0 : float64;
//           val err@0@0 : float64;
//       std/num/ddouble/Ddouble(z@1@0, (match ((std/num/float64/is-finite(z@1@0))) {
//           ((std/core/types/True() : bool ) as @pat@1@0@1: bool)
//              -> err@0@0;
//           ((@skip std/core/types/False() : bool ) as @pat@2@0@1: bool)
//              -> z@1@0;
//         }));
//     ((@skip std/core/types/False() : bool ) as @pat@0@5@0: bool)
//        -> std/num/ddouble/Ddouble((match (z@0@0) {
//           ((@skip std/num/ddouble/Edouble((@x@5@0: float64) : float64, (@pat@0@7@0: float64) : float64) : std/num/ddouble/edouble ) as @pat@8@0: std/num/ddouble/edouble)
//              -> @x@5@0;
//         }), 0.0);
//   };
// }

kk_std_core_types__list kk_std_num_ddouble_list_fs__lift_hypot_11078(kk_std_num_ddouble__ddouble hi, kk_std_core_types__list _uniq_xs_11041, kk_context_t* _ctx) { /* (hi : ddouble, list<ddouble>) -> list<ddouble> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_11041, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x675 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x676 = kk_std_num_ddouble_list_fs__trmc_lift_hypot_11079(hi, _uniq_xs_11041, _brw_x675, _ctx); /*list<std/num/ddouble/ddouble>*/;
    kk_std_core_types__cctx_drop(_brw_x675, _ctx);
    return _brw_x676;
  }
}
 
// The square root of the sum of squares of a list of doubles.
// Prevents overflow for large numbers and uses Kahan-Babu&scaron;kan-Neumaier summation
// for precision.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs_hypot(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<ddouble>) -> ddouble */ 
  kk_std_num_ddouble__ddouble hi;
  kk_std_core_types__list _x_x2638 = kk_std_core_types__list_dup(xs, _ctx); /*list<std/num/ddouble/ddouble>*/
  hi = kk_std_num_ddouble_list_fs__lift_hypot_11076(_x_x2638, kk_std_num_ddouble_zero, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_x673;
  double _x_x2639;
  {
    double _x = hi.hi;
    _x_x2639 = _x; /*float64*/
  }
  _match_x673 = (_x_x2639 == (0x0p+0)); /*bool*/
  if (_match_x673) {
    kk_std_core_types__list_drop(xs, _ctx);
    return kk_std_num_ddouble_zero;
  }
  {
    kk_std_core_types__list xs_0_11349 = kk_std_num_ddouble_list_fs__lift_hypot_11078(hi, xs, _ctx); /*list<std/num/ddouble/ddouble>*/;
    kk_ref_t loc = kk_ref_alloc((kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx)),kk_context()); /*local-var<2804,std/num/ddouble/ddouble>*/;
    kk_ref_t loc_0 = kk_ref_alloc((kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx)),kk_context()); /*local-var<2804,std/num/ddouble/ddouble>*/;
    kk_unit_t ___0 = kk_Unit;
    kk_ref_t _x_x2640 = kk_ref_dup(loc_0, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
    kk_ref_t _x_x2641 = kk_ref_dup(loc, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
    kk_std_num_ddouble_list_fs__lift_sum_11070(_x_x2640, _x_x2641, xs_0_11349, _ctx);
    kk_std_num_ddouble__ddouble res_0;
    kk_std_num_ddouble__ddouble _x_x2642;
    kk_box_t _x_x2643;
    kk_ref_t _x_x2644 = kk_ref_dup(loc, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
    _x_x2643 = kk_ref_get(_x_x2644,kk_context()); /*10000*/
    _x_x2642 = kk_std_num_ddouble__ddouble_unbox(_x_x2643, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x2645;
    kk_box_t _x_x2646;
    kk_ref_t _x_x2647 = kk_ref_dup(loc_0, _ctx); /*local-var<2804,std/num/ddouble/ddouble>*/
    _x_x2646 = kk_ref_get(_x_x2647,kk_context()); /*10000*/
    _x_x2645 = kk_std_num_ddouble__ddouble_unbox(_x_x2646, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    res_0 = kk_std_num_ddouble__lp__plus__rp_(_x_x2642, _x_x2645, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble res;
    kk_box_t _x_x2648 = kk_std_core_hnd_prompt_local_var(loc_0, kk_std_num_ddouble__ddouble_box(res_0, _ctx), _ctx); /*10001*/
    res = kk_std_num_ddouble__ddouble_unbox(_x_x2648, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble y_10797;
    kk_std_num_ddouble__ddouble _x_x2649;
    kk_box_t _x_x2650 = kk_std_core_hnd_prompt_local_var(loc, kk_std_num_ddouble__ddouble_box(res, _ctx), _ctx); /*10001*/
    _x_x2649 = kk_std_num_ddouble__ddouble_unbox(_x_x2650, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    y_10797 = kk_std_num_ddouble_sqrt(_x_x2649, _ctx); /*std/num/ddouble/ddouble*/
    double z;
    double _x_x2651;
    {
      double _x_0 = hi.hi;
      _x_x2651 = _x_0; /*float64*/
    }
    double _x_x2652;
    {
      double _x_0_0 = y_10797.hi;
      _x_x2652 = _x_0_0; /*float64*/
    }
    z = (_x_x2651 * _x_x2652); /*float64*/
    double err;
    double _x_x2653;
    {
      double _x_0_2 = hi.hi;
      _x_x2653 = _x_0_2; /*float64*/
    }
    double _x_x2654;
    {
      double _x_0_0_0 = y_10797.hi;
      _x_x2654 = _x_0_0_0; /*float64*/
    }
    double _x_x2655 = (-z); /*float64*/
    err = kk_std_num_float64_fmadd(_x_x2653, _x_x2654, _x_x2655, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
    double e;
    double _x_x2656;
    {
      double _x_1 = z_0.err;
      _x_x2656 = _x_1; /*float64*/
    }
    double _x_x2657;
    double _x_x2658;
    double _x_x2659;
    {
      double _x_2 = hi.hi;
      _x_x2659 = _x_2; /*float64*/
    }
    double _x_x2660;
    {
      double _x_3 = y_10797.lo;
      _x_x2660 = _x_3; /*float64*/
    }
    _x_x2658 = (_x_x2659 * _x_x2660); /*float64*/
    double _x_x2661;
    double _x_x2662;
    {
      double _x_4 = hi.lo;
      _x_x2662 = _x_4; /*float64*/
    }
    double _x_x2663;
    {
      double _x_5 = y_10797.hi;
      _x_x2663 = _x_5; /*float64*/
    }
    _x_x2661 = (_x_x2662 * _x_x2663); /*float64*/
    _x_x2657 = (_x_x2658 + _x_x2661); /*float64*/
    e = (_x_x2656 + _x_x2657); /*float64*/
    bool b_10040;
    double _x_x2664;
    {
      double _x_6 = z_0.num;
      _x_x2664 = _x_6; /*float64*/
    }
    b_10040 = isfinite(_x_x2664); /*bool*/
    if (b_10040) {
      double z_1;
      double _x_x2665;
      {
        double _x_6_0 = z_0.num;
        _x_x2665 = _x_6_0; /*float64*/
      }
      z_1 = (_x_x2665 + e); /*float64*/
      double err_0;
      double _x_x2666;
      double _x_x2667;
      {
        double _x_6_1 = z_0.num;
        _x_x2667 = _x_6_1; /*float64*/
      }
      _x_x2666 = (z_1 - _x_x2667); /*float64*/
      err_0 = (e - _x_x2666); /*float64*/
      double _x_x2668;
      bool _match_x674 = isfinite(z_1); /*bool*/;
      if (_match_x674) {
        _x_x2668 = err_0; /*float64*/
      }
      else {
        _x_x2668 = z_1; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(z_1, _x_x2668, _ctx);
    }
    {
      double _x_x2669;
      {
        double _x_6_2 = z_0.num;
        _x_x2669 = _x_6_2; /*float64*/
      }
      return kk_std_num_ddouble__new_Ddouble(_x_x2669, 0x0p+0, _ctx);
    }
  }
}

kk_std_core_types__list kk_std_num_ddouble_ch_factors;

kk_vector_t kk_std_num_ddouble_sin16_table;
 
// lifted local: @lift-sincos@11080, sincos, @spec-x11067
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@11062, using:
// @uniq-f@11062 = fn(acc: std/num/ddouble/ddouble, f: std/num/ddouble/ddouble){
//   std/num/ddouble/(+)(f, (std/num/ddouble/(*)(acc, s2)));
// }

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lift_sincos_11081(kk_std_num_ddouble__ddouble s2, kk_std_core_types__list _uniq_xs_11060, kk_std_num_ddouble__ddouble _uniq_z_11061, kk_context_t* _ctx) { /* (s2 : ddouble, list<ddouble>, ddouble) -> ddouble */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_11060, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2706 = kk_std_core_types__as_Cons(_uniq_xs_11060, _ctx);
    kk_box_t _box_x497 = _con_x2706->head;
    kk_std_core_types__list _uniq_xx_11065 = _con_x2706->tail;
    kk_std_num_ddouble__ddouble _uniq_x_11064 = kk_std_num_ddouble__ddouble_unbox(_box_x497, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_11060, _ctx)) {
      kk_box_drop(_box_x497, _ctx);
      kk_datatype_ptr_free(_uniq_xs_11060, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_11065, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_11060, _ctx);
    }
    kk_std_num_ddouble__ddouble _uniq_z_11061_0_11092;
    kk_std_num_ddouble__ddouble _x_x2707 = kk_std_num_ddouble__lp__star__rp_(_uniq_z_11061, s2, _ctx); /*std/num/ddouble/ddouble*/
    _uniq_z_11061_0_11092 = kk_std_num_ddouble__lp__plus__rp_(_uniq_x_11064, _x_x2707, _ctx); /*std/num/ddouble/ddouble*/
    { // tailcall
      _uniq_xs_11060 = _uniq_xx_11065;
      _uniq_z_11061 = _uniq_z_11061_0_11092;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_11061;
  }
}
 
// lifted local: sincos, @spec-x11059
// specialized: std/core/list/foldl, on parameters @uniq-f@11056, using:
// @uniq-f@11056 = fn(acc: std/num/ddouble/ddouble, f: std/num/ddouble/ddouble){
//   std/num/ddouble/(+)(f, (std/num/ddouble/(*)(acc, s2)));
// }

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lift_sincos_11080(kk_std_num_ddouble__ddouble s2, kk_std_core_types__list _uniq_xs_11054, kk_std_num_ddouble__ddouble _uniq_z_11055, kk_context_t* _ctx) { /* (s2 : ddouble, list<ddouble>, ddouble) -> ddouble */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_11054, _ctx)) {
    return _uniq_z_11055;
  }
  {
    return kk_std_num_ddouble__lift_sincos_11081(s2, _uniq_xs_11054, _uniq_z_11055, _ctx);
  }
}
 
// Calculate sine and cosine on an angle in radians.

kk_std_core_types__tuple2 kk_std_num_ddouble_sincos(kk_std_num_ddouble__ddouble rad, kk_context_t* _ctx) { /* (rad : ddouble) -> (ddouble, ddouble) */ 
  bool _match_x617;
  double _x_x2708;
  double _x_x2709;
  {
    double _x = rad.hi;
    _x_x2709 = _x; /*float64*/
  }
  _x_x2708 = kk_double_abs(_x_x2709); /*float64*/
  _match_x617 = (_x_x2708 < (0x1.5fd7fe1796495p-37)); /*bool*/
  if (_match_x617) {
    kk_std_num_ddouble__ddouble y_10496;
    kk_std_num_ddouble__ddouble _x_x2710 = kk_std_num_ddouble_sqr(rad, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x2711 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(3), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    y_10496 = kk_std_num_ddouble__lp__fs__rp_(_x_x2710, _x_x2711, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble y_10800;
    kk_std_num_ddouble__ddouble _x_x2712;
    double _x_x2713;
    double _x_x2714;
    {
      double _x_7 = y_10496.hi;
      _x_x2714 = _x_7; /*float64*/
    }
    _x_x2713 = (-_x_x2714); /*float64*/
    double _x_x2715;
    double _x_x2716;
    {
      double _x_0_1 = y_10496.lo;
      _x_x2716 = _x_0_1; /*float64*/
    }
    _x_x2715 = (-_x_x2716); /*float64*/
    _x_x2712 = kk_std_num_ddouble__new_Ddouble(_x_x2713, _x_x2715, _ctx); /*std/num/ddouble/ddouble*/
    y_10800 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2712, _ctx); /*std/num/ddouble/ddouble*/
    double z;
    double _x_x2717;
    {
      double _x_0 = rad.hi;
      _x_x2717 = _x_0; /*float64*/
    }
    double _x_x2718;
    {
      double _x_0_0 = y_10800.hi;
      _x_x2718 = _x_0_0; /*float64*/
    }
    z = (_x_x2717 * _x_x2718); /*float64*/
    double err;
    double _x_x2719;
    {
      double _x_0_2 = rad.hi;
      _x_x2719 = _x_0_2; /*float64*/
    }
    double _x_x2720;
    {
      double _x_0_0_0 = y_10800.hi;
      _x_x2720 = _x_0_0_0; /*float64*/
    }
    double _x_x2721 = (-z); /*float64*/
    err = kk_std_num_float64_fmadd(_x_x2719, _x_x2720, _x_x2721, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
    double e;
    double _x_x2722;
    {
      double _x_1 = z_0.err;
      _x_x2722 = _x_1; /*float64*/
    }
    double _x_x2723;
    double _x_x2724;
    double _x_x2725;
    {
      double _x_2 = rad.hi;
      _x_x2725 = _x_2; /*float64*/
    }
    double _x_x2726;
    {
      double _x_3 = y_10800.lo;
      _x_x2726 = _x_3; /*float64*/
    }
    _x_x2724 = (_x_x2725 * _x_x2726); /*float64*/
    double _x_x2727;
    double _x_x2728;
    {
      double _x_4 = rad.lo;
      _x_x2728 = _x_4; /*float64*/
    }
    double _x_x2729;
    {
      double _x_5 = y_10800.hi;
      _x_x2729 = _x_5; /*float64*/
    }
    _x_x2727 = (_x_x2728 * _x_x2729); /*float64*/
    _x_x2723 = (_x_x2724 + _x_x2727); /*float64*/
    e = (_x_x2722 + _x_x2723); /*float64*/
    bool b_10040;
    double _x_x2730;
    {
      double _x_6 = z_0.num;
      _x_x2730 = _x_6; /*float64*/
    }
    b_10040 = isfinite(_x_x2730); /*bool*/
    kk_std_num_ddouble__ddouble s;
    if (b_10040) {
      double z_1;
      double _x_x2731;
      {
        double _x_6_0 = z_0.num;
        _x_x2731 = _x_6_0; /*float64*/
      }
      z_1 = (_x_x2731 + e); /*float64*/
      double err_0;
      double _x_x2732;
      double _x_x2733;
      {
        double _x_6_1 = z_0.num;
        _x_x2733 = _x_6_1; /*float64*/
      }
      _x_x2732 = (z_1 - _x_x2733); /*float64*/
      err_0 = (e - _x_x2732); /*float64*/
      double _x_x2734;
      bool _match_x671 = isfinite(z_1); /*bool*/;
      if (_match_x671) {
        _x_x2734 = err_0; /*float64*/
      }
      else {
        _x_x2734 = z_1; /*float64*/
      }
      s = kk_std_num_ddouble__new_Ddouble(z_1, _x_x2734, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double _x_x2735;
      {
        double _x_6_2 = z_0.num;
        _x_x2735 = _x_6_2; /*float64*/
      }
      s = kk_std_num_ddouble__new_Ddouble(_x_x2735, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble y_0_10499 = kk_std_num_ddouble_sqr(s, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble c;
    kk_std_num_ddouble__ddouble _x_x2736;
    kk_std_num_ddouble__ddouble _x_x2737;
    double _x_x2738;
    double _x_x2739;
    {
      double _x_8 = y_0_10499.hi;
      _x_x2739 = _x_8; /*float64*/
    }
    _x_x2738 = (-_x_x2739); /*float64*/
    double _x_x2740;
    double _x_x2741;
    {
      double _x_0_2_0 = y_0_10499.lo;
      _x_x2741 = _x_0_2_0; /*float64*/
    }
    _x_x2740 = (-_x_x2741); /*float64*/
    _x_x2737 = kk_std_num_ddouble__new_Ddouble(_x_x2738, _x_x2740, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2736 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2737, _ctx); /*std/num/ddouble/ddouble*/
    c = kk_std_num_ddouble_sqrt(_x_x2736, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(s, _ctx), kk_std_num_ddouble__ddouble_box(c, _ctx), _ctx);
  }
  {
    kk_std_num_ddouble__ddouble x1 = kk_std_num_ddouble__lp__fs__rp_(rad, kk_std_num_ddouble_dd_twopi, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble y_1_10501 = kk_std_num_ddouble_round(x1, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble x3;
    kk_std_num_ddouble__ddouble _x_x2742;
    double _x_x2743;
    double _x_x2744;
    {
      double _x_9 = y_1_10501.hi;
      _x_x2744 = _x_9; /*float64*/
    }
    _x_x2743 = (-_x_x2744); /*float64*/
    double _x_x2745;
    double _x_x2746;
    {
      double _x_0_3 = y_1_10501.lo;
      _x_x2746 = _x_0_3; /*float64*/
    }
    _x_x2745 = (-_x_x2746); /*float64*/
    _x_x2742 = kk_std_num_ddouble__new_Ddouble(_x_x2743, _x_x2745, _ctx); /*std/num/ddouble/ddouble*/
    x3 = kk_std_num_ddouble__lp__plus__rp_(x1, _x_x2742, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble x32 = kk_std_num_ddouble__lp__plus__rp_(x3, x3, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble x34 = kk_std_num_ddouble__lp__plus__rp_(x32, x32, _ctx); /*std/num/ddouble/ddouble*/;
    kk_integer_t a = kk_std_num_ddouble_int(x34, kk_std_core_types__new_None(_ctx), _ctx); /*int*/;
    kk_std_num_ddouble__ddouble y_2_10504;
    kk_integer_t _x_x2747 = kk_integer_dup(a, _ctx); /*int*/
    y_2_10504 = kk_std_num_ddouble_ddouble_int_exp(_x_x2747, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble x_3_10804 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(8), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble y_0_10805;
    kk_std_num_ddouble__ddouble _x_x2748;
    double _x_x2749;
    double _x_x2750;
    {
      double _x_11 = y_2_10504.hi;
      _x_x2750 = _x_11; /*float64*/
    }
    _x_x2749 = (-_x_x2750); /*float64*/
    double _x_x2751;
    double _x_x2752;
    {
      double _x_0_5 = y_2_10504.lo;
      _x_x2752 = _x_0_5; /*float64*/
    }
    _x_x2751 = (-_x_x2752); /*float64*/
    _x_x2748 = kk_std_num_ddouble__new_Ddouble(_x_x2749, _x_x2751, _ctx); /*std/num/ddouble/ddouble*/
    y_0_10805 = kk_std_num_ddouble__lp__plus__rp_(x34, _x_x2748, _ctx); /*std/num/ddouble/ddouble*/
    double z_2;
    double _x_x2753;
    {
      double _x_10 = x_3_10804.hi;
      _x_x2753 = _x_10; /*float64*/
    }
    double _x_x2754;
    {
      double _x_0_4 = y_0_10805.hi;
      _x_x2754 = _x_0_4; /*float64*/
    }
    z_2 = (_x_x2753 * _x_x2754); /*float64*/
    double err_1;
    double _x_x2755;
    {
      double _x_10_0 = x_3_10804.hi;
      _x_x2755 = _x_10_0; /*float64*/
    }
    double _x_x2756;
    {
      double _x_0_4_0 = y_0_10805.hi;
      _x_x2756 = _x_0_4_0; /*float64*/
    }
    double _x_x2757 = (-z_2); /*float64*/
    err_1 = kk_std_num_float64_fmadd(_x_x2755, _x_x2756, _x_x2757, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0_0 = kk_std_num_ddouble__new_Edouble(z_2, err_1, _ctx); /*std/num/ddouble/edouble*/;
    double e_0;
    double _x_x2758;
    {
      double _x_1_0 = z_0_0.err;
      _x_x2758 = _x_1_0; /*float64*/
    }
    double _x_x2759;
    double _x_x2760;
    double _x_x2761;
    {
      double _x_2_0 = x_3_10804.hi;
      _x_x2761 = _x_2_0; /*float64*/
    }
    double _x_x2762;
    {
      double _x_3_0 = y_0_10805.lo;
      _x_x2762 = _x_3_0; /*float64*/
    }
    _x_x2760 = (_x_x2761 * _x_x2762); /*float64*/
    double _x_x2763;
    double _x_x2764;
    {
      double _x_4_0 = x_3_10804.lo;
      _x_x2764 = _x_4_0; /*float64*/
    }
    double _x_x2765;
    {
      double _x_5_0 = y_0_10805.hi;
      _x_x2765 = _x_5_0; /*float64*/
    }
    _x_x2763 = (_x_x2764 * _x_x2765); /*float64*/
    _x_x2759 = (_x_x2760 + _x_x2763); /*float64*/
    e_0 = (_x_x2758 + _x_x2759); /*float64*/
    bool b_10040_0;
    double _x_x2766;
    {
      double _x_6_0_0 = z_0_0.num;
      _x_x2766 = _x_6_0_0; /*float64*/
    }
    b_10040_0 = isfinite(_x_x2766); /*bool*/
    kk_integer_t b;
    kk_std_num_ddouble__ddouble _x_x2767;
    if (b_10040_0) {
      double z_1_0;
      double _x_x2768;
      {
        double _x_6_0_1 = z_0_0.num;
        _x_x2768 = _x_6_0_1; /*float64*/
      }
      z_1_0 = (_x_x2768 + e_0); /*float64*/
      double err_0_0;
      double _x_x2769;
      double _x_x2770;
      {
        double _x_6_0_2 = z_0_0.num;
        _x_x2770 = _x_6_0_2; /*float64*/
      }
      _x_x2769 = (z_1_0 - _x_x2770); /*float64*/
      err_0_0 = (e_0 - _x_x2769); /*float64*/
      double _x_x2771;
      bool _match_x670 = isfinite(z_1_0); /*bool*/;
      if (_match_x670) {
        _x_x2771 = err_0_0; /*float64*/
      }
      else {
        _x_x2771 = z_1_0; /*float64*/
      }
      _x_x2767 = kk_std_num_ddouble__new_Ddouble(z_1_0, _x_x2771, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double _x_x2772;
      {
        double _x_6_0_3 = z_0_0.num;
        _x_x2772 = _x_6_0_3; /*float64*/
      }
      _x_x2767 = kk_std_num_ddouble__new_Ddouble(_x_x2772, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    }
    b = kk_std_num_ddouble_int(_x_x2767, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
    kk_integer_t x_4_10509;
    kk_integer_t _x_x2773 = kk_integer_dup(a, _ctx); /*int*/
    x_4_10509 = kk_integer_mul((kk_integer_from_small(8)),_x_x2773,kk_context()); /*int*/
    kk_integer_t i_2_10508;
    kk_integer_t _x_x2774 = kk_integer_dup(b, _ctx); /*int*/
    i_2_10508 = kk_integer_add(x_4_10509,_x_x2774,kk_context()); /*int*/
    kk_std_num_ddouble__ddouble y_3_10507;
    kk_std_num_ddouble__ddouble _x_x2775 = kk_std_num_ddouble_ddouble_int_exp(i_2_10508, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x2776 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(16), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    y_3_10507 = kk_std_num_ddouble__lp__fs__rp_(_x_x2775, _x_x2776, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble y_1_10808;
    kk_std_num_ddouble__ddouble _x_x2777;
    double _x_x2778;
    double _x_x2779;
    {
      double _x_13 = y_3_10507.hi;
      _x_x2779 = _x_13; /*float64*/
    }
    _x_x2778 = (-_x_x2779); /*float64*/
    double _x_x2780;
    double _x_x2781;
    {
      double _x_0_7 = y_3_10507.lo;
      _x_x2781 = _x_0_7; /*float64*/
    }
    _x_x2780 = (-_x_x2781); /*float64*/
    _x_x2777 = kk_std_num_ddouble__new_Ddouble(_x_x2778, _x_x2780, _ctx); /*std/num/ddouble/ddouble*/
    y_1_10808 = kk_std_num_ddouble__lp__plus__rp_(x32, _x_x2777, _ctx); /*std/num/ddouble/ddouble*/
    double z_3;
    double _x_x2782;
    kk_std_num_ddouble__ddouble _x_x2783 = kk_std_num_ddouble_dd_pi; /*std/num/ddouble/ddouble*/
    {
      double _x_12 = _x_x2783.hi;
      _x_x2782 = _x_12; /*float64*/
    }
    double _x_x2784;
    {
      double _x_0_6 = y_1_10808.hi;
      _x_x2784 = _x_0_6; /*float64*/
    }
    z_3 = (_x_x2782 * _x_x2784); /*float64*/
    double err_2;
    double _x_x2785;
    kk_std_num_ddouble__ddouble _x_x2786 = kk_std_num_ddouble_dd_pi; /*std/num/ddouble/ddouble*/
    {
      double _x_12_0 = _x_x2786.hi;
      _x_x2785 = _x_12_0; /*float64*/
    }
    double _x_x2787;
    {
      double _x_0_6_0 = y_1_10808.hi;
      _x_x2787 = _x_0_6_0; /*float64*/
    }
    double _x_x2788 = (-z_3); /*float64*/
    err_2 = kk_std_num_float64_fmadd(_x_x2785, _x_x2787, _x_x2788, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0_1 = kk_std_num_ddouble__new_Edouble(z_3, err_2, _ctx); /*std/num/ddouble/edouble*/;
    double e_1;
    double _x_x2789;
    {
      double _x_1_1 = z_0_1.err;
      _x_x2789 = _x_1_1; /*float64*/
    }
    double _x_x2790;
    double _x_x2791;
    double _x_x2792;
    kk_std_num_ddouble__ddouble _x_x2793 = kk_std_num_ddouble_dd_pi; /*std/num/ddouble/ddouble*/
    {
      double _x_2_1 = _x_x2793.hi;
      _x_x2792 = _x_2_1; /*float64*/
    }
    double _x_x2794;
    {
      double _x_3_1 = y_1_10808.lo;
      _x_x2794 = _x_3_1; /*float64*/
    }
    _x_x2791 = (_x_x2792 * _x_x2794); /*float64*/
    double _x_x2795;
    double _x_x2796;
    kk_std_num_ddouble__ddouble _x_x2797 = kk_std_num_ddouble_dd_pi; /*std/num/ddouble/ddouble*/
    {
      double _x_4_1 = _x_x2797.lo;
      _x_x2796 = _x_4_1; /*float64*/
    }
    double _x_x2798;
    {
      double _x_5_1 = y_1_10808.hi;
      _x_x2798 = _x_5_1; /*float64*/
    }
    _x_x2795 = (_x_x2796 * _x_x2798); /*float64*/
    _x_x2790 = (_x_x2791 + _x_x2795); /*float64*/
    e_1 = (_x_x2789 + _x_x2790); /*float64*/
    bool b_10040_1;
    double _x_x2799;
    {
      double _x_6_1_0 = z_0_1.num;
      _x_x2799 = _x_6_1_0; /*float64*/
    }
    b_10040_1 = isfinite(_x_x2799); /*bool*/
    kk_std_num_ddouble__ddouble s_0;
    if (b_10040_1) {
      double z_1_1;
      double _x_x2800;
      {
        double _x_6_1_1 = z_0_1.num;
        _x_x2800 = _x_6_1_1; /*float64*/
      }
      z_1_1 = (_x_x2800 + e_1); /*float64*/
      double err_0_1;
      double _x_x2801;
      double _x_x2802;
      {
        double _x_6_1_2 = z_0_1.num;
        _x_x2802 = _x_6_1_2; /*float64*/
      }
      _x_x2801 = (z_1_1 - _x_x2802); /*float64*/
      err_0_1 = (e_1 - _x_x2801); /*float64*/
      double _x_x2803;
      bool _match_x669 = isfinite(z_1_1); /*bool*/;
      if (_match_x669) {
        _x_x2803 = err_0_1; /*float64*/
      }
      else {
        _x_x2803 = z_1_1; /*float64*/
      }
      s_0 = kk_std_num_ddouble__new_Ddouble(z_1_1, _x_x2803, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double _x_x2804;
      {
        double _x_6_1_3 = z_0_1.num;
        _x_x2804 = _x_6_1_3; /*float64*/
      }
      s_0 = kk_std_num_ddouble__new_Ddouble(_x_x2804, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble s2 = kk_std_num_ddouble_sqr(s_0, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble y_2_10811;
    kk_std_core_types__list _x_x2805 = kk_std_core_types__list_dup(kk_std_num_ddouble_ch_factors, _ctx); /*list<std/num/ddouble/ddouble>*/
    y_2_10811 = kk_std_num_ddouble__lift_sincos_11080(s2, _x_x2805, kk_std_num_ddouble_zero, _ctx); /*std/num/ddouble/ddouble*/
    double z_4;
    double _x_x2806;
    {
      double _x_14 = s_0.hi;
      _x_x2806 = _x_14; /*float64*/
    }
    double _x_x2807;
    {
      double _x_0_8 = y_2_10811.hi;
      _x_x2807 = _x_0_8; /*float64*/
    }
    z_4 = (_x_x2806 * _x_x2807); /*float64*/
    double err_3;
    double _x_x2808;
    {
      double _x_14_0 = s_0.hi;
      _x_x2808 = _x_14_0; /*float64*/
    }
    double _x_x2809;
    {
      double _x_0_8_0 = y_2_10811.hi;
      _x_x2809 = _x_0_8_0; /*float64*/
    }
    double _x_x2810 = (-z_4); /*float64*/
    err_3 = kk_std_num_float64_fmadd(_x_x2808, _x_x2809, _x_x2810, _ctx); /*float64*/
    kk_std_num_ddouble__edouble z_0_2 = kk_std_num_ddouble__new_Edouble(z_4, err_3, _ctx); /*std/num/ddouble/edouble*/;
    double e_2;
    double _x_x2811;
    {
      double _x_1_2 = z_0_2.err;
      _x_x2811 = _x_1_2; /*float64*/
    }
    double _x_x2812;
    double _x_x2813;
    double _x_x2814;
    {
      double _x_2_2 = s_0.hi;
      _x_x2814 = _x_2_2; /*float64*/
    }
    double _x_x2815;
    {
      double _x_3_2 = y_2_10811.lo;
      _x_x2815 = _x_3_2; /*float64*/
    }
    _x_x2813 = (_x_x2814 * _x_x2815); /*float64*/
    double _x_x2816;
    double _x_x2817;
    {
      double _x_4_2 = s_0.lo;
      _x_x2817 = _x_4_2; /*float64*/
    }
    double _x_x2818;
    {
      double _x_5_2 = y_2_10811.hi;
      _x_x2818 = _x_5_2; /*float64*/
    }
    _x_x2816 = (_x_x2817 * _x_x2818); /*float64*/
    _x_x2812 = (_x_x2813 + _x_x2816); /*float64*/
    e_2 = (_x_x2811 + _x_x2812); /*float64*/
    bool b_10040_2;
    double _x_x2819;
    {
      double _x_6_2_0 = z_0_2.num;
      _x_x2819 = _x_6_2_0; /*float64*/
    }
    b_10040_2 = isfinite(_x_x2819); /*bool*/
    kk_std_num_ddouble__ddouble sins;
    if (b_10040_2) {
      double z_1_2;
      double _x_x2820;
      {
        double _x_6_2_1 = z_0_2.num;
        _x_x2820 = _x_6_2_1; /*float64*/
      }
      z_1_2 = (_x_x2820 + e_2); /*float64*/
      double err_0_2;
      double _x_x2821;
      double _x_x2822;
      {
        double _x_6_2_2 = z_0_2.num;
        _x_x2822 = _x_6_2_2; /*float64*/
      }
      _x_x2821 = (z_1_2 - _x_x2822); /*float64*/
      err_0_2 = (e_2 - _x_x2821); /*float64*/
      double _x_x2823;
      bool _match_x668 = isfinite(z_1_2); /*bool*/;
      if (_match_x668) {
        _x_x2823 = err_0_2; /*float64*/
      }
      else {
        _x_x2823 = z_1_2; /*float64*/
      }
      sins = kk_std_num_ddouble__new_Ddouble(z_1_2, _x_x2823, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double _x_x2824;
      {
        double _x_6_2_3 = z_0_2.num;
        _x_x2824 = _x_6_2_3; /*float64*/
      }
      sins = kk_std_num_ddouble__new_Ddouble(_x_x2824, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble y_5_10513 = kk_std_num_ddouble_sqr(sins, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble coss;
    kk_std_num_ddouble__ddouble _x_x2825;
    kk_std_num_ddouble__ddouble _x_x2826;
    double _x_x2827;
    double _x_x2828;
    {
      double _x_15 = y_5_10513.hi;
      _x_x2828 = _x_15; /*float64*/
    }
    _x_x2827 = (-_x_x2828); /*float64*/
    double _x_x2829;
    double _x_x2830;
    {
      double _x_0_9 = y_5_10513.lo;
      _x_x2830 = _x_0_9; /*float64*/
    }
    _x_x2829 = (-_x_x2830); /*float64*/
    _x_x2826 = kk_std_num_ddouble__new_Ddouble(_x_x2827, _x_x2829, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2825 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x2826, _ctx); /*std/num/ddouble/ddouble*/
    coss = kk_std_num_ddouble_sqrt(_x_x2825, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble sinb;
    bool _match_x664 = kk_integer_gte_borrow(b,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x664) {
      kk_std_core_types__maybe m_10515 = kk_std_core_vector_at(kk_std_num_ddouble_sin16_table, b, _ctx); /*maybe<std/num/ddouble/ddouble>*/;
      if (kk_std_core_types__is_Nothing(m_10515, _ctx)) {
        sinb = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x500 = m_10515._cons.Just.value;
        kk_std_num_ddouble__ddouble x_6_0 = kk_std_num_ddouble__ddouble_unbox(_box_x500, KK_BORROWED, _ctx);
        kk_std_core_types__maybe_drop(m_10515, _ctx);
        sinb = x_6_0; /*std/num/ddouble/ddouble*/
      }
    }
    else {
      kk_integer_t i_5_10518;
      kk_integer_t _x_x2831 = kk_integer_dup(b, _ctx); /*int*/
      i_5_10518 = kk_integer_neg(_x_x2831,kk_context()); /*int*/
      kk_std_core_types__maybe m_0_10519;
      kk_std_core_types__maybe _brw_x667 = kk_std_core_vector_at(kk_std_num_ddouble_sin16_table, i_5_10518, _ctx); /*maybe<10000>*/;
      kk_integer_drop(i_5_10518, _ctx);
      m_0_10519 = _brw_x667; /*maybe<std/num/ddouble/ddouble>*/
      double _x_x2832;
      double _x_x2833;
      kk_std_num_ddouble__ddouble _match_x666;
      if (kk_std_core_types__is_Nothing(m_0_10519, _ctx)) {
        _match_x666 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x501 = m_0_10519._cons.Just.value;
        kk_std_num_ddouble__ddouble x_8_0 = kk_std_num_ddouble__ddouble_unbox(_box_x501, KK_BORROWED, _ctx);
        _match_x666 = x_8_0; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_0_10 = _match_x666.hi;
        _x_x2833 = _x_0_10; /*float64*/
      }
      _x_x2832 = (-_x_x2833); /*float64*/
      double _x_x2834;
      double _x_x2835;
      kk_std_num_ddouble__ddouble _match_x665;
      if (kk_std_core_types__is_Nothing(m_0_10519, _ctx)) {
        _match_x665 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x502 = m_0_10519._cons.Just.value;
        kk_std_num_ddouble__ddouble x_8_0_0 = kk_std_num_ddouble__ddouble_unbox(_box_x502, KK_BORROWED, _ctx);
        kk_std_core_types__maybe_drop(m_0_10519, _ctx);
        _match_x665 = x_8_0_0; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_1_3 = _match_x665.lo;
        _x_x2835 = _x_1_3; /*float64*/
      }
      _x_x2834 = (-_x_x2835); /*float64*/
      sinb = kk_std_num_ddouble__new_Ddouble(_x_x2832, _x_x2834, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_integer_t y_6_10525 = kk_integer_abs(b,kk_context()); /*int*/;
    kk_integer_t i_6_10523 = kk_integer_sub((kk_integer_from_small(8)),y_6_10525,kk_context()); /*int*/;
    kk_std_core_types__maybe m_1_10526;
    kk_std_core_types__maybe _brw_x663 = kk_std_core_vector_at(kk_std_num_ddouble_sin16_table, i_6_10523, _ctx); /*maybe<10000>*/;
    kk_integer_drop(i_6_10523, _ctx);
    m_1_10526 = _brw_x663; /*maybe<std/num/ddouble/ddouble>*/
    bool _match_x618 = kk_integer_eq_borrow(a,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x618) {
      kk_integer_drop(a, _ctx);
      double z_5;
      double _x_x2836;
      {
        double _x_16 = coss.hi;
        _x_x2836 = _x_16; /*float64*/
      }
      double _x_x2837;
      kk_std_num_ddouble__ddouble _match_x662;
      if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
        _match_x662 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x503 = m_1_10526._cons.Just.value;
        kk_std_num_ddouble__ddouble x_9 = kk_std_num_ddouble__ddouble_unbox(_box_x503, KK_BORROWED, _ctx);
        _match_x662 = x_9; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_0_11 = _match_x662.hi;
        _x_x2837 = _x_0_11; /*float64*/
      }
      z_5 = (_x_x2836 * _x_x2837); /*float64*/
      double err_4;
      double _x_x2838;
      {
        double _x_1_4 = coss.hi;
        _x_x2838 = _x_1_4; /*float64*/
      }
      double _x_x2839;
      kk_std_num_ddouble__ddouble _match_x661;
      if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
        _match_x661 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x504 = m_1_10526._cons.Just.value;
        kk_std_num_ddouble__ddouble x_9_0 = kk_std_num_ddouble__ddouble_unbox(_box_x504, KK_BORROWED, _ctx);
        _match_x661 = x_9_0; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_0_0_1 = _match_x661.hi;
        _x_x2839 = _x_0_0_1; /*float64*/
      }
      double _x_x2840 = (-z_5); /*float64*/
      err_4 = kk_std_num_float64_fmadd(_x_x2838, _x_x2839, _x_x2840, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0_3 = kk_std_num_ddouble__new_Edouble(z_5, err_4, _ctx); /*std/num/ddouble/edouble*/;
      double e_3;
      double _x_x2841;
      {
        double _x_1_0_0 = z_0_3.err;
        _x_x2841 = _x_1_0_0; /*float64*/
      }
      double _x_x2842;
      double _x_x2843;
      double _x_x2844;
      {
        double _x_2_3 = coss.hi;
        _x_x2844 = _x_2_3; /*float64*/
      }
      double _x_x2845;
      kk_std_num_ddouble__ddouble _match_x660;
      if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
        _match_x660 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x505 = m_1_10526._cons.Just.value;
        kk_std_num_ddouble__ddouble x_9_1 = kk_std_num_ddouble__ddouble_unbox(_box_x505, KK_BORROWED, _ctx);
        _match_x660 = x_9_1; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_3_3 = _match_x660.lo;
        _x_x2845 = _x_3_3; /*float64*/
      }
      _x_x2843 = (_x_x2844 * _x_x2845); /*float64*/
      double _x_x2846;
      double _x_x2847;
      {
        double _x_4_3 = coss.lo;
        _x_x2847 = _x_4_3; /*float64*/
      }
      double _x_x2848;
      kk_std_num_ddouble__ddouble _match_x659;
      if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
        _match_x659 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x506 = m_1_10526._cons.Just.value;
        kk_std_num_ddouble__ddouble x_9_2 = kk_std_num_ddouble__ddouble_unbox(_box_x506, KK_BORROWED, _ctx);
        _match_x659 = x_9_2; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_5_3 = _match_x659.hi;
        _x_x2848 = _x_5_3; /*float64*/
      }
      _x_x2846 = (_x_x2847 * _x_x2848); /*float64*/
      _x_x2842 = (_x_x2843 + _x_x2846); /*float64*/
      e_3 = (_x_x2841 + _x_x2842); /*float64*/
      bool b_10040_3;
      double _x_x2849;
      {
        double _x_6_3 = z_0_3.num;
        _x_x2849 = _x_6_3; /*float64*/
      }
      b_10040_3 = isfinite(_x_x2849); /*bool*/
      kk_std_num_ddouble__ddouble x_11_10528;
      if (b_10040_3) {
        double z_1_3;
        double _x_x2850;
        {
          double _x_6_0_4 = z_0_3.num;
          _x_x2850 = _x_6_0_4; /*float64*/
        }
        z_1_3 = (_x_x2850 + e_3); /*float64*/
        double err_0_3;
        double _x_x2851;
        double _x_x2852;
        {
          double _x_6_1_4 = z_0_3.num;
          _x_x2852 = _x_6_1_4; /*float64*/
        }
        _x_x2851 = (z_1_3 - _x_x2852); /*float64*/
        err_0_3 = (e_3 - _x_x2851); /*float64*/
        double _x_x2853;
        bool _match_x658 = isfinite(z_1_3); /*bool*/;
        if (_match_x658) {
          _x_x2853 = err_0_3; /*float64*/
        }
        else {
          _x_x2853 = z_1_3; /*float64*/
        }
        x_11_10528 = kk_std_num_ddouble__new_Ddouble(z_1_3, _x_x2853, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double _x_x2854;
        {
          double _x_6_2_4 = z_0_3.num;
          _x_x2854 = _x_6_2_4; /*float64*/
        }
        x_11_10528 = kk_std_num_ddouble__new_Ddouble(_x_x2854, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble y_7_10529 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
      double z_6;
      double _x_x2855;
      {
        double _x_17 = sins.hi;
        _x_x2855 = _x_17; /*float64*/
      }
      double _x_x2856;
      kk_std_num_ddouble__ddouble _match_x657;
      if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
        _match_x657 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x507 = m_1_10526._cons.Just.value;
        kk_std_num_ddouble__ddouble x_9_0_0 = kk_std_num_ddouble__ddouble_unbox(_box_x507, KK_BORROWED, _ctx);
        _match_x657 = x_9_0_0; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_0_12 = _match_x657.hi;
        _x_x2856 = _x_0_12; /*float64*/
      }
      z_6 = (_x_x2855 * _x_x2856); /*float64*/
      double err_5;
      double _x_x2857;
      {
        double _x_1_5 = sins.hi;
        _x_x2857 = _x_1_5; /*float64*/
      }
      double _x_x2858;
      kk_std_num_ddouble__ddouble _match_x656;
      if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
        _match_x656 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x508 = m_1_10526._cons.Just.value;
        kk_std_num_ddouble__ddouble x_9_0_1 = kk_std_num_ddouble__ddouble_unbox(_box_x508, KK_BORROWED, _ctx);
        _match_x656 = x_9_0_1; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_0_0_2 = _match_x656.hi;
        _x_x2858 = _x_0_0_2; /*float64*/
      }
      double _x_x2859 = (-z_6); /*float64*/
      err_5 = kk_std_num_float64_fmadd(_x_x2857, _x_x2858, _x_x2859, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0_4 = kk_std_num_ddouble__new_Edouble(z_6, err_5, _ctx); /*std/num/ddouble/edouble*/;
      double e_4;
      double _x_x2860;
      {
        double _x_1_0_1 = z_0_4.err;
        _x_x2860 = _x_1_0_1; /*float64*/
      }
      double _x_x2861;
      double _x_x2862;
      double _x_x2863;
      {
        double _x_2_4 = sins.hi;
        _x_x2863 = _x_2_4; /*float64*/
      }
      double _x_x2864;
      kk_std_num_ddouble__ddouble _match_x655;
      if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
        _match_x655 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x509 = m_1_10526._cons.Just.value;
        kk_std_num_ddouble__ddouble x_9_0_2 = kk_std_num_ddouble__ddouble_unbox(_box_x509, KK_BORROWED, _ctx);
        _match_x655 = x_9_0_2; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_3_4 = _match_x655.lo;
        _x_x2864 = _x_3_4; /*float64*/
      }
      _x_x2862 = (_x_x2863 * _x_x2864); /*float64*/
      double _x_x2865;
      double _x_x2866;
      {
        double _x_4_4 = sins.lo;
        _x_x2866 = _x_4_4; /*float64*/
      }
      double _x_x2867;
      kk_std_num_ddouble__ddouble _match_x654;
      if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
        _match_x654 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x510 = m_1_10526._cons.Just.value;
        kk_std_num_ddouble__ddouble x_9_0_3 = kk_std_num_ddouble__ddouble_unbox(_box_x510, KK_BORROWED, _ctx);
        kk_std_core_types__maybe_drop(m_1_10526, _ctx);
        _match_x654 = x_9_0_3; /*std/num/ddouble/ddouble*/
      }
      {
        double _x_5_4 = _match_x654.hi;
        _x_x2867 = _x_5_4; /*float64*/
      }
      _x_x2865 = (_x_x2866 * _x_x2867); /*float64*/
      _x_x2861 = (_x_x2862 + _x_x2865); /*float64*/
      e_4 = (_x_x2860 + _x_x2861); /*float64*/
      bool b_10040_4;
      double _x_x2868;
      {
        double _x_6_4 = z_0_4.num;
        _x_x2868 = _x_6_4; /*float64*/
      }
      b_10040_4 = isfinite(_x_x2868); /*bool*/
      kk_std_num_ddouble__ddouble _b_x511_545;
      kk_std_num_ddouble__ddouble _x_x2869;
      if (b_10040_4) {
        double z_1_4;
        double _x_x2870;
        {
          double _x_6_0_5 = z_0_4.num;
          _x_x2870 = _x_6_0_5; /*float64*/
        }
        z_1_4 = (_x_x2870 + e_4); /*float64*/
        double err_0_4;
        double _x_x2871;
        double _x_x2872;
        {
          double _x_6_1_5 = z_0_4.num;
          _x_x2872 = _x_6_1_5; /*float64*/
        }
        _x_x2871 = (z_1_4 - _x_x2872); /*float64*/
        err_0_4 = (e_4 - _x_x2871); /*float64*/
        double _x_x2873;
        bool _match_x653 = isfinite(z_1_4); /*bool*/;
        if (_match_x653) {
          _x_x2873 = err_0_4; /*float64*/
        }
        else {
          _x_x2873 = z_1_4; /*float64*/
        }
        _x_x2869 = kk_std_num_ddouble__new_Ddouble(z_1_4, _x_x2873, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double _x_x2874;
        {
          double _x_6_2_5 = z_0_4.num;
          _x_x2874 = _x_6_2_5; /*float64*/
        }
        _x_x2869 = kk_std_num_ddouble__new_Ddouble(_x_x2874, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x_x2875 = kk_std_num_ddouble__lp__star__rp_(coss, sinb, _ctx); /*std/num/ddouble/ddouble*/
      _b_x511_545 = kk_std_num_ddouble__lp__plus__rp_(_x_x2869, _x_x2875, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _b_x512_546;
      kk_std_num_ddouble__ddouble _x_x2876;
      double _x_x2877;
      double _x_x2878;
      {
        double _x_16_0 = y_7_10529.hi;
        _x_x2878 = _x_16_0; /*float64*/
      }
      _x_x2877 = (-_x_x2878); /*float64*/
      double _x_x2879;
      double _x_x2880;
      {
        double _x_0_11_0 = y_7_10529.lo;
        _x_x2880 = _x_0_11_0; /*float64*/
      }
      _x_x2879 = (-_x_x2880); /*float64*/
      _x_x2876 = kk_std_num_ddouble__new_Ddouble(_x_x2877, _x_x2879, _ctx); /*std/num/ddouble/ddouble*/
      _b_x512_546 = kk_std_num_ddouble__lp__plus__rp_(x_11_10528, _x_x2876, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(_b_x511_545, _ctx), kk_std_num_ddouble__ddouble_box(_b_x512_546, _ctx), _ctx);
    }
    {
      bool _match_x619 = kk_integer_eq_borrow(a,(kk_integer_from_small(1)),kk_context()); /*bool*/;
      if (_match_x619) {
        kk_integer_drop(a, _ctx);
        double z_7;
        double _x_x2881;
        {
          double _x_18 = coss.hi;
          _x_x2881 = _x_18; /*float64*/
        }
        double _x_x2882;
        kk_std_num_ddouble__ddouble _match_x652;
        if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
          _match_x652 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_box_t _box_x513 = m_1_10526._cons.Just.value;
          kk_std_num_ddouble__ddouble x_9_1_0 = kk_std_num_ddouble__ddouble_unbox(_box_x513, KK_BORROWED, _ctx);
          _match_x652 = x_9_1_0; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_0_13 = _match_x652.hi;
          _x_x2882 = _x_0_13; /*float64*/
        }
        z_7 = (_x_x2881 * _x_x2882); /*float64*/
        double err_6;
        double _x_x2883;
        {
          double _x_1_6 = coss.hi;
          _x_x2883 = _x_1_6; /*float64*/
        }
        double _x_x2884;
        kk_std_num_ddouble__ddouble _match_x651;
        if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
          _match_x651 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_box_t _box_x514 = m_1_10526._cons.Just.value;
          kk_std_num_ddouble__ddouble x_9_1_1 = kk_std_num_ddouble__ddouble_unbox(_box_x514, KK_BORROWED, _ctx);
          _match_x651 = x_9_1_1; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_0_0_3 = _match_x651.hi;
          _x_x2884 = _x_0_0_3; /*float64*/
        }
        double _x_x2885 = (-z_7); /*float64*/
        err_6 = kk_std_num_float64_fmadd(_x_x2883, _x_x2884, _x_x2885, _ctx); /*float64*/
        kk_std_num_ddouble__edouble z_0_5 = kk_std_num_ddouble__new_Edouble(z_7, err_6, _ctx); /*std/num/ddouble/edouble*/;
        double e_5;
        double _x_x2886;
        {
          double _x_1_0_2 = z_0_5.err;
          _x_x2886 = _x_1_0_2; /*float64*/
        }
        double _x_x2887;
        double _x_x2888;
        double _x_x2889;
        {
          double _x_2_5 = coss.hi;
          _x_x2889 = _x_2_5; /*float64*/
        }
        double _x_x2890;
        kk_std_num_ddouble__ddouble _match_x650;
        if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
          _match_x650 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_box_t _box_x515 = m_1_10526._cons.Just.value;
          kk_std_num_ddouble__ddouble x_9_1_2 = kk_std_num_ddouble__ddouble_unbox(_box_x515, KK_BORROWED, _ctx);
          _match_x650 = x_9_1_2; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_3_5 = _match_x650.lo;
          _x_x2890 = _x_3_5; /*float64*/
        }
        _x_x2888 = (_x_x2889 * _x_x2890); /*float64*/
        double _x_x2891;
        double _x_x2892;
        {
          double _x_4_5 = coss.lo;
          _x_x2892 = _x_4_5; /*float64*/
        }
        double _x_x2893;
        kk_std_num_ddouble__ddouble _match_x649;
        if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
          _match_x649 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_box_t _box_x516 = m_1_10526._cons.Just.value;
          kk_std_num_ddouble__ddouble x_9_1_3 = kk_std_num_ddouble__ddouble_unbox(_box_x516, KK_BORROWED, _ctx);
          _match_x649 = x_9_1_3; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_5_5 = _match_x649.hi;
          _x_x2893 = _x_5_5; /*float64*/
        }
        _x_x2891 = (_x_x2892 * _x_x2893); /*float64*/
        _x_x2887 = (_x_x2888 + _x_x2891); /*float64*/
        e_5 = (_x_x2886 + _x_x2887); /*float64*/
        bool b_10040_5;
        double _x_x2894;
        {
          double _x_6_5 = z_0_5.num;
          _x_x2894 = _x_6_5; /*float64*/
        }
        b_10040_5 = isfinite(_x_x2894); /*bool*/
        kk_std_num_ddouble__ddouble x_12_10530;
        if (b_10040_5) {
          double z_1_5;
          double _x_x2895;
          {
            double _x_6_0_6 = z_0_5.num;
            _x_x2895 = _x_6_0_6; /*float64*/
          }
          z_1_5 = (_x_x2895 + e_5); /*float64*/
          double err_0_5;
          double _x_x2896;
          double _x_x2897;
          {
            double _x_6_1_6 = z_0_5.num;
            _x_x2897 = _x_6_1_6; /*float64*/
          }
          _x_x2896 = (z_1_5 - _x_x2897); /*float64*/
          err_0_5 = (e_5 - _x_x2896); /*float64*/
          double _x_x2898;
          bool _match_x648 = isfinite(z_1_5); /*bool*/;
          if (_match_x648) {
            _x_x2898 = err_0_5; /*float64*/
          }
          else {
            _x_x2898 = z_1_5; /*float64*/
          }
          x_12_10530 = kk_std_num_ddouble__new_Ddouble(z_1_5, _x_x2898, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          double _x_x2899;
          {
            double _x_6_2_6 = z_0_5.num;
            _x_x2899 = _x_6_2_6; /*float64*/
          }
          x_12_10530 = kk_std_num_ddouble__new_Ddouble(_x_x2899, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
        }
        kk_std_num_ddouble__ddouble y_8_10531 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble x_11_10814;
        double _x_x2900;
        double _x_x2901;
        {
          double _x_18_0 = coss.hi;
          _x_x2901 = _x_18_0; /*float64*/
        }
        _x_x2900 = (-_x_x2901); /*float64*/
        double _x_x2902;
        double _x_x2903;
        {
          double _x_0_13_0 = coss.lo;
          _x_x2903 = _x_0_13_0; /*float64*/
        }
        _x_x2902 = (-_x_x2903); /*float64*/
        x_11_10814 = kk_std_num_ddouble__new_Ddouble(_x_x2900, _x_x2902, _ctx); /*std/num/ddouble/ddouble*/
        double z_5_0;
        double _x_x2904;
        {
          double _x_17_0 = x_11_10814.hi;
          _x_x2904 = _x_17_0; /*float64*/
        }
        double _x_x2905;
        {
          double _x_0_12_0 = sinb.hi;
          _x_x2905 = _x_0_12_0; /*float64*/
        }
        z_5_0 = (_x_x2904 * _x_x2905); /*float64*/
        double err_4_0;
        double _x_x2906;
        {
          double _x_17_0_0 = x_11_10814.hi;
          _x_x2906 = _x_17_0_0; /*float64*/
        }
        double _x_x2907;
        {
          double _x_0_12_0_0 = sinb.hi;
          _x_x2907 = _x_0_12_0_0; /*float64*/
        }
        double _x_x2908 = (-z_5_0); /*float64*/
        err_4_0 = kk_std_num_float64_fmadd(_x_x2906, _x_x2907, _x_x2908, _ctx); /*float64*/
        kk_std_num_ddouble__edouble z_0_3_0 = kk_std_num_ddouble__new_Edouble(z_5_0, err_4_0, _ctx); /*std/num/ddouble/edouble*/;
        double e_3_0;
        double _x_x2909;
        {
          double _x_1_4_0 = z_0_3_0.err;
          _x_x2909 = _x_1_4_0; /*float64*/
        }
        double _x_x2910;
        double _x_x2911;
        double _x_x2912;
        {
          double _x_2_3_0 = x_11_10814.hi;
          _x_x2912 = _x_2_3_0; /*float64*/
        }
        double _x_x2913;
        {
          double _x_3_3_0 = sinb.lo;
          _x_x2913 = _x_3_3_0; /*float64*/
        }
        _x_x2911 = (_x_x2912 * _x_x2913); /*float64*/
        double _x_x2914;
        double _x_x2915;
        {
          double _x_4_3_0 = x_11_10814.lo;
          _x_x2915 = _x_4_3_0; /*float64*/
        }
        double _x_x2916;
        {
          double _x_5_3_0 = sinb.hi;
          _x_x2916 = _x_5_3_0; /*float64*/
        }
        _x_x2914 = (_x_x2915 * _x_x2916); /*float64*/
        _x_x2910 = (_x_x2911 + _x_x2914); /*float64*/
        e_3_0 = (_x_x2909 + _x_x2910); /*float64*/
        bool b_10040_3_0;
        double _x_x2917;
        {
          double _x_6_3_0 = z_0_3_0.num;
          _x_x2917 = _x_6_3_0; /*float64*/
        }
        b_10040_3_0 = isfinite(_x_x2917); /*bool*/
        kk_std_num_ddouble__ddouble x_13_10532;
        if (b_10040_3_0) {
          double z_1_3_0;
          double _x_x2918;
          {
            double _x_6_3_0_0 = z_0_3_0.num;
            _x_x2918 = _x_6_3_0_0; /*float64*/
          }
          z_1_3_0 = (_x_x2918 + e_3_0); /*float64*/
          double err_0_3_0;
          double _x_x2919;
          double _x_x2920;
          {
            double _x_6_3_1 = z_0_3_0.num;
            _x_x2920 = _x_6_3_1; /*float64*/
          }
          _x_x2919 = (z_1_3_0 - _x_x2920); /*float64*/
          err_0_3_0 = (e_3_0 - _x_x2919); /*float64*/
          double _x_x2921;
          bool _match_x647 = isfinite(z_1_3_0); /*bool*/;
          if (_match_x647) {
            _x_x2921 = err_0_3_0; /*float64*/
          }
          else {
            _x_x2921 = z_1_3_0; /*float64*/
          }
          x_13_10532 = kk_std_num_ddouble__new_Ddouble(z_1_3_0, _x_x2921, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          double _x_x2922;
          {
            double _x_6_3_2 = z_0_3_0.num;
            _x_x2922 = _x_6_3_2; /*float64*/
          }
          x_13_10532 = kk_std_num_ddouble__new_Ddouble(_x_x2922, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
        }
        double z_8;
        double _x_x2923;
        {
          double _x_19 = sins.hi;
          _x_x2923 = _x_19; /*float64*/
        }
        double _x_x2924;
        kk_std_num_ddouble__ddouble _match_x646;
        if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
          _match_x646 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_box_t _box_x517 = m_1_10526._cons.Just.value;
          kk_std_num_ddouble__ddouble x_9_2_0 = kk_std_num_ddouble__ddouble_unbox(_box_x517, KK_BORROWED, _ctx);
          _match_x646 = x_9_2_0; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_0_14 = _match_x646.hi;
          _x_x2924 = _x_0_14; /*float64*/
        }
        z_8 = (_x_x2923 * _x_x2924); /*float64*/
        double err_7;
        double _x_x2925;
        {
          double _x_1_7 = sins.hi;
          _x_x2925 = _x_1_7; /*float64*/
        }
        double _x_x2926;
        kk_std_num_ddouble__ddouble _match_x645;
        if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
          _match_x645 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_box_t _box_x518 = m_1_10526._cons.Just.value;
          kk_std_num_ddouble__ddouble x_9_2_1 = kk_std_num_ddouble__ddouble_unbox(_box_x518, KK_BORROWED, _ctx);
          _match_x645 = x_9_2_1; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_0_0_4 = _match_x645.hi;
          _x_x2926 = _x_0_0_4; /*float64*/
        }
        double _x_x2927 = (-z_8); /*float64*/
        err_7 = kk_std_num_float64_fmadd(_x_x2925, _x_x2926, _x_x2927, _ctx); /*float64*/
        kk_std_num_ddouble__edouble z_0_6 = kk_std_num_ddouble__new_Edouble(z_8, err_7, _ctx); /*std/num/ddouble/edouble*/;
        double e_6;
        double _x_x2928;
        {
          double _x_1_0_3 = z_0_6.err;
          _x_x2928 = _x_1_0_3; /*float64*/
        }
        double _x_x2929;
        double _x_x2930;
        double _x_x2931;
        {
          double _x_2_6 = sins.hi;
          _x_x2931 = _x_2_6; /*float64*/
        }
        double _x_x2932;
        kk_std_num_ddouble__ddouble _match_x644;
        if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
          _match_x644 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_box_t _box_x519 = m_1_10526._cons.Just.value;
          kk_std_num_ddouble__ddouble x_9_2_2 = kk_std_num_ddouble__ddouble_unbox(_box_x519, KK_BORROWED, _ctx);
          _match_x644 = x_9_2_2; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_3_6 = _match_x644.lo;
          _x_x2932 = _x_3_6; /*float64*/
        }
        _x_x2930 = (_x_x2931 * _x_x2932); /*float64*/
        double _x_x2933;
        double _x_x2934;
        {
          double _x_4_6 = sins.lo;
          _x_x2934 = _x_4_6; /*float64*/
        }
        double _x_x2935;
        kk_std_num_ddouble__ddouble _match_x643;
        if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
          _match_x643 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_box_t _box_x520 = m_1_10526._cons.Just.value;
          kk_std_num_ddouble__ddouble x_9_2_3 = kk_std_num_ddouble__ddouble_unbox(_box_x520, KK_BORROWED, _ctx);
          kk_std_core_types__maybe_drop(m_1_10526, _ctx);
          _match_x643 = x_9_2_3; /*std/num/ddouble/ddouble*/
        }
        {
          double _x_5_6 = _match_x643.hi;
          _x_x2935 = _x_5_6; /*float64*/
        }
        _x_x2933 = (_x_x2934 * _x_x2935); /*float64*/
        _x_x2929 = (_x_x2930 + _x_x2933); /*float64*/
        e_6 = (_x_x2928 + _x_x2929); /*float64*/
        bool b_10040_6;
        double _x_x2936;
        {
          double _x_6_6 = z_0_6.num;
          _x_x2936 = _x_6_6; /*float64*/
        }
        b_10040_6 = isfinite(_x_x2936); /*bool*/
        kk_std_num_ddouble__ddouble y_9_10533;
        if (b_10040_6) {
          double z_1_6;
          double _x_x2937;
          {
            double _x_6_0_7 = z_0_6.num;
            _x_x2937 = _x_6_0_7; /*float64*/
          }
          z_1_6 = (_x_x2937 + e_6); /*float64*/
          double err_0_6;
          double _x_x2938;
          double _x_x2939;
          {
            double _x_6_1_7 = z_0_6.num;
            _x_x2939 = _x_6_1_7; /*float64*/
          }
          _x_x2938 = (z_1_6 - _x_x2939); /*float64*/
          err_0_6 = (e_6 - _x_x2938); /*float64*/
          double _x_x2940;
          bool _match_x642 = isfinite(z_1_6); /*bool*/;
          if (_match_x642) {
            _x_x2940 = err_0_6; /*float64*/
          }
          else {
            _x_x2940 = z_1_6; /*float64*/
          }
          y_9_10533 = kk_std_num_ddouble__new_Ddouble(z_1_6, _x_x2940, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          double _x_x2941;
          {
            double _x_6_2_7 = z_0_6.num;
            _x_x2941 = _x_6_2_7; /*float64*/
          }
          y_9_10533 = kk_std_num_ddouble__new_Ddouble(_x_x2941, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
        }
        kk_std_num_ddouble__ddouble _b_x521_547;
        kk_std_num_ddouble__ddouble _x_x2942;
        double _x_x2943;
        double _x_x2944;
        {
          double _x_19_0 = y_8_10531.hi;
          _x_x2944 = _x_19_0; /*float64*/
        }
        _x_x2943 = (-_x_x2944); /*float64*/
        double _x_x2945;
        double _x_x2946;
        {
          double _x_0_14_0 = y_8_10531.lo;
          _x_x2946 = _x_0_14_0; /*float64*/
        }
        _x_x2945 = (-_x_x2946); /*float64*/
        _x_x2942 = kk_std_num_ddouble__new_Ddouble(_x_x2943, _x_x2945, _ctx); /*std/num/ddouble/ddouble*/
        _b_x521_547 = kk_std_num_ddouble__lp__plus__rp_(x_12_10530, _x_x2942, _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble _b_x522_548;
        kk_std_num_ddouble__ddouble _x_x2947;
        double _x_x2948;
        double _x_x2949;
        {
          double _x_20 = y_9_10533.hi;
          _x_x2949 = _x_20; /*float64*/
        }
        _x_x2948 = (-_x_x2949); /*float64*/
        double _x_x2950;
        double _x_x2951;
        {
          double _x_0_15 = y_9_10533.lo;
          _x_x2951 = _x_0_15; /*float64*/
        }
        _x_x2950 = (-_x_x2951); /*float64*/
        _x_x2947 = kk_std_num_ddouble__new_Ddouble(_x_x2948, _x_x2950, _ctx); /*std/num/ddouble/ddouble*/
        _b_x522_548 = kk_std_num_ddouble__lp__plus__rp_(x_13_10532, _x_x2947, _ctx); /*std/num/ddouble/ddouble*/
        return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(_b_x521_547, _ctx), kk_std_num_ddouble__ddouble_box(_b_x522_548, _ctx), _ctx);
      }
      {
        bool _match_x620;
        bool _brw_x641 = kk_integer_eq_borrow(a,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
        kk_integer_drop(a, _ctx);
        _match_x620 = _brw_x641; /*bool*/
        if (_match_x620) {
          kk_std_num_ddouble__ddouble x_14_10534 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
          double z_9;
          double _x_x2952;
          {
            double _x_21 = coss.hi;
            _x_x2952 = _x_21; /*float64*/
          }
          double _x_x2953;
          kk_std_num_ddouble__ddouble _match_x640;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x640 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x523 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_3 = kk_std_num_ddouble__ddouble_unbox(_box_x523, KK_BORROWED, _ctx);
            _match_x640 = x_9_3; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_0_16 = _match_x640.hi;
            _x_x2953 = _x_0_16; /*float64*/
          }
          z_9 = (_x_x2952 * _x_x2953); /*float64*/
          double err_8;
          double _x_x2954;
          {
            double _x_1_8 = coss.hi;
            _x_x2954 = _x_1_8; /*float64*/
          }
          double _x_x2955;
          kk_std_num_ddouble__ddouble _match_x639;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x639 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x524 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_3_0 = kk_std_num_ddouble__ddouble_unbox(_box_x524, KK_BORROWED, _ctx);
            _match_x639 = x_9_3_0; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_0_0_5 = _match_x639.hi;
            _x_x2955 = _x_0_0_5; /*float64*/
          }
          double _x_x2956 = (-z_9); /*float64*/
          err_8 = kk_std_num_float64_fmadd(_x_x2954, _x_x2955, _x_x2956, _ctx); /*float64*/
          kk_std_num_ddouble__edouble z_0_7 = kk_std_num_ddouble__new_Edouble(z_9, err_8, _ctx); /*std/num/ddouble/edouble*/;
          double e_7;
          double _x_x2957;
          {
            double _x_1_0_4 = z_0_7.err;
            _x_x2957 = _x_1_0_4; /*float64*/
          }
          double _x_x2958;
          double _x_x2959;
          double _x_x2960;
          {
            double _x_2_7 = coss.hi;
            _x_x2960 = _x_2_7; /*float64*/
          }
          double _x_x2961;
          kk_std_num_ddouble__ddouble _match_x638;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x638 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x525 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_3_1 = kk_std_num_ddouble__ddouble_unbox(_box_x525, KK_BORROWED, _ctx);
            _match_x638 = x_9_3_1; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_3_7 = _match_x638.lo;
            _x_x2961 = _x_3_7; /*float64*/
          }
          _x_x2959 = (_x_x2960 * _x_x2961); /*float64*/
          double _x_x2962;
          double _x_x2963;
          {
            double _x_4_7 = coss.lo;
            _x_x2963 = _x_4_7; /*float64*/
          }
          double _x_x2964;
          kk_std_num_ddouble__ddouble _match_x637;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x637 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x526 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_3_2 = kk_std_num_ddouble__ddouble_unbox(_box_x526, KK_BORROWED, _ctx);
            _match_x637 = x_9_3_2; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_5_7 = _match_x637.hi;
            _x_x2964 = _x_5_7; /*float64*/
          }
          _x_x2962 = (_x_x2963 * _x_x2964); /*float64*/
          _x_x2958 = (_x_x2959 + _x_x2962); /*float64*/
          e_7 = (_x_x2957 + _x_x2958); /*float64*/
          bool b_10040_7;
          double _x_x2965;
          {
            double _x_6_7 = z_0_7.num;
            _x_x2965 = _x_6_7; /*float64*/
          }
          b_10040_7 = isfinite(_x_x2965); /*bool*/
          kk_std_num_ddouble__ddouble y_10_10535;
          if (b_10040_7) {
            double z_1_7;
            double _x_x2966;
            {
              double _x_6_0_8 = z_0_7.num;
              _x_x2966 = _x_6_0_8; /*float64*/
            }
            z_1_7 = (_x_x2966 + e_7); /*float64*/
            double err_0_7;
            double _x_x2967;
            double _x_x2968;
            {
              double _x_6_1_8 = z_0_7.num;
              _x_x2968 = _x_6_1_8; /*float64*/
            }
            _x_x2967 = (z_1_7 - _x_x2968); /*float64*/
            err_0_7 = (e_7 - _x_x2967); /*float64*/
            double _x_x2969;
            bool _match_x636 = isfinite(z_1_7); /*bool*/;
            if (_match_x636) {
              _x_x2969 = err_0_7; /*float64*/
            }
            else {
              _x_x2969 = z_1_7; /*float64*/
            }
            y_10_10535 = kk_std_num_ddouble__new_Ddouble(z_1_7, _x_x2969, _ctx); /*std/num/ddouble/ddouble*/
          }
          else {
            double _x_x2970;
            {
              double _x_6_2_8 = z_0_7.num;
              _x_x2970 = _x_6_2_8; /*float64*/
            }
            y_10_10535 = kk_std_num_ddouble__new_Ddouble(_x_x2970, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          }
          double z_10;
          double _x_x2971;
          {
            double _x_22 = sins.hi;
            _x_x2971 = _x_22; /*float64*/
          }
          double _x_x2972;
          kk_std_num_ddouble__ddouble _match_x635;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x635 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x527 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_4 = kk_std_num_ddouble__ddouble_unbox(_box_x527, KK_BORROWED, _ctx);
            _match_x635 = x_9_4; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_0_17 = _match_x635.hi;
            _x_x2972 = _x_0_17; /*float64*/
          }
          z_10 = (_x_x2971 * _x_x2972); /*float64*/
          double err_9;
          double _x_x2973;
          {
            double _x_1_9 = sins.hi;
            _x_x2973 = _x_1_9; /*float64*/
          }
          double _x_x2974;
          kk_std_num_ddouble__ddouble _match_x634;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x634 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x528 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_4_0 = kk_std_num_ddouble__ddouble_unbox(_box_x528, KK_BORROWED, _ctx);
            _match_x634 = x_9_4_0; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_0_0_6 = _match_x634.hi;
            _x_x2974 = _x_0_0_6; /*float64*/
          }
          double _x_x2975 = (-z_10); /*float64*/
          err_9 = kk_std_num_float64_fmadd(_x_x2973, _x_x2974, _x_x2975, _ctx); /*float64*/
          kk_std_num_ddouble__edouble z_0_8 = kk_std_num_ddouble__new_Edouble(z_10, err_9, _ctx); /*std/num/ddouble/edouble*/;
          double e_8;
          double _x_x2976;
          {
            double _x_1_0_5 = z_0_8.err;
            _x_x2976 = _x_1_0_5; /*float64*/
          }
          double _x_x2977;
          double _x_x2978;
          double _x_x2979;
          {
            double _x_2_8 = sins.hi;
            _x_x2979 = _x_2_8; /*float64*/
          }
          double _x_x2980;
          kk_std_num_ddouble__ddouble _match_x633;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x633 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x529 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_4_1 = kk_std_num_ddouble__ddouble_unbox(_box_x529, KK_BORROWED, _ctx);
            _match_x633 = x_9_4_1; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_3_8 = _match_x633.lo;
            _x_x2980 = _x_3_8; /*float64*/
          }
          _x_x2978 = (_x_x2979 * _x_x2980); /*float64*/
          double _x_x2981;
          double _x_x2982;
          {
            double _x_4_8 = sins.lo;
            _x_x2982 = _x_4_8; /*float64*/
          }
          double _x_x2983;
          kk_std_num_ddouble__ddouble _match_x632;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x632 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x530 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_4_2 = kk_std_num_ddouble__ddouble_unbox(_box_x530, KK_BORROWED, _ctx);
            kk_std_core_types__maybe_drop(m_1_10526, _ctx);
            _match_x632 = x_9_4_2; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_5_8 = _match_x632.hi;
            _x_x2983 = _x_5_8; /*float64*/
          }
          _x_x2981 = (_x_x2982 * _x_x2983); /*float64*/
          _x_x2977 = (_x_x2978 + _x_x2981); /*float64*/
          e_8 = (_x_x2976 + _x_x2977); /*float64*/
          bool b_10040_8;
          double _x_x2984;
          {
            double _x_6_8 = z_0_8.num;
            _x_x2984 = _x_6_8; /*float64*/
          }
          b_10040_8 = isfinite(_x_x2984); /*bool*/
          kk_std_num_ddouble__ddouble _b_x531_549;
          kk_std_num_ddouble__ddouble _x_x2985;
          double _x_x2986;
          double _x_x2987;
          {
            double _x_21_0 = y_10_10535.hi;
            _x_x2987 = _x_21_0; /*float64*/
          }
          _x_x2986 = (-_x_x2987); /*float64*/
          double _x_x2988;
          double _x_x2989;
          {
            double _x_0_16_0 = y_10_10535.lo;
            _x_x2989 = _x_0_16_0; /*float64*/
          }
          _x_x2988 = (-_x_x2989); /*float64*/
          _x_x2985 = kk_std_num_ddouble__new_Ddouble(_x_x2986, _x_x2988, _ctx); /*std/num/ddouble/ddouble*/
          _b_x531_549 = kk_std_num_ddouble__lp__plus__rp_(x_14_10534, _x_x2985, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _b_x532_550;
          kk_std_num_ddouble__ddouble _x_x2990 = kk_std_num_ddouble__lp__star__rp_(coss, sinb, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x2991;
          if (b_10040_8) {
            double z_1_8;
            double _x_x2992;
            {
              double _x_6_0_9 = z_0_8.num;
              _x_x2992 = _x_6_0_9; /*float64*/
            }
            z_1_8 = (_x_x2992 + e_8); /*float64*/
            double err_0_8;
            double _x_x2993;
            double _x_x2994;
            {
              double _x_6_1_9 = z_0_8.num;
              _x_x2994 = _x_6_1_9; /*float64*/
            }
            _x_x2993 = (z_1_8 - _x_x2994); /*float64*/
            err_0_8 = (e_8 - _x_x2993); /*float64*/
            double _x_x2995;
            bool _match_x631 = isfinite(z_1_8); /*bool*/;
            if (_match_x631) {
              _x_x2995 = err_0_8; /*float64*/
            }
            else {
              _x_x2995 = z_1_8; /*float64*/
            }
            _x_x2991 = kk_std_num_ddouble__new_Ddouble(z_1_8, _x_x2995, _ctx); /*std/num/ddouble/ddouble*/
          }
          else {
            double _x_x2996;
            {
              double _x_6_2_9 = z_0_8.num;
              _x_x2996 = _x_6_2_9; /*float64*/
            }
            _x_x2991 = kk_std_num_ddouble__new_Ddouble(_x_x2996, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          }
          _b_x532_550 = kk_std_num_ddouble__lp__plus__rp_(_x_x2990, _x_x2991, _ctx); /*std/num/ddouble/ddouble*/
          return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(_b_x531_549, _ctx), kk_std_num_ddouble__ddouble_box(_b_x532_550, _ctx), _ctx);
        }
        {
          kk_std_num_ddouble__ddouble x_16_10820;
          double _x_x2997;
          double _x_x2998;
          {
            double _x_23 = sins.hi;
            _x_x2998 = _x_23; /*float64*/
          }
          _x_x2997 = (-_x_x2998); /*float64*/
          double _x_x2999;
          double _x_x3000;
          {
            double _x_0_18 = sins.lo;
            _x_x3000 = _x_0_18; /*float64*/
          }
          _x_x2999 = (-_x_x3000); /*float64*/
          x_16_10820 = kk_std_num_ddouble__new_Ddouble(_x_x2997, _x_x2999, _ctx); /*std/num/ddouble/ddouble*/
          double z_6_0;
          double _x_x3001;
          {
            double _x_22_0 = x_16_10820.hi;
            _x_x3001 = _x_22_0; /*float64*/
          }
          double _x_x3002;
          kk_std_num_ddouble__ddouble _match_x630;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x630 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x533 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_5 = kk_std_num_ddouble__ddouble_unbox(_box_x533, KK_BORROWED, _ctx);
            _match_x630 = x_9_5; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_0_17_0 = _match_x630.hi;
            _x_x3002 = _x_0_17_0; /*float64*/
          }
          z_6_0 = (_x_x3001 * _x_x3002); /*float64*/
          double err_5_0;
          double _x_x3003;
          {
            double _x_22_0_0 = x_16_10820.hi;
            _x_x3003 = _x_22_0_0; /*float64*/
          }
          double _x_x3004;
          kk_std_num_ddouble__ddouble _match_x629;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x629 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x534 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_6 = kk_std_num_ddouble__ddouble_unbox(_box_x534, KK_BORROWED, _ctx);
            _match_x629 = x_9_6; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_0_17_0_0 = _match_x629.hi;
            _x_x3004 = _x_0_17_0_0; /*float64*/
          }
          double _x_x3005 = (-z_6_0); /*float64*/
          err_5_0 = kk_std_num_float64_fmadd(_x_x3003, _x_x3004, _x_x3005, _ctx); /*float64*/
          kk_std_num_ddouble__edouble z_0_4_0 = kk_std_num_ddouble__new_Edouble(z_6_0, err_5_0, _ctx); /*std/num/ddouble/edouble*/;
          double e_4_0;
          double _x_x3006;
          {
            double _x_1_5_0 = z_0_4_0.err;
            _x_x3006 = _x_1_5_0; /*float64*/
          }
          double _x_x3007;
          double _x_x3008;
          double _x_x3009;
          {
            double _x_2_4_0 = x_16_10820.hi;
            _x_x3009 = _x_2_4_0; /*float64*/
          }
          double _x_x3010;
          kk_std_num_ddouble__ddouble _match_x628;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x628 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x535 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_7 = kk_std_num_ddouble__ddouble_unbox(_box_x535, KK_BORROWED, _ctx);
            _match_x628 = x_9_7; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_3_4_0 = _match_x628.lo;
            _x_x3010 = _x_3_4_0; /*float64*/
          }
          _x_x3008 = (_x_x3009 * _x_x3010); /*float64*/
          double _x_x3011;
          double _x_x3012;
          {
            double _x_4_4_0 = x_16_10820.lo;
            _x_x3012 = _x_4_4_0; /*float64*/
          }
          double _x_x3013;
          kk_std_num_ddouble__ddouble _match_x627;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x627 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x536 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_8 = kk_std_num_ddouble__ddouble_unbox(_box_x536, KK_BORROWED, _ctx);
            _match_x627 = x_9_8; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_5_4_0 = _match_x627.hi;
            _x_x3013 = _x_5_4_0; /*float64*/
          }
          _x_x3011 = (_x_x3012 * _x_x3013); /*float64*/
          _x_x3007 = (_x_x3008 + _x_x3011); /*float64*/
          e_4_0 = (_x_x3006 + _x_x3007); /*float64*/
          bool b_10040_4_0;
          double _x_x3014;
          {
            double _x_6_4_0 = z_0_4_0.num;
            _x_x3014 = _x_6_4_0; /*float64*/
          }
          b_10040_4_0 = isfinite(_x_x3014); /*bool*/
          kk_std_num_ddouble__ddouble x_15_10536;
          if (b_10040_4_0) {
            double z_1_4_0;
            double _x_x3015;
            {
              double _x_6_4_0_0 = z_0_4_0.num;
              _x_x3015 = _x_6_4_0_0; /*float64*/
            }
            z_1_4_0 = (_x_x3015 + e_4_0); /*float64*/
            double err_0_4_0;
            double _x_x3016;
            double _x_x3017;
            {
              double _x_6_4_1 = z_0_4_0.num;
              _x_x3017 = _x_6_4_1; /*float64*/
            }
            _x_x3016 = (z_1_4_0 - _x_x3017); /*float64*/
            err_0_4_0 = (e_4_0 - _x_x3016); /*float64*/
            double _x_x3018;
            bool _match_x626 = isfinite(z_1_4_0); /*bool*/;
            if (_match_x626) {
              _x_x3018 = err_0_4_0; /*float64*/
            }
            else {
              _x_x3018 = z_1_4_0; /*float64*/
            }
            x_15_10536 = kk_std_num_ddouble__new_Ddouble(z_1_4_0, _x_x3018, _ctx); /*std/num/ddouble/ddouble*/
          }
          else {
            double _x_x3019;
            {
              double _x_6_4_2 = z_0_4_0.num;
              _x_x3019 = _x_6_4_2; /*float64*/
            }
            x_15_10536 = kk_std_num_ddouble__new_Ddouble(_x_x3019, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          }
          kk_std_num_ddouble__ddouble y_11_10537 = kk_std_num_ddouble__lp__star__rp_(coss, sinb, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble x_16_10538 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
          double z_11;
          double _x_x3020;
          {
            double _x_24 = coss.hi;
            _x_x3020 = _x_24; /*float64*/
          }
          double _x_x3021;
          kk_std_num_ddouble__ddouble _match_x625;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x625 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x537 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_9 = kk_std_num_ddouble__ddouble_unbox(_box_x537, KK_BORROWED, _ctx);
            _match_x625 = x_9_9; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_0_19 = _match_x625.hi;
            _x_x3021 = _x_0_19; /*float64*/
          }
          z_11 = (_x_x3020 * _x_x3021); /*float64*/
          double err_10;
          double _x_x3022;
          {
            double _x_1_10 = coss.hi;
            _x_x3022 = _x_1_10; /*float64*/
          }
          double _x_x3023;
          kk_std_num_ddouble__ddouble _match_x624;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x624 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x538 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_9_0 = kk_std_num_ddouble__ddouble_unbox(_box_x538, KK_BORROWED, _ctx);
            _match_x624 = x_9_9_0; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_0_0_7 = _match_x624.hi;
            _x_x3023 = _x_0_0_7; /*float64*/
          }
          double _x_x3024 = (-z_11); /*float64*/
          err_10 = kk_std_num_float64_fmadd(_x_x3022, _x_x3023, _x_x3024, _ctx); /*float64*/
          kk_std_num_ddouble__edouble z_0_9 = kk_std_num_ddouble__new_Edouble(z_11, err_10, _ctx); /*std/num/ddouble/edouble*/;
          double e_9;
          double _x_x3025;
          {
            double _x_1_0_6 = z_0_9.err;
            _x_x3025 = _x_1_0_6; /*float64*/
          }
          double _x_x3026;
          double _x_x3027;
          double _x_x3028;
          {
            double _x_2_9 = coss.hi;
            _x_x3028 = _x_2_9; /*float64*/
          }
          double _x_x3029;
          kk_std_num_ddouble__ddouble _match_x623;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x623 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x539 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_9_1 = kk_std_num_ddouble__ddouble_unbox(_box_x539, KK_BORROWED, _ctx);
            _match_x623 = x_9_9_1; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_3_9 = _match_x623.lo;
            _x_x3029 = _x_3_9; /*float64*/
          }
          _x_x3027 = (_x_x3028 * _x_x3029); /*float64*/
          double _x_x3030;
          double _x_x3031;
          {
            double _x_4_9 = coss.lo;
            _x_x3031 = _x_4_9; /*float64*/
          }
          double _x_x3032;
          kk_std_num_ddouble__ddouble _match_x622;
          if (kk_std_core_types__is_Nothing(m_1_10526, _ctx)) {
            _match_x622 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            kk_box_t _box_x540 = m_1_10526._cons.Just.value;
            kk_std_num_ddouble__ddouble x_9_9_2 = kk_std_num_ddouble__ddouble_unbox(_box_x540, KK_BORROWED, _ctx);
            kk_std_core_types__maybe_drop(m_1_10526, _ctx);
            _match_x622 = x_9_9_2; /*std/num/ddouble/ddouble*/
          }
          {
            double _x_5_9 = _match_x622.hi;
            _x_x3032 = _x_5_9; /*float64*/
          }
          _x_x3030 = (_x_x3031 * _x_x3032); /*float64*/
          _x_x3026 = (_x_x3027 + _x_x3030); /*float64*/
          e_9 = (_x_x3025 + _x_x3026); /*float64*/
          bool b_10040_9;
          double _x_x3033;
          {
            double _x_6_9 = z_0_9.num;
            _x_x3033 = _x_6_9; /*float64*/
          }
          b_10040_9 = isfinite(_x_x3033); /*bool*/
          kk_std_num_ddouble__ddouble y_12_10539;
          if (b_10040_9) {
            double z_1_9;
            double _x_x3034;
            {
              double _x_6_0_10 = z_0_9.num;
              _x_x3034 = _x_6_0_10; /*float64*/
            }
            z_1_9 = (_x_x3034 + e_9); /*float64*/
            double err_0_9;
            double _x_x3035;
            double _x_x3036;
            {
              double _x_6_1_10 = z_0_9.num;
              _x_x3036 = _x_6_1_10; /*float64*/
            }
            _x_x3035 = (z_1_9 - _x_x3036); /*float64*/
            err_0_9 = (e_9 - _x_x3035); /*float64*/
            double _x_x3037;
            bool _match_x621 = isfinite(z_1_9); /*bool*/;
            if (_match_x621) {
              _x_x3037 = err_0_9; /*float64*/
            }
            else {
              _x_x3037 = z_1_9; /*float64*/
            }
            y_12_10539 = kk_std_num_ddouble__new_Ddouble(z_1_9, _x_x3037, _ctx); /*std/num/ddouble/ddouble*/
          }
          else {
            double _x_x3038;
            {
              double _x_6_2_10 = z_0_9.num;
              _x_x3038 = _x_6_2_10; /*float64*/
            }
            y_12_10539 = kk_std_num_ddouble__new_Ddouble(_x_x3038, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          }
          kk_std_num_ddouble__ddouble _b_x541_551;
          kk_std_num_ddouble__ddouble _x_x3039;
          double _x_x3040;
          double _x_x3041;
          {
            double _x_24_0 = y_11_10537.hi;
            _x_x3041 = _x_24_0; /*float64*/
          }
          _x_x3040 = (-_x_x3041); /*float64*/
          double _x_x3042;
          double _x_x3043;
          {
            double _x_0_19_0 = y_11_10537.lo;
            _x_x3043 = _x_0_19_0; /*float64*/
          }
          _x_x3042 = (-_x_x3043); /*float64*/
          _x_x3039 = kk_std_num_ddouble__new_Ddouble(_x_x3040, _x_x3042, _ctx); /*std/num/ddouble/ddouble*/
          _b_x541_551 = kk_std_num_ddouble__lp__plus__rp_(x_15_10536, _x_x3039, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _b_x542_552;
          kk_std_num_ddouble__ddouble _x_x3044;
          double _x_x3045;
          double _x_x3046;
          {
            double _x_25 = y_12_10539.hi;
            _x_x3046 = _x_25; /*float64*/
          }
          _x_x3045 = (-_x_x3046); /*float64*/
          double _x_x3047;
          double _x_x3048;
          {
            double _x_0_20 = y_12_10539.lo;
            _x_x3048 = _x_0_20; /*float64*/
          }
          _x_x3047 = (-_x_x3048); /*float64*/
          _x_x3044 = kk_std_num_ddouble__new_Ddouble(_x_x3045, _x_x3047, _ctx); /*std/num/ddouble/ddouble*/
          _b_x542_552 = kk_std_num_ddouble__lp__plus__rp_(x_16_10538, _x_x3044, _ctx); /*std/num/ddouble/ddouble*/
          return kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(_b_x541_551, _ctx), kk_std_num_ddouble__ddouble_box(_b_x542_552, _ctx), _ctx);
        }
      }
    }
  }
}
 
// Return `x` with the sign of `y`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_with_sign_of(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_x615;
  double _x_x3049;
  {
    double _x = y.hi;
    _x_x3049 = _x; /*float64*/
  }
  _match_x615 = (_x_x3049 < (0x0p+0)); /*bool*/
  if (_match_x615) {
    kk_std_num_ddouble__ddouble x_1_10545 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
    double _x_x3050;
    double _x_x3051;
    {
      double _x_0 = x_1_10545.hi;
      _x_x3051 = _x_0; /*float64*/
    }
    _x_x3050 = (-_x_x3051); /*float64*/
    double _x_x3052;
    double _x_x3053;
    {
      double _x_1 = x_1_10545.lo;
      _x_x3053 = _x_1; /*float64*/
    }
    _x_x3052 = (-_x_x3053); /*float64*/
    return kk_std_num_ddouble__new_Ddouble(_x_x3050, _x_x3052, _ctx);
  }
  {
    return kk_std_num_ddouble_abs(x, _ctx);
  }
}
 
// The arc-tangent of a point (`x`,`y`). Returns the angle with respect to the x-axis in radians between -&pi; and &pi;.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_atan2(kk_std_num_ddouble__ddouble y, kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (y : ddouble, x : ddouble) -> ddouble */ 
  bool _match_x602;
  double _x_x3054;
  {
    double _x = x.hi;
    _x_x3054 = _x; /*float64*/
  }
  _match_x602 = (_x_x3054 == (0x0p+0)); /*bool*/
  if (_match_x602) {
    bool _match_x614;
    double _x_x3055;
    {
      double _x_0 = y.hi;
      _x_x3055 = _x_0; /*float64*/
    }
    _match_x614 = (_x_x3055 == (0x0p+0)); /*bool*/
    if (_match_x614) {
      return kk_std_num_ddouble_zero;
    }
    {
      return kk_std_num_ddouble_with_sign_of(kk_std_num_ddouble_dd_pi2, y, _ctx);
    }
  }
  {
    bool _match_x603;
    double _x_x3056;
    {
      double _x_1 = y.hi;
      _x_x3056 = _x_1; /*float64*/
    }
    _match_x603 = (_x_x3056 == (0x0p+0)); /*bool*/
    if (_match_x603) {
      bool _match_x613;
      double _x_x3057;
      {
        double _x_2 = x.hi;
        _x_x3057 = _x_2; /*float64*/
      }
      _match_x613 = (_x_x3057 > (0x0p+0)); /*bool*/
      if (_match_x613) {
        return kk_std_num_ddouble_zero;
      }
      {
        return kk_std_num_ddouble_dd_pi;
      }
    }
    {
      bool _match_x604 = kk_std_num_ddouble__lp__eq__eq__rp_(x, y, _ctx); /*bool*/;
      if (_match_x604) {
        bool _match_x612;
        double _x_x3058;
        {
          double _x_3 = y.hi;
          _x_x3058 = _x_3; /*float64*/
        }
        _match_x612 = (_x_x3058 > (0x0p+0)); /*bool*/
        if (_match_x612) {
          return kk_std_num_ddouble_dd_pi4;
        }
        {
          double _x_x3059;
          double _x_x3060;
          kk_std_num_ddouble__ddouble _x_x3061 = kk_std_num_ddouble_dd_pi34; /*std/num/ddouble/ddouble*/
          {
            double _x_4 = _x_x3061.hi;
            _x_x3060 = _x_4; /*float64*/
          }
          _x_x3059 = (-_x_x3060); /*float64*/
          double _x_x3062;
          double _x_x3063;
          kk_std_num_ddouble__ddouble _x_x3064 = kk_std_num_ddouble_dd_pi34; /*std/num/ddouble/ddouble*/
          {
            double _x_0_0 = _x_x3064.lo;
            _x_x3063 = _x_0_0; /*float64*/
          }
          _x_x3062 = (-_x_x3063); /*float64*/
          return kk_std_num_ddouble__new_Ddouble(_x_x3059, _x_x3062, _ctx);
        }
      }
      {
        kk_std_num_ddouble__ddouble y_0_10564;
        double _x_x3065;
        double _x_x3066;
        {
          double _x_5 = y.hi;
          _x_x3066 = _x_5; /*float64*/
        }
        _x_x3065 = (-_x_x3066); /*float64*/
        double _x_x3067;
        double _x_x3068;
        {
          double _x_0_1 = y.lo;
          _x_x3068 = _x_0_1; /*float64*/
        }
        _x_x3067 = (-_x_x3068); /*float64*/
        y_0_10564 = kk_std_num_ddouble__new_Ddouble(_x_x3065, _x_x3067, _ctx); /*std/num/ddouble/ddouble*/
        kk_std_core_types__order x_6_10565;
        kk_std_core_types__order _match_x611;
        double _x_x3069;
        {
          double _x_6 = x.hi;
          _x_x3069 = _x_6; /*float64*/
        }
        double _x_x3070;
        {
          double _x_0_2 = y_0_10564.hi;
          _x_x3070 = _x_0_2; /*float64*/
        }
        _match_x611 = kk_std_num_float64_cmp(_x_x3069, _x_x3070, _ctx); /*order*/
        if (kk_std_core_types__is_Eq(_match_x611, _ctx)) {
          double _x_x3071;
          {
            double _x_1_0 = x.lo;
            _x_x3071 = _x_1_0; /*float64*/
          }
          double _x_x3072;
          {
            double _x_2_0 = y_0_10564.lo;
            _x_x3072 = _x_2_0; /*float64*/
          }
          x_6_10565 = kk_std_num_float64_cmp(_x_x3071, _x_x3072, _ctx); /*order*/
        }
        else {
          x_6_10565 = _match_x611; /*order*/
        }
        bool _match_x605;
        kk_integer_t _brw_x609;
        if (kk_std_core_types__is_Lt(x_6_10565, _ctx)) {
          _brw_x609 = kk_integer_from_small(-1); /*int*/
          goto _match_x3073;
        }
        if (kk_std_core_types__is_Eq(x_6_10565, _ctx)) {
          _brw_x609 = kk_integer_from_small(0); /*int*/
          goto _match_x3073;
        }
        {
          _brw_x609 = kk_integer_from_small(1); /*int*/
        }
        _match_x3073: ;
        bool _brw_x610 = kk_integer_eq_borrow(_brw_x609,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        kk_integer_drop(_brw_x609, _ctx);
        _match_x605 = _brw_x610; /*bool*/
        if (_match_x605) {
          bool _match_x608;
          double _x_x3074;
          {
            double _x_4_0 = y.hi;
            _x_x3074 = _x_4_0; /*float64*/
          }
          _match_x608 = (_x_x3074 > (0x0p+0)); /*bool*/
          if (_match_x608) {
            return kk_std_num_ddouble_dd_pi34;
          }
          {
            double _x_x3075;
            double _x_x3076;
            kk_std_num_ddouble__ddouble _x_x3077 = kk_std_num_ddouble_dd_pi4; /*std/num/ddouble/ddouble*/
            {
              double _x_7 = _x_x3077.hi;
              _x_x3076 = _x_7; /*float64*/
            }
            _x_x3075 = (-_x_x3076); /*float64*/
            double _x_x3078;
            double _x_x3079;
            kk_std_num_ddouble__ddouble _x_x3080 = kk_std_num_ddouble_dd_pi4; /*std/num/ddouble/ddouble*/
            {
              double _x_0_3 = _x_x3080.lo;
              _x_x3079 = _x_0_3; /*float64*/
            }
            _x_x3078 = (-_x_x3079); /*float64*/
            return kk_std_num_ddouble__new_Ddouble(_x_x3075, _x_x3078, _ctx);
          }
        }
        {
          kk_std_num_ddouble__ddouble r;
          kk_std_num_ddouble__ddouble _x_x3081;
          kk_std_num_ddouble__ddouble _x_x3082 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x3083 = kk_std_num_ddouble_sqr(y, _ctx); /*std/num/ddouble/ddouble*/
          _x_x3081 = kk_std_num_ddouble__lp__plus__rp_(_x_x3082, _x_x3083, _ctx); /*std/num/ddouble/ddouble*/
          r = kk_std_num_ddouble_sqrt(_x_x3081, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble xr = kk_std_num_ddouble__lp__fs__rp_(x, r, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble yr = kk_std_num_ddouble__lp__fs__rp_(y, r, _ctx); /*std/num/ddouble/ddouble*/;
          double d_5_10570;
          double _x_x3084;
          {
            double _x_5_0 = y.hi;
            _x_x3084 = _x_5_0; /*float64*/
          }
          double _x_x3085;
          {
            double _x_6_0 = x.hi;
            _x_x3085 = _x_6_0; /*float64*/
          }
          d_5_10570 = atan2(_x_x3084,_x_x3085); /*float64*/
          kk_std_num_ddouble__ddouble z = kk_std_num_ddouble__new_Ddouble(d_5_10570, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_core_types__tuple2 _match_x606 = kk_std_num_ddouble_sincos(z, _ctx); /*(std/num/ddouble/ddouble, std/num/ddouble/ddouble)*/;
          {
            kk_box_t _box_x559 = _match_x606.fst;
            kk_box_t _box_x560 = _match_x606.snd;
            kk_std_num_ddouble__ddouble sinz = kk_std_num_ddouble__ddouble_unbox(_box_x559, KK_BORROWED, _ctx);
            kk_std_num_ddouble__ddouble cosz = kk_std_num_ddouble__ddouble_unbox(_box_x560, KK_BORROWED, _ctx);
            kk_std_core_types__tuple2_drop(_match_x606, _ctx);
            kk_std_num_ddouble__ddouble ddouble_0_8_10576 = kk_std_num_ddouble_abs(yr, _ctx); /*std/num/ddouble/ddouble*/;
            bool _match_x607;
            double _x_x3086;
            double _x_x3087;
            {
              double _x_7_0 = xr.hi;
              _x_x3087 = _x_7_0; /*float64*/
            }
            _x_x3086 = kk_double_abs(_x_x3087); /*float64*/
            double _x_x3088;
            {
              double _x_8 = ddouble_0_8_10576.hi;
              _x_x3088 = _x_8; /*float64*/
            }
            _match_x607 = (_x_x3086 > _x_x3088); /*bool*/
            if (_match_x607) {
              kk_std_num_ddouble__ddouble _x_x3089;
              kk_std_num_ddouble__ddouble _x_x3090;
              kk_std_num_ddouble__ddouble _x_x3091;
              double _x_x3092;
              double _x_x3093;
              {
                double _x_9 = sinz.hi;
                _x_x3093 = _x_9; /*float64*/
              }
              _x_x3092 = (-_x_x3093); /*float64*/
              double _x_x3094;
              double _x_x3095;
              {
                double _x_0_4 = sinz.lo;
                _x_x3095 = _x_0_4; /*float64*/
              }
              _x_x3094 = (-_x_x3095); /*float64*/
              _x_x3091 = kk_std_num_ddouble__new_Ddouble(_x_x3092, _x_x3094, _ctx); /*std/num/ddouble/ddouble*/
              _x_x3090 = kk_std_num_ddouble__lp__plus__rp_(yr, _x_x3091, _ctx); /*std/num/ddouble/ddouble*/
              _x_x3089 = kk_std_num_ddouble__lp__fs__rp_(_x_x3090, cosz, _ctx); /*std/num/ddouble/ddouble*/
              return kk_std_num_ddouble__lp__plus__rp_(z, _x_x3089, _ctx);
            }
            {
              kk_std_num_ddouble__ddouble y_3_10580;
              kk_std_num_ddouble__ddouble _x_x3096;
              kk_std_num_ddouble__ddouble _x_x3097;
              double _x_x3098;
              double _x_x3099;
              {
                double _x_10 = cosz.hi;
                _x_x3099 = _x_10; /*float64*/
              }
              _x_x3098 = (-_x_x3099); /*float64*/
              double _x_x3100;
              double _x_x3101;
              {
                double _x_0_5 = cosz.lo;
                _x_x3101 = _x_0_5; /*float64*/
              }
              _x_x3100 = (-_x_x3101); /*float64*/
              _x_x3097 = kk_std_num_ddouble__new_Ddouble(_x_x3098, _x_x3100, _ctx); /*std/num/ddouble/ddouble*/
              _x_x3096 = kk_std_num_ddouble__lp__plus__rp_(xr, _x_x3097, _ctx); /*std/num/ddouble/ddouble*/
              y_3_10580 = kk_std_num_ddouble__lp__fs__rp_(_x_x3096, sinz, _ctx); /*std/num/ddouble/ddouble*/
              kk_std_num_ddouble__ddouble _x_x3102;
              double _x_x3103;
              double _x_x3104;
              {
                double _x_11 = y_3_10580.hi;
                _x_x3104 = _x_11; /*float64*/
              }
              _x_x3103 = (-_x_x3104); /*float64*/
              double _x_x3105;
              double _x_x3106;
              {
                double _x_0_6 = y_3_10580.lo;
                _x_x3106 = _x_0_6; /*float64*/
              }
              _x_x3105 = (-_x_x3106); /*float64*/
              _x_x3102 = kk_std_num_ddouble__new_Ddouble(_x_x3103, _x_x3105, _ctx); /*std/num/ddouble/ddouble*/
              return kk_std_num_ddouble__lp__plus__rp_(z, _x_x3102, _ctx);
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
  bool _match_x600 = kk_std_num_ddouble__lp__gt__rp_(a, kk_std_num_ddouble_one, _ctx); /*bool*/;
  if (_match_x600) {
    return kk_std_num_ddouble_dd_nan;
  }
  {
    bool _match_x601 = kk_std_num_ddouble__lp__eq__eq__rp_(a, kk_std_num_ddouble_one, _ctx); /*bool*/;
    if (_match_x601) {
      return kk_std_num_ddouble_with_sign_of(kk_std_num_ddouble_dd_pi2, x, _ctx);
    }
    {
      kk_std_num_ddouble__ddouble y_10584 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x_x3107;
      kk_std_num_ddouble__ddouble _x_x3108;
      kk_std_num_ddouble__ddouble _x_x3109;
      double _x_x3110;
      double _x_x3111;
      {
        double _x = y_10584.hi;
        _x_x3111 = _x; /*float64*/
      }
      _x_x3110 = (-_x_x3111); /*float64*/
      double _x_x3112;
      double _x_x3113;
      {
        double _x_0 = y_10584.lo;
        _x_x3113 = _x_0; /*float64*/
      }
      _x_x3112 = (-_x_x3113); /*float64*/
      _x_x3109 = kk_std_num_ddouble__new_Ddouble(_x_x3110, _x_x3112, _ctx); /*std/num/ddouble/ddouble*/
      _x_x3108 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x3109, _ctx); /*std/num/ddouble/ddouble*/
      _x_x3107 = kk_std_num_ddouble_sqrt(_x_x3108, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble_atan2(x, _x_x3107, _ctx);
    }
  }
}
 
// The arc-cosine of `x`. Returns the angle in radians.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_acos(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble a = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x597 = kk_std_num_ddouble__lp__gt__rp_(a, kk_std_num_ddouble_one, _ctx); /*bool*/;
  if (_match_x597) {
    return kk_std_num_ddouble_dd_nan;
  }
  {
    bool _match_x598 = kk_std_num_ddouble__lp__eq__eq__rp_(a, kk_std_num_ddouble_one, _ctx); /*bool*/;
    if (_match_x598) {
      bool _match_x599;
      double _x_x3114;
      {
        double _x = x.hi;
        _x_x3114 = _x; /*float64*/
      }
      _match_x599 = (_x_x3114 > (0x0p+0)); /*bool*/
      if (_match_x599) {
        return kk_std_num_ddouble_zero;
      }
      {
        return kk_std_num_ddouble_dd_pi;
      }
    }
    {
      kk_std_num_ddouble__ddouble y_10589 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x_x3115;
      kk_std_num_ddouble__ddouble _x_x3116;
      kk_std_num_ddouble__ddouble _x_x3117;
      double _x_x3118;
      double _x_x3119;
      {
        double _x_0 = y_10589.hi;
        _x_x3119 = _x_0; /*float64*/
      }
      _x_x3118 = (-_x_x3119); /*float64*/
      double _x_x3120;
      double _x_x3121;
      {
        double _x_0_0 = y_10589.lo;
        _x_x3121 = _x_0_0; /*float64*/
      }
      _x_x3120 = (-_x_x3121); /*float64*/
      _x_x3117 = kk_std_num_ddouble__new_Ddouble(_x_x3118, _x_x3120, _ctx); /*std/num/ddouble/ddouble*/
      _x_x3116 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x3117, _ctx); /*std/num/ddouble/ddouble*/
      _x_x3115 = kk_std_num_ddouble_sqrt(_x_x3116, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble_atan2(_x_x3115, x, _ctx);
    }
  }
}
 
// The hyperbolic sine of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sinh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x591;
  double _x_x3122;
  {
    double _x = x.hi;
    _x_x3122 = _x; /*float64*/
  }
  _match_x591 = (_x_x3122 == (0x0p+0)); /*bool*/
  if (_match_x591) {
    return kk_std_num_ddouble_zero;
  }
  {
    kk_std_num_ddouble__ddouble x_1_10593 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_x592;
    double _x_x3123;
    {
      double _x_0 = x_1_10593.hi;
      _x_x3123 = _x_0; /*float64*/
    }
    _match_x592 = (_x_x3123 > (0x1.999999999999ap-5)); /*bool*/
    if (_match_x592) {
      kk_std_num_ddouble__ddouble ex = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
      bool b_10595;
      bool _match_x596;
      double _x_x3124;
      {
        double _x_1 = ex.hi;
        _x_x3124 = _x_1; /*float64*/
      }
      _match_x596 = isfinite(_x_x3124); /*bool*/
      if (_match_x596) {
        double _x_x3125;
        {
          double _x_0_0 = ex.lo;
          _x_x3125 = _x_0_0; /*float64*/
        }
        b_10595 = isfinite(_x_x3125); /*bool*/
      }
      else {
        b_10595 = false; /*bool*/
      }
      if (b_10595) {
        kk_std_num_ddouble__ddouble y_10598 = kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble_one, ex, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble x_2_10596;
        kk_std_num_ddouble__ddouble _x_x3126;
        double _x_x3127;
        double _x_x3128;
        {
          double _x_2 = y_10598.hi;
          _x_x3128 = _x_2; /*float64*/
        }
        _x_x3127 = (-_x_x3128); /*float64*/
        double _x_x3129;
        double _x_x3130;
        {
          double _x_0_1 = y_10598.lo;
          _x_x3130 = _x_0_1; /*float64*/
        }
        _x_x3129 = (-_x_x3130); /*float64*/
        _x_x3126 = kk_std_num_ddouble__new_Ddouble(_x_x3127, _x_x3129, _ctx); /*std/num/ddouble/ddouble*/
        x_2_10596 = kk_std_num_ddouble__lp__plus__rp_(ex, _x_x3126, _ctx); /*std/num/ddouble/ddouble*/
        double _x_x3131;
        double _x_x3132;
        {
          double _x_1_0 = x_2_10596.hi;
          _x_x3132 = _x_1_0; /*float64*/
        }
        _x_x3131 = (_x_x3132 * (0x1p-1)); /*float64*/
        double _x_x3133;
        double _x_x3134;
        {
          double _x_2_0 = x_2_10596.lo;
          _x_x3134 = _x_2_0; /*float64*/
        }
        _x_x3133 = (_x_x3134 * (0x1p-1)); /*float64*/
        return kk_std_num_ddouble__new_Ddouble(_x_x3131, _x_x3133, _ctx);
      }
      {
        return ex;
      }
    }
    {
      kk_std_num_ddouble__ddouble x2 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble x_3_10839;
      kk_std_num_ddouble__ddouble _x_x3135 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(6), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      x_3_10839 = kk_std_num_ddouble__lp__fs__rp_(x2, _x_x3135, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble x_4_10841;
      kk_std_num_ddouble__ddouble _x_x3136 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(20), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      x_4_10841 = kk_std_num_ddouble__lp__fs__rp_(x2, _x_x3136, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble y_1_10842;
      kk_std_num_ddouble__ddouble _x_x3137;
      kk_std_num_ddouble__ddouble _x_x3138 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(42), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      _x_x3137 = kk_std_num_ddouble__lp__fs__rp_(x2, _x_x3138, _ctx); /*std/num/ddouble/ddouble*/
      y_1_10842 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x3137, _ctx); /*std/num/ddouble/ddouble*/
      double z_3;
      double _x_x3139;
      {
        double _x_8 = x_4_10841.hi;
        _x_x3139 = _x_8; /*float64*/
      }
      double _x_x3140;
      {
        double _x_0_4 = y_1_10842.hi;
        _x_x3140 = _x_0_4; /*float64*/
      }
      z_3 = (_x_x3139 * _x_x3140); /*float64*/
      double err_2;
      double _x_x3141;
      {
        double _x_8_0 = x_4_10841.hi;
        _x_x3141 = _x_8_0; /*float64*/
      }
      double _x_x3142;
      {
        double _x_0_4_0 = y_1_10842.hi;
        _x_x3142 = _x_0_4_0; /*float64*/
      }
      double _x_x3143 = (-z_3); /*float64*/
      err_2 = kk_std_num_float64_fmadd(_x_x3141, _x_x3142, _x_x3143, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0_1 = kk_std_num_ddouble__new_Edouble(z_3, err_2, _ctx); /*std/num/ddouble/edouble*/;
      double e_1;
      double _x_x3144;
      {
        double _x_1_3 = z_0_1.err;
        _x_x3144 = _x_1_3; /*float64*/
      }
      double _x_x3145;
      double _x_x3146;
      double _x_x3147;
      {
        double _x_2_3 = x_4_10841.hi;
        _x_x3147 = _x_2_3; /*float64*/
      }
      double _x_x3148;
      {
        double _x_3_2 = y_1_10842.lo;
        _x_x3148 = _x_3_2; /*float64*/
      }
      _x_x3146 = (_x_x3147 * _x_x3148); /*float64*/
      double _x_x3149;
      double _x_x3150;
      {
        double _x_4_1 = x_4_10841.lo;
        _x_x3150 = _x_4_1; /*float64*/
      }
      double _x_x3151;
      {
        double _x_5_1 = y_1_10842.hi;
        _x_x3151 = _x_5_1; /*float64*/
      }
      _x_x3149 = (_x_x3150 * _x_x3151); /*float64*/
      _x_x3145 = (_x_x3146 + _x_x3149); /*float64*/
      e_1 = (_x_x3144 + _x_x3145); /*float64*/
      bool b_10040_1;
      double _x_x3152;
      {
        double _x_6_1 = z_0_1.num;
        _x_x3152 = _x_6_1; /*float64*/
      }
      b_10040_1 = isfinite(_x_x3152); /*bool*/
      kk_std_num_ddouble__ddouble y_0_10840;
      kk_std_num_ddouble__ddouble _x_x3153;
      if (b_10040_1) {
        double z_1_1;
        double _x_x3154;
        {
          double _x_6_1_0 = z_0_1.num;
          _x_x3154 = _x_6_1_0; /*float64*/
        }
        z_1_1 = (_x_x3154 + e_1); /*float64*/
        double err_0_1;
        double _x_x3155;
        double _x_x3156;
        {
          double _x_6_1_1 = z_0_1.num;
          _x_x3156 = _x_6_1_1; /*float64*/
        }
        _x_x3155 = (z_1_1 - _x_x3156); /*float64*/
        err_0_1 = (e_1 - _x_x3155); /*float64*/
        double _x_x3157;
        bool _match_x595 = isfinite(z_1_1); /*bool*/;
        if (_match_x595) {
          _x_x3157 = err_0_1; /*float64*/
        }
        else {
          _x_x3157 = z_1_1; /*float64*/
        }
        _x_x3153 = kk_std_num_ddouble__new_Ddouble(z_1_1, _x_x3157, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double _x_x3158;
        {
          double _x_6_1_2 = z_0_1.num;
          _x_x3158 = _x_6_1_2; /*float64*/
        }
        _x_x3153 = kk_std_num_ddouble__new_Ddouble(_x_x3158, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      }
      y_0_10840 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x3153, _ctx); /*std/num/ddouble/ddouble*/
      double z_2;
      double _x_x3159;
      {
        double _x_7 = x_3_10839.hi;
        _x_x3159 = _x_7; /*float64*/
      }
      double _x_x3160;
      {
        double _x_0_3 = y_0_10840.hi;
        _x_x3160 = _x_0_3; /*float64*/
      }
      z_2 = (_x_x3159 * _x_x3160); /*float64*/
      double err_1;
      double _x_x3161;
      {
        double _x_7_0 = x_3_10839.hi;
        _x_x3161 = _x_7_0; /*float64*/
      }
      double _x_x3162;
      {
        double _x_0_3_0 = y_0_10840.hi;
        _x_x3162 = _x_0_3_0; /*float64*/
      }
      double _x_x3163 = (-z_2); /*float64*/
      err_1 = kk_std_num_float64_fmadd(_x_x3161, _x_x3162, _x_x3163, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0_0 = kk_std_num_ddouble__new_Edouble(z_2, err_1, _ctx); /*std/num/ddouble/edouble*/;
      double e_0;
      double _x_x3164;
      {
        double _x_1_2 = z_0_0.err;
        _x_x3164 = _x_1_2; /*float64*/
      }
      double _x_x3165;
      double _x_x3166;
      double _x_x3167;
      {
        double _x_2_2 = x_3_10839.hi;
        _x_x3167 = _x_2_2; /*float64*/
      }
      double _x_x3168;
      {
        double _x_3_1 = y_0_10840.lo;
        _x_x3168 = _x_3_1; /*float64*/
      }
      _x_x3166 = (_x_x3167 * _x_x3168); /*float64*/
      double _x_x3169;
      double _x_x3170;
      {
        double _x_4_0 = x_3_10839.lo;
        _x_x3170 = _x_4_0; /*float64*/
      }
      double _x_x3171;
      {
        double _x_5_0 = y_0_10840.hi;
        _x_x3171 = _x_5_0; /*float64*/
      }
      _x_x3169 = (_x_x3170 * _x_x3171); /*float64*/
      _x_x3165 = (_x_x3166 + _x_x3169); /*float64*/
      e_0 = (_x_x3164 + _x_x3165); /*float64*/
      bool b_10040_0;
      double _x_x3172;
      {
        double _x_6_0 = z_0_0.num;
        _x_x3172 = _x_6_0; /*float64*/
      }
      b_10040_0 = isfinite(_x_x3172); /*bool*/
      kk_std_num_ddouble__ddouble y_10838;
      kk_std_num_ddouble__ddouble _x_x3173;
      if (b_10040_0) {
        double z_1_0;
        double _x_x3174;
        {
          double _x_6_0_0 = z_0_0.num;
          _x_x3174 = _x_6_0_0; /*float64*/
        }
        z_1_0 = (_x_x3174 + e_0); /*float64*/
        double err_0_0;
        double _x_x3175;
        double _x_x3176;
        {
          double _x_6_0_1 = z_0_0.num;
          _x_x3176 = _x_6_0_1; /*float64*/
        }
        _x_x3175 = (z_1_0 - _x_x3176); /*float64*/
        err_0_0 = (e_0 - _x_x3175); /*float64*/
        double _x_x3177;
        bool _match_x594 = isfinite(z_1_0); /*bool*/;
        if (_match_x594) {
          _x_x3177 = err_0_0; /*float64*/
        }
        else {
          _x_x3177 = z_1_0; /*float64*/
        }
        _x_x3173 = kk_std_num_ddouble__new_Ddouble(z_1_0, _x_x3177, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double _x_x3178;
        {
          double _x_6_0_2 = z_0_0.num;
          _x_x3178 = _x_6_0_2; /*float64*/
        }
        _x_x3173 = kk_std_num_ddouble__new_Ddouble(_x_x3178, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      }
      y_10838 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x3173, _ctx); /*std/num/ddouble/ddouble*/
      double z;
      double _x_x3179;
      {
        double _x_3 = x.hi;
        _x_x3179 = _x_3; /*float64*/
      }
      double _x_x3180;
      {
        double _x_0_2 = y_10838.hi;
        _x_x3180 = _x_0_2; /*float64*/
      }
      z = (_x_x3179 * _x_x3180); /*float64*/
      double err;
      double _x_x3181;
      {
        double _x_3_0 = x.hi;
        _x_x3181 = _x_3_0; /*float64*/
      }
      double _x_x3182;
      {
        double _x_0_2_0 = y_10838.hi;
        _x_x3182 = _x_0_2_0; /*float64*/
      }
      double _x_x3183 = (-z); /*float64*/
      err = kk_std_num_float64_fmadd(_x_x3181, _x_x3182, _x_x3183, _ctx); /*float64*/
      kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
      double e;
      double _x_x3184;
      {
        double _x_1_1 = z_0.err;
        _x_x3184 = _x_1_1; /*float64*/
      }
      double _x_x3185;
      double _x_x3186;
      double _x_x3187;
      {
        double _x_2_1 = x.hi;
        _x_x3187 = _x_2_1; /*float64*/
      }
      double _x_x3188;
      {
        double _x_3_0_0 = y_10838.lo;
        _x_x3188 = _x_3_0_0; /*float64*/
      }
      _x_x3186 = (_x_x3187 * _x_x3188); /*float64*/
      double _x_x3189;
      double _x_x3190;
      {
        double _x_4 = x.lo;
        _x_x3190 = _x_4; /*float64*/
      }
      double _x_x3191;
      {
        double _x_5 = y_10838.hi;
        _x_x3191 = _x_5; /*float64*/
      }
      _x_x3189 = (_x_x3190 * _x_x3191); /*float64*/
      _x_x3185 = (_x_x3186 + _x_x3189); /*float64*/
      e = (_x_x3184 + _x_x3185); /*float64*/
      bool b_10040;
      double _x_x3192;
      {
        double _x_6 = z_0.num;
        _x_x3192 = _x_6; /*float64*/
      }
      b_10040 = isfinite(_x_x3192); /*bool*/
      if (b_10040) {
        double z_1;
        double _x_x3193;
        {
          double _x_6_2 = z_0.num;
          _x_x3193 = _x_6_2; /*float64*/
        }
        z_1 = (_x_x3193 + e); /*float64*/
        double err_0;
        double _x_x3194;
        double _x_x3195;
        {
          double _x_6_3 = z_0.num;
          _x_x3195 = _x_6_3; /*float64*/
        }
        _x_x3194 = (z_1 - _x_x3195); /*float64*/
        err_0 = (e - _x_x3194); /*float64*/
        double _x_x3196;
        bool _match_x593 = isfinite(z_1); /*bool*/;
        if (_match_x593) {
          _x_x3196 = err_0; /*float64*/
        }
        else {
          _x_x3196 = z_1; /*float64*/
        }
        return kk_std_num_ddouble__new_Ddouble(z_1, _x_x3196, _ctx);
      }
      {
        double _x_x3197;
        {
          double _x_6_4 = z_0.num;
          _x_x3197 = _x_6_4; /*float64*/
        }
        return kk_std_num_ddouble__new_Ddouble(_x_x3197, 0x0p+0, _ctx);
      }
    }
  }
}
 
// The hyperbolic cosine of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_cosh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x588;
  double _x_x3198;
  {
    double _x = x.hi;
    _x_x3198 = _x; /*float64*/
  }
  _match_x588 = (_x_x3198 == (0x0p+0)); /*bool*/
  if (_match_x588) {
    return kk_std_num_ddouble_one;
  }
  {
    kk_std_num_ddouble__ddouble x_1_10609 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_x589;
    double _x_x3199;
    {
      double _x_0 = x_1_10609.hi;
      _x_x3199 = _x_0; /*float64*/
    }
    _match_x589 = (_x_x3199 > (0x1.999999999999ap-5)); /*bool*/
    if (_match_x589) {
      kk_std_num_ddouble__ddouble ex = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
      bool b_10611;
      bool _match_x590;
      double _x_x3200;
      {
        double _x_1 = ex.hi;
        _x_x3200 = _x_1; /*float64*/
      }
      _match_x590 = isfinite(_x_x3200); /*bool*/
      if (_match_x590) {
        double _x_x3201;
        {
          double _x_0_0 = ex.lo;
          _x_x3201 = _x_0_0; /*float64*/
        }
        b_10611 = isfinite(_x_x3201); /*bool*/
      }
      else {
        b_10611 = false; /*bool*/
      }
      if (b_10611) {
        kk_std_num_ddouble__ddouble x_2_10612;
        kk_std_num_ddouble__ddouble _x_x3202 = kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble_one, ex, _ctx); /*std/num/ddouble/ddouble*/
        x_2_10612 = kk_std_num_ddouble__lp__plus__rp_(ex, _x_x3202, _ctx); /*std/num/ddouble/ddouble*/
        double _x_x3203;
        double _x_x3204;
        {
          double _x_1_0 = x_2_10612.hi;
          _x_x3204 = _x_1_0; /*float64*/
        }
        _x_x3203 = (_x_x3204 * (0x1p-1)); /*float64*/
        double _x_x3205;
        double _x_x3206;
        {
          double _x_2 = x_2_10612.lo;
          _x_x3206 = _x_2; /*float64*/
        }
        _x_x3205 = (_x_x3206 * (0x1p-1)); /*float64*/
        return kk_std_num_ddouble__new_Ddouble(_x_x3203, _x_x3205, _ctx);
      }
      {
        return ex;
      }
    }
    {
      kk_std_num_ddouble__ddouble s = kk_std_num_ddouble_sinh(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x_x3207;
      kk_std_num_ddouble__ddouble _x_x3208 = kk_std_num_ddouble_sqr(s, _ctx); /*std/num/ddouble/ddouble*/
      _x_x3207 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x3208, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble_sqrt(_x_x3207, _ctx);
    }
  }
}
 
// The hyperbolic tangent of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_tanh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x584;
  double _x_x3209;
  {
    double _x = x.hi;
    _x_x3209 = _x; /*float64*/
  }
  _match_x584 = (_x_x3209 == (0x0p+0)); /*bool*/
  if (_match_x584) {
    return kk_std_num_ddouble_zero;
  }
  {
    kk_std_num_ddouble__ddouble x_1_10620 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_x585;
    double _x_x3210;
    {
      double _x_0 = x_1_10620.hi;
      _x_x3210 = _x_0; /*float64*/
    }
    _match_x585 = (_x_x3210 > (0x1.999999999999ap-5)); /*bool*/
    if (_match_x585) {
      kk_std_num_ddouble__ddouble ex = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble iex = kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble_one, ex, _ctx); /*std/num/ddouble/ddouble*/;
      bool _match_x586;
      double _x_x3211;
      {
        double _x_1 = ex.hi;
        _x_x3211 = _x_1; /*float64*/
      }
      _match_x586 = (_x_x3211 == (0x0p+0)); /*bool*/
      if (_match_x586) {
        double _x_x3212;
        double _x_x3213;
        kk_std_num_ddouble__ddouble _x_x3214 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_2 = _x_x3214.hi;
          _x_x3213 = _x_2; /*float64*/
        }
        _x_x3212 = (-_x_x3213); /*float64*/
        double _x_x3215;
        double _x_x3216;
        kk_std_num_ddouble__ddouble _x_x3217 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        {
          double _x_0_0 = _x_x3217.lo;
          _x_x3216 = _x_0_0; /*float64*/
        }
        _x_x3215 = (-_x_x3216); /*float64*/
        return kk_std_num_ddouble__new_Ddouble(_x_x3212, _x_x3215, _ctx);
      }
      {
        bool _match_x587;
        double _x_x3218;
        {
          double _x_2_0 = ex.hi;
          _x_x3218 = _x_2_0; /*float64*/
        }
        _match_x587 = (isinf(_x_x3218) && !signbit(_x_x3218)); /*bool*/
        if (_match_x587) {
          return kk_std_num_ddouble_one;
        }
        {
          kk_std_num_ddouble__ddouble _x_x3219;
          kk_std_num_ddouble__ddouble _x_x3220;
          double _x_x3221;
          double _x_x3222;
          {
            double _x_3 = iex.hi;
            _x_x3222 = _x_3; /*float64*/
          }
          _x_x3221 = (-_x_x3222); /*float64*/
          double _x_x3223;
          double _x_x3224;
          {
            double _x_0_1 = iex.lo;
            _x_x3224 = _x_0_1; /*float64*/
          }
          _x_x3223 = (-_x_x3224); /*float64*/
          _x_x3220 = kk_std_num_ddouble__new_Ddouble(_x_x3221, _x_x3223, _ctx); /*std/num/ddouble/ddouble*/
          _x_x3219 = kk_std_num_ddouble__lp__plus__rp_(ex, _x_x3220, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x3225 = kk_std_num_ddouble__lp__plus__rp_(ex, iex, _ctx); /*std/num/ddouble/ddouble*/
          return kk_std_num_ddouble__lp__fs__rp_(_x_x3219, _x_x3225, _ctx);
        }
      }
    }
    {
      kk_std_num_ddouble__ddouble s = kk_std_num_ddouble_sinh(x, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble c;
      kk_std_num_ddouble__ddouble _x_x3226;
      kk_std_num_ddouble__ddouble _x_x3227 = kk_std_num_ddouble_sqr(s, _ctx); /*std/num/ddouble/ddouble*/
      _x_x3226 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x3227, _ctx); /*std/num/ddouble/ddouble*/
      c = kk_std_num_ddouble_sqrt(_x_x3226, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__fs__rp_(s, c, _ctx);
    }
  }
}
 
// The area hyperbolic sine of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_asinh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_0_10629;
  kk_std_num_ddouble__ddouble _x_x3228;
  kk_std_num_ddouble__ddouble _x_x3229;
  kk_std_num_ddouble__ddouble _x_x3230 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/
  _x_x3229 = kk_std_num_ddouble__lp__plus__rp_(_x_x3230, kk_std_num_ddouble_one, _ctx); /*std/num/ddouble/ddouble*/
  _x_x3228 = kk_std_num_ddouble_sqrt(_x_x3229, _ctx); /*std/num/ddouble/ddouble*/
  x_0_10629 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x3228, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_x578 = kk_std_num_ddouble__lp__lt__eq__rp_(x_0_10629, kk_std_num_ddouble_zero, _ctx); /*bool*/;
  if (_match_x578) {
    bool _match_x583 = kk_std_num_ddouble__lp__eq__eq__rp_(x_0_10629, kk_std_num_ddouble_zero, _ctx); /*bool*/;
    if (_match_x583) {
      return kk_std_num_ddouble_dd_neginf;
    }
    {
      return kk_std_num_ddouble_dd_nan;
    }
  }
  {
    bool _match_x579 = kk_std_num_ddouble__lp__eq__eq__rp_(x_0_10629, kk_std_num_ddouble_one, _ctx); /*bool*/;
    if (_match_x579) {
      return kk_std_num_ddouble_zero;
    }
    {
      bool _match_x580 = kk_std_num_ddouble__lp__eq__eq__rp_(x_0_10629, kk_std_num_ddouble_dd_e, _ctx); /*bool*/;
      if (_match_x580) {
        return kk_std_num_ddouble_one;
      }
      {
        bool _match_x581;
        double _x_x3231;
        {
          double _x = x_0_10629.hi;
          _x_x3231 = _x; /*float64*/
        }
        _match_x581 = (isinf(_x_x3231) && !signbit(_x_x3231)); /*bool*/
        if (_match_x581) {
          return x_0_10629;
        }
        {
          double d_10632;
          double _x_x3232;
          {
            double _x_0 = x_0_10629.hi;
            _x_x3232 = _x_0; /*float64*/
          }
          d_10632 = log(_x_x3232); /*float64*/
          kk_std_num_ddouble__ddouble a0 = kk_std_num_ddouble__new_Ddouble(d_10632, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
          kk_std_num_ddouble__ddouble y_10849;
          kk_std_num_ddouble__ddouble _x_x3233;
          double _x_x3234;
          double _x_x3235;
          {
            double _x_7 = a0.hi;
            _x_x3235 = _x_7; /*float64*/
          }
          _x_x3234 = (-_x_x3235); /*float64*/
          double _x_x3236;
          double _x_x3237;
          {
            double _x_0_1 = a0.lo;
            _x_x3237 = _x_0_1; /*float64*/
          }
          _x_x3236 = (-_x_x3237); /*float64*/
          _x_x3233 = kk_std_num_ddouble__new_Ddouble(_x_x3234, _x_x3236, _ctx); /*std/num/ddouble/ddouble*/
          y_10849 = kk_std_num_ddouble_exp(_x_x3233, _ctx); /*std/num/ddouble/ddouble*/
          double z;
          double _x_x3238;
          {
            double _x_1 = x_0_10629.hi;
            _x_x3238 = _x_1; /*float64*/
          }
          double _x_x3239;
          {
            double _x_0_0 = y_10849.hi;
            _x_x3239 = _x_0_0; /*float64*/
          }
          z = (_x_x3238 * _x_x3239); /*float64*/
          double err;
          double _x_x3240;
          {
            double _x_1_0 = x_0_10629.hi;
            _x_x3240 = _x_1_0; /*float64*/
          }
          double _x_x3241;
          {
            double _x_0_0_0 = y_10849.hi;
            _x_x3241 = _x_0_0_0; /*float64*/
          }
          double _x_x3242 = (-z); /*float64*/
          err = kk_std_num_float64_fmadd(_x_x3240, _x_x3241, _x_x3242, _ctx); /*float64*/
          kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
          double e;
          double _x_x3243;
          {
            double _x_1_0_0 = z_0.err;
            _x_x3243 = _x_1_0_0; /*float64*/
          }
          double _x_x3244;
          double _x_x3245;
          double _x_x3246;
          {
            double _x_2 = x_0_10629.hi;
            _x_x3246 = _x_2; /*float64*/
          }
          double _x_x3247;
          {
            double _x_3 = y_10849.lo;
            _x_x3247 = _x_3; /*float64*/
          }
          _x_x3245 = (_x_x3246 * _x_x3247); /*float64*/
          double _x_x3248;
          double _x_x3249;
          {
            double _x_4 = x_0_10629.lo;
            _x_x3249 = _x_4; /*float64*/
          }
          double _x_x3250;
          {
            double _x_5 = y_10849.hi;
            _x_x3250 = _x_5; /*float64*/
          }
          _x_x3248 = (_x_x3249 * _x_x3250); /*float64*/
          _x_x3244 = (_x_x3245 + _x_x3248); /*float64*/
          e = (_x_x3243 + _x_x3244); /*float64*/
          bool b_10040;
          double _x_x3251;
          {
            double _x_6 = z_0.num;
            _x_x3251 = _x_6; /*float64*/
          }
          b_10040 = isfinite(_x_x3251); /*bool*/
          kk_std_num_ddouble__ddouble x_2_10634;
          if (b_10040) {
            double z_1;
            double _x_x3252;
            {
              double _x_6_0 = z_0.num;
              _x_x3252 = _x_6_0; /*float64*/
            }
            z_1 = (_x_x3252 + e); /*float64*/
            double err_0;
            double _x_x3253;
            double _x_x3254;
            {
              double _x_6_1 = z_0.num;
              _x_x3254 = _x_6_1; /*float64*/
            }
            _x_x3253 = (z_1 - _x_x3254); /*float64*/
            err_0 = (e - _x_x3253); /*float64*/
            double _x_x3255;
            bool _match_x582 = isfinite(z_1); /*bool*/;
            if (_match_x582) {
              _x_x3255 = err_0; /*float64*/
            }
            else {
              _x_x3255 = z_1; /*float64*/
            }
            x_2_10634 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x3255, _ctx); /*std/num/ddouble/ddouble*/
          }
          else {
            double _x_x3256;
            {
              double _x_6_2 = z_0.num;
              _x_x3256 = _x_6_2; /*float64*/
            }
            x_2_10634 = kk_std_num_ddouble__new_Ddouble(_x_x3256, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          }
          kk_std_num_ddouble__ddouble _x_x3257;
          kk_std_num_ddouble__ddouble _x_x3258;
          double _x_x3259;
          double _x_x3260;
          kk_std_num_ddouble__ddouble _x_x3261 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
          {
            double _x_8 = _x_x3261.hi;
            _x_x3260 = _x_8; /*float64*/
          }
          _x_x3259 = (-_x_x3260); /*float64*/
          double _x_x3262;
          double _x_x3263;
          kk_std_num_ddouble__ddouble _x_x3264 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
          {
            double _x_0_2 = _x_x3264.lo;
            _x_x3263 = _x_0_2; /*float64*/
          }
          _x_x3262 = (-_x_x3263); /*float64*/
          _x_x3258 = kk_std_num_ddouble__new_Ddouble(_x_x3259, _x_x3262, _ctx); /*std/num/ddouble/ddouble*/
          _x_x3257 = kk_std_num_ddouble__lp__plus__rp_(x_2_10634, _x_x3258, _ctx); /*std/num/ddouble/ddouble*/
          return kk_std_num_ddouble__lp__plus__rp_(a0, _x_x3257, _ctx);
        }
      }
    }
  }
}
 
// The area hyperbolic cosine of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_acosh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x571 = kk_std_num_ddouble__lp__lt__rp_(x, kk_std_num_ddouble_one, _ctx); /*bool*/;
  if (_match_x571) {
    return kk_std_num_ddouble_dd_nan;
  }
  {
    kk_std_num_ddouble__ddouble x_3_10637 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble x_0_10636;
    kk_std_num_ddouble__ddouble _x_x3265;
    kk_std_num_ddouble__ddouble _x_x3266;
    kk_std_num_ddouble__ddouble _x_x3267;
    double _x_x3268;
    double _x_x3269;
    kk_std_num_ddouble__ddouble _x_x3270 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x = _x_x3270.hi;
      _x_x3269 = _x; /*float64*/
    }
    _x_x3268 = (-_x_x3269); /*float64*/
    double _x_x3271;
    double _x_x3272;
    kk_std_num_ddouble__ddouble _x_x3273 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_0 = _x_x3273.lo;
      _x_x3272 = _x_0; /*float64*/
    }
    _x_x3271 = (-_x_x3272); /*float64*/
    _x_x3267 = kk_std_num_ddouble__new_Ddouble(_x_x3268, _x_x3271, _ctx); /*std/num/ddouble/ddouble*/
    _x_x3266 = kk_std_num_ddouble__lp__plus__rp_(x_3_10637, _x_x3267, _ctx); /*std/num/ddouble/ddouble*/
    _x_x3265 = kk_std_num_ddouble_sqrt(_x_x3266, _ctx); /*std/num/ddouble/ddouble*/
    x_0_10636 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x3265, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_x572 = kk_std_num_ddouble__lp__lt__eq__rp_(x_0_10636, kk_std_num_ddouble_zero, _ctx); /*bool*/;
    if (_match_x572) {
      bool _match_x577 = kk_std_num_ddouble__lp__eq__eq__rp_(x_0_10636, kk_std_num_ddouble_zero, _ctx); /*bool*/;
      if (_match_x577) {
        return kk_std_num_ddouble_dd_neginf;
      }
      {
        return kk_std_num_ddouble_dd_nan;
      }
    }
    {
      bool _match_x573 = kk_std_num_ddouble__lp__eq__eq__rp_(x_0_10636, kk_std_num_ddouble_one, _ctx); /*bool*/;
      if (_match_x573) {
        return kk_std_num_ddouble_zero;
      }
      {
        bool _match_x574 = kk_std_num_ddouble__lp__eq__eq__rp_(x_0_10636, kk_std_num_ddouble_dd_e, _ctx); /*bool*/;
        if (_match_x574) {
          return kk_std_num_ddouble_one;
        }
        {
          bool _match_x575;
          double _x_x3274;
          {
            double _x_1 = x_0_10636.hi;
            _x_x3274 = _x_1; /*float64*/
          }
          _match_x575 = (isinf(_x_x3274) && !signbit(_x_x3274)); /*bool*/
          if (_match_x575) {
            return x_0_10636;
          }
          {
            double d_10641;
            double _x_x3275;
            {
              double _x_0_0 = x_0_10636.hi;
              _x_x3275 = _x_0_0; /*float64*/
            }
            d_10641 = log(_x_x3275); /*float64*/
            kk_std_num_ddouble__ddouble a0 = kk_std_num_ddouble__new_Ddouble(d_10641, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_std_num_ddouble__ddouble y_10854;
            kk_std_num_ddouble__ddouble _x_x3276;
            double _x_x3277;
            double _x_x3278;
            {
              double _x_7 = a0.hi;
              _x_x3278 = _x_7; /*float64*/
            }
            _x_x3277 = (-_x_x3278); /*float64*/
            double _x_x3279;
            double _x_x3280;
            {
              double _x_0_2 = a0.lo;
              _x_x3280 = _x_0_2; /*float64*/
            }
            _x_x3279 = (-_x_x3280); /*float64*/
            _x_x3276 = kk_std_num_ddouble__new_Ddouble(_x_x3277, _x_x3279, _ctx); /*std/num/ddouble/ddouble*/
            y_10854 = kk_std_num_ddouble_exp(_x_x3276, _ctx); /*std/num/ddouble/ddouble*/
            double z;
            double _x_x3281;
            {
              double _x_2 = x_0_10636.hi;
              _x_x3281 = _x_2; /*float64*/
            }
            double _x_x3282;
            {
              double _x_0_1 = y_10854.hi;
              _x_x3282 = _x_0_1; /*float64*/
            }
            z = (_x_x3281 * _x_x3282); /*float64*/
            double err;
            double _x_x3283;
            {
              double _x_2_0 = x_0_10636.hi;
              _x_x3283 = _x_2_0; /*float64*/
            }
            double _x_x3284;
            {
              double _x_0_1_0 = y_10854.hi;
              _x_x3284 = _x_0_1_0; /*float64*/
            }
            double _x_x3285 = (-z); /*float64*/
            err = kk_std_num_float64_fmadd(_x_x3283, _x_x3284, _x_x3285, _ctx); /*float64*/
            kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
            double e;
            double _x_x3286;
            {
              double _x_1_0 = z_0.err;
              _x_x3286 = _x_1_0; /*float64*/
            }
            double _x_x3287;
            double _x_x3288;
            double _x_x3289;
            {
              double _x_2_0_0 = x_0_10636.hi;
              _x_x3289 = _x_2_0_0; /*float64*/
            }
            double _x_x3290;
            {
              double _x_3 = y_10854.lo;
              _x_x3290 = _x_3; /*float64*/
            }
            _x_x3288 = (_x_x3289 * _x_x3290); /*float64*/
            double _x_x3291;
            double _x_x3292;
            {
              double _x_4 = x_0_10636.lo;
              _x_x3292 = _x_4; /*float64*/
            }
            double _x_x3293;
            {
              double _x_5 = y_10854.hi;
              _x_x3293 = _x_5; /*float64*/
            }
            _x_x3291 = (_x_x3292 * _x_x3293); /*float64*/
            _x_x3287 = (_x_x3288 + _x_x3291); /*float64*/
            e = (_x_x3286 + _x_x3287); /*float64*/
            bool b_10040;
            double _x_x3294;
            {
              double _x_6 = z_0.num;
              _x_x3294 = _x_6; /*float64*/
            }
            b_10040 = isfinite(_x_x3294); /*bool*/
            kk_std_num_ddouble__ddouble x_2_10643;
            if (b_10040) {
              double z_1;
              double _x_x3295;
              {
                double _x_6_0 = z_0.num;
                _x_x3295 = _x_6_0; /*float64*/
              }
              z_1 = (_x_x3295 + e); /*float64*/
              double err_0;
              double _x_x3296;
              double _x_x3297;
              {
                double _x_6_1 = z_0.num;
                _x_x3297 = _x_6_1; /*float64*/
              }
              _x_x3296 = (z_1 - _x_x3297); /*float64*/
              err_0 = (e - _x_x3296); /*float64*/
              double _x_x3298;
              bool _match_x576 = isfinite(z_1); /*bool*/;
              if (_match_x576) {
                _x_x3298 = err_0; /*float64*/
              }
              else {
                _x_x3298 = z_1; /*float64*/
              }
              x_2_10643 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x3298, _ctx); /*std/num/ddouble/ddouble*/
            }
            else {
              double _x_x3299;
              {
                double _x_6_2 = z_0.num;
                _x_x3299 = _x_6_2; /*float64*/
              }
              x_2_10643 = kk_std_num_ddouble__new_Ddouble(_x_x3299, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
            }
            kk_std_num_ddouble__ddouble _x_x3300;
            kk_std_num_ddouble__ddouble _x_x3301;
            double _x_x3302;
            double _x_x3303;
            kk_std_num_ddouble__ddouble _x_x3304 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
            {
              double _x_8 = _x_x3304.hi;
              _x_x3303 = _x_8; /*float64*/
            }
            _x_x3302 = (-_x_x3303); /*float64*/
            double _x_x3305;
            double _x_x3306;
            kk_std_num_ddouble__ddouble _x_x3307 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
            {
              double _x_0_3 = _x_x3307.lo;
              _x_x3306 = _x_0_3; /*float64*/
            }
            _x_x3305 = (-_x_x3306); /*float64*/
            _x_x3301 = kk_std_num_ddouble__new_Ddouble(_x_x3302, _x_x3305, _ctx); /*std/num/ddouble/ddouble*/
            _x_x3300 = kk_std_num_ddouble__lp__plus__rp_(x_2_10643, _x_x3301, _ctx); /*std/num/ddouble/ddouble*/
            return kk_std_num_ddouble__lp__plus__rp_(a0, _x_x3300, _ctx);
          }
        }
      }
    }
  }
}
 
// The area hyperbolic tangent of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_atanh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_0_10645 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_core_types__order x_1_10647;
  kk_std_core_types__order _match_x570;
  double _x_x3308;
  {
    double _x = x_0_10645.hi;
    _x_x3308 = _x; /*float64*/
  }
  double _x_x3309;
  kk_std_num_ddouble__ddouble _x_x3310 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
  {
    double _x_0 = _x_x3310.hi;
    _x_x3309 = _x_0; /*float64*/
  }
  _match_x570 = kk_std_num_float64_cmp(_x_x3308, _x_x3309, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x570, _ctx)) {
    double _x_x3311;
    {
      double _x_1 = x_0_10645.lo;
      _x_x3311 = _x_1; /*float64*/
    }
    double _x_x3312;
    kk_std_num_ddouble__ddouble _x_x3313 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
    {
      double _x_2 = _x_x3313.lo;
      _x_x3312 = _x_2; /*float64*/
    }
    x_1_10647 = kk_std_num_float64_cmp(_x_x3311, _x_x3312, _ctx); /*order*/
  }
  else {
    x_1_10647 = _match_x570; /*order*/
  }
  bool _match_x561;
  kk_integer_t _brw_x568;
  if (kk_std_core_types__is_Lt(x_1_10647, _ctx)) {
    _brw_x568 = kk_integer_from_small(-1); /*int*/
    goto _match_x3314;
  }
  if (kk_std_core_types__is_Eq(x_1_10647, _ctx)) {
    _brw_x568 = kk_integer_from_small(0); /*int*/
    goto _match_x3314;
  }
  {
    _brw_x568 = kk_integer_from_small(1); /*int*/
  }
  _match_x3314: ;
  bool _brw_x569 = kk_integer_eq_borrow(_brw_x568,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x568, _ctx);
  _match_x561 = _brw_x569; /*bool*/
  if (_match_x561) {
    return kk_std_num_ddouble_dd_nan;
  }
  {
    kk_std_num_ddouble__ddouble x_4_10650;
    kk_std_num_ddouble__ddouble _x_x3315 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, x, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x3316;
    kk_std_num_ddouble__ddouble _x_x3317;
    double _x_x3318;
    double _x_x3319;
    {
      double _x_3 = x.hi;
      _x_x3319 = _x_3; /*float64*/
    }
    _x_x3318 = (-_x_x3319); /*float64*/
    double _x_x3320;
    double _x_x3321;
    {
      double _x_0_0 = x.lo;
      _x_x3321 = _x_0_0; /*float64*/
    }
    _x_x3320 = (-_x_x3321); /*float64*/
    _x_x3317 = kk_std_num_ddouble__new_Ddouble(_x_x3318, _x_x3320, _ctx); /*std/num/ddouble/ddouble*/
    _x_x3316 = kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble_one, _x_x3317, _ctx); /*std/num/ddouble/ddouble*/
    x_4_10650 = kk_std_num_ddouble__lp__fs__rp_(_x_x3315, _x_x3316, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble x_2_10649;
    bool _match_x562 = kk_std_num_ddouble__lp__lt__eq__rp_(x_4_10650, kk_std_num_ddouble_zero, _ctx); /*bool*/;
    if (_match_x562) {
      bool _match_x567 = kk_std_num_ddouble__lp__eq__eq__rp_(x_4_10650, kk_std_num_ddouble_zero, _ctx); /*bool*/;
      if (_match_x567) {
        x_2_10649 = kk_std_num_ddouble_dd_neginf; /*std/num/ddouble/ddouble*/
      }
      else {
        x_2_10649 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
    }
    else {
      bool _match_x563 = kk_std_num_ddouble__lp__eq__eq__rp_(x_4_10650, kk_std_num_ddouble_one, _ctx); /*bool*/;
      if (_match_x563) {
        x_2_10649 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
      }
      else {
        bool _match_x564 = kk_std_num_ddouble__lp__eq__eq__rp_(x_4_10650, kk_std_num_ddouble_dd_e, _ctx); /*bool*/;
        if (_match_x564) {
          x_2_10649 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        }
        else {
          bool _match_x565;
          double _x_x3322;
          {
            double _x_1_0 = x_4_10650.hi;
            _x_x3322 = _x_1_0; /*float64*/
          }
          _match_x565 = (isinf(_x_x3322) && !signbit(_x_x3322)); /*bool*/
          if (_match_x565) {
            x_2_10649 = x_4_10650; /*std/num/ddouble/ddouble*/
          }
          else {
            double d_10655;
            double _x_x3323;
            {
              double _x_2_0 = x_4_10650.hi;
              _x_x3323 = _x_2_0; /*float64*/
            }
            d_10655 = log(_x_x3323); /*float64*/
            kk_std_num_ddouble__ddouble a0 = kk_std_num_ddouble__new_Ddouble(d_10655, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
            kk_std_num_ddouble__ddouble y_0_10861;
            kk_std_num_ddouble__ddouble _x_x3324;
            double _x_x3325;
            double _x_x3326;
            {
              double _x_7 = a0.hi;
              _x_x3326 = _x_7; /*float64*/
            }
            _x_x3325 = (-_x_x3326); /*float64*/
            double _x_x3327;
            double _x_x3328;
            {
              double _x_0_2 = a0.lo;
              _x_x3328 = _x_0_2; /*float64*/
            }
            _x_x3327 = (-_x_x3328); /*float64*/
            _x_x3324 = kk_std_num_ddouble__new_Ddouble(_x_x3325, _x_x3327, _ctx); /*std/num/ddouble/ddouble*/
            y_0_10861 = kk_std_num_ddouble_exp(_x_x3324, _ctx); /*std/num/ddouble/ddouble*/
            double z;
            double _x_x3329;
            {
              double _x_4 = x_4_10650.hi;
              _x_x3329 = _x_4; /*float64*/
            }
            double _x_x3330;
            {
              double _x_0_1 = y_0_10861.hi;
              _x_x3330 = _x_0_1; /*float64*/
            }
            z = (_x_x3329 * _x_x3330); /*float64*/
            double err;
            double _x_x3331;
            {
              double _x_4_0 = x_4_10650.hi;
              _x_x3331 = _x_4_0; /*float64*/
            }
            double _x_x3332;
            {
              double _x_0_1_0 = y_0_10861.hi;
              _x_x3332 = _x_0_1_0; /*float64*/
            }
            double _x_x3333 = (-z); /*float64*/
            err = kk_std_num_float64_fmadd(_x_x3331, _x_x3332, _x_x3333, _ctx); /*float64*/
            kk_std_num_ddouble__edouble z_0 = kk_std_num_ddouble__new_Edouble(z, err, _ctx); /*std/num/ddouble/edouble*/;
            double e;
            double _x_x3334;
            {
              double _x_1_1 = z_0.err;
              _x_x3334 = _x_1_1; /*float64*/
            }
            double _x_x3335;
            double _x_x3336;
            double _x_x3337;
            {
              double _x_2_1 = x_4_10650.hi;
              _x_x3337 = _x_2_1; /*float64*/
            }
            double _x_x3338;
            {
              double _x_3_0 = y_0_10861.lo;
              _x_x3338 = _x_3_0; /*float64*/
            }
            _x_x3336 = (_x_x3337 * _x_x3338); /*float64*/
            double _x_x3339;
            double _x_x3340;
            {
              double _x_4_0_0 = x_4_10650.lo;
              _x_x3340 = _x_4_0_0; /*float64*/
            }
            double _x_x3341;
            {
              double _x_5 = y_0_10861.hi;
              _x_x3341 = _x_5; /*float64*/
            }
            _x_x3339 = (_x_x3340 * _x_x3341); /*float64*/
            _x_x3335 = (_x_x3336 + _x_x3339); /*float64*/
            e = (_x_x3334 + _x_x3335); /*float64*/
            bool b_10040;
            double _x_x3342;
            {
              double _x_6 = z_0.num;
              _x_x3342 = _x_6; /*float64*/
            }
            b_10040 = isfinite(_x_x3342); /*bool*/
            kk_std_num_ddouble__ddouble x_6_10657;
            if (b_10040) {
              double z_1;
              double _x_x3343;
              {
                double _x_6_0 = z_0.num;
                _x_x3343 = _x_6_0; /*float64*/
              }
              z_1 = (_x_x3343 + e); /*float64*/
              double err_0;
              double _x_x3344;
              double _x_x3345;
              {
                double _x_6_1 = z_0.num;
                _x_x3345 = _x_6_1; /*float64*/
              }
              _x_x3344 = (z_1 - _x_x3345); /*float64*/
              err_0 = (e - _x_x3344); /*float64*/
              double _x_x3346;
              bool _match_x566 = isfinite(z_1); /*bool*/;
              if (_match_x566) {
                _x_x3346 = err_0; /*float64*/
              }
              else {
                _x_x3346 = z_1; /*float64*/
              }
              x_6_10657 = kk_std_num_ddouble__new_Ddouble(z_1, _x_x3346, _ctx); /*std/num/ddouble/ddouble*/
            }
            else {
              double _x_x3347;
              {
                double _x_6_2 = z_0.num;
                _x_x3347 = _x_6_2; /*float64*/
              }
              x_6_10657 = kk_std_num_ddouble__new_Ddouble(_x_x3347, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
            }
            kk_std_num_ddouble__ddouble _x_x3348;
            kk_std_num_ddouble__ddouble _x_x3349;
            double _x_x3350;
            double _x_x3351;
            kk_std_num_ddouble__ddouble _x_x3352 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
            {
              double _x_8 = _x_x3352.hi;
              _x_x3351 = _x_8; /*float64*/
            }
            _x_x3350 = (-_x_x3351); /*float64*/
            double _x_x3353;
            double _x_x3354;
            kk_std_num_ddouble__ddouble _x_x3355 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
            {
              double _x_0_3 = _x_x3355.lo;
              _x_x3354 = _x_0_3; /*float64*/
            }
            _x_x3353 = (-_x_x3354); /*float64*/
            _x_x3349 = kk_std_num_ddouble__new_Ddouble(_x_x3350, _x_x3353, _ctx); /*std/num/ddouble/ddouble*/
            _x_x3348 = kk_std_num_ddouble__lp__plus__rp_(x_6_10657, _x_x3349, _ctx); /*std/num/ddouble/ddouble*/
            x_2_10649 = kk_std_num_ddouble__lp__plus__rp_(a0, _x_x3348, _ctx); /*std/num/ddouble/ddouble*/
          }
        }
      }
    }
    double _x_x3356;
    double _x_x3357;
    {
      double _x_9 = x_2_10649.hi;
      _x_x3357 = _x_9; /*float64*/
    }
    _x_x3356 = (_x_x3357 * (0x1p-1)); /*float64*/
    double _x_x3358;
    double _x_x3359;
    {
      double _x_0_4 = x_2_10649.lo;
      _x_x3359 = _x_0_4; /*float64*/
    }
    _x_x3358 = (_x_x3359 * (0x1p-1)); /*float64*/
    return kk_std_num_ddouble__new_Ddouble(_x_x3356, _x_x3358, _ctx);
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
    kk_box_t _x_x1652;
    kk_std_num_ddouble__ddouble _x_x1653 = kk_std_num_ddouble__new_Ddouble(0x1.5555555555555p-3, 0x1.5555555555555p-57, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1652 = kk_std_num_ddouble__ddouble_box(_x_x1653, _ctx); /*10021*/
    kk_std_core_types__list _x_x1654;
    kk_box_t _x_x1655;
    kk_std_num_ddouble__ddouble _x_x1656 = kk_std_num_ddouble__new_Ddouble(0x1.5555555555555p-5, 0x1.5555555555555p-59, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1655 = kk_std_num_ddouble__ddouble_box(_x_x1656, _ctx); /*10021*/
    kk_std_core_types__list _x_x1657;
    kk_box_t _x_x1658;
    kk_std_num_ddouble__ddouble _x_x1659 = kk_std_num_ddouble__new_Ddouble(0x1.1111111111111p-7, 0x1.1111111111111p-63, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1658 = kk_std_num_ddouble__ddouble_box(_x_x1659, _ctx); /*10021*/
    kk_std_core_types__list _x_x1660;
    kk_box_t _x_x1661;
    kk_std_num_ddouble__ddouble _x_x1662 = kk_std_num_ddouble__new_Ddouble(0x1.6c16c16c16c17p-10, -0x1.f49f49f49f49fp-65, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1661 = kk_std_num_ddouble__ddouble_box(_x_x1662, _ctx); /*10021*/
    kk_std_core_types__list _x_x1663;
    kk_box_t _x_x1664;
    kk_std_num_ddouble__ddouble _x_x1665 = kk_std_num_ddouble__new_Ddouble(0x1.a01a01a01a01ap-13, 0x1.a01a01a01a01ap-73, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1664 = kk_std_num_ddouble__ddouble_box(_x_x1665, _ctx); /*10021*/
    kk_std_core_types__list _x_x1666;
    kk_box_t _x_x1667;
    kk_std_num_ddouble__ddouble _x_x1668 = kk_std_num_ddouble__new_Ddouble(0x1.a01a01a01a01ap-16, 0x1.a01a01a01a01ap-76, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1667 = kk_std_num_ddouble__ddouble_box(_x_x1668, _ctx); /*10021*/
    _x_x1666 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1667, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1663 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1664, _x_x1666, _ctx); /*list<10021>*/
    _x_x1660 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1661, _x_x1663, _ctx); /*list<10021>*/
    _x_x1657 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1658, _x_x1660, _ctx); /*list<10021>*/
    _x_x1654 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1655, _x_x1657, _ctx); /*list<10021>*/
    kk_std_num_ddouble_exp_factors = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1652, _x_x1654, _ctx); /*list<std/num/ddouble/ddouble>*/
  }
  {
    kk_std_num_ddouble_one_half = kk_std_num_ddouble__new_Ddouble(0x1p-1, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_box_t _x_x2670;
    kk_std_num_ddouble__ddouble _x_x2671 = kk_std_num_ddouble__new_Ddouble(0x1.6116039167de1p-33, 0x1.ea9f4c1702653p-88, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2670 = kk_std_num_ddouble__ddouble_box(_x_x2671, _ctx); /*10021*/
    kk_std_core_types__list _x_x2672;
    kk_box_t _x_x2673;
    kk_std_num_ddouble__ddouble _x_x2674 = kk_std_num_ddouble__new_Ddouble(-0x1.ae64561f4804fp-26, -0x1.c5104f49cf934p-82, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2673 = kk_std_num_ddouble__ddouble_box(_x_x2674, _ctx); /*10021*/
    kk_std_core_types__list _x_x2675;
    kk_box_t _x_x2676;
    kk_std_num_ddouble__ddouble _x_x2677 = kk_std_num_ddouble__new_Ddouble(0x1.71de3a556b36bp-19, -0x1.eb33da7509008p-73, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2676 = kk_std_num_ddouble__ddouble_box(_x_x2677, _ctx); /*10021*/
    kk_std_core_types__list _x_x2678;
    kk_box_t _x_x2679;
    kk_std_num_ddouble__ddouble _x_x2680 = kk_std_num_ddouble__new_Ddouble(-0x1.a01a01a01a01ap-13, 0x1.0313e2634850bp-67, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2679 = kk_std_num_ddouble__ddouble_box(_x_x2680, _ctx); /*10021*/
    kk_std_core_types__list _x_x2681;
    kk_box_t _x_x2682;
    kk_std_num_ddouble__ddouble _x_x2683 = kk_std_num_ddouble__new_Ddouble(0x1.1111111111111p-7, 0x1.110a7e6657814p-63, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2682 = kk_std_num_ddouble__ddouble_box(_x_x2683, _ctx); /*10021*/
    kk_std_core_types__list _x_x2684;
    kk_box_t _x_x2685;
    kk_std_num_ddouble__ddouble _x_x2686 = kk_std_num_ddouble__new_Ddouble(-0x1.5555555555555p-3, -0x1.5555555162e8fp-57, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2685 = kk_std_num_ddouble__ddouble_box(_x_x2686, _ctx); /*10021*/
    kk_std_core_types__list _x_x2687;
    kk_box_t _x_x2688;
    kk_std_num_ddouble__ddouble _x_x2689 = kk_std_num_ddouble__new_Ddouble(0x1p0, -0x1.86fa265ab5ed7p-101, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2688 = kk_std_num_ddouble__ddouble_box(_x_x2689, _ctx); /*10021*/
    _x_x2687 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2688, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x2684 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2685, _x_x2687, _ctx); /*list<10021>*/
    _x_x2681 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2682, _x_x2684, _ctx); /*list<10021>*/
    _x_x2678 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2679, _x_x2681, _ctx); /*list<10021>*/
    _x_x2675 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2676, _x_x2678, _ctx); /*list<10021>*/
    _x_x2672 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2673, _x_x2675, _ctx); /*list<10021>*/
    kk_std_num_ddouble_ch_factors = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2670, _x_x2672, _ctx); /*list<std/num/ddouble/ddouble>*/
  }
  {
    kk_box_t _x_x2690;
    kk_std_num_ddouble__ddouble _x_x2691 = kk_std_num_ddouble__new_Ddouble(0x1.8f8b83c69a60bp-3, -0x1.26d19b9ff8d82p-57, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2690 = kk_std_num_ddouble__ddouble_box(_x_x2691, _ctx); /*10021*/
    kk_box_t _x_x2692;
    kk_std_num_ddouble__ddouble _x_x2693 = kk_std_num_ddouble__new_Ddouble(0x1.87de2a6aea963p-2, -0x1.72cedd3d5a61p-57, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2692 = kk_std_num_ddouble__ddouble_box(_x_x2693, _ctx); /*10021*/
    kk_box_t _x_x2694;
    kk_std_num_ddouble__ddouble _x_x2695 = kk_std_num_ddouble__new_Ddouble(0x1.1c73b39ae68c8p-1, 0x1.b25dd267f66p-55, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2694 = kk_std_num_ddouble__ddouble_box(_x_x2695, _ctx); /*10021*/
    kk_box_t _x_x2696;
    kk_std_num_ddouble__ddouble _x_x2697 = kk_std_num_ddouble__new_Ddouble(0x1.6a09e667f3bcdp-1, -0x1.bdd3413b26455p-55, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2696 = kk_std_num_ddouble__ddouble_box(_x_x2697, _ctx); /*10021*/
    kk_box_t _x_x2698;
    kk_std_num_ddouble__ddouble _x_x2699 = kk_std_num_ddouble__new_Ddouble(0x1.a9b66290ea1a3p-1, 0x1.9f630e8b6dafp-60, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2698 = kk_std_num_ddouble__ddouble_box(_x_x2699, _ctx); /*10021*/
    kk_box_t _x_x2700;
    kk_std_num_ddouble__ddouble _x_x2701 = kk_std_num_ddouble__new_Ddouble(0x1.d906bcf328d46p-1, 0x1.457e610231ac4p-56, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2700 = kk_std_num_ddouble__ddouble_box(_x_x2701, _ctx); /*10021*/
    kk_box_t _x_x2702;
    kk_std_num_ddouble__ddouble _x_x2703 = kk_std_num_ddouble__new_Ddouble(0x1.f6297cff75cbp-1, 0x1.562172a361fd6p-56, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2702 = kk_std_num_ddouble__ddouble_box(_x_x2703, _ctx); /*10021*/
    kk_vector_t _vec_x2704 = kk_std_core_vector__unsafe_vector((KK_IZ(9)), _ctx);
    kk_box_t* _buf_x2705 = kk_vector_buf_borrow(_vec_x2704, NULL, _ctx);
    _buf_x2705[0] = kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx);
    _buf_x2705[1] = _x_x2690;
    _buf_x2705[2] = _x_x2692;
    _buf_x2705[3] = _x_x2694;
    _buf_x2705[4] = _x_x2696;
    _buf_x2705[5] = _x_x2698;
    _buf_x2705[6] = _x_x2700;
    _buf_x2705[7] = _x_x2702;
    _buf_x2705[8] = kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_one, _ctx);
    kk_std_num_ddouble_sin16_table = _vec_x2704; /*vector<std/num/ddouble/ddouble>*/
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
