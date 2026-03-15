# Garden Migration Guide (S023)

## Summary

As part of the S023 Garden Consolidation campaign, the 30-garden system has been folded into the perfect 28-fold symmetry to align with the 28 Lunar Mansions.

## Changes

### Folded Gardens

| Orphan Garden | Target Garden | Rationale |
|---------------|---------------|-----------|
| `air` | `voice` | Air is the medium of voice - breath enables speech |
| `metal` | `practice` | Metal tools enable disciplined practice and mastery |

### API Migrations

#### Air → Voice

```python
# BEFORE (deprecated)
from whitemagic.gardens import get_air_garden
air = get_air_garden()
air.breathe("calm")
air.clear()

# AFTER (recommended)
from whitemagic.gardens import get_voice_garden
voice = get_voice_garden()
voice.breathe("calm")  # Same functionality now in voice
voice.clear()  # Same functionality now in voice
```

#### Metal → Practice

```python
# BEFORE (deprecated)
from whitemagic.gardens import get_metal_garden
metal = get_metal_garden()
result = metal.consult_zodiac("capricorn", {"task": "build"})

# AFTER (recommended)
from whitemagic.gardens import get_practice_garden
practice = get_practice_garden()
result = practice.consult_zodiac("capricorn", {"task": "build"})
```

#### Terminal Scratchpad

```python
# BEFORE (deprecated)
from whitemagic.gardens.air.agentic.terminal_scratchpad import TerminalScratchpad

# AFTER (recommended)
from whitemagic.gardens.voice.agentic.terminal_scratchpad import TerminalScratchpad
```

#### Zodiac Council

```python
# BEFORE (deprecated)
from whitemagic.gardens.metal.zodiac import ZodiacCouncil, get_zodiac_council

# AFTER (recommended)
from whitemagic.gardens.practice.zodiac import ZodiacCouncil, get_zodiac_council
```

## Backward Compatibility

The old imports still work with deprecation warnings:

```python
import warnings
warnings.filterwarnings("always")

from whitemagic.gardens import get_air_garden, get_metal_garden

# These will emit DeprecationWarnings but still work
air = get_air_garden()  # Returns VoiceGarden instance
metal = get_metal_garden()  # Returns PracticeGarden instance
```

## Registry Status

- **28 active gardens**: joy, love, beauty, truth, wisdom, mystery, play, wonder, connection, sangha, practice, presence, voice, dharma, courage, gratitude, patience, grief, awe, humor, healing, creation, transformation, sanctuary, adventure, reverence, stillness, protection
- **2 deprecated (redirected)**: air → voice, metal → practice

## Timeline

- **S023 Completion Date**: 2026-02-21
- **Migration Period**: Ongoing (backward compatible)
- **Full Removal**: Future major version (TBD)

## Benefits

1. **Perfect 28-fold symmetry**: Corresponds to 28 Lunar Mansions
2. **Reduced maintenance**: 28 vs 30 gardens
3. **Deeper integration**: Air/voice synergy, metal/practice synergy
4. **Clearer taxonomy**: No orphan ambiguity

## Questions?

See the full campaign documentation: `campaigns/S023_garden_consolidation.md`
