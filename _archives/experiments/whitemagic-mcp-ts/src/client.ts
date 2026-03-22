/**
 * WhiteMagic Client - Direct Python Library Integration
 *
 * This client spawns a Python process and communicates with the WhiteMagic library directly.
 */

import { spawn, ChildProcess } from 'child_process';
import { EventEmitter } from 'events';
import type { Memory, MemorySearchResult, ContextResponse, ConsolidateResult, TagsResponse, StatsResponse, WhiteMagicConfig } from './types.js';

interface PythonCommand {
  id: string;
  method: string;
  params: Record<string, any>;
}

interface PythonResponse {
  id: string;
  success: boolean;
  result?: any;
  error?: string;
}

export class WhiteMagicClient extends EventEmitter {
  private pythonProcess: ChildProcess | null = null;
  private pendingRequests: Map<string, { resolve: (value: any) => void; reject: (reason: any) => void }> = new Map();
  private requestCounter = 0;
  private buffer = '';
  private config: WhiteMagicConfig;

  constructor(config: WhiteMagicConfig) {
    super();
    this.config = config;
  }

  // Metrics
  async trackMetric(category: string, metric: string, value: number, context?: string): Promise<void> {
    await this.call('track_metric', { category, metric, value, context });
  }

  async getMetricsSummary(categories?: string[]): Promise<Record<string, any>> {
    return await this.call('get_metrics_summary', { categories });
  }

  async connect(): Promise<void> {
    const DEBUG = process.env.WM_DEBUG === 'true' || process.env.WM_MCP_DEBUG === 'true';
    
    return new Promise((resolve, reject) => {
      if (DEBUG) {
        console.error('\n[Python Worker] Starting connection...');
        console.error('[Python Worker] Base path:', this.config.basePath);
        console.error('[Python Worker] Python command: python3');
      }
      
      // Spawn Python process running a simple JSON-RPC wrapper around WhiteMagic
      this.pythonProcess = spawn('python3', [
        '-c',
        this.getPythonWrapperCode(),
        this.config.basePath
      ], {
        env: { ...process.env }
      });

      if (DEBUG) {
        console.error('[Python Worker] Process spawned, PID:', this.pythonProcess.pid);
      }

      this.pythonProcess.stdout?.on('data', (data) => {
        if (DEBUG) console.error('[Python Worker] stdout:', data.toString().substring(0, 100));
        this.buffer += data.toString();
        this.processBuffer();
      });

      this.pythonProcess.stderr?.on('data', (data) => {
        const msg = data.toString();
        console.error('[Python Worker] stderr:', msg);
        if (DEBUG && msg.includes('Traceback')) {
          console.error('[Python Worker] ⚠️  Python exception detected!');
        }
      });

      this.pythonProcess.on('spawn', () => {
        if (DEBUG) console.error('[Python Worker] ✅ Process spawned successfully');
      });

      this.pythonProcess.on('error', (err) => {
        console.error('[Python Worker] ❌ Spawn error:', err.message);
        reject(new Error(`Failed to start Python process: ${err.message}`));
      });

      this.pythonProcess.on('exit', (code, signal) => {
        if (process.env.NODE_ENV !== 'test') {
          if (code !== 0 && code !== null) {
            console.error(`[Python Worker] ❌ Exited with code ${code}${signal ? ` (signal: ${signal})` : ''}`);
          } else if (DEBUG) {
            console.error(`[Python Worker] Exited cleanly`);
          }
        }
        this.emit('disconnected');
      });

      // Send a ping to verify connection with timeout
      const timeout = setTimeout(() => {
        reject(new Error('Python worker connection timeout (10s) - check stderr for Python errors'));
      }, 10000);

      if (DEBUG) console.error('[Python Worker] Sending ping...');
      
      this.call('ping', {})
        .then(() => {
          clearTimeout(timeout);
          if (DEBUG) console.error('[Python Worker] ✅ Ping successful, connected!\n');
          resolve();
        })
        .catch(err => {
          clearTimeout(timeout);
          console.error('[Python Worker] ❌ Ping failed:', err.message);
          reject(err);
        });
    });
  }

  private processBuffer(): void {
    const lines = this.buffer.split('\n');
    this.buffer = lines.pop() || '';

    for (const line of lines) {
      if (!line.trim()) continue;

      try {
        const response: PythonResponse = JSON.parse(line);
        const pending = this.pendingRequests.get(response.id);

        if (pending) {
          this.pendingRequests.delete(response.id);
          if (response.success) {
            pending.resolve(response.result);
          } else {
            pending.reject(new Error(response.error || 'Unknown error'));
          }
        }
      } catch (err) {
        console.error('Failed to parse Python response:', line, err);
      }
    }
  }

