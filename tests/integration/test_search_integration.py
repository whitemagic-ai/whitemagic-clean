"""Integration tests for PSR-002 Search"""

import pytest
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent / ".venv" / "lib" / "python3.12" / "site-packages"))

try:
    import whitemagic_rs
    RUST_AVAILABLE = True
except ImportError:
    RUST_AVAILABLE = False
    pytest.skip("Rust bindings not available", allow_module_level=True)

class TestVectorSearch:
    """Test vector search"""
    
    def test_add_and_search(self):
        """Test adding vectors and searching"""
        vs = whitemagic_rs.VectorSearch()
        
        # Add vectors
        vs.add_vector("vec1", [1.0, 2.0, 3.0])
        vs.add_vector("vec2", [1.1, 2.1, 3.1])
        vs.add_vector("vec3", [5.0, 6.0, 7.0])
        
        # Search
        results = vs.search([1.0, 2.0, 3.0], 2)
        
        assert len(results) == 2
        assert results[0][0] == "vec1"  # Closest match
    
    def test_cosine_similarity(self):
        """Test cosine similarity calculation"""
        vs = whitemagic_rs.VectorSearch()
        
        # Identical vectors should have similarity 1.0
        sim = vs.cosine_similarity([1.0, 2.0, 3.0], [1.0, 2.0, 3.0])
        assert abs(sim - 1.0) < 0.01

class TestHybridRecall:
    """Test hybrid recall"""
    
    def test_hybrid_search(self):
        """Test hybrid search combining methods"""
        recall = whitemagic_rs.HybridRecall()
        
        results = recall.search("test query", use_fts=True, use_vector=True, limit=5)
        
        assert isinstance(results, list)
        assert len(results) <= 5
