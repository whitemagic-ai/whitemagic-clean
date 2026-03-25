// Koka generated module: src/ring_buffer, koka version: 3.2.2, platform: 64-bit
#include "src_ring__buffer.h"

kk_src_ring__buffer__buffer_config kk_src_ring__buffer_buffer_config_fs__copy(kk_src_ring__buffer__buffer_config _this, kk_std_core_types__optional capacity, kk_std_core_types__optional slot_size, kk_std_core_types__optional header_size, kk_context_t* _ctx) { /* (buffer-config, capacity : ? int, slot-size : ? int, header-size : ? int) -> buffer-config */ 
  kk_integer_t _x_x383;
  if (kk_std_core_types__is_Optional(capacity, _ctx)) {
    kk_box_t _box_x0 = capacity._cons._Optional.value;
    kk_integer_t _uniq_capacity_65 = kk_integer_unbox(_box_x0, _ctx);
    kk_integer_dup(_uniq_capacity_65, _ctx);
    kk_std_core_types__optional_drop(capacity, _ctx);
    _x_x383 = _uniq_capacity_65; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(capacity, _ctx);
    {
      struct kk_src_ring__buffer_Buffer_config* _con_x384 = kk_src_ring__buffer__as_Buffer_config(_this, _ctx);
      kk_integer_t _x = _con_x384->capacity;
      kk_integer_dup(_x, _ctx);
      _x_x383 = _x; /*int*/
    }
  }
  kk_integer_t _x_x385;
  if (kk_std_core_types__is_Optional(slot_size, _ctx)) {
    kk_box_t _box_x1 = slot_size._cons._Optional.value;
    kk_integer_t _uniq_slot_size_73 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_slot_size_73, _ctx);
    kk_std_core_types__optional_drop(slot_size, _ctx);
    _x_x385 = _uniq_slot_size_73; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(slot_size, _ctx);
    {
      struct kk_src_ring__buffer_Buffer_config* _con_x386 = kk_src_ring__buffer__as_Buffer_config(_this, _ctx);
      kk_integer_t _x_0 = _con_x386->slot_size;
      kk_integer_dup(_x_0, _ctx);
      _x_x385 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x387;
  if (kk_std_core_types__is_Optional(header_size, _ctx)) {
    kk_box_t _box_x2 = header_size._cons._Optional.value;
    kk_integer_t _uniq_header_size_81 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_header_size_81, _ctx);
    kk_std_core_types__optional_drop(header_size, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x387 = _uniq_header_size_81; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(header_size, _ctx);
    {
      struct kk_src_ring__buffer_Buffer_config* _con_x388 = kk_src_ring__buffer__as_Buffer_config(_this, _ctx);
      kk_integer_t _pat_0_2 = _con_x388->capacity;
      kk_integer_t _pat_1_3 = _con_x388->slot_size;
      kk_integer_t _x_1 = _con_x388->header_size;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_1_3, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_integer_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x387 = _x_1; /*int*/
    }
  }
  return kk_src_ring__buffer__new_Buffer_config(kk_reuse_null, 0, _x_x383, _x_x385, _x_x387, _ctx);
}

kk_src_ring__buffer__buffer_state kk_src_ring__buffer_buffer_state_fs__copy(kk_src_ring__buffer__buffer_state _this, kk_std_core_types__optional write_pos, kk_std_core_types__optional read_pos, kk_std_core_types__optional count, kk_std_core_types__optional total_written, kk_std_core_types__optional total_read, kk_context_t* _ctx) { /* (buffer-state, write-pos : ? int, read-pos : ? int, count : ? int, total-written : ? int64, total-read : ? int64) -> buffer-state */ 
  kk_integer_t _x_x394;
  if (kk_std_core_types__is_Optional(write_pos, _ctx)) {
    kk_box_t _box_x3 = write_pos._cons._Optional.value;
    kk_integer_t _uniq_write_pos_139 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_write_pos_139, _ctx);
    kk_std_core_types__optional_drop(write_pos, _ctx);
    _x_x394 = _uniq_write_pos_139; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(write_pos, _ctx);
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x395 = kk_src_ring__buffer__as_Buffer_state(_this, _ctx);
      kk_integer_t _x = _con_x395->write_pos;
      kk_integer_dup(_x, _ctx);
      _x_x394 = _x; /*int*/
    }
  }
  kk_integer_t _x_x396;
  if (kk_std_core_types__is_Optional(read_pos, _ctx)) {
    kk_box_t _box_x4 = read_pos._cons._Optional.value;
    kk_integer_t _uniq_read_pos_147 = kk_integer_unbox(_box_x4, _ctx);
    kk_integer_dup(_uniq_read_pos_147, _ctx);
    kk_std_core_types__optional_drop(read_pos, _ctx);
    _x_x396 = _uniq_read_pos_147; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(read_pos, _ctx);
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x397 = kk_src_ring__buffer__as_Buffer_state(_this, _ctx);
      kk_integer_t _x_0 = _con_x397->read_pos;
      kk_integer_dup(_x_0, _ctx);
      _x_x396 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x398;
  if (kk_std_core_types__is_Optional(count, _ctx)) {
    kk_box_t _box_x5 = count._cons._Optional.value;
    kk_integer_t _uniq_count_155 = kk_integer_unbox(_box_x5, _ctx);
    kk_integer_dup(_uniq_count_155, _ctx);
    kk_std_core_types__optional_drop(count, _ctx);
    _x_x398 = _uniq_count_155; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(count, _ctx);
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x399 = kk_src_ring__buffer__as_Buffer_state(_this, _ctx);
      kk_integer_t _x_1 = _con_x399->count;
      kk_integer_dup(_x_1, _ctx);
      _x_x398 = _x_1; /*int*/
    }
  }
  int64_t _x_x400;
  if (kk_std_core_types__is_Optional(total_written, _ctx)) {
    kk_box_t _box_x6 = total_written._cons._Optional.value;
    int64_t _uniq_total_written_163 = kk_int64_unbox(_box_x6, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(total_written, _ctx);
    _x_x400 = _uniq_total_written_163; /*int64*/
  }
  else {
    kk_std_core_types__optional_drop(total_written, _ctx);
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x401 = kk_src_ring__buffer__as_Buffer_state(_this, _ctx);
      int64_t _x_2 = _con_x401->total_written;
      _x_x400 = _x_2; /*int64*/
    }
  }
  int64_t _x_x402;
  if (kk_std_core_types__is_Optional(total_read, _ctx)) {
    kk_box_t _box_x7 = total_read._cons._Optional.value;
    int64_t _uniq_total_read_171 = kk_int64_unbox(_box_x7, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(total_read, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x402 = _uniq_total_read_171; /*int64*/
  }
  else {
    kk_std_core_types__optional_drop(total_read, _ctx);
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x403 = kk_src_ring__buffer__as_Buffer_state(_this, _ctx);
      kk_integer_t _pat_0_4 = _con_x403->write_pos;
      kk_integer_t _pat_1_5 = _con_x403->read_pos;
      kk_integer_t _pat_2_4 = _con_x403->count;
      int64_t _x_3 = _con_x403->total_read;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_integer_drop(_pat_2_4, _ctx);
        kk_integer_drop(_pat_1_5, _ctx);
        kk_integer_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x402 = _x_3; /*int64*/
    }
  }
  return kk_src_ring__buffer__new_Buffer_state(kk_reuse_null, 0, _x_x394, _x_x396, _x_x398, _x_x400, _x_x402, _ctx);
}
 
// Check if buffer is full

bool kk_src_ring__buffer_is_full(kk_src_ring__buffer__buffer_state state, kk_integer_t capacity, kk_context_t* _ctx) { /* (state : buffer-state, capacity : int) -> bool */ 
  kk_integer_t _brw_x335;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x405 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _pat_0 = _con_x405->write_pos;
    kk_integer_t _pat_1 = _con_x405->read_pos;
    kk_integer_t _x = _con_x405->count;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_1, _ctx);
      kk_integer_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_integer_dup(_x, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    _brw_x335 = _x; /*int*/
  }
  bool _brw_x336 = kk_integer_gte_borrow(_brw_x335,capacity,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x335, _ctx);
  kk_integer_drop(capacity, _ctx);
  return _brw_x336;
}
 
// Check if buffer is empty

bool kk_src_ring__buffer_is_empty(kk_src_ring__buffer__buffer_state state, kk_context_t* _ctx) { /* (state : buffer-state) -> bool */ 
  kk_integer_t _brw_x333;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x406 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _pat_0 = _con_x406->write_pos;
    kk_integer_t _pat_1 = _con_x406->read_pos;
    kk_integer_t _x = _con_x406->count;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_1, _ctx);
      kk_integer_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_integer_dup(_x, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    _brw_x333 = _x; /*int*/
  }
  bool _brw_x334 = kk_integer_eq_borrow(_brw_x333,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x333, _ctx);
  return _brw_x334;
}
 
// Write to buffer - returns new state or error

kk_std_core_types__maybe kk_src_ring__buffer_try_write(kk_src_ring__buffer__buffer_state state, kk_src_ring__buffer__buffer_config config, kk_context_t* _ctx) { /* (state : buffer-state, config : buffer-config) -> maybe<buffer-state> */ 
  bool _match_x329;
  kk_integer_t _brw_x331;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x407 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x = _con_x407->count;
    kk_integer_dup(_x, _ctx);
    _brw_x331 = _x; /*int*/
  }
  kk_integer_t _brw_x330;
  {
    struct kk_src_ring__buffer_Buffer_config* _con_x408 = kk_src_ring__buffer__as_Buffer_config(config, _ctx);
    kk_integer_t _x_0 = _con_x408->capacity;
    kk_integer_dup(_x_0, _ctx);
    _brw_x330 = _x_0; /*int*/
  }
  bool _brw_x332 = kk_integer_gte_borrow(_brw_x331,_brw_x330,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x331, _ctx);
  kk_integer_drop(_brw_x330, _ctx);
  _match_x329 = _brw_x332; /*bool*/
  if (_match_x329) {
    kk_datatype_ptr_dropn(state, (KK_I32(3)), _ctx);
    kk_datatype_ptr_dropn(config, (KK_I32(3)), _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_src_ring__buffer__buffer_state new_state;
    kk_integer_t _x_x409;
    kk_integer_t _x_x410;
    kk_integer_t _x_x411;
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x412 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
      kk_integer_t _x_1 = _con_x412->write_pos;
      kk_integer_dup(_x_1, _ctx);
      _x_x411 = _x_1; /*int*/
    }
    _x_x410 = kk_integer_add_small_const(_x_x411, 1, _ctx); /*int*/
    kk_integer_t _x_x413;
    {
      struct kk_src_ring__buffer_Buffer_config* _con_x414 = kk_src_ring__buffer__as_Buffer_config(config, _ctx);
      kk_integer_t _x_2 = _con_x414->capacity;
      kk_integer_t _pat_0_3 = _con_x414->slot_size;
      kk_integer_t _pat_1_2 = _con_x414->header_size;
      if kk_likely(kk_datatype_ptr_is_unique(config, _ctx)) {
        kk_integer_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(config, _ctx);
      }
      else {
        kk_integer_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(config, _ctx);
      }
      _x_x413 = _x_2; /*int*/
    }
    _x_x409 = kk_integer_mod(_x_x410,_x_x413,kk_context()); /*int*/
    kk_integer_t _x_x415;
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x416 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
      kk_integer_t _x_3 = _con_x416->read_pos;
      kk_integer_dup(_x_3, _ctx);
      _x_x415 = _x_3; /*int*/
    }
    kk_integer_t _x_x417;
    kk_integer_t _x_x418;
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x419 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
      kk_integer_t _x_4 = _con_x419->count;
      kk_integer_dup(_x_4, _ctx);
      _x_x418 = _x_4; /*int*/
    }
    _x_x417 = kk_integer_add_small_const(_x_x418, 1, _ctx); /*int*/
    int64_t _x_x420;
    int64_t _x_x421 = (KK_I64(1)); /*int64*/
    int64_t _x_x422;
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x423 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
      int64_t _x_5 = _con_x423->total_written;
      _x_x422 = _x_5; /*int64*/
    }
    _x_x420 = (int64_t)((uint64_t)_x_x421 + (uint64_t)_x_x422); /*int64*/
    int64_t _x_x424;
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x425 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
      kk_integer_t _pat_0_7 = _con_x425->write_pos;
      kk_integer_t _pat_1_6 = _con_x425->read_pos;
      kk_integer_t _pat_2_4 = _con_x425->count;
      int64_t _x_6 = _con_x425->total_read;
      if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
        kk_integer_drop(_pat_2_4, _ctx);
        kk_integer_drop(_pat_1_6, _ctx);
        kk_integer_drop(_pat_0_7, _ctx);
        kk_datatype_ptr_free(state, _ctx);
      }
      else {
        kk_datatype_ptr_decref(state, _ctx);
      }
      _x_x424 = _x_6; /*int64*/
    }
    new_state = kk_src_ring__buffer__new_Buffer_state(kk_reuse_null, 0, _x_x409, _x_x415, _x_x417, _x_x420, _x_x424, _ctx); /*src/ring_buffer/buffer-state*/
    return kk_std_core_types__new_Just(kk_src_ring__buffer__buffer_state_box(new_state, _ctx), _ctx);
  }
}
 
// Read from buffer - returns new state or error

kk_std_core_types__maybe kk_src_ring__buffer_try_read(kk_src_ring__buffer__buffer_state state, kk_src_ring__buffer__buffer_config config, kk_context_t* _ctx) { /* (state : buffer-state, config : buffer-config) -> maybe<buffer-state> */ 
  bool _match_x326;
  kk_integer_t _brw_x327;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x426 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x = _con_x426->count;
    kk_integer_dup(_x, _ctx);
    _brw_x327 = _x; /*int*/
  }
  bool _brw_x328 = kk_integer_eq_borrow(_brw_x327,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x327, _ctx);
  _match_x326 = _brw_x328; /*bool*/
  if (_match_x326) {
    kk_datatype_ptr_dropn(state, (KK_I32(3)), _ctx);
    kk_datatype_ptr_dropn(config, (KK_I32(3)), _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_src_ring__buffer__buffer_state new_state;
    kk_integer_t _x_x427;
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x428 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
      kk_integer_t _x_0 = _con_x428->write_pos;
      kk_integer_dup(_x_0, _ctx);
      _x_x427 = _x_0; /*int*/
    }
    kk_integer_t _x_x429;
    kk_integer_t _x_x430;
    kk_integer_t _x_x431;
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x432 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
      kk_integer_t _x_1 = _con_x432->read_pos;
      kk_integer_dup(_x_1, _ctx);
      _x_x431 = _x_1; /*int*/
    }
    _x_x430 = kk_integer_add_small_const(_x_x431, 1, _ctx); /*int*/
    kk_integer_t _x_x433;
    {
      struct kk_src_ring__buffer_Buffer_config* _con_x434 = kk_src_ring__buffer__as_Buffer_config(config, _ctx);
      kk_integer_t _x_2 = _con_x434->capacity;
      kk_integer_t _pat_0_3 = _con_x434->slot_size;
      kk_integer_t _pat_1_2 = _con_x434->header_size;
      if kk_likely(kk_datatype_ptr_is_unique(config, _ctx)) {
        kk_integer_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(config, _ctx);
      }
      else {
        kk_integer_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(config, _ctx);
      }
      _x_x433 = _x_2; /*int*/
    }
    _x_x429 = kk_integer_mod(_x_x430,_x_x433,kk_context()); /*int*/
    kk_integer_t _x_x435;
    kk_integer_t _x_x436;
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x437 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
      kk_integer_t _x_3 = _con_x437->count;
      kk_integer_dup(_x_3, _ctx);
      _x_x436 = _x_3; /*int*/
    }
    _x_x435 = kk_integer_add_small_const(_x_x436, -1, _ctx); /*int*/
    int64_t _x_x438;
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x439 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
      int64_t _x_4 = _con_x439->total_written;
      _x_x438 = _x_4; /*int64*/
    }
    int64_t _x_x440;
    int64_t _x_x441 = (KK_I64(1)); /*int64*/
    int64_t _x_x442;
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x443 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
      kk_integer_t _pat_0_6 = _con_x443->write_pos;
      kk_integer_t _pat_1_5 = _con_x443->read_pos;
      kk_integer_t _pat_2_4 = _con_x443->count;
      int64_t _x_5 = _con_x443->total_read;
      if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
        kk_integer_drop(_pat_2_4, _ctx);
        kk_integer_drop(_pat_1_5, _ctx);
        kk_integer_drop(_pat_0_6, _ctx);
        kk_datatype_ptr_free(state, _ctx);
      }
      else {
        kk_datatype_ptr_decref(state, _ctx);
      }
      _x_x442 = _x_5; /*int64*/
    }
    _x_x440 = (int64_t)((uint64_t)_x_x441 + (uint64_t)_x_x442); /*int64*/
    new_state = kk_src_ring__buffer__new_Buffer_state(kk_reuse_null, 0, _x_x427, _x_x429, _x_x435, _x_x438, _x_x440, _ctx); /*src/ring_buffer/buffer-state*/
    return kk_std_core_types__new_Just(kk_src_ring__buffer__buffer_state_box(new_state, _ctx), _ctx);
  }
}
 
