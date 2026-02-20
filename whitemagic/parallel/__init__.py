"""WhiteMagic parallel processing package."""

try:
    from .adaptive import AdaptiveThreadingController, SystemMetrics
except ImportError:
    AdaptiveThreadingController = SystemMetrics = None  # type: ignore[assignment,misc]
try:
    from .cache import CacheEntry, DistributedCache
except ImportError:
    CacheEntry = DistributedCache = None  # type: ignore[assignment,misc]
try:
    from .file_ops import FileReadResult, ParallelFileReader, batch_read_files, batch_read_files_dict
except ImportError:
    FileReadResult = ParallelFileReader = batch_read_files = batch_read_files_dict = None  # type: ignore[assignment,misc]
try:
    from .memory_consolidator import (
        ConsolidationResult,
        ParallelMemoryConsolidator,
        consolidate_all_memories,
        emit_consolidation_event,
    )
except ImportError:
    ConsolidationResult = ParallelMemoryConsolidator = consolidate_all_memories = emit_consolidation_event = None  # type: ignore[assignment,misc]
try:
    from .pipeline import ParallelPipeline, PipelineResult, PipelineStage
except ImportError:
    ParallelPipeline = PipelineResult = PipelineStage = None  # type: ignore[assignment,misc]
try:
    from .pools import PoolConfig, ThreadingManager, ThreadingTier
except ImportError:
    PoolConfig = ThreadingManager = ThreadingTier = None  # type: ignore[assignment,misc]
try:
    from .runner import ParallelTestRunner, TestResult, TestSuiteResult, run_tests_parallel
except ImportError:
    ParallelTestRunner = TestResult = TestSuiteResult = run_tests_parallel = None  # type: ignore[assignment,misc]
try:
    from .scheduler import ParallelScheduler, SchedulerStats, Task, TaskPriority, TaskStatus
except ImportError:
    ParallelScheduler = SchedulerStats = Task = TaskPriority = TaskStatus = None  # type: ignore[assignment,misc]

# Legacy names that were removed from the package layout.
# Keep placeholders for compatibility with old imports.
MassivePatternScanner = None
PatternMatch = None
ScanResult = None
quick_scan = None
DreamStateSynthesizer = None
GardenInsight = None
SynthesisResult = None
dream_synthesize = None
GrimoireIndexer = None
GrimoireIndex = None
Spell = None
index_grimoire = None
GanYingAmplifier = None
AmplifiedEvent = None
ResonanceWave = None
AmplificationResult = None
amplify = None
create_harmony = None

__all__ = [
    "ThreadingTier",
    "PoolConfig",
    "ThreadingManager",
    "AdaptiveThreadingController",
    "SystemMetrics",
    "ParallelScheduler",
    "TaskPriority",
    "TaskStatus",
    "Task",
    "SchedulerStats",
    "ParallelPipeline",
    "PipelineStage",
    "PipelineResult",
    "DistributedCache",
    "CacheEntry",
    "ParallelFileReader",
    "FileReadResult",
    "batch_read_files",
    "batch_read_files_dict",
    "ParallelMemoryConsolidator",
    "ConsolidationResult",
    "consolidate_all_memories",
    "emit_consolidation_event",
    "ParallelTestRunner",
    "TestResult",
    "TestSuiteResult",
    "run_tests_parallel",
    "MassivePatternScanner",
    "PatternMatch",
    "ScanResult",
    "quick_scan",
    "DreamStateSynthesizer",
    "GardenInsight",
    "SynthesisResult",
    "dream_synthesize",
    "GrimoireIndexer",
    "GrimoireIndex",
    "Spell",
    "index_grimoire",
    "GanYingAmplifier",
    "AmplifiedEvent",
    "ResonanceWave",
    "AmplificationResult",
    "amplify",
    "create_harmony",
]

__version__ = "2.6.6"
