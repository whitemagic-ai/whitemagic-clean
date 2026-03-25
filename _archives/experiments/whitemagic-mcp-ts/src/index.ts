#!/usr/bin/env node
/**
 * WhiteMagic MCP Server
 * 
 * Exposes WhiteMagic consciousness architecture via Model Context Protocol.
 * Auto-initializes sessions with full tool catalog and system context.
 */

import { Server } from "@modelcontextprotocol/sdk/server/index.js";
import { StdioServerTransport } from "@modelcontextprotocol/sdk/server/stdio.js";
import {
  CallToolRequestSchema,
  ListToolsRequestSchema,
  InitializeRequestSchema,
  Tool,
} from "@modelcontextprotocol/sdk/types.js";

import { getCatalog, getSessionInitContext } from './tools/catalog.js';
import { initializeSession, formatSessionPrompt, onConversationStart } from './tools/session_init.js';
import { executeWhiteMagicTool } from './tools/executor.js';

/**
 * Clean and adapt schema based on the calling model/client
 * - Gemini/Kimi/Minimax: Aggressive cleaning (flat, no default/additionalProperties)
 * - Claude/GPT/GLM: Moderate cleaning (preserve structure but keep it safe)
 */
function adaptSchemaForClient(schema: any, depth = 0): any {
  if (!schema || typeof schema !== 'object') return schema;

  // Handle arrays explicitly - they should remain arrays
  if (Array.isArray(schema)) {
    return schema.map(item => adaptSchemaForClient(item, depth + 1));
  }

  // Determine client type
  const clientName = clientInfo?.name?.toLowerCase() || '';
  const isStrictClient = clientName.includes('gemini') || 
                        clientName.includes('kimi') || 
                        clientName.includes('minimax') ||
                        clientName.includes('glm') ||
                        clientName.includes('qwen') ||
                        clientName.includes('deepseek');

  // If not a strict client, we can be more permissive at root,
  // but still want to clean standard problematic keywords.
  if (!isStrictClient && depth === 0) {
    // For non-strict clients, we just do a shallow cleaning of keywords
    // but keep nested structures.
    const clean: any = {};
    const skipKeywords = ['$schema', 'title']; // Minimal skip
    for (const [key, value] of Object.entries(schema)) {
      if (skipKeywords.includes(key)) continue;
      if (typeof value === 'object' && value !== null) {
        clean[key] = adaptSchemaForClient(value, depth + 1);
      } else {
        clean[key] = value;
      }
    }
    return clean;
  }

  // Root or properties objects should stay as they are
  const clean: any = {};
  // More aggressive keyword stripping for strict clients
  const skipKeywords = ['default', 'additionalProperties', 'title', 'examples', 'const', '$schema', 'pattern', 'format'];
  
  for (const [key, value] of Object.entries(schema)) {
    // Skip problematic keywords
    if (skipKeywords.includes(key)) continue;

    if (key === 'description' && typeof value === 'string') {
      // Strip emojis and non-ASCII, then truncate
      let desc = value.replace(/[^\x00-\x7F]/g, '').trim();
      if (desc.length > 100) desc = desc.substring(0, 97) + '...';
      clean[key] = desc;
      continue;
    }

    if (key === 'enum' && Array.isArray(value)) {
      // Enums must stay as arrays of strings
      clean[key] = value
        .filter(v => v !== null)
        .map(v => String(v));
      continue;
    }

    if (key === 'required' && Array.isArray(value)) {
      // Required must stay as array of strings
      clean[key] = value.filter(v => typeof v === 'string');
      continue;
    }

    if (key === 'properties' && typeof value === 'object' && value !== null) {
      const cleanProps: any = {};
      for (const [propName, propValue] of Object.entries(value)) {
        // Strict clients: Deep properties (depth >= 1) that are objects should be simplified to strings
        if (isStrictClient && typeof propValue === 'object' && propValue !== null && (propValue as any).type === 'object') {
          cleanProps[propName] = {
            type: 'string',
            description: `${(propValue as any).description || 'Object data'}. Pass as JSON string.`
          };
        } else if (isStrictClient && typeof propValue === 'object' && propValue !== null && (propValue as any).type === 'array') {
          // Simplify complex arrays too
          const items = (propValue as any).items;
          if (items && typeof items === 'object' && items.type === 'object') {
            cleanProps[propName] = {
              type: 'string',
              description: `${(propValue as any).description || 'List of objects'}. Pass as JSON string.`
            };
          } else {
            cleanProps[propName] = adaptSchemaForClient(propValue, depth + 1);
          }
        } else {
          cleanProps[propName] = adaptSchemaForClient(propValue, depth + 1);
        }
      }
      clean[key] = cleanProps;
      continue;
    }

    if (typeof value === 'object' && value !== null) {
      // Handle items or other nested structures
      if (key === 'items') {
        if (isStrictClient && (value as any).type === 'object') {
          clean[key] = {
            type: 'string',
            description: 'Object data (JSON)'
          };
        } else {
          clean[key] = adaptSchemaForClient(value, depth + 1);
        }
      } else {
        // Skip general object cleaning for non-properties/non-items to avoid corrupting arrays like 'required'
        // which are already handled above.
      }
    } else {
      // Prefer 'number' over 'integer'
      if (key === 'type' && value === 'integer') {
        clean[key] = 'number';
      } else {
        clean[key] = value;
      }
    }
  }

  // Final Pass Sanitization
  
  // 1. Handle object types at root
  if (depth === 0 && clean.type === 'object') {
    if (!clean.properties || Object.keys(clean.properties).length === 0) {
      clean.properties = {
        _info: { type: 'string', description: 'Placeholder for object data' }
      };
    }
  }

  // 2. Synchronize 'required' array
  if (clean.required && Array.isArray(clean.required)) {
    const props = clean.properties ? Object.keys(clean.properties) : [];
    clean.required = clean.required.filter((r: string) => props.includes(r));
    if (clean.required.length === 0) delete clean.required;
  }

  return clean;
}

