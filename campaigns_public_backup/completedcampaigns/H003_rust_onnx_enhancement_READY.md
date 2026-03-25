---
name: "Rust ONNX Enhancement — V17 Speed Boost"
codename: H003
army: beta
type: enhancement
priority: 3
strategies:
  - polyglot_acceleration
  - rust_hot_path
category: infrastructure
phase: post_v17
source: "V17 success enables optional Rust ONNX for additional 2-3x speedup"
---

# Rust ONNX Enhancement — Post-V17 Speed Boost

## Status: READY TO IMPLEMENT

**V17 achieved 1,216 embeddings/sec on CPU alone (target: 1,000+).**

This campaign provides an **optional 2-3x additional speedup** using Rust ONNX runtime for production deployments requiring maximum throughput.

---

## Objective

Enhance V17's embedding pipeline with optional Rust ONNX backend:
- **Current**: 1,216/sec (Python + ThreadPool + bounded concurrency)
- **With Rust ONNX**: 2,500-3,500/sec (CPU) or 10,000+/sec (GPU)
- **Use case**: Production deployments needing >1,000/sec sustained

---

## Why Rust ONNX Now?

**V17 proved the architecture works.** With bounded concurrency + bulk operations validated, we can now safely add Rust as an optional backend:

| V17 Achievement | Enables |
|---------------|---------|
| Bounded concurrency pattern | Rust async/await with Tokio |
| Bulk INSERT architecture | Arrow IPC zero-copy batches |
| 304x speedup proven | Rust adds 2-3x on top |
| Connection pooling | Rust SQLx async pool |

---

## Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│                     V17 + Rust ONNX Hybrid                       │
├─────────────────────────────────────────────────────────────────┤
│                                                                   │
│  ┌──────────────┐    ┌──────────────┐    ┌──────────────┐      │
│  │ Text Batch   │───→│ Arrow IPC    │───→│ Rust ONNX    │      │
│  │ (Python)     │    │ (zero-copy)  │    │ Runtime      │      │
│  └──────────────┘    └──────────────┘    └──────────────┘      │
│                                                 │                │
│                                                 ▼                │
│                                        ┌──────────────┐       │
│                                        │ Embeddings   │       │
│                                        │ (f32[384])   │       │
│                                        └──────────────┘       │
│                                                 │                │
│                                                 ▼                │
│                                        ┌──────────────┐       │
│                                        │ Arrow IPC    │──────→│ Python
│                                        │ (return)     │       │ Bulk
│                                        └──────────────┘       │ Insert
│                                                                   │
└─────────────────────────────────────────────────────────────────┘
```

---

## Implementation Plan

### Phase 1: Rust ONNX Embedder (READY)

File: `whitemagic-rust/src/bin/onnx_embedder.rs`

```rust
use ort::{Environment, Session, Value};
use arrow::array::{StringArray, Float32Array};
use arrow::ipc::writer::StreamWriter;

#[tokio::main]
async fn main() -> Result<()> {
    // Load ONNX model (all-MiniLM-L6-v2 quantized)
    let env = Environment::builder()
        .with_name("embedding_runtime")
        .build()?;
    
    let session = env
        .new_session_builder()?
        .with_model_from_file("models/all-MiniLM-L6-v2.onnx")?;
    
    // Process Arrow IPC input
    let input = read_arrow_ipc_batch().await?;
    let texts: Vec<&str> = input.column(0).as_string().iter().flatten().collect();
    
    // Batch encode with ONNX Runtime
    let embeddings = session.run(vec![texts])?;
    
    // Return via Arrow IPC
    write_arrow_ipc_batch(embeddings).await?;
    Ok(())
}
```

### Phase 2: Python Bridge (READY)

File: `whitemagic/core/memory/rust_onnx_bridge.py`

```python
import subprocess
import pyarrow as pa

class RustOnnxBridge:
    """Zero-copy bridge to Rust ONNX embedder"""
    
    def encode_batch(self, texts: list[str]) -> list[list[float]]:
        # Serialize to Arrow IPC
        batch = pa.record_batch([pa.array(texts)], names=["text"])
        ipc_bytes = batch.serialize()
        
        # Spawn Rust process with Arrow IPC
        result = subprocess.run(
            ["./whitemagic-rust/onnx_embedder"],
            input=ipc_bytes,
            capture_output=True
        )
        
        # Deserialize Arrow IPC result
        embeddings = pa.ipc.deserialize(result.stdout)
        return embeddings.column("embedding").to_pylist()
