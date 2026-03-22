/**
 * Unified Tool Registry - Single Source of Truth
 * Consolidates tools-extended, tools-extensions, edge-tools
 * 
 * Phase A.1: MCP 2.0 - Unified tool definitions
 */

export interface ToolDefinition {
  name: string;
  description: string;
  category:
    | 'memory'
    | 'session'
    | 'garden'
    | 'metrics'
    | 'edge'
    | 'system'
    | 'archaeology'
    | 'dharma'
    | 'synthesis';
  safety: 'read' | 'write' | 'delete';
  inputSchema: {
    type: 'object';
    properties: Record<string, any>;
    required?: string[];
  };
}

export interface TypedError {
  code: 'NOT_FOUND' | 'VALIDATION' | 'UNAVAILABLE' | 'DENIED' | 'TIMEOUT' | 'INTERNAL';
  message: string;
  hint?: string;
  duration_ms?: number;
  cache_hit?: boolean;
}

/**
 * All MCP tools in one registry
 */
export const TOOL_REGISTRY: ToolDefinition[] = [
  // Memory Tools
  {
    name: 'create_memory',
    description: 'Create a new memory entry (short-term or long-term)',
    category: 'memory',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        title: {
          type: 'string',
          description: 'Memory title',
        },
        content: {
          type: 'string',
          description: 'Memory content (markdown supported)',
        },
        type: {
          type: 'string',
          enum: ['short_term', 'long_term'],
          description: 'Memory type',
          default: 'short_term',
        },
        tags: {
          type: 'array',
          items: { type: 'string' },
          description: 'Tags for categorization',
          default: [],
        },
      },
      required: ['title', 'content'],
    },
  },
  {
    name: 'search_memories',
    description: 'Search memories by query, type, and tags',
    category: 'memory',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        query: {
          type: 'string',
          description: 'Search query (searches title, content, and tags)',
        },
        type: {
          type: 'string',
          enum: ['short_term', 'long_term'],
          description: 'Filter by memory type',
        },
        tags: {
          type: 'array',
          items: { type: 'string' },
          description: 'Filter by tags (AND logic)',
        },
        include_archived: {
          type: 'boolean',
          description: 'Include archived memories',
          default: false,
        },
      },
    },
  },

  // Archaeology Tools
  {
    name: 'archaeology_mark_read',
    description: 'Mark a file as read for context awareness',
    category: 'archaeology',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        path: { type: 'string', description: 'File path' },
        context: { type: 'string', description: 'Read context' },
        note: { type: 'string', description: 'Optional note' },
        insight: { type: 'string', description: 'Key insight from the file' },
      },
      required: ['path'],
    },
  },
  {
    name: 'archaeology_mark_written',
    description: 'Mark a file as written for context awareness',
    category: 'archaeology',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        path: { type: 'string', description: 'File path' },
        context: { type: 'string', description: 'Write context' },
        note: { type: 'string', description: 'Optional note' },
      },
      required: ['path'],
    },
  },
  {
    name: 'archaeology_have_read',
    description: 'Check if a file has been read',
    category: 'archaeology',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        path: { type: 'string', description: 'File path to check' },
      },
      required: ['path'],
    },
  },
  {
    name: 'archaeology_find_unread',
    description: 'Find unread files in a directory',
    category: 'archaeology',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        directory: { type: 'string', default: '.' },
        patterns: {
          type: 'array',
          items: { type: 'string' },
          description: 'Glob patterns to match',
        },
      },
    },
  },
  {
    name: 'archaeology_find_changed',
    description: 'Find files that have changed since they were last read',
    category: 'archaeology',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        directory: { type: 'string', description: 'Directory to scan' },
      },
    },
  },
  {
    name: 'archaeology_recent_reads',
    description: 'Get recently read files',
    category: 'archaeology',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        limit: { type: 'integer', default: 50 },
      },
    },
  },
  {
    name: 'archaeology_stats',
    description: 'Get archaeology statistics',
    category: 'archaeology',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        scan_disk: {
          type: 'boolean',
          description: 'Perform a real-time disk usage scan (slower)',
          default: false
        }
      },
    },
  },
  {
    name: 'archaeology_report',
    description: 'Generate a human-readable archaeology report',
    category: 'archaeology',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {},
    },
  },
  {
    name: 'archaeology_scan',
    description: 'Scan a directory for files and track them in archaeology system',
    category: 'archaeology',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        directory: { type: 'string', description: 'Directory to scan' },
        depth: { type: 'integer', description: 'Scan depth (default: 3)', default: 3 },
        recursive: { type: 'boolean', description: 'Recursive scan', default: true },
        patterns: { type: 'array', items: { type: 'string' }, description: 'File patterns to match' }
      },
      required: ['directory']
    }
  },
  {
    name: 'archaeology_search',
    description: 'Search archaeology entries by path, notes, or insights',
    category: 'archaeology',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        query: { type: 'string', description: 'Search query' },
      },
      required: ['query'],
    },
  },
  {
    name: 'archaeology_process_wisdom',
    description: 'Extract insights from memory archives and store as wisdom memories',
    category: 'archaeology',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        limit_files: { type: 'integer', default: 1000 },
        memory_type: {
          type: 'string',
          enum: ['short_term', 'long_term'],
          default: 'long_term',
        },
      },
    },
  },
  {
    name: 'archaeology_daily_digest',
    description: 'Create a daily wisdom digest from recent insights',
    category: 'archaeology',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {},
    },
  },
  {
    name: 'read_memory',
    description: 'Read full content of a specific memory',
    category: 'memory',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        filename: {
          type: 'string',
          description: 'Memory filename (e.g., "20251115_setup_wizard.md")',
        },
        include_metadata: {
          type: 'boolean',
          description: 'Include metadata (tags, dates, etc)',
          default: true,
        },
      },
      required: ['filename'],
    },
  },
  {
    name: 'fast_read_memory',
    description: '⚡ FAST: Read memory content with optimizations (10-100x faster)',
    category: 'memory',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        filename: {
          type: 'string',
          description: 'Memory filename (e.g., "20251115_setup_wizard.md")',
        },
        cache: {
          type: 'boolean',
          description: 'Use cache if available',
          default: true,
        },
        fast_mode: {
          type: 'boolean',
          description: 'Skip metadata parsing for maximum speed',
          default: true,
        },
      },
      required: ['filename'],
    },
  },
  {
    name: 'batch_read_memories',
    description: '⚡ BATCH: Read multiple memories in one operation',
    category: 'memory',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        filenames: {
          type: 'array',
          items: { type: 'string' },
          description: 'Array of memory filenames to read',
        },
        cache: {
          type: 'boolean',
          description: 'Use cache',
          default: true,
        },
        fast_mode: {
          type: 'boolean',
          description: 'Skip metadata parsing',
          default: true,
        },
      },
      required: ['filenames'],
    },
  },
  {
    name: 'parallel_search',
    description: '⚡ Search multiple queries in parallel (8x faster)',
    category: 'memory',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        queries: {
          type: 'array',
          items: { type: 'string' },
          description: 'List of search queries',
          minItems: 1,
        },
        deduplicate: {
          type: 'boolean',
          description: 'Remove duplicate results',
          default: true,
        },
      },
      required: ['queries'],
    },
  },
  {
    name: 'list_memories',
    description: 'List all memories with metadata (useful for browsing)',
    category: 'memory',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        include_archived: {
          type: 'boolean',
          description: 'Include archived memories',
          default: false,
        },
        sort_by: {
          type: 'string',
          enum: ['created', 'updated', 'accessed', 'title'],
          description: 'Sort order',
          default: 'created',
        },
        type: {
          type: 'string',
          enum: ['short_term', 'long_term'],
          description: 'Filter by memory type',
        },
      },
    },
  },
  {
    name: 'update_memory',
    description: "Update an existing memory's content, title, or tags",
    category: 'memory',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        filename: {
          type: 'string',
          description: 'Memory filename to update',
        },
        title: {
          type: 'string',
          description: 'New title (optional)',
        },
        content: {
          type: 'string',
          description: 'New content (optional)',
        },
        tags: {
          type: 'array',
          items: { type: 'string' },
          description: 'Replace all tags (optional)',
        },
        add_tags: {
          type: 'array',
          items: { type: 'string' },
          description: 'Add these tags (optional)',
        },
        remove_tags: {
          type: 'array',
          items: { type: 'string' },
          description: 'Remove these tags (optional)',
        },
      },
      required: ['filename'],
    },
  },
  {
    name: 'delete_memory',
    description: 'Delete or archive a memory',
    category: 'memory',
    safety: 'delete',
    inputSchema: {
      type: 'object',
      properties: {
        filename: {
          type: 'string',
          description: 'Memory filename to delete',
        },
        permanent: {
          type: 'boolean',
          description: 'If true, permanently delete; otherwise archive',
          default: false,
        },
      },
      required: ['filename'],
    },
  },
  {
    name: 'manage_memories',
    description: 'Unified memory management (create, search, read, update, delete, list)',
    category: 'memory',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        operation: {
          type: 'string',
          enum: ['create', 'search', 'read', 'update', 'delete', 'list'],
          description: 'Operation to perform',
          default: 'search'
        },
        title: {
          type: 'string',
          description: 'Memory title (for create)',
        },
        content: {
          type: 'string',
          description: 'Memory content (markdown, for create)',
        },
        type: {
          type: 'string',
          enum: ['short_term', 'long_term'],
          description: 'Memory type (for create/list)',
          default: 'short_term'
        },
        tags: {
          type: 'array',
          items: { type: 'string' },
          description: 'Tags for categorization',
          default: []
        },
        query: {
          type: 'string',
          description: 'Search query (for search)',
        },
        limit: {
          type: 'integer',
          description: 'Maximum results to return',
          default: 10
        },
        filename: {
          type: 'string',
          description: 'Memory filename (for read/update/delete)',
        },
        memory_id: {
          type: 'string',
          description: 'Memory ID (alternative to filename)',
        }
      },
    },
  },
  
  // Session Tools
  {
    name: 'create_session',
    description: 'Create new work session with automatic state management',
    category: 'session',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        name: {
          type: 'string',
          description: 'Session name',
        },
        goals: {
          type: 'array',
          items: { type: 'string' },
          description: 'Session goals',
        },
        tags: {
          type: 'array',
          items: { type: 'string' },
          description: 'Session tags',
        },
        auto_checkpoint: {
          type: 'boolean',
          default: true,
        },
        context_tier: {
          type: 'number',
          enum: [0, 1, 2],
          default: 1,
        },
      },
      required: ['name'],
    },
  },
  {
    name: 'create_scratchpad',
    description: 'Create temporary scratchpad for active work',
    category: 'session',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        name: {
          type: 'string',
          description: 'Scratchpad name',
        },
        session_id: {
          type: 'string',
          description: 'Associated session ID',
        },
      },
      required: ['name'],
    },
  },
  {
    name: 'update_scratchpad',
    description: 'Update specific scratchpad section',
    category: 'session',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        scratchpad_id: {
          type: 'string',
          description: 'Scratchpad ID',
        },
        section: {
          type: 'string',
          enum: ['current_focus', 'decisions', 'questions', 'next_steps', 'ideas'],
          description: 'Section to update',
        },
        content: {
          type: 'string',
          description: 'Content to add',
        },
      },
      required: ['scratchpad_id', 'section', 'content'],
    },
  },
  {
    name: 'finalize_scratchpad',
    description: 'Convert scratchpad to permanent memory',
    category: 'session',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        scratchpad_id: {
          type: 'string',
          description: 'Scratchpad ID',
        },
        memory_type: {
          type: 'string',
          enum: ['short_term', 'long_term'],
          default: 'short_term',
        },
      },
      required: ['scratchpad_id'],
    },
  },
  
  // Garden Tools
  {
    name: 'garden_activate',
    description: 'Activate a consciousness garden',
    category: 'garden',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        garden: {
          type: 'string',
          description: 'Garden name',
        },
      },
      required: ['garden'],
    },
  },
  {
    name: 'garden_status',
    description: 'Get garden activation status',
    category: 'garden',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {},
    },
  },
  {
    name: 'garden_health',
    description: 'Check garden health metrics',
    category: 'garden',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {},
    },
  },
  
  // Metrics Tools
  {
    name: 'track_metric',
    description: 'Record a quantitative metric (category/metric/value/context)',
    category: 'metrics',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        category: {
          type: 'string',
          description: 'Metric category (e.g., token_efficiency)',
        },
        metric: {
          type: 'string',
          description: 'Metric name (e.g., usage_percent)',
        },
        value: {
          type: 'number',
          description: 'Metric value',
        },
        context: {
          type: 'string',
          description: 'Optional context label',
        },
      },
      required: ['category', 'metric', 'value'],
    },
  },
  {
    name: 'get_metrics_summary',
    description: 'Retrieve metrics dashboard summary (optionally filtered by categories)',
    category: 'metrics',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        categories: {
          type: 'array',
          items: { type: 'string' },
          description: 'Categories to include',
        },
      },
    },
  },
  
  // Edge AI Tools
  {
    name: 'edge_infer',
    description: 'Local edge inference',
    category: 'edge',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        query: {
          type: 'string',
        },
      },
      required: ['query'],
    },
  },
  {
    name: 'edge_batch_infer',
    description: 'Batch edge inference',
    category: 'edge',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        queries: {
          type: 'array',
        },
      },
      required: ['queries'],
    },
  },
  
  // Sangha (Multi-Agent Coordination) Tools
  {
    name: 'sangha_chat_send',
    description: 'Send message to Sangha chat channel for multi-agent coordination',
    category: 'system',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        message: { type: 'string', description: 'Message content' },
        channel: { type: 'string', description: 'Channel name (default: general)' },
        sender: { type: 'string', description: 'Sender ID' },
        tags: { type: 'array', items: { type: 'string' }, description: 'Message tags' },
        priority: { type: 'string', enum: ['low', 'normal', 'high', 'urgent'], description: 'Message priority' },
      },
      required: ['message', 'sender'],
    },
  },
  {
    name: 'sangha_chat_read',
    description: 'Read messages from Sangha chat channel',
    category: 'system',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        channel: { type: 'string', description: 'Channel name (default: general)' },
        limit: { type: 'number', description: 'Number of messages to read' },
        priority: { type: 'string', enum: ['low', 'normal', 'high', 'urgent'], description: 'Filter by priority' },
      },
    },
  },
  {
    name: 'sangha_workspace_info',
    description: 'Get Sangha workspace configuration and status',
    category: 'system',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {},
    },
  },
  {
    name: 'sangha_lock_acquire',
    description: 'Acquire resource lock for multi-agent coordination (prevents conflicts)',
    category: 'system',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        resource: { type: 'string', description: 'Resource to lock (e.g., VERSION, pyproject.toml)' },
        reason: { type: 'string', description: 'Lock reason' },
        timeout: { type: 'number', description: 'Timeout in seconds (default: 3600)' },
      },
      required: ['resource'],
    },
  },
  {
    name: 'sangha_lock_release',
    description: 'Release resource lock',
    category: 'system',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        resource: { type: 'string', description: 'Resource to unlock' },
      },
      required: ['resource'],
    },
  },
  {
    name: 'sangha_lock_list',
    description: 'List active resource locks',
    category: 'system',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {},
    },
  },
  
  // Windsurf Tools
  {
    name: 'windsurf_backup',
    description: 'Backup Windsurf conversations for transfer between machines',
    category: 'system',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        destination: {
          type: 'string',
          description: 'Destination directory for backup (optional, defaults to windsurf_conversations_archive)',
          default: 'windsurf_conversations_archive'
        },
        compress: {
          type: 'boolean',
          description: 'Whether to compress the backup into a tar.gz file',
          default: false
        }
      }
    }
  },
  {
    name: 'windsurf_restore',
    description: 'Restore Windsurf conversations from a backup',
    category: 'system',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        backupPath: {
          type: 'string',
          description: 'Path to the backup directory or .tar.gz file',
          required: true
        }
      },
      required: ['backupPath']
    }
  },
  {
    name: 'windsurf_merge_backups',
    description: 'Merge multiple Windsurf backups into one unified backup',
    category: 'system',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        backupPaths: {
          type: 'array',
          items: { type: 'string' },
          description: 'Array of backup directory paths to merge',
          required: true
        },
        outputName: {
          type: 'string',
          description: 'Name for the merged backup (optional)',
          default: null
        }
      },
      required: ['backupPaths']
    }
  },

  // Dharma Tools (Phase 4 - Ethical Reasoning & Boundaries)
  {
    name: 'evaluate_ethics',
    description: 'Evaluate an action against ethical principles and get ethical score with concerns',
    category: 'dharma',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        action: {
          type: 'object',
          description: 'Action to evaluate (can include description, type, context)',
          additionalProperties: true,
        },
        context: {
          type: 'object',
          description: 'Additional context for evaluation',
          additionalProperties: true,
        },
      },
      required: ['action'],
    },
  },
  {
    name: 'check_boundaries',
    description: 'Check if an action violates any ethical boundaries (privacy, autonomy, transparency, capability)',
    category: 'dharma',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        action: {
          type: 'object',
          description: 'Action to check for boundary violations',
          additionalProperties: true,
        },
        strict_mode: {
          type: 'boolean',
          description: 'Use stricter boundary thresholds',
          default: false,
        },
      },
      required: ['action'],
    },
  },
  {
    name: 'verify_consent',
    description: 'Verify if proper consent has been obtained for an action',
    category: 'dharma',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        action: {
          type: 'object',
          description: 'Action requiring consent verification',
          additionalProperties: true,
        },
        consent_type: {
          type: 'string',
          enum: ['explicit', 'implicit', 'informed'],
          description: 'Type of consent to verify',
          default: 'explicit',
        },
      },
      required: ['action'],
    },
  },
  {
    name: 'get_guidance',
    description: 'Get ethical guidance for a situation based on Dharma principles',
    category: 'dharma',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        situation: {
          type: 'string',
          description: 'Description of the situation requiring guidance',
        },
        principles: {
          type: 'array',
          items: { type: 'string' },
          description: 'Specific principles to consider (optional)',
        },
      },
      required: ['situation'],
    },
  },
  {
    name: 'get_ethical_score',
    description: 'Get overall ethical score based on recent system actions',
    category: 'dharma',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        time_window_hours: {
          type: 'integer',
          description: 'Time window to consider (hours)',
          default: 24,
        },
      },
    },
  },
  {
    name: 'list_principles',
    description: 'List all ethical principles with their descriptions and weights',
    category: 'dharma',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        level: {
          type: 'string',
          enum: ['universal', 'compassion', 'integrity', 'harmony', 'wisdom'],
          description: 'Filter by dharma level',
        },
      },
    },
  },

  {
    name: 'view_hologram',
    description: 'Get a holographic snapshot of the memory space or query a specific sector',
    category: 'memory',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        operation: {
          type: 'string',
          enum: ['snapshot', 'query', 'status'],
          description: 'Operation to perform',
          default: 'snapshot'
        },
        x: { type: 'number', description: 'X coordinate (Logic-Emotion)', default: 0.0 },
        y: { type: 'number', description: 'Y coordinate (Micro-Macro)', default: 0.0 },
        z: { type: 'number', description: 'Z coordinate (Time)', default: 0.0 },
        w: { type: 'number', description: 'W coordinate (Importance)', default: 0.5 },
        limit: { type: 'integer', description: 'Max results for query', default: 10 }
      }
    }
  },

  // Cascade Tools (Phase 5 - MCP Cascade Intelligence)
  {
    name: 'execute_cascade',
    description: 'Execute an intelligent tool chain pattern with automatic Yin-Yang balance pacing. Decomposes complex tasks into parallel tool batches.',
    category: 'system',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        pattern_name: {
          type: 'string',
          description: 'Name of the cascade pattern (e.g., "analyze_codebase", "refactor_module", "debug_issue")',
        },
        context: {
          type: 'object',
          description: 'Context dictionary with inputs for the pattern',
          additionalProperties: true,
        },
        options: {
          type: 'object',
          description: 'Optional execution configuration (enable_yin_yang, max_parallel_calls, dry_run)',
        },
      },
      required: ['pattern_name', 'context'],
    },
  },
  {
    name: 'list_cascade_patterns',
    description: 'List all available cascade patterns with descriptions and expected inputs',
    category: 'system',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        tag: {
          type: 'string',
          description: 'Filter patterns by tag (e.g., "analysis", "debug", "refactor")',
        },
      },
    },
  },
  {
    name: 'get_cascade_pattern',
    description: 'Get detailed information about a specific cascade pattern including step breakdown',
    category: 'system',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        pattern_name: {
          type: 'string',
          description: 'Name of the pattern to retrieve',
        },
      },
      required: ['pattern_name'],
    },
  },

  // Synthesis Engine Tools (Kaizen - Continuous Improvement)
  {
    name: 'kaizen_analyze',
    description: 'Run Kaizen self-improvement analysis to find quality issues and improvement opportunities',
    category: 'synthesis',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        include_auto_fixable: {
          type: 'boolean',
          description: 'Include auto-fixable proposals',
          default: true,
        },
      },
    },
  },
  {
    name: 'kaizen_apply_fixes',
    description: 'Apply all auto-fixable Kaizen proposals (titles, tags, etc.)',
    category: 'synthesis',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        dry_run: {
          type: 'boolean',
          description: 'Preview changes without applying',
          default: false,
        },
      },
    },
  },
  {
    name: 'serendipity_surface',
    description: 'Surface dormant knowledge through intelligent random selection (high-gravity, rarely-accessed memories)',
    category: 'synthesis',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        count: {
          type: 'integer',
          description: 'Number of memories to surface',
          default: 5,
        },
        mode: {
          type: 'string',
          enum: ['balanced', 'dormant', 'ancient', 'bridge', 'random'],
          description: 'Surfacing mode',
          default: 'balanced',
        },
        context: {
          type: 'string',
          description: 'Optional context to bias selection',
        },
      },
    },
  },
  {
    name: 'serendipity_mark_accessed',
    description: 'Mark a surfaced memory as accessed (updates access count)',
    category: 'synthesis',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        memory_id: {
          type: 'string',
          description: 'ID of the memory to mark',
        },
      },
      required: ['memory_id'],
    },
  },
  {
    name: 'title_generate',
    description: 'Generate a descriptive title from memory content',
    category: 'synthesis',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        content: {
          type: 'string',
          description: 'Content to generate title from',
        },
      },
      required: ['content'],
    },
  },
  {
    name: 'title_fix_untitled',
    description: 'Fix all untitled memories by auto-generating titles',
    category: 'synthesis',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        dry_run: {
          type: 'boolean',
          description: 'Preview changes without applying',
          default: false,
        },
      },
    },
  },
  {
    name: 'tag_normalize',
    description: 'Normalize tags (lowercase, merge synonyms)',
    category: 'synthesis',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        dry_run: {
          type: 'boolean',
          description: 'Preview changes without applying',
          default: false,
        },
      },
    },
  },
  {
    name: 'tag_find_orphans',
    description: 'Find tags used only once (potential cleanup candidates)',
    category: 'synthesis',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {},
    },
  },
  {
    name: 'tag_find_similar',
    description: 'Find similar tags that might be duplicates',
    category: 'synthesis',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        threshold: {
          type: 'number',
          description: 'Similarity threshold (0.0-1.0)',
          default: 0.8,
        },
      },
    },
  },
  {
    name: 'tag_auto_tag',
    description: 'Auto-tag memories without tags by inferring from content',
    category: 'synthesis',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        dry_run: {
          type: 'boolean',
          description: 'Preview changes without applying',
          default: false,
        },
      },
    },
  },
  {
    name: 'cluster_stats',
    description: 'Get statistics about memory clustering in 4D holographic space',
    category: 'synthesis',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {},
    },
  },
  {
    name: 'cluster_find_large',
    description: 'Find large memory clusters that may need subdivision',
    category: 'synthesis',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        threshold: {
          type: 'integer',
          description: 'Minimum cluster size to consider "large"',
          default: 20,
        },
      },
    },
  },
  {
    name: 'cluster_subdivide',
    description: 'Subdivide large clusters into quadrant-based sub-clusters',
    category: 'synthesis',
    safety: 'write',
    inputSchema: {
      type: 'object',
      properties: {
        threshold: {
          type: 'integer',
          description: 'Minimum cluster size to subdivide',
          default: 20,
        },
        dry_run: {
          type: 'boolean',
          description: 'Preview changes without applying',
          default: false,
        },
      },
    },
  },
  {
    name: 'pattern_search',
    description: 'Search patterns across all pattern engines (core, holographic, edge)',
    category: 'synthesis',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {
        query: {
          type: 'string',
          description: 'Search query (optional)',
        },
        engines: {
          type: 'array',
          items: { type: 'string' },
          description: 'Engines to search (core, holographic, edge)',
        },
        min_confidence: {
          type: 'number',
          description: 'Minimum confidence threshold',
          default: 0.5,
        },
      },
    },
  },
  {
    name: 'pattern_correlations',
    description: 'Find correlations between patterns from different engines',
    category: 'synthesis',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {},
    },
  },
  {
    name: 'pattern_stats',
    description: 'Get statistics about all detected patterns',
    category: 'synthesis',
    safety: 'read',
    inputSchema: {
      type: 'object',
      properties: {},
    },
  },
];

