pub mod zodiac_ledger;
pub mod dharma_engine;

use pyo3::prelude::*;

pub use zodiac_ledger::ZodiacLedger;
pub use dharma_engine::DharmaEngine;

pub fn sutra_kernel(_py: Python<'_>, m: &Bound<'_, PyModule>) -> PyResult<()> {
    m.add_class::<ZodiacLedger>()?;
    m.add_class::<DharmaEngine>()?;
    Ok(())
}
