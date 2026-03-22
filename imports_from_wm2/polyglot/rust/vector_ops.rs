// WM2 Polyglot: Rust Vector Operations
// =====================================
// High-performance vector operations for 10-100x speedup

use pyo3::prelude::*;
use rayon::prelude::*;
use std::f32;

/// Compute cosine similarity between two vectors
#[inline]
fn cosine_similarity(a: &[f32], b: &[f32]) -> f32 {
    if a.len() != b.len() {
        return 0.0;
    }
    
    let dot: f32 = a.iter().zip(b.iter()).map(|(x, y)| x * y).sum();
    let norm_a: f32 = a.iter().map(|x| x * x).sum::<f32>().sqrt();
    let norm_b: f32 = b.iter().map(|x| x * x).sum::<f32>().sqrt();
    
    if norm_a == 0.0 || norm_b == 0.0 {
        return 0.0;
    }
    
    dot / (norm_a * norm_b)
}

/// Batch compute cosine similarities (parallel)
#[pyfunction]
fn batch_cosine_similarity(query: Vec<f32>, vectors: Vec<Vec<f32>>) -> PyResult<Vec<f32>> {
    let results: Vec<f32> = vectors
        .par_iter()
        .map(|v| cosine_similarity(&query, v))
        .collect();
    
    Ok(results)
}

/// Compute dot product
#[pyfunction]
fn dot_product(a: Vec<f32>, b: Vec<f32>) -> PyResult<f32> {
    if a.len() != b.len() {
        return Err(PyErr::new::<pyo3::exceptions::PyValueError, _>(
            "Vectors must have same length"
        ));
    }
    
    let result: f32 = a.iter().zip(b.iter()).map(|(x, y)| x * y).sum();
    Ok(result)
}

/// Normalize vector to unit length
#[pyfunction]
fn normalize(mut vector: Vec<f32>) -> PyResult<Vec<f32>> {
    let norm: f32 = vector.iter().map(|x| x * x).sum::<f32>().sqrt();
    
    if norm == 0.0 {
        return Ok(vector);
    }
    
    for x in vector.iter_mut() {
        *x /= norm;
    }
    
    Ok(vector)
}

/// Batch normalize vectors (parallel)
#[pyfunction]
fn batch_normalize(vectors: Vec<Vec<f32>>) -> PyResult<Vec<Vec<f32>>> {
    let results: Vec<Vec<f32>> = vectors
        .into_par_iter()
        .map(|mut v| {
            let norm: f32 = v.iter().map(|x| x * x).sum::<f32>().sqrt();
            if norm > 0.0 {
                for x in v.iter_mut() {
                    *x /= norm;
                }
            }
            v
        })
        .collect();
    
    Ok(results)
}

/// Top-K similar vectors by cosine similarity
#[pyfunction]
fn top_k_similar(query: Vec<f32>, vectors: Vec<Vec<f32>>, k: usize) -> PyResult<Vec<(usize, f32)>> {
    let mut similarities: Vec<(usize, f32)> = vectors
        .par_iter()
        .enumerate()
        .map(|(idx, v)| (idx, cosine_similarity(&query, v)))
        .collect();
    
    // Sort by similarity (descending)
    similarities.sort_by(|a, b| b.1.partial_cmp(&a.1).unwrap());
    
    // Take top K
    similarities.truncate(k);
    
    Ok(similarities)
}

/// Python module
#[pymodule]
fn wm2_vector_ops(_py: Python, m: &PyModule) -> PyResult<()> {
    m.add_function(wrap_pyfunction!(batch_cosine_similarity, m)?)?;
    m.add_function(wrap_pyfunction!(dot_product, m)?)?;
    m.add_function(wrap_pyfunction!(normalize, m)?)?;
    m.add_function(wrap_pyfunction!(batch_normalize, m)?)?;
    m.add_function(wrap_pyfunction!(top_k_similar, m)?)?;
    Ok(())
}
