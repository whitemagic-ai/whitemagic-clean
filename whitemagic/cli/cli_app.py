#!/usr/bin/env python3
# mypy: disable-error-code=no-untyped-def
"""WhiteMagic CLI - Complete Implementation
Phase 1: Core Commands for Production Readiness
"""
import logging
import os
import sys

from whitemagic.utils.fast_json import dumps_str as _json_dumps
from datetime import datetime
from importlib.util import find_spec
from pathlib import Path
from typing import Any

import click

logger = logging.getLogger(__name__)

try:
    from whitemagic import __version__
except ImportError:
    __version__ = "unknown"

if __name__ == "__main__" and __package__ is None:
    sys.path.insert(0, str(Path(__file__).resolve().parent.parent))

def _bootstrap_env_from_argv(argv: list[str]) -> None:
    """Bootstrap environment variables from CLI flags *before* importing Whitemagic
    modules that compute state paths at import time.

    This keeps `--state-root`/`--base-dir` and `--silent-init` effective even when
    running as an installed console script (module import happens before Click
    parses options).
    """

    def _extract_value(flag: str) -> str | None:
        for i, arg in enumerate(argv):
            if arg == flag and i + 1 < len(argv):
                return argv[i + 1]
            if arg.startswith(flag + "="):
                return arg.split("=", 1)[1]
        return None

    state_root = _extract_value("--state-root") or _extract_value("--base-dir")
    if state_root:
        # CLI flag should win for this process.
        os.environ["WM_STATE_ROOT"] = state_root

    db_path = _extract_value("--db-path")
    if db_path:
        # CLI flag should win for this process.
        os.environ["WM_DB_PATH"] = db_path

    if "--silent-init" in argv or "--json" in argv:
        os.environ["WM_SILENT_INIT"] = "1"


_bootstrap_env_from_argv(sys.argv)

# Import Rich for beautiful CLI output
try:
    from rich.console import Console
    from rich.panel import Panel
    from rich.table import Table
    from rich.tree import Tree
    HAS_RICH = True
    console = Console()
except ImportError:
    HAS_RICH = False
    console = None  # type: ignore[assignment]

# Optional feature flags
HAS_VOICE = False
HAS_GRAPH = False
HAS_EXEC = False

# Import WhiteMagic modules
try:
    from whitemagic.core.memory.unified import get_unified_memory
    HAS_CORE = True
except ImportError:
    # We delay the error message until we actually need core
    HAS_CORE = False

# Plugin system
try:
    from whitemagic.plugins import load_plugins, register_commands
    HAS_PLUGINS = True
except ImportError:
    HAS_PLUGINS = False

try:
    from whitemagic.cli.cli_commands_gardens import gardens
    from whitemagic.cli.cli_commands_intelligence import intelligence
    from whitemagic.cli.cli_commands_symbolic import iching, wuxing
    HAS_EXTENSIONS = True
except ImportError:
    HAS_EXTENSIONS = False

# Reasoning CLI commands (v4.10.0 - Multi-Spectral Reasoning)
try:
    from whitemagic.cli.cli_reasoning import reasoning  # type: ignore[import-not-found]
    HAS_REASONING = True
except ImportError:
    HAS_REASONING = False

# Inference CLI commands (v4.11.0 - Unified Inference)
try:
    from whitemagic.cli.infer_commands import infer  # type: ignore[import-not-found]
    HAS_INFERENCE = True
except ImportError:
    HAS_INFERENCE = False

# Hardware CLI commands (v4.11.0 - Hardware Awareness)
try:
    from whitemagic.cli.hardware_commands import hardware  # type: ignore[import-not-found]
    HAS_HARDWARE_CLI = True
except ImportError:
    HAS_HARDWARE_CLI = False

# Rust CLI commands (v4.9.0)
try:
    from whitemagic.cli.cli_rust import register_rust_commands
    HAS_RUST_CLI = True
except ImportError:
    HAS_RUST_CLI = False

try:
    from whitemagic.cli.cli_archaeology import archaeology, windsurf
    HAS_ARCHAEOLOGY = True
except ImportError:
    HAS_ARCHAEOLOGY = False

try:
    from whitemagic.cli.cli_watcher import watch
    HAS_WATCHER = True
except ImportError:
    HAS_WATCHER = False

try:
    from whitemagic.cli.cli_autonomous_execution import autonomous
    HAS_AUTONOMOUS = True
except ImportError:
    HAS_AUTONOMOUS = False

try:
    from whitemagic.cli.cli_sangha import sangha_cli
    HAS_SANGHA = True
except ImportError:
    HAS_SANGHA = False

try:
    from whitemagic.cli.cli_local import local_cli  # type: ignore[attr-defined]
    HAS_LOCAL = True
except ImportError:
    HAS_LOCAL = False

# Scratchpad CLI (v5.2.0 - Phase 26)
try:
    from whitemagic.cli.cli_scratchpad import scratch
    HAS_SCRATCH = True
except ImportError:
    HAS_SCRATCH = False

# New CLI Commands (Phase 27 - Infrastructure)
try:
    from whitemagic.cli.cli_commands_optimization import optimization_cli
    from whitemagic.cli.cli_commands_thought import thought_cli
    from whitemagic.cli.cli_commands_supervisor import supervisor_cli
    from whitemagic.cli.cli_commands_phase import phase_cli
    HAS_NEW_INFRA = True
except ImportError:
    HAS_NEW_INFRA = False

