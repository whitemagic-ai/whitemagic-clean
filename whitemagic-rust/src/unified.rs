use pyo3::prelude::*;

#[pyclass]
pub struct UnifiedMemory {
    capacity: usize,
}

#[pymethods]
impl UnifiedMemory {
    #[new]
    fn new(capacity: usize) -> Self {
        Self { capacity }
    }
}
