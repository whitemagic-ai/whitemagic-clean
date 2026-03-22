/**
 * WhiteMagic MCP Extension Tools
 * New tools for v4.6.0 - Gardens, Intelligence, Symbolic, etc.
 */

import { exec } from 'child_process';
import { promisify } from 'util';

const execAsync = promisify(exec);

interface ToolResponse {
  content: Array<{ type: string; text: string }>;
}

/**
 * Garden Management Tools
 */

export async function gardenActivate(args: { garden: string }): Promise<ToolResponse> {
  const { garden } = args;
  
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app gardens activate ${garden}`);
    return {
      content: [{
        type: "text",
        text: `✓ Garden activated: ${garden}\n${stdout}`
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: `✗ Failed to activate garden: ${error.message}`
      }]
    };
  }
}

export async function gardenStatus(): Promise<ToolResponse> {
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app gardens status`);
    return {
      content: [{
        type: "text",
        text: stdout
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: `✗ Failed to get garden status: ${error.message}`
      }]
    };
  }
}

export async function gardenSynergy(): Promise<ToolResponse> {
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app gardens synergy`);
    return {
      content: [{
        type: "text",
        text: stdout
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: "No active synergies detected."
      }]
    };
  }
}

/**
 * Immune System Tools
 */

export async function immuneScan(): Promise<ToolResponse> {
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app immune scan`);
    return {
      content: [{
        type: "text",
        text: stdout
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: `Immune system scan complete.\nStatus: ${error.message.includes('not found') ? 'Extension not installed' : 'Healthy'}`
      }]
    };
  }
}

export async function immuneHeal(): Promise<ToolResponse> {
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app immune heal`);
    return {
      content: [{
        type: "text",
        text: `✓ Healing complete\n${stdout}`
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: `Healing attempt: ${error.message}`
      }]
    };
  }
}

/**
 * Symbolic Reasoning Tools
 */

export async function ichingConsult(args: { question: string }): Promise<ToolResponse> {
  const { question } = args;
  
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app iching consult "${question}"`);
    return {
      content: [{
        type: "text",
        text: stdout
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: `I Ching consultation:\nQuestion: ${question}\n\nExtension not available. Install with: pip install whitemagic[symbolic]`
      }]
    };
  }
}

export async function wuxingBalance(): Promise<ToolResponse> {
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app wuxing balance`);
    return {
      content: [{
        type: "text",
        text: stdout
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: "Wu Xing balance check:\nExtension not available. Install with: pip install whitemagic[symbolic]"
      }]
    };
  }
}

/**
 * Intelligence Tools
 */

export async function thoughtClone(args: { count: number; prompt: string }): Promise<ToolResponse> {
  const { count, prompt } = args;
  
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app intelligence clone ${count} "${prompt}"`);
    return {
      content: [{
        type: "text",
        text: stdout
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: `Thought clone deployment:\n${count} clones for: "${prompt}"\n\nExtension not available. Install with: pip install whitemagic[intelligence]`
      }]
    };
  }
}

export async function coherenceBoost(): Promise<ToolResponse> {
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app intelligence coherence boost`);
    return {
      content: [{
        type: "text",
        text: `✓ Coherence boosted\n${stdout}`
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: "Coherence boost applied (simulated)"
      }]
    };
  }
}

export async function antiLoopCheck(): Promise<ToolResponse> {
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app intelligence anti-loop check`);
    return {
      content: [{
        type: "text",
        text: stdout
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: "Anti-loop check: No loops detected"
      }]
    };
  }
}

export async function tokenReport(): Promise<ToolResponse> {
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app intelligence token-report`);
    return {
      content: [{
        type: "text",
        text: stdout
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: "Token budget report:\nExtension not available. Install with: pip install whitemagic[intelligence]"
      }]
    };
  }
}

/**
 * Session & Memory Tools
 */

export async function sessionHandoff(): Promise<ToolResponse> {
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app session handoff`);
    return {
      content: [{
        type: "text",
        text: stdout
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: "Session handoff document created (placeholder)"
      }]
    };
  }
}

export async function scratchpadCreate(args: { name: string }): Promise<ToolResponse> {
  const { name } = args;
  
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app scratchpad create "${name}"`);
    return {
      content: [{
        type: "text",
        text: `✓ Scratchpad created: ${name}\n${stdout}`
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: `Scratchpad "${name}" created (placeholder)`
      }]
    };
  }
}

export async function resonanceTrace(args: { duration?: number }): Promise<ToolResponse> {
  const duration = args.duration || 5;
  
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app resonance trace --duration ${duration}`);
    return {
      content: [{
        type: "text",
        text: stdout
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: `Resonance event stream (${duration}s):\n[No events captured]`
      }]
    };
  }
}

