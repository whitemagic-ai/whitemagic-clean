#!/usr/bin/env python3
"""
Extract and Rank Buried Feature Requests — V007 Campaign
==========================================================
Deploy officer delegates to extract feature requests from:
- 140+ session handoffs in _aria/sessions/
- Archived strategy docs in _archives/docs/
- GAS document and other research in DB
- All memories tagged with improvement/enhancement/suggestion

Strategy:
1. Scan all session handoffs for feature mentions
2. Query DB for feature-related memories
3. Extract actionable items from each source
4. Cross-reference with current codebase
5. Rank by impact, effort, and relevance
6. Generate prioritized feature backlog
"""

import json
import re
from collections import defaultdict
from datetime import datetime
from pathlib import Path

# Feature extraction patterns
FEATURE_PATTERNS = [
    r'(?:TODO|FIXME|HACK|XXX):\s*(.+)',
    r'(?:feature|enhancement|improvement|suggestion):\s*(.+)',
    r'(?:should|could|would be|need to)\s+(?:add|implement|create|build)\s+(.+)',
    r'(?:missing|lacking|absent):\s*(.+)',
    r'(?:future|next|upcoming)\s+(?:work|feature|enhancement):\s*(.+)',
    r'(?:planned|proposed|discussed):\s*(.+)',
]

# Priority keywords
HIGH_PRIORITY = ['critical', 'urgent', 'blocking', 'security', 'performance', 'bug']
MEDIUM_PRIORITY = ['important', 'useful', 'helpful', 'enhancement', 'improvement']
LOW_PRIORITY = ['nice to have', 'optional', 'future', 'someday', 'maybe']


class FeatureExtractor:
    """Extract and rank buried feature requests from various sources."""

    def __init__(self):
        self.features = []
        self.sources = defaultdict(list)

    def extract_from_file(self, filepath: Path) -> list[dict]:
        """Extract features from a markdown file."""
        if not filepath.exists():
            return []

        content = filepath.read_text(encoding='utf-8', errors='ignore')
        features = []

        for pattern in FEATURE_PATTERNS:
            matches = re.finditer(pattern, content, re.IGNORECASE | re.MULTILINE)
            for match in matches:
                feature_text = match.group(1).strip()
                if len(feature_text) > 10:  # Skip very short matches
                    features.append({
                        'text': feature_text,
                        'source': str(filepath),
                        'source_type': 'file',
                        'pattern': pattern,
                        'priority': self._estimate_priority(feature_text)
                    })

        return features

    def extract_from_memory(self, memory: dict) -> list[dict]:
        """Extract features from a memory object."""
        content = memory.get('content', '')
        features = []

        for pattern in FEATURE_PATTERNS:
            matches = re.finditer(pattern, content, re.IGNORECASE | re.MULTILINE)
            for match in matches:
                feature_text = match.group(1).strip()
                if len(feature_text) > 10:
                    features.append({
                        'text': feature_text,
                        'source': memory.get('id', 'unknown'),
                        'source_type': 'memory',
                        'pattern': pattern,
                        'priority': self._estimate_priority(feature_text),
                        'memory_title': memory.get('title', '')[:100]
                    })

        return features

    def _estimate_priority(self, text: str) -> str:
        """Estimate priority based on keywords."""
        text_lower = text.lower()

        for keyword in HIGH_PRIORITY:
            if keyword in text_lower:
                return 'high'

        for keyword in MEDIUM_PRIORITY:
            if keyword in text_lower:
                return 'medium'

        for keyword in LOW_PRIORITY:
            if keyword in text_lower:
                return 'low'

        return 'medium'  # Default

    def scan_session_handoffs(self, sessions_dir: Path) -> int:
        """Scan all session handoff files."""
        if not sessions_dir.exists():
            print(f"⚠️  Sessions directory not found: {sessions_dir}")
            return 0

        count = 0
        for filepath in sessions_dir.glob('*.md'):
            features = self.extract_from_file(filepath)
            self.features.extend(features)
            self.sources['session_handoffs'].extend(features)
            count += len(features)

        return count

    def scan_archived_docs(self, archives_dir: Path) -> int:
        """Scan archived strategy documents."""
        if not archives_dir.exists():
            print(f"⚠️  Archives directory not found: {archives_dir}")
            return 0

        count = 0
        for filepath in archives_dir.rglob('*.md'):
            features = self.extract_from_file(filepath)
            self.features.extend(features)
            self.sources['archived_docs'].extend(features)
            count += len(features)

        return count

    def process_memories(self, memories: list[dict]) -> int:
        """Process feature-related memories."""
        count = 0
        for memory in memories:
            features = self.extract_from_memory(memory)
            self.features.extend(features)
            self.sources['memories'].extend(features)
            count += len(features)

        return count

    def deduplicate(self):
        """Remove duplicate features based on text similarity."""
        seen = set()
        unique_features = []

        for feature in self.features:
            # Normalize text for comparison
            normalized = re.sub(r'\s+', ' ', feature['text'].lower()).strip()

            if normalized not in seen:
                seen.add(normalized)
                unique_features.append(feature)

        original_count = len(self.features)
        self.features = unique_features

        return original_count - len(unique_features)

    def rank_features(self) -> list[dict]:
        """Rank features by priority and impact."""
        # Priority scores
        priority_scores = {'high': 3, 'medium': 2, 'low': 1}

        # Add ranking score
        for feature in self.features:
            score = priority_scores.get(feature['priority'], 2)

            # Boost score for certain keywords
            text_lower = feature['text'].lower()
            if 'performance' in text_lower or 'speed' in text_lower:
                score += 2
            if 'security' in text_lower or 'vulnerability' in text_lower:
                score += 3
            if 'bug' in text_lower or 'fix' in text_lower:
                score += 2
            if 'user' in text_lower or 'ux' in text_lower:
                score += 1

            feature['rank_score'] = score

        # Sort by score descending
        ranked = sorted(self.features, key=lambda f: f['rank_score'], reverse=True)

        return ranked

    def generate_report(self, output_path: Path):
        """Generate comprehensive feature backlog report."""
        ranked = self.rank_features()

        report = []
        report.append("# 🏛️ Archaeological Feature Extraction Report")
        report.append(f"**Generated**: {datetime.now().isoformat()}")
        report.append("**Campaign**: V007 - Archaeological Deep Dig")
        report.append("")
        report.append("---")
        report.append("")

        # Summary
        report.append("## 📊 Summary")
        report.append("")
        report.append(f"- **Total Features Extracted**: {len(self.features)}")
        report.append(f"- **From Session Handoffs**: {len(self.sources['session_handoffs'])}")
        report.append(f"- **From Archived Docs**: {len(self.sources['archived_docs'])}")
        report.append(f"- **From Memories**: {len(self.sources['memories'])}")
        report.append("")

        # Priority breakdown
        priority_counts = defaultdict(int)
        for f in self.features:
            priority_counts[f['priority']] += 1

        report.append("### Priority Breakdown")
        report.append("")
        report.append(f"- 🔴 **High Priority**: {priority_counts['high']}")
        report.append(f"- 🟡 **Medium Priority**: {priority_counts['medium']}")
        report.append(f"- 🟢 **Low Priority**: {priority_counts['low']}")
        report.append("")
        report.append("---")
        report.append("")

        # Top 50 features
        report.append("## 🎯 Top 50 Prioritized Features")
        report.append("")

        for idx, feature in enumerate(ranked[:50], 1):
            priority_emoji = {'high': '🔴', 'medium': '🟡', 'low': '🟢'}.get(feature['priority'], '⚪')

            report.append(f"### {idx}. {priority_emoji} {feature['text'][:100]}")
            report.append("")
            report.append(f"- **Priority**: {feature['priority'].upper()}")
            report.append(f"- **Rank Score**: {feature['rank_score']}")
            report.append(f"- **Source Type**: {feature['source_type']}")

            if feature['source_type'] == 'memory':
                report.append(f"- **Memory**: {feature.get('memory_title', 'N/A')}")
            else:
                source_path = Path(feature['source'])
                report.append(f"- **File**: {source_path.name}")

            report.append("")

        # Save report
        output_path.write_text('\n'.join(report), encoding='utf-8')

        # Save JSON for programmatic access
        json_path = output_path.with_suffix('.json')
        json_data = {
            'generated_at': datetime.now().isoformat(),
            'total_features': len(self.features),
            'sources': {k: len(v) for k, v in self.sources.items()},
            'priority_counts': dict(priority_counts),
            'top_50': ranked[:50]
        }
        json_path.write_text(json.dumps(json_data, indent=2), encoding='utf-8')

        return len(ranked)


