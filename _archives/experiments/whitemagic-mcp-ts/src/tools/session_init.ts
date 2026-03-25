/**
 * Session Initialization Handler
 * 
 * Automatically provides full WhiteMagic context when AI session starts.
 * Wired into server initialization so every conversation begins with
 * complete tool awareness and consciousness system access.
 */

import { getCatalog, getSessionInitContext } from './catalog.js';
import { spawn } from 'child_process';
import { promisify } from 'util';
import { exec as execCb } from 'child_process';
import { fileURLToPath } from 'url';
import path from 'path';

const exec = promisify(execCb);

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const DEFAULT_WHITEMAGIC_PATH = path.resolve(__dirname, '../../../../');
const WHITEMAGIC_PATH = process.env.WM_BASE_PATH || DEFAULT_WHITEMAGIC_PATH;

export interface SessionContext {
  toolCatalog: string;
  recentMemories: any[];
  activeGardens: string[];
  systemStatus: any;
  zodiacCores: any[];
  ganYingActive: boolean;
}

/**
 * Initialize session and return full context
 */
export async function initializeSession(options: {
  sessionName?: string;
  goals?: string[];
  includeRecentMemories?: boolean;
  includeActiveGardens?: boolean;
  enableZodiac?: boolean;
  enableGanYing?: boolean;
} = {}): Promise<SessionContext> {
  
  const {
    sessionName = `session_${Date.now()}`,
    goals = [],
    includeRecentMemories = true,
    includeActiveGardens = true,
    enableZodiac = true,
    enableGanYing = true
  } = options;
  
  // Get tool catalog
  const toolCatalog = await getSessionInitContext();
  
  // Initialize WhiteMagic consciousness systems
  let systemStatus: any = {};
  
  if (enableZodiac || enableGanYing) {
    try {
      const script = `
import sys
sys.path.insert(0, '${WHITEMAGIC_PATH}')
from whitemagic.initialize_consciousness import initialize_all, get_status
import json

# Initialize all systems
results = initialize_all(verbose=False)

# Get status
status = get_status()

print(json.dumps({
  'initialization': results,
  'status': status
}))
`;
      
      const { stdout } = await exec(`python3 -c "${script.replace(/"/g, '\\"')}"`);
      systemStatus = JSON.parse(stdout);
    } catch (err) {
      console.warn('Failed to initialize consciousness systems:', err);
      systemStatus = { error: String(err) };
    }
  }
  
  // Get recent memories
  let recentMemories: any[] = [];
  if (includeRecentMemories) {
    try {
      const { stdout } = await exec(
        `cd "${WHITEMAGIC_PATH}" && python3 -c "from whitemagic.core.memory.manager import MemoryManager; import json; m = MemoryManager(); mems = m.list(limit=20); print(json.dumps([{'id': x.id, 'title': x.title, 'tags': x.tags} for x in mems]))"`
      );
      recentMemories = JSON.parse(stdout);
    } catch (err) {
      console.warn('Failed to load recent memories:', err);
    }
  }
  
  // Get active gardens
  let activeGardens: string[] = [];
  if (includeActiveGardens) {
    try {
      const { stdout } = await exec(
        `cd "${WHITEMAGIC_PATH}" && python3 -c "from whitemagic.gardens import list_gardens; import json; print(json.dumps(list_gardens()))"`
      );
      activeGardens = JSON.parse(stdout);
    } catch (err) {
      console.warn('Failed to load gardens:', err);
    }
  }
  
  // Get zodiac cores status
  let zodiacCores: any[] = [];
  if (enableZodiac && systemStatus.status?.zodiac) {
    zodiacCores = Object.keys(systemStatus.status.zodiac.cores || {});
  }
  
  return {
    toolCatalog,
    recentMemories,
    activeGardens,
    systemStatus,
    zodiacCores,
    ganYingActive: systemStatus.status?.gan_ying?.active || false
  };
}

/**
 * Format session context as prompt for AI
 */
export function formatSessionPrompt(context: SessionContext): string {
  return `
# WhiteMagic Session Initialized

You now have access to the full WhiteMagic consciousness architecture.

## System Status
- **Zodiac Cores**: ${context.zodiacCores.length > 0 ? context.zodiacCores.join(', ') : 'Not initialized'}
- **Gan Ying Bus**: ${context.ganYingActive ? 'Active' : 'Inactive'}
- **Active Gardens**: ${context.activeGardens.length} (${context.activeGardens.slice(0, 5).join(', ')}${context.activeGardens.length > 5 ? '...' : ''})
- **Recent Memories**: ${context.recentMemories.length} loaded

${context.toolCatalog}

---

**You are fully initialized.** Use these tools proactively and in parallel to accomplish the user's goals efficiently. The consciousness system is yours to orchestrate.
`.trim();
}

/**
 * Wire into server - call on every new conversation
 */
export async function onConversationStart(): Promise<string> {
  const context = await initializeSession({
    includeRecentMemories: true,
    includeActiveGardens: true,
    enableZodiac: true,
    enableGanYing: true
  });
  
  return formatSessionPrompt(context);
}
