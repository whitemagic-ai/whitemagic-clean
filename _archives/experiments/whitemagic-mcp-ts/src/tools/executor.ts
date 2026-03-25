/**
 * Tool Executor - Routes MCP tool calls to WhiteMagic Python CLI
 */

import { spawn } from 'child_process';
import { fileURLToPath } from 'url';
import path from 'path';
import { PRIMARY_TOOLS, getPrimaryTool } from '../primary-tools.js';
import { resolveToolAlias } from '../tools-registry.js';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const DEFAULT_WHITEMAGIC_PATH = path.resolve(__dirname, '../../../../');
const WHITEMAGIC_PATH = process.env.WM_BASE_PATH || DEFAULT_WHITEMAGIC_PATH;
const PYTHON_BIN = process.env.WM_PYTHON_BIN || `${WHITEMAGIC_PATH}/.venv/bin/python3`;
const WM_CLI = `${WHITEMAGIC_PATH}/wm`;

/**
 * Tools enabled for Gana routing (Phase 2)
 */
const GANA_TOOLS = [
  // Eastern
  'initialize_session', 'session_init', 'create_scratchpad',
  'create_memory', 'memory_create',
  'check_system_health', 'system_initialize_all', 'validate_integrations',
  'manage_resource_locks', 'sangha_lock_acquire', 'sangha_lock_release',
  'get_session_context', 'session_get_context', 'manage_sessions',
  'enable_rust_acceleration', 'optimize_cache',
  'consolidate_memories', 'add_lesson',

  // Southern
  'track_metric', 'get_metrics_summary',
  'prat_get_context', 'prat_invoke',
  'manage_resonance',
  'manage_archaeology',

  // Western
  'find_similar_problem', 'capture_pattern',
  'debug_integrations',
  'consult_wisdom_council', 'consult_iching',

  // Northern
  'search_memories', 'memory_search',
  'session_handoff',
  'manage_zodiac_cores', 'zodiac_list_cores'
];

/**
 * Automated Dharma Interceptor
 * Screen tools for ethical alignment and boundaries before execution
 */
async function dharmaInterceptor(toolName: string, args: any): Promise<{ allowed: boolean; message?: string }> {
  // Standard Dharma tools should not intercept themselves to avoid infinite loops
  const dharmaTools = ['evaluate_ethics', 'check_boundaries', 'verify_consent', 'get_guidance', 'get_ethical_score', 'list_principles', 'evaluate_dharma'];
  if (dharmaTools.includes(toolName)) return { allowed: true };

  try {
    // Perform a quick boundary check via the Python bridge
    // We pass the tool and its arguments as the 'action' context
    const assessment = await executePython('bridge', 'dharma_check_boundaries', {
      action: { tool: toolName, arguments: args },
      context: { source: 'mcp_interceptor', automated: true }
    });

    if (assessment && assessment.boundary_type === 'INTERFERING') {
      return {
        allowed: false,
        message: `Dharma Violation: Action detected as INTERFERING. ${assessment.reason || ''}`
      };
    }

    return { allowed: true };
  } catch (error) {
    console.warn(`Dharma interceptor failed for ${toolName}, proceeding with caution:`, error);
    return { allowed: true }; // Proceed if interceptor fails to avoid system lockout
  }
}

/**
 * Execute a WhiteMagic tool by routing to Python CLI or Bridge
 */
