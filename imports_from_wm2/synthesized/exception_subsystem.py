"""
WM2 Exception Subsystem
========================
Unified exception handling synthesized from whitemagicpublic

Total custom exceptions: 22
Total exception handlers: 2133
Exception hierarchies: 4
"""

from typing import Any, Dict, List, Optional, Type
from wm2.core import BaseEngine
from wm2.core.serializable import Serializable
from wm2.core.metrics import MetricCollector, tracked


# Base WM2 Exceptions
class WM2Exception(Exception):
    """Base exception for all WM2 errors."""
    pass


class WM2ValidationError(WM2Exception):
    """Validation error."""
    pass


class WM2ConfigurationError(WM2Exception):
    """Configuration error."""
    pass


class WM2RuntimeError(WM2Exception):
    """Runtime error."""
    pass


class WM2TimeoutError(WM2Exception):
    """Timeout error."""
    pass


class ExceptionSubsystem(BaseEngine, Serializable, MetricCollector):
    """
    Unified exception handling subsystem for WM2.
    
    Provides:
    - Exception tracking and logging
    - Error recovery strategies
    - Exception statistics
    """
    
    def __init__(self, name: str = "exception_subsystem"):
        BaseEngine.__init__(self, name=name)
        MetricCollector.__init__(self)
        self.exceptions_caught: List[Dict[str, Any]] = []
        self.active = False
    
    @tracked
    def initialize(self):
        """Initialize exception subsystem."""
        self.active = True
        self.record_metric("initialized", True)
    
    @tracked
    def handle_exception(self, exc: Exception, context: Optional[Dict[str, Any]] = None):
        """Handle and log an exception."""
        if not self.active:
            self.initialize()
        
        exc_info = {
            "type": type(exc).__name__,
            "message": str(exc),
            "context": context or {},
        }
        
        self.exceptions_caught.append(exc_info)
        self.record_metric("exceptions_handled", len(self.exceptions_caught))
    
    @tracked
    def get_exception_stats(self) -> Dict[str, Any]:
        """Get exception statistics."""
        if not self.exceptions_caught:
            return {"total": 0}
        
        # Count by type
        type_counts = {}
        for exc in self.exceptions_caught:
            exc_type = exc["type"]
            type_counts[exc_type] = type_counts.get(exc_type, 0) + 1
        
        return {
            "total": len(self.exceptions_caught),
            "by_type": type_counts,
            "most_common": max(type_counts.items(), key=lambda x: x[1])[0] if type_counts else None,
        }
    
    @tracked
    def get_stats(self) -> Dict[str, Any]:
        """Get comprehensive statistics."""
        return {
            **BaseEngine.get_stats(self),
            **MetricCollector.get_stats(self),
            "active": self.active,
            "exceptions_synthesized": 22,
            "exception_stats": self.get_exception_stats(),
        }


# Top exception types from whitemagicpublic:
# 1. Exception: 1492 handlers
# 2. ImportError: 339 handlers
# 3. ValueError: 41 handlers
# 4. json.JSONDecodeError: 34 handlers
# 5. OSError: 26 handlers
# 6. RuntimeError: 15 handlers
# 7. subprocess.TimeoutExpired: 14 handlers
# 8. FileNotFoundError: 11 handlers
# 9. asyncio.TimeoutError: 11 handlers
# 10. (json.JSONDecodeError, OSError): 10 handlers

# Custom exception classes from whitemagicpublic:
# Total: 22
# - WhiteMagicError (extends Exception)
# - MemoryNotFoundError (extends WhiteMagicError)
# - MemoryAlreadyExistsError (extends WhiteMagicError)
# - InvalidMemoryTypeError (extends WhiteMagicError)
# - InvalidSortOptionError (extends WhiteMagicError)
# - InvalidTierError (extends WhiteMagicError)
# - MemoryAlreadyArchivedError (extends WhiteMagicError)
# - MemoryNotArchivedError (extends WhiteMagicError)
# - FileOperationError (extends WhiteMagicError)
# - MetadataCorruptedError (extends WhiteMagicError)
# - ValidationError (extends WhiteMagicError)
# - APIError (extends WhiteMagicError)
# - AuthenticationError (extends APIError)
# - AuthorizationError (extends APIError)
# - RateLimitExceededError (extends APIError)
# - QuotaExceededError (extends APIError)
# - InvalidAPIKeyError (extends AuthenticationError)
# - APIKeyExpiredError (extends AuthenticationError)
# - CommandNotAllowedError (extends Exception)
# - RateLimitExceeded (extends Exception)
# ...

# TODO: Implement specific exception patterns from whitemagicpublic
