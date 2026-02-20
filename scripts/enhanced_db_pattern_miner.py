#!/usr/bin/env python3
"""
Enhanced DB Pattern Miner
Mines patterns from WhiteMagic databases and geneseed vault for better code generation
"""

import sqlite3
from pathlib import Path
from typing import Dict, List, Any
from collections import defaultdict
import json

class EnhancedDBPatternMiner:
    """Mines patterns from multiple WhiteMagic databases"""
    
    def __init__(self, base_path: Path):
        self.base_path = base_path
        self.patterns = defaultdict(list)
        self.db_paths = self._find_databases()
    
    def _find_databases(self) -> List[Path]:
        """Find all WhiteMagic databases"""
        dbs = []
        
        # Main DB
        main_db = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"
        if main_db.exists():
            dbs.append(main_db)
        
        # Project DB
        project_db = self.base_path / "whitemagic" / "memory" / "whitemagic.db"
        if project_db.exists():
            dbs.append(project_db)
        
        # Archive DBs
        archive_dir = self.base_path.parent / "whitemagic_memory_archive"
        if archive_dir.exists():
            for db_file in archive_dir.glob("*.db"):
                dbs.append(db_file)
        
        return dbs
    
    def mine_all_databases(self):
        """Mine patterns from all databases"""
        print("\n" + "="*70)
        print("🔍 ENHANCED DB PATTERN MINING")
        print("="*70)
        
        print(f"\nFound {len(self.db_paths)} databases to mine")
        
        for db_path in self.db_paths:
            print(f"\n📊 Mining {db_path.name}...")
            self._mine_database(db_path)
        
        self._analyze_patterns()
    
    def _mine_database(self, db_path: Path):
        """Mine patterns from a single database"""
        try:
            conn = sqlite3.connect(str(db_path))
            cursor = conn.cursor()
            
            # Get memory content
            cursor.execute("""
                SELECT content, tags, title 
                FROM memories 
                WHERE content IS NOT NULL 
                LIMIT 1000
            """)
            
            memories = cursor.fetchall()
            
            for content, tags, title in memories:
                # Extract code patterns
                if 'rust' in content.lower() or 'impl' in content:
                    self.patterns['rust_code'].append({
                        'content': content[:500],
                        'tags': tags,
                        'title': title
                    })
                
                # Extract performance patterns
                if 'speedup' in content.lower() or 'performance' in content.lower():
                    self.patterns['performance'].append({
                        'content': content[:500],
                        'tags': tags,
                        'title': title
                    })
                
                # Extract algorithm patterns
                if any(word in content.lower() for word in ['algorithm', 'search', 'sort', 'graph']):
                    self.patterns['algorithms'].append({
                        'content': content[:500],
                        'tags': tags,
                        'title': title
                    })
                
                # Extract optimization patterns
                if any(word in content.lower() for word in ['optimize', 'parallel', 'async', 'cache']):
                    self.patterns['optimization'].append({
                        'content': content[:500],
                        'tags': tags,
                        'title': title
                    })
            
            conn.close()
            
            print(f"  Found {len(memories)} memories")
            
        except Exception as e:
            print(f"  Error mining {db_path.name}: {e}")
    
    def _analyze_patterns(self):
        """Analyze mined patterns"""
        print("\n" + "="*70)
        print("📊 PATTERN ANALYSIS")
        print("="*70)
        
        for category, patterns in sorted(self.patterns.items(), key=lambda x: len(x[1]), reverse=True):
            print(f"\n{category.upper()}: {len(patterns)} patterns")
            
            # Show top 3
            for i, pattern in enumerate(patterns[:3], 1):
                title = pattern.get('title', 'Untitled')
                print(f"  {i}. {title[:60]}")
    
    def export_patterns(self) -> Dict[str, Any]:
        """Export patterns for clone army"""
        export = {
            'total_patterns': sum(len(p) for p in self.patterns.values()),
            'categories': {k: len(v) for k, v in self.patterns.items()},
            'patterns': dict(self.patterns)
        }
        
        # Save to file
        export_path = self.base_path / "geneseed" / "db_patterns.json"
        export_path.parent.mkdir(parents=True, exist_ok=True)
        
        with open(export_path, 'w') as f:
            json.dump(export, f, indent=2, default=str)
        
        print(f"\n💾 Patterns exported to {export_path}")
        
        return export

def main():
    """Mine patterns from databases"""
    base_path = Path(__file__).parent.parent
    
    miner = EnhancedDBPatternMiner(base_path)
    miner.mine_all_databases()
    patterns = miner.export_patterns()
    
    print(f"\n✅ Pattern mining complete!")
    print(f"   Total patterns: {patterns['total_patterns']}")
    print(f"   Categories: {len(patterns['categories'])}")

if __name__ == '__main__':
    main()