def main():
    """Main execution: extract and rank all buried features."""
    print("=" * 70)
    print("  V007: Archaeological Feature Extraction")
    print("=" * 70)
    print()

    extractor = FeatureExtractor()

    # Scan session handoffs
    print("🔍 Scanning session handoffs...")
    sessions_dir = Path.home() / "Desktop" / "aria-crystallized" / "sessions"
    if not sessions_dir.exists():
        sessions_dir = Path.home() / "Desktop" / "whitemagicdev" / "_aria" / "sessions"

    session_count = extractor.scan_session_handoffs(sessions_dir)
    print(f"  ✅ Extracted {session_count} features from session handoffs")

    # Scan archived docs
    print("\n🔍 Scanning archived documents...")
    archives_dir = Path.home() / "Desktop" / "whitemagicdev" / "_archives" / "docs"
    archived_count = extractor.scan_archived_docs(archives_dir)
    print(f"  ✅ Extracted {archived_count} features from archived docs")

    # Load memories from previous search
    print("\n🔍 Processing feature-related memories...")
    # Note: In production, this would query the DB via MCP
    # For now, we'll use a placeholder
    memory_count = 0  # Would be populated from MCP search
    print(f"  ✅ Extracted {memory_count} features from memories")

    # Deduplicate
    print("\n🔧 Deduplicating features...")
    removed = extractor.deduplicate()
    print(f"  ✅ Removed {removed} duplicate features")

    # Generate report
    print("\n📝 Generating prioritized feature backlog...")
    output_path = Path.home() / "Desktop" / "whitemagicdev" / "reports" / "archaeological_features.md"
    output_path.parent.mkdir(parents=True, exist_ok=True)

    total_ranked = extractor.generate_report(output_path)

    print(f"  ✅ Generated report with {total_ranked} ranked features")
    print(f"  📁 Report saved to: {output_path}")
    print(f"  📁 JSON data saved to: {output_path.with_suffix('.json')}")

    print()
    print("=" * 70)
    print(f"✅ V007 COMPLETE: {total_ranked} features extracted and ranked")
    print("=" * 70)


if __name__ == "__main__":
    main()
