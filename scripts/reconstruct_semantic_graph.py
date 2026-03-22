#!/usr/bin/env python3
"""
Semantic Graph Reconstruction
==============================
Phase 2 of v17: Build 50K semantic edges from embeddings.

Approach:
1. Load all embedded memories
2. Compute cosine similarity matrix (efficiently)
3. Generate typed edges based on thresholds:
   - SIMILAR_TO (cosine > 0.90)
   - RELATED_TO (cosine > 0.85)
   - CONTEXTUAL_MATCH (cosine > 0.80)
4. Bulk insert edges with association types

Usage:
    python3 scripts/reconstruct_semantic_graph.py --dry-run
    python3 scripts/reconstruct_semantic_graph.py --commit
"""
import argparse
import logging
import sqlite3
import sys
from pathlib import Path
from typing import Any

import numpy as np
from numpy.linalg import norm

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

logging.basicConfig(level=logging.INFO, format='%(asctime)s | %(message)s')
logger = logging.getLogger(__name__)

DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"

# Similarity thresholds for edge types
EDGE_THRESHOLDS = {
    'SIMILAR_TO': 0.90,      # Very similar
    'RELATED_TO': 0.85,       # Related content
    'CONTEXTUAL_MATCH': 0.80, # Contextually relevant
}

MAX_EDGES_PER_MEMORY = 10  # Limit to prevent dense connections


def cosine_similarity(a: np.ndarray, b: np.ndarray) -> float:
    """Compute cosine similarity between two vectors"""
    return float(np.dot(a, b) / (norm(a) * norm(b)))


def load_embeddings(db_path: Path) -> dict[str, tuple[str, np.ndarray]]:
    """Load all embeddings from DB"""
    logger.info("Loading embeddings from database...")

    conn = sqlite3.connect(str(db_path))
    conn.row_factory = sqlite3.Row

    rows = conn.execute("""
        SELECT m.id, m.title, e.embedding
        FROM memories m
        JOIN memory_embeddings e ON m.id = e.memory_id
        WHERE m.memory_type != 'quarantined'
    """).fetchall()

    embeddings = {}
    for row in rows:
        mem_id = row['id']
        title = row['title'] or 'Untitled'
        # Parse embedding blob
        embedding_bytes = row['embedding']
        if embedding_bytes:
            # Assuming float32, 384-dim
            vec = np.frombuffer(embedding_bytes, dtype=np.float32)
            embeddings[mem_id] = (title, vec)

    conn.close()
    logger.info(f"Loaded {len(embeddings)} embeddings")
    return embeddings


def compute_similarity_pairs(embeddings: dict) -> list[tuple[str, str, float]]:
    """
    Compute pairwise similarities efficiently.
    Returns list of (id1, id2, similarity) above threshold.
    """
    logger.info("Computing similarity matrix...")

    ids = list(embeddings.keys())
    vectors = [embeddings[mid][1] for mid in ids]

    # Convert to matrix for vectorized computation
    matrix = np.stack(vectors)

    # Normalize for cosine similarity
    norms = norm(matrix, axis=1, keepdims=True)
    normalized = matrix / norms

    # Compute full similarity matrix
    similarity_matrix = np.dot(normalized, normalized.T)

    # Find pairs above minimum threshold
    min_threshold = min(EDGE_THRESHOLDS.values())
    pairs = []

    for i in range(len(ids)):
        for j in range(i + 1, len(ids)):
            sim = similarity_matrix[i, j]
            if sim >= min_threshold:
                pairs.append((ids[i], ids[j], float(sim)))

    logger.info(f"Found {len(pairs)} pairs above threshold {min_threshold}")
    return pairs


def classify_edge(similarity: float) -> str | None:
    """Classify edge type based on similarity score"""
    for edge_type, threshold in sorted(EDGE_THRESHOLDS.items(), key=lambda x: -x[1]):
        if similarity >= threshold:
            return edge_type
    return None


