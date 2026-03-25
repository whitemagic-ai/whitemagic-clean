#!/usr/bin/env python3
"""Mine Windsurf Conversations - Extract Development Patterns

Mines Windsurf conversation history for:
- Development patterns
- Problem-solving approaches
- Optimization strategies
- Architectural decisions
- Code evolution patterns
"""

import sys
import json
import sqlite3
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

print("="*80)
print("WINDSURF CONVERSATION MINING - Development Pattern Extraction")
print("="*80)

# Locate Windsurf conversation database
windsurf_db = Path.home() / ".windsurf/conversations.db"
if not windsurf_db.exists():
    print(f"\n❌ Windsurf database not found: {windsurf_db}")
    print("   Trying alternative locations...")
    
    # Try alternative locations
    alt_locations = [
        Path.home() / ".config/windsurf/conversations.db",
        Path.home() / ".local/share/windsurf/conversations.db",
        Path.home() / "Library/Application Support/Windsurf/conversations.db",
    ]
    
    for alt in alt_locations:
        if alt.exists():
            windsurf_db = alt
            print(f"   ✅ Found at: {alt}")
            break
    else:
        print("\n   ⚠️  Could not find Windsurf database")
        print("   Will use WhiteMagic memory database as fallback")
        windsurf_db = None

# Pattern extraction
patterns = defaultdict(lambda: {
    'count': 0,
    'conversations': [],
    'contexts': [],
    'importance': 0.0,
})

# Keywords indicating development patterns
dev_keywords = {
    'rust': 0.9,
    'optimization': 0.9,
    'performance': 0.85,
    'speedup': 0.9,
    'refactor': 0.8,
    'architecture': 0.85,
    'pattern': 0.8,
    'algorithm': 0.85,
    'benchmark': 0.85,
    'parallel': 0.85,
    'concurrent': 0.85,
    'async': 0.8,
    'cache': 0.8,
    'memory': 0.75,
    'database': 0.75,
}

conversations_mined = 0
total_messages = 0

if windsurf_db and windsurf_db.exists():
    print("\n[1/3] Mining Windsurf conversation database...")
    print(f"   Database: {windsurf_db}")
    
    try:
        conn = sqlite3.connect(str(windsurf_db))
        cursor = conn.cursor()
        
        # Get conversation count
        cursor.execute("SELECT COUNT(*) FROM conversations")
        conv_count = cursor.fetchone()[0]
        print(f"   Total conversations: {conv_count}")
        
        # Get messages
        cursor.execute("""
            SELECT c.id, c.title, m.content, m.role
            FROM conversations c
            JOIN messages m ON c.id = m.conversation_id
            WHERE m.role IN ('user', 'assistant')
            ORDER BY c.created_at DESC, m.created_at ASC
        """)
        
        messages = cursor.fetchall()
        total_messages = len(messages)
        print(f"   Total messages: {total_messages}")
        
        # Extract patterns
        for conv_id, title, content, role in messages:
            if not content:
                continue
            
            content_lower = content.lower()
            
            # Check for development keywords
            for keyword, importance in dev_keywords.items():
                if keyword in content_lower:
                    patterns[keyword]['count'] += 1
                    patterns[keyword]['conversations'].append(conv_id)
                    
                    # Extract context (first 200 chars)
                    context = content.strip()[:200]
                    if context:
                        patterns[keyword]['contexts'].append(context)
                        patterns[keyword]['importance'] = max(
                            patterns[keyword]['importance'],
                            importance
                        )
        
        conversations_mined = conv_count
        conn.close()
        
    except Exception as e:
        print(f"   ⚠️  Error reading Windsurf database: {e}")
        print("   Falling back to WhiteMagic memory...")
        windsurf_db = None

