"""Semantic search for WhiteMagic memories."""

try:
    from .semantic import SearchMode, SearchResult, SemanticSearcher
except ImportError:
    SearchMode = None  # type: ignore[assignment,misc]
    SearchResult = None  # type: ignore[assignment,misc]
    SemanticSearcher = None  # type: ignore[assignment,misc]

__all__ = ["SearchMode", "SearchResult", "SemanticSearcher"]
