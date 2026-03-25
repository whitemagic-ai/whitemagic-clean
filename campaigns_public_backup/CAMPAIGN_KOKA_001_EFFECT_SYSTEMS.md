# Campaign KOKA-001: Effect-Based Functional Programming Initiative

**Campaign Codename**: DHARMA-EFFECTS  
**Objective**: Migrate effect-heavy Python patterns to Koka for typed effects and composable handlers  
**Estimated Impact**: 214,516 LOC migrated | 636 files | 77.4% of Python codebase  
**Shadow Clone Composition**: 6 Specialist Clones  
**Estimated Duration**: 6-8 weeks with parallel execution  

---

## Strategic Overview

Koka is the optimal choice for:
- **Effect tracking** (explicit effect types in function signatures)
- **Handler composition** (modular error handling, logging, state)
- **Resource safety** (automatic disposal via effects)
- **Async/await clarity** (async effects vs sync functions)
- **Exception handling** (checked exceptions via effect types)

The Python scout identified **636 files** with strong effect patterns - this is the largest migration target by file count, representing decorator-heavy, exception-prone code that would benefit from Koka's effect system.

**Key Advantage**: Koka compiles to efficient C code with minimal runtime overhead while providing strong static guarantees about effects.

---

## Victory Conditions (VCs)

### VC-1: Grimoire Chapters Effect System (Priority: CRITICAL)
**Target**: `whitemagic/grimoire/chapters.py` (789 LOC)  
**Objective**: Effect-tracked spell execution with handlers  
**Success Metrics**:
- `spell-cast` effect with handler for different contexts
- `io` effect isolated from pure spell logic
- `state` effect for grimoire state management
- Resource safety via `dispose` effect

**Clone Assignment**: KOKA-LEAD-01 (Expert) + KOKA-SPEC-01 (Effects)

### VC-2: Unified API Effect Handlers (Priority: CRITICAL)
**Target**: `whitemagic/tools/unified_api.py` (544 LOC)  
**Objective**: Composable API effects (auth, rate-limit, logging)  
**Success Metrics**:
- `http` effect with retry handler
- `auth` effect with token refresh handler
- `log` effect with structured logging handler
- Effect polymorphism (same API, different handlers)

**Clone Assignment**: KOKA-SPEC-02 (API handlers)

### VC-3: Dharma Rules Effect Engine (Priority: HIGH)
**Target**: `whitemagic/dharma/rules.py` (639 LOC)  
**Objective**: Effect-based rule evaluation  
**Success Metrics**:
- `check` effect for rule validation
- `exception` effect for rule violations
- Handler for graceful degradation
- Effect row polymorphism for extensibility

**Clone Assignment**: KOKA-SPEC-03 (Rules engine)

### VC-4: Session Startup Effect Pipeline (Priority: HIGH)
**Target**: `whitemagic/core/orchestration/session_startup.py` (676 LOC)  
**Objective**: Composable startup effects  
**Success Metrics**:
- `init` effect sequence handler
- `config` effect for configuration loading
- `error` effect for startup failure handling
- Resume capability for partial startup

**Clone Assignment**: KOKA-SPEC-04 (Orchestration)

### VC-5: MCP Lean Effect Runtime (Priority: MEDIUM)
**Target**: `whitemagic/run_mcp_lean.py` (523 LOC)  
**Objective**: Effect-based MCP protocol handling  
**Success Metrics**:
- `websocket` effect for real-time comms
- `jsonrpc` effect for request handling
- `timeout` effect with early termination handler
- Backpressure via `yield` effect

**Clone Assignment**: KOKA-SPEC-05 (Runtime)

### VC-6: Gnosis Tool Effect System (Priority: MEDIUM)
**Target**: `whitemagic/tools/gnosis.py` (571 LOC)  
**Objective**: Effect-tracked tool discovery  
**Success Metrics**:
- `discover` effect for capability scanning
- `cache` effect with TTL handler
- `fallback` effect for degraded operation
- Effect-based capability matrix

**Clone Assignment**: KOKA-SPEC-06 (Tools)

### VC-7: Dispatch Table Effect Router (Priority: MEDIUM)
**Target**: `whitemagic/tools/dispatch_table.py` (748 LOC)  
**Objective**: Effect-based dynamic dispatch  
**Success Metrics**:
- `dispatch` effect with routing handler
- `not-found` effect with fallback handler
- `metrics` effect for telemetry
- Composable middleware via effects

**Clone Assignment**: KOKA-SPEC-02 (shared with VC-2)

### VC-8: Koka-Python Bridge Infrastructure (Priority: CRITICAL)
**Objective**: FFI bridge for Koka ↔ Python interop  
**Success Metrics**:
- C FFI generation from Koka
- Python ctypes bindings
- Effect marshalling across boundary
- Build integration (kkc compiler)