# Fallback: Use WhiteMagic memory database
if not windsurf_db or conversations_mined == 0:
    print("\n[1/3] Mining WhiteMagic memory for Windsurf-related content...")
    
    wm_db = Path.home() / ".whitemagic/memory/whitemagic.db"
    if not wm_db.exists():
        print(f"   ⚠️  WhiteMagic database not found: {wm_db}")
    else:
        try:
            conn = sqlite3.connect(str(wm_db))
            cursor = conn.cursor()
            
            # Search for Windsurf-related memories
            cursor.execute("""
                SELECT id, content, tags
                FROM memories
                WHERE content LIKE '%windsurf%'
                   OR content LIKE '%conversation%'
                   OR tags LIKE '%windsurf%'
                ORDER BY created_at DESC
            """)
            
            memories = cursor.fetchall()
            print(f"   Found {len(memories)} Windsurf-related memories")
            
            for mem_id, content, tags in memories:
                if not content:
                    continue
                
                content_lower = content.lower()
                
                for keyword, importance in dev_keywords.items():
                    if keyword in content_lower:
                        patterns[keyword]['count'] += 1
                        patterns[keyword]['conversations'].append(mem_id)
                        
                        context = content.strip()[:200]
                        if context:
                            patterns[keyword]['contexts'].append(context)
                            patterns[keyword]['importance'] = max(
                                patterns[keyword]['importance'],
                                importance
                            )
            
            conversations_mined = len(memories)
            total_messages = len(memories)
            conn.close()
            
        except Exception as e:
            print(f"   ⚠️  Error reading WhiteMagic database: {e}")

print(f"\n  Processed {total_messages:,} messages from {conversations_mined} conversations")
print(f"  Found {len(patterns)} unique patterns")

# Analyze patterns
print("\n[2/3] Analyzing patterns...")

scored_patterns = []
for keyword, data in patterns.items():
    # Score based on frequency, conversation spread, and importance
    conv_spread = len(set(data['conversations']))
    frequency_score = min(data['count'] / 10.0, 1.0)
    spread_score = min(conv_spread / 5.0, 1.0)
    
    final_score = (
        0.4 * spread_score +
        0.3 * data['importance'] +
        0.3 * frequency_score
    )
    
    scored_patterns.append({
        'keyword': keyword,
        'count': data['count'],
        'conv_spread': conv_spread,
        'importance': data['importance'],
        'final_score': final_score,
        'sample_contexts': data['contexts'][:3],
    })

scored_patterns.sort(key=lambda x: x['final_score'], reverse=True)

print("\n  Top 15 patterns by score:")
for i, pattern in enumerate(scored_patterns[:15], 1):
    print(f"    {i:2d}. {pattern['keyword']:15s}: score={pattern['final_score']:.2%}, "
          f"count={pattern['count']:3d}, convs={pattern['conv_spread']:2d}")

# Prepare cross-validation data
print("\n[3/3] Preparing cross-validation data...")

cross_validated_tags = {}
for pattern in scored_patterns:
    if pattern['final_score'] >= 0.5:
        cross_validated_tags[pattern['keyword']] = {
            'cluster_count': pattern['conv_spread'],
            'total_size': pattern['count'],
            'avg_importance': pattern['importance'],
            'source': 'windsurf_conversations',
        }

print(f"\nPatterns for cross-validation: {len(cross_validated_tags)}")

# Save results
output_dir = ROOT / "reports"
output_dir.mkdir(exist_ok=True)

results = {
    'timestamp': __import__('time').strftime("%Y-%m-%d %H:%M:%S"),
    'source': 'windsurf_conversations',
    'conversations_processed': conversations_mined,
    'total_messages': total_messages,
    'patterns_found': len(patterns),
    'cross_validated_tags': cross_validated_tags,
    'top_15_patterns': [
        {
            'keyword': p['keyword'],
            'count': p['count'],
            'conv_spread': p['conv_spread'],
            'importance': p['importance'],
            'final_score': p['final_score'],
            'sample_contexts': p['sample_contexts'],
        }
        for p in scored_patterns[:15]
    ],
}

output_file = output_dir / "windsurf_conversation_mining_results.json"
with open(output_file, 'w') as f:
    json.dump(results, f, indent=2)

print(f"\n💾 Results saved to: {output_file}")

print(f"\n{'='*80}")
print("✅ WINDSURF CONVERSATION MINING COMPLETE")
print("Ready for cross-validation with other sources")
print(f"{'='*80}")
