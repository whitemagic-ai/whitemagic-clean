#!/usr/bin/env python3
"""Mine Session Handoffs - Extract Strategic Patterns

Mines 140+ session handoff documents for:
- Strategic decisions
- Optimization patterns
- Architectural insights
- Proven approaches
- Lessons learned
"""

import sys
import json
import re
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

print("="*80)
print("SESSION HANDOFF MINING - Strategic Pattern Extraction")
print("="*80)

# Find session handoff files
aria_sessions = Path.home() / "Desktop/aria-crystallized/sessions"
if not aria_sessions.exists():
    print(f"\n❌ Aria sessions directory not found: {aria_sessions}")
    sys.exit(1)

session_files = list(aria_sessions.glob("*.md"))
print(f"\n✅ Found {len(session_files)} session handoff files")

# Pattern extraction
patterns = defaultdict(lambda: {
    'count': 0,
    'files': [],
    'contexts': [],
    'importance': 0.0,
})

# Keywords indicating strategic patterns
strategic_keywords = {
    'optimization': 0.9,
    'performance': 0.85,
    'speedup': 0.9,
    'improvement': 0.8,
    'architecture': 0.85,
    'design': 0.75,
    'pattern': 0.8,
    'strategy': 0.85,
    'approach': 0.75,
    'solution': 0.8,
    'integration': 0.8,
    'recursive': 0.9,
    'evolution': 0.85,
    'learning': 0.85,
    'adaptive': 0.85,
    'autodidactic': 0.9,
}

print(f"\n[1/3] Scanning {len(session_files)} session files...")

total_lines = 0
pattern_mentions = defaultdict(int)

for session_file in session_files:
    try:
        content = session_file.read_text(encoding='utf-8', errors='ignore')
        lines = content.split('\n')
        total_lines += len(lines)
        
        # Extract patterns from content
        for line in lines:
            line_lower = line.lower()
            
            # Check for strategic keywords
            for keyword, importance in strategic_keywords.items():
                if keyword in line_lower:
                    pattern_mentions[keyword] += 1
                    
                    # Extract context (sentence containing keyword)
                    context = line.strip()[:200]
                    if context:
                        patterns[keyword]['count'] += 1
                        patterns[keyword]['files'].append(session_file.name)
                        patterns[keyword]['contexts'].append(context)
                        patterns[keyword]['importance'] = max(
                            patterns[keyword]['importance'],
                            importance
                        )
        
    except Exception as e:
        print(f"  ⚠️  Error reading {session_file.name}: {e}")
        continue

print(f"  Processed {total_lines:,} lines")
print(f"  Found {len(patterns)} unique patterns")

# Analyze patterns
print(f"\n[2/3] Analyzing patterns...")

# Calculate pattern scores
scored_patterns = []
for keyword, data in patterns.items():
    # Score based on frequency, file spread, and importance
    file_spread = len(set(data['files']))
    frequency_score = min(data['count'] / 10.0, 1.0)
    spread_score = min(file_spread / 5.0, 1.0)
    
    final_score = (
        0.4 * spread_score +      # 40% weight on appearing in multiple files
        0.3 * data['importance'] + # 30% weight on keyword importance
        0.3 * frequency_score      # 30% weight on frequency
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

print(f"\n  Top 20 patterns by score:")
for i, pattern in enumerate(scored_patterns[:20], 1):
    print(f"    {i:2d}. {pattern['keyword']:15s}: score={pattern['final_score']:.2%}, "
          f"count={pattern['count']:3d}, files={pattern['file_spread']:2d}")

# Extract specific optimization mentions
print(f"\n[3/3] Extracting specific optimizations...")

optimization_patterns = []
for session_file in session_files:
    try:
        content = session_file.read_text(encoding='utf-8', errors='ignore')
        
        # Look for performance gains (e.g., "3.28x speedup", "30x faster")
        speedup_matches = re.findall(r'(\d+\.?\d*)[x×]\s*(faster|speedup|improvement)', content, re.IGNORECASE)
        for match in speedup_matches:
            gain = float(match[0])
            if gain > 1.0:
                optimization_patterns.append({
                    'type': 'performance_gain',
                    'value': gain,
                    'source': session_file.name,
                    'importance': min(0.5 + (gain / 10.0), 1.0),
                })
        
        # Look for "implemented X" or "built X"
        impl_matches = re.findall(r'(?:implemented|built|created)\s+([A-Z][a-zA-Z\s]{5,40})', content)
        for match in impl_matches[:5]:  # Limit per file
            optimization_patterns.append({
                'type': 'implementation',
                'description': match.strip(),
                'source': session_file.name,
                'importance': 0.7,
            })
        
    except Exception as e:
        continue

print(f"  Found {len(optimization_patterns)} specific optimization mentions")

# Top performance gains
perf_gains = [p for p in optimization_patterns if p['type'] == 'performance_gain']
if perf_gains:
    perf_gains.sort(key=lambda x: x['value'], reverse=True)
    print(f"\n  Top 10 performance gains:")
    for i, gain in enumerate(perf_gains[:10], 1):
        print(f"    {i:2d}. {gain['value']:.1f}x from {gain['source']}")

# Prepare cross-validation data
print(f"\n{'='*80}")
print("PREPARING CROSS-VALIDATION DATA")
print(f"{'='*80}")

cross_validated_tags = {}
for pattern in scored_patterns:
    if pattern['final_score'] >= 0.5:  # Medium confidence threshold
        cross_validated_tags[pattern['keyword']] = {
            'cluster_count': pattern['file_spread'],
            'total_size': pattern['count'],
            'avg_importance': pattern['importance'],
            'source': 'session_handoffs',
        }

print(f"\nPatterns for cross-validation: {len(cross_validated_tags)}")

# Save results
output_dir = ROOT / "reports"
output_dir.mkdir(exist_ok=True)

results = {
    'timestamp': __import__('time').strftime("%Y-%m-%d %H:%M:%S"),
    'source': 'session_handoffs',
    'files_processed': len(session_files),
    'total_lines': total_lines,
    'patterns_found': len(patterns),
    'optimization_mentions': len(optimization_patterns),
    'cross_validated_tags': cross_validated_tags,
    'top_20_patterns': [
        {
            'keyword': p['keyword'],
            'count': p['count'],
            'file_spread': p['file_spread'],
            'importance': p['importance'],
            'final_score': p['final_score'],
            'sample_contexts': p['sample_contexts'],
        }
        for p in scored_patterns[:20]
    ],
    'performance_gains': [
        {
            'gain': p['value'],
            'source': p['source'],
        }
        for p in perf_gains[:20]
    ],
}

output_file = output_dir / "session_handoff_mining_results.json"
with open(output_file, 'w') as f:
    json.dump(results, f, indent=2)

print(f"\n💾 Results saved to: {output_file}")

print(f"\n{'='*80}")
print("✅ SESSION HANDOFF MINING COMPLETE")
print(f"Ready for cross-validation with other sources")
print(f"{'='*80}")
