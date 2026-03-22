#!/bin/bash
# Restart WhiteMagic MCP Server
# Kills existing processes and rebuilds

echo "🔄 Restarting WhiteMagic MCP Server..."

# Kill existing MCP server processes
echo "Killing existing processes..."
pkill -f "whitemagic-mcp/dist/index.js" 2>/dev/null && echo "  ✅ Killed old MCP server" || echo "  ℹ️  No running MCP server found"

# Rebuild
echo "Rebuilding..."
cd "$(dirname "$0")"
npm run build

if [ $? -eq 0 ]; then
    echo "✅ Build successful!"
    echo ""
    echo "📊 Verifying tool count..."
    node -e "
    const { buildToolCatalog } = require('./dist/tools/catalog.js');
    buildToolCatalog().then(catalog => {
        console.log('Total tools:', catalog.totalCount);
        const names = catalog.tools.map(t => t.name);
        const dupes = names.filter((n, i) => names.indexOf(n) !== i);
        if (dupes.length > 0) {
            console.log('⚠️  Duplicates found:', dupes);
        } else {
            console.log('✅ No duplicates!');
        }
    }).catch(e => console.error('Error:', e.message));
    "
    echo ""
    echo "🎉 MCP server ready!"
    echo "Now restart Windsurf or toggle MCP tools off/on to reload"
else
    echo "❌ Build failed!"
    exit 1
fi
