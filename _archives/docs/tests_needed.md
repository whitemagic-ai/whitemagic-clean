# WhiteMagic Test Plan

Comprehensive test plan organized by area. Each entry includes test name, what to test, what to mock, and expected behavior. Use `pytest` with `click.testing.CliRunner` for CLI tests.

---

## 1. CLI Commands (~30 tests)

All CLI tests should use `click.testing.CliRunner` and import `main` from `whitemagic.cli_app`.

| Test Name | What to Test | Mock | Expected |
|-----------|-------------|------|----------|
| `test_cli_status` | `wm status` returns system overview | None (reads local state) | Exit code 0, prints version and memory count |
| `test_cli_status_json` | `wm --json status` outputs valid JSON | None | Exit code 0, valid JSON with "status" key |
| `test_cli_health` | `wm health` runs health check | `whitemagic.mcp_api_bridge.check_system_health` | Exit code 0, displays health score |
| `test_cli_health_json` | `wm --json health` outputs JSON | `check_system_health` | Valid JSON with health_score |
| `test_cli_doctor` | `wm doctor` aliases to health | `check_system_health` | Same output as `wm health` |
| `test_cli_stats` | `wm stats` shows memory statistics | `MemoryManager.get_stats` | Exit code 0, prints counts |
| `test_cli_stats_json` | `wm --json stats` outputs JSON | `MemoryManager.get_stats` | Valid JSON with memory counts |
| `test_cli_recall_with_query` | `wm recall "test query"` | `search_memories` handler | Exit code 0, prints results |
| `test_cli_recall_no_query` | `wm recall` with no args | None | Error or usage message |
| `test_cli_remember` | `wm remember "test content"` | `create_memory` handler | Exit code 0, confirms creation |
| `test_cli_scratchpad_create` | `wm scratchpad create "test"` | `ScratchpadManager` | Exit code 0, returns scratchpad ID |
| `test_cli_scratchpad_update` | `wm scratchpad update <id> "content"` | `ScratchpadManager` | Exit code 0 |
| `test_cli_gana_list` | `wm gana list` | `gana_invoke` | Exit code 0, lists 28 ganas |
| `test_cli_gana_invoke` | `wm gana invoke horn status` | `gana_invoke` | Exit code 0, returns gana result |
| `test_cli_dharma` | `wm dharma "situation"` | `get_dharma_guidance` handler | Exit code 0, prints guidance |
| `test_cli_wisdom` | `wm wisdom` shows wisdom report | None | Exit code 0, prints report |
| `test_cli_explore` | `wm explore` shows feature guide | None | Exit code 0, prints tree |
| `test_cli_version` | `wm --version` | None | Prints version string |
| `test_cli_garden_list` | `wm garden list` | `get_all_gardens` | Exit code 0, lists gardens |
| `test_cli_garden_activate` | `wm garden activate zen` | `get_garden` | Exit code 0, confirms activation |
| `test_cli_oracle` | `wm oracle "question"` | I Ching module | Exit code 0, shows hexagram |
| `test_cli_metrics` | `wm metrics` | `get_metrics_summary` | Exit code 0, shows metrics |
| `test_cli_config_show` | `wm config show` | None | Exit code 0, shows config |
| `test_cli_archaeology_scan` | `wm scan .` | Archaeology handler | Exit code 0, shows scan results |
| `test_cli_doctor_deep` | `wm doctor-deep` runs deep audit | Multiple backends | Exit code 0, prints audit |
| `test_cli_kaizen` | `wm kaizen` runs analysis | `kaizen_engine` | Exit code 0, shows proposals |
| `test_cli_sangha_status` | `wm sangha status` | `sangha_lock_list` | Exit code 0, shows lock status |
| `test_cli_init` | `wm init` initializes state dir | Filesystem | Creates state directory |
| `test_cli_export` | `wm export memories` | `MemoryManager` | Exit code 0, exports data |
| `test_cli_invalid_command` | `wm nonexistent` | None | Non-zero exit code |

---

## 2. Dream Daemon (~8 tests)

Test file: `tests/test_dream_daemon.py`. Import from `whitemagic.dream_daemon_v2`.

| Test Name | What to Test | Mock | Expected |
|-----------|-------------|------|----------|
| `test_oracle_phase` | Oracle consultation phase produces hexagram | `whitemagic.intelligence.wisdom.i_ching` | Returns hexagram dict with number, name, guidance |
| `test_heavens_net_phase` | Heaven's Net script execution | `subprocess.run` | Returns parsed JSON from script output |
| `test_julia_resonance_converge` | Julia bridge returns CONVERGED | `subprocess.run` (Julia) | Returns `{"status": "CONVERGED", ...}` |
| `test_julia_resonance_timeout` | Julia bridge falls back on timeout | `subprocess.run` raising `TimeoutExpired` | Returns simulated CONVERGED result |
| `test_dream_synthesis` | Dream synthesis combines phases | Oracle + HN + Julia mocked | Returns synthesis with all phases merged |
| `test_dream_state_async` | `DreamState.enter_dream_state()` is awaitable | Mock internal phases | Completes without RuntimeError |
| `test_daemon_full_cycle` | Full daemon cycle from start to finish | All subprocess calls | Cycle completes < 60s, emits RESONANCE_AMPLIFIED |
| `test_daemon_partial_failure` | Daemon handles one phase failing | One phase raises Exception | Other phases still run, partial result returned |

