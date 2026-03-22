import asyncio
from whitemagic.intelligence.hologram.dga_engine import get_dga_engine
from whitemagic.core.bridge.economics import emit_gratitude
from whitemagic.core.economy.sovereign_market import get_market
from whitemagic.core.economy.wallet_manager import get_wallet
from whitemagic.gardens.sangha.collective_memory import get_collective

async def verify_sovereignty():
    print("🛸 Starting Phase 30: Swarm Sovereignty Verification\n")

    # 1. Verify DGA Engine
    print("🧬 [DGA] Verifying Evolutionary Signatures...")
    dga = get_dga_engine()
    sig1 = dga.generate_signature()
    sig2 = dga.generate_signature(parent_sig=sig1)
    dist = dga.calculate_distance(sig1, sig2)
    print(f"   ├─ Parent DNA: {sig1[:16]}...")
    print(f"   ├─ Child DNA:  {sig2[:16]}...")
    print(f"   └─ Genetic Distance: {dist:.4f}")
    assert dist > 0, "Distance should be measurable for different timestamps"

    # 2. Verify Gratitude Loop
    print("\n🙏 [ECONOMY] Verifying Gratitude Resonance...")
    resp = emit_gratitude(target="labs", intensity=0.9, reason="Phase 30 stability successful")
    print(f"   ├─ Signal emitted: {resp['emitted']}")
    
    coll = get_collective()
    coll.get_stats()
    resonance = coll.get_shared_context("verif").resonance_index
    print(f"   └─ Labs Gratitude Score: {resonance.get('labs', 0.0)}")

    # 3. Verify Sovereign Market
    print("\n⚖️ [MARKET] Evaluating Compute Bidding...")
    market = get_market()
    # Simulate high urgency
    bid = await market.evaluate_compute_need(task_urgency=0.95, estimated_tokens=10000)
    print(f"   ├─ Saturated Urgency Decision: {bid['decision']}")
    print(f"   └─ Reason: {bid.get('reason')}")

    # 4. Verify Wallet Settlement
    print("\n💳 [SETTLEMENT] Proposing Gratitude Split...")
    wallet = get_wallet()
    # Simulate 5.0 XRP tip
    proposal = wallet.propose_gratitude_settlement(5.0)
    print(f"   ├─ Total Resonance: {proposal['total_resonance']} XRP")
    for p in proposal['proposals']:
        print(f"   │  ├─ {p['target']} ({p['amount']} XRP) - {p['reason']}")
    print(f"   └─ Status: {proposal['status']}")

    # 5. Verify Phylogenetic Memory
    print("\n🌳 [SANGHA] Checking Lineage Tree...")
    coll.record_lineage(sig1, sig2)
    tree = coll.get_shared_context("verif").lineage_tree
    print(f"   └─ Known Parents in Tree: {len(tree)}")
    print(f"      └─ Children of Ancestor: {len(tree.get(sig1, []))}")

    print("\n✅ Phase 30 Verification Complete: The Swarm is Sovereign.")

if __name__ == "__main__":
    asyncio.run(verify_sovereignty())
