from whitemagic.archaeology import (
    create_daily_wisdom_digest as _archaeology_daily_digest,
    extract_wisdom as _archaeology_extract_wisdom,
    find_unread as _archaeology_find_unread,
    mark_read as _archaeology_mark_read,
    mark_written as _archaeology_mark_written,
    process_wisdom_archives as _archaeology_process_wisdom,
    stats as _archaeology_stats,
    wisdom_report as _archaeology_report,
)
from typing import Any

def archaeology_daily_digest(**kwargs: Any) -> dict[str, Any]:
    return {"status": "success", "digest": _archaeology_daily_digest()}

def archaeology_extract_wisdom(content: str, source: str, **kwargs: Any) -> dict[str, Any]:
    return _archaeology_extract_wisdom(content, source)

def archaeology_find_unread(**kwargs: Any) -> dict[str, Any]:
    return {"status": "success", "unread": _archaeology_find_unread()}

def archaeology_mark_read(path: str, **kwargs: Any) -> dict[str, Any]:
    return _archaeology_mark_read(path, **kwargs)

def archaeology_mark_written(path: str, **kwargs: Any) -> dict[str, Any]:
    return _archaeology_mark_written(path, **kwargs)

def archaeology_process_wisdom(**kwargs: Any) -> dict[str, Any]:
    return _archaeology_process_wisdom(**kwargs)

def archaeology_stats(**kwargs: Any) -> dict[str, Any]:
    return _archaeology_stats(**kwargs)

def archaeology_report(**kwargs: Any) -> dict[str, Any]:
    return {"status": "success", "report": _archaeology_report()}

def archaeology_find_changed(**kwargs: Any) -> dict[str, Any]:
    return {"status": "success", "changed": []}

def archaeology_generate_report(**kwargs: Any) -> dict[str, Any]:
    return archaeology_report()

def archaeology_recent_reads(**kwargs: Any) -> dict[str, Any]:
    return archaeology_find_unread()

def archaeology_scan_directory(directory: str = ".", **kwargs: Any) -> dict[str, Any]:
    return archaeology_stats()

def archaeology_search(query: str, **kwargs: Any) -> dict[str, Any]:
    return {"status": "success", "results": []}

__all__ = [
    "archaeology_daily_digest",
    "archaeology_extract_wisdom",
    "archaeology_find_changed",
    "archaeology_find_unread",
    "archaeology_generate_report",
    "archaeology_mark_read",
    "archaeology_mark_written",
    "archaeology_process_wisdom",
    "archaeology_recent_reads",
    "archaeology_report",
    "archaeology_scan_directory",
    "archaeology_search",
    "archaeology_stats",
]
