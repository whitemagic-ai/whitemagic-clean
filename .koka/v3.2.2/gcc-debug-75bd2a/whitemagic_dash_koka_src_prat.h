#pragma once
#ifndef kk_whitemagic_dash_koka_src_prat_H
#define kk_whitemagic_dash_koka_src_prat_H
// Koka generated module: whitemagic-koka/src/prat, koka version: 3.2.2, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"
#include "std_core_bool.h"
#include "std_core_order.h"
#include "std_core_char.h"
#include "std_core_int.h"
#include "std_core_vector.h"
#include "std_core_string.h"
#include "std_core_sslice.h"
#include "std_core_list.h"
#include "std_core_maybe.h"
#include "std_core_maybe2.h"
#include "std_core_either.h"
#include "std_core_tuple.h"
#include "std_core_lazy.h"
#include "std_core_show.h"
#include "std_core_debug.h"
#include "std_core_delayed.h"
#include "std_core_console.h"
#include "std_core.h"
#include "std_os_readline.h"
#include "std_num_float64.h"

// type declarations

// value type whitemagic-koka/src/prat/gana
enum kk_whitemagic_dash_koka_src_prat__gana_e {
  kk_whitemagic_dash_koka_src_prat_GanaHorn,
  kk_whitemagic_dash_koka_src_prat_GanaNeck,
  kk_whitemagic_dash_koka_src_prat_GanaRoot,
  kk_whitemagic_dash_koka_src_prat_GanaRoom,
  kk_whitemagic_dash_koka_src_prat_GanaHeart,
  kk_whitemagic_dash_koka_src_prat_GanaTail,
  kk_whitemagic_dash_koka_src_prat_GanaWinnowingBasket,
  kk_whitemagic_dash_koka_src_prat_GanaGhost,
  kk_whitemagic_dash_koka_src_prat_GanaWillow,
  kk_whitemagic_dash_koka_src_prat_GanaStar,
  kk_whitemagic_dash_koka_src_prat_GanaExtendedNet,
  kk_whitemagic_dash_koka_src_prat_GanaWings,
  kk_whitemagic_dash_koka_src_prat_GanaChariot,
  kk_whitemagic_dash_koka_src_prat_GanaAbundance,
  kk_whitemagic_dash_koka_src_prat_GanaStraddlingLegs,
  kk_whitemagic_dash_koka_src_prat_GanaMound,
  kk_whitemagic_dash_koka_src_prat_GanaStomach,
  kk_whitemagic_dash_koka_src_prat_GanaHairyHead,
  kk_whitemagic_dash_koka_src_prat_GanaNet,
  kk_whitemagic_dash_koka_src_prat_GanaTurtleBeak,
  kk_whitemagic_dash_koka_src_prat_GanaThreeStars,
  kk_whitemagic_dash_koka_src_prat_GanaDipper,
  kk_whitemagic_dash_koka_src_prat_GanaOx,
  kk_whitemagic_dash_koka_src_prat_GanaGirl,
  kk_whitemagic_dash_koka_src_prat_GanaVoid,
  kk_whitemagic_dash_koka_src_prat_GanaRoof,
  kk_whitemagic_dash_koka_src_prat_GanaEncampment,
  kk_whitemagic_dash_koka_src_prat_GanaWall
};
typedef uint8_t kk_whitemagic_dash_koka_src_prat__gana;

