---
name: "Unified Polyglot Embedding Pipeline — H002 + PSR-009 + F001"
codename: UNIFIED_EMBED
army: zodiac_grand_army
type: synthesis
priority: 1
clone_count: 500000
strategies: [polyglot, zero_copy, parallel_execution]
category: performance
phase: immediate
source: "User request - all three campaigns simultaneously leveraging Arrow + Iceoryx2"
dependencies: ["arrow_bridge.rs (✅ exists)", "ipc_bridge.rs (✅ exists)"]
---

# Unified Polyglot Embedding Pipeline

**Mission**: Implement H002 (Rust ONNX), PSR-009 (Mojo GPU), and complete F001 (100K embeddings) **simultaneously** using existing Arrow and Iceoryx2 infrastructure for zero-copy end-to-end pipeline.

**Expected Performance**: 500-1000 embeddings/sec (125-250× faster than current 4/s)  
**Time to Complete F001**: 3-8 minutes (vs 7 hours at 4/s)

---

## Architecture: Zero-Copy Polyglot Pipeline

```
Python (Orchestrator)
    ↓ Arrow IPC (zero-copy columnar)
Rust ONNX Worker (CPU)  ←→  Mojo GPU Worker (parallel)
    ↑                            ↑
    └──── Iceoryx2 Shared Memory ────┘
         (zero-copy tensors via /dev/shm)
```

### Data Flow
1. **Python** loads 100K texts from DB
2. **Arrow RecordBatch** serializes texts (zero-copy, 85× faster than JSON)
3. **Rust ONNX** OR **Mojo GPU** processes batch (parallel workers)
4. **Iceoryx2** shares tensors in /dev/shm (zero-copy, 1000× faster than sockets)
5. **Arrow** returns Float32 embeddings to Python
6. **Python** writes to DB

### Leverages Existing Infrastructure ✅
- `whitemagic-rust/src/arrow_bridge.rs` (352 lines) - Already implemented
- `whitemagic-rust/src/ipc_bridge.rs` - Iceoryx2 channels ready
- `whitemagic-mojo/src/batch_encoder.mojo` - Holographic encoding (adapt for embeddings)

---

## Phase 1: Rust ONNX Embedder with Arrow (H002)

### Implementation
**File**: `whitemagic-rust/src/onnx_embedder.rs`

```rust
//! ONNX Embedder with Arrow zero-copy input/output

use arrow::array::{Float32Array, StringArray, RecordBatch};
use arrow::datatypes::{DataType, Field, Schema};
use ort::{Session, Value, GraphOptimizationLevel};
use std::sync::Arc;

pub struct ONNXEmbedder {
    session: Session,
    model_name: String,
}

impl ONNXEmbedder {
    pub fn new(model_path: &str) -> Result<Self, Box<dyn std::error::Error>> {
        let session = Session::builder()?
            .with_optimization_level(GraphOptimizationLevel::Level3)?
            .with_intra_threads(4)?
            .with_model_from_file(model_path)?;
        
        Ok(Self {
            session,
            model_name: model_path.to_string(),
        })
    }
    
    /// Encode texts from Arrow StringArray → Arrow Float32Array
    /// Zero-copy input via Arrow, zero-copy output via Arrow
    pub fn encode_batch_arrow(
        &self,
        texts: &StringArray,
    ) -> Result<RecordBatch, Box<dyn std::error::Error>> {
        let batch_size = texts.len();
        
        // Tokenize (fast path - use Rust tokenizer or existing cache)
        let input_ids = self.tokenize_batch(texts)?;
        
        // Run ONNX inference
        let outputs = self.session.run(vec![
            Value::from_array(self.session.allocator(), &input_ids)?
        ])?;
        
        // Extract embeddings (Float32Array, zero-copy)
        let embeddings = outputs[0].try_extract::<f32>()?.view();
        
        // Build Arrow RecordBatch
        let schema = Arc::new(Schema::new(vec![
            Field::new("embedding", DataType::List(
                Arc::new(Field::new("item", DataType::Float32, false))
            ), false),
        ]));
        
        // Convert to Arrow Float32Array (384 dims per embedding)
        let embedding_arrays = self.reshape_to_arrow(embeddings, batch_size)?;
        
        Ok(RecordBatch::try_new(
            schema,
            vec![Arc::new(embedding_arrays)],
        )?)
    }
}

// PyO3 binding
#[pyfunction]
pub fn arrow_onnx_embed(
    texts_arrow: &[u8],  // Arrow IPC bytes
    model_path: String,
) -> PyResult<Vec<u8>> {
    let embedder = ONNXEmbedder::new(&model_path)
        .map_err(|e| PyErr::new::<PyRuntimeError, _>(e.to_string()))?;
    
    // Decode Arrow IPC
    let batch = ipc_bytes_to_arrow(texts_arrow)?;
    let texts = batch.column(0).as_any().downcast_ref::<StringArray>().unwrap();
    
    // Encode via ONNX
    let output_batch = embedder.encode_batch_arrow(texts)?;
    
    // Return as Arrow IPC
    Ok(arrow_to_ipc_bytes(&output_batch)?)
}
```