@click.group()
@click.version_option(version=__version__)
@click.option(
    "--state-root",
    help="Override WM_STATE_ROOT for this run (recommended for tests/containers).",
)
@click.option(
    "--base-dir",
    help="(Deprecated) Alias for --state-root.",
)
@click.option(
    "--db-path",
    help="Override WM_DB_PATH for this run (SQLite DB file path).",
)
@click.option("--json", "json_output", is_flag=True, help="Emit full tool envelopes as JSON (AI-friendly).")
@click.option("--now", help="ISO timestamp override for deterministic tool runs.")
@click.option("--silent-init", is_flag=True, help="Set WM_SILENT_INIT=1 to suppress noisy initialization logs.")
@click.pass_context
def main(
    ctx,
    state_root: str | None,
    base_dir: str | None,
    db_path: str | None,
    json_output: bool,
    now: str | None,
    silent_init: bool,
):
    """WhiteMagic CLI - AI Memory & Context Management"""
    effective_state_root = state_root or base_dir

    if json_output or silent_init:
        os.environ.setdefault("WM_SILENT_INIT", "1")

    # NOTE: WM_STATE_ROOT is resolved at import time in whitemagic.config.paths.
    # cli_app bootstraps WM_STATE_ROOT from argv early, so this flag is effective
    # for the current process, and we also propagate it for subprocesses.
    if effective_state_root:
        os.environ.setdefault("WM_STATE_ROOT", effective_state_root)
    if db_path:
        os.environ.setdefault("WM_DB_PATH", db_path)

    ctx.ensure_object(dict)
    ctx.obj["state_root"] = effective_state_root
    ctx.obj["json_output"] = bool(json_output)
    ctx.obj["now"] = now

    # Non-blocking update check (cached 24h, opt-out via WM_NO_UPDATE_CHECK=1)
    if not json_output:
        try:
            from whitemagic.core.update_checker import check_for_update
            update_msg = check_for_update()
            if update_msg:
                click.echo(update_msg, err=True)
        except Exception:
            pass

# --- Enhanced Commands (Rich Enabled) --- (PSR-028: status/health/doctor extracted to cli/commands/diagnostics_commands.py)
from whitemagic.cli.commands.diagnostics_commands import register_diagnostics_commands, status_command  # noqa: E402
register_diagnostics_commands(main)


@main.command(name="explore")
def explore_command() -> None:
    """Interactive guide to WhiteMagic features"""
    if HAS_RICH and console:
        console.print("\n[bold cyan]🧭 WhiteMagic Explorer[/bold cyan]\n")

        tree = Tree(f"🪄 WhiteMagic v{__version__}")

        gana_branch = tree.add("[cyan]🌙 28 Lunar Mansion Ganas[/cyan]")
        gana_branch.add("wm gana list - View all Ganas by quadrant")
        gana_branch.add("wm gana invoke <tool> - Invoke tool through Gana")
        gana_branch.add("wm gana status - System status")

        dharma_branch = tree.add("[yellow]☸️  Dharma Ethical System[/yellow]")
        dharma_branch.add("wm dharma evaluate <action> - Check ethics")
        dharma_branch.add("wm dharma principles - List principles")
        dharma_branch.add("wm dharma check-boundaries <action> - Check boundaries")

        ml_branch = tree.add("[green]🤖 Local ML Inference[/green]")
        ml_branch.add("wm infer local-query <prompt> - Run local inference")
        ml_branch.add("wm infer local-status - Engine status")

        wisdom_branch = tree.add("[magenta]🧙 Wisdom Systems[/magenta]")
        wisdom_branch.add("wm wisdom consult <question> - Ask wisdom council")
        wisdom_branch.add("wm wisdom iching <question> - Ask I Ching")

        system_branch = tree.add("[blue]🔧 System Commands[/blue]")
        system_branch.add("wm status - Overall status")
        system_branch.add("wm health - Health check")
        system_branch.add("wm start-session - Start session orchestrator")

        console.print(tree)
        console.print("\n[dim]Use --help on any command for more details[/dim]\n")
    else:
        click.echo("WhiteMagic Explorer - Interactive guide (Rich required for full experience)")

@main.command(name="galaxy")
def galaxy_command() -> None:
    """Launch the Galaxy TUI (Visual Memory Browser)"""
    try:
        from whitemagic.interfaces.tui import GalaxyTUI
        # Run the TUI
        app = GalaxyTUI()
        app.run()
    except ImportError as e:
        click.echo(f"❌ Error: TUI dependencies missing. Install with 'pip install whitemagic[tui]' ({e})")
    except Exception as e:
        click.echo(f"❌ Error launching Galaxy: {e}")


@main.command(name="init")
@click.option("--galaxy", default="default", help="Name for the default galaxy")
@click.option("--skip-seed", is_flag=True, help="Skip seeding quickstart memories")
@click.option("--skip-ollama", is_flag=True, help="Skip Ollama detection")
@click.pass_context
def init_command(ctx, galaxy: str, skip_seed: bool, skip_ollama: bool) -> None:
    """🧙 First-time setup wizard for WhiteMagic.

    Creates state directory, seeds quickstart memories, detects Ollama,
    and runs a health check.
    """
    import shutil

    from whitemagic.config import paths as cfg_paths

    _echo = click.echo

    def _ok(msg: str) -> None:
        _echo(f"  ✅ {msg}")

    def _skip(msg: str) -> None:
        _echo(f"  ⏭️  {msg}")

    def _fail(msg: str) -> None:
        _echo(f"  ❌ {msg}")

    _echo(f"\n🧙 WhiteMagic Init Wizard (v{__version__})\n")

    # Step 1: Ensure state directory
    _echo("Step 1/5: State directory")
    state_root = cfg_paths.get_state_root()  # type: ignore[attr-defined]
    state_root.mkdir(parents=True, exist_ok=True)
    _ok(f"WM_STATE_ROOT = {state_root}")

    # Step 2: Create default galaxy
    _echo("Step 2/5: Default galaxy")
    try:
        from whitemagic.core.memory.galaxy_manager import get_galaxy_manager
        gm = get_galaxy_manager()
        existing = gm.list_galaxies()
        if any(g.get("name") == galaxy for g in existing):
            _ok(f"Galaxy '{galaxy}' already exists")
        else:
            gm.create_galaxy(galaxy)
            _ok(f"Galaxy '{galaxy}' created")
    except Exception as e:
        _fail(f"Galaxy setup: {e}")

    # Step 3: Seed quickstart memories
    _echo("Step 3/5: Quickstart memories")
    if skip_seed:
        _skip("Skipped (--skip-seed)")
    else:
        try:
            from whitemagic.core.memory.unified import get_unified_memory
            um = get_unified_memory()
            existing_count = len(um.search(tags={"quickstart"}, limit=1))
            if existing_count > 0:
                _ok("Quickstart memories already present")
            else:
                import subprocess
                import sys
                seed_script = Path(__file__).resolve().parent.parent.parent / "scripts" / "seed_quickstart_memories.py"
                if seed_script.exists():
                    subprocess.run([sys.executable, str(seed_script)], check=True, capture_output=True)
                    _ok("Quickstart memories seeded")
                else:
                    _skip("Seed script not found (run from git checkout)")
        except Exception as e:
            _fail(f"Seed: {e}")

    # Step 4: Detect Ollama
    _echo("Step 4/5: Ollama detection")
    if skip_ollama:
        _skip("Skipped (--skip-ollama)")
    else:
        ollama_bin = shutil.which("ollama")
        if ollama_bin:
            _ok(f"Ollama found: {ollama_bin}")
            try:
                import subprocess
                result = subprocess.run(
                    ["ollama", "list"], capture_output=True, text=True, timeout=5,
                )
                if result.returncode == 0:
                    lines = result.stdout.strip().split("\n")
                    model_count = max(0, len(lines) - 1)  # subtract header
                    _ok(f"{model_count} model(s) available")
                else:
                    _skip("Ollama installed but not running")
            except Exception:
                _skip("Ollama installed but not responding")
        else:
            _skip("Ollama not found (optional — install from ollama.com)")

    # Step 5: Health check
    _echo("Step 5/5: Health check")
    try:
        from whitemagic.tools.dispatch_table import dispatch
        raw = dispatch("health_report") or {}
        health: dict = raw if isinstance(raw, dict) else {}
        score = health.get("health_score", 0)
        status = health.get("health_status", "unknown")
        tool_count = health.get("tool_count", "?")
        _ok(f"Health: {status} ({score:.0%}) | {tool_count} tools")
    except Exception as e:
        _fail(f"Health check: {e}")

    _echo("\n🎉 WhiteMagic is ready! Try:\n")
    _echo("  wm status          # system overview")
    _echo("  wm doctor          # detailed diagnostics")
    _echo('  wm gana invoke gnosis \'{"compact": true}\'  # introspection')
    _echo("")

