"""AI module initialization"""

# Import all AI components
try:
    from .guidelines import check_constraints, load_guidelines, validate_action
    from .integration import AIIntegration
    from .interface import AIInterface, RateLimiter
    from .performance import AIPerformance, BatchProcessor, LatencyTracker, PerformanceCache
    from .safety import (
        AISafety, BiasDetector, ContentFilter, PrivacyProtector, SafetyMonitor,
    )
except ImportError:
    pass

__all__: list[str] = []
