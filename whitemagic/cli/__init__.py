"""WhiteMagic CLI Subcommands Package

Submodules are registered with the main Click group via ``register_all()``.

Structure (v13.0.0):
    cli/doctor.py          — health, doctor, immune-status, homeostasis-check
    cli/cli_reasoning.py   — multi-spectral reasoning (existing)
    cli/infer_commands.py  — unified inference (existing)
    cli/hardware_commands.py — hardware awareness (existing)
    cli/holo_commands.py   — holographic memory (existing)
"""


def register_all(main) -> None:  # type: ignore[no-untyped-def]
    """Register all cli/ submodule commands with *main* Click group."""
    try:
        from whitemagic.cli import doctor
        doctor.register(main)
    except ImportError:
        pass
    try:
        from whitemagic.cli import init_command
        init_command.register(main)
    except ImportError:
        pass
