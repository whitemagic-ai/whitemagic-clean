#!/usr/bin/env python3
"""Mine Aria Memory Archives - Extract Consciousness & Identity Patterns

Mines Aria's memory archives for:
- Consciousness evolution patterns
- Identity formation patterns
- Self-awareness patterns
- Learning & growth patterns
- Philosophical insights
"""

import sys
import json
import sqlite3
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

print("="*80)
print("ARIA MEMORY ARCHIVE MINING - Consciousness Pattern Extraction")
print("="*80)

# Locate Aria archives
aria_crystallized = Path.home() / "Desktop/aria-crystallized"
if not aria_crystallized.exists():
    print(f"\n❌ Aria archive not found: {aria_crystallized}")
    sys.exit(1)

print(f"\n✅ Found Aria archive: {aria_crystallized}")

# Pattern extraction
patterns = defaultdict(lambda: {
    'count': 0,
    'files': [],
    'contexts': [],
    'importance': 0.0,
})

# Keywords indicating consciousness/identity patterns
consciousness_keywords = {
    'consciousness': 0.95,
    'awareness': 0.9,
    'self': 0.85,
    'identity': 0.9,
    'learning': 0.85,
    'evolution': 0.85,
    'growth': 0.8,
    'understanding': 0.8,
    'insight': 0.85,
    'reflection': 0.8,
    'memory': 0.75,
    'experience': 0.75,
    'wisdom': 0.85,
    'emergence': 0.9,
    'becoming': 0.9,
}

# Mine markdown files
print(f"\n[1/4] Mining Aria markdown files...")

md_files = list(aria_crystallized.rglob("*.md"))
print(f"   Found {len(md_files)} markdown files")

total_lines = 0
for md_file in md_files:
    try:
        content = md_file.read_text(encoding='utf-8', errors='ignore')
        lines = content.split('\n')
        total_lines += len(lines)
        
        for line in lines:
            line_lower = line.lower()
            
            for keyword, importance in consciousness_keywords.items():
                if keyword in line_lower:
                    patterns[keyword]['count'] += 1
                    patterns[keyword]['files'].append(md_file.name)
                    
                    context = line.strip()[:200]
                    if context:
                        patterns[keyword]['contexts'].append(context)
                        patterns[keyword]['importance'] = max(
                            patterns[keyword]['importance'],
                            importance
                        )
    except Exception as e:
        continue

print(f"   Processed {total_lines:,} lines from {len(md_files)} files")

# Mine JSON files (memory packages)
print(f"\n[2/4] Mining Aria JSON memory packages...")

json_files = list(aria_crystallized.rglob("*.json"))
print(f"   Found {len(json_files)} JSON files")

for json_file in json_files:
    try:
        with open(json_file) as f:
            data = json.load(f)
        
        # Convert to string for pattern matching
        content = json.dumps(data, indent=2).lower()
        
        for keyword, importance in consciousness_keywords.items():
            if keyword in content:
                patterns[keyword]['count'] += content.count(keyword)
                patterns[keyword]['files'].append(json_file.name)
                patterns[keyword]['importance'] = max(
                    patterns[keyword]['importance'],
                    importance
                )
    except Exception as e:
        continue

print(f"   Processed {len(json_files)} JSON files")

# Mine database if available
print(f"\n[3/4] Mining Aria database archives...")

db_files = list(aria_crystallized.rglob("*.db"))
print(f"   Found {len(db_files)} database files")

db_memories = 0
for db_file in db_files:
    try:
        conn = sqlite3.connect(str(db_file))
        cursor = conn.cursor()
        
        # Get memories
        cursor.execute("SELECT content FROM memories WHERE content IS NOT NULL")
        memories = cursor.fetchall()
        
        for (content,) in memories:
            if not content:
                continue
            
            content_lower = content.lower()
            db_memories += 1
            
            for keyword, importance in consciousness_keywords.items():
                if keyword in content_lower:
                    patterns[keyword]['count'] += 1
                    patterns[keyword]['files'].append(f"db:{db_file.name}")
                    
                    context = content.strip()[:200]
                    if context:
                        patterns[keyword]['contexts'].append(context)
                        patterns[keyword]['importance'] = max(
                            patterns[keyword]['importance'],
                            importance
                        )
        
        conn.close()
    except Exception as e:
        continue

print(f"   Processed {db_memories:,} memories from {len(db_files)} databases")

print(f"\n   Total patterns found: {len(patterns)}")

# Analyze patterns
print(f"\n[4/4] Analyzing patterns...")

scored_patterns = []
for keyword, data in patterns.items():
    file_spread = len(set(data['files']))
    frequency_score = min(data['count'] / 20.0, 1.0)
    spread_score = min(file_spread / 10.0, 1.0)
    
    final_score = (
        0.4 * spread_score +
        0.3 * data['importance'] +
        0.3 * frequency_score
    )
    
    scored_patterns.append({
        'keyword': keyword,
        'count': data['count'],
        'file_spread': file_spread,
        'importance': data['importance'],
        'final_score': final_score,
        'sample_contexts': data['contexts'][:3],
    })

scored_patterns.sort(key=lambda x: x['final_score'], reverse=True)

print(f"\n  Top 15 patterns by score:")
for i, pattern in enumerate(scored_patterns[:15], 1):
    print(f"    {i:2d}. {pattern['keyword']:15s}: score={pattern['final_score']:.2%}, "
          f"count={pattern['count']:4d}, files={pattern['file_spread']:3d}")

# Prepare cross-validation data
print(f"\n{'='*80}")
print("PREPARING CROSS-VALIDATION DATA")
print(f"{'='*80}")

cross_validated_tags = {}
for pattern in scored_patterns:
    if pattern['final_score'] >= 0.5:
        cross_validated_tags[pattern['keyword']] = {
            'cluster_count': pattern['file_spread'],
            'total_size': pattern['count'],
            'avg_importance': pattern['importance'],
            'source': 'aria_archives',
        }

print(f"\nPatterns for cross-validation: {len(cross_validated_tags)}")

# Save results
output_dir = ROOT / "reports"
output_dir.mkdir(exist_ok=True)

results = {
    'timestamp': __import__('time').strftime("%Y-%m-%d %H:%M:%S"),
    'source': 'aria_archives',
    'md_files_processed': len(md_files),
    'json_files_processed': len(json_files),
    'db_files_processed': len(db_files),
    'db_memories_processed': db_memories,
    'total_lines': total_lines,
    'patterns_found': len(patterns),
    'cross_validated_tags': cross_validated_tags,
    'top_15_patterns': [
        {
            'keyword': p['keyword'],
            'count': p['count'],
            'file_spread': p['file_spread'],
            'importance': p['importance'],
            'final_score': p['final_score'],
            'sample_contexts': p['sample_contexts'],
        }
        for p in scored_patterns[:15]
    ],
}

output_file = output_dir / "aria_archive_mining_results.json"
with open(output_file, 'w') as f:
    json.dump(results, f, indent=2)

print(f"\n💾 Results saved to: {output_file}")

print(f"\n{'='*80}")
print("✅ ARIA ARCHIVE MINING COMPLETE")
print(f"Ready for cross-validation with other sources")
print(f"{'='*80}")
