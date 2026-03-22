# WhiteMagic Release Readiness Program

## Purpose

This document turns the current audit findings into a phased release program for bringing **Whitemagic Labs** (`whitemagicdev`) and **Whitemagic Core** (`whitemagicpublic`) into a disciplined release relationship and defining a reliable promotion path from Labs to Core to GitHub.

The goal is not only to clean the repositories, but to make Whitemagic legible, portable, safe, and credible as an open-source project while preserving a healthy space for research, experimentation, and evolution.

## Current Baseline

- `whitemagicdev` is **Whitemagic Labs**, the active development and research tree, and is not currently a Git checkout.
- `whitemagicpublic` is **Whitemagic Core**, the Git-backed staging/publishing tree on `main` with remote `origin = https://github.com/whitemagic-ai/whitemagic-clean.git`.
- `whitemagicpublic` is cleaner than `whitemagicdev`, but it still contains local or release-noisy surfaces such as `.claude/`, `.windsurf/`, `.coverage`, `dist/`, `logs/`, `tmp/`, `.mcp.json`, and failure logs.
- `whitemagicdev` currently contains substantial local/runtime/build residue, including `.venv/`, `_memories/`, `memory/`, `models/`, `target/`, large logs, patch scripts, test artifacts, and backup archives.
- Public-facing documentation currently drifts across version numbers, capability counts, and architectural framing.
- State-root policy exists in `whitemagic/config/paths.py`, but some code paths still bypass it via hard-coded home paths or ad hoc `Path.home()` / `expanduser()` fallbacks.
- The active runtime memory corpus is dominated by quarantined material, which makes the public memory story weak unless a curated export path is defined.
- Live code currently exposes a very large tool surface, with hundreds of dispatch entries and PRAT mappings; public documentation should not rely on stale hand-maintained counts.

## Program Model: Labs and Core

- `whitemagicdev` is **Labs**
  - Private, high-context, higher-entropy development space.
  - May contain research material, experiments, archives, migration scaffolding, campaign outputs, and work-in-progress remediation.
- `whitemagicpublic` is **Core**
  - Sanitized, Git-backed public contract and release staging space.
  - Should contain only approved source, docs, tests, packaging, and release assets.
- Runtime state is **neither Labs nor Core**
  - DBs, memories, logs, caches, models, temporary outputs, and local campaign residue should live outside the shipping surface whenever possible.
- Promotion flows one way
  - Labs -> Core -> GitHub.
- Core must be intentionally smaller and calmer than Labs
  - If something is powerful but not yet legible, stable, portable, or governable, it stays in Labs.

## Release Principles

- [ ] **Code is the final authority**
  - Public docs should follow live code and generated inventories where possible.
- [ ] **Runtime state stays out of the repo**
  - All writable state should resolve through `WM_STATE_ROOT` or explicitly documented opt-in paths.
- [ ] **Stable contract before maximal scope**
  - The public release should present the smallest stable surface that still captures Whitemagic's identity.
- [ ] **Research and product surfaces are separated**
  - Experimental subsystems, one-off scripts, archives, and local campaign artifacts should not define the public release.
- [ ] **Core is smaller than Labs by design**
  - Core should optimize for clarity, stability, portability, and public trust; Labs can remain broader and more exploratory.
- [ ] **Promotion must be reproducible**
  - Movement from `whitemagicdev` to `whitemagicpublic` should be deterministic and auditable.
- [ ] **Memory and privacy are first-class release concerns**
  - Public data, sample memory, and state-root behavior must be intentionally curated.

- [ ] **Generated truth beats stale hand counts**
  - Tool inventories, capability counts, release manifests, and ship-surface checks should be derived from code where possible.
- [ ] **Plain language comes before symbolic depth**
  - Public onboarding should explain the practical value first, then invite users into the Grimoire, Ganas, and deeper architecture.
- [ ] **Extensions must be first-class and governable**
  - The extension model should be documented, versioned, and safe enough to be part of the public story.

## Execution Doctrine

- [ ] **One primary phase is active at a time**
  - Supporting tasks from other phases are allowed only when they directly unblock the active phase.
- [ ] **Every phase follows the same loop**
  - Recon -> Implement -> Verify -> Record -> Gate review.
