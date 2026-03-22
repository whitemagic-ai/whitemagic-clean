# KOKA002 — Koka Enhancement Roadmap

**Status**: PLANNED
**Priority**: HIGH
**Started**: 2026-02-22
**Target**: 2026-03-15

## Objective

Complete the Koka integration for WhiteMagic with batch IPC, shared memory, effect composition, JIT compilation, and polyglot unification.

---

## Verification Criteria (VCs)

### Phase 1: IPC Optimization (Short-Term)

#### VC-01: Batch IPC Protocol
- [ ] Implement multi-command batching in Koka binaries
- [ ] Single write for N commands, N reads for responses
- [ ] Benchmark: batch of 10 commands < 5x single command latency
- [ ] Update `gan_ying.kk`, `hot_paths.kk`, `unified_runtime.kk`
- [ ] Python client support in `hybrid_dispatcher_v2.py`

#### VC-02: Binary Protocol Upgrade
- [ ] Add length-prefixed message framing
- [ ] Support binary payloads (not just JSON)
- [ ] Implement message checksums
- [ ] Document protocol in `docs/koka_ipc_protocol.md`

#### VC-03: Process Health Monitoring
- [x] Heartbeat mechanism (ping/pong every 30s)
- [x] Automatic restart on missed heartbeats
- [x] Health metrics exposed via `stats()` endpoint
- [ ] Integration with `health_check()` in dispatcher

#### VC-04: Connection Pooling v2
- [x] Lazy pool initialization (on first use)
- [x] Pool scaling based on load (min 1, max 4)
- [x] Pool shrink after 5min idle
- [ ] Metrics: pool utilization, avg wait time

---

### Phase 2: Memory & Data Transfer (Short-Term)

#### VC-05: Shared Memory Bridge
- [x] POSIX shared memory segment for Koka-Python data
- [x] Zero-copy transfer for embeddings (384-dim vectors)
- [ ] Ring buffer for streaming data
- [x] Benchmark: 1000 embeddings transfer < 1ms

#### VC-06: Memory-Mapped IPC
- [ ] mmap-backed stdin/stdout for large payloads
- [ ] Support payloads > 1MB
- [ ] Automatic fallback to pipe for small data
- [ ] Test with 10K memory batch operations

#### VC-07: Serialization Optimization
- [ ] Implement MessagePack support in Koka
- [ ] Benchmark: MessagePack vs JSON (target 2x faster)
- [ ] Auto-detect format via magic bytes
- [ ] Update all IPC handlers

---

### Phase 3: Effect System Deepening (Medium-Term)

#### VC-08: Koka Module Imports
- [ ] `unified_runtime.kk` imports `gan_ying` as module
- [ ] True effect composition (not just IPC chaining)
- [ ] Single process, multiple effect handlers
- [ ] Benchmark: import-based vs IPC-based (target 10x faster)

#### VC-09: Effect Handler Stacking
- [ ] Define `profile-ops ⊕ event-ops ⊕ memory-ops`
- [ ] Handler priority ordering
- [ ] Effect interception for cross-cutting concerns
- [ ] Example: logging handler wraps all operations

#### VC-10: Stateful Effect Handlers
- [ ] Persistent state across handler invocations
- [ ] State checkpoint/restore
- [ ] State migration on handler version change
- [ ] Test: 1000 operations with state persistence

#### VC-11: Effect Handler Hot Reload
- [ ] Detect `.kk` file changes
- [ ] Recompile and reload without process restart
- [ ] State preservation across reload
- [ ] Development mode flag in dispatcher

---

### Phase 4: Performance (Medium-Term)

#### VC-12: LLVM JIT Compilation
- [ ] Enable Koka's LLVM backend for hot paths
- [ ] AOT compile `gan_ying`, `hot_paths`, `unified_runtime`
- [ ] Benchmark: JIT vs interpreter (target 5x faster)
- [ ] Build script update in `Makefile`

#### VC-13: Native Binary Optimization
- [ ] Strip debug symbols for production
- [ ] LTO (Link Time Optimization) enabled
- [ ] Static linking for portability
- [ ] Binary size target: < 5MB per module

#### VC-14: SIMD Vectorization
- [ ] Identify vectorizable operations in hot_paths
- [ ] Koka SIMD intrinsics for embedding operations
- [ ] Benchmark: SIMD vs scalar (target 4x faster)
- [ ] Integration with Zig SIMD kernels

#### VC-15: Parallel Effect Handlers
- [ ] `parallel` effect for concurrent operations
- [ ] Fork-join parallelism in Koka
- [ ] Work-stealing scheduler
- [ ] Benchmark: 4-core speedup > 3x