  /**
   * Call a Python tool via JSON-RPC
   * Made public for MCP 2.0 persistent worker routing
   */
  public call(method: string, params: Record<string, any>): Promise<any> {
    return new Promise((resolve, reject) => {
      const id = `req_${++this.requestCounter}`;
      const command: PythonCommand = { id, method, params };

      this.pendingRequests.set(id, { resolve, reject });

      if (!this.pythonProcess || !this.pythonProcess.stdin) {
        reject(new Error('Python process not connected'));
        return;
      }

      this.pythonProcess.stdin.write(JSON.stringify(command) + '\n');
    });
  }

  // Memory Operations
  async createMemory(title: string, content: string, type: 'short_term' | 'long_term', tags: string[] = []): Promise<string> {
    const result = await this.call('create_memory', { title, content, type, tags });
    return result.path;
  }

  async searchMemories(query?: string, type?: string, tags?: string[], includeArchived: boolean = false): Promise<MemorySearchResult[]> {
    return await this.call('search_memories', { query, type, tags, include_archived: includeArchived });
  }

  async readMemory(filename: string, includeMetadata: boolean = true): Promise<Memory> {
    return await this.call('read_memory', { filename, include_metadata: includeMetadata });
  }

  async listMemories(includeArchived: boolean = false, sortBy: string = 'created'): Promise<{
    short_term: Memory[];
    long_term: Memory[];
    archived?: Memory[];
  }> {
    return await this.call('list_memories', { include_archived: includeArchived, sort_by: sortBy });
  }

  async deleteMemory(filename: string, permanent: boolean = false): Promise<void> {
    await this.call('delete_memory', { filename, permanent });
  }

  async updateMemory(filename: string, updates: {
    title?: string;
    content?: string;
    tags?: string[];
    addTags?: string[];
    removeTags?: string[];
  }): Promise<void> {
    await this.call('update_memory', {
      filename,
      title: updates.title,
      content: updates.content,
      tags: updates.tags,
      add_tags: updates.addTags,
      remove_tags: updates.removeTags,
    });
  }

  async restoreMemory(filename: string, type: 'short_term' | 'long_term' = 'short_term'): Promise<void> {
    await this.call('restore_memory', { filename, type });
  }

  // Context Operations
  async generateContext(tier: 0 | 1 | 2, role?: string): Promise<string> {
    const result = await this.call('generate_context', { tier, role });
    return result.summary;
  }

  // Consolidation
  async consolidate(dryRun: boolean = true): Promise<ConsolidateResult> {
    return await this.call('consolidate', { dry_run: dryRun });
  }

  // Stats & Tags
  async getTags(includeArchived: boolean = false): Promise<TagsResponse> {
    return await this.call('list_tags', { include_archived: includeArchived });
  }

  async getStats(): Promise<StatsResponse> {
    const listing = await this.listMemories(true);
    const tags = await this.getTags(false);
    return {
      short_term_count: listing.short_term.length,
      long_term_count: listing.long_term.length,
      archived_count: listing.archived?.length || 0,
      total_memories: listing.short_term.length + listing.long_term.length + (listing.archived?.length || 0),
      total_tags: tags.total_unique_tags,
    };
  }

  disconnect(): void {
    if (this.pythonProcess) {
      this.pythonProcess.kill();
      this.pythonProcess = null;
    }
  }

