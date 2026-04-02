import asyncio
import logging
import os
import time
import traceback
from collections.abc import Coroutine
from concurrent.futures import ThreadPoolExecutor, TimeoutError
from pathlib import Path
from typing import Any, TypeVar, cast
from uuid import uuid4

from whitemagic.utils.fast_json import dumps_str as _json_dumps, loads as _json_loads
from whitemagic.tools.errors import ToolExecutionError

# Tool contract helpers (AI-first)
from whitemagic.config.paths import WM_ROOT, ensure_paths
from whitemagic.tools.errors import ErrorCode
from whitemagic.utils.time import now_iso, override_now

logger = logging.getLogger(__name__)
T = TypeVar("T")

# v21: Centralized executor for tool dispatch to prevent thread-bombing
_TOOL_DISPATCH_EXECUTOR = ThreadPoolExecutor(max_workers=8, thread_name_prefix="tool-dispatch")

_DEFAULT_TOOL_DISPATCH_TIMEOUT_S = float(os.getenv("WM_TOOL_DISPATCH_TIMEOUT_S", "30.0"))
_TOOL_TIMEOUT_CLASS_BUDGETS_S: dict[str, float] = {
    "default": _DEFAULT_TOOL_DISPATCH_TIMEOUT_S,
    "cold_status": float(os.getenv("WM_TOOL_TIMEOUT_COLD_STATUS_S", "15.0")),
    "local_generation": float(os.getenv("WM_TOOL_TIMEOUT_LOCAL_GENERATION_S", "30.0")),
    "agent_generation": float(os.getenv("WM_TOOL_TIMEOUT_AGENT_GENERATION_S", "45.0")),
}
_TOOL_TIMEOUT_CLASS_BY_TOOL: dict[str, str] = {
    "vector.status": "cold_status",
    "ollama.generate": "local_generation",
    "ollama.chat": "local_generation",
    "ollama.agent": "agent_generation",
}
_LIGHTWEIGHT_STATUS_TOOLS: set[str] = {
    "vector.status",
    "prompt.list",
    "forge.status",
}
_FAST_INTERACTIVE_WRITE_TOOLS: set[str] = {
    "create_memory",
}

_TOOL_CLASS_TIMEOUTS: dict[str, float] = {
    "create_memory": 30.0,
}


#!/usr/bin/env python3
"""
Safe integration script for Gana tool circuit breakers.
This creates a patch for unified_api.py with timeout and circuit breaker support.
"""

