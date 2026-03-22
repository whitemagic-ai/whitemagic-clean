#!/bin/bash
# Test a single MCP tool call with full debug output

set -e

echo "🧪 Single Tool Test with Debug"
echo "=============================="
echo ""

if [ ! -f "dist/index.js" ]; then
    echo "Building..."
    npx tsc
    echo ""
fi

# Test the simplest read-only tool
echo "Testing: mcp2_garden_health (simplest read tool)"
echo "------------------------------------------------"

WM_MCP_DEBUG=true timeout 10 bash -c '
{
  echo "{\"jsonrpc\":\"2.0\",\"id\":1,\"method\":\"initialize\",\"params\":{\"protocolVersion\":\"2024-11-05\",\"capabilities\":{},\"clientInfo\":{\"name\":\"test\",\"version\":\"1.0\"}}}"
  sleep 0.5
  echo "{\"jsonrpc\":\"2.0\",\"id\":2,\"method\":\"tools/call\",\"params\":{\"name\":\"mcp2_garden_health\",\"arguments\":{}}}"
  sleep 2
} | node dist/index.js 2>&1
' | tee tool_test.log

echo ""
echo "=============================="
echo "Log saved to: tool_test.log"
echo ""
echo "Look for:"
echo "  - [Tool Request] Tool: mcp2_garden_health"
echo "  - [CallTool] Success or FAILED"
echo "  - Any Python stderr errors"
