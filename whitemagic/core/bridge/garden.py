from typing import Any

from whitemagic.gardens import get_all_gardens, get_garden, list_gardens
from whitemagic.gardens.garden_resonance import get_garden_resonance_map


def garden_activate(**kwargs: Any) -> dict[str, Any]:
    """Activate a garden through the lazy-loaded gardens package."""
    garden_name = (kwargs.get("garden") or kwargs.get("name") or "").strip().lower()
    if not garden_name:
        return {"status": "error", "error": "garden parameter required"}

    try:
        garden = get_garden(garden_name)
        return {"status": "success", "garden": garden_name, "active": garden is not None}
    except Exception as exc:
        return {"status": "error", "error": str(exc), "active": False}


def garden_garden_activate(**kwargs: Any) -> dict[str, Any]:
    """Legacy compatibility alias for garden_activate."""
    return garden_activate(**kwargs)


def garden_garden_status(**kwargs: Any) -> dict[str, Any]:
    """Return garden inventory/status information."""
    gardens = get_all_gardens()
    return {"status": "success", "count": len(gardens), "gardens": sorted(gardens.keys())}


def garden_list(**kwargs: Any) -> dict[str, Any]:
    """List all available gardens."""
    gardens = list_gardens()
    return {"status": "success", "count": len(gardens), "gardens": gardens}


def garden_resonance_map(**kwargs: Any) -> dict[str, Any]:
    """Expose the garden resonance map."""
    return {"status": "success", "resonance_map": get_garden_resonance_map()}


def manage_gardens(operation: str = "list", **kwargs: Any) -> dict[str, Any]:
    """Legacy router for garden operations."""
    op = (operation or "list").lower()
    if op in {"activate", "garden_activate"}:
        return garden_activate(**kwargs)
    if op in {"status", "garden_status"}:
        return garden_garden_status(**kwargs)
    if op in {"resonance", "resonance_map"}:
        return garden_resonance_map(**kwargs)
    if op in {"list", "garden_list"}:
        return garden_list(**kwargs)
    return {"status": "error", "error": f"Unknown garden operation: {operation}"}


def protect_context(**kwargs: Any) -> dict[str, Any]:
    """Compatibility stub used by the bridge dispatcher."""
    return {"status": "success", "protected": True}


def validate_integrations(**kwargs: Any) -> dict[str, Any]:
    """Compatibility stub used by the bridge dispatcher."""
    return {"status": "success", "valid": True}


__all__ = [
    "garden_activate",
    "garden_garden_activate",
    "garden_garden_status",
    "garden_list",
    "garden_resonance_map",
    "manage_gardens",
    "protect_context",
    "validate_integrations",
]
