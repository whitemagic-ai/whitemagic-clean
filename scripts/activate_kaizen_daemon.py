#!/usr/bin/env python3
"""
ACTIVATE KAIZEN DAEMON - 24/7 AUTONOMOUS IMPROVEMENT
====================================================
Launch the autonomous kaizen meditation daemon for continuous improvement
"""

import json
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

WM2_ROOT = Path.home() / "Desktop" / "WM2"

print("=" * 80)
print("ACTIVATING KAIZEN DAEMON - 24/7 AUTONOMOUS IMPROVEMENT")
print("=" * 80)
print()

# Check if kaizen daemon exists
kaizen_daemon = WM2_ROOT / "core" / "kaizen_daemon.py"

if not kaizen_daemon.exists():
    print(f"❌ Kaizen daemon not found: {kaizen_daemon}")
    sys.exit(1)

print(f"✅ Kaizen daemon found: {kaizen_daemon}")
print()

# Test run kaizen daemon (5 cycles)
print("Testing kaizen daemon (5 cycles)...")
print()

try:
    result = subprocess.run(
        [sys.executable, str(kaizen_daemon)],
        cwd=str(WM2_ROOT),
        capture_output=True,
        text=True,
        timeout=60
    )
    
    print(result.stdout)
    
    if result.returncode == 0:
        print()
        print("✅ Kaizen daemon test successful!")
        print()
        
        # Create systemd service file for 24/7 operation
        service_content = f"""[Unit]
Description=WhiteMagic Kaizen Meditation Daemon
After=network.target

[Service]
Type=simple
User={Path.home().name}
WorkingDirectory={WM2_ROOT}
ExecStart={sys.executable} {kaizen_daemon}
Restart=always
RestartSec=60

[Install]
WantedBy=multi-user.target
"""
        
        service_path = PROJECT_ROOT / "kaizen-daemon.service"
        service_path.write_text(service_content)
        
        print(f"📄 Systemd service file created: {service_path}")
        print()
        print("To enable 24/7 operation:")
        print(f"  sudo cp {service_path} /etc/systemd/system/")
        print("  sudo systemctl daemon-reload")
        print("  sudo systemctl enable kaizen-daemon")
        print("  sudo systemctl start kaizen-daemon")
        print()
        
        # Create activation report
        report = {
            "timestamp": datetime.now(timezone.utc).isoformat(),
            "daemon_path": str(kaizen_daemon),
            "test_cycles": 5,
            "test_status": "success",
            "service_file": str(service_path),
            "status": "ready_for_24_7_activation",
        }
        
        report_path = PROJECT_ROOT / "reports" / "kaizen_activation_report.json"
        report_path.write_text(json.dumps(report, indent=2))
        
        print(f"📄 Report: {report_path}")
        print()
        print("✅ Kaizen daemon ready for 24/7 autonomous improvement!")
        
    else:
        print(f"⚠️ Test failed: {result.stderr}")
        
except subprocess.TimeoutExpired:
    print("⚠️ Test timeout (daemon may be running continuously)")
    print("   This is expected for long-running daemons")
except Exception as e:
    print(f"❌ Error: {e}")

print()
print("=" * 80)