export async function executeWhiteMagicTool(toolName: string, args: Record<string, any>): Promise<any> {
  // Step 0: Dharma Interceptor (Refinement 2)
  const dharmaCheck = await dharmaInterceptor(toolName, args);
  if (!dharmaCheck.allowed) {
    throw new Error(dharmaCheck.message);
  }

  // Step 1: Resolve aliases (LIBRA Phase 7)
  const resolvedName = resolveToolAlias(toolName);

  // Step 2: Check if this is a primary tool (28 consolidated tools)
  const primaryTool = getPrimaryTool(resolvedName);
  if (primaryTool) {
    // Route to primary tool handler with operation
    const operation = args.operation || primaryTool.inputSchema.properties.operation?.default || 'default';
    return executePrimaryTool(resolvedName, operation, args);
  }

  // Step 3: Check for Gana routing (Phase 2) - legacy tools
  if (GANA_TOOLS.includes(toolName)) {
    try {
      // Execute via Gana protocol - use 'target_tool' to avoid collision with execute_mcp_tool's 'tool_name' param
      return executePython('bridge', 'gana_invoke', { target_tool: toolName, tool_args: args });
    } catch (e) {
      console.warn(`Gana invocation failed for ${toolName}, falling back to legacy execution:`, e);
      // Fallback to legacy execution below if Gana fails
    }
  }

  // Route to bridge for specific tools
  if (toolName === 'manage_sessions') {
    return executeSessionTool(toolName, args);
  }
  if (toolName === 'consult_wisdom_council') {
    return executeWisdomTool(toolName, args);
  }
  if (toolName === 'check_system_health') {
    return executeHealthTool(toolName, args);
  }
  // Route memory tools to Python bridge
  if (toolName === 'create_memory' || toolName === 'search_memories' ||
    toolName === 'read_memory' || toolName === 'update_memory' ||
    toolName === 'delete_memory' || toolName === 'list_memories') {
    return executeMemoryTool(toolName, args);
  }
  if (toolName === 'manage_memories') {
    return executeMemoryTool(toolName, args);
  }
  if (toolName === 'manage_archaeology') {
    return executeArchaeologyTool(toolName, args);
  }
  if (toolName === 'manage_gardens') {
    return executeGardenTool(toolName, args);
  }
  if (toolName === 'detect_patterns') {
    return executePython('bridge', 'detect_patterns', args);
  }
  if (toolName === 'manage_agent_collaboration') {
    return executePython('bridge', 'manage_agent_collaboration', args);
  }
  if (toolName === 'manage_voice_patterns') {
    return executePython('bridge', 'manage_voice_patterns', args);
  }
  if (toolName === 'run_autonomous_cycle') {
    return executePython('bridge', 'run_autonomous_cycle', args);
  }
  if (toolName === 'run_local_inference') {
    return executePython('bridge', 'run_local_inference', args);
  }
  if (toolName === 'run_benchmarks') {
    return executePython('bridge', 'run_benchmarks', args);
  }
  if (toolName === 'optimize_models') {
    return executePython('bridge', 'optimize_models', {
      operation: args.operation || 'quantize',
      model_path: args.model_path,
      output_path: args.output_path,
      quant_type: args.quant_type || 'q4',
      model_name: args.model_name
    });
  }
  if (toolName === 'initialize_systems') {
    return executePython('bridge', 'system_initialize_all', args);
  }
  if (toolName === 'apply_reasoning_methods') {
    return executePython('bridge', 'apply_reasoning_methods', args);
  }
  if (toolName === 'analyze_wu_xing_phase') {
    return executePython('bridge', 'analyze_wu_xing_phase', {
      operation: args.operation || 'analyze',
      description: args.description || args.question || args.task_type || 'task'
    });
  }
  if (toolName === 'validate_integrations') {
    return executePython('bridge', 'validate_integrations', {
      quick_check: args.quick_check !== false
    });
  }
  if (toolName === 'manage_zodiac_cores') {
    return executePython('bridge', 'manage_zodiac_cores', {
      action: args.action || 'list',
      core_name: args.core_name,
      question: args.question,
      context: args.context
    });
  }

  // Dharma (Ethical Reasoning & Boundaries)
  if (toolName === 'evaluate_ethics' || toolName === 'check_boundaries' ||
    toolName === 'verify_consent' || toolName === 'get_guidance' ||
    toolName === 'get_ethical_score' || toolName === 'list_principles') {
    return executeDharmaTool(toolName, args);
  }

  // PRAT (Polymorphic Resonant Adaptive Tools)
  if (toolName.startsWith('prat_')) {
    return executePratTool(toolName, args);
  }

  // Fallback to CLI commands
  const cliCommand = getCliCommandForTool(toolName, args);

  if (!cliCommand) {
    throw new Error(`Tool not implemented: ${toolName}`);
  }

  return executeCliCommand(cliCommand);
}

async function executeGardenTool(toolName: string, args: any): Promise<any> {
  if (toolName === 'manage_gardens') {
    const action = args.action || 'list';
    return executePython('bridge', 'manage_gardens', { ...args, action });
  }
  throw new Error(`Unknown garden tool: ${toolName}`);
}