static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaHorn(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaHorn;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaNeck(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaNeck;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaRoot(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaRoot;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaRoom(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaRoom;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaHeart(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaHeart;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaTail(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaTail;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaWinnowingBasket(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaWinnowingBasket;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaGhost(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaGhost;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaWillow(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaWillow;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaStar(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaStar;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaExtendedNet(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaExtendedNet;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaWings(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaWings;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaChariot(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaChariot;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaAbundance(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaAbundance;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaStraddlingLegs(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaStraddlingLegs;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaMound(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaMound;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaStomach(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaStomach;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaHairyHead(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaHairyHead;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaNet(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaNet;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaTurtleBeak(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaTurtleBeak;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaThreeStars(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaThreeStars;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaDipper(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaDipper;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaOx(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaOx;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaGirl(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaGirl;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaVoid(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaVoid;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaRoof(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaRoof;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaEncampment(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaEncampment;
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__new_GanaWall(kk_context_t* _ctx) {
  return kk_whitemagic_dash_koka_src_prat_GanaWall;
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaHorn(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaHorn);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaNeck(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaNeck);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaRoot(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaRoot);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaRoom(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaRoom);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaHeart(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaHeart);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaTail(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaTail);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaWinnowingBasket(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaWinnowingBasket);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaGhost(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaGhost);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaWillow(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaWillow);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaStar(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaStar);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaExtendedNet(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaExtendedNet);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaWings(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaWings);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaChariot(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaChariot);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaAbundance(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaAbundance);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaStraddlingLegs(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaStraddlingLegs);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaMound(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaMound);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaStomach(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaStomach);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaHairyHead(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaHairyHead);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaNet(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaNet);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaTurtleBeak(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaTurtleBeak);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaThreeStars(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaThreeStars);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaDipper(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaDipper);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaOx(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaOx);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaGirl(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaGirl);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaVoid(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaVoid);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaRoof(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaRoof);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaEncampment(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaEncampment);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_GanaWall(kk_whitemagic_dash_koka_src_prat__gana x, kk_context_t* _ctx) {
  return (x == kk_whitemagic_dash_koka_src_prat_GanaWall);
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__gana_dup(kk_whitemagic_dash_koka_src_prat__gana _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_whitemagic_dash_koka_src_prat__gana_drop(kk_whitemagic_dash_koka_src_prat__gana _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_whitemagic_dash_koka_src_prat__gana_box(kk_whitemagic_dash_koka_src_prat__gana _x, kk_context_t* _ctx) {
  return kk_enum_box(_x);
}
static inline kk_whitemagic_dash_koka_src_prat__gana kk_whitemagic_dash_koka_src_prat__gana_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return (kk_whitemagic_dash_koka_src_prat__gana)kk_enum_unbox(_x);
}

// type whitemagic-koka/src/prat/prat-dispatch
struct kk_whitemagic_dash_koka_src_prat__prat_dispatch_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_whitemagic_dash_koka_src_prat__prat_dispatch;
struct kk_whitemagic_dash_koka_src_prat__Hnd_prat_dispatch {
  struct kk_whitemagic_dash_koka_src_prat__prat_dispatch_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause2 _fun_dispatch;
};
static inline kk_whitemagic_dash_koka_src_prat__prat_dispatch kk_whitemagic_dash_koka_src_prat__base_Hnd_prat_dispatch(struct kk_whitemagic_dash_koka_src_prat__Hnd_prat_dispatch* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_whitemagic_dash_koka_src_prat__prat_dispatch kk_whitemagic_dash_koka_src_prat__new_Hnd_prat_dispatch(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause2 _fun_dispatch, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_prat__Hnd_prat_dispatch* _con = kk_block_alloc_at_as(struct kk_whitemagic_dash_koka_src_prat__Hnd_prat_dispatch, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_dispatch = _fun_dispatch;
  return kk_whitemagic_dash_koka_src_prat__base_Hnd_prat_dispatch(_con, _ctx);
}
static inline struct kk_whitemagic_dash_koka_src_prat__Hnd_prat_dispatch* kk_whitemagic_dash_koka_src_prat__as_Hnd_prat_dispatch(kk_whitemagic_dash_koka_src_prat__prat_dispatch x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_whitemagic_dash_koka_src_prat__Hnd_prat_dispatch*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_Hnd_prat_dispatch(kk_whitemagic_dash_koka_src_prat__prat_dispatch x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_whitemagic_dash_koka_src_prat__prat_dispatch kk_whitemagic_dash_koka_src_prat__prat_dispatch_dup(kk_whitemagic_dash_koka_src_prat__prat_dispatch _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_whitemagic_dash_koka_src_prat__prat_dispatch_drop(kk_whitemagic_dash_koka_src_prat__prat_dispatch _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_whitemagic_dash_koka_src_prat__prat_dispatch_box(kk_whitemagic_dash_koka_src_prat__prat_dispatch _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_whitemagic_dash_koka_src_prat__prat_dispatch kk_whitemagic_dash_koka_src_prat__prat_dispatch_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type whitemagic-koka/src/prat/resonance
struct kk_whitemagic_dash_koka_src_prat__resonance_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_whitemagic_dash_koka_src_prat__resonance;
struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance {
  struct kk_whitemagic_dash_koka_src_prat__resonance_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause0 _fun_get_harmony_score;
  kk_std_core_hnd__clause0 _fun_get_lunar_phase;
  kk_std_core_hnd__clause0 _fun_get_predecessor;
  kk_std_core_hnd__clause2 _fun_record_invocation;
};
static inline kk_whitemagic_dash_koka_src_prat__resonance kk_whitemagic_dash_koka_src_prat__base_Hnd_resonance(struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_whitemagic_dash_koka_src_prat__resonance kk_whitemagic_dash_koka_src_prat__new_Hnd_resonance(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause0 _fun_get_harmony_score, kk_std_core_hnd__clause0 _fun_get_lunar_phase, kk_std_core_hnd__clause0 _fun_get_predecessor, kk_std_core_hnd__clause2 _fun_record_invocation, kk_context_t* _ctx) {
  struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con = kk_block_alloc_at_as(struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance, _at, 5 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_get_harmony_score = _fun_get_harmony_score;
  _con->_fun_get_lunar_phase = _fun_get_lunar_phase;
  _con->_fun_get_predecessor = _fun_get_predecessor;
  _con->_fun_record_invocation = _fun_record_invocation;
  return kk_whitemagic_dash_koka_src_prat__base_Hnd_resonance(_con, _ctx);
}
static inline struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(kk_whitemagic_dash_koka_src_prat__resonance x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_whitemagic_dash_koka_src_prat__is_Hnd_resonance(kk_whitemagic_dash_koka_src_prat__resonance x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_whitemagic_dash_koka_src_prat__resonance kk_whitemagic_dash_koka_src_prat__resonance_dup(kk_whitemagic_dash_koka_src_prat__resonance _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_whitemagic_dash_koka_src_prat__resonance_drop(kk_whitemagic_dash_koka_src_prat__resonance _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_whitemagic_dash_koka_src_prat__resonance_box(kk_whitemagic_dash_koka_src_prat__resonance _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_whitemagic_dash_koka_src_prat__resonance kk_whitemagic_dash_koka_src_prat__resonance_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Tests for the `GanaHorn` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaHorn(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaHorn(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaNeck` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaNeck(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaNeck(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaRoot` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaRoot(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaRoot(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaRoom` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaRoom(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaRoom(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaHeart` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaHeart(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaHeart(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaTail` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaTail(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaTail(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaWinnowingBasket` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaWinnowingBasket(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaWinnowingBasket(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaGhost` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaGhost(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaGhost(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaWillow` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaWillow(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaWillow(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaStar` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaStar(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaStar(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaExtendedNet` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaExtendedNet(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaExtendedNet(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaWings` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaWings(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaWings(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaChariot` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaChariot(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaChariot(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaAbundance` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaAbundance(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaAbundance(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaStraddlingLegs` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaStraddlingLegs(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaStraddlingLegs(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaMound` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaMound(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaMound(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaStomach` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaStomach(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaStomach(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaHairyHead` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaHairyHead(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaHairyHead(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaNet` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaNet(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaNet(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaTurtleBeak` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaTurtleBeak(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaTurtleBeak(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaThreeStars` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaThreeStars(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaThreeStars(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaDipper` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaDipper(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaDipper(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaOx` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaOx(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaOx(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaGirl` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaGirl(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaGirl(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaVoid` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaVoid(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaVoid(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaRoof` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaRoof(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaRoof(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaEncampment` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaEncampment(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaEncampment(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `GanaWall` constructor of the `:gana` type.

static inline bool kk_whitemagic_dash_koka_src_prat_is_ganaWall(kk_whitemagic_dash_koka_src_prat__gana gana, kk_context_t* _ctx) { /* (gana : gana) -> bool */ 
  if (kk_whitemagic_dash_koka_src_prat__is_GanaWall(gana, _ctx)) {
    return true;
  }
  {
    return false;
  }
}

kk_string_t kk_whitemagic_dash_koka_src_prat_gana_to_string(kk_whitemagic_dash_koka_src_prat__gana g, kk_context_t* _ctx); /* (g : gana) -> string */ 

kk_std_core_types__maybe kk_whitemagic_dash_koka_src_prat_route_tool_to_gana(kk_string_t tool_name, kk_context_t* _ctx); /* (tool-name : string) -> maybe<gana> */ 
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:resonance` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_prat_resonance_fs__cfc(kk_whitemagic_dash_koka_src_prat__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x630 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(resonance, _ctx);
    kk_integer_t _x = _con_x630->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_whitemagic_dash_koka_src_prat_resonance_fs__tag;

kk_box_t kk_whitemagic_dash_koka_src_prat_resonance_fs__handle(kk_whitemagic_dash_koka_src_prat__resonance hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : resonance<e,b>, ret : (res : a) -> e b, action : () -> <resonance|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-get-predecessor` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause0 kk_whitemagic_dash_koka_src_prat_resonance_fs__fun_get_predecessor(kk_whitemagic_dash_koka_src_prat__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause0<maybe<gana>,resonance,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x634 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x634->_fun_get_predecessor;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-predecessor` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause0 kk_whitemagic_dash_koka_src_prat_get_predecessor_fs__select(kk_whitemagic_dash_koka_src_prat__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause0<maybe<gana>,resonance,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x635 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_predecessor = _con_x635->_fun_get_predecessor;
    return kk_std_core_hnd__clause0_dup(_fun_get_predecessor, _ctx);
  }
}
 
// Call the `fun get-predecessor` operation of the effect `:resonance`

static inline kk_std_core_types__maybe kk_whitemagic_dash_koka_src_prat_get_predecessor(kk_context_t* _ctx) { /* () -> resonance maybe<gana> */ 
  kk_std_core_hnd__ev ev_10090 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/prat/resonance>*/;
  kk_box_t _x_x636;
  {
    struct kk_std_core_hnd_Ev* _con_x637 = kk_std_core_hnd__as_Ev(ev_10090, _ctx);
    kk_box_t _box_x72 = _con_x637->hnd;
    int32_t m = _con_x637->marker;
    kk_whitemagic_dash_koka_src_prat__resonance h = kk_whitemagic_dash_koka_src_prat__resonance_unbox(_box_x72, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_prat__resonance_dup(h, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x638 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x638->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x638->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x638->_fun_get_lunar_phase;
      kk_std_core_hnd__clause0 _fun_get_predecessor = _con_x638->_fun_get_predecessor;
      kk_std_core_hnd__clause2 _pat_3 = _con_x638->_fun_record_invocation;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_predecessor, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x75 = _fun_get_predecessor.clause;
        _x_x636 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x75, (_fun_unbox_x75, m, ev_10090, _ctx), _ctx); /*10005*/
      }
    }
  }
  return kk_std_core_types__maybe_unbox(_x_x636, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-record-invocation` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause2 kk_whitemagic_dash_koka_src_prat_resonance_fs__fun_record_invocation(kk_whitemagic_dash_koka_src_prat__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause2<gana,string,(),resonance,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x639 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x639->_fun_record_invocation;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `record-invocation` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause2 kk_whitemagic_dash_koka_src_prat_record_invocation_fs__select(kk_whitemagic_dash_koka_src_prat__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause2<gana,string,(),resonance,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x640 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_record_invocation = _con_x640->_fun_record_invocation;
    return kk_std_core_hnd__clause2_dup(_fun_record_invocation, _ctx);
  }
}
 
// Call the `fun record-invocation` operation of the effect `:resonance`

static inline kk_unit_t kk_whitemagic_dash_koka_src_prat_record_invocation(kk_whitemagic_dash_koka_src_prat__gana gana, kk_string_t tool, kk_context_t* _ctx) { /* (gana : gana, tool : string) -> resonance () */ 
  kk_std_core_hnd__ev evx_10092 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/prat/resonance>*/;
  kk_box_t _x_x641;
  {
    struct kk_std_core_hnd_Ev* _con_x642 = kk_std_core_hnd__as_Ev(evx_10092, _ctx);
    kk_box_t _box_x78 = _con_x642->hnd;
    int32_t m = _con_x642->marker;
    kk_whitemagic_dash_koka_src_prat__resonance h = kk_whitemagic_dash_koka_src_prat__resonance_unbox(_box_x78, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_prat__resonance_dup(h, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x643 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x643->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x643->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x643->_fun_get_lunar_phase;
      kk_std_core_hnd__clause0 _pat_3 = _con_x643->_fun_get_predecessor;
      kk_std_core_hnd__clause2 _fun_record_invocation = _con_x643->_fun_record_invocation;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_record_invocation, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x83 = _fun_record_invocation.clause;
        _x_x641 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x83, (_fun_unbox_x83, m, evx_10092, kk_whitemagic_dash_koka_src_prat__gana_box(gana, _ctx), kk_string_box(tool), _ctx), _ctx); /*10016*/
      }
    }
  }
  kk_unit_unbox(_x_x641); return kk_Unit;
}
 
// Automatically generated. Retrieves the `@fun-get-lunar-phase` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause0 kk_whitemagic_dash_koka_src_prat_resonance_fs__fun_get_lunar_phase(kk_whitemagic_dash_koka_src_prat__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause0<float64,resonance,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x644 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x644->_fun_get_lunar_phase;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-lunar-phase` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause0 kk_whitemagic_dash_koka_src_prat_get_lunar_phase_fs__select(kk_whitemagic_dash_koka_src_prat__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause0<float64,resonance,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x645 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_lunar_phase = _con_x645->_fun_get_lunar_phase;
    return kk_std_core_hnd__clause0_dup(_fun_get_lunar_phase, _ctx);
  }
}
 
// Call the `fun get-lunar-phase` operation of the effect `:resonance`

static inline double kk_whitemagic_dash_koka_src_prat_get_lunar_phase(kk_context_t* _ctx) { /* () -> resonance float64 */ 
  kk_std_core_hnd__ev ev_10096 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/prat/resonance>*/;
  kk_box_t _x_x646;
  {
    struct kk_std_core_hnd_Ev* _con_x647 = kk_std_core_hnd__as_Ev(ev_10096, _ctx);
    kk_box_t _box_x88 = _con_x647->hnd;
    int32_t m = _con_x647->marker;
    kk_whitemagic_dash_koka_src_prat__resonance h = kk_whitemagic_dash_koka_src_prat__resonance_unbox(_box_x88, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_prat__resonance_dup(h, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x648 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x648->_cfc;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x648->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _fun_get_lunar_phase = _con_x648->_fun_get_lunar_phase;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x648->_fun_get_predecessor;
      kk_std_core_hnd__clause2 _pat_3 = _con_x648->_fun_record_invocation;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_lunar_phase, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x91 = _fun_get_lunar_phase.clause;
        _x_x646 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x91, (_fun_unbox_x91, m, ev_10096, _ctx), _ctx); /*10005*/
      }
    }
  }
  return kk_double_unbox(_x_x646, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-get-harmony-score` constructor field of the `:resonance` type.

static inline kk_std_core_hnd__clause0 kk_whitemagic_dash_koka_src_prat_resonance_fs__fun_get_harmony_score(kk_whitemagic_dash_koka_src_prat__resonance resonance, kk_context_t* _ctx) { /* forall<e,a> (resonance : resonance<e,a>) -> hnd/clause0<float64,resonance,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x649 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(resonance, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x649->_fun_get_harmony_score;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// select `get-harmony-score` operation out of effect `:resonance`

static inline kk_std_core_hnd__clause0 kk_whitemagic_dash_koka_src_prat_get_harmony_score_fs__select(kk_whitemagic_dash_koka_src_prat__resonance hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : resonance<e,a>) -> hnd/clause0<float64,resonance,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x650 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_get_harmony_score = _con_x650->_fun_get_harmony_score;
    return kk_std_core_hnd__clause0_dup(_fun_get_harmony_score, _ctx);
  }
}
 
// Call the `fun get-harmony-score` operation of the effect `:resonance`

static inline double kk_whitemagic_dash_koka_src_prat_get_harmony_score(kk_context_t* _ctx) { /* () -> resonance float64 */ 
  kk_std_core_hnd__ev ev_10098 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/prat/resonance>*/;
  kk_box_t _x_x651;
  {
    struct kk_std_core_hnd_Ev* _con_x652 = kk_std_core_hnd__as_Ev(ev_10098, _ctx);
    kk_box_t _box_x94 = _con_x652->hnd;
    int32_t m = _con_x652->marker;
    kk_whitemagic_dash_koka_src_prat__resonance h = kk_whitemagic_dash_koka_src_prat__resonance_unbox(_box_x94, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_prat__resonance_dup(h, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_prat__Hnd_resonance* _con_x653 = kk_whitemagic_dash_koka_src_prat__as_Hnd_resonance(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x653->_cfc;
      kk_std_core_hnd__clause0 _fun_get_harmony_score = _con_x653->_fun_get_harmony_score;
      kk_std_core_hnd__clause0 _pat_1_0 = _con_x653->_fun_get_lunar_phase;
      kk_std_core_hnd__clause0 _pat_2_0 = _con_x653->_fun_get_predecessor;
      kk_std_core_hnd__clause2 _pat_3 = _con_x653->_fun_record_invocation;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_get_harmony_score, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x97 = _fun_get_harmony_score.clause;
        _x_x651 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x97, (_fun_unbox_x97, m, ev_10098, _ctx), _ctx); /*10005*/
      }
    }
  }
  return kk_double_unbox(_x_x651, KK_OWNED, _ctx);
}
 
// monadic lift

static inline kk_unit_t kk_whitemagic_dash_koka_src_prat__mlift_handle_resonance_10079(kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,e> (wild_ : ()) -> <local<h>|e> () */ 
  kk_Unit; return kk_Unit;
}

kk_box_t kk_whitemagic_dash_koka_src_prat_handle_resonance(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <resonance|e> a) -> e a */ 
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:prat-dispatch` type.

static inline kk_integer_t kk_whitemagic_dash_koka_src_prat_prat_dispatch_fs__cfc(kk_whitemagic_dash_koka_src_prat__prat_dispatch _this, kk_context_t* _ctx) { /* forall<e,a> (prat-dispatch<e,a>) -> int */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_prat_dispatch* _con_x674 = kk_whitemagic_dash_koka_src_prat__as_Hnd_prat_dispatch(_this, _ctx);
    kk_integer_t _x = _con_x674->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_whitemagic_dash_koka_src_prat_prat_dispatch_fs__tag;

kk_box_t kk_whitemagic_dash_koka_src_prat_prat_dispatch_fs__handle(kk_whitemagic_dash_koka_src_prat__prat_dispatch hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : prat-dispatch<e,b>, ret : (res : a) -> e b, action : () -> <prat-dispatch|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-dispatch` constructor field of the `:prat-dispatch` type.

static inline kk_std_core_hnd__clause2 kk_whitemagic_dash_koka_src_prat_prat_dispatch_fs__fun_dispatch(kk_whitemagic_dash_koka_src_prat__prat_dispatch _this, kk_context_t* _ctx) { /* forall<e,a> (prat-dispatch<e,a>) -> hnd/clause2<string,string,string,prat-dispatch,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_prat_dispatch* _con_x678 = kk_whitemagic_dash_koka_src_prat__as_Hnd_prat_dispatch(_this, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x678->_fun_dispatch;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `dispatch` operation out of effect `:prat-dispatch`

static inline kk_std_core_hnd__clause2 kk_whitemagic_dash_koka_src_prat_dispatch_fs__select(kk_whitemagic_dash_koka_src_prat__prat_dispatch hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : prat-dispatch<e,a>) -> hnd/clause2<string,string,string,prat-dispatch,e,a> */ 
  {
    struct kk_whitemagic_dash_koka_src_prat__Hnd_prat_dispatch* _con_x679 = kk_whitemagic_dash_koka_src_prat__as_Hnd_prat_dispatch(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_dispatch = _con_x679->_fun_dispatch;
    return kk_std_core_hnd__clause2_dup(_fun_dispatch, _ctx);
  }
}
 
// Call the `fun dispatch` operation of the effect `:prat-dispatch`

static inline kk_string_t kk_whitemagic_dash_koka_src_prat_dispatch(kk_string_t tool, kk_string_t args, kk_context_t* _ctx) { /* (tool : string, args : string) -> prat-dispatch string */ 
  kk_std_core_hnd__ev evx_10112 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<whitemagic-koka/src/prat/prat-dispatch>*/;
  kk_box_t _x_x680;
  {
    struct kk_std_core_hnd_Ev* _con_x681 = kk_std_core_hnd__as_Ev(evx_10112, _ctx);
    kk_box_t _box_x164 = _con_x681->hnd;
    int32_t m = _con_x681->marker;
    kk_whitemagic_dash_koka_src_prat__prat_dispatch h = kk_whitemagic_dash_koka_src_prat__prat_dispatch_unbox(_box_x164, KK_BORROWED, _ctx);
    kk_whitemagic_dash_koka_src_prat__prat_dispatch_dup(h, _ctx);
    {
      struct kk_whitemagic_dash_koka_src_prat__Hnd_prat_dispatch* _con_x682 = kk_whitemagic_dash_koka_src_prat__as_Hnd_prat_dispatch(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x682->_cfc;
      kk_std_core_hnd__clause2 _fun_dispatch = _con_x682->_fun_dispatch;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_dispatch, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x169 = _fun_dispatch.clause;
        _x_x680 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x169, (_fun_unbox_x169, m, evx_10112, kk_string_box(tool), kk_string_box(args), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_string_unbox(_x_x680);
}

kk_box_t kk_whitemagic_dash_koka_src_prat_handle_prat_dispatch_production(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <prat-dispatch|e> a) -> e a */ 

kk_string_t kk_whitemagic_dash_koka_src_prat__mlift_route_prat_call_10080(kk_string_t _c_x10030, double _y_x10032, kk_whitemagic_dash_koka_src_prat__gana g, kk_string_t tool_name, double _y_x10034, kk_context_t* _ctx); /* (string, float64, g : gana, tool-name : string, float64) -> <resonance,prat-dispatch> string */ 

kk_string_t kk_whitemagic_dash_koka_src_prat__mlift_route_prat_call_10081(kk_string_t _c_x10030, kk_whitemagic_dash_koka_src_prat__gana g, kk_string_t tool_name, double _y_x10032, kk_context_t* _ctx); /* (string, g : gana, tool-name : string, float64) -> <resonance,prat-dispatch> string */ 

kk_string_t kk_whitemagic_dash_koka_src_prat__mlift_route_prat_call_10082(kk_whitemagic_dash_koka_src_prat__gana g, kk_string_t tool_name, kk_string_t _c_x10030, kk_context_t* _ctx); /* (g : gana, tool-name : string, string) -> string */ 

kk_string_t kk_whitemagic_dash_koka_src_prat__mlift_route_prat_call_10083(kk_whitemagic_dash_koka_src_prat__gana g, kk_std_core_types__maybe pred, kk_string_t tool_name, kk_unit_t wild__, kk_context_t* _ctx); /* (g : gana, pred : maybe<gana>, tool-name : string, wild_ : ()) -> <resonance,prat-dispatch> string */ 

kk_string_t kk_whitemagic_dash_koka_src_prat__mlift_route_prat_call_10084(kk_whitemagic_dash_koka_src_prat__gana g, kk_std_core_types__maybe pred, kk_string_t tool_name, kk_string_t result, kk_context_t* _ctx); /* (g : gana, pred : maybe<gana>, tool-name : string, result : string) -> <prat-dispatch,resonance> string */ 

kk_string_t kk_whitemagic_dash_koka_src_prat__mlift_route_prat_call_10085(kk_string_t args, kk_whitemagic_dash_koka_src_prat__gana g, kk_string_t tool_name, kk_std_core_types__maybe pred, kk_context_t* _ctx); /* (args : string, g : gana, tool-name : string, pred : maybe<gana>) -> <resonance,prat-dispatch> string */ 

kk_string_t kk_whitemagic_dash_koka_src_prat_route_prat_call(kk_string_t tool_name, kk_string_t args, kk_context_t* _ctx); /* (tool-name : string, args : string) -> <prat-dispatch,resonance> string */ 
 
// Extract tool name from JSON (very simplified for benchmarking)
// Just returns "search_memories" for any non-empty input

static inline kk_string_t kk_whitemagic_dash_koka_src_prat_extract_tool(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> string */ 
  bool _match_x569;
  kk_string_t _x_x901 = kk_string_empty(); /*string*/
  _match_x569 = kk_string_is_eq(line,_x_x901,kk_context()); /*bool*/
  if (_match_x569) {
    kk_define_string_literal(, _s_x903, 7, "unknown", _ctx)
    return kk_string_dup(_s_x903, _ctx);
  }
  {
    kk_define_string_literal(, _s_x904, 15, "search_memories", _ctx)
    return kk_string_dup(_s_x904, _ctx);
  }
}

kk_unit_t kk_whitemagic_dash_koka_src_prat_flush_stdout(kk_context_t* _ctx); /* () -> console/console () */ 

kk_string_t kk_whitemagic_dash_koka_src_prat_extract_tool_from_ffi(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> string */ 

kk_unit_t kk_whitemagic_dash_koka_src_prat__mlift_server_loop_10086(kk_string_t response, kk_context_t* _ctx); /* (response : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,exn> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_prat__mlift_server_loop_10087(kk_string_t _c_x10037, kk_context_t* _ctx); /* (string) -> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_prat__mlift_server_loop_10088(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> <console/console,exn,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>,exn> () */ 

kk_unit_t kk_whitemagic_dash_koka_src_prat_server_loop(kk_context_t* _ctx); /* () -> io () */ 

kk_unit_t kk_whitemagic_dash_koka_src_prat_main(kk_context_t* _ctx); /* () -> io () */ 

void kk_whitemagic_dash_koka_src_prat__init(kk_context_t* _ctx);


void kk_whitemagic_dash_koka_src_prat__done(kk_context_t* _ctx);

#endif // header