// Get available slots for writing

kk_integer_t kk_src_ring__buffer_write_available(kk_src_ring__buffer__buffer_state state, kk_integer_t capacity, kk_context_t* _ctx) { /* (state : buffer-state, capacity : int) -> int */ 
  kk_integer_t _x_x444;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x445 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _pat_0 = _con_x445->write_pos;
    kk_integer_t _pat_1 = _con_x445->read_pos;
    kk_integer_t _x = _con_x445->count;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_1, _ctx);
      kk_integer_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_integer_dup(_x, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x444 = _x; /*int*/
  }
  return kk_integer_sub(capacity,_x_x444,kk_context());
}
 
// Get available slots for reading

kk_integer_t kk_src_ring__buffer_read_available(kk_src_ring__buffer__buffer_state state, kk_context_t* _ctx) { /* (state : buffer-state) -> int */ 
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x446 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _pat_0 = _con_x446->write_pos;
    kk_integer_t _pat_1 = _con_x446->read_pos;
    kk_integer_t _x = _con_x446->count;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_1, _ctx);
      kk_integer_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_integer_dup(_x, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    return _x;
  }
}
 
// Write n items, returns actual count written

kk_std_core_types__tuple2 kk_src_ring__buffer_write_batch(kk_src_ring__buffer__buffer_state state, kk_src_ring__buffer__buffer_config config, kk_integer_t n, kk_context_t* _ctx) { /* (state : buffer-state, config : buffer-config, n : int) -> (int, buffer-state) */ 
  kk_integer_t available;
  kk_integer_t _x_x447;
  {
    struct kk_src_ring__buffer_Buffer_config* _con_x448 = kk_src_ring__buffer__as_Buffer_config(config, _ctx);
    kk_integer_t _x_0 = _con_x448->capacity;
    kk_integer_dup(_x_0, _ctx);
    _x_x447 = _x_0; /*int*/
  }
  kk_integer_t _x_x449;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x450 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x = _con_x450->count;
    kk_integer_dup(_x, _ctx);
    _x_x449 = _x; /*int*/
  }
  available = kk_integer_sub(_x_x447,_x_x449,kk_context()); /*int*/
  kk_integer_t to_write;
  bool _match_x325 = kk_integer_gt_borrow(n,available,kk_context()); /*bool*/;
  if (_match_x325) {
    kk_integer_drop(n, _ctx);
    to_write = available; /*int*/
  }
  else {
    kk_integer_drop(available, _ctx);
    to_write = n; /*int*/
  }
  kk_integer_t new_count;
  kk_integer_t _x_x451;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x452 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x_1 = _con_x452->count;
    kk_integer_dup(_x_1, _ctx);
    _x_x451 = _x_1; /*int*/
  }
  kk_integer_t _x_x453 = kk_integer_dup(to_write, _ctx); /*int*/
  new_count = kk_integer_add(_x_x451,_x_x453,kk_context()); /*int*/
  kk_integer_t new_write_pos;
  kk_integer_t _x_x454;
  kk_integer_t _x_x455;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x456 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x_2 = _con_x456->write_pos;
    kk_integer_dup(_x_2, _ctx);
    _x_x455 = _x_2; /*int*/
  }
  kk_integer_t _x_x457 = kk_integer_dup(to_write, _ctx); /*int*/
  _x_x454 = kk_integer_add(_x_x455,_x_x457,kk_context()); /*int*/
  kk_integer_t _x_x458;
  {
    struct kk_src_ring__buffer_Buffer_config* _con_x459 = kk_src_ring__buffer__as_Buffer_config(config, _ctx);
    kk_integer_t _x_3 = _con_x459->capacity;
    kk_integer_t _pat_0_4 = _con_x459->slot_size;
    kk_integer_t _pat_1_3 = _con_x459->header_size;
    if kk_likely(kk_datatype_ptr_is_unique(config, _ctx)) {
      kk_integer_drop(_pat_1_3, _ctx);
      kk_integer_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(config, _ctx);
    }
    else {
      kk_integer_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(config, _ctx);
    }
    _x_x458 = _x_3; /*int*/
  }
  new_write_pos = kk_integer_mod(_x_x454,_x_x458,kk_context()); /*int*/
  kk_src_ring__buffer__buffer_state new_state;
  kk_integer_t _x_x460;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x461 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x_4 = _con_x461->read_pos;
    kk_integer_dup(_x_4, _ctx);
    _x_x460 = _x_4; /*int*/
  }
  int64_t _x_x462;
  int64_t _x_x463;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x464 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    int64_t _x_5 = _con_x464->total_written;
    _x_x463 = _x_5; /*int64*/
  }
  int64_t _x_x465;
  kk_integer_t _x_x466 = kk_integer_dup(to_write, _ctx); /*int*/
  _x_x465 = kk_std_num_int64_int64(_x_x466, _ctx); /*int64*/
  _x_x462 = (int64_t)((uint64_t)_x_x463 + (uint64_t)_x_x465); /*int64*/
  int64_t _x_x467;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x468 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _pat_0_7 = _con_x468->write_pos;
    kk_integer_t _pat_1_6 = _con_x468->read_pos;
    kk_integer_t _pat_2_4 = _con_x468->count;
    int64_t _x_6 = _con_x468->total_read;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_2_4, _ctx);
      kk_integer_drop(_pat_1_6, _ctx);
      kk_integer_drop(_pat_0_7, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x467 = _x_6; /*int64*/
  }
  new_state = kk_src_ring__buffer__new_Buffer_state(kk_reuse_null, 0, new_write_pos, _x_x460, new_count, _x_x462, _x_x467, _ctx); /*src/ring_buffer/buffer-state*/
  return kk_std_core_types__new_Tuple2(kk_integer_box(to_write, _ctx), kk_src_ring__buffer__buffer_state_box(new_state, _ctx), _ctx);
}
 
// Read n items, returns actual count read

kk_std_core_types__tuple2 kk_src_ring__buffer_read_batch(kk_src_ring__buffer__buffer_state state, kk_src_ring__buffer__buffer_config config, kk_integer_t n, kk_context_t* _ctx) { /* (state : buffer-state, config : buffer-config, n : int) -> (int, buffer-state) */ 
  kk_integer_t to_read;
  bool _match_x322;
  kk_integer_t _brw_x323;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x469 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x = _con_x469->count;
    kk_integer_dup(_x, _ctx);
    _brw_x323 = _x; /*int*/
  }
  bool _brw_x324 = kk_integer_gt_borrow(n,_brw_x323,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x323, _ctx);
  _match_x322 = _brw_x324; /*bool*/
  if (_match_x322) {
    kk_integer_drop(n, _ctx);
    {
      struct kk_src_ring__buffer_Buffer_state* _con_x470 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
      kk_integer_t _x_0 = _con_x470->count;
      kk_integer_dup(_x_0, _ctx);
      to_read = _x_0; /*int*/
    }
  }
  else {
    to_read = n; /*int*/
  }
  kk_integer_t new_count;
  kk_integer_t _x_x471;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x472 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x_0_0 = _con_x472->count;
    kk_integer_dup(_x_0_0, _ctx);
    _x_x471 = _x_0_0; /*int*/
  }
  kk_integer_t _x_x473 = kk_integer_dup(to_read, _ctx); /*int*/
  new_count = kk_integer_sub(_x_x471,_x_x473,kk_context()); /*int*/
  kk_integer_t new_read_pos;
  kk_integer_t _x_x474;
  kk_integer_t _x_x475;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x476 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x_1 = _con_x476->read_pos;
    kk_integer_dup(_x_1, _ctx);
    _x_x475 = _x_1; /*int*/
  }
  kk_integer_t _x_x477 = kk_integer_dup(to_read, _ctx); /*int*/
  _x_x474 = kk_integer_add(_x_x475,_x_x477,kk_context()); /*int*/
  kk_integer_t _x_x478;
  {
    struct kk_src_ring__buffer_Buffer_config* _con_x479 = kk_src_ring__buffer__as_Buffer_config(config, _ctx);
    kk_integer_t _x_2 = _con_x479->capacity;
    kk_integer_t _pat_0_3 = _con_x479->slot_size;
    kk_integer_t _pat_1_2 = _con_x479->header_size;
    if kk_likely(kk_datatype_ptr_is_unique(config, _ctx)) {
      kk_integer_drop(_pat_1_2, _ctx);
      kk_integer_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(config, _ctx);
    }
    else {
      kk_integer_dup(_x_2, _ctx);
      kk_datatype_ptr_decref(config, _ctx);
    }
    _x_x478 = _x_2; /*int*/
  }
  new_read_pos = kk_integer_mod(_x_x474,_x_x478,kk_context()); /*int*/
  kk_src_ring__buffer__buffer_state new_state;
  kk_integer_t _x_x480;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x481 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x_3 = _con_x481->write_pos;
    kk_integer_dup(_x_3, _ctx);
    _x_x480 = _x_3; /*int*/
  }
  int64_t _x_x482;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x483 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    int64_t _x_4 = _con_x483->total_written;
    _x_x482 = _x_4; /*int64*/
  }
  int64_t _x_x484;
  int64_t _x_x485;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x486 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _pat_0_6 = _con_x486->write_pos;
    kk_integer_t _pat_1_5 = _con_x486->read_pos;
    kk_integer_t _pat_2_4 = _con_x486->count;
    int64_t _x_5 = _con_x486->total_read;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_2_4, _ctx);
      kk_integer_drop(_pat_1_5, _ctx);
      kk_integer_drop(_pat_0_6, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x485 = _x_5; /*int64*/
  }
  int64_t _x_x487;
  kk_integer_t _x_x488 = kk_integer_dup(to_read, _ctx); /*int*/
  _x_x487 = kk_std_num_int64_int64(_x_x488, _ctx); /*int64*/
  _x_x484 = (int64_t)((uint64_t)_x_x485 + (uint64_t)_x_x487); /*int64*/
  new_state = kk_src_ring__buffer__new_Buffer_state(kk_reuse_null, 0, _x_x480, new_read_pos, new_count, _x_x482, _x_x484, _ctx); /*src/ring_buffer/buffer-state*/
  return kk_std_core_types__new_Tuple2(kk_integer_box(to_read, _ctx), kk_src_ring__buffer__buffer_state_box(new_state, _ctx), _ctx);
}

