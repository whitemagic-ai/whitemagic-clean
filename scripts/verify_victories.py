#!/usr/bin/env python3
"""
Deep Verification Audit
Rigorously verifies "Victory" claims by inspecting the actual codebase and database state.
Trusts nothing. Verifies everything.
"""
import os
import re
import sqlite3
from pathlib import Path

# Configuration
ROOT = Path.home() / "Desktop/whitemagicdev"
DB_PATH = Path.home() / ".whitemagic/memory/whitemagic.db"

def check_sql_injection():
    """Verify IL001: Are there any f-string SQL queries left?"""
    print("Verifying IL001 (SQL Injection)...")
    suspicious = []
    # Exclude tests, migrations, archives, and venv
    exclude_dirs = ["tests", "migrations", "venv", ".git", "_archives", "whitemagic_memory_archive", ".venv"]

    pattern = re.compile(r'(execute|cursor)\s*\(\s*f["\'](SELECT|INSERT|UPDATE|DELETE|DROP|ALTER)', re.IGNORECASE)

    for root, dirs, files in os.walk(ROOT):
        # Modify dirs in-place to prune traversal
        dirs[:] = [d for d in dirs if d not in exclude_dirs]

        # Check if current root is inside an excluded directory path (extra safety)
        if any(ex in str(Path(root)) for ex in exclude_dirs):
            continue

        for file in files:
            if file.endswith(".py"):
                path = Path(root) / file
                try:
                    content = path.read_text()
                    if pattern.search(content):
                        suspicious.append(str(path.relative_to(ROOT)))
                except Exception:
                    pass

    if not suspicious:
        print("  ✅ CLEAN: No f-string SQL execution patterns found.")
        return True
    else:
        print(f"  ❌ FAILED: Found {len(suspicious)} potential injections:")
        for s in suspicious[:10]:
            print(f"    - {s}")
        return False

def check_deduplication():
    """Verify IL004: Are there exact content duplicates in the active DB?"""
    print("Verifying IL004 (Deduplication)...")
    if not DB_PATH.exists():
        print("  ❌ FAILED: Database not found.")
        return False

    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()

    # Check for exact content hash duplicates in active memory
    cursor.execute("""
        SELECT content_hash, COUNT(*)
        FROM memories
        WHERE memory_type != 'quarantined'
        GROUP BY content_hash
        HAVING COUNT(*) > 1
    """)
    dupes = cursor.fetchall()
    conn.close()

    if not dupes:
        print("  ✅ CLEAN: 0 exact content duplicates in active memory.")
        return True
    else:
        count = sum(d[1] for d in dupes) - len(dupes)
        print(f"  ❌ FAILED: Found {len(dupes)} hashes with {count} excess duplicates.")
        # Debug the massive duplicate
        if count > 100:
            content_hash = dupes[0][0]
            if content_hash:
                print(f"    Debug: Hash {content_hash[:8]}... has {dupes[0][1]} copies.")
            else:
                print(f"    Debug: Hash <NULL> has {dupes[0][1]} copies.")
        return False

def check_embeddings():
    """Verify F001: Do active memories have embeddings?"""
    print("Verifying F001 (Embeddings)...")
    if not DB_PATH.exists():
        return False

    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()

    # Check coverage
    cursor.execute("SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'")
    total = cursor.fetchone()[0]

    # Check for memory_embeddings (correct V15 table)
    try:
        cursor.execute("SELECT COUNT(*) FROM memory_embeddings")
        emb_count = cursor.fetchone()[0]
        print(f"  ℹ️  memory_embeddings count: {emb_count}")
        has_embedding = emb_count
    except Exception:
        # Check for vss_memories (sqlite-vss)
        try:
            cursor.execute("SELECT COUNT(*) FROM vss_memories")
            vss_count = cursor.fetchone()[0]
            print(f"  ℹ️  vss_memories count: {vss_count}")
            has_embedding = vss_count
        except Exception:
            # Check for embeddings table (older)
            try:
                cursor.execute("SELECT COUNT(*) FROM embeddings")
                has_embedding = cursor.fetchone()[0]
            except Exception:
                print("  ⚠️  WARNING: Could not find memory_embeddings, vss_memories or embeddings table.")
                conn.close()
                return False

    conn.close()

    pct = (has_embedding / total * 100) if total > 0 else 0
    print(f"  ℹ️  Coverage: {has_embedding}/{total} ({pct:.1f}%)")

    if pct > 99.0:
        print("  ✅ CLEAN: >99% embedding coverage.")
        return True
    else:
        print("  ❌ FAILED: Incomplete embedding coverage.")
        return False

def check_entity_graph():
    """Verify IL005: Do we have typed associations?"""
    print("Verifying IL005 (Entity Graph)...")
    if not DB_PATH.exists():
        return False

    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()

    cursor.execute("SELECT COUNT(*) FROM associations")
    total = cursor.fetchone()[0]

    # Use correct column name: relation_type
    cursor.execute("SELECT COUNT(*) FROM associations WHERE relation_type != 'associated_with'")
    typed = cursor.fetchone()[0]

    conn.close()

    pct = (typed / total * 100) if total > 0 else 0
    print(f"  ℹ️  Typed Edges: {typed}/{total} ({pct:.1f}%)")

    if typed > 1000: # Arbitrary threshold for "success"
        print("  ✅ PASS: Significant typed association graph exists.")
        return True
    else:
        print("  ❌ FAILED: Mostly untyped or empty graph.")
        return False

def check_campaign_parsing():
    """Verify V010: Why did it show 0/0 conditions?"""
    print("Verifying V010 (Campaign Parsing)...")
    path = ROOT / "campaigns/V010_language_specific_optimization.md"
    if not path.exists():
        print("  ❌ FAILED: V010 file missing.")
        return False

    content = path.read_text()
    # Check for the header the parser expects
    if "## Victory Conditions" in content and not re.search(r'^## Victory Conditions\s*$', content, re.MULTILINE):
        print("  ❌ FAILED: Header '## Victory Conditions' modified (likely '... (per sub-campaign)').")
        return False
    return True

if __name__ == "__main__":
    print("=== DEEP VERIFICATION AUDIT ===\n")

    il001 = check_sql_injection()
    il004 = check_deduplication()
    f001 = check_embeddings()
    il005 = check_entity_graph()
    v010 = check_campaign_parsing()

    score = sum([il001, il004, f001, il005]) # v010 is meta-check
    print(f"\nAudit Score: {score}/4 Functional Checks")