  private getPythonWrapperCode(): string {
    return `
import sys
import json
from pathlib import Path

# Get base_dir from command line argument
base_dir = sys.argv[1] if len(sys.argv) > 1 else '.'
base_path = Path(base_dir).resolve()

# CRITICAL FIX: Add WhiteMagic root to Python path
# If base_dir is the whitemagic project root, use it
# Otherwise try to find whitemagic in parent directories
whitemagic_root = base_path
if not (whitemagic_root / 'whitemagic' / '__init__.py').exists():
    # Try parent directory
    whitemagic_root = base_path.parent
    
sys.path.insert(0, str(whitemagic_root))

from whitemagic import MemoryManager
from whitemagic.metrics import track_metric as wm_track_metric, get_tracker

manager = MemoryManager(base_dir=base_path)

def handle_request(cmd):
    method = cmd['method']
    params = cmd['params']

    try:
        if method == 'ping':
            return {'success': True, 'result': 'pong'}

        elif method == 'create_memory':
            path = manager.create_memory(
                title=params['title'],
                content=params['content'],
                memory_type=params['type'],
                tags=params.get('tags', [])
            )
            return {'success': True, 'result': {'path': str(path)}}

        elif method == 'search_memories':
            results = manager.search_memories(
                query=params.get('query'),
                memory_type=params.get('type'),
                tags=params.get('tags'),
                include_archived=params.get('include_archived', False)
            )
            return {'success': True, 'result': results}

        elif method == 'list_memories':
            listing = manager.list_all_memories(
                include_archived=params.get('include_archived', False),
                sort_by=params.get('sort_by', 'created')
            )
            return {'success': True, 'result': listing}

        elif method == 'read_memory':
            memory = manager.get_memory(
                filename=params['filename'],
                include_metadata=params.get('include_metadata', True)
            )
            return {'success': True, 'result': memory}

        elif method == 'delete_memory':
            result = manager.delete_memory(
                params['filename'],
                permanent=params.get('permanent', False)
            )
            return {'success': True, 'result': result}

        elif method == 'update_memory':
            result = manager.update_memory(
                filename=params['filename'],
                title=params.get('title'),
                content=params.get('content'),
                tags=params.get('tags'),
                add_tags=params.get('add_tags'),
                remove_tags=params.get('remove_tags')
            )
            return {'success': True, 'result': result}

        elif method == 'restore_memory':
            result = manager.restore_memory(
                params['filename'],
                memory_type=params.get('type', 'short_term')
            )
            return {'success': True, 'result': result}

        elif method == 'generate_context':
            summary = manager.generate_context_summary(params['tier'])
            return {'success': True, 'result': {'summary': summary}}

        elif method == 'consolidate':
            result = manager.consolidate_short_term(
                dry_run=params.get('dry_run', True)
            )
            return {'success': True, 'result': result}

        elif method == 'list_tags':
            result = manager.list_all_tags(
                include_archived=params.get('include_archived', False)
            )
            return {'success': True, 'result': result}

        elif method == 'track_metric':
            wm_track_metric(
                category=params['category'],
                metric=params['metric'],
                value=float(params['value']),
                context=params.get('context')
            )
            return {'success': True, 'result': 'ok'}

        elif method == 'get_metrics_summary':
            tracker = get_tracker()
            summary = tracker.get_summary(params.get('categories'))
            return {'success': True, 'result': summary}

        # Cascade Tools (Phase 5 - MCP Cascade Intelligence)
        elif method == 'execute_cascade':
            import asyncio
            from whitemagic.cascade import CascadeEngine

            engine = CascadeEngine(
                enable_yin_yang=params.get('enable_yin_yang', True),
                max_parallel_calls=params.get('max_parallel_calls', 20),
            )

            # Run async cascade execution
            async def run_cascade():
                return await engine.execute(
                    pattern_name=params['pattern_name'],
                    context=params.get('context', {}),
                )

            result = asyncio.run(run_cascade())

            # Convert CascadeResult to dict
            return {'success': True, 'result': {
                'success': result.success,
                'results': result.results,
                'metrics': result.metrics,
                'synthesis': result.synthesis,
                'error': result.error,
                'duration': result.duration,
            }}

        elif method == 'list_cascade_patterns':
            from whitemagic.cascade import PatternLibrary

            library = PatternLibrary()
            tag_filter = params.get('tag')

            if tag_filter:
                patterns = library.search_patterns(tag_filter)
            else:
                patterns = [library.get_pattern(name) for name in library.list_patterns()]

            pattern_infos = []
            for p in patterns:
                if p:
                    pattern_infos.append({
                        'name': p.name,
                        'description': p.description,
                        'expected_inputs': p.expected_inputs,
                        'tags': p.tags,
                        'step_count': len(p.steps),
                    })

            return {'success': True, 'result': {'patterns': pattern_infos}}

        elif method == 'get_cascade_pattern':
            from whitemagic.cascade import PatternLibrary

            library = PatternLibrary()
            pattern = library.get_pattern(params['pattern_name'])

            if not pattern:
                return {'success': True, 'result': {
                    'found': False,
                    'error': f"Pattern '{params['pattern_name']}' not found"
                }}

            # Convert steps to dicts
            steps = []
            for step in pattern.steps:
                steps.append({
                    'tool_name': step.tool_name,
                    'description': step.description,
                    'params': step.params,
                    'activity_type': step.activity_type.value,
                    'depends_on': step.depends_on,
                    'optional': step.optional,
                })

            return {'success': True, 'result': {
                'found': True,
                'pattern': {
                    'name': pattern.name,
                    'description': pattern.description,
                    'expected_inputs': pattern.expected_inputs,
                    'tags': pattern.tags,
                    'steps': steps,
                }
            }}

        else:
            return {'success': False, 'error': f'Unknown method: {method}'}

    except Exception as e:
        return {'success': False, 'error': str(e)}

# Main loop
for line in sys.stdin:
    try:
        cmd = json.loads(line.strip())
        response = handle_request(cmd)
        response['id'] = cmd['id']
        print(json.dumps(response), flush=True)
    except Exception as e:
        print(json.dumps({'id': '', 'success': False, 'error': str(e)}), flush=True)
`;
  }
}