GANA_TIMEOUTS_PATCH = '''
# =============================================================================
# GANA TOOL TIMEOUTS AND CIRCUIT BREAKER CONFIGURATION (V20)
# Added to prevent hangs and provide graceful degradation for all 28 Gana families
# =============================================================================

# Tool-specific timeouts for all 28 Gana MCP tools (in seconds)
GANA_TOOL_TIMEOUTS: dict[str, int] = {
    # Root/Foundation (gana_root)
    "health_report": 10, "rust_audit": 30, "rust_status": 15, "state_summary": 10, "ship_check": 15,

    # Winnowing Basket (gana_winnowing_basket)
    "search_memories": 15, "vector_search": 20, "hybrid_recall": 20, "graph_walk": 25, "recall": 10,
    "batch_read_memories": 30, "list_memories": 15, "fast_read_memory": 10, "vector_index": 20,
    "vector_status": 15,

    # Neck (gana_neck)
    "create_memory": 10, "update_memory": 10, "delete_memory": 10, "import_memories": 60,
    "thought_clone": 15, "remember": 10,

    # Net (gana_net)
    "prompt_render": 5, "prompt_list": 5, "prompt_reload": 5, "karma_verify_chain": 10,

    # Ghost (gana_ghost)
    "gnosis": 15, "get_telemetry_summary": 10, "web_search": 30, "web_fetch": 30,
    "research_topic": 60, "browser_navigate": 45, "browser_click": 10, "browser_type": 10,
    "browser_screenshot": 15, "browser_extract_dom": 20, "browser_get_interactables": 15,
    "browser_session_status": 5, "surprise_stats": 10, "explain_this": 20, "graph_topology": 25,
    "manifest": 10, "capabilities": 10, "get_agent_capabilities": 10, "selfmodel_forecast": 30,
    "selfmodel_alerts": 15, "watcher_add": 10, "watcher_remove": 10, "watcher_list": 10,
    "watcher_status": 10, "watcher_recent_events": 15, "watcher_start": 15, "watcher_stop": 15,
    "watcher_stats": 10, "web_search_and_read": 45,

    # Heart (gana_heart)
    "scratchpad": 10, "scratchpad_create": 10, "scratchpad_update": 10, "scratchpad_finalize": 10,
    "analyze_scratchpad": 20, "session_handoff": 15, "context_pack": 30, "context_status": 10,
    "working_memory_attend": 15, "working_memory_context": 15, "working_memory_status": 10,

    # Horn (gana_horn)
    "session_bootstrap": 20, "create_session": 15, "resume_session": 20, "checkpoint_session": 30,
    "session_handoff_transfer": 15, "session_list_handoffs": 10, "session_accept_handoff": 15,
    "session_status": 10, "focus_session": 15,

    # Dipper (gana_dipper) - Extended timeouts for stability
    "homeostasis": 60, "homeostasis_check": 60, "homeostasis_status": 30, "maturity_assess": 60,
    "starter_packs": 30, "starter_packs_list": 20, "starter_packs_get": 20, "starter_packs_suggest": 45,
    "cognitive_set": 30, "cognitive_mode": 25, "cognitive_stats": 25, "cognitive_hints": 30,
    "doctrine_stratagems": 45, "doctrine_summary": 35, "doctrine_force": 45,

    # Willow (gana_willow) - Extended timeouts for stability
    "cast_oracle": 45, "grimoire_list": 25, "grimoire_read": 25, "grimoire_suggest": 35,
    "grimoire_recommend": 35, "grimoire_cast": 45, "grimoire_walkthrough": 60,
    "rate_limiter_stats": 15, "fool_guard_status": 25, "fool_guard_ralph": 45,
    "fool_guard_dare_to_die": 60, "grimoire_auto_status": 15,

    # Room (gana_room)
    "sangha_lock": 10, "sangha_lock_acquire": 10, "sangha_lock_release": 10, "sangha_lock_list": 10,
    "hermit_status": 20, "hermit_check_access": 15, "hermit_assess": 30, "hermit_mediate": 45,
    "hermit_resolve": 60, "hermit_withdraw": 45, "hermit_verify_ledger": 30, "sandbox_status": 15,
    "sandbox_set_limits": 20, "sandbox_violations": 20, "mcp_integrity_status": 20,
    "mcp_integrity_verify": 25, "mcp_integrity_snapshot": 25, "anti_loop_check": 15,
    "immune_scan": 45, "immune_heal": 45, "security_monitor_status": 20, "security_alerts": 20,

    # Star (gana_star)
    "governor_validate": 25, "governor_set_goal": 20, "governor_check_drift": 45,
    "governor_check_budget": 20, "governor_check_dharma": 30, "governor_stats": 20,
    "governor_validate_path": 35, "forge_status": 20, "forge_reload": 30, "forge_validate": 35,
    "dharma_reload": 30, "set_dharma_profile": 20, "guideline_evolve": 45,

    # Tail (gana_tail)
    "simd_status": 15, "simd_cosine": 25, "simd_batch": 35, "execute_cascade": 90,
    "list_cascade_patterns": 20, "token_report": 15,

    # Three Stars (gana_three_stars)
    "reasoning_bicameral": 60, "reasoning_multispectral": 75, "ensemble": 75,
    "ensemble_query": 45, "ensemble_history": 30, "ensemble_status": 20, "think": 45,
    "kaizen_analyze": 60, "kaizen_apply_fixes": 75, "solve_optimization": 60,
    "elemental_optimize": 75, "art_of_war_wisdom": 30, "art_of_war_terrain": 35,
    "art_of_war_chapter": 30, "art_of_war_campaign": 45, "satkona_fuse": 60,
    "sabha_convene": 45, "sabha_status": 20,

    # Straddling Legs (gana_straddling_legs)
    "evaluate_ethics": 45, "verify_consent": 20, "check_boundaries": 30, "get_ethical_score": 20,
    "get_dharma_guidance": 35, "wu_xing_balance": 30, "harmony_vector": 30,
    "verification_request": 20, "verification_status": 20, "verification_attest": 20,

    # Abundance (gana_abundance)
    "dream_start": 30, "dream_stop": 25, "dream_status": 15, "dream_now": 75,
    "entity_resolve": 45, "gratitude_benefits": 25, "gratitude_stats": 15, "ilp_status": 20,
    "ilp_balance": 15, "ilp_send": 30, "ilp_receipt": 20, "ilp_history": 30,
    "ilp_configure": 20, "memory_lifecycle": 45, "memory_consolidate": 60,
    "memory_consolidation_stats": 20, "memory_retention_sweep": 75, "memory_lifecycle_sweep": 75,
    "memory_lifecycle_stats": 20, "reconsolidation_mark": 45, "reconsolidation_status": 20,
    "reconsolidation_update": 45, "narrative_compress": 60, "narrative_stats": 20,
    "serendipity_surface": 45, "serendipity_mark_accessed": 20, "galactic_stats": 20,
    "galactic_sweep": 75, "dream": 75,

    # Girl (gana_girl)
    "agent_list": 20, "agent_register": 30, "agent_deregister": 20, "agent_heartbeat": 15,
    "agent_capabilities": 20, "agent_trust": 30,

    # Void (gana_void)
    "galaxy_list": 20, "galaxy_status": 20, "galaxy_create": 30, "galaxy_delete": 20,
    "galaxy_switch": 20, "galaxy_transfer": 45, "galaxy_merge": 60, "galaxy_sync": 75,
    "galaxy_backup": 60, "galaxy_restore": 75, "galaxy_lineage": 45, "galaxy_taxonomy": 60,
    "galaxy_ingest": 75, "garden_list_files": 30, "garden_list_functions": 30,
    "garden_map_system": 45, "garden_stats": 20, "garden_status": 20, "garden_health": 30,
    "garden_browse": 35, "garden_activate": 45, "garden_search": 45, "garden_resolve": 45,
    "garden_resonance": 60, "garden_synergy": 60, "oms_list": 20, "oms_status": 20,
    "oms_price": 20, "oms_export": 75, "oms_import": 75, "oms_verify": 45,
    "oms_inspect": 45, "galactic_dashboard": 60,

    # Wings (gana_wings)
    "export_memories": 75, "audit_export": 75, "mesh_connect": 20, "mesh_status": 20, "mesh_broadcast": 45,

    # Mound (gana_mound)
    "get_metrics_summary": 20, "view_hologram": 45, "get_yin_yang_balance": 20,
    "track_metric": 15, "green_report": 30, "green_record": 15, "record_yin_yang_activity": 15,

    # Hairy Head (gana_hairy_head)
    "salience_spotlight": 45, "anomaly_check": 30, "anomaly_status": 20, "anomaly_history": 30,
    "karma_report": 20, "karmic_trace": 45, "karma_anchor": 30, "karma_anchor_status": 20,
    "karma_verify_anchor": 30, "dharma_rules": 20, "otel": 20, "otel_metrics": 20,
    "otel_spans": 20, "otel_status": 15, "anomaly": 30,

    # Ox (gana_ox)
    "swarm_decompose": 75, "swarm_route": 60, "swarm_plan": 75, "swarm_vote": 45,
    "swarm_resolve": 60, "swarm_complete": 75, "swarm_status": 20, "worker_status": 20,
    "war_room_plan": 75, "war_room_status": 30, "war_room_hierarchy": 45,
    "war_room_execute": 75, "war_room_phase": 60, "war_room_campaigns": 30,

    # Turtle Beak (gana_turtle_beak)
    "edge_infer": 30, "edge_batch_infer": 60, "edge_stats": 20, "edge_add_rule": 20,
    "bitnet_infer": 45, "bitnet_status": 20,

    # Roof (gana_roof)
    "ollama_models": 20, "ollama_generate": 75, "ollama_chat": 75, "ollama_agent": 60,
    "shelter_create": 45, "shelter_destroy": 20, "shelter_execute": 60, "shelter_inspect": 30,
    "shelter_status": 20, "shelter_policy": 30, "model_list": 20, "model_register": 30,
    "model_signing_status": 20, "model_hash": 30, "model_verify": 35,

    # Stomach (gana_stomach)
    "pipeline": 45, "pipeline_create": 30, "pipeline_list": 20, "pipeline_status": 20,
    "task_distribute": 60, "task_route_smart": 60, "task_status": 20, "task_list": 20,
    "task_complete": 30,

    # Wall (gana_wall)
    "vote_create": 30, "vote_cast": 20, "vote_analyze": 45, "vote_list": 20,
    "vote_record_outcome": 30, "engagement_issue": 20, "engagement_validate": 20,
    "engagement_list": 20, "engagement_revoke": 20, "engagement_status": 20,

    # Encampment (gana_encampment)
    "sangha_chat_send": 20, "sangha_chat_read": 20, "broker_publish": 30,
    "broker_history": 30, "broker_status": 20, "ganying_emit": 20, "ganying_history": 30,
    "ganying_listeners": 20,

    # Extended Net (gana_extended_net)
    "pattern_search": 45, "cluster_stats": 30, "learning_patterns": 60, "learning_status": 20,
    "learning_suggest": 45, "resonance_trace": 60, "association_mine": 75,
    "association_mine_semantic": 75, "causal_mine": 75, "causal_stats": 20,
    "coherence_boost": 45, "community_health": 35, "community_status": 20,
    "community_propagate": 60, "constellation_detect": 60, "constellation_stats": 20,
    "constellation_merge": 45, "emergence_scan": 75, "emergence_status": 20,
    "novelty_detect": 60, "novelty_stats": 20, "tool_graph": 45, "tool_graph_full": 60,
    "pattern_consciousness_status": 20,

    # Chariot (gana_chariot) - Extended timeouts for stability
    "archaeology": 75, "archaeology_stats": 20, "archaeology_search": 60,
    "archaeology_scan_directory": 75, "archaeology_mark_read": 30, "archaeology_mark_written": 30,
    "archaeology_have_read": 20, "archaeology_find_unread": 45, "archaeology_find_changed": 45,
    "archaeology_recent_reads": 30, "archaeology_daily_digest": 45, "archaeology_process_wisdom": 60,
    "archaeology_report": 45, "kg_extract": 60, "kg_query": 45, "kg_status": 20,
    "kg_top": 30, "kg2_extract": 60, "kg2_batch": 75, "kg2_entity": 45, "kg2_stats": 20,
    "marketplace_status": 20, "marketplace_discover": 45, "marketplace_publish": 45,
    "marketplace_negotiate": 60, "marketplace_complete": 45, "marketplace_my_listings": 30,
    "marketplace_remove": 30, "windsurf_list_conversations": 30, "windsurf_read_conversation": 45,
    "windsurf_search_conversations": 45, "windsurf_export_conversation": 60, "windsurf_stats": 20,
    "kg2": 60,

    # Net (gana_net)
    "embedding_daemon_start": 45, "embedding_daemon_stop": 20, "embedding_daemon_status": 20,
    "embedding_daemon_process": 60,
}

# Default timeout for any tool not explicitly configured
DEFAULT_GANA_TIMEOUT: int = 30

# Circuit breaker configurations by tool category
GANA_CB_CONFIGS: dict[str, dict[str, float]] = {
    "fast": {"failure_threshold": 5, "window_seconds": 60.0, "cooldown_seconds": 15.0},
    "standard": {"failure_threshold": 3, "window_seconds": 60.0, "cooldown_seconds": 30.0},
    "heavy": {"failure_threshold": 2, "window_seconds": 180.0, "cooldown_seconds": 60.0},
    "network": {"failure_threshold": 3, "window_seconds": 120.0, "cooldown_seconds": 45.0},
    "critical": {"failure_threshold": 5, "window_seconds": 60.0, "cooldown_seconds": 10.0},
}

def _get_gana_tool_timeout(tool_name: str) -> int:
    """Get timeout in seconds for a specific Gana tool."""
    # Normalize tool name (remove gana_ prefix if present)
    normalized = tool_name.replace("gana_", "").replace(".", "_")
    return GANA_TOOL_TIMEOUTS.get(normalized, DEFAULT_GANA_TIMEOUT)

def _get_gana_cb_config(tool_name: str) -> dict[str, float]:
    """Get circuit breaker config for a Gana tool based on its characteristics."""
    tool_lower = tool_name.lower()

    # Critical status/info tools - be lenient
    if any(x in tool_lower for x in ["status", "stats", "list", "health", "report", "check"]):
        return GANA_CB_CONFIGS["critical"]

    # Heavy compute tools - strict
    if any(x in tool_lower for x in ["swarm_", "war_room_", "sweep", "mine", "scan", "consolidate", "compress", "emergence"]):
        return GANA_CB_CONFIGS["heavy"]

    # Network operations - moderate
    if any(x in tool_lower for x in ["web_", "browser_", "network", "fetch", "search", "galaxy_"]):
        return GANA_CB_CONFIGS["network"]

    # Fast operations
    if any(x in tool_lower for x in ["get_", "check_", "prompt_", "karma_"]):
        return GANA_CB_CONFIGS["fast"]

    return GANA_CB_CONFIGS["standard"]

# Debug flag for Gana tool execution
GANA_DEBUG = os.getenv("WM_GANA_DEBUG", "0") == "1"

def _log_gana_debug(tool_name: str, message: str) -> None:
    """Log debug message if GANA_DEBUG is enabled."""
    if GANA_DEBUG:
        logger.info(f"[GANA_DEBUG:{tool_name}] {message}")

# =============================================================================
# END GANA TOOL TIMEOUTS AND CIRCUIT BREAKER CONFIGURATION
# =============================================================================
'''

