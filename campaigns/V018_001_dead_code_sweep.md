# Campaign V018-001: The Great Dead Code Sweep — Phase Final

**Campaign Codename**: BROOMSTICK  
**Objective**: Archive 120 confirmed dead code files (19,576 LOC) to `_archives/dead_code_v018/`  
**Estimated Impact**: 19,576 LOC removed | 120 files | Python ↓ to ~15% of total  
**Shadow Clone Composition**: 5 Specialist Clones  
**Estimated Duration**: 2-3 days with parallel verification  
**Depends On**: None (self-contained)  
**Priority**: P1 — Foundation  

---

## Strategic Overview

V001 Census identified **120 files with 0 importers and no `__main__` block** — confirmed dead code totaling 19,576 LOC. These files have been sitting untouched, creating:
- Import graph noise (1,148 nodes, many disconnected)
- Cognitive overhead for developers
- False positive search results
- Maintenance burden for dead functionality

**The Sweep**: Not deletion — archival. All files move to `_archives/dead_code_v018/` with:
- Full git history preserved
- Import guard shims for graceful degradation
- Archive manifest for potential restoration
- Category-tagged for future archaeological digs

**Top 10 Targets by LOC**:
| File | LOC | Category |
|------|-----|----------|
| `scripts/execute_grand_campaign.py` | 761 | scripts |
| `scripts/grand_evolution_campaign.py` | 700 | scripts |
| `whitemagic/core/immune/security_integration.py` | 501 | immune_security |
| `scripts/art_of_war_reconnaissance.py` | 480 | scripts |
| `scripts/evolution_deep_reconnaissance.py` | 472 | scripts |
| `whitemagic/tools/handlers/war_room.py` | 453 | tools_handlers |
| `scripts/phase2_deep_analysis.py` | 425 | scripts |
| `whitemagic/tools/handlers/pattern_engines.py` | 420 | tools_handlers |
| `scripts/phase3_synthesis.py` | 414 | scripts |
| `scripts/total_war_victory.py` | 397 | scripts |

---

## Victory Conditions (VCs)

### VC-1: Pre-Archive Verification Sweep (Priority: CRITICAL)
**Objective**: Re-verify all 120 files are truly unreferenced  
**Success Metrics**:
- [ ] Re-run AST import analysis on all 120 files
- [ ] Confirm zero runtime imports (not just static)
- [ ] Identify any `__init__.py` re-export chains missed by V001
- [ ] Flag files with potential transitive dependencies
- [ ] Generate verification report: `reports/v018_dead_code_verification.md`

**Clone Assignment**: BROOM-LEAD-01 (Analysis specialist)

### VC-2: Archive Infrastructure Setup (Priority: CRITICAL)
**Objective**: Create archival structure with full provenance  
**Success Metrics**:
- [ ] Create `_archives/dead_code_v018/` with category subdirs
- [ ] Design archive manifest schema (JSON) with:
  - Original path, module name, LOC
  - Category, bio_subsystem tags
  - Last modified date, reason for archival
  - Restoration instructions
- [ ] Create import guard shim template
- [ ] Set up archive index for quick search

**Clone Assignment**: BROOM-SPEC-01 (Infrastructure)

### VC-3: Batch Archive Execution (Priority: HIGH)
**Objective**: Move all 120 files to archive with shims  
**Success Metrics**:
- [ ] Move files preserving directory structure in archive
- [ ] Create import guard shims in original locations:
  ```python
  # Shim pattern
  try:
      from _archives.dead_code_v018.original.module import *
  except ImportError:
      pass  # Module archived in v018
  ```
- [ ] Update any `__init__.py` files that re-export archived modules
- [ ] Run full import test: `scripts/wm -c "import whitemagic"`
- [ ] Zero import errors post-archive

**Clone Assignment**: BROOM-SPEC-02 (Migration specialist)

### VC-4: Post-Archive Cleanup (Priority: HIGH)
**Objective**: Clean up references, update docs, verify tests pass  
**Success Metrics**:
- [ ] Remove archived modules from any dispatch tables
- [ ] Update any hardcoded path references
- [ ] Update `skip_patterns` in census if needed
- [ ] Re-run V001 census, verify new counts
- [ ] Run test suite: 2,280 tests must still pass
- [ ] Update CHANGELOG with archived file list

**Clone Assignment**: BROOM-SPEC-03 (Cleanup specialist)

### VC-5: Restoration Capability (Priority: MEDIUM)
**Objective**: Ensure any archived file can be restored if needed  
**Success Metrics**:
- [ ] Create `scripts/restore_archived_module.py` CLI tool
- [ ] Tool accepts module path, validates safe to restore
- [ ] Tool moves from archive back to original location
- [ ] Tool removes shim, updates manifest
- [ ] Document restoration procedure

**Clone Assignment**: BROOM-SPEC-04 (Tooling)

---

## Verification

**Success Criteria**:
- Python LOC: 217,166 → ~197,590 (verified by re-run census)
- Import graph nodes: 1,148 → ~1,028
- All 2,280 tests still pass
- No runtime import errors
- Archive manifest complete and searchable

**Failure Recovery**:
- Full git history preserved
- Restoration tool ready
- Shim pattern allows graceful degradation

---

*Campaign BROOMSTICK — v18 Foundation Phase*