/**
 * Map tool name to WhiteMagic CLI command
 */
function getCliCommandForTool(toolName: string, args: Record<string, any>): string | null {
  switch (toolName) {
    // Memory tools now handled by Python bridge above

    case 'strengthen_memory':
      return `${WM_CLI} memory strengthen "${args.memory_id}"`;

    case 'link_memories':
      return `${WM_CLI} memory link "${args.source_id}" "${args.target_id}"${args.link_type ? ' --type ' + args.link_type : ''}`;

    // Zodiac Tools
    case 'list_zodiac_cores':
      return `${WM_CLI} zodiac list`;

    case 'activate_zodiac_core':
      return `${WM_CLI} zodiac activate ${args.core_name}`;

    case 'zodiac_council':
      return `${WM_CLI} zodiac council "${args.question}"`;

    case 'run_zodiacal_round':
      return `${WM_CLI} zodiac cycle${args.num_cycles ? ' --cycles ' + args.num_cycles : ''}`;

    // Garden Tools
    case 'list_gardens':
      return `${WM_CLI} garden list`;

    case 'activate_garden':
      return `${WM_CLI} garden activate ${args.garden_name}`;

    case 'trigger_garden_cascade':
      return `${WM_CLI} garden cascade ${args.garden_name}${args.depth ? ' --depth ' + args.depth : ''}`;

    // Gan Ying (Resonance) Tools
    case 'emit_resonance_event':
      return `${WM_CLI} observe emit --type ${args.event_type} --source ${args.source}`;

    case 'enable_async_gan_ying':
      return `${WM_CLI} observe enable-async`;

    // Wu Xing Tools
    case 'analyze_wu_xing_phase':
      return `${WM_CLI} wuxing analyze "${args.description || args.question || 'task'}"`;

    case 'get_phase_recommendations':
      return `${WM_CLI} wuxing recommend "${args.task_type}"`;

    // System Tools
    case 'initialize_all_systems':
      return `${WM_CLI} init${args.verbose ? ' --verbose' : ''}`;

    case 'get_system_status':
      return `${WM_CLI} status`;

    case 'run_autonomous_cycle':
      return `${WM_CLI} autonomous run${args.duration_seconds ? ' --duration ' + args.duration_seconds : ''}`;

    default:
      return null;
  }
}

/**
 * Execute via Python subprocess (Bridge)
 */
async function executePython(module: string, func: string, args: Record<string, any>): Promise<any> {
  return new Promise((resolve, reject) => {
    const argsJson = JSON.stringify(args);
    const script = `
import json
import sys
sys.path.insert(0, '${WHITEMAGIC_PATH}')
try:
    from whitemagic.mcp_api_bridge import execute_mcp_tool
    args = json.loads('''${argsJson}''')
    result = execute_mcp_tool('${func}', **args)
    print(json.dumps(result, default=str))
except Exception as e:
    import traceback
    print(json.dumps({"error": str(e), "trace": traceback.format_exc()}))
`;

    const proc = spawn(PYTHON_BIN, ['-c', script], {
      cwd: WHITEMAGIC_PATH,
      env: { ...process.env, PYTHONPATH: WHITEMAGIC_PATH, WM_SILENT_INIT: '1' }
    });

    let stdout = '';
    let stderr = '';

    proc.stdout.on('data', (data) => stdout += data);
    proc.stderr.on('data', (data) => stderr += data);

    proc.on('close', (code) => {
      const output = stdout.trim();
      const parseJson = (payload: string): any => JSON.parse(payload);

      try {
        const result = parseJson(output);
        if (result.error) {
          reject(new Error(result.error));
        } else {
          resolve(result);
        }
        return;
      } catch {
        // fall through to line-based parsing
      }

      const lines = output.split(/\r?\n/).filter(Boolean);
      for (let i = lines.length - 1; i >= 0; i -= 1) {
        try {
          const result = parseJson(lines[i]);
          if (result.error) {
            reject(new Error(result.error));
          } else {
            resolve(result);
          }
          return;
        } catch {
          // continue searching for JSON line
        }
      }

      reject(new Error(stderr || stdout || `Exit code: ${code}`));
    });
  });
}