if __name__ == "__main__":
    print("GANA_TIMEOUTS_PATCH ready for integration into unified_api.py")
    print(f"Patch length: {len(GANA_TIMEOUTS_PATCH)} characters")
    print("\nTo apply:")
    print("1. Backup: cp unified_api.py unified_api.py.backup")
    print("2. Insert this patch after the imports section")
    print("3. Use the _get_gana_tool_timeout() function in dispatch logic")
def _dispatch_timeout_for_tool(tool_name: str) -> float:
    if tool_name in _TOOL_CLASS_TIMEOUTS:
        return _TOOL_CLASS_TIMEOUTS[tool_name]

    timeout_class = _TOOL_TIMEOUT_CLASS_BY_TOOL.get(tool_name, "default")
    return _TOOL_TIMEOUT_CLASS_BUDGETS_S.get(timeout_class, _DEFAULT_TOOL_DISPATCH_TIMEOUT_S)

def _nervous_system_check(tool_name: str) -> tuple[bool, str]:
    """Pre-dispatch check via Nervous System (StateBoard + DispatchBridge).

    Checks circuit breakers and rate limits via the Zig/Python dispatch bridge.
    Returns (allowed, reason).
    """
    try:
        from whitemagic.core.acceleration.dispatch_bridge import DispatchResult, get_dispatch
        bridge = get_dispatch()
        # Map tool name to a generic tool_id (0-27) via hash
        tool_id = hash(tool_name) % 28
        result = bridge.check(tool_id)
        if result == DispatchResult.CIRCUIT_OPEN:
            return False, f"Circuit breaker OPEN for {tool_name}"
        if result == DispatchResult.RATE_LIMITED:
            return False, f"Rate limited: {tool_name}"
        if result == DispatchResult.IMMATURE:
            return False, f"Tool maturity gate blocked: {tool_name}"
    except Exception:
        pass  # Nervous system is advisory — never block on failure
    return True, ""


