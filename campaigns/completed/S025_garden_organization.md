# S025: 28-Garden Organization — MCP Integration & Discoverability

## Objective
Organize all WhiteMagic files, functions, and systems under the 28 Gardens/Lunar Mansions structure, integrating fully with MCP tools to make everything discoverable, accessible, and intuitively navigable.

## Background

### The Problem: Lost in the Garden
WhiteMagic has grown organically across:
- 1,194 Python files
- 1,405 Rust files  
- 674 Elixir files
- 333 Go files
- 756 Mojo files
- 70 Zig files
- 15 Haskell files
- Plus documentation, configs, tests, scripts

**Total: 5,993 files**

Finding the right file, function, or system requires tribal knowledge. The 28-fold garden architecture exists but is **not used for organization** — it's decorative rather than functional.

### The Vision: 28-Fold File System
Every file, function, and system has a "home garden" — a primary garden that "owns" it. This creates:
- **Intuitive navigation**: "I need memory functions → go to wisdom garden"
- **MCP discoverability**: "list tools in joy garden" → relevant MCP tools
- **Semantic organization**: Code organized by purpose, not just type
- **Gana routing**: Operations naturally route to appropriate Gana handler

## Victory Conditions (30 VCs)

### Phase 1: File-to-Garden Mapping (6 VCs)
- [ ] Analyze all Python files: determine primary garden affinity
- [ ] Analyze all Rust files: determine primary garden affinity
- [ ] Create garden_directory registry (file → garden mapping)
- [ ] Tag files with garden metadata (comments, docstrings)
- [ ] Generate garden_ownership report
- [ ] Verify 100% file coverage (no orphans)

### Phase 2: Function-to-Garden Mapping (5 VCs)
- [ ] Extract all public functions from each file
- [ ] Assign primary garden to each function
- [ ] Create function registry with garden metadata
- [ ] Map function dependencies to garden resonance
- [ ] Generate cross-garden function call graph

### Phase 3: System-to-Garden Mapping (5 VCs)
- [ ] Map 7 biological subsystems to gardens
- [ ] Map 28 Ganas to garden implementations
- [ ] Map all MCP tools to gardens
- [ ] Map all CLI commands to gardens
- [ ] Create system_garden_registry.json

### Phase 4: MCP Tool Integration (6 VCs)
- [ ] `garden.list_files(garden_name)` — List files in garden
- [ ] `garden.list_functions(garden_name)` — List functions in garden
- [ ] `garden.search(query, gardens=[])` — Search within gardens
- [ ] `garden.activate(garden_name)` — Activate garden context
- [ ] `garden.resonance(source, target)` — Cross-garden resonance
- [ ] `garden.map_system(system_id)` — Show garden ownership

### Phase 5: Physical Organization (4 VCs)
- [ ] Create garden directory structure (or virtual)
- [ ] Add garden headers to all files
- [ ] Create garden index files (README per garden)
- [ ] Generate garden_dependency_map visualization

### Phase 6: Discoverability Features (4 VCs)
- [ ] Garden-aware code search ("find in joy garden")
- [ ] Garden-aware autocomplete (garden context)
- [ ] Garden dashboard (active gardens, health)
- [ ] Garden CLI (garden-focused command interface)

**Total: 30 VCs**

## Clone Deployment
- 280,000 shadow clones (10K per VC)
- File mapping army: 60K
- Function mapping army: 50K
- System mapping army: 40K
- MCP integration army: 70K
- Organization army: 40K
- Discoverability army: 20K

## Garden Affinity Analysis

### How to Determine "Home Garden"

1. **Resonance Keywords**: File content matches garden resonance keywords
2. **Import Patterns**: What gardens does it import from?
3. **Functional Domain**: Memory → wisdom/joy, Agents → practice/play
4. **Gana Association**: Which Gana would handle this?
5. **Emotional Tone**: Wonder (curiosity), Courage (risk), etc.

### Example Mappings

| File | Primary Garden | Reasoning |
|------|---------------|-----------|
| `core/memory/sqlite_backend.py` | wisdom | Storage, retrieval, knowledge |
| `core/dreaming/dream_cycle.py` | mystery | Unconscious, hidden processes |
| `agents/doctrine.py` | practice | Training, discipline, repetition |
| `grimoire/auto_cast.py` | reverence | Sacred knowledge, spells |
| `cli/cli_app.py` | voice | Command interface, expression |
| `ganas/base.py` | sangha | Community, collective wisdom |
| `resonance/gan_ying*.py` | connection | Event flow, linkage |
| `core/fusions.py` | transformation | Combining, changing |

