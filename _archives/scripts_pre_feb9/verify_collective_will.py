import asyncio
import logging
from whitemagic.core.governance.zodiac_council import get_council, VoteSpectrum
from whitemagic.core.intelligence.synthesis.accelerator_bridge import get_accelerator_bridge
from whitemagic.gardens.sangha.collective_memory import get_collective

# Configure logging to see the bridge output
logging.basicConfig(level=logging.INFO, format="%(levelname)s - %(message)s")

async def verify_collective_will():
    print("🤝 Starting Phase 31: Collective Will Verification\n")

    council = get_council()
    coll = get_collective()
    bridge = get_accelerator_bridge()

    # 1. Setup high-resonance agent
    print("🧬 [PREP] Establishing resonant authority...")
    coll.record_gratitude("system_architect", 10.0)
    
    # 2. Create high-importance proposal
    print("\n📜 [PROPOSAL] Creating critical system upgrade proposal...")
    prop_id = council.create_proposal(
        "Autonomous Protocol Hardening", 
        "Scale the system's defensive logic to counter external entropy.",
        "system_architect"
    )

    # 3. Cast a high-impact, analytical vote
    print("🗳️ [VOTING] Casting high-importance analytical vote...")
    architect_vote = VoteSpectrum(logic=0.9, micro=0.5, time=0.8, importance=0.95)
    council.cast_vote(prop_id, "system_architect", architect_vote)

    # 4. Calculate Consensus and Dispatch to Bridge
    print("\n⚖️ [CONSENSUS] Calculating weighted center of mass...")
    consensus = council.calculate_consensus(prop_id)
    
    print(f"   ├─ Logic: {consensus['logic']:.2f}")
    print(f"   └─ Importance: {consensus['importance']:.2f}")

    # 5. Execute via AcceleratorBridge
    print("\n⚡ [EXECUTION] Dispatching Council decision to AcceleratorBridge...")
    success = bridge.execute_council_decision(consensus)
    
    if success:
        print("\n✅ Success: Collective will translated into system action.")
    else:
        print("\n❌ Failure: Collective will failed to trigger action.")
        
    assert success, "Council decision failed to trigger bridge action"

if __name__ == "__main__":
    asyncio.run(verify_collective_will())