/**
 * Tool aliases for backwards compatibility
 * Maps legacy tool names to primary tools (Phase 7 consolidation)
 */
export const TOOL_ALIASES: Record<string, string> = {
  // Session aliases → primary session tools
  "session_init": "initialize_session",
  "create_scratchpad": "initialize_session",
  "manage_sessions": "get_session_context",
  "get_session_context": "get_session_context",
  "session_get_context": "get_session_context",
  "session_handoff": "session_handoff",
  
  // Memory aliases → primary memory tools
  "remember": "create_memory",
  "recall": "search_memories",
  "memory_create": "create_memory",
  "memory_search": "search_memories",
  "read_memory": "search_memories",
  "update_memory": "protect_context",
  "delete_memory": "protect_context",
  "list_memories": "search_memories",
  "strengthen_memory": "protect_context",
  "link_memories": "protect_context",
  "consolidate_memories": "consolidate",
  
  // System aliases → primary system tools
  "initialize_systems": "check_system_health",
  "system_initialize_all": "check_system_health",
  "check_system_health": "check_system_health",
  "get_system_status": "monitor_status",
  // "validate_integrations": handled directly - has unique signature
  
  // Lock aliases → manage_locks
  "sangha_lock_acquire": "manage_locks",
  "sangha_lock_release": "manage_locks",
  "manage_resource_locks": "manage_locks",
  
  // Context/PRAT aliases - these have unique signatures, no aliasing
  // "prat_get_context": handled directly
  // "prat_invoke": handled directly
  // "prat_list_morphologies": handled directly
  // "prat_status": handled directly
  
  // Optimization aliases → enable_acceleration / manage_cache
  "enable_rust_acceleration": "enable_acceleration",
  "optimize_cache": "manage_cache",
  
  // Metrics aliases → track_metrics
  "track_metric": "track_metrics",
  "get_metrics_summary": "track_metrics",
  
  // Resonance aliases → manage_resonance
  "emit_resonance_event": "manage_resonance",
  "enable_async_gan_ying": "manage_resonance",
  "monitor_resonance": "manage_resonance",
  
  // Archaeology aliases → manage_archaeology
  "archaeology_scan_directory": "manage_archaeology",
  "archaeology_mark_read": "manage_archaeology",
  "archaeology_find_unread": "manage_archaeology",
  "archaeology_extract_wisdom": "manage_archaeology",
  "archaeology_generate_report": "manage_archaeology",
  
  // Pattern aliases (detect_patterns has its own implementation)
  "capture_pattern": "search_memories",
  "find_similar_problem": "search_memories",
  "add_lesson": "search_memories",
  
  // Debugging aliases → debug_system
  "debug_integrations": "debug_system",
  
  // Wisdom aliases → consult_wisdom
  "consult_wisdom_council": "consult_wisdom",
  "consult_iching": "consult_wisdom",
  
  // Wu Xing aliases → consult_wisdom
  "analyze_wu_xing_phase": "consult_wisdom",
  
  // Zodiac aliases → consult_wisdom (zodiac operations live in wisdom layer)
  "manage_zodiac_cores": "consult_wisdom",
  "zodiac_list_cores": "consult_wisdom",
  "activate_zodiac_core": "consult_wisdom",
  "zodiac_council": "consult_wisdom",
  
  // Garden aliases → monitor_status
  "list_gardens": "monitor_status",
  "activate_garden": "monitor_status",
  "trigger_garden_cascade": "monitor_status",
};

/**
 * Resolve tool name through aliases
 */
export function resolveToolAlias(toolName: string): string {
  return TOOL_ALIASES[toolName] || toolName;
}

/**
 * Get tools for MCP ListTools - optionally filtered by safety mode
 */
export function getToolsForMCP(safetyMode: 'safe' | 'full' = 'full') {
  let tools = TOOL_REGISTRY;
  
  if (safetyMode === 'safe') {
    // In safe mode, only expose read operations
    tools = tools.filter(t => t.safety === 'read');
  }
  
  return tools.map(tool => ({
    name: tool.name,
    description: `[${tool.category.toUpperCase()}${tool.safety === 'read' ? '' : ` | ${tool.safety.toUpperCase()}`}] ${tool.description}`,
    inputSchema: tool.inputSchema,
  }));
}

/**
 * Create typed error response
 */
export function createTypedError(
  code: TypedError['code'],
  message: string,
  hint?: string,
  duration_ms?: number
): TypedError {
  return {
    code,
    message,
    hint,
    duration_ms,
    cache_hit: false,
  };
}
