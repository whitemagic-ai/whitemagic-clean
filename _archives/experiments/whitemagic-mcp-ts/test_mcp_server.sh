#!/bin/bash
# Test MCP server startup

echo "Testing WhiteMagic MCP Server..."
echo ""

# Set environment
# Dynamic path resolution
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export WM_BASE_PATH="$(dirname "$SCRIPT_DIR")"
export WM_DEBUG="true"

echo "📂 Base Path: $WM_BASE_PATH"

# Test server can start
echo "1. Testing server startup..."
timeout 2 node "$SCRIPT_DIR/dist/index.js" <<EOF 2>&1 | head -50
{"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2024-11-05","capabilities":{},"clientInfo":{"name":"test","version":"1.0"}}}
EOF

echo ""
echo "2. Checking dist/index.js exists..."
ls -lh "$SCRIPT_DIR/dist/index.js"

echo ""
echo "3. Checking if executable..."
head -1 "$SCRIPT_DIR/dist/index.js"

echo ""
echo "✅ If you see JSON-RPC responses above, the server is working!"
echo "📝 Next step: Reload Windsurf window to reconnect MCP servers"
