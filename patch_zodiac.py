
with open('whitemagic-rust/src/sutra_kernel/zodiac_ledger.rs') as f:
    content = f.read()

# Add PyO3 imports and macros
content = "use pyo3::prelude::*;\n" + content
content = content.replace("pub struct LedgerEntry", "#[pyclass]\npub struct LedgerEntry")
content = content.replace("pub struct ZodiacLedger", "#[pyclass]\npub struct ZodiacLedger")

# Add #[pymethods] to impl
content = content.replace("impl ZodiacLedger {", "#[pymethods]\nimpl ZodiacLedger {")

# Add #[new] to constructor
content = content.replace("pub fn new() -> Self", "#[new]\n    pub fn new() -> Self")

with open('whitemagic-rust/src/sutra_kernel/zodiac_ledger.rs', 'w') as f:
    f.write(content)

print("Patched zodiac_ledger.rs")