@main.command(name="backup")
@click.option("--output", "-o", default=None, help="Output path for backup archive")
@click.option("--galaxy", default=None, help="Backup a specific galaxy (default: all)")
def backup_command(output: str | None, galaxy: str | None) -> None:
    """📦 Backup WhiteMagic memory databases.

    Creates a timestamped .tar.gz archive of the memory directory.
    """
    import tarfile

    from whitemagic.config import paths as cfg_paths

    state_root = cfg_paths.get_state_root()  # type: ignore[attr-defined]
    memory_dir = state_root / "memory"

    if not memory_dir.exists():
        click.echo("❌ No memory directory found. Nothing to backup.")
        raise SystemExit(1)

    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")

    if output:
        out_path = Path(output)
    else:
        out_path = Path.cwd() / f"whitemagic_backup_{timestamp}.tar.gz"

    if galaxy:
        # Backup specific galaxy
        galaxy_dir = memory_dir / "galaxies" / galaxy
        if not galaxy_dir.exists():
            click.echo(f"❌ Galaxy '{galaxy}' not found at {galaxy_dir}")
            raise SystemExit(1)
        source = galaxy_dir
        label = f"galaxy:{galaxy}"
    else:
        source = memory_dir
        label = "all memories"

    click.echo(f"📦 Backing up {label} from {source}")
    try:
        with tarfile.open(str(out_path), "w:gz") as tar:
            tar.add(str(source), arcname=source.name)
        size_mb = out_path.stat().st_size / (1024 * 1024)
        click.echo(f"✅ Backup saved: {out_path} ({size_mb:.1f} MB)")
    except Exception as e:
        click.echo(f"❌ Backup failed: {e}")
        raise SystemExit(1)


@main.command(name="restore")
@click.argument("archive_path")
@click.option("--force", is_flag=True, help="Overwrite existing data")
def restore_command(archive_path: str, force: bool) -> None:
    """📦 Restore WhiteMagic memory from a backup archive."""
    import tarfile

    from whitemagic.config import paths as cfg_paths

    archive = Path(archive_path)
    if not archive.exists():
        click.echo(f"❌ Archive not found: {archive}")
        raise SystemExit(1)

    state_root = cfg_paths.get_state_root()  # type: ignore[attr-defined]
    memory_dir = state_root / "memory"

    if memory_dir.exists() and not force:
        click.echo("❌ Memory directory already exists. Use --force to overwrite.")
        raise SystemExit(1)

    click.echo(f"📦 Restoring from {archive}")
    try:
        memory_dir.mkdir(parents=True, exist_ok=True)
        with tarfile.open(str(archive), "r:gz") as tar:
            tar.extractall(str(memory_dir.parent))
        click.echo(f"✅ Restored to {memory_dir}")
    except Exception as e:
        click.echo(f"❌ Restore failed: {e}")
        raise SystemExit(1)


# --- Global Memory Helper ---

_memory = None

def get_memory():  # type: ignore[return]
    """Get or create memory instance (respects WM_STATE_ROOT)."""
    global _memory
    if _memory is None and HAS_CORE:
        _memory = get_unified_memory()
    return _memory

# --- Gana System --- (PSR-028: extracted to cli/commands/gana_commands.py)
from whitemagic.cli.commands.gana_commands import gana_group  # noqa: E402
main.add_command(gana_group)

# --- Dharma System --- (PSR-028: extracted to cli/commands/dharma_commands.py)
from whitemagic.cli.commands.dharma_commands import dharma_group  # noqa: E402
main.add_command(dharma_group)

# --- Local ML (Enhanced) ---

@click.command(name="local-query")
@click.argument("prompt")
@click.option("--backend", type=click.Choice(["bitnet", "ollama", "auto"]), default="auto")
def infer_local_query(prompt: str, backend: str) -> None:
    """Run local ML inference query (BitNet/Ollama)"""
    from whitemagic.mcp_api_bridge import local_ml_infer

    try:
        if HAS_RICH and console:
            with console.status(f"[cyan]Running inference with {backend}...", spinner="dots"):
                result = local_ml_infer(prompt=prompt, backend=backend if backend != "auto" else None)
        else:
            result = local_ml_infer(prompt=prompt, backend=backend if backend != "auto" else None)

        if "error" in result:
            click.echo(f"❌ Error: {result['error']}")
            return

        if HAS_RICH and console:
            panel = Panel(
                "[bold]Response:[/bold]\n\n"
                f"{result.get('response', 'N/A')}\n\n"
                f"[dim]Backend: {result.get('backend', 'unknown')} | "
                f"Time: {result.get('time_ms', 0):.0f}ms[/dim]",
                title="🤖 Local ML",
                border_style="cyan",
            )
            console.print(panel)
        else:
            click.echo(result.get("response", "N/A"))
    except Exception as e:
        click.echo(f"❌ Error: {e}")

