import asyncio
import logging
import sys
from pathlib import Path

# Ensure project root is in path
sys.path.insert(0, str(Path(__file__).resolve().parent.parent))

from whitemagic.core.intelligence.bicameral import get_bicameral_reasoner
from whitemagic.core.memory.embeddings import get_embedding_engine
from whitemagic.core.memory.unified import get_unified_memory

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("bicameral_merge")

async def run_semantic_merge(similarity_threshold: float = 0.85):
    """
    Perform a semantic-aware merge of redundant memories using the Bicameral Reasoner.
    """
    um = get_unified_memory()
    engine = get_embedding_engine()
    reasoner = get_bicameral_reasoner()

    if not engine.available():
        logger.error("Embedding engine unavailable. Aborting.")
        return

    logger.info(f"Starting semantic merge with threshold {similarity_threshold}...")

    # 1. Find similar pairs
    pairs = engine.find_similar_pairs(min_similarity=similarity_threshold, max_pairs=100)
    if not pairs:
        logger.info("No similar pairs found above threshold.")
        return

    logger.info(f"Found {len(pairs)} candidate pairs for semantic review.")

    merged_count = 0
    for m1_id, m2_id, similarity in pairs:
        m1 = um.backend.recall(m1_id)
        m2 = um.backend.recall(m2_id)

        if not m1 or not m2:
            continue

        # 2. Use Bicameral Reasoner to decide if they are truly redundant
        query = f"Compare these two memories and decide if they should be merged. \nMemory A: {m1.title}\nContent A: {str(m1.content)[:500]}\n\nMemory B: {m2.title}\nContent B: {str(m2.content)[:500]}"

        try:
            # Note: Bicameral Reasoner uses thought clones, might be slow but high quality
            result = await reasoner.reason(query)

            # Simple heuristic: if synthesis contains "merge" and confidence is high
            if "merge" in result.synthesis.lower() and result.final_confidence > 0.7:
                logger.info(f"Bicameral verdict: MERGE {m1_id} and {m2_id} (conf={result.final_confidence:.2f})")

                # Perform the merge (using logic similar to consolidation.py)
                # Determine canonical
                score_a = (m1.importance or 0.5) * 10 + (m1.access_count or 0)
                score_b = (m2.importance or 0.5) * 10 + (m2.access_count or 0)
                canonical, duplicate = (m1, m2) if score_a >= score_b else (m2, m1)

                # Merge tags
                canonical.tags = list(set(canonical.tags or []) | set(duplicate.tags or []))
                canonical.importance = min(1.0, (canonical.importance or 0.5) + 0.05)
                if not hasattr(canonical, "metadata") or canonical.metadata is None:
                    canonical.metadata = {}
                canonical.metadata["bicameral_merge"] = {
                    "merged_id": duplicate.id,
                    "confidence": result.final_confidence,
                    "verdict": result.synthesis[:500]
                }

                um.backend.store(canonical)
                # Archive to edge
                um.backend.archive_to_edge(duplicate.id, galactic_distance=0.98)
                merged_count += 1
            else:
                logger.info(f"Bicameral verdict: KEEP SEPARATE {m1_id} and {m2_id}")
        except Exception as e:
            logger.error(f"Error reviewing pair {m1_id}/{m2_id}: {e}")

    logger.info(f"Semantic merge complete. {merged_count} pairs merged.")

if __name__ == "__main__":
    asyncio.run(run_semantic_merge())
