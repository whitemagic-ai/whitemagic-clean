/**
 * Reasoning Bridge - TypeScript handlers for multi-spectral reasoning
 */

import { execFile } from 'child_process';
import { promisify } from 'util';
import { fileURLToPath } from 'url';
import { dirname, join } from 'path';

const execFileAsync = promisify(execFile);

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

export async function reasonMultiSpectral(params: {
  question: string;
  lenses?: string[];
  context?: any;
  use_sequential_thinking?: boolean;
  use_phase_awareness?: boolean;
}): Promise<any> {
  try {
    const apiPath = join(__dirname, 'unified_api.py');
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

export const REASONING_TOOL_DEFINITION = {
  name: 'reason_multi_spectral',
  description: 'Multi-spectral reasoning combining I Ching, Wu Xing, Art of War, Zodiac wisdom systems with optional sequential thinking and phase awareness',
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
};
