#!/usr/bin/env python3
"""IPC Monitoring Dashboard - Real-time channel metrics."""

import sys
sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

import time
import json
from datetime import datetime

class IPCMonitorDashboard:
    """Real-time dashboard for IPC channel health."""
    
    def __init__(self):
        self.channels = {
            'wm/events': {'sent': 0, 'received': 0, 'errors': 0},
            'wm/memories': {'sent': 0, 'received': 0, 'errors': 0},
            'wm/commands': {'sent': 0, 'received': 0, 'errors': 0},
            'wm/harmony': {'sent': 0, 'received': 0, 'errors': 0},
        }
        self.start_time = time.time()
        
    def _get_ipc_status(self):
        """Get current IPC bridge status."""
        try:
            from whitemagic.core.ipc_bridge import get_status
            return get_status()
        except Exception as e:
            return {'error': str(e)}
    
    def _display_header(self):
        """Display dashboard header."""
        print("\033[2J\033[H")  # Clear screen
        print("╔══════════════════════════════════════════════════════════════╗")
        print("║       WhiteMagic IPC Monitoring Dashboard v1.0               ║")
        print("╚══════════════════════════════════════════════════════════════╝")
        print(f"Time: {datetime.now().isoformat()}")
        print()
    
    def _display_status(self, status):
        """Display IPC bridge status."""
        backend = status.get('backend', 'unknown')
        initialized = status.get('initialized', False)
        iceoryx = status.get('iceoryx2_compiled', False)
        
        print(f"Backend: {backend} {'✅' if initialized else '❌'}")
        print(f"Iceoryx2 compiled: {'✅' if iceoryx else '❌'}")
        print(f"Channels: {', '.join(status.get('channels', []))}")
        print(f"Published: {status.get('published', 0)}")
        print(f"Received: {status.get('received', 0)}")
        print(f"Errors: {status.get('errors', 0)}")
        print()
    
    def _display_performance(self):
        """Display performance metrics."""
        elapsed = time.time() - self.start_time
        
        print("Performance:")
        print(f"  Uptime: {elapsed:.1f}s")
        
        total_events = sum(c['sent'] for c in self.channels.values())
        if elapsed > 0:
            throughput = total_events / elapsed
            print(f"  Throughput: {throughput:.1f} events/sec")
        print()
    
    def _display_targets(self):
        """Display target vs actual metrics."""
        print("Targets vs Actual:")
        print(f"  IPC latency: <0.1ms (measuring...)")
        print(f"  Events/sec: N/A → target 100K+")
        print(f"  Multi-process ops: 5.6 → target 2,500+")
        print(f"  Failover: Manual → target <1s")
        print()
    
    def run(self, duration_seconds=30):
        """Run dashboard for specified duration."""
        import signal
        
        signal.signal(signal.SIGINT, lambda s, f: print("\n👋 Dashboard stopped"))
        
        print("🔍 Starting IPC monitoring...")
        print("   Press Ctrl+C to stop\n")
        
        start = time.time()
        while time.time() - start < duration_seconds:
            self._display_header()
            
            status = self._get_ipc_status()
            self._display_status(status)
            self._display_performance()
            self._display_targets()
            
            # Sample update
            if 'published' in status:
                self.channels['wm/events']['sent'] = status.get('published', 0)
            
            print("\nLast update: " + datetime.now().strftime('%H:%M:%S.%f')[:-3])
            print("(Auto-refresh every 1s)")
            
            time.sleep(1)
        
        print("\n✅ Dashboard complete")

if __name__ == "__main__":
    dashboard = IPCMonitorDashboard()
    dashboard.run(duration_seconds=30)
