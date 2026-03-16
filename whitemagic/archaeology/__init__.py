import json
import logging
import os
import re
import threading
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime
from pathlib import Path
from typing import Any, Dict, List, Optional

from whitemagic.config import PROJECT_ROOT

logger = logging.getLogger("Chariot")

_archaeologist: Optional['ChariotArchaeologist'] = None
_arch_lock = threading.Lock()

def get_archaeologist() -> 'ChariotArchaeologist':
    """Get the global ChariotArchaeologist singleton."""
    global _archaeologist
    if _archaeologist is None:
        with _arch_lock:
            if _archaeologist is None:
                target_dir = str(PROJECT_ROOT)
                output_dir = str(PROJECT_ROOT / "core_system" / "data")
                _archaeologist = ChariotArchaeologist(target_dir, output_dir)
    return _archaeologist

def mark_read(path: str, context: Optional[str] = None, note: Optional[str] = None, insight: Optional[str] = None) -> Dict[str, Any]:
    return get_archaeologist().mark_read(path, context, note, insight)

def mark_written(path: str, context: Optional[str] = None, note: Optional[str] = None) -> Dict[str, Any]:
    return get_archaeologist().mark_written(path, context, note)

def have_read(path: str) -> bool:
    return get_archaeologist().have_read(path)

def find_unread(directory: str = ".", patterns: Optional[List[str]] = None) -> List[Any]:
    return get_archaeologist().find_unread(directory, patterns)

def stats(scan_disk: bool = False) -> Dict[str, Any]:
    return get_archaeologist().stats(scan_disk=scan_disk)

from .dig import ChariotArchaeologist

# Bridge for WisdomExtractor (placeholder for now using Chariot logic)
class WisdomExtractor:
    def __init__(self):
        self.arch = get_archaeologist()
    
    def extract_wisdom(self, content: str, source: str) -> Dict[str, Any]:
        from .dig import Grimoire, Ganas
        return {
            "chapters": Grimoire.identify(content, source),
            "gana": Ganas.identify(content, source)
        }

def get_wisdom_extractor() -> WisdomExtractor:
    return WisdomExtractor()

def process_wisdom_archives(limit_files: int = 1000, memory_type: str = "long_term") -> Dict[str, Any]:
    # TODO: Implement actual archive processing
    return {"status": "success", "processed": 0}

def create_daily_wisdom_digest() -> str:
    # TODO: Implement digest creation
    return "No digest generated"

def wisdom_report() -> str:
    return get_archaeologist().reading_report()

__all__ = [
    "ChariotArchaeologist",
    "WisdomExtractor",
    "create_daily_wisdom_digest",
    "extract_wisdom",
    "find_unread",
    "get_archaeologist",
    "get_wisdom_extractor",
    "mark_read",
    "mark_read_async",
    "mark_written",
    "mark_written_async",
    "process_wisdom_archives",
    "stats",
    "wisdom_report",
]

# Compatibility aliases
def mark_read_async(*args, **kwargs): return mark_read(*args, **kwargs)
def mark_written_async(*args, **kwargs): return mark_written(*args, **kwargs)
def extract_wisdom(content: str, source: str): return get_wisdom_extractor().extract_wisdom(content, source)
