"""
Yin Reflection Demonstration - Self-Prompting AI logic.
"""

import asyncio
import logging
from whitemagic.autonomous.yin_controller import get_yin_controller

logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(levelname)s - %(message)s")
logger = logging.getLogger(__name__)

async def demonstrate_yin_phase():
    logger.info("🎬 [YIN DEMO] Starting autonomous reflection cycle...")
    
    yin = get_yin_controller()
    
    # Trigger Protocol 27 (Stillness)
    directive = await yin.enter_stillness(duration_seconds=3)
    
    print("\n" + "="*60)
    print("🌙 SELF-PROMPTED DIRECTIVE GENERATED")
    print("="*60)
    print(f"Origin: {directive['origin']}")
    print(f"Consensus: {directive['consensus']}")
    print("\nRationale:")
    print(directive['rationale'])
    print("\nTop Suggested Actions:")
    for action in directive['suggested_actions']:
        print(f"  • {action}")
    print("="*60 + "\n")

    logger.info("✨ [YIN DEMO] Reflection complete. The system has spoken to itself.")

if __name__ == "__main__":
    asyncio.run(demonstrate_yin_phase())
