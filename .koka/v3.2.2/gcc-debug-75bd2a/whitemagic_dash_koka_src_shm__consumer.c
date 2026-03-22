// Koka generated module: whitemagic-koka/src/shm_consumer, koka version: 3.2.2, platform: 64-bit
#include "whitemagic_dash_koka_src_shm__consumer.h"
#ifndef SHM_CONSUMER_H
#define SHM_CONSUMER_H

#include <kklib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

static inline int64_t kk_shm_open_map(kk_string_t name, kk_integer_t size, kk_context_t* ctx) {
    const char* c_name = kk_string_cbuf_borrow(name, NULL, ctx);
    int fd = shm_open(c_name, O_RDWR, 0666);
    kk_string_drop(name, ctx);
    if (fd < 0) return 0;
    
    intptr_t sz = kk_integer_clamp_ssize_t(size, ctx);
    void* addr = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    if (addr == MAP_FAILED) return 0;
    return (int64_t)addr;
}

static inline kk_integer_t kk_shm_unmap(int64_t addr, kk_integer_t size, kk_context_t* ctx) {
    intptr_t sz = kk_integer_clamp_ssize_t(size, ctx);
    int res = munmap((void*)addr, sz);
    return kk_integer_from_int(res, ctx);
}

static inline kk_integer_t kk_shm_read_int(int64_t addr, kk_integer_t offset, kk_context_t* ctx) {
    intptr_t off = kk_integer_clamp_ssize_t(offset, ctx);
    int32_t val = *(int32_t*)(addr + off);
    return kk_integer_from_int(val, ctx);
}

static inline int64_t kk_shm_read_int64(int64_t addr, kk_integer_t offset, kk_context_t* ctx) {
    intptr_t off = kk_integer_clamp_ssize_t(offset, ctx);
    return *(int64_t*)(addr + off);
}

static inline double kk_shm_read_double(int64_t addr, kk_integer_t offset, kk_context_t* ctx) {
    intptr_t off = kk_integer_clamp_ssize_t(offset, ctx);
    return *(double*)(addr + off);
}

#endif\n

kk_unit_t kk_whitemagic_dash_koka_src_shm__consumer_flush_stdout(kk_context_t* _ctx) { /* () -> console/console () */ 
  fflush(stdout); return kk_Unit;
}
 
// Open and map shared memory, returns pointer (0 on error)

int64_t kk_whitemagic_dash_koka_src_shm__consumer_shm_open_map(kk_string_t name, kk_integer_t size, kk_context_t* _ctx) { /* (name : string, size : int) -> int64 */ 
  return kk_shm_open_map(name,size,kk_context());
}
 
// Unmap shared memory

kk_integer_t kk_whitemagic_dash_koka_src_shm__consumer_shm_unmap(int64_t addr, kk_integer_t size, kk_context_t* _ctx) { /* (addr : int64, size : int) -> int */ 
  return kk_shm_unmap(addr,size,kk_context());
}
 
// Read int32 at offset

kk_integer_t kk_whitemagic_dash_koka_src_shm__consumer_shm_read_int(int64_t addr, kk_integer_t offset, kk_context_t* _ctx) { /* (addr : int64, offset : int) -> int */ 
  return kk_shm_read_int(addr,offset,kk_context());
}
 
// Read int64 at offset

int64_t kk_whitemagic_dash_koka_src_shm__consumer_shm_read_int64(int64_t addr, kk_integer_t offset, kk_context_t* _ctx) { /* (addr : int64, offset : int) -> int64 */ 
  return kk_shm_read_int64(addr,offset,kk_context());
}
 
// Read double at offset

double kk_whitemagic_dash_koka_src_shm__consumer_shm_read_double(int64_t addr, kk_integer_t offset, kk_context_t* _ctx) { /* (addr : int64, offset : int) -> float64 */ 
  return kk_shm_read_double(addr,offset,kk_context());
}
kk_declare_string_literal(static, kk_whitemagic_dash_koka_src_shm__consumer_shm_name, 23, "whitemagic_embed_bridge")

kk_integer_t kk_whitemagic_dash_koka_src_shm__consumer_segment_size;

kk_integer_t kk_whitemagic_dash_koka_src_shm__consumer_header_size;

kk_integer_t kk_whitemagic_dash_koka_src_shm__consumer_slot_size;

kk_integer_t kk_whitemagic_dash_koka_src_shm__consumer_embedding_dim;

kk_integer_t kk_whitemagic_dash_koka_src_shm__consumer_magic_number;

kk_whitemagic_dash_koka_src_shm__consumer__shm_header kk_whitemagic_dash_koka_src_shm__consumer_shm_header_fs__copy(kk_whitemagic_dash_koka_src_shm__consumer__shm_header _this, kk_std_core_types__optional magic, kk_std_core_types__optional version, kk_std_core_types__optional capacity, kk_std_core_types__optional count, kk_std_core_types__optional write_pos, kk_std_core_types__optional read_pos, kk_context_t* _ctx) { /* (shm-header, magic : ? int, version : ? int, capacity : ? int, count : ? int, write-pos : ? int, read-pos : ? int) -> shm-header */ 
  kk_integer_t _x_x211;
  if (kk_std_core_types__is_Optional(magic, _ctx)) {
    kk_box_t _box_x0 = magic._cons._Optional.value;
    kk_integer_t _uniq_magic_142 = kk_integer_unbox(_box_x0, _ctx);
    kk_integer_dup(_uniq_magic_142, _ctx);
    kk_std_core_types__optional_drop(magic, _ctx);
    _x_x211 = _uniq_magic_142; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(magic, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x212 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _x = _con_x212->magic;
      kk_integer_dup(_x, _ctx);
      _x_x211 = _x; /*int*/
    }
  }
  kk_integer_t _x_x213;
  if (kk_std_core_types__is_Optional(version, _ctx)) {
    kk_box_t _box_x1 = version._cons._Optional.value;
    kk_integer_t _uniq_version_150 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_version_150, _ctx);
    kk_std_core_types__optional_drop(version, _ctx);
    _x_x213 = _uniq_version_150; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(version, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x214 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _x_0 = _con_x214->version;
      kk_integer_dup(_x_0, _ctx);
      _x_x213 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x215;
  if (kk_std_core_types__is_Optional(capacity, _ctx)) {
    kk_box_t _box_x2 = capacity._cons._Optional.value;
    kk_integer_t _uniq_capacity_158 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_capacity_158, _ctx);
    kk_std_core_types__optional_drop(capacity, _ctx);
    _x_x215 = _uniq_capacity_158; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(capacity, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x216 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _x_1 = _con_x216->capacity;
      kk_integer_dup(_x_1, _ctx);
      _x_x215 = _x_1; /*int*/
    }
  }
  kk_integer_t _x_x217;
  if (kk_std_core_types__is_Optional(count, _ctx)) {
    kk_box_t _box_x3 = count._cons._Optional.value;
    kk_integer_t _uniq_count_166 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_count_166, _ctx);
    kk_std_core_types__optional_drop(count, _ctx);
    _x_x217 = _uniq_count_166; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(count, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x218 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _x_2 = _con_x218->count;
      kk_integer_dup(_x_2, _ctx);
      _x_x217 = _x_2; /*int*/
    }
  }
  kk_integer_t _x_x219;
  if (kk_std_core_types__is_Optional(write_pos, _ctx)) {
    kk_box_t _box_x4 = write_pos._cons._Optional.value;
    kk_integer_t _uniq_write_pos_174 = kk_integer_unbox(_box_x4, _ctx);
    kk_integer_dup(_uniq_write_pos_174, _ctx);
    kk_std_core_types__optional_drop(write_pos, _ctx);
    _x_x219 = _uniq_write_pos_174; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(write_pos, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x220 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _x_3 = _con_x220->write_pos;
      kk_integer_dup(_x_3, _ctx);
      _x_x219 = _x_3; /*int*/
    }
  }
  kk_integer_t _x_x221;
  if (kk_std_core_types__is_Optional(read_pos, _ctx)) {
    kk_box_t _box_x5 = read_pos._cons._Optional.value;
    kk_integer_t _uniq_read_pos_182 = kk_integer_unbox(_box_x5, _ctx);
    kk_integer_dup(_uniq_read_pos_182, _ctx);
    kk_std_core_types__optional_drop(read_pos, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(6)), _ctx);
    _x_x221 = _uniq_read_pos_182; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(read_pos, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x222 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _pat_0_5 = _con_x222->magic;
      kk_integer_t _pat_1_6 = _con_x222->version;
      kk_integer_t _pat_2_5 = _con_x222->capacity;
      kk_integer_t _pat_3_5 = _con_x222->count;
      kk_integer_t _pat_4_5 = _con_x222->write_pos;
      kk_integer_t _x_4 = _con_x222->read_pos;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_4_5, _ctx);
        kk_integer_drop(_pat_3_5, _ctx);
        kk_integer_drop(_pat_2_5, _ctx);
        kk_integer_drop(_pat_1_6, _ctx);
        kk_integer_drop(_pat_0_5, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_4, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x221 = _x_4; /*int*/
    }
  }
  return kk_whitemagic_dash_koka_src_shm__consumer__new_Shm_header(kk_reuse_null, 0, _x_x211, _x_x213, _x_x215, _x_x217, _x_x219, _x_x221, _ctx);
}

