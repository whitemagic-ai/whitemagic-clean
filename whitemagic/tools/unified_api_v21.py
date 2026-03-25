"""Unified API V21 - Enhanced with Willow Health Checks.

This is the V21 version of unified_api.py with integrated Willow health checks,
circuit breaker validation, and improved error handling.
"""

import asyncio
import logging
from typing import Any, Dict

from .willow_health_check import willow_pre_check, get_willow_health_checker

logger = logging.getLogger(__name__)

# V21 Enhanced timeout configuration with Willow health integration
TIMEOUT_CONFIG_V21 = {
    # Horn (gana_horn)
    "session_bootstrap": 20, "create_session": 15, "resume_session": 20, "checkpoint_session": 30,
    "session_handoff_transfer": 15, "session_list_handoffs": 10, "session_accept_handoff": 15,
    "session_status": 10, "focus_session": 15,

    # Dipper (gana_dipper) - Extended timeouts for stability
    "homeostasis": 60, "homeostasis_check": 60, "homeostasis_status": 30, "maturity_assess": 60,
    "starter_packs": 30, "starter_packs_list": 20, "starter_packs_get": 20, "starter_packs_suggest": 45,
    "cognitive_set": 30, "cognitive_mode": 25, "cognitive_stats": 25, "cognitive_hints": 30,
    "doctrine_stratagems": 45, "doctrine_summary": 35, "doctrine_force": 45,

    # Willow (gana_willow) - V21: Health-checked timeouts
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
}

# Willow tools that require health checks
WILLOW_TOOLS = {
    "cast_oracle", "grimoire_list", "grimoire_read", "grimoire_suggest",
    "grimoire_recommend", "grimoire_cast", "grimoire_walkthrough",
    "rate_limiter_stats", "fool_guard_status", "fool_guard_ralph",
    "fool_guard_dare_to_die", "grimoire_auto_status"
}

async def execute_tool_v21(tool_name: str, **kwargs: Any) -> Dict[str, Any]:
    """V21 enhanced tool execution with Willow health checks."""
    
    # Check if this is a Willow tool
    if tool_name in WILLOW_TOOLS:
        # Perform pre-check
        healthy = await willow_pre_check(tool_name)
        if not healthy:
            return {
                "status": "error",
                "error": "Willow subsystem unhealthy - operation blocked",
                "recovery_available": True,
                "suggestion": "Try again in 30 seconds or run willow_health_check"
            }
    
    # Get timeout
    timeout = TIMEOUT_CONFIG_V21.get(tool_name, 30)
    
    try:
        # Execute with timeout
        if asyncio.iscoroutinefunction(_execute_tool_internal):
            result = await asyncio.wait_for(
                _execute_tool_internal(tool_name, **kwargs),
                timeout=timeout
            )
        else:
            result = await asyncio.wait_for(
                asyncio.to_thread(_execute_tool_internal, tool_name, **kwargs),
                timeout=timeout
            )
            
        return result
        
    except asyncio.TimeoutError:
        logger.warning(f"⏰ Tool {tool_name} timed out after {timeout}s")
        
        # For Willow tools, trigger health check on timeout
        if tool_name in WILLOW_TOOLS:
            checker = get_willow_health_checker()
            await checker.check_willow_health(force=True)
            
        return {
            "status": "error",
            "error": f"Tool {tool_name} timed out after {timeout} seconds",
            "timeout": timeout
        }
    except Exception as e:
        logger.error(f"❌ Tool {tool_name} failed: {e}")
        return {
            "status": "error", 
            "error": str(e)
        }

def _execute_tool_internal(tool_name: str, **kwargs: Any) -> Dict[str, Any]:
    """Internal tool execution - same as original unified_api."""
    # Import the handler mapping
    from .prat_router import get_gana_for_tool
    
    gana_name = get_gana_for_tool(tool_name)
    if not gana_name:
        return {"status": "error", "error": f"Unknown tool: {tool_name}"}
    
    # Try Koka first for certain ganas
    if gana_name in ["gana_willow", "gana_ghost", "gana_winnowing_basket"]:
        try:
            from .prat_router import _try_koka_handler
            koka_result = _try_koka_handler(gana_name, tool_name, kwargs)
            if koka_result:
                return koka_result
        except Exception as e:
            logger.debug(f"Koka handler failed for {tool_name}: {e}")
    
    # Fall back to Python handler
    try:
        handler_module_name = f".handlers.{gana_name.replace('gana_', '')}"
        handler_module = __import__(handler_module_name, fromlist=[''])
        handler_name = f"handle_{tool_name.replace('.', '_')}"
        handler = getattr(handler_module, handler_name)
        
        if asyncio.iscoroutinefunction(handler):
            # This shouldn't happen with sync wrapper, but just in case
            return asyncio.run(handler(**kwargs))
        else:
            return handler(**kwargs)
            
    except (ImportError, AttributeError) as e:
        return {"status": "error", "error": f"Handler not found for {tool_name}: {e}"}
    except Exception as e:
        return {"status": "error", "error": f"Handler execution failed for {tool_name}: {e}"}

# Health check endpoint
async def willow_health_check_endpoint() -> Dict[str, Any]:
    """Public endpoint for Willow health status."""
    checker = get_willow_health_checker()
    health = await checker.check_willow_health()
    recommendations = await checker.get_willow_recommendations()
    
    return {
        "status": "success",
        "health": {
            "is_healthy": health.is_healthy,
            "circuit_breaker_ok": health.circuit_breaker_ok,
            "koka_responsive": health.koka_responsive,
            "error_count": health.error_count,
            "issues": health.issues
        },
        "recommendations": recommendations,
        "last_check": health.last_check
    }

# Recovery endpoint
async def willow_recovery_endpoint() -> Dict[str, Any]:
    """Public endpoint for Willow recovery."""
    checker = get_willow_health_checker()
    recovered = await checker.attempt_recovery()
    
    return {
        "status": "success",
        "recovered": recovered,
        "recovery_attempts": checker._recovery_attempts
    }

# V21 API exports
__all__ = [
    "execute_tool_v21",
    "willow_health_check_endpoint", 
    "willow_recovery_endpoint",
    "TIMEOUT_CONFIG_V21",
    "WILLOW_TOOLS"
]
