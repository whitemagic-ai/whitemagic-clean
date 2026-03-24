from whitemagic.core.health_monitor import HealthMonitor
from typing import Any

def _get_monitor() -> HealthMonitor:
    return HealthMonitor()

def check_integrations_health(**kwargs: Any) -> dict[str, Any]:
    return _get_monitor().check_integrations_health()

def check_memory_health(**kwargs: Any) -> dict[str, Any]:
    return _get_monitor().check_memory_health()

def check_resonance_health(**kwargs: Any) -> dict[str, Any]:
    return _get_monitor().check_resonance_health()

def check_system_health(**kwargs: Any) -> dict[str, Any]:
    return _get_monitor().check_system_health()

def debug_system(**kwargs: Any) -> dict[str, Any]:
    return {"status": "ok", "debug": "active"}

def system_get_status(**kwargs: Any) -> dict[str, Any]:
    return check_system_health()

def system_initialize_all(**kwargs: Any) -> dict[str, Any]:
    return {"status": "initialized"}

__all__ = [
    "check_integrations_health",
    "check_memory_health",
    "check_resonance_health",
    "check_system_health",
    "debug_system",
    "system_get_status",
    "system_initialize_all",
]
