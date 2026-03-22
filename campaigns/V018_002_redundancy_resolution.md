# Campaign V018-002: Redundancy Resolution Initiative

**Campaign Codename**: CONFLUENCE  
**Objective**: Analyze and merge 2,177 high-redundancy module pairs (≥60% import similarity)  
**Estimated Impact**: ~30,000+ LOC consolidated | 1,000+ files optimized | Import graph simplified  
**Shadow Clone Composition**: 8 Specialist Clones  
**Estimated Duration**: 1-2 weeks with conservative merging  
**Depends On**: V018-001 (clear dead code first)  
**Priority**: P1 — Foundation  

---

## Strategic Overview

V001 Census detected **2,177 pairs with ≥60% Jaccard import similarity** — modules importing largely the same dependencies, suggesting overlapping functionality or split responsibilities that could be unified.

**Why This Matters**:
- Import graph complexity: 2,838 edges, many redundant
- Maintenance overhead: 2,177 potential bug locations instead of ~1,000
- Cognitive load: developers face similar files repeatedly
- False modularity: split for no architectural reason

**The Approach**: Conservative, safety-first merging:
1. Analyze each pair with shadow clones (risk assessment)
2. Only merge when safe: no runtime conflicts, complementary functionality
3. Preserve all functionality in unified module
4. Update all importers automatically
5. Full test coverage before committing

**Top Redundancy Patterns**:
- Handler modules with shared tool imports (40% of pairs)
- Memory core utilities with overlapping sqlite patterns (25%)
- Script utilities with common CLI patterns (20%)
- Bridge/polyglot wrappers with identical FFI setups (15%)

---

## Victory Conditions (VCs)

### VC-1: Redundancy Pair Triage (Priority: CRITICAL)
**Objective**: Categorize all 2,177 pairs by merge safety  
**Success Metrics**:
- [ ] Sort pairs by similarity score (highest first)
- [ ] For top 500 pairs: detailed shadow clone analysis
- [ ] Classify each:
  - **SAFE**: Same functionality, split by accident → merge
  - **RELATED**: Overlapping but distinct → keep, document relationship
  - **FALSE_POSITIVE**: Similar imports but different purpose → dismiss
- [ ] Generate merge candidates list (target: 300-500 SAFE pairs)
- [ ] Report: `reports/v018_redundancy_triage.md`

**Clone Assignment**: CONFL-LEAD-01 + CONFL-SPEC-01 (Analysis team)

### VC-2: Merge Strategy Development (Priority: CRITICAL)
**Objective**: Design safe merge patterns for each merge type  
**Success Metrics**:
- [ ] Define merge patterns:
  - **Type A: Identical functionality** → keep one, redirect other
  - **Type B: Complementary functions** → unified module with both
  - **Type C: Split class methods** → unified class
- [ ] Create `scripts/merge_modules.py` automation tool
- [ ] Tool features:
  - AST-based merge (preserves docstrings, type hints)
  - Automatic import updater across codebase
  - Git commit generation with full diff
  - Rollback capability
- [ ] Test tool on 5 low-risk pairs

**Clone Assignment**: CONFL-SPEC-02 (Merge architect)

### VC-3: Conservative Merge Execution (Priority: HIGH)
**Objective**: Execute SAFE merges in batches of 50  
**Success Metrics**:
- [ ] Batch 1-5: 50 lowest-risk merges (simple utility modules)
- [ ] After each batch: full test suite must pass
- [ ] After each batch: census re-run to verify edge reduction
- [ ] Stop immediately if any batch causes test failures
- [ ] Target: 250 successful merges (12.5% of identified pairs)
- [ ] Document: `reports/v018_merge_batch_report.md`

**Clone Assignment**: CONFL-SPEC-03 + CONFL-SPEC-04 (Execution team)

### VC-4: Importer Update Automation (Priority: HIGH)
**Objective**: Update all import statements post-merge  
**Success Metrics**:
- [ ] For each merged pair: identify all files importing either module
- [ ] Automatically update imports to new unified location
- [ ] Handle `from X import Y` → `from NewX import Y` mappings
- [ ] Preserve `as` aliases and re-export chains
- [ ] Zero manual import fixes required

**Clone Assignment**: CONFL-SPEC-05 (Import refactoring)

### VC-5: Post-Merge Verification (Priority: HIGH)
**Objective**: Validate system integrity after all merges  
**Success Metrics**:
- [ ] Full test suite: 2,280 tests pass
- [ ] Import smoke test: all modules importable
- [ ] Census re-run: verify import graph edge reduction
- [ ] Performance smoke test: no regression in hot paths
- [ ] Documentation: which files merged, where functionality moved

**Clone Assignment**: CONFL-SPEC-06 (Verification)

### VC-6: Related-Pair Documentation (Priority: MEDIUM)
**Objective**: Document RELATED pairs that were kept separate  
**Success Metrics**:
- [ ] For 200+ RELATED pairs: create relationship docs
- [ ] Document why kept separate (architectural reason)
- [ ] Cross-reference in module docstrings
- [ ] Add to architecture guide

**Clone Assignment**: CONFL-SPEC-07 (Documentation)

### VC-7: False-Positive Cleanup (Priority: LOW)
**Objective**: Dismiss FALSE_POSITIVE pairs from future analysis  
**Success Metrics**:
- [ ] Maintain `reports/v018_redundancy_dismissed.json` with reasons
- [ ] Add census filter to ignore dismissed pairs in future runs
- [ ] Review periodically for changed circumstances

**Clone Assignment**: CONFL-SPEC-08 (Maintenance)

---

## Targets (Sample High-Similarity Pairs)

| File A | File B | Similarity | Category | Proposed Action |
|--------|--------|------------|----------|-----------------|
| `tools/handlers/memory.py` | `tools/handlers/galaxy.py` | 0.85 | handlers | Merge (same tool domain) |
| `core/memory/embeddings.py` | `core/memory/v17_embedding_optimizer.py` | 0.82 | memory | Keep (V17 is optimization layer) |
| `scripts/benchmark_gauntlet.py` | `scripts/benchmark_gauntlet_v2.py` | 0.91 | scripts | Merge (version consolidation) |
| `agents/campaign_loader.py` | `agents/campaign_metrics.py` | 0.78 | agents | Merge (campaign system unified) |
| `core/bridge/rust_bridge.py` | `core/acceleration/rust_unified.py` | 0.88 | bridge | Merge (rust integration unified) |

---

## Risk Mitigation

**Merge Risk Levels**:
- 🟢 **LOW**: Utility scripts, handlers, non-core modules
- 🟡 **MEDIUM**: Memory core utilities, bridge modules
- 🔴 **HIGH**: Intelligence engines, dream cycle, consolidation

**Stop Conditions**:
- Any test failure in a merge batch → halt, investigate, rollback
- Performance regression >5% → halt, profile
- Import cycle introduced → halt, redesign

---

*Campaign CONFLUENCE — v18 Foundation Phase*