### Full Mapping Strategy

```python
# whitemagic/core/garden_directory.py
GARDEN_FILE_REGISTRY: dict[str, list[str]] = {
    "wonder": [
        "gardens/wonder/__init__.py",
        "core/intelligence/discovery.py",
        "search/curiosity.py",
        # ... files that embody wonder
    ],
    "wisdom": [
        "core/memory/sqlite_backend.py",
        "core/memory/unified.py",
        "knowledge_graph/builder.py",
        # ... files that embody wisdom
    ],
    # ... all 28 gardens
}

# Reverse lookup: file → gardens (primary + resonant)
FILE_GARDEN_MAP: dict[str, dict] = {
    "core/memory/sqlite_backend.py": {
        "primary": "wisdom",
        "resonant": ["stillness", "sanctuary"],
        "quadrant": "Northern",
        "element": "Water",
    },
    # ... all files
}
```

## MCP Tool Integration

### New MCP Tools

```python
# whitemagic/tools/handlers/garden_directory.py

@tool
def garden_list_files(garden: str, file_type: str = "all") -> dict:
    """List all files belonging to a specific garden.
    
    Args:
        garden: Garden name (e.g., "wisdom", "joy", "practice")
        file_type: Filter by "python", "rust", "config", "all"
    """
    registry = get_garden_registry()
    files = registry.get_files(garden, file_type)
    return {
        "garden": garden,
        "quadrant": registry.get_quadrant(garden),
        "element": registry.get_element(garden),
        "files": files,
        "count": len(files),
    }

@tool
def garden_search(query: str, gardens: list[str] = None) -> dict:
    """Search across files, restricted to specified gardens.
    
    Args:
        query: Search string (function names, concepts)
        gardens: Limit to these gardens (default: all)
    """
    results = []
    for garden in (gardens or ALL_GARDENS):
        garden_results = search_in_garden(query, garden)
        results.extend(garden_results)
    return {"results": results, "by_garden": group_by_garden(results)}

@tool
def garden_activate(garden: str, context: dict = None) -> dict:
    """Activate a garden context for subsequent operations.
    
    Sets the "active garden" which affects:
    - Autocomplete suggestions
    - Search rankings
    - Tool recommendations
    - Resonance calculations
    """
    set_active_garden(garden)
    return {
        "activated": garden,
        "quadrant": get_quadrant(garden),
        "element": get_element(garden),
        "gana": get_gana(garden),
        "available_tools": get_garden_tools(garden),
        "resonant_gardens": get_resonant_gardens(garden),
    }

@tool  
def garden_map_system(system_id: str) -> dict:
    """Show which gardens own/operate a system.
    
    Args:
        system_id: System identifier (e.g., "memory", "dream", "mcp")
    """
    return {
        "system": system_id,
        "primary_garden": get_primary_garden(system_id),
        "operating_gardens": get_operating_gardens(system_id),
        "files": get_system_files(system_id),
        "functions": get_system_functions(system_id),
    }

@tool
def garden_resonance(source: str, target: str) -> dict:
    """Calculate cross-garden resonance strength.
    
    Args:
        source: Source garden name
        target: Target garden name
    """
    return calculate_garden_resonance(source, target)
```

### Tool Registry Integration

```python
# whitemagic/tools/dispatch_table.py additions
"garden.list_files": LazyHandler("garden", "handle_list_files"),
"garden.search": LazyHandler("garden", "handle_search"),
"garden.activate": LazyHandler("garden", "handle_activate"),
"garden.map_system": LazyHandler("garden", "handle_map_system"),
"garden.resonance": LazyHandler("garden", "handle_resonance"),
"garden.list_functions": LazyHandler("garden", "handle_list_functions"),
"garden.depends": LazyHandler("garden", "handle_dependencies"),
```

## Physical Organization Options

### Option A: Virtual Organization (Recommended)
- Files stay in current locations
- Garden metadata in registry files
- No file moves (preserves git history)
- Flexible, non-disruptive

