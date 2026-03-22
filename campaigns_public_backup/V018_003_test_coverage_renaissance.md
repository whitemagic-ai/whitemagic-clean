# Campaign V018-003: Test Coverage Renaissance

**Campaign Codename**: AEGIS  
**Objective**: Expand test coverage from 3.4% → 25% via auto-generation + manual critical path coverage  
**Estimated Impact**: 250+ new test files | 3,000+ new test cases | CI reliability ↑  
**Shadow Clone Composition**: 6 Specialist Clones  
**Estimated Duration**: 3-4 weeks (auto-gen fast, manual review slow)  
**Depends On**: V018-001, V018-002 (clean codebase first)  
**Priority**: P2 — Infrastructure  

---

## Strategic Overview

Current test coverage: **3.4% of files** (39/1,148 Python files). Critical gaps:
- Memory core: 6/84 files tested (7.1%)
- Intelligence: 5/84 files tested (6.0%)
- Gardens: 2/68 files tested (2.9%)
- Scripts: 0/337 files tested (0%)

**The Goal**: 25% coverage by v18.0.0 release — 286 files with tests.

**Dual Strategy**:
1. **Auto-Generated (70%)**: From docstrings, type hints, existing examples
2. **Manual Critical (30%)**: Hot paths, edge cases, integration flows

**Coverage Priority**:
| Tier | Files | Target Coverage | Method |
|------|-------|-----------------|--------|
| T1 | Memory core, Intelligence | 60% | Manual + auto |
| T2 | Tools, Gardens, Agents | 40% | Auto + spot checks |
| T3 | Scripts, Eval | 15% | Auto only |
| T4 | Uncategorized, CLI | 10% | Auto only |

---

## Victory Conditions (VCs)

### VC-1: Auto-Generation Pipeline (Priority: CRITICAL)
**Objective**: Build tool that generates tests from code analysis  
**Success Metrics**:
- [ ] Create `scripts/generate_tests.py` with modes:
  - `--from-docstrings`: Extract examples, make pytest cases
  - `--from-types`: Generate boundary tests from type hints
  - `--from-signatures`: Create mock/stub tests for all public functions
- [ ] Support docstring formats: Google, NumPy, reStructuredText
- [ ] Generate tests for 500+ untested files
- [ ] Output: `tests/auto_generated/` organized by category
- [ ] All generated tests are runnable (may fail, but execute)

**Clone Assignment**: AEGIS-LEAD-01 + AEGIS-SPEC-01 (Tooling team)

### VC-2: Memory Core Critical Coverage (Priority: CRITICAL)
**Objective**: Manual test coverage for memory hot paths  
**Success Metrics**:
- [ ] Target files:
  - `core/memory/unified.py` (811 LOC) — unified memory interface
  - `core/memory/sqlite_backend.py` (600+ LOC) — DB operations
  - `core/memory/consolidation.py` (761 LOC) — dream cycle engine
  - `core/memory/embeddings.py` (943 LOC) — embedding pipeline
  - `core/memory/galactic_map.py` (500+ LOC) — holographic coords
- [ ] 60% line coverage per file
- [ ] Integration tests: store → embed → search → retrieve
- [ ] Edge cases: null fields, corrupted data, concurrent access
- [ ] Mock external dependencies (no real DB needed for unit tests)

**Clone Assignment**: AEGIS-SPEC-02 (Memory testing specialist)

### VC-3: Intelligence Engine Coverage (Priority: HIGH)
**Objective**: Test coverage for pattern/intelligence systems  
**Success Metrics**:
- [ ] Target files:
  - `core/intelligence/graph_walker.py` — graph traversal
  - `core/intelligence/constellation_detector.py` — clustering
  - `core/intelligence/association_miner.py` — pattern mining
  - `core/patterns/` directory — all pattern engines
- [ ] 50% line coverage per file
- [ ] Property-based tests for graph algorithms
- [ ] Fuzz tests for pattern matching
- [ ] Mock embedding models for deterministic tests

**Clone Assignment**: AEGIS-SPEC-03 (Intelligence testing)

### VC-4: Garden Ecosystem Coverage (Priority: HIGH)
**Objective**: Test coverage for 28 Gana garden modules  
**Success Metrics**:
- [ ] Target: 20/68 garden files (priority Ganas)
  - `gardens/gana_neck.py` — memory creation
  - `gardens/gana_winnowing_basket.py` — search
  - `gardens/gana_three_stars.py` — reasoning
  - `gardens/gana_void.py` — galaxy management
- [ ] 40% line coverage per file
- [ ] Test tool dispatch → handler → result flow
- [ ] Mock MCP context for garden isolation
- [ ] Property: all 375 tools have at least one test path

**Clone Assignment**: AEGIS-SPEC-04 (Garden testing)

### VC-5: Integration Test Expansion (Priority: HIGH)
**Objective**: End-to-end tests for critical user flows  
**Success Metrics**:
- [ ] Flow: `memory.create` → `search.hybrid` → `galaxy.ingest` → `dream.cycle`
- [ ] Flow: `ollama.generate` with context injection
- [ ] Flow: Full LoCoMo question → answer validation
- [ ] Flow: Campaign deployment → clone execution → victory report
- [ ] All flows run in <30 seconds
- [ ] Run in CI with fresh DB (no state leakage)

**Clone Assignment**: AEGIS-SPEC-05 (Integration testing)

### VC-6: Coverage Reporting & CI Integration (Priority: MEDIUM)
**Objective**: Track coverage metrics in CI, block regression  
**Success Metrics**:
- [ ] Integrate pytest-cov for coverage reporting
- [ ] Coverage gate: PRs cannot decrease coverage
- [ ] Badge in README: current coverage %
- [ ] Weekly coverage report: `reports/coverage_weekly.md`
- [ ] Coverage diff in PR comments

**Clone Assignment**: AEGIS-SPEC-06 (CI/DevOps)

---

## Test Generation Strategy

**From Docstrings**:
```python
def store_memory(content: str, tags: list[str]) -> str:
    """Store a memory.
    
    Example:
        >>> store_memory("test", ["test"])
        "mem_abc123"
    """
```
→ Generate:
```python
def test_store_memory_basic():
    result = store_memory("test", ["test"])
    assert result.startswith("mem_")
```

**From Type Hints**:
```python
def encode_batch(texts: list[str], batch_size: int = 32) -> np.ndarray:
```
→ Generate:
```python
def test_encode_batch_types():
    # Boundary: empty list
    # Boundary: single item
    # Boundary: batch_size variations
    # Type: returns ndarray
```

---

## Metrics

**Current State**:
- Files with tests: 39/1,148 (3.4%)
- Total tests: 2,280
- Test LOC: 13,809

**Target State (v18.0.0)**:
- Files with tests: 286/1,148 (25%)
- Total tests: 5,000+
- Test LOC: 40,000+

**Stretch Goal (v18.1.0)**:
- Coverage: 40%
- Critical path: 80% coverage

---

*Campaign AEGIS — v18 Infrastructure Phase*