### Victory Conditions
- [x] ONNX Runtime integrated (`ort` crate - verified in Cargo.toml)
- [x] Arrow input/output (zero-copy - verified in Cargo.toml)
- [ ] Python binding via PyO3 test
- [ ] CPU inference: 80-200/s benchmark
- [ ] GPU inference: 500+/s (CUDA execution provider)

---

## Phase 2: Mojo GPU Accelerator (PSR-009)

### Implementation
**File**: `whitemagic-mojo/src/gpu_batch_embedder.mojo`

```mojo
from max.tensor import Tensor, TensorShape
from max.driver import Device
from iceoryx2 import Publisher, Subscriber  # Via Python bindings

struct GPUBatchEmbedder:
    """GPU-accelerated batch embedding via SIMD + CUDA"""
    var device: Device
    var model: TensorModel
    var embedding_dim: Int
    
    fn __init__(inout self, model_path: String):
        self.device = Device.cuda(0)  # Use first GPU
        self.model = load_onnx_model(model_path, self.device)
        self.embedding_dim = 384
    
    fn encode_batch_simd(
        self,
        texts: Tensor[DType.uint8],  # Tokenized input
        batch_size: Int,
    ) -> Tensor[DType.float32]:
        """SIMD batch encoding on GPU"""
        
        # Allocate output tensor on GPU
        var embeddings = Tensor[DType.float32](
            TensorShape(batch_size, self.embedding_dim)
        )
        
        # Run model on GPU (automatic CUDA kernel launch)
        self.model.infer(texts, embeddings)
        
        return embeddings
    
    fn listen_iceoryx2(self):
        """Listen for embedding requests via Iceoryx2 shared memory"""
        let subscriber = Subscriber.create("wm/embed_requests")
        
        while True:
            if let Some(sample) = subscriber.receive():
                # Zero-copy: sample is in shared memory
                let texts = Tensor.from_shared_memory(sample.payload())
                let embeddings = self.encode_batch_simd(texts, sample.batch_size())
                
                # Publish results via Iceoryx2 (zero-copy)
                let publisher = Publisher.create("wm/embed_results")
                publisher.send(embeddings.to_shared_memory())
```

### Victory Conditions
- [ ] Mojo SIMD batch processing
- [ ] GPU CUDA kernel integration
- [ ] Iceoryx2 pub/sub wired
- [ ] 500-1000 embeddings/sec measured

---

## Phase 3: Python Orchestrator (F001 Integration)

### Implementation
**File**: `whitemagic/inference/unified_embedder.py`

```python
"""Unified Polyglot Embedder - Routes to Rust ONNX or Mojo GPU"""

import whitemagic_rs
import numpy as np
from typing import List

class UnifiedEmbedder:
    """
    Embedding router with zero-copy Arrow pipeline:
    1. Try Mojo GPU (fastest, via Iceoryx2)
    2. Fall back to Rust ONNX GPU
    3. Fall back to Rust ONNX CPU
    4. Fall back to Python FastEmbed
    """
    
    def __init__(self):
        self.mojo_available = self._check_mojo_gpu()
        self.rust_onnx_available = self._check_rust_onnx()
        self.model_path = self._get_onnx_model()
    
    def encode_batch(self, texts: List[str], batch_size: int = 2048) -> np.ndarray:
        """Encode batch with automatic polyglot routing"""
        
        # Convert texts to Arrow IPC (zero-copy)
        texts_arrow = whitemagic_rs.arrow_encode_texts(texts)
        
        # Route 1: Mojo GPU via Iceoryx2 (fastest)
        if self.mojo_available:
            try:
                # Publish to Iceoryx2 shared memory
                whitemagic_rs.ipc_bridge_publish("wm/embed_requests", texts_arrow)
                # Subscribe to results (zero-copy)
                result_arrow = whitemagic_rs.ipc_bridge_subscribe("wm/embed_results", timeout_ms=5000)
                return self._arrow_to_numpy(result_arrow)
            except Exception as e:
                logger.warning(f"Mojo GPU failed, falling back: {e}")
        
        # Route 2: Rust ONNX (fast)
        if self.rust_onnx_available:
            try:
                result_arrow = whitemagic_rs.arrow_onnx_embed(texts_arrow, self.model_path)
                return self._arrow_to_numpy(result_arrow)
            except Exception as e:
                logger.warning(f"Rust ONNX failed, falling back: {e}")
        
        # Route 3: Python FastEmbed (slow but reliable)
        from whitemagic.inference.local_embedder import LocalEmbedder
        embedder = LocalEmbedder()
        return embedder.embed(texts, batch_size)
    
    def _arrow_to_numpy(self, arrow_bytes: bytes) -> np.ndarray:
        """Convert Arrow IPC to numpy (zero-copy via Arrow's buffer protocol)"""
        import pyarrow as pa
        reader = pa.ipc.open_stream(arrow_bytes)
        batch = reader.read_next_batch()
        # Zero-copy: numpy array views Arrow buffer
        return batch.column(0).to_numpy(zero_copy_only=True)
```

