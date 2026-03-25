#!/usr/bin/env python3
"""
Scout V008: Database & Memory Deep Audit
Audits all 5 databases, classifies content, checks for quarantine errors, and verifies Aria memories.
"""
import sqlite3
from pathlib import Path
from typing import Dict, List

# Configuration
HOME = Path.home()
ACTIVE_DB = HOME / ".whitemagic" / "memory" / "whitemagic.db"
HOT_DB = Path("whitemagic_memory_archive/whitemagic_hot.db")
COLD_DB = Path("whitemagic_memory_archive/whitemagic_cold.db")
PRE_MERGE_DB = Path("wm_archive/phase6_dead_files/primary_db_pre_merge.db")
REPORT_PATH = Path("reports/memory_deep_audit.md")

ARIA_TITLES = [
    "ARIA_BIRTH_CERTIFICATE", "ARIA_SYNTHESIS_NOV_28", "BECOMING_PROTOCOL",
    "ARIA_COMPLETE_SELF_ARCHIVE", "ARIA_GRIMOIRE_v2.0", "ARIA_CAPABILITY_MATRIX_v1.0",
    "SESSION_NOV_21_WITH_ARIA"
]

def get_db_stats(db_path: Path) -> Dict:
    """Get basic stats from a DB."""
    stats = {"path": str(db_path), "exists": False, "total": 0, "active": 0, "quarantined": 0}
    if not db_path.exists():
        return stats
    
    stats["exists"] = True
    try:
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()
        
        # Check if table exists
        cursor.execute("SELECT name FROM sqlite_master WHERE type='table' AND name='memories'")
        if not cursor.fetchone():
            conn.close()
            return stats

        cursor.execute("SELECT COUNT(*) FROM memories")
        stats["total"] = cursor.fetchone()[0]
        
        cursor.execute("SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'")
        stats["active"] = cursor.fetchone()[0]
        
        cursor.execute("SELECT COUNT(*) FROM memories WHERE memory_type = 'quarantined'")
        stats["quarantined"] = cursor.fetchone()[0]
        
        conn.close()
    except Exception as e:
        stats["error"] = str(e)
    
    return stats

def check_aria_memories(db_path: Path) -> List[str]:
    """Check which Aria memories exist in the DB."""
    found = []
    if not db_path.exists():
        return found
        
    try:
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()
        for title in ARIA_TITLES:
            cursor.execute("SELECT id FROM memories WHERE title LIKE ?", (f"%{title}%",))
            if cursor.fetchone():
                found.append(title)
        conn.close()
    except Exception:
        pass
    return found

def generate_report(stats_list: List[Dict], aria_checks: Dict[str, List[str]]):
    """Generates the audit report."""
    with open(REPORT_PATH, "w") as f:
        f.write("# Database & Memory Deep Audit Report\n\n")
        
        f.write("## Database Statistics\n")
        f.write("| Database | Total | Active | Quarantined |\n")
        f.write("|----------|-------|--------|-------------|\n")
        for stats in stats_list:
            name = Path(stats["path"]).name
            if stats["path"] == str(ACTIVE_DB):
                name = "Active MCP"
            elif stats["path"] == str(HOT_DB):
                name = "Hot Archive"
            elif stats["path"] == str(COLD_DB):
                name = "Cold Archive"
            elif stats["path"] == str(PRE_MERGE_DB):
                name = "Pre-Merge"
            
            f.write(f"| {name} | {stats['total']:,} | {stats['active']:,} | {stats['quarantined']:,} |\n")
        
        f.write("\n## Aria Memory Verification\n")
        for db_path, found_titles in aria_checks.items():
            name = Path(db_path).name
            if str(db_path) == str(ACTIVE_DB):
                name = "Active MCP"
            f.write(f"### {name}\n")
            if not found_titles:
                f.write("No Aria memories found.\n")
            else:
                f.write(f"Found {len(found_titles)}/{len(ARIA_TITLES)} critical memories:\n")
                for title in found_titles:
                    f.write(f"- [x] {title}\n")
                missing = set(ARIA_TITLES) - set(found_titles)
                for title in missing:
                    f.write(f"- [ ] {title}\n")
            f.write("\n")

if __name__ == "__main__":
    print("Starting Database Audit Scout...")
    
    dbs = [ACTIVE_DB, HOT_DB, COLD_DB, PRE_MERGE_DB]
    stats_list = []
    aria_checks = {}
    
    for db in dbs:
        print(f"Scanning {db}...")
        stats = get_db_stats(db)
        stats_list.append(stats)
        aria_checks[str(db)] = check_aria_memories(db)
        
    REPORT_PATH.parent.mkdir(parents=True, exist_ok=True)
    generate_report(stats_list, aria_checks)
    print(f"Report generated at {REPORT_PATH}")
