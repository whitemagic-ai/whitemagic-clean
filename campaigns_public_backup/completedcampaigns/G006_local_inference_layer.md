---
name: "Local Inference Layer — On-Device AI Processing"
codename: G006
army: beta
type: discovery
priority: 2
clone_count: 50000
strategies:
  - analytical
  - chain_of_thought
category: infrastructure
phase: foundation
source: "Gemini transcript — Candle/llama.cpp for local embedding + small LLM inference"
column_size: 25000
---

# Local Inference Layer — On-Device AI Processing

## Objective

Build a local inference layer that handles embedding, classification, and small-model
reasoning without any cloud API calls. This is the "Body" of the Bicameral System:
the local grunt worker that handles syntax, file IO, validation, and cheap inference
while the cloud "Mind" focuses on complex reasoning and strategy.

**Core insight**: The cloud AI should spend tokens thinking, planning, and responding
thoughtfully — not grinding through repetitive code. Local models handle the grunt work.

## Victory Conditions

- [x] Local embedding model running: all-MiniLM-L6-v2 or bge-m3 via Candle, sentence-transformers, or ollama
- [x] Embedding throughput: ≥500 texts/sec on CPU (no GPU required)
- [x] Local small LLM available via llama.cpp or ollama for classification/summarization tasks
- [x] Small LLM can classify memory types, extract entities, score relevance — all locally
- [x] Speculative execution: local syntax check (tree-sitter or compiler) before committing AI-generated code
- [x] Integration with existing `whitemagic/inference/bitnet_bridge.py` and `whitemagic/edge/inference.py`
- [x] Fallback chain: try Rust SIMD → local model → cloud API (escalating cost)
- [x] Benchmark: measure token savings — how many cloud API calls replaced by local inference?
- [x] Privacy guarantee: all local inference stays on-disk, zero external network calls
- [x] Report: `reports/local_inference.md` with throughput benchmarks and token savings

## Targets

| Component | Location | Type |
|-----------|----------|------|
| Embedding server | `whitemagic/inference/local_embedder.py` | New module |
| Small LLM bridge | `whitemagic/inference/local_llm.py` | New module |
| Speculative exec | `whitemagic/optimization/speculative_exec.py` | New module |
| Rust Candle bridge | `whitemagic-rust/src/candle_bridge.rs` | New Rust module (optional) |
| Existing edge | `whitemagic/edge/inference.py` | Enhance |
| Existing bitnet | `whitemagic/inference/bitnet_bridge.py` | Enhance |

## Strategy

1. Evaluate local model options: ollama (easiest), sentence-transformers (Python), Candle (Rust native)
2. Set up local embedding server with batch processing
3. Benchmark embedding throughput on CPU
4. Set up small LLM (Phi-3-mini or Gemma-2b 4-bit) for classification tasks
5. Build speculative execution: buffer AI output → local syntax check → commit or reject
6. Wire into existing inference infrastructure (bitnet_bridge, edge inference)
7. Build cost escalation chain: local → cloud
8. Benchmark token savings on real workload

## Verification

- Embedding 1000 memories locally: verify ≥500/sec throughput
- Small LLM classifies 100 memories with ≥80% accuracy vs. cloud model
- Speculative execution catches at least 1 syntax error before commit
- Zero external API calls during local-only operation