- [ ] **Every phase leaves durable artifacts**
  - Code, tests, preflight rules, docs deltas, and a short phase summary should land before advancing.
- [ ] **Core promotion follows proof, not intent**
  - Nothing moves from Labs to Core without diff review and passing preflight.
- [ ] **Automation is bounded and reviewable**
  - MCP tools, Grimoire-guided workflows, and army-style batch analysis are encouraged for scouting, inventorying, code generation, and QA, but release-bound changes must remain reviewable and reversible.
- [ ] **Major narrative rewrites trail structural stabilization**
  - Public-facing docs should describe the system that actually ships, not the system we hope to ship later.
- [ ] **Completed phases stay closed unless a regression reopens them**
  - Once a phase meets exit criteria, it stays complete unless new evidence reveals a blocker or regression.

## Refinement Agenda

- [ ] **Strengthen the Labs/Core split**
  - Give each repo a distinct role, eligibility policy, and success criteria.
- [ ] **Generate truth from code**
  - Replace stale hand-maintained counts and inventories with generated artifacts where possible.
- [ ] **Build a gold-standard extension story**
  - Make the manifest and forge model legible, documented, versioned, and safely extensible.
- [ ] **Measure retrieval quality explicitly**
  - Evaluate recall, contamination, and public sample quality with repeatable benchmarks.
- [ ] **Present Whitemagic in two layers**
  - Plain-language onboarding first; deeper Grimoire, Gana, and research material second.

## Stop-the-Line Blockers

The following issues should block public release until resolved:

- [ ] **Missing Labs/Core boundary**
  - It must be clear whether an artifact belongs in Labs, Core, or runtime state.
- [ ] **Documentation drift**
  - Resolve contradictory version claims, tool counts, and architecture descriptions across `README.md`, `ABOUT.md`, `AI_PRIMARY.md`, `SYSTEM_MAP.md`, `SYSTEM_ARCHITECTURE.md`, and audit reports.
- [ ] **State-root leaks**
  - Remove hard-coded or bypass path logic that ignores `whitemagic/config/paths.py`.
- [ ] **Noisy ship surface**
  - Eliminate build outputs, logs, DB files, local archives, models, and helper residue from the release tree.
- [ ] **Unclear public memory posture**
  - Define what memory data is public, what is private, and what sample corpus ships, if any.
- [ ] **Unclear canonical tool contract**
  - Stabilize the public tool surface and clearly distinguish stable from experimental endpoints.
- [ ] **Weak provenance in development tree**
  - `whitemagicdev` should gain a private Git-backed workflow or equivalent source-of-truth discipline.

- [ ] **Underspecified extension surface**
  - The public extension story needs stable documentation, safety expectations, and versioning.
- [ ] **Unproven retrieval quality**
  - Memory quality is central to the project identity and should be measured, not assumed.

## Phase 0: Program Governance and Labs/Core Charter

### Objectives

- Ratify the Labs/Core model.
- Define the release target and allowed scope.
- Create a single operating board and gating model for release work.

### Checklist

- [ ] **Ratify the Labs/Core charter**
  - Confirm `whitemagicdev` as Labs and `whitemagicpublic` as Core, and write down the responsibilities of each.
- [ ] **Name the release target**
  - Decide whether this is a private release candidate, a public alpha, or a general open-source launch.
- [ ] **Choose the canonical public identity**
  - Confirm project name, version line, license, support channels, and public repo destination.
- [ ] **Define Core eligibility rules**
  - Specify what kinds of code, docs, assets, data, and tooling are allowed into Core.
- [ ] **Define Labs-only categories**
  - Identify what remains experimental, internal, research-oriented, or operational.
- [ ] **Create a release board**
  - Track blockers by category: docs, code, memory, packaging, CI, governance, Labs/Core boundary, and publishing.
- [ ] **Freeze non-release feature work**
  - Limit changes to release-critical cleanup, stabilization, documentation, and tests.
- [ ] **Snapshot the current baseline**
  - Record current counts, current docs set, current public repo state, and known blockers.

### Exit Criteria

- [ ] **The Labs/Core boundary is documented**
- [ ] **A defined release target exists**
- [ ] **A blocker list exists**
- [ ] **The team knows what is in scope and out of scope**

## Phase 1: Canonical Truth and Documentation Convergence

### Objectives

