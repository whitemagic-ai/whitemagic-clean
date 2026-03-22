---
name: "Skeletonization Engine — AST Context Compression"
codename: G002
army: alpha
type: discovery
priority: 2
clone_count: 30000
strategies:
  - analytical
  - chain_of_thought
category: optimization
phase: foundation
source: "Gemini transcript — Tree-Sitter AST skeletons for 95% context compression"
column_size: 15000
---

# Skeletonization Engine — AST Context Compression

## Objective

Build a Tree-Sitter-based code skeletonization engine that extracts only the
structural skeleton of source files (struct definitions, impl signatures, function
headers, class outlines) while replacing bodies with `// ... implementation hidden`.

**Core insight**: Sending 50 files to cloud AI wastes 80% of tokens on function
bodies irrelevant to the current task. Skeletons give the AI the full architecture
at 5% of the token cost, with on-demand expansion of specific functions.

## Victory Conditions

- [x] Tree-Sitter parser integrated for Python, Rust, TypeScript (the 3 primary languages)
- [x] `skeletonize(file_path) -> str` function returns AST skeleton with hidden bodies
- [x] On-demand `expand(file_path, symbol_name) -> str` returns just the requested function/class body
- [x] Skeleton of a 500-line Python file fits in ≤50 lines (≥90% compression)
- [x] Multi-file skeleton: `skeletonize_directory(path) -> str` for project-wide overviews
- [x] Integration with shadow clone recon: clones receive skeletons instead of raw files
- [x] Benchmark: token count comparison (raw vs. skeleton) on 100 WhiteMagic source files
- [x] Handles edge cases: decorators, docstrings (keep first line), nested classes, async defs
- [x] Report: `reports/skeletonization.md` with compression ratios and example output

## Targets

| Component | Location | Type |
|-----------|----------|------|
| Core engine | `whitemagic/optimization/skeletonizer.py` | New module |
| Tree-Sitter bindings | `whitemagic-rust/src/tree_sitter_bridge.rs` | New Rust module (optional) |
| Clone integration | `scripts/deploy_grand_army.py` | Wire skeletons into recon |
| CLI command | `whitemagic/cli/cli_app.py` | `wm skeleton <path>` command |

## Strategy

1. Install `tree-sitter` and language grammars for Python, Rust, TypeScript
2. Build `Skeletonizer` class that walks AST and emits skeleton text
3. Implement `expand()` for on-demand drill-down into specific symbols
4. Benchmark compression ratios on real WhiteMagic source files
5. Wire into clone army recon phase as context preparation step
6. Add CLI command for interactive use

## Verification

- Run skeletonizer on `whitemagic/core/memory/sqlite_backend.py` (large file) — verify ≥90% reduction
- Verify skeleton preserves all public API signatures
- Verify `expand("search_memories")` returns exactly that function's body
