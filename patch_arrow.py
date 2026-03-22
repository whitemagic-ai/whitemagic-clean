import re

with open('whitemagic-rust/src/arrow_bridge.rs', 'r') as f:
    content = f.read()

replacement = """pub fn arrow_encode_memories<'py>(py: Python<'py>, json_str: &str) -> PyResult<Bound<'py, pyo3::types::PyBytes>> {
    let records: Vec<MemoryRecord> = serde_json::from_str(json_str)
        .map_err(|e| pyo3::exceptions::PyValueError::new_err(format!("JSON parse: {}", e)))?;

    #[cfg(feature = "arrow")]
    {
        let batch = memories_to_arrow(&records)
            .map_err(|e| pyo3::exceptions::PyRuntimeError::new_err(format!("Arrow: {}", e)))?;
        let ipc = arrow_to_ipc_bytes(&batch)
            .map_err(|e| pyo3::exceptions::PyRuntimeError::new_err(format!("IPC: {}", e)))?;
        Ok(pyo3::types::PyBytes::new_bound(py, &ipc))
    }
    #[cfg(not(feature = "arrow"))]
    {
        // Fallback: return JSON bytes
        Ok(pyo3::types::PyBytes::new_bound(py, json_str.as_bytes()))
    }
}"""

content = re.sub(r'pub fn arrow_encode_memories[^}]+}[^}]+}[^}]+}[^}]+}[^}]+}', replacement, content)

with open('whitemagic-rust/src/arrow_bridge.rs', 'w') as f:
    f.write(content)

print("Patched arrow_bridge.rs")