def _nervous_system_post(tool_name: str, duration: float, success: bool) -> None:
    """Post-dispatch: sync Harmony Vector to StateBoard and publish to EventRing."""
    # Sync Harmony Vector → StateBoard mmap
    try:
        from whitemagic.harmony.vector import get_harmony_vector
        from whitemagic.core.acceleration.state_board_bridge import get_state_board
        hv = get_harmony_vector()
        snap = hv.snapshot()
        board = get_state_board()
        board.write_harmony(
            balance=snap.balance,
            throughput=snap.throughput,
            latency=snap.latency,
            error_rate=snap.error_rate,
            dharma=snap.dharma,
            karma_debt=snap.karma_debt,
            energy=snap.energy,
        )
    except Exception:
        pass
    # Publish tool completion to EventRing
    try:
        from whitemagic.core.acceleration.event_ring_bridge import get_event_ring
        event_type = "tool_completed" if success else "error_occurred"
        get_event_ring().publish(
            event_type=event_type,
            source=tool_name,
            confidence=1.0,
            data=f"{duration:.3f}s".encode()[:80],
        )
    except Exception:
        pass


def _emit_gan_ying(event_type_name: str, data: dict[str, Any], source: str = "mcp") -> None:
    """Emit Gan Ying events without breaking tool flows."""
    try:
        # Use the public wrapper (handles unknown string event types safely).
        from whitemagic.core.resonance.gan_ying import emit_event

        emit_event(event_type_name, data, source=source, confidence=1.0)
    except Exception as exc:
        logger.info(f"Gan Ying event ({event_type_name}) failed: {exc}")

