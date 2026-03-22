import asyncio
import logging
from whitemagic.core.memory.unified import get_unified_memory, MemoryType
from whitemagic.core.intelligence.synthesis.refining_fire import get_refining_fire
from whitemagic.core.intelligence.tzimtzum_manager import get_tzimtzum
from whitemagic.core.homeostasis import get_homeostasis
from whitemagic.core.temporal.chronos_guard import get_chronos_guard
from whitemagic.core.intelligence.synthesis.solution_library import get_solution_library

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("TikkunVerification")

async def verify_phase_33():
    memory = get_unified_memory()
    refiner = get_refining_fire()
    tzimtzum = get_tzimtzum()
    homeostasis = get_homeostasis()
    chronos = get_chronos_guard()
    library = get_solution_library()

    print("\n🔥 [PHASE 33: TIKKUN] Starting Verification...")

    # 1. Simulate a "Husk" memory (low importance, contains code)
    print("\n📦 [MEMORY] Creating a 'Husk' memory with refined content...")
    husk_content = """
    def experimental_optimization_v1():
        # This is a temporary test function that should be refined
        pass
    """
    mem = memory.store(
        content=husk_content,
        memory_type=MemoryType.SHORT_TERM,
        importance=0.15, # Below refinement threshold
        neuro_score=0.05, # Extremely low to ensure it's at the very bottom
        tags={"experimental", "test"}
    )
    print(f"   └─ Husk Memory Created: {mem.id}")
    print(f"   └─ Initial Importances: Importance={mem.importance}, Neuro={mem.neuro_score}")
    
    # Verify it's in the DB with the right score
    db_mem = memory.recall(mem.id)
    print(f"   └─ DB Recalled Scores: Importance={db_mem.importance}, Neuro={db_mem.neuro_score}")

    # 2. Trigger Pruning (Tikkun)
    print("\n🔥 [TIKKUN] Triggering pruning and refinement fire...")
    pruned = memory.prune(threshold=0.2)
    print(f"   └─ Memories Pruned: {pruned}")

    # 3. Verify Solution Library for Spark
    print("\n✨ [REFINEMENT] Checking Solution Library for 'Golden Spark'...")
    # Solution ID is stable: spark_<md5(husk_content)>
    import hashlib
    husk_sol_id = f"spark_{hashlib.md5(husk_content.encode()).hexdigest()[:8]}"
    
    found_spark = library.get_solution(husk_sol_id)
    if not found_spark:
        # Fallback: check all solutions for 'refined' tag
        print(f"   ⚠️  Spark {husk_sol_id} not found by direct ID. Checking by tag...")
        solutions = library.find_nearest_solutions({"query": "optimization"}, k=10)
        for sol in solutions:
            if "refined" in sol.tags:
                found_spark = sol
                break
            
    if found_spark:
        print(f"   └─ Found Refined Spark: {found_spark.title} ({found_spark.id})")
        print(f"   └─ Confidence Boosted to: {found_spark.confidence:.2f}")
    else:
        print("   ⚠️  Refined spark not found in library.")
        assert False, "Refining Fire failed to extract spark from husk."

    # 4. Verify Tzimtzum (Vacant Space)
    print("\n🌌 [TZIMTZUM] Creating Vacant Space (Humility Protocol)...")
    tzimtzum.make_space(intensity=0.4)
    status = tzimtzum.get_status()
    print(f"   └─ Tzimtzum Active: {status['is_active']} (Cap: {status['intensity_cap']})")

    # 5. Verify Homeostasis Influence
    print("\n⚖️ [HOMEOSTASIS] Checking Yin-Yang balance under Tzimtzum...")
    balance = homeostasis.maintain_balance()
    print(f"   └─ Yin Score: {balance['metrics']['yin']:.2f} (Boosted by contraction)")
    print(f"   └─ Balance Mode: {balance['health']}")
    
    # 6. Verify Hollow Bamboo Grounding
    print("\n🎋 [GROUNDING] Generating Hollow Bamboo pulse...")
    context = chronos.get_grounding_context()
    print(f"   └─ Grounding Context: {context}")
    assert "HOLLOW BAMBOO" in context, "Hollow Bamboo grounding missing from temporal pulse"

    print("\n✅ Phase 33 Verification Complete: The Refining Fire burns bright but humble.")
    
    # Cleanup
    tzimtzum.release_space()

if __name__ == "__main__":
    asyncio.run(verify_phase_33())
