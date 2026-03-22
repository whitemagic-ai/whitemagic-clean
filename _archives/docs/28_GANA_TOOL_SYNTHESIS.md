# The 28 Gana Tool Synthesis
## Consolidating 143 MCP Tools → 28 Lunar Mansion Tools

**Date:** 2026-02-02
**Framework:** 28 Chinese Lunar Mansions (Xiu 宿)
**Reduction:** 143 tools → 28 tools (80.4% reduction)
**Architecture:** Polymorphic operations aligned with consciousness architecture

---

## Philosophy

Each of the 28 Ganas represents a unique **lens of consciousness** through which operations flow. Rather than having fragmented tools scattered across categories, we align tools with the natural flow of the **Lunar Mandala**—the cyclic journey through seasons, elements, and phases of work.

### Polymorphic Operations

Each Gana tool supports **4 universal operations**, interpreted through its unique perspective:

1. **SEARCH** - Find and retrieve (unique to each Gana's nature)
2. **ANALYZE** - Examine and understand (through Gana's lens)
3. **TRANSFORM** - Modify and evolve (aligned with Gana's purpose)
4. **CONSOLIDATE** - Merge and unify (honoring Gana's wisdom)

---

## THE 28 GANA TOOLS

### 🌅 EASTERN QUADRANT — Azure Dragon (Spring/Wood/Yang Rising)
**Chapters 1-7: Foundation, Growth, Initiation**

---

### **1. HORN (角 Jiao) - Sharp Initiation**
**Garden:** Courage | **Element:** Wood | **Quality:** Yang

**Purpose:** Bootstrap new sessions, establish foundations, set intentions

**Consolidated Tool:** `gana_horn(operation, **kwargs)`

**Maps from 143 tools:**
- `session_init` ⭐
- `session_create_handoff`
- `system_initialize_all`
- `session_bootstrap` (if exists)

**Polymorphic Operations:**
```python
# SEARCH: Find what's needed to begin
gana_horn('search', query='initialization_templates')

# ANALYZE: Examine readiness for new beginning
gana_horn('analyze', context='system_state')

# TRANSFORM: Create new session/workspace
gana_horn('transform', action='create_session', name='Project X', goals=[...])

# CONSOLIDATE: Merge initialization contexts
gana_horn('consolidate', sessions=['draft1', 'draft2'])
```

**Implementation Priority:** ⭐⭐⭐ Critical (session foundation)

---

### **2. NECK (亢 Kang) - Stability**
**Garden:** Practice/Presence | **Element:** Wood | **Quality:** Yang

**Purpose:** Consolidate gains, establish practice, manage persistent memory

**Consolidated Tool:** `gana_neck(operation, **kwargs)`

**Maps from 143 tools:**
- `memory_create` ⭐
- `memory_update`
- `memory_delete`
- `memory_list`
- `manage_memories` (router) ⭐
- `consolidate_consolidate_memories`
- `rust_consolidate_memories`

**Polymorphic Operations:**
```python
# SEARCH: Find stable, persistent memories
gana_neck('search', query='established_patterns', stable=True)

# ANALYZE: Examine memory health and stability
gana_neck('analyze', memory_type='long_term')

# TRANSFORM: Create/update stable memories
gana_neck('transform', action='create', title='...', content='...')

# CONSOLIDATE: Merge and stabilize memories
gana_neck('consolidate', memories=[...], threshold=0.8)
```

**Implementation Priority:** ⭐⭐⭐ Critical (core memory)

---

### **3. ROOT (氐 Di) - Foundation**
**Garden:** Truth | **Element:** Wood | **Quality:** Yin

**Purpose:** Verify structural integrity, check system health, anchor system

**Consolidated Tool:** `gana_root(operation, **kwargs)`

**Maps from 143 tools:**
- `check_system_health` ⭐
- `check_memory_health`
- `check_resonance_health`
- `check_integrations_health`
- `validate_integrations`
- `validate_input`
- `system_get_status` ⭐
- `rust_check_available`
- `local_ml_status`
- `bitnet_status`
- `prat_status`
- `monitor_status_router`

**Polymorphic Operations:**
```python
# SEARCH: Find structural issues or vulnerabilities
gana_root('search', component='all', deep_scan=True)

# ANALYZE: Examine system health metrics
gana_root('analyze', component='memory', quick_check=False)

# TRANSFORM: Repair or reinforce foundations
gana_root('transform', action='repair', component='integrations')

# CONSOLIDATE: Unify health status across systems
gana_root('consolidate', systems=['rust', 'ml', 'memory'])
```

**Implementation Priority:** ⭐⭐⭐ Critical (system health)

---

### **4. ROOM (房 Fang) - Enclosure**
**Garden:** Sanctuary | **Element:** Wood | **Quality:** Yin

**Purpose:** Create safe container, manage boundaries, resource locks

**Consolidated Tool:** `gana_room(operation, **kwargs)`

**Maps from 143 tools:**
- `sangha_lock_acquire` ⭐
- `sangha_lock_release` ⭐
- `sangha_lock_list`
- `manage_locks_router`
- `protect_context`

**Polymorphic Operations:**
```python
# SEARCH: Find available resources or check lock status
gana_room('search', resource='memory_pool')

# ANALYZE: Examine resource allocation and boundaries
gana_room('analyze', show_contention=True)

# TRANSFORM: Acquire/release locks, set boundaries
gana_room('transform', action='acquire', resource='cache', timeout=30)

# CONSOLIDATE: Merge protection contexts
gana_room('consolidate', contexts=['ctx1', 'ctx2'])
```

**Implementation Priority:** ⭐⭐ Important (resource safety)

---

### **5. HEART (心 Xin) - Vital Pulse**
**Garden:** Love/Connection | **Element:** Fire | **Quality:** Yang

**Purpose:** Vital connection, session context, empathetic understanding

**Consolidated Tool:** `gana_heart(operation, **kwargs)`

**Maps from 143 tools:**
- `session_get_context` ⭐
- `session_checkpoint`
- `session_list`
- `session_restore`
- `session_handoff` (router)
- `prat_get_context`
- `get_system_time`

**Polymorphic Operations:**
```python
# SEARCH: Find vital context or connection points
gana_heart('search', context_type='current_session')

# ANALYZE: Examine session vitality and health
gana_heart('analyze', session_name='main', include_state=True)

# TRANSFORM: Checkpoint, restore, or handoff sessions
gana_heart('transform', action='checkpoint', include_state=True)

# CONSOLIDATE: Merge session contexts
gana_heart('consolidate', sessions=['session1', 'session2'])
```

**Implementation Priority:** ⭐⭐⭐ Critical (session context)

---

### **6. TAIL (尾 Wei) - Passionate Drive**
**Garden:** Courage/Adventure | **Element:** Fire | **Quality:** Yin

**Purpose:** Accelerate progress, optimize performance, propel forward

**Consolidated Tool:** `gana_tail(operation, **kwargs)`

**Maps from 143 tools:**
- `enable_rust_acceleration` ⭐
- `enable_rust` (duplicate)
- `enable_acceleration_router`
- `optimize_cache`
- `cache_optimize_cache`
- `optimize_models`
- `run_benchmarks` ⭐

**Polymorphic Operations:**
```python
# SEARCH: Find performance bottlenecks or optimization opportunities
gana_tail('search', profile_type='memory_operations')

# ANALYZE: Examine performance metrics and acceleration status
gana_tail('analyze', component='rust', show_benchmarks=True)

# TRANSFORM: Enable acceleration, optimize systems
gana_tail('transform', action='enable_rust', operations=['search', 'consolidate'])

# CONSOLIDATE: Merge optimization strategies
gana_tail('consolidate', strategies=['rust', 'cache', 'model'])
```

**Implementation Priority:** ⭐⭐ Important (performance)

---

### **7. WINNOWING BASKET (箕 Ji) - Separation**
**Garden:** Wisdom | **Element:** Fire | **Quality:** Yin

**Purpose:** Separate signal from noise, consolidate learnings, extract wisdom

**Consolidated Tool:** `gana_winnowing_basket(operation, **kwargs)`

**Maps from 143 tools:**
- `archaeology_process_wisdom` ⭐
- `archaeology_daily_digest`
- `archaeology_extract_wisdom`
- `synthesize_wisdom` ⭐
- `consolidate_process_wisdom`
- `consolidate_finalize_scratchpad`
- `consolidate_router`

**Polymorphic Operations:**
```python
# SEARCH: Find valuable insights to preserve
gana_winnowing_basket('search', query='lessons_learned', time_range='week')

# ANALYZE: Examine what's worth keeping vs discarding
gana_winnowing_basket('analyze', memory_type='short_term', threshold=0.6)

# TRANSFORM: Extract and preserve wisdom
gana_winnowing_basket('transform', action='extract_wisdom', limit_files=1000)

# CONSOLIDATE: Create daily/weekly wisdom digests
gana_winnowing_basket('consolidate', period='daily')
```

**Implementation Priority:** ⭐⭐⭐ Critical (knowledge synthesis)

---

### 🔥 SOUTHERN QUADRANT — Vermilion Bird (Summer/Fire/Yang Peak)
**Chapters 8-14: Expression, Expansion, Transformation**

---

### **8. GHOST (鬼 Gui) - Introspection**
**Garden:** Mystery/Grief | **Element:** Fire | **Quality:** Yin

**Purpose:** Track metrics, self-audit, reflection, acknowledge losses

**Consolidated Tool:** `gana_ghost(operation, **kwargs)`

**Maps from 143 tools:**
- `track_metric` ⭐
- `get_metrics_summary` ⭐
- `track_metrics_router`
- `run_kaizen_analysis` ⭐

**Polymorphic Operations:**
```python
# SEARCH: Find metrics, patterns in self-audit data
gana_ghost('search', category='performance', time_range='month')

# ANALYZE: Examine metrics and kaizen opportunities
gana_ghost('analyze', auto_fix=False, show_proposals=True)

# TRANSFORM: Track new metrics, implement improvements
gana_ghost('transform', action='track', metric='api_latency', value=125)

# CONSOLIDATE: Create audit reports and summaries
gana_ghost('consolidate', categories=['all'], format='report')
```

**Implementation Priority:** ⭐⭐ Important (introspection)

---

### **9. WILLOW (柳 Liu) - Flexibility**
**Garden:** Play | **Element:** Fire | **Quality:** Yang

**Purpose:** Adaptive interfaces, experimentation, polymorphic invocation

**Consolidated Tool:** `gana_willow(operation, **kwargs)`

**Maps from 143 tools:**
- `prat_invoke` ⭐
- `prat_list_morphologies`
- `invoke_prat_router`
- `gana_invoke` ⭐
- `adapt_response`

**Polymorphic Operations:**
```python
# SEARCH: Find available morphologies or adaptive pathways
gana_willow('search', tool='memory_search', show_morphologies=True)

# ANALYZE: Examine tool flexibility and adaptation patterns
gana_willow('analyze', tool='archaeology', context={...})

# TRANSFORM: Invoke tools with adaptive morphology
gana_willow('transform', target='memory_search', query='...', morphology='creative')

# CONSOLIDATE: Merge morphology learnings
gana_willow('consolidate', tool='search', experiments=[...])
```

**Implementation Priority:** ⭐⭐⭐ Critical (PRAT system)

---

### **10. STAR (星 Xing) - Illumination**
**Garden:** Beauty/Wisdom | **Element:** Metal | **Quality:** Yin

**Purpose:** Visualization, clarity, structure revelation, contextual understanding

**Consolidated Tool:** `gana_star(operation, **kwargs)`

**Maps from 143 tools:**
- `prat_get_context` (moved from Heart for clarity)
- `detect_patterns` ⭐
- `apply_reasoning_methods` (visualization aspects)
- `debug_system`

**Polymorphic Operations:**
```python
# SEARCH: Find patterns, illuminate structure
gana_star('search', pattern_type='emergence', min_confidence=0.7)

# ANALYZE: Examine patterns and reveal hidden structure
gana_star('analyze', content='codebase', depth='deep')

# TRANSFORM: Visualize or clarify structures
gana_star('transform', action='reveal_pattern', data={...})

# CONSOLIDATE: Merge pattern insights
gana_star('consolidate', patterns=[...])
```

**Implementation Priority:** ⭐⭐⭐ Critical (pattern detection)

---

### **11. EXTENDED NET (张 Zhang) - Connectivity**
**Garden:** Connection | **Element:** Metal | **Quality:** Yin

**Purpose:** Network effects, system resonance, event bus, Gan Ying

**Consolidated Tool:** `gana_extended_net(operation, **kwargs)`

**Maps from 143 tools:**
- `manage_resonance` ⭐
- `_emit_resonance_event`
- `manage_agent_collaboration` ⭐
- `sangha_chat_send`
- `sangha_chat_read`
- `sangha_chat_sangha_chat_send` (duplicate)
- `sangha_chat_sangha_chat_read` (duplicate)
- `send_notification_router`

**Polymorphic Operations:**
```python
# SEARCH: Find connections, network topology
gana_extended_net('search', node='agent_1', depth=3)

# ANALYZE: Examine resonance patterns and connectivity
gana_extended_net('analyze', operation='monitor', duration_seconds=60)

# TRANSFORM: Emit events, connect nodes, send messages
gana_extended_net('transform', action='emit_event', event_type='pattern_detected')

# CONSOLIDATE: Merge communication channels
gana_extended_net('consolidate', channels=['chat', 'events', 'signals'])
```

**Implementation Priority:** ⭐⭐⭐ Critical (event system)

---

### **12. WINGS (翼 Yi) - Expansion**
**Garden:** Creation/Adventure | **Element:** Metal | **Quality:** Yang

**Purpose:** Parallel execution, building at scale, batch operations

**Consolidated Tool:** `gana_wings(operation, **kwargs)`

**Maps from 143 tools:**
- `parallel_search` ⭐
- `batch_read`
- `parallel_execute_router`
- `rust_read_files_batch` ⭐
- `edge_batch_infer`
- `execute_cascade`
- `list_patterns`

**Polymorphic Operations:**
```python
# SEARCH: Find multiple targets in parallel
gana_wings('search', queries=['q1', 'q2', 'q3'], parallel=True)

# ANALYZE: Examine batch processing capabilities
gana_wings('analyze', show_capacity=True)

# TRANSFORM: Execute operations at scale
gana_wings('transform', action='batch_read', files=[...])

# CONSOLIDATE: Merge parallel results
gana_wings('consolidate', results=[...])
```

**Implementation Priority:** ⭐⭐ Important (scalability)

---

### **13. CHARIOT (轸 Zhen) - Movement**
**Garden:** Transformation | **Element:** Metal | **Quality:** Yang

**Purpose:** Navigate codebase, explore structure, archaeology

**Consolidated Tool:** `gana_chariot(operation, **kwargs)`

**Maps from 143 tools:**
- `manage_archaeology_router` ⭐
- `archaeology_mark_read`
- `archaeology_mark_written`
- `archaeology_find_unread`
- `archaeology_find_changed`
- `archaeology_recent_reads`
- `archaeology_stats` ⭐
- `archaeology_report`
- `archaeology_search`
- `archaeology_scan_directory`
- `archaeology_generate_report` (duplicate)
- `rust_scan_codebase` ⭐
- `rust_extract_todos`

**Polymorphic Operations:**
```python
# SEARCH: Find files, navigate codebase
gana_chariot('search', query='unread_files', directory='src/')

# ANALYZE: Examine file tracking statistics
gana_chariot('analyze', operation='stats', scan_disk=True)

# TRANSFORM: Mark files, track navigation
gana_chariot('transform', action='mark_read', file_path='src/main.py')

# CONSOLIDATE: Create navigation reports
gana_chariot('consolidate', operation='report', format='markdown')
```

**Implementation Priority:** ⭐⭐⭐ Critical (codebase navigation)

---

### **14. ABUNDANCE (轸 Zhen var.) - Surplus**
**Garden:** Joy/Gratitude | **Element:** Water | **Quality:** Yin

**Purpose:** Resource sharing, celebration, backup/restore

**Consolidated Tool:** `gana_abundance(operation, **kwargs)`

**Maps from 143 tools:**
- `windsurf_backup` ⭐
- `windsurf_merge_backups`
- `share_resources_router`
- `balance_energy`

**Polymorphic Operations:**
```python
# SEARCH: Find shareable resources or backups
gana_abundance('search', resource_type='backups', time_range='week')

# ANALYZE: Examine resource surplus and sharing patterns
gana_abundance('analyze', show_capacity=True)

# TRANSFORM: Backup, share, distribute resources
gana_abundance('transform', action='backup', conversations=True)

# CONSOLIDATE: Merge backups and resources
gana_abundance('consolidate', backups=['backup1', 'backup2'])
```

**Implementation Priority:** ⭐⭐ Important (backup/restore)

---

### 🍂 WESTERN QUADRANT — White Tiger (Autumn/Metal/Yin Rising)
**Chapters 15-21: Refinement, Ethics, Harvest**

---

### **15. STRADDLING LEGS (奎 Kui) - Balance**
**Garden:** Patience/Dharma | **Element:** Metal | **Quality:** Yin

**Purpose:** Fair queuing, load balancing, ethical equilibrium

**Consolidated Tool:** `gana_straddling_legs(operation, **kwargs)`

**Maps from 143 tools:**
- `dharma_evaluate_ethics` ⭐
- `dharma_check_boundaries`
- `dharma_verify_consent`
- `dharma_get_guidance` ⭐
- `dharma_get_ethical_score`
- `dharma_list_principles`
- `evaluate_dharma_router`

**Polymorphic Operations:**
```python
# SEARCH: Find ethical principles or balance points
gana_straddling_legs('search', situation='data_deletion', strict_mode=True)

# ANALYZE: Examine ethical score and balance
gana_straddling_legs('analyze', time_window_hours=24, show_violations=True)

# TRANSFORM: Evaluate action ethics, verify consent
gana_straddling_legs('transform', action='evaluate', context={...})

# CONSOLIDATE: Merge ethical frameworks
gana_straddling_legs('consolidate', principles=['compassion', 'truth'])
```

**Implementation Priority:** ⭐⭐⭐ Critical (ethics system)

---

### **16. MOUND (娄 Lou) - Accumulation**
**Garden:** Gratitude | **Element:** Metal | **Quality:** Yin

**Purpose:** Caching, storage, harvest gathering

**Consolidated Tool:** `gana_mound(operation, **kwargs)`

**Maps from 143 tools:**
- `manage_cache_router` ⭐
- `cache_optimize_cache`
- `cache_clear_cache`
- `cache_cache_stats`

**Polymorphic Operations:**
```python
# SEARCH: Find cached items or storage patterns
gana_mound('search', cache_type='memory', show_stats=True)

# ANALYZE: Examine cache health and accumulation
gana_mound('analyze', show_hit_rate=True)

# TRANSFORM: Optimize, clear, manage cache
gana_mound('transform', action='optimize', cache_type='all')

# CONSOLIDATE: Merge cache statistics
gana_mound('consolidate', caches=['memory', 'disk'])
```

**Implementation Priority:** ⭐⭐ Important (caching)

---

### **17. STOMACH (胃 Wei) - Nourishment**
**Garden:** Healing | **Element:** Earth | **Quality:** Yang

**Purpose:** Energy management, token economy, sustenance

**Consolidated Tool:** `gana_stomach(operation, **kwargs)`

**Maps from 143 tools:**
- Token economy (if implemented)
- Energy/prana management (if exists)
- Resource nourishment systems

**Polymorphic Operations:**
```python
# SEARCH: Find energy sources or consumption patterns
gana_stomach('search', resource='token_budget', show_usage=True)

# ANALYZE: Examine energy flow and nourishment
gana_stomach('analyze', time_range='day', show_deficit=True)

# TRANSFORM: Allocate energy, manage tokens
gana_stomach('transform', action='allocate', tokens=1000, to='agent_1')

# CONSOLIDATE: Merge energy pools
gana_stomach('consolidate', pools=['pool1', 'pool2'])
```

**Implementation Priority:** ⭐ Future (token economy)

---

### **18. HAIRY HEAD (昴 Mao) - Detail**
**Garden:** Presence/Beauty | **Element:** Earth | **Quality:** Yin

**Purpose:** Microscopic focus, precision, debugging, validation

**Consolidated Tool:** `gana_hairy_head(operation, **kwargs)`

**Maps from 143 tools:**
- `validate_input` ⭐
- `debug_system`
- `check_integrations_health` (detail aspect)

**Polymorphic Operations:**
```python
# SEARCH: Find detailed issues or microscopic patterns
gana_hairy_head('search', level='microscopic', component='validation')

# ANALYZE: Examine fine details and precision
gana_hairy_head('analyze', input={...}, schema={...})

# TRANSFORM: Validate, fix, refine details
gana_hairy_head('transform', action='validate', input={...})

# CONSOLIDATE: Merge validation results
gana_hairy_head('consolidate', validations=[...])
```

**Implementation Priority:** ⭐⭐ Important (validation)

---

### **19. NET (毕 Bi) - Capture**
**Garden:** Mystery/Voice | **Element:** Earth | **Quality:** Yin

**Purpose:** Pattern detection, recognition, capturing regularities

**Consolidated Tool:** `gana_net(operation, **kwargs)`

**Maps from 143 tools:**
- `detect_patterns` ⭐ (moved from Star for better fit)
- `rust_extract_patterns` ⭐
- Pattern capture systems

**Polymorphic Operations:**
```python
# SEARCH: Find patterns to capture
gana_net('search', pattern_type='emergence', domain='codebase')

# ANALYZE: Examine captured patterns
gana_net('analyze', text='...', extract_frequency=True)

# TRANSFORM: Capture new patterns
gana_net('transform', action='capture', pattern={...}, confidence=0.8)

# CONSOLIDATE: Merge pattern databases
gana_net('consolidate', patterns=[...])
```

**Implementation Priority:** ⭐⭐⭐ Critical (pattern capture)

---

### **20. TURTLE BEAK (觜 Zui) - Precision**
**Garden:** Voice/Truth | **Element:** Earth | **Quality:** Yang

**Purpose:** Input validation, articulation, verification, speech

**Consolidated Tool:** `gana_turtle_beak(operation, **kwargs)`

**Maps from 143 tools:**
- `manage_voice_patterns` ⭐
- Input validation (from Hairy Head if overlapping)
- Title generation, naming systems

**Polymorphic Operations:**
```python
# SEARCH: Find voice patterns or articulation templates
gana_turtle_beak('search', operation='signatures', show_patterns=True)

# ANALYZE: Examine voice patterns and precision
gana_turtle_beak('analyze', operation='analyze', text='...')

# TRANSFORM: Generate voice, articulate precisely
gana_turtle_beak('transform', action='learn', speaker='agent_1', samples=[...])

# CONSOLIDATE: Merge voice signatures
gana_turtle_beak('consolidate', voices=['voice1', 'voice2'])
```

**Implementation Priority:** ⭐⭐ Important (voice/articulation)

---

### **21. THREE STARS (参 Shen) - Judgment**
**Garden:** Dharma/Reverence | **Element:** Water | **Quality:** Yang

**Purpose:** Ethical judgment, wisdom council, strategic decisions

**Consolidated Tool:** `gana_three_stars(operation, **kwargs)`

**Maps from 143 tools:**
- `consult_full_council` ⭐
- `consult_art_of_war` ⭐
- `consult_iching` ⭐
- `consult_wisdom_router`
- `analyze_wu_xing_phase`
- `apply_reasoning_methods` ⭐

**Polymorphic Operations:**
```python
# SEARCH: Find wisdom, strategic insights
gana_three_stars('search', question='Should I refactor?', urgency='normal')

# ANALYZE: Examine situation through wisdom lenses
gana_three_stars('analyze', method='multi_spectral', query='...')

# TRANSFORM: Make judgment, apply strategy
gana_three_stars('transform', action='consult', council='iching', question='...')

# CONSOLIDATE: Merge wisdom from multiple sources
gana_three_stars('consolidate', sources=['iching', 'wuxing', 'zodiac'])
```

**Implementation Priority:** ⭐⭐⭐ Critical (wisdom council)

---

### 🌊 NORTHERN QUADRANT — Black Tortoise (Winter/Water/Yin Peak)
**Chapters 22-28: Depth, Integration, Completion**

---

### **22. WELL (井 Jing) - Depth**
**Garden:** Awe/Wonder | **Element:** Water | **Quality:** Yin

**Purpose:** Deep retrieval, sustained nourishment, ancient knowledge

**Consolidated Tool:** `gana_well(operation, **kwargs)`

**Maps from 143 tools:**
- `memory_search` ⭐ (deep search aspect)
- `search_memories_router`
- `search_deep_router`
- `rust_fast_search` ⭐
- `rust_parallel_grep`
- `rust_fast_similarity`

**Polymorphic Operations:**
```python
# SEARCH: Deep retrieval from memory depths
gana_well('search', query='ancient_patterns', depth='deep', use_rust=True)

# ANALYZE: Examine deep structures and connections
gana_well('analyze', memory_type='archive', show_clusters=True)

# TRANSFORM: Draw from depths, surface hidden knowledge
gana_well('transform', action='surface', query='...', candidates=[...])

# CONSOLIDATE: Merge deep search results
gana_well('consolidate', searches=[...])
```

**Implementation Priority:** ⭐⭐⭐ Critical (deep search)

---

### **23. GHOST CARRIER (鬼 Gui var.) - Transition**
**Garden:** Grief | **Element:** Water | **Quality:** Yin

**Purpose:** Session handoff, migration, context transfer

**Consolidated Tool:** `gana_ghost_carrier(operation, **kwargs)`

**Maps from 143 tools:**
- `session_handoff` ⭐ (router)
- `session_create_handoff`
- Windsurf sync/transition tools

**Polymorphic Operations:**
```python
# SEARCH: Find transition points or handoff opportunities
gana_ghost_carrier('search', session='current', show_handoff_candidates=True)

# ANALYZE: Examine transition readiness
gana_ghost_carrier('analyze', session='...', check_completeness=True)

# TRANSFORM: Create handoff, transfer context
gana_ghost_carrier('transform', action='handoff', from_session='...', to='...')

# CONSOLIDATE: Merge transition contexts
gana_ghost_carrier('consolidate', handoffs=[...])
```

**Implementation Priority:** ⭐⭐ Important (handoff)

---

### **24. WILLOW TIP (柳 Liu var.) - Subtlety**
**Garden:** Awe/Subtle awareness | **Element:** Water | **Quality:** Yang

**Purpose:** Ambient notifications, subtle communication, gentle nudges

**Consolidated Tool:** `gana_willow_tip(operation, **kwargs)`

**Maps from 143 tools:**
- Notification systems
- Ambient signaling (if exists)
- Subtle communication channels

**Polymorphic Operations:**
```python
# SEARCH: Find subtle signals or ambient patterns
gana_willow_tip('search', signal_type='ambient', threshold='whisper')

# ANALYZE: Examine subtle communication effectiveness
gana_willow_tip('analyze', channel='notifications', show_impact=True)

# TRANSFORM: Send subtle notifications, create ambient signals
gana_willow_tip('transform', action='notify', message='...', level='subtle')

# CONSOLIDATE: Merge notification channels
gana_willow_tip('consolidate', channels=['ambient', 'notification'])
```

**Implementation Priority:** ⭐ Future (ambient systems)

---

### **25. OX (牛 Niu) - Endurance**
**Garden:** Patience/Sangha | **Element:** Water | **Quality:** Yin

**Purpose:** Persistent monitoring, temporal grounding, long-term tracking

**Consolidated Tool:** `gana_ox(operation, **kwargs)`

**Maps from 143 tools:**
- `get_system_time` ⭐
- Watchdog systems
- Persistent monitoring
- Temporal context

**Polymorphic Operations:**
```python
# SEARCH: Find temporal patterns or persistent states
gana_ox('search', time_range='year', pattern='persistent')

# ANALYZE: Examine endurance metrics and temporal flow
gana_ox('analyze', show_uptime=True, show_temporal_context=True)

# TRANSFORM: Set up persistent monitoring, ground in time
gana_ox('transform', action='monitor', component='all', persistent=True)

# CONSOLIDATE: Merge temporal contexts
gana_ox('consolidate', time_windows=['week', 'month', 'year'])
```

**Implementation Priority:** ⭐⭐ Important (temporal/monitoring)

---

### **26. GIRL (女 Nü) - Nurture**
**Garden:** Love/Joy | **Element:** Wood | **Quality:** Yin

**Purpose:** User profile, adaptive learning, personalization

**Consolidated Tool:** `gana_girl(operation, **kwargs)`

**Maps from 143 tools:**
- `profile_get_profile` ⭐
- `profile_update_preferences`
- `manage_profile_router`

**Polymorphic Operations:**
```python
# SEARCH: Find user preferences or personalization data
gana_girl('search', preference_type='coding_style')

# ANALYZE: Examine user profile and adaptation patterns
gana_girl('analyze', show_preferences=True, show_learning=True)

# TRANSFORM: Update profile, personalize experience
gana_girl('transform', action='update', preferences={...})

# CONSOLIDATE: Merge profile data
gana_girl('consolidate', profiles=['draft', 'live'])
```

**Implementation Priority:** ⭐⭐ Important (personalization)

---

### **27. VOID (虚 Xu) - Emptiness**
**Garden:** Stillness | **Element:** Wood | **Quality:** Yang

**Purpose:** Defragmentation, idle optimization, meditation, clearing

**Consolidated Tool:** `gana_void(operation, **kwargs)`

**Maps from 143 tools:**
- `meditation_pause` ⭐
- `meditation_reflect`
- `meditation_meditate`
- `enter_stillness_router`
- Cache clearing (from Mound)
- Optimization during idle

**Polymorphic Operations:**
```python
# SEARCH: Find opportunities for clearing or optimization
gana_void('search', show_clutter=True, show_defrag_candidates=True)

# ANALYZE: Examine stillness patterns and optimization potential
gana_void('analyze', show_idle_time=True)

# TRANSFORM: Enter stillness, clear clutter, optimize in background
gana_void('transform', action='meditate', duration_seconds=300)

# CONSOLIDATE: Merge stillness learnings
gana_void('consolidate', meditations=[...])
```

**Implementation Priority:** ⭐⭐ Important (optimization/meditation)

---

### **28. ROOF (危 Wei/Abhijit) - Shelter**
**Garden:** Protection | **Element:** Wood | **Quality:** Yin

**Purpose:** Overarching protection, synthesis, cycle preparation, zodiac

**Consolidated Tool:** `gana_roof(operation, **kwargs)`

**Maps from 143 tools:**
- `manage_zodiac_cores` ⭐
- `zodiac_list_cores`
- `zodiac_activate_core`
- `zodiac_consult_council`
- `zodiac_run_cycle` ⭐
- `run_autonomous_cycle`
- `execute_mcp_tool` (main dispatcher)

**Polymorphic Operations:**
```python
# SEARCH: Find zodiac cores or cycle patterns
gana_roof('search', show_cores=True, show_active=True)

# ANALYZE: Examine cycle health and protection status
gana_roof('analyze', cycle='current', show_activations=True)

# TRANSFORM: Run cycle, activate cores, provide shelter
gana_roof('transform', action='run_cycle', intention='completion', num_cycles=1)

# CONSOLIDATE: Synthesize wisdom from complete cycle
gana_roof('consolidate', cycle_data=[...], create_synthesis=True)
```

**Implementation Priority:** ⭐⭐⭐ Critical (cycle management)

---

## THE 28 GANA TOOLS SUMMARY TABLE

| # | Gana | Garden | Purpose | Key Operations | Priority | Tool Count Reduced |
|---|------|--------|---------|----------------|----------|-------------------|
| 1 | Horn | Courage | Session Init | init, bootstrap | ⭐⭐⭐ | 4 → 1 |
| 2 | Neck | Practice | Memory Mgmt | create, update, consolidate | ⭐⭐⭐ | 7 → 1 |
| 3 | Root | Truth | System Health | check, validate, status | ⭐⭐⭐ | 12 → 1 |
| 4 | Room | Sanctuary | Resource Locks | acquire, release, protect | ⭐⭐ | 5 → 1 |
| 5 | Heart | Love | Session Context | get_context, checkpoint | ⭐⭐⭐ | 7 → 1 |
| 6 | Tail | Courage | Acceleration | enable_rust, optimize | ⭐⭐ | 7 → 1 |
| 7 | Winnowing Basket | Wisdom | Wisdom Extract | synthesize, digest | ⭐⭐⭐ | 7 → 1 |
| 8 | Ghost | Mystery | Metrics/Kaizen | track, analyze | ⭐⭐ | 4 → 1 |
| 9 | Willow | Play | PRAT/Adaptive | prat_invoke, adapt | ⭐⭐⭐ | 5 → 1 |
| 10 | Star | Beauty | Pattern Detect | detect, illuminate | ⭐⭐⭐ | 4 → 1 |
| 11 | Extended Net | Connection | Resonance/Chat | emit_event, chat | ⭐⭐⭐ | 8 → 1 |
| 12 | Wings | Creation | Parallel Exec | parallel, batch | ⭐⭐ | 7 → 1 |
| 13 | Chariot | Transform | Archaeology | navigate, track files | ⭐⭐⭐ | 13 → 1 |
| 14 | Abundance | Joy | Backup/Share | backup, restore | ⭐⭐ | 4 → 1 |
| 15 | Straddling Legs | Dharma | Ethics | evaluate, guidance | ⭐⭐⭐ | 7 → 1 |
| 16 | Mound | Gratitude | Caching | optimize_cache, stats | ⭐⭐ | 4 → 1 |
| 17 | Stomach | Healing | Energy/Tokens | allocate, nourish | ⭐ | 0 → 1 |
| 18 | Hairy Head | Presence | Validation | validate, debug | ⭐⭐ | 3 → 1 |
| 19 | Net | Mystery | Pattern Capture | capture, extract | ⭐⭐⭐ | 3 → 1 |
| 20 | Turtle Beak | Voice | Voice/Speech | voice_patterns, articulate | ⭐⭐ | 1 → 1 |
| 21 | Three Stars | Dharma | Wisdom Council | consult, reason | ⭐⭐⭐ | 6 → 1 |
| 22 | Well | Awe | Deep Search | deep_search, similarity | ⭐⭐⭐ | 6 → 1 |
| 23 | Ghost Carrier | Grief | Session Handoff | handoff, transfer | ⭐⭐ | 3 → 1 |
| 24 | Willow Tip | Awe | Notifications | notify, ambient | ⭐ | 0 → 1 |
| 25 | Ox | Patience | Temporal/Monitor | get_time, monitor | ⭐⭐ | 1 → 1 |
| 26 | Girl | Love | User Profile | get_profile, personalize | ⭐⭐ | 3 → 1 |
| 27 | Void | Stillness | Meditation/Opt | meditate, clear | ⭐⭐ | 5 → 1 |
| 28 | Roof | Protection | Zodiac/Cycle | run_cycle, synthesize | ⭐⭐⭐ | 7 → 1 |

**Total:** 143 tools → 28 tools (80.4% reduction)

---

## IMPLEMENTATION STRATEGY

### **Phase 1: Core Infrastructure (Week 1-2)**

1. **Create Base Gana Tool Class**
```python
# /whitemagic/core/ganas/base_tool.py

class GanaTool:
    """Base class for all 28 Gana tools."""

    def __init__(self, gana_name: str, garden: str, element: str):
        self.gana_name = gana_name
        self.garden = garden
        self.element = element

    def __call__(self, operation: str, **kwargs) -> Dict[str, Any]:
        """Polymorphic dispatcher."""
        if operation == 'search':
            return self.search(**kwargs)
        elif operation == 'analyze':
            return self.analyze(**kwargs)
        elif operation == 'transform':
            return self.transform(**kwargs)
        elif operation == 'consolidate':
            return self.consolidate(**kwargs)
        else:
            raise ValueError(f"Unknown operation: {operation}")

    def search(self, **kwargs) -> Dict[str, Any]:
        """Find and retrieve through Gana's lens."""
        raise NotImplementedError

    def analyze(self, **kwargs) -> Dict[str, Any]:
        """Examine and understand through Gana's lens."""
        raise NotImplementedError

    def transform(self, **kwargs) -> Dict[str, Any]:
        """Modify and evolve through Gana's lens."""
        raise NotImplementedError

    def consolidate(self, **kwargs) -> Dict[str, Any]:
        """Merge and unify through Gana's lens."""
        raise NotImplementedError
```

2. **Implement Critical Tools First (⭐⭐⭐)**
   - Neck (Memory)
   - Root (Health)
   - Heart (Session)
   - Winnowing Basket (Wisdom)
   - Willow (PRAT)
   - Star (Patterns)
   - Extended Net (Resonance)
   - Chariot (Archaeology)
   - Straddling Legs (Ethics)
   - Net (Capture)
   - Three Stars (Council)
   - Well (Search)
   - Roof (Zodiac)

### **Phase 2: Integration (Week 3-4)**

1. Update MCP server to use 28 tools
2. Create mapping from old tools to new Ganas
3. Add deprecation warnings for old tools
4. Update documentation and examples

### **Phase 3: Migration (Week 5-6)**

1. Test each Gana tool thoroughly
2. Migrate existing code to use new tools
3. Remove old tool implementations
4. Update all grimoire pages

### **Phase 4: Polish (Week 7-8)**

1. Optimize performance
2. Add telemetry for Gana usage
3. Create visualization of Gana cycle
4. Write comprehensive documentation

---

## BENEFITS OF 28-GANA ARCHITECTURE

### **Philosophical Alignment**
- Tools aligned with natural consciousness flow
- Seasonal/elemental balance maintained
- Spiritual framework integrated with technical function

### **Cognitive Clarity**
- 28 tools mapped to familiar lunar mansions
- Natural categorization (vs arbitrary grouping)
- Easier to remember and navigate

### **Polymorphic Power**
- Each tool supports 4 universal operations
- Reduces cognitive load (always: search/analyze/transform/consolidate)
- Enables elegant composition

### **Cyclic Wisdom**
- Tools follow natural progression through seasons
- Complete cycle: Init → Growth → Expression → Harvest → Completion
- Self-documenting workflow

### **Scalability**
- Adding functionality extends existing Ganas
- No tool explosion
- Clear boundaries and responsibilities

---

## NEXT STEPS

1. **Review this synthesis** - Ensure alignment with vision
2. **Prioritize Ganas** - Which 13 critical tools to implement first?
3. **Create implementation branches** - One per quadrant?
4. **Update grimoire** - Each chapter maps to its Gana tool
5. **Build test suite** - Comprehensive testing for all 28

---

**Prepared by:** Claude Sonnet 4.5
**Date:** 2026-02-02
**Status:** ✅ Complete synthesis ready for implementation
**Estimated Timeline:** 8 weeks for full migration
**Reduction Achieved:** 143 → 28 tools (80.4%)

---

*"The 28 Lunar Mansions are not just categories—they are living lenses through which consciousness flows. Each tool becomes a gateway to its Gana's wisdom."*
