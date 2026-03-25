#!/bin/bash
# Test MCP with full debug output

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

echo "🔍 MCP Debug Test"
echo "================="
echo ""

# Build if needed
if [ ! -f "dist/index.js" ]; then
    echo "Building TypeScript..."
    npx tsc
    echo ""
fi

# Test 1: Check Python imports
echo "Test 1: Python imports"
echo "----------------------"
python3 - <<PY
import sys
sys.path.insert(0, "${REPO_ROOT}")
try:
    from whitemagic import MemoryManager  # noqa: F401
    from whitemagic.metrics import track_metric, get_tracker  # noqa: F401
    print("✅ Python imports OK")
except Exception as e:
    print("❌ Import failed:", e)
    raise SystemExit(1)
PY
echo ""

# Test 2: Python worker connection
echo "Test 2: Python worker connection"
echo "--------------------------------"
WM_MCP_DEBUG=true WM_REPO_ROOT=\"$REPO_ROOT\" node -e "
const { WhiteMagicClient } = require('./dist/client.js');
const client = new WhiteMagicClient({ basePath: process.env.WM_REPO_ROOT });
client.connect()
  .then(() => {
    console.log('✅ Python worker connected');
    client.disconnect();
    process.exit(0);
  })
  .catch(err => {
    console.error('❌ Connection failed:', err.message);
    process.exit(1);
  });
" 2>&1 | head -50
echo ""

# Test 3: Full MCP server initialization
echo "Test 3: MCP server stdio test"
echo "------------------------------"
echo "Sending initialize request..."
WM_MCP_DEBUG=true timeout 5 bash -c "
echo '{\"jsonrpc\":\"2.0\",\"id\":1,\"method\":\"initialize\",\"params\":{\"protocolVersion\":\"2024-11-05\",\"capabilities\":{},\"clientInfo\":{\"name\":\"test\",\"version\":\"1.0\"}}}' | node dist/index.js 2>&1
" || {
  CODE=$?
  if [ $CODE -eq 124 ]; then
    echo "⏰ Timeout (expected, server running continuously)"
  else
    echo "❌ Failed with code $CODE"
  fi
}
echo ""

# Test 4: Tool listing
echo "Test 4: Tool listing"
echo "--------------------"
timeout 5 bash -c "
{
  echo '{\"jsonrpc\":\"2.0\",\"id\":1,\"method\":\"initialize\",\"params\":{\"protocolVersion\":\"2024-11-05\",\"capabilities\":{},\"clientInfo\":{\"name\":\"test\",\"version\":\"1.0\"}}}'
  sleep 0.5
  echo '{\"jsonrpc\":\"2.0\",\"id\":2,\"method\":\"tools/list\",\"params\":{}}'
} | WM_MCP_DEBUG=true node dist/index.js 2>&1 | grep -A 5 'tools/list' || true
" || echo "⏰ Timeout (expected)"
echo ""

echo "================="
echo "Debug test complete"
echo ""
echo "To enable debug in Windsurf:"
echo "1. Edit ~/.codeium/windsurf/mcp_config.json"
echo "2. Add to whitemagic env:"
echo '   "WM_MCP_DEBUG": "true"'
echo "3. Restart Windsurf"