def select_top_edges(pairs: list, max_per_memory: int = MAX_EDGES_PER_MEMORY) -> list:
    """Select top N edges per memory to prevent over-connection"""
    logger.info(f"Selecting top {max_per_memory} edges per memory...")

    # Group by source memory
    by_source = {}
    for id1, id2, sim in pairs:
        if id1 not in by_source:
            by_source[id1] = []
        if id2 not in by_source:
            by_source[id2] = []

        by_source[id1].append((id2, sim))
        by_source[id2].append((id1, sim))  # Undirected

    # Select top N for each
    selected = []
    for mem_id, connections in by_source.items():
        # Sort by similarity descending
        connections.sort(key=lambda x: -x[1])

        for target_id, sim in connections[:max_per_memory]:
            # Avoid duplicates (only add if mem_id < target_id to ensure uniqueness)
            if mem_id < target_id:
                edge_type = classify_edge(sim)
                if edge_type:
                    selected.append((mem_id, target_id, edge_type, sim))

    logger.info(f"Selected {len(selected)} edges (max {max_per_memory} per memory)")
    return selected


def generate_edges(dry_run: bool = True, commit: bool = False) -> dict[str, Any]:
    """Main pipeline for semantic edge generation"""

    # Step 1: Load embeddings
    embeddings = load_embeddings(DB_PATH)
    if len(embeddings) < 2:
        logger.error("Not enough embeddings to compute similarities")
        return {'error': 'insufficient_embeddings'}

    # Step 2: Compute similarities
    pairs = compute_similarity_pairs(embeddings)

    # Step 3: Select top edges
    edges = select_top_edges(pairs)

    # Step 4: Categorize
    by_type = {}
    for id1, id2, edge_type, sim in edges:
        if edge_type not in by_type:
            by_type[edge_type] = []
        by_type[edge_type].append((id1, id2, sim))

    # Report
    logger.info("\nEdge distribution:")
    for edge_type, edges_list in by_type.items():
        logger.info(f"  {edge_type}: {len(edges_list)}")

    # Step 5: Insert if committing
    if commit and not dry_run:
        logger.info("\nCommitting edges to database...")
        conn = sqlite3.connect(str(DB_PATH))

        inserted = 0
        for id1, id2, edge_type, sim in edges:
            try:
                conn.execute("""
                    INSERT OR IGNORE INTO associations 
                    (source_id, target_id, relation_type, strength, created_at)
                    VALUES (?, ?, ?, ?, datetime('now'))
                """, (id1, id2, edge_type, sim))
                inserted += 1
            except Exception as e:
                logger.warning(f"Failed to insert edge {id1}->{id2}: {e}")

        conn.commit()
        conn.close()
        logger.info(f"Inserted {inserted} edges")
    else:
        logger.info("\nDRY RUN - No changes made (use --commit to apply)")

    return {
        'total_embeddings': len(embeddings),
        'pairs_considered': len(pairs),
        'edges_selected': len(edges),
        'by_type': {k: len(v) for k, v in by_type.items()},
        'dry_run': dry_run,
        'committed': commit and not dry_run
    }


def main():
    parser = argparse.ArgumentParser(description='Semantic Graph Reconstruction')
    parser.add_argument('--dry-run', action='store_true', default=True,
                        help='Preview without making changes')
    parser.add_argument('--commit', action='store_true',
                        help='Actually insert edges into database')

    args = parser.parse_args()

    # Dry run by default unless explicitly committing
    dry_run = not args.commit

    logger.info("=" * 70)
    logger.info("Semantic Graph Reconstruction — v17 Phase 2")
    logger.info("=" * 70)

    results = generate_edges(dry_run=dry_run, commit=args.commit)

    logger.info("\n" + "=" * 70)
    logger.info("Results Summary")
    logger.info("=" * 70)
    logger.info(f"Embeddings processed: {results['total_embeddings']}")
    logger.info(f"Pairs above threshold: {results['pairs_considered']}")
    logger.info(f"Edges selected: {results['edges_selected']}")

    if results.get('by_type'):
        logger.info("\nEdges by type:")
        for edge_type, count in results['by_type'].items():
            logger.info(f"  {edge_type}: {count}")

    if results.get('committed'):
        logger.info("\n✅ Edges committed to database")
    else:
        logger.info("\n🚧 Dry run complete — use --commit to apply changes")

    return 0


if __name__ == '__main__':
    sys.exit(main())
