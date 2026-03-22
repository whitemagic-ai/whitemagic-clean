import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/acceleration/koka_native_bridge.py"

with open(file_path, "r") as f:
    content = f.read()

# VC-03: Process Health Monitoring & VC-04: Connection Pooling v2
# We'll update the bridge to automatically prune dead processes and scale the pool up to _max_connections

patch = """
    def is_available(self, module: str) -> bool:
        \"\"\"Check if a Koka module is available and healthy.\"\"\"
        if module not in self._binaries:
            return False
            
        with self._lock:
            # Check for dead processes and prune them
            if module in self._processes:
                dead_procs = [p for p in self._processes[module] if p.poll() is not None]
                for p in dead_procs:
                    self._processes[module].remove(p)
                    if module in self._available and p in self._available[module]:
                        self._available[module].remove(p)
                        
            # If we have living processes or room to grow, we are available
            current_alive = len(self._processes.get(module, []))
            return current_alive > 0 or current_alive < self._max_connections
            
    def _get_process(self, module: str) -> subprocess.Popen | None:
        \"\"\"Get or create a subprocess for the module.\"\"\"
        with self._lock:
            # Clean dead processes from available pool first
            if self._available.get(module):
                valid_procs = [p for p in self._available[module] if p.poll() is None]
                self._available[module] = valid_procs
                if valid_procs:
                    return self._available[module].pop()
            
            # Check if we can create more
            # Clean dead processes from total tracked
            if module in self._processes:
                self._processes[module] = [p for p in self._processes[module] if p.poll() is None]
                
            current = len(self._processes.get(module, []))
            if current >= self._max_connections:
                return None  # Pool exhausted
"""

pattern = r'    def is_available\(self, module: str\) -> bool:.*?if current >= self\._max_connections:\n                return None  # Pool exhausted'

new_content = re.sub(pattern, patch.lstrip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("koka_native_bridge.py patched for health monitoring and connection pooling!")
