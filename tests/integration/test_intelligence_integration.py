"""Integration tests for PSR-004 Intelligence"""

import sys
from pathlib import Path

import pytest

# Add project root to path
sys.path.insert(0, str(Path(__file__).parents[2]))

try:
    import whitemagic_rs
    RUST_AVAILABLE = True
except ImportError:
    RUST_AVAILABLE = False
    pytest.skip("Rust bindings not available", allow_module_level=True)

class TestReasoningEngine:
    """Test reasoning engine"""

    def test_basic_inference(self):
        """Test basic inference"""
        engine = whitemagic_rs.ReasoningEngine(threshold=0.7)

        premises = ["A", "B"]
        rules = [
            (["A", "B"], "C", 0.9)
        ]

        results = engine.infer(premises, rules)

        assert "C" in results

    def test_confidence_threshold(self):
        """Test confidence threshold"""
        engine = whitemagic_rs.ReasoningEngine(threshold=0.95)

        premises = ["A"]
        rules = [
            (["A"], "B", 0.8)  # Below threshold
        ]

        results = engine.infer(premises, rules)

        assert "B" not in results

class TestEmergenceDetector:
    """Test emergence detection"""

    def test_detect_patterns(self):
        """Test pattern detection"""
        detector = whitemagic_rs.EmergenceDetector(threshold=0.7)

        patterns = ["pattern1", "pattern2", "pattern1"]

        results = detector.detect(patterns)

        assert len(results) > 0