**Clone Assignment**: KOKA-SPEC-07 (Infrastructure)

---

## Shadow Clone Army Composition

### Clone Squad Alpha (Effect System Core)
| Clone ID | Role | Assignment | Specialization |
|----------|------|------------|----------------|
| KOKA-LEAD-01 | Squad Lead | VC-1, Coordination | Effect architecture |
| KOKA-SPEC-01 | Specialist | VC-1 Grimoire | Effect handlers |
| KOKA-SPEC-02 | Specialist | VC-2,7 API/Dispatch | Composable handlers |
| KOKA-SPEC-03 | Specialist | VC-3 Dharma | Rule effects |
| KOKA-SPEC-04 | Specialist | VC-4 Orchestration | Pipeline effects |

### Clone Squad Beta (Runtime & Infrastructure)
| Clone ID | Role | Assignment | Specialization |
|----------|------|------------|----------------|
| KOKA-LEAD-02 | Squad Lead | VC-5-8 Coordination | Runtime design |
| KOKA-SPEC-05 | Specialist | VC-5 MCP Runtime | Async effects |
| KOKA-SPEC-06 | Specialist | VC-6 Gnosis | Tool effects |
| KOKA-SPEC-07 | Specialist | VC-8 Bridge | FFI/Build |

---

## Complete Target Registry (Top 40 of 636)

| Rank | File | LOC | Score | Primary Effects | Assigned Clone |
|------|------|-----|-------|-----------------|----------------|
| 1 | `whitemagic/grimoire/chapters.py` | 789 | 21 | effect, handler, resume | KOKA-SPEC-01 |
| 2 | `scripts/python_scout.py` | 366 | 21 | effect, handler, resume | KOKA-LEAD-01 |
| 3 | `whitemagic/tools/unified_api.py` | 544 | 15 | effect, handler, exception | KOKA-SPEC-02 |
| 4 | `whitemagic/dharma/rules.py` | 639 | 14 | effect, exception, with | KOKA-SPEC-03 |
| 5 | `whitemagic/core/orchestration/session_startup.py` | 676 | 14 | effect, resume, control | KOKA-SPEC-04 |
| 6 | `whitemagic/run_mcp_lean.py` | 523 | 13 | handler, resume, exception | KOKA-SPEC-05 |
| 7 | `whitemagic/tools/gnosis.py` | 571 | 13 | effect, handler, exception | KOKA-SPEC-06 |
| 8 | `whitemagic/tools/dispatch_table.py` | 748 | 13 | handler, resume, exception | KOKA-SPEC-02 |
| 9 | `whitemagic/core/consciousness/coherence.py` | 312 | 12 | effect, state, control | KOKA-SPEC-01 |
| 10 | `whitemagic/core/bridge/adaptive.py` | 398 | 12 | effect, handler, exception | KOKA-SPEC-02 |
| 11 | `whitemagic/core/continuity.py` | 289 | 12 | effect, state, io | KOKA-SPEC-04 |
| 12 | `whitemagic/grimoire/recommend.py` | 246 | 12 | effect, handler, exception | KOKA-SPEC-01 |
| 13 | `scripts/deploy_polyglot_optimization_armies.py` | 784 | 12 | effect, handler, resume | KOKA-SPEC-04 |
| 14 | `scripts/grand_evolution_campaign.py` | 1001 | 12 | effect, exception, with | KOKA-SPEC-04 |
| 15 | `whitemagic/core/memory/consolidation.py` | 761 | 11 | effect, exception, with | KOKA-SPEC-01 |
| 16 | `whitemagic/core/memory/unified.py` | 811 | 11 | effect, handler, exception | KOKA-SPEC-02 |
| 17 | `whitemagic/cascade/advanced_parallel.py` | 374 | 11 | effect, handler, control | KOKA-SPEC-04 |
| 18 | `scripts/execute_clone_campaign.py` | 445 | 11 | effect, exception, with | KOKA-SPEC-04 |
| 19 | `scripts/deploy_grand_army.py` | 3644 | 11 | effect, handler, exception | KOKA-SPEC-04 |
| 20 | `whitemagic/tools/selfmodel.py` | 467 | 11 | effect, state, resume | KOKA-SPEC-06 |

**Note**: Remaining 596 targets (171,000 LOC) are in `reports/python_scout_campaign.md` and will be assigned to Clone Squads Gamma-Omega in Phases 2-4.

---

## Effect Migration Patterns

### Python Decorator → Koka Effect Handler
```python
# Python (decorator chain)
@log_calls
@retry_on_error
@require_auth
def api_call():
    return http.get("/api/data")
```

```koka
// Koka (composable handlers)
fun api-call(): io maybe<error,data>
  with log-calls
  with retry-on-error(max=3)
  with require-auth
  http.get("/api/data")
```

