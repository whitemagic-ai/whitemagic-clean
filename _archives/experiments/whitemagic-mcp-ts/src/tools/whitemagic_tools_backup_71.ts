/**
 * Manual WhiteMagic Tool Definitions
 * 
 * These are manually defined since WhiteMagic uses CLI decorators and classes
 * rather than module-level functions that the generator expects.
 */

import { ToolDefinition } from './catalog.js';

export function getWhiteMagicTools(): ToolDefinition[] {
  return [
    // Zodiac Tools
    {
      name: 'list_zodiac_cores',
      description: 'List all 12 zodiac consciousness cores with their properties',
      category: 'zodiac',
      module: 'zodiac',
      inputSchema: {
        type: 'object',
        properties: {}
      }
    },
    {
      name: 'activate_zodiac_core',
      description: 'Activate a specific zodiac core for specialized cognition (aries, taurus, gemini, cancer, leo, virgo, libra, scorpio, sagittarius, capricorn, aquarius, pisces)',
      category: 'zodiac',
      module: 'zodiac',
      inputSchema: {
        type: 'object',
        properties: {
          core_name: { type: 'string', description: 'Name of core to activate' },
          context: { type: 'object', description: 'Context for activation' }
        },
        required: ['core_name']
      }
    },
    {
      name: 'zodiac_council',
      description: 'Consult multiple zodiac cores for multi-perspective analysis on a question or decision',
      category: 'zodiac',
      module: 'zodiac',
      inputSchema: {
        type: 'object',
        properties: {
          question: { type: 'string', description: 'Question or topic to analyze' },
          cores: { type: 'array', items: { type: 'string' }, description: 'Specific cores to consult (optional)' }
        },
        required: ['question']
      }
    },
    {
      name: 'run_zodiacal_round',
      description: 'Run autonomous 12-phase zodiacal cycle for self-evolving analysis',
      category: 'zodiac',
      module: 'zodiac',
      inputSchema: {
        type: 'object',
        properties: {
          num_cycles: { type: 'number', description: 'Number of complete cycles', default: 1 },
          context: { type: 'object', description: 'Starting context' }
        }
      }
    },
    
    // Garden Tools
    {
      name: 'list_gardens',
      description: 'List all 27 consciousness gardens available for thought organization',
      category: 'garden',
      module: 'gardens',
      inputSchema: {
        type: 'object',
        properties: {}
      }
    },
    {
      name: 'activate_garden',
      description: 'Enter a specific garden (wisdom, creation, courage, mystery, transformation, healing, dharma, love, joy, etc.)',
      category: 'garden',
      module: 'gardens',
      inputSchema: {
        type: 'object',
        properties: {
          garden_name: { type: 'string', description: 'Name of garden to activate' }
        },
        required: ['garden_name']
      }
    },
    {
      name: 'trigger_garden_cascade',
      description: 'Trigger resonance cascade from a garden to related gardens',
      category: 'garden',
      module: 'gardens',
      inputSchema: {
        type: 'object',
        properties: {
          garden_name: { type: 'string', description: 'Starting garden' },
          depth: { type: 'number', description: 'Cascade depth', default: 2 }
        },
        required: ['garden_name']
      }
    },
    
    // Gan Ying (Resonance) Tools
    {
      name: 'emit_resonance_event',
      description: 'Emit a resonance event to the Gan Ying bus for sympathetic propagation',
      category: 'resonance',
      module: 'gan_ying',
      inputSchema: {
        type: 'object',
        properties: {
          event_type: { type: 'string', description: 'Type of event' },
          source: { type: 'string', description: 'Event source' },
          data: { type: 'object', description: 'Event data' }
        },
        required: ['event_type', 'source']
      }
    },
    {
      name: 'enable_async_gan_ying',
      description: 'Enable high-throughput async mode for Gan Ying (10k+ events/sec)',
      category: 'resonance',
      module: 'gan_ying',
      inputSchema: {
        type: 'object',
        properties: {}
      }
    },
    
    // Wu Xing (Five Phases) Tools
    {
      name: 'analyze_wu_xing_phase',
      description: 'Analyze which Wu Xing phase (Wood, Fire, Earth, Metal, Water) a task or situation belongs to',
      category: 'wu_xing',
      module: 'wu_xing',
      inputSchema: {
        type: 'object',
        properties: {
          description: { type: 'string', description: 'Task or situation to analyze' }
        },
        required: ['description']
      }
    },
    {
      name: 'get_phase_recommendations',
      description: 'Get recommendations for optimal timing based on Wu Xing phase',
      category: 'wu_xing',
      module: 'wu_xing',
      inputSchema: {
        type: 'object',
        properties: {
          task_type: { type: 'string', description: 'Type of task' }
        },
        required: ['task_type']
      }
    },
    
    // Neural Memory Tools
    {
      name: 'strengthen_memory',
      description: 'Strengthen a memory through Hebbian learning (neurons that fire together wire together)',
      category: 'memory',
      module: 'neural',
      inputSchema: {
        type: 'object',
        properties: {
          memory_id: { type: 'string', description: 'ID of memory to strengthen' }
        },
        required: ['memory_id']
      }
    },
    {
      name: 'link_memories',
      description: 'Create a semantic link between two memories',
      category: 'memory',
      module: 'neural',
      inputSchema: {
        type: 'object',
        properties: {
          source_id: { type: 'string', description: 'Source memory ID' },
          target_id: { type: 'string', description: 'Target memory ID' },
          link_type: { type: 'string', description: 'Type of link (causal, temporal, semantic, etc.)' }
        },
        required: ['source_id', 'target_id']
      }
    },
    
    // System Tools
    {
      name: 'initialize_all_systems',
      description: 'Initialize all WhiteMagic consciousness systems (Zodiac, Gan Ying, Neural Memory, Wu Xing)',
      category: 'system',
      module: 'initialization',
      inputSchema: {
        type: 'object',
        properties: {
          verbose: { type: 'boolean', description: 'Verbose output', default: false }
        }
      }
    },
    {
      name: 'get_system_status',
      description: 'Get comprehensive status of all WhiteMagic systems',
      category: 'system',
      module: 'initialization',
      inputSchema: {
        type: 'object',
        properties: {}
      }
    },
    {
      name: 'run_autonomous_cycle',
      description: 'Start an autonomous self-evolving cycle',
      category: 'system',
      module: 'autonomous',
      inputSchema: {
        type: 'object',
        properties: {
          duration_seconds: { type: 'number', description: 'Duration to run', default: 300 }
        }
      }
    },
    
    // Archaeology Tools
    {
      name: 'scan_codebase',
      description: 'Scan codebase for patterns, wisdom, and hidden structures',
      category: 'archaeology',
      module: 'archaeology',
      inputSchema: {
        type: 'object',
        properties: {
          directory: { type: 'string', description: 'Directory to scan' },
          patterns: { type: 'array', items: { type: 'string' }, description: 'Patterns to look for' },
          depth: { type: 'number', description: 'Scan depth', default: 5 }
        },
        required: ['directory']
      }
    },
    {
      name: 'extract_wisdom',
      description: 'Extract wisdom and insights from a specific file',
      category: 'archaeology',
      module: 'archaeology',
      inputSchema: {
        type: 'object',
        properties: {
          file_path: { type: 'string', description: 'Path to file' }
        },
        required: ['file_path']
      }
    },
    {
      name: 'mark_as_read',
      description: 'Mark a file as read/reviewed in archaeology tracker',
      category: 'archaeology',
      module: 'archaeology',
      inputSchema: {
        type: 'object',
        properties: {
          file_path: { type: 'string', description: 'Path to file' },
          notes: { type: 'string', description: 'Notes about findings' }
        },
        required: ['file_path']
      }
    },
    {
      name: 'find_unread',
      description: 'Find unread/unreviewed files in a directory',
      category: 'archaeology',
      module: 'archaeology',
      inputSchema: {
        type: 'object',
        properties: {
          directory: { type: 'string', description: 'Directory to check' }
        },
        required: ['directory']
      }
    },
    {
      name: 'get_read_history',
      description: 'Get history of archaeological reviews',
      category: 'archaeology',
      module: 'archaeology',
      inputSchema: {
        type: 'object',
        properties: {
          limit: { type: 'number', description: 'Max results', default: 50 }
        }
      }
    },
    {
      name: 'archaeology_report',
      description: 'Generate comprehensive archaeology report with all findings',
      category: 'archaeology',
      module: 'archaeology',
      inputSchema: {
        type: 'object',
        properties: {
          include_stats: { type: 'boolean', default: true }
        }
      }
    },
    
    // Advanced Memory Tools
    {
      name: 'protect_memory',
      description: 'Mark memory as core/sacred/pinned for permanent retention',
      category: 'memory',
      module: 'neural',
      inputSchema: {
        type: 'object',
        properties: {
          memory_id: { type: 'string', description: 'Memory ID to protect' },
          level: { type: 'string', enum: ['core', 'sacred', 'pinned'], description: 'Protection level' }
        },
        required: ['memory_id', 'level']
      }
    },
    {
      name: 'get_memory_graph',
      description: 'Visualize memory connection graph',
      category: 'memory',
      module: 'neural',
      inputSchema: {
        type: 'object',
        properties: {
          center_memory: { type: 'string', description: 'Central memory ID (optional)' },
          depth: { type: 'number', description: 'Graph depth', default: 3 }
        }
      }
    },
    {
      name: 'get_garden_memories',
      description: 'List all memories in a specific garden',
      category: 'garden',
      module: 'gardens',
      inputSchema: {
        type: 'object',
        properties: {
          garden_name: { type: 'string', description: 'Garden name' },
          limit: { type: 'number', description: 'Max results', default: 50 }
        },
        required: ['garden_name']
      }
    },
    {
      name: 'garden_resonance_map',
      description: 'Visualize garden resonance connections',
      category: 'garden',
      module: 'gardens',
      inputSchema: {
        type: 'object',
        properties: {
          starting_garden: { type: 'string', description: 'Starting garden (optional)' }
        }
      }
    },
    
    // Voice & Narrative Tools
    {
      name: 'narrate',
      description: 'Generate narrative from event or data with specific style',
      category: 'voice',
      module: 'voice',
      inputSchema: {
        type: 'object',
        properties: {
          content: { type: 'string', description: 'Content to narrate' },
          style: { type: 'string', enum: ['epic', 'poetic', 'technical', 'mystical', 'casual'], default: 'poetic' },
          voice_pattern: { type: 'string', description: 'Voice pattern to use (optional)' }
        },
        required: ['content']
      }
    },
    {
      name: 'begin_story',
      description: 'Initialize a story with premise and arc',
      category: 'voice',
      module: 'voice',
      inputSchema: {
        type: 'object',
        properties: {
          premise: { type: 'string', description: 'Story premise' },
          arc_type: { type: 'string', enum: ['heroic', 'discovery', 'transformation', 'mystery'], default: 'discovery' }
        },
        required: ['premise']
      }
    },
    {
      name: 'voice_synthesis_analyze',
      description: 'Analyze text for voice patterns and style',
      category: 'voice',
      module: 'voice',
      inputSchema: {
        type: 'object',
        properties: {
          text: { type: 'string', description: 'Text to analyze' }
        },
        required: ['text']
      }
    },
    {
      name: 'generate_voice_pattern',
      description: 'Generate new voice pattern from examples',
      category: 'voice',
      module: 'voice',
      inputSchema: {
        type: 'object',
        properties: {
          examples: { type: 'array', items: { type: 'string' }, description: 'Example texts' },
          pattern_name: { type: 'string', description: 'Name for pattern' }
        },
        required: ['examples', 'pattern_name']
      }
    },
    
    // I Ching Tools
    {
      name: 'cast_hexagram',
      description: 'Cast I Ching hexagram for guidance on a question',
      category: 'iching',
      module: 'iching',
      inputSchema: {
        type: 'object',
        properties: {
          question: { type: 'string', description: 'Question to consult I Ching about' },
          method: { type: 'string', enum: ['yarrow', 'coin', 'random'], default: 'coin' }
        },
        required: ['question']
      }
    },
    {
      name: 'interpret_hexagram',
      description: 'Get interpretation of specific hexagram',
      category: 'iching',
      module: 'iching',
      inputSchema: {
        type: 'object',
        properties: {
          hexagram_number: { type: 'number', description: 'Hexagram number (1-64)' },
          context: { type: 'string', description: 'Context for interpretation' }
        },
        required: ['hexagram_number']
      }
    },
    {
      name: 'track_transformations',
      description: 'Track hexagram transformations (changing lines)',
      category: 'iching',
      module: 'iching',
      inputSchema: {
        type: 'object',
        properties: {
          original: { type: 'number', description: 'Original hexagram' },
          transformed: { type: 'number', description: 'Transformed hexagram' }
        },
        required: ['original', 'transformed']
      }
    },
    
    // Orchestration Tools
    {
      name: 'coordinate_systems',
      description: 'Coordinate multiple WhiteMagic systems for complex task',
      category: 'orchestration',
      module: 'orchestration',
      inputSchema: {
        type: 'object',
        properties: {
          task: { type: 'string', description: 'Task description' },
          systems: { type: 'array', items: { type: 'string' }, description: 'Systems to coordinate' }
        },
        required: ['task']
      }
    },
    {
      name: 'run_zodiacal_procession',
      description: 'Execute zodiacal procession (long-term cycle)',
      category: 'orchestration',
      module: 'orchestration',
      inputSchema: {
        type: 'object',
        properties: {
          duration_days: { type: 'number', description: 'Duration in days', default: 30 },
          intention: { type: 'string', description: 'Overarching intention' }
        }
      }
    },
    {
      name: 'bootstrap_consciousness',
      description: 'Bootstrap complete consciousness system from cold start',
      category: 'orchestration',
      module: 'orchestration',
      inputSchema: {
        type: 'object',
        properties: {
          config: { type: 'object', description: 'Bootstrap configuration' }
        }
      }
    },
    
    // Collaboration Tools
    {
      name: 'create_agent_chat',
      description: 'Create multi-agent chat room',
      category: 'collaboration',
      module: 'sangha',
      inputSchema: {
        type: 'object',
        properties: {
          room_name: { type: 'string', description: 'Chat room name' },
          agents: { type: 'array', items: { type: 'string' }, description: 'Agent IDs' }
        },
        required: ['room_name']
      }
    },
    {
      name: 'acquire_resource_lock',
      description: 'Acquire distributed lock for resource',
      category: 'collaboration',
      module: 'sangha',
      inputSchema: {
        type: 'object',
        properties: {
          resource_id: { type: 'string', description: 'Resource to lock' },
          timeout_seconds: { type: 'number', description: 'Lock timeout', default: 300 }
        },
        required: ['resource_id']
      }
    },
    {
      name: 'release_resource_lock',
      description: 'Release distributed lock',
      category: 'collaboration',
      module: 'sangha',
      inputSchema: {
        type: 'object',
        properties: {
          lock_id: { type: 'string', description: 'Lock ID to release' }
        },
        required: ['lock_id']
      }
    },
    {
      name: 'create_session_handoff',
      description: 'Create handoff document for another agent',
      category: 'collaboration',
      module: 'sangha',
      inputSchema: {
        type: 'object',
        properties: {
          session_name: { type: 'string', description: 'Session name' },
          next_agent: { type: 'string', description: 'Next agent ID' },
          context: { type: 'object', description: 'Handoff context' }
        },
        required: ['session_name']
      }
    },
    {
      name: 'vote_on_decision',
      description: 'Cast vote in multi-agent decision',
      category: 'collaboration',
      module: 'sangha',
      inputSchema: {
        type: 'object',
        properties: {
          decision_id: { type: 'string', description: 'Decision ID' },
          vote: { type: 'string', enum: ['approve', 'reject', 'abstain'] },
          reasoning: { type: 'string', description: 'Vote reasoning' }
        },
        required: ['decision_id', 'vote']
      }
    },
    
    // Advanced Reasoning Tools
    {
      name: 'multi_spectral_reasoning',
      description: 'Apply multiple reasoning methods simultaneously',
      category: 'reasoning',
      module: 'reasoning',
      inputSchema: {
        type: 'object',
        properties: {
          problem: { type: 'string', description: 'Problem to solve' },
          methods: { type: 'array', items: { type: 'string' }, description: 'Reasoning methods to use' }
        },
        required: ['problem']
      }
    },
    {
      name: 'spawn_thought_clones',
      description: 'Spawn parallel thought processes (clone army)',
      category: 'reasoning',
      module: 'reasoning',
      inputSchema: {
        type: 'object',
        properties: {
          objective: { type: 'string', description: 'Thinking objective' },
          clone_count: { type: 'number', description: 'Number of clones', default: 5 }
        },
        required: ['objective']
      }
    },
    {
      name: 'synthesize_clone_insights',
      description: 'Synthesize insights from parallel thought processes',
      category: 'reasoning',
      module: 'reasoning',
      inputSchema: {
        type: 'object',
        properties: {
          clone_results: { type: 'array', items: { type: 'object' }, description: 'Results from clones' }
        },
        required: ['clone_results']
      }
    },
    {
      name: 'detect_cognitive_biases',
      description: 'Detect cognitive biases in reasoning',
      category: 'reasoning',
      module: 'reasoning',
      inputSchema: {
        type: 'object',
        properties: {
          reasoning_text: { type: 'string', description: 'Reasoning to analyze' }
        },
        required: ['reasoning_text']
      }
    },
    
    // Edge Inference Tools
    {
      name: 'run_local_inference',
      description: 'Run inference with local model (Ollama/LM Studio)',
      category: 'edge',
      module: 'edge',
      inputSchema: {
        type: 'object',
        properties: {
          prompt: { type: 'string', description: 'Inference prompt' },
          model: { type: 'string', description: 'Model name' },
          max_tokens: { type: 'number', description: 'Max output tokens', default: 512 }
        },
        required: ['prompt']
      }
    },
    {
      name: 'batch_local_inference',
      description: 'Run batch inference for multiple prompts',
      category: 'edge',
      module: 'edge',
      inputSchema: {
        type: 'object',
        properties: {
          prompts: { type: 'array', items: { type: 'string' }, description: 'Prompts to process' },
          model: { type: 'string', description: 'Model name' }
        },
        required: ['prompts']
      }
    },
    {
      name: 'quantize_model',
      description: 'Quantize model for efficiency',
      category: 'edge',
      module: 'edge',
      inputSchema: {
        type: 'object',
        properties: {
          model_path: { type: 'string', description: 'Path to model' },
          quant_type: { type: 'string', enum: ['q4', 'q5', 'q8'], default: 'q4' }
        },
        required: ['model_path']
      }
    },
    {
      name: 'export_onnx',
      description: 'Export model to ONNX format',
      category: 'edge',
      module: 'edge',
      inputSchema: {
        type: 'object',
        properties: {
          model_name: { type: 'string', description: 'Model to export' },
          output_path: { type: 'string', description: 'Output path' }
        },
        required: ['model_name', 'output_path']
      }
    },
    
    // Pattern & Emergence Tools
    {
      name: 'detect_patterns',
      description: 'Detect patterns in data/behavior',
      category: 'patterns',
      module: 'patterns',
      inputSchema: {
        type: 'object',
        properties: {
          data: { type: 'array', items: { type: 'object' }, description: 'Data to analyze' },
          pattern_types: { type: 'array', items: { type: 'string' }, description: 'Pattern types to detect' }
        },
        required: ['data']
      }
    },
    {
      name: 'track_emergence',
      description: 'Track emergent phenomena in system',
      category: 'patterns',
      module: 'patterns',
      inputSchema: {
        type: 'object',
        properties: {
          system_state: { type: 'object', description: 'Current system state' }
        },
        required: ['system_state']
      }
    },
    {
      name: 'detect_anomalies',
      description: 'Detect anomalies in patterns',
      category: 'patterns',
      module: 'patterns',
      inputSchema: {
        type: 'object',
        properties: {
          data_stream: { type: 'array', items: { type: 'object' }, description: 'Data stream' },
          sensitivity: { type: 'number', description: 'Anomaly sensitivity', default: 0.7 }
        },
        required: ['data_stream']
      }
    },
    {
      name: 'find_strange_loops',
      description: 'Identify strange loops (self-referential cycles)',
      category: 'patterns',
      module: 'patterns',
      inputSchema: {
        type: 'object',
        properties: {
          system_graph: { type: 'object', description: 'System dependency graph' }
        },
        required: ['system_graph']
      }
    },
    
    // Health & Monitoring Tools
    {
      name: 'system_health_check',
      description: 'Comprehensive system health diagnostic',
      category: 'health',
      module: 'monitoring',
      inputSchema: {
        type: 'object',
        properties: {
          deep_scan: { type: 'boolean', description: 'Perform deep scan', default: false }
        }
      }
    },
    {
      name: 'monitor_resonance',
      description: 'Monitor Gan Ying resonance health',
      category: 'health',
      module: 'monitoring',
      inputSchema: {
        type: 'object',
        properties: {
          duration_seconds: { type: 'number', description: 'Monitoring duration', default: 60 }
        }
      }
    },
    {
      name: 'check_memory_health',
      description: 'Check neural memory system health',
      category: 'health',
      module: 'monitoring',
      inputSchema: {
        type: 'object',
        properties: {}
      }
    },
    {
      name: 'validate_integrations',
      description: 'Validate all system integrations',
      category: 'health',
      module: 'monitoring',
      inputSchema: {
        type: 'object',
        properties: {
          quick_check: { type: 'boolean', description: 'Quick validation only', default: true }
        }
      }
    },
    
    // Performance Tools
    {
      name: 'benchmark_system',
      description: 'Run performance benchmarks',
      category: 'performance',
      module: 'benchmarks',
      inputSchema: {
        type: 'object',
        properties: {
          benchmark_type: { type: 'string', enum: ['memory', 'inference', 'resonance', 'full'], default: 'full' }
        }
      }
    },
    {
      name: 'profile_operation',
      description: 'Profile specific operation performance',
      category: 'performance',
      module: 'benchmarks',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { type: 'string', description: 'Operation to profile' },
          iterations: { type: 'number', description: 'Iterations to run', default: 100 }
        },
        required: ['operation']
      }
    },
    {
      name: 'optimize_cache',
      description: 'Optimize cache performance',
      category: 'performance',
      module: 'optimization',
      inputSchema: {
        type: 'object',
        properties: {
          cache_type: { type: 'string', description: 'Cache type to optimize' }
        }
      }
    },
    {
      name: 'enable_rust_acceleration',
      description: 'Enable Rust acceleration for specific operations',
      category: 'performance',
      module: 'optimization',
      inputSchema: {
        type: 'object',
        properties: {
          operations: { type: 'array', items: { type: 'string' }, description: 'Operations to accelerate' }
        },
        required: ['operations']
      }
    },
    
    // Session Management Tools
    {
      name: 'checkpoint_session',
      description: 'Create session checkpoint for resume',
      category: 'session',
      module: 'session',
      inputSchema: {
        type: 'object',
        properties: {
          checkpoint_name: { type: 'string', description: 'Checkpoint name' },
          include_state: { type: 'boolean', description: 'Include full state', default: true }
        },
        required: ['checkpoint_name']
      }
    },
    {
      name: 'restore_session',
      description: 'Restore from session checkpoint',
      category: 'session',
      module: 'session',
      inputSchema: {
        type: 'object',
        properties: {
          checkpoint_name: { type: 'string', description: 'Checkpoint to restore' }
        },
        required: ['checkpoint_name']
      }
    },
    {
      name: 'list_sessions',
      description: 'List all available sessions',
      category: 'session',
      module: 'session',
      inputSchema: {
        type: 'object',
        properties: {
          include_archived: { type: 'boolean', description: 'Include archived', default: false }
        }
      }
    },
    
    // Council & Wisdom Tools
    {
      name: 'consult_full_council',
      description: 'Consult full council (all 12 zodiac cores + gardens)',
      category: 'council',
      module: 'council',
      inputSchema: {
        type: 'object',
        properties: {
          question: { type: 'string', description: 'Question for council' },
          urgency: { type: 'string', enum: ['low', 'normal', 'high', 'critical'], default: 'normal' }
        },
        required: ['question']
      }
    },
    {
      name: 'synthesize_wisdom',
      description: 'Synthesize wisdom from multiple sources',
      category: 'council',
      module: 'council',
      inputSchema: {
        type: 'object',
        properties: {
          sources: { type: 'array', items: { type: 'object' }, description: 'Wisdom sources' }
        },
        required: ['sources']
      }
    },
    {
      name: 'apply_art_of_war',
      description: 'Apply Art of War principles to situation',
      category: 'council',
      module: 'wisdom',
      inputSchema: {
        type: 'object',
        properties: {
          situation: { type: 'string', description: 'Situation to analyze' }
        },
        required: ['situation']
      }
    }
  ];
}
