use pyo3::prelude::*;
use rayon::prelude::*;

#[pyclass]
pub struct AssociationMiner {
    min_support: f64,
}

#[pymethods]
impl AssociationMiner {
    #[new]
    fn new(min_support: f64) -> Self {
        Self { min_support }
    }
}
