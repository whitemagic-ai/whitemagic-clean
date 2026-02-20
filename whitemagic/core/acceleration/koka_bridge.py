"""Koka Effect Bridge — Python ↔ Koka via subprocess JSON.
============================================================
Bridges to Koka effect-typed modules for provably-correct pipeline
orchestration. Koka compiles to native C via GCC; called via subprocess
with JSON stdin/stdout protocol (same pattern as Julia bridge).

Koka modules:
- army_deployment.kk — Clone army orchestration with algebraic effects
- search_effects.kk  — Search pipeline with composable effect handlers
- memory_effects.kk  — Memory store/retrieve with transaction effects

Falls back to pure Python when Koka is not available.

Usage:
    from whitemagic.core.acceleration.koka_bridge import (
        koka_plan_deployment, koka_bridge_status
    )
"""
from __future__ import annotations

import logging
import os
import shutil
import subprocess
import tempfile
import threading
from pathlib import Path
from typing import Any

from whitemagic.utils.fast_json import dumps_str as _json_dumps, loads as _json_loads

logger = logging.getLogger(__name__)

_koka_bin: str | None = None
_koka_lock = threading.Lock()
_HAS_KOKA = False
_KOKA_DIR: Path | None = None
_KOKA_BUILD_DIR: Path | None = None


def _find_koka() -> tuple[str | None, Path | None]:
    """Locate Koka binary and source directory."""
    base = Path(__file__).resolve().parent.parent.parent.parent
    koka_dir = base / "whitemagic-koka"

    candidates = [
        os.environ.get("KOKA_PATH", ""),
        shutil.which("koka") or "",
        "/usr/local/bin/koka",
    ]
    for path in candidates:
        if path and os.path.isfile(path) and os.access(path, os.X_OK):
            return path, koka_dir if koka_dir.is_dir() else None
    return None, koka_dir if koka_dir.is_dir() else None


def _init_koka() -> None:
    """Initialize Koka bridge (lazy, thread-safe)."""
    global _koka_bin, _HAS_KOKA, _KOKA_DIR, _KOKA_BUILD_DIR
    if _koka_bin is not None or _HAS_KOKA:
        return
    with _koka_lock:
        if _koka_bin is not None or _HAS_KOKA:
            return
        _koka_bin, _KOKA_DIR = _find_koka()
        if _koka_bin and _KOKA_DIR:
            _HAS_KOKA = True
            _KOKA_BUILD_DIR = _KOKA_DIR / ".koka_build"
            _KOKA_BUILD_DIR.mkdir(exist_ok=True)
            logger.info("Koka bridge initialized: bin=%s, dir=%s", _koka_bin, _KOKA_DIR)
        else:
            logger.debug("Koka not found - using Python fallback")


def _build_koka_runner(module_name: str, commands: list[str]) -> Path | None:
    """Compile a Koka module with a JSON stdio runner into a native binary.

    Generates a thin main.kk wrapper that reads JSON from stdin, dispatches
    to the module, and writes JSON to stdout. Compiles once and caches.
    """
    _init_koka()
    if not _koka_bin or not _KOKA_DIR or not _KOKA_BUILD_DIR:
        return None

    module_src = _KOKA_DIR / f"{module_name}.kk"
    if not module_src.exists():
        logger.debug("Koka source not found: %s", module_src)
        return None

    binary_path = _KOKA_BUILD_DIR / f"{module_name}_runner"
    stamp_path = _KOKA_BUILD_DIR / f"{module_name}.stamp"

    # Check if rebuild needed (source newer than binary)
    if binary_path.exists() and stamp_path.exists():
        src_mtime = module_src.stat().st_mtime
        stamp_mtime = stamp_path.stat().st_mtime
        if src_mtime <= stamp_mtime:
            return binary_path

    # Generate runner source
    cmd_dispatch = "\n    ".join(
        f'"{cmd}" -> handle_{cmd.replace("-", "_")}(req)'
        for cmd in commands
    )
    runner_src = f'''
import {module_name}
import std/core
import std/text/json

fun main() : io ()
  val input = readline()
  match parse-json(input)
    Ok(req) ->
      val cmd = req.field("command").string
      val result = match cmd
        {cmd_dispatch}
        _ -> json-object([("error", json-string("unknown command: " ++ cmd))])
      println(result.show)
    Error(e) ->
      println(json-object([("error", json-string(e))]).show)
'''

    runner_path = _KOKA_BUILD_DIR / f"{module_name}_runner.kk"
    runner_path.write_text(runner_src)

    try:
        proc = subprocess.run(
            [_koka_bin, "-o", str(binary_path), str(runner_path)],
            capture_output=True,
            text=True,
            timeout=60,
            cwd=str(_KOKA_DIR),
        )
        if proc.returncode == 0 and binary_path.exists():
            stamp_path.touch()
            logger.info("Koka compiled: %s → %s", module_name, binary_path)
            return binary_path
        else:
            logger.debug("Koka compile failed for %s: %s", module_name, proc.stderr[:300])
    except subprocess.TimeoutExpired:
        logger.warning("Koka compile timed out for %s", module_name)
    except Exception as e:
        logger.debug("Koka compile error for %s: %s", module_name, e)

    return None


