from typing import Any
import asyncio

def run_autonomous_cycle(*args: Any, **kwargs: Any) -> dict[str, Any]:
    from whitemagic.zodiac.zodiac_round_cycle import get_zodiacal_round
    
    try:
        loop = asyncio.get_event_loop()
    except RuntimeError:
        loop = None

    if loop and loop.is_running():
        # In an existing loop, we can't use asyncio.run
        # This is a shim for bridge/dispatcher
        return {"status": "error", "message": "Async loop already running, call get_zodiacal_round directly"}
    else:
        results = asyncio.run(get_zodiacal_round().run_autonomous_cycle(*args, **kwargs))
        return {"status": "success", "results": [r.to_dict() if hasattr(r, "to_dict") else str(r) for r in results]}

__all__ = ["run_autonomous_cycle"]