---

### Phase 5: Integration (Medium-Term)

#### VC-16: Python-Koka Type Bridge
- [ ] Auto-generate Python stubs from Koka types
- [ ] Type-safe IPC calls from Python
- [ ] Runtime type validation
- [ ] IDE support (autocompletion)

#### VC-17: MCP Tool Integration
- [ ] Expose Koka operations as MCP tools
- [ ] `koka_emit_event`, `koka_profile_path`, etc.
- [ ] Schema generation for tool definitions
- [ ] Integration test with MCP server

#### VC-18: Rust Interop
- [ ] FFI bridge between Koka and Rust
- [ ] Call Rust functions from Koka effect handlers
- [ ] Memory safety guarantees maintained
- [ ] Benchmark: Koka→Rust vs Python→Rust

#### VC-19: Zig Interop
- [ ] Koka extern declarations for Zig functions
- [ ] Shared memory with Zig SIMD kernels
- [ ] Cross-compilation support
- [ ] Test: embedding similarity via Zig from Koka

---

### Phase 6: Advanced Features (Long-Term)

#### VC-20: Distributed Effects
- [ ] Effect handlers across network nodes
- [ ] Serialization of effect continuations
- [ ] Network-transparent handler dispatch
- [ ] Test: emit event on node A, handle on node B

#### VC-21: Formal Verification
- [ ] Koka effect signatures for all operations
- [ ] Coq/Lean proofs for critical paths
- [ ] Verified: no unhandled effects
- [ ] Document in `docs/formal_verification.md`

#### VC-22: Effect Profiling
- [ ] Automatic profiling of effect operations
- [ ] Cost model for each effect type
- [ ] Optimization suggestions from profiler
- [ ] Integration with `hot_paths` module

#### VC-23: Effect Versioning
- [ ] Semantic versioning for effect interfaces
- [ ] Backward compatibility checks
- [ ] Migration tools for effect upgrades
- [ ] Test: upgrade gan_ying v1 → v2

---

### Phase 7: Polyglot Unification (Long-Term)

#### VC-24: Unified Dispatcher v3
- [ ] Single dispatcher for Rust, Koka, Zig, Python
- [ ] Automatic routing based on operation characteristics
- [ ] Cost-based optimization
- [ ] Benchmark: unified vs separate dispatchers

#### VC-25: Cross-Language Effects
- [ ] Define effects that span languages
- [ ] `compute` effect → Rust, `io` effect → Koka, `simd` effect → Zig
- [ ] Seamless handoff between runtimes
- [ ] Test: embedding pipeline across 3 languages

#### VC-26: Polyglot Build System
- [ ] Single `Makefile` for all languages
- [ ] Dependency tracking across languages
- [ ] Incremental compilation
- [ ] CI/CD integration

#### VC-27: Performance Dashboard
- [ ] Real-time metrics for all runtimes
- [ ] Latency heatmaps per language
- [ ] Resource utilization tracking
- [ ] Alerting on degradation

---

### Phase 8: Developer Experience (Long-Term)

#### VC-28: Koka Development Environment
- [ ] VSCode extension for Koka in WhiteMagic
- [ ] Syntax highlighting, type checking
- [ ] Effect visualization
- [ ] Debug adapter protocol support

#### VC-29: Documentation
- [ ] API docs for all Koka modules
- [ ] Effect handler guide
- [ ] Performance tuning guide
- [ ] Migration guide from Python

#### VC-30: Testing Infrastructure
- [ ] Property-based testing for effect handlers
- [ ] Integration tests for IPC
- [ ] Performance regression tests
- [ ] Coverage tracking

---

## Dependencies

- KOKA001 (completed): Initial gan_ying, hot_paths, unified_runtime ports
- Rust bridge (whitemagic-rust): For VC-18
- Zig SIMD (whitemagic-zig): For VC-14, VC-19
- Python dispatcher: For VC-01, VC-05, VC-24

## Risks

| Risk | Mitigation |
|------|------------|
| Koka compiler bugs | Test thoroughly, report upstream |
| IPC latency regression | Continuous benchmarking |
| Effect handler complexity | Start simple, iterate |
| Cross-language FFI issues | Isolate FFI layer, extensive testing |

## Success Metrics

- All 30 VCs completed
- Koka IPC latency < 100µs p95
- Unified dispatcher overhead < 10µs
- Zero production incidents from Koka integration
- Developer onboarding time < 1 hour

## Next Session Priorities

1. VC-01: Batch IPC Protocol (highest impact)
2. VC-05: Shared Memory Bridge
3. VC-08: Koka Module Imports
4. VC-12: LLVM JIT Compilation
