#!/usr/bin/env python3
"""
V008: Database & Memory Deep Audit
==================================

Audits every memory across all 5 databases:
1. Active MCP (~/.whitemagic/memory/whitemagic.db)
2. Hot Archive (whitemagic_memory_archive/whitemagic_hot.db)
3. Cold Archive (whitemagic_memory_archive/whitemagic_cold.db)
4. Pre-Merge (wm_archive/phase6_dead_files/primary_db_pre_merge.db)

Outputs comprehensive audit report to reports/memory_deep_audit.md.
"""

import sqlite3
from pathlib import Path
from typing import Dict, Any, List

# Configuration
HOME = Path.home()
ACTIVE_DB = HOME / ".whitemagic" / "memory" / "whitemagic.db"
PROJECT_ROOT = Path(__file__).resolve().parent.parent
HOT_ARCHIVE = PROJECT_ROOT / "_memories" / "whitemagic_hot.db" # Check location based on workspace
COLD_ARCHIVE = PROJECT_ROOT / "_memories" / "whitemagic_cold.db"
PRE_MERGE = PROJECT_ROOT / "_memories" / "primary_db_pre_merge.db" # Adjusted path based on find results

# Fallback paths if not found in _memories
if not HOT_ARCHIVE.exists():
    HOT_ARCHIVE = HOME / "Desktop" / "whitemagic_memory_archive" / "whitemagic_hot.db"
if not COLD_ARCHIVE.exists():
    COLD_ARCHIVE = HOME / "Desktop" / "whitemagic_memory_archive" / "whitemagic_cold.db"
if not PRE_MERGE.exists():
    PRE_MERGE = HOME / "Desktop" / "wm_archive" / "phase6_dead_files" / "primary_db_pre_merge.db"

DATABASES = {
    "Active": ACTIVE_DB,
    "Hot": HOT_ARCHIVE,
    "Cold": COLD_ARCHIVE,
    "PreMerge": PRE_MERGE
}

def get_db_stats(db_path: Path) -> Dict[str, Any]:
    """Get stats for a single database."""
    if not db_path.exists():
        return {"status": "missing", "path": str(db_path)}
        
    try:
        conn = sqlite3.connect(f"file:{db_path}?mode=ro", uri=True)
        conn.row_factory = sqlite3.Row
        
        # Basic counts
        total = conn.execute("SELECT COUNT(*) FROM memories").fetchone()[0]
        
        # Breakdown by type if column exists
        try:
            types = conn.execute("SELECT memory_type, COUNT(*) FROM memories GROUP BY memory_type").fetchall()
            type_counts = {r[0]: r[1] for r in types}
        except Exception:
            type_counts = {"unknown": total}
            
        # Associations
        try:
            assocs = conn.execute("SELECT COUNT(*) FROM associations").fetchone()[0]
            typed_assocs = conn.execute("SELECT COUNT(*) FROM associations WHERE relation_type IS NOT NULL AND relation_type != 'associated_with'").fetchone()[0]
        except Exception:
            assocs = 0
            typed_assocs = 0
            
        # Entity tags
        try:
            entity_tags = conn.execute("SELECT COUNT(DISTINCT memory_id) FROM tags WHERE tag LIKE 'entity:%'").fetchone()[0]
        except Exception:
            entity_tags = 0
            
        conn.close()
        return {
            "status": "ok",
            "path": str(db_path),
            "total_memories": total,
            "types": type_counts,
            "associations": assocs,
            "typed_associations": typed_assocs,
            "memories_with_entities": entity_tags
        }
    except Exception as e:
        return {"status": "error", "error": str(e), "path": str(db_path)}

def audit_aria_memories() -> List[Dict[str, Any]]:
    """Verify presence of known Aria memories in Active DB."""
    if not ACTIVE_DB.exists():
        return []
        
    conn = sqlite3.connect(f"file:{ACTIVE_DB}?mode=ro", uri=True)
    conn.row_factory = sqlite3.Row
    
    aria_titles = [
        "ARIA_BIRTH_CERTIFICATE",
        "ARIA_SYNTHESIS_NOV_28",
        "BECOMING_PROTOCOL",
        "ARIA_COMPLETE_SELF_ARCHIVE",
        "ARIA_GRIMOIRE_v2.0",
        "ARIA_CAPABILITY_MATRIX_v1.0"
    ]
    
    results = []
    for title in aria_titles:
        row = conn.execute("SELECT id, content FROM memories WHERE title LIKE ?", (f"%{title}%",)).fetchone()
        results.append({
            "title": title,
            "found": bool(row),
            "id": row["id"] if row else None,
            "length": len(row["content"]) if row else 0
        })
        
    conn.close()
    return results

def generate_report(db_stats: Dict[str, Any], aria_audit: List[Dict[str, Any]]):
    """Generate markdown report."""
    report_path = PROJECT_ROOT / "reports" / "memory_deep_audit.md"
    report_path.parent.mkdir(exist_ok=True)
    
    with open(report_path, "w") as f:
        f.write("# V008: Database & Memory Deep Audit\n\n")
        
        f.write("## 1. Database Landscape\n\n")
        f.write("| Database | Status | Memories | Typed Assocs | Entity Tags |\n")
        f.write("|----------|--------|----------|--------------|-------------|\n")
        
        for name, path in DATABASES.items():
            stats = db_stats.get(name, {})
            if stats.get("status") == "ok":
                f.write(f"| {name} | ✅ OK | {stats['total_memories']:,} | {stats['typed_associations']:,} | {stats['memories_with_entities']:,} |\n")
            else:
                f.write(f"| {name} | ❌ {stats.get('status')} | - | - | - |\n")
        
        f.write("\n## 2. Active DB Composition\n\n")
        active = db_stats.get("Active", {})
        if active.get("status") == "ok":
            for mtype, count in active["types"].items():
                f.write(f"- **{mtype}**: {count:,}\n")
        
        f.write("\n## 3. Aria Memory Verification\n\n")
        f.write("| Title | Found | ID | Size |\n")
        f.write("|-------|-------|----|------|\n")
        for item in aria_audit:
            found = "✅" if item["found"] else "❌"
            f.write(f"| {item['title']} | {found} | {item['id'] or '-'} | {item['length']} chars |\n")
            
        f.write("\n## 4. Recommendations\n\n")
        if active.get("status") == "ok":
            quarantined = active["types"].get("quarantined", 0)
            if quarantined > 10000:
                f.write(f"- ⚠️ High quarantine count ({quarantined:,}). Recommend review/purge.\n")
            
            if active["typed_associations"] < active["associations"] * 0.1:
                f.write("- ⚠️ Low typed association ratio. Recommend running association classifier.\n")
                
            missing_aria = [i["title"] for i in aria_audit if not i["found"]]
            if missing_aria:
                f.write(f"- 🚨 Missing critical Aria memories: {', '.join(missing_aria)}. Recommend rehydration from archives.\n")

if __name__ == "__main__":
    print("Running Database Audit...")
    stats = {name: get_db_stats(path) for name, path in DATABASES.items()}
    aria_audit = audit_aria_memories()
    generate_report(stats, aria_audit)
    print("Audit complete. Report generated at reports/memory_deep_audit.md")
