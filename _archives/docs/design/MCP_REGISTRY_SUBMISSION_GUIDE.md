# MCP Registry Submission Guide

> How to get WhiteMagic listed on MCP registries so AI agents can discover and install it.

## Overview

MCP (Model Context Protocol) registries are directories where AI agents discover tool servers.
Getting listed is the **#1 distribution channel** for agent-first software.

There are three main registries as of early 2026:

| Registry | URL | Servers Listed | Notes |
|----------|-----|----------------|-------|
| **Official MCP Registry** | https://registry.modelcontextprotocol.io | Growing | Anthropic-backed, highest authority |
| **PulseMCP** | https://pulsemcp.com | 8,245+ | Largest independent directory |
| **Gradually AI** | https://gradually.ai | 1,065+ | Curated, quality-focused |

## Prerequisites

Before submitting, ensure:

1. **`pip install whitemagic[mcp]` works clean** in a fresh venv
2. **`wm doctor` passes** (or at minimum, MCP server starts)
3. **MCP server starts** in all 3 modes:
   ```bash
   WM_MCP_PRAT=1 python -m whitemagic.run_mcp   # 28 Gana tools
   WM_MCP_LITE=1 python -m whitemagic.run_mcp   # ~92 core tools
   python -m whitemagic.run_mcp                   # Full 285 tools
   ```
4. **GitHub repo is public** with README, LICENSE (MIT), and clear install instructions
5. **`llms.txt`** exists at repo root (machine-readable project summary)
6. **`.well-known/agent.json`** exists (A2A Agent Card)
7. **`skill.md`** exists (OpenClaw skill descriptor)

## Step 1: Official MCP Registry

The official registry at `registry.modelcontextprotocol.io` is the most authoritative listing.

### Submission Process

1. **Go to**: https://registry.modelcontextprotocol.io
2. **Check if a submission form or GitHub issue template exists** — the registry is still evolving
3. **If GitHub-based**: Open an issue or PR on the registry's GitHub repo with:
   - **Server name**: `whitemagic`
   - **Description**: "Cognitive scaffolding for AI agents — 285 MCP tools (28 PRAT Ganas), tiered memory, ethical governance, polyglot accelerators"
   - **Install command**: `pip install whitemagic[mcp]`
   - **Launch command**: `WM_MCP_PRAT=1 python -m whitemagic.run_mcp`
   - **Repository URL**: https://github.com/lbailey94/whitemagic
   - **License**: MIT
   - **Categories**: Memory, Governance, Security, Agent Coordination, Introspection
   - **Tool count**: 285 (or 28 in PRAT mode)

### MCP Server Manifest

The registry may require a machine-readable manifest. WhiteMagic's is at:

```
.well-known/agent.json    # A2A Agent Card
mcp-registry.json          # MCP registry metadata (if required)
```

If a specific JSON schema is required, generate it from:

```python
from whitemagic.tools.registry import TOOL_REGISTRY
import json

manifest = {
    "name": "whitemagic",
    "version": "14.4.0",
    "description": "Cognitive scaffolding for AI agents",
    "tools": [
        {"name": t.name, "description": t.description, "category": t.category.value}
        for t in TOOL_REGISTRY.values()
    ],
    "install": "pip install whitemagic[mcp]",
    "launch": "WM_MCP_PRAT=1 python -m whitemagic.run_mcp",
    "license": "MIT",
    "repository": "https://github.com/lbailey94/whitemagic",
}
print(json.dumps(manifest, indent=2))
```

## Step 2: PulseMCP

PulseMCP is the largest independent MCP server directory.

### Submission Process

1. **Go to**: https://pulsemcp.com/submit (or equivalent submission page)
2. **Fill out the listing form** with:
   - **Name**: WhiteMagic
   - **Tagline**: "The Tool Substrate for Agentic AI"
   - **Description**: Full description from README.md
   - **GitHub URL**: https://github.com/lbailey94/whitemagic
   - **Install**: `pip install whitemagic[mcp]`
   - **Categories**: Memory, Governance, Security, Tools, AI
   - **Tags**: mcp, memory, governance, ethical-ai, agent-tools, polyglot
3. **Provide a logo/icon** if available
4. **Include screenshots or demo GIFs** if the submission supports media

### Tips for PulseMCP

- PulseMCP ranks by popularity/stars — encourage early users to star the GitHub repo
- Having a clear, concise README with install-in-one-line is important
- They may feature servers with unique capabilities (governance, ethics are differentiators)

