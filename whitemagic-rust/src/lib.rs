use pyo3::prelude::*;

mod embeddings;
mod consolidation;
mod association_miner;
mod unified;
mod graph_walker;

#[pymodule]
fn whitemagic_rust(_py: Python, m: &PyModule) -> PyResult<()> {
    m.add_class::<embeddings::EmbeddingEngine>()?;
    m.add_class::<consolidation::ConsolidationEngine>()?;
    m.add_class::<association_miner::AssociationMiner>()?;
    m.add_class::<unified::UnifiedMemory>()?;
    m.add_class::<graph_walker::GraphWalker>()?;
    Ok(())
}