@click.command(name="local-status")
def infer_local_status() -> None:
    """Show local ML engine status"""
    from whitemagic.mcp_api_bridge import local_ml_status

    try:
        result = local_ml_status()
        if HAS_RICH and console:
            table = Table(title="🤖 Local ML Status", show_header=True)
            table.add_column("Backend", style="cyan")
            table.add_column("Available", justify="center")
            table.add_column("Models", justify="center")
            for backend, info in result.get("backends", {}).items():
                available = "✅" if info.get("available") else "❌"
                models = info.get("models", [])
                table.add_row(
                    backend.title(),
                    available,
                    str(len(models)) if models else "0",
                )
            console.print(table)
            default = result.get("default_backend")
            if default:
                console.print(f"\n[green]Default backend:[/green] {default}")
        else:
            for backend, info in result.get("backends", {}).items():
                available = "yes" if info.get("available") else "no"
                models = info.get("models", [])
                click.echo(f"{backend}: {available} ({len(models)} models)")
    except Exception as e:
        click.echo(f"❌ Error: {e}")

# --- Convenience Aliases (commands the test AI tried) ---

@main.command(name="rules")
def rules_command() -> None:
    """☸️  Show active Dharma rules (alias for `wm dharma principles`)"""
    from whitemagic.tools.dispatch_table import dispatch
    try:
        result = dispatch("dharma_rules") or {}
        rules = result.get("rules", result.get("principles", []))
        if isinstance(rules, list):
            for r in rules[:20]:
                if isinstance(r, dict):
                    click.echo(f"  {r.get('name', '?')}: {r.get('level', '?')} (weight: {r.get('weight', '?')})")
                else:
                    click.echo(f"  {r}")
        else:
            click.echo(_json_dumps(result, indent=2, default=str)[:2000])
    except Exception as e:
        click.echo(f"❌ {e}")


@main.command(name="systemmap")
def systemmap_command() -> None:
    """🗺️  Display the system map overview"""
    try:
        from whitemagic.config.paths import get_project_root
        sm = get_project_root() / "SYSTEM_MAP.md"
        if sm.exists():
            text = sm.read_text()
            click.echo(text[:3000])
        else:
            click.echo("System map not found. Try: wm status")
    except Exception as e:
        click.echo(f"❌ {e}")


# --- Wisdom & Reasoning --- (PSR-028: extracted to cli/commands/wisdom_commands.py)
from whitemagic.cli.commands.wisdom_commands import wisdom_group  # noqa: E402
main.add_command(wisdom_group)

# --- Maintenance Commands --- (PSR-028: extracted to cli/commands/maintenance_commands.py)
from whitemagic.cli.commands.maintenance_commands import maintenance_group  # noqa: E402
main.add_command(maintenance_group)

# --- Core Memory Commands ---

@main.command()
@click.argument("content")
@click.option("--title", help="Memory title")
@click.option("--tags", help="Comma-separated tags")
@click.option("--type", "memory_type", default="short_term",
              type=click.Choice(["short_term", "long_term"]))
@click.pass_context
def remember(ctx, content: str, title: str | None, tags: str | None, memory_type: str) -> None:
    """Create a new memory entry"""
    from whitemagic.tools.unified_api import call_tool

    now = (ctx.obj or {}).get("now") if isinstance(ctx.obj, dict) else None
    json_output = (ctx.obj or {}).get("json_output") if isinstance(ctx.obj, dict) else False

    tags_list = [t.strip() for t in (tags or "").split(",") if t.strip()]
    title_val = title or (content[:60] + ("..." if len(content) > 60 else ""))

    out = call_tool(
        "create_memory",
        title=title_val,
        content=content,
        tags=tags_list,
        type=memory_type,
        now=now,
    )

    if json_output:
        click.echo(_json_dumps(out, indent=2, sort_keys=True))
        return

    if out.get("status") != "success":
        click.echo(f"❌ Error: {out.get('message', 'Unknown error')}")
        return

    details = out.get("details", {}) or {}
    click.echo(f"✅ Memory created: {details.get('memory_id')}")
    if details.get("filename"):
        click.echo(f"   Filename: {details.get('filename')}")

# --- Scratchpad Commands --- (PSR-028: extracted to cli/commands/scratchpad_commands.py)
from whitemagic.cli.commands.scratchpad_commands import scratchpad  # noqa: E402
main.add_command(scratchpad)

# --- Session Commands --- (PSR-028: session group kept inline — single command, low value to extract)


@main.command(name="start-session")
@click.option("--quiet", is_flag=True, help="Suppress verbose startup output")
def start_session_cli(quiet: bool):
    """Start a WhiteMagic session orchestrator run"""
    try:
        from whitemagic.core.orchestration.session_startup import start_session
        result = start_session(verbose=not quiet)
        click.echo(f"✅ Session start: {result.get('status', 'unknown')}")
        click.echo(f"   Activated: {result.get('activated', 0)} | Failed: {result.get('failed', 0)}")
    except Exception as exc:
        click.echo(f"❌ Session start failed: {exc}")

