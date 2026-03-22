#!/usr/bin/env python3
"""
Verify Holocron Integration
===========================
Checks if the Holocron (Golden Rules) is correctly integrated into:
1. Thought Galaxy (recall_best_strategies)
2. Context Optimizer (pack_full_context)
"""

import sys
import logging
from pathlib import Path

# Add project root to path
PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

# Setup logging
logging.basicConfig(level=logging.INFO, format='%(levelname)s: %(message)s')
logger = logging.getLogger(__name__)

def verify_thought_galaxy():
    logger.info("--- Verifying Thought Galaxy Integration ---")
    try:
        from whitemagic.core.memory.thought_galaxy import ThoughtGalaxy
        
        db_path = Path.home() / ".whitemagic/memory/thought_galaxy.db"
        galaxy = ThoughtGalaxy(str(db_path))
        
        # Query for something that should trigger a Golden Rule match
        # (Based on the rules we saw in the cat output, e.g., "Pattern: Patterns Patterns.Py Pattern")
        # Let's try a generic query that matches one of the rules
        query_task = "python patterns" 
        
        episodes = galaxy.recall_best_strategies(task_type=query_task, limit=5)
        
        found_gold = False
        for ep in episodes:
            if ep.strategy == "Golden Rule":
                logger.info(f"✅ Found Golden Rule: {ep.thought_trace}")
                found_gold = True
                
        if not found_gold:
            logger.warning("❌ No Golden Rules found in Thought Galaxy recall.")
            # This might happen if the simple keyword matcher in Holocron doesn't find overlap.
            # Let's list what we got
            for ep in episodes:
                logger.info(f"  - {ep.strategy}: {ep.context_summary[:50]}...")
                
    except Exception as e:
        logger.error(f"❌ Thought Galaxy check failed: {e}")

def verify_context_optimizer():
    logger.info("\n--- Verifying Context Optimizer Integration ---")
    try:
        from whitemagic.ai.context_optimizer import get_context_optimizer
        
        opt = get_context_optimizer()
        query = "python patterns"
        
        # Test pack_full_context
        packed = opt.pack_full_context(query=query, token_budget=1000, wisdom_limit=3)
        
        found_wisdom = False
        for item in packed.items:
            if item.source == "holocron":
                logger.info(f"✅ Found Wisdom in Context: {item.content.splitlines()[0]}")
                found_wisdom = True
                
        if not found_wisdom:
            logger.warning("❌ No Wisdom found in packed context.")
            
    except Exception as e:
        logger.error(f"❌ Context Optimizer check failed: {e}")

if __name__ == "__main__":
    verify_thought_galaxy()
    verify_context_optimizer()
