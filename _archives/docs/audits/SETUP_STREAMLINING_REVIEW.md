# Setup Streamlining Review

> Comparison of WhiteMagic's setup experience vs OpenMemory (mem0), with friction points and recommendations.

## Current WhiteMagic Setup Paths

### Path 1: Agent via MCP (Primary)

```bash
pip install whitemagic[mcp]
python -m whitemagic.run_mcp  # or WM_MCP_PRAT=1 python -m whitemagic.run_mcp
```

**Steps to first tool call: 2** (install + launch server)
**Friction**: None — zero config. State auto-creates at `~/.whitemagic/`.

### Path 2: Agent via Python API

```python
pip install whitemagic
from whitemagic.tools.unified_api import call_tool
call_tool("gnosis", compact=True)
```

**Steps to first tool call: 2** (install + import)
**Friction**: None — no API keys needed, no external services required.

### Path 3: Human via CLI

```bash
pip install whitemagic
wm init my-project
cd my-project && python playground.py
```

**Steps to first interaction: 3** (install + init + run)
**Friction**: Moderate — `wm init` is a scaffolding tool, not a system init. The `wm setup` command exists separately. Two init-like commands is confusing.

### Path 4: Human via CLI (Alternative)

```bash
pip install whitemagic
wm setup   # Interactive wizard
wm doctor  # Verify
```

**Steps to first interaction: 3**
**Friction**: `setup` and `init` do different things but sound similar.

## OpenMemory (mem0) Setup Paths

### Path 1: Hosted Platform

```python
pip install mem0ai
from mem0 import MemoryClient
client = MemoryClient(api_key="...")
client.add("I love basketball", user_id="alex")
```

**Steps: 2** (install + API key)
**Friction**: Requires API key signup. External dependency.

### Path 2: Self-hosted Python

```python
pip install mem0ai
export OPENAI_API_KEY=...
from mem0 import Memory
m = Memory()
m.add("I love basketball", user_id="alex")
```

**Steps: 3** (install + API key + code)
**Friction**: **Requires OpenAI API key** — cannot work without external LLM.

### Path 3: OpenMemory MCP Server

```bash
curl -sL https://raw.githubusercontent.com/mem0ai/mem0/main/openmemory/run.sh | bash
npx @openmemory/install
```

**Steps: 2** (curl + configure client)
**Friction**: Requires Docker, OpenAI API key, Node.js for npx.

## Comparison Matrix

| Aspect | WhiteMagic | OpenMemory |
|--------|-----------|------------|
| **Minimum install** | `pip install whitemagic` | `pip install mem0ai` |
| **External API keys needed** | None | OpenAI required |
| **External services needed** | None | Qdrant (vector DB) |
| **Steps to first tool call** | 2 | 3 |
| **Works offline** | Yes | No (needs LLM API) |
| **MCP server launch** | `python -m whitemagic.run_mcp` | Docker + curl script |
| **CLI scaffolding** | `wm init` | None |
| **Health check** | `wm doctor` | None |
| **Auto-fix** | `wm doctor --fix` | None |

## WhiteMagic Advantages

1. **Zero external dependencies** — No API keys, no Docker, no vector DB service
2. **SQLite-native** — Everything works from a single file database
3. **Offline-capable** — Full functionality without internet
4. **Self-diagnosing** — `wm doctor` with auto-fix
5. **Multi-mode MCP** — PRAT/Lite/Full in one binary
6. **285 tools** vs mem0's ~8 memory operations

## Friction Points to Fix

### 1. CRITICAL: Two "init" commands — `wm init` vs `wm setup`

**Problem**: `wm init` scaffolds project files. `wm setup` creates state directories and checks MCP readiness. They overlap in intent.

**Recommendation**: Merge into a single `wm init` that does both:
- If run in empty dir: scaffold files + system init
- If run in existing dir: system init only
- If already initialized: health check + show status

### 2. HIGH: `wm init` seed script path is fragile

The init wizard (in `cli_app.py` line 621) looks for `scripts/seed_quickstart_memories.py` relative to the package. This won't exist in a pip install (scripts aren't packaged).

**Recommendation**: Bundle the seed data as a Python module (e.g., `whitemagic.core.memory.seeds`) and import it directly instead of calling an external script.

### 3. MEDIUM: No single "am I ready?" check for agents

An agent installing WhiteMagic has no quick way to verify everything works. `wm doctor` requires the CLI extra.

**Recommendation**: Add a `call_tool("ship.check")` or make `gnosis` include a `ready: true/false` field.

### 4. LOW: `wm init` project README references wrong GitHub URL

The template in `init_command.py` line 170 references `github.com/whitemagic-labs/whitemagic` but the actual repo is `github.com/lbailey94/whitemagic`.

**Recommendation**: Fix the URL or make it configurable.

### 5. LOW: Debug logging noise on first import

When importing whitemagic in a clean env, 35 DEBUG lines from `registry_defs` print before anything useful happens. These should be suppressed at DEBUG level by default.

**Recommendation**: Set the `whitemagic.tools.registry_defs` logger to INFO by default, or guard with `WM_DEBUG`.

## Recommended Quick Wins

1. **Fix the GitHub URL** in init_command.py template (5 min)
2. **Suppress registry_defs DEBUG noise** by default (5 min)
3. **Add `ready` field to gnosis output** for agent self-check (15 min)
4. **Document the single fastest path** prominently in README:
   ```
   pip install whitemagic && python -c "from whitemagic.tools.unified_api import call_tool; print(call_tool('gnosis', compact=True))"
   ```

---

*Reviewed: February 2026 — WhiteMagic v14.5.0*