def _load_rust() -> tuple[object | None, str | None]:
    """Load the Rust bridge if available."""
    try:
        try:
            import whitemagic_rust as rs_module  # type: ignore
        except ImportError:
            import whitemagic_rs as rs_module  # type: ignore
        return rs_module, None
    except Exception as exc:  # pragma: no cover - best-effort availability
        return None, str(exc)


def _resolve_base_path(kwargs: dict[str, Any]) -> Path:
    """Resolve base path with security validation."""
    base_path = kwargs.get("base_path") or os.environ.get("WM_BASE_PATH")
    if not base_path:
        return cast("Path", WM_ROOT)

    resolved = Path(base_path).expanduser().resolve()

    # Strong default: state lives under WM_STATE_ROOT. Allow external state roots
    # only via explicit opt-in.
    allow_external = os.getenv("WHITEMAGIC_ALLOW_EXTERNAL_STATE_ROOT", "false").lower() == "true"
    if not allow_external:
        try:
            resolved.relative_to(WM_ROOT)
        except ValueError:
            return cast("Path", WM_ROOT)

    # Security: validate base_path is allowed (read/write allowlist).
    from whitemagic.security.tool_gating import get_tool_gate
    gate = get_tool_gate()
    allowed, _reason = gate.path_validator.is_path_allowed(str(resolved))
    if not allowed:
        return cast("Path", WM_ROOT)

    resolved.mkdir(parents=True, exist_ok=True)
    return resolved


def _session_dir(base_path: Path) -> Path:
    session_dir = base_path / "sessions"
    session_dir.mkdir(parents=True, exist_ok=True)
    return session_dir


def _session_path(base_path: Path, session_id: str) -> Path:
    return _session_dir(base_path) / f"{session_id}.json"


def _load_session(base_path: Path, session_id: str) -> dict[str, Any]:
    path = _session_path(base_path, session_id)
    if not path.exists():
        raise FileNotFoundError(f"Session not found: {session_id}")
    return cast("dict[str, Any]", _json_loads(path.read_text(encoding="utf-8")))


def _save_session(base_path: Path, session: dict[str, Any]) -> None:
    path = _session_path(base_path, session["id"])
    path.write_text(_json_dumps(session, indent=2), encoding="utf-8")


def _run_async(coro: Coroutine[Any, Any, T]) -> T:
    try:
        asyncio.get_running_loop()
    except RuntimeError:
        return asyncio.run(coro)

    with ThreadPoolExecutor(max_workers=1) as executor:
        return executor.submit(asyncio.run, coro).result()


def _local_models_archived() -> dict[str, Any]:
    return {
        "status": "error",
        "message": "Local model execution is archived/disabled in this build. "
        "Use an external model via MCP/REST to call Whitemagic tools.",
        "archived": True,
    }


def record_yin_yang_activity(activity: str) -> dict[str, Any]:
    """Record Yin-Yang activity from MCP."""
    try:
        from whitemagic.harmony.yin_yang_tracker import get_tracker

        tracker = get_tracker()
        metrics = tracker.record_activity(activity)

        return {
            "success": True,
            "balance_score": metrics.balance_score,
            "burnout_risk": metrics.burnout_risk,
            "recommendation": metrics.recommendation,
            "yang_ratio": metrics.yang_ratio,
            "yin_ratio": metrics.yin_ratio,
        }
    except Exception as e:
        return {"success": False, "error": str(e)}


def get_yin_yang_balance() -> dict[str, Any]:
    """Get current Yin-Yang balance report."""
    try:
        from whitemagic.harmony.yin_yang_tracker import get_tracker

        tracker = get_tracker()
        return cast("dict[str, Any]", tracker.get_report())
    except Exception as e:
        return {"error": str(e)}


