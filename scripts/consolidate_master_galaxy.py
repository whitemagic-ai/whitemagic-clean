
import sqlite3
import os
import sys

def get_connection(db_path):
    conn = sqlite3.connect(db_path)
    conn.execute("PRAGMA journal_mode=WAL")
    conn.execute("PRAGMA synchronous=NORMAL")
    conn.execute("PRAGMA busy_timeout=30000")
    return conn

def create_master_db(master_path, schema_db_path):
    if os.path.exists(master_path):
        print(f"Master database already exists at {master_path}. Skipping creation.")
        return
    
    print(f"Creating master database at {master_path} using schema from {schema_db_path}...")
    with get_connection(schema_db_path) as schema_conn:
        schema = schema_conn.execute("""
            SELECT sql FROM sqlite_master 
            WHERE sql IS NOT NULL 
            AND name NOT LIKE 'sqlite_%'
            AND name NOT LIKE '%_fts_data'
            AND name NOT LIKE '%_fts_idx'
            AND name NOT LIKE '%_fts_content'
            AND name NOT LIKE '%_fts_docsize'
            AND name NOT LIKE '%_fts_config'
        """).fetchall()
    
    with get_connection(master_path) as master_conn:
        for (sql,) in schema:
            try:
                master_conn.execute(sql)
            except sqlite3.OperationalError as e:
                print(f"Warning: Could not execute: {sql[:100]}... Error: {e}")
    print("Master database initialized.")

def phase_a_union(master_path, archive_paths):
    print("Phase A: Union of unique memories...")
    with get_connection(master_path) as master_conn:
        for path in archive_paths:
            print(f"Processing {path}...")
            master_conn.execute(f"ATTACH DATABASE '{path}' AS source")
            
            source_cols = [row[1] for row in master_conn.execute("PRAGMA source.table_info(memories)").fetchall()]
            master_cols = [row[1] for row in master_conn.execute("PRAGMA table_info(memories)").fetchall()]
            common_cols = [col for col in source_cols if col in master_cols]
            col_list = ", ".join(common_cols)
            
            master_conn.execute(f"INSERT OR IGNORE INTO memories ({col_list}) SELECT {col_list} FROM source.memories")
            master_conn.execute("INSERT OR IGNORE INTO tags (memory_id, tag) SELECT memory_id, tag FROM source.tags")
            
            master_conn.commit()
            master_conn.execute("DETACH DATABASE source")
    print("Phase A completed.")

def phase_b_upsert(master_path, source_paths):
    print("Phase B: Attribute Merge...")
    with get_connection(master_path) as master_conn:
        for path in source_paths:
            print(f"Merging attributes from {path}...")
            master_conn.execute(f"ATTACH DATABASE '{path}' AS source")
            
            master_cols = [row[1] for row in master_conn.execute("PRAGMA table_info(memories)").fetchall()]
            cols_to_update = [c for c in master_cols if c != 'id']
            
            for col in cols_to_update:
                master_conn.execute(f"UPDATE memories SET {col} = (SELECT {col} FROM source.memories WHERE source.memories.id = memories.id) WHERE memories.id IN (SELECT id FROM source.memories) AND memories.{col} IS NULL")
            
            master_conn.commit()
            master_conn.execute("DETACH DATABASE source")
    print("Phase B completed.")

def phase_c_associations(master_path, cold_path):
    print(f"Phase C: Association Sync from {cold_path}...")
    
    with get_connection(master_path) as master_conn:
        # Check total rows for progress calculation
        with get_connection(cold_path) as source_conn:
            total_rows = source_conn.execute("SELECT COUNT(*) FROM associations").fetchone()[0]
        
        if total_rows == 0:
            print("No associations found in source. Skipping.")
            return

        print(f"Total associations to process: {total_rows:,}")
        
        master_conn.execute(f"ATTACH DATABASE '{cold_path}' AS source")
        
        source_cols = [row[1] for row in master_conn.execute("PRAGMA source.table_info(associations)").fetchall()]
        master_cols = [row[1] for row in master_conn.execute("PRAGMA table_info(associations)").fetchall()]
        common_cols = [col for col in source_cols if col in master_cols]
        col_list = ", ".join(common_cols)
        
        chunk_size = 100000
        offset = 0
        
        print(f"Inserting associations in chunks of {chunk_size:,}...")
        
        while offset < total_rows:
            master_conn.execute("BEGIN TRANSACTION")
            query = f"""
                INSERT OR IGNORE INTO associations ({col_list}) 
                SELECT {col_list} FROM source.associations 
                LIMIT {chunk_size} OFFSET {offset}
            """
            master_conn.execute(query)
            master_conn.commit()
            
            offset += chunk_size
            progress = min(100.0, (offset / total_rows) * 100)
            # Using \r to update the same line
            sys.stdout.write(f"\rProgress: [{progress:6.2f}%] - {min(offset, total_rows):,}/{total_rows:,} rows merged")
            sys.stdout.flush()
            
        print("\nPhase C completed.")
        master_conn.execute("DETACH DATABASE source")

if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(description="Consolidate Whitemagic databases.")
    parser.add_argument("--phase", choices=["lite", "heavy", "c"], default="lite", help="Phase to run: lite (A+B), heavy (A+B+C), or c (C only)")
    args = parser.parse_args()

    MASTER_PATH = "/home/lucas/Desktop/whitemagic_master_lite.db"
    SSD_DB = "/home/lucas/.whitemagic/memory/whitemagic.db"
    
    # Paths for cold storage on SD and local SSD staging
    COLD_DB_SD = "/media/lucas/3C44-E4B5/WM/WM16/whitemagic_cold.db"
    COLD_DB_SSD = "/home/lucas/Desktop/whitemagic_cold_staging.db"
    
    # For Phase A/B, we use what's available. 
    # Since we deleted WM_SALVAGE, we might need to point back to SD or re-salvage if needed.
    # But Phase A/B is already done for the Lite DB.
    
    if args.phase == "lite":
        # Note: This expects ARCHIVES to be valid. Since SALVAGE_DIR was deleted, 
        # this would need adjustment if re-running A/B.
        print("Phase A and B are already completed in the existing Lite DB.")
    
    if args.phase in ["heavy", "c"]:
        if not os.path.exists(COLD_DB_SSD):
            print(f"Staging Cold DB to SSD for faster processing...")
            import subprocess
            subprocess.run(["cp", COLD_DB_SD, COLD_DB_SSD], check=True)
            print("Staging complete.")
        
        phase_c_associations(MASTER_PATH, COLD_DB_SSD)
        
    with get_connection(MASTER_PATH) as conn:
        print(f"\nFinal Master DB Stats at {MASTER_PATH}:")
        print(f"Memories: {conn.execute('SELECT COUNT(*) FROM memories').fetchone()[0]:,}")
        print(f"Tags: {conn.execute('SELECT COUNT(*) FROM tags').fetchone()[0]:,}")
        print(f"Associations: {conn.execute('SELECT COUNT(*) FROM associations').fetchone()[0]:,}")