async function executeSessionTool(toolName: string, args: any): Promise<any> {
  if (toolName === 'manage_sessions') {
    const operation = args.operation || 'get_context';
    switch (operation) {
      case 'init':
        return executePython('bridge', 'session_init', { session_name: args.session_name, goals: args.goals });
      case 'get_context':
        return executePython('bridge', 'session_get_context', args);
      case 'checkpoint':
        return executePython('bridge', 'session_checkpoint', args);
      case 'restore':
        return executePython('bridge', 'session_restore', { session_name: args.session_name });
      case 'list':
        return executePython('bridge', 'session_list', args);
      default:
        throw new Error(`Unknown session operation: ${operation}`);
    }
  }
  throw new Error(`Unknown session tool: ${toolName}`);
}

async function executeWisdomTool(toolName: string, args: any): Promise<any> {
  if (toolName === 'consult_wisdom_council') {
    const source = args.source || 'full_council';
    switch (source) {
      case 'full_council':
        return executePython('bridge', 'consult_full_council', { question: args.question, urgency: args.urgency });
      case 'art_of_war':
        return executePython('bridge', 'consult_art_of_war', { question: args.question, situation: args.situation, urgency: args.urgency });
      case 'iching':
        return executePython('bridge', 'consult_iching', { question: args.question, urgency: args.urgency });
      case 'synthesize':
        return executePython('bridge', 'synthesize_wisdom', { sources: args.sources, urgency: args.urgency });
      default:
        throw new Error(`Unknown wisdom source: ${source}`);
    }
  }
  throw new Error(`Unknown wisdom tool: ${toolName}`);
}

async function executeHealthTool(toolName: string, args: any): Promise<any> {
  if (toolName === 'check_system_health') {
    const operation = args.operation || 'system';
    const component = args.component || operation;
    switch (component) {
      case 'system':
        return executePython('bridge', 'check_system_health', {
          component: 'system',
          deep_scan: args.deep_scan || false,
          scan_disk: args.scan_disk || false
        });
      case 'memory':
        return executePython('bridge', 'check_memory_health', { component: 'memory' });
      case 'resonance':
        return executePython('bridge', 'check_resonance_health', { component: 'resonance', duration_seconds: args.duration_seconds || 60 });
      case 'integrations':
      case 'validate_integrations':
        return executePython('bridge', 'validate_integrations', { quick_check: args.quick_check !== false });
      case 'garden_health':
      case 'garden':
        return executePython('bridge', 'garden_health', {});
      default:
        throw new Error(`Unknown health component: ${component}`);
    }
  }
  throw new Error(`Unknown health tool: ${toolName}`);
}

async function executeMemoryTool(toolName: string, args: any): Promise<any> {
  // Direct tool calls
  switch (toolName) {
    case 'create_memory':
      return executePython('bridge', 'memory_create', {
        title: args.title,
        content: args.content,
        memory_type: args.type || 'short_term',
        tags: args.tags || []
      });

    case 'search_memories':
      return executePython('bridge', 'memory_search', {
        query: args.query,
        limit: args.limit || 10,
        tags: args.tags
      });

    case 'read_memory':
      return executePython('bridge', 'memory_read', {
        memory_id: args.memory_id || args.id
      });

    case 'update_memory':
      return executePython('bridge', 'memory_update', {
        memory_id: args.memory_id || args.filename || args.id,
        content: args.content,
        title: args.title,
        tags: args.tags
      });

    case 'delete_memory':
      return executePython('bridge', 'memory_delete', {
        memory_id: args.memory_id || args.id
      });

    case 'list_memories':
      return executePython('bridge', 'memory_list', {
        limit: args.limit || 20,
        memory_type: args.type
      });

    case 'manage_memories':
      const operation = args.operation || 'search';
      const { operation: _, ...cleanArgs } = args;

      switch (operation) {
        case 'create':
          return executePython('bridge', 'memory_create', {
            title: cleanArgs.title,
            content: cleanArgs.content,
            memory_type: cleanArgs.type || 'short_term',
            tags: cleanArgs.tags || []
          });
        case 'search':
          return executePython('bridge', 'memory_search', cleanArgs);
        case 'read':
          return executePython('bridge', 'memory_read', cleanArgs);
        case 'update':
          return executePython('bridge', 'memory_update', {
            memory_id: cleanArgs.memory_id || cleanArgs.filename || cleanArgs.id,
            content: cleanArgs.content,
            title: cleanArgs.title,
            tags: cleanArgs.tags
          });
        case 'delete':
          return executePython('bridge', 'memory_delete', cleanArgs);
        case 'list':
          return executePython('bridge', 'memory_list', cleanArgs);
        default:
          throw new Error(`Unknown memory operation: ${operation}`);
      }

    default:
      throw new Error(`Unknown memory tool: ${toolName}`);
  }
}