@main.command()
@click.argument("query")
@click.option("--limit", default=10, help="Max results")
@click.option("--type", "search_type", help="Filter by memory type")
@click.option("--fast", is_flag=True, help="Use Rust fast_search (v4.9.0)")
@click.pass_context
def recall(ctx, query: str, limit: int, search_type: str | None, fast: bool) -> None:
    """Search memories"""
    from whitemagic.tools.unified_api import call_tool

    now = (ctx.obj or {}).get("now") if isinstance(ctx.obj, dict) else None
    json_output = (ctx.obj or {}).get("json_output") if isinstance(ctx.obj, dict) else False

    args: dict[str, Any] = {"query": query, "limit": limit}
    if search_type:
        args["type"] = search_type

    out = call_tool("search_memories", now=now, **args)
    if json_output:
        click.echo(_json_dumps(out, indent=2, sort_keys=True))
        return

    if out.get("status") != "success":
        click.echo(f"❌ Error: {out.get('message', 'Unknown error')}")
        return

    details = out.get("details", {}) or {}
    results = details.get("results")
    if not isinstance(results, list):
        results = details.get("memories")
    if not isinstance(results, list):
        results = []
    click.echo(f"\n🔍 Found {len(results)} memories matching '{query}':")
    for i, item in enumerate(results[:limit], 1):
        entry = (item or {}).get("entry", {}) if isinstance(item, dict) else {}
        if not entry and isinstance(item, dict):
            entry = {
                "id": item.get("id"),
                "title": item.get("title"),
                "tags": item.get("tags"),
            }
        title = entry.get("title") or entry.get("id") or "memory"
        preview = (item or {}).get("preview") if isinstance(item, dict) else ""
        if not preview and isinstance(item, dict):
            preview = item.get("content", "")
        score = (item or {}).get("score") if isinstance(item, dict) else None
        score_str = f" (score={score:.2f})" if isinstance(score, (int, float)) else ""
        click.echo(f"\n{i}. {title}{score_str}")
        if preview:
            click.echo(f"   {str(preview)[:200]}")
        tags = entry.get("tags") or ((item or {}).get("tags") if isinstance(item, dict) else []) or []
        if isinstance(tags, str):
            tags = [tags]
        elif not isinstance(tags, list):
            tags = []
        if tags:
            click.echo(f"   Tags: {', '.join(tags)}")

@main.command()
@click.argument("query")
@click.option("--limit", default=10, help="Max results")
@click.option("--type", "search_type", help="Filter by memory type")
@click.option("--fast", is_flag=True, help="Use Rust fast_search (v4.9.0)")
def search(query: str, limit: int, search_type: str | None, fast: bool) -> None:
    """Alias for recall - search memories"""
    # Forward to recall command
    ctx = click.get_current_context()
    ctx.invoke(recall, query=query, limit=limit, search_type=search_type, fast=fast)

@main.command()
@click.option("--tier", default=1, type=click.IntRange(0, 2),
              help="Context tier (0=quick, 1=balanced, 2=deep)")
def context(tier: int) -> None:
    """Generate context summary for AI prompts"""
    if not HAS_CORE:
        click.echo("Error: WhiteMagic core not available", err=True)
        return

    # Simple context generation
    memory = get_memory()

    # Limit based on tier
    limits = {0: 3, 1: 10, 2: 50}
    limit = limits.get(tier, 10)

    recent_memories = memory.list_recent(limit=limit)

    click.echo(f"\n📚 Context (Tier {tier}, {limit} most recent):")
    click.echo("=" * 50)

    for i, mem in enumerate(recent_memories, 1):
        content_preview = str(mem.content)[:150] + "..." if len(str(mem.content)) > 150 else str(mem.content)
        click.echo(f"\n{i}. [{mem.memory_type.name}] {mem.created_at.strftime('%Y-%m-%d %H:%M')}")
        click.echo(f"   {content_preview}")

@main.command()
def list_tools() -> None:
    """Alias for tools - list all available commands"""
    # Forward to tools command
    ctx = click.get_current_context()
    ctx.invoke(tools)

@main.command()
def consolidate() -> None:
    """Archive old short-term memories"""
    if not HAS_CORE:
        click.echo("Error: WhiteMagic core not available", err=True)
        return

    memory = get_memory()

    click.echo("🔄 Consolidating memories...")
    consolidated = memory.consolidate()

    if consolidated == 0:
        click.echo("✅ No memories needed consolidation")
        return

    click.echo(f"✅ Consolidated {consolidated} memories (strengthened/decayed/promoted)")

@main.command()
def stats() -> None:
    """Show memory statistics dashboard"""
    if not HAS_CORE:
        click.echo("Error: WhiteMagic core not available", err=True)
        return

    memory = get_memory()

    click.echo("\n📊 Memory Statistics")
    click.echo("=" * 40)

    stats_data = memory.get_stats()

    # Total memories
    total = stats_data["total_memories"]
    click.echo(f"Total Memories: {total}")

    # By type
    click.echo("\nBy Type:")
    type_counts = stats_data.get("by_type", {})
    for mem_type_name, count in type_counts.items():
        if count > 0:
            click.echo(f"  {mem_type_name.replace('_', ' ').title():<12}: {count:>6}")

    # Tags
    total_tags = stats_data.get("total_tags", 0)
    click.echo(f"\nUnique Tags: {total_tags}")

    # Most used tags
    tag_counts = memory.get_tag_counts(limit=10)

    if tag_counts:
        click.echo("\nTop Tags:")
        for tag, count in tag_counts:
            click.echo(f"  {tag:<20}: {count:>3}")


@main.command()
def setup() -> None:
    """Interactive setup wizard"""
    click.echo("\n🚀 WhiteMagic Setup Wizard")
    click.echo("=" * 40)

    # Check if already configured
    from whitemagic.config.paths import WM_ROOT, ensure_paths
    config_dir = WM_ROOT
    if config_dir.exists():
        click.echo(f"✅ WhiteMagic already configured at: {config_dir}")
        if click.confirm("Would you like to reconfigure?"):
            pass
        else:
            return

    # Create directories
    click.echo("\n📁 Creating directories...")
    ensure_paths()
    # Extra legacy/utility dirs (best-effort; keep runtime state together)
    for d in ["backups"]:
        (config_dir / d).mkdir(parents=True, exist_ok=True)
    click.echo(f"   ✅ {config_dir}")

    # Initialize memory system
    if HAS_CORE:
        click.echo("\n🧠 Initializing memory system...")
        memory = get_memory()
        click.echo(f"   ✅ {memory.get_stats()['total_memories']} memories found")

    # MCP readiness (stdio)
    click.echo("\n🔌 MCP readiness...")
    if find_spec("fastmcp") is not None:
        click.echo("   ✅ fastmcp installed")
    else:
        click.echo("   ⚠️  fastmcp not installed (MCP server won't run)")
        click.echo("      Install: pip install 'whitemagic[mcp]'")

    mcp_entry = Path(__file__).resolve().parent / "run_mcp.py"
    if mcp_entry.exists():
        rel = str(mcp_entry)
        try:
            rel = str(mcp_entry.relative_to(Path.cwd()))
        except ValueError:
            pass
        click.echo(f"   ✅ MCP entrypoint present: {rel}")
    else:
        click.echo("   ⚠️  MCP entrypoint missing: whitemagic/run_mcp.py")

    click.echo("\n✨ Setup complete!")
    click.echo("\nNext steps:")
    click.echo("  1. Run: wm status")
    click.echo("  2. Try: wm remember 'my first memory' --title 'Hello'")
    click.echo("  3. Use: wm recall 'first'")
    click.echo("  4. MCP: python -m whitemagic.run_mcp")

