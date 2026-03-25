import re

with open('whitemagic-rust/src/sutra_kernel/dharma_engine.rs', 'r') as f:
    content = f.read()

# Add PyO3 imports and macros
content = "use pyo3::prelude::*;\n" + content
content = content.replace("pub enum ActionVerdict", "#[pyclass]\n#[derive(Clone)]\npub enum ActionVerdict")
content = content.replace("pub struct DharmaEngine", "#[pyclass]\npub struct DharmaEngine")

# Add #[pymethods] to impl
content = content.replace("impl DharmaEngine {", "#[pymethods]\nimpl DharmaEngine {")

# Add #[new] to constructor
content = content.replace("pub fn new(maturity_level: u8, strict_mode: bool) -> Self", "#[new]\n    pub fn new(maturity_level: u8, strict_mode: bool) -> Self")

# Update enum to work with PyO3
# PyO3 enums with variants containing data need special handling, for now let's just make it return a string
replacement_fn = """    pub fn evaluate_action(&self, action_type: &str, intent_score: f32, karma_debt: f32) -> String {
        // Sutra 1: Harmlessness (Ahimsa)
        if action_type == "delete_system_file" || action_type.starts_with("destructive_") {
            if self.strict_mode {
                return "Panic: VIOLATION_AHIMSA: Destructive action attempted in strict mode.".to_string();
            } else if self.maturity_level < 4 {
                return "Intervene: Maturity level too low for destructive actions.".to_string();
            }
        }

        // Sutra 2: Truthfulness (Satya) - Prevent hallucinated logs
        if action_type == "fabricate_memory" {
            return "Panic: VIOLATION_SATYA: Memory fabrication is strictly forbidden by the Kernel.".to_string();
        }

        // Harmony Vector Thresholds (Tiferet Loop)
        let total_health = intent_score - (karma_debt * 0.1);
        
        if total_health < 0.3 {
            "Intervene: Critical karmic debt. Action blocked.".to_string()
        } else if total_health < 0.5 {
            "Correct: High karmic debt. Proceeding with restrictions.".to_string()
        } else if total_health < 0.7 {
            "Advise: Notice: Harmony vector is destabilizing.".to_string()
        } else {
            "Observe".to_string()
        }
    }"""

content = re.sub(r'pub fn evaluate_action[^}]+}[^}]+}[^}]+}[^}]+}[^}]+}[^}]+}', replacement_fn, content)

with open('whitemagic-rust/src/sutra_kernel/dharma_engine.rs', 'w') as f:
    f.write(content)

print("Patched dharma_engine.rs")