kk_string_t kk_src_ring__buffer_buffer_stats(kk_src_ring__buffer__buffer_state state, kk_src_ring__buffer__buffer_config config, kk_context_t* _ctx) { /* (state : buffer-state, config : buffer-config) -> string */ 
  kk_string_t _x_x489;
  kk_define_string_literal(, _s_x490, 12, "{\"capacity\":", _ctx)
  _x_x489 = kk_string_dup(_s_x490, _ctx); /*string*/
  kk_string_t _x_x491;
  kk_string_t _x_x492;
  kk_integer_t _x_x493;
  {
    struct kk_src_ring__buffer_Buffer_config* _con_x494 = kk_src_ring__buffer__as_Buffer_config(config, _ctx);
    kk_integer_t _x = _con_x494->capacity;
    kk_integer_dup(_x, _ctx);
    _x_x493 = _x; /*int*/
  }
  _x_x492 = kk_std_core_int_show(_x_x493, _ctx); /*string*/
  kk_string_t _x_x495;
  kk_string_t _x_x496;
  kk_define_string_literal(, _s_x497, 9, ",\"count\":", _ctx)
  _x_x496 = kk_string_dup(_s_x497, _ctx); /*string*/
  kk_string_t _x_x498;
  kk_string_t _x_x499;
  kk_integer_t _x_x500;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x501 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x_0 = _con_x501->count;
    kk_integer_dup(_x_0, _ctx);
    _x_x500 = _x_0; /*int*/
  }
  _x_x499 = kk_std_core_int_show(_x_x500, _ctx); /*string*/
  kk_string_t _x_x502;
  kk_string_t _x_x503;
  kk_define_string_literal(, _s_x504, 13, ",\"write_pos\":", _ctx)
  _x_x503 = kk_string_dup(_s_x504, _ctx); /*string*/
  kk_string_t _x_x505;
  kk_string_t _x_x506;
  kk_integer_t _x_x507;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x508 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x_1 = _con_x508->write_pos;
    kk_integer_dup(_x_1, _ctx);
    _x_x507 = _x_1; /*int*/
  }
  _x_x506 = kk_std_core_int_show(_x_x507, _ctx); /*string*/
  kk_string_t _x_x509;
  kk_string_t _x_x510;
  kk_define_string_literal(, _s_x511, 12, ",\"read_pos\":", _ctx)
  _x_x510 = kk_string_dup(_s_x511, _ctx); /*string*/
  kk_string_t _x_x512;
  kk_string_t _x_x513;
  kk_integer_t _x_x514;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x515 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x_2 = _con_x515->read_pos;
    kk_integer_dup(_x_2, _ctx);
    _x_x514 = _x_2; /*int*/
  }
  _x_x513 = kk_std_core_int_show(_x_x514, _ctx); /*string*/
  kk_string_t _x_x516;
  kk_string_t _x_x517;
  kk_define_string_literal(, _s_x518, 17, ",\"total_written\":", _ctx)
  _x_x517 = kk_string_dup(_s_x518, _ctx); /*string*/
  kk_string_t _x_x519;
  kk_string_t _x_x520;
  kk_integer_t _x_x521;
  int64_t _x_x522;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x523 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    int64_t _x_3 = _con_x523->total_written;
    _x_x522 = _x_3; /*int64*/
  }
  _x_x521 = kk_integer_from_int64(_x_x522,kk_context()); /*int*/
  _x_x520 = kk_std_core_int_show(_x_x521, _ctx); /*string*/
  kk_string_t _x_x524;
  kk_string_t _x_x525;
  kk_define_string_literal(, _s_x526, 14, ",\"total_read\":", _ctx)
  _x_x525 = kk_string_dup(_s_x526, _ctx); /*string*/
  kk_string_t _x_x527;
  kk_string_t _x_x528;
  kk_integer_t _x_x529;
  int64_t _x_x530;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x531 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    int64_t _x_4 = _con_x531->total_read;
    _x_x530 = _x_4; /*int64*/
  }
  _x_x529 = kk_integer_from_int64(_x_x530,kk_context()); /*int*/
  _x_x528 = kk_std_core_int_show(_x_x529, _ctx); /*string*/
  kk_string_t _x_x532;
  kk_string_t _x_x533;
  kk_define_string_literal(, _s_x534, 19, ",\"write_available\":", _ctx)
  _x_x533 = kk_string_dup(_s_x534, _ctx); /*string*/
  kk_string_t _x_x535;
  kk_string_t _x_x536;
  kk_integer_t _x_x537;
  kk_integer_t _x_x538;
  {
    struct kk_src_ring__buffer_Buffer_config* _con_x539 = kk_src_ring__buffer__as_Buffer_config(config, _ctx);
    kk_integer_t _x_6 = _con_x539->capacity;
    kk_integer_t _pat_0_6 = _con_x539->slot_size;
    kk_integer_t _pat_1_6 = _con_x539->header_size;
    if kk_likely(kk_datatype_ptr_is_unique(config, _ctx)) {
      kk_integer_drop(_pat_1_6, _ctx);
      kk_integer_drop(_pat_0_6, _ctx);
      kk_datatype_ptr_free(config, _ctx);
    }
    else {
      kk_integer_dup(_x_6, _ctx);
      kk_datatype_ptr_decref(config, _ctx);
    }
    _x_x538 = _x_6; /*int*/
  }
  kk_integer_t _x_x540;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x541 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _x_5 = _con_x541->count;
    kk_integer_dup(_x_5, _ctx);
    _x_x540 = _x_5; /*int*/
  }
  _x_x537 = kk_integer_sub(_x_x538,_x_x540,kk_context()); /*int*/
  _x_x536 = kk_std_core_int_show(_x_x537, _ctx); /*string*/
  kk_string_t _x_x542;
  kk_string_t _x_x543;
  kk_define_string_literal(, _s_x544, 18, ",\"read_available\":", _ctx)
  _x_x543 = kk_string_dup(_s_x544, _ctx); /*string*/
  kk_string_t _x_x545;
  kk_string_t _x_x546;
  kk_integer_t _x_x547;
  {
    struct kk_src_ring__buffer_Buffer_state* _con_x548 = kk_src_ring__buffer__as_Buffer_state(state, _ctx);
    kk_integer_t _pat_0_7 = _con_x548->write_pos;
    kk_integer_t _pat_1_7 = _con_x548->read_pos;
    kk_integer_t _x_7 = _con_x548->count;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_integer_drop(_pat_1_7, _ctx);
      kk_integer_drop(_pat_0_7, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_integer_dup(_x_7, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    _x_x547 = _x_7; /*int*/
  }
  _x_x546 = kk_std_core_int_show(_x_x547, _ctx); /*string*/
  kk_string_t _x_x549;
  kk_define_string_literal(, _s_x550, 1, "}", _ctx)
  _x_x549 = kk_string_dup(_s_x550, _ctx); /*string*/
  _x_x545 = kk_std_core_types__lp__plus__plus__rp_(_x_x546, _x_x549, _ctx); /*string*/
  _x_x542 = kk_std_core_types__lp__plus__plus__rp_(_x_x543, _x_x545, _ctx); /*string*/
  _x_x535 = kk_std_core_types__lp__plus__plus__rp_(_x_x536, _x_x542, _ctx); /*string*/
  _x_x532 = kk_std_core_types__lp__plus__plus__rp_(_x_x533, _x_x535, _ctx); /*string*/
  _x_x527 = kk_std_core_types__lp__plus__plus__rp_(_x_x528, _x_x532, _ctx); /*string*/
  _x_x524 = kk_std_core_types__lp__plus__plus__rp_(_x_x525, _x_x527, _ctx); /*string*/
  _x_x519 = kk_std_core_types__lp__plus__plus__rp_(_x_x520, _x_x524, _ctx); /*string*/
  _x_x516 = kk_std_core_types__lp__plus__plus__rp_(_x_x517, _x_x519, _ctx); /*string*/
  _x_x512 = kk_std_core_types__lp__plus__plus__rp_(_x_x513, _x_x516, _ctx); /*string*/
  _x_x509 = kk_std_core_types__lp__plus__plus__rp_(_x_x510, _x_x512, _ctx); /*string*/
  _x_x505 = kk_std_core_types__lp__plus__plus__rp_(_x_x506, _x_x509, _ctx); /*string*/
  _x_x502 = kk_std_core_types__lp__plus__plus__rp_(_x_x503, _x_x505, _ctx); /*string*/
  _x_x498 = kk_std_core_types__lp__plus__plus__rp_(_x_x499, _x_x502, _ctx); /*string*/
  _x_x495 = kk_std_core_types__lp__plus__plus__rp_(_x_x496, _x_x498, _ctx); /*string*/
  _x_x491 = kk_std_core_types__lp__plus__plus__rp_(_x_x492, _x_x495, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x489, _x_x491, _ctx);
}

kk_string_t kk_src_ring__buffer_extract_op(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x315;
  kk_string_t _x_x551 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x552;
  kk_define_string_literal(, _s_x553, 7, "\"write\"", _ctx)
  _x_x552 = kk_string_dup(_s_x553, _ctx); /*string*/
  _match_x315 = kk_string_contains(_x_x551,_x_x552,kk_context()); /*bool*/
  if (_match_x315) {
    kk_string_drop(line, _ctx);
    kk_define_string_literal(, _s_x554, 5, "write", _ctx)
    return kk_string_dup(_s_x554, _ctx);
  }
  {
    bool _match_x316;
    kk_string_t _x_x555 = kk_string_dup(line, _ctx); /*string*/
    kk_string_t _x_x556;
    kk_define_string_literal(, _s_x557, 6, "\"read\"", _ctx)
    _x_x556 = kk_string_dup(_s_x557, _ctx); /*string*/
    _match_x316 = kk_string_contains(_x_x555,_x_x556,kk_context()); /*bool*/
    if (_match_x316) {
      kk_string_drop(line, _ctx);
      kk_define_string_literal(, _s_x558, 4, "read", _ctx)
      return kk_string_dup(_s_x558, _ctx);
    }
    {
      bool _match_x317;
      kk_string_t _x_x559 = kk_string_dup(line, _ctx); /*string*/
      kk_string_t _x_x560;
      kk_define_string_literal(, _s_x561, 7, "\"stats\"", _ctx)
      _x_x560 = kk_string_dup(_s_x561, _ctx); /*string*/
      _match_x317 = kk_string_contains(_x_x559,_x_x560,kk_context()); /*bool*/
      if (_match_x317) {
        kk_string_drop(line, _ctx);
        kk_define_string_literal(, _s_x562, 5, "stats", _ctx)
        return kk_string_dup(_s_x562, _ctx);
      }
      {
        bool _match_x318;
        kk_string_t _x_x563 = kk_string_dup(line, _ctx); /*string*/
        kk_string_t _x_x564;
        kk_define_string_literal(, _s_x565, 13, "\"batch_write\"", _ctx)
        _x_x564 = kk_string_dup(_s_x565, _ctx); /*string*/
        _match_x318 = kk_string_contains(_x_x563,_x_x564,kk_context()); /*bool*/
        if (_match_x318) {
          kk_string_drop(line, _ctx);
          kk_define_string_literal(, _s_x566, 11, "batch_write", _ctx)
          return kk_string_dup(_s_x566, _ctx);
        }
        {
          bool _match_x319;
          kk_string_t _x_x567 = kk_string_dup(line, _ctx); /*string*/
          kk_string_t _x_x568;
          kk_define_string_literal(, _s_x569, 12, "\"batch_read\"", _ctx)
          _x_x568 = kk_string_dup(_s_x569, _ctx); /*string*/
          _match_x319 = kk_string_contains(_x_x567,_x_x568,kk_context()); /*bool*/
          if (_match_x319) {
            kk_string_drop(line, _ctx);
            kk_define_string_literal(, _s_x570, 10, "batch_read", _ctx)
            return kk_string_dup(_s_x570, _ctx);
          }
          {
            bool _match_x320;
            kk_string_t _x_x571 = kk_string_dup(line, _ctx); /*string*/
            kk_string_t _x_x572;
            kk_define_string_literal(, _s_x573, 7, "\"reset\"", _ctx)
            _x_x572 = kk_string_dup(_s_x573, _ctx); /*string*/
            _match_x320 = kk_string_contains(_x_x571,_x_x572,kk_context()); /*bool*/
            if (_match_x320) {
              kk_string_drop(line, _ctx);
              kk_define_string_literal(, _s_x574, 5, "reset", _ctx)
              return kk_string_dup(_s_x574, _ctx);
            }
            {
              bool _match_x321;
              kk_string_t _x_x575;
              kk_define_string_literal(, _s_x576, 6, "\"quit\"", _ctx)
              _x_x575 = kk_string_dup(_s_x576, _ctx); /*string*/
              _match_x321 = kk_string_contains(line,_x_x575,kk_context()); /*bool*/
              if (_match_x321) {
                kk_define_string_literal(, _s_x577, 4, "quit", _ctx)
                return kk_string_dup(_s_x577, _ctx);
              }
              {
                kk_define_string_literal(, _s_x578, 7, "unknown", _ctx)
                return kk_string_dup(_s_x578, _ctx);
              }
            }
          }
        }
      }
    }
  }
}

kk_integer_t kk_src_ring__buffer_extract_count(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> int */ 
  bool _match_x312;
  kk_string_t _x_x579 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x580;
  kk_define_string_literal(, _s_x581, 8, "\"count\":", _ctx)
  _x_x580 = kk_string_dup(_s_x581, _ctx); /*string*/
  _match_x312 = kk_string_contains(_x_x579,_x_x580,kk_context()); /*bool*/
  if (_match_x312) {
    kk_vector_t v_10019;
    kk_string_t _x_x582;
    kk_define_string_literal(, _s_x583, 8, "\"count\":", _ctx)
    _x_x582 = kk_string_dup(_s_x583, _ctx); /*string*/
    v_10019 = kk_string_splitv(line,_x_x582,kk_context()); /*vector<string>*/
    kk_std_core_types__list parts = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
    if (kk_std_core_types__is_Cons(parts, _ctx)) {
      struct kk_std_core_types_Cons* _con_x584 = kk_std_core_types__as_Cons(parts, _ctx);
      kk_box_t _box_x20 = _con_x584->head;
      kk_std_core_types__list xx = _con_x584->tail;
      kk_string_t _pat_0_0 = kk_string_unbox(_box_x20);
      if kk_likely(kk_datatype_ptr_is_unique(parts, _ctx)) {
        kk_string_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(parts, _ctx);
      }
      else {
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(parts, _ctx);
      }
      if (kk_std_core_types__is_Nil(xx, _ctx)) {
        return kk_integer_from_small(1);
      }
      {
        struct kk_std_core_types_Cons* _con_x585 = kk_std_core_types__as_Cons(xx, _ctx);
        kk_box_t _box_x21 = _con_x585->head;
        kk_std_core_types__list _pat_2 = _con_x585->tail;
        kk_string_t rest = kk_string_unbox(_box_x21);
        if kk_likely(kk_datatype_ptr_is_unique(xx, _ctx)) {
          kk_std_core_types__list_drop(_pat_2, _ctx);
          kk_datatype_ptr_free(xx, _ctx);
        }
        else {
          kk_string_dup(rest, _ctx);
          kk_datatype_ptr_decref(xx, _ctx);
        }
        kk_vector_t v_10019_0;
        kk_string_t _x_x586;
        kk_define_string_literal(, _s_x587, 1, "}", _ctx)
        _x_x586 = kk_string_dup(_s_x587, _ctx); /*string*/
        v_10019_0 = kk_string_splitv(rest,_x_x586,kk_context()); /*vector<string>*/
        kk_std_core_types__list num_parts = kk_std_core_vector_vlist(v_10019_0, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
        if (kk_std_core_types__is_Nil(num_parts, _ctx)) {
          return kk_integer_from_small(1);
        }
        {
          struct kk_std_core_types_Cons* _con_x588 = kk_std_core_types__as_Cons(num_parts, _ctx);
          kk_box_t _box_x22 = _con_x588->head;
          kk_std_core_types__list _pat_5 = _con_x588->tail;
          kk_string_t num_str = kk_string_unbox(_box_x22);
          if kk_likely(kk_datatype_ptr_is_unique(num_parts, _ctx)) {
            kk_std_core_types__list_drop(_pat_5, _ctx);
            kk_datatype_ptr_free(num_parts, _ctx);
          }
          else {
            kk_string_dup(num_str, _ctx);
            kk_datatype_ptr_decref(num_parts, _ctx);
          }
          kk_string_t s_1_10095;
          kk_string_t _x_x589 = kk_string_trim_left(num_str,kk_context()); /*string*/
          s_1_10095 = kk_string_trim_right(_x_x589,kk_context()); /*string*/
          kk_std_core_types__maybe _match_x313;
          bool _x_x590;
          kk_std_core_types__optional _match_x314 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
          if (kk_std_core_types__is_Optional(_match_x314, _ctx)) {
            kk_box_t _box_x23 = _match_x314._cons._Optional.value;
            bool _uniq_hex_581 = kk_bool_unbox(_box_x23);
            kk_std_core_types__optional_drop(_match_x314, _ctx);
            _x_x590 = _uniq_hex_581; /*bool*/
          }
          else {
            kk_std_core_types__optional_drop(_match_x314, _ctx);
            _x_x590 = false; /*bool*/
          }
          _match_x313 = kk_std_core_int_xparse(s_1_10095, _x_x590, _ctx); /*maybe<int>*/
          if (kk_std_core_types__is_Nothing(_match_x313, _ctx)) {
            return kk_integer_from_small(1);
          }
          {
            kk_box_t _box_x24 = _match_x313._cons.Just.value;
            kk_integer_t n = kk_integer_unbox(_box_x24, _ctx);
            kk_integer_dup(n, _ctx);
            kk_std_core_types__maybe_drop(_match_x313, _ctx);
            return n;
          }
        }
      }
    }
    {
      return kk_integer_from_small(1);
    }
  }
  {
    kk_string_drop(line, _ctx);
    return kk_integer_from_small(1);
  }
}
 
// monadic lift

kk_unit_t kk_src_ring__buffer__mlift_server_loop_10264(kk_src_ring__buffer__buffer_config config, kk_src_ring__buffer__buffer_state _c_x10204, kk_context_t* _ctx) { /* (config : buffer-config, buffer-state) -> () */ 
  kk_src_ring__buffer_server_loop(_c_x10204, config, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10265_fun593__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun593(kk_function_t _fself, kk_box_t _b_x28, kk_box_t _b_x29, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10265_fun593(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10265_fun593, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun593(kk_function_t _fself, kk_box_t _b_x28, kk_box_t _b_x29, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x594;
  kk_src_ring__buffer__buffer_state _x_x595 = kk_src_ring__buffer__buffer_state_unbox(_b_x28, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x596 = kk_src_ring__buffer__buffer_config_unbox(_b_x29, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  _x_x594 = kk_src_ring__buffer_try_write(_x_x595, _x_x596, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
  return kk_std_core_types__maybe_box(_x_x594, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10265_fun603__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun603(kk_function_t _fself, kk_box_t _b_x34, kk_box_t _b_x35, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10265_fun603(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10265_fun603, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun603(kk_function_t _fself, kk_box_t _b_x34, kk_box_t _b_x35, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x604;
  kk_src_ring__buffer__buffer_state _x_x605 = kk_src_ring__buffer__buffer_state_unbox(_b_x34, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x606 = kk_src_ring__buffer__buffer_config_unbox(_b_x35, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  _x_x604 = kk_src_ring__buffer_try_read(_x_x605, _x_x606, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
  return kk_std_core_types__maybe_box(_x_x604, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10265_fun613__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun613(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10265_fun613(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10265_fun613, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun613(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x614;
  kk_string_t _x_x615 = kk_string_unbox(_b_x39); /*string*/
  _x_x614 = kk_src_ring__buffer_extract_count(_x_x615, _ctx); /*int*/
  return kk_integer_box(_x_x614, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10265_fun617__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun617(kk_function_t _fself, kk_box_t _b_x46, kk_box_t _b_x47, kk_box_t _b_x48, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10265_fun617(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10265_fun617, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun617(kk_function_t _fself, kk_box_t _b_x46, kk_box_t _b_x47, kk_box_t _b_x48, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x618;
  kk_src_ring__buffer__buffer_state _x_x619 = kk_src_ring__buffer__buffer_state_unbox(_b_x46, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x620 = kk_src_ring__buffer__buffer_config_unbox(_b_x47, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  kk_integer_t _x_x621 = kk_integer_unbox(_b_x48, _ctx); /*int*/
  _x_x618 = kk_src_ring__buffer_write_batch(_x_x619, _x_x620, _x_x621, _ctx); /*(int, src/ring_buffer/buffer-state)*/
  return kk_std_core_types__tuple2_box(_x_x618, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10265_fun626__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun626(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10265_fun626(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10265_fun626, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun626(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x627;
  kk_string_t _x_x628 = kk_string_unbox(_b_x53); /*string*/
  _x_x627 = kk_src_ring__buffer_extract_count(_x_x628, _ctx); /*int*/
  return kk_integer_box(_x_x627, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10265_fun630__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun630(kk_function_t _fself, kk_box_t _b_x60, kk_box_t _b_x61, kk_box_t _b_x62, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10265_fun630(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10265_fun630, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun630(kk_function_t _fself, kk_box_t _b_x60, kk_box_t _b_x61, kk_box_t _b_x62, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x631;
  kk_src_ring__buffer__buffer_state _x_x632 = kk_src_ring__buffer__buffer_state_unbox(_b_x60, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x633 = kk_src_ring__buffer__buffer_config_unbox(_b_x61, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  kk_integer_t _x_x634 = kk_integer_unbox(_b_x62, _ctx); /*int*/
  _x_x631 = kk_src_ring__buffer_read_batch(_x_x632, _x_x633, _x_x634, _ctx); /*(int, src/ring_buffer/buffer-state)*/
  return kk_std_core_types__tuple2_box(_x_x631, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10265_fun640__t {
  struct kk_function_s _base;
  kk_src_ring__buffer__buffer_config config_0;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun640(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10265_fun640(kk_src_ring__buffer__buffer_config config_0, kk_context_t* _ctx) {
  struct kk_src_ring__buffer__mlift_server_loop_10265_fun640__t* _self = kk_function_alloc_as(struct kk_src_ring__buffer__mlift_server_loop_10265_fun640__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_ring__buffer__mlift_server_loop_10265_fun640, kk_context());
  _self->config_0 = config_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10265_fun640(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx) {
  struct kk_src_ring__buffer__mlift_server_loop_10265_fun640__t* _self = kk_function_as(struct kk_src_ring__buffer__mlift_server_loop_10265_fun640__t*, _fself, _ctx);
  kk_src_ring__buffer__buffer_config config_0 = _self->config_0; /* src/ring_buffer/buffer-config */
  kk_drop_match(_self, {kk_src_ring__buffer__buffer_config_dup(config_0, _ctx);}, {}, _ctx)
  kk_src_ring__buffer__buffer_state _c_x10204_0_82 = kk_src_ring__buffer__buffer_state_unbox(_b_x80, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/;
  kk_unit_t _x_x641 = kk_Unit;
  kk_src_ring__buffer__mlift_server_loop_10264(config_0, _c_x10204_0_82, _ctx);
  return kk_unit_box(_x_x641);
}

kk_unit_t kk_src_ring__buffer__mlift_server_loop_10265(kk_src_ring__buffer__buffer_config config_0, kk_string_t line, kk_string_t op, kk_src_ring__buffer__buffer_state state, kk_string_t _c_x10203, kk_context_t* _ctx) { /* (config : buffer-config, line : string, op : string, state : buffer-state, string) -> () */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(_c_x10203, _ctx);
  kk_src_ring__buffer__buffer_state x_10267;
  if (kk_string_cmp_cstr_borrow(op, "write", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_string_drop(line, _ctx);
    kk_std_core_types__maybe _match_x311;
    kk_box_t _x_x592;
    kk_box_t _x_x597;
    kk_src_ring__buffer__buffer_state _x_x598 = kk_src_ring__buffer__buffer_state_dup(state, _ctx); /*src/ring_buffer/buffer-state*/
    _x_x597 = kk_src_ring__buffer__buffer_state_box(_x_x598, _ctx); /*10000*/
    kk_box_t _x_x599;
    kk_src_ring__buffer__buffer_config _x_x600 = kk_src_ring__buffer__buffer_config_dup(config_0, _ctx); /*src/ring_buffer/buffer-config*/
    _x_x599 = kk_src_ring__buffer__buffer_config_box(_x_x600, _ctx); /*10001*/
    _x_x592 = kk_std_core_hnd__open_none2(kk_src_ring__buffer__new_mlift_server_loop_10265_fun593(_ctx), _x_x597, _x_x599, _ctx); /*10002*/
    _match_x311 = kk_std_core_types__maybe_unbox(_x_x592, KK_OWNED, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
    if (kk_std_core_types__is_Nothing(_match_x311, _ctx)) {
      x_10267 = state; /*src/ring_buffer/buffer-state*/
      goto _match_x591;
    }
    {
      kk_box_t _box_x30 = _match_x311._cons.Just.value;
      kk_src_ring__buffer__buffer_state s_1 = kk_src_ring__buffer__buffer_state_unbox(_box_x30, KK_BORROWED, _ctx);
      struct kk_src_ring__buffer_Buffer_state* _con_x601 = kk_src_ring__buffer__as_Buffer_state(s_1, _ctx);
      kk_datatype_ptr_dropn(state, (KK_I32(3)), _ctx);
      kk_src_ring__buffer__buffer_state_dup(s_1, _ctx);
      kk_std_core_types__maybe_drop(_match_x311, _ctx);
      x_10267 = s_1; /*src/ring_buffer/buffer-state*/
      goto _match_x591;
    }
  }
  if (kk_string_cmp_cstr_borrow(op, "read", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_string_drop(line, _ctx);
    kk_std_core_types__maybe _match_x310;
    kk_box_t _x_x602;
    kk_box_t _x_x607;
    kk_src_ring__buffer__buffer_state _x_x608 = kk_src_ring__buffer__buffer_state_dup(state, _ctx); /*src/ring_buffer/buffer-state*/
    _x_x607 = kk_src_ring__buffer__buffer_state_box(_x_x608, _ctx); /*10000*/
    kk_box_t _x_x609;
    kk_src_ring__buffer__buffer_config _x_x610 = kk_src_ring__buffer__buffer_config_dup(config_0, _ctx); /*src/ring_buffer/buffer-config*/
    _x_x609 = kk_src_ring__buffer__buffer_config_box(_x_x610, _ctx); /*10001*/
    _x_x602 = kk_std_core_hnd__open_none2(kk_src_ring__buffer__new_mlift_server_loop_10265_fun603(_ctx), _x_x607, _x_x609, _ctx); /*10002*/
    _match_x310 = kk_std_core_types__maybe_unbox(_x_x602, KK_OWNED, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
    if (kk_std_core_types__is_Nothing(_match_x310, _ctx)) {
      x_10267 = state; /*src/ring_buffer/buffer-state*/
      goto _match_x591;
    }
    {
      kk_box_t _box_x36 = _match_x310._cons.Just.value;
      kk_src_ring__buffer__buffer_state s_0_0 = kk_src_ring__buffer__buffer_state_unbox(_box_x36, KK_BORROWED, _ctx);
      struct kk_src_ring__buffer_Buffer_state* _con_x611 = kk_src_ring__buffer__as_Buffer_state(s_0_0, _ctx);
      kk_datatype_ptr_dropn(state, (KK_I32(3)), _ctx);
      kk_src_ring__buffer__buffer_state_dup(s_0_0, _ctx);
      kk_std_core_types__maybe_drop(_match_x310, _ctx);
      x_10267 = s_0_0; /*src/ring_buffer/buffer-state*/
      goto _match_x591;
    }
  }
  if (kk_string_cmp_cstr_borrow(op, "batch_write", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_integer_t n_1;
    kk_box_t _x_x612 = kk_std_core_hnd__open_none1(kk_src_ring__buffer__new_mlift_server_loop_10265_fun613(_ctx), kk_string_box(line), _ctx); /*10001*/
    n_1 = kk_integer_unbox(_x_x612, _ctx); /*int*/
    kk_std_core_types__tuple2 _match_x309;
    kk_box_t _x_x616;
    kk_box_t _x_x622;
    kk_src_ring__buffer__buffer_config _x_x623 = kk_src_ring__buffer__buffer_config_dup(config_0, _ctx); /*src/ring_buffer/buffer-config*/
    _x_x622 = kk_src_ring__buffer__buffer_config_box(_x_x623, _ctx); /*10001*/
    _x_x616 = kk_std_core_hnd__open_none3(kk_src_ring__buffer__new_mlift_server_loop_10265_fun617(_ctx), kk_src_ring__buffer__buffer_state_box(state, _ctx), _x_x622, kk_integer_box(n_1, _ctx), _ctx); /*10003*/
    _match_x309 = kk_std_core_types__tuple2_unbox(_x_x616, KK_OWNED, _ctx); /*(int, src/ring_buffer/buffer-state)*/
    {
      kk_box_t _box_x49 = _match_x309.fst;
      kk_box_t _box_x50 = _match_x309.snd;
      kk_src_ring__buffer__buffer_state s_1_0 = kk_src_ring__buffer__buffer_state_unbox(_box_x50, KK_BORROWED, _ctx);
      struct kk_src_ring__buffer_Buffer_state* _con_x624 = kk_src_ring__buffer__as_Buffer_state(s_1_0, _ctx);
      kk_src_ring__buffer__buffer_state_dup(s_1_0, _ctx);
      kk_std_core_types__tuple2_drop(_match_x309, _ctx);
      x_10267 = s_1_0; /*src/ring_buffer/buffer-state*/
      goto _match_x591;
    }
  }
  if (kk_string_cmp_cstr_borrow(op, "batch_read", _ctx) == 0) {
    kk_string_drop(op, _ctx);
    kk_integer_t n_2;
    kk_box_t _x_x625 = kk_std_core_hnd__open_none1(kk_src_ring__buffer__new_mlift_server_loop_10265_fun626(_ctx), kk_string_box(line), _ctx); /*10001*/
    n_2 = kk_integer_unbox(_x_x625, _ctx); /*int*/
    kk_std_core_types__tuple2 _match_x308;
    kk_box_t _x_x629;
    kk_box_t _x_x635;
    kk_src_ring__buffer__buffer_config _x_x636 = kk_src_ring__buffer__buffer_config_dup(config_0, _ctx); /*src/ring_buffer/buffer-config*/
    _x_x635 = kk_src_ring__buffer__buffer_config_box(_x_x636, _ctx); /*10001*/
    _x_x629 = kk_std_core_hnd__open_none3(kk_src_ring__buffer__new_mlift_server_loop_10265_fun630(_ctx), kk_src_ring__buffer__buffer_state_box(state, _ctx), _x_x635, kk_integer_box(n_2, _ctx), _ctx); /*10003*/
    _match_x308 = kk_std_core_types__tuple2_unbox(_x_x629, KK_OWNED, _ctx); /*(int, src/ring_buffer/buffer-state)*/
    {
      kk_box_t _box_x63 = _match_x308.fst;
      kk_box_t _box_x64 = _match_x308.snd;
      kk_src_ring__buffer__buffer_state s_2 = kk_src_ring__buffer__buffer_state_unbox(_box_x64, KK_BORROWED, _ctx);
      struct kk_src_ring__buffer_Buffer_state* _con_x637 = kk_src_ring__buffer__as_Buffer_state(s_2, _ctx);
      kk_src_ring__buffer__buffer_state_dup(s_2, _ctx);
      kk_std_core_types__tuple2_drop(_match_x308, _ctx);
      x_10267 = s_2; /*src/ring_buffer/buffer-state*/
      goto _match_x591;
    }
  }
  if (kk_string_cmp_cstr_borrow(op, "reset", _ctx) == 0) {
    kk_reuse_t _ru_x364 = kk_reuse_null; /*@reuse*/;
    kk_reuse_t _x_x638 = kk_datatype_ptr_dropn_reuse(state, (KK_I32(3)), _ctx); /*@reuse*/
    _ru_x364 = _x_x638;
    kk_string_drop(op, _ctx);
    kk_string_drop(line, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    int64_t x_0 = (KK_I64(0)); /*int64*/;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    int64_t x_1 = (KK_I64(0)); /*int64*/;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    x_10267 = kk_src_ring__buffer__new_Buffer_state(_ru_x364, 0, kk_integer_from_small(0), kk_integer_from_small(0), kk_integer_from_small(0), x_0, x_1, _ctx); /*src/ring_buffer/buffer-state*/
    goto _match_x591;
  }
  {
    kk_string_drop(op, _ctx);
    kk_string_drop(line, _ctx);
    x_10267 = state; /*src/ring_buffer/buffer-state*/
  }
  _match_x591: ;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10267, (KK_I32(3)), _ctx);
    kk_box_t _x_x639 = kk_std_core_hnd_yield_extend(kk_src_ring__buffer__new_mlift_server_loop_10265_fun640(config_0, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x639); return kk_Unit;
  }
  {
    kk_src_ring__buffer__mlift_server_loop_10264(config_0, x_10267, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10266_fun651__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun651(kk_function_t _fself, kk_box_t _b_x85, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10266_fun651(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10266_fun651, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun651(kk_function_t _fself, kk_box_t _b_x85, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x652;
  kk_string_t _x_x653 = kk_string_unbox(_b_x85); /*string*/
  _x_x652 = kk_src_ring__buffer_extract_op(_x_x653, _ctx); /*string*/
  return kk_string_box(_x_x652);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10266_fun658__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun658(kk_function_t _fself, kk_box_t _b_x91, kk_box_t _b_x92, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10266_fun658(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10266_fun658, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun658(kk_function_t _fself, kk_box_t _b_x91, kk_box_t _b_x92, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x659;
  kk_src_ring__buffer__buffer_state _x_x660 = kk_src_ring__buffer__buffer_state_unbox(_b_x91, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x661 = kk_src_ring__buffer__buffer_config_unbox(_b_x92, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  _x_x659 = kk_src_ring__buffer_try_write(_x_x660, _x_x661, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
  return kk_std_core_types__maybe_box(_x_x659, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10266_fun684__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun684(kk_function_t _fself, kk_box_t _b_x97, kk_box_t _b_x98, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10266_fun684(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10266_fun684, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun684(kk_function_t _fself, kk_box_t _b_x97, kk_box_t _b_x98, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x685;
  kk_src_ring__buffer__buffer_state _x_x686 = kk_src_ring__buffer__buffer_state_unbox(_b_x97, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x687 = kk_src_ring__buffer__buffer_config_unbox(_b_x98, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  _x_x685 = kk_src_ring__buffer_try_read(_x_x686, _x_x687, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
  return kk_std_core_types__maybe_box(_x_x685, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10266_fun703__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun703(kk_function_t _fself, kk_box_t _b_x102, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10266_fun703(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10266_fun703, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun703(kk_function_t _fself, kk_box_t _b_x102, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x704;
  kk_string_t _x_x705 = kk_string_unbox(_b_x102); /*string*/
  _x_x704 = kk_src_ring__buffer_extract_count(_x_x705, _ctx); /*int*/
  return kk_integer_box(_x_x704, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10266_fun709__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun709(kk_function_t _fself, kk_box_t _b_x109, kk_box_t _b_x110, kk_box_t _b_x111, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10266_fun709(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10266_fun709, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun709(kk_function_t _fself, kk_box_t _b_x109, kk_box_t _b_x110, kk_box_t _b_x111, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x710;
  kk_src_ring__buffer__buffer_state _x_x711 = kk_src_ring__buffer__buffer_state_unbox(_b_x109, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x712 = kk_src_ring__buffer__buffer_config_unbox(_b_x110, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  kk_integer_t _x_x713 = kk_integer_unbox(_b_x111, _ctx); /*int*/
  _x_x710 = kk_src_ring__buffer_write_batch(_x_x711, _x_x712, _x_x713, _ctx); /*(int, src/ring_buffer/buffer-state)*/
  return kk_std_core_types__tuple2_box(_x_x710, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10266_fun733__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun733(kk_function_t _fself, kk_box_t _b_x116, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10266_fun733(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10266_fun733, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun733(kk_function_t _fself, kk_box_t _b_x116, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x734;
  kk_string_t _x_x735 = kk_string_unbox(_b_x116); /*string*/
  _x_x734 = kk_src_ring__buffer_extract_count(_x_x735, _ctx); /*int*/
  return kk_integer_box(_x_x734, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10266_fun739__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun739(kk_function_t _fself, kk_box_t _b_x123, kk_box_t _b_x124, kk_box_t _b_x125, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10266_fun739(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10266_fun739, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun739(kk_function_t _fself, kk_box_t _b_x123, kk_box_t _b_x124, kk_box_t _b_x125, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x740;
  kk_src_ring__buffer__buffer_state _x_x741 = kk_src_ring__buffer__buffer_state_unbox(_b_x123, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x742 = kk_src_ring__buffer__buffer_config_unbox(_b_x124, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  kk_integer_t _x_x743 = kk_integer_unbox(_b_x125, _ctx); /*int*/
  _x_x740 = kk_src_ring__buffer_read_batch(_x_x741, _x_x742, _x_x743, _ctx); /*(int, src/ring_buffer/buffer-state)*/
  return kk_std_core_types__tuple2_box(_x_x740, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10266_fun763__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun763(kk_function_t _fself, kk_box_t _b_x131, kk_box_t _b_x132, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10266_fun763(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer__mlift_server_loop_10266_fun763, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun763(kk_function_t _fself, kk_box_t _b_x131, kk_box_t _b_x132, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x764;
  kk_src_ring__buffer__buffer_state _x_x765 = kk_src_ring__buffer__buffer_state_unbox(_b_x131, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x766 = kk_src_ring__buffer__buffer_config_unbox(_b_x132, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  _x_x764 = kk_src_ring__buffer_buffer_stats(_x_x765, _x_x766, _ctx); /*string*/
  return kk_string_box(_x_x764);
}


// lift anonymous function
struct kk_src_ring__buffer__mlift_server_loop_10266_fun774__t {
  struct kk_function_s _base;
  kk_src_ring__buffer__buffer_config config_1;
  kk_string_t line_0;
  kk_string_t op_0;
  kk_src_ring__buffer__buffer_state state_0;
};
static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun774(kk_function_t _fself, kk_box_t _b_x151, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer__new_mlift_server_loop_10266_fun774(kk_src_ring__buffer__buffer_config config_1, kk_string_t line_0, kk_string_t op_0, kk_src_ring__buffer__buffer_state state_0, kk_context_t* _ctx) {
  struct kk_src_ring__buffer__mlift_server_loop_10266_fun774__t* _self = kk_function_alloc_as(struct kk_src_ring__buffer__mlift_server_loop_10266_fun774__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_ring__buffer__mlift_server_loop_10266_fun774, kk_context());
  _self->config_1 = config_1;
  _self->line_0 = line_0;
  _self->op_0 = op_0;
  _self->state_0 = state_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_ring__buffer__mlift_server_loop_10266_fun774(kk_function_t _fself, kk_box_t _b_x151, kk_context_t* _ctx) {
  struct kk_src_ring__buffer__mlift_server_loop_10266_fun774__t* _self = kk_function_as(struct kk_src_ring__buffer__mlift_server_loop_10266_fun774__t*, _fself, _ctx);
  kk_src_ring__buffer__buffer_config config_1 = _self->config_1; /* src/ring_buffer/buffer-config */
  kk_string_t line_0 = _self->line_0; /* string */
  kk_string_t op_0 = _self->op_0; /* string */
  kk_src_ring__buffer__buffer_state state_0 = _self->state_0; /* src/ring_buffer/buffer-state */
  kk_drop_match(_self, {kk_src_ring__buffer__buffer_config_dup(config_1, _ctx);kk_string_dup(line_0, _ctx);kk_string_dup(op_0, _ctx);kk_src_ring__buffer__buffer_state_dup(state_0, _ctx);}, {}, _ctx)
  kk_string_t _c_x10203_0_153 = kk_string_unbox(_b_x151); /*string*/;
  kk_unit_t _x_x775 = kk_Unit;
  kk_src_ring__buffer__mlift_server_loop_10265(config_1, line_0, op_0, state_0, _c_x10203_0_153, _ctx);
  return kk_unit_box(_x_x775);
}

kk_unit_t kk_src_ring__buffer__mlift_server_loop_10266(kk_src_ring__buffer__buffer_config config_1, kk_src_ring__buffer__buffer_state state_0, kk_string_t line_0, kk_context_t* _ctx) { /* (config : buffer-config, state : buffer-state, line : string) -> <console/console,exn> () */ 
  bool _match_x300;
  kk_string_t _x_x642 = kk_string_dup(line_0, _ctx); /*string*/
  kk_string_t _x_x643 = kk_string_empty(); /*string*/
  _match_x300 = kk_string_is_eq(_x_x642,_x_x643,kk_context()); /*bool*/
  if (_match_x300) {
    kk_datatype_ptr_dropn(state_0, (KK_I32(3)), _ctx);
    kk_string_drop(line_0, _ctx);
    kk_datatype_ptr_dropn(config_1, (KK_I32(3)), _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    bool _match_x301;
    kk_string_t _x_x645 = kk_string_dup(line_0, _ctx); /*string*/
    kk_string_t _x_x646;
    kk_define_string_literal(, _s_x647, 6, "\"quit\"", _ctx)
    _x_x646 = kk_string_dup(_s_x647, _ctx); /*string*/
    _match_x301 = kk_string_contains(_x_x645,_x_x646,kk_context()); /*bool*/
    if (_match_x301) {
      kk_datatype_ptr_dropn(state_0, (KK_I32(3)), _ctx);
      kk_string_drop(line_0, _ctx);
      kk_datatype_ptr_dropn(config_1, (KK_I32(3)), _ctx);
      kk_string_t _x_x648;
      kk_define_string_literal(, _s_x649, 20, "{\"status\":\"stopped\"}", _ctx)
      _x_x648 = kk_string_dup(_s_x649, _ctx); /*string*/
      kk_std_core_console_printsln(_x_x648, _ctx); return kk_Unit;
    }
    {
      kk_string_t op_0;
      kk_box_t _x_x650;
      kk_box_t _x_x654;
      kk_string_t _x_x655 = kk_string_dup(line_0, _ctx); /*string*/
      _x_x654 = kk_string_box(_x_x655); /*10000*/
      _x_x650 = kk_std_core_hnd__open_none1(kk_src_ring__buffer__new_mlift_server_loop_10266_fun651(_ctx), _x_x654, _ctx); /*10001*/
      op_0 = kk_string_unbox(_x_x650); /*string*/
      kk_string_t x_2_10273;
      if (kk_string_cmp_cstr_borrow(op_0, "write", _ctx) == 0) {
        kk_std_core_types__maybe _match_x306;
        kk_box_t _x_x657;
        kk_box_t _x_x662;
        kk_src_ring__buffer__buffer_state _x_x663 = kk_src_ring__buffer__buffer_state_dup(state_0, _ctx); /*src/ring_buffer/buffer-state*/
        _x_x662 = kk_src_ring__buffer__buffer_state_box(_x_x663, _ctx); /*10000*/
        kk_box_t _x_x664;
        kk_src_ring__buffer__buffer_config _x_x665 = kk_src_ring__buffer__buffer_config_dup(config_1, _ctx); /*src/ring_buffer/buffer-config*/
        _x_x664 = kk_src_ring__buffer__buffer_config_box(_x_x665, _ctx); /*10001*/
        _x_x657 = kk_std_core_hnd__open_none2(kk_src_ring__buffer__new_mlift_server_loop_10266_fun658(_ctx), _x_x662, _x_x664, _ctx); /*10002*/
        _match_x306 = kk_std_core_types__maybe_unbox(_x_x657, KK_OWNED, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
        if (kk_std_core_types__is_Nothing(_match_x306, _ctx)) {
          kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_1 = kk_Unit;
          kk_evv_set(w_1,kk_context());
          kk_string_t _x_x666;
          kk_define_string_literal(, _s_x667, 31, "{\"error\":\"buffer_full\",\"count\":", _ctx)
          _x_x666 = kk_string_dup(_s_x667, _ctx); /*string*/
          kk_string_t _x_x668;
          kk_string_t _x_x669;
          kk_integer_t _x_x670;
          {
            struct kk_src_ring__buffer_Buffer_state* _con_x671 = kk_src_ring__buffer__as_Buffer_state(state_0, _ctx);
            kk_integer_t _x = _con_x671->count;
            kk_integer_dup(_x, _ctx);
            _x_x670 = _x; /*int*/
          }
          _x_x669 = kk_std_core_int_show(_x_x670, _ctx); /*string*/
          kk_string_t _x_x672;
          kk_define_string_literal(, _s_x673, 1, "}", _ctx)
          _x_x672 = kk_string_dup(_s_x673, _ctx); /*string*/
          _x_x668 = kk_std_core_types__lp__plus__plus__rp_(_x_x669, _x_x672, _ctx); /*string*/
          x_2_10273 = kk_std_core_types__lp__plus__plus__rp_(_x_x666, _x_x668, _ctx); /*string*/
          goto _match_x656;
        }
        {
          kk_box_t _box_x93 = _match_x306._cons.Just.value;
          kk_src_ring__buffer__buffer_state new_state = kk_src_ring__buffer__buffer_state_unbox(_box_x93, KK_BORROWED, _ctx);
          struct kk_src_ring__buffer_Buffer_state* _con_x674 = kk_src_ring__buffer__as_Buffer_state(new_state, _ctx);
          kk_src_ring__buffer__buffer_state_dup(new_state, _ctx);
          kk_std_core_types__maybe_drop(_match_x306, _ctx);
          kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_2 = kk_Unit;
          kk_evv_set(w_2,kk_context());
          kk_string_t _x_x675;
          kk_define_string_literal(, _s_x676, 28, "{\"written\":true,\"write_pos\":", _ctx)
          _x_x675 = kk_string_dup(_s_x676, _ctx); /*string*/
          kk_string_t _x_x677;
          kk_string_t _x_x678;
          kk_integer_t _x_x679;
          {
            struct kk_src_ring__buffer_Buffer_state* _con_x680 = kk_src_ring__buffer__as_Buffer_state(new_state, _ctx);
            kk_integer_t _x_0 = _con_x680->write_pos;
            kk_integer_t _pat_0_1_0 = _con_x680->read_pos;
            kk_integer_t _pat_1_1 = _con_x680->count;
            if kk_likely(kk_datatype_ptr_is_unique(new_state, _ctx)) {
              kk_integer_drop(_pat_1_1, _ctx);
              kk_integer_drop(_pat_0_1_0, _ctx);
              kk_datatype_ptr_free(new_state, _ctx);
            }
            else {
              kk_integer_dup(_x_0, _ctx);
              kk_datatype_ptr_decref(new_state, _ctx);
            }
            _x_x679 = _x_0; /*int*/
          }
          _x_x678 = kk_std_core_int_show(_x_x679, _ctx); /*string*/
          kk_string_t _x_x681;
          kk_define_string_literal(, _s_x682, 1, "}", _ctx)
          _x_x681 = kk_string_dup(_s_x682, _ctx); /*string*/
          _x_x677 = kk_std_core_types__lp__plus__plus__rp_(_x_x678, _x_x681, _ctx); /*string*/
          x_2_10273 = kk_std_core_types__lp__plus__plus__rp_(_x_x675, _x_x677, _ctx); /*string*/
          goto _match_x656;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_0, "read", _ctx) == 0) {
        kk_std_core_types__maybe _match_x305;
        kk_box_t _x_x683;
        kk_box_t _x_x688;
        kk_src_ring__buffer__buffer_state _x_x689 = kk_src_ring__buffer__buffer_state_dup(state_0, _ctx); /*src/ring_buffer/buffer-state*/
        _x_x688 = kk_src_ring__buffer__buffer_state_box(_x_x689, _ctx); /*10000*/
        kk_box_t _x_x690;
        kk_src_ring__buffer__buffer_config _x_x691 = kk_src_ring__buffer__buffer_config_dup(config_1, _ctx); /*src/ring_buffer/buffer-config*/
        _x_x690 = kk_src_ring__buffer__buffer_config_box(_x_x691, _ctx); /*10001*/
        _x_x683 = kk_std_core_hnd__open_none2(kk_src_ring__buffer__new_mlift_server_loop_10266_fun684(_ctx), _x_x688, _x_x690, _ctx); /*10002*/
        _match_x305 = kk_std_core_types__maybe_unbox(_x_x683, KK_OWNED, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
        if (kk_std_core_types__is_Nothing(_match_x305, _ctx)) {
          kk_define_string_literal(, _s_x692, 24, "{\"error\":\"buffer_empty\"}", _ctx)
          x_2_10273 = kk_string_dup(_s_x692, _ctx); /*string*/
          goto _match_x656;
        }
        {
          kk_box_t _box_x99 = _match_x305._cons.Just.value;
          kk_src_ring__buffer__buffer_state new_state_0 = kk_src_ring__buffer__buffer_state_unbox(_box_x99, KK_BORROWED, _ctx);
          struct kk_src_ring__buffer_Buffer_state* _con_x693 = kk_src_ring__buffer__as_Buffer_state(new_state_0, _ctx);
          kk_src_ring__buffer__buffer_state_dup(new_state_0, _ctx);
          kk_std_core_types__maybe_drop(_match_x305, _ctx);
          kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
          kk_unit_t keep_3 = kk_Unit;
          kk_evv_set(w_3,kk_context());
          kk_string_t _x_x694;
          kk_define_string_literal(, _s_x695, 24, "{\"read\":true,\"read_pos\":", _ctx)
          _x_x694 = kk_string_dup(_s_x695, _ctx); /*string*/
          kk_string_t _x_x696;
          kk_string_t _x_x697;
          kk_integer_t _x_x698;
          {
            struct kk_src_ring__buffer_Buffer_state* _con_x699 = kk_src_ring__buffer__as_Buffer_state(new_state_0, _ctx);
            kk_integer_t _pat_0_2 = _con_x699->write_pos;
            kk_integer_t _x_1 = _con_x699->read_pos;
            kk_integer_t _pat_1_2 = _con_x699->count;
            if kk_likely(kk_datatype_ptr_is_unique(new_state_0, _ctx)) {
              kk_integer_drop(_pat_1_2, _ctx);
              kk_integer_drop(_pat_0_2, _ctx);
              kk_datatype_ptr_free(new_state_0, _ctx);
            }
            else {
              kk_integer_dup(_x_1, _ctx);
              kk_datatype_ptr_decref(new_state_0, _ctx);
            }
            _x_x698 = _x_1; /*int*/
          }
          _x_x697 = kk_std_core_int_show(_x_x698, _ctx); /*string*/
          kk_string_t _x_x700;
          kk_define_string_literal(, _s_x701, 1, "}", _ctx)
          _x_x700 = kk_string_dup(_s_x701, _ctx); /*string*/
          _x_x696 = kk_std_core_types__lp__plus__plus__rp_(_x_x697, _x_x700, _ctx); /*string*/
          x_2_10273 = kk_std_core_types__lp__plus__plus__rp_(_x_x694, _x_x696, _ctx); /*string*/
          goto _match_x656;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_0, "batch_write", _ctx) == 0) {
        kk_integer_t n;
        kk_box_t _x_x702;
        kk_box_t _x_x706;
        kk_string_t _x_x707 = kk_string_dup(line_0, _ctx); /*string*/
        _x_x706 = kk_string_box(_x_x707); /*10000*/
        _x_x702 = kk_std_core_hnd__open_none1(kk_src_ring__buffer__new_mlift_server_loop_10266_fun703(_ctx), _x_x706, _ctx); /*10001*/
        n = kk_integer_unbox(_x_x702, _ctx); /*int*/
        kk_std_core_types__tuple2 _match_x304;
        kk_box_t _x_x708;
        kk_box_t _x_x714;
        kk_src_ring__buffer__buffer_state _x_x715 = kk_src_ring__buffer__buffer_state_dup(state_0, _ctx); /*src/ring_buffer/buffer-state*/
        _x_x714 = kk_src_ring__buffer__buffer_state_box(_x_x715, _ctx); /*10000*/
        kk_box_t _x_x716;
        kk_src_ring__buffer__buffer_config _x_x717 = kk_src_ring__buffer__buffer_config_dup(config_1, _ctx); /*src/ring_buffer/buffer-config*/
        _x_x716 = kk_src_ring__buffer__buffer_config_box(_x_x717, _ctx); /*10001*/
        kk_box_t _x_x718;
        kk_integer_t _x_x719 = kk_integer_dup(n, _ctx); /*int*/
        _x_x718 = kk_integer_box(_x_x719, _ctx); /*10002*/
        _x_x708 = kk_std_core_hnd__open_none3(kk_src_ring__buffer__new_mlift_server_loop_10266_fun709(_ctx), _x_x714, _x_x716, _x_x718, _ctx); /*10003*/
        _match_x304 = kk_std_core_types__tuple2_unbox(_x_x708, KK_OWNED, _ctx); /*(int, src/ring_buffer/buffer-state)*/
        {
          kk_box_t _box_x112 = _match_x304.fst;
          kk_box_t _box_x113 = _match_x304.snd;
          kk_src_ring__buffer__buffer_state new_state_1 = kk_src_ring__buffer__buffer_state_unbox(_box_x113, KK_BORROWED, _ctx);
          struct kk_src_ring__buffer_Buffer_state* _con_x720 = kk_src_ring__buffer__as_Buffer_state(new_state_1, _ctx);
          kk_integer_t written = kk_integer_unbox(_box_x112, _ctx);
          kk_integer_dup(written, _ctx);
          kk_std_core_types__tuple2_drop(_match_x304, _ctx);
          kk_string_t _x_x721;
          kk_define_string_literal(, _s_x722, 15, "{\"batch_write\":", _ctx)
          _x_x721 = kk_string_dup(_s_x722, _ctx); /*string*/
          kk_string_t _x_x723;
          kk_string_t _x_x724 = kk_std_core_int_show(written, _ctx); /*string*/
          kk_string_t _x_x725;
          kk_string_t _x_x726;
          kk_define_string_literal(, _s_x727, 13, ",\"requested\":", _ctx)
          _x_x726 = kk_string_dup(_s_x727, _ctx); /*string*/
          kk_string_t _x_x728;
          kk_string_t _x_x729 = kk_std_core_int_show(n, _ctx); /*string*/
          kk_string_t _x_x730;
          kk_define_string_literal(, _s_x731, 1, "}", _ctx)
          _x_x730 = kk_string_dup(_s_x731, _ctx); /*string*/
          _x_x728 = kk_std_core_types__lp__plus__plus__rp_(_x_x729, _x_x730, _ctx); /*string*/
          _x_x725 = kk_std_core_types__lp__plus__plus__rp_(_x_x726, _x_x728, _ctx); /*string*/
          _x_x723 = kk_std_core_types__lp__plus__plus__rp_(_x_x724, _x_x725, _ctx); /*string*/
          x_2_10273 = kk_std_core_types__lp__plus__plus__rp_(_x_x721, _x_x723, _ctx); /*string*/
          goto _match_x656;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_0, "batch_read", _ctx) == 0) {
        kk_integer_t n_0;
        kk_box_t _x_x732;
        kk_box_t _x_x736;
        kk_string_t _x_x737 = kk_string_dup(line_0, _ctx); /*string*/
        _x_x736 = kk_string_box(_x_x737); /*10000*/
        _x_x732 = kk_std_core_hnd__open_none1(kk_src_ring__buffer__new_mlift_server_loop_10266_fun733(_ctx), _x_x736, _ctx); /*10001*/
        n_0 = kk_integer_unbox(_x_x732, _ctx); /*int*/
        kk_std_core_types__tuple2 _match_x303;
        kk_box_t _x_x738;
        kk_box_t _x_x744;
        kk_src_ring__buffer__buffer_state _x_x745 = kk_src_ring__buffer__buffer_state_dup(state_0, _ctx); /*src/ring_buffer/buffer-state*/
        _x_x744 = kk_src_ring__buffer__buffer_state_box(_x_x745, _ctx); /*10000*/
        kk_box_t _x_x746;
        kk_src_ring__buffer__buffer_config _x_x747 = kk_src_ring__buffer__buffer_config_dup(config_1, _ctx); /*src/ring_buffer/buffer-config*/
        _x_x746 = kk_src_ring__buffer__buffer_config_box(_x_x747, _ctx); /*10001*/
        kk_box_t _x_x748;
        kk_integer_t _x_x749 = kk_integer_dup(n_0, _ctx); /*int*/
        _x_x748 = kk_integer_box(_x_x749, _ctx); /*10002*/
        _x_x738 = kk_std_core_hnd__open_none3(kk_src_ring__buffer__new_mlift_server_loop_10266_fun739(_ctx), _x_x744, _x_x746, _x_x748, _ctx); /*10003*/
        _match_x303 = kk_std_core_types__tuple2_unbox(_x_x738, KK_OWNED, _ctx); /*(int, src/ring_buffer/buffer-state)*/
        {
          kk_box_t _box_x126 = _match_x303.fst;
          kk_box_t _box_x127 = _match_x303.snd;
          kk_src_ring__buffer__buffer_state new_state_2 = kk_src_ring__buffer__buffer_state_unbox(_box_x127, KK_BORROWED, _ctx);
          struct kk_src_ring__buffer_Buffer_state* _con_x750 = kk_src_ring__buffer__as_Buffer_state(new_state_2, _ctx);
          kk_integer_t read = kk_integer_unbox(_box_x126, _ctx);
          kk_integer_dup(read, _ctx);
          kk_std_core_types__tuple2_drop(_match_x303, _ctx);
          kk_string_t _x_x751;
          kk_define_string_literal(, _s_x752, 14, "{\"batch_read\":", _ctx)
          _x_x751 = kk_string_dup(_s_x752, _ctx); /*string*/
          kk_string_t _x_x753;
          kk_string_t _x_x754 = kk_std_core_int_show(read, _ctx); /*string*/
          kk_string_t _x_x755;
          kk_string_t _x_x756;
          kk_define_string_literal(, _s_x757, 13, ",\"requested\":", _ctx)
          _x_x756 = kk_string_dup(_s_x757, _ctx); /*string*/
          kk_string_t _x_x758;
          kk_string_t _x_x759 = kk_std_core_int_show(n_0, _ctx); /*string*/
          kk_string_t _x_x760;
          kk_define_string_literal(, _s_x761, 1, "}", _ctx)
          _x_x760 = kk_string_dup(_s_x761, _ctx); /*string*/
          _x_x758 = kk_std_core_types__lp__plus__plus__rp_(_x_x759, _x_x760, _ctx); /*string*/
          _x_x755 = kk_std_core_types__lp__plus__plus__rp_(_x_x756, _x_x758, _ctx); /*string*/
          _x_x753 = kk_std_core_types__lp__plus__plus__rp_(_x_x754, _x_x755, _ctx); /*string*/
          x_2_10273 = kk_std_core_types__lp__plus__plus__rp_(_x_x751, _x_x753, _ctx); /*string*/
          goto _match_x656;
        }
      }
      if (kk_string_cmp_cstr_borrow(op_0, "stats", _ctx) == 0) {
        kk_box_t _x_x762;
        kk_box_t _x_x767;
        kk_src_ring__buffer__buffer_state _x_x768 = kk_src_ring__buffer__buffer_state_dup(state_0, _ctx); /*src/ring_buffer/buffer-state*/
        _x_x767 = kk_src_ring__buffer__buffer_state_box(_x_x768, _ctx); /*10000*/
        kk_box_t _x_x769;
        kk_src_ring__buffer__buffer_config _x_x770 = kk_src_ring__buffer__buffer_config_dup(config_1, _ctx); /*src/ring_buffer/buffer-config*/
        _x_x769 = kk_src_ring__buffer__buffer_config_box(_x_x770, _ctx); /*10001*/
        _x_x762 = kk_std_core_hnd__open_none2(kk_src_ring__buffer__new_mlift_server_loop_10266_fun763(_ctx), _x_x767, _x_x769, _ctx); /*10002*/
        x_2_10273 = kk_string_unbox(_x_x762); /*string*/
        goto _match_x656;
      }
      if (kk_string_cmp_cstr_borrow(op_0, "reset", _ctx) == 0) {
        kk_define_string_literal(, _s_x771, 14, "{\"reset\":true}", _ctx)
        x_2_10273 = kk_string_dup(_s_x771, _ctx); /*string*/
        goto _match_x656;
      }
      {
        kk_define_string_literal(, _s_x772, 22, "{\"error\":\"unknown op\"}", _ctx)
        x_2_10273 = kk_string_dup(_s_x772, _ctx); /*string*/
      }
      _match_x656: ;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_2_10273, _ctx);
        kk_box_t _x_x773 = kk_std_core_hnd_yield_extend(kk_src_ring__buffer__new_mlift_server_loop_10266_fun774(config_1, line_0, op_0, state_0, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x773); return kk_Unit;
      }
      {
        kk_src_ring__buffer__mlift_server_loop_10265(config_1, line_0, op_0, state_0, x_2_10273, _ctx); return kk_Unit;
      }
    }
  }
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun777__t {
  struct kk_function_s _base;
  kk_src_ring__buffer__buffer_config config_2;
  kk_src_ring__buffer__buffer_state state_1;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun777(kk_function_t _fself, kk_box_t _b_x155, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun777(kk_src_ring__buffer__buffer_config config_2, kk_src_ring__buffer__buffer_state state_1, kk_context_t* _ctx) {
  struct kk_src_ring__buffer_server_loop_fun777__t* _self = kk_function_alloc_as(struct kk_src_ring__buffer_server_loop_fun777__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_ring__buffer_server_loop_fun777, kk_context());
  _self->config_2 = config_2;
  _self->state_1 = state_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun777(kk_function_t _fself, kk_box_t _b_x155, kk_context_t* _ctx) {
  struct kk_src_ring__buffer_server_loop_fun777__t* _self = kk_function_as(struct kk_src_ring__buffer_server_loop_fun777__t*, _fself, _ctx);
  kk_src_ring__buffer__buffer_config config_2 = _self->config_2; /* src/ring_buffer/buffer-config */
  kk_src_ring__buffer__buffer_state state_1 = _self->state_1; /* src/ring_buffer/buffer-state */
  kk_drop_match(_self, {kk_src_ring__buffer__buffer_config_dup(config_2, _ctx);kk_src_ring__buffer__buffer_state_dup(state_1, _ctx);}, {}, _ctx)
  kk_string_t line_1_284 = kk_string_unbox(_b_x155); /*string*/;
  kk_unit_t _x_x778 = kk_Unit;
  kk_src_ring__buffer__mlift_server_loop_10266(config_2, state_1, line_1_284, _ctx);
  return kk_unit_box(_x_x778);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun788__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun788(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun788(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun788, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun788(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x789;
  kk_string_t _x_x790 = kk_string_unbox(_b_x158); /*string*/
  _x_x789 = kk_src_ring__buffer_extract_op(_x_x790, _ctx); /*string*/
  return kk_string_box(_x_x789);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun795__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun795(kk_function_t _fself, kk_box_t _b_x164, kk_box_t _b_x165, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun795(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun795, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun795(kk_function_t _fself, kk_box_t _b_x164, kk_box_t _b_x165, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x796;
  kk_src_ring__buffer__buffer_state _x_x797 = kk_src_ring__buffer__buffer_state_unbox(_b_x164, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x798 = kk_src_ring__buffer__buffer_config_unbox(_b_x165, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  _x_x796 = kk_src_ring__buffer_try_write(_x_x797, _x_x798, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
  return kk_std_core_types__maybe_box(_x_x796, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun821__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun821(kk_function_t _fself, kk_box_t _b_x170, kk_box_t _b_x171, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun821(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun821, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun821(kk_function_t _fself, kk_box_t _b_x170, kk_box_t _b_x171, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x822;
  kk_src_ring__buffer__buffer_state _x_x823 = kk_src_ring__buffer__buffer_state_unbox(_b_x170, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x824 = kk_src_ring__buffer__buffer_config_unbox(_b_x171, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  _x_x822 = kk_src_ring__buffer_try_read(_x_x823, _x_x824, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
  return kk_std_core_types__maybe_box(_x_x822, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun840__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun840(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun840(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun840, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun840(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x841;
  kk_string_t _x_x842 = kk_string_unbox(_b_x175); /*string*/
  _x_x841 = kk_src_ring__buffer_extract_count(_x_x842, _ctx); /*int*/
  return kk_integer_box(_x_x841, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun846__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun846(kk_function_t _fself, kk_box_t _b_x182, kk_box_t _b_x183, kk_box_t _b_x184, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun846(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun846, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun846(kk_function_t _fself, kk_box_t _b_x182, kk_box_t _b_x183, kk_box_t _b_x184, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x847;
  kk_src_ring__buffer__buffer_state _x_x848 = kk_src_ring__buffer__buffer_state_unbox(_b_x182, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x849 = kk_src_ring__buffer__buffer_config_unbox(_b_x183, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  kk_integer_t _x_x850 = kk_integer_unbox(_b_x184, _ctx); /*int*/
  _x_x847 = kk_src_ring__buffer_write_batch(_x_x848, _x_x849, _x_x850, _ctx); /*(int, src/ring_buffer/buffer-state)*/
  return kk_std_core_types__tuple2_box(_x_x847, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun870__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun870(kk_function_t _fself, kk_box_t _b_x189, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun870(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun870, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun870(kk_function_t _fself, kk_box_t _b_x189, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x871;
  kk_string_t _x_x872 = kk_string_unbox(_b_x189); /*string*/
  _x_x871 = kk_src_ring__buffer_extract_count(_x_x872, _ctx); /*int*/
  return kk_integer_box(_x_x871, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun876__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun876(kk_function_t _fself, kk_box_t _b_x196, kk_box_t _b_x197, kk_box_t _b_x198, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun876(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun876, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun876(kk_function_t _fself, kk_box_t _b_x196, kk_box_t _b_x197, kk_box_t _b_x198, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x877;
  kk_src_ring__buffer__buffer_state _x_x878 = kk_src_ring__buffer__buffer_state_unbox(_b_x196, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x879 = kk_src_ring__buffer__buffer_config_unbox(_b_x197, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  kk_integer_t _x_x880 = kk_integer_unbox(_b_x198, _ctx); /*int*/
  _x_x877 = kk_src_ring__buffer_read_batch(_x_x878, _x_x879, _x_x880, _ctx); /*(int, src/ring_buffer/buffer-state)*/
  return kk_std_core_types__tuple2_box(_x_x877, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun900__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun900(kk_function_t _fself, kk_box_t _b_x204, kk_box_t _b_x205, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun900(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun900, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun900(kk_function_t _fself, kk_box_t _b_x204, kk_box_t _b_x205, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x901;
  kk_src_ring__buffer__buffer_state _x_x902 = kk_src_ring__buffer__buffer_state_unbox(_b_x204, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x903 = kk_src_ring__buffer__buffer_config_unbox(_b_x205, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  _x_x901 = kk_src_ring__buffer_buffer_stats(_x_x902, _x_x903, _ctx); /*string*/
  return kk_string_box(_x_x901);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun911__t {
  struct kk_function_s _base;
  kk_src_ring__buffer__buffer_config config_2;
  kk_string_t op_1;
  kk_src_ring__buffer__buffer_state state_1;
  kk_string_t x_3_10275;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun911(kk_function_t _fself, kk_box_t _b_x224, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun911(kk_src_ring__buffer__buffer_config config_2, kk_string_t op_1, kk_src_ring__buffer__buffer_state state_1, kk_string_t x_3_10275, kk_context_t* _ctx) {
  struct kk_src_ring__buffer_server_loop_fun911__t* _self = kk_function_alloc_as(struct kk_src_ring__buffer_server_loop_fun911__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_ring__buffer_server_loop_fun911, kk_context());
  _self->config_2 = config_2;
  _self->op_1 = op_1;
  _self->state_1 = state_1;
  _self->x_3_10275 = x_3_10275;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun911(kk_function_t _fself, kk_box_t _b_x224, kk_context_t* _ctx) {
  struct kk_src_ring__buffer_server_loop_fun911__t* _self = kk_function_as(struct kk_src_ring__buffer_server_loop_fun911__t*, _fself, _ctx);
  kk_src_ring__buffer__buffer_config config_2 = _self->config_2; /* src/ring_buffer/buffer-config */
  kk_string_t op_1 = _self->op_1; /* string */
  kk_src_ring__buffer__buffer_state state_1 = _self->state_1; /* src/ring_buffer/buffer-state */
  kk_string_t x_3_10275 = _self->x_3_10275; /* string */
  kk_drop_match(_self, {kk_src_ring__buffer__buffer_config_dup(config_2, _ctx);kk_string_dup(op_1, _ctx);kk_src_ring__buffer__buffer_state_dup(state_1, _ctx);kk_string_dup(x_3_10275, _ctx);}, {}, _ctx)
  kk_string_t _c_x10203_1_285 = kk_string_unbox(_b_x224); /*string*/;
  kk_unit_t _x_x912 = kk_Unit;
  kk_src_ring__buffer__mlift_server_loop_10265(config_2, x_3_10275, op_1, state_1, _c_x10203_1_285, _ctx);
  return kk_unit_box(_x_x912);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun915__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun915(kk_function_t _fself, kk_box_t _b_x228, kk_box_t _b_x229, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun915(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun915, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun915(kk_function_t _fself, kk_box_t _b_x228, kk_box_t _b_x229, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x916;
  kk_src_ring__buffer__buffer_state _x_x917 = kk_src_ring__buffer__buffer_state_unbox(_b_x228, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x918 = kk_src_ring__buffer__buffer_config_unbox(_b_x229, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  _x_x916 = kk_src_ring__buffer_try_write(_x_x917, _x_x918, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
  return kk_std_core_types__maybe_box(_x_x916, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun925__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun925(kk_function_t _fself, kk_box_t _b_x234, kk_box_t _b_x235, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun925(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun925, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun925(kk_function_t _fself, kk_box_t _b_x234, kk_box_t _b_x235, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x926;
  kk_src_ring__buffer__buffer_state _x_x927 = kk_src_ring__buffer__buffer_state_unbox(_b_x234, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x928 = kk_src_ring__buffer__buffer_config_unbox(_b_x235, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  _x_x926 = kk_src_ring__buffer_try_read(_x_x927, _x_x928, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
  return kk_std_core_types__maybe_box(_x_x926, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun935__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun935(kk_function_t _fself, kk_box_t _b_x239, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun935(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun935, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun935(kk_function_t _fself, kk_box_t _b_x239, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x936;
  kk_string_t _x_x937 = kk_string_unbox(_b_x239); /*string*/
  _x_x936 = kk_src_ring__buffer_extract_count(_x_x937, _ctx); /*int*/
  return kk_integer_box(_x_x936, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun939__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun939(kk_function_t _fself, kk_box_t _b_x246, kk_box_t _b_x247, kk_box_t _b_x248, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun939(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun939, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun939(kk_function_t _fself, kk_box_t _b_x246, kk_box_t _b_x247, kk_box_t _b_x248, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x940;
  kk_src_ring__buffer__buffer_state _x_x941 = kk_src_ring__buffer__buffer_state_unbox(_b_x246, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x942 = kk_src_ring__buffer__buffer_config_unbox(_b_x247, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  kk_integer_t _x_x943 = kk_integer_unbox(_b_x248, _ctx); /*int*/
  _x_x940 = kk_src_ring__buffer_write_batch(_x_x941, _x_x942, _x_x943, _ctx); /*(int, src/ring_buffer/buffer-state)*/
  return kk_std_core_types__tuple2_box(_x_x940, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun948__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun948(kk_function_t _fself, kk_box_t _b_x253, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun948(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun948, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun948(kk_function_t _fself, kk_box_t _b_x253, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x949;
  kk_string_t _x_x950 = kk_string_unbox(_b_x253); /*string*/
  _x_x949 = kk_src_ring__buffer_extract_count(_x_x950, _ctx); /*int*/
  return kk_integer_box(_x_x949, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun952__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun952(kk_function_t _fself, kk_box_t _b_x260, kk_box_t _b_x261, kk_box_t _b_x262, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun952(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_ring__buffer_server_loop_fun952, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun952(kk_function_t _fself, kk_box_t _b_x260, kk_box_t _b_x261, kk_box_t _b_x262, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _x_x953;
  kk_src_ring__buffer__buffer_state _x_x954 = kk_src_ring__buffer__buffer_state_unbox(_b_x260, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x955 = kk_src_ring__buffer__buffer_config_unbox(_b_x261, KK_OWNED, _ctx); /*src/ring_buffer/buffer-config*/
  kk_integer_t _x_x956 = kk_integer_unbox(_b_x262, _ctx); /*int*/
  _x_x953 = kk_src_ring__buffer_read_batch(_x_x954, _x_x955, _x_x956, _ctx); /*(int, src/ring_buffer/buffer-state)*/
  return kk_std_core_types__tuple2_box(_x_x953, _ctx);
}


// lift anonymous function
struct kk_src_ring__buffer_server_loop_fun962__t {
  struct kk_function_s _base;
  kk_src_ring__buffer__buffer_config config_2;
};
static kk_box_t kk_src_ring__buffer_server_loop_fun962(kk_function_t _fself, kk_box_t _b_x280, kk_context_t* _ctx);
static kk_function_t kk_src_ring__buffer_new_server_loop_fun962(kk_src_ring__buffer__buffer_config config_2, kk_context_t* _ctx) {
  struct kk_src_ring__buffer_server_loop_fun962__t* _self = kk_function_alloc_as(struct kk_src_ring__buffer_server_loop_fun962__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_ring__buffer_server_loop_fun962, kk_context());
  _self->config_2 = config_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_ring__buffer_server_loop_fun962(kk_function_t _fself, kk_box_t _b_x280, kk_context_t* _ctx) {
  struct kk_src_ring__buffer_server_loop_fun962__t* _self = kk_function_as(struct kk_src_ring__buffer_server_loop_fun962__t*, _fself, _ctx);
  kk_src_ring__buffer__buffer_config config_2 = _self->config_2; /* src/ring_buffer/buffer-config */
  kk_drop_match(_self, {kk_src_ring__buffer__buffer_config_dup(config_2, _ctx);}, {}, _ctx)
  kk_src_ring__buffer__buffer_state _c_x10204_1_286 = kk_src_ring__buffer__buffer_state_unbox(_b_x280, KK_OWNED, _ctx); /*src/ring_buffer/buffer-state*/;
  kk_unit_t _x_x963 = kk_Unit;
  kk_src_ring__buffer__mlift_server_loop_10264(config_2, _c_x10204_1_286, _ctx);
  return kk_unit_box(_x_x963);
}

kk_unit_t kk_src_ring__buffer_server_loop(kk_src_ring__buffer__buffer_state state_1, kk_src_ring__buffer__buffer_config config_2, kk_context_t* _ctx) { /* (state : buffer-state, config : buffer-config) -> io () */ 
  kk__tailcall: ;
  kk_string_t x_3_10275 = kk_std_os_readline_readline(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_3_10275, _ctx);
    kk_box_t _x_x776 = kk_std_core_hnd_yield_extend(kk_src_ring__buffer_new_server_loop_fun777(config_2, state_1, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x776); return kk_Unit;
  }
  {
    bool _match_x288;
    kk_string_t _x_x779 = kk_string_dup(x_3_10275, _ctx); /*string*/
    kk_string_t _x_x780 = kk_string_empty(); /*string*/
    _match_x288 = kk_string_is_eq(_x_x779,_x_x780,kk_context()); /*bool*/
    if (_match_x288) {
      kk_string_drop(x_3_10275, _ctx);
      kk_datatype_ptr_dropn(state_1, (KK_I32(3)), _ctx);
      kk_datatype_ptr_dropn(config_2, (KK_I32(3)), _ctx);
      kk_Unit; return kk_Unit;
    }
    {
      bool _match_x289;
      kk_string_t _x_x782 = kk_string_dup(x_3_10275, _ctx); /*string*/
      kk_string_t _x_x783;
      kk_define_string_literal(, _s_x784, 6, "\"quit\"", _ctx)
      _x_x783 = kk_string_dup(_s_x784, _ctx); /*string*/
      _match_x289 = kk_string_contains(_x_x782,_x_x783,kk_context()); /*bool*/
      if (_match_x289) {
        kk_string_drop(x_3_10275, _ctx);
        kk_datatype_ptr_dropn(state_1, (KK_I32(3)), _ctx);
        kk_datatype_ptr_dropn(config_2, (KK_I32(3)), _ctx);
        kk_string_t _x_x785;
        kk_define_string_literal(, _s_x786, 20, "{\"status\":\"stopped\"}", _ctx)
        _x_x785 = kk_string_dup(_s_x786, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x785, _ctx); return kk_Unit;
      }
      {
        kk_string_t op_1;
        kk_box_t _x_x787;
        kk_box_t _x_x791;
        kk_string_t _x_x792 = kk_string_dup(x_3_10275, _ctx); /*string*/
        _x_x791 = kk_string_box(_x_x792); /*10000*/
        _x_x787 = kk_std_core_hnd__open_none1(kk_src_ring__buffer_new_server_loop_fun788(_ctx), _x_x791, _ctx); /*10001*/
        op_1 = kk_string_unbox(_x_x787); /*string*/
        kk_string_t x_4_10278;
        if (kk_string_cmp_cstr_borrow(op_1, "write", _ctx) == 0) {
          kk_std_core_types__maybe _match_x299;
          kk_box_t _x_x794;
          kk_box_t _x_x799;
          kk_src_ring__buffer__buffer_state _x_x800 = kk_src_ring__buffer__buffer_state_dup(state_1, _ctx); /*src/ring_buffer/buffer-state*/
          _x_x799 = kk_src_ring__buffer__buffer_state_box(_x_x800, _ctx); /*10000*/
          kk_box_t _x_x801;
          kk_src_ring__buffer__buffer_config _x_x802 = kk_src_ring__buffer__buffer_config_dup(config_2, _ctx); /*src/ring_buffer/buffer-config*/
          _x_x801 = kk_src_ring__buffer__buffer_config_box(_x_x802, _ctx); /*10001*/
          _x_x794 = kk_std_core_hnd__open_none2(kk_src_ring__buffer_new_server_loop_fun795(_ctx), _x_x799, _x_x801, _ctx); /*10002*/
          _match_x299 = kk_std_core_types__maybe_unbox(_x_x794, KK_OWNED, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
          if (kk_std_core_types__is_Nothing(_match_x299, _ctx)) {
            kk_evv_t w_4 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_4 = kk_Unit;
            kk_evv_set(w_4,kk_context());
            kk_string_t _x_x803;
            kk_define_string_literal(, _s_x804, 31, "{\"error\":\"buffer_full\",\"count\":", _ctx)
            _x_x803 = kk_string_dup(_s_x804, _ctx); /*string*/
            kk_string_t _x_x805;
            kk_string_t _x_x806;
            kk_integer_t _x_x807;
            {
              struct kk_src_ring__buffer_Buffer_state* _con_x808 = kk_src_ring__buffer__as_Buffer_state(state_1, _ctx);
              kk_integer_t _x_2 = _con_x808->count;
              kk_integer_dup(_x_2, _ctx);
              _x_x807 = _x_2; /*int*/
            }
            _x_x806 = kk_std_core_int_show(_x_x807, _ctx); /*string*/
            kk_string_t _x_x809;
            kk_define_string_literal(, _s_x810, 1, "}", _ctx)
            _x_x809 = kk_string_dup(_s_x810, _ctx); /*string*/
            _x_x805 = kk_std_core_types__lp__plus__plus__rp_(_x_x806, _x_x809, _ctx); /*string*/
            x_4_10278 = kk_std_core_types__lp__plus__plus__rp_(_x_x803, _x_x805, _ctx); /*string*/
            goto _match_x793;
          }
          {
            kk_box_t _box_x166 = _match_x299._cons.Just.value;
            kk_src_ring__buffer__buffer_state new_state_3 = kk_src_ring__buffer__buffer_state_unbox(_box_x166, KK_BORROWED, _ctx);
            struct kk_src_ring__buffer_Buffer_state* _con_x811 = kk_src_ring__buffer__as_Buffer_state(new_state_3, _ctx);
            kk_src_ring__buffer__buffer_state_dup(new_state_3, _ctx);
            kk_std_core_types__maybe_drop(_match_x299, _ctx);
            kk_evv_t w_5 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_5 = kk_Unit;
            kk_evv_set(w_5,kk_context());
            kk_string_t _x_x812;
            kk_define_string_literal(, _s_x813, 28, "{\"written\":true,\"write_pos\":", _ctx)
            _x_x812 = kk_string_dup(_s_x813, _ctx); /*string*/
            kk_string_t _x_x814;
            kk_string_t _x_x815;
            kk_integer_t _x_x816;
            {
              struct kk_src_ring__buffer_Buffer_state* _con_x817 = kk_src_ring__buffer__as_Buffer_state(new_state_3, _ctx);
              kk_integer_t _x_0_0 = _con_x817->write_pos;
              kk_integer_t _pat_0_1_1 = _con_x817->read_pos;
              kk_integer_t _pat_1_1_0 = _con_x817->count;
              if kk_likely(kk_datatype_ptr_is_unique(new_state_3, _ctx)) {
                kk_integer_drop(_pat_1_1_0, _ctx);
                kk_integer_drop(_pat_0_1_1, _ctx);
                kk_datatype_ptr_free(new_state_3, _ctx);
              }
              else {
                kk_integer_dup(_x_0_0, _ctx);
                kk_datatype_ptr_decref(new_state_3, _ctx);
              }
              _x_x816 = _x_0_0; /*int*/
            }
            _x_x815 = kk_std_core_int_show(_x_x816, _ctx); /*string*/
            kk_string_t _x_x818;
            kk_define_string_literal(, _s_x819, 1, "}", _ctx)
            _x_x818 = kk_string_dup(_s_x819, _ctx); /*string*/
            _x_x814 = kk_std_core_types__lp__plus__plus__rp_(_x_x815, _x_x818, _ctx); /*string*/
            x_4_10278 = kk_std_core_types__lp__plus__plus__rp_(_x_x812, _x_x814, _ctx); /*string*/
            goto _match_x793;
          }
        }
        if (kk_string_cmp_cstr_borrow(op_1, "read", _ctx) == 0) {
          kk_std_core_types__maybe _match_x298;
          kk_box_t _x_x820;
          kk_box_t _x_x825;
          kk_src_ring__buffer__buffer_state _x_x826 = kk_src_ring__buffer__buffer_state_dup(state_1, _ctx); /*src/ring_buffer/buffer-state*/
          _x_x825 = kk_src_ring__buffer__buffer_state_box(_x_x826, _ctx); /*10000*/
          kk_box_t _x_x827;
          kk_src_ring__buffer__buffer_config _x_x828 = kk_src_ring__buffer__buffer_config_dup(config_2, _ctx); /*src/ring_buffer/buffer-config*/
          _x_x827 = kk_src_ring__buffer__buffer_config_box(_x_x828, _ctx); /*10001*/
          _x_x820 = kk_std_core_hnd__open_none2(kk_src_ring__buffer_new_server_loop_fun821(_ctx), _x_x825, _x_x827, _ctx); /*10002*/
          _match_x298 = kk_std_core_types__maybe_unbox(_x_x820, KK_OWNED, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
          if (kk_std_core_types__is_Nothing(_match_x298, _ctx)) {
            kk_define_string_literal(, _s_x829, 24, "{\"error\":\"buffer_empty\"}", _ctx)
            x_4_10278 = kk_string_dup(_s_x829, _ctx); /*string*/
            goto _match_x793;
          }
          {
            kk_box_t _box_x172 = _match_x298._cons.Just.value;
            kk_src_ring__buffer__buffer_state new_state_0_0 = kk_src_ring__buffer__buffer_state_unbox(_box_x172, KK_BORROWED, _ctx);
            struct kk_src_ring__buffer_Buffer_state* _con_x830 = kk_src_ring__buffer__as_Buffer_state(new_state_0_0, _ctx);
            kk_src_ring__buffer__buffer_state_dup(new_state_0_0, _ctx);
            kk_std_core_types__maybe_drop(_match_x298, _ctx);
            kk_evv_t w_6 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_6 = kk_Unit;
            kk_evv_set(w_6,kk_context());
            kk_string_t _x_x831;
            kk_define_string_literal(, _s_x832, 24, "{\"read\":true,\"read_pos\":", _ctx)
            _x_x831 = kk_string_dup(_s_x832, _ctx); /*string*/
            kk_string_t _x_x833;
            kk_string_t _x_x834;
            kk_integer_t _x_x835;
            {
              struct kk_src_ring__buffer_Buffer_state* _con_x836 = kk_src_ring__buffer__as_Buffer_state(new_state_0_0, _ctx);
              kk_integer_t _pat_0_2_0 = _con_x836->write_pos;
              kk_integer_t _x_1_0 = _con_x836->read_pos;
              kk_integer_t _pat_1_2_0 = _con_x836->count;
              if kk_likely(kk_datatype_ptr_is_unique(new_state_0_0, _ctx)) {
                kk_integer_drop(_pat_1_2_0, _ctx);
                kk_integer_drop(_pat_0_2_0, _ctx);
                kk_datatype_ptr_free(new_state_0_0, _ctx);
              }
              else {
                kk_integer_dup(_x_1_0, _ctx);
                kk_datatype_ptr_decref(new_state_0_0, _ctx);
              }
              _x_x835 = _x_1_0; /*int*/
            }
            _x_x834 = kk_std_core_int_show(_x_x835, _ctx); /*string*/
            kk_string_t _x_x837;
            kk_define_string_literal(, _s_x838, 1, "}", _ctx)
            _x_x837 = kk_string_dup(_s_x838, _ctx); /*string*/
            _x_x833 = kk_std_core_types__lp__plus__plus__rp_(_x_x834, _x_x837, _ctx); /*string*/
            x_4_10278 = kk_std_core_types__lp__plus__plus__rp_(_x_x831, _x_x833, _ctx); /*string*/
            goto _match_x793;
          }
        }
        if (kk_string_cmp_cstr_borrow(op_1, "batch_write", _ctx) == 0) {
          kk_integer_t n_3;
          kk_box_t _x_x839;
          kk_box_t _x_x843;
          kk_string_t _x_x844 = kk_string_dup(x_3_10275, _ctx); /*string*/
          _x_x843 = kk_string_box(_x_x844); /*10000*/
          _x_x839 = kk_std_core_hnd__open_none1(kk_src_ring__buffer_new_server_loop_fun840(_ctx), _x_x843, _ctx); /*10001*/
          n_3 = kk_integer_unbox(_x_x839, _ctx); /*int*/
          kk_std_core_types__tuple2 _match_x297;
          kk_box_t _x_x845;
          kk_box_t _x_x851;
          kk_src_ring__buffer__buffer_state _x_x852 = kk_src_ring__buffer__buffer_state_dup(state_1, _ctx); /*src/ring_buffer/buffer-state*/
          _x_x851 = kk_src_ring__buffer__buffer_state_box(_x_x852, _ctx); /*10000*/
          kk_box_t _x_x853;
          kk_src_ring__buffer__buffer_config _x_x854 = kk_src_ring__buffer__buffer_config_dup(config_2, _ctx); /*src/ring_buffer/buffer-config*/
          _x_x853 = kk_src_ring__buffer__buffer_config_box(_x_x854, _ctx); /*10001*/
          kk_box_t _x_x855;
          kk_integer_t _x_x856 = kk_integer_dup(n_3, _ctx); /*int*/
          _x_x855 = kk_integer_box(_x_x856, _ctx); /*10002*/
          _x_x845 = kk_std_core_hnd__open_none3(kk_src_ring__buffer_new_server_loop_fun846(_ctx), _x_x851, _x_x853, _x_x855, _ctx); /*10003*/
          _match_x297 = kk_std_core_types__tuple2_unbox(_x_x845, KK_OWNED, _ctx); /*(int, src/ring_buffer/buffer-state)*/
          {
            kk_box_t _box_x185 = _match_x297.fst;
            kk_box_t _box_x186 = _match_x297.snd;
            kk_src_ring__buffer__buffer_state new_state_1_0 = kk_src_ring__buffer__buffer_state_unbox(_box_x186, KK_BORROWED, _ctx);
            struct kk_src_ring__buffer_Buffer_state* _con_x857 = kk_src_ring__buffer__as_Buffer_state(new_state_1_0, _ctx);
            kk_integer_t written_0 = kk_integer_unbox(_box_x185, _ctx);
            kk_integer_dup(written_0, _ctx);
            kk_std_core_types__tuple2_drop(_match_x297, _ctx);
            kk_string_t _x_x858;
            kk_define_string_literal(, _s_x859, 15, "{\"batch_write\":", _ctx)
            _x_x858 = kk_string_dup(_s_x859, _ctx); /*string*/
            kk_string_t _x_x860;
            kk_string_t _x_x861 = kk_std_core_int_show(written_0, _ctx); /*string*/
            kk_string_t _x_x862;
            kk_string_t _x_x863;
            kk_define_string_literal(, _s_x864, 13, ",\"requested\":", _ctx)
            _x_x863 = kk_string_dup(_s_x864, _ctx); /*string*/
            kk_string_t _x_x865;
            kk_string_t _x_x866 = kk_std_core_int_show(n_3, _ctx); /*string*/
            kk_string_t _x_x867;
            kk_define_string_literal(, _s_x868, 1, "}", _ctx)
            _x_x867 = kk_string_dup(_s_x868, _ctx); /*string*/
            _x_x865 = kk_std_core_types__lp__plus__plus__rp_(_x_x866, _x_x867, _ctx); /*string*/
            _x_x862 = kk_std_core_types__lp__plus__plus__rp_(_x_x863, _x_x865, _ctx); /*string*/
            _x_x860 = kk_std_core_types__lp__plus__plus__rp_(_x_x861, _x_x862, _ctx); /*string*/
            x_4_10278 = kk_std_core_types__lp__plus__plus__rp_(_x_x858, _x_x860, _ctx); /*string*/
            goto _match_x793;
          }
        }
        if (kk_string_cmp_cstr_borrow(op_1, "batch_read", _ctx) == 0) {
          kk_integer_t n_0_0;
          kk_box_t _x_x869;
          kk_box_t _x_x873;
          kk_string_t _x_x874 = kk_string_dup(x_3_10275, _ctx); /*string*/
          _x_x873 = kk_string_box(_x_x874); /*10000*/
          _x_x869 = kk_std_core_hnd__open_none1(kk_src_ring__buffer_new_server_loop_fun870(_ctx), _x_x873, _ctx); /*10001*/
          n_0_0 = kk_integer_unbox(_x_x869, _ctx); /*int*/
          kk_std_core_types__tuple2 _match_x296;
          kk_box_t _x_x875;
          kk_box_t _x_x881;
          kk_src_ring__buffer__buffer_state _x_x882 = kk_src_ring__buffer__buffer_state_dup(state_1, _ctx); /*src/ring_buffer/buffer-state*/
          _x_x881 = kk_src_ring__buffer__buffer_state_box(_x_x882, _ctx); /*10000*/
          kk_box_t _x_x883;
          kk_src_ring__buffer__buffer_config _x_x884 = kk_src_ring__buffer__buffer_config_dup(config_2, _ctx); /*src/ring_buffer/buffer-config*/
          _x_x883 = kk_src_ring__buffer__buffer_config_box(_x_x884, _ctx); /*10001*/
          kk_box_t _x_x885;
          kk_integer_t _x_x886 = kk_integer_dup(n_0_0, _ctx); /*int*/
          _x_x885 = kk_integer_box(_x_x886, _ctx); /*10002*/
          _x_x875 = kk_std_core_hnd__open_none3(kk_src_ring__buffer_new_server_loop_fun876(_ctx), _x_x881, _x_x883, _x_x885, _ctx); /*10003*/
          _match_x296 = kk_std_core_types__tuple2_unbox(_x_x875, KK_OWNED, _ctx); /*(int, src/ring_buffer/buffer-state)*/
          {
            kk_box_t _box_x199 = _match_x296.fst;
            kk_box_t _box_x200 = _match_x296.snd;
            kk_src_ring__buffer__buffer_state new_state_2_0 = kk_src_ring__buffer__buffer_state_unbox(_box_x200, KK_BORROWED, _ctx);
            struct kk_src_ring__buffer_Buffer_state* _con_x887 = kk_src_ring__buffer__as_Buffer_state(new_state_2_0, _ctx);
            kk_integer_t read_0 = kk_integer_unbox(_box_x199, _ctx);
            kk_integer_dup(read_0, _ctx);
            kk_std_core_types__tuple2_drop(_match_x296, _ctx);
            kk_string_t _x_x888;
            kk_define_string_literal(, _s_x889, 14, "{\"batch_read\":", _ctx)
            _x_x888 = kk_string_dup(_s_x889, _ctx); /*string*/
            kk_string_t _x_x890;
            kk_string_t _x_x891 = kk_std_core_int_show(read_0, _ctx); /*string*/
            kk_string_t _x_x892;
            kk_string_t _x_x893;
            kk_define_string_literal(, _s_x894, 13, ",\"requested\":", _ctx)
            _x_x893 = kk_string_dup(_s_x894, _ctx); /*string*/
            kk_string_t _x_x895;
            kk_string_t _x_x896 = kk_std_core_int_show(n_0_0, _ctx); /*string*/
            kk_string_t _x_x897;
            kk_define_string_literal(, _s_x898, 1, "}", _ctx)
            _x_x897 = kk_string_dup(_s_x898, _ctx); /*string*/
            _x_x895 = kk_std_core_types__lp__plus__plus__rp_(_x_x896, _x_x897, _ctx); /*string*/
            _x_x892 = kk_std_core_types__lp__plus__plus__rp_(_x_x893, _x_x895, _ctx); /*string*/
            _x_x890 = kk_std_core_types__lp__plus__plus__rp_(_x_x891, _x_x892, _ctx); /*string*/
            x_4_10278 = kk_std_core_types__lp__plus__plus__rp_(_x_x888, _x_x890, _ctx); /*string*/
            goto _match_x793;
          }
        }
        if (kk_string_cmp_cstr_borrow(op_1, "stats", _ctx) == 0) {
          kk_box_t _x_x899;
          kk_box_t _x_x904;
          kk_src_ring__buffer__buffer_state _x_x905 = kk_src_ring__buffer__buffer_state_dup(state_1, _ctx); /*src/ring_buffer/buffer-state*/
          _x_x904 = kk_src_ring__buffer__buffer_state_box(_x_x905, _ctx); /*10000*/
          kk_box_t _x_x906;
          kk_src_ring__buffer__buffer_config _x_x907 = kk_src_ring__buffer__buffer_config_dup(config_2, _ctx); /*src/ring_buffer/buffer-config*/
          _x_x906 = kk_src_ring__buffer__buffer_config_box(_x_x907, _ctx); /*10001*/
          _x_x899 = kk_std_core_hnd__open_none2(kk_src_ring__buffer_new_server_loop_fun900(_ctx), _x_x904, _x_x906, _ctx); /*10002*/
          x_4_10278 = kk_string_unbox(_x_x899); /*string*/
          goto _match_x793;
        }
        if (kk_string_cmp_cstr_borrow(op_1, "reset", _ctx) == 0) {
          kk_define_string_literal(, _s_x908, 14, "{\"reset\":true}", _ctx)
          x_4_10278 = kk_string_dup(_s_x908, _ctx); /*string*/
          goto _match_x793;
        }
        {
          kk_define_string_literal(, _s_x909, 22, "{\"error\":\"unknown op\"}", _ctx)
          x_4_10278 = kk_string_dup(_s_x909, _ctx); /*string*/
        }
        _match_x793: ;
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_4_10278, _ctx);
          kk_box_t _x_x910 = kk_std_core_hnd_yield_extend(kk_src_ring__buffer_new_server_loop_fun911(config_2, op_1, state_1, x_3_10275, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x910); return kk_Unit;
        }
        {
          kk_unit_t ___0 = kk_Unit;
          kk_std_core_console_printsln(x_4_10278, _ctx);
          kk_src_ring__buffer__buffer_state x_5_10281;
          if (kk_string_cmp_cstr_borrow(op_1, "write", _ctx) == 0) {
            kk_string_drop(x_3_10275, _ctx);
            kk_string_drop(op_1, _ctx);
            kk_std_core_types__maybe _match_x295;
            kk_box_t _x_x914;
            kk_box_t _x_x919;
            kk_src_ring__buffer__buffer_state _x_x920 = kk_src_ring__buffer__buffer_state_dup(state_1, _ctx); /*src/ring_buffer/buffer-state*/
            _x_x919 = kk_src_ring__buffer__buffer_state_box(_x_x920, _ctx); /*10000*/
            kk_box_t _x_x921;
            kk_src_ring__buffer__buffer_config _x_x922 = kk_src_ring__buffer__buffer_config_dup(config_2, _ctx); /*src/ring_buffer/buffer-config*/
            _x_x921 = kk_src_ring__buffer__buffer_config_box(_x_x922, _ctx); /*10001*/
            _x_x914 = kk_std_core_hnd__open_none2(kk_src_ring__buffer_new_server_loop_fun915(_ctx), _x_x919, _x_x921, _ctx); /*10002*/
            _match_x295 = kk_std_core_types__maybe_unbox(_x_x914, KK_OWNED, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
            if (kk_std_core_types__is_Nothing(_match_x295, _ctx)) {
              x_5_10281 = state_1; /*src/ring_buffer/buffer-state*/
              goto _match_x913;
            }
            {
              kk_box_t _box_x230 = _match_x295._cons.Just.value;
              kk_src_ring__buffer__buffer_state s_1_1 = kk_src_ring__buffer__buffer_state_unbox(_box_x230, KK_BORROWED, _ctx);
              struct kk_src_ring__buffer_Buffer_state* _con_x923 = kk_src_ring__buffer__as_Buffer_state(s_1_1, _ctx);
              kk_datatype_ptr_dropn(state_1, (KK_I32(3)), _ctx);
              kk_src_ring__buffer__buffer_state_dup(s_1_1, _ctx);
              kk_std_core_types__maybe_drop(_match_x295, _ctx);
              x_5_10281 = s_1_1; /*src/ring_buffer/buffer-state*/
              goto _match_x913;
            }
          }
          if (kk_string_cmp_cstr_borrow(op_1, "read", _ctx) == 0) {
            kk_string_drop(x_3_10275, _ctx);
            kk_string_drop(op_1, _ctx);
            kk_std_core_types__maybe _match_x294;
            kk_box_t _x_x924;
            kk_box_t _x_x929;
            kk_src_ring__buffer__buffer_state _x_x930 = kk_src_ring__buffer__buffer_state_dup(state_1, _ctx); /*src/ring_buffer/buffer-state*/
            _x_x929 = kk_src_ring__buffer__buffer_state_box(_x_x930, _ctx); /*10000*/
            kk_box_t _x_x931;
            kk_src_ring__buffer__buffer_config _x_x932 = kk_src_ring__buffer__buffer_config_dup(config_2, _ctx); /*src/ring_buffer/buffer-config*/
            _x_x931 = kk_src_ring__buffer__buffer_config_box(_x_x932, _ctx); /*10001*/
            _x_x924 = kk_std_core_hnd__open_none2(kk_src_ring__buffer_new_server_loop_fun925(_ctx), _x_x929, _x_x931, _ctx); /*10002*/
            _match_x294 = kk_std_core_types__maybe_unbox(_x_x924, KK_OWNED, _ctx); /*maybe<src/ring_buffer/buffer-state>*/
            if (kk_std_core_types__is_Nothing(_match_x294, _ctx)) {
              x_5_10281 = state_1; /*src/ring_buffer/buffer-state*/
              goto _match_x913;
            }
            {
              kk_box_t _box_x236 = _match_x294._cons.Just.value;
              kk_src_ring__buffer__buffer_state s_0_0_0 = kk_src_ring__buffer__buffer_state_unbox(_box_x236, KK_BORROWED, _ctx);
              struct kk_src_ring__buffer_Buffer_state* _con_x933 = kk_src_ring__buffer__as_Buffer_state(s_0_0_0, _ctx);
              kk_datatype_ptr_dropn(state_1, (KK_I32(3)), _ctx);
              kk_src_ring__buffer__buffer_state_dup(s_0_0_0, _ctx);
              kk_std_core_types__maybe_drop(_match_x294, _ctx);
              x_5_10281 = s_0_0_0; /*src/ring_buffer/buffer-state*/
              goto _match_x913;
            }
          }
          if (kk_string_cmp_cstr_borrow(op_1, "batch_write", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_integer_t n_1_0;
            kk_box_t _x_x934 = kk_std_core_hnd__open_none1(kk_src_ring__buffer_new_server_loop_fun935(_ctx), kk_string_box(x_3_10275), _ctx); /*10001*/
            n_1_0 = kk_integer_unbox(_x_x934, _ctx); /*int*/
            kk_std_core_types__tuple2 _match_x293;
            kk_box_t _x_x938;
            kk_box_t _x_x944;
            kk_src_ring__buffer__buffer_config _x_x945 = kk_src_ring__buffer__buffer_config_dup(config_2, _ctx); /*src/ring_buffer/buffer-config*/
            _x_x944 = kk_src_ring__buffer__buffer_config_box(_x_x945, _ctx); /*10001*/
            _x_x938 = kk_std_core_hnd__open_none3(kk_src_ring__buffer_new_server_loop_fun939(_ctx), kk_src_ring__buffer__buffer_state_box(state_1, _ctx), _x_x944, kk_integer_box(n_1_0, _ctx), _ctx); /*10003*/
            _match_x293 = kk_std_core_types__tuple2_unbox(_x_x938, KK_OWNED, _ctx); /*(int, src/ring_buffer/buffer-state)*/
            {
              kk_box_t _box_x249 = _match_x293.fst;
              kk_box_t _box_x250 = _match_x293.snd;
              kk_src_ring__buffer__buffer_state s_1_0_0 = kk_src_ring__buffer__buffer_state_unbox(_box_x250, KK_BORROWED, _ctx);
              struct kk_src_ring__buffer_Buffer_state* _con_x946 = kk_src_ring__buffer__as_Buffer_state(s_1_0_0, _ctx);
              kk_src_ring__buffer__buffer_state_dup(s_1_0_0, _ctx);
              kk_std_core_types__tuple2_drop(_match_x293, _ctx);
              x_5_10281 = s_1_0_0; /*src/ring_buffer/buffer-state*/
              goto _match_x913;
            }
          }
          if (kk_string_cmp_cstr_borrow(op_1, "batch_read", _ctx) == 0) {
            kk_string_drop(op_1, _ctx);
            kk_integer_t n_2_0;
            kk_box_t _x_x947 = kk_std_core_hnd__open_none1(kk_src_ring__buffer_new_server_loop_fun948(_ctx), kk_string_box(x_3_10275), _ctx); /*10001*/
            n_2_0 = kk_integer_unbox(_x_x947, _ctx); /*int*/
            kk_std_core_types__tuple2 _match_x292;
            kk_box_t _x_x951;
            kk_box_t _x_x957;
            kk_src_ring__buffer__buffer_config _x_x958 = kk_src_ring__buffer__buffer_config_dup(config_2, _ctx); /*src/ring_buffer/buffer-config*/
            _x_x957 = kk_src_ring__buffer__buffer_config_box(_x_x958, _ctx); /*10001*/
            _x_x951 = kk_std_core_hnd__open_none3(kk_src_ring__buffer_new_server_loop_fun952(_ctx), kk_src_ring__buffer__buffer_state_box(state_1, _ctx), _x_x957, kk_integer_box(n_2_0, _ctx), _ctx); /*10003*/
            _match_x292 = kk_std_core_types__tuple2_unbox(_x_x951, KK_OWNED, _ctx); /*(int, src/ring_buffer/buffer-state)*/
            {
              kk_box_t _box_x263 = _match_x292.fst;
              kk_box_t _box_x264 = _match_x292.snd;
              kk_src_ring__buffer__buffer_state s_2_0 = kk_src_ring__buffer__buffer_state_unbox(_box_x264, KK_BORROWED, _ctx);
              struct kk_src_ring__buffer_Buffer_state* _con_x959 = kk_src_ring__buffer__as_Buffer_state(s_2_0, _ctx);
              kk_src_ring__buffer__buffer_state_dup(s_2_0, _ctx);
              kk_std_core_types__tuple2_drop(_match_x292, _ctx);
              x_5_10281 = s_2_0; /*src/ring_buffer/buffer-state*/
              goto _match_x913;
            }
          }
          if (kk_string_cmp_cstr_borrow(op_1, "reset", _ctx) == 0) {
            kk_string_drop(x_3_10275, _ctx);
            kk_reuse_t _ru_x379 = kk_reuse_null; /*@reuse*/;
            kk_reuse_t _x_x960 = kk_datatype_ptr_dropn_reuse(state_1, (KK_I32(3)), _ctx); /*@reuse*/
            _ru_x379 = _x_x960;
            kk_string_drop(op_1, _ctx);
            kk_evv_t w_1_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            int64_t x_6_0 = (KK_I64(0)); /*int64*/;
            kk_unit_t keep_1_0 = kk_Unit;
            kk_evv_set(w_1_0,kk_context());
            kk_evv_t w_2_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            int64_t x_7 = (KK_I64(0)); /*int64*/;
            kk_unit_t keep_2_0 = kk_Unit;
            kk_evv_set(w_2_0,kk_context());
            x_5_10281 = kk_src_ring__buffer__new_Buffer_state(_ru_x379, 0, kk_integer_from_small(0), kk_integer_from_small(0), kk_integer_from_small(0), x_6_0, x_7, _ctx); /*src/ring_buffer/buffer-state*/
            goto _match_x913;
          }
          {
            kk_string_drop(x_3_10275, _ctx);
            kk_string_drop(op_1, _ctx);
            x_5_10281 = state_1; /*src/ring_buffer/buffer-state*/
          }
          _match_x913: ;
          if (kk_yielding(kk_context())) {
            kk_datatype_ptr_dropn(x_5_10281, (KK_I32(3)), _ctx);
            kk_box_t _x_x961 = kk_std_core_hnd_yield_extend(kk_src_ring__buffer_new_server_loop_fun962(config_2, _ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x961); return kk_Unit;
          }
          { // tailcall
            state_1 = x_5_10281;
            goto kk__tailcall;
          }
        }
      }
    }
  }
}

kk_unit_t kk_src_ring__buffer_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x964;
  kk_define_string_literal(, _s_x965, 126, "{\"status\":\"started\",\"ring_buffer\":true,\"version\":\"5.0\",\"features\":[\"lock_free\",\"multi_producer\",\"multi_consumer\",\"batch_ops\"]}", _ctx)
  _x_x964 = kk_string_dup(_s_x965, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x964, _ctx);
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  int64_t x = (KK_I64(0)); /*int64*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  int64_t x_0 = (KK_I64(0)); /*int64*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_src_ring__buffer__buffer_state _x_x966 = kk_src_ring__buffer__new_Buffer_state(kk_reuse_null, 0, kk_integer_from_small(0), kk_integer_from_small(0), kk_integer_from_small(0), x, x_0, _ctx); /*src/ring_buffer/buffer-state*/
  kk_src_ring__buffer__buffer_config _x_x967 = kk_src_ring__buffer__new_Buffer_config(kk_reuse_null, 0, kk_integer_from_small(1000), kk_integer_from_small(1544), kk_integer_from_small(64), _ctx); /*src/ring_buffer/buffer-config*/
  kk_src_ring__buffer_server_loop(_x_x966, _x_x967, _ctx); return kk_Unit;
}

// initialization
void kk_src_ring__buffer__init(kk_context_t* _ctx){
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
}

// termination
void kk_src_ring__buffer__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
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