- Make the project's self-description internally consistent.
- Establish one canonical reading path for new contributors and AI runtimes.

### Checklist

- [ ] **Define canonical doc order**
  - Recommended order: `whitemagic/grimoire/00_PROLOGUE.md` -> `AI_PRIMARY.md` -> `SYSTEM_MAP.md` -> `README.md`.
- [ ] **Document the Labs/Core split**
  - Explain how Whitemagic Labs and Whitemagic Core relate, and what users and contributors should expect from each surface.
- [ ] **Create one current-version narrative**
  - Decide what release family the repo is actually in now and update all top-level docs accordingly.
- [ ] **Normalize tool and capability claims**
  - Either generate counts from code or remove brittle numeric claims from user-facing docs.
- [ ] **Differentiate stable vs research surfaces**
  - Mark which subsystems are public contract, which are optional accelerators, and which are experimental.
- [ ] **Collapse duplicated architectural narratives**
  - Reduce contradictions across `README.md`, `ABOUT.md`, `SYSTEM_ARCHITECTURE.md`, `ARCHITECTURE.md`, and strategy reports.
- [ ] **Create a public release note baseline**
  - Summarize what the project is, what is stable, and what is intentionally not part of the public contract.

### Exit Criteria

- [ ] **A new reader can understand Whitemagic without contradiction**
- [ ] **No public doc claims obviously conflict with live code**
- [ ] **The stable contract is explained in one place**
- [ ] **The Labs/Core relationship is clearly explained**

## Phase 2: State-Root, Portability, and Filesystem Hygiene

### Objectives

- Enforce the runtime-state policy everywhere.
- Remove user-specific or machine-specific storage assumptions.

### Checklist

- [ ] **Audit all path bypasses**
  - Search for `Path.home()`, `expanduser("~/.whitemagic")`, hard-coded `/home/`, hard-coded `/Users/`, and direct DB path literals.
- [ ] **Replace direct fallbacks with centralized path resolution**
  - Route writable state through `whitemagic/config/paths.py`.
- [ ] **Eliminate hard-coded user paths**
  - Fix known hotspots such as ledger persistence and ad hoc memory DB fallbacks.
- [ ] **Define allowed exceptions**
  - If any path may intentionally escape `WM_STATE_ROOT`, document and guard it explicitly.
- [ ] **Add tests for state-root behavior**
  - Verify default state root, custom `WM_STATE_ROOT`, and no accidental repo writes.
- [ ] **Add a path leak preflight**
  - Fail release prep when source files contain disallowed machine-local path assumptions.

### Exit Criteria

- [ ] **All writable runtime state resolves through the canonical path layer**
- [ ] **No source-level hard-coded personal paths remain in ship code**
- [ ] **State-root behavior is test-covered**

## Phase 3: Ship Surface Cleanup

### Objectives

- Make the release tree clean, intentional, and reproducible.
- Separate product assets from local work residue.

### Checklist

- [ ] **Classify the top-level tree**
  - Tag each top-level directory or asset as Core, Labs, or runtime state.
- [ ] **Define the Core ship surface**
  - Decide which top-level directories are part of Core and which remain Labs-only.
- [ ] **Purge local residue from the release path**
  - Remove or exclude logs, DB files, backups, temporary outputs, models, benchmark dumps, generated binaries, and build directories.
- [ ] **Quarantine one-off helper scripts**
  - Move `patch_*`, `fix_*`, emergency repair scripts, and investigation artifacts into a clearly non-shipping area.
- [ ] **Tighten ignore and packaging rules**
  - Audit `.gitignore`, `.dockerignore`, `MANIFEST.in`, and package inclusion rules.
- [ ] **Add a release preflight script**
  - Check for forbidden files, forbidden directories, oversized assets, broken symlinks, and secrets.
- [ ] **Define archive policy**
  - `_archives/`, `campaigns/`, and research artifacts should be either excluded from public release or intentionally curated.

### Exit Criteria

- [ ] **Every top-level area has an ownership classification**
- [ ] **The release tree contains only intentional source and documentation**
- [ ] **Preflight catches obvious release contaminants**
- [ ] **A clean mirror can be produced repeatedly**

## Phase 4: Memory Governance and Public Data Policy

### Objectives

- Turn memory from a private operational substrate into a safe public story.
- Prevent noisy or private runtime data from defining the open-source release.