---

## 3. MCP Server (~6 tests)

Test file: `tests/test_mcp_server.py`. Import from `whitemagic.run_mcp`.

| Test Name | What to Test | Mock | Expected |
|-----------|-------------|------|----------|
| `test_tool_registration` | All tools registered with FastMCP | None | `mcp.list_tools()` returns 60+ tools |
| `test_param_rename_title` | `title` param renamed to avoid Pydantic conflict | None | `create_memory` accepts `memory_title` |
| `test_tool_schema_generation` | Tool schemas have proper JSON schema | None | Each tool has `inputSchema` with `properties` |
| `test_mcp_lifecycle_start` | MCP server starts without error | Transport layer | Server enters running state |
| `test_tool_dispatch_round_trip` | Call a tool through MCP and get result | None | `search_memories` returns dict with `status` |
| `test_gana_tools_registered` | All 28 gana tools appear in tool list | None | 28 tools with `gana_` prefix registered |

---

## 4. Bridges (~8 tests)

Test file: `tests/test_bridges.py`.

| Test Name | What to Test | Mock | Expected |
|-----------|-------------|------|----------|
| `test_julia_bridge_success` | Julia subprocess runs gan_ying.jl | `subprocess.run` returning JSON | Parsed dict with `status: CONVERGED` |
| `test_julia_bridge_timeout` | Julia subprocess times out | `subprocess.run` raising `TimeoutExpired` | Fallback simulated result |
| `test_julia_bridge_missing` | Julia binary not found | `subprocess.run` raising `FileNotFoundError` | Graceful fallback |
| `test_haskell_bridge_ffi` | Haskell FFI call succeeds | `ctypes` or subprocess | Returns valid result |
| `test_haskell_bridge_fallback` | Haskell binary missing, Python fallback | `subprocess.run` raising `FileNotFoundError` | Python implementation used |
| `test_gana_event_loop` | Gana invoke works inside existing event loop | `asyncio.get_running_loop` returning loop | ThreadPoolExecutor workaround fires |
| `test_gana_no_event_loop` | Gana invoke works without event loop | `asyncio.get_running_loop` raising RuntimeError | Direct `asyncio.run` used |
| `test_rust_bridge_status` | Rust bridge reports availability | `whitemagic_rs` import | Returns `{"available": True, "version": ...}` |

---

## 5. Gardens (~12 tests)

Test file: `tests/test_gardens.py`.

| Test Name | What to Test | Mock | Expected |
|-----------|-------------|------|----------|
| `test_garden_activate_zen` | Activate zen garden | None | Garden registered in state |
| `test_garden_activate_chaos` | Activate chaos garden | None | Garden registered |
| `test_garden_activate_invalid` | Activate nonexistent garden | None | Error or default garden |
| `test_garden_status` | List all active gardens | None | Dict of garden names |
| `test_garden_health` | Health check all gardens | None | All gardens report status |
| `test_garden_synergy` | Cross-pollination matrix | `get_resonance_matrix` | Returns resonance stats |
| `test_garden_bias_zen` | Zen garden bias coordinates | None | Returns 4D bias vector |
| `test_garden_bias_chaos` | Chaos garden bias coordinates | None | Different bias than zen |
| `test_cross_pollination_matrix` | Resonance matrix calculations | None | Matrix is symmetric, values 0-1 |
| `test_garden_state_tracker` | State tracker records activations | None | Activation count increments |
| `test_garden_deactivate` | Deactivate a garden | None | Garden removed from active set |
| `test_garden_multi_active` | Multiple gardens active simultaneously | None | All coexist without conflict |

---

## 6. Intelligence (~8 tests)

Test file: `tests/test_intelligence.py`.

| Test Name | What to Test | Mock | Expected |
|-----------|-------------|------|----------|
| `test_holographic_garden_bias` | Garden bias affects holographic indexing | Garden state | Coordinates shifted by bias vector |
| `test_multi_spectral_scratchpad` | Multi-spectral analysis of scratchpad content | None | Returns synthesis, wisdom, confidence |
| `test_i_ching_cast` | I Ching hexagram casting | `random` | Returns hexagram with number 1-64 |
| `test_wu_xing_balance` | Wu Xing phase detection | None | Returns one of 5 phases |
| `test_coherence_metric` | Coherence measurement | None | Returns float 0-1 |
| `test_anti_loop_detection` | Loop detector identifies repeated patterns | Simulate repeated calls | Circuit breaker opens |
| `test_kaizen_analysis` | Kaizen engine finds improvement proposals | Memory data | Returns proposals list |
| `test_serendipity_surface` | Serendipity engine surfaces connections | Memory data | Returns list of related memories |

