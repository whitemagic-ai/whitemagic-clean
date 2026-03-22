"""
WM2 Core - Unified Lifecycle Management
========================================
Consolidates initialization, loading, saving patterns
"""

from abc import ABC, abstractmethod
from pathlib import Path


class Lifecycle(ABC):
    """Universal lifecycle management."""

    @abstractmethod
    def _load(self) -> None:
        """Load state from storage."""
        pass

    @abstractmethod
    def _save(self) -> None:
        """Save state to storage."""
        pass

    def reload(self) -> None:
        """Reload from storage."""
        self._load()

    def persist(self) -> None:
        """Persist to storage."""
        self._save()


class FileBackedLifecycle(Lifecycle):
    """Lifecycle with file-based persistence."""

    def __init__(self, path: Path):
        self.path = path

    def _load(self) -> None:
        if self.path.exists():
            import json
            with open(self.path) as f:
                data = json.load(f)
                self._restore_from_dict(data)

    def _save(self) -> None:
        import json
        self.path.parent.mkdir(parents=True, exist_ok=True)
        with open(self.path, 'w') as f:
            json.dump(self._to_dict(), f, indent=2)

    @abstractmethod
    def _restore_from_dict(self, data: dict) -> None:
        pass

    @abstractmethod
    def _to_dict(self) -> dict:
        pass
