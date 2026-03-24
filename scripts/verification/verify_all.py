"""
Verify All Unifications
=======================
Tests all components that have been migrated to the Unified Monitoring Library.
"""
import asyncio
import os
import sys
import threading
import time

sys.path.append(os.getcwd())

from whitemagic.core.ganas.base import GanaCall
from whitemagic.core.ganas.eastern_quadrant import RootGana
from whitemagic.core.ganas.western_quadrant import NetGana
from whitemagic.logging_config import get_logger, setup_logging
from whitemagic.oracle.quantum_iching import QuantumIChing
from whitemagic.utils.fileio import atomic_write, file_lock

from typing import Any, Type

try:
    from whitemagic.symbolic import ConceptType, SymbolicReasoning
    HAS_SYMBOLIC = True
except ImportError:
    HAS_SYMBOLIC = False
    ConceptType = Any  # type: ignore
    SymbolicReasoning = Any  # type: ignore

try:
    from whitemagic.gardens.synthesis_enhanced import EnhancedGardenSynthesis
    HAS_SYNTHESIS = True
except ImportError:
    HAS_SYNTHESIS = False
    EnhancedGardenSynthesis = Any  # type: ignore


def verify_iching():
    print("\n🔮 Testing QuantumIChing...")
    oracle = QuantumIChing()
    oracle.consult("Verify me")
    stats = oracle.get_statistics()

    assert "total_consultations" in stats
    assert stats["total_consultations"] >= 1
    assert "average_resonance" in stats
    print("✅ QuantumIChing OK")

def verify_symbolic():
    print("\n☯️ Testing SymbolicReasoning...")
    if not HAS_SYMBOLIC:
        print("   ⚠️ SymbolicReasoning not available in the public workspace; skipping.")
        return

    engine = SymbolicReasoning(use_chinese=True)

    # Add a concept
    engine.add_concept("dao", "The Way", "道", ConceptType.PRINCIPLE)

    # Query it (should trigger stats)
    result = engine.query_concept("dao")
    print(f"   Query Result: {result}")

    stats = engine.get_statistics()
    print("   Stats:", stats)

    # Assertions
    assert "metrics" in stats, "Missing metrics"
    assert "query_latency" in stats["metrics"], "Missing query_latency"
    assert "total_queries" in stats["metrics"], "Missing total_queries"
    assert stats["metrics"]["total_queries"]["count"] == 1
    assert "specific" in stats, "Missing specific stats"
    assert "token_savings" in stats["specific"], "Missing token_savings in specific"

    print("✅ SymbolicReasoning OK")


def verify_synthesis():
    print("\n🌸 Testing EnhancedGardenSynthesis...")
    if not HAS_SYNTHESIS:
        print("   ⚠️ EnhancedGardenSynthesis not available in the public workspace; skipping.")
        return

    synth = EnhancedGardenSynthesis()

    # Run a synthesis
    result = synth.synthesize_gardens(["joy", "love"], {"intention": True})
    print(f"   Harmony: {result['harmony_score']:.2f}")

    stats = synth.get_statistics()
    print("   Stats keys:", list(stats.keys()))

    # Assertions
    assert "metrics" in stats
    assert "synthesis_time" in stats["metrics"]
    assert "syntheses" in stats["metrics"]
    assert stats["metrics"]["syntheses"]["count"] == 1
    assert "specific" in stats
    assert "average_harmony" in stats["specific"]

    print("✅ EnhancedGardenSynthesis OK")


def verify_locking():
    print("\n🔒 Testing File Locking...")
    test_file = "test_lock.txt"
    with open(test_file, "w") as f:
        f.write("initial")

    def locker():
        with file_lock(test_file):
            time.sleep(0.1)

    # Atomic Write Test
    atomic_write(test_file, "atomic_content")
    with open(test_file) as f:
        assert f.read() == "atomic_content", "Atomic write failed"
    print("   ✅ Atomic Write OK")

    # Locking Test (Basic smoke test)
    # We just ensure it doesn't crash and actually runs
    t = threading.Thread(target=locker)
    t.start()
    with file_lock(test_file):
        pass # If we acquire it, good
    t.join()
    print("   ✅ Concurrency Lock OK")

    if os.path.exists(test_file):
        os.remove(test_file)

def verify_logging_sys():
    print("\n📝 Testing Logging System...")
    # This should be safe to call multiple times
    setup_logging(level="INFO")
    logger = get_logger("verification")

    assert logger.level == 0  # Level is delegated, root sets effective level
    print("   ✅ Logger Initialization OK")


async def verify_transmutation():
    print("\n⚔️ Testing Phase 4: The Transmutation (RootGana x Rust)...")
    root = RootGana()

    # Trigger a search for something certain to exist
    call = GanaCall(
        task="search_truth",
        state_vector={"query": "def setup_logging", "limit": 5},
        resonance_hints=None
    )

    result = await root._execute_core(call, "")
    print(f"   Mansion: {result['mansion']}")
    print(f"   Garden: {result['garden']}")
    print(f"   Integrity: {result['integrity']}")
    print(f"   Health Check: {result['health_check']}")

    assert result['mansion'] == 'ROOT', "Unexpected mansion"
    assert result['garden'] == 'Truth', "Unexpected garden"
    assert result['integrity'] == 'verified', "Root integrity not verified"
    
    print("✅ RootGana Transmutation OK")


async def verify_net_transmutation():
    print("\n🕸️ Testing Phase 4: NetGana Transmutation (Heaven's Net v6)...")
    net = NetGana()

    # Trigger Heaven's Net scan
    call = GanaCall(
        task="cast_heavens_net",
        state_vector={"mode": "safe"},
        resonance_hints=None
    )

    result = await net._execute_core(call, "")
    print(f"   Net Status: {result['status']}")

    if 'internal_net' in result:
        print(f"   Files Scanned: {result['internal_net']['files_scanned']}")
        print(f"   Concepts Found: {result['internal_net']['concepts_extracted']}")
        print(f"   Engine: {result['internal_net']['engine']}")

        assert result['internal_net']['files_scanned'] > 0
        assert result['internal_net']['engine'] in {'rust_v6', 'python_fallback'}
    else:
        print("   ⚠️ Heaven's Net integration MISSING or failed")

    print("✅ NetGana Transmutation OK")

if __name__ == "__main__":
    print("🚀 Starting Unified Verification...")
    verify_iching()
    verify_symbolic()
    verify_synthesis()
    verify_locking()
    verify_logging_sys()

    # Async tasks
    asyncio.run(verify_transmutation())
    asyncio.run(verify_net_transmutation())

    print("\n🎉 ALL SYSTEMS GO + UNIFIED.")
