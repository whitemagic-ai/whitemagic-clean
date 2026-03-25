# Polyglot Acceleration Roadmap

## Phase 1: Rust Vector Operations [HIGH PRIORITY]

**Target Functions:**
- cosine_similarity
- batch_similarities
- vector_search
- dot_product
- normalize

**Implementation:**
```rust
// whitemagic-rust/src/vector_ops.rs
use pyo3::prelude::*;
use rayon::prelude::*;

#[pyfunction]
pub fn batch_cosine_similarity(
    query: Vec<f32>,
    vectors: Vec<Vec<f32>>
) -> PyResult<Vec<f32>> {
    Ok(vectors.par_iter()
        .map(|v| cosine_sim(&query, v))
        .collect())
}
```

## Phase 2: Rust Search Operations [HIGH PRIORITY]

**Target Functions:**
- search_memories
- hybrid_recall
- fts_search
- regex_search

**Implementation:**
```rust
// whitemagic-rust/src/search_ops.rs
use tantivy::*;

#[pyfunction]
pub fn fast_search(
    query: String,
    index_path: String
) -> PyResult<Vec<(String, f32)>> {
    // Tantivy-based full-text search
}
```

## Phase 3: Mojo ML Operations [HIGH PRIORITY]

**Target Functions:**
- embed
- encode
- generate_embedding
- batch_embed

**Implementation:**
```mojo
# wm2/polyglot/mojo/ml_ops.mojo
from tensor import Tensor
from algorithm import vectorize

fn batch_embed(texts: List[String]) -> Tensor[DType.float32]:
    # SIMD-accelerated embedding generation
    pass
```

## Phase 4: Rust Compression [MEDIUM PRIORITY]

**Target Functions:**
- compress
- decompress
- gzip_compress
- lz4_compress

**Already Implemented:**
- ✅ fast_compress (gzip)
- ✅ fast_decompress (gzip)
- ⏳ Wire to Python hot paths
