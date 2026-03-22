// Koka generated module: whitemagic-koka/src/shm_search, koka version: 3.2.2, platform: 64-bit
#include "whitemagic_dash_koka_src_shm__search.h"
#ifndef SHM_SEARCH_H
#define SHM_SEARCH_H

#include <kklib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>

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

static inline double kk_shm_read_float32(int64_t addr, kk_integer_t offset, kk_context_t* ctx) {
    intptr_t off = kk_integer_clamp_ssize_t(offset, ctx);
    float val = *(float*)(addr + off);
    return (double)val;
}

#pragma GCC push_options
#pragma GCC optimize("O3,unroll-loops,tree-vectorize")
static inline kk_string_t kk_shm_search_top5(int64_t addr, kk_integer_t kk_count, kk_integer_t kk_query_idx, kk_context_t* ctx) {
    intptr_t count = kk_integer_clamp_ssize_t(kk_count, ctx);
    intptr_t query_idx = kk_integer_clamp_ssize_t(kk_query_idx, ctx);
    intptr_t dim = 384;
    intptr_t header_size = 64;
    intptr_t slot_size = 1540; // 4 bytes id + 384*4 bytes vector

    intptr_t query_off = header_size + (query_idx * slot_size) + 4;
    float* restrict q_vec = (float*)(addr + query_off);

    // Pre-calculate query magnitude
    float q_mag = 0.0f;
    for (int i = 0; i < dim; i++) {
        q_mag += q_vec[i] * q_vec[i];
    }
    
    // We want top 5 scores
    float best_scores[5] = {-2.0f, -2.0f, -2.0f, -2.0f, -2.0f};
    int32_t best_ids[5] = {0, 0, 0, 0, 0};

    for (intptr_t i = 0; i < count; i++) {
        intptr_t item_off = header_size + (i * slot_size);
        int32_t item_id = *(int32_t*)(addr + item_off);
        float* restrict vec = (float*)(addr + item_off + 4);
        
        float dot = 0.0f;
        float v_mag = 0.0f;
        
        #pragma GCC ivdep
        for (intptr_t j = 0; j < dim; j++) {
            float a = q_vec[j];
            float b = vec[j];
            dot += a * b;
            v_mag += b * b;
        }
        
        float score = 0.0f;
        if (q_mag > 0.0f && v_mag > 0.0f) {
            score = dot / (sqrtf(q_mag) * sqrtf(v_mag));
        }
        
        if (score > best_scores[4]) {
            best_scores[4] = score;
            best_ids[4] = item_id;
            
            // Bubble up
            for (int k = 4; k > 0; k--) {
                if (best_scores[k] > best_scores[k-1]) {
                    float tmp_s = best_scores[k-1];
                    best_scores[k-1] = best_scores[k];
                    best_scores[k] = tmp_s;
                    
                    int32_t tmp_i = best_ids[k-1];
                    best_ids[k-1] = best_ids[k];
                    best_ids[k] = tmp_i;
                } else {
                    break;
                }
            }
        }
    }

    char buf[512];
    snprintf(buf, sizeof(buf), "[{\"id\":%d,\"score\":%.6f},{\"id\":%d,\"score\":%.6f},{\"id\":%d,\"score\":%.6f},{\"id\":%d,\"score\":%.6f},{\"id\":%d,\"score\":%.6f}]",
             best_ids[0], best_scores[0],
             best_ids[1], best_scores[1],
             best_ids[2], best_scores[2],
             best_ids[3], best_scores[3],
             best_ids[4], best_scores[4]);

    return kk_string_alloc_from_utf8(buf, ctx);
}
#pragma GCC pop_options

#endif

 
// Open and map shared memory, returns pointer (0 on error)

int64_t kk_whitemagic_dash_koka_src_shm__search_shm_open_map(kk_string_t name, kk_integer_t size, kk_context_t* _ctx) { /* (name : string, size : int) -> int64 */ 
  return kk_shm_open_map(name,size,kk_context());
}
 
// Unmap shared memory

kk_integer_t kk_whitemagic_dash_koka_src_shm__search_shm_unmap(int64_t addr, kk_integer_t size, kk_context_t* _ctx) { /* (addr : int64, size : int) -> int */ 
  return kk_shm_unmap(addr,size,kk_context());
}
 
// Read int32 at offset

kk_integer_t kk_whitemagic_dash_koka_src_shm__search_shm_read_int(int64_t addr, kk_integer_t offset, kk_context_t* _ctx) { /* (addr : int64, offset : int) -> int */ 
  return kk_shm_read_int(addr,offset,kk_context());
}
 
// Fast C-optimized cosine similarity