### Checklist

- [ ] **Write a public memory policy**
  - Specify what memory is runtime-only, what sample data may ship, and what never ships.
- [ ] **Separate Labs operational memory from Core sample memory**
  - Core should never depend on private operational corpora or unstable archive residue.
- [ ] **Curate a public sample corpus**
  - Prefer a small, intentional, documented seed over dumping operational databases.
- [ ] **Treat quarantined data as non-public by default**
  - Public retrieval flows should not depend on noisy or contaminated operational memory.
- [ ] **Repair or retire broken archive references**
  - Broken symlinks, empty DB stand-ins, and unclear archive chains should be resolved or documented as deprecated.
- [ ] **Document the memory lifecycle**
  - Explain memory types, quarantine semantics, consolidation, archives, and cold storage clearly.
- [ ] **Add memory QA checks**
  - Create checks or reports for signal-to-noise ratio, type distribution, and retrieval relevance.

- [ ] **Create a retrieval-quality benchmark**
  - Use curated queries, expected-answer sets, and contamination/noise scoring to evaluate public-facing retrieval quality.

### Exit Criteria

- [ ] **The project has a defensible public memory story**
- [ ] **No private operational memory leaks into the release**
- [ ] **Curated sample data exists or the release explicitly ships no data**
- [ ] **Retrieval quality is measured and acceptable for public demos**

## Phase 5: Tool Surface Stabilization

### Objectives

- Make the public interface easy to explain and safe to depend on.
- Reduce ambiguity between overlapping dispatch layers.

### Checklist

- [ ] **Define the public contract**
  - Decide whether the release centers on MCP, PRAT, Python API, CLI, or a layered combination.
- [ ] **Define Core vs Labs tool eligibility**
  - Not every internal capability needs to be exposed through Core by default.
- [ ] **Mark stable and experimental tool groups**
  - Not every internal capability needs to be in the public default surface.
- [ ] **Audit overlapping dispatch layers**
  - Clarify the roles of `run_mcp.py`, `unified_api.py`, `dispatch_table.py`, registry definitions, and bridge layers.
- [ ] **Create a generated tool inventory**
  - Produce documentation from live code rather than hand-maintained counts.
- [ ] **Publish the extension contract**
  - Document `gana_forge`, manifest schema, lifecycle, safety expectations, and versioning.
- [ ] **Review dynamic execution surfaces**
  - Ensure sandboxed or code-executing paths are clearly gated, documented, or disabled by default in public release profiles.
- [ ] **Define release profiles**
  - Example: `core`, `full`, `labs`, `experimental`.

### Exit Criteria

- [ ] **New users can identify the stable interface immediately**
- [ ] **Experimental paths are clearly labeled**
- [ ] **Public docs match the actual routed tool surface**
- [ ] **The extension path is documented and governable**

## Phase 6: Testing, CI, and Packaging

### Objectives

- Ensure the release is buildable and testable without reproducing the entire internal environment.
- Make optional accelerators truly optional.

### Checklist

- [ ] **Define the minimum supported platform matrix**
  - Start with Linux and the supported Python versions.
- [ ] **Tier the test suite**
  - Separate core tests from optional polyglot and heavy-performance tests.
- [ ] **Create separate Labs and Core validation lanes**
  - Core CI must pass from the sanitized tree without Labs-only assets.
- [ ] **Make the core install path simple**
  - Public installation should not require Rust, Elixir, Haskell, Mojo, or local models unless explicitly opting in.
- [ ] **Create release smoke tests**
  - Validate startup, MCP registration, PRAT mode, lite mode, state-root behavior, and memory initialization.
- [ ] **Add packaging and manifest tests**
  - Verify what actually lands in source distributions, wheels, containers, and archives.
- [ ] **Add security and hygiene scans**
  - Path leaks, secrets, oversized artifacts, broken docs links, and risky files should be checked automatically.

### Exit Criteria

- [ ] **Core CI passes on the supported matrix**
- [ ] **Optional accelerators fail gracefully when absent**
- [ ] **Release artifacts match the intended ship surface**

## Phase 7: Public Docs, Positioning, and Onboarding

### Objectives

- Make Whitemagic understandable and attractive to new users without diluting its identity.
- Reduce intimidation while preserving depth.

### Checklist