### Python Exception → Koka Checked Effect
```python
# Python (runtime exception)
def parse_config():
    try:
        return json.load(file)
    except JSONDecodeError:
        return default_config
```

```koka
// Koka (checked effect)
fun parse-config(): <config,json-error> config
  with default-on-error(default-config)
  json/load(file)
```

### Python Context Manager → Koka Resource Effect
```python
# Python (context manager)
with database.connection() as conn:
    conn.execute(query)
```

```koka
// Koka (resource effect)
fun query-db(query): <db,dispose> result
  with db-connection
  execute(query)
```

---

## Implementation Strategy

### Phase 1: Effect System Foundations (Weeks 1-2)
- [ ] Install Koka compiler (v3.1.2+)
- [ ] Establish `koka-clones/` project structure
- [ ] Create effect standard library
  - `std/effects/io` - Console/file I/O
  - `std/effects/http` - HTTP client/server
  - `std/effects/state` - Mutable state
  - `std/effects/exception` - Error handling
  - `std/effects/log` - Structured logging
- [ ] VC-8: FFI bridge to Python

### Phase 2: Core Migration (Weeks 3-5)
- [ ] VC-1: Grimoire chapters (effect handlers)
- [ ] VC-2: Unified API (composable effects)
- [ ] VC-3: Dharma rules (exception effects)
- [ ] VC-4: Session startup (pipeline effects)
- [ ] Handler testing suite

### Phase 3: Runtime Migration (Weeks 5-7)
- [ ] VC-5: MCP Lean (async effects)
- [ ] VC-6: Gnosis tools (discovery effects)
- [ ] VC-7: Dispatch table (routing effects)
- [ ] Integration testing

### Phase 4: Mass Migration (Weeks 7-8)
- [ ] Automated migration tool (decorator → effect)
- [ ] Remaining 596 targets (Squads Gamma-Omega)
- [ ] Performance benchmarking
- [ ] Documentation

---

## Dependencies & Prerequisites

**Required**:
- Koka v3.1.2+ (compiler)
- Node.js 18+ (Koka build dependency)
- C compiler (gcc/clang for C backend)
- Python 3.10+ (for FFI testing)
- CMake 3.20+ (for build system)

**Toolchain**:
- `kkc` (Koka compiler)
- `koka --target=c` (C code generation)
- `ctypes` (Python FFI)

---

## Risk Assessment

| Risk | Likelihood | Impact | Mitigation |
|------|------------|--------|------------|
| Koka ecosystem immaturity | High | Medium | Contribute patches, use stable features |
| FFI complexity | Medium | High | C FFI vs direct bindings |
| Developer learning curve | High | Medium | Training, effect pattern library |
| Performance overhead | Low | Medium | Benchmark early, optimize hot paths |

---

## Success Metrics (Campaign Level)

- **Type Safety**: 100% effect coverage on migrated code
- **Composability**: All handlers compose without conflicts
- **Performance**: <10% overhead vs Python (optimization mode)
- **Coverage**: Top 40 targets (25,000 LOC) in Phase 1-3
- **LOC Impact**: 25,000 Python LOC → Koka (9% reduction)

---

## Koka Project Structure

```
koka-clones/
├── std/
│   └── effects/
│       ├── io.kk
│       ├── http.kk
│       ├── state.kk
│       ├── exception.kk
│       └── log.kk
├── grimoire/
│   └── chapters.kk        # VC-1
├── tools/
│   ├── unified-api.kk      # VC-2
│   ├── gnosis.kk           # VC-6
│   └── dispatch-table.kk   # VC-7
├── dharma/
│   └── rules.kk            # VC-3
├── core/
│   └── session-startup.kk  # VC-4
├── runtime/
│   └── mcp-lean.kk         # VC-5
├── ffi/
│   └── python-bridge.kk    # VC-8
├── kk.project              # Koka project file
└── README.md
```

---

## Effect Standard Library

### Core Effects
```koka
// I/O Effect
pub effect io
  fun print(s: string): ()
  fun read-line(): string

// State Effect
pub effect state<s>
  fun get(): s
  fun put(s: s): ()

// Exception Effect
pub effect excpt<e>
  fun throw(e: e): a

// HTTP Effect
pub effect http
  fun get(url: string): response
  fun post(url: string, body: string): response

// Log Effect
pub effect log
  fun info(msg: string): ()
  fun error(msg: string): ()
```

---

## Next Actions

1. **Install Koka compiler** (v3.1.2+)
2. **Deploy Squad Alpha** to VC-1 (Grimoire chapters)
3. **Design effect standard library** (io, http, state, exception, log)
4. **Implement FFI bridge** (VC-8)
5. **Begin Phase 1** effect system foundations

**Campaign Ready for Execution** ✅

**Note**: This is the largest campaign by file count (636 files). Success here establishes effect-based programming patterns across the entire WhiteMagic ecosystem.
