# Encryption at Rest — Design Document

> Design for WhiteMagic v15.0+ local database encryption.
> Goal: Protect memory DB, gratitude ledger, and secrets at rest without requiring a server.

---

## Problem Statement

Today, WhiteMagic's SQLite database (`~/.whitemagic/memory/whitemagic.db`) and JSONL files (gratitude ledger, karma ledger, telemetry) are stored in plaintext. While the state directory is now chmod `0o700` (owner-only), this doesn't protect against:
- Disk theft / forensic recovery
- Malware with user-level access
- Cloud sync services (Dropbox, iCloud) inadvertently copying unencrypted DB
- Multi-user systems where another user gains access

## Architecture Options

### Option A: SQLCipher (Recommended)

**SQLCipher** is an open-source extension to SQLite that provides transparent 256-bit AES encryption.

| Aspect | Details |
|--------|---------|
| Library | `sqlcipher` (C library) or `pysqlcipher3` (Python bindings) |
| Encryption | AES-256-CBC with HMAC-SHA512 |
| Key derivation | PBKDF2-HMAC-SHA512, 256K iterations |
| Performance | ~5-15% overhead vs plain SQLite |
| Compatibility | Drop-in replacement for SQLite API |

**Integration points:**
```python
# In whitemagic/core/memory/unified.py — connection setup
import sqlite3  # Replace with sqlcipher when available

def _connect(db_path: Path, key: str | None = None) -> sqlite3.Connection:
    conn = sqlite3.connect(str(db_path))
    if key:
        conn.execute(f"PRAGMA key = '{key}'")
        conn.execute("PRAGMA cipher_page_size = 4096")
    return conn
```

**Migration path:**
1. Detect unencrypted DB on startup
2. Prompt for passphrase (or derive from OS keychain)
3. Create encrypted copy: `sqlcipher_export('encrypted.db')`
4. Verify encrypted DB, swap in place
5. Securely delete plaintext original

### Option B: Row-Level AES-GCM

Encrypt individual memory content fields while keeping metadata (IDs, timestamps, tags) searchable in plaintext.

| Aspect | Details |
|--------|---------|
| Library | Python `cryptography` (Fernet or AES-GCM) |
| Encryption | AES-256-GCM per-row |
| Key derivation | Argon2id |
| Performance | Higher overhead (encrypt/decrypt per read/write) |
| Compatibility | Requires schema changes |

**Tradeoff**: Allows FTS on tags/titles while protecting content. But more complex and slower than SQLCipher.

### Recommendation

**SQLCipher for v15.0** — simpler, proven, minimal code changes. Row-level encryption as a future option for cases where metadata must remain queryable by untrusted processes.

---

## Key Management

### Key Derivation Hierarchy

```
User Passphrase (or OS keychain entry)
    │
    ├── Argon2id(passphrase, salt) → Master Key (256-bit)
    │       │
    │       ├── HKDF(master, "sqlite") → DB Encryption Key
    │       ├── HKDF(master, "ledger") → Ledger Encryption Key
    │       └── HKDF(master, "vault") → Secret Vault Key
    │
    └── OS Keychain (preferred, no passphrase needed)
            │
            └── Stored Master Key → same derivation as above
```

### Key Sources (Priority Order)

1. **OS Keychain** (macOS Keychain, Linux Secret Service, Windows Credential Manager)
   - Zero friction — no passphrase prompt
   - Key stored securely by OS
   - Python library: `keyring`

2. **Passphrase** (fallback)
   - User enters on first run, derived via Argon2id
   - Salt stored in `$WM_STATE_ROOT/encryption/salt.bin`
   - Key cached in memory for session duration

3. **Environment Variable** (`WM_ENCRYPTION_KEY`)
   - For CI/CD and container environments
   - Base64-encoded 256-bit key
   - Least secure but most automated

### Implementation Sketch

```python
# whitemagic/security/vault.py (new file)

import os
from pathlib import Path
from typing import Optional

def get_master_key() -> Optional[bytes]:
    """Get the master encryption key from available sources."""

    # Priority 1: Environment variable (CI/container)
    env_key = os.environ.get("WM_ENCRYPTION_KEY")
    if env_key:
        import base64
        return base64.b64decode(env_key)

    # Priority 2: OS keychain
    try:
        import keyring
        stored = keyring.get_password("whitemagic", "master_key")
        if stored:
            import base64
            return base64.b64decode(stored)
    except Exception:
        pass

    # Priority 3: No encryption (current behavior)
    return None
```