---

## 7. Core (~10 tests)

Test file: `tests/test_core.py`.

| Test Name | What to Test | Mock | Expected |
|-----------|-------------|------|----------|
| `test_metrics_track` | Track a metric value | None | Metric recorded in store |
| `test_metrics_summary` | Get metrics summary | None | Returns dict with categories |
| `test_sangha_lock_acquire` | Acquire resource lock | None | Lock acquired, returns True |
| `test_sangha_lock_release` | Release resource lock | None | Lock released |
| `test_sangha_lock_conflict` | Two agents lock same resource | None | Second lock fails |
| `test_sangha_chat_send` | Send chat message | None | Message stored |
| `test_sangha_chat_read` | Read chat messages | None | Returns recent messages |
| `test_token_economy_budget` | Token budget tracking | None | Returns budget status dict |
| `test_coherence_report` | Coherence full report | None | Returns level + score + report |
| `test_governor_validate` | Governor validates safe command | None | Returns `safe: True` |

---

## 8. Handler Coverage (~20 tests)

Test file: `tests/test_handlers.py`. Tests for each newly-implemented handler.

| Test Name | What to Test | Mock | Expected |
|-----------|-------------|------|----------|
| `test_handle_immune_scan` | immune_scan returns threat list | `autoimmune.get_immune_system` | Dict with `threats` count, `violations` list |
| `test_handle_immune_heal` | immune_heal triggers auto-heal | `autoimmune.get_immune_system` | Dict with `healed_count` |
| `test_handle_cast_oracle` | cast_oracle returns hexagram | `i_ching.get_i_ching` | Dict with `hexagram`, `name`, `guidance` |
| `test_handle_wu_xing_balance` | wu_xing_balance returns phases | `wu_xing.get_wu_xing` | Dict with `balance`, `current_phase` |
| `test_handle_thought_clone` | thought_clone creates memories | `handle_create_memory` | Dict with `clones_created` count |
| `test_handle_coherence_boost` | coherence_boost returns score | `coherence.get_coherence_metric` | Dict with `coherence_score`, `level` |
| `test_handle_anti_loop_check` | anti_loop_check detects loops | `anti_loop.get_anti_loop` | Dict with `circuit_breaker` OPEN/CLOSED |
| `test_handle_token_report` | token_report returns budget | `token_economy.get_token_economy` | Dict with budget fields |
| `test_handle_grimoire_list` | grimoire_list returns spells | `grimoire_audit.get_auditor` | Dict with `total_spells`, `categories` |
| `test_handle_grimoire_read` | grimoire_read filters by category | `grimoire_audit.get_auditor` | Dict with filtered `spells` list |
| `test_handle_ganying_history` | ganying_history returns events | `gan_ying.get_bus` | Dict with `events` list |
| `test_handle_ganying_listeners` | ganying_listeners returns registry | `gan_ying.get_bus` | Dict with `listeners` map |
| `test_handle_resonance_trace` | resonance_trace filters by time | `gan_ying.get_bus` | Dict with `traced_events` count |
| `test_handle_capability_harness` | capability_harness runs tests | `CapabilityHarness` | Dict with `tests_run`, `passed`, `failed` |
| `test_handle_garden_synergy` | garden_synergy returns matrix | `cross_pollination`, `garden_state` | Dict with `active_gardens`, `resonance_stats` |
| `test_handle_health_report` | health_report aggregates checks | Multiple backends | Dict with all health sections |
| `test_handle_immune_scan_no_threats` | immune_scan with clean dir | Mock returning empty | `threats: 0` |
| `test_handle_cast_oracle_custom_question` | Custom question passed through | I Ching module | Question echoed in response |
| `test_handle_thought_clone_limit` | Clone count capped at 5 | `handle_create_memory` | Max 5 clones even if count=100 |
| `test_handle_grimoire_read_no_filter` | grimoire_read with no category | `grimoire_audit.get_auditor` | Returns all spells (up to 50) |

---

## Test Infrastructure Notes

- **Fixtures**: Create a `conftest.py` with temp state dir, mock DB, and mock memory manager
- **DB**: Use SQLite `:memory:` for test isolation
- **Async**: Use `pytest-asyncio` for async handler tests
- **Imports**: All handlers use lazy imports, so mock at the module level where the import happens
- **State**: Each test should use `tmp_path` fixture to avoid polluting real state at `~/.whitemagic/`