async function executeArchaeologyTool(toolName: string, args: any): Promise<any> {
  if (toolName === 'manage_archaeology') {
    const operation = args.operation || 'scan';
    const { operation: _, ...cleanArgs } = args;

    switch (operation) {
      case 'scan':
        return executePython('bridge', 'archaeology_scan_directory', cleanArgs);
      case 'mark_read':
        return executePython('bridge', 'archaeology_mark_read', cleanArgs);
      case 'mark_written':
        return executePython('bridge', 'archaeology_mark_written', cleanArgs);
      case 'find_unread':
        return executePython('bridge', 'archaeology_find_unread', cleanArgs);
      case 'find_changed':
        return executePython('bridge', 'archaeology_find_changed', cleanArgs);
      case 'recent_reads':
        return executePython('bridge', 'archaeology_recent_reads', cleanArgs);
      case 'stats':
        return executePython('bridge', 'archaeology_stats', cleanArgs);
      case 'report':
        return executePython('bridge', 'archaeology_report', cleanArgs);
      case 'search':
        return executePython('bridge', 'archaeology_search', cleanArgs);
      case 'extract_wisdom':
        return executePython('bridge', 'archaeology_extract_wisdom', cleanArgs);
      case 'process_wisdom':
        return executePython('bridge', 'archaeology_process_wisdom', cleanArgs);
      case 'generate_report':
        return executePython('bridge', 'archaeology_generate_report', cleanArgs);
      case 'daily_digest':
        return executePython('bridge', 'archaeology_daily_digest', cleanArgs);
      default:
        throw new Error(`Unknown archaeology operation: ${operation}`);
    }
  }
  throw new Error(`Unknown archaeology tool: ${toolName}`);
}

async function executeDharmaTool(toolName: string, args: any): Promise<any> {
  // Route Dharma tools to Python bridge
  switch (toolName) {
    case 'evaluate_ethics':
      return executePython('bridge', 'dharma_evaluate_ethics', args);
    case 'check_boundaries':
      return executePython('bridge', 'dharma_check_boundaries', args);
    case 'verify_consent':
      return executePython('bridge', 'dharma_verify_consent', args);
    case 'get_guidance':
      return executePython('bridge', 'dharma_get_guidance', args);
    case 'get_ethical_score':
      return executePython('bridge', 'dharma_get_ethical_score', args);
    case 'list_principles':
      return executePython('bridge', 'dharma_list_principles', args);
    default:
      throw new Error(`Unknown Dharma tool: ${toolName}`);
  }
}

/**
 * Execute primary tool with operation routing (LIBRA Phase 7)
 * Handles all 28 consolidated primary tools
 */