@main.command()
@click.option("--json", "json_output", is_flag=True, help="Emit tools list as JSON.")
@click.pass_context
def tools(ctx, json_output: bool) -> None:
    """List all available tools and commands"""
    global_json = bool((ctx.obj or {}).get("json_output")) if isinstance(ctx.obj, dict) else False
    emit_json = json_output or global_json

    commands = [
        ("remember", "Create a new memory"),
        ("recall", "Search memories"),
        ("search", "Alias for recall"),
        ("context", "Generate AI context"),
        ("status", "Show system status"),
        ("setup", "Run setup wizard"),
        ("consolidate", "Archive old memories"),
        ("stats", "Show memory statistics"),
        ("health", "Check system health"),
        ("doctor", "Install + ship hygiene check (AI-first)"),
        ("doctor-deep", "Legacy deep audit (unstable)"),
        ("start-session", "Start session orchestrator"),
        ("explore", "Interactive feature guide"),
        ("fast", "Fast-mode CLI passthrough"),
    ]

    garden_commands = [
        ("voice", "Voice and narrative tools"),
        ("gana", "28 Lunar Mansion Gana system"),
        ("dharma", "Ethical reasoning tools"),
        ("wisdom", "Wisdom council and I Ching"),
        ("infer", "Inference tools (local + unified)"),
    ]
    if HAS_SANGHA:
        garden_commands.append(("sangha", "Multi-agent coordination"))

    optional_commands = []
    if HAS_EXEC:
        optional_commands.append(("exec", "Execute terminal commands"))
    if HAS_GRAPH:
        optional_commands.extend([
            ("graph", "Visualize memory relationships"),
            ("graph-stats", "Show relationship statistics"),
        ])

    if emit_json:
        click.echo(_json_dumps({
            "core_commands": [{"command": c, "description": d} for c, d in commands],
            "garden_commands": [{"command": c, "description": d} for c, d in garden_commands],
            "optional_commands": [{"command": c, "description": d} for c, d in optional_commands],
            "usage": "whitemagic <command> --help",
        }, indent=2, sort_keys=True))
        return

    click.echo("\n🛠️  WhiteMagic Tools")
    click.echo("=" * 40)

    click.echo("\nCore Commands:")
    for cmd, desc in commands:
        click.echo(f"  {cmd:<12} - {desc}")

    click.echo("\nGarden Commands:")
    for cmd, desc in garden_commands:
        click.echo(f"  {cmd:<12} - {desc}")

    for cmd, desc in optional_commands:
        click.echo(f"  {cmd:<12} - {desc}")

    click.echo("\nFor help with any command:")
    click.echo("  whitemagic <command> --help")

# === RESONANCE / HEALTH COMMANDS === (PSR-028: extracted to cli/commands/health_commands.py)
from whitemagic.cli.commands.health_commands import register_health_commands  # noqa: E402
register_health_commands(main)

@main.command(name="memory-list")
@click.option("--limit", default=10, help="Max memories to show")
def memory_list(limit: int) -> None:
    """List recent memories"""
    if not HAS_CORE:
        click.echo("Error: WhiteMagic core not available", err=True)
        return

    memory = get_memory()

    # Get recent memories
    all_mems = memory.list_recent(limit=limit)

    click.echo(f"\n📝 Recent Memories (Top {limit})")
    click.echo("=" * 40)

    for i, mem in enumerate(all_mems[:limit], 1):
        preview = str(mem.content)[:80] + "..." if len(str(mem.content)) > 80 else str(mem.content)
        click.echo(f"\n{i}. {mem.title or 'Untitled'} ({mem.memory_type.value})")
        click.echo(f"   {preview}")
        click.echo(f"   ID: {mem.id[:8]}... | Tags: {', '.join(mem.tags)}")

@main.command()
@click.option("--output", "-o", default="memory_graph.html", help="Output file for the graph")
def graph(output: str) -> None:
    """Generate relationship graph for memories (v4.5.0)."""
    if not HAS_CORE:
        click.echo("Error: WhiteMagic core not available", err=True)
        return

    # Placeholder implementation - generate basic HTML graph
    html_content = """<!DOCTYPE html>
<html>
<head>
    <title>WhiteMagic Memory Graph</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        .node { border: 1px solid #ccc; padding: 10px; margin: 5px; display: inline-block; }
    </style>
</head>
<body>
    <h1>WhiteMagic Memory Relationship Graph</h1>
    <p>Graph visualization placeholder. Implement full graph logic here.</p>
    <div class="node">Memory 1</div>
    <div class="node">Memory 2</div>
    <!-- Add actual graph generation logic -->
</body>
</html>"""

    try:
        with open(output, "w") as f:
            f.write(html_content)
        click.echo(f"✅ Graph generated: {output}")
    except Exception as e:
        click.echo(f"❌ Failed to generate graph: {e}", err=True)

@main.command(name="session-start")
def session_start() -> None:
    """Bootstrap new session with full context loading."""
    click.echo("\n🚀 Starting WhiteMagic Session...")
    click.echo("=" * 40)
    try:
        from whitemagic.maintenance.capability_harness import run_harness
        report = run_harness()
        # Handle report structure safely
        passed = getattr(report, "passed", 0)
        failed = getattr(report, "failed", 0)
        click.echo(f"\n✅ Session initialized with {passed}/{passed + failed} capabilities")
    except Exception as e:
        click.echo(f"⚠️  Warning: {e}")
    click.echo("\n📚 Use 'wm tools' to see available commands")

@main.command(name="session-status")
def session_status() -> None:
    """Show current session status."""
    ctx = click.get_current_context()
    ctx.invoke(status_command)

