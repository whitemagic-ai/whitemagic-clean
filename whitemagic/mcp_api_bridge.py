# ruff: noqa: F403

# ============================================================================
# WHITEMAGIC MCP API BRIDGE (FACADE)
# ============================================================================
# This file is now a facade for the modular package `whitemagic.core.bridge`.
# It maintains backward compatibility for existing tools/servers invoking this script.
# ============================================================================

import sys
from typing import Any

from whitemagic.core.bridge.adaptive import *
from whitemagic.core.bridge.agent import *
from whitemagic.core.bridge.archaeology import *
from whitemagic.core.bridge.autonomous import *
from whitemagic.core.bridge.benchmark import *
from whitemagic.core.bridge.collaboration import *
from whitemagic.core.bridge.dharma import *
from whitemagic.core.bridge.gana import *
from whitemagic.core.bridge.gana_wrappers import *
from whitemagic.core.bridge.garden import *
from whitemagic.core.bridge.inference import *
from whitemagic.core.bridge.kaizen import *
from whitemagic.core.bridge.meditation import *
from whitemagic.core.bridge.memory import *
from whitemagic.core.bridge.metrics import *
from whitemagic.core.bridge.optimization import *
from whitemagic.core.bridge.pattern import *
from whitemagic.core.bridge.reasoning import *
from whitemagic.core.bridge.rust import *
from whitemagic.core.bridge.session import *
from whitemagic.core.bridge.system import *

# Import the Main Dispatcher
from whitemagic.core.bridge.tools import execute_mcp_tool
from whitemagic.core.bridge.utils import logger
from whitemagic.core.bridge.voice import *
from whitemagic.core.bridge.wisdom import *

# === IMPORT ALL TOOLS FROM MODULAR BRIDGE ===
from whitemagic.core.bridge.zodiac import *
from whitemagic.utils.fast_json import dumps_str as _json_dumps
from whitemagic.utils.fast_json import loads as _json_loads


def _make_gana_alias(default_tool: str):
    async def _alias(**kwargs: Any) -> dict[str, Any]:
        call_kwargs = dict(kwargs)
        tool_name = call_kwargs.pop("task", default_tool)
        return execute_mcp_tool(tool_name, **call_kwargs)

    return _alias


for _alias_name, _default_tool in {
    # Eastern quadrant
    "gana_horn": "session_init",
    "gana_neck": "memory_create",
    "gana_root": "check_system_health",
    "gana_room": "manage_resource_locks",
    "gana_heart": "session_get_context",
    "gana_tail": "check_acceleration",
    "gana_winnowing_basket": "extract_wisdom",
    # Northern quadrant
    "gana_dipper": "search_memories",
    "gana_ox": "get_system_time",
    "gana_girl": "learn",
    "gana_void": "kaizen",
    "gana_roof": "manage_zodiac",
    "gana_encampment": "check_structure",
    "gana_wall": "check_boundary",
    # Southern quadrant
    "gana_ghost": "track_metric",
    "gana_willow": "adapt_ui",
    "gana_star": "prat_get_context",
    "gana_extended_net": "manage_resonance",
    "gana_wings": "check_status",
    "gana_chariot": "manage_archaeology",
    "gana_abundance": "check_surplus",
    # Western quadrant
    "gana_straddling_legs": "check_balance",
    "gana_mound": "check_storage",
    "gana_stomach": "check_energy",
    "gana_hairy_head": "validate_integrations",
    "gana_net": "detect_patterns",
    "gana_turtle_beak": "validate_command",
    "gana_three_stars": "consult_wisdom_council",
}.items():
    globals()[_alias_name] = _make_gana_alias(_default_tool)

if __name__ == '__main__':
    if len(sys.argv) > 1:
        tool_name = sys.argv[1]
        kwargs = _json_loads(sys.argv[2]) if len(sys.argv) > 2 else {}
        result = execute_mcp_tool(tool_name, **kwargs)
        logger.info(_json_dumps(result, default=str))
