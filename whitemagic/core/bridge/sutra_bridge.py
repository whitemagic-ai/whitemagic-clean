import logging

logger = logging.getLogger(__name__)

# Try to load Rust Sutra Kernel
try:
    import whitemagic_rust
    if hasattr(whitemagic_rust, 'sutra_kernel'):
        _RustDharmaEngine = whitemagic_rust.sutra_kernel.DharmaEngine
        RUST_SUTRA_AVAILABLE = True
    else:
        _RustDharmaEngine = None
        RUST_SUTRA_AVAILABLE = False
except ImportError:
    _RustDharmaEngine = None
    RUST_SUTRA_AVAILABLE = False

class SutraKernelBridge:
    """Bridge to the Rust-backed Sutra/Dharma kernel."""
    def __init__(self, maturity_level: int = 1, strict_mode: bool = True):
        self._rust_engine = _RustDharmaEngine(maturity_level, strict_mode) if _RustDharmaEngine else None

    def evaluate_action(self, action_type: str, intent_score: float = 1.0, karma_debt: float = 0.0) -> str:
        """Evaluates an action using the Rust Dharma Kernel or Python fallback."""
        if self._rust_engine:
            return self._rust_engine.evaluate_action(action_type, intent_score, karma_debt)

        # v20 Hardened Fallback: Use Dharma System instead of passive string
        try:
            from whitemagic.dharma import evaluate_ethics
            score, concerns = evaluate_ethics({"tool": action_type, "description": "Sutra Fallback Evaluation"})

            if score < 0.4:
                return "Panic: Ethical misalignment detected in fallback mode."
            if score < 0.7:
                return "Intervene: Cautionary threshold reached."
            return "Observe" if score > 0.9 else " Rajasic: Proceed with logging"
        except Exception:
            # Absolute last resort: Fail-Safe (Restrictive)
            return "Intervene: Safety system failure."

_sutra_kernel_instance = None

def get_sutra_kernel() -> SutraKernelBridge:
    global _sutra_kernel_instance
    if _sutra_kernel_instance is None:
        _sutra_kernel_instance = SutraKernelBridge()
    return _sutra_kernel_instance
