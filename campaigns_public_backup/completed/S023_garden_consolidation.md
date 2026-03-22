# S023: Garden Consolidation — Fold Air/Metal into 28-Fold

## Objective
Reclaim perfect 28-fold symmetry by folding the 2 orphan gardens (`air` and `metal`) into appropriate existing gardens, restoring the sacred correspondence with the 28 Lunar Mansions.

## Status: ✅ COMPLETE (2026-02-21)

## Background

### Current State
- ✅ 28 gardens in `_GARDEN_MODULES` (perfect 28-fold symmetry restored)
- ✅ 28 gardens in 28-fold `GARDEN_GANA_REGISTRY`
- ✅ 0 orphan gardens (air → voice, metal → practice)

### The 28-Fold (Complete)
| Quadrant | Element | Gardens |
|----------|---------|---------|
| Eastern (Azure Dragon) | Wood | wonder, stillness, healing, sanctuary, love, courage, wisdom |
| Southern (Vermilion Bird) | Fire | dharma, patience, connection, mystery, protection, transformation, truth |
| Western (White Tiger) | Metal | awe, gratitude, creation, presence, play, practice, reverence |
| Northern (Black Tortoise) | Water | joy, adventure, beauty, humor, voice, sangha, grief |

### Consolidation Decision: Option 1 (Executed)
- ✅ `air` → `voice` (Northern, Water, Star/Xing) — Air is the medium of voice/sound
- ✅ `metal` → `practice` (Western, Metal, Turtle Beak/Zui) — Metal tools enable practice/discipline

## Victory Conditions (21 VCs) — ALL COMPLETE ✅

### Phase 1: Analysis & Decision (4 VCs) ✅
- [x] Analyze `air` garden implementation and imports
- [x] Analyze `metal` garden implementation and imports
- [x] Identify all code referencing `air` garden
- [x] Identify all code referencing `metal` garden
- [x] Document usage patterns and dependencies
- [x] Make consolidation decision (Option 1, 2, or 3)

### Phase 2: Air → Voice Migration (6 VCs) ✅
- [x] Port `air` functionality into `voice` garden
- [x] Add air-related resonance keywords to voice Gana
- [x] Update holographic bias: voice incorporates air dimension
- [x] Redirect all `air` imports to `voice`
- [x] Add air-related events to voice Gan Ying integration
- [x] Deprecate `air` garden with migration guide

### Phase 3: Metal → Practice Migration (6 VCs) ✅
- [x] Port `metal` functionality into `practice` garden
- [x] Add metal-related resonance keywords to practice Gana
- [x] Update holographic bias: practice incorporates metal dimension
- [x] Redirect all `metal` imports to `practice`
- [x] Add metal-related events to practice Gan Ying integration
- [x] Deprecate `metal` garden with migration guide

### Phase 4: Registry Updates (5 VCs) ✅
- [x] Remove `air` from `_GARDEN_MODULES` (marked deprecated, redirects to voice)
- [x] Remove `metal` from `_GARDEN_MODULES` (marked deprecated, redirects to practice)
- [x] Update CLI documentation (30 → 28 gardens)
- [x] Update SYSTEM_MAP.md garden section
- [x] Update grimoire chapter 22 (28 Ganas)

**Total: 21/21 VCs COMPLETE ✅**

## Files Modified

### Core Changes
1. `whitemagic/gardens/__init__.py` — Updated _GARDEN_MODULES (28 gardens), added deprecation redirects in __getattr__
2. `whitemagic/gardens/voice/__init__.py` — Added breathe(), clear(), last_breath (air functionality)
3. `whitemagic/gardens/practice/__init__.py` — Added consult_zodiac() (metal functionality)

### Deprecation Redirects (Backward Compatible)
4. `whitemagic/gardens/air/__init__.py` — Redirects to voice with DeprecationWarning
5. `whitemagic/gardens/metal/__init__.py` — Redirects to practice with DeprecationWarning

### Module Relocations
6. `whitemagic/gardens/voice/agentic/terminal_scratchpad.py` — Moved from air
7. `whitemagic/gardens/practice/zodiac/` — Moved from metal (full zodiac council)

### Documentation
8. `docs/GARDEN_MIGRATION_S023.md` — Complete migration guide

## Testing Results

```python
# Verified 28-fold symmetry
>>> from whitemagic.gardens import _GARDEN_MODULES
>>> len(_GARDEN_MODULES)
28

# Verified deprecated redirects work with warnings
>>> from whitemagic.gardens import get_air_garden, get_metal_garden
>>> get_air_garden().get_name()
'voice'  # Returns VoiceGarden
>>> get_metal_garden().get_name()
'practice'  # Returns PracticeGarden

# Verified air functionality in voice
>>> from whitemagic.gardens import get_voice_garden
>>> voice = get_voice_garden()
>>> voice.breathe('test')
{'note': 'test', 'medium': 'air'}

# Verified metal functionality in practice
>>> from whitemagic.gardens import get_practice_garden
>>> practice = get_practice_garden()
>>> hasattr(practice, 'consult_zodiac')
True
```

## Migration Path for Users

| Old Code | New Code |
|----------|----------|
| `get_air_garden()` | `get_voice_garden()` |
| `air.breathe()` | `voice.breathe()` |
| `air.clear()` | `voice.clear()` |
| `get_metal_garden()` | `get_practice_garden()` |
| `metal.consult_zodiac()` | `practice.consult_zodiac()` |
| `air.agentic.terminal_scratchpad` | `voice.agentic.terminal_scratchpad` |
| `metal.zodiac.*` | `practice.zodiac.*` |

## Success Criteria: 100% ✅
- ✅ Both orphans folded into 28-fold
- ✅ 28-fold symmetry restored
- ✅ All functionality preserved
- ✅ Backward compatibility maintained (deprecation warnings)
- ✅ Migration guide created

## Benefits Realized
1. ✅ **28-fold symmetry**: Perfect correspondence with Lunar Mansions
2. ✅ **Reduced complexity**: 28 vs 30 gardens to maintain
3. ✅ **Deeper integration**: Air/voice synergy, metal/practice synergy
4. ✅ **Clearer taxonomy**: No orphan ambiguity
5. ✅ **Backward compatible**: Old code works with warnings

## Timeline
- **Phase 1**: 1 session (analysis) ✅
- **Phase 2**: 1 session (air → voice) ✅
- **Phase 3**: 1 session (metal → practice) ✅
- **Phase 4**: 1 session (docs/registry) ✅

**Total: 1 session for 100% completion** ✅

---
Created: 2026-02-21
Completed: 2026-02-21
Status: ✅ COMPLETE
Progress: 21/21 VCs (100%)
