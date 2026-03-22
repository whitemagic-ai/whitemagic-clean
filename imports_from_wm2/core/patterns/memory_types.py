"""
WM2 - Unified Memory Framework
===============================
Consolidates 4 Memory* variants
"""

from dataclasses import dataclass
from typing import Any, Dict, Optional


@dataclass
class Memory:
    """Universal memory representation."""
    id: str
    content: str
    memory_type: str
    importance: float = 0.5
    metadata: Dict[str, Any] = None
    
    def __post_init__(self):
        if self.metadata is None:
            self.metadata = {}