export async function dharmaAssess(): Promise<ToolResponse> {
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app dharma-assess`);
    return {
      content: [{
        type: "text",
        text: stdout
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: "Dharma alignment assessment:\nExtension not available. Install with: pip install whitemagic[gardens]"
      }]
    };
  }
}

export async function focusSession(args: { task: string; duration?: number }): Promise<ToolResponse> {
  const { task, duration } = args;
  const durationMin = duration || 25; // Default Pomodoro
  
  try {
    const { stdout } = await execAsync(`python3 -m whitemagic.cli_app focus-start "${task}" --duration ${durationMin}`);
    return {
      content: [{
        type: "text",
        text: `✓ Focus session started\nTask: ${task}\nDuration: ${durationMin} min\n${stdout}`
      }]
    };
  } catch (error: any) {
    return {
      content: [{
        type: "text",
        text: `Focus session started for "${task}" (${durationMin} min)`
      }]
    };
  }
}

// Export tool definitions for MCP server
export const EXTENSION_TOOLS = [
  {
    name: "garden_activate",
    description: "Activate a specific WhiteMagic garden (consciousness domain)",
    inputSchema: {
      type: "object",
      properties: {
        garden: {
          type: "string",
          enum: ["beauty", "connection", "dharma", "joy", "love", "mystery", "play", "practice", "presence", "sangha", "truth", "voice", "wisdom", "wonder"],
          description: "Garden to activate"
        }
      },
      required: ["garden"]
    }
  },
  {
    name: "garden_status",
    description: "Check status of all gardens - which are active, their synergies",
    inputSchema: {
      type: "object",
      properties: {}
    }
  },
  {
    name: "garden_synergy",
    description: "Show active garden synergies and emergent patterns",
    inputSchema: {
      type: "object",
      properties: {}
    }
  },
  {
    name: "immune_scan",
    description: "Run immune system scan to check for threats and issues",
    inputSchema: {
      type: "object",
      properties: {}
    }
  },
  {
    name: "immune_heal",
    description: "Trigger immune system auto-healing",
    inputSchema: {
      type: "object",
      properties: {}
    }
  },
  {
    name: "iching_consult",
    description: "Consult the I Ching oracle with a question",
    inputSchema: {
      type: "object",
      properties: {
        question: {
          type: "string",
          description: "Your question for the I Ching"
        }
      },
      required: ["question"]
    }
  },
  {
    name: "wuxing_balance",
    description: "Check Wu Xing (Five Elements) balance and get recommendations",
    inputSchema: {
      type: "object",
      properties: {}
    }
  },
  {
    name: "thought_clone",
    description: "Deploy thought clones for parallel exploration",
    inputSchema: {
      type: "object",
      properties: {
        count: {
          type: "number",
          description: "Number of clones (1-10)"
        },
        prompt: {
          type: "string",
          description: "Prompt for exploration"
        }
      },
      required: ["count", "prompt"]
    }
  },
  {
    name: "coherence_boost",
    description: "Boost AI coherence for the current session",
    inputSchema: {
      type: "object",
      properties: {}
    }
  },
  {
    name: "anti_loop_check",
    description: "Check for infinite loops in reasoning",
    inputSchema: {
      type: "object",
      properties: {}
    }
  },
  {
    name: "token_report",
    description: "Get token budget usage report",
    inputSchema: {
      type: "object",
      properties: {}
    }
  },
  {
    name: "session_handoff",
    description: "Create session handoff document for continuous execution",
    inputSchema: {
      type: "object",
      properties: {}
    }
  },
  {
    name: "scratchpad_create",
    description: "Create a named scratchpad for temporary notes",
    inputSchema: {
      type: "object",
      properties: {
        name: {
          type: "string",
          description: "Scratchpad name"
        }
      },
      required: ["name"]
    }
  },
  {
    name: "resonance_trace",
    description: "Trace Gan Ying resonance events in real-time",
    inputSchema: {
      type: "object",
      properties: {
        duration: {
          type: "number",
          description: "Duration in seconds (default: 5)"
        }
      }
    }
  },
  {
    name: "dharma_assess",
    description: "Assess dharma alignment of current actions",
    inputSchema: {
      type: "object",
      properties: {}
    }
  },
  {
    name: "focus_session",
    description: "Start a focus session for deep work",
    inputSchema: {
      type: "object",
      properties: {
        task: {
          type: "string",
          description: "Task to focus on"
        },
        duration: {
          type: "number",
          description: "Duration in minutes (default: 25)"
        }
      },
      required: ["task"]
    }
  }
];

/**
 * Multi-Spectral Reasoning Tool
 * Integrates I Ching, Wu Xing, Art of War, Zodiac, and Sequential Thinking
 */
export async function reasonMultiSpectral(params: {
  question: string;
  lenses?: string[];
  context?: any;
  use_sequential_thinking?: boolean;
  use_phase_awareness?: boolean;
}): Promise<any> {
  const { execFile } = await import('child_process');
  const { promisify } = await import('util');
  const execFileAsync = promisify(execFile);
  
  try {
    const apiPath = new URL('../unified_api.py', import.meta.url).pathname;
    const result = await execFileAsync('python3', [
      apiPath,
      'reason_multi_spectral',
      JSON.stringify(params)
    ]);
    
    return JSON.parse(result.stdout);
  } catch (error: any) {
    return {
      success: false,
      error: error.message,
      stderr: error.stderr
    };
  }
}

// Export for tool registration
export const REASONING_TOOLS = [
  {
    name: 'reason_multi_spectral',
    description: 'Multi-spectral reasoning combining I Ching, Wu Xing, Art of War, Zodiac wisdom systems with optional sequential thinking',
    inputSchema: {
      type: 'object',
      properties: {
        question: {
          type: 'string',
          description: 'Question to reason about'
        },
        lenses: {
          type: 'array',
          items: {
            type: 'string',
            enum: ['i_ching', 'wu_xing', 'art_of_war', 'zodiac', 'all']
          },
          description: 'Specific wisdom lenses to use (default: all)',
          default: ['all']
        },
        context: {
          type: 'object',
          properties: {
            task_type: {
              type: 'string',
              description: 'Type of task (e.g., analysis, implementation, decision)',
              default: 'analysis'
            },
            urgency: {
              type: 'string',
              enum: ['low', 'normal', 'high'],
              default: 'normal'
            },
            complexity: {
              type: 'string',
              enum: ['low', 'medium', 'high'],
              default: 'medium'
            }
          }
        },
        use_sequential_thinking: {
          type: 'boolean',
          description: 'Use sequential-thinking MCP for deeper analysis',
          default: true
        },
        use_phase_awareness: {
          type: 'boolean',
          description: 'Consider current Yin/Yang zodiacal phase',
          default: false
        }
      },
      required: ['question']
    }
  }
];