kk_string_t kk_whitemagic_dash_koka_src_shm__search_shm_search_top5(int64_t addr, kk_integer_t count, kk_integer_t query_item_id, kk_context_t* _ctx) { /* (addr : int64, count : int, query-item-id : int) -> string */ 
  return kk_shm_search_top5(addr,count,query_item_id,kk_context());
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__search_flush_stdout(kk_context_t* _ctx) { /* () -> console/console () */ 
  fflush(stdout); return kk_Unit;
}
kk_declare_string_literal(static, kk_whitemagic_dash_koka_src_shm__search_shm_name, 29, "/whitemagic_embed_bridge_real")

kk_integer_t kk_whitemagic_dash_koka_src_shm__search_segment_size;

kk_integer_t kk_whitemagic_dash_koka_src_shm__search_header_size;

kk_integer_t kk_whitemagic_dash_koka_src_shm__search_slot_size;

kk_integer_t kk_whitemagic_dash_koka_src_shm__search_embedding_dim;

kk_integer_t kk_whitemagic_dash_koka_src_shm__search_magic_number;

kk_whitemagic_dash_koka_src_shm__search__shm_header kk_whitemagic_dash_koka_src_shm__search_shm_header_fs__copy(kk_whitemagic_dash_koka_src_shm__search__shm_header _this, kk_std_core_types__optional magic, kk_std_core_types__optional version, kk_std_core_types__optional capacity, kk_std_core_types__optional count, kk_std_core_types__optional write_pos, kk_std_core_types__optional read_pos, kk_context_t* _ctx) { /* (shm-header, magic : ? int, version : ? int, capacity : ? int, count : ? int, write-pos : ? int, read-pos : ? int) -> shm-header */ 
  kk_integer_t _x_x212;
  if (kk_std_core_types__is_Optional(magic, _ctx)) {
    kk_box_t _box_x0 = magic._cons._Optional.value;
    kk_integer_t _uniq_magic_132 = kk_integer_unbox(_box_x0, _ctx);
    kk_integer_dup(_uniq_magic_132, _ctx);
    kk_std_core_types__optional_drop(magic, _ctx);
    _x_x212 = _uniq_magic_132; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(magic, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x213 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
      kk_integer_t _x = _con_x213->magic;
      kk_integer_dup(_x, _ctx);
      _x_x212 = _x; /*int*/
    }
  }
  kk_integer_t _x_x214;
  if (kk_std_core_types__is_Optional(version, _ctx)) {
    kk_box_t _box_x1 = version._cons._Optional.value;
    kk_integer_t _uniq_version_140 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_version_140, _ctx);
    kk_std_core_types__optional_drop(version, _ctx);
    _x_x214 = _uniq_version_140; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(version, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x215 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
      kk_integer_t _x_0 = _con_x215->version;
      kk_integer_dup(_x_0, _ctx);
      _x_x214 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x216;
  if (kk_std_core_types__is_Optional(capacity, _ctx)) {
    kk_box_t _box_x2 = capacity._cons._Optional.value;
    kk_integer_t _uniq_capacity_148 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_capacity_148, _ctx);
    kk_std_core_types__optional_drop(capacity, _ctx);
    _x_x216 = _uniq_capacity_148; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(capacity, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x217 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
      kk_integer_t _x_1 = _con_x217->capacity;
      kk_integer_dup(_x_1, _ctx);
      _x_x216 = _x_1; /*int*/
    }
  }
  kk_integer_t _x_x218;
  if (kk_std_core_types__is_Optional(count, _ctx)) {
    kk_box_t _box_x3 = count._cons._Optional.value;
    kk_integer_t _uniq_count_156 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_count_156, _ctx);
    kk_std_core_types__optional_drop(count, _ctx);
    _x_x218 = _uniq_count_156; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(count, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x219 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
      kk_integer_t _x_2 = _con_x219->count;
      kk_integer_dup(_x_2, _ctx);
      _x_x218 = _x_2; /*int*/
    }
  }
  kk_integer_t _x_x220;
  if (kk_std_core_types__is_Optional(write_pos, _ctx)) {
    kk_box_t _box_x4 = write_pos._cons._Optional.value;
    kk_integer_t _uniq_write_pos_164 = kk_integer_unbox(_box_x4, _ctx);
    kk_integer_dup(_uniq_write_pos_164, _ctx);
    kk_std_core_types__optional_drop(write_pos, _ctx);
    _x_x220 = _uniq_write_pos_164; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(write_pos, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x221 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
      kk_integer_t _x_3 = _con_x221->write_pos;
      kk_integer_dup(_x_3, _ctx);
      _x_x220 = _x_3; /*int*/
    }
  }
  kk_integer_t _x_x222;
  if (kk_std_core_types__is_Optional(read_pos, _ctx)) {
    kk_box_t _box_x5 = read_pos._cons._Optional.value;
    kk_integer_t _uniq_read_pos_172 = kk_integer_unbox(_box_x5, _ctx);
    kk_integer_dup(_uniq_read_pos_172, _ctx);
    kk_std_core_types__optional_drop(read_pos, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(6)), _ctx);
    _x_x222 = _uniq_read_pos_172; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(read_pos, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x223 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
      kk_integer_t _pat_0_5 = _con_x223->magic;
      kk_integer_t _pat_1_6 = _con_x223->version;
      kk_integer_t _pat_2_5 = _con_x223->capacity;
      kk_integer_t _pat_3_5 = _con_x223->count;
      kk_integer_t _pat_4_5 = _con_x223->write_pos;
      kk_integer_t _x_4 = _con_x223->read_pos;
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
      _x_x222 = _x_4; /*int*/
    }
  }
  return kk_whitemagic_dash_koka_src_shm__search__new_Shm_header(kk_reuse_null, 0, _x_x212, _x_x214, _x_x216, _x_x218, _x_x220, _x_x222, _ctx);
}

kk_whitemagic_dash_koka_src_shm__search__shm_header kk_whitemagic_dash_koka_src_shm__search_read_header(int64_t addr, kk_context_t* _ctx) { /* (addr : int64) -> shm-header */ 
  kk_integer_t _x_x224 = kk_whitemagic_dash_koka_src_shm__search_shm_read_int(addr, kk_integer_from_small(0), _ctx); /*int*/
  kk_integer_t _x_x225 = kk_whitemagic_dash_koka_src_shm__search_shm_read_int(addr, kk_integer_from_small(4), _ctx); /*int*/
  kk_integer_t _x_x226 = kk_whitemagic_dash_koka_src_shm__search_shm_read_int(addr, kk_integer_from_small(8), _ctx); /*int*/
  kk_integer_t _x_x227 = kk_whitemagic_dash_koka_src_shm__search_shm_read_int(addr, kk_integer_from_small(12), _ctx); /*int*/
  kk_integer_t _x_x228 = kk_whitemagic_dash_koka_src_shm__search_shm_read_int(addr, kk_integer_from_small(16), _ctx); /*int*/
  kk_integer_t _x_x229 = kk_whitemagic_dash_koka_src_shm__search_shm_read_int(addr, kk_integer_from_small(20), _ctx); /*int*/
  return kk_whitemagic_dash_koka_src_shm__search__new_Shm_header(kk_reuse_null, 0, _x_x224, _x_x225, _x_x226, _x_x227, _x_x228, _x_x229, _ctx);
}

kk_string_t kk_whitemagic_dash_koka_src_shm__search_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x192;
  kk_string_t _x_x230 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x231;
  kk_define_string_literal(, _s_x232, 8, "\"search\"", _ctx)
  _x_x231 = kk_string_dup(_s_x232, _ctx); /*string*/
  _match_x192 = kk_string_contains(_x_x230,_x_x231,kk_context()); /*bool*/
  if (_match_x192) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x233, 6, "search", _ctx)
    return kk_string_dup(_s_x233, _ctx);
  }
  {
    bool _match_x193;
    kk_string_t _x_x234 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x235;
    kk_define_string_literal(, _s_x236, 8, "\"status\"", _ctx)
    _x_x235 = kk_string_dup(_s_x236, _ctx); /*string*/
    _match_x193 = kk_string_contains(_x_x234,_x_x235,kk_context()); /*bool*/
    if (_match_x193) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x237, 6, "status", _ctx)
      return kk_string_dup(_s_x237, _ctx);
    }
    {
      bool _match_x194;
      kk_string_t _x_x238;
      kk_define_string_literal(, _s_x239, 6, "\"quit\"", _ctx)
      _x_x238 = kk_string_dup(_s_x239, _ctx); /*string*/
      _match_x194 = kk_string_contains(line,_x_x238,kk_context()); /*bool*/
      if (_match_x194) {
        kk_define_string_literal(, _s_x240, 4, "quit", _ctx)
        return kk_string_dup(_s_x240, _ctx);
      }
      {
        kk_define_string_literal(, _s_x241, 7, "unknown", _ctx)
        return kk_string_dup(_s_x241, _ctx);
      }
    }
  }
}

