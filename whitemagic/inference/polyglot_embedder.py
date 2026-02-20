"""PolyglotEmbedder — H002 Rust ONNX + FastEmbed fallback chain (H002 campaign).

Fallback chain:
  1. whitemagic_rs.batch_embed (Rust ONNX, GPU if available)  — target 200-500/s
  2. fastembed TextEmbedding (CPU ONNX)                        — ~50-100/s
  3. sentence-transformers                                      — ~10-20/s
"""
from __future__ import annotations

import logging
import time
from typing import List

import numpy as np

logger = logging.getLogger(__name__)

# ── Backend availability ──────────────────────────────────────────────────────

try:
    import whitemagic_rs as _rs
    _RUST_EMBED = hasattr(_rs, "batch_embed")
except ImportError:
    _rs = None
    _RUST_EMBED = False

try:
    from fastembed import TextEmbedding as _FastEmbed
    _FASTEMBED = True
except ImportError:
    _FastEmbed = None
    _FASTEMBED = False

try:
    from sentence_transformers import SentenceTransformer as _ST
    _SENTENCE_TRANSFORMERS = True
except ImportError:
    _ST = None
    _SENTENCE_TRANSFORMERS = False


class PolyglotEmbedder:
    """Drop-in replacement for LocalEmbedder with Rust ONNX acceleration.

    Usage::

        embedder = PolyglotEmbedder()
        vectors = embedder.embed(["hello world", "local ai is fast"])
        # returns List[List[float]], shape (N, 384)
    """

    DEFAULT_MODEL = "BAAI/bge-small-en-v1.5"

    def __init__(self, model_name: str = DEFAULT_MODEL, max_length: int = 512):
        self.model_name = model_name
        self.max_length = max_length
        self._fastembed_model = None
        self._st_model = None
        self._backend: str = "none"
        self._available = False
        self._init_backend()

    def _init_backend(self) -> None:
        if _RUST_EMBED:
            self._backend = "rust"
            self._available = True
            logger.info("PolyglotEmbedder: using Rust ONNX backend")
            return

        if _FASTEMBED:
            try:
                self._fastembed_model = _FastEmbed(
                    model_name=self.model_name, max_length=self.max_length
                )
                self._backend = "fastembed"
                self._available = True
                logger.info("PolyglotEmbedder: using FastEmbed backend")
                return
            except Exception as e:
                logger.warning(f"FastEmbed init failed: {e}")

        if _SENTENCE_TRANSFORMERS:
            try:
                self._st_model = _ST(self.model_name)
                self._backend = "sentence_transformers"
                self._available = True
                logger.info("PolyglotEmbedder: using SentenceTransformer backend")
                return
            except Exception as e:
                logger.warning(f"SentenceTransformer init failed: {e}")

        logger.error("PolyglotEmbedder: no embedding backend available")

    @property
    def available(self) -> bool:
        return self._available

    @property
    def backend(self) -> str:
        return self._backend

    def embed(self, texts: List[str], batch_size: int = 256) -> List[List[float]]:
        """Embed a list of texts. Returns list of float vectors (dim=384)."""
        if not self._available:
            raise RuntimeError("No embedding backend available")

        texts = [t[:self.max_length * 4] for t in texts]  # rough char limit

        if self._backend == "rust":
            return self._embed_rust(texts, batch_size)
        if self._backend == "fastembed":
            return self._embed_fastembed(texts, batch_size)
        return self._embed_st(texts, batch_size)

    def embed_one(self, text: str) -> List[float]:
        """Embed a single text."""
        return self.embed([text])[0]

    def _embed_rust(self, texts: List[str], batch_size: int) -> List[List[float]]:
        try:
            return _rs.batch_embed(texts, batch_size)
        except Exception as e:
            logger.warning(f"Rust embed failed, falling back: {e}")
            self._backend = "fastembed" if _FASTEMBED else "sentence_transformers"
            self._init_backend()
            return self.embed(texts, batch_size)

    def _embed_fastembed(self, texts: List[str], batch_size: int) -> List[List[float]]:
        results = []
        for i in range(0, len(texts), batch_size):
            batch = texts[i : i + batch_size]
            embeddings = list(self._fastembed_model.embed(batch))
            results.extend([e.tolist() for e in embeddings])
        return results

    def _embed_st(self, texts: List[str], batch_size: int) -> List[List[float]]:
        embeddings = self._st_model.encode(
            texts, batch_size=batch_size, show_progress_bar=False
        )
        return embeddings.tolist()

    def benchmark(self, n: int = 100) -> dict:
        """Quick throughput benchmark."""
        texts = [f"benchmark text number {i} with some content" for i in range(n)]
        t0 = time.time()
        self.embed(texts)
        elapsed = time.time() - t0
        return {
            "backend": self._backend,
            "n": n,
            "elapsed_s": round(elapsed, 3),
            "throughput": round(n / elapsed, 1),
        }
