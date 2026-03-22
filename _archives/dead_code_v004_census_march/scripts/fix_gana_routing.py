#!/usr/bin/env python3
"""Fix Gana Handler Routing Issues

Fixes:
1. community.* tools routed to living_graph (not cognitive_extensions)
2. Missing sangha_chat_read export
3. Missing stub modules
"""

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent))

print("="*80)
print("FIXING GANA HANDLER ROUTING ISSUES")
print("="*80)

fixes_applied = []

# Fix 1: Update dispatch table routing
print("\n1. Updating dispatch table routing...")
dispatch_file = Path(__file__).parent.parent / "whitemagic/tools/dispatch_table.py"

if dispatch_file.exists():
    content = dispatch_file.read_text()
    
    # Check if community.status is incorrectly routed
    if '"community.status": LazyHandler("cognitive_extensions"' in content:
        content = content.replace(
            '"community.status": LazyHandler("cognitive_extensions", "handle_community_status")',
            '"community.status": LazyHandler("living_graph", "handle_community_status")'
        )
        fixes_applied.append("Fixed community.status routing")
    
    if '"community.propagate": LazyHandler("cognitive_extensions"' in content:
        content = content.replace(
            '"community.propagate": LazyHandler("cognitive_extensions", "handle_community_propagate")',
            '"community.propagate": LazyHandler("living_graph", "handle_community_propagate")'
        )
        fixes_applied.append("Fixed community.propagate routing")
    
    if '"community.health": LazyHandler("cognitive_extensions"' in content:
        content = content.replace(
            '"community.health": LazyHandler("cognitive_extensions", "handle_community_health")',
            '"community.health": LazyHandler("living_graph", "handle_community_health")'
        )
        fixes_applied.append("Fixed community.health routing")
    
    dispatch_file.write_text(content)
    print("   ✓ Dispatch table updated")
else:
    print("   ✗ Dispatch table not found")

# Fix 2: Add sangha_chat_read to collaboration.py
print("\n2. Adding sangha_chat_read to collaboration.py...")
collab_file = Path(__file__).parent.parent / "whitemagic/core/bridge/collaboration.py"

if collab_file.exists():
    content = collab_file.read_text()
    
    if "def sangha_chat_read" not in content:
        # Add the function
        sangha_chat_read = '''

def sangha_chat_read(channel: str = "general", limit: int = 10, **kwargs: Any) -> dict[str, Any]:
    """Read messages from Sangha chat."""
    try:
        from whitemagic.gardens.sangha.chat import SanghaChat
        chat = SanghaChat()
        messages = chat.read_messages(channel=channel, limit=limit)
        return {
            "status": "success",
            "messages": [
                {
                    "sender": getattr(m, "sender", None) or getattr(m, "sender_id", None),
                    "content": getattr(m, "content", ""),
                    "time": (m.timestamp.isoformat() if getattr(m, "timestamp", None) else None),
                }
                for m in messages
            ],
            "channel": channel,
            "count": len(messages),
        }
    except Exception as e:
        logger.error(f"Failed to read sangha chat: {e}")
        return {"status": "error", "error": str(e), "messages": [], "count": 0}
'''
        content += sangha_chat_read
        collab_file.write_text(content)
        fixes_applied.append("Added sangha_chat_read function")
        print("   ✓ sangha_chat_read added")
    else:
        print("   ✓ sangha_chat_read already exists")
else:
    print("   ✗ collaboration.py not found")

# Fix 3: Create missing stub modules
print("\n3. Creating missing stub modules...")

# pattern_engine stub
pattern_engine_file = Path(__file__).parent.parent / "whitemagic/core/intelligence/synthesis/pattern_engine.py"
pattern_engine_file.parent.mkdir(parents=True, exist_ok=True)

if not pattern_engine_file.exists():
    pattern_engine_stub = '''"""Pattern Engine - Pattern detection and analysis (stub)."""

import logging
from typing import Any

logger = logging.getLogger(__name__)


class PatternEngine:
    """Pattern detection and analysis engine."""
    
    def detect(self, query: str = "", **kwargs: Any) -> list[dict[str, Any]]:
        """Detect patterns in data."""
        logger.warning("PatternEngine.detect not yet fully implemented")
        return []
    
    def analyze(self, pattern_id: str, **kwargs: Any) -> dict[str, Any]:
        """Analyze a specific pattern."""
        logger.warning("PatternEngine.analyze not yet fully implemented")
        return {"status": "not_implemented", "pattern_id": pattern_id}
'''
    pattern_engine_file.write_text(pattern_engine_stub)
    fixes_applied.append("Created pattern_engine.py stub")
    print("   ✓ pattern_engine.py created")

# graph_engine stub
graph_engine_file = Path(__file__).parent.parent / "whitemagic/core/intelligence/graph_engine.py"
graph_engine_file.parent.mkdir(parents=True, exist_ok=True)

if not graph_engine_file.exists():
    graph_engine_stub = '''"""Graph Engine - Graph topology and analysis (stub)."""

import logging
from typing import Any

logger = logging.getLogger(__name__)


def get_graph_topology(**kwargs: Any) -> dict[str, Any]:
    """Get graph topology information."""
    logger.warning("get_graph_topology not yet fully implemented")
    return {
        "status": "not_implemented",
        "nodes": 0,
        "edges": 0,
        "message": "Graph engine not yet fully implemented"
    }
'''
    graph_engine_file.write_text(graph_engine_stub)
    fixes_applied.append("Created graph_engine.py stub")
    print("   ✓ graph_engine.py created")

# v14_2_handlers stub
v14_2_file = Path(__file__).parent.parent / "whitemagic/tools/handlers/v14_2_handlers.py"

if not v14_2_file.exists():
    v14_2_stub = '''"""v14.2 Handlers - Legacy handler compatibility layer (stub)."""

import logging
from typing import Any

logger = logging.getLogger(__name__)


def handle_legacy_tool(**kwargs: Any) -> dict[str, Any]:
    """Handle legacy v14.2 tool calls."""
    logger.warning("v14.2 handler called but not fully implemented")
    return {
        "status": "not_implemented",
        "message": "This tool requires v14.2 compatibility layer which is not yet implemented"
    }
'''
    v14_2_file.write_text(v14_2_stub)
    fixes_applied.append("Created v14_2_handlers.py stub")
    print("   ✓ v14_2_handlers.py created")

print("\n" + "="*80)
print("FIXES APPLIED")
print("="*80)
for fix in fixes_applied:
    print(f"  ✓ {fix}")

print(f"\nTotal fixes: {len(fixes_applied)}")

sys.exit(0)
