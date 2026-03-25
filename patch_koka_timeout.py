import re

with open('whitemagic/core/acceleration/koka_native_bridge.py', 'r') as f:
    content = f.read()

# Add a circuit breaker implementation
circuit_breaker = """
class KokaCircuitBreaker:
    def __init__(self, failure_threshold: int = 3, reset_timeout: float = 30.0):
        self.failures = 0
        self.failure_threshold = failure_threshold
        self.reset_timeout = reset_timeout
        self.last_failure_time = 0.0
        self.state = "CLOSED" # CLOSED (ok), OPEN (failing), HALF_OPEN (testing)
        self.lock = threading.Lock()
        
    def record_failure(self):
        with self.lock:
            self.failures += 1
            self.last_failure_time = time.time()
            if self.failures >= self.failure_threshold:
                self.state = "OPEN"
                logger.warning(f"Koka circuit breaker OPENED after {self.failures} failures")
                
    def record_success(self):
        with self.lock:
            self.failures = 0
            if self.state != "CLOSED":
                self.state = "CLOSED"
                logger.info("Koka circuit breaker RESET to CLOSED")
                
    def allow_request(self) -> bool:
        with self.lock:
            if self.state == "CLOSED":
                return True
            if self.state == "OPEN":
                if time.time() - self.last_failure_time > self.reset_timeout:
                    self.state = "HALF_OPEN"
                    return True
                return False
            # HALF_OPEN allows 1 request through
            return True
"""

if "class KokaCircuitBreaker" not in content:
    content = content.replace("class KokaNativeBridge:", circuit_breaker + "\nclass KokaNativeBridge:")
    
    # Initialize circuit breakers per module
    content = content.replace("self._binaries: dict[str, Path] = {}", "self._binaries: dict[str, Path] = {}\n        self._breakers: dict[str, KokaCircuitBreaker] = {}")
    
    # Register breaker when checking binaries
    content = content.replace("self._available[name] = []", "self._available[name] = []\n                if name not in self._breakers:\n                    self._breakers[name] = KokaCircuitBreaker()")
    content = content.replace('self._available["dispatcher"] = []', 'self._available["dispatcher"] = []\n            if "dispatcher" not in self._breakers:\n                self._breakers["dispatcher"] = KokaCircuitBreaker()')
    
    # Check circuit breaker before dispatch
    check_breaker = """
        if not self.is_available(module):
            logger.debug("Koka module not available: %s", module)
            return None
            
        breaker = self._breakers.get(module)
        if breaker and not breaker.allow_request():
            logger.warning("Koka circuit breaker OPEN for %s - skipping dispatch", module)
            return None
"""
    content = re.sub(r'        if not self\.is_available\(module\):\n            logger\.debug\("Koka module not available: %s", module\)\n            return None', check_breaker, content)
    
    # Record success/failure in dispatch
    content = content.replace('logger.error("Koka process timed out or returned no response for %s.%s", module, operation)', 'logger.error("Koka process timed out or returned no response for %s.%s", module, operation)\n            if breaker: breaker.record_failure()')
    content = content.replace('logger.error("Invalid JSON from Koka: %s", e)', 'logger.error("Invalid JSON from Koka: %s", e)\n                if breaker: breaker.record_failure()')
    content = content.replace('logger.error("Koka call timed out: %s.%s", module, operation)', 'logger.error("Koka call timed out: %s.%s", module, operation)\n            if breaker: breaker.record_failure()')
    content = content.replace('logger.error("Koka dispatch error: %s", e)', 'logger.error("Koka dispatch error: %s", e)\n            if breaker: breaker.record_failure()')
    
    # Add success record
    content = content.replace('response["_koka_latency_ms"] = elapsed * 1000\n                return response', 'response["_koka_latency_ms"] = elapsed * 1000\n                if breaker: breaker.record_success()\n                return response')
    
    # Add timeout fallback to _readline_with_timeout to be safe from hanging threads
    fallback = """        thread.start()
        # Add thread join with a slightly longer timeout just to avoid leaking threads
        try:
            res = result_queue.get(timeout=timeout)
            # Give thread a chance to finish cleanly
            thread.join(0.1) 
            return res
        except queue.Empty:
            return None"""
            
    content = re.sub(r'        thread\.start\(\)\n\n        try:\n            return result_queue\.get\(timeout=timeout\)\n        except queue\.Empty:\n            return None', fallback, content)

with open('whitemagic/core/acceleration/koka_native_bridge.py', 'w') as f:
    f.write(content)

print("Patched koka_native_bridge.py with circuit breakers")
