/**
 * Extended MCP Tools - All 21 WhiteMagic Capabilities
 * 
 * This file defines all tools available through the MCP server,
 * matching the Python unified_api.py for consistency.
 */

import { spawn } from 'child_process';
import { fileURLToPath } from 'url';
import path from 'path';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const DEFAULT_WHITEMAGIC_PATH = path.resolve(__dirname, '../../../');
const WHITEMAGIC_PATH = process.env.WM_BASE_PATH || DEFAULT_WHITEMAGIC_PATH;

/**
 * Call a Python tool and return JSON result
 */
export async function callPythonTool(toolName: string, args: Record<string, any> = {}): Promise<any> {
  return new Promise((resolve, reject) => {
    const script = `
import json
import sys
sys.path.insert(0, '${WHITEMAGIC_PATH}')
from whitemagic.tools import call_tool
try:
    result = call_tool('${toolName}', **${JSON.stringify(args)})
    print(json.dumps(result))
except Exception as e:
    print(json.dumps({"error": str(e)}))
`;
    
    const proc = spawn('python3', ['-c', script], {
      cwd: WHITEMAGIC_PATH,
      env: { ...process.env, PYTHONPATH: WHITEMAGIC_PATH }
    });
    
    let stdout = '';
    let stderr = '';
    
    proc.stdout.on('data', (data) => stdout += data);
    proc.stderr.on('data', (data) => stderr += data);
    
    proc.on('close', (code) => {
      try {
        resolve(JSON.parse(stdout));
      } catch {
        reject(new Error(stderr || stdout || `Exit code: ${code}`));
      }
    });
  });
}

/**
 * Tool definitions for MCP ListTools response
 */
