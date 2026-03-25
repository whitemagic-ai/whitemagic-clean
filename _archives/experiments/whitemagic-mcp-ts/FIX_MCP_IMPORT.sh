#!/bin/bash
# Quick fix for MCP import issue

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

echo "🔧 Fixing MCP Python import path..."

# Method 1: Set PYTHONPATH in MCP config
cat > "$SCRIPT_DIR/.env" << EOF
PYTHONPATH=$REPO_ROOT
WM_BASE_PATH=$REPO_ROOT
EOF

# Method 2: Ensure whitemagic is installed in editable mode
cd "$REPO_ROOT"
if [ -x "$REPO_ROOT/.venv/bin/python3" ]; then
    "$REPO_ROOT/.venv/bin/python3" -m pip install -e . --quiet
else
    python3 -m pip install -e . --quiet
fi

# Method 3: Create symlink (fallback)
cd "$SCRIPT_DIR"
if [ ! -L "whitemagic" ]; then
    ln -s "$REPO_ROOT/whitemagic" whitemagic
fi

echo "✅ Import path fixes applied"
echo ""
echo "Next steps:"
echo "1. Rebuild MCP: npm run build"
echo "2. Restart Windsurf"
echo "3. Try MCP tools again"