kk_whitemagic_dash_koka_src_shm__consumer__shm_header kk_whitemagic_dash_koka_src_shm__consumer_read_header(int64_t addr, kk_context_t* _ctx) { /* (addr : int64) -> shm-header */ 
  kk_integer_t _x_x223 = kk_whitemagic_dash_koka_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(0), _ctx); /*int*/
  kk_integer_t _x_x224 = kk_whitemagic_dash_koka_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(4), _ctx); /*int*/
  kk_integer_t _x_x225 = kk_whitemagic_dash_koka_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(8), _ctx); /*int*/
  kk_integer_t _x_x226 = kk_whitemagic_dash_koka_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(12), _ctx); /*int*/
  kk_integer_t _x_x227 = kk_whitemagic_dash_koka_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(16), _ctx); /*int*/
  kk_integer_t _x_x228 = kk_whitemagic_dash_koka_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(20), _ctx); /*int*/
  return kk_whitemagic_dash_koka_src_shm__consumer__new_Shm_header(kk_reuse_null, 0, _x_x223, _x_x224, _x_x225, _x_x226, _x_x227, _x_x228, _ctx);
}

kk_string_t kk_whitemagic_dash_koka_src_shm__consumer_json_header(kk_whitemagic_dash_koka_src_shm__consumer__shm_header h, kk_context_t* _ctx) { /* (h : shm-header) -> string */ 
  kk_string_t _x_x229;
  kk_define_string_literal(, _s_x230, 9, "{\"magic\":", _ctx)
  _x_x229 = kk_string_dup(_s_x230, _ctx); /*string*/
  kk_string_t _x_x231;
  kk_string_t _x_x232;
  kk_integer_t _x_x233;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x234 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _x = _con_x234->magic;
    kk_integer_dup(_x, _ctx);
    _x_x233 = _x; /*int*/
  }
  _x_x232 = kk_std_core_int_show(_x_x233, _ctx); /*string*/
  kk_string_t _x_x235;
  kk_string_t _x_x236;
  kk_define_string_literal(, _s_x237, 11, ",\"version\":", _ctx)
  _x_x236 = kk_string_dup(_s_x237, _ctx); /*string*/
  kk_string_t _x_x238;
  kk_string_t _x_x239;
  kk_integer_t _x_x240;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x241 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _x_0 = _con_x241->version;
    kk_integer_dup(_x_0, _ctx);
    _x_x240 = _x_0; /*int*/
  }
  _x_x239 = kk_std_core_int_show(_x_x240, _ctx); /*string*/
  kk_string_t _x_x242;
  kk_string_t _x_x243;
  kk_define_string_literal(, _s_x244, 12, ",\"capacity\":", _ctx)
  _x_x243 = kk_string_dup(_s_x244, _ctx); /*string*/
  kk_string_t _x_x245;
  kk_string_t _x_x246;
  kk_integer_t _x_x247;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x248 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _x_1 = _con_x248->capacity;
    kk_integer_dup(_x_1, _ctx);
    _x_x247 = _x_1; /*int*/
  }
  _x_x246 = kk_std_core_int_show(_x_x247, _ctx); /*string*/
  kk_string_t _x_x249;
  kk_string_t _x_x250;
  kk_define_string_literal(, _s_x251, 9, ",\"count\":", _ctx)
  _x_x250 = kk_string_dup(_s_x251, _ctx); /*string*/
  kk_string_t _x_x252;
  kk_string_t _x_x253;
  kk_integer_t _x_x254;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x255 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _x_2 = _con_x255->count;
    kk_integer_dup(_x_2, _ctx);
    _x_x254 = _x_2; /*int*/
  }
  _x_x253 = kk_std_core_int_show(_x_x254, _ctx); /*string*/
  kk_string_t _x_x256;
  kk_string_t _x_x257;
  kk_define_string_literal(, _s_x258, 13, ",\"write_pos\":", _ctx)
  _x_x257 = kk_string_dup(_s_x258, _ctx); /*string*/
  kk_string_t _x_x259;
  kk_string_t _x_x260;
  kk_integer_t _x_x261;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x262 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _x_3 = _con_x262->write_pos;
    kk_integer_dup(_x_3, _ctx);
    _x_x261 = _x_3; /*int*/
  }
  _x_x260 = kk_std_core_int_show(_x_x261, _ctx); /*string*/
  kk_string_t _x_x263;
  kk_string_t _x_x264;
  kk_define_string_literal(, _s_x265, 12, ",\"read_pos\":", _ctx)
  _x_x264 = kk_string_dup(_s_x265, _ctx); /*string*/
  kk_string_t _x_x266;
  kk_string_t _x_x267;
  kk_integer_t _x_x268;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x269 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _pat_0_4 = _con_x269->magic;
    kk_integer_t _pat_1_4 = _con_x269->version;
    kk_integer_t _pat_2_4 = _con_x269->capacity;
    kk_integer_t _pat_3_4 = _con_x269->count;
    kk_integer_t _pat_4_4 = _con_x269->write_pos;
    kk_integer_t _x_4 = _con_x269->read_pos;
    if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
      kk_integer_drop(_pat_4_4, _ctx);
      kk_integer_drop(_pat_3_4, _ctx);
      kk_integer_drop(_pat_2_4, _ctx);
      kk_integer_drop(_pat_1_4, _ctx);
      kk_integer_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(h, _ctx);
    }
    else {
      kk_integer_dup(_x_4, _ctx);
      kk_datatype_ptr_decref(h, _ctx);
    }
    _x_x268 = _x_4; /*int*/
  }
  _x_x267 = kk_std_core_int_show(_x_x268, _ctx); /*string*/
  kk_string_t _x_x270;
  kk_define_string_literal(, _s_x271, 1, "}", _ctx)
  _x_x270 = kk_string_dup(_s_x271, _ctx); /*string*/
  _x_x266 = kk_std_core_types__lp__plus__plus__rp_(_x_x267, _x_x270, _ctx); /*string*/
  _x_x263 = kk_std_core_types__lp__plus__plus__rp_(_x_x264, _x_x266, _ctx); /*string*/
  _x_x259 = kk_std_core_types__lp__plus__plus__rp_(_x_x260, _x_x263, _ctx); /*string*/
  _x_x256 = kk_std_core_types__lp__plus__plus__rp_(_x_x257, _x_x259, _ctx); /*string*/
  _x_x252 = kk_std_core_types__lp__plus__plus__rp_(_x_x253, _x_x256, _ctx); /*string*/
  _x_x249 = kk_std_core_types__lp__plus__plus__rp_(_x_x250, _x_x252, _ctx); /*string*/
  _x_x245 = kk_std_core_types__lp__plus__plus__rp_(_x_x246, _x_x249, _ctx); /*string*/
  _x_x242 = kk_std_core_types__lp__plus__plus__rp_(_x_x243, _x_x245, _ctx); /*string*/
  _x_x238 = kk_std_core_types__lp__plus__plus__rp_(_x_x239, _x_x242, _ctx); /*string*/
  _x_x235 = kk_std_core_types__lp__plus__plus__rp_(_x_x236, _x_x238, _ctx); /*string*/
  _x_x231 = kk_std_core_types__lp__plus__plus__rp_(_x_x232, _x_x235, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x229, _x_x231, _ctx);
}

