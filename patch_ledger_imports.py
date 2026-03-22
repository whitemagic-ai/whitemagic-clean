import re

with open('whitemagic/security/zodiac/ledger.py') as f:
    content = f.read()

# Make it use Rust ZodiacLedger if available, otherwise fallback
replacement = """
try:
    import whitemagic_rust
    if hasattr(whitemagic_rust.sutra_kernel, 'ZodiacLedger'):
        _RustLedger = whitemagic_rust.sutra_kernel.ZodiacLedger
    else:
        _RustLedger = None
except ImportError:
    _RustLedger = None

class ZodiacLedger:
    \"\"\"In-memory and persistent cryptographic ledger.\"\"\"
    
    def __init__(self, db_manager=None):
        self._chain: List[ZodiacEntry] = []
        self._genesis_hash = hashlib.sha256(b"WHITEMAGIC_GENESIS_v16").hexdigest()
        self._current_tail = self._genesis_hash
        self._db = db_manager # Hook for SQLite persistence
        self._lock = __import__('threading').Lock()
        self._rust_ledger = _RustLedger() if _RustLedger else None

    def record_action(
        self, 
        actor_id: str, 
        action_type: str, 
        payload: Dict[str, Any],
        context_id: Optional[str] = None,
        consent_token: Optional[str] = None
    ) -> ZodiacEntry:
        \"\"\"Record an action in the cryptographic ledger.\"\"\"
        with self._lock:
            # Parallel track in Rust kernel if available
            if self._rust_ledger:
                try:
                    rust_sig = self._rust_ledger.record_action(
                        action_type, 
                        _json_dumps(payload),
                        "sattvic", # default guna
                        0.0 # default karma
                    )
                except Exception as e:
                    import logging
                    logging.getLogger(__name__).warning(f"Rust ledger record failed: {e}")
"""

content = re.sub(r'class ZodiacLedger:[^}]+def record_action[^:]+:[^:]+with self\._lock:', replacement, content)

with open('whitemagic/security/zodiac/ledger.py', 'w') as f:
    f.write(content)

print("Patched ledger.py")
