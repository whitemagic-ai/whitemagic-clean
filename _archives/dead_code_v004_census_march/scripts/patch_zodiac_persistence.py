import re
from pathlib import Path

file_path = Path("/home/lucas/Desktop/whitemagicdev/whitemagic/security/zodiac/ledger.py")
content = file_path.read_text()

# Patch the ZodiacLedger to persist to SQLite using the db_manager pool
import_pattern = r"from whitemagic.utils.fast_json import dumps_str as _json_dumps"
replacement = r"""from whitemagic.utils.fast_json import dumps_str as _json_dumps
from whitemagic.core.memory.db_manager import get_db_pool"""
content = content.replace(import_pattern, replacement)

persistence_pattern = r"(# TODO: Persist to SQLite ledger table via db_manager\n\s+return entry)"
replacement_logic = r"""# Persist to SQLite ledger table via db_manager
            try:
                db_path = "/home/lucas/.whitemagic/memory/whitemagic.db"
                pool = get_db_pool(db_path)
                with pool.connection() as conn:
                    with conn:
                        conn.execute(\"\"\"
                            INSERT INTO zodiac_ledger (
                                entry_id, timestamp, actor_id, action_type,
                                payload, parent_hash, context_id, consent_token, hash_signature
                            ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
                        \"\"\", (
                            entry.entry_id, entry.timestamp, entry.actor_id, entry.action_type,
                            _json_dumps(entry.payload), entry.parent_hash,
                            entry.context_id, entry.consent_token, entry.hash_signature
                        ))
            except Exception as e:
                import logging
                logging.getLogger(__name__).error(f"Failed to persist zodiac entry: {e}")
                
            return entry"""
content = re.sub(persistence_pattern, replacement_logic, content)

file_path.write_text(content)
print("zodiac ledger patched for SQLite persistence.")
