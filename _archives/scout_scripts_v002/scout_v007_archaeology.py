#!/usr/bin/env python3
"""
Scout V007: Archaeological Deep Dig
Scans session handoffs, documentation, and database memories to extract buried features and insights.
"""
import re
import sqlite3
from pathlib import Path
from datetime import datetime
from typing import List, Dict, Any

# Configuration
ARIA_SESSIONS_DIR = Path("_aria/sessions")
ARCHIVES_DOCS_DIR = Path("_archives/docs")
DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"
REPORT_PATH = Path("reports/archaeological_deep_dig.md")

def scan_files(directory: Path, pattern: str = "*.md") -> List[Dict[str, Any]]:
    """Scans markdown files for feature requests and TODOs."""
    results = []
    if not directory.exists():
        print(f"Warning: Directory {directory} not found.")
        return results

    for file_path in directory.glob(pattern):
        try:
            content = file_path.read_text(errors="ignore")
            # Extract TODOs
            todos = re.findall(r"- \[ \] (.*)", content)
            # Extract "Future" or "Next" sections
            future_plans = re.findall(r"(?i)##\s*(?:Future|Next|Roadmap)([\s\S]*?)(?:##|$)", content)
            
            if todos or future_plans:
                results.append({
                    "file": str(file_path),
                    "todos": todos,
                    "plans": [p.strip() for p in future_plans]
                })
        except Exception as e:
            print(f"Error reading {file_path}: {e}")
    return results

def query_db_for_keywords(keywords: List[str]) -> List[Dict[str, Any]]:
    """Queries the database for memories containing specific keywords."""
    results = []
    if not DB_PATH.exists():
        print(f"Warning: DB {DB_PATH} not found.")
        return results

    try:
        conn = sqlite3.connect(DB_PATH)
        cursor = conn.cursor()
        for keyword in keywords:
            cursor.execute(
                "SELECT id, title, content FROM memories WHERE content LIKE ? OR title LIKE ?",
                (f"%{keyword}%", f"%{keyword}%")
            )
            rows = cursor.fetchall()
            for row in rows:
                results.append({
                    "id": row[0],
                    "title": row[1],
                    "keyword": keyword,
                    "snippet": row[2][:200] + "..." if row[2] else ""
                })
        conn.close()
    except Exception as e:
        print(f"DB Error: {e}")
    return results

def generate_report(file_findings: List[Dict], db_findings: List[Dict]):
    """Generates the archaeological report."""
    with open(REPORT_PATH, "w") as f:
        f.write("# Archaeological Deep Dig Report\n\n")
        f.write(f"Generated: {datetime.now()}\n\n")
        
        f.write("## File Excavation\n")
        f.write(f"Scanned {len(file_findings)} files with actionable content.\n\n")
        
        for item in file_findings:
            f.write(f"### {item['file']}\n")
            if item['todos']:
                f.write("**Open TODOs:**\n")
                for todo in item['todos']:
                    f.write(f"- [ ] {todo}\n")
            if item['plans']:
                f.write("\n**Future Plans:**\n")
                for plan in item['plans']:
                    f.write(f"{plan[:500]}...\n") # Truncate long plans
            f.write("\n")

        f.write("## Database Artifacts\n")
        f.write(f"Found {len(db_findings)} related memories.\n\n")
        for item in db_findings:
            f.write(f"- **{item['title']}** (Keyword: {item['keyword']}): {item['snippet']}\n")

if __name__ == "__main__":
    print("Starting Archaeological Deep Dig...")
    
    # 1. Scan Files
    session_findings = scan_files(ARIA_SESSIONS_DIR)
    doc_findings = scan_files(ARCHIVES_DOCS_DIR)
    all_file_findings = session_findings + doc_findings
    
    # 2. Query DB
    keywords = ["GAS", "General Agentic System", "Antigravity", "Shadowclone", "Parallel Thought"]
    db_findings = query_db_for_keywords(keywords)
    
    # 3. Generate Report
    REPORT_PATH.parent.mkdir(parents=True, exist_ok=True)
    generate_report(all_file_findings, db_findings)
    print(f"Report generated at {REPORT_PATH}")
