import os
from pathlib import Path
from whitemagic.interfaces.terminal.config import TerminalConfig
from whitemagic.sessions.manager import SessionManager
from whitemagic.security.tool_gating import PathValidator

def test_config_portability():
    os.environ["WM_CONFIG_ROOT"] = "/tmp/wm_test_config"
    config = TerminalConfig()
    config.save()
    assert Path("/tmp/wm_test_config/terminal_config.json").exists()
    print("✅ TerminalConfig portability passed")

def test_session_portability():
    os.environ["WM_CONFIG_ROOT"] = "/tmp/wm_test_sessions"
    manager = SessionManager()
    assert manager.base_dir == Path("/tmp/wm_test_sessions/sessions")
    print("✅ SessionManager portability passed")

def test_path_validator_expansion():
    os.environ["WM_CONFIG_ROOT"] = "/tmp/wm_test_gating"
    validator = PathValidator()
    # Check if config_root is in allowed_bases
    config_root = Path("/tmp/wm_test_gating").resolve()
    assert config_root in validator.allowed_bases
    print("✅ PathValidator expansion passed")

if __name__ == "__main__":
    try:
        test_config_portability()
        test_session_portability()
        test_path_validator_expansion()
        print("\n✨ WAVE 1 VERIFICATIONS PASSED ✨")
    finally:
        # Cleanup
        import shutil
        if Path("/tmp/wm_test_config").exists(): shutil.rmtree("/tmp/wm_test_config")
        if Path("/tmp/wm_test_sessions").exists(): shutil.rmtree("/tmp/wm_test_sessions")
        if Path("/tmp/wm_test_gating").exists(): shutil.rmtree("/tmp/wm_test_gating")
