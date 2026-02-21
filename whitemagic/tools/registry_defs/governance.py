"""Governance Tools Registry — Sabha Council & Forge Management
===========================================================

Registry definitions for governance-related MCP tools:
- Sabha council convening and status
- Forge validation, reloading, and status
"""

from whitemagic.tools.tool_types import ToolCategory, ToolDefinition, ToolSafety

#: Sabha Council Tools
SABHA_TOOLS = [
    ToolDefinition(
        name="sabha.convene",
        description="Convene the full Zodiac Council (Sabha) for deliberation on complex tasks",
        category=ToolCategory.GOVERNANCE,
        safety=ToolSafety.READ,
        input_schema={
            "type": "object",
            "properties": {
                "task": {
                    "type": "string",
                    "description": "The complex task requiring council deliberation"
                },
                "ganas": {
                    "type": "array",
                    "items": {"type": "string"},
                    "description": "Optional specific Ganas to convene (defaults to all 28)"
                }
            },
            "required": ["task"]
        },
        gana="gana_star",
        garden="Truth",
        quadrant="East",
        element="Metal"
    ),
    ToolDefinition(
        name="sabha.status",
        description="Get current status of the Zodiac Council and recent deliberations",
        category=ToolCategory.GOVERNANCE,
        safety=ToolSafety.READ,
        input_schema={
            "type": "object",
            "properties": {}
        },
        gana="gana_star",
        garden="Truth",
        quadrant="East",
        element="Metal"
    ),
]

#: Forge Management Tools
FORGE_TOOLS = [
    ToolDefinition(
        name="forge.status",
        description="Get current status of the Forge (tool compilation system)",
        category=ToolCategory.GOVERNANCE,
        safety=ToolSafety.READ,
        input_schema={
            "type": "object",
            "properties": {}
        },
        gana="gana_star",
        garden="Metal",
        quadrant="West",
        element="Metal"
    ),
    ToolDefinition(
        name="forge.reload",
        description="Reload the Forge and re-scan for available tools",
        category=ToolCategory.GOVERNANCE,
        safety=ToolSafety.WRITE,
        input_schema={
            "type": "object",
            "properties": {
                "domain": {
                    "type": "string",
                    "description": "Optional specific domain to reload (e.g., 'gana')"
                }
            }
        },
        gana="gana_star",
        garden="Metal",
        quadrant="West",
        element="Metal"
    ),
    ToolDefinition(
        name="forge.validate",
        description="Validate a tool manifest without loading it",
        category=ToolCategory.GOVERNANCE,
        safety=ToolSafety.READ,
        input_schema={
            "type": "object",
            "properties": {
                "manifest_path": {
                    "type": "string",
                    "description": "Path to the tool manifest JSON file"
                }
            },
            "required": ["manifest_path"]
        },
        gana="gana_star",
        garden="Metal",
        quadrant="West",
        element="Metal"
    ),
]

#: All Governance Tools
TOOLS = SABHA_TOOLS + FORGE_TOOLS
