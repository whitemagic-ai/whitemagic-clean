/**
 * WhiteMagic MCP Tool Catalog
 */

import { readdir } from 'fs/promises';
import { join, dirname } from 'path';
import { fileURLToPath } from 'url';
import { getWhiteMagicTools } from './whitemagic_tools.js';
import { PRIMARY_TOOLS } from '../primary-tools.js';

// ES module compatibility
const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

export interface ToolDefinition {
  name: string;
  description: string;
  category: string;
  module: string;
  inputSchema: any;
}

export interface ToolCatalog {
  tools: ToolDefinition[];
  categories: Record<string, ToolDefinition[]>;
  totalCount: number;
  lastUpdated: string;
}

export async function buildToolCatalog(): Promise<ToolCatalog> {
  const tools: ToolDefinition[] = [];
  const categories: Record<string, ToolDefinition[]> = {};
  
  // Flag to serve minimal toolset (Mandala only)
  // Forcing true for Gemini stability as the user requested a robust solution
  const minimalMode = process.env.WM_MCP_MINIMAL !== 'false';
  
  // PRIMARY TOOLS (LIBRA Phase 7) - 28 consolidated tools
  // These are the "gateways" to the entire system (Ganas/Gardens)
  const primaryTools = PRIMARY_TOOLS.map(tool => ({
    name: tool.name,
    description: tool.description,
    category: tool.category,
    module: `${tool.quadrant}-${tool.element}`,
    inputSchema: tool.inputSchema
  }));
  tools.push(...primaryTools);
  
  // Core hardcoded tools (legacy support)
  const coreTools = getCoreTools();
  tools.push(...coreTools);
  
  if (!minimalMode) {
    // WhiteMagic-specific tools (legacy support)
    const wmTools = getWhiteMagicTools();
    tools.push(...wmTools);
    
    // ... rest of the code for loading generated tools
  }
  
  // Deduplicate tools by name (PRIMARY_TOOLS take precedence)
  const seenNames = new Set<string>();
  const uniqueTools: ToolDefinition[] = [];
  for (const tool of tools) {
    if (!seenNames.has(tool.name)) {
      seenNames.add(tool.name);
      uniqueTools.push(tool);
    }
  }
  
  // Organize by category
  for (const tool of uniqueTools) {
    if (!categories[tool.category]) {
      categories[tool.category] = [];
    }
    categories[tool.category].push(tool);
  }
  
  return {
    tools: uniqueTools,
    categories,
    totalCount: uniqueTools.length,
    lastUpdated: new Date().toISOString()
  };
}

function getCoreTools(): ToolDefinition[] {
  return [
    {
      name: 'create_memory',
      description: 'Create a new memory in WhiteMagic',
      category: 'memory',
      module: 'core',
      inputSchema: {
        type: 'object',
        properties: {
          title: { type: 'string', description: 'Memory title' },
          content: { type: 'string', description: 'Memory content' },
          tags: { type: 'array', items: { type: 'string' }, description: 'Tags' },
          garden: { type: 'string', description: 'Garden to store in' }
        },
        required: ['title', 'content']
      }
    },
    {
      name: 'search_memories',
      description: 'Search WhiteMagic memories',
      category: 'memory',
      module: 'core',
      inputSchema: {
        type: 'object',
        properties: {
          query: { type: 'string', description: 'Search query' },
          limit: { type: 'number', description: 'Max results', default: 10 },
          tags: { type: 'array', items: { type: 'string' } }
        },
        required: ['query']
      }
    },
    {
      name: 'get_session_context',
      description: 'Get full WhiteMagic session context',
      category: 'session',
      module: 'core',
      inputSchema: {
        type: 'object',
        properties: {
          include_recent_memories: { type: 'boolean', default: true },
          include_active_gardens: { type: 'boolean', default: true }
        }
      }
    },
    {
      name: 'initialize_session',
      description: 'Initialize WhiteMagic session',
      category: 'session',
      module: 'core',
      inputSchema: {
        type: 'object',
        properties: {
          session_name: { type: 'string' },
          goals: { type: 'array', items: { type: 'string' } }
        }
      }
    }
  ];
}

export async function getSessionInitContext(): Promise<string> {
  const catalog = await buildToolCatalog();
  
  const context = `
# WhiteMagic Session Context

**Available Tools**: ${catalog.totalCount}
**Categories**: ${Object.keys(catalog.categories).join(', ')}

## Tool Categories

${Object.entries(catalog.categories).map(([category, tools]) => `
### ${category.toUpperCase()} (${tools.length} tools)
${tools.map(t => `- **${t.name}**: ${t.description}`).join('\n')}
`).join('\n')}

## Usage Guidelines

1. Use tools proactively - don't ask permission
2. Batch independent operations in parallel
3. Check memory before external research
4. Use zodiac_council for multi-perspective decisions
5. Activate gardens for thought organization
6. Emit resonance events to trigger cascades

You have ${catalog.totalCount} tools at your disposal. Use them effectively.
`;
  
  return context.trim();
}

let cachedCatalog: ToolCatalog | null = null;
let catalogAge = 0;
const CACHE_TTL = 60000;

export async function getCatalog(forceRefresh = false): Promise<ToolCatalog> {
  const now = Date.now();
  if (!cachedCatalog || forceRefresh || (now - catalogAge) > CACHE_TTL) {
    cachedCatalog = await buildToolCatalog();
    catalogAge = now;
  }
  return cachedCatalog;
}