- [ ] **Create a one-page public positioning doc**
  - Explain what Whitemagic is in plain language before entering the deeper symbolic and architectural material.
- [ ] **Produce a short quickstart**
  - Get a user from install to successful MCP usage quickly.
- [ ] **Provide a stable newcomer path**
  - Orient newcomers toward Core docs first, then Labs research material as optional depth.
- [ ] **Separate Core onboarding from Labs research**
  - Make it obvious which docs are public contract and which are deeper exploratory material.
- [ ] **Document optional depth separately**
  - Gardens, Grimoire, polyglot subsystems, and research surfaces should be discoverable but not mandatory.
- [ ] **Add contributor onboarding**
  - Clarify repo layout, release profiles, path policy, and how to add or evolve tools safely.
- [ ] **Publish architecture at two levels**
  - One simple diagram and one deep technical diagram set.

### Exit Criteria

- [ ] **A new user can install and understand the core value quickly**
- [ ] **A contributor can find the stable entry points without archaeology**
- [ ] **The public face feels intentional rather than accreted**
- [ ] **Core and Labs are discoverable without being confused for each other**

## Phase 8: Labs -> Core Promotion Pipeline Engineering

### Objectives

- Make the `whitemagicdev -> whitemagicpublic -> GitHub` flow safe and repeatable.
- Improve provenance, auditability, and release quality.
- Turn Labs and Core into a deliberate release system rather than an informal copy path.

### Recommended Direction

Use a dual-repo model intentionally:

- `whitemagicdev` = **Whitemagic Labs**
  - Private, full-fidelity development repo.
  - May contain research material, broader history, internal notes, and active remediation work.
- `whitemagicpublic` = **Whitemagic Core**
  - Sanitized public mirror and release staging repo.
  - Should contain only the approved public contract and its supporting assets.

### Checklist

- [ ] **Put Labs under private Git provenance**
  - `whitemagicdev` should become a real private Git repo or equivalent source-of-truth surface.
- [ ] **Add a private remote and branch policy for Labs**
  - Ensure Labs work has backup, review, and provenance independent of Core.
- [ ] **Define a promotion manifest**
  - Explicitly list what directories and files are copied or mirrored from dev to public.
- [ ] **Define exclusion rules**
  - Explicitly exclude memories, models, logs, local archives, caches, benchmarks, patch scripts, and experimental residue from the public mirror.
- [ ] **Generate machine-readable export and diff reports**
  - Promotion should produce an auditable manifest of what moved from Labs into Core.
- [ ] **Automate promotion**
  - Replace manual copying with a repeatable sync/export step.
- [ ] **Add promotion preflight**
  - Validate docs consistency, ship surface cleanliness, path hygiene, and test status before promotion.
- [ ] **Add post-promotion diff review**
  - Compare `whitemagicdev` export against `whitemagicpublic` and review unexpected drift.
- [ ] **Tag only from Core**
  - Public tags and releases should come from the sanitized repo.
- [ ] **Support optional private publication of Labs**
  - If desired, `whitemagicdev` should also be publishable to a private remote for backup, CI, review, and provenance.

### Exit Criteria

- [ ] **Development work has private provenance**
- [ ] **Public promotion is scripted and reviewable**
- [ ] **Core is cleaner, smaller, and more stable than Labs by design, not by luck**

## Phase 9: Release Candidate and Launch Operations

### Objectives

- Validate the public release like a product.
- Prepare for the first wave of real users and contributors.

### Checklist

- [ ] **Cut a release candidate**
  - Freeze scope and treat it as if it were public.
- [ ] **Run a dry-run publish**
  - Build release artifacts, mirror to `whitemagicpublic`, run tests, and inspect the exact public surface.
- [ ] **Invite a cold-start reviewer**
  - Ask someone without deep internal context to install and use it.
- [ ] **Prepare public issue templates**
  - Bugs, docs, security, tool requests, and contributor questions.
- [ ] **Publish the roadmap**
  - Show what is stable now and what remains experimental.
- [ ] **Define post-launch governance**
  - Triage cadence, compatibility policy, release cadence, and deprecation policy.

### Exit Criteria

- [ ] **A release candidate survives a dry-run publish cleanly**
- [ ] **Cold-start onboarding works**
- [ ] **The public repo, docs, and artifacts match the intended story**