def _dispatch_tool(tool_name: str, **kwargs: Any) -> Any:
    """Dispatch tool calls via the dispatch table (v11 refactor).

    The dispatch table lives in whitemagic.tools.dispatch_table and maps
    tool names to handler functions grouped by category.  Governor
    interception, gana prefix routing, and bridge fallback are handled
    inside ``dispatch()``.
    """
    from whitemagic.tools.dispatch_table import dispatch as _table_dispatch

    return _table_dispatch(tool_name, **kwargs)


def _dispatch_lightweight_tool(tool_name: str, **kwargs: Any) -> Any:
    if tool_name == "vector.status":
        from whitemagic.core.memory.vector_search import get_vector_status
        return {"status": "success", **get_vector_status()}
    if tool_name == "prompt.list":
        from whitemagic.prompts import get_prompt_engine
        tag = kwargs.get("tag")
        engine = get_prompt_engine()
        return {
            "status": "success",
            "templates": engine.list_templates(tag=tag),
            **engine.status(),
        }
    if tool_name == "forge.status":
        from whitemagic.tools.gana_forge import _DEFAULT_EXT_DIR, discover_extensions
        ext_dir = _DEFAULT_EXT_DIR
        manifests = discover_extensions(ext_dir)
        loaded_names: list[str] = []
        try:
            from whitemagic.tools.prat_router import TOOL_TO_GANA
            loaded_names = [
                name for name in TOOL_TO_GANA
                if name.startswith("ext.") or name.startswith("custom.")
            ]
        except Exception:
            pass
        return {
            "status": "success",
            "extensions_dir": str(ext_dir),
            "extensions_dir_exists": ext_dir.exists(),
            "manifests_found": len(manifests),
            "manifest_files": [m.get("_source_path", "?") for m in manifests],
            "loaded_extension_tools": loaded_names,
            "usage": (
                "Place YAML manifests in ~/.whitemagic/extensions/ with format:\n"
                "tool:\n"
                "  name: custom.my_tool\n"
                "  description: What it does\n"
                "  gana: gana_ghost\n"
                "  safety: read\n"
                "  handler: 'my_module:my_function'"
            ),
        }
    raise KeyError(tool_name)


def _dispatch_tool_with_timeout(tool_name: str, timeout_s: float, **kwargs: Any) -> Any:
    """Run tool dispatch with a hard client-facing timeout."""
    # v21: Use the centralized executor instead of spawning raw threads
    future = _TOOL_DISPATCH_EXECUTOR.submit(_dispatch_tool, tool_name, **kwargs)

    try:
        return future.result(timeout=timeout_s)
    except TimeoutError as exc:
        raise TimeoutError(f"Tool dispatch timed out after {timeout_s:.1f}s: {tool_name}") from exc
    except Exception as exc:
        raise exc


# Dead code removed: the 1400-line if/elif dispatcher was replaced by
# whitemagic.tools.dispatch_table (Phase 2 refactor, v11 hardening).
# Original handlers live in whitemagic/tools/handlers/*.py


_DEAD_CODE_REMOVED = True  # Marker for grep-ability



_TOOL_ALIASES: dict[str, str] = {
    # Legacy names -> canonical v11 names
    "manifest_read": "manifest",
    "manifest_summary": "manifest",
    "state_paths": "state.paths",
    "state_summary": "state.summary",
    "repo_summary": "repo.summary",
    "ship_check": "ship.check",
    # Underscore aliases for dot-notation tools
    "mesh_connect": "mesh.connect",
    "broker_publish": "broker.publish",
    "broker_history": "broker.history",
    "broker_status": "broker.status",
    "task_distribute": "task.distribute",
    "task_status": "task.status",
    "task_list": "task.list",
    "task_complete": "task.complete",
    "vote_create": "vote.create",
    "vote_cast": "vote.cast",
    "vote_analyze": "vote.analyze",
    "vote_list": "vote.list",
    "vote_record_outcome": "vote.record_outcome",
    "ollama_models": "ollama.models",
    "ollama_generate": "ollama.generate",
    "ollama_chat": "ollama.chat",
    "agent_register": "agent.register",
    "agent_heartbeat": "agent.heartbeat",
    "agent_list": "agent.list",
    "agent_capabilities": "agent.capabilities",
    "agent_deregister": "agent.deregister",
    "pipeline_create": "pipeline.create",
    "pipeline_status": "pipeline.status",
    "pipeline_list": "pipeline.list",
    "homeostasis_status": "homeostasis.status",
    "homeostasis_check": "homeostasis.check",
    "maturity_assess": "maturity.assess",
    "tool_graph": "tool.graph",
    "tool_graph_full": "tool.graph_full",
    "dharma_reload": "dharma.reload",
    "salience_spotlight": "salience.spotlight",
    "reasoning_bicameral": "reasoning.bicameral",
    "memory_retention_sweep": "memory.retention.sweep",
    "read_memory": "memory_read",
    "update_memory": "memory_update",
    "delete_memory": "memory_delete",
    "starter_packs_list": "starter_packs.list",
    "starter_packs_get": "starter_packs.get",
    "starter_packs_suggest": "starter_packs.suggest",
    "capability_matrix": "capability.matrix",
    "capability_status": "capability.status",
    "capability_suggest": "capability.suggest",
    "rate_limiter_stats": "rate_limiter.stats",
    "audit_export": "audit.export",
    "agent_trust": "agent.trust",
}

