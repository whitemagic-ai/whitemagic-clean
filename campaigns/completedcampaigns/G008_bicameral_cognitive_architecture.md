---
name: "Bicameral Cognitive Architecture — Local Body, Cloud Mind"
codename: G008
army: beta
type: batch_transform
priority: 1
clone_count: 85000
strategies:
  - analytical
  - chain_of_thought
  - synthesis
  - first_principles
category: architecture
phase: foundation
source: "Gemini conversation on cognitive architecture — separating grunt work from strategic thinking"
column_size: 50000
---

# Bicameral Cognitive Architecture

## Objective

Implement a two-tier cognitive system that separates "grunt work" (syntax, I/O, validation) from "strategic thinking" (logic, architecture, reasoning). The goal is to minimize cloud AI token burn on repetitive tasks while maximizing thoughtful, high-value inference.

### Current Problem
- Cloud AI burns 80% of tokens on boilerplate: whitespace, braces, function bodies, repetitive code
- No structural awareness — must read entire files to understand architecture
- "Blind agent" problem — writes code without verifying it compiled/ran
- Overwrites entire files to change one line (5,000 lines regenerated for 1-line fix)
- No persistent learning from "thought process" — same mistakes repeated

### Proposed Architecture

**Local System (The Body/Grunt)** — Rust + Tree-sitter + Small LLMs
- Handles: syntax parsing, file I/O, validation, compilation checks
- Fast, zero-token operations on disk
- Provides AST skeletons to cloud AI (5% token cost vs raw text)
- Implements surgical patching (search/replace blocks, not full rewrites)
- Runs speculative execution (syntax check before commit)

**Cloud System (The Mind/Architect)** — Large LLM
- Handles: logic, strategy, complex reasoning, architecture decisions
- Receives compressed context (AST skeletons, not full files)
- Outputs focused instructions (patch blocks, not full files)
- Writes to `.thought` channel for reasoning (stored in Thought Galaxy)
- Self-corrects via local feedback loop

## Victory Conditions

### Phase 1: Skeletonization (Context Compression)
- [x] Tree-sitter integration in Rust — parse Python/Rust/TypeScript/Elixir ASTs
- [x] AST skeleton extractor — struct defs, impl signatures, function headers only
- [x] Function body replacement — `// ... implementation hidden ...` placeholder
- [x] On-demand expansion protocol — `expand: function_name` retrieves full body
- [x] Benchmark: 50-file codebase context fits in 5% of tokens vs raw text

### Phase 2: Surgical Patching (Token Savings)
- [x] Search/Replace block protocol implemented in local Rust agent
- [x] Fuzzy matching for SEARCH blocks (handles whitespace variations)
- [x] Atomic file operations — backup before patch, rollback on failure
- [x] Multi-block patches — apply multiple edits in single transaction
- [x] Benchmark: 1-line change uses <50 tokens vs 5,000+ for full rewrite

### Phase 3: Speculative Execution (Blind Agent Fix)
- [x] Local syntax validator — cargo check, tree-sitter validity, linters
- [x] Stream buffer — capture cloud AI output before disk commit
- [x] Interrupt protocol — send errors to cloud AI mid-generation for correction
- [x] Commit-on-success — only write to disk after validation passes
- [x] Self-correction loop — AI fixes errors before user sees them

### Phase 4: Thought Galaxy (Meta-Cognitive Memory)
- [x] `.thought` channel — dedicated stream for reasoning (not code)
- [x] Cognitive episode storage — context, strategy, thought trace, outcome score
- [x] Outcome scoring — -1.0 (failed) to +1.0 (breakthrough) based on compile success
- [x] Strategy query system — "How have I solved async race conditions before?"
- [x] Pattern library — distilled "Golden Rules" from high-scoring episodes

### Phase 5: Auto-Prompting Supervisor (Manager Removal)
- [x] Post-action reflection — automatic self-review after code generation
- [x] SOP pattern matching — "High-rated episodes always include X step"
- [x] Synthetic prompt injection — system prompts itself without user input
- [x] Idle-time triggers — "20 min inactive → draft session handoff"
- [x] Benchmark: 70% of managerial prompts automated

### Phase 6: Dream Cycle (Offline Optimization)
- [x] Nightly clustering — group similar thoughts (e.g., "All CSS fixes")
- [x] A/B comparison — analyze "Good" vs "Bad" thought patterns
- [x] Golden Rule synthesis — distill principles from successful clusters
- [x] Prompt patching — update system prompt with new rules
- [x] Recursive improvement — AI wakes up smarter than yesterday

### Phase 7: Historical Transmutation (100K Memory Processing)
- [x] Nigredo (Decomposition) — filter 100K memories, keep 30% novelty
- [x] Albedo (Purification) — vectorize patterns, abstract specifics
- [x] Rubedo (Completion) — synthesize "Holocron" of distilled wisdom
- [x] Pattern clustering — identify universal patterns (e.g., "Async Deadlock Fix")
- [x] Wisdom integration — AI loads Holocron before tasks

## Targets