kk_integer_t kk_whitemagic_dash_koka_src_shm__search_extract_query_id(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> int */ 
  kk_vector_t v_10011;
  kk_string_t _x_x242;
  kk_define_string_literal(, _s_x243, 11, "\"query_id\":", _ctx)
  _x_x242 = kk_string_dup(_s_x243, _ctx); /*string*/
  v_10011 = kk_string_splitv(line,_x_x242,kk_context()); /*vector<string>*/
  kk_std_core_types__list parts = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  if (kk_std_core_types__is_Cons(parts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x244 = kk_std_core_types__as_Cons(parts, _ctx);
    kk_box_t _box_x6 = _con_x244->head;
    kk_std_core_types__list _pat_1 = _con_x244->tail;
    if (kk_std_core_types__is_Cons(_pat_1, _ctx)) {
      struct kk_std_core_types_Cons* _con_x245 = kk_std_core_types__as_Cons(_pat_1, _ctx);
      kk_box_t _box_x7 = _con_x245->head;
      kk_string_t _pat_0 = kk_string_unbox(_box_x6);
      kk_std_core_types__list _pat_2 = _con_x245->tail;
      kk_string_t rest = kk_string_unbox(_box_x7);
      if kk_likely(kk_datatype_ptr_is_unique(parts, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_1, _ctx)) {
          kk_std_core_types__list_drop(_pat_2, _ctx);
          kk_datatype_ptr_free(_pat_1, _ctx);
        }
        else {
          kk_string_dup(rest, _ctx);
          kk_datatype_ptr_decref(_pat_1, _ctx);
        }
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(parts, _ctx);
      }
      else {
        kk_string_dup(rest, _ctx);
        kk_datatype_ptr_decref(parts, _ctx);
      }
      kk_vector_t v_10011_0;
      kk_string_t _x_x246;
      kk_define_string_literal(, _s_x247, 1, ",", _ctx)
      _x_x246 = kk_string_dup(_s_x247, _ctx); /*string*/
      v_10011_0 = kk_string_splitv(rest,_x_x246,kk_context()); /*vector<string>*/
      kk_std_core_types__list _match_x189 = kk_std_core_vector_vlist(v_10011_0, kk_std_core_types__new_None(_ctx), _ctx); /*list<10000>*/;
      if (kk_std_core_types__is_Cons(_match_x189, _ctx)) {
        struct kk_std_core_types_Cons* _con_x248 = kk_std_core_types__as_Cons(_match_x189, _ctx);
        kk_box_t _box_x8 = _con_x248->head;
        kk_std_core_types__list _pat_4 = _con_x248->tail;
        kk_string_t id = kk_string_unbox(_box_x8);
        if kk_likely(kk_datatype_ptr_is_unique(_match_x189, _ctx)) {
          kk_std_core_types__list_drop(_pat_4, _ctx);
          kk_datatype_ptr_free(_match_x189, _ctx);
        }
        else {
          kk_string_dup(id, _ctx);
          kk_datatype_ptr_decref(_match_x189, _ctx);
        }
        kk_string_t s_1_10010;
        kk_string_t _x_x249 = kk_string_trim_left(id,kk_context()); /*string*/
        s_1_10010 = kk_string_trim_right(_x_x249,kk_context()); /*string*/
        kk_std_core_types__maybe _match_x190;
        bool _x_x250;
        kk_std_core_types__optional _match_x191 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x191, _ctx)) {
          kk_box_t _box_x9 = _match_x191._cons._Optional.value;
          bool _uniq_hex_581 = kk_bool_unbox(_box_x9);
          kk_std_core_types__optional_drop(_match_x191, _ctx);
          _x_x250 = _uniq_hex_581; /*bool*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x191, _ctx);
          _x_x250 = false; /*bool*/
        }
        _match_x190 = kk_std_core_int_xparse(s_1_10010, _x_x250, _ctx); /*maybe<int>*/
        if (kk_std_core_types__is_Just(_match_x190, _ctx)) {
          kk_box_t _box_x10 = _match_x190._cons.Just.value;
          kk_integer_t i = kk_integer_unbox(_box_x10, _ctx);
          kk_integer_dup(i, _ctx);
          kk_std_core_types__maybe_drop(_match_x190, _ctx);
          return i;
        }
        {
          return kk_integer_from_small(0);
        }
      }
      {
        return kk_integer_from_small(0);
      }
    }
  }
  {
    kk_std_core_types__list_drop(parts, _ctx);
    return kk_integer_from_small(0);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun252__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun252(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10067_fun252(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun252, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun252(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x253 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__search_flush_stdout(_ctx);
  return kk_unit_box(_x_x253);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun257__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun257(kk_function_t _fself, kk_box_t _b_x16, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10067_fun257(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun257, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun257(kk_function_t _fself, kk_box_t _b_x16, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x258 = kk_Unit;
  int64_t _x_x259 = kk_int64_unbox(_b_x16, KK_OWNED, _ctx); /*int64*/
  kk_whitemagic_dash_koka_src_shm__search_server_loop(_x_x259, _ctx);
  return kk_unit_box(_x_x258);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun261__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun261(kk_function_t _fself, kk_box_t _b_x20, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10067_fun261(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun261, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067_fun261(kk_function_t _fself, kk_box_t _b_x20, kk_box_t _b_x21, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x262;
  int64_t _x_x263 = kk_int64_unbox(_b_x20, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x264 = kk_integer_unbox(_b_x21, _ctx); /*int*/
  _x_x262 = kk_whitemagic_dash_koka_src_shm__search_shm_unmap(_x_x263, _x_x264, _ctx); /*int*/
  return kk_integer_box(_x_x262, _ctx);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067(int64_t addr, kk_string_t op, kk_string_t _c_x10015, kk_context_t* _ctx) { /* (addr : int64, op : string, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10015, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x251 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10067_fun252(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x251);
  bool _match_x188;
  kk_string_t _x_x254;
  kk_define_string_literal(, _s_x255, 4, "quit", _ctx)
  _x_x254 = kk_string_dup(_s_x255, _ctx); /*string*/
  _match_x188 = kk_string_is_neq(op,_x_x254,kk_context()); /*bool*/
  if (_match_x188) {
    kk_ssize_t _b_x13_25 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_box_t _x_x256 = kk_std_core_hnd__open_at1(_b_x13_25, kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10067_fun257(_ctx), kk_int64_box(addr, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x256); return kk_Unit;
  }
  {
    kk_integer_t _pat_9;
    kk_box_t _x_x260 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10067_fun261(_ctx), kk_int64_box(addr, _ctx), kk_integer_box(kk_integer_from_int(30800064, _ctx), _ctx), _ctx); /*10002*/
    _pat_9 = kk_integer_unbox(_x_x260, _ctx); /*int*/
    kk_integer_drop(_pat_9, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun269__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun269(kk_function_t _fself, kk_box_t _b_x30, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun269(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun269, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun269(kk_function_t _fself, kk_box_t _b_x30, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x270;
  kk_string_t _x_x271 = kk_string_unbox(_b_x30); /*string*/
  _x_x270 = kk_whitemagic_dash_koka_src_shm__search_extract_op(_x_x271, _ctx); /*string*/
  return kk_string_box(_x_x270);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun276__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun276(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun276(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun276, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun276(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x277;
  kk_string_t _x_x278 = kk_string_unbox(_b_x35); /*string*/
  _x_x277 = kk_whitemagic_dash_koka_src_shm__search_extract_query_id(_x_x278, _ctx); /*int*/
  return kk_integer_box(_x_x277, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun280__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun280(kk_function_t _fself, kk_box_t _b_x40, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun280(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun280, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun280(kk_function_t _fself, kk_box_t _b_x40, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__search__shm_header _x_x281;
  int64_t _x_x282 = kk_int64_unbox(_b_x40, KK_OWNED, _ctx); /*int64*/
  _x_x281 = kk_whitemagic_dash_koka_src_shm__search_read_header(_x_x282, _ctx); /*whitemagic-koka/src/shm_search/shm-header*/
  return kk_whitemagic_dash_koka_src_shm__search__shm_header_box(_x_x281, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun284__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun284(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun284(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun284, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun284(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x285;
  kk_whitemagic_dash_koka_src_shm__search__shm_header _match_x185 = kk_whitemagic_dash_koka_src_shm__search__shm_header_unbox(_b_x45, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_search/shm-header*/;
  {
    struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x286 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_match_x185, _ctx);
    kk_integer_t _pat_0_0_0 = _con_x286->magic;
    kk_integer_t _pat_1_0_0 = _con_x286->version;
    kk_integer_t _pat_2_0 = _con_x286->capacity;
    kk_integer_t _x = _con_x286->count;
    kk_integer_t _pat_3 = _con_x286->write_pos;
    kk_integer_t _pat_4 = _con_x286->read_pos;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x185, _ctx)) {
      kk_integer_drop(_pat_4, _ctx);
      kk_integer_drop(_pat_3, _ctx);
      kk_integer_drop(_pat_2_0, _ctx);
      kk_integer_drop(_pat_1_0_0, _ctx);
      kk_integer_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(_match_x185, _ctx);
    }
    else {
      kk_integer_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x185, _ctx);
    }
    _x_x285 = _x; /*int*/
  }
  return kk_integer_box(_x_x285, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun291__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun291(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun291(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun291, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun291(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x292;
  kk_whitemagic_dash_koka_src_shm__search__shm_header _match_x184 = kk_whitemagic_dash_koka_src_shm__search__shm_header_unbox(_b_x48, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_search/shm-header*/;
  {
    struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x293 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_match_x184, _ctx);
    kk_integer_t _pat_0_1 = _con_x293->magic;
    kk_integer_t _pat_1_1 = _con_x293->version;
    kk_integer_t _pat_2_2 = _con_x293->capacity;
    kk_integer_t _x_0 = _con_x293->count;
    kk_integer_t _pat_3_1 = _con_x293->write_pos;
    kk_integer_t _pat_4_0 = _con_x293->read_pos;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x184, _ctx)) {
      kk_integer_drop(_pat_4_0, _ctx);
      kk_integer_drop(_pat_3_1, _ctx);
      kk_integer_drop(_pat_2_2, _ctx);
      kk_integer_drop(_pat_1_1, _ctx);
      kk_integer_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(_match_x184, _ctx);
    }
    else {
      kk_integer_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x184, _ctx);
    }
    _x_x292 = _x_0; /*int*/
  }
  return kk_integer_box(_x_x292, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun295__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun295(kk_function_t _fself, kk_box_t _b_x56, kk_box_t _b_x57, kk_box_t _b_x58, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun295(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun295, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun295(kk_function_t _fself, kk_box_t _b_x56, kk_box_t _b_x57, kk_box_t _b_x58, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x296;
  int64_t _x_x297 = kk_int64_unbox(_b_x56, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x298 = kk_integer_unbox(_b_x57, _ctx); /*int*/
  kk_integer_t _x_x299 = kk_integer_unbox(_b_x58, _ctx); /*int*/
  _x_x296 = kk_whitemagic_dash_koka_src_shm__search_shm_search_top5(_x_x297, _x_x298, _x_x299, _ctx); /*string*/
  return kk_string_box(_x_x296);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun306__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun306(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun306(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun306, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun306(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__search__shm_header _x_x307;
  int64_t _x_x308 = kk_int64_unbox(_b_x65, KK_OWNED, _ctx); /*int64*/
  _x_x307 = kk_whitemagic_dash_koka_src_shm__search_read_header(_x_x308, _ctx); /*whitemagic-koka/src/shm_search/shm-header*/
  return kk_whitemagic_dash_koka_src_shm__search__shm_header_box(_x_x307, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun315__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun315(kk_function_t _fself, kk_box_t _b_x70, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun315(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun315, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun315(kk_function_t _fself, kk_box_t _b_x70, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__search__shm_header _this_1_79 = kk_whitemagic_dash_koka_src_shm__search__shm_header_unbox(_b_x70, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_search/shm-header*/;
  kk_integer_t _x_x316;
  {
    struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x317 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this_1_79, _ctx);
    kk_integer_t _pat_0_2 = _con_x317->magic;
    kk_integer_t _pat_1_2 = _con_x317->version;
    kk_integer_t _pat_2_3 = _con_x317->capacity;
    kk_integer_t _x_1 = _con_x317->count;
    kk_integer_t _pat_3_2 = _con_x317->write_pos;
    kk_integer_t _pat_4_2 = _con_x317->read_pos;
    if kk_likely(kk_datatype_ptr_is_unique(_this_1_79, _ctx)) {
      kk_integer_drop(_pat_4_2, _ctx);
      kk_integer_drop(_pat_3_2, _ctx);
      kk_integer_drop(_pat_2_3, _ctx);
      kk_integer_drop(_pat_1_2, _ctx);
      kk_integer_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(_this_1_79, _ctx);
    }
    else {
      kk_integer_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_this_1_79, _ctx);
    }
    _x_x316 = _x_1; /*int*/
  }
  return kk_integer_box(_x_x316, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun323__t {
  struct kk_function_s _base;
  kk_string_t op_0;
  int64_t addr_0;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun323(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun323(kk_string_t op_0, int64_t addr_0, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun323__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun323__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun323, kk_context());
  _self->op_0 = op_0;
  _self->addr_0 = addr_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun323(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun323__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068_fun323__t*, _fself, _ctx);
  kk_string_t op_0 = _self->op_0; /* string */
  int64_t addr_0 = _self->addr_0; /* int64 */
  kk_drop_match(_self, {kk_string_dup(op_0, _ctx);kk_skip_dup(addr_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10015_0_80 = kk_string_unbox(_b_x76); /*string*/;
  kk_unit_t _x_x324 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067(addr_0, op_0, _c_x10015_0_80, _ctx);
  return kk_unit_box(_x_x324);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068(int64_t addr_0, kk_string_t line, kk_context_t* _ctx) { /* (addr : int64, line : string) -> <console/console,exn,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>,exn> () */ 
  bool _match_x181;
  kk_string_t _x_x265 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x266 = kk_string_empty(); /*string*/
  _match_x181 = kk_string_is_eq(_x_x265,_x_x266,kk_context()); /*bool*/
  if (_match_x181) {
    kk_string_drop(line, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_string_t op_0;
    kk_box_t _x_x268;
    kk_box_t _x_x272;
    kk_string_t _x_x273 = kk_string_dup(line, _ctx); /*string*/
    _x_x272 = kk_string_box(_x_x273); /*10000*/
    _x_x268 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun269(_ctx), _x_x272, _ctx); /*10001*/
    op_0 = kk_string_unbox(_x_x268); /*string*/
    kk_string_t x_10069;
    if (kk_string_cmp_cstr_borrow(op_0, "search", _ctx) == 0) {
      kk_integer_t q_id;
      kk_box_t _x_x275 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun276(_ctx), kk_string_box(line), _ctx); /*10001*/
      q_id = kk_integer_unbox(_x_x275, _ctx); /*int*/
      kk_whitemagic_dash_koka_src_shm__search__shm_header h;
      kk_box_t _x_x279 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun280(_ctx), kk_int64_box(addr_0, _ctx), _ctx); /*10001*/
      h = kk_whitemagic_dash_koka_src_shm__search__shm_header_unbox(_x_x279, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_search/shm-header*/
      bool _match_x183;
      kk_integer_t _brw_x186;
      kk_box_t _x_x283;
      kk_box_t _x_x287;
      kk_whitemagic_dash_koka_src_shm__search__shm_header _x_x288 = kk_whitemagic_dash_koka_src_shm__search__shm_header_dup(h, _ctx); /*whitemagic-koka/src/shm_search/shm-header*/
      _x_x287 = kk_whitemagic_dash_koka_src_shm__search__shm_header_box(_x_x288, _ctx); /*10000*/
      _x_x283 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun284(_ctx), _x_x287, _ctx); /*10001*/
      _brw_x186 = kk_integer_unbox(_x_x283, _ctx); /*int*/
      bool _brw_x187 = kk_integer_eq_borrow(_brw_x186,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x186, _ctx);
      _match_x183 = _brw_x187; /*bool*/
      if (_match_x183) {
        kk_integer_drop(q_id, _ctx);
        kk_datatype_ptr_dropn(h, (KK_I32(6)), _ctx);
        kk_define_string_literal(, _s_x289, 17, "{\"error\":\"empty\"}", _ctx)
        x_10069 = kk_string_dup(_s_x289, _ctx); /*string*/
        goto _match_x274;
      }
      {
        kk_integer_t _x_x2_10051;
        kk_box_t _x_x290 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun291(_ctx), kk_whitemagic_dash_koka_src_shm__search__shm_header_box(h, _ctx), _ctx); /*10001*/
        _x_x2_10051 = kk_integer_unbox(_x_x290, _ctx); /*int*/
        kk_string_t best;
        kk_box_t _x_x294 = kk_std_core_hnd__open_none3(kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun295(_ctx), kk_int64_box(addr_0, _ctx), kk_integer_box(_x_x2_10051, _ctx), kk_integer_box(q_id, _ctx), _ctx); /*10003*/
        best = kk_string_unbox(_x_x294); /*string*/
        kk_string_t _x_x300;
        kk_define_string_literal(, _s_x301, 25, "{\"status\":\"ok\",\"results\":", _ctx)
        _x_x300 = kk_string_dup(_s_x301, _ctx); /*string*/
        kk_string_t _x_x302;
        kk_string_t _x_x303;
        kk_define_string_literal(, _s_x304, 1, "}", _ctx)
        _x_x303 = kk_string_dup(_s_x304, _ctx); /*string*/
        _x_x302 = kk_std_core_types__lp__plus__plus__rp_(best, _x_x303, _ctx); /*string*/
        x_10069 = kk_std_core_types__lp__plus__plus__rp_(_x_x300, _x_x302, _ctx); /*string*/
        goto _match_x274;
      }
    }
    if (kk_string_cmp_cstr_borrow(op_0, "status", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_whitemagic_dash_koka_src_shm__search__shm_header h_0;
      kk_box_t _x_x305 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun306(_ctx), kk_int64_box(addr_0, _ctx), _ctx); /*10001*/
      h_0 = kk_whitemagic_dash_koka_src_shm__search__shm_header_unbox(_x_x305, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_search/shm-header*/
      kk_string_t _x_x309;
      kk_define_string_literal(, _s_x310, 29, "{\"shm_consumer\":true,\"count\":", _ctx)
      _x_x309 = kk_string_dup(_s_x310, _ctx); /*string*/
      kk_string_t _x_x311;
      kk_string_t _x_x312;
      kk_integer_t _x_x313;
      kk_box_t _x_x314 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun315(_ctx), kk_whitemagic_dash_koka_src_shm__search__shm_header_box(h_0, _ctx), _ctx); /*10001*/
      _x_x313 = kk_integer_unbox(_x_x314, _ctx); /*int*/
      _x_x312 = kk_std_core_int_show(_x_x313, _ctx); /*string*/
      kk_string_t _x_x318;
      kk_define_string_literal(, _s_x319, 1, "}", _ctx)
      _x_x318 = kk_string_dup(_s_x319, _ctx); /*string*/
      _x_x311 = kk_std_core_types__lp__plus__plus__rp_(_x_x312, _x_x318, _ctx); /*string*/
      x_10069 = kk_std_core_types__lp__plus__plus__rp_(_x_x309, _x_x311, _ctx); /*string*/
      goto _match_x274;
    }
    if (kk_string_cmp_cstr_borrow(op_0, "quit", _ctx) == 0) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x320, 20, "{\"status\":\"stopped\"}", _ctx)
      x_10069 = kk_string_dup(_s_x320, _ctx); /*string*/
      goto _match_x274;
    }
    {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x321, 22, "{\"error\":\"unknown op\"}", _ctx)
      x_10069 = kk_string_dup(_s_x321, _ctx); /*string*/
    }
    _match_x274: ;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_10069, _ctx);
      kk_box_t _x_x322 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_shm__search__new_mlift_server_loop_10068_fun323(op_0, addr_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x322); return kk_Unit;
    }
    {
      kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10067(addr_0, op_0, x_10069, _ctx); return kk_Unit;
    }
  }
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun326__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun326(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x_0, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun326(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_server_loop_fun326, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun327__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun327(kk_function_t _fself, kk_function_t _b_x83, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun327(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_server_loop_fun327, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun328__t {
  struct kk_function_s _base;
  kk_function_t _b_x83;
};
static kk_unit_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun328(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x84, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun328(kk_function_t _b_x83, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun328__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun328__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__search_server_loop_fun328, kk_context());
  _self->_b_x83 = _b_x83;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun328(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x84, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun328__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun328__t*, _fself, _ctx);
  kk_function_t _b_x83 = _self->_b_x83; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x83, _ctx);}, {}, _ctx)
  kk_box_t _x_x329 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x83, (_b_x83, _b_x84, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x329); return kk_Unit;
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun327(kk_function_t _fself, kk_function_t _b_x83, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t ___wildcard_x653__45_106 = kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun328(_b_x83, _ctx); /*(hnd/resume-result<391,()>) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> ()*/;
  kk_function_drop(___wildcard_x653__45_106, _ctx);
  return kk_unit_box(kk_Unit);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun326(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  kk_std_core_exn__exception_drop(x_0, _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun327(_ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun332__t {
  struct kk_function_s _base;
  kk_function_t _b_x85_102;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun332(kk_function_t _fself, int32_t _b_x86, kk_std_core_hnd__ev _b_x87, kk_box_t _b_x88, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun332(kk_function_t _b_x85_102, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun332__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun332__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__search_server_loop_fun332, kk_context());
  _self->_b_x85_102 = _b_x85_102;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun332(kk_function_t _fself, int32_t _b_x86, kk_std_core_hnd__ev _b_x87, kk_box_t _b_x88, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun332__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun332__t*, _fself, _ctx);
  kk_function_t _b_x85_102 = _self->_b_x85_102; /* (m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x@0 : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 391 */
  kk_drop_match(_self, {kk_function_dup(_b_x85_102, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x333 = kk_std_core_exn__exception_unbox(_b_x88, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x85_102, (_b_x85_102, _b_x86, _b_x87, _x_x333, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun334__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun334(kk_function_t _fself, kk_box_t _b_x98, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun334(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_server_loop_fun334, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun334(kk_function_t _fself, kk_box_t _b_x98, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_107 = kk_Unit;
  kk_unit_unbox(_b_x98);
  return kk_unit_box(_res_107);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun335__t {
  struct kk_function_s _base;
  int64_t addr_1;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun335(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun335(int64_t addr_1, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun335__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun335__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__search_server_loop_fun335, kk_context());
  _self->addr_1 = addr_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun337__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun337(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun337(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_server_loop_fun337, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun337(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x338 = kk_std_os_readline_readline(_ctx); /*string*/
  return kk_string_box(_x_x338);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun341__t {
  struct kk_function_s _base;
  int64_t addr_1;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun341(kk_function_t _fself, kk_box_t _b_x94, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun341(int64_t addr_1, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun341__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun341__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__search_server_loop_fun341, kk_context());
  _self->addr_1 = addr_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun341(kk_function_t _fself, kk_box_t _b_x94, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun341__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun341__t*, _fself, _ctx);
  int64_t addr_1 = _self->addr_1; /* int64 */
  kk_drop_match(_self, {kk_skip_dup(addr_1, _ctx);}, {}, _ctx)
  kk_string_t line_0_108 = kk_string_unbox(_b_x94); /*string*/;
  kk_unit_t _x_x342 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068(addr_1, line_0_108, _ctx);
  return kk_unit_box(_x_x342);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_server_loop_fun335(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun335__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__search_server_loop_fun335__t*, _fself, _ctx);
  int64_t addr_1 = _self->addr_1; /* int64 */
  kk_drop_match(_self, {kk_skip_dup(addr_1, _ctx);}, {}, _ctx)
  kk_ssize_t _b_x89_91 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_string_t x_1_10072;
  kk_box_t _x_x336 = kk_std_core_hnd__open_at0(_b_x89_91, kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun337(_ctx), _ctx); /*10000*/
  x_1_10072 = kk_string_unbox(_x_x336); /*string*/
  kk_unit_t _x_x339 = kk_Unit;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_1_10072, _ctx);
    kk_box_t _x_x340 = kk_std_core_hnd_yield_extend(kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun341(addr_1, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x340);
  }
  else {
    kk_whitemagic_dash_koka_src_shm__search__mlift_server_loop_10068(addr_1, x_1_10072, _ctx);
  }
  return kk_unit_box(_x_x339);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__search_server_loop(int64_t addr_1, kk_context_t* _ctx) { /* (addr : int64) -> io () */ 
  kk_box_t _x_x325;
  kk_function_t _b_x85_102 = kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun326(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x@0 : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 391*/;
  kk_std_core_exn__exn _x_x330;
  kk_std_core_hnd__clause1 _x_x331 = kk_std_core_hnd__new_Clause1(kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun332(_b_x85_102, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x330 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x331, _ctx); /*exn<10005,10006>*/
  _x_x325 = kk_std_core_exn_exn_fs__handle(_x_x330, kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun334(_ctx), kk_whitemagic_dash_koka_src_shm__search_new_server_loop_fun335(addr_1, _ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x325); return kk_Unit;
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun344__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun344(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun344(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun344, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun345__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun345(kk_function_t _fself, kk_function_t _b_x111, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun345(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun345, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun346__t {
  struct kk_function_s _base;
  kk_function_t _b_x111;
};
static kk_unit_t kk_whitemagic_dash_koka_src_shm__search_main_fun346(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x112, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun346(kk_function_t _b_x111, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_main_fun346__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__search_main_fun346__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__search_main_fun346, kk_context());
  _self->_b_x111 = _b_x111;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_whitemagic_dash_koka_src_shm__search_main_fun346(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x112, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_main_fun346__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__search_main_fun346__t*, _fself, _ctx);
  kk_function_t _b_x111 = _self->_b_x111; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x111, _ctx);}, {}, _ctx)
  kk_box_t _x_x347 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x111, (_b_x111, _b_x112, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x347); return kk_Unit;
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun345(kk_function_t _fself, kk_function_t _b_x111, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t ___wildcard_x653__45_173 = kk_whitemagic_dash_koka_src_shm__search_new_main_fun346(_b_x111, _ctx); /*(hnd/resume-result<981,()>) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> ()*/;
  kk_function_drop(___wildcard_x653__45_173, _ctx);
  return kk_unit_box(kk_Unit);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun344(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  kk_std_core_exn__exception_drop(x, _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_whitemagic_dash_koka_src_shm__search_new_main_fun345(_ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun350__t {
  struct kk_function_s _base;
  kk_function_t _b_x113_161;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun350(kk_function_t _fself, int32_t _b_x114, kk_std_core_hnd__ev _b_x115, kk_box_t _b_x116, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun350(kk_function_t _b_x113_161, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_main_fun350__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__search_main_fun350__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__search_main_fun350, kk_context());
  _self->_b_x113_161 = _b_x113_161;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun350(kk_function_t _fself, int32_t _b_x114, kk_std_core_hnd__ev _b_x115, kk_box_t _b_x116, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_main_fun350__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__search_main_fun350__t*, _fself, _ctx);
  kk_function_t _b_x113_161 = _self->_b_x113_161; /* (m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 981 */
  kk_drop_match(_self, {kk_function_dup(_b_x113_161, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x351 = kk_std_core_exn__exception_unbox(_b_x116, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x113_161, (_b_x113_161, _b_x114, _b_x115, _x_x351, _ctx), _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun352__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun352(kk_function_t _fself, kk_box_t _b_x157, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun352(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun352, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun352(kk_function_t _fself, kk_box_t _b_x157, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_174 = kk_Unit;
  kk_unit_unbox(_b_x157);
  return kk_unit_box(_res_174);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun353__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun353(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun353(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun353, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun357__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun357(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun357(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun357, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun357(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x358 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__search_flush_stdout(_ctx);
  return kk_unit_box(_x_x358);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun360__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun360(kk_function_t _fself, kk_box_t _b_x122, kk_box_t _b_x123, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun360(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun360, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun360(kk_function_t _fself, kk_box_t _b_x122, kk_box_t _b_x123, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  int64_t _x_x361;
  kk_string_t _x_x362 = kk_string_unbox(_b_x122); /*string*/
  kk_integer_t _x_x363 = kk_integer_unbox(_b_x123, _ctx); /*int*/
  _x_x361 = kk_whitemagic_dash_koka_src_shm__search_shm_open_map(_x_x362, _x_x363, _ctx); /*int64*/
  return kk_int64_box(_x_x361, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun369__t {
  struct kk_function_s _base;
};
static int64_t kk_whitemagic_dash_koka_src_shm__search_main_fun369(kk_function_t _fself, kk_integer_t _x1_x368, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun369(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun369, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static int64_t kk_whitemagic_dash_koka_src_shm__search_main_fun369(kk_function_t _fself, kk_integer_t _x1_x368, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_num_int64_int64(_x1_x368, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun372__t {
  struct kk_function_s _base;
  kk_function_t _b_x127_164;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun372(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun372(kk_function_t _b_x127_164, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_main_fun372__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__search_main_fun372__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__search_main_fun372, kk_context());
  _self->_b_x127_164 = _b_x127_164;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun372(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_main_fun372__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__search_main_fun372__t*, _fself, _ctx);
  kk_function_t _b_x127_164 = _self->_b_x127_164; /* (i : int) -> int64 */
  kk_drop_match(_self, {kk_function_dup(_b_x127_164, _ctx);}, {}, _ctx)
  int64_t _x_x373;
  kk_integer_t _x_x374 = kk_integer_unbox(_b_x129, _ctx); /*int*/
  _x_x373 = kk_function_call(int64_t, (kk_function_t, kk_integer_t, kk_context_t*), _b_x127_164, (_b_x127_164, _x_x374, _ctx), _ctx); /*int64*/
  return kk_int64_box(_x_x373, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun378__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun378(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun378(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun378, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun378(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x379 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__search_flush_stdout(_ctx);
  return kk_unit_box(_x_x379);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun381__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun381(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun381(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun381, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun381(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_whitemagic_dash_koka_src_shm__search__shm_header _x_x382;
  int64_t _x_x383 = kk_int64_unbox(_b_x133, KK_OWNED, _ctx); /*int64*/
  _x_x382 = kk_whitemagic_dash_koka_src_shm__search_read_header(_x_x383, _ctx); /*whitemagic-koka/src/shm_search/shm-header*/
  return kk_whitemagic_dash_koka_src_shm__search__shm_header_box(_x_x382, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun384__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_whitemagic_dash_koka_src_shm__search_main_fun384(kk_function_t _fself, kk_whitemagic_dash_koka_src_shm__search__shm_header _this, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun384(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun384, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_whitemagic_dash_koka_src_shm__search_main_fun384(kk_function_t _fself, kk_whitemagic_dash_koka_src_shm__search__shm_header _this, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  {
    struct kk_whitemagic_dash_koka_src_shm__search_Shm_header* _con_x385 = kk_whitemagic_dash_koka_src_shm__search__as_Shm_header(_this, _ctx);
    kk_integer_t _x = _con_x385->magic;
    kk_integer_t _pat_0_0 = _con_x385->version;
    kk_integer_t _pat_1_0 = _con_x385->capacity;
    kk_integer_t _pat_2 = _con_x385->count;
    kk_integer_t _pat_3 = _con_x385->write_pos;
    kk_integer_t _pat_4 = _con_x385->read_pos;
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
struct kk_whitemagic_dash_koka_src_shm__search_main_fun387__t {
  struct kk_function_s _base;
  kk_function_t _b_x136_167;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun387(kk_function_t _fself, kk_box_t _b_x138, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun387(kk_function_t _b_x136_167, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_main_fun387__t* _self = kk_function_alloc_as(struct kk_whitemagic_dash_koka_src_shm__search_main_fun387__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_whitemagic_dash_koka_src_shm__search_main_fun387, kk_context());
  _self->_b_x136_167 = _b_x136_167;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun387(kk_function_t _fself, kk_box_t _b_x138, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_shm__search_main_fun387__t* _self = kk_function_as(struct kk_whitemagic_dash_koka_src_shm__search_main_fun387__t*, _fself, _ctx);
  kk_function_t _b_x136_167 = _self->_b_x136_167; /* (whitemagic-koka/src/shm_search/shm-header) -> int */
  kk_drop_match(_self, {kk_function_dup(_b_x136_167, _ctx);}, {}, _ctx)
  kk_integer_t _x_x388;
  kk_whitemagic_dash_koka_src_shm__search__shm_header _x_x389 = kk_whitemagic_dash_koka_src_shm__search__shm_header_unbox(_b_x138, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_search/shm-header*/
  _x_x388 = kk_function_call(kk_integer_t, (kk_function_t, kk_whitemagic_dash_koka_src_shm__search__shm_header, kk_context_t*), _b_x136_167, (_b_x136_167, _x_x389, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x388, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun393__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun393(kk_function_t _fself, kk_box_t _b_x142, kk_box_t _b_x143, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun393(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun393, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun393(kk_function_t _fself, kk_box_t _b_x142, kk_box_t _b_x143, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x394;
  int64_t _x_x395 = kk_int64_unbox(_b_x142, KK_OWNED, _ctx); /*int64*/
  kk_integer_t _x_x396 = kk_integer_unbox(_b_x143, _ctx); /*int*/
  _x_x394 = kk_whitemagic_dash_koka_src_shm__search_shm_unmap(_x_x395, _x_x396, _ctx); /*int*/
  return kk_integer_box(_x_x394, _ctx);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun398__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun398(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun398(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun398, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun398(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x399 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__search_flush_stdout(_ctx);
  return kk_unit_box(_x_x399);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun403__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun403(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun403(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun403, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun403(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x404 = kk_Unit;
  kk_whitemagic_dash_koka_src_shm__search_flush_stdout(_ctx);
  return kk_unit_box(_x_x404);
}


// lift anonymous function
struct kk_whitemagic_dash_koka_src_shm__search_main_fun406__t {
  struct kk_function_s _base;
};
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun406(kk_function_t _fself, kk_box_t _b_x153, kk_context_t* _ctx);
static kk_function_t kk_whitemagic_dash_koka_src_shm__search_new_main_fun406(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_whitemagic_dash_koka_src_shm__search_main_fun406, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun406(kk_function_t _fself, kk_box_t _b_x153, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x407 = kk_Unit;
  int64_t _x_x408 = kk_int64_unbox(_b_x153, KK_OWNED, _ctx); /*int64*/
  kk_whitemagic_dash_koka_src_shm__search_server_loop(_x_x408, _ctx);
  return kk_unit_box(_x_x407);
}
static kk_box_t kk_whitemagic_dash_koka_src_shm__search_main_fun353(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x354;
  kk_define_string_literal(, _s_x355, 39, "{\"status\":\"starting\",\"shm_search\":true}", _ctx)
  _x_x354 = kk_string_dup(_s_x355, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x354, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x356 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__search_new_main_fun357(_ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x356);
  int64_t addr;
  kk_box_t _x_x359;
  kk_box_t _x_x364;
  kk_string_t _x_x365;
  kk_define_string_literal(, _s_x366, 29, "/whitemagic_embed_bridge_real", _ctx)
  _x_x365 = kk_string_dup(_s_x366, _ctx); /*string*/
  _x_x364 = kk_string_box(_x_x365); /*10000*/
  _x_x359 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__search_new_main_fun360(_ctx), _x_x364, kk_integer_box(kk_integer_from_int(30800064, _ctx), _ctx), _ctx); /*10002*/
  addr = kk_int64_unbox(_x_x359, KK_OWNED, _ctx); /*int64*/
  kk_unit_t _x_x367 = kk_Unit;
  kk_function_t _b_x127_164 = kk_whitemagic_dash_koka_src_shm__search_new_main_fun369(_ctx); /*(i : int) -> int64*/;
  kk_integer_t _b_x128_165 = kk_integer_from_small(0); /*int*/;
  bool _match_x175;
  int64_t _x_x370;
  kk_box_t _x_x371 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__search_new_main_fun372(_b_x127_164, _ctx), kk_integer_box(_b_x128_165, _ctx), _ctx); /*10001*/
  _x_x370 = kk_int64_unbox(_x_x371, KK_OWNED, _ctx); /*int64*/
  _match_x175 = (addr == _x_x370); /*bool*/
  if (_match_x175) {
    kk_unit_t ___1 = kk_Unit;
    kk_string_t _x_x375;
    kk_define_string_literal(, _s_x376, 40, "{\"error\":\"failed to open shared memory\"}", _ctx)
    _x_x375 = kk_string_dup(_s_x376, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x375, _ctx);
    kk_box_t _x_x377 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__search_new_main_fun378(_ctx), _ctx); /*10000*/
    kk_unit_unbox(_x_x377);
  }
  else {
    kk_whitemagic_dash_koka_src_shm__search__shm_header header;
    kk_box_t _x_x380 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__search_new_main_fun381(_ctx), kk_int64_box(addr, _ctx), _ctx); /*10001*/
    header = kk_whitemagic_dash_koka_src_shm__search__shm_header_unbox(_x_x380, KK_OWNED, _ctx); /*whitemagic-koka/src/shm_search/shm-header*/
    kk_function_t _b_x136_167 = kk_whitemagic_dash_koka_src_shm__search_new_main_fun384(_ctx); /*(whitemagic-koka/src/shm_search/shm-header) -> int*/;
    kk_whitemagic_dash_koka_src_shm__search__shm_header _b_x137_168 = header; /*whitemagic-koka/src/shm_search/shm-header*/;
    bool _match_x176;
    kk_integer_t _brw_x178;
    kk_box_t _x_x386 = kk_std_core_hnd__open_none1(kk_whitemagic_dash_koka_src_shm__search_new_main_fun387(_b_x136_167, _ctx), kk_whitemagic_dash_koka_src_shm__search__shm_header_box(_b_x137_168, _ctx), _ctx); /*10001*/
    _brw_x178 = kk_integer_unbox(_x_x386, _ctx); /*int*/
    kk_integer_t _brw_x177 = kk_integer_from_int(1464683339, _ctx); /*int*/;
    bool _brw_x179 = kk_integer_neq_borrow(_brw_x178,_brw_x177,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x178, _ctx);
    kk_integer_drop(_brw_x177, _ctx);
    _match_x176 = _brw_x179; /*bool*/
    if (_match_x176) {
      kk_unit_t ___2 = kk_Unit;
      kk_string_t _x_x390;
      kk_define_string_literal(, _s_x391, 25, "{\"error\":\"invalid magic\"}", _ctx)
      _x_x390 = kk_string_dup(_s_x391, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x390, _ctx);
      kk_integer_t _pat_2_0;
      kk_box_t _x_x392 = kk_std_core_hnd__open_none2(kk_whitemagic_dash_koka_src_shm__search_new_main_fun393(_ctx), kk_int64_box(addr, _ctx), kk_integer_box(kk_integer_from_int(30800064, _ctx), _ctx), _ctx); /*10002*/
      _pat_2_0 = kk_integer_unbox(_x_x392, _ctx); /*int*/
      kk_integer_drop(_pat_2_0, _ctx);
      kk_box_t _x_x397 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__search_new_main_fun398(_ctx), _ctx); /*10000*/
      kk_unit_unbox(_x_x397);
    }
    else {
      kk_unit_t ___3 = kk_Unit;
      kk_string_t _x_x400;
      kk_define_string_literal(, _s_x401, 37, "{\"status\":\"started\",\"connected\":true}", _ctx)
      _x_x400 = kk_string_dup(_s_x401, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x400, _ctx);
      kk_unit_t ___4 = kk_Unit;
      kk_box_t _x_x402 = kk_std_core_hnd__open_none0(kk_whitemagic_dash_koka_src_shm__search_new_main_fun403(_ctx), _ctx); /*10000*/
      kk_unit_unbox(_x_x402);
      kk_ssize_t _b_x150_170 = (KK_IZ(0)); /*hnd/ev-index*/;
      kk_box_t _x_x405 = kk_std_core_hnd__open_at1(_b_x150_170, kk_whitemagic_dash_koka_src_shm__search_new_main_fun406(_ctx), kk_int64_box(addr, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x405);
    }
  }
  return kk_unit_box(_x_x367);
}

kk_unit_t kk_whitemagic_dash_koka_src_shm__search_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_box_t _x_x343;
  kk_function_t _b_x113_161 = kk_whitemagic_dash_koka_src_shm__search_new_main_fun344(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn>,()>, hnd/ev<exn>, x : exception) -> <alloc<global>,console/console,div,fsys,ndet,net,read<global>,ui,write<global>,exn> 981*/;
  kk_std_core_exn__exn _x_x348;
  kk_std_core_hnd__clause1 _x_x349 = kk_std_core_hnd__new_Clause1(kk_whitemagic_dash_koka_src_shm__search_new_main_fun350(_b_x113_161, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x348 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x349, _ctx); /*exn<10005,10006>*/
  _x_x343 = kk_std_core_exn_exn_fs__handle(_x_x348, kk_whitemagic_dash_koka_src_shm__search_new_main_fun352(_ctx), kk_whitemagic_dash_koka_src_shm__search_new_main_fun353(_ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x343); return kk_Unit;
}

// initialization
void kk_whitemagic_dash_koka_src_shm__search__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_bool__init(_ctx);
  kk_std_core_order__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_vector__init(_ctx);
  kk_std_core_sslice__init(_ctx);
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
  kk_std_core_list__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_int__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  kk_init_string_literal(kk_whitemagic_dash_koka_src_shm__search_shm_name, _ctx)
  {
    kk_whitemagic_dash_koka_src_shm__search_segment_size = kk_integer_from_int(30800064, _ctx); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__search_header_size = kk_integer_from_small(64); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__search_slot_size = kk_integer_from_small(1540); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__search_embedding_dim = kk_integer_from_small(384); /*int*/
  }
  {
    kk_whitemagic_dash_koka_src_shm__search_magic_number = kk_integer_from_int(1464683339, _ctx); /*int*/
  }
}

// termination
void kk_whitemagic_dash_koka_src_shm__search__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__search_magic_number, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__search_embedding_dim, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__search_slot_size, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__search_header_size, _ctx);
  kk_integer_drop(kk_whitemagic_dash_koka_src_shm__search_segment_size, _ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_list__done(_ctx);
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
  kk_std_core_sslice__done(_ctx);
  kk_std_core_vector__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_order__done(_ctx);
  kk_std_core_bool__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
