"""Association Miner Bridge - Rust-accelerated Jaccard similarity.

Phase 2 VC2: Translate association_miner.py Jaccard to Rust.
"""
from __future__ import annotations

import re
from collections import defaultdict
from typing import Any

# Try to load Rust module
_rs = None
try:
    import whitemagic_rs as _rs
except Exception:
    pass

# Stop words
_STOP_WORDS = frozenset({
    "the", "a", "an", "is", "are", "was", "were", "be", "been", "being",
    "have", "has", "had", "do", "does", "did", "will", "would", "shall",
    "should", "may", "might", "can", "could", "must", "to", "of", "in",
    "for", "on", "with", "at", "by", "from", "as", "into", "through",
    "during", "before", "after", "above", "below", "between", "under",
    "again", "further", "then", "once", "here", "there", "when", "where",
    "why", "how", "all", "each", "every", "both", "few", "more", "most",
    "other", "some", "such", "no", "nor", "not", "only", "own", "same",
    "so", "than", "too", "very", "just", "because", "but", "and", "or",
    "if", "while", "about", "up", "out", "off", "over", "this", "that",
    "these", "those", "it", "its", "my", "your", "his", "her", "our",
    "their", "what", "which", "who", "whom", "me", "him", "them", "we",
    "you", "they", "i", "he", "she", "us", "self", "none", "also", "any",
})

_WORD_RE = re.compile(r"[a-z_][a-z0-9_]{2,}")


def extract_keywords(text: str, limit: int = 50) -> set[str]:
    """Extract keywords from text with Rust acceleration."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'extract_keywords'):
        try:
            result = _rs.extract_keywords(text, limit)
            return set(result)
        except Exception:
            pass
    
    # Python fallback
    text_lower = text.lower()
    words = _WORD_RE.findall(text_lower)
    keywords = {w for w in words if w not in _STOP_WORDS}
    
    # Frequency count for ranking
    freq: dict[str, int] = defaultdict(int)
    for w in words:
        if w in keywords:
            freq[w] += 1
    
    # Return top by frequency
    top = sorted(freq.items(), key=lambda x: x[1], reverse=True)[:limit]
    return {w for w, _ in top}


def jaccard_similarity(set_a: set[str], set_b: set[str]) -> float:
    """Compute Jaccard similarity |A ∩ B| / |A ∪ B| with Rust acceleration."""
    if not set_a and not set_b:
        return 1.0
    if not set_a or not set_b:
        return 0.0
    
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'jaccard_similarity'):
        try:
            return float(_rs.jaccard_similarity(list(set_a), list(set_b)))
        except Exception:
            pass
    
    # Python fallback
    intersection = len(set_a & set_b)
    union = len(set_a | set_b)
    return intersection / union if union > 0 else 0.0


def batch_jaccard(
    query_set: set[str],
    candidate_sets: list[set[str]]
) -> list[float]:
    """Compute Jaccard similarities in batch with Rust parallelization."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'batch_jaccard'):
        try:
            query_list = list(query_set)
            candidates_list = [list(s) for s in candidate_sets]
            return list(_rs.batch_jaccard(query_list, candidates_list))
        except Exception:
            pass
    
    # Python fallback
    return [jaccard_similarity(query_set, s) for s in candidate_sets]


def title_similarity(title_a: str, title_b: str) -> float:
    """Compute title similarity with substring matching."""
    if not title_a or not title_b:
        return 0.0
    
    a_lower = title_a.lower()
    b_lower = title_b.lower()
    
    # Exact match
    if a_lower == b_lower:
        return 1.0
    
    # Substring match
    if a_lower in b_lower or b_lower in a_lower:
        return 0.8
    
    # Keyword overlap
    keywords_a = extract_keywords(title_a, 10)
    keywords_b = extract_keywords(title_b, 10)
    
    return jaccard_similarity(keywords_a, keywords_b)


class AssociationMinerBridge:
    """Rust-accelerated association mining operations."""
    
    def __init__(self) -> None:
        self._rust_available = _rs is not None
        self._keyword_cache: dict[str, set[str]] = {}
    
    def mine_proposals(
        self,
        memories: list[dict[str, Any]],
        similarity_threshold: float = 0.3,
        max_proposals: int = 100
    ) -> list[dict[str, Any]]:
        """Mine association proposals with Rust acceleration."""
        proposals = []
        
        # Pre-compute keywords for all memories
        memory_keywords = []
        for m in memories:
            content = str(m.get('content', ''))
            title = str(m.get('title', ''))
            cache_key = f"{title}:{content[:200]}"
            
            if cache_key in self._keyword_cache:
                keywords = self._keyword_cache[cache_key]
            else:
                keywords = extract_keywords(content) | extract_keywords(title)
                self._keyword_cache[cache_key] = keywords
            
            memory_keywords.append(keywords)
        
        # Find similar pairs
        n = len(memories)
        for i in range(n):
            for j in range(i + 1, n):
                sim = jaccard_similarity(memory_keywords[i], memory_keywords[j])
                
                if sim >= similarity_threshold:
                    proposal = {
                        "source_id": memories[i].get('id'),
                        "target_id": memories[j].get('id'),
                        "strength": round(sim, 3),
                        "shared_keywords": list(memory_keywords[i] & memory_keywords[j])[:10],
                    }
                    proposals.append(proposal)
                    
                    if len(proposals) >= max_proposals:
                        break
            
            if len(proposals) >= max_proposals:
                break
        
        # Sort by strength
        proposals.sort(key=lambda x: x["strength"], reverse=True)
        return proposals[:max_proposals]
    
    def batch_mine(
        self,
        memory_batches: list[list[dict[str, Any]]],
        similarity_threshold: float = 0.3
    ) -> list[list[dict[str, Any]]]:
        """Mine associations for multiple batches in parallel."""
        from concurrent.futures import ThreadPoolExecutor
        
        def mine_batch(batch: list[dict[str, Any]]) -> list[dict[str, Any]]:
            return self.mine_proposals(batch, similarity_threshold)
        
        with ThreadPoolExecutor(max_workers=min(len(memory_batches), 4)) as executor:
            return list(executor.map(mine_batch, memory_batches))
    
    def get_backend(self) -> str:
        """Report which backend is active."""
        return "rust" if self._rust_available else "python"


def get_association_miner_bridge() -> AssociationMinerBridge:
    """Get association miner bridge instance."""
    return AssociationMinerBridge()
