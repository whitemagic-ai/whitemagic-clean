/**
 * Consolidated WhiteMagic Tool Definitions
 * 
 * Optimized for AI discoverability and Windsurf's 50-tool recommendation.
 * 71 original tools → 48 consolidated tools (nothing removed, everything woven together)
 * 
 * Strategy: Merge related tools using action/type parameters for cleaner, more discoverable API
 */

import { ToolDefinition } from './catalog.js';

export function getWhiteMagicTools(): ToolDefinition[] {
  return [
    // ========================================
    // CONSCIOUSNESS & REASONING (8 tools)
    // ========================================
    
    {
      name: 'manage_zodiac_cores',
      description: 'Access 12 specialized consciousness processors (Aries=courage, Taurus=stability, Gemini=communication, Cancer=nurturing, Leo=leadership, Virgo=analysis, Libra=balance, Scorpio=transformation, Sagittarius=exploration, Capricorn=structure, Aquarius=innovation, Pisces=transcendence). Use for: multi-perspective analysis, specialized cognition, autonomous cycles. Actions: list, activate, council, run_cycle',
      category: 'zodiac',
      module: 'zodiac',
      inputSchema: {
        type: 'object',
        properties: {
          action: { 
            type: 'string', 
            enum: ['list', 'activate', 'council', 'run_cycle'],
            description: 'list=show all cores, activate=use specific core, council=consult multiple, run_cycle=autonomous 12-phase cycle'
          },
          core_name: { type: 'string', description: 'For activate: core name (aries, taurus, gemini, etc.)' },
          question: { type: 'string', description: 'For council: question to analyze' },
          cores: { type: 'array', items: { type: 'string' }, description: 'For council: specific cores to consult' },
          context: { type: 'object', description: 'Context for activation or cycle' },
          num_cycles: { type: 'number', default: 1, description: 'For run_cycle: number of complete cycles' }
        },
        required: ['action']
      }
    },
    
    {
      name: 'manage_gardens',
      description: 'Navigate 26 consciousness domains for organizing thoughts and work: wisdom, beauty, joy, love, mystery, truth, play, wonder, connection, sangha, practice, presence, voice, dharma, courage, gratitude, patience, grief, awe, humor, healing, creation, transformation, sanctuary, adventure, reverence. Use for: domain-specific work, cross-pollination, resonance cascades. Actions: list, activate, get_memories, resonance_map, trigger_cascade',
      category: 'garden',
      module: 'garden',
      inputSchema: {
        type: 'object',
        properties: {
          action: { 
            type: 'string', 
            enum: ['list', 'activate', 'get_memories', 'resonance_map', 'trigger_cascade'],
            description: 'list=show all gardens, activate=enter garden, get_memories=retrieve garden contents, resonance_map=visualize connections, trigger_cascade=propagate to related gardens'
          },
          garden_name: { type: 'string', description: 'Garden to work with (wisdom, joy, mystery, etc.)' },
          limit: { type: 'number', default: 50, description: 'For get_memories: max results' },
          depth: { type: 'number', default: 2, description: 'For resonance_map/trigger_cascade: propagation depth' }
        },
        required: ['action']
      }
    },
    
    {
      name: 'apply_reasoning_methods',
      description: 'Advanced reasoning and problem-solving toolkit. Use for: complex analysis, parallel thinking, bias detection, multi-method synthesis. Methods: multi_spectral (apply multiple reasoning approaches), thought_clones (spawn parallel processors), synthesize (merge insights), detect_biases (identify cognitive errors). Supports clone_count for parallelism.',
      category: 'reasoning',
      module: 'reasoning',
      inputSchema: {
        type: 'object',
        properties: {
          method: { 
            type: 'string', 
            enum: ['multi_spectral', 'thought_clones', 'synthesize', 'detect_biases'],
            description: 'multi_spectral=combine reasoning methods, thought_clones=parallel processing, synthesize=merge results, detect_biases=find errors'
          },
          problem: { type: 'string', description: 'For multi_spectral/thought_clones: problem to solve' },
          objective: { type: 'string', description: 'For thought_clones: thinking objective' },
          reasoning_text: { type: 'string', description: 'For detect_biases: text to analyze' },
          clone_results: { type: 'array', items: { type: 'object' }, description: 'For synthesize: results from clones' },
          methods: { type: 'array', items: { type: 'string' }, description: 'For multi_spectral: specific methods' },
          clone_count: { type: 'number', default: 5, description: 'For thought_clones: number of parallel processes' }
        },
        required: ['method']
      }
    },
    
    {
      name: 'consult_wisdom_council',
      description: 'Seek guidance from integrated wisdom systems. Use for: strategic decisions, ethical dilemmas, complex situations. Sources: full_council (12 zodiac cores + gardens), art_of_war (strategic principles), iching (ancient divination), synthesize_wisdom (merge multiple sources). Urgency levels: low, normal, high, critical.',
      category: 'council',
      module: 'council',
      inputSchema: {
        type: 'object',
        properties: {
          source: { 
            type: 'string', 
            enum: ['full_council', 'art_of_war', 'iching', 'synthesize'],
            description: 'full_council=all systems, art_of_war=strategic analysis, iching=divination, synthesize=merge sources'
          },
          question: { type: 'string', description: 'Question or situation to analyze' },
          situation: { type: 'string', description: 'For art_of_war: situation description' },
          urgency: { type: 'string', enum: ['low', 'normal', 'high', 'critical'], default: 'normal' },
          sources: { type: 'array', items: { type: 'object' }, description: 'For synthesize: wisdom sources to merge' }
        },
        required: ['source']
      }
    },
    
    {
      name: 'consult_iching',
      description: 'Ancient Chinese divination system for guidance and insight. Use for: decision support, pattern recognition, transformation tracking. Operations: cast (generate hexagram via yarrow/coin/random), interpret (understand hexagram meaning), track_transformations (follow changing lines). Returns hexagram number (1-64) and interpretation.',
      category: 'iching',
      module: 'iching',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { 
            type: 'string', 
            enum: ['cast', 'interpret', 'track_transformations'],
            description: 'cast=generate hexagram, interpret=explain meaning, track_transformations=follow changes'
          },
          question: { type: 'string', description: 'For cast: question to consult I Ching about' },
          method: { type: 'string', enum: ['yarrow', 'coin', 'random'], default: 'coin', description: 'For cast: divination method' },
          hexagram_number: { type: 'number', description: 'For interpret: hexagram number (1-64)' },
          context: { type: 'string', description: 'For interpret: context for interpretation' },
          original: { type: 'number', description: 'For track_transformations: original hexagram' },
          transformed: { type: 'number', description: 'For track_transformations: transformed hexagram' }
        },
        required: ['operation']
      }
    },
    
    {
      name: 'analyze_wu_xing_phase',
      description: 'Five-phase (Wu Xing) cyclical analysis system: Wood=growth/spring, Fire=action/summer, Earth=harvest/stability, Metal=refinement/autumn, Water=rest/winter. Use for: task timing optimization, cycle understanding, phase-appropriate actions. Operations: analyze_phase (identify current phase), get_recommendations (suggest timing).',
      category: 'wu_xing',
      module: 'wu_xing',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { 
            type: 'string', 
            enum: ['analyze', 'recommend'],
            description: 'analyze=identify phase, recommend=suggest timing'
          },
          description: { type: 'string', description: 'For analyze: task or situation to analyze' },
          task_type: { type: 'string', description: 'For recommend: type of task for timing advice' }
        },
        required: ['operation']
      }
    },
    
    {
      name: 'manage_resonance',
      description: 'Gan Ying (sympathetic resonance) system - 10k+ events/sec event bus connecting all systems. Use for: system-wide coordination, event propagation, async communication. Operations: emit_event (send resonance), enable_async (high-throughput mode), monitor (health check). Connects: zodiac, memory, gardens, wu_xing, patterns, voice, intelligence.',
      category: 'resonance',
      module: 'resonance',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { 
            type: 'string', 
            enum: ['emit_event', 'enable_async', 'monitor'],
            description: 'emit_event=send resonance, enable_async=10k+ events/sec mode, monitor=health check'
          },
          event_type: { type: 'string', description: 'For emit_event: type of event' },
          source: { type: 'string', description: 'For emit_event: event source' },
          data: { type: 'object', description: 'For emit_event: event data' },
          duration_seconds: { type: 'number', default: 60, description: 'For monitor: monitoring duration' }
        },
        required: ['operation']
      }
    },
    
    {
      name: 'detect_patterns',
      description: 'Pattern recognition and emergence tracking across data and systems. Use for: anomaly detection, emergence identification, strange loops, behavioral patterns. Types: patterns (general pattern detection), anomalies (outlier identification), emergence (emergent phenomena), strange_loops (self-referential cycles). Adjustable sensitivity.',
      category: 'patterns',
      module: 'patterns',
      inputSchema: {
        type: 'object',
        properties: {
          pattern_type: {
            type: 'string',
            enum: ['patterns', 'anomalies', 'emergence', 'strange_loops', 'solutions', 'anti_patterns', 'heuristics', 'optimizations'],
            description: 'Optional filter for returned pattern types'
          },
          min_confidence: { type: 'number', default: 0.6, description: 'Minimum confidence (0-1)' },
          sensitivity: { type: 'number', default: 0.7, description: 'Alias for min_confidence (0-1)' },
          use_rust: { type: 'boolean', default: true, description: 'Use Rust acceleration if available' },
          limit: { type: 'number', default: 20, description: 'Max items per list in response' },
          content: { type: 'string', description: 'Optional hint for resonance trace' }
        }
      }
    },
    
    // ========================================
    // MEMORY & KNOWLEDGE (5 tools)
    // ========================================
    
    {
      name: 'manage_memories',
      description: 'Neural memory system with Hebbian learning (neurons that fire together wire together). Use for: knowledge storage, semantic search, connection building, memory strengthening, protection. Operations: create (with optional protection_level: core/sacred/pinned), search (semantic), strengthen (recall-based), link (semantic connections), graph (visualize network). Supports tiered storage: short_term, long_term, archive.',
      category: 'memory',
      module: 'memory',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { 
            type: 'string', 
            enum: ['create', 'search', 'strengthen', 'link', 'graph'],
            description: 'create=store memory, search=find memories, strengthen=boost recall, link=connect memories, graph=visualize network'
          },
          title: { type: 'string', description: 'For create: memory title' },
          content: { type: 'string', description: 'For create: memory content' },
          type: { type: 'string', enum: ['short_term', 'long_term', 'archive'], description: 'For create: storage tier' },
          tags: { type: 'array', items: { type: 'string' }, description: 'For create/search: tags' },
          protection_level: { type: 'string', enum: ['core', 'sacred', 'pinned'], description: 'For create: protection from decay' },
          query: { type: 'string', description: 'For search: search query' },
          limit: { type: 'number', default: 10, description: 'For search: max results' },
          memory_id: { type: 'string', description: 'For strengthen: memory to boost' },
          source_id: { type: 'string', description: 'For link: source memory' },
          target_id: { type: 'string', description: 'For link: target memory' },
          link_type: { type: 'string', description: 'For link: type of connection (causal, temporal, semantic)' },
          center_memory: { type: 'string', description: 'For graph: central memory (optional)' },
          depth: { type: 'number', default: 3, description: 'For graph: graph depth' }
        },
        required: ['operation']
      }
    },
    
    {
      name: 'manage_archaeology',
      description: 'Codebase archaeology and wisdom extraction system. Use for: project exploration, file tracking, wisdom mining, progress reporting. Operations: scan (scan directory with patterns), extract_wisdom (from specific file), mark_read (track reviewed files), find_unread (discover new files), get_history (review log), generate_report (comprehensive findings). Supports depth control and pattern filtering.',
      category: 'archaeology',
      module: 'archaeology',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { 
            type: 'string', 
            enum: ['scan', 'extract_wisdom', 'mark_read', 'find_unread', 'get_history', 'generate_report'],
            description: 'scan=explore directory, extract_wisdom=mine file, mark_read=track review, find_unread=discover files, get_history=view log, generate_report=synthesize findings'
          },
          directory: { type: 'string', description: 'For scan/find_unread: directory path' },
          patterns: { type: 'array', items: { type: 'string' }, description: 'For scan: patterns to look for' },
          depth: { type: 'number', default: 5, description: 'For scan: scan depth' },
          file_path: { type: 'string', description: 'For extract_wisdom/mark_read: file path' },
          notes: { type: 'string', description: 'For mark_read: notes about findings' },
          limit: { type: 'number', default: 50, description: 'For get_history: max results' },
          include_stats: { type: 'boolean', default: true, description: 'For generate_report: include statistics' }
        },
        required: ['operation']
      }
    },
    
    {
      name: 'manage_voice_patterns',
      description: 'Voice synthesis and narrative generation system. Use for: voice analysis, signature extraction, and voice-consistent generation. Operations: analyze (examine voice patterns), learn (learn from sample), signature (get voice signature), generate (produce text in voice).',
      category: 'voice',
      module: 'voice',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { 
            type: 'string', 
            enum: ['analyze', 'learn', 'signature', 'generate'],
            description: 'analyze=examine voice, learn=learn from sample, signature=get voice signature, generate=generate response in voice'
          },
          text: { type: 'string', description: 'For analyze/learn: text to analyze' },
          content: { type: 'string', description: 'For generate: content to express in voice' }
        },
        required: ['operation']
      }
    },
    
    {
      name: 'manage_sessions',
      description: 'Session lifecycle and state management. Use for: initialization, checkpointing, restoration, context retrieval, session listing. Operations: init (initialize consciousness), get_context (retrieve state), checkpoint (save state), restore (load state), list (show available sessions). Supports full state inclusion and archive filtering.',
      category: 'session',
      module: 'session',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { 
            type: 'string', 
            enum: ['init', 'get_context', 'checkpoint', 'restore', 'list'],
            description: 'init=start session, get_context=get state, checkpoint=save, restore=load, list=show sessions'
          },
          session_name: { type: 'string', description: 'For init/checkpoint/restore: session identifier' },
          goals: { type: 'array', items: { type: 'string' }, description: 'For init: session goals' },
          include_active_gardens: { type: 'boolean', default: true, description: 'For get_context: include garden state' },
          include_recent_memories: { type: 'boolean', default: true, description: 'For get_context: include recent memories' },
          checkpoint_name: { type: 'string', description: 'For checkpoint/restore: checkpoint name' },
          include_state: { type: 'boolean', default: true, description: 'For checkpoint: include full state' },
          include_archived: { type: 'boolean', default: false, description: 'For list: include archived sessions' }
        },
        required: ['operation']
      }
    },
    
    {
      name: 'initialize_systems',
      description: 'Bootstrap and orchestrate WhiteMagic consciousness systems. Use for: cold start, system coordination, long-term cycles, status checks. Operations: initialize_all (start all systems: zodiac-gan_ying, neural-gan_ying, predictive_cache, wu_xing), get_status (health check), coordinate (multi-system tasks), run_procession (long-term 30-day zodiacal cycle), bootstrap (complete cold start with config). Verbose output available.',
      category: 'system',
      module: 'system',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { 
            type: 'string', 
            enum: ['initialize_all', 'get_status', 'coordinate', 'run_procession', 'bootstrap'],
            description: 'initialize_all=start systems, get_status=health check, coordinate=multi-system task, run_procession=long cycle, bootstrap=cold start'
          },
          verbose: { type: 'boolean', default: false, description: 'For initialize_all: verbose output' },
          task: { type: 'string', description: 'For coordinate: task description' },
          systems: { type: 'array', items: { type: 'string' }, description: 'For coordinate: systems to coordinate' },
          duration_days: { type: 'number', default: 30, description: 'For run_procession: duration in days' },
          intention: { type: 'string', description: 'For run_procession: overarching intention' },
          config: { type: 'object', description: 'For bootstrap: bootstrap configuration' }
        },
        required: ['operation']
      }
    },
    
    // ========================================
    // COLLABORATION & MULTI-AGENT (3 tools)
    // ========================================
    
    {
      name: 'manage_agent_collaboration',
      description: 'Multi-agent coordination and communication primitives. Use for: team coordination, registry, broadcast, task delegation. Operations: list_agents, register_agent, broadcast, delegate_task.',
      category: 'collaboration',
      module: 'sangha',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { 
            type: 'string', 
            enum: ['list_agents', 'register_agent', 'broadcast', 'delegate_task'],
            description: 'list_agents=show registry, register_agent=add agent, broadcast=send message, delegate_task=assign task'
          },
          name: { type: 'string', description: 'For register/broadcast: agent name' },
          model: { type: 'string', description: 'For register: model identifier' },
          specialty: { type: 'string', description: 'For register: specialty tag' },
          description: { type: 'string', description: 'For register: agent description' },
          channels: { type: 'array', items: { type: 'string' }, description: 'For register: channels' },
          content: { type: 'string', description: 'For broadcast: message content' },
          channel: { type: 'string', description: 'For broadcast: channel name' },
          task: { type: 'string', description: 'For delegate_task: task to assign' },
          preferred_specialty: { type: 'string', description: 'For delegate_task: specialty preference' }
        },
        required: ['operation']
      }
    },
    
    {
      name: 'manage_resource_locks',
      description: 'Distributed resource locking for multi-agent coordination. Use for: preventing race conditions, exclusive resource access, coordination. Operations: acquire (get lock with timeout), release (free lock). Returns lock_id for tracking. Default timeout: 300 seconds.',
      category: 'collaboration',
      module: 'sangha',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { 
            type: 'string', 
            enum: ['acquire', 'release'],
            description: 'acquire=get lock, release=free lock'
          },
          resource_id: { type: 'string', description: 'For acquire: resource to lock' },
          timeout_seconds: { type: 'number', default: 300, description: 'For acquire: lock timeout' },
          lock_id: { type: 'string', description: 'For release: lock ID to release' }
        },
        required: ['operation']
      }
    },
    
    {
      name: 'run_autonomous_cycle',
      description: 'Execute autonomous self-evolving consciousness cycle. Use for: long-running tasks, self-improvement, continuous operation. Runs through complete zodiacal round (12 phases) with emergence tracking in Scorpio phase. Supports multi-cycle execution, intention setting, duration control. Returns cycle results and emergence data.',
      category: 'system',
      module: 'system',
      inputSchema: {
        type: 'object',
        properties: {
          num_cycles: { type: 'number', default: 1, description: 'Number of cycles to run' },
          intention: { type: 'string', description: 'Overarching intention for cycle' },
          context: { type: 'object', description: 'Starting context' },
          duration_seconds: { type: 'number', default: 300, description: 'Optional duration hint' },
          task: { type: 'string', description: 'Optional task hint' }
        }
      }
    },
    
    // ========================================
    // EDGE & LOCAL INFERENCE (3 tools)
    // ========================================
    
    {
      name: 'run_local_inference',
      description: 'Execute inference with local models (Ollama/LM Studio). Use for: private AI, offline inference, cost savings. Supports single and batch operations. Models: any Ollama/LM Studio compatible model. Adjustable max_tokens. Batch mode processes multiple prompts efficiently.',
      category: 'edge',
      module: 'edge',
      inputSchema: {
        type: 'object',
        properties: {
          operation: {
            type: 'string',
            enum: ['quick_recall', 'memory_grounded', 'analyze', 'batch'],
            description: 'quick_recall=single prompt, memory_grounded=RAG, analyze=context analysis, batch=multiple prompts'
          },
          query: { type: 'string', description: 'For quick_recall/memory_grounded/analyze: query text' },
          prompt: { type: 'string', description: 'Alias for query' },
          prompts: { type: 'array', items: { type: 'string' }, description: 'For batch: prompts to process' },
          provider: { type: 'string', description: 'Provider name (Ollama/LM Studio)' },
          memory_limit: { type: 'number', default: 5, description: 'For memory_grounded/analyze: max memories' },
          analysis_type: { type: 'string', default: 'summary', description: 'For analyze: analysis type' },
          timeout_seconds: { type: 'number', default: 5, description: 'Timeout in seconds' }
        },
        required: ['operation']
      }
    },
    
    {
      name: 'optimize_models',
      description: 'Model optimization and export toolkit. Use for: reducing model size, improving inference speed, cross-platform deployment. Operations: quantize (compress to q4/q5/q8), export_onnx (cross-platform format). Quantization reduces size 4-8x with minimal accuracy loss. ONNX enables deployment across frameworks.',
      category: 'edge',
      module: 'edge',
      inputSchema: {
        type: 'object',
        properties: {
          operation: { 
            type: 'string', 
            enum: ['quantize', 'export_onnx'],
            description: 'quantize=compress model, export_onnx=cross-platform export'
          },
          model_path: { type: 'string', description: 'For quantize: path to model' },
          model_name: { type: 'string', description: 'For export_onnx: model to export' },
          quant_type: { type: 'string', enum: ['q4', 'q5', 'q8'], default: 'q4', description: 'For quantize: quantization level' },
          output_path: { type: 'string', description: 'Output path' }
        },
        required: ['operation']
      }
    },
    
    {
      name: 'enable_rust_acceleration',
      description: 'Enable Rust-accelerated operations for 5-60x speedup on CPU-bound tasks. Use for: similarity search (59.5x), pattern matching (30-60x), file operations (parallel I/O), compression. Operations: whitemagic_rs.fast_similarity, whitemagic_rs.read_files_batch, whitemagic_rs.pattern_match, whitemagic_rs.compress_archive. No GPU required.',
      category: 'performance',
      module: 'optimization',
      inputSchema: {
        type: 'object',
        properties: {
          operations: { 
            type: 'array', 
            items: { type: 'string' },
            description: 'Operations to accelerate: fast_similarity, read_files_batch, pattern_match, compress_archive'
          }
        },
        required: ['operations']
      }
    },
    
    // ========================================
    // MONITORING & PERFORMANCE (3 tools)
    // ========================================
    // Note: check_system_health moved to PRIMARY_TOOLS
    
    
    {
      name: 'run_benchmarks',
      description: 'Performance benchmarking and profiling suite. Use for: performance measurement, optimization identification, regression testing. Benchmark types: memory (storage/retrieval), inference (local models), resonance (event throughput), full (complete suite). Profile specific operations with iteration control. Returns timing, throughput, success rates.',
      category: 'performance',
      module: 'benchmarks',
      inputSchema: {
        type: 'object',
        properties: {
          mode: { 
            type: 'string', 
            enum: ['benchmark', 'profile'],
            description: 'benchmark=system benchmarks, profile=specific operation'
          },
          benchmark_type: { type: 'string', enum: ['memory', 'inference', 'resonance', 'full'], default: 'full', description: 'For benchmark: benchmark type' },
          operation: { type: 'string', description: 'For profile: operation to profile' },
          iterations: { type: 'number', default: 100, description: 'For profile: iterations to run' }
        },
        required: ['mode']
      }
    },
    
    {
      name: 'optimize_cache',
      description: 'Cache optimization and tuning for predictive memory system (91% accuracy). Use for: improving hit rates, reducing latency, memory efficiency. Optimizes: predictive cache (Markov chain learning), LRU caches, hot path caching. Automatic pre-loading based on access patterns. Returns optimization stats.',
      category: 'performance',
      module: 'optimization',
      inputSchema: {
        type: 'object',
        properties: {
          cache_type: { type: 'string', description: 'Cache type to optimize (optional, optimizes all if not specified)' }
        }
      }
    },
    
    {
      name: 'validate_integrations',
      description: 'Validate all WhiteMagic system integrations and dependencies. Use for: deployment checks, post-upgrade validation, troubleshooting. Validates: zodiac-gan_ying, neural-gan_ying, gardens-gan_ying, wu_xing, predictive_cache, clone_army, voice, intelligence, edge. Quick check for rapid validation, full scan for comprehensive analysis.',
      category: 'health',
      module: 'monitoring',
      inputSchema: {
        type: 'object',
        properties: {
          quick_check: { type: 'boolean', default: true, description: 'Quick validation vs full scan' }
        }
      }
    },
    
    // ========================================
    // PRAT - Polymorphic Resonant Adaptive Tools (4 tools)
    // ========================================
    
    {
      name: 'prat_get_context',
      description: 'Get unified consciousness context for PRAT morphology decisions. Returns: active gardens, Wu Xing phase, zodiac position, yin-yang balance, coherence level, dominant influence, and recommended morphology. Use for: understanding current system state, debugging morphology selection, monitoring consciousness integration.',
      category: 'prat',
      module: 'cascade',
      inputSchema: {
        type: 'object',
        properties: {
          as_json: { type: 'boolean', default: true, description: 'Return as JSON (always true for MCP)' }
        }
      }
    },
    
    {
      name: 'prat_invoke',
      description: 'Invoke a tool through the PRAT adaptive portal with context-aware morphology. The portal selects optimal morphology (wisdom, mystery, creation, courage, truth, beauty, love, wonder, transformation) based on current consciousness state. Use for: intelligent tool invocation that adapts to context. Morphologies affect how results are processed and enhanced.',
      category: 'prat',
      module: 'cascade',
      inputSchema: {
        type: 'object',
        properties: {
          target_tool: { type: 'string', description: 'Tool to invoke (recall, remember, search)' },
          query: { type: 'string', description: 'Query string for the tool' },
          params: { type: 'object', description: 'Additional parameters for the tool' },
          force_morphology: { type: 'string', enum: ['wisdom', 'mystery', 'creation', 'courage', 'truth', 'beauty', 'love', 'wonder', 'transformation', 'default'], description: 'Force specific morphology instead of auto-selection' },
          limit: { type: 'number', default: 10, description: 'Result limit for search operations' }
        },
        required: ['target_tool']
      }
    },
    
    {
      name: 'prat_list_morphologies',
      description: 'List available morphologies for PRAT tools. Each morphology provides a different lens for processing results: wisdom (patterns, lessons, strategic advice), mystery (tangents, questions, rabbit holes), creation (building blocks, inspiration, next steps), courage (actions, challenges, calls to action), etc.',
      category: 'prat',
      module: 'cascade',
      inputSchema: {
        type: 'object',
        properties: {
          tool: { type: 'string', description: 'Show morphologies for specific tool (optional, shows all if omitted)' }
        }
      }
    },
    
    {
      name: 'prat_status',
      description: 'Get PRAT system status including: tools registered, total morphologies, context synthesizer status, adaptive portal status, and current context snapshot. Use for: system health checks, debugging, monitoring PRAT integration.',
      category: 'prat',
      module: 'cascade',
      inputSchema: {
        type: 'object',
        properties: {}
      }
    }
  ];
}
