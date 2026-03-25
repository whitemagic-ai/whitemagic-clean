"""
Deep Dive Mission - Systematic audit of the 276,501 memories in the Data Sea.
Integrates ShadowCloneArmy, MemoryNetworkExplorer, and WisdomCouncil.
"""

import asyncio
import logging
import json
from datetime import datetime
from pathlib import Path

from whitemagic.intelligence.agentic.clone_army import get_clone_army
from whitemagic.intelligence.agentic.network_explorer import get_network_explorer
from whitemagic.intelligence.agentic.wisdom_council import get_wisdom_council

logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(levelname)s - %(message)s")
logger = logging.getLogger(__name__)

async def run_mission():
    logger.info("🚀 Starting 276K Data Sea Deep Dive Mission...")
    
    army = get_clone_army()
    explorer = get_network_explorer()
    council = get_wisdom_council()
    
    report = {
        "mission_start": datetime.now().isoformat(),
        "total_memories": 276501,
        "sectors": {}
    }

    # SECTOR 1: Core Directives & Truth
    logger.info("🔍 Sector 1: Searching for Core Directives...")
    findings_directives = await army.deploy_search("Core Directives Dharma Truth", army_size=100)
    report["sectors"]["core_directives"] = [
        {"id": c.memory_id, "score": c.consensus_score, "title": c.memory_details.title if c.memory_details else "Unknown"}
        for c in findings_directives[:5]
    ]

    # SECTOR 2: Lost Prototypes & Legacy
    logger.info("🔍 Sector 2: Searching for Lost Prototypes...")
    findings_prototypes = await army.deploy_search("Legacy Pipeline Lost Prototype Bridge", army_size=100)
    report["sectors"]["lost_prototypes"] = [
        {"id": c.memory_id, "score": c.consensus_score, "title": c.memory_details.title if c.memory_details else "Unknown"}
        for c in findings_prototypes[:5]
    ]

    # SECTOR 3: High Density Knowledge Clusters
    logger.info("🔍 Sector 3: Mapping High Density Clusters...")
    clusters = await explorer.get_high_density_clusters(limit=5)
    report["sectors"]["density_clusters"] = clusters

    # SECTOR 4: Wisdom Synthesis
    logger.info("⚖️ Sector 4: Consulting the Wisdom Council...")
    decision = await council.deliberate(
        topic="Data Sea Satiation and Autonomous readiness",
        findings=list(report["sectors"].values())
    )
    report["wisdom_decision"] = {
        "consensus": decision.consensus,
        "rationale": decision.rationale,
        "urgency": decision.urgency
    }

    report["mission_end"] = datetime.now().isoformat()
    
    # Save Report
    report_path = Path("deep_dive_report.json")
    with open(report_path, "w") as f:
        json.dump(report, f, indent=4)
        
    logger.info(f"✅ Deep Dive Mission Complete. Report saved to {report_path}")
    print(f"\n✨ MISSION RESULT: {decision.consensus}")

if __name__ == "__main__":
    asyncio.run(run_mission())
