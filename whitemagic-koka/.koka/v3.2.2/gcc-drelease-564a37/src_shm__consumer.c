// Koka generated module: src/shm_consumer, koka version: 3.2.2, platform: 64-bit
#include "src_shm__consumer.h"
// shm_consumer.c - C helper functions for Koka shared memory consumer
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

// Open and map shared memory, returns pointer (0 on error)
int64_t kk_shm_open_map(const char* name, int size) {
    int fd = shm_open(name, O_RDWR, 0666);
    if (fd < 0) return 0;
    void* addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    return (int64_t)addr;
}

// Unmap shared memory
int kk_shm_unmap(int64_t addr, int size) {
    return munmap((void*)addr, size);
}

// Read int32 at offset
int kk_shm_read_int(int64_t addr, int offset) {
    return *(int32_t*)(addr + offset);
}

// Read int64 at offset
int64_t kk_shm_read_int64(int64_t addr, int offset) {
    return *(int64_t*)(addr + offset);
}

// Read double at offset
double kk_shm_read_double(int64_t addr, int offset) {
    return *(double*)(addr + offset);
}

 
// Open and map shared memory, returns pointer (0 on error)

int64_t kk_src_shm__consumer_shm_open_map(kk_string_t name, kk_integer_t size, kk_context_t* _ctx) { /* (name : string, size : int) -> int64 */ 
  return kk_shm_open_map(name,size,kk_context());
}
 
// Unmap shared memory

kk_integer_t kk_src_shm__consumer_shm_unmap(int64_t addr, kk_integer_t size, kk_context_t* _ctx) { /* (addr : int64, size : int) -> int */ 
  return kk_shm_unmap(addr,size,kk_context());
}
 
// Read int32 at offset

kk_integer_t kk_src_shm__consumer_shm_read_int(int64_t addr, kk_integer_t offset, kk_context_t* _ctx) { /* (addr : int64, offset : int) -> int */ 
  return kk_shm_read_int(addr,offset,kk_context());
}
 
// Read int64 at offset

int64_t kk_src_shm__consumer_shm_read_int64(int64_t addr, kk_integer_t offset, kk_context_t* _ctx) { /* (addr : int64, offset : int) -> int64 */ 
  return kk_shm_read_int64(addr,offset,kk_context());
}
 
// Read double at offset

double kk_src_shm__consumer_shm_read_double(int64_t addr, kk_integer_t offset, kk_context_t* _ctx) { /* (addr : int64, offset : int) -> float64 */ 
  return kk_shm_read_double(addr,offset,kk_context());
}
kk_declare_string_literal(static, kk_src_shm__consumer_shm_name, 23, "whitemagic_embed_bridge")

kk_integer_t kk_src_shm__consumer_segment_size;

kk_integer_t kk_src_shm__consumer_header_size;

kk_integer_t kk_src_shm__consumer_slot_size;

kk_integer_t kk_src_shm__consumer_embedding_dim;

kk_integer_t kk_src_shm__consumer_magic_number;

kk_src_shm__consumer__shm_header kk_src_shm__consumer_shm_header_fs__copy(kk_src_shm__consumer__shm_header _this, kk_std_core_types__optional magic, kk_std_core_types__optional version, kk_std_core_types__optional capacity, kk_std_core_types__optional count, kk_std_core_types__optional write_pos, kk_std_core_types__optional read_pos, kk_context_t* _ctx) { /* (shm-header, magic : ? int, version : ? int, capacity : ? int, count : ? int, write-pos : ? int, read-pos : ? int) -> shm-header */ 
  kk_integer_t _x_x114;
  if (kk_std_core_types__is_Optional(magic, _ctx)) {
    kk_box_t _box_x0 = magic._cons._Optional.value;
    kk_integer_t _uniq_magic_133 = kk_integer_unbox(_box_x0, _ctx);
    kk_integer_dup(_uniq_magic_133, _ctx);
    kk_std_core_types__optional_drop(magic, _ctx);
    _x_x114 = _uniq_magic_133; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(magic, _ctx);
    {
      struct kk_src_shm__consumer_Shm_header* _con_x115 = kk_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _x = _con_x115->magic;
      kk_integer_dup(_x, _ctx);
      _x_x114 = _x; /*int*/
    }
  }
  kk_integer_t _x_x116;
  if (kk_std_core_types__is_Optional(version, _ctx)) {
    kk_box_t _box_x1 = version._cons._Optional.value;
    kk_integer_t _uniq_version_141 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_version_141, _ctx);
    kk_std_core_types__optional_drop(version, _ctx);
    _x_x116 = _uniq_version_141; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(version, _ctx);
    {
      struct kk_src_shm__consumer_Shm_header* _con_x117 = kk_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _x_0 = _con_x117->version;
      kk_integer_dup(_x_0, _ctx);
      _x_x116 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x118;
  if (kk_std_core_types__is_Optional(capacity, _ctx)) {
    kk_box_t _box_x2 = capacity._cons._Optional.value;
    kk_integer_t _uniq_capacity_149 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_capacity_149, _ctx);
    kk_std_core_types__optional_drop(capacity, _ctx);
    _x_x118 = _uniq_capacity_149; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(capacity, _ctx);
    {
      struct kk_src_shm__consumer_Shm_header* _con_x119 = kk_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _x_1 = _con_x119->capacity;
      kk_integer_dup(_x_1, _ctx);
      _x_x118 = _x_1; /*int*/
    }
  }
  kk_integer_t _x_x120;
  if (kk_std_core_types__is_Optional(count, _ctx)) {
    kk_box_t _box_x3 = count._cons._Optional.value;
    kk_integer_t _uniq_count_157 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_count_157, _ctx);
    kk_std_core_types__optional_drop(count, _ctx);
    _x_x120 = _uniq_count_157; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(count, _ctx);
    {
      struct kk_src_shm__consumer_Shm_header* _con_x121 = kk_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _x_2 = _con_x121->count;
      kk_integer_dup(_x_2, _ctx);
      _x_x120 = _x_2; /*int*/
    }
  }
  kk_integer_t _x_x122;
  if (kk_std_core_types__is_Optional(write_pos, _ctx)) {
    kk_box_t _box_x4 = write_pos._cons._Optional.value;
    kk_integer_t _uniq_write_pos_165 = kk_integer_unbox(_box_x4, _ctx);
    kk_integer_dup(_uniq_write_pos_165, _ctx);
    kk_std_core_types__optional_drop(write_pos, _ctx);
    _x_x122 = _uniq_write_pos_165; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(write_pos, _ctx);
    {
      struct kk_src_shm__consumer_Shm_header* _con_x123 = kk_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _x_3 = _con_x123->write_pos;
      kk_integer_dup(_x_3, _ctx);
      _x_x122 = _x_3; /*int*/
    }
  }
  kk_integer_t _x_x124;
  if (kk_std_core_types__is_Optional(read_pos, _ctx)) {
    kk_box_t _box_x5 = read_pos._cons._Optional.value;
    kk_integer_t _uniq_read_pos_173 = kk_integer_unbox(_box_x5, _ctx);
    kk_integer_dup(_uniq_read_pos_173, _ctx);
    kk_std_core_types__optional_drop(read_pos, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(6)), _ctx);
    _x_x124 = _uniq_read_pos_173; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(read_pos, _ctx);
    {
      struct kk_src_shm__consumer_Shm_header* _con_x125 = kk_src_shm__consumer__as_Shm_header(_this, _ctx);
      kk_integer_t _pat_0_5 = _con_x125->magic;
      kk_integer_t _pat_1_6 = _con_x125->version;
      kk_integer_t _pat_2_5 = _con_x125->capacity;
      kk_integer_t _pat_3_5 = _con_x125->count;
      kk_integer_t _pat_4_5 = _con_x125->write_pos;
      kk_integer_t _x_4 = _con_x125->read_pos;
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
      _x_x124 = _x_4; /*int*/
    }
  }
  return kk_src_shm__consumer__new_Shm_header(kk_reuse_null, 0, _x_x114, _x_x116, _x_x118, _x_x120, _x_x122, _x_x124, _ctx);
}

