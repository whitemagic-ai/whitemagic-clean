# ruff: noqa: F403
"""Edge Local LLM (Archived)
========================

This module called a locally-running Ollama instance as part of the edge cascade.

The implementation has been physically relocated to:
`whitemagic/_archived/local_models/edge/local_llm.py`
"""

from __future__ import annotations

import os
from dataclasses import dataclass
from typing import Any
from urllib.parse import urlparse


def _enabled() -> bool:
    return os.getenv("WHITEMAGIC_ENABLE_LOCAL_MODELS", "").strip().lower() in {
        "1",
        "true",
        "yes",
        "on",
    }


def _disabled_error() -> RuntimeError:
    return RuntimeError(
        "Local LLM execution is archived/disabled. "
        "Set WHITEMAGIC_ENABLE_LOCAL_MODELS=1 to enable legacy local-model support.",
    )


def is_url_safe(url: str) -> bool:
    """Check whether a URL is safe for local-model access."""
    parsed = urlparse(url)
    host = (parsed.hostname or "").lower()
    return parsed.scheme in {"http", "https"} and host in {"localhost", "127.0.0.1", "::1"}


if _enabled():  # pragma: no cover - legacy opt-in path
    from whitemagic._archived.local_models.edge.local_llm import *  # type: ignore
else:
    @dataclass
    class CascadeResult:  # pragma: no cover - legacy shim
        query: str
        answer: str
        method: str
        confidence: float
        latency_ms: float
        tokens_saved: int = 0

    class LocalLLM:  # pragma: no cover - legacy shim
        def __init__(self, *args: Any, **kwargs: Any) -> None:
            candidate = kwargs.get("url") or kwargs.get("base_url")
            if candidate is None and args and isinstance(args[0], str):
                candidate = args[0]

            if candidate is not None and not is_url_safe(str(candidate)):
                raise ValueError(f"Unsafe local LLM URL blocked: {candidate}")
            raise _disabled_error()

    class CascadingInference:  # pragma: no cover - legacy shim
        def __init__(self, *_: Any, **__: Any) -> None:
            raise _disabled_error()

    def get_cascade() -> Any:
        raise _disabled_error()

