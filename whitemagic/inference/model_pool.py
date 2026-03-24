"""Compatibility helpers for inference model safety checks."""

from __future__ import annotations

from whitemagic.edge.local_llm import is_url_safe


def is_ollama_url_safe(url: str) -> bool:
    """Check whether an Ollama endpoint URL is safe to use."""
    return is_url_safe(url)


__all__ = ["is_ollama_url_safe"]
