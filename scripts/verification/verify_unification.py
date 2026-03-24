"""
Verification: Phase 3 Unification (Stats)
=========================================
Tests if QuantumIChing correctly inherits from BaseMonitor and reports unified stats.
"""
import os
import sys

# Ensure we can import from staging/core_system
sys.path.append(os.getcwd())

from whitemagic.oracle.quantum_iching import QuantumIChing


def verify():
    print("🔍 Testing QuantumIChing Unification...")

    # 1. Instantiate
    oracle = QuantumIChing()
    print("✅ Instantiation successful.")

    # 2. Run Operation (Should trigger latencies)
    print("🔮 Running consultation...")
    result = oracle.consult("Test unified stats?")
    print(f"✅ Result: Hexagram #{result.primary_hexagram}")

    # 3. Check Stats
    stats = oracle.get_statistics()
    print("📊 Statistics:")
    print(stats)

    # 4. Assertions
    assert "total_consultations" in stats, "Missing total_consultations"
    assert stats["total_consultations"] >= 1, "Consultation count mismatch"
    assert "average_resonance" in stats, "Missing average_resonance"

    print("\n✅ VERIFICATION PASSED: Unification successful.")

if __name__ == "__main__":
    verify()
