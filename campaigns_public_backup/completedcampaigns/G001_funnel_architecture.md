---
name: "Funnel Architecture — Zero-Burn File Processing"
codename: G001
army: beta
type: batch_transform
priority: 2
clone_count: 80000
strategies:
  - analytical
  - chain_of_thought
  - synthesis
category: optimization
phase: foundation
source: "Gemini transcript — 3-layer funnel: heuristic pre-filter → sparse embedding → RAG"
column_size: 40000
---

# Funnel Architecture — Zero-Burn File Processing

## Objective

Build a 3-layer processing funnel that minimizes token/inference burn when reading
thousands of files. Layer 1 (heuristic pre-filter) discards irrelevant content at
disk-read speed using Rust regex/Aho-Corasick. Layer 2 (sparse embedding) converts
surviving content into vectors using a small local model. Layer 3 (RAG) feeds only
the relevant chunks to the cloud LLM for actual reasoning.

**Core insight**: Reading ≠ generating. You can embed/vectorize 1M words for a
fraction of the compute cost of generating 1K words.

## Victory Conditions

- [x] Layer 1: Rust-powered heuristic pre-filter module created (`whitemagic/optimization/funnel_filter.rs` or Python wrapper)
- [x] Pre-filter uses Aho-Corasick multi-pattern matching for keyword/signature scanning at GB/s speeds
- [x] Pre-filter reduces candidate files by ≥70% before any AI touches them (measured on real corpus)
- [x] Layer 2: Small embedding model (all-MiniLM-L6-v2 or bge-m3) wired into the funnel for cheap vectorization
- [x] Layer 2 runs on CPU at ≥1000 chunks/sec (no GPU required)
- [x] Layer 3: RAG retrieval reduces input to cloud LLM from "all files" to "top-K relevant chunks" (K ≤ 20)
- [x] End-to-end benchmark: process 1000 files through full funnel, measure token savings vs. naive approach
- [x] Funnel integrated into shadow clone recon phase (clones use funnel before deploying expensive inference)
- [x] Report: `reports/funnel_architecture.md` with benchmark data and token savings

## Targets

| Component | Location | Type |
|-----------|----------|------|
| Rust pre-filter | `whitemagic-rust/src/funnel_filter.rs` | New Rust module |
| Python bridge | `whitemagic/optimization/funnel.py` | New Python wrapper |
| Embedding worker | `whitemagic/core/intelligence/embedding_worker.py` | Enhance existing |
| Clone recon | `scripts/deploy_grand_army.py` | Wire funnel into recon phase |

## Strategy

1. Implement Aho-Corasick pattern set in Rust (keyword lists for code, config, docs, noise)
2. Wire into Python via whitemagic_rs bridge
3. Benchmark Layer 1 alone: files in → files out, measure discard rate
4. Integrate small embedding model (all-MiniLM-L6-v2) for Layer 2 vectorization
5. Build RAG retrieval pipeline that queries vectors and returns top-K chunks
6. Wire into shadow clone recon phase as a "pre-flight filter"
7. End-to-end benchmark on real corpus (1000+ files)

## Verification

- Benchmark data showing ≥70% file discard at Layer 1
- Token savings calculation: naive vs. funnel approach
- Integration test: clone deployment with funnel pre-filter active