---

## Encrypted File Types

| File | Current Format | Encryption Method |
|------|---------------|-------------------|
| `memory/whitemagic.db` | SQLite | SQLCipher (full DB) |
| `memory/whitemagic_cold.db` | SQLite | SQLCipher (full DB) |
| `gratitude/ledger.jsonl` | Plaintext JSONL | AES-GCM per-line (or encrypted file) |
| `dharma/karma_ledger.jsonl` | Plaintext JSONL | AES-GCM per-line |
| `logs/telemetry.jsonl` | Plaintext JSONL | Optional (low sensitivity) |
| Galaxy DBs | SQLite | SQLCipher (per-galaxy key possible) |

---

## Auto-Lock

After a configurable idle timeout, WhiteMagic should:
1. Flush any in-memory caches
2. Close DB connections (releasing the decrypted page cache)
3. Clear the master key from memory
4. Require re-authentication on next access

```python
# Config
WM_LOCK_TIMEOUT=300  # seconds (5 minutes default)
WM_LOCK_ON_SLEEP=1   # lock when system sleeps
```

---

## `wm vault` CLI Command

A new CLI command for managing encrypted secrets:

```bash
# Initialize encryption (first time)
wm vault init
# → Prompts for passphrase or uses OS keychain
# → Creates salt, derives master key, encrypts DB

# Store a secret
wm vault set OPENAI_API_KEY sk-abc123...
# → Encrypted in local vault, never in .env

# Retrieve a secret (for use in scripts)
wm vault get OPENAI_API_KEY
# → Decrypts and prints (or exports to env)

# List stored secrets (names only)
wm vault list
# → OPENAI_API_KEY, ANTHROPIC_API_KEY, WM_XRP_ADDRESS

# Lock the vault (clear keys from memory)
wm vault lock

# Change passphrase
wm vault rekey
```

### Secret Storage Schema

```sql
CREATE TABLE IF NOT EXISTS vault (
    name TEXT PRIMARY KEY,
    encrypted_value BLOB NOT NULL,  -- AES-GCM ciphertext
    nonce BLOB NOT NULL,            -- 12-byte GCM nonce
    created_at TEXT NOT NULL,
    updated_at TEXT NOT NULL
);
```

---

## Context Sanitization Integration

The existing `_sanitize_context()` in `ollama_agent.py` is defense-in-depth. With a vault:
1. Secrets are never stored in `.env` files (which might get committed)
2. `ollama.agent` loads secrets from the vault when needed
3. Context sanitization catches any secrets that leak into memory content
4. Double protection: vault + runtime redaction

---

## Migration Plan

### Phase 1 (v15.0): Optional Encryption
- Add `whitemagic[secure]` extra with `pysqlcipher3` + `keyring` + `argon2-cffi`
- `wm vault init` creates encrypted DB alongside plaintext
- Opt-in: `WM_ENCRYPTION=1` enables encryption
- Zero-config users unaffected

### Phase 2 (v15.1): Default Encryption for New Installs
- New `wm init` projects default to encrypted DB
- Existing installs prompted to migrate on `wm doctor`
- `wm vault` becomes the recommended way to store API keys

### Phase 3 (v16.0): Encryption Required
- Plaintext DB deprecated
- Auto-migration on upgrade
- All JSONL files encrypted

---

## Dependencies

| Package | Purpose | Size |
|---------|---------|------|
| `pysqlcipher3` | SQLCipher Python bindings | ~50KB (needs libsqlcipher) |
| `keyring` | OS keychain access | ~100KB |
| `argon2-cffi` | Passphrase key derivation | ~50KB |
| `cryptography` | AES-GCM for JSONL files | Already a transitive dep |

Total: ~200KB additional, all well-maintained packages.

---

## Security Properties

| Property | Guarantee |
|----------|-----------|
| Confidentiality at rest | AES-256 encryption on all sensitive files |
| Key never in repo | Derived from passphrase or OS keychain |
| Forward secrecy | Key rotation via `wm vault rekey` |
| Memory safety | Key cleared on lock/timeout |
| Backward compatibility | Plaintext mode still works (opt-in encryption) |
| No server dependency | Everything local, no cloud key management |

---

*Design document: February 2026 — Target: WhiteMagic v15.0*