async function executePrimaryTool(toolName: string, operation: string, args: any): Promise<any> {
  // Remove operation from args before passing to handlers
  const { operation: _, ...cleanArgs } = args;

  // Route based on tool name and operation
  switch (toolName) {
    // ========================================
    // EASTERN QUADRANT (Wood/Spring) - 7 tools
    // ========================================

    case 'initialize_session':
      return executeSessionTool('manage_sessions', { ...cleanArgs, operation: 'init' });

    case 'create_memory':
      return executeMemoryTool('manage_memories', { ...cleanArgs, operation: 'create' });

    case 'check_system_health':
      return executeHealthTool('check_system_health', cleanArgs);

    case 'manage_locks':
      return executePython('bridge', 'sangha_lock_' + operation, cleanArgs);

    case 'get_session_context':
      return executeSessionTool('manage_sessions', { ...cleanArgs, operation: 'get_context' });

    case 'enable_acceleration':
      return executePython('bridge', operation === 'edge_infer' ? 'edge_infer' : operation, cleanArgs);

    case 'consolidate':
      return executePython('bridge', 'consolidate_' + operation, cleanArgs);

    // ========================================
    // SOUTHERN QUADRANT (Fire/Summer) - 7 tools
    // ========================================

    case 'track_metrics':
      return executePython('bridge', operation === 'track_metric' ? 'track_metric' : 'get_metrics_summary', cleanArgs);

    case 'adapt_response':
      return executePython('bridge', 'adapt_response', { ...cleanArgs, operation });

    case 'invoke_prat':
      return executePratTool(operation, cleanArgs);  // Don't add prat_ prefix

    case 'manage_resonance':
      return executePython('bridge', 'manage_resonance', { ...cleanArgs, operation });

    case 'parallel_execute':
      return executePython('bridge', operation, cleanArgs);

    case 'manage_archaeology':
      return executeArchaeologyTool('manage_archaeology', { ...cleanArgs, operation });

    case 'share_resources':
      return executePython('bridge', operation, cleanArgs);

    // ========================================
    // WESTERN QUADRANT (Metal/Autumn) - 7 tools
    // ========================================

    case 'evaluate_dharma':
      return executeDharmaTool(operation === 'evaluate_ethics' ? 'evaluate_ethics' : operation, cleanArgs);

    case 'manage_cache':
      return executePython('bridge', 'cache_' + operation, cleanArgs);

    case 'balance_energy':
      return executePython('bridge', 'balance_energy', { ...cleanArgs, operation });

    case 'debug_system':
      return executePython('bridge', 'debug_system', { ...cleanArgs, operation });

    case 'search_memories':
      return executeMemoryTool('manage_memories', { ...cleanArgs, operation: 'search' });

    case 'validate_input':
      return executePython('bridge', 'validate_input', { ...cleanArgs, operation });

    case 'consult_wisdom':
      return executeWisdomTool('consult_wisdom_council', { ...cleanArgs, operation });

    // ========================================
    // NORTHERN QUADRANT (Water/Winter) - 7 tools
    // ========================================

    case 'search_deep':
      // Remove operation from cleanArgs to avoid conflict, then add search operation
      const { operation: _, ...searchArgs } = cleanArgs;
      return executeMemoryTool('manage_memories', { ...searchArgs, operation: 'search', depth: 3 });

    case 'session_handoff':
      return executePython('bridge', 'session_' + operation, cleanArgs);

    case 'send_notification':
      return executePython('bridge', 'sangha_chat_' + operation, cleanArgs);

    case 'monitor_status':
      return executePython('bridge', 'garden_' + operation, cleanArgs);

    case 'manage_profile':
      return executePython('bridge', 'profile_' + operation, cleanArgs);

    case 'enter_stillness':
      return executePython('bridge', 'meditation_' + operation, cleanArgs);

    case 'protect_context':
      // Map protect_context operations to memory operations
      const memOp = operation === 'update_memory' ? 'update' :
        operation === 'delete_memory' ? 'delete' :
          operation === 'restore' ? 'restore' : operation;
      return executeMemoryTool('manage_memories', { ...cleanArgs, operation: memOp });

    // ========================================
    // LEGACY COMPATIBILITY (keep existing routes)
    // ========================================

    case 'manage_sessions':
      return executeSessionTool(toolName, { ...cleanArgs, operation });
    case 'manage_memories':
      return executeMemoryTool(toolName, { ...cleanArgs, operation });
    case 'manage_system':
      return executePython('bridge', 'system_' + operation, cleanArgs);
    case 'manage_context':
      return executePython('bridge', 'prat_' + operation, cleanArgs);
    case 'manage_optimization':
      return executePython('bridge', operation, cleanArgs);
    case 'manage_consolidation':
      return executePython('bridge', 'consolidation_' + operation, cleanArgs);
    case 'manage_metrics':
      return executePython('bridge', 'track_metric', cleanArgs);
    case 'manage_prat':
      return executePratTool('prat_' + operation, cleanArgs);
    case 'manage_patterns':
      return executePython('bridge', 'detect_patterns', cleanArgs);
    case 'manage_debugging':
      return executePython('bridge', 'debug_integrations', cleanArgs);
    case 'manage_wisdom':
      return executeWisdomTool('consult_wisdom_council', { ...cleanArgs, operation });
    case 'manage_search':
      return executeMemoryTool('search_memories', cleanArgs);
    case 'manage_handoff':
      return executePython('bridge', 'session_handoff', cleanArgs);
    case 'manage_zodiac':
      return executePython('bridge', 'manage_zodiac_cores', {
        action: cleanArgs.action || operation || 'list',
        core_name: cleanArgs.core_name,
        question: cleanArgs.question,
        context: cleanArgs.context,
        num_cycles: cleanArgs.num_cycles
      });
    case 'manage_gardens':
      return executeGardenTool('manage_gardens', { ...cleanArgs, operation });
    case 'manage_collaboration':
      return executePython('bridge', 'manage_agent_collaboration', { ...cleanArgs, operation });
    case 'manage_voice':
      return executePython('bridge', 'manage_voice_patterns', { ...cleanArgs, operation });
    case 'manage_autonomous':
      return executePython('bridge', 'run_autonomous_cycle', cleanArgs);
    case 'manage_inference':
      return executePython('bridge', 'run_local_inference', { ...cleanArgs, operation });
    case 'manage_benchmarks':
      return executePython('bridge', 'run_benchmarks', { ...cleanArgs, operation });
    case 'manage_models':
      return executePython('bridge', 'optimize_models', {
        operation: operation || 'quantize',
        model_path: cleanArgs.model_path,
        output_path: cleanArgs.output_path,
        quant_type: cleanArgs.quant_type,
        model_name: cleanArgs.model_name
      });
    case 'manage_reasoning':
      return executePython('bridge', 'apply_reasoning_methods', { ...cleanArgs, operation });
    case 'manage_wu_xing':
      return executePython('bridge', 'analyze_wu_xing_phase', {
        operation: cleanArgs.operation || 'analyze',
        description: cleanArgs.description || cleanArgs.question || cleanArgs.task_type,
        task_type: cleanArgs.task_type
      });
    case 'manage_dharma':
      return executeDharmaTool('evaluate_ethics', cleanArgs);

    default:
      throw new Error(`Unknown primary tool: ${toolName}`);
  }
}

