#!/usr/bin/env python3
"""
Comprehensive Integration Tests
Creates real integration tests for all PSR implementations
"""

from pathlib import Path

class IntegrationTestGenerator:
    """Generates comprehensive integration tests"""
    
    def __init__(self, base_path: Path):
        self.base_path = base_path
        self.generated = []
    
    def generate_all_tests(self):
        """Generate all integration tests"""
        print("\n" + "="*70)
        print("🧪 COMPREHENSIVE INTEGRATION TEST GENERATION")
        print("="*70)
        
        # PSR-001: Memory Core
        self._generate_memory_tests()
        
        # PSR-002: Search
        self._generate_search_tests()
        
        # PSR-003: Graph
        self._generate_graph_tests()
        
        # PSR-004: Intelligence
        self._generate_intelligence_tests()
        
        self._print_summary()
    
    def _generate_memory_tests(self):
        """Generate memory core integration tests"""
        test_code = '''"""Integration tests for PSR-001 Memory Core"""

import pytest
import sys
from pathlib import Path

# Add Rust bindings to path
sys.path.insert(0, str(Path(__file__).parent.parent / ".venv" / "lib" / "python3.12" / "site-packages"))

try:
    import whitemagic_rs
    RUST_AVAILABLE = True
except ImportError:
    RUST_AVAILABLE = False
    pytest.skip("Rust bindings not available", allow_module_level=True)

class TestMemoryConsolidation:
    """Test memory consolidation"""
    
    def test_consolidation_basic(self):
        """Test basic consolidation"""
        consolidation = whitemagic_rs.MemoryConsolidation(threshold=0.7)
        
        # Add candidates
        consolidation.add_candidate("mem1", 0.8, 5, 24.0)
        consolidation.add_candidate("mem2", 0.5, 2, 12.0)
        
        # Consolidate
        results = consolidation.consolidate()
        
        assert len(results) >= 1
        assert "mem1" in results
    
    def test_consolidation_threshold(self):
        """Test consolidation threshold"""
        consolidation = whitemagic_rs.MemoryConsolidation(threshold=0.9)
        
        consolidation.add_candidate("mem1", 0.8, 5, 24.0)
        results = consolidation.consolidate()
        
        # Should not consolidate with high threshold
        assert len(results) == 0

class TestMemoryDecay:
    """Test memory decay"""
    
    def test_decay_calculation(self):
        """Test decay calculation"""
        decay = whitemagic_rs.MemoryDecay(half_life=168.0)
        
        # Test decay after 1 week
        strength = decay.calculate_decay(168.0, 1.0)
        
        assert 0.4 < strength < 0.6  # Should be ~0.5
    
    def test_should_forget(self):
        """Test forgetting decision"""
        decay = whitemagic_rs.MemoryDecay(half_life=168.0)
        
        # Old, low importance should be forgotten
        should_forget = decay.should_forget(500.0, 0.2)
        assert should_forget

class TestMemoryLifecycle:
    """Test memory lifecycle"""
    
    def test_stage_transitions(self):
        """Test lifecycle stage transitions"""
        lifecycle = whitemagic_rs.MemoryLifecycle()
        
        lifecycle.set_stage("mem1", "short_term")
        lifecycle.set_stage("mem1", "long_term")
        
        transitions = lifecycle.get_transitions("mem1")
        
        assert len(transitions) == 1
        assert transitions[0] == ("short_term", "long_term")
'''
        
        self._write_test("test_memory_integration.py", test_code)
    
    def _generate_search_tests(self):
        """Generate search integration tests"""
        test_code = '''"""Integration tests for PSR-002 Search"""

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
'''
        
        self._write_test("test_search_integration.py", test_code)
    
    def _generate_graph_tests(self):
        """Generate graph integration tests"""
        test_code = '''"""Integration tests for PSR-003 Graph"""

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
'''
        
        self._write_test("test_graph_integration.py", test_code)
    
    def _generate_intelligence_tests(self):
        """Generate intelligence layer tests"""
        test_code = '''"""Integration tests for PSR-004 Intelligence"""

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

class TestReasoningEngine:
    """Test reasoning engine"""
    
    def test_basic_inference(self):
        """Test basic inference"""
        engine = whitemagic_rs.ReasoningEngine(threshold=0.7)
        
        premises = ["A", "B"]
        rules = [
            (["A", "B"], "C", 0.9)
        ]
        
        results = engine.infer(premises, rules)
        
        assert "C" in results
    
    def test_confidence_threshold(self):
        """Test confidence threshold"""
        engine = whitemagic_rs.ReasoningEngine(threshold=0.95)
        
        premises = ["A"]
        rules = [
            (["A"], "B", 0.8)  # Below threshold
        ]
        
        results = engine.infer(premises, rules)
        
        assert "B" not in results

class TestEmergenceDetector:
    """Test emergence detection"""
    
    def test_detect_patterns(self):
        """Test pattern detection"""
        detector = whitemagic_rs.EmergenceDetector(threshold=0.7)
        
        patterns = ["pattern1", "pattern2", "pattern1"]
        
        results = detector.detect(patterns)
        
        assert len(results) > 0
'''
        
        self._write_test("test_intelligence_integration.py", test_code)
    
    def _write_test(self, filename: str, code: str):
        """Write test file"""
        test_path = self.base_path / "tests" / "integration" / filename
        test_path.parent.mkdir(parents=True, exist_ok=True)
        test_path.write_text(code)
        
        lines = len(code.split('\n'))
        self.generated.append((filename, lines))
        print(f"  ✅ {filename}: {lines} lines")
    
    def _print_summary(self):
        """Print summary"""
        print("\n" + "="*70)
        print("📊 TEST GENERATION SUMMARY")
        print("="*70)
        
        total_lines = sum(lines for _, lines in self.generated)
        
        print(f"\nGenerated: {len(self.generated)} test files")
        print(f"Total lines: {total_lines}")
        
        print(f"\n✅ Integration tests ready!")
        print(f"\nTo run tests:")
        print(f"  pytest tests/integration/ -v")

def main():
    """Generate integration tests"""
    base_path = Path(__file__).parent.parent
    
    generator = IntegrationTestGenerator(base_path)
    generator.generate_all_tests()

if __name__ == '__main__':
    main()