kk_string_t kk_whitemagic_dash_koka_src_shm__consumer_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x191;
  kk_string_t _x_x272 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x273;
  kk_define_string_literal(, _s_x274, 8, "\"header\"", _ctx)
  _x_x273 = kk_string_dup(_s_x274, _ctx); /*string*/
  _match_x191 = kk_string_contains(_x_x272,_x_x273,kk_context()); /*bool*/
  if (_match_x191) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x275, 6, "header", _ctx)
    return kk_string_dup(_s_x275, _ctx);
  }
  {
    bool _match_x192;
    kk_string_t _x_x276 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x277;
    kk_define_string_literal(, _s_x278, 6, "\"read\"", _ctx)
    _x_x277 = kk_string_dup(_s_x278, _ctx); /*string*/
    _match_x192 = kk_string_contains(_x_x276,_x_x277,kk_context()); /*bool*/
    if (_match_x192) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x279, 4, "read", _ctx)
      return kk_string_dup(_s_x279, _ctx);
    }
    {
      bool _match_x193;
      kk_string_t _x_x280 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x281;
      kk_define_string_literal(, _s_x282, 8, "\"status\"", _ctx)
      _x_x281 = kk_string_dup(_s_x282, _ctx); /*string*/
      _match_x193 = kk_string_contains(_x_x280,_x_x281,kk_context()); /*bool*/
      if (_match_x193) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x283, 6, "status", _ctx)
        return kk_string_dup(_s_x283, _ctx);
      }
      {
        bool _match_x194;
        kk_string_t _x_x284;
        kk_define_string_literal(, _s_x285, 6, "\"quit\"", _ctx)
        _x_x284 = kk_string_dup(_s_x285, _ctx); /*string*/
        _match_x194 = kk_string_contains(line,_x_x284,kk_context()); /*bool*/
        if (_match_x194) {
          kk_define_string_literal(, _s_x286, 4, "quit", _ctx)
          return kk_string_dup(_s_x286, _ctx);
        }
        {
          kk_define_string_literal(, _s_x287, 7, "unknown", _ctx)
          return kk_string_dup(_s_x287, _ctx);
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063_fun289__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063_fun289(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10063_fun289(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063_fun289, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063_fun289(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x290 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__consumer_flush_stdout(_ctx);
  return kk_unit_box(_x_x290);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063_fun294__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063_fun294(kk_function_t _fself, kk_box_t _b_x11, kk_box_t _b_x12, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10063_fun294(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063_fun294, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063_fun294(kk_function_t _fself, kk_box_t _b_x11, kk_box_t _b_x12, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x295;
  int64_t _x_x296 = kk_int64_unbox(_b_x11, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x297 = kk_integer_unbox(_b_x12, _ctx); /*int*/
  _x_x295 = kk_whitemagic_dash_koka_src_shm__consumer_shm_unmap(_x_x296, _x_x297, _ctx); /*int*/
  return kk_integer_box(_x_x295, _ctx);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063(int64_t addr, kk_string_t op, kk_string_t _c_x10014, kk_context_t* _ctx) { /* (addr : int64, op : string, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10014, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x288 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10063_fun289(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x288);
  bool _match_x190;
  kk_string_t _x_x291;
  kk_define_string_literal(, _s_x292, 4, "quit", _ctx)
  _x_x291 = kk_string_dup(_s_x292, _ctx); /*string*/
  _match_x190 = kk_string_is_neq(op,_x_x291,kk_context()); /*bool*/
  if (_match_x190) {
    kk_whitemagic_dash_koka_src_shm__consumer_server_loop(addr, _ctx); return kk_Unit;
  }
  {
    kk_integer_t _pat_10;
    kk_box_t _x_x293 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10063_fun294(_ctx), kk_int64_box(addr, _ctx), kk_integer_box(kk_integer_from_int(1544704, _ctx), _ctx), _ctx); /*10002*/
    _pat_10 = kk_integer_unbox(_x_x293, _ctx); /*int*/
    kk_integer_drop(_pat_10, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun302__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun302(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun302(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun302, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun302(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x303;
  kk_string_t _x_x304 = kk_string_unbox(_b_x18); /*string*/
  _x_x303 = kk_whitemagic_dash_koka_src_shm__consumer_extract_op(_x_x304, _ctx); /*string*/
  return kk_string_box(_x_x303);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun307__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun307(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun307(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun307, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun307(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _x_x308;
  int64_t _x_x309 = kk_int64_unbox(_b_x23, KK_OWNED, _ctx); /*int64*/
  _x_x308 = kk_whitemagic_dash_koka_src_shm__consumer_read_header(_x_x309, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
  return kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(_x_x308, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun311__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun311(kk_function_t _fself, kk_box_t _b_x28, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun311(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun311, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun311(kk_function_t _fself, kk_box_t _b_x28, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x312;
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _x_x313 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_b_x28, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
  _x_x312 = kk_whitemagic_dash_koka_src_shm__consumer_json_header(_x_x313, _ctx); /*string*/
  return kk_string_box(_x_x312);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun315__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun315(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun315(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun315, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun315(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _x_x316;
  int64_t _x_x317 = kk_int64_unbox(_b_x31, KK_OWNED, _ctx); /*int64*/
  _x_x316 = kk_whitemagic_dash_koka_src_shm__consumer_read_header(_x_x317, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
  return kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(_x_x316, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun319__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun319(kk_function_t _fself, kk_box_t _b_x36, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun319(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun319, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun319(kk_function_t _fself, kk_box_t _b_x36, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x320;
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _match_x187 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_b_x36, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x321 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_match_x187, _ctx);
    kk_integer_t _pat_0_0_0 = _con_x321->magic;
    kk_integer_t _pat_1_0_0 = _con_x321->version;
    kk_integer_t _pat_2_0 = _con_x321->capacity;
    kk_integer_t _x = _con_x321->count;
    kk_integer_t _pat_3_0 = _con_x321->write_pos;
    kk_integer_t _pat_4 = _con_x321->read_pos;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x187, _ctx)) {
      kk_integer_drop(_pat_4, _ctx);
      kk_integer_drop(_pat_3_0, _ctx);
      kk_integer_drop(_pat_2_0, _ctx);
      kk_integer_drop(_pat_1_0_0, _ctx);
      kk_integer_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(_match_x187, _ctx);
    }
    else {
      kk_integer_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x187, _ctx);
    }
    _x_x320 = _x; /*int*/
  }
  return kk_integer_box(_x_x320, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun327__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun327(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun327(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun327, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun327(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x328;
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _match_x186 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_b_x39, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x329 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_match_x186, _ctx);
    kk_integer_t _pat_0_1 = _con_x329->magic;
    kk_integer_t _pat_1_1 = _con_x329->version;
    kk_integer_t _pat_2_1 = _con_x329->capacity;
    kk_integer_t _pat_3_2 = _con_x329->count;
    kk_integer_t _pat_4_1 = _con_x329->write_pos;
    kk_integer_t _x_0 = _con_x329->read_pos;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x186, _ctx)) {
      kk_integer_drop(_pat_4_1, _ctx);
      kk_integer_drop(_pat_3_2, _ctx);
      kk_integer_drop(_pat_2_1, _ctx);
      kk_integer_drop(_pat_1_1, _ctx);
      kk_integer_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(_match_x186, _ctx);
    }
    else {
      kk_integer_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x186, _ctx);
    }
    _x_x328 = _x_0; /*int*/
  }
  return kk_integer_box(_x_x328, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun331__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun331(kk_function_t _fself, kk_box_t _b_x46, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun331(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun331, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun331(kk_function_t _fself, kk_box_t _b_x46, kk_box_t _b_x47, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x332;
  int64_t _x_x333 = kk_int64_unbox(_b_x46, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x334 = kk_integer_unbox(_b_x47, _ctx); /*int*/
  _x_x332 = kk_whitemagic_dash_koka_src_shm__consumer_shm_read_int(_x_x333, _x_x334, _ctx); /*int*/
  return kk_integer_box(_x_x332, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun356__t {
  struct kk_function_s _base;
  kk_string_t op_0;
  int64_t addr_0;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun356(kk_function_t _fself, kk_box_t _b_x56, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun356(kk_string_t op_0, int64_t addr_0, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun356__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun356__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun356, kk_context());
  _self->op_0 = op_0;
  _self->addr_0 = addr_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun356(kk_function_t _fself, kk_box_t _b_x56, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun356__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064_fun356__t*, _fself, _ctx);
  kk_string_t op_0 = _self->op_0; /* string */
  int64_t addr_0 = _self->addr_0; /* int64 */
  kk_drop_match(_self, {kk_string_dup(op_0, _ctx);kk_skip_dup(addr_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10014_0_59 = kk_string_unbox(_b_x56); /*string*/;
  kk_unit_t _x_x357 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063(addr_0, op_0, _c_x10014_0_59, _ctx);
  return kk_unit_box(_x_x357);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064(int64_t addr_0, kk_string_t line, kk_context_t* _ctx) { /* (addr : int64, line : string) -> <console/console,exn> () */ 
  bool _match_x183;
  kk_string_t _x_x298 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x299 = kk_string_empty(); /*string*/
  _match_x183 = kk_string_is_eq(_x_x298,_x_x299,kk_context()); /*bool*/
  if (_match_x183) {
    kk_string_drop(line, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_string_t op_0;
    kk_box_t _x_x301 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun302(_ctx), kk_string_box(line), _ctx); /*10001*/
    op_0 = kk_string_unbox(_x_x301); /*string*/
    kk_string_t x_10065;
    if (kk_string_cmp_cstr_borrow(op_0, "header", _ctx) == 0) {
      kk_whitemagic_dash_koka_src_shm__consumer__shm_header h;
      kk_box_t _x_x306 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun307(_ctx), kk_int64_box(addr_0, _ctx), _ctx); /*10001*/
      h = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_x_x306, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
      kk_box_t _x_x310 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun311(_ctx), kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(h, _ctx), _ctx); /*10001*/
      x_10065 = kk_string_unbox(_x_x310); /*string*/
      goto _match_x305;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "read", _ctx) == 0) {
      kk_whitemagic_dash_koka_src_shm__consumer__shm_header h_0;
      kk_box_t _x_x314 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun315(_ctx), kk_int64_box(addr_0, _ctx), _ctx); /*10001*/
      h_0 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_x_x314, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
      bool _match_x185;
      kk_integer_t _brw_x188;
      kk_box_t _x_x318;
      kk_box_t _x_x322;
      kk_whitemagic_dash_koka_src_shm__consumer__shm_header _x_x323 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_dup(h_0, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
      _x_x322 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(_x_x323, _ctx); /*10000*/
      _x_x318 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun319(_ctx), _x_x322, _ctx); /*10001*/
      _brw_x188 = kk_integer_unbox(_x_x318, _ctx); /*int*/
      bool _brw_x189 = kk_integer_eq_borrow(_brw_x188,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x188, _ctx);
      _match_x185 = _brw_x189; /*bool*/
      if (_match_x185) {
        kk_datatype_ptr_dropn(h_0, (KK_I32(6)), _ctx);
        kk_define_string_literal(, _s_x324, 17, "{\"error\":\"empty\"}", _ctx)
        x_10065 = kk_string_dup(_s_x324, _ctx); /*string*/
        goto _match_x305;
      }
      {
        kk_integer_t y_10027;
        kk_integer_t _x_x325;
        kk_box_t _x_x326 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun327(_ctx), kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(h_0, _ctx), _ctx); /*10001*/
        _x_x325 = kk_integer_unbox(_x_x326, _ctx); /*int*/
        y_10027 = kk_integer_mul(_x_x325,(kk_integer_from_small(1544)),kk_context()); /*int*/
        kk_integer_t offset = kk_integer_add_small_const(y_10027, 64, _ctx); /*int*/;
        kk_integer_t id;
        kk_box_t _x_x330 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun331(_ctx), kk_int64_box(addr_0, _ctx), kk_integer_box(offset, _ctx), _ctx); /*10002*/
        id = kk_integer_unbox(_x_x330, _ctx); /*int*/
        kk_string_t _x_x335;
        kk_define_string_literal(, _s_x336, 6, "{\"id\":", _ctx)
        _x_x335 = kk_string_dup(_s_x336, _ctx); /*string*/
        kk_string_t _x_x337;
        kk_string_t _x_x338 = kk_std_core_int_show(id, _ctx); /*string*/
        kk_string_t _x_x339;
        kk_string_t _x_x340;
        kk_define_string_literal(, _s_x341, 7, ",\"dim\":", _ctx)
        _x_x340 = kk_string_dup(_s_x341, _ctx); /*string*/
        kk_string_t _x_x342;
        kk_string_t _x_x343 = kk_std_core_int_show(kk_integer_from_small(384), _ctx); /*string*/
        kk_string_t _x_x344;
        kk_define_string_literal(, _s_x345, 1, "}", _ctx)
        _x_x344 = kk_string_dup(_s_x345, _ctx); /*string*/
        _x_x342 = kk_std_core_types__lp__plus__plus__rp_(_x_x343, _x_x344, _ctx); /*string*/
        _x_x339 = kk_std_core_types__lp__plus__plus__rp_(_x_x340, _x_x342, _ctx); /*string*/
        _x_x337 = kk_std_core_types__lp__plus__plus__rp_(_x_x338, _x_x339, _ctx); /*string*/
        x_10065 = kk_std_core_types__lp__plus__plus__rp_(_x_x335, _x_x337, _ctx); /*string*/
        goto _match_x305;
      }
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_string_t _x_x346;
      kk_define_string_literal(, _s_x347, 28, "{\"shm_consumer\":true,\"addr\":", _ctx)
      _x_x346 = kk_string_dup(_s_x347, _ctx); /*string*/
      kk_string_t _x_x348;
      kk_string_t _x_x349;
      kk_integer_t _x_x350 = kk_integer_from_int64(addr_0,kk_context()); /*int*/
      _x_x349 = kk_std_core_int_show(_x_x350, _ctx); /*string*/
      kk_string_t _x_x351;
      kk_define_string_literal(, _s_x352, 1, "}", _ctx)
      _x_x351 = kk_string_dup(_s_x352, _ctx); /*string*/
      _x_x348 = kk_std_core_types__lp__plus__plus__rp_(_x_x349, _x_x351, _ctx); /*string*/
      x_10065 = kk_std_core_types__lp__plus__plus__rp_(_x_x346, _x_x348, _ctx); /*string*/
      goto _match_x305;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "quit", _ctx) == 0) {
      kk_define_string_literal(, _s_x353, 20, "{\"status\":\"stopped\"}", _ctx)
      x_10065 = kk_string_dup(_s_x353, _ctx); /*string*/
      goto _match_x305;
    }
    {
      kk_define_string_literal(, _s_x354, 22, "{\"error\":\"unknown op\"}", _ctx)
      x_10065 = kk_string_dup(_s_x354, _ctx); /*string*/
    }
    _match_x305: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_10065, _ctx);
      kk_box_t _x_x355 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_shm__consumer__new_mlift_server_loop_10064_fun356(op_0, addr_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x355); return kk_Unit;
    }
    {
      kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063(addr_0, op_0, x_10065, _ctx); return kk_Unit;
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun359__t {
  struct kk_function_s _base;
  int64_t addr_1;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun359(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun359(int64_t addr_1, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun359__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun359__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun359, kk_context());
  _self->addr_1 = addr_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun359(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun359__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun359__t*, _fself, _ctx);
  int64_t addr_1 = _self->addr_1; /* int64 */
  kk_drop_match(_self, {kk_skip_dup(addr_1, _ctx);}, {}, _ctx)
  kk_string_t line_0_116 = kk_string_unbox(_b_x61); /*string*/;
  kk_unit_t _x_x360 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10064(addr_1, line_0_116, _ctx);
  return kk_unit_box(_x_x360);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun365__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun365(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun365(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun365, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun365(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x366;
  kk_string_t _x_x367 = kk_string_unbox(_b_x64); /*string*/
  _x_x366 = kk_whitemagic_dash_koka_src_shm__consumer_extract_op(_x_x367, _ctx); /*string*/
  return kk_string_box(_x_x366);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun370__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun370(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun370(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun370, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun370(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _x_x371;
  int64_t _x_x372 = kk_int64_unbox(_b_x69, KK_OWNED, _ctx); /*int64*/
  _x_x371 = kk_whitemagic_dash_koka_src_shm__consumer_read_header(_x_x372, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
  return kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(_x_x371, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun374__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun374(kk_function_t _fself, kk_box_t _b_x74, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun374(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun374, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun374(kk_function_t _fself, kk_box_t _b_x74, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x375;
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _x_x376 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_b_x74, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
  _x_x375 = kk_whitemagic_dash_koka_src_shm__consumer_json_header(_x_x376, _ctx); /*string*/
  return kk_string_box(_x_x375);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun378__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun378(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun378(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun378, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun378(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _x_x379;
  int64_t _x_x380 = kk_int64_unbox(_b_x77, KK_OWNED, _ctx); /*int64*/
  _x_x379 = kk_whitemagic_dash_koka_src_shm__consumer_read_header(_x_x380, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
  return kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(_x_x379, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun382__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun382(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun382(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun382, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun382(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x383;
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _match_x180 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_b_x82, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x384 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_match_x180, _ctx);
    kk_integer_t _pat_0_0_1 = _con_x384->magic;
    kk_integer_t _pat_1_0_1 = _con_x384->version;
    kk_integer_t _pat_2_0_0 = _con_x384->capacity;
    kk_integer_t _x_1 = _con_x384->count;
    kk_integer_t _pat_3_0_0 = _con_x384->write_pos;
    kk_integer_t _pat_4_2 = _con_x384->read_pos;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x180, _ctx)) {
      kk_integer_drop(_pat_4_2, _ctx);
      kk_integer_drop(_pat_3_0_0, _ctx);
      kk_integer_drop(_pat_2_0_0, _ctx);
      kk_integer_drop(_pat_1_0_1, _ctx);
      kk_integer_drop(_pat_0_0_1, _ctx);
      kk_datatype_ptr_free(_match_x180, _ctx);
    }
    else {
      kk_integer_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_match_x180, _ctx);
    }
    _x_x383 = _x_1; /*int*/
  }
  return kk_integer_box(_x_x383, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun390__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun390(kk_function_t _fself, kk_box_t _b_x85, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun390(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun390, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun390(kk_function_t _fself, kk_box_t _b_x85, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x391;
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _match_x179 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_b_x85, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x392 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_match_x179, _ctx);
    kk_integer_t _pat_0_1_0 = _con_x392->magic;
    kk_integer_t _pat_1_1_0 = _con_x392->version;
    kk_integer_t _pat_2_1_0 = _con_x392->capacity;
    kk_integer_t _pat_3_2_0 = _con_x392->count;
    kk_integer_t _pat_4_1_0 = _con_x392->write_pos;
    kk_integer_t _x_0_0 = _con_x392->read_pos;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x179, _ctx)) {
      kk_integer_drop(_pat_4_1_0, _ctx);
      kk_integer_drop(_pat_3_2_0, _ctx);
      kk_integer_drop(_pat_2_1_0, _ctx);
      kk_integer_drop(_pat_1_1_0, _ctx);
      kk_integer_drop(_pat_0_1_0, _ctx);
      kk_datatype_ptr_free(_match_x179, _ctx);
    }
    else {
      kk_integer_dup(_x_0_0, _ctx);
      kk_datatype_ptr_decref(_match_x179, _ctx);
    }
    _x_x391 = _x_0_0; /*int*/
  }
  return kk_integer_box(_x_x391, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun394__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun394(kk_function_t _fself, kk_box_t _b_x92, kk_box_t _b_x93, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun394(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun394, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun394(kk_function_t _fself, kk_box_t _b_x92, kk_box_t _b_x93, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x395;
  int64_t _x_x396 = kk_int64_unbox(_b_x92, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x397 = kk_integer_unbox(_b_x93, _ctx); /*int*/
  _x_x395 = kk_whitemagic_dash_koka_src_shm__consumer_shm_read_int(_x_x396, _x_x397, _ctx); /*int*/
  return kk_integer_box(_x_x395, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun419__t {
  struct kk_function_s _base;
  kk_string_t op_1;
  int64_t addr_1;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun419(kk_function_t _fself, kk_box_t _b_x102, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun419(kk_string_t op_1, int64_t addr_1, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun419__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun419__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun419, kk_context());
  _self->op_1 = op_1;
  _self->addr_1 = addr_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun419(kk_function_t _fself, kk_box_t _b_x102, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun419__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun419__t*, _fself, _ctx);
  kk_string_t op_1 = _self->op_1; /* string */
  int64_t addr_1 = _self->addr_1; /* int64 */
  kk_drop_match(_self, {kk_string_dup(op_1, _ctx);kk_skip_dup(addr_1, _ctx);}, {}, _ctx)
  kk_string_t _c_x10014_1_117 = kk_string_unbox(_b_x102); /*string*/;
  kk_unit_t _x_x420 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__consumer__mlift_server_loop_10063(addr_1, op_1, _c_x10014_1_117, _ctx);
  return kk_unit_box(_x_x420);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun422__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun422(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun422(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun422, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun422(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x423 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__consumer_flush_stdout(_ctx);
  return kk_unit_box(_x_x423);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun427__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun427(kk_function_t _fself, kk_box_t _b_x108, kk_box_t _b_x109, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun427(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun427, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop_fun427(kk_function_t _fself, kk_box_t _b_x108, kk_box_t _b_x109, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x428;
  int64_t _x_x429 = kk_int64_unbox(_b_x108, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x430 = kk_integer_unbox(_b_x109, _ctx); /*int*/
  _x_x428 = kk_whitemagic_dash_koka_src_shm__consumer_shm_unmap(_x_x429, _x_x430, _ctx); /*int*/
  return kk_integer_box(_x_x428, _ctx);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__consumer_server_loop(int64_t addr_1, kk_context_t* _ctx) { /* (addr : int64) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_0_10067 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10067, _ctx);
    kk_box_t _x_x358 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun359(addr_1, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x358); return kk_Unit;
  }
  {
    bool _match_x175;
    kk_string_t _x_x361 = kk_string_dup(x_0_10067, _ctx); /*string*/
    kk_string_t _x_x362 = kk_string_empty(); /*string*/
    _match_x175 = kk_string_is_eq(_x_x361,_x_x362,kk_context()); /*bool*/
    if (_match_x175) {
      kk_string_drop(x_0_10067, _ctx);
      kk_Unit; return kk_Unit;
    }
    {
      kk_string_t op_1;
      kk_box_t _x_x364 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun365(_ctx), kk_string_box(x_0_10067), _ctx); /*10001*/
      op_1 = kk_string_unbox(_x_x364); /*string*/
      kk_string_t x_1_10070;
      if (kk_string_cmp_cstr_borrow(op_1, "header", _ctx) == 0) {
        kk_whitemagic_dash_koka_src_shm__consumer__shm_header h_1;
        kk_box_t _x_x369 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun370(_ctx), kk_int64_box(addr_1, _ctx), _ctx); /*10001*/
        h_1 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_x_x369, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
        kk_box_t _x_x373 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun374(_ctx), kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(h_1, _ctx), _ctx); /*10001*/
        x_1_10070 = kk_string_unbox(_x_x373); /*string*/
        goto _match_x368;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "read", _ctx) == 0) {
        kk_whitemagic_dash_koka_src_shm__consumer__shm_header h_0_0;
        kk_box_t _x_x377 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun378(_ctx), kk_int64_box(addr_1, _ctx), _ctx); /*10001*/
        h_0_0 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_x_x377, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
        bool _match_x178;
        kk_integer_t _brw_x181;
        kk_box_t _x_x381;
        kk_box_t _x_x385;
        kk_whitemagic_dash_koka_src_shm__consumer__shm_header _x_x386 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_dup(h_0_0, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
        _x_x385 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(_x_x386, _ctx); /*10000*/
        _x_x381 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun382(_ctx), _x_x385, _ctx); /*10001*/
        _brw_x181 = kk_integer_unbox(_x_x381, _ctx); /*int*/
        bool _brw_x182 = kk_integer_eq_borrow(_brw_x181,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        kk_integer_drop(_brw_x181, _ctx);
        _match_x178 = _brw_x182; /*bool*/
        if (_match_x178) {
          kk_datatype_ptr_dropn(h_0_0, (KK_I32(6)), _ctx);
          kk_define_string_literal(, _s_x387, 17, "{\"error\":\"empty\"}", _ctx)
          x_1_10070 = kk_string_dup(_s_x387, _ctx); /*string*/
          goto _match_x368;
        }
        {
          kk_integer_t y_10027_0;
          kk_integer_t _x_x388;
          kk_box_t _x_x389 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun390(_ctx), kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(h_0_0, _ctx), _ctx); /*10001*/
          _x_x388 = kk_integer_unbox(_x_x389, _ctx); /*int*/
          y_10027_0 = kk_integer_mul(_x_x388,(kk_integer_from_small(1544)),kk_context()); /*int*/
          kk_integer_t offset_0 = kk_integer_add_small_const(y_10027_0, 64, _ctx); /*int*/;
          kk_integer_t id_0;
          kk_box_t _x_x393 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun394(_ctx), kk_int64_box(addr_1, _ctx), kk_integer_box(offset_0, _ctx), _ctx); /*10002*/
          id_0 = kk_integer_unbox(_x_x393, _ctx); /*int*/
          kk_string_t _x_x398;
          kk_define_string_literal(, _s_x399, 6, "{\"id\":", _ctx)
          _x_x398 = kk_string_dup(_s_x399, _ctx); /*string*/
          kk_string_t _x_x400;
          kk_string_t _x_x401 = kk_std_core_int_show(id_0, _ctx); /*string*/
          kk_string_t _x_x402;
          kk_string_t _x_x403;
          kk_define_string_literal(, _s_x404, 7, ",\"dim\":", _ctx)
          _x_x403 = kk_string_dup(_s_x404, _ctx); /*string*/
          kk_string_t _x_x405;
          kk_string_t _x_x406 = kk_std_core_int_show(kk_integer_from_small(384), _ctx); /*string*/
          kk_string_t _x_x407;
          kk_define_string_literal(, _s_x408, 1, "}", _ctx)
          _x_x407 = kk_string_dup(_s_x408, _ctx); /*string*/
          _x_x405 = kk_std_core_types__lp__plus__plus__rp_(_x_x406, _x_x407, _ctx); /*string*/
          _x_x402 = kk_std_core_types__lp__plus__plus__rp_(_x_x403, _x_x405, _ctx); /*string*/
          _x_x400 = kk_std_core_types__lp__plus__plus__rp_(_x_x401, _x_x402, _ctx); /*string*/
          x_1_10070 = kk_std_core_types__lp__plus__plus__rp_(_x_x398, _x_x400, _ctx); /*string*/
          goto _match_x368;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
        kk_string_t _x_x409;
        kk_define_string_literal(, _s_x410, 28, "{\"shm_consumer\":true,\"addr\":", _ctx)
        _x_x409 = kk_string_dup(_s_x410, _ctx); /*string*/
        kk_string_t _x_x411;
        kk_string_t _x_x412;
        kk_integer_t _x_x413 = kk_integer_from_int64(addr_1,kk_context()); /*int*/
        _x_x412 = kk_std_core_int_show(_x_x413, _ctx); /*string*/
        kk_string_t _x_x414;
        kk_define_string_literal(, _s_x415, 1, "}", _ctx)
        _x_x414 = kk_string_dup(_s_x415, _ctx); /*string*/
        _x_x411 = kk_std_core_types__lp__plus__plus__rp_(_x_x412, _x_x414, _ctx); /*string*/
        x_1_10070 = kk_std_core_types__lp__plus__plus__rp_(_x_x409, _x_x411, _ctx); /*string*/
        goto _match_x368;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "quit", _ctx) == 0) {
        kk_define_string_literal(, _s_x416, 20, "{\"status\":\"stopped\"}", _ctx)
        x_1_10070 = kk_string_dup(_s_x416, _ctx); /*string*/
        goto _match_x368;
      }
      {
        kk_define_string_literal(, _s_x417, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_1_10070 = kk_string_dup(_s_x417, _ctx); /*string*/
      }
      _match_x368: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_1_10070, _ctx);
        kk_box_t _x_x418 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun419(op_1, addr_1, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x418); return kk_Unit;
      }
      {
        kk_unit_t ___1 = kk_Unit;
        kk_std_core_console_printsln(x_1_10070, _ctx);
        kk_unit_t ___0_0 = kk_Unit;
        kk_box_t _x_x421 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun422(_ctx), _ctx); /*10000*/
        kk_unit_unbox(_x_x421);
        bool _match_x177;
        kk_string_t _x_x424;
        kk_define_string_literal(, _s_x425, 4, "quit", _ctx)
        _x_x424 = kk_string_dup(_s_x425, _ctx); /*string*/
        _match_x177 = kk_string_is_neq(op_1,_x_x424,kk_context()); /*bool*/
        if (_match_x177) { // tailcall
                           goto kk__tailcall;
        }
        {
          kk_integer_t _pat_10_0;
          kk_box_t _x_x426 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__consumer_new_server_loop_fun427(_ctx), kk_int64_box(addr_1, _ctx), kk_integer_box(kk_integer_from_int(1544704, _ctx), _ctx), _ctx); /*10002*/
          _pat_10_0 = kk_integer_unbox(_x_x426, _ctx); /*int*/
          kk_integer_drop(_pat_10_0, _ctx);
          kk_Unit; return kk_Unit;
        }
      }
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun440__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun440(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun440(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_main_fun440, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun440(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x441 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__consumer_flush_stdout(_ctx);
  return kk_unit_box(_x_x441);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun443__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun443(kk_function_t _fself, kk_box_t _b_x123, kk_box_t _b_x124, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun443(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_main_fun443, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun443(kk_function_t _fself, kk_box_t _b_x123, kk_box_t _b_x124, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x444;
  kk_string_t _x_x445 = kk_string_unbox(_b_x123); /*string*/
  kk_integer_t _x_x446 = kk_integer_unbox(_b_x124, _ctx); /*int*/
  _x_x444 = kk_whitemagic_dash_koka_src_shm__consumer_shm_open_map(_x_x445, _x_x446, _ctx); /*int64*/
  return kk_int64_box(_x_x444, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun451__t {
  struct kk_function_s _base;
};
static int64_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun451(kk_function_t _fself, kk_integer_t _x1_x450, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun451(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_main_fun451, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static int64_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun451(kk_function_t _fself, kk_integer_t _x1_x450, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_int64_int64(_x1_x450, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun454__t {
  struct kk_function_s _base;
  kk_function_t _b_x128_162;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun454(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun454(kk_function_t _b_x128_162, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun454__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun454__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__consumer_main_fun454, kk_context());
  _self->_b_x128_162 = _b_x128_162;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun454(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun454__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun454__t*, _fself, _ctx);
  kk_function_t _b_x128_162 = _self->_b_x128_162; /* (i : int) -> int64 */
  kk_drop_match(_self, {kk_function_dup(_b_x128_162, _ctx);}, {}, _ctx)
  int64_t _x_x455;
  kk_integer_t _x_x456 = kk_integer_unbox(_b_x130, _ctx); /*int*/
  _x_x455 = kk_function_call(int64_t, (kk_function_t, kk_integer_t, kk_context_t*), _b_x128_162, (_b_x128_162, _x_x456, _ctx), _ctx); /*int64*/
  return kk_int64_box(_x_x455, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun460__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun460(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun460(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_main_fun460, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun460(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x461 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__consumer_flush_stdout(_ctx);
  return kk_unit_box(_x_x461);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun463__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun463(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun463(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_main_fun463, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun463(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _x_x464;
  int64_t _x_x465 = kk_int64_unbox(_b_x134, KK_OWNED, _ctx); /*int64*/
  _x_x464 = kk_whitemagic_dash_koka_src_shm__consumer_read_header(_x_x465, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
  return kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(_x_x464, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun466__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun466(kk_function_t _fself, kk_whitemagic_dash_koka_src_shm__consumer__shm_header _this, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun466(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_main_fun466, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun466(kk_function_t _fself, kk_whitemagic_dash_koka_src_shm__consumer__shm_header _this, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x467 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_this, _ctx);
    kk_integer_t _x = _con_x467->magic;
    kk_integer_t _pat_0_0 = _con_x467->version;
    kk_integer_t _pat_1_0 = _con_x467->capacity;
    kk_integer_t _pat_2 = _con_x467->count;
    kk_integer_t _pat_3 = _con_x467->write_pos;
    kk_integer_t _pat_4 = _con_x467->read_pos;
    if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
      kk_integer_drop(_pat_4, _ctx);
      kk_integer_drop(_pat_3, _ctx);
      kk_integer_drop(_pat_2, _ctx);
      kk_integer_drop(_pat_1_0, _ctx);
      kk_integer_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(_this, _ctx);
    }
    else {
      kk_integer_dup(_x, _ctx);
      kk_datatype_ptr_decref(_this, _ctx);
    }
    return _x;
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun469__t {
  struct kk_function_s _base;
  kk_function_t _b_x137_165;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun469(kk_function_t _fself, kk_box_t _b_x139, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun469(kk_function_t _b_x137_165, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun469__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun469__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__consumer_main_fun469, kk_context());
  _self->_b_x137_165 = _b_x137_165;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun469(kk_function_t _fself, kk_box_t _b_x139, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun469__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun469__t*, _fself, _ctx);
  kk_function_t _b_x137_165 = _self->_b_x137_165; /* (whitemagic-koka/src/shm_consumer/shm-header) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x137_165, _ctx);}, {}, _ctx)
  kk_integer_t _x_x470;
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _x_x471 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_b_x139, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
  _x_x470 = kk_function_call(kk_integer_t, (kk_function_t, kk_whitemagic_dash_koka_src_shm__consumer__shm_header, kk_context_t*), _b_x137_165, (_b_x137_165, _x_x471, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x470, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun479__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun479(kk_function_t _fself, kk_box_t _b_x142, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun479(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_main_fun479, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun479(kk_function_t _fself, kk_box_t _b_x142, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x480;
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _this_0_167 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_b_x142, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x481 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_this_0_167, _ctx);
    kk_integer_t _x_0 = _con_x481->magic;
    kk_integer_t _pat_0_1 = _con_x481->version;
    kk_integer_t _pat_1_2 = _con_x481->capacity;
    kk_integer_t _pat_2_0 = _con_x481->count;
    kk_integer_t _pat_3_0 = _con_x481->write_pos;
    kk_integer_t _pat_4_0 = _con_x481->read_pos;
    if kk_likely(kk_datatype_ptr_is_unique(_this_0_167, _ctx)) {
      kk_integer_drop(_pat_4_0, _ctx);
      kk_integer_drop(_pat_3_0, _ctx);
      kk_integer_drop(_pat_2_0, _ctx);
      kk_integer_drop(_pat_1_2, _ctx);
      kk_integer_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(_this_0_167, _ctx);
    }
    else {
      kk_integer_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_this_0_167, _ctx);
    }
    _x_x480 = _x_0; /*int*/
  }
  return kk_integer_box(_x_x480, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun485__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun485(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun485(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_main_fun485, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun485(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x486 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__consumer_flush_stdout(_ctx);
  return kk_unit_box(_x_x486);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun488__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun488(kk_function_t _fself, kk_box_t _b_x150, kk_box_t _b_x151, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun488(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_main_fun488, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun488(kk_function_t _fself, kk_box_t _b_x150, kk_box_t _b_x151, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x489;
  int64_t _x_x490 = kk_int64_unbox(_b_x150, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x491 = kk_integer_unbox(_b_x151, _ctx); /*int*/
  _x_x489 = kk_whitemagic_dash_koka_src_shm__consumer_shm_unmap(_x_x490, _x_x491, _ctx); /*int*/
  return kk_integer_box(_x_x489, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun499__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun499(kk_function_t _fself, kk_box_t _b_x157, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun499(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_main_fun499, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun499(kk_function_t _fself, kk_box_t _b_x157, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x500;
  kk_whitemagic_dash_koka_src_shm__consumer__shm_header _this_1_168 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_b_x157, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/;
  {
    struct kk_whitemagic_dash_koka_src_shm__consumer_Shm_header* _con_x501 = kk_whitemagic_dash_koka_src_shm__consumer__as_Shm_header(_this_1_168, _ctx);
    kk_integer_t _pat_0_2 = _con_x501->magic;
    kk_integer_t _pat_1_3 = _con_x501->version;
    kk_integer_t _x_1 = _con_x501->capacity;
    kk_integer_t _pat_2_2 = _con_x501->count;
    kk_integer_t _pat_3_2 = _con_x501->write_pos;
    kk_integer_t _pat_4_1 = _con_x501->read_pos;
    if kk_likely(kk_datatype_ptr_is_unique(_this_1_168, _ctx)) {
      kk_integer_drop(_pat_4_1, _ctx);
      kk_integer_drop(_pat_3_2, _ctx);
      kk_integer_drop(_pat_2_2, _ctx);
      kk_integer_drop(_pat_1_3, _ctx);
      kk_integer_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(_this_1_168, _ctx);
    }
    else {
      kk_integer_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_this_1_168, _ctx);
    }
    _x_x500 = _x_1; /*int*/
  }
  return kk_integer_box(_x_x500, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__consumer_main_fun505__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun505(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun505(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__consumer_main_fun505, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__consumer_main_fun505(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x506 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__consumer_flush_stdout(_ctx);
  return kk_unit_box(_x_x506);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__consumer_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x431;
  kk_string_t _x_x432;
  kk_define_string_literal(, _s_x433, 51, "{\"status\":\"starting\",\"shm_consumer\":true,\"target\":\"", _ctx)
  _x_x432 = kk_string_dup(_s_x433, _ctx); /*string*/
  kk_string_t _x_x434;
  kk_string_t _x_x435;
  kk_define_string_literal(, _s_x436, 23, "whitemagic_embed_bridge", _ctx)
  _x_x435 = kk_string_dup(_s_x436, _ctx); /*string*/
  kk_string_t _x_x437;
  kk_define_string_literal(, _s_x438, 2, "\"}", _ctx)
  _x_x437 = kk_string_dup(_s_x438, _ctx); /*string*/
  _x_x434 = kk_std_core_types__lp__plus__plus__rp_(_x_x435, _x_x437, _ctx); /*string*/
  _x_x431 = kk_std_core_types__lp__plus__plus__rp_(_x_x432, _x_x434, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x431, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x439 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun440(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x439);
  int64_t addr;
  kk_box_t _x_x442;
  kk_box_t _x_x447;
  kk_string_t _x_x448;
  kk_define_string_literal(, _s_x449, 23, "whitemagic_embed_bridge", _ctx)
  _x_x448 = kk_string_dup(_s_x449, _ctx); /*string*/
  _x_x447 = kk_string_box(_x_x448); /*10000*/
  _x_x442 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun443(_ctx), _x_x447, kk_integer_box(kk_integer_from_int(1544704, _ctx), _ctx), _ctx); /*10002*/
  addr = kk_int64_unbox(_x_x442, KK_OWNED, _ctx); /*int64*/
  kk_function_t _b_x128_162 = kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun451(_ctx); /*(i : int) -> int64*/;
  kk_integer_t _b_x129_163 = kk_integer_from_small(0); /*int*/;
  bool _match_x169;
  int64_t _x_x452;
  kk_box_t _x_x453 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun454(_b_x128_162, _ctx), kk_integer_box(_b_x129_163, _ctx), _ctx); /*10001*/
  _x_x452 = kk_int64_unbox(_x_x453, KK_OWNED, _ctx); /*int64*/
  _match_x169 = (addr == _x_x452); /*bool*/
  if (_match_x169) {
    kk_unit_t ___1 = kk_Unit;
    kk_string_t _x_x457;
    kk_define_string_literal(, _s_x458, 69, "{\"error\":\"failed to open shared memory - producer must create first\"}", _ctx)
    _x_x457 = kk_string_dup(_s_x458, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x457, _ctx);
    kk_box_t _x_x459 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun460(_ctx), _ctx); /*10000*/
    kk_unit_unbox(_x_x459); return kk_Unit;
  }
  {
    kk_whitemagic_dash_koka_src_shm__consumer__shm_header header;
    kk_box_t _x_x462 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun463(_ctx), kk_int64_box(addr, _ctx), _ctx); /*10001*/
    header = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_unbox(_x_x462, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/
    kk_function_t _b_x137_165 = kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun466(_ctx); /*(whitemagic-koka/src/shm_consumer/shm-header) -> int*/;
    kk_whitemagic_dash_koka_src_shm__consumer__shm_header _b_x138_166 = kk_whitemagic_dash_koka_src_shm__consumer__shm_header_dup(header, _ctx); /*whitemagic-koka/src/shm_consumer/shm-header*/;
    bool _match_x170;
    kk_integer_t _brw_x172;
    kk_box_t _x_x468 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun469(_b_x137_165, _ctx), kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(_b_x138_166, _ctx), _ctx); /*10001*/
    _brw_x172 = kk_integer_unbox(_x_x468, _ctx); /*int*/
    kk_integer_t _brw_x171 = kk_integer_from_int(1464683339, _ctx); /*int*/;
    bool _brw_x173 = kk_integer_neq_borrow(_brw_x172,_brw_x171,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x172, _ctx);
    kk_integer_drop(_brw_x171, _ctx);
    _match_x170 = _brw_x173; /*bool*/
    if (_match_x170) {
      kk_unit_t ___2 = kk_Unit;
      kk_string_t _x_x472;
      kk_string_t _x_x473;
      kk_define_string_literal(, _s_x474, 30, "{\"error\":\"invalid magic - got ", _ctx)
      _x_x473 = kk_string_dup(_s_x474, _ctx); /*string*/
      kk_string_t _x_x475;
      kk_string_t _x_x476;
      kk_integer_t _x_x477;
      kk_box_t _x_x478 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun479(_ctx), kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(header, _ctx), _ctx); /*10001*/
      _x_x477 = kk_integer_unbox(_x_x478, _ctx); /*int*/
      _x_x476 = kk_std_core_int_show(_x_x477, _ctx); /*string*/
      kk_string_t _x_x482;
      kk_define_string_literal(, _s_x483, 2, "\"}", _ctx)
      _x_x482 = kk_string_dup(_s_x483, _ctx); /*string*/
      _x_x475 = kk_std_core_types__lp__plus__plus__rp_(_x_x476, _x_x482, _ctx); /*string*/
      _x_x472 = kk_std_core_types__lp__plus__plus__rp_(_x_x473, _x_x475, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x472, _ctx);
      kk_unit_t ___3 = kk_Unit;
      kk_box_t _x_x484 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun485(_ctx), _ctx); /*10000*/
      kk_unit_unbox(_x_x484);
      kk_integer_t _pat_2_1;
      kk_box_t _x_x487 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun488(_ctx), kk_int64_box(addr, _ctx), kk_integer_box(kk_integer_from_int(1544704, _ctx), _ctx), _ctx); /*10002*/
      _pat_2_1 = kk_integer_unbox(_x_x487, _ctx); /*int*/
      kk_integer_drop(_pat_2_1, _ctx);
      kk_Unit; return kk_Unit;
    }
    {
      kk_unit_t ___4 = kk_Unit;
      kk_string_t _x_x492;
      kk_string_t _x_x493;
      kk_define_string_literal(, _s_x494, 48, "{\"status\":\"started\",\"connected\":true,\"capacity\":", _ctx)
      _x_x493 = kk_string_dup(_s_x494, _ctx); /*string*/
      kk_string_t _x_x495;
      kk_string_t _x_x496;
      kk_integer_t _x_x497;
      kk_box_t _x_x498 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun499(_ctx), kk_whitemagic_dash_koka_src_shm__consumer__shm_header_box(header, _ctx), _ctx); /*10001*/
      _x_x497 = kk_integer_unbox(_x_x498, _ctx); /*int*/
      _x_x496 = kk_std_core_int_show(_x_x497, _ctx); /*string*/
      kk_string_t _x_x502;
      kk_define_string_literal(, _s_x503, 1, "}", _ctx)
      _x_x502 = kk_string_dup(_s_x503, _ctx); /*string*/
      _x_x495 = kk_std_core_types__lp__plus__plus__rp_(_x_x496, _x_x502, _ctx); /*string*/
      _x_x492 = kk_std_core_types__lp__plus__plus__rp_(_x_x493, _x_x495, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x492, _ctx);
      kk_unit_t ___5 = kk_Unit;
      kk_box_t _x_x504 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__consumer_new_main_fun505(_ctx), _ctx); /*10000*/
      kk_unit_unbox(_x_x504);
      kk_whitemagic_dash_koka_src_shm__consumer_server_loop(addr, _ctx); return kk_Unit;
    }
  }
}

// initialization
void kk_whitemagic_dash_koka_src_shm__consumer__init(kk_context_t* _ctx){
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
  kk_std_num_int64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  kk_init_string_literal(kk_whitemagic_dash_koka_src_shm__consumer_shm_name, _ctx)
  {
    kk_whitemagic_dash_koka_src_shm__consumer_segment_size = kk_integer_from_int(1544704, _ctx); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__consumer_header_size = kk_integer_from_small(64); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__consumer_slot_size = kk_integer_from_small(1544); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__consumer_embedding_dim = kk_integer_from_small(384); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__consumer_magic_number = kk_integer_from_int(1464683339, _ctx); /*int*/
  }
}

// termination
void kk_whitemagic_dash_koka_src_shm__consumer__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__consumer_magic_number, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__consumer_embedding_dim, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__consumer_slot_size, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__consumer_header_size, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__consumer_segment_size, _ctx);
  kk_std_num_int64__done(_ctx);
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