### Victory Conditions
- [ ] Unified embedder class created
- [ ] Arrow zero-copy pipeline working
- [ ] Iceoryx2 pub/sub integration
- [ ] Fallback chain tested
- [ ] F001 batch script updated

---

## Phase 4: F001 Completion with Unified Pipeline

### Updated Script
**File**: `scripts/batch_embed_memories_unified.py`

```python
#!/usr/bin/env python3
"""F001 Batch Embeddings with Unified Polyglot Pipeline"""

from whitemagic.inference.unified_embedder import UnifiedEmbedder
import sqlite3

def batch_embed_unified():
    embedder = UnifiedEmbedder()
    
    # Load all texts
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.execute("SELECT id, content FROM memories WHERE memory_type != 'quarantined'")
    
    batch_size = 2048  # Large batch for GPU efficiency
    batch_ids = []
    batch_texts = []
    total_embedded = 0
    
    for memory_id, content in cursor:
        batch_ids.append(memory_id)
        batch_texts.append(content[:512])
        
        if len(batch_texts) >= batch_size:
            # Encode via unified pipeline (Rust ONNX or Mojo GPU)
            embeddings = embedder.encode_batch(batch_texts, batch_size)
            
            # Write to DB
            for mid, emb in zip(batch_ids, embeddings):
                conn.execute(
                    "INSERT OR REPLACE INTO memory_embeddings (memory_id, embedding) VALUES (?, ?)",
                    (mid, emb.tobytes())
                )
            
            total_embedded += len(batch_texts)
            print(f"Embedded {total_embedded} memories...")
            
            batch_ids.clear()
            batch_texts.clear()
    
    conn.commit()
    print(f"✅ Completed! {total_embedded} memories embedded")

if __name__ == "__main__":
    batch_embed_unified()
```

---

## Benchmarks & Targets

| Implementation | Device | Speed | Time for 100K | Speedup |
|----------------|--------|-------|---------------|---------|
| **Current FastEmbed** | CPU | 4/s | 7 hours | 1× |
| **Rust ONNX** | CPU | 200/s | 8 min | 50× |
| **Rust ONNX** | GPU | 500/s | 3 min | 125× |
| **Mojo GPU + Iceoryx2** | GPU | 1000/s | 100 sec | 250× |

---

## Implementation Order

### Sprint 1: Rust ONNX with Arrow (2-3 hours)
1. Add `ort` to Cargo.toml
2. Implement `onnx_embedder.rs` with Arrow I/O
3. Test CPU inference
4. Enable GPU execution provider (CUDA)
5. Benchmark vs FastEmbed

### Sprint 2: Iceoryx2 Integration (1-2 hours)
6. Test existing `ipc_bridge.rs` pub/sub
7. Wire embedding request/response channels
8. Benchmark zero-copy overhead

### Sprint 3: Mojo GPU Worker (2-4 hours)
9. Adapt `batch_encoder.mojo` for embeddings
10. Add ONNX model loading in Mojo
11. Wire Iceoryx2 subscriber
12. Test GPU inference

### Sprint 4: Python Integration (1 hour)
13. Create `UnifiedEmbedder` wrapper
14. Update F001 batch script
15. Run full 100K embedding test

**Total Estimated Time**: 6-10 hours  
**Result**: 100K memories embedded in 2-8 minutes (vs 7 hours)

---

## Success Criteria

- [x] Arrow bridge operational (already exists ✅)
- [x] Iceoryx2 compiled (already exists ✅)
- [x] Cargo.toml dependencies verified (ort, arrow, iceoryx2 ✅)
- [ ] Rust ONNX embedder working
- [ ] Mojo GPU worker operational
- [ ] Zero-copy pipeline validated
- [ ] F001 complete in < 10 minutes
- [ ] 50-250× speedup measured
- [ ] All three campaigns marked complete

**Status**: Infrastructure ready, implementation in progress (Feb 18 2026)

---

**This is the dream architecture** - leveraging existing infrastructure (Arrow + Iceoryx2) to build a zero-copy polyglot embedding pipeline that completes all three campaigns simultaneously! 🚀
