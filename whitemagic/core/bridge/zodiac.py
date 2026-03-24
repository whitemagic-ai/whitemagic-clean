from __future__ import annotations

import asyncio
from typing import Any

from whitemagic.zodiac import get_zodiac_council, get_zodiacal_round
from whitemagic.zodiac.zodiac_cores import CoreResponse, get_zodiac_cores


def _serialize_response(response: CoreResponse | None) -> dict[str, Any]:
    if response is None:
        return {"status": "error", "error": "Unknown zodiac core"}
    return {
        "core_name": response.core_name,
        "processing_result": response.processing_result,
        "wisdom": response.wisdom,
        "resonance": response.resonance,
        "transformation_applied": response.transformation_applied,
        "timestamp": response.timestamp.isoformat(),
    }


def zodiac_list_cores(**kwargs: Any) -> dict[str, Any]:
    """List available zodiac cores."""
    cores = get_zodiac_cores().get_all_cores()
    return {"status": "success", "cores": list(cores.keys()), "count": len(cores)}


def zodiac_activate_core(core_name: str | None = None, context: dict[str, Any] | None = None, **kwargs: Any) -> dict[str, Any]:
    """Activate a zodiac core."""
    name = core_name or kwargs.get("name") or kwargs.get("core")
    if not name:
        return {"status": "error", "error": "core_name required"}

    response = get_zodiac_cores().activate_core(name, context or kwargs.get("context", {}) or {})
    if response is None:
        return {"status": "error", "error": f"Unknown zodiac core: {name}"}

    return {"status": "success", "core": name, "response": _serialize_response(response)}


def zodiac_consult_council(**kwargs: Any) -> dict[str, Any]:
    """Consult the zodiac council."""
    try:
        council = get_zodiac_council()
        if hasattr(council, "to_dict"):
            council_data = council.to_dict()
        else:
            council_data = council
        return {"status": "success", "council": council_data}
    except Exception as exc:
        return {"status": "error", "error": str(exc)}


def zodiac_run_cycle(num_cycles: int = 1, **kwargs: Any) -> dict[str, Any]:
    """Run the autonomous zodiac cycle."""
    round_cycle = get_zodiacal_round()

    async def _run() -> list[Any]:
        return await round_cycle.run_autonomous_cycle(num_cycles=num_cycles)

    try:
        try:
            loop = asyncio.get_running_loop()
        except RuntimeError:
            loop = None

        if loop and loop.is_running():
            import concurrent.futures

            with concurrent.futures.ThreadPoolExecutor() as executor:
                future = executor.submit(asyncio.run, _run())
                responses = future.result(timeout=60)
        else:
            responses = asyncio.run(_run())

        return {
            "status": "success",
            "cycles": num_cycles,
            "responses": [
                {
                    "core_name": response.core_name,
                    "wisdom": response.wisdom,
                    "resonance": response.resonance,
                    "transformation_applied": response.transformation_applied,
                }
                for response in responses
            ],
            "count": len(responses),
        }
    except Exception as exc:
        return {"status": "error", "error": str(exc)}


def manage_zodiac_cores(operation: str = "list", **kwargs: Any) -> dict[str, Any]:
    """Legacy router for zodiac operations."""
    op = (operation or "list").lower()
    if op in {"list", "list_cores"}:
        return zodiac_list_cores(**kwargs)
    if op in {"activate", "activate_core"}:
        return zodiac_activate_core(**kwargs)
    if op in {"consult", "council"}:
        return zodiac_consult_council(**kwargs)
    if op in {"run", "run_cycle"}:
        return zodiac_run_cycle(**kwargs)
    return {"status": "error", "error": f"Unknown zodiac operation: {operation}"}


__all__ = [
    "manage_zodiac_cores",
    "zodiac_activate_core",
    "zodiac_consult_council",
    "zodiac_list_cores",
    "zodiac_run_cycle",
]
