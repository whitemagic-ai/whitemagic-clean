"""
WM2 - Unified Evolution Framework
==================================
Consolidates 3 Evolution* variants
"""

from typing import Protocol


class Evolvable(Protocol):
    """Protocol for evolvable components."""

    def mutate(self) -> None:
        """Apply mutation."""
        ...

    def fitness(self) -> float:
        """Calculate fitness score."""
        ...
