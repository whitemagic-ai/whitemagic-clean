/**
 * Archaeology MCP Tools
 * 
 * Tools for tracking file reads, discovering unread files,
 * and reading Windsurf conversation history.
 */

import { spawn } from 'child_process';
import { fileURLToPath } from 'url';
import path from 'path';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const DEFAULT_WHITEMAGIC_PATH = path.resolve(__dirname, '../../../');
const WHITEMAGIC_PATH = process.env.WM_BASE_PATH || DEFAULT_WHITEMAGIC_PATH;

/**
 * Call a Python archaeology function
 */
async function callArchaeology(func: string, args: Record<string, any> = {}): Promise<any> {
  return new Promise((resolve, reject) => {
    const argsJson = JSON.stringify(args).replace(/"/g, '\\"');
    const script = `
import json
import sys
sys.path.insert(0, '${WHITEMAGIC_PATH}')
try:
    from whitemagic.archaeology import FileArchaeologist, WindsurfConversationReader
    arch = FileArchaeologist()
    reader = WindsurfConversationReader()
    
    func = '${func}'
    args = json.loads("${argsJson}")
    
    if func == 'mark_read':
        result = arch.mark_read(**args)
        print(json.dumps(result.to_dict()))
    elif func == 'have_read':
        result = arch.have_read(args['path'])
        print(json.dumps({"have_read": result}))
    elif func == 'find_unread':
        result = arch.find_unread(**args)
        print(json.dumps({"unread_files": result, "count": len(result)}))
    elif func == 'find_changed':
        result = arch.find_changed(args.get('directory'))
        print(json.dumps({"changed_files": [e.to_dict() for e in result], "count": len(result)}))
    elif func == 'recent_reads':
        result = arch.get_recent_reads(args.get('limit', 50))
        print(json.dumps({"recent": [e.to_dict() for e in result]}))
    elif func == 'reading_stats':
        result = arch.stats()
        print(json.dumps(result))
    elif func == 'reading_report':
        result = arch.reading_report()
        print(json.dumps({"report": result}))
    elif func == 'search_reads':
        result = arch.search(args['query'])
        print(json.dumps({"results": [e.to_dict() for e in result]}))
    elif func == 'list_conversations':
        result = reader.list_conversations()
        print(json.dumps({"conversations": result}))
    elif func == 'read_conversation':
        result = reader.read_conversation(args['path'])
        print(json.dumps(result.to_dict()))
    elif func == 'export_conversation':
        result = reader.export_conversation(args['path'], args.get('format', 'markdown'))
        print(json.dumps({"content": result}))
    elif func == 'search_conversations':
        result = reader.search_conversations(args['query'])
        print(json.dumps({"results": result}))
    elif func == 'conversation_stats':
        result = reader.stats()
        print(json.dumps(result))
    else:
        print(json.dumps({"error": f"Unknown function: {func}"}))
except Exception as e:
    import traceback
    print(json.dumps({"error": str(e), "trace": traceback.format_exc()}))
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
 * MCP Tool definitions for archaeology
 */
export const ARCHAEOLOGY_TOOLS = [
  // File Reading Tracker
  {
    name: 'archaeology_mark_read',
    description: '📖 Mark a file as read with optional context and notes',
    category: 'archaeology',
    inputSchema: {
      type: 'object',
      properties: {
        path: { type: 'string', description: 'File path to mark as read' },
        context: { type: 'string', description: 'Why reading this file (e.g., "Phase 1 scan")' },
        note: { type: 'string', description: 'Notes about what was found' },
        insight: { type: 'string', description: 'Key insight extracted from file' }
      },
      required: ['path']
    }
  },
  {
    name: 'archaeology_have_read',
    description: '❓ Check if a file has been read before',
    category: 'archaeology',
    inputSchema: {
      type: 'object',
      properties: {
        path: { type: 'string', description: 'File path to check' }
      },
      required: ['path']
    }
  },
  {
    name: 'archaeology_find_unread',
    description: '🔍 Find unread files in a directory',
    category: 'archaeology',
    inputSchema: {
      type: 'object',
      properties: {
        directory: { type: 'string', description: 'Directory to scan' },
        patterns: { 
          type: 'array', 
          items: { type: 'string' },
          description: 'Glob patterns to include (e.g., ["*.md", "*.py"])'
        }
      },
      required: ['directory']
    }
  },
  {
    name: 'archaeology_find_changed',
    description: '📝 Find files that changed since last read',
    category: 'archaeology',
    inputSchema: {
      type: 'object',
      properties: {
        directory: { type: 'string', description: 'Directory to check (optional)' }
      }
    }
  },
  {
    name: 'archaeology_recent_reads',
    description: '📚 Get recently read files',
    category: 'archaeology',
    inputSchema: {
      type: 'object',
      properties: {
        limit: { type: 'integer', description: 'Max results (default: 50)', default: 50 }
      }
    }
  },
  {
    name: 'archaeology_stats',
    description: '📊 Get file reading statistics',
    category: 'archaeology',
    inputSchema: { type: 'object', properties: {} }
  },
  {
    name: 'archaeology_report',
    description: '📋 Generate human-readable reading report',
    category: 'archaeology',
    inputSchema: { type: 'object', properties: {} }
  },
  {
    name: 'archaeology_search',
    description: '🔎 Search read files by path, notes, or insights',
    category: 'archaeology',
    inputSchema: {
      type: 'object',
      properties: {
        query: { type: 'string', description: 'Search query' }
      },
      required: ['query']
    }
  },
  
  // Windsurf Conversation Tools
  {
    name: 'windsurf_list_conversations',
    description: '💬 List all Windsurf conversation files',
    category: 'windsurf',
    inputSchema: { type: 'object', properties: {} }
  },
  {
    name: 'windsurf_read_conversation',
    description: '📜 Read a specific Windsurf conversation',
    category: 'windsurf',
    inputSchema: {
      type: 'object',
      properties: {
        path: { type: 'string', description: 'Path to .pb conversation file' }
      },
      required: ['path']
    }
  },
  {
    name: 'windsurf_export_conversation',
    description: '📤 Export a conversation to markdown/json/text',
    category: 'windsurf',
    inputSchema: {
      type: 'object',
      properties: {
        path: { type: 'string', description: 'Path to .pb conversation file' },
        format: { 
          type: 'string', 
          enum: ['markdown', 'json', 'text'],
          description: 'Export format',
          default: 'markdown'
        }
      },
      required: ['path']
    }
  },
  {
    name: 'windsurf_search_conversations',
    description: '🔍 Search across all conversations for a query',
    category: 'windsurf',
    inputSchema: {
      type: 'object',
      properties: {
        query: { type: 'string', description: 'Text to search for' }
      },
      required: ['query']
    }
  },
  {
    name: 'windsurf_stats',
    description: '📊 Get statistics about Windsurf conversations',
    category: 'windsurf',
    inputSchema: { type: 'object', properties: {} }
  }
];

/**
 * Handle archaeology tool calls
 */
export async function handleArchaeologyTool(name: string, args: Record<string, any>): Promise<any> {
  const funcMap: Record<string, string> = {
    'archaeology_mark_read': 'mark_read',
    'archaeology_have_read': 'have_read',
    'archaeology_find_unread': 'find_unread',
    'archaeology_find_changed': 'find_changed',
    'archaeology_recent_reads': 'recent_reads',
    'archaeology_stats': 'reading_stats',
    'archaeology_report': 'reading_report',
    'archaeology_search': 'search_reads',
    'windsurf_list_conversations': 'list_conversations',
    'windsurf_read_conversation': 'read_conversation',
    'windsurf_export_conversation': 'export_conversation',
    'windsurf_search_conversations': 'search_conversations',
    'windsurf_stats': 'conversation_stats',
  };
  
  const func = funcMap[name];
  if (!func) {
    throw new Error(`Unknown archaeology tool: ${name}`);
  }
  
  return callArchaeology(func, args);
}

/**
 * Check if a tool name is an archaeology tool
 */
export function isArchaeologyTool(name: string): boolean {
  return name.startsWith('archaeology_') || name.startsWith('windsurf_');
}