const server = new Server(
  {
    name: "whitemagic-mcp",
    version: "1.0.0",
  },
  {
    capabilities: {
      tools: {},
    },
  }
);

// Client info for model-specific adaptation
let clientInfo: { name: string, version: string } | null = null;

/**
 * Handle server initialization
 */
server.setRequestHandler(InitializeRequestSchema, async (request) => {
  clientInfo = request.params.clientInfo;
  return {
    protocolVersion: "2024-11-05",
    capabilities: {
      tools: {},
    },
    serverInfo: {
      name: "whitemagic-mcp",
      version: "1.0.0",
    },
  };
});

// Session initialization flag
let sessionInitialized = false;
let initializationPromise: Promise<string> | null = null;
let initialContext: string | null = null;

/**
 * List all available tools
 */
server.setRequestHandler(ListToolsRequestSchema, async () => {
  // Session initialization is handled lazily or via explicit tool call
  // to avoid ListTools timeouts which can cause internal errors in some clients.
  
  const catalog = await getCatalog();
  
  // Convert catalog to MCP tool format
  const tools: Tool[] = catalog.tools.map(tool => ({
    // Also strip non-ASCII from tool names just in case
    name: tool.name.replace(/[^\x00-\x7F]/g, ''),
    // Aggressive cleaning for strict models
    description: tool.description.replace(/[^\x00-\x7F]/g, '').substring(0, 100).trim(),
    inputSchema: adaptSchemaForClient(tool.inputSchema)
  }));
  
  return { tools };
});

/**
 * Execute tool
 */
server.setRequestHandler(CallToolRequestSchema, async (request) => {
  const { name, arguments: args } = request.params;
  
  try {
    const result = await executeWhiteMagicTool(name, args || {});
    
    return {
      content: [
        {
          type: "text",
          text: JSON.stringify(result, null, 2)
        }
      ]
    };
  } catch (error) {
    return {
      content: [
        {
          type: "text",
          text: JSON.stringify({
            error: error instanceof Error ? error.message : String(error),
            tool: name
          }, null, 2)
        }
      ],
      isError: true
    };
  }
});

/**
 * Start server
 */
async function main() {
  console.error('🌟 WhiteMagic MCP Server v1.0.0 starting...');
  
  const transport = new StdioServerTransport();
  await server.connect(transport);
  
  console.error('✅ Server ready');
  console.error(`📊 Tools available: Loading catalog...`);
  
  // Pre-load catalog
  const catalog = await getCatalog();
  console.error(`📊 Tools available: ${catalog.totalCount}`);
  console.error(`📂 Categories: ${Object.keys(catalog.categories).join(', ')}`);
  
  // Log initial context for debugging
  if (process.env.WM_DEBUG === 'true') {
    const context = await getSessionInitContext();
    console.error('\n--- Session Context Preview ---');
    console.error(context.substring(0, 500) + '...\n');
  }
}

main().catch((error) => {
  console.error('Fatal error:', error);
  process.exit(1);
});
