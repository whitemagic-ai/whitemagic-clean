#!/bin/bash
# Deploy shadow clone armies on S001-S004 campaigns with full monitoring
# S001: Yin-Yang & Zodiacal Round Synthesis
# S002: Ralph Loop Integration & Victory Condition Framework
# S003: Digital Phylogenetics & Evolutionary Agent Improvement
# S004: Kaizen Metrics & System-Wide Refinement

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
cd "$PROJECT_ROOT"

echo "========================================================================"
echo "  SHADOW CLONE DEPLOYMENT: S CAMPAIGNS (SYNTHESIS)"
echo "========================================================================"
echo ""
echo "Target Campaigns:"
echo "  - S001: Yin-Yang & Zodiacal Round Synthesis (9 VCs, 50K clones)"
echo "  - S002: Ralph Loop Integration (10 VCs, 30K clones)"
echo "  - S003: Digital Phylogenetics (11 VCs, 40K clones)"
echo "  - S004: Kaizen Metrics (12 VCs, 25K clones)"
echo ""
echo "Total: 42 VCs, 145K clones"
echo ""

# Run deployment with monitoring wrapper
.venv/bin/python scripts/deploy_with_monitoring.py \
    --campaigns \
    --time-limit 600 \
    --filter-codes S001,S002,S003,S004

echo ""
echo "========================================================================"
echo "  DEPLOYMENT COMPLETE"
echo "========================================================================"