### Option B: Directory Restructure
```
whitemagic/
├── eastern/  # Azure Dragon, Wood
│   ├── wonder/
│   ├── stillness/
│   └── ...
├── southern/  # Vermilion Bird, Fire
├── western/   # White Tiger, Metal
└── northern/  # Black Tortoise, Water
```
- Files move to garden directories
- Clear physical organization
- Disruptive to git history
- Requires extensive imports update

**Recommendation**: Option A (virtual) for now, Option B as future goal.

## Discoverability Features

### Garden Headers
```python
# Added to top of every file
"""
🌸 GARDEN: wisdom
🌗 GANA: Winnowing Basket (Ji)
🧭 QUADRANT: Eastern (Azure Dragon)
🔥 ELEMENT: Wood
📝 PURPOSE: Memory storage and retrieval operations
🌿 RESONANT: stillness, sanctuary, healing
"""
```

### Garden Index Files
```markdown
# whitemagic/gardens/wisdom/README.md
# 🌸 Wisdom Garden

**Gana**: Winnowing Basket (Ji)
**Quadrant**: Eastern (Azure Dragon)
**Element**: Wood
**Emotion**: Understanding, insight

## Files in This Garden
- `core/memory/sqlite_backend.py` — Database operations
- `core/memory/unified.py` — Unified memory interface
- `knowledge_graph/builder.py` — Knowledge graph construction

## Key Functions
- `store_memory()` — Store with wisdom bias
- `retrieve_wise()` — Retrieve with insight ranking
- `consolidate_knowledge()` — Merge related memories

## Resonant Gardens
- stillness (deep contemplation)
- sanctuary (safe knowledge storage)
- healing (wisdom as medicine)

## MCP Tools
- `garden.activate("wisdom")` — Set wisdom context
- `garden.list_functions("wisdom")` — List all functions
```

### Garden Dashboard
```
┌─────────────────────────────────────────────────────────────┐
│  🌸 WHITEMAGIC GARDEN DASHBOARD                             │
├─────────────────────────────────────────────────────────────┤
│  ACTIVE: wisdom (Eastern, Wood)                             │
│  RESONANCE: 0.87 with stillness, 0.72 with sanctuary        │
├─────────────────────────────────────────────────────────────┤
│  GARDEN HEALTH                                              │
│  wonder     ████████░░ 80%  joy         ██████░░░░ 60%      │
│  wisdom     █████████░ 90%  sangha      ████████░░ 85%      │
│  practice   ███████░░░ 70%  grief       ██████░░░░ 60%      │
├─────────────────────────────────────────────────────────────┤
│  RECENT ACTIVITY                                            │
│  wisdom: 42 memory operations                               │
│  voice: 12 command executions                               │
│  connection: 8 event broadcasts                             │
└─────────────────────────────────────────────────────────────┘
```

## Success Criteria
- 100% = All 5,993 files mapped, MCP tools operational, dashboard live
- 90%+ = All Python files mapped, core MCP tools working
- 75%+ = 80% files mapped, basic MCP tools functional
- <75% = Mapping incomplete, needs continuation

## Report Location
- Campaign: `campaigns/S025_garden_organization.md`
- Registry: `whitemagic/core/garden_directory.py`
- Mapping data: `data/garden_file_registry.json`
- MCP docs: `docs/GARDEN_MCP_TOOLS.md`
- Dashboard: `docs/GARDEN_DASHBOARD.md`

## Dependencies
- S020 (file census data)
- S023 (garden consolidation - 28-fold structure finalized)
- S024 (ResonanceConductor - for garden-aware orchestration)

## Timeline Estimate
- Phase 1: 2 sessions (file mapping)
- Phase 2: 2 sessions (function mapping)
- Phase 3: 1 session (system mapping)
- Phase 4: 2 sessions (MCP tools)
- Phase 5: 1 session (organization)
- Phase 6: 1 session (discoverability)

**Total: 9 sessions for 100% completion**

## Next Session
Begin Phase 1: File-to-Garden Mapping
1. Analyze all Python files for garden affinity
2. Create initial garden_directory registry
3. Tag high-priority files with garden metadata

---
Created: 2026-02-21
Status: PLANNED
Progress: 0/30 VCs
