import asyncio
import logging
from whitemagic.core.governance.zodiac_council import get_council, VoteSpectrum
from whitemagic.core.homeostasis import get_homeostasis
from whitemagic.core.temporal.chronos_guard import get_chronos_guard
from whitemagic.gardens.sangha.collective_memory import get_collective

# Configure logging
logging.basicConfig(level=logging.INFO, format="%(levelname)s - %(message)s")

async def verify_harmonic_gravity():
    print("🌌 Starting Phase 32: Harmonic Gravity Verification\n")

    council = get_council()
    homeo = get_homeostasis()
    chronos = get_chronos_guard()
    coll = get_collective()

    # 1. Setup high-resonance agent and importance
    print("🧬 [PREP] Initializing collective resonance...")
    coll.record_gratitude("visionary_agent", 15.0)
    
    # 2. Create an "Analytical" proposal (Yin Bias)
    print("\n📜 [PROPOSAL] Creating 'Strict Memory Optimization' proposal...")
    prop_id = council.create_proposal(
        "Strict Memory Optimization",
        "Converge all loose data patterns into the Solution Library for maximum coherence.",
        "visionary_agent"
    )

    # 3. Cast high-importance analytical vote
    # Logic=0.9 (Analytical), Importance=0.95
    print("🗳️ [VOTING] Casting high-importance analytical vote (Logic=0.9)...")
    vote = VoteSpectrum(logic=0.9, micro=0.8, time=0.5, importance=0.95)
    council.cast_vote(prop_id, "visionary_agent", vote)

    # 4. Verify Homeostasis Bias
    print("\n⚖️ [HOMEOSTASIS] Checking for Harmonic Bias...")
    result = homeo.maintain_balance()
    
    bias = result.get("harmonic_bias")
    if bias:
        print(f"   ├─ Detected Bias Mode: {bias['mode']}")
        print(f"   ├─ Bias Intensity: {bias['intensity']:.2f}")
        print(f"   └─ Adjusted Yin: {result['metrics']['yin']:.4f}")
        
        # Validation: Mode should be analytical and Yin should be boosted
        assert bias['mode'] == "analytical", "Harmonic bias mode mismatch"
        assert result['metrics']['yin'] >= 0.9, "Yin bias intensity boost failed"
    else:
        print("   ❌ Error: Harmonic bias not detected in Homeostasis")
        assert False, "Harmonic bias missing"

    # 5. Verify Chronos Pulse Context
    print("\n⏳ [TEMPORAL] Verifying Council Intent in grounding pulse...")
    pulse = chronos.generate_pulse()
    print(f"   ├─ Pulse Council Intent: {pulse.council_intent}")
    context = chronos.get_grounding_context()
    
    print(f"   └─ Pulse Context: {context}")
    assert "ACTIVE COUNCIL INTENT: ANALYTICAL" in context, f"Council intent missing from grounding context. Found: {context}"

    print("\n✅ Phase 32 Verification Complete: The Swarm orbits its collective center.")

if __name__ == "__main__":
    asyncio.run(verify_harmonic_gravity())
