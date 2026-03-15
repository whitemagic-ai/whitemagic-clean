// Conditional compilation for Python vs WASM
#[cfg(feature = "python")]
use pyo3::prelude::*;

#[cfg(feature = "wasm")]
use wasm_bindgen::prelude::*;

// Conductor module (ResonanceConductor - unified orchestration)
#[cfg(not(feature = "wasm"))]
pub mod conductor;

// Python modules (only compiled for Python target)
#[cfg(feature = "python")]
mod embeddings;
#[cfg(feature = "python")]
mod consolidation;
#[cfg(feature = "python")]
mod association_miner;
#[cfg(feature = "python")]
mod unified;
#[cfg(feature = "python")]
mod graph_walker;
#[cfg(feature = "python")]
mod graph_engine;
#[cfg(feature = "python")]
mod hnsw_index;
#[cfg(feature = "python")]
mod simhash_lsh;
#[cfg(feature = "python")]
mod galaxy_miner;
#[cfg(feature = "python")]
mod recursive_intelligence;
#[cfg(feature = "python")]
mod sutra_kernel;
#[cfg(feature = "python")]
pub mod search;
pub mod hot_paths;
pub mod arrow_bridge;
#[cfg(feature = "python")]
mod holographic_encoder_5d;
#[cfg(feature = "python")]
mod constellations;
#[cfg(feature = "python")]
mod galactic_accelerator;
#[cfg(feature = "python")]
mod native_ffi;
#[cfg(feature = "python")]
mod massive_deployer;
#[cfg(feature = "python")]
mod ipc_bridge;
#[cfg(feature = "python")]
mod prat_router_v6;
#[cfg(feature = "python")]
mod continuous_daemon;

// WASM-specific module
#[cfg(feature = "wasm")]
mod wasm;

// Python module
#[cfg(feature = "python")]
#[pymodule]
fn whitemagic_rust(_py: Python<'_>, m: &Bound<'_, PyModule>) -> PyResult<()> {
    m.add_class::<embeddings::EmbeddingEngine>()?;
    m.add_class::<consolidation::ConsolidationEngine>()?;
    m.add_class::<association_miner::AssociationMiner>()?;
    m.add_class::<unified::UnifiedMemory>()?;
    m.add_class::<graph_walker::GraphWalker>()?;

    // Add arrow_bridge sub-module
    let arrow_bridge_module = PyModule::new_bound(_py, "arrow_bridge")?;
    arrow_bridge::arrow_bridge(_py, &arrow_bridge_module)?;
    m.add_submodule(&arrow_bridge_module)?;

    // Add sutra_kernel sub-module
    let sutra_kernel_module = PyModule::new_bound(_py, "sutra_kernel")?;
    sutra_kernel::sutra_kernel(_py, &sutra_kernel_module)?;
    m.add_submodule(&sutra_kernel_module)?;
    
    // Add constellations sub-module
    let constellations_module = PyModule::new_bound(_py, "constellations")?;
    constellations::constellations(_py, &constellations_module)?;
    m.add_submodule(&constellations_module)?;
    
    // Add galactic_accelerator functions directly to main module for backward compatibility
    m.add_function(wrap_pyfunction!(galactic_accelerator::galactic_batch_score, m)?)?;
    m.add_function(wrap_pyfunction!(galactic_accelerator::galactic_batch_score_quick, m)?)?;
    m.add_function(wrap_pyfunction!(galactic_accelerator::galactic_decay_drift, m)?)?;
    m.add_function(wrap_pyfunction!(galactic_accelerator::galactic_zone_counts, m)?)?;
    
    // Register native FFI functions
    native_ffi::register_native_ffi(m)?;
    
    // Add massive_deployer classes
    m.add_class::<massive_deployer::MassiveDeployer>()?;
    m.add_class::<massive_deployer::CampaignTask>()?;
    m.add_function(wrap_pyfunction!(massive_deployer::create_massive_deployer, m)?)?;
    m.add_function(wrap_pyfunction!(massive_deployer::benchmark_rust_vs_python, m)?)?;
    
    // Register prat router functions
    prat_router_v6::register_prat_router(m)?;
    
    // Register continuous daemon
    continuous_daemon::register_daemon(m)?;
    
    // Add graph_engine sub-module
    let graph_engine_module = PyModule::new_bound(_py, "graph_engine")?;
    graph_engine::graph_engine(_py, &graph_engine_module)?;
    m.add_submodule(&graph_engine_module)?;
    
    // Add hnsw_index sub-module
    let hnsw_index_module = PyModule::new_bound(_py, "hnsw_index")?;
    hnsw_index::hnsw_index(_py, &hnsw_index_module)?;
    m.add_submodule(&hnsw_index_module)?;

    // Add simhash_lsh sub-module
    let simhash_module = PyModule::new_bound(_py, "simhash_lsh")?;
    simhash_lsh::simhash_lsh(_py, &simhash_module)?;
    m.add_submodule(&simhash_module)?;
    
    // Add galaxy_miner sub-module
    let galaxy_miner_module = PyModule::new_bound(_py, "galaxy_miner")?;
    galaxy_miner::galaxy_miner(_py, &galaxy_miner_module)?;
    m.add_submodule(&galaxy_miner_module)?;
    
    // Add recursive_intelligence sub-module
    let recursive_intelligence_module = PyModule::new_bound(_py, "recursive_intelligence")?;
    recursive_intelligence::recursive_intelligence(_py, &recursive_intelligence_module)?;
    m.add_submodule(&recursive_intelligence_module)?;
    
    // Add holographic_encoder_5d sub-module
    let holographic_module = PyModule::new_bound(_py, "holographic_encoder_5d")?;
    holographic_encoder_5d::register_holographic_encoder(_py, &holographic_module)?;
    m.add_submodule(&holographic_module)?;
    

    // Add ipc_bridge sub-module
    let ipc_bridge_module = PyModule::new_bound(_py, "ipc_bridge")?;
    ipc_bridge::ipc_bridge(_py, &ipc_bridge_module)?;
    m.add_submodule(&ipc_bridge_module)?;
    
    // Add conductor sub-module
    let conductor_module = PyModule::new_bound(_py, "conductor")?;
    conductor::ffi::conductor(_py, &conductor_module)?;
    m.add_submodule(&conductor_module)?;
    
    // Add search functions directly to main module
    m.add_function(wrap_pyfunction!(search::search_build_index, m)?)?;
    m.add_function(wrap_pyfunction!(search::search_query, m)?)?;
    m.add_function(wrap_pyfunction!(search::search_fuzzy, m)?)?;
    m.add_function(wrap_pyfunction!(search::search_and_query, m)?)?;
    m.add_function(wrap_pyfunction!(search::search_stats, m)?)?;
    
    // Add hot_paths functions directly to main module
    hot_paths::hot_paths(_py, m)?;

    Ok(())
}

// WASM exports - re-export from wasm module
#[cfg(feature = "wasm")]
pub use wasm::*;


pub mod monte_carlo;
