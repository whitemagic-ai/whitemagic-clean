"""
Step 4: Hybrid Fusion Deployment
Wires together BM25 + Vector + Graph for optimal retrieval
"""

import logging
from typing import Dict, List, Any, Optional

logger = logging.getLogger(__name__)

# Global state
_HYBRID_FUSION_ACTIVE = False
_FUSION_CONFIG = {
    "vector_weight": 0.4,
    "bm25_weight": 0.3,
    "graph_weight": 0.3,
    "rrf_k": 60,
    "constellation_boost": 0.3,
}

def deploy_hybrid_fusion() -> bool:
    """
    Deploy hybrid fusion system (Step 4)
    
    This wires together:
    1. BM25 lexical search (via Rust)
    2. Vector semantic search (embeddings)
    3. Graph PageRank/association scoring
    
    Uses Reciprocal Rank Fusion (RRF) to combine signals.
    """
    global _HYBRID_FUSION_ACTIVE
    
    try:
        # Verify all components are available
        components = _verify_fusion_components()
        
        if not all(components.values()):
            missing = [k for k, v in components.items() if not v]
            logger.warning(f"Hybrid fusion: Missing components: {missing}")
            return False
        
        # Configure query-type specific weights
        _configure_query_weights()
        
        _HYBRID_FUSION_ACTIVE = True
        logger.info("🔄 Hybrid Fusion deployed: BM25 + Vector + Graph")
        logger.info(f"   Config: {_FUSION_CONFIG}")
        
        return True
        
    except Exception as e:
        logger.error(f"Failed to deploy hybrid fusion: {e}")
        return False


def _verify_fusion_components() -> Dict[str, bool]:
    """Check that all fusion components are available."""
    components = {
        "bm25": False,
        "vector": False,
        "graph": False,
        "rrf": False,
    }
    
    # Check BM25 (Rust)
    try:
        from whitemagic.optimization.rust_accelerators import rust_search_available
        components["bm25"] = rust_search_available()
    except Exception:
        pass
    
    # Check Vector (Embeddings)
    try:
        from whitemagic.core.memory.embeddings import get_embedding_engine
        engine = get_embedding_engine()
        components["vector"] = engine.available()
    except Exception:
        pass
    
    # Check Graph
    try:
        from whitemagic.core.memory.graph_engine import get_graph_engine
        engine = get_graph_engine()
        components["graph"] = engine.available
    except Exception:
        pass
    
    # Check RRF (Rust or Python fallback)
    try:
        import whitemagic_rs
        components["rrf"] = hasattr(whitemagic_rs, "rrf_fuse")
    except Exception:
        components["rrf"] = True  # Python fallback available
    
    return components


def _configure_query_weights():
    """Configure query-type specific weight adaptations."""
    global _FUSION_CONFIG
    
    # Store weight configurations for different query types
    _FUSION_CONFIG["query_weights"] = {
        "single_hop": {"vector": 0.4, "bm25": 0.5, "graph": 0.1},
        "multi_hop": {"vector": 0.3, "bm25": 0.3, "graph": 0.4},
        "temporal": {"vector": 0.6, "bm25": 0.3, "graph": 0.1},
        "open_domain": {"vector": 0.5, "bm25": 0.3, "graph": 0.2},
        "adversarial": {"vector": 0.4, "bm25": 0.4, "graph": 0.2},
    }


def get_fusion_weights(query_type: str = "open_domain") -> Dict[str, float]:
    """Get fusion weights for a specific query type."""
    global _FUSION_CONFIG
    return _FUSION_CONFIG.get("query_weights", {}).get(
        query_type,
        {"vector": 0.4, "bm25": 0.3, "graph": 0.3}
    )


def hybrid_search_with_fusion(
    query: str,
    query_type: str = "open_domain",
    limit: int = 10,
    include_cold: bool = False,
) -> List[Dict[str, Any]]:
    """
    Perform hybrid search with full fusion pipeline.
    
    Steps:
    1. Get BM25 results (lexical)
    2. Get vector results (semantic)
    3. Get graph results (associations)
    4. Fuse with RRF using query-type specific weights
    5. Apply constellation boost
    6. Return ranked results
    """
    global _HYBRID_FUSION_ACTIVE
    
    if not _HYBRID_FUSION_ACTIVE:
        logger.warning("Hybrid fusion not active, using fallback")
        return _fallback_search(query, limit)
    
    try:
        from whitemagic.core.memory.unified import get_unified_memory
        from whitemagic.core.memory.hybrid_fusion import HybridFusion
        
        um = get_unified_memory()
        
        # Get weights for this query type
        weights = get_fusion_weights(query_type)
        
        # Use unified hybrid search (already does BM25 + Vector + Constellation boost)
        lexical_semantic_results = um.search_hybrid(
            query=query,
            limit=limit * 2,  # Get more for fusion
            semantic_weight=weights["vector"],
            lexical_weight=weights["bm25"],
            include_cold=include_cold,
        )
        
        # Get graph results via hybrid_recall (multi-hop)
        graph_results = um.hybrid_recall(
            query=query,
            hops=2,
            anchor_limit=5,
            final_limit=limit * 2,
        )
        
        # Use HybridFusion for final ranking
        fusion = HybridFusion(
            vector_weight=weights["vector"],
            bm25_weight=weights["bm25"],
            graph_weight=weights["graph"],
        )
        
        # Convert to fusion format
        vector_formatted = [
            {"id": m.id, "title": m.title, "content": str(m.content)[:200]}
            for m in lexical_semantic_results
        ]
        
        bm25_formatted = vector_formatted  # Already fused in search_hybrid
        
        graph_formatted = [
            {"id": r["memory_id"], "title": r["title"], "content": r["content"][:200]}
            for r in graph_results
        ]
        
        # Final fusion
        fused = fusion.fuse_rrf(
            vector_results=vector_formatted,
            bm25_results=bm25_formatted,
            graph_results=graph_formatted,
            top_k=limit,
        )
        
        # Convert back to dict format
        results = []
        for candidate in fused:
            results.append({
                "memory_id": candidate.memory_id,
                "title": candidate.title,
                "content": candidate.content,
                "score": candidate.final_score,
                "vector_score": candidate.vector_score,
                "bm25_score": candidate.bm25_score,
                "graph_score": candidate.graph_score,
                "query_type": query_type,
            })
        
        logger.info(f"🔍 Hybrid fusion: '{query[:30]}' → {len(results)} results (type={query_type})")
        return results
        
    except Exception as e:
        logger.error(f"Hybrid fusion search failed: {e}")
        return _fallback_search(query, limit)


def _fallback_search(query: str, limit: int) -> List[Dict[str, Any]]:
    """Fallback to basic search if fusion fails."""
    try:
        from whitemagic.core.memory.unified import get_unified_memory
        um = get_unified_memory()
        results = um.search(query=query, limit=limit)
        return [
            {
                "memory_id": m.id,
                "title": m.title,
                "content": str(m.content)[:200],
                "score": 0.5,
                "source": "fallback",
            }
            for m in results
        ]
    except Exception:
        return []


def is_fusion_active() -> bool:
    """Check if hybrid fusion is active."""
    return _HYBRID_FUSION_ACTIVE


# Deploy on import
deploy_hybrid_fusion()