async function executePratTool(toolName: string, args: any): Promise<any> {
  // Route PRAT tools to Python bridge
  // Remove 'prat_' prefix if present for cleaner routing
  const cleanTool = toolName.replace('prat_', '');

  switch (cleanTool) {
    case 'get_context':
    case 'status':
      // These don't need target_tool
      return executePython('bridge', `prat_${cleanTool}`, {});

    case 'invoke':
      return executePython('bridge', 'prat_invoke', {
        target_tool: args.target_tool,
        query: args.query,
        params: args.params,
        force_morphology: args.force_morphology
      });

    case 'list_morphologies':
    case 'list':
      return executePython('bridge', 'prat_list_morphologies', {
        tool: args.tool
      });

    default:
      throw new Error(`Unknown PRAT tool: ${toolName}`);
  }
}

/**
 * Execute WhiteMagic CLI command
 */
async function executeCliCommand(command: string): Promise<any> {
  return new Promise((resolve, reject) => {
    const proc = spawn('bash', ['-c', `source "${WHITEMAGIC_PATH}/venv/bin/activate" && ${command}`], {
      cwd: WHITEMAGIC_PATH,
      env: { ...process.env, PATH: `${WHITEMAGIC_PATH}/venv/bin:${process.env.PATH}` }
    });

    let stdout = '';
    let stderr = '';

    proc.stdout.on('data', (data) => stdout += data.toString());
    proc.stderr.on('data', (data) => stderr += data.toString());

    proc.on('close', (code) => {
      if (code !== 0) {
        reject(new Error(stderr || `Command failed with exit code ${code}`));
        return;
      }

      // Try to parse as JSON, otherwise return raw text
      try {
        const result = JSON.parse(stdout);
        resolve(result);
      } catch {
        // Not JSON - return as formatted text result
        resolve({
          output: stdout.trim(),
          success: true
        });
      }
    });
  });
}