export const EXTENDED_TOOLS = [
  // SESSION TOOLS
  {
    name: 'session_bootstrap',
    description: '🚀 Full session bootstrap with context loading, Gan Ying wiring, and status display',
    category: 'session',
    inputSchema: { type: 'object', properties: {} }
  },
  {
    name: 'session_status',
    description: '📊 Get current session state (files seen, memories, Gan Ying status)',
    category: 'session',
    inputSchema: { type: 'object', properties: {} }
  },
  {
    name: 'session_remember',
    description: '🧠 Add content to the memory matrix for later recall',
    category: 'session',
    inputSchema: {
      type: 'object',
      properties: {
        content: { type: 'string', description: 'Content to remember' },
        tags: { type: 'array', items: { type: 'string' }, description: 'Tags for categorization' },
        source: { type: 'string', description: 'Source of the memory' }
      },
      required: ['content']
    }
  },
  {
    name: 'session_recall',
    description: '🔍 Search the memory matrix by semantic similarity',
    category: 'session',
    inputSchema: {
      type: 'object',
      properties: {
        query: { type: 'string', description: 'Search query' },
        limit: { type: 'integer', description: 'Max results', default: 10 }
      },
      required: ['query']
    }
  },
  {
    name: 'session_mark_seen',
    description: '👁️ Mark a file as seen (track what has been read)',
    category: 'session',
    inputSchema: {
      type: 'object',
      properties: {
        path: { type: 'string', description: 'File path' },
        action: { type: 'string', description: 'Action type (read, viewed, edited)', default: 'read' },
        context: { type: 'string', description: 'Context of viewing' }
      },
      required: ['path']
    }
  },
  {
    name: 'session_have_seen',
    description: '❓ Check if a file has been seen before',
    category: 'session',
    inputSchema: {
      type: 'object',
      properties: {
        path: { type: 'string', description: 'File path to check' }
      },
      required: ['path']
    }
  },
  
  // WISDOM TOOLS
  {
    name: 'cast_oracle',
    description: '🔮 Cast I Ching hexagram for guidance',
    category: 'wisdom',
    inputSchema: {
      type: 'object',
      properties: {
        question: { type: 'string', description: 'Question to ask', default: 'What guidance do you offer?' }
      }
    }
  },
  {
    name: 'wu_xing_balance',
    description: '☯️ Check Wu Xing (Five Elements) balance',
    category: 'wisdom',
    inputSchema: {
      type: 'object',
      properties: {
        context: { type: 'string', description: 'Context for analysis' }
      }
    }
  },
  {
    name: 'grimoire_list',
    description: '📖 List all Grimoire chapters',
    category: 'wisdom',
    inputSchema: { type: 'object', properties: {} }
  },
  {
    name: 'grimoire_read',
    description: '📜 Read a specific Grimoire chapter',
    category: 'wisdom',
    inputSchema: {
      type: 'object',
      properties: {
        chapter: { type: 'string', description: 'Chapter name or number to read' }
      },
      required: ['chapter']
    }
  },
  
  // GARDEN TOOLS
  {
    name: 'garden_health',
    description: '💚 Check health of all 14 gardens',
    category: 'garden',
    inputSchema: { type: 'object', properties: {} }
  },
  {
    name: 'capability_harness',
    description: '🧪 Run capability combo tests (6 combos)',
    category: 'garden',
    inputSchema: { type: 'object', properties: {} }
  },
  
  // GAN YING TOOLS
  {
    name: 'ganying_emit',
    description: '📡 Emit event to Gan Ying bus',
    category: 'ganying',
    inputSchema: {
      type: 'object',
      properties: {
        event_type: { type: 'string', description: 'Event type (e.g., PATTERN_DETECTED, JOY_DETECTED)' },
        source: { type: 'string', description: 'Event source' },
        data: { type: 'object', description: 'Event data' },
        confidence: { type: 'number', description: 'Confidence level', default: 0.8 }
      },
      required: ['event_type', 'source']
    }
  },
  {
    name: 'ganying_history',
    description: '📜 Get recent Gan Ying bus events',
    category: 'ganying',
    inputSchema: {
      type: 'object',
      properties: {
        limit: { type: 'integer', description: 'Max events to return', default: 20 }
      }
    }
  },
  {
    name: 'ganying_listeners',
    description: '👂 Get Gan Ying listener counts by event type',
    category: 'ganying',
    inputSchema: { type: 'object', properties: {} }
  },
  
  // RUST TOOLS
  {
    name: 'rust_audit',
    description: '⚡ Fast directory audit via Rust bridge (5-10x faster)',
    category: 'rust',
    inputSchema: {
      type: 'object',
      properties: {
        path: { type: 'string', description: 'Directory path to audit' },
        pattern: { type: 'string', description: 'File pattern (e.g., *.py)', default: '*.py' },
        depth: { type: 'integer', description: 'Max depth', default: 3 }
      },
      required: ['path']
    }
  },
  {
    name: 'rust_similarity',
    description: '⚡ Fast text similarity via Rust bridge',
    category: 'rust',
    inputSchema: {
      type: 'object',
      properties: {
        text1: { type: 'string', description: 'First text' },
        text2: { type: 'string', description: 'Second text' }
      },
      required: ['text1', 'text2']
    }
  },
  {
    name: 'rust_compress',
    description: '⚡ Fast LZ4 compression via Rust bridge',
    category: 'rust',
    inputSchema: {
      type: 'object',
      properties: {
        data: { type: 'string', description: 'Data to compress' }
      },
      required: ['data']
    }
  },
  {
    name: 'rust_status',
    description: '🔧 Check Rust bridge status and available functions',
    category: 'rust',
    inputSchema: { type: 'object', properties: {} }
  },
  {
    name: 'rust_fast_search',
    description: '⚡ Fast file search via Rust',
    category: 'rust',
    inputSchema: {
      type: 'object',
      properties: {
        root_path: { type: 'string', description: 'Root path to search' },
        pattern: { type: 'string', description: 'Search pattern or regex' },
        limit: { type: 'integer', description: 'Max results', default: 100 },
        extensions: { type: 'array', items: { type: 'string' }, description: 'File extensions to include' },
        max_file_size: { type: 'integer', description: 'Max file size in bytes' }
      },
      required: ['root_path', 'pattern']
    }
  },
  {
    name: 'rust_compress_file',
    description: '⚡ Compress a file via Rust',
    category: 'rust',
    inputSchema: {
      type: 'object',
      properties: {
        input_path: { type: 'string', description: 'Input file path' },
        output_path: { type: 'string', description: 'Output file path' }
      },
      required: ['input_path', 'output_path']
    }
  },
  {
    name: 'rust_consolidate_memories',
    description: '⚡ Consolidate memories via Rust',
    category: 'rust',
    inputSchema: {
      type: 'object',
      properties: {
        short_term_dir: { type: 'string', description: 'Short-term memory directory' },
        top_n: { type: 'integer', description: 'Top N memories to keep', default: 20 },
        similarity_threshold: { type: 'number', description: 'Similarity threshold', default: 0.7 }
      },
      required: ['short_term_dir']
    }
  },
  
  // MANIFEST TOOLS
  {
    name: 'manifest_read',
    description: '📋 Read full SESSION_MANIFEST.yaml',
    category: 'manifest',
    inputSchema: { type: 'object', properties: {} }
  },
  {
    name: 'manifest_summary',
    description: '📊 Get manifest summary (version, gardens, tools)',
    category: 'manifest',
    inputSchema: { type: 'object', properties: {} }
  }
];

/**
 * Handle a tool call by routing to Python unified API
 */
export async function handleToolCall(name: string, args: Record<string, any>): Promise<string> {
  try {
    const result = await callPythonTool(name, args);
    return JSON.stringify(result, null, 2);
  } catch (error) {
    return JSON.stringify({ error: String(error) });
  }
}

// IMAGE TOOLS (v2.6.8) - Added at end
export const IMAGE_TOOLS = [
  {
    name: 'store_image',
    description: '🖼️ Store image in State Server',
    category: 'image',
    inputSchema: {
      type: 'object',
      properties: {
        url: { type: 'string' },
        description: { type: 'string' },
        tags: { type: 'array', items: { type: 'string' } }
      },
      required: ['url', 'description']
    }
  },
  {
    name: 'search_images',
    description: '🔍 Search images by description',
    category: 'image',
    inputSchema: {
      type: 'object',
      properties: {
        query: { type: 'string' },
        limit: { type: 'integer', default: 20 }
      },
      required: ['query']
    }
  },
  {
    name: 'state_server_status',
    description: '📊 Get State Server status',
    category: 'web',
    inputSchema: { type: 'object', properties: {} }
  }
];