kk_src_shm__consumer__shm_header kk_src_shm__consumer_read_header(int64_t addr, kk_context_t* _ctx) { /* (addr : int64) -> shm-header */ 
  kk_integer_t _x_x126 = kk_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(0), _ctx); /*int*/
  kk_integer_t _x_x127 = kk_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(4), _ctx); /*int*/
  kk_integer_t _x_x128 = kk_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(8), _ctx); /*int*/
  kk_integer_t _x_x129 = kk_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(12), _ctx); /*int*/
  kk_integer_t _x_x130 = kk_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(16), _ctx); /*int*/
  kk_integer_t _x_x131 = kk_src_shm__consumer_shm_read_int(addr, kk_integer_from_small(20), _ctx); /*int*/
  return kk_src_shm__consumer__new_Shm_header(kk_reuse_null, 0, _x_x126, _x_x127, _x_x128, _x_x129, _x_x130, _x_x131, _ctx);
}

kk_string_t kk_src_shm__consumer_json_header(kk_src_shm__consumer__shm_header h, kk_context_t* _ctx) { /* (h : shm-header) -> string */ 
  kk_string_t _x_x132;
  kk_define_string_literal(, _s_x133, 9, "{\"magic\":", _ctx)
  _x_x132 = kk_string_dup(_s_x133, _ctx); /*string*/
  kk_string_t _x_x134;
  kk_string_t _x_x135;
  kk_integer_t _x_x136;
  {
    struct kk_src_shm__consumer_Shm_header* _con_x137 = kk_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _x = _con_x137->magic;
    kk_integer_dup(_x, _ctx);
    _x_x136 = _x; /*int*/
  }
  _x_x135 = kk_std_core_int_show(_x_x136, _ctx); /*string*/
  kk_string_t _x_x138;
  kk_string_t _x_x139;
  kk_define_string_literal(, _s_x140, 11, ",\"version\":", _ctx)
  _x_x139 = kk_string_dup(_s_x140, _ctx); /*string*/
  kk_string_t _x_x141;
  kk_string_t _x_x142;
  kk_integer_t _x_x143;
  {
    struct kk_src_shm__consumer_Shm_header* _con_x144 = kk_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _x_0 = _con_x144->version;
    kk_integer_dup(_x_0, _ctx);
    _x_x143 = _x_0; /*int*/
  }
  _x_x142 = kk_std_core_int_show(_x_x143, _ctx); /*string*/
  kk_string_t _x_x145;
  kk_string_t _x_x146;
  kk_define_string_literal(, _s_x147, 12, ",\"capacity\":", _ctx)
  _x_x146 = kk_string_dup(_s_x147, _ctx); /*string*/
  kk_string_t _x_x148;
  kk_string_t _x_x149;
  kk_integer_t _x_x150;
  {
    struct kk_src_shm__consumer_Shm_header* _con_x151 = kk_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _x_1 = _con_x151->capacity;
    kk_integer_dup(_x_1, _ctx);
    _x_x150 = _x_1; /*int*/
  }
  _x_x149 = kk_std_core_int_show(_x_x150, _ctx); /*string*/
  kk_string_t _x_x152;
  kk_string_t _x_x153;
  kk_define_string_literal(, _s_x154, 9, ",\"count\":", _ctx)
  _x_x153 = kk_string_dup(_s_x154, _ctx); /*string*/
  kk_string_t _x_x155;
  kk_string_t _x_x156;
  kk_integer_t _x_x157;
  {
    struct kk_src_shm__consumer_Shm_header* _con_x158 = kk_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _x_2 = _con_x158->count;
    kk_integer_dup(_x_2, _ctx);
    _x_x157 = _x_2; /*int*/
  }
  _x_x156 = kk_std_core_int_show(_x_x157, _ctx); /*string*/
  kk_string_t _x_x159;
  kk_string_t _x_x160;
  kk_define_string_literal(, _s_x161, 13, ",\"write_pos\":", _ctx)
  _x_x160 = kk_string_dup(_s_x161, _ctx); /*string*/
  kk_string_t _x_x162;
  kk_string_t _x_x163;
  kk_integer_t _x_x164;
  {
    struct kk_src_shm__consumer_Shm_header* _con_x165 = kk_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _x_3 = _con_x165->write_pos;
    kk_integer_dup(_x_3, _ctx);
    _x_x164 = _x_3; /*int*/
  }
  _x_x163 = kk_std_core_int_show(_x_x164, _ctx); /*string*/
  kk_string_t _x_x166;
  kk_string_t _x_x167;
  kk_define_string_literal(, _s_x168, 12, ",\"read_pos\":", _ctx)
  _x_x167 = kk_string_dup(_s_x168, _ctx); /*string*/
  kk_string_t _x_x169;
  kk_string_t _x_x170;
  kk_integer_t _x_x171;
  {
    struct kk_src_shm__consumer_Shm_header* _con_x172 = kk_src_shm__consumer__as_Shm_header(h, _ctx);
    kk_integer_t _pat_0_4 = _con_x172->magic;
    kk_integer_t _pat_1_4 = _con_x172->version;
    kk_integer_t _pat_2_4 = _con_x172->capacity;
    kk_integer_t _pat_3_4 = _con_x172->count;
    kk_integer_t _pat_4_4 = _con_x172->write_pos;
    kk_integer_t _x_4 = _con_x172->read_pos;
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
    _x_x171 = _x_4; /*int*/
  }
  _x_x170 = kk_std_core_int_show(_x_x171, _ctx); /*string*/
  kk_string_t _x_x173;
  kk_define_string_literal(, _s_x174, 1, "}", _ctx)
  _x_x173 = kk_string_dup(_s_x174, _ctx); /*string*/
  _x_x169 = kk_std_core_types__lp__plus__plus__rp_(_x_x170, _x_x173, _ctx); /*string*/
  _x_x166 = kk_std_core_types__lp__plus__plus__rp_(_x_x167, _x_x169, _ctx); /*string*/
  _x_x162 = kk_std_core_types__lp__plus__plus__rp_(_x_x163, _x_x166, _ctx); /*string*/
  _x_x159 = kk_std_core_types__lp__plus__plus__rp_(_x_x160, _x_x162, _ctx); /*string*/
  _x_x155 = kk_std_core_types__lp__plus__plus__rp_(_x_x156, _x_x159, _ctx); /*string*/
  _x_x152 = kk_std_core_types__lp__plus__plus__rp_(_x_x153, _x_x155, _ctx); /*string*/
  _x_x148 = kk_std_core_types__lp__plus__plus__rp_(_x_x149, _x_x152, _ctx); /*string*/
  _x_x145 = kk_std_core_types__lp__plus__plus__rp_(_x_x146, _x_x148, _ctx); /*string*/
  _x_x141 = kk_std_core_types__lp__plus__plus__rp_(_x_x142, _x_x145, _ctx); /*string*/
  _x_x138 = kk_std_core_types__lp__plus__plus__rp_(_x_x139, _x_x141, _ctx); /*string*/
  _x_x134 = kk_std_core_types__lp__plus__plus__rp_(_x_x135, _x_x138, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x132, _x_x134, _ctx);
}

