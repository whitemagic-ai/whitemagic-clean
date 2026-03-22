# WhiteMagic Release Execution Board

## Program Status

- **Program**: Whitemagic Release Readiness
- **Labs**: `whitemagicdev`
- **Core**: `whitemagicpublic`
- **Current active phase**: Phase 2 — State-Root, Portability, and Filesystem Hygiene
- **Execution pattern**: one primary phase at a time, with recon -> implement -> verify -> record -> gate review

## Phase Status Board

- [x] **Phase 0 — Program Governance and Labs/Core Charter**
  - [x] Add and revise `docs/RELEASE_READINESS_PROGRAM.md`
  - [x] Ratify Labs/Core framing in strategy
  - [x] Add `docs/LABS_CORE_CHARTER.md`
  - [x] Add `docs/RELEASE_EXECUTION_BOARD.md`
  - [x] Define Core eligibility rules in operational form for promotions and preflight
  - [x] Snapshot current blocker register for active execution
  - [x] Gate review and close Phase 0

- [ ] **Phase 1 — Canonical Truth and Documentation Convergence**
  - [ ] Reconcile top-level docs and version narrative
  - [ ] Normalize tool/capability claims against live code
  - [ ] Explain Labs/Core relationship in public-facing docs
  - [ ] Create a canonical release-note baseline

- [ ] **Phase 2 — State-Root, Portability, and Filesystem Hygiene**
  - [ ] Inventory all path bypasses and home-directory fallbacks
  - [ ] Route writable state through `whitemagic/config/paths.py`
  - [ ] Remove hard-coded personal paths from ship code
  - [ ] Add state-root tests and path-leak checks

- [ ] **Phase 3 — Ship Surface Cleanup**
  - [ ] Classify top-level surfaces as Core, Labs, or runtime state
  - [ ] Quarantine non-shipping helper and repair artifacts
  - [ ] Tighten ignore, manifest, and packaging rules
  - [ ] Add release preflight for ship-surface contamination

- [ ] **Phase 4 — Memory Governance and Public Data Policy**
  - [ ] Separate Labs operational memory from Core sample memory
  - [ ] Define public memory policy
  - [ ] Decide curated sample corpus vs no shipped data
  - [ ] Add retrieval-quality benchmark plan

- [ ] **Phase 5 — Tool Surface Stabilization**
  - [ ] Define Core vs Labs tool eligibility
  - [ ] Audit overlapping dispatch layers
  - [ ] Generate live tool inventory
  - [ ] Document extension contract and release profiles

- [ ] **Phase 6 — Testing, CI, and Packaging**
  - [ ] Define Core validation lane
  - [ ] Separate core tests from optional polyglot tests
  - [ ] Add release smoke tests
  - [ ] Add packaging and hygiene validation

- [ ] **Phase 7 — Public Docs, Positioning, and Onboarding**
  - [ ] Create plain-language positioning layer
  - [ ] Create Core-first quickstart and onboarding path
  - [ ] Separate optional depth from required onboarding
  - [ ] Clarify contributor path and architecture views

- [ ] **Phase 8 — Labs -> Core Promotion Pipeline Engineering**
  - [ ] Put Labs under private Git provenance
  - [ ] Define promotion manifest and exclusion rules
  - [ ] Automate export, preflight, and diff review
  - [ ] Tag releases only from Core

- [ ] **Phase 9 — Release Candidate and Launch Operations**
  - [ ] Cut and validate release candidate
  - [ ] Dry-run Labs -> Core -> GitHub publish
  - [ ] Cold-start review and issue-template readiness
  - [ ] Post-launch governance defined

- [ ] **Phase 10 — Benchmark Gauntlet, Comparative Analysis, and Tactical Guide**
  - [ ] Improve benchmark surfaces to match shipped reality
  - [ ] Run benchmark profiles and compare to prior evidence
  - [ ] Interpret metrics and implications
  - [ ] Write tactical guide for future AI maintainers

## Current Blocker Register

### Release-Critical Blockers

- [ ] **State-root leaks in ship code**
  - Known classes include hard-coded home paths, `Path.home()` fallbacks, and direct `~/.whitemagic` expansion outside the canonical path layer.
- [ ] **Noisy ship surface**
  - Labs contains logs, backups, local DBs, build outputs, models, helper scripts, and runtime residue that must not define Core.
- [ ] **Documentation drift**
  - Top-level docs currently disagree on version lines, tool counts, architecture framing, and release story.
- [ ] **Public memory posture is undefined**
  - The active operational memory corpus is noisy and cannot become the public memory story by default.
- [ ] **Tool contract is not yet sharply separated into Core vs Labs**
  - The live tool surface is broad and needs a stable public framing.
- [ ] **Labs lacks private Git provenance**
  - Core is Git-backed; Labs is not yet under equivalent source-of-truth discipline.
- [ ] **Benchmark story is present but not yet release-shaped**
  - Multiple gauntlet scripts and reports exist, but the canonical suite and comparison workflow need consolidation.

## Immediate Execution Queue

- [x] **Close Phase 0**
  - Convert charter policy into a practical operational checklist and phase-close summary.
- [ ] **Start Phase 2**
  - Patch known path/state-root leaks in ship code.
- [ ] **Start Phase 3**
  - Classify top-level Labs/Core/runtime-state surfaces.
- [ ] **Prepare Phase 8 dependency**
  - Define how Labs will gain private Git provenance.

## Phase 0 Artifacts

- `docs/RELEASE_READINESS_PROGRAM.md`
- `docs/LABS_CORE_CHARTER.md`
- `docs/RELEASE_EXECUTION_BOARD.md`
- `docs/CORE_PROMOTION_CHECKLIST.md`

## Phase Closure Rule

A phase is complete only when:

- its checklist items are materially satisfied
- durable artifacts exist in the repo
- verification has been performed
- the board has been updated
- the next phase has a clear starting condition