@main.command(name="matrix-stats")
def matrix_stats() -> None:
    """Show Memory Matrix statistics."""
    click.echo("\n📊 Memory Matrix Statistics")
    click.echo("=" * 40)
    try:
        memory = get_memory()
        stats_data = memory.get_stats()
        total = stats_data["total_memories"]
        click.echo(f"Total memories: {total}")
        type_counts = stats_data.get("by_type", {})
        for mt_name, count in type_counts.items():
            click.echo(f"  {mt_name:<12}: {count}")
    except Exception as e:
        click.echo(f"⚠️  Matrix not available: {e}")


@main.command(name="matrix-seen")
@click.option("--limit", default=10, help="Max items")
def matrix_seen(limit: int):
    """List recently accessed memories."""
    try:
        memory = get_memory()
        recent_accessed = memory.list_accessed(limit=limit)

        click.echo("\n🧠 Recently Accessed Memories")
        click.echo("=" * 40)
        for mem in recent_accessed:
            preview = str(mem.content)
            if len(preview) > 80:
                preview = preview[:77] + "..."
            click.echo(f"{mem.accessed_at.isoformat()} | {mem.memory_type.name:<10} | {mem.id} | tags={list(mem.tags)}")
            click.echo(f"  {preview}")
    except Exception as e:
        click.echo(f"⚠️  Matrix not available: {e}")


# --- Balance Commands --- (PSR-028: extracted to cli/commands/balance_commands.py)
from whitemagic.cli.commands.balance_commands import balance  # noqa: E402
main.add_command(balance)


@main.command(name="matrix-search")
@click.option("--query", required=True, help="Text to search in content")
@click.option("--limit", default=10, help="Max results")
def matrix_search(query: str, limit: int) -> None:
    """Search memories by substring (quick local scan)."""
    try:
        memory = get_memory()
        # Use UnifiedMemory's search which uses SQLite backend
        results = memory.search(query=query, limit=limit)

        click.echo(f"\n🔎 Matrix Search: '{query}' (showing up to {limit})")
        click.echo("=" * 50)
        for mem in results:
            preview = str(mem.content)
            if len(preview) > 120:
                preview = preview[:117] + "..."
            click.echo(f"{mem.memory_type.name:<10} | {mem.id} | tags={list(mem.tags)}")
            click.echo(f"  {preview}")
        if not results:
            click.echo("No matches found.")
    except Exception as e:
        click.echo(f"⚠️  Matrix search unavailable: {e}")

@main.command(name="activate-all")
def activate_all() -> None:
    """Full system activation - bootstrap all capabilities."""
    click.echo("\n⚡ Activating All WhiteMagic Systems...")
    click.echo("=" * 40)
    ctx = click.get_current_context()
    ctx.invoke(session_start)
    ctx.invoke(status_command)
    click.echo("\n✅ Full system activation complete!")

@main.command(name="manifest")
def manifest() -> None:
    """Export tools as JSON manifest."""
    commands = {}
    for name, cmd in main.commands.items():
        commands[name] = {
            "help": cmd.help or "No description",
            "params": [p.name for p in cmd.params],
        }
    click.echo(_json_dumps(commands, indent=2))


# === SHADOW CLONE ARMY COMMANDS === (PSR-028: extracted to cli/commands/army_commands.py)
from whitemagic.cli.commands.army_commands import army  # noqa: E402
main.add_command(army)


# === CONDUCTOR COMMANDS === (PSR-028: extracted to cli/commands/conductor_commands.py)
from whitemagic.cli.commands.conductor_commands import register_conductor_commands  # noqa: E402
register_conductor_commands(main)

@main.command()
def observe() -> None:
    """Real-time Gan Ying event viewer (v4.5.0)."""
    if not HAS_RICH:
        click.echo("❌ Rich is required for observation mode. Install with: pip install rich")
        return

    try:
        import time
        from collections import deque

        from rich.live import Live
        from rich.table import Table

        from whitemagic.core.resonance.gan_ying import get_bus
    except ImportError as e:
        click.echo(f"❌ Failed to import required modules: {e}")
        return

    bus = get_bus()
    events = deque(maxlen=20)

    def on_event(event):
        events.append(event)

    # Subscribe to ALL events
    if hasattr(bus, "listen_all"):
        bus.listen_all(on_event)
    else:
        # Fallback if listen_all not available yet
        click.echo("⚠️  GanYingBus does not support listen_all. Update core.")
        return

    def generate_table():
        table = Table(title="🔮 Gan Ying Resonance (Real-time)", expand=True)
        table.add_column("Time", style="cyan", no_wrap=True)
        table.add_column("Type", style="magenta")
        table.add_column("Source", style="green")
        table.add_column("Data", style="white")
        table.add_column("Conf", justify="right", style="yellow")

        # Sort by timestamp desc
        sorted_events = sorted(list(events), key=lambda e: e.timestamp, reverse=True)

        for e in sorted_events:
            data_str = str(e.data)
            if len(data_str) > 50:
                data_str = data_str[:47] + "..."

            table.add_row(
                e.timestamp.strftime("%H:%M:%S.%f")[:-3],
                e.event_type.name if hasattr(e.event_type, "name") else str(e.event_type),
                e.source,
                data_str,
                f"{e.confidence:.2f}",
            )
        return table

    console.print("[bold green]Starting observer... Press Ctrl+C to stop.[/bold green]")

    try:
        with Live(generate_table(), refresh_per_second=4, console=console) as live:
            while True:
                live.update(generate_table())
                time.sleep(0.25)
    except KeyboardInterrupt:
        console.print("\n[bold yellow]Observer stopped.[/bold yellow]")

# --- Dream Daemon Commands --- (PSR-028: extracted to cli/commands/dream_commands.py)
from whitemagic.cli.commands.dream_commands import dream_group  # noqa: E402
main.add_command(dream_group)

# --- Extension Registration ---
try:
    main.add_command(gardens)
    main.add_command(intelligence)
    main.add_command(iching)
    main.add_command(wuxing)
except Exception as e:
    if HAS_RICH and console:
        console.print(f"[yellow]Warning: Failed to load extensions: {e}[/yellow]")
    else:
        click.echo(f"Warning: Failed to load extensions: {e}", err=True)