kk_string_t kk_src_shm__consumer_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x97;
  kk_string_t _x_x175 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x176;
  kk_define_string_literal(, _s_x177, 8, "\"header\"", _ctx)
  _x_x176 = kk_string_dup(_s_x177, _ctx); /*string*/
  _match_x97 = kk_string_contains(_x_x175,_x_x176,kk_context()); /*bool*/
  if (_match_x97) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x178, 6, "header", _ctx)
    return kk_string_dup(_s_x178, _ctx);
  }
  {
    bool _match_x98;
    kk_string_t _x_x179 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x180;
    kk_define_string_literal(, _s_x181, 6, "\"read\"", _ctx)
    _x_x180 = kk_string_dup(_s_x181, _ctx); /*string*/
    _match_x98 = kk_string_contains(_x_x179,_x_x180,kk_context()); /*bool*/
    if (_match_x98) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x182, 4, "read", _ctx)
      return kk_string_dup(_s_x182, _ctx);
    }
    {
      bool _match_x99;
      kk_string_t _x_x183 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x184;
      kk_define_string_literal(, _s_x185, 8, "\"status\"", _ctx)
      _x_x184 = kk_string_dup(_s_x185, _ctx); /*string*/
      _match_x99 = kk_string_contains(_x_x183,_x_x184,kk_context()); /*bool*/
      if (_match_x99) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x186, 6, "status", _ctx)
        return kk_string_dup(_s_x186, _ctx);
      }
      {
        bool _match_x100;
        kk_string_t _x_x187;
        kk_define_string_literal(, _s_x188, 6, "\"quit\"", _ctx)
        _x_x187 = kk_string_dup(_s_x188, _ctx); /*string*/
        _match_x100 = kk_string_contains(line,_x_x187,kk_context()); /*bool*/
        if (_match_x100) {
          kk_define_string_literal(, _s_x189, 4, "quit", _ctx)
          return kk_string_dup(_s_x189, _ctx);
        }
        {
          kk_define_string_literal(, _s_x190, 7, "unknown", _ctx)
          return kk_string_dup(_s_x190, _ctx);
        }
      }
    }
  }
}
 
// monadic lift