def _call_koka_direct(module_file: str, request: dict[str, Any]) -> dict[str, Any] | None:
    """Call a Koka module directly via `koka -e` (interpret mode, no compile step).

    Slower than compiled binary but works without a runner wrapper.
    Used for modules that have their own main() entry point.
    """
    _init_koka()
    if not _koka_bin or not _KOKA_DIR:
        return None

    src_path = _KOKA_DIR / module_file
    if not src_path.exists():
        logger.debug("Koka source not found: %s", src_path)
        return None

    try:
        proc = subprocess.run(
            [_koka_bin, "-e", str(src_path)],
            input=_json_dumps(request),
            capture_output=True,
            text=True,
            timeout=30,
        )
        if proc.returncode == 0 and proc.stdout.strip():
            parsed = _json_loads(proc.stdout.strip())
            if isinstance(parsed, dict):
                return parsed
        elif proc.stderr:
            logger.debug("Koka %s stderr: %s", module_file, proc.stderr[:300])
    except subprocess.TimeoutExpired:
        logger.warning("Koka %s timed out", module_file)
    except Exception as e:
        logger.debug("Koka %s call failed: %s", module_file, e)
    return None


# ---------------------------------------------------------------------------
# Python-native implementations (used when Koka binary unavailable)
# ---------------------------------------------------------------------------

def _py_plan_deployment(
    tasks: list[dict[str, Any]],
    army_size: int,
    strategy: str = "balanced",
) -> dict[str, Any]:
    """Pure Python fallback for deployment planning."""
    import math
    batches = []
    batch_size = max(1, math.ceil(len(tasks) / max(1, army_size)))
    for i in range(0, len(tasks), batch_size):
        batches.append(tasks[i:i + batch_size])
    return {
        "strategy": strategy,
        "army_size": army_size,
        "total_tasks": len(tasks),
        "batches": len(batches),
        "batch_plan": [
            {"batch": idx, "tasks": [t.get("id", str(i)) for i, t in enumerate(b)]}
            for idx, b in enumerate(batches)
        ],
        "backend": "python_fallback",
    }


def _py_search_pipeline(
    query: str,
    strategies: list[str],
    limit: int = 10,
) -> dict[str, Any]:
    """Pure Python fallback for search pipeline planning."""
    return {
        "query": query,
        "strategies": strategies,
        "limit": limit,
        "pipeline": [{"step": i + 1, "strategy": s} for i, s in enumerate(strategies)],
        "backend": "python_fallback",
    }


# ---------------------------------------------------------------------------
# Public API
# ---------------------------------------------------------------------------

def koka_plan_deployment(
    tasks: list[dict[str, Any]],
    army_size: int = 10,
    strategy: str = "balanced",
) -> dict[str, Any]:
    """Plan clone army deployment using Koka effect-typed orchestration.

    Args:
        tasks: List of {id, priority, type} task dicts.
        army_size: Number of parallel workers.
        strategy: 'balanced' | 'priority' | 'adaptive'

    Returns:
        Deployment plan with batch assignments.
    """
    _init_koka()
    if _HAS_KOKA:
        result = _call_koka_direct("army_deployment.kk", {
            "command": "plan_deployment",
            "tasks": tasks,
            "army_size": army_size,
            "strategy": strategy,
        })
        if result:
            return result
    return _py_plan_deployment(tasks, army_size, strategy)


def koka_search_pipeline(
    query: str,
    strategies: list[str] | None = None,
    limit: int = 10,
) -> dict[str, Any]:
    """Build a composable search pipeline using Koka effect handlers.

    Args:
        query: Search query string.
        strategies: Ordered list of search strategies to compose.
        limit: Max results per strategy.

    Returns:
        Pipeline plan with composable effect steps.
    """
    _init_koka()
    strats = strategies or ["lexical", "semantic", "hybrid"]
    if _HAS_KOKA:
        result = _call_koka_direct("search_effects.kk", {
            "command": "build_pipeline",
            "query": query,
            "strategies": strats,
            "limit": limit,
        })
        if result:
            return result
    return _py_search_pipeline(query, strats, limit)


def koka_bridge_status() -> dict[str, Any]:
    """Get Koka bridge status."""
    _init_koka()
    modules = {}
    if _KOKA_DIR:
        for f in ["army_deployment.kk", "search_effects.kk", "memory_effects.kk",
                  "intelligence_effects.kk", "graph_effects.kk", "dream_orchestration.kk"]:
            modules[f.replace(".kk", "")] = (_KOKA_DIR / f).exists()

    return {
        "has_koka": _HAS_KOKA,
        "koka_bin": _koka_bin or "not found",
        "koka_dir": str(_KOKA_DIR) if _KOKA_DIR else "not found",
        "modules": modules,
        "backend": "koka_effects" if _HAS_KOKA else "python_fallback",
    }