# Register reasoning commands (v4.10.0)
if HAS_REASONING:
    try:
        main.add_command(reasoning, name="reason")
    except Exception as e:
        if HAS_RICH and console:
            console.print(f"[yellow]Warning: Failed to load reasoning CLI: {e}[/yellow]")
        else:
            click.echo(f"Warning: Failed to load reasoning CLI: {e}", err=True)

# Register inference commands (v4.11.0)
if HAS_INFERENCE:
    try:
        main.add_command(infer)
    except Exception as e:
        if HAS_RICH and console:
            console.print(f"[yellow]Warning: Failed to load inference CLI: {e}[/yellow]")
        else:
            click.echo(f"Warning: Failed to load inference CLI: {e}", err=True)

# Fallback for inference if module not available or errored
if "infer" not in main.commands:
    @main.group(name="infer")
    def infer_fallback_group():
        """Local inference commands (fallback)"""
    if os.getenv("WHITEMAGIC_ENABLE_LOCAL_MODELS", "").strip().lower() in {"1", "true", "yes", "on"}:
        infer_fallback_group.add_command(infer_local_query)
        infer_fallback_group.add_command(infer_local_status)
else:
    # Attempt to attach local commands to existing infer group
    try:
        if os.getenv("WHITEMAGIC_ENABLE_LOCAL_MODELS", "").strip().lower() in {"1", "true", "yes", "on"}:
            infer.add_command(infer_local_query)
            infer.add_command(infer_local_status)
    except Exception:
        pass

# Register hardware commands (v4.11.0)
if HAS_HARDWARE_CLI:
    try:
        main.add_command(hardware)
    except Exception as e:
        if HAS_RICH and console:
            console.print(f"[yellow]Warning: Failed to load hardware CLI: {e}[/yellow]")
        else:
            click.echo(f"Warning: Failed to load hardware CLI: {e}", err=True)

# Register Sangha CLI commands (v4.12.x)
if HAS_SANGHA:
    try:
        main.add_command(sangha_cli, name="sangha")
    except Exception as e:
        if HAS_RICH and console:
            console.print(f"[yellow]Warning: Failed to load Sangha CLI: {e}[/yellow]")
        else:
            click.echo(f"Warning: Failed to load Sangha CLI: {e}", err=True)

# Register Archaeology CLI commands (v4.11.0)
if HAS_ARCHAEOLOGY:
    try:
        main.add_command(archaeology)
        main.add_command(windsurf)
    except Exception as e:
        if HAS_RICH and console:
            console.print(f"[yellow]Warning: Failed to load Archaeology CLI: {e}[/yellow]")
        else:
            click.echo(f"Warning: Failed to load Archaeology CLI: {e}", err=True)

# Register Watcher CLI commands (v4.13.0)
if HAS_WATCHER:
    try:
        main.add_command(watch)
    except Exception as e:
        if HAS_RICH and console:
            console.print(f"[yellow]Warning: Failed to load Watcher CLI: {e}[/yellow]")
        else:
            click.echo(f"Warning: Failed to load Watcher CLI: {e}", err=True)

# Register Autonomous Execution CLI commands (v4.14.0)
if HAS_AUTONOMOUS:
    main.add_command(autonomous)

# Register local model CLI (v4.14.0)
if HAS_LOCAL:
    main.add_command(local_cli, name="local")

# Register cache commands (v4.15.0)
try:
    from whitemagic.cli.cli_cache import cache_cli
    main.add_command(cache_cli, name="cache")
except ImportError:
    pass

# Register zodiac commands (v4.15.0 - Zodiacal Round)
try:
    from whitemagic.cli.cli_zodiac import zodiac_cli
    main.add_command(zodiac_cli, name="zodiac")
except ImportError:
    pass

# Register Scratchpad CLI (v5.2.0 - Phase 26)
if HAS_SCRATCH:
    main.add_command(scratch)

# Register new infra commands
if HAS_NEW_INFRA:
    main.add_command(optimization_cli)
    main.add_command(thought_cli)
    main.add_command(supervisor_cli)
    main.add_command(phase_cli)

# Register PRAT commands (v5.1.0 - Polymorphic Resonant Adaptive Tools)
try:
    from whitemagic.cli.cli_prat import prat
    main.add_command(prat, name="prat")
except ImportError:
    pass

# Register Holographic commands (v5.0.0 - 4D Memory)
try:
    from whitemagic.cli.holo_commands import holo_cli  # type: ignore[import-not-found]
    main.add_command(holo_cli, name="holo")
except ImportError as e:
    missing_mod = getattr(e, "name", "")
    expected_absence = missing_mod in {"whitemagic.cli", "whitemagic.cli.holo_commands"}
    if not expected_absence or os.getenv("WM_DEBUG"):
        if HAS_RICH and console:
            console.print(f"[yellow]Warning: Failed to load Holographic CLI: {e}[/yellow]")
        else:
            click.echo(f"Warning: Failed to load Holographic CLI: {e}", err=True)
except Exception as e:
    click.echo(f"Warning: Unexpected error loading Holographic CLI: {e}", err=True)

# Load and register plugins
if HAS_PLUGINS:
    try:
        load_plugins()
        register_commands(main)
    except Exception as e:
        if not os.getenv("WM_SILENT_INIT"):
            if HAS_RICH and console:
                console.print(f"[yellow]Warning: Failed to load plugins: {e}[/yellow]")
            else:
                click.echo(f"Warning: Failed to load plugins: {e}", err=True)

# Register init command (v14.0 — first-run scaffolding)
try:
    from whitemagic.cli.init_command import init_command
    main.add_command(init_command)
except ImportError:
    pass

# Register Rust CLI commands (v4.9.0)
if HAS_RUST_CLI:
    try:
        register_rust_commands(main)
    except Exception as e:
        if HAS_RICH and console:
            console.print(f"[yellow]Warning: Failed to load Rust CLI: {e}[/yellow]")
        else:
            click.echo(f"Warning: Failed to load Rust CLI: {e}", err=True)


# ── Vault CLI ───────────────────────────────────────────────── (PSR-028: extracted to cli/commands/vault_commands.py)
from whitemagic.cli.commands.vault_commands import vault_group  # noqa: E402
main.add_command(vault_group)


if __name__ == "__main__":
    main()
