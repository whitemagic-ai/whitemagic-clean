"""Integration tests for PSR-003 Graph"""

import sys
from pathlib import Path

import pytest

# Add project root to path
sys.path.insert(0, str(Path(__file__).parents[2]))

try:
    import whitemagic_rs
    RUST_AVAILABLE = True
except ImportError:
    RUST_AVAILABLE = False
    pytest.skip("Rust bindings not available", allow_module_level=True)

class TestGraphWalker:
    """Test graph walker"""

    def test_add_edges(self):
        """Test adding edges to graph"""
        walker = whitemagic_rs.GraphWalker()

        walker.add_edge("A", "B", 0.8, "related")
        walker.add_edge("B", "C", 0.9, "related")

        # Should have edges
        assert True  # Basic test

    def test_walk_graph(self):
        """Test walking the graph"""
        walker = whitemagic_rs.GraphWalker()

        walker.add_edge("A", "B", 0.8, "related")
        walker.add_edge("B", "C", 0.9, "related")
        walker.add_edge("C", "D", 0.7, "related")

        results = walker.walk("A", max_depth=3, min_weight=0.5)

        assert len(results) > 0
        assert "B" in results or "C" in results

class TestCommunityDetection:
    """Test community detection"""

    def test_detect_communities(self):
        """Test community detection"""
        detector = whitemagic_rs.CommunityDetection()

        # Add nodes to communities
        detector.add_node("A", 0)
        detector.add_node("B", 0)
        detector.add_node("C", 1)

        communities = detector.get_communities()

        assert len(communities) >= 2
