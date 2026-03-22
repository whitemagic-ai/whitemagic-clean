---
name: "Pure Rust AST Gene Scanner"
codename: "EVO001"
army: "beta"
type: "batch_transform"
priority: "P1"
clone_count: 50000
strategies: ["map_reduce", "parallel_processing"]
category: "foundation"
phase: "immediate"
source: "DEEP_ANALYSIS_GENE_EFFICIENCY.md - Phase 1"
column_size: 3
---

## Objective

Build a pure Rust AST-based gene scanner using Tree-sitter to extract 200-500 deep code patterns from WhiteMagic codebase. This is the **highest priority** campaign as it accelerates all other work by providing the expanded gene library needed for effective evolution.

**Why Pure Rust?**
- 10-50x faster than Python AST parsing
- Memory safety (no crashes on large codebases)
- True parallelism with Rayon (no GIL)
- Tree-sitter integration (best AST parser available)
- Zero-cost abstractions

**Impact**: Expands gene vault from 34 → 234+ patterns, enabling breakthrough evolution results.

## Victory Conditions

- [ ] Rust scanner compiles successfully with all dependencies
- [ ] Scans Python files using tree-sitter-python
- [ ] Scans Rust files using tree-sitter-rust
- [ ] Detects algorithmic patterns (BFS, DFS, Dijkstra, A*, DP)
- [ ] Detects design patterns (Factory, Observer, Strategy)
- [ ] Detects concurrency patterns (async, threading, pools)
- [ ] Detects error handling patterns (retry, fallback, circuit breaker)
- [ ] Detects WhiteMagic domain patterns (memory, dream, resonance)
- [ ] Processes 2,217 files in < 60 seconds
- [ ] Outputs valid JSON gene vault (gene_vault_deep.json)
- [ ] Finds 200+ unique patterns
- [ ] Includes pattern metadata (frequency, examples, synergies)
- [ ] No crashes or panics during execution
- [ ] Memory usage stays < 500MB

## Targets

| Pattern Category | Target Count | Examples |
|-----------------|--------------|----------|
| Algorithmic | 50-100 | BFS, DFS, Dijkstra, A*, binary search, DP |
| Design Patterns | 20-30 | Factory, Observer, Strategy, Adapter, Decorator |
| Concurrency | 15-25 | async/await, ThreadPool, Lock patterns, async context managers |
| Error Handling | 10-20 | retry with backoff, fallback chains, circuit breaker |
| Domain (WhiteMagic) | 30-50 | memory consolidation, dream phases, holographic encoding, resonance |
| Optimization | 30-50 | zero-copy, SIMD, vectorization, caching strategies |
| Rust-specific | 20-30 | lifetimes, traits, zero-cost abstractions |
| **Total** | **200-500** | Comprehensive pattern library |

## Strategy

### Phase 1: Setup & Dependencies (5K clones)
1. Create Cargo.toml with dependencies:
   - tree-sitter 0.20
   - tree-sitter-python 0.20
   - tree-sitter-rust 0.20
   - walkdir 2.4
   - serde + serde_json 1.0
   - rayon 1.8
   - regex 1.10
   - ahash 0.8
   - clap 4.4

2. Verify all dependencies compile
3. Set up project structure

### Phase 2: Core Scanner Implementation (15K clones)
1. Implement `PatternScanner` struct with Python/Rust parsers
2. Add file walking with walkdir
3. Implement parallel processing with Rayon
4. Add pattern detection methods for each category
5. Implement synergy detection
6. Add JSON serialization

### Phase 3: Pattern Detection (20K clones)
1. **Algorithmic patterns**:
   - Graph algorithms (BFS, DFS, Dijkstra, A*)
   - Search algorithms (binary search, linear search)
   - Dynamic programming (memoization, DP tables)
   - Sorting patterns

2. **Design patterns**:
   - Creational (Factory, Builder, Singleton)
   - Structural (Adapter, Decorator, Facade)
   - Behavioral (Observer, Strategy, Command)

3. **Concurrency patterns**:
   - Async/await usage
   - Thread pools
   - Lock patterns
   - Async context managers

4. **Error handling**:
   - Retry with backoff
   - Fallback chains
   - Circuit breaker
   - Graceful degradation

5. **Domain patterns** (WhiteMagic):
   - Memory consolidation
   - Dream cycle phases
   - Holographic encoding
   - Resonance detection
   - Galactic positioning

### Phase 4: Testing & Validation (5K clones)
1. Test on small sample (10 files)
2. Test on medium sample (100 files)
3. Test on full WhiteMagic codebase (2,217 files)
4. Verify pattern counts
5. Validate JSON output
6. Check memory usage
7. Measure performance

### Phase 5: Optimization & Deployment (5K clones)
1. Profile hot paths
2. Optimize pattern detection
3. Tune parallel processing
4. Build release binary
5. Document usage
6. Create integration script

## Verification

**Automated Checks**:
```bash
# Compile check
cd rust_gene_scanner && cargo build --release

# Run on WhiteMagic
./target/release/gene-scanner \
  /home/lucas/Desktop/whitemagicpublic \
  /home/lucas/Desktop/whitemagicdev \
  --output gene_vault_deep.json \
  --min-frequency 2

# Verify output
python3 << EOF
import json
vault = json.load(open('gene_vault_deep.json'))
assert vault['total_genes'] >= 200, f"Only {vault['total_genes']} patterns found"
assert vault['total_files_scanned'] >= 2000, "Not enough files scanned"
print(f"✅ Found {vault['total_genes']} patterns from {vault['total_files_scanned']} files")
EOF
```

**Manual Checks**:
- Review pattern quality
- Verify examples are correct
- Check synergies make sense
- Confirm no duplicates

## Success Metrics

- **Pattern count**: 200+ unique patterns
- **Scan speed**: < 60 seconds for 2,217 files
- **Memory usage**: < 500MB peak
- **Accuracy**: 95%+ patterns are valid
- **Coverage**: All major pattern categories represented

## Dependencies

None (this is the foundation campaign)

## Enables

- EVO002 (Validation Framework Enhancement)
- EVO003 (Benchmark Suite Creation)
- EVO004 (Self-Expanding Vault Integration)
- All Week 2-4 campaigns (need expanded gene library)
