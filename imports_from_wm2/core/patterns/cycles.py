"""
WM2 - Unified Cycle Framework
==============================
Consolidates 5 Cycle* variants
"""

from enum import Enum
from typing import Protocol


class CyclePhase(Enum):
    """Universal cycle phase enumeration."""
    INIT = "init"
    ACTIVE = "active"
    TRANSITION = "transition"
    COMPLETE = "complete"


class Cycle(Protocol):
    """Base protocol for all cycles."""

    def advance(self) -> None:
        """Advance to next phase."""
        ...

    def get_phase(self) -> CyclePhase:
        """Get current phase."""
        ...

    def reset(self) -> None:
        """Reset to initial phase."""
        ...
