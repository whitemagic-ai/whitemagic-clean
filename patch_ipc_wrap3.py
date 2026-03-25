
with open('whitemagic-rust/src/ipc_bridge.rs', 'r') as f:
    content = f.read()

# Fix the PyO3 wrappers. In recent pyo3 versions, the module requires explicit imports for wrap_pyfunction
# The issue is that the python functions are missing #[pyfunction] or the wrap macro is incorrectly called
content = content.replace("pyo3::wrap_pyfunction!(ipc_init, m)", "wrap_pyfunction!(ipc_init, m)")
content = content.replace("pyo3::wrap_pyfunction!(ipc_publish, m)", "wrap_pyfunction!(ipc_publish, m)")
content = content.replace("pyo3::wrap_pyfunction!(ipc_status, m)", "wrap_pyfunction!(ipc_status, m)")

# We also need to add back the `use pyo3::prelude::*;` which was probably stripped or broken
if "use pyo3::prelude::*;" not in content:
    content = content.replace("#[cfg(feature = \"python\")]\nuse pyo3::wrap_pyfunction;", "#[cfg(feature = \"python\")]\nuse pyo3::prelude::*;")

with open('whitemagic-rust/src/ipc_bridge.rs', 'w') as f:
    f.write(content)

print("Patched ipc_bridge.rs")
