"""
Massive Deep Search Mission - The Eternal Return
Orchestrates a large-scale probe into the Data Sea using Shadow Clone Army and Heaven's Net.
Keywords: Yin/Yang, Ganying, Resonance Cascades, Gardens, Lunar Mansions, Ganas, 
          Zodiacal Round, Progression, Ralph Wiggum, Ralph Loops.
"""

import asyncio
import logging
from whitemagic.intelligence.agentic.clone_army import get_clone_army
from whitemagic.intelligence.agentic.network_explorer import get_network_explorer
from whitemagic.core.resonance.gan_ying import emit_event, EventType

logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(levelname)s - %(message)s")
logger = logging.getLogger(__name__)

KEYWORDS = [
    "Yin and Yang", "Ganying", "Resonance Cascades", "Gardens", 
    "Lunar Mansions", "Ganas", "Zodiacal Round", "Progression", 
    "Ralph Wiggum", "Ralph loops"
]

async def run_massive_search():
    logger.info("📡 Initiating Massive Deep Search Mission...")
    
    army = get_clone_army()
    explorer = get_network_explorer()
    
    emit_event(
        source="deep_search_mission",
        event_type=EventType.SYSTEM_STARTED,
        data={"keywords": KEYWORDS, "army_size": 1000}
    )

    # 1. Parallel Keyword Search (Shadow Clone Army)
    logger.info(f"⚔️ Deploying Shadow Clone Army (size 1000) for {len(KEYWORDS)} keywords...")
    
    search_tasks = [army.deploy_search(query, army_size=100) for query in KEYWORDS]
    results = await asyncio.gather(*search_tasks)
    
    all_findings = []
    for i, res in enumerate(results):
        if res:
            logger.info(f"✅ Found {len(res)} high-resonance memories for '{KEYWORDS[i]}'")
            all_findings.extend(res)
            
    # 2. Network Exploration (Map the Cascades)
    logger.info("🌌 Mapping the Resonance Cascades across the searched memories...")
    mem_ids = [f.memory_id for f in all_findings]
    
    # Build a cluster map from the most relevant seed
    if mem_ids:
        seed_id = mem_ids[0]
        graph = await explorer.build_cluster_map(seed_id, max_depth=2, max_nodes=100)
        logger.info(f"🕸️ Resonance Graph built: {len(graph.nodes)} nodes, {len(graph.links)} links.")
        
        # 3. Cluster Identification
        logger.info(f"🧩 Identified {len(graph.clusters)} knowledge clusters related to core philosophy.")
        for i, cluster_ids in enumerate(graph.clusters[:5]):
            logger.info(f"   - Cluster {i+1}: {len(cluster_ids)} memories")
    else:
        logger.warning("No memories found to build resonance graph.")

    # 4. Final Synthesis
    from whitemagic.intelligence.agentic.wisdom_council import get_wisdom_council
    council = get_wisdom_council()
    
    logger.info("⚖️ Consulting the Wisdom Council for Cross-Concept Synthesis...")
    decision = await council.deliberate(
        topic="Interconnectivity of Core System Concepts",
        findings=all_findings,
        urgency="high"
    )
    
    print("\n" + "="*80)
    print("📜 THE ETERNAL RETURN - MASSIVE SEARCH REPORT")
    print("="*80)
    print(f"Consensus: {decision.consensus}")
    print("\nRationale:")
    print(decision.rationale)
    print("\nNext Steps:")
    for p in decision.perspectives:
        print(f"  • [{p.role.value.upper()}] Recommendation: {p.recommendation}")
    print("="*80 + "\n")

    emit_event(
        source="deep_search_mission",
        event_type=EventType.SYSTEM_STOPPED,
        data={"status": "complete", "nodes_mapped": len(graph.nodes)}
    )

if __name__ == "__main__":
    asyncio.run(run_massive_search())
