import re

with open('whitemagic-rust/src/sutra_kernel/mod.rs') as f:
    content = f.read()

replacement = """pub fn sutra_kernel(_py: Python<'_>, m: &Bound<'_, PyModule>) -> PyResult<()> {
    m.add_class::<ZodiacLedger>()?;
    Ok(())
}"""

content = re.sub(r'pub fn sutra_kernel[^}]+}', replacement, content)

with open('whitemagic-rust/src/sutra_kernel/mod.rs', 'w') as f:
    f.write(content)

print("Patched mod.rs")
