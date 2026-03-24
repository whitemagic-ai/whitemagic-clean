from whitemagic.core.ganas.base import GanaCall, ResonanceHints, GanaResult
from typing import Any

# Stubs for Gana wrappers
def wrap_gana_call(tool_name: str, **kwargs: Any) -> dict[str, Any]:
    return {"status": "wrapped"}

__all__ = ["wrap_gana_call"]