kk_unit_t kk_src_shm__consumer__mlift_server_loop_10158(int64_t addr, kk_string_t op, kk_string_t _c_x10114, kk_context_t* _ctx) { /* (addr : int64, op : string, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10114, _ctx);
  bool _match_x96;
  kk_string_t _x_x191;
  kk_define_string_literal(, _s_x192, 4, "quit", _ctx)
  _x_x191 = kk_string_dup(_s_x192, _ctx); /*string*/
  _match_x96 = kk_string_is_neq(op,_x_x191,kk_context()); /*bool*/
  if (_match_x96) {
    kk_src_shm__consumer_server_loop(addr, _ctx); return kk_Unit;
  }
  {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_integer_t x = kk_src_shm__consumer_shm_unmap(addr, kk_integer_from_int(1544704, _ctx), _ctx); /*int*/;
    kk_integer_drop(x, _ctx);
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_shm__consumer__mlift_server_loop_10159_fun197__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun197(kk_function_t _fself, kk_box_t _b_x8, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer__new_mlift_server_loop_10159_fun197(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_shm__consumer__mlift_server_loop_10159_fun197, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun197(kk_function_t _fself, kk_box_t _b_x8, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x198;
  kk_string_t _x_x199 = kk_string_unbox(_b_x8); /*string*/
  _x_x198 = kk_src_shm__consumer_extract_op(_x_x199, _ctx); /*string*/
  return kk_string_box(_x_x198);
}


// lift anonymous function
struct kk_src_shm__consumer__mlift_server_loop_10159_fun202__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun202(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer__new_mlift_server_loop_10159_fun202(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_shm__consumer__mlift_server_loop_10159_fun202, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun202(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_shm__consumer__shm_header _x_x203;
  int64_t _x_x204 = kk_int64_unbox(_b_x13, KK_OWNED, _ctx); /*int64*/
  _x_x203 = kk_src_shm__consumer_read_header(_x_x204, _ctx); /*src/shm_consumer/shm-header*/
  return kk_src_shm__consumer__shm_header_box(_x_x203, _ctx);
}


// lift anonymous function
struct kk_src_shm__consumer__mlift_server_loop_10159_fun206__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun206(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer__new_mlift_server_loop_10159_fun206(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_shm__consumer__mlift_server_loop_10159_fun206, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun206(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x207;
  kk_src_shm__consumer__shm_header _x_x208 = kk_src_shm__consumer__shm_header_unbox(_b_x18, KK_OWNED, _ctx); /*src/shm_consumer/shm-header*/
  _x_x207 = kk_src_shm__consumer_json_header(_x_x208, _ctx); /*string*/
  return kk_string_box(_x_x207);
}


// lift anonymous function
struct kk_src_shm__consumer__mlift_server_loop_10159_fun210__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun210(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer__new_mlift_server_loop_10159_fun210(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_shm__consumer__mlift_server_loop_10159_fun210, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun210(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_shm__consumer__shm_header _x_x211;
  int64_t _x_x212 = kk_int64_unbox(_b_x21, KK_OWNED, _ctx); /*int64*/
  _x_x211 = kk_src_shm__consumer_read_header(_x_x212, _ctx); /*src/shm_consumer/shm-header*/
  return kk_src_shm__consumer__shm_header_box(_x_x211, _ctx);
}


// lift anonymous function
struct kk_src_shm__consumer__mlift_server_loop_10159_fun218__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun218(kk_function_t _fself, kk_box_t _b_x27, kk_box_t _b_x28, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer__new_mlift_server_loop_10159_fun218(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_shm__consumer__mlift_server_loop_10159_fun218, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun218(kk_function_t _fself, kk_box_t _b_x27, kk_box_t _b_x28, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x219;
  int64_t _x_x220 = kk_int64_unbox(_b_x27, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x221 = kk_integer_unbox(_b_x28, _ctx); /*int*/
  _x_x219 = kk_src_shm__consumer_shm_read_int(_x_x220, _x_x221, _ctx); /*int*/
  return kk_integer_box(_x_x219, _ctx);
}


// lift anonymous function
struct kk_src_shm__consumer__mlift_server_loop_10159_fun243__t {
  struct kk_function_s _base;
  kk_string_t op_0;
  int64_t addr_0;
};
static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun243(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer__new_mlift_server_loop_10159_fun243(kk_string_t op_0, int64_t addr_0, kk_context_t* _ctx) {
  struct kk_src_shm__consumer__mlift_server_loop_10159_fun243__t* _self = kk_function_alloc_as(struct kk_src_shm__consumer__mlift_server_loop_10159_fun243__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_shm__consumer__mlift_server_loop_10159_fun243, kk_context());
  _self->op_0 = op_0;
  _self->addr_0 = addr_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_shm__consumer__mlift_server_loop_10159_fun243(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx) {
  struct kk_src_shm__consumer__mlift_server_loop_10159_fun243__t* _self = kk_function_as(struct kk_src_shm__consumer__mlift_server_loop_10159_fun243__t*, _fself, _ctx);
  kk_string_t op_0 = _self->op_0; /* string */
  int64_t addr_0 = _self->addr_0; /* int64 */
  kk_drop_match(_self, {kk_string_dup(op_0, _ctx);kk_skip_dup(addr_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10114_0_37 = kk_string_unbox(_b_x35); /*string*/;
  kk_unit_t _x_x244 = kk_Unit;
  kk_src_shm__consumer__mlift_server_loop_10158(addr_0, op_0, _c_x10114_0_37, _ctx);
  return kk_unit_box(_x_x244);
}

kk_unit_t kk_src_shm__consumer__mlift_server_loop_10159(int64_t addr_0, kk_string_t line, kk_context_t* _ctx) { /* (addr : int64, line : string) -> <console/console,exn> () */ 
  bool _match_x91;
  kk_string_t _x_x193 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x194 = kk_string_empty(); /*string*/
  _match_x91 = kk_string_is_eq(_x_x193,_x_x194,kk_context()); /*bool*/
  if (_match_x91) {
    kk_string_drop(line, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_string_t op_0;
    kk_box_t _x_x196 = kk_std_core_hnd__open_none1(kk_src_shm__consumer__new_mlift_server_loop_10159_fun197(_ctx), kk_string_box(line), _ctx); /*10001*/
    op_0 = kk_string_unbox(_x_x196); /*string*/
    kk_string_t x_0_10163;
    if (kk_string_cmp_cstr_borrow(op_0, "header", _ctx) == 0) {
      kk_src_shm__consumer__shm_header h;
      kk_box_t _x_x201 = kk_std_core_hnd__open_none1(kk_src_shm__consumer__new_mlift_server_loop_10159_fun202(_ctx), kk_int64_box(addr_0, _ctx), _ctx); /*10001*/
      h = kk_src_shm__consumer__shm_header_unbox(_x_x201, KK_OWNED, _ctx); /*src/shm_consumer/shm-header*/
      kk_box_t _x_x205 = kk_std_core_hnd__open_none1(kk_src_shm__consumer__new_mlift_server_loop_10159_fun206(_ctx), kk_src_shm__consumer__shm_header_box(h, _ctx), _ctx); /*10001*/
      x_0_10163 = kk_string_unbox(_x_x205); /*string*/
      goto _match_x200;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "read", _ctx) == 0) {
      kk_src_shm__consumer__shm_header h_0;
      kk_box_t _x_x209 = kk_std_core_hnd__open_none1(kk_src_shm__consumer__new_mlift_server_loop_10159_fun210(_ctx), kk_int64_box(addr_0, _ctx), _ctx); /*10001*/
      h_0 = kk_src_shm__consumer__shm_header_unbox(_x_x209, KK_OWNED, _ctx); /*src/shm_consumer/shm-header*/
      kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_0 = kk_Unit;
      kk_evv_set(w_0,kk_context());
      bool _match_x93;
      kk_integer_t _brw_x94;
      {
        struct kk_src_shm__consumer_Shm_header* _con_x213 = kk_src_shm__consumer__as_Shm_header(h_0, _ctx);
        kk_integer_t _x = _con_x213->count;
        kk_integer_dup(_x, _ctx);
        _brw_x94 = _x; /*int*/
      }
      bool _brw_x95 = kk_integer_eq_borrow(_brw_x94,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x94, _ctx);
      _match_x93 = _brw_x95; /*bool*/
      if (_match_x93) {
        kk_datatype_ptr_dropn(h_0, (KK_I32(6)), _ctx);
        kk_define_string_literal(, _s_x214, 17, "{\"error\":\"empty\"}", _ctx)
        x_0_10163 = kk_string_dup(_s_x214, _ctx); /*string*/
        goto _match_x200;
      }
      {
        kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_1 = kk_Unit;
        kk_evv_set(w_1,kk_context());
        kk_integer_t y_10127;
        kk_integer_t _x_x215;
        {
          struct kk_src_shm__consumer_Shm_header* _con_x216 = kk_src_shm__consumer__as_Shm_header(h_0, _ctx);
          kk_integer_t _pat_0_1 = _con_x216->magic;
          kk_integer_t _pat_1_1 = _con_x216->version;
          kk_integer_t _pat_2_1 = _con_x216->capacity;
          kk_integer_t _pat_3_2 = _con_x216->count;
          kk_integer_t _pat_4_1 = _con_x216->write_pos;
          kk_integer_t _x_0 = _con_x216->read_pos;
          if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
            kk_integer_drop(_pat_4_1, _ctx);
            kk_integer_drop(_pat_3_2, _ctx);
            kk_integer_drop(_pat_2_1, _ctx);
            kk_integer_drop(_pat_1_1, _ctx);
            kk_integer_drop(_pat_0_1, _ctx);
            kk_datatype_ptr_free(h_0, _ctx);
          }
          else {
            kk_integer_dup(_x_0, _ctx);
            kk_datatype_ptr_decref(h_0, _ctx);
          }
          _x_x215 = _x_0; /*int*/
        }
        y_10127 = kk_integer_mul(_x_x215,(kk_integer_from_small(1544)),kk_context()); /*int*/
        kk_integer_t offset = kk_integer_add_small_const(y_10127, 64, _ctx); /*int*/;
        kk_integer_t id;
        kk_box_t _x_x217 = kk_std_core_hnd__open_none2(kk_src_shm__consumer__new_mlift_server_loop_10159_fun218(_ctx), kk_int64_box(addr_0, _ctx), kk_integer_box(offset, _ctx), _ctx); /*10002*/
        id = kk_integer_unbox(_x_x217, _ctx); /*int*/
        kk_string_t _x_x222;
        kk_define_string_literal(, _s_x223, 6, "{\"id\":", _ctx)
        _x_x222 = kk_string_dup(_s_x223, _ctx); /*string*/
        kk_string_t _x_x224;
        kk_string_t _x_x225 = kk_std_core_int_show(id, _ctx); /*string*/
        kk_string_t _x_x226;
        kk_string_t _x_x227;
        kk_define_string_literal(, _s_x228, 7, ",\"dim\":", _ctx)
        _x_x227 = kk_string_dup(_s_x228, _ctx); /*string*/
        kk_string_t _x_x229;
        kk_string_t _x_x230 = kk_std_core_int_show(kk_integer_from_small(384), _ctx); /*string*/
        kk_string_t _x_x231;
        kk_define_string_literal(, _s_x232, 1, "}", _ctx)
        _x_x231 = kk_string_dup(_s_x232, _ctx); /*string*/
        _x_x229 = kk_std_core_types__lp__plus__plus__rp_(_x_x230, _x_x231, _ctx); /*string*/
        _x_x226 = kk_std_core_types__lp__plus__plus__rp_(_x_x227, _x_x229, _ctx); /*string*/
        _x_x224 = kk_std_core_types__lp__plus__plus__rp_(_x_x225, _x_x226, _ctx); /*string*/
        x_0_10163 = kk_std_core_types__lp__plus__plus__rp_(_x_x222, _x_x224, _ctx); /*string*/
        goto _match_x200;
      }
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_string_t _x_x233;
      kk_define_string_literal(, _s_x234, 28, "{\"shm_consumer\":true,\"addr\":", _ctx)
      _x_x233 = kk_string_dup(_s_x234, _ctx); /*string*/
      kk_string_t _x_x235;
      kk_string_t _x_x236;
      kk_integer_t _x_x237 = kk_integer_from_int64(addr_0,kk_context()); /*int*/
      _x_x236 = kk_std_core_int_show(_x_x237, _ctx); /*string*/
      kk_string_t _x_x238;
      kk_define_string_literal(, _s_x239, 1, "}", _ctx)
      _x_x238 = kk_string_dup(_s_x239, _ctx); /*string*/
      _x_x235 = kk_std_core_types__lp__plus__plus__rp_(_x_x236, _x_x238, _ctx); /*string*/
      x_0_10163 = kk_std_core_types__lp__plus__plus__rp_(_x_x233, _x_x235, _ctx); /*string*/
      goto _match_x200;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "quit", _ctx) == 0) {
      kk_define_string_literal(, _s_x240, 20, "{\"status\":\"stopped\"}", _ctx)
      x_0_10163 = kk_string_dup(_s_x240, _ctx); /*string*/
      goto _match_x200;
    }
    {
      kk_define_string_literal(, _s_x241, 22, "{\"error\":\"unknown op\"}", _ctx)
      x_0_10163 = kk_string_dup(_s_x241, _ctx); /*string*/
    }
    _match_x200: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10163, _ctx);
      kk_box_t _x_x242 = kk_std_core_hnd_yield_extend(kk_src_shm__consumer__new_mlift_server_loop_10159_fun243(op_0, addr_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x242); return kk_Unit;
    }
    {
      kk_src_shm__consumer__mlift_server_loop_10158(addr_0, op_0, x_0_10163, _ctx); return kk_Unit;
    }
  }
}


// lift anonymous function
struct kk_src_shm__consumer_server_loop_fun246__t {
  struct kk_function_s _base;
  int64_t addr_1;
};
static kk_box_t kk_src_shm__consumer_server_loop_fun246(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer_new_server_loop_fun246(int64_t addr_1, kk_context_t* _ctx) {
  struct kk_src_shm__consumer_server_loop_fun246__t* _self = kk_function_alloc_as(struct kk_src_shm__consumer_server_loop_fun246__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_shm__consumer_server_loop_fun246, kk_context());
  _self->addr_1 = addr_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_shm__consumer_server_loop_fun246(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx) {
  struct kk_src_shm__consumer_server_loop_fun246__t* _self = kk_function_as(struct kk_src_shm__consumer_server_loop_fun246__t*, _fself, _ctx);
  int64_t addr_1 = _self->addr_1; /* int64 */
  kk_drop_match(_self, {kk_skip_dup(addr_1, _ctx);}, {}, _ctx)
  kk_string_t line_0_72 = kk_string_unbox(_b_x39); /*string*/;
  kk_unit_t _x_x247 = kk_Unit;
  kk_src_shm__consumer__mlift_server_loop_10159(addr_1, line_0_72, _ctx);
  return kk_unit_box(_x_x247);
}


// lift anonymous function
struct kk_src_shm__consumer_server_loop_fun252__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_shm__consumer_server_loop_fun252(kk_function_t _fself, kk_box_t _b_x42, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer_new_server_loop_fun252(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_shm__consumer_server_loop_fun252, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_shm__consumer_server_loop_fun252(kk_function_t _fself, kk_box_t _b_x42, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x253;
  kk_string_t _x_x254 = kk_string_unbox(_b_x42); /*string*/
  _x_x253 = kk_src_shm__consumer_extract_op(_x_x254, _ctx); /*string*/
  return kk_string_box(_x_x253);
}


// lift anonymous function
struct kk_src_shm__consumer_server_loop_fun257__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_shm__consumer_server_loop_fun257(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer_new_server_loop_fun257(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_shm__consumer_server_loop_fun257, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_shm__consumer_server_loop_fun257(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_shm__consumer__shm_header _x_x258;
  int64_t _x_x259 = kk_int64_unbox(_b_x47, KK_OWNED, _ctx); /*int64*/
  _x_x258 = kk_src_shm__consumer_read_header(_x_x259, _ctx); /*src/shm_consumer/shm-header*/
  return kk_src_shm__consumer__shm_header_box(_x_x258, _ctx);
}


// lift anonymous function
struct kk_src_shm__consumer_server_loop_fun261__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_shm__consumer_server_loop_fun261(kk_function_t _fself, kk_box_t _b_x52, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer_new_server_loop_fun261(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_shm__consumer_server_loop_fun261, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_shm__consumer_server_loop_fun261(kk_function_t _fself, kk_box_t _b_x52, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x262;
  kk_src_shm__consumer__shm_header _x_x263 = kk_src_shm__consumer__shm_header_unbox(_b_x52, KK_OWNED, _ctx); /*src/shm_consumer/shm-header*/
  _x_x262 = kk_src_shm__consumer_json_header(_x_x263, _ctx); /*string*/
  return kk_string_box(_x_x262);
}


// lift anonymous function
struct kk_src_shm__consumer_server_loop_fun265__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_shm__consumer_server_loop_fun265(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer_new_server_loop_fun265(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_shm__consumer_server_loop_fun265, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_shm__consumer_server_loop_fun265(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_shm__consumer__shm_header _x_x266;
  int64_t _x_x267 = kk_int64_unbox(_b_x55, KK_OWNED, _ctx); /*int64*/
  _x_x266 = kk_src_shm__consumer_read_header(_x_x267, _ctx); /*src/shm_consumer/shm-header*/
  return kk_src_shm__consumer__shm_header_box(_x_x266, _ctx);
}


// lift anonymous function
struct kk_src_shm__consumer_server_loop_fun273__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_shm__consumer_server_loop_fun273(kk_function_t _fself, kk_box_t _b_x61, kk_box_t _b_x62, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer_new_server_loop_fun273(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_shm__consumer_server_loop_fun273, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_shm__consumer_server_loop_fun273(kk_function_t _fself, kk_box_t _b_x61, kk_box_t _b_x62, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x274;
  int64_t _x_x275 = kk_int64_unbox(_b_x61, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x276 = kk_integer_unbox(_b_x62, _ctx); /*int*/
  _x_x274 = kk_src_shm__consumer_shm_read_int(_x_x275, _x_x276, _ctx); /*int*/
  return kk_integer_box(_x_x274, _ctx);
}


// lift anonymous function
struct kk_src_shm__consumer_server_loop_fun298__t {
  struct kk_function_s _base;
  kk_string_t op_1;
  int64_t addr_1;
};
static kk_box_t kk_src_shm__consumer_server_loop_fun298(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer_new_server_loop_fun298(kk_string_t op_1, int64_t addr_1, kk_context_t* _ctx) {
  struct kk_src_shm__consumer_server_loop_fun298__t* _self = kk_function_alloc_as(struct kk_src_shm__consumer_server_loop_fun298__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_shm__consumer_server_loop_fun298, kk_context());
  _self->op_1 = op_1;
  _self->addr_1 = addr_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_shm__consumer_server_loop_fun298(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx) {
  struct kk_src_shm__consumer_server_loop_fun298__t* _self = kk_function_as(struct kk_src_shm__consumer_server_loop_fun298__t*, _fself, _ctx);
  kk_string_t op_1 = _self->op_1; /* string */
  int64_t addr_1 = _self->addr_1; /* int64 */
  kk_drop_match(_self, {kk_string_dup(op_1, _ctx);kk_skip_dup(addr_1, _ctx);}, {}, _ctx)
  kk_string_t _c_x10114_1_73 = kk_string_unbox(_b_x69); /*string*/;
  kk_unit_t _x_x299 = kk_Unit;
  kk_src_shm__consumer__mlift_server_loop_10158(addr_1, op_1, _c_x10114_1_73, _ctx);
  return kk_unit_box(_x_x299);
}

kk_unit_t kk_src_shm__consumer_server_loop(int64_t addr_1, kk_context_t* _ctx) { /* (addr : int64) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_3_10169 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_3_10169, _ctx);
    kk_box_t _x_x245 = kk_std_core_hnd_yield_extend(kk_src_shm__consumer_new_server_loop_fun246(addr_1, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x245); return kk_Unit;
  }
  {
    bool _match_x85;
    kk_string_t _x_x248 = kk_string_dup(x_3_10169, _ctx); /*string*/
    kk_string_t _x_x249 = kk_string_empty(); /*string*/
    _match_x85 = kk_string_is_eq(_x_x248,_x_x249,kk_context()); /*bool*/
    if (_match_x85) {
      kk_string_drop(x_3_10169, _ctx);
      kk_Unit; return kk_Unit;
    }
    {
      kk_string_t op_1;
      kk_box_t _x_x251 = kk_std_core_hnd__open_none1(kk_src_shm__consumer_new_server_loop_fun252(_ctx), kk_string_box(x_3_10169), _ctx); /*10001*/
      op_1 = kk_string_unbox(_x_x251); /*string*/
      kk_string_t x_4_10172;
      if (kk_string_cmp_cstr_borrow(op_1, "header", _ctx) == 0) {
        kk_src_shm__consumer__shm_header h_1;
        kk_box_t _x_x256 = kk_std_core_hnd__open_none1(kk_src_shm__consumer_new_server_loop_fun257(_ctx), kk_int64_box(addr_1, _ctx), _ctx); /*10001*/
        h_1 = kk_src_shm__consumer__shm_header_unbox(_x_x256, KK_OWNED, _ctx); /*src/shm_consumer/shm-header*/
        kk_box_t _x_x260 = kk_std_core_hnd__open_none1(kk_src_shm__consumer_new_server_loop_fun261(_ctx), kk_src_shm__consumer__shm_header_box(h_1, _ctx), _ctx); /*10001*/
        x_4_10172 = kk_string_unbox(_x_x260); /*string*/
        goto _match_x255;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "read", _ctx) == 0) {
        kk_src_shm__consumer__shm_header h_0_0;
        kk_box_t _x_x264 = kk_std_core_hnd__open_none1(kk_src_shm__consumer_new_server_loop_fun265(_ctx), kk_int64_box(addr_1, _ctx), _ctx); /*10001*/
        h_0_0 = kk_src_shm__consumer__shm_header_unbox(_x_x264, KK_OWNED, _ctx); /*src/shm_consumer/shm-header*/
        kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_2 = kk_Unit;
        kk_evv_set(w_2,kk_context());
        bool _match_x88;
        kk_integer_t _brw_x89;
        {
          struct kk_src_shm__consumer_Shm_header* _con_x268 = kk_src_shm__consumer__as_Shm_header(h_0_0, _ctx);
          kk_integer_t _x_1 = _con_x268->count;
          kk_integer_dup(_x_1, _ctx);
          _brw_x89 = _x_1; /*int*/
        }
        bool _brw_x90 = kk_integer_eq_borrow(_brw_x89,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        kk_integer_drop(_brw_x89, _ctx);
        _match_x88 = _brw_x90; /*bool*/
        if (_match_x88) {
          kk_datatype_ptr_dropn(h_0_0, (KK_I32(6)), _ctx);
          kk_define_string_literal(, _s_x269, 17, "{\"error\":\"empty\"}", _ctx)
          x_4_10172 = kk_string_dup(_s_x269, _ctx); /*string*/
          goto _match_x255;
        }
        {
          kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_3 = kk_Unit;
          kk_evv_set(w_3,kk_context());
          kk_integer_t y_10127_0;
          kk_integer_t _x_x270;
          {
            struct kk_src_shm__consumer_Shm_header* _con_x271 = kk_src_shm__consumer__as_Shm_header(h_0_0, _ctx);
            kk_integer_t _pat_0_1_0 = _con_x271->magic;
            kk_integer_t _pat_1_1_0 = _con_x271->version;
            kk_integer_t _pat_2_1_0 = _con_x271->capacity;
            kk_integer_t _pat_3_2_0 = _con_x271->count;
            kk_integer_t _pat_4_1_0 = _con_x271->write_pos;
            kk_integer_t _x_0_0 = _con_x271->read_pos;
            if kk_likely(kk_datatype_ptr_is_unique(h_0_0, _ctx)) {
              kk_integer_drop(_pat_4_1_0, _ctx);
              kk_integer_drop(_pat_3_2_0, _ctx);
              kk_integer_drop(_pat_2_1_0, _ctx);
              kk_integer_drop(_pat_1_1_0, _ctx);
              kk_integer_drop(_pat_0_1_0, _ctx);
              kk_datatype_ptr_free(h_0_0, _ctx);
            }
            else {
              kk_integer_dup(_x_0_0, _ctx);
              kk_datatype_ptr_decref(h_0_0, _ctx);
            }
            _x_x270 = _x_0_0; /*int*/
          }
          y_10127_0 = kk_integer_mul(_x_x270,(kk_integer_from_small(1544)),kk_context()); /*int*/
          kk_integer_t offset_0 = kk_integer_add_small_const(y_10127_0, 64, _ctx); /*int*/;
          kk_integer_t id_0;
          kk_box_t _x_x272 = kk_std_core_hnd__open_none2(kk_src_shm__consumer_new_server_loop_fun273(_ctx), kk_int64_box(addr_1, _ctx), kk_integer_box(offset_0, _ctx), _ctx); /*10002*/
          id_0 = kk_integer_unbox(_x_x272, _ctx); /*int*/
          kk_string_t _x_x277;
          kk_define_string_literal(, _s_x278, 6, "{\"id\":", _ctx)
          _x_x277 = kk_string_dup(_s_x278, _ctx); /*string*/
          kk_string_t _x_x279;
          kk_string_t _x_x280 = kk_std_core_int_show(id_0, _ctx); /*string*/
          kk_string_t _x_x281;
          kk_string_t _x_x282;
          kk_define_string_literal(, _s_x283, 7, ",\"dim\":", _ctx)
          _x_x282 = kk_string_dup(_s_x283, _ctx); /*string*/
          kk_string_t _x_x284;
          kk_string_t _x_x285 = kk_std_core_int_show(kk_integer_from_small(384), _ctx); /*string*/
          kk_string_t _x_x286;
          kk_define_string_literal(, _s_x287, 1, "}", _ctx)
          _x_x286 = kk_string_dup(_s_x287, _ctx); /*string*/
          _x_x284 = kk_std_core_types__lp__plus__plus__rp_(_x_x285, _x_x286, _ctx); /*string*/
          _x_x281 = kk_std_core_types__lp__plus__plus__rp_(_x_x282, _x_x284, _ctx); /*string*/
          _x_x279 = kk_std_core_types__lp__plus__plus__rp_(_x_x280, _x_x281, _ctx); /*string*/
          x_4_10172 = kk_std_core_types__lp__plus__plus__rp_(_x_x277, _x_x279, _ctx); /*string*/
          goto _match_x255;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_1, "status", _ctx) == 0) {
        kk_string_t _x_x288;
        kk_define_string_literal(, _s_x289, 28, "{\"shm_consumer\":true,\"addr\":", _ctx)
        _x_x288 = kk_string_dup(_s_x289, _ctx); /*string*/
        kk_string_t _x_x290;
        kk_string_t _x_x291;
        kk_integer_t _x_x292 = kk_integer_from_int64(addr_1,kk_context()); /*int*/
        _x_x291 = kk_std_core_int_show(_x_x292, _ctx); /*string*/
        kk_string_t _x_x293;
        kk_define_string_literal(, _s_x294, 1, "}", _ctx)
        _x_x293 = kk_string_dup(_s_x294, _ctx); /*string*/
        _x_x290 = kk_std_core_types__lp__plus__plus__rp_(_x_x291, _x_x293, _ctx); /*string*/
        x_4_10172 = kk_std_core_types__lp__plus__plus__rp_(_x_x288, _x_x290, _ctx); /*string*/
        goto _match_x255;
      }
      if (kk_string_cmp_cstr_borrow(op_1, "quit", _ctx) == 0) {
        kk_define_string_literal(, _s_x295, 20, "{\"status\":\"stopped\"}", _ctx)
        x_4_10172 = kk_string_dup(_s_x295, _ctx); /*string*/
        goto _match_x255;
      }
      {
        kk_define_string_literal(, _s_x296, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_4_10172 = kk_string_dup(_s_x296, _ctx); /*string*/
      }
      _match_x255: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_4_10172, _ctx);
        kk_box_t _x_x297 = kk_std_core_hnd_yield_extend(kk_src_shm__consumer_new_server_loop_fun298(op_1, addr_1, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x297); return kk_Unit;
      }
      {
        kk_unit_t ___0 = kk_Unit;
        kk_std_core_console_printsln(x_4_10172, _ctx);
        bool _match_x87;
        kk_string_t _x_x300;
        kk_define_string_literal(, _s_x301, 4, "quit", _ctx)
        _x_x300 = kk_string_dup(_s_x301, _ctx); /*string*/
        _match_x87 = kk_string_is_neq(op_1,_x_x300,kk_context()); /*bool*/
        if (_match_x87) { // tailcall
                          goto kk__tailcall;
        }
        {
          kk_evv_t w_4 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_integer_t x_7 = kk_src_shm__consumer_shm_unmap(addr_1, kk_integer_from_int(1544704, _ctx), _ctx); /*int*/;
          kk_integer_drop(x_7, _ctx);
          kk_unit_t keep_4 = kk_Unit;
          kk_evv_set(w_4,kk_context());
          kk_Unit; return kk_Unit;
        }
      }
    }
  }
}


// lift anonymous function
struct kk_src_shm__consumer_main_fun315__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_shm__consumer_main_fun315(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx);
static kk_function_t kk_src_shm__consumer_new_main_fun315(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_shm__consumer_main_fun315, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_shm__consumer_main_fun315(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_shm__consumer__shm_header _x_x316;
  int64_t _x_x317 = kk_int64_unbox(_b_x76, KK_OWNED, _ctx); /*int64*/
  _x_x316 = kk_src_shm__consumer_read_header(_x_x317, _ctx); /*src/shm_consumer/shm-header*/
  return kk_src_shm__consumer__shm_header_box(_x_x316, _ctx);
}

kk_unit_t kk_src_shm__consumer_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x302;
  kk_string_t _x_x303;
  kk_define_string_literal(, _s_x304, 51, "{\"status\":\"starting\",\"shm_consumer\":true,\"target\":\"", _ctx)
  _x_x303 = kk_string_dup(_s_x304, _ctx); /*string*/
  kk_string_t _x_x305;
  kk_string_t _x_x306;
  kk_define_string_literal(, _s_x307, 23, "whitemagic_embed_bridge", _ctx)
  _x_x306 = kk_string_dup(_s_x307, _ctx); /*string*/
  kk_string_t _x_x308;
  kk_define_string_literal(, _s_x309, 2, "\"}", _ctx)
  _x_x308 = kk_string_dup(_s_x309, _ctx); /*string*/
  _x_x305 = kk_std_core_types__lp__plus__plus__rp_(_x_x306, _x_x308, _ctx); /*string*/
  _x_x302 = kk_std_core_types__lp__plus__plus__rp_(_x_x303, _x_x305, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x302, _ctx);
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  int64_t x;
  kk_string_t _x_x310;
  kk_define_string_literal(, _s_x311, 23, "whitemagic_embed_bridge", _ctx)
  _x_x310 = kk_string_dup(_s_x311, _ctx); /*string*/
  x = kk_src_shm__consumer_shm_open_map(_x_x310, kk_integer_from_int(1544704, _ctx), _ctx); /*int64*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  int64_t x_0 = (KK_I64(0)); /*int64*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  bool _match_x79 = (x == x_0); /*bool*/;
  if (_match_x79) {
    kk_string_t _x_x312;
    kk_define_string_literal(, _s_x313, 69, "{\"error\":\"failed to open shared memory - producer must create first\"}", _ctx)
    _x_x312 = kk_string_dup(_s_x313, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x312, _ctx); return kk_Unit;
  }
  {
    kk_src_shm__consumer__shm_header header;
    kk_box_t _x_x314 = kk_std_core_hnd__open_none1(kk_src_shm__consumer_new_main_fun315(_ctx), kk_int64_box(x, _ctx), _ctx); /*10001*/
    header = kk_src_shm__consumer__shm_header_unbox(_x_x314, KK_OWNED, _ctx); /*src/shm_consumer/shm-header*/
    kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_1 = kk_Unit;
    kk_evv_set(w_1,kk_context());
    bool _match_x80;
    kk_integer_t _brw_x82;
    {
      struct kk_src_shm__consumer_Shm_header* _con_x318 = kk_src_shm__consumer__as_Shm_header(header, _ctx);
      kk_integer_t _x = _con_x318->magic;
      kk_integer_dup(_x, _ctx);
      _brw_x82 = _x; /*int*/
    }
    kk_integer_t _brw_x81 = kk_integer_from_int(1464264013, _ctx); /*int*/;
    bool _brw_x83 = kk_integer_neq_borrow(_brw_x82,_brw_x81,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x82, _ctx);
    kk_integer_drop(_brw_x81, _ctx);
    _match_x80 = _brw_x83; /*bool*/
    if (_match_x80) {
      kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_2 = kk_Unit;
      kk_evv_set(w_2,kk_context());
      kk_unit_t ___0 = kk_Unit;
      kk_string_t _x_x319;
      kk_string_t _x_x320;
      kk_define_string_literal(, _s_x321, 30, "{\"error\":\"invalid magic - got ", _ctx)
      _x_x320 = kk_string_dup(_s_x321, _ctx); /*string*/
      kk_string_t _x_x322;
      kk_string_t _x_x323;
      kk_integer_t _x_x324;
      {
        struct kk_src_shm__consumer_Shm_header* _con_x325 = kk_src_shm__consumer__as_Shm_header(header, _ctx);
        kk_integer_t _x_0 = _con_x325->magic;
        kk_integer_t _pat_0_1 = _con_x325->version;
        kk_integer_t _pat_1_2 = _con_x325->capacity;
        kk_integer_t _pat_2_0 = _con_x325->count;
        kk_integer_t _pat_3_0 = _con_x325->write_pos;
        kk_integer_t _pat_4_0 = _con_x325->read_pos;
        if kk_likely(kk_datatype_ptr_is_unique(header, _ctx)) {
          kk_integer_drop(_pat_4_0, _ctx);
          kk_integer_drop(_pat_3_0, _ctx);
          kk_integer_drop(_pat_2_0, _ctx);
          kk_integer_drop(_pat_1_2, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(header, _ctx);
        }
        else {
          kk_integer_dup(_x_0, _ctx);
          kk_datatype_ptr_decref(header, _ctx);
        }
        _x_x324 = _x_0; /*int*/
      }
      _x_x323 = kk_std_core_int_show(_x_x324, _ctx); /*string*/
      kk_string_t _x_x326;
      kk_define_string_literal(, _s_x327, 2, "\"}", _ctx)
      _x_x326 = kk_string_dup(_s_x327, _ctx); /*string*/
      _x_x322 = kk_std_core_types__lp__plus__plus__rp_(_x_x323, _x_x326, _ctx); /*string*/
      _x_x319 = kk_std_core_types__lp__plus__plus__rp_(_x_x320, _x_x322, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x319, _ctx);
      kk_evv_t w_2_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_integer_t x_2_0 = kk_src_shm__consumer_shm_unmap(x, kk_integer_from_int(1544704, _ctx), _ctx); /*int*/;
      kk_integer_drop(x_2_0, _ctx);
      kk_unit_t keep_2_0 = kk_Unit;
      kk_evv_set(w_2_0,kk_context());
      kk_Unit; return kk_Unit;
    }
    {
      kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_3 = kk_Unit;
      kk_evv_set(w_3,kk_context());
      kk_unit_t ___1 = kk_Unit;
      kk_string_t _x_x328;
      kk_string_t _x_x329;
      kk_define_string_literal(, _s_x330, 48, "{\"status\":\"started\",\"connected\":true,\"capacity\":", _ctx)
      _x_x329 = kk_string_dup(_s_x330, _ctx); /*string*/
      kk_string_t _x_x331;
      kk_string_t _x_x332;
      kk_integer_t _x_x333;
      {
        struct kk_src_shm__consumer_Shm_header* _con_x334 = kk_src_shm__consumer__as_Shm_header(header, _ctx);
        kk_integer_t _pat_0_2 = _con_x334->magic;
        kk_integer_t _pat_1_3 = _con_x334->version;
        kk_integer_t _x_1 = _con_x334->capacity;
        kk_integer_t _pat_2_2 = _con_x334->count;
        kk_integer_t _pat_3_2 = _con_x334->write_pos;
        kk_integer_t _pat_4_1 = _con_x334->read_pos;
        if kk_likely(kk_datatype_ptr_is_unique(header, _ctx)) {
          kk_integer_drop(_pat_4_1, _ctx);
          kk_integer_drop(_pat_3_2, _ctx);
          kk_integer_drop(_pat_2_2, _ctx);
          kk_integer_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(header, _ctx);
        }
        else {
          kk_integer_dup(_x_1, _ctx);
          kk_datatype_ptr_decref(header, _ctx);
        }
        _x_x333 = _x_1; /*int*/
      }
      _x_x332 = kk_std_core_int_show(_x_x333, _ctx); /*string*/
      kk_string_t _x_x335;
      kk_define_string_literal(, _s_x336, 1, "}", _ctx)
      _x_x335 = kk_string_dup(_s_x336, _ctx); /*string*/
      _x_x331 = kk_std_core_types__lp__plus__plus__rp_(_x_x332, _x_x335, _ctx); /*string*/
      _x_x328 = kk_std_core_types__lp__plus__plus__rp_(_x_x329, _x_x331, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x328, _ctx);
      kk_src_shm__consumer_server_loop(x, _ctx); return kk_Unit;
    }
  }
}

// initialization
void kk_src_shm__consumer__init(kk_context_t* _ctx){
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
  kk_init_string_literal(kk_src_shm__consumer_shm_name, _ctx)
  {
    kk_src_shm__consumer_segment_size = kk_integer_from_int(1544704, _ctx); /*int*/
  }
  {
    kk_src_shm__consumer_header_size = kk_integer_from_small(64); /*int*/
  }
  {
    kk_src_shm__consumer_slot_size = kk_integer_from_small(1544); /*int*/
  }
  {
    kk_src_shm__consumer_embedding_dim = kk_integer_from_small(384); /*int*/
  }
  {
    kk_src_shm__consumer_magic_number = kk_integer_from_int(1464264013, _ctx); /*int*/
  }
}

// termination
void kk_src_shm__consumer__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_integer_drop(kk_src_shm__consumer_magic_number, _ctx);
  kk_integer_drop(kk_src_shm__consumer_embedding_dim, _ctx);
  kk_integer_drop(kk_src_shm__consumer_slot_size, _ctx);
  kk_integer_drop(kk_src_shm__consumer_header_size, _ctx);
  kk_integer_drop(kk_src_shm__consumer_segment_size, _ctx);
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
