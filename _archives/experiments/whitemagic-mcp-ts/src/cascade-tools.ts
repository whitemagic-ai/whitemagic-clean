/**
 * Cascade Tools - MCP integration for intelligent tool chain orchestration
 *
 * Phase 5: MCP Cascade Intelligence Integration
 *
 * These tools expose the CascadeEngine to MCP clients (Claude, Windsurf, etc.)
 * enabling pattern-based tool chain execution with Yin-Yang balance tracking.
 */

import { Tool } from '@modelcontextprotocol/sdk/types.js';

/**
 * Result type for cascade execution
 */
export interface CascadeExecutionResult {
  success: boolean;
  results: Record<string, any>;
  metrics: {
    total_calls: number;
    num_batches: number;
    parallel_efficiency: number;
    balance_score?: number;
    burnout_risk?: number;
    yang_ratio?: number;
    duration?: number;
  };
  synthesis?: {
    pattern: string;
    confidence: number;
    recommendations: string[];
    key_findings?: string[];
  };
  error?: string;
}

/**
 * Pattern info for listing
 */
export interface CascadePatternInfo {
  name: string;
  description: string;
  expected_inputs: string[];
  tags: string[];
  step_count: number;
}

// ============================================================================
// Tool Definitions
// ============================================================================

/**
 * Execute a cascade pattern - the main orchestration tool
 */
export const executeCascadeTool: Tool = {
  name: 'execute_cascade',
  description: `Execute an intelligent tool chain pattern with automatic Yin-Yang balance pacing.

Cascade patterns decompose complex tasks into parallel tool batches, optimizing for:
- Dependency-based parallelism (concurrent tool calls where possible)
- Yin-Yang balance (pacing between reading and writing activities)
- Context synthesis (combining results from multiple tools)

Available patterns:
- analyze_codebase: Comprehensive codebase analysis with context loading
- refactor_module: Plan and execute module refactoring
- debug_issue: Systematic debugging with context gathering

Example usage:
  execute_cascade("analyze_codebase", {"query": "authentication flow", "module": "auth"})`,
  inputSchema: {
    type: 'object',
    properties: {
      pattern_name: {
        type: 'string',
        description: 'Name of the cascade pattern to execute (e.g., "analyze_codebase", "refactor_module", "debug_issue")',
      },
      context: {
        type: 'object',
        description: 'Context dictionary with inputs for the pattern (varies by pattern)',
        additionalProperties: true,
      },
      options: {
        type: 'object',
        description: 'Optional execution configuration',
        properties: {
          enable_yin_yang: {
            type: 'boolean',
            description: 'Enable Yin-Yang balance pacing (default: true)',
            default: true,
          },
          max_parallel_calls: {
            type: 'number',
            description: 'Maximum parallel tool calls per batch (default: 20)',
            default: 20,
          },
          dry_run: {
            type: 'boolean',
            description: 'If true, simulate execution without actually calling tools',
            default: false,
          },
        },
      },
    },
    required: ['pattern_name', 'context'],
  },
};

/**
 * List available cascade patterns
 */
export const listCascadePatternsTool: Tool = {
  name: 'list_cascade_patterns',
  description: `List all available cascade patterns with their descriptions and expected inputs.

Use this tool to discover what patterns are available before executing a cascade.
Each pattern includes:
- Name and description
- Expected input parameters
- Tags for categorization
- Number of steps in the pattern`,
  inputSchema: {
    type: 'object',
    properties: {
      tag: {
        type: 'string',
        description: 'Filter patterns by tag (e.g., "analysis", "debug", "refactor")',
      },
    },
  },
};

/**
 * Get details about a specific cascade pattern
 */
export const getCascadePatternTool: Tool = {
  name: 'get_cascade_pattern',
  description: `Get detailed information about a specific cascade pattern including its steps.

Returns the full pattern definition with:
- Step-by-step breakdown of tool calls
- Dependencies between steps
- Activity types (Yin/Yang classification)
- Parameter templates`,
  inputSchema: {
    type: 'object',
    properties: {
      pattern_name: {
        type: 'string',
        description: 'Name of the pattern to retrieve details for',
      },
    },
    required: ['pattern_name'],
  },
};

// ============================================================================
// Handler Functions
// ============================================================================

/**
 * Handle execute_cascade tool call
 */
export async function handleExecuteCascade(
  args: {
    pattern_name: string;
    context: Record<string, any>;
    options?: {
      enable_yin_yang?: boolean;
      max_parallel_calls?: number;
      dry_run?: boolean;
    };
  },
  client: { call: (method: string, params: Record<string, any>) => Promise<any> }
): Promise<CascadeExecutionResult> {
  const { pattern_name, context, options = {} } = args;

  try {
    // Call Python CascadeEngine via client
    const result = await client.call('execute_cascade', {
      pattern_name,
      context,
      enable_yin_yang: options.enable_yin_yang ?? true,
      max_parallel_calls: options.max_parallel_calls ?? 20,
      dry_run: options.dry_run ?? false,
    });

    return result;
  } catch (error: any) {
    return {
      success: false,
      results: {},
      metrics: {
        total_calls: 0,
        num_batches: 0,
        parallel_efficiency: 0,
      },
      error: error.message || 'Unknown error executing cascade',
    };
  }
}

/**
 * Handle list_cascade_patterns tool call
 */
export async function handleListCascadePatterns(
  args: { tag?: string },
  client: { call: (method: string, params: Record<string, any>) => Promise<any> }
): Promise<{ patterns: CascadePatternInfo[] }> {
  try {
    const result = await client.call('list_cascade_patterns', {
      tag: args.tag,
    });

    return result;
  } catch (error: any) {
    return {
      patterns: [],
    };
  }
}

/**
 * Handle get_cascade_pattern tool call
 */
export async function handleGetCascadePattern(
  args: { pattern_name: string },
  client: { call: (method: string, params: Record<string, any>) => Promise<any> }
): Promise<{
  found: boolean;
  pattern?: {
    name: string;
    description: string;
    expected_inputs: string[];
    tags: string[];
    steps: Array<{
      tool_name: string;
      description: string;
      params: Record<string, any>;
      activity_type: string;
      depends_on: string[];
      optional: boolean;
    }>;
  };
  error?: string;
}> {
  try {
    const result = await client.call('get_cascade_pattern', {
      pattern_name: args.pattern_name,
    });

    return result;
  } catch (error: any) {
    return {
      found: false,
      error: error.message || `Pattern '${args.pattern_name}' not found`,
    };
  }
}

// ============================================================================
// Tool Registry Export
// ============================================================================

/**
 * All cascade tools for registration in the main MCP server
 */
export const CASCADE_TOOLS: Tool[] = [
  executeCascadeTool,
  listCascadePatternsTool,
  getCascadePatternTool,
];

/**
 * Tool handler map for routing in index.ts
 */
export const CASCADE_TOOL_HANDLERS = {
  execute_cascade: handleExecuteCascade,
  list_cascade_patterns: handleListCascadePatterns,
  get_cascade_pattern: handleGetCascadePattern,
};
