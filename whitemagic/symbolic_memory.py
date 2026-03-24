"""Symbolic memory compatibility shim"""

from typing import Any, Dict, List, Optional

class ConceptMap:
    """Maps concepts and their relationships"""
    
    def __init__(self) -> None:
        self.concepts: Dict[str, Dict[str, Any]] = {}
        self.relationships: List[Dict[str, str]] = []
    
    def add_concept(self, name: str, properties: Optional[Dict[str, Any]] = None) -> None:
        """Add a concept to the map"""
        self.concepts[name] = properties or {}
    
    def add_relationship(self, source: str, target: str, relation_type: str) -> None:
        """Add a relationship between concepts"""
        self.relationships.append({
            "source": source,
            "target": target,
            "type": relation_type
        })
    
    def get_related(self, concept: str) -> List[str]:
        """Get concepts related to the given concept"""
        related = []
        for rel in self.relationships:
            if rel["source"] == concept:
                related.append(rel["target"])
            elif rel["target"] == concept:
                related.append(rel["source"])
        return related
    
    def to_dict(self) -> Dict[str, Any]:
        """Convert to dictionary"""
        return {
            "concepts": self.concepts,
            "relationships": self.relationships
        }

# Mock MemoryManager for symbolic memory tests
class MemoryManager:
    """Symbolic memory manager mock"""
    
    def __init__(self) -> None:
        self.memories: List[Dict[str, Any]] = []
    
    def add_memory(self, content: str, tags: Optional[List[str]] = None) -> Dict[str, Any]:
        """Add a memory"""
        memory = {
            "id": len(self.memories),
            "content": content,
            "tags": tags or [],
            "symbolic": True
        }
        self.memories.append(memory)
        return memory
    
    def get_symbolic_memories(self) -> List[Dict[str, Any]]:
        """Get all symbolic memories"""
        return [m for m in self.memories if m.get("symbolic", False)]

# Re-export
__all__ = ['ConceptMap', 'MemoryManager']