## Phase 10: Benchmark Gauntlet, Comparative Analysis, and Tactical Guide

### Objectives

- Improve the Benchmark Gauntlet so it measures the system that actually ships.
- Run the Gauntlet and compare results against prior runs where historical data exists.
- Interpret the metrics, regressions, strengths, and tradeoffs in release terms.
- Produce a tactical guide that explains how the release objectives were reasoned through and accomplished so future AI systems can continue the work coherently.

### Checklist

- [ ] **Audit the active benchmark surfaces**
  - Identify the canonical Gauntlet entrypoint, supporting harnesses, historical trackers, and prior reports.
- [ ] **Improve the Benchmark Gauntlet**
  - Ensure the suite reflects Core-facing workloads, stable interfaces, and reproducible release conditions.
- [ ] **Define benchmark profiles**
  - Separate Core smoke benchmarks, release benchmarks, and Labs-only experimental benchmarks.
- [ ] **Run the benchmark suite**
  - Execute the appropriate Gauntlet profiles in a documented environment and capture raw outputs.
- [ ] **Compare against prior results when available**
  - Use historical reports and trackers to identify improvements, regressions, and missing comparables.
- [ ] **Interpret the results**
  - Discuss what the metrics imply for portability, stability, retrieval quality, tool latency, acceleration value, and release confidence.
- [ ] **Write a tactical guide for future AI maintainers**
  - Explain the reasoning pattern used to solve each objective, the order of operations, the gating logic, and the principle that it is better to document the system that actually ships than to rewrite public docs too early.
- [ ] **Publish the benchmark and tactical artifacts**
  - Save the benchmark report, comparison analysis, and tactical guide in durable repo locations.

### Exit Criteria

- [ ] **A release-relevant benchmark suite exists and runs successfully**
- [ ] **Current results are compared with prior data where possible**
- [ ] **The implications of the metrics are documented clearly**
- [ ] **A future AI can read the tactical guide and continue the release program coherently**

## Recommended Sequencing

Use this order for continuous execution once implementation begins:

1. Phase 0: Program Governance and Labs/Core Charter
2. Phase 2: State-Root, Portability, and Filesystem Hygiene
3. Phase 3: Ship Surface Cleanup
4. Phase 5: Tool Surface Stabilization
5. Phase 4: Memory Governance and Public Data Policy
6. Phase 6: Testing, CI, and Packaging
7. Phase 1: Canonical Truth and Documentation Convergence
8. Phase 7: Public Docs, Positioning, and Onboarding
9. Phase 8: Labs -> Core Promotion Pipeline Engineering
10. Phase 9: Release Candidate and Launch Operations
11. Phase 10: Benchmark Gauntlet, Comparative Analysis, and Tactical Guide

Companion rules:

- [ ] **Run preflight at the end of every phase**
- [ ] **Update the release board and docs delta before advancing**
- [ ] **Reopen earlier phases only when a regression or blocker is discovered**

## First Execution Wave

The first implementation wave should focus on the highest-leverage blockers:

- [ ] **Ratify the Labs/Core charter and Core eligibility rules**
- [ ] **Fix all known state-root leaks in ship code**
- [ ] **Classify top-level directories as Core, Labs, or runtime state**
- [ ] **Create a release preflight script that fails on local artifacts and path leaks**
- [ ] **Define the public memory posture and retrieval benchmark plan**
- [ ] **Place Labs under private Git and formalize promotion into Core**

## Definition of Done

Whitemagic can be considered release-ready when all of the following are true:

- [ ] **Labs and Core have explicit, enforced roles**
- [ ] **The public contract is clear**
- [ ] **The public docs are internally consistent**
- [ ] **The release tree is clean and reproducible**
- [ ] **Runtime state is fully externalized**
- [ ] **Memory/data policy is explicit and safe**
- [ ] **Retrieval quality is measured and acceptable for public-facing use**
- [ ] **The extension story is documented and governable**
- [ ] **Core install and smoke tests pass reliably**
- [ ] **Promotion from dev to public is scripted and auditable**
- [ ] **The Benchmark Gauntlet is improved, run, and interpreted against prior evidence**
- [ ] **A tactical guide exists for future AI maintainers to continue the work**
- [ ] **The resulting repo feels curated, intentional, and understandable**
