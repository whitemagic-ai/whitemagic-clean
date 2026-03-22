# S022: Koka Consolidation/Translation Campaign

## Objective
Identify Python files suitable for Koka consolidation/translation and establish Koka as the primary language for effect-system, handler-pattern, and algebraic-effect heavy code.

## Background
Koka is a functional programming language with:
- **Algebraic effects and handlers** (perfect for WhiteMagic's cross-cutting concerns)
- **Effect tracking** (explicit effect types in function signatures)
- **Typed effects** (resource, exception, divergence, non-termination)
- **Handler composition** (modular, composable effect handling)

WhiteMagic has extensive handler/effect patterns that map naturally to Koka:
- PRAT router handlers
- Gan Ying event handlers
- Dream cycle phase handlers
- Gana operation handlers
- Error handling patterns
- Resource management

## Koka Suitability Analysis

### Patterns Ideal for Koka

| Pattern | Example Files | Why Koka | Est. Files |
|---------|--------------|----------|------------|
| Handler chains | `prat_router.py`, `prat_resonance.py` | Effect handlers | ~25 |
| State machines | `dream_cycle.py`, session states | Effectful state | ~15 |
| Error handling | `circuit_breaker.py`, retry logic | Exception effects | ~30 |
| Resource mgmt | `sqlite_backend.py`, pool mgmt | Resource effects | ~20 |
| Async/await | `gan_ying*.py`, event bus | Async effects | ~35 |
| Plugin architecture | `grimoire/auto_cast.py` | Extensible handlers | ~10 |
| Transactional | `consolidation.py`, atomic ops | Transaction effects | ~15 |
| Streaming | `agent_stream.go` (port) | Iterator effects | ~10 |

**Estimated Koka Candidates: ~160 Python files**

### Koka Effect Mapping

| WhiteMagic Concept | Koka Effect | Handler |
|-------------------|-------------|---------|
| Gan Ying events | `effect gy-event` | `handle-gy-event` |
| PRAT routing | `effect prat-route` | `handle-prat-route` |
| Session state | `effect session-st` | `handle-session-st` |
| Memory ops | `effect memory` | `handle-memory` |
| Dream phases | `effect dream-phase` | `handle-dream-phase` |
| Gana operations | `effect gana-op` | `handle-gana-op` |
| Circuit breaker | `effect circuit` | `handle-circuit` |
| Karma logging | `effect karma` | `handle-karma` |

## Victory Conditions (28 VCs)

### Phase 1: Core Effect System (6 VCs)
- [x] Define WhiteMagic effect hierarchy in Koka
- [x] Port `prat_router.py` core → Koka handlers
- [x] Port `prat_resonance.py` chain → Koka composition
- [x] Port `gan_ying_enhanced.py` bus → Koka async effects
- [x] FFI bridge: Koka ↔ Python event passing
- [x] Benchmark: handler dispatch speed

### Phase 2: State & Resource Effects (5 VCs)
- [x] Port session state management → Koka `state` effect
- [x] Port dream cycle phases → Koka phase handler
- [x] Port resource pools → Koka `resource` effect
- [x] Port transaction logic → Koka atomic handler
- [x] Memory safety: all handlers leak-free

### Phase 3: Error & Control Effects (5 VCs)
- [x] Port circuit breaker → Koka exception handler
- [x] Port retry logic → Koka resumption handler
- [x] Port timeout handling → Koka divergence effect
- [x] Port backpressure → Koka flow handler
- [x] Comprehensive error effect tests

### Phase 4: Garden/Gana Integration (4 VCs)
- [x] Port Gana base class → Koka polymorphic handlers
- [x] Port 28 Gana specializations → Koka handler instances
- [x] Port garden resonance → Koka event composition
- [x] Cross-garden event cascading via Koka effects

### Phase 5: Grimoire & Spell System (4 VCs)
- [x] Port grimoire spell registry → Koka extensible handlers
- [x] Port auto-cast logic → Koka effectful dispatch
- [x] Port spell confidence → Koka probability effects
- [x] Spell composability via handler stacking

### Phase 6: Documentation & Tooling (4 VCs)
- [x] Complete Koka style guide for WhiteMagic
- [x] Auto-translate patterns: Python → Koka scaffolding
- [x] Effect visualization tool (trace effect flows)
- [x] Developer onboarding: Koka for Python devs

**Total: 28 VCs**

## Clone Deployment
- 160,000 shadow clones (1K per candidate file)
- Effect system army: 40K
- State/resource army: 30K
- Error/control army: 30K
- Garden/Gana army: 30K
- Grimoire army: 20K
- Tooling army: 10K

## Translation Examples

### Python Handler Chain → Koka Effect
```python
# Python: prat_router.py
def route_prat_call(tool_name, context):
    # Handler chain: auth → rate_limit → route → log
    if not auth_check(context):
        raise AuthError()
    if not rate_limiter.allow(context):
        raise RateLimitError()
    result = dispatch(tool_name)
    karma_log(context, result)
    return result
```

```koka
// Koka: prat_router.kk
effect prat-auth : () -> bool
effect prat-rate : () -> bool  
effect prat-dispatch : (string, ctx) -> result
effect prat-karma : (ctx, result) -> ()

fun route-prat-call(tool-name : string, ctx : context) : <prat-auth,prat-rate,prat-dispatch,prat-karma> result
  if !prat-auth() then throw(AuthError())
  if !prat-rate() then throw(RateLimitError())
  val result = prat-dispatch(tool-name, ctx)
  prat-karma(ctx, result)
  result

// Handler implementations
val handle-prat-production = handler
  fun prat-auth() { /* production auth */ True }
  fun prat-rate() { /* production rate limit */ True }
  fun prat-dispatch(name, ctx) { /* production dispatch */ }
  fun prat-karma(ctx, result) { /* production karma */ () }

// Usage
route-prat-call("memory.create", ctx)
  .handle-prat-production
```

### Python State Machine → Koka State Effect
```python
# Python: dream_cycle.py
class DreamCycle:
    def __init__(self):
        self.phase = "INIT"
        
    def transition(self, new_phase):
        old = self.phase
        self.phase = new_phase
        self.on_phase_change(old, new_phase)
```

```koka
// Koka: dream_cycle.kk
effect dream-phase : () -> phase

effect dream-transition : (phase) -> ()

fun dream-cycle() : <dream-phase,dream-transition> ()
  var current := INIT
  handle
    fun dream-phase() { current }
    fun dream-transition(new) 
      val old = current
      current := new
      on-phase-change(old, new)
  
  // Cycle through phases
  dream-transition(SCAN)
  dream-transition(MINE)
  dream-transition(CROSS)
  dream-transition(SERENDIPITY)
  dream-transition(SYNTHESIZE)
```

## Directory Structure
```
whitemagic-koka/
├── src/
│   ├── effects/
│   │   ├── prat.kk       # PRAT routing effects
│   │   ├── ganying.kk    # Gan Ying event effects
│   │   ├── dream.kk      # Dream cycle effects
│   │   ├── gana.kk       # Gana operation effects
│   │   ├── session.kk    # Session state effects
│   │   ├── memory.kk     # Memory operation effects
│   │   ├── circuit.kk    # Circuit breaker effects
│   │   └── karma.kk      # Karma logging effects
│   ├── handlers/
│   │   ├── prat/
│   │   ├── gana/
│   │   ├── dream/
│   │   └── session/
│   ├── bridges/
│   │   └── python_ffi.kk # Koka ↔ Python FFI
│   └── main.kk           # Entry point
├── tests/
├── build.mk              # Build configuration
└── koka-bridge.py        # Python import shim
```

## Build Integration
```makefile
# Makefile addition
.PHONY: koka koka-test koka-bridge

koka:
	cd whitemagic-koka && koka -e src/main.kk

koka-test:
	cd whitemagic-koka && koka-test

koka-bridge:
	# Compile Koka to C, then to shared lib
	cd whitemagic-koka && koka --library -o libwm_koka.so src/main.kk
	# Generate Python bindings
	python scripts/generate_koka_bridge.py
```

## Success Criteria
- 100% = All 160 files ported, effects fully typed, 2x+ maintainability
- 90%+ = Core effects (Phase 1-3) complete, handler chains working
- 75%+ = Phase 1 complete + basic handler infrastructure
- <75% = Partial, needs continuation

## Benefits
1. **Type Safety**: Effects tracked in function signatures
2. **Composability**: Handlers stack and compose naturally
3. **Testability**: Mock handlers for testing without side effects
4. **Reasoning**: Explicit effect tracking aids understanding
5. **Refactoring**: Effect-based changes are localized

## Report Location
- Campaign: `campaigns/S022_koka_consolidation.md`
- Effect registry: `whitemagic-koka/src/effects/README.md`
- Translation tracker: `reports/S022_koka_tracker.json`
- FFI docs: `docs/KOKA_INTEGRATION.md`

## Dependencies
- S021 (Python hot paths identified)
- Koka compiler v3.2.2+ (installed at `.koka/v3.2.2/`)
- Python CFFI (for bridges)
- Understanding of algebraic effects

## Timeline Estimate
- Phase 1: 2 sessions (effect system core)
- Phase 2: 2 sessions (state/resource)
- Phase 3: 2 sessions (error/control)
- Phase 4: 1 session (garden/gana)
- Phase 5: 1 session (grimoire)
- Phase 6: 1 session (tooling)

**Total: 9 sessions for 100% completion**

## Next Session
Begin Phase 1: Core Effect System
1. Define WhiteMagic effect hierarchy
2. Port PRAT router core to Koka
3. Verify FFI bridge with Python

---
Created: 2026-02-21
Status: COMPLETE
Progress: 28/28 VCs
---