## Step 3: Gradually AI

Gradually AI is a curated directory that emphasizes quality.

### Submission Process

1. **Go to**: https://gradually.ai (check for submission/listing page)
2. **Submit via their process** (typically a form or contact)
3. **Emphasize quality differentiators**:
   - 285 production-ready tools (not a toy/demo)
   - Full test suite (1,200+ tests passing)
   - Ethical governance built-in (unique in MCP ecosystem)
   - 9-language polyglot accelerators
   - MIT licensed, no telemetry by default

## Step 4: PyPI (Package Index)

PyPI is the secondary discovery channel for Python-native agents.

### Publishing to PyPI

```bash
# 1. Clean build
rm -rf dist/ build/ *.egg-info
python -m build --sdist --wheel

# 2. Check the distribution
twine check dist/*

# 3. Upload to Test PyPI first
twine upload --repository testpypi dist/*

# 4. Test install from Test PyPI
pip install --index-url https://test.pypi.org/simple/ whitemagic

# 5. Upload to real PyPI
twine upload dist/*
```

### PyPI Account Setup

1. Create account at https://pypi.org/account/register/
2. Enable 2FA (required for new projects)
3. Create an API token at https://pypi.org/manage/account/token/
4. Configure `~/.pypirc`:
   ```ini
   [pypi]
   username = __token__
   password = pypi-YOUR_API_TOKEN_HERE
   
   [testpypi]
   repository = https://test.pypi.org/legacy/
   username = __token__
   password = pypi-YOUR_TEST_API_TOKEN_HERE
   ```

### PyPI Metadata Checklist

Verify in `pyproject.toml`:
- [ ] `name = "whitemagic"` — check availability on PyPI
- [ ] `version` matches `VERSION` file
- [ ] `description` is compelling and keyword-rich
- [ ] `readme = "README.md"` — renders correctly on PyPI
- [ ] `license = "MIT"`
- [ ] `keywords` include: memory, ai, mcp, agents, governance, tools
- [ ] `classifiers` are accurate and complete
- [ ] `project.urls` all resolve (Homepage, Repository, Docs, Changelog, Issues)
- [ ] `project.scripts` work (`wm`, `whitemagic` CLI entry points)
- [ ] Optional dependencies are documented in README

## Step 5: Additional Discovery Channels

### llms.txt

Already present at repo root. Ensure it's up to date with current tool count and capabilities.
AI agents that crawl GitHub repos look for this file first.

### skill.md (OpenClaw)

Already present at repo root. This is the standard for OpenClaw's skill marketplace.

### .well-known/agent.json (A2A)

Already present. This is the Google A2A protocol's agent discovery mechanism.

### GitHub Topics

Add these topics to the GitHub repo:
- `mcp`
- `mcp-server`
- `ai-agents`
- `memory`
- `governance`
- `ethical-ai`
- `tool-substrate`
- `polyglot`

## Submission Timeline

| Step | When | Time Required |
|------|------|---------------|
| PyPI Test Upload | Before any registry | 30 min |
| PyPI Production Upload | Day 1 | 10 min |
| Official MCP Registry | Day 1 | 1 hour (submission + review) |
| PulseMCP | Day 1–2 | 30 min |
| Gradually AI | Day 2–3 | 30 min |
| GitHub Topics | Day 1 | 5 min |

## Monitoring After Submission

Track adoption via:
- **PyPI download stats**: https://pypistats.org/packages/whitemagic
- **GitHub traffic**: Settings → Traffic
- **MCP Registry analytics**: (if available)
- **WhiteMagic telemetry** (opt-in): `call_tool("get_telemetry_summary")`

## Troubleshooting

### "Package name already taken" on PyPI
- Check https://pypi.org/project/whitemagic/ — if taken, consider `whitemagic-ai` or `whitemagic-mcp`

### Registry rejection
- Ensure README has clear install instructions
- Ensure MCP server actually starts and responds to tool list requests
- Ensure license file is present and OSI-approved

### Agent can't find WhiteMagic after listing
- Verify the MCP server responds to `tools/list` JSON-RPC method
- Check that `python -m whitemagic.run_mcp` exits cleanly on stdio
- Test with `npx @anthropic-ai/mcp-inspector` if available

---

*Last updated: February 2026 — WhiteMagic v14.4.0*
