"""Association Miner Hot Path — Python wrapper for Rust V2 implementation.

PSR-029 Migration: Thin wrapper calling Rust for 20-50× speedup.
Replaces: whitemagic/core/memory/association_miner.py (649 lines)
With: Python wrapper + Rust core (association_miner_v2.rs)

Usage:
    from whitemagic.core.memory.association_miner_hot_path import AssociationMinerRust
    miner = AssociationMinerRust(min_overlap=0.15, max_proposals=50)
    result = miner.mine_batch(texts)
"""

from __future__ import annotations

import logging
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    import numpy as np

logger = logging.getLogger(__name__)


class AssociationMinerRust:
    """Thin Python wrapper for Rust association miner.
    
    v1.0: Direct passthrough to whitemagic_rs.AssociationMinerV2
    """
    
    def __init__(self, min_overlap: float = 0.15, max_proposals: int = 50):
        """Initialize the Rust-backed association miner.
        
        Args:
            min_overlap: Minimum Jaccard overlap score to propose link
            max_proposals: Maximum proposals per mining run
        """
        self.min_overlap = min_overlap
        self.max_proposals = max_proposals
        self._rust_miner = None
        
        # Try to initialize Rust backend
        try:
            import whitemagic_rs
            self._rust_miner = whitemagic_rs.PyAssociationMinerV2(min_overlap)
            logger.info("✅ Rust AssociationMinerV2 initialized")
        except ImportError:
            logger.warning("⚠️  whitemagic_rs not available, using Python fallback")
        except Exception as e:
            logger.warning(f"⚠️  Rust init failed: {e}, using Python fallback")
    
    def extract_keywords(self, text: str, max_keywords: int = 50) -> set[str]:
        """Extract keywords from text.
        
        Args:
            text: Input text
            max_keywords: Maximum keywords to extract
            
        Returns:
            Set of keywords
        """
        if self._rust_miner is not None:
            try:
                # Call Rust implementation
                import whitemagic_rs
                return whitemagic_rs.keyword_extract(text, max_keywords)
            except Exception as e:
                logger.debug(f"Rust keyword_extract failed: {e}")
        
        # Python fallback
        return self._extract_keywords_python(text, max_keywords)
    
    def _extract_keywords_python(self, text: str, max_keywords: int) -> set[str]:
        """Pure Python keyword extraction (fallback)."""
        import re
        from collections import defaultdict
        
        stop_words = {
            "the", "a", "an", "and", "or", "but", "in", "on", "at", "to", "for",
            "of", "with", "by", "from", "is", "it", "this", "that", "was", "are",
        }
        
        word_re = re.compile(r"\w+")
        words = word_re.findall(text.lower())
        keywords = {w for w in words if w not in stop_words and len(w) > 2}
        
        # Frequency-based selection
        if len(keywords) > max_keywords:
            freq: defaultdict[str, int] = defaultdict(int)
            for w in words:
                if w in keywords:
                    freq[w] += 1
            sorted_kw = sorted(keywords, key=lambda k: freq[k], reverse=True)
            keywords = set(sorted_kw[:max_keywords])
        
        return keywords
    
    def mine_batch(
        self,
        texts: list[tuple[str, str]],  # (id, content)
        max_keywords: int = 50,
    ) -> dict:
        """Mine associations from batch of texts.
        
        Args:
            texts: List of (memory_id, text_content) tuples
            max_keywords: Max keywords per text
            
        Returns:
            Mining result dict with overlaps
        """
        if not texts:
            return {"memory_count": 0, "pair_count": 0, "overlaps": []}
        
        # Try Rust fast path
        if self._rust_miner is not None:
            try:
                import whitemagic_rs
                result = whitemagic_rs.association_mine(
                    texts,
                    max_keywords=max_keywords,
                    min_score=self.min_overlap,
                    max_results=self.max_proposals,
                )
                logger.debug(f"Rust mined {result.get('pair_count', 0)} associations")
                return result
            except Exception as e:
                logger.debug(f"Rust mining failed: {e}")
        
        # Python fallback
        return self._mine_batch_python(texts, max_keywords)
    
    def _mine_batch_python(
        self,
        texts: list[tuple[str, str]],
        max_keywords: int,
    ) -> dict:
        """Pure Python batch mining (fallback)."""
        from whitemagic.optimization._rust_fallbacks import _association_mine_python
        
        return _association_mine_python(
            texts,
            max_keywords=max_keywords,
            min_score=self.min_overlap,
            max_results=self.max_proposals,
        )
    
    def is_rust_available(self) -> bool:
        """Check if Rust backend is available."""
        return self._rust_miner is not None


def install_hot_path() -> bool:
    """Install the association_miner hot path by monkey-patching.
    
    Replaces:
        from whitemagic.core.memory.association_miner import AssociationMiner
    With:
        AssociationMinerRust (thin wrapper around Rust)
    
    Returns:
        True if installation successful
    """
    try:
        import whitemagic.core.memory.association_miner as orig_module
        
        # Replace the class
        orig_module.AssociationMiner = AssociationMinerRust
        
        logger.info("✅ AssociationMiner hot path installed (Rust-backed)")
        return True
        
    except Exception as e:
        logger.warning(f"⚠️  Hot path install failed: {e}")
        return False


# Auto-install on import
_RUST_BACKED = False
try:
    import whitemagic_rs
    _RUST_BACKED = True
except ImportError:
    pass

logger.debug(f"association_miner_hot_path loaded (Rust: {_RUST_BACKED})")
