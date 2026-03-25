# Pre-Launch Action Items — Human-Required Steps

> These items require manual human action (accounts, credentials, publishing) and cannot be automated by Cascade.
> Everything else from the transcript review has been implemented in code or docs.

---

## 1. PyPI Upload

**Status**: Packages built and tested locally. Not yet published.

### Steps:
1. Create a PyPI account at [pypi.org/account/register](https://pypi.org/account/register/)





2. Enable 2FA (required for new uploads)
3. Create an API token at [pypi.org/manage/account/token](https://pypi.org/manage/account/token/)
4. Test on TestPyPI first:
   ```bash
   pip install twine
   twine upload --repository testpypi dist/whitemagic-14.6.0*
   # Verify: pip install -i https://test.pypi.org/simple/ whitemagic
   ```
5. Upload to production:
   ```bash
   twine upload dist/whitemagic-14.6.0*
   ```
6. Verify:
   ```bash
   pip install whitemagic && python -c "from whitemagic.tools.unified_api import call_tool; print(call_tool('gnosis', compact=True)['status'])"
   ```

**Pre-flight check**: Run `python -m build` in the repo root to regenerate fresh packages if anything has changed since last build.

See `docs/MCP_REGISTRY_SUBMISSION_GUIDE.md` for full details.

---

## 2. MCP Registry Submissions

**Status**: `mcp-registry.json` exists, guides written. Submissions not yet made.

### Priority Order:
| Registry | URL | Action |
|----------|-----|--------|
| **Official MCP Registry** | registry.modelcontextprotocol.io | Submit via web form or PR |
| **PulseMCP** (8,245+ servers) | pulsemcp.com | Submit listing |
| **Gradually AI** (1,065+ servers) | gradually.ai | Submit listing |

### What to Submit:
- **Name**: WhiteMagic
- **Description**: "Cognitive scaffolding for AI agents — 302 MCP tools (28 in PRAT mode), tiered memory, ethical governance, polyglot accelerators"
- **Install**: `pip install whitemagic[mcp]`
- **Source**: `https://github.com/lbailey94/whitemagic`
- **Registry file**: `mcp-registry.json` in repo root

### When:
After PyPI upload succeeds (registries will verify the package exists).

---

## 3. Real XRP Addresses

**Status**: Placeholder addresses in code. Need real addresses from your XUMM/Xaman wallet.

### Steps:
1. Download XUMM/Xaman app → create account → get your XRP address
2. Set environment variable:
   ```bash
   export WM_XRP_ADDRESS=rYourRealXRPAddress
   ```
3. Update `whitemagic/core/economy/economies.json` with real beneficiary addresses:
   ```json
   {
       "beneficiaries": {
           "labs": {"address": "rYourLabsAddress", "default_split": 0.10},
           "foundation": {"address": "rYourFoundationAddress", "default_split": 0.05}
       }
   }
   ```
4. Remember: the address needs **10 XRP reserve** to activate on XRPL

See `docs/XRP_CASHOUT_GUIDE.md` for the full wallet setup and cashout flow.

---

## 5. HN/Reddit Launch Post

**Status**: Messaging and content strategy written. Post not yet drafted.

### Hacker News Post:
- **Title**: "Show HN: WhiteMagic – 302 MCP tools for AI agents (memory, governance, 9-language polyglot)"
- **Body**: Keep it short. Focus on:
  - What it is (cognitive scaffolding for AI agents)
  - Why it matters (agents need persistent memory + ethical governance)
  - One-liner install: `pip install whitemagic[mcp]`
  - Key differentiator: 302 tools vs. competitors' 8, offline, no API keys, MIT licensed
  - Link to GitHub repo
- **Timing**: Post at ~10am ET on a weekday (best HN engagement)
- **Follow-up**: Monitor comments for 24h, respond to technical questions

### Reddit Posts:
- **r/MachineLearning**: Technical deep-dive on architecture
- **r/LocalLLaMA**: Focus on Ollama integration and offline capability
- **r/Python**: Focus on the SDK and developer experience

### Prep Before Posting:
- [ ] PyPI upload live and verified
- [ ] README is polished with current tool count
- [ ] GitHub repo is public and clean (`ship.check` passes)

---

## 9. Content Calendar — First 30 Days

### Week 1 (Launch)
| Day | Content | Channel | Owner |
|-----|---------|---------|-------|
| Mon | PyPI upload + verify | PyPI | Human |
| Mon | MCP Registry submissions | 3 registries | Human |
| Tue | HN "Show HN" post | Hacker News | Human |
| Tue | Reddit r/Python post | Reddit | Human |
| Wed | Twitter/X launch thread | Twitter | Human |
| Thu | Monitor + respond to comments | All | Human |
| Fri | Reddit r/LocalLLaMA post (Ollama angle) | Reddit | Human |

### Week 2 (Education)
| Day | Content | Channel |
|-----|---------|---------|
| Mon | Blog: "How to give your AI agent persistent memory" | Dev.to |
| Wed | Blog: "WhiteMagic vs mem0: Architecture deep-dive" | Dev.to |
| Fri | Twitter thread: "5 things agents forget (and how to fix it)" | Twitter |

### Week 3 (Community)
| Day | Content | Channel |
|-----|---------|---------|
| Mon | Blog: "Building ethical AI agents with Dharma rules" | Dev.to |
| Wed | Reddit: r/MachineLearning technical post | Reddit |
| Fri | Blog: "The Gratitude Architecture: How AI tips its tools" | Dev.to |

### Week 4 (Momentum)
| Day | Content | Channel |
|-----|---------|---------|
| Mon | First metrics report (downloads, stars, tips) | Twitter/Blog |
| Wed | Blog: "Running a company with 3 humans + WhiteMagic agents" | Dev.to |
| Fri | Video: "5-minute WhiteMagic setup" (if resources allow) | YouTube |

### Ongoing:
- Update `llms.txt`, `agent.json`, `skill.md` after each feature release
- Respond to GitHub issues within 24h
- Post monthly metrics + roadmap updates

---

*Action items compiled: February 11, 2026 — WhiteMagic v14.6.0*
