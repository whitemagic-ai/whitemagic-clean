from pathlib import Path

file_path = Path("/home/lucas/Desktop/whitemagicdev/whitemagic-rust/src/arrow_bridge.rs")
content = file_path.read_text()

# Add ArrowIPC class to expose to Python
class_injection = """
#[cfg(feature = "pyo3")]
#[pyclass]
pub struct ArrowIPCBridge {
    ipc_file_path: String,
}

#[cfg(feature = "pyo3")]
#[pymethods]
impl ArrowIPCBridge {
    #[new]
    fn new(path: String) -> Self {
        ArrowIPCBridge { ipc_file_path: path }
    }

    /// Read an Arrow IPC file and return basic stats (demonstrating zero-copy read capability)
    fn read_ipc_stats(&self) -> PyResult<String> {
        #[cfg(feature = "arrow")]
        {
            use std::fs::File;
            use arrow::ipc::reader::FileReader;
            
            let file = File::open(&self.ipc_file_path).map_err(|e| pyo3::exceptions::PyIOError::new_err(e.to_string()))?;
            let mut reader = FileReader::try_new(file, None).map_err(|e| pyo3::exceptions::PyRuntimeError::new_err(e.to_string()))?;
            
            let mut total_records = 0;
            let mut batches = 0;
            
            while let Some(Ok(batch)) = reader.next() {
                total_records += batch.num_rows();
                batches += 1;
            }
            
            Ok(format!("Read {} records across {} batches from {}", total_records, batches, self.ipc_file_path))
        }
        #[cfg(not(feature = "arrow"))]
        {
            Err(pyo3::exceptions::PyRuntimeError::new_err("Arrow feature not enabled in build"))
        }
    }
}
"""

if "ArrowIPCBridge" not in content:
    content = content.replace("#[cfg(feature = \"pyo3\")]\npub fn arrow_bridge", class_injection + "\n#[cfg(feature = \"pyo3\")]\npub fn arrow_bridge")
    content = content.replace("// Add arrow bindings here later", "m.add_class::<ArrowIPCBridge>()?;")
    file_path.write_text(content)
    print("arrow_bridge.rs patched to include ArrowIPCBridge for Python.")
else:
    print("ArrowIPCBridge already present.")