### Files to Create
| File | Purpose |
|------|---------|
| `whitemagic-rust/src/tree_sitter_bridge.rs` | AST parsing + skeleton extraction |
| `whitemagic-rust/src/surgical_patcher.rs` | Search/Replace block protocol |
| `whitemagic-rust/src/speculative_executor.rs` | Syntax validation + stream buffer |
| `whitemagic/core/cognition/thought_galaxy.py` | Cognitive episode storage |
| `whitemagic/core/cognition/auto_supervisor.py` | Post-action reflection + SOP matching |
| `whitemagic/core/cognition/dream_transmutation.py` | Nightly optimization cycle |
| `whitemagic/core/cognition/holocron.py` | Distilled wisdom library |

### Files to Modify
| File | Change |
|------|--------|
| `whitemagic/tools/input_sanitizer.py` | Route through skeleton extractor |
| `whitemagic/tools/handlers/*.py` | Use surgical patcher for edits |
| `whitemagic/core/memory/dream_cycle.py` | Add transmutation phase |
| `whitemagic/agents/campaign_loader.py` | Load thought episodes as context |

## Strategy

### Phase 1-3: Local Grunt Infrastructure (Week 1)
1. Implement Tree-sitter Rust bindings for Python/Rust/TS/Elixir
2. Build AST skeleton extractor with `// ... hidden ...` placeholders
3. Create Search/Replace protocol with fuzzy matching
4. Add speculative execution with syntax validation
5. Wire into MCP tool dispatch for code generation tasks
6. Benchmark token savings on real editing tasks

### Phase 4-5: Thought Galaxy + Auto-Supervisor (Week 2)
1. Create `CognitiveEpisode` schema in SQLite
2. Add `.thought` channel to tool handlers
3. Implement outcome scoring based on compile/test results
4. Build strategy query system for pattern retrieval
5. Create SOP pattern matcher for auto-prompting
6. Wire post-action reflection into tool completion hooks

### Phase 6-7: Dream Cycle + Historical Transmutation (Week 3)
1. Add transmutation phase to existing dream_cycle.py
2. Implement thought clustering (HDBSCAN on thought vectors)
3. Build A/B comparison for good vs bad patterns
4. Create Golden Rule synthesizer
5. Add prompt patching to system initialization
6. Run Nigredo/Albedo/Rubedo on 100K historical memories
7. Generate Holocron file for wisdom integration

## Verification

```bash
# Tree-sitter parsing works
scripts/wm -c "from whitemagic_rs import parse_ast; print(parse_ast('def foo(): pass', 'python'))"

# Skeleton extraction reduces tokens
scripts/wm -c "from whitemagic.core.cognition import skeletonize; s = skeletonize('whitemagic/'); print(f'{len(s)} chars vs {sum(len(open(f).read()) for f in glob(\"whitemagic/**/*.py\"))} raw')"

# Surgical patcher works
echo 'def test(): return 1' > /tmp/test.py
scripts/wm -c "from whitemagic_rs import surgical_patch; surgical_patch('/tmp/test.py', 'return 1', 'return 2'); print(open('/tmp/test.py').read())"

# Thought galaxy stores episodes
scripts/wm -c "from whitemagic.core.cognition import ThoughtGalaxy; tg = ThoughtGalaxy(); tg.store('test', 'strategy', 'thought', 0.8); print(tg.query('test'))"

# Auto-supervisor triggers reflection
scripts/wm -c "from whitemagic.core.cognition import AutoSupervisor; sup = AutoSupervisor(); sup.post_action_reflect('code_generation'); print('OK')"

# Dream transmutation runs
scripts/wm scripts/run_dream_cycle.py --phase transmutation

# Holocron loads
scripts/wm -c "from whitemagic.core.cognition import Holocron; h = Holocron(); print(f'{len(h.golden_rules)} rules loaded')"
```

## Expected Impact

### Token Efficiency
- **Context compression**: 95% token reduction via AST skeletons
- **Surgical edits**: 99% token reduction (50 tokens vs 5,000 for 1-line change)
- **Thought channel**: 70% reduction in context pollution (discarded reasoning)
- **Auto-supervisor**: 70% reduction in managerial prompts

### Quality Improvements
- **Blind agent fix**: 90% reduction in "hallucinated API" errors via speculative execution
- **Pattern learning**: Recursive improvement via Thought Galaxy + Dream Cycle
- **Wisdom integration**: Faster problem-solving via Holocron pattern library

### Autonomy Gains
- **Manager removal**: 70% of supervision automated via auto-prompting
- **Self-correction**: Errors caught and fixed before user sees them
- **Continuous learning**: AI improves overnight via dream transmutation

## Notes

This campaign implements the core ideas from the Gemini conversation:
1. **Funnel Architecture** — filter before reading (Tree-sitter skeletons)
2. **Map-Reduce Summarization** — chunk + summarize (thought episodes)
3. **Scratchpad Reasoning** — external memory (Thought Galaxy)
4. **Janus Architecture** — local body + cloud mind (Rust + LLM)
5. **Ouroboros Loop** — recursive self-improvement (Dream Cycle)

The key insight: **Reading ≠ Generating**. We can "read" (embed/vectorize) 1M words for a fraction of the compute cost of "writing" 1K words. By moving heavy lifting to the local embedding/parsing layer and keeping generative inference only for final output, we minimize resource burn while maximizing thoughtful reasoning.

This is the path to true cognitive efficiency — where the AI spends most of its tokens **thinking**, not **typing**.
