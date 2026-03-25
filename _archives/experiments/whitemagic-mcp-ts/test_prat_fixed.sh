#!/bin/bash
# Test PRAT tools after fixes

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

export WM_BASE_PATH="$REPO_ROOT"
export WM_DEBUG="1"

echo "=== Testing prat_status ==="
echo '{"jsonrpc":"2.0","id":1,"method":"tools/call","params":{"name":"prat_status","arguments":{}}}' | node dist/index.js 2>&1 | tail -5

echo ""
echo "=== Testing prat_get_context ==="
echo '{"jsonrpc":"2.0","id":2,"method":"tools/call","params":{"name":"prat_get_context","arguments":{}}}' | node dist/index.js 2>&1 | tail -5

echo ""
echo "=== Testing prat_list_morphologies ==="
echo '{"jsonrpc":"2.0","id":3,"method":"tools/call","params":{"name":"prat_list_morphologies","arguments":{}}}' | node dist/index.js 2>&1 | tail -5

echo ""
echo "=== Testing prat_invoke ==="
echo '{"jsonrpc":"2.0","id":4,"method":"tools/call","params":{"name":"prat_invoke","arguments":{"target_tool":"recall","query":"PRAT","limit":5}}}' | node dist/index.js 2>&1 | tail -10

echo ""
echo "=== All tests complete ==="