```

### Phase 3: V17 Integration (READY)

File: `whitemagic/core/memory/v17_embedding_optimizer.py`

```python
class V17EmbeddingOptimizer:
    def __init__(self, engine, use_rust_onnx: bool = False):
        self.engine = engine
        self.use_rust_onnx = use_rust_onnx
        self._rust_bridge = RustOnnxBridge() if use_rust_onnx else None
    
    async def _encode_batch_bounded(self, tasks: list[EmbeddingTask]) -> list[EmbeddingTask]:
        if self.use_rust_onnx and self._rust_bridge:
            # Use Rust ONNX for 2-3x speedup
            texts = [t.text for t in tasks]
            embeddings = await asyncio.get_event_loop().run_in_executor(
                None, self._rust_bridge.encode_batch, texts
            )
            for task, embedding in zip(tasks, embeddings):
                task.result = embedding
        else:
            # Fall back to Python (V17 default)
            ...
```

---

## Victory Conditions

- [ ] Rust ONNX embedder binary builds successfully
- [ ] Arrow IPC zero-copy serialization works
- [ ] Python bridge integrates with V17 optimizer
- [ ] 2,500+ embeddings/sec achieved (2x V17)
- [ ] 3,500+ embeddings/sec on GPU (optional)
- [ ] Feature flag enables gradual rollout
- [ ] Falls back to Python if Rust unavailable

---

## Performance Targets

| Configuration | Expected Rate | Use Case |
|--------------|---------------|----------|
| V17 (Python) | 1,216/sec | Default, universal |
| V17 + Rust ONNX (CPU) | 2,500-3,000/sec | Production CPU-max |
| V17 + Rust ONNX (GPU) | 8,000-12,000/sec | GPU deployments |

---

## Files to Create

1. `whitemagic-rust/src/bin/onnx_embedder.rs` — Rust ONNX runtime
2. `whitemagic/core/memory/rust_onnx_bridge.py` — Python bridge
3. `whitemagic/core/memory/v17_rust_integration.py` — V17 integration
4. `scripts/benchmark_rust_onnx.py` — Performance validation

---

## Dependencies

```toml
# whitemagic-rust/Cargo.toml
[dependencies]
ort = "2.0"              # ONNX Runtime
arrow = "50.0"           # Arrow IPC
tokio = { version = "1", features = ["full"] }
serde = { version = "1.0", features = ["derive"] }
```

```bash
# Python
pip install pyarrow onnxruntime
```

---

## Risk Mitigation

| Risk | Mitigation |
|------|-----------|
| Rust build complexity | Pre-built binaries for common platforms |
| ONNX model compatibility | Test with all-MiniLM-L6-v2 only |
| Memory pressure | Arrow IPC prevents copies |
| Fallback failure | Graceful Python fallback always available |

---

## Next Steps

1. **Build Rust ONNX embedder** (2-3 hours)
   - Download all-MiniLM-L6-v2 ONNX model
   - Implement Arrow IPC I/O
   - Add Tokio async runtime

2. **Python bridge** (1-2 hours)
   - Arrow IPC serialization
   - Subprocess spawn with IPC
   - Error handling + fallback

3. **V17 integration** (1 hour)
   - Feature flag in optimizer
   - Benchmark comparison
   - Gradual rollout plan

---

## Conclusion

**H003 is READY TO IMPLEMENT.**

V17's success (1,216/sec) proves the architecture. Rust ONNX adds an **optional 2-3x boost** for production deployments. The Alienware GPU emergency is **cancelled** — CPU-only V17 exceeds targets, and Rust ONNX is now a **value-add enhancement**, not a requirement.

**Total time to implement: 4-6 hours**
**Expected outcome: 2,500-3,500 embeddings/sec**

---

*Campaign Date: 2026-02-18*
*Status: READY — awaiting implementation go-ahead*
*Blocked by: Nothing (V17 unblocked everything)*
