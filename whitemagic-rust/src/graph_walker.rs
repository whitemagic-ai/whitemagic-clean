use pyo3::prelude::*;

#[pyclass]
pub struct GraphWalker {
    max_depth: usize,
}

#[pymethods]
impl GraphWalker {
    #[new]
    fn new(max_depth: usize) -> Self {
        Self { max_depth }
    }
}