_TOOL_CLASS_TIMEOUTS.update({
    "memory.consolidate": 60.0,  # Consolidation can be heavy
    "archaeology.scan": 30.0,
    "search_query": 15.0,
})


def _canonical_tool_name(tool_name: str) -> str:
    name = tool_name.strip()
    return _TOOL_ALIASES.get(name, name)


def _tool_writes_hint(tool_name: str) -> list[dict[str, Any]]:
    # Best-effort: most writes are within WM_STATE_ROOT.
    return [{"kind": "wm_state_root", "path": str(WM_ROOT)}]


def call_tool(tool_name: str, **kwargs: Any) -> dict[str, Any]:
    """Canonical tool entrypoint (AI-first contract).

    Responsibilities:
    - Ensure WM_STATE_ROOT directories exist
    - Validate params (best-effort) against TOOL_REGISTRY schema when available
    - Apply ToolGate policy checks
    - Provide idempotency for write tools via `idempotency_key`
    - Normalize all outputs into the stable envelope format
    """
    from whitemagic.tools.envelope import err, normalize_raw
    from whitemagic.tools.registry import ToolSafety, get_tool
    from whitemagic.tools.schema import validate_params

    ensure_paths()

    # Common fields (present in every tool schema)
    request_id = str(kwargs.pop("request_id", "") or uuid4())
    idempotency_key = kwargs.pop("idempotency_key", None)
    dry_run = bool(kwargs.pop("dry_run", False))
    now_override = kwargs.pop("now", None)

    canonical = _canonical_tool_name(tool_name)
    ts = now_override or now_iso()
    call_started_at = time.time()

    if canonical not in _FAST_INTERACTIVE_WRITE_TOOLS:
        # Touch dream cycle idle timer on every tool call
        try:
            from whitemagic.core.dreaming import get_dream_cycle
            get_dream_cycle().touch()
        except Exception:
            pass

        # Cross-session learning — record tool usage
        try:
            from whitemagic.core.learning import get_session_learner
            get_session_learner().record_tool_use(canonical)
        except Exception:
            pass

    def _record_telemetry(out: dict[str, Any]) -> None:
        duration = time.time() - call_started_at
        status_value = str(out.get("status", "")).lower()
        telemetry_status = "success" if status_value in {"success", "ok"} else "error"
        telemetry_error = out.get("error_code") if telemetry_status == "error" else None
        try:
            from whitemagic.core.monitoring.telemetry import get_telemetry
            get_telemetry().record_call(canonical, duration, telemetry_status, telemetry_error)
        except Exception:
            pass
        try:
            from whitemagic.core.monitoring.otel_export import record_tool_span
            record_tool_span(canonical, duration, telemetry_status)
        except Exception:
            pass
        if canonical in _LIGHTWEIGHT_STATUS_TOOLS:
            return
        if canonical in _FAST_INTERACTIVE_WRITE_TOOLS:
            return
        declared_safety = "READ"
        if tool_def is not None:
            declared_safety = tool_def.safety.value.upper()
        actual_writes = len(out.get("writes", []) or [])
        try:
            from whitemagic.harmony.vector import get_harmony_vector
            hv = get_harmony_vector()
            snap = hv.record_call(
                tool_name=canonical,
                duration_s=duration,
                success=(telemetry_status == "success"),
                declared_safety=declared_safety,
                actual_writes=actual_writes,
            )
            metrics = out.get("metrics")
            if isinstance(metrics, dict):
                metrics["harmony_score"] = snap.harmony_score
                metrics["guna"] = snap.guna_rajasic_pct
        except Exception:
            pass
        try:
            from whitemagic.dharma.karma_ledger import get_karma_ledger
            get_karma_ledger().record(
                tool=canonical,
                declared_safety=declared_safety,
                actual_writes=actual_writes,
                success=(telemetry_status == "success"),
            )
        except Exception:
            pass

    def _finish(out: dict[str, Any]) -> dict[str, Any]:
        _record_telemetry(out)
        return out

    with override_now(now_override):
        tool_def = get_tool(canonical)

        # Best-effort schema validation (only for registry tools).
        if tool_def is not None:
            valid, reason, sanitized = validate_params(tool_def.input_schema, kwargs)
            if not valid:
                return _finish(err(
                    tool=canonical,
                    request_id=request_id,
                    idempotency_key=idempotency_key,
                    timestamp=ts,
                    error_code=ErrorCode.INVALID_PARAMS,
                    message=reason,
                    details={"tool": canonical},
                ))
            kwargs = sanitized

        # ToolGate policy checks + param sanitation (applies to all non-lightweight tools).
        if canonical not in _LIGHTWEIGHT_STATUS_TOOLS:
            from whitemagic.security.tool_gating import check_tool_execution
            allowed, reason, sanitized_params = check_tool_execution(canonical, kwargs)
            if not allowed:
                return _finish(err(
                    tool=canonical,
                    request_id=request_id,
                    idempotency_key=idempotency_key,
                    timestamp=ts,
                    error_code=ErrorCode.POLICY_BLOCKED,
                    message=reason,
                    details={"tool": canonical},
                    retryable=False,
                ))
            kwargs = sanitized_params

        # Idempotency replay (write/delete tools only)
        if idempotency_key and tool_def is not None and tool_def.safety != ToolSafety.READ:
            from whitemagic.tools.idempotency import get_record
            record = get_record(canonical, str(idempotency_key))
            if record is not None:
                replay = dict(record.response)
                replay["request_id"] = request_id
                replay["timestamp"] = ts
                side_effects_obj = replay.get("side_effects")
                side_effects: dict[str, Any] = dict(side_effects_obj) if isinstance(side_effects_obj, dict) else {}
                side_effects.update(
                    {
                        "idempotency_replay": True,
                        "idempotency_stored_at": record.stored_at,
                    },
                )
                replay["side_effects"] = side_effects
                return _finish(replay)

        # Nervous System pre-dispatch check (circuit breakers, rate limits)
        ns_allowed = True
        ns_reason = ""
        if canonical not in _LIGHTWEIGHT_STATUS_TOOLS:
            ns_allowed, ns_reason = _nervous_system_check(canonical)
            if not ns_allowed:
                return _finish(err(
                    tool=canonical,
                    request_id=request_id,
                    idempotency_key=idempotency_key,
                    timestamp=ts,
                    error_code=ErrorCode.POLICY_BLOCKED,
                    message=ns_reason,
                    details={"tool": canonical, "source": "nervous_system"},
                    retryable=True,
                ))

        # Dispatch to handler.
        try:
            dispatch_kwargs = dict(kwargs)
            if dry_run:
                dispatch_kwargs["dry_run"] = True
            # Zig/StateBoard already validated circuit breaker, rate limit, maturity
            # — tell the middleware pipeline to skip redundant Python checks
            if ns_allowed:
                dispatch_kwargs["_zig_prevalidated"] = True
            if canonical in _LIGHTWEIGHT_STATUS_TOOLS:
                raw = _dispatch_lightweight_tool(canonical, **dispatch_kwargs)
            else:
                raw = _dispatch_tool_with_timeout(canonical, _dispatch_timeout_for_tool(canonical), **dispatch_kwargs)
        except ImportError as exc:
            out = err(
                tool=canonical,
                request_id=request_id,
                idempotency_key=idempotency_key,
                timestamp=ts,
                error_code=ErrorCode.MISSING_DEPENDENCY,
                message=str(exc),
                details={"tool": canonical},
                retryable=False,
            )
        except ToolExecutionError as exc:
            out = err(
                tool=canonical,
                request_id=request_id,
                idempotency_key=idempotency_key,
                timestamp=ts,
                error_code=exc.error_code,
                message=exc.message,
                details=exc.details or {},
                retryable=exc.retryable,
            )
        except Exception as exc:
            out = err(
                tool=canonical,
                request_id=request_id,
                idempotency_key=idempotency_key,
                timestamp=ts,
                error_code=ErrorCode.INTERNAL_ERROR,
                message=str(exc),
                details={"tool": canonical, "traceback": traceback.format_exc() if os.getenv("WM_DEBUG") else None},
                retryable=False,
            )
        else:
            # Normalize into the stable envelope.
            out = normalize_raw(
                tool=canonical,
                request_id=request_id,
                idempotency_key=str(idempotency_key) if idempotency_key else None,
                timestamp=ts,
                raw=raw,
            )

        # Ensure write tools include an explicit writes hint.
        if tool_def is not None and tool_def.safety != ToolSafety.READ and not out.get("writes"):
            out["writes"] = _tool_writes_hint(canonical)

        # Persist idempotency result on success (write/delete only)
        if (
            idempotency_key
            and not dry_run
            and tool_def is not None
            and tool_def.safety != ToolSafety.READ
            and out.get("status") == "success"
        ):
            try:
                from whitemagic.tools.idempotency import put_record
                put_record(canonical, str(idempotency_key), out)
            except Exception:
                # Never fail a tool call due to idempotency persistence.
                pass

        # Nervous System post-dispatch sync
        if (
            canonical not in _LIGHTWEIGHT_STATUS_TOOLS
            and canonical not in _FAST_INTERACTIVE_WRITE_TOOLS
        ):
            _nervous_system_post(
                canonical,
                time.time() - call_started_at,
                out.get("status") in ("success", "ok"),
            )

        return _finish(out)

def smart_infer(query: str, mode: str = "auto", ground_in_memory: bool = False) -> dict:
    """Unified local inference with automatic tier selection.

    Wu Wei principle: Query finds its own path (fast/explore/deep).

    Args:
        query: Query string
        mode: auto/fast/explore/deep/memory_augmented
        ground_in_memory: Use memory for RAG-style context

    Returns:
        dict with answer, tier, confidence, latency_ms, tokens_saved

    """
    return {
        "status": "error",
        "error": "Local inference (edge_infer) has been archived. Please use an external model via MCP.",
    }



def inference_stats() -> dict:
    """Get unified inference statistics."""
    return {
        "status": "error",
        "error": "Local inference (edge_stats) has been archived.",
    }
