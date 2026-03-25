import asyncio
from whitemagic.core.governance.zodiac_council import get_council, VoteSpectrum
from whitemagic.gardens.sangha.chat import get_chat
from whitemagic.gardens.sangha.collective_memory import get_collective

async def verify_democratic_autonomy():
    print("☸️ Starting Phase 31: Democratic Autonomy Verification\n")

    council = get_council()
    chat = get_chat()
    coll = get_collective()

    # 1. Setup Resonance (Utility)
    print("🧬 [RESONANCE] Priming agent utility scores...")
    # Simulate agent1 as a high-utility contributor
    coll.record_gratitude("agent_alpha", 5.0) 
    # Simulate agent2 as a new or less active contributor
    coll.record_gratitude("agent_beta", 0.5)
    
    context = coll.get_shared_context("verif_p31")
    print(f"   ├─ Alpha Gratitude: {context.resonance_index.get('agent_alpha')}")
    print(f"   └─ Beta Gratitude:  {context.resonance_index.get('agent_beta')}")

    # 2. Create Proposal
    print("\n📜 [PROPOSAL] Creating a Council proposal...")
    prop_id = chat.propose_to_council(
        sender_id="agent_alpha",
        title="Collective Refactoring of Core Memory",
        description="Shift system focus to optimize holographic memory subdivisions via WingsGana."
    )
    print(f"   ├─ Proposal ID: {prop_id}")
    print("   └─ Channel: #council")

    # 3. Simulate Multi-Dimensional Voting
    print("\n🗳️ [VOTING] Casting multidimensional SpectraVotes...")
    
    # Agent Alpha: Analytical, Macro, Future-looking, High Importance
    alpha_vote = VoteSpectrum(logic=0.9, micro=0.2, time=0.8, importance=0.9)
    council.cast_vote(prop_id, "agent_alpha", alpha_vote)
    print(f"   ├─ Alpha Vote (Analytical/Future): Logic={alpha_vote.logic}, Time={alpha_vote.time}")

    # Agent Beta: Intuitive, Micro, Present-looking, Low Importance
    beta_vote = VoteSpectrum(logic=0.3, micro=0.8, time=0.4, importance=0.3)
    council.cast_vote(prop_id, "agent_beta", beta_vote)
    print(f"   └─ Beta Vote (Intuitive/Present): Logic={beta_vote.logic}, Time={beta_vote.time}")

    # 4. Calculate Weighted Consensus
    print("\n⚖️ [CONSENSUS] Calculating Resonance-Weighted Center of Mass...")
    consensus = council.calculate_consensus(prop_id)
    
    print(f"   ├─ Center of Mass (Logic): {consensus['logic']:.4f}")
    print(f"   ├─ Center of Mass (Time):  {consensus['time']:.4f}")
    print(f"   ├─ Total Resonance Weight: {consensus['total_weight']:.2f}")
    
    # Validation: Logic should be closer to Alpha's 0.9 because they have higher resonance weight
    # Weight Alpha (1+5=6) vs Weight Beta (1+0.5=1.5). Total Weight = 7.5
    # Weighted Logic = (0.9*6 + 0.3*1.5)/7.5 = (5.4 + 0.45)/7.5 = 5.85/7.5 = 0.78
    expected_logic = 0.78
    print(f"   └─ Logic Delta: {abs(consensus['logic'] - expected_logic):.6f}")
    
    assert abs(consensus['logic'] - expected_logic) < 0.01, "Resonance weighting failed"

    print("\n✅ Phase 31 Verification Complete: The Council is Harmonious.")

if __name__ == "__main__":
    asyncio.run(verify_democratic_autonomy())
