
with open('whitemagic/core/acceleration/koka_native_bridge.py', 'r') as f:
    content = f.read()

# Fix indentation error introduced earlier
content = content.replace('            if breaker: breaker.record_failure()\n                self._discard_process(module, proc)', '                if breaker: breaker.record_failure()\n                self._discard_process(module, proc)')

with open('whitemagic/core/acceleration/koka_native_bridge.py', 'w') as f:
    f.write(content)

print("Fixed indentation")
